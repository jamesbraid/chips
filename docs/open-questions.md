# Open questions

Each entry: the question, the routes already tried, the next route. When answered, the fact moves into its
chip page and the entry is deleted.

- **Chip numbering inside the shared Bridge-family accessors.** *[route: software now]* The accessors choose among four chips by a
  type field and by the identification word's part number. For Bridge (part `0xc002`), XBridge (`0xd002`) and PIC
  (`0xd102`, `0xd112`) the part numbers and the 32-bit and 64-bit layouts match the public Linux and OpenBSD constants
  (chips/bridge/README.md, "Against the public drivers"), so those three are settled. Still open: the type 3 and part
  `0xe000`/`0xe010` chip (see TIOCP). The part number `0xd100` that `xbow_widget_present` tests is not a Bridge-family part: the routine reads it from the word at +4 of the block it is given and then reads per-link words at +0x13c from a 0x40 stride, so it names the crossbar's own identification (inferred).
  Next: the Crossbow probe routines' callers, and the public Linux `pci-xtalk-bridge.c` history for the later part
  numbers.
- **Bridge and XBridge: revision 2 attach path.** *[route: software now]* `xbridge_attach` takes a separate path for identification
  `revision | part << 4` equal to `0xc0022` (at `0xc000000000070d98` of the IP27 `unix`) that builds the interrupt-enable
  mask differently. The path ORs a constant into the mask and ANDs a literal; the intent is not decoded. Next: read the
  path with the literal pool resolved and compare with the revision-3 path.
- **Bridge and XBridge: the interrupt device register at attach.** *[route: software now]* IRIX writes `0xffffffff`; the public Linux and
  OpenBSD drivers write 0. Neither says why, and no shipped routine reads the reset value. Next: the pin-to-device
  assignment in `pcibr_intr_alloc` and what the all-ones value does before any pin is assigned.
- **Bridge and XBridge: response buffer registers.** *[route: software now]* `0x280` and `0x288` are accessed through `pcireg_rrb_*`; only the
  enable constant `0x8` and the index-to-offset mapping are read. The field layout (enable, virtual channel, device) is
  the public drivers' and was not derived. Next: `pcibr_rrb_alloc`, `pcibr_alloc_all_rrbs` and `pcibr_rrb_check`.
- **Bridge and XBridge: registers above 0x298.** *[route: software now; PROM search; an accepted end state if none is found]* Whether the XBridge has registers between `0x2a0` and `0x10000`
  (the census reaches none and the public headers name none). Valid end state unless a routine that touches them is
  found. Next: the IP27 PROM and I/O-board PROM, which the scan could not resolve.
- **Bridge and XBridge: the IP27 and I/O-board PROMs.** *[route: software now]* The window base is built at run time and neither PROM has
  symbols, so the census holds no access from them. Next: constant-fold the PROM's widget-window setup, or read the
  I/O-board PROM's bridge probe by hand.
- **Bridge and XBridge: device register bits.** *[route: software now]* Only the pair `0x180000` (`pcibr_endian_set`) and the IP30 PROM's
  `0x1004` are read; the other bits the flags routines pass are derived from their callers at run time. Next:
  `pcibr_device_flags_set`'s callers and `pcibr_slot_addr_space_init`.
- **TIOCP and TIO.** *[route: missing source: Altix-era headers in the uninitialised linux-2.5.40 submodule; the product history needs a published document that is not held]* Whether any product in scope carries a TIOCP is not established, and no TIO code is held: the
  names `tio_init_xswitch_widgets` and `Tio_brick_map_widget` are in the debug name tables of the IP35 `kernel.o` with no
  text symbol, and the software enumeration `pciio_asic_type_e` has a TIOCP value (chips/tiocp/README.md). Tried: the
  census of the shared accessors, a string and symbol search of every IP27 and IP35 object and PROM image. Next: the
  public Altix-era headers in the pinned older Linux tree, and `pci-xtalk-bridge.c` in current Linux, read after the
  binary reading.
