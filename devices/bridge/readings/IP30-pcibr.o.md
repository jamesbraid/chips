# Readings: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`

One entry per routine, filed here from the reading batches by binary.

- `pcibr_try_set_device` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
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

- `pcibr_release_device` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x4a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
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

- `pcibr_device_write_gather_flush` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x554 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x554-0x570 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x55c calls pcireg_wrb_flush_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x568 has v0 = ret(pcireg_wrb_flush_get).

- `pcibr_close` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x5a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x5a4-0x5ac (8 bytes).
  It occupies 8 bytes.
  The return at 0x5a4 has v0 = 0x0.

- `pcibr_map` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x5ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
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

- `pcibr_unmap` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x678 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
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

- `pcibr_device_slot_get` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x6f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
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

- `pcibr_ioctl` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x778 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
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

- `pcibr_info_get` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x8e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x8e8-0x904 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x8f0 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x8fc has v0 = ret(pciio_hostinfo_get).

- `pcibr_device_info_new` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x904 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
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

- `pcibr_device_unregister` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xa1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
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

- `pcibr_driver_reg_callback` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb54 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
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

- `pcibr_driver_unreg_callback` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xbfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
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

- `pcibr_detach` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xca4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
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

- `pcibr_directmap_init` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xe34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xe34-0xec8 (148 bytes).
  It occupies 148 bytes.
  The `lw` at 0xe44 loads 4 bytes from a0 (arg0 at entry) +0x0.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x30, including `lbu` at 0xe78, `lbu` at 0xe80.
  The `sb` at 0xe88 stores 1 byte to a0 (arg0 at entry) +0x58.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x50, including `sd` at 0xe9c, `sd` at 0xec4.
  The `jal` at 0xe58 calls xtalk_dmatrans_addr with a0=[a0], a1=0x0, a2=0x0, a3=0x4000, a4=0x0.
  The `jal` at 0xe68 calls pcireg_dirmap_diroff_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe74 calls pcireg_dirmap_wid_set with a0=a0 at entry (arg0), a1=[a0+48]:1, a2=?, a3=?.
  The `jal` at 0xe8c calls pcireg_dirmap_add512_clr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xeb4 calls pcireg_dirmap_add512_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xe84 targets 0xeb4, is taken when v0(=0x20000000) == s1(=ret(xtalk_dmatrans_addr)), and falls through when v0(=0x20000000) != s1(=ret(xtalk_dmatrans_addr)).
  The `beq` branch at 0xec0 targets 0xea0 and is always taken.
  The return at 0xeac has v0 = one of ret(pcireg_dirmap_add512_clr), ret(pcireg_dirmap_add512_set).

- `pcibr_asic_rev` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xec8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xec8-0xf30 (104 bytes).
  It occupies 104 bytes.
  The `jal` at 0xed8 calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-32, a3=a3 at entry (arg3).
  The `jal` at 0xf00 calls hwgraph_info_get_LBL with a0=?, a1=sym(.rodata), a2=sp-24, a3=?.
  The `jal` at 0xf0c calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0xee0 targets 0xef8, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0xf18 targets 0xf28, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xf20 targets 0xef0 and is always taken.
  The `beq` branch at 0xf28 targets 0xeec and is always taken.
  The return at 0xef0 has v0 = one of ?, -0x1.

- `pcibr_write_gather_flush` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xf30 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xf30-0xf6c (60 bytes).
  It occupies 60 bytes.
  The `lbu` at 0xf54 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `jal` at 0xf38 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xf44 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xf50 calls pcibr_device_write_gather_flush [0x554] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The return at 0xf64 has v0 = 0x0.

- `pcibr_addr_pci_to_xio` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xf6c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xf6c-0x183c (2256 bytes).
  It occupies 2256 bytes.
  The `lw` at 0xfe4 loads 4 bytes from (ret(pciio_info_mfast_get) + (a1 << 0x7)) +0x100.
  The `lbu` at 0xff0 loads 1 byte from (ret(pciio_info_mfast_get) + (a1 << 0x7)) +0x104.
  The `ld` at 0xffc loads 8 bytes from (ret(pciio_info_mfast_get) + ([(ret(pciio_info_mfast_get) + (a1 << 0x7))+260]:1 << 0x7)) +0x118.
  The `ld` at 0x1000 loads 8 bytes from [(ret(pciio_info_mfast_get) + ([(ret(pciio_info_mfast_get) + (a1 << 0x7))+260]:1 << 0x7))+280]:8 +0x0.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x104c, `lw` at 0x1118, `lw` at 0x11b0.
  8 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1058, `ld` at 0x1070, `ld` at 0x1110.
  The `lbu` at 0x1098 loads 1 byte from ret(pciio_info_mfast_get) +0x39.
  5 such `lw` accesses load 4 bytes from ret(pciio_info_mfast_get) +0x48, including `lw` at 0x11fc, `lw` at 0x1510, `lw` at 0x153c.
  4 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x72, including `lh` at 0x12a8, `lh` at 0x1468, `lh` at 0x149c.
  The `lw` at 0x12f4 loads 4 bytes from (ret(pciio_info_mfast_get) + one of 0xa98, 0xa9c) +0x0.
  4 such `ld` accesses load 8 bytes from table(sym(pci_space)) +0x0, including `ld` at 0x136c, `ld` at 0x1454, `ld` at 0x167c.
  5 such `sw` accesses store 4 bytes to ?, including `sw` at 0x13ec, `sw` at 0x1410, `sw` at 0x15b0.
  The `lw` at 0x14a8 loads 4 bytes from ret(pciio_info_mfast_get) +0x78.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x15bc, `sd` at 0x17cc.
  2 such `sw` accesses store 4 bytes to (ret(pciio_info_mfast_get) + one of 0xa98, 0xa9c) +0x0, including `sw` at 0x16e8, `sw` at 0x1808.
  The `jal` at 0xfa4 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xfb0 calls pciio_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xfc4 calls pciio_info_mfast_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xfd4 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0x1260 calls mutex_io_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1368 calls sprintf with a0=sp-736, a1=sym(.rodata), a2=entry(sym(pci_space)), a3=sym(.rodata), a4=sym(.rodata), a5=sym(.rodata), a6=sym(.rodata), a7=sym(.rodata).
  The `jal` at 0x1450 calls sprintf with a0=sp-736, a1=sym(.rodata), a2=entry(sym(pci_space)), a3=?.
  The `jal` at 0x1690 calls sprintf with a0=sp-736, a1=sym(.rodata), a2=entry(sym(pci_space)), a3=?.
  The `jal` at 0x16e0 calls pcireg_control_bit_set with a0=ret(pciio_info_mfast_get), a1=one of 0x400000, 0x800000, a2=?, a3=?, a6=0x2.
  The `jal` at 0x1724 calls sprintf with a0=sp-736, a1=sym(.rodata), a2=entry(sym(pci_space)), a3=sym(.rodata), a4=sym(.rodata), a7=sym(.rodata).
  The `jal` at 0x17c4 calls pcireg_device_set with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?, a6=0x2, a7=0xfffff.
  The `jal` at 0x17d0 calls pcireg_tflush_get with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0x17fc calls pcireg_control_bit_clr with a0=ret(pciio_info_mfast_get), a1=one of 0x400000, 0x800000, a2=?, a3=?, a6=0x2.
  The `beq` branch at 0xfe8 targets 0x1008, is taken when at(=[(ret(pciio_info_mfast_get) + (a1 << 0x7))+256]) == 0, and falls through when at(=[(ret(pciio_info_mfast_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0x1008 targets 0x1290, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x1014 targets 0x1298, is taken when s1(=a2) == ra(=0x7), and falls through when s1(=a2) != ra(=0x7).
  The `beq` branch at 0x1020 targets 0x1378, is taken when s1(=a2) == ra(=0x1), and falls through when s1(=a2) != ra(=0x1).
  The `beq` branch at 0x102c targets 0x1094, is taken when a4(?) >= 0x6 (unsigned), and falls through when a4(?) < 0x6 (unsigned).
  The `beq` branch at 0x1050 targets 0x13ac, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x1068 targets 0x107c, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x107c targets 0x13b4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x1084 targets 0x1098, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x108c targets 0x124c and is always taken.
  The `bltz` branch at 0x109c targets 0x1220, is taken when a3(=[ret(pciio_info_mfast_get)+57]:1) < 0 (signed), and falls through when a3(=[ret(pciio_info_mfast_get)+57]:1) >= 0 (signed).
  The `beq` branch at 0x1100 targets 0x114c and is always taken.
  The `beq` branch at 0x1108 targets 0x1120, is taken when s4(?) == s5(?), and falls through when s4(?) != s5(?).
  The `bne` branch at 0x111c targets 0x113c, is taken when a1(?) != a5(=-0x1), and falls through when a1(?) == a5(=-0x1).
  The `beq` branch at 0x1134 targets 0x157c, is taken when s0(?) == a5(?), and falls through when s0(?) != a5(?).
  The `beq` branch at 0x1144 targets 0x1228, is taken when a4(?) >= t0(=([ret(pciio_info_mfast_get)+57]:1 + [ret(pciio_info_mfast_get)+57]:1)+2) (signed), and falls through when a4(?) < t0(=([ret(pciio_info_mfast_get)+57]:1 + [ret(pciio_info_mfast_get)+57]:1)+2) (signed).
  The `beq` branch at 0x1178 targets 0x1184, is taken when s1(?) == a6(=0x2), and falls through when s1(?) != a6(=0x2).
  The `bne` branch at 0x119c targets 0x113c, is taken when a5(=one of 0x100000, 0x200000) < t1(?) (unsigned), and falls through when a5(=one of 0x100000, 0x200000) >= t1(?) (unsigned).
  The `beq` branch at 0x11ac targets 0x11bc, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x11b4 targets 0x1108, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x11bc targets 0x113c, is taken when a1(?) != s1(?), and falls through when a1(?) == s1(?).
  The `bne` branch at 0x11d8 targets 0x113c, is taken when s0(?) < a3(?) (unsigned), and falls through when s0(?) >= a3(?) (unsigned).
  The `bne` branch at 0x11e0 targets 0x1140, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0x11e8 targets 0x14e8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x11f0 targets 0x1140, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x1200 targets 0x13bc, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x1218 targets 0x13d0 and is always taken.
  The `beq` branch at 0x1228 targets 0x12a8, is taken when s1(?) == a5(=0x4), and falls through when s1(?) != a5(=0x4).
  The `beq` branch at 0x1230 targets 0x12a8, is taken when s1(?) == a7(=0x5), and falls through when s1(?) != a7(=0x5).
  The `beq` branch at 0x1238 targets 0x1468, is taken when s1(?) == t0(=0x6), and falls through when s1(?) != t0(=0x6).
  The `beq` branch at 0x1240 targets 0x149c, is taken when s1(?) == a6(=0x2), and falls through when s1(?) != a6(=0x2).
  The `beq` branch at 0x1290 targets 0x124c and is always taken.
  The `beq` branch at 0x1298 targets 0x14f8, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x12a0 targets 0x124c and is always taken.
  The `beq` branch at 0x12ac targets 0x153c, is taken when a3(=[ret(pciio_info_mfast_get)+114]:2) == a6(=0x2), and falls through when a3(=[ret(pciio_info_mfast_get)+114]:2) != a6(=0x2).
  The `bne` branch at 0x12cc targets 0x1460, is taken when a4(=0x7fffffff) < a5(=table(0x3fffffff)) (unsigned), and falls through when a4(=0x7fffffff) >= a5(=table(0x3fffffff)) (unsigned).
  The `beq` branch at 0x12dc targets 0x1250, is taken when t0(=-0x1) == s3(?), and falls through when t0(=-0x1) != s3(?).
  The `beq` branch at 0x12e4 targets 0x16a0, is taken when s1(?) == a6(=0x2), and falls through when s1(?) != a6(=0x2).
  The `beq` branch at 0x1304 targets 0x1250, is taken when s5(=one of 0x1000, 0x2000) == a1(?), and falls through when s5(=one of 0x1000, 0x2000) != a1(?).
  The `beq` branch at 0x130c targets 0x16c8, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bgez` branch at 0x131c targets 0x1370, is taken when t8(=([sym(pcibr_debug_mask)] << 0x24)) >= 0 (signed), and falls through when t8(=([sym(pcibr_debug_mask)] << 0x24)) < 0 (signed).
  The `beq` branch at 0x1324 targets 0x177c, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x1338 targets 0x16a8, is taken when (a1(?) & 0x2000) == 0, and falls through when (a1(?) & 0x2000) != 0.
  The `beq` branch at 0x1340 targets 0x16b0, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1370 targets 0x124c and is always taken.
  The `bne` branch at 0x1388 targets 0x139c, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x139c targets 0x1028, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x13a4 targets 0x124c and is always taken.
  The `bne` branch at 0x13ac targets 0x1098, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x13b4 targets 0x124c and is always taken.
  The `beq` branch at 0x13e8 targets 0x1414, is taken when t0(=-0x1) == t1(?), and falls through when t0(=-0x1) != t1(?).
  The `bgez` branch at 0x141c targets 0x1250, is taken when at(=([sym(pcibr_debug_mask)] << 0x24)) >= 0 (signed), and falls through when at(=([sym(pcibr_debug_mask)] << 0x24)) < 0 (signed).
  The `beq` branch at 0x1458 targets 0x1250 and is always taken.
  The `beq` branch at 0x1460 targets 0x124c and is always taken.
  The `beq` branch at 0x146c targets 0x173c, is taken when a5(=[ret(pciio_info_mfast_get)+114]:2) == a6(=0x2), and falls through when a5(=[ret(pciio_info_mfast_get)+114]:2) != a6(=0x2).
  The `bne` branch at 0x1488 targets 0x1534, is taken when a7(=0xbfffffff) < t0(=table(0x7fffffff)) (unsigned), and falls through when a7(=0xbfffffff) >= t0(=table(0x7fffffff)) (unsigned).
  The `beq` branch at 0x1494 targets 0x12d8 and is always taken.
  The `beq` branch at 0x14a0 targets 0x1784, is taken when a2(=[ret(pciio_info_mfast_get)+114]:2) == a6(=0x2), and falls through when a2(=[ret(pciio_info_mfast_get)+114]:2) != a6(=0x2).
  The `beq` branch at 0x14b4 targets 0x1574, is taken when a3(=0xc0023) >= a4(=[ret(pciio_info_mfast_get)+120]) (signed), and falls through when a3(=0xc0023) < a4(=[ret(pciio_info_mfast_get)+120]) (signed).
  The `bne` branch at 0x14d4 targets 0x1734, is taken when a4(=0x1ffffffff) < a5(=table(0xffffffff)) (unsigned), and falls through when a4(=0x1ffffffff) >= a5(=table(0xffffffff)) (unsigned).
  The `beq` branch at 0x14e0 targets 0x12d8 and is always taken.
  The `bne` branch at 0x14e8 targets 0x1140, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x14f0 targets 0x11fc and is always taken.
  The `beq` branch at 0x14fc targets 0x16c0, is taken when t8(=(a3 + a4)) >= 0x101 (unsigned), and falls through when t8(=(a3 + a4)) < 0x101 (unsigned).
  The `beq` branch at 0x1520 targets 0x17f4, is taken when a4(=[ret(pciio_info_mfast_get)+114]:2) == a5(=0x2), and falls through when a4(=[ret(pciio_info_mfast_get)+114]:2) != a5(=0x2).
  The `beq` branch at 0x152c targets 0x124c and is always taken.
  The `beq` branch at 0x1534 targets 0x124c and is always taken.
  The `beq` branch at 0x1540 targets 0x178c, is taken when a1(=[ret(pciio_info_mfast_get)+72]) == 0, and falls through when a1(=[ret(pciio_info_mfast_get)+72]) != 0.
  The `bne` branch at 0x1548 targets 0x12b0, is taken when a1(=[ret(pciio_info_mfast_get)+72]) != t0(=0x1), and falls through when a1(=[ret(pciio_info_mfast_get)+72]) == t0(=0x1).
  The `bne` branch at 0x1564 targets 0x1460, is taken when t1(=0xffffffff) < t2(=table(0xbfffffff)) (unsigned), and falls through when t1(=0xffffffff) >= t2(=table(0xbfffffff)) (unsigned).
  The `beq` branch at 0x156c targets 0x12d4 and is always taken.
  The `beq` branch at 0x1574 targets 0x124c and is always taken.
  The `beq` branch at 0x157c targets 0x17e0, is taken when s1(?) == a6(=0x2), and falls through when s1(?) != a6(=0x2).
  The `beq` branch at 0x159c targets 0x17e8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x15a8 targets 0x17b8, is taken when ra(?) != v0(?), and falls through when ra(?) == v0(?).
  The `beq` branch at 0x15c4 targets 0x15e4, is taken when s4(?) >= 0x2 (signed), and falls through when s4(?) < 0x2 (signed).
  The `beq` branch at 0x15dc targets 0x15fc and is always taken.
  The `beq` branch at 0x1618 targets 0x1644, is taken when a7(=-0x1) == t0(?), and falls through when a7(=-0x1) != t0(?).
  The `bgez` branch at 0x164c targets 0x124c, is taken when at(=([sym(pcibr_debug_mask)] << 0x24)) >= 0 (signed), and falls through when at(=([sym(pcibr_debug_mask)] << 0x24)) < 0 (signed).
  The `beq` branch at 0x1698 targets 0x1250 and is always taken.
  The `beq` branch at 0x16a0 targets 0x12ec and is always taken.
  The `bne` branch at 0x16a8 targets 0x1348, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x16b8 targets 0x1354 and is always taken.
  The `beq` branch at 0x16c0 targets 0x124c and is always taken.
  The `beq` branch at 0x16d8 targets 0x17fc, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x16f4 targets 0x1250, is taken when (s6(=0x8000000) & t0(=[sym(pcibr_debug_mask)])) == 0, and falls through when (s6(=0x8000000) & t0(=[sym(pcibr_debug_mask)])) != 0.
  The `beq` branch at 0x16fc targets 0x180c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x172c targets 0x1250 and is always taken.
  The `beq` branch at 0x1734 targets 0x124c and is always taken.
  The `beq` branch at 0x1740 targets 0x1818, is taken when a1(=[ret(pciio_info_mfast_get)+72]) == 0, and falls through when a1(=[ret(pciio_info_mfast_get)+72]) != 0.
  The `bne` branch at 0x174c targets 0x1474, is taken when a1(=[ret(pciio_info_mfast_get)+72]) != a7(=0x1), and falls through when a1(=[ret(pciio_info_mfast_get)+72]) == a7(=0x1).
  The `bne` branch at 0x176c targets 0x1534, is taken when t0(=0x13fffffff) < t1(=table(0xffffffff)) (unsigned), and falls through when t0(=0x13fffffff) >= t1(=table(0xffffffff)) (unsigned).
  The `beq` branch at 0x1774 targets 0x1494 and is always taken.
  The `beq` branch at 0x177c targets 0x1334 and is always taken.
  The `beq` branch at 0x1784 targets 0x124c and is always taken.
  The `bne` branch at 0x17a8 targets 0x1460, is taken when a2(=0x7fffffff) < a3(=table(0x3fffffff)) (unsigned), and falls through when a2(=0x7fffffff) >= a3(=table(0x3fffffff)) (unsigned).
  The `beq` branch at 0x17b0 targets 0x12d4 and is always taken.
  The `beq` branch at 0x17d8 targets 0x15b0 and is always taken.
  The `beq` branch at 0x17e0 targets 0x1590 and is always taken.
  The `beq` branch at 0x17ec targets 0x15a8 and is always taken.
  The `beq` branch at 0x17f4 targets 0x152c and is always taken.
  The `beq` branch at 0x1804 targets 0x16ec and is always taken.
  The `beq` branch at 0x1810 targets 0x1710 and is always taken.
  The `bne` branch at 0x182c targets 0x1534, is taken when a0(=0xbfffffff) < a1(=table(0x7fffffff)) (unsigned), and falls through when a0(=0xbfffffff) >= a1(=table(0x7fffffff)) (unsigned).
  The `beq` branch at 0x1834 targets 0x1494 and is always taken.
  The return at 0x1288 has v0 = ?.

- `pcibr_piomap_alloc` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x183c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x183c-0x1a84 (584 bytes).
  It occupies 584 bytes.
  The `lbu` at 0x1884 loads 1 byte from ret(pcibr_info_get) +0x21c.
  The `lw` at 0x189c loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `ld` at 0x18f4 loads 8 bytes from ret(pcibr_info_get) +0x210.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1904, `ld` at 0x1910, `ld` at 0x199c.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0x193c, `sw` at 0x1958, `sw` at 0x1968.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x72, including `lh` at 0x1948, `lh` at 0x1978.
  9 such `sd` accesses store 8 bytes to ?, including `sd` at 0x195c, `sd` at 0x1960, `sd` at 0x1964.
  The `sb` at 0x196c stores 1 byte to ?.
  The `jal` at 0x1878 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x188c calls pciio_info_mfast_get with a0=ret(pcibr_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x18c4 calls pcibr_addr_pci_to_xio [0xf6c] with a0=a0 at entry (arg0), a1=[ret(pcibr_info_get)+540]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a6 at entry (arg6).
  The `jal` at 0x18e8 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0x191c calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x1928 calls kmem_zalloc with a0=0x60, a1=0x0, a2=?, a3=?.
  The `jal` at 0x198c calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=ret(mutex_spinlock), a2=?, a3=0x2.
  The `jal` at 0x19b0 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x19d0 calls xtalk_piomap_alloc with a0=[ret(pciio_info_mfast_get)], a1=0x0, a2=ret(pcibr_addr_pci_to_xio), a3=a4 at entry (arg4), a4=a5 at entry (arg5).
  The `jal` at 0x1a58 calls pcibr_debug with a0=0x8000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x1a74 calls pcibr_debug with a0=0x8000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `beq` branch at 0x1898 targets 0x1a4c, is taken when s1(=a4) == 0, and falls through when s1(=a4) != 0.
  The `beq` branch at 0x18a0 targets 0x1a4c, is taken when s7(=a5) == 0, and falls through when s7(=a5) != 0.
  The `beq` branch at 0x18d0 targets 0x1a68, is taken when v0(=ret(pcibr_addr_pci_to_xio)) == at(=-0x1), and falls through when v0(=ret(pcibr_addr_pci_to_xio)) != at(=-0x1).
  The `beq` branch at 0x18fc targets 0x1918, is taken when s0(=[ret(pcibr_info_get)+528]:8) == 0, and falls through when s0(=[ret(pcibr_info_get)+528]:8) != 0.
  The `beq` branch at 0x1908 targets 0x1a20, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `bne` branch at 0x1914 targets 0x1904, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x1940 targets 0x1958, is taken when s2(=[ret(pcibr_info_get)+540]:1) == ra(=0xff), and falls through when s2(=[ret(pcibr_info_get)+540]:1) != ra(=0xff).
  The `beq` branch at 0x194c targets 0x1958, is taken when at(=[ret(pciio_info_mfast_get)+114]:2) == a3(=0x2), and falls through when at(=[ret(pciio_info_mfast_get)+114]:2) != a3(=0x2).
  The `beq` branch at 0x197c targets 0x1a3c, is taken when v0(=[ret(pciio_info_mfast_get)+114]:2) == a3(=0x2), and falls through when v0(=[ret(pciio_info_mfast_get)+114]:2) != a3(=0x2).
  The `beq` branch at 0x1984 targets 0x19ac, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0x19b8 targets 0x19ec, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x19d8 targets 0x1a30, is taken when v0(=ret(xtalk_piomap_alloc)) == 0, and falls through when v0(=ret(xtalk_piomap_alloc)) != 0.
  The `beq` branch at 0x1a20 targets 0x191c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1a28 targets 0x1934 and is always taken.
  The `beq` branch at 0x1a34 targets 0x19ec and is always taken.
  The `beq` branch at 0x1a44 targets 0x1984 and is always taken.
  The `beq` branch at 0x1a60 targets 0x19ec and is always taken.
  The `beq` branch at 0x1a7c targets 0x19ec and is always taken.
  The return at 0x1a18 has v0 = one of ?, 0x0.

- `pcibr_piomap_free` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x1a84 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x1a84-0x1ad4 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0x1a98 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `sd` at 0x1a9c stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `ld` at 0x1aa0 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sd` at 0x1aa4 stores 8 bytes to a0 (arg0 at entry) +0x30.
  The `lh` at 0x1aa8 loads 2 bytes from [a0+64]:8 +0x72.
  The `sw` at 0x1ac4 stores 4 bytes to a0 (arg0 at entry) +0x5c.
  The `sw` at 0x1ac8 stores 4 bytes to a0 (arg0 at entry) +0x58.
  The `sd` at 0x1ad0 stores 8 bytes to a0 (arg0 at entry) +0x50.
  The `jal` at 0x1a94 calls xtalk_piomap_free with a0=[a0+48]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x1ab0 targets 0x1ac4, is taken when at(=[[a0+64]:8+114]:2) == v0(=0x2), and falls through when at(=[[a0+64]:8+114]:2) != v0(=0x2).
  The `beq` branch at 0x1acc targets 0x1ab8 and is always taken.
  The return at 0x1abc has v0 = 0x2.

- `pcibr_piomap_addr` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x1ad4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x1ad4-0x1b00 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0x1ad4 loads 8 bytes from a0 (arg0 at entry) +0x28.
  The `ld` at 0x1ad8 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x1adc loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `jal` at 0x1aec calls xtalk_piomap_addr with a0=[a0+48]:8, a1=?, a2=a2 at entry (arg2), a3=[a0+16]:8, a4=[a0+40]:8.
  The return at 0x1af8 has v0 = ret(xtalk_piomap_addr).

- `pcibr_piomap_done` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x1b00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x1b00-0x1b1c (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0x1b0c loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `jal` at 0x1b08 calls xtalk_piomap_done with a0=[a0+48]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1b14 has v0 = ret(xtalk_piomap_done).

- `pcibr_piotrans_addr` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x1b1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x1b1c-0x1be8 (204 bytes).
  It occupies 204 bytes.
  The `lbu` at 0x1b50 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0x1b74 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0x1b48 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b58 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1b7c calls pcibr_addr_pci_to_xio [0xf6c] with a0=a0 at entry (arg0), a1=[ret(pciio_hostinfo_get)+540]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b9c calls xtalk_piotrans_addr with a0=[ret(pciio_info_mfast_get)], a1=0x0, a2=ret(pcibr_addr_pci_to_xio), a3=a4 at entry (arg4).
  The `jal` at 0x1bd8 calls pcibr_debug with a0=0x10000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `beq` branch at 0x1b88 targets 0x1bcc, is taken when v0(=ret(pcibr_addr_pci_to_xio)) == v1(=-0x1), and falls through when v0(=ret(pcibr_addr_pci_to_xio)) != v1(=-0x1).
  The `beq` branch at 0x1be0 targets 0x1ba8 and is always taken.
  The return at 0x1bc4 has v0 = one of ret(xtalk_piotrans_addr), 0x0.

- `pcibr_piospace_alloc` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x1be8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x1be8-0x1ddc (500 bytes).
  It occupies 500 bytes.
  2 such `ld` accesses load 8 bytes from ret(pcibr_info_get) +0x1d0, including `ld` at 0x1c40, `ld` at 0x1d70.
  The `lbu` at 0x1c60 loads 1 byte from [ret(pcibr_info_get)+464]:8 +0x8.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1c64, `ld` at 0x1c88, `ld` at 0x1c98.
  The `lbu` at 0x1c70 loads 1 byte from ?.
  The `lw` at 0x1c7c loads 4 bytes from ?.
  The `sb` at 0x1cb4 stores 1 byte to ?.
  The `sd` at 0x1d60 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `sd` at 0x1d64 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sw` at 0x1d68 stores 4 bytes to ret(kmem_zalloc) +0xc.
  The `sb` at 0x1d6c stores 1 byte to ret(kmem_zalloc) +0x8.
  The `sd` at 0x1d78 stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `sd` at 0x1d84 stores 8 bytes to ret(pcibr_info_get) +0x1d0.
  The `jal` at 0x1c10 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1c20 calls pciio_info_mfast_get with a0=ret(pcibr_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1c38 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0x1cb0 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=a4-1, a3=0x4, a4=0x5.
  The `jal` at 0x1cdc calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=a4-1, a3=0x4, a4=0x5.
  The `jal` at 0x1cf4 calls pcibr_debug with a0=0x8000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a2 at entry (arg2).
  The `jal` at 0x1d40 calls pcibr_bus_addr_alloc with a0=ret(pciio_info_mfast_get), a1=0x0, a2=0x5, a3=0x0, a4=(a3 << 0x0), a5=(a4 << 0x0).
  The `jal` at 0x1d58 calls kmem_zalloc with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1d80 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=[ret(pcibr_info_get)+464]:8.
  The `jal` at 0x1d94 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x1dac calls pcibr_debug with a0=0x8000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a3 at entry (arg3).
  The `jal` at 0x1dcc calls pcibr_bus_addr_alloc with a0=ret(pciio_info_mfast_get), a1=0x0, a2=0x2, a3=0x0, a4=(a3 << 0x0), a5=(a4 << 0x0).
  The `beq` branch at 0x1c54 targets 0x1cc0, is taken when s0(=[ret(pcibr_info_get)+464]:8) == 0, and falls through when s0(=[ret(pcibr_info_get)+464]:8) != 0.
  The `beq` branch at 0x1c5c targets 0x1c74 and is always taken.
  The `beq` branch at 0x1c68 targets 0x1cc0, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1c74 targets 0x1c64, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1c80 targets 0x1c64, is taken when v1(?) != s1(=a2), and falls through when v1(?) == s1(=a2).
  The `bne` branch at 0x1c90 targets 0x1c64, is taken when a0(?) < s2(=a3) (unsigned), and falls through when a0(?) >= s2(=a3) (unsigned).
  The `bnel` branch at 0x1ca0 targets 0x1c68, is taken when (a5(?) & a2(=a4-1)) != 0, and falls through when (a5(?) & a2(=a4-1)) == 0; its branch-likely delay slot `ld s0,0(s0)` at 0x1ca4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x1cb8 targets 0x1d00 and is always taken.
  The `beq` branch at 0x1cc0 targets 0x1dbc, is taken when s1(=a2) == a1(=0x2), and falls through when s1(=a2) != a1(=0x2).
  The `beq` branch at 0x1cc8 targets 0x1d30, is taken when s1(=a2) == a3(=0x4), and falls through when s1(=a2) != a3(=0x4).
  The `beq` branch at 0x1cd0 targets 0x1d30, is taken when s1(=a2) == a4(=0x5), and falls through when s1(=a2) != a4(=0x5).
  The `beq` branch at 0x1d4c targets 0x1d90, is taken when s0(=ret(pcibr_bus_addr_alloc)) == 0, and falls through when s0(=ret(pcibr_bus_addr_alloc)) != 0.
  The `beq` branch at 0x1d88 targets 0x1d00 and is always taken.
  The `beq` branch at 0x1db4 targets 0x1d00 and is always taken.
  The `beq` branch at 0x1dd4 targets 0x1d4c and is always taken.
  The return at 0x1d24 has v0 = one of ?, 0x0, ret(pcibr_bus_addr_alloc).
  The instructions from 0x1d2c to 0x1d2c are not reached by any path from the entry, and their branches are not listed.

- `pcibr_piospace_free` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x1ddc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x1ddc-0x1f0c (304 bytes).
  It occupies 304 bytes.
  The `ld` at 0x1e04 loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `ld` at 0x1e1c loads 8 bytes from ret(pcibr_info_get) +0x1d0.
  The `ld` at 0x1e2c loads 8 bytes from [ret(pcibr_info_get)+464]:8 +0x10.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1e30, `ld` at 0x1e3c, `ld` at 0x1e48.
  The `sb` at 0x1e68 stores 1 byte to ?.
  The `jal` at 0x1dfc calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e14 calls mutex_spinlock with a0=[ret(pcibr_info_get)+40]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0x1e6c calls mutex_io_spinunlock with a0=[ret(pcibr_info_get)+40]:8+128, a1=?, a2=?, a3=?, a6=sym(.rodata).
  The `jal` at 0x1ea0 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=sym(.rodata).
  The `jal` at 0x1eac calls mutex_io_spinunlock with a0=[ret(pcibr_info_get)+40]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0x1ec4 calls hwgraph_vertex_name_get with a0=a0 at entry (arg0), a1=sp-1088, a2=0x400, a3=?.
  The `jal` at 0x1ed4 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x1eec calls cmn_err with a0=0x4, a1=sym(.rodata), a2=sp-1088, a3=a3 at entry (arg3).
  The `jal` at 0x1efc calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x1e20 targets 0x1e58, is taken when s0(=[ret(pcibr_info_get)+464]:8) == 0, and falls through when s0(=[ret(pcibr_info_get)+464]:8) != 0.
  The `beq` branch at 0x1e28 targets 0x1e40 and is always taken.
  The `beq` branch at 0x1e34 targets 0x1e58, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x1e40 targets 0x1e30, is taken when t8(?) != s1(=a2), and falls through when t8(?) == s1(=a2).
  The `bne` branch at 0x1e4c targets 0x1ebc, is taken when t9(?) != s2(=a3), and falls through when t9(?) == s2(=a3).
  The `beq` branch at 0x1e58 targets 0x1e94, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1eb4 targets 0x1e78 and is always taken.
  The `beq` branch at 0x1f04 targets 0x1e54 and is always taken.
  The return at 0x1e8c has v0 = ret(mutex_io_spinunlock).

- `pcibr_flags_to_d64` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x1f0c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x1f0c-0x20c0 (436 bytes).
  It occupies 436 bytes.
  The `lh` at 0x1f90 loads 2 bytes from a1 (arg1 at entry) +0x72.
  The `lh` at 0x2048 loads 2 bytes from a1 (arg1 at entry) +0x74.
  The `jal` at 0x20b0 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0x7d0, a3=a3 at entry (arg3).
  The `bgez` branch at 0x1f30 targets 0x1f40, is taken when t8(=(a0 << 0x26)) >= 0 (signed), and falls through when t8(=(a0 << 0x26)) < 0 (signed).
  The `beq` branch at 0x1f38 targets 0x20a4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1f54 targets 0x1f70, is taken when (s0(=a0) & 0x10) == 0, and falls through when (s0(=a0) & 0x10) != 0.
  The `beq` branch at 0x1f74 targets 0x1f84, is taken when (s0(=a0) & 0x400) == 0, and falls through when (s0(=a0) & 0x400) != 0.
  The `beq` branch at 0x1f84 targets 0x1f90, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x1fa4 targets 0x2068, is taken when a1(=[a1+114]:2) == a5(=0x1), and falls through when a1(=[a1+114]:2) != a5(=0x1).
  The `beq` branch at 0x1fac targets 0x206c, is taken when a1(=[a1+114]:2) == a4(=0x2), and falls through when a1(=[a1+114]:2) != a4(=0x2).
  The `bgez` branch at 0x1fb8 targets 0x1fc8, is taken when t0(=(a0 << 0x29)) >= 0 (signed), and falls through when t0(=(a0 << 0x29)) < 0 (signed).
  The `bgez` branch at 0x1fc8 targets 0x1fdc, is taken when t1(=(a0 << 0x28)) >= 0 (signed), and falls through when t1(=(a0 << 0x28)) < 0 (signed).
  The `bgez` branch at 0x1fdc targets 0x1fec, is taken when t3(=(a0 << 0x2d)) >= 0 (signed), and falls through when t3(=(a0 << 0x2d)) < 0 (signed).
  The `bgez` branch at 0x1fec targets 0x1ffc, is taken when t8(=(a0 << 0x2c)) >= 0 (signed), and falls through when t8(=(a0 << 0x2c)) < 0 (signed).
  The `bgez` branch at 0x2000 targets 0x200c, is taken when a1(=(a0 << 0x2b)) >= 0 (signed), and falls through when a1(=(a0 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0x2020 targets 0x2094, is taken when a2(=(a0 << 0x2a)) >= 0 (signed), and falls through when a2(=(a0 << 0x2a)) < 0 (signed).
  The `beq` branch at 0x2028 targets 0x203c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bgez` branch at 0x203c targets 0x2048, is taken when a0(=(a0 << 0x27)) >= 0 (signed), and falls through when a0(=(a0 << 0x27)) < 0 (signed).
  The `beq` branch at 0x2050 targets 0x205c, is taken when (a5(=[a1+116]:2) & 0x1) == 0, and falls through when (a5(=[a1+116]:2) & 0x1) != 0.
  The `beq` branch at 0x2074 targets 0x2080, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x2084 targets 0x1fb8, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x208c targets 0x1fb4 and is always taken.
  The `bne` branch at 0x2094 targets 0x2034, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x209c targets 0x203c and is always taken.
  The `beq` branch at 0x20b8 targets 0x1f40 and is always taken.
  The return at 0x2060 has v0 = ?.

- `pcibr_dmamap_alloc` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x20c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x20c0-0x253c (1148 bytes).
  It occupies 1148 bytes.
  The `lw` at 0x2100 loads 4 bytes from ret(pciio_info_mfast_get) +0x7c.
  The `lw` at 0x2110 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `lbu` at 0x2184 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lbu` at 0x218c loads 1 byte from ret(pciio_info_mfast_get) +0x30.
  The `sw` at 0x2194 stores 4 bytes to ret(kmem_zalloc) +0x4.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x72, including `lh` at 0x2198, `lh` at 0x243c.
  The `sb` at 0x21a8 stores 1 byte to ret(kmem_zalloc) +0x28.
  The `sd` at 0x21ac stores 8 bytes to ret(kmem_zalloc) +0x20.
  The `sd` at 0x21b0 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `sd` at 0x21b8 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sb` at 0x21c0 stores 1 byte to ret(kmem_zalloc) +0x8.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x74, including `lh` at 0x21f4, `lh` at 0x2390.
  3 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x0, including `sw` at 0x2244, `sw` at 0x238c, `sw` at 0x2428.
  The `ld` at 0x2248 loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  6 such `sd` accesses store 8 bytes to ret(kmem_zalloc) +0x38, including `sd` at 0x2254, `sd` at 0x2384, `sd` at 0x2438.
  3 such `sd` accesses store 8 bytes to ret(kmem_zalloc) +0x30, including `sd` at 0x225c, `sd` at 0x2388, `sd` at 0x24a4.
  2 such `lw` accesses load 4 bytes from ret(pciio_info_mfast_get) +0x51c, including `lw` at 0x23a0, `lw` at 0x24c8.
  The `lw` at 0x23d0 loads 4 bytes from ?.
  The `ld` at 0x246c loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `sd` at 0x24b0 stores 8 bytes to ret(kmem_zalloc) +0x50.
  The `sw` at 0x24b4 stores 4 bytes to ret(kmem_zalloc) +0x40.
  The `sd` at 0x24b8 stores 8 bytes to ret(kmem_zalloc) +0x48.
  The `sw` at 0x24c0 stores 4 bytes to ret(kmem_zalloc) +0x44.
  The `lw` at 0x24e0 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `jal` at 0x20e4 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x20f8 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x211c calls kmem_zalloc with a0=0x60, a1=?, a2=[ret(pciio_info_mfast_get)], a3=[ret(pciio_info_mfast_get)+124].
  The `jal` at 0x2170 calls xtalk_dmamap_alloc with a0=[ret(pciio_info_mfast_get)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x21d4 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=([ret(pciio_info_mfast_get)+124] | a3), a3=0x898000, a4=0xff.
  The `jal` at 0x21ec calls pcibr_debug with a0=0x60000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x2208 calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?, a4=-0x41.
  The `jal` at 0x2234 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x8f8000, a4=one of -0x41, 0xff.
  The `jal` at 0x2280 calls pcibr_ate_alloc with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?, a4=one of -0x41, 0xff.
  The `jal` at 0x22a0 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x1100000.
  The `jal` at 0x22c0 calls pcibr_debug with a0=0x20000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=ret(pcibr_ate_alloc).
  The `jal` at 0x22d0 calls pcibr_ate_free with a0=ret(pciio_info_mfast_get), a1=ret(pcibr_ate_alloc), a2=?, a3=?.
  The `jal` at 0x22e8 calls pcibr_debug with a0=0x60000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x22f0 calls xtalk_dmamap_free with a0=ret(xtalk_dmamap_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0x22fc calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `jal` at 0x231c calls pcibr_debug with a0=0x20000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x2324 calls xtalk_dmamap_free with a0=ret(xtalk_dmamap_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0x2330 calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `jal` at 0x235c calls pcibr_debug with a0=0x20000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x2368 calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `jal` at 0x237c calls pcibr_flags_to_d64 [0x1f0c] with a0=([ret(pciio_info_mfast_get)+124] | a3), a1=ret(pciio_info_mfast_get), a2=sym(.rodata), a3=?.
  The `jal` at 0x2420 calls pcibr_flags_to_ate with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x24a8 calls pcibr_ate_addr with a0=ret(pciio_info_mfast_get), a1=ret(pcibr_ate_alloc), a2=?, a3=?, a6=0x40000000, a7=[ret(pciio_info_mfast_get)+114]:2.
  The `jal` at 0x2514 calls pcibr_rrb_alloc_more with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?, a5=0x1, a7=one of 0x1, 0x2.
  The `jal` at 0x252c calls pcibr_rrb_alloc_more with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?, a6=one of 0x1, 0x2.
  The `bne` branch at 0x212c targets 0x2164, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x2178 targets 0x2350, is taken when v0(=ret(xtalk_dmamap_alloc)) == 0, and falls through when v0(=ret(xtalk_dmamap_alloc)) != 0.
  The `beq` branch at 0x2190 targets 0x2340, is taken when s3(=[ret(pciio_hostinfo_get)+540]:1) == a4(=0xff), and falls through when s3(=[ret(pciio_hostinfo_get)+540]:1) != a4(=0xff).
  The `beq` branch at 0x21a0 targets 0x2348, is taken when t8(=[ret(pciio_info_mfast_get)+114]:2) == t9(=0x2), and falls through when t8(=[ret(pciio_info_mfast_get)+114]:2) != t9(=0x2).
  The `beq` branch at 0x21bc targets 0x221c, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) != 0.
  The `beq` branch at 0x21dc targets 0x2378, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0x21fc targets 0x2218, is taken when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0x2210 targets 0x2138 and is always taken.
  The `beq` branch at 0x2220 targets 0x2260, is taken when (s0(?) & 0x1) == 0, and falls through when (s0(?) & 0x1) != 0.
  The `bne` branch at 0x223c targets 0x22e0, is taken when v0(=ret(pcibr_try_set_device)) != 0, and falls through when v0(=ret(pcibr_try_set_device)) == 0.
  The `beq` branch at 0x2258 targets 0x2138 and is always taken.
  The `beq` branch at 0x2264 targets 0x2408, is taken when (s0(?) & 0x8000) == 0, and falls through when (s0(?) & 0x8000) != 0.
  The `beq` branch at 0x228c targets 0x230c, is taken when v0(=ret(pcibr_ate_alloc)) == t0(=-0x1), and falls through when v0(=ret(pcibr_ate_alloc)) != t0(=-0x1).
  The `beq` branch at 0x22a8 targets 0x2420, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0x22d8 targets 0x2314 and is always taken.
  The `beq` branch at 0x2304 targets 0x2138 and is always taken.
  The `beq` branch at 0x2338 targets 0x2138 and is always taken.
  The `beq` branch at 0x2340 targets 0x21a8 and is always taken.
  The `beq` branch at 0x2348 targets 0x21a8 and is always taken.
  The `beq` branch at 0x2370 targets 0x2138 and is always taken.
  The `bne` branch at 0x2398 targets 0x2400, is taken when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0, and falls through when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0.
  The `bne` branch at 0x23b0 targets 0x2400, is taken when (a4(=[ret(pciio_info_mfast_get)+1308]) & a5(?)) != 0, and falls through when (a4(=[ret(pciio_info_mfast_get)+1308]) & a5(?)) == 0.
  The `beq` branch at 0x23d8 targets 0x2400, is taken when a6(?) >= 0x2 (signed), and falls through when a6(?) < 0x2 (signed).
  The `bne` branch at 0x23f8 targets 0x2510, is taken when a6(?) < a7(=one of 0x1, 0x2) (signed), and falls through when a6(?) >= a7(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0x2400 targets 0x213c and is always taken.
  The `beq` branch at 0x2418 targets 0x227c and is always taken.
  The `beq` branch at 0x2440 targets 0x24a0, is taken when a7(=[ret(pciio_info_mfast_get)+114]:2) == 0, and falls through when a7(=[ret(pciio_info_mfast_get)+114]:2) != 0.
  The `beq` branch at 0x244c targets 0x2468, is taken when (s0(?) & 0x1000) == 0, and falls through when (s0(?) & 0x1000) != 0.
  The `bgez` branch at 0x2474 targets 0x248c, is taken when a2(=([(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8 << 0x2b)) >= 0 (signed), and falls through when a2(=([(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8 << 0x2b)) < 0 (signed).
  The `beq` branch at 0x248c targets 0x24a0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x24d4 targets 0x2508, is taken when (a6(=[ret(pciio_info_mfast_get)+1308]) & a7(?)) != 0, and falls through when (a6(=[ret(pciio_info_mfast_get)+1308]) & a7(?)) == 0.
  The `beq` branch at 0x24e8 targets 0x2508, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) >= 0x2 (signed), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) < 0x2 (signed).
  The `bne` branch at 0x2500 targets 0x2524, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) < a6(=one of 0x1, 0x2) (signed), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) >= a6(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0x2508 targets 0x213c and is always taken.
  The `beq` branch at 0x251c targets 0x2400 and is always taken.
  The `beq` branch at 0x2534 targets 0x2508 and is always taken.
  The return at 0x215c has v0 = one of ?, ret(kmem_zalloc).

- `pcibr_dmamap_free` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x253c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x253c-0x25f0 (180 bytes).
  It occupies 180 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x2544, `ld` at 0x25b0.
  The `lbu` at 0x2548 loads 1 byte from a0 (arg0 at entry) +0x8.
  The `lh` at 0x256c loads 2 bytes from [a0+16]:8 +0x72.
  The `ld` at 0x2580 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x2584 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0x25a4 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `lw` at 0x25b8 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `jal` at 0x257c calls xtalk_dmamap_free with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=[a0+8]:1, a3=a3 at entry (arg3).
  The `jal` at 0x259c calls pcibr_release_device with a0=[a0+16]:8, a1=?, a2=0x898000, a3=?.
  The `jal` at 0x25b4 calls pcibr_ate_free with a0=[a0+16]:8, a1=[a0+64], a2=[a0+68], a3=?.
  The `jal` at 0x25c4 calls pcibr_release_device with a0=[a0+16]:8, a1=?, a2=0x1100000, a3=?.
  The `jal` at 0x25d8 calls kmem_free with a0=a0 at entry (arg0), a1=0x60, a2=?, a3=?.
  The `beq` branch at 0x2564 targets 0x257c, is taken when a2(=[a0+8]:1) == at(=0xff), and falls through when a2(=[a0+8]:1) != at(=0xff).
  The `beq` branch at 0x2570 targets 0x257c, is taken when v0(=[[a0+16]:8+114]:2) == v1(=0x2), and falls through when v0(=[[a0+16]:8+114]:2) != v1(=0x2).
  The `beq` branch at 0x258c targets 0x25a4, is taken when (a0(=[a0]) & 0x40) == 0, and falls through when (a0(=[a0]) & 0x40) != 0.
  The `beq` branch at 0x25a8 targets 0x25cc, is taken when a2(=[a0+68]) == 0, and falls through when a2(=[a0+68]) != 0.
  The return at 0x25e8 has v0 = ret(kmem_free).

- `pcibr_addr_xio_to_pci` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x25f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x25f0-0x2878 (648 bytes).
  It occupies 648 bytes.
  The `lh` at 0x25f0 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lbu` at 0x2668 loads 1 byte from a0 (arg0 at entry) +0x39.
  The `lbu` at 0x266c loads 1 byte from a0 (arg0 at entry) +0x38.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x48, including `lw` at 0x2688, `lw` at 0x2778.
  The `ld` at 0x2728 loads 8 bytes from ?.
  The `beq` branch at 0x260c targets 0x2778, is taken when at(=[a0+114]:2) == v1(=0x2), and falls through when at(=[a0+114]:2) != v1(=0x2).
  The `bne` branch at 0x261c targets 0x2640, is taken when a1 < a3(=0x40000000) (unsigned), and falls through when a1 >= a3(=0x40000000) (unsigned).
  The `beq` branch at 0x2638 targets 0x27e4, is taken when v1(=0x7fffffff) >= a3(=(a1 + a2)-1) (unsigned), and falls through when v1(=0x7fffffff) < a3(=(a1 + a2)-1) (unsigned).
  The `bne` branch at 0x2650 targets 0x2668, is taken when a1 < a3(=0x80000000) (unsigned), and falls through when a1 >= a3(=0x80000000) (unsigned).
  The `beq` branch at 0x2660 targets 0x27ec, is taken when a5(=0xbfffffff) >= v1(=(a1 + a2)-1) (unsigned), and falls through when a5(=0xbfffffff) < v1(=(a1 + a2)-1) (unsigned).
  The `beq` branch at 0x2678 targets 0x2704, is taken when v0(=[a0+56]:1) >= t3(=[a0+57]:1+1) (signed), and falls through when v0(=[a0+56]:1) < t3(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x26a0 targets 0x2860 and is always taken.
  The `bne` branch at 0x26b4 targets 0x26d0, is taken when a1 < a2(?) (unsigned), and falls through when a1 >= a2(?) (unsigned).
  The `blez` branch at 0x26bc targets 0x2760, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `bne` branch at 0x26c8 targets 0x2718, is taken when s0(=(a1 + a2)-1) < a2(?) (unsigned), and falls through when s0(=(a1 + a2)-1) >= a2(?) (unsigned).
  The `beq` branch at 0x26e4 targets 0x2704, is taken when v0(?) >= t3(=[a0+57]:1+1) (signed), and falls through when v0(?) < t3(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x26f4 targets 0x26a8, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x26fc targets 0x26ac and is always taken.
  The `beq` branch at 0x2724 targets 0x2738, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x2730 targets 0x273c and is always taken.
  The `beq` branch at 0x274c targets 0x2758, is taken when (a2(?) & 0x1000) == 0, and falls through when (a2(?) & 0x1000) != 0.
  The `beq` branch at 0x2758 targets 0x270c and is always taken.
  The `beq` branch at 0x2770 targets 0x26c4 and is always taken.
  The `beq` branch at 0x277c targets 0x27f4, is taken when a7(=[a0+72]) == 0, and falls through when a7(=[a0+72]) != 0.
  The `bne` branch at 0x2784 targets 0x2618, is taken when a7(=[a0+72]) != v0(=0x1), and falls through when a7(=[a0+72]) == v0(=0x1).
  The `bne` branch at 0x2798 targets 0x27b0, is taken when a1 < a4(=0xc0000000) (unsigned), and falls through when a1 >= a4(=0xc0000000) (unsigned).
  The `beq` branch at 0x27ac targets 0x2854, is taken when a5(=0xffffffff) >= a6(=(a1 + a2)-1) (unsigned), and falls through when a5(=0xffffffff) < a6(=(a1 + a2)-1) (unsigned).
  The `bne` branch at 0x27bc targets 0x2668, is taken when a1 < a6(=0x100000000) (unsigned), and falls through when a1 >= a6(=0x100000000) (unsigned).
  The `bne` branch at 0x27d0 targets 0x2668, is taken when a7(=0x13fffffff) < t0(=(a1 + a2)-1) (unsigned), and falls through when a7(=0x13fffffff) >= t0(=(a1 + a2)-1) (unsigned).
  The `beq` branch at 0x27dc targets 0x2708 and is always taken.
  The `beq` branch at 0x27e4 targets 0x270c and is always taken.
  The `beq` branch at 0x27ec targets 0x270c and is always taken.
  The `bne` branch at 0x2800 targets 0x2824, is taken when a1 < v1(=0x40000000) (unsigned), and falls through when a1 >= v1(=0x40000000) (unsigned).
  The `beq` branch at 0x281c targets 0x2848, is taken when a3(=0x7fffffff) >= a4(=(a1 + a2)-1) (unsigned), and falls through when a3(=0x7fffffff) < a4(=(a1 + a2)-1) (unsigned).
  The `bne` branch at 0x2824 targets 0x2668, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x2838 targets 0x2668, is taken when a4(=0xbfffffff) < a5(=(a1 + a2)-1) (unsigned), and falls through when a4(=0xbfffffff) >= a5(=(a1 + a2)-1) (unsigned).
  The `beq` branch at 0x2840 targets 0x2708 and is always taken.
  The `beq` branch at 0x284c targets 0x2708 and is always taken.
  The `beq` branch at 0x2858 targets 0x2708 and is always taken.
  The `beq` branch at 0x2870 targets 0x26f0 and is always taken.
  The return at 0x2710 has v0 = one of ?, a1+0xffffffffc0000000, a1+0xffffffff80000000.

- `pcibr_dmamap_addr` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x2878 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x2878-0x2a64 (492 bytes).
  It occupies 492 bytes.
  The `ld` at 0x2880 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0x2888 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0x28ac loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `lbu` at 0x28d8 loads 1 byte from [a0+16]:8 +0x28.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x28f8, `ld` at 0x29d8, `ld` at 0x2a20.
  The `lbu` at 0x2938 loads 1 byte from a0 (arg0 at entry) +0x28.
  The `lbu` at 0x2948 loads 1 byte from [a0+16]:8 +0x58.
  The `ld` at 0x2958 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `lw` at 0x29b4 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `ld` at 0x29bc loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `lw` at 0x2a0c loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x2a50 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x28a8 calls xtalk_dmamap_addr with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2994 calls pcibr_addr_xio_to_pci [0x25f0] with a0=[a0+16]:8, a1=?, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x2a10 calls ate_write with a0=[a0+16]:8, a1=a0 at entry (arg0), a2=[a0+64], a3=?, a6=[a0+68].
  The `jal` at 0x2a54 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a1 at entry (arg1), a4=(a1 + a2)-1, a6=[a0+68].
  The `beq` branch at 0x28c4 targets 0x2934, is taken when (v0(=ret(xtalk_dmamap_addr)) & at(=0xf000000000000000)) == 0, and falls through when (v0(=ret(xtalk_dmamap_addr)) & at(=0xf000000000000000)) != 0.
  The `beq` branch at 0x28e8 targets 0x298c, is taken when t3(=[[a0+16]:8+40]:1) == t2(?), and falls through when t3(=[[a0+16]:8+40]:1) != t2(?).
  The `beq` branch at 0x28f0 targets 0x293c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x2934 targets 0x28d8 and is always taken.
  The `beq` branch at 0x2940 targets 0x29b4, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `bne` branch at 0x2950 targets 0x29a4, is taken when v0(=[[a0+16]:8+88]:1) != t2(?), and falls through when v0(=[[a0+16]:8+88]:1) == t2(?).
  The `bne` branch at 0x2960 targets 0x29ac, is taken when t1(?) < v0(=[a0+48]:8) (unsigned), and falls through when t1(?) >= v0(=[a0+48]:8) (unsigned).
  The `bne` branch at 0x2974 targets 0x2a30, is taken when a3(=[a0+48]:8+0x80000000) < a1(?) (unsigned), and falls through when a3(=[a0+48]:8+0x80000000) >= a1(?) (unsigned).
  The `bne` branch at 0x297c targets 0x2a20, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x2984 targets 0x2914 and is always taken.
  The `beq` branch at 0x299c targets 0x2910 and is always taken.
  The `beq` branch at 0x29a4 targets 0x2914 and is always taken.
  The `beq` branch at 0x29ac targets 0x2910 and is always taken.
  The `bgez` branch at 0x29c8 targets 0x29d8, is taken when a1(=([a0] << 0x2c)) >= 0 (signed), and falls through when a1(=([a0] << 0x2c)) < 0 (signed).
  The `bne` branch at 0x29ec targets 0x2a38, is taken when a6(=[a0+68]) < a5(?) (signed), and falls through when a6(=[a0+68]) >= a5(?) (signed).
  The `beq` branch at 0x2a18 targets 0x2914 and is always taken.
  The `beq` branch at 0x2a28 targets 0x2910 and is always taken.
  The `beq` branch at 0x2a30 targets 0x2910 and is always taken.
  The `beq` branch at 0x2a5c targets 0x2910 and is always taken.
  The return at 0x292c has v0 = one of ?, 0x0.

- `pcibr_dmamap_list` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x2a64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x2a64-0x2e04 (928 bytes).
  It occupies 928 bytes.
  The `ld` at 0x2a6c loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x2a78 loads 8 bytes from a0 (arg0 at entry) +0x18.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x2ac0, `lw` at 0x2c08, `lw` at 0x2d04.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x2b28, `lw` at 0x2da0.
  The `ld` at 0x2b54 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `lbu` at 0x2bb0 loads 1 byte from [a0+16]:8 +0x28.
  The `lw` at 0x2c94 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `lw` at 0x2d30 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `ld` at 0x2d34 loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `lbu` at 0x2d44 loads 1 byte from a0 (arg0 at entry) +0x28.
  The `jal` at 0x2a94 calls xtalk_dmamap_list with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x2ac4 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x2b0c calls alenlist_cursor_init with a0=ret(xtalk_dmamap_list), a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x2b58 calls alenlist_get with a0=ret(xtalk_dmamap_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0x2bf0 calls alenlist_append with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2c0c calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x2c30 calls alenlist_get with a0=ret(xtalk_dmamap_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0x2c4c calls alenlist_cursor_init with a0=?, a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x2cbc calls ate_write with a0=[a0+16]:8, a1=a0 at entry (arg0), a2=?, a3=?, a6=[a0+68].
  The `jal` at 0x2cec calls alenlist_replace with a0=?, a1=0x0, a2=sp-144, a3=sp-152.
  The `jal` at 0x2d08 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x2d20 calls alenlist_destroy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2d50 calls pcibr_addr_xio_to_pci [0x25f0] with a0=[a0+16]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x2d6c calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x2d80 calls alenlist_create with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2da4 calls alenlist_done with a0=ret(xtalk_dmamap_list), a1=?, a2=?, a3=?.
  The `jal` at 0x2dc8 calls pcibr_debug with a0=0x10, a1=[a0+4], a2=sym(.rodata), a3=?, a6=[a0+68].
  The `jal` at 0x2df4 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `bne` branch at 0x2aac targets 0x2b04, is taken when v0(=ret(xtalk_dmamap_list)) != 0, and falls through when v0(=ret(xtalk_dmamap_list)) == 0.
  The `beq` branch at 0x2b1c targets 0x2d7c, is taken when (s8(=a2) & 0x4) == 0, and falls through when (s8(=a2) & 0x4) != 0.
  The `beq` branch at 0x2b30 targets 0x2d30, is taken when (t8(=[a0]) & 0x40) == 0, and falls through when (t8(=[a0]) & 0x40) != 0.
  The `bne` branch at 0x2b60 targets 0x2c40, is taken when v0(=ret(alenlist_get)) != 0, and falls through when v0(=ret(alenlist_get)) == 0.
  The `beq` branch at 0x2b98 targets 0x2d40, is taken when (a3(?) & a0(=0xf000000000000000)) == 0, and falls through when (a3(?) & a0(=0xf000000000000000)) != 0.
  The `beq` branch at 0x2bb4 targets 0x2d48, is taken when a0(=[[a0+16]:8+40]:1) == v0(?), and falls through when a0(=[[a0+16]:8+40]:1) != v0(?).
  The `beq` branch at 0x2bbc targets 0x2c5c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2bcc targets 0x2cd4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x2bdc targets 0x2cdc, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `beq` branch at 0x2bf8 targets 0x2c20, is taken when v0(=ret(alenlist_append)) == 0, and falls through when v0(=ret(alenlist_append)) != 0.
  The `beq` branch at 0x2c14 targets 0x2d10 and is always taken.
  The `beq` branch at 0x2c38 targets 0x2b7c, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0x2c40 targets 0x2da4, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `beq` branch at 0x2c54 targets 0x2ad4 and is always taken.
  The `beq` branch at 0x2c7c targets 0x2dd8, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x2ca8 targets 0x2db4, is taken when a6(=[a0+68]) < a7(?) (signed), and falls through when a6(=[a0+68]) >= a7(?) (signed).
  The `beq` branch at 0x2cd4 targets 0x2be8, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `beq` branch at 0x2cf4 targets 0x2c20, is taken when v0(=ret(alenlist_replace)) == 0, and falls through when v0(=ret(alenlist_replace)) != 0.
  The `beq` branch at 0x2d10 targets 0x2acc, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0x2d18 targets 0x2acc, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `beq` branch at 0x2d28 targets 0x2ad0 and is always taken.
  The `beq` branch at 0x2d38 targets 0x2b40 and is always taken.
  The `beq` branch at 0x2d40 targets 0x2bb0 and is always taken.
  The `bne` branch at 0x2d58 targets 0x2cd4, is taken when v0(=ret(pcibr_addr_xio_to_pci)) != 0, and falls through when v0(=ret(pcibr_addr_xio_to_pci)) == 0.
  The `beq` branch at 0x2d74 targets 0x2d10 and is always taken.
  The `beq` branch at 0x2d8c targets 0x2de4, is taken when v0(=ret(alenlist_create)) == 0, and falls through when v0(=ret(alenlist_create)) != 0.
  The `bne` branch at 0x2d94 targets 0x2d10, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x2d9c targets 0x2b2c and is always taken.
  The `beq` branch at 0x2dac targets 0x2c48 and is always taken.
  The `beq` branch at 0x2dd0 targets 0x2d10 and is always taken.
  The `beq` branch at 0x2ddc targets 0x2c84 and is always taken.
  The `beq` branch at 0x2dfc targets 0x2d94 and is always taken.
  The return at 0x2afc has v0 = one of 0x0, ?.
  The instructions from 0x2c1c to 0x2c1c are not reached by any path from the entry, and their branches are not listed.

- `pcibr_dmamap_done` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x2e04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x2e04-0x2e20 (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0x2e10 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `jal` at 0x2e0c calls xtalk_dmamap_done with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x2e18 has v0 = ret(xtalk_dmamap_done).

- `pcibr_get_dmatrans_node` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x2e20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x2e20-0x2e28 (8 bytes).
  It occupies 8 bytes.
  The return at 0x2e20 has v0 = 0x0.

- `pcibr_dmatrans_addr` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x2e28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x2e28-0x31d4 (940 bytes).
  It occupies 940 bytes.
  The `lw` at 0x2e6c loads 4 bytes from ret(pciio_info_mfast_get) +0x7c.
  The `lw` at 0x2e7c loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `lbu` at 0x2e84 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lbu` at 0x2ed0 loads 1 byte from ret(pciio_info_mfast_get) +0x28.
  The `ld` at 0x2efc loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x150.
  The `lw` at 0x2f0c loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x74, including `lh` at 0x2f70, `lh` at 0x30b0.
  The `ld` at 0x2f9c loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  The `lbu` at 0x2fc4 loads 1 byte from ret(pciio_info_mfast_get) +0x58.
  The `ld` at 0x2fe0 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  The `lw` at 0x2fec loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `lbu` at 0x302c loads 1 byte from ret(pciio_info_mfast_get) +0x30.
  The `sd` at 0x30a8 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x150.
  The `sw` at 0x30ac stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `sw` at 0x30d0 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `sd` at 0x30d4 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  2 such `lw` accesses load 4 bytes from ret(pciio_info_mfast_get) +0x51c, including `lw` at 0x30d8, `lw` at 0x3130.
  The `lw` at 0x30f4 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `ld` at 0x3104 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `lw` at 0x3184 loads 4 bytes from ?.
  The `jal` at 0x2e4c calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2e60 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x2e88 calls xtalk_dmatrans_addr with a0=[ret(pciio_info_mfast_get)], a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2f60 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x898000.
  The `jal` at 0x3010 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x8f8000.
  The `jal` at 0x3040 calls pcibr_addr_xio_to_pci [0x25f0] with a0=ret(pciio_info_mfast_get), a1=?, a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x306c calls pcibr_debug with a0=0x40000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a2 at entry (arg2), a4=(a2 + a3)-1, a5=ret(xtalk_dmatrans_addr).
  The `jal` at 0x3090 calls pcibr_debug with a0=0x40000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a2 at entry (arg2), a4=(a2 + a3)-1.
  The `jal` at 0x30a0 calls pcibr_flags_to_d64 [0x1f0c] with a0=?, a1=ret(pciio_info_mfast_get), a2=?, a3=?.
  The `jal` at 0x3160 calls pcibr_rrb_alloc_more with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?, a4=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384], a7=0x1.
  The `jal` at 0x31c4 calls pcibr_rrb_alloc_more with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?, a6=0x1.
  The `beq` branch at 0x2e98 targets 0x3050, is taken when v0(=ret(xtalk_dmatrans_addr)) == 0, and falls through when v0(=ret(xtalk_dmatrans_addr)) != 0.
  The `beq` branch at 0x2eac targets 0x3028, is taken when (v0(=ret(xtalk_dmatrans_addr)) & v1(=0xf000000000000000)) == 0, and falls through when (v0(=ret(xtalk_dmatrans_addr)) & v1(=0xf000000000000000)) != 0.
  The `beq` branch at 0x2eb4 targets 0x307c, is taken when v0(=ret(xtalk_dmatrans_addr)) == a0(=-0x1), and falls through when v0(=ret(xtalk_dmatrans_addr)) != a0(=-0x1).
  The `beq` branch at 0x2ed4 targets 0x303c, is taken when t8(=[ret(pciio_info_mfast_get)+40]:1) == s5(?), and falls through when t8(=[ret(pciio_info_mfast_get)+40]:1) != s5(?).
  The `beq` branch at 0x2ee0 targets 0x2f90, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a4)) & 0x40) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a4)) & 0x40) != 0.
  The `bgez` branch at 0x2ef8 targets 0x3030, is taken when ra(=(([ret(pciio_info_mfast_get)+124] | a4) << 0x26)) >= 0 (signed), and falls through when ra(=(([ret(pciio_info_mfast_get)+124] | a4) << 0x26)) < 0 (signed).
  The `beq` branch at 0x2f04 targets 0x2f54, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+336]:8) == t8(=-0x1), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+336]:8) != t8(=-0x1).
  The `bne` branch at 0x2f10 targets 0x2f50, is taken when t9(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]) != s0(?), and falls through when t9(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]) == s0(?).
  The `beq` branch at 0x2f68 targets 0x30a0, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0x2f78 targets 0x2f88, is taken when (a4(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (a4(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0x2f80 targets 0x2f20 and is always taken.
  The `bne` branch at 0x2f98 targets 0x3020, is taken when s7(=0x80000000) < s4(=a3) (unsigned), and falls through when s7(=0x80000000) >= s4(=a3) (unsigned).
  The `bne` branch at 0x2fa4 targets 0x3020, is taken when s3(?) < v0(=[ret(pciio_info_mfast_get)+80]:8) (unsigned), and falls through when s3(?) >= v0(=[ret(pciio_info_mfast_get)+80]:8) (unsigned).
  The `beq` branch at 0x2fbc targets 0x3020, is taken when t9(?) >= s7(=0x80000000) (unsigned), and falls through when t9(?) < s7(=0x80000000) (unsigned).
  The `bne` branch at 0x2fc8 targets 0x3020, is taken when ra(=[ret(pciio_info_mfast_get)+88]:1) != s5(?), and falls through when ra(=[ret(pciio_info_mfast_get)+88]:1) == s5(?).
  The `bne` branch at 0x2fd8 targets 0x3020, is taken when s7(=0x80000000) < at(?) (unsigned), and falls through when s7(=0x80000000) >= at(?) (unsigned).
  The `beq` branch at 0x2fe4 targets 0x3000, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]:8) == a1(=0xffffffff), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]:8) != a1(=0xffffffff).
  The `bne` branch at 0x2ff0 targets 0x3000, is taken when v1(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]) != s0(?), and falls through when v1(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]) == s0(?).
  The `beq` branch at 0x2ff8 targets 0x2f24 and is always taken.
  The `beq` branch at 0x3018 targets 0x30d0, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0x3020 targets 0x2f20 and is always taken.
  The `beq` branch at 0x3028 targets 0x2ed0 and is always taken.
  The `beq` branch at 0x3034 targets 0x2f00 and is always taken.
  The `beq` branch at 0x3048 targets 0x2f20 and is always taken.
  The `beq` branch at 0x3074 targets 0x2f20 and is always taken.
  The `beq` branch at 0x3098 targets 0x2f20 and is always taken.
  The `beq` branch at 0x30b8 targets 0x3130, is taken when (a5(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (a5(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0x30c8 targets 0x2f20 and is always taken.
  The `bne` branch at 0x30e8 targets 0x3128, is taken when (t8(=[ret(pciio_info_mfast_get)+1308]) & t9(?)) != 0, and falls through when (t8(=[ret(pciio_info_mfast_get)+1308]) & t9(?)) == 0.
  The `beq` branch at 0x30fc targets 0x3128, is taken when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) >= 0x2 (signed), and falls through when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) < 0x2 (signed).
  The `bne` branch at 0x3120 targets 0x3158, is taken when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) < v0(=one of 0x1, 0x2) (signed), and falls through when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1384]) >= v0(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0x3128 targets 0x2f20 and is always taken.
  The `beq` branch at 0x3140 targets 0x3170, is taken when (t0(=[ret(pciio_info_mfast_get)+1308]) & t1(?)) == 0, and falls through when (t0(=[ret(pciio_info_mfast_get)+1308]) & t1(?)) != 0.
  The `beq` branch at 0x3150 targets 0x30c8 and is always taken.
  The `beq` branch at 0x3168 targets 0x3128 and is always taken.
  The `beq` branch at 0x3194 targets 0x30c8, is taken when a4(?) >= 0x2 (signed), and falls through when a4(?) < 0x2 (signed).
  The `beq` branch at 0x31b8 targets 0x30c8, is taken when a4(?) >= v0(=one of 0x1, 0x2) (signed), and falls through when a4(?) < v0(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0x31cc targets 0x30c8 and is always taken.
  The return at 0x2f48 has v0 = ?.

- `pcibr_dmatrans_list` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x31d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x31d4-0x359c (968 bytes).
  It occupies 968 bytes.
  The `lw` at 0x3214 loads 4 bytes from ret(pciio_info_mfast_get) +0x7c.
  The `lbu` at 0x321c loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0x3224 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `ld` at 0x3244 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x150.
  The `lw` at 0x3254 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `lbu` at 0x3370 loads 1 byte from ret(pciio_info_mfast_get) +0x28.
  The `sd` at 0x33e8 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x150.
  The `sw` at 0x33ec stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `ld` at 0x3444 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  The `ld` at 0x3454 loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  The `lw` at 0x3464 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `sd` at 0x34e0 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  The `sw` at 0x34e8 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `lbu` at 0x34f0 loads 1 byte from ret(pciio_info_mfast_get) +0x30.
  The `lbu` at 0x351c loads 1 byte from ret(pciio_info_mfast_get) +0x58.
  The `jal` at 0x31e8 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3200 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3278 calls xtalk_dmatrans_list with a0=?, a1=0x0, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x3298 calls pcibr_release_device with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=one of 0x0, 0x898000, 0x8f8000, a3=?.
  The `jal` at 0x32f0 calls alenlist_cursor_init with a0=ret(xtalk_dmatrans_list), a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x332c calls alenlist_get with a0=ret(xtalk_dmatrans_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0x33a4 calls alenlist_replace with a0=?, a1=0x0, a2=sp-144, a3=sp-152.
  The `jal` at 0x33c4 calls alenlist_get with a0=ret(xtalk_dmatrans_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0x33fc calls alenlist_cursor_init with a0=?, a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x341c calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=([ret(pciio_info_mfast_get)+124] | a3), a3=0x898000.
  The `jal` at 0x342c calls pcibr_flags_to_d64 [0x1f0c] with a0=([ret(pciio_info_mfast_get)+124] | a3), a1=ret(pciio_info_mfast_get), a2=?, a3=?.
  The `jal` at 0x3488 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=([ret(pciio_info_mfast_get)+124] | a3), a3=0x8f8000.
  The `jal` at 0x34b0 calls alenlist_destroy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x34c4 calls pcibr_addr_xio_to_pci [0x25f0] with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3550 calls alenlist_append with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3568 calls alenlist_create with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3584 calls alenlist_done with a0=ret(xtalk_dmatrans_list), a1=?, a2=?, a3=?.
  The `beq` branch at 0x323c targets 0x3444, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) != 0.
  The `beq` branch at 0x324c targets 0x3410, is taken when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+336]:8) == ra(=-0x1), and falls through when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+336]:8) != ra(=-0x1).
  The `bne` branch at 0x3258 targets 0x340c, is taken when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]) != s0(=([ret(pciio_info_mfast_get)+124] | a3)), and falls through when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]) == s0(=([ret(pciio_info_mfast_get)+124] | a3)).
  The `bne` branch at 0x3280 targets 0x32e8, is taken when v0(=ret(xtalk_dmatrans_list)) != 0, and falls through when v0(=ret(xtalk_dmatrans_list)) == 0.
  The `beq` branch at 0x328c targets 0x32a0, is taken when s4(=one of 0x0, 0x898000, 0x8f8000) == 0, and falls through when s4(=one of 0x0, 0x898000, 0x8f8000) != 0.
  The `beq` branch at 0x32a0 targets 0x32b0, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x32a8 targets 0x34b0, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x330c targets 0x3568, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x4) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x4) != 0.
  The `bne` branch at 0x3334 targets 0x33d4, is taken when v0(=ret(alenlist_get)) != 0, and falls through when v0(=ret(alenlist_get)) == 0.
  The `beq` branch at 0x3358 targets 0x34ec, is taken when (a1(?) & v0(=0xf000000000000000)) == 0, and falls through when (a1(?) & v0(=0xf000000000000000)) != 0.
  The `beq` branch at 0x3360 targets 0x3594, is taken when v1(=-0x1) == a1(?), and falls through when v1(=-0x1) != a1(?).
  The `beq` branch at 0x3378 targets 0x34c0, is taken when a0(=[ret(pciio_info_mfast_get)+40]:1) == v0(?), and falls through when a0(=[ret(pciio_info_mfast_get)+40]:1) != v0(?).
  The `beq` branch at 0x3380 targets 0x34f4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x3390 targets 0x3544, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0x33ac targets 0x328c, is taken when v0(=ret(alenlist_replace)) != 0, and falls through when v0(=ret(alenlist_replace)) == 0.
  The `beq` branch at 0x33cc targets 0x3340, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0x33d4 targets 0x33f0, is taken when s4(=one of 0x0, 0x898000, 0x8f8000) == 0, and falls through when s4(=one of 0x0, 0x898000, 0x8f8000) != 0.
  The `beq` branch at 0x33e0 targets 0x34e0, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x33f0 targets 0x3584, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0x3404 targets 0x32b8 and is always taken.
  The `bltz` branch at 0x3424 targets 0x32b0, is taken when v0(=ret(pcibr_try_set_device)) < 0 (signed), and falls through when v0(=ret(pcibr_try_set_device)) >= 0 (signed).
  The `beq` branch at 0x343c targets 0x3260 and is always taken.
  The `beq` branch at 0x345c targets 0x3478, is taken when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]:8) == s7(=0xffffffff), and falls through when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]:8) != s7(=0xffffffff).
  The `bne` branch at 0x3468 targets 0x347c, is taken when t8(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]) != s0(=([ret(pciio_info_mfast_get)+124] | a3)), and falls through when t8(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]) == s0(=([ret(pciio_info_mfast_get)+124] | a3)).
  The `beq` branch at 0x3470 targets 0x3270 and is always taken.
  The `bltz` branch at 0x3490 targets 0x32b0, is taken when v0(=ret(pcibr_try_set_device)) < 0 (signed), and falls through when v0(=ret(pcibr_try_set_device)) >= 0 (signed).
  The `beq` branch at 0x34a8 targets 0x326c and is always taken.
  The `beq` branch at 0x34b8 targets 0x32b4 and is always taken.
  The `bne` branch at 0x34d0 targets 0x338c, is taken when v0(=ret(pcibr_addr_xio_to_pci)) != 0, and falls through when v0(=ret(pcibr_addr_xio_to_pci)) == 0.
  The `beq` branch at 0x34d8 targets 0x328c and is always taken.
  The `beq` branch at 0x34e4 targets 0x33f0 and is always taken.
  The `beq` branch at 0x34ec targets 0x3370 and is always taken.
  The `bne` branch at 0x34fc targets 0x328c, is taken when s7(=one of 0x80000000, 0x1000000000000) < a2(?) (unsigned), and falls through when s7(=one of 0x80000000, 0x1000000000000) >= a2(?) (unsigned).
  The `beq` branch at 0x3508 targets 0x328c, is taken when t9(?) >= s7(=one of 0x80000000, 0x1000000000000) (unsigned), and falls through when t9(?) < s7(=one of 0x80000000, 0x1000000000000) (unsigned).
  The `bne` branch at 0x3514 targets 0x328c, is taken when a1(?) < ra(?) (unsigned), and falls through when a1(?) >= ra(?) (unsigned).
  The `bne` branch at 0x3520 targets 0x328c, is taken when at(=[ret(pciio_info_mfast_get)+88]:1) != v0(?), and falls through when at(=[ret(pciio_info_mfast_get)+88]:1) == v0(?).
  The `bne` branch at 0x3534 targets 0x328c, is taken when s7(=one of 0x80000000, 0x1000000000000) < v1(?) (unsigned), and falls through when s7(=one of 0x80000000, 0x1000000000000) >= v1(?) (unsigned).
  The `beq` branch at 0x353c targets 0x338c and is always taken.
  The `bne` branch at 0x3558 targets 0x328c, is taken when v0(=ret(alenlist_append)) != 0, and falls through when v0(=ret(alenlist_append)) == 0.
  The `beq` branch at 0x3560 targets 0x33b4 and is always taken.
  The `beq` branch at 0x3574 targets 0x3318, is taken when v0(=ret(alenlist_create)) >= 0x1 (unsigned), and falls through when v0(=ret(alenlist_create)) < 0x1 (unsigned).
  The `beq` branch at 0x357c targets 0x328c and is always taken.
  The `beq` branch at 0x358c targets 0x33f8 and is always taken.
  The `beq` branch at 0x3594 targets 0x32b4 and is always taken.
  The return at 0x32e0 has v0 = one of 0x0, ?.

- `pcibr_dmamap_drain` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x359c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x359c-0x35b8 (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0x35a8 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `jal` at 0x35a4 calls xtalk_dmamap_drain with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x35b0 has v0 = ret(xtalk_dmamap_drain).

- `pcibr_dmaaddr_drain` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x35b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x35b8-0x35f8 (64 bytes).
  It occupies 64 bytes.
  The `lw` at 0x35d8 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0x35c8 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x35d0 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x35e0 calls xtalk_dmaaddr_drain with a0=[ret(pciio_info_mfast_get)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The return at 0x35f0 has v0 = ret(xtalk_dmaaddr_drain).

- `pcibr_dmalist_drain` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x35f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x35f8-0x3630 (56 bytes).
  It occupies 56 bytes.
  The `lw` at 0x3614 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0x3604 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x360c calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3618 calls xtalk_dmalist_drain with a0=[ret(pciio_info_mfast_get)], a1=a1 at entry (arg1), a2=?, a3=?.
  The return at 0x3628 has v0 = ret(xtalk_dmalist_drain).

- `pcibr_dmamap_pciaddr_get` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x3630 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x3630-0x3638 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0x3634 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The return at 0x3630 has v0 = [a0+56]:8.

- `pcibr_provider_startup` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x3638 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x3638-0x3640 (8 bytes).
  It occupies 8 bytes.
  The return at 0x3638 has v0 = ?.

- `pcibr_provider_shutdown` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x3640 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x3640-0x3648 (8 bytes).
  It occupies 8 bytes.
  The return at 0x3640 has v0 = ?.

- `pcibr_reset` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x3648 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x3648-0x3904 (700 bytes).
  It occupies 700 bytes.
  The `lbu` at 0x365c loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0x3670 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  The `lbu` at 0x3674 loads 1 byte from ret(pciio_info_mfast_get) +0x31.
  The `lw` at 0x3684 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x100.
  The `lbu` at 0x369c loads 1 byte from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x104.
  The `lbu` at 0x36ac loads 1 byte from ret(pciio_info_mfast_get) +0x33.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x36d8, `lw` at 0x384c.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x36f0, `ld` at 0x3718, `ld` at 0x37c4.
  The `sw` at 0x3738 stores 4 bytes to ?.
  3 such `ld` accesses load 8 bytes from table(0x0) +0x0, including `ld` at 0x38d8, `ld` at 0x38ec, `ld` at 0x3900.
  The `jal` at 0x3654 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3668 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x36c8 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)), a3=a0 at entry (arg0).
  The `jal` at 0x372c calls pcibr_func_config_get with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=0x4.
  The `jal` at 0x375c calls pcireg_control_bit_clr with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3764 calls nano_delay with a0=sp-128, a1=?, a2=?, a3=?.
  The `jal` at 0x3770 calls pcireg_control_bit_set with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3778 calls nano_delay with a0=sp-128, a1=?, a2=?, a3=?.
  The `jal` at 0x379c calls pcibr_func_config_set with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3850 calls pcibr_func_config_set with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=0x4.
  The `jal` at 0x3870 calls mutex_io_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3894 calls pcibr_debug with a0=0x8, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a0 at entry (arg0).
  The `beq` branch at 0x3694 targets 0x36a0, is taken when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+256]) == 0, and falls through when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+256]) != 0.
  The `bne` branch at 0x36a4 targets 0x3884, is taken when s3(?) < a0(=[ret(pciio_info_mfast_get)+49]:1) (signed), and falls through when s3(?) >= a0(=[ret(pciio_info_mfast_get)+49]:1) (signed).
  The `bne` branch at 0x36b4 targets 0x3884, is taken when a4(=[ret(pciio_info_mfast_get)+51]:1) < s3(?) (signed), and falls through when a4(=[ret(pciio_info_mfast_get)+51]:1) >= s3(?) (signed).
  The `blez` branch at 0x36ec targets 0x373c, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0x36f4 targets 0x38c8 and is always taken.
  The `beq` branch at 0x3710 targets 0x373c, is taken when s0(?) >= s6(?) (signed), and falls through when s0(?) < s6(?) (signed).
  The `beq` branch at 0x371c targets 0x36fc, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x3734 targets 0x36fc and is always taken.
  The `blez` branch at 0x3780 targets 0x3860, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0x3788 targets 0x38dc and is always taken.
  The `beq` branch at 0x37ac targets 0x37e0, is taken when s0(?) >= 0x6 (signed), and falls through when s0(?) < 0x6 (signed).
  The `bne` branch at 0x37c8 targets 0x3790, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0x37d8 targets 0x37b4, is taken when s0(?) < 0x6 (signed), and falls through when s0(?) >= 0x6 (signed).
  The `beq` branch at 0x37f0 targets 0x3814, is taken when s7(?) >= s6(?) (signed), and falls through when s7(?) < s6(?) (signed).
  The `beq` branch at 0x3804 targets 0x37e0, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x380c targets 0x37b8 and is always taken.
  The `beq` branch at 0x3814 targets 0x38f0 and is always taken.
  The `beq` branch at 0x382c targets 0x3860, is taken when s0(?) >= s6(?) (signed), and falls through when s0(?) < s6(?) (signed).
  The `beq` branch at 0x3838 targets 0x381c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x3858 targets 0x3820 and is always taken.
  The `beq` branch at 0x3878 targets 0x38a0 and is always taken.
  The `beq` branch at 0x38d4 targets 0x371c and is always taken.
  The `beq` branch at 0x38e8 targets 0x37fc and is always taken.
  The `beq` branch at 0x38fc targets 0x3838 and is always taken.
  The return at 0x38c0 has v0 = one of -0x1, 0x0.
  The instructions from 0x3880 to 0x3880 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_endian_set` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x3904 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x3904-0x39ec (232 bytes).
  It occupies 232 bytes.
  The `lbu` at 0x3928 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0x395c loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `sd` at 0x39e0 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `jal` at 0x3920 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3930 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3940 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0x3980 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x39a0 calls pcibr_debug with a0=0x4000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=[ret(pciio_hostinfo_get)+540]:1, a5=sym(device_bits).
  The `jal` at 0x39cc calls pcireg_device_set with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8, a4=0x180000, a7=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `jal` at 0x39dc calls pcireg_tflush_get with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `beq` branch at 0x3958 targets 0x3968, is taken when s0(=a1) == s2(=a2), and falls through when s0(=a1) != s2(=a2).
  The `beq` branch at 0x3960 targets 0x396c and is always taken.
  The `bne` branch at 0x3970 targets 0x39c4, is taken when a3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8) != s0(?), and falls through when a3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8) == s0(?).
  The `beq` branch at 0x39e4 targets 0x3978 and is always taken.
  The return at 0x39bc has v0 = a2.

- `pcibr_priority_bits_set` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x39ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x39ec-0x3b48 (348 bytes).
  It occupies 348 bytes.
  The `lw` at 0x3a10 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `ld` at 0x3a58 loads 8 bytes from (a0 + (a1 << 0x7)) +0x138.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x140, including `lw` at 0x3ab8, `lw` at 0x3af8.
  2 such `sw` accesses store 4 bytes to (a0 + (a1 << 0x7)) +0x140, including `sw` at 0x3ac8, `sw` at 0x3b10.
  The `sd` at 0x3ae4 stores 8 bytes to (a0 + (a1 << 0x7)) +0x138.
  The `jal` at 0x3a44 calls mutex_spinlock with a0=a0+128, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3a98 calls mutex_io_spinunlock with a0=a0+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x3adc calls pcireg_device_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x3ae8 calls pcireg_tflush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x3a2c targets 0x3a38, is taken when a2 == v0(=0x2), and falls through when a2 != v0(=0x2).
  The `beq` branch at 0x3a60 targets 0x3ab8, is taken when s2(=a2) == a0(=0x1), and falls through when s2(=a2) != a0(=0x1).
  The `beq` branch at 0x3a68 targets 0x3ab8, is taken when s2(=a2) == t8(=0x2), and falls through when s2(=a2) != t8(=0x2).
  The `beq` branch at 0x3a70 targets 0x3af8, is taken when s2(=a2) == 0, and falls through when s2(=a2) != 0.
  The `bne` branch at 0x3a78 targets 0x3ad4, is taken when a2(=[(a0 + (a1 << 0x7))+312]:8) != s3(?), and falls through when a2(=[(a0 + (a1 << 0x7))+312]:8) == s3(?).
  The `bne` branch at 0x3ac4 targets 0x3a78, is taken when t9(=[(a0 + (a1 << 0x7))+320]+1) != a0(=0x1), and falls through when t9(=[(a0 + (a1 << 0x7))+320]+1) == a0(=0x1).
  The `beq` branch at 0x3acc targets 0x3b1c and is always taken.
  The `beq` branch at 0x3af0 targets 0x3a80 and is always taken.
  The `blez` branch at 0x3b00 targets 0x3a78, is taken when a0(=[(a0 + (a1 << 0x7))+320]) <= 0 (signed), and falls through when a0(=[(a0 + (a1 << 0x7))+320]) > 0 (signed).
  The `bne` branch at 0x3b0c targets 0x3a78, is taken when a0(=[(a0 + (a1 << 0x7))+320]-1) != 0, and falls through when a0(=[(a0 + (a1 << 0x7))+320]-1) == 0.
  The `beq` branch at 0x3b14 targets 0x3b2c and is always taken.
  The `beq` branch at 0x3b1c targets 0x3b40, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x3b24 targets 0x3a78 and is always taken.
  The `beq` branch at 0x3b2c targets 0x3a78, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x3b38 targets 0x3a78 and is always taken.
  The `beq` branch at 0x3b40 targets 0x3a78 and is always taken.
  The return at 0x3ab0 has v0 = one of -0x1, 0x0.

- `pcibr_priority_set` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x3b48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x3b48-0x3b94 (76 bytes).
  It occupies 76 bytes.
  The `lbu` at 0x3b68 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `jal` at 0x3b58 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3b64 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3b74 calls pcibr_priority_bits_set with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=a1 at entry (arg1), a3=?.
  The return at 0x3b8c has v0 = a1.

- `pcibr_device_flags_set` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x3b94 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x3b94-0x3d94 (512 bytes).
  It occupies 512 bytes.
  The `lbu` at 0x3bb0 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lh` at 0x3c8c loads 2 bytes from ret(pciio_info_mfast_get) +0x72.
  The `ld` at 0x3cc4 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `sd` at 0x3d50 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x138.
  The `lw` at 0x3d74 loads 4 bytes from ret(pciio_info_mfast_get) +0x78.
  The `jal` at 0x3ba8 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3bc0 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3cb0 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=(a1 << 0x2c), a2=?, a3=(a1 << 0x2b), a7=(a1 << 0x25).
  The `jal` at 0x3ce8 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x3d08 calls pcibr_debug with a0=0x4000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=[ret(pciio_hostinfo_get)+540]:1, a5=sym(device_bits).
  The `jal` at 0x3d3c calls pcireg_device_set with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The `jal` at 0x3d4c calls pcireg_tflush_get with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `bgez` branch at 0x3bf4 targets 0x3d5c, is taken when v0(=(a1 << 0x2f)) >= 0 (signed), and falls through when v0(=(a1 << 0x2f)) < 0 (signed).
  The `bgez` branch at 0x3bfc targets 0x3c08, is taken when a3(=(a1 << 0x2e)) >= 0 (signed), and falls through when a3(=(a1 << 0x2e)) < 0 (signed).
  The `bgez` branch at 0x3c0c targets 0x3c18, is taken when v1(=(a1 << 0x2d)) >= 0 (signed), and falls through when v1(=(a1 << 0x2d)) < 0 (signed).
  The `bgez` branch at 0x3c1c targets 0x3c2c, is taken when a1(=(a1 << 0x2c)) >= 0 (signed), and falls through when a1(=(a1 << 0x2c)) < 0 (signed).
  The `bgez` branch at 0x3c2c targets 0x3c3c, is taken when a3(=(a1 << 0x2b)) >= 0 (signed), and falls through when a3(=(a1 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0x3c3c targets 0x3c4c, is taken when a4(=(a1 << 0x2a)) >= 0 (signed), and falls through when a4(=(a1 << 0x2a)) < 0 (signed).
  The `bgez` branch at 0x3c4c targets 0x3c58, is taken when a5(=(a1 << 0x29)) >= 0 (signed), and falls through when a5(=(a1 << 0x29)) < 0 (signed).
  The `beq` branch at 0x3c5c targets 0x3c6c, is taken when (s2(=a1) & a0(=0x800000)) == 0, and falls through when (s2(=a1) & a0(=0x800000)) != 0.
  The `bgez` branch at 0x3c70 targets 0x3c7c, is taken when a7(=(a1 << 0x25)) >= 0 (signed), and falls through when a7(=(a1 << 0x25)) < 0 (signed).
  The `bgez` branch at 0x3c80 targets 0x3c8c, is taken when t0(=(a1 << 0x24)) >= 0 (signed), and falls through when t0(=(a1 << 0x24)) < 0 (signed).
  The `beq` branch at 0x3c94 targets 0x3d6c, is taken when t1(=[ret(pciio_info_mfast_get)+114]:2) == t2(=0x2), and falls through when t1(=[ret(pciio_info_mfast_get)+114]:2) != t2(=0x2).
  The `bne` branch at 0x3c9c targets 0x3cb0, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x3ca4 targets 0x3d14, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x3cd4 targets 0x3d34, is taken when t3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8) != s2(?), and falls through when t3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+312]:8) == s2(?).
  The `beq` branch at 0x3d54 targets 0x3cdc and is always taken.
  The `bltz` branch at 0x3d5c targets 0x3c04, is taken when a3(=(a1 << 0x2e)) < 0 (signed), and falls through when a3(=(a1 << 0x2e)) >= 0 (signed).
  The `beq` branch at 0x3d64 targets 0x3c0c and is always taken.
  The `beq` branch at 0x3d6c targets 0x3c9c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x3d80 targets 0x3c9c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x3d8c targets 0x3c9c and is always taken.
  The return at 0x3d2c has v0 = 0x1.

- `pcibr_pcix_rbars_calc` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x3d94 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x3d94-0x3e24 (144 bytes).
  It occupies 144 bytes.
  The `lw` at 0x3d94 loads 4 bytes from a0 (arg0 at entry) +0x508.
  The `lw` at 0x3dc8 loads 4 bytes from a0 (arg0 at entry) +0x50c.
  The `ld` at 0x3e08 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `jal` at 0x3e10 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+16]:8, a3=0x10, a4=[a0+1288], a7=a0 at entry (arg0).
  The `beq` branch at 0x3da8 targets 0x3df8, is taken when a4(=[a0+1288]) == 0, and falls through when a4(=[a0+1288]) != 0.
  The `beq` branch at 0x3db4 targets 0x3e00, is taken when a4(=[a0+1288]) >= 0x11 (signed), and falls through when a4(=[a0+1288]) < 0x11 (signed).
  The `bne` branch at 0x3de0 targets 0x3df0, is taken when v0(?) < 0x65 (signed), and falls through when v0(?) >= 0x65 (signed).
  The `beq` branch at 0x3de8 targets 0x3df4 and is always taken.
  The `beq` branch at 0x3e1c targets 0x3df8 and is always taken.
  The return at 0x3df8 has v0 = one of 0x13, ?, 0x0.

- `pcibr_dma_enabled` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x3e24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x3e24-0x3e50 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x3e40 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0x3e2c calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3e34 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3e3c calls xtalk_dma_enabled with a0=[ret(pciio_info_mfast_get)], a1=?, a2=?, a3=?.
  The return at 0x3e48 has v0 = ret(xtalk_dma_enabled).

- `pcibr_debug` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x3e50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x3e50-0x4080 (560 bytes).
  It occupies 560 bytes.
  The `lh` at 0x403c loads 2 bytes from abs 0xffffffffffffc3a0.
  The `jal` at 0x3e84 calls bzero with a0=sp-624, a1=0x100, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3ebc calls hwgraph_vertex_name_get with a0=a1 at entry (arg1), a1=sp-624, a2=0x100, a3=?.
  The `jal` at 0x3ef0 calls strcmp with a0=?, a1=[sym(pcibr_debug_module)]:8, a2=?, a3=?.
  The `jal` at 0x3f10 calls kmem_zalloc with a0=0x400, a1=0x0, a2=?, a3=?.
  The `jal` at 0x3f54 calls strcmp with a0=sym(.rodata), a1=[sym(pcibr_debug_module)]:8, a2=?, a3=?.
  The `jal` at 0x3f64 calls strcpy with a0=sp-368, a1=sp-624, a2=?, a3=?.
  The `jal` at 0x3f74 calls strstr with a0=sp-368, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x3f98 calls strstr with a0=sp-624, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x3fb8 calls strstr with a0=sp-624, a1=sym(.rodata), a2=[sym(pcibr_debug_slot)], a3=?.
  The `jal` at 0x3fec calls atoi with a0=ret(strstr)+7, a1=?, a2=?, a3=?.
  The `jal` at 0x4000 calls atoi with a0=ret(strstr)+5, a1=?, a2=?, a3=?.
  The `jal` at 0x4024 calls strtok_r with a0=ret(strstr)+7, a1=sym(.rodata), a2=sp-112, a3=?.
  The `jal` at 0x4040 calls printf with a0=sym(.rodata), a1=[-0x3c60]:2, a2=sp-624, a3=?.
  The `jal` at 0x4050 calls vsprintf with a0=ret(kmem_zalloc), a1=a2 at entry (arg2), a2=sp-40, a3=?.
  The `jal` at 0x4064 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x4070 calls kmem_free with a0=ret(kmem_zalloc), a1=0x400, a2=?, a3=?.
  The `beq` branch at 0x3ea4 targets 0x3f20, is taken when (v1(=[sym(pcibr_debug_mask)]) & a0) == 0, and falls through when (v1(=[sym(pcibr_debug_mask)]) & a0) != 0.
  The `beq` branch at 0x3eac targets 0x3f3c, is taken when s1(=a1) == 0, and falls through when s1(=a1) != 0.
  The `beq` branch at 0x3ec4 targets 0x3f50, is taken when v0(=ret(hwgraph_vertex_name_get)) == 0, and falls through when v0(=ret(hwgraph_vertex_name_get)) != 0.
  The `beq` branch at 0x3ee4 targets 0x3f10, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x3ef8 targets 0x3f20, is taken when v0(=ret(strcmp)) != 0, and falls through when v0(=ret(strcmp)) == 0.
  The `bne` branch at 0x3f00 targets 0x3f20, is taken when t9(=[sym(pcibr_debug_widget)]) != s2(?), and falls through when t9(=[sym(pcibr_debug_widget)]) == s2(?).
  The `bne` branch at 0x3f08 targets 0x3f20, is taken when ra(=[sym(pcibr_debug_slot)]) != s3(?), and falls through when ra(=[sym(pcibr_debug_slot)]) == s3(?).
  The `bne` branch at 0x3f18 targets 0x4034, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x3f48 targets 0x3edc and is always taken.
  The `beq` branch at 0x3f5c targets 0x3fd0, is taken when v0(=ret(strcmp)) == 0, and falls through when v0(=ret(strcmp)) != 0.
  The `bne` branch at 0x3f7c targets 0x4014, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x3f8c targets 0x3fdc, is taken when t8(=[sym(pcibr_debug_widget)]) == s3(=-0x1), and falls through when t8(=[sym(pcibr_debug_widget)]) != s3(=-0x1).
  The `bne` branch at 0x3fa0 targets 0x3fec, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x3fac targets 0x3fe4, is taken when a2(=[sym(pcibr_debug_slot)]) == s3(=-0x1), and falls through when a2(=[sym(pcibr_debug_slot)]) != s3(=-0x1).
  The `bne` branch at 0x3fc0 targets 0x4000, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x3fc8 targets 0x3edc and is always taken.
  The `beq` branch at 0x3fd4 targets 0x3f88 and is always taken.
  The `beq` branch at 0x3fdc targets 0x3fa8 and is always taken.
  The `beq` branch at 0x3fe4 targets 0x3edc and is always taken.
  The `beq` branch at 0x3ff8 targets 0x3fa8 and is always taken.
  The `beq` branch at 0x400c targets 0x3edc and is always taken.
  The `beq` branch at 0x402c targets 0x3f88 and is always taken.
  The `beq` branch at 0x4078 targets 0x3f24 and is always taken.
  The return at 0x3f34 has v0 = one of ?, ret(kmem_free).

- `pcibr_businfo_get` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x4080 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x4080-0x40c0 (64 bytes).
  It occupies 64 bytes.
  The `sw` at 0x4098 stores 4 bytes to ret(pciio_info_mfast_get) +0xaa0.
  The `sw` at 0x40a4 stores 4 bytes to ret(pciio_info_mfast_get) +0xaa4.
  The `sw` at 0x40ac stores 4 bytes to ret(pciio_info_mfast_get) +0xaa8.
  The `sw` at 0x40b4 stores 4 bytes to ret(pciio_info_mfast_get) +0xaac.
  The `jal` at 0x4088 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4090 calls pciio_info_mfast_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The return at 0x40b8 has v0 = ret(pciio_info_mfast_get)+2720.

- `pcibr_pio_flush_read` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x416c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x416c-0x41d8 (108 bytes).
  It occupies 108 bytes.
  The `lbu` at 0x41a0 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `sb` at 0x41a4 stores 1 byte to a2 (arg2 at entry) +0x0.
  The `ld` at 0x41b4 loads 8 bytes from a1 (arg1 at entry) +0x0.
  The `sd` at 0x41bc stores 8 bytes to a2 (arg2 at entry) +0x0.
  The `lhu` at 0x41c0 loads 2 bytes from a1 (arg1 at entry) +0x0.
  The `sh` at 0x41c8 stores 2 bytes to a2 (arg2 at entry) +0x0.
  The `lw` at 0x41cc loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `sw` at 0x41d4 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `beq` branch at 0x4178 targets 0x41a0, is taken when a3 == at(=0x1), and falls through when a3 != at(=0x1).
  The `beq` branch at 0x4180 targets 0x41c0, is taken when a3 == v0(=0x2), and falls through when a3 != v0(=0x2).
  The `beq` branch at 0x4188 targets 0x41cc, is taken when a3 == a5(=0x4), and falls through when a3 != a5(=0x4).
  The `bne` branch at 0x4190 targets 0x41ac, is taken when a3 != a6(=0x8), and falls through when a3 == a6(=0x8).
  The `beq` branch at 0x4198 targets 0x41b4 and is always taken.
  The `beq` branch at 0x41b8 targets 0x41a8 and is always taken.
  The `beq` branch at 0x41c4 targets 0x41a8 and is always taken.
  The `beq` branch at 0x41d0 targets 0x41a8 and is always taken.
  The return at 0x41ac has v0 = one of 0x0, 0x1.

- `pcibr_pio_flush_del` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x41d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x41d8-0x41e0 (8 bytes).
  It occupies 8 bytes.
  The return at 0x41d8 has v0 = ?.

- `pcibr_pio_flush_init` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x41e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x41e0-0x41e8 (8 bytes).
  It occupies 8 bytes.
  The return at 0x41e0 has v0 = 0x0.

- `idbg_pss_func` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x41e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x41e8-0x4370 (392 bytes).
  It occupies 392 bytes.
  The `ld` at 0x41fc loads 8 bytes from (a0 + (a1 << 0x3)) +0x0.
  The `lw` at 0x4228 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x8.
  The `lbu` at 0x4238 loads 1 byte from [(a0 + (a1 << 0x3))]:8 +0x10.
  The `lbu` at 0x4244 loads 1 byte from [(a0 + (a1 << 0x3))]:8 +0x11.
  The `lbu` at 0x4250 loads 1 byte from [(a0 + (a1 << 0x3))]:8 +0x12.
  The `lw` at 0x425c loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x14.
  The `lw` at 0x4268 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x18.
  The `lw` at 0x4280 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x1c.
  The `ld` at 0x4290 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x30.
  The `ld` at 0x429c loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x40.
  The `ld` at 0x42a0 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x38.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x42c4, `lw` at 0x4334.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x42c8, `ld` at 0x42d4, `ld` at 0x42e4.
  The `ld` at 0x42f8 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x1a8.
  The `ld` at 0x42fc loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x1a0.
  The `jal` at 0x4214 calls qprintf with a0=sym(.rodata)+2280, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4224 calls vertex_to_name with a0=[[(a0 + (a1 << 0x3))]:8+8], a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0x4230 calls qprintf with a0=sym(.rodata)+2280, a1=sp-304, a2=?, a3=?.
  The `jal` at 0x423c calls qprintf with a0=sym(.rodata)+2280, a1=[[(a0 + (a1 << 0x3))]:8+16]:1, a2=?, a3=?.
  The `jal` at 0x4248 calls qprintf with a0=sym(.rodata)+2280, a1=[[(a0 + (a1 << 0x3))]:8+17]:1, a2=?, a3=?.
  The `jal` at 0x4254 calls qprintf with a0=sym(.rodata)+2280, a1=[[(a0 + (a1 << 0x3))]:8+18]:1, a2=?, a3=?.
  The `jal` at 0x4260 calls qprintf with a0=sym(.rodata)+2280, a1=[[(a0 + (a1 << 0x3))]:8+20], a2=?, a3=?.
  The `jal` at 0x426c calls qprintf with a0=sym(.rodata)+2280, a1=[[(a0 + (a1 << 0x3))]:8+24], a2=?, a3=?.
  The `jal` at 0x427c calls vertex_to_name with a0=[[(a0 + (a1 << 0x3))]:8+28], a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0x4288 calls qprintf with a0=sym(.rodata)+2280, a1=sp-304, a2=?, a3=?.
  The `jal` at 0x4294 calls qprintf with a0=sym(.rodata)+2280, a1=[[(a0 + (a1 << 0x3))]:8+48]:8, a2=?, a3=?.
  The `jal` at 0x42a4 calls qprintf with a0=sym(.rodata)+2280, a1=[[(a0 + (a1 << 0x3))]:8+56]:8, a2=[[(a0 + (a1 << 0x3))]:8+64]:8, a3=?.
  The `jal` at 0x42e0 calls qprintf with a0=sym(.rodata)+2280, a1=?, a2=?, a3=?.
  The `jal` at 0x4300 calls qprintf with a0=sym(.rodata)+2280, a1=[[(a0 + (a1 << 0x3))]:8+416]:8, a2=[[(a0 + (a1 << 0x3))]:8+424]:8, a3=?.
  The `jal` at 0x4308 calls qprintf with a0=sym(.rodata)+2280, a1=?, a2=?, a3=?.
  The `jal` at 0x4310 calls qprintf with a0=sym(.rodata)+2280, a1=?, a2=?, a3=?.
  The `jal` at 0x4330 calls qprintf with a0=sym(.rodata)+2280, a1=?, a2=?, a3=?.
  The `jal` at 0x434c calls qprintf with a0=sym(.rodata)+2280, a1=?, a2=?, a3=?.
  The `beq` branch at 0x4208 targets 0x4354, is taken when s0(=[(a0 + (a1 << 0x3))]:8) == 0, and falls through when s0(=[(a0 + (a1 << 0x3))]:8) != 0.
  The `bne` branch at 0x42f0 targets 0x42b8, is taken when s2(?) < 0x6 (signed), and falls through when s2(?) >= 0x6 (signed).
  The `bne` branch at 0x4340 targets 0x4320, is taken when s2(?) < 0x4 (signed), and falls through when s2(?) >= 0x4 (signed).
  The return at 0x4368 has v0 = one of ?, ret(qprintf).

- `idbg_pss_info` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x4370 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x4370-0x454c (476 bytes).
  It occupies 476 bytes.
  The `lw` at 0x43a8 loads 4 bytes from (a0 + (a1 << 0x7)) +0x100.
  The `lbu` at 0x43c8 loads 1 byte from (a0 + (a1 << 0x7)) +0x104.
  The `lw` at 0x43e0 loads 4 bytes from (a0 + (a1 << 0x7)) +0x108.
  3 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x110, including `lw` at 0x43f0, `lw` at 0x43fc, `lw` at 0x4414.
  The `ld` at 0x4408 loads 8 bytes from (a0 + (a1 << 0x7)) +0x118.
  The `lw` at 0x4428 loads 4 bytes from (a0 + (a1 << 0x7)) +0x120.
  The `ld` at 0x4440 loads 8 bytes from (sym(pci_space) + ([(a0 + (a1 << 0x7))+288] << 0x3)) +0x0.
  The `ld` at 0x4444 loads 8 bytes from (a0 + (a1 << 0x7)) +0x128.
  The `ld` at 0x4450 loads 8 bytes from (a0 + (a1 << 0x7)) +0x138.
  The `lw` at 0x445c loads 4 bytes from (a0 + (a1 << 0x7)) +0x14c.
  The `lw` at 0x4460 loads 4 bytes from (a0 + (a1 << 0x7)) +0x148.
  The `lw` at 0x4464 loads 4 bytes from (a0 + (a1 << 0x7)) +0x144.
  The `lw` at 0x4470 loads 4 bytes from (a0 + (a1 << 0x7)) +0x168.
  The `ld` at 0x4474 loads 8 bytes from (a0 + (a1 << 0x7)) +0x160.
  The `lw` at 0x4478 loads 4 bytes from (a0 + (a1 << 0x7)) +0x158.
  The `ld` at 0x447c loads 8 bytes from (a0 + (a1 << 0x7)) +0x150.
  The `lw` at 0x4488 loads 4 bytes from (a0 + (a1 << 0x7)) +0x16c.
  The `ld` at 0x44a0 loads 8 bytes from (a0 + (a1 << 0x7)) +0x170.
  The `lw` at 0x44ac loads 4 bytes from (a0 + (a1 << 0x7)) +0x178.
  The `lh` at 0x44b8 loads 2 bytes from a0 (arg0 at entry) +0x72.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x2)) +0x528, including `lw` at 0x44dc, `lw` at 0x4528.
  The `lw` at 0x44e0 loads 4 bytes from (a0 + (a1 << 0x4)) +0x574.
  The `lw` at 0x44e4 loads 4 bytes from (a0 + (a1 << 0x4)) +0x570.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x4)) +0x56c, including `lw` at 0x44e8, `lw` at 0x452c.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x4)) +0x568, including `lw` at 0x44f4, `lw` at 0x4538.
  The `jal` at 0x4394 calls qprintf with a0=sym(.rodata)+2280, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x43c0 calls qprintf with a0=sym(.rodata)+2280, a1=sym(.rodata)+2280, a2=sym(.rodata)+2280, a3=sym(.rodata)+2280.
  The `jal` at 0x43cc calls qprintf with a0=sym(.rodata)+2280, a1=[(a0 + (a1 << 0x7))+260]:1, a2=?, a3=?.
  The `jal` at 0x43dc calls vertex_to_name with a0=[(a0 + (a1 << 0x7))+264], a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0x43e8 calls qprintf with a0=sym(.rodata)+2280, a1=sp-304, a2=?, a3=?.
  The `jal` at 0x43f4 calls qprintf with a0=sym(.rodata)+2280, a1=[(a0 + (a1 << 0x7))+272], a2=?, a3=?.
  The `jal` at 0x440c calls idbg_pss_func with a0=[(a0 + (a1 << 0x7))+280]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x443c calls qprintf with a0=sym(.rodata)+2280, a1=[(sym(pci_space) + ([(a0 + (a1 << 0x7))+288] << 0x3))]:8, a2=([(a0 + (a1 << 0x7))+288] << 0x3), a3=?.
  The `jal` at 0x4448 calls qprintf with a0=sym(.rodata)+2280, a1=[(a0 + (a1 << 0x7))+296]:8, a2=?, a3=?.
  The `jal` at 0x4454 calls qprintf with a0=sym(.rodata)+2280, a1=[(a0 + (a1 << 0x7))+312]:8, a2=?, a3=?.
  The `jal` at 0x4468 calls qprintf with a0=sym(.rodata)+2280, a1=[(a0 + (a1 << 0x7))+324], a2=[(a0 + (a1 << 0x7))+328], a3=[(a0 + (a1 << 0x7))+332].
  The `jal` at 0x4480 calls qprintf with a0=sym(.rodata)+2280, a1=[(a0 + (a1 << 0x7))+336]:8, a2=[(a0 + (a1 << 0x7))+344], a3=[(a0 + (a1 << 0x7))+352]:8, a4=[(a0 + (a1 << 0x7))+360].
  The `jal` at 0x4498 calls qprintf with a0=sym(.rodata)+2280, a1=sym(.rodata)+2280, a2=sym(.rodata)+2280, a3=[(a0 + (a1 << 0x7))+364].
  The `jal` at 0x44a4 calls qprintf with a0=sym(.rodata)+2280, a1=[(a0 + (a1 << 0x7))+368]:8, a2=?, a3=?.
  The `jal` at 0x44b0 calls qprintf with a0=sym(.rodata)+2280, a1=[(a0 + (a1 << 0x7))+376], a2=?, a3=?.
  The `jal` at 0x44f0 calls qprintf with a0=sym(.rodata)+2280, a1=[(a0 + (a1 << 0x4))+1384], a2=[(a0 + (a1 << 0x4))+1388], a3=[(a0 + (a1 << 0x4))+1392], a4=[(a0 + (a1 << 0x4))+1396], a5=[(a0 + (a1 << 0x2))+1320].
  The `jal` at 0x4534 calls qprintf with a0=sym(.rodata)+2280, a1=[(a0 + (a1 << 0x4))+1384], a2=[(a0 + (a1 << 0x4))+1388], a3=[(a0 + (a1 << 0x2))+1320].
  The `beq` branch at 0x43b4 targets 0x43c0, is taken when at(=[(a0 + (a1 << 0x7))+256]) == 0, and falls through when at(=[(a0 + (a1 << 0x7))+256]) != 0.
  The `blez` branch at 0x4400 targets 0x4428, is taken when t8(=[(a0 + (a1 << 0x7))+272]) <= 0 (signed), and falls through when t8(=[(a0 + (a1 << 0x7))+272]) > 0 (signed).
  The `bne` branch at 0x4420 targets 0x4408, is taken when s1(?) < t9(=[(a0 + (a1 << 0x7))+272]) (signed), and falls through when s1(?) >= t9(=[(a0 + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0x448c targets 0x4544, is taken when a3(=[(a0 + (a1 << 0x7))+364]) == 0, and falls through when a3(=[(a0 + (a1 << 0x7))+364]) != 0.
  The `beq` branch at 0x44bc targets 0x451c, is taken when a1(=[a0+114]:2) == 0, and falls through when a1(=[a0+114]:2) != 0.
  The `beq` branch at 0x44c8 targets 0x4518, is taken when a1(=[a0+114]:2) == a2(=0x1), and falls through when a1(=[a0+114]:2) != a2(=0x1).
  The `beq` branch at 0x453c targets 0x44fc and is always taken.
  The `beq` branch at 0x4544 targets 0x4498 and is always taken.
  The return at 0x4510 has v0 = ret(qprintf).

- `idbg_pss` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x454c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x454c-0x4600 (180 bytes).
  It occupies 180 bytes.
  The `lbu` at 0x454c loads 1 byte from a0 (arg0 at entry) +0x38.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x39, including `lbu` at 0x4574, `lbu` at 0x458c, `lbu` at 0x45ac.
  The `jal` at 0x45a4 calls idbg_pss_info with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x45e0 calls qprintf with a0=sym(.rodata)+2280, a1=[sym(ips)], a2=a2 at entry (arg2), a3=[sym(ips)].
  The `jal` at 0x45f0 calls idbg_pss_info with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=[sym(ips)].
  The `bne` branch at 0x456c targets 0x4584, is taken when a3(=[sym(ips)]) < a1(=[a0+56]:1) (signed), and falls through when a3(=[sym(ips)]) >= a1(=[a0+56]:1) (signed).
  The `beq` branch at 0x457c targets 0x45f0, is taken when v0(=[a0+57]:1) >= a3(=[sym(ips)]) (signed), and falls through when v0(=[a0+57]:1) < a3(=[sym(ips)]) (signed).
  The `bgez` branch at 0x4584 targets 0x45dc, is taken when a3(=[sym(ips)]) >= 0 (signed), and falls through when a3(=[sym(ips)]) < 0 (signed).
  The `beq` branch at 0x4598 targets 0x45cc, is taken when a1(=[a0+56]:1) >= v1(=[a0+57]:1+1) (signed), and falls through when a1(=[a0+56]:1) < v1(=[a0+57]:1+1) (signed).
  The `bne` branch at 0x45c0 targets 0x45a4, is taken when s0(?) < a0(=[a0+57]:1+1) (signed), and falls through when s0(?) >= a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x45e8 targets 0x45cc and is always taken.
  The `beq` branch at 0x45f8 targets 0x45cc and is always taken.
  The return at 0x45d4 has v0 = one of ?, ret(idbg_pss_info), ret(qprintf).

- `pcibr_init_ext_ate_ram` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x4600 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x4600-0x4760 (352 bytes).
  It occupies 352 bytes.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x4640, `lw` at 0x4668, `lw` at 0x468c.
  The `ld` at 0x46d8 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0x46e0 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x464c calls pcireg_ext_ate_set with a0=a0 at entry (arg0), a1=?, a2=0x123456789abcdef, a3=?.
  The `jal` at 0x4674 calls pcireg_ext_ate_set with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?.
  The `jal` at 0x4694 calls pcireg_ext_ate_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x46b8 calls pcireg_ssram_size_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x46ec calls pcibr_debug with a0=0x10, a1=[a0+4], a2=sym(.rodata)+3184, a3=[a0+8]:8.
  The `jal` at 0x470c calls pcireg_ext_ate_set with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?.
  The `jal` at 0x4750 calls pcibr_debug with a0=0x10, a1=[a0+4], a2=sym(.rodata)+3184, a3=[a0+8]:8.
  The `bne` branch at 0x4658 targets 0x468c, is taken when s0(?) < 0x2 (signed), and falls through when s0(?) >= 0x2 (signed).
  The `bne` branch at 0x4684 targets 0x4664, is taken when s4(?) < s0(?) (signed), and falls through when s4(?) >= s0(?) (signed).
  The `bne` branch at 0x46b0 targets 0x4638, is taken when s0(?) < 0x4 (unsigned), and falls through when s0(?) >= 0x4 (unsigned).
  The `beq` branch at 0x46d0 targets 0x46f4, is taken when (t8(=[sym(pcibr_debug_mask)]) & 0x10) == 0, and falls through when (t8(=[sym(pcibr_debug_mask)]) & 0x10) != 0.
  The `beq` branch at 0x46dc targets 0x4748, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `blez` branch at 0x46fc targets 0x4724, is taken when s2(?) <= 0 (signed), and falls through when s2(?) > 0 (signed).
  The `bne` branch at 0x471c targets 0x4708, is taken when s0(?) < s2(?) (signed), and falls through when s0(?) >= s2(?) (signed).
  The `beq` branch at 0x4758 targets 0x46f8 and is always taken.
  The return at 0x4740 has v0 = ?.

- `pcibr_ate_alloc` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x4760 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x4760-0x47ac (76 bytes).
  It occupies 76 bytes.
  The `ld` at 0x4774 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `ld` at 0x4784 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `jal` at 0x4770 calls rmalloc with a0=[a0+96]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4790 calls rmalloc with a0=[a0+104]:8, a1=a1 at entry (arg1), a2=?, a3=?, a4=(ret(rmalloc) << 0x0).
  The `bne` branch at 0x477c targets 0x479c, is taken when a4(=(ret(rmalloc) << 0x0)) != 0, and falls through when a4(=(ret(rmalloc) << 0x0)) == 0.
  The `beq` branch at 0x4788 targets 0x47a0, is taken when a0(=[a0+104]:8) == 0, and falls through when a0(=[a0+104]:8) != 0.
  The return at 0x47a4 has v0 = (ret(rmalloc) << 0x0)-1.

- `pcibr_ate_free` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x47ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x47ac-0x47f0 (68 bytes).
  It occupies 68 bytes.
  The `lh` at 0x47ac loads 2 bytes from a0 (arg0 at entry) +0x70.
  The `ld` at 0x47cc loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `ld` at 0x47d0 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `jal` at 0x47dc calls rmfree with a0=?, a1=a2 at entry (arg2), a2=a1+1, a3=a3 at entry (arg3), a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `beq` branch at 0x47c0 targets 0x47d0, is taken when a1 >= at(=[a0+112]:2) (signed), and falls through when a1 < at(=[a0+112]:2) (signed).
  The `beq` branch at 0x47c8 targets 0x47d4 and is always taken.
  The return at 0x47e8 has v0 = ret(rmfree).

- `pcibr_flags_to_ate` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x47f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x47f0-0x48a4 (180 bytes).
  It occupies 180 bytes.
  The `beq` branch at 0x4804 targets 0x4818, is taken when (a0 & 0x10) == 0, and falls through when (a0 & 0x10) != 0.
  The `beq` branch at 0x4820 targets 0x482c, is taken when (a0 & 0x400) == 0, and falls through when (a0 & 0x400) != 0.
  The `beq` branch at 0x482c targets 0x483c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bgez` branch at 0x4840 targets 0x484c, is taken when a2(=(a0 << 0x29)) >= 0 (signed), and falls through when a2(=(a0 << 0x29)) < 0 (signed).
  The `bgez` branch at 0x484c targets 0x4858, is taken when a3(=(a0 << 0x28)) >= 0 (signed), and falls through when a3(=(a0 << 0x28)) < 0 (signed).
  The `bgez` branch at 0x4868 targets 0x4874, is taken when a5(=(a0 << 0x2d)) >= 0 (signed), and falls through when a5(=(a0 << 0x2d)) < 0 (signed).
  The `bgez` branch at 0x4874 targets 0x4880, is taken when a4(=(a0 << 0x2c)) >= 0 (signed), and falls through when a4(=(a0 << 0x2c)) < 0 (signed).
  The `bgez` branch at 0x4884 targets 0x4890, is taken when a6(=(a0 << 0x2b)) >= 0 (signed), and falls through when a6(=(a0 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0x4890 targets 0x489c, is taken when a3(=(a0 << 0x2a)) >= 0 (signed), and falls through when a3(=(a0 << 0x2a)) < 0 (signed).
  The return at 0x489c has v0 = ?.

- `pcibr_ate_addr` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x48a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x48a4-0x48e4 (64 bytes).
  It occupies 64 bytes.
  The `lh` at 0x48a4 loads 2 bytes from a0 (arg0 at entry) +0x70.
  The `jal` at 0x48b8 calls pcireg_int_ate_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x48c8 calls pcireg_ext_ate_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x48b0 targets 0x48c8, is taken when a1 >= at(=[a0+112]:2) (signed), and falls through when a1 < at(=[a0+112]:2) (signed).
  The `beq` branch at 0x48c0 targets 0x48d4 and is always taken.
  The return at 0x48dc has v0 = one of ret(pcireg_int_ate_addr), ret(pcireg_ext_ate_addr).

- `ate_write` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x48e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x48e4-0x4bf4 (784 bytes).
  It occupies 784 bytes.
  The `lbu` at 0x48e8 loads 1 byte from a1 (arg1 at entry) +0x8.
  The `lbu` at 0x48f4 loads 1 byte from a0 (arg0 at entry) +0x38.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0x4918, `lh` at 0x4994.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x0, including `lw` at 0x4924, `lw` at 0x4a20, `lw` at 0x4aa8.
  The `lh` at 0x4970 loads 2 bytes from a0 (arg0 at entry) +0x70.
  5 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x39, including `lbu` at 0x49ac, `lbu` at 0x49d4, `lbu` at 0x4afc.
  The `ld` at 0x49c8 loads 8 bytes from a0 (arg0 at entry) +0x8.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x49fc, `lw` at 0x4b1c, `lw` at 0x4b5c.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0x4a34, `sw` at 0x4adc.
  2 such `ll` accesses load 4 bytes from ?, including `ll` at 0x4a40, `ll` at 0x4ae4.
  2 such `sc` accesses store 4 bytes to ?, including `sc` at 0x4a4c, `sc` at 0x4af0.
  The `ld` at 0x4b2c loads 8 bytes from ?.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x4b30, `sw` at 0x4b3c, `sw` at 0x4b6c.
  The `jal` at 0x4958 calls pcireg_int_ate_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4984 calls pcireg_ext_ate_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x49cc calls pcibr_slot_config_set with a0=[a0+8]:8, a1=?, a2=0x4, a3=?.
  The `jal` at 0x4a5c calls mutex_io_spinunlock with a0=a0+128, a1=?, a2=?, a3=?.
  The `jal` at 0x4a64 calls pcireg_tflush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4aa0 calls mutex_spinlock with a0=a0+128, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=[a1].
  The `jal` at 0x4b90 calls pcireg_wrb_flush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x4938 targets 0x4a94, is taken when at(=[a0+114]:2) == 0, and falls through when at(=[a0+114]:2) != 0.
  The `blez` branch at 0x4940 targets 0x4994, is taken when s3(=a3) <= 0 (signed), and falls through when s3(=a3) > 0 (signed).
  The `beq` branch at 0x4948 targets 0x4970 and is always taken.
  The `bltz` branch at 0x4968 targets 0x4994, is taken when s3(?) < 0 (signed), and falls through when s3(?) >= 0 (signed).
  The `bne` branch at 0x4978 targets 0x4950, is taken when s1(?) < a0(=[a0+112]:2) (signed), and falls through when s1(?) >= a0(=[a0+112]:2) (signed).
  The `beq` branch at 0x498c targets 0x4960 and is always taken.
  The `bne` branch at 0x499c targets 0x4a64, is taken when a1(=[a0+114]:2) != 0, and falls through when a1(=[a0+114]:2) == 0.
  The `beq` branch at 0x49a4 targets 0x4a64, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x49b8 targets 0x49f4, is taken when s6(=[a0+56]:1) < a0(=[a0+57]:1+1) (signed), and falls through when s6(=[a0+56]:1) >= a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x49c0 targets 0x4a1c and is always taken.
  The `beq` branch at 0x49e8 targets 0x4a20, is taken when s1(?) >= a0(=[a0+57]:1+1) (signed), and falls through when s1(?) < a0(=[a0+57]:1+1) (signed).
  The `bne` branch at 0x4a04 targets 0x49c8, is taken when (a3(?) & 0x4) != 0, and falls through when (a3(?) & 0x4) == 0.
  The `bne` branch at 0x4a18 targets 0x49f0, is taken when s1(?) < a0(=[a0+57]:1+1) (signed), and falls through when s1(?) >= a0(=[a0+57]:1+1) (signed).
  The `beql` branch at 0x4a50 targets 0x4a40, is taken when at(=table(0x1)) == 0, and falls through when at(=table(0x1)) != 0; its branch-likely delay slot `nop` at 0x4a54 runs only when taken and is annulled on fall-through.
  The `bgez` branch at 0x4a98 targets 0x4940, is taken when ra(=([a1] << 0x21)) >= 0 (signed), and falls through when ra(=([a1] << 0x21)) < 0 (signed).
  The `beq` branch at 0x4ac4 targets 0x4afc, is taken when (a2(=[a1]) & at(=0xffffffff80000000)) == 0, and falls through when (a2(=[a1]) & at(=0xffffffff80000000)) != 0.
  The `beql` branch at 0x4af4 targets 0x4ae4, is taken when a4(=table(-0x1)) == 0, and falls through when a4(=table(-0x1)) != 0; its branch-likely delay slot `nop` at 0x4af8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x4b0c targets 0x4940, is taken when s6(=[a0+56]:1) >= a0(=[a0+57]:1+1) (signed), and falls through when s6(=[a0+56]:1) < a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x4b14 targets 0x4be4 and is always taken.
  The `beq` branch at 0x4b24 targets 0x4b3c, is taken when (a6(?) & 0x4) == 0, and falls through when (a6(?) & 0x4) != 0.
  The `beq` branch at 0x4b4c targets 0x4b70, is taken when a2(?) >= a0(=[a0+57]:1+1) (signed), and falls through when a2(?) < a0(=[a0+57]:1+1) (signed).
  The `bne` branch at 0x4b60 targets 0x4b1c, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x4b68 targets 0x4b40 and is always taken.
  The `beq` branch at 0x4b70 targets 0x4940, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x4b7c targets 0x4bb0, is taken when s6(=[a0+56]:1) < a0(=[a0+57]:1+1) (signed), and falls through when s6(=[a0+56]:1) >= a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x4b84 targets 0x4940 and is always taken.
  The `beq` branch at 0x4bac targets 0x4940, is taken when s4(?) >= a0(=[a0+57]:1+1) (signed), and falls through when s4(?) < a0(=[a0+57]:1+1) (signed).
  The `bne` branch at 0x4bc0 targets 0x4b8c, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `bne` branch at 0x4bd4 targets 0x4bb4, is taken when s4(?) < a0(=[a0+57]:1+1) (signed), and falls through when s4(?) >= a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x4bdc targets 0x4940 and is always taken.
  The `beq` branch at 0x4bec targets 0x4b58 and is always taken.
  The return at 0x4a8c has v0 = ret(pcireg_tflush_get).

- `do_pcibr_rrb_count_valid` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x4bf4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x4bf4-0x4dc4 (464 bytes).
  It occupies 464 bytes.
  8 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x4bf8, `lw` at 0x4c34, `lw` at 0x4c78.
  The `jal` at 0x4ca0 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=0xd002, a6=0xc002.
  The `jal` at 0x4db4 calls cmn_err with a0=0x4, a1=sym(.rodata)+3280, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0xc002.
  The `beq` branch at 0x4c2c targets 0x4d04, is taken when a6(=0xc002) == at(?), and falls through when a6(=0xc002) != at(?).
  The `beq` branch at 0x4c44 targets 0x4d24, is taken when v1(?) == a1(=0xd002), and falls through when v1(?) != a1(=0xd002).
  The `beq` branch at 0x4c4c targets 0x4c70, is taken when s0(=a1) == v0(=0xff), and falls through when s0(=a1) != v0(=0xff).
  The `beq` branch at 0x4c54 targets 0x4c70, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bltz` branch at 0x4c5c targets 0x4c70, is taken when s1(=a2) < 0 (signed), and falls through when s1(=a2) >= 0 (signed).
  The `bne` branch at 0x4c64 targets 0x4c70, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0x4c70 targets 0x4db4, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x4c84 targets 0x4d68, is taken when a6(=0xc002) == a1(?), and falls through when a6(=0xc002) != a1(?).
  The `beq` branch at 0x4c98 targets 0x4d88, is taken when a2(?) == a3(=0xd002), and falls through when a2(?) != a3(=0xd002).
  The `bne` branch at 0x4cd4 targets 0x4ce0, is taken when a7(?) != t1(?), and falls through when a7(?) == t1(?).
  The `bne` branch at 0x4ce0 targets 0x4ccc, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x4d14 targets 0x4c34, is taken when t2(?) != t3(=0x36), and falls through when t2(?) == t3(=0x36).
  The `beq` branch at 0x4d1c targets 0x4d3c and is always taken.
  The `bne` branch at 0x4d34 targets 0x4c4c, is taken when t3(?) != t8(=0x24), and falls through when t3(?) == t8(=0x24).
  The `beq` branch at 0x4d3c targets 0x4da8, is taken when s0(=a1) == t8(=0xff), and falls through when s0(=a1) != t8(=0xff).
  The `beq` branch at 0x4d44 targets 0x4dac, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bltz` branch at 0x4d4c targets 0x4dac, is taken when s1(=a2) < 0 (signed), and falls through when s1(=a2) >= 0 (signed).
  The `beq` branch at 0x4d58 targets 0x4dac, is taken when s1(=a2) >= 0x2 (signed), and falls through when s1(=a2) < 0x2 (signed).
  The `beq` branch at 0x4d60 targets 0x4dac and is always taken.
  The `bne` branch at 0x4d78 targets 0x4c8c, is taken when ra(?) != at(=0x36), and falls through when ra(?) == at(=0x36).
  The `beq` branch at 0x4d80 targets 0x4da0 and is always taken.
  The `bne` branch at 0x4d98 targets 0x4ca0, is taken when at(?) != v0(=0x24), and falls through when at(?) == v0(=0x24).
  The `beq` branch at 0x4da0 targets 0x4ca0 and is always taken.
  The `bne` branch at 0x4dac targets 0x4c78, is taken when v0(=one of 0x0, 0x1) != 0, and falls through when v0(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x4dbc targets 0x4ce8 and is always taken.
  The return at 0x4cfc has v0 = one of ?, 0x0.

- `do_pcibr_rrb_count_avail` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x4dc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x4dc4-0x4ed8 (276 bytes).
  It occupies 276 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x4dc4, `lw` at 0x4df0, `lw` at 0x4e68.
  The `jal` at 0x4e20 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?, a4=0xff.
  The `jal` at 0x4ec8 calls cmn_err with a0=0x4, a1=sym(.rodata)+3280, a2=a2 at entry (arg2), a3=?, a4=0xff.
  The `beq` branch at 0x4de8 targets 0x4e68, is taken when at(?) == v1(=0xc002), and falls through when at(?) != v1(=0xc002).
  The `beq` branch at 0x4dfc targets 0x4e88, is taken when v1(?) == a1(=0xd002), and falls through when v1(?) != a1(=0xd002).
  The `beq` branch at 0x4e04 targets 0x4e18, is taken when v0(=a1) == a4(=0xff), and falls through when v0(=a1) != a4(=0xff).
  The `beq` branch at 0x4e0c targets 0x4e18, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x4e18 targets 0x4ec4, is taken when a1(=one of 0x0, 0x1) == 0, and falls through when a1(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x4e44 targets 0x4e50, is taken when a5(=0x8) == a2(?), and falls through when a5(=0x8) != a2(?).
  The `bne` branch at 0x4e50 targets 0x4e3c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x4e78 targets 0x4df0, is taken when a3(?) != a6(=0x36), and falls through when a3(?) == a6(=0x36).
  The `beq` branch at 0x4e80 targets 0x4ea0 and is always taken.
  The `bne` branch at 0x4e98 targets 0x4e04, is taken when a6(?) != a7(=0x24), and falls through when a6(?) == a7(=0x24).
  The `beq` branch at 0x4ea0 targets 0x4eb8, is taken when v0(=a1) == a7(=0xff), and falls through when v0(=a1) != a7(=0xff).
  The `beq` branch at 0x4ea8 targets 0x4ebc, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x4eb0 targets 0x4ebc and is always taken.
  The `bne` branch at 0x4ebc targets 0x4e20, is taken when a1(=one of 0x0, 0x1) != 0, and falls through when a1(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x4ed0 targets 0x4e58 and is always taken.
  The return at 0x4e60 has v0 = one of ?, 0x0.

- `do_pcibr_rrb_alloc` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x4ed8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x4ed8-0x510c (564 bytes).
  It occupies 564 bytes.
  8 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x4ee8, `lw` at 0x4f28, `lw` at 0x4f6c.
  The `jal` at 0x4f9c calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=0xd002, a3=?.
  The `jal` at 0x5018 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x50fc calls cmn_err with a0=0x4, a1=sym(.rodata)+3280, a2=a2 at entry (arg2), a3=?, a7=0xc002.
  The `beq` branch at 0x4f20 targets 0x5048, is taken when a7(=0xc002) == at(?), and falls through when a7(=0xc002) != at(?).
  The `beq` branch at 0x4f38 targets 0x5068, is taken when v1(?) == a0(=0xd002), and falls through when v1(?) != a0(=0xd002).
  The `beq` branch at 0x4f40 targets 0x4f64, is taken when s2(=a1) == v0(=0xff), and falls through when s2(=a1) != v0(=0xff).
  The `beq` branch at 0x4f48 targets 0x4f64, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bltz` branch at 0x4f50 targets 0x4f64, is taken when s3(=a2) < 0 (signed), and falls through when s3(=a2) >= 0 (signed).
  The `beq` branch at 0x4f58 targets 0x4f64, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x4f64 targets 0x50f8, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x4f78 targets 0x50ac, is taken when a7(=0xc002) == a0(?), and falls through when a7(=0xc002) != a0(?).
  The `beq` branch at 0x4f8c targets 0x50cc, is taken when a1(?) == a2(=0xd002), and falls through when a1(?) != a2(=0xd002).
  The `blez` branch at 0x4fa8 targets 0x5014, is taken when s0(=a3) <= 0 (signed), and falls through when s0(=a3) > 0 (signed).
  The `beq` branch at 0x4fec targets 0x5000, is taken when t2(=0x8) == t8(?), and falls through when t2(=0x8) != t8(?).
  The `beq` branch at 0x5004 targets 0x5014, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bgtz` branch at 0x500c targets 0x4fd8, is taken when s0(?) > 0 (signed), and falls through when s0(?) <= 0 (signed).
  The `bne` branch at 0x5058 targets 0x4f28, is taken when a3(?) != a4(=0x36), and falls through when a3(?) == a4(=0x36).
  The `beq` branch at 0x5060 targets 0x5080 and is always taken.
  The `bne` branch at 0x5078 targets 0x4f40, is taken when a4(?) != a5(=0x24), and falls through when a4(?) == a5(=0x24).
  The `beq` branch at 0x5080 targets 0x50ec, is taken when s2(=a1) == a5(=0xff), and falls through when s2(=a1) != a5(=0xff).
  The `beq` branch at 0x5088 targets 0x50f0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bltz` branch at 0x5090 targets 0x50f0, is taken when s3(=a2) < 0 (signed), and falls through when s3(=a2) >= 0 (signed).
  The `beq` branch at 0x509c targets 0x50f0, is taken when s3(=a2) >= 0x2 (signed), and falls through when s3(=a2) < 0x2 (signed).
  The `beq` branch at 0x50a4 targets 0x50f0 and is always taken.
  The `bne` branch at 0x50bc targets 0x4f80, is taken when a7(?) != t0(=0x36), and falls through when a7(?) == t0(=0x36).
  The `beq` branch at 0x50c4 targets 0x50e4 and is always taken.
  The `bne` branch at 0x50dc targets 0x4f94, is taken when t0(?) != t1(=0x24), and falls through when t0(?) == t1(=0x24).
  The `beq` branch at 0x50e4 targets 0x4f94 and is always taken.
  The `bne` branch at 0x50f0 targets 0x4f6c, is taken when v0(=one of 0x0, 0x1) != 0, and falls through when v0(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x5104 targets 0x5028 and is always taken.
  The return at 0x5040 has v0 = one of -0x1, 0x0.

- `do_pcibr_rrb_free` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x510c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x510c-0x53b4 (680 bytes).
  It occupies 680 bytes.
  8 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x5120, `lw` at 0x5160, `lw` at 0x51b0.
  The `jal` at 0x51e4 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=a3 at entry (arg3), a7=0xc002.
  The `jal` at 0x525c calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5270 calls do_pcibr_rrb_clear with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x53a4 calls cmn_err with a0=0x4, a1=sym(.rodata)+3280, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=0xc002.
  The `beq` branch at 0x5158 targets 0x52e0, is taken when a7(=0xc002) == at(?), and falls through when a7(=0xc002) != at(?).
  The `beq` branch at 0x5170 targets 0x5300, is taken when v1(?) == a0(=0xd002), and falls through when v1(?) != a0(=0xd002).
  The `beq` branch at 0x5178 targets 0x51a8, is taken when s0(=a1) == v0(=0xff), and falls through when s0(=a1) != v0(=0xff).
  The `beq` branch at 0x5180 targets 0x51a8, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bltz` branch at 0x5188 targets 0x51a8, is taken when s2(=a2) < 0 (signed), and falls through when s2(=a2) >= 0 (signed).
  The `beq` branch at 0x5190 targets 0x51a8, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x519c targets 0x51a8 and is always taken.
  The `beq` branch at 0x51a8 targets 0x53a0, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x51bc targets 0x5348, is taken when a7(=0xc002) == a0(?), and falls through when a7(=0xc002) != a0(?).
  The `beq` branch at 0x51d4 targets 0x5368, is taken when a1(?) == a2(=0xd002), and falls through when a1(?) != a2(=0xd002).
  The `blez` branch at 0x51f4 targets 0x5388, is taken when s5(=a3) <= 0 (signed), and falls through when s5(=a3) > 0 (signed).
  The `beq` branch at 0x5218 targets 0x5224 and is always taken.
  The `blez` branch at 0x5220 targets 0x5258, is taken when s5(?) <= 0 (signed), and falls through when s5(?) > 0 (signed).
  The `bne` branch at 0x5238 targets 0x524c, is taken when t1(?) != t2(?), and falls through when t1(?) == t2(?).
  The `bne` branch at 0x5250 targets 0x5220, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x5268 targets 0x528c and is always taken.
  The `beq` branch at 0x5284 targets 0x52b0, is taken when s2(?) >= 0x8 (signed), and falls through when s2(?) < 0x8 (signed).
  The `bne` branch at 0x5294 targets 0x5270, is taken when (s4(?) & t8(?)) != 0, and falls through when (s4(?) & t8(?)) == 0.
  The `bne` branch at 0x52a8 targets 0x528c, is taken when s2(?) < 0x8 (signed), and falls through when s2(?) >= 0x8 (signed).
  The `bne` branch at 0x52f0 targets 0x5160, is taken when ra(?) != at(=0x36), and falls through when ra(?) == at(=0x36).
  The `beq` branch at 0x52f8 targets 0x531c and is always taken.
  The `bne` branch at 0x5310 targets 0x5178, is taken when at(?) != v1(=0x24), and falls through when at(?) == v1(=0x24).
  The `beq` branch at 0x531c targets 0x5394, is taken when s0(=a1) == v0(=0xff), and falls through when s0(=a1) != v0(=0xff).
  The `beq` branch at 0x5324 targets 0x5398, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bltz` branch at 0x532c targets 0x5398, is taken when s2(=a2) < 0 (signed), and falls through when s2(=a2) >= 0 (signed).
  The `beq` branch at 0x5338 targets 0x5398, is taken when s2(=a2) >= 0x2 (signed), and falls through when s2(=a2) < 0x2 (signed).
  The `beq` branch at 0x5340 targets 0x5398 and is always taken.
  The `bne` branch at 0x5358 targets 0x51c4, is taken when a0(?) != a1(=0x36), and falls through when a0(?) == a1(=0x36).
  The `beq` branch at 0x5360 targets 0x5380 and is always taken.
  The `bne` branch at 0x5378 targets 0x51dc, is taken when a1(?) != a2(=0x24), and falls through when a1(?) == a2(=0x24).
  The `beq` branch at 0x5380 targets 0x51dc and is always taken.
  The `beq` branch at 0x538c targets 0x5258 and is always taken.
  The `bne` branch at 0x5398 targets 0x51b0, is taken when v0(=one of 0x0, 0x1) != 0, and falls through when v0(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x53ac targets 0x52b8 and is always taken.
  The return at 0x52d8 has v0 = one of -0x1, 0x0.
  The instructions from 0x51a4 to 0x51a4 are not reached by any path from the entry, and their branches are not listed.

- `do_pcibr_rrb_free_all` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x53b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x53b4-0x54a8 (244 bytes).
  It occupies 244 bytes.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x53c0, `lw` at 0x53fc, `lw` at 0x5468.
  The `sw` at 0x5440 stores 4 bytes to ?.
  The `jal` at 0x5420 calls do_pcibr_rrb_free with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=?, a3=0x8.
  The `beq` branch at 0x53f0 targets 0x5468, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0x5408 targets 0x5488, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `bne` branch at 0x543c targets 0x5414, is taken when s0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when s0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x5478 targets 0x53fc, is taken when a0(?) != a1(=0x36), and falls through when a0(?) == a1(=0x36).
  The `beq` branch at 0x5480 targets 0x54a0 and is always taken.
  The `bne` branch at 0x5498 targets 0x5410, is taken when a1(?) != a2(=0x24), and falls through when a1(?) == a2(=0x24).
  The `beq` branch at 0x54a0 targets 0x5410 and is always taken.
  The return at 0x5460 has v0 = ret(do_pcibr_rrb_free).

- `do_pcibr_rrb_clear` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x54a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x54a8-0x5554 (172 bytes).
  It occupies 172 bytes.
  The `jal` at 0x54c0 calls pcireg_rrb_status_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x54e0 calls pcireg_rrb_status_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5508 calls pcireg_rrb_clear_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5510 calls pcireg_rrb_status_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5524 calls pcireg_rrb_status_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x54d8 targets 0x54f4, is taken when (s1(?) & v0(=ret(pcireg_rrb_status_get))) == 0, and falls through when (s1(?) & v0(=ret(pcireg_rrb_status_get))) != 0.
  The `bne` branch at 0x54ec targets 0x54e0, is taken when (s1(?) & v0(=ret(pcireg_rrb_status_get))) != 0, and falls through when (s1(?) & v0(=ret(pcireg_rrb_status_get))) == 0.
  The `beq` branch at 0x5500 targets 0x5538, is taken when (s2(?) & a0(=ret(pcireg_rrb_status_get))) == 0, and falls through when (s2(?) & a0(=ret(pcireg_rrb_status_get))) != 0.
  The `beq` branch at 0x551c targets 0x553c, is taken when (s2(?) & v0(=ret(pcireg_rrb_status_get))) == 0, and falls through when (s2(?) & v0(=ret(pcireg_rrb_status_get))) != 0.
  The `bne` branch at 0x5530 targets 0x5524, is taken when (s2(?) & v0(=ret(pcireg_rrb_status_get))) != 0, and falls through when (s2(?) & v0(=ret(pcireg_rrb_status_get))) == 0.
  The return at 0x554c has v0 = ret(pcireg_rrb_status_get).

- `do_pcibr_rrb_flush` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x5554 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x5554-0x55f4 (160 bytes).
  It occupies 160 bytes.
  The `jal` at 0x5578 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x55ac calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x55b8 calls do_pcibr_rrb_clear with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x55d0 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=ret(pcireg_rrb_get), a3=?.
  The `beq` branch at 0x5598 targets 0x55b4, is taken when (a5(?) & v0(=ret(pcireg_rrb_get))) == 0, and falls through when (a5(?) & v0(=ret(pcireg_rrb_get))) != 0.
  The `beq` branch at 0x55c4 targets 0x55d8, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The return at 0x55ec has v0 = one of ret(do_pcibr_rrb_clear), ret(pcireg_rrb_set).

- `pcibr_rrb_alloc_init` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x55f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x55f4-0x57c4 (464 bytes).
  It occupies 464 bytes.
  The `ld` at 0x5604 loads 8 bytes from a0 (arg0 at entry) +0x8.
  3 such `lw` accesses load 4 bytes from (a0 + ((a2 + (a1 << 0x2)) << 0x2)) +0x568, including `lw` at 0x5630, `lw` at 0x5698, `lw` at 0x5708.
  The `sw` at 0x5674 stores 4 bytes to ((a1 << 0x2) + a0) +0x528.
  2 such `sw` accesses store 4 bytes to (a0 + ((a2 + (a1 << 0x2)) << 0x2)) +0x568, including `sw` at 0x56ac, `sw` at 0x571c.
  The `lw` at 0x56b0 loads 4 bytes from ((a1 << 0x2) + a0) +0x528.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x56bc, `lw` at 0x56f4.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x56cc, `sw` at 0x56fc.
  The `lh` at 0x5758 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lw` at 0x578c loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x5684 calls do_pcibr_rrb_alloc with a0=[a0+8]:8, a1=?, a2=a2 at entry (arg2), a3=0x1.
  The `jal` at 0x5718 calls do_pcibr_rrb_free with a0=[a0+8]:8, a1=?, a2=a2 at entry (arg2), a3=0x1.
  The `jal` at 0x5790 calls pcibr_debug with a0=0x20, a1=[a0+4], a2=sym(.rodata)+3280, a3=[(a0 + ((a2 + (a1 << 0x2)) << 0x2))+1384], a5=a3 at entry (arg3), a7=a2 at entry (arg2).
  The `jal` at 0x57ac calls pcibr_rrb_debug with a0=sym(.rodata)+3280, a1=a0 at entry (arg0), a2=?, a3=?.
  The `beq` branch at 0x565c targets 0x56d0, is taken when s1(=[(a0 + ((a2 + (a1 << 0x2)) << 0x2))+1384]) >= a3 (signed), and falls through when s1(=[(a0 + ((a2 + (a1 << 0x2)) << 0x2))+1384]) < a3 (signed).
  The `beq` branch at 0x566c targets 0x56b0 and is always taken.
  The `bltz` branch at 0x568c targets 0x56d4, is taken when v0(=ret(do_pcibr_rrb_alloc)) < 0 (signed), and falls through when v0(=ret(do_pcibr_rrb_alloc)) >= 0 (signed).
  The `beq` branch at 0x56a8 targets 0x56d4, is taken when s1(?) >= s2(=a3) (signed), and falls through when s1(?) < s2(=a3) (signed).
  The `bgtz` branch at 0x56b4 targets 0x5674, is taken when a2(=[((a1 << 0x2) + a0)+1320]) > 0 (signed), and falls through when a2(=[((a1 << 0x2) + a0)+1320]) <= 0 (signed).
  The `blez` branch at 0x56c0 targets 0x56d4, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x56c8 targets 0x5678 and is always taken.
  The `beq` branch at 0x56ec targets 0x5730, is taken when s2(=a3) >= s1(?) (signed), and falls through when s2(=a3) < s1(?) (signed).
  The `bne` branch at 0x5728 targets 0x56f4, is taken when s2(=a3) < s1(?) (signed), and falls through when s2(=a3) >= s1(?) (signed).
  The `beq` branch at 0x574c targets 0x576c, is taken when at(=a1) == v0(=0xff), and falls through when at(=a1) != v0(=0xff).
  The `beq` branch at 0x5760 targets 0x576c, is taken when v1(=[a0+114]:2) == a0(=0x2), and falls through when v1(=[a0+114]:2) != a0(=0x2).
  The return at 0x57bc has v0 = ret(pcibr_rrb_debug).

- `pcibr_rrb_alloc_more` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x57c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x57c4-0x5918 (340 bytes).
  It occupies 340 bytes.
  The `ld` at 0x57cc loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sw` at 0x5838 stores 4 bytes to ((a1 << 0x2) + a0) +0x528.
  The `lw` at 0x585c loads 4 bytes from (((a2 + (a1 << 0x2)) << 0x2) + a0) +0x568.
  The `sw` at 0x586c stores 4 bytes to (((a2 + (a1 << 0x2)) << 0x2) + a0) +0x568.
  The `lw` at 0x5870 loads 4 bytes from ((a1 << 0x2) + a0) +0x528.
  The `lw` at 0x5880 loads 4 bytes from ?.
  The `sw` at 0x5894 stores 4 bytes to ?.
  The `lh` at 0x58ac loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lw` at 0x58d8 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x5848 calls do_pcibr_rrb_alloc with a0=[a0+8]:8, a1=?, a2=a2 at entry (arg2), a3=0x1, a5=[((a1 << 0x2) + a0)+1320]-1.
  The `jal` at 0x58dc calls pcibr_debug with a0=0x20, a1=[a0+4], a2=sym(.rodata)+3280, a3=?, a4=a3 at entry (arg3), a6=a2 at entry (arg2).
  The `jal` at 0x58ec calls pcibr_rrb_debug with a0=sym(.rodata)+3280, a1=a0 at entry (arg0), a2=?, a3=?.
  The `blez` branch at 0x5808 targets 0x5898, is taken when a3 <= 0 (signed), and falls through when a3 > 0 (signed).
  The `beq` branch at 0x5830 targets 0x5870 and is always taken.
  The `bltz` branch at 0x5850 targets 0x58a0, is taken when v0(=ret(do_pcibr_rrb_alloc)) < 0 (signed), and falls through when v0(=ret(do_pcibr_rrb_alloc)) >= 0 (signed).
  The `beq` branch at 0x5868 targets 0x589c, is taken when s0(?) >= s3(=a3) (signed), and falls through when s0(?) < s3(=a3) (signed).
  The `bgtz` branch at 0x5874 targets 0x5838, is taken when a5(=[((a1 << 0x2) + a0)+1320]) > 0 (signed), and falls through when a5(=[((a1 << 0x2) + a0)+1320]) <= 0 (signed).
  The `blez` branch at 0x5888 targets 0x589c, is taken when a0(?) <= 0 (signed), and falls through when a0(?) > 0 (signed).
  The `beq` branch at 0x5890 targets 0x583c and is always taken.
  The `beq` branch at 0x58a4 targets 0x58bc, is taken when s8(=a1) == a2(=0xff), and falls through when s8(=a1) != a2(=0xff).
  The `beq` branch at 0x58b0 targets 0x58bc, is taken when a3(=[a0+114]:2) == a4(=0x2), and falls through when a3(=[a0+114]:2) != a4(=0x2).
  The return at 0x5910 has v0 = ret(pcibr_rrb_debug).

- `pcibr_rrb_flush` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x5918 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x5918-0x5a94 (380 bytes).
  It occupies 380 bytes.
  The `ld` at 0x5940 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(pciio_info_mfast_get)+8]:8 +0x4, including `lw` at 0x5944, `lw` at 0x5970, `lw` at 0x5a54.
  The `lbu` at 0x5950 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `jal` at 0x5920 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5938 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x5990 calls pcireg_rrb_get with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x59a8 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0x59f8 calls do_pcibr_rrb_flush with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x5a24 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `beq` branch at 0x5968 targets 0x5a54, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0x597c targets 0x5a74, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `beq` branch at 0x59d0 targets 0x59ec and is always taken.
  The `beq` branch at 0x59e4 targets 0x5a14, is taken when s2(?) >= 0x8 (signed), and falls through when s2(?) < 0x8 (signed).
  The `bne` branch at 0x59f0 targets 0x59d8, is taken when s3(?) != t9(?), and falls through when s3(?) == t9(?).
  The `bne` branch at 0x5a0c targets 0x59ec, is taken when s2(?) < 0x8 (signed), and falls through when s2(?) >= 0x8 (signed).
  The `bne` branch at 0x5a64 targets 0x5970, is taken when a2(?) != a3(=0x36), and falls through when a2(?) == a3(=0x36).
  The `beq` branch at 0x5a6c targets 0x5a8c and is always taken.
  The `bne` branch at 0x5a84 targets 0x5984, is taken when a3(?) != a4(=0x24), and falls through when a3(?) == a4(=0x24).
  The `beq` branch at 0x5a8c targets 0x5984 and is always taken.
  The return at 0x5a4c has v0 = ret(mutex_io_spinunlock).

- `pcibr_wrb_flush` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x5a94 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x5a94-0x5ad0 (60 bytes).
  It occupies 60 bytes.
  The `lbu` at 0x5aac loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0x5ab0 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  The `jal` at 0x5a9c calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5aa8 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x5ab4 calls pcireg_wrb_flush_get with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The return at 0x5ac8 has v0 = 0x0.

- `pcibr_rrb_alloc` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x5ad0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x5ad0-0x5ed4 (1028 bytes).
  It occupies 1028 bytes.
  The `lbu` at 0x5af4 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0x5b08 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(pciio_info_mfast_get)+8]:8 +0x4, including `lw` at 0x5b1c, `lw` at 0x5b50, `lw` at 0x5bbc.
  2 such `lw` accesses load 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x5e8, including `lw` at 0x5b70, `lw` at 0x5be0.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0x5b98, `lw` at 0x5c24, `lw` at 0x5d94.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x5ba0, `sw` at 0x5da4, `sw` at 0x5e20.
  3 such `lw` accesses load 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528, including `lw` at 0x5bac, `lw` at 0x5bf0, `lw` at 0x5d90.
  The `sw` at 0x5bb4 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x548.
  The `lw` at 0x5bf8 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x56c.
  The `lw` at 0x5bfc loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `lw` at 0x5c10 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x5c5c loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `sw` at 0x5d50 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `sw` at 0x5d64 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `lw` at 0x5d70 loads 4 bytes from ret(pciio_info_mfast_get) +0x51c.
  The `sw` at 0x5d84 stores 4 bytes to ret(pciio_info_mfast_get) +0x51c.
  The `sw` at 0x5d88 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x56c.
  The `sw` at 0x5d8c stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `lw` at 0x5da8 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x548.
  2 such `sw` accesses store 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528, including `sw` at 0x5db0, `sw` at 0x5e14.
  The `jal` at 0x5aec calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5afc calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x5b10 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0x5d1c calls do_pcibr_rrb_alloc with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?.
  The `jal` at 0x5d38 calls do_pcibr_rrb_alloc with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x1, a3=?, a6=[ret(pciio_info_mfast_get)+8]:8.
  The `jal` at 0x5e2c calls pcibr_rrb_debug with a0=sym(.rodata)+3280, a1=ret(pciio_info_mfast_get), a2=?, a3=?, a4=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2))+1320], a5=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)).
  The `jal` at 0x5e60 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x5eac calls do_pcibr_rrb_free with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?.
  The `jal` at 0x5ec4 calls do_pcibr_rrb_free with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x1, a3=?.
  The `beq` branch at 0x5b44 targets 0x5e84, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0x5b60 targets 0x5bb8, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `bgez` branch at 0x5b74 targets 0x5bec, is taken when v1(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) >= 0 (signed), and falls through when v1(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) < 0 (signed).
  The `bne` branch at 0x5b9c targets 0x5b84, is taken when a1(?) < s6(=one of 0x2, 0x4) (signed), and falls through when a1(?) >= s6(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x5bb0 targets 0x5bf4 and is always taken.
  The `bne` branch at 0x5bcc targets 0x5b68, is taken when a4(?) != a5(=0x24), and falls through when a4(?) == a5(=0x24).
  The `bltz` branch at 0x5be4 targets 0x5b7c, is taken when a5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) < 0 (signed), and falls through when a5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1512]) >= 0 (signed).
  The `beq` branch at 0x5c04 targets 0x5c50, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `bne` branch at 0x5c0c targets 0x5c58, is taken when s5(=a2) != 0, and falls through when s5(=a2) == 0.
  The `bne` branch at 0x5c40 targets 0x5c78, is taken when a1(?) < t1(?) (signed), and falls through when a1(?) >= t1(?) (signed).
  The `beq` branch at 0x5c48 targets 0x5cd8 and is always taken.
  The `beq` branch at 0x5c50 targets 0x5c14, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0x5c58 targets 0x5c14 and is always taken.
  The `beq` branch at 0x5c70 targets 0x5cd8, is taken when a1(?) >= v1(?) (signed), and falls through when a1(?) < v1(?) (signed).
  The `beq` branch at 0x5c78 targets 0x5c9c, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `beq` branch at 0x5c80 targets 0x5c90, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0x5c88 targets 0x5c9c, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x5c94 targets 0x5ca4 and is always taken.
  The `beq` branch at 0x5cac targets 0x5cd8, is taken when a1(?) >= a4(?) (signed), and falls through when a1(?) < a4(?) (signed).
  The `beq` branch at 0x5cb4 targets 0x5c60, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `beq` branch at 0x5cbc targets 0x5ccc, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0x5cc4 targets 0x5c60, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x5cd0 targets 0x5c68 and is always taken.
  The `beq` branch at 0x5cd8 targets 0x5ce8, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x5ce4 targets 0x5e7c, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x5cec targets 0x5cfc, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x5cf4 targets 0x5e7c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bltz` branch at 0x5cfc targets 0x5ea4, is taken when s1(?) < 0 (signed), and falls through when s1(?) >= 0 (signed).
  The `bltz` branch at 0x5d04 targets 0x5ebc, is taken when s0(?) < 0 (signed), and falls through when s0(?) >= 0 (signed).
  The `blez` branch at 0x5d0c targets 0x5d24, is taken when s1(?) <= 0 (signed), and falls through when s1(?) > 0 (signed).
  The `blez` branch at 0x5d24 targets 0x5d40, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `beq` branch at 0x5d44 targets 0x5d5c, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `bne` branch at 0x5d4c targets 0x5d64, is taken when s5(=a2) != 0, and falls through when s5(=a2) == 0.
  The `beq` branch at 0x5d54 targets 0x5d6c and is always taken.
  The `beq` branch at 0x5d5c targets 0x5d6c, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `blez` branch at 0x5dac targets 0x5e08, is taken when s6(=one of 0x2, 0x4) <= 0 (signed), and falls through when s6(=one of 0x2, 0x4) > 0 (signed).
  The `beq` branch at 0x5ddc targets 0x5e08, is taken when a1(?) >= s6(=one of 0x2, 0x4) (signed), and falls through when a1(?) < s6(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x5e00 targets 0x5db8, is taken when a1(?) < s6(=one of 0x2, 0x4) (signed), and falls through when a1(?) >= s6(=one of 0x2, 0x4) (signed).
  The `blez` branch at 0x5e08 targets 0x5e28, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x5e7c targets 0x5e38 and is always taken.
  The `bne` branch at 0x5e94 targets 0x5b50, is taken when a2(?) != a3(=0x36), and falls through when a2(?) == a3(=0x36).
  The `beq` branch at 0x5e9c targets 0x5bd8 and is always taken.
  The `beq` branch at 0x5eb4 targets 0x5d04 and is always taken.
  The `beq` branch at 0x5ecc targets 0x5d0c and is always taken.
  The return at 0x5e74 has v0 = one of -0x1, 0x0.

- `pcibr_rrb_check` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x5ed4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x5ed4-0x6008 (308 bytes).
  It occupies 308 bytes.
  The `lbu` at 0x5f24 loads 1 byte from ret(pciio_info_mfast_get) +0x39.
  The `lbu` at 0x5f28 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0x5f70 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x568.
  The `sw` at 0x5f78 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `lw` at 0x5f84 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x528.
  The `sw` at 0x5f8c stores 4 bytes to a3 (arg3 at entry) +0x0.
  The `lw` at 0x5fc4 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x56c.
  The `sw` at 0x5fcc stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `lw` at 0x5fe0 loads 4 bytes from ?.
  The `sw` at 0x5fe4 stores 4 bytes to a4 (arg4 at entry) +0x0.
  The `jal` at 0x5ef8 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5f10 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?, a7=-0x1.
  The `jal` at 0x5f48 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+128, a1=?, a2=?, a3=?, a7=-0x1.
  The `jal` at 0x5fe8 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=([ret(pciio_hostinfo_get)+540]:1 << 0x4), a3=([ret(pciio_hostinfo_get)+540]:1 << 0x2).
  The `beq` branch at 0x5f08 targets 0x5f98, is taken when v0(=ret(pciio_hostinfo_get)) == 0, and falls through when v0(=ret(pciio_hostinfo_get)) != 0.
  The `beq` branch at 0x5f1c targets 0x6000, is taken when v0(=ret(pciio_info_mfast_get)) == 0, and falls through when v0(=ret(pciio_info_mfast_get)) != 0.
  The `beq` branch at 0x5f38 targets 0x5ff8, is taken when at(=[ret(pciio_hostinfo_get)+540]:1) >= v0(=[ret(pciio_info_mfast_get)+57]:1+1) (signed), and falls through when at(=[ret(pciio_hostinfo_get)+540]:1) < v0(=[ret(pciio_info_mfast_get)+57]:1+1) (signed).
  The `beq` branch at 0x5f64 targets 0x5fbc, is taken when s1(=a1) == 0, and falls through when s1(=a1) != 0.
  The `bne` branch at 0x5f74 targets 0x5fc0, is taken when s4(=a2) != 0, and falls through when s4(=a2) == 0.
  The `beq` branch at 0x5f7c targets 0x5fd0, is taken when s3(=a3) == 0, and falls through when s3(=a3) != 0.
  The `bne` branch at 0x5f88 targets 0x5fd4, is taken when s2(=a4) != 0, and falls through when s2(=a4) == 0.
  The `beq` branch at 0x5f90 targets 0x5fe8 and is always taken.
  The `beq` branch at 0x5fbc targets 0x5f7c, is taken when s4(=a2) == 0, and falls through when s4(=a2) != 0.
  The `bne` branch at 0x5fc8 targets 0x5f80, is taken when s3(=a3) != 0, and falls through when s3(=a3) == 0.
  The `beq` branch at 0x5fd0 targets 0x5fe8, is taken when s2(=a4) == 0, and falls through when s2(=a4) != 0.
  The `beq` branch at 0x5ff0 targets 0x5f98 and is always taken.
  The `beq` branch at 0x5ff8 targets 0x5f9c and is always taken.
  The `beq` branch at 0x6000 targets 0x5f9c and is always taken.
  The return at 0x5fb4 has v0 = one of -0x1, 0x0.

- `pcibr_slot_initial_rrb_alloc` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x63dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x63dc-0x6790 (948 bytes).
  It occupies 948 bytes.
  The `lbu` at 0x641c loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `ld` at 0x6430 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(hwgraph_fastinfo_get)+8]:8 +0x4, including `lw` at 0x6434, `lw` at 0x644c, `lw` at 0x6608.
  8 such `sw` accesses store 4 bytes to ?, including `sw` at 0x6490, `sw` at 0x655c, `sw` at 0x6588.
  3 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0x6494, `lh` at 0x650c, `lh` at 0x6660.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x78, including `lw` at 0x64e8, `lw` at 0x6604.
  The `ld` at 0x64fc loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `ld` at 0x6508 loads 8 bytes from [(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8 +0x0.
  2 such `lw` accesses load 4 bytes from [[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8 +0x14, including `lw` at 0x651c, `lw` at 0x66cc.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x6558, `lw` at 0x6580.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100, including `lw` at 0x6648, `lw` at 0x66dc.
  The `sw` at 0x6734 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x4)) +0x574.
  The `jal` at 0x63f4 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x647c calls do_pcibr_rrb_count_valid with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x64e0 calls pcibr_debug with a0=0x20, a1=a0 at entry (arg0), a2=sym(.rodata)+3280, a3=?.
  The `jal` at 0x65f8 calls pcibr_debug with a0=0x20, a1=a0 at entry (arg0), a2=sym(.rodata)+3280, a3=?.
  The `jal` at 0x6658 calls do_pcibr_rrb_free_all with a0=ret(hwgraph_fastinfo_get), a1=[ret(hwgraph_fastinfo_get)+8]:8, a2=a1 at entry (arg1), a3=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20], a4=-0x1, a5=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256].
  The `jal` at 0x66fc calls do_pcibr_rrb_free with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=?, a3=0x8.
  The `beq` branch at 0x6414 targets 0x6590, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x6428 targets 0x65c0, is taken when s1(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s1(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0x6444 targets 0x6608, is taken when v0(?) == v1(=0xc002), and falls through when v0(?) != v1(=0xc002).
  The `beq` branch at 0x645c targets 0x6628, is taken when v1(?) == a0(=0xd002), and falls through when v1(?) != a0(=0xd002).
  The `bne` branch at 0x648c targets 0x646c, is taken when s3(?) < s2(=one of 0x2, 0x4) (signed), and falls through when s3(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x6498 targets 0x65c8, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == 0, and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != 0.
  The `beq` branch at 0x64a0 targets 0x65cc, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == s3(=0x1), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != s3(=0x1).
  The `beq` branch at 0x64ac targets 0x6738, is taken when s1(=a1) == t9(=0xff), and falls through when s1(=a1) != t9(=0xff).
  The `beq` branch at 0x64b8 targets 0x64c4, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == ra(=0x2), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != ra(=0x2).
  The `beq` branch at 0x6504 targets 0x651c, is taken when (v1(?) & 0x2) == 0, and falls through when (v1(?) & 0x2) != 0.
  The `beq` branch at 0x6514 targets 0x66bc, is taken when a2(=[ret(hwgraph_fastinfo_get)+114]:2) == a1(=0x2), and falls through when a2(=[ret(hwgraph_fastinfo_get)+114]:2) != a1(=0x2).
  The `beq` branch at 0x6524 targets 0x6648, is taken when a3(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20]) == a4(=-0x1), and falls through when a3(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20]) != a4(=-0x1).
  The `blez` branch at 0x652c targets 0x6590, is taken when s2(=one of 0x2, 0x4) <= 0 (signed), and falls through when s2(=one of 0x2, 0x4) > 0 (signed).
  The `beq` branch at 0x6560 targets 0x658c, is taken when v0(?) >= s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) < s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x6584 targets 0x653c, is taken when v0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x65c0 targets 0x6590 and is always taken.
  The `beq` branch at 0x65cc targets 0x65e4, is taken when s1(=a1) == t0(=0xff), and falls through when s1(=a1) != t0(=0xff).
  The `beq` branch at 0x65d8 targets 0x65e4, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == t1(=0x2), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != t1(=0x2).
  The `beq` branch at 0x6600 targets 0x64ec and is always taken.
  The `bne` branch at 0x6618 targets 0x644c, is taken when a3(?) != a4(=0x36), and falls through when a3(?) == a4(=0x36).
  The `beq` branch at 0x6620 targets 0x6640 and is always taken.
  The `bne` branch at 0x6638 targets 0x6464, is taken when a4(?) != a5(=0x24), and falls through when a4(?) == a5(=0x24).
  The `beq` branch at 0x6640 targets 0x6464 and is always taken.
  The `bne` branch at 0x664c targets 0x652c, is taken when a5(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0, and falls through when a5(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0.
  The `beq` branch at 0x6668 targets 0x6740, is taken when a6(=[ret(hwgraph_fastinfo_get)+114]:2) == 0, and falls through when a6(=[ret(hwgraph_fastinfo_get)+114]:2) != 0.
  The `bne` branch at 0x6670 targets 0x66b4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x6690 targets 0x66b4, is taken when v0(?) >= s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) < s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x66ac targets 0x667c, is taken when v0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x66b4 targets 0x6590 and is always taken.
  The `beq` branch at 0x66bc targets 0x66cc, is taken when a1(=0x2) == s1(=a1), and falls through when a1(=0x2) != s1(=a1).
  The `bne` branch at 0x66c4 targets 0x651c, is taken when s1(=a1) != t1(=0x3), and falls through when s1(=a1) == t1(=0x3).
  The `bne` branch at 0x66d4 targets 0x652c, is taken when t2(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20]) != t3(=-0x1), and falls through when t2(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8]:8+20]) == t3(=-0x1).
  The `bne` branch at 0x66e0 targets 0x652c, is taken when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0, and falls through when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0.
  The `bne` branch at 0x6718 targets 0x66f0, is taken when s2(?) < 0x2 (signed), and falls through when s2(?) >= 0x2 (signed).
  The `beq` branch at 0x6730 targets 0x6590 and is always taken.
  The `beq` branch at 0x6738 targets 0x64c8 and is always taken.
  The `bne` branch at 0x6740 targets 0x66b4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x6764 targets 0x66b4, is taken when v0(?) >= s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) < s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x6780 targets 0x6750, is taken when v0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x6788 targets 0x66b4 and is always taken.
  The return at 0x65b8 has v0 = one of 0x0, 0x13, 0x16.

- `pcibr_initial_rrb` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x6790 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x6790-0x6ae8 (856 bytes).
  It occupies 856 bytes.
  The `ld` at 0x67d8 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(hwgraph_fastinfo_get)+8]:8 +0x4, including `lw` at 0x67e0, `lw` at 0x681c, `lw` at 0x6a9c.
  2 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0x67f0, `lbu` at 0x6a60.
  The `lbu` at 0x67f8 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  The `sw` at 0x6864 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x520.
  The `sw` at 0x687c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x524.
  9 such `lw` accesses load 4 bytes from ?, including `lw` at 0x6898, `lw` at 0x689c, `lw` at 0x68a8.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0x68dc, `sw` at 0x6914, `sw` at 0x6948.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x34, including `lw` at 0x6968, `lw` at 0x6ae4.
  The `jal` at 0x67b8 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6850 calls do_pcibr_rrb_count_avail with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=?, a3=?.
  The `jal` at 0x6860 calls do_pcibr_rrb_count_avail with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x1, a2=?, a3=?.
  The `jal` at 0x69bc calls pcibr_rrb_debug with a0=sym(.rodata)+3280, a1=ret(hwgraph_fastinfo_get), a2=?, a3=?, a5=0x1, a7=sp-88.
  The `jal` at 0x6a54 calls pcibr_slot_initial_rrb_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x6814 targets 0x6a9c, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0x6828 targets 0x6abc, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `beq` branch at 0x6834 targets 0x6844, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x683c targets 0x6a54 and is always taken.
  The `bne` branch at 0x68d4 targets 0x6908, is taken when t0(?) < v1(?) (signed), and falls through when t0(?) >= v1(?) (signed).
  The `bne` branch at 0x68e8 targets 0x688c, is taken when a0(?) < 0x2 (signed), and falls through when a0(?) >= 0x2 (signed).
  The `bne` branch at 0x68f4 targets 0x69ac, is taken when s3(=a2) < a2(?) (signed), and falls through when s3(=a2) >= a2(?) (signed).
  The `beq` branch at 0x6900 targets 0x6adc and is always taken.
  The `bne` branch at 0x6908 targets 0x69e4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x6910 targets 0x68e0 and is always taken.
  The `bne` branch at 0x6934 targets 0x691c, is taken when a1(?) < s1(=one of 0x2, 0x4) (signed), and falls through when a1(?) >= s1(=one of 0x2, 0x4) (signed).
  The `blez` branch at 0x6940 targets 0x6958, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `bne` branch at 0x6960 targets 0x69ac, is taken when s3(=a2) < v0(?) (signed), and falls through when s3(=a2) >= v0(?) (signed).
  The `bne` branch at 0x6970 targets 0x6958, is taken when (a0(=[ret(hwgraph_fastinfo_get)+52]) & a1(?)) != 0, and falls through when (a0(=[ret(hwgraph_fastinfo_get)+52]) & a1(?)) == 0.
  The `bne` branch at 0x6990 targets 0x6918, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `blez` branch at 0x6998 targets 0x6958, is taken when a6(?) <= 0 (signed), and falls through when a6(?) > 0 (signed).
  The `beq` branch at 0x69a4 targets 0x6944 and is always taken.
  The `bne` branch at 0x69e4 targets 0x6a94, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x69ec targets 0x68e0 and is always taken.
  The `bne` branch at 0x6a10 targets 0x69f8, is taken when a2(?) < s1(=one of 0x2, 0x4) (signed), and falls through when a2(?) >= s1(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x6a1c targets 0x6a44, is taken when v0(?) >= 0x3 (signed), and falls through when v0(?) < 0x3 (signed).
  The `beq` branch at 0x6a4c targets 0x6844, is taken when s2(?) >= a5(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(?) < a5(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `bne` branch at 0x6a70 targets 0x6a44, is taken when s2(?) < s4(=a1) (signed), and falls through when s2(?) >= s4(=a1) (signed).
  The `bne` branch at 0x6a78 targets 0x6a44, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x6a80 targets 0x69f4, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `beq` branch at 0x6a8c targets 0x6a24 and is always taken.
  The `beq` branch at 0x6a94 targets 0x68e0 and is always taken.
  The `bne` branch at 0x6aac targets 0x681c, is taken when t3(?) != t8(=0x36), and falls through when t3(?) == t8(=0x36).
  The `beq` branch at 0x6ab4 targets 0x6ad4 and is always taken.
  The `bne` branch at 0x6acc targets 0x6830, is taken when t8(?) != t9(=0x24), and falls through when t8(?) == t9(=0x24).
  The `beq` branch at 0x6ad4 targets 0x6830 and is always taken.
  The `beq` branch at 0x6ae0 targets 0x696c and is always taken.
  The return at 0x69dc has v0 = 0x0.

- `pcibr_rrb_debug` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x6ae8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x6ae8-0x6cbc (468 bytes).
  It occupies 468 bytes.
  The `lw` at 0x6b1c loads 4 bytes from a1 (arg1 at entry) +0x524.
  The `lw` at 0x6b28 loads 4 bytes from a1 (arg1 at entry) +0x520.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x6b2c, `lw` at 0x6b4c, `lw` at 0x6bc4.
  3 such `lh` accesses load 2 bytes from a1 (arg1 at entry) +0x72, including `lh` at 0x6b38, `lh` at 0x6b74, `lh` at 0x6bec.
  3 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x39, including `lbu` at 0x6b58, `lbu` at 0x6bd0, `lbu` at 0x6cb8.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0x6b80, `lw` at 0x6b88, `lw` at 0x6b94.
  The `jal` at 0x6b30 calls pcibr_debug with a0=0x20, a1=[a1+4], a2=sym(.rodata)+3280, a3=a0 at entry (arg0), a4=[a1+1312], a5=[a1+1316].
  The `jal` at 0x6b50 calls pcibr_debug with a0=0x20, a1=[a1+4], a2=sym(.rodata)+3280, a3=?.
  The `jal` at 0x6bb0 calls sprintf with a0=sp-320, a1=sym(.rodata)+3280, a2=?, a3=?.
  The `jal` at 0x6bc8 calls pcibr_debug with a0=0x20, a1=[a1+4], a2=sym(.rodata)+3280, a3=sp-320.
  The `jal` at 0x6c54 calls sprintf with a0=sp-320, a1=sym(.rodata)+3280, a2=?, a3=?.
  The `jal` at 0x6cac calls pcibr_debug with a0=0x20, a1=[a1+4], a2=sym(.rodata)+3280, a3=?.
  The `beq` branch at 0x6b14 targets 0x6c64, is taken when (at(=[sym(pcibr_debug_mask)]) & 0x20) == 0, and falls through when (at(=[sym(pcibr_debug_mask)]) & 0x20) != 0.
  The `beq` branch at 0x6b3c targets 0x6ca4, is taken when a0(=[a1+114]:2) == 0, and falls through when a0(=[a1+114]:2) != 0.
  The `beq` branch at 0x6b44 targets 0x6ca4, is taken when a0(=[a1+114]:2) == a1(=0x1), and falls through when a0(=[a1+114]:2) != a1(=0x1).
  The `bltz` branch at 0x6b68 targets 0x6c64, is taken when v0(=[a1+57]:1) < 0 (signed), and falls through when v0(=[a1+57]:1) >= 0 (signed).
  The `beq` branch at 0x6b70 targets 0x6bf0 and is always taken.
  The `beq` branch at 0x6be4 targets 0x6c64, is taken when s0(?) >= a3(=[a1+57]:1+1) (signed), and falls through when s0(?) < a3(=[a1+57]:1+1) (signed).
  The `beq` branch at 0x6bf0 targets 0x6c1c, is taken when a0(=[a1+114]:2) == 0, and falls through when a0(=[a1+114]:2) != 0.
  The `beq` branch at 0x6bf8 targets 0x6c1c, is taken when a0(=[a1+114]:2) == s5(=0x1), and falls through when a0(=[a1+114]:2) != s5(=0x1).
  The `beq` branch at 0x6c00 targets 0x6c88, is taken when s3(=0xff) == s0(?), and falls through when s3(=0xff) != s0(?).
  The `bne` branch at 0x6c08 targets 0x6b78, is taken when a0(=[a1+114]:2) != s4(=0x2), and falls through when a0(=[a1+114]:2) == s4(=0x2).
  The `beq` branch at 0x6c14 targets 0x6b78 and is always taken.
  The `beq` branch at 0x6c1c targets 0x6c90, is taken when s3(=0xff) == s0(?), and falls through when s3(=0xff) != s0(?).
  The `beq` branch at 0x6c24 targets 0x6c98, is taken when a0(=[a1+114]:2) == s4(=0x2), and falls through when a0(=[a1+114]:2) != s4(=0x2).
  The `beq` branch at 0x6c5c targets 0x6bbc and is always taken.
  The `beq` branch at 0x6c88 targets 0x6b78 and is always taken.
  The `beq` branch at 0x6c90 targets 0x6c2c and is always taken.
  The `beq` branch at 0x6c9c targets 0x6c2c and is always taken.
  The `beq` branch at 0x6cb4 targets 0x6b5c and is always taken.
  The return at 0x6c80 has v0 = one of ?, [a1+57]:1, ret(pcibr_debug).

- `pcibr_hints_get` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x6cbc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x6cbc-0x6dc4 (264 bytes).
  It occupies 264 bytes.
  The `sd` at 0x6d00 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sd` at 0x6d08 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `jal` at 0x6cd8 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4040, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x6cf4 calls kmem_zalloc with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0x6d10 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4040, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x6d54 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4040, a2=sp-48, a3=?.
  The `jal` at 0x6da8 calls cmn_err with a0=0x4, a1=sym(.rodata)+4040, a2=?, a3=?.
  The `jal` at 0x6db4 calls kmem_free with a0=?, a1=0x20, a2=?, a3=?.
  The `beq` branch at 0x6ce0 targets 0x6d44, is taken when s3(=a1) == 0, and falls through when s3(=a1) != 0.
  The `beq` branch at 0x6ce8 targets 0x6d3c, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0x6d1c targets 0x6d4c, is taken when v0(=ret(hwgraph_info_add_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_add_LBL)) != 0.
  The `beq` branch at 0x6d24 targets 0x6da0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x6d3c targets 0x6d2c and is always taken.
  The `beq` branch at 0x6d44 targets 0x6d2c and is always taken.
  The `beq` branch at 0x6d60 targets 0x6d80, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0x6d68 targets 0x6da4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x6d70 targets 0x6da4, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x6d78 targets 0x6d2c and is always taken.
  The `beq` branch at 0x6d8c targets 0x6da0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x6d94 targets 0x6da4, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x6d9c targets 0x6d2c, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x6dbc targets 0x6d2c and is always taken.
  The return at 0x6d34 has v0 = one of ?, 0x0.

- `pcibr_hints_fix_some_rrbs` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x6dc4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x6dc4-0x6e10 (76 bytes).
  It occupies 76 bytes.
  The `sw` at 0x6de4 stores 4 bytes to ret(pcibr_hints_get) +0x8.
  The `jal` at 0x6dd4 calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6e00 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4040, a3=?.
  The `beq` branch at 0x6ddc targets 0x6df4, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x6e08 targets 0x6dec and is always taken.
  The return at 0x6dec has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_hints_fix_rrbs` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x6e10 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x6e10-0x6e2c (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x6e18 calls pcibr_hints_fix_some_rrbs with a0=a0 at entry (arg0), a1=0xff, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x6e24 has v0 = ret(pcibr_hints_fix_some_rrbs).

- `pcibr_hints_dualslot` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x6e2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x6e2c-0x6e88 (92 bytes).
  It occupies 92 bytes.
  The `sb` at 0x6e60 stores 1 byte to (a2 + ret(pcibr_hints_get)) +0x0.
  The `jal` at 0x6e40 calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6e78 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4040, a3=?.
  The `beq` branch at 0x6e48 targets 0x6e70, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x6e80 targets 0x6e68 and is always taken.
  The return at 0x6e68 has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_hints_intr_bits` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x6e88 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x6e88-0x6ed4 (76 bytes).
  It occupies 76 bytes.
  The `sd` at 0x6eac stores 8 bytes to ret(pcibr_hints_get) +0x18.
  The `jal` at 0x6e98 calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6ec4 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4040, a3=?.
  The `beq` branch at 0x6ea0 targets 0x6ebc, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x6ecc targets 0x6eb4 and is always taken.
  The return at 0x6eb4 has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_set_rrb_callback` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x6ed4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x6ed4-0x6f00 (44 bytes).
  It occupies 44 bytes.
  The `sd` at 0x6ef4 stores 8 bytes to ret(pcibr_hints_get) +0x10.
  The `jal` at 0x6ee0 calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x6ee8 targets 0x6ef8, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The return at 0x6ef8 has v0 = ret(pcibr_hints_get).

- `pcibr_hints_handsoff` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x6f00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x6f00-0x6f48 (72 bytes).
  It occupies 72 bytes.
  The `sw` at 0x6f1c stores 4 bytes to ret(pcibr_hints_get) +0xc.
  The `jal` at 0x6f0c calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6f38 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4040, a3=0x1.
  The `beq` branch at 0x6f14 targets 0x6f2c, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x6f40 targets 0x6f24 and is always taken.
  The return at 0x6f24 has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_hints_subdevs` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x6f48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x6f48-0x709c (340 bytes).
  It occupies 340 bytes.
  The `sd` at 0x6fbc stores 8 bytes to ?.
  The `sd` at 0x6fec stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `jal` at 0x6f7c calls sprintf with a0=sp-48, a1=sym(.rodata)+4040, a2=sym(.rodata)+4040, a3=a1 at entry (arg1), a4=-0x1.
  The `jal` at 0x6f8c calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-48, a2=sp-56, a3=?.
  The `jal` at 0x6fa8 calls hwgraph_info_get_LBL with a0=?, a1=sym(.rodata)+4040, a2=sp-64, a3=?, a5=-0x1.
  The `jal` at 0x6fd4 calls kmem_zalloc with a0=0x8, a1=0x0, a2=?, a3=?.
  The `jal` at 0x6ff4 calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+4040, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7008 calls hwgraph_info_get_LBL with a0=?, a1=sym(.rodata)+4040, a2=sp-64, a3=?.
  The `jal` at 0x7020 calls kmem_free with a0=?, a1=0x8, a2=?, a3=?.
  The `jal` at 0x703c calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4040, a3=?.
  The `jal` at 0x7058 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4040, a3=?, a5=-0x1.
  The `jal` at 0x7074 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4040, a3=?.
  The `jal` at 0x708c calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4040, a3=?.
  The `beq` branch at 0x6f9c targets 0x704c, is taken when a5(=-0x1) == a0(?), and falls through when a5(=-0x1) != a0(?).
  The `beq` branch at 0x6fb4 targets 0x6fd4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x6fdc targets 0x7068, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x7018 targets 0x6fc0, is taken when a2(?) == a3(?), and falls through when a2(?) != a3(?).
  The `beq` branch at 0x702c targets 0x7084, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x7044 targets 0x6fbc and is always taken.
  The `beq` branch at 0x7060 targets 0x6fc4 and is always taken.
  The `beq` branch at 0x707c targets 0x6fc4 and is always taken.
  The `beq` branch at 0x7094 targets 0x6fc4 and is always taken.
  The return at 0x6fcc has v0 = one of ?, ret(pcibr_debug).

- `pcibr_intr_bits` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x709c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x709c-0x70e8 (76 bytes).
  It occupies 76 bytes.
  The `lbu` at 0x709c loads 1 byte from a0 (arg0 at entry) +0x21c.
  The `beq` branch at 0x70b0 targets 0x70d8, is taken when a6(=[a0+540]:1) >= a2 (signed), and falls through when a6(=[a0+540]:1) < a2 (signed).
  The `beq` branch at 0x70b8 targets 0x70e0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x70e0 targets 0x70c0 and is always taken.
  The return at 0x70d0 has v0 = ?.
  The return at 0x70d8 has v0 = 0x0.

- `pcibr_wrap_get` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x70e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x70e8-0x714c (100 bytes).
  It occupies 100 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x70e8, `lw` at 0x7148.
  The `lw` at 0x70ec loads 4 bytes from a0 (arg0 at entry) +0x4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8, including `sw` at 0x7114, `sw` at 0x7124.
  The `ld` at 0x711c loads 8 bytes from (a0 + ([a0+8]+1 << 0x3)) +0x8.
  The `jal` at 0x7138 calls panic with a0=sym(.rodata)+4504, a1=a0 at entry (arg0), a2=[a0+8], a3=a3 at entry (arg3).
  The `beq` branch at 0x70fc targets 0x7134, is taken when at(=[a0+4]) == a2(=[a0+8]), and falls through when at(=[a0+4]) != a2(=[a0+8]).
  The `beq` branch at 0x7144 targets 0x7104 and is always taken.
  The return at 0x712c has v0 = [(a0 + ([a0+8]+1 << 0x3))+8]:8.

- `pcibr_wrap_put` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x714c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x714c-0x71e0 (148 bytes).
  It occupies 148 bytes.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x716c, `lw` at 0x71dc.
  The `lw` at 0x717c loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `sd` at 0x719c stores 8 bytes to (a1 + ([a1+4] << 0x3)) +0x10.
  The `sw` at 0x71a0 stores 4 bytes to a1 (arg1 at entry) +0x4.
  The `jal` at 0x7164 calls mutex_spinlock with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x71a4 calls mutex_spinunlock with a0=a1 at entry (arg1), a1=ret(mutex_spinlock), a2=[a1+4], a3=?.
  The `jal` at 0x71c8 calls panic with a0=sym(.rodata)+4504, a1=a1 at entry (arg1), a2=[a1+4], a3=?.
  The `beq` branch at 0x7188 targets 0x71c0, is taken when at(=[a1+8]) == a5(?), and falls through when at(=[a1+8]) != a5(?).
  The `beq` branch at 0x71d8 targets 0x7190 and is always taken.
  The return at 0x71b8 has v0 = ret(mutex_spinunlock).

- `pcibr_force_interrupt` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x71e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x71e0-0x7268 (136 bytes).
  It occupies 136 bytes.
  The `ld` at 0x71e8 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x71ec loads 2 bytes from [a0]:8 +0x72.
  The `lw` at 0x71f4 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x7250 loads 8 bytes from ?.
  The `jal` at 0x7204 calls pcireg_force_intr_set with a0=[a0]:8, a1=[a0+8], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7220 calls pcireg_intr_status_get with a0=[a0]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x724c calls xtalk_intr_vector_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7258 calls heart_set_cpu_intr with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x71f8 targets 0x7220, is taken when at(=[[a0]:8+114]:2) == 0, and falls through when at(=[[a0]:8+114]:2) != 0.
  The `beq` branch at 0x7234 targets 0x7210, is taken when (v0(=ret(pcireg_intr_status_get)) & v1(?)) == 0, and falls through when (v0(=ret(pcireg_intr_status_get)) & v1(?)) != 0.
  The `beq` branch at 0x7260 targets 0x7210 and is always taken.
  The return at 0x7218 has v0 = one of ret(pcireg_force_intr_set), ?, ret(heart_set_cpu_intr).

- `pcibr_intrd` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x7268 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x7268-0x72e0 (120 bytes).
  It occupies 120 bytes.
  The `ld` at 0x726c loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0x7280 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ll` at 0x7294 loads 4 bytes from ret(pcibr_wrap_get) +0x18.
  The `sc` at 0x72a0 stores 4 bytes to ret(pcibr_wrap_get) +0x18.
  The `lw` at 0x72ac loads 4 bytes from ret(pcibr_wrap_get) +0x18.
  The `jalr` at 0x727c calls (unknown callee) with a0=[a0+32]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7284 calls pcibr_wrap_get with a0=a0+104, a1=?, a2=?, a3=?.
  The `jal` at 0x72b8 calls ipsema with a0=a0+48, a1=?, a2=?, a3=?.
  The `jal` at 0x72d0 calls pcibr_force_interrupt with a0=ret(pcibr_wrap_get), a1=ret(pcibr_wrap_get)+24, a2=-0x1, a3=[ret(pcibr_wrap_get)+24]-1.
  The `beql` branch at 0x72a4 targets 0x7294, is taken when a3(=[ret(pcibr_wrap_get)+24]-1) == 0, and falls through when a3(=[ret(pcibr_wrap_get)+24]-1) != 0; its branch-likely delay slot `nop` at 0x72a8 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x72b0 targets 0x72d0, is taken when v1(=[ret(pcibr_wrap_get)+24]) == 0, and falls through when v1(=[ret(pcibr_wrap_get)+24]) != 0.
  The `beq` branch at 0x72d8 targets 0x72b8 and is always taken.
  The return at 0x72c8 has v0 = ret(ipsema).

- `pcibr_intrd_start` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x72e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x72e0-0x735c (124 bytes).
  It occupies 124 bytes.
  The `lh` at 0x72f4 loads 2 bytes from a0 (arg0 at entry) +0x50.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc020, including `ld` at 0x72f8, `ld` at 0x7314.
  The `ld` at 0x7310 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ll` at 0x7330 loads 4 bytes from a0 (arg0 at entry) +0x28.
  The `sc` at 0x7338 stores 4 bytes to a0 (arg0 at entry) +0x28.
  The `jal` at 0x72f0 calls setmustrun with a0=[a0+80]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7300 calls xthread_set_func with a0=[-0x3fe0]:8, a1=sym(pcibr_intrd), a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x730c calls fetch_kname with a0=[a0+24]:8, a1=sp-32, a2=?, a3=?.
  The `jal` at 0x7320 calls strncpy with a0=[-0x3fe0]:8+832, a1=ret(fetch_kname), a2=0x10, a3=?.
  The `jal` at 0x7344 calls ipsema with a0=a0+48, a1=[a0+40], a2=a0+40, a3=0x400, a4=([a0+40] | 0x400).
  The `beql` branch at 0x733c targets 0x7330, is taken when a4(=([a0+40] | 0x400)) == 0, and falls through when a4(=([a0+40] | 0x400)) != 0; its branch-likely delay slot `nop` at 0x7340 runs only when taken and is annulled on fall-through.
  The return at 0x7354 has v0 = ret(ipsema).

- `pcibr_thread_setup` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x735c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x735c-0x73d4 (120 bytes).
  It occupies 120 bytes.
  The `sh` at 0x7398 stores 2 bytes to a0 (arg0 at entry) +0x48.
  The `ll` at 0x73a0 loads 4 bytes from a0 (arg0 at entry) +0x28.
  The `sc` at 0x73a8 stores 4 bytes to a0 (arg0 at entry) +0x28.
  The `jal` at 0x7380 calls sprintf with a0=sp-64, a1=sym(.rodata)+4504, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x73bc calls xthread_setup with a0=sp-64, a1=a2 at entry (arg2), a2=a0+40, a3=sym(pcibr_intrd_start), a4=a0 at entry (arg0), a5=0x300, a6=([a0+40] | 0x300), a7=a2 at entry (arg2).
  The `beql` branch at 0x73ac targets 0x73a0, is taken when a6(=([a0+40] | 0x300)) == 0, and falls through when a6(=([a0+40] | 0x300)) != 0; its branch-likely delay slot `nop` at 0x73b0 runs only when taken and is annulled on fall-through.
  The return at 0x73cc has v0 = ret(xthread_setup).

- `pcibr_intr_alloc` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x73d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x73d4-0x7a00 (1580 bytes).
  It occupies 1580 bytes.
  The `lbu` at 0x7418 loads 1 byte from ret(pcibr_info_get) +0x21c.
  The `ld` at 0x741c loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `lw` at 0x7428 loads 4 bytes from [ret(pcibr_info_get)+40]:8 +0x0.
  2 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x70, including `sw` at 0x74d4, `sw` at 0x74e8.
  The `sw` at 0x74ec stores 4 bytes to ret(kmem_zalloc) +0x6c.
  The `sd` at 0x74f0 stores 8 bytes to ret(kmem_zalloc) +0x20.
  The `sd` at 0x74f4 stores 8 bytes to ret(kmem_zalloc) +0x18.
  2 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x58, including `sw` at 0x74f8, `sw` at 0x75b8.
  The `sd` at 0x74fc stores 8 bytes to ret(kmem_zalloc) +0x60.
  3 such `sh` accesses store 2 bytes to ret(kmem_zalloc) +0x50, including `sh` at 0x7504, `sh` at 0x7598, `sh` at 0x76e8.
  The `sw` at 0x750c stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `sw` at 0x7518 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `sw` at 0x7528 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `ld` at 0x752c loads 8 bytes from [ret(pcibr_info_get)+40]:8 +0x500.
  The `lbu` at 0x7530 loads 1 byte from [ret(pcibr_info_get)+40]:8 +0x39.
  2 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x58, including `lw` at 0x75a4, `lw` at 0x79d4.
  The `sd` at 0x75bc stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `sd` at 0x75c4 stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0x75d0 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sb` at 0x75e8 stores 1 byte to ret(kmem_zalloc) +0x18.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x7658, `ld` at 0x7698, `ld` at 0x7720.
  The `sw` at 0x775c stores 4 bytes to ?.
  The `ld` at 0x77f0 loads 8 bytes from a1 (arg1 at entry) +0x10.
  The `lh` at 0x7810 loads 2 bytes from ret(kmem_zalloc) +0x50.
  2 such `ld` accesses load 8 bytes from [ret(pcibr_info_get)+40]:8 +0x10, including `ld` at 0x7974, `ld` at 0x79d8.
  The `jal` at 0x73f4 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7484 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4504, a3=sym(.rodata)+4504, a4=sym(.rodata)+4504, a5=sym(.rodata)+4504, a6=sym(.rodata)+4504, a7=sym(.rodata)+4504.
  The `jal` at 0x7490 calls kmem_zalloc with a0=0xa0, a1=0x0, a2=?, a3=?.
  The `jal` at 0x74b0 calls device_desc_flags_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?, a5=[sym(default_intr_pri)].
  The `jal` at 0x7524 calls spinlock_init with a0=ret(kmem_zalloc)+104, a1=sym(.rodata)+4504, a2=?, a3=?.
  The `jalr` at 0x753c calls (unknown callee) with a0=?, a1=a2 at entry (arg2), a2=[[ret(pcibr_info_get)+40]:8+57]:1+1, a3=[[ret(pcibr_info_get)+40]:8+1280]:8.
  The `jal` at 0x7554 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4504, a3=ret(?).
  The `jal` at 0x75b4 calls kmem_zalloc with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0x75e4 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4504, a3=?.
  The `jal` at 0x75f4 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7610 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4504, a3=ret(?).
  The `jal` at 0x7670 calls xtalk_intr_cpuid_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x76a8 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x76bc calls kmem_free with a0=ret(kmem_zalloc), a1=0x20, a2=?, a3=?.
  The `jal` at 0x76d4 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4504, a3=ret(?).
  The `jal` at 0x76f4 calls xtalk_intr_alloc_nothd with a0=?, a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x7710 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4504, a3=ret(xtalk_intr_alloc_nothd).
  The `jal` at 0x7738 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7760 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4504, a3=ret(?).
  The `jal` at 0x7774 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(xtalk_intr_alloc_nothd), a3=?.
  The `jal` at 0x778c calls pcireg_intr_device_bit_clr with a0=[ret(pcibr_info_get)+40]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x77a0 calls pcireg_intr_device_bit_set with a0=[ret(pcibr_info_get)+40]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x77b4 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4504, a3=?.
  The `jal` at 0x77d8 calls pcibr_thread_setup [0x735c] with a0=ret(kmem_zalloc), a1=ret(?), a2=?, a3=?, a4=a1 at entry (arg1).
  The `jal` at 0x77f8 calls xtalk_intr_cpuid_get with a0=?, a1=?, a2=?, a3=?, a4=a1 at entry (arg1).
  The `jal` at 0x7828 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4504, a3=ret(kmem_zalloc), a4=a1 at entry (arg1), a6=ret(xtalk_intr_cpuid_get).
  The `jal` at 0x786c calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7880 calls kmem_free with a0=ret(kmem_zalloc), a1=0x20, a2=?, a3=?.
  The `jal` at 0x7898 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4504, a3=ret(?).
  The `jal` at 0x78ac calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x78d0 calls xtalk_intr_free with a0=ret(xtalk_intr_alloc_nothd), a1=?, a2=?, a3=?.
  The `jal` at 0x791c calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4504, a3=ret(?).
  The `jal` at 0x792c calls device_desc_intr_target_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x7940 calls cpuvertex_to_cpuid with a0=ret(device_desc_intr_target_get), a1=?, a2=?, a3=?.
  The `jal` at 0x7960 calls device_desc_intr_swlevel_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x7978 calls cmn_err with a0=0x4, a1=sym(.rodata)+4504, a2=[[ret(pcibr_info_get)+40]:8+16]:8, a3=?, a5=-0x1.
  The `jal` at 0x7990 calls cmn_err with a0=0x4, a1=sym(.rodata)+4504, a2=?, a3=?.
  The `jal` at 0x79a8 calls vertex_to_name with a0=a3 at entry (arg3), a1=sp-440, a2=0x100, a3=?, a5=-0x1.
  The `jal` at 0x79c8 calls cmn_err with a0=0x4, a1=sym(.rodata)+4504, a2=?, a3=?, a5=sp-440, a6=a3 at entry (arg3).
  The `jal` at 0x79dc calls cmn_err with a0=0x1, a1=sym(.rodata)+4504, a2=[[ret(pcibr_info_get)+40]:8+16]:8, a3=?.
  The `beq` branch at 0x742c targets 0x78e4, is taken when (s0(=a2) & 0xf) == 0, and falls through when (s0(=a2) & 0xf) != 0.
  The `beq` branch at 0x7440 targets 0x78f0, is taken when (s0(=a2) & 0x1) == 0, and falls through when (s0(=a2) & 0x1) != 0.
  The `beq` branch at 0x7450 targets 0x78f8, is taken when (s0(=a2) & 0x2) == 0, and falls through when (s0(=a2) & 0x2) != 0.
  The `beq` branch at 0x7460 targets 0x7900, is taken when (s0(=a2) & 0x4) == 0, and falls through when (s0(=a2) & 0x4) != 0.
  The `beq` branch at 0x7470 targets 0x7908, is taken when (s0(=a2) & 0x8) == 0, and falls through when (s0(=a2) & 0x8) != 0.
  The `beq` branch at 0x749c targets 0x78c8, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x74a8 targets 0x74d8, is taken when t0(=a1) == 0, and falls through when t0(=a1) != 0.
  The `beq` branch at 0x74c8 targets 0x792c, is taken when (v0(=ret(device_desc_flags_get)) & 0x4) == 0, and falls through when (v0(=ret(device_desc_flags_get)) & 0x4) != 0.
  The `beq` branch at 0x74d0 targets 0x74ec and is always taken.
  The `beq` branch at 0x756c targets 0x79ec and is always taken.
  The `bne` branch at 0x757c targets 0x7970, is taken when a6(?) != a1(?), and falls through when a6(?) == a1(?).
  The `beq` branch at 0x7588 targets 0x76e4, is taken when a7(?) == a5(=-0x1), and falls through when a7(?) != a5(=-0x1).
  The `bne` branch at 0x759c targets 0x79a0, is taken when t1(?) != t0(?), and falls through when t1(?) == t0(?).
  The `beq` branch at 0x75fc targets 0x7698, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x7634 targets 0x77c4, is taken when s0(?) >= 0x8 (unsigned), and falls through when s0(?) < 0x8 (unsigned).
  The `beq` branch at 0x7648 targets 0x7618, is taken when (s5(?) & s3(=ret(?))) == 0, and falls through when (s5(?) & s3(=ret(?))) != 0.
  The `beq` branch at 0x765c targets 0x76ec, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x7668 targets 0x75a4, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x7680 targets 0x7574, is taken when a1(?) != a5(=-0x1), and falls through when a1(?) == a5(=-0x1).
  The `beq` branch at 0x7690 targets 0x7584 and is always taken.
  The `beq` branch at 0x76b0 targets 0x7734, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x76dc targets 0x761c and is always taken.
  The `beq` branch at 0x76e4 targets 0x75a4 and is always taken.
  The `bne` branch at 0x7718 targets 0x7770, is taken when s7(=ret(xtalk_intr_alloc_nothd)) != 0, and falls through when s7(=ret(xtalk_intr_alloc_nothd)) == 0.
  The `bne` branch at 0x7724 targets 0x7668, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0x772c targets 0x79d8 and is always taken.
  The `beq` branch at 0x7740 targets 0x7864, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x7768 targets 0x761c and is always taken.
  The `beq` branch at 0x777c targets 0x78d0, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x77bc targets 0x7668 and is always taken.
  The `beq` branch at 0x77c8 targets 0x77e4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x77e4 targets 0x77f4, is taken when a4(=a1) == 0, and falls through when a4(=a1) != 0.
  The `beq` branch at 0x77ec targets 0x77f8 and is always taken.
  The `beq` branch at 0x7808 targets 0x7814, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x7874 targets 0x78a8, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x78a0 targets 0x761c and is always taken.
  The `bne` branch at 0x78b4 targets 0x7910, is taken when v0(=ret(compare_and_swap_ptr)) != 0, and falls through when v0(=ret(compare_and_swap_ptr)) == 0.
  The `beq` branch at 0x78c0 targets 0x7864 and is always taken.
  The `beq` branch at 0x78c8 targets 0x7830 and is always taken.
  The `beq` branch at 0x78dc targets 0x7664 and is always taken.
  The `beq` branch at 0x78e8 targets 0x743c and is always taken.
  The `beq` branch at 0x78f0 targets 0x744c and is always taken.
  The `beq` branch at 0x78f8 targets 0x745c and is always taken.
  The `beq` branch at 0x7900 targets 0x746c and is always taken.
  The `beq` branch at 0x7908 targets 0x747c and is always taken.
  The `beq` branch at 0x7924 targets 0x761c and is always taken.
  The `beq` branch at 0x7938 targets 0x7958, is taken when ra(=-0x1) == v0(=ret(device_desc_intr_target_get)), and falls through when ra(=-0x1) != v0(=ret(device_desc_intr_target_get)).
  The `beq` branch at 0x7950 targets 0x7960 and is always taken.
  The `beq` branch at 0x7968 targets 0x74e8 and is always taken.
  The `beq` branch at 0x7998 targets 0x7584 and is always taken.
  The `beq` branch at 0x79d0 targets 0x75a8 and is always taken.
  The `beq` branch at 0x79e4 targets 0x7830 and is always taken.
  The `beq` branch at 0x79f8 targets 0x7640 and is always taken.
  The return at 0x785c has v0 = one of ret(kmem_zalloc), 0x0.

- `pcibr_intr_setmustrun` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x7a00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x7a00-0x7a44 (68 bytes).
  It occupies 68 bytes.
  The `sh` at 0x7a24 stores 2 bytes to a0 (arg0 at entry) +0x50.
  The `jal` at 0x7a10 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7a20 calls setmustrun with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x7a30 calls splx with a0=(ret(splhi) << 0x0), a1=?, a2=?, a3=?.
  The return at 0x7a3c has v0 = ret(splx).

- `pcibr_intr_free` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x7a44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x7a44-0x7c3c (504 bytes).
  It occupies 504 bytes.
  The `lw` at 0x7a4c loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x7a54 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `sd` at 0x7a9c stores 8 bytes to ?.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x7ae0, `ld` at 0x7b14, `ld` at 0x7b2c.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x7b08, `lw` at 0x7b80.
  The `lw` at 0x7b20 loads 4 bytes from ?.
  The `lw` at 0x7b40 loads 4 bytes from a0 (arg0 at entry) +0x0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x28, including `lw` at 0x7b50, `lw` at 0x7bf0.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x7b64, `ld` at 0x7b8c.
  The `jal` at 0x7a90 calls xtalk_intr_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7aa4 calls pcireg_intr_device_bit_clr with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7af4 calls compare_and_swap_ptr with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x7b0c calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4504, a3=?.
  The `jal` at 0x7b70 calls xthread_set_func with a0=[a0+64]:8, a1=sym(xthread_exit), a2=0x0, a3=[a0+64]:8.
  The `jal` at 0x7b78 calls vsema with a0=a0+48, a1=?, a2=?, a3=?.
  The `jal` at 0x7b90 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4504, a3=[a0+64]:8.
  The `jal` at 0x7b9c calls kmem_free with a0=a0 at entry (arg0), a1=0xa0, a2=?, a3=?.
  The `jal` at 0x7be8 calls nano_delay with a0=sp-96, a1=?, a2=?, a3=?.
  The `jal` at 0x7c1c calls cmn_err with a0=0x4, a1=sym(.rodata)+4504, a2=[a0+64]:8, a3=[a0+64]:8.
  The `beq` branch at 0x7a88 targets 0x7c2c and is always taken.
  The `beq` branch at 0x7abc targets 0x7b40, is taken when s2(?) >= 0x8 (unsigned), and falls through when s2(?) < 0x8 (unsigned).
  The `beq` branch at 0x7acc targets 0x7aac, is taken when (s6(=[a0+88]) & a3(?)) == 0, and falls through when (s6(=[a0+88]) & a3(?)) != 0.
  The `beq` branch at 0x7ae4 targets 0x7b20, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x7afc targets 0x7b14, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `bne` branch at 0x7b18 targets 0x7af0, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `bne` branch at 0x7b24 targets 0x7aac, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `bne` branch at 0x7b30 targets 0x7a90, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x7b38 targets 0x7ab0 and is always taken.
  The `bne` branch at 0x7b48 targets 0x7b9c, is taken when (t9(=[a0]) & 0x2) != 0, and falls through when (t9(=[a0]) & 0x2) == 0.
  The `beq` branch at 0x7b58 targets 0x7bd4, is taken when (a1(=[a0+40]) & 0x400) == 0, and falls through when (a1(=[a0+40]) & 0x400) != 0.
  The `beq` branch at 0x7b60 targets 0x7c14, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x7bf8 targets 0x7b60, is taken when (a1(=[a0+40]) & 0x400) != 0, and falls through when (a1(=[a0+40]) & 0x400) == 0.
  The `bne` branch at 0x7c04 targets 0x7be0, is taken when s0(?) < 0x3e8 (signed), and falls through when s0(?) >= 0x3e8 (signed).
  The `beq` branch at 0x7c0c targets 0x7b60 and is always taken.
  The `beq` branch at 0x7c24 targets 0x7b9c and is always taken.
  The `beq` branch at 0x7c34 targets 0x7ac8 and is always taken.
  The return at 0x7bcc has v0 = ret(kmem_free).

- `pcibr_setpciint` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x7c3c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x7c3c-0x7ce4 (168 bytes).
  It occupies 168 bytes.
  2 such `lw` accesses load 4 bytes from ret(xtalk_intr_sfarg_get) +0x0, including `lw` at 0x7c80, `lw` at 0x7c90.
  The `jal` at 0x7c48 calls xtalk_intr_addr_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7c58 calls xtalk_intr_vector_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7c68 calls xtalk_intr_dev_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7c78 calls xtalk_intr_sfarg_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7c88 calls xtalk_intr_sfarg_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x7ca0 calls pcibr_bridge_ptr_get with a0=ret(xtalk_intr_dev_get), a1=?, a2=?, a3=?.
  The `jal` at 0x7cb8 calls pcireg_intr_addr_vect_set with a0=ret(pcibr_bridge_ptr_get), a1=?, a2=?, a3=?.
  The `jal` at 0x7ccc calls pcireg_intr_addr_addr_set with a0=ret(pcibr_bridge_ptr_get), a1=?, a2=ret(xtalk_intr_addr_get), a3=?.
  The return at 0x7cdc has v0 = ret(pcireg_intr_addr_addr_set).

- `pcibr_intr_connect` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x7ce4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x7ce4-0x7e88 (420 bytes).
  It occupies 420 bytes.
  The `lw` at 0x7cec loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x7cf4 loads 8 bytes from a0 (arg0 at entry) +0x60.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x7d24, `lw` at 0x7e64.
  The `sd` at 0x7d48 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `lw` at 0x7d4c loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0x7d54 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sw` at 0x7d60 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `lw` at 0x7d88 loads 4 bytes from ?.
  The `ld` at 0x7d90 loads 8 bytes from ?.
  The `lw` at 0x7e0c loads 4 bytes from [a0+96]:8 +0x48.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x7e30, `sw` at 0x7e44.
  The `jal` at 0x7d40 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4504, a3=a1 at entry (arg1), a4=a2 at entry (arg2).
  The `jal` at 0x7da4 calls mutex_spinlock with a0=[a0+96]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0x7dc0 calls pcireg_intr_enable_bit_set with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7dc8 calls pcireg_tflush_get with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7dd4 calls mutex_io_spinunlock with a0=[a0+96]:8+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x7e04 calls pcireg_intr_addr_addr with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7e34 calls xtalk_intr_connect with a0=?, a1=sym(pcibr_intr_func), a2=?, a3=sym(pcibr_setpciint), a5=0x0.
  The `jal` at 0x7e48 calls pcireg_intr_addr_get with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7e68 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4504, a3=ret(pcireg_intr_addr_addr), a4=ret(pcireg_intr_addr_get).
  The `bne` branch at 0x7d14 targets 0x7d24, is taken when a0 != 0, and falls through when a0 == 0.
  The `beq` branch at 0x7d1c targets 0x7de8 and is always taken.
  The `beq` branch at 0x7d74 targets 0x7d94, is taken when (s2(=[a0+88]) & a5(?)) == 0, and falls through when (s2(=[a0+88]) & a5(?)) != 0.
  The `beq` branch at 0x7d8c targets 0x7e00, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0x7d9c targets 0x7d64, is taken when s0(?) < 0x8 (unsigned), and falls through when s0(?) >= 0x8 (unsigned).
  The `bne` branch at 0x7e78 targets 0x7d68, is taken when s0(?) < 0x8 (unsigned), and falls through when s0(?) >= 0x8 (unsigned).
  The `beq` branch at 0x7e80 targets 0x7da4 and is always taken.
  The return at 0x7df8 has v0 = one of -0x1, 0x0.

- `pcibr_intr_disconnect` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x7e88 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x7e88-0x8064 (476 bytes).
  It occupies 476 bytes.
  The `sd` at 0x7e88 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0x7e8c stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `ld` at 0x7e98 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `lw` at 0x7ea0 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `lw` at 0x7eac loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sw` at 0x7ec4 stores 4 bytes to a0 (arg0 at entry) +0x0.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x7ef4, `lw` at 0x7f98, `lw` at 0x7ffc.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x7f64, `lw` at 0x7ff0, `lw` at 0x8040.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x7fdc, `ld` at 0x8014.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x7fec, `sw` at 0x8028.
  The `lw` at 0x8008 loads 4 bytes from [a0+96]:8 +0x48.
  The `jal` at 0x7f28 calls mutex_spinlock with a0=[a0+96]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0x7f3c calls pcireg_intr_enable_bit_clr with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7f44 calls pcireg_tflush_get with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7f50 calls mutex_io_spinunlock with a0=[a0+96]:8+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x7f68 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4504, a3=?.
  The `jal` at 0x7fd8 calls xtalk_intr_disconnect with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7ff4 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4504, a3=?.
  The `jal` at 0x802c calls xtalk_intr_connect with a0=?, a1=sym(pcibr_intr_func), a2=?, a3=sym(pcibr_setpciint), a5=0x0.
  The `jal` at 0x8044 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4504, a3=?.
  The `beq` branch at 0x7ee0 targets 0x7f04, is taken when (a6(?) & s0(?)) == 0, and falls through when (a6(?) & s0(?)) != 0.
  The `beq` branch at 0x7ef8 targets 0x7f08, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x7f0c targets 0x7ed0, is taken when v0(?) < 0x8 (unsigned), and falls through when v0(?) >= 0x8 (unsigned).
  The `beq` branch at 0x7f1c targets 0x7fb4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x7f84 targets 0x7fa4, is taken when (s0(?) & a2(?)) == 0, and falls through when (s0(?) & a2(?)) != 0.
  The `beq` branch at 0x7f9c targets 0x7fd8, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x7fac targets 0x7f78, is taken when s1(?) < 0x8 (unsigned), and falls through when s1(?) >= 0x8 (unsigned).
  The `beq` branch at 0x8000 targets 0x804c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x8054 targets 0x7f78, is taken when s1(?) < 0x8 (unsigned), and falls through when s1(?) >= 0x8 (unsigned).
  The `beq` branch at 0x805c targets 0x7fb8 and is always taken.
  The return at 0x7fd0 has v0 = one of ?, ret(pcibr_debug).

- `pcibr_intr_cpu_get` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x8064 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x8064-0x80dc (120 bytes).
  It occupies 120 bytes.
  The `lw` at 0x8068 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x80bc loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `ld` at 0x80d0 loads 8 bytes from ?.
  The `jal` at 0x80cc calls xtalk_intr_cpu_get with a0=?, a1=?, a2=?, a3=[a0+88], a4=0x1, a5=a0 at entry (arg0).
  The `bne` branch at 0x8084 targets 0x80b4, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0x8098 targets 0x8084, is taken when v0(?) < 0x8 (unsigned), and falls through when v0(?) >= 0x8 (unsigned).
  The `beq` branch at 0x80d4 targets 0x80a4 and is always taken.
  The return at 0x80ac has v0 = one of 0x0, ret(xtalk_intr_cpu_get).

- `pcibr_setwidint` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x80dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x80dc-0x8160 (132 bytes).
  It occupies 132 bytes.
  The `jal` at 0x80ec calls xtalk_intr_target_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x80fc calls xtalk_intr_addr_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8108 calls xtalk_intr_vector_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8114 calls xtalk_intr_sfarg_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8124 calls pcireg_intr_dst_target_id_set with a0=ret(xtalk_intr_sfarg_get), a1=?, a2=?, a3=?.
  The `jal` at 0x8134 calls pcireg_intr_dst_addr_set with a0=ret(xtalk_intr_sfarg_get), a1=ret(xtalk_intr_addr_get), a2=?, a3=?.
  The `jal` at 0x8148 calls pcireg_intr_host_err_set with a0=ret(xtalk_intr_sfarg_get), a1=?, a2=?, a3=?.
  The return at 0x8158 has v0 = ret(pcireg_intr_host_err_set).

- `pcibr_xintr_preset` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x8160 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x8160-0x8210 (176 bytes).
  It occupies 176 bytes.
  The `jal` at 0x8190 calls pcireg_intr_dst_target_id_set with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x819c calls pcireg_intr_dst_addr_set with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=?, a3=?.
  The `jal` at 0x81a8 calls pcireg_intr_host_err_set with a0=a0 at entry (arg0), a1=a4 at entry (arg4), a2=?, a3=?.
  The `jal` at 0x81b4 calls pcireg_intr_enable_bit_set with a0=a0 at entry (arg0), a1=-0x100, a2=?, a3=?.
  The `jal` at 0x81c4 calls pcireg_intr_addr_addr_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=a3 at entry (arg3).
  The `jal` at 0x81d4 calls pcireg_intr_addr_vect_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a4 at entry (arg4), a3=?.
  The `jal` at 0x81e4 calls pcireg_intr_enable_bit_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x81f8 calls pcireg_tflush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0x8188 targets 0x81c4, is taken when a1 != at(=-0x1), and falls through when a1 == at(=-0x1).
  The `beq` branch at 0x81bc targets 0x81ec and is always taken.
  The return at 0x8208 has v0 = ret(pcireg_tflush_get).

- `pcibr_intr_func` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x8210 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x8210-0x845c (588 bytes).
  It occupies 588 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x8210, `lw` at 0x838c.
  The `ld` at 0x8228 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x8230 loads 2 bytes from [a0]:8 +0x72.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0x8250, `lw` at 0x8378, `lw` at 0x8448.
  The `ld` at 0x828c loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x829c loads 8 bytes from [a0+16]:8 +0x8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1c, including `lw` at 0x82b8, `lw` at 0x8324.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x82c4, `lbu` at 0x8330.
  6 such `ld` accesses load 8 bytes from ?, including `ld` at 0x82cc, `ld` at 0x82d0, `ld` at 0x82d8.
  The `lw` at 0x82f8 loads 4 bytes from ?.
  The `ll` at 0x8348 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `sc` at 0x8354 stores 4 bytes to a0 (arg0 at entry) +0x18.
  The `lw` at 0x83f0 loads 4 bytes from [a0]:8 +0x78.
  The `jal` at 0x82c8 calls pcireg_wrb_flush_get with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0x82d4 calls (unknown callee) with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x8334 calls pcireg_wrb_flush_get with a0=?, a1=?, a2=a0+24, a3=?.
  The `jal` at 0x8360 calls pcibr_wrap_put with a0=a0 at entry (arg0), a1=?, a2=a0+24, a3=0x1, a4=[a0+24]+1.
  The `jal` at 0x8368 calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x8394 calls mutex_spinlock with a0=[a0]:8+128, a1=?, a2=?, a3=?.
  The `jal` at 0x83a4 calls pcireg_intr_enable_bit_clr with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x83ac calls pcireg_tflush_get with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x83b8 calls mutex_io_spinunlock with a0=[a0]:8+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x8410 calls mutex_spinlock with a0=[a0]:8+128, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8424 calls pcireg_intr_enable_bit_clr with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x8430 calls pcireg_intr_enable_bit_set with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x843c calls mutex_io_spinunlock with a0=[a0]:8+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x844c calls pcibr_force_interrupt with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=[a0+24].
  The `beq` branch at 0x8248 targets 0x83f0, is taken when at(=[[a0]:8+114]:2) == v1(=0x2), and falls through when at(=[[a0]:8+114]:2) != v1(=0x2).
  The `bne` branch at 0x8268 targets 0x83c0, is taken when a0(=[a0+24]) != 0, and falls through when a0(=[a0+24]) == 0.
  The `beq` branch at 0x8274 targets 0x828c and is always taken.
  The `beq` branch at 0x827c targets 0x8378, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x8284 targets 0x8384, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x8290 targets 0x827c, is taken when s0(=[a0+16]:8) == 0, and falls through when s0(=[a0+16]:8) != 0.
  The `beq` branch at 0x8298 targets 0x82f0 and is always taken.
  The `bne` branch at 0x82a0 targets 0x831c, is taken when s3(=one of 0x0, 0x1) != 0, and falls through when s3(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x82a8 targets 0x82e0, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x82b0 targets 0x82e0, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x82bc targets 0x82d0, is taken when a1(=[a0+28]) == 0, and falls through when a1(=[a0+28]) != 0.
  The `beq` branch at 0x82e4 targets 0x827c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x82f0 targets 0x82e0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x8304 targets 0x82e0, is taken when (v0(?) & 0x1) == 0, and falls through when (v0(?) & 0x1) != 0.
  The `bne` branch at 0x830c targets 0x82a0, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x8314 targets 0x82a8, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x831c targets 0x82a8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x8328 targets 0x8340, is taken when v1(=[a0+28]) == 0, and falls through when v1(=[a0+28]) != 0.
  The `beql` branch at 0x8358 targets 0x8348, is taken when a4(=[a0+24]+1) == 0, and falls through when a4(=[a0+24]+1) != 0; its branch-likely delay slot `nop` at 0x835c runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x8370 targets 0x82e0 and is always taken.
  The `beq` branch at 0x837c targets 0x844c, is taken when a5(=[a0+24]) == 0, and falls through when a5(=[a0+24]) != 0.
  The `beq` branch at 0x8384 targets 0x83c0, is taken when s6(=one of 0x0, 0x1) == 0, and falls through when s6(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x8400 targets 0x8250, is taken when (t8(?) & 0x2) == 0, and falls through when (t8(?) & 0x2) != 0.
  The `beq` branch at 0x8444 targets 0x8254 and is always taken.
  The `beq` branch at 0x8454 targets 0x8384 and is always taken.
  The return at 0x83e8 has v0 = one of a0+24, ?, ret(mutex_io_spinunlock).

- `print_bridge_errcmd` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x845c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x845c-0x848c (48 bytes).
  It occupies 48 bytes.
  The `jal` at 0x8478 calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=a1 at entry (arg1), a3=a0 at entry (arg0), a4=sym(.data)+16.
  The return at 0x8484 has v0 = ret(cmn_err).

- `pcibr_errintr_group` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x94e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x94e8-0x956c (132 bytes).
  It occupies 132 bytes.
  The `beq` branch at 0x9504 targets 0x9514, is taken when (a0 & a1(=0x40010000)) == 0, and falls through when (a0 & a1(=0x40010000)) != 0.
  The `beq` branch at 0x952c targets 0x9538, is taken when (a3(=a0) & v1(=0x3e0000)) == 0, and falls through when (a3(=a0) & v1(=0x3e0000)) != 0.
  The `beq` branch at 0x9538 targets 0x9544, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x954c targets 0x9558, is taken when (a3(=a0) & a0(=0x14000200)) == 0, and falls through when (a3(=a0) & a0(=0x14000200)) != 0.
  The `beq` branch at 0x9558 targets 0x9564, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0x9564 has v0 = ?.

- `pcibr_pioerr_check` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x956c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x956c-0x96d4 (360 bytes).
  It occupies 360 bytes.
  The `lbu` at 0x9598 loads 1 byte from a0 (arg0 at entry) +0x39.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x95cc, `lw` at 0x95f8.
  11 such `ld` accesses load 8 bytes from ?, including `ld` at 0x95e0, `ld` at 0x95ec, `ld` at 0x9604.
  The `ll` at 0x9658 loads 4 bytes from ?.
  The `sc` at 0x9664 stores 4 bytes to ?.
  The `jal` at 0x9578 calls pcireg_intr_status_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x9590 calls pcireg_pci_bus_addr_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x9588 targets 0x96c0, is taken when (v0(=ret(pcireg_intr_status_get)) & at(=0x4400008800)) == 0, and falls through when (v0(=ret(pcireg_intr_status_get)) & at(=0x4400008800)) != 0.
  The `blez` branch at 0x95a8 targets 0x96c0, is taken when at(?) <= 0 (signed), and falls through when at(?) > 0 (signed).
  The `beq` branch at 0x95b0 targets 0x95bc and is always taken.
  The `blez` branch at 0x95b8 targets 0x96c0, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `blez` branch at 0x95dc targets 0x95b8, is taken when t8(?) <= 0 (signed), and falls through when t8(?) > 0 (signed).
  The `beq` branch at 0x95e4 targets 0x9684 and is always taken.
  The `beq` branch at 0x95f0 targets 0x967c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x9608 targets 0x96ac, is taken when a6(?) >= 0x6 (unsigned), and falls through when a6(?) < 0x6 (unsigned).
  The `bne` branch at 0x9638 targets 0x95ec, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x964c targets 0x95ec, is taken when v0(=ret(pcireg_pci_bus_addr_get)) >= a2(?) (unsigned), and falls through when v0(=ret(pcireg_pci_bus_addr_get)) < a2(?) (unsigned).
  The `beql` branch at 0x9668 targets 0x9658, is taken when at(?) == 0, and falls through when at(?) != 0; its branch-likely delay slot `nop` at 0x966c runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x9674 targets 0x95f8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x967c targets 0x95b8, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x9690 targets 0x967c, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `bne` branch at 0x969c targets 0x95f8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x96a4 targets 0x967c and is always taken.
  The `bne` branch at 0x96ac targets 0x9638, is taken when a5(?) != t3(=0x1), and falls through when a5(?) == t3(=0x1).
  The `beq` branch at 0x96b8 targets 0x9634 and is always taken.
  The return at 0x96cc has v0 = one of ret(pcireg_intr_status_get), ret(pcireg_pci_bus_addr_get).

- `pcibr_error_intr_handler` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x96d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x96d4-0x9c38 (1380 bytes).
  It occupies 1380 bytes.
  The `lw` at 0x96ec loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lbu` at 0x9718 loads 1 byte from a0 (arg0 at entry) +0x28.
  8 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0x979c, `lh` at 0x9830, `lh` at 0x9948.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x97d4, `lw` at 0x97d8, `lw` at 0x97dc.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0x97e4, `sw` at 0x9884, `sw` at 0x988c.
  The `lw` at 0x97e8 loads 4 bytes from a0 (arg0 at entry) +0x48.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x9898, `lw` at 0x99a4, `lw` at 0x9a6c.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x9b00, `ld` at 0x9b7c, `ld` at 0x9bb4.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x9b0c, `ld` at 0x9b88, `ld` at 0x9bbc.
  The `jal` at 0x96e4 calls pcireg_intr_status_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x9708 calls pcibr_debug with a0=0x100, a1=[a0], a2=sym(.rodata)+6040, a3=ret(pcireg_intr_status_get).
  The `jal` at 0x975c calls pcibr_pioerr_check [0x956c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x98d0 calls mutex_spinlock with a0=a0+128, a1=0x1, a2=sym(.data)+16, a3=0x2.
  The `jal` at 0x98e0 calls pcireg_intr_enable_bit_clr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x98ec calls mutex_io_spinunlock with a0=a0+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x9908 calls pcireg_bus_err_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x2.
  The `jal` at 0x997c calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=(ret(pcireg_intr_status_get) | 0x40), a2=?, a3=?, a7=0x1.
  The `jal` at 0x99c4 calls pcireg_arbitration_bit_set with a0=a0 at entry (arg0), a1=0xf00000, a2=[a0+114]:2, a3=0x2.
  The `jal` at 0x99d0 calls test_and_set_long with a0=a0+2112, a1=0x0, a2=?, a3=?.
  The `jal` at 0x9a1c calls pcibr_errintr_group with a0=(ret(pcireg_intr_status_get) << 0x0), a1=?, a2=?, a3=?, a7=0x1.
  The `jal` at 0x9a2c calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9a44 calls pcireg_intr_enable_bit_clr with a0=a0 at entry (arg0), a1=0x80, a2=?, a3=[a0+40]:1, a4=0xf.
  The `jal` at 0x9a4c calls powerfail with a0=0x0, a1=?, a2=?, a3=?.
  The `jal` at 0x9aac calls pcireg_cmdword_err_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x2.
  The `jal` at 0x9b10 calls cmn_err with a0=0x5, a1=sym(.rodata)+6040, a2=[a0+16]:8, a3=?.
  The `jal` at 0x9b44 calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=?, a3=0x2.
  The `jal` at 0x9b4c calls pcibr_error_dump with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9b5c calls machine_error_dump with a0=sym(.rodata)+6040, a1=?, a2=?, a3=?.
  The `jal` at 0x9b68 calls panic with a0=sym(.rodata)+6040, a1=?, a2=?, a3=?.
  The `jal` at 0x9b8c calls cmn_err with a0=0x5, a1=sym(.rodata)+6040, a2=[a0+16]:8, a3=?.
  The `jal` at 0x9bc8 calls cmn_err with a0=0x4, a1=sym(.rodata)+6040, a2=[a0+16]:8, a3=?.
  The `jal` at 0x9bf4 calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=?, a3=0x2, a5=[a0+114]:2, a6=0x22133fc06000.
  The `jal` at 0x9bfc calls pcibr_error_dump with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9c08 calls machine_error_dump with a0=sym(.rodata)+6040, a1=?, a2=?, a3=?.
  The `jal` at 0x9c14 calls panic with a0=sym(.rodata)+6040, a1=?, a2=?, a3=?.
  The `beq` branch at 0x9738 targets 0x9a3c, is taken when a3(=[a0+40]:1) == a4(=0xf), and falls through when a3(=[a0+40]:1) != a4(=0xf).
  The `beq` branch at 0x9748 targets 0x99d8, is taken when (s1(=ret(pcireg_intr_status_get)) & t8(=-0x100)) == 0, and falls through when (s1(=ret(pcireg_intr_status_get)) & t8(=-0x100)) != 0.
  The `beq` branch at 0x9754 targets 0x9764, is taken when (v0(=0x4400008800) & s1(=ret(pcireg_intr_status_get))) == 0, and falls through when (v0(=0x4400008800) & s1(=ret(pcireg_intr_status_get))) != 0.
  The `beq` branch at 0x9764 targets 0x9aec, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0x9794 targets 0x9c24 and is always taken.
  The `beq` branch at 0x97a0 targets 0x9890, is taken when t3(=[a0+114]:2) == a3(=0x2), and falls through when t3(=[a0+114]:2) != a3(=0x2).
  The `beq` branch at 0x97bc targets 0x98c0, is taken when s0(?) >= 0x40 (signed), and falls through when s0(?) < 0x40 (signed).
  The `beq` branch at 0x97cc targets 0x97a8, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x97f8 targets 0x9840, is taken when t8(=[a0+72]) == 0, and falls through when t8(=[a0+72]) != 0.
  The `beq` branch at 0x9800 targets 0x979c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x9824 targets 0x979c, is taken when s1(?) < 0x65 (unsigned), and falls through when s1(?) >= 0x65 (unsigned).
  The `bnel` branch at 0x982c targets 0x97a0, is taken when a0(?) != 0, and falls through when a0(?) == 0; its branch-likely delay slot `lh t3,114(s3)` at 0x9830 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x9838 targets 0x9afc and is always taken.
  The `beq` branch at 0x9840 targets 0x9a08, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x9850 targets 0x981c, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x985c targets 0x9820, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x9864 targets 0x9820, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `bne` branch at 0x987c targets 0x9bb4, is taken when t8(=[sym(.sbss)]) < a4(?) (unsigned), and falls through when t8(=[sym(.sbss)]) >= a4(?) (unsigned).
  The `beq` branch at 0x9888 targets 0x9820 and is always taken.
  The `bne` branch at 0x9890 targets 0x97a8, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0x98a8 targets 0x97a8, is taken when (t9(?) & 0x2) == 0, and falls through when (t9(?) & 0x2) != 0.
  The `bnel` branch at 0x98b0 targets 0x97ac, is taken when a0(?) != 0, and falls through when a0(?) == 0; its branch-likely delay slot `addiu s0,s0,1` at 0x98b4 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x98b8 targets 0x9b78 and is always taken.
  The `beq` branch at 0x98c4 targets 0x98fc, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `bgez` branch at 0x9900 targets 0x9924, is taken when at(=(ret(pcireg_intr_status_get) << 0x27)) >= 0 (signed), and falls through when at(=(ret(pcireg_intr_status_get) << 0x27)) < 0 (signed).
  The `beq` branch at 0x991c targets 0x9aac, is taken when v0(?) == v1(=0xc00000), and falls through when v0(?) != v1(=0xc00000).
  The `beq` branch at 0x9928 targets 0x9a5c, is taken when a1(=[sym(pcibr_pioerr_dump)]) == 0, and falls through when a1(=[sym(pcibr_pioerr_dump)]) != 0.
  The `bne` branch at 0x9940 targets 0x9b3c, is taken when (s4(?) & a0(?)) != 0, and falls through when (s4(?) & a0(?)) == 0.
  The `beq` branch at 0x994c targets 0x9a6c, is taken when a5(=[a0+114]:2) == a3(=0x2), and falls through when a5(=[a0+114]:2) != a3(=0x2).
  The `bne` branch at 0x9958 targets 0x9b5c, is taken when (s4(?) & a6(=0x22133fc06000)) != 0, and falls through when (s4(?) & a6(=0x22133fc06000)) == 0.
  The `beq` branch at 0x9964 targets 0x9a18, is taken when a0(=[a0+114]:2) == 0, and falls through when a0(=[a0+114]:2) != 0.
  The `beq` branch at 0x996c targets 0x9a1c, is taken when a0(=[a0+114]:2) == a7(=0x1), and falls through when a0(=[a0+114]:2) != a7(=0x1).
  The `bne` branch at 0x998c targets 0x99cc, is taken when a2(=[a0+114]:2) != a3(=0x2), and falls through when a2(=[a0+114]:2) == a3(=0x2).
  The `beq` branch at 0x999c targets 0x99d0, is taken when (s4(?) & a4(=0x10000000000)) == 0, and falls through when (s4(?) & a4(=0x10000000000)) != 0.
  The `beq` branch at 0x99b8 targets 0x99d0, is taken when (a5(?) & 0x2) == 0, and falls through when (a5(?) & 0x2) != 0.
  The `bne` branch at 0x9a08 targets 0x9a9c, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0x9a10 targets 0x97a0 and is always taken.
  The `beq` branch at 0x9a34 targets 0x9984 and is always taken.
  The `beq` branch at 0x9a3c targets 0x9740, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x9a54 targets 0x9744 and is always taken.
  The `beq` branch at 0x9a64 targets 0x993c and is always taken.
  The `beq` branch at 0x9a84 targets 0x9950, is taken when (a1(?) & 0x6) == 0, and falls through when (a1(?) & 0x6) != 0.
  The `beq` branch at 0x9a8c targets 0x9954, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x9a94 targets 0x9bec and is always taken.
  The `beq` branch at 0x9a9c targets 0x9ae0, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x9aa4 targets 0x97a0 and is always taken.
  The `bne` branch at 0x9ad0 targets 0x9924, is taken when a1(?) != a2(=0x402000), and falls through when a1(?) == a2(=0x402000).
  The `beq` branch at 0x9ad8 targets 0x9924 and is always taken.
  The `beq` branch at 0x9ae4 targets 0x979c and is always taken.
  The `beq` branch at 0x9af4 targets 0x98f8 and is always taken.
  The `beq` branch at 0x9b34 targets 0x979c and is always taken.
  The `beq` branch at 0x9b54 targets 0x9948 and is always taken.
  The `beq` branch at 0x9b70 targets 0x9964 and is always taken.
  The `beq` branch at 0x9bac targets 0x97a8 and is always taken.
  The `beq` branch at 0x9be4 targets 0x9884 and is always taken.
  The `beq` branch at 0x9c1c targets 0x9954 and is always taken.
  The `beq` branch at 0x9c30 targets 0x97c8 and is always taken.
  The return at 0x9a00 has v0 = one of 0x4400008800, ret(test_and_set_long).

- `pcibr_addr_toslot` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x9c38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x9c38-0x9f1c (740 bytes).
  It occupies 740 bytes.
  The `lbu` at 0x9c74 loads 1 byte from a0 (arg0 at entry) +0x38.
  The `lbu` at 0x9c78 loads 1 byte from a0 (arg0 at entry) +0x39.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x9c9c, `lw` at 0x9cf4, `lw` at 0x9df4.
  13 such `ld` accesses load 8 bytes from ?, including `ld` at 0x9cac, `ld` at 0x9cc4, `ld` at 0x9d00.
  4 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0x9d30, `sw` at 0x9db0, `sw` at 0x9e78.
  2 such `sb` accesses store 1 byte to a4 (arg4 at entry) +0x0, including `sb` at 0x9d3c, `sb` at 0x9dbc.
  4 such `sd` accesses store 8 bytes to a3 (arg3 at entry) +0x0, including `sd` at 0x9d54, `sd` at 0x9d94, `sd` at 0x9e94.
  The `bne` branch at 0x9c40 targets 0x9c74, is taken when a1 < v0(=0x20000) (unsigned), and falls through when a1 >= v0(=0x20000) (unsigned).
  The `beq` branch at 0x9c50 targets 0x9c74, is taken when a1 >= v1(=0x30000) (unsigned), and falls through when a1 < v1(=0x30000) (unsigned).
  The `bne` branch at 0x9c60 targets 0x9d60, is taken when a1 < a0(=0x28000) (unsigned), and falls through when a1 >= a0(=0x28000) (unsigned).
  The `beq` branch at 0x9c6c targets 0x9d68 and is always taken.
  The `bne` branch at 0x9c8c targets 0x9de0, is taken when a6(=[a0+57]:1) < v0(=[a0+56]:1) (signed), and falls through when a6(=[a0+57]:1) >= v0(=[a0+56]:1) (signed).
  The `blez` branch at 0x9ca0 targets 0x9dc8, is taken when t9(?) <= 0 (signed), and falls through when t9(?) > 0 (signed).
  The `beq` branch at 0x9ca8 targets 0x9f0c and is always taken.
  The `beq` branch at 0x9cbc targets 0x9dc8, is taken when t3(?) >= t9(?) (signed), and falls through when t3(?) < t9(?) (signed).
  The `beq` branch at 0x9cc8 targets 0x9cb0, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x9cd0 targets 0x9f00 and is always taken.
  The `beq` branch at 0x9ce4 targets 0x9cb0, is taken when a7(?) >= 0x6 (signed), and falls through when a7(?) < 0x6 (signed).
  The `beq` branch at 0x9cf8 targets 0x9cd8, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `bne` branch at 0x9d08 targets 0x9cd8, is taken when a1 < t1(?) (unsigned), and falls through when a1 >= t1(?) (unsigned).
  The `beql` branch at 0x9d1c targets 0x9cdc, is taken when a1 >= v1(?) (unsigned), and falls through when a1 < v1(?) (unsigned); its branch-likely delay slot `addiu a7,a7,1` at 0x9d20 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x9d24 targets 0x9d48, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x9d2c targets 0x9d4c, is taken when a3 != 0, and falls through when a3 == 0.
  The `beq` branch at 0x9d34 targets 0x9d40, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0x9d48 targets 0x9d34, is taken when a3 == 0, and falls through when a3 != 0.
  The `bne` branch at 0x9d50 targets 0x9d3c, is taken when a4 != 0, and falls through when a4 == 0.
  The `beq` branch at 0x9d58 targets 0x9d40 and is always taken.
  The `beq` branch at 0x9d70 targets 0x9da0, is taken when a4 == 0, and falls through when a4 != 0.
  The `bne` branch at 0x9d80 targets 0x9da8, is taken when a2 != 0, and falls through when a2 == 0.
  The `beq` branch at 0x9d88 targets 0x9db4, is taken when a3 == 0, and falls through when a3 != 0.
  The `bne` branch at 0x9d90 targets 0x9dbc, is taken when a4 != 0, and falls through when a4 == 0.
  The `beq` branch at 0x9d98 targets 0x9d40 and is always taken.
  The `beq` branch at 0x9da0 targets 0x9d88, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x9dac targets 0x9d90, is taken when a3 != 0, and falls through when a3 == 0.
  The `beq` branch at 0x9db4 targets 0x9d40, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0x9dc0 targets 0x9d40 and is always taken.
  The `beq` branch at 0x9dd8 targets 0x9c9c, is taken when t9(=[a0+57]:1) >= v0(?) (signed), and falls through when t9(=[a0+57]:1) < v0(?) (signed).
  The `beq` branch at 0x9de4 targets 0x9eb8, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `blez` branch at 0x9df8 targets 0x9ea0, is taken when t1(?) <= 0 (signed), and falls through when t1(?) > 0 (signed).
  The `beq` branch at 0x9e00 targets 0x9e0c and is always taken.
  The `beq` branch at 0x9e08 targets 0x9ea0, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x9e1c targets 0x9e08, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x9e28 targets 0x9e08, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x9e30 targets 0x9e48 and is always taken.
  The `beq` branch at 0x9e3c targets 0x9e08, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x9e4c targets 0x9e38, is taken when a1 < a7(?) (unsigned), and falls through when a1 >= a7(?) (unsigned).
  The `beq` branch at 0x9e60 targets 0x9e38, is taken when a1 >= t9(?) (unsigned), and falls through when a1 < t9(?) (unsigned).
  The `beq` branch at 0x9e68 targets 0x9e84, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0x9e74 targets 0x9e8c, is taken when a3 != 0, and falls through when a3 == 0.
  The `beq` branch at 0x9e7c targets 0x9d40 and is always taken.
  The `beq` branch at 0x9e84 targets 0x9d40, is taken when a3 == 0, and falls through when a3 != 0.
  The `beq` branch at 0x9e98 targets 0x9d40 and is always taken.
  The `beq` branch at 0x9eb0 targets 0x9df4, is taken when a4(=[a0+57]:1) >= v0(?) (signed), and falls through when a4(=[a0+57]:1) < v0(?) (signed).
  The `beq` branch at 0x9eb8 targets 0x9eec, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0x9ec4 targets 0x9ed4, is taken when a1 >= a5(=0x40000000) (unsigned), and falls through when a1 < a5(=0x40000000) (unsigned).
  The `beq` branch at 0x9ecc targets 0x9ee8 and is always taken.
  The `beq` branch at 0x9eec targets 0x9ef8, is taken when a3 == 0, and falls through when a3 != 0.
  The `beq` branch at 0x9ef8 targets 0x9d40 and is always taken.
  The `beq` branch at 0x9f04 targets 0x9cf0 and is always taken.
  The `beq` branch at 0x9f14 targets 0x9cc8 and is always taken.
  The return at 0x9d40 has v0 = one of ?, 0xff.

- `pcibr_error_cleanup` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x9f1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x9f1c-0x9f70 (84 bytes).
  It occupies 84 bytes.
  The `lh` at 0x9f1c loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `jal` at 0x9f44 calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=one of 0x41, 0x3cff00000041, a2=a2 at entry (arg2), a3=0x1, a4=[a0+114]:2.
  The `jal` at 0x9f4c calls pcireg_tflush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x9f34 targets 0x9f44, is taken when a4(=[a0+114]:2) == 0, and falls through when a4(=[a0+114]:2) != 0.
  The `beq` branch at 0x9f3c targets 0x9f64, is taken when a4(=[a0+114]:2) == a3(=0x1), and falls through when a4(=[a0+114]:2) != a3(=0x1).
  The `beq` branch at 0x9f68 targets 0x9f44 and is always taken.
  The return at 0x9f5c has v0 = ret(pcireg_tflush_get).

- `pcibr_error_extract` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x9f70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x9f70-0x9fe8 (120 bytes).
  It occupies 120 bytes.
  The `jal` at 0x9f8c calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+6040, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x9fa8 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9fbc calls pcireg_pci_bus_addr_get with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?, a5=0xff.
  The `jal` at 0x9fd4 calls pcibr_addr_toslot with a0=?, a1=ret(pcireg_pci_bus_addr_get), a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `beq` branch at 0x9f94 targets 0x9fa8, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0x9fb4 targets 0x9fe0, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x9fe0 targets 0x9f9c and is always taken.
  The return at 0x9fa0 has v0 = one of 0xff, ?.

- `pcibr_device_disable` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x9fe8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x9fe8-0x9ff0 (8 bytes).
  It occupies 8 bytes.
  The return at 0x9fe8 has v0 = ?.

- `pcibr_pioerror` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0x9ff0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0x9ff0-0xad38 (3400 bytes).
  It occupies 3400 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0xa008, `lw` at 0xa4dc.
  The `lw` at 0xa010 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `ld` at 0xa02c loads 8 bytes from a3 (arg3 at entry) +0x18.
  4 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0xa060, `lh` at 0xa500, `lh` at 0xa5b8.
  The `lw` at 0xa068 loads 4 bytes from a0 (arg0 at entry) +0x48.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa1b4, `lw` at 0xa398, `lw` at 0xa440.
  21 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa1c0, `ld` at 0xa3a4, `ld` at 0xa3d8.
  12 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x39, including `lbu` at 0xa244, `lbu` at 0xa2c4, `lbu` at 0xa314.
  10 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x38, including `lbu` at 0xa248, `lbu` at 0xa2cc, `lbu` at 0xa318.
  The `ll` at 0xa3f0 loads 4 bytes from ?.
  The `sc` at 0xa3fc stores 4 bytes to ?.
  5 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0xa4fc, `lw` at 0xa59c, `lw` at 0xaaf0.
  3 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0xa524, `sw` at 0xa550, `sw` at 0xa704.
  2 such `sh` accesses store 2 bytes to a3 (arg3 at entry) +0x8, including `sh` at 0xa534, `sh` at 0xa714.
  The `sd` at 0xa538 stores 8 bytes to a3 (arg3 at entry) +0x28.
  The `sd` at 0xa540 stores 8 bytes to a3 (arg3 at entry) +0x20.
  5 such `lh` accesses load 2 bytes from a3 (arg3 at entry) +0x8, including `lh` at 0xa598, `lh` at 0xab78, `lh` at 0xac24.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0xaac4, `ld` at 0xaae4.
  The `lw` at 0xac38 loads 4 bytes from a3 (arg3 at entry) +0x24.
  4 such `ld` accesses load 8 bytes from a3 (arg3 at entry) +0x28, including `ld` at 0xac8c, `ld` at 0xacc4, `ld` at 0xacec.
  The `lw` at 0xad34 loads 4 bytes from (a0 + ([a0+56]:1 << 0x7)) +0x110.
  The `jal` at 0xa044 calls pcibr_debug with a0=0x200, a1=[a0], a2=sym(.rodata)+6040, a3=a0 at entry (arg0), a4=[a3+24]:8.
  The `jal` at 0xa4e0 calls pcibr_debug with a0=0x200, a1=[a0], a2=sym(.rodata)+6040, a3=?.
  The `jal` at 0xa570 calls pciio_error_handler with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8b4 calls pcibr_error_cleanup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa8d4 calls pciio_error_handler with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa8e8 calls pcibr_device_disable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=([a3] << 0x2).
  The `jal` at 0xa8f8 calls pcibr_error_cleanup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xaad0 calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=[a0+16]:8, a3=[a3+24]:8.
  The `jal` at 0xaae8 calls cmn_err with a0=0x1, a1=sym(.rodata)+6040, a2=[a0+16]:8, a3=?.
  The `jal` at 0xab10 calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=sym(.rodata)+6040, a3=?.
  The `jal` at 0xab18 calls pcireg_intr_status_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xab30 calls pcibr_error_dump with a0=a0 at entry (arg0), a1=sym(.rodata)+6040, a2=?, a3=?.
  The `jal` at 0xab54 calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=sym(.rodata)+6040, a3=?.
  The `jal` at 0xab6c calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=sym(.rodata)+6040, a3=?.
  The `jal` at 0xabc0 calls pcireg_device_get with a0=a0 at entry (arg0), a1=?, a2=[a3+8]:2, a3=?, a4=([a3] << 0x2).
  The `jal` at 0xabdc calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=sym(.rodata)+6040, a3=?.
  The `jal` at 0xabf8 calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=sym(.rodata)+6040, a3=?.
  The `jal` at 0xac18 calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=sym(.rodata)+6040, a3=ret(pcireg_device_get), a4=sym(.data)+16.
  The `jal` at 0xac90 calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=?, a3=?, a4=[a3+36]-8, a5=[a3+40]:8, a6=0x4, a7=0x5.
  The `jal` at 0xacc8 calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=[a3+40]:8, a3=?, a5=0x7, a6=0x4, a7=0x5.
  The `jal` at 0xacf0 calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=?, a3=?, a4=[a3+40]:8, a5=0x7.
  The `jal` at 0xad0c calls cmn_err with a0=0x6, a1=sym(.rodata)+6040, a2=[a3+40]:8, a3=?, a5=0x7, a6=0x4.
  The `beq` branch at 0xa078 targets 0xa650, is taken when t1(=[a0+114]:2) == a6(=0x2), and falls through when t1(=[a0+114]:2) != a6(=0x2).
  The `bne` branch at 0xa0a8 targets 0xa0f8, is taken when s2(=[a3+24]:8) < t3(=one of 0x20000, 0x21000, 0x820000, 0x821000) (unsigned), and falls through when s2(=[a3+24]:8) >= t3(=one of 0x20000, 0x21000, 0x820000, 0x821000) (unsigned).
  The `beq` branch at 0xa0b0 targets 0xa0e0, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0xa0b8 targets 0xa908, is taken when t1(=[a0+114]:2) == a6(=0x2), and falls through when t1(=[a0+114]:2) != a6(=0x2).
  The `beq` branch at 0xa0d8 targets 0xa0e8 and is always taken.
  The `bne` branch at 0xa0e8 targets 0xa110, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `beq` branch at 0xa0f0 targets 0xa138 and is always taken.
  The `bne` branch at 0xa0f8 targets 0xa718, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0xa124 targets 0xa138, is taken when s2(=[a3+24]:8) >= a2(=one of 0x29000, 0x829000) (unsigned), and falls through when s2(=[a3+24]:8) < a2(=one of 0x29000, 0x829000) (unsigned).
  The `bne` branch at 0xa144 targets 0xa1c8, is taken when s2(=[a3+24]:8) < t3(=one of 0x200000, 0xa00000) (unsigned), and falls through when s2(=[a3+24]:8) >= t3(=one of 0x200000, 0xa00000) (unsigned).
  The `beq` branch at 0xa158 targets 0xa1c8, is taken when s2(=[a3+24]:8) >= t2(=one of 0xc00000, 0x1400000) (unsigned), and falls through when s2(=[a3+24]:8) < t2(=one of 0xc00000, 0x1400000) (unsigned).
  The `beq` branch at 0xa17c targets 0xa724, is taken when v0(?) == ra(=0x1), and falls through when v0(?) != ra(=0x1).
  The `beq` branch at 0xa188 targets 0xa724, is taken when v0(?) == v1(=0x3), and falls through when v0(?) != v1(=0x3).
  The `blez` branch at 0xa190 targets 0xa1a0, is taken when t8(?) <= 0 (signed), and falls through when t8(?) > 0 (signed).
  The `bne` branch at 0xa1a0 targets 0xa1b0, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0xa1b8 targets 0xa914, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa1c8 targets 0xa668, is taken when t1(=[a0+114]:2) == a6(=0x2), and falls through when t1(=[a0+114]:2) != a6(=0x2).
  The `bne` branch at 0xa1d4 targets 0xa268, is taken when s2(=[a3+24]:8) < t8(=0x40000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t8(=0x40000000) (unsigned).
  The `bne` branch at 0xa1e8 targets 0xa268, is taken when t9(=0x7fffffff) < s2(=[a3+24]:8) (unsigned), and falls through when t9(=0x7fffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa204 targets 0xa218, is taken when s2(=[a3+24]:8) < ra(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= ra(=0x80000000) (unsigned).
  The `beq` branch at 0xa214 targets 0xa284, is taken when at(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when at(=0xbfffffff) < s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa224 targets 0xa23c, is taken when s2(=[a3+24]:8) < v0(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= v0(=0x100000000) (unsigned).
  The `beq` branch at 0xa234 targets 0xa304, is taken when v1(=0x1ffffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when v1(=0x1ffffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa23c targets 0xa9d0, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa25c targets 0xa354 and is always taken.
  The `bne` branch at 0xa270 targets 0xa2dc, is taken when s2(=[a3+24]:8) < a4(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= a4(=0x80000000) (unsigned).
  The `bne` branch at 0xa27c targets 0xa2e0, is taken when a7(=0xbfffffff) < s2(=[a3+24]:8) (unsigned), and falls through when a7(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa298 targets 0xa2b4, is taken when s2(=[a3+24]:8) < t0(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t0(=0x100000000) (unsigned).
  The `beq` branch at 0xa2ac targets 0xa304, is taken when t1(=0x1ffffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when t1(=0x1ffffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa2b4 targets 0xa950, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa2d4 targets 0xa354 and is always taken.
  The `bne` branch at 0xa2e8 targets 0xa338, is taken when s2(=[a3+24]:8) < t3(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t3(=0x100000000) (unsigned).
  The `bne` branch at 0xa2fc targets 0xa334, is taken when t8(=0x1ffffffff) < s2(=[a3+24]:8) (unsigned), and falls through when t8(=0x1ffffffff) >= s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa30c targets 0xa934, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa32c targets 0xa354 and is always taken.
  The `beq` branch at 0xa338 targets 0xa730, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `bne` branch at 0xa35c targets 0xa4b0, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0xa370 targets 0xad28 and is always taken.
  The `bne` branch at 0xa390 targets 0xa4b0, is taken when t1(=[a0+57]:1) < a4(?) (signed), and falls through when t1(=[a0+57]:1) >= a4(?) (signed).
  The `blez` branch at 0xa3a0 targets 0xa37c, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0xa3a8 targets 0xad1c and is always taken.
  The `beq` branch at 0xa3b0 targets 0xa49c, is taken when v0(?) == ra(=0x1), and falls through when v0(?) != ra(=0x1).
  The `beq` branch at 0xa3b8 targets 0xa444, is taken when v0(?) == s1(=0x5), and falls through when v0(?) != s1(=0x5).
  The `beq` branch at 0xa3c0 targets 0xa444, is taken when v0(?) == s4(=0x6), and falls through when v0(?) != s4(=0x6).
  The `bne` branch at 0xa3c8 targets 0xa44c, is taken when v0(?) != s0(?), and falls through when v0(?) == s0(?).
  The `bne` branch at 0xa3d0 targets 0xa44c, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0xa3e4 targets 0xa44c, is taken when s3(?) >= v0(?) (unsigned), and falls through when s3(?) < v0(?) (unsigned).
  The `beql` branch at 0xa400 targets 0xa3f0, is taken when t2(=table(0x1)) == 0, and falls through when t2(=table(0x1)) != 0; its branch-likely delay slot `nop` at 0xa404 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa408 targets 0xa60c, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa41c targets 0xa378, is taken when t9(?) >= s6(?) (signed), and falls through when t9(?) < s6(?) (signed).
  The `beq` branch at 0xa428 targets 0xa410, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa434 targets 0xa410, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0xa43c targets 0xa45c and is always taken.
  The `beq` branch at 0xa444 targets 0xa3d0, is taken when s0(?) == s7(=0x4), and falls through when s0(?) != s7(=0x4).
  The `beq` branch at 0xa450 targets 0xa410, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0xa468 targets 0xa3b0, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `beq` branch at 0xa470 targets 0xa3b0, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `bne` branch at 0xa494 targets 0xa3b8, is taken when v0(?) != ra(=0x1), and falls through when v0(?) == ra(=0x1).
  The `bne` branch at 0xa4a0 targets 0xa44c, is taken when s0(?) != s7(=0x4), and falls through when s0(?) == s7(=0x4).
  The `beq` branch at 0xa4a8 targets 0xa3d0 and is always taken.
  The `beq` branch at 0xa4f0 targets 0xa554, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa4f8 targets 0xa538, is taken when s6(=0xff) == s2(?), and falls through when s6(=0xff) != s2(?).
  The `beq` branch at 0xa504 targets 0xa6fc, is taken when a3(=[a0+114]:2) == s7(=0x2), and falls through when a3(=[a0+114]:2) != s7(=0x2).
  The `beq` branch at 0xa518 targets 0xa704, is taken when s6(=0xff) == a6(?), and falls through when s6(=0xff) != a6(?).
  The `beq` branch at 0xa554 targets 0xa8b0, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0xa55c targets 0xaac4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa578 targets 0xa5d8, is taken when v0(=ret(pciio_error_handler)) == 0, and falls through when v0(=ret(pciio_error_handler)) != 0.
  The `beq` branch at 0xa584 targets 0xaae0, is taken when v0(=ret(pciio_error_handler)) == t1(=0x9), and falls through when v0(=ret(pciio_error_handler)) != t1(=0x9).
  The `bne` branch at 0xa590 targets 0xab08, is taken when t2(=[sym(kdebug)]:2) != 0, and falls through when t2(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0xa5b0 targets 0xa6ec, is taken when s6(=0xff) == v0(?), and falls through when s6(=0xff) != v0(?).
  The `beq` branch at 0xa5bc targets 0xa6f4, is taken when a1(=[a0+114]:2) == s7(=0x2), and falls through when a1(=[a0+114]:2) != s7(=0x2).
  The `bltz` branch at 0xa5c8 targets 0xa8e8, is taken when a4(=([a3] << 0x2)) < 0 (signed), and falls through when a4(=([a3] << 0x2)) >= 0 (signed).
  The `beq` branch at 0xa5d0 targets 0xa8f8, is taken when s5(=a2) == s7(=0x2), and falls through when s5(=a2) != s7(=0x2).
  The `bltz` branch at 0xa618 targets 0xa410, is taken when t8(?) < 0 (signed), and falls through when t8(?) >= 0 (signed).
  The `beq` branch at 0xa624 targets 0xa410, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa648 targets 0xa410 and is always taken.
  The `beq` branch at 0xa660 targets 0xa08c and is always taken.
  The `beq` branch at 0xa668 targets 0xa95c, is taken when a4(=[a0+72]) == 0, and falls through when a4(=[a0+72]) != 0.
  The `bne` branch at 0xa674 targets 0xa1cc, is taken when a4(=[a0+72]) != t9(=0x1), and falls through when a4(=[a0+72]) == t9(=0x1).
  The `bne` branch at 0xa684 targets 0xaa30, is taken when s2(=[a3+24]:8) < ra(=0xc0000000) (unsigned), and falls through when s2(=[a3+24]:8) >= ra(=0xc0000000) (unsigned).
  The `bne` branch at 0xa698 targets 0xaa2c, is taken when at(=0xffffffff) < s2(=[a3+24]:8) (unsigned), and falls through when at(=0xffffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa6ac targets 0xa6c4, is taken when s2(=[a3+24]:8) < t8(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t8(=0x100000000) (unsigned).
  The `beq` branch at 0xa6bc targets 0xaa4c, is taken when t9(=0x13fffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when t9(=0x13fffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa6c4 targets 0xaab8, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa6e4 targets 0xa354 and is always taken.
  The `beq` branch at 0xa6ec targets 0xa5c8 and is always taken.
  The `beq` branch at 0xa6f4 targets 0xa5c4 and is always taken.
  The `beq` branch at 0xa6fc targets 0xa50c and is always taken.
  The `beq` branch at 0xa710 targets 0xa538 and is always taken.
  The `beq` branch at 0xa71c targets 0xa134 and is always taken.
  The `beq` branch at 0xa728 targets 0xa190 and is always taken.
  The `beq` branch at 0xa730 targets 0xaa7c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0xa744 targets 0xa940, is taken when t1(=[a0+57]:1) < a4(=[a0+56]:1) (signed), and falls through when t1(=[a0+57]:1) >= a4(=[a0+56]:1) (signed).
  The `beq` branch at 0xa760 targets 0xa77c and is always taken.
  The `bne` branch at 0xa770 targets 0xa358, is taken when t1(=[a0+57]:1) < t2(?) (signed), and falls through when t1(=[a0+57]:1) >= t2(?) (signed).
  The `bne` branch at 0xa778 targets 0xa354, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `blez` branch at 0xa788 targets 0xa768, is taken when s5(?) <= 0 (signed), and falls through when s5(?) > 0 (signed).
  The `bne` branch at 0xa790 targets 0xa768, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xa798 targets 0xa7b8 and is always taken.
  The `beq` branch at 0xa7ac targets 0xa768, is taken when v0(?) >= s5(?) (signed), and falls through when v0(?) < s5(?) (signed).
  The `bne` branch at 0xa7b4 targets 0xa768, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xa7c4 targets 0xa7a4, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `bne` branch at 0xa7cc targets 0xa7a4, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xa7d8 targets 0xa804 and is always taken.
  The `beq` branch at 0xa7f4 targets 0xa7a0, is taken when s8(?) == 0, and falls through when s8(?) != 0.
  The `bne` branch at 0xa7fc targets 0xa7a4, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xa81c targets 0xa7f4, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0xa82c targets 0xa7f4, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa844 targets 0xa7f4, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0xa858 targets 0xa7f4, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0xa860 targets 0xa7f4, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0xa868 targets 0xa7f4, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0xa870 targets 0xa7e0, is taken when t3(?) == a3(?), and falls through when t3(?) != a3(?).
  The `beq` branch at 0xa878 targets 0xa890, is taken when t3(?) == s7(=0x4), and falls through when t3(?) != s7(=0x4).
  The `beq` branch at 0xa880 targets 0xa890, is taken when t3(?) == s1(=0x5), and falls through when t3(?) != s1(=0x5).
  The `bne` branch at 0xa888 targets 0xa7f4, is taken when t3(?) != s4(=0x6), and falls through when t3(?) == s4(=0x6).
  The `beq` branch at 0xa890 targets 0xa7e0, is taken when a3(?) == s7(=0x4), and falls through when a3(?) != s7(=0x4).
  The `beq` branch at 0xa898 targets 0xa7e0, is taken when a3(?) == s1(=0x5), and falls through when a3(?) != s1(=0x5).
  The `bne` branch at 0xa8a0 targets 0xa7f4, is taken when a3(?) != s4(=0x6), and falls through when a3(?) == s4(=0x6).
  The `beq` branch at 0xa8a8 targets 0xa7e4 and is always taken.
  The `bne` branch at 0xa8bc targets 0xa8cc, is taken when s6(=0xff) != s2(?), and falls through when s6(=0xff) == s2(?).
  The `beq` branch at 0xa8c4 targets 0xa8e0 and is always taken.
  The `beq` branch at 0xa8e0 targets 0xa5dc and is always taken.
  The `beq` branch at 0xa8f0 targets 0xa5d0 and is always taken.
  The `beq` branch at 0xa900 targets 0xa5dc and is always taken.
  The `beq` branch at 0xa90c targets 0xa0c8 and is always taken.
  The `beq` branch at 0xa92c targets 0xa1c8 and is always taken.
  The `beq` branch at 0xa938 targets 0xa738 and is always taken.
  The `beq` branch at 0xa948 targets 0xa354 and is always taken.
  The `beq` branch at 0xa954 targets 0xa738 and is always taken.
  The `bne` branch at 0xa960 targets 0xa9e0, is taken when s2(=[a3+24]:8) < ra(=0x40000000) (unsigned), and falls through when s2(=[a3+24]:8) >= ra(=0x40000000) (unsigned).
  The `bne` branch at 0xa974 targets 0xa9e0, is taken when at(=0x7fffffff) < s2(=[a3+24]:8) (unsigned), and falls through when at(=0x7fffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa990 targets 0xa9a8, is taken when s2(=[a3+24]:8) < v0(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= v0(=0x80000000) (unsigned).
  The `beq` branch at 0xa9a0 targets 0xaa00, is taken when v1(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when v1(=0xbfffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa9a8 targets 0xaaac, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa9c8 targets 0xa354 and is always taken.
  The `beq` branch at 0xa9d4 targets 0xa738 and is always taken.
  The `bne` branch at 0xa9e8 targets 0xa338, is taken when s2(=[a3+24]:8) < a4(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= a4(=0x80000000) (unsigned).
  The `bne` branch at 0xa9f8 targets 0xa334, is taken when a7(=0xbfffffff) < s2(=[a3+24]:8) (unsigned), and falls through when a7(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xaa04 targets 0xaa94, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xaa24 targets 0xa354 and is always taken.
  The `bne` branch at 0xaa38 targets 0xa334, is taken when s2(=[a3+24]:8) < a4(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= a4(=0x100000000) (unsigned).
  The `bne` branch at 0xaa44 targets 0xa334, is taken when a7(=0x13fffffff) < s2(=[a3+24]:8) (unsigned), and falls through when a7(=0x13fffffff) >= s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xaa54 targets 0xaaa0, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xaa74 targets 0xa354 and is always taken.
  The `beq` branch at 0xaa8c targets 0xa354 and is always taken.
  The `beq` branch at 0xaa98 targets 0xa738 and is always taken.
  The `beq` branch at 0xaaa4 targets 0xa738 and is always taken.
  The `beq` branch at 0xaab0 targets 0xa738 and is always taken.
  The `beq` branch at 0xaabc targets 0xa738 and is always taken.
  The `beq` branch at 0xaad8 targets 0xa5dc and is always taken.
  The `bltz` branch at 0xaaf8 targets 0xac38, is taken when a2(=([a3] << 0x8)) < 0 (signed), and falls through when a2(=([a3] << 0x8)) >= 0 (signed).
  The `beq` branch at 0xab00 targets 0xa58c and is always taken.
  The `beq` branch at 0xab28 targets 0xab3c, is taken when (v0(=ret(pcireg_intr_status_get)) & a3(=0x4400008800)) == 0, and falls through when (v0(=ret(pcireg_intr_status_get)) & a3(=0x4400008800)) != 0.
  The `bgez` branch at 0xab84 targets 0xa5ac, is taken when a4(=([a3] << 0x2)) >= 0 (signed), and falls through when a4(=([a3] << 0x2)) < 0 (signed).
  The `beq` branch at 0xab8c targets 0xaca0, is taken when s6(=0xff) == a0(?), and falls through when s6(=0xff) != a0(?).
  The `beq` branch at 0xab98 targets 0xacb4, is taken when a5(=[a0+114]:2) == s7(=0x2), and falls through when a5(=[a0+114]:2) != s7(=0x2).
  The `beq` branch at 0xabac targets 0xa5b0, is taken when s0(?) >= a6(=[a0+57]:1+1) (signed), and falls through when s0(?) < a6(=[a0+57]:1+1) (signed).
  The `beq` branch at 0xac30 targets 0xa5ac and is always taken.
  The `beq` branch at 0xac40 targets 0xacd8, is taken when v0(=[a3+36]) == a5(=0x7), and falls through when v0(=[a3+36]) != a5(=0x7).
  The `beq` branch at 0xac48 targets 0xad00, is taken when s7(=0x2) == v0(=[a3+36]), and falls through when s7(=0x2) != v0(=[a3+36]).
  The `beq` branch at 0xac50 targets 0xacbc, is taken when v0(=[a3+36]) == a6(=0x4), and falls through when v0(=[a3+36]) != a6(=0x4).
  The `beq` branch at 0xac58 targets 0xacc0, is taken when v0(=[a3+36]) == a7(=0x5), and falls through when v0(=[a3+36]) != a7(=0x5).
  The `beq` branch at 0xac64 targets 0xacbc, is taken when v0(=[a3+36]) == t0(=0x6), and falls through when v0(=[a3+36]) != t0(=0x6).
  The `beq` branch at 0xac70 targets 0xab00, is taken when a4(=[a3+36]-8) >= 0x6 (unsigned), and falls through when a4(=[a3+36]-8) < 0x6 (unsigned).
  The `beq` branch at 0xac98 targets 0xab00 and is always taken.
  The `bne` branch at 0xaca4 targets 0xa5b0, is taken when t1(=[a0+57]:1) < 0xff (signed), and falls through when t1(=[a0+57]:1) >= 0xff (signed).
  The `beq` branch at 0xacac targets 0xabb4 and is always taken.
  The `beq` branch at 0xacb4 targets 0xaba0 and is always taken.
  The `beq` branch at 0xacd0 targets 0xab00 and is always taken.
  The `beq` branch at 0xacf8 targets 0xab00 and is always taken.
  The `beq` branch at 0xad14 targets 0xab00 and is always taken.
  The `beq` branch at 0xad20 targets 0xa428 and is always taken.
  The `beq` branch at 0xad30 targets 0xa39c and is always taken.
  The return at 0xa604 has v0 = one of ?, 0x7.
  The instructions from 0xa264 to 0xa264 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xa9dc to 0xa9dc are not reached by any path from the entry, and their branches are not listed.

- `pcibr_dmard_error` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xad38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xad38-0xae60 (296 bytes).
  It occupies 296 bytes.
  The `lw` at 0xad38 loads 4 bytes from a0 (arg0 at entry) +0x4.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0xad7c, `lw` at 0xad98.
  The `sh` at 0xad80 stores 2 bytes to a3 (arg3 at entry) +0x8.
  2 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0xad94, `sw` at 0xadac.
  The `sd` at 0xad9c stores 8 bytes to a3 (arg3 at entry) +0x28.
  The `lh` at 0xadc8 loads 2 bytes from a3 (arg3 at entry) +0x8.
  The `jal` at 0xad64 calls pcireg_resp_err_buf_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xad70 calls pcireg_resp_err_dev_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xad90 calls pcireg_resp_err_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xadb8 calls pciio_error_handler with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xadd4 calls pcibr_device_disable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xade8 calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=0x10, a2=?, a3=?.
  The `jal` at 0xae04 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xae30 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xae40 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=ret(pcireg_rrb_get), a3=?.
  The `beq` branch at 0xadc0 targets 0xaddc, is taken when v0(=ret(pciio_error_handler)) == 0, and falls through when v0(=ret(pciio_error_handler)) != 0.
  The return at 0xae58 has v0 = ret(pciio_error_handler).

- `pcibr_dmawr_error` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xae60 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xae60-0xaea8 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0xae74 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lh` at 0xae84 loads 2 bytes from a3 (arg3 at entry) +0x8.
  The `jal` at 0xae70 calls pciio_error_handler with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xae90 calls pcibr_device_disable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xae78 targets 0xae98, is taken when v0(=ret(pciio_error_handler)) == 0, and falls through when v0(=ret(pciio_error_handler)) != 0.
  The return at 0xaea0 has v0 = ret(pciio_error_handler).

- `pcibr_error_handler` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xaea8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xaea8-0xaf74 (204 bytes).
  It occupies 204 bytes.
  The `lw` at 0xaedc loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0xaee0 calls pcibr_debug with a0=0x200, a1=[a0], a2=sym(.rodata)+6040, a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The `jal` at 0xaf00 calls pcibr_pioerror with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xaf2c calls pcibr_dmard_error with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0xaf4c calls pcibr_dmawr_error with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=a3 at entry (arg3).
  The `beq` branch at 0xaeec targets 0xaf0c, is taken when (s0(=a1) & 0x4) == 0, and falls through when (s0(=a1) & 0x4) != 0.
  The `beq` branch at 0xaf10 targets 0xaf58, is taken when (s0(=a1) & 0x8) == 0, and falls through when (s0(=a1) & 0x8) != 0.
  The `beq` branch at 0xaf18 targets 0xaf3c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xaf3c targets 0xaf58, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0xaf6c has v0 = one of ?, ret(pcibr_dmawr_error).

- `pcibr_error_handler_wrapper` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xaf74 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xaf74-0xb1bc (584 bytes).
  It occupies 584 bytes.
  The `lw` at 0xaf84 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0xafe8 loads 8 bytes from a3 (arg3 at entry) +0x18.
  The `ld` at 0xb054 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lh` at 0xb134 loads 2 bytes from a3 (arg3 at entry) +0x50.
  The `lw` at 0xb13c loads 4 bytes from a3 (arg3 at entry) +0x0.
  The `sw` at 0xb150 stores 4 bytes to a3 (arg3 at entry) +0x0.
  The `sh` at 0xb15c stores 2 bytes to a3 (arg3 at entry) +0x8.
  The `ld` at 0xb164 loads 8 bytes from ?.
  The `jal` at 0xafc4 calls pcibr_debug with a0=0x200, a1=[a0], a2=sym(.rodata)+6040, a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The `jal` at 0xb0ec calls pcibr_error_handler with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb10c calls pcibr_error_handler with a0=[a0+64]:8, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb168 calls pcibr_error_handler with a0=?, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=([a3] | 0x20000000), a6=0x20000000.
  The `jal` at 0xb18c calls pcibr_error_handler with a0=?, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=([a3] | 0x20000000), a6=0x20000000.
  The `jal` at 0xb1a8 calls cmn_err with a0=0x4, a1=sym(.rodata)+6040, a2=[a3+24]:8, a3=?.
  The `beq` branch at 0xafe0 targets 0xb11c, is taken when (s1(=a1) & 0x4) == 0, and falls through when (s1(=a1) & 0x4) != 0.
  The `beq` branch at 0xb008 targets 0xb0dc, is taken when a4(=0x7fffff) >= a2(=[a3+24]:8) (unsigned), and falls through when a4(=0x7fffff) < a2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xb020 targets 0xb02c, is taken when a2(=[a3+24]:8) < a5(=0x40000000) (unsigned), and falls through when a2(=[a3+24]:8) >= a5(=0x40000000) (unsigned).
  The `beq` branch at 0xb028 targets 0xb0dc, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0xb034 targets 0xb044, is taken when a2(=[a3+24]:8) < a6(=0x800000) (unsigned), and falls through when a2(=[a3+24]:8) >= a6(=0x800000) (unsigned).
  The `beq` branch at 0xb03c targets 0xb054, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0xb044 targets 0xb1a4, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0xb04c targets 0xb1a4, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0xb058 targets 0xb100, is taken when s3(=[a0+64]:8) != 0, and falls through when s3(=[a0+64]:8) == 0.
  The `beq` branch at 0xb06c targets 0xb134, is taken when a7(?) == t0(=0xa), and falls through when a7(?) != t0(=0xa).
  The `beq` branch at 0xb080 targets 0xb124, is taken when s0(?) == s5(=-0x1), and falls through when s0(?) != s5(=-0x1).
  The `beq` branch at 0xb088 targets 0xb0c4, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xb090 targets 0xb0c4, is taken when a0(?) == s5(=-0x1), and falls through when a0(?) != s5(=-0x1).
  The `beq` branch at 0xb0c4 targets 0xb17c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xb0cc targets 0xb17c, is taken when s0(?) == s5(=-0x1), and falls through when s0(?) != s5(=-0x1).
  The `beq` branch at 0xb0d4 targets 0xb09c and is always taken.
  The `beq` branch at 0xb0f8 targets 0xb064 and is always taken.
  The `beq` branch at 0xb114 targets 0xb060 and is always taken.
  The `beq` branch at 0xb11c targets 0xb068 and is always taken.
  The `bne` branch at 0xb124 targets 0xb088, is taken when a0(?) != s5(=-0x1), and falls through when a0(?) == s5(=-0x1).
  The `beq` branch at 0xb12c targets 0xb098 and is always taken.
  The `beq` branch at 0xb158 targets 0xb184, is taken when (a4(=[a3+80]:2) & 0x4) == 0, and falls through when (a4(=[a3+80]:2) & 0x4) != 0.
  The `beq` branch at 0xb174 targets 0xb074 and is always taken.
  The `beq` branch at 0xb17c targets 0xb098 and is always taken.
  The `beq` branch at 0xb198 targets 0xb074 and is always taken.
  The `beq` branch at 0xb1b4 targets 0xb064 and is always taken.
  The return at 0xb0bc has v0 = ?.
  The instructions from 0xb1a0 to 0xb1a0 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_error_devenable` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb1bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb1bc-0xb238 (124 bytes).
  It occupies 124 bytes.
  The `lbu` at 0xb1d4 loads 1 byte from ret(pciio_info_get) +0x21c.
  The `lw` at 0xb1f4 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0xb1c8 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb1dc calls pciio_info_mfast_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xb1fc calls xtalk_error_devenable with a0=[ret(pciio_info_mfast_get)], a1=[ret(pciio_info_get)+540]:1, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0xb218 calls pcibr_error_cleanup with a0=ret(pciio_info_mfast_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `bne` branch at 0xb1ec targets 0xb218, is taken when (s0(=a1) & 0x2) != 0, and falls through when (s0(=a1) & 0x2) == 0.
  The `beq` branch at 0xb204 targets 0xb218, is taken when v0(=ret(xtalk_error_devenable)) == 0, and falls through when v0(=ret(xtalk_error_devenable)) != 0.
  The `beq` branch at 0xb20c targets 0xb228 and is always taken.
  The return at 0xb230 has v0 = one of ret(xtalk_error_devenable), 0x0.
  The instructions from 0xb214 to 0xb214 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_func_config_addr` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb238 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb238-0xb2bc (132 bytes).
  It occupies 132 bytes.
  The `jal` at 0xb26c calls pcireg_type1_cntr_set with a0=a0 at entry (arg0), a1=((a1 << 0x10) | (a2 << 0xb)), a2=(a2 << 0xb), a3=a3 at entry (arg3), a7=a1 at entry (arg1).
  The `jal` at 0xb27c calls pcireg_type1_cfg_addr with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=?.
  The `jal` at 0xb2ac calls pcireg_type0_cfg_addr with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=a4 at entry (arg4), a7=a1 at entry (arg1).
  The `blez` branch at 0xb25c targets 0xb2a4, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0xb2b4 targets 0xb288 and is always taken.
  The return at 0xb29c has v0 = one of ret(pcireg_type1_cfg_addr), ret(pcireg_type0_cfg_addr).

- `pcibr_slot_config_addr` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb2bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb2bc-0xb2e8 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xb2d4 calls pcibr_func_config_addr with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=0x0, a4=a2 at entry (arg2).
  The return at 0xb2e0 has v0 = ret(pcibr_func_config_addr).

- `pcibr_slot_config_get` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb2e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb2e8-0xb324 (60 bytes).
  It occupies 60 bytes.
  The `jal` at 0xb2f8 calls pcibr_slot_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0xb308 calls do_pcibr_config_get with a0=ret(pcibr_slot_config_addr), a1=a2 at entry (arg2), a2=0x4, a3=?.
  The return at 0xb31c has v0 = (ret(do_pcibr_config_get) << 0x0).

- `pcibr_func_config_get` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb324 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb324-0xb374 (80 bytes).
  It occupies 80 bytes.
  The `jal` at 0xb348 calls pcibr_func_config_addr with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `jal` at 0xb358 calls do_pcibr_config_get with a0=ret(pcibr_func_config_addr), a1=a3 at entry (arg3), a2=0x4, a3=?.
  The return at 0xb36c has v0 = (ret(do_pcibr_config_get) << 0x0).

- `pcibr_slot_config_set` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb374 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb374-0xb3bc (72 bytes).
  It occupies 72 bytes.
  The `jal` at 0xb388 calls pcibr_slot_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0xb3a4 calls do_pcibr_config_set with a0=ret(pcibr_slot_config_addr), a1=a2 at entry (arg2), a2=0x4, a3=?.
  The return at 0xb3b4 has v0 = ret(do_pcibr_config_set).

- `pcibr_func_config_set` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb3bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb3bc-0xb418 (92 bytes).
  It occupies 92 bytes.
  The `jal` at 0xb3e4 calls pcibr_func_config_addr with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `jal` at 0xb400 calls do_pcibr_config_set with a0=ret(pcibr_func_config_addr), a1=a3 at entry (arg3), a2=0x4, a3=?.
  The return at 0xb410 has v0 = ret(do_pcibr_config_set).

- `pcibr_config_addr` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb418 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb418-0xb50c (244 bytes).
  It occupies 244 bytes.
  The `ld` at 0xb480 loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `ld` at 0xb490 loads 8 bytes from [ret(pcibr_info_get)+40]:8 +0x8.
  The `lbu` at 0xb4b4 loads 1 byte from ret(pciio_info_get) +0x12.
  The `lbu` at 0xb4b8 loads 1 byte from ret(pciio_info_get) +0x11.
  The `lbu` at 0xb4c0 loads 1 byte from ret(pciio_info_get) +0x10.
  The `lbu` at 0xb4d0 loads 1 byte from ret(pcibr_info_get) +0x21c.
  The `lbu` at 0xb4d8 loads 1 byte from ret(pcibr_info_get) +0x12.
  The `jal` at 0xb430 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb440 calls pcibr_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb44c calls pciio_info_type1_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xb48c calls pcibr_func_config_addr with a0=[[ret(pcibr_info_get)+40]:8+8]:8, a1=?, a2=?, a3=?, a4=0x0.
  The `jal` at 0xb4a4 calls pciio_info_hostdev_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xb454 targets 0xb4a4, is taken when v0(=ret(pciio_info_type1_get)) == 0, and falls through when v0(=ret(pciio_info_type1_get)) != 0.
  The `beq` branch at 0xb4ac targets 0xb4d0, is taken when v0(=ret(pciio_info_hostdev_get)) == s2(=a0), and falls through when v0(=ret(pciio_info_hostdev_get)) != s2(=a0).
  The `beq` branch at 0xb4c8 targets 0xb478 and is always taken.
  The `beq` branch at 0xb4d4 targets 0xb4ec, is taken when a0(=0xff) == a2(=[ret(pcibr_info_get)+540]:1), and falls through when a0(=0xff) != a2(=[ret(pcibr_info_get)+540]:1).
  The `beq` branch at 0xb4dc targets 0xb4fc, is taken when a0(=0xff) == a3(=[ret(pcibr_info_get)+18]:1), and falls through when a0(=0xff) != a3(=[ret(pcibr_info_get)+18]:1).
  The `beq` branch at 0xb4e4 targets 0xb47c and is always taken.
  The `beq` branch at 0xb4f4 targets 0xb4dc and is always taken.
  The `beq` branch at 0xb504 targets 0xb4e0 and is always taken.
  The return at 0xb49c has v0 = ret(pcibr_func_config_addr).

- `pcibr_config_get` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb50c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb50c-0xb544 (56 bytes).
  It occupies 56 bytes.
  The `jal` at 0xb51c calls pcibr_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb52c calls do_pcibr_config_get with a0=ret(pcibr_config_addr), a1=?, a2=a2 at entry (arg2), a3=?.
  The return at 0xb53c has v0 = ret(do_pcibr_config_get).

- `pcibr_config_get_safe` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb544 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb544-0xb5a4 (96 bytes).
  It occupies 96 bytes.
  The `ld` at 0xb55c loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `ld` at 0xb564 loads 8 bytes from [ret(pcibr_info_get)+40]:8 +0x8.
  The `jal` at 0xb554 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb56c calls pcibr_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xb580 calls pcibr_probe_slot with a0=?, a1=ret(pcibr_config_addr), a2=sp-48, a3=?.
  The `beq` branch at 0xb588 targets 0xb59c, is taken when v0(=ret(pcibr_probe_slot)) == 0, and falls through when v0(=ret(pcibr_probe_slot)) != 0.
  The `beq` branch at 0xb59c targets 0xb594 and is always taken.
  The return at 0xb594 has v0 = one of -0x1, ?.

- `do_pcibr_config_get` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb5a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb5a4-0xb5f0 (76 bytes).
  It occupies 76 bytes.
  The `lw` at 0xb5c8 loads 4 bytes from ?.
  The `beq` branch at 0xb5c4 targets 0xb5d4, is taken when (a1 & 0x3) == 0, and falls through when (a1 & 0x3) != 0.
  The `beq` branch at 0xb5d4 targets 0xb5e4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0xb5e8 has v0 = ?.

- `pcibr_config_set` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb5f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb5f0-0xb630 (64 bytes).
  It occupies 64 bytes.
  The `jal` at 0xb604 calls pcibr_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb618 calls do_pcibr_config_set with a0=ret(pcibr_config_addr), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xb628 has v0 = ret(do_pcibr_config_set).

- `do_pcibr_config_set` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb630 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb630-0xb768 (312 bytes).
  It occupies 312 bytes.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0xb690, `sb` at 0xb69c, `sb` at 0xb6d0.
  3 such `sh` accesses store 2 bytes to ?, including `sh` at 0xb6dc, `sh` at 0xb728, `sh` at 0xb75c.
  The `sw` at 0xb6f0 stores 4 bytes to ?.
  The `beq` branch at 0xb63c targets 0xb6f4, is taken when a2 == at(=0x1), and falls through when a2 != at(=0x1).
  The `beq` branch at 0xb644 targets 0xb664, is taken when a2 == a5(=0x2), and falls through when a2 != a5(=0x2).
  The `beq` branch at 0xb64c targets 0xb6a0, is taken when a2 == a6(=0x3), and falls through when a2 != a6(=0x3).
  The `beq` branch at 0xb654 targets 0xb6e0, is taken when a2 == a7(=0x4), and falls through when a2 != a7(=0x4).
  The `beq` branch at 0xb678 targets 0xb70c, is taken when (a1 & 0x1) == 0, and falls through when (a1 & 0x1) != 0.
  The `beq` branch at 0xb6ac targets 0xb72c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The return at 0xb65c has v0 = ?.
  The return at 0xb698 has v0 = ?.
  The return at 0xb6d8 has v0 = ?.
  The return at 0xb6ec has v0 = ?.
  The return at 0xb704 has v0 = ?.
  The return at 0xb724 has v0 = ?.
  The return at 0xb760 has v0 = ?.

- `pcibr_slot_info_init` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xb768 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xb768-0xc298 (2864 bytes).
  It occupies 2864 bytes.
  The `lbu` at 0xb7a0 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `ld` at 0xb7b0 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `lw` at 0xb7c0 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xb84c, `lw` at 0xb94c, `lw` at 0xbff0.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0xb854, `sw` at 0xb9b0, `sw` at 0xbb84.
  6 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0xb878, `lh` at 0xba5c, `lh` at 0xbb18.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xb9a4, `sd` at 0xbb78, `sd` at 0xbb7c.
  5 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x74, including `lh` at 0xbac0, `lh` at 0xbae8, `lh` at 0xbf7c.
  The `sd` at 0xbe1c stores 8 bytes to ret(pcibr_device_info_new) +0x220.
  The `lw` at 0xbe20 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x508.
  The `sw` at 0xbe28 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x508.
  The `ld` at 0xbe2c loads 8 bytes from ret(pcibr_device_info_new) +0x220.
  The `lw` at 0xbe30 loads 4 bytes from [ret(pcibr_device_info_new)+544]:8 +0x4.
  The `lw` at 0xbe48 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x50c.
  The `lw` at 0xbe4c loads 4 bytes from table(sym(max_splittrans_to_numbuf)) +0x0.
  The `sw` at 0xbe54 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x50c.
  3 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x878, including `lw` at 0xbef4, `lw` at 0xbf20, `lw` at 0xc210.
  The `lbu` at 0xbefc loads 1 byte from ret(hwgraph_fastinfo_get) +0x28.
  2 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0x878, including `sw` at 0xbf2c, `sw` at 0xc21c.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x10, including `ld` at 0xc23c, `ld` at 0xc26c.
  The `jal` at 0xb788 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb7fc calls pcibr_is_slot_sys_critical with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x16, a3=?.
  The `jal` at 0xb81c calls pcibr_slot_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=0x0, a3=?.
  The `jal` at 0xb830 calls pcibr_probe_slot with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=ret(pcibr_slot_config_addr), a2=sp-608, a3=?.
  The `jal` at 0xb894 calls pcibr_debug with a0=0x80, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=?.
  The `jal` at 0xb8b0 calls do_pcibr_config_get with a0=ret(pcibr_slot_config_addr), a1=0xe, a2=0x1, a3=?, a5=0xffff.
  The `jal` at 0xb92c calls pcibr_func_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xb93c calls pcibr_probe_slot with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=ret(pcibr_func_config_addr), a2=?, a3=?.
  The `jal` at 0xb974 calls pcibr_slot_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=0x0, a3=?.
  The `jal` at 0xb990 calls kmem_zalloc with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0xba80 calls pcibr_debug with a0=0x400, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=?.
  The `jal` at 0xba9c calls do_pcibr_config_get with a0=?, a1=0xd, a2=0x1, a3=?.
  The `jal` at 0xbaac calls pcireg_device_get with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xbad8 calls do_pcibr_config_get with a0=?, a1=0xc, a2=0x1, a3=?.
  The `jal` at 0xbafc calls pcibr_find_capability with a0=?, a1=0x7, a2=?, a3=?.
  The `jal` at 0xbb40 calls pcibr_debug with a0=0x400, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=ret(pcibr_find_capability).
  The `jal` at 0xbbb4 calls do_pcibr_config_set with a0=?, a1=?, a2=0x4, a3=0x0, a6=0x4.
  The `jal` at 0xbbf0 calls sprintf with a0=sp-568, a1=sym(.rodata)+10664, a2=?, a3=?.
  The `jal` at 0xbc08 calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=sp-568.
  The `jal` at 0xbc4c calls do_pcibr_config_get with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xbce4 calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=one of 0x2, 0x4, 0x5, a3=?, a5=0x0.
  The `jal` at 0xbd70 calls do_pcibr_config_set with a0=?, a1=?, a2=0x4, a3=-0x1.
  The `jal` at 0xbd80 calls do_pcibr_config_get with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xbe0c calls pcibr_device_info_new with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xbe5c calls pciio_device_info_register with a0=a0 at entry (arg0), a1=ret(pcibr_device_info_new), a2=?, a3=?.
  The `jal` at 0xbe70 calls do_pcibr_config_get with a0=?, a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xbf18 calls pciio_device_win_populate with a0=?, a1=([ret(hwgraph_fastinfo_get)+40]:1 << 0x18), a2=0x1000000, a3=?.
  The `jal` at 0xbf74 calls do_pcibr_config_get with a0=?, a1=0x3e, a2=0x1, a3=?.
  The `jal` at 0xbff8 calls pcibr_func_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xc018 calls do_pcibr_config_get with a0=ret(pcibr_func_config_addr), a1=0xe, a2=0x1, a3=?.
  The `jal` at 0xc094 calls do_pcibr_config_get with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xc0b8 calls do_pcibr_config_set with a0=?, a1=0xc, a2=0x1, a3=0x20.
  The `jal` at 0xc0ec calls pcibr_debug with a0=0x400, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=?.
  The `jal` at 0xc110 calls do_pcibr_config_set with a0=?, a1=0xd, a2=0x1, a3=?, a6=one of 0x8, 0x10, 0x18, 0x20, a7=0x5.
  The `jal` at 0xc148 calls pcibr_debug with a0=0x400, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=?.
  The `jal` at 0xc208 calls pciio_device_win_populate with a0=?, a1=([ret(hwgraph_fastinfo_get)+40]:1 << 0x18), a2=0x1000000, a3=0x10a9.
  The `jal` at 0xc24c calls cmn_err with a0=0x4, a1=sym(.rodata)+10664, a2=[ret(hwgraph_fastinfo_get)+16]:8, a3=a1 at entry (arg1).
  The `jal` at 0xc270 calls cmn_err with a0=0x4, a1=sym(.rodata)+10664, a2=[ret(hwgraph_fastinfo_get)+16]:8, a3=a1 at entry (arg1).
  The `jal` at 0xc288 calls pcibr_device_info_new with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=0xff, a3=-0x1, a4=-0x1.
  The `beq` branch at 0xb798 targets 0xb7d0, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xb7ac targets 0xb7f4, is taken when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xb7c4 targets 0xb7fc, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xb7f4 targets 0xb7d0 and is always taken.
  The `beq` branch at 0xb804 targets 0xb814, is taken when v0(=ret(pcibr_is_slot_sys_critical)) == 0, and falls through when v0(=ret(pcibr_is_slot_sys_critical)) != 0.
  The `beq` branch at 0xb80c targets 0xb7d0 and is always taken.
  The `beq` branch at 0xb838 targets 0xb84c, is taken when v0(=ret(pcibr_probe_slot)) == 0, and falls through when v0(=ret(pcibr_probe_slot)) != 0.
  The `beq` branch at 0xb844 targets 0xb7d0 and is always taken.
  The `beq` branch at 0xb870 targets 0xc04c, is taken when v1(=0xff) == s0(=a1), and falls through when v1(=0xff) != s0(=a1).
  The `beq` branch at 0xb880 targets 0xc07c, is taken when a3(=[ret(hwgraph_fastinfo_get)+114]:2) == a4(=0x2), and falls through when a3(=[ret(hwgraph_fastinfo_get)+114]:2) != a4(=0x2).
  The `beq` branch at 0xb8a4 targets 0xc034, is taken when a5(=0xffff) == a6(?), and falls through when a5(=0xffff) != a6(?).
  The `beq` branch at 0xb8c8 targets 0xc054, is taken when (a7(=(ret(do_pcibr_config_get) << 0x0)) & 0x80) == 0, and falls through when (a7(=(ret(do_pcibr_config_get) << 0x0)) & 0x80) != 0.
  The `beq` branch at 0xb8e8 targets 0xb90c and is always taken.
  The `beq` branch at 0xb904 targets 0xb96c, is taken when s2(?) >= 0x8 (signed), and falls through when s2(?) < 0x8 (signed).
  The `bne` branch at 0xb944 targets 0xb8f0, is taken when v0(=ret(pcibr_probe_slot)) != 0, and falls through when v0(=ret(pcibr_probe_slot)) == 0.
  The `beq` branch at 0xb958 targets 0xc06c, is taken when ra(?) == at(=0xffff), and falls through when ra(?) != at(=0xffff).
  The `beq` branch at 0xb964 targets 0xb8fc and is always taken.
  The `blez` branch at 0xb9ac targets 0xbeb8, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0xb9d4 targets 0xba00 and is always taken.
  The `bne` branch at 0xb9e4 targets 0xbb8c, is taken when a6(?) != a7(=0x3), and falls through when a6(?) == a7(=0x3).
  The `beq` branch at 0xb9f8 targets 0xbeb8, is taken when s2(?) >= t0(?) (signed), and falls through when s2(?) < t0(?) (signed).
  The `beq` branch at 0xba00 targets 0xba28, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xba18 targets 0xbfd4, is taken when (s3(?) & t8(?)) == 0, and falls through when (s3(?) & t8(?)) != 0.
  The `bne` branch at 0xba20 targets 0xb9f0, is taken when s3(?) != 0, and falls through when s3(?) == 0.
  The `beq` branch at 0xba30 targets 0xbed0, is taken when (t9(?) & 0x7f) == 0, and falls through when (t9(?) & 0x7f) != 0.
  The `bne` branch at 0xba40 targets 0xc238, is taken when ra(=0x1) != at(?), and falls through when ra(=0x1) == at(?).
  The `beq` branch at 0xba54 targets 0xbedc, is taken when v1(=0xff) == s0(=a1), and falls through when v1(=0xff) != s0(=a1).
  The `beq` branch at 0xba64 targets 0xbfcc, is taken when a0(=[ret(hwgraph_fastinfo_get)+114]:2) == a1(=0x2), and falls through when a0(=[ret(hwgraph_fastinfo_get)+114]:2) != a1(=0x2).
  The `beq` branch at 0xba90 targets 0xbee4, is taken when a2(?) == a3(=0x10a9), and falls through when a2(?) != a3(=0x10a9).
  The `beq` branch at 0xbab8 targets 0xbf30, is taken when a4(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a4(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xbac8 targets 0xbdfc, is taken when (a5(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a5(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xbae0 targets 0xc0b0, is taken when v0(=ret(do_pcibr_config_get)) == 0, and falls through when v0(=ret(do_pcibr_config_get)) != 0.
  The `beq` branch at 0xbaf0 targets 0xbdfc, is taken when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xbb04 targets 0xc25c, is taken when v0(=ret(pcibr_find_capability)) == 0, and falls through when v0(=ret(pcibr_find_capability)) != 0.
  The `beq` branch at 0xbb10 targets 0xc084, is taken when t0(=0xff) == s0(=a1), and falls through when t0(=0xff) != s0(=a1).
  The `beq` branch at 0xbb20 targets 0xc0a8, is taken when t1(=[ret(hwgraph_fastinfo_get)+114]:2) == t2(=0x2), and falls through when t1(=[ret(hwgraph_fastinfo_get)+114]:2) != t2(=0x2).
  The `bne` branch at 0xbb4c targets 0xb9ec, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0xbb54 targets 0xbe00 and is always taken.
  The `beq` branch at 0xbb80 targets 0xb9dc, is taken when a5(?) == a6(=0x10a9), and falls through when a5(?) != a6(=0x10a9).
  The `bne` branch at 0xbb90 targets 0xbc20, is taken when a6(=0x4) != a7(?), and falls through when a6(=0x4) == a7(?).
  The `beq` branch at 0xbbbc targets 0xbc24 and is always taken.
  The `beq` branch at 0xbc18 targets 0xbb5c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xbc3c targets 0xb9ec, is taken when s6(?) >= a4(?) (signed), and falls through when s6(?) < a4(?) (signed).
  The `beq` branch at 0xbc68 targets 0xbd20, is taken when (v0(=ret(do_pcibr_config_get)) & 0x1) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0x1) != 0.
  The `beq` branch at 0xbc80 targets 0xbc90, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xbc94 targets 0xbd64, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xbcb0 targets 0xbda8, is taken when t2(=one of 0x2, 0x4) == t3(=0x4), and falls through when t2(=one of 0x2, 0x4) != t3(=0x4).
  The `beq` branch at 0xbcfc targets 0xbc10, is taken when (a5(=[sym(pcibr_debug_mask)]) & 0x800) == 0, and falls through when (a5(=[sym(pcibr_debug_mask)]) & 0x800) != 0.
  The `beq` branch at 0xbd04 targets 0xbdc0, is taken when a6(=0xff) == s0(=a1), and falls through when a6(=0xff) != s0(=a1).
  The `bne` branch at 0xbd10 targets 0xbbc4, is taken when a7(=[ret(hwgraph_fastinfo_get)+114]:2) != t0(=0x2), and falls through when a7(=[ret(hwgraph_fastinfo_get)+114]:2) == t0(=0x2).
  The `beq` branch at 0xbd18 targets 0xbbc8 and is always taken.
  The `beq` branch at 0xbd40 targets 0xbdd4, is taken when (t3(=-0x10) & v0(=ret(do_pcibr_config_get))) == 0, and falls through when (t3(=-0x10) & v0(=ret(do_pcibr_config_get))) != 0.
  The `beq` branch at 0xbd48 targets 0xbde4, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0xbd58 targets 0xbdc8, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xbda0 targets 0xbc10 and is always taken.
  The `beq` branch at 0xbdb0 targets 0xbcb8, is taken when v0(=0x2) == v1(?), and falls through when v0(=0x2) != v1(?).
  The `beq` branch at 0xbdb8 targets 0xbcb8 and is always taken.
  The `beq` branch at 0xbdc0 targets 0xbbc8 and is always taken.
  The `beq` branch at 0xbdcc targets 0xc08c, is taken when a1(=0x4) == t2(?), and falls through when a1(=0x4) != t2(?).
  The `beq` branch at 0xbddc targets 0xbc90 and is always taken.
  The `beq` branch at 0xbdf4 targets 0xbd64 and is always taken.
  The `beq` branch at 0xbe18 targets 0xbe58, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xbe64 targets 0xc040, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `blez` branch at 0xbe7c targets 0xb9f0, is taken when t1(?) <= 0 (signed), and falls through when t1(?) > 0 (signed).
  The `beq` branch at 0xbeb0 targets 0xbc44 and is always taken.
  The `beq` branch at 0xbec8 targets 0xb7d0 and is always taken.
  The `beq` branch at 0xbed4 targets 0xba50 and is always taken.
  The `beq` branch at 0xbedc targets 0xba6c and is always taken.
  The `bne` branch at 0xbeec targets 0xba98, is taken when ra(?) != at(=0x2), and falls through when ra(?) == at(=0x2).
  The `beq` branch at 0xbf00 targets 0xc200, is taken when (v0(=[ret(hwgraph_fastinfo_get)+2168]) & 0x1) == 0, and falls through when (v0(=[ret(hwgraph_fastinfo_get)+2168]) & 0x1) != 0.
  The `bne` branch at 0xbf0c targets 0xba94, is taken when (v0(?) & 0x2) != 0, and falls through when (v0(?) & 0x2) == 0.
  The `beq` branch at 0xbf28 targets 0xba94 and is always taken.
  The `bne` branch at 0xbf34 targets 0xbac0, is taken when (at(=0x200000) & v0(=ret(pcireg_device_get))) != 0, and falls through when (at(=0x200000) & v0(=ret(pcireg_device_get))) == 0.
  The `bne` branch at 0xbf40 targets 0xbf70, is taken when v0(?) != v1(=0x10a9), and falls through when v0(?) == v1(=0x10a9).
  The `beq` branch at 0xbf50 targets 0xbac0, is taken when a0(?) == a1(=0x3), and falls through when a0(?) != a1(=0x3).
  The `beq` branch at 0xbf5c targets 0xbac0, is taken when a2(?) == a3(=0x2), and falls through when a2(?) != a3(=0x2).
  The `beq` branch at 0xbf68 targets 0xbac0, is taken when a4(?) == a5(=0x5), and falls through when a4(?) != a5(=0x5).
  The `beq` branch at 0xbf84 targets 0xc188, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == a6(=0x7), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != a6(=0x7).
  The `beq` branch at 0xbf8c targets 0xc1b8, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == a7(=0x5), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != a7(=0x5).
  The `beq` branch at 0xbf94 targets 0xc168, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == t0(=0x2), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != t0(=0x2).
  The `beq` branch at 0xbf9c targets 0xc168, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == t1(=0x3), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != t1(=0x3).
  The `beq` branch at 0xbfa4 targets 0xc1e8, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xbfb0 targets 0xc0fc, is taken when t2(=(ret(do_pcibr_config_get) << 0x3)) >= 0x100 (unsigned), and falls through when t2(=(ret(do_pcibr_config_get) << 0x3)) < 0x100 (unsigned).
  The `beq` branch at 0xbfc4 targets 0xc104 and is always taken.
  The `beq` branch at 0xbfcc targets 0xba6c and is always taken.
  The `beq` branch at 0xc02c targets 0xba20 and is always taken.
  The `beq` branch at 0xc038 targets 0xb7d0 and is always taken.
  The `beq` branch at 0xc044 targets 0xbe68 and is always taken.
  The `beq` branch at 0xc04c targets 0xb888 and is always taken.
  The `beq` branch at 0xc064 targets 0xb984 and is always taken.
  The `beq` branch at 0xc074 targets 0xb8fc and is always taken.
  The `beq` branch at 0xc07c targets 0xb888 and is always taken.
  The `beq` branch at 0xc084 targets 0xbb28 and is always taken.
  The `beq` branch at 0xc0a0 targets 0xbdd4 and is always taken.
  The `beq` branch at 0xc0a8 targets 0xbb28 and is always taken.
  The `beq` branch at 0xc0c4 targets 0xc158, is taken when a3(=0xff) == s0(=a1), and falls through when a3(=0xff) != s0(=a1).
  The `beq` branch at 0xc0d4 targets 0xc160, is taken when a4(=[ret(hwgraph_fastinfo_get)+114]:2) == a5(=0x2), and falls through when a4(=[ret(hwgraph_fastinfo_get)+114]:2) != a5(=0x2).
  The `beq` branch at 0xc0f4 targets 0xbaec and is always taken.
  The `beq` branch at 0xc11c targets 0xc1a8, is taken when a4(=0xff) == s0(=a1), and falls through when a4(=0xff) != s0(=a1).
  The `beq` branch at 0xc12c targets 0xc1b0, is taken when a5(=[ret(hwgraph_fastinfo_get)+114]:2) == a6(=0x2), and falls through when a5(=[ret(hwgraph_fastinfo_get)+114]:2) != a6(=0x2).
  The `beq` branch at 0xc150 targets 0xbac4 and is always taken.
  The `beq` branch at 0xc158 targets 0xc0dc and is always taken.
  The `beq` branch at 0xc160 targets 0xc0dc and is always taken.
  The `beq` branch at 0xc16c targets 0xc220, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xc178 targets 0xc1e0, is taken when a3(=(ret(do_pcibr_config_get) << 0x4)) >= 0x100 (unsigned), and falls through when a3(=(ret(do_pcibr_config_get) << 0x4)) < 0x100 (unsigned).
  The `beq` branch at 0xc180 targets 0xbfbc and is always taken.
  The `beq` branch at 0xc18c targets 0xc228, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xc198 targets 0xc1f0, is taken when a4(=(ret(do_pcibr_config_get) << 0x5)) >= 0x100 (unsigned), and falls through when a4(=(ret(do_pcibr_config_get) << 0x5)) < 0x100 (unsigned).
  The `beq` branch at 0xc1a0 targets 0xbfbc and is always taken.
  The `beq` branch at 0xc1a8 targets 0xc134 and is always taken.
  The `beq` branch at 0xc1b0 targets 0xc134 and is always taken.
  The `beq` branch at 0xc1bc targets 0xc230, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xc1d0 targets 0xc1f8, is taken when a5(?) >= 0x100 (unsigned), and falls through when a5(?) < 0x100 (unsigned).
  The `beq` branch at 0xc1d8 targets 0xbfbc and is always taken.
  The `beq` branch at 0xc1e0 targets 0xc0fc and is always taken.
  The `beq` branch at 0xc1e8 targets 0xc0fc and is always taken.
  The `beq` branch at 0xc1f0 targets 0xc0fc and is always taken.
  The `beq` branch at 0xc1f8 targets 0xc0fc and is always taken.
  The `beq` branch at 0xc218 targets 0xbf08 and is always taken.
  The `beq` branch at 0xc220 targets 0xc0fc and is always taken.
  The `beq` branch at 0xc228 targets 0xc0fc and is always taken.
  The `beq` branch at 0xc230 targets 0xc0fc and is always taken.
  The `beq` branch at 0xc254 targets 0xba4c and is always taken.
  The `beq` branch at 0xc290 targets 0xbb4c and is always taken.
  The return at 0xb7ec has v0 = one of 0x0, 0x1, 0x13, 0x16.

- `pcibr_find_capability` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xc298 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xc298-0xc370 (216 bytes).
  It occupies 216 bytes.
  The `jal` at 0xc2b4 calls do_pcibr_config_get with a0=a0 at entry (arg0), a1=0x6, a2=0x2, a3=a3 at entry (arg3).
  The `jal` at 0xc2d8 calls do_pcibr_config_get with a0=a0 at entry (arg0), a1=0x34, a2=0x1, a3=?.
  The `jal` at 0xc300 calls do_pcibr_config_get with a0=a0 at entry (arg0), a1=?, a2=0x1, a3=?.
  The `jal` at 0xc328 calls do_pcibr_config_get with a0=a0 at entry (arg0), a1=?, a2=0x1, a3=?.
  The `beq` branch at 0xc2c8 targets 0xc368, is taken when (v0(=ret(do_pcibr_config_get)) & 0x10) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0x10) != 0.
  The `beq` branch at 0xc2e8 targets 0xc360, is taken when (v0(=ret(do_pcibr_config_get)) & 0xfc) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0xfc) != 0.
  The `beq` branch at 0xc2f0 targets 0xc324 and is always taken.
  The `beq` branch at 0xc310 targets 0xc360, is taken when (v0(=ret(do_pcibr_config_get)) & 0xfc) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0xfc) != 0.
  The `beq` branch at 0xc31c targets 0xc360, is taken when s2(?) >= 0x31 (signed), and falls through when s2(?) < 0x31 (signed).
  The `bne` branch at 0xc334 targets 0xc2f8, is taken when s3(=a1) != t9(=(ret(do_pcibr_config_get) << 0x0)), and falls through when s3(=a1) == t9(=(ret(do_pcibr_config_get) << 0x0)).
  The `beq` branch at 0xc360 targets 0xc344 and is always taken.
  The `beq` branch at 0xc368 targets 0xc348 and is always taken.
  The return at 0xc358 has v0 = one of ?, 0x0.

- `pcibr_slot_info_free` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xc370 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xc370-0xc3f8 (136 bytes).
  It occupies 136 bytes.
  The `lbu` at 0xc390 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xc3c8 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xc3e8 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `sw` at 0xc3ec stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `jal` at 0xc380 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc3d0 calls pcibr_device_info_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a4=0x16.
  The `jal` at 0xc3e4 calls kmem_free with a0=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8, a1=([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272] << 0x3), a2=?, a3=?.
  The `beq` branch at 0xc388 targets 0xc3a4, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0xc39c targets 0xc3b8, is taken when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xc3f0 targets 0xc3a4 and is always taken.
  The return at 0xc3b0 has v0 = one of 0x0, 0x16.

- `pcibr_slot_pcix_rbar_init` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xc3f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xc3f8-0xc770 (888 bytes).
  It occupies 888 bytes.
  The `lbu` at 0xc410 loads 1 byte from a0 (arg0 at entry) +0x39.
  The `lw` at 0xc44c loads 4 bytes from (a0 + (a1 << 0x7)) +0x110.
  The `ld` at 0xc458 loads 8 bytes from (a0 + (a1 << 0x7)) +0x118.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0xc470, `lh` at 0xc68c.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xc48c, `lw` at 0xc49c, `lw` at 0xc524.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x518, including `lw` at 0xc4dc, `lw` at 0xc62c, `lw` at 0xc6bc.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x514, including `lw` at 0xc4e8, `lw` at 0xc638, `lw` at 0xc6c8.
  5 such `lw` accesses load 4 bytes from table(sym(max_splittrans_to_numbuf)) +0x0, including `lw` at 0xc508, `lw` at 0xc514, `lw` at 0xc59c.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xc544, `ld` at 0xc564.
  6 such `lw` accesses load 4 bytes from ?, including `lw` at 0xc558, `lw` at 0xc578, `lw` at 0xc5c4.
  3 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0xc570, `lhu` at 0xc650, `lhu` at 0xc6e0.
  The `lw` at 0xc574 loads 4 bytes from a0 (arg0 at entry) +0x510.
  4 such `sh` accesses store 2 bytes to ?, including `sh` at 0xc624, `sh` at 0xc66c, `sh` at 0xc6b4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x518, including `sw` at 0xc640, `sw` at 0xc6d0.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x514, including `sw` at 0xc648, `sw` at 0xc6d8.
  The `ld` at 0xc76c loads 8 bytes from [(a0 + (a1 << 0x7))+280]:8 +0x0.
  The `jal` at 0xc490 calls pcibr_debug with a0=0x40, a1=[a0+4], a2=sym(.rodata)+10664, a3=?.
  The `jal` at 0xc4a0 calls pcibr_debug with a0=0x40, a1=[a0+4], a2=sym(.rodata)+10664, a3=?.
  The `jal` at 0xc510 calls sprintf with a0=sp-352, a1=sym(.rodata)+10664, a2=?, a3=?, a4=entry(sym(max_splittrans_to_numbuf)), a5=entry(sym(max_splittrans_to_numbuf)), a6=[a0+1300], a7=[a0+1304].
  The `jal` at 0xc528 calls pcibr_debug with a0=0x40, a1=[a0+4], a2=sym(.rodata)+10664, a3=sp-352.
  The `beq` branch at 0xc444 targets 0xc740, is taken when a1 >= at(=[a0+57]:1+1) (signed), and falls through when a1 < at(=[a0+57]:1+1) (signed).
  The `blez` branch at 0xc450 targets 0xc750, is taken when s6(=[(a0 + (a1 << 0x7))+272]) <= 0 (signed), and falls through when s6(=[(a0 + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xc45c targets 0xc758, is taken when s3(=[(a0 + (a1 << 0x7))+280]:8) == 0, and falls through when s3(=[(a0 + (a1 << 0x7))+280]:8) != 0.
  The `beq` branch at 0xc468 targets 0xc748, is taken when v0(=0xff) == a1, and falls through when v0(=0xff) != a1.
  The `beq` branch at 0xc478 targets 0xc484, is taken when v1(=[a0+114]:2) == a0(=0x2), and falls through when v1(=[a0+114]:2) != a0(=0x2).
  The `blez` branch at 0xc4a8 targets 0xc710, is taken when s6(=[(a0 + (a1 << 0x7))+272]) <= 0 (signed), and falls through when s6(=[(a0 + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xc4c8 targets 0xc760 and is always taken.
  The `beq` branch at 0xc53c targets 0xc70c, is taken when s2(?) >= s6(=[(a0 + (a1 << 0x7))+272]) (signed), and falls through when s2(?) < s6(=[(a0 + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xc550 targets 0xc530, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xc55c targets 0xc530, is taken when a5(?) == s5(=-0x1), and falls through when a5(?) != s5(=-0x1).
  The `beq` branch at 0xc568 targets 0xc530, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xc588 targets 0xc6a0, is taken when a7(=[a0+1296]) >= 0x64 (signed), and falls through when a7(=[a0+1296]) < 0x64 (signed).
  The `bne` branch at 0xc5cc targets 0xc610, is taken when a2(?) < a6(?) (signed), and falls through when a2(?) >= a6(?) (signed).
  The `beq` branch at 0xc5e0 targets 0xc60c, is taken when v0(?) >= 0x7 (signed), and falls through when v0(?) < 0x7 (signed).
  The `bne` branch at 0xc5f0 targets 0xc610, is taken when a2(?) < t0(?) (signed), and falls through when a2(?) >= t0(?) (signed).
  The `bne` branch at 0xc604 targets 0xc5c4, is taken when v0(?) < 0x7 (signed), and falls through when v0(?) >= 0x7 (signed).
  The `beq` branch at 0xc67c targets 0xc530, is taken when (v0(=[sym(pcibr_debug_mask)]) & 0x40) == 0, and falls through when (v0(=[sym(pcibr_debug_mask)]) & 0x40) != 0.
  The `beq` branch at 0xc684 targets 0xc704, is taken when v1(=0xff) == s4(=a1), and falls through when v1(=0xff) != s4(=a1).
  The `bne` branch at 0xc690 targets 0xc4d0, is taken when a0(=[a0+114]:2) != a1(=0x2), and falls through when a0(=[a0+114]:2) == a1(=0x2).
  The `beq` branch at 0xc698 targets 0xc4d4 and is always taken.
  The `beq` branch at 0xc6fc targets 0xc670 and is always taken.
  The `beq` branch at 0xc704 targets 0xc4d4 and is always taken.
  The `beq` branch at 0xc740 targets 0xc714 and is always taken.
  The `beq` branch at 0xc748 targets 0xc484 and is always taken.
  The `beq` branch at 0xc750 targets 0xc714 and is always taken.
  The `beq` branch at 0xc758 targets 0xc714 and is always taken.
  The `beq` branch at 0xc768 targets 0xc548 and is always taken.
  The return at 0xc738 has v0 = one of 0x0, 0x16.

- `pcibr_slot_addr_space_init` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xc770 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xc770-0xcdd4 (1636 bytes).
  It occupies 1636 bytes.
  The `lbu` at 0xc798 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xc7b8 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100.
  The `ld` at 0xc7c0 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `lw` at 0xc800 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xc828 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  5 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0xc884, `lh` at 0xc9c8, `lh` at 0xcaa8.
  6 such `lw` accesses load 4 bytes from ?, including `lw` at 0xc8b8, `lw` at 0xc944, `lw` at 0xca64.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xc8c0, `sd` at 0xc8c8, `sd` at 0xcaec.
  6 such `ld` accesses load 8 bytes from ?, including `ld` at 0xc934, `ld` at 0xca4c, `ld` at 0xca50.
  The `ld` at 0xca04 loads 8 bytes from table(sym(pci_space)) +0x0.
  The `jal` at 0xc784 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc870 calls do_pcibr_config_set with a0=?, a1=0x0, a2=0x4, a3=ret(pcibr_bus_addr_alloc).
  The `jal` at 0xc8b0 calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=?, a5=ret(pcibr_bus_addr_alloc).
  The `jal` at 0xc8d8 calls do_pcibr_config_get with a0=?, a1=0x4, a2=0x4, a3=?, a4=0x9004.
  The `jal` at 0xc910 calls do_pcibr_config_set with a0=?, a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xc960 calls pcibr_func_config_addr with a0=?, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xc978 calls do_pcibr_config_get with a0=ret(pcibr_func_config_addr), a1=0xe, a2=0x1, a3=?.
  The `jal` at 0xca00 calls sprintf with a0=sp-464, a1=sym(.rodata)+10664, a2=?, a3=?, a5=entry(sym(pci_space)).
  The `jal` at 0xca18 calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=sp-464.
  The `jal` at 0xcacc calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=?, a6=0x4, a7=0xff.
  The `jal` at 0xcae8 calls do_pcibr_config_set with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xcb5c calls sprintf with a0=sp-464, a1=sym(.rodata)+10664, a2=?, a3=?.
  The `jal` at 0xcb74 calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=sp-464.
  The `jal` at 0xcbb4 calls sprintf with a0=sp-464, a1=sym(.rodata)+10664, a2=?, a3=?, a7=0xff.
  The `jal` at 0xcbcc calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=sp-464.
  The `jal` at 0xcc20 calls do_pcibr_config_set with a0=?, a1=0x0, a2=0x4, a3=0xfffff000, a4=one of 0x3, 0x10a9.
  The `jal` at 0xcc30 calls do_pcibr_config_get with a0=?, a1=0x0, a2=0x4, a3=?.
  The `jal` at 0xcc5c calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x5, a3=0x0.
  The `jal` at 0xccb8 calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x2, a3=0x0, a6=0x4, a7=0xff.
  The `jal` at 0xcce4 calls do_pcibr_config_get with a0=?, a1=?, a2=0x4, a3=0xff, a4=[sym(pcibr_debug_mask)], a6=0x4, a7=0xff.
  The `jal` at 0xcd0c calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x5, a3=0x0.
  The `jal` at 0xcd5c calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x4, a3=0x0.
  The `beq` branch at 0xc790 targets 0xcd80, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xc7a4 targets 0xc7e8, is taken when s3(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s3(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xc7c4 targets 0xc7f0, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xc7e8 targets 0xc7d4 and is always taken.
  The `blez` branch at 0xc820 targets 0xcd90, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xc82c targets 0xcd88, is taken when a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8) == 0, and falls through when a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]:8) != 0.
  The `blez` branch at 0xc838 targets 0xcd9c, is taken when a2(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when a2(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xc85c targets 0xcdc8 and is always taken.
  The `beq` branch at 0xc87c targets 0xc894, is taken when a3(=0xff) == s3(=a1), and falls through when a3(=0xff) != s3(=a1).
  The `beq` branch at 0xc888 targets 0xc894, is taken when a4(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when a4(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xc8c4 targets 0xcc90, is taken when a3(?) == a4(=0x9004), and falls through when a3(?) != a4(=0x9004).
  The `beq` branch at 0xc8f4 targets 0xc918, is taken when (a5(?) & a6(?)) == 0, and falls through when (a5(?) & a6(?)) != 0.
  The `beq` branch at 0xc924 targets 0xcd30, is taken when s4(?) >= a4(?) (signed), and falls through when s4(?) < a4(?) (signed).
  The `beq` branch at 0xc93c targets 0xc918, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `beq` branch at 0xc948 targets 0xc91c, is taken when a7(?) == t0(=-0x1), and falls through when a7(?) != t0(=-0x1).
  The `blez` branch at 0xc9a0 targets 0xcbdc, is taken when t1(=one of 0x2, 0x6) <= 0 (signed), and falls through when t1(=one of 0x2, 0x6) > 0 (signed).
  The `beq` branch at 0xc9b0 targets 0xcdb8 and is always taken.
  The `beq` branch at 0xc9b8 targets 0xca24, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xc9c0 targets 0xcc78, is taken when t3(=0xff) == s3(=a1), and falls through when t3(=0xff) != s3(=a1).
  The `beq` branch at 0xc9cc targets 0xc9d8, is taken when t8(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when t8(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xca40 targets 0xcbdc, is taken when s0(?) >= a3(?) (signed), and falls through when s0(?) < a3(?) (signed).
  The `beq` branch at 0xca68 targets 0xca20, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xca74 targets 0xc9b8, is taken when a6(?) >= s1(?) (unsigned), and falls through when a6(?) < s1(?) (unsigned).
  The `beq` branch at 0xca90 targets 0xcca8, is taken when s2(?) == s7(=0x2), and falls through when s2(?) != s7(=0x2).
  The `beq` branch at 0xca98 targets 0xccdc, is taken when s2(?) == a6(=0x4), and falls through when s2(?) != a6(=0x4).
  The `beq` branch at 0xcaa0 targets 0xcab8, is taken when a7(=0xff) == s3(=a1), and falls through when a7(=0xff) != s3(=a1).
  The `beq` branch at 0xcaac targets 0xcab8, is taken when t0(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when t0(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xcb14 targets 0xca20, is taken when (a6(=[sym(pcibr_debug_mask)]) & 0x800) == 0, and falls through when (a6(=[sym(pcibr_debug_mask)]) & 0x800) != 0.
  The `bne` branch at 0xcb1c targets 0xcb84, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0xcb24 targets 0xcc80, is taken when a7(=0xff) == s3(=a1), and falls through when a7(=0xff) != s3(=a1).
  The `beq` branch at 0xcb30 targets 0xcb3c, is taken when t0(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when t0(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xcb7c targets 0xca24 and is always taken.
  The `beq` branch at 0xcb84 targets 0xcc88, is taken when a3(=0xff) == s3(=a1), and falls through when a3(=0xff) != s3(=a1).
  The `beq` branch at 0xcb90 targets 0xcb9c, is taken when a4(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when a4(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xcbd4 targets 0xca24 and is always taken.
  The `bne` branch at 0xcbf4 targets 0xcc08, is taken when a3(?) != a4(=0x10a9), and falls through when a3(?) == a4(=0x10a9).
  The `beq` branch at 0xcc04 targets 0xc8b8, is taken when a3(?) == a4(=0x3), and falls through when a3(?) != a4(=0x3).
  The `beq` branch at 0xcc3c targets 0xc8b8, is taken when (s0(=0xfffff000) & v0(=ret(do_pcibr_config_get))) == 0, and falls through when (s0(=0xfffff000) & v0(=ret(do_pcibr_config_get))) != 0.
  The `bne` branch at 0xcc64 targets 0xc864, is taken when v0(=ret(pcibr_bus_addr_alloc)) != 0, and falls through when v0(=ret(pcibr_bus_addr_alloc)) == 0.
  The `beq` branch at 0xcc70 targets 0xc8b8 and is always taken.
  The `beq` branch at 0xcc78 targets 0xc9d8 and is always taken.
  The `beq` branch at 0xcc80 targets 0xcb3c and is always taken.
  The `beq` branch at 0xcc88 targets 0xcb9c and is always taken.
  The `bne` branch at 0xcc98 targets 0xc8cc, is taken when t9(?) != ra(=0x1160), and falls through when t9(?) == ra(=0x1160).
  The `beq` branch at 0xcca0 targets 0xc8d4 and is always taken.
  The `beq` branch at 0xccd4 targets 0xcad4 and is always taken.
  The `beq` branch at 0xccfc targets 0xcd54, is taken when s7(=0x2) == a6(?), and falls through when s7(=0x2) != a6(?).
  The `beq` branch at 0xcd28 targets 0xcad4 and is always taken.
  The `beq` branch at 0xcd4c targets 0xc7d0 and is always taken.
  The `beq` branch at 0xcd78 targets 0xcad4 and is always taken.
  The `beq` branch at 0xcd80 targets 0xc7d4 and is always taken.
  The `beq` branch at 0xcd88 targets 0xc7d0 and is always taken.
  The `beq` branch at 0xcd94 targets 0xc7d0 and is always taken.
  The `beq` branch at 0xcdb0 targets 0xcd30 and is always taken.
  The `beq` branch at 0xcdc0 targets 0xca4c and is always taken.
  The `beq` branch at 0xcdcc targets 0xc930 and is always taken.
  The return at 0xc7e0 has v0 = one of ?, 0x16.

- `pcibr_slot_device_init` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xcdd4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xcdd4-0xcec8 (244 bytes).
  It occupies 244 bytes.
  The `lbu` at 0xcdfc loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lh` at 0xce34 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `sd` at 0xce68 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x138.
  The `lw` at 0xcea0 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x78.
  The `jal` at 0xcde8 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xce2c calls pcireg_device_get with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xce6c calls pcireg_device_set with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?, a7=0x8000000.
  The `jal` at 0xce8c calls pcibr_debug with a0=0x4000000, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=a1 at entry (arg1), a5=sym(device_bits).
  The `beq` branch at 0xcdf4 targets 0xce10, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0xce08 targets 0xce28, is taken when s1(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s1(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xce4c targets 0xcea0, is taken when v1(=[ret(hwgraph_fastinfo_get)+114]:2) == a1(=0x2), and falls through when v1(=[ret(hwgraph_fastinfo_get)+114]:2) != a1(=0x2).
  The `beq` branch at 0xce98 targets 0xce10 and is always taken.
  The `beq` branch at 0xceb8 targets 0xce54, is taken when (a5(?) & 0x2) == 0, and falls through when (a5(?) & 0x2) != 0.
  The `beq` branch at 0xcec0 targets 0xce58 and is always taken.
  The return at 0xce20 has v0 = one of 0x0, 0x16.

- `pcibr_slot_guest_info_init` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xcec8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xcec8-0xcfdc (276 bytes).
  It occupies 276 bytes.
  The `lbu` at 0xcef4 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xcf10 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  3 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100, including `lw` at 0xcf1c, `lw` at 0xcfb8, `lw` at 0xcfd0.
  The `lbu` at 0xcf28 loads 1 byte from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x104.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x108, including `lw` at 0xcf34, `lw` at 0xcf4c.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + ([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+260]:1 << 0x7)) +0x108, including `lw` at 0xcf44, `lw` at 0xcf50.
  The `sd` at 0xcfa8 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `sw` at 0xcfb4 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `sw` at 0xcfd8 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x108.
  The `jal` at 0xcedc calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xcf40 calls hwgraph_edge_add with a0=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264], a1=[(ret(hwgraph_fastinfo_get) + ([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+260]:1 << 0x7))+264], a2=sym(.rodata)+10664, a3=?, a4=0x0.
  The `jal` at 0xcf54 calls hwgraph_edge_add with a0=[(ret(hwgraph_fastinfo_get) + ([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+260]:1 << 0x7))+264], a1=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264], a2=sym(.rodata)+10664, a3=?.
  The `jal` at 0xcf8c calls kmem_zalloc with a0=0x8, a1=0x0, a2=?, a3=?, a4=0x16.
  The `jal` at 0xcfb0 calls pcibr_device_info_new with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=0xff, a3=-0x1, a4=-0x1, a5=0x1.
  The `jal` at 0xcfc8 calls pciio_device_info_register with a0=a0 at entry (arg0), a1=ret(pcibr_device_info_new), a2=?, a3=?, a4=0x0, a6=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256].
  The `beq` branch at 0xceec targets 0xcf84, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xcf00 targets 0xcf7c, is taken when s2(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `blez` branch at 0xcf14 targets 0xcf8c, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xcf20 targets 0xcf60, is taken when a0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when a0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xcf7c targets 0xcf64 and is always taken.
  The `beq` branch at 0xcf84 targets 0xcf64 and is always taken.
  The `beq` branch at 0xcfbc targets 0xcf60, is taken when a6(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when a6(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xcfd4 targets 0xcf20 and is always taken.
  The return at 0xcf74 has v0 = one of 0x0, 0x16.

- `pcibr_slot_call_device_attach` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xcfdc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xcfdc-0xd218 (572 bytes).
  It occupies 572 bytes.
  The `lbu` at 0xd00c loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xd028 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100.
  The `lw` at 0xd05c loads 4 bytes from ret(hwgraph_fastinfo_get) +0x0.
  The `lw` at 0xd06c loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xd070 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xd0c8, `sw` at 0xd1ac, `sw` at 0xd1d8.
  The `ld` at 0xd0f0 loads 8 bytes from ?.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd100, `lw` at 0xd110, `lw` at 0xd1a0.
  The `lh` at 0xd158 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `jal` at 0xcff4 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd058 calls async_attach_get_info with a0=[ret(hwgraph_fastinfo_get)], a1=?, a2=?, a3=?.
  The `jal` at 0xd0b8 calls pcibr_debug with a0=0x2000, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=?, a5=a2 at entry (arg2), a6=ret(pciio_device_attach).
  The `jal` at 0xd118 calls device_admin_info_get with a0=?, a1=sym(.rodata)+10664, a2=?, a3=?.
  The `jal` at 0xd134 calls async_attach_add_info with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd140 calls pciio_device_attach with a0=?, a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0xd1e8 calls vertex_to_name with a0=?, a1=sp-384, a2=0x100, a3=?.
  The `jal` at 0xd1fc calls cmn_err with a0=0x4, a1=sym(.rodata)+10664, a2=sp-384, a3=?.
  The `beq` branch at 0xd004 targets 0xd034, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xd018 targets 0xd050, is taken when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xd02c targets 0xd058, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xd050 targets 0xd038 and is always taken.
  The `blez` branch at 0xd084 targets 0xd1dc, is taken when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xd094 targets 0xd20c and is always taken.
  The `beq` branch at 0xd0e0 targets 0xd16c, is taken when s2(?) >= a4(?) (signed), and falls through when s2(?) < a4(?) (signed).
  The `beq` branch at 0xd0f8 targets 0xd0d4, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0xd104 targets 0xd0d8, is taken when a7(?) == t0(=-0x1), and falls through when a7(?) != t0(=-0x1).
  The `bne` branch at 0xd120 targets 0xd1e4, is taken when v0(=ret(device_admin_info_get)) != 0, and falls through when v0(=ret(device_admin_info_get)) == 0.
  The `beq` branch at 0xd12c targets 0xd13c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xd150 targets 0xd09c, is taken when a0(=0xff) == s0(=a1), and falls through when a0(=0xff) != s0(=a1).
  The `bne` branch at 0xd15c targets 0xd09c, is taken when a3(=[ret(hwgraph_fastinfo_get)+114]:2) != a4(=0x2), and falls through when a3(=[ret(hwgraph_fastinfo_get)+114]:2) == a4(=0x2).
  The `beq` branch at 0xd164 targets 0xd09c and is always taken.
  The `beq` branch at 0xd170 targets 0xd1bc, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xd180 targets 0xd1b4, is taken when s3(?) == a5(=0x13), and falls through when s3(?) != a5(=0x13).
  The `beq` branch at 0xd188 targets 0xd1b4, is taken when s3(?) == v0(=0x2a), and falls through when s3(?) != v0(=0x2a).
  The `beq` branch at 0xd194 targets 0xd1b4, is taken when s3(?) == a6(=0x1), and falls through when s3(?) != a6(=0x1).
  The `beq` branch at 0xd1b4 targets 0xd034 and is always taken.
  The `beq` branch at 0xd1d4 targets 0xd1b0 and is always taken.
  The `beq` branch at 0xd1dc targets 0xd1b0 and is always taken.
  The `beq` branch at 0xd204 targets 0xd0d8 and is always taken.
  The `beq` branch at 0xd210 targets 0xd0ec and is always taken.
  The return at 0xd048 has v0 = one of ?, 0x16.

- `pcibr_slot_call_device_detach` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xd218 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xd218-0xd478 (608 bytes).
  It occupies 608 bytes.
  The `lbu` at 0xd250 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xd26c loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x100.
  The `lw` at 0xd2ac loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xd2b0 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `sw` at 0xd30c stores 4 bytes to ?.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xd334, `ld` at 0xd360, `ld` at 0xd378.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd344, `lw` at 0xd37c, `lw` at 0xd3a0.
  The `lh` at 0xd350 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x74.
  The `lw` at 0xd36c loads 4 bytes from ret(hwgraph_fastinfo_get) +0x508.
  The `sw` at 0xd374 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x508.
  The `lw` at 0xd38c loads 4 bytes from ret(hwgraph_fastinfo_get) +0x50c.
  The `lw` at 0xd394 loads 4 bytes from table(sym(max_splittrans_to_numbuf)) +0x0.
  The `sw` at 0xd39c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x50c.
  The `lh` at 0xd3c4 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x10c, including `lw` at 0xd40c, `lw` at 0xd448.
  2 such `sw` accesses store 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x10c, including `sw` at 0xd418, `sw` at 0xd45c.
  The `jal` at 0xd234 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd300 calls pcibr_debug with a0=0x4000, a1=a0 at entry (arg0), a2=sym(.rodata)+10664, a3=?, a5=a2 at entry (arg2), a6=ret(pciio_device_detach).
  The `jal` at 0xd3a8 calls pciio_device_detach with a0=?, a1=a2 at entry (arg2), a2=?, a3=?, a5=-0x1.
  The `jal` at 0xd43c calls pcibr_device_unregister with a0=?, a1=-0x1, a2=?, a3=?.
  The `beq` branch at 0xd248 targets 0xd278, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xd25c targets 0xd29c, is taken when s3(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s3(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xd270 targets 0xd2a4, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) == 0, and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+256]) != 0.
  The `beq` branch at 0xd29c targets 0xd27c and is always taken.
  The `blez` branch at 0xd2c4 targets 0xd460, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xd2e0 targets 0xd468 and is always taken.
  The `beq` branch at 0xd324 targets 0xd3d8, is taken when s0(?) >= a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed), and falls through when s0(?) < a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xd33c targets 0xd314, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xd348 targets 0xd318, is taken when a4(?) == a5(=-0x1), and falls through when a4(?) != a5(=-0x1).
  The `beq` branch at 0xd358 targets 0xd3a0, is taken when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xd364 targets 0xd3a0, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xd3bc targets 0xd2ec, is taken when a0(=0xff) == s3(=a1), and falls through when a0(=0xff) != s3(=a1).
  The `bne` branch at 0xd3c8 targets 0xd2e8, is taken when t8(=[ret(hwgraph_fastinfo_get)+114]:2) != t9(=0x2), and falls through when t8(=[ret(hwgraph_fastinfo_get)+114]:2) == t9(=0x2).
  The `beq` branch at 0xd3d0 targets 0xd2ec and is always taken.
  The `beq` branch at 0xd3dc targets 0xd424, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0xd3f4 targets 0xd41c, is taken when s4(?) == ra(=0x13), and falls through when s4(?) != ra(=0x13).
  The `beq` branch at 0xd3fc targets 0xd41c, is taken when s4(?) == v0(=0x2a), and falls through when s4(?) != v0(=0x2a).
  The `beq` branch at 0xd404 targets 0xd41c, is taken when s4(?) == at(=0x1), and falls through when s4(?) != at(=0x1).
  The `beq` branch at 0xd41c targets 0xd278 and is always taken.
  The `beq` branch at 0xd434 targets 0xd444, is taken when a1(=-0x1) == s8(?), and falls through when a1(=-0x1) != s8(?).
  The `beq` branch at 0xd458 targets 0xd41c and is always taken.
  The `beq` branch at 0xd460 targets 0xd41c and is always taken.
  The `beq` branch at 0xd470 targets 0xd330 and is always taken.
  The return at 0xd294 has v0 = one of ?, 0x16.

- `pcibr_slot_detach` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xd478 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xd478-0xd558 (224 bytes).
  It occupies 224 bytes.
  The `sw` at 0xd4f0 stores 4 bytes to a4 (arg4 at entry) +0x0.
  The `lh` at 0xd4fc loads 2 bytes from ret(hwgraph_fastinfo_get) +0x74.
  The `sw` at 0xd50c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x518.
  The `sw` at 0xd510 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x514.
  2 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0xd51c, `lbu` at 0xd53c.
  The `lbu` at 0xd520 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  The `sw` at 0xd52c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x510.
  The `jal` at 0xd498 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd4a8 calls pcibr_is_slot_sys_critical with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xd4d8 calls pcibr_slot_call_device_detach with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xd514 calls pcibr_pcix_rbars_calc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xd534 calls pcibr_slot_pcix_rbar_init with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xd4b0 targets 0xd4d4, is taken when v0(=ret(pcibr_is_slot_sys_critical)) == 0, and falls through when v0(=ret(pcibr_is_slot_sys_critical)) != 0.
  The `beq` branch at 0xd4e0 targets 0xd4fc, is taken when v0(=ret(pcibr_slot_call_device_detach)) == 0, and falls through when v0(=ret(pcibr_slot_call_device_detach)) != 0.
  The `beq` branch at 0xd4e8 targets 0xd4f4, is taken when a0(=a4) == 0, and falls through when a0(=a4) != 0.
  The `beq` branch at 0xd4f4 targets 0xd4bc and is always taken.
  The `beq` branch at 0xd504 targets 0xd550, is taken when (at(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (at(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `bne` branch at 0xd528 targets 0xd550, is taken when v1(=[ret(hwgraph_fastinfo_get)+57]:1) < s1(=[ret(hwgraph_fastinfo_get)+56]:1) (signed), and falls through when v1(=[ret(hwgraph_fastinfo_get)+57]:1) >= s1(=[ret(hwgraph_fastinfo_get)+56]:1) (signed).
  The `beq` branch at 0xd548 targets 0xd534, is taken when a0(=[ret(hwgraph_fastinfo_get)+57]:1) >= s1(?) (signed), and falls through when a0(=[ret(hwgraph_fastinfo_get)+57]:1) < s1(?) (signed).
  The `beq` branch at 0xd550 targets 0xd4bc and is always taken.
  The return at 0xd4cc has v0 = one of 0x0, 0x4, 0x1a.

- `pcibr_is_slot_sys_critical` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xd558 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xd558-0xd668 (272 bytes).
  It occupies 272 bytes.
  The `lbu` at 0xd58c loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xd5a4 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xd5ac loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `ld` at 0xd5cc loads 8 bytes from ?.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd5d8, `lw` at 0xd5e4.
  The `jal` at 0xd564 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd5f0 calls vertex_to_name with a0=?, a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0xd5f8 calls is_sys_critical_vertex with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd658 calls cmn_err with a0=0x4, a1=sym(.rodata)+10664, a2=sp-304, a3=?.
  The `beq` branch at 0xd584 targets 0xd644, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xd59c targets 0xd63c, is taken when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `blez` branch at 0xd5a8 targets 0xd614, is taken when s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xd5b0 targets 0xd5c4 and is always taken.
  The `beq` branch at 0xd5c0 targets 0xd614, is taken when s0(?) >= s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed), and falls through when s0(?) < s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xd5d0 targets 0xd5b8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xd5dc targets 0xd5b8, is taken when v1(?) == s4(=-0x1), and falls through when v1(?) != s4(=-0x1).
  The `bne` branch at 0xd600 targets 0xd64c, is taken when v0(=ret(is_sys_critical_vertex)) != 0, and falls through when v0(=ret(is_sys_critical_vertex)) == 0.
  The `bne` branch at 0xd60c targets 0xd5c8, is taken when s0(?) < s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed), and falls through when s0(?) >= s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xd63c targets 0xd61c and is always taken.
  The `beq` branch at 0xd644 targets 0xd61c and is always taken.
  The `beq` branch at 0xd660 targets 0xd618 and is always taken.
  The return at 0xd634 has v0 = one of 0x0, 0x1, 0x16.

- `pcibr_probe_slot` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xd668 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xd668-0xd688 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0xd674 calls pcibr_probe_work [0xd6d8] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x4, a3=a2 at entry (arg2).
  The return at 0xd680 has v0 = ret(pcibr_probe_work).

- `pcibr_piomap_probe` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xd688 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xd688-0xd6d8 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0xd688 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0xd6b8 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ld` at 0xd6bc loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `ld` at 0xd6c0 loads 8 bytes from [a0+64]:8 +0x8.
  The `jal` at 0xd6c4 calls pcibr_probe_work [0xd6d8] with a0=[[a0+64]:8+8]:8, a1=(a1 + [a0+32]:8), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=-0x1, a7=a0 at entry (arg0).
  The `beq` branch at 0xd6a4 targets 0xd6b8, is taken when at(=[a0+24]:8) >= v1(=(a2 + a1)) (unsigned), and falls through when at(=[a0+24]:8) < v1(=(a2 + a1)) (unsigned).
  The `beq` branch at 0xd6d0 targets 0xd6ac and is always taken.
  The return at 0xd6b0 has v0 = one of -0x1, ret(pcibr_probe_work).

- `pcibr_probe_work` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xd6d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xd6d8-0xd7a4 (204 bytes).
  It occupies 204 bytes.
  The `jal` at 0xd750 calls pcibr_disable_mst_timeout_work [0xd7ec] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x4.
  The `jal` at 0xd764 calls badaddr_val with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0xd778 calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=0x40, a2=?, a3=?.
  The `jal` at 0xd78c calls pcibr_enable_mst_timeout_work [0xd840] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xd700 targets 0xd72c, is taken when a2 == at(=0x1), and falls through when a2 != at(=0x1).
  The `beq` branch at 0xd70c targets 0xd72c, is taken when a2 == v1(=0x2), and falls through when a2 != v1(=0x2).
  The `beq` branch at 0xd714 targets 0xd72c, is taken when a2 == a6(=0x4), and falls through when a2 != a6(=0x4).
  The `beq` branch at 0xd71c targets 0xd72c, is taken when a2 == t0(=0x8), and falls through when a2 != t0(=0x8).
  The `beq` branch at 0xd724 targets 0xd744 and is always taken.
  The `beq` branch at 0xd738 targets 0xd750, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xd784 targets 0xd798, is taken when a0(=(ret(pcibr_disable_mst_timeout_work) << 0x0)) == 0, and falls through when a0(=(ret(pcibr_disable_mst_timeout_work) << 0x0)) != 0.
  The `beq` branch at 0xd79c targets 0xd740 and is always taken.
  The return at 0xd748 has v0 = one of -0x1, ?.

- `pcibr_disable_mst_timeout` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xd7a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xd7a4-0xd7c8 (36 bytes).
  It occupies 36 bytes.
  The `ld` at 0xd7b8 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `jal` at 0xd7ac calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd7b4 calls pcibr_disable_mst_timeout_work [0xd7ec] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=?, a2=?, a3=?.
  The return at 0xd7c0 has v0 = ret(pcibr_disable_mst_timeout_work).

- `pcibr_enable_mst_timeout` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xd7c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xd7c8-0xd7ec (36 bytes).
  It occupies 36 bytes.
  The `ld` at 0xd7dc loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `jal` at 0xd7d0 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd7d8 calls pcibr_enable_mst_timeout_work [0xd840] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=?, a2=?, a3=?.
  The return at 0xd7e4 has v0 = ret(pcibr_enable_mst_timeout_work).

- `pcibr_disable_mst_timeout_work` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xd7ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xd7ec-0xd840 (84 bytes).
  It occupies 84 bytes.
  The `jal` at 0xd7fc calls pcireg_intr_enable_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd80c calls pcireg_intr_enable_bit_clr with a0=a0 at entry (arg0), a1=0x400000800, a2=?, a3=?.
  The `jal` at 0xd814 calls pcireg_intr_enable_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0xd820 targets 0xd830, is taken when s8(=ret(pcireg_intr_enable_get)) != v0(=ret(pcireg_intr_enable_get)), and falls through when s8(=ret(pcireg_intr_enable_get)) == v0(=ret(pcireg_intr_enable_get)).
  The `beq` branch at 0xd828 targets 0xd834 and is always taken.
  The return at 0xd838 has v0 = one of 0x0, 0x1.

- `pcibr_enable_mst_timeout_work` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xd840 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xd840-0xd894 (84 bytes).
  It occupies 84 bytes.
  The `jal` at 0xd850 calls pcireg_intr_enable_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd860 calls pcireg_intr_enable_bit_set with a0=a0 at entry (arg0), a1=0x400000800, a2=?, a3=?.
  The `jal` at 0xd868 calls pcireg_intr_enable_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0xd874 targets 0xd884, is taken when s8(=ret(pcireg_intr_enable_get)) != v0(=ret(pcireg_intr_enable_get)), and falls through when s8(=ret(pcireg_intr_enable_get)) == v0(=ret(pcireg_intr_enable_get)).
  The `beq` branch at 0xd87c targets 0xd888 and is always taken.
  The return at 0xd88c has v0 = one of 0x0, 0x1.

- `pcibr_device_info_free` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xd894 (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xd894-0xdacc (568 bytes).
  It occupies 568 bytes.
  The `lw` at 0xd8d4 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `ld` at 0xd8e4 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xd908, `ld` at 0xd914, `ld` at 0xd980.
  3 such `ld` accesses load 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118, including `ld` at 0xd938, `ld` at 0xd978, `ld` at 0xdac8.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xd94c, `sd` at 0xda40, `sd` at 0xda54.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd9f0, `lw` at 0xd9fc, `lw` at 0xda2c.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0xda14, `sw` at 0xda48.
  The `sw` at 0xda78 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x144.
  The `sw` at 0xda7c stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x148.
  The `sw` at 0xda80 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x14c.
  The `sd` at 0xda88 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x150.
  The `sw` at 0xda8c stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x158.
  The `sw` at 0xda90 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x168.
  The `sw` at 0xda94 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x16c.
  The `sd` at 0xda98 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x170.
  The `sw` at 0xdaa0 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x178.
  The `sd` at 0xdaac stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x160.
  The `jal` at 0xd8b0 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd920 calls pcibr_bus_addr_free with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0xd930 calls mutex_io_spinunlock with a0=ret(hwgraph_fastinfo_get)+128, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xd948 calls pciio_device_info_unregister with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xd950 calls pciio_device_info_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xd95c calls kmem_free with a0=?, a1=0x228, a2=?, a3=?.
  The `jal` at 0xd98c calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+128, a1=?, a2=?, a3=?.
  The `jal` at 0xd9a8 calls pcibr_func_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xd9c0 calls do_pcibr_config_get with a0=ret(pcibr_func_config_addr), a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xd9d8 calls do_pcibr_config_set with a0=ret(pcibr_func_config_addr), a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xd9e8 calls pcibr_bus_addr_free with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0xd8ec targets 0xdabc, is taken when s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) <= 0 (signed), and falls through when s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) > 0 (signed).
  The `beq` branch at 0xd8f4 targets 0xdac4 and is always taken.
  The `bne` branch at 0xd900 targets 0xda20, is taken when s0(?) < 0x6 (signed), and falls through when s0(?) >= 0x6 (signed).
  The `beq` branch at 0xd90c targets 0xd92c, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0xd918 targets 0xd92c, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `beq` branch at 0xd970 targets 0xda58, is taken when s3(?) >= s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed), and falls through when s3(?) < s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272]) (signed).
  The `beq` branch at 0xd984 targets 0xd964, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xd9e0 targets 0xda1c and is always taken.
  The `beq` branch at 0xda10 targets 0xda40, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xda18 targets 0xd908, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0xda30 targets 0xd9e8, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0xda38 targets 0xd8fc and is always taken.
  The `beq` branch at 0xda50 targets 0xda18 and is always taken.
  The `beq` branch at 0xdabc targets 0xda5c and is always taken.
  The `beq` branch at 0xdac4 targets 0xd97c and is always taken.
  The return at 0xdab4 has v0 = one of ?, ret(hwgraph_fastinfo_get).

- `pcibr_bus_addr_alloc` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xdacc (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xdacc-0xdb5c (144 bytes).
  It occupies 144 bytes.
  The `jal` at 0xdb20 calls pciio_device_win_alloc with a0=(a0 + one of 0x848, 0x858, 0x868), a1=?, a2=a3 at entry (arg3), a3=a4 at entry (arg4), a4=a5 at entry (arg5).
  The `beq` branch at 0xdae4 targets 0xdb3c, is taken when a2 == at(=0x2), and falls through when a2 != at(=0x2).
  The `beq` branch at 0xdaec targets 0xdb54, is taken when a2 == t0(=0x4), and falls through when a2 != t0(=0x4).
  The `beq` branch at 0xdaf4 targets 0xdb04, is taken when a2 == t1(=0x5), and falls through when a2 != t1(=0x5).
  The `beq` branch at 0xdafc targets 0xdb30 and is always taken.
  The `bne` branch at 0xdb04 targets 0xdb48, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0xdb40 targets 0xdb0c, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0xdb4c targets 0xdb10 and is always taken.
  The `beq` branch at 0xdb54 targets 0xdb40 and is always taken.
  The return at 0xdb34 has v0 = one of 0x0, ret(pciio_device_win_alloc).

- `pcibr_bus_addr_free` in `IP30/usr/cpu/sysgen/IP30boot/pcibr.o` at 0xdb5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP30/usr/cpu/sysgen/IP30boot/pcibr.o`.
  Range: 0xdb5c-0xdb78 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xdb64 calls pciio_device_win_free with a0=a0+32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xdb70 has v0 = ret(pciio_device_win_free).
