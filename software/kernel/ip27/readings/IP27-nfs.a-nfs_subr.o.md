# Readings: `IP27/usr/cpu/sysgen/IP27boot/nfs.a(nfs_subr.o)`

One entry per routine, filed here from the reading batches by binary.

- `rfscall` in `IP27/usr/cpu/sysgen/IP27boot/nfs.a(nfs_subr.o)` at 0xbd0
  **Inferred.** This reads as a client-side remote call dispatcher, judged from its callees. It gets a transaction id from `krpc_getxid` (0xc18), calls `rfscall_tcp` (0xd04) only when flag 0x2000 in the word at a0+304 is set, takes a client handle with `clget` (0xd54), and issues the call through `KCLNT_CALL` (0xe40). When the `KCLNT_CALL` result is below 0x13 (unsigned), a load at 0xe68 and the indirect jump at 0xe6c index a table in `.rodata` by that result. The jump table's targets are unresolved in these facts, so per-error handling is only partly read. Flags in the structure at a0+304 (masks 0x2000, 0x4000, 0x8000 and 0x20000) and the `is_biod` call at 0xfb0 appear in branches on the later paths, and `printf` calls at 0xf34, 0x1074, 0x1158 and 0x11cc take a format string from `.rodata`, probably diagnostics. The return at 0xc6c is 0x91 on one path and a value the facts leave unresolved on another.
  Reviewed: 2026-11-12
