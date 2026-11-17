# Readings: `IP27/usr/cpu/sysgen/IP27boot/os.a(pda.o)`

One entry per routine, filed here from the reading batches by binary.

- `enter_panic_mode` in `IP27/usr/cpu/sysgen/IP27boot/os.a(pda.o)` at 0x1cc4
  **Inferred.** Panic entry for the boot-time PDA code. It takes `panic_lock` (0x1ccc), tests a global at -0x3d80 (0x1cdc), and sets a byte at the fixed address 0xffffffffffffc429 (0x1ce0, listed right after that branch). It loops over the CPU count in `maxcpus` (0x1cf8) and stores through pointers it loads (their targets are unresolved in the facts). `log_tstamp_event` (0x1d64) is called with a1 from the global at -0x3d80 and the tag constant 0x50414e49436d6465, which decodes to the ASCII text "PANICmde"; the branch at 0x1cdc is taken when the global is nonzero, and the facts do not show that call on the other path. The return at 0x1d50 is a value the facts leave unresolved.
  Reviewed: 2026-11-12
