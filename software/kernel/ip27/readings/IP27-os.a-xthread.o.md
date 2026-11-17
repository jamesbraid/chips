# Readings: `IP27/usr/cpu/sysgen/IP27boot/os.a(xthread.o)`

One entry per routine, filed here from the reading batches by binary.

- `xthread_periodic_timeout` in `IP27/usr/cpu/sysgen/IP27boot/os.a(xthread.o)` at 0x72c
  **Inferred.** Role (from name): sets up a periodic timeout. The word at a4 is tested against 0x800 at 0x74c; the `beq` goes to 0x760 when the bit is clear. The code from 0x760 stores at +0x0 (0x764), +0x28 (0x768), +0x30 (0x76c) and +0x38 (0x774), then calls `xthread_table_name_get_property` at 0x778 with a1 = 2; the facts do not name the base register of those stores. After that it stores halfwords at +0x4a (0x78c) and +0x48 (0x798, 0x7b8, 0x80c), tests a word at +0x48 of the per-CPU record from `sym(pdaindr)` against 0x800 (the `beq` at 0x7b0) and a word at +0x6a0 (the `bne` at 0x7f4). `xthread_setup` is called at 0x7cc (a2 = a4, a3 = sym(xpt_init), a5 = sym(pdaindr)) and `xpt_timeout` at 0x7e0 (a0 = a4, followed by a store at +0x40). The return at 0x758 is one of an unresolved value and `ret(xpt_timeout)`. The facts do not settle which test chooses between `xthread_setup` and `xpt_timeout`.
  Reviewed: 2026-11-12

- `xthread_periodic_timeout` in `IP27/usr/cpu/sysgen/IP27boot/os.a(xthread.o)` at 0x72c
  **Inferred.** It tests a flag bit in the word at a4+0x0 [@0x74c]. On the taken side of that test [@0x74c taken] it stores a word at +0x0 of the fifth argument (a4) [@0x764]. It stores doublewords at a4+0x28, a4+0x30 and a4+0x38 [@0x768] [@0x76c] [@0x774]. It then calls xthread_table_name_get_property with a0 at entry and a1 = 0x2 [call 1, @0x74c taken]. It stores a halfword at a4+0x4a [@0x78c]. The branch on a -1 value [@0x790 taken] tests a register rebuilt from the call 1 result, not the a2 argument.
  Role (from facts): a record setup on a4 [@0x764] that runs only when a flag bit of its first word is clear [@0x74c taken], followed by a property lookup [call 1].
  Reviewed: 2026-11-12
