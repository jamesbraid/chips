# Readings: `IP27/usr/cpu/sysgen/IP27boot/os.a(vmdump.o)`

One entry per routine, filed here from the reading batches by binary.

- `real_dumpsys` in `IP27/usr/cpu/sysgen/IP27boot/os.a(vmdump.o)` at 0x268
  **Inferred.** Role (from name): the top-level crash-dump routine. After `spl7` at 0x270 it tests dumpdev against -1 at 0x280, tests dump_level for negative at 0x288 and dumpsize for zero at 0x290. The first two branch to 0x484, where the next call is `mdboot` at 0x488, and a zero dumpsize goes to 0x5e0, where the call is `panic` at 0x5e4. It compares MAJOR with bdevcnt at 0x2cc and with bdevmax at 0x2d8. It then calls `enter_dump_mode` at 0x320 (a4 = 1), `bdrv` at 0x358 (a1 = 8, a2 = dumpdev, a3 = 1), `compression_init` at 0x3cc (a2 = 0x8000), `dumpvmcore` at 0x3e4, `exit_dump_mode` at 0x3ec and `mdboot` at 0x404 (a0 = 0, a1 = 0). A loop between 0x498 and 0x4e8 calls `cpu_enabled` at 0x4b8. `panic` is called at 0x5d0, 0x5e4, 0x5fc and 0x614, and `dumperror` at 0x5f4 and 0x60c.
  Reviewed: 2026-11-12
