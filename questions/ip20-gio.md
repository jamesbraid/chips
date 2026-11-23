# Indigo R4000 GIO bus and board facts: what the pages leave open

Question. Where do the held sources stop for the Indigo's GIO32 slots and for the processor, cache and memory facts of the board? The
settled parts are on [the GIO page](../platforms/ip20/gio.md) and [the board page](../platforms/ip20/README.md).

Status: **unknown** for everything below.

- **How the PROM tolerates a missing graphics board.** The 4.0.5D routines `Gr2Probe` (`0xbfc0e6f0`) and `Lg1Probe` (`0xbfc0f9a8`) issue
  plain loads. The PROM's fault handler has a "no fault" pointer; whether the callers (`0xbfc0f6dc`, `0xbfc0f814`, `0xbfc1034c`,
  `0xbfc1045c`) set it, or the probe's bus error is handled some other way, is not traced. Route: software now, read the callers and the
  PROM's bus-error path. Decides what a headless Indigo model must return.
- **Which `gio_err_stat` bit a reserved-region access sets.** A GIO time-out sets `time`; the MC specification says unused addresses
  in the physical map bus-error without naming a bit. Route: software now for any PROM or kernel path that prints it; hardware residue.
- **What `0x1f800000`–`0x1f9fffff` returns.** The MC decodes it as the upper half of the slot 1 window; the GIO specification reserves it.
  Route: a read on a board (a hardware residue; read-only and without side effects on an empty region).
- **The GIO clock of the R4000 board.** IRIX assumes 33 MHz for its burst and delay estimates; no source names the crystal. Route: the
  board schematic.
- **The secondary cache line size and the strapped primary line sizes of the Indigo R4000 module.** `Config.SB`, `IB` and `DB` are
  boot-mode strapping; the PROM assumes 16-byte primary lines. Route: a console print of the PROM's cache report on a real board, or the
  module's data sheet.
- **Whether an Indigo shipped with an R4000PC (no secondary cache).** Firmware handles `Config.SC` = 1; no capture or manual shows one.
  Route: a configuration list or price book for the Indigo R4000 family.
- **Which SIMM sizes SGI shipped for the R4000 Indigo.** The encoding accepts 256K×36 to 8M×36; the held sources give 4 MB and 32 MB
  SIMMs from users only. Route: the Indigo R4000 configuration guide or the field-replaceable-unit list.
- **Whether the MC's fourth bank has any use on the Indigo.** Three groups of sockets exist; the PROM probes four banks. Route: the
  board schematic.
