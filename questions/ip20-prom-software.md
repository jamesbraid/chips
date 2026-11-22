# Indigo R4000 PROM software: what the first reading left open

Question. What does the Indigo R4000 (IP20) PROM 4.0.5D Rev A do in the places the first reading could not settle? The settled parts are on
[the IP20 PROM software page](../platforms/ip20/prom-software.md).

Status: **unknown** for everything below.

- **Little-endian continuation.** Whether the restart store of `0x10000` at MC `+0` always takes effect, so that the NT default table
  (flag at `0xa8741070`) is never consulted. Tried: every caller of the flip routine and every writer of the flag. Route: an R4000 manual page for
  Config.BE and the mode stream, the MC specification, or a run on a machine configured little-endian.
- **Why `0x8400`.** What EEPROM bit 10 does (bit 15 is the byte-order bit by inference). Route: the same word in the Indigo2 images, or an R4000 mode-stream description.
- **Low alias of RAM.** How far above physical `0x2000` the bank-0 alias at physical 0 reaches, and whether NT's 6 MiB requirement is met. Route:
  the MC address-decode description, or the shipped IRIX kernel binary's mapping of low memory (binary only, not source).
- **Progress strings.** What prints "Initializing primary/secondary caches." to "All initialization and diagnostic completed." (`0xbfc42b60`..`0xbfc42c34`);
  no address pair or data word refers to any of them. Route: a boot capture of this PROM, or a trace of the print routine `0xbfc351e8` callers for computed pointers.
- **Empty path keys.** Whether the parser accepts `scsi()disk(1)rdisk()partition(1)`; the key reader `0xbfc3adfc` was not read to its end.
- **Descriptors above 128 MiB and in the second window.** No code that adds them was found in `0xbfc081fc`; read callers of the add routine `0xbfc0af40`.
- **`netpasswd_key` index overrun.** The table at `0xbfc45c40` has 24 words; record 24 reads index 24. Route: only observable with the flag set.
- **Board field at `0xbfbd0000`, HPC1 and graphics accesses.** Roles of the bits `0x7000` and of the offsets listed in the device map that were not decoded.
- **Private ARC vector.** The ten slots' roles.
