# Readings: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`

One entry per routine, filed here from the reading batches by binary.

- `pcibr_try_set_device` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x0-0x4a4 (1188 bytes).
  It occupies 1188 bytes.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0x14, `lh` at 0x150.
  The `ld` at 0x90 loads 8 bytes from (a0 + (a1 << 0x7)) +0x140.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x150, including `lw` at 0x250, `lw` at 0x32c.
  3 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x14c, including `lw` at 0x27c, `lw` at 0x310, `lw` at 0x3f8.
  3 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x154, including `lw` at 0x290, `lw` at 0x348, `lw` at 0x400.
  The `sw` at 0x318 stores 4 bytes to (a0 + (a1 << 0x7)) +0x14c.
  The `sw` at 0x334 stores 4 bytes to (a0 + (a1 << 0x7)) +0x150.
  The `sw` at 0x350 stores 4 bytes to (a0 + (a1 << 0x7)) +0x154.
  The `sd` at 0x384 stores 8 bytes to (a0 + (a1 << 0x7)) +0x140.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x440, `lw` at 0x474.
  The `jal` at 0x78 calls mutex_spinlock with a0=a0+140, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x364 calls mutex_io_spinunlock with a0=a0+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=0x1100000, a5=0x8f8000.
  The `jal` at 0x37c calls pcireg_device_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=0x1100000, a5=0x8f8000.
  The `jal` at 0x388 calls pcireg_tflush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x394 calls mutex_io_spinunlock with a0=a0+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x3d0 calls mutex_io_spinunlock with a0=a0+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?, a4=[(a0 + (a1 << 0x7))+336].
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
  The `beq` branch at 0x254 targets 0x268, is taken when a4(=[(a0 + (a1 << 0x7))+336]) == 0, and falls through when a4(=[(a0 + (a1 << 0x7))+336]) != 0.
  The `beq` branch at 0x26c targets 0x3f8, is taken when a2(=[a0+114]:2) == t3(=0x1), and falls through when a2(=[a0+114]:2) != t3(=0x1).
  The `beq` branch at 0x274 targets 0x3f8, is taken when a2(=[a0+114]:2) == t1(=0x2), and falls through when a2(=[a0+114]:2) != t1(=0x2).
  The `beq` branch at 0x280 targets 0x290, is taken when t8(=[(a0 + (a1 << 0x7))+332]) == 0, and falls through when t8(=[(a0 + (a1 << 0x7))+332]) != 0.
  The `beq` branch at 0x294 targets 0x494, is taken when a2(=[(a0 + (a1 << 0x7))+340]) == 0, and falls through when a2(=[(a0 + (a1 << 0x7))+340]) != 0.
  The `beq` branch at 0x2ac targets 0x304, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x2c0 targets 0x2e0, is taken when (a2(=0x28000) & a0(?)) == 0, and falls through when (a2(=0x28000) & a0(?)) != 0.
  The `beq` branch at 0x2e8 targets 0x3c8, is taken when (s0(?) & a0(=0x1840000)) == 0, and falls through when (s0(?) & a0(=0x1840000)) != 0.
  The `bne` branch at 0x2fc targets 0x3cc, is taken when (s0(?) & a2(?)) != 0, and falls through when (s0(?) & a2(?)) == 0.
  The `bne` branch at 0x308 targets 0x320, is taken when s3(=a3) != a3(=0x1100000), and falls through when s3(=a3) == a3(=0x1100000).
  The `bne` branch at 0x324 targets 0x33c, is taken when s3(=a3) != a5(=0x8f8000), and falls through when s3(=a3) == a5(=0x8f8000).
  The `bne` branch at 0x340 targets 0x358, is taken when s3(=a3) != t1(=0x898000), and falls through when s3(=a3) == t1(=0x898000).
  The `bne` branch at 0x358 targets 0x374, is taken when s3(?) != t0(=[(a0 + (a1 << 0x7))+320]:8), and falls through when s3(?) == t0(=[(a0 + (a1 << 0x7))+320]:8).
  The `beq` branch at 0x36c targets 0x3a0 and is always taken.
  The `beq` branch at 0x3c8 targets 0x304, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x3d8 targets 0x3a0 and is always taken.
  The `beq` branch at 0x3e4 targets 0x170 and is always taken.
  The `beq` branch at 0x3f0 targets 0x198 and is always taken.
  The `beq` branch at 0x404 targets 0x49c, is taken when a1(=[(a0 + (a1 << 0x7))+332]) == 0, and falls through when a1(=[(a0 + (a1 << 0x7))+332]) != 0.
  The `beq` branch at 0x414 targets 0x420, is taken when a0(=[(a0 + (a1 << 0x7))+340]) == 0, and falls through when a0(=[(a0 + (a1 << 0x7))+340]) != 0.
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

- `pcibr_release_device` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x4a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x4a4-0x554 (176 bytes).
  It occupies 176 bytes.
  The `lw` at 0x500 loads 4 bytes from (a0 + (a1 << 0x7)) +0x14c.
  The `sw` at 0x508 stores 4 bytes to (a0 + (a1 << 0x7)) +0x14c.
  The `lw` at 0x514 loads 4 bytes from (a0 + (a1 << 0x7)) +0x150.
  The `sw` at 0x51c stores 4 bytes to (a0 + (a1 << 0x7)) +0x150.
  The `lw` at 0x528 loads 4 bytes from (a0 + (a1 << 0x7)) +0x154.
  The `sw` at 0x530 stores 4 bytes to (a0 + (a1 << 0x7)) +0x154.
  The `jal` at 0x4c4 calls mutex_spinlock with a0=a0+140, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x540 calls mutex_io_spinunlock with a0=a0+140, a1=(ret(mutex_spinlock) << 0x0), a2=a0+140, a3=?, a5=0x8f8000, a6=(a0 + (a1 << 0x7)), a7=(a0 + (a1 << 0x7)).
  The `bne` branch at 0x4f8 targets 0x50c, is taken when s0(=a2) != at(=0x1100000), and falls through when s0(=a2) == at(=0x1100000).
  The `bne` branch at 0x50c targets 0x520, is taken when s0(=a2) != a5(=0x8f8000), and falls through when s0(=a2) == a5(=0x8f8000).
  The `bne` branch at 0x520 targets 0x538, is taken when s0(=a2) != a1(=0x898000), and falls through when s0(=a2) == a1(=0x898000).
  The return at 0x54c has v0 = ret(mutex_io_spinunlock).

- `pcibr_device_write_gather_flush` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x554 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x554-0x570 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x55c calls pcireg_wrb_flush_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x568 has v0 = ret(pcireg_wrb_flush_get).

- `pcibr_close` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x5a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x5a4-0x5ac (8 bytes).
  It occupies 8 bytes.
  The return at 0x5a4 has v0 = 0x0.

- `pcibr_map` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x5ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
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

- `pcibr_unmap` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x678 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
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

- `pcibr_device_slot_get` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x6f0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
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

- `pcibr_ioctl` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x778 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x778-0x9b4 (572 bytes).
  It occupies 572 bytes.
  The `jal` at 0x790 calls hwgraph_connectpt_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x79c calls hwgraph_fastinfo_get with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0x7a8 calls hwgraph_vertex_unref with a0=ret(hwgraph_connectpt_get), a1=?, a2=?, a3=?.
  The `jal` at 0x808 calls cap_able with a0=0x2000000000, a1=0x7003, a2=?, a3=?.
  The `jal` at 0x81c calls copyin with a0=a2 at entry (arg2), a1=sp-144, a2=0x18, a3=?.
  The `jal` at 0x834 calls cap_able with a0=0x2000000000, a1=?, a2=?, a3=?.
  The `jal` at 0x848 calls copyin with a0=a2 at entry (arg2), a1=sp-56, a2=0x10, a3=?.
  The `jal` at 0x860 calls cap_able with a0=0x2000000000, a1=?, a2=?, a3=?.
  The `jal` at 0x874 calls copyin with a0=a2 at entry (arg2), a1=sp-72, a2=0x10, a3=?.
  The `jal` at 0x88c calls cap_able with a0=0x2000000000, a1=?, a2=?, a3=?.
  The `jal` at 0x8a0 calls copyin with a0=a2 at entry (arg2), a1=sp-96, a2=0x18, a3=?.
  The `jal` at 0x8bc calls cap_able with a0=0x2000000000, a1=0x7003, a2=?, a3=?.
  The `jal` at 0x8d0 calls copyin with a0=a2 at entry (arg2), a1=sp-120, a2=0x18, a3=?.
  The `jal` at 0x910 calls pcibr_device_slot_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x930 calls pcibr_priority_bits_set with a0=?, a1=?, a2=0x1, a3=?.
  The `jal` at 0x940 calls pcibr_device_slot_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x960 calls pcibr_priority_bits_set with a0=?, a1=?, a2=0x0, a3=0xff.
  The `jal` at 0x970 calls pcibr_slot_query with a0=ret(hwgraph_connectpt_get), a1=sp-144, a2=?, a3=?.
  The `jal` at 0x980 calls pcibr_slot_startup with a0=ret(hwgraph_connectpt_get), a1=sp-96, a2=?, a3=?.
  The `jal` at 0x994 calls pcibr_slot_shutdown with a0=ret(hwgraph_connectpt_get), a1=sp-120, a2=?, a3=?.
  The `beq` branch at 0x7b4 targets 0x834, is taken when s0(=a1) == at(=0x6701), and falls through when s0(=a1) != at(=0x6701).
  The `beq` branch at 0x7c0 targets 0x860, is taken when s0(=a1) == v0(=0x6702), and falls through when s0(=a1) != v0(=0x6702).
  The `beq` branch at 0x7cc targets 0x88c, is taken when s0(=a1) == v1(=0x7001), and falls through when s0(=a1) != v1(=0x7001).
  The `beq` branch at 0x7d8 targets 0x8b8, is taken when s0(=a1) == a0(=0x7002), and falls through when s0(=a1) != a0(=0x7002).
  The `beq` branch at 0x7e0 targets 0x804, is taken when s0(=a1) == a1(=0x7003), and falls through when s0(=a1) != a1(=0x7003).
  The `beq` branch at 0x810 targets 0x8e8, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x824 targets 0x970, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x82c targets 0x7e8 and is always taken.
  The `beq` branch at 0x83c targets 0x8f0, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x850 targets 0x910, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x858 targets 0x7e8 and is always taken.
  The `beq` branch at 0x868 targets 0x8f8, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x87c targets 0x940, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x884 targets 0x7ec and is always taken.
  The `beq` branch at 0x894 targets 0x900, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x8a8 targets 0x980, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x8b0 targets 0x7e8 and is always taken.
  The `beq` branch at 0x8c4 targets 0x908, is taken when v0(=ret(cap_able)) == 0, and falls through when v0(=ret(cap_able)) != 0.
  The `beq` branch at 0x8d8 targets 0x990, is taken when v0(=ret(copyin)) == 0, and falls through when v0(=ret(copyin)) != 0.
  The `beq` branch at 0x8e0 targets 0x7ec and is always taken.
  The `beq` branch at 0x8e8 targets 0x7e8 and is always taken.
  The `beq` branch at 0x8f0 targets 0x7e8 and is always taken.
  The `beq` branch at 0x8f8 targets 0x7e8 and is always taken.
  The `beq` branch at 0x900 targets 0x7e8 and is always taken.
  The `beq` branch at 0x908 targets 0x7e8 and is always taken.
  The `beq` branch at 0x91c targets 0x9a4, is taken when v0(=ret(pcibr_device_slot_get)) == a1(=0xff), and falls through when v0(=ret(pcibr_device_slot_get)) != a1(=0xff).
  The `beq` branch at 0x924 targets 0x938, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x938 targets 0x7e8 and is always taken.
  The `beq` branch at 0x94c targets 0x9ac, is taken when v0(=ret(pcibr_device_slot_get)) == a3(=0xff), and falls through when v0(=ret(pcibr_device_slot_get)) != a3(=0xff).
  The `beq` branch at 0x954 targets 0x968, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x968 targets 0x7e8 and is always taken.
  The `beq` branch at 0x978 targets 0x7e8 and is always taken.
  The `beq` branch at 0x988 targets 0x7e8 and is always taken.
  The `beq` branch at 0x99c targets 0x7e8 and is always taken.
  The `beq` branch at 0x9a4 targets 0x7e8 and is always taken.
  The `beq` branch at 0x9ac targets 0x7e8 and is always taken.
  The return at 0x7fc has v0 = one of ?, 0xe.

- `pcibr_info_get` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x9b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x9b4-0x9d0 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x9bc calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x9c8 has v0 = ret(pciio_hostinfo_get).

- `pcibr_device_info_new` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x9d0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x9d0-0xaf0 (288 bytes).
  It occupies 288 bytes.
  The `lh` at 0xa20 loads 2 bytes from a0 (arg0 at entry) +0x72.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xa38, `lw` at 0xa50.
  The `sb` at 0xa48 stores 1 byte to ret(kmem_zalloc) +0x21c.
  The `sb` at 0xa5c stores 1 byte to ret(kmem_zalloc) +0x10.
  The `sw` at 0xa8c stores 4 bytes to ?.
  The `lw` at 0xaa0 loads 4 bytes from ((a1 << 0x7) + a0) +0x118.
  The `ld` at 0xab4 loads 8 bytes from ((a1 << 0x7) + a0) +0x120.
  The `sd` at 0xac0 stores 8 bytes to ?.
  The `jal` at 0xa04 calls kmem_zalloc with a0=0x228, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa3c calls pciio_device_info_new with a0=ret(kmem_zalloc), a1=[a0+4], a2=?, a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=a4 at entry (arg4).
  The `jal` at 0xa4c calls pcibr_widget_to_bus with a0=[a0+4], a1=?, a2=?, a3=?.
  The `beq` branch at 0xa18 targets 0xae0, is taken when at(=0xff) == s1(=a1), and falls through when at(=0xff) != s1(=a1).
  The `beq` branch at 0xa24 targets 0xae8, is taken when v0(=[a0+114]:2) == v1(=0x2), and falls through when v0(=[a0+114]:2) != v1(=0x2).
  The `beq` branch at 0xa68 targets 0xac4, is taken when a3(=0xff) == s1(=a1), and falls through when a3(=0xff) != s1(=a1).
  The `bne` branch at 0xa88 targets 0xa70, is taken when a0(?) < 0x4 (signed), and falls through when a0(?) >= 0x4 (signed).
  The `beq` branch at 0xaac targets 0xac4, is taken when v0(?) >= v1(=[((a1 << 0x7) + a0)+280]) (signed), and falls through when v0(?) < v1(=[((a1 << 0x7) + a0)+280]) (signed).
  The `beq` branch at 0xae0 targets 0xa2c and is always taken.
  The `beq` branch at 0xae8 targets 0xa2c and is always taken.
  The return at 0xad8 has v0 = ret(kmem_zalloc).

- `pcibr_device_unregister` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xaf0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xaf0-0xc28 (312 bytes).
  It occupies 312 bytes.
  The `lbu` at 0xb24 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0xb28 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x0.
  The `ld` at 0xb30 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x5f0, including `lw` at 0xb54, `lw` at 0xbb4.
  The `lw` at 0xb68 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x574.
  The `lw` at 0xb6c loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x57c.
  The `lw` at 0xb70 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x570.
  The `lw` at 0xb80 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x530.
  The `lw` at 0xb88 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x578.
  The `sw` at 0xba8 stores 4 bytes to (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x530.
  The `lw` at 0xbbc loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x5f4.
  The `jal` at 0xb00 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb10 calls pciio_info_master_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xb20 calls hwgraph_fastinfo_get with a0=ret(pciio_info_master_get), a1=?, a2=?, a3=?.
  The `jal` at 0xb38 calls xtalk_widgetdev_shutdown with a0=[ret(hwgraph_fastinfo_get)], a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The `jal` at 0xb44 calls pcibr_rrb_flush with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb60 calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+140, a1=?, a2=?, a3=?.
  The `jal` at 0xba4 calls do_pcibr_rrb_free_all with a0=ret(hwgraph_fastinfo_get), a1=?, a2=[ret(pciio_hostinfo_get)+540]:1, a3=?.
  The `jal` at 0xbc4 calls mutex_io_spinunlock with a0=?, a1=?, a2=[(ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1520], a3=?.
  The `jal` at 0xbd4 calls pcibr_rrb_alloc with a0=a0 at entry (arg0), a1=sp-80, a2=sp-76, a3=?.
  The `jal` at 0xbe0 calls pcibr_wrb_flush with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xbf4 calls pcibr_slot_info_free with a0=?, a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The `bltz` branch at 0xb58 targets 0xbdc, is taken when v0(=[(ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1520]) < 0 (signed), and falls through when v0(=[(ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1520]) >= 0 (signed).
  The return at 0xc20 has v0 = ?.

- `pcibr_driver_reg_callback` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xc28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xc28-0xcfc (212 bytes).
  It occupies 212 bytes.
  The `lbu` at 0xc70 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `sw` at 0xcac stores 4 bytes to ret(pcibr_info_get) +0x218.
  The `lw` at 0xcb4 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x114.
  3 such `sw` accesses store 4 bytes to (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x114, including `sw` at 0xcc8, `sw` at 0xcd0, `sw` at 0xcf8.
  The `jal` at 0xc50 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=-0x1.
  The `jal` at 0xc5c calls pcibr_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xc68 calls pciio_info_master_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xc78 calls hwgraph_fastinfo_get with a0=ret(pciio_info_master_get), a1=?, a2=?, a3=?.
  The `jal` at 0xc98 calls mrlock with a0=ret(hwgraph_fastinfo_get)+144, a1=0x2, a2=0x19, a3=?.
  The `jal` at 0xcd4 calls mrunlock with a0=ret(hwgraph_fastinfo_get)+144, a1=?, a2=(ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)), a3=([ret(pciio_hostinfo_get)+540]:1 << 0x7), a7=ret(pcibr_info_get).
  The `beq` branch at 0xc40 targets 0xcdc, is taken when a1 == a6(=-0x1), and falls through when a1 != a6(=-0x1).
  The `beq` branch at 0xc48 targets 0xcdc, is taken when a2 == a6(=-0x1), and falls through when a2 != a6(=-0x1).
  The `beq` branch at 0xcc4 targets 0xcf0, is taken when s0(=a3) == 0, and falls through when s0(=a3) != 0.
  The `beq` branch at 0xcf4 targets 0xcd4 and is always taken.
  The return at 0xce8 has v0 = one of a3, ret(mrunlock).

- `pcibr_driver_unreg_callback` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xcfc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xcfc-0xdd0 (212 bytes).
  It occupies 212 bytes.
  The `lbu` at 0xd44 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `sw` at 0xd80 stores 4 bytes to ret(pcibr_info_get) +0x218.
  The `lw` at 0xd88 loads 4 bytes from (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x114.
  3 such `sw` accesses store 4 bytes to (ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x114, including `sw` at 0xd9c, `sw` at 0xda4, `sw` at 0xdcc.
  The `jal` at 0xd24 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=-0x1.
  The `jal` at 0xd30 calls pcibr_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xd3c calls pciio_info_master_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xd4c calls hwgraph_fastinfo_get with a0=ret(pciio_info_master_get), a1=?, a2=?, a3=?.
  The `jal` at 0xd6c calls mrlock with a0=ret(hwgraph_fastinfo_get)+144, a1=0x2, a2=0x19, a3=?.
  The `jal` at 0xda8 calls mrunlock with a0=ret(hwgraph_fastinfo_get)+144, a1=?, a2=(ret(hwgraph_fastinfo_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)), a3=([ret(pciio_hostinfo_get)+540]:1 << 0x7), a7=ret(pcibr_info_get).
  The `beq` branch at 0xd14 targets 0xdb0, is taken when a1 == a6(=-0x1), and falls through when a1 != a6(=-0x1).
  The `beq` branch at 0xd1c targets 0xdb0, is taken when a2 == a6(=-0x1), and falls through when a2 != a6(=-0x1).
  The `beq` branch at 0xd98 targets 0xdc4, is taken when s0(=a3) == 0, and falls through when s0(=a3) != 0.
  The `beq` branch at 0xdc8 targets 0xda8 and is always taken.
  The return at 0xdbc has v0 = one of a3, ret(mrunlock).

- `pcibr_bus_cnvlink` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xdd0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xdd0-0xeec (284 bytes).
  It occupies 284 bytes.
  The `sb` at 0xe58 stores 1 byte to ret(strstr) +0x0.
  The `jal` at 0xde8 calls pcibr_debug with a0=0x4, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a3 at entry (arg3).
  The `jal` at 0xdf8 calls hwgraph_vertex_name_get with a0=a0 at entry (arg0), a1=sp-320, a2=0x100, a3=?.
  The `jal` at 0xe24 calls hwgraph_traverse with a0=[sym(hwgraph_root)], a1=sp-316, a2=sp-64, a3=?.
  The `jal` at 0xe40 calls strstr with a0=sp-320, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0xe5c calls pcibr_widget_to_bus with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe74 calls strcat with a0=sp-320, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0xe88 calls sprintf with a0=sp-56, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0xea4 calls pcibr_debug with a0=0x4, a1=a0 at entry (arg0), a2=sym(.rodata), a3=sp-320, a4=sp-56.
  The `jal` at 0xeb4 calls hwgraph_path_add with a0=[sym(hwgraph_root)], a1=?, a2=sp-48, a3=?.
  The `jal` at 0xedc calls hwgraph_edge_add with a0=?, a1=?, a2=sp-56, a3=?.
  The `beq` branch at 0xe00 targets 0xe18, is taken when v0(=ret(hwgraph_vertex_name_get)) == 0, and falls through when v0(=ret(hwgraph_vertex_name_get)) != 0.
  The `beq` branch at 0xe2c targets 0xe3c, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0xe34 targets 0xe08 and is always taken.
  The `bne` branch at 0xe48 targets 0xe58, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0xe50 targets 0xe08 and is always taken.
  The `beq` branch at 0xe64 targets 0xecc, is taken when v0(=ret(pcibr_widget_to_bus)) == 0, and falls through when v0(=ret(pcibr_widget_to_bus)) != 0.
  The `beq` branch at 0xebc targets 0xed4, is taken when v0(=ret(hwgraph_path_add)) == 0, and falls through when v0(=ret(hwgraph_path_add)) != 0.
  The `beq` branch at 0xec4 targets 0xe08 and is always taken.
  The `beq` branch at 0xecc targets 0xe08 and is always taken.
  The `beq` branch at 0xee4 targets 0xec4 and is always taken.
  The return at 0xe10 has v0 = one of 0x0, ?.

- `pcibr_detach` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xeec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xeec-0x1080 (404 bytes).
  It occupies 404 bytes.
  2 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0xf7c, `lbu` at 0xfac.
  The `lbu` at 0xf80 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  The `ld` at 0xfcc loads 8 bytes from ret(hwgraph_fastinfo_get) +0x100.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x10, including `ld` at 0xfe4, `ld` at 0xff0.
  The `ld` at 0xff4 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x60.
  The `ld` at 0x1008 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x68.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x830, including `ld` at 0x1020, `ld` at 0x1028.
  The `jal` at 0xf08 calls pcibr_debug with a0=0x8, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a3 at entry (arg3).
  The `jal` at 0xf1c calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-64, a3=?.
  The `jal` at 0xf40 calls hwgraph_fastinfo_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xf50 calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+140, a1=?, a2=?, a3=?.
  The `jal` at 0xf60 calls pcireg_intr_enable_set with a0=ret(hwgraph_fastinfo_get), a1=0x0, a2=?, a3=?.
  The `jal` at 0xf74 calls mutex_io_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xfa4 calls pcibr_slot_detach with a0=?, a1=?, a2=0x0, a3=0x0, a4=0x0.
  The `jal` at 0xfd0 calls pciio_device_info_unregister with a0=?, a1=[ret(hwgraph_fastinfo_get)+256]:8, a2=?, a3=?.
  The `jal` at 0xfd8 calls spinlock_destroy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xfe0 calls strlen with a0=[ret(hwgraph_fastinfo_get)+16]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xfec calls kmem_free with a0=[ret(hwgraph_fastinfo_get)+16]:8, a1=ret(strlen), a2=?, a3=?.
  The `jal` at 0x1000 calls rmfreemap with a0=[ret(hwgraph_fastinfo_get)+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1014 calls rmfreemap with a0=[ret(hwgraph_fastinfo_get)+104]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x101c calls xtalk_intr_disconnect with a0=[ret(hwgraph_fastinfo_get)+2096]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1024 calls xtalk_intr_free with a0=[ret(hwgraph_fastinfo_get)+2096]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x1030 calls kmem_free with a0=ret(hwgraph_fastinfo_get), a1=0xac0, a2=?, a3=?.
  The `jal` at 0x1044 calls hwgraph_info_remove_LBL with a0=?, a1=sym(.rodata), a2=0x0, a3=?.
  The `jal` at 0x105c calls hwgraph_edge_remove with a0=?, a1=sym(.rodata), a2=0x0, a3=?.
  The `jal` at 0x1070 calls hwgraph_edge_remove with a0=a0 at entry (arg0), a1=sym(.rodata), a2=0x0, a3=?.
  The `beq` branch at 0xf24 targets 0xf3c, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0xf8c targets 0xfc8, is taken when s2(=[ret(hwgraph_fastinfo_get)+56]:1) >= a2(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(=[ret(hwgraph_fastinfo_get)+56]:1) < a2(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `bne` branch at 0xfc0 targets 0xf98, is taken when s2(?) < a3(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(?) >= a3(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xff8 targets 0x1008, is taken when a0(=[ret(hwgraph_fastinfo_get)+96]:8) == 0, and falls through when a0(=[ret(hwgraph_fastinfo_get)+96]:8) != 0.
  The `beq` branch at 0x100c targets 0x101c, is taken when a0(=[ret(hwgraph_fastinfo_get)+104]:8) == 0, and falls through when a0(=[ret(hwgraph_fastinfo_get)+104]:8) != 0.
  The `beq` branch at 0x1078 targets 0xf2c and is always taken.
  The return at 0xf34 has v0 = one of 0x0, 0x1.

- `pcibr_directmap_init` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x1080 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x1080-0x11ac (300 bytes).
  It occupies 300 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x1090, `lw` at 0x1184.
  The `lw` at 0x10b4 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x10c4 loads 2 bytes from ?.
  2 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x30, including `lbu` at 0x10f0, `lbu` at 0x10f8.
  The `sb` at 0x1100 stores 1 byte to a0 (arg0 at entry) +0x58.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x50, including `sd` at 0x1114, `sd` at 0x1174.
  The `jal` at 0x1098 calls device_admin_info_get with a0=[a0+4], a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x10d0 calls xtalk_dmatrans_addr with a0=[a0], a1=0x0, a2=?, a3=0x4000, a4=0x0.
  The `jal` at 0x10e0 calls pcireg_dirmap_diroff_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x10ec calls pcireg_dirmap_wid_set with a0=a0 at entry (arg0), a1=[a0+48]:1, a2=?, a3=?.
  The `jal` at 0x1104 calls pcireg_dirmap_add512_clr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=[a0+48]:1, a5=0x20000000.
  The `jal` at 0x112c calls hwgraph_path_to_vertex with a0=ret(device_admin_info_get), a1=?, a2=?, a3=?, a7=0x0.
  The `jal` at 0x1140 calls nodevertex_to_cnodeid with a0=ret(hwgraph_path_to_vertex), a1=?, a2=0x100, a3=?, a7=-0x1.
  The `jal` at 0x1164 calls pcireg_dirmap_add512_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=[a0+48]:1, a5=0x20000000.
  The `jal` at 0x1180 calls vertex_to_name with a0=[a0+4], a1=sp-288, a2=0x100, a3=?.
  The `jal` at 0x119c calls cmn_err with a0=0x4, a1=sym(.rodata), a2=sp-288, a3=sym(.rodata).
  The `bne` branch at 0x10a4 targets 0x112c, is taken when v0(=ret(device_admin_info_get)) != 0, and falls through when v0(=ret(device_admin_info_get)) == 0.
  The `beq` branch at 0x10fc targets 0x1164, is taken when a5(=0x20000000) == s1(=ret(xtalk_dmatrans_addr)), and falls through when a5(=0x20000000) != s1(=ret(xtalk_dmatrans_addr)).
  The `beq` branch at 0x1138 targets 0x117c, is taken when a7(=-0x1) == v0(=ret(hwgraph_path_to_vertex)), and falls through when a7(=-0x1) != v0(=ret(hwgraph_path_to_vertex)).
  The `bne` branch at 0x1154 targets 0x10b0, is taken when a7(?) != t0(=-0x1), and falls through when a7(?) == t0(=-0x1).
  The `beq` branch at 0x115c targets 0x117c and is always taken.
  The `beq` branch at 0x1170 targets 0x1118 and is always taken.
  The `beq` branch at 0x11a4 targets 0x10ac and is always taken.
  The return at 0x1124 has v0 = one of ret(pcireg_dirmap_add512_clr), ret(pcireg_dirmap_add512_set).
  The instructions from 0x1178 to 0x1178 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_asic_rev` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x11ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x11ac-0x1214 (104 bytes).
  It occupies 104 bytes.
  The `jal` at 0x11bc calls hwgraph_traverse with a0=a0 at entry (arg0), a1=sym(.rodata), a2=sp-32, a3=a3 at entry (arg3).
  The `jal` at 0x11e4 calls hwgraph_info_get_LBL with a0=?, a1=sym(.rodata), a2=sp-24, a3=?.
  The `jal` at 0x11f0 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x11c4 targets 0x11dc, is taken when v0(=ret(hwgraph_traverse)) == 0, and falls through when v0(=ret(hwgraph_traverse)) != 0.
  The `beq` branch at 0x11fc targets 0x120c, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x1204 targets 0x11d4 and is always taken.
  The `beq` branch at 0x120c targets 0x11d0 and is always taken.
  The return at 0x11d4 has v0 = one of ?, -0x1.

- `pcibr_write_gather_flush` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x1214 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x1214-0x1250 (60 bytes).
  It occupies 60 bytes.
  The `lbu` at 0x1238 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `jal` at 0x121c calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1228 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1234 calls pcibr_device_write_gather_flush [0x554] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The return at 0x1248 has v0 = 0x0.

- `pcibr_addr_pci_to_xio` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x1250 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x1250-0x1b24 (2260 bytes).
  It occupies 2260 bytes.
  The `lw` at 0x12c8 loads 4 bytes from (ret(pciio_info_mfast_get) + (a1 << 0x7)) +0x108.
  The `lbu` at 0x12d4 loads 1 byte from (ret(pciio_info_mfast_get) + (a1 << 0x7)) +0x10c.
  The `ld` at 0x12e0 loads 8 bytes from (ret(pciio_info_mfast_get) + ([(ret(pciio_info_mfast_get) + (a1 << 0x7))+268]:1 << 0x7)) +0x120.
  The `ld` at 0x12e4 loads 8 bytes from [(ret(pciio_info_mfast_get) + ([(ret(pciio_info_mfast_get) + (a1 << 0x7))+268]:1 << 0x7))+288]:8 +0x0.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x132c, `lw` at 0x13fc, `lw` at 0x1494.
  8 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1338, `ld` at 0x1350, `ld` at 0x13f4.
  The `lbu` at 0x1378 loads 1 byte from ret(pciio_info_mfast_get) +0x39.
  5 such `lw` accesses load 4 bytes from ret(pciio_info_mfast_get) +0x48, including `lw` at 0x14e0, `lw` at 0x17f8, `lw` at 0x1824.
  4 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x72, including `lh` at 0x1590, `lh` at 0x1750, `lh` at 0x1784.
  The `lw` at 0x15dc loads 4 bytes from (ret(pciio_info_mfast_get) + one of 0xaa0, 0xaa4) +0x0.
  4 such `ld` accesses load 8 bytes from table(sym(pci_space)) +0x0, including `ld` at 0x1654, `ld` at 0x173c, `ld` at 0x1960.
  5 such `sw` accesses store 4 bytes to ?, including `sw` at 0x16d4, `sw` at 0x16f8, `sw` at 0x1894.
  The `lw` at 0x1790 loads 4 bytes from ret(pciio_info_mfast_get) +0x78.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x18a0, `sd` at 0x1ab0.
  2 such `sw` accesses store 4 bytes to (ret(pciio_info_mfast_get) + one of 0xaa0, 0xaa4) +0x0, including `sw` at 0x19cc, `sw` at 0x1af0.
  The `jal` at 0x1288 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1294 calls pciio_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x12a8 calls pciio_info_mfast_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x12b8 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+140, a1=?, a2=?, a3=?.
  The `jal` at 0x1544 calls mutex_io_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1650 calls sprintf with a0=sp-736, a1=sym(.rodata), a2=entry(sym(pci_space)), a3=sym(.rodata), a4=sym(.rodata), a5=sym(.rodata), a6=sym(.rodata), a7=sym(.rodata).
  The `jal` at 0x1738 calls sprintf with a0=sp-736, a1=sym(.rodata), a2=entry(sym(pci_space)), a3=?.
  The `jal` at 0x1974 calls sprintf with a0=sp-736, a1=sym(.rodata), a2=entry(sym(pci_space)), a3=?.
  The `jal` at 0x19c4 calls pcireg_control_bit_set with a0=ret(pciio_info_mfast_get), a1=one of 0x400000, 0x800000, a2=?, a3=?, a6=0x2.
  The `jal` at 0x1a08 calls sprintf with a0=sp-736, a1=sym(.rodata), a2=entry(sym(pci_space)), a3=sym(.rodata), a4=sym(.rodata), a7=sym(.rodata).
  The `jal` at 0x1aa8 calls pcireg_device_set with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?, a6=0x2, a7=0xfffff.
  The `jal` at 0x1ab4 calls pcireg_tflush_get with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1ae4 calls pcireg_control_bit_clr with a0=ret(pciio_info_mfast_get), a1=one of 0x400000, 0x800000, a2=?, a3=?, a6=0x2.
  The `beq` branch at 0x12cc targets 0x12ec, is taken when at(=[(ret(pciio_info_mfast_get) + (a1 << 0x7))+264]) == 0, and falls through when at(=[(ret(pciio_info_mfast_get) + (a1 << 0x7))+264]) != 0.
  The `beq` branch at 0x12ec targets 0x1574, is taken when s1(=a2) == 0, and falls through when s1(=a2) != 0.
  The `beq` branch at 0x12f8 targets 0x157c, is taken when s1(=a2) == ra(=0x7), and falls through when s1(=a2) != ra(=0x7).
  The `beq` branch at 0x1300 targets 0x1660, is taken when s1(=a2) == ra(=0x1), and falls through when s1(=a2) != ra(=0x1).
  The `beq` branch at 0x130c targets 0x1374, is taken when a4(?) >= 0x6 (unsigned), and falls through when a4(?) < 0x6 (unsigned).
  The `beq` branch at 0x1330 targets 0x1694, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x1348 targets 0x135c, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x135c targets 0x169c, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x1364 targets 0x1378, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x136c targets 0x1530 and is always taken.
  The `bltz` branch at 0x137c targets 0x1504, is taken when a3(=[ret(pciio_info_mfast_get)+57]:1) < 0 (signed), and falls through when a3(=[ret(pciio_info_mfast_get)+57]:1) >= 0 (signed).
  The `beq` branch at 0x13e0 targets 0x1430 and is always taken.
  The `beq` branch at 0x13e8 targets 0x1408, is taken when s4(?) == s5(?), and falls through when s4(?) != s5(?).
  The `bne` branch at 0x1400 targets 0x1420, is taken when a1(?) != a5(=-0x1), and falls through when a1(?) == a5(=-0x1).
  The `beq` branch at 0x1418 targets 0x1864, is taken when s0(?) == a5(?), and falls through when s0(?) != a5(?).
  The `beq` branch at 0x1428 targets 0x150c, is taken when a4(?) >= t0(=([ret(pciio_info_mfast_get)+57]:1 + [ret(pciio_info_mfast_get)+57]:1)+2) (signed), and falls through when a4(?) < t0(=([ret(pciio_info_mfast_get)+57]:1 + [ret(pciio_info_mfast_get)+57]:1)+2) (signed).
  The `beq` branch at 0x145c targets 0x1468, is taken when s1(?) == a6(=0x2), and falls through when s1(?) != a6(=0x2).
  The `bne` branch at 0x1480 targets 0x1420, is taken when a5(=one of 0x100000, 0x200000) < t1(?) (unsigned), and falls through when a5(=one of 0x100000, 0x200000) >= t1(?) (unsigned).
  The `beq` branch at 0x1490 targets 0x14a0, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x1498 targets 0x13e8, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x14a0 targets 0x1420, is taken when a1(?) != s1(?), and falls through when a1(?) == s1(?).
  The `bne` branch at 0x14bc targets 0x1420, is taken when s0(?) < a3(?) (unsigned), and falls through when s0(?) >= a3(?) (unsigned).
  The `bne` branch at 0x14c4 targets 0x1424, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0x14cc targets 0x17d0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x14d4 targets 0x1424, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x14e4 targets 0x16a4, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0x14fc targets 0x16b8 and is always taken.
  The `beq` branch at 0x150c targets 0x1590, is taken when s1(?) == a5(=0x4), and falls through when s1(?) != a5(=0x4).
  The `beq` branch at 0x1514 targets 0x1590, is taken when s1(?) == a7(=0x5), and falls through when s1(?) != a7(=0x5).
  The `beq` branch at 0x151c targets 0x1750, is taken when s1(?) == t0(=0x6), and falls through when s1(?) != t0(=0x6).
  The `beq` branch at 0x1524 targets 0x1784, is taken when s1(?) == a6(=0x2), and falls through when s1(?) != a6(=0x2).
  The `beq` branch at 0x1574 targets 0x1530 and is always taken.
  The `beq` branch at 0x1580 targets 0x17e0, is taken when (s6(=a5) & 0x1000) == 0, and falls through when (s6(=a5) & 0x1000) != 0.
  The `beq` branch at 0x1588 targets 0x1530 and is always taken.
  The `beq` branch at 0x1594 targets 0x1824, is taken when a3(=[ret(pciio_info_mfast_get)+114]:2) == a6(=0x2), and falls through when a3(=[ret(pciio_info_mfast_get)+114]:2) != a6(=0x2).
  The `bne` branch at 0x15b4 targets 0x1748, is taken when a4(=0x7fffffff) < a5(=table(0x3fffffff)) (unsigned), and falls through when a4(=0x7fffffff) >= a5(=table(0x3fffffff)) (unsigned).
  The `beq` branch at 0x15c4 targets 0x1534, is taken when t0(=-0x1) == s3(?), and falls through when t0(=-0x1) != s3(?).
  The `beq` branch at 0x15cc targets 0x1984, is taken when s1(?) == a6(=0x2), and falls through when s1(?) != a6(=0x2).
  The `beq` branch at 0x15ec targets 0x1534, is taken when s5(=one of 0x1000, 0x2000) == a1(?), and falls through when s5(=one of 0x1000, 0x2000) != a1(?).
  The `beq` branch at 0x15f4 targets 0x19ac, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bgez` branch at 0x1604 targets 0x1658, is taken when t8(=([sym(pcibr_debug_mask)] << 0x24)) >= 0 (signed), and falls through when t8(=([sym(pcibr_debug_mask)] << 0x24)) < 0 (signed).
  The `beq` branch at 0x160c targets 0x1a60, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x1620 targets 0x198c, is taken when (a1(?) & 0x2000) == 0, and falls through when (a1(?) & 0x2000) != 0.
  The `beq` branch at 0x1628 targets 0x1994, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1658 targets 0x1530 and is always taken.
  The `bne` branch at 0x1670 targets 0x1684, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x1684 targets 0x1308, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x168c targets 0x1530 and is always taken.
  The `bne` branch at 0x1694 targets 0x1378, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `beq` branch at 0x169c targets 0x1530 and is always taken.
  The `beq` branch at 0x16d0 targets 0x16fc, is taken when t0(=-0x1) == t1(?), and falls through when t0(=-0x1) != t1(?).
  The `bgez` branch at 0x1704 targets 0x1534, is taken when at(=([sym(pcibr_debug_mask)] << 0x24)) >= 0 (signed), and falls through when at(=([sym(pcibr_debug_mask)] << 0x24)) < 0 (signed).
  The `beq` branch at 0x1740 targets 0x1534 and is always taken.
  The `beq` branch at 0x1748 targets 0x1530 and is always taken.
  The `beq` branch at 0x1754 targets 0x1a20, is taken when a5(=[ret(pciio_info_mfast_get)+114]:2) == a6(=0x2), and falls through when a5(=[ret(pciio_info_mfast_get)+114]:2) != a6(=0x2).
  The `bne` branch at 0x1770 targets 0x181c, is taken when a7(=0xbfffffff) < t0(=table(0x7fffffff)) (unsigned), and falls through when a7(=0xbfffffff) >= t0(=table(0x7fffffff)) (unsigned).
  The `beq` branch at 0x177c targets 0x15c0 and is always taken.
  The `beq` branch at 0x1788 targets 0x1a68, is taken when a2(=[ret(pciio_info_mfast_get)+114]:2) == a6(=0x2), and falls through when a2(=[ret(pciio_info_mfast_get)+114]:2) != a6(=0x2).
  The `beq` branch at 0x179c targets 0x185c, is taken when a3(=0xc0023) >= a4(=[ret(pciio_info_mfast_get)+120]) (signed), and falls through when a3(=0xc0023) < a4(=[ret(pciio_info_mfast_get)+120]) (signed).
  The `bne` branch at 0x17bc targets 0x1a18, is taken when a4(=0x1ffffffff) < a5(=table(0xffffffff)) (unsigned), and falls through when a4(=0x1ffffffff) >= a5(=table(0xffffffff)) (unsigned).
  The `beq` branch at 0x17c8 targets 0x15c0 and is always taken.
  The `bne` branch at 0x17d0 targets 0x1424, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x17d8 targets 0x14e0 and is always taken.
  The `beq` branch at 0x17e4 targets 0x19a4, is taken when t8(=(a3 + a4)) >= 0x101 (unsigned), and falls through when t8(=(a3 + a4)) < 0x101 (unsigned).
  The `beq` branch at 0x1808 targets 0x1adc, is taken when a4(=[ret(pciio_info_mfast_get)+114]:2) == a5(=0x2), and falls through when a4(=[ret(pciio_info_mfast_get)+114]:2) != a5(=0x2).
  The `beq` branch at 0x1814 targets 0x1530 and is always taken.
  The `beq` branch at 0x181c targets 0x1530 and is always taken.
  The `beq` branch at 0x1828 targets 0x1a70, is taken when a1(=[ret(pciio_info_mfast_get)+72]) == 0, and falls through when a1(=[ret(pciio_info_mfast_get)+72]) != 0.
  The `bne` branch at 0x1830 targets 0x1598, is taken when a1(=[ret(pciio_info_mfast_get)+72]) != t0(=0x1), and falls through when a1(=[ret(pciio_info_mfast_get)+72]) == t0(=0x1).
  The `bne` branch at 0x184c targets 0x1748, is taken when t1(=0xffffffff) < t2(=table(0xbfffffff)) (unsigned), and falls through when t1(=0xffffffff) >= t2(=table(0xbfffffff)) (unsigned).
  The `beq` branch at 0x1854 targets 0x15bc and is always taken.
  The `beq` branch at 0x185c targets 0x1530 and is always taken.
  The `beq` branch at 0x1864 targets 0x1ac4, is taken when s1(?) == a6(=0x2), and falls through when s1(?) != a6(=0x2).
  The `beq` branch at 0x1880 targets 0x1ad0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x188c targets 0x1a9c, is taken when ra(?) != v0(?), and falls through when ra(?) == v0(?).
  The `beq` branch at 0x18a8 targets 0x18c8, is taken when s4(?) >= 0x2 (signed), and falls through when s4(?) < 0x2 (signed).
  The `beq` branch at 0x18c0 targets 0x18e0 and is always taken.
  The `beq` branch at 0x18fc targets 0x1928, is taken when a7(=-0x1) == t0(?), and falls through when a7(=-0x1) != t0(?).
  The `bgez` branch at 0x1930 targets 0x1530, is taken when at(=([sym(pcibr_debug_mask)] << 0x24)) >= 0 (signed), and falls through when at(=([sym(pcibr_debug_mask)] << 0x24)) < 0 (signed).
  The `beq` branch at 0x197c targets 0x1534 and is always taken.
  The `beq` branch at 0x1984 targets 0x15d4 and is always taken.
  The `bne` branch at 0x198c targets 0x1630, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x199c targets 0x163c and is always taken.
  The `beq` branch at 0x19a4 targets 0x1530 and is always taken.
  The `beq` branch at 0x19bc targets 0x1ae4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x19d8 targets 0x1534, is taken when (s6(=0x8000000) & t0(=[sym(pcibr_debug_mask)])) == 0, and falls through when (s6(=0x8000000) & t0(=[sym(pcibr_debug_mask)])) != 0.
  The `beq` branch at 0x19e0 targets 0x1af4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1a10 targets 0x1534 and is always taken.
  The `beq` branch at 0x1a18 targets 0x1530 and is always taken.
  The `beq` branch at 0x1a24 targets 0x1b00, is taken when a1(=[ret(pciio_info_mfast_get)+72]) == 0, and falls through when a1(=[ret(pciio_info_mfast_get)+72]) != 0.
  The `bne` branch at 0x1a30 targets 0x175c, is taken when a1(=[ret(pciio_info_mfast_get)+72]) != a7(=0x1), and falls through when a1(=[ret(pciio_info_mfast_get)+72]) == a7(=0x1).
  The `bne` branch at 0x1a50 targets 0x181c, is taken when t0(=0x13fffffff) < t1(=table(0xffffffff)) (unsigned), and falls through when t0(=0x13fffffff) >= t1(=table(0xffffffff)) (unsigned).
  The `beq` branch at 0x1a58 targets 0x177c and is always taken.
  The `beq` branch at 0x1a60 targets 0x161c and is always taken.
  The `beq` branch at 0x1a68 targets 0x1530 and is always taken.
  The `bne` branch at 0x1a8c targets 0x1748, is taken when a2(=0x7fffffff) < a3(=table(0x3fffffff)) (unsigned), and falls through when a2(=0x7fffffff) >= a3(=table(0x3fffffff)) (unsigned).
  The `beq` branch at 0x1a94 targets 0x15bc and is always taken.
  The `beq` branch at 0x1abc targets 0x1894 and is always taken.
  The `beq` branch at 0x1ac8 targets 0x1874 and is always taken.
  The `beq` branch at 0x1ad4 targets 0x188c and is always taken.
  The `beq` branch at 0x1adc targets 0x1814 and is always taken.
  The `beq` branch at 0x1aec targets 0x19d0 and is always taken.
  The `beq` branch at 0x1af8 targets 0x19f4 and is always taken.
  The `bne` branch at 0x1b14 targets 0x181c, is taken when a0(=0xbfffffff) < a1(=table(0x7fffffff)) (unsigned), and falls through when a0(=0xbfffffff) >= a1(=table(0x7fffffff)) (unsigned).
  The `beq` branch at 0x1b1c targets 0x177c and is always taken.
  The return at 0x156c has v0 = ?.

- `pcibr_piomap_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x1b24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x1b24-0x1da0 (636 bytes).
  It occupies 636 bytes.
  The `lbu` at 0x1b6c loads 1 byte from ret(pcibr_info_get) +0x21c.
  The `lw` at 0x1b84 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `ld` at 0x1bd4 loads 8 bytes from ret(pcibr_info_get) +0x210.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1be4, `ld` at 0x1bf0, `ld` at 0x1c84.
  6 such `sw` accesses store 4 bytes to ?, including `sw` at 0x1c18, `sw` at 0x1c3c, `sw` at 0x1c48.
  3 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x72, including `lh` at 0x1c28, `lh` at 0x1c60, `lh` at 0x1cdc.
  9 such `sd` accesses store 8 bytes to ?, including `sd` at 0x1c40, `sd` at 0x1c44, `sd` at 0x1c58.
  The `sb` at 0x1c4c stores 1 byte to ?.
  The `jal` at 0x1b60 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1b74 calls pciio_info_mfast_get with a0=ret(pcibr_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1bac calls pcibr_addr_pci_to_xio [0x1250] with a0=a0 at entry (arg0), a1=[ret(pcibr_info_get)+540]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=a6 at entry (arg6).
  The `jal` at 0x1bcc calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+140, a1=?, a2=?, a3=?.
  The `jal` at 0x1bfc calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x1c08 calls kmem_zalloc with a0=0x60, a1=0x0, a2=?, a3=?.
  The `jal` at 0x1c74 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+140, a1=ret(mutex_spinlock), a2=0xff, a3=?, a4=[ret(pciio_info_mfast_get)+114]:2, a5=a3 at entry (arg3), a6=a2 at entry (arg2).
  The `jal` at 0x1c98 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x1cb8 calls xtalk_piomap_alloc with a0=[ret(pciio_info_mfast_get)], a1=0x0, a2=ret(pcibr_addr_pci_to_xio), a3=a4 at entry (arg4), a4=a5 at entry (arg5).
  The `jal` at 0x1cf0 calls pic_pio_flush_new with a0=?, a1=ret(pcibr_info_get), a2=?, a3=[ret(pciio_info_mfast_get)+114]:2.
  The `jal` at 0x1d60 calls pcibr_debug with a0=0x8000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x1d7c calls pcibr_debug with a0=0x8000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x1d90 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x1b80 targets 0x1d54, is taken when s1(=a4) == 0, and falls through when s1(=a4) != 0.
  The `beq` branch at 0x1b88 targets 0x1d54, is taken when s8(=a5) == 0, and falls through when s8(=a5) != 0.
  The `beq` branch at 0x1bb8 targets 0x1d70, is taken when v0(=ret(pcibr_addr_pci_to_xio)) == at(=-0x1), and falls through when v0(=ret(pcibr_addr_pci_to_xio)) != at(=-0x1).
  The `beq` branch at 0x1bdc targets 0x1bf8, is taken when s0(=[ret(pcibr_info_get)+528]:8) == 0, and falls through when s0(=[ret(pcibr_info_get)+528]:8) != 0.
  The `beq` branch at 0x1be8 targets 0x1d34, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x1bf4 targets 0x1be4, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x1c20 targets 0x1c3c, is taken when s4(=[ret(pcibr_info_get)+540]:1) == a2(=0xff), and falls through when s4(=[ret(pcibr_info_get)+540]:1) != a2(=0xff).
  The `beq` branch at 0x1c30 targets 0x1c3c, is taken when a3(=[ret(pciio_info_mfast_get)+114]:2) == s5(=0x2), and falls through when a3(=[ret(pciio_info_mfast_get)+114]:2) != s5(=0x2).
  The `beq` branch at 0x1c64 targets 0x1d44, is taken when a4(=[ret(pciio_info_mfast_get)+114]:2) == s5(=0x2), and falls through when a4(=[ret(pciio_info_mfast_get)+114]:2) != s5(=0x2).
  The `beq` branch at 0x1c6c targets 0x1c94, is taken when s8(?) == 0, and falls through when s8(?) != 0.
  The `beq` branch at 0x1ca0 targets 0x1cdc, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1cc0 targets 0x1cd4, is taken when v0(=ret(xtalk_piomap_alloc)) == 0, and falls through when v0(=ret(xtalk_piomap_alloc)) != 0.
  The `beq` branch at 0x1ccc targets 0x1cdc and is always taken.
  The `bne` branch at 0x1ce0 targets 0x1d00, is taken when a3(=[ret(pciio_info_mfast_get)+114]:2) != s5(=0x2), and falls through when a3(=[ret(pciio_info_mfast_get)+114]:2) == s5(=0x2).
  The `beq` branch at 0x1ce8 targets 0x1d00, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x1cf8 targets 0x1d8c, is taken when v0(=ret(pic_pio_flush_new)) == 0, and falls through when v0(=ret(pic_pio_flush_new)) != 0.
  The `beq` branch at 0x1d34 targets 0x1bfc, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1d3c targets 0x1c14 and is always taken.
  The `beq` branch at 0x1d4c targets 0x1c6c and is always taken.
  The `beq` branch at 0x1d68 targets 0x1d00 and is always taken.
  The `beq` branch at 0x1d84 targets 0x1d00 and is always taken.
  The `beq` branch at 0x1d98 targets 0x1d00 and is always taken.
  The return at 0x1d2c has v0 = one of ?, 0x0.

- `pcibr_piomap_free` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x1da0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x1da0-0x1df0 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0x1db4 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `sd` at 0x1db8 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `ld` at 0x1dbc loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `sd` at 0x1dc0 stores 8 bytes to a0 (arg0 at entry) +0x30.
  The `lh` at 0x1dc4 loads 2 bytes from [a0+64]:8 +0x72.
  The `sw` at 0x1de0 stores 4 bytes to a0 (arg0 at entry) +0x5c.
  The `sw` at 0x1de4 stores 4 bytes to a0 (arg0 at entry) +0x58.
  The `sd` at 0x1dec stores 8 bytes to a0 (arg0 at entry) +0x50.
  The `jal` at 0x1db0 calls xtalk_piomap_free with a0=[a0+48]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x1dcc targets 0x1de0, is taken when at(=[[a0+64]:8+114]:2) == v0(=0x2), and falls through when at(=[[a0+64]:8+114]:2) != v0(=0x2).
  The `beq` branch at 0x1de8 targets 0x1dd4 and is always taken.
  The return at 0x1dd8 has v0 = 0x2.

- `pcibr_piomap_addr` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x1df0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x1df0-0x1e1c (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0x1df0 loads 8 bytes from a0 (arg0 at entry) +0x28.
  The `ld` at 0x1df4 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x1df8 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `jal` at 0x1e08 calls xtalk_piomap_addr with a0=[a0+48]:8, a1=?, a2=a2 at entry (arg2), a3=[a0+16]:8, a4=[a0+40]:8.
  The return at 0x1e14 has v0 = ret(xtalk_piomap_addr).

- `pcibr_piomap_done` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x1e1c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x1e1c-0x1e38 (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0x1e28 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `jal` at 0x1e24 calls xtalk_piomap_done with a0=[a0+48]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x1e30 has v0 = ret(xtalk_piomap_done).

- `pcibr_piotrans_addr` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x1e38 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x1e38-0x1f04 (204 bytes).
  It occupies 204 bytes.
  The `lbu` at 0x1e6c loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0x1e90 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0x1e64 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1e74 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1e98 calls pcibr_addr_pci_to_xio [0x1250] with a0=a0 at entry (arg0), a1=[ret(pciio_hostinfo_get)+540]:1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1ebc calls xtalk_piotrans_addr with a0=[ret(pciio_info_mfast_get)], a1=0x0, a2=ret(pcibr_addr_pci_to_xio), a3=a4 at entry (arg4).
  The `jal` at 0x1ef4 calls pcibr_debug with a0=0x10000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `beq` branch at 0x1ea4 targets 0x1eec, is taken when v0(=ret(pcibr_addr_pci_to_xio)) == v1(=-0x1), and falls through when v0(=ret(pcibr_addr_pci_to_xio)) != v1(=-0x1).
  The `beq` branch at 0x1efc targets 0x1ec8 and is always taken.
  The return at 0x1ee4 has v0 = one of ret(xtalk_piotrans_addr), 0x0.

- `pcibr_piospace_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x1f04 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x1f04-0x20f8 (500 bytes).
  It occupies 500 bytes.
  2 such `ld` accesses load 8 bytes from ret(pcibr_info_get) +0x1d0, including `ld` at 0x1f5c, `ld` at 0x208c.
  The `lbu` at 0x1f7c loads 1 byte from [ret(pcibr_info_get)+464]:8 +0x8.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x1f80, `ld` at 0x1fa4, `ld` at 0x1fb4.
  The `lbu` at 0x1f8c loads 1 byte from ?.
  The `lw` at 0x1f98 loads 4 bytes from ?.
  The `sb` at 0x1fd0 stores 1 byte to ?.
  The `sd` at 0x207c stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `sd` at 0x2080 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sw` at 0x2084 stores 4 bytes to ret(kmem_zalloc) +0xc.
  The `sb` at 0x2088 stores 1 byte to ret(kmem_zalloc) +0x8.
  The `sd` at 0x2094 stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `sd` at 0x20a0 stores 8 bytes to ret(pcibr_info_get) +0x1d0.
  The `jal` at 0x1f2c calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1f3c calls pciio_info_mfast_get with a0=ret(pcibr_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0x1f54 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+140, a1=?, a2=?, a3=?.
  The `jal` at 0x1fcc calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=a4-1, a3=0x4, a4=0x5.
  The `jal` at 0x1ff8 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=a4-1, a3=0x4, a4=0x5.
  The `jal` at 0x2010 calls pcibr_debug with a0=0x8000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a2 at entry (arg2).
  The `jal` at 0x205c calls pcibr_bus_addr_alloc with a0=ret(pciio_info_mfast_get), a1=0x0, a2=0x5, a3=0x0, a4=(a3 << 0x0), a5=(a4 << 0x0).
  The `jal` at 0x2074 calls kmem_zalloc with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0x209c calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=[ret(pcibr_info_get)+464]:8.
  The `jal` at 0x20b0 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x20c8 calls pcibr_debug with a0=0x8000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a3 at entry (arg3).
  The `jal` at 0x20e8 calls pcibr_bus_addr_alloc with a0=ret(pciio_info_mfast_get), a1=0x0, a2=0x2, a3=0x0, a4=(a3 << 0x0), a5=(a4 << 0x0).
  The `beq` branch at 0x1f70 targets 0x1fdc, is taken when s0(=[ret(pcibr_info_get)+464]:8) == 0, and falls through when s0(=[ret(pcibr_info_get)+464]:8) != 0.
  The `beq` branch at 0x1f78 targets 0x1f90 and is always taken.
  The `beq` branch at 0x1f84 targets 0x1fdc, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x1f90 targets 0x1f80, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0x1f9c targets 0x1f80, is taken when v1(?) != s1(=a2), and falls through when v1(?) == s1(=a2).
  The `bne` branch at 0x1fac targets 0x1f80, is taken when a0(?) < s2(=a3) (unsigned), and falls through when a0(?) >= s2(=a3) (unsigned).
  The `bnel` branch at 0x1fbc targets 0x1f84, is taken when (a5(?) & a2(=a4-1)) != 0, and falls through when (a5(?) & a2(=a4-1)) == 0; its branch-likely delay slot `ld s0,0(s0)` at 0x1fc0 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x1fd4 targets 0x201c and is always taken.
  The `beq` branch at 0x1fdc targets 0x20d8, is taken when s1(=a2) == a1(=0x2), and falls through when s1(=a2) != a1(=0x2).
  The `beq` branch at 0x1fe4 targets 0x204c, is taken when s1(=a2) == a3(=0x4), and falls through when s1(=a2) != a3(=0x4).
  The `beq` branch at 0x1fec targets 0x204c, is taken when s1(=a2) == a4(=0x5), and falls through when s1(=a2) != a4(=0x5).
  The `beq` branch at 0x2068 targets 0x20ac, is taken when s0(=ret(pcibr_bus_addr_alloc)) == 0, and falls through when s0(=ret(pcibr_bus_addr_alloc)) != 0.
  The `beq` branch at 0x20a4 targets 0x201c and is always taken.
  The `beq` branch at 0x20d0 targets 0x201c and is always taken.
  The `beq` branch at 0x20f0 targets 0x2068 and is always taken.
  The return at 0x2040 has v0 = one of ?, 0x0, ret(pcibr_bus_addr_alloc).
  The instructions from 0x2048 to 0x2048 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_piospace_free` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x20f8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x20f8-0x2228 (304 bytes).
  It occupies 304 bytes.
  The `ld` at 0x2120 loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `ld` at 0x2138 loads 8 bytes from ret(pcibr_info_get) +0x1d0.
  The `ld` at 0x2148 loads 8 bytes from [ret(pcibr_info_get)+464]:8 +0x10.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x214c, `ld` at 0x2158, `ld` at 0x2164.
  The `sb` at 0x2184 stores 1 byte to ?.
  The `jal` at 0x2118 calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2130 calls mutex_spinlock with a0=[ret(pcibr_info_get)+40]:8+140, a1=?, a2=?, a3=?.
  The `jal` at 0x2188 calls mutex_io_spinunlock with a0=[ret(pcibr_info_get)+40]:8+140, a1=?, a2=?, a3=?, a6=sym(.rodata).
  The `jal` at 0x21bc calls cmn_err with a0=0x4, a1=sym(.rodata), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=sym(.rodata).
  The `jal` at 0x21c8 calls mutex_io_spinunlock with a0=[ret(pcibr_info_get)+40]:8+140, a1=?, a2=?, a3=?.
  The `jal` at 0x21e0 calls hwgraph_vertex_name_get with a0=a0 at entry (arg0), a1=sp-1088, a2=0x400, a3=?.
  The `jal` at 0x21f0 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x2208 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=sp-1088, a3=a3 at entry (arg3).
  The `jal` at 0x2218 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=?, a3=?.
  The `beq` branch at 0x213c targets 0x2174, is taken when s0(=[ret(pcibr_info_get)+464]:8) == 0, and falls through when s0(=[ret(pcibr_info_get)+464]:8) != 0.
  The `beq` branch at 0x2144 targets 0x215c and is always taken.
  The `beq` branch at 0x2150 targets 0x2174, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x215c targets 0x214c, is taken when t8(?) != s1(=a2), and falls through when t8(?) == s1(=a2).
  The `bne` branch at 0x2168 targets 0x21d8, is taken when t9(?) != s2(=a3), and falls through when t9(?) == s2(=a3).
  The `beq` branch at 0x2174 targets 0x21b0, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x21d0 targets 0x2194 and is always taken.
  The `beq` branch at 0x2220 targets 0x2170 and is always taken.
  The return at 0x21a8 has v0 = ret(mutex_io_spinunlock).

- `pcibr_flags_to_d64` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x2228 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x2228-0x23d4 (428 bytes).
  It occupies 428 bytes.
  The `lh` at 0x22ac loads 2 bytes from a1 (arg1 at entry) +0x72.
  The `lh` at 0x235c loads 2 bytes from a1 (arg1 at entry) +0x74.
  The `jal` at 0x23c4 calls assfail with a0=sym(.rodata), a1=sym(.rodata), a2=0x7d0, a3=a3 at entry (arg3).
  The `bgez` branch at 0x224c targets 0x225c, is taken when t8(=(a0 << 0x26)) >= 0 (signed), and falls through when t8(=(a0 << 0x26)) < 0 (signed).
  The `beq` branch at 0x2254 targets 0x23b8, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x2270 targets 0x228c, is taken when (s0(=a0) & 0x10) == 0, and falls through when (s0(=a0) & 0x10) != 0.
  The `beq` branch at 0x2290 targets 0x22a0, is taken when (s0(=a0) & 0x400) == 0, and falls through when (s0(=a0) & 0x400) != 0.
  The `beq` branch at 0x22a0 targets 0x22ac, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x22c0 targets 0x237c, is taken when a1(=[a1+114]:2) == a5(=0x1), and falls through when a1(=[a1+114]:2) != a5(=0x1).
  The `beq` branch at 0x22c8 targets 0x237c, is taken when a1(=[a1+114]:2) == a4(=0x2), and falls through when a1(=[a1+114]:2) != a4(=0x2).
  The `bgez` branch at 0x22d0 targets 0x22e0, is taken when t0(=(a0 << 0x29)) >= 0 (signed), and falls through when t0(=(a0 << 0x29)) < 0 (signed).
  The `bgez` branch at 0x22e0 targets 0x22ec, is taken when t1(=(a0 << 0x28)) >= 0 (signed), and falls through when t1(=(a0 << 0x28)) < 0 (signed).
  The `bgez` branch at 0x22f0 targets 0x2300, is taken when t3(=(a0 << 0x2d)) >= 0 (signed), and falls through when t3(=(a0 << 0x2d)) < 0 (signed).
  The `bgez` branch at 0x2300 targets 0x2310, is taken when t8(=(a0 << 0x2c)) >= 0 (signed), and falls through when t8(=(a0 << 0x2c)) < 0 (signed).
  The `bgez` branch at 0x2314 targets 0x2320, is taken when a1(=(a0 << 0x2b)) >= 0 (signed), and falls through when a1(=(a0 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0x2334 targets 0x23a8, is taken when a2(=(a0 << 0x2a)) >= 0 (signed), and falls through when a2(=(a0 << 0x2a)) < 0 (signed).
  The `beq` branch at 0x233c targets 0x2350, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bgez` branch at 0x2350 targets 0x235c, is taken when a0(=(a0 << 0x27)) >= 0 (signed), and falls through when a0(=(a0 << 0x27)) < 0 (signed).
  The `beq` branch at 0x2364 targets 0x2370, is taken when (a5(=[a1+116]:2) & 0x1) == 0, and falls through when (a5(=[a1+116]:2) & 0x1) != 0.
  The `beq` branch at 0x2388 targets 0x2394, is taken when (s0(=a0) & 0x1000) == 0, and falls through when (s0(=a0) & 0x1000) != 0.
  The `beq` branch at 0x2398 targets 0x22d0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x23a0 targets 0x22cc and is always taken.
  The `bne` branch at 0x23a8 targets 0x2348, is taken when s2(?) != 0, and falls through when s2(?) == 0.
  The `beq` branch at 0x23b0 targets 0x2350 and is always taken.
  The `beq` branch at 0x23cc targets 0x225c and is always taken.
  The return at 0x2374 has v0 = ?.

- `pcibr_dmamap_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x23d4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x23d4-0x28cc (1272 bytes).
  It occupies 1272 bytes.
  The `lw` at 0x2414 loads 4 bytes from ret(pciio_info_mfast_get) +0x7c.
  The `lw` at 0x2424 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `lbu` at 0x2498 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lbu` at 0x24a0 loads 1 byte from ret(pciio_info_mfast_get) +0x30.
  The `sw` at 0x24a8 stores 4 bytes to ret(kmem_zalloc) +0x4.
  3 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x72, including `lh` at 0x24ac, `lh` at 0x2750, `lh` at 0x27fc.
  The `sb` at 0x24bc stores 1 byte to ret(kmem_zalloc) +0x28.
  The `sd` at 0x24c0 stores 8 bytes to ret(kmem_zalloc) +0x20.
  The `sd` at 0x24c4 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `sd` at 0x24cc stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sb` at 0x24d4 stores 1 byte to ret(kmem_zalloc) +0x8.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x74, including `lh` at 0x250c, `lh` at 0x26a4.
  4 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x0, including `sw` at 0x255c, `sw` at 0x26a0, `sw` at 0x273c.
  The `ld` at 0x2560 loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  6 such `sd` accesses store 8 bytes to ret(kmem_zalloc) +0x38, including `sd` at 0x256c, `sd` at 0x2698, `sd` at 0x274c.
  3 such `sd` accesses store 8 bytes to ret(kmem_zalloc) +0x30, including `sd` at 0x2574, `sd` at 0x269c, `sd` at 0x27b4.
  2 such `lw` accesses load 4 bytes from ret(pciio_info_mfast_get) +0x524, including `lw` at 0x26b4, `lw` at 0x27d8.
  The `lw` at 0x26e4 loads 4 bytes from ?.
  The `ld` at 0x2780 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x140.
  The `sd` at 0x27c0 stores 8 bytes to ret(kmem_zalloc) +0x50.
  The `sw` at 0x27c4 stores 4 bytes to ret(kmem_zalloc) +0x40.
  The `sd` at 0x27c8 stores 8 bytes to ret(kmem_zalloc) +0x48.
  The `sw` at 0x27d0 stores 4 bytes to ret(kmem_zalloc) +0x44.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x70, including `lh` at 0x27ec, `lh` at 0x2850.
  The `lw` at 0x2814 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x570.
  The `lw` at 0x2868 loads 4 bytes from ret(kmem_zalloc) +0x0.
  The `ld` at 0x286c loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  The `sw` at 0x28b4 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x180.
  The `sd` at 0x28c0 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x178.
  The `jal` at 0x23f8 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x240c calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x2430 calls kmem_zalloc with a0=0x60, a1=?, a2=[ret(pciio_info_mfast_get)], a3=[ret(pciio_info_mfast_get)+124].
  The `jal` at 0x2484 calls xtalk_dmamap_alloc with a0=[ret(pciio_info_mfast_get)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x24e8 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=([ret(pciio_info_mfast_get)+124] | a3), a3=0x898000, a4=0xff.
  The `jal` at 0x2504 calls pcibr_debug with a0=0x60000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x2520 calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?, a4=-0x41.
  The `jal` at 0x254c calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x8f8000, a4=one of -0x41, 0xff.
  The `jal` at 0x2598 calls pcibr_ate_alloc with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?, a4=one of -0x41, 0xff.
  The `jal` at 0x25b8 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x1100000.
  The `jal` at 0x25d8 calls pcibr_debug with a0=0x20000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=ret(pcibr_ate_alloc).
  The `jal` at 0x25e8 calls pcibr_ate_free with a0=ret(pciio_info_mfast_get), a1=ret(pcibr_ate_alloc), a2=?, a3=?.
  The `jal` at 0x2600 calls pcibr_debug with a0=0x60000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x2608 calls xtalk_dmamap_free with a0=ret(xtalk_dmamap_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0x2614 calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `jal` at 0x2634 calls pcibr_debug with a0=0x20000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x263c calls xtalk_dmamap_free with a0=ret(xtalk_dmamap_alloc), a1=?, a2=?, a3=?.
  The `jal` at 0x2648 calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `jal` at 0x2674 calls pcibr_debug with a0=0x20000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=?.
  The `jal` at 0x2680 calls kmem_free with a0=ret(kmem_zalloc), a1=0x60, a2=?, a3=?.
  The `jal` at 0x2690 calls pcibr_flags_to_d64 [0x2228] with a0=([ret(pciio_info_mfast_get)+124] | a3), a1=ret(pciio_info_mfast_get), a2=?, a3=?.
  The `jal` at 0x2734 calls pcibr_flags_to_ate with a0=?, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0x27b8 calls pcibr_ate_addr with a0=ret(pciio_info_mfast_get), a1=ret(pcibr_ate_alloc), a2=?, a3=?, a6=[ret(pciio_info_mfast_get)+114]:2.
  The `jal` at 0x2844 calls pcibr_rrb_alloc_more with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?, a6=one of 0x1, 0x2.
  The `jal` at 0x2858 calls pcibr_rrb_alloc_more with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?, a5=0x1, a7=one of 0x1, 0x2.
  The `jal` at 0x2878 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+140, a1=?, a2=?, a3=(0x40000000 | [ret(kmem_zalloc)]).
  The `jal` at 0x288c calls pcibr_slot_config_addr with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x4, a3=?.
  The `jal` at 0x28a0 calls pcibr_slot_config_get with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x4, a3=?.
  The `jal` at 0x28bc calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?, a4=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `bne` branch at 0x2440 targets 0x2478, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x248c targets 0x2668, is taken when v0(=ret(xtalk_dmamap_alloc)) == 0, and falls through when v0(=ret(xtalk_dmamap_alloc)) != 0.
  The `beq` branch at 0x24a4 targets 0x2658, is taken when s3(=[ret(pciio_hostinfo_get)+540]:1) == a4(=0xff), and falls through when s3(=[ret(pciio_hostinfo_get)+540]:1) != a4(=0xff).
  The `beq` branch at 0x24b4 targets 0x2660, is taken when t8(=[ret(pciio_info_mfast_get)+114]:2) == t9(=0x2), and falls through when t8(=[ret(pciio_info_mfast_get)+114]:2) != t9(=0x2).
  The `beq` branch at 0x24d0 targets 0x2534, is taken when (s1(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) == 0, and falls through when (s1(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) != 0.
  The `beq` branch at 0x24f0 targets 0x2690, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0x2514 targets 0x2530, is taken when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0x2528 targets 0x244c and is always taken.
  The `beq` branch at 0x2538 targets 0x2578, is taken when (s1(?) & 0x1) == 0, and falls through when (s1(?) & 0x1) != 0.
  The `bne` branch at 0x2554 targets 0x25f8, is taken when v0(=ret(pcibr_try_set_device)) != 0, and falls through when v0(=ret(pcibr_try_set_device)) == 0.
  The `beq` branch at 0x2570 targets 0x244c and is always taken.
  The `beq` branch at 0x257c targets 0x271c, is taken when (s1(?) & 0x8000) == 0, and falls through when (s1(?) & 0x8000) != 0.
  The `beq` branch at 0x25a4 targets 0x2624, is taken when v0(=ret(pcibr_ate_alloc)) == t0(=-0x1), and falls through when v0(=ret(pcibr_ate_alloc)) != t0(=-0x1).
  The `beq` branch at 0x25c0 targets 0x2734, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0x25f0 targets 0x262c and is always taken.
  The `beq` branch at 0x261c targets 0x244c and is always taken.
  The `beq` branch at 0x2650 targets 0x244c and is always taken.
  The `beq` branch at 0x2658 targets 0x24bc and is always taken.
  The `beq` branch at 0x2660 targets 0x24bc and is always taken.
  The `beq` branch at 0x2688 targets 0x244c and is always taken.
  The `bne` branch at 0x26ac targets 0x2714, is taken when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0, and falls through when (a3(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0.
  The `bne` branch at 0x26c4 targets 0x2714, is taken when (a4(=[ret(pciio_info_mfast_get)+1316]) & a5(?)) != 0, and falls through when (a4(=[ret(pciio_info_mfast_get)+1316]) & a5(?)) == 0.
  The `beq` branch at 0x26ec targets 0x2714, is taken when a6(?) >= 0x2 (signed), and falls through when a6(?) < 0x2 (signed).
  The `bne` branch at 0x270c targets 0x2854, is taken when a6(?) < a7(=one of 0x1, 0x2) (signed), and falls through when a6(?) >= a7(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0x2714 targets 0x2450 and is always taken.
  The `beq` branch at 0x272c targets 0x2594 and is always taken.
  The `beq` branch at 0x2754 targets 0x27b0, is taken when a6(=[ret(pciio_info_mfast_get)+114]:2) == 0, and falls through when a6(=[ret(pciio_info_mfast_get)+114]:2) != 0.
  The `beq` branch at 0x2760 targets 0x277c, is taken when (s1(?) & 0x1000) == 0, and falls through when (s1(?) & 0x1000) != 0.
  The `bgez` branch at 0x2788 targets 0x2798, is taken when a2(=([(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+320]:8 << 0x2b)) >= 0 (signed), and falls through when a2(=([(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+320]:8 << 0x2b)) < 0 (signed).
  The `beq` branch at 0x279c targets 0x27b0, is taken when (s1(?) & 0x2000) == 0, and falls through when (s1(?) & 0x2000) != 0.
  The `beq` branch at 0x27e4 targets 0x2810, is taken when (a6(=[ret(pciio_info_mfast_get)+1316]) & a7(?)) == 0, and falls through when (a6(=[ret(pciio_info_mfast_get)+1316]) & a7(?)) != 0.
  The `bne` branch at 0x27f4 targets 0x2808, is taken when s5(=ret(pcibr_ate_alloc)) < t1(=[ret(pciio_info_mfast_get)+112]:2) (signed), and falls through when s5(=ret(pcibr_ate_alloc)) >= t1(=[ret(pciio_info_mfast_get)+112]:2) (signed).
  The `beq` branch at 0x2800 targets 0x2868, is taken when t2(=[ret(pciio_info_mfast_get)+114]:2) == 0, and falls through when t2(=[ret(pciio_info_mfast_get)+114]:2) != 0.
  The `beq` branch at 0x2808 targets 0x2450 and is always taken.
  The `beq` branch at 0x281c targets 0x27ec, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1392]) >= 0x2 (signed), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1392]) < 0x2 (signed).
  The `beq` branch at 0x2834 targets 0x27ec, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1392]) >= a6(=one of 0x1, 0x2) (signed), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1392]) < a6(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0x284c targets 0x27f0 and is always taken.
  The `beq` branch at 0x2860 targets 0x2714 and is always taken.
  The `beq` branch at 0x28c4 targets 0x2808 and is always taken.
  The return at 0x2470 has v0 = one of ?, ret(kmem_zalloc).

- `pcibr_dmamap_free` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x28cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x28cc-0x29c8 (252 bytes).
  It occupies 252 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x28d4, `ld` at 0x2988.
  The `lbu` at 0x28dc loads 1 byte from a0 (arg0 at entry) +0x8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x28f4, `lw` at 0x295c.
  The `lh` at 0x290c loads 2 bytes from [a0+16]:8 +0x72.
  The `ll` at 0x293c loads 4 bytes from ?.
  The `sc` at 0x2948 stores 4 bytes to ?.
  The `ld` at 0x2958 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `lw` at 0x297c loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `lw` at 0x2990 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `jal` at 0x2954 calls xtalk_dmamap_free with a0=[a0+24]:8, a1=?, a2=?, a3=?, a4=0xffffffff80000000, a5=([a0] << 0x21).
  The `jal` at 0x2974 calls pcibr_release_device with a0=[a0+16]:8, a1=?, a2=0x898000, a3=?.
  The `jal` at 0x298c calls pcibr_ate_free with a0=[a0+16]:8, a1=[a0+64], a2=[a0+68], a3=?.
  The `jal` at 0x299c calls pcibr_release_device with a0=[a0+16]:8, a1=?, a2=0x1100000, a3=?.
  The `jal` at 0x29b0 calls kmem_free with a0=a0 at entry (arg0), a1=0x60, a2=?, a3=?.
  The `beq` branch at 0x2900 targets 0x291c, is taken when a2(=[a0+8]:1) == at(=0xff), and falls through when a2(=[a0+8]:1) != at(=0xff).
  The `beq` branch at 0x2910 targets 0x291c, is taken when v0(=[[a0+16]:8+114]:2) == v1(=0x2), and falls through when v0(=[[a0+16]:8+114]:2) != v1(=0x2).
  The `beq` branch at 0x292c targets 0x2954, is taken when (a3(=[a0]) & a4(=0xffffffff80000000)) == 0, and falls through when (a3(=[a0]) & a4(=0xffffffff80000000)) != 0.
  The `bgez` branch at 0x2934 targets 0x2954, is taken when a5(=([a0] << 0x21)) >= 0 (signed), and falls through when a5(=([a0] << 0x21)) < 0 (signed).
  The `beql` branch at 0x294c targets 0x293c, is taken when a3(=table(-0x1)) == 0, and falls through when a3(=table(-0x1)) != 0; its branch-likely delay slot `nop` at 0x2950 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x2964 targets 0x297c, is taken when (a4(=[a0]) & 0x40) == 0, and falls through when (a4(=[a0]) & 0x40) != 0.
  The `beq` branch at 0x2980 targets 0x29a4, is taken when a2(=[a0+68]) == 0, and falls through when a2(=[a0+68]) != 0.
  The return at 0x29c0 has v0 = ret(kmem_free).

- `pcibr_addr_xio_to_pci` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x29c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x29c8-0x2c50 (648 bytes).
  It occupies 648 bytes.
  The `lh` at 0x29c8 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lbu` at 0x2a40 loads 1 byte from a0 (arg0 at entry) +0x39.
  The `lbu` at 0x2a44 loads 1 byte from a0 (arg0 at entry) +0x38.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x48, including `lw` at 0x2a60, `lw` at 0x2b50.
  The `ld` at 0x2b00 loads 8 bytes from ?.
  The `beq` branch at 0x29e4 targets 0x2b50, is taken when at(=[a0+114]:2) == v1(=0x2), and falls through when at(=[a0+114]:2) != v1(=0x2).
  The `bne` branch at 0x29f4 targets 0x2a18, is taken when a1 < a3(=0x40000000) (unsigned), and falls through when a1 >= a3(=0x40000000) (unsigned).
  The `beq` branch at 0x2a10 targets 0x2bc0, is taken when v1(=0x7fffffff) >= a3(=(a1 + a2)-1) (unsigned), and falls through when v1(=0x7fffffff) < a3(=(a1 + a2)-1) (unsigned).
  The `bne` branch at 0x2a28 targets 0x2a40, is taken when a1 < a3(=0x80000000) (unsigned), and falls through when a1 >= a3(=0x80000000) (unsigned).
  The `beq` branch at 0x2a38 targets 0x2bc8, is taken when a5(=0xbfffffff) >= v1(=(a1 + a2)-1) (unsigned), and falls through when a5(=0xbfffffff) < v1(=(a1 + a2)-1) (unsigned).
  The `beq` branch at 0x2a50 targets 0x2adc, is taken when v0(=[a0+56]:1) >= t3(=[a0+57]:1+1) (signed), and falls through when v0(=[a0+56]:1) < t3(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x2a78 targets 0x2c38 and is always taken.
  The `bne` branch at 0x2a8c targets 0x2aa8, is taken when a1 < a2(?) (unsigned), and falls through when a1 >= a2(?) (unsigned).
  The `blez` branch at 0x2a94 targets 0x2b38, is taken when v0(?) <= 0 (signed), and falls through when v0(?) > 0 (signed).
  The `bne` branch at 0x2aa0 targets 0x2af0, is taken when s0(=(a1 + a2)-1) < a2(?) (unsigned), and falls through when s0(=(a1 + a2)-1) >= a2(?) (unsigned).
  The `beq` branch at 0x2abc targets 0x2adc, is taken when v0(?) >= t3(=[a0+57]:1+1) (signed), and falls through when v0(?) < t3(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x2acc targets 0x2a80, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x2ad4 targets 0x2a84 and is always taken.
  The `beq` branch at 0x2afc targets 0x2b10, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x2b08 targets 0x2b14 and is always taken.
  The `beq` branch at 0x2b24 targets 0x2b30, is taken when (a2(?) & 0x1000) == 0, and falls through when (a2(?) & 0x1000) != 0.
  The `beq` branch at 0x2b30 targets 0x2ae4 and is always taken.
  The `beq` branch at 0x2b48 targets 0x2a9c and is always taken.
  The `beq` branch at 0x2b54 targets 0x2bd0, is taken when a7(=[a0+72]) == 0, and falls through when a7(=[a0+72]) != 0.
  The `bne` branch at 0x2b5c targets 0x29f0, is taken when a7(=[a0+72]) != v0(=0x1), and falls through when a7(=[a0+72]) == v0(=0x1).
  The `bne` branch at 0x2b70 targets 0x2b8c, is taken when a1 < a4(=0xc0000000) (unsigned), and falls through when a1 >= a4(=0xc0000000) (unsigned).
  The `beq` branch at 0x2b84 targets 0x2c30, is taken when a5(=0xffffffff) >= a6(=(a1 + a2)-1) (unsigned), and falls through when a5(=0xffffffff) < a6(=(a1 + a2)-1) (unsigned).
  The `bne` branch at 0x2b98 targets 0x2a40, is taken when a1 < a6(=0x100000000) (unsigned), and falls through when a1 >= a6(=0x100000000) (unsigned).
  The `bne` branch at 0x2bac targets 0x2a40, is taken when a7(=0x13fffffff) < t0(=(a1 + a2)-1) (unsigned), and falls through when a7(=0x13fffffff) >= t0(=(a1 + a2)-1) (unsigned).
  The `beq` branch at 0x2bb8 targets 0x2ae0 and is always taken.
  The `beq` branch at 0x2bc0 targets 0x2ae4 and is always taken.
  The `beq` branch at 0x2bc8 targets 0x2ae4 and is always taken.
  The `bne` branch at 0x2bdc targets 0x2c00, is taken when a1 < v1(=0x40000000) (unsigned), and falls through when a1 >= v1(=0x40000000) (unsigned).
  The `beq` branch at 0x2bf8 targets 0x2c24, is taken when a3(=0x7fffffff) >= a4(=(a1 + a2)-1) (unsigned), and falls through when a3(=0x7fffffff) < a4(=(a1 + a2)-1) (unsigned).
  The `bne` branch at 0x2c00 targets 0x2a40, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x2c14 targets 0x2a40, is taken when a4(=0xbfffffff) < a5(=(a1 + a2)-1) (unsigned), and falls through when a4(=0xbfffffff) >= a5(=(a1 + a2)-1) (unsigned).
  The `beq` branch at 0x2c1c targets 0x2ae0 and is always taken.
  The `beq` branch at 0x2c28 targets 0x2ae0 and is always taken.
  The `beq` branch at 0x2c30 targets 0x2ae0 and is always taken.
  The `beq` branch at 0x2c48 targets 0x2ac8 and is always taken.
  The return at 0x2ae8 has v0 = one of ?, a1+0xffffffffc0000000, a1+0xffffffff80000000.

- `pcibr_dmamap_addr` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x2c50 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x2c50-0x2e28 (472 bytes).
  It occupies 472 bytes.
  The `ld` at 0x2c58 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `lw` at 0x2c60 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0x2c84 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `lbu` at 0x2ca8 loads 1 byte from [a0+16]:8 +0x28.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x38, including `ld` at 0x2cd0, `ld` at 0x2d78, `ld` at 0x2db4.
  The `lbu` at 0x2d10 loads 1 byte from a0 (arg0 at entry) +0x28.
  The `lbu` at 0x2d28 loads 1 byte from [a0+16]:8 +0x58.
  The `ld` at 0x2d34 loads 8 bytes from a0 (arg0 at entry) +0x30.
  The `lw` at 0x2d90 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `ld` at 0x2d98 loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `lw` at 0x2de8 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `lw` at 0x2e14 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x2c80 calls xtalk_dmamap_addr with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x2d60 calls pcibr_addr_xio_to_pci [0x29c8] with a0=[a0+16]:8, a1=?, a2=a2 at entry (arg2), a3=?, a5=-0x1.
  The `jal` at 0x2dec calls ate_write with a0=[a0+16]:8, a1=a0 at entry (arg0), a2=[a0+64], a3=?, a6=[a0+68].
  The `jal` at 0x2e18 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a1 at entry (arg1), a4=(a1 + a2)-1, a6=[a0+68].
  The `beq` branch at 0x2cac targets 0x2d0c, is taken when (v0(=ret(xtalk_dmamap_addr)) & at(=0xf000000000000000)) == 0, and falls through when (v0(=ret(xtalk_dmamap_addr)) & at(=0xf000000000000000)) != 0.
  The `beq` branch at 0x2cc0 targets 0x2d5c, is taken when a0(=[[a0+16]:8+40]:1) == t2(?), and falls through when a0(=[[a0+16]:8+40]:1) != t2(?).
  The `beq` branch at 0x2cc8 targets 0x2d14, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2d0c targets 0x2cc0 and is always taken.
  The `beq` branch at 0x2d20 targets 0x2d90, is taken when (s2(=[a0]) & 0x1) == 0, and falls through when (s2(=[a0]) & 0x1) != 0.
  The `bne` branch at 0x2d2c targets 0x2d70, is taken when at(=[[a0+16]:8+88]:1) != t2(?), and falls through when at(=[[a0+16]:8+88]:1) == t2(?).
  The `bne` branch at 0x2d3c targets 0x2d88, is taken when t1(?) < v0(=[a0+48]:8) (unsigned), and falls through when t1(?) >= v0(=[a0+48]:8) (unsigned).
  The `beq` branch at 0x2d4c targets 0x2d78, is taken when a1(=[a0+48]:8+0x80000000) >= a2(?) (unsigned), and falls through when a1(=[a0+48]:8+0x80000000) < a2(?) (unsigned).
  The `beq` branch at 0x2d54 targets 0x2cec and is always taken.
  The `beq` branch at 0x2d68 targets 0x2ce8 and is always taken.
  The `beq` branch at 0x2d70 targets 0x2ce8 and is always taken.
  The `beq` branch at 0x2d80 targets 0x2ce8 and is always taken.
  The `beq` branch at 0x2d88 targets 0x2cec and is always taken.
  The `bgez` branch at 0x2da4 targets 0x2db4, is taken when a1(=([a0] << 0x2c)) >= 0 (signed), and falls through when a1(=([a0] << 0x2c)) < 0 (signed).
  The `bne` branch at 0x2dc8 targets 0x2dfc, is taken when a6(=[a0+68]) < a5(?) (signed), and falls through when a6(=[a0+68]) >= a5(?) (signed).
  The `beq` branch at 0x2df4 targets 0x2cec and is always taken.
  The `beq` branch at 0x2e20 targets 0x2ce8 and is always taken.
  The return at 0x2d04 has v0 = one of ?, 0x0.

- `pcibr_dmamap_list` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x2e28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x2e28-0x31bc (916 bytes).
  It occupies 916 bytes.
  The `ld` at 0x2e30 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x2e3c loads 8 bytes from a0 (arg0 at entry) +0x18.
  6 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x2e84, `lw` at 0x2fc8, `lw` at 0x30bc.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0x2eec, `lw` at 0x3158.
  The `ld` at 0x2f18 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The `lbu` at 0x2f74 loads 1 byte from [a0+16]:8 +0x28.
  The `lw` at 0x3054 loads 4 bytes from a0 (arg0 at entry) +0x44.
  The `lw` at 0x30e8 loads 4 bytes from a0 (arg0 at entry) +0x40.
  The `ld` at 0x30ec loads 8 bytes from a0 (arg0 at entry) +0x50.
  The `lbu` at 0x30fc loads 1 byte from a0 (arg0 at entry) +0x28.
  The `jal` at 0x2e58 calls xtalk_dmamap_list with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=?, a3=a3 at entry (arg3).
  The `jal` at 0x2e88 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x2ed0 calls alenlist_cursor_init with a0=ret(xtalk_dmamap_list), a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x2f1c calls alenlist_get with a0=ret(xtalk_dmamap_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0x2fb4 calls alenlist_append with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x2fcc calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x2ff0 calls alenlist_get with a0=ret(xtalk_dmamap_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0x300c calls alenlist_cursor_init with a0=?, a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x307c calls ate_write with a0=[a0+16]:8, a1=a0 at entry (arg0), a2=?, a3=?, a6=[a0+68].
  The `jal` at 0x30a8 calls alenlist_replace with a0=?, a1=0x0, a2=sp-144, a3=sp-152.
  The `jal` at 0x30c0 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x30d8 calls alenlist_destroy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3108 calls pcibr_addr_xio_to_pci [0x29c8] with a0=[a0+16]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3124 calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `jal` at 0x3138 calls alenlist_create with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x315c calls alenlist_done with a0=ret(xtalk_dmamap_list), a1=?, a2=?, a3=?.
  The `jal` at 0x3180 calls pcibr_debug with a0=0x10, a1=[a0+4], a2=sym(.rodata), a3=?, a6=[a0+68].
  The `jal` at 0x31ac calls pcibr_debug with a0=0x20000000, a1=[a0+4], a2=sym(.rodata), a3=a0 at entry (arg0).
  The `bne` branch at 0x2e70 targets 0x2ec8, is taken when v0(=ret(xtalk_dmamap_list)) != 0, and falls through when v0(=ret(xtalk_dmamap_list)) == 0.
  The `beq` branch at 0x2ee0 targets 0x3134, is taken when (s8(=a2) & 0x4) == 0, and falls through when (s8(=a2) & 0x4) != 0.
  The `beq` branch at 0x2ef4 targets 0x30e8, is taken when (t8(=[a0]) & 0x40) == 0, and falls through when (t8(=[a0]) & 0x40) != 0.
  The `bne` branch at 0x2f24 targets 0x3000, is taken when v0(=ret(alenlist_get)) != 0, and falls through when v0(=ret(alenlist_get)) == 0.
  The `beq` branch at 0x2f5c targets 0x30f8, is taken when (a3(?) & a0(=0xf000000000000000)) == 0, and falls through when (a3(?) & a0(=0xf000000000000000)) != 0.
  The `beq` branch at 0x2f78 targets 0x3100, is taken when a0(=[[a0+16]:8+40]:1) == v0(?), and falls through when a0(=[[a0+16]:8+40]:1) != v0(?).
  The `beq` branch at 0x2f80 targets 0x301c, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x2f90 targets 0x3094, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x2fa0 targets 0x3098, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `beq` branch at 0x2fbc targets 0x2fdc, is taken when v0(=ret(alenlist_append)) == 0, and falls through when v0(=ret(alenlist_append)) != 0.
  The `beq` branch at 0x2fd4 targets 0x30c8 and is always taken.
  The `beq` branch at 0x2ff8 targets 0x2f40, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0x3000 targets 0x315c, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `beq` branch at 0x3014 targets 0x2e98 and is always taken.
  The `beq` branch at 0x303c targets 0x3190, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x3068 targets 0x316c, is taken when a6(=[a0+68]) < a7(?) (signed), and falls through when a6(=[a0+68]) >= a7(?) (signed).
  The `beq` branch at 0x3094 targets 0x2fa8, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `beq` branch at 0x30b0 targets 0x2fdc, is taken when v0(=ret(alenlist_replace)) == 0, and falls through when v0(=ret(alenlist_replace)) != 0.
  The `beq` branch at 0x30c8 targets 0x2e90, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bne` branch at 0x30d0 targets 0x2e90, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `beq` branch at 0x30e0 targets 0x2e94 and is always taken.
  The `beq` branch at 0x30f0 targets 0x2f04 and is always taken.
  The `beq` branch at 0x30f8 targets 0x2f74 and is always taken.
  The `bne` branch at 0x3110 targets 0x3094, is taken when v0(=ret(pcibr_addr_xio_to_pci)) != 0, and falls through when v0(=ret(pcibr_addr_xio_to_pci)) == 0.
  The `beq` branch at 0x312c targets 0x30c8 and is always taken.
  The `beq` branch at 0x3144 targets 0x319c, is taken when v0(=ret(alenlist_create)) == 0, and falls through when v0(=ret(alenlist_create)) != 0.
  The `bne` branch at 0x314c targets 0x30c8, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x3154 targets 0x2ef0 and is always taken.
  The `beq` branch at 0x3164 targets 0x3008 and is always taken.
  The `beq` branch at 0x3188 targets 0x30c8 and is always taken.
  The `beq` branch at 0x3194 targets 0x3044 and is always taken.
  The `beq` branch at 0x31b4 targets 0x314c and is always taken.
  The return at 0x2ec0 has v0 = one of 0x0, ?.

- `pcibr_dmamap_done` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x31bc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x31bc-0x3260 (164 bytes).
  It occupies 164 bytes.
  The `lw` at 0x31bc loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lbu` at 0x31e0 loads 1 byte from a0 (arg0 at entry) +0x8.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0x31f8, `ld` at 0x321c.
  The `lh` at 0x31fc loads 2 bytes from [a0+16]:8 +0x72.
  The `sw` at 0x3214 stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `ll` at 0x322c loads 4 bytes from ?.
  The `sc` at 0x3238 stores 4 bytes to ?.
  The `ld` at 0x3248 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `jal` at 0x3244 calls xtalk_dmamap_done with a0=[a0+24]:8, a1=?, a2=a0 at entry (arg0), a3=?.
  The `beq` branch at 0x31d4 targets 0x3244, is taken when (a4(=[a0]) & at(=0xffffffff80000000)) == 0, and falls through when (a4(=[a0]) & at(=0xffffffff80000000)) != 0.
  The `beq` branch at 0x31f0 targets 0x320c, is taken when a3(=[a0+8]:1) == v0(=0xff), and falls through when a3(=[a0+8]:1) != v0(=0xff).
  The `beq` branch at 0x3204 targets 0x3258, is taken when v1(=[[a0+16]:8+114]:2) == a0(=0x2), and falls through when v1(=[[a0+16]:8+114]:2) != a0(=0x2).
  The `bgez` branch at 0x3210 targets 0x3244, is taken when a6(?) >= 0 (signed), and falls through when a6(?) < 0 (signed).
  The `beql` branch at 0x323c targets 0x322c, is taken when a5(=table(-0x1)) == 0, and falls through when a5(=table(-0x1)) != 0; its branch-likely delay slot `nop` at 0x3240 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x3258 targets 0x320c and is always taken.
  The return at 0x3250 has v0 = ret(xtalk_dmamap_done).

- `pcibr_get_dmatrans_node` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x3260 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x3260-0x32a0 (64 bytes).
  It occupies 64 bytes.
  The `ld` at 0x3278 loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  The `lh` at 0x3294 loads 2 bytes from table(sym(nasid_to_compact_node)) +0x0.
  The `jal` at 0x3268 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3270 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The return at 0x3298 has v0 = entry(sym(nasid_to_compact_node)).

- `pcibr_dmatrans_addr` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x32a0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x32a0-0x363c (924 bytes).
  It occupies 924 bytes.
  The `lw` at 0x32e4 loads 4 bytes from ret(pciio_info_mfast_get) +0x7c.
  The `lw` at 0x32f4 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `lbu` at 0x32fc loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lbu` at 0x3344 loads 1 byte from ret(pciio_info_mfast_get) +0x28.
  The `ld` at 0x336c loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `lw` at 0x337c loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x74, including `lh` at 0x33dc, `lh` at 0x3514.
  The `ld` at 0x3408 loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  The `lbu` at 0x3420 loads 1 byte from ret(pciio_info_mfast_get) +0x58.
  The `ld` at 0x3440 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `lw` at 0x3450 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x170.
  The `lbu` at 0x3490 loads 1 byte from ret(pciio_info_mfast_get) +0x30.
  The `sd` at 0x350c stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `sw` at 0x3510 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  The `sw` at 0x3534 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x170.
  The `sd` at 0x3538 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  2 such `lw` accesses load 4 bytes from ret(pciio_info_mfast_get) +0x524, including `lw` at 0x353c, `lw` at 0x3594.
  The `lw` at 0x3558 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x570.
  The `ld` at 0x3568 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x140.
  The `lw` at 0x35ec loads 4 bytes from ?.
  The `jal` at 0x32c4 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x32d8 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3300 calls xtalk_dmatrans_addr with a0=[ret(pciio_info_mfast_get)], a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x33cc calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x898000.
  The `jal` at 0x3474 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=0x8f8000, a5=0xffffffff.
  The `jal` at 0x34a4 calls pcibr_addr_xio_to_pci [0x29c8] with a0=ret(pciio_info_mfast_get), a1=?, a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x34d0 calls pcibr_debug with a0=0x40000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a2 at entry (arg2), a4=(a2 + a3)-1, a5=ret(xtalk_dmatrans_addr).
  The `jal` at 0x34f4 calls pcibr_debug with a0=0x40000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a2 at entry (arg2), a4=(a2 + a3)-1.
  The `jal` at 0x3504 calls pcibr_flags_to_d64 [0x2228] with a0=?, a1=ret(pciio_info_mfast_get), a2=?, a3=?.
  The `jal` at 0x35c4 calls pcibr_rrb_alloc_more with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?, a4=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1392], a7=0x1.
  The `jal` at 0x362c calls pcibr_rrb_alloc_more with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?, a6=0x1.
  The `beq` branch at 0x330c targets 0x34b4, is taken when v0(=ret(xtalk_dmatrans_addr)) == 0, and falls through when v0(=ret(xtalk_dmatrans_addr)) != 0.
  The `beq` branch at 0x3320 targets 0x348c, is taken when (v0(=ret(xtalk_dmatrans_addr)) & v1(=0xf000000000000000)) == 0, and falls through when (v0(=ret(xtalk_dmatrans_addr)) & v1(=0xf000000000000000)) != 0.
  The `beq` branch at 0x3328 targets 0x34e0, is taken when v0(=ret(xtalk_dmatrans_addr)) == a0(=-0x1), and falls through when v0(=ret(xtalk_dmatrans_addr)) != a0(=-0x1).
  The `beq` branch at 0x3348 targets 0x34a0, is taken when t8(=[ret(pciio_info_mfast_get)+40]:1) == s4(?), and falls through when t8(=[ret(pciio_info_mfast_get)+40]:1) != s4(?).
  The `beq` branch at 0x3354 targets 0x33fc, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a4)) & 0x40) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a4)) & 0x40) != 0.
  The `bgez` branch at 0x3368 targets 0x3494, is taken when ra(=(([ret(pciio_info_mfast_get)+124] | a4) << 0x26)) >= 0 (signed), and falls through when ra(=(([ret(pciio_info_mfast_get)+124] | a4) << 0x26)) < 0 (signed).
  The `beq` branch at 0x3374 targets 0x33c0, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]:8) == t8(=-0x1), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]:8) != t8(=-0x1).
  The `bne` branch at 0x3380 targets 0x33bc, is taken when t9(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]) != s0(?), and falls through when t9(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]) == s0(?).
  The `beq` branch at 0x33d4 targets 0x3504, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0x33e4 targets 0x33f4, is taken when (a4(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (a4(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0x33ec targets 0x3390 and is always taken.
  The `bne` branch at 0x3404 targets 0x3484, is taken when v0(=0x80000000) < s5(=a3) (unsigned), and falls through when v0(=0x80000000) >= s5(=a3) (unsigned).
  The `bne` branch at 0x3418 targets 0x3484, is taken when s3(?) < a0(=[ret(pciio_info_mfast_get)+80]:8) (unsigned), and falls through when s3(?) >= a0(=[ret(pciio_info_mfast_get)+80]:8) (unsigned).
  The `bne` branch at 0x3424 targets 0x3484, is taken when a3(=[ret(pciio_info_mfast_get)+88]:1) != s4(?), and falls through when a3(=[ret(pciio_info_mfast_get)+88]:1) == s4(?).
  The `bne` branch at 0x3438 targets 0x3484, is taken when v0(=0x80000000) < a4(?) (unsigned), and falls through when v0(=0x80000000) >= a4(?) (unsigned).
  The `beq` branch at 0x3448 targets 0x3464, is taken when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]:8) == a5(=0xffffffff), and falls through when v0(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]:8) != a5(=0xffffffff).
  The `bne` branch at 0x3454 targets 0x3464, is taken when t8(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+368]) != s0(?), and falls through when t8(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+368]) == s0(?).
  The `beq` branch at 0x345c targets 0x3394 and is always taken.
  The `beq` branch at 0x347c targets 0x3534, is taken when v0(=ret(pcibr_try_set_device)) == 0, and falls through when v0(=ret(pcibr_try_set_device)) != 0.
  The `beq` branch at 0x3484 targets 0x3390 and is always taken.
  The `beq` branch at 0x348c targets 0x3344 and is always taken.
  The `beq` branch at 0x3498 targets 0x3370 and is always taken.
  The `beq` branch at 0x34ac targets 0x3390 and is always taken.
  The `beq` branch at 0x34d8 targets 0x3390 and is always taken.
  The `beq` branch at 0x34fc targets 0x3390 and is always taken.
  The `beq` branch at 0x351c targets 0x3594, is taken when (a5(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (a5(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0x352c targets 0x3390 and is always taken.
  The `bne` branch at 0x354c targets 0x358c, is taken when (t8(=[ret(pciio_info_mfast_get)+1316]) & t9(?)) != 0, and falls through when (t8(=[ret(pciio_info_mfast_get)+1316]) & t9(?)) == 0.
  The `beq` branch at 0x3560 targets 0x358c, is taken when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1392]) >= 0x2 (signed), and falls through when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1392]) < 0x2 (signed).
  The `bne` branch at 0x3584 targets 0x35bc, is taken when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1392]) < v0(=one of 0x1, 0x2) (signed), and falls through when a4(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1392]) >= v0(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0x358c targets 0x3390 and is always taken.
  The `beq` branch at 0x35a4 targets 0x35d4, is taken when (t0(=[ret(pciio_info_mfast_get)+1316]) & t1(?)) == 0, and falls through when (t0(=[ret(pciio_info_mfast_get)+1316]) & t1(?)) != 0.
  The `beq` branch at 0x35b4 targets 0x352c and is always taken.
  The `beq` branch at 0x35cc targets 0x358c and is always taken.
  The `beq` branch at 0x35fc targets 0x352c, is taken when a4(?) >= 0x2 (signed), and falls through when a4(?) < 0x2 (signed).
  The `beq` branch at 0x3620 targets 0x352c, is taken when a4(?) >= v0(=one of 0x1, 0x2) (signed), and falls through when a4(?) < v0(=one of 0x1, 0x2) (signed).
  The `beq` branch at 0x3634 targets 0x352c and is always taken.
  The return at 0x33b4 has v0 = ?.

- `pcibr_dmatrans_list` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x363c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x363c-0x3a08 (972 bytes).
  It occupies 972 bytes.
  The `lw` at 0x367c loads 4 bytes from ret(pciio_info_mfast_get) +0x7c.
  The `lbu` at 0x3684 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0x368c loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `ld` at 0x36ac loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `lw` at 0x36bc loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  The `lbu` at 0x37d8 loads 1 byte from ret(pciio_info_mfast_get) +0x28.
  The `sd` at 0x3854 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x158.
  The `sw` at 0x3858 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x160.
  The `ld` at 0x38b4 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `ld` at 0x38c4 loads 8 bytes from ret(pciio_info_mfast_get) +0x50.
  The `lw` at 0x38d4 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x170.
  The `sd` at 0x3954 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x168.
  The `sw` at 0x395c stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x170.
  The `lbu` at 0x3964 loads 1 byte from ret(pciio_info_mfast_get) +0x30.
  The `lbu` at 0x3988 loads 1 byte from ret(pciio_info_mfast_get) +0x58.
  The `jal` at 0x3650 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3668 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x36e0 calls xtalk_dmatrans_list with a0=?, a1=0x0, a2=a2 at entry (arg2), a3=?.
  The `jal` at 0x3700 calls pcibr_release_device with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=one of 0x0, 0x898000, 0x8f8000, a3=?.
  The `jal` at 0x375c calls alenlist_cursor_init with a0=ret(xtalk_dmatrans_list), a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x3794 calls alenlist_get with a0=ret(xtalk_dmatrans_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0x3810 calls alenlist_replace with a0=?, a1=0x0, a2=sp-144, a3=sp-152.
  The `jal` at 0x3830 calls alenlist_get with a0=ret(xtalk_dmatrans_list), a1=0x0, a2=0x0, a3=sp-160, a4=sp-152.
  The `jal` at 0x3868 calls alenlist_cursor_init with a0=?, a1=0x0, a2=0x0, a3=?.
  The `jal` at 0x3888 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=([ret(pciio_info_mfast_get)+124] | a3), a3=0x898000.
  The `jal` at 0x389c calls pcibr_flags_to_d64 [0x2228] with a0=([ret(pciio_info_mfast_get)+124] | a3), a1=ret(pciio_info_mfast_get), a2=?, a3=?.
  The `jal` at 0x38f8 calls pcibr_try_set_device [0x0] with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=([ret(pciio_info_mfast_get)+124] | a3), a3=0x8f8000.
  The `jal` at 0x3924 calls alenlist_destroy with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3938 calls pcibr_addr_xio_to_pci [0x29c8] with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=?.
  The `jal` at 0x39bc calls alenlist_append with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x39d4 calls alenlist_create with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x39f0 calls alenlist_done with a0=ret(xtalk_dmatrans_list), a1=?, a2=?, a3=?.
  The `beq` branch at 0x36a4 targets 0x38b4, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x40) != 0.
  The `beq` branch at 0x36b4 targets 0x387c, is taken when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]:8) == ra(=-0x1), and falls through when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+344]:8) != ra(=-0x1).
  The `bne` branch at 0x36c0 targets 0x3878, is taken when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]) != s0(=([ret(pciio_info_mfast_get)+124] | a3)), and falls through when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+352]) == s0(=([ret(pciio_info_mfast_get)+124] | a3)).
  The `bne` branch at 0x36e8 targets 0x3750, is taken when v0(=ret(xtalk_dmatrans_list)) != 0, and falls through when v0(=ret(xtalk_dmatrans_list)) == 0.
  The `beq` branch at 0x36f4 targets 0x3708, is taken when s4(=one of 0x0, 0x898000, 0x8f8000) == 0, and falls through when s4(=one of 0x0, 0x898000, 0x8f8000) != 0.
  The `beq` branch at 0x3708 targets 0x3718, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0x3710 targets 0x3924, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x3774 targets 0x39d4, is taken when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x4) == 0, and falls through when (s0(=([ret(pciio_info_mfast_get)+124] | a3)) & 0x4) != 0.
  The `bne` branch at 0x379c targets 0x3840, is taken when v0(=ret(alenlist_get)) != 0, and falls through when v0(=ret(alenlist_get)) == 0.
  The `beq` branch at 0x37c0 targets 0x3960, is taken when (a1(?) & v0(=0xf000000000000000)) == 0, and falls through when (a1(?) & v0(=0xf000000000000000)) != 0.
  The `beq` branch at 0x37c8 targets 0x3a00, is taken when v1(=-0x1) == a1(?), and falls through when v1(=-0x1) != a1(?).
  The `beq` branch at 0x37e0 targets 0x3934, is taken when a0(=[ret(pciio_info_mfast_get)+40]:1) == v0(?), and falls through when a0(=[ret(pciio_info_mfast_get)+40]:1) != v0(?).
  The `beq` branch at 0x37e8 targets 0x3968, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x37f8 targets 0x39b4, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x3818 targets 0x36f4, is taken when v0(=ret(alenlist_replace)) != 0, and falls through when v0(=ret(alenlist_replace)) == 0.
  The `beq` branch at 0x3838 targets 0x37a8, is taken when v0(=ret(alenlist_get)) == 0, and falls through when v0(=ret(alenlist_get)) != 0.
  The `beq` branch at 0x3840 targets 0x385c, is taken when s4(=one of 0x0, 0x898000, 0x8f8000) == 0, and falls through when s4(=one of 0x0, 0x898000, 0x8f8000) != 0.
  The `beq` branch at 0x384c targets 0x3954, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x385c targets 0x39f0, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x3870 targets 0x3720 and is always taken.
  The `bltz` branch at 0x3890 targets 0x371c, is taken when v0(=ret(pcibr_try_set_device)) < 0 (signed), and falls through when v0(=ret(pcibr_try_set_device)) >= 0 (signed).
  The `beq` branch at 0x38ac targets 0x36c8 and is always taken.
  The `beq` branch at 0x38cc targets 0x38e8, is taken when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]:8) == t8(=0xffffffff), and falls through when s5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+360]:8) != t8(=0xffffffff).
  The `bne` branch at 0x38d8 targets 0x38ec, is taken when t9(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+368]) != s0(=([ret(pciio_info_mfast_get)+124] | a3)), and falls through when t9(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+368]) == s0(=([ret(pciio_info_mfast_get)+124] | a3)).
  The `beq` branch at 0x38e0 targets 0x36d8 and is always taken.
  The `bltz` branch at 0x3900 targets 0x371c, is taken when v0(=ret(pcibr_try_set_device)) < 0 (signed), and falls through when v0(=ret(pcibr_try_set_device)) >= 0 (signed).
  The `beq` branch at 0x391c targets 0x36d4 and is always taken.
  The `beq` branch at 0x392c targets 0x371c and is always taken.
  The `bne` branch at 0x3944 targets 0x37f4, is taken when v0(=ret(pcibr_addr_xio_to_pci)) != 0, and falls through when v0(=ret(pcibr_addr_xio_to_pci)) == 0.
  The `beq` branch at 0x394c targets 0x36f4 and is always taken.
  The `beq` branch at 0x3958 targets 0x385c and is always taken.
  The `beq` branch at 0x3960 targets 0x37d8 and is always taken.
  The `bne` branch at 0x3974 targets 0x36f4, is taken when t8(?) < a0(?) (unsigned), and falls through when t8(?) >= a0(?) (unsigned).
  The `bne` branch at 0x3980 targets 0x36f4, is taken when a1(?) < t9(?) (unsigned), and falls through when a1(?) >= t9(?) (unsigned).
  The `bne` branch at 0x398c targets 0x36f4, is taken when ra(=[ret(pciio_info_mfast_get)+88]:1) != v0(?), and falls through when ra(=[ret(pciio_info_mfast_get)+88]:1) == v0(?).
  The `bne` branch at 0x39a4 targets 0x36f4, is taken when at(?) < v1(?) (unsigned), and falls through when at(?) >= v1(?) (unsigned).
  The `beq` branch at 0x39ac targets 0x37f4 and is always taken.
  The `bne` branch at 0x39c4 targets 0x36f4, is taken when v0(=ret(alenlist_append)) != 0, and falls through when v0(=ret(alenlist_append)) == 0.
  The `beq` branch at 0x39cc targets 0x3820 and is always taken.
  The `beq` branch at 0x39e0 targets 0x3780, is taken when v0(=ret(alenlist_create)) >= 0x1 (unsigned), and falls through when v0(=ret(alenlist_create)) < 0x1 (unsigned).
  The `beq` branch at 0x39e8 targets 0x36f4 and is always taken.
  The `beq` branch at 0x39f8 targets 0x3864 and is always taken.
  The `beq` branch at 0x3a00 targets 0x371c and is always taken.
  The return at 0x3748 has v0 = one of 0x0, ?.

- `pcibr_dmamap_drain` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x3a08 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x3a08-0x3a24 (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0x3a14 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `jal` at 0x3a10 calls xtalk_dmamap_drain with a0=[a0+24]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x3a1c has v0 = ret(xtalk_dmamap_drain).

- `pcibr_dmaaddr_drain` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x3a24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x3a24-0x3a64 (64 bytes).
  It occupies 64 bytes.
  The `lw` at 0x3a44 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0x3a34 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3a3c calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3a4c calls xtalk_dmaaddr_drain with a0=[ret(pciio_info_mfast_get)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The return at 0x3a5c has v0 = ret(xtalk_dmaaddr_drain).

- `pcibr_dmalist_drain` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x3a64 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x3a64-0x3a9c (56 bytes).
  It occupies 56 bytes.
  The `lw` at 0x3a80 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0x3a70 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3a78 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3a84 calls xtalk_dmalist_drain with a0=[ret(pciio_info_mfast_get)], a1=a1 at entry (arg1), a2=?, a3=?.
  The return at 0x3a94 has v0 = ret(xtalk_dmalist_drain).

- `pcibr_dmamap_pciaddr_get` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x3a9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x3a9c-0x3aa4 (8 bytes).
  It occupies 8 bytes.
  The `ld` at 0x3aa0 loads 8 bytes from a0 (arg0 at entry) +0x38.
  The return at 0x3a9c has v0 = [a0+56]:8.

- `pcibr_provider_startup` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x3aa4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x3aa4-0x3aac (8 bytes).
  It occupies 8 bytes.
  The return at 0x3aa4 has v0 = ?.

- `pcibr_provider_shutdown` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x3aac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x3aac-0x3ab4 (8 bytes).
  It occupies 8 bytes.
  The return at 0x3aac has v0 = ?.

- `pcibr_reset` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x3ab4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x3ab4-0x3d70 (700 bytes).
  It occupies 700 bytes.
  The `lbu` at 0x3ac8 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0x3adc loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  The `lw` at 0x3aec loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x108.
  The `lbu` at 0x3b04 loads 1 byte from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x10c.
  The `lbu` at 0x3b08 loads 1 byte from ret(pciio_info_mfast_get) +0x31.
  The `lbu` at 0x3b18 loads 1 byte from ret(pciio_info_mfast_get) +0x33.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x3b44, `lw` at 0x3cb8.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x3b5c, `ld` at 0x3b84, `ld` at 0x3c30.
  The `sw` at 0x3ba4 stores 4 bytes to ?.
  The `lw` at 0x3ba8 loads 4 bytes from ret(pciio_info_mfast_get) +0x4.
  The `lh` at 0x3bc8 loads 2 bytes from ret(pciio_info_mfast_get) +0x72.
  The `lbu` at 0x3bd8 loads 1 byte from ret(pciio_info_mfast_get) +0x28.
  The `ld` at 0x3be4 loads 8 bytes from ret(pciio_info_mfast_get) +0x80.
  2 such `ld` accesses load 8 bytes from table(0x0) +0x0, including `ld` at 0x3d58, `ld` at 0x3d6c.
  The `jal` at 0x3ac0 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3ad4 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3b34 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+140, a1=?, a2=?, a3=a0 at entry (arg0).
  The `jal` at 0x3b98 calls pcibr_func_config_get with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=0x4.
  The `jal` at 0x3bac calls pcibr_widget_to_bus with a0=[ret(pciio_info_mfast_get)+4], a1=?, a2=?, a3=?.
  The `jal` at 0x3be0 calls iobrick_pci_slot_rst with a0=[ret(pciio_info_mfast_get)+128]:8, a1=ret(pcibr_widget_to_bus), a2=?, a3=0x0, a4=[ret(pciio_info_mfast_get)+40]:1.
  The `jal` at 0x3c08 calls pcibr_func_config_set with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x3cbc calls pcibr_func_config_set with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=0x4.
  The `jal` at 0x3ce0 calls mutex_io_spinunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3d08 calls pcibr_debug with a0=0x8, a1=a0 at entry (arg0), a2=sym(.rodata), a3=a0 at entry (arg0).
  The `beq` branch at 0x3afc targets 0x3b08, is taken when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+264]) == 0, and falls through when at(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+264]) != 0.
  The `bne` branch at 0x3b10 targets 0x3cf8, is taken when s3(?) < a1(=[ret(pciio_info_mfast_get)+49]:1) (signed), and falls through when s3(?) >= a1(=[ret(pciio_info_mfast_get)+49]:1) (signed).
  The `bne` branch at 0x3b20 targets 0x3cf8, is taken when a2(=[ret(pciio_info_mfast_get)+51]:1) < s3(?) (signed), and falls through when a2(=[ret(pciio_info_mfast_get)+51]:1) >= s3(?) (signed).
  The `blez` branch at 0x3b58 targets 0x3ba8, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0x3b60 targets 0x3d3c and is always taken.
  The `beq` branch at 0x3b74 targets 0x3ba8, is taken when s0(?) >= s6(?) (signed), and falls through when s0(?) < s6(?) (signed).
  The `beq` branch at 0x3b88 targets 0x3b68, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x3ba0 targets 0x3b68 and is always taken.
  The `beq` branch at 0x3bc0 targets 0x3bd8, is taken when s3(?) == t9(=0xff), and falls through when s3(?) != t9(=0xff).
  The `beq` branch at 0x3bcc targets 0x3bd8, is taken when ra(=[ret(pciio_info_mfast_get)+114]:2) == at(=0x2), and falls through when ra(=[ret(pciio_info_mfast_get)+114]:2) != at(=0x2).
  The `blez` branch at 0x3be8 targets 0x3cd0, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0x3bf4 targets 0x3d48 and is always taken.
  The `beq` branch at 0x3c18 targets 0x3c4c, is taken when s0(?) >= 0x6 (signed), and falls through when s0(?) < 0x6 (signed).
  The `bne` branch at 0x3c34 targets 0x3bfc, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `bne` branch at 0x3c44 targets 0x3c20, is taken when s0(?) < 0x6 (signed), and falls through when s0(?) >= 0x6 (signed).
  The `beq` branch at 0x3c5c targets 0x3c80, is taken when s8(?) >= s6(?) (signed), and falls through when s8(?) < s6(?) (signed).
  The `beq` branch at 0x3c70 targets 0x3c4c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0x3c78 targets 0x3c24 and is always taken.
  The `beq` branch at 0x3c80 targets 0x3d5c and is always taken.
  The `beq` branch at 0x3c98 targets 0x3ccc, is taken when s0(?) >= s6(?) (signed), and falls through when s0(?) < s6(?) (signed).
  The `beq` branch at 0x3ca4 targets 0x3c88, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x3cc4 targets 0x3c8c and is always taken.
  The `beq` branch at 0x3cec targets 0x3d14 and is always taken.
  The `beq` branch at 0x3d40 targets 0x3b80 and is always taken.
  The `beq` branch at 0x3d54 targets 0x3c68 and is always taken.
  The `beq` branch at 0x3d68 targets 0x3ca4 and is always taken.
  The return at 0x3d34 has v0 = one of -0x1, 0x0.
  The instructions from 0x3cf4 to 0x3cf4 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_endian_set` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x3d70 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x3d70-0x3e58 (232 bytes).
  It occupies 232 bytes.
  The `lbu` at 0x3d94 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0x3dc8 loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x140.
  The `sd` at 0x3e4c stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x140.
  The `jal` at 0x3d8c calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3d9c calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3dac calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+140, a1=?, a2=?, a3=?.
  The `jal` at 0x3dec calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x3e0c calls pcibr_debug with a0=0x4000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=[ret(pciio_hostinfo_get)+540]:1, a5=sym(device_bits).
  The `jal` at 0x3e38 calls pcireg_device_set with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+320]:8, a4=0x180000, a7=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `jal` at 0x3e48 calls pcireg_tflush_get with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `beq` branch at 0x3dc4 targets 0x3dd4, is taken when s0(=a1) == s2(=a2), and falls through when s0(=a1) != s2(=a2).
  The `beq` branch at 0x3dcc targets 0x3dd8 and is always taken.
  The `bne` branch at 0x3ddc targets 0x3e30, is taken when a3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+320]:8) != s0(?), and falls through when a3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+320]:8) == s0(?).
  The `beq` branch at 0x3e50 targets 0x3de4 and is always taken.
  The return at 0x3e28 has v0 = a2.

- `pcibr_priority_bits_set` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x3e58 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x3e58-0x3fb0 (344 bytes).
  It occupies 344 bytes.
  The `lw` at 0x3e90 loads 4 bytes from a0 (arg0 at entry) +0x78.
  The `ld` at 0x3ebc loads 8 bytes from (a0 + (a1 << 0x7)) +0x140.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x148, including `lw` at 0x3f24, `lw` at 0x3f60.
  2 such `sw` accesses store 4 bytes to (a0 + (a1 << 0x7)) +0x148, including `sw` at 0x3f34, `sw` at 0x3f78.
  The `sd` at 0x3f4c stores 8 bytes to (a0 + (a1 << 0x7)) +0x140.
  The `jal` at 0x3ea8 calls mutex_spinlock with a0=a0+140, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3f00 calls mutex_io_spinunlock with a0=a0+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x3f44 calls pcireg_device_set with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x3f50 calls pcireg_tflush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x3ec8 targets 0x3f24, is taken when s0(=a2) == a1(=0x1), and falls through when s0(=a2) != a1(=0x1).
  The `beq` branch at 0x3ed0 targets 0x3f24, is taken when s0(=a2) == a0(=0x2), and falls through when s0(=a2) != a0(=0x2).
  The `beq` branch at 0x3ed8 targets 0x3f60, is taken when s0(=a2) == 0, and falls through when s0(=a2) != 0.
  The `bne` branch at 0x3ee0 targets 0x3f40, is taken when a2(=[(a0 + (a1 << 0x7))+320]:8) != s1(?), and falls through when a2(=[(a0 + (a1 << 0x7))+320]:8) == s1(?).
  The `bne` branch at 0x3f30 targets 0x3ee0, is taken when t8(=[(a0 + (a1 << 0x7))+328]+1) != a1(=0x1), and falls through when t8(=[(a0 + (a1 << 0x7))+328]+1) == a1(=0x1).
  The `beq` branch at 0x3f38 targets 0x3f84 and is always taken.
  The `beq` branch at 0x3f58 targets 0x3eec and is always taken.
  The `blez` branch at 0x3f68 targets 0x3ee0, is taken when v0(=[(a0 + (a1 << 0x7))+328]) <= 0 (signed), and falls through when v0(=[(a0 + (a1 << 0x7))+328]) > 0 (signed).
  The `bne` branch at 0x3f74 targets 0x3ee0, is taken when v0(=[(a0 + (a1 << 0x7))+328]-1) != 0, and falls through when v0(=[(a0 + (a1 << 0x7))+328]-1) == 0.
  The `beq` branch at 0x3f7c targets 0x3f94 and is always taken.
  The `beq` branch at 0x3f84 targets 0x3fa8, is taken when s5(=one of 0x0, 0x200000) == 0, and falls through when s5(=one of 0x0, 0x200000) != 0.
  The `beq` branch at 0x3f8c targets 0x3ee0 and is always taken.
  The `beq` branch at 0x3f94 targets 0x3ee0, is taken when s5(=one of 0x0, 0x200000) == 0, and falls through when s5(=one of 0x0, 0x200000) != 0.
  The `beq` branch at 0x3fa0 targets 0x3ee0 and is always taken.
  The `beq` branch at 0x3fa8 targets 0x3ee0 and is always taken.
  The return at 0x3f1c has v0 = one of -0x1, 0x0.

- `pcibr_priority_set` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x3fb0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x3fb0-0x3ffc (76 bytes).
  It occupies 76 bytes.
  The `lbu` at 0x3fd0 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `jal` at 0x3fc0 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x3fcc calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x3fdc calls pcibr_priority_bits_set with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=a1 at entry (arg1), a3=?.
  The return at 0x3ff4 has v0 = a1.

- `pcibr_device_flags_set` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x3ffc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x3ffc-0x41fc (512 bytes).
  It occupies 512 bytes.
  The `lbu` at 0x4018 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lh` at 0x40f4 loads 2 bytes from ret(pciio_info_mfast_get) +0x72.
  The `ld` at 0x412c loads 8 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x140.
  The `sd` at 0x41b8 stores 8 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)) +0x140.
  The `lw` at 0x41dc loads 4 bytes from ret(pciio_info_mfast_get) +0x78.
  The `jal` at 0x4010 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4028 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x4118 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+140, a1=(a1 << 0x2c), a2=?, a3=(a1 << 0x2b), a7=(a1 << 0x25).
  The `jal` at 0x4150 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x4170 calls pcibr_debug with a0=0x4000000, a1=a0 at entry (arg0), a2=sym(.rodata), a3=[ret(pciio_hostinfo_get)+540]:1, a5=sym(device_bits).
  The `jal` at 0x41a4 calls pcireg_device_set with a0=ret(pciio_info_mfast_get), a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The `jal` at 0x41b4 calls pcireg_tflush_get with a0=ret(pciio_info_mfast_get), a1=?, a2=?, a3=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7)).
  The `bgez` branch at 0x405c targets 0x41c4, is taken when v0(=(a1 << 0x2f)) >= 0 (signed), and falls through when v0(=(a1 << 0x2f)) < 0 (signed).
  The `bgez` branch at 0x4064 targets 0x4070, is taken when a3(=(a1 << 0x2e)) >= 0 (signed), and falls through when a3(=(a1 << 0x2e)) < 0 (signed).
  The `bgez` branch at 0x4074 targets 0x4080, is taken when v1(=(a1 << 0x2d)) >= 0 (signed), and falls through when v1(=(a1 << 0x2d)) < 0 (signed).
  The `bgez` branch at 0x4084 targets 0x4094, is taken when a1(=(a1 << 0x2c)) >= 0 (signed), and falls through when a1(=(a1 << 0x2c)) < 0 (signed).
  The `bgez` branch at 0x4094 targets 0x40a4, is taken when a3(=(a1 << 0x2b)) >= 0 (signed), and falls through when a3(=(a1 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0x40a4 targets 0x40b4, is taken when a4(=(a1 << 0x2a)) >= 0 (signed), and falls through when a4(=(a1 << 0x2a)) < 0 (signed).
  The `bgez` branch at 0x40b4 targets 0x40c0, is taken when a5(=(a1 << 0x29)) >= 0 (signed), and falls through when a5(=(a1 << 0x29)) < 0 (signed).
  The `beq` branch at 0x40c4 targets 0x40d4, is taken when (s2(=a1) & a0(=0x800000)) == 0, and falls through when (s2(=a1) & a0(=0x800000)) != 0.
  The `bgez` branch at 0x40d8 targets 0x40e4, is taken when a7(=(a1 << 0x25)) >= 0 (signed), and falls through when a7(=(a1 << 0x25)) < 0 (signed).
  The `bgez` branch at 0x40e8 targets 0x40f4, is taken when t0(=(a1 << 0x24)) >= 0 (signed), and falls through when t0(=(a1 << 0x24)) < 0 (signed).
  The `beq` branch at 0x40fc targets 0x41d4, is taken when t1(=[ret(pciio_info_mfast_get)+114]:2) == t2(=0x2), and falls through when t1(=[ret(pciio_info_mfast_get)+114]:2) != t2(=0x2).
  The `bne` branch at 0x4104 targets 0x4118, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `beq` branch at 0x410c targets 0x417c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x413c targets 0x419c, is taken when t3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+320]:8) != s2(?), and falls through when t3(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x7))+320]:8) == s2(?).
  The `beq` branch at 0x41bc targets 0x4144 and is always taken.
  The `bltz` branch at 0x41c4 targets 0x406c, is taken when a3(=(a1 << 0x2e)) < 0 (signed), and falls through when a3(=(a1 << 0x2e)) >= 0 (signed).
  The `beq` branch at 0x41cc targets 0x4074 and is always taken.
  The `beq` branch at 0x41d4 targets 0x4104, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x41e8 targets 0x4104, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x41f4 targets 0x4104 and is always taken.
  The return at 0x4194 has v0 = 0x1.

- `pcibr_pcix_rbars_calc` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x41fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x41fc-0x428c (144 bytes).
  It occupies 144 bytes.
  The `lw` at 0x41fc loads 4 bytes from a0 (arg0 at entry) +0x510.
  The `lw` at 0x4230 loads 4 bytes from a0 (arg0 at entry) +0x514.
  The `ld` at 0x4270 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `jal` at 0x4278 calls cmn_err with a0=0x4, a1=sym(.rodata), a2=[a0+16]:8, a3=0x10, a4=[a0+1296], a7=a0 at entry (arg0).
  The `beq` branch at 0x4210 targets 0x4260, is taken when a4(=[a0+1296]) == 0, and falls through when a4(=[a0+1296]) != 0.
  The `beq` branch at 0x421c targets 0x4268, is taken when a4(=[a0+1296]) >= 0x11 (signed), and falls through when a4(=[a0+1296]) < 0x11 (signed).
  The `bne` branch at 0x4248 targets 0x4258, is taken when v0(?) < 0x65 (signed), and falls through when v0(?) >= 0x65 (signed).
  The `beq` branch at 0x4250 targets 0x425c and is always taken.
  The `beq` branch at 0x4284 targets 0x4260 and is always taken.
  The return at 0x4260 has v0 = one of 0x13, ?, 0x0.

- `pcibr_dma_enabled` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x428c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x428c-0x42b8 (44 bytes).
  It occupies 44 bytes.
  The `lw` at 0x42a8 loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0x4294 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x429c calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x42a4 calls xtalk_dma_enabled with a0=[ret(pciio_info_mfast_get)], a1=?, a2=?, a3=?.
  The return at 0x42b0 has v0 = ret(xtalk_dma_enabled).

- `pcibr_debug` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x42b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x42b8-0x44ec (564 bytes).
  It occupies 564 bytes.
  The `lh` at 0x44a8 loads 2 bytes from abs 0xffffffffffffc428.
  The `jal` at 0x42ec calls bzero with a0=sp-624, a1=0x100, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4324 calls hwgraph_vertex_name_get with a0=a1 at entry (arg1), a1=sp-624, a2=0x100, a3=?.
  The `jal` at 0x4354 calls strcmp with a0=?, a1=[sym(pcibr_debug_module)]:8, a2=?, a3=?.
  The `jal` at 0x4378 calls kmem_zalloc with a0=0x400, a1=0x0, a2=?, a3=?.
  The `jal` at 0x43c0 calls strcmp with a0=sym(.rodata), a1=[sym(pcibr_debug_module)]:8, a2=?, a3=?.
  The `jal` at 0x43d4 calls strcpy with a0=sp-368, a1=sp-624, a2=?, a3=?.
  The `jal` at 0x43e4 calls strstr with a0=sp-368, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4408 calls strstr with a0=sp-624, a1=sym(.rodata), a2=?, a3=?.
  The `jal` at 0x4428 calls strstr with a0=sp-624, a1=sym(.rodata), a2=[sym(pcibr_debug_slot)], a3=?.
  The `jal` at 0x4458 calls atoi with a0=ret(strstr)+7, a1=?, a2=?, a3=?.
  The `jal` at 0x446c calls atoi with a0=ret(strstr)+5, a1=?, a2=?, a3=?.
  The `jal` at 0x4490 calls strtok_r with a0=ret(strstr)+7, a1=sym(.rodata), a2=sp-112, a3=?.
  The `jal` at 0x44ac calls printf with a0=sym(.rodata), a1=[-0x3bd8]:2, a2=sp-624, a3=?.
  The `jal` at 0x44bc calls vsprintf with a0=ret(kmem_zalloc), a1=a2 at entry (arg2), a2=sp-40, a3=?.
  The `jal` at 0x44d0 calls cmn_err with a0=0x6, a1=sym(.rodata), a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x44dc calls kmem_free with a0=ret(kmem_zalloc), a1=0x400, a2=?, a3=?.
  The `beq` branch at 0x430c targets 0x4388, is taken when (v1(=[sym(pcibr_debug_mask)]) & a0) == 0, and falls through when (v1(=[sym(pcibr_debug_mask)]) & a0) != 0.
  The `beq` branch at 0x4314 targets 0x43a4, is taken when s1(=a1) == 0, and falls through when s1(=a1) != 0.
  The `beq` branch at 0x432c targets 0x43b8, is taken when v0(=ret(hwgraph_vertex_name_get)) == 0, and falls through when v0(=ret(hwgraph_vertex_name_get)) != 0.
  The `beq` branch at 0x4348 targets 0x4378, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x435c targets 0x4388, is taken when v0(=ret(strcmp)) != 0, and falls through when v0(=ret(strcmp)) == 0.
  The `bne` branch at 0x4364 targets 0x438c, is taken when t9(=[sym(pcibr_debug_widget)]) != s2(?), and falls through when t9(=[sym(pcibr_debug_widget)]) == s2(?).
  The `bne` branch at 0x4370 targets 0x4388, is taken when ra(=[sym(pcibr_debug_slot)]) != s3(?), and falls through when ra(=[sym(pcibr_debug_slot)]) == s3(?).
  The `bne` branch at 0x4380 targets 0x44a0, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0x43b0 targets 0x4340 and is always taken.
  The `beq` branch at 0x43c8 targets 0x4440, is taken when v0(=ret(strcmp)) == 0, and falls through when v0(=ret(strcmp)) != 0.
  The `bne` branch at 0x43ec targets 0x4480, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x43fc targets 0x4448, is taken when t8(=[sym(pcibr_debug_widget)]) == s3(=-0x1), and falls through when t8(=[sym(pcibr_debug_widget)]) != s3(=-0x1).
  The `bne` branch at 0x4410 targets 0x4458, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x441c targets 0x4450, is taken when a2(=[sym(pcibr_debug_slot)]) == s3(=-0x1), and falls through when a2(=[sym(pcibr_debug_slot)]) != s3(=-0x1).
  The `bne` branch at 0x4430 targets 0x446c, is taken when v0(=ret(strstr)) != 0, and falls through when v0(=ret(strstr)) == 0.
  The `beq` branch at 0x4438 targets 0x4340 and is always taken.
  The `beq` branch at 0x4440 targets 0x43f8 and is always taken.
  The `beq` branch at 0x4448 targets 0x4418 and is always taken.
  The `beq` branch at 0x4450 targets 0x4340 and is always taken.
  The `beq` branch at 0x4464 targets 0x4418 and is always taken.
  The `beq` branch at 0x4478 targets 0x4340 and is always taken.
  The `beq` branch at 0x4498 targets 0x43f8 and is always taken.
  The `beq` branch at 0x44e4 targets 0x438c and is always taken.
  The return at 0x439c has v0 = one of ret(strcmp), ?, ret(kmem_free).

- `pcibr_businfo_get` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x44ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x44ec-0x45d4 (232 bytes).
  It occupies 232 bytes.
  The `lh` at 0x4504 loads 2 bytes from ret(pciio_info_mfast_get) +0x72.
  2 such `lh` accesses load 2 bytes from ret(pciio_info_mfast_get) +0x74, including `lh` at 0x452c, `lh` at 0x4584.
  2 such `sw` accesses store 4 bytes to ret(pciio_info_mfast_get) +0xaac, including `sw` at 0x4544, `sw` at 0x4590.
  3 such `sw` accesses store 4 bytes to ret(pciio_info_mfast_get) +0xaa8, including `sw` at 0x4550, `sw` at 0x459c, `sw` at 0x45b0.
  3 such `sw` accesses store 4 bytes to ret(pciio_info_mfast_get) +0xab0, including `sw` at 0x4558, `sw` at 0x4588, `sw` at 0x45a8.
  6 such `sw` accesses store 4 bytes to ret(pciio_info_mfast_get) +0xab4, including `sw` at 0x4580, `sw` at 0x45a4, `sw` at 0x45b8.
  The `jal` at 0x44f4 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x44fc calls pciio_info_mfast_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0x4514 targets 0x4584, is taken when a4(=[ret(pciio_info_mfast_get)+114]:2) == a5(=0x1), and falls through when a4(=[ret(pciio_info_mfast_get)+114]:2) != a5(=0x1).
  The `beq` branch at 0x451c targets 0x452c, is taken when a4(=[ret(pciio_info_mfast_get)+114]:2) == a3(=0x2), and falls through when a4(=[ret(pciio_info_mfast_get)+114]:2) != a3(=0x2).
  The `beq` branch at 0x4548 targets 0x45a8, is taken when (v0(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) == 0, and falls through when (v0(=[ret(pciio_info_mfast_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0x4554 targets 0x45b4, is taken when v0(=[ret(pciio_info_mfast_get)+116]:2) == 0, and falls through when v0(=[ret(pciio_info_mfast_get)+116]:2) != 0.
  The `beq` branch at 0x455c targets 0x45bc, is taken when v0(=[ret(pciio_info_mfast_get)+116]:2) == a3(=0x2), and falls through when v0(=[ret(pciio_info_mfast_get)+116]:2) != a3(=0x2).
  The `beq` branch at 0x4564 targets 0x45bc, is taken when v0(=[ret(pciio_info_mfast_get)+116]:2) == a7(=0x3), and falls through when v0(=[ret(pciio_info_mfast_get)+116]:2) != a7(=0x3).
  The `beq` branch at 0x456c targets 0x45c4, is taken when v0(=[ret(pciio_info_mfast_get)+116]:2) == a6(=0x5), and falls through when v0(=[ret(pciio_info_mfast_get)+116]:2) != a6(=0x5).
  The `bne` branch at 0x4574 targets 0x4524, is taken when v0(=[ret(pciio_info_mfast_get)+116]:2) != a4(=0x7), and falls through when v0(=[ret(pciio_info_mfast_get)+116]:2) == a4(=0x7).
  The `beq` branch at 0x457c targets 0x4520 and is always taken.
  The `beq` branch at 0x4598 targets 0x45cc, is taken when v0(=[ret(pciio_info_mfast_get)+116]:2) == 0, and falls through when v0(=[ret(pciio_info_mfast_get)+116]:2) != 0.
  The `beq` branch at 0x45a0 targets 0x451c and is always taken.
  The `bne` branch at 0x45ac targets 0x455c, is taken when v0(=[ret(pciio_info_mfast_get)+116]:2) != 0, and falls through when v0(=[ret(pciio_info_mfast_get)+116]:2) == 0.
  The `beq` branch at 0x45b4 targets 0x455c and is always taken.
  The `beq` branch at 0x45bc targets 0x456c and is always taken.
  The `beq` branch at 0x45c4 targets 0x4574 and is always taken.
  The `beq` branch at 0x45cc targets 0x451c and is always taken.
  The return at 0x4524 has v0 = ret(pciio_info_mfast_get)+2728.

- `idbg_pss_func` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x4680 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x4680-0x4808 (392 bytes).
  It occupies 392 bytes.
  The `ld` at 0x4694 loads 8 bytes from (a0 + (a1 << 0x3)) +0x0.
  The `lw` at 0x46c0 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x8.
  The `lbu` at 0x46d0 loads 1 byte from [(a0 + (a1 << 0x3))]:8 +0x10.
  The `lbu` at 0x46dc loads 1 byte from [(a0 + (a1 << 0x3))]:8 +0x11.
  The `lbu` at 0x46e8 loads 1 byte from [(a0 + (a1 << 0x3))]:8 +0x12.
  The `lw` at 0x46f4 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x14.
  The `lw` at 0x4700 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x18.
  The `lw` at 0x4718 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x1c.
  The `ld` at 0x4728 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x30.
  The `ld` at 0x4734 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x40.
  The `ld` at 0x4738 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x38.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x475c, `lw` at 0x47cc.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x4760, `ld` at 0x476c, `ld` at 0x477c.
  The `ld` at 0x4790 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x1a8.
  The `ld` at 0x4794 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x1a0.
  The `jal` at 0x46ac calls qprintf with a0=sym(.rodata)+2504, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x46bc calls vertex_to_name with a0=[[(a0 + (a1 << 0x3))]:8+8], a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0x46c8 calls qprintf with a0=sym(.rodata)+2504, a1=sp-304, a2=?, a3=?.
  The `jal` at 0x46d4 calls qprintf with a0=sym(.rodata)+2504, a1=[[(a0 + (a1 << 0x3))]:8+16]:1, a2=?, a3=?.
  The `jal` at 0x46e0 calls qprintf with a0=sym(.rodata)+2504, a1=[[(a0 + (a1 << 0x3))]:8+17]:1, a2=?, a3=?.
  The `jal` at 0x46ec calls qprintf with a0=sym(.rodata)+2504, a1=[[(a0 + (a1 << 0x3))]:8+18]:1, a2=?, a3=?.
  The `jal` at 0x46f8 calls qprintf with a0=sym(.rodata)+2504, a1=[[(a0 + (a1 << 0x3))]:8+20], a2=?, a3=?.
  The `jal` at 0x4704 calls qprintf with a0=sym(.rodata)+2504, a1=[[(a0 + (a1 << 0x3))]:8+24], a2=?, a3=?.
  The `jal` at 0x4714 calls vertex_to_name with a0=[[(a0 + (a1 << 0x3))]:8+28], a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0x4720 calls qprintf with a0=sym(.rodata)+2504, a1=sp-304, a2=?, a3=?.
  The `jal` at 0x472c calls qprintf with a0=sym(.rodata)+2504, a1=[[(a0 + (a1 << 0x3))]:8+48]:8, a2=?, a3=?.
  The `jal` at 0x473c calls qprintf with a0=sym(.rodata)+2504, a1=[[(a0 + (a1 << 0x3))]:8+56]:8, a2=[[(a0 + (a1 << 0x3))]:8+64]:8, a3=?.
  The `jal` at 0x4778 calls qprintf with a0=sym(.rodata)+2504, a1=?, a2=?, a3=?.
  The `jal` at 0x4798 calls qprintf with a0=sym(.rodata)+2504, a1=[[(a0 + (a1 << 0x3))]:8+416]:8, a2=[[(a0 + (a1 << 0x3))]:8+424]:8, a3=?.
  The `jal` at 0x47a0 calls qprintf with a0=sym(.rodata)+2504, a1=?, a2=?, a3=?.
  The `jal` at 0x47a8 calls qprintf with a0=sym(.rodata)+2504, a1=?, a2=?, a3=?.
  The `jal` at 0x47c8 calls qprintf with a0=sym(.rodata)+2504, a1=?, a2=?, a3=?.
  The `jal` at 0x47e4 calls qprintf with a0=sym(.rodata)+2504, a1=?, a2=?, a3=?.
  The `beq` branch at 0x46a0 targets 0x47ec, is taken when s0(=[(a0 + (a1 << 0x3))]:8) == 0, and falls through when s0(=[(a0 + (a1 << 0x3))]:8) != 0.
  The `bne` branch at 0x4788 targets 0x4750, is taken when s2(?) < 0x6 (signed), and falls through when s2(?) >= 0x6 (signed).
  The `bne` branch at 0x47d8 targets 0x47b8, is taken when s2(?) < 0x4 (signed), and falls through when s2(?) >= 0x4 (signed).
  The return at 0x4800 has v0 = one of ?, ret(qprintf).

- `idbg_pss_info` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x4808 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x4808-0x49e4 (476 bytes).
  It occupies 476 bytes.
  The `lw` at 0x4840 loads 4 bytes from (a0 + (a1 << 0x7)) +0x108.
  The `lbu` at 0x4860 loads 1 byte from (a0 + (a1 << 0x7)) +0x10c.
  The `lw` at 0x4878 loads 4 bytes from (a0 + (a1 << 0x7)) +0x110.
  3 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x118, including `lw` at 0x4888, `lw` at 0x4894, `lw` at 0x48ac.
  The `ld` at 0x48a0 loads 8 bytes from (a0 + (a1 << 0x7)) +0x120.
  The `lw` at 0x48c0 loads 4 bytes from (a0 + (a1 << 0x7)) +0x128.
  The `ld` at 0x48d8 loads 8 bytes from (sym(pci_space) + ([(a0 + (a1 << 0x7))+296] << 0x3)) +0x0.
  The `ld` at 0x48dc loads 8 bytes from (a0 + (a1 << 0x7)) +0x130.
  The `ld` at 0x48e8 loads 8 bytes from (a0 + (a1 << 0x7)) +0x140.
  The `lw` at 0x48f4 loads 4 bytes from (a0 + (a1 << 0x7)) +0x154.
  The `lw` at 0x48f8 loads 4 bytes from (a0 + (a1 << 0x7)) +0x150.
  The `lw` at 0x48fc loads 4 bytes from (a0 + (a1 << 0x7)) +0x14c.
  The `lw` at 0x4908 loads 4 bytes from (a0 + (a1 << 0x7)) +0x170.
  The `ld` at 0x490c loads 8 bytes from (a0 + (a1 << 0x7)) +0x168.
  The `lw` at 0x4910 loads 4 bytes from (a0 + (a1 << 0x7)) +0x160.
  The `ld` at 0x4914 loads 8 bytes from (a0 + (a1 << 0x7)) +0x158.
  The `lw` at 0x4920 loads 4 bytes from (a0 + (a1 << 0x7)) +0x174.
  The `ld` at 0x4938 loads 8 bytes from (a0 + (a1 << 0x7)) +0x178.
  The `lw` at 0x4944 loads 4 bytes from (a0 + (a1 << 0x7)) +0x180.
  The `lh` at 0x4950 loads 2 bytes from a0 (arg0 at entry) +0x72.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x2)) +0x530, including `lw` at 0x4974, `lw` at 0x49c0.
  The `lw` at 0x4978 loads 4 bytes from (a0 + (a1 << 0x4)) +0x57c.
  The `lw` at 0x497c loads 4 bytes from (a0 + (a1 << 0x4)) +0x578.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x4)) +0x574, including `lw` at 0x4980, `lw` at 0x49c4.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x4)) +0x570, including `lw` at 0x498c, `lw` at 0x49d0.
  The `jal` at 0x482c calls qprintf with a0=sym(.rodata)+2504, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4858 calls qprintf with a0=sym(.rodata)+2504, a1=sym(.rodata)+2504, a2=sym(.rodata)+2504, a3=sym(.rodata)+2504.
  The `jal` at 0x4864 calls qprintf with a0=sym(.rodata)+2504, a1=[(a0 + (a1 << 0x7))+268]:1, a2=?, a3=?.
  The `jal` at 0x4874 calls vertex_to_name with a0=[(a0 + (a1 << 0x7))+272], a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0x4880 calls qprintf with a0=sym(.rodata)+2504, a1=sp-304, a2=?, a3=?.
  The `jal` at 0x488c calls qprintf with a0=sym(.rodata)+2504, a1=[(a0 + (a1 << 0x7))+280], a2=?, a3=?.
  The `jal` at 0x48a4 calls idbg_pss_func with a0=[(a0 + (a1 << 0x7))+288]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x48d4 calls qprintf with a0=sym(.rodata)+2504, a1=[(sym(pci_space) + ([(a0 + (a1 << 0x7))+296] << 0x3))]:8, a2=([(a0 + (a1 << 0x7))+296] << 0x3), a3=?.
  The `jal` at 0x48e0 calls qprintf with a0=sym(.rodata)+2504, a1=[(a0 + (a1 << 0x7))+304]:8, a2=?, a3=?.
  The `jal` at 0x48ec calls qprintf with a0=sym(.rodata)+2504, a1=[(a0 + (a1 << 0x7))+320]:8, a2=?, a3=?.
  The `jal` at 0x4900 calls qprintf with a0=sym(.rodata)+2504, a1=[(a0 + (a1 << 0x7))+332], a2=[(a0 + (a1 << 0x7))+336], a3=[(a0 + (a1 << 0x7))+340].
  The `jal` at 0x4918 calls qprintf with a0=sym(.rodata)+2504, a1=[(a0 + (a1 << 0x7))+344]:8, a2=[(a0 + (a1 << 0x7))+352], a3=[(a0 + (a1 << 0x7))+360]:8, a4=[(a0 + (a1 << 0x7))+368].
  The `jal` at 0x4930 calls qprintf with a0=sym(.rodata)+2504, a1=sym(.rodata)+2504, a2=sym(.rodata)+2504, a3=[(a0 + (a1 << 0x7))+372].
  The `jal` at 0x493c calls qprintf with a0=sym(.rodata)+2504, a1=[(a0 + (a1 << 0x7))+376]:8, a2=?, a3=?.
  The `jal` at 0x4948 calls qprintf with a0=sym(.rodata)+2504, a1=[(a0 + (a1 << 0x7))+384], a2=?, a3=?.
  The `jal` at 0x4988 calls qprintf with a0=sym(.rodata)+2504, a1=[(a0 + (a1 << 0x4))+1392], a2=[(a0 + (a1 << 0x4))+1396], a3=[(a0 + (a1 << 0x4))+1400], a4=[(a0 + (a1 << 0x4))+1404], a5=[(a0 + (a1 << 0x2))+1328].
  The `jal` at 0x49cc calls qprintf with a0=sym(.rodata)+2504, a1=[(a0 + (a1 << 0x4))+1392], a2=[(a0 + (a1 << 0x4))+1396], a3=[(a0 + (a1 << 0x2))+1328].
  The `beq` branch at 0x484c targets 0x4858, is taken when at(=[(a0 + (a1 << 0x7))+264]) == 0, and falls through when at(=[(a0 + (a1 << 0x7))+264]) != 0.
  The `blez` branch at 0x4898 targets 0x48c0, is taken when t8(=[(a0 + (a1 << 0x7))+280]) <= 0 (signed), and falls through when t8(=[(a0 + (a1 << 0x7))+280]) > 0 (signed).
  The `bne` branch at 0x48b8 targets 0x48a0, is taken when s1(?) < t9(=[(a0 + (a1 << 0x7))+280]) (signed), and falls through when s1(?) >= t9(=[(a0 + (a1 << 0x7))+280]) (signed).
  The `beq` branch at 0x4924 targets 0x49dc, is taken when a3(=[(a0 + (a1 << 0x7))+372]) == 0, and falls through when a3(=[(a0 + (a1 << 0x7))+372]) != 0.
  The `beq` branch at 0x4954 targets 0x49b4, is taken when a1(=[a0+114]:2) == 0, and falls through when a1(=[a0+114]:2) != 0.
  The `beq` branch at 0x4960 targets 0x49b0, is taken when a1(=[a0+114]:2) == a2(=0x1), and falls through when a1(=[a0+114]:2) != a2(=0x1).
  The `beq` branch at 0x49d4 targets 0x4994 and is always taken.
  The `beq` branch at 0x49dc targets 0x4930 and is always taken.
  The return at 0x49a8 has v0 = ret(qprintf).

- `idbg_pss` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x49e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x49e4-0x4a98 (180 bytes).
  It occupies 180 bytes.
  The `lbu` at 0x49e4 loads 1 byte from a0 (arg0 at entry) +0x38.
  3 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x39, including `lbu` at 0x4a0c, `lbu` at 0x4a24, `lbu` at 0x4a44.
  The `jal` at 0x4a3c calls idbg_pss_info with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4a78 calls qprintf with a0=sym(.rodata)+2504, a1=[sym(ips)], a2=a2 at entry (arg2), a3=[sym(ips)].
  The `jal` at 0x4a88 calls idbg_pss_info with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=[sym(ips)].
  The `bne` branch at 0x4a04 targets 0x4a1c, is taken when a3(=[sym(ips)]) < a1(=[a0+56]:1) (signed), and falls through when a3(=[sym(ips)]) >= a1(=[a0+56]:1) (signed).
  The `beq` branch at 0x4a14 targets 0x4a88, is taken when v0(=[a0+57]:1) >= a3(=[sym(ips)]) (signed), and falls through when v0(=[a0+57]:1) < a3(=[sym(ips)]) (signed).
  The `bgez` branch at 0x4a1c targets 0x4a74, is taken when a3(=[sym(ips)]) >= 0 (signed), and falls through when a3(=[sym(ips)]) < 0 (signed).
  The `beq` branch at 0x4a30 targets 0x4a64, is taken when a1(=[a0+56]:1) >= v1(=[a0+57]:1+1) (signed), and falls through when a1(=[a0+56]:1) < v1(=[a0+57]:1+1) (signed).
  The `bne` branch at 0x4a58 targets 0x4a3c, is taken when s0(?) < a0(=[a0+57]:1+1) (signed), and falls through when s0(?) >= a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x4a80 targets 0x4a64 and is always taken.
  The `beq` branch at 0x4a90 targets 0x4a64 and is always taken.
  The return at 0x4a6c has v0 = one of ?, ret(idbg_pss_info), ret(qprintf).

- `pcibr_init_ext_ate_ram` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x4a98 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x4a98-0x4bf8 (352 bytes).
  It occupies 352 bytes.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0x4ad8, `lw` at 0x4b00, `lw` at 0x4b24.
  The `ld` at 0x4b70 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lw` at 0x4b78 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x4ae4 calls pcireg_ext_ate_set with a0=a0 at entry (arg0), a1=?, a2=0x123456789abcdef, a3=?.
  The `jal` at 0x4b0c calls pcireg_ext_ate_set with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?.
  The `jal` at 0x4b2c calls pcireg_ext_ate_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4b50 calls pcireg_ssram_size_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4b84 calls pcibr_debug with a0=0x10, a1=[a0+4], a2=sym(.rodata)+3408, a3=[a0+8]:8.
  The `jal` at 0x4ba4 calls pcireg_ext_ate_set with a0=a0 at entry (arg0), a1=?, a2=0x0, a3=?.
  The `jal` at 0x4be8 calls pcibr_debug with a0=0x10, a1=[a0+4], a2=sym(.rodata)+3408, a3=[a0+8]:8.
  The `bne` branch at 0x4af0 targets 0x4b24, is taken when s0(?) < 0x2 (signed), and falls through when s0(?) >= 0x2 (signed).
  The `bne` branch at 0x4b1c targets 0x4afc, is taken when s4(?) < s0(?) (signed), and falls through when s4(?) >= s0(?) (signed).
  The `bne` branch at 0x4b48 targets 0x4ad0, is taken when s0(?) < 0x4 (unsigned), and falls through when s0(?) >= 0x4 (unsigned).
  The `beq` branch at 0x4b68 targets 0x4b8c, is taken when (t8(=[sym(pcibr_debug_mask)]) & 0x10) == 0, and falls through when (t8(=[sym(pcibr_debug_mask)]) & 0x10) != 0.
  The `beq` branch at 0x4b74 targets 0x4be0, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `blez` branch at 0x4b94 targets 0x4bbc, is taken when s2(?) <= 0 (signed), and falls through when s2(?) > 0 (signed).
  The `bne` branch at 0x4bb4 targets 0x4ba0, is taken when s0(?) < s2(?) (signed), and falls through when s0(?) >= s2(?) (signed).
  The `beq` branch at 0x4bf0 targets 0x4b90 and is always taken.
  The return at 0x4bd8 has v0 = ?.

- `pcibr_ate_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x4bf8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x4bf8-0x4c44 (76 bytes).
  It occupies 76 bytes.
  The `ld` at 0x4c0c loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `ld` at 0x4c1c loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `jal` at 0x4c08 calls rmalloc with a0=[a0+96]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4c28 calls rmalloc with a0=[a0+104]:8, a1=a1 at entry (arg1), a2=?, a3=?, a4=(ret(rmalloc) << 0x0).
  The `bne` branch at 0x4c14 targets 0x4c34, is taken when a4(=(ret(rmalloc) << 0x0)) != 0, and falls through when a4(=(ret(rmalloc) << 0x0)) == 0.
  The `beq` branch at 0x4c20 targets 0x4c38, is taken when a0(=[a0+104]:8) == 0, and falls through when a0(=[a0+104]:8) != 0.
  The return at 0x4c3c has v0 = (ret(rmalloc) << 0x0)-1.

- `pcibr_ate_free` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x4c44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x4c44-0x4c88 (68 bytes).
  It occupies 68 bytes.
  The `lh` at 0x4c44 loads 2 bytes from a0 (arg0 at entry) +0x70.
  The `ld` at 0x4c64 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `ld` at 0x4c68 loads 8 bytes from a0 (arg0 at entry) +0x68.
  The `jal` at 0x4c74 calls rmfree with a0=?, a1=a2 at entry (arg2), a2=a1+1, a3=a3 at entry (arg3), a5=a2 at entry (arg2), a6=a1 at entry (arg1).
  The `beq` branch at 0x4c58 targets 0x4c68, is taken when a1 >= at(=[a0+112]:2) (signed), and falls through when a1 < at(=[a0+112]:2) (signed).
  The `beq` branch at 0x4c60 targets 0x4c6c and is always taken.
  The return at 0x4c80 has v0 = ret(rmfree).

- `pcibr_flags_to_ate` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x4c88 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x4c88-0x4d3c (180 bytes).
  It occupies 180 bytes.
  The `beq` branch at 0x4c9c targets 0x4cb0, is taken when (a0 & 0x10) == 0, and falls through when (a0 & 0x10) != 0.
  The `beq` branch at 0x4cb8 targets 0x4cc4, is taken when (a0 & 0x400) == 0, and falls through when (a0 & 0x400) != 0.
  The `beq` branch at 0x4cc4 targets 0x4cd4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bgez` branch at 0x4cd8 targets 0x4ce4, is taken when a2(=(a0 << 0x29)) >= 0 (signed), and falls through when a2(=(a0 << 0x29)) < 0 (signed).
  The `bgez` branch at 0x4ce4 targets 0x4cf0, is taken when a3(=(a0 << 0x28)) >= 0 (signed), and falls through when a3(=(a0 << 0x28)) < 0 (signed).
  The `bgez` branch at 0x4d00 targets 0x4d0c, is taken when a5(=(a0 << 0x2d)) >= 0 (signed), and falls through when a5(=(a0 << 0x2d)) < 0 (signed).
  The `bgez` branch at 0x4d0c targets 0x4d18, is taken when a4(=(a0 << 0x2c)) >= 0 (signed), and falls through when a4(=(a0 << 0x2c)) < 0 (signed).
  The `bgez` branch at 0x4d1c targets 0x4d28, is taken when a6(=(a0 << 0x2b)) >= 0 (signed), and falls through when a6(=(a0 << 0x2b)) < 0 (signed).
  The `bgez` branch at 0x4d28 targets 0x4d34, is taken when a3(=(a0 << 0x2a)) >= 0 (signed), and falls through when a3(=(a0 << 0x2a)) < 0 (signed).
  The return at 0x4d34 has v0 = ?.

- `pcibr_ate_addr` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x4d3c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x4d3c-0x4d7c (64 bytes).
  It occupies 64 bytes.
  The `lh` at 0x4d3c loads 2 bytes from a0 (arg0 at entry) +0x70.
  The `jal` at 0x4d50 calls pcireg_int_ate_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x4d60 calls pcireg_ext_ate_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x4d48 targets 0x4d60, is taken when a1 >= at(=[a0+112]:2) (signed), and falls through when a1 < at(=[a0+112]:2) (signed).
  The `beq` branch at 0x4d58 targets 0x4d6c and is always taken.
  The return at 0x4d74 has v0 = one of ret(pcireg_int_ate_addr), ret(pcireg_ext_ate_addr).

- `ate_write` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x4d7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x4d7c-0x508c (784 bytes).
  It occupies 784 bytes.
  The `lbu` at 0x4d80 loads 1 byte from a1 (arg1 at entry) +0x8.
  The `lbu` at 0x4d8c loads 1 byte from a0 (arg0 at entry) +0x38.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0x4db0, `lh` at 0x4e2c.
  3 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x0, including `lw` at 0x4dbc, `lw` at 0x4eb8, `lw` at 0x4f40.
  The `lh` at 0x4e08 loads 2 bytes from a0 (arg0 at entry) +0x70.
  5 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x39, including `lbu` at 0x4e44, `lbu` at 0x4e6c, `lbu` at 0x4f94.
  The `ld` at 0x4e60 loads 8 bytes from a0 (arg0 at entry) +0x8.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x4e94, `lw` at 0x4fb4, `lw` at 0x4ff4.
  2 such `sw` accesses store 4 bytes to a1 (arg1 at entry) +0x0, including `sw` at 0x4ecc, `sw` at 0x4f74.
  2 such `ll` accesses load 4 bytes from ?, including `ll` at 0x4ed8, `ll` at 0x4f7c.
  2 such `sc` accesses store 4 bytes to ?, including `sc` at 0x4ee4, `sc` at 0x4f88.
  The `ld` at 0x4fc4 loads 8 bytes from ?.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x4fc8, `sw` at 0x4fd4, `sw` at 0x5004.
  The `jal` at 0x4df0 calls pcireg_int_ate_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4e1c calls pcireg_ext_ate_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4e64 calls pcibr_slot_config_set with a0=[a0+8]:8, a1=?, a2=0x4, a3=?.
  The `jal` at 0x4ef4 calls mutex_io_spinunlock with a0=a0+140, a1=?, a2=?, a3=?.
  The `jal` at 0x4efc calls pcireg_tflush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x4f38 calls mutex_spinlock with a0=a0+140, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=[a1].
  The `jal` at 0x5028 calls pcireg_wrb_flush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x4dd0 targets 0x4f2c, is taken when at(=[a0+114]:2) == 0, and falls through when at(=[a0+114]:2) != 0.
  The `blez` branch at 0x4dd8 targets 0x4e2c, is taken when s3(=a3) <= 0 (signed), and falls through when s3(=a3) > 0 (signed).
  The `beq` branch at 0x4de0 targets 0x4e08 and is always taken.
  The `bltz` branch at 0x4e00 targets 0x4e2c, is taken when s3(?) < 0 (signed), and falls through when s3(?) >= 0 (signed).
  The `bne` branch at 0x4e10 targets 0x4de8, is taken when s1(?) < a0(=[a0+112]:2) (signed), and falls through when s1(?) >= a0(=[a0+112]:2) (signed).
  The `beq` branch at 0x4e24 targets 0x4df8 and is always taken.
  The `bne` branch at 0x4e34 targets 0x4efc, is taken when a1(=[a0+114]:2) != 0, and falls through when a1(=[a0+114]:2) == 0.
  The `beq` branch at 0x4e3c targets 0x4efc, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x4e50 targets 0x4e8c, is taken when s6(=[a0+56]:1) < a0(=[a0+57]:1+1) (signed), and falls through when s6(=[a0+56]:1) >= a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x4e58 targets 0x4eb4 and is always taken.
  The `beq` branch at 0x4e80 targets 0x4eb8, is taken when s1(?) >= a0(=[a0+57]:1+1) (signed), and falls through when s1(?) < a0(=[a0+57]:1+1) (signed).
  The `bne` branch at 0x4e9c targets 0x4e60, is taken when (a3(?) & 0x4) != 0, and falls through when (a3(?) & 0x4) == 0.
  The `bne` branch at 0x4eb0 targets 0x4e88, is taken when s1(?) < a0(=[a0+57]:1+1) (signed), and falls through when s1(?) >= a0(=[a0+57]:1+1) (signed).
  The `beql` branch at 0x4ee8 targets 0x4ed8, is taken when at(=table(0x1)) == 0, and falls through when at(=table(0x1)) != 0; its branch-likely delay slot `nop` at 0x4eec runs only when taken and is annulled on fall-through.
  The `bgez` branch at 0x4f30 targets 0x4dd8, is taken when ra(=([a1] << 0x21)) >= 0 (signed), and falls through when ra(=([a1] << 0x21)) < 0 (signed).
  The `beq` branch at 0x4f5c targets 0x4f94, is taken when (a2(=[a1]) & at(=0xffffffff80000000)) == 0, and falls through when (a2(=[a1]) & at(=0xffffffff80000000)) != 0.
  The `beql` branch at 0x4f8c targets 0x4f7c, is taken when a4(=table(-0x1)) == 0, and falls through when a4(=table(-0x1)) != 0; its branch-likely delay slot `nop` at 0x4f90 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x4fa4 targets 0x4dd8, is taken when s6(=[a0+56]:1) >= a0(=[a0+57]:1+1) (signed), and falls through when s6(=[a0+56]:1) < a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x4fac targets 0x507c and is always taken.
  The `beq` branch at 0x4fbc targets 0x4fd4, is taken when (a6(?) & 0x4) == 0, and falls through when (a6(?) & 0x4) != 0.
  The `beq` branch at 0x4fe4 targets 0x5008, is taken when a2(?) >= a0(=[a0+57]:1+1) (signed), and falls through when a2(?) < a0(=[a0+57]:1+1) (signed).
  The `bne` branch at 0x4ff8 targets 0x4fb4, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `beq` branch at 0x5000 targets 0x4fd8 and is always taken.
  The `beq` branch at 0x5008 targets 0x4dd8, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x5014 targets 0x5048, is taken when s6(=[a0+56]:1) < a0(=[a0+57]:1+1) (signed), and falls through when s6(=[a0+56]:1) >= a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x501c targets 0x4dd8 and is always taken.
  The `beq` branch at 0x5044 targets 0x4dd8, is taken when s4(?) >= a0(=[a0+57]:1+1) (signed), and falls through when s4(?) < a0(=[a0+57]:1+1) (signed).
  The `bne` branch at 0x5058 targets 0x5024, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `bne` branch at 0x506c targets 0x504c, is taken when s4(?) < a0(=[a0+57]:1+1) (signed), and falls through when s4(?) >= a0(=[a0+57]:1+1) (signed).
  The `beq` branch at 0x5074 targets 0x4dd8 and is always taken.
  The `beq` branch at 0x5084 targets 0x4ff0 and is always taken.
  The return at 0x4f24 has v0 = ret(pcireg_tflush_get).

- `do_pcibr_rrb_count_valid` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x508c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x508c-0x525c (464 bytes).
  It occupies 464 bytes.
  8 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x5090, `lw` at 0x50cc, `lw` at 0x5110.
  The `jal` at 0x5138 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=0xd002, a6=0xc002.
  The `jal` at 0x524c calls cmn_err with a0=0x4, a1=sym(.rodata)+3504, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0xc002.
  The `beq` branch at 0x50c4 targets 0x519c, is taken when a6(=0xc002) == at(?), and falls through when a6(=0xc002) != at(?).
  The `beq` branch at 0x50dc targets 0x51bc, is taken when v1(?) == a1(=0xd002), and falls through when v1(?) != a1(=0xd002).
  The `beq` branch at 0x50e4 targets 0x5108, is taken when s0(=a1) == v0(=0xff), and falls through when s0(=a1) != v0(=0xff).
  The `beq` branch at 0x50ec targets 0x5108, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bltz` branch at 0x50f4 targets 0x5108, is taken when s1(=a2) < 0 (signed), and falls through when s1(=a2) >= 0 (signed).
  The `bne` branch at 0x50fc targets 0x5108, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0x5108 targets 0x524c, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x511c targets 0x5200, is taken when a6(=0xc002) == a1(?), and falls through when a6(=0xc002) != a1(?).
  The `beq` branch at 0x5130 targets 0x5220, is taken when a2(?) == a3(=0xd002), and falls through when a2(?) != a3(=0xd002).
  The `bne` branch at 0x516c targets 0x5178, is taken when a7(?) != t1(?), and falls through when a7(?) == t1(?).
  The `bne` branch at 0x5178 targets 0x5164, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0x51ac targets 0x50cc, is taken when t2(?) != t3(=0x36), and falls through when t2(?) == t3(=0x36).
  The `beq` branch at 0x51b4 targets 0x51d4 and is always taken.
  The `bne` branch at 0x51cc targets 0x50e4, is taken when t3(?) != t8(=0x24), and falls through when t3(?) == t8(=0x24).
  The `beq` branch at 0x51d4 targets 0x5240, is taken when s0(=a1) == t8(=0xff), and falls through when s0(=a1) != t8(=0xff).
  The `beq` branch at 0x51dc targets 0x5244, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bltz` branch at 0x51e4 targets 0x5244, is taken when s1(=a2) < 0 (signed), and falls through when s1(=a2) >= 0 (signed).
  The `beq` branch at 0x51f0 targets 0x5244, is taken when s1(=a2) >= 0x2 (signed), and falls through when s1(=a2) < 0x2 (signed).
  The `beq` branch at 0x51f8 targets 0x5244 and is always taken.
  The `bne` branch at 0x5210 targets 0x5124, is taken when ra(?) != at(=0x36), and falls through when ra(?) == at(=0x36).
  The `beq` branch at 0x5218 targets 0x5238 and is always taken.
  The `bne` branch at 0x5230 targets 0x5138, is taken when at(?) != v0(=0x24), and falls through when at(?) == v0(=0x24).
  The `beq` branch at 0x5238 targets 0x5138 and is always taken.
  The `bne` branch at 0x5244 targets 0x5110, is taken when v0(=one of 0x0, 0x1) != 0, and falls through when v0(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x5254 targets 0x5180 and is always taken.
  The return at 0x5194 has v0 = one of ?, 0x0.

- `do_pcibr_rrb_count_avail` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x525c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x525c-0x5370 (276 bytes).
  It occupies 276 bytes.
  4 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x525c, `lw` at 0x5288, `lw` at 0x5300.
  The `jal` at 0x52b8 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=?, a4=0xff.
  The `jal` at 0x5360 calls cmn_err with a0=0x4, a1=sym(.rodata)+3504, a2=a2 at entry (arg2), a3=?, a4=0xff.
  The `beq` branch at 0x5280 targets 0x5300, is taken when at(?) == v1(=0xc002), and falls through when at(?) != v1(=0xc002).
  The `beq` branch at 0x5294 targets 0x5320, is taken when v1(?) == a1(=0xd002), and falls through when v1(?) != a1(=0xd002).
  The `beq` branch at 0x529c targets 0x52b0, is taken when v0(=a1) == a4(=0xff), and falls through when v0(=a1) != a4(=0xff).
  The `beq` branch at 0x52a4 targets 0x52b0, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x52b0 targets 0x535c, is taken when a1(=one of 0x0, 0x1) == 0, and falls through when a1(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x52dc targets 0x52e8, is taken when a5(=0x8) == a2(?), and falls through when a5(=0x8) != a2(?).
  The `bne` branch at 0x52e8 targets 0x52d4, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x5310 targets 0x5288, is taken when a3(?) != a6(=0x36), and falls through when a3(?) == a6(=0x36).
  The `beq` branch at 0x5318 targets 0x5338 and is always taken.
  The `bne` branch at 0x5330 targets 0x529c, is taken when a6(?) != a7(=0x24), and falls through when a6(?) == a7(=0x24).
  The `beq` branch at 0x5338 targets 0x5350, is taken when v0(=a1) == a7(=0xff), and falls through when v0(=a1) != a7(=0xff).
  The `beq` branch at 0x5340 targets 0x5354, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `beq` branch at 0x5348 targets 0x5354 and is always taken.
  The `bne` branch at 0x5354 targets 0x52b8, is taken when a1(=one of 0x0, 0x1) != 0, and falls through when a1(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x5368 targets 0x52f0 and is always taken.
  The return at 0x52f8 has v0 = one of ?, 0x0.

- `do_pcibr_rrb_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x5370 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x5370-0x55a4 (564 bytes).
  It occupies 564 bytes.
  8 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x5380, `lw` at 0x53c0, `lw` at 0x5404.
  The `jal` at 0x5434 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=0xd002, a3=?.
  The `jal` at 0x54b0 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5594 calls cmn_err with a0=0x4, a1=sym(.rodata)+3504, a2=a2 at entry (arg2), a3=?, a7=0xc002.
  The `beq` branch at 0x53b8 targets 0x54e0, is taken when a7(=0xc002) == at(?), and falls through when a7(=0xc002) != at(?).
  The `beq` branch at 0x53d0 targets 0x5500, is taken when v1(?) == a0(=0xd002), and falls through when v1(?) != a0(=0xd002).
  The `beq` branch at 0x53d8 targets 0x53fc, is taken when s2(=a1) == v0(=0xff), and falls through when s2(=a1) != v0(=0xff).
  The `beq` branch at 0x53e0 targets 0x53fc, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bltz` branch at 0x53e8 targets 0x53fc, is taken when s3(=a2) < 0 (signed), and falls through when s3(=a2) >= 0 (signed).
  The `beq` branch at 0x53f0 targets 0x53fc, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x53fc targets 0x5590, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x5410 targets 0x5544, is taken when a7(=0xc002) == a0(?), and falls through when a7(=0xc002) != a0(?).
  The `beq` branch at 0x5424 targets 0x5564, is taken when a1(?) == a2(=0xd002), and falls through when a1(?) != a2(=0xd002).
  The `blez` branch at 0x5440 targets 0x54ac, is taken when s0(=a3) <= 0 (signed), and falls through when s0(=a3) > 0 (signed).
  The `beq` branch at 0x5484 targets 0x5498, is taken when t2(=0x8) == t8(?), and falls through when t2(=0x8) != t8(?).
  The `beq` branch at 0x549c targets 0x54ac, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bgtz` branch at 0x54a4 targets 0x5470, is taken when s0(?) > 0 (signed), and falls through when s0(?) <= 0 (signed).
  The `bne` branch at 0x54f0 targets 0x53c0, is taken when a3(?) != a4(=0x36), and falls through when a3(?) == a4(=0x36).
  The `beq` branch at 0x54f8 targets 0x5518 and is always taken.
  The `bne` branch at 0x5510 targets 0x53d8, is taken when a4(?) != a5(=0x24), and falls through when a4(?) == a5(=0x24).
  The `beq` branch at 0x5518 targets 0x5584, is taken when s2(=a1) == a5(=0xff), and falls through when s2(=a1) != a5(=0xff).
  The `beq` branch at 0x5520 targets 0x5588, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bltz` branch at 0x5528 targets 0x5588, is taken when s3(=a2) < 0 (signed), and falls through when s3(=a2) >= 0 (signed).
  The `beq` branch at 0x5534 targets 0x5588, is taken when s3(=a2) >= 0x2 (signed), and falls through when s3(=a2) < 0x2 (signed).
  The `beq` branch at 0x553c targets 0x5588 and is always taken.
  The `bne` branch at 0x5554 targets 0x5418, is taken when a7(?) != t0(=0x36), and falls through when a7(?) == t0(=0x36).
  The `beq` branch at 0x555c targets 0x557c and is always taken.
  The `bne` branch at 0x5574 targets 0x542c, is taken when t0(?) != t1(=0x24), and falls through when t0(?) == t1(=0x24).
  The `beq` branch at 0x557c targets 0x542c and is always taken.
  The `bne` branch at 0x5588 targets 0x5404, is taken when v0(=one of 0x0, 0x1) != 0, and falls through when v0(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x559c targets 0x54c0 and is always taken.
  The return at 0x54d8 has v0 = one of -0x1, 0x0.

- `do_pcibr_rrb_free` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x55a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x55a4-0x584c (680 bytes).
  It occupies 680 bytes.
  8 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x55b8, `lw` at 0x55f8, `lw` at 0x5648.
  The `jal` at 0x567c calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=a3 at entry (arg3), a7=0xc002.
  The `jal` at 0x56f4 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5708 calls do_pcibr_rrb_clear with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x583c calls cmn_err with a0=0x4, a1=sym(.rodata)+3504, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a7=0xc002.
  The `beq` branch at 0x55f0 targets 0x5778, is taken when a7(=0xc002) == at(?), and falls through when a7(=0xc002) != at(?).
  The `beq` branch at 0x5608 targets 0x5798, is taken when v1(?) == a0(=0xd002), and falls through when v1(?) != a0(=0xd002).
  The `beq` branch at 0x5610 targets 0x5640, is taken when s0(=a1) == v0(=0xff), and falls through when s0(=a1) != v0(=0xff).
  The `beq` branch at 0x5618 targets 0x5640, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bltz` branch at 0x5620 targets 0x5640, is taken when s2(=a2) < 0 (signed), and falls through when s2(=a2) >= 0 (signed).
  The `beq` branch at 0x5628 targets 0x5640, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x5634 targets 0x5640 and is always taken.
  The `beq` branch at 0x5640 targets 0x5838, is taken when v0(=one of 0x0, 0x1) == 0, and falls through when v0(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x5654 targets 0x57e0, is taken when a7(=0xc002) == a0(?), and falls through when a7(=0xc002) != a0(?).
  The `beq` branch at 0x566c targets 0x5800, is taken when a1(?) == a2(=0xd002), and falls through when a1(?) != a2(=0xd002).
  The `blez` branch at 0x568c targets 0x5820, is taken when s5(=a3) <= 0 (signed), and falls through when s5(=a3) > 0 (signed).
  The `beq` branch at 0x56b0 targets 0x56bc and is always taken.
  The `blez` branch at 0x56b8 targets 0x56f0, is taken when s5(?) <= 0 (signed), and falls through when s5(?) > 0 (signed).
  The `bne` branch at 0x56d0 targets 0x56e4, is taken when t1(?) != t2(?), and falls through when t1(?) == t2(?).
  The `bne` branch at 0x56e8 targets 0x56b8, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x5700 targets 0x5724 and is always taken.
  The `beq` branch at 0x571c targets 0x5748, is taken when s2(?) >= 0x8 (signed), and falls through when s2(?) < 0x8 (signed).
  The `bne` branch at 0x572c targets 0x5708, is taken when (s4(?) & t8(?)) != 0, and falls through when (s4(?) & t8(?)) == 0.
  The `bne` branch at 0x5740 targets 0x5724, is taken when s2(?) < 0x8 (signed), and falls through when s2(?) >= 0x8 (signed).
  The `bne` branch at 0x5788 targets 0x55f8, is taken when ra(?) != at(=0x36), and falls through when ra(?) == at(=0x36).
  The `beq` branch at 0x5790 targets 0x57b4 and is always taken.
  The `bne` branch at 0x57a8 targets 0x5610, is taken when at(?) != v1(=0x24), and falls through when at(?) == v1(=0x24).
  The `beq` branch at 0x57b4 targets 0x582c, is taken when s0(=a1) == v0(=0xff), and falls through when s0(=a1) != v0(=0xff).
  The `beq` branch at 0x57bc targets 0x5830, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bltz` branch at 0x57c4 targets 0x5830, is taken when s2(=a2) < 0 (signed), and falls through when s2(=a2) >= 0 (signed).
  The `beq` branch at 0x57d0 targets 0x5830, is taken when s2(=a2) >= 0x2 (signed), and falls through when s2(=a2) < 0x2 (signed).
  The `beq` branch at 0x57d8 targets 0x5830 and is always taken.
  The `bne` branch at 0x57f0 targets 0x565c, is taken when a0(?) != a1(=0x36), and falls through when a0(?) == a1(=0x36).
  The `beq` branch at 0x57f8 targets 0x5818 and is always taken.
  The `bne` branch at 0x5810 targets 0x5674, is taken when a1(?) != a2(=0x24), and falls through when a1(?) == a2(=0x24).
  The `beq` branch at 0x5818 targets 0x5674 and is always taken.
  The `beq` branch at 0x5824 targets 0x56f0 and is always taken.
  The `bne` branch at 0x5830 targets 0x5648, is taken when v0(=one of 0x0, 0x1) != 0, and falls through when v0(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x5844 targets 0x5750 and is always taken.
  The return at 0x5770 has v0 = one of -0x1, 0x0.
  The instructions from 0x563c to 0x563c are not reached by any path from the entry, and their branches are not listed.

- `do_pcibr_rrb_free_all` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x584c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x584c-0x5940 (244 bytes).
  It occupies 244 bytes.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x5858, `lw` at 0x5894, `lw` at 0x5900.
  The `sw` at 0x58d8 stores 4 bytes to ?.
  The `jal` at 0x58b8 calls do_pcibr_rrb_free with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=?, a3=0x8.
  The `beq` branch at 0x5888 targets 0x5900, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0x58a0 targets 0x5920, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `bne` branch at 0x58d4 targets 0x58ac, is taken when s0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when s0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x5910 targets 0x5894, is taken when a0(?) != a1(=0x36), and falls through when a0(?) == a1(=0x36).
  The `beq` branch at 0x5918 targets 0x5938 and is always taken.
  The `bne` branch at 0x5930 targets 0x58a8, is taken when a1(?) != a2(=0x24), and falls through when a1(?) == a2(=0x24).
  The `beq` branch at 0x5938 targets 0x58a8 and is always taken.
  The return at 0x58f8 has v0 = ret(do_pcibr_rrb_free).

- `do_pcibr_rrb_clear` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x5940 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x5940-0x59ec (172 bytes).
  It occupies 172 bytes.
  The `jal` at 0x5958 calls pcireg_rrb_status_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5978 calls pcireg_rrb_status_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x59a0 calls pcireg_rrb_clear_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x59a8 calls pcireg_rrb_status_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x59bc calls pcireg_rrb_status_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x5970 targets 0x598c, is taken when (s1(?) & v0(=ret(pcireg_rrb_status_get))) == 0, and falls through when (s1(?) & v0(=ret(pcireg_rrb_status_get))) != 0.
  The `bne` branch at 0x5984 targets 0x5978, is taken when (s1(?) & v0(=ret(pcireg_rrb_status_get))) != 0, and falls through when (s1(?) & v0(=ret(pcireg_rrb_status_get))) == 0.
  The `beq` branch at 0x5998 targets 0x59d0, is taken when (s2(?) & a0(=ret(pcireg_rrb_status_get))) == 0, and falls through when (s2(?) & a0(=ret(pcireg_rrb_status_get))) != 0.
  The `beq` branch at 0x59b4 targets 0x59d4, is taken when (s2(?) & v0(=ret(pcireg_rrb_status_get))) == 0, and falls through when (s2(?) & v0(=ret(pcireg_rrb_status_get))) != 0.
  The `bne` branch at 0x59c8 targets 0x59bc, is taken when (s2(?) & v0(=ret(pcireg_rrb_status_get))) != 0, and falls through when (s2(?) & v0(=ret(pcireg_rrb_status_get))) == 0.
  The return at 0x59e4 has v0 = ret(pcireg_rrb_status_get).

- `do_pcibr_rrb_flush` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x59ec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x59ec-0x5a8c (160 bytes).
  It occupies 160 bytes.
  The `jal` at 0x5a10 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5a44 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x5a50 calls do_pcibr_rrb_clear with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x5a68 calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=ret(pcireg_rrb_get), a3=?.
  The `beq` branch at 0x5a30 targets 0x5a4c, is taken when (a5(?) & v0(=ret(pcireg_rrb_get))) == 0, and falls through when (a5(?) & v0(=ret(pcireg_rrb_get))) != 0.
  The `beq` branch at 0x5a5c targets 0x5a70, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The return at 0x5a84 has v0 = one of ret(do_pcibr_rrb_clear), ret(pcireg_rrb_set).

- `pcibr_rrb_alloc_init` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x5a8c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x5a8c-0x5c5c (464 bytes).
  It occupies 464 bytes.
  The `ld` at 0x5a9c loads 8 bytes from a0 (arg0 at entry) +0x8.
  3 such `lw` accesses load 4 bytes from (a0 + ((a2 + (a1 << 0x2)) << 0x2)) +0x570, including `lw` at 0x5ac8, `lw` at 0x5b30, `lw` at 0x5ba0.
  The `sw` at 0x5b0c stores 4 bytes to ((a1 << 0x2) + a0) +0x530.
  2 such `sw` accesses store 4 bytes to (a0 + ((a2 + (a1 << 0x2)) << 0x2)) +0x570, including `sw` at 0x5b44, `sw` at 0x5bb4.
  The `lw` at 0x5b48 loads 4 bytes from ((a1 << 0x2) + a0) +0x530.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x5b54, `lw` at 0x5b8c.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x5b64, `sw` at 0x5b94.
  The `lh` at 0x5bf0 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lw` at 0x5c24 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x5b1c calls do_pcibr_rrb_alloc with a0=[a0+8]:8, a1=?, a2=a2 at entry (arg2), a3=0x1.
  The `jal` at 0x5bb0 calls do_pcibr_rrb_free with a0=[a0+8]:8, a1=?, a2=a2 at entry (arg2), a3=0x1.
  The `jal` at 0x5c28 calls pcibr_debug with a0=0x20, a1=[a0+4], a2=sym(.rodata)+3504, a3=[(a0 + ((a2 + (a1 << 0x2)) << 0x2))+1392], a5=a3 at entry (arg3), a7=a2 at entry (arg2).
  The `jal` at 0x5c44 calls pcibr_rrb_debug with a0=sym(.rodata)+3504, a1=a0 at entry (arg0), a2=?, a3=?.
  The `beq` branch at 0x5af4 targets 0x5b68, is taken when s1(=[(a0 + ((a2 + (a1 << 0x2)) << 0x2))+1392]) >= a3 (signed), and falls through when s1(=[(a0 + ((a2 + (a1 << 0x2)) << 0x2))+1392]) < a3 (signed).
  The `beq` branch at 0x5b04 targets 0x5b48 and is always taken.
  The `bltz` branch at 0x5b24 targets 0x5b6c, is taken when v0(=ret(do_pcibr_rrb_alloc)) < 0 (signed), and falls through when v0(=ret(do_pcibr_rrb_alloc)) >= 0 (signed).
  The `beq` branch at 0x5b40 targets 0x5b6c, is taken when s1(?) >= s2(=a3) (signed), and falls through when s1(?) < s2(=a3) (signed).
  The `bgtz` branch at 0x5b4c targets 0x5b0c, is taken when a2(=[((a1 << 0x2) + a0)+1328]) > 0 (signed), and falls through when a2(=[((a1 << 0x2) + a0)+1328]) <= 0 (signed).
  The `blez` branch at 0x5b58 targets 0x5b6c, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x5b60 targets 0x5b10 and is always taken.
  The `beq` branch at 0x5b84 targets 0x5bc8, is taken when s2(=a3) >= s1(?) (signed), and falls through when s2(=a3) < s1(?) (signed).
  The `bne` branch at 0x5bc0 targets 0x5b8c, is taken when s2(=a3) < s1(?) (signed), and falls through when s2(=a3) >= s1(?) (signed).
  The `beq` branch at 0x5be4 targets 0x5c04, is taken when at(=a1) == v0(=0xff), and falls through when at(=a1) != v0(=0xff).
  The `beq` branch at 0x5bf8 targets 0x5c04, is taken when v1(=[a0+114]:2) == a0(=0x2), and falls through when v1(=[a0+114]:2) != a0(=0x2).
  The return at 0x5c54 has v0 = ret(pcibr_rrb_debug).

- `pcibr_rrb_alloc_more` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x5c5c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x5c5c-0x5db0 (340 bytes).
  It occupies 340 bytes.
  The `ld` at 0x5c64 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `sw` at 0x5cd0 stores 4 bytes to ((a1 << 0x2) + a0) +0x530.
  The `lw` at 0x5cf4 loads 4 bytes from (((a2 + (a1 << 0x2)) << 0x2) + a0) +0x570.
  The `sw` at 0x5d04 stores 4 bytes to (((a2 + (a1 << 0x2)) << 0x2) + a0) +0x570.
  The `lw` at 0x5d08 loads 4 bytes from ((a1 << 0x2) + a0) +0x530.
  The `lw` at 0x5d18 loads 4 bytes from ?.
  The `sw` at 0x5d2c stores 4 bytes to ?.
  The `lh` at 0x5d44 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `lw` at 0x5d70 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `jal` at 0x5ce0 calls do_pcibr_rrb_alloc with a0=[a0+8]:8, a1=?, a2=a2 at entry (arg2), a3=0x1, a5=[((a1 << 0x2) + a0)+1328]-1.
  The `jal` at 0x5d74 calls pcibr_debug with a0=0x20, a1=[a0+4], a2=sym(.rodata)+3504, a3=?, a4=a3 at entry (arg3), a6=a2 at entry (arg2).
  The `jal` at 0x5d84 calls pcibr_rrb_debug with a0=sym(.rodata)+3504, a1=a0 at entry (arg0), a2=?, a3=?.
  The `blez` branch at 0x5ca0 targets 0x5d30, is taken when a3 <= 0 (signed), and falls through when a3 > 0 (signed).
  The `beq` branch at 0x5cc8 targets 0x5d08 and is always taken.
  The `bltz` branch at 0x5ce8 targets 0x5d38, is taken when v0(=ret(do_pcibr_rrb_alloc)) < 0 (signed), and falls through when v0(=ret(do_pcibr_rrb_alloc)) >= 0 (signed).
  The `beq` branch at 0x5d00 targets 0x5d34, is taken when s0(?) >= s3(=a3) (signed), and falls through when s0(?) < s3(=a3) (signed).
  The `bgtz` branch at 0x5d0c targets 0x5cd0, is taken when a5(=[((a1 << 0x2) + a0)+1328]) > 0 (signed), and falls through when a5(=[((a1 << 0x2) + a0)+1328]) <= 0 (signed).
  The `blez` branch at 0x5d20 targets 0x5d34, is taken when a0(?) <= 0 (signed), and falls through when a0(?) > 0 (signed).
  The `beq` branch at 0x5d28 targets 0x5cd4 and is always taken.
  The `beq` branch at 0x5d3c targets 0x5d54, is taken when s8(=a1) == a2(=0xff), and falls through when s8(=a1) != a2(=0xff).
  The `beq` branch at 0x5d48 targets 0x5d54, is taken when a3(=[a0+114]:2) == a4(=0x2), and falls through when a3(=[a0+114]:2) != a4(=0x2).
  The return at 0x5da8 has v0 = ret(pcibr_rrb_debug).

- `pcibr_rrb_flush` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x5db0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x5db0-0x5f2c (380 bytes).
  It occupies 380 bytes.
  The `ld` at 0x5dd8 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(pciio_info_mfast_get)+8]:8 +0x4, including `lw` at 0x5ddc, `lw` at 0x5e08, `lw` at 0x5eec.
  The `lbu` at 0x5de8 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `jal` at 0x5db8 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5dd0 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x5e28 calls pcireg_rrb_get with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x5e40 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+140, a1=?, a2=?, a3=?.
  The `jal` at 0x5e90 calls do_pcibr_rrb_flush with a0=[ret(pciio_info_mfast_get)+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x5ebc calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `beq` branch at 0x5e00 targets 0x5eec, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0x5e14 targets 0x5f0c, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `beq` branch at 0x5e68 targets 0x5e84 and is always taken.
  The `beq` branch at 0x5e7c targets 0x5eac, is taken when s2(?) >= 0x8 (signed), and falls through when s2(?) < 0x8 (signed).
  The `bne` branch at 0x5e88 targets 0x5e70, is taken when s3(?) != t9(?), and falls through when s3(?) == t9(?).
  The `bne` branch at 0x5ea4 targets 0x5e84, is taken when s2(?) < 0x8 (signed), and falls through when s2(?) >= 0x8 (signed).
  The `bne` branch at 0x5efc targets 0x5e08, is taken when a2(?) != a3(=0x36), and falls through when a2(?) == a3(=0x36).
  The `beq` branch at 0x5f04 targets 0x5f24 and is always taken.
  The `bne` branch at 0x5f1c targets 0x5e1c, is taken when a3(?) != a4(=0x24), and falls through when a3(?) == a4(=0x24).
  The `beq` branch at 0x5f24 targets 0x5e1c and is always taken.
  The return at 0x5ee4 has v0 = ret(mutex_io_spinunlock).

- `pcibr_wrb_flush` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x5f2c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x5f2c-0x5f68 (60 bytes).
  It occupies 60 bytes.
  The `lbu` at 0x5f44 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0x5f48 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  The `jal` at 0x5f34 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5f40 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x5f4c calls pcireg_wrb_flush_get with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=?, a3=?.
  The return at 0x5f60 has v0 = 0x0.

- `pcibr_rrb_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x5f68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x5f68-0x636c (1028 bytes).
  It occupies 1028 bytes.
  The `lbu` at 0x5f8c loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `ld` at 0x5fa0 loads 8 bytes from ret(pciio_info_mfast_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(pciio_info_mfast_get)+8]:8 +0x4, including `lw` at 0x5fb4, `lw` at 0x5fe8, `lw` at 0x6054.
  2 such `lw` accesses load 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x5f0, including `lw` at 0x6008, `lw` at 0x6078.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0x6030, `lw` at 0x60bc, `lw` at 0x622c.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x6038, `sw` at 0x623c, `sw` at 0x62b8.
  3 such `lw` accesses load 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x530, including `lw` at 0x6044, `lw` at 0x6088, `lw` at 0x6228.
  The `sw` at 0x604c stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x550.
  The `lw` at 0x6090 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x574.
  The `lw` at 0x6094 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x570.
  The `lw` at 0x60a8 loads 4 bytes from a1 (arg1 at entry) +0x0.
  The `lw` at 0x60f4 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `sw` at 0x61e8 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `sw` at 0x61fc stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `lw` at 0x6208 loads 4 bytes from ret(pciio_info_mfast_get) +0x524.
  The `sw` at 0x621c stores 4 bytes to ret(pciio_info_mfast_get) +0x524.
  The `sw` at 0x6220 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x574.
  The `sw` at 0x6224 stores 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x570.
  The `lw` at 0x6240 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x550.
  2 such `sw` accesses store 4 bytes to (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x530, including `sw` at 0x6248, `sw` at 0x62ac.
  The `jal` at 0x5f84 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x5f94 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0x5fa8 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+140, a1=?, a2=?, a3=?.
  The `jal` at 0x61b4 calls do_pcibr_rrb_alloc with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?.
  The `jal` at 0x61d0 calls do_pcibr_rrb_alloc with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x1, a3=?, a6=[ret(pciio_info_mfast_get)+8]:8.
  The `jal` at 0x62c4 calls pcibr_rrb_debug with a0=sym(.rodata)+3504, a1=ret(pciio_info_mfast_get), a2=?, a3=?, a4=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2))+1328], a5=(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)).
  The `jal` at 0x62f8 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x6344 calls do_pcibr_rrb_free with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x0, a3=?.
  The `jal` at 0x635c calls do_pcibr_rrb_free with a0=[ret(pciio_info_mfast_get)+8]:8, a1=[ret(pciio_hostinfo_get)+540]:1, a2=0x1, a3=?.
  The `beq` branch at 0x5fdc targets 0x631c, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0x5ff8 targets 0x6050, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `bgez` branch at 0x600c targets 0x6084, is taken when v1(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1520]) >= 0 (signed), and falls through when v1(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1520]) < 0 (signed).
  The `bne` branch at 0x6034 targets 0x601c, is taken when a1(?) < s6(=one of 0x2, 0x4) (signed), and falls through when a1(?) >= s6(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x6048 targets 0x608c and is always taken.
  The `bne` branch at 0x6064 targets 0x6000, is taken when a4(?) != a5(=0x24), and falls through when a4(?) == a5(=0x24).
  The `bltz` branch at 0x607c targets 0x6014, is taken when a5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1520]) < 0 (signed), and falls through when a5(=[(ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4))+1520]) >= 0 (signed).
  The `beq` branch at 0x609c targets 0x60e8, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `bne` branch at 0x60a4 targets 0x60f0, is taken when s5(=a2) != 0, and falls through when s5(=a2) == 0.
  The `bne` branch at 0x60d8 targets 0x6110, is taken when a1(?) < t1(?) (signed), and falls through when a1(?) >= t1(?) (signed).
  The `beq` branch at 0x60e0 targets 0x6170 and is always taken.
  The `beq` branch at 0x60e8 targets 0x60ac, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0x60f0 targets 0x60ac and is always taken.
  The `beq` branch at 0x6108 targets 0x6170, is taken when a1(?) >= v1(?) (signed), and falls through when a1(?) < v1(?) (signed).
  The `beq` branch at 0x6110 targets 0x6134, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `beq` branch at 0x6118 targets 0x6128, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0x6120 targets 0x6134, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x612c targets 0x613c and is always taken.
  The `beq` branch at 0x6144 targets 0x6170, is taken when a1(?) >= a4(?) (signed), and falls through when a1(?) < a4(?) (signed).
  The `beq` branch at 0x614c targets 0x60f8, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `beq` branch at 0x6154 targets 0x6164, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0x615c targets 0x60f8, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `beq` branch at 0x6168 targets 0x6100 and is always taken.
  The `beq` branch at 0x6170 targets 0x6180, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x617c targets 0x6314, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0x6184 targets 0x6194, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0x618c targets 0x6314, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `bltz` branch at 0x6194 targets 0x633c, is taken when s1(?) < 0 (signed), and falls through when s1(?) >= 0 (signed).
  The `bltz` branch at 0x619c targets 0x6354, is taken when s0(?) < 0 (signed), and falls through when s0(?) >= 0 (signed).
  The `blez` branch at 0x61a4 targets 0x61bc, is taken when s1(?) <= 0 (signed), and falls through when s1(?) > 0 (signed).
  The `blez` branch at 0x61bc targets 0x61d8, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `beq` branch at 0x61dc targets 0x61f4, is taken when s4(=a1) == 0, and falls through when s4(=a1) != 0.
  The `bne` branch at 0x61e4 targets 0x61fc, is taken when s5(=a2) != 0, and falls through when s5(=a2) == 0.
  The `beq` branch at 0x61ec targets 0x6204 and is always taken.
  The `beq` branch at 0x61f4 targets 0x6204, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `blez` branch at 0x6244 targets 0x62a0, is taken when s6(=one of 0x2, 0x4) <= 0 (signed), and falls through when s6(=one of 0x2, 0x4) > 0 (signed).
  The `beq` branch at 0x6274 targets 0x62a0, is taken when a1(?) >= s6(=one of 0x2, 0x4) (signed), and falls through when a1(?) < s6(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x6298 targets 0x6250, is taken when a1(?) < s6(=one of 0x2, 0x4) (signed), and falls through when a1(?) >= s6(=one of 0x2, 0x4) (signed).
  The `blez` branch at 0x62a0 targets 0x62c0, is taken when a2(?) <= 0 (signed), and falls through when a2(?) > 0 (signed).
  The `beq` branch at 0x6314 targets 0x62d0 and is always taken.
  The `bne` branch at 0x632c targets 0x5fe8, is taken when a2(?) != a3(=0x36), and falls through when a2(?) == a3(=0x36).
  The `beq` branch at 0x6334 targets 0x6070 and is always taken.
  The `beq` branch at 0x634c targets 0x619c and is always taken.
  The `beq` branch at 0x6364 targets 0x61a4 and is always taken.
  The return at 0x630c has v0 = one of -0x1, 0x0.

- `pcibr_rrb_check` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x636c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x636c-0x64a0 (308 bytes).
  It occupies 308 bytes.
  The `lbu` at 0x63bc loads 1 byte from ret(pciio_info_mfast_get) +0x39.
  The `lbu` at 0x63c0 loads 1 byte from ret(pciio_hostinfo_get) +0x21c.
  The `lw` at 0x6408 loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x570.
  The `sw` at 0x6410 stores 4 bytes to a1 (arg1 at entry) +0x0.
  The `lw` at 0x641c loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x2)) +0x530.
  The `sw` at 0x6424 stores 4 bytes to a3 (arg3 at entry) +0x0.
  The `lw` at 0x645c loads 4 bytes from (ret(pciio_info_mfast_get) + ([ret(pciio_hostinfo_get)+540]:1 << 0x4)) +0x574.
  The `sw` at 0x6464 stores 4 bytes to a2 (arg2 at entry) +0x0.
  The `lw` at 0x6478 loads 4 bytes from ?.
  The `sw` at 0x647c stores 4 bytes to a4 (arg4 at entry) +0x0.
  The `jal` at 0x6390 calls pciio_hostinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x63a8 calls pciio_info_mfast_get with a0=ret(pciio_hostinfo_get), a1=?, a2=?, a3=?, a7=-0x1.
  The `jal` at 0x63e0 calls mutex_spinlock with a0=ret(pciio_info_mfast_get)+140, a1=?, a2=?, a3=?, a7=-0x1.
  The `jal` at 0x6480 calls mutex_io_spinunlock with a0=ret(pciio_info_mfast_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=([ret(pciio_hostinfo_get)+540]:1 << 0x4), a3=([ret(pciio_hostinfo_get)+540]:1 << 0x2).
  The `beq` branch at 0x63a0 targets 0x6430, is taken when v0(=ret(pciio_hostinfo_get)) == 0, and falls through when v0(=ret(pciio_hostinfo_get)) != 0.
  The `beq` branch at 0x63b4 targets 0x6498, is taken when v0(=ret(pciio_info_mfast_get)) == 0, and falls through when v0(=ret(pciio_info_mfast_get)) != 0.
  The `beq` branch at 0x63d0 targets 0x6490, is taken when at(=[ret(pciio_hostinfo_get)+540]:1) >= v0(=[ret(pciio_info_mfast_get)+57]:1+1) (signed), and falls through when at(=[ret(pciio_hostinfo_get)+540]:1) < v0(=[ret(pciio_info_mfast_get)+57]:1+1) (signed).
  The `beq` branch at 0x63fc targets 0x6454, is taken when s1(=a1) == 0, and falls through when s1(=a1) != 0.
  The `bne` branch at 0x640c targets 0x6458, is taken when s4(=a2) != 0, and falls through when s4(=a2) == 0.
  The `beq` branch at 0x6414 targets 0x6468, is taken when s3(=a3) == 0, and falls through when s3(=a3) != 0.
  The `bne` branch at 0x6420 targets 0x646c, is taken when s2(=a4) != 0, and falls through when s2(=a4) == 0.
  The `beq` branch at 0x6428 targets 0x6480 and is always taken.
  The `beq` branch at 0x6454 targets 0x6414, is taken when s4(=a2) == 0, and falls through when s4(=a2) != 0.
  The `bne` branch at 0x6460 targets 0x6418, is taken when s3(=a3) != 0, and falls through when s3(=a3) == 0.
  The `beq` branch at 0x6468 targets 0x6480, is taken when s2(=a4) == 0, and falls through when s2(=a4) != 0.
  The `beq` branch at 0x6488 targets 0x6430 and is always taken.
  The `beq` branch at 0x6490 targets 0x6434 and is always taken.
  The `beq` branch at 0x6498 targets 0x6434 and is always taken.
  The return at 0x644c has v0 = one of -0x1, 0x0.

- `pcibr_slot_initial_rrb_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x6874 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x6874-0x6c28 (948 bytes).
  It occupies 948 bytes.
  The `lbu` at 0x68b4 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `ld` at 0x68c8 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(hwgraph_fastinfo_get)+8]:8 +0x4, including `lw` at 0x68cc, `lw` at 0x68e4, `lw` at 0x6aa0.
  8 such `sw` accesses store 4 bytes to ?, including `sw` at 0x6928, `sw` at 0x69f4, `sw` at 0x6a20.
  3 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0x692c, `lh` at 0x69a4, `lh` at 0x6af8.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x78, including `lw` at 0x6980, `lw` at 0x6a9c.
  The `ld` at 0x6994 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x120.
  The `ld` at 0x69a0 loads 8 bytes from [(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+288]:8 +0x0.
  2 such `lw` accesses load 4 bytes from [[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+288]:8]:8 +0x14, including `lw` at 0x69b4, `lw` at 0x6b64.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x69f0, `lw` at 0x6a18.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x108, including `lw` at 0x6ae0, `lw` at 0x6b74.
  The `sw` at 0x6bcc stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x4)) +0x57c.
  The `jal` at 0x688c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6914 calls do_pcibr_rrb_count_valid with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x6978 calls pcibr_debug with a0=0x20, a1=a0 at entry (arg0), a2=sym(.rodata)+3504, a3=?.
  The `jal` at 0x6a90 calls pcibr_debug with a0=0x20, a1=a0 at entry (arg0), a2=sym(.rodata)+3504, a3=?.
  The `jal` at 0x6af0 calls do_pcibr_rrb_free_all with a0=ret(hwgraph_fastinfo_get), a1=[ret(hwgraph_fastinfo_get)+8]:8, a2=a1 at entry (arg1), a3=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+288]:8]:8+20], a4=-0x1, a5=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264].
  The `jal` at 0x6b94 calls do_pcibr_rrb_free with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=?, a3=0x8.
  The `beq` branch at 0x68ac targets 0x6a28, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0x68c0 targets 0x6a58, is taken when s1(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s1(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0x68dc targets 0x6aa0, is taken when v0(?) == v1(=0xc002), and falls through when v0(?) != v1(=0xc002).
  The `beq` branch at 0x68f4 targets 0x6ac0, is taken when v1(?) == a0(=0xd002), and falls through when v1(?) != a0(=0xd002).
  The `bne` branch at 0x6924 targets 0x6904, is taken when s3(?) < s2(=one of 0x2, 0x4) (signed), and falls through when s3(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x6930 targets 0x6a60, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == 0, and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != 0.
  The `beq` branch at 0x6938 targets 0x6a64, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == s3(=0x1), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != s3(=0x1).
  The `beq` branch at 0x6944 targets 0x6bd0, is taken when s1(=a1) == t9(=0xff), and falls through when s1(=a1) != t9(=0xff).
  The `beq` branch at 0x6950 targets 0x695c, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == ra(=0x2), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != ra(=0x2).
  The `beq` branch at 0x699c targets 0x69b4, is taken when (v1(?) & 0x2) == 0, and falls through when (v1(?) & 0x2) != 0.
  The `beq` branch at 0x69ac targets 0x6b54, is taken when a2(=[ret(hwgraph_fastinfo_get)+114]:2) == a1(=0x2), and falls through when a2(=[ret(hwgraph_fastinfo_get)+114]:2) != a1(=0x2).
  The `beq` branch at 0x69bc targets 0x6ae0, is taken when a3(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+288]:8]:8+20]) == a4(=-0x1), and falls through when a3(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+288]:8]:8+20]) != a4(=-0x1).
  The `blez` branch at 0x69c4 targets 0x6a28, is taken when s2(=one of 0x2, 0x4) <= 0 (signed), and falls through when s2(=one of 0x2, 0x4) > 0 (signed).
  The `beq` branch at 0x69f8 targets 0x6a24, is taken when v0(?) >= s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) < s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x6a1c targets 0x69d4, is taken when v0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x6a58 targets 0x6a28 and is always taken.
  The `beq` branch at 0x6a64 targets 0x6a7c, is taken when s1(=a1) == t0(=0xff), and falls through when s1(=a1) != t0(=0xff).
  The `beq` branch at 0x6a70 targets 0x6a7c, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == t1(=0x2), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != t1(=0x2).
  The `beq` branch at 0x6a98 targets 0x6984 and is always taken.
  The `bne` branch at 0x6ab0 targets 0x68e4, is taken when a3(?) != a4(=0x36), and falls through when a3(?) == a4(=0x36).
  The `beq` branch at 0x6ab8 targets 0x6ad8 and is always taken.
  The `bne` branch at 0x6ad0 targets 0x68fc, is taken when a4(?) != a5(=0x24), and falls through when a4(?) == a5(=0x24).
  The `beq` branch at 0x6ad8 targets 0x68fc and is always taken.
  The `bne` branch at 0x6ae4 targets 0x69c4, is taken when a5(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) != 0, and falls through when a5(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) == 0.
  The `beq` branch at 0x6b00 targets 0x6bd8, is taken when a6(=[ret(hwgraph_fastinfo_get)+114]:2) == 0, and falls through when a6(=[ret(hwgraph_fastinfo_get)+114]:2) != 0.
  The `bne` branch at 0x6b08 targets 0x6b4c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x6b28 targets 0x6b4c, is taken when v0(?) >= s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) < s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x6b44 targets 0x6b14, is taken when v0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x6b4c targets 0x6a28 and is always taken.
  The `beq` branch at 0x6b54 targets 0x6b64, is taken when a1(=0x2) == s1(=a1), and falls through when a1(=0x2) != s1(=a1).
  The `bne` branch at 0x6b5c targets 0x69b4, is taken when s1(=a1) != t1(=0x3), and falls through when s1(=a1) == t1(=0x3).
  The `bne` branch at 0x6b6c targets 0x69c4, is taken when t2(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+288]:8]:8+20]) != t3(=-0x1), and falls through when t2(=[[[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+288]:8]:8+20]) == t3(=-0x1).
  The `bne` branch at 0x6b78 targets 0x69c4, is taken when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) != 0, and falls through when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) == 0.
  The `bne` branch at 0x6bb0 targets 0x6b88, is taken when s2(?) < 0x2 (signed), and falls through when s2(?) >= 0x2 (signed).
  The `beq` branch at 0x6bc8 targets 0x6a28 and is always taken.
  The `beq` branch at 0x6bd0 targets 0x6960 and is always taken.
  The `bne` branch at 0x6bd8 targets 0x6b4c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x6bfc targets 0x6b4c, is taken when v0(?) >= s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) < s2(=one of 0x2, 0x4) (signed).
  The `bne` branch at 0x6c18 targets 0x6be8, is taken when v0(?) < s2(=one of 0x2, 0x4) (signed), and falls through when v0(?) >= s2(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x6c20 targets 0x6b4c and is always taken.
  The return at 0x6a50 has v0 = one of 0x0, 0x13, 0x16.

- `pcibr_initial_rrb` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x6c28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x6c28-0x6f80 (856 bytes).
  It occupies 856 bytes.
  The `ld` at 0x6c70 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  4 such `lw` accesses load 4 bytes from [ret(hwgraph_fastinfo_get)+8]:8 +0x4, including `lw` at 0x6c78, `lw` at 0x6cb4, `lw` at 0x6f34.
  2 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0x6c88, `lbu` at 0x6ef8.
  The `lbu` at 0x6c90 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  The `sw` at 0x6cfc stores 4 bytes to ret(hwgraph_fastinfo_get) +0x528.
  The `sw` at 0x6d14 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x52c.
  9 such `lw` accesses load 4 bytes from ?, including `lw` at 0x6d30, `lw` at 0x6d34, `lw` at 0x6d40.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0x6d74, `sw` at 0x6dac, `sw` at 0x6de0.
  2 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x34, including `lw` at 0x6e00, `lw` at 0x6f7c.
  The `jal` at 0x6c50 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x6ce8 calls do_pcibr_rrb_count_avail with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=?, a3=?.
  The `jal` at 0x6cf8 calls do_pcibr_rrb_count_avail with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x1, a2=?, a3=?.
  The `jal` at 0x6e54 calls pcibr_rrb_debug with a0=sym(.rodata)+3504, a1=ret(hwgraph_fastinfo_get), a2=?, a3=?, a5=0x1, a7=sp-88.
  The `jal` at 0x6eec calls pcibr_slot_initial_rrb_alloc with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x6cac targets 0x6f34, is taken when at(?) == v0(=0xc002), and falls through when at(?) != v0(=0xc002).
  The `beq` branch at 0x6cc0 targets 0x6f54, is taken when v0(?) == v1(=0xd002), and falls through when v0(?) != v1(=0xd002).
  The `beq` branch at 0x6ccc targets 0x6cdc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x6cd4 targets 0x6eec and is always taken.
  The `bne` branch at 0x6d6c targets 0x6da0, is taken when t0(?) < v1(?) (signed), and falls through when t0(?) >= v1(?) (signed).
  The `bne` branch at 0x6d80 targets 0x6d24, is taken when a0(?) < 0x2 (signed), and falls through when a0(?) >= 0x2 (signed).
  The `bne` branch at 0x6d8c targets 0x6e44, is taken when s3(=a2) < a2(?) (signed), and falls through when s3(=a2) >= a2(?) (signed).
  The `beq` branch at 0x6d98 targets 0x6f74 and is always taken.
  The `bne` branch at 0x6da0 targets 0x6e7c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x6da8 targets 0x6d78 and is always taken.
  The `bne` branch at 0x6dcc targets 0x6db4, is taken when a1(?) < s1(=one of 0x2, 0x4) (signed), and falls through when a1(?) >= s1(=one of 0x2, 0x4) (signed).
  The `blez` branch at 0x6dd8 targets 0x6df0, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `bne` branch at 0x6df8 targets 0x6e44, is taken when s3(=a2) < v0(?) (signed), and falls through when s3(=a2) >= v0(?) (signed).
  The `bne` branch at 0x6e08 targets 0x6df0, is taken when (a0(=[ret(hwgraph_fastinfo_get)+52]) & a1(?)) != 0, and falls through when (a0(=[ret(hwgraph_fastinfo_get)+52]) & a1(?)) == 0.
  The `bne` branch at 0x6e28 targets 0x6db0, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `blez` branch at 0x6e30 targets 0x6df0, is taken when a6(?) <= 0 (signed), and falls through when a6(?) > 0 (signed).
  The `beq` branch at 0x6e3c targets 0x6ddc and is always taken.
  The `bne` branch at 0x6e7c targets 0x6f2c, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x6e84 targets 0x6d78 and is always taken.
  The `bne` branch at 0x6ea8 targets 0x6e90, is taken when a2(?) < s1(=one of 0x2, 0x4) (signed), and falls through when a2(?) >= s1(=one of 0x2, 0x4) (signed).
  The `beq` branch at 0x6eb4 targets 0x6edc, is taken when v0(?) >= 0x3 (signed), and falls through when v0(?) < 0x3 (signed).
  The `beq` branch at 0x6ee4 targets 0x6cdc, is taken when s2(?) >= a5(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(?) < a5(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `bne` branch at 0x6f08 targets 0x6edc, is taken when s2(?) < s4(=a1) (signed), and falls through when s2(?) >= s4(=a1) (signed).
  The `bne` branch at 0x6f10 targets 0x6edc, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `bne` branch at 0x6f18 targets 0x6e8c, is taken when s6(?) != 0, and falls through when s6(?) == 0.
  The `beq` branch at 0x6f24 targets 0x6ebc and is always taken.
  The `beq` branch at 0x6f2c targets 0x6d78 and is always taken.
  The `bne` branch at 0x6f44 targets 0x6cb4, is taken when t3(?) != t8(=0x36), and falls through when t3(?) == t8(=0x36).
  The `beq` branch at 0x6f4c targets 0x6f6c and is always taken.
  The `bne` branch at 0x6f64 targets 0x6cc8, is taken when t8(?) != t9(=0x24), and falls through when t8(?) == t9(=0x24).
  The `beq` branch at 0x6f6c targets 0x6cc8 and is always taken.
  The `beq` branch at 0x6f78 targets 0x6e04 and is always taken.
  The return at 0x6e74 has v0 = 0x0.

- `pcibr_rrb_debug` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x6f80 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x6f80-0x7154 (468 bytes).
  It occupies 468 bytes.
  The `lw` at 0x6fb4 loads 4 bytes from a1 (arg1 at entry) +0x52c.
  The `lw` at 0x6fc0 loads 4 bytes from a1 (arg1 at entry) +0x528.
  4 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x6fc4, `lw` at 0x6fe4, `lw` at 0x705c.
  3 such `lh` accesses load 2 bytes from a1 (arg1 at entry) +0x72, including `lh` at 0x6fd0, `lh` at 0x700c, `lh` at 0x7084.
  3 such `lbu` accesses load 1 byte from a1 (arg1 at entry) +0x39, including `lbu` at 0x6ff0, `lbu` at 0x7068, `lbu` at 0x7150.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0x7018, `lw` at 0x7020, `lw` at 0x702c.
  The `jal` at 0x6fc8 calls pcibr_debug with a0=0x20, a1=[a1+4], a2=sym(.rodata)+3504, a3=a0 at entry (arg0), a4=[a1+1320], a5=[a1+1324].
  The `jal` at 0x6fe8 calls pcibr_debug with a0=0x20, a1=[a1+4], a2=sym(.rodata)+3504, a3=?.
  The `jal` at 0x7048 calls sprintf with a0=sp-320, a1=sym(.rodata)+3504, a2=?, a3=?.
  The `jal` at 0x7060 calls pcibr_debug with a0=0x20, a1=[a1+4], a2=sym(.rodata)+3504, a3=sp-320.
  The `jal` at 0x70ec calls sprintf with a0=sp-320, a1=sym(.rodata)+3504, a2=?, a3=?.
  The `jal` at 0x7144 calls pcibr_debug with a0=0x20, a1=[a1+4], a2=sym(.rodata)+3504, a3=?.
  The `beq` branch at 0x6fac targets 0x70fc, is taken when (at(=[sym(pcibr_debug_mask)]) & 0x20) == 0, and falls through when (at(=[sym(pcibr_debug_mask)]) & 0x20) != 0.
  The `beq` branch at 0x6fd4 targets 0x713c, is taken when a0(=[a1+114]:2) == 0, and falls through when a0(=[a1+114]:2) != 0.
  The `beq` branch at 0x6fdc targets 0x713c, is taken when a0(=[a1+114]:2) == a1(=0x1), and falls through when a0(=[a1+114]:2) != a1(=0x1).
  The `bltz` branch at 0x7000 targets 0x70fc, is taken when v0(=[a1+57]:1) < 0 (signed), and falls through when v0(=[a1+57]:1) >= 0 (signed).
  The `beq` branch at 0x7008 targets 0x7088 and is always taken.
  The `beq` branch at 0x707c targets 0x70fc, is taken when s0(?) >= a3(=[a1+57]:1+1) (signed), and falls through when s0(?) < a3(=[a1+57]:1+1) (signed).
  The `beq` branch at 0x7088 targets 0x70b4, is taken when a0(=[a1+114]:2) == 0, and falls through when a0(=[a1+114]:2) != 0.
  The `beq` branch at 0x7090 targets 0x70b4, is taken when a0(=[a1+114]:2) == s5(=0x1), and falls through when a0(=[a1+114]:2) != s5(=0x1).
  The `beq` branch at 0x7098 targets 0x7120, is taken when s3(=0xff) == s0(?), and falls through when s3(=0xff) != s0(?).
  The `bne` branch at 0x70a0 targets 0x7010, is taken when a0(=[a1+114]:2) != s4(=0x2), and falls through when a0(=[a1+114]:2) == s4(=0x2).
  The `beq` branch at 0x70ac targets 0x7010 and is always taken.
  The `beq` branch at 0x70b4 targets 0x7128, is taken when s3(=0xff) == s0(?), and falls through when s3(=0xff) != s0(?).
  The `beq` branch at 0x70bc targets 0x7130, is taken when a0(=[a1+114]:2) == s4(=0x2), and falls through when a0(=[a1+114]:2) != s4(=0x2).
  The `beq` branch at 0x70f4 targets 0x7054 and is always taken.
  The `beq` branch at 0x7120 targets 0x7010 and is always taken.
  The `beq` branch at 0x7128 targets 0x70c4 and is always taken.
  The `beq` branch at 0x7134 targets 0x70c4 and is always taken.
  The `beq` branch at 0x714c targets 0x6ff4 and is always taken.
  The return at 0x7118 has v0 = one of ?, [a1+57]:1, ret(pcibr_debug).

- `pcibr_hints_get` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x7154 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x7154-0x725c (264 bytes).
  It occupies 264 bytes.
  The `sd` at 0x7198 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sd` at 0x71a0 stores 8 bytes to ret(kmem_zalloc) +0x18.
  The `jal` at 0x7170 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4264, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0x718c calls kmem_zalloc with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0x71a8 calls hwgraph_info_add_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4264, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x71ec calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+4264, a2=sp-48, a3=?.
  The `jal` at 0x7240 calls cmn_err with a0=0x4, a1=sym(.rodata)+4264, a2=?, a3=?.
  The `jal` at 0x724c calls kmem_free with a0=?, a1=0x20, a2=?, a3=?.
  The `beq` branch at 0x7178 targets 0x71dc, is taken when s3(=a1) == 0, and falls through when s3(=a1) != 0.
  The `beq` branch at 0x7180 targets 0x71d4, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0x71b4 targets 0x71e4, is taken when v0(=ret(hwgraph_info_add_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_add_LBL)) != 0.
  The `beq` branch at 0x71bc targets 0x7238, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x71d4 targets 0x71c4 and is always taken.
  The `beq` branch at 0x71dc targets 0x71c4 and is always taken.
  The `beq` branch at 0x71f8 targets 0x7218, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0x7200 targets 0x723c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x7208 targets 0x723c, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x7210 targets 0x71c4 and is always taken.
  The `beq` branch at 0x7224 targets 0x7238, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The `bne` branch at 0x722c targets 0x723c, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0x7234 targets 0x71c4, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x7254 targets 0x71c4 and is always taken.
  The return at 0x71cc has v0 = one of ?, 0x0.

- `pcibr_hints_fix_some_rrbs` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x725c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x725c-0x72a8 (76 bytes).
  It occupies 76 bytes.
  The `sw` at 0x727c stores 4 bytes to ret(pcibr_hints_get) +0x8.
  The `jal` at 0x726c calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7298 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4264, a3=?.
  The `beq` branch at 0x7274 targets 0x728c, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x72a0 targets 0x7284 and is always taken.
  The return at 0x7284 has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_hints_fix_rrbs` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x72a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x72a8-0x72c4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0x72b0 calls pcibr_hints_fix_some_rrbs with a0=a0 at entry (arg0), a1=0xff, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x72bc has v0 = ret(pcibr_hints_fix_some_rrbs).

- `pcibr_hints_dualslot` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x72c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x72c4-0x7320 (92 bytes).
  It occupies 92 bytes.
  The `sb` at 0x72f8 stores 1 byte to (a2 + ret(pcibr_hints_get)) +0x0.
  The `jal` at 0x72d8 calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7310 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4264, a3=?.
  The `beq` branch at 0x72e0 targets 0x7308, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x7318 targets 0x7300 and is always taken.
  The return at 0x7300 has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_hints_intr_bits` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x7320 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x7320-0x736c (76 bytes).
  It occupies 76 bytes.
  The `sd` at 0x7344 stores 8 bytes to ret(pcibr_hints_get) +0x18.
  The `jal` at 0x7330 calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x735c calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4264, a3=?.
  The `beq` branch at 0x7338 targets 0x7354, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x7364 targets 0x734c and is always taken.
  The return at 0x734c has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_set_rrb_callback` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x736c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x736c-0x7398 (44 bytes).
  It occupies 44 bytes.
  The `sd` at 0x738c stores 8 bytes to ret(pcibr_hints_get) +0x10.
  The `jal` at 0x7378 calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `beq` branch at 0x7380 targets 0x7390, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The return at 0x7390 has v0 = ret(pcibr_hints_get).

- `pcibr_hints_handsoff` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x7398 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x7398-0x73e0 (72 bytes).
  It occupies 72 bytes.
  The `sw` at 0x73b4 stores 4 bytes to ret(pcibr_hints_get) +0xc.
  The `jal` at 0x73a4 calls pcibr_hints_get with a0=a0 at entry (arg0), a1=0x1, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x73d0 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4264, a3=0x1.
  The `beq` branch at 0x73ac targets 0x73c4, is taken when v0(=ret(pcibr_hints_get)) == 0, and falls through when v0(=ret(pcibr_hints_get)) != 0.
  The `beq` branch at 0x73d8 targets 0x73bc and is always taken.
  The return at 0x73bc has v0 = one of ret(pcibr_hints_get), ret(pcibr_debug).

- `pcibr_hints_subdevs` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x73e0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x73e0-0x7534 (340 bytes).
  It occupies 340 bytes.
  The `sd` at 0x7454 stores 8 bytes to ?.
  The `sd` at 0x7484 stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `jal` at 0x7414 calls sprintf with a0=sp-48, a1=sym(.rodata)+4264, a2=sym(.rodata)+4264, a3=a1 at entry (arg1), a4=-0x1.
  The `jal` at 0x7424 calls hwgraph_path_add with a0=a0 at entry (arg0), a1=sp-48, a2=sp-56, a3=?.
  The `jal` at 0x7440 calls hwgraph_info_get_LBL with a0=?, a1=sym(.rodata)+4264, a2=sp-64, a3=?, a5=-0x1.
  The `jal` at 0x746c calls kmem_zalloc with a0=0x8, a1=0x0, a2=?, a3=?.
  The `jal` at 0x748c calls hwgraph_info_add_LBL with a0=?, a1=sym(.rodata)+4264, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x74a0 calls hwgraph_info_get_LBL with a0=?, a1=sym(.rodata)+4264, a2=sp-64, a3=?.
  The `jal` at 0x74b8 calls kmem_free with a0=?, a1=0x8, a2=?, a3=?.
  The `jal` at 0x74d4 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4264, a3=?.
  The `jal` at 0x74f0 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4264, a3=?, a5=-0x1.
  The `jal` at 0x750c calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4264, a3=?.
  The `jal` at 0x7524 calls pcibr_debug with a0=0x2, a1=a0 at entry (arg0), a2=sym(.rodata)+4264, a3=?.
  The `beq` branch at 0x7434 targets 0x74e4, is taken when a5(=-0x1) == a0(?), and falls through when a5(=-0x1) != a0(?).
  The `beq` branch at 0x744c targets 0x746c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x7474 targets 0x7500, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x74b0 targets 0x7458, is taken when a2(?) == a3(?), and falls through when a2(?) != a3(?).
  The `beq` branch at 0x74c4 targets 0x751c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x74dc targets 0x7454 and is always taken.
  The `beq` branch at 0x74f8 targets 0x745c and is always taken.
  The `beq` branch at 0x7514 targets 0x745c and is always taken.
  The `beq` branch at 0x752c targets 0x745c and is always taken.
  The return at 0x7464 has v0 = one of ?, ret(pcibr_debug).

- `pcibr_intr_bits` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x7534 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x7534-0x7580 (76 bytes).
  It occupies 76 bytes.
  The `lbu` at 0x7534 loads 1 byte from a0 (arg0 at entry) +0x21c.
  The `beq` branch at 0x7548 targets 0x7570, is taken when a6(=[a0+540]:1) >= a2 (signed), and falls through when a6(=[a0+540]:1) < a2 (signed).
  The `beq` branch at 0x7550 targets 0x7578, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x7578 targets 0x7558 and is always taken.
  The return at 0x7568 has v0 = ?.
  The return at 0x7570 has v0 = 0x0.

- `pcibr_wrap_get` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x7580 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x7580-0x75e4 (100 bytes).
  It occupies 100 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x7580, `lw` at 0x75e0.
  The `lw` at 0x7584 loads 4 bytes from a0 (arg0 at entry) +0x4.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x8, including `sw` at 0x75ac, `sw` at 0x75bc.
  The `ld` at 0x75b4 loads 8 bytes from (a0 + ([a0+8]+1 << 0x3)) +0x8.
  The `jal` at 0x75d0 calls panic with a0=sym(.rodata)+4728, a1=a0 at entry (arg0), a2=[a0+8], a3=a3 at entry (arg3).
  The `beq` branch at 0x7594 targets 0x75cc, is taken when at(=[a0+4]) == a2(=[a0+8]), and falls through when at(=[a0+4]) != a2(=[a0+8]).
  The `beq` branch at 0x75dc targets 0x759c and is always taken.
  The return at 0x75c4 has v0 = [(a0 + ([a0+8]+1 << 0x3))+8]:8.

- `pcibr_wrap_put` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x75e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x75e4-0x7678 (148 bytes).
  It occupies 148 bytes.
  2 such `lw` accesses load 4 bytes from a1 (arg1 at entry) +0x4, including `lw` at 0x7604, `lw` at 0x7674.
  The `lw` at 0x7614 loads 4 bytes from a1 (arg1 at entry) +0x8.
  The `sd` at 0x7634 stores 8 bytes to (a1 + ([a1+4] << 0x3)) +0x10.
  The `sw` at 0x7638 stores 4 bytes to a1 (arg1 at entry) +0x4.
  The `jal` at 0x75fc calls mutex_spinlock with a0=a1 at entry (arg1), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x763c calls mutex_spinunlock with a0=a1 at entry (arg1), a1=ret(mutex_spinlock), a2=[a1+4], a3=?.
  The `jal` at 0x7660 calls panic with a0=sym(.rodata)+4728, a1=a1 at entry (arg1), a2=[a1+4], a3=?.
  The `beq` branch at 0x7620 targets 0x7658, is taken when at(=[a1+8]) == a5(?), and falls through when at(=[a1+8]) != a5(?).
  The `beq` branch at 0x7670 targets 0x7628 and is always taken.
  The return at 0x7650 has v0 = ret(mutex_spinunlock).

- `pcibr_force_interrupt` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x7678 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x7678-0x7760 (232 bytes).
  It occupies 232 bytes.
  The `ld` at 0x7680 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x7684 loads 2 bytes from [a0]:8 +0x72.
  The `lw` at 0x768c loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0x76e4 loads 8 bytes from ?.
  The `ld` at 0x7710 loads 8 bytes from table(sym(pdaindr)) +0x8.
  The `lbu` at 0x771c loads 1 byte from [table(sym(pdaindr))+8]:8 +0x528.
  The `lh` at 0x7728 loads 2 bytes from [table(sym(pdaindr))+8]:8 +0x42c.
  The `sd` at 0x775c stores 8 bytes to (([[table(sym(pdaindr))+8]:8+1068]:2 << 0x21) + one of 0x9200000001800090, 0x9200000001a00090) +0x0.
  The `jal` at 0x769c calls pcireg_force_intr_set with a0=[a0]:8, a1=[a0+8], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x76b8 calls pcireg_intr_status_get with a0=[a0]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x76e8 calls xtalk_intr_vector_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x76f4 calls xtalk_intr_cpuid_get with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x7690 targets 0x76b8, is taken when at(=[[a0]:8+114]:2) == 0, and falls through when at(=[[a0]:8+114]:2) != 0.
  The `beq` branch at 0x76cc targets 0x76a8, is taken when (v0(=ret(pcireg_intr_status_get)) & v1(?)) == 0, and falls through when (v0(=ret(pcireg_intr_status_get)) & v1(?)) != 0.
  The `beq` branch at 0x7758 targets 0x76a4 and is always taken.
  The return at 0x76b0 has v0 = ?.

- `pcibr_intrd` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x7760 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x7760-0x77d8 (120 bytes).
  It occupies 120 bytes.
  The `ld` at 0x7764 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0x7778 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ll` at 0x778c loads 4 bytes from ret(pcibr_wrap_get) +0x18.
  The `sc` at 0x7798 stores 4 bytes to ret(pcibr_wrap_get) +0x18.
  The `lw` at 0x77a4 loads 4 bytes from ret(pcibr_wrap_get) +0x18.
  The `jalr` at 0x7774 calls (unknown callee) with a0=[a0+32]:8, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x777c calls pcibr_wrap_get with a0=a0+104, a1=?, a2=?, a3=?.
  The `jal` at 0x77b0 calls ipsema with a0=a0+48, a1=?, a2=?, a3=?.
  The `jal` at 0x77c8 calls pcibr_force_interrupt with a0=ret(pcibr_wrap_get), a1=ret(pcibr_wrap_get)+24, a2=-0x1, a3=[ret(pcibr_wrap_get)+24]-1.
  The `beql` branch at 0x779c targets 0x778c, is taken when a3(=[ret(pcibr_wrap_get)+24]-1) == 0, and falls through when a3(=[ret(pcibr_wrap_get)+24]-1) != 0; its branch-likely delay slot `nop` at 0x77a0 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x77a8 targets 0x77c8, is taken when v1(=[ret(pcibr_wrap_get)+24]) == 0, and falls through when v1(=[ret(pcibr_wrap_get)+24]) != 0.
  The `beq` branch at 0x77d0 targets 0x77b0 and is always taken.
  The return at 0x77c0 has v0 = ret(ipsema).

- `pcibr_intrd_start` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x77d8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x77d8-0x7854 (124 bytes).
  It occupies 124 bytes.
  The `lh` at 0x77ec loads 2 bytes from a0 (arg0 at entry) +0x50.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffc020, including `ld` at 0x77f0, `ld` at 0x780c.
  The `ld` at 0x7808 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ll` at 0x7828 loads 4 bytes from a0 (arg0 at entry) +0x28.
  The `sc` at 0x7830 stores 4 bytes to a0 (arg0 at entry) +0x28.
  The `jal` at 0x77e8 calls setmustrun with a0=[a0+80]:2, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x77f8 calls xthread_set_func with a0=[-0x3fe0]:8, a1=sym(pcibr_intrd), a2=a0 at entry (arg0), a3=?.
  The `jal` at 0x7804 calls fetch_kname with a0=[a0+24]:8, a1=sp-32, a2=?, a3=?.
  The `jal` at 0x7818 calls strncpy with a0=[-0x3fe0]:8+848, a1=ret(fetch_kname), a2=0x10, a3=?.
  The `jal` at 0x783c calls ipsema with a0=a0+48, a1=[a0+40], a2=a0+40, a3=0x400, a4=([a0+40] | 0x400).
  The `beql` branch at 0x7834 targets 0x7828, is taken when a4(=([a0+40] | 0x400)) == 0, and falls through when a4(=([a0+40] | 0x400)) != 0; its branch-likely delay slot `nop` at 0x7838 runs only when taken and is annulled on fall-through.
  The return at 0x784c has v0 = ret(ipsema).

- `pcibr_thread_setup` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x7854 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x7854-0x78cc (120 bytes).
  It occupies 120 bytes.
  The `sh` at 0x7890 stores 2 bytes to a0 (arg0 at entry) +0x48.
  The `ll` at 0x7898 loads 4 bytes from a0 (arg0 at entry) +0x28.
  The `sc` at 0x78a0 stores 4 bytes to a0 (arg0 at entry) +0x28.
  The `jal` at 0x7878 calls sprintf with a0=sp-64, a1=sym(.rodata)+4728, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The `jal` at 0x78b4 calls xthread_setup with a0=sp-64, a1=a2 at entry (arg2), a2=a0+40, a3=sym(pcibr_intrd_start), a4=a0 at entry (arg0), a5=0x300, a6=([a0+40] | 0x300), a7=a2 at entry (arg2).
  The `beql` branch at 0x78a4 targets 0x7898, is taken when a6(=([a0+40] | 0x300)) == 0, and falls through when a6(=([a0+40] | 0x300)) != 0; its branch-likely delay slot `nop` at 0x78a8 runs only when taken and is annulled on fall-through.
  The return at 0x78c4 has v0 = ret(xthread_setup).

- `pcibr_intr_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x78cc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x78cc-0x7edc (1552 bytes).
  It occupies 1552 bytes.
  The `lbu` at 0x7910 loads 1 byte from ret(pcibr_info_get) +0x21c.
  The `ld` at 0x7914 loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `lw` at 0x7920 loads 4 bytes from [ret(pcibr_info_get)+40]:8 +0x0.
  2 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x70, including `sw` at 0x79cc, `sw` at 0x79e0.
  The `sw` at 0x79e4 stores 4 bytes to ret(kmem_zalloc) +0x6c.
  The `sd` at 0x79e8 stores 8 bytes to ret(kmem_zalloc) +0x20.
  The `sd` at 0x79ec stores 8 bytes to ret(kmem_zalloc) +0x18.
  2 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x58, including `sw` at 0x79f0, `sw` at 0x7ab0.
  The `sd` at 0x79f4 stores 8 bytes to ret(kmem_zalloc) +0x60.
  3 such `sh` accesses store 2 bytes to ret(kmem_zalloc) +0x50, including `sh` at 0x79fc, `sh` at 0x7a90, `sh` at 0x7be0.
  The `sw` at 0x7a04 stores 4 bytes to ret(kmem_zalloc) +0x10.
  The `sw` at 0x7a10 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `sw` at 0x7a20 stores 4 bytes to ret(kmem_zalloc) +0x0.
  The `ld` at 0x7a24 loads 8 bytes from [ret(pcibr_info_get)+40]:8 +0x508.
  The `lbu` at 0x7a28 loads 1 byte from [ret(pcibr_info_get)+40]:8 +0x39.
  2 such `lw` accesses load 4 bytes from ret(kmem_zalloc) +0x58, including `lw` at 0x7a9c, `lw` at 0x7eb0.
  The `sd` at 0x7ab4 stores 8 bytes to ret(kmem_zalloc) +0x0.
  The `sd` at 0x7abc stores 8 bytes to ret(kmem_zalloc) +0x8.
  The `sd` at 0x7ac8 stores 8 bytes to ret(kmem_zalloc) +0x10.
  The `sb` at 0x7ae0 stores 1 byte to ret(kmem_zalloc) +0x18.
  5 such `ld` accesses load 8 bytes from ?, including `ld` at 0x7b50, `ld` at 0x7b90, `ld` at 0x7c18.
  The `sw` at 0x7c54 stores 4 bytes to ?.
  The `ld` at 0x7ce8 loads 8 bytes from a1 (arg1 at entry) +0x10.
  The `lh` at 0x7d08 loads 2 bytes from ret(kmem_zalloc) +0x50.
  2 such `ld` accesses load 8 bytes from [ret(pcibr_info_get)+40]:8 +0x10, including `ld` at 0x7e50, `ld` at 0x7eb4.
  The `jal` at 0x78ec calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x797c calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4728, a3=sym(.rodata)+4728, a4=sym(.rodata)+4728, a5=sym(.rodata)+4728, a6=sym(.rodata)+4728, a7=sym(.rodata)+4728.
  The `jal` at 0x7988 calls kmem_zalloc with a0=0xa0, a1=0x0, a2=?, a3=?.
  The `jal` at 0x79a8 calls device_desc_flags_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?, a5=[sym(default_intr_pri)].
  The `jal` at 0x7a1c calls spinlock_init with a0=ret(kmem_zalloc)+104, a1=sym(.rodata)+4728, a2=?, a3=?.
  The `jalr` at 0x7a34 calls (unknown callee) with a0=?, a1=a2 at entry (arg2), a2=[[ret(pcibr_info_get)+40]:8+57]:1+1, a3=[[ret(pcibr_info_get)+40]:8+1288]:8.
  The `jal` at 0x7a4c calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4728, a3=ret(?).
  The `jal` at 0x7aac calls kmem_zalloc with a0=0x20, a1=0x0, a2=?, a3=?.
  The `jal` at 0x7adc calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4728, a3=?.
  The `jal` at 0x7aec calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7b08 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4728, a3=ret(?).
  The `jal` at 0x7b68 calls xtalk_intr_cpuid_get with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7ba0 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7bb4 calls kmem_free with a0=ret(kmem_zalloc), a1=0x20, a2=?, a3=?.
  The `jal` at 0x7bcc calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4728, a3=ret(?).
  The `jal` at 0x7bec calls xtalk_intr_alloc_nothd with a0=?, a1=a1 at entry (arg1), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0x7c08 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4728, a3=ret(xtalk_intr_alloc_nothd).
  The `jal` at 0x7c30 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7c58 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4728, a3=ret(?).
  The `jal` at 0x7c6c calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(xtalk_intr_alloc_nothd), a3=?.
  The `jal` at 0x7c84 calls pcireg_intr_device_bit_clr with a0=[ret(pcibr_info_get)+40]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7c98 calls pcireg_intr_device_bit_set with a0=[ret(pcibr_info_get)+40]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7cac calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4728, a3=?.
  The `jal` at 0x7cd0 calls pcibr_thread_setup [0x7854] with a0=ret(kmem_zalloc), a1=ret(?), a2=?, a3=?, a4=a1 at entry (arg1).
  The `jal` at 0x7cf0 calls xtalk_intr_cpuid_get with a0=?, a1=?, a2=?, a3=?, a4=a1 at entry (arg1).
  The `jal` at 0x7d20 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4728, a3=ret(kmem_zalloc), a4=a1 at entry (arg1), a6=ret(xtalk_intr_cpuid_get).
  The `jal` at 0x7d64 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7d78 calls kmem_free with a0=ret(kmem_zalloc), a1=0x20, a2=?, a3=?.
  The `jal` at 0x7d90 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4728, a3=ret(?).
  The `jal` at 0x7da4 calls compare_and_swap_ptr with a0=?, a1=0x0, a2=ret(kmem_zalloc), a3=?.
  The `jal` at 0x7dc8 calls xtalk_intr_free with a0=ret(xtalk_intr_alloc_nothd), a1=?, a2=?, a3=?.
  The `jal` at 0x7e14 calls pcibr_debug with a0=0x1000, a1=a0 at entry (arg0), a2=sym(.rodata)+4728, a3=ret(?).
  The `jal` at 0x7e28 calls intr_target_from_desc with a0=a1 at entry (arg1), a1=-0x1, a2=?, a3=?.
  The `jal` at 0x7e3c calls device_desc_intr_swlevel_get with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x7e54 calls cmn_err with a0=0x4, a1=sym(.rodata)+4728, a2=[[ret(pcibr_info_get)+40]:8+16]:8, a3=?, a5=-0x1.
  The `jal` at 0x7e6c calls cmn_err with a0=0x4, a1=sym(.rodata)+4728, a2=?, a3=?.
  The `jal` at 0x7e84 calls vertex_to_name with a0=a3 at entry (arg3), a1=sp-440, a2=0x100, a3=?, a5=-0x1.
  The `jal` at 0x7ea4 calls cmn_err with a0=0x4, a1=sym(.rodata)+4728, a2=?, a3=?, a5=sp-440, a6=a3 at entry (arg3).
  The `jal` at 0x7eb8 calls cmn_err with a0=0x1, a1=sym(.rodata)+4728, a2=[[ret(pcibr_info_get)+40]:8+16]:8, a3=?.
  The `beq` branch at 0x7924 targets 0x7ddc, is taken when (s0(=a2) & 0xf) == 0, and falls through when (s0(=a2) & 0xf) != 0.
  The `beq` branch at 0x7938 targets 0x7de8, is taken when (s0(=a2) & 0x1) == 0, and falls through when (s0(=a2) & 0x1) != 0.
  The `beq` branch at 0x7948 targets 0x7df0, is taken when (s0(=a2) & 0x2) == 0, and falls through when (s0(=a2) & 0x2) != 0.
  The `beq` branch at 0x7958 targets 0x7df8, is taken when (s0(=a2) & 0x4) == 0, and falls through when (s0(=a2) & 0x4) != 0.
  The `beq` branch at 0x7968 targets 0x7e00, is taken when (s0(=a2) & 0x8) == 0, and falls through when (s0(=a2) & 0x8) != 0.
  The `beq` branch at 0x7994 targets 0x7dc0, is taken when v0(=ret(kmem_zalloc)) == 0, and falls through when v0(=ret(kmem_zalloc)) != 0.
  The `beq` branch at 0x79a0 targets 0x79d0, is taken when t0(=a1) == 0, and falls through when t0(=a1) != 0.
  The `beq` branch at 0x79c0 targets 0x7e24, is taken when (v0(=ret(device_desc_flags_get)) & 0x4) == 0, and falls through when (v0(=ret(device_desc_flags_get)) & 0x4) != 0.
  The `beq` branch at 0x79c8 targets 0x79e4 and is always taken.
  The `beq` branch at 0x7a64 targets 0x7ec8 and is always taken.
  The `bne` branch at 0x7a74 targets 0x7e4c, is taken when a6(?) != a1(?), and falls through when a6(?) == a1(?).
  The `beq` branch at 0x7a80 targets 0x7bdc, is taken when a7(?) == a5(=-0x1), and falls through when a7(?) != a5(=-0x1).
  The `bne` branch at 0x7a94 targets 0x7e7c, is taken when t1(?) != t0(?), and falls through when t1(?) == t0(?).
  The `beq` branch at 0x7af4 targets 0x7b90, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x7b2c targets 0x7cbc, is taken when s0(?) >= 0x8 (unsigned), and falls through when s0(?) < 0x8 (unsigned).
  The `beq` branch at 0x7b40 targets 0x7b10, is taken when (s5(?) & s3(=ret(?))) == 0, and falls through when (s5(?) & s3(=ret(?))) != 0.
  The `beq` branch at 0x7b54 targets 0x7be4, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0x7b60 targets 0x7a9c, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bne` branch at 0x7b78 targets 0x7a6c, is taken when a1(?) != a5(=-0x1), and falls through when a1(?) == a5(=-0x1).
  The `beq` branch at 0x7b88 targets 0x7a7c and is always taken.
  The `beq` branch at 0x7ba8 targets 0x7c2c, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x7bd4 targets 0x7b14 and is always taken.
  The `beq` branch at 0x7bdc targets 0x7a9c and is always taken.
  The `bne` branch at 0x7c10 targets 0x7c68, is taken when s7(=ret(xtalk_intr_alloc_nothd)) != 0, and falls through when s7(=ret(xtalk_intr_alloc_nothd)) == 0.
  The `bne` branch at 0x7c1c targets 0x7b60, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0x7c24 targets 0x7eb4 and is always taken.
  The `beq` branch at 0x7c38 targets 0x7d5c, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x7c60 targets 0x7b14 and is always taken.
  The `beq` branch at 0x7c74 targets 0x7dc8, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x7cb4 targets 0x7b60 and is always taken.
  The `beq` branch at 0x7cc0 targets 0x7cdc, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0x7cdc targets 0x7cec, is taken when a4(=a1) == 0, and falls through when a4(=a1) != 0.
  The `beq` branch at 0x7ce4 targets 0x7cf0 and is always taken.
  The `beq` branch at 0x7d00 targets 0x7d0c, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0x7d6c targets 0x7da0, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `beq` branch at 0x7d98 targets 0x7b14 and is always taken.
  The `bne` branch at 0x7dac targets 0x7e08, is taken when v0(=ret(compare_and_swap_ptr)) != 0, and falls through when v0(=ret(compare_and_swap_ptr)) == 0.
  The `beq` branch at 0x7db8 targets 0x7d5c and is always taken.
  The `beq` branch at 0x7dc0 targets 0x7d28 and is always taken.
  The `beq` branch at 0x7dd4 targets 0x7b5c and is always taken.
  The `beq` branch at 0x7de0 targets 0x7934 and is always taken.
  The `beq` branch at 0x7de8 targets 0x7944 and is always taken.
  The `beq` branch at 0x7df0 targets 0x7954 and is always taken.
  The `beq` branch at 0x7df8 targets 0x7964 and is always taken.
  The `beq` branch at 0x7e00 targets 0x7974 and is always taken.
  The `beq` branch at 0x7e1c targets 0x7b14 and is always taken.
  The `beq` branch at 0x7e44 targets 0x79e0 and is always taken.
  The `beq` branch at 0x7e74 targets 0x7a7c and is always taken.
  The `beq` branch at 0x7eac targets 0x7aa0 and is always taken.
  The `beq` branch at 0x7ec0 targets 0x7d28 and is always taken.
  The `beq` branch at 0x7ed4 targets 0x7b38 and is always taken.
  The return at 0x7d54 has v0 = one of ret(kmem_zalloc), 0x0.

- `pcibr_intr_setmustrun` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x7edc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x7edc-0x7f20 (68 bytes).
  It occupies 68 bytes.
  The `sh` at 0x7f00 stores 2 bytes to a0 (arg0 at entry) +0x50.
  The `jal` at 0x7eec calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x7efc calls setmustrun with a0=a1 at entry (arg1), a1=?, a2=?, a3=?.
  The `jal` at 0x7f0c calls splx with a0=(ret(splhi) << 0x0), a1=?, a2=?, a3=?.
  The return at 0x7f18 has v0 = ret(splx).

- `pcibr_intr_free` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x7f20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x7f20-0x8118 (504 bytes).
  It occupies 504 bytes.
  The `lw` at 0x7f28 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x7f30 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `sd` at 0x7f78 stores 8 bytes to ?.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0x7fbc, `ld` at 0x7ff0, `ld` at 0x8008.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x7fe4, `lw` at 0x805c.
  The `lw` at 0x7ffc loads 4 bytes from ?.
  The `lw` at 0x801c loads 4 bytes from a0 (arg0 at entry) +0x0.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x28, including `lw` at 0x802c, `lw` at 0x80cc.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x40, including `ld` at 0x8040, `ld` at 0x8068.
  The `jal` at 0x7f6c calls xtalk_intr_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x7f80 calls pcireg_intr_device_bit_clr with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x7fd0 calls compare_and_swap_ptr with a0=?, a1=a0 at entry (arg0), a2=0x0, a3=?.
  The `jal` at 0x7fe8 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4728, a3=?.
  The `jal` at 0x804c calls xthread_set_func with a0=[a0+64]:8, a1=sym(xthread_exit), a2=0x0, a3=[a0+64]:8.
  The `jal` at 0x8054 calls vsema with a0=a0+48, a1=?, a2=?, a3=?.
  The `jal` at 0x806c calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4728, a3=[a0+64]:8.
  The `jal` at 0x8078 calls kmem_free with a0=a0 at entry (arg0), a1=0xa0, a2=?, a3=?.
  The `jal` at 0x80c4 calls nano_delay with a0=sp-96, a1=?, a2=?, a3=?.
  The `jal` at 0x80f8 calls cmn_err with a0=0x4, a1=sym(.rodata)+4728, a2=[a0+64]:8, a3=[a0+64]:8.
  The `beq` branch at 0x7f64 targets 0x8108 and is always taken.
  The `beq` branch at 0x7f98 targets 0x801c, is taken when s2(?) >= 0x8 (unsigned), and falls through when s2(?) < 0x8 (unsigned).
  The `beq` branch at 0x7fa8 targets 0x7f88, is taken when (s6(=[a0+88]) & a3(?)) == 0, and falls through when (s6(=[a0+88]) & a3(?)) != 0.
  The `beq` branch at 0x7fc0 targets 0x7ffc, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x7fd8 targets 0x7ff0, is taken when v0(=ret(compare_and_swap_ptr)) == 0, and falls through when v0(=ret(compare_and_swap_ptr)) != 0.
  The `bne` branch at 0x7ff4 targets 0x7fcc, is taken when s0(?) != 0, and falls through when s0(?) == 0.
  The `bne` branch at 0x8000 targets 0x7f88, is taken when t8(?) != 0, and falls through when t8(?) == 0.
  The `bne` branch at 0x800c targets 0x7f6c, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x8014 targets 0x7f8c and is always taken.
  The `bne` branch at 0x8024 targets 0x8078, is taken when (t9(=[a0]) & 0x2) != 0, and falls through when (t9(=[a0]) & 0x2) == 0.
  The `beq` branch at 0x8034 targets 0x80b0, is taken when (a1(=[a0+40]) & 0x400) == 0, and falls through when (a1(=[a0+40]) & 0x400) != 0.
  The `beq` branch at 0x803c targets 0x80f0, is taken when a1(?) == 0, and falls through when a1(?) != 0.
  The `bne` branch at 0x80d4 targets 0x803c, is taken when (a1(=[a0+40]) & 0x400) != 0, and falls through when (a1(=[a0+40]) & 0x400) == 0.
  The `bne` branch at 0x80e0 targets 0x80bc, is taken when s0(?) < 0x3e8 (signed), and falls through when s0(?) >= 0x3e8 (signed).
  The `beq` branch at 0x80e8 targets 0x803c and is always taken.
  The `beq` branch at 0x8100 targets 0x8078 and is always taken.
  The `beq` branch at 0x8110 targets 0x7fa4 and is always taken.
  The return at 0x80a8 has v0 = ret(kmem_free).

- `pcibr_setpciint` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x8118 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x8118-0x81c0 (168 bytes).
  It occupies 168 bytes.
  2 such `lw` accesses load 4 bytes from ret(xtalk_intr_sfarg_get) +0x0, including `lw` at 0x815c, `lw` at 0x816c.
  The `jal` at 0x8124 calls xtalk_intr_addr_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8134 calls xtalk_intr_vector_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8144 calls xtalk_intr_dev_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8154 calls xtalk_intr_sfarg_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8164 calls xtalk_intr_sfarg_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x817c calls pcibr_bridge_ptr_get with a0=ret(xtalk_intr_dev_get), a1=?, a2=?, a3=?.
  The `jal` at 0x8194 calls pcireg_intr_addr_vect_set with a0=ret(pcibr_bridge_ptr_get), a1=?, a2=?, a3=?.
  The `jal` at 0x81a8 calls pcireg_intr_addr_addr_set with a0=ret(pcibr_bridge_ptr_get), a1=?, a2=ret(xtalk_intr_addr_get), a3=?.
  The return at 0x81b8 has v0 = ret(pcireg_intr_addr_addr_set).

- `pcibr_intr_connect` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x81c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x81c0-0x8364 (420 bytes).
  It occupies 420 bytes.
  The `lw` at 0x81c8 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x81d0 loads 8 bytes from a0 (arg0 at entry) +0x60.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x8200, `lw` at 0x8340.
  The `sd` at 0x8224 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `lw` at 0x8228 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sd` at 0x8230 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sw` at 0x823c stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `lw` at 0x8264 loads 4 bytes from ?.
  The `ld` at 0x826c loads 8 bytes from ?.
  The `lw` at 0x82e8 loads 4 bytes from [a0+96]:8 +0x48.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x830c, `sw` at 0x8320.
  The `jal` at 0x821c calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4728, a3=a1 at entry (arg1), a4=a2 at entry (arg2).
  The `jal` at 0x8280 calls mutex_spinlock with a0=[a0+96]:8+140, a1=?, a2=?, a3=?.
  The `jal` at 0x829c calls pcireg_intr_enable_bit_set with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x82a4 calls pcireg_tflush_get with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x82b0 calls mutex_io_spinunlock with a0=[a0+96]:8+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x82e0 calls pcireg_intr_addr_addr with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x8310 calls xtalk_intr_connect with a0=?, a1=sym(pcibr_intr_func), a2=?, a3=sym(pcibr_setpciint), a5=0x0.
  The `jal` at 0x8324 calls pcireg_intr_addr_get with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x8344 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4728, a3=ret(pcireg_intr_addr_addr), a4=ret(pcireg_intr_addr_get).
  The `bne` branch at 0x81f0 targets 0x8200, is taken when a0 != 0, and falls through when a0 == 0.
  The `beq` branch at 0x81f8 targets 0x82c4 and is always taken.
  The `beq` branch at 0x8250 targets 0x8270, is taken when (s2(=[a0+88]) & a5(?)) == 0, and falls through when (s2(=[a0+88]) & a5(?)) != 0.
  The `beq` branch at 0x8268 targets 0x82dc, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0x8278 targets 0x8240, is taken when s0(?) < 0x8 (unsigned), and falls through when s0(?) >= 0x8 (unsigned).
  The `bne` branch at 0x8354 targets 0x8244, is taken when s0(?) < 0x8 (unsigned), and falls through when s0(?) >= 0x8 (unsigned).
  The `beq` branch at 0x835c targets 0x8280 and is always taken.
  The return at 0x82d4 has v0 = one of -0x1, 0x0.

- `pcibr_intr_disconnect` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x8364 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x8364-0x8540 (476 bytes).
  It occupies 476 bytes.
  The `sd` at 0x8364 stores 8 bytes to a0 (arg0 at entry) +0x18.
  The `sd` at 0x8368 stores 8 bytes to a0 (arg0 at entry) +0x20.
  The `ld` at 0x8374 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `lw` at 0x837c loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `lw` at 0x8388 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `sw` at 0x83a0 stores 4 bytes to a0 (arg0 at entry) +0x0.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0x83d0, `lw` at 0x8474, `lw` at 0x84d8.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0x8440, `lw` at 0x84cc, `lw` at 0x851c.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x84b8, `ld` at 0x84f0.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0x84c8, `sw` at 0x8504.
  The `lw` at 0x84e4 loads 4 bytes from [a0+96]:8 +0x48.
  The `jal` at 0x8404 calls mutex_spinlock with a0=[a0+96]:8+140, a1=?, a2=?, a3=?.
  The `jal` at 0x8418 calls pcireg_intr_enable_bit_clr with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x8420 calls pcireg_tflush_get with a0=[a0+96]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x842c calls mutex_io_spinunlock with a0=[a0+96]:8+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x8444 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4728, a3=?.
  The `jal` at 0x84b4 calls xtalk_intr_disconnect with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x84d0 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4728, a3=?.
  The `jal` at 0x8508 calls xtalk_intr_connect with a0=?, a1=sym(pcibr_intr_func), a2=?, a3=sym(pcibr_setpciint), a5=0x0.
  The `jal` at 0x8520 calls pcibr_debug with a0=0x1000, a1=[a0+4], a2=sym(.rodata)+4728, a3=?.
  The `beq` branch at 0x83bc targets 0x83e0, is taken when (a6(?) & s0(?)) == 0, and falls through when (a6(?) & s0(?)) != 0.
  The `beq` branch at 0x83d4 targets 0x83e4, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `bne` branch at 0x83e8 targets 0x83ac, is taken when v0(?) < 0x8 (unsigned), and falls through when v0(?) >= 0x8 (unsigned).
  The `beq` branch at 0x83f8 targets 0x8490, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x8460 targets 0x8480, is taken when (s0(?) & a2(?)) == 0, and falls through when (s0(?) & a2(?)) != 0.
  The `beq` branch at 0x8478 targets 0x84b4, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x8488 targets 0x8454, is taken when s1(?) < 0x8 (unsigned), and falls through when s1(?) >= 0x8 (unsigned).
  The `beq` branch at 0x84dc targets 0x8528, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0x8530 targets 0x8454, is taken when s1(?) < 0x8 (unsigned), and falls through when s1(?) >= 0x8 (unsigned).
  The `beq` branch at 0x8538 targets 0x8494 and is always taken.
  The return at 0x84ac has v0 = one of ?, ret(pcibr_debug).

- `pcibr_intr_cpu_get` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x8540 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x8540-0x85b8 (120 bytes).
  It occupies 120 bytes.
  The `lw` at 0x8544 loads 4 bytes from a0 (arg0 at entry) +0x58.
  The `ld` at 0x8598 loads 8 bytes from a0 (arg0 at entry) +0x60.
  The `ld` at 0x85ac loads 8 bytes from ?.
  The `jal` at 0x85a8 calls xtalk_intr_cpu_get with a0=?, a1=?, a2=?, a3=[a0+88], a4=0x1, a5=a0 at entry (arg0).
  The `bne` branch at 0x8560 targets 0x8590, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `bne` branch at 0x8574 targets 0x8560, is taken when v0(?) < 0x8 (unsigned), and falls through when v0(?) >= 0x8 (unsigned).
  The `beq` branch at 0x85b0 targets 0x8580 and is always taken.
  The return at 0x8588 has v0 = one of 0x0, ret(xtalk_intr_cpu_get).

- `pcibr_setwidint` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x85b8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x85b8-0x863c (132 bytes).
  It occupies 132 bytes.
  The `jal` at 0x85c8 calls xtalk_intr_target_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x85d8 calls xtalk_intr_addr_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x85e4 calls xtalk_intr_vector_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x85f0 calls xtalk_intr_sfarg_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x8600 calls pcireg_intr_dst_target_id_set with a0=ret(xtalk_intr_sfarg_get), a1=?, a2=?, a3=?.
  The `jal` at 0x8610 calls pcireg_intr_dst_addr_set with a0=ret(xtalk_intr_sfarg_get), a1=ret(xtalk_intr_addr_get), a2=?, a3=?.
  The `jal` at 0x8624 calls pcireg_intr_host_err_set with a0=ret(xtalk_intr_sfarg_get), a1=?, a2=?, a3=?.
  The return at 0x8634 has v0 = ret(pcireg_intr_host_err_set).

- `pcibr_intr_func` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x863c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x863c-0x888c (592 bytes).
  It occupies 592 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x8, including `lw` at 0x863c, `lw` at 0x87bc.
  The `ld` at 0x8654 loads 8 bytes from a0 (arg0 at entry) +0x0.
  The `lh` at 0x865c loads 2 bytes from [a0]:8 +0x72.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x18, including `lw` at 0x867c, `lw` at 0x87a4, `lw` at 0x8878.
  The `ld` at 0x86b8 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0x86c8 loads 8 bytes from [a0+16]:8 +0x8.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x1c, including `lw` at 0x86e4, `lw` at 0x8750.
  2 such `lbu` accesses load 1 byte from ?, including `lbu` at 0x86f0, `lbu` at 0x875c.
  6 such `ld` accesses load 8 bytes from ?, including `ld` at 0x86f8, `ld` at 0x86fc, `ld` at 0x8704.
  The `lw` at 0x8724 loads 4 bytes from ?.
  The `ll` at 0x8774 loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `sc` at 0x8780 stores 4 bytes to a0 (arg0 at entry) +0x18.
  The `lw` at 0x8820 loads 4 bytes from [a0]:8 +0x78.
  The `jal` at 0x86f4 calls pcireg_wrb_flush_get with a0=?, a1=?, a2=?, a3=?.
  The `jalr` at 0x8700 calls (unknown callee) with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x8760 calls pcireg_wrb_flush_get with a0=?, a1=?, a2=a0+24, a3=?.
  The `jal` at 0x878c calls pcibr_wrap_put with a0=a0 at entry (arg0), a1=?, a2=a0+24, a3=0x1, a4=[a0+24]+1.
  The `jal` at 0x8794 calls vsema with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x87c4 calls mutex_spinlock with a0=[a0]:8+140, a1=?, a2=?, a3=?.
  The `jal` at 0x87d4 calls pcireg_intr_enable_bit_clr with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x87dc calls pcireg_tflush_get with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x87e8 calls mutex_io_spinunlock with a0=[a0]:8+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x8840 calls mutex_spinlock with a0=[a0]:8+140, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8854 calls pcireg_intr_enable_bit_clr with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x8860 calls pcireg_intr_enable_bit_set with a0=[a0]:8, a1=?, a2=?, a3=?.
  The `jal` at 0x886c calls mutex_io_spinunlock with a0=[a0]:8+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x887c calls pcibr_force_interrupt with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a5=[a0+24].
  The `beq` branch at 0x8674 targets 0x8820, is taken when at(=[[a0]:8+114]:2) == v1(=0x2), and falls through when at(=[[a0]:8+114]:2) != v1(=0x2).
  The `bne` branch at 0x8694 targets 0x87f0, is taken when a0(=[a0+24]) != 0, and falls through when a0(=[a0+24]) == 0.
  The `beq` branch at 0x86a0 targets 0x86b8 and is always taken.
  The `beq` branch at 0x86a8 targets 0x87a4, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x86b0 targets 0x87b0, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x86bc targets 0x86a8, is taken when s0(=[a0+16]:8) == 0, and falls through when s0(=[a0+16]:8) != 0.
  The `beq` branch at 0x86c4 targets 0x871c and is always taken.
  The `bne` branch at 0x86cc targets 0x8748, is taken when s3(=one of 0x0, 0x1) != 0, and falls through when s3(=one of 0x0, 0x1) == 0.
  The `beq` branch at 0x86d4 targets 0x870c, is taken when s4(=one of 0x0, 0x1) == 0, and falls through when s4(=one of 0x0, 0x1) != 0.
  The `bne` branch at 0x86dc targets 0x870c, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x86e8 targets 0x86fc, is taken when a1(=[a0+28]) == 0, and falls through when a1(=[a0+28]) != 0.
  The `beq` branch at 0x8710 targets 0x86a8, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0x871c targets 0x870c, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x8730 targets 0x870c, is taken when (v0(?) & 0x1) == 0, and falls through when (v0(?) & 0x1) != 0.
  The `bne` branch at 0x8738 targets 0x86cc, is taken when v0(?) != 0, and falls through when v0(?) == 0.
  The `beq` branch at 0x8740 targets 0x86d4, is taken when s3(=one of 0x0, 0x1) == 0, and falls through when s3(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x8748 targets 0x86d4, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0x8754 targets 0x876c, is taken when v1(=[a0+28]) == 0, and falls through when v1(=[a0+28]) != 0.
  The `beql` branch at 0x8784 targets 0x8774, is taken when a4(=[a0+24]+1) == 0, and falls through when a4(=[a0+24]+1) != 0; its branch-likely delay slot `nop` at 0x8788 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x879c targets 0x870c and is always taken.
  The `beq` branch at 0x87a8 targets 0x887c, is taken when a5(=[a0+24]) == 0, and falls through when a5(=[a0+24]) != 0.
  The `beq` branch at 0x87b0 targets 0x87f4, is taken when s6(=one of 0x0, 0x1) == 0, and falls through when s6(=one of 0x0, 0x1) != 0.
  The `beq` branch at 0x8830 targets 0x867c, is taken when (t8(?) & 0x2) == 0, and falls through when (t8(?) & 0x2) != 0.
  The `beq` branch at 0x8874 targets 0x8680 and is always taken.
  The `beq` branch at 0x8884 targets 0x87b0 and is always taken.
  The return at 0x8818 has v0 = ?.

- `pcibr_show_dir_state` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x888c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x888c-0x88e8 (92 bytes).
  It occupies 92 bytes.
  The `ld` at 0x88d4 loads 8 bytes from table(sym(dir_state_str)) +0x0.
  The `jal` at 0x88a8 calls get_dir_ent with a0=a0 at entry (arg0), a1=sp-48, a2=sp-40, a3=sp-32.
  The `jal` at 0x88d0 calls printf with a0=sym(.rodata)+6264, a1=a1 at entry (arg1), a2=a0 at entry (arg0), a3=?, a5=entry(sym(dir_state_str)).
  The return at 0x88e0 has v0 = ret(printf).

- `print_bridge_errcmd` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x88e8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x88e8-0x891c (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x8908 calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=a1 at entry (arg1), a3=a0 at entry (arg0), a4=sym(.data)+16.
  The return at 0x8914 has v0 = ret(cmn_err).

- `pcibr_errintr_group` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x99c8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x99c8-0x9a4c (132 bytes).
  It occupies 132 bytes.
  The `beq` branch at 0x99e4 targets 0x99f4, is taken when (a0 & a1(=0x40010000)) == 0, and falls through when (a0 & a1(=0x40010000)) != 0.
  The `beq` branch at 0x9a0c targets 0x9a18, is taken when (a3(=a0) & v1(=0x3e0000)) == 0, and falls through when (a3(=a0) & v1(=0x3e0000)) != 0.
  The `beq` branch at 0x9a18 targets 0x9a24, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x9a2c targets 0x9a38, is taken when (a3(=a0) & a0(=0x14000200)) == 0, and falls through when (a3(=a0) & a0(=0x14000200)) != 0.
  The `beq` branch at 0x9a38 targets 0x9a44, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0x9a44 has v0 = ?.

- `pcibr_pioerr_check` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x9a4c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x9a4c-0x9bb4 (360 bytes).
  It occupies 360 bytes.
  The `lbu` at 0x9a78 loads 1 byte from a0 (arg0 at entry) +0x39.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0x9aac, `lw` at 0x9ad8.
  11 such `ld` accesses load 8 bytes from ?, including `ld` at 0x9ac0, `ld` at 0x9acc, `ld` at 0x9ae4.
  The `ll` at 0x9b38 loads 4 bytes from ?.
  The `sc` at 0x9b44 stores 4 bytes to ?.
  The `jal` at 0x9a58 calls pcireg_intr_status_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x9a70 calls pcireg_pci_bus_addr_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0x9a68 targets 0x9ba0, is taken when (v0(=ret(pcireg_intr_status_get)) & at(=0x4400008800)) == 0, and falls through when (v0(=ret(pcireg_intr_status_get)) & at(=0x4400008800)) != 0.
  The `blez` branch at 0x9a88 targets 0x9ba0, is taken when at(?) <= 0 (signed), and falls through when at(?) > 0 (signed).
  The `beq` branch at 0x9a90 targets 0x9a9c and is always taken.
  The `blez` branch at 0x9a98 targets 0x9ba0, is taken when s0(?) <= 0 (signed), and falls through when s0(?) > 0 (signed).
  The `blez` branch at 0x9abc targets 0x9a98, is taken when t8(?) <= 0 (signed), and falls through when t8(?) > 0 (signed).
  The `beq` branch at 0x9ac4 targets 0x9b64 and is always taken.
  The `beq` branch at 0x9ad0 targets 0x9b5c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x9ae8 targets 0x9b8c, is taken when a6(?) >= 0x6 (unsigned), and falls through when a6(?) < 0x6 (unsigned).
  The `bne` branch at 0x9b18 targets 0x9acc, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0x9b2c targets 0x9acc, is taken when v0(=ret(pcireg_pci_bus_addr_get)) >= a2(?) (unsigned), and falls through when v0(=ret(pcireg_pci_bus_addr_get)) < a2(?) (unsigned).
  The `beql` branch at 0x9b48 targets 0x9b38, is taken when at(?) == 0, and falls through when at(?) != 0; its branch-likely delay slot `nop` at 0x9b4c runs only when taken and is annulled on fall-through.
  The `bne` branch at 0x9b54 targets 0x9ad8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x9b5c targets 0x9a98, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x9b70 targets 0x9b5c, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `bne` branch at 0x9b7c targets 0x9ad8, is taken when a4(?) != 0, and falls through when a4(?) == 0.
  The `beq` branch at 0x9b84 targets 0x9b5c and is always taken.
  The `bne` branch at 0x9b8c targets 0x9b18, is taken when a5(?) != t3(=0x1), and falls through when a5(?) == t3(=0x1).
  The `beq` branch at 0x9b98 targets 0x9b14 and is always taken.
  The return at 0x9bac has v0 = one of ret(pcireg_intr_status_get), ret(pcireg_pci_bus_addr_get).

- `pcibr_error_intr_handler` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0x9bb4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0x9bb4-0xa168 (1460 bytes).
  It occupies 1460 bytes.
  8 such `ld` accesses load 8 bytes from ?, including `ld` at 0x9bf0, `ld` at 0x9bfc, `ld` at 0xa01c.
  The `ld` at 0x9c08 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lbu` at 0x9c18 loads 1 byte from a0 (arg0 at entry) +0x28.
  The `lw` at 0x9c38 loads 4 bytes from a0 (arg0 at entry) +0x838.
  The `sw` at 0x9c40 stores 4 bytes to a0 (arg0 at entry) +0x838.
  The `lw` at 0x9c88 loads 4 bytes from a0 (arg0 at entry) +0x0.
  9 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0x9d00, `lh` at 0x9d94, `lh` at 0x9eac.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0x9d38, `lw` at 0x9d3c, `lw` at 0x9d40.
  7 such `sw` accesses store 4 bytes to ?, including `sw` at 0x9d48, `sw` at 0x9de8, `sw` at 0x9df0.
  The `lw` at 0x9d4c loads 4 bytes from a0 (arg0 at entry) +0x48.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x78, including `lw` at 0x9dfc, `lw` at 0x9f08, `lw` at 0x9f88.
  3 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0xa04c, `ld` at 0xa0c0, `ld` at 0xa0f4.
  The `jal` at 0x9c1c calls hubii_check_widget_disabled with a0=?, a1=[a0+40]:1, a2=?, a3=?.
  The `jal` at 0x9c30 calls timeout with a0=sym(pcibr_error_intr_handler), a1=a0 at entry (arg0), a2=0x1, a3=?.
  The `jal` at 0x9c74 calls pcireg_intr_status_get with a0=a0 at entry (arg0), a1=?, a2=0x1, a3=?.
  The `jal` at 0x9c8c calls pcibr_debug with a0=0x100, a1=[a0], a2=sym(.rodata)+6264, a3=ret(pcireg_intr_status_get).
  The `jal` at 0x9cbc calls pcibr_pioerr_check [0x9a4c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x2.
  The `jal` at 0x9e30 calls mutex_spinlock with a0=a0+140, a1=0x1, a2=sym(.data)+16, a3=0x2.
  The `jal` at 0x9e40 calls pcireg_intr_enable_bit_clr with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9e4c calls mutex_io_spinunlock with a0=a0+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0x9e6c calls pcireg_bus_err_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x2.
  The `jal` at 0x9ee0 calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=(ret(pcireg_intr_status_get) | 0x40), a2=0x1, a3=?.
  The `jal` at 0x9f28 calls pcireg_arbitration_bit_set with a0=a0 at entry (arg0), a1=0xf00000, a2=[a0+114]:2, a3=0x2.
  The `jal` at 0x9f34 calls test_and_set_long with a0=a0+2120, a1=0x0, a2=?, a3=?.
  The `jal` at 0x9f58 calls pcibr_errintr_group with a0=(ret(pcireg_intr_status_get) << 0x0), a1=?, a2=0x1, a3=?.
  The `jal` at 0x9f68 calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0x9fc8 calls pcireg_cmdword_err_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=0x2.
  The `jal` at 0xa014 calls panic with a0=sym(.rodata)+6264, a1=a0 at entry (arg0), a2=?, a3=?.
  The `jal` at 0xa050 calls cmn_err with a0=0x5, a1=sym(.rodata)+6264, a2=[a0+16]:8, a3=?.
  The `jal` at 0xa080 calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=?, a3=0x2.
  The `jal` at 0xa088 calls pcibr_error_dump with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa098 calls machine_error_dump with a0=sym(.rodata)+6264, a1=?, a2=?, a3=?.
  The `jal` at 0xa0a0 calls panic with a0=sym(.rodata)+6264, a1=?, a2=?, a3=?.
  The `jal` at 0xa0c4 calls cmn_err with a0=0x5, a1=sym(.rodata)+6264, a2=[a0+16]:8, a3=?.
  The `jal` at 0xa100 calls cmn_err with a0=0x4, a1=sym(.rodata)+6264, a2=[a0+16]:8, a3=?.
  The `jal` at 0xa128 calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=?, a3=0x2.
  The `jal` at 0xa130 calls pcibr_error_dump with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa13c calls machine_error_dump with a0=sym(.rodata)+6264, a1=?, a2=?, a3=?.
  The `jal` at 0xa144 calls panic with a0=sym(.rodata)+6264, a1=?, a2=?, a3=?.
  The `beq` branch at 0x9be8 targets 0x9bf4 and is always taken.
  The `beq` branch at 0x9bf4 targets 0xa010, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x9c00 targets 0x9bf0, is taken when at(?) != s0(=a0), and falls through when at(?) == s0(=a0).
  The `beq` branch at 0x9c24 targets 0x9c74, is taken when v0(=ret(hubii_check_widget_disabled)) == 0, and falls through when v0(=ret(hubii_check_widget_disabled)) != 0.
  The `beq` branch at 0x9ca4 targets 0x9c44, is taken when (s2(=ret(pcireg_intr_status_get)) & a2(=-0x100)) == 0, and falls through when (s2(=ret(pcireg_intr_status_get)) & a2(=-0x100)) != 0.
  The `beq` branch at 0x9cb4 targets 0x9cc8, is taken when (v0(=0x4400008800) & s2(=ret(pcireg_intr_status_get))) == 0, and falls through when (v0(=0x4400008800) & s2(=ret(pcireg_intr_status_get))) != 0.
  The `beq` branch at 0x9cc8 targets 0xa008, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0x9cf8 targets 0xa154 and is always taken.
  The `beq` branch at 0x9d04 targets 0x9df4, is taken when t3(=[a0+114]:2) == a3(=0x2), and falls through when t3(=[a0+114]:2) != a3(=0x2).
  The `beq` branch at 0x9d20 targets 0x9e24, is taken when s2(?) >= 0x40 (signed), and falls through when s2(?) < 0x40 (signed).
  The `beq` branch at 0x9d30 targets 0x9d0c, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0x9d5c targets 0x9da4, is taken when t8(=[a0+72]) == 0, and falls through when t8(=[a0+72]) != 0.
  The `beq` branch at 0x9d64 targets 0x9d00, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `bne` branch at 0x9d88 targets 0x9d00, is taken when s1(?) < 0x65 (unsigned), and falls through when s1(?) >= 0x65 (unsigned).
  The `bnel` branch at 0x9d90 targets 0x9d04, is taken when a0(?) != 0, and falls through when a0(?) == 0; its branch-likely delay slot `lh t3,114(s0)` at 0x9d94 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x9d9c targets 0xa03c and is always taken.
  The `beq` branch at 0x9da4 targets 0x9f44, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x9db4 targets 0x9d80, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0x9dc0 targets 0x9d84, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x9dc8 targets 0x9d84, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `bne` branch at 0x9de0 targets 0xa0ec, is taken when t1(=[sym(.sbss)]) < a4(?) (unsigned), and falls through when t1(=[sym(.sbss)]) >= a4(?) (unsigned).
  The `beq` branch at 0x9dec targets 0x9d84 and is always taken.
  The `bne` branch at 0x9df4 targets 0x9d0c, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0x9e0c targets 0x9d0c, is taken when (t3(?) & 0x2) == 0, and falls through when (t3(?) & 0x2) != 0.
  The `bnel` branch at 0x9e14 targets 0x9d10, is taken when a0(?) != 0, and falls through when a0(?) == 0; its branch-likely delay slot `addiu s2,s2,1` at 0x9e18 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x9e1c targets 0xa0b0 and is always taken.
  The `beq` branch at 0x9e28 targets 0x9e58, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `bgez` branch at 0x9e64 targets 0x9e88, is taken when t9(=(ret(pcireg_intr_status_get) << 0x27)) >= 0 (signed), and falls through when t9(=(ret(pcireg_intr_status_get) << 0x27)) < 0 (signed).
  The `beq` branch at 0x9e80 targets 0x9fc8, is taken when ra(?) == at(=0xc00000), and falls through when ra(?) != at(=0xc00000).
  The `beq` branch at 0x9e8c targets 0x9f78, is taken when at(=[sym(pcibr_pioerr_dump)]) == 0, and falls through when at(=[sym(pcibr_pioerr_dump)]) != 0.
  The `bne` branch at 0x9ea4 targets 0xa07c, is taken when (s1(?) & a0(?)) != 0, and falls through when (s1(?) & a0(?)) == 0.
  The `beq` branch at 0x9eb0 targets 0x9f88, is taken when a0(=[a0+114]:2) == a3(=0x2), and falls through when a0(=[a0+114]:2) != a3(=0x2).
  The `bne` branch at 0x9ebc targets 0xa098, is taken when (s1(?) & a1(=0x22133fc06000)) != 0, and falls through when (s1(?) & a1(=0x22133fc06000)) == 0.
  The `beq` branch at 0x9ec8 targets 0x9f54, is taken when a0(=[a0+114]:2) == 0, and falls through when a0(=[a0+114]:2) != 0.
  The `beq` branch at 0x9ed0 targets 0x9f58, is taken when a0(=[a0+114]:2) == a2(=0x1), and falls through when a0(=[a0+114]:2) != a2(=0x1).
  The `bne` branch at 0x9ef0 targets 0x9f30, is taken when a2(=[a0+114]:2) != a3(=0x2), and falls through when a2(=[a0+114]:2) == a3(=0x2).
  The `beq` branch at 0x9f00 targets 0x9f34, is taken when (s1(?) & a4(=0x10000000000)) == 0, and falls through when (s1(?) & a4(=0x10000000000)) != 0.
  The `beq` branch at 0x9f1c targets 0x9f34, is taken when (a5(?) & 0x2) == 0, and falls through when (a5(?) & 0x2) != 0.
  The `beq` branch at 0x9f3c targets 0x9c48 and is always taken.
  The `bne` branch at 0x9f44 targets 0x9fb8, is taken when t1(?) != 0, and falls through when t1(?) == 0.
  The `beq` branch at 0x9f4c targets 0x9d04 and is always taken.
  The `beq` branch at 0x9f70 targets 0x9eec and is always taken.
  The `beq` branch at 0x9f80 targets 0x9ea0 and is always taken.
  The `beq` branch at 0x9fa0 targets 0x9eb4, is taken when (a1(?) & 0x6) == 0, and falls through when (a1(?) & 0x6) != 0.
  The `beq` branch at 0x9fa8 targets 0x9eb8, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0x9fb0 targets 0xa124 and is always taken.
  The `beq` branch at 0x9fb8 targets 0x9ffc, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0x9fc0 targets 0x9d04 and is always taken.
  The `bne` branch at 0x9fec targets 0x9e88, is taken when a1(?) != a2(=0x402000), and falls through when a1(?) == a2(=0x402000).
  The `beq` branch at 0x9ff4 targets 0x9e88 and is always taken.
  The `beq` branch at 0xa000 targets 0x9d00 and is always taken.
  The `beq` branch at 0xa008 targets 0x9e58 and is always taken.
  The `beq` branch at 0xa020 targets 0x9c08, is taken when a2(?) == s0(=a0), and falls through when a2(?) != s0(=a0).
  The `bnel` branch at 0xa02c targets 0x9c00, is taken when s1(?) != 0, and falls through when s1(?) == 0; its branch-likely delay slot `ld at,8(s1)` at 0xa030 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa034 targets 0xa014 and is always taken.
  The `beq` branch at 0xa074 targets 0x9d00 and is always taken.
  The `beq` branch at 0xa090 targets 0x9eac and is always taken.
  The `beq` branch at 0xa0a8 targets 0x9ec8 and is always taken.
  The `beq` branch at 0xa0e4 targets 0x9d0c and is always taken.
  The `beq` branch at 0xa11c targets 0x9de8 and is always taken.
  The `beq` branch at 0xa14c targets 0x9eb8 and is always taken.
  The `beq` branch at 0xa160 targets 0x9d2c and is always taken.
  The return at 0x9c6c has v0 = one of ?, ret(test_and_set_long).

- `pcibr_addr_toslot` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xa168 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xa168-0xa450 (744 bytes).
  It occupies 744 bytes.
  The `lbu` at 0xa1a4 loads 1 byte from a0 (arg0 at entry) +0x38.
  The `lbu` at 0xa1a8 loads 1 byte from a0 (arg0 at entry) +0x39.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa1cc, `lw` at 0xa224, `lw` at 0xa324.
  13 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa1dc, `ld` at 0xa1f4, `ld` at 0xa230.
  4 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0xa260, `sw` at 0xa2e0, `sw` at 0xa3ac.
  2 such `sb` accesses store 1 byte to a4 (arg4 at entry) +0x0, including `sb` at 0xa26c, `sb` at 0xa2ec.
  4 such `sd` accesses store 8 bytes to a3 (arg3 at entry) +0x0, including `sd` at 0xa284, `sd` at 0xa2c4, `sd` at 0xa3c8.
  The `bne` branch at 0xa170 targets 0xa1a4, is taken when a1 < v0(=0x20000) (unsigned), and falls through when a1 >= v0(=0x20000) (unsigned).
  The `beq` branch at 0xa180 targets 0xa1a4, is taken when a1 >= v1(=0x30000) (unsigned), and falls through when a1 < v1(=0x30000) (unsigned).
  The `bne` branch at 0xa190 targets 0xa290, is taken when a1 < a0(=0x28000) (unsigned), and falls through when a1 >= a0(=0x28000) (unsigned).
  The `beq` branch at 0xa19c targets 0xa298 and is always taken.
  The `bne` branch at 0xa1bc targets 0xa310, is taken when a6(=[a0+57]:1) < v0(=[a0+56]:1) (signed), and falls through when a6(=[a0+57]:1) >= v0(=[a0+56]:1) (signed).
  The `blez` branch at 0xa1d0 targets 0xa2f8, is taken when t9(?) <= 0 (signed), and falls through when t9(?) > 0 (signed).
  The `beq` branch at 0xa1d8 targets 0xa440 and is always taken.
  The `beq` branch at 0xa1ec targets 0xa2f8, is taken when t3(?) >= t9(?) (signed), and falls through when t3(?) < t9(?) (signed).
  The `beq` branch at 0xa1f8 targets 0xa1e0, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0xa200 targets 0xa434 and is always taken.
  The `beq` branch at 0xa214 targets 0xa1e0, is taken when a7(?) >= 0x6 (signed), and falls through when a7(?) < 0x6 (signed).
  The `beq` branch at 0xa228 targets 0xa208, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `bne` branch at 0xa238 targets 0xa208, is taken when a1 < t1(?) (unsigned), and falls through when a1 >= t1(?) (unsigned).
  The `beql` branch at 0xa24c targets 0xa20c, is taken when a1 >= v1(?) (unsigned), and falls through when a1 < v1(?) (unsigned); its branch-likely delay slot `addiu a7,a7,1` at 0xa250 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa254 targets 0xa278, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa25c targets 0xa27c, is taken when a3 != 0, and falls through when a3 == 0.
  The `beq` branch at 0xa264 targets 0xa270, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0xa278 targets 0xa264, is taken when a3 == 0, and falls through when a3 != 0.
  The `bne` branch at 0xa280 targets 0xa26c, is taken when a4 != 0, and falls through when a4 == 0.
  The `beq` branch at 0xa288 targets 0xa270 and is always taken.
  The `beq` branch at 0xa2a0 targets 0xa2d0, is taken when a4 == 0, and falls through when a4 != 0.
  The `bne` branch at 0xa2b0 targets 0xa2d8, is taken when a2 != 0, and falls through when a2 == 0.
  The `beq` branch at 0xa2b8 targets 0xa2e4, is taken when a3 == 0, and falls through when a3 != 0.
  The `bne` branch at 0xa2c0 targets 0xa2ec, is taken when a4 != 0, and falls through when a4 == 0.
  The `beq` branch at 0xa2c8 targets 0xa270 and is always taken.
  The `beq` branch at 0xa2d0 targets 0xa2b8, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa2dc targets 0xa2c0, is taken when a3 != 0, and falls through when a3 == 0.
  The `beq` branch at 0xa2e4 targets 0xa270, is taken when a4 == 0, and falls through when a4 != 0.
  The `beq` branch at 0xa2f0 targets 0xa270 and is always taken.
  The `beq` branch at 0xa308 targets 0xa1cc, is taken when t9(=[a0+57]:1) >= v0(?) (signed), and falls through when t9(=[a0+57]:1) < v0(?) (signed).
  The `beq` branch at 0xa314 targets 0xa3ec, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `blez` branch at 0xa328 targets 0xa3d4, is taken when t1(?) <= 0 (signed), and falls through when t1(?) > 0 (signed).
  The `beq` branch at 0xa330 targets 0xa340 and is always taken.
  The `beq` branch at 0xa338 targets 0xa3d8, is taken when t0(?) == 0, and falls through when t0(?) != 0.
  The `beq` branch at 0xa350 targets 0xa338, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xa35c targets 0xa338, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xa364 targets 0xa37c and is always taken.
  The `beq` branch at 0xa370 targets 0xa338, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0xa380 targets 0xa36c, is taken when a1 < a7(?) (unsigned), and falls through when a1 >= a7(?) (unsigned).
  The `beq` branch at 0xa394 targets 0xa36c, is taken when a1 >= t9(?) (unsigned), and falls through when a1 < t9(?) (unsigned).
  The `beq` branch at 0xa39c targets 0xa3b8, is taken when a2 == 0, and falls through when a2 != 0.
  The `bne` branch at 0xa3a8 targets 0xa3c0, is taken when a3 != 0, and falls through when a3 == 0.
  The `beq` branch at 0xa3b0 targets 0xa270 and is always taken.
  The `beq` branch at 0xa3b8 targets 0xa270, is taken when a3 == 0, and falls through when a3 != 0.
  The `beq` branch at 0xa3cc targets 0xa270 and is always taken.
  The `beq` branch at 0xa3e4 targets 0xa324, is taken when a4(=[a0+57]:1) >= v0(?) (signed), and falls through when a4(=[a0+57]:1) < v0(?) (signed).
  The `beq` branch at 0xa3ec targets 0xa420, is taken when a2 == 0, and falls through when a2 != 0.
  The `beq` branch at 0xa3f8 targets 0xa408, is taken when a1 >= a5(=0x40000000) (unsigned), and falls through when a1 < a5(=0x40000000) (unsigned).
  The `beq` branch at 0xa400 targets 0xa41c and is always taken.
  The `beq` branch at 0xa420 targets 0xa42c, is taken when a3 == 0, and falls through when a3 != 0.
  The `beq` branch at 0xa42c targets 0xa270 and is always taken.
  The `beq` branch at 0xa438 targets 0xa220 and is always taken.
  The `beq` branch at 0xa448 targets 0xa1f8 and is always taken.
  The return at 0xa270 has v0 = one of ?, 0xff.

- `pcibr_error_cleanup` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xa450 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xa450-0xa4a4 (84 bytes).
  It occupies 84 bytes.
  The `lh` at 0xa450 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `jal` at 0xa478 calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=one of 0x41, 0x3cff00000041, a2=a2 at entry (arg2), a3=0x1, a4=[a0+114]:2.
  The `jal` at 0xa480 calls pcireg_tflush_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa468 targets 0xa478, is taken when a4(=[a0+114]:2) == 0, and falls through when a4(=[a0+114]:2) != 0.
  The `beq` branch at 0xa470 targets 0xa498, is taken when a4(=[a0+114]:2) == a3(=0x1), and falls through when a4(=[a0+114]:2) != a3(=0x1).
  The `beq` branch at 0xa49c targets 0xa478 and is always taken.
  The return at 0xa490 has v0 = ret(pcireg_tflush_get).

- `pcibr_error_extract` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xa4a4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xa4a4-0xa51c (120 bytes).
  It occupies 120 bytes.
  The `jal` at 0xa4c0 calls hwgraph_info_get_LBL with a0=a0 at entry (arg0), a1=sym(.rodata)+6264, a2=sp-48, a3=a3 at entry (arg3).
  The `jal` at 0xa4dc calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xa4f0 calls pcireg_pci_bus_addr_get with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?, a5=0xff.
  The `jal` at 0xa508 calls pcibr_addr_toslot with a0=?, a1=ret(pcireg_pci_bus_addr_get), a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `beq` branch at 0xa4c8 targets 0xa4dc, is taken when v0(=ret(hwgraph_info_get_LBL)) == 0, and falls through when v0(=ret(hwgraph_info_get_LBL)) != 0.
  The `beq` branch at 0xa4e8 targets 0xa514, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xa514 targets 0xa4d0 and is always taken.
  The return at 0xa4d4 has v0 = one of 0xff, ?.

- `pcibr_device_disable` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xa51c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xa51c-0xa524 (8 bytes).
  It occupies 8 bytes.
  The return at 0xa51c has v0 = ?.

- `pcibr_pioerror` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xa524 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xa524-0xb274 (3408 bytes).
  It occupies 3408 bytes.
  2 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x0, including `lw` at 0xa53c, `lw` at 0xaa0c.
  The `lw` at 0xa544 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `ld` at 0xa560 loads 8 bytes from a3 (arg3 at entry) +0x18.
  4 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0xa594, `lh` at 0xaa30, `lh` at 0xaae8.
  The `lw` at 0xa59c loads 4 bytes from a0 (arg0 at entry) +0x48.
  8 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa6e4, `lw` at 0xa8c8, `lw` at 0xa970.
  21 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa6f0, `ld` at 0xa8d4, `ld` at 0xa908.
  12 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x39, including `lbu` at 0xa774, `lbu` at 0xa7f8, `lbu` at 0xa844.
  10 such `lbu` accesses load 1 byte from a0 (arg0 at entry) +0x38, including `lbu` at 0xa778, `lbu` at 0xa800, `lbu` at 0xa848.
  The `ll` at 0xa920 loads 4 bytes from ?.
  The `sc` at 0xa92c stores 4 bytes to ?.
  5 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0xaa2c, `lw` at 0xaacc, `lw` at 0xb02c.
  3 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0xaa54, `sw` at 0xaa80, `sw` at 0xac38.
  2 such `sh` accesses store 2 bytes to a3 (arg3 at entry) +0x8, including `sh` at 0xaa64, `sh` at 0xac48.
  The `sd` at 0xaa68 stores 8 bytes to a3 (arg3 at entry) +0x28.
  The `sd` at 0xaa70 stores 8 bytes to a3 (arg3 at entry) +0x20.
  5 such `lh` accesses load 2 bytes from a3 (arg3 at entry) +0x8, including `lh` at 0xaac8, `lh` at 0xb0b4, `lh` at 0xb160.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x10, including `ld` at 0xb000, `ld` at 0xb020.
  The `lw` at 0xb174 loads 4 bytes from a3 (arg3 at entry) +0x24.
  4 such `ld` accesses load 8 bytes from a3 (arg3 at entry) +0x28, including `ld` at 0xb1c8, `ld` at 0xb200, `ld` at 0xb228.
  The `lw` at 0xb270 loads 4 bytes from (a0 + ([a0+56]:1 << 0x7)) +0x118.
  The `jal` at 0xa578 calls pcibr_debug with a0=0x200, a1=[a0], a2=sym(.rodata)+6264, a3=a0 at entry (arg0), a4=[a3+24]:8.
  The `jal` at 0xaa10 calls pcibr_debug with a0=0x200, a1=[a0], a2=sym(.rodata)+6264, a3=?.
  The `jal` at 0xaaa0 calls pciio_error_handler with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xadec calls pcibr_error_cleanup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xae0c calls pciio_error_handler with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xae20 calls pcibr_device_disable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?, a4=([a3] << 0x2).
  The `jal` at 0xae30 calls pcibr_error_cleanup with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xb00c calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=[a0+16]:8, a3=[a3+24]:8.
  The `jal` at 0xb024 calls cmn_err with a0=0x1, a1=sym(.rodata)+6264, a2=[a0+16]:8, a3=?.
  The `jal` at 0xb04c calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=sym(.rodata)+6264, a3=?.
  The `jal` at 0xb054 calls pcireg_intr_status_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb06c calls pcibr_error_dump with a0=a0 at entry (arg0), a1=sym(.rodata)+6264, a2=?, a3=?.
  The `jal` at 0xb090 calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=sym(.rodata)+6264, a3=?.
  The `jal` at 0xb0a8 calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=sym(.rodata)+6264, a3=?.
  The `jal` at 0xb0fc calls pcireg_device_get with a0=a0 at entry (arg0), a1=?, a2=[a3+8]:2, a3=?, a4=([a3] << 0x2).
  The `jal` at 0xb118 calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=sym(.rodata)+6264, a3=?.
  The `jal` at 0xb134 calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=sym(.rodata)+6264, a3=?.
  The `jal` at 0xb154 calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=sym(.rodata)+6264, a3=ret(pcireg_device_get), a4=sym(.data)+16.
  The `jal` at 0xb1cc calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=?, a3=?, a4=[a3+36]-8, a5=[a3+40]:8, a6=0x4, a7=0x5.
  The `jal` at 0xb204 calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=[a3+40]:8, a3=?, a5=0x7, a6=0x4, a7=0x5.
  The `jal` at 0xb22c calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=?, a3=?, a4=[a3+40]:8, a5=0x7.
  The `jal` at 0xb248 calls cmn_err with a0=0x6, a1=sym(.rodata)+6264, a2=[a3+40]:8, a3=?, a5=0x7, a6=0x4.
  The `beq` branch at 0xa5ac targets 0xab80, is taken when t1(=[a0+114]:2) == a6(=0x2), and falls through when t1(=[a0+114]:2) != a6(=0x2).
  The `bne` branch at 0xa5dc targets 0xa62c, is taken when s2(=[a3+24]:8) < t3(=one of 0x20000, 0x21000, 0x820000, 0x821000) (unsigned), and falls through when s2(=[a3+24]:8) >= t3(=one of 0x20000, 0x21000, 0x820000, 0x821000) (unsigned).
  The `beq` branch at 0xa5e4 targets 0xa614, is taken when t2(?) == 0, and falls through when t2(?) != 0.
  The `beq` branch at 0xa5ec targets 0xae40, is taken when t1(=[a0+114]:2) == a6(=0x2), and falls through when t1(=[a0+114]:2) != a6(=0x2).
  The `beq` branch at 0xa60c targets 0xa61c and is always taken.
  The `bne` branch at 0xa61c targets 0xa640, is taken when ra(?) != 0, and falls through when ra(?) == 0.
  The `beq` branch at 0xa624 targets 0xa668 and is always taken.
  The `bne` branch at 0xa62c targets 0xac4c, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0xa654 targets 0xa668, is taken when s2(=[a3+24]:8) >= a2(=one of 0x29000, 0x829000) (unsigned), and falls through when s2(=[a3+24]:8) < a2(=one of 0x29000, 0x829000) (unsigned).
  The `bne` branch at 0xa674 targets 0xa6f8, is taken when s2(=[a3+24]:8) < t3(=one of 0x200000, 0xa00000) (unsigned), and falls through when s2(=[a3+24]:8) >= t3(=one of 0x200000, 0xa00000) (unsigned).
  The `beq` branch at 0xa688 targets 0xa6f8, is taken when s2(=[a3+24]:8) >= t2(=one of 0xc00000, 0x1400000) (unsigned), and falls through when s2(=[a3+24]:8) < t2(=one of 0xc00000, 0x1400000) (unsigned).
  The `beq` branch at 0xa6ac targets 0xac5c, is taken when v0(?) == ra(=0x1), and falls through when v0(?) != ra(=0x1).
  The `beq` branch at 0xa6b8 targets 0xac5c, is taken when v0(?) == v1(=0x3), and falls through when v0(?) != v1(=0x3).
  The `blez` branch at 0xa6c0 targets 0xa6d0, is taken when t8(?) <= 0 (signed), and falls through when t8(?) > 0 (signed).
  The `bne` branch at 0xa6d0 targets 0xa6e0, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0xa6e8 targets 0xae4c, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa6f8 targets 0xab98, is taken when t1(=[a0+114]:2) == a6(=0x2), and falls through when t1(=[a0+114]:2) != a6(=0x2).
  The `bne` branch at 0xa704 targets 0xa794, is taken when s2(=[a3+24]:8) < t8(=0x40000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t8(=0x40000000) (unsigned).
  The `bne` branch at 0xa714 targets 0xa798, is taken when t9(=0x7fffffff) < s2(=[a3+24]:8) (unsigned), and falls through when t9(=0x7fffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa730 targets 0xa748, is taken when s2(=[a3+24]:8) < ra(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= ra(=0x80000000) (unsigned).
  The `beq` branch at 0xa740 targets 0xa7bc, is taken when at(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when at(=0xbfffffff) < s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa754 targets 0xa76c, is taken when s2(=[a3+24]:8) < v0(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= v0(=0x100000000) (unsigned).
  The `beq` branch at 0xa764 targets 0xa834, is taken when v1(=0x1ffffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when v1(=0x1ffffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa76c targets 0xaf0c, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa78c targets 0xa884 and is always taken.
  The `bne` branch at 0xa7a0 targets 0xa814, is taken when s2(=[a3+24]:8) < a4(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= a4(=0x80000000) (unsigned).
  The `bne` branch at 0xa7b0 targets 0xa814, is taken when a7(=0xbfffffff) < s2(=[a3+24]:8) (unsigned), and falls through when a7(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xa7cc targets 0xa7e8, is taken when s2(=[a3+24]:8) < t0(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t0(=0x100000000) (unsigned).
  The `beq` branch at 0xa7e0 targets 0xa834, is taken when t1(=0x1ffffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when t1(=0x1ffffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa7e8 targets 0xae88, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa808 targets 0xa884 and is always taken.
  The `bne` branch at 0xa81c targets 0xa864, is taken when s2(=[a3+24]:8) < t3(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t3(=0x100000000) (unsigned).
  The `bne` branch at 0xa82c targets 0xa864, is taken when t8(=0x1ffffffff) < s2(=[a3+24]:8) (unsigned), and falls through when t8(=0x1ffffffff) >= s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xa83c targets 0xae6c, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa85c targets 0xa884 and is always taken.
  The `beq` branch at 0xa868 targets 0xac68, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `bne` branch at 0xa88c targets 0xa9e0, is taken when a7(?) != 0, and falls through when a7(?) == 0.
  The `beq` branch at 0xa8a0 targets 0xb264 and is always taken.
  The `bne` branch at 0xa8c0 targets 0xa9e0, is taken when t1(=[a0+57]:1) < a4(?) (signed), and falls through when t1(=[a0+57]:1) >= a4(?) (signed).
  The `blez` branch at 0xa8d0 targets 0xa8ac, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0xa8d8 targets 0xb258 and is always taken.
  The `beq` branch at 0xa8e0 targets 0xa9cc, is taken when v0(?) == ra(=0x1), and falls through when v0(?) != ra(=0x1).
  The `beq` branch at 0xa8e8 targets 0xa974, is taken when v0(?) == s1(=0x5), and falls through when v0(?) != s1(=0x5).
  The `beq` branch at 0xa8f0 targets 0xa974, is taken when v0(?) == s4(=0x6), and falls through when v0(?) != s4(=0x6).
  The `bne` branch at 0xa8f8 targets 0xa97c, is taken when v0(?) != s0(?), and falls through when v0(?) == s0(?).
  The `bne` branch at 0xa900 targets 0xa97c, is taken when at(?) != 0, and falls through when at(?) == 0.
  The `beq` branch at 0xa914 targets 0xa97c, is taken when s3(?) >= v0(?) (unsigned), and falls through when s3(?) < v0(?) (unsigned).
  The `beql` branch at 0xa930 targets 0xa920, is taken when t2(=table(0x1)) == 0, and falls through when t2(=table(0x1)) != 0; its branch-likely delay slot `nop` at 0xa934 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0xa938 targets 0xab3c, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xa94c targets 0xa8a8, is taken when t9(?) >= s6(?) (signed), and falls through when t9(?) < s6(?) (signed).
  The `beq` branch at 0xa958 targets 0xa940, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xa964 targets 0xa940, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `beq` branch at 0xa96c targets 0xa98c and is always taken.
  The `beq` branch at 0xa974 targets 0xa900, is taken when s0(?) == s7(=0x4), and falls through when s0(?) != s7(=0x4).
  The `beq` branch at 0xa980 targets 0xa940, is taken when t1(?) == 0, and falls through when t1(?) != 0.
  The `bne` branch at 0xa998 targets 0xa8e0, is taken when v0(?) < 0x8 (signed), and falls through when v0(?) >= 0x8 (signed).
  The `beq` branch at 0xa9a0 targets 0xa8e0, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `bne` branch at 0xa9c4 targets 0xa8e8, is taken when v0(?) != ra(=0x1), and falls through when v0(?) == ra(=0x1).
  The `bne` branch at 0xa9d0 targets 0xa97c, is taken when s0(?) != s7(=0x4), and falls through when s0(?) == s7(=0x4).
  The `beq` branch at 0xa9d8 targets 0xa900 and is always taken.
  The `beq` branch at 0xaa20 targets 0xaa84, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xaa28 targets 0xaa68, is taken when s6(=0xff) == s2(?), and falls through when s6(=0xff) != s2(?).
  The `beq` branch at 0xaa34 targets 0xac30, is taken when a3(=[a0+114]:2) == s7(=0x2), and falls through when a3(=[a0+114]:2) != s7(=0x2).
  The `beq` branch at 0xaa48 targets 0xac38, is taken when s6(=0xff) == a6(?), and falls through when s6(=0xff) != a6(?).
  The `beq` branch at 0xaa84 targets 0xade8, is taken when s5(=a2) == 0, and falls through when s5(=a2) != 0.
  The `beq` branch at 0xaa8c targets 0xb000, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xaaa8 targets 0xab08, is taken when v0(=ret(pciio_error_handler)) == 0, and falls through when v0(=ret(pciio_error_handler)) != 0.
  The `beq` branch at 0xaab4 targets 0xb01c, is taken when v0(=ret(pciio_error_handler)) == t1(=0x9), and falls through when v0(=ret(pciio_error_handler)) != t1(=0x9).
  The `bne` branch at 0xaac0 targets 0xb044, is taken when t2(=[sym(kdebug)]:2) != 0, and falls through when t2(=[sym(kdebug)]:2) == 0.
  The `beq` branch at 0xaae0 targets 0xac20, is taken when s6(=0xff) == v0(?), and falls through when s6(=0xff) != v0(?).
  The `beq` branch at 0xaaec targets 0xac28, is taken when a1(=[a0+114]:2) == s7(=0x2), and falls through when a1(=[a0+114]:2) != s7(=0x2).
  The `bltz` branch at 0xaaf8 targets 0xae20, is taken when a4(=([a3] << 0x2)) < 0 (signed), and falls through when a4(=([a3] << 0x2)) >= 0 (signed).
  The `beq` branch at 0xab00 targets 0xae30, is taken when s5(=a2) == s7(=0x2), and falls through when s5(=a2) != s7(=0x2).
  The `bltz` branch at 0xab48 targets 0xa940, is taken when t8(?) < 0 (signed), and falls through when t8(?) >= 0 (signed).
  The `beq` branch at 0xab54 targets 0xa940, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xab78 targets 0xa940 and is always taken.
  The `beq` branch at 0xab90 targets 0xa5c0 and is always taken.
  The `beq` branch at 0xab98 targets 0xae94, is taken when a4(=[a0+72]) == 0, and falls through when a4(=[a0+72]) != 0.
  The `bne` branch at 0xaba0 targets 0xa700, is taken when a4(=[a0+72]) != t9(=0x1), and falls through when a4(=[a0+72]) == t9(=0x1).
  The `bne` branch at 0xabb4 targets 0xaf68, is taken when s2(=[a3+24]:8) < ra(=0xc0000000) (unsigned), and falls through when s2(=[a3+24]:8) >= ra(=0xc0000000) (unsigned).
  The `bne` branch at 0xabc8 targets 0xaf68, is taken when at(=0xffffffff) < s2(=[a3+24]:8) (unsigned), and falls through when at(=0xffffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xabe0 targets 0xabf8, is taken when s2(=[a3+24]:8) < t8(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= t8(=0x100000000) (unsigned).
  The `beq` branch at 0xabf0 targets 0xaf88, is taken when t9(=0x13fffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when t9(=0x13fffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xabf8 targets 0xaff4, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xac18 targets 0xa884 and is always taken.
  The `beq` branch at 0xac20 targets 0xaaf8 and is always taken.
  The `beq` branch at 0xac28 targets 0xaaf4 and is always taken.
  The `beq` branch at 0xac30 targets 0xaa3c and is always taken.
  The `beq` branch at 0xac44 targets 0xaa68 and is always taken.
  The `beq` branch at 0xac54 targets 0xa664 and is always taken.
  The `beq` branch at 0xac60 targets 0xa6c0 and is always taken.
  The `beq` branch at 0xac68 targets 0xafb8, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0xac7c targets 0xae78, is taken when t1(=[a0+57]:1) < a4(=[a0+56]:1) (signed), and falls through when t1(=[a0+57]:1) >= a4(=[a0+56]:1) (signed).
  The `beq` branch at 0xac98 targets 0xacb8 and is always taken.
  The `bne` branch at 0xaca8 targets 0xa888, is taken when t1(=[a0+57]:1) < t2(?) (signed), and falls through when t1(=[a0+57]:1) >= t2(?) (signed).
  The `bne` branch at 0xacb0 targets 0xa888, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `blez` branch at 0xacc4 targets 0xaca0, is taken when s5(?) <= 0 (signed), and falls through when s5(?) > 0 (signed).
  The `bne` branch at 0xaccc targets 0xaca0, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xacd4 targets 0xacf4 and is always taken.
  The `beq` branch at 0xace8 targets 0xaca0, is taken when v0(?) >= s5(?) (signed), and falls through when v0(?) < s5(?) (signed).
  The `bne` branch at 0xacf0 targets 0xaca0, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xad00 targets 0xace0, is taken when s6(?) == 0, and falls through when s6(?) != 0.
  The `bne` branch at 0xad08 targets 0xace0, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xad14 targets 0xad3c and is always taken.
  The `beq` branch at 0xad30 targets 0xacdc, is taken when s8(?) == 0, and falls through when s8(?) != 0.
  The `bne` branch at 0xad38 targets 0xacdc, is taken when a0(=0xff) != a1(?), and falls through when a0(=0xff) == a1(?).
  The `beq` branch at 0xad54 targets 0xad30, is taken when t3(?) == 0, and falls through when t3(?) != 0.
  The `beq` branch at 0xad64 targets 0xad30, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xad7c targets 0xad30, is taken when v1(?) == 0, and falls through when v1(?) != 0.
  The `beq` branch at 0xad90 targets 0xad30, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0xad98 targets 0xad30, is taken when v1(?) != 0, and falls through when v1(?) == 0.
  The `beq` branch at 0xada0 targets 0xad30, is taken when at(?) == 0, and falls through when at(?) != 0.
  The `beq` branch at 0xada8 targets 0xad1c, is taken when t3(?) == a3(?), and falls through when t3(?) != a3(?).
  The `beq` branch at 0xadb0 targets 0xadc8, is taken when t3(?) == s7(=0x4), and falls through when t3(?) != s7(=0x4).
  The `beq` branch at 0xadb8 targets 0xadc8, is taken when t3(?) == s1(=0x5), and falls through when t3(?) != s1(=0x5).
  The `bne` branch at 0xadc0 targets 0xad30, is taken when t3(?) != s4(=0x6), and falls through when t3(?) == s4(=0x6).
  The `beq` branch at 0xadc8 targets 0xad1c, is taken when a3(?) == s7(=0x4), and falls through when a3(?) != s7(=0x4).
  The `beq` branch at 0xadd0 targets 0xad1c, is taken when a3(?) == s1(=0x5), and falls through when a3(?) != s1(=0x5).
  The `bne` branch at 0xadd8 targets 0xad30, is taken when a3(?) != s4(=0x6), and falls through when a3(?) == s4(=0x6).
  The `beq` branch at 0xade0 targets 0xad20 and is always taken.
  The `bne` branch at 0xadf4 targets 0xae04, is taken when s6(=0xff) != s2(?), and falls through when s6(=0xff) == s2(?).
  The `beq` branch at 0xadfc targets 0xae18 and is always taken.
  The `beq` branch at 0xae18 targets 0xab0c and is always taken.
  The `beq` branch at 0xae28 targets 0xab00 and is always taken.
  The `beq` branch at 0xae38 targets 0xab0c and is always taken.
  The `beq` branch at 0xae44 targets 0xa5fc and is always taken.
  The `beq` branch at 0xae64 targets 0xa6f8 and is always taken.
  The `beq` branch at 0xae70 targets 0xac70 and is always taken.
  The `beq` branch at 0xae80 targets 0xa884 and is always taken.
  The `beq` branch at 0xae8c targets 0xac70 and is always taken.
  The `bne` branch at 0xae9c targets 0xaf1c, is taken when s2(=[a3+24]:8) < ra(=0x40000000) (unsigned), and falls through when s2(=[a3+24]:8) >= ra(=0x40000000) (unsigned).
  The `bne` branch at 0xaeb0 targets 0xaf1c, is taken when at(=0x7fffffff) < s2(=[a3+24]:8) (unsigned), and falls through when at(=0x7fffffff) >= s2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xaecc targets 0xaee4, is taken when s2(=[a3+24]:8) < v0(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= v0(=0x80000000) (unsigned).
  The `beq` branch at 0xaedc targets 0xaf38, is taken when v1(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned), and falls through when v1(=0xbfffffff) < s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xaee4 targets 0xafe8, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xaf04 targets 0xa884 and is always taken.
  The `beq` branch at 0xaf10 targets 0xac70 and is always taken.
  The `bne` branch at 0xaf24 targets 0xa864, is taken when s2(=[a3+24]:8) < a4(=0x80000000) (unsigned), and falls through when s2(=[a3+24]:8) >= a4(=0x80000000) (unsigned).
  The `bne` branch at 0xaf30 targets 0xa864, is taken when a7(=0xbfffffff) < s2(=[a3+24]:8) (unsigned), and falls through when a7(=0xbfffffff) >= s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xaf3c targets 0xafd0, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xaf5c targets 0xa884 and is always taken.
  The `bne` branch at 0xaf70 targets 0xa864, is taken when s2(=[a3+24]:8) < a4(=0x100000000) (unsigned), and falls through when s2(=[a3+24]:8) >= a4(=0x100000000) (unsigned).
  The `bne` branch at 0xaf7c targets 0xa868, is taken when a7(=0x13fffffff) < s2(=[a3+24]:8) (unsigned), and falls through when a7(=0x13fffffff) >= s2(=[a3+24]:8) (unsigned).
  The `beq` branch at 0xaf90 targets 0xafdc, is taken when a0(=0xff) == a1(?), and falls through when a0(=0xff) != a1(?).
  The `beq` branch at 0xafb0 targets 0xa884 and is always taken.
  The `beq` branch at 0xafc8 targets 0xa884 and is always taken.
  The `beq` branch at 0xafd4 targets 0xac70 and is always taken.
  The `beq` branch at 0xafe0 targets 0xac70 and is always taken.
  The `beq` branch at 0xafec targets 0xac70 and is always taken.
  The `beq` branch at 0xaff8 targets 0xac70 and is always taken.
  The `beq` branch at 0xb014 targets 0xab0c and is always taken.
  The `bltz` branch at 0xb034 targets 0xb174, is taken when a2(=([a3] << 0x8)) < 0 (signed), and falls through when a2(=([a3] << 0x8)) >= 0 (signed).
  The `beq` branch at 0xb03c targets 0xaabc and is always taken.
  The `beq` branch at 0xb064 targets 0xb078, is taken when (v0(=ret(pcireg_intr_status_get)) & a3(=0x4400008800)) == 0, and falls through when (v0(=ret(pcireg_intr_status_get)) & a3(=0x4400008800)) != 0.
  The `bgez` branch at 0xb0c0 targets 0xaadc, is taken when a4(=([a3] << 0x2)) >= 0 (signed), and falls through when a4(=([a3] << 0x2)) < 0 (signed).
  The `beq` branch at 0xb0c8 targets 0xb1dc, is taken when s6(=0xff) == a0(?), and falls through when s6(=0xff) != a0(?).
  The `beq` branch at 0xb0d4 targets 0xb1f0, is taken when a5(=[a0+114]:2) == s7(=0x2), and falls through when a5(=[a0+114]:2) != s7(=0x2).
  The `beq` branch at 0xb0e8 targets 0xaae0, is taken when s0(?) >= a6(=[a0+57]:1+1) (signed), and falls through when s0(?) < a6(=[a0+57]:1+1) (signed).
  The `beq` branch at 0xb16c targets 0xaadc and is always taken.
  The `beq` branch at 0xb17c targets 0xb214, is taken when v0(=[a3+36]) == a5(=0x7), and falls through when v0(=[a3+36]) != a5(=0x7).
  The `beq` branch at 0xb184 targets 0xb23c, is taken when s7(=0x2) == v0(=[a3+36]), and falls through when s7(=0x2) != v0(=[a3+36]).
  The `beq` branch at 0xb18c targets 0xb1f8, is taken when v0(=[a3+36]) == a6(=0x4), and falls through when v0(=[a3+36]) != a6(=0x4).
  The `beq` branch at 0xb194 targets 0xb1fc, is taken when v0(=[a3+36]) == a7(=0x5), and falls through when v0(=[a3+36]) != a7(=0x5).
  The `beq` branch at 0xb1a0 targets 0xb1f8, is taken when v0(=[a3+36]) == t0(=0x6), and falls through when v0(=[a3+36]) != t0(=0x6).
  The `beq` branch at 0xb1ac targets 0xb03c, is taken when a4(=[a3+36]-8) >= 0x6 (unsigned), and falls through when a4(=[a3+36]-8) < 0x6 (unsigned).
  The `beq` branch at 0xb1d4 targets 0xb03c and is always taken.
  The `bne` branch at 0xb1e0 targets 0xaae0, is taken when t1(=[a0+57]:1) < 0xff (signed), and falls through when t1(=[a0+57]:1) >= 0xff (signed).
  The `beq` branch at 0xb1e8 targets 0xb0f0 and is always taken.
  The `beq` branch at 0xb1f0 targets 0xb0dc and is always taken.
  The `beq` branch at 0xb20c targets 0xb03c and is always taken.
  The `beq` branch at 0xb234 targets 0xb03c and is always taken.
  The `beq` branch at 0xb250 targets 0xb03c and is always taken.
  The `beq` branch at 0xb25c targets 0xa958 and is always taken.
  The `beq` branch at 0xb26c targets 0xa8cc and is always taken.
  The return at 0xab34 has v0 = one of ?, 0x7.
  The instructions from 0xa810 to 0xa810 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xaf18 to 0xaf18 are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0xaf64 to 0xaf64 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_dmard_error` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xb274 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xb274-0xb39c (296 bytes).
  It occupies 296 bytes.
  The `lw` at 0xb274 loads 4 bytes from a0 (arg0 at entry) +0x4.
  2 such `lw` accesses load 4 bytes from a3 (arg3 at entry) +0x0, including `lw` at 0xb2b8, `lw` at 0xb2d4.
  The `sh` at 0xb2bc stores 2 bytes to a3 (arg3 at entry) +0x8.
  2 such `sw` accesses store 4 bytes to a3 (arg3 at entry) +0x0, including `sw` at 0xb2d0, `sw` at 0xb2e8.
  The `sd` at 0xb2d8 stores 8 bytes to a3 (arg3 at entry) +0x28.
  The `lh` at 0xb304 loads 2 bytes from a3 (arg3 at entry) +0x8.
  The `jal` at 0xb2a0 calls pcireg_resp_err_buf_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb2ac calls pcireg_resp_err_dev_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb2cc calls pcireg_resp_err_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb2f4 calls pciio_error_handler with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb310 calls pcibr_device_disable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb324 calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=0x10, a2=?, a3=?.
  The `jal` at 0xb340 calls pcireg_rrb_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb36c calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb37c calls pcireg_rrb_set with a0=a0 at entry (arg0), a1=?, a2=ret(pcireg_rrb_get), a3=?.
  The `beq` branch at 0xb2fc targets 0xb318, is taken when v0(=ret(pciio_error_handler)) == 0, and falls through when v0(=ret(pciio_error_handler)) != 0.
  The return at 0xb394 has v0 = ret(pciio_error_handler).

- `pcibr_dmawr_error` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xb39c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xb39c-0xb3e4 (72 bytes).
  It occupies 72 bytes.
  The `lw` at 0xb3b0 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lh` at 0xb3c0 loads 2 bytes from a3 (arg3 at entry) +0x8.
  The `jal` at 0xb3ac calls pciio_error_handler with a0=[a0+4], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb3cc calls pcibr_device_disable with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xb3b4 targets 0xb3d4, is taken when v0(=ret(pciio_error_handler)) == 0, and falls through when v0(=ret(pciio_error_handler)) != 0.
  The return at 0xb3dc has v0 = ret(pciio_error_handler).

- `pcibr_error_handler` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xb3e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xb3e4-0xb4ac (200 bytes).
  It occupies 200 bytes.
  The `lw` at 0xb418 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `jal` at 0xb41c calls pcibr_debug with a0=0x200, a1=[a0], a2=sym(.rodata)+6264, a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The `jal` at 0xb43c calls pcibr_pioerror with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb464 calls pcibr_dmard_error with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=a3 at entry (arg3).
  The `jal` at 0xb484 calls pcibr_dmawr_error with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x1, a3=a3 at entry (arg3).
  The `beq` branch at 0xb428 targets 0xb448, is taken when (s0(=a1) & 0x4) == 0, and falls through when (s0(=a1) & 0x4) != 0.
  The `beq` branch at 0xb44c targets 0xb490, is taken when (s0(=a1) & 0x8) == 0, and falls through when (s0(=a1) & 0x8) != 0.
  The `beq` branch at 0xb454 targets 0xb470, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xb474 targets 0xb490, is taken when (s0(=a1) & 0x2) == 0, and falls through when (s0(=a1) & 0x2) != 0.
  The return at 0xb4a4 has v0 = one of ?, ret(pcibr_dmawr_error).

- `pcibr_error_handler_wrapper` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xb4ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xb4ac-0xb6f4 (584 bytes).
  It occupies 584 bytes.
  The `lw` at 0xb4bc loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `ld` at 0xb520 loads 8 bytes from a3 (arg3 at entry) +0x18.
  The `ld` at 0xb58c loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `lh` at 0xb66c loads 2 bytes from a3 (arg3 at entry) +0x50.
  The `lw` at 0xb674 loads 4 bytes from a3 (arg3 at entry) +0x0.
  The `sw` at 0xb688 stores 4 bytes to a3 (arg3 at entry) +0x0.
  The `sh` at 0xb694 stores 2 bytes to a3 (arg3 at entry) +0x8.
  The `ld` at 0xb69c loads 8 bytes from ?.
  The `jal` at 0xb4fc calls pcibr_debug with a0=0x200, a1=[a0], a2=sym(.rodata)+6264, a3=a0 at entry (arg0), a4=a1 at entry (arg1).
  The `jal` at 0xb624 calls pcibr_error_handler with a0=a0 at entry (arg0), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb644 calls pcibr_error_handler with a0=[a0+64]:8, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb6a0 calls pcibr_error_handler with a0=?, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=([a3] | 0x20000000), a6=0x20000000.
  The `jal` at 0xb6c4 calls pcibr_error_handler with a0=?, a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3), a5=([a3] | 0x20000000), a6=0x20000000.
  The `jal` at 0xb6e0 calls cmn_err with a0=0x4, a1=sym(.rodata)+6264, a2=[a3+24]:8, a3=?.
  The `beq` branch at 0xb518 targets 0xb654, is taken when (s1(=a1) & 0x4) == 0, and falls through when (s1(=a1) & 0x4) != 0.
  The `beq` branch at 0xb540 targets 0xb614, is taken when a4(=0x7fffff) >= a2(=[a3+24]:8) (unsigned), and falls through when a4(=0x7fffff) < a2(=[a3+24]:8) (unsigned).
  The `bne` branch at 0xb558 targets 0xb564, is taken when a2(=[a3+24]:8) < a5(=0x40000000) (unsigned), and falls through when a2(=[a3+24]:8) >= a5(=0x40000000) (unsigned).
  The `beq` branch at 0xb560 targets 0xb614, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0xb56c targets 0xb57c, is taken when a2(=[a3+24]:8) < a6(=0x800000) (unsigned), and falls through when a2(=[a3+24]:8) >= a6(=0x800000) (unsigned).
  The `beq` branch at 0xb574 targets 0xb58c, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0xb57c targets 0xb6dc, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `bne` branch at 0xb584 targets 0xb6dc, is taken when a3(?) != 0, and falls through when a3(?) == 0.
  The `bne` branch at 0xb590 targets 0xb638, is taken when s3(=[a0+64]:8) != 0, and falls through when s3(=[a0+64]:8) == 0.
  The `beq` branch at 0xb5a4 targets 0xb66c, is taken when a7(?) == t0(=0xa), and falls through when a7(?) != t0(=0xa).
  The `beq` branch at 0xb5b8 targets 0xb65c, is taken when s0(?) == s5(=-0x1), and falls through when s0(?) != s5(=-0x1).
  The `beq` branch at 0xb5c0 targets 0xb5fc, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xb5c8 targets 0xb5fc, is taken when a0(?) == s5(=-0x1), and falls through when a0(?) != s5(=-0x1).
  The `beq` branch at 0xb5fc targets 0xb6b4, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xb604 targets 0xb6b4, is taken when s0(?) == s5(=-0x1), and falls through when s0(?) != s5(=-0x1).
  The `beq` branch at 0xb60c targets 0xb5d4 and is always taken.
  The `beq` branch at 0xb630 targets 0xb59c and is always taken.
  The `beq` branch at 0xb64c targets 0xb598 and is always taken.
  The `beq` branch at 0xb654 targets 0xb5a0 and is always taken.
  The `bne` branch at 0xb65c targets 0xb5c0, is taken when a0(?) != s5(=-0x1), and falls through when a0(?) == s5(=-0x1).
  The `beq` branch at 0xb664 targets 0xb5d0 and is always taken.
  The `beq` branch at 0xb690 targets 0xb6bc, is taken when (a4(=[a3+80]:2) & 0x4) == 0, and falls through when (a4(=[a3+80]:2) & 0x4) != 0.
  The `beq` branch at 0xb6ac targets 0xb5ac and is always taken.
  The `beq` branch at 0xb6b4 targets 0xb5d0 and is always taken.
  The `beq` branch at 0xb6d0 targets 0xb5ac and is always taken.
  The `beq` branch at 0xb6ec targets 0xb59c and is always taken.
  The return at 0xb5f4 has v0 = ?.
  The instructions from 0xb6d8 to 0xb6d8 are not reached by any path from the entry, and their branches are not listed.

- `pcibr_error_devenable` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xb6f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xb6f4-0xb770 (124 bytes).
  It occupies 124 bytes.
  The `lbu` at 0xb70c loads 1 byte from ret(pciio_info_get) +0x21c.
  The `lw` at 0xb72c loads 4 bytes from ret(pciio_info_mfast_get) +0x0.
  The `jal` at 0xb700 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb714 calls pciio_info_mfast_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xb734 calls xtalk_error_devenable with a0=[ret(pciio_info_mfast_get)], a1=[ret(pciio_info_get)+540]:1, a2=a1 at entry (arg1), a3=?.
  The `jal` at 0xb750 calls pcibr_error_cleanup with a0=ret(pciio_info_mfast_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `bne` branch at 0xb724 targets 0xb750, is taken when (s0(=a1) & 0x2) != 0, and falls through when (s0(=a1) & 0x2) == 0.
  The `beq` branch at 0xb73c targets 0xb750, is taken when v0(=ret(xtalk_error_devenable)) == 0, and falls through when v0(=ret(xtalk_error_devenable)) != 0.
  The `beq` branch at 0xb744 targets 0xb760 and is always taken.
  The return at 0xb768 has v0 = one of ret(xtalk_error_devenable), 0x0.
  The instructions from 0xb74c to 0xb74c are not reached by any path from the entry, and their branches are not listed.

- `pcibr_func_config_addr` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xb770 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xb770-0xb7f4 (132 bytes).
  It occupies 132 bytes.
  The `jal` at 0xb7a4 calls pcireg_type1_cntr_set with a0=a0 at entry (arg0), a1=((a1 << 0x10) | (a2 << 0xb)), a2=(a2 << 0xb), a3=a3 at entry (arg3), a7=a1 at entry (arg1).
  The `jal` at 0xb7b4 calls pcireg_type1_cfg_addr with a0=a0 at entry (arg0), a1=a3 at entry (arg3), a2=a4 at entry (arg4), a3=?.
  The `jal` at 0xb7e4 calls pcireg_type0_cfg_addr with a0=a0 at entry (arg0), a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=a4 at entry (arg4), a7=a1 at entry (arg1).
  The `blez` branch at 0xb794 targets 0xb7dc, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0xb7ec targets 0xb7c0 and is always taken.
  The return at 0xb7d4 has v0 = one of ret(pcireg_type1_cfg_addr), ret(pcireg_type0_cfg_addr).

- `pcibr_slot_config_addr` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xb7f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xb7f4-0xb820 (44 bytes).
  It occupies 44 bytes.
  The `jal` at 0xb80c calls pcibr_func_config_addr with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=0x0, a4=a2 at entry (arg2).
  The return at 0xb818 has v0 = ret(pcibr_func_config_addr).

- `pcibr_slot_config_get` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xb820 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xb820-0xb85c (60 bytes).
  It occupies 60 bytes.
  The `jal` at 0xb830 calls pcibr_slot_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0xb840 calls do_pcibr_config_get with a0=ret(pcibr_slot_config_addr), a1=a2 at entry (arg2), a2=0x4, a3=?.
  The return at 0xb854 has v0 = (ret(do_pcibr_config_get) << 0x0).

- `pcibr_func_config_get` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xb85c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xb85c-0xb8ac (80 bytes).
  It occupies 80 bytes.
  The `jal` at 0xb880 calls pcibr_func_config_addr with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `jal` at 0xb890 calls do_pcibr_config_get with a0=ret(pcibr_func_config_addr), a1=a3 at entry (arg3), a2=0x4, a3=?.
  The return at 0xb8a4 has v0 = (ret(do_pcibr_config_get) << 0x0).

- `pcibr_slot_config_set` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xb8ac (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xb8ac-0xb8f4 (72 bytes).
  It occupies 72 bytes.
  The `jal` at 0xb8c0 calls pcibr_slot_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=a3 at entry (arg3).
  The `jal` at 0xb8dc calls do_pcibr_config_set with a0=ret(pcibr_slot_config_addr), a1=a2 at entry (arg2), a2=0x4, a3=?.
  The return at 0xb8ec has v0 = ret(do_pcibr_config_set).

- `pcibr_func_config_set` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xb8f4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xb8f4-0xb950 (92 bytes).
  It occupies 92 bytes.
  The `jal` at 0xb91c calls pcibr_func_config_addr with a0=a0 at entry (arg0), a1=0x0, a2=a1 at entry (arg1), a3=a2 at entry (arg2), a4=0x0.
  The `jal` at 0xb938 calls do_pcibr_config_set with a0=ret(pcibr_func_config_addr), a1=a3 at entry (arg3), a2=0x4, a3=?.
  The return at 0xb948 has v0 = ret(do_pcibr_config_set).

- `pcibr_config_addr` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xb950 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xb950-0xba44 (244 bytes).
  It occupies 244 bytes.
  The `ld` at 0xb9b8 loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `ld` at 0xb9c8 loads 8 bytes from [ret(pcibr_info_get)+40]:8 +0x8.
  The `lbu` at 0xb9ec loads 1 byte from ret(pciio_info_get) +0x12.
  The `lbu` at 0xb9f0 loads 1 byte from ret(pciio_info_get) +0x11.
  The `lbu` at 0xb9f8 loads 1 byte from ret(pciio_info_get) +0x10.
  The `lbu` at 0xba08 loads 1 byte from ret(pcibr_info_get) +0x21c.
  The `lbu` at 0xba10 loads 1 byte from ret(pcibr_info_get) +0x12.
  The `jal` at 0xb968 calls pciio_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xb978 calls pcibr_info_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xb984 calls pciio_info_type1_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `jal` at 0xb9c4 calls pcibr_func_config_addr with a0=[[ret(pcibr_info_get)+40]:8+8]:8, a1=?, a2=?, a3=?, a4=0x0.
  The `jal` at 0xb9dc calls pciio_info_hostdev_get with a0=ret(pciio_info_get), a1=?, a2=?, a3=?.
  The `beq` branch at 0xb98c targets 0xb9dc, is taken when v0(=ret(pciio_info_type1_get)) == 0, and falls through when v0(=ret(pciio_info_type1_get)) != 0.
  The `beq` branch at 0xb9e4 targets 0xba08, is taken when v0(=ret(pciio_info_hostdev_get)) == s2(=a0), and falls through when v0(=ret(pciio_info_hostdev_get)) != s2(=a0).
  The `beq` branch at 0xba00 targets 0xb9b0 and is always taken.
  The `beq` branch at 0xba0c targets 0xba24, is taken when a0(=0xff) == a2(=[ret(pcibr_info_get)+540]:1), and falls through when a0(=0xff) != a2(=[ret(pcibr_info_get)+540]:1).
  The `beq` branch at 0xba14 targets 0xba34, is taken when a0(=0xff) == a3(=[ret(pcibr_info_get)+18]:1), and falls through when a0(=0xff) != a3(=[ret(pcibr_info_get)+18]:1).
  The `beq` branch at 0xba1c targets 0xb9b4 and is always taken.
  The `beq` branch at 0xba2c targets 0xba14 and is always taken.
  The `beq` branch at 0xba3c targets 0xba18 and is always taken.
  The return at 0xb9d4 has v0 = ret(pcibr_func_config_addr).

- `pcibr_config_get` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xba44 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xba44-0xba7c (56 bytes).
  It occupies 56 bytes.
  The `jal` at 0xba54 calls pcibr_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xba64 calls do_pcibr_config_get with a0=ret(pcibr_config_addr), a1=?, a2=a2 at entry (arg2), a3=?.
  The return at 0xba74 has v0 = ret(do_pcibr_config_get).

- `pcibr_config_get_safe` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xba7c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xba7c-0xbadc (96 bytes).
  It occupies 96 bytes.
  The `ld` at 0xba94 loads 8 bytes from ret(pcibr_info_get) +0x28.
  The `ld` at 0xba9c loads 8 bytes from [ret(pcibr_info_get)+40]:8 +0x8.
  The `jal` at 0xba8c calls pcibr_info_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbaa4 calls pcibr_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xbab8 calls pcibr_probe_slot with a0=?, a1=ret(pcibr_config_addr), a2=sp-48, a3=?.
  The `beq` branch at 0xbac0 targets 0xbad4, is taken when v0(=ret(pcibr_probe_slot)) == 0, and falls through when v0(=ret(pcibr_probe_slot)) != 0.
  The `beq` branch at 0xbad4 targets 0xbacc and is always taken.
  The return at 0xbacc has v0 = one of -0x1, ?.

- `do_pcibr_config_get` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xbadc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xbadc-0xbb28 (76 bytes).
  It occupies 76 bytes.
  The `lw` at 0xbb00 loads 4 bytes from ?.
  The `beq` branch at 0xbafc targets 0xbb0c, is taken when (a1 & 0x3) == 0, and falls through when (a1 & 0x3) != 0.
  The `beq` branch at 0xbb0c targets 0xbb1c, is taken when a5(?) == 0, and falls through when a5(?) != 0.
  The return at 0xbb20 has v0 = ?.

- `pcibr_config_set` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xbb28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xbb28-0xbb68 (64 bytes).
  It occupies 64 bytes.
  The `jal` at 0xbb3c calls pcibr_config_addr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbb50 calls do_pcibr_config_set with a0=ret(pcibr_config_addr), a1=?, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xbb60 has v0 = ret(do_pcibr_config_set).

- `do_pcibr_config_set` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xbb68 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xbb68-0xbca0 (312 bytes).
  It occupies 312 bytes.
  5 such `sb` accesses store 1 byte to ?, including `sb` at 0xbbc8, `sb` at 0xbbd4, `sb` at 0xbc08.
  3 such `sh` accesses store 2 bytes to ?, including `sh` at 0xbc14, `sh` at 0xbc60, `sh` at 0xbc94.
  The `sw` at 0xbc28 stores 4 bytes to ?.
  The `beq` branch at 0xbb74 targets 0xbc2c, is taken when a2 == at(=0x1), and falls through when a2 != at(=0x1).
  The `beq` branch at 0xbb7c targets 0xbb9c, is taken when a2 == a5(=0x2), and falls through when a2 != a5(=0x2).
  The `beq` branch at 0xbb84 targets 0xbbd8, is taken when a2 == a6(=0x3), and falls through when a2 != a6(=0x3).
  The `beq` branch at 0xbb8c targets 0xbc18, is taken when a2 == a7(=0x4), and falls through when a2 != a7(=0x4).
  The `beq` branch at 0xbbb0 targets 0xbc44, is taken when (a1 & 0x1) == 0, and falls through when (a1 & 0x1) != 0.
  The `beq` branch at 0xbbe4 targets 0xbc64, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The return at 0xbb94 has v0 = ?.
  The return at 0xbbd0 has v0 = ?.
  The return at 0xbc10 has v0 = ?.
  The return at 0xbc24 has v0 = ?.
  The return at 0xbc3c has v0 = ?.
  The return at 0xbc5c has v0 = ?.
  The return at 0xbc98 has v0 = ?.

- `pcibr_slot_startup` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xbca0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xbca0-0xbe00 (352 bytes).
  It occupies 352 bytes.
  The `lbu` at 0xbcc8 loads 1 byte from a1 (arg1 at entry) +0x3.
  The `lh` at 0xbce4 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `lw` at 0xbd1c loads 4 bytes from ret(hwgraph_fastinfo_get) +0x0.
  The `lbu` at 0xbd50 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xbd88 loads 4 bytes from ?.
  The `lw` at 0xbde0 loads 4 bytes from a1 (arg1 at entry) +0x10.
  The `ld` at 0xbde4 loads 8 bytes from a1 (arg1 at entry) +0x8.
  The `jal` at 0xbcb8 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbd10 calls pcibr_debug with a0=0x8000, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=ret(hwgraph_fastinfo_get), a5=a1 at entry (arg1).
  The `jal` at 0xbd20 calls nic_vertex_info_match with a0=[ret(hwgraph_fastinfo_get)], a1=sym(.rodata)+11000, a2=?, a3=?.
  The `jal` at 0xbd78 calls mrlock with a0=ret(hwgraph_fastinfo_get)+144, a1=0x2, a2=0x19, a3=?.
  The `jal` at 0xbda0 calls mrunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xbdc0 calls pcibr_slot_attach with a0=a0 at entry (arg0), a1=?, a2=0x200, a3=sp-336, a4=sp-200.
  The `jal` at 0xbdd4 calls strncpy with a0=sp-196, a1=sp-336, a2=0x80, a3=?.
  The `jal` at 0xbde8 calls copyout with a0=sp-200, a1=[a1+8]:8, a2=[a1+16], a3=?.
  The `beq` branch at 0xbcd0 targets 0xbd30, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xbcdc targets 0xbcf8, is taken when a3(=[a1+3]:1) == at(=0xff), and falls through when a3(=[a1+3]:1) != at(=0xff).
  The `beq` branch at 0xbcec targets 0xbcf8, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == v1(=0x2), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != v1(=0x2).
  The `beq` branch at 0xbd28 targets 0xbd50, is taken when v0(=ret(nic_vertex_info_match)) == 0, and falls through when v0(=ret(nic_vertex_info_match)) != 0.
  The `bne` branch at 0xbd5c targets 0xbd6c, is taken when s3(?) < a2(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s3(?) >= a2(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xbd64 targets 0xbd34 and is always taken.
  The `beq` branch at 0xbd90 targets 0xbdb0, is taken when (a3(?) & 0x1) == 0, and falls through when (a3(?) & 0x1) != 0.
  The `beq` branch at 0xbda8 targets 0xbd30 and is always taken.
  The `beq` branch at 0xbdf0 targets 0xbd9c, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0xbdf8 targets 0xbd30 and is always taken.
  The return at 0xbd48 has v0 = one of ?, 0xa.

- `pcibr_slot_shutdown` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xbe00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xbe00-0xbfec (492 bytes).
  It occupies 492 bytes.
  The `lbu` at 0xbe24 loads 1 byte from a1 (arg1 at entry) +0x3.
  The `lh` at 0xbe48 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `lbu` at 0xbe7c loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xbebc loads 4 bytes from ret(hwgraph_fastinfo_get) +0x0.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xbef0, `lw` at 0xbf20, `lw` at 0xbf68.
  The `lh` at 0xbf3c loads 2 bytes from ret(hwgraph_fastinfo_get) +0x74.
  The `lbu` at 0xbf48 loads 1 byte from ret(hwgraph_fastinfo_get) +0x32.
  The `lbu` at 0xbf4c loads 1 byte from ret(hwgraph_fastinfo_get) +0x31.
  The `lw` at 0xbfcc loads 4 bytes from a1 (arg1 at entry) +0x10.
  The `ld` at 0xbfd0 loads 8 bytes from a1 (arg1 at entry) +0x8.
  The `jal` at 0xbe1c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xbe74 calls pcibr_debug with a0=0x8000, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=ret(hwgraph_fastinfo_get), a5=a1 at entry (arg1).
  The `jal` at 0xbeb8 calls nic_vertex_info_match with a0=[ret(hwgraph_fastinfo_get)], a1=sym(.rodata)+11000, a2=?, a3=0xa.
  The `jal` at 0xbee0 calls mrlock with a0=ret(hwgraph_fastinfo_get)+144, a1=0x2, a2=0x19, a3=?.
  The `jal` at 0xbf04 calls mrunlock with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xbfac calls pcibr_slot_detach with a0=a0 at entry (arg0), a1=?, a2=0x400, a3=sp-200, a4=sp-336, a7=[ret(hwgraph_fastinfo_get)+116]:2.
  The `jal` at 0xbfc0 calls strncpy with a0=sp-332, a1=sp-200, a2=0x80, a3=?.
  The `jal` at 0xbfd4 calls copyout with a0=sp-336, a1=[a1+8]:8, a2=[a1+16], a3=?.
  The `beq` branch at 0xbe34 targets 0xbe90, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xbe40 targets 0xbe58, is taken when a4(=[a1+3]:1) == at(=0xff), and falls through when a4(=[a1+3]:1) != at(=0xff).
  The `beq` branch at 0xbe50 targets 0xbed0, is taken when v0(=[ret(hwgraph_fastinfo_get)+114]:2) == v1(=0x2), and falls through when v0(=[ret(hwgraph_fastinfo_get)+114]:2) != v1(=0x2).
  The `bne` branch at 0xbe88 targets 0xbeb4, is taken when s2(?) < a0(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(?) >= a0(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xbec0 targets 0xbed8, is taken when v0(=ret(nic_vertex_info_match)) == 0, and falls through when v0(=ret(nic_vertex_info_match)) != 0.
  The `beq` branch at 0xbec8 targets 0xbe90 and is always taken.
  The `beq` branch at 0xbed0 targets 0xbe58 and is always taken.
  The `beq` branch at 0xbefc targets 0xbf14, is taken when (v0(?) & 0x4) == 0, and falls through when (v0(?) & 0x4) != 0.
  The `beq` branch at 0xbf0c targets 0xbe90 and is always taken.
  The `beq` branch at 0xbf18 targets 0xbf04, is taken when (v0(?) & 0xf) == 0, and falls through when (v0(?) & 0xf) != 0.
  The `bne` branch at 0xbf28 targets 0xbf3c, is taken when a5(?) < 0x2 (signed), and falls through when a5(?) >= 0x2 (signed).
  The `beq` branch at 0xbf34 targets 0xbfcc and is always taken.
  The `bne` branch at 0xbf40 targets 0xbfa0, is taken when a7(=[ret(hwgraph_fastinfo_get)+116]:2) != 0, and falls through when a7(=[ret(hwgraph_fastinfo_get)+116]:2) == 0.
  The `bne` branch at 0xbf54 targets 0xbf94, is taken when a3(=[ret(hwgraph_fastinfo_get)+50]:1) < v0(=[ret(hwgraph_fastinfo_get)+49]:1) (signed), and falls through when a3(=[ret(hwgraph_fastinfo_get)+50]:1) >= v0(=[ret(hwgraph_fastinfo_get)+49]:1) (signed).
  The `beq` branch at 0xbf5c targets 0xbf80, is taken when v0(?) == s2(?), and falls through when v0(?) != s2(?).
  The `beq` branch at 0xbf70 targets 0xbf84, is taken when (t1(?) & 0x10) == 0, and falls through when (t1(?) & 0x10) != 0.
  The `beq` branch at 0xbf78 targets 0xbf98 and is always taken.
  The `beq` branch at 0xbf8c targets 0xbf5c, is taken when a3(=[ret(hwgraph_fastinfo_get)+50]:1) >= v0(?) (signed), and falls through when a3(=[ret(hwgraph_fastinfo_get)+50]:1) < v0(?) (signed).
  The `bne` branch at 0xbf98 targets 0xbf04, is taken when a1(?) != 0, and falls through when a1(?) == 0.
  The `beq` branch at 0xbfdc targets 0xbf04, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0xbfe4 targets 0xbe90 and is always taken.
  The return at 0xbeac has v0 = one of 0x8, 0xa, 0x9, ?, 0xe.

- `pcibr_slot_func_info_return` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xbfec (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xbfec-0xc170 (388 bytes).
  It occupies 388 bytes.
  The `ld` at 0xc000 loads 8 bytes from (a0 + (a1 << 0x3)) +0x0.
  3 such `sw` accesses store 4 bytes to a2 (arg2 at entry) +0x0, including `sw` at 0xc014, `sw` at 0xc020, `sw` at 0xc048.
  2 such `lw` accesses load 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x8, including `lw` at 0xc02c, `lw` at 0xc034.
  The `lw` at 0xc040 loads 4 bytes from a2 (arg2 at entry) +0x0.
  The `lbu` at 0xc04c loads 1 byte from [(a0 + (a1 << 0x3))]:8 +0x10.
  The `sb` at 0xc050 stores 1 byte to a2 (arg2 at entry) +0x104.
  The `lbu` at 0xc054 loads 1 byte from [(a0 + (a1 << 0x3))]:8 +0x11.
  The `sb` at 0xc058 stores 1 byte to a2 (arg2 at entry) +0x105.
  The `lbu` at 0xc05c loads 1 byte from [(a0 + (a1 << 0x3))]:8 +0x12.
  The `sb` at 0xc064 stores 1 byte to a2 (arg2 at entry) +0x106.
  The `lw` at 0xc070 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x1c.
  The `ld` at 0xc074 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x30.
  The `sd` at 0xc078 stores 8 bytes to a2 (arg2 at entry) +0x208.
  The `ld` at 0xc07c loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x38.
  The `sd` at 0xc080 stores 8 bytes to a2 (arg2 at entry) +0x210.
  The `ld` at 0xc084 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x40.
  The `sd` at 0xc088 stores 8 bytes to a2 (arg2 at entry) +0x218.
  The `lw` at 0xc08c loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x14.
  The `sw` at 0xc090 stores 4 bytes to a2 (arg2 at entry) +0x220.
  The `lw` at 0xc094 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x18.
  The `sw` at 0xc09c stores 4 bytes to a2 (arg2 at entry) +0x224.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xc0bc, `ld` at 0xc0c4, `ld` at 0xc0e8.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0xc0c0, `sd` at 0xc0c8.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xc0cc, `lw` at 0xc128, `lw` at 0xc148.
  The `ld` at 0xc100 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x1a0.
  The `sw` at 0xc104 stores 4 bytes to a2 (arg2 at entry) +0x2e8.
  The `ld` at 0xc108 loads 8 bytes from [(a0 + (a1 << 0x3))]:8 +0x1a8.
  The `sw` at 0xc110 stores 4 bytes to a2 (arg2 at entry) +0x2ec.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0xc12c, `sw` at 0xc150.
  The `lw` at 0xc158 loads 4 bytes from [(a0 + (a1 << 0x3))]:8 +0x218.
  The `sw` at 0xc15c stores 4 bytes to a2 (arg2 at entry) +0x300.
  The `jal` at 0xc028 calls vertex_to_name with a0=[[(a0 + (a1 << 0x3))]:8+8], a1=a2+4, a2=0x100, a3=a3 at entry (arg3).
  The `jal` at 0xc030 calls is_sys_critical_vertex with a0=[[(a0 + (a1 << 0x3))]:8+8], a1=?, a2=?, a3=?.
  The `jal` at 0xc06c calls vertex_to_name with a0=[[(a0 + (a1 << 0x3))]:8+28], a1=a2+263, a2=0x100, a3=?.
  The `jal` at 0xc0e4 calls sprintf with a0=?, a1=sym(.rodata)+11000, a2=?, a3=?.
  The `beq` branch at 0xc010 targets 0xc160, is taken when s0(=[(a0 + (a1 << 0x3))]:8) == 0, and falls through when s0(=[(a0 + (a1 << 0x3))]:8) != 0.
  The `beq` branch at 0xc038 targets 0xc04c, is taken when v0(=ret(is_sys_critical_vertex)) == 0, and falls through when v0(=ret(is_sys_critical_vertex)) != 0.
  The `bne` branch at 0xc0f4 targets 0xc0a4, is taken when s2(?) < 0x6 (signed), and falls through when s2(?) >= 0x6 (signed).
  The `beq` branch at 0xc130 targets 0xc154, is taken when a1(?) >= 0x4 (signed), and falls through when a1(?) < 0x4 (signed).
  The `bne` branch at 0xc14c targets 0xc114, is taken when a1(?) < 0x4 (signed), and falls through when a1(?) >= 0x4 (signed).
  The return at 0xc168 has v0 = one of ?, ret(sprintf).

- `pcibr_slot_info_return` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xc170 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xc170-0xc3c0 (592 bytes).
  It occupies 592 bytes.
  The `ld` at 0xc188 loads 8 bytes from a0 (arg0 at entry) +0x8.
  The `lh` at 0xc1d4 loads 2 bytes from a0 (arg0 at entry) +0x74.
  The `sh` at 0xc1d8 stores 2 bytes to ret(kmem_zalloc) +0x2.
  The `lh` at 0xc1e0 loads 2 bytes from a0 (arg0 at entry) +0x72.
  The `sh` at 0xc1e8 stores 2 bytes to ret(kmem_zalloc) +0x0.
  The `lw` at 0xc1ec loads 4 bytes from (a0 + (a1 << 0x7)) +0x108.
  The `sw` at 0xc1f0 stores 4 bytes to ret(kmem_zalloc) +0x4.
  The `lbu` at 0xc1f4 loads 1 byte from (a0 + (a1 << 0x7)) +0x10c.
  The `sb` at 0xc1fc stores 1 byte to ret(kmem_zalloc) +0x8.
  2 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x110, including `lw` at 0xc208, `lw` at 0xc224.
  The `lw` at 0xc20c loads 4 bytes from (a0 + (a1 << 0x7)) +0x114.
  2 such `sw` accesses store 4 bytes to ret(kmem_zalloc) +0x110, including `sw` at 0xc210, `sw` at 0xc238.
  The `lw` at 0xc218 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `sw` at 0xc21c stores 4 bytes to ret(kmem_zalloc) +0x114.
  The `lw` at 0xc230 loads 4 bytes from ret(kmem_zalloc) +0x110.
  3 such `lw` accesses load 4 bytes from (a0 + (a1 << 0x7)) +0x118, including `lw` at 0xc23c, `lw` at 0xc244, `lw` at 0xc27c.
  The `sw` at 0xc240 stores 4 bytes to ret(kmem_zalloc) +0x118.
  The `ld` at 0xc270 loads 8 bytes from (a0 + (a1 << 0x7)) +0x120.
  The `lw` at 0xc290 loads 4 bytes from (a0 + (a1 << 0x7)) +0x128.
  The `ld` at 0xc2b4 loads 8 bytes from (sym(pci_space) + ([(a0 + (a1 << 0x7))+296] << 0x3)) +0x0.
  The `ld` at 0xc2b8 loads 8 bytes from (a0 + (a1 << 0x7)) +0x130.
  The `sd` at 0xc2bc stores 8 bytes to ret(kmem_zalloc) +0x130.
  The `ld` at 0xc2c0 loads 8 bytes from (a0 + (a1 << 0x7)) +0x140.
  The `sd` at 0xc2c4 stores 8 bytes to ret(kmem_zalloc) +0x138.
  The `lw` at 0xc2c8 loads 4 bytes from (a0 + (a1 << 0x7)) +0x14c.
  The `sw` at 0xc2cc stores 4 bytes to ret(kmem_zalloc) +0x140.
  The `lw` at 0xc2d0 loads 4 bytes from (a0 + (a1 << 0x7)) +0x150.
  The `sw` at 0xc2d4 stores 4 bytes to ret(kmem_zalloc) +0x144.
  The `lw` at 0xc2d8 loads 4 bytes from (a0 + (a1 << 0x7)) +0x154.
  The `sw` at 0xc2dc stores 4 bytes to ret(kmem_zalloc) +0x148.
  The `ld` at 0xc2e0 loads 8 bytes from (a0 + (a1 << 0x7)) +0x158.
  The `sd` at 0xc2e4 stores 8 bytes to ret(kmem_zalloc) +0x150.
  The `lw` at 0xc2e8 loads 4 bytes from (a0 + (a1 << 0x7)) +0x160.
  The `sw` at 0xc2ec stores 4 bytes to ret(kmem_zalloc) +0x158.
  The `ld` at 0xc2f0 loads 8 bytes from (a0 + (a1 << 0x7)) +0x168.
  The `sd` at 0xc2f4 stores 8 bytes to ret(kmem_zalloc) +0x160.
  The `lw` at 0xc2f8 loads 4 bytes from (a0 + (a1 << 0x7)) +0x170.
  The `sw` at 0xc2fc stores 4 bytes to ret(kmem_zalloc) +0x168.
  The `lw` at 0xc300 loads 4 bytes from (a0 + (a1 << 0x7)) +0x174.
  The `sw` at 0xc304 stores 4 bytes to ret(kmem_zalloc) +0x16c.
  The `ld` at 0xc308 loads 8 bytes from (a0 + (a1 << 0x7)) +0x178.
  The `sd` at 0xc30c stores 8 bytes to ret(kmem_zalloc) +0x170.
  The `lw` at 0xc314 loads 4 bytes from (a0 + (a1 << 0x7)) +0x180.
  The `sw` at 0xc31c stores 4 bytes to ret(kmem_zalloc) +0x178.
  The `lw` at 0xc320 loads 4 bytes from (a0 + (a1 << 0x4)) +0x570.
  The `sw` at 0xc324 stores 4 bytes to ret(kmem_zalloc) +0x17c.
  The `lw` at 0xc328 loads 4 bytes from (a0 + (a1 << 0x4)) +0x574.
  The `sw` at 0xc32c stores 4 bytes to ret(kmem_zalloc) +0x180.
  The `lw` at 0xc330 loads 4 bytes from (a0 + (a1 << 0x4)) +0x578.
  The `sw` at 0xc334 stores 4 bytes to ret(kmem_zalloc) +0x184.
  The `lw` at 0xc33c loads 4 bytes from (a0 + (a1 << 0x4)) +0x57c.
  The `sw` at 0xc344 stores 4 bytes to ret(kmem_zalloc) +0x188.
  The `lw` at 0xc34c loads 4 bytes from (a0 + (a1 << 0x2)) +0x530.
  The `sw` at 0xc358 stores 4 bytes to ret(kmem_zalloc) +0x18c.
  The `sd` at 0xc360 stores 8 bytes to ret(kmem_zalloc) +0x190.
  The `sd` at 0xc36c stores 8 bytes to ret(kmem_zalloc) +0x198.
  The `sd` at 0xc380 stores 8 bytes to ret(kmem_zalloc) +0x1a0.
  The `sd` at 0xc39c stores 8 bytes to ret(kmem_zalloc) +0x1a8.
  The `jal` at 0xc19c calls kmem_zalloc with a0=0x19f0, a1=0x0, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc204 calls vertex_to_name with a0=[(a0 + (a1 << 0x7))+272], a1=ret(kmem_zalloc)+16, a2=0x100, a3=?.
  The `jal` at 0xc214 calls pcibr_widget_to_bus with a0=[a0+4], a1=?, a2=?, a3=?.
  The `jal` at 0xc220 calls is_sys_critical_vertex with a0=[(a0 + (a1 << 0x7))+272], a1=?, a2=?, a3=?.
  The `jal` at 0xc274 calls pcibr_slot_func_info_return with a0=[(a0 + (a1 << 0x7))+288]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xc2b0 calls sprintf with a0=ret(kmem_zalloc)+284, a1=sym(.rodata)+11000, a2=[(sym(pci_space) + ([(a0 + (a1 << 0x7))+296] << 0x3))]:8, a3=([(a0 + (a1 << 0x7))+296] << 0x3).
  The `jal` at 0xc354 calls pcireg_rrb_get with a0=[a0+8]:8, a1=?, a2=?, a3=?, a4=[(a0 + (a1 << 0x2))+1328], a5=[(a0 + (a1 << 0x4))+1404], a6=[(a0 + (a1 << 0x4))+1400], a7=[(a0 + (a1 << 0x4))+1396].
  The `jal` at 0xc364 calls pcireg_intr_device_get with a0=[a0+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xc370 calls pcireg_intr_enable_get with a0=[a0+8]:8, a1=?, a2=?, a3=?.
  The `jal` at 0xc384 calls pcireg_intr_addr_get with a0=[a0+8]:8, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xc398 calls copyout with a0=ret(kmem_zalloc), a1=a2 at entry (arg2), a2=0x19f0, a3=?.
  The `jal` at 0xc3b0 calls kmem_free with a0=ret(kmem_zalloc), a1=0x19f0, a2=?, a3=?.
  The `bne` branch at 0xc1ac targets 0xc1d4, is taken when v0(=ret(kmem_zalloc)) != 0, and falls through when v0(=ret(kmem_zalloc)) == 0.
  The `beq` branch at 0xc228 targets 0xc23c, is taken when v0(=ret(is_sys_critical_vertex)) == 0, and falls through when v0(=ret(is_sys_critical_vertex)) != 0.
  The `blez` branch at 0xc248 targets 0xc290, is taken when at(=[(a0 + (a1 << 0x7))+280]) <= 0 (signed), and falls through when at(=[(a0 + (a1 << 0x7))+280]) > 0 (signed).
  The `bne` branch at 0xc288 targets 0xc258, is taken when s2(?) < a3(=[(a0 + (a1 << 0x7))+280]) (signed), and falls through when s2(?) >= a3(=[(a0 + (a1 << 0x7))+280]) (signed).
  The `beq` branch at 0xc3a0 targets 0xc3b0, is taken when v0(=ret(copyout)) == 0, and falls through when v0(=ret(copyout)) != 0.
  The `beq` branch at 0xc3a8 targets 0xc1b4 and is always taken.
  The `beq` branch at 0xc3b8 targets 0xc1b4 and is always taken.
  The return at 0xc1cc has v0 = one of 0x0, 0xc, 0xe.

- `pcibr_slot_query` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xc3c0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xc3c0-0xc5a8 (488 bytes).
  It occupies 488 bytes.
  The `lw` at 0xc3e4 loads 4 bytes from a1 (arg1 at entry) +0x10.
  The `ld` at 0xc3e8 loads 8 bytes from a1 (arg1 at entry) +0x8.
  The `lbu` at 0xc3f0 loads 1 byte from a1 (arg1 at entry) +0x3.
  The `lh` at 0xc40c loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  3 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0xc440, `lbu` at 0xc504, `lbu` at 0xc56c.
  The `lw` at 0xc488 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x0.
  The `lbu` at 0xc508 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  The `jal` at 0xc3dc calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc438 calls pcibr_debug with a0=0x8000, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=ret(hwgraph_fastinfo_get), a5=a1 at entry (arg1).
  The `jal` at 0xc48c calls nic_vertex_info_match with a0=[ret(hwgraph_fastinfo_get)], a1=sym(.rodata)+11000, a2=?, a3=?.
  The `jal` at 0xc4d8 calls mrlock with a0=ret(hwgraph_fastinfo_get)+144, a1=0x1, a2=0x19, a3=?.
  The `jal` at 0xc4e8 calls pcibr_slot_info_return with a0=ret(hwgraph_fastinfo_get), a1=?, a2=[a1+8]:8, a3=?.
  The `jal` at 0xc4f4 calls mrunlock with a0=ret(hwgraph_fastinfo_get)+144, a1=?, a2=?, a3=?.
  The `jal` at 0xc530 calls mrlock with a0=ret(hwgraph_fastinfo_get)+144, a1=0x1, a2=0x19, a3=?.
  The `jal` at 0xc540 calls pcibr_slot_info_return with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xc550 calls mrunlock with a0=ret(hwgraph_fastinfo_get)+144, a1=?, a2=?, a3=?.
  The `beq` branch at 0xc3f8 targets 0xc460, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xc404 targets 0xc4a4, is taken when a0(=0xff) == a3(=[a1+3]:1), and falls through when a0(=0xff) != a3(=[a1+3]:1).
  The `beq` branch at 0xc414 targets 0xc4ac, is taken when at(=[ret(hwgraph_fastinfo_get)+114]:2) == v0(=0x2), and falls through when at(=[ret(hwgraph_fastinfo_get)+114]:2) != v0(=0x2).
  The `bne` branch at 0xc450 targets 0xc484, is taken when s1(?) < a3(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s1(?) >= a3(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xc458 targets 0xc488, is taken when s2(=0xff) == s1(?), and falls through when s2(=0xff) != s1(?).
  The `beq` branch at 0xc494 targets 0xc4b4, is taken when v0(=ret(nic_vertex_info_match)) == 0, and falls through when v0(=ret(nic_vertex_info_match)) != 0.
  The `beq` branch at 0xc49c targets 0xc464 and is always taken.
  The `beq` branch at 0xc4a4 targets 0xc41c and is always taken.
  The `beq` branch at 0xc4ac targets 0xc41c and is always taken.
  The `beq` branch at 0xc4b8 targets 0xc504, is taken when s2(=0xff) == s1(?), and falls through when s2(=0xff) != s1(?).
  The `beq` branch at 0xc4c0 targets 0xc4d0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xc4c8 targets 0xc460 and is always taken.
  The `beq` branch at 0xc4fc targets 0xc460 and is always taken.
  The `beq` branch at 0xc514 targets 0xc5a0, is taken when s2(=[ret(hwgraph_fastinfo_get)+56]:1) >= a2(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(=[ret(hwgraph_fastinfo_get)+56]:1) < a2(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `bne` branch at 0xc524 targets 0xc598, is taken when s3(?) < 0x19f0 (unsigned), and falls through when s3(?) >= 0x19f0 (unsigned).
  The `beq` branch at 0xc55c targets 0xc56c, is taken when v0(=ret(pcibr_slot_info_return)) == 0, and falls through when v0(=ret(pcibr_slot_info_return)) != 0.
  The `beq` branch at 0xc564 targets 0xc460 and is always taken.
  The `bne` branch at 0xc588 targets 0xc520, is taken when s2(?) < t8(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(?) >= t8(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xc590 targets 0xc5a0 and is always taken.
  The `beq` branch at 0xc598 targets 0xc460 and is always taken.
  The `beq` branch at 0xc5a0 targets 0xc460 and is always taken.
  The return at 0xc47c has v0 = one of ?, 0x9.

- `pcibr_slot_info_init` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xc5a8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xc5a8-0xd0dc (2868 bytes).
  It occupies 2868 bytes.
  The `lbu` at 0xc5e0 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `ld` at 0xc5f0 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `lw` at 0xc600 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x108.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xc68c, `lw` at 0xc790, `lw` at 0xce34.
  4 such `sw` accesses store 4 bytes to ?, including `sw` at 0xc694, `sw` at 0xc7f4, `sw` at 0xc9c8.
  6 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0xc6b8, `lh` at 0xc8a0, `lh` at 0xc95c.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xc7e8, `sd` at 0xc9bc, `sd` at 0xc9c0.
  5 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x74, including `lh` at 0xc904, `lh` at 0xc92c, `lh` at 0xcdc0.
  The `sd` at 0xcc60 stores 8 bytes to ret(pcibr_device_info_new) +0x220.
  The `lw` at 0xcc64 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x510.
  The `sw` at 0xcc6c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x510.
  The `ld` at 0xcc70 loads 8 bytes from ret(pcibr_device_info_new) +0x220.
  The `lw` at 0xcc74 loads 4 bytes from [ret(pcibr_device_info_new)+544]:8 +0x4.
  The `lw` at 0xcc8c loads 4 bytes from ret(hwgraph_fastinfo_get) +0x514.
  The `lw` at 0xcc90 loads 4 bytes from table(sym(max_splittrans_to_numbuf)) +0x0.
  The `sw` at 0xcc98 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x514.
  3 such `lw` accesses load 4 bytes from ret(hwgraph_fastinfo_get) +0x880, including `lw` at 0xcd38, `lw` at 0xcd64, `lw` at 0xd054.
  The `lbu` at 0xcd40 loads 1 byte from ret(hwgraph_fastinfo_get) +0x28.
  2 such `sw` accesses store 4 bytes to ret(hwgraph_fastinfo_get) +0x880, including `sw` at 0xcd70, `sw` at 0xd060.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x10, including `ld` at 0xd080, `ld` at 0xd0b0.
  The `jal` at 0xc5c8 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xc63c calls pcibr_is_slot_sys_critical with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x0, a3=?.
  The `jal` at 0xc65c calls pcibr_slot_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=0x0, a3=?.
  The `jal` at 0xc670 calls pcibr_probe_slot with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=ret(pcibr_slot_config_addr), a2=sp-608, a3=?.
  The `jal` at 0xc6d8 calls pcibr_debug with a0=0x80, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=?.
  The `jal` at 0xc6f4 calls do_pcibr_config_get with a0=ret(pcibr_slot_config_addr), a1=0xe, a2=0x1, a3=0xffff.
  The `jal` at 0xc770 calls pcibr_func_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xc780 calls pcibr_probe_slot with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=ret(pcibr_func_config_addr), a2=?, a3=?.
  The `jal` at 0xc7b8 calls pcibr_slot_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=0x0, a3=?.
  The `jal` at 0xc7d4 calls kmem_zalloc with a0=?, a1=0x0, a2=?, a3=?.
  The `jal` at 0xc8c4 calls pcibr_debug with a0=0x400, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=?.
  The `jal` at 0xc8e0 calls do_pcibr_config_get with a0=?, a1=0xd, a2=0x1, a3=?.
  The `jal` at 0xc8f0 calls pcireg_device_get with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xc91c calls do_pcibr_config_get with a0=?, a1=0xc, a2=0x1, a3=?.
  The `jal` at 0xc940 calls pcibr_find_capability with a0=?, a1=0x7, a2=?, a3=?.
  The `jal` at 0xc984 calls pcibr_debug with a0=0x400, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=ret(pcibr_find_capability).
  The `jal` at 0xc9f8 calls do_pcibr_config_set with a0=?, a1=?, a2=0x4, a3=0x0, a6=0x4.
  The `jal` at 0xca34 calls sprintf with a0=sp-568, a1=sym(.rodata)+11000, a2=?, a3=?.
  The `jal` at 0xca4c calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=sp-568.
  The `jal` at 0xca90 calls do_pcibr_config_get with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xcb28 calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=one of 0x2, 0x4, 0x5, a3=?, a5=0x0.
  The `jal` at 0xcbb4 calls do_pcibr_config_set with a0=?, a1=?, a2=0x4, a3=-0x1.
  The `jal` at 0xcbc4 calls do_pcibr_config_get with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xcc50 calls pcibr_device_info_new with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xcca0 calls pciio_device_info_register with a0=a0 at entry (arg0), a1=ret(pcibr_device_info_new), a2=?, a3=?.
  The `jal` at 0xccb4 calls do_pcibr_config_get with a0=?, a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xcd5c calls pciio_device_win_populate with a0=?, a1=([ret(hwgraph_fastinfo_get)+40]:1 << 0x18), a2=0x1000000, a3=?.
  The `jal` at 0xcdb8 calls do_pcibr_config_get with a0=?, a1=0x3e, a2=0x1, a3=?.
  The `jal` at 0xce3c calls pcibr_func_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xce5c calls do_pcibr_config_get with a0=ret(pcibr_func_config_addr), a1=0xe, a2=0x1, a3=?.
  The `jal` at 0xced8 calls do_pcibr_config_get with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xcefc calls do_pcibr_config_set with a0=?, a1=0xc, a2=0x1, a3=0x20.
  The `jal` at 0xcf30 calls pcibr_debug with a0=0x400, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=?.
  The `jal` at 0xcf54 calls do_pcibr_config_set with a0=?, a1=0xd, a2=0x1, a3=?, a6=one of 0x8, 0x10, 0x18, 0x20, a7=0x5.
  The `jal` at 0xcf8c calls pcibr_debug with a0=0x400, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=?.
  The `jal` at 0xd04c calls pciio_device_win_populate with a0=?, a1=([ret(hwgraph_fastinfo_get)+40]:1 << 0x18), a2=0x1000000, a3=0x10a9.
  The `jal` at 0xd090 calls cmn_err with a0=0x4, a1=sym(.rodata)+11000, a2=[ret(hwgraph_fastinfo_get)+16]:8, a3=a1 at entry (arg1).
  The `jal` at 0xd0b4 calls cmn_err with a0=0x4, a1=sym(.rodata)+11000, a2=[ret(hwgraph_fastinfo_get)+16]:8, a3=a1 at entry (arg1).
  The `jal` at 0xd0cc calls pcibr_device_info_new with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=0xff, a3=-0x1, a4=-0x1.
  The `beq` branch at 0xc5d8 targets 0xc60c, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xc5ec targets 0xc630, is taken when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xc604 targets 0xc638, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) != 0.
  The `beq` branch at 0xc630 targets 0xc60c and is always taken.
  The `beq` branch at 0xc644 targets 0xc654, is taken when v0(=ret(pcibr_is_slot_sys_critical)) == 0, and falls through when v0(=ret(pcibr_is_slot_sys_critical)) != 0.
  The `beq` branch at 0xc64c targets 0xc60c and is always taken.
  The `beq` branch at 0xc678 targets 0xc68c, is taken when v0(=ret(pcibr_probe_slot)) == 0, and falls through when v0(=ret(pcibr_probe_slot)) != 0.
  The `beq` branch at 0xc684 targets 0xc60c and is always taken.
  The `beq` branch at 0xc6b0 targets 0xce90, is taken when v1(=0xff) == s0(=a1), and falls through when v1(=0xff) != s0(=a1).
  The `beq` branch at 0xc6c0 targets 0xcec0, is taken when a3(=[ret(hwgraph_fastinfo_get)+114]:2) == a4(=0x2), and falls through when a3(=[ret(hwgraph_fastinfo_get)+114]:2) != a4(=0x2).
  The `beq` branch at 0xc6e8 targets 0xce78, is taken when a3(=0xffff) == a4(?), and falls through when a3(=0xffff) != a4(?).
  The `beq` branch at 0xc70c targets 0xce98, is taken when (a5(=(ret(do_pcibr_config_get) << 0x0)) & 0x80) == 0, and falls through when (a5(=(ret(do_pcibr_config_get) << 0x0)) & 0x80) != 0.
  The `beq` branch at 0xc72c targets 0xc750 and is always taken.
  The `beq` branch at 0xc748 targets 0xc7b0, is taken when s2(?) >= 0x8 (signed), and falls through when s2(?) < 0x8 (signed).
  The `bne` branch at 0xc788 targets 0xc734, is taken when v0(=ret(pcibr_probe_slot)) != 0, and falls through when v0(=ret(pcibr_probe_slot)) == 0.
  The `beq` branch at 0xc79c targets 0xceb0, is taken when t8(?) == t9(=0xffff), and falls through when t8(?) != t9(=0xffff).
  The `beq` branch at 0xc7a8 targets 0xc740 and is always taken.
  The `blez` branch at 0xc7f0 targets 0xccfc, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0xc818 targets 0xc844 and is always taken.
  The `bne` branch at 0xc828 targets 0xc9d0, is taken when a6(?) != a7(=0x3), and falls through when a6(?) == a7(=0x3).
  The `beq` branch at 0xc83c targets 0xccfc, is taken when s2(?) >= t0(?) (signed), and falls through when s2(?) < t0(?) (signed).
  The `beq` branch at 0xc844 targets 0xc86c, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xc85c targets 0xce18, is taken when (s3(?) & t8(?)) == 0, and falls through when (s3(?) & t8(?)) != 0.
  The `bne` branch at 0xc864 targets 0xc834, is taken when s3(?) != 0, and falls through when s3(?) == 0.
  The `beq` branch at 0xc874 targets 0xcd14, is taken when (t9(?) & 0x7f) == 0, and falls through when (t9(?) & 0x7f) != 0.
  The `bne` branch at 0xc884 targets 0xd07c, is taken when ra(=0x1) != at(?), and falls through when ra(=0x1) == at(?).
  The `beq` branch at 0xc898 targets 0xcd20, is taken when v1(=0xff) == s0(=a1), and falls through when v1(=0xff) != s0(=a1).
  The `beq` branch at 0xc8a8 targets 0xce10, is taken when a0(=[ret(hwgraph_fastinfo_get)+114]:2) == a1(=0x2), and falls through when a0(=[ret(hwgraph_fastinfo_get)+114]:2) != a1(=0x2).
  The `beq` branch at 0xc8d4 targets 0xcd28, is taken when a2(?) == a3(=0x10a9), and falls through when a2(?) != a3(=0x10a9).
  The `beq` branch at 0xc8fc targets 0xcd74, is taken when a4(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a4(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xc90c targets 0xcc40, is taken when (a5(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a5(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xc924 targets 0xcef4, is taken when v0(=ret(do_pcibr_config_get)) == 0, and falls through when v0(=ret(do_pcibr_config_get)) != 0.
  The `beq` branch at 0xc934 targets 0xcc40, is taken when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xc948 targets 0xd0a0, is taken when v0(=ret(pcibr_find_capability)) == 0, and falls through when v0(=ret(pcibr_find_capability)) != 0.
  The `beq` branch at 0xc954 targets 0xcec8, is taken when t0(=0xff) == s0(=a1), and falls through when t0(=0xff) != s0(=a1).
  The `beq` branch at 0xc964 targets 0xceec, is taken when t1(=[ret(hwgraph_fastinfo_get)+114]:2) == t2(=0x2), and falls through when t1(=[ret(hwgraph_fastinfo_get)+114]:2) != t2(=0x2).
  The `bne` branch at 0xc990 targets 0xc830, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0xc998 targets 0xcc44 and is always taken.
  The `beq` branch at 0xc9c4 targets 0xc820, is taken when a5(?) == a6(=0x10a9), and falls through when a5(?) != a6(=0x10a9).
  The `bne` branch at 0xc9d4 targets 0xca64, is taken when a6(=0x4) != a7(?), and falls through when a6(=0x4) == a7(?).
  The `beq` branch at 0xca00 targets 0xca68 and is always taken.
  The `beq` branch at 0xca5c targets 0xc9a0, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xca80 targets 0xc830, is taken when s6(?) >= a4(?) (signed), and falls through when s6(?) < a4(?) (signed).
  The `beq` branch at 0xcaac targets 0xcb64, is taken when (v0(=ret(do_pcibr_config_get)) & 0x1) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0x1) != 0.
  The `beq` branch at 0xcac4 targets 0xcad4, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xcad8 targets 0xcba8, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xcaf4 targets 0xcbec, is taken when t2(=one of 0x2, 0x4) == t3(=0x4), and falls through when t2(=one of 0x2, 0x4) != t3(=0x4).
  The `beq` branch at 0xcb40 targets 0xca54, is taken when (a5(=[sym(pcibr_debug_mask)]) & 0x800) == 0, and falls through when (a5(=[sym(pcibr_debug_mask)]) & 0x800) != 0.
  The `beq` branch at 0xcb48 targets 0xcc04, is taken when a6(=0xff) == s0(=a1), and falls through when a6(=0xff) != s0(=a1).
  The `bne` branch at 0xcb54 targets 0xca08, is taken when a7(=[ret(hwgraph_fastinfo_get)+114]:2) != t0(=0x2), and falls through when a7(=[ret(hwgraph_fastinfo_get)+114]:2) == t0(=0x2).
  The `beq` branch at 0xcb5c targets 0xca0c and is always taken.
  The `beq` branch at 0xcb84 targets 0xcc18, is taken when (t3(=-0x10) & v0(=ret(do_pcibr_config_get))) == 0, and falls through when (t3(=-0x10) & v0(=ret(do_pcibr_config_get))) != 0.
  The `beq` branch at 0xcb8c targets 0xcc28, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0xcb9c targets 0xcc0c, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xcbe4 targets 0xca54 and is always taken.
  The `beq` branch at 0xcbf4 targets 0xcafc, is taken when v0(=0x2) == v1(?), and falls through when v0(=0x2) != v1(?).
  The `beq` branch at 0xcbfc targets 0xcafc and is always taken.
  The `beq` branch at 0xcc04 targets 0xca0c and is always taken.
  The `beq` branch at 0xcc10 targets 0xced0, is taken when a1(=0x4) == t2(?), and falls through when a1(=0x4) != t2(?).
  The `beq` branch at 0xcc20 targets 0xcad4 and is always taken.
  The `beq` branch at 0xcc38 targets 0xcba8 and is always taken.
  The `beq` branch at 0xcc5c targets 0xcc9c, is taken when s3(?) == 0, and falls through when s3(?) != 0.
  The `beq` branch at 0xcca8 targets 0xce84, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `blez` branch at 0xccc0 targets 0xc834, is taken when t1(?) <= 0 (signed), and falls through when t1(?) > 0 (signed).
  The `beq` branch at 0xccf4 targets 0xca88 and is always taken.
  The `beq` branch at 0xcd0c targets 0xc60c and is always taken.
  The `beq` branch at 0xcd18 targets 0xc894 and is always taken.
  The `beq` branch at 0xcd20 targets 0xc8b0 and is always taken.
  The `bne` branch at 0xcd30 targets 0xc8dc, is taken when ra(?) != at(=0x2), and falls through when ra(?) == at(=0x2).
  The `beq` branch at 0xcd44 targets 0xd044, is taken when (v0(=[ret(hwgraph_fastinfo_get)+2176]) & 0x1) == 0, and falls through when (v0(=[ret(hwgraph_fastinfo_get)+2176]) & 0x1) != 0.
  The `bne` branch at 0xcd50 targets 0xc8d8, is taken when (v0(?) & 0x2) != 0, and falls through when (v0(?) & 0x2) == 0.
  The `beq` branch at 0xcd6c targets 0xc8d8 and is always taken.
  The `bne` branch at 0xcd78 targets 0xc904, is taken when (at(=0x200000) & v0(=ret(pcireg_device_get))) != 0, and falls through when (at(=0x200000) & v0(=ret(pcireg_device_get))) == 0.
  The `bne` branch at 0xcd84 targets 0xcdb4, is taken when v0(?) != v1(=0x10a9), and falls through when v0(?) == v1(=0x10a9).
  The `beq` branch at 0xcd94 targets 0xc904, is taken when a0(?) == a1(=0x3), and falls through when a0(?) != a1(=0x3).
  The `beq` branch at 0xcda0 targets 0xc904, is taken when a2(?) == a3(=0x2), and falls through when a2(?) != a3(=0x2).
  The `beq` branch at 0xcdac targets 0xc904, is taken when a4(?) == a5(=0x5), and falls through when a4(?) != a5(=0x5).
  The `beq` branch at 0xcdc8 targets 0xcfcc, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == a6(=0x7), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != a6(=0x7).
  The `beq` branch at 0xcdd0 targets 0xcffc, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == a7(=0x5), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != a7(=0x5).
  The `beq` branch at 0xcdd8 targets 0xcfac, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == t0(=0x2), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != t0(=0x2).
  The `beq` branch at 0xcde0 targets 0xcfac, is taken when a1(=[ret(hwgraph_fastinfo_get)+116]:2) == t1(=0x3), and falls through when a1(=[ret(hwgraph_fastinfo_get)+116]:2) != t1(=0x3).
  The `beq` branch at 0xcde8 targets 0xd02c, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xcdf4 targets 0xcf40, is taken when t2(=(ret(do_pcibr_config_get) << 0x3)) >= 0x100 (unsigned), and falls through when t2(=(ret(do_pcibr_config_get) << 0x3)) < 0x100 (unsigned).
  The `beq` branch at 0xce08 targets 0xcf48 and is always taken.
  The `beq` branch at 0xce10 targets 0xc8b0 and is always taken.
  The `beq` branch at 0xce70 targets 0xc864 and is always taken.
  The `beq` branch at 0xce7c targets 0xc60c and is always taken.
  The `beq` branch at 0xce88 targets 0xccac and is always taken.
  The `beq` branch at 0xce90 targets 0xc6c8 and is always taken.
  The `beq` branch at 0xcea8 targets 0xc7c8 and is always taken.
  The `beq` branch at 0xceb8 targets 0xc740 and is always taken.
  The `beq` branch at 0xcec0 targets 0xc6c8 and is always taken.
  The `beq` branch at 0xcec8 targets 0xc96c and is always taken.
  The `beq` branch at 0xcee4 targets 0xcc18 and is always taken.
  The `beq` branch at 0xceec targets 0xc96c and is always taken.
  The `beq` branch at 0xcf08 targets 0xcf9c, is taken when a3(=0xff) == s0(=a1), and falls through when a3(=0xff) != s0(=a1).
  The `beq` branch at 0xcf18 targets 0xcfa4, is taken when a4(=[ret(hwgraph_fastinfo_get)+114]:2) == a5(=0x2), and falls through when a4(=[ret(hwgraph_fastinfo_get)+114]:2) != a5(=0x2).
  The `beq` branch at 0xcf38 targets 0xc930 and is always taken.
  The `beq` branch at 0xcf60 targets 0xcfec, is taken when a4(=0xff) == s0(=a1), and falls through when a4(=0xff) != s0(=a1).
  The `beq` branch at 0xcf70 targets 0xcff4, is taken when a5(=[ret(hwgraph_fastinfo_get)+114]:2) == a6(=0x2), and falls through when a5(=[ret(hwgraph_fastinfo_get)+114]:2) != a6(=0x2).
  The `beq` branch at 0xcf94 targets 0xc908 and is always taken.
  The `beq` branch at 0xcf9c targets 0xcf20 and is always taken.
  The `beq` branch at 0xcfa4 targets 0xcf20 and is always taken.
  The `beq` branch at 0xcfb0 targets 0xd064, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xcfbc targets 0xd024, is taken when a3(=(ret(do_pcibr_config_get) << 0x4)) >= 0x100 (unsigned), and falls through when a3(=(ret(do_pcibr_config_get) << 0x4)) < 0x100 (unsigned).
  The `beq` branch at 0xcfc4 targets 0xce00 and is always taken.
  The `beq` branch at 0xcfd0 targets 0xd06c, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xcfdc targets 0xd034, is taken when a4(=(ret(do_pcibr_config_get) << 0x5)) >= 0x100 (unsigned), and falls through when a4(=(ret(do_pcibr_config_get) << 0x5)) < 0x100 (unsigned).
  The `beq` branch at 0xcfe4 targets 0xce00 and is always taken.
  The `beq` branch at 0xcfec targets 0xcf78 and is always taken.
  The `beq` branch at 0xcff4 targets 0xcf78 and is always taken.
  The `beq` branch at 0xd000 targets 0xd074, is taken when a1(=(ret(do_pcibr_config_get) << 0x0)) == 0, and falls through when a1(=(ret(do_pcibr_config_get) << 0x0)) != 0.
  The `beq` branch at 0xd014 targets 0xd03c, is taken when a5(?) >= 0x100 (unsigned), and falls through when a5(?) < 0x100 (unsigned).
  The `beq` branch at 0xd01c targets 0xce00 and is always taken.
  The `beq` branch at 0xd024 targets 0xcf40 and is always taken.
  The `beq` branch at 0xd02c targets 0xcf40 and is always taken.
  The `beq` branch at 0xd034 targets 0xcf40 and is always taken.
  The `beq` branch at 0xd03c targets 0xcf40 and is always taken.
  The `beq` branch at 0xd05c targets 0xcd4c and is always taken.
  The `beq` branch at 0xd064 targets 0xcf40 and is always taken.
  The `beq` branch at 0xd06c targets 0xcf40 and is always taken.
  The `beq` branch at 0xd074 targets 0xcf40 and is always taken.
  The `beq` branch at 0xd098 targets 0xc890 and is always taken.
  The `beq` branch at 0xd0d4 targets 0xc990 and is always taken.
  The return at 0xc628 has v0 = one of 0x0, 0x1, 0x13, 0x16.

- `pcibr_find_capability` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xd0dc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xd0dc-0xd1b4 (216 bytes).
  It occupies 216 bytes.
  The `jal` at 0xd0f8 calls do_pcibr_config_get with a0=a0 at entry (arg0), a1=0x6, a2=0x2, a3=a3 at entry (arg3).
  The `jal` at 0xd11c calls do_pcibr_config_get with a0=a0 at entry (arg0), a1=0x34, a2=0x1, a3=?.
  The `jal` at 0xd144 calls do_pcibr_config_get with a0=a0 at entry (arg0), a1=?, a2=0x1, a3=?.
  The `jal` at 0xd16c calls do_pcibr_config_get with a0=a0 at entry (arg0), a1=?, a2=0x1, a3=?.
  The `beq` branch at 0xd10c targets 0xd1ac, is taken when (v0(=ret(do_pcibr_config_get)) & 0x10) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0x10) != 0.
  The `beq` branch at 0xd12c targets 0xd1a4, is taken when (v0(=ret(do_pcibr_config_get)) & 0xfc) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0xfc) != 0.
  The `beq` branch at 0xd134 targets 0xd168 and is always taken.
  The `beq` branch at 0xd154 targets 0xd1a4, is taken when (v0(=ret(do_pcibr_config_get)) & 0xfc) == 0, and falls through when (v0(=ret(do_pcibr_config_get)) & 0xfc) != 0.
  The `beq` branch at 0xd160 targets 0xd1a4, is taken when s2(?) >= 0x31 (signed), and falls through when s2(?) < 0x31 (signed).
  The `bne` branch at 0xd178 targets 0xd13c, is taken when s3(=a1) != t9(=(ret(do_pcibr_config_get) << 0x0)), and falls through when s3(=a1) == t9(=(ret(do_pcibr_config_get) << 0x0)).
  The `beq` branch at 0xd1a4 targets 0xd188 and is always taken.
  The `beq` branch at 0xd1ac targets 0xd18c and is always taken.
  The return at 0xd19c has v0 = one of ?, 0x0.

- `pcibr_slot_info_free` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xd1b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xd1b4-0xd23c (136 bytes).
  It occupies 136 bytes.
  The `lbu` at 0xd1d4 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xd20c loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `ld` at 0xd22c loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x120.
  The `sw` at 0xd230 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `jal` at 0xd1c4 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd214 calls pcibr_device_info_free with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?, a4=0x16.
  The `jal` at 0xd228 calls kmem_free with a0=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+288]:8, a1=([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280] << 0x3), a2=?, a3=?.
  The `beq` branch at 0xd1cc targets 0xd1e8, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0xd1e0 targets 0xd1fc, is taken when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xd234 targets 0xd1e8 and is always taken.
  The return at 0xd1f4 has v0 = one of 0x0, 0x16.

- `pcibr_slot_pcix_rbar_init` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xd23c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xd23c-0xd5b4 (888 bytes).
  It occupies 888 bytes.
  The `lbu` at 0xd254 loads 1 byte from a0 (arg0 at entry) +0x39.
  The `lw` at 0xd290 loads 4 bytes from (a0 + (a1 << 0x7)) +0x118.
  The `ld` at 0xd29c loads 8 bytes from (a0 + (a1 << 0x7)) +0x120.
  2 such `lh` accesses load 2 bytes from a0 (arg0 at entry) +0x72, including `lh` at 0xd2b4, `lh` at 0xd4d0.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x4, including `lw` at 0xd2d0, `lw` at 0xd2e0, `lw` at 0xd368.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x520, including `lw` at 0xd320, `lw` at 0xd470, `lw` at 0xd500.
  3 such `lw` accesses load 4 bytes from a0 (arg0 at entry) +0x51c, including `lw` at 0xd32c, `lw` at 0xd47c, `lw` at 0xd50c.
  5 such `lw` accesses load 4 bytes from table(sym(max_splittrans_to_numbuf)) +0x0, including `lw` at 0xd34c, `lw` at 0xd358, `lw` at 0xd3e0.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xd388, `ld` at 0xd3a8.
  6 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd39c, `lw` at 0xd3bc, `lw` at 0xd408.
  3 such `lhu` accesses load 2 bytes from ?, including `lhu` at 0xd3b4, `lhu` at 0xd494, `lhu` at 0xd524.
  The `lw` at 0xd3b8 loads 4 bytes from a0 (arg0 at entry) +0x518.
  4 such `sh` accesses store 2 bytes to ?, including `sh` at 0xd468, `sh` at 0xd4b0, `sh` at 0xd4f8.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x520, including `sw` at 0xd484, `sw` at 0xd514.
  2 such `sw` accesses store 4 bytes to a0 (arg0 at entry) +0x51c, including `sw` at 0xd48c, `sw` at 0xd51c.
  The `ld` at 0xd5b0 loads 8 bytes from [(a0 + (a1 << 0x7))+288]:8 +0x0.
  The `jal` at 0xd2d4 calls pcibr_debug with a0=0x40, a1=[a0+4], a2=sym(.rodata)+11000, a3=?.
  The `jal` at 0xd2e4 calls pcibr_debug with a0=0x40, a1=[a0+4], a2=sym(.rodata)+11000, a3=?.
  The `jal` at 0xd354 calls sprintf with a0=sp-352, a1=sym(.rodata)+11000, a2=?, a3=?, a4=entry(sym(max_splittrans_to_numbuf)), a5=entry(sym(max_splittrans_to_numbuf)), a6=[a0+1308], a7=[a0+1312].
  The `jal` at 0xd36c calls pcibr_debug with a0=0x40, a1=[a0+4], a2=sym(.rodata)+11000, a3=sp-352.
  The `beq` branch at 0xd288 targets 0xd584, is taken when a1 >= at(=[a0+57]:1+1) (signed), and falls through when a1 < at(=[a0+57]:1+1) (signed).
  The `blez` branch at 0xd294 targets 0xd594, is taken when s6(=[(a0 + (a1 << 0x7))+280]) <= 0 (signed), and falls through when s6(=[(a0 + (a1 << 0x7))+280]) > 0 (signed).
  The `beq` branch at 0xd2a0 targets 0xd59c, is taken when s3(=[(a0 + (a1 << 0x7))+288]:8) == 0, and falls through when s3(=[(a0 + (a1 << 0x7))+288]:8) != 0.
  The `beq` branch at 0xd2ac targets 0xd58c, is taken when v0(=0xff) == a1, and falls through when v0(=0xff) != a1.
  The `beq` branch at 0xd2bc targets 0xd2c8, is taken when v1(=[a0+114]:2) == a0(=0x2), and falls through when v1(=[a0+114]:2) != a0(=0x2).
  The `blez` branch at 0xd2ec targets 0xd554, is taken when s6(=[(a0 + (a1 << 0x7))+280]) <= 0 (signed), and falls through when s6(=[(a0 + (a1 << 0x7))+280]) > 0 (signed).
  The `beq` branch at 0xd30c targets 0xd5a4 and is always taken.
  The `beq` branch at 0xd380 targets 0xd550, is taken when s2(?) >= s6(=[(a0 + (a1 << 0x7))+280]) (signed), and falls through when s2(?) < s6(=[(a0 + (a1 << 0x7))+280]) (signed).
  The `beq` branch at 0xd394 targets 0xd374, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xd3a0 targets 0xd374, is taken when a5(?) == s5(=-0x1), and falls through when a5(?) != s5(=-0x1).
  The `beq` branch at 0xd3ac targets 0xd374, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `beq` branch at 0xd3cc targets 0xd4e4, is taken when a7(=[a0+1304]) >= 0x64 (signed), and falls through when a7(=[a0+1304]) < 0x64 (signed).
  The `bne` branch at 0xd410 targets 0xd454, is taken when a2(?) < a6(?) (signed), and falls through when a2(?) >= a6(?) (signed).
  The `beq` branch at 0xd424 targets 0xd450, is taken when v0(?) >= 0x7 (signed), and falls through when v0(?) < 0x7 (signed).
  The `bne` branch at 0xd434 targets 0xd454, is taken when a2(?) < t0(?) (signed), and falls through when a2(?) >= t0(?) (signed).
  The `bne` branch at 0xd448 targets 0xd408, is taken when v0(?) < 0x7 (signed), and falls through when v0(?) >= 0x7 (signed).
  The `beq` branch at 0xd4c0 targets 0xd374, is taken when (v0(=[sym(pcibr_debug_mask)]) & 0x40) == 0, and falls through when (v0(=[sym(pcibr_debug_mask)]) & 0x40) != 0.
  The `beq` branch at 0xd4c8 targets 0xd548, is taken when v1(=0xff) == s4(=a1), and falls through when v1(=0xff) != s4(=a1).
  The `bne` branch at 0xd4d4 targets 0xd314, is taken when a0(=[a0+114]:2) != a1(=0x2), and falls through when a0(=[a0+114]:2) == a1(=0x2).
  The `beq` branch at 0xd4dc targets 0xd318 and is always taken.
  The `beq` branch at 0xd540 targets 0xd4b4 and is always taken.
  The `beq` branch at 0xd548 targets 0xd318 and is always taken.
  The `beq` branch at 0xd584 targets 0xd558 and is always taken.
  The `beq` branch at 0xd58c targets 0xd2c8 and is always taken.
  The `beq` branch at 0xd594 targets 0xd558 and is always taken.
  The `beq` branch at 0xd59c targets 0xd558 and is always taken.
  The `beq` branch at 0xd5ac targets 0xd38c and is always taken.
  The return at 0xd57c has v0 = one of 0x0, 0x16.

- `pcibr_slot_addr_space_init` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xd5b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xd5b4-0xdc18 (1636 bytes).
  It occupies 1636 bytes.
  The `lbu` at 0xd5dc loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xd5fc loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x108.
  The `ld` at 0xd604 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `lw` at 0xd644 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `ld` at 0xd66c loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x120.
  5 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0xd6c8, `lh` at 0xd80c, `lh` at 0xd8ec.
  6 such `lw` accesses load 4 bytes from ?, including `lw` at 0xd6fc, `lw` at 0xd788, `lw` at 0xd8a8.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xd704, `sd` at 0xd70c, `sd` at 0xd930.
  6 such `ld` accesses load 8 bytes from ?, including `ld` at 0xd778, `ld` at 0xd890, `ld` at 0xd894.
  The `ld` at 0xd848 loads 8 bytes from table(sym(pci_space)) +0x0.
  The `jal` at 0xd5c8 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xd6b4 calls do_pcibr_config_set with a0=?, a1=0x0, a2=0x4, a3=ret(pcibr_bus_addr_alloc).
  The `jal` at 0xd6f4 calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=?, a5=ret(pcibr_bus_addr_alloc).
  The `jal` at 0xd71c calls do_pcibr_config_get with a0=?, a1=0x4, a2=0x4, a3=?, a4=0x9004.
  The `jal` at 0xd754 calls do_pcibr_config_set with a0=?, a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xd7a4 calls pcibr_func_config_addr with a0=?, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xd7bc calls do_pcibr_config_get with a0=ret(pcibr_func_config_addr), a1=0xe, a2=0x1, a3=?.
  The `jal` at 0xd844 calls sprintf with a0=sp-464, a1=sym(.rodata)+11000, a2=?, a3=?, a5=entry(sym(pci_space)).
  The `jal` at 0xd85c calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=sp-464.
  The `jal` at 0xd910 calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=?, a6=0x4, a7=0xff.
  The `jal` at 0xd92c calls do_pcibr_config_set with a0=?, a1=?, a2=0x4, a3=?.
  The `jal` at 0xd9a0 calls sprintf with a0=sp-464, a1=sym(.rodata)+11000, a2=?, a3=?.
  The `jal` at 0xd9b8 calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=sp-464.
  The `jal` at 0xd9f8 calls sprintf with a0=sp-464, a1=sym(.rodata)+11000, a2=?, a3=?, a7=0xff.
  The `jal` at 0xda10 calls pcibr_debug with a0=0x800, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=sp-464.
  The `jal` at 0xda64 calls do_pcibr_config_set with a0=?, a1=0x0, a2=0x4, a3=0xfffff000, a4=one of 0x3, 0x10a9.
  The `jal` at 0xda74 calls do_pcibr_config_get with a0=?, a1=0x0, a2=0x4, a3=?.
  The `jal` at 0xdaa0 calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x5, a3=0x0.
  The `jal` at 0xdafc calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x2, a3=0x0, a6=0x4, a7=0xff.
  The `jal` at 0xdb28 calls do_pcibr_config_get with a0=?, a1=?, a2=0x4, a3=0xff, a4=[sym(pcibr_debug_mask)], a6=0x4, a7=0xff.
  The `jal` at 0xdb50 calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x5, a3=0x0.
  The `jal` at 0xdba0 calls pcibr_bus_addr_alloc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=0x4, a3=0x0.
  The `beq` branch at 0xd5d4 targets 0xdbc4, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xd5e8 targets 0xd62c, is taken when s3(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s3(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xd608 targets 0xd634, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) != 0.
  The `beq` branch at 0xd62c targets 0xd618 and is always taken.
  The `blez` branch at 0xd664 targets 0xdbd4, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) <= 0 (signed), and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) > 0 (signed).
  The `beq` branch at 0xd670 targets 0xdbcc, is taken when a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+288]:8) == 0, and falls through when a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+288]:8) != 0.
  The `blez` branch at 0xd67c targets 0xdbe0, is taken when a2(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) <= 0 (signed), and falls through when a2(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) > 0 (signed).
  The `beq` branch at 0xd6a0 targets 0xdc0c and is always taken.
  The `beq` branch at 0xd6c0 targets 0xd6d8, is taken when a3(=0xff) == s3(=a1), and falls through when a3(=0xff) != s3(=a1).
  The `beq` branch at 0xd6cc targets 0xd6d8, is taken when a4(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when a4(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xd708 targets 0xdad4, is taken when a3(?) == a4(=0x9004), and falls through when a3(?) != a4(=0x9004).
  The `beq` branch at 0xd738 targets 0xd75c, is taken when (a5(?) & a6(?)) == 0, and falls through when (a5(?) & a6(?)) != 0.
  The `beq` branch at 0xd768 targets 0xdb74, is taken when s4(?) >= a4(?) (signed), and falls through when s4(?) < a4(?) (signed).
  The `beq` branch at 0xd780 targets 0xd75c, is taken when s5(?) == 0, and falls through when s5(?) != 0.
  The `beq` branch at 0xd78c targets 0xd760, is taken when a7(?) == t0(=-0x1), and falls through when a7(?) != t0(=-0x1).
  The `blez` branch at 0xd7e4 targets 0xda20, is taken when t1(=one of 0x2, 0x6) <= 0 (signed), and falls through when t1(=one of 0x2, 0x6) > 0 (signed).
  The `beq` branch at 0xd7f4 targets 0xdbfc and is always taken.
  The `beq` branch at 0xd7fc targets 0xd868, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xd804 targets 0xdabc, is taken when t3(=0xff) == s3(=a1), and falls through when t3(=0xff) != s3(=a1).
  The `beq` branch at 0xd810 targets 0xd81c, is taken when t8(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when t8(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xd884 targets 0xda20, is taken when s0(?) >= a3(?) (signed), and falls through when s0(?) < a3(?) (signed).
  The `beq` branch at 0xd8ac targets 0xd864, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xd8b8 targets 0xd7fc, is taken when a6(?) >= s1(?) (unsigned), and falls through when a6(?) < s1(?) (unsigned).
  The `beq` branch at 0xd8d4 targets 0xdaec, is taken when s2(?) == s7(=0x2), and falls through when s2(?) != s7(=0x2).
  The `beq` branch at 0xd8dc targets 0xdb20, is taken when s2(?) == a6(=0x4), and falls through when s2(?) != a6(=0x4).
  The `beq` branch at 0xd8e4 targets 0xd8fc, is taken when a7(=0xff) == s3(=a1), and falls through when a7(=0xff) != s3(=a1).
  The `beq` branch at 0xd8f0 targets 0xd8fc, is taken when t0(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when t0(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xd958 targets 0xd864, is taken when (a6(=[sym(pcibr_debug_mask)]) & 0x800) == 0, and falls through when (a6(=[sym(pcibr_debug_mask)]) & 0x800) != 0.
  The `bne` branch at 0xd960 targets 0xd9c8, is taken when a2(?) != 0, and falls through when a2(?) == 0.
  The `beq` branch at 0xd968 targets 0xdac4, is taken when a7(=0xff) == s3(=a1), and falls through when a7(=0xff) != s3(=a1).
  The `beq` branch at 0xd974 targets 0xd980, is taken when t0(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when t0(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xd9c0 targets 0xd868 and is always taken.
  The `beq` branch at 0xd9c8 targets 0xdacc, is taken when a3(=0xff) == s3(=a1), and falls through when a3(=0xff) != s3(=a1).
  The `beq` branch at 0xd9d4 targets 0xd9e0, is taken when a4(=[ret(hwgraph_fastinfo_get)+114]:2) == s7(=0x2), and falls through when a4(=[ret(hwgraph_fastinfo_get)+114]:2) != s7(=0x2).
  The `beq` branch at 0xda18 targets 0xd868 and is always taken.
  The `bne` branch at 0xda38 targets 0xda4c, is taken when a3(?) != a4(=0x10a9), and falls through when a3(?) == a4(=0x10a9).
  The `beq` branch at 0xda48 targets 0xd6fc, is taken when a3(?) == a4(=0x3), and falls through when a3(?) != a4(=0x3).
  The `beq` branch at 0xda80 targets 0xd6fc, is taken when (s0(=0xfffff000) & v0(=ret(do_pcibr_config_get))) == 0, and falls through when (s0(=0xfffff000) & v0(=ret(do_pcibr_config_get))) != 0.
  The `bne` branch at 0xdaa8 targets 0xd6a8, is taken when v0(=ret(pcibr_bus_addr_alloc)) != 0, and falls through when v0(=ret(pcibr_bus_addr_alloc)) == 0.
  The `beq` branch at 0xdab4 targets 0xd6fc and is always taken.
  The `beq` branch at 0xdabc targets 0xd81c and is always taken.
  The `beq` branch at 0xdac4 targets 0xd980 and is always taken.
  The `beq` branch at 0xdacc targets 0xd9e0 and is always taken.
  The `bne` branch at 0xdadc targets 0xd710, is taken when t9(?) != ra(=0x1160), and falls through when t9(?) == ra(=0x1160).
  The `beq` branch at 0xdae4 targets 0xd718 and is always taken.
  The `beq` branch at 0xdb18 targets 0xd918 and is always taken.
  The `beq` branch at 0xdb40 targets 0xdb98, is taken when s7(=0x2) == a6(?), and falls through when s7(=0x2) != a6(?).
  The `beq` branch at 0xdb6c targets 0xd918 and is always taken.
  The `beq` branch at 0xdb90 targets 0xd614 and is always taken.
  The `beq` branch at 0xdbbc targets 0xd918 and is always taken.
  The `beq` branch at 0xdbc4 targets 0xd618 and is always taken.
  The `beq` branch at 0xdbcc targets 0xd614 and is always taken.
  The `beq` branch at 0xdbd8 targets 0xd614 and is always taken.
  The `beq` branch at 0xdbf4 targets 0xdb74 and is always taken.
  The `beq` branch at 0xdc04 targets 0xd890 and is always taken.
  The `beq` branch at 0xdc10 targets 0xd774 and is always taken.
  The return at 0xd624 has v0 = one of ?, 0x16.

- `pcibr_slot_device_init` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xdc18 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xdc18-0xdd0c (244 bytes).
  It occupies 244 bytes.
  The `lbu` at 0xdc40 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lh` at 0xdc78 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `sd` at 0xdcac stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x140.
  The `lw` at 0xdce4 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x78.
  The `jal` at 0xdc2c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xdc70 calls pcireg_device_get with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xdcb0 calls pcireg_device_set with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?, a7=0x8000000.
  The `jal` at 0xdcd0 calls pcibr_debug with a0=0x4000000, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=a1 at entry (arg1), a5=sym(device_bits).
  The `beq` branch at 0xdc38 targets 0xdc54, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `bne` branch at 0xdc4c targets 0xdc6c, is taken when s1(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s1(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xdc90 targets 0xdce4, is taken when v1(=[ret(hwgraph_fastinfo_get)+114]:2) == a1(=0x2), and falls through when v1(=[ret(hwgraph_fastinfo_get)+114]:2) != a1(=0x2).
  The `beq` branch at 0xdcdc targets 0xdc54 and is always taken.
  The `beq` branch at 0xdcfc targets 0xdc98, is taken when (a5(?) & 0x2) == 0, and falls through when (a5(?) & 0x2) != 0.
  The `beq` branch at 0xdd04 targets 0xdc9c and is always taken.
  The return at 0xdc64 has v0 = one of 0x0, 0x16.

- `pcibr_slot_guest_info_init` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xdd0c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xdd0c-0xde20 (276 bytes).
  It occupies 276 bytes.
  The `lbu` at 0xdd38 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xdd54 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  3 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x108, including `lw` at 0xdd60, `lw` at 0xddfc, `lw` at 0xde14.
  The `lbu` at 0xdd6c loads 1 byte from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x10c.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110, including `lw` at 0xdd78, `lw` at 0xdd90.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + ([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+268]:1 << 0x7)) +0x110, including `lw` at 0xdd88, `lw` at 0xdd94.
  The `sd` at 0xddec stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x120.
  The `sw` at 0xddf8 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `sw` at 0xde1c stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x110.
  The `jal` at 0xdd20 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xdd84 calls hwgraph_edge_add with a0=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272], a1=[(ret(hwgraph_fastinfo_get) + ([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+268]:1 << 0x7))+272], a2=sym(.rodata)+11000, a3=?, a4=0x0.
  The `jal` at 0xdd98 calls hwgraph_edge_add with a0=[(ret(hwgraph_fastinfo_get) + ([(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+268]:1 << 0x7))+272], a1=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+272], a2=sym(.rodata)+11000, a3=?.
  The `jal` at 0xddd0 calls kmem_zalloc with a0=0x8, a1=0x0, a2=?, a3=?, a4=0x16.
  The `jal` at 0xddf4 calls pcibr_device_info_new with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=0xff, a3=-0x1, a4=-0x1, a5=0x1.
  The `jal` at 0xde0c calls pciio_device_info_register with a0=a0 at entry (arg0), a1=ret(pcibr_device_info_new), a2=?, a3=?, a4=0x0, a6=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264].
  The `beq` branch at 0xdd30 targets 0xddc8, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xdd44 targets 0xddc0, is taken when s2(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s2(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `blez` branch at 0xdd58 targets 0xddd0, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) <= 0 (signed), and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) > 0 (signed).
  The `beq` branch at 0xdd64 targets 0xdda4, is taken when a0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) == 0, and falls through when a0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) != 0.
  The `beq` branch at 0xddc0 targets 0xdda8 and is always taken.
  The `beq` branch at 0xddc8 targets 0xdda8 and is always taken.
  The `beq` branch at 0xde00 targets 0xdda4, is taken when a6(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) == 0, and falls through when a6(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) != 0.
  The `beq` branch at 0xde18 targets 0xdd64 and is always taken.
  The return at 0xddb8 has v0 = one of 0x0, 0x16.

- `pcibr_slot_call_device_attach` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xde20 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xde20-0xe0fc (732 bytes).
  It occupies 732 bytes.
  The `lbu` at 0xde54 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xde74 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x108.
  The `lw` at 0xdea8 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x0.
  5 such `lw` accesses load 4 bytes from ?, including `lw` at 0xdec0, `lw` at 0xdf38, `lw` at 0xdf44.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0xdedc, `ld` at 0xdf28.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0xdf04, `sw` at 0xe07c, `sw` at 0xe0b4.
  The `lh` at 0xdf90 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `ld` at 0xe0f8 loads 8 bytes from table(0x0) +0x0.
  The `jal` at 0xde40 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xdeb0 calls async_attach_get_info with a0=[ret(hwgraph_fastinfo_get)], a1=?, a2=?, a3=?.
  The `jal` at 0xdef8 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xdf4c calls device_admin_info_get with a0=?, a1=sym(.rodata)+11000, a2=?, a3=?.
  The `jal` at 0xdf68 calls async_attach_add_info with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xdf74 calls pciio_device_attach with a0=?, a1=a2 at entry (arg2), a2=?, a3=?.
  The `jal` at 0xdfb4 calls pcibr_debug with a0=0x2000, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=?, a5=a2 at entry (arg2), a6=ret(pciio_device_attach).
  The `jal` at 0xdfd0 calls hwgraph_path_lookup with a0=?, a1=sym(.rodata)+11000, a2=sp-144, a3=0x0.
  The `jal` at 0xdfe0 calls hwgraph_vertex_unref with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xdff8 calls hwgraph_path_lookup with a0=?, a1=sym(.rodata)+11000, a2=sp-144, a3=0x0.
  The `jal` at 0xe008 calls scsi_ctlr_nums_add with a0=[sym(baseio_pci_vhdl)], a1=?, a2=?, a3=?.
  The `jal` at 0xe020 calls scsi_ctlr_nums_add with a0=[sym(baseio_pci_vhdl)], a1=?, a2=?, a3=?.
  The `jal` at 0xe0c8 calls vertex_to_name with a0=?, a1=sp-400, a2=0x100, a3=?.
  The `jal` at 0xe0dc calls cmn_err with a0=0x4, a1=sym(.rodata)+11000, a2=sp-400, a3=?.
  The `beq` branch at 0xde4c targets 0xde80, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xde60 targets 0xdea0, is taken when s4(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s4(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xde78 targets 0xdea8, is taken when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) == 0, and falls through when v0(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) != 0.
  The `beq` branch at 0xdea0 targets 0xde84 and is always taken.
  The `blez` branch at 0xded8 targets 0xe0b8, is taken when s6(?) <= 0 (signed), and falls through when s6(?) > 0 (signed).
  The `beq` branch at 0xdef0 targets 0xe0ec and is always taken.
  The `beq` branch at 0xdf20 targets 0xe030, is taken when s0(?) >= s6(?) (signed), and falls through when s0(?) < s6(?) (signed).
  The `beq` branch at 0xdf30 targets 0xdf14, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xdf3c targets 0xdf14, is taken when v1(?) == a0(=-0x1), and falls through when v1(?) != a0(=-0x1).
  The `bne` branch at 0xdf54 targets 0xe0c4, is taken when v0(=ret(device_admin_info_get)) != 0, and falls through when v0(=ret(device_admin_info_get)) == 0.
  The `beq` branch at 0xdf60 targets 0xdf70, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xdf88 targets 0xdf9c, is taken when a0(=0xff) == s4(=a1), and falls through when a0(=0xff) != s4(=a1).
  The `beq` branch at 0xdf94 targets 0xe018, is taken when a3(=[ret(hwgraph_fastinfo_get)+114]:2) == a4(=0x2), and falls through when a3(=[ret(hwgraph_fastinfo_get)+114]:2) != a4(=0x2).
  The `beq` branch at 0xdfbc targets 0xdf00, is taken when s3(=a2) == 0, and falls through when s3(=a2) != 0.
  The `beq` branch at 0xdfd8 targets 0xe020, is taken when v0(=ret(hwgraph_path_lookup)) == 0, and falls through when v0(=ret(hwgraph_path_lookup)) != 0.
  The `bne` branch at 0xe000 targets 0xdef8, is taken when v0(=ret(hwgraph_path_lookup)) != 0, and falls through when v0(=ret(hwgraph_path_lookup)) == 0.
  The `beq` branch at 0xe010 targets 0xdef8 and is always taken.
  The `beq` branch at 0xe018 targets 0xdf9c and is always taken.
  The `beq` branch at 0xe028 targets 0xdfe0 and is always taken.
  The `beq` branch at 0xe048 targets 0xe094, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0xe058 targets 0xe080, is taken when a3(?) == a4(=0x13), and falls through when a3(?) != a4(=0x13).
  The `beq` branch at 0xe060 targets 0xe080, is taken when a5(?) == a1(=0x2a), and falls through when a5(?) != a1(=0x2a).
  The `beq` branch at 0xe068 targets 0xe084, is taken when a6(?) == a7(=0x1), and falls through when a6(?) != a7(=0x1).
  The `beq` branch at 0xe08c targets 0xde80 and is always taken.
  The `beq` branch at 0xe0b0 targets 0xe080 and is always taken.
  The `beq` branch at 0xe0bc targets 0xe080 and is always taken.
  The `beq` branch at 0xe0e4 targets 0xdf18 and is always taken.
  The `beq` branch at 0xe0f4 targets 0xdf2c and is always taken.
  The return at 0xde98 has v0 = one of ?, 0x16.

- `pcibr_slot_call_device_detach` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xe0fc (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xe0fc-0xe35c (608 bytes).
  It occupies 608 bytes.
  The `lbu` at 0xe134 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xe150 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x108.
  The `lw` at 0xe190 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `ld` at 0xe194 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x120.
  The `sw` at 0xe1f0 stores 4 bytes to ?.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xe218, `ld` at 0xe244, `ld` at 0xe25c.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xe228, `lw` at 0xe260, `lw` at 0xe284.
  The `lh` at 0xe234 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x74.
  The `lw` at 0xe250 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x510.
  The `sw` at 0xe258 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x510.
  The `lw` at 0xe270 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x514.
  The `lw` at 0xe278 loads 4 bytes from table(sym(max_splittrans_to_numbuf)) +0x0.
  The `sw` at 0xe280 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x514.
  The `lh` at 0xe2a8 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x114, including `lw` at 0xe2f0, `lw` at 0xe32c.
  2 such `sw` accesses store 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x114, including `sw` at 0xe2fc, `sw` at 0xe340.
  The `jal` at 0xe118 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe1e4 calls pcibr_debug with a0=0x4000, a1=a0 at entry (arg0), a2=sym(.rodata)+11000, a3=?, a5=a2 at entry (arg2), a6=ret(pciio_device_detach).
  The `jal` at 0xe28c calls pciio_device_detach with a0=?, a1=a2 at entry (arg2), a2=?, a3=?, a5=-0x1.
  The `jal` at 0xe320 calls pcibr_device_unregister with a0=?, a1=-0x1, a2=?, a3=?.
  The `beq` branch at 0xe12c targets 0xe15c, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xe140 targets 0xe180, is taken when s3(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s3(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `beq` branch at 0xe154 targets 0xe188, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) == 0, and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+264]) != 0.
  The `beq` branch at 0xe180 targets 0xe160 and is always taken.
  The `blez` branch at 0xe1a8 targets 0xe344, is taken when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) <= 0 (signed), and falls through when v1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) > 0 (signed).
  The `beq` branch at 0xe1c4 targets 0xe34c and is always taken.
  The `beq` branch at 0xe208 targets 0xe2bc, is taken when s0(?) >= a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) (signed), and falls through when s0(?) < a1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) (signed).
  The `beq` branch at 0xe220 targets 0xe1f8, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0xe22c targets 0xe1fc, is taken when a4(?) == a5(=-0x1), and falls through when a4(?) != a5(=-0x1).
  The `beq` branch at 0xe23c targets 0xe284, is taken when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a6(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xe248 targets 0xe284, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xe2a0 targets 0xe1d0, is taken when a0(=0xff) == s3(=a1), and falls through when a0(=0xff) != s3(=a1).
  The `bne` branch at 0xe2ac targets 0xe1cc, is taken when t8(=[ret(hwgraph_fastinfo_get)+114]:2) != t9(=0x2), and falls through when t8(=[ret(hwgraph_fastinfo_get)+114]:2) == t9(=0x2).
  The `beq` branch at 0xe2b4 targets 0xe1d0 and is always taken.
  The `beq` branch at 0xe2c0 targets 0xe308, is taken when s4(?) == 0, and falls through when s4(?) != 0.
  The `beq` branch at 0xe2d8 targets 0xe300, is taken when s4(?) == ra(=0x13), and falls through when s4(?) != ra(=0x13).
  The `beq` branch at 0xe2e0 targets 0xe300, is taken when s4(?) == v0(=0x2a), and falls through when s4(?) != v0(=0x2a).
  The `beq` branch at 0xe2e8 targets 0xe300, is taken when s4(?) == at(=0x1), and falls through when s4(?) != at(=0x1).
  The `beq` branch at 0xe300 targets 0xe15c and is always taken.
  The `beq` branch at 0xe318 targets 0xe328, is taken when a1(=-0x1) == s8(?), and falls through when a1(=-0x1) != s8(?).
  The `beq` branch at 0xe33c targets 0xe300 and is always taken.
  The `beq` branch at 0xe344 targets 0xe300 and is always taken.
  The `beq` branch at 0xe354 targets 0xe214 and is always taken.
  The return at 0xe178 has v0 = one of ?, 0x16.

- `pcibr_slot_attach` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xe35c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xe35c-0xe618 (700 bytes).
  It occupies 700 bytes.
  2 such `lw` accesses load 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x114, including `lw` at 0xe398, `lw` at 0xe45c.
  The `lw` at 0xe3a8 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  9 such `sw` accesses store 4 bytes to a4 (arg4 at entry) +0x0, including `sw` at 0xe3c0, `sw` at 0xe404, `sw` at 0xe440.
  The `sw` at 0xe46c stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x114.
  The `lh` at 0xe470 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x72.
  The `sh` at 0xe49c stores 2 bytes to ret(hwgraph_fastinfo_get) +0x74.
  The `lh` at 0xe504 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x74.
  The `sw` at 0xe518 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x520.
  The `sw` at 0xe51c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x51c.
  2 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0xe52c, `lbu` at 0xe58c.
  The `lbu` at 0xe530 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  The `sw` at 0xe53c stores 4 bytes to ret(hwgraph_fastinfo_get) +0x518.
  The `jal` at 0xe388 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe3ec calls pcibr_slot_call_device_attach with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xe428 calls pcibr_slot_pwr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2002, a3=a3 at entry (arg3).
  The `jal` at 0xe47c calls pcireg_speed_get with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xe488 calls pcireg_mode_get with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xe4b0 calls nano_delay with a0=sp-96, a1=0x1dcd6500, a2=?, a3=?.
  The `jal` at 0xe4bc calls pcibr_slot_info_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xe4e0 calls pcibr_slot_addr_space_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xe524 calls pcibr_pcix_rbars_calc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=0x10.
  The `jal` at 0xe544 calls pcibr_slot_pcix_rbar_init with a0=ret(hwgraph_fastinfo_get), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xe584 calls pcibr_slot_pcix_rbar_init with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xe5ac calls pcibr_slot_device_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xe5d0 calls pcibr_slot_guest_info_init with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xe5f4 calls pcibr_slot_initial_rrb_alloc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `beq` branch at 0xe3a0 targets 0xe41c, is taken when (at(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+276]) & 0x10) == 0, and falls through when (at(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+276]) & 0x10) != 0.
  The `bne` branch at 0xe3b0 targets 0xe3e8, is taken when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) < 0x2 (signed), and falls through when t8(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) >= 0x2 (signed).
  The `beq` branch at 0xe3b8 targets 0xe3c4, is taken when s0(=a4) == 0, and falls through when s0(=a4) != 0.
  The `beq` branch at 0xe3f4 targets 0xe454, is taken when v0(=ret(pcibr_slot_call_device_attach)) == 0, and falls through when v0(=ret(pcibr_slot_call_device_attach)) != 0.
  The `beq` branch at 0xe3fc targets 0xe40c, is taken when s0(=a4) == 0, and falls through when s0(=a4) != 0.
  The `beq` branch at 0xe40c targets 0xe44c, is taken when v0(=ret(pcibr_slot_call_device_attach)) == ra(=0x2a), and falls through when v0(=ret(pcibr_slot_call_device_attach)) != ra(=0x2a).
  The `beq` branch at 0xe414 targets 0xe3c8 and is always taken.
  The `beq` branch at 0xe430 targets 0xe45c, is taken when v0(=ret(pcibr_slot_pwr)) == 0, and falls through when v0(=ret(pcibr_slot_pwr)) != 0.
  The `beq` branch at 0xe438 targets 0xe444, is taken when s0(=a4) == 0, and falls through when s0(=a4) != 0.
  The `beq` branch at 0xe444 targets 0xe3c8 and is always taken.
  The `beq` branch at 0xe44c targets 0xe3c8 and is always taken.
  The `beq` branch at 0xe454 targets 0xe3c8 and is always taken.
  The `beq` branch at 0xe474 targets 0xe4a4, is taken when at(=[ret(hwgraph_fastinfo_get)+114]:2) == 0, and falls through when at(=[ret(hwgraph_fastinfo_get)+114]:2) != 0.
  The `beq` branch at 0xe4c4 targets 0xe4e0, is taken when v0(=ret(pcibr_slot_info_init)) == 0, and falls through when v0(=ret(pcibr_slot_info_init)) != 0.
  The `beq` branch at 0xe4cc targets 0xe4d8, is taken when s0(=a4) == 0, and falls through when s0(=a4) != 0.
  The `beq` branch at 0xe4d8 targets 0xe3c8 and is always taken.
  The `beq` branch at 0xe4e8 targets 0xe504, is taken when v0(=ret(pcibr_slot_addr_space_init)) == 0, and falls through when v0(=ret(pcibr_slot_addr_space_init)) != 0.
  The `beq` branch at 0xe4f0 targets 0xe4fc, is taken when s0(=a4) == 0, and falls through when s0(=a4) != 0.
  The `beq` branch at 0xe4fc targets 0xe3c8 and is always taken.
  The `beq` branch at 0xe50c targets 0xe5ac, is taken when (a2(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (a2(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `beq` branch at 0xe538 targets 0xe578, is taken when a0(=[ret(hwgraph_fastinfo_get)+57]:1) >= s4(=[ret(hwgraph_fastinfo_get)+56]:1) (signed), and falls through when a0(=[ret(hwgraph_fastinfo_get)+57]:1) < s4(=[ret(hwgraph_fastinfo_get)+56]:1) (signed).
  The `beq` branch at 0xe54c targets 0xe5a8, is taken when v0(=ret(pcibr_slot_pcix_rbar_init)) == 0, and falls through when v0(=ret(pcibr_slot_pcix_rbar_init)) != 0.
  The `beq` branch at 0xe554 targets 0xe560, is taken when s0(=a4) == 0, and falls through when s0(=a4) != 0.
  The `beq` branch at 0xe560 targets 0xe3c8 and is always taken.
  The `bne` branch at 0xe570 targets 0xe540, is taken when a0(=[ret(hwgraph_fastinfo_get)+57]:1) < s4(?) (signed), and falls through when a0(=[ret(hwgraph_fastinfo_get)+57]:1) >= s4(?) (signed).
  The `beq` branch at 0xe578 targets 0xe568, is taken when s4(?) == s1(=a1), and falls through when s4(?) != s1(=a1).
  The `beq` branch at 0xe598 targets 0xe578, is taken when a0(=[ret(hwgraph_fastinfo_get)+57]:1) >= s4(?) (signed), and falls through when a0(=[ret(hwgraph_fastinfo_get)+57]:1) < s4(?) (signed).
  The `beq` branch at 0xe5a0 targets 0xe544 and is always taken.
  The `beq` branch at 0xe5b4 targets 0xe5d0, is taken when v0(=ret(pcibr_slot_device_init)) == 0, and falls through when v0(=ret(pcibr_slot_device_init)) != 0.
  The `beq` branch at 0xe5bc targets 0xe5c8, is taken when s0(=a4) == 0, and falls through when s0(=a4) != 0.
  The `beq` branch at 0xe5c8 targets 0xe3c8 and is always taken.
  The `beq` branch at 0xe5d8 targets 0xe5f4, is taken when v0(=ret(pcibr_slot_guest_info_init)) == 0, and falls through when v0(=ret(pcibr_slot_guest_info_init)) != 0.
  The `beq` branch at 0xe5e0 targets 0xe5ec, is taken when s0(=a4) == 0, and falls through when s0(=a4) != 0.
  The `beq` branch at 0xe5ec targets 0xe3c8 and is always taken.
  The `beq` branch at 0xe5fc targets 0xe3a8, is taken when v0(=ret(pcibr_slot_initial_rrb_alloc)) == 0, and falls through when v0(=ret(pcibr_slot_initial_rrb_alloc)) != 0.
  The `beq` branch at 0xe604 targets 0xe610, is taken when s0(=a4) == 0, and falls through when s0(=a4) != 0.
  The `beq` branch at 0xe610 targets 0xe3c8 and is always taken.
  The return at 0xe3e0 has v0 = one of 0x1c, 0x19, 0x7, 0xd, 0x0, 0x12, 0x14, 0x1d, 0x15, 0x17, 0x18.

- `pcibr_slot_detach` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xe618 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xe618-0xe768 (336 bytes).
  It occupies 336 bytes.
  2 such `sw` accesses store 4 bytes to a4 (arg4 at entry) +0x0, including `sw` at 0xe69c, `sw` at 0xe734.
  The `lh` at 0xe6a8 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x74.
  The `sw` at 0xe6b8 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x520.
  The `sw` at 0xe6bc stores 4 bytes to ret(hwgraph_fastinfo_get) +0x51c.
  The `lbu` at 0xe6c8 loads 1 byte from ret(hwgraph_fastinfo_get) +0x38.
  2 such `lbu` accesses load 1 byte from ret(hwgraph_fastinfo_get) +0x39, including `lbu` at 0xe6cc, `lbu` at 0xe6f4.
  The `sw` at 0xe6d4 stores 4 bytes to ret(hwgraph_fastinfo_get) +0x518.
  The `lw` at 0xe74c loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x114.
  The `sw` at 0xe764 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x114.
  The `jal` at 0xe640 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe650 calls pcibr_is_slot_sys_critical with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xe684 calls pcibr_slot_call_device_detach with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=?.
  The `jal` at 0xe6c0 calls pcibr_pcix_rbars_calc with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xe6e8 calls pcibr_slot_pcix_rbar_init with a0=ret(hwgraph_fastinfo_get), a1=?, a2=?, a3=?.
  The `jal` at 0xe71c calls pcibr_slot_pwr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x2003, a3=a3 at entry (arg3), a4=a2 at entry (arg2).
  The `beq` branch at 0xe658 targets 0xe67c, is taken when v0(=ret(pcibr_is_slot_sys_critical)) == 0, and falls through when v0(=ret(pcibr_is_slot_sys_critical)) != 0.
  The `beq` branch at 0xe68c targets 0xe6a8, is taken when v0(=ret(pcibr_slot_call_device_detach)) == 0, and falls through when v0(=ret(pcibr_slot_call_device_detach)) != 0.
  The `beq` branch at 0xe694 targets 0xe6a0, is taken when s3(=a4) == 0, and falls through when s3(=a4) != 0.
  The `beq` branch at 0xe6a0 targets 0xe660 and is always taken.
  The `beq` branch at 0xe6b0 targets 0xe708, is taken when (at(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) == 0, and falls through when (at(=[ret(hwgraph_fastinfo_get)+116]:2) & 0x1) != 0.
  The `bne` branch at 0xe6d8 targets 0xe708, is taken when v1(=[ret(hwgraph_fastinfo_get)+57]:1) < a0(=[ret(hwgraph_fastinfo_get)+56]:1) (signed), and falls through when v1(=[ret(hwgraph_fastinfo_get)+57]:1) >= a0(=[ret(hwgraph_fastinfo_get)+56]:1) (signed).
  The `beq` branch at 0xe700 targets 0xe6e0, is taken when a2(=[ret(hwgraph_fastinfo_get)+57]:1) >= a3(?) (signed), and falls through when a2(=[ret(hwgraph_fastinfo_get)+57]:1) < a3(?) (signed).
  The `beq` branch at 0xe70c targets 0xe740, is taken when a4(=a2) == 0, and falls through when a4(=a2) != 0.
  The `beq` branch at 0xe724 targets 0xe748, is taken when v0(=ret(pcibr_slot_pwr)) == 0, and falls through when v0(=ret(pcibr_slot_pwr)) != 0.
  The `beq` branch at 0xe72c targets 0xe738, is taken when s3(=a4) == 0, and falls through when s3(=a4) != 0.
  The `beq` branch at 0xe738 targets 0xe660 and is always taken.
  The `beq` branch at 0xe740 targets 0xe660 and is always taken.
  The `beq` branch at 0xe760 targets 0xe660 and is always taken.
  The return at 0xe674 has v0 = one of 0x0, 0x4, 0x7, 0x1a.

- `pcibr_slot_pwr` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xe768 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xe768-0xe8b4 (332 bytes).
  It occupies 332 bytes.
  The `ld` at 0xe798 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `ld` at 0xe7c0 loads 8 bytes from table(0x9000000034000000) +0x0.
  2 such `lh` accesses load 2 bytes from ret(hwgraph_fastinfo_get) +0x72, including `lh` at 0xe7f0, `lh` at 0xe874.
  The `lbu` at 0xe804 loads 1 byte from ret(hwgraph_fastinfo_get) +0x28.
  2 such `ld` accesses load 8 bytes from ret(hwgraph_fastinfo_get) +0x80, including `ld` at 0xe810, `ld` at 0xe884.
  The `jal` at 0xe790 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe7d4 calls pcibr_widget_to_bus with a0=a0 at entry (arg0), a1=sp-64, a2=?, a3=?.
  The `jal` at 0xe80c calls iobrick_pci_slot_pwr with a0=[ret(hwgraph_fastinfo_get)+128]:8, a1=ret(pcibr_widget_to_bus), a2=?, a3=a2 at entry (arg2), a4=a3 at entry (arg3), a5=[ret(hwgraph_fastinfo_get)+40]:1.
  The `jal` at 0xe840 calls peer_iobrick_rack_bay_get with a0=?, a1=sp-64, a2=sp-60, a3=?.
  The `jal` at 0xe854 calls printf with a0=sym(.rodata)+11000, a1=?, a2=?, a3=?.
  The `jal` at 0xe85c calls pcibr_widget_to_bus with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xe894 calls peer_iobrick_pci_slot_pwr with a0=[ret(hwgraph_fastinfo_get)+128]:8, a1=?, a2=?, a3=ret(pcibr_widget_to_bus), a5=a2 at entry (arg2), a6=a3 at entry (arg3).
  The `beq` branch at 0xe7cc targets 0xe83c, is taken when at(?) == v0(=0xc000), and falls through when at(?) != v0(=0xc000).
  The `beq` branch at 0xe7e8 targets 0xe8a4, is taken when v0(=0xff) == s0(=a1), and falls through when v0(=0xff) != s0(=a1).
  The `beq` branch at 0xe7f4 targets 0xe800, is taken when v1(=[ret(hwgraph_fastinfo_get)+114]:2) == a0(=0x2), and falls through when v1(=[ret(hwgraph_fastinfo_get)+114]:2) != a0(=0x2).
  The `beq` branch at 0xe848 targets 0xe85c, is taken when v0(=ret(peer_iobrick_rack_bay_get)) == 0, and falls through when v0(=ret(peer_iobrick_rack_bay_get)) != 0.
  The `beq` branch at 0xe86c targets 0xe884, is taken when a1(=0xff) == s0(=a1), and falls through when a1(=0xff) != s0(=a1).
  The `beq` branch at 0xe87c targets 0xe8ac, is taken when a2(=[ret(hwgraph_fastinfo_get)+114]:2) == a4(=0x2), and falls through when a2(=[ret(hwgraph_fastinfo_get)+114]:2) != a4(=0x2).
  The `beq` branch at 0xe89c targets 0xe818 and is always taken.
  The `beq` branch at 0xe8a4 targets 0xe804 and is always taken.
  The `beq` branch at 0xe8ac targets 0xe884 and is always taken.
  The return at 0xe834 has v0 = one of ret(iobrick_pci_slot_pwr), ret(peer_iobrick_pci_slot_pwr).

- `pcibr_is_slot_sys_critical` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xe8b4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xe8b4-0xe9c4 (272 bytes).
  It occupies 272 bytes.
  The `lbu` at 0xe8e8 loads 1 byte from ret(hwgraph_fastinfo_get) +0x39.
  The `lw` at 0xe900 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `ld` at 0xe908 loads 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x120.
  The `ld` at 0xe928 loads 8 bytes from ?.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xe934, `lw` at 0xe940.
  The `jal` at 0xe8c0 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xe94c calls vertex_to_name with a0=?, a1=sp-304, a2=0x100, a3=?.
  The `jal` at 0xe954 calls is_sys_critical_vertex with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xe9b4 calls cmn_err with a0=0x4, a1=sym(.rodata)+11000, a2=sp-304, a3=?.
  The `beq` branch at 0xe8e0 targets 0xe9a4, is taken when v0(=ret(hwgraph_fastinfo_get)) == 0, and falls through when v0(=ret(hwgraph_fastinfo_get)) != 0.
  The `beq` branch at 0xe8f8 targets 0xe99c, is taken when s0(=a1) >= at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed), and falls through when s0(=a1) < at(=[ret(hwgraph_fastinfo_get)+57]:1+1) (signed).
  The `blez` branch at 0xe904 targets 0xe974, is taken when s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) <= 0 (signed), and falls through when s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) > 0 (signed).
  The `beq` branch at 0xe90c targets 0xe920 and is always taken.
  The `beq` branch at 0xe91c targets 0xe974, is taken when s0(?) >= s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) (signed), and falls through when s0(?) < s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) (signed).
  The `beq` branch at 0xe92c targets 0xe914, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xe938 targets 0xe914, is taken when v1(?) == s4(=-0x1), and falls through when v1(?) != s4(=-0x1).
  The `bne` branch at 0xe95c targets 0xe9ac, is taken when v0(=ret(is_sys_critical_vertex)) != 0, and falls through when v0(=ret(is_sys_critical_vertex)) == 0.
  The `bne` branch at 0xe96c targets 0xe924, is taken when s0(?) < s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) (signed), and falls through when s0(?) >= s1(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) (signed).
  The `beq` branch at 0xe99c targets 0xe97c and is always taken.
  The `beq` branch at 0xe9a4 targets 0xe97c and is always taken.
  The `beq` branch at 0xe9bc targets 0xe978 and is always taken.
  The return at 0xe994 has v0 = one of 0x0, 0x1, 0x16.

- `pcibr_probe_slot` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xe9c4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xe9c4-0xe9e4 (32 bytes).
  It occupies 32 bytes.
  The `jal` at 0xe9d0 calls pcibr_probe_work [0xea34] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=0x4, a3=a2 at entry (arg2).
  The return at 0xe9dc has v0 = ret(pcibr_probe_work).

- `pcibr_piomap_probe` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xe9e4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xe9e4-0xea34 (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0xe9e4 loads 8 bytes from a0 (arg0 at entry) +0x18.
  The `ld` at 0xea14 loads 8 bytes from a0 (arg0 at entry) +0x20.
  The `ld` at 0xea18 loads 8 bytes from a0 (arg0 at entry) +0x40.
  The `ld` at 0xea1c loads 8 bytes from [a0+64]:8 +0x8.
  The `jal` at 0xea20 calls pcibr_probe_work [0xea34] with a0=[[a0+64]:8+8]:8, a1=(a1 + [a0+32]:8), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=-0x1, a7=a0 at entry (arg0).
  The `beq` branch at 0xea00 targets 0xea14, is taken when at(=[a0+24]:8) >= v1(=(a2 + a1)) (unsigned), and falls through when at(=[a0+24]:8) < v1(=(a2 + a1)) (unsigned).
  The `beq` branch at 0xea2c targets 0xea08 and is always taken.
  The return at 0xea0c has v0 = one of -0x1, ret(pcibr_probe_work).

- `pcibr_probe_work` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xea34 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xea34-0xeb00 (204 bytes).
  It occupies 204 bytes.
  The `jal` at 0xeaac calls pcibr_disable_mst_timeout_work [0xeb48] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a6=0x4.
  The `jal` at 0xeac0 calls badaddr_val with a0=a1 at entry (arg1), a1=a2 at entry (arg2), a2=a3 at entry (arg3), a3=?.
  The `jal` at 0xead4 calls pcireg_intr_reset_set with a0=a0 at entry (arg0), a1=0x40, a2=?, a3=?.
  The `jal` at 0xeae8 calls pcibr_enable_mst_timeout_work [0xeb9c] with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xea5c targets 0xea88, is taken when a2 == at(=0x1), and falls through when a2 != at(=0x1).
  The `beq` branch at 0xea68 targets 0xea88, is taken when a2 == v1(=0x2), and falls through when a2 != v1(=0x2).
  The `beq` branch at 0xea70 targets 0xea88, is taken when a2 == a6(=0x4), and falls through when a2 != a6(=0x4).
  The `beq` branch at 0xea78 targets 0xea88, is taken when a2 == t0(=0x8), and falls through when a2 != t0(=0x8).
  The `beq` branch at 0xea80 targets 0xeaa0 and is always taken.
  The `beq` branch at 0xea94 targets 0xeaac, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0xeae0 targets 0xeaf4, is taken when a0(=(ret(pcibr_disable_mst_timeout_work) << 0x0)) == 0, and falls through when a0(=(ret(pcibr_disable_mst_timeout_work) << 0x0)) != 0.
  The `beq` branch at 0xeaf8 targets 0xea9c and is always taken.
  The return at 0xeaa4 has v0 = one of -0x1, ?.

- `pcibr_disable_mst_timeout` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xeb00 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xeb00-0xeb24 (36 bytes).
  It occupies 36 bytes.
  The `ld` at 0xeb14 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `jal` at 0xeb08 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xeb10 calls pcibr_disable_mst_timeout_work [0xeb48] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=?, a2=?, a3=?.
  The return at 0xeb1c has v0 = ret(pcibr_disable_mst_timeout_work).

- `pcibr_enable_mst_timeout` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xeb24 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xeb24-0xeb48 (36 bytes).
  It occupies 36 bytes.
  The `ld` at 0xeb38 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  The `jal` at 0xeb2c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xeb34 calls pcibr_enable_mst_timeout_work [0xeb9c] with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=?, a2=?, a3=?.
  The return at 0xeb40 has v0 = ret(pcibr_enable_mst_timeout_work).

- `pcibr_disable_mst_timeout_work` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xeb48 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xeb48-0xeb9c (84 bytes).
  It occupies 84 bytes.
  The `jal` at 0xeb58 calls pcireg_intr_enable_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xeb68 calls pcireg_intr_enable_bit_clr with a0=a0 at entry (arg0), a1=0x400000800, a2=?, a3=?.
  The `jal` at 0xeb70 calls pcireg_intr_enable_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0xeb7c targets 0xeb8c, is taken when s8(=ret(pcireg_intr_enable_get)) != v0(=ret(pcireg_intr_enable_get)), and falls through when s8(=ret(pcireg_intr_enable_get)) == v0(=ret(pcireg_intr_enable_get)).
  The `beq` branch at 0xeb84 targets 0xeb90 and is always taken.
  The return at 0xeb94 has v0 = one of 0x0, 0x1.

- `pcibr_enable_mst_timeout_work` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xeb9c (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xeb9c-0xebf0 (84 bytes).
  It occupies 84 bytes.
  The `jal` at 0xebac calls pcireg_intr_enable_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xebbc calls pcireg_intr_enable_bit_set with a0=a0 at entry (arg0), a1=0x400000800, a2=?, a3=?.
  The `jal` at 0xebc4 calls pcireg_intr_enable_get with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `bne` branch at 0xebd0 targets 0xebe0, is taken when s8(=ret(pcireg_intr_enable_get)) != v0(=ret(pcireg_intr_enable_get)), and falls through when s8(=ret(pcireg_intr_enable_get)) == v0(=ret(pcireg_intr_enable_get)).
  The `beq` branch at 0xebd8 targets 0xebe4 and is always taken.
  The return at 0xebe8 has v0 = one of 0x0, 0x1.

- `pcibr_device_info_free` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xebf0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xebf0-0xee28 (568 bytes).
  It occupies 568 bytes.
  The `lw` at 0xec30 loads 4 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x118.
  The `ld` at 0xec40 loads 8 bytes from ret(hwgraph_fastinfo_get) +0x8.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xec64, `ld` at 0xec70, `ld` at 0xecdc.
  3 such `ld` accesses load 8 bytes from (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x120, including `ld` at 0xec94, `ld` at 0xecd4, `ld` at 0xee24.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xeca8, `sd` at 0xed9c, `sd` at 0xedb0.
  3 such `lw` accesses load 4 bytes from ?, including `lw` at 0xed4c, `lw` at 0xed58, `lw` at 0xed88.
  2 such `sw` accesses store 4 bytes to ?, including `sw` at 0xed70, `sw` at 0xeda4.
  The `sw` at 0xedd4 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x14c.
  The `sw` at 0xedd8 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x150.
  The `sw` at 0xeddc stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x154.
  The `sd` at 0xede4 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x158.
  The `sw` at 0xede8 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x160.
  The `sw` at 0xedec stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x170.
  The `sw` at 0xedf0 stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x174.
  The `sd` at 0xedf4 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x178.
  The `sw` at 0xedfc stores 4 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x180.
  The `sd` at 0xee08 stores 8 bytes to (ret(hwgraph_fastinfo_get) + (a1 << 0x7)) +0x168.
  The `jal` at 0xec0c calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xec7c calls pcibr_bus_addr_free with a0=?, a1=ret(mutex_spinlock), a2=?, a3=?.
  The `jal` at 0xec8c calls mutex_io_spinunlock with a0=ret(hwgraph_fastinfo_get)+140, a1=(ret(mutex_spinlock) << 0x0), a2=?, a3=?.
  The `jal` at 0xeca4 calls pciio_device_info_unregister with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `jal` at 0xecac calls pciio_device_info_free with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xecb8 calls kmem_free with a0=?, a1=0x228, a2=?, a3=?.
  The `jal` at 0xece8 calls mutex_spinlock with a0=ret(hwgraph_fastinfo_get)+140, a1=?, a2=?, a3=?.
  The `jal` at 0xed04 calls pcibr_func_config_addr with a0=[ret(hwgraph_fastinfo_get)+8]:8, a1=0x0, a2=a1 at entry (arg1), a3=?, a4=0x0.
  The `jal` at 0xed1c calls do_pcibr_config_get with a0=ret(pcibr_func_config_addr), a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xed34 calls do_pcibr_config_set with a0=ret(pcibr_func_config_addr), a1=0x4, a2=0x4, a3=?.
  The `jal` at 0xed44 calls pcibr_bus_addr_free with a0=?, a1=?, a2=?, a3=?.
  The `blez` branch at 0xec48 targets 0xee18, is taken when s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) <= 0 (signed), and falls through when s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) > 0 (signed).
  The `beq` branch at 0xec50 targets 0xee20 and is always taken.
  The `bne` branch at 0xec5c targets 0xed7c, is taken when s0(?) < 0x6 (signed), and falls through when s0(?) >= 0x6 (signed).
  The `beq` branch at 0xec68 targets 0xec88, is taken when t9(?) == 0, and falls through when t9(?) != 0.
  The `beq` branch at 0xec74 targets 0xec88, is taken when ra(?) == 0, and falls through when ra(?) != 0.
  The `beq` branch at 0xeccc targets 0xedb4, is taken when s3(?) >= s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) (signed), and falls through when s3(?) < s7(=[(ret(hwgraph_fastinfo_get) + (a1 << 0x7))+280]) (signed).
  The `beq` branch at 0xece0 targets 0xecc0, is taken when s2(?) == 0, and falls through when s2(?) != 0.
  The `beq` branch at 0xed3c targets 0xed78 and is always taken.
  The `beq` branch at 0xed6c targets 0xed9c, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `beq` branch at 0xed74 targets 0xec64, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0xed8c targets 0xed44, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0xed94 targets 0xec58 and is always taken.
  The `beq` branch at 0xedac targets 0xed74 and is always taken.
  The `beq` branch at 0xee18 targets 0xedb8 and is always taken.
  The `beq` branch at 0xee20 targets 0xecd8 and is always taken.
  The return at 0xee10 has v0 = one of ?, ret(hwgraph_fastinfo_get).

- `pcibr_bus_addr_alloc` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xee28 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xee28-0xeeb8 (144 bytes).
  It occupies 144 bytes.
  The `jal` at 0xee7c calls pciio_device_win_alloc with a0=(a0 + one of 0x850, 0x860, 0x870), a1=?, a2=a3 at entry (arg3), a3=a4 at entry (arg4), a4=a5 at entry (arg5).
  The `beq` branch at 0xee40 targets 0xee98, is taken when a2 == at(=0x2), and falls through when a2 != at(=0x2).
  The `beq` branch at 0xee48 targets 0xeeb0, is taken when a2 == t0(=0x4), and falls through when a2 != t0(=0x4).
  The `beq` branch at 0xee50 targets 0xee60, is taken when a2 == t1(=0x5), and falls through when a2 != t1(=0x5).
  The `beq` branch at 0xee58 targets 0xee8c and is always taken.
  The `bne` branch at 0xee60 targets 0xeea4, is taken when a1 != 0, and falls through when a1 == 0.
  The `beq` branch at 0xee9c targets 0xee68, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0xeea8 targets 0xee6c and is always taken.
  The `beq` branch at 0xeeb0 targets 0xee9c and is always taken.
  The return at 0xee90 has v0 = one of 0x0, ret(pciio_device_win_alloc).

- `pcibr_bus_addr_free` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xeeb8 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xeeb8-0xeed4 (28 bytes).
  It occupies 28 bytes.
  The `jal` at 0xeec0 calls pciio_device_win_free with a0=a0+32, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0xeecc has v0 = ret(pciio_device_win_free).

- `pcibr_widget_to_bus` in `IP35/usr/cpu/sysgen/IP35boot/pcibr.o` at 0xeed4 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/pcibr.o`.
  Range: 0xeed4-0xef48 (116 bytes).
  It occupies 116 bytes.
  The `lh` at 0xeee8 loads 2 bytes from ret(hwgraph_fastinfo_get) +0x8a.
  The `lbu` at 0xeeec loads 1 byte from ret(hwgraph_fastinfo_get) +0x28.
  The `lw` at 0xeef0 loads 4 bytes from ret(hwgraph_fastinfo_get) +0x48.
  The `jal` at 0xeee0 calls hwgraph_fastinfo_get with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xeef4 calls io_brick_map_widget with a0=[ret(hwgraph_fastinfo_get)+138]:2, a1=[ret(hwgraph_fastinfo_get)+40]:1, a2=?, a3=?.
  The `bne` branch at 0xef0c targets 0xef2c, is taken when s7(=[ret(hwgraph_fastinfo_get)+138]:2) != v0(=0x39), and falls through when s7(=[ret(hwgraph_fastinfo_get)+138]:2) == v0(=0x39).
  The `beq` branch at 0xef20 targets 0xef40, is taken when s0(?) == a0(=0x3), and falls through when s0(?) != a0(=0x3).
  The `beq` branch at 0xef40 targets 0xef2c and is always taken.
  The return at 0xef38 has v0 = one of ?, 0x4.
