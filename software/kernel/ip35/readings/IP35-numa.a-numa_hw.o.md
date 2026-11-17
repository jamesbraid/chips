# Readings: `IP35/usr/cpu/sysgen/IP35boot/numa.a(numa_hw.o)`

One entry per routine, filed here from the reading batches by binary.

- `migr_effthreshold_diff_set` in `IP35/usr/cpu/sysgen/IP35boot/numa.a(numa_hw.o)` at 0x0 (n64).
  Evidence grade: inferred.
  Exact binary: `IP35/usr/cpu/sysgen/IP35boot/numa.a(numa_hw.o)`.
  Range: 0x0-0x40 (64 bytes).
  It occupies 64 bytes.
  The `lh` at 0x18 loads 2 bytes from (sym(compact_to_nasid_node) + (a0 + a0)) +0x0.
  The `sd` at 0x3c stores 8 bytes to ([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21) -0x6dfffffffe03ffc0.
  The return at 0x38 has v0 = ([(sym(compact_to_nasid_node) + (a0 + a0))]:2 << 0x21)+0x9200000001fc0000.
