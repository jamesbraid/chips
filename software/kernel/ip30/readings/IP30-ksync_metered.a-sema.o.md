# Readings: `IP30/usr/cpu/sysgen/IP30boot/ksync_metered.a(sema.o)`

One entry per routine, filed here from the reading batches by binary.

- `_mraccess` in `IP30/usr/cpu/sysgen/IP30boot/ksync_metered.a(sema.o)` at 0x3890 (n64).
  Grade: inferred.
  It looks like a metered access path for a kernel synchronisation object, judged from the callee names. It calls `wchanmeter` on `syncinfo`. When that call returns nonzero it first calls `mrmeter_entry` (0x3974) with the constant 5 and the doubleword at 0xffffffffaff20000 among its arguments. Every path then calls `mr_access` (0x38c0), and when the meter pointer is nonzero it follows with `mrmeter_getentry` (0x391c, constants 5 and 1). The meaning of class 5 and of the doubleword is inferred from the callee names.
  Reviewed: 2026-11-12

- `_mrupdate` in `IP30/usr/cpu/sysgen/IP30boot/ksync_metered.a(sema.o)` at 0x39cc (n64).
  Grade: inferred.
  It is the update counterpart of `_mraccess`. It calls `wchanmeter` on `syncinfo`. When that returns nonzero it first calls `mrmeter_entry` (0x3a94) with class 6, then reads the doubleword at 0xffffffffaff20000 and saves its low word. It then calls `mr_update`, and when the meter pointer is nonzero it updates fields from +0x1a0 to +0x1d8 of the meter record. Its return value is either the result of `mr_update` or an unresolved value, and the names are the main evidence for what it measures.
  Reviewed: 2026-11-12
