# Readings: `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)`

One entry per routine, filed here from the reading batches by binary.

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x5f0
  **Inferred.** The metered counterpart of the try-lock at 0x35c. It calls `wchanmeter` (0x604, with `mutexinfolist` in `a1`) and makes the same single `compare_and_swap_ptr` call on the lock word (0x618). When `wchanmeter` returns nonzero it updates the word at `meter+0x38` with an `ll`/`sc` pair (0x638, 0x6a4) on both paths of the swap result. On the path where the swap result is nonzero it also stores to `meter+0x3c`, `+0x40`, `+0x48`, `+0x50` and `+0x70`. The facts do not state what the meter fields hold; reading `wchanmeter` as a per-wait-channel lookup is from its name.
  Reviewed: 2026-11-12

- `mutex_trylock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x5f0
  **Inferred.** It calls wchanmeter [call 1]. It then calls compare_and_swap_ptr with a0 at entry and a1 = 0x0 [call 2]. When the swap result is zero it takes the branch [@0x620 taken zero] to a separate path. Its return value is one of 0x0 and 0x1 [@0x690].
  Role (from facts): a compare-and-swap attempt [call 2] made after a metering call [call 1], returning one of two values [@0x690].
  Reviewed: 2026-11-12

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x760
  **Inferred.** The metered counterpart of the lock at 0x454. It gets the meter from `wchanmeter` (0x778) and calls `compare_and_swap_ptr` on the lock word (0x79c). The two outcomes of that call take different paths. When it returns nonzero and the meter is not null, the routine increments `meter+0x28` with an `ll`/`sc` pair (0x7c4) and stores to `+0x30`, `+0x40`, `+0x48`, `+0x50` and `+0x70`; it loads from `+0x60` and `+0x5c`. When the compare at 0x828 falls through it also stores to `+0x60`, `+0x68` and `+0x5c`. When the swap returns zero and the meter is not null (0x84c), it increments `meter+0x28` with a second `ll`/`sc` pair (0x858) and then calls `mutex_wait` (0x874) with its own `a0` and `a1`. The value returned at 0x844 is the `compare_and_swap_ptr` result, the `mutex_wait` result or a value the facts leave unresolved, not a fixed 0 or 1. Which outcome means the lock was taken, and what the meter fields hold, are not established.
  Reviewed: 2026-11-12

- `mutex_lock` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x760
  **Inferred.** It calls wchanmeter [call 1]. It then calls compare_and_swap_ptr with a0 at entry and a1 = 0x0 [call 2]. When the swap result is zero it takes the branch [@0x7a4 taken zero] to a path that calls mutex_wait with a0 and a1 at entry [call 3, @0x7a4 taken]. On the nonzero side, when the wchanmeter result is nonzero [@0x7ac fall], it stores a word to the record found through that result [@0x7e8].
  Role (from facts): a lock acquire that meters first [call 1], then tries a compare-and-swap [call 2], and waits [call 3] when the swap result is zero [@0x7a4 taken zero].
  Reviewed: 2026-11-12

- `mutex_wake_r` in `IP27/usr/cpu/sysgen/IP27boot/ksync_metered.a(mutex.o)` at 0x13c8
  **Inferred.** A 684-byte routine on a mutex record passed in `a0`. It calls `wchanmeter` (0x13ec). It takes the nested bit lock at offset 132 of the record at `[a0+8]` (`nested_bitlock` at 0x14cc), calls `thread_unblock` on `[a0+8]` with 2 (0x150c) and calls `mutex_bitunlock` on the same address (0x151c). Later it takes `nested_bitlock` at offset 132 of the record named by the global at `-0x3fe0` (0x1608), calls `drop_inheritance` (0x1618) with that global in `a2`, and calls `nested_bitunlock` (0x1624). It calls `getsr`, `isspl0`, `splhi`, `kpswtch` and `splx` (0x1530 to 0x1558) on one path and `splx` again (0x15f4); the facts do not show what the calls return or why. The `_r` suffix and the meaning of the meter updates are not shown by the facts. Role (from name): waking a thread blocked on a mutex.
  Reviewed: 2026-11-12
