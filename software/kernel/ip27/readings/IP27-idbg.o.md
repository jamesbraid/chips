# Readings: `IP27/usr/cpu/sysgen/IP27boot/idbg.o`

One entry per routine, filed here from the reading batches by binary.

- `idbg_callo` in `IP27/usr/cpu/sysgen/IP27boot/idbg.o` at 0x165a8
  **Inferred.** Role (from name): a debugger command that dumps callout state. It indexes the table at `pdaindr` with `a0` shifted by 4, loads a pointer at offset 8 of the table entry, and reads fields at offsets 0x5d0, 0x5e8 and 0x630 of what that pointer addresses. It calls `qprintf` at 0x1661c, 0x16690, 0x166d0, 0x16724 and 0x167b0 with `.rodata` format strings; the field at 0x5d0 is an argument of the call at 0x16690. It raises the priority with `splprof` at 0x165cc, calls a `.text` callee at 0x16770 and 0x167fc with the fields at 0x5e8 and 0x630, and passes the `splprof` result to `splx` at 0x16820. At 0x165e0 an `a0` equal to -1 falls through and any other value jumps to 0x1662c. That `a0` is a CPU number is not derived.
  Reviewed: 2026-11-12
