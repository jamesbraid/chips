# Readings: `IP32/usr/cpu/sysgen/IP32boot/mace.o`

One entry per routine, filed here from the reading batches by binary.

- `setmaceisavector` in `IP32/usr/cpu/sysgen/IP32boot/mace.o` at 0x22c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/mace.o`.
  Range: 0x22c-0x40c (480 bytes).
  It occupies 480 bytes.
  The `ld` at 0x2b0 loads 8 bytes from sym(mace_tbl) +0x20.
  The `lw` at 0x2d8 loads 4 bytes from sym(mace_tbl) +0x0.
  The `sw` at 0x2e4 stores 4 bytes to sym(mace_tbl) +0x0.
  2 such `sd` accesses store 8 bytes to ?, including `sd` at 0x2e8, `sd` at 0x2ec.
  3 such `sw` accesses store 4 bytes to ?, including `sw` at 0x2f0, `sw` at 0x2f4, `sw` at 0x2fc.
  The `sh` at 0x314 stores 2 bytes to ?.
  The `ll` at 0x330 loads 4 bytes from ?.
  The `sc` at 0x338 stores 4 bytes to ?.
  The `lh` at 0x358 loads 2 bytes from ?.
  The `jal` at 0x244 calls spl7 with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x310 calls sprintf with a0=sp-88, a1=sym(.rodata)+48, a2=a0 at entry (arg0), a3=?, a4=sym(mace_tbl), a5=[sym(mace_tbl)]+1, a7=sym(mace_tbl).
  The `jal` at 0x31c calls mace_is_thd with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0x35c calls xthread_setup with a0=sp-88, a1=?, a2=?, a3=sym(macevec_intrd_setup), a6=[sym(ithreads_enabled)].
  The `jal` at 0x364 calls splx with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3a4 calls setcrimevector with a0=a0 at entry (arg0), a1=0x1, a2=sym(mace_intr), a3=a0 at entry (arg0), a4=0x1.
  The `jal` at 0x3b4 calls mace_tbl_init with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x3e0 calls setcrimevector with a0=a0 at entry (arg0), a1=0x1, a2=sym(mace_intr), a3=a0 at entry (arg0), a4=0x1.
  The `jal` at 0x3f4 calls panic with a0=sym(.rodata)+64, a1=?, a2=?, a3=?.
  The `jal` at 0x3fc calls splx with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x254 targets 0x3b4, is taken when at(=[sym(is_macetbl_initialized)]) == 0, and falls through when at(=[sym(is_macetbl_initialized)]) != 0.
  The `beq` branch at 0x268 targets 0x384, is taken when s2(=a0) == v0(=0x5), and falls through when s2(=a0) != v0(=0x5).
  The `bne` branch at 0x270 targets 0x3f4, is taken when s2(=a0) != a1(=0x4), and falls through when s2(=a0) == a1(=0x4).
  The `beq` branch at 0x278 targets 0x3c8, is taken when a3(=[sym(.sdata)+16]) == 0, and falls through when a3(=[sym(.sdata)+16]) != 0.
  The `beq` branch at 0x294 targets 0x2b0 and is always taken.
  The `bne` branch at 0x29c targets 0x3f0, is taken when t2(?) != 0, and falls through when t2(?) == 0.
  The `beq` branch at 0x2a8 targets 0x2d4, is taken when t0(?) >= 0xa (signed), and falls through when t0(?) < 0xa (signed).
  The `bne` branch at 0x2b8 targets 0x29c, is taken when t2(=[sym(mace_tbl+32)]:8) != 0, and falls through when t2(=[sym(mace_tbl+32)]:8) == 0.
  The `bne` branch at 0x2c0 targets 0x2a0, is taken when s1(?) != 0, and falls through when s1(?) == 0.
  The `beq` branch at 0x2cc targets 0x2a0 and is always taken.
  The `beq` branch at 0x2d4 targets 0x3f0, is taken when s1(?) == 0, and falls through when s1(?) != 0.
  The `beq` branch at 0x324 targets 0x364, is taken when v0(=ret(mace_is_thd)) == 0, and falls through when v0(=ret(mace_is_thd)) != 0.
  The `beql` branch at 0x33c targets 0x330, is taken when t1(?) == 0, and falls through when t1(?) != 0; its branch-likely delay slot `nop` at 0x340 runs only when taken and is annulled on fall-through.
  The `beq` branch at 0x348 targets 0x364, is taken when a6(=[sym(ithreads_enabled)]) == 0, and falls through when a6(=[sym(ithreads_enabled)]) != 0.
  The `bne` branch at 0x384 targets 0x280, is taken when a4(=[sym(.sdata)+12]) != 0, and falls through when a4(=[sym(.sdata)+12]) == 0.
  The `beq` branch at 0x3ac targets 0x280 and is always taken.
  The `beq` branch at 0x3c0 targets 0x25c and is always taken.
  The `beq` branch at 0x3e8 targets 0x280 and is always taken.
  The `beq` branch at 0x404 targets 0x370 and is always taken.
  The return at 0x37c has v0 = ret(splx).
