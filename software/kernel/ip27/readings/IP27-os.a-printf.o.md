# Readings: `IP27/usr/cpu/sysgen/IP27boot/os.a(printf.o)`

One entry per routine, filed here from the reading batches by binary.

- `do_mprboot` in `IP27/usr/cpu/sysgen/IP27boot/os.a(printf.o)` at 0x26bc
  **Inferred.** A shutdown or reboot helper for a multi-CPU machine, judged from its flow. It takes `mutex_spinlock` on `panicbuf` (0x26f0) and releases it at 0x2708. It checks `maxcpus` at 0x26d8 and the global `power_off_flag` at 0x26e0, and compares a halfword in the master PDA with a value at -0x3be0 (0x2724). It polls a 64-bit timestamp from 0x9200000001030100 while calling `us_delay` with 0x186a0 (0x2754), flushes the console buffer through `conbuf_flush` with a0=3 (0x2774), and reports with `cmn_err` at severity 6 (0x27bc). The name suggests an MP reboot path, and the callees fit that reading only loosely.
  Reviewed: 2026-11-12
