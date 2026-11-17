# Readings: `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(mutex.o)`

One entry per routine, filed here from the reading batches by binary.

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(mutex.o)` at 0x5f0
  **Inferred.** A one-shot try-lock on the word at a0. It loads the doubleword at the fixed address 0xffffffffffffc020, calls `compare_and_swap_ptr` (0x5fc) with a1=0 and a2 from the global at -0x3fe0, and branches on the result at 0x604. The return at 0x610 is a plain 0 or 1 flag, and there is no retry loop.
  Reviewed: 2026-11-12

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_named.a(mutex.o)` at 0x6e8
  **Inferred.** The blocking form of the same compare-and-swap lock. It loads from the fixed address 0xffffffffffffc020, calls `compare_and_swap_ptr` (0x6fc), and returns on success at 0x70c. On failure it calls `mutex_wait` (0x718) with its own a0 and a1 and jumps back to the return at 0x70c, so the return value is either the compare result or the `mutex_wait` result.
  Reviewed: 2026-11-12