- **Xbow: the PROMs' large crossbar routines.** *[route: software now]* The census seeds only the small routines it could tie to the
  Crossbow (link-usable tests, link reset, error save, the IP30 interrupt service). Routines that touch the
  link-block displacements and were not read: IP27 PROM `0x1fc444b0`; I/O-board PROM `0x11c1d4ac`, `0x11c21c58`,
  `0x11c3250c`, `0x11c517f4`, `0x11c52f80`, `0x11c5ce08`; IP35 PROM `0x1fc4ca98`; IP30 PROM `0xbfc4528c`,
  `0xbfc48038`, `0xbfc48384`, `0xbfc75020`. Some may be Bridge-family code: the Bridge shares the widget-common
  offsets 0x4 to 0x5c and has registers from 0x100 up, so a displacement pattern alone does not say which chip.
  They take their window pointer from a record field or a global, which the scan does not follow. They hold the
  link credit and arbitration setup, the diagnostics and any write of widget 0 control, packet time-out, LLP control and
  arbitration reload. Next: read each by hand, or constant-fold the record fields; settle the input-buffer flush
  register, the packet time-out and arbitration reload values and the NIC register.
- **Xbow: interrupt vector assignment.** *[route: software now]* IRIX writes the vector into interrupt destination upper from the interrupt
  layer at run time; which number each product uses is not in `xbow.o`. Next: the interrupt allocation code of the node
  controller and HEART, and any PROM routine that programs the register.
- **Xbow: write-error behaviour.** *[route: software now; proposed: the link time-out and second-error routines in the held images; the PXBOW registers need a PXBOW object, none is held]* The graded answers (what sets each error bit, what is latched on a refused register
  write, how the vector is chosen) are in chips/xbow/README.md, "Error reporting for a refused or timed-out register
  write". Open there: what a link-level time-out latches, how a 4-byte access reaches a double-word-only register
  file, a second error's effect, and the registers of the PXBOW part.
