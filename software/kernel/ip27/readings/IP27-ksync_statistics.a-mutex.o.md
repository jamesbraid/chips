# Readings: `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(mutex.o)`

One entry per routine, filed here from the reading batches by binary.

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(mutex.o)` at 0x35c
  **Inferred.** The try-lock form with accounting. It loads the doubleword at 0xffffffffffffc020, calls `compare_and_swap_ptr` (0x374) with a2 from the global at -0x3fe0, and charges the outcome with `lstat_update` (0x38c with a2=0x0, and 0x3b0 with a2=0x3). Both `lstat_update` calls pass the caller's return address, which suggests they record the call site. The return at 0x3a0 is a 0 or 1 flag.
  Reviewed: 2026-11-12

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_statistics.a(mutex.o)` at 0x484
  **Inferred.** The blocking acquire with the same compare-and-swap as the non-statistics `mutex_lock`, plus accounting. It calls `compare_and_swap_ptr` (0x4a0). When the result is nonzero it records an event with `lstat_update` (0x4bc, a2=0x0). When the result is zero it reads a doubleword from the fixed address 0x9200000001030100 (0x4dc), calls `mutex_wait` (0x4f4), reads a second doubleword (0x504) and calls `lstat_update_time` (0x520, a2=0x2). The return at 0x4d0 is the `lstat_update` or `lstat_update_time` result. The two reads probably bracket the wait with a time, judging only from the `lstat_update_time` name.
  Reviewed: 2026-11-12
