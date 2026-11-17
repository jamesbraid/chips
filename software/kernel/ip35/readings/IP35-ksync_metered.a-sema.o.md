# Readings: `IP35/usr/cpu/sysgen/IP35boot/ksync_metered.a(sema.o)`

One entry per routine, filed here from the reading batches by binary.

- `_mraccess` in `IP35/usr/cpu/sysgen/IP35boot/ksync_metered.a(sema.o)` at 0x3890.
  The routine first obtains a record from wchanmeter (call at 0x38b0). When the record is nonzero (bne at 0x38b8) it
  first calls mrmeter_entry with a1 = 5 and its own arg1 as a2 (0x3994). It then calls mr_access (0x38c0) whether or
  not a record was found. When the record is nonzero it reads the counter at 0x9200000001030100 (0x38e4) and updates
  the record's fields at offsets +0x1c0 to +0x1d0 (the stores at 0x3910 to 0x391c sit behind the beq at 0x3908, the
  one at 0x390c does not), calls mrmeter_getentry with a2 = 5 (0x392c), and when that returns nonzero runs a load-
  linked and store-conditional loop on the word at +0x198 (0x3940 and 0x394c) that retries at 0x3950. Its return value
  is one of the results of mr_access or mrmeter_getentry. Role (from name): a metered access; the facts show the
  counter updates but not what is counted. Grade: inferred.
  Reviewed: 2026-11-12

- `_mrupdate` in `IP35/usr/cpu/sysgen/IP35boot/ksync_metered.a(sema.o)` at 0x39ec.
  This is the counterpart of `_mraccess`: it obtains the same record from wchanmeter (0x3a0c) and updates a different
  set of counters, at offsets +0x1a0 to +0x1d8. It calls mr_update (0x3a1c) and calls mrmeter_entry with kind code 6
  rather than 5 (0x3ac4). Whether the value tested with a7 at 0x3a90 is an input or a computed flag is not known from the
  facts. Grade: inferred.
  Reviewed: 2026-11-12