- **CRIME: identification register upper word.** *[route: software now]* `get_crimerev` in the IP32 kernel object reads bits 63:32 of the
  identification doubleword and returns 0x13 for 1 and 0x14 for anything larger, while the specification defines only
  bits 7:0 and the PROM and diagnostic compare the low word with 0xa0 and 0xa1 only. Tried: the kernel, PROM,
  diagnostic and monitor censuses; the public Linux and NetBSD revision constants (0x11, 0x13, 0x14) match the kernel's
  return values but not how the kernel derives them. Next: the other IP32 objects that read the register (the
  graphics driver's identification probe and its callers), and the history of the public drivers' revision constants.
- **CRIME: CPU error status location on CRIME 1.5.** *[route: software now]* The specification puts it at 0x4048 for 1.5 and 0x48 for 1.1; every
  IP32 routine uses 0x48. Next: the graphics driver's error paths and any public source that
  reads the status register by its 1.5 address.
- **CRIME: write-error behaviour.** *[route: software now; hardware residue: the bus-level exception and the failed-store latch on the part]* The graded answers (what sets CPU error status bit 2, what a failed or timed-out
  uncached store latches, which interrupt bits fire, how the kernel detects a failed store) are in chips/crime/README.md,
  "Write-error questions". Open there: which addresses are "invalid", whether a read and a write differ in the
  three-bit layout, whether a failed store also takes a bus error exception, which CRIME bit the MACE PCI error
  handler is attached to, second-error handling, and whether the interrupt asserts with its enable bit clear.
- **CRIME: registers no scanned image reaches.** *[route: software now; proposed: constant-fold the PROM's bank-sizing addresses once the IP32 PROM is unpacked; the stripped diagnostic is a missing binary]* Refresh counter (0x248), memory control bit 1 (replacement select),
  the JUICE field (control bits 7:5), the watchdog's operation (only a store of 0), and the contents of 0x58 and 0x270.
  Valid end state unless a PROM or diagnostic routine that sets them is found. The PROM's bank-sizing loops use
  indexed addresses, so the census records only their bases, and the diagnostic's CRIME routines are stripped.
- **Bedrock, IOC3, IOC4 inventories.** *[route: software now; stale in part: the IOC3 and IOC4 censuses have run, Hub and Bedrock have census output, and Bedrock has no accessor seeds]* Censuses not run (stub configs). Next: write each config's
- **MACE: write- and read-failure behaviour.** *[route: software now; hardware residue: an ISA device that never answers, since the specification gives no timeout]* The graded answers (what sets each PCI error flag, what the error
  address register latches, which interrupt fires) are in chips/mace/README.md, "Error reporting for a refused or
  timed-out CPU access". Open there: what sets flags 26, 24 and 23 and what a refused memory or I/O window access
  sets; whether a posted write's failure differs from a read's at the CPU; whether any MACE address returns the read
  response error bit; what a PIO to an ISA device that never answers does (the specification gives the peripheral
  controller no timeout or error flag); a second error's effect on the latched address. Next: CRIME's own error
  registers (the CRIME census), and the compressed IP32 PROM's PCI and ISA probes once it can be read.
- **MACE: the compressed IP32 PROM.** *[route: software now; unlocks the MACE and CRIME PROM entries]* `ip32prom.image` holds three segments (`sloader`, `post1`, `firmware`) with
  an eight-byte `PROM` header and `SHDR` records at `0x108`, `0x4108`, `0x4508`, `0x9308`; their bodies are not plain
  code. The census therefore holds no PROM access. Tried: the Xbow-era container unpacker (a different layout);
  string search (only the `sloader` and `post1` banner and a few message strings are readable). Next: read the
  decompression routine from the `sloader` body (the one segment small enough to read by hand) and unpack
  `firmware` with it.
- **MACE: blocks reached through run-time pointers.** *[route: software now]* The Ethernet driver (`if_me.o`), the 16550 serial driver
  (`sio_ti16550.o`, `serialio.o`), the video code (`mvp.o`) and the DP-RAM and parallel context registers take their
  addresses from records. The census has three Ethernet rows (from `ide`) and one video row. Next: constant-fold the
  record fields, or read the attach routines by hand and add the registers to the page.
- **MACE: revision strap at `0x310000` bit 4.** *[route: missing source: the NetBSD driver is in an uninitialised submodule; the entry also says NetBSD was already read, so drop it if so]* `pckm_attach` sets a `mace_rev` flag from bit 4 of the ring base and
  reset register, which the specification calls reserved; the PS/2 code treats status bit 6 differently when the flag
  is 0. Tried: the specification's PS/2 and ISA chapters, Linux and NetBSD (neither reads it). Next: the specification
  revision history pages (host bridge revision 0 versus 1 notes) and the NetBSD PS/2 driver for the same quirk.
- **MACE: video output `0x200058` bits 35:32.** `mvpprobe` returns bits 35:32 of the 64-bit read; the specification
  defines bits 18:0 of the hardware configuration register. Next: the specification's video chapter text.
- **MACE: `0x304018`.** The Ethernet driver writes and reads this address as a flush target. It is not in the
  specification's register list. Next: confirm the block repeat on the peripheral controller's audio block.
- **MACE: calendar-clock user RAM spacing.** `read_dallas_nvram` reads one byte apart from `0x3a0e08` while every
  other register of the block is 256 bytes apart. Next: read the writer and its callers.
- **MACE: Linux I2C offsets.** `struct mace_i2c` in the Linux header puts control and data at 8 and 0x10; IRIX and the
  specification use `0x10` and `0x18`. Next: the Linux I2C driver that uses the structure, to see which offsets it
  reaches in practice.
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
- **Hub PI write-buffer errors: which fault sets which.** PI error pending bits 4 to 7 (write response block timeout and write
  error) and 18 and 19 (error during spool), the status 0 and 1 latches (address, command, type 0 write error, 1 partial write error,
  3 timeout), the clear sequence and the interrupt (cause level 6) are read from the kernel (graded entries in
  [chips/hub/README.md](../chips/hub/README.md#error-reporting-for-a-refused-or-timed-out-uncached-write-and-read)). Unknown: the
  transaction that raises each bit, whether a 4-byte store differs, the unit of the CRB time-out (`0x30`, `0x38`), the processor line
  that cause level 6 is, the level number the I/O error interrupt is given, and whether reading the status 0 clear alias
  (`0x438`, `0x458`) clears it. Tried: the error initialisation, the PI, I/O and network handlers, the spool and stack routines,
  the shipped decode text. Next: `hub_ioerror_handler`, `handle_uncac_buserr` and `hubni_error_handler` in full, the trap dispatcher
  that indexes the cause table, `intr_heuristic`.
- **Hub registers with no named role.** `0x2000c8`, `0x2000d0`, `0x2000d8`, `0x2000e0`, `0x400160`, `0x400190` and `0x4002c8` are
  touched by `per_hub_init`, `hub_ifdr_fix_value`, `hub_piomap_alloc`, `mlreset` and `hub_error_devenable` and are not in the public
  headers. Next: read those routines in full. The I/O-board PROM is not in the Hub census.
- **Hub directory error labels.** The shipped decode text labels directory error bit 61 uncorrectable and bit 63 correctable; the
  single-bit-error handler and the public header have them the other way round. Next: read `log_md_errors` and the decode routine
  `show_hub_md_err` in full.
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
- **Bedrock refused widget read: what the silicon latches.** Established: a read that gets a timeout or error reply
  is typed in PI error status 0 (type 3 timeout; read types 1 to 3) and the kernel prints "Read timeout, physaddr".
  Inferred: no pending bit exists for it; the exception is the bus error and the spool entry carries the address.
  Unknown: whether status 0 and the spool entry are both written for a read, which of the CRB error codes (5, 6) a
  refused read of a Crosstalk widget produces, and what the processor sees (data bus error or a zero return). No
  shipped code distinguishes these. Next: read `handle_io_buserr` and `hub_ioerror_handler` in full, and the PROM
  error dump.
- **Bedrock error status clear semantics.** Established: the kernel writes all ones to PI `0x438` and `0x458` and zero
  to `0x448` and `0x468`, and writes the handled bit back to the pending register. Unknown: whether those four
  are clear-on-read as in the public Hub headers, whether the pending register is write-one-to-clear, and what a
  second error does to a status whose valid bit is still set beyond setting overrun (bit 62). Route: none from
  software; a measurement or a published erratum.
- **Bedrock error spool entry layout.** Established: entries are 8 bytes and `get_matching_spool_addr` matches the
  address (status 0 bits 61:25 `<< 3`) and size; the status 0 field names are shared. Unknown: the entry's own
  layout (the Hub error stack packs the fields differently), what writes an entry, and the units of the size
  register (`4096 << (n - 1)`). Next: read `process_error_spool`, `huberror_process_stack_entry` and
  `hubpi_spool_get_next` in full.
- **Bedrock pending bits 25 to 34 and fatal selection.** Established: names from the kernel's table and the fatal
  and miscellaneous masks. Unknown: what sets bits 29 to 34 beyond their names (crossbar data cycle count, intervention
  state, state-pending timeout), and why bit 24 is ORed into one interrupt mask only (the first one written).
- **Bedrock protected-region replies.** Unknown: which status 0 type or CRB error code a protection violation
  produces, and what the strings "Protection error response" and "Vector response timeout" index. Next: find
  their table's users in `kernel.o` and read the memory/directory error decode.
- **Bedrock interrupt numbers.** Established: PI error handler on cause line 6, network interface error on vector
  126. Unknown: the II error level (chosen at run time by `intr_heuristic`), and whether cause line 6 is the Cause
  IP6 bit. Next: the interrupt allocator and the CPU exception vector in the PROM.
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
- **IOC3: why interrupts are polled while the top interrupt bits are enabled.** `ioc3_write_ireg` keeps interrupt bits 22:0 out
  of the hardware enable register and polls them every tick while bit 27 or 28 is enabled; the mechanism is read in full
  (chips/ioc3/README.md), the reason is in no string the objects carry. Next: a hardware note for the part; Linux and OpenBSD
  have no equivalent.
- **IOC3: UART byte lane.** IRIX addresses the line-control register at UART+3 (the 16550 index as the byte offset); Linux's 8250
  glue uses `offset ^ 3` and so reads it at UART+0. Which lane the hardware presents, and whether a bridge byte-swap setting
  explains the difference, is not settled. Next: the PIO mapping flags the IRIX drivers pass and the Linux bridge setup.
- **IOC3: Ethernet inter-frame gap table, parallel-port registers, error address words.** The three table words `ef_ioc3init`
  stores to the transmit control register sit in the object's data and are not extracted; the parallel-port DMA words
  (`0x84` to `0x98`) and super-I/O registers (`0x20151` to `0x2015a`) are touched but their routines are not read; the
  configuration words `0x40` and `0x44` are read and written by `ioc3_error_handler`, read for accesses only. Next: resolve the
  data relocations; read `plp_dma`, `plpintr`, `plp_reset` and the error handler.
- **IOC4: the word at `0x24`.** `ioc4_attach` clears bits 3:0 of it when the revision byte is below 79 and the bus-speed query
  returns 1; the public header calls it unused. Next: `pciio_businfo_bus_speed_get` and any string the attach carries.
- **IOC4: the ATA registers.** The command, control and DMA block roles are inferred from index order and the public driver.
  `xide_intr_clear` reads index 4 of the interrupt block (offset `0x10`) after index 0 where the public driver's error address
  high word is at `0x4`. Next: read `xide_pktDMA_start`, `xide_dma_init` and `xide_intr_clear` in full.
- **IOC3 and IOC4: reset values and the per-port tables.** No routine reads a reset value; the mode-select pin numbers and
  serial configuration records are static data not extracted. Next: extract the data sections through their relocations.
- **CRIME rendering engine: field layouts the specification does not print.** The pixel pipeline's depth function, stencil
  mode and stencil mask, the blend constant colour and the antialias coverage word have no field table in the 1.5 specification
  pages, and the antialias slope is given as 2.12 in one place and 2.14 in another. The loaders copy these words unchanged, so
  the shipped kernel does not decide them. Routes tried: the specification's register map and chapter text, the shadow loaders'
  copy order. Next: a shipped renderer or X server module that builds the words, and the public CRIME frame-buffer driver sources.
- **CRIME memory transfer engine: the null register and the tile table formats.** No routine in the IP32 member objects
  writes `MTE.null` (`0x3070`), and no routine read builds a texture-TLB or clip-ID-TLB entry, so the entry bit layouts and
  the register's effect are open. The specification prints no entry layout. Routes tried: the shadow loaders, the clear,
  swap and copy routines, and a displacement scan of all 702 member objects. Next: the PROM, diagnostic and monitor
  images, an X server module, and the public CRIME frame-buffer drivers.
- **Router scan-chain tunnel (IP35).** `read_rr_reg` asks the L1 to shift 197 bits through the router chain and keeps 128 of
  them; established: the command layout, the bit reversal, the iRouter framing and the address arithmetic
  (chips/scan/README.md). Unknown: which router state the selector `2*(port-1)` and `2*(port-1)+1` names, what the 128 bits
  hold, the L1 task value `0xf` that the scan command is addressed to (the public header names tasks 1 to 6), what the `state`
  values 0, 1 and 16 stand for, and whether the router's JTAG controller registers (public `RR_LB_TO_L2`, `RR_L2_TO_LB`) are the
  chip side of this path. Tried: the held kernel, the `jtagio.a` and `irouter.o` objects, the `l1_command.o` task census, the public
  `l1.h` and `router.h`. Next: the L1 command-path callers of task `0xf` in `l1_command.o`, and any diagnostic or monitor image that
  names the scan operations (none found in the IP35 boot set).
