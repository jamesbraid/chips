# Open questions

Each entry: the question, the routes already tried, the next route. When answered, the fact moves into its
chip page and the entry is deleted.

- **Chip numbering inside the shared Bridge-family accessors.** The accessors choose among four chips by a
  type field and by the identification word's part number. Which chip is which is inferred from the part
  numbers and offsets matching the Bridge, XBridge and PIC layouts; not read from a named source.
  Next: the XBridge and Crossbow specifications' identification-register sections (page images).
- **TIOCP.** Whether any product in scope carries it is not established. Tried: its part numbers appear only
  in the shared accessors. Next: Linux `pci-xtalk-bridge.c` and its history for the platform that uses it.
- **Xbow: the PROMs' large crossbar routines.** The census seeds only the small routines it could tie to the
  Crossbow (link-usable tests, link reset, error save, the IP30 interrupt service). Routines that touch the
  link-block displacements and were not read: IP27 PROM `0x1fc444b0`; I/O-board PROM `0x11c1d4ac`, `0x11c21c58`,
  `0x11c3250c`, `0x11c517f4`, `0x11c52f80`, `0x11c5ce08`; IP35 PROM `0x1fc4ca98`; IP30 PROM `0xbfc4528c`,
  `0xbfc48038`, `0xbfc48384`, `0xbfc75020`. Some may be Bridge-family code: the Bridge shares the widget-common
  offsets 0x4 to 0x5c and has registers from 0x100 up, so a displacement pattern alone does not say which chip.
  They take their window pointer from a record field or a global, which the scan does not follow. They hold the
  link credit and arbitration setup, the diagnostics and any write of widget 0 control, packet time-out, LLP control and
  arbitration reload. Next: read each by hand, or constant-fold the record fields; settle the input-buffer flush
  register, the packet time-out and arbitration reload values and the NIC register.
- **Xbow: interrupt vector assignment.** IRIX writes the vector into interrupt destination upper from the interrupt
  layer at run time; which number each product uses is not in `xbow.o`. Next: the interrupt allocation code of the node
  controller and HEART, and any PROM routine that programs the register.
- **Xbow: write-error behaviour.** The graded answers (what sets each error bit, what is latched on a refused register
  write, how the vector is chosen) are in chips/xbow/README.md, "Error reporting for a refused or timed-out register
  write". Open there: what a link-level time-out latches, how a 4-byte access reaches a double-word-only register
  file, a second error's effect, and the registers of the PXBOW part.
- **Hub, Bedrock, IOC3, IOC4 inventories.** Censuses not run (stub configs). Next: write each config's
  seeds (see HAIKU-BRIEF.md) and run `tools/run.sh`.
- **Model of a PROM's window base.** A PROM builds its window pointer at run time; the census recovers a
  pointer only where an identity-register probe shows it. Next: constant-fold the PROM's address setup.
- **IP35 reset window.** The routing rule that returns boot-PROM bytes for uncached memory-space fetches of physical
  0x1fc0xxxx after bank 0 is enabled, and whether any write ends it, are not visible in the PROM. Tried: full read of
  the reset, memory and jump-to-RAM path. Next: see [docs/questions/ip35-reset-window.md](questions/ip35-reset-window.md).
- **Literal-pool bases (PIC and Bedrock objects): settled by audit.** Every object's options record carries its
  gp (0x7ff0 for `kernel.o`, 0x7800 for the eleven others checked, including `pic.o`), and in each of them the
  lowest `.lit8` displacement equals minus gp and the pool is exactly covered by the displacements used, so
  `gp: auto-min` gives the stated base. The constants read this way can be labelled established where the function
  is read in full. Remaining: the census tool could read the gp from the options record instead of inferring it.
- **Census scanner faults found by the audit.** (1) A load or store whose displacement is added at run time through
  a `movz`-selected constant or a loop counter is recorded at the window base or at one iteration's slot
  (`dump_error_spool`, `hub_error_clear`, `part_discovery`); the families they build need their bounds read from the
  code. (2) A site in a routine with no symbol is credited to the preceding named routine (the three `+0x1000090`
  stores). (3) The IP35 PROM image is split after each return, so a block that is jumped to from earlier in the
  same routine (the PIC branch of the interrupt-register clear at 0xc00000001fc41f38) is missed while the other
  branch is labelled PIC. Next: do not split a PROM pseudo-function at an address a branch from the previous one
  reaches, and fold `movz` of two constants into two sites.
- **HEART refused-access errors.** What sets CAUSE bits 40, 41 and 42 (bad system read, bad system write, PIU
  register access error), what a failed or timed-out processor store latches, and which of the level 4 vectors 51 to
  63 each error raises. Known: the latch registers and decode paths, the widget error type bits (store timeout is
  type bit 2), the vector formula for widget errors. Unknown: the triggers and the cause-to-vector mapping. Tried:
  kernel error handler and probe routines, PROM, monitor decode tables. Next: the stripped diagnostic's PIU access
  and widget error tests, and the PROM error dump. Entries: [chips/heart/README.md](../chips/heart/README.md#open).
- **HEART registers no held code reaches.** Eleven registers appear only in the diagnostic's register table (SDRAM mode,
  memory refresh, flow-control timers, MicroLAN divider and control, compare, widget status, control, link layer,
  target flush); TRIGGER and SYNC are reached but unread. Valid end state unless a routine setting them is found.
- **PIC error and interrupt service.** `pcibr_error_dump` and `pcibr_error_intr_handler` in `pcibr.o` and the
  PIC branches of the error accessors are not read. Next: read both in full and fill the error and interrupt
  sections of chips/pic/README.md.
- **PIC direct map and revision-1 steps.** `pcibr_directmap_init` is not read; what the revision-1-only
  writes (control bit 29 test, request timeout 0x750, enable bits 39 and 9, response buffer bits) fix is unknown.
- **PIC +0x18000 banks.** Three banks of 256 doublewords are cleared at attach; their contents are unknown.
- **Bedrock block boundaries and indexed families.** Registers are listed by offset; membership of the
  processor interface, memory, I/O, network and local blocks is inferred from routine-name prefixes only.
  Many accesses add a node or block index the scan does not follow. Next: read the index arithmetic in
  `hub_error_init`, `hub_error_clear`, `intr_connect_level`.
- **Bedrock PROM and second window.** The IP35 PROM builds its window base at run time (no sites yet) and the
  0x90000000_18xxxxxx window of `hubspc.o` and `nic.o` is uninterpreted.
- **Harness limits.** `scripts/run_routine.py` replaces calls with `v0 = 0` and has no global data, so a routine
  that reads a table by gp (`pcireg_int_ate_set`, `pcireg_force_always_set`, `pcireg_intr_addr_vect_set`) ends in
  an unmapped read; the routines that touch only the chip record run to completion.
- **Scanner fixes after the first audit.** Since that audit the scan reads gp from each object's options record
  (the auto-min rule is a flagged fallback and no object needed it), alternatives chosen by a conditional move
  are kept as separate conditional sites, loop counters are widened to an indexed site instead of one site per
  pass, and routines are cut by control flow (after a return that nothing branches to, and at call targets)
  rather than by symbol or by every return. Fixed since: the PROM's non-PIC 32-bit stores are no longer
  labelled `pic`, and routines following an unconditional branch or reached only as a delay-slot duplicate are
  cut or merged by control flow. Remaining: large code spans with no return
  (PROM data disassembled as code) stay single routines.
