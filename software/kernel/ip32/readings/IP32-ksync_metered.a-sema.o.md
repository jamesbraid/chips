# Readings: `IP32/usr/cpu/sysgen/IP32boot/ksync_metered.a(sema.o)`

One entry per routine, filed here from the reading batches by binary.

- `_mraccess` in `IP32/usr/cpu/sysgen/IP32boot/ksync_metered.a(sema.o)` at 0x35b8
  It calls `wchanmeter` with `mrinfolist` and branches on the nonzero return. A nonzero return goes to `_get_timestamp` and then `mrmeter_entry` with tag 5, and a zero return goes through `mr_access`. The record's words at +0x138 through +0x170 are read and updated, with an `ll`/`sc` pair on +0x138, and `mrmeter_getentry` is called with a value read from +356 of that record. The name suggests metering of an access to a wait channel, but the facts do not show what is counted or what tag 5 means.
  Grade: inferred.
  Reviewed: 2026-11-12

- `_mrupdate` in `IP32/usr/cpu/sysgen/IP32boot/ksync_metered.a(sema.o)` at 0x36e0
  It makes the same `wchanmeter` call as `_mraccess` and branches on the return. A zero return falls through to `mr_update` at 0x3708. A nonzero return goes to 0x3790, which calls `mrmeter_entry` with tag 6 at 0x379c and `_get_timestamp` at 0x37a4. `_get_timestamp` is also called at 0x3718. It stores into the record at +0x140, +0x148 through +0x158 and +0x178, and a test on bit 0x4 at 0x3768 picks one of two branches, while the `lhu` and `sh` through an unresolved register are not identified.
  Grade: inferred.
  Reviewed: 2026-11-12
