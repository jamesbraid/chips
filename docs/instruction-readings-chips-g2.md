# Instruction readings from hostfacts

These entries record instruction facts rendered from the routines below. They describe software behavior, not hardware behavior, and each locator names an address in the identified binary.

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
- `gbe_too_late` in `IP32/usr/cpu/sysgen/IP32boot/mvp.o` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mvp.o`.
  Range: 0x0-0x34 (52 bytes).
  It occupies 52 bytes.
  The `lw` at 0x4 loads 4 bytes from abs 0xffffffffb6010000.
  The `bltz` branch at 0x10 targets 0x28, is taken when v0(?) < 0 (signed), and falls through when v0(?) >= 0 (signed).
  The `beq` branch at 0x18 targets 0x2c, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The return at 0x20 has v0 = 0x1.
  The return at 0x2c has v0 = 0x0.
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

Skipped no routines.
