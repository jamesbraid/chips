# Readings: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`

One entry per routine, filed here from the reading batches by binary.

- `pcibr_try_set_device` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x0-0x4a4 (1188 bytes).
  It occupies 1188 bytes.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0x14, `lh` at 0x150.
  The `ld` at 0x90 loads 8 bytes from (a0 + (a1 << 0x7)) +0x138.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x148, including `lw` at 0x250, `lw` at 0x32c.
  3 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x144, including `lw` at 0x27c, `lw` at 0x310, `lw` at 0x3f8.
  3 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x14c, including `lw` at 0x290, `lw` at 0x348, `lw` at 0x400.
  The `sw` at 0x318 stores 4 bytes to (a0 + (a1 << 0x7)) +0x144.
  The `sw` at 0x334 stores 4 bytes to (a0 + (a1 << 0x7)) +0x148.
  The `sw` at 0x350 stores 4 bytes to (a0 + (a1 << 0x7)) +0x14c.
  The `sd` at 0x384 stores 8 bytes to (a0 + (a1 << 0x7)) +0x138.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x440, `lw` at 0x474.
  The `jal` at 0x78 calls mutex_spinlock with a0=a0+128, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x364 calls mutex_io_spinunlock with a0=a0+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=0x1100000, a5=0x8f8000.
  The `jal` at 0x37c calls pcireg_device_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=0x1100000, a5=0x8f8000.
  The `jal` at 0x388 calls pcireg_tflush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x394 calls mutex_io_spinunlock with a0=a0+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x3d0 calls mutex_io_spinunlock with a0=a0+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?, a4=[(a0 + (a1 << 0x7))+328].
  The `beq` branch at 0x34 targets 0x70, is taken when at(=[a0+114]:2) == 0, and falls through when at(=[a0+114]:2) != 0.
  The `beq` branch at 0x98 targets 0xb0, is taken when (s0(=a2) & 0x20) == 0, and falls through when (s0(=a2) & 0x20) != 0.
  The `beq` branch at 0xb4 targets 0xcc, is taken when (s0(=a2) & 0x10) == 0, and falls through when (s0(=a2) & 0x10) != 0.
  The `beq` branch at 0xcc targets 0xe0, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0xe0 targets 0xf8, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0xf8 targets 0x108, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `beq` branch at 0x108 targets 0x120, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bgez` branch at 0x120 targets 0x134, is taken when a0(=(a2 << 0x2f)) >= 0 (signed), and falls through when a0(=(a2 << 0x2f)) < 0 (signed).
  The `bgez` branch at 0x134 targets 0x148, is taken when a2(=(a2 << 0x2e)) >= 0 (signed), and falls through when a2(=(a2 << 0x2e)) < 0 (signed).
  The `beq` branch at 0x154 targets 0x174, is taken when (s0(=a2) & 0x1000) == 0, and falls through when (s0(=a2) & 0x1000) != 0.
  The `beq` branch at 0x160 targets 0x3e0, is taken when a2(=[a0+114]:2) == t1(=0x1), and falls through when a2(=[a0+114]:2) != t1(=0x1).
  The `beq` branch at 0x168 targets 0x3e0, is taken when a2(=[a0+114]:2) == t1(=0x2), and falls through when a2(=[a0+114]:2) != t1(=0x2).
  The `beq` branch at 0x178 targets 0x1a0, is taken when (s0(=a2) & 0x2000) == 0, and falls through when (s0(=a2) & 0x2000) != 0.
  The `beq` branch at 0x184 targets 0x3f0, is taken when a2(=[a0+114]:2) == t3(=0x1), and falls through when a2(=[a0+114]:2) != t3(=0x1).
  The `beq` branch at 0x18c targets 0x3ec, is taken when a2(=[a0+114]:2) == t1(=0x2), and falls through when a2(=[a0+114]:2) != t1(=0x2).
  The `beq` branch at 0x1a0 targets 0x1b0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x1b0 targets 0x1c8, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bgez` branch at 0x1c8 targets 0x1d8, is taken when t2(=(a2 << 0x2b)) >= 0 (signed), and falls through when t2(=(a2 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0x1d8 targets 0x1f0, is taken when t3(=(a2 << 0x2a)) >= 0 (signed), and falls through when t3(=(a2 << 0x2a)) < 0 (signed).
  The `bgez` branch at 0x1f0 targets 0x1fc, is taken when t9(=(a2 << 0x29)) >= 0 (signed), and falls through when t9(=(a2 << 0x29)) < 0 (signed).
  The `bgez` branch at 0x200 targets 0x218, is taken when ra(=(a2 << 0x28)) >= 0 (signed), and falls through when ra(=(a2 << 0x28)) < 0 (signed).
  The `bgez` branch at 0x21c targets 0x228, is taken when a3(=(a2 << 0x25)) >= 0 (signed), and falls through when a3(=(a2 << 0x25)) < 0 (signed).
  The `bgez` branch at 0x22c targets 0x23c, is taken when a4(=(a2 << 0x24)) >= 0 (signed), and falls through when a4(=(a2 << 0x24)) < 0 (signed).
  The `beq` branch at 0x23c targets 0x428, is taken when a2(=[a0+114]:2) == t1(=0x2), and falls through when a2(=[a0+114]:2) != t1(=0x2).
  The `beq` branch at 0x248 targets 0x304, is taken when (s4(?) & a3(?)) == 0, and falls through when (s4(?) & a3(?)) != 0.
  The `beq` branch at 0x254 targets 0x268, is taken when a4(=[(a0 + (a1 << 0x7))+328]) == 0, and falls through when a4(=[(a0 + (a1 << 0x7))+328]) != 0.
  The `beq` branch at 0x26c targets 0x3f8, is taken when a2(=[a0+114]:2) == t3(=0x1), and falls through when a2(=[a0+114]:2) != t3(=0x1).
  The `beq` branch at 0x274 targets 0x3f8, is taken when a2(=[a0+114]:2) == t1(=0x2), and falls through when a2(=[a0+114]:2) != t1(=0x2).
  The `beq` branch at 0x280 targets 0x290, is taken when t8(=[(a0 + (a1 << 0x7))+324]) == 0, and falls through when t8(=[(a0 + (a1 << 0x7))+324]) != 0.
  The `beq` branch at 0x294 targets 0x494, is taken when a2(=[(a0 + (a1 << 0x7))+332]) == 0, and falls through when a2(=[(a0 + (a1 << 0x7))+332]) != 0.
  The `beq` branch at 0x2ac targets 0x304, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x2c0 targets 0x2e0, is taken when (a2(=0x28000) & a0(?)) == 0, and falls through when (a2(=0x28000) & a0(?)) != 0.
  The `beq` branch at 0x2e8 targets 0x3c8, is taken when (s0(?) & a0(=0x1840000)) == 0, and falls through when (s0(?) & a0(=0x1840000)) != 0.
  The `bne` branch at 0x2fc targets 0x3cc, is taken when (s0(?) & a2(?)) != 0, and falls through when (s0(?) & a2(?)) == 0.
  The `bne` branch at 0x308 targets 0x320, is taken when s3(=a3) != a3(=0x1100000), and falls through when s3(=a3) == a3(=0x1100000).
  The `bne` branch at 0x324 targets 0x33c, is taken when s3(=a3) != a5(=0x8f8000), and falls through when s3(=a3) == a5(=0x8f8000).
  The `bne` branch at 0x340 targets 0x358, is taken when s3(=a3) != t1(=0x898000), and falls through when s3(=a3) == t1(=0x898000).
  The `bne` branch at 0x358 targets 0x374, is taken when s3(?) != t0(=[(a0 + (a1 << 0x7))+312]:8), and falls through when s3(?) == t0(=[(a0 + (a1 << 0x7))+312]:8).
  The `beq` branch at 0x36c targets 0x3a0 and is always taken.
  The `beq` branch at 0x3c8 targets 0x304, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x3d8 targets 0x3a0 and is always taken.
  The `beq` branch at 0x3e4 targets 0x170 and is always taken.
  The `beq` branch at 0x3f0 targets 0x198 and is always taken.
  The `beq` branch at 0x404 targets 0x49c, is taken when a1(=[(a0 + (a1 << 0x7))+324]) == 0, and falls through when a1(=[(a0 + (a1 << 0x7))+324]) != 0.
  The `beq` branch at 0x414 targets 0x420, is taken when a0(=[(a0 + (a1 << 0x7))+332]) == 0, and falls through when a0(=[(a0 + (a1 << 0x7))+332]) != 0.
  The `beq` branch at 0x420 targets 0x2a8 and is always taken.
  The `bne` branch at 0x438 targets 0x468, is taken when s3(=a3) != a3(=0x898000), and falls through when s3(=a3) == a3(=0x898000).
  The `beq` branch at 0x450 targets 0x468, is taken when (a4(?) & 0x2) == 0, and falls through when (a4(?) & 0x2) != 0.
  The `bgez` branch at 0x458 targets 0x468, is taken when a1(=(a2 << 0x26)) >= 0 (signed), and falls through when a1(=(a2 << 0x26)) < 0 (signed).
  The `beq` branch at 0x468 targets 0x244, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x480 targets 0x240, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x48c targets 0x240 and is always taken.
  The `beq` branch at 0x494 targets 0x2a4 and is always taken.
  The `beq` branch at 0x49c targets 0x410 and is always taken.
  The return at 0x3c0 has v0 = one of 0x0, ?.

- `pcibr_release_device` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x4a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x4a4-0x554 (176 bytes).
  It occupies 176 bytes.
  The `lw` at 0x500 loads 4 bytes from (a0 + (a1 << 0x7)) +0x144.
  The `sw` at 0x508 stores 4 bytes to (a0 + (a1 << 0x7)) +0x144.
  The `lw` at 0x514 loads 4 bytes from (a0 + (a1 << 0x7)) +0x148.
  The `sw` at 0x51c stores 4 bytes to (a0 + (a1 << 0x7)) +0x148.
  The `lw` at 0x528 loads 4 bytes from (a0 + (a1 << 0x7)) +0x14c.
  The `sw` at 0x530 stores 4 bytes to (a0 + (a1 << 0x7)) +0x14c.
  The `jal` at 0x4c4 calls mutex_spinlock with a0=a0+128, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x540 calls mutex_io_spinunlock with a0=a0+128, a1=(ret(mutex_spinlock) << 0x0), a2=a0+128, a3=?, a5=0x8f8000, a6=(a0 + (a1 << 0x7)), a7=(a0 + (a1 << 0x7)).
  The `bne` branch at 0x4f8 targets 0x50c, is taken when s0(=a2) != at(=0x1100000), and falls through when s0(=a2) == at(=0x1100000).
  The `bne` branch at 0x50c targets 0x520, is taken when s0(=a2) != a5(=0x8f8000), and falls through when s0(=a2) == a5(=0x8f8000).
  The `bne` branch at 0x520 targets 0x538, is taken when s0(=a2) != a1(=0x898000), and falls through when s0(=a2) == a1(=0x898000).
  The return at 0x54c has v0 = ret(mutex_io_spinunlock).

- `pcibr_device_write_gather_flush` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x554 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x554-0x570 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x55c calls pcireg_wrb_flush_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x568 has v0 = ret(pcireg_wrb_flush_get).

- `pcibr_open` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x570
  **Inferred.** Calls `cap_able_cred` at 0x580 with a0 = a3, a1 = 0x2000000000, a2 = a2 and a3 = a3. The `beq` at 0x588 goes to 0x59c when the result is zero; otherwise the routine falls into the return at 0x594, whose value is one of 0x0 and 0x1 (the facts do not say which side gives which). The routine has no other calls. Role (from name): a capability check on opening a PCI bridge device.
  Reviewed: 2026-11-12

- `pcibr_open` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x570
  **Inferred.** It calls cap_able_cred with a1 = 0x2000000000 [call 1]. When its result is zero it takes the branch [@0x588 taken zero] to a separate path. Its return value is one of 0x0 and 0x1 [@0x594].
  Role (from facts): one call [call 1] followed by a return of one of two values [@0x594].
  Reviewed: 2026-11-12

- `pcibr_close` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x5a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x5a4-0x5ac (8 bytes).
  It occupies 8 bytes.
  The return at 0x5a4 has v0 = 0x0.

- `pcibr_map` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x5ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x5ac-0x678 (204 bytes).
  It occupies 204 bytes.
  The `ld` at 0x5e8 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `lh` at 0x618 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `jal` at 0x5cc calls hwgraph_connectpt_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5dc calls hwgraph_fastinfo_get with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0x5f0 calls hwgraph_vertex_unref with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0x610 calls v_mapphys with a0=a1 at entry (arg1), a1=(a2 + [ret(hwgraph_fastinfo_get)+8]:8), a2=?, a3=-0x4000.
  The `jal` at 0x668 calls pcireg_control_bit_set with a0=ret(hwgraph_fastinfo_get), a1=0x80000000, a2=[ret(hwgraph_fastinfo_get)+114]:2, a3=?.
  The `bne` branch at 0x624 targets 0x644, is taken when a2(=[ret(hwgraph_fastinfo_get)+114]:2) != 0, and falls through when a2(=[ret(hwgraph_fastinfo_get)+114]:2) == 0.
  The `bne` branch at 0x62c targets 0x644, is taken when v0(=ret(v_mapphys)) != 0, and falls through when v0(=ret(v_mapphys)) == 0.
  The `beq` branch at 0x638 targets 0x660, is taken when v0(=0xc00000) == s1(=a2), and falls through when v0(=0xc00000) != s1(=a2).
  The `bne` branch at 0x640 targets 0x660, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x670 targets 0x648 and is always taken.
  The return at 0x658 has v0 = ret(v_mapphys).

- `pcibr_unmap` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x678 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x678-0x6f0 (120 bytes).
  It occupies 120 bytes.
  The `lh` at 0x6a4 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `jal` at 0x680 calls hwgraph_connectpt_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x690 calls hwgraph_fastinfo_get with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0x69c calls hwgraph_vertex_unref with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0x6c4 calls pcireg_control_get with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x6e0 calls pcireg_control_bit_clr with a0=ret(hwgraph_fastinfo_get), a1=0x80000000, a2=?, a3=?.
  The `beq` branch at 0x6a8 targets 0x6c4, is taken when at(=[ret(hwgraph_fastinfo_get)+114]:2) == 0, and falls through when at(=[ret(hwgraph_fastinfo_get)+114]:2) != 0.
  The `beq` branch at 0x6d8 targets 0x6b4, is taken when (a1(=0x80000000) & v0(=ret(pcireg_control_get))) == 0, and falls through when (a1(=0x80000000) & v0(=ret(pcireg_control_get))) != 0.
  The `beq` branch at 0x6e8 targets 0x6b4 and is always taken.
  The return at 0x6bc has v0 = 0x0.

- `pcibr_device_slot_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x6f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x6f0-0x778 (136 bytes).
  It occupies 136 bytes.
  The `lbu` at 0x734 loads 1 byte from ret(pciio_info_chk) +0x21c.
  The `jal` at 0x708 calls vertex_to_name with a0=a0 at entry (arg0), a1=sp-288, a2=0x100, a3=a3 at entry (arg3).
  The `jal` at 0x710 calls hwgraph_connectpt_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x724 calls pciio_info_chk with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0x738 calls hwgraph_vertex_unref with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0x758 calls hwgraph_vertex_unref with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0x760 calls hwgraph_connectpt_get with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0x71c targets 0x770, is taken when s1(=-0x1) == v0(=ret(hwgraph_connectpt_get)), and falls through when s1(=-0x1) != v0(=ret(hwgraph_connectpt_get)).
  The `beq` branch at 0x72c targets 0x758, is taken when v0(=ret(pciio_info_chk)) == 0, and falls through when v0(=ret(pciio_info_chk)) != 0.
  The `bne` branch at 0x768 targets 0x724, is taken when s1(=-0x1) != v0(=ret(hwgraph_connectpt_get)), and falls through when s1(=-0x1) == v0(=ret(hwgraph_connectpt_get)).
  The `beq` branch at 0x770 targets 0x738 and is always taken.
  The return at 0x750 has v0 = ?.

- `pcibr_ioctl` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x778 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x778-0x8e8 (368 bytes).
  It occupies 368 bytes.
  The `jal` at 0x78c calls hwgraph_connectpt_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x798 calls hwgraph_fastinfo_get with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0x7a4 calls hwgraph_vertex_unref with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0x810 calls cap_able with a0=0x2000000000, a1=?, a2=?, a3=?.
  The `jal` at 0x824 calls copyin with a0=a2 at entry (arg2), a1=sp-64, a2=0x10, a3=?.
  The `jal` at 0x83c calls cap_able with a0=0x2000000000, a1=?, a2=?, a3=?.
  The `jal` at 0x850 calls copyin with a0=a2 at entry (arg2), a1=sp-80, a2=0x10, a3=?.
  The `jal` at 0x878 calls pcibr_device_slot_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x898 calls pcibr_priority_bits_set with a0=?, a1=?, a2=0x1, a3=?.
  The `jal` at 0x8a8 calls pcibr_device_slot_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x8c8 calls pcibr_priority_bits_set with a0=?, a1=?, a2=0x0, a3=0xff.
  The `beq` branch at 0x7b0 targets 0x80c, is taken when s0(=a1) == at(=0x6701), and falls through when s0(=a1) != at(=0x6701).
  The `beq` branch at 0x7bc targets 0x83c, is taken when s0(=a1) == v0(=0x6702), and falls through when s0(=a1) != v0(=0x6702).
  The `beq` branch at 0x7c8 targets 0x7fc, is taken when s0(=a1) == v1(=0x7001), and falls through when s0(=a1) != v1(=0x7001).
  The `beq` branch at 0x7d0 targets 0x804, is taken when s0(=a1) == a0(=0x7002), and falls through when s0(=a1) != a0(=0x7002).
  The `beq` branch at 0x7dc targets 0x7f4, is taken when s0(=a1) == a1(=0x7003), and falls through when s0(=a1) != a1(=0x7003).
  The `beq` branch at 0x7f4 targets 0x7e4 and is always taken.
  The `beq` branch at 0x7fc targets 0x7e4 and is always taken.
  The `beq` branch at 0x804 targets 0x7e8 and is always taken.
  The `beq` branch at 0x818 targets 0x868, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x82c targets 0x878, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x834 targets 0x7e4 and is always taken.
  The `beq` branch at 0x844 targets 0x870, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x858 targets 0x8a8, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x860 targets 0x7e4 and is always taken.
  The `beq` branch at 0x868 targets 0x7e4 and is always taken.
  The `beq` branch at 0x870 targets 0x7e4 and is always taken.
  The `beq` branch at 0x884 targets 0x8d8, is taken when v0(=ret(pcibr_device_slot_get)) == a1(=0xff), and falls through when v0(=ret(pcibr_device_slot_get)) != a1(=0xff).
  The `beq` branch at 0x88c targets 0x8a0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x8a0 targets 0x7e4 and is always taken.
  The `beq` branch at 0x8b4 targets 0x8e0, is taken when v0(=ret(pcibr_device_slot_get)) == a3(=0xff), and falls through when v0(=ret(pcibr_device_slot_get)) != a3(=0xff).
  The `beq` branch at 0x8bc targets 0x8d0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x8d0 targets 0x7e4 and is always taken.
  The `beq` branch at 0x8d8 targets 0x7e4 and is always taken.
  The `beq` branch at 0x8e0 targets 0x7e4 and is always taken.
  The return at 0x7ec has v0 = one of 0x0, 0x1, 0x5, 0xe.

- `pcibr_info_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x8e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x8e8-0x904 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x8f0 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x8fc has v0 = ret(pciio_hostinfo_get).

- `pcibr_device_info_new` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x904 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x904-0xa1c (280 bytes).
  It occupies 280 bytes.
  The `lh` at 0x954 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lw` at 0x96c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `sb` at 0x984 stores 1 byte to ret(kmem_zalloc) +0x10.
  The `sb` at 0x990 stores 1 byte to ret(kmem_zalloc) +0x21c.
  The `sw` at 0x9b8 stores 4 bytes to ?.
  The `lw` at 0x9cc loads 4 bytes from ((a1 << 0x7) + a0) +0x110.
  The `ld` at 0x9e0 loads 8 bytes from ((a1 << 0x7) + a0) +0x118.
  The `sd` at 0x9ec stores 8 bytes to ?.
  The `jal` at 0x938 calls kmem_zalloc with a0=0x228, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x970 calls pciio_device_info_new with a0=ret(kmem_zalloc), a1=[a0+4], a2=?, a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=a4 at entry (arg4).
  The `beq` branch at 0x94c targets 0xa0c, is taken when at(=0xff) == s1(=a1), and falls through when at(=0xff) != s1(=a1).
  The `beq` branch at 0x958 targets 0xa14, is taken when v0(=[a0+114]:2) == v1(=0x2), and falls through when v0(=[a0+114]:2) != v1(=0x2).
  The `beq` branch at 0x994 targets 0x9f0, is taken when a3(=0xff) == s1(=a1), and falls through when a3(=0xff) != s1(=a1).
  The `bne` branch at 0x9b4 targets 0x99c, is taken when a0(?) < 0x4 (signed), and falls through when a0(?) >= 0x4 (signed).
  The `beq` branch at 0x9d8 targets 0x9f0, is taken when v0(?) >= v1(=[((a1 << 0x7) + a0)+272]) (signed), and falls through when v0(?) < v1(=[((a1 << 0x7) + a0)+272]) (signed).
  The `beq` branch at 0xa0c targets 0x960 and is always taken.
  The `beq` branch at 0xa14 targets 0x960 and is always taken.
  The return at 0xa04 has v0 = ret(kmem_zalloc).

- `pcibr_device_unregister` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xa1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xa1c-0xb54 (312 bytes).
  It occupies 312 bytes.
  The `lbu` at 0xa50 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0xa54 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x0.
  The `ld` at 0xa5c loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x5e8, including `lw` at 0xa80, `lw` at 0xae0.
  The `lw` at 0xa94 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x56c.
  The `lw` at 0xa98 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x574.
  The `lw` at 0xa9c loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `lw` at 0xaac loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528.
  The `lw` at 0xab4 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x570.
  The `sw` at 0xad4 stores 4 bytes to (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528.
  The `lw` at 0xae8 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x5ec.
  The `jal` at 0xa2c calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa3c calls pciio_info_master_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa4c calls hwgraph_fastinfo_get with a0=ret(pciio_info_master_get), a1=?, a2=?, a3=?.
  The `jal` at 0xa64 calls xtalk_widgetdev_shutdown with a0=[ret(hwgraph_fastinfo_get)], a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The `jal` at 0xa70 calls pcibr_rrb_flush with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa8c calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0xad0 calls do_pcibr_rrb_free_all with a0=ret(hwgraph_fastinfo_get), a1=?, a2=[ret(pciio_hostinfo_get)+540]:1, a3=?.
  The `jal` at 0xaf0 calls mutex_io_spinunlock with a0=?, a1=?, a2=[(ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512], a3=?.
  The `jal` at 0xb00 calls pcibr_rrb_alloc with a0=a0 at entry (arg0), a1=sp-80, a2=sp-76, a3=?.
  The `jal` at 0xb0c calls pcibr_wrb_flush with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb20 calls pcibr_slot_info_free with a0=?, a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The `bltz` branch at 0xa84 targets 0xb08, is taken when v0(=[(ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) < 0 (signed), and falls through when v0(=[(ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) >= 0 (signed).
  The return at 0xb4c has v0 = ?.

- `pcibr_driver_reg_callback` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb54-0xbfc (168 bytes).
  It occupies 168 bytes.
  The `lbu` at 0xb9c loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `sw` at 0xbbc stores 4 bytes to ret(pcibr_info_get) +0x218.
  The `lw` at 0xbc4 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x10c.
  3 such `sw` accesses store 4 bytes to (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x10c, including `sw` at 0xbd8, `sw` at 0xbe0, `sw` at 0xbf8.
  The `jal` at 0xb78 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=-0x1.
  The `jal` at 0xb84 calls pcibr_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb90 calls pciio_info_master_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xba4 calls hwgraph_fastinfo_get with a0=ret(pciio_info_master_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xb64 targets 0xbe4, is taken when a1 == a6(=-0x1), and falls through when a1 != a6(=-0x1).
  The `beq` branch at 0xb70 targets 0xbe4, is taken when a2 == a6(=-0x1), and falls through when a2 != a6(=-0x1).
  The `beq` branch at 0xbd4 targets 0xbf0, is taken when s0(=a3) == 0, and falls through when s0(=a3) != 0.
  The `beq` branch at 0xbf4 targets 0xbe4 and is always taken.
  The return at 0xbe8 has v0 = one of a3, ret(hwgraph_fastinfo_get).

- `pcibr_driver_unreg_callback` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xbfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xbfc-0xca4 (168 bytes).
  It occupies 168 bytes.
  The `lbu` at 0xc44 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `sw` at 0xc64 stores 4 bytes to ret(pcibr_info_get) +0x218.
  The `lw` at 0xc6c loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x10c.
  3 such `sw` accesses store 4 bytes to (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x10c, including `sw` at 0xc80, `sw` at 0xc88, `sw` at 0xca0.
  The `jal` at 0xc20 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=-0x1.
  The `jal` at 0xc2c calls pcibr_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xc38 calls pciio_info_master_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xc4c calls hwgraph_fastinfo_get with a0=ret(pciio_info_master_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xc0c targets 0xc8c, is taken when a1 == a6(=-0x1), and falls through when a1 != a6(=-0x1).
  The `beq` branch at 0xc18 targets 0xc8c, is taken when a2 == a6(=-0x1), and falls through when a2 != a6(=-0x1).
  The `beq` branch at 0xc7c targets 0xc98, is taken when s0(=a3) == 0, and falls through when s0(=a3) != 0.
  The `beq` branch at 0xc9c targets 0xc8c and is always taken.
  The return at 0xc90 has v0 = one of a3, ret(hwgraph_fastinfo_get).

- `pcibr_detach` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xca4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xca4-0xe34 (400 bytes).
  It occupies 400 bytes.
  2 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0xd30, `lbu` at 0xd60.
  The `lbu` at 0xd34 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  The `ld` at 0xd80 loads 8 bytes from ret(hwgraph_fastinfo_get) +0xf8.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x10, including `ld` at 0xd98, `ld` at 0xda4.
  The `ld` at 0xda8 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x60.
  The `ld` at 0xdbc loads 8 bytes from ret(hwgraph_fastinfo_get) +0x68.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x828, including `ld` at 0xdd4, `ld` at 0xddc.
  The `jal` at 0xcbc calls pcibr_debug with a0=0x8, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a3 at entry (arg3).
  The `jal` at 0xcd0 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-64, a3=?.
  The `jal` at 0xcf4 calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd04 calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0xd14 calls pcireg_intr_enable_set with a0=ret(hwgraph_fastinfo_get), a1=0x0, a2=?, a3=?.
  The `jal` at 0xd28 calls mutex_io_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd58 calls pcibr_slot_detach with a0=?, a1=?, a2=0x0, a3=0x0, a4=0x0.
  The `jal` at 0xd84 calls pciio_device_info_unregister with a0=?, a1=[ret(hwgraph_fastinfo_get)+248]:8, a2=?, a3=?.
  The `jal` at 0xd8c calls spinlock_destroy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd94 calls strlen with a0=[ret(hwgraph_fastinfo_get)+16]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xda0 calls kmem_free with a0=[ret(hwgraph_fastinfo_get)+16]:8, a1=ret(strlen), a2=?, a3=?.
  The `jal` at 0xdb4 calls rmfreemap with a0=[ret(hwgraph_fastinfo_get)+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xdc8 calls rmfreemap with a0=[ret(hwgraph_fastinfo_get)+104]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xdd0 calls xtalk_intr_disconnect with a0=[ret(hwgraph_fastinfo_get)+2088]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xdd8 calls xtalk_intr_free with a0=[ret(hwgraph_fastinfo_get)+2088]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xde4 calls kmem_free with a0=ret(hwgraph_fastinfo_get), a1=0xab8, a2=?, a3=?.
  The `jal` at 0xdf8 calls hwgraph_info_remove_LBL with a0=?, a1=sym(.rodata), a2=0x0, a3=?.
  The `jal` at 0xe10 calls hwgraph_edge_remove with a0=?, a1=sym(.rodata), a2=0x0, a3=?.
  The `jal` at 0xe24 calls hwgraph_edge_remove with a0=a0 at entry (arg0), a1=sym(.rodata), a2=0x0, a3=?.
  The `beq` branch at 0xcd8 targets 0xcf0, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0xd40 targets 0xd7c, is taken when s2(=[ret(hwgraph_fastinfo_get)+56]:1) >= a2(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(=[ret(hwgraph_fastinfo_get)+56]:1) < a2(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `bne` branch at 0xd74 targets 0xd4c, is taken when s2(?) < a3(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(?) >= a3(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xdac targets 0xdbc, is taken when a0(=[ret(hwgraph_fastinfo_get)+96]:8) == 0, and falls through when a0(=[ret(hwgraph_fastinfo_get)+96]:8) != 0.
  The `beq` branch at 0xdc0 targets 0xdd0, is taken when a0(=[ret(hwgraph_fastinfo_get)+104]:8) == 0, and falls through when a0(=[ret(hwgraph_fastinfo_get)+104]:8) != 0.
  The `beq` branch at 0xe2c targets 0xce0 and is always taken.
  The return at 0xce8 has v0 = one of 0x0, 0x1.

- `pcibr_directmap_init` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xe34-0xf60 (300 bytes).
  It occupies 300 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xe44, `lw` at 0xf38.
  The `lw` at 0xe68 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0xe78 loads 2 bytes from ?.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x30, including `lbu` at 0xea4, `lbu` at 0xeac.
  The `sb` at 0xeb4 stores 1 byte to a0 (arg0 at entry) +0x58.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x50, including `sd` at 0xec8, `sd` at 0xf28.
  The `jal` at 0xe4c calls device_admin_info_get with a0=[a0+4], a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe84 calls xtalk_dmatrans_addr with a0=[a0], a1=0x0, a2=?, a3=0x4000, a4=0x0.
  The `jal` at 0xe94 calls pcireg_dirmap_diroff_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xea0 calls pcireg_dirmap_wid_set with a0=a0 at entry (arg0), a1=[a0+48]:1, a2=?, a3=?.
  The `jal` at 0xeb8 calls pcireg_dirmap_add512_clr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=[a0+48]:1, a5=0x20000000.
  The `jal` at 0xee0 calls hwgraph_path_to_vertex with a0=ret(device_admin_info_get), a1=?, a2=?, a3=?, a7=0x0.
  The `jal` at 0xef4 calls nodevertex_to_cnodeid with a0=ret(hwgraph_path_to_vertex), a1=?, a2=0x100, a3=?, a7=-0x1.
  The `jal` at 0xf18 calls pcireg_dirmap_add512_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=[a0+48]:1, a5=0x20000000.
  The `jal` at 0xf34 calls vertex_to_name with a0=[a0+4], a1=sp-288, a2=0x100, a3=?.
  The `jal` at 0xf50 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=sp-288, a3=sym(.rodata).
  The `bne` branch at 0xe58 targets 0xee0, is taken when v0(=ret(device_admin_info_get)) != 0, and falls through when v0(=ret(device_admin_info_get)) == 0.
  The `beq` branch at 0xeb0 targets 0xf18, is taken when a5(=0x20000000) == s1(=ret(xtalk_dmatrans_addr)), and falls through when a5(=0x20000000) != s1(=ret(xtalk_dmatrans_addr)).
  The `beq` branch at 0xeec targets 0xf30, is taken when a7(=-0x1) == v0(=ret(hwgraph_path_to_vertex)), and falls through when a7(=-0x1) != v0(=ret(hwgraph_path_to_vertex)).
  The `bne` branch at 0xf08 targets 0xe64, is taken when a7(?) != t0(=-0x1), and falls through when a7(?) == t0(=-0x1).
  The `beq` branch at 0xf10 targets 0xf30 and is always taken.
  The `beq` branch at 0xf24 targets 0xecc and is always taken.
  The `beq` branch at 0xf58 targets 0xe60 and is always taken.
  The return at 0xed8 has v0 = one of ret(pcireg_dirmap_add512_clr), ret(pcireg_dirmap_add512_set).
  The instructions from 0xf2c to 0xf2c are not reached by any path from the entry, and their branches are not listed.

- `pcibr_asic_rev` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xf60-0xfc8 (104 bytes).
  It occupies 104 bytes.
  The `jal` at 0xf70 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-32, a3=a3 at entry (arg3).
  The `jal` at 0xf98 calls hwgraph_info_get_LBL with a0=?, a1=sym(.rodata), a2=sp-24, a3=?.
  The `jal` at 0xfa4 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xf78 targets 0xf90, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0xfb0 targets 0xfc0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xfb8 targets 0xf88 and is always taken.
  The `beq` branch at 0xfc0 targets 0xf84 and is always taken.
  The return at 0xf88 has v0 = one of ?, -0x1.

- `pcibr_write_gather_flush` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xfc8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xfc8-0x1004 (60 bytes).
  It occupies 60 bytes.
  The `lbu` at 0xfec loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `jal` at 0xfd0 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xfdc calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xfe8 calls pcibr_device_write_gather_flush [0x554] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The return at 0xffc has v0 = 0x0.

- `pcibr_addr_pci_to_xio` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1004 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x1004-0x18d4 (2256 bytes).
  It occupies 2256 bytes.
  The `lw` at 0x107c loads 4 bytes from (ret(pciio_info_mfast_get) + (a1 << 0x7)) +0x100.
  The `lbu` at 0x1088 loads 1 byte from (ret(pciio_info_mfast_get) + (a1 << 0x7)) +0x104.
  The `ld` at 0x1094 loads 8 bytes from (ret(pciio_info_mfast_get) + ([(ret(pciio_info_mfast_get) + (a1 << 0x7))+260]:1 << 0x7)) +0x118.
  The `ld` at 0x1098 loads 8 bytes from [(ret(pciio_info_mfast_get) + ([(ret(pciio_info_mfast_get) + (a1 << 0x7))+260]:1 << 0x7))+280]:8 +0x0.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x10e0, `lw` at 0x11ac, `lw` at 0x1244.
  8 such `ld` accesses load 8 bytes from ?, including `ld` at 0x10ec, `ld` at 0x1104, `ld` at 0x11a4.
  The `lbu` at 0x112c loads 1 byte from ret(pciio_info_mfast_get) +0x39.
  5 such `lw` accesses load 4 bytes from ret(pciio_info_mfast_get) +0x48, including `lw` at 0x1290, `lw` at 0x15a8, `lw` at 0x15d4.
  4 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x72, including `lh` at 0x1340, `lh` at 0x1500, `lh` at 0x1534.
  The `lw` at 0x138c loads 4 bytes from (ret(pciio_info_mfast_get) + one of 0xa98, 0xa9c) +0x0.
  4 such `ld` accesses load 8 bytes from table(sym(pci_space)) +0x0, including `ld` at 0x1404, `ld` at 0x14ec, `ld` at 0x1714.
  5 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1484, `sw` at 0x14a8, `sw` at 0x1648.
  The `lw` at 0x1540 loads 4 bytes from ret(pciio_info_mfast_get) +0x78.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1654, `sd` at 0x1864.
  2 such `sw` accesses store 4 bytes to (ret(pciio_info_mfast_get) + one of 0xa98, 0xa9c) +0x0, including `sw` at 0x1780, `sw` at 0x18a0.
  The `jal` at 0x103c calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1048 calls pciio_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x105c calls pciio_info_mfast_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x106c calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0x12f4 calls mutex_io_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1400 calls sprintf with a0=sp-736, a1=sym(.rodata), a2=entry(sym(pci_space)), a3=sym(.rodata), a4=sym(.rodata), a5=sym(.rodata), a6=sym(.rodata), a7=sym(.rodata).
  The `jal` at 0x14e8 calls sprintf with a0=sp-736, a1=sym(.rodata), a2=entry(sym(pci_space)), a3=?.
  The `jal` at 0x1728 calls sprintf with a0=sp-736, a1=sym(.rodata), a2=entry(sym(pci_space)), a3=?.
  The `jal` at 0x1778 calls pcireg_control_bit_set with a0=ret(pciio_info_mfast_get), a1=one of 0x400000, 0x800000, a2=?, a3=?, a6=0x2.
  The `jal` at 0x17bc calls sprintf with a0=sp-736, a1=sym(.rodata), a2=entry(sym(pci_space)), a3=sym(.rodata), a4=sym(.rodata), a7=sym(.rodata).
  The `jal` at 0x185c calls pcireg_device_set with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?, a6=0x2, a7=0xfffff.
  The `jal` at 0x1868 calls pcireg_tflush_get with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1894 calls pcireg_control_bit_clr with a0=ret(pciio_info_mfast_get), a1=one of 0x400000, 0x800000, a2=?, a3=?, a6=0x2.
  The `beq` branch at 0x1080 targets 0x10a0, is taken when at(=[(ret(pciio_info_mfast_get) + (a1 << 0x7))+256]) == 0, and falls through when at(=[(ret(pciio_info_mfast_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0x10a0 targets 0x1324, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x10ac targets 0x132c, is taken when s1(=a2) == ra(=0x7), and falls through when s1(=a2) != ra(=0x7).
  The `beq` branch at 0x10b4 targets 0x1410, is taken when s1(=a2) == ra(=0x1), and falls through when s1(=a2) != ra(=0x1).
  The `beq` branch at 0x10c0 targets 0x1128, is taken when a4(?) >= 0x6 (unsigned), and falls through when a4(?) < 0x6 (unsigned).
  The `beq` branch at 0x10e4 targets 0x1444, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x10fc targets 0x1110, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x1110 targets 0x144c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x1118 targets 0x112c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x1120 targets 0x12e0 and is always taken.
  The `bltz` branch at 0x1130 targets 0x12b4, is taken when a3(=[ret(pciio_info_mfast_get)+57]:1) < 0 (signed), and falls through when a3(=[ret(pciio_info_mfast_get)+57]:1) >= 0 (signed).
  The `beq` branch at 0x1194 targets 0x11e0 and is always taken.
  The `beq` branch at 0x119c targets 0x11b4, is taken when s4(?) == s5(?), and falls through when s4(?) != s5(?).
  The `bne` branch at 0x11b0 targets 0x11d0, is taken when a1(?) != a5(=-0x1), and falls through when a1(?) == a5(=-0x1).
  The `beq` branch at 0x11c8 targets 0x1614, is taken when s0(?) == a5(?), and falls through when s0(?) != a5(?).
  The `beq` branch at 0x11d8 targets 0x12bc, is taken when a4(?) >= t0(=([ret(pciio_info_mfast_get)+57]:1 + [ret(pciio_info_mfast_get)+57]:1)+2) (signed), and falls through when a4(?) < t0(=([ret(pciio_info_mfast_get)+57]:1 + [ret(pciio_info_mfast_get)+57]:1)+2) (signed).
  The `beq` branch at 0x120c targets 0x1218, is taken when s1(?) == a6(=0x2), and falls through when s1(?) != a6(=0x2).
  The `bne` branch at 0x1230 targets 0x11d0, is taken when a5(=one of 0x100000, 0x200000) < t1(?) (unsigned), and falls through when a5(=one of 0x100000, 0x200000) >= t1(?) (unsigned).
  The `beq` branch at 0x1240 targets 0x1250, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x1248 targets 0x119c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x1250 targets 0x11d0, is taken when a1(?) != s1(?), and falls through when a1(?) == s1(?).
  The `bne` branch at 0x126c targets 0x11d0, is taken when s0(?) < a3(?) (unsigned), and falls through when s0(?) >= a3(?) (unsigned).
  The `bne` branch at 0x1274 targets 0x11d4, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0x127c targets 0x1580, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x1284 targets 0x11d4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x1294 targets 0x1454, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x12ac targets 0x1468 and is always taken.
  The `beq` branch at 0x12bc targets 0x1340, is taken when s1(?) == a5(=0x4), and falls through when s1(?) != a5(=0x4).
  The `beq` branch at 0x12c4 targets 0x1340, is taken when s1(?) == a7(=0x5), and falls through when s1(?) != a7(=0x5).
  The `beq` branch at 0x12cc targets 0x1500, is taken when s1(?) == t0(=0x6), and falls through when s1(?) != t0(=0x6).
  The `beq` branch at 0x12d4 targets 0x1534, is taken when s1(?) == a6(=0x2), and falls through when s1(?) != a6(=0x2).
  The `beq` branch at 0x1324 targets 0x12e0 and is always taken.
  The `beq` branch at 0x1330 targets 0x1590, is taken when (s6(=a5) & 0x1000) == 0, and falls through when (s6(=a5) & 0x1000) != 0.
  The `beq` branch at 0x1338 targets 0x12e0 and is always taken.
  The `beq` branch at 0x1344 targets 0x15d4, is taken when a3(=[ret(pciio_info_mfast_get)+114]:2) == a6(=0x2), and falls through when a3(=[ret(pciio_info_mfast_get)+114]:2) != a6(=0x2).
  The `bne` branch at 0x1364 targets 0x14f8, is taken when a4(=0x7fffffff) < a5(=table(0x3fffffff)) (unsigned), and falls through when a4(=0x7fffffff) >= a5(=table(0x3fffffff)) (unsigned).
  The `beq` branch at 0x1374 targets 0x12e4, is taken when t0(=-0x1) == s3(?), and falls through when t0(=-0x1) != s3(?).
  The `beq` branch at 0x137c targets 0x1738, is taken when s1(?) == a6(=0x2), and falls through when s1(?) != a6(=0x2).
  The `beq` branch at 0x139c targets 0x12e4, is taken when s5(=one of 0x1000, 0x2000) == a1(?), and falls through when s5(=one of 0x1000, 0x2000) != a1(?).
  The `beq` branch at 0x13a4 targets 0x1760, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bgez` branch at 0x13b4 targets 0x1408, is taken when t8(=([sym(pcibr_debug_mask)] << 0x24)) >= 0 (signed), and falls through when t8(=([sym(pcibr_debug_mask)] << 0x24)) < 0 (signed).
  The `beq` branch at 0x13bc targets 0x1814, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x13d0 targets 0x1740, is taken when (a1(?) & 0x2000) == 0, and falls through when (a1(?) & 0x2000) != 0.
  The `beq` branch at 0x13d8 targets 0x1748, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1408 targets 0x12e0 and is always taken.
  The `bne` branch at 0x1420 targets 0x1434, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x1434 targets 0x10bc, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x143c targets 0x12e0 and is always taken.
  The `bne` branch at 0x1444 targets 0x112c, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x144c targets 0x12e0 and is always taken.
  The `beq` branch at 0x1480 targets 0x14ac, is taken when t0(=-0x1) == t1(?), and falls through when t0(=-0x1) != t1(?).
  The `bgez` branch at 0x14b4 targets 0x12e4, is taken when at(=([sym(pcibr_debug_mask)] << 0x24)) >= 0 (signed), and falls through when at(=([sym(pcibr_debug_mask)] << 0x24)) < 0 (signed).
  The `beq` branch at 0x14f0 targets 0x12e4 and is always taken.
  The `beq` branch at 0x14f8 targets 0x12e0 and is always taken.
  The `beq` branch at 0x1504 targets 0x17d4, is taken when a5(=[ret(pciio_info_mfast_get)+114]:2) == a6(=0x2), and falls through when a5(=[ret(pciio_info_mfast_get)+114]:2) != a6(=0x2).
  The `bne` branch at 0x1520 targets 0x15cc, is taken when a7(=0xbfffffff) < t0(=table(0x7fffffff)) (unsigned), and falls through when a7(=0xbfffffff) >= t0(=table(0x7fffffff)) (unsigned).
  The `beq` branch at 0x152c targets 0x1370 and is always taken.
  The `beq` branch at 0x1538 targets 0x181c, is taken when a2(=[ret(pciio_info_mfast_get)+114]:2) == a6(=0x2), and falls through when a2(=[ret(pciio_info_mfast_get)+114]:2) != a6(=0x2).
  The `beq` branch at 0x154c targets 0x160c, is taken when a3(=0xc0023) >= a4(=[ret(pciio_info_mfast_get)+120]) (signed), and falls through when a3(=0xc0023) < a4(=[ret(pciio_info_mfast_get)+120]) (signed).
  The `bne` branch at 0x156c targets 0x17cc, is taken when a4(=0x1ffffffff) < a5(=table(0xffffffff)) (unsigned), and falls through when a4(=0x1ffffffff) >= a5(=table(0xffffffff)) (unsigned).
  The `beq` branch at 0x1578 targets 0x1370 and is always taken.
  The `bne` branch at 0x1580 targets 0x11d4, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x1588 targets 0x1290 and is always taken.
  The `beq` branch at 0x1594 targets 0x1758, is taken when t8(=(a3 + a4)) >= 0x101 (unsigned), and falls through when t8(=(a3 + a4)) < 0x101 (unsigned).
  The `beq` branch at 0x15b8 targets 0x188c, is taken when a4(=[ret(pciio_info_mfast_get)+114]:2) == a5(=0x2), and falls through when a4(=[ret(pciio_info_mfast_get)+114]:2) != a5(=0x2).
  The `beq` branch at 0x15c4 targets 0x12e0 and is always taken.
  The `beq` branch at 0x15cc targets 0x12e0 and is always taken.
  The `beq` branch at 0x15d8 targets 0x1824, is taken when a1(=[ret(pciio_info_mfast_get)+72]) == 0, and falls through when a1(=[ret(pciio_info_mfast_get)+72]) != 0.
  The `bne` branch at 0x15e0 targets 0x1348, is taken when a1(=[ret(pciio_info_mfast_get)+72]) != t0(=0x1), and falls through when a1(=[ret(pciio_info_mfast_get)+72]) == t0(=0x1).
  The `bne` branch at 0x15fc targets 0x14f8, is taken when t1(=0xffffffff) < t2(=table(0xbfffffff)) (unsigned), and falls through when t1(=0xffffffff) >= t2(=table(0xbfffffff)) (unsigned).
  The `beq` branch at 0x1604 targets 0x136c and is always taken.
  The `beq` branch at 0x160c targets 0x12e0 and is always taken.
  The `beq` branch at 0x1614 targets 0x1878, is taken when s1(?) == a6(=0x2), and falls through when s1(?) != a6(=0x2).
  The `beq` branch at 0x1634 targets 0x1880, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x1640 targets 0x1850, is taken when ra(?) != v0(?), and falls through when ra(?) == v0(?).
  The `beq` branch at 0x165c targets 0x167c, is taken when s4(?) >= 0x2 (signed), and falls through when s4(?) < 0x2 (signed).
  The `beq` branch at 0x1674 targets 0x1694 and is always taken.
  The `beq` branch at 0x16b0 targets 0x16dc, is taken when a7(=-0x1) == t0(?), and falls through when a7(=-0x1) != t0(?).
  The `bgez` branch at 0x16e4 targets 0x12e0, is taken when at(=([sym(pcibr_debug_mask)] << 0x24)) >= 0 (signed), and falls through when at(=([sym(pcibr_debug_mask)] << 0x24)) < 0 (signed).
  The `beq` branch at 0x1730 targets 0x12e4 and is always taken.
  The `beq` branch at 0x1738 targets 0x1384 and is always taken.
  The `bne` branch at 0x1740 targets 0x13e0, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x1750 targets 0x13ec and is always taken.
  The `beq` branch at 0x1758 targets 0x12e0 and is always taken.
  The `beq` branch at 0x1770 targets 0x1894, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x178c targets 0x12e4, is taken when (s6(=0x8000000) & t0(=[sym(pcibr_debug_mask)])) == 0, and falls through when (s6(=0x8000000) & t0(=[sym(pcibr_debug_mask)])) != 0.
  The `beq` branch at 0x1794 targets 0x18a4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x17c4 targets 0x12e4 and is always taken.
  The `beq` branch at 0x17cc targets 0x12e0 and is always taken.
  The `beq` branch at 0x17d8 targets 0x18b0, is taken when a1(=[ret(pciio_info_mfast_get)+72]) == 0, and falls through when a1(=[ret(pciio_info_mfast_get)+72]) != 0.
  The `bne` branch at 0x17e4 targets 0x150c, is taken when a1(=[ret(pciio_info_mfast_get)+72]) != a7(=0x1), and falls through when a1(=[ret(pciio_info_mfast_get)+72]) == a7(=0x1).
  The `bne` branch at 0x1804 targets 0x15cc, is taken when t0(=0x13fffffff) < t1(=table(0xffffffff)) (unsigned), and falls through when t0(=0x13fffffff) >= t1(=table(0xffffffff)) (unsigned).
  The `beq` branch at 0x180c targets 0x152c and is always taken.
  The `beq` branch at 0x1814 targets 0x13cc and is always taken.
  The `beq` branch at 0x181c targets 0x12e0 and is always taken.
  The `bne` branch at 0x1840 targets 0x14f8, is taken when a2(=0x7fffffff) < a3(=table(0x3fffffff)) (unsigned), and falls through when a2(=0x7fffffff) >= a3(=table(0x3fffffff)) (unsigned).
  The `beq` branch at 0x1848 targets 0x136c and is always taken.
  The `beq` branch at 0x1870 targets 0x1648 and is always taken.
  The `beq` branch at 0x1878 targets 0x1628 and is always taken.
  The `beq` branch at 0x1884 targets 0x1640 and is always taken.
  The `beq` branch at 0x188c targets 0x15c4 and is always taken.
  The `beq` branch at 0x189c targets 0x1784 and is always taken.
  The `beq` branch at 0x18a8 targets 0x17a8 and is always taken.
  The `bne` branch at 0x18c4 targets 0x15cc, is taken when a0(=0xbfffffff) < a1(=table(0x7fffffff)) (unsigned), and falls through when a0(=0xbfffffff) >= a1(=table(0x7fffffff)) (unsigned).
  The `beq` branch at 0x18cc targets 0x152c and is always taken.
  The return at 0x131c has v0 = ?.

- `pcibr_piomap_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x18d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x18d4-0x1b1c (584 bytes).
  It occupies 584 bytes.
  The `lbu` at 0x191c loads 1 byte from ret(pcibr_info_get) +0x21c.
  The `lw` at 0x1934 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `ld` at 0x198c loads 8 bytes from ret(pcibr_info_get) +0x210.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x199c, `ld` at 0x19a8, `ld` at 0x1a34.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0x19d4, `sw` at 0x19f0, `sw` at 0x1a00.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x72, including `lh` at 0x19e0, `lh` at 0x1a10.
  9 such `sd` accesses store 8 bytes to ?, including `sd` at 0x19f4, `sd` at 0x19f8, `sd` at 0x19fc.
  The `sb` at 0x1a04 stores 1 byte to ?.
  The `jal` at 0x1910 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1924 calls pciio_info_mfast_get with a0=ret(pcibr_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x195c calls pcibr_addr_pci_to_xio [0x1004] with a0=a0 at entry (arg0), a1=[ret(pcibr_info_get)+540]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a6 at entry (arg6).
  The `jal` at 0x1980 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0x19b4 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x19c0 calls kmem_zalloc with a0=0x60, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1a24 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=ret(mutex_spinlock), a2=?, a3=0x2.
  The `jal` at 0x1a48 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x1a68 calls xtalk_piomap_alloc with a0=[ret(pciio_info_mfast_get)], a1=0x0, a2=ret(pcibr_addr_pci_to_xio), a3=a4 at entry (arg4), a4=a5 at entry (arg5).
  The `jal` at 0x1af0 calls pcibr_debug with a0=0x8000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x1b0c calls pcibr_debug with a0=0x8000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `beq` branch at 0x1930 targets 0x1ae4, is taken when s1(=a4) == 0, and falls through when s1(=a4) != 0.
  The `beq` branch at 0x1938 targets 0x1ae4, is taken when s7(=a5) == 0, and falls through when s7(=a5) != 0.
  The `beq` branch at 0x1968 targets 0x1b00, is taken when v0(=ret(pcibr_addr_pci_to_xio)) == at(=-0x1), and falls through when v0(=ret(pcibr_addr_pci_to_xio)) != at(=-0x1).
  The `beq` branch at 0x1994 targets 0x19b0, is taken when s0(=[ret(pcibr_info_get)+528]:8) == 0, and falls through when s0(=[ret(pcibr_info_get)+528]:8) != 0.
  The `beq` branch at 0x19a0 targets 0x1ab8, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x19ac targets 0x199c, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x19d8 targets 0x19f0, is taken when s2(=[ret(pcibr_info_get)+540]:1) == ra(=0xff), and falls through when s2(=[ret(pcibr_info_get)+540]:1) != ra(=0xff).
  The `beq` branch at 0x19e4 targets 0x19f0, is taken when at(=[ret(pciio_info_mfast_get)+114]:2) == a3(=0x2), and falls through when at(=[ret(pciio_info_mfast_get)+114]:2) != a3(=0x2).
  The `beq` branch at 0x1a14 targets 0x1ad4, is taken when v0(=[ret(pciio_info_mfast_get)+114]:2) == a3(=0x2), and falls through when v0(=[ret(pciio_info_mfast_get)+114]:2) != a3(=0x2).
  The `beq` branch at 0x1a1c targets 0x1a44, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0x1a50 targets 0x1a84, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1a70 targets 0x1ac8, is taken when v0(=ret(xtalk_piomap_alloc)) == 0, and falls through when v0(=ret(xtalk_piomap_alloc)) != 0.
  The `beq` branch at 0x1ab8 targets 0x19b4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1ac0 targets 0x19cc and is always taken.
  The `beq` branch at 0x1acc targets 0x1a84 and is always taken.
  The `beq` branch at 0x1adc targets 0x1a1c and is always taken.
  The `beq` branch at 0x1af8 targets 0x1a84 and is always taken.
  The `beq` branch at 0x1b14 targets 0x1a84 and is always taken.
  The return at 0x1ab0 has v0 = one of ?, 0x0.

- `pcibr_piomap_free` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1b1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x1b1c-0x1b6c (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0x1b30 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `sd` at 0x1b34 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `ld` at 0x1b38 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sd` at 0x1b3c stores 8 bytes to a0 (arg0 at entry) +0x30.
  The `lh` at 0x1b40 loads 2 bytes from [a0+64]:8 +0x72.
  The `sw` at 0x1b5c stores 4 bytes to a0 (arg0 at entry) +0x5c.
  The `sw` at 0x1b60 stores 4 bytes to a0 (arg0 at entry) +0x58.
  The `sd` at 0x1b68 stores 8 bytes to a0 (arg0 at entry) +0x50.
  The `jal` at 0x1b2c calls xtalk_piomap_free with a0=[a0+48]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x1b48 targets 0x1b5c, is taken when at(=[[a0+64]:8+114]:2) == v0(=0x2), and falls through when at(=[[a0+64]:8+114]:2) != v0(=0x2).
  The `beq` branch at 0x1b64 targets 0x1b50 and is always taken.
  The return at 0x1b54 has v0 = 0x2.

- `pcibr_piomap_addr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1b6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x1b6c-0x1b98 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0x1b6c loads 8 bytes from a0 (arg0 at entry) +0x28.
  The `ld` at 0x1b70 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x1b74 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `jal` at 0x1b84 calls xtalk_piomap_addr with a0=[a0+48]:8, a1=?, a2=a2 at entry (arg2), a3=[a0+16]:8, a4=[a0+40]:8.
  The return at 0x1b90 has v0 = ret(xtalk_piomap_addr).

- `pcibr_piomap_done` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1b98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x1b98-0x1bb4 (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0x1ba4 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `jal` at 0x1ba0 calls xtalk_piomap_done with a0=[a0+48]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1bac has v0 = ret(xtalk_piomap_done).

- `pcibr_piotrans_addr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1bb4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x1bb4-0x1c80 (204 bytes).
  It occupies 204 bytes.
  The `lbu` at 0x1be8 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0x1c0c loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0x1be0 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1bf0 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1c14 calls pcibr_addr_pci_to_xio [0x1004] with a0=a0 at entry (arg0), a1=[ret(pciio_hostinfo_get)+540]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1c34 calls xtalk_piotrans_addr with a0=[ret(pciio_info_mfast_get)], a1=0x0, a2=ret(pcibr_addr_pci_to_xio), a3=a4 at entry (arg4).
  The `jal` at 0x1c70 calls pcibr_debug with a0=0x10000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `beq` branch at 0x1c20 targets 0x1c64, is taken when v0(=ret(pcibr_addr_pci_to_xio)) == v1(=-0x1), and falls through when v0(=ret(pcibr_addr_pci_to_xio)) != v1(=-0x1).
  The `beq` branch at 0x1c78 targets 0x1c40 and is always taken.
  The return at 0x1c5c has v0 = one of ret(xtalk_piotrans_addr), 0x0.

- `pcibr_piospace_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1c80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x1c80-0x1e74 (500 bytes).
  It occupies 500 bytes.
  2 such `ld` accesses load 8 bytes from ret(pcibr_info_get) +0x1d0, including `ld` at 0x1cd8, `ld` at 0x1e08.
  The `lbu` at 0x1cf8 loads 1 byte from [ret(pcibr_info_get)+464]:8 +0x8.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1cfc, `ld` at 0x1d20, `ld` at 0x1d30.
  The `lbu` at 0x1d08 loads 1 byte from ?.
  The `lw` at 0x1d14 loads 4 bytes from ?.
  The `sb` at 0x1d4c stores 1 byte to ?.
  The `sd` at 0x1df8 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `sd` at 0x1dfc stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sw` at 0x1e00 stores 4 bytes to ret(kmem_zalloc) +0xc.
  The `sb` at 0x1e04 stores 1 byte to ret(kmem_zalloc) +0x8.
  The `sd` at 0x1e10 stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `sd` at 0x1e1c stores 8 bytes to ret(pcibr_info_get) +0x1d0.
  The `jal` at 0x1ca8 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1cb8 calls pciio_info_mfast_get with a0=ret(pcibr_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1cd0 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0x1d48 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=a4-1, a3=0x4, a4=0x5.
  The `jal` at 0x1d74 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=a4-1, a3=0x4, a4=0x5.
  The `jal` at 0x1d8c calls pcibr_debug with a0=0x8000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a2 at entry (arg2).
  The `jal` at 0x1dd8 calls pcibr_bus_addr_alloc with a0=ret(pciio_info_mfast_get), a1=0x0, a2=0x5, a3=0x0, a4=(a3 << 0x0), a5=(a4 << 0x0).
  The `jal` at 0x1df0 calls kmem_zalloc with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1e18 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=[ret(pcibr_info_get)+464]:8.
  The `jal` at 0x1e2c calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x1e44 calls pcibr_debug with a0=0x8000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a3 at entry (arg3).
  The `jal` at 0x1e64 calls pcibr_bus_addr_alloc with a0=ret(pciio_info_mfast_get), a1=0x0, a2=0x2, a3=0x0, a4=(a3 << 0x0), a5=(a4 << 0x0).
  The `beq` branch at 0x1cec targets 0x1d58, is taken when s0(=[ret(pcibr_info_get)+464]:8) == 0, and falls through when s0(=[ret(pcibr_info_get)+464]:8) != 0.
  The `beq` branch at 0x1cf4 targets 0x1d0c and is always taken.
  The `beq` branch at 0x1d00 targets 0x1d58, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1d0c targets 0x1cfc, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1d18 targets 0x1cfc, is taken when v1(?) != s1(=a2), and falls through when v1(?) == s1(=a2).
  The `bne` branch at 0x1d28 targets 0x1cfc, is taken when a0(?) < s2(=a3) (unsigned), and falls through when a0(?) >= s2(=a3) (unsigned).
  The `bnel` branch at 0x1d38 targets 0x1d00, is taken when (a5(?) & a2(=a4-1)) != 0, and falls through when (a5(?) & a2(=a4-1)) == 0; its branch-likely delay slot `ld s0,0(s0)` at 0x1d3c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x1d50 targets 0x1d98 and is always taken.
  The `beq` branch at 0x1d58 targets 0x1e54, is taken when s1(=a2) == a1(=0x2), and falls through when s1(=a2) != a1(=0x2).
  The `beq` branch at 0x1d60 targets 0x1dc8, is taken when s1(=a2) == a3(=0x4), and falls through when s1(=a2) != a3(=0x4).
  The `beq` branch at 0x1d68 targets 0x1dc8, is taken when s1(=a2) == a4(=0x5), and falls through when s1(=a2) != a4(=0x5).
  The `beq` branch at 0x1de4 targets 0x1e28, is taken when s0(=ret(pcibr_bus_addr_alloc)) == 0, and falls through when s0(=ret(pcibr_bus_addr_alloc)) != 0.
  The `beq` branch at 0x1e20 targets 0x1d98 and is always taken.
  The `beq` branch at 0x1e4c targets 0x1d98 and is always taken.
  The `beq` branch at 0x1e6c targets 0x1de4 and is always taken.
  The return at 0x1dbc has v0 = one of ?, 0x0, ret(pcibr_bus_addr_alloc).
  The instructions from 0x1dc4 to 0x1dc4 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_piospace_free` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1e74 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x1e74-0x1fa4 (304 bytes).
  It occupies 304 bytes.
  The `ld` at 0x1e9c loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `ld` at 0x1eb4 loads 8 bytes from ret(pcibr_info_get) +0x1d0.
  The `ld` at 0x1ec4 loads 8 bytes from [ret(pcibr_info_get)+464]:8 +0x10.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1ec8, `ld` at 0x1ed4, `ld` at 0x1ee0.
  The `sb` at 0x1f00 stores 1 byte to ?.
  The `jal` at 0x1e94 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1eac calls mutex_spinlock with a0=[ret(pcibr_info_get)+40]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0x1f04 calls mutex_io_spinunlock with a0=[ret(pcibr_info_get)+40]:8+128, a1=?, a2=?, a3=?, a6=sym(.rodata).
  The `jal` at 0x1f38 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=sym(.rodata).
  The `jal` at 0x1f44 calls mutex_io_spinunlock with a0=[ret(pcibr_info_get)+40]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0x1f5c calls hwgraph_vertex_name_get with a0=a0 at entry (arg0), a1=sp-1088, a2=0x400, a3=?.
  The `jal` at 0x1f6c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x1f84 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=sp-1088, a3=a3 at entry (arg3).
  The `jal` at 0x1f94 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x1eb8 targets 0x1ef0, is taken when s0(=[ret(pcibr_info_get)+464]:8) == 0, and falls through when s0(=[ret(pcibr_info_get)+464]:8) != 0.
  The `beq` branch at 0x1ec0 targets 0x1ed8 and is always taken.
  The `beq` branch at 0x1ecc targets 0x1ef0, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x1ed8 targets 0x1ec8, is taken when t8(?) != s1(=a2), and falls through when t8(?) == s1(=a2).
  The `bne` branch at 0x1ee4 targets 0x1f54, is taken when t9(?) != s2(=a3), and falls through when t9(?) == s2(=a3).
  The `beq` branch at 0x1ef0 targets 0x1f2c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1f4c targets 0x1f10 and is always taken.
  The `beq` branch at 0x1f9c targets 0x1eec and is always taken.
  The return at 0x1f24 has v0 = ret(mutex_io_spinunlock).

- `pcibr_flags_to_d64` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1fa4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x1fa4-0x2158 (436 bytes).
  It occupies 436 bytes.
  The `lh` at 0x2028 loads 2 bytes from a1 (arg1 at entry) +0x72.
  The `lh` at 0x20e0 loads 2 bytes from a1 (arg1 at entry) +0x74.
  The `jal` at 0x2148 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0x7d0, a3=a3 at entry (arg3).
  The `bgez` branch at 0x1fc8 targets 0x1fd8, is taken when t8(=(a0 << 0x26)) >= 0 (signed), and falls through when t8(=(a0 << 0x26)) < 0 (signed).
  The `beq` branch at 0x1fd0 targets 0x213c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1fec targets 0x2008, is taken when (s0(=a0) & 0x10) == 0, and falls through when (s0(=a0) & 0x10) != 0.
  The `beq` branch at 0x200c targets 0x201c, is taken when (s0(=a0) & 0x400) == 0, and falls through when (s0(=a0) & 0x400) != 0.
  The `beq` branch at 0x201c targets 0x2028, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x203c targets 0x2100, is taken when a1(=[a1+114]:2) == a5(=0x1), and falls through when a1(=[a1+114]:2) != a5(=0x1).
  The `beq` branch at 0x2044 targets 0x2104, is taken when a1(=[a1+114]:2) == a4(=0x2), and falls through when a1(=[a1+114]:2) != a4(=0x2).
  The `bgez` branch at 0x2050 targets 0x2060, is taken when t0(=(a0 << 0x29)) >= 0 (signed), and falls through when t0(=(a0 << 0x29)) < 0 (signed).
  The `bgez` branch at 0x2060 targets 0x2074, is taken when t1(=(a0 << 0x28)) >= 0 (signed), and falls through when t1(=(a0 << 0x28)) < 0 (signed).
  The `bgez` branch at 0x2074 targets 0x2084, is taken when t3(=(a0 << 0x2d)) >= 0 (signed), and falls through when t3(=(a0 << 0x2d)) < 0 (signed).
  The `bgez` branch at 0x2084 targets 0x2094, is taken when t8(=(a0 << 0x2c)) >= 0 (signed), and falls through when t8(=(a0 << 0x2c)) < 0 (signed).
  The `bgez` branch at 0x2098 targets 0x20a4, is taken when a1(=(a0 << 0x2b)) >= 0 (signed), and falls through when a1(=(a0 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0x20b8 targets 0x212c, is taken when a2(=(a0 << 0x2a)) >= 0 (signed), and falls through when a2(=(a0 << 0x2a)) < 0 (signed).
  The `beq` branch at 0x20c0 targets 0x20d4, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bgez` branch at 0x20d4 targets 0x20e0, is taken when a0(=(a0 << 0x27)) >= 0 (signed), and falls through when a0(=(a0 << 0x27)) < 0 (signed).
  The `beq` branch at 0x20e8 targets 0x20f4, is taken when (a5(=[a1+116]:2) & 0x1) == 0, and falls through when (a5(=[a1+116]:2) & 0x1) != 0.
  The `beq` branch at 0x210c targets 0x2118, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x211c targets 0x2050, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2124 targets 0x204c and is always taken.
  The `bne` branch at 0x212c targets 0x20cc, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x2134 targets 0x20d4 and is always taken.
  The `beq` branch at 0x2150 targets 0x1fd8 and is always taken.
  The return at 0x20f8 has v0 = ?.

- `pcibr_dmamap_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x2158 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x2158-0x2654 (1276 bytes).
  It occupies 1276 bytes.
  The `lw` at 0x2198 loads 4 bytes from ret(pciio_info_mfast_get) +0x7c.
  The `lw` at 0x21a8 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `lbu` at 0x221c loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lbu` at 0x2224 loads 1 byte from ret(pciio_info_mfast_get) +0x30.
  The `sw` at 0x222c stores 4 bytes to ret(kmem_zalloc) +0x4.
  3 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x72, including `lh` at 0x2230, `lh` at 0x24d4, `lh` at 0x2584.
  The `sb` at 0x2240 stores 1 byte to ret(kmem_zalloc) +0x28.
  The `sd` at 0x2244 stores 8 bytes to ret(kmem_zalloc) +0x20.
  The `sd` at 0x2248 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `sd` at 0x2250 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sb` at 0x2258 stores 1 byte to ret(kmem_zalloc) +0x8.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x74, including `lh` at 0x228c, `lh` at 0x2428.
  4 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x0, including `sw` at 0x22dc, `sw` at 0x2424, `sw` at 0x24c0.
  The `ld` at 0x22e0 loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  6 such `sd` accesses store 8 bytes to ret(kmem_zalloc) +0x38, including `sd` at 0x22ec, `sd` at 0x241c, `sd` at 0x24d0.
  3 such `sd` accesses store 8 bytes to ret(kmem_zalloc) +0x30, including `sd` at 0x22f4, `sd` at 0x2420, `sd` at 0x253c.
  2 such `lw` accesses load 4 bytes from ret(pciio_info_mfast_get) +0x51c, including `lw` at 0x2438, `lw` at 0x2560.
  The `lw` at 0x2468 loads 4 bytes from ?.
  The `ld` at 0x2504 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `sd` at 0x2548 stores 8 bytes to ret(kmem_zalloc) +0x50.
  The `sw` at 0x254c stores 4 bytes to ret(kmem_zalloc) +0x40.
  The `sd` at 0x2550 stores 8 bytes to ret(kmem_zalloc) +0x48.
  The `sw` at 0x2558 stores 4 bytes to ret(kmem_zalloc) +0x44.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x70, including `lh` at 0x2574, `lh` at 0x25d8.
  The `lw` at 0x259c loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `lw` at 0x25f0 loads 4 bytes from ret(kmem_zalloc) +0x0.
  The `ld` at 0x25f4 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  The `sw` at 0x263c stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x178.
  The `sd` at 0x2648 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x170.
  The `jal` at 0x217c calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2190 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x21b4 calls kmem_zalloc with a0=0x60, a1=?, a2=[ret(pciio_info_mfast_get)], a3=[ret(pciio_info_mfast_get)+124].
  The `jal` at 0x2208 calls xtalk_dmamap_alloc with a0=[ret(pciio_info_mfast_get)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x226c calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=([ret(pciio_info_mfast_get)+124] | a3), a3=0x898000, a4=0xff.
  The `jal` at 0x2284 calls pcibr_debug with a0=0x60000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x22a0 calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?, a4=-0x41.
  The `jal` at 0x22cc calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x8f8000, a4=one of -0x41, 0xff.
  The `jal` at 0x2318 calls pcibr_ate_alloc with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?, a4=one of -0x41, 0xff.
  The `jal` at 0x2338 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x1100000.
  The `jal` at 0x2358 calls pcibr_debug with a0=0x20000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=ret(pcibr_ate_alloc).
  The `jal` at 0x2368 calls pcibr_ate_free with a0=ret(pciio_info_mfast_get), a1=ret(pcibr_ate_alloc), a2=?, a3=?.
  The `jal` at 0x2380 calls pcibr_debug with a0=0x60000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x2388 calls xtalk_dmamap_free with a0=ret(xtalk_dmamap_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0x2394 calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `jal` at 0x23b4 calls pcibr_debug with a0=0x20000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x23bc calls xtalk_dmamap_free with a0=ret(xtalk_dmamap_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0x23c8 calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `jal` at 0x23f4 calls pcibr_debug with a0=0x20000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x2400 calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `jal` at 0x2414 calls pcibr_flags_to_d64 [0x1fa4] with a0=([ret(pciio_info_mfast_get)+124] | a3), a1=ret(pciio_info_mfast_get), a2=sym(.rodata), a3=?.
  The `jal` at 0x24b8 calls pcibr_flags_to_ate with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x2540 calls pcibr_ate_addr with a0=ret(pciio_info_mfast_get), a1=ret(pcibr_ate_alloc), a2=?, a3=?, a6=[ret(pciio_info_mfast_get)+114]:2.
  The `jal` at 0x25cc calls pcibr_rrb_alloc_more with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?, a6=one of 0x1, 0x2.
  The `jal` at 0x25e0 calls pcibr_rrb_alloc_more with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?, a5=0x1, a7=one of 0x1, 0x2.
  The `jal` at 0x2600 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=(0x40000000 | [ret(kmem_zalloc)]).
  The `jal` at 0x2614 calls pcibr_slot_config_addr with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x4, a3=?.
  The `jal` at 0x2628 calls pcibr_slot_config_get with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x4, a3=?.
  The `jal` at 0x2644 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?, a4=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `bne` branch at 0x21c4 targets 0x21fc, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x2210 targets 0x23e8, is taken when v0(=ret(xtalk_dmamap_alloc)) == 0, and falls through when v0(=ret(xtalk_dmamap_alloc)) != 0.
  The `beq` branch at 0x2228 targets 0x23d8, is taken when s3(=[ret(pciio_hostinfo_get)+540]:1) == a4(=0xff), and falls through when s3(=[ret(pciio_hostinfo_get)+540]:1) != a4(=0xff).
  The `beq` branch at 0x2238 targets 0x23e0, is taken when t8(=[ret(pciio_info_mfast_get)+114]:2) == t9(=0x2), and falls through when t8(=[ret(pciio_info_mfast_get)+114]:2) != t9(=0x2).
  The `beq` branch at 0x2254 targets 0x22b4, is taken when (s1(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) == 0, and falls through when (s1(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) != 0.
  The `beq` branch at 0x2274 targets 0x2410, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0x2294 targets 0x22b0, is taken when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0x22a8 targets 0x21d0 and is always taken.
  The `beq` branch at 0x22b8 targets 0x22f8, is taken when (s1(?) & 0x1) == 0, and falls through when (s1(?) & 0x1) != 0.
  The `bne` branch at 0x22d4 targets 0x2378, is taken when v0(=ret(pcibr_try_set_device)) != 0, and falls through when v0(=ret(pcibr_try_set_device)) == 0.
  The `beq` branch at 0x22f0 targets 0x21d0 and is always taken.
  The `beq` branch at 0x22fc targets 0x24a0, is taken when (s1(?) & 0x8000) == 0, and falls through when (s1(?) & 0x8000) != 0.
  The `beq` branch at 0x2324 targets 0x23a4, is taken when v0(=ret(pcibr_ate_alloc)) == t0(=-0x1), and falls through when v0(=ret(pcibr_ate_alloc)) != t0(=-0x1).
  The `beq` branch at 0x2340 targets 0x24b8, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0x2370 targets 0x23ac and is always taken.
  The `beq` branch at 0x239c targets 0x21d0 and is always taken.
  The `beq` branch at 0x23d0 targets 0x21d0 and is always taken.
  The `beq` branch at 0x23d8 targets 0x2240 and is always taken.
  The `beq` branch at 0x23e0 targets 0x2240 and is always taken.
  The `beq` branch at 0x2408 targets 0x21d0 and is always taken.
  The `bne` branch at 0x2430 targets 0x2498, is taken when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0, and falls through when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0.
  The `bne` branch at 0x2448 targets 0x2498, is taken when (a4(=[ret(pciio_info_mfast_get)+1308]) & a5(?)) != 0, and falls through when (a4(=[ret(pciio_info_mfast_get)+1308]) & a5(?)) == 0.
  The `beq` branch at 0x2470 targets 0x2498, is taken when a6(?) >= 0x2 (signed), and falls through when a6(?) < 0x2 (signed).
  The `bne` branch at 0x2490 targets 0x25dc, is taken when a6(?) < a7(=one of 0x1, 0x2) (signed), and falls through when a6(?) >= a7(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0x2498 targets 0x21d4 and is always taken.
  The `beq` branch at 0x24b0 targets 0x2314 and is always taken.
  The `beq` branch at 0x24d8 targets 0x2538, is taken when a6(=[ret(pciio_info_mfast_get)+114]:2) == 0, and falls through when a6(=[ret(pciio_info_mfast_get)+114]:2) != 0.
  The `beq` branch at 0x24e4 targets 0x2500, is taken when (s1(?) & 0x1000) == 0, and falls through when (s1(?) & 0x1000) != 0.
  The `bgez` branch at 0x250c targets 0x2524, is taken when a2(=([(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8 << 0x2b)) >= 0 (signed), and falls through when a2(=([(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8 << 0x2b)) < 0 (signed).
  The `beq` branch at 0x2524 targets 0x2538, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x256c targets 0x2598, is taken when (a6(=[ret(pciio_info_mfast_get)+1308]) & a7(?)) == 0, and falls through when (a6(=[ret(pciio_info_mfast_get)+1308]) & a7(?)) != 0.
  The `bne` branch at 0x257c targets 0x2590, is taken when s5(=ret(pcibr_ate_alloc)) < t1(=[ret(pciio_info_mfast_get)+112]:2) (signed), and falls through when s5(=ret(pcibr_ate_alloc)) >= t1(=[ret(pciio_info_mfast_get)+112]:2) (signed).
  The `beq` branch at 0x2588 targets 0x25f0, is taken when t2(=[ret(pciio_info_mfast_get)+114]:2) == 0, and falls through when t2(=[ret(pciio_info_mfast_get)+114]:2) != 0.
  The `beq` branch at 0x2590 targets 0x21d4 and is always taken.
  The `beq` branch at 0x25a4 targets 0x2574, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) >= 0x2 (signed), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) < 0x2 (signed).
  The `beq` branch at 0x25bc targets 0x2574, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) >= a6(=one of 0x1, 0x2) (signed), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) < a6(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0x25d4 targets 0x2578 and is always taken.
  The `beq` branch at 0x25e8 targets 0x2498 and is always taken.
  The `beq` branch at 0x264c targets 0x2590 and is always taken.
  The return at 0x21f4 has v0 = one of ?, ret(kmem_zalloc).

- `pcibr_dmamap_free` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x2654 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x2654-0x2750 (252 bytes).
  It occupies 252 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x265c, `ld` at 0x2710.
  The `lbu` at 0x2664 loads 1 byte from a0 (arg0 at entry) +0x8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x267c, `lw` at 0x26e4.
  The `lh` at 0x2694 loads 2 bytes from [a0+16]:8 +0x72.
  The `ll` at 0x26c4 loads 4 bytes from ?.
  The `sc` at 0x26d0 stores 4 bytes to ?.
  The `ld` at 0x26e0 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x2704 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `lw` at 0x2718 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `jal` at 0x26dc calls xtalk_dmamap_free with a0=[a0+24]:8, a1=?, a2=?, a3=?, a4=0xffffffff80000000, a5=([a0] << 0x21).
  The `jal` at 0x26fc calls pcibr_release_device with a0=[a0+16]:8, a1=?, a2=0x898000, a3=?.
  The `jal` at 0x2714 calls pcibr_ate_free with a0=[a0+16]:8, a1=[a0+64], a2=[a0+68], a3=?.
  The `jal` at 0x2724 calls pcibr_release_device with a0=[a0+16]:8, a1=?, a2=0x1100000, a3=?.
  The `jal` at 0x2738 calls kmem_free with a0=a0 at entry (arg0), a1=0x60, a2=?, a3=?.
  The `beq` branch at 0x2688 targets 0x26a4, is taken when a2(=[a0+8]:1) == at(=0xff), and falls through when a2(=[a0+8]:1) != at(=0xff).
  The `beq` branch at 0x2698 targets 0x26a4, is taken when v0(=[[a0+16]:8+114]:2) == v1(=0x2), and falls through when v0(=[[a0+16]:8+114]:2) != v1(=0x2).
  The `beq` branch at 0x26b4 targets 0x26dc, is taken when (a3(=[a0]) & a4(=0xffffffff80000000)) == 0, and falls through when (a3(=[a0]) & a4(=0xffffffff80000000)) != 0.
  The `bgez` branch at 0x26bc targets 0x26dc, is taken when a5(=([a0] << 0x21)) >= 0 (signed), and falls through when a5(=([a0] << 0x21)) < 0 (signed).
  The `beql` branch at 0x26d4 targets 0x26c4, is taken when a3(=table(-0x1)) == 0, and falls through when a3(=table(-0x1)) != 0; its branch-likely delay slot `nop` at 0x26d8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x26ec targets 0x2704, is taken when (a4(=[a0]) & 0x40) == 0, and falls through when (a4(=[a0]) & 0x40) != 0.
  The `beq` branch at 0x2708 targets 0x272c, is taken when a2(=[a0+68]) == 0, and falls through when a2(=[a0+68]) != 0.
  The return at 0x2748 has v0 = ret(kmem_free).

- `pcibr_addr_xio_to_pci` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x2750 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x2750-0x29d8 (648 bytes).
  It occupies 648 bytes.
  The `lh` at 0x2750 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lbu` at 0x27c8 loads 1 byte from a0 (arg0 at entry) +0x39.
  The `lbu` at 0x27cc loads 1 byte from a0 (arg0 at entry) +0x38.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x48, including `lw` at 0x27e8, `lw` at 0x28d8.
  The `ld` at 0x2888 loads 8 bytes from ?.
  The `beq` branch at 0x276c targets 0x28d8, is taken when at(=[a0+114]:2) == v1(=0x2), and falls through when at(=[a0+114]:2) != v1(=0x2).
  The `bne` branch at 0x277c targets 0x27a0, is taken when a1 < a3(=0x40000000) (unsigned), and falls through when a1 >= a3(=0x40000000) (unsigned).
  The `beq` branch at 0x2798 targets 0x2948, is taken when v1(=0x7fffffff) >= a3(=(a1 + a2)-1) (unsigned), and falls through when v1(=0x7fffffff) < a3(=(a1 + a2)-1) (unsigned).
  The `bne` branch at 0x27b0 targets 0x27c8, is taken when a1 < a3(=0x80000000) (unsigned), and falls through when a1 >= a3(=0x80000000) (unsigned).
  The `beq` branch at 0x27c0 targets 0x2950, is taken when a5(=0xbfffffff) >= v1(=(a1 + a2)-1) (unsigned), and falls through when a5(=0xbfffffff) < v1(=(a1 + a2)-1) (unsigned).
  The `beq` branch at 0x27d8 targets 0x2864, is taken when v0(=[a0+56]:1) >= t3(=[a0+57]:1+1) (signed), and falls through when v0(=[a0+56]:1) < t3(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x2800 targets 0x29c0 and is always taken.
  The `bne` branch at 0x2814 targets 0x2830, is taken when a1 < a2(?) (unsigned), and falls through when a1 >= a2(?) (unsigned).
  The `blez` branch at 0x281c targets 0x28c0, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `bne` branch at 0x2828 targets 0x2878, is taken when s0(=(a1 + a2)-1) < a2(?) (unsigned), and falls through when s0(=(a1 + a2)-1) >= a2(?) (unsigned).
  The `beq` branch at 0x2844 targets 0x2864, is taken when v0(?) >= t3(=[a0+57]:1+1) (signed), and falls through when v0(?) < t3(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x2854 targets 0x2808, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x285c targets 0x280c and is always taken.
  The `beq` branch at 0x2884 targets 0x2898, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x2890 targets 0x289c and is always taken.
  The `beq` branch at 0x28ac targets 0x28b8, is taken when (a2(?) & 0x1000) == 0, and falls through when (a2(?) & 0x1000) != 0.
  The `beq` branch at 0x28b8 targets 0x286c and is always taken.
  The `beq` branch at 0x28d0 targets 0x2824 and is always taken.
  The `beq` branch at 0x28dc targets 0x2958, is taken when a7(=[a0+72]) == 0, and falls through when a7(=[a0+72]) != 0.
  The `bne` branch at 0x28e4 targets 0x2778, is taken when a7(=[a0+72]) != v0(=0x1), and falls through when a7(=[a0+72]) == v0(=0x1).
  The `bne` branch at 0x28f8 targets 0x2914, is taken when a1 < a4(=0xc0000000) (unsigned), and falls through when a1 >= a4(=0xc0000000) (unsigned).
  The `beq` branch at 0x290c targets 0x29b8, is taken when a5(=0xffffffff) >= a6(=(a1 + a2)-1) (unsigned), and falls through when a5(=0xffffffff) < a6(=(a1 + a2)-1) (unsigned).
  The `bne` branch at 0x2920 targets 0x27c8, is taken when a1 < a6(=0x100000000) (unsigned), and falls through when a1 >= a6(=0x100000000) (unsigned).
  The `bne` branch at 0x2934 targets 0x27c8, is taken when a7(=0x13fffffff) < t0(=(a1 + a2)-1) (unsigned), and falls through when a7(=0x13fffffff) >= t0(=(a1 + a2)-1) (unsigned).
  The `beq` branch at 0x2940 targets 0x2868 and is always taken.
  The `beq` branch at 0x2948 targets 0x286c and is always taken.
  The `beq` branch at 0x2950 targets 0x286c and is always taken.
  The `bne` branch at 0x2964 targets 0x2988, is taken when a1 < v1(=0x40000000) (unsigned), and falls through when a1 >= v1(=0x40000000) (unsigned).
  The `beq` branch at 0x2980 targets 0x29ac, is taken when a3(=0x7fffffff) >= a4(=(a1 + a2)-1) (unsigned), and falls through when a3(=0x7fffffff) < a4(=(a1 + a2)-1) (unsigned).
  The `bne` branch at 0x2988 targets 0x27c8, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x299c targets 0x27c8, is taken when a4(=0xbfffffff) < a5(=(a1 + a2)-1) (unsigned), and falls through when a4(=0xbfffffff) >= a5(=(a1 + a2)-1) (unsigned).
  The `beq` branch at 0x29a4 targets 0x2868 and is always taken.
  The `beq` branch at 0x29b0 targets 0x2868 and is always taken.
  The `beq` branch at 0x29b8 targets 0x2868 and is always taken.
  The `beq` branch at 0x29d0 targets 0x2850 and is always taken.
  The return at 0x2870 has v0 = one of ?, a1+0xffffffffc0000000, a1+0xffffffff80000000.

- `pcibr_dmamap_addr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x29d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x29d8-0x2bb0 (472 bytes).
  It occupies 472 bytes.
  The `ld` at 0x29e0 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0x29e8 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0x2a0c loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `lbu` at 0x2a30 loads 1 byte from [a0+16]:8 +0x28.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x2a58, `ld` at 0x2b00, `ld` at 0x2b3c.
  The `lbu` at 0x2a98 loads 1 byte from a0 (arg0 at entry) +0x28.
  The `lbu` at 0x2ab0 loads 1 byte from [a0+16]:8 +0x58.
  The `ld` at 0x2abc loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `lw` at 0x2b18 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `ld` at 0x2b20 loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `lw` at 0x2b70 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x2b9c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x2a08 calls xtalk_dmamap_addr with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2ae8 calls pcibr_addr_xio_to_pci [0x2750] with a0=[a0+16]:8, a1=?, a2=a2 at entry (arg2), a3=?, a5=-0x1.
  The `jal` at 0x2b74 calls ate_write with a0=[a0+16]:8, a1=a0 at entry (arg0), a2=[a0+64], a3=?, a6=[a0+68].
  The `jal` at 0x2ba0 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a1 at entry (arg1), a4=(a1 + a2)-1, a6=[a0+68].
  The `beq` branch at 0x2a34 targets 0x2a94, is taken when (v0(=ret(xtalk_dmamap_addr)) & at(=0xf000000000000000)) == 0, and falls through when (v0(=ret(xtalk_dmamap_addr)) & at(=0xf000000000000000)) != 0.
  The `beq` branch at 0x2a48 targets 0x2ae4, is taken when a0(=[[a0+16]:8+40]:1) == t2(?), and falls through when a0(=[[a0+16]:8+40]:1) != t2(?).
  The `beq` branch at 0x2a50 targets 0x2a9c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2a94 targets 0x2a48 and is always taken.
  The `beq` branch at 0x2aa8 targets 0x2b18, is taken when (s2(=[a0]) & 0x1) == 0, and falls through when (s2(=[a0]) & 0x1) != 0.
  The `bne` branch at 0x2ab4 targets 0x2af8, is taken when at(=[[a0+16]:8+88]:1) != t2(?), and falls through when at(=[[a0+16]:8+88]:1) == t2(?).
  The `bne` branch at 0x2ac4 targets 0x2b10, is taken when t1(?) < v0(=[a0+48]:8) (unsigned), and falls through when t1(?) >= v0(=[a0+48]:8) (unsigned).
  The `beq` branch at 0x2ad4 targets 0x2b00, is taken when a1(=[a0+48]:8+0x80000000) >= a2(?) (unsigned), and falls through when a1(=[a0+48]:8+0x80000000) < a2(?) (unsigned).
  The `beq` branch at 0x2adc targets 0x2a74 and is always taken.
  The `beq` branch at 0x2af0 targets 0x2a70 and is always taken.
  The `beq` branch at 0x2af8 targets 0x2a70 and is always taken.
  The `beq` branch at 0x2b08 targets 0x2a70 and is always taken.
  The `beq` branch at 0x2b10 targets 0x2a74 and is always taken.
  The `bgez` branch at 0x2b2c targets 0x2b3c, is taken when a1(=([a0] << 0x2c)) >= 0 (signed), and falls through when a1(=([a0] << 0x2c)) < 0 (signed).
  The `bne` branch at 0x2b50 targets 0x2b84, is taken when a6(=[a0+68]) < a5(?) (signed), and falls through when a6(=[a0+68]) >= a5(?) (signed).
  The `beq` branch at 0x2b7c targets 0x2a74 and is always taken.
  The `beq` branch at 0x2ba8 targets 0x2a70 and is always taken.
  The return at 0x2a8c has v0 = one of ?, 0x0.

- `pcibr_dmamap_list` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x2bb0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x2bb0-0x2f48 (920 bytes).
  It occupies 920 bytes.
  The `ld` at 0x2bb8 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x2bc4 loads 8 bytes from a0 (arg0 at entry) +0x18.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x2c0c, `lw` at 0x2d50, `lw` at 0x2e48.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x2c74, `lw` at 0x2ee4.
  The `ld` at 0x2ca0 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `lbu` at 0x2cfc loads 1 byte from [a0+16]:8 +0x28.
  The `lw` at 0x2ddc loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `lw` at 0x2e74 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `ld` at 0x2e78 loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `lbu` at 0x2e88 loads 1 byte from a0 (arg0 at entry) +0x28.
  The `jal` at 0x2be0 calls xtalk_dmamap_list with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x2c10 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x2c58 calls alenlist_cursor_init with a0=ret(xtalk_dmamap_list), a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x2ca4 calls alenlist_get with a0=ret(xtalk_dmamap_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0x2d3c calls alenlist_append with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2d54 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x2d78 calls alenlist_get with a0=ret(xtalk_dmamap_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0x2d94 calls alenlist_cursor_init with a0=?, a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x2e04 calls ate_write with a0=[a0+16]:8, a1=a0 at entry (arg0), a2=?, a3=?, a6=[a0+68].
  The `jal` at 0x2e34 calls alenlist_replace with a0=?, a1=0x0, a2=sp-144, a3=sp-152.
  The `jal` at 0x2e4c calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x2e64 calls alenlist_destroy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2e94 calls pcibr_addr_xio_to_pci [0x2750] with a0=[a0+16]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x2eb0 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x2ec4 calls alenlist_create with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2ee8 calls alenlist_done with a0=ret(xtalk_dmamap_list), a1=?, a2=?, a3=?.
  The `jal` at 0x2f0c calls pcibr_debug with a0=0x10, a1=[a0+4], a2=sym(.rodata), a3=?, a6=[a0+68].
  The `jal` at 0x2f38 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `bne` branch at 0x2bf8 targets 0x2c50, is taken when v0(=ret(xtalk_dmamap_list)) != 0, and falls through when v0(=ret(xtalk_dmamap_list)) == 0.
  The `beq` branch at 0x2c68 targets 0x2ec0, is taken when (s8(=a2) & 0x4) == 0, and falls through when (s8(=a2) & 0x4) != 0.
  The `beq` branch at 0x2c7c targets 0x2e74, is taken when (t8(=[a0]) & 0x40) == 0, and falls through when (t8(=[a0]) & 0x40) != 0.
  The `bne` branch at 0x2cac targets 0x2d88, is taken when v0(=ret(alenlist_get)) != 0, and falls through when v0(=ret(alenlist_get)) == 0.
  The `beq` branch at 0x2ce4 targets 0x2e84, is taken when (a3(?) & a0(=0xf000000000000000)) == 0, and falls through when (a3(?) & a0(=0xf000000000000000)) != 0.
  The `beq` branch at 0x2d00 targets 0x2e8c, is taken when a0(=[[a0+16]:8+40]:1) == v0(?), and falls through when a0(=[[a0+16]:8+40]:1) != v0(?).
  The `beq` branch at 0x2d08 targets 0x2da4, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2d18 targets 0x2e1c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x2d28 targets 0x2e24, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `beq` branch at 0x2d44 targets 0x2d64, is taken when v0(=ret(alenlist_append)) == 0, and falls through when v0(=ret(alenlist_append)) != 0.
  The `beq` branch at 0x2d5c targets 0x2e54 and is always taken.
  The `beq` branch at 0x2d80 targets 0x2cc8, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0x2d88 targets 0x2ee8, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `beq` branch at 0x2d9c targets 0x2c20 and is always taken.
  The `beq` branch at 0x2dc4 targets 0x2f1c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x2df0 targets 0x2ef8, is taken when a6(=[a0+68]) < a7(?) (signed), and falls through when a6(=[a0+68]) >= a7(?) (signed).
  The `beq` branch at 0x2e1c targets 0x2d34, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `beq` branch at 0x2e3c targets 0x2d64, is taken when v0(=ret(alenlist_replace)) == 0, and falls through when v0(=ret(alenlist_replace)) != 0.
  The `beq` branch at 0x2e54 targets 0x2c18, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0x2e5c targets 0x2c18, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `beq` branch at 0x2e6c targets 0x2c1c and is always taken.
  The `beq` branch at 0x2e7c targets 0x2c8c and is always taken.
  The `beq` branch at 0x2e84 targets 0x2cfc and is always taken.
  The `bne` branch at 0x2e9c targets 0x2e1c, is taken when v0(=ret(pcibr_addr_xio_to_pci)) != 0, and falls through when v0(=ret(pcibr_addr_xio_to_pci)) == 0.
  The `beq` branch at 0x2eb8 targets 0x2e54 and is always taken.
  The `beq` branch at 0x2ed0 targets 0x2f28, is taken when v0(=ret(alenlist_create)) == 0, and falls through when v0(=ret(alenlist_create)) != 0.
  The `bne` branch at 0x2ed8 targets 0x2e54, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2ee0 targets 0x2c78 and is always taken.
  The `beq` branch at 0x2ef0 targets 0x2d90 and is always taken.
  The `beq` branch at 0x2f14 targets 0x2e54 and is always taken.
  The `beq` branch at 0x2f20 targets 0x2dcc and is always taken.
  The `beq` branch at 0x2f40 targets 0x2ed8 and is always taken.
  The return at 0x2c48 has v0 = one of 0x0, ?.

- `pcibr_dmamap_done` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x2f48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x2f48-0x2fec (164 bytes).
  It occupies 164 bytes.
  The `lw` at 0x2f48 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lbu` at 0x2f6c loads 1 byte from a0 (arg0 at entry) +0x8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x2f84, `ld` at 0x2fa8.
  The `lh` at 0x2f88 loads 2 bytes from [a0+16]:8 +0x72.
  The `sw` at 0x2fa0 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `ll` at 0x2fb8 loads 4 bytes from ?.
  The `sc` at 0x2fc4 stores 4 bytes to ?.
  The `ld` at 0x2fd4 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `jal` at 0x2fd0 calls xtalk_dmamap_done with a0=[a0+24]:8, a1=?, a2=a0 at entry (arg0), a3=?.
  The `beq` branch at 0x2f60 targets 0x2fd0, is taken when (a4(=[a0]) & at(=0xffffffff80000000)) == 0, and falls through when (a4(=[a0]) & at(=0xffffffff80000000)) != 0.
  The `beq` branch at 0x2f7c targets 0x2f98, is taken when a3(=[a0+8]:1) == v0(=0xff), and falls through when a3(=[a0+8]:1) != v0(=0xff).
  The `beq` branch at 0x2f90 targets 0x2fe4, is taken when v1(=[[a0+16]:8+114]:2) == a0(=0x2), and falls through when v1(=[[a0+16]:8+114]:2) != a0(=0x2).
  The `bgez` branch at 0x2f9c targets 0x2fd0, is taken when a6(?) >= 0 (signed), and falls through when a6(?) < 0 (signed).
  The `beql` branch at 0x2fc8 targets 0x2fb8, is taken when a5(=table(-0x1)) == 0, and falls through when a5(=table(-0x1)) != 0; its branch-likely delay slot `nop` at 0x2fcc runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2fe4 targets 0x2f98 and is always taken.
  The return at 0x2fdc has v0 = ret(xtalk_dmamap_done).

- `pcibr_get_dmatrans_node` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x2fec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x2fec-0x302c (64 bytes).
  It occupies 64 bytes.
  The `ld` at 0x3004 loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  The `lh` at 0x3020 loads 2 bytes from table(sym(nasid_to_compact_node)) +0x0.
  The `jal` at 0x2ff4 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2ffc calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The return at 0x3024 has v0 = entry(sym(nasid_to_compact_node)).

- `pcibr_dmatrans_addr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x302c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x302c-0x33cc (928 bytes).
  It occupies 928 bytes.
  The `lw` at 0x3070 loads 4 bytes from ret(pciio_info_mfast_get) +0x7c.
  The `lw` at 0x3080 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `lbu` at 0x3088 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lbu` at 0x30d0 loads 1 byte from ret(pciio_info_mfast_get) +0x28.
  The `ld` at 0x30f8 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x150.
  The `lw` at 0x3108 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x74, including `lh` at 0x316c, `lh` at 0x32a4.
  The `ld` at 0x3198 loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  The `lbu` at 0x31b0 loads 1 byte from ret(pciio_info_mfast_get) +0x58.
  The `ld` at 0x31d0 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  The `lw` at 0x31e0 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `lbu` at 0x3220 loads 1 byte from ret(pciio_info_mfast_get) +0x30.
  The `sd` at 0x329c stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x150.
  The `sw` at 0x32a0 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `sw` at 0x32c4 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `sd` at 0x32c8 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  2 such `lw` accesses load 4 bytes from ret(pciio_info_mfast_get) +0x51c, including `lw` at 0x32cc, `lw` at 0x3324.
  The `lw` at 0x32e8 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `ld` at 0x32f8 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `lw` at 0x337c loads 4 bytes from ?.
  The `jal` at 0x3050 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3064 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x308c calls xtalk_dmatrans_addr with a0=[ret(pciio_info_mfast_get)], a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x315c calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x898000.
  The `jal` at 0x3204 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x8f8000, a5=0xffffffff.
  The `jal` at 0x3234 calls pcibr_addr_xio_to_pci [0x2750] with a0=ret(pciio_info_mfast_get), a1=?, a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x3260 calls pcibr_debug with a0=0x40000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a2 at entry (arg2), a4=(a2 + a3)-1, a5=ret(xtalk_dmatrans_addr).
  The `jal` at 0x3284 calls pcibr_debug with a0=0x40000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a2 at entry (arg2), a4=(a2 + a3)-1.
  The `jal` at 0x3294 calls pcibr_flags_to_d64 [0x1fa4] with a0=?, a1=ret(pciio_info_mfast_get), a2=?, a3=?.
  The `jal` at 0x3350 calls pcibr_rrb_alloc_more with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?, a4=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384], a7=0x1.
  The `jal` at 0x33bc calls pcibr_rrb_alloc_more with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?, a6=0x1.
  The `beq` branch at 0x3098 targets 0x3244, is taken when v0(=ret(xtalk_dmatrans_addr)) == 0, and falls through when v0(=ret(xtalk_dmatrans_addr)) != 0.
  The `beq` branch at 0x30ac targets 0x321c, is taken when (v0(=ret(xtalk_dmatrans_addr)) & v1(=0xf000000000000000)) == 0, and falls through when (v0(=ret(xtalk_dmatrans_addr)) & v1(=0xf000000000000000)) != 0.
  The `beq` branch at 0x30b4 targets 0x3270, is taken when v0(=ret(xtalk_dmatrans_addr)) == a0(=-0x1), and falls through when v0(=ret(xtalk_dmatrans_addr)) != a0(=-0x1).
  The `beq` branch at 0x30d4 targets 0x3230, is taken when t8(=[ret(pciio_info_mfast_get)+40]:1) == s4(?), and falls through when t8(=[ret(pciio_info_mfast_get)+40]:1) != s4(?).
  The `beq` branch at 0x30e0 targets 0x318c, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a4)) & 0x40) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a4)) & 0x40) != 0.
  The `bgez` branch at 0x30f4 targets 0x3224, is taken when ra(=(([ret(pciio_info_mfast_get)+124] | a4) << 0x26)) >= 0 (signed), and falls through when ra(=(([ret(pciio_info_mfast_get)+124] | a4) << 0x26)) < 0 (signed).
  The `beq` branch at 0x3100 targets 0x3150, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+336]:8) == t8(=-0x1), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+336]:8) != t8(=-0x1).
  The `bne` branch at 0x310c targets 0x3150, is taken when t9(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]) != s0(?), and falls through when t9(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]) == s0(?).
  The `beq` branch at 0x3164 targets 0x3294, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0x3174 targets 0x3184, is taken when (a4(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (a4(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0x317c targets 0x3120 and is always taken.
  The `bne` branch at 0x3194 targets 0x3214, is taken when v0(=0x80000000) < s5(=a3) (unsigned), and falls through when v0(=0x80000000) >= s5(=a3) (unsigned).
  The `bne` branch at 0x31a8 targets 0x3214, is taken when s3(?) < a0(=[ret(pciio_info_mfast_get)+80]:8) (unsigned), and falls through when s3(?) >= a0(=[ret(pciio_info_mfast_get)+80]:8) (unsigned).
  The `bne` branch at 0x31b4 targets 0x3214, is taken when a3(=[ret(pciio_info_mfast_get)+88]:1) != s4(?), and falls through when a3(=[ret(pciio_info_mfast_get)+88]:1) == s4(?).
  The `bne` branch at 0x31c8 targets 0x3214, is taken when v0(=0x80000000) < a4(?) (unsigned), and falls through when v0(=0x80000000) >= a4(?) (unsigned).
  The `beq` branch at 0x31d8 targets 0x31f4, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]:8) == a5(=0xffffffff), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]:8) != a5(=0xffffffff).
  The `bne` branch at 0x31e4 targets 0x31f4, is taken when t8(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]) != s0(?), and falls through when t8(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]) == s0(?).
  The `beq` branch at 0x31ec targets 0x3124 and is always taken.
  The `beq` branch at 0x320c targets 0x32c4, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0x3214 targets 0x3120 and is always taken.
  The `beq` branch at 0x321c targets 0x30d0 and is always taken.
  The `beq` branch at 0x3228 targets 0x30fc and is always taken.
  The `beq` branch at 0x323c targets 0x3120 and is always taken.
  The `beq` branch at 0x3268 targets 0x3120 and is always taken.
  The `beq` branch at 0x328c targets 0x3120 and is always taken.
  The `beq` branch at 0x32ac targets 0x3324, is taken when (a5(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (a5(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0x32bc targets 0x3120 and is always taken.
  The `bne` branch at 0x32dc targets 0x331c, is taken when (t8(=[ret(pciio_info_mfast_get)+1308]) & t9(?)) != 0, and falls through when (t8(=[ret(pciio_info_mfast_get)+1308]) & t9(?)) == 0.
  The `beq` branch at 0x32f0 targets 0x331c, is taken when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) >= 0x2 (signed), and falls through when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) < 0x2 (signed).
  The `bne` branch at 0x3314 targets 0x3348, is taken when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) < v0(=one of 0x1, 0x2) (signed), and falls through when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) >= v0(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0x331c targets 0x3120 and is always taken.
  The `beq` branch at 0x3334 targets 0x3360, is taken when (t0(=[ret(pciio_info_mfast_get)+1308]) & t1(?)) == 0, and falls through when (t0(=[ret(pciio_info_mfast_get)+1308]) & t1(?)) != 0.
  The `beq` branch at 0x3340 targets 0x32bc and is always taken.
  The `beq` branch at 0x3358 targets 0x331c and is always taken.
  The `beq` branch at 0x338c targets 0x32bc, is taken when a4(?) >= 0x2 (signed), and falls through when a4(?) < 0x2 (signed).
  The `beq` branch at 0x33b0 targets 0x32bc, is taken when a4(?) >= v0(=one of 0x1, 0x2) (signed), and falls through when a4(?) < v0(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0x33c4 targets 0x32bc and is always taken.
  The return at 0x3144 has v0 = ?.
  The instructions from 0x314c to 0x314c are not reached by any path from the entry, and their branches are not listed.

- `pcibr_dmatrans_list` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x33cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x33cc-0x379c (976 bytes).
  It occupies 976 bytes.
  The `lw` at 0x340c loads 4 bytes from ret(pciio_info_mfast_get) +0x7c.
  The `lbu` at 0x3414 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0x341c loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `ld` at 0x343c loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x150.
  The `lw` at 0x344c loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `lbu` at 0x356c loads 1 byte from ret(pciio_info_mfast_get) +0x28.
  The `sd` at 0x35e8 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x150.
  The `sw` at 0x35ec stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `ld` at 0x3648 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  The `ld` at 0x3658 loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  The `lw` at 0x3668 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `sd` at 0x36e8 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  The `sw` at 0x36f0 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `lbu` at 0x36f8 loads 1 byte from ret(pciio_info_mfast_get) +0x30.
  The `lbu` at 0x371c loads 1 byte from ret(pciio_info_mfast_get) +0x58.
  The `jal` at 0x33e0 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x33f8 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3474 calls xtalk_dmatrans_list with a0=?, a1=0x0, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x3494 calls pcibr_release_device with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=one of 0x0, 0x898000, 0x8f8000, a3=?.
  The `jal` at 0x34f0 calls alenlist_cursor_init with a0=ret(xtalk_dmatrans_list), a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x3528 calls alenlist_get with a0=ret(xtalk_dmatrans_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0x35a4 calls alenlist_replace with a0=?, a1=0x0, a2=sp-144, a3=sp-152.
  The `jal` at 0x35c4 calls alenlist_get with a0=ret(xtalk_dmatrans_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0x35fc calls alenlist_cursor_init with a0=?, a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x361c calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=([ret(pciio_info_mfast_get)+124] | a3), a3=0x898000.
  The `jal` at 0x3630 calls pcibr_flags_to_d64 [0x1fa4] with a0=([ret(pciio_info_mfast_get)+124] | a3), a1=ret(pciio_info_mfast_get), a2=?, a3=?.
  The `jal` at 0x368c calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=([ret(pciio_info_mfast_get)+124] | a3), a3=0x8f8000.
  The `jal` at 0x36b8 calls alenlist_destroy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x36cc calls pcibr_addr_xio_to_pci [0x2750] with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3750 calls alenlist_append with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3768 calls alenlist_create with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3784 calls alenlist_done with a0=ret(xtalk_dmatrans_list), a1=?, a2=?, a3=?.
  The `beq` branch at 0x3434 targets 0x3648, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) != 0.
  The `beq` branch at 0x3444 targets 0x3610, is taken when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+336]:8) == ra(=-0x1), and falls through when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+336]:8) != ra(=-0x1).
  The `bne` branch at 0x3450 targets 0x3610, is taken when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]) != s0(=([ret(pciio_info_mfast_get)+124] | a3)), and falls through when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]) == s0(=([ret(pciio_info_mfast_get)+124] | a3)).
  The `bne` branch at 0x347c targets 0x34e4, is taken when v0(=ret(xtalk_dmatrans_list)) != 0, and falls through when v0(=ret(xtalk_dmatrans_list)) == 0.
  The `beq` branch at 0x3488 targets 0x349c, is taken when s4(=one of 0x0, 0x898000, 0x8f8000) == 0, and falls through when s4(=one of 0x0, 0x898000, 0x8f8000) != 0.
  The `beq` branch at 0x349c targets 0x34ac, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x34a4 targets 0x36b8, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x3508 targets 0x3768, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x4) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x4) != 0.
  The `bne` branch at 0x3530 targets 0x35d4, is taken when v0(=ret(alenlist_get)) != 0, and falls through when v0(=ret(alenlist_get)) == 0.
  The `beq` branch at 0x3554 targets 0x36f4, is taken when (a1(?) & v0(=0xf000000000000000)) == 0, and falls through when (a1(?) & v0(=0xf000000000000000)) != 0.
  The `beq` branch at 0x355c targets 0x3794, is taken when v1(=-0x1) == a1(?), and falls through when v1(=-0x1) != a1(?).
  The `beq` branch at 0x3574 targets 0x36c8, is taken when a0(=[ret(pciio_info_mfast_get)+40]:1) == v0(?), and falls through when a0(=[ret(pciio_info_mfast_get)+40]:1) != v0(?).
  The `beq` branch at 0x357c targets 0x36fc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x358c targets 0x3748, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x35ac targets 0x3488, is taken when v0(=ret(alenlist_replace)) != 0, and falls through when v0(=ret(alenlist_replace)) == 0.
  The `beq` branch at 0x35cc targets 0x353c, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0x35d4 targets 0x35f0, is taken when s4(=one of 0x0, 0x898000, 0x8f8000) == 0, and falls through when s4(=one of 0x0, 0x898000, 0x8f8000) != 0.
  The `beq` branch at 0x35e0 targets 0x36e8, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x35f0 targets 0x3784, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x3604 targets 0x34b4 and is always taken.
  The `bltz` branch at 0x3624 targets 0x34b0, is taken when v0(=ret(pcibr_try_set_device)) < 0 (signed), and falls through when v0(=ret(pcibr_try_set_device)) >= 0 (signed).
  The `beq` branch at 0x3640 targets 0x345c and is always taken.
  The `beq` branch at 0x3660 targets 0x367c, is taken when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]:8) == t8(=0xffffffff), and falls through when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]:8) != t8(=0xffffffff).
  The `bne` branch at 0x366c targets 0x3680, is taken when t9(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]) != s0(=([ret(pciio_info_mfast_get)+124] | a3)), and falls through when t9(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]) == s0(=([ret(pciio_info_mfast_get)+124] | a3)).
  The `beq` branch at 0x3674 targets 0x346c and is always taken.
  The `bltz` branch at 0x3694 targets 0x34b0, is taken when v0(=ret(pcibr_try_set_device)) < 0 (signed), and falls through when v0(=ret(pcibr_try_set_device)) >= 0 (signed).
  The `beq` branch at 0x36b0 targets 0x3468 and is always taken.
  The `beq` branch at 0x36c0 targets 0x34b0 and is always taken.
  The `bne` branch at 0x36d8 targets 0x3588, is taken when v0(=ret(pcibr_addr_xio_to_pci)) != 0, and falls through when v0(=ret(pcibr_addr_xio_to_pci)) == 0.
  The `beq` branch at 0x36e0 targets 0x3488 and is always taken.
  The `beq` branch at 0x36ec targets 0x35f0 and is always taken.
  The `beq` branch at 0x36f4 targets 0x356c and is always taken.
  The `bne` branch at 0x3708 targets 0x3488, is taken when t8(?) < a0(?) (unsigned), and falls through when t8(?) >= a0(?) (unsigned).
  The `bne` branch at 0x3714 targets 0x3488, is taken when a1(?) < t9(?) (unsigned), and falls through when a1(?) >= t9(?) (unsigned).
  The `bne` branch at 0x3720 targets 0x3488, is taken when ra(=[ret(pciio_info_mfast_get)+88]:1) != v0(?), and falls through when ra(=[ret(pciio_info_mfast_get)+88]:1) == v0(?).
  The `bne` branch at 0x3738 targets 0x3488, is taken when at(?) < v1(?) (unsigned), and falls through when at(?) >= v1(?) (unsigned).
  The `beq` branch at 0x3740 targets 0x3588 and is always taken.
  The `bne` branch at 0x3758 targets 0x3488, is taken when v0(=ret(alenlist_append)) != 0, and falls through when v0(=ret(alenlist_append)) == 0.
  The `beq` branch at 0x3760 targets 0x35b4 and is always taken.
  The `beq` branch at 0x3774 targets 0x3514, is taken when v0(=ret(alenlist_create)) >= 0x1 (unsigned), and falls through when v0(=ret(alenlist_create)) < 0x1 (unsigned).
  The `beq` branch at 0x377c targets 0x3488 and is always taken.
  The `beq` branch at 0x378c targets 0x35f8 and is always taken.
  The `beq` branch at 0x3794 targets 0x34b0 and is always taken.
  The return at 0x34dc has v0 = one of 0x0, ?.
  The instructions from 0x360c to 0x360c are not reached by any path from the entry, and their branches are not listed.

- `pcibr_dmamap_drain` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x379c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x379c-0x37b8 (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0x37a8 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `jal` at 0x37a4 calls xtalk_dmamap_drain with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x37b0 has v0 = ret(xtalk_dmamap_drain).

- `pcibr_dmaaddr_drain` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x37b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x37b8-0x37f8 (64 bytes).
  It occupies 64 bytes.
  The `lw` at 0x37d8 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0x37c8 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x37d0 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x37e0 calls xtalk_dmaaddr_drain with a0=[ret(pciio_info_mfast_get)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The return at 0x37f0 has v0 = ret(xtalk_dmaaddr_drain).

- `pcibr_dmalist_drain` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x37f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x37f8-0x3830 (56 bytes).
  It occupies 56 bytes.
  The `lw` at 0x3814 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0x3804 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x380c calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3818 calls xtalk_dmalist_drain with a0=[ret(pciio_info_mfast_get)], a1=a1 at entry (arg1), a2=?, a3=?.
  The return at 0x3828 has v0 = ret(xtalk_dmalist_drain).

- `pcibr_dmamap_pciaddr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x3830 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x3830-0x3838 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0x3834 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The return at 0x3830 has v0 = [a0+56]:8.

- `pcibr_provider_startup` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x3838 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x3838-0x3840 (8 bytes).
  It occupies 8 bytes.
  The return at 0x3838 has v0 = ?.

- `pcibr_provider_shutdown` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x3840 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x3840-0x3848 (8 bytes).
  It occupies 8 bytes.
  The return at 0x3840 has v0 = ?.

- `pcibr_reset` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x3848 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x3848-0x3b04 (700 bytes).
  It occupies 700 bytes.
  The `lbu` at 0x385c loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0x3870 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  The `lbu` at 0x3874 loads 1 byte from ret(pciio_info_mfast_get) +0x31.
  The `lw` at 0x3884 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x100.
  The `lbu` at 0x389c loads 1 byte from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x104.
  The `lbu` at 0x38ac loads 1 byte from ret(pciio_info_mfast_get) +0x33.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x38d8, `lw` at 0x3a4c.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x38f0, `ld` at 0x3918, `ld` at 0x39c4.
  The `sw` at 0x3938 stores 4 bytes to ?.
  3 such `ld` accesses load 8 bytes from table(0x0) +0x0, including `ld` at 0x3ad8, `ld` at 0x3aec, `ld` at 0x3b00.
  The `jal` at 0x3854 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3868 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x38c8 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)), a3=a0 at entry (arg0).
  The `jal` at 0x392c calls pcibr_func_config_get with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=0x4.
  The `jal` at 0x395c calls pcireg_control_bit_clr with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3964 calls nano_delay with a0=sp-128, a1=?, a2=?, a3=?.
  The `jal` at 0x3970 calls pcireg_control_bit_set with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3978 calls nano_delay with a0=sp-128, a1=?, a2=?, a3=?.
  The `jal` at 0x399c calls pcibr_func_config_set with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3a50 calls pcibr_func_config_set with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=0x4.
  The `jal` at 0x3a70 calls mutex_io_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3a94 calls pcibr_debug with a0=0x8, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a0 at entry (arg0).
  The `beq` branch at 0x3894 targets 0x38a0, is taken when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+256]) == 0, and falls through when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+256]) != 0.
  The `bne` branch at 0x38a4 targets 0x3a84, is taken when s3(?) < a0(=[ret(pciio_info_mfast_get)+49]:1) (signed), and falls through when s3(?) >= a0(=[ret(pciio_info_mfast_get)+49]:1) (signed).
  The `bne` branch at 0x38b4 targets 0x3a84, is taken when a4(=[ret(pciio_info_mfast_get)+51]:1) < s3(?) (signed), and falls through when a4(=[ret(pciio_info_mfast_get)+51]:1) >= s3(?) (signed).
  The `blez` branch at 0x38ec targets 0x393c, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0x38f4 targets 0x3ac8 and is always taken.
  The `beq` branch at 0x3910 targets 0x393c, is taken when s0(?) >= s6(?) (signed), and falls through when s0(?) < s6(?) (signed).
  The `beq` branch at 0x391c targets 0x38fc, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x3934 targets 0x38fc and is always taken.
  The `blez` branch at 0x3980 targets 0x3a60, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0x3988 targets 0x3adc and is always taken.
  The `beq` branch at 0x39ac targets 0x39e0, is taken when s0(?) >= 0x6 (signed), and falls through when s0(?) < 0x6 (signed).
  The `bne` branch at 0x39c8 targets 0x3990, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0x39d8 targets 0x39b4, is taken when s0(?) < 0x6 (signed), and falls through when s0(?) >= 0x6 (signed).
  The `beq` branch at 0x39f0 targets 0x3a14, is taken when s7(?) >= s6(?) (signed), and falls through when s7(?) < s6(?) (signed).
  The `beq` branch at 0x3a04 targets 0x39e0, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x3a0c targets 0x39b8 and is always taken.
  The `beq` branch at 0x3a14 targets 0x3af0 and is always taken.
  The `beq` branch at 0x3a2c targets 0x3a60, is taken when s0(?) >= s6(?) (signed), and falls through when s0(?) < s6(?) (signed).
  The `beq` branch at 0x3a38 targets 0x3a1c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x3a58 targets 0x3a20 and is always taken.
  The `beq` branch at 0x3a78 targets 0x3aa0 and is always taken.
  The `beq` branch at 0x3ad4 targets 0x391c and is always taken.
  The `beq` branch at 0x3ae8 targets 0x39fc and is always taken.
  The `beq` branch at 0x3afc targets 0x3a38 and is always taken.
  The return at 0x3ac0 has v0 = one of -0x1, 0x0.
  The instructions from 0x3a80 to 0x3a80 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_endian_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x3b04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x3b04-0x3bec (232 bytes).
  It occupies 232 bytes.
  The `lbu` at 0x3b28 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0x3b5c loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `sd` at 0x3be0 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `jal` at 0x3b20 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3b30 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3b40 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0x3b80 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x3ba0 calls pcibr_debug with a0=0x4000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=[ret(pciio_hostinfo_get)+540]:1, a5=sym(device_bits).
  The `jal` at 0x3bcc calls pcireg_device_set with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8, a4=0x180000, a7=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `jal` at 0x3bdc calls pcireg_tflush_get with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `beq` branch at 0x3b58 targets 0x3b68, is taken when s0(=a1) == s2(=a2), and falls through when s0(=a1) != s2(=a2).
  The `beq` branch at 0x3b60 targets 0x3b6c and is always taken.
  The `bne` branch at 0x3b70 targets 0x3bc4, is taken when a3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8) != s0(?), and falls through when a3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8) == s0(?).
  The `beq` branch at 0x3be4 targets 0x3b78 and is always taken.
  The return at 0x3bbc has v0 = a2.

- `pcibr_priority_bits_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x3bec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x3bec-0x3d44 (344 bytes).
  It occupies 344 bytes.
  The `lw` at 0x3c24 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `ld` at 0x3c50 loads 8 bytes from (a0 + (a1 << 0x7)) +0x138.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x140, including `lw` at 0x3cb8, `lw` at 0x3cf4.
  2 such `sw` accesses store 4 bytes to (a0 + (a1 << 0x7)) +0x140, including `sw` at 0x3cc8, `sw` at 0x3d0c.
  The `sd` at 0x3ce0 stores 8 bytes to (a0 + (a1 << 0x7)) +0x138.
  The `jal` at 0x3c3c calls mutex_spinlock with a0=a0+128, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3c94 calls mutex_io_spinunlock with a0=a0+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x3cd8 calls pcireg_device_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x3ce4 calls pcireg_tflush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x3c5c targets 0x3cb8, is taken when s0(=a2) == a1(=0x1), and falls through when s0(=a2) != a1(=0x1).
  The `beq` branch at 0x3c64 targets 0x3cb8, is taken when s0(=a2) == a0(=0x2), and falls through when s0(=a2) != a0(=0x2).
  The `beq` branch at 0x3c6c targets 0x3cf4, is taken when s0(=a2) == 0, and falls through when s0(=a2) != 0.
  The `bne` branch at 0x3c74 targets 0x3cd4, is taken when a2(=[(a0 + (a1 << 0x7))+312]:8) != s1(?), and falls through when a2(=[(a0 + (a1 << 0x7))+312]:8) == s1(?).
  The `bne` branch at 0x3cc4 targets 0x3c74, is taken when t8(=[(a0 + (a1 << 0x7))+320]+1) != a1(=0x1), and falls through when t8(=[(a0 + (a1 << 0x7))+320]+1) == a1(=0x1).
  The `beq` branch at 0x3ccc targets 0x3d18 and is always taken.
  The `beq` branch at 0x3cec targets 0x3c80 and is always taken.
  The `blez` branch at 0x3cfc targets 0x3c74, is taken when v0(=[(a0 + (a1 << 0x7))+320]) <= 0 (signed), and falls through when v0(=[(a0 + (a1 << 0x7))+320]) > 0 (signed).
  The `bne` branch at 0x3d08 targets 0x3c74, is taken when v0(=[(a0 + (a1 << 0x7))+320]-1) != 0, and falls through when v0(=[(a0 + (a1 << 0x7))+320]-1) == 0.
  The `beq` branch at 0x3d10 targets 0x3d28 and is always taken.
  The `beq` branch at 0x3d18 targets 0x3d3c, is taken when s5(=one of 0x0, 0x200000) == 0, and falls through when s5(=one of 0x0, 0x200000) != 0.
  The `beq` branch at 0x3d20 targets 0x3c74 and is always taken.
  The `beq` branch at 0x3d28 targets 0x3c74, is taken when s5(=one of 0x0, 0x200000) == 0, and falls through when s5(=one of 0x0, 0x200000) != 0.
  The `beq` branch at 0x3d34 targets 0x3c74 and is always taken.
  The `beq` branch at 0x3d3c targets 0x3c74 and is always taken.
  The return at 0x3cb0 has v0 = one of -0x1, 0x0.

- `pcibr_priority_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x3d44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x3d44-0x3d90 (76 bytes).
  It occupies 76 bytes.
  The `lbu` at 0x3d64 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `jal` at 0x3d54 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3d60 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3d70 calls pcibr_priority_bits_set with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=a1 at entry (arg1), a3=?.
  The return at 0x3d88 has v0 = a1.

- `pcibr_device_flags_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x3d90 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x3d90-0x3f90 (512 bytes).
  It occupies 512 bytes.
  The `lbu` at 0x3dac loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lh` at 0x3e88 loads 2 bytes from ret(pciio_info_mfast_get) +0x72.
  The `ld` at 0x3ec0 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `sd` at 0x3f4c stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `lw` at 0x3f70 loads 4 bytes from ret(pciio_info_mfast_get) +0x78.
  The `jal` at 0x3da4 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3dbc calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3eac calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=(a1 << 0x2c), a2=?, a3=(a1 << 0x2b), a7=(a1 << 0x25).
  The `jal` at 0x3ee4 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x3f04 calls pcibr_debug with a0=0x4000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=[ret(pciio_hostinfo_get)+540]:1, a5=sym(device_bits).
  The `jal` at 0x3f38 calls pcireg_device_set with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The `jal` at 0x3f48 calls pcireg_tflush_get with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `bgez` branch at 0x3df0 targets 0x3f58, is taken when v0(=(a1 << 0x2f)) >= 0 (signed), and falls through when v0(=(a1 << 0x2f)) < 0 (signed).
  The `bgez` branch at 0x3df8 targets 0x3e04, is taken when a3(=(a1 << 0x2e)) >= 0 (signed), and falls through when a3(=(a1 << 0x2e)) < 0 (signed).
  The `bgez` branch at 0x3e08 targets 0x3e14, is taken when v1(=(a1 << 0x2d)) >= 0 (signed), and falls through when v1(=(a1 << 0x2d)) < 0 (signed).
  The `bgez` branch at 0x3e18 targets 0x3e28, is taken when a1(=(a1 << 0x2c)) >= 0 (signed), and falls through when a1(=(a1 << 0x2c)) < 0 (signed).
  The `bgez` branch at 0x3e28 targets 0x3e38, is taken when a3(=(a1 << 0x2b)) >= 0 (signed), and falls through when a3(=(a1 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0x3e38 targets 0x3e48, is taken when a4(=(a1 << 0x2a)) >= 0 (signed), and falls through when a4(=(a1 << 0x2a)) < 0 (signed).
  The `bgez` branch at 0x3e48 targets 0x3e54, is taken when a5(=(a1 << 0x29)) >= 0 (signed), and falls through when a5(=(a1 << 0x29)) < 0 (signed).
  The `beq` branch at 0x3e58 targets 0x3e68, is taken when (s2(=a1) & a0(=0x800000)) == 0, and falls through when (s2(=a1) & a0(=0x800000)) != 0.
  The `bgez` branch at 0x3e6c targets 0x3e78, is taken when a7(=(a1 << 0x25)) >= 0 (signed), and falls through when a7(=(a1 << 0x25)) < 0 (signed).
  The `bgez` branch at 0x3e7c targets 0x3e88, is taken when t0(=(a1 << 0x24)) >= 0 (signed), and falls through when t0(=(a1 << 0x24)) < 0 (signed).
  The `beq` branch at 0x3e90 targets 0x3f68, is taken when t1(=[ret(pciio_info_mfast_get)+114]:2) == t2(=0x2), and falls through when t1(=[ret(pciio_info_mfast_get)+114]:2) != t2(=0x2).
  The `bne` branch at 0x3e98 targets 0x3eac, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x3ea0 targets 0x3f10, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x3ed0 targets 0x3f30, is taken when t3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8) != s2(?), and falls through when t3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8) == s2(?).
  The `beq` branch at 0x3f50 targets 0x3ed8 and is always taken.
  The `bltz` branch at 0x3f58 targets 0x3e00, is taken when a3(=(a1 << 0x2e)) < 0 (signed), and falls through when a3(=(a1 << 0x2e)) >= 0 (signed).
  The `beq` branch at 0x3f60 targets 0x3e08 and is always taken.
  The `beq` branch at 0x3f68 targets 0x3e98, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x3f7c targets 0x3e98, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x3f88 targets 0x3e98 and is always taken.
  The return at 0x3f28 has v0 = 0x1.

- `pcibr_pcix_rbars_calc` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x3f90 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x3f90-0x4020 (144 bytes).
  It occupies 144 bytes.
  The `lw` at 0x3f90 loads 4 bytes from a0 (arg0 at entry) +0x508.
  The `lw` at 0x3fc4 loads 4 bytes from a0 (arg0 at entry) +0x50c.
  The `ld` at 0x4004 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `jal` at 0x400c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+16]:8, a3=0x10, a4=[a0+1288], a7=a0 at entry (arg0).
  The `beq` branch at 0x3fa4 targets 0x3ff4, is taken when a4(=[a0+1288]) == 0, and falls through when a4(=[a0+1288]) != 0.
  The `beq` branch at 0x3fb0 targets 0x3ffc, is taken when a4(=[a0+1288]) >= 0x11 (signed), and falls through when a4(=[a0+1288]) < 0x11 (signed).
  The `bne` branch at 0x3fdc targets 0x3fec, is taken when v0(?) < 0x65 (signed), and falls through when v0(?) >= 0x65 (signed).
  The `beq` branch at 0x3fe4 targets 0x3ff0 and is always taken.
  The `beq` branch at 0x4018 targets 0x3ff4 and is always taken.
  The return at 0x3ff4 has v0 = one of 0x13, ?, 0x0.

- `pcibr_dma_enabled` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x4020 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x4020-0x404c (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x403c loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0x4028 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4030 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x4038 calls xtalk_dma_enabled with a0=[ret(pciio_info_mfast_get)], a1=?, a2=?, a3=?.
  The return at 0x4044 has v0 = ret(xtalk_dma_enabled).

- `pcibr_debug` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x404c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x404c-0x42ac (608 bytes).
  It occupies 608 bytes.
  The `lh` at 0x4268 loads 2 bytes from abs 0xffffffffffffc420.
  The `jal` at 0x4080 calls bzero with a0=sp-624, a1=0x100, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x40b8 calls hwgraph_vertex_name_get with a0=a1 at entry (arg1), a1=sp-624, a2=0x100, a3=?.
  The `jal` at 0x40e8 calls strcmp with a0=?, a1=[sym(pcibr_debug_module)]:8, a2=?, a3=?.
  The `jal` at 0x4108 calls kmem_zalloc with a0=0x400, a1=0x0, a2=?, a3=?.
  The `jal` at 0x4150 calls strcmp with a0=sym(.rodata), a1=[sym(pcibr_debug_module)]:8, a2=?, a3=?.
  The `jal` at 0x4160 calls strcpy with a0=sp-368, a1=sp-624, a2=?, a3=?.
  The `jal` at 0x4170 calls strstr with a0=sp-368, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4194 calls strstr with a0=sp-624, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x41bc calls strstr with a0=sp-624, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x41d8 calls strstr with a0=sp-624, a1=sym(.rodata), a2=[sym(pcibr_debug_slot)], a3=?.
  The `jal` at 0x4204 calls atoi with a0=ret(strstr)+7, a1=?, a2=?, a3=?.
  The `jal` at 0x4218 calls atoi with a0=ret(strstr)+8, a1=?, a2=[sym(pcibr_debug_slot)], a3=?.
  The `jal` at 0x422c calls atoi with a0=ret(strstr)+5, a1=?, a2=?, a3=?.
  The `jal` at 0x4250 calls strtok_r with a0=ret(strstr)+7, a1=sym(.rodata), a2=sp-112, a3=?.
  The `jal` at 0x426c calls printf with a0=sym(.rodata), a1=[-0x3be0]:2, a2=sp-624, a3=?.
  The `jal` at 0x427c calls vsprintf with a0=ret(kmem_zalloc), a1=a2 at entry (arg2), a2=sp-40, a3=?.
  The `jal` at 0x4290 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x429c calls kmem_free with a0=ret(kmem_zalloc), a1=0x400, a2=?, a3=?.
  The `beq` branch at 0x40a0 targets 0x4118, is taken when (v1(=[sym(pcibr_debug_mask)]) & a0) == 0, and falls through when (v1(=[sym(pcibr_debug_mask)]) & a0) != 0.
  The `beq` branch at 0x40a8 targets 0x4134, is taken when s2(=a1) == 0, and falls through when s2(=a1) != 0.
  The `beq` branch at 0x40c0 targets 0x4148, is taken when v0(=ret(hwgraph_vertex_name_get)) == 0, and falls through when v0(=ret(hwgraph_vertex_name_get)) != 0.
  The `beq` branch at 0x40dc targets 0x4108, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x40f0 targets 0x4118, is taken when v0(=ret(strcmp)) != 0, and falls through when v0(=ret(strcmp)) == 0.
  The `bne` branch at 0x40f8 targets 0x4118, is taken when t9(=[sym(pcibr_debug_widget)]) != s1(?), and falls through when t9(=[sym(pcibr_debug_widget)]) == s1(?).
  The `bne` branch at 0x4100 targets 0x4118, is taken when ra(=[sym(pcibr_debug_slot)]) != s3(?), and falls through when ra(=[sym(pcibr_debug_slot)]) == s3(?).
  The `bne` branch at 0x4110 targets 0x4260, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x4140 targets 0x40d4 and is always taken.
  The `beq` branch at 0x4158 targets 0x41f0, is taken when v0(=ret(strcmp)) == 0, and falls through when v0(=ret(strcmp)) != 0.
  The `bne` branch at 0x4178 targets 0x4240, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x4188 targets 0x41ac, is taken when v0(=[sym(pcibr_debug_widget)]) == s3(=-0x1), and falls through when v0(=[sym(pcibr_debug_widget)]) != s3(=-0x1).
  The `bne` branch at 0x419c targets 0x4204, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x41a4 targets 0x41b0 and is always taken.
  The `beq` branch at 0x41b0 targets 0x41c8, is taken when v0(=[sym(pcibr_debug_widget)]) == s3(=-0x1), and falls through when v0(=[sym(pcibr_debug_widget)]) != s3(=-0x1).
  The `bne` branch at 0x41c4 targets 0x4218, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x41cc targets 0x41fc, is taken when a2(=[sym(pcibr_debug_slot)]) == s3(=-0x1), and falls through when a2(=[sym(pcibr_debug_slot)]) != s3(=-0x1).
  The `bne` branch at 0x41e0 targets 0x422c, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x41e8 targets 0x40d4 and is always taken.
  The `beq` branch at 0x41f4 targets 0x4184 and is always taken.
  The `beq` branch at 0x41fc targets 0x40d4 and is always taken.
  The `beq` branch at 0x4210 targets 0x41a4 and is always taken.
  The `beq` branch at 0x4224 targets 0x41c8 and is always taken.
  The `beq` branch at 0x4238 targets 0x40d4 and is always taken.
  The `beq` branch at 0x4258 targets 0x4184 and is always taken.
  The `beq` branch at 0x42a4 targets 0x411c and is always taken.
  The return at 0x412c has v0 = one of ?, ret(kmem_free).

- `pcibr_businfo_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x42ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x42ac-0x42ec (64 bytes).
  It occupies 64 bytes.
  The `sw` at 0x42c4 stores 4 bytes to ret(pciio_info_mfast_get) +0xaa0.
  The `sw` at 0x42d0 stores 4 bytes to ret(pciio_info_mfast_get) +0xaa4.
  The `sw` at 0x42d8 stores 4 bytes to ret(pciio_info_mfast_get) +0xaa8.
  The `sw` at 0x42e0 stores 4 bytes to ret(pciio_info_mfast_get) +0xaac.
  The `jal` at 0x42b4 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x42bc calls pciio_info_mfast_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The return at 0x42e4 has v0 = ret(pciio_info_mfast_get)+2720.

- `pcibr_bridge_ptr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x42ec
  **Inferred.** Role (from name): computes a PIO address for a bridge register window. It calls `xtalk_piotrans_addr` at 0x4304 with a0 = a0, a1 0, a2 0, a3 8 and a4 0. It then compares a word loaded from +0x4 with 0xd102 (the `beq` at 0x4324) and with 0xd112 (the `bne` at 0x4338), and a second word with 0x24 (the `bne` at 0x4350). The return at 0x4368 is either the result of `xtalk_piotrans_addr` or that result plus 0x800000.
  Reviewed: 2026-11-12

- `pcibr_bridge_ptr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x42ec
  **Inferred.** It calls xtalk_piotrans_addr with a1 = 0x0, a2 = 0x0, a3 = 0x8 and a4 = 0x0 [call 1]. It loads words at +0x4 of that result [@0x430c] [@0x432c] [@0x4340]. It compares a value with 0xd102 [@0x4324 taken]. Its return value is one of the xtalk_piotrans_addr result and that result plus 0x800000 [@0x4368].
  Role (from facts): one call [call 1] whose result is returned either as is or plus 0x800000 [@0x4368].
  Reviewed: 2026-11-12

- `pcibr_pio_flush_read` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x4398 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x4398-0x4404 (108 bytes).
  It occupies 108 bytes.
  The `lbu` at 0x43cc loads 1 byte from a1 (arg1 at entry) +0x0.
  The `sb` at 0x43d0 stores 1 byte to a2 (arg2 at entry) +0x0.
  The `ld` at 0x43e0 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `sd` at 0x43e8 stores 8 bytes to a2 (arg2 at entry) +0x0.
  The `lhu` at 0x43ec loads 2 bytes from a1 (arg1 at entry) +0x0.
  The `sh` at 0x43f4 stores 2 bytes to a2 (arg2 at entry) +0x0.
  The `lw` at 0x43f8 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `sw` at 0x4400 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `beq` branch at 0x43a4 targets 0x43cc, is taken when a3 == at(=0x1), and falls through when a3 != at(=0x1).
  The `beq` branch at 0x43ac targets 0x43ec, is taken when a3 == v0(=0x2), and falls through when a3 != v0(=0x2).
  The `beq` branch at 0x43b4 targets 0x43f8, is taken when a3 == a5(=0x4), and falls through when a3 != a5(=0x4).
  The `bne` branch at 0x43bc targets 0x43d8, is taken when a3 != a6(=0x8), and falls through when a3 == a6(=0x8).
  The `beq` branch at 0x43c4 targets 0x43e0 and is always taken.
  The `beq` branch at 0x43e4 targets 0x43d4 and is always taken.
  The `beq` branch at 0x43f0 targets 0x43d4 and is always taken.
  The `beq` branch at 0x43fc targets 0x43d4 and is always taken.
  The return at 0x43d8 has v0 = one of 0x0, 0x1.

- `pcibr_pio_flush_del` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x4404 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x4404-0x440c (8 bytes).
  It occupies 8 bytes.
  The return at 0x4404 has v0 = ?.

- `pcibr_pio_flush_init` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x440c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x440c-0x4414 (8 bytes).
  It occupies 8 bytes.
  The return at 0x440c has v0 = 0x0.

- `idbg_pss_func` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x4414 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x4414-0x459c (392 bytes).
  It occupies 392 bytes.
  The `ld` at 0x4428 loads 8 bytes from (a0 + (a1 << 0x3)) +0x0.
  The `lw` at 0x4454 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x8.
  The `lbu` at 0x4464 loads 1 byte from [(a0 + (a1 << 0x3))]:8 +0x10.
  The `lbu` at 0x4470 loads 1 byte from [(a0 + (a1 << 0x3))]:8 +0x11.
  The `lbu` at 0x447c loads 1 byte from [(a0 + (a1 << 0x3))]:8 +0x12.
  The `lw` at 0x4488 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x14.
  The `lw` at 0x4494 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x18.
  The `lw` at 0x44ac loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x1c.
  The `ld` at 0x44bc loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x30.
  The `ld` at 0x44c8 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x40.
  The `ld` at 0x44cc loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x38.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x44f0, `lw` at 0x4560.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x44f4, `ld` at 0x4500, `ld` at 0x4510.
  The `ld` at 0x4524 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x1a8.
  The `ld` at 0x4528 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x1a0.
  The `jal` at 0x4440 calls qprintf with a0=sym(.rodata)+2392, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4450 calls vertex_to_name with a0=[[(a0 + (a1 << 0x3))]:8+8], a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0x445c calls qprintf with a0=sym(.rodata)+2392, a1=sp-304, a2=?, a3=?.
  The `jal` at 0x4468 calls qprintf with a0=sym(.rodata)+2392, a1=[[(a0 + (a1 << 0x3))]:8+16]:1, a2=?, a3=?.
  The `jal` at 0x4474 calls qprintf with a0=sym(.rodata)+2392, a1=[[(a0 + (a1 << 0x3))]:8+17]:1, a2=?, a3=?.
  The `jal` at 0x4480 calls qprintf with a0=sym(.rodata)+2392, a1=[[(a0 + (a1 << 0x3))]:8+18]:1, a2=?, a3=?.
  The `jal` at 0x448c calls qprintf with a0=sym(.rodata)+2392, a1=[[(a0 + (a1 << 0x3))]:8+20], a2=?, a3=?.
  The `jal` at 0x4498 calls qprintf with a0=sym(.rodata)+2392, a1=[[(a0 + (a1 << 0x3))]:8+24], a2=?, a3=?.
  The `jal` at 0x44a8 calls vertex_to_name with a0=[[(a0 + (a1 << 0x3))]:8+28], a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0x44b4 calls qprintf with a0=sym(.rodata)+2392, a1=sp-304, a2=?, a3=?.
  The `jal` at 0x44c0 calls qprintf with a0=sym(.rodata)+2392, a1=[[(a0 + (a1 << 0x3))]:8+48]:8, a2=?, a3=?.
  The `jal` at 0x44d0 calls qprintf with a0=sym(.rodata)+2392, a1=[[(a0 + (a1 << 0x3))]:8+56]:8, a2=[[(a0 + (a1 << 0x3))]:8+64]:8, a3=?.
  The `jal` at 0x450c calls qprintf with a0=sym(.rodata)+2392, a1=?, a2=?, a3=?.
  The `jal` at 0x452c calls qprintf with a0=sym(.rodata)+2392, a1=[[(a0 + (a1 << 0x3))]:8+416]:8, a2=[[(a0 + (a1 << 0x3))]:8+424]:8, a3=?.
  The `jal` at 0x4534 calls qprintf with a0=sym(.rodata)+2392, a1=?, a2=?, a3=?.
  The `jal` at 0x453c calls qprintf with a0=sym(.rodata)+2392, a1=?, a2=?, a3=?.
  The `jal` at 0x455c calls qprintf with a0=sym(.rodata)+2392, a1=?, a2=?, a3=?.
  The `jal` at 0x4578 calls qprintf with a0=sym(.rodata)+2392, a1=?, a2=?, a3=?.
  The `beq` branch at 0x4434 targets 0x4580, is taken when s0(=[(a0 + (a1 << 0x3))]:8) == 0, and falls through when s0(=[(a0 + (a1 << 0x3))]:8) != 0.
  The `bne` branch at 0x451c targets 0x44e4, is taken when s2(?) < 0x6 (signed), and falls through when s2(?) >= 0x6 (signed).
  The `bne` branch at 0x456c targets 0x454c, is taken when s2(?) < 0x4 (signed), and falls through when s2(?) >= 0x4 (signed).
  The return at 0x4594 has v0 = one of ?, ret(qprintf).

- `idbg_pss_info` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x459c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x459c-0x4778 (476 bytes).
  It occupies 476 bytes.
  The `lw` at 0x45d4 loads 4 bytes from (a0 + (a1 << 0x7)) +0x100.
  The `lbu` at 0x45f4 loads 1 byte from (a0 + (a1 << 0x7)) +0x104.
  The `lw` at 0x460c loads 4 bytes from (a0 + (a1 << 0x7)) +0x108.
  3 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x110, including `lw` at 0x461c, `lw` at 0x4628, `lw` at 0x4640.
  The `ld` at 0x4634 loads 8 bytes from (a0 + (a1 << 0x7)) +0x118.
  The `lw` at 0x4654 loads 4 bytes from (a0 + (a1 << 0x7)) +0x120.
  The `ld` at 0x466c loads 8 bytes from (sym(pci_space) + ([(a0 + (a1 << 0x7))+288] << 0x3)) +0x0.
  The `ld` at 0x4670 loads 8 bytes from (a0 + (a1 << 0x7)) +0x128.
  The `ld` at 0x467c loads 8 bytes from (a0 + (a1 << 0x7)) +0x138.
  The `lw` at 0x4688 loads 4 bytes from (a0 + (a1 << 0x7)) +0x14c.
  The `lw` at 0x468c loads 4 bytes from (a0 + (a1 << 0x7)) +0x148.
  The `lw` at 0x4690 loads 4 bytes from (a0 + (a1 << 0x7)) +0x144.
  The `lw` at 0x469c loads 4 bytes from (a0 + (a1 << 0x7)) +0x168.
  The `ld` at 0x46a0 loads 8 bytes from (a0 + (a1 << 0x7)) +0x160.
  The `lw` at 0x46a4 loads 4 bytes from (a0 + (a1 << 0x7)) +0x158.
  The `ld` at 0x46a8 loads 8 bytes from (a0 + (a1 << 0x7)) +0x150.
  The `lw` at 0x46b4 loads 4 bytes from (a0 + (a1 << 0x7)) +0x16c.
  The `ld` at 0x46cc loads 8 bytes from (a0 + (a1 << 0x7)) +0x170.
  The `lw` at 0x46d8 loads 4 bytes from (a0 + (a1 << 0x7)) +0x178.
  The `lh` at 0x46e4 loads 2 bytes from a0 (arg0 at entry) +0x72.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x2)) +0x528, including `lw` at 0x4708, `lw` at 0x4754.
  The `lw` at 0x470c loads 4 bytes from (a0 + (a1 << 0x4)) +0x574.
  The `lw` at 0x4710 loads 4 bytes from (a0 + (a1 << 0x4)) +0x570.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x4)) +0x56c, including `lw` at 0x4714, `lw` at 0x4758.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x4)) +0x568, including `lw` at 0x4720, `lw` at 0x4764.
  The `jal` at 0x45c0 calls qprintf with a0=sym(.rodata)+2392, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x45ec calls qprintf with a0=sym(.rodata)+2392, a1=sym(.rodata)+2392, a2=sym(.rodata)+2392, a3=sym(.rodata)+2392.
  The `jal` at 0x45f8 calls qprintf with a0=sym(.rodata)+2392, a1=[(a0 + (a1 << 0x7))+260]:1, a2=?, a3=?.
  The `jal` at 0x4608 calls vertex_to_name with a0=[(a0 + (a1 << 0x7))+264], a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0x4614 calls qprintf with a0=sym(.rodata)+2392, a1=sp-304, a2=?, a3=?.
  The `jal` at 0x4620 calls qprintf with a0=sym(.rodata)+2392, a1=[(a0 + (a1 << 0x7))+272], a2=?, a3=?.
  The `jal` at 0x4638 calls idbg_pss_func with a0=[(a0 + (a1 << 0x7))+280]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x4668 calls qprintf with a0=sym(.rodata)+2392, a1=[(sym(pci_space) + ([(a0 + (a1 << 0x7))+288] << 0x3))]:8, a2=([(a0 + (a1 << 0x7))+288] << 0x3), a3=?.
  The `jal` at 0x4674 calls qprintf with a0=sym(.rodata)+2392, a1=[(a0 + (a1 << 0x7))+296]:8, a2=?, a3=?.
  The `jal` at 0x4680 calls qprintf with a0=sym(.rodata)+2392, a1=[(a0 + (a1 << 0x7))+312]:8, a2=?, a3=?.
  The `jal` at 0x4694 calls qprintf with a0=sym(.rodata)+2392, a1=[(a0 + (a1 << 0x7))+324], a2=[(a0 + (a1 << 0x7))+328], a3=[(a0 + (a1 << 0x7))+332].
  The `jal` at 0x46ac calls qprintf with a0=sym(.rodata)+2392, a1=[(a0 + (a1 << 0x7))+336]:8, a2=[(a0 + (a1 << 0x7))+344], a3=[(a0 + (a1 << 0x7))+352]:8, a4=[(a0 + (a1 << 0x7))+360].
  The `jal` at 0x46c4 calls qprintf with a0=sym(.rodata)+2392, a1=sym(.rodata)+2392, a2=sym(.rodata)+2392, a3=[(a0 + (a1 << 0x7))+364].
  The `jal` at 0x46d0 calls qprintf with a0=sym(.rodata)+2392, a1=[(a0 + (a1 << 0x7))+368]:8, a2=?, a3=?.
  The `jal` at 0x46dc calls qprintf with a0=sym(.rodata)+2392, a1=[(a0 + (a1 << 0x7))+376], a2=?, a3=?.
  The `jal` at 0x471c calls qprintf with a0=sym(.rodata)+2392, a1=[(a0 + (a1 << 0x4))+1384], a2=[(a0 + (a1 << 0x4))+1388], a3=[(a0 + (a1 << 0x4))+1392], a4=[(a0 + (a1 << 0x4))+1396], a5=[(a0 + (a1 << 0x2))+1320].
  The `jal` at 0x4760 calls qprintf with a0=sym(.rodata)+2392, a1=[(a0 + (a1 << 0x4))+1384], a2=[(a0 + (a1 << 0x4))+1388], a3=[(a0 + (a1 << 0x2))+1320].
  The `beq` branch at 0x45e0 targets 0x45ec, is taken when at(=[(a0 + (a1 << 0x7))+256]) == 0, and falls through when at(=[(a0 + (a1 << 0x7))+256]) != 0.
  The `blez` branch at 0x462c targets 0x4654, is taken when t8(=[(a0 + (a1 << 0x7))+272]) <= 0 (signed), and falls through when t8(=[(a0 + (a1 << 0x7))+272]) > 0 (signed).
  The `bne` branch at 0x464c targets 0x4634, is taken when s1(?) < t9(=[(a0 + (a1 << 0x7))+272]) (signed), and falls through when s1(?) >= t9(=[(a0 + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0x46b8 targets 0x4770, is taken when a3(=[(a0 + (a1 << 0x7))+364]) == 0, and falls through when a3(=[(a0 + (a1 << 0x7))+364]) != 0.
  The `beq` branch at 0x46e8 targets 0x4748, is taken when a1(=[a0+114]:2) == 0, and falls through when a1(=[a0+114]:2) != 0.
  The `beq` branch at 0x46f4 targets 0x4744, is taken when a1(=[a0+114]:2) == a2(=0x1), and falls through when a1(=[a0+114]:2) != a2(=0x1).
  The `beq` branch at 0x4768 targets 0x4728 and is always taken.
  The `beq` branch at 0x4770 targets 0x46c4 and is always taken.
  The return at 0x473c has v0 = ret(qprintf).

- `idbg_pss` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x4778 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x4778-0x482c (180 bytes).
  It occupies 180 bytes.
  The `lbu` at 0x4778 loads 1 byte from a0 (arg0 at entry) +0x38.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x39, including `lbu` at 0x47a0, `lbu` at 0x47b8, `lbu` at 0x47d8.
  The `jal` at 0x47d0 calls idbg_pss_info with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x480c calls qprintf with a0=sym(.rodata)+2392, a1=[sym(ips)], a2=a2 at entry (arg2), a3=[sym(ips)].
  The `jal` at 0x481c calls idbg_pss_info with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=[sym(ips)].
  The `bne` branch at 0x4798 targets 0x47b0, is taken when a3(=[sym(ips)]) < a1(=[a0+56]:1) (signed), and falls through when a3(=[sym(ips)]) >= a1(=[a0+56]:1) (signed).
  The `beq` branch at 0x47a8 targets 0x481c, is taken when v0(=[a0+57]:1) >= a3(=[sym(ips)]) (signed), and falls through when v0(=[a0+57]:1) < a3(=[sym(ips)]) (signed).
  The `bgez` branch at 0x47b0 targets 0x4808, is taken when a3(=[sym(ips)]) >= 0 (signed), and falls through when a3(=[sym(ips)]) < 0 (signed).
  The `beq` branch at 0x47c4 targets 0x47f8, is taken when a1(=[a0+56]:1) >= v1(=[a0+57]:1+1) (signed), and falls through when a1(=[a0+56]:1) < v1(=[a0+57]:1+1) (signed).
  The `bne` branch at 0x47ec targets 0x47d0, is taken when s0(?) < a0(=[a0+57]:1+1) (signed), and falls through when s0(?) >= a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x4814 targets 0x47f8 and is always taken.
  The `beq` branch at 0x4824 targets 0x47f8 and is always taken.
  The return at 0x4800 has v0 = one of ?, ret(idbg_pss_info), ret(qprintf).

- `pcibr_init_ext_ate_ram` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x482c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x482c-0x498c (352 bytes).
  It occupies 352 bytes.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x486c, `lw` at 0x4894, `lw` at 0x48b8.
  The `ld` at 0x4904 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0x490c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x4878 calls pcireg_ext_ate_set with a0=a0 at entry (arg0), a1=?, a2=0x123456789abcdef, a3=?.
  The `jal` at 0x48a0 calls pcireg_ext_ate_set with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?.
  The `jal` at 0x48c0 calls pcireg_ext_ate_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x48e4 calls pcireg_ssram_size_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4918 calls pcibr_debug with a0=0x10, a1=[a0+4], a2=sym(.rodata)+3296, a3=[a0+8]:8.
  The `jal` at 0x4938 calls pcireg_ext_ate_set with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?.
  The `jal` at 0x497c calls pcibr_debug with a0=0x10, a1=[a0+4], a2=sym(.rodata)+3296, a3=[a0+8]:8.
  The `bne` branch at 0x4884 targets 0x48b8, is taken when s0(?) < 0x2 (signed), and falls through when s0(?) >= 0x2 (signed).
  The `bne` branch at 0x48b0 targets 0x4890, is taken when s4(?) < s0(?) (signed), and falls through when s4(?) >= s0(?) (signed).
  The `bne` branch at 0x48dc targets 0x4864, is taken when s0(?) < 0x4 (unsigned), and falls through when s0(?) >= 0x4 (unsigned).
  The `beq` branch at 0x48fc targets 0x4920, is taken when (t8(=[sym(pcibr_debug_mask)]) & 0x10) == 0, and falls through when (t8(=[sym(pcibr_debug_mask)]) & 0x10) != 0.
  The `beq` branch at 0x4908 targets 0x4974, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `blez` branch at 0x4928 targets 0x4950, is taken when s2(?) <= 0 (signed), and falls through when s2(?) > 0 (signed).
  The `bne` branch at 0x4948 targets 0x4934, is taken when s0(?) < s2(?) (signed), and falls through when s0(?) >= s2(?) (signed).
  The `beq` branch at 0x4984 targets 0x4924 and is always taken.
  The return at 0x496c has v0 = ?.

- `pcibr_ate_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x498c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x498c-0x49d8 (76 bytes).
  It occupies 76 bytes.
  The `ld` at 0x49a0 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `ld` at 0x49b0 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `jal` at 0x499c calls rmalloc with a0=[a0+96]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x49bc calls rmalloc with a0=[a0+104]:8, a1=a1 at entry (arg1), a2=?, a3=?, a4=(ret(rmalloc) << 0x0).
  The `bne` branch at 0x49a8 targets 0x49c8, is taken when a4(=(ret(rmalloc) << 0x0)) != 0, and falls through when a4(=(ret(rmalloc) << 0x0)) == 0.
  The `beq` branch at 0x49b4 targets 0x49cc, is taken when a0(=[a0+104]:8) == 0, and falls through when a0(=[a0+104]:8) != 0.
  The return at 0x49d0 has v0 = (ret(rmalloc) << 0x0)-1.

- `pcibr_ate_free` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x49d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x49d8-0x4a1c (68 bytes).
  It occupies 68 bytes.
  The `lh` at 0x49d8 loads 2 bytes from a0 (arg0 at entry) +0x70.
  The `ld` at 0x49f8 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `ld` at 0x49fc loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `jal` at 0x4a08 calls rmfree with a0=?, a1=a2 at entry (arg2), a2=a1+1, a3=a3 at entry (arg3), a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `beq` branch at 0x49ec targets 0x49fc, is taken when a1 >= at(=[a0+112]:2) (signed), and falls through when a1 < at(=[a0+112]:2) (signed).
  The `beq` branch at 0x49f4 targets 0x4a00 and is always taken.
  The return at 0x4a14 has v0 = ret(rmfree).

- `pcibr_flags_to_ate` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x4a1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x4a1c-0x4ad0 (180 bytes).
  It occupies 180 bytes.
  The `beq` branch at 0x4a30 targets 0x4a44, is taken when (a0 & 0x10) == 0, and falls through when (a0 & 0x10) != 0.
  The `beq` branch at 0x4a4c targets 0x4a58, is taken when (a0 & 0x400) == 0, and falls through when (a0 & 0x400) != 0.
  The `beq` branch at 0x4a58 targets 0x4a68, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bgez` branch at 0x4a6c targets 0x4a78, is taken when a2(=(a0 << 0x29)) >= 0 (signed), and falls through when a2(=(a0 << 0x29)) < 0 (signed).
  The `bgez` branch at 0x4a78 targets 0x4a84, is taken when a3(=(a0 << 0x28)) >= 0 (signed), and falls through when a3(=(a0 << 0x28)) < 0 (signed).
  The `bgez` branch at 0x4a94 targets 0x4aa0, is taken when a5(=(a0 << 0x2d)) >= 0 (signed), and falls through when a5(=(a0 << 0x2d)) < 0 (signed).
  The `bgez` branch at 0x4aa0 targets 0x4aac, is taken when a4(=(a0 << 0x2c)) >= 0 (signed), and falls through when a4(=(a0 << 0x2c)) < 0 (signed).
  The `bgez` branch at 0x4ab0 targets 0x4abc, is taken when a6(=(a0 << 0x2b)) >= 0 (signed), and falls through when a6(=(a0 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0x4abc targets 0x4ac8, is taken when a3(=(a0 << 0x2a)) >= 0 (signed), and falls through when a3(=(a0 << 0x2a)) < 0 (signed).
  The return at 0x4ac8 has v0 = ?.

- `pcibr_ate_addr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x4ad0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x4ad0-0x4b10 (64 bytes).
  It occupies 64 bytes.
  The `lh` at 0x4ad0 loads 2 bytes from a0 (arg0 at entry) +0x70.
  The `jal` at 0x4ae4 calls pcireg_int_ate_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4af4 calls pcireg_ext_ate_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x4adc targets 0x4af4, is taken when a1 >= at(=[a0+112]:2) (signed), and falls through when a1 < at(=[a0+112]:2) (signed).
  The `beq` branch at 0x4aec targets 0x4b00 and is always taken.
  The return at 0x4b08 has v0 = one of ret(pcireg_int_ate_addr), ret(pcireg_ext_ate_addr).

- `ate_write` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x4b10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x4b10-0x4e20 (784 bytes).
  It occupies 784 bytes.
  The `lbu` at 0x4b14 loads 1 byte from a1 (arg1 at entry) +0x8.
  The `lbu` at 0x4b20 loads 1 byte from a0 (arg0 at entry) +0x38.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0x4b44, `lh` at 0x4bc0.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x0, including `lw` at 0x4b50, `lw` at 0x4c4c, `lw` at 0x4cd4.
  The `lh` at 0x4b9c loads 2 bytes from a0 (arg0 at entry) +0x70.
  5 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x39, including `lbu` at 0x4bd8, `lbu` at 0x4c00, `lbu` at 0x4d28.
  The `ld` at 0x4bf4 loads 8 bytes from a0 (arg0 at entry) +0x8.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x4c28, `lw` at 0x4d48, `lw` at 0x4d88.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0x4c60, `sw` at 0x4d08.
  2 such `ll` accesses load 4 bytes from ?, including `ll` at 0x4c6c, `ll` at 0x4d10.
  2 such `sc` accesses store 4 bytes to ?, including `sc` at 0x4c78, `sc` at 0x4d1c.
  The `ld` at 0x4d58 loads 8 bytes from ?.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x4d5c, `sw` at 0x4d68, `sw` at 0x4d98.
  The `jal` at 0x4b84 calls pcireg_int_ate_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4bb0 calls pcireg_ext_ate_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4bf8 calls pcibr_slot_config_set with a0=[a0+8]:8, a1=?, a2=0x4, a3=?.
  The `jal` at 0x4c88 calls mutex_io_spinunlock with a0=a0+128, a1=?, a2=?, a3=?.
  The `jal` at 0x4c90 calls pcireg_tflush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4ccc calls mutex_spinlock with a0=a0+128, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=[a1].
  The `jal` at 0x4dbc calls pcireg_wrb_flush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x4b64 targets 0x4cc0, is taken when at(=[a0+114]:2) == 0, and falls through when at(=[a0+114]:2) != 0.
  The `blez` branch at 0x4b6c targets 0x4bc0, is taken when s3(=a3) <= 0 (signed), and falls through when s3(=a3) > 0 (signed).
  The `beq` branch at 0x4b74 targets 0x4b9c and is always taken.
  The `bltz` branch at 0x4b94 targets 0x4bc0, is taken when s3(?) < 0 (signed), and falls through when s3(?) >= 0 (signed).
  The `bne` branch at 0x4ba4 targets 0x4b7c, is taken when s1(?) < a0(=[a0+112]:2) (signed), and falls through when s1(?) >= a0(=[a0+112]:2) (signed).
  The `beq` branch at 0x4bb8 targets 0x4b8c and is always taken.
  The `bne` branch at 0x4bc8 targets 0x4c90, is taken when a1(=[a0+114]:2) != 0, and falls through when a1(=[a0+114]:2) == 0.
  The `beq` branch at 0x4bd0 targets 0x4c90, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x4be4 targets 0x4c20, is taken when s6(=[a0+56]:1) < a0(=[a0+57]:1+1) (signed), and falls through when s6(=[a0+56]:1) >= a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x4bec targets 0x4c48 and is always taken.
  The `beq` branch at 0x4c14 targets 0x4c4c, is taken when s1(?) >= a0(=[a0+57]:1+1) (signed), and falls through when s1(?) < a0(=[a0+57]:1+1) (signed).
  The `bne` branch at 0x4c30 targets 0x4bf4, is taken when (a3(?) & 0x4) != 0, and falls through when (a3(?) & 0x4) == 0.
  The `bne` branch at 0x4c44 targets 0x4c1c, is taken when s1(?) < a0(=[a0+57]:1+1) (signed), and falls through when s1(?) >= a0(=[a0+57]:1+1) (signed).
  The `beql` branch at 0x4c7c targets 0x4c6c, is taken when at(=table(0x1)) == 0, and falls through when at(=table(0x1)) != 0; its branch-likely delay slot `nop` at 0x4c80 runs only when taken and is annulled on fall-through.
  The `bgez` branch at 0x4cc4 targets 0x4b6c, is taken when ra(=([a1] << 0x21)) >= 0 (signed), and falls through when ra(=([a1] << 0x21)) < 0 (signed).
  The `beq` branch at 0x4cf0 targets 0x4d28, is taken when (a2(=[a1]) & at(=0xffffffff80000000)) == 0, and falls through when (a2(=[a1]) & at(=0xffffffff80000000)) != 0.
  The `beql` branch at 0x4d20 targets 0x4d10, is taken when a4(=table(-0x1)) == 0, and falls through when a4(=table(-0x1)) != 0; its branch-likely delay slot `nop` at 0x4d24 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x4d38 targets 0x4b6c, is taken when s6(=[a0+56]:1) >= a0(=[a0+57]:1+1) (signed), and falls through when s6(=[a0+56]:1) < a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x4d40 targets 0x4e10 and is always taken.
  The `beq` branch at 0x4d50 targets 0x4d68, is taken when (a6(?) & 0x4) == 0, and falls through when (a6(?) & 0x4) != 0.
  The `beq` branch at 0x4d78 targets 0x4d9c, is taken when a2(?) >= a0(=[a0+57]:1+1) (signed), and falls through when a2(?) < a0(=[a0+57]:1+1) (signed).
  The `bne` branch at 0x4d8c targets 0x4d48, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x4d94 targets 0x4d6c and is always taken.
  The `beq` branch at 0x4d9c targets 0x4b6c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x4da8 targets 0x4ddc, is taken when s6(=[a0+56]:1) < a0(=[a0+57]:1+1) (signed), and falls through when s6(=[a0+56]:1) >= a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x4db0 targets 0x4b6c and is always taken.
  The `beq` branch at 0x4dd8 targets 0x4b6c, is taken when s4(?) >= a0(=[a0+57]:1+1) (signed), and falls through when s4(?) < a0(=[a0+57]:1+1) (signed).
  The `bne` branch at 0x4dec targets 0x4db8, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `bne` branch at 0x4e00 targets 0x4de0, is taken when s4(?) < a0(=[a0+57]:1+1) (signed), and falls through when s4(?) >= a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x4e08 targets 0x4b6c and is always taken.
  The `beq` branch at 0x4e18 targets 0x4d84 and is always taken.
  The return at 0x4cb8 has v0 = ret(pcireg_tflush_get).

- `do_pcibr_rrb_count_valid` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x4e20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x4e20-0x4ff0 (464 bytes).
  It occupies 464 bytes.
  8 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x4e24, `lw` at 0x4e60, `lw` at 0x4ea4.
  The `jal` at 0x4ecc calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=0xd002, a6=0xc002.
  The `jal` at 0x4fe0 calls cmn_err with a0=0x4, a1=sym(.rodata)+3392, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0xc002.
  The `beq` branch at 0x4e58 targets 0x4f30, is taken when a6(=0xc002) == at(?), and falls through when a6(=0xc002) != at(?).
  The `beq` branch at 0x4e70 targets 0x4f50, is taken when v1(?) == a1(=0xd002), and falls through when v1(?) != a1(=0xd002).
  The `beq` branch at 0x4e78 targets 0x4e9c, is taken when s0(=a1) == v0(=0xff), and falls through when s0(=a1) != v0(=0xff).
  The `beq` branch at 0x4e80 targets 0x4e9c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bltz` branch at 0x4e88 targets 0x4e9c, is taken when s1(=a2) < 0 (signed), and falls through when s1(=a2) >= 0 (signed).
  The `bne` branch at 0x4e90 targets 0x4e9c, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0x4e9c targets 0x4fe0, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x4eb0 targets 0x4f94, is taken when a6(=0xc002) == a1(?), and falls through when a6(=0xc002) != a1(?).
  The `beq` branch at 0x4ec4 targets 0x4fb4, is taken when a2(?) == a3(=0xd002), and falls through when a2(?) != a3(=0xd002).
  The `bne` branch at 0x4f00 targets 0x4f0c, is taken when a7(?) != t1(?), and falls through when a7(?) == t1(?).
  The `bne` branch at 0x4f0c targets 0x4ef8, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x4f40 targets 0x4e60, is taken when t2(?) != t3(=0x36), and falls through when t2(?) == t3(=0x36).
  The `beq` branch at 0x4f48 targets 0x4f68 and is always taken.
  The `bne` branch at 0x4f60 targets 0x4e78, is taken when t3(?) != t8(=0x24), and falls through when t3(?) == t8(=0x24).
  The `beq` branch at 0x4f68 targets 0x4fd4, is taken when s0(=a1) == t8(=0xff), and falls through when s0(=a1) != t8(=0xff).
  The `beq` branch at 0x4f70 targets 0x4fd8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bltz` branch at 0x4f78 targets 0x4fd8, is taken when s1(=a2) < 0 (signed), and falls through when s1(=a2) >= 0 (signed).
  The `beq` branch at 0x4f84 targets 0x4fd8, is taken when s1(=a2) >= 0x2 (signed), and falls through when s1(=a2) < 0x2 (signed).
  The `beq` branch at 0x4f8c targets 0x4fd8 and is always taken.
  The `bne` branch at 0x4fa4 targets 0x4eb8, is taken when ra(?) != at(=0x36), and falls through when ra(?) == at(=0x36).
  The `beq` branch at 0x4fac targets 0x4fcc and is always taken.
  The `bne` branch at 0x4fc4 targets 0x4ecc, is taken when at(?) != v0(=0x24), and falls through when at(?) == v0(=0x24).
  The `beq` branch at 0x4fcc targets 0x4ecc and is always taken.
  The `bne` branch at 0x4fd8 targets 0x4ea4, is taken when v0(=one of 0x0, 0x1) != 0, and falls through when v0(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x4fe8 targets 0x4f14 and is always taken.
  The return at 0x4f28 has v0 = one of ?, 0x0.

- `do_pcibr_rrb_count_avail` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x4ff0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x4ff0-0x5104 (276 bytes).
  It occupies 276 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x4ff0, `lw` at 0x501c, `lw` at 0x5094.
  The `jal` at 0x504c calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?, a4=0xff.
  The `jal` at 0x50f4 calls cmn_err with a0=0x4, a1=sym(.rodata)+3392, a2=a2 at entry (arg2), a3=?, a4=0xff.
  The `beq` branch at 0x5014 targets 0x5094, is taken when at(?) == v1(=0xc002), and falls through when at(?) != v1(=0xc002).
  The `beq` branch at 0x5028 targets 0x50b4, is taken when v1(?) == a1(=0xd002), and falls through when v1(?) != a1(=0xd002).
  The `beq` branch at 0x5030 targets 0x5044, is taken when v0(=a1) == a4(=0xff), and falls through when v0(=a1) != a4(=0xff).
  The `beq` branch at 0x5038 targets 0x5044, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x5044 targets 0x50f0, is taken when a1(=one of 0x0, 0x1) == 0, and falls through when a1(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x5070 targets 0x507c, is taken when a5(=0x8) == a2(?), and falls through when a5(=0x8) != a2(?).
  The `bne` branch at 0x507c targets 0x5068, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x50a4 targets 0x501c, is taken when a3(?) != a6(=0x36), and falls through when a3(?) == a6(=0x36).
  The `beq` branch at 0x50ac targets 0x50cc and is always taken.
  The `bne` branch at 0x50c4 targets 0x5030, is taken when a6(?) != a7(=0x24), and falls through when a6(?) == a7(=0x24).
  The `beq` branch at 0x50cc targets 0x50e4, is taken when v0(=a1) == a7(=0xff), and falls through when v0(=a1) != a7(=0xff).
  The `beq` branch at 0x50d4 targets 0x50e8, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x50dc targets 0x50e8 and is always taken.
  The `bne` branch at 0x50e8 targets 0x504c, is taken when a1(=one of 0x0, 0x1) != 0, and falls through when a1(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x50fc targets 0x5084 and is always taken.
  The return at 0x508c has v0 = one of ?, 0x0.

- `do_pcibr_rrb_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x5104 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x5104-0x5338 (564 bytes).
  It occupies 564 bytes.
  8 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x5114, `lw` at 0x5154, `lw` at 0x5198.
  The `jal` at 0x51c8 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=0xd002, a3=?.
  The `jal` at 0x5244 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5328 calls cmn_err with a0=0x4, a1=sym(.rodata)+3392, a2=a2 at entry (arg2), a3=?, a7=0xc002.
  The `beq` branch at 0x514c targets 0x5274, is taken when a7(=0xc002) == at(?), and falls through when a7(=0xc002) != at(?).
  The `beq` branch at 0x5164 targets 0x5294, is taken when v1(?) == a0(=0xd002), and falls through when v1(?) != a0(=0xd002).
  The `beq` branch at 0x516c targets 0x5190, is taken when s2(=a1) == v0(=0xff), and falls through when s2(=a1) != v0(=0xff).
  The `beq` branch at 0x5174 targets 0x5190, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bltz` branch at 0x517c targets 0x5190, is taken when s3(=a2) < 0 (signed), and falls through when s3(=a2) >= 0 (signed).
  The `beq` branch at 0x5184 targets 0x5190, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x5190 targets 0x5324, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x51a4 targets 0x52d8, is taken when a7(=0xc002) == a0(?), and falls through when a7(=0xc002) != a0(?).
  The `beq` branch at 0x51b8 targets 0x52f8, is taken when a1(?) == a2(=0xd002), and falls through when a1(?) != a2(=0xd002).
  The `blez` branch at 0x51d4 targets 0x5240, is taken when s0(=a3) <= 0 (signed), and falls through when s0(=a3) > 0 (signed).
  The `beq` branch at 0x5218 targets 0x522c, is taken when t2(=0x8) == t8(?), and falls through when t2(=0x8) != t8(?).
  The `beq` branch at 0x5230 targets 0x5240, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bgtz` branch at 0x5238 targets 0x5204, is taken when s0(?) > 0 (signed), and falls through when s0(?) <= 0 (signed).
  The `bne` branch at 0x5284 targets 0x5154, is taken when a3(?) != a4(=0x36), and falls through when a3(?) == a4(=0x36).
  The `beq` branch at 0x528c targets 0x52ac and is always taken.
  The `bne` branch at 0x52a4 targets 0x516c, is taken when a4(?) != a5(=0x24), and falls through when a4(?) == a5(=0x24).
  The `beq` branch at 0x52ac targets 0x5318, is taken when s2(=a1) == a5(=0xff), and falls through when s2(=a1) != a5(=0xff).
  The `beq` branch at 0x52b4 targets 0x531c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bltz` branch at 0x52bc targets 0x531c, is taken when s3(=a2) < 0 (signed), and falls through when s3(=a2) >= 0 (signed).
  The `beq` branch at 0x52c8 targets 0x531c, is taken when s3(=a2) >= 0x2 (signed), and falls through when s3(=a2) < 0x2 (signed).
  The `beq` branch at 0x52d0 targets 0x531c and is always taken.
  The `bne` branch at 0x52e8 targets 0x51ac, is taken when a7(?) != t0(=0x36), and falls through when a7(?) == t0(=0x36).
  The `beq` branch at 0x52f0 targets 0x5310 and is always taken.
  The `bne` branch at 0x5308 targets 0x51c0, is taken when t0(?) != t1(=0x24), and falls through when t0(?) == t1(=0x24).
  The `beq` branch at 0x5310 targets 0x51c0 and is always taken.
  The `bne` branch at 0x531c targets 0x5198, is taken when v0(=one of 0x0, 0x1) != 0, and falls through when v0(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x5330 targets 0x5254 and is always taken.
  The return at 0x526c has v0 = one of -0x1, 0x0.

- `do_pcibr_rrb_free` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x5338 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x5338-0x55e0 (680 bytes).
  It occupies 680 bytes.
  8 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x534c, `lw` at 0x538c, `lw` at 0x53dc.
  The `jal` at 0x5410 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=a3 at entry (arg3), a7=0xc002.
  The `jal` at 0x5488 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x549c calls do_pcibr_rrb_clear with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x55d0 calls cmn_err with a0=0x4, a1=sym(.rodata)+3392, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=0xc002.
  The `beq` branch at 0x5384 targets 0x550c, is taken when a7(=0xc002) == at(?), and falls through when a7(=0xc002) != at(?).
  The `beq` branch at 0x539c targets 0x552c, is taken when v1(?) == a0(=0xd002), and falls through when v1(?) != a0(=0xd002).
  The `beq` branch at 0x53a4 targets 0x53d4, is taken when s0(=a1) == v0(=0xff), and falls through when s0(=a1) != v0(=0xff).
  The `beq` branch at 0x53ac targets 0x53d4, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bltz` branch at 0x53b4 targets 0x53d4, is taken when s2(=a2) < 0 (signed), and falls through when s2(=a2) >= 0 (signed).
  The `beq` branch at 0x53bc targets 0x53d4, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x53c8 targets 0x53d4 and is always taken.
  The `beq` branch at 0x53d4 targets 0x55cc, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x53e8 targets 0x5574, is taken when a7(=0xc002) == a0(?), and falls through when a7(=0xc002) != a0(?).
  The `beq` branch at 0x5400 targets 0x5594, is taken when a1(?) == a2(=0xd002), and falls through when a1(?) != a2(=0xd002).
  The `blez` branch at 0x5420 targets 0x55b4, is taken when s5(=a3) <= 0 (signed), and falls through when s5(=a3) > 0 (signed).
  The `beq` branch at 0x5444 targets 0x5450 and is always taken.
  The `blez` branch at 0x544c targets 0x5484, is taken when s5(?) <= 0 (signed), and falls through when s5(?) > 0 (signed).
  The `bne` branch at 0x5464 targets 0x5478, is taken when t1(?) != t2(?), and falls through when t1(?) == t2(?).
  The `bne` branch at 0x547c targets 0x544c, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x5494 targets 0x54b8 and is always taken.
  The `beq` branch at 0x54b0 targets 0x54dc, is taken when s2(?) >= 0x8 (signed), and falls through when s2(?) < 0x8 (signed).
  The `bne` branch at 0x54c0 targets 0x549c, is taken when (s4(?) & t8(?)) != 0, and falls through when (s4(?) & t8(?)) == 0.
  The `bne` branch at 0x54d4 targets 0x54b8, is taken when s2(?) < 0x8 (signed), and falls through when s2(?) >= 0x8 (signed).
  The `bne` branch at 0x551c targets 0x538c, is taken when ra(?) != at(=0x36), and falls through when ra(?) == at(=0x36).
  The `beq` branch at 0x5524 targets 0x5548 and is always taken.
  The `bne` branch at 0x553c targets 0x53a4, is taken when at(?) != v1(=0x24), and falls through when at(?) == v1(=0x24).
  The `beq` branch at 0x5548 targets 0x55c0, is taken when s0(=a1) == v0(=0xff), and falls through when s0(=a1) != v0(=0xff).
  The `beq` branch at 0x5550 targets 0x55c4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bltz` branch at 0x5558 targets 0x55c4, is taken when s2(=a2) < 0 (signed), and falls through when s2(=a2) >= 0 (signed).
  The `beq` branch at 0x5564 targets 0x55c4, is taken when s2(=a2) >= 0x2 (signed), and falls through when s2(=a2) < 0x2 (signed).
  The `beq` branch at 0x556c targets 0x55c4 and is always taken.
  The `bne` branch at 0x5584 targets 0x53f0, is taken when a0(?) != a1(=0x36), and falls through when a0(?) == a1(=0x36).
  The `beq` branch at 0x558c targets 0x55ac and is always taken.
  The `bne` branch at 0x55a4 targets 0x5408, is taken when a1(?) != a2(=0x24), and falls through when a1(?) == a2(=0x24).
  The `beq` branch at 0x55ac targets 0x5408 and is always taken.
  The `beq` branch at 0x55b8 targets 0x5484 and is always taken.
  The `bne` branch at 0x55c4 targets 0x53dc, is taken when v0(=one of 0x0, 0x1) != 0, and falls through when v0(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x55d8 targets 0x54e4 and is always taken.
  The return at 0x5504 has v0 = one of -0x1, 0x0.
  The instructions from 0x53d0 to 0x53d0 are not reached by any path from the entry, and their branches are not listed.

- `do_pcibr_rrb_free_all` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x55e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x55e0-0x56d4 (244 bytes).
  It occupies 244 bytes.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x55ec, `lw` at 0x5628, `lw` at 0x5694.
  The `sw` at 0x566c stores 4 bytes to ?.
  The `jal` at 0x564c calls do_pcibr_rrb_free with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=?, a3=0x8.
  The `beq` branch at 0x561c targets 0x5694, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0x5634 targets 0x56b4, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `bne` branch at 0x5668 targets 0x5640, is taken when s0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when s0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x56a4 targets 0x5628, is taken when a0(?) != a1(=0x36), and falls through when a0(?) == a1(=0x36).
  The `beq` branch at 0x56ac targets 0x56cc and is always taken.
  The `bne` branch at 0x56c4 targets 0x563c, is taken when a1(?) != a2(=0x24), and falls through when a1(?) == a2(=0x24).
  The `beq` branch at 0x56cc targets 0x563c and is always taken.
  The return at 0x568c has v0 = ret(do_pcibr_rrb_free).

- `do_pcibr_rrb_clear` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x56d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x56d4-0x5780 (172 bytes).
  It occupies 172 bytes.
  The `jal` at 0x56ec calls pcireg_rrb_status_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x570c calls pcireg_rrb_status_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5734 calls pcireg_rrb_clear_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x573c calls pcireg_rrb_status_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5750 calls pcireg_rrb_status_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x5704 targets 0x5720, is taken when (s1(?) & v0(=ret(pcireg_rrb_status_get))) == 0, and falls through when (s1(?) & v0(=ret(pcireg_rrb_status_get))) != 0.
  The `bne` branch at 0x5718 targets 0x570c, is taken when (s1(?) & v0(=ret(pcireg_rrb_status_get))) != 0, and falls through when (s1(?) & v0(=ret(pcireg_rrb_status_get))) == 0.
  The `beq` branch at 0x572c targets 0x5764, is taken when (s2(?) & a0(=ret(pcireg_rrb_status_get))) == 0, and falls through when (s2(?) & a0(=ret(pcireg_rrb_status_get))) != 0.
  The `beq` branch at 0x5748 targets 0x5768, is taken when (s2(?) & v0(=ret(pcireg_rrb_status_get))) == 0, and falls through when (s2(?) & v0(=ret(pcireg_rrb_status_get))) != 0.
  The `bne` branch at 0x575c targets 0x5750, is taken when (s2(?) & v0(=ret(pcireg_rrb_status_get))) != 0, and falls through when (s2(?) & v0(=ret(pcireg_rrb_status_get))) == 0.
  The return at 0x5778 has v0 = ret(pcireg_rrb_status_get).

- `do_pcibr_rrb_flush` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x5780 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x5780-0x5820 (160 bytes).
  It occupies 160 bytes.
  The `jal` at 0x57a4 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x57d8 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x57e4 calls do_pcibr_rrb_clear with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x57fc calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=ret(pcireg_rrb_get), a3=?.
  The `beq` branch at 0x57c4 targets 0x57e0, is taken when (a5(?) & v0(=ret(pcireg_rrb_get))) == 0, and falls through when (a5(?) & v0(=ret(pcireg_rrb_get))) != 0.
  The `beq` branch at 0x57f0 targets 0x5804, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The return at 0x5818 has v0 = one of ret(do_pcibr_rrb_clear), ret(pcireg_rrb_set).

- `pcibr_rrb_alloc_init` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x5820 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x5820-0x59f0 (464 bytes).
  It occupies 464 bytes.
  The `ld` at 0x5830 loads 8 bytes from a0 (arg0 at entry) +0x8.
  3 such `lw` accesses load 4 bytes from (a0 + ((a2 + (a1 << 0x2)) << 0x2)) +0x568, including `lw` at 0x585c, `lw` at 0x58c4, `lw` at 0x5934.
  The `sw` at 0x58a0 stores 4 bytes to ((a1 << 0x2) + a0) +0x528.
  2 such `sw` accesses store 4 bytes to (a0 + ((a2 + (a1 << 0x2)) << 0x2)) +0x568, including `sw` at 0x58d8, `sw` at 0x5948.
  The `lw` at 0x58dc loads 4 bytes from ((a1 << 0x2) + a0) +0x528.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x58e8, `lw` at 0x5920.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x58f8, `sw` at 0x5928.
  The `lh` at 0x5984 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lw` at 0x59b8 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x58b0 calls do_pcibr_rrb_alloc with a0=[a0+8]:8, a1=?, a2=a2 at entry (arg2), a3=0x1.
  The `jal` at 0x5944 calls do_pcibr_rrb_free with a0=[a0+8]:8, a1=?, a2=a2 at entry (arg2), a3=0x1.
  The `jal` at 0x59bc calls pcibr_debug with a0=0x20, a1=[a0+4], a2=sym(.rodata)+3392, a3=[(a0 + ((a2 + (a1 << 0x2)) << 0x2))+1384], a5=a3 at entry (arg3), a7=a2 at entry (arg2).
  The `jal` at 0x59d8 calls pcibr_rrb_debug with a0=sym(.rodata)+3392, a1=a0 at entry (arg0), a2=?, a3=?.
  The `beq` branch at 0x5888 targets 0x58fc, is taken when s1(=[(a0 + ((a2 + (a1 << 0x2)) << 0x2))+1384]) >= a3 (signed), and falls through when s1(=[(a0 + ((a2 + (a1 << 0x2)) << 0x2))+1384]) < a3 (signed).
  The `beq` branch at 0x5898 targets 0x58dc and is always taken.
  The `bltz` branch at 0x58b8 targets 0x5900, is taken when v0(=ret(do_pcibr_rrb_alloc)) < 0 (signed), and falls through when v0(=ret(do_pcibr_rrb_alloc)) >= 0 (signed).
  The `beq` branch at 0x58d4 targets 0x5900, is taken when s1(?) >= s2(=a3) (signed), and falls through when s1(?) < s2(=a3) (signed).
  The `bgtz` branch at 0x58e0 targets 0x58a0, is taken when a2(=[((a1 << 0x2) + a0)+1320]) > 0 (signed), and falls through when a2(=[((a1 << 0x2) + a0)+1320]) <= 0 (signed).
  The `blez` branch at 0x58ec targets 0x5900, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x58f4 targets 0x58a4 and is always taken.
  The `beq` branch at 0x5918 targets 0x595c, is taken when s2(=a3) >= s1(?) (signed), and falls through when s2(=a3) < s1(?) (signed).
  The `bne` branch at 0x5954 targets 0x5920, is taken when s2(=a3) < s1(?) (signed), and falls through when s2(=a3) >= s1(?) (signed).
  The `beq` branch at 0x5978 targets 0x5998, is taken when at(=a1) == v0(=0xff), and falls through when at(=a1) != v0(=0xff).
  The `beq` branch at 0x598c targets 0x5998, is taken when v1(=[a0+114]:2) == a0(=0x2), and falls through when v1(=[a0+114]:2) != a0(=0x2).
  The return at 0x59e8 has v0 = ret(pcibr_rrb_debug).

- `pcibr_rrb_alloc_more` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x59f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x59f0-0x5b44 (340 bytes).
  It occupies 340 bytes.
  The `ld` at 0x59f8 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sw` at 0x5a64 stores 4 bytes to ((a1 << 0x2) + a0) +0x528.
  The `lw` at 0x5a88 loads 4 bytes from (((a2 + (a1 << 0x2)) << 0x2) + a0) +0x568.
  The `sw` at 0x5a98 stores 4 bytes to (((a2 + (a1 << 0x2)) << 0x2) + a0) +0x568.
  The `lw` at 0x5a9c loads 4 bytes from ((a1 << 0x2) + a0) +0x528.
  The `lw` at 0x5aac loads 4 bytes from ?.
  The `sw` at 0x5ac0 stores 4 bytes to ?.
  The `lh` at 0x5ad8 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lw` at 0x5b04 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x5a74 calls do_pcibr_rrb_alloc with a0=[a0+8]:8, a1=?, a2=a2 at entry (arg2), a3=0x1, a5=[((a1 << 0x2) + a0)+1320]-1.
  The `jal` at 0x5b08 calls pcibr_debug with a0=0x20, a1=[a0+4], a2=sym(.rodata)+3392, a3=?, a4=a3 at entry (arg3), a6=a2 at entry (arg2).
  The `jal` at 0x5b18 calls pcibr_rrb_debug with a0=sym(.rodata)+3392, a1=a0 at entry (arg0), a2=?, a3=?.
  The `blez` branch at 0x5a34 targets 0x5ac4, is taken when a3 <= 0 (signed), and falls through when a3 > 0 (signed).
  The `beq` branch at 0x5a5c targets 0x5a9c and is always taken.
  The `bltz` branch at 0x5a7c targets 0x5acc, is taken when v0(=ret(do_pcibr_rrb_alloc)) < 0 (signed), and falls through when v0(=ret(do_pcibr_rrb_alloc)) >= 0 (signed).
  The `beq` branch at 0x5a94 targets 0x5ac8, is taken when s0(?) >= s3(=a3) (signed), and falls through when s0(?) < s3(=a3) (signed).
  The `bgtz` branch at 0x5aa0 targets 0x5a64, is taken when a5(=[((a1 << 0x2) + a0)+1320]) > 0 (signed), and falls through when a5(=[((a1 << 0x2) + a0)+1320]) <= 0 (signed).
  The `blez` branch at 0x5ab4 targets 0x5ac8, is taken when a0(?) <= 0 (signed), and falls through when a0(?) > 0 (signed).
  The `beq` branch at 0x5abc targets 0x5a68 and is always taken.
  The `beq` branch at 0x5ad0 targets 0x5ae8, is taken when s8(=a1) == a2(=0xff), and falls through when s8(=a1) != a2(=0xff).
  The `beq` branch at 0x5adc targets 0x5ae8, is taken when a3(=[a0+114]:2) == a4(=0x2), and falls through when a3(=[a0+114]:2) != a4(=0x2).
  The return at 0x5b3c has v0 = ret(pcibr_rrb_debug).

- `pcibr_rrb_flush` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x5b44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x5b44-0x5cc0 (380 bytes).
  It occupies 380 bytes.
  The `ld` at 0x5b6c loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(pciio_info_mfast_get)+8]:8 +0x4, including `lw` at 0x5b70, `lw` at 0x5b9c, `lw` at 0x5c80.
  The `lbu` at 0x5b7c loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `jal` at 0x5b4c calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5b64 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x5bbc calls pcireg_rrb_get with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x5bd4 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0x5c24 calls do_pcibr_rrb_flush with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x5c50 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `beq` branch at 0x5b94 targets 0x5c80, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0x5ba8 targets 0x5ca0, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `beq` branch at 0x5bfc targets 0x5c18 and is always taken.
  The `beq` branch at 0x5c10 targets 0x5c40, is taken when s2(?) >= 0x8 (signed), and falls through when s2(?) < 0x8 (signed).
  The `bne` branch at 0x5c1c targets 0x5c04, is taken when s3(?) != t9(?), and falls through when s3(?) == t9(?).
  The `bne` branch at 0x5c38 targets 0x5c18, is taken when s2(?) < 0x8 (signed), and falls through when s2(?) >= 0x8 (signed).
  The `bne` branch at 0x5c90 targets 0x5b9c, is taken when a2(?) != a3(=0x36), and falls through when a2(?) == a3(=0x36).
  The `beq` branch at 0x5c98 targets 0x5cb8 and is always taken.
  The `bne` branch at 0x5cb0 targets 0x5bb0, is taken when a3(?) != a4(=0x24), and falls through when a3(?) == a4(=0x24).
  The `beq` branch at 0x5cb8 targets 0x5bb0 and is always taken.
  The return at 0x5c78 has v0 = ret(mutex_io_spinunlock).

- `pcibr_wrb_flush` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x5cc0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x5cc0-0x5cfc (60 bytes).
  It occupies 60 bytes.
  The `lbu` at 0x5cd8 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0x5cdc loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  The `jal` at 0x5cc8 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5cd4 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x5ce0 calls pcireg_wrb_flush_get with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The return at 0x5cf4 has v0 = 0x0.

- `pcibr_rrb_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x5cfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x5cfc-0x6100 (1028 bytes).
  It occupies 1028 bytes.
  The `lbu` at 0x5d20 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0x5d34 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(pciio_info_mfast_get)+8]:8 +0x4, including `lw` at 0x5d48, `lw` at 0x5d7c, `lw` at 0x5de8.
  2 such `lw` accesses load 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x5e8, including `lw` at 0x5d9c, `lw` at 0x5e0c.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0x5dc4, `lw` at 0x5e50, `lw` at 0x5fc0.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x5dcc, `sw` at 0x5fd0, `sw` at 0x604c.
  3 such `lw` accesses load 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528, including `lw` at 0x5dd8, `lw` at 0x5e1c, `lw` at 0x5fbc.
  The `sw` at 0x5de0 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x548.
  The `lw` at 0x5e24 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x56c.
  The `lw` at 0x5e28 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `lw` at 0x5e3c loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x5e88 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `sw` at 0x5f7c stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `sw` at 0x5f90 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `lw` at 0x5f9c loads 4 bytes from ret(pciio_info_mfast_get) +0x51c.
  The `sw` at 0x5fb0 stores 4 bytes to ret(pciio_info_mfast_get) +0x51c.
  The `sw` at 0x5fb4 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x56c.
  The `sw` at 0x5fb8 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `lw` at 0x5fd4 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x548.
  2 such `sw` accesses store 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528, including `sw` at 0x5fdc, `sw` at 0x6040.
  The `jal` at 0x5d18 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5d28 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x5d3c calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0x5f48 calls do_pcibr_rrb_alloc with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?.
  The `jal` at 0x5f64 calls do_pcibr_rrb_alloc with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x1, a3=?, a6=[ret(pciio_info_mfast_get)+8]:8.
  The `jal` at 0x6058 calls pcibr_rrb_debug with a0=sym(.rodata)+3392, a1=ret(pciio_info_mfast_get), a2=?, a3=?, a4=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2))+1320], a5=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)).
  The `jal` at 0x608c calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x60d8 calls do_pcibr_rrb_free with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?.
  The `jal` at 0x60f0 calls do_pcibr_rrb_free with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x1, a3=?.
  The `beq` branch at 0x5d70 targets 0x60b0, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0x5d8c targets 0x5de4, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `bgez` branch at 0x5da0 targets 0x5e18, is taken when v1(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) >= 0 (signed), and falls through when v1(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) < 0 (signed).
  The `bne` branch at 0x5dc8 targets 0x5db0, is taken when a1(?) < s6(=one of 0x2, 0x4) (signed), and falls through when a1(?) >= s6(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x5ddc targets 0x5e20 and is always taken.
  The `bne` branch at 0x5df8 targets 0x5d94, is taken when a4(?) != a5(=0x24), and falls through when a4(?) == a5(=0x24).
  The `bltz` branch at 0x5e10 targets 0x5da8, is taken when a5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) < 0 (signed), and falls through when a5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) >= 0 (signed).
  The `beq` branch at 0x5e30 targets 0x5e7c, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `bne` branch at 0x5e38 targets 0x5e84, is taken when s5(=a2) != 0, and falls through when s5(=a2) == 0.
  The `bne` branch at 0x5e6c targets 0x5ea4, is taken when a1(?) < t1(?) (signed), and falls through when a1(?) >= t1(?) (signed).
  The `beq` branch at 0x5e74 targets 0x5f04 and is always taken.
  The `beq` branch at 0x5e7c targets 0x5e40, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0x5e84 targets 0x5e40 and is always taken.
  The `beq` branch at 0x5e9c targets 0x5f04, is taken when a1(?) >= v1(?) (signed), and falls through when a1(?) < v1(?) (signed).
  The `beq` branch at 0x5ea4 targets 0x5ec8, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `beq` branch at 0x5eac targets 0x5ebc, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0x5eb4 targets 0x5ec8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x5ec0 targets 0x5ed0 and is always taken.
  The `beq` branch at 0x5ed8 targets 0x5f04, is taken when a1(?) >= a4(?) (signed), and falls through when a1(?) < a4(?) (signed).
  The `beq` branch at 0x5ee0 targets 0x5e8c, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `beq` branch at 0x5ee8 targets 0x5ef8, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0x5ef0 targets 0x5e8c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x5efc targets 0x5e94 and is always taken.
  The `beq` branch at 0x5f04 targets 0x5f14, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x5f10 targets 0x60a8, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x5f18 targets 0x5f28, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x5f20 targets 0x60a8, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bltz` branch at 0x5f28 targets 0x60d0, is taken when s1(?) < 0 (signed), and falls through when s1(?) >= 0 (signed).
  The `bltz` branch at 0x5f30 targets 0x60e8, is taken when s0(?) < 0 (signed), and falls through when s0(?) >= 0 (signed).
  The `blez` branch at 0x5f38 targets 0x5f50, is taken when s1(?) <= 0 (signed), and falls through when s1(?) > 0 (signed).
  The `blez` branch at 0x5f50 targets 0x5f6c, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `beq` branch at 0x5f70 targets 0x5f88, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `bne` branch at 0x5f78 targets 0x5f90, is taken when s5(=a2) != 0, and falls through when s5(=a2) == 0.
  The `beq` branch at 0x5f80 targets 0x5f98 and is always taken.
  The `beq` branch at 0x5f88 targets 0x5f98, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `blez` branch at 0x5fd8 targets 0x6034, is taken when s6(=one of 0x2, 0x4) <= 0 (signed), and falls through when s6(=one of 0x2, 0x4) > 0 (signed).
  The `beq` branch at 0x6008 targets 0x6034, is taken when a1(?) >= s6(=one of 0x2, 0x4) (signed), and falls through when a1(?) < s6(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x602c targets 0x5fe4, is taken when a1(?) < s6(=one of 0x2, 0x4) (signed), and falls through when a1(?) >= s6(=one of 0x2, 0x4) (signed).
  The `blez` branch at 0x6034 targets 0x6054, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x60a8 targets 0x6064 and is always taken.
  The `bne` branch at 0x60c0 targets 0x5d7c, is taken when a2(?) != a3(=0x36), and falls through when a2(?) == a3(=0x36).
  The `beq` branch at 0x60c8 targets 0x5e04 and is always taken.
  The `beq` branch at 0x60e0 targets 0x5f30 and is always taken.
  The `beq` branch at 0x60f8 targets 0x5f38 and is always taken.
  The return at 0x60a0 has v0 = one of -0x1, 0x0.

- `pcibr_rrb_check` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x6100 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x6100-0x6234 (308 bytes).
  It occupies 308 bytes.
  The `lbu` at 0x6150 loads 1 byte from ret(pciio_info_mfast_get) +0x39.
  The `lbu` at 0x6154 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0x619c loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `sw` at 0x61a4 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `lw` at 0x61b0 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528.
  The `sw` at 0x61b8 stores 4 bytes to a3 (arg3 at entry) +0x0.
  The `lw` at 0x61f0 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x56c.
  The `sw` at 0x61f8 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `lw` at 0x620c loads 4 bytes from ?.
  The `sw` at 0x6210 stores 4 bytes to a4 (arg4 at entry) +0x0.
  The `jal` at 0x6124 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x613c calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?, a7=-0x1.
  The `jal` at 0x6174 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?, a7=-0x1.
  The `jal` at 0x6214 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=([ret(pciio_hostinfo_get)+540]:1 << 0x4), a3=([ret(pciio_hostinfo_get)+540]:1 << 0x2).
  The `beq` branch at 0x6134 targets 0x61c4, is taken when v0(=ret(pciio_hostinfo_get)) == 0, and falls through when v0(=ret(pciio_hostinfo_get)) != 0.
  The `beq` branch at 0x6148 targets 0x622c, is taken when v0(=ret(pciio_info_mfast_get)) == 0, and falls through when v0(=ret(pciio_info_mfast_get)) != 0.
  The `beq` branch at 0x6164 targets 0x6224, is taken when at(=[ret(pciio_hostinfo_get)+540]:1) >= v0(=[ret(pciio_info_mfast_get)+57]:1+1) (signed), and falls through when at(=[ret(pciio_hostinfo_get)+540]:1) < v0(=[ret(pciio_info_mfast_get)+57]:1+1) (signed).
  The `beq` branch at 0x6190 targets 0x61e8, is taken when s1(=a1) == 0, and falls through when s1(=a1) != 0.
  The `bne` branch at 0x61a0 targets 0x61ec, is taken when s4(=a2) != 0, and falls through when s4(=a2) == 0.
  The `beq` branch at 0x61a8 targets 0x61fc, is taken when s3(=a3) == 0, and falls through when s3(=a3) != 0.
  The `bne` branch at 0x61b4 targets 0x6200, is taken when s2(=a4) != 0, and falls through when s2(=a4) == 0.
  The `beq` branch at 0x61bc targets 0x6214 and is always taken.
  The `beq` branch at 0x61e8 targets 0x61a8, is taken when s4(=a2) == 0, and falls through when s4(=a2) != 0.
  The `bne` branch at 0x61f4 targets 0x61ac, is taken when s3(=a3) != 0, and falls through when s3(=a3) == 0.
  The `beq` branch at 0x61fc targets 0x6214, is taken when s2(=a4) == 0, and falls through when s2(=a4) != 0.
  The `beq` branch at 0x621c targets 0x61c4 and is always taken.
  The `beq` branch at 0x6224 targets 0x61c8 and is always taken.
  The `beq` branch at 0x622c targets 0x61c8 and is always taken.
  The return at 0x61e0 has v0 = one of -0x1, 0x0.

- `pcibr_alloc_all_rrbs` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x6234
  **Inferred.** Role (from name): allocates read-response buffers for the bridge. It calls `hwgraph_traverse` at 0x627c (a zero result goes to 0x657c, which calls `hwgraph_fastinfo_get`), `xtalk_piotrans_addr` at 0x62a0 (a1 0, a2 0, a3 8, a4 0), `mutex_spinlock` at 0x649c, `pcireg_rrb_set` at 0x64b8, `mutex_io_spinunlock` at 0x654c and `hwgraph_vertex_unref` at 0x6594. The `mutex_spinlock` call is skipped when the `beq` at 0x6494 finds a value zero. Words loaded in the routine are compared with 0xc002 (the `beq` at 0x62e0 and 0x63ac) and 0xd002 (the `beq` at 0x62f8 and 0x63c4), and with 0x36 and 0x24; a run of word stores follows at 0x64ec to 0x6550. The facts do not show a loop over slots.
  Reviewed: 2026-11-12

- `pcibr_slot_initial_rrb_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x6608 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x6608-0x69bc (948 bytes).
  It occupies 948 bytes.
  The `lbu` at 0x6648 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `ld` at 0x665c loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(hwgraph_fastinfo_get)+8]:8 +0x4, including `lw` at 0x6660, `lw` at 0x6678, `lw` at 0x6834.
  8 such `sw` accesses store 4 bytes to ?, including `sw` at 0x66bc, `sw` at 0x6788, `sw` at 0x67b4.
  3 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0x66c0, `lh` at 0x6738, `lh` at 0x688c.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x78, including `lw` at 0x6714, `lw` at 0x6830.
  The `ld` at 0x6728 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `ld` at 0x6734 loads 8 bytes from [(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8 +0x0.
  2 such `lw` accesses load 4 bytes from [[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8 +0x14, including `lw` at 0x6748, `lw` at 0x68f8.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x6784, `lw` at 0x67ac.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100, including `lw` at 0x6874, `lw` at 0x6908.
  The `sw` at 0x6960 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x4)) +0x574.
  The `jal` at 0x6620 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x66a8 calls do_pcibr_rrb_count_valid with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x670c calls pcibr_debug with a0=0x20, a1=a0 at entry (arg0), a2=sym(.rodata)+3392, a3=?.
  The `jal` at 0x6824 calls pcibr_debug with a0=0x20, a1=a0 at entry (arg0), a2=sym(.rodata)+3392, a3=?.
  The `jal` at 0x6884 calls do_pcibr_rrb_free_all with a0=ret(hwgraph_fastinfo_get), a1=[ret(hwgraph_fastinfo_get)+8]:8, a2=a1 at entry (arg1), a3=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20], a4=-0x1, a5=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256].
  The `jal` at 0x6928 calls do_pcibr_rrb_free with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=?, a3=0x8.
  The `beq` branch at 0x6640 targets 0x67bc, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x6654 targets 0x67ec, is taken when s1(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s1(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0x6670 targets 0x6834, is taken when v0(?) == v1(=0xc002), and falls through when v0(?) != v1(=0xc002).
  The `beq` branch at 0x6688 targets 0x6854, is taken when v1(?) == a0(=0xd002), and falls through when v1(?) != a0(=0xd002).
  The `bne` branch at 0x66b8 targets 0x6698, is taken when s3(?) < s2(=one of 0x2, 0x4) (signed), and falls through when s3(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x66c4 targets 0x67f4, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == 0, and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != 0.
  The `beq` branch at 0x66cc targets 0x67f8, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == s3(=0x1), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != s3(=0x1).
  The `beq` branch at 0x66d8 targets 0x6964, is taken when s1(=a1) == t9(=0xff), and falls through when s1(=a1) != t9(=0xff).
  The `beq` branch at 0x66e4 targets 0x66f0, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == ra(=0x2), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != ra(=0x2).
  The `beq` branch at 0x6730 targets 0x6748, is taken when (v1(?) & 0x2) == 0, and falls through when (v1(?) & 0x2) != 0.
  The `beq` branch at 0x6740 targets 0x68e8, is taken when a2(=[ret(hwgraph_fastinfo_get)+114]:2) == a1(=0x2), and falls through when a2(=[ret(hwgraph_fastinfo_get)+114]:2) != a1(=0x2).
  The `beq` branch at 0x6750 targets 0x6874, is taken when a3(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20]) == a4(=-0x1), and falls through when a3(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20]) != a4(=-0x1).
  The `blez` branch at 0x6758 targets 0x67bc, is taken when s2(=one of 0x2, 0x4) <= 0 (signed), and falls through when s2(=one of 0x2, 0x4) > 0 (signed).
  The `beq` branch at 0x678c targets 0x67b8, is taken when v0(?) >= s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) < s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x67b0 targets 0x6768, is taken when v0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x67ec targets 0x67bc and is always taken.
  The `beq` branch at 0x67f8 targets 0x6810, is taken when s1(=a1) == t0(=0xff), and falls through when s1(=a1) != t0(=0xff).
  The `beq` branch at 0x6804 targets 0x6810, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == t1(=0x2), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != t1(=0x2).
  The `beq` branch at 0x682c targets 0x6718 and is always taken.
  The `bne` branch at 0x6844 targets 0x6678, is taken when a3(?) != a4(=0x36), and falls through when a3(?) == a4(=0x36).
  The `beq` branch at 0x684c targets 0x686c and is always taken.
  The `bne` branch at 0x6864 targets 0x6690, is taken when a4(?) != a5(=0x24), and falls through when a4(?) == a5(=0x24).
  The `beq` branch at 0x686c targets 0x6690 and is always taken.
  The `bne` branch at 0x6878 targets 0x6758, is taken when a5(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0, and falls through when a5(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0.
  The `beq` branch at 0x6894 targets 0x696c, is taken when a6(=[ret(hwgraph_fastinfo_get)+114]:2) == 0, and falls through when a6(=[ret(hwgraph_fastinfo_get)+114]:2) != 0.
  The `bne` branch at 0x689c targets 0x68e0, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x68bc targets 0x68e0, is taken when v0(?) >= s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) < s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x68d8 targets 0x68a8, is taken when v0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x68e0 targets 0x67bc and is always taken.
  The `beq` branch at 0x68e8 targets 0x68f8, is taken when a1(=0x2) == s1(=a1), and falls through when a1(=0x2) != s1(=a1).
  The `bne` branch at 0x68f0 targets 0x6748, is taken when s1(=a1) != t1(=0x3), and falls through when s1(=a1) == t1(=0x3).
  The `bne` branch at 0x6900 targets 0x6758, is taken when t2(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20]) != t3(=-0x1), and falls through when t2(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20]) == t3(=-0x1).
  The `bne` branch at 0x690c targets 0x6758, is taken when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0, and falls through when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0.
  The `bne` branch at 0x6944 targets 0x691c, is taken when s2(?) < 0x2 (signed), and falls through when s2(?) >= 0x2 (signed).
  The `beq` branch at 0x695c targets 0x67bc and is always taken.
  The `beq` branch at 0x6964 targets 0x66f4 and is always taken.
  The `bne` branch at 0x696c targets 0x68e0, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x6990 targets 0x68e0, is taken when v0(?) >= s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) < s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x69ac targets 0x697c, is taken when v0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x69b4 targets 0x68e0 and is always taken.
  The return at 0x67e4 has v0 = one of 0x0, 0x13, 0x16.

- `pcibr_initial_rrb` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x69bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x69bc-0x6d14 (856 bytes).
  It occupies 856 bytes.
  The `ld` at 0x6a04 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(hwgraph_fastinfo_get)+8]:8 +0x4, including `lw` at 0x6a0c, `lw` at 0x6a48, `lw` at 0x6cc8.
  2 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0x6a1c, `lbu` at 0x6c8c.
  The `lbu` at 0x6a24 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  The `sw` at 0x6a90 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x520.
  The `sw` at 0x6aa8 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x524.
  9 such `lw` accesses load 4 bytes from ?, including `lw` at 0x6ac4, `lw` at 0x6ac8, `lw` at 0x6ad4.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0x6b08, `sw` at 0x6b40, `sw` at 0x6b74.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x34, including `lw` at 0x6b94, `lw` at 0x6d10.
  The `jal` at 0x69e4 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6a7c calls do_pcibr_rrb_count_avail with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=?, a3=?.
  The `jal` at 0x6a8c calls do_pcibr_rrb_count_avail with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x1, a2=?, a3=?.
  The `jal` at 0x6be8 calls pcibr_rrb_debug with a0=sym(.rodata)+3392, a1=ret(hwgraph_fastinfo_get), a2=?, a3=?, a5=0x1, a7=sp-88.
  The `jal` at 0x6c80 calls pcibr_slot_initial_rrb_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x6a40 targets 0x6cc8, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0x6a54 targets 0x6ce8, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `beq` branch at 0x6a60 targets 0x6a70, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x6a68 targets 0x6c80 and is always taken.
  The `bne` branch at 0x6b00 targets 0x6b34, is taken when t0(?) < v1(?) (signed), and falls through when t0(?) >= v1(?) (signed).
  The `bne` branch at 0x6b14 targets 0x6ab8, is taken when a0(?) < 0x2 (signed), and falls through when a0(?) >= 0x2 (signed).
  The `bne` branch at 0x6b20 targets 0x6bd8, is taken when s3(=a2) < a2(?) (signed), and falls through when s3(=a2) >= a2(?) (signed).
  The `beq` branch at 0x6b2c targets 0x6d08 and is always taken.
  The `bne` branch at 0x6b34 targets 0x6c10, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x6b3c targets 0x6b0c and is always taken.
  The `bne` branch at 0x6b60 targets 0x6b48, is taken when a1(?) < s1(=one of 0x2, 0x4) (signed), and falls through when a1(?) >= s1(=one of 0x2, 0x4) (signed).
  The `blez` branch at 0x6b6c targets 0x6b84, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `bne` branch at 0x6b8c targets 0x6bd8, is taken when s3(=a2) < v0(?) (signed), and falls through when s3(=a2) >= v0(?) (signed).
  The `bne` branch at 0x6b9c targets 0x6b84, is taken when (a0(=[ret(hwgraph_fastinfo_get)+52]) & a1(?)) != 0, and falls through when (a0(=[ret(hwgraph_fastinfo_get)+52]) & a1(?)) == 0.
  The `bne` branch at 0x6bbc targets 0x6b44, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `blez` branch at 0x6bc4 targets 0x6b84, is taken when a6(?) <= 0 (signed), and falls through when a6(?) > 0 (signed).
  The `beq` branch at 0x6bd0 targets 0x6b70 and is always taken.
  The `bne` branch at 0x6c10 targets 0x6cc0, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x6c18 targets 0x6b0c and is always taken.
  The `bne` branch at 0x6c3c targets 0x6c24, is taken when a2(?) < s1(=one of 0x2, 0x4) (signed), and falls through when a2(?) >= s1(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x6c48 targets 0x6c70, is taken when v0(?) >= 0x3 (signed), and falls through when v0(?) < 0x3 (signed).
  The `beq` branch at 0x6c78 targets 0x6a70, is taken when s2(?) >= a5(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(?) < a5(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `bne` branch at 0x6c9c targets 0x6c70, is taken when s2(?) < s4(=a1) (signed), and falls through when s2(?) >= s4(=a1) (signed).
  The `bne` branch at 0x6ca4 targets 0x6c70, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x6cac targets 0x6c20, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `beq` branch at 0x6cb8 targets 0x6c50 and is always taken.
  The `beq` branch at 0x6cc0 targets 0x6b0c and is always taken.
  The `bne` branch at 0x6cd8 targets 0x6a48, is taken when t3(?) != t8(=0x36), and falls through when t3(?) == t8(=0x36).
  The `beq` branch at 0x6ce0 targets 0x6d00 and is always taken.
  The `bne` branch at 0x6cf8 targets 0x6a5c, is taken when t8(?) != t9(=0x24), and falls through when t8(?) == t9(=0x24).
  The `beq` branch at 0x6d00 targets 0x6a5c and is always taken.
  The `beq` branch at 0x6d0c targets 0x6b98 and is always taken.
  The return at 0x6c08 has v0 = 0x0.

- `pcibr_rrb_debug` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x6d14 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x6d14-0x6ee8 (468 bytes).
  It occupies 468 bytes.
  The `lw` at 0x6d48 loads 4 bytes from a1 (arg1 at entry) +0x524.
  The `lw` at 0x6d54 loads 4 bytes from a1 (arg1 at entry) +0x520.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x6d58, `lw` at 0x6d78, `lw` at 0x6df0.
  3 such `lh` accesses load 2 bytes from a1 (arg1 at entry) +0x72, including `lh` at 0x6d64, `lh` at 0x6da0, `lh` at 0x6e18.
  3 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x39, including `lbu` at 0x6d84, `lbu` at 0x6dfc, `lbu` at 0x6ee4.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0x6dac, `lw` at 0x6db4, `lw` at 0x6dc0.
  The `jal` at 0x6d5c calls pcibr_debug with a0=0x20, a1=[a1+4], a2=sym(.rodata)+3392, a3=a0 at entry (arg0), a4=[a1+1312], a5=[a1+1316].
  The `jal` at 0x6d7c calls pcibr_debug with a0=0x20, a1=[a1+4], a2=sym(.rodata)+3392, a3=?.
  The `jal` at 0x6ddc calls sprintf with a0=sp-320, a1=sym(.rodata)+3392, a2=?, a3=?.
  The `jal` at 0x6df4 calls pcibr_debug with a0=0x20, a1=[a1+4], a2=sym(.rodata)+3392, a3=sp-320.
  The `jal` at 0x6e80 calls sprintf with a0=sp-320, a1=sym(.rodata)+3392, a2=?, a3=?.
  The `jal` at 0x6ed8 calls pcibr_debug with a0=0x20, a1=[a1+4], a2=sym(.rodata)+3392, a3=?.
  The `beq` branch at 0x6d40 targets 0x6e90, is taken when (at(=[sym(pcibr_debug_mask)]) & 0x20) == 0, and falls through when (at(=[sym(pcibr_debug_mask)]) & 0x20) != 0.
  The `beq` branch at 0x6d68 targets 0x6ed0, is taken when a0(=[a1+114]:2) == 0, and falls through when a0(=[a1+114]:2) != 0.
  The `beq` branch at 0x6d70 targets 0x6ed0, is taken when a0(=[a1+114]:2) == a1(=0x1), and falls through when a0(=[a1+114]:2) != a1(=0x1).
  The `bltz` branch at 0x6d94 targets 0x6e90, is taken when v0(=[a1+57]:1) < 0 (signed), and falls through when v0(=[a1+57]:1) >= 0 (signed).
  The `beq` branch at 0x6d9c targets 0x6e1c and is always taken.
  The `beq` branch at 0x6e10 targets 0x6e90, is taken when s0(?) >= a3(=[a1+57]:1+1) (signed), and falls through when s0(?) < a3(=[a1+57]:1+1) (signed).
  The `beq` branch at 0x6e1c targets 0x6e48, is taken when a0(=[a1+114]:2) == 0, and falls through when a0(=[a1+114]:2) != 0.
  The `beq` branch at 0x6e24 targets 0x6e48, is taken when a0(=[a1+114]:2) == s5(=0x1), and falls through when a0(=[a1+114]:2) != s5(=0x1).
  The `beq` branch at 0x6e2c targets 0x6eb4, is taken when s3(=0xff) == s0(?), and falls through when s3(=0xff) != s0(?).
  The `bne` branch at 0x6e34 targets 0x6da4, is taken when a0(=[a1+114]:2) != s4(=0x2), and falls through when a0(=[a1+114]:2) == s4(=0x2).
  The `beq` branch at 0x6e40 targets 0x6da4 and is always taken.
  The `beq` branch at 0x6e48 targets 0x6ebc, is taken when s3(=0xff) == s0(?), and falls through when s3(=0xff) != s0(?).
  The `beq` branch at 0x6e50 targets 0x6ec4, is taken when a0(=[a1+114]:2) == s4(=0x2), and falls through when a0(=[a1+114]:2) != s4(=0x2).
  The `beq` branch at 0x6e88 targets 0x6de8 and is always taken.
  The `beq` branch at 0x6eb4 targets 0x6da4 and is always taken.
  The `beq` branch at 0x6ebc targets 0x6e58 and is always taken.
  The `beq` branch at 0x6ec8 targets 0x6e58 and is always taken.
  The `beq` branch at 0x6ee0 targets 0x6d88 and is always taken.
  The return at 0x6eac has v0 = one of ?, [a1+57]:1, ret(pcibr_debug).

- `pcibr_hints_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x6ee8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x6ee8-0x6ff0 (264 bytes).
  It occupies 264 bytes.
  The `sd` at 0x6f2c stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sd` at 0x6f34 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `jal` at 0x6f04 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4152, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x6f20 calls kmem_zalloc with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0x6f3c calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4152, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x6f80 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4152, a2=sp-48, a3=?.
  The `jal` at 0x6fd4 calls cmn_err with a0=0x4, a1=sym(.rodata)+4152, a2=?, a3=?.
  The `jal` at 0x6fe0 calls kmem_free with a0=?, a1=0x20, a2=?, a3=?.
  The `beq` branch at 0x6f0c targets 0x6f70, is taken when s3(=a1) == 0, and falls through when s3(=a1) != 0.
  The `beq` branch at 0x6f14 targets 0x6f68, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0x6f48 targets 0x6f78, is taken when v0(=ret(hwgraph_info_add_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_add_LBL)) != 0.
  The `beq` branch at 0x6f50 targets 0x6fcc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x6f68 targets 0x6f58 and is always taken.
  The `beq` branch at 0x6f70 targets 0x6f58 and is always taken.
  The `beq` branch at 0x6f8c targets 0x6fac, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0x6f94 targets 0x6fd0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x6f9c targets 0x6fd0, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x6fa4 targets 0x6f58 and is always taken.
  The `beq` branch at 0x6fb8 targets 0x6fcc, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x6fc0 targets 0x6fd0, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x6fc8 targets 0x6f58, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x6fe8 targets 0x6f58 and is always taken.
  The return at 0x6f60 has v0 = one of ?, 0x0.

- `pcibr_hints_fix_some_rrbs` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x6ff0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x6ff0-0x703c (76 bytes).
  It occupies 76 bytes.
  The `sw` at 0x7010 stores 4 bytes to ret(pcibr_hints_get) +0x8.
  The `jal` at 0x7000 calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x702c calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4152, a3=?.
  The `beq` branch at 0x7008 targets 0x7020, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x7034 targets 0x7018 and is always taken.
  The return at 0x7018 has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_hints_fix_rrbs` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x703c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x703c-0x7058 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x7044 calls pcibr_hints_fix_some_rrbs with a0=a0 at entry (arg0), a1=0xff, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x7050 has v0 = ret(pcibr_hints_fix_some_rrbs).

- `pcibr_hints_dualslot` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x7058 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x7058-0x70b4 (92 bytes).
  It occupies 92 bytes.
  The `sb` at 0x708c stores 1 byte to (a2 + ret(pcibr_hints_get)) +0x0.
  The `jal` at 0x706c calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x70a4 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4152, a3=?.
  The `beq` branch at 0x7074 targets 0x709c, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x70ac targets 0x7094 and is always taken.
  The return at 0x7094 has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_hints_intr_bits` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x70b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x70b4-0x7100 (76 bytes).
  It occupies 76 bytes.
  The `sd` at 0x70d8 stores 8 bytes to ret(pcibr_hints_get) +0x18.
  The `jal` at 0x70c4 calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x70f0 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4152, a3=?.
  The `beq` branch at 0x70cc targets 0x70e8, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x70f8 targets 0x70e0 and is always taken.
  The return at 0x70e0 has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_set_rrb_callback` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x7100 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x7100-0x712c (44 bytes).
  It occupies 44 bytes.
  The `sd` at 0x7120 stores 8 bytes to ret(pcibr_hints_get) +0x10.
  The `jal` at 0x710c calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x7114 targets 0x7124, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The return at 0x7124 has v0 = ret(pcibr_hints_get).

- `pcibr_hints_handsoff` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x712c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x712c-0x7174 (72 bytes).
  It occupies 72 bytes.
  The `sw` at 0x7148 stores 4 bytes to ret(pcibr_hints_get) +0xc.
  The `jal` at 0x7138 calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7164 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4152, a3=0x1.
  The `beq` branch at 0x7140 targets 0x7158, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x716c targets 0x7150 and is always taken.
  The return at 0x7150 has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_hints_subdevs` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x7174 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x7174-0x72c8 (340 bytes).
  It occupies 340 bytes.
  The `sd` at 0x71e8 stores 8 bytes to ?.
  The `sd` at 0x7218 stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `jal` at 0x71a8 calls sprintf with a0=sp-48, a1=sym(.rodata)+4152, a2=sym(.rodata)+4152, a3=a1 at entry (arg1), a4=-0x1.
  The `jal` at 0x71b8 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-48, a2=sp-56, a3=?.
  The `jal` at 0x71d4 calls hwgraph_info_get_LBL with a0=?, a1=sym(.rodata)+4152, a2=sp-64, a3=?, a5=-0x1.
  The `jal` at 0x7200 calls kmem_zalloc with a0=0x8, a1=0x0, a2=?, a3=?.
  The `jal` at 0x7220 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+4152, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7234 calls hwgraph_info_get_LBL with a0=?, a1=sym(.rodata)+4152, a2=sp-64, a3=?.
  The `jal` at 0x724c calls kmem_free with a0=?, a1=0x8, a2=?, a3=?.
  The `jal` at 0x7268 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4152, a3=?.
  The `jal` at 0x7284 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4152, a3=?, a5=-0x1.
  The `jal` at 0x72a0 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4152, a3=?.
  The `jal` at 0x72b8 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4152, a3=?.
  The `beq` branch at 0x71c8 targets 0x7278, is taken when a5(=-0x1) == a0(?), and falls through when a5(=-0x1) != a0(?).
  The `beq` branch at 0x71e0 targets 0x7200, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x7208 targets 0x7294, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x7244 targets 0x71ec, is taken when a2(?) == a3(?), and falls through when a2(?) != a3(?).
  The `beq` branch at 0x7258 targets 0x72b0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x7270 targets 0x71e8 and is always taken.
  The `beq` branch at 0x728c targets 0x71f0 and is always taken.
  The `beq` branch at 0x72a8 targets 0x71f0 and is always taken.
  The `beq` branch at 0x72c0 targets 0x71f0 and is always taken.
  The return at 0x71f8 has v0 = one of ?, ret(pcibr_debug).

- `pcibr_intr_bits` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x72c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x72c8-0x7314 (76 bytes).
  It occupies 76 bytes.
  The `lbu` at 0x72c8 loads 1 byte from a0 (arg0 at entry) +0x21c.
  The `beq` branch at 0x72dc targets 0x7304, is taken when a6(=[a0+540]:1) >= a2 (signed), and falls through when a6(=[a0+540]:1) < a2 (signed).
  The `beq` branch at 0x72e4 targets 0x730c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x730c targets 0x72ec and is always taken.
  The return at 0x72fc has v0 = ?.
  The return at 0x7304 has v0 = 0x0.

- `pcibr_wrap_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x7314 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x7314-0x7378 (100 bytes).
  It occupies 100 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x7314, `lw` at 0x7374.
  The `lw` at 0x7318 loads 4 bytes from a0 (arg0 at entry) +0x4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8, including `sw` at 0x7340, `sw` at 0x7350.
  The `ld` at 0x7348 loads 8 bytes from (a0 + ([a0+8]+1 << 0x3)) +0x8.
  The `jal` at 0x7364 calls panic with a0=sym(.rodata)+4616, a1=a0 at entry (arg0), a2=[a0+8], a3=a3 at entry (arg3).
  The `beq` branch at 0x7328 targets 0x7360, is taken when at(=[a0+4]) == a2(=[a0+8]), and falls through when at(=[a0+4]) != a2(=[a0+8]).
  The `beq` branch at 0x7370 targets 0x7330 and is always taken.
  The return at 0x7358 has v0 = [(a0 + ([a0+8]+1 << 0x3))+8]:8.

- `pcibr_wrap_put` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x7378 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x7378-0x740c (148 bytes).
  It occupies 148 bytes.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x7398, `lw` at 0x7408.
  The `lw` at 0x73a8 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `sd` at 0x73c8 stores 8 bytes to (a1 + ([a1+4] << 0x3)) +0x10.
  The `sw` at 0x73cc stores 4 bytes to a1 (arg1 at entry) +0x4.
  The `jal` at 0x7390 calls mutex_spinlock with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x73d0 calls mutex_spinunlock with a0=a1 at entry (arg1), a1=ret(mutex_spinlock), a2=[a1+4], a3=?.
  The `jal` at 0x73f4 calls panic with a0=sym(.rodata)+4616, a1=a1 at entry (arg1), a2=[a1+4], a3=?.
  The `beq` branch at 0x73b4 targets 0x73ec, is taken when at(=[a1+8]) == a5(?), and falls through when at(=[a1+8]) != a5(?).
  The `beq` branch at 0x7404 targets 0x73bc and is always taken.
  The return at 0x73e4 has v0 = ret(mutex_spinunlock).

- `pcibr_force_interrupt` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x740c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x740c-0x74d4 (200 bytes).
  It occupies 200 bytes.
  The `ld` at 0x7414 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x7418 loads 2 bytes from [a0]:8 +0x72.
  The `lw` at 0x7420 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x7478 loads 8 bytes from ?.
  The `ld` at 0x74a8 loads 8 bytes from table(sym(pdaindr)) +0x8.
  The `lh` at 0x74b4 loads 2 bytes from [table(sym(pdaindr))+8]:8 +0x424.
  The `sd` at 0x74d0 stores 8 bytes to ([[table(sym(pdaindr))+8]:8+1060]:2 << 0x20) -0x6dfffffffe7fff70.
  The `jal` at 0x7430 calls pcireg_force_intr_set with a0=[a0]:8, a1=[a0+8], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x744c calls pcireg_intr_status_get with a0=[a0]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x747c calls xtalk_intr_vector_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7488 calls xtalk_intr_cpuid_get with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x7424 targets 0x744c, is taken when at(=[[a0]:8+114]:2) == 0, and falls through when at(=[[a0]:8+114]:2) != 0.
  The `beq` branch at 0x7460 targets 0x743c, is taken when (v0(=ret(pcireg_intr_status_get)) & v1(?)) == 0, and falls through when (v0(=ret(pcireg_intr_status_get)) & v1(?)) != 0.
  The `beq` branch at 0x74cc targets 0x7438 and is always taken.
  The return at 0x7444 has v0 = ?.

- `pcibr_intrd` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x74d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x74d4-0x754c (120 bytes).
  It occupies 120 bytes.
  The `ld` at 0x74d8 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0x74ec loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ll` at 0x7500 loads 4 bytes from ret(pcibr_wrap_get) +0x18.
  The `sc` at 0x750c stores 4 bytes to ret(pcibr_wrap_get) +0x18.
  The `lw` at 0x7518 loads 4 bytes from ret(pcibr_wrap_get) +0x18.
  The `jalr` at 0x74e8 calls (unknown callee) with a0=[a0+32]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x74f0 calls pcibr_wrap_get with a0=a0+104, a1=?, a2=?, a3=?.
  The `jal` at 0x7524 calls ipsema with a0=a0+48, a1=?, a2=?, a3=?.
  The `jal` at 0x753c calls pcibr_force_interrupt with a0=ret(pcibr_wrap_get), a1=ret(pcibr_wrap_get)+24, a2=-0x1, a3=[ret(pcibr_wrap_get)+24]-1.
  The `beql` branch at 0x7510 targets 0x7500, is taken when a3(=[ret(pcibr_wrap_get)+24]-1) == 0, and falls through when a3(=[ret(pcibr_wrap_get)+24]-1) != 0; its branch-likely delay slot `nop` at 0x7514 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x751c targets 0x753c, is taken when v1(=[ret(pcibr_wrap_get)+24]) == 0, and falls through when v1(=[ret(pcibr_wrap_get)+24]) != 0.
  The `beq` branch at 0x7544 targets 0x7524 and is always taken.
  The return at 0x7534 has v0 = ret(ipsema).

- `pcibr_intrd_start` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x754c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x754c-0x75c8 (124 bytes).
  It occupies 124 bytes.
  The `lh` at 0x7560 loads 2 bytes from a0 (arg0 at entry) +0x50.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc020, including `ld` at 0x7564, `ld` at 0x7580.
  The `ld` at 0x757c loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ll` at 0x759c loads 4 bytes from a0 (arg0 at entry) +0x28.
  The `sc` at 0x75a4 stores 4 bytes to a0 (arg0 at entry) +0x28.
  The `jal` at 0x755c calls setmustrun with a0=[a0+80]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x756c calls xthread_set_func with a0=[-0x3fe0]:8, a1=sym(pcibr_intrd), a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x7578 calls fetch_kname with a0=[a0+24]:8, a1=sp-32, a2=?, a3=?.
  The `jal` at 0x758c calls strncpy with a0=[-0x3fe0]:8+832, a1=ret(fetch_kname), a2=0x10, a3=?.
  The `jal` at 0x75b0 calls ipsema with a0=a0+48, a1=[a0+40], a2=a0+40, a3=0x400, a4=([a0+40] | 0x400).
  The `beql` branch at 0x75a8 targets 0x759c, is taken when a4(=([a0+40] | 0x400)) == 0, and falls through when a4(=([a0+40] | 0x400)) != 0; its branch-likely delay slot `nop` at 0x75ac runs only when taken and is annulled on fall-through.
  The return at 0x75c0 has v0 = ret(ipsema).

- `pcibr_thread_setup` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x75c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x75c8-0x7640 (120 bytes).
  It occupies 120 bytes.
  The `sh` at 0x7604 stores 2 bytes to a0 (arg0 at entry) +0x48.
  The `ll` at 0x760c loads 4 bytes from a0 (arg0 at entry) +0x28.
  The `sc` at 0x7614 stores 4 bytes to a0 (arg0 at entry) +0x28.
  The `jal` at 0x75ec calls sprintf with a0=sp-64, a1=sym(.rodata)+4616, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x7628 calls xthread_setup with a0=sp-64, a1=a2 at entry (arg2), a2=a0+40, a3=sym(pcibr_intrd_start), a4=a0 at entry (arg0), a5=0x300, a6=([a0+40] | 0x300), a7=a2 at entry (arg2).
  The `beql` branch at 0x7618 targets 0x760c, is taken when a6(=([a0+40] | 0x300)) == 0, and falls through when a6(=([a0+40] | 0x300)) != 0; its branch-likely delay slot `nop` at 0x761c runs only when taken and is annulled on fall-through.
  The return at 0x7638 has v0 = ret(xthread_setup).

- `pcibr_intr_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x7640 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x7640-0x7c50 (1552 bytes).
  It occupies 1552 bytes.
  The `lbu` at 0x7684 loads 1 byte from ret(pcibr_info_get) +0x21c.
  The `ld` at 0x7688 loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `lw` at 0x7694 loads 4 bytes from [ret(pcibr_info_get)+40]:8 +0x0.
  2 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x70, including `sw` at 0x7740, `sw` at 0x7754.
  The `sw` at 0x7758 stores 4 bytes to ret(kmem_zalloc) +0x6c.
  The `sd` at 0x775c stores 8 bytes to ret(kmem_zalloc) +0x20.
  The `sd` at 0x7760 stores 8 bytes to ret(kmem_zalloc) +0x18.
  2 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x58, including `sw` at 0x7764, `sw` at 0x7824.
  The `sd` at 0x7768 stores 8 bytes to ret(kmem_zalloc) +0x60.
  3 such `sh` accesses store 2 bytes to ret(kmem_zalloc) +0x50, including `sh` at 0x7770, `sh` at 0x7804, `sh` at 0x7954.
  The `sw` at 0x7778 stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `sw` at 0x7784 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `sw` at 0x7794 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `ld` at 0x7798 loads 8 bytes from [ret(pcibr_info_get)+40]:8 +0x500.
  The `lbu` at 0x779c loads 1 byte from [ret(pcibr_info_get)+40]:8 +0x39.
  2 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x58, including `lw` at 0x7810, `lw` at 0x7c24.
  The `sd` at 0x7828 stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `sd` at 0x7830 stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0x783c stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sb` at 0x7854 stores 1 byte to ret(kmem_zalloc) +0x18.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x78c4, `ld` at 0x7904, `ld` at 0x798c.
  The `sw` at 0x79c8 stores 4 bytes to ?.
  The `ld` at 0x7a5c loads 8 bytes from a1 (arg1 at entry) +0x10.
  The `lh` at 0x7a7c loads 2 bytes from ret(kmem_zalloc) +0x50.
  2 such `ld` accesses load 8 bytes from [ret(pcibr_info_get)+40]:8 +0x10, including `ld` at 0x7bc4, `ld` at 0x7c28.
  The `jal` at 0x7660 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x76f0 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4616, a3=sym(.rodata)+4616, a4=sym(.rodata)+4616, a5=sym(.rodata)+4616, a6=sym(.rodata)+4616, a7=sym(.rodata)+4616.
  The `jal` at 0x76fc calls kmem_zalloc with a0=0xa0, a1=0x0, a2=?, a3=?.
  The `jal` at 0x771c calls device_desc_flags_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?, a5=[sym(default_intr_pri)].
  The `jal` at 0x7790 calls spinlock_init with a0=ret(kmem_zalloc)+104, a1=sym(.rodata)+4616, a2=?, a3=?.
  The `jalr` at 0x77a8 calls (unknown callee) with a0=?, a1=a2 at entry (arg2), a2=[[ret(pcibr_info_get)+40]:8+57]:1+1, a3=[[ret(pcibr_info_get)+40]:8+1280]:8.
  The `jal` at 0x77c0 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4616, a3=ret(?).
  The `jal` at 0x7820 calls kmem_zalloc with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0x7850 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4616, a3=?.
  The `jal` at 0x7860 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x787c calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4616, a3=ret(?).
  The `jal` at 0x78dc calls xtalk_intr_cpuid_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7914 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7928 calls kmem_free with a0=ret(kmem_zalloc), a1=0x20, a2=?, a3=?.
  The `jal` at 0x7940 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4616, a3=ret(?).
  The `jal` at 0x7960 calls xtalk_intr_alloc_nothd with a0=?, a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x797c calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4616, a3=ret(xtalk_intr_alloc_nothd).
  The `jal` at 0x79a4 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x79cc calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4616, a3=ret(?).
  The `jal` at 0x79e0 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(xtalk_intr_alloc_nothd), a3=?.
  The `jal` at 0x79f8 calls pcireg_intr_device_bit_clr with a0=[ret(pcibr_info_get)+40]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7a0c calls pcireg_intr_device_bit_set with a0=[ret(pcibr_info_get)+40]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7a20 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4616, a3=?.
  The `jal` at 0x7a44 calls pcibr_thread_setup [0x75c8] with a0=ret(kmem_zalloc), a1=ret(?), a2=?, a3=?, a4=a1 at entry (arg1).
  The `jal` at 0x7a64 calls xtalk_intr_cpuid_get with a0=?, a1=?, a2=?, a3=?, a4=a1 at entry (arg1).
  The `jal` at 0x7a94 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4616, a3=ret(kmem_zalloc), a4=a1 at entry (arg1), a6=ret(xtalk_intr_cpuid_get).
  The `jal` at 0x7ad8 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7aec calls kmem_free with a0=ret(kmem_zalloc), a1=0x20, a2=?, a3=?.
  The `jal` at 0x7b04 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4616, a3=ret(?).
  The `jal` at 0x7b18 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7b3c calls xtalk_intr_free with a0=ret(xtalk_intr_alloc_nothd), a1=?, a2=?, a3=?.
  The `jal` at 0x7b88 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4616, a3=ret(?).
  The `jal` at 0x7b9c calls intr_target_from_desc with a0=a1 at entry (arg1), a1=-0x1, a2=?, a3=?.
  The `jal` at 0x7bb0 calls device_desc_intr_swlevel_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x7bc8 calls cmn_err with a0=0x4, a1=sym(.rodata)+4616, a2=[[ret(pcibr_info_get)+40]:8+16]:8, a3=?, a5=-0x1.
  The `jal` at 0x7be0 calls cmn_err with a0=0x4, a1=sym(.rodata)+4616, a2=?, a3=?.
  The `jal` at 0x7bf8 calls vertex_to_name with a0=a3 at entry (arg3), a1=sp-440, a2=0x100, a3=?, a5=-0x1.
  The `jal` at 0x7c18 calls cmn_err with a0=0x4, a1=sym(.rodata)+4616, a2=?, a3=?, a5=sp-440, a6=a3 at entry (arg3).
  The `jal` at 0x7c2c calls cmn_err with a0=0x1, a1=sym(.rodata)+4616, a2=[[ret(pcibr_info_get)+40]:8+16]:8, a3=?.
  The `beq` branch at 0x7698 targets 0x7b50, is taken when (s0(=a2) & 0xf) == 0, and falls through when (s0(=a2) & 0xf) != 0.
  The `beq` branch at 0x76ac targets 0x7b5c, is taken when (s0(=a2) & 0x1) == 0, and falls through when (s0(=a2) & 0x1) != 0.
  The `beq` branch at 0x76bc targets 0x7b64, is taken when (s0(=a2) & 0x2) == 0, and falls through when (s0(=a2) & 0x2) != 0.
  The `beq` branch at 0x76cc targets 0x7b6c, is taken when (s0(=a2) & 0x4) == 0, and falls through when (s0(=a2) & 0x4) != 0.
  The `beq` branch at 0x76dc targets 0x7b74, is taken when (s0(=a2) & 0x8) == 0, and falls through when (s0(=a2) & 0x8) != 0.
  The `beq` branch at 0x7708 targets 0x7b34, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x7714 targets 0x7744, is taken when t0(=a1) == 0, and falls through when t0(=a1) != 0.
  The `beq` branch at 0x7734 targets 0x7b98, is taken when (v0(=ret(device_desc_flags_get)) & 0x4) == 0, and falls through when (v0(=ret(device_desc_flags_get)) & 0x4) != 0.
  The `beq` branch at 0x773c targets 0x7758 and is always taken.
  The `beq` branch at 0x77d8 targets 0x7c3c and is always taken.
  The `bne` branch at 0x77e8 targets 0x7bc0, is taken when a6(?) != a1(?), and falls through when a6(?) == a1(?).
  The `beq` branch at 0x77f4 targets 0x7950, is taken when a7(?) == a5(=-0x1), and falls through when a7(?) != a5(=-0x1).
  The `bne` branch at 0x7808 targets 0x7bf0, is taken when t1(?) != t0(?), and falls through when t1(?) == t0(?).
  The `beq` branch at 0x7868 targets 0x7904, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x78a0 targets 0x7a30, is taken when s0(?) >= 0x8 (unsigned), and falls through when s0(?) < 0x8 (unsigned).
  The `beq` branch at 0x78b4 targets 0x7884, is taken when (s5(?) & s3(=ret(?))) == 0, and falls through when (s5(?) & s3(=ret(?))) != 0.
  The `beq` branch at 0x78c8 targets 0x7958, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x78d4 targets 0x7810, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x78ec targets 0x77e0, is taken when a1(?) != a5(=-0x1), and falls through when a1(?) == a5(=-0x1).
  The `beq` branch at 0x78fc targets 0x77f0 and is always taken.
  The `beq` branch at 0x791c targets 0x79a0, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x7948 targets 0x7888 and is always taken.
  The `beq` branch at 0x7950 targets 0x7810 and is always taken.
  The `bne` branch at 0x7984 targets 0x79dc, is taken when s7(=ret(xtalk_intr_alloc_nothd)) != 0, and falls through when s7(=ret(xtalk_intr_alloc_nothd)) == 0.
  The `bne` branch at 0x7990 targets 0x78d4, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0x7998 targets 0x7c28 and is always taken.
  The `beq` branch at 0x79ac targets 0x7ad0, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x79d4 targets 0x7888 and is always taken.
  The `beq` branch at 0x79e8 targets 0x7b3c, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x7a28 targets 0x78d4 and is always taken.
  The `beq` branch at 0x7a34 targets 0x7a50, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x7a50 targets 0x7a60, is taken when a4(=a1) == 0, and falls through when a4(=a1) != 0.
  The `beq` branch at 0x7a58 targets 0x7a64 and is always taken.
  The `beq` branch at 0x7a74 targets 0x7a80, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x7ae0 targets 0x7b14, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x7b0c targets 0x7888 and is always taken.
  The `bne` branch at 0x7b20 targets 0x7b7c, is taken when v0(=ret(compare_and_swap_ptr)) != 0, and falls through when v0(=ret(compare_and_swap_ptr)) == 0.
  The `beq` branch at 0x7b2c targets 0x7ad0 and is always taken.
  The `beq` branch at 0x7b34 targets 0x7a9c and is always taken.
  The `beq` branch at 0x7b48 targets 0x78d0 and is always taken.
  The `beq` branch at 0x7b54 targets 0x76a8 and is always taken.
  The `beq` branch at 0x7b5c targets 0x76b8 and is always taken.
  The `beq` branch at 0x7b64 targets 0x76c8 and is always taken.
  The `beq` branch at 0x7b6c targets 0x76d8 and is always taken.
  The `beq` branch at 0x7b74 targets 0x76e8 and is always taken.
  The `beq` branch at 0x7b90 targets 0x7888 and is always taken.
  The `beq` branch at 0x7bb8 targets 0x7754 and is always taken.
  The `beq` branch at 0x7be8 targets 0x77f0 and is always taken.
  The `beq` branch at 0x7c20 targets 0x7814 and is always taken.
  The `beq` branch at 0x7c34 targets 0x7a9c and is always taken.
  The `beq` branch at 0x7c48 targets 0x78ac and is always taken.
  The return at 0x7ac8 has v0 = one of ret(kmem_zalloc), 0x0.

- `pcibr_intr_setmustrun` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x7c50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x7c50-0x7c94 (68 bytes).
  It occupies 68 bytes.
  The `sh` at 0x7c74 stores 2 bytes to a0 (arg0 at entry) +0x50.
  The `jal` at 0x7c60 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7c70 calls setmustrun with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x7c80 calls splx with a0=(ret(splhi) << 0x0), a1=?, a2=?, a3=?.
  The return at 0x7c8c has v0 = ret(splx).

- `pcibr_intr_free` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x7c94 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x7c94-0x7e8c (504 bytes).
  It occupies 504 bytes.
  The `lw` at 0x7c9c loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x7ca4 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `sd` at 0x7cec stores 8 bytes to ?.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x7d30, `ld` at 0x7d64, `ld` at 0x7d7c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x7d58, `lw` at 0x7dd0.
  The `lw` at 0x7d70 loads 4 bytes from ?.
  The `lw` at 0x7d90 loads 4 bytes from a0 (arg0 at entry) +0x0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x28, including `lw` at 0x7da0, `lw` at 0x7e40.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x7db4, `ld` at 0x7ddc.
  The `jal` at 0x7ce0 calls xtalk_intr_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7cf4 calls pcireg_intr_device_bit_clr with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7d44 calls compare_and_swap_ptr with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x7d5c calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4616, a3=?.
  The `jal` at 0x7dc0 calls xthread_set_func with a0=[a0+64]:8, a1=sym(xthread_exit), a2=0x0, a3=[a0+64]:8.
  The `jal` at 0x7dc8 calls vsema with a0=a0+48, a1=?, a2=?, a3=?.
  The `jal` at 0x7de0 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4616, a3=[a0+64]:8.
  The `jal` at 0x7dec calls kmem_free with a0=a0 at entry (arg0), a1=0xa0, a2=?, a3=?.
  The `jal` at 0x7e38 calls nano_delay with a0=sp-96, a1=?, a2=?, a3=?.
  The `jal` at 0x7e6c calls cmn_err with a0=0x4, a1=sym(.rodata)+4616, a2=[a0+64]:8, a3=[a0+64]:8.
  The `beq` branch at 0x7cd8 targets 0x7e7c and is always taken.
  The `beq` branch at 0x7d0c targets 0x7d90, is taken when s2(?) >= 0x8 (unsigned), and falls through when s2(?) < 0x8 (unsigned).
  The `beq` branch at 0x7d1c targets 0x7cfc, is taken when (s6(=[a0+88]) & a3(?)) == 0, and falls through when (s6(=[a0+88]) & a3(?)) != 0.
  The `beq` branch at 0x7d34 targets 0x7d70, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x7d4c targets 0x7d64, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `bne` branch at 0x7d68 targets 0x7d40, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `bne` branch at 0x7d74 targets 0x7cfc, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `bne` branch at 0x7d80 targets 0x7ce0, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x7d88 targets 0x7d00 and is always taken.
  The `bne` branch at 0x7d98 targets 0x7dec, is taken when (t9(=[a0]) & 0x2) != 0, and falls through when (t9(=[a0]) & 0x2) == 0.
  The `beq` branch at 0x7da8 targets 0x7e24, is taken when (a1(=[a0+40]) & 0x400) == 0, and falls through when (a1(=[a0+40]) & 0x400) != 0.
  The `beq` branch at 0x7db0 targets 0x7e64, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x7e48 targets 0x7db0, is taken when (a1(=[a0+40]) & 0x400) != 0, and falls through when (a1(=[a0+40]) & 0x400) == 0.
  The `bne` branch at 0x7e54 targets 0x7e30, is taken when s0(?) < 0x3e8 (signed), and falls through when s0(?) >= 0x3e8 (signed).
  The `beq` branch at 0x7e5c targets 0x7db0 and is always taken.
  The `beq` branch at 0x7e74 targets 0x7dec and is always taken.
  The `beq` branch at 0x7e84 targets 0x7d18 and is always taken.
  The return at 0x7e1c has v0 = ret(kmem_free).

- `pcibr_setpciint` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x7e8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x7e8c-0x7f34 (168 bytes).
  It occupies 168 bytes.
  2 such `lw` accesses load 4 bytes from ret(xtalk_intr_sfarg_get) +0x0, including `lw` at 0x7ed0, `lw` at 0x7ee0.
  The `jal` at 0x7e98 calls xtalk_intr_addr_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7ea8 calls xtalk_intr_vector_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7eb8 calls xtalk_intr_dev_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7ec8 calls xtalk_intr_sfarg_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7ed8 calls xtalk_intr_sfarg_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7ef0 calls pcibr_bridge_ptr_get with a0=ret(xtalk_intr_dev_get), a1=?, a2=?, a3=?.
  The `jal` at 0x7f08 calls pcireg_intr_addr_vect_set with a0=ret(pcibr_bridge_ptr_get), a1=?, a2=?, a3=?.
  The `jal` at 0x7f1c calls pcireg_intr_addr_addr_set with a0=ret(pcibr_bridge_ptr_get), a1=?, a2=ret(xtalk_intr_addr_get), a3=?.
  The return at 0x7f2c has v0 = ret(pcireg_intr_addr_addr_set).

- `pcibr_intr_connect` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x7f34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x7f34-0x80d8 (420 bytes).
  It occupies 420 bytes.
  The `lw` at 0x7f3c loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x7f44 loads 8 bytes from a0 (arg0 at entry) +0x60.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x7f74, `lw` at 0x80b4.
  The `sd` at 0x7f98 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `lw` at 0x7f9c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0x7fa4 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sw` at 0x7fb0 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `lw` at 0x7fd8 loads 4 bytes from ?.
  The `ld` at 0x7fe0 loads 8 bytes from ?.
  The `lw` at 0x805c loads 4 bytes from [a0+96]:8 +0x48.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x8080, `sw` at 0x8094.
  The `jal` at 0x7f90 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4616, a3=a1 at entry (arg1), a4=a2 at entry (arg2).
  The `jal` at 0x7ff4 calls mutex_spinlock with a0=[a0+96]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0x8010 calls pcireg_intr_enable_bit_set with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x8018 calls pcireg_tflush_get with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x8024 calls mutex_io_spinunlock with a0=[a0+96]:8+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x8054 calls pcireg_intr_addr_addr with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x8084 calls xtalk_intr_connect with a0=?, a1=sym(pcibr_intr_func), a2=?, a3=sym(pcibr_setpciint), a5=0x0.
  The `jal` at 0x8098 calls pcireg_intr_addr_get with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x80b8 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4616, a3=ret(pcireg_intr_addr_addr), a4=ret(pcireg_intr_addr_get).
  The `bne` branch at 0x7f64 targets 0x7f74, is taken when a0 != 0, and falls through when a0 == 0.
  The `beq` branch at 0x7f6c targets 0x8038 and is always taken.
  The `beq` branch at 0x7fc4 targets 0x7fe4, is taken when (s2(=[a0+88]) & a5(?)) == 0, and falls through when (s2(=[a0+88]) & a5(?)) != 0.
  The `beq` branch at 0x7fdc targets 0x8050, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0x7fec targets 0x7fb4, is taken when s0(?) < 0x8 (unsigned), and falls through when s0(?) >= 0x8 (unsigned).
  The `bne` branch at 0x80c8 targets 0x7fb8, is taken when s0(?) < 0x8 (unsigned), and falls through when s0(?) >= 0x8 (unsigned).
  The `beq` branch at 0x80d0 targets 0x7ff4 and is always taken.
  The return at 0x8048 has v0 = one of -0x1, 0x0.

- `pcibr_intr_disconnect` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x80d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x80d8-0x82b4 (476 bytes).
  It occupies 476 bytes.
  The `sd` at 0x80d8 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0x80dc stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `ld` at 0x80e8 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `lw` at 0x80f0 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `lw` at 0x80fc loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sw` at 0x8114 stores 4 bytes to a0 (arg0 at entry) +0x0.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x8144, `lw` at 0x81e8, `lw` at 0x824c.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x81b4, `lw` at 0x8240, `lw` at 0x8290.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x822c, `ld` at 0x8264.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x823c, `sw` at 0x8278.
  The `lw` at 0x8258 loads 4 bytes from [a0+96]:8 +0x48.
  The `jal` at 0x8178 calls mutex_spinlock with a0=[a0+96]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0x818c calls pcireg_intr_enable_bit_clr with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x8194 calls pcireg_tflush_get with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x81a0 calls mutex_io_spinunlock with a0=[a0+96]:8+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x81b8 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4616, a3=?.
  The `jal` at 0x8228 calls xtalk_intr_disconnect with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x8244 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4616, a3=?.
  The `jal` at 0x827c calls xtalk_intr_connect with a0=?, a1=sym(pcibr_intr_func), a2=?, a3=sym(pcibr_setpciint), a5=0x0.
  The `jal` at 0x8294 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4616, a3=?.
  The `beq` branch at 0x8130 targets 0x8154, is taken when (a6(?) & s0(?)) == 0, and falls through when (a6(?) & s0(?)) != 0.
  The `beq` branch at 0x8148 targets 0x8158, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x815c targets 0x8120, is taken when v0(?) < 0x8 (unsigned), and falls through when v0(?) >= 0x8 (unsigned).
  The `beq` branch at 0x816c targets 0x8204, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x81d4 targets 0x81f4, is taken when (s0(?) & a2(?)) == 0, and falls through when (s0(?) & a2(?)) != 0.
  The `beq` branch at 0x81ec targets 0x8228, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x81fc targets 0x81c8, is taken when s1(?) < 0x8 (unsigned), and falls through when s1(?) >= 0x8 (unsigned).
  The `beq` branch at 0x8250 targets 0x829c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x82a4 targets 0x81c8, is taken when s1(?) < 0x8 (unsigned), and falls through when s1(?) >= 0x8 (unsigned).
  The `beq` branch at 0x82ac targets 0x8208 and is always taken.
  The return at 0x8220 has v0 = one of ?, ret(pcibr_debug).

- `pcibr_intr_cpu_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x82b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x82b4-0x832c (120 bytes).
  It occupies 120 bytes.
  The `lw` at 0x82b8 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x830c loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `ld` at 0x8320 loads 8 bytes from ?.
  The `jal` at 0x831c calls xtalk_intr_cpu_get with a0=?, a1=?, a2=?, a3=[a0+88], a4=0x1, a5=a0 at entry (arg0).
  The `bne` branch at 0x82d4 targets 0x8304, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0x82e8 targets 0x82d4, is taken when v0(?) < 0x8 (unsigned), and falls through when v0(?) >= 0x8 (unsigned).
  The `beq` branch at 0x8324 targets 0x82f4 and is always taken.
  The return at 0x82fc has v0 = one of 0x0, ret(xtalk_intr_cpu_get).

- `pcibr_setwidint` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x832c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x832c-0x83b0 (132 bytes).
  It occupies 132 bytes.
  The `jal` at 0x833c calls xtalk_intr_target_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x834c calls xtalk_intr_addr_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8358 calls xtalk_intr_vector_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8364 calls xtalk_intr_sfarg_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8374 calls pcireg_intr_dst_target_id_set with a0=ret(xtalk_intr_sfarg_get), a1=?, a2=?, a3=?.
  The `jal` at 0x8384 calls pcireg_intr_dst_addr_set with a0=ret(xtalk_intr_sfarg_get), a1=ret(xtalk_intr_addr_get), a2=?, a3=?.
  The `jal` at 0x8398 calls pcireg_intr_host_err_set with a0=ret(xtalk_intr_sfarg_get), a1=?, a2=?, a3=?.
  The return at 0x83a8 has v0 = ret(pcireg_intr_host_err_set).

- `pcibr_intr_func` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x83b0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x83b0-0x8600 (592 bytes).
  It occupies 592 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x83b0, `lw` at 0x8530.
  The `ld` at 0x83c8 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x83d0 loads 2 bytes from [a0]:8 +0x72.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0x83f0, `lw` at 0x8518, `lw` at 0x85ec.
  The `ld` at 0x842c loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x843c loads 8 bytes from [a0+16]:8 +0x8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1c, including `lw` at 0x8458, `lw` at 0x84c4.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x8464, `lbu` at 0x84d0.
  6 such `ld` accesses load 8 bytes from ?, including `ld` at 0x846c, `ld` at 0x8470, `ld` at 0x8478.
  The `lw` at 0x8498 loads 4 bytes from ?.
  The `ll` at 0x84e8 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `sc` at 0x84f4 stores 4 bytes to a0 (arg0 at entry) +0x18.
  The `lw` at 0x8594 loads 4 bytes from [a0]:8 +0x78.
  The `jal` at 0x8468 calls pcireg_wrb_flush_get with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0x8474 calls (unknown callee) with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x84d4 calls pcireg_wrb_flush_get with a0=?, a1=?, a2=a0+24, a3=?.
  The `jal` at 0x8500 calls pcibr_wrap_put with a0=a0 at entry (arg0), a1=?, a2=a0+24, a3=0x1, a4=[a0+24]+1.
  The `jal` at 0x8508 calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x8538 calls mutex_spinlock with a0=[a0]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0x8548 calls pcireg_intr_enable_bit_clr with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x8550 calls pcireg_tflush_get with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x855c calls mutex_io_spinunlock with a0=[a0]:8+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x85b4 calls mutex_spinlock with a0=[a0]:8+128, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x85c8 calls pcireg_intr_enable_bit_clr with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x85d4 calls pcireg_intr_enable_bit_set with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x85e0 calls mutex_io_spinunlock with a0=[a0]:8+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x85f0 calls pcibr_force_interrupt with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=[a0+24].
  The `beq` branch at 0x83e8 targets 0x8594, is taken when at(=[[a0]:8+114]:2) == v1(=0x2), and falls through when at(=[[a0]:8+114]:2) != v1(=0x2).
  The `bne` branch at 0x8408 targets 0x8564, is taken when a0(=[a0+24]) != 0, and falls through when a0(=[a0+24]) == 0.
  The `beq` branch at 0x8414 targets 0x842c and is always taken.
  The `beq` branch at 0x841c targets 0x8518, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x8424 targets 0x8524, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x8430 targets 0x841c, is taken when s0(=[a0+16]:8) == 0, and falls through when s0(=[a0+16]:8) != 0.
  The `beq` branch at 0x8438 targets 0x8490 and is always taken.
  The `bne` branch at 0x8440 targets 0x84bc, is taken when s3(=one of 0x0, 0x1) != 0, and falls through when s3(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x8448 targets 0x8480, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x8450 targets 0x8480, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x845c targets 0x8470, is taken when a1(=[a0+28]) == 0, and falls through when a1(=[a0+28]) != 0.
  The `beq` branch at 0x8484 targets 0x841c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x8490 targets 0x8480, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x84a4 targets 0x8480, is taken when (v0(?) & 0x1) == 0, and falls through when (v0(?) & 0x1) != 0.
  The `bne` branch at 0x84ac targets 0x8440, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x84b4 targets 0x8448, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x84bc targets 0x8448, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x84c8 targets 0x84e0, is taken when v1(=[a0+28]) == 0, and falls through when v1(=[a0+28]) != 0.
  The `beql` branch at 0x84f8 targets 0x84e8, is taken when a4(=[a0+24]+1) == 0, and falls through when a4(=[a0+24]+1) != 0; its branch-likely delay slot `nop` at 0x84fc runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x8510 targets 0x8480 and is always taken.
  The `beq` branch at 0x851c targets 0x85f0, is taken when a5(=[a0+24]) == 0, and falls through when a5(=[a0+24]) != 0.
  The `beq` branch at 0x8524 targets 0x8568, is taken when s6(=one of 0x0, 0x1) == 0, and falls through when s6(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x85a4 targets 0x83f0, is taken when (t8(?) & 0x2) == 0, and falls through when (t8(?) & 0x2) != 0.
  The `beq` branch at 0x85e8 targets 0x83f4 and is always taken.
  The `beq` branch at 0x85f8 targets 0x8524 and is always taken.
  The return at 0x858c has v0 = ?.

- `pcibr_show_dir_state` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x8600 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x8600-0x865c (92 bytes).
  It occupies 92 bytes.
  The `ld` at 0x8648 loads 8 bytes from table(sym(dir_state_str)) +0x0.
  The `jal` at 0x861c calls get_dir_ent with a0=a0 at entry (arg0), a1=sp-48, a2=sp-40, a3=sp-32.
  The `jal` at 0x8644 calls printf with a0=sym(.rodata)+6152, a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=?, a5=entry(sym(dir_state_str)).
  The return at 0x8654 has v0 = ret(printf).

- `print_bridge_errcmd` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x865c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x865c-0x8690 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x867c calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=a1 at entry (arg1), a3=a0 at entry (arg0), a4=sym(.data)+16.
  The return at 0x8688 has v0 = ret(cmn_err).

- `pcibr_error_dump` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x8690
  **Inferred.** Role (from name): the bridge error-interrupt handler. It calls `pcireg_intr_status_get` at 0x86a0, then `test_and_set_long` at 0x86c4 on a0+2112 (0x840) when the status ANDed with -0x100 is nonzero (the `beq` at 0x86b8 goes to 0x86d0 when it is zero). The routine compares values with 0x80000000, 0x10000, 0x100 and 0x800000 (the branches at 0x878c to 0x879c and 0x8820) and an unresolved value with 0x40 (the `beq` at 0x8760). It makes many `pcireg_*` getter calls (for example `pcireg_intr_multiple_get` at 0x889c) and `cmn_err` calls at 0x8718, 0x88e0 and further sites; the facts do not tie each getter to one status bit. The return at 0x86e4 is one of the `test_and_set_long` result, an unresolved value, `ret(pcireg_intr_multiple_get)` and `ret(cmn_err)`.
  Reviewed: 2026-11-12

- `pcibr_errintr_group` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x973c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x973c-0x97c0 (132 bytes).
  It occupies 132 bytes.
  The `beq` branch at 0x9758 targets 0x9768, is taken when (a0 & a1(=0x40010000)) == 0, and falls through when (a0 & a1(=0x40010000)) != 0.
  The `beq` branch at 0x9780 targets 0x978c, is taken when (a3(=a0) & v1(=0x3e0000)) == 0, and falls through when (a3(=a0) & v1(=0x3e0000)) != 0.
  The `beq` branch at 0x978c targets 0x9798, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x97a0 targets 0x97ac, is taken when (a3(=a0) & a0(=0x14000200)) == 0, and falls through when (a3(=a0) & a0(=0x14000200)) != 0.
  The `beq` branch at 0x97ac targets 0x97b8, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0x97b8 has v0 = ?.

- `pcibr_pioerr_check` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x97c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x97c0-0x9928 (360 bytes).
  It occupies 360 bytes.
  The `lbu` at 0x97ec loads 1 byte from a0 (arg0 at entry) +0x39.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x9820, `lw` at 0x984c.
  11 such `ld` accesses load 8 bytes from ?, including `ld` at 0x9834, `ld` at 0x9840, `ld` at 0x9858.
  The `ll` at 0x98ac loads 4 bytes from ?.
  The `sc` at 0x98b8 stores 4 bytes to ?.
  The `jal` at 0x97cc calls pcireg_intr_status_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x97e4 calls pcireg_pci_bus_addr_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x97dc targets 0x9914, is taken when (v0(=ret(pcireg_intr_status_get)) & at(=0x4400008800)) == 0, and falls through when (v0(=ret(pcireg_intr_status_get)) & at(=0x4400008800)) != 0.
  The `blez` branch at 0x97fc targets 0x9914, is taken when at(?) <= 0 (signed), and falls through when at(?) > 0 (signed).
  The `beq` branch at 0x9804 targets 0x9810 and is always taken.
  The `blez` branch at 0x980c targets 0x9914, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `blez` branch at 0x9830 targets 0x980c, is taken when t8(?) <= 0 (signed), and falls through when t8(?) > 0 (signed).
  The `beq` branch at 0x9838 targets 0x98d8 and is always taken.
  The `beq` branch at 0x9844 targets 0x98d0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x985c targets 0x9900, is taken when a6(?) >= 0x6 (unsigned), and falls through when a6(?) < 0x6 (unsigned).
  The `bne` branch at 0x988c targets 0x9840, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x98a0 targets 0x9840, is taken when v0(=ret(pcireg_pci_bus_addr_get)) >= a2(?) (unsigned), and falls through when v0(=ret(pcireg_pci_bus_addr_get)) < a2(?) (unsigned).
  The `beql` branch at 0x98bc targets 0x98ac, is taken when at(?) == 0, and falls through when at(?) != 0; its branch-likely delay slot `nop` at 0x98c0 runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x98c8 targets 0x984c, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x98d0 targets 0x980c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x98e4 targets 0x98d0, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `bne` branch at 0x98f0 targets 0x984c, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x98f8 targets 0x98d0 and is always taken.
  The `bne` branch at 0x9900 targets 0x988c, is taken when a5(?) != t3(=0x1), and falls through when a5(?) == t3(=0x1).
  The `beq` branch at 0x990c targets 0x9888 and is always taken.
  The return at 0x9920 has v0 = one of ret(pcireg_intr_status_get), ret(pcireg_pci_bus_addr_get).

- `pcibr_error_intr_handler` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x9928 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x9928-0x9ea8 (1408 bytes).
  It occupies 1408 bytes.
  The `lw` at 0x994c loads 4 bytes from a0 (arg0 at entry) +0x0.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x999c, `lw` at 0x9aec, `lw` at 0x9bf4.
  8 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0x99f4, `lh` at 0x9a88, `lh` at 0x9b98.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x9a2c, `lw` at 0x9a30, `lw` at 0x9a34.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0x9a3c, `sw` at 0x9ad8, `sw` at 0x9ae0.
  The `lw` at 0x9a40 loads 4 bytes from a0 (arg0 at entry) +0x48.
  5 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x9d38, `ld` at 0x9d58, `ld` at 0x9d8c.
  The `lw` at 0x9d50 loads 4 bytes from a0 (arg0 at entry) +0x4.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x9d80, `ld` at 0x9df4, `ld` at 0x9e2c.
  The `jal` at 0x993c calls pcireg_intr_status_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x995c calls pcibr_debug with a0=0x100, a1=[a0], a2=sym(.rodata)+6152, a3=ret(pcireg_intr_status_get).
  The `jal` at 0x9988 calls pcibr_pioerr_check [0x97c0] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9b24 calls mutex_spinlock with a0=a0+128, a1=0x1, a2=?, a3=sym(.data)+16.
  The `jal` at 0x9b34 calls pcireg_intr_enable_bit_clr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9b40 calls mutex_io_spinunlock with a0=a0+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x9b58 calls pcireg_bus_err_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9bcc calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=(ret(pcireg_intr_status_get) | 0x40), a2=?, a3=?, a6=0x1.
  The `jal` at 0x9c10 calls pcireg_arbitration_bit_set with a0=a0 at entry (arg0), a1=0xf00000, a2=[a0+114]:2, a3=0x2.
  The `jal` at 0x9c30 calls test_and_set_long with a0=a0+2112, a1=0x0, a2=?, a3=?.
  The `jal` at 0x9c68 calls pcibr_errintr_group with a0=(ret(pcireg_intr_status_get) << 0x0), a1=?, a2=?, a3=?, a6=0x1.
  The `jal` at 0x9c78 calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9cd8 calls pcireg_cmdword_err_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9d3c calls cmn_err with a0=0x4, a1=sym(.rodata)+6152, a2=[sym(rev_b_datacorr_warning)]:8, a3=[a0+16]:8, a4=[sym(rev_b_datacorr_mesg)]:8, a5=[sym(rev_b_datacorr_warning)]:8.
  The `jal` at 0x9d4c calls ql_bridge_rev_b_war with a0=[a0+4], a1=?, a2=[sym(bridge_rev_b_data_check_disable)], a3=?, a5=[sym(rev_b_datacorr_warning)]:8.
  The `jal` at 0x9d64 calls panic with a0=sym(.rodata)+6152, a1=[sym(rev_b_datacorr_warning)]:8, a2=[a0+16]:8, a3=[sym(rev_b_datacorr_mesg)]:8, a4=[sym(rev_b_datacorr_warning)]:8.
  The `jal` at 0x9d90 calls cmn_err with a0=0x5, a1=sym(.rodata)+6152, a2=[a0+16]:8, a3=?.
  The `jal` at 0x9dc0 calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=?, a3=?.
  The `jal` at 0x9dc8 calls pcibr_error_dump with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9dd8 calls machine_error_dump with a0=sym(.rodata)+6152, a1=?, a2=?, a3=?.
  The `jal` at 0x9de0 calls panic with a0=sym(.rodata)+6152, a1=?, a2=?, a3=?.
  The `jal` at 0x9e04 calls cmn_err with a0=0x5, a1=sym(.rodata)+6152, a2=[a0+16]:8, a3=?.
  The `jal` at 0x9e40 calls cmn_err with a0=0x4, a1=sym(.rodata)+6152, a2=[a0+16]:8, a3=?.
  The `jal` at 0x9e68 calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=?, a3=?, a4=[a0+114]:2, a5=0x22133fc06000.
  The `jal` at 0x9e70 calls pcibr_error_dump with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9e7c calls machine_error_dump with a0=sym(.rodata)+6152, a1=?, a2=?, a3=?.
  The `jal` at 0x9e84 calls panic with a0=sym(.rodata)+6152, a1=?, a2=?, a3=?.
  The `beq` branch at 0x9970 targets 0x9c38, is taken when (s0(=ret(pcireg_intr_status_get)) & t8(=-0x100)) == 0, and falls through when (s0(=ret(pcireg_intr_status_get)) & t8(=-0x100)) != 0.
  The `beq` branch at 0x9980 targets 0x9990, is taken when (t9(=0x4400008800) & s0(=ret(pcireg_intr_status_get))) == 0, and falls through when (t9(=0x4400008800) & s0(=ret(pcireg_intr_status_get))) != 0.
  The `bne` branch at 0x99b0 targets 0x99c4, is taken when ra(=[a0+120]) != at(=0xc0022), and falls through when ra(=[a0+120]) == at(=0xc0022).
  The `bltz` branch at 0x99bc targets 0x9d24, is taken when v0(=(ret(pcireg_intr_status_get) << 0x2b)) < 0 (signed), and falls through when v0(=(ret(pcireg_intr_status_get) << 0x2b)) >= 0 (signed).
  The `beq` branch at 0x99c4 targets 0x9d18, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `beq` branch at 0x99ec targets 0x9e94 and is always taken.
  The `beq` branch at 0x99f8 targets 0x9ae4, is taken when t3(=[a0+114]:2) == t1(=0x2), and falls through when t3(=[a0+114]:2) != t1(=0x2).
  The `beq` branch at 0x9a14 targets 0x9b14, is taken when s0(?) >= 0x40 (signed), and falls through when s0(?) < 0x40 (signed).
  The `beq` branch at 0x9a24 targets 0x9a00, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x9a50 targets 0x9a98, is taken when t8(=[a0+72]) == 0, and falls through when t8(=[a0+72]) != 0.
  The `beq` branch at 0x9a58 targets 0x99f4, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x9a7c targets 0x99f4, is taken when s1(?) < 0x65 (unsigned), and falls through when s1(?) >= 0x65 (unsigned).
  The `bnel` branch at 0x9a84 targets 0x99f8, is taken when a0(?) != 0, and falls through when a0(?) == 0; its branch-likely delay slot `lh t3,114(s3)` at 0x9a88 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x9a90 targets 0x9d7c and is always taken.
  The `beq` branch at 0x9a98 targets 0x9c54, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x9aa8 targets 0x9a74, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x9ab4 targets 0x9a78, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x9abc targets 0x9a74, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `bne` branch at 0x9ad0 targets 0x9e2c, is taken when t8(=[sym(.sbss)]) < a4(?) (unsigned), and falls through when t8(=[sym(.sbss)]) >= a4(?) (unsigned).
  The `beq` branch at 0x9adc targets 0x9a78 and is always taken.
  The `bne` branch at 0x9ae4 targets 0x9a00, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0x9afc targets 0x9a00, is taken when (t9(?) & 0x2) == 0, and falls through when (t9(?) & 0x2) != 0.
  The `bnel` branch at 0x9b04 targets 0x9a04, is taken when a0(?) != 0, and falls through when a0(?) == 0; its branch-likely delay slot `addiu s0,s0,1` at 0x9b08 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x9b0c targets 0x9df0 and is always taken.
  The `beq` branch at 0x9b18 targets 0x9b50, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `bgez` branch at 0x9b50 targets 0x9b74, is taken when at(?) >= 0 (signed), and falls through when at(?) < 0 (signed).
  The `beq` branch at 0x9b6c targets 0x9cd8, is taken when v0(?) == v1(=0xc00000), and falls through when v0(?) != v1(=0xc00000).
  The `beq` branch at 0x9b78 targets 0x9c88, is taken when a1(=[sym(pcibr_pioerr_dump)]) == 0, and falls through when a1(=[sym(pcibr_pioerr_dump)]) != 0.
  The `bne` branch at 0x9b90 targets 0x9dbc, is taken when (s6(?) & a0(?)) != 0, and falls through when (s6(?) & a0(?)) == 0.
  The `beq` branch at 0x9b9c targets 0x9c98, is taken when a4(=[a0+114]:2) == t1(=0x2), and falls through when a4(=[a0+114]:2) != t1(=0x2).
  The `bne` branch at 0x9ba8 targets 0x9dd8, is taken when (s6(?) & a5(=0x22133fc06000)) != 0, and falls through when (s6(?) & a5(=0x22133fc06000)) == 0.
  The `beq` branch at 0x9bb4 targets 0x9c64, is taken when a0(=[a0+114]:2) == 0, and falls through when a0(=[a0+114]:2) != 0.
  The `beq` branch at 0x9bbc targets 0x9c68, is taken when a0(=[a0+114]:2) == a6(=0x1), and falls through when a0(=[a0+114]:2) != a6(=0x1).
  The `bne` branch at 0x9bdc targets 0x9c18, is taken when a2(=[a0+114]:2) != a3(=0x2), and falls through when a2(=[a0+114]:2) == a3(=0x2).
  The `beq` branch at 0x9bec targets 0x9c1c, is taken when (s6(?) & a4(=0x10000000000)) == 0, and falls through when (s6(?) & a4(=0x10000000000)) != 0.
  The `beq` branch at 0x9c08 targets 0x9c18, is taken when (a5(?) & 0x2) == 0, and falls through when (a5(?) & 0x2) != 0.
  The `bne` branch at 0x9c54 targets 0x9cc8, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0x9c5c targets 0x99f8 and is always taken.
  The `beq` branch at 0x9c80 targets 0x9bd4 and is always taken.
  The `beq` branch at 0x9c90 targets 0x9b8c and is always taken.
  The `beq` branch at 0x9cb0 targets 0x9ba0, is taken when (a1(?) & 0x6) == 0, and falls through when (a1(?) & 0x6) != 0.
  The `beq` branch at 0x9cb8 targets 0x9ba4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x9cc0 targets 0x9e64 and is always taken.
  The `beq` branch at 0x9cc8 targets 0x9d0c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x9cd0 targets 0x99f8 and is always taken.
  The `bne` branch at 0x9cfc targets 0x9b74, is taken when a1(?) != a2(=0x402000), and falls through when a1(?) == a2(=0x402000).
  The `beq` branch at 0x9d04 targets 0x9b74 and is always taken.
  The `beq` branch at 0x9d10 targets 0x99f4 and is always taken.
  The `beq` branch at 0x9d1c targets 0x9b50 and is always taken.
  The `beq` branch at 0x9d24 targets 0x9d4c, is taken when a2(=[sym(bridge_rev_b_data_check_disable)]) == 0, and falls through when a2(=[sym(bridge_rev_b_data_check_disable)]) != 0.
  The `beq` branch at 0x9d44 targets 0x9d6c and is always taken.
  The `beq` branch at 0x9d74 targets 0x99c4 and is always taken.
  The `beq` branch at 0x9db4 targets 0x99f4 and is always taken.
  The `beq` branch at 0x9dd0 targets 0x9b98 and is always taken.
  The `beq` branch at 0x9de8 targets 0x9bb4 and is always taken.
  The `beq` branch at 0x9e24 targets 0x9a00 and is always taken.
  The `beq` branch at 0x9e5c targets 0x9ad8 and is always taken.
  The `beq` branch at 0x9e8c targets 0x9ba4 and is always taken.
  The `beq` branch at 0x9ea0 targets 0x9a20 and is always taken.
  The return at 0x9c4c has v0 = one of ret(pcibr_debug), ret(test_and_set_long).

- `pcibr_addr_toslot` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x9ea8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0x9ea8-0xa18c (740 bytes).
  It occupies 740 bytes.
  The `lbu` at 0x9ee4 loads 1 byte from a0 (arg0 at entry) +0x38.
  The `lbu` at 0x9ee8 loads 1 byte from a0 (arg0 at entry) +0x39.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x9f0c, `lw` at 0x9f64, `lw` at 0xa064.
  13 such `ld` accesses load 8 bytes from ?, including `ld` at 0x9f1c, `ld` at 0x9f34, `ld` at 0x9f70.
  4 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x9fa0, `sw` at 0xa020, `sw` at 0xa0e8.
  2 such `sb` accesses store 1 byte to a4 (arg4 at entry) +0x0, including `sb` at 0x9fac, `sb` at 0xa02c.
  4 such `sd` accesses store 8 bytes to a3 (arg3 at entry) +0x0, including `sd` at 0x9fc4, `sd` at 0xa004, `sd` at 0xa104.
  The `bne` branch at 0x9eb0 targets 0x9ee4, is taken when a1 < v0(=0x20000) (unsigned), and falls through when a1 >= v0(=0x20000) (unsigned).
  The `beq` branch at 0x9ec0 targets 0x9ee4, is taken when a1 >= v1(=0x30000) (unsigned), and falls through when a1 < v1(=0x30000) (unsigned).
  The `bne` branch at 0x9ed0 targets 0x9fd0, is taken when a1 < a0(=0x28000) (unsigned), and falls through when a1 >= a0(=0x28000) (unsigned).
  The `beq` branch at 0x9edc targets 0x9fd8 and is always taken.
  The `bne` branch at 0x9efc targets 0xa050, is taken when a6(=[a0+57]:1) < v0(=[a0+56]:1) (signed), and falls through when a6(=[a0+57]:1) >= v0(=[a0+56]:1) (signed).
  The `blez` branch at 0x9f10 targets 0xa038, is taken when t9(?) <= 0 (signed), and falls through when t9(?) > 0 (signed).
  The `beq` branch at 0x9f18 targets 0xa17c and is always taken.
  The `beq` branch at 0x9f2c targets 0xa038, is taken when t3(?) >= t9(?) (signed), and falls through when t3(?) < t9(?) (signed).
  The `beq` branch at 0x9f38 targets 0x9f20, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x9f40 targets 0xa170 and is always taken.
  The `beq` branch at 0x9f54 targets 0x9f20, is taken when a7(?) >= 0x6 (signed), and falls through when a7(?) < 0x6 (signed).
  The `beq` branch at 0x9f68 targets 0x9f48, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `bne` branch at 0x9f78 targets 0x9f48, is taken when a1 < t1(?) (unsigned), and falls through when a1 >= t1(?) (unsigned).
  The `beql` branch at 0x9f8c targets 0x9f4c, is taken when a1 >= v1(?) (unsigned), and falls through when a1 < v1(?) (unsigned); its branch-likely delay slot `addiu a7,a7,1` at 0x9f90 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x9f94 targets 0x9fb8, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x9f9c targets 0x9fbc, is taken when a3 != 0, and falls through when a3 == 0.
  The `beq` branch at 0x9fa4 targets 0x9fb0, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0x9fb8 targets 0x9fa4, is taken when a3 == 0, and falls through when a3 != 0.
  The `bne` branch at 0x9fc0 targets 0x9fac, is taken when a4 != 0, and falls through when a4 == 0.
  The `beq` branch at 0x9fc8 targets 0x9fb0 and is always taken.
  The `beq` branch at 0x9fe0 targets 0xa010, is taken when a4 == 0, and falls through when a4 != 0.
  The `bne` branch at 0x9ff0 targets 0xa018, is taken when a2 != 0, and falls through when a2 == 0.
  The `beq` branch at 0x9ff8 targets 0xa024, is taken when a3 == 0, and falls through when a3 != 0.
  The `bne` branch at 0xa000 targets 0xa02c, is taken when a4 != 0, and falls through when a4 == 0.
  The `beq` branch at 0xa008 targets 0x9fb0 and is always taken.
  The `beq` branch at 0xa010 targets 0x9ff8, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa01c targets 0xa000, is taken when a3 != 0, and falls through when a3 == 0.
  The `beq` branch at 0xa024 targets 0x9fb0, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0xa030 targets 0x9fb0 and is always taken.
  The `beq` branch at 0xa048 targets 0x9f0c, is taken when t9(=[a0+57]:1) >= v0(?) (signed), and falls through when t9(=[a0+57]:1) < v0(?) (signed).
  The `beq` branch at 0xa054 targets 0xa128, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `blez` branch at 0xa068 targets 0xa110, is taken when t1(?) <= 0 (signed), and falls through when t1(?) > 0 (signed).
  The `beq` branch at 0xa070 targets 0xa07c and is always taken.
  The `beq` branch at 0xa078 targets 0xa110, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xa08c targets 0xa078, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xa098 targets 0xa078, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa0a0 targets 0xa0b8 and is always taken.
  The `beq` branch at 0xa0ac targets 0xa078, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0xa0bc targets 0xa0a8, is taken when a1 < a7(?) (unsigned), and falls through when a1 >= a7(?) (unsigned).
  The `beq` branch at 0xa0d0 targets 0xa0a8, is taken when a1 >= t9(?) (unsigned), and falls through when a1 < t9(?) (unsigned).
  The `beq` branch at 0xa0d8 targets 0xa0f4, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa0e4 targets 0xa0fc, is taken when a3 != 0, and falls through when a3 == 0.
  The `beq` branch at 0xa0ec targets 0x9fb0 and is always taken.
  The `beq` branch at 0xa0f4 targets 0x9fb0, is taken when a3 == 0, and falls through when a3 != 0.
  The `beq` branch at 0xa108 targets 0x9fb0 and is always taken.
  The `beq` branch at 0xa120 targets 0xa064, is taken when a4(=[a0+57]:1) >= v0(?) (signed), and falls through when a4(=[a0+57]:1) < v0(?) (signed).
  The `beq` branch at 0xa128 targets 0xa15c, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xa134 targets 0xa144, is taken when a1 >= a5(=0x40000000) (unsigned), and falls through when a1 < a5(=0x40000000) (unsigned).
  The `beq` branch at 0xa13c targets 0xa158 and is always taken.
  The `beq` branch at 0xa15c targets 0xa168, is taken when a3 == 0, and falls through when a3 != 0.
  The `beq` branch at 0xa168 targets 0x9fb0 and is always taken.
  The `beq` branch at 0xa174 targets 0x9f60 and is always taken.
  The `beq` branch at 0xa184 targets 0x9f38 and is always taken.
  The return at 0x9fb0 has v0 = one of ?, 0xff.

- `pcibr_error_cleanup` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xa18c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xa18c-0xa1e0 (84 bytes).
  It occupies 84 bytes.
  The `lh` at 0xa18c loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `jal` at 0xa1b4 calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=one of 0x41, 0x3cff00000041, a2=a2 at entry (arg2), a3=0x1, a4=[a0+114]:2.
  The `jal` at 0xa1bc calls pcireg_tflush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa1a4 targets 0xa1b4, is taken when a4(=[a0+114]:2) == 0, and falls through when a4(=[a0+114]:2) != 0.
  The `beq` branch at 0xa1ac targets 0xa1d4, is taken when a4(=[a0+114]:2) == a3(=0x1), and falls through when a4(=[a0+114]:2) != a3(=0x1).
  The `beq` branch at 0xa1d8 targets 0xa1b4 and is always taken.
  The return at 0xa1cc has v0 = ret(pcireg_tflush_get).

- `pcibr_error_extract` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xa1e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xa1e0-0xa258 (120 bytes).
  It occupies 120 bytes.
  The `jal` at 0xa1fc calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+6152, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0xa218 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa22c calls pcireg_pci_bus_addr_get with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?, a5=0xff.
  The `jal` at 0xa244 calls pcibr_addr_toslot with a0=?, a1=ret(pcireg_pci_bus_addr_get), a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `beq` branch at 0xa204 targets 0xa218, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0xa224 targets 0xa250, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xa250 targets 0xa20c and is always taken.
  The return at 0xa210 has v0 = one of 0xff, ?.

- `pcibr_device_disable` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xa258 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xa258-0xa260 (8 bytes).
  It occupies 8 bytes.
  The return at 0xa258 has v0 = ?.

- `pcibr_pioerror` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xa260 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xa260-0xafac (3404 bytes).
  It occupies 3404 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0xa278, `lw` at 0xa748.
  The `lw` at 0xa280 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `ld` at 0xa29c loads 8 bytes from a3 (arg3 at entry) +0x18.
  4 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0xa2d0, `lh` at 0xa76c, `lh` at 0xa824.
  The `lw` at 0xa2d8 loads 4 bytes from a0 (arg0 at entry) +0x48.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa420, `lw` at 0xa604, `lw` at 0xa6ac.
  21 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa42c, `ld` at 0xa610, `ld` at 0xa644.
  12 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x39, including `lbu` at 0xa4b0, `lbu` at 0xa534, `lbu` at 0xa580.
  10 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x38, including `lbu` at 0xa4b4, `lbu` at 0xa53c, `lbu` at 0xa584.
  The `ll` at 0xa65c loads 4 bytes from ?.
  The `sc` at 0xa668 stores 4 bytes to ?.
  5 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0xa768, `lw` at 0xa808, `lw` at 0xad64.
  3 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0xa790, `sw` at 0xa7bc, `sw` at 0xa970.
  2 such `sh` accesses store 2 bytes to a3 (arg3 at entry) +0x8, including `sh` at 0xa7a0, `sh` at 0xa980.
  The `sd` at 0xa7a4 stores 8 bytes to a3 (arg3 at entry) +0x28.
  The `sd` at 0xa7ac stores 8 bytes to a3 (arg3 at entry) +0x20.
  5 such `lh` accesses load 2 bytes from a3 (arg3 at entry) +0x8, including `lh` at 0xa804, `lh` at 0xadec, `lh` at 0xae98.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0xad38, `ld` at 0xad58.
  The `lw` at 0xaeac loads 4 bytes from a3 (arg3 at entry) +0x24.
  4 such `ld` accesses load 8 bytes from a3 (arg3 at entry) +0x28, including `ld` at 0xaf00, `ld` at 0xaf38, `ld` at 0xaf60.
  The `lw` at 0xafa8 loads 4 bytes from (a0 + ([a0+56]:1 << 0x7)) +0x110.
  The `jal` at 0xa2b4 calls pcibr_debug with a0=0x200, a1=[a0], a2=sym(.rodata)+6152, a3=a0 at entry (arg0), a4=[a3+24]:8.
  The `jal` at 0xa74c calls pcibr_debug with a0=0x200, a1=[a0], a2=sym(.rodata)+6152, a3=?.
  The `jal` at 0xa7dc calls pciio_error_handler with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xab24 calls pcibr_error_cleanup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xab44 calls pciio_error_handler with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xab58 calls pcibr_device_disable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=([a3] << 0x2).
  The `jal` at 0xab68 calls pcibr_error_cleanup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xad44 calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=[a0+16]:8, a3=[a3+24]:8.
  The `jal` at 0xad5c calls cmn_err with a0=0x1, a1=sym(.rodata)+6152, a2=[a0+16]:8, a3=?.
  The `jal` at 0xad84 calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=sym(.rodata)+6152, a3=?.
  The `jal` at 0xad8c calls pcireg_intr_status_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xada4 calls pcibr_error_dump with a0=a0 at entry (arg0), a1=sym(.rodata)+6152, a2=?, a3=?.
  The `jal` at 0xadc8 calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=sym(.rodata)+6152, a3=?.
  The `jal` at 0xade0 calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=sym(.rodata)+6152, a3=?.
  The `jal` at 0xae34 calls pcireg_device_get with a0=a0 at entry (arg0), a1=?, a2=[a3+8]:2, a3=?, a4=([a3] << 0x2).
  The `jal` at 0xae50 calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=sym(.rodata)+6152, a3=?.
  The `jal` at 0xae6c calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=sym(.rodata)+6152, a3=?.
  The `jal` at 0xae8c calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=sym(.rodata)+6152, a3=ret(pcireg_device_get), a4=sym(.data)+16.
  The `jal` at 0xaf04 calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=?, a3=?, a4=[a3+36]-8, a5=[a3+40]:8, a6=0x4, a7=0x5.
  The `jal` at 0xaf3c calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=[a3+40]:8, a3=?, a5=0x7, a6=0x4, a7=0x5.
  The `jal` at 0xaf64 calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=?, a3=?, a4=[a3+40]:8, a5=0x7.
  The `jal` at 0xaf80 calls cmn_err with a0=0x6, a1=sym(.rodata)+6152, a2=[a3+40]:8, a3=?, a5=0x7, a6=0x4.
  The `beq` branch at 0xa2e8 targets 0xa8bc, is taken when t1(=[a0+114]:2) == a6(=0x2), and falls through when t1(=[a0+114]:2) != a6(=0x2).
  The `bne` branch at 0xa318 targets 0xa364, is taken when s2(=[a3+24]:8) < t3(=one of 0x20000, 0x21000, 0x820000, 0x821000) (unsigned), and falls through when s2(=[a3+24]:8) >= t3(=one of 0x20000, 0x21000, 0x820000, 0x821000) (unsigned).
  The `beq` branch at 0xa320 targets 0xa34c, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0xa328 targets 0xab78, is taken when t1(=[a0+114]:2) == a6(=0x2), and falls through when t1(=[a0+114]:2) != a6(=0x2).
  The `beq` branch at 0xa344 targets 0xa354 and is always taken.
  The `bne` branch at 0xa354 targets 0xa37c, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `beq` branch at 0xa35c targets 0xa3a4 and is always taken.
  The `bne` branch at 0xa364 targets 0xa984, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0xa390 targets 0xa3a4, is taken when s2(=[a3+24]:8) >= a2(=one of 0x29000, 0x829000) (unsigned), and falls through when s2(=[a3+24]:8) < a2(=one of 0x29000, 0x829000) (unsigned).
  The `bne` branch at 0xa3b0 targets 0xa434, is taken when s2(=[a3+24]:8) < t3(=one of 0x200000, 0xa00000) (unsigned), and falls through when s2(=[a3+24]:8) >= t3(=one of 0x200000, 0xa00000) (unsigned).
  The `beq` branch at 0xa3c4 targets 0xa434, is taken when s2(=[a3+24]:8) >= t2(=one of 0xc00000, 0x1400000) (unsigned), and falls through when s2(=[a3+24]:8) < t2(=one of 0xc00000, 0x1400000) (unsigned).
  The `beq` branch at 0xa3e8 targets 0xa990, is taken when v0(?) == ra(=0x1), and falls through when v0(?) != ra(=0x1).
  The `beq` branch at 0xa3f4 targets 0xa990, is taken when v0(?) == v1(=0x3), and falls through when v0(?) != v1(=0x3).
  The `blez` branch at 0xa3fc targets 0xa40c, is taken when t8(?) <= 0 (signed), and falls through when t8(?) > 0 (signed).
  The `bne` branch at 0xa40c targets 0xa41c, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0xa424 targets 0xab88, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa434 targets 0xa8d4, is taken when t1(=[a0+114]:2) == a6(=0x2), and falls through when t1(=[a0+114]:2) != a6(=0x2).
  The `bne` branch at 0xa440 targets 0xa4d4, is taken when s2(=[a3+24]:8) < t8(=0x40000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t8(=0x40000000) (unsigned).
  The `bne` branch at 0xa454 targets 0xa4d4, is taken when t9(=0x7fffffff) < s2(=[a3+24]:8) (unsigned), and falls through when t9(=0x7fffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa470 targets 0xa484, is taken when s2(=[a3+24]:8) < ra(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= ra(=0x80000000) (unsigned).
  The `beq` branch at 0xa480 targets 0xa4f4, is taken when at(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when at(=0xbfffffff) < s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa490 targets 0xa4a8, is taken when s2(=[a3+24]:8) < v0(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= v0(=0x100000000) (unsigned).
  The `beq` branch at 0xa4a0 targets 0xa570, is taken when v1(=0x1ffffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when v1(=0x1ffffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa4a8 targets 0xac44, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa4c8 targets 0xa5c0 and is always taken.
  The `bne` branch at 0xa4dc targets 0xa550, is taken when s2(=[a3+24]:8) < a4(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= a4(=0x80000000) (unsigned).
  The `bne` branch at 0xa4ec targets 0xa550, is taken when a7(=0xbfffffff) < s2(=[a3+24]:8) (unsigned), and falls through when a7(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa508 targets 0xa524, is taken when s2(=[a3+24]:8) < t0(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t0(=0x100000000) (unsigned).
  The `beq` branch at 0xa51c targets 0xa570, is taken when t1(=0x1ffffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when t1(=0x1ffffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa524 targets 0xabc4, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa544 targets 0xa5c0 and is always taken.
  The `bne` branch at 0xa558 targets 0xa5a0, is taken when s2(=[a3+24]:8) < t3(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t3(=0x100000000) (unsigned).
  The `bne` branch at 0xa568 targets 0xa5a0, is taken when t8(=0x1ffffffff) < s2(=[a3+24]:8) (unsigned), and falls through when t8(=0x1ffffffff) >= s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa578 targets 0xaba8, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa598 targets 0xa5c0 and is always taken.
  The `beq` branch at 0xa5a4 targets 0xa99c, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `bne` branch at 0xa5c8 targets 0xa71c, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0xa5dc targets 0xaf9c and is always taken.
  The `bne` branch at 0xa5fc targets 0xa71c, is taken when t1(=[a0+57]:1) < a4(?) (signed), and falls through when t1(=[a0+57]:1) >= a4(?) (signed).
  The `blez` branch at 0xa60c targets 0xa5e8, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0xa614 targets 0xaf90 and is always taken.
  The `beq` branch at 0xa61c targets 0xa708, is taken when v0(?) == ra(=0x1), and falls through when v0(?) != ra(=0x1).
  The `beq` branch at 0xa624 targets 0xa6b0, is taken when v0(?) == s1(=0x5), and falls through when v0(?) != s1(=0x5).
  The `beq` branch at 0xa62c targets 0xa6b0, is taken when v0(?) == s4(=0x6), and falls through when v0(?) != s4(=0x6).
  The `bne` branch at 0xa634 targets 0xa6b8, is taken when v0(?) != s0(?), and falls through when v0(?) == s0(?).
  The `bne` branch at 0xa63c targets 0xa6b8, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0xa650 targets 0xa6b8, is taken when s3(?) >= v0(?) (unsigned), and falls through when s3(?) < v0(?) (unsigned).
  The `beql` branch at 0xa66c targets 0xa65c, is taken when t2(=table(0x1)) == 0, and falls through when t2(=table(0x1)) != 0; its branch-likely delay slot `nop` at 0xa670 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa674 targets 0xa878, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa688 targets 0xa5e4, is taken when t9(?) >= s6(?) (signed), and falls through when t9(?) < s6(?) (signed).
  The `beq` branch at 0xa694 targets 0xa67c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa6a0 targets 0xa67c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0xa6a8 targets 0xa6c8 and is always taken.
  The `beq` branch at 0xa6b0 targets 0xa63c, is taken when s0(?) == s7(=0x4), and falls through when s0(?) != s7(=0x4).
  The `beq` branch at 0xa6bc targets 0xa67c, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0xa6d4 targets 0xa61c, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `beq` branch at 0xa6dc targets 0xa61c, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `bne` branch at 0xa700 targets 0xa624, is taken when v0(?) != ra(=0x1), and falls through when v0(?) == ra(=0x1).
  The `bne` branch at 0xa70c targets 0xa6b8, is taken when s0(?) != s7(=0x4), and falls through when s0(?) == s7(=0x4).
  The `beq` branch at 0xa714 targets 0xa63c and is always taken.
  The `beq` branch at 0xa75c targets 0xa7c0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa764 targets 0xa7a4, is taken when s6(=0xff) == s2(?), and falls through when s6(=0xff) != s2(?).
  The `beq` branch at 0xa770 targets 0xa968, is taken when a3(=[a0+114]:2) == s7(=0x2), and falls through when a3(=[a0+114]:2) != s7(=0x2).
  The `beq` branch at 0xa784 targets 0xa970, is taken when s6(=0xff) == a6(?), and falls through when s6(=0xff) != a6(?).
  The `beq` branch at 0xa7c0 targets 0xab20, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0xa7c8 targets 0xad38, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa7e4 targets 0xa844, is taken when v0(=ret(pciio_error_handler)) == 0, and falls through when v0(=ret(pciio_error_handler)) != 0.
  The `beq` branch at 0xa7f0 targets 0xad54, is taken when v0(=ret(pciio_error_handler)) == t1(=0x9), and falls through when v0(=ret(pciio_error_handler)) != t1(=0x9).
  The `bne` branch at 0xa7fc targets 0xad7c, is taken when t2(=[sym(kdebug)]:2) != 0, and falls through when t2(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0xa81c targets 0xa958, is taken when s6(=0xff) == v0(?), and falls through when s6(=0xff) != v0(?).
  The `beq` branch at 0xa828 targets 0xa960, is taken when a1(=[a0+114]:2) == s7(=0x2), and falls through when a1(=[a0+114]:2) != s7(=0x2).
  The `bltz` branch at 0xa834 targets 0xab58, is taken when a4(=([a3] << 0x2)) < 0 (signed), and falls through when a4(=([a3] << 0x2)) >= 0 (signed).
  The `beq` branch at 0xa83c targets 0xab68, is taken when s5(=a2) == s7(=0x2), and falls through when s5(=a2) != s7(=0x2).
  The `bltz` branch at 0xa884 targets 0xa67c, is taken when t8(?) < 0 (signed), and falls through when t8(?) >= 0 (signed).
  The `beq` branch at 0xa890 targets 0xa67c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa8b4 targets 0xa67c and is always taken.
  The `beq` branch at 0xa8cc targets 0xa2fc and is always taken.
  The `beq` branch at 0xa8d4 targets 0xabd0, is taken when a4(=[a0+72]) == 0, and falls through when a4(=[a0+72]) != 0.
  The `bne` branch at 0xa8dc targets 0xa43c, is taken when a4(=[a0+72]) != t9(=0x1), and falls through when a4(=[a0+72]) == t9(=0x1).
  The `bne` branch at 0xa8f0 targets 0xac9c, is taken when s2(=[a3+24]:8) < ra(=0xc0000000) (unsigned), and falls through when s2(=[a3+24]:8) >= ra(=0xc0000000) (unsigned).
  The `bne` branch at 0xa900 targets 0xaca0, is taken when at(=0xffffffff) < s2(=[a3+24]:8) (unsigned), and falls through when at(=0xffffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa918 targets 0xa930, is taken when s2(=[a3+24]:8) < t8(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t8(=0x100000000) (unsigned).
  The `beq` branch at 0xa928 targets 0xacc0, is taken when t9(=0x13fffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when t9(=0x13fffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa930 targets 0xad2c, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa950 targets 0xa5c0 and is always taken.
  The `beq` branch at 0xa958 targets 0xa834 and is always taken.
  The `beq` branch at 0xa960 targets 0xa830 and is always taken.
  The `beq` branch at 0xa968 targets 0xa778 and is always taken.
  The `beq` branch at 0xa97c targets 0xa7a4 and is always taken.
  The `beq` branch at 0xa988 targets 0xa3a0 and is always taken.
  The `beq` branch at 0xa994 targets 0xa3fc and is always taken.
  The `beq` branch at 0xa99c targets 0xacf0, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0xa9b0 targets 0xabb4, is taken when t1(=[a0+57]:1) < a4(=[a0+56]:1) (signed), and falls through when t1(=[a0+57]:1) >= a4(=[a0+56]:1) (signed).
  The `beq` branch at 0xa9cc targets 0xa9ec and is always taken.
  The `bne` branch at 0xa9dc targets 0xa5c4, is taken when t1(=[a0+57]:1) < t2(?) (signed), and falls through when t1(=[a0+57]:1) >= t2(?) (signed).
  The `bne` branch at 0xa9e4 targets 0xa5c4, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `blez` branch at 0xa9f8 targets 0xa9d4, is taken when s5(?) <= 0 (signed), and falls through when s5(?) > 0 (signed).
  The `bne` branch at 0xaa00 targets 0xa9d4, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xaa08 targets 0xaa28 and is always taken.
  The `beq` branch at 0xaa1c targets 0xa9d4, is taken when v0(?) >= s5(?) (signed), and falls through when v0(?) < s5(?) (signed).
  The `bne` branch at 0xaa24 targets 0xa9d4, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xaa34 targets 0xaa14, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `bne` branch at 0xaa3c targets 0xaa14, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xaa48 targets 0xaa74 and is always taken.
  The `beq` branch at 0xaa64 targets 0xaa10, is taken when s8(?) == 0, and falls through when s8(?) != 0.
  The `bne` branch at 0xaa6c targets 0xaa14, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xaa8c targets 0xaa64, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0xaa9c targets 0xaa64, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xaab4 targets 0xaa64, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0xaac8 targets 0xaa64, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0xaad0 targets 0xaa64, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0xaad8 targets 0xaa64, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0xaae0 targets 0xaa50, is taken when t3(?) == a3(?), and falls through when t3(?) != a3(?).
  The `beq` branch at 0xaae8 targets 0xab00, is taken when t3(?) == s7(=0x4), and falls through when t3(?) != s7(=0x4).
  The `beq` branch at 0xaaf0 targets 0xab00, is taken when t3(?) == s1(=0x5), and falls through when t3(?) != s1(=0x5).
  The `bne` branch at 0xaaf8 targets 0xaa64, is taken when t3(?) != s4(=0x6), and falls through when t3(?) == s4(=0x6).
  The `beq` branch at 0xab00 targets 0xaa50, is taken when a3(?) == s7(=0x4), and falls through when a3(?) != s7(=0x4).
  The `beq` branch at 0xab08 targets 0xaa50, is taken when a3(?) == s1(=0x5), and falls through when a3(?) != s1(=0x5).
  The `bne` branch at 0xab10 targets 0xaa64, is taken when a3(?) != s4(=0x6), and falls through when a3(?) == s4(=0x6).
  The `beq` branch at 0xab18 targets 0xaa54 and is always taken.
  The `bne` branch at 0xab2c targets 0xab3c, is taken when s6(=0xff) != s2(?), and falls through when s6(=0xff) == s2(?).
  The `beq` branch at 0xab34 targets 0xab50 and is always taken.
  The `beq` branch at 0xab50 targets 0xa848 and is always taken.
  The `beq` branch at 0xab60 targets 0xa83c and is always taken.
  The `beq` branch at 0xab70 targets 0xa848 and is always taken.
  The `beq` branch at 0xab80 targets 0xa334 and is always taken.
  The `beq` branch at 0xaba0 targets 0xa434 and is always taken.
  The `beq` branch at 0xabac targets 0xa9a4 and is always taken.
  The `beq` branch at 0xabbc targets 0xa5c0 and is always taken.
  The `beq` branch at 0xabc8 targets 0xa9a4 and is always taken.
  The `bne` branch at 0xabd8 targets 0xac54, is taken when s2(=[a3+24]:8) < ra(=0x40000000) (unsigned), and falls through when s2(=[a3+24]:8) >= ra(=0x40000000) (unsigned).
  The `bne` branch at 0xabec targets 0xac50, is taken when at(=0x7fffffff) < s2(=[a3+24]:8) (unsigned), and falls through when at(=0x7fffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xac04 targets 0xac1c, is taken when s2(=[a3+24]:8) < v0(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= v0(=0x80000000) (unsigned).
  The `beq` branch at 0xac14 targets 0xac70, is taken when v1(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when v1(=0xbfffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xac1c targets 0xad20, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xac3c targets 0xa5c0 and is always taken.
  The `beq` branch at 0xac48 targets 0xa9a4 and is always taken.
  The `bne` branch at 0xac5c targets 0xa5a0, is taken when s2(=[a3+24]:8) < a4(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= a4(=0x80000000) (unsigned).
  The `bne` branch at 0xac68 targets 0xa5a0, is taken when a7(=0xbfffffff) < s2(=[a3+24]:8) (unsigned), and falls through when a7(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xac74 targets 0xad08, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xac94 targets 0xa5c0 and is always taken.
  The `bne` branch at 0xaca8 targets 0xa5a0, is taken when s2(=[a3+24]:8) < a4(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= a4(=0x100000000) (unsigned).
  The `bne` branch at 0xacb4 targets 0xa5a4, is taken when a7(=0x13fffffff) < s2(=[a3+24]:8) (unsigned), and falls through when a7(=0x13fffffff) >= s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xacc8 targets 0xad14, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xace8 targets 0xa5c0 and is always taken.
  The `beq` branch at 0xad00 targets 0xa5c0 and is always taken.
  The `beq` branch at 0xad0c targets 0xa9a4 and is always taken.
  The `beq` branch at 0xad18 targets 0xa9a4 and is always taken.
  The `beq` branch at 0xad24 targets 0xa9a4 and is always taken.
  The `beq` branch at 0xad30 targets 0xa9a4 and is always taken.
  The `beq` branch at 0xad4c targets 0xa848 and is always taken.
  The `bltz` branch at 0xad6c targets 0xaeac, is taken when a2(=([a3] << 0x8)) < 0 (signed), and falls through when a2(=([a3] << 0x8)) >= 0 (signed).
  The `beq` branch at 0xad74 targets 0xa7f8 and is always taken.
  The `beq` branch at 0xad9c targets 0xadb0, is taken when (v0(=ret(pcireg_intr_status_get)) & a3(=0x4400008800)) == 0, and falls through when (v0(=ret(pcireg_intr_status_get)) & a3(=0x4400008800)) != 0.
  The `bgez` branch at 0xadf8 targets 0xa818, is taken when a4(=([a3] << 0x2)) >= 0 (signed), and falls through when a4(=([a3] << 0x2)) < 0 (signed).
  The `beq` branch at 0xae00 targets 0xaf14, is taken when s6(=0xff) == a0(?), and falls through when s6(=0xff) != a0(?).
  The `beq` branch at 0xae0c targets 0xaf28, is taken when a5(=[a0+114]:2) == s7(=0x2), and falls through when a5(=[a0+114]:2) != s7(=0x2).
  The `beq` branch at 0xae20 targets 0xa81c, is taken when s0(?) >= a6(=[a0+57]:1+1) (signed), and falls through when s0(?) < a6(=[a0+57]:1+1) (signed).
  The `beq` branch at 0xaea4 targets 0xa818 and is always taken.
  The `beq` branch at 0xaeb4 targets 0xaf4c, is taken when v0(=[a3+36]) == a5(=0x7), and falls through when v0(=[a3+36]) != a5(=0x7).
  The `beq` branch at 0xaebc targets 0xaf74, is taken when s7(=0x2) == v0(=[a3+36]), and falls through when s7(=0x2) != v0(=[a3+36]).
  The `beq` branch at 0xaec4 targets 0xaf30, is taken when v0(=[a3+36]) == a6(=0x4), and falls through when v0(=[a3+36]) != a6(=0x4).
  The `beq` branch at 0xaecc targets 0xaf34, is taken when v0(=[a3+36]) == a7(=0x5), and falls through when v0(=[a3+36]) != a7(=0x5).
  The `beq` branch at 0xaed8 targets 0xaf30, is taken when v0(=[a3+36]) == t0(=0x6), and falls through when v0(=[a3+36]) != t0(=0x6).
  The `beq` branch at 0xaee4 targets 0xad74, is taken when a4(=[a3+36]-8) >= 0x6 (unsigned), and falls through when a4(=[a3+36]-8) < 0x6 (unsigned).
  The `beq` branch at 0xaf0c targets 0xad74 and is always taken.
  The `bne` branch at 0xaf18 targets 0xa81c, is taken when t1(=[a0+57]:1) < 0xff (signed), and falls through when t1(=[a0+57]:1) >= 0xff (signed).
  The `beq` branch at 0xaf20 targets 0xae28 and is always taken.
  The `beq` branch at 0xaf28 targets 0xae14 and is always taken.
  The `beq` branch at 0xaf44 targets 0xad74 and is always taken.
  The `beq` branch at 0xaf6c targets 0xad74 and is always taken.
  The `beq` branch at 0xaf88 targets 0xad74 and is always taken.
  The `beq` branch at 0xaf94 targets 0xa694 and is always taken.
  The `beq` branch at 0xafa4 targets 0xa608 and is always taken.
  The return at 0xa870 has v0 = one of ?, 0x7.
  The instructions from 0xa4d0 to 0xa4d0 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xa54c to 0xa54c are not reached by any path from the entry, and their branches are not listed.

- `pcibr_dmard_error` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xafac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xafac-0xb0d4 (296 bytes).
  It occupies 296 bytes.
  The `lw` at 0xafac loads 4 bytes from a0 (arg0 at entry) +0x4.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0xaff0, `lw` at 0xb00c.
  The `sh` at 0xaff4 stores 2 bytes to a3 (arg3 at entry) +0x8.
  2 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0xb008, `sw` at 0xb020.
  The `sd` at 0xb010 stores 8 bytes to a3 (arg3 at entry) +0x28.
  The `lh` at 0xb03c loads 2 bytes from a3 (arg3 at entry) +0x8.
  The `jal` at 0xafd8 calls pcireg_resp_err_buf_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xafe4 calls pcireg_resp_err_dev_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb004 calls pcireg_resp_err_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb02c calls pciio_error_handler with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb048 calls pcibr_device_disable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb05c calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=0x10, a2=?, a3=?.
  The `jal` at 0xb078 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb0a4 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb0b4 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=ret(pcireg_rrb_get), a3=?.
  The `beq` branch at 0xb034 targets 0xb050, is taken when v0(=ret(pciio_error_handler)) == 0, and falls through when v0(=ret(pciio_error_handler)) != 0.
  The return at 0xb0cc has v0 = ret(pciio_error_handler).

- `pcibr_dmawr_error` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb0d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb0d4-0xb11c (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0xb0e8 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lh` at 0xb0f8 loads 2 bytes from a3 (arg3 at entry) +0x8.
  The `jal` at 0xb0e4 calls pciio_error_handler with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb104 calls pcibr_device_disable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xb0ec targets 0xb10c, is taken when v0(=ret(pciio_error_handler)) == 0, and falls through when v0(=ret(pciio_error_handler)) != 0.
  The return at 0xb114 has v0 = ret(pciio_error_handler).

- `pcibr_error_handler` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb11c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb11c-0xb1e8 (204 bytes).
  It occupies 204 bytes.
  The `lw` at 0xb150 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0xb154 calls pcibr_debug with a0=0x200, a1=[a0], a2=sym(.rodata)+6152, a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The `jal` at 0xb174 calls pcibr_pioerror with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb1a0 calls pcibr_dmard_error with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0xb1c0 calls pcibr_dmawr_error with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=a3 at entry (arg3).
  The `beq` branch at 0xb160 targets 0xb180, is taken when (s0(=a1) & 0x4) == 0, and falls through when (s0(=a1) & 0x4) != 0.
  The `beq` branch at 0xb184 targets 0xb1cc, is taken when (s0(=a1) & 0x8) == 0, and falls through when (s0(=a1) & 0x8) != 0.
  The `beq` branch at 0xb18c targets 0xb1b0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xb1b0 targets 0xb1cc, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0xb1e0 has v0 = one of ?, ret(pcibr_dmawr_error).

- `pcibr_error_handler_wrapper` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb1e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb1e8-0xb430 (584 bytes).
  It occupies 584 bytes.
  The `lw` at 0xb1f8 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0xb25c loads 8 bytes from a3 (arg3 at entry) +0x18.
  The `ld` at 0xb2c8 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lh` at 0xb3a8 loads 2 bytes from a3 (arg3 at entry) +0x50.
  The `lw` at 0xb3b0 loads 4 bytes from a3 (arg3 at entry) +0x0.
  The `sw` at 0xb3c4 stores 4 bytes to a3 (arg3 at entry) +0x0.
  The `sh` at 0xb3d0 stores 2 bytes to a3 (arg3 at entry) +0x8.
  The `ld` at 0xb3d8 loads 8 bytes from ?.
  The `jal` at 0xb238 calls pcibr_debug with a0=0x200, a1=[a0], a2=sym(.rodata)+6152, a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The `jal` at 0xb360 calls pcibr_error_handler with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb380 calls pcibr_error_handler with a0=[a0+64]:8, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb3dc calls pcibr_error_handler with a0=?, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=([a3] | 0x20000000), a6=0x20000000.
  The `jal` at 0xb400 calls pcibr_error_handler with a0=?, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=([a3] | 0x20000000), a6=0x20000000.
  The `jal` at 0xb41c calls cmn_err with a0=0x4, a1=sym(.rodata)+6152, a2=[a3+24]:8, a3=?.
  The `beq` branch at 0xb254 targets 0xb390, is taken when (s1(=a1) & 0x4) == 0, and falls through when (s1(=a1) & 0x4) != 0.
  The `beq` branch at 0xb27c targets 0xb350, is taken when a4(=0x7fffff) >= a2(=[a3+24]:8) (unsigned), and falls through when a4(=0x7fffff) < a2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xb294 targets 0xb2a0, is taken when a2(=[a3+24]:8) < a5(=0x40000000) (unsigned), and falls through when a2(=[a3+24]:8) >= a5(=0x40000000) (unsigned).
  The `beq` branch at 0xb29c targets 0xb350, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0xb2a8 targets 0xb2b8, is taken when a2(=[a3+24]:8) < a6(=0x800000) (unsigned), and falls through when a2(=[a3+24]:8) >= a6(=0x800000) (unsigned).
  The `beq` branch at 0xb2b0 targets 0xb2c8, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0xb2b8 targets 0xb418, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0xb2c0 targets 0xb418, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0xb2cc targets 0xb374, is taken when s3(=[a0+64]:8) != 0, and falls through when s3(=[a0+64]:8) == 0.
  The `beq` branch at 0xb2e0 targets 0xb3a8, is taken when a7(?) == t0(=0xa), and falls through when a7(?) != t0(=0xa).
  The `beq` branch at 0xb2f4 targets 0xb398, is taken when s0(?) == s5(=-0x1), and falls through when s0(?) != s5(=-0x1).
  The `beq` branch at 0xb2fc targets 0xb338, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xb304 targets 0xb338, is taken when a0(?) == s5(=-0x1), and falls through when a0(?) != s5(=-0x1).
  The `beq` branch at 0xb338 targets 0xb3f0, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xb340 targets 0xb3f0, is taken when s0(?) == s5(=-0x1), and falls through when s0(?) != s5(=-0x1).
  The `beq` branch at 0xb348 targets 0xb310 and is always taken.
  The `beq` branch at 0xb36c targets 0xb2d8 and is always taken.
  The `beq` branch at 0xb388 targets 0xb2d4 and is always taken.
  The `beq` branch at 0xb390 targets 0xb2dc and is always taken.
  The `bne` branch at 0xb398 targets 0xb2fc, is taken when a0(?) != s5(=-0x1), and falls through when a0(?) == s5(=-0x1).
  The `beq` branch at 0xb3a0 targets 0xb30c and is always taken.
  The `beq` branch at 0xb3cc targets 0xb3f8, is taken when (a4(=[a3+80]:2) & 0x4) == 0, and falls through when (a4(=[a3+80]:2) & 0x4) != 0.
  The `beq` branch at 0xb3e8 targets 0xb2e8 and is always taken.
  The `beq` branch at 0xb3f0 targets 0xb30c and is always taken.
  The `beq` branch at 0xb40c targets 0xb2e8 and is always taken.
  The `beq` branch at 0xb428 targets 0xb2d8 and is always taken.
  The return at 0xb330 has v0 = ?.
  The instructions from 0xb414 to 0xb414 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_error_devenable` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb430 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb430-0xb4ac (124 bytes).
  It occupies 124 bytes.
  The `lbu` at 0xb448 loads 1 byte from ret(pciio_info_get) +0x21c.
  The `lw` at 0xb468 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0xb43c calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb450 calls pciio_info_mfast_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xb470 calls xtalk_error_devenable with a0=[ret(pciio_info_mfast_get)], a1=[ret(pciio_info_get)+540]:1, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0xb48c calls pcibr_error_cleanup with a0=ret(pciio_info_mfast_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `bne` branch at 0xb460 targets 0xb48c, is taken when (s0(=a1) & 0x2) != 0, and falls through when (s0(=a1) & 0x2) == 0.
  The `beq` branch at 0xb478 targets 0xb48c, is taken when v0(=ret(xtalk_error_devenable)) == 0, and falls through when v0(=ret(xtalk_error_devenable)) != 0.
  The `beq` branch at 0xb480 targets 0xb49c and is always taken.
  The return at 0xb4a4 has v0 = one of ret(xtalk_error_devenable), 0x0.
  The instructions from 0xb488 to 0xb488 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_func_config_addr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb4ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb4ac-0xb530 (132 bytes).
  It occupies 132 bytes.
  The `jal` at 0xb4e0 calls pcireg_type1_cntr_set with a0=a0 at entry (arg0), a1=((a1 << 0x10) | (a2 << 0xb)), a2=(a2 << 0xb), a3=a3 at entry (arg3), a7=a1 at entry (arg1).
  The `jal` at 0xb4f0 calls pcireg_type1_cfg_addr with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=?.
  The `jal` at 0xb520 calls pcireg_type0_cfg_addr with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=a4 at entry (arg4), a7=a1 at entry (arg1).
  The `blez` branch at 0xb4d0 targets 0xb518, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0xb528 targets 0xb4fc and is always taken.
  The return at 0xb510 has v0 = one of ret(pcireg_type1_cfg_addr), ret(pcireg_type0_cfg_addr).

- `pcibr_slot_config_addr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb530 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb530-0xb55c (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xb548 calls pcibr_func_config_addr with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=0x0, a4=a2 at entry (arg2).
  The return at 0xb554 has v0 = ret(pcibr_func_config_addr).

- `pcibr_slot_config_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb55c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb55c-0xb598 (60 bytes).
  It occupies 60 bytes.
  The `jal` at 0xb56c calls pcibr_slot_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0xb57c calls do_pcibr_config_get with a0=ret(pcibr_slot_config_addr), a1=a2 at entry (arg2), a2=0x4, a3=?.
  The return at 0xb590 has v0 = (ret(do_pcibr_config_get) << 0x0).

- `pcibr_func_config_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb598 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb598-0xb5e8 (80 bytes).
  It occupies 80 bytes.
  The `jal` at 0xb5bc calls pcibr_func_config_addr with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `jal` at 0xb5cc calls do_pcibr_config_get with a0=ret(pcibr_func_config_addr), a1=a3 at entry (arg3), a2=0x4, a3=?.
  The return at 0xb5e0 has v0 = (ret(do_pcibr_config_get) << 0x0).

- `pcibr_slot_config_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb5e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb5e8-0xb630 (72 bytes).
  It occupies 72 bytes.
  The `jal` at 0xb5fc calls pcibr_slot_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0xb618 calls do_pcibr_config_set with a0=ret(pcibr_slot_config_addr), a1=a2 at entry (arg2), a2=0x4, a3=?.
  The return at 0xb628 has v0 = ret(do_pcibr_config_set).

- `pcibr_func_config_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb630 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb630-0xb68c (92 bytes).
  It occupies 92 bytes.
  The `jal` at 0xb658 calls pcibr_func_config_addr with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `jal` at 0xb674 calls do_pcibr_config_set with a0=ret(pcibr_func_config_addr), a1=a3 at entry (arg3), a2=0x4, a3=?.
  The return at 0xb684 has v0 = ret(do_pcibr_config_set).

- `pcibr_config_addr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb68c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb68c-0xb780 (244 bytes).
  It occupies 244 bytes.
  The `ld` at 0xb6f4 loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `ld` at 0xb704 loads 8 bytes from [ret(pcibr_info_get)+40]:8 +0x8.
  The `lbu` at 0xb728 loads 1 byte from ret(pciio_info_get) +0x12.
  The `lbu` at 0xb72c loads 1 byte from ret(pciio_info_get) +0x11.
  The `lbu` at 0xb734 loads 1 byte from ret(pciio_info_get) +0x10.
  The `lbu` at 0xb744 loads 1 byte from ret(pcibr_info_get) +0x21c.
  The `lbu` at 0xb74c loads 1 byte from ret(pcibr_info_get) +0x12.
  The `jal` at 0xb6a4 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb6b4 calls pcibr_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb6c0 calls pciio_info_type1_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xb700 calls pcibr_func_config_addr with a0=[[ret(pcibr_info_get)+40]:8+8]:8, a1=?, a2=?, a3=?, a4=0x0.
  The `jal` at 0xb718 calls pciio_info_hostdev_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xb6c8 targets 0xb718, is taken when v0(=ret(pciio_info_type1_get)) == 0, and falls through when v0(=ret(pciio_info_type1_get)) != 0.
  The `beq` branch at 0xb720 targets 0xb744, is taken when v0(=ret(pciio_info_hostdev_get)) == s2(=a0), and falls through when v0(=ret(pciio_info_hostdev_get)) != s2(=a0).
  The `beq` branch at 0xb73c targets 0xb6ec and is always taken.
  The `beq` branch at 0xb748 targets 0xb760, is taken when a0(=0xff) == a2(=[ret(pcibr_info_get)+540]:1), and falls through when a0(=0xff) != a2(=[ret(pcibr_info_get)+540]:1).
  The `beq` branch at 0xb750 targets 0xb770, is taken when a0(=0xff) == a3(=[ret(pcibr_info_get)+18]:1), and falls through when a0(=0xff) != a3(=[ret(pcibr_info_get)+18]:1).
  The `beq` branch at 0xb758 targets 0xb6f0 and is always taken.
  The `beq` branch at 0xb768 targets 0xb750 and is always taken.
  The `beq` branch at 0xb778 targets 0xb754 and is always taken.
  The return at 0xb710 has v0 = ret(pcibr_func_config_addr).

- `pcibr_config_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb780 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb780-0xb7b8 (56 bytes).
  It occupies 56 bytes.
  The `jal` at 0xb790 calls pcibr_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb7a0 calls do_pcibr_config_get with a0=ret(pcibr_config_addr), a1=?, a2=a2 at entry (arg2), a3=?.
  The return at 0xb7b0 has v0 = ret(do_pcibr_config_get).

- `pcibr_config_get_safe` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb7b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb7b8-0xb818 (96 bytes).
  It occupies 96 bytes.
  The `ld` at 0xb7d0 loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `ld` at 0xb7d8 loads 8 bytes from [ret(pcibr_info_get)+40]:8 +0x8.
  The `jal` at 0xb7c8 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb7e0 calls pcibr_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xb7f4 calls pcibr_probe_slot with a0=?, a1=ret(pcibr_config_addr), a2=sp-48, a3=?.
  The `beq` branch at 0xb7fc targets 0xb810, is taken when v0(=ret(pcibr_probe_slot)) == 0, and falls through when v0(=ret(pcibr_probe_slot)) != 0.
  The `beq` branch at 0xb810 targets 0xb808 and is always taken.
  The return at 0xb808 has v0 = one of -0x1, ?.

- `do_pcibr_config_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb818 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb818-0xb864 (76 bytes).
  It occupies 76 bytes.
  The `lw` at 0xb83c loads 4 bytes from ?.
  The `beq` branch at 0xb838 targets 0xb848, is taken when (a1 & 0x3) == 0, and falls through when (a1 & 0x3) != 0.
  The `beq` branch at 0xb848 targets 0xb858, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0xb85c has v0 = ?.

- `pcibr_config_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb864 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb864-0xb8a4 (64 bytes).
  It occupies 64 bytes.
  The `jal` at 0xb878 calls pcibr_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb88c calls do_pcibr_config_set with a0=ret(pcibr_config_addr), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xb89c has v0 = ret(do_pcibr_config_set).

- `do_pcibr_config_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb8a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb8a4-0xb9dc (312 bytes).
  It occupies 312 bytes.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0xb904, `sb` at 0xb910, `sb` at 0xb944.
  3 such `sh` accesses store 2 bytes to ?, including `sh` at 0xb950, `sh` at 0xb99c, `sh` at 0xb9d0.
  The `sw` at 0xb964 stores 4 bytes to ?.
  The `beq` branch at 0xb8b0 targets 0xb968, is taken when a2 == at(=0x1), and falls through when a2 != at(=0x1).
  The `beq` branch at 0xb8b8 targets 0xb8d8, is taken when a2 == a5(=0x2), and falls through when a2 != a5(=0x2).
  The `beq` branch at 0xb8c0 targets 0xb914, is taken when a2 == a6(=0x3), and falls through when a2 != a6(=0x3).
  The `beq` branch at 0xb8c8 targets 0xb954, is taken when a2 == a7(=0x4), and falls through when a2 != a7(=0x4).
  The `beq` branch at 0xb8ec targets 0xb980, is taken when (a1 & 0x1) == 0, and falls through when (a1 & 0x1) != 0.
  The `beq` branch at 0xb920 targets 0xb9a0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The return at 0xb8d0 has v0 = ?.
  The return at 0xb90c has v0 = ?.
  The return at 0xb94c has v0 = ?.
  The return at 0xb960 has v0 = ?.
  The return at 0xb978 has v0 = ?.
  The return at 0xb998 has v0 = ?.
  The return at 0xb9d4 has v0 = ?.

- `pcibr_slot_info_init` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xb9dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xb9dc-0xc50c (2864 bytes).
  It occupies 2864 bytes.
  The `lbu` at 0xba14 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `ld` at 0xba24 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `lw` at 0xba34 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xbac0, `lw` at 0xbbc0, `lw` at 0xc264.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0xbac8, `sw` at 0xbc24, `sw` at 0xbdf8.
  6 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0xbaec, `lh` at 0xbcd0, `lh` at 0xbd8c.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xbc18, `sd` at 0xbdec, `sd` at 0xbdf0.
  5 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x74, including `lh` at 0xbd34, `lh` at 0xbd5c, `lh` at 0xc1f0.
  The `sd` at 0xc090 stores 8 bytes to ret(pcibr_device_info_new) +0x220.
  The `lw` at 0xc094 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x508.
  The `sw` at 0xc09c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x508.
  The `ld` at 0xc0a0 loads 8 bytes from ret(pcibr_device_info_new) +0x220.
  The `lw` at 0xc0a4 loads 4 bytes from [ret(pcibr_device_info_new)+544]:8 +0x4.
  The `lw` at 0xc0bc loads 4 bytes from ret(hwgraph_fastinfo_get) +0x50c.
  The `lw` at 0xc0c0 loads 4 bytes from table(sym(max_splittrans_to_numbuf)) +0x0.
  The `sw` at 0xc0c8 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x50c.
  3 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x878, including `lw` at 0xc168, `lw` at 0xc194, `lw` at 0xc484.
  The `lbu` at 0xc170 loads 1 byte from ret(hwgraph_fastinfo_get) +0x28.
  2 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0x878, including `sw` at 0xc1a0, `sw` at 0xc490.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x10, including `ld` at 0xc4b0, `ld` at 0xc4e0.
  The `jal` at 0xb9fc calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xba70 calls pcibr_is_slot_sys_critical with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x16, a3=?.
  The `jal` at 0xba90 calls pcibr_slot_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=0x0, a3=?.
  The `jal` at 0xbaa4 calls pcibr_probe_slot with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=ret(pcibr_slot_config_addr), a2=sp-608, a3=?.
  The `jal` at 0xbb08 calls pcibr_debug with a0=0x80, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=?.
  The `jal` at 0xbb24 calls do_pcibr_config_get with a0=ret(pcibr_slot_config_addr), a1=0xe, a2=0x1, a3=?, a5=0xffff.
  The `jal` at 0xbba0 calls pcibr_func_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xbbb0 calls pcibr_probe_slot with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=ret(pcibr_func_config_addr), a2=?, a3=?.
  The `jal` at 0xbbe8 calls pcibr_slot_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=0x0, a3=?.
  The `jal` at 0xbc04 calls kmem_zalloc with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0xbcf4 calls pcibr_debug with a0=0x400, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=?.
  The `jal` at 0xbd10 calls do_pcibr_config_get with a0=?, a1=0xd, a2=0x1, a3=?.
  The `jal` at 0xbd20 calls pcireg_device_get with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xbd4c calls do_pcibr_config_get with a0=?, a1=0xc, a2=0x1, a3=?.
  The `jal` at 0xbd70 calls pcibr_find_capability with a0=?, a1=0x7, a2=?, a3=?.
  The `jal` at 0xbdb4 calls pcibr_debug with a0=0x400, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=ret(pcibr_find_capability).
  The `jal` at 0xbe28 calls do_pcibr_config_set with a0=?, a1=?, a2=0x4, a3=0x0, a6=0x4.
  The `jal` at 0xbe64 calls sprintf with a0=sp-568, a1=sym(.rodata)+10976, a2=?, a3=?.
  The `jal` at 0xbe7c calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=sp-568.
  The `jal` at 0xbec0 calls do_pcibr_config_get with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xbf58 calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=one of 0x2, 0x4, 0x5, a3=?, a5=0x0.
  The `jal` at 0xbfe4 calls do_pcibr_config_set with a0=?, a1=?, a2=0x4, a3=-0x1.
  The `jal` at 0xbff4 calls do_pcibr_config_get with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xc080 calls pcibr_device_info_new with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xc0d0 calls pciio_device_info_register with a0=a0 at entry (arg0), a1=ret(pcibr_device_info_new), a2=?, a3=?.
  The `jal` at 0xc0e4 calls do_pcibr_config_get with a0=?, a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xc18c calls pciio_device_win_populate with a0=?, a1=([ret(hwgraph_fastinfo_get)+40]:1 << 0x18), a2=0x1000000, a3=?.
  The `jal` at 0xc1e8 calls do_pcibr_config_get with a0=?, a1=0x3e, a2=0x1, a3=?.
  The `jal` at 0xc26c calls pcibr_func_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xc28c calls do_pcibr_config_get with a0=ret(pcibr_func_config_addr), a1=0xe, a2=0x1, a3=?.
  The `jal` at 0xc308 calls do_pcibr_config_get with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xc32c calls do_pcibr_config_set with a0=?, a1=0xc, a2=0x1, a3=0x20.
  The `jal` at 0xc360 calls pcibr_debug with a0=0x400, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=?.
  The `jal` at 0xc384 calls do_pcibr_config_set with a0=?, a1=0xd, a2=0x1, a3=?, a6=one of 0x8, 0x10, 0x18, 0x20, a7=0x5.
  The `jal` at 0xc3bc calls pcibr_debug with a0=0x400, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=?.
  The `jal` at 0xc47c calls pciio_device_win_populate with a0=?, a1=([ret(hwgraph_fastinfo_get)+40]:1 << 0x18), a2=0x1000000, a3=0x10a9.
  The `jal` at 0xc4c0 calls cmn_err with a0=0x4, a1=sym(.rodata)+10976, a2=[ret(hwgraph_fastinfo_get)+16]:8, a3=a1 at entry (arg1).
  The `jal` at 0xc4e4 calls cmn_err with a0=0x4, a1=sym(.rodata)+10976, a2=[ret(hwgraph_fastinfo_get)+16]:8, a3=a1 at entry (arg1).
  The `jal` at 0xc4fc calls pcibr_device_info_new with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=0xff, a3=-0x1, a4=-0x1.
  The `beq` branch at 0xba0c targets 0xba44, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xba20 targets 0xba68, is taken when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xba38 targets 0xba70, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xba68 targets 0xba44 and is always taken.
  The `beq` branch at 0xba78 targets 0xba88, is taken when v0(=ret(pcibr_is_slot_sys_critical)) == 0, and falls through when v0(=ret(pcibr_is_slot_sys_critical)) != 0.
  The `beq` branch at 0xba80 targets 0xba44 and is always taken.
  The `beq` branch at 0xbaac targets 0xbac0, is taken when v0(=ret(pcibr_probe_slot)) == 0, and falls through when v0(=ret(pcibr_probe_slot)) != 0.
  The `beq` branch at 0xbab8 targets 0xba44 and is always taken.
  The `beq` branch at 0xbae4 targets 0xc2c0, is taken when v1(=0xff) == s0(=a1), and falls through when v1(=0xff) != s0(=a1).
  The `beq` branch at 0xbaf4 targets 0xc2f0, is taken when a3(=[ret(hwgraph_fastinfo_get)+114]:2) == a4(=0x2), and falls through when a3(=[ret(hwgraph_fastinfo_get)+114]:2) != a4(=0x2).
  The `beq` branch at 0xbb18 targets 0xc2a8, is taken when a5(=0xffff) == a6(?), and falls through when a5(=0xffff) != a6(?).
  The `beq` branch at 0xbb3c targets 0xc2c8, is taken when (a7(=(ret(do_pcibr_config_get) << 0x0)) & 0x80) == 0, and falls through when (a7(=(ret(do_pcibr_config_get) << 0x0)) & 0x80) != 0.
  The `beq` branch at 0xbb5c targets 0xbb80 and is always taken.
  The `beq` branch at 0xbb78 targets 0xbbe0, is taken when s2(?) >= 0x8 (signed), and falls through when s2(?) < 0x8 (signed).
  The `bne` branch at 0xbbb8 targets 0xbb64, is taken when v0(=ret(pcibr_probe_slot)) != 0, and falls through when v0(=ret(pcibr_probe_slot)) == 0.
  The `beq` branch at 0xbbcc targets 0xc2e0, is taken when ra(?) == at(=0xffff), and falls through when ra(?) != at(=0xffff).
  The `beq` branch at 0xbbd8 targets 0xbb70 and is always taken.
  The `blez` branch at 0xbc20 targets 0xc12c, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0xbc48 targets 0xbc74 and is always taken.
  The `bne` branch at 0xbc58 targets 0xbe00, is taken when a6(?) != a7(=0x3), and falls through when a6(?) == a7(=0x3).
  The `beq` branch at 0xbc6c targets 0xc12c, is taken when s2(?) >= t0(?) (signed), and falls through when s2(?) < t0(?) (signed).
  The `beq` branch at 0xbc74 targets 0xbc9c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xbc8c targets 0xc248, is taken when (s3(?) & t8(?)) == 0, and falls through when (s3(?) & t8(?)) != 0.
  The `bne` branch at 0xbc94 targets 0xbc64, is taken when s3(?) != 0, and falls through when s3(?) == 0.
  The `beq` branch at 0xbca4 targets 0xc144, is taken when (t9(?) & 0x7f) == 0, and falls through when (t9(?) & 0x7f) != 0.
  The `bne` branch at 0xbcb4 targets 0xc4ac, is taken when ra(=0x1) != at(?), and falls through when ra(=0x1) == at(?).
  The `beq` branch at 0xbcc8 targets 0xc150, is taken when v1(=0xff) == s0(=a1), and falls through when v1(=0xff) != s0(=a1).
  The `beq` branch at 0xbcd8 targets 0xc240, is taken when a0(=[ret(hwgraph_fastinfo_get)+114]:2) == a1(=0x2), and falls through when a0(=[ret(hwgraph_fastinfo_get)+114]:2) != a1(=0x2).
  The `beq` branch at 0xbd04 targets 0xc158, is taken when a2(?) == a3(=0x10a9), and falls through when a2(?) != a3(=0x10a9).
  The `beq` branch at 0xbd2c targets 0xc1a4, is taken when a4(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a4(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xbd3c targets 0xc070, is taken when (a5(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a5(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xbd54 targets 0xc324, is taken when v0(=ret(do_pcibr_config_get)) == 0, and falls through when v0(=ret(do_pcibr_config_get)) != 0.
  The `beq` branch at 0xbd64 targets 0xc070, is taken when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xbd78 targets 0xc4d0, is taken when v0(=ret(pcibr_find_capability)) == 0, and falls through when v0(=ret(pcibr_find_capability)) != 0.
  The `beq` branch at 0xbd84 targets 0xc2f8, is taken when t0(=0xff) == s0(=a1), and falls through when t0(=0xff) != s0(=a1).
  The `beq` branch at 0xbd94 targets 0xc31c, is taken when t1(=[ret(hwgraph_fastinfo_get)+114]:2) == t2(=0x2), and falls through when t1(=[ret(hwgraph_fastinfo_get)+114]:2) != t2(=0x2).
  The `bne` branch at 0xbdc0 targets 0xbc60, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0xbdc8 targets 0xc074 and is always taken.
  The `beq` branch at 0xbdf4 targets 0xbc50, is taken when a5(?) == a6(=0x10a9), and falls through when a5(?) != a6(=0x10a9).
  The `bne` branch at 0xbe04 targets 0xbe94, is taken when a6(=0x4) != a7(?), and falls through when a6(=0x4) == a7(?).
  The `beq` branch at 0xbe30 targets 0xbe98 and is always taken.
  The `beq` branch at 0xbe8c targets 0xbdd0, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xbeb0 targets 0xbc60, is taken when s6(?) >= a4(?) (signed), and falls through when s6(?) < a4(?) (signed).
  The `beq` branch at 0xbedc targets 0xbf94, is taken when (v0(=ret(do_pcibr_config_get)) & 0x1) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0x1) != 0.
  The `beq` branch at 0xbef4 targets 0xbf04, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xbf08 targets 0xbfd8, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xbf24 targets 0xc01c, is taken when t2(=one of 0x2, 0x4) == t3(=0x4), and falls through when t2(=one of 0x2, 0x4) != t3(=0x4).
  The `beq` branch at 0xbf70 targets 0xbe84, is taken when (a5(=[sym(pcibr_debug_mask)]) & 0x800) == 0, and falls through when (a5(=[sym(pcibr_debug_mask)]) & 0x800) != 0.
  The `beq` branch at 0xbf78 targets 0xc034, is taken when a6(=0xff) == s0(=a1), and falls through when a6(=0xff) != s0(=a1).
  The `bne` branch at 0xbf84 targets 0xbe38, is taken when a7(=[ret(hwgraph_fastinfo_get)+114]:2) != t0(=0x2), and falls through when a7(=[ret(hwgraph_fastinfo_get)+114]:2) == t0(=0x2).
  The `beq` branch at 0xbf8c targets 0xbe3c and is always taken.
  The `beq` branch at 0xbfb4 targets 0xc048, is taken when (t3(=-0x10) & v0(=ret(do_pcibr_config_get))) == 0, and falls through when (t3(=-0x10) & v0(=ret(do_pcibr_config_get))) != 0.
  The `beq` branch at 0xbfbc targets 0xc058, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0xbfcc targets 0xc03c, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xc014 targets 0xbe84 and is always taken.
  The `beq` branch at 0xc024 targets 0xbf2c, is taken when v0(=0x2) == v1(?), and falls through when v0(=0x2) != v1(?).
  The `beq` branch at 0xc02c targets 0xbf2c and is always taken.
  The `beq` branch at 0xc034 targets 0xbe3c and is always taken.
  The `beq` branch at 0xc040 targets 0xc300, is taken when a1(=0x4) == t2(?), and falls through when a1(=0x4) != t2(?).
  The `beq` branch at 0xc050 targets 0xbf04 and is always taken.
  The `beq` branch at 0xc068 targets 0xbfd8 and is always taken.
  The `beq` branch at 0xc08c targets 0xc0cc, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xc0d8 targets 0xc2b4, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `blez` branch at 0xc0f0 targets 0xbc64, is taken when t1(?) <= 0 (signed), and falls through when t1(?) > 0 (signed).
  The `beq` branch at 0xc124 targets 0xbeb8 and is always taken.
  The `beq` branch at 0xc13c targets 0xba44 and is always taken.
  The `beq` branch at 0xc148 targets 0xbcc4 and is always taken.
  The `beq` branch at 0xc150 targets 0xbce0 and is always taken.
  The `bne` branch at 0xc160 targets 0xbd0c, is taken when ra(?) != at(=0x2), and falls through when ra(?) == at(=0x2).
  The `beq` branch at 0xc174 targets 0xc474, is taken when (v0(=[ret(hwgraph_fastinfo_get)+2168]) & 0x1) == 0, and falls through when (v0(=[ret(hwgraph_fastinfo_get)+2168]) & 0x1) != 0.
  The `bne` branch at 0xc180 targets 0xbd08, is taken when (v0(?) & 0x2) != 0, and falls through when (v0(?) & 0x2) == 0.
  The `beq` branch at 0xc19c targets 0xbd08 and is always taken.
  The `bne` branch at 0xc1a8 targets 0xbd34, is taken when (at(=0x200000) & v0(=ret(pcireg_device_get))) != 0, and falls through when (at(=0x200000) & v0(=ret(pcireg_device_get))) == 0.
  The `bne` branch at 0xc1b4 targets 0xc1e4, is taken when v0(?) != v1(=0x10a9), and falls through when v0(?) == v1(=0x10a9).
  The `beq` branch at 0xc1c4 targets 0xbd34, is taken when a0(?) == a1(=0x3), and falls through when a0(?) != a1(=0x3).
  The `beq` branch at 0xc1d0 targets 0xbd34, is taken when a2(?) == a3(=0x2), and falls through when a2(?) != a3(=0x2).
  The `beq` branch at 0xc1dc targets 0xbd34, is taken when a4(?) == a5(=0x5), and falls through when a4(?) != a5(=0x5).
  The `beq` branch at 0xc1f8 targets 0xc3fc, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == a6(=0x7), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != a6(=0x7).
  The `beq` branch at 0xc200 targets 0xc42c, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == a7(=0x5), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != a7(=0x5).
  The `beq` branch at 0xc208 targets 0xc3dc, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == t0(=0x2), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != t0(=0x2).
  The `beq` branch at 0xc210 targets 0xc3dc, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == t1(=0x3), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != t1(=0x3).
  The `beq` branch at 0xc218 targets 0xc45c, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xc224 targets 0xc370, is taken when t2(=(ret(do_pcibr_config_get) << 0x3)) >= 0x100 (unsigned), and falls through when t2(=(ret(do_pcibr_config_get) << 0x3)) < 0x100 (unsigned).
  The `beq` branch at 0xc238 targets 0xc378 and is always taken.
  The `beq` branch at 0xc240 targets 0xbce0 and is always taken.
  The `beq` branch at 0xc2a0 targets 0xbc94 and is always taken.
  The `beq` branch at 0xc2ac targets 0xba44 and is always taken.
  The `beq` branch at 0xc2b8 targets 0xc0dc and is always taken.
  The `beq` branch at 0xc2c0 targets 0xbafc and is always taken.
  The `beq` branch at 0xc2d8 targets 0xbbf8 and is always taken.
  The `beq` branch at 0xc2e8 targets 0xbb70 and is always taken.
  The `beq` branch at 0xc2f0 targets 0xbafc and is always taken.
  The `beq` branch at 0xc2f8 targets 0xbd9c and is always taken.
  The `beq` branch at 0xc314 targets 0xc048 and is always taken.
  The `beq` branch at 0xc31c targets 0xbd9c and is always taken.
  The `beq` branch at 0xc338 targets 0xc3cc, is taken when a3(=0xff) == s0(=a1), and falls through when a3(=0xff) != s0(=a1).
  The `beq` branch at 0xc348 targets 0xc3d4, is taken when a4(=[ret(hwgraph_fastinfo_get)+114]:2) == a5(=0x2), and falls through when a4(=[ret(hwgraph_fastinfo_get)+114]:2) != a5(=0x2).
  The `beq` branch at 0xc368 targets 0xbd60 and is always taken.
  The `beq` branch at 0xc390 targets 0xc41c, is taken when a4(=0xff) == s0(=a1), and falls through when a4(=0xff) != s0(=a1).
  The `beq` branch at 0xc3a0 targets 0xc424, is taken when a5(=[ret(hwgraph_fastinfo_get)+114]:2) == a6(=0x2), and falls through when a5(=[ret(hwgraph_fastinfo_get)+114]:2) != a6(=0x2).
  The `beq` branch at 0xc3c4 targets 0xbd38 and is always taken.
  The `beq` branch at 0xc3cc targets 0xc350 and is always taken.
  The `beq` branch at 0xc3d4 targets 0xc350 and is always taken.
  The `beq` branch at 0xc3e0 targets 0xc494, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xc3ec targets 0xc454, is taken when a3(=(ret(do_pcibr_config_get) << 0x4)) >= 0x100 (unsigned), and falls through when a3(=(ret(do_pcibr_config_get) << 0x4)) < 0x100 (unsigned).
  The `beq` branch at 0xc3f4 targets 0xc230 and is always taken.
  The `beq` branch at 0xc400 targets 0xc49c, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xc40c targets 0xc464, is taken when a4(=(ret(do_pcibr_config_get) << 0x5)) >= 0x100 (unsigned), and falls through when a4(=(ret(do_pcibr_config_get) << 0x5)) < 0x100 (unsigned).
  The `beq` branch at 0xc414 targets 0xc230 and is always taken.
  The `beq` branch at 0xc41c targets 0xc3a8 and is always taken.
  The `beq` branch at 0xc424 targets 0xc3a8 and is always taken.
  The `beq` branch at 0xc430 targets 0xc4a4, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xc444 targets 0xc46c, is taken when a5(?) >= 0x100 (unsigned), and falls through when a5(?) < 0x100 (unsigned).
  The `beq` branch at 0xc44c targets 0xc230 and is always taken.
  The `beq` branch at 0xc454 targets 0xc370 and is always taken.
  The `beq` branch at 0xc45c targets 0xc370 and is always taken.
  The `beq` branch at 0xc464 targets 0xc370 and is always taken.
  The `beq` branch at 0xc46c targets 0xc370 and is always taken.
  The `beq` branch at 0xc48c targets 0xc17c and is always taken.
  The `beq` branch at 0xc494 targets 0xc370 and is always taken.
  The `beq` branch at 0xc49c targets 0xc370 and is always taken.
  The `beq` branch at 0xc4a4 targets 0xc370 and is always taken.
  The `beq` branch at 0xc4c8 targets 0xbcc0 and is always taken.
  The `beq` branch at 0xc504 targets 0xbdc0 and is always taken.
  The return at 0xba60 has v0 = one of 0x0, 0x1, 0x13, 0x16.

- `pcibr_find_capability` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xc50c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xc50c-0xc5e4 (216 bytes).
  It occupies 216 bytes.
  The `jal` at 0xc528 calls do_pcibr_config_get with a0=a0 at entry (arg0), a1=0x6, a2=0x2, a3=a3 at entry (arg3).
  The `jal` at 0xc54c calls do_pcibr_config_get with a0=a0 at entry (arg0), a1=0x34, a2=0x1, a3=?.
  The `jal` at 0xc574 calls do_pcibr_config_get with a0=a0 at entry (arg0), a1=?, a2=0x1, a3=?.
  The `jal` at 0xc59c calls do_pcibr_config_get with a0=a0 at entry (arg0), a1=?, a2=0x1, a3=?.
  The `beq` branch at 0xc53c targets 0xc5dc, is taken when (v0(=ret(do_pcibr_config_get)) & 0x10) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0x10) != 0.
  The `beq` branch at 0xc55c targets 0xc5d4, is taken when (v0(=ret(do_pcibr_config_get)) & 0xfc) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0xfc) != 0.
  The `beq` branch at 0xc564 targets 0xc598 and is always taken.
  The `beq` branch at 0xc584 targets 0xc5d4, is taken when (v0(=ret(do_pcibr_config_get)) & 0xfc) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0xfc) != 0.
  The `beq` branch at 0xc590 targets 0xc5d4, is taken when s2(?) >= 0x31 (signed), and falls through when s2(?) < 0x31 (signed).
  The `bne` branch at 0xc5a8 targets 0xc56c, is taken when s3(=a1) != t9(=(ret(do_pcibr_config_get) << 0x0)), and falls through when s3(=a1) == t9(=(ret(do_pcibr_config_get) << 0x0)).
  The `beq` branch at 0xc5d4 targets 0xc5b8 and is always taken.
  The `beq` branch at 0xc5dc targets 0xc5bc and is always taken.
  The return at 0xc5cc has v0 = one of ?, 0x0.

- `pcibr_slot_info_free` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xc5e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xc5e4-0xc66c (136 bytes).
  It occupies 136 bytes.
  The `lbu` at 0xc604 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xc63c loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xc65c loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `sw` at 0xc660 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `jal` at 0xc5f4 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc644 calls pcibr_device_info_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a4=0x16.
  The `jal` at 0xc658 calls kmem_free with a0=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8, a1=([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272] << 0x3), a2=?, a3=?.
  The `beq` branch at 0xc5fc targets 0xc618, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0xc610 targets 0xc62c, is taken when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xc664 targets 0xc618 and is always taken.
  The return at 0xc624 has v0 = one of 0x0, 0x16.

- `pcibr_slot_pcix_rbar_init` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xc66c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xc66c-0xc9e4 (888 bytes).
  It occupies 888 bytes.
  The `lbu` at 0xc684 loads 1 byte from a0 (arg0 at entry) +0x39.
  The `lw` at 0xc6c0 loads 4 bytes from (a0 + (a1 << 0x7)) +0x110.
  The `ld` at 0xc6cc loads 8 bytes from (a0 + (a1 << 0x7)) +0x118.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0xc6e4, `lh` at 0xc900.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xc700, `lw` at 0xc710, `lw` at 0xc798.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x518, including `lw` at 0xc750, `lw` at 0xc8a0, `lw` at 0xc930.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x514, including `lw` at 0xc75c, `lw` at 0xc8ac, `lw` at 0xc93c.
  5 such `lw` accesses load 4 bytes from table(sym(max_splittrans_to_numbuf)) +0x0, including `lw` at 0xc77c, `lw` at 0xc788, `lw` at 0xc810.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xc7b8, `ld` at 0xc7d8.
  6 such `lw` accesses load 4 bytes from ?, including `lw` at 0xc7cc, `lw` at 0xc7ec, `lw` at 0xc838.
  3 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0xc7e4, `lhu` at 0xc8c4, `lhu` at 0xc954.
  The `lw` at 0xc7e8 loads 4 bytes from a0 (arg0 at entry) +0x510.
  4 such `sh` accesses store 2 bytes to ?, including `sh` at 0xc898, `sh` at 0xc8e0, `sh` at 0xc928.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x518, including `sw` at 0xc8b4, `sw` at 0xc944.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x514, including `sw` at 0xc8bc, `sw` at 0xc94c.
  The `ld` at 0xc9e0 loads 8 bytes from [(a0 + (a1 << 0x7))+280]:8 +0x0.
  The `jal` at 0xc704 calls pcibr_debug with a0=0x40, a1=[a0+4], a2=sym(.rodata)+10976, a3=?.
  The `jal` at 0xc714 calls pcibr_debug with a0=0x40, a1=[a0+4], a2=sym(.rodata)+10976, a3=?.
  The `jal` at 0xc784 calls sprintf with a0=sp-352, a1=sym(.rodata)+10976, a2=?, a3=?, a4=entry(sym(max_splittrans_to_numbuf)), a5=entry(sym(max_splittrans_to_numbuf)), a6=[a0+1300], a7=[a0+1304].
  The `jal` at 0xc79c calls pcibr_debug with a0=0x40, a1=[a0+4], a2=sym(.rodata)+10976, a3=sp-352.
  The `beq` branch at 0xc6b8 targets 0xc9b4, is taken when a1 >= at(=[a0+57]:1+1) (signed), and falls through when a1 < at(=[a0+57]:1+1) (signed).
  The `blez` branch at 0xc6c4 targets 0xc9c4, is taken when s6(=[(a0 + (a1 << 0x7))+272]) <= 0 (signed), and falls through when s6(=[(a0 + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xc6d0 targets 0xc9cc, is taken when s3(=[(a0 + (a1 << 0x7))+280]:8) == 0, and falls through when s3(=[(a0 + (a1 << 0x7))+280]:8) != 0.
  The `beq` branch at 0xc6dc targets 0xc9bc, is taken when v0(=0xff) == a1, and falls through when v0(=0xff) != a1.
  The `beq` branch at 0xc6ec targets 0xc6f8, is taken when v1(=[a0+114]:2) == a0(=0x2), and falls through when v1(=[a0+114]:2) != a0(=0x2).
  The `blez` branch at 0xc71c targets 0xc984, is taken when s6(=[(a0 + (a1 << 0x7))+272]) <= 0 (signed), and falls through when s6(=[(a0 + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xc73c targets 0xc9d4 and is always taken.
  The `beq` branch at 0xc7b0 targets 0xc980, is taken when s2(?) >= s6(=[(a0 + (a1 << 0x7))+272]) (signed), and falls through when s2(?) < s6(=[(a0 + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xc7c4 targets 0xc7a4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xc7d0 targets 0xc7a4, is taken when a5(?) == s5(=-0x1), and falls through when a5(?) != s5(=-0x1).
  The `beq` branch at 0xc7dc targets 0xc7a4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xc7fc targets 0xc914, is taken when a7(=[a0+1296]) >= 0x64 (signed), and falls through when a7(=[a0+1296]) < 0x64 (signed).
  The `bne` branch at 0xc840 targets 0xc884, is taken when a2(?) < a6(?) (signed), and falls through when a2(?) >= a6(?) (signed).
  The `beq` branch at 0xc854 targets 0xc880, is taken when v0(?) >= 0x7 (signed), and falls through when v0(?) < 0x7 (signed).
  The `bne` branch at 0xc864 targets 0xc884, is taken when a2(?) < t0(?) (signed), and falls through when a2(?) >= t0(?) (signed).
  The `bne` branch at 0xc878 targets 0xc838, is taken when v0(?) < 0x7 (signed), and falls through when v0(?) >= 0x7 (signed).
  The `beq` branch at 0xc8f0 targets 0xc7a4, is taken when (v0(=[sym(pcibr_debug_mask)]) & 0x40) == 0, and falls through when (v0(=[sym(pcibr_debug_mask)]) & 0x40) != 0.
  The `beq` branch at 0xc8f8 targets 0xc978, is taken when v1(=0xff) == s4(=a1), and falls through when v1(=0xff) != s4(=a1).
  The `bne` branch at 0xc904 targets 0xc744, is taken when a0(=[a0+114]:2) != a1(=0x2), and falls through when a0(=[a0+114]:2) == a1(=0x2).
  The `beq` branch at 0xc90c targets 0xc748 and is always taken.
  The `beq` branch at 0xc970 targets 0xc8e4 and is always taken.
  The `beq` branch at 0xc978 targets 0xc748 and is always taken.
  The `beq` branch at 0xc9b4 targets 0xc988 and is always taken.
  The `beq` branch at 0xc9bc targets 0xc6f8 and is always taken.
  The `beq` branch at 0xc9c4 targets 0xc988 and is always taken.
  The `beq` branch at 0xc9cc targets 0xc988 and is always taken.
  The `beq` branch at 0xc9dc targets 0xc7bc and is always taken.
  The return at 0xc9ac has v0 = one of 0x0, 0x16.

- `pcibr_slot_addr_space_init` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xc9e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xc9e4-0xd048 (1636 bytes).
  It occupies 1636 bytes.
  The `lbu` at 0xca0c loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xca2c loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100.
  The `ld` at 0xca34 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `lw` at 0xca74 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xca9c loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  5 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0xcaf8, `lh` at 0xcc3c, `lh` at 0xcd1c.
  6 such `lw` accesses load 4 bytes from ?, including `lw` at 0xcb2c, `lw` at 0xcbb8, `lw` at 0xccd8.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xcb34, `sd` at 0xcb3c, `sd` at 0xcd60.
  6 such `ld` accesses load 8 bytes from ?, including `ld` at 0xcba8, `ld` at 0xccc0, `ld` at 0xccc4.
  The `ld` at 0xcc78 loads 8 bytes from table(sym(pci_space)) +0x0.
  The `jal` at 0xc9f8 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xcae4 calls do_pcibr_config_set with a0=?, a1=0x0, a2=0x4, a3=ret(pcibr_bus_addr_alloc).
  The `jal` at 0xcb24 calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=?, a5=ret(pcibr_bus_addr_alloc).
  The `jal` at 0xcb4c calls do_pcibr_config_get with a0=?, a1=0x4, a2=0x4, a3=?, a4=0x9004.
  The `jal` at 0xcb84 calls do_pcibr_config_set with a0=?, a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xcbd4 calls pcibr_func_config_addr with a0=?, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xcbec calls do_pcibr_config_get with a0=ret(pcibr_func_config_addr), a1=0xe, a2=0x1, a3=?.
  The `jal` at 0xcc74 calls sprintf with a0=sp-464, a1=sym(.rodata)+10976, a2=?, a3=?, a5=entry(sym(pci_space)).
  The `jal` at 0xcc8c calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=sp-464.
  The `jal` at 0xcd40 calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=?, a6=0x4, a7=0xff.
  The `jal` at 0xcd5c calls do_pcibr_config_set with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xcdd0 calls sprintf with a0=sp-464, a1=sym(.rodata)+10976, a2=?, a3=?.
  The `jal` at 0xcde8 calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=sp-464.
  The `jal` at 0xce28 calls sprintf with a0=sp-464, a1=sym(.rodata)+10976, a2=?, a3=?, a7=0xff.
  The `jal` at 0xce40 calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=sp-464.
  The `jal` at 0xce94 calls do_pcibr_config_set with a0=?, a1=0x0, a2=0x4, a3=0xfffff000, a4=one of 0x3, 0x10a9.
  The `jal` at 0xcea4 calls do_pcibr_config_get with a0=?, a1=0x0, a2=0x4, a3=?.
  The `jal` at 0xced0 calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x5, a3=0x0.
  The `jal` at 0xcf2c calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x2, a3=0x0, a6=0x4, a7=0xff.
  The `jal` at 0xcf58 calls do_pcibr_config_get with a0=?, a1=?, a2=0x4, a3=0xff, a4=[sym(pcibr_debug_mask)], a6=0x4, a7=0xff.
  The `jal` at 0xcf80 calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x5, a3=0x0.
  The `jal` at 0xcfd0 calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x4, a3=0x0.
  The `beq` branch at 0xca04 targets 0xcff4, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xca18 targets 0xca5c, is taken when s3(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s3(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xca38 targets 0xca64, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xca5c targets 0xca48 and is always taken.
  The `blez` branch at 0xca94 targets 0xd004, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xcaa0 targets 0xcffc, is taken when a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8) == 0, and falls through when a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8) != 0.
  The `blez` branch at 0xcaac targets 0xd010, is taken when a2(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when a2(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xcad0 targets 0xd03c and is always taken.
  The `beq` branch at 0xcaf0 targets 0xcb08, is taken when a3(=0xff) == s3(=a1), and falls through when a3(=0xff) != s3(=a1).
  The `beq` branch at 0xcafc targets 0xcb08, is taken when a4(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when a4(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xcb38 targets 0xcf04, is taken when a3(?) == a4(=0x9004), and falls through when a3(?) != a4(=0x9004).
  The `beq` branch at 0xcb68 targets 0xcb8c, is taken when (a5(?) & a6(?)) == 0, and falls through when (a5(?) & a6(?)) != 0.
  The `beq` branch at 0xcb98 targets 0xcfa4, is taken when s4(?) >= a4(?) (signed), and falls through when s4(?) < a4(?) (signed).
  The `beq` branch at 0xcbb0 targets 0xcb8c, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `beq` branch at 0xcbbc targets 0xcb90, is taken when a7(?) == t0(=-0x1), and falls through when a7(?) != t0(=-0x1).
  The `blez` branch at 0xcc14 targets 0xce50, is taken when t1(=one of 0x2, 0x6) <= 0 (signed), and falls through when t1(=one of 0x2, 0x6) > 0 (signed).
  The `beq` branch at 0xcc24 targets 0xd02c and is always taken.
  The `beq` branch at 0xcc2c targets 0xcc98, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xcc34 targets 0xceec, is taken when t3(=0xff) == s3(=a1), and falls through when t3(=0xff) != s3(=a1).
  The `beq` branch at 0xcc40 targets 0xcc4c, is taken when t8(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when t8(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xccb4 targets 0xce50, is taken when s0(?) >= a3(?) (signed), and falls through when s0(?) < a3(?) (signed).
  The `beq` branch at 0xccdc targets 0xcc94, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xcce8 targets 0xcc2c, is taken when a6(?) >= s1(?) (unsigned), and falls through when a6(?) < s1(?) (unsigned).
  The `beq` branch at 0xcd04 targets 0xcf1c, is taken when s2(?) == s7(=0x2), and falls through when s2(?) != s7(=0x2).
  The `beq` branch at 0xcd0c targets 0xcf50, is taken when s2(?) == a6(=0x4), and falls through when s2(?) != a6(=0x4).
  The `beq` branch at 0xcd14 targets 0xcd2c, is taken when a7(=0xff) == s3(=a1), and falls through when a7(=0xff) != s3(=a1).
  The `beq` branch at 0xcd20 targets 0xcd2c, is taken when t0(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when t0(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xcd88 targets 0xcc94, is taken when (a6(=[sym(pcibr_debug_mask)]) & 0x800) == 0, and falls through when (a6(=[sym(pcibr_debug_mask)]) & 0x800) != 0.
  The `bne` branch at 0xcd90 targets 0xcdf8, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0xcd98 targets 0xcef4, is taken when a7(=0xff) == s3(=a1), and falls through when a7(=0xff) != s3(=a1).
  The `beq` branch at 0xcda4 targets 0xcdb0, is taken when t0(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when t0(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xcdf0 targets 0xcc98 and is always taken.
  The `beq` branch at 0xcdf8 targets 0xcefc, is taken when a3(=0xff) == s3(=a1), and falls through when a3(=0xff) != s3(=a1).
  The `beq` branch at 0xce04 targets 0xce10, is taken when a4(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when a4(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xce48 targets 0xcc98 and is always taken.
  The `bne` branch at 0xce68 targets 0xce7c, is taken when a3(?) != a4(=0x10a9), and falls through when a3(?) == a4(=0x10a9).
  The `beq` branch at 0xce78 targets 0xcb2c, is taken when a3(?) == a4(=0x3), and falls through when a3(?) != a4(=0x3).
  The `beq` branch at 0xceb0 targets 0xcb2c, is taken when (s0(=0xfffff000) & v0(=ret(do_pcibr_config_get))) == 0, and falls through when (s0(=0xfffff000) & v0(=ret(do_pcibr_config_get))) != 0.
  The `bne` branch at 0xced8 targets 0xcad8, is taken when v0(=ret(pcibr_bus_addr_alloc)) != 0, and falls through when v0(=ret(pcibr_bus_addr_alloc)) == 0.
  The `beq` branch at 0xcee4 targets 0xcb2c and is always taken.
  The `beq` branch at 0xceec targets 0xcc4c and is always taken.
  The `beq` branch at 0xcef4 targets 0xcdb0 and is always taken.
  The `beq` branch at 0xcefc targets 0xce10 and is always taken.
  The `bne` branch at 0xcf0c targets 0xcb40, is taken when t9(?) != ra(=0x1160), and falls through when t9(?) == ra(=0x1160).
  The `beq` branch at 0xcf14 targets 0xcb48 and is always taken.
  The `beq` branch at 0xcf48 targets 0xcd48 and is always taken.
  The `beq` branch at 0xcf70 targets 0xcfc8, is taken when s7(=0x2) == a6(?), and falls through when s7(=0x2) != a6(?).
  The `beq` branch at 0xcf9c targets 0xcd48 and is always taken.
  The `beq` branch at 0xcfc0 targets 0xca44 and is always taken.
  The `beq` branch at 0xcfec targets 0xcd48 and is always taken.
  The `beq` branch at 0xcff4 targets 0xca48 and is always taken.
  The `beq` branch at 0xcffc targets 0xca44 and is always taken.
  The `beq` branch at 0xd008 targets 0xca44 and is always taken.
  The `beq` branch at 0xd024 targets 0xcfa4 and is always taken.
  The `beq` branch at 0xd034 targets 0xccc0 and is always taken.
  The `beq` branch at 0xd040 targets 0xcba4 and is always taken.
  The return at 0xca54 has v0 = one of ?, 0x16.

- `pcibr_slot_device_init` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xd048 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xd048-0xd13c (244 bytes).
  It occupies 244 bytes.
  The `lbu` at 0xd070 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lh` at 0xd0a8 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `sd` at 0xd0dc stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x138.
  The `lw` at 0xd114 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x78.
  The `jal` at 0xd05c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd0a0 calls pcireg_device_get with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xd0e0 calls pcireg_device_set with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?, a7=0x8000000.
  The `jal` at 0xd100 calls pcibr_debug with a0=0x4000000, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=a1 at entry (arg1), a5=sym(device_bits).
  The `beq` branch at 0xd068 targets 0xd084, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0xd07c targets 0xd09c, is taken when s1(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s1(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xd0c0 targets 0xd114, is taken when v1(=[ret(hwgraph_fastinfo_get)+114]:2) == a1(=0x2), and falls through when v1(=[ret(hwgraph_fastinfo_get)+114]:2) != a1(=0x2).
  The `beq` branch at 0xd10c targets 0xd084 and is always taken.
  The `beq` branch at 0xd12c targets 0xd0c8, is taken when (a5(?) & 0x2) == 0, and falls through when (a5(?) & 0x2) != 0.
  The `beq` branch at 0xd134 targets 0xd0cc and is always taken.
  The return at 0xd094 has v0 = one of 0x0, 0x16.

- `pcibr_slot_guest_info_init` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xd13c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xd13c-0xd250 (276 bytes).
  It occupies 276 bytes.
  The `lbu` at 0xd168 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xd184 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  3 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100, including `lw` at 0xd190, `lw` at 0xd22c, `lw` at 0xd244.
  The `lbu` at 0xd19c loads 1 byte from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x104.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x108, including `lw` at 0xd1a8, `lw` at 0xd1c0.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + ([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+260]:1 << 0x7)) +0x108, including `lw` at 0xd1b8, `lw` at 0xd1c4.
  The `sd` at 0xd21c stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `sw` at 0xd228 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `sw` at 0xd24c stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x108.
  The `jal` at 0xd150 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd1b4 calls hwgraph_edge_add with a0=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264], a1=[(ret(hwgraph_fastinfo_get) + ([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+260]:1 << 0x7))+264], a2=sym(.rodata)+10976, a3=?, a4=0x0.
  The `jal` at 0xd1c8 calls hwgraph_edge_add with a0=[(ret(hwgraph_fastinfo_get) + ([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+260]:1 << 0x7))+264], a1=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264], a2=sym(.rodata)+10976, a3=?.
  The `jal` at 0xd200 calls kmem_zalloc with a0=0x8, a1=0x0, a2=?, a3=?, a4=0x16.
  The `jal` at 0xd224 calls pcibr_device_info_new with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=0xff, a3=-0x1, a4=-0x1, a5=0x1.
  The `jal` at 0xd23c calls pciio_device_info_register with a0=a0 at entry (arg0), a1=ret(pcibr_device_info_new), a2=?, a3=?, a4=0x0, a6=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256].
  The `beq` branch at 0xd160 targets 0xd1f8, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xd174 targets 0xd1f0, is taken when s2(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `blez` branch at 0xd188 targets 0xd200, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xd194 targets 0xd1d4, is taken when a0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when a0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xd1f0 targets 0xd1d8 and is always taken.
  The `beq` branch at 0xd1f8 targets 0xd1d8 and is always taken.
  The `beq` branch at 0xd230 targets 0xd1d4, is taken when a6(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when a6(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xd248 targets 0xd194 and is always taken.
  The return at 0xd1e8 has v0 = one of 0x0, 0x16.

- `pcibr_slot_call_device_attach` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xd250 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xd250-0xd48c (572 bytes).
  It occupies 572 bytes.
  The `lbu` at 0xd280 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xd29c loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100.
  The `lw` at 0xd2d0 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x0.
  The `lw` at 0xd2e0 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xd2e4 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xd33c, `sw` at 0xd420, `sw` at 0xd44c.
  The `ld` at 0xd364 loads 8 bytes from ?.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd374, `lw` at 0xd384, `lw` at 0xd414.
  The `lh` at 0xd3cc loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `jal` at 0xd268 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd2cc calls async_attach_get_info with a0=[ret(hwgraph_fastinfo_get)], a1=?, a2=?, a3=?.
  The `jal` at 0xd32c calls pcibr_debug with a0=0x2000, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=?, a5=a2 at entry (arg2), a6=ret(pciio_device_attach).
  The `jal` at 0xd38c calls device_admin_info_get with a0=?, a1=sym(.rodata)+10976, a2=?, a3=?.
  The `jal` at 0xd3a8 calls async_attach_add_info with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd3b4 calls pciio_device_attach with a0=?, a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0xd45c calls vertex_to_name with a0=?, a1=sp-384, a2=0x100, a3=?.
  The `jal` at 0xd470 calls cmn_err with a0=0x4, a1=sym(.rodata)+10976, a2=sp-384, a3=?.
  The `beq` branch at 0xd278 targets 0xd2a8, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xd28c targets 0xd2c4, is taken when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xd2a0 targets 0xd2cc, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xd2c4 targets 0xd2ac and is always taken.
  The `blez` branch at 0xd2f8 targets 0xd450, is taken when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xd308 targets 0xd480 and is always taken.
  The `beq` branch at 0xd354 targets 0xd3e0, is taken when s2(?) >= a4(?) (signed), and falls through when s2(?) < a4(?) (signed).
  The `beq` branch at 0xd36c targets 0xd348, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0xd378 targets 0xd34c, is taken when a7(?) == t0(=-0x1), and falls through when a7(?) != t0(=-0x1).
  The `bne` branch at 0xd394 targets 0xd458, is taken when v0(=ret(device_admin_info_get)) != 0, and falls through when v0(=ret(device_admin_info_get)) == 0.
  The `beq` branch at 0xd3a0 targets 0xd3b0, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xd3c4 targets 0xd310, is taken when a0(=0xff) == s0(=a1), and falls through when a0(=0xff) != s0(=a1).
  The `bne` branch at 0xd3d0 targets 0xd310, is taken when a3(=[ret(hwgraph_fastinfo_get)+114]:2) != a4(=0x2), and falls through when a3(=[ret(hwgraph_fastinfo_get)+114]:2) == a4(=0x2).
  The `beq` branch at 0xd3d8 targets 0xd310 and is always taken.
  The `beq` branch at 0xd3e4 targets 0xd430, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xd3f4 targets 0xd428, is taken when s3(?) == a5(=0x13), and falls through when s3(?) != a5(=0x13).
  The `beq` branch at 0xd3fc targets 0xd428, is taken when s3(?) == v0(=0x2a), and falls through when s3(?) != v0(=0x2a).
  The `beq` branch at 0xd408 targets 0xd428, is taken when s3(?) == a6(=0x1), and falls through when s3(?) != a6(=0x1).
  The `beq` branch at 0xd428 targets 0xd2a8 and is always taken.
  The `beq` branch at 0xd448 targets 0xd424 and is always taken.
  The `beq` branch at 0xd450 targets 0xd424 and is always taken.
  The `beq` branch at 0xd478 targets 0xd34c and is always taken.
  The `beq` branch at 0xd484 targets 0xd360 and is always taken.
  The return at 0xd2bc has v0 = one of ?, 0x16.

- `pcibr_slot_call_device_detach` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xd48c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xd48c-0xd6ec (608 bytes).
  It occupies 608 bytes.
  The `lbu` at 0xd4c4 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xd4e0 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100.
  The `lw` at 0xd520 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xd524 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `sw` at 0xd580 stores 4 bytes to ?.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xd5a8, `ld` at 0xd5d4, `ld` at 0xd5ec.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd5b8, `lw` at 0xd5f0, `lw` at 0xd614.
  The `lh` at 0xd5c4 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x74.
  The `lw` at 0xd5e0 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x508.
  The `sw` at 0xd5e8 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x508.
  The `lw` at 0xd600 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x50c.
  The `lw` at 0xd608 loads 4 bytes from table(sym(max_splittrans_to_numbuf)) +0x0.
  The `sw` at 0xd610 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x50c.
  The `lh` at 0xd638 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x10c, including `lw` at 0xd680, `lw` at 0xd6bc.
  2 such `sw` accesses store 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x10c, including `sw` at 0xd68c, `sw` at 0xd6d0.
  The `jal` at 0xd4a8 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd574 calls pcibr_debug with a0=0x4000, a1=a0 at entry (arg0), a2=sym(.rodata)+10976, a3=?, a5=a2 at entry (arg2), a6=ret(pciio_device_detach).
  The `jal` at 0xd61c calls pciio_device_detach with a0=?, a1=a2 at entry (arg2), a2=?, a3=?, a5=-0x1.
  The `jal` at 0xd6b0 calls pcibr_device_unregister with a0=?, a1=-0x1, a2=?, a3=?.
  The `beq` branch at 0xd4bc targets 0xd4ec, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xd4d0 targets 0xd510, is taken when s3(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s3(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xd4e4 targets 0xd518, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xd510 targets 0xd4f0 and is always taken.
  The `blez` branch at 0xd538 targets 0xd6d4, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xd554 targets 0xd6dc and is always taken.
  The `beq` branch at 0xd598 targets 0xd64c, is taken when s0(?) >= a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed), and falls through when s0(?) < a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xd5b0 targets 0xd588, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xd5bc targets 0xd58c, is taken when a4(?) == a5(=-0x1), and falls through when a4(?) != a5(=-0x1).
  The `beq` branch at 0xd5cc targets 0xd614, is taken when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xd5d8 targets 0xd614, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xd630 targets 0xd560, is taken when a0(=0xff) == s3(=a1), and falls through when a0(=0xff) != s3(=a1).
  The `bne` branch at 0xd63c targets 0xd55c, is taken when t8(=[ret(hwgraph_fastinfo_get)+114]:2) != t9(=0x2), and falls through when t8(=[ret(hwgraph_fastinfo_get)+114]:2) == t9(=0x2).
  The `beq` branch at 0xd644 targets 0xd560 and is always taken.
  The `beq` branch at 0xd650 targets 0xd698, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0xd668 targets 0xd690, is taken when s4(?) == ra(=0x13), and falls through when s4(?) != ra(=0x13).
  The `beq` branch at 0xd670 targets 0xd690, is taken when s4(?) == v0(=0x2a), and falls through when s4(?) != v0(=0x2a).
  The `beq` branch at 0xd678 targets 0xd690, is taken when s4(?) == at(=0x1), and falls through when s4(?) != at(=0x1).
  The `beq` branch at 0xd690 targets 0xd4ec and is always taken.
  The `beq` branch at 0xd6a8 targets 0xd6b8, is taken when a1(=-0x1) == s8(?), and falls through when a1(=-0x1) != s8(?).
  The `beq` branch at 0xd6cc targets 0xd690 and is always taken.
  The `beq` branch at 0xd6d4 targets 0xd690 and is always taken.
  The `beq` branch at 0xd6e4 targets 0xd5a4 and is always taken.
  The return at 0xd508 has v0 = one of ?, 0x16.

- `pcibr_slot_detach` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xd6ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xd6ec-0xd7cc (224 bytes).
  It occupies 224 bytes.
  The `sw` at 0xd764 stores 4 bytes to a4 (arg4 at entry) +0x0.
  The `lh` at 0xd770 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x74.
  The `sw` at 0xd780 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x518.
  The `sw` at 0xd784 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x514.
  2 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0xd790, `lbu` at 0xd7b0.
  The `lbu` at 0xd794 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  The `sw` at 0xd7a0 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x510.
  The `jal` at 0xd70c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd71c calls pcibr_is_slot_sys_critical with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xd74c calls pcibr_slot_call_device_detach with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xd788 calls pcibr_pcix_rbars_calc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xd7a8 calls pcibr_slot_pcix_rbar_init with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xd724 targets 0xd748, is taken when v0(=ret(pcibr_is_slot_sys_critical)) == 0, and falls through when v0(=ret(pcibr_is_slot_sys_critical)) != 0.
  The `beq` branch at 0xd754 targets 0xd770, is taken when v0(=ret(pcibr_slot_call_device_detach)) == 0, and falls through when v0(=ret(pcibr_slot_call_device_detach)) != 0.
  The `beq` branch at 0xd75c targets 0xd768, is taken when a0(=a4) == 0, and falls through when a0(=a4) != 0.
  The `beq` branch at 0xd768 targets 0xd730 and is always taken.
  The `beq` branch at 0xd778 targets 0xd7c4, is taken when (at(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (at(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `bne` branch at 0xd79c targets 0xd7c4, is taken when v1(=[ret(hwgraph_fastinfo_get)+57]:1) < s1(=[ret(hwgraph_fastinfo_get)+56]:1) (signed), and falls through when v1(=[ret(hwgraph_fastinfo_get)+57]:1) >= s1(=[ret(hwgraph_fastinfo_get)+56]:1) (signed).
  The `beq` branch at 0xd7bc targets 0xd7a8, is taken when a0(=[ret(hwgraph_fastinfo_get)+57]:1) >= s1(?) (signed), and falls through when a0(=[ret(hwgraph_fastinfo_get)+57]:1) < s1(?) (signed).
  The `beq` branch at 0xd7c4 targets 0xd730 and is always taken.
  The return at 0xd740 has v0 = one of 0x0, 0x4, 0x1a.

- `pcibr_is_slot_sys_critical` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xd7cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xd7cc-0xd8dc (272 bytes).
  It occupies 272 bytes.
  The `lbu` at 0xd800 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xd818 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xd820 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `ld` at 0xd840 loads 8 bytes from ?.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd84c, `lw` at 0xd858.
  The `jal` at 0xd7d8 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd864 calls vertex_to_name with a0=?, a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0xd86c calls is_sys_critical_vertex with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd8cc calls cmn_err with a0=0x4, a1=sym(.rodata)+10976, a2=sp-304, a3=?.
  The `beq` branch at 0xd7f8 targets 0xd8b8, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xd810 targets 0xd8b0, is taken when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `blez` branch at 0xd81c targets 0xd888, is taken when s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xd824 targets 0xd838 and is always taken.
  The `beq` branch at 0xd834 targets 0xd888, is taken when s0(?) >= s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed), and falls through when s0(?) < s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xd844 targets 0xd82c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xd850 targets 0xd82c, is taken when v1(?) == s4(=-0x1), and falls through when v1(?) != s4(=-0x1).
  The `bne` branch at 0xd874 targets 0xd8c0, is taken when v0(=ret(is_sys_critical_vertex)) != 0, and falls through when v0(=ret(is_sys_critical_vertex)) == 0.
  The `bne` branch at 0xd880 targets 0xd83c, is taken when s0(?) < s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed), and falls through when s0(?) >= s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xd8b0 targets 0xd890 and is always taken.
  The `beq` branch at 0xd8b8 targets 0xd890 and is always taken.
  The `beq` branch at 0xd8d4 targets 0xd88c and is always taken.
  The return at 0xd8a8 has v0 = one of 0x0, 0x1, 0x16.

- `pcibr_probe_slot` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xd8dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xd8dc-0xd8fc (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0xd8e8 calls pcibr_probe_work [0xd94c] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x4, a3=a2 at entry (arg2).
  The return at 0xd8f4 has v0 = ret(pcibr_probe_work).

- `pcibr_piomap_probe` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xd8fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xd8fc-0xd94c (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0xd8fc loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0xd92c loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ld` at 0xd930 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `ld` at 0xd934 loads 8 bytes from [a0+64]:8 +0x8.
  The `jal` at 0xd938 calls pcibr_probe_work [0xd94c] with a0=[[a0+64]:8+8]:8, a1=(a1 + [a0+32]:8), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=-0x1, a7=a0 at entry (arg0).
  The `beq` branch at 0xd918 targets 0xd92c, is taken when at(=[a0+24]:8) >= v1(=(a2 + a1)) (unsigned), and falls through when at(=[a0+24]:8) < v1(=(a2 + a1)) (unsigned).
  The `beq` branch at 0xd944 targets 0xd920 and is always taken.
  The return at 0xd924 has v0 = one of -0x1, ret(pcibr_probe_work).

- `pcibr_probe_work` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xd94c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xd94c-0xda18 (204 bytes).
  It occupies 204 bytes.
  The `jal` at 0xd9c4 calls pcibr_disable_mst_timeout_work [0xda60] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x4.
  The `jal` at 0xd9d8 calls badaddr_val with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0xd9ec calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=0x40, a2=?, a3=?.
  The `jal` at 0xda00 calls pcibr_enable_mst_timeout_work [0xdab4] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xd974 targets 0xd9a0, is taken when a2 == at(=0x1), and falls through when a2 != at(=0x1).
  The `beq` branch at 0xd980 targets 0xd9a0, is taken when a2 == v1(=0x2), and falls through when a2 != v1(=0x2).
  The `beq` branch at 0xd988 targets 0xd9a0, is taken when a2 == a6(=0x4), and falls through when a2 != a6(=0x4).
  The `beq` branch at 0xd990 targets 0xd9a0, is taken when a2 == t0(=0x8), and falls through when a2 != t0(=0x8).
  The `beq` branch at 0xd998 targets 0xd9b8 and is always taken.
  The `beq` branch at 0xd9ac targets 0xd9c4, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xd9f8 targets 0xda0c, is taken when a0(=(ret(pcibr_disable_mst_timeout_work) << 0x0)) == 0, and falls through when a0(=(ret(pcibr_disable_mst_timeout_work) << 0x0)) != 0.
  The `beq` branch at 0xda10 targets 0xd9b4 and is always taken.
  The return at 0xd9bc has v0 = one of -0x1, ?.

- `pcibr_disable_mst_timeout` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xda18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xda18-0xda3c (36 bytes).
  It occupies 36 bytes.
  The `ld` at 0xda2c loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `jal` at 0xda20 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xda28 calls pcibr_disable_mst_timeout_work [0xda60] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=?, a2=?, a3=?.
  The return at 0xda34 has v0 = ret(pcibr_disable_mst_timeout_work).

- `pcibr_enable_mst_timeout` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xda3c (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xda3c-0xda60 (36 bytes).
  It occupies 36 bytes.
  The `ld` at 0xda50 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `jal` at 0xda44 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xda4c calls pcibr_enable_mst_timeout_work [0xdab4] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=?, a2=?, a3=?.
  The return at 0xda58 has v0 = ret(pcibr_enable_mst_timeout_work).

- `pcibr_disable_mst_timeout_work` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xda60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xda60-0xdab4 (84 bytes).
  It occupies 84 bytes.
  The `jal` at 0xda70 calls pcireg_intr_enable_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xda80 calls pcireg_intr_enable_bit_clr with a0=a0 at entry (arg0), a1=0x400000800, a2=?, a3=?.
  The `jal` at 0xda88 calls pcireg_intr_enable_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0xda94 targets 0xdaa4, is taken when s8(=ret(pcireg_intr_enable_get)) != v0(=ret(pcireg_intr_enable_get)), and falls through when s8(=ret(pcireg_intr_enable_get)) == v0(=ret(pcireg_intr_enable_get)).
  The `beq` branch at 0xda9c targets 0xdaa8 and is always taken.
  The return at 0xdaac has v0 = one of 0x0, 0x1.

- `pcibr_enable_mst_timeout_work` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xdab4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xdab4-0xdb08 (84 bytes).
  It occupies 84 bytes.
  The `jal` at 0xdac4 calls pcireg_intr_enable_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xdad4 calls pcireg_intr_enable_bit_set with a0=a0 at entry (arg0), a1=0x400000800, a2=?, a3=?.
  The `jal` at 0xdadc calls pcireg_intr_enable_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0xdae8 targets 0xdaf8, is taken when s8(=ret(pcireg_intr_enable_get)) != v0(=ret(pcireg_intr_enable_get)), and falls through when s8(=ret(pcireg_intr_enable_get)) == v0(=ret(pcireg_intr_enable_get)).
  The `beq` branch at 0xdaf0 targets 0xdafc and is always taken.
  The return at 0xdb00 has v0 = one of 0x0, 0x1.

- `pcibr_device_info_free` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xdb08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xdb08-0xdd40 (568 bytes).
  It occupies 568 bytes.
  The `lw` at 0xdb48 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xdb58 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xdb7c, `ld` at 0xdb88, `ld` at 0xdbf4.
  3 such `ld` accesses load 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118, including `ld` at 0xdbac, `ld` at 0xdbec, `ld` at 0xdd3c.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xdbc0, `sd` at 0xdcb4, `sd` at 0xdcc8.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xdc64, `lw` at 0xdc70, `lw` at 0xdca0.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0xdc88, `sw` at 0xdcbc.
  The `sw` at 0xdcec stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x144.
  The `sw` at 0xdcf0 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x148.
  The `sw` at 0xdcf4 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x14c.
  The `sd` at 0xdcfc stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x150.
  The `sw` at 0xdd00 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x158.
  The `sw` at 0xdd04 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x168.
  The `sw` at 0xdd08 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x16c.
  The `sd` at 0xdd0c stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x170.
  The `sw` at 0xdd14 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x178.
  The `sd` at 0xdd20 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x160.
  The `jal` at 0xdb24 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xdb94 calls pcibr_bus_addr_free with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0xdba4 calls mutex_io_spinunlock with a0=ret(hwgraph_fastinfo_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xdbbc calls pciio_device_info_unregister with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xdbc4 calls pciio_device_info_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xdbd0 calls kmem_free with a0=?, a1=0x228, a2=?, a3=?.
  The `jal` at 0xdc00 calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0xdc1c calls pcibr_func_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xdc34 calls do_pcibr_config_get with a0=ret(pcibr_func_config_addr), a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xdc4c calls do_pcibr_config_set with a0=ret(pcibr_func_config_addr), a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xdc5c calls pcibr_bus_addr_free with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0xdb60 targets 0xdd30, is taken when s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xdb68 targets 0xdd38 and is always taken.
  The `bne` branch at 0xdb74 targets 0xdc94, is taken when s0(?) < 0x6 (signed), and falls through when s0(?) >= 0x6 (signed).
  The `beq` branch at 0xdb80 targets 0xdba0, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0xdb8c targets 0xdba0, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `beq` branch at 0xdbe4 targets 0xdccc, is taken when s3(?) >= s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed), and falls through when s3(?) < s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xdbf8 targets 0xdbd8, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xdc54 targets 0xdc90 and is always taken.
  The `beq` branch at 0xdc84 targets 0xdcb4, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xdc8c targets 0xdb7c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0xdca4 targets 0xdc5c, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0xdcac targets 0xdb70 and is always taken.
  The `beq` branch at 0xdcc4 targets 0xdc8c and is always taken.
  The `beq` branch at 0xdd30 targets 0xdcd0 and is always taken.
  The `beq` branch at 0xdd38 targets 0xdbf0 and is always taken.
  The return at 0xdd28 has v0 = one of ?, ret(hwgraph_fastinfo_get).

- `pcibr_bus_addr_alloc` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xdd40 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xdd40-0xddd0 (144 bytes).
  It occupies 144 bytes.
  The `jal` at 0xdd94 calls pciio_device_win_alloc with a0=(a0 + one of 0x848, 0x858, 0x868), a1=?, a2=a3 at entry (arg3), a3=a4 at entry (arg4), a4=a5 at entry (arg5).
  The `beq` branch at 0xdd58 targets 0xddb0, is taken when a2 == at(=0x2), and falls through when a2 != at(=0x2).
  The `beq` branch at 0xdd60 targets 0xddc8, is taken when a2 == t0(=0x4), and falls through when a2 != t0(=0x4).
  The `beq` branch at 0xdd68 targets 0xdd78, is taken when a2 == t1(=0x5), and falls through when a2 != t1(=0x5).
  The `beq` branch at 0xdd70 targets 0xdda4 and is always taken.
  The `bne` branch at 0xdd78 targets 0xddbc, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0xddb4 targets 0xdd80, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0xddc0 targets 0xdd84 and is always taken.
  The `beq` branch at 0xddc8 targets 0xddb4 and is always taken.
  The return at 0xdda8 has v0 = one of 0x0, ret(pciio_device_win_alloc).

- `pcibr_bus_addr_free` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xddd0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`.
  Range: 0xddd0-0xddec (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xddd8 calls pciio_device_win_free with a0=a0+32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xdde4 has v0 = ret(pciio_device_win_free).

- `pcireg_id_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xddec
  **Inferred.** Role (from name): reads a bridge register, for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xddf4) and a selector of -1 (the `beq` at 0xde3c) both branch to the `panic` at 0xdf3c. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xde78 to 0xde98) and with 0xc002 (the next `bne`, which goes to the panic when it differs). The return at 0xde48 is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_id_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xddec
  **Inferred.** When a0 is zero it takes the branch [@0xddf4 taken] to a call to panic [call 1, @0xdf3c]. It loads the halfword at a0+0x72 [@0xde10]. It loads the doubleword at a0+0x8 [@0xde1c]. Its return value is one of 0x0 and a value the facts leave open [@0xde48].
  Role (from facts): a halfword read [@0xde10] that feeds a chain of compare branches [@0xde18 taken], with a panic call [call 1] on a zero a0 [@0xddf4 taken].
  Reviewed: 2026-11-12

- `pcireg_stat_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xdf4c
  **Inferred.** Role (from name): reads a bridge register (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xdf54) and a selector of -1 (the `beq` at 0xdf9c) both branch to the `panic` at 0xe0a0. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xdfd8 to 0xdff8) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xe000. The return at 0xdfa8 is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_stat_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xdf4c
  **Inferred.** When a0 is zero it takes the branch [@0xdf54 taken] to a call to panic [call 1, @0xe0a0]. It loads the halfword at a0+0x72 [@0xdf70]. It loads the doubleword at a0+0x8 [@0xdf7c]. Its return value is one of 0x0 and a value the facts leave open [@0xdfa8].
  Role (from facts): a halfword read [@0xdf70] that feeds a chain of compare branches [@0xdf78 taken], with a panic call [call 1] on a zero a0 [@0xdf54 taken].
  Reviewed: 2026-11-12

- `pcireg_bus_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe0b0
  **Inferred.** Role (from name): reads a bus-error register (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xe0b8) and a selector of -1 (the `beq` at 0xe100) both branch to the `panic` at 0xe210. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xe13c to 0xe15c) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xe164. The return at 0xe10c is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_bus_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe0b0
  **Inferred.** When a0 is zero it takes the branch [@0xe0b8 taken] to a call to panic [call 1, @0xe210]. It loads the halfword at a0+0x72 [@0xe0d4]. It loads the doubleword at a0+0x8 [@0xe0e0]. Its return value is one of 0x0 and a value the facts leave open [@0xe10c].
  Role (from facts): a halfword read [@0xe0d4] that feeds a chain of compare branches [@0xe0dc taken], with a panic call [call 1] on a zero a0 [@0xe0b8 taken].
  Reviewed: 2026-11-12

- `pcireg_control_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe220
  **Inferred.** Role (from name): reads a control register (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xe228) and a selector of -1 (the `beq` at 0xe270) both branch to the `panic` at 0xe378. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xe2b0 to 0xe2d0) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xe2d8. The return at 0xe280 is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_control_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe220
  **Inferred.** When a0 is zero it takes the branch [@0xe228 taken] to a call to panic [call 1, @0xe378]. It loads the halfword at a0+0x72 [@0xe244]. It loads the doubleword at a0+0x8 [@0xe250]. Its return value is one of 0x0 and a value the facts leave open [@0xe280].
  Role (from facts): a halfword read [@0xe244] that feeds a chain of compare branches [@0xe24c taken], with a panic call [call 1] on a zero a0 [@0xe228 taken].
  Reviewed: 2026-11-12

- `pcireg_control_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe388
  **Inferred.** Role (from name): writes a control register. It calls `splhi` at 0xe39c and `splx` at 0xe400 and returns at 0xe40c the result of `splx`. The null test is the `beq` at 0xe3a8 (it goes to 0xe4fc) and the selector in the halfword at a0+0x72 is compared with 3, 2, 0 and 1 (0xe3cc to 0xe3e8) and with -1 (the `beq` at 0xe3f0, which goes to the `panic` at 0xe500). A word loaded from +0x4 is compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (0xe43c to 0xe45c) and with 0xc002 (the `bne` at 0xe464, which goes to the panic when it differs). The stores are a `sw` at 0xe474 and `sd` at 0xe490 and 0xe4ac.
  Reviewed: 2026-11-12

- `pcireg_control_bit_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe510
  **Inferred.** Role (from name): clears bits in a control register. It calls `splhi` at 0xe524 and `splx` at 0xe584 and returns at 0xe590 the result of `splx`. It loads a word at 0xe5fc and 0xe610 with a `sw` at 0xe608 between them, and has `ld`/`sd` variants at 0xe624 to 0xe660; which value is written is not shown. The selector in the halfword at a0+0x72 is compared with 3, 2, 0 and 1 (0xe554 to 0xe570) and with -1 (0xe578); a null a0 (0xe530) and -1 both go to 0xe6a8, and the `panic` is at 0xe6ac. A word loaded from +0x4 is compared with the constants 0xe000 to 0xd002 (0xe5c0 to 0xe5e0) and with 0xc002 (the `bne` at 0xe5e8).
  Reviewed: 2026-11-12

- `pcireg_control_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe6bc
  **Inferred.** Role (from name): sets bits in a control register. It calls `splhi` at 0xe6d0 and `splx` at 0xe730 and returns at 0xe73c the result of `splx`. It loads a word at 0xe7a4 and 0xe7b4 with a `sw` at 0xe7ac between them, and has `ld`/`sd` variants at 0xe7c8 to 0xe7fc; which value is written is not shown. The selector in the halfword at a0+0x72 is compared with 3, 2, 0 and 1 (0xe700 to 0xe71c) and with -1 (0xe724); a null a0 (0xe6dc) and -1 both go to 0xe844, and the `panic` is at 0xe848. A word loaded from +0x4 is compared with the constants 0xe000 to 0xd002 (0xe76c to 0xe78c) and with 0xc002 (the `bne` at 0xe794).
  Reviewed: 2026-11-12

- `pcireg_ssram_size_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xe858
  **Inferred.** Role (from name): sets an SSRAM size field. It calls `splhi` at 0xe86c first and `splx` at 0xe8d4, and returns at 0xe8e0 the result of `splx`. The size check comes later and only on the side of the selector test where the halfword at a0+0x72 is 0 (the `beq` at 0xe8bc goes to 0xe94c): `bltz` on a1 at 0xe94c and the `beq` at 0xe958 (taken when a1 is at least 4) both go to 0xea20, and `assfail` at 0xea28 has a2 = 0x158. The selectors 1, 2 and 3 are compared at 0xe89c to 0xe8b4 and -1 at 0xe8c4; `panic` is called at 0xe9fc and 0xea10. A word loaded from +0x4 is compared with 0xe000 to 0xd002 (0xe910 to 0xe934) and with 0xc002 (the `bne` at 0xe93c). The `sw` stores are at 0xe96c and 0xe97c.
  Reviewed: 2026-11-12

- `pcireg_speed_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xea48
  **Inferred.** Role (from name): reads a bus-speed field (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xea50) and a selector of -1 (the `beq` at 0xea98) both branch to the `panic` at 0xebb0. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xead8 to 0xeaf8) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xeb00. The return at 0xeaa8 is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_mode_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xebc0
  **Inferred.** Role (from name): reads a bus-mode field (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xebc8) and a selector of -1 (the `beq` at 0xec10) both branch to the `panic` at 0xed1c. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xec4c to 0xec6c) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xec74. The return at 0xec1c is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_req_timeout_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xed2c
  **Inferred.** Role (from name): reads a request-timeout field (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xed34) and a selector of -1 (the `beq` at 0xed7c) both branch to the `panic` at 0xee80. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xedb8 to 0xedd8) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xede0. The return at 0xed88 is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_req_timeout_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xee90
  **Inferred.** Role (from name): writes a request-timeout field. The null test is the `beq` at 0xee98 (it goes to 0xefd8). The selector in the halfword at a0+0x72 is compared with 3, 2, 0 and 1 (0xeebc to 0xeed8) and with -1 (the `beq` at 0xeee0, which goes to the `panic` at 0xefdc with a1 passed as its argument). A word loaded from +0x4 is compared with 0xe000 to 0xd002 (0xef1c to 0xef3c) and with 0xc002 (the `bne` at 0xef44). The stores are a `sw` at 0xef58 and `sd` at 0xef74 and 0xef90; the facts do not show the stored value. The return at 0xeeec is one of an unresolved value and `ret(panic)`.
  Reviewed: 2026-11-12

- `pcireg_intr_dst_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xefec
  **Inferred.** Role (from name): reads an interrupt-destination register (same shape as `pcireg_id_get`), for the selector in the halfword at a0+0x72. A null a0 (the `beq` at 0xeff4) and a selector of -1 (the `beq` at 0xf03c) both branch to the `panic` at 0xf150. The selector is also compared with 0, 1, 2 and 3. A word loaded from +0x4 is then compared with 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (the `beq` branches from 0xf07c to 0xf09c) and with 0xc002 (the next `bne`, which goes to the panic when it differs) at 0xf0a4. The return at 0xf04c is one of 0x0 and an unresolved value; the facts do not show which path gives which.
  Reviewed: 2026-11-12

- `pcireg_intr_dst_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf160
  **Inferred.** Set-side accessor that takes a pointer in a0 and returns through 0xf1bc. It reads a 16-bit field at +0x72
  (lh at 0xf184), a doubleword at +0x8 and a word at +0x4, and branches on that field against 3, 2, 0, 1 and -1; the -1
  case goes to the panic call at 0xf2b4. Its stores are the words at 0xf228 and 0xf230 and the doublewords at 0xf24c and
  0xf268, chosen by a second comparison chain against 0xe000, 0xe010, 0xd102, 0xd112, 0xd002, 0xc002 and 0x36. The meaning
  of the selector constants and the stored values is not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_intr_dst_target_id_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf2c4
  **Inferred.** Read-side accessor with the same entry shape: a null check on a0 (beq at 0xf2cc), the 16-bit field at +0x72
  (lh at 0xf2e8) dispatched against 2, 3, 0, 1 and -1 (panic call at 0xf420 for -1), and the same second chain of
  comparisons against 0xe000 to 0xd002 and 0xc002, 0x36. It loads a word from an unknown base at 0xf38c and a doubleword at
  0xf3b0 and returns 0 or an unknown value at 0xf324. Which bridge register it reads is not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_intr_dst_target_id_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf430
  **Inferred.** Set-side accessor. It takes a0, tests it for null (beq at 0xf438 to the panic path), and dispatches the
  16-bit field at +0x72 (lh at 0xf454) against 2, 3, 0, 1 and -1. It stores words at 0xf504 and 0xf51c and doublewords at
  0xf540 and 0xf558 on the paths chosen by the 0xe000 to 0xc002 comparison chain, and panics at 0xf5bc with a1 passed
  through. The return at 0xf48c yields a panic result or an unknown value.
  Reviewed: 2026-11-12

- `pcireg_intr_dst_addr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf5cc
  **Inferred.** Read-side accessor that takes a0, checks it for null at 0xf5d4, and dispatches the 16-bit field at +0x72
  (lh at 0xf5f0) against 2, 3, 0, 1 and -1, with -1 going to the panic call at 0xf73c. It loads words at 0xf694 and 0xf698
  and a doubleword at 0xf6c8 from bases the facts do not name, then returns 0 or an unknown value at 0xf62c. The selector
  constants 0xe000 to 0x36 choose among the loads; their meaning is not shown.
  Reviewed: 2026-11-12

- `pcireg_intr_dst_addr_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf74c
  **Inferred.** Set-side accessor. After the null check at 0xf754 and the dispatch on the 16-bit field at +0x72 (lh at
  0xf770, values 2, 3, 0, 1, -1), it stores words at 0xf81c, 0xf830 and 0xf838 and doublewords at 0xf864 and 0xf87c. The
  -1 case panics at 0xf8e0 with a1 passed through. The return at 0xf7a8 yields a panic result or an unknown value.
  Reviewed: 2026-11-12

- `pcireg_cmdword_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf8f0
  **Inferred.** Read-side accessor with a null check at 0xf8f8 and the 16-bit field at +0x72 (lh at 0xf914) dispatched
  against 3, 2, 0, 1 and -1, where the -1 case panics at 0xfa48. The 3 and 2 cases branch to different paths (0xf9dc and
  0xf9f8). It loads a word from an unknown base at 0xf9b8 and doublewords at 0xf9e0 and 0xf9fc. The return at 0xf950 is 0
  or an unknown value. The meaning of the command-word error it may serve is not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_llp_cfg_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xfa58
  **Inferred.** Read-side accessor with a null check at 0xfa5c and the 16-bit field at +0x72 (lh at 0xfa78) dispatched
  against 3, 2, 0, 1 and -1. It has two panic calls. The one at 0xfba8 is the -1 target, and the one at 0xfbbc passes a1
  through and sits just after 0xfbb8, the target of the case-3 branch at 0xfa80. It loads a word at 0xfb1c and a
  doubleword at 0xfb44 from unknown bases, and returns 0 or an unknown value at 0xfab4. The link configuration field it
  name-suggests is not confirmed by the facts.
  Reviewed: 2026-11-12

- `pcireg_llp_cfg_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xfbcc
  **Inferred.** Set-side accessor that calls splhi at 0xfbdc on entry and splx at 0xfc3c before returning, so the body
  likely runs at a raised interrupt level; the callee names are the only basis for that. It dispatches the 16-bit field at
  +0x72 (lh at 0xfc04) against 3, 2, 0, 1 and -1, stores a word at 0xfcb4 and a doubleword at 0xfcd8, and reads a word at
  0xfcbc and a doubleword at 0xfce0. The selector chain runs against 0xe000 to 0x36. Panics occur at 0xfd44 and 0xfd58,
  and the return at 0xfc48 yields the splx result.
  Reviewed: 2026-11-12

- `pcireg_tflush_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xfd68
  **Inferred.** Read-side accessor with a null check at 0xfd70 and the 16-bit field at +0x72 (lh at 0xfd8c) dispatched
  against 3, 2, 0, 1 and -1; -1 goes to the panic call at 0xfecc. A second failure path calls assfail at 0xfee8 with the
  constant 0x30f as its third argument (a2). It loads a word at 0xfe28 and doublewords at 0xfe64 and 0xfe80 from unknown
  bases, and returns an unknown value at 0xfe44. The routine name suggests a flush of pending transactions, but the facts
  do not show the flush itself.
  Reviewed: 2026-11-12

- `pcireg_linkside_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xfef8
  **Inferred.** Read-side accessor with a null check at 0xff00 (beq to the panic path at 0x10048), and the 16-bit field at +0x72
  (lh at 0xff1c) dispatched against 3, 2, 0, 1 and -1. It loads a word at 0xffbc and doublewords at 0xffe4 and 0x10000
  from unknown bases, and returns 0 or an unknown value at 0xff54. The link side it names is not confirmed by the facts.
  Reviewed: 2026-11-12

- `pcireg_resp_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1005c
  **Inferred.** Read-side accessor with a null check at 0x10064 (panic path at 0x101bc) and the 16-bit field at +0x72 (lh
  at 0x10080) dispatched against 3, 2, 0, 1 and -1. It loads words at 0x10124 and 0x10128 and doublewords at 0x10158 and
  0x10174 from unknown bases, and returns 0 or an unknown value at 0x100bc. The response-error role is named, not shown.
  Reviewed: 2026-11-12

- `pcireg_resp_err_addr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x101d0
  **Inferred.** Read-side accessor with a null check at 0x101d8 and the 16-bit field at +0x72 (lh at 0x101f4) dispatched
  against 2, 3, 0, 1 and -1; -1 goes to the panic call at 0x1033c. It loads words at 0x10294 and 0x10298 and a doubleword
  at 0x102c8, and returns 0 or an unknown value at 0x1022c. The address it name-suggests is not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_resp_err_buf_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1034c
  **Inferred.** Read-side accessor with a null check at 0x10354 and the 16-bit field at +0x72 (lh at 0x10370) dispatched
  against 2, 3, 0, 1 and -1; -1 goes to the panic call at 0x104b0. It loads a word at 0x10414 and a doubleword at 0x10440
  from unknown bases, and returns 0 or an unknown value at 0x103ac. The buffer role is named, not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_resp_err_dev_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x104c0
  **Inferred.** Read-side accessor with a null check at 0x104c8 (beq to the panic path at 0x10620) and the 16-bit field at +0x72 (lh at 0x104e4)
  dispatched against 3, 2, 0, 1 and -1. It loads a word at 0x10588 and a doubleword at 0x105b4 from unknown bases, and
  returns 0 or an unknown value at 0x10520. Which device the error names is not shown; the panic call at 0x10624 takes
  only the message and unknown arguments.
  Reviewed: 2026-11-12

- `pcireg_linkside_err_addr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x10634
  **Inferred.** Read-side accessor with the 16-bit field at +0x72 (lh at 0x10658) and a doubleword at +0x8 and a word at
  +0x4 read from a0. It has two panic calls, at 0x10760 and 0x10780, the second with a5 set to 0x24, and returns
  0 or an unknown value at 0x10694. The address role is named, not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_dirmap_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x10790
  **Inferred.** Read-side accessor with the 16-bit field at +0x72 (lh at 0x107b4) dispatched against 2, 3, 0, 1 and -1,
  a word loaded from an unknown base at 0x10858 and doublewords at 0x10880 and 0x1089c. The panic call at 0x108e8 is the only call in the routine.
  The return at 0x107f0 is 0 or an unknown value. The direct-map role is named, not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_dirmap_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x108f8
  **Inferred.** Set-side accessor with the 16-bit field at +0x72 (lh at 0x1091c). It stores a word at 0x109bc and
  doublewords at 0x109d8 and 0x109f4, and calls panic at 0x10a40 with a1 passed through. The return at 0x10950 gives 3, an
  unknown value, or a panic result. The purpose of the stored direct-map values is not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_dirmap_wid_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x10a50
  **Inferred.** Set-side accessor with the 16-bit field at +0x72 (lh at 0x10a74). It stores words at 0x10b20 and 0x10b38 and
  doublewords at 0x10b60 and 0x10b78, and panics at 0x10bdc with a1 passed through. The return at 0x10aa8 gives 2, an
  unknown value, or a panic result. The widget role the name suggests is not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_dirmap_diroff_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x10bec
  **Inferred.** Set-side accessor with the 16-bit field at +0x72 (lh at 0x10c10). It stores words at 0x10cc0 and 0x10cd8
  and six doubleword sites, including 0x10d00, 0x10d14 and 0x10d28, and panics at 0x10dcc with a1 passed through and a5
  set to -1. The return at 0x10c48 is an unknown value or a panic result. The offset role is named, not shown.
  Reviewed: 2026-11-12

- `pcireg_dirmap_add512_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x10ddc
  **Inferred.** Set-side accessor with the 16-bit field at +0x72 (lh at 0x10e00). It reads a word at 0x10ea0, stores a word
  at 0x10eb0 and doublewords at 0x10ed8 and 0x10f00, and panics at 0x10f4c. The return at 0x10e38 is an unknown value or a
  panic result. The 512-entry window the name suggests is not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_dirmap_add512_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x10f5c
  **Inferred.** Set-side accessor with the 16-bit field at +0x72 (lh at 0x10f80). It reads a word at 0x1101c, stores a word
  at 0x11030 and doublewords at 0x1105c and 0x11088, and panics at 0x110d4. The return at 0x10fb4 gives 3, an unknown
  value, or a panic result. The clear role is suggested by the name and its pairing with the add512_set entry, not by
  the facts.
  Reviewed: 2026-11-12

- `pcireg_ssram_parity_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x110e4
  **Inferred.** Read-side accessor with the 16-bit field at +0x72 (lh at 0x11108). It loads a word at 0x111ac from an
  unknown base, and has two panic calls, at 0x11234 and at 0x11248 with a5 set to 0x24. It returns 0 or an
  unknown value at 0x11144. The SSRAM parity role is named, not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_map_fault_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11260
  **Inferred.** Read-side accessor with the 16-bit field at +0x72 (lh at 0x11284). It loads a word at 0x11324 from an
  unknown base, and has two panic calls, at 0x113b8 (a5 set to 0xc002) and 0x113c4. It returns 0 or an unknown
  value at 0x112c0. The map-fault role is named, not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_arbitration_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x113d4
  **Inferred.** Read-side accessor with the 16-bit field at +0x72 (lh at 0x113f8). It loads a word at 0x1149c from an
  unknown base, and panics at 0x1152c. It returns 0 or an unknown value at 0x11434. The arbitration role is named, not
  shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_arbitration_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1153c
  **Inferred.** Set-side accessor with the 16-bit field at +0x72 (lh at 0x11560). It stores a word at 0x11604 and
  doublewords at 0x11620 and 0x1163c, and panics at 0x11688 with a1 passed through. The return at 0x11598 is an unknown
  value or a panic result. The arbitration value it writes is not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_arbitration_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11698
  **Inferred.** It sends a zero `a0` to a panic block at 0x117f4 (branch at 0x116a0) and loads a halfword at `a0+0x72` at 0x116bc. It dispatches on that halfword through compares at 0x116c4 to 0x116e8, with -1 going to the panic block, and reads and writes a 32-bit word at 0x11758 and 0x11764. The name suggests setting bits in an arbitration register; the mask and the register address are not in these facts.
  Reviewed: 2026-11-12

- `pcireg_arbitration_bit_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11808
  **Inferred.** It sends a zero `a0` to a panic block at 0x11970 (branch at 0x11810) and loads the same halfword at `a0+0x72` at 0x1182c, then dispatches on it. It reads a 32-bit word at 0x118c8 and stores the changed word at 0x118d8, the read-modify-write shape of a bit clear. The name suggests clearing bits in the same arbitration register as its set partner at 0x11698; the facts do not confirm the mask.
  Reviewed: 2026-11-12

- `pcireg_nic_addr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11984
  **Inferred.** It sends a zero `a0` to a panic block at 0x11ac8 (branch at 0x1198c) and reads the halfword at `a0+0x72` at 0x119a8, the doubleword at `a0+8` and a word at `a0+4`. It makes no stores, and its return at 0x119e0 yields 0 or a value the facts do not resolve. The name suggests a NIC address getter, but the source of the returned value is unknown here.
  Reviewed: 2026-11-12

- `pcireg_parity_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11adc
  **Inferred.** It sends a zero `a0` to a panic block at 0x11c24 (branch at 0x11ae4), reads the halfword at `a0+0x72` at 0x11b00, and loads two doubleword values from addresses the facts do not resolve at 0x11b94 and 0x11bb0. Two panic calls sit at 0x11c1c and 0x11c28; the facts show a fifth argument (a4) of -1 on the first and none resolved on the second. The return at 0x11b38 yields 0 or an unknown value, so the parity error meaning is not settled.
  Reviewed: 2026-11-12

- `pcireg_timeout_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11c38
  **Inferred.** It sends a zero `a0` to a panic block at 0x11d88 (branch at 0x11c40), reads the halfword at `a0+0x72` at 0x11c5c, and reads two words at 0x11ca0 and 0x11cfc. It does not store, and it returns 0 or an unknown value at 0x11c94. The name suggests a timeout getter; the facts leave the field and the return value open.
  Reviewed: 2026-11-12

- `pcireg_timeout_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11d9c
  **Inferred.** It sends a zero `a0` to a panic block at 0x11ee0 (branch at 0x11da4), reads the halfword at `a0+0x72` at 0x11dc0 and a word at `a0+4` at 0x11e00, and then stores a 32-bit word at 0x11e60. It returns 3 or an unknown value, or reaches the panic at 0x11ee4 with the .rodata string at +12520. The name suggests a timeout setter; the value written and the register are not shown by the facts.
  Reviewed: 2026-11-12

- `pcireg_timeout_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11ef4
  **Inferred.** It sends a zero `a0` to a panic block at 0x12054 (branch at 0x11efc) and reads the halfword at `a0+0x72` at 0x11f18 and a word at `a0+4` at 0x11f5c. It reads a word at 0x11fb8 and stores a word at 0x11fc4; the facts do not show how the stored value derives from the read. The return at 0x11f50 yields an unknown value or the panic result. Role (from name): a bit set; the mask is not in these facts.
  Reviewed: 2026-11-12

- `pcireg_timeout_bit_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12068
  **Inferred.** It sends a zero `a0` to a panic block at 0x121d0 (branch at 0x12070) and reads the halfword at `a0+0x72` at 0x1208c and a word at `a0+4` at 0x120cc. It reads a word at 0x12128 and stores the changed word at 0x12138, the read-modify-write shape of a bit clear. The return at 0x120c0 yields 3, an unknown value, or the panic result.
  Reviewed: 2026-11-12

- `pcireg_type1_cntr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x121e4
  **Inferred.** It sends a zero `a0` to a panic block at 0x12338 (branch at 0x121ec) and reads the halfword at `a0+0x72` at 0x12208 and a word at `a0+4` at 0x12250. It reads one more word at 0x122ac and two doublewords at 0x122d4 and 0x122f0, and returns 0 or an unknown value at 0x12244. The name suggests a read of a type 1 configuration counter; the facts do not show what the counter counts.
  Reviewed: 2026-11-12

- `pcireg_type1_cntr_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1234c
  **Inferred.** It sends a zero `a0` to a panic block at 0x12490 (branch at 0x12354) and reads the halfword at `a0+0x72` at 0x12370 and a word at `a0+4` at 0x123b0. It stores a 32-bit word at 0x12410 and returns 3, an unknown value, or the panic result at 0x123a4. The name suggests a write to the same type 1 counter that its getter at 0x121e4 reads; the stored value is not shown.
  Reviewed: 2026-11-12

- `pcireg_pci_bus_addr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x124a4
  **Inferred.** It sends a zero `a0` to a panic block at 0x12600 (branch at 0x124ac) and reads the halfword at `a0+0x72` at 0x124c8, the doubleword at `a0+8` at 0x124d4 and the word at `a0+4` at 0x1250c. The facts show no stores, and the return at 0x12500 yields 0 or an unknown value. The name suggests a PCI bus address getter; the facts do not show the address it returns.
  Reviewed: 2026-11-12

- `pcireg_pci_bus_addr_addr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12614
  **Inferred.** It sends a zero `a0` to a panic block at 0x12780 (branch at 0x1261c) and reads the halfword at `a0+0x72` at 0x12638 and the word at `a0+4` at 0x12680. It loads a doubleword from an address the facts do not resolve at 0x12710 and returns 0 or an unknown value at 0x12674. The name suggests a getter for an address of the bus address register, but the facts do not settle which address.
  Reviewed: 2026-11-12

- `pcireg_intr_status_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12794
  **Inferred.** It sends a zero `a0` to a panic block at 0x128e8 (branch at 0x1279c) and reads the halfword at `a0+0x72` at 0x127b8 and the word at `a0+4` at 0x12800. It reads one more word at 0x1285c and two doublewords at 0x12884 and 0x128a0, and returns 0 or an unknown value at 0x127f4. The name suggests a status getter for interrupts; the facts do not show which status bits it reads.
  Reviewed: 2026-11-12

- `pcireg_intr_enable_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x128fc
  **Inferred.** It sends a zero `a0` to a panic block at 0x12a4c (branch at 0x12904) and reads the halfword at `a0+0x72` at 0x12920 and the word at `a0+4` at 0x12964. It reads a word at 0x129c0 and returns 0 or an unknown value at 0x12958. The name suggests a getter for the interrupt enable register; the facts do not show the register address.
  Reviewed: 2026-11-12

- `pcireg_intr_enable_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12a60
  **Inferred.** It sends a zero `a0` to a panic block at 0x12ba4 (branch at 0x12a68) and reads the halfword at `a0+0x72` at 0x12a84 and the word at `a0+4` at 0x12ac4. It stores a 32-bit word at 0x12b24 and returns 3, an unknown value, or the panic result at 0x12ab8. The name suggests a setter for the interrupt enable register that its getter at 0x128fc reads; the value written is not in the facts.
  Reviewed: 2026-11-12

- `pcireg_intr_enable_bit_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12bb8
  **Inferred.** It sends a zero `a0` to a panic block at 0x12d24 (branch at 0x12bc0) and reads the halfword at `a0+0x72` at 0x12bdc and the word at `a0+4` at 0x12c20. It reads a word at 0x12c7c and stores a word at 0x12c8c; the facts do not show what register that is or how the stored value derives from the read. The return at 0x12c14 is an unknown value or the panic result. Role (from name): a bit clear on an interrupt enable setting; the mask is not shown.
  Reviewed: 2026-11-12

- `pcireg_intr_enable_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12d38
  **Inferred.** It sends a zero `a0` to a panic block at 0x12e98 (branch at 0x12d40) and reads the halfword at `a0+0x72` at 0x12d5c and the word at `a0+4` at 0x12da0. It reads a word at 0x12dfc and stores a word at 0x12e08; the facts do not show what register that is or how the stored value derives from the read. The return at 0x12d94 is an unknown value or the panic result. Role (from name): a bit set on an interrupt enable setting; the mask is not in the facts.
  Reviewed: 2026-11-12

- `pcireg_intr_reset_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x12eac
  **Inferred.** It sends a zero `a0` to a panic block at 0x12ff0 (branch at 0x12eb4) and reads the halfword at `a0+0x72` at 0x12ed0 and the word at `a0+4` at 0x12f10. It stores a 32-bit word at 0x12f70 and returns 3, an unknown value, or the panic result at 0x12f04. The name suggests a write to an interrupt reset register; the stored value and the register are not shown.
  Reviewed: 2026-11-12

- `pcireg_intr_reset_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x13004
  **Inferred.** It sends a zero `a0` to a panic block at 0x13164 (branch at 0x1300c) and reads the halfword at `a0+0x72` at 0x13028 and the word at `a0+4` at 0x1306c. It reads a word at 0x130c8 and stores a word at 0x130d4; the facts do not show how the stored value derives from the read. The return at 0x13060 is an unknown value or the panic result. Role (from name): a bit set; the mask is open.
  Reviewed: 2026-11-12

- `pcireg_intr_mode_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x13178
  **Inferred.** It sends a zero `a0` to a panic block at 0x132cc (branch at 0x13180) and reads the halfword at `a0+0x72` at 0x1319c and the word at `a0+4` at 0x131e4. It reads a word at 0x13240 and returns 0 or an unknown value at 0x131d8. The name suggests a getter for an interrupt mode setting; the facts do not show which mode field it extracts.
  Reviewed: 2026-11-12

- `pcireg_intr_mode_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x132e0
  **Inferred.** It sends a zero `a0` to a panic block at 0x13428 (branch at 0x132e8) and reads the halfword at `a0+0x72` at 0x13304 and the word at `a0+4` at 0x13348. It stores a 32-bit word at 0x133a8 and returns an unknown value or the panic result at 0x1333c. The name suggests a setter for the interrupt mode register that its getter at 0x13178 reads; the value written is not in the facts.
  Reviewed: 2026-11-12

- `pcireg_intr_mode_bit_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1343c
  **Inferred.** It sends a zero `a0` to a panic block at 0x1359c (branch at 0x13444) and reads the halfword at `a0+0x72` at 0x13460 and the word at `a0+4` at 0x134a4. It reads a word at 0x13500 and stores a word at 0x1350c; the facts do not show how the stored value derives from the read. The return at 0x13498 is an unknown value or the panic result. Role (from name): a bit set; the mask is not in these facts.
  Reviewed: 2026-11-12

- `pcireg_intr_mode_bit_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x135b0
  **Inferred.** It sends a zero `a0` to a panic block at 0x13718 (branch at 0x135b8) and reads the halfword at `a0+0x72` at 0x135d4 and the word at `a0+4` at 0x13614. It reads a word at 0x13670 and stores a word at 0x13680; the facts do not show how the stored value derives from the read. It returns 3, an unknown value, or the panic result at 0x13608. Role (from name): a bit clear; the mask is not shown.
  Reviewed: 2026-11-12

- `pcireg_intr_device_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1372c
  **Inferred.** It sends a zero `a0` to a panic block at 0x13880 (branch at 0x13734) and reads the halfword at `a0+0x72` at 0x13750 and the word at `a0+4` at 0x13798. It reads a word at 0x137f4 and returns 0 or an unknown value at 0x1378c. The name suggests a getter for an interrupt device field; the facts do not show which field.
  Reviewed: 2026-11-12

- `pcireg_intr_device_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x13894
  **Inferred.** It sends a zero `a0` to a panic block at 0x139dc (branch at 0x1389c) and reads the halfword at `a0+0x72` at 0x138b8 and the word at `a0+4` at 0x138fc. It stores a 32-bit word at 0x1395c and returns an unknown value or the panic result at 0x138f0. The name suggests a setter for the interrupt device register that its getter at 0x1372c reads; the value written is not shown.
  Reviewed: 2026-11-12
