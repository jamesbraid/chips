# Readings: `IP27/usr/cpu/sysgen/IP27boot/numa.a(mem_tick.o)`

One entry per routine, filed here from the reading batches by binary.

- `mem_tick` in `IP27/usr/cpu/sysgen/IP27boot/numa.a(mem_tick.o)` at 0x498
  **Inferred.** A per-CPU periodic tick. It calls `get_cpu_cnode` (0x4b0), then loads a record pointer from offset 8 of the `pdaindr` entry indexed by a0<<4 (0x4b4). In that record it stores halfwords at 0x758 and 0x75a, words at 0x764, 0x794 and 0x7a0 and doublewords at 0x770, 0x778, 0x780 and 0x788; it only loads from 0x768, 0x76c, 0x790 and 0x79c. A test of the word at 0x768 (offset 1896, at 0x4c4) selects between two paths. It calls `migr_periodic_bounce_control` (0x570, a1 from offset 1940) and `migr_periodic_unpegging_control` (0x6b4, a1 from offset 1952); the facts show branches before each call, on loaded bytes and fields. The branch at 0x5b4 compares two 64-bit values loaded from 0x9200000001030100. The branch at 0x5c4 compares the doubleword at offset 1904 with the doubleword loaded from +0x770, not a timestamp. The likely role is migration or accounting on each tick; the callee names only suggest what the counters mean.
  Reviewed: 2026-11-12
