# Open questions

Each entry: the question, the routes already tried, the next route. When answered, the fact moves into its
chip page and the entry is deleted.

**Triage (2026-11-01).**

Each entry carries a route tag: `software now` (the next step is in software, and the binaries it needs are in `root/`), `missing source` (the route needs a public source tree or a published document that this clone does not hold), `missing binary` (the route needs a payload that is not held), or `closed` (settled). A `hardware residue` note marks the part of an entry that no software route reaches. Those notes are recorded, not scheduled.

Counts for the 55 entries:

- **Software now: 48.** Seven of these also carry a hardware residue.
- **Missing source: 5.** The public trees (`linux`, `linux-2.4.37`, `linux-2.5.40`, `linux-ip30`, `linux-ia64`, `netbsd`, `openbsd`) are uninitialised submodules in this clone, and the published documents for the IOC3 and Bedrock items are not held.
- **Missing binary: 1.** The CRIME rendering-engine entry needs a renderer or X server module that is not held. (The diagnostics `ide.IP30` and `ide.IP32` and the monitor `symmon.IP32` are held; they are stripped, so reading them is software work without symbols.)
- **Closed: 1.** The literal-pool entry. Move its fact to the chip page and delete the entry.
- **Hardware only as the sole route: 0.** Hardware residues sit inside seven software-now entries: CRIME write-error (the bus-level exception), MACE failure (an ISA device that never answers), IP35 reset window (the routing rule), Bedrock refused read (what the hardware latches), Bedrock pending bits 25 to 34 (what physically sets bits 29 to 34), IOC3 UART byte lane (the physical lane) and IOC3 and IOC4 reset values.

Ordered software-now list. Earlier steps unlock more entries, and each step names the entries it settles.

1. Unpack the IP32 PROM: read the `sloader` decompression routine by hand and unpack `firmware`. Unlocks MACE failure, CRIME registers no image reaches, and CRIME transfer-engine tile formats.
2. Hub error handlers, read in full: `hub_ioerror_handler`, `handle_uncac_buserr`, `hubni_error_handler`, `log_md_errors`, `show_hub_md_err`, `process_error_spool`, `huberror_process_stack_entry`, `hubpi_spool_get_next`. Settles Hub PI write-buffer errors, Hub directory error labels, Bedrock refused widget read, Bedrock spool entry layout and Bedrock protected-region replies.
3. Bedrock block indexing and interrupts: `hub_error_init`, `hub_error_clear`, `intr_connect_level`, `intr_heuristic`, plus the mask code that ORs bit 24. Settles Bedrock block boundaries, Bedrock interrupt numbers and the software half of Bedrock pending bits 25 to 34.
4. Hub registers with no named role: `per_hub_init`, `hub_ifdr_fix_value`, `hub_piomap_alloc`, `hub_piomap_free`, the unnamed routine at `0xc00000000003b440` (it stores `0x400160`), `mlreset`, `hub_error_devenable`. Settles Hub registers with no named role.
5. Bridge attach paths in the IP27 kernel: `xbridge_attach` (revision 2 path), `pcibr_intr_alloc`, `pcibr_rrb_alloc`, `pcibr_alloc_all_rrbs`, `pcibr_rrb_check`, the callers of `pcibr_device_flags_set`, `pcibr_slot_addr_space_init`, and the callers of the Crossbow probe routines. Settles chip numbering, the revision 2 attach path, the interrupt device register, response buffer registers and device register bits.
6. PIC error service and direct map: `pcibr_error_dump`, `pcibr_error_intr_handler`, `pcibr_directmap_init`, and every reader and writer of the +0x18000 banks. Settles PIC error and interrupt service, PIC direct map and PIC +0x18000 banks.
7. PROM window bases, constant-folded: the IP27 and I/O-board PROMs, the IP35 PROM window setup, the `hubspc.o` and `nic.o` uses of the second window, and a PROM search for registers above 0x298. Settles registers above 0x298, the IP27 and I/O-board PROM window base, the window-base model and the Bedrock second window.
8. Xbow: the large crossbar routines in the four PROM images, the interrupt allocation in the node controller and HEART, and the link time-out and second-error routines. Settles the Xbow large routines and interrupt vector assignment. The PXBOW registers stay open until a PXBOW object is held.
9. CRIME: the other IP32 objects that call `get_crimerev`, the graphics driver's error paths and the write-error handlers. Settles CRIME identification, CRIME error status location, CRIME write-error (software half) and CRIME registers no image reaches.
10. MACE records and registers: the Ethernet, serial and video attach routines and the calendar RAM writer's callers (the audio block at `0x304018` is settled in docs/coverage-mace.md). Settles MACE run-time pointers and calendar RAM spacing.
11. IOC3 and IOC4: resolve the data relocations, read `plp_dma`, `plpintr`, `plp_reset`, `pciio_businfo_bus_speed_get`, `xide_pktDMA_start`, `xide_dma_init`, `xide_intr_clear`, and the IRIX PIO mapping flags. Settles the IOC3 UART lane (software half), the IOC3 tables, the IOC4 word at 0x24, the IOC4 ATA registers and the per-port tables.
12. HEART: the PROM error dump, the PIU access and widget error tests of the stripped `ide.IP30`, and one search of every held image for the eleven registers the diagnostic table names. Settles HEART refused-access errors and HEART registers no held code reaches.
13. Router: the callers of task `0xf` in `l1_command.o`. Settles the router scan-chain entry.
14. Tools and inventories: write the Bedrock accessor seeds, rerun the scanner to check the scanner-fault items, and give the harness a way to read an object's data by gp. Settles the Bedrock, IOC3 and IOC4 inventory entries (both), the scanner faults, the harness limits and the scanner status note, which belongs in the tool notes.
15. IP35 reset window, items 2 and 3 of the linked question: simulate the cache-staging routine against the cache-operation semantics, and read the remaining memory-configuration helpers.

Corrections found while tagging. These are not fixed here.

- Stale in part: the two census entries say the Hub, Bedrock, IOC3 and IOC4 censuses are not run. The IOC3 and IOC4 censuses have run, and Hub and Bedrock have census output under `chips/*/census/`. Bedrock still has no accessor seeds.
- Duplicates: the Bedrock, IOC3 and IOC4 entry is cut off mid-sentence ("write each config's") and overlaps the Hub, Bedrock, IOC3 and IOC4 entry. The PROM window-base model overlaps the IP27 and I/O-board PROM entry.
- Status note: "Scanner fixes after the first audit" records finished work with one open item. It belongs in the tool notes, and it partly covers the scanner-faults entry.
- Self-contradiction: the MACE revision-strap entry says NetBSD was already read, then names the NetBSD PS/2 driver as the next route.
- Unestablished claim: the Bedrock error-clear entry says no software route exists, but the public Hub headers it cites are a software route. They are not held in this clone.

- **Chip numbering inside the shared Bridge-family accessors.** *[route: software now]* The accessors choose among four chips by a
  type field and by the identification word's part number. For Bridge (part `0xc002`), XBridge (`0xd002`) and PIC
  (`0xd102`, `0xd112`) the part numbers and the 32-bit and 64-bit layouts match the public Linux and OpenBSD constants
  (chips/bridge/README.md, "Against the public drivers"), so those three are settled. Still open: the type 3 and part
  `0xe000`/`0xe010` chip (see TIOCP). The part number `0xd100` that `xbow_widget_present` tests is not a Bridge-family part: the routine reads it from the word at +4 of the block it is given and then reads per-link words at +0x13c from a 0x40 stride, so it names the crossbar's own identification (inferred).
  Next: the Crossbow probe routines' callers, and the public Linux `pci-xtalk-bridge.c` history for the later part
  numbers.
- **Bridge and XBridge: why the interrupt device register is written with all ones at attach.** *[route: software now]* The field layout and its use are answered
  (chips/bridge/README.md: three bits per pin, set to the device by `pcibr_intr_alloc`). Open: only the reason for the placeholder value.
- **Bridge and XBridge: registers above 0x298.** *[route: software now; PROM search; an accepted end state if none is found]* Whether the XBridge has registers between `0x2a0` and `0x10000`
  (the census reaches none and the public headers name none). Valid end state unless a routine that touches them is
  found. Next: the IP27 PROM and I/O-board PROM, which the scan could not resolve.
- **Bridge and XBridge: the IP27 and I/O-board PROMs.** *[route: software now]* The window base is built at run time and neither PROM has
  symbols, so the census holds no access from them. Next: constant-fold the PROM's widget-window setup, or read the
  I/O-board PROM's bridge probe by hand.
- **Bridge and XBridge: device register bits.** *[route: software now]* Only the pair `0x180000` (`pcibr_endian_set`) and the IP30 PROM's
  `0x1004` are read; the other bits the flags routines pass are derived from their callers at run time. Next:
  `pcibr_device_flags_set`'s callers and `pcibr_slot_addr_space_init`.
- **TIOCP: which product carries one.** *[route: missing source: a published hardware overview of the Altix-class generation]* The register layout, the identification and the two registers the shared code says the chip lacks are settled
  (chips/tiocp/README.md, docs/coverage-tiocp.md). Open: only the product list. No TIO code is held, so no software route exists.
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
- **CRIME: what the identification register's upper word holds on a CRIME 1.5; where the CPU error status lives on a 1.5.** *[route: hardware residue]* The upper word is a 1.1, 1.3 or 1.4 discriminator (docs/coverage-crime.md: IRIX arithmetic and NetBSD's attach text agree), and IRIX, NetBSD and Linux all read the 1.5 error status at `0x48` while the specification says `0x4048`. Open: what a real 1.5 returns for either, which only a read on the part answers.
- **CRIME: write-error behaviour.** *[route: software now; hardware residue: the bus-level exception and the failed-store latch on the part]* The graded answers (what sets CPU error status bit 2, what a failed or timed-out
  uncached store latches, which interrupt bits fire, how the kernel detects a failed store) are in chips/crime/README.md,
  "Write-error questions". Open there: which addresses are "invalid", whether a read and a write differ in the
  three-bit layout, whether a failed store also takes a bus error exception, which CRIME bit the MACE PCI error
  handler is attached to, second-error handling, and whether the interrupt asserts with its enable bit clear.
- **CRIME: registers no scanned image reaches.** *[route: software now; proposed: constant-fold the PROM's bank-sizing addresses once the IP32 PROM is unpacked, and read the CRIME routines of the held stripped `ide.IP32`]* Refresh counter (0x248), memory control bit 1 (replacement select),
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
- **MACE: revision strap at `0x310000` bit 4.** *[route: hardware residue: no public source or specification page names it]* Tried and recorded in docs/coverage-mace.md: the specification's ring base, PS/2 and host bridge revision pages, NetBSD `macekbc.c` and Linux `maceps2.c` (neither reads it). Hypothesis (inferred): it tracks the MACE revision whose PS/2 parity flag is reliable. Test: read `0x310000` and `0x8000c` on a MACE 1.0 and a 2.0 part.
- **MACE: calendar-clock user RAM stride.** *[route: hardware residue]* Base register `0x0e` and size 114 are established, and no held kernel object, diagnostic or monitor calls `read_dallas_nvram` or `write_dallas_nvram` (inferred; the compressed IP32 PROM is the one image not covered; both in docs/coverage-mace.md). Open: the one-byte stride in `read_dallas_nvram` against the specification's 256 bytes per register. The test is the one recorded in docs/coverage-mace.md under the stride conflict.
- **Hub, Bedrock, IOC3, IOC4 inventories.** *[route: software now; stale in part: duplicates the Bedrock, IOC3, IOC4 entry]* Censuses not run (stub configs). Next: write each config's
  seeds (see HAIKU-BRIEF.md) and run `retools/tools/chips/run.sh`.
- **Model of a PROM's window base.** *[route: software now; overlaps the IP27 and I/O-board PROM entry]* A PROM builds its window pointer at run time; the census recovers a
  pointer only where an identity-register probe shows it. Next: constant-fold the PROM's address setup.
- **IP35 reset window.** *[route: software now; hardware residue: item 1, the routing rule, which the linked question says only a hardware observation settles]* The routing rule that returns boot-PROM bytes for uncached memory-space fetches of physical
  0x1fc0xxxx after bank 0 is enabled, and whether any write ends it, are not visible in the PROM. Tried: full read of
  the reset, memory and jump-to-RAM path. Next: see [docs/questions/ip35-reset-window.md](questions/ip35-reset-window.md).
- **Census scanner faults found by the audit.** *[route: software now; tool work; partly covered by the scanner-fix entry, so rerun to check]* (1) A load or store whose displacement is added at run time through
  a `movz`-selected constant or a loop counter is recorded at the window base or at one iteration's slot
  (`dump_error_spool`, `hub_error_clear`, `part_discovery`); the families they build need their bounds read from the
  code. (2) A site in a routine with no symbol is credited to the preceding named routine (the three `+0x1000090`
  stores). (3) The IP35 PROM image is split after each return, so a block that is jumped to from earlier in the
  same routine (the PIC branch of the interrupt-register clear at 0xc00000001fc41f38) is missed while the other
  branch is labelled PIC. Next: do not split a PROM pseudo-function at an address a branch from the previous one
  reaches, and fold `movz` of two constants into two sites.
- **Hub PI write-buffer errors: which fault sets which.** *[route: software now]* PI error pending bits 4 to 7 (write response block timeout and write
  error) and 18 and 19 (error during spool), the status 0 and 1 latches (address, command, type 0 write error, 1 partial write error,
  3 timeout), the clear sequence and the interrupt (cause level 6) are read from the kernel (graded entries in
  [chips/hub/README.md](../chips/hub/README.md#error-reporting-for-a-refused-or-timed-out-uncached-write-and-read)). Unknown: the
  transaction that raises each bit, whether a 4-byte store differs, the unit of the CRB time-out (`0x30`, `0x38`), the processor line
  that cause level 6 is, the level number the I/O error interrupt is given, and whether reading the status 0 clear alias
  (`0x438`, `0x458`) clears it. Tried: the error initialisation, the PI, I/O and network handlers, the spool and stack routines,
  the shipped decode text. Next: `hub_ioerror_handler`, `handle_uncac_buserr` and `hubni_error_handler` in full, the trap dispatcher
  that indexes the cause table, `intr_heuristic`.
- **HEART refused-access errors.** *[route: software now; the held `ide.IP30` diagnostic is stripped, so its half is read without symbols]* What sets CAUSE bits 40, 41 and 42 (bad system read, bad system write, PIU
  register access error), what a failed or timed-out processor store latches, and which of the level 4 vectors 51 to
  63 each error raises. Known: the latch registers and decode paths, the widget error type bits (store timeout is
  type bit 2), the vector formula for widget errors. Unknown: the triggers and the cause-to-vector mapping. Tried:
  kernel error handler and probe routines, PROM, monitor decode tables. Next: the stripped diagnostic's PIU access
  and widget error tests, and the PROM error dump. Entries: [chips/heart/README.md](../chips/heart/README.md#open).
- **HEART registers no held code reaches.** *[route: software now; proposed: one search of every held image, then accept as no software dependency]* Eleven registers appear only in the diagnostic's register table (SDRAM mode,
  memory refresh, flow-control timers, MicroLAN divider and control, compare, widget status, control, link layer,
  target flush); TRIGGER and SYNC are reached but unread. Valid end state unless a routine setting them is found.
- **PIC error interrupt handler: rate limiter and programmed-I/O check.** *[route: software now]* The handler's flow, its fatal and dump masks and the registers `pcibr_error_dump` reads
  for each status bit are answered (chips/pic/README.md, "Error interrupt service"). Open: the thresholds and revision conditions of the per-bit rate limiter
  at record +2276, the routine at `pcibr.o` 0x9a4c that bits 11, 15, 34 and 38 call, what `test_and_set_long` does with the dump-guard word at record +2120, and what the
  record word at +72 is (`pic_attach2` stores a value there at `pic.o` 0x858; the halfword at +116 is the PCI-X mode bit and speed field). Next: read the 0x9a4c routine and the limiter loop in full and trace the +72 value.
- **PIC revision-1 steps.** *[route: software now]* The direct map is answered (chips/pic/README.md, "Direct map set-up"). Open: what the revision-1-only
  writes (control bit 29 test, request timeout 0x750, enable bits 39 and 9, response buffer bits) fix. Next: the same steps in `xbridge_attach` and the
  response-buffer allocator.
- **Bedrock block boundaries and indexed families.** *[route: software now]* Registers are listed by offset; membership of the
  processor interface, memory, I/O, network and local blocks is inferred from routine-name prefixes only.
  Many accesses add a node or block index the scan does not follow. Next: read the index arithmetic in
  `hub_error_init`, `hub_error_clear`, `intr_connect_level`.
- **Bedrock PROM and second window.** *[route: software now; proposed: constant-fold the IP35 PROM window setup, then read the hubspc.o and nic.o uses]* The IP35 PROM builds its window base at run time (no sites yet) and the
  0x90000000_18xxxxxx window of `hubspc.o` and `nic.o` is uninterpreted.
- **Bedrock refused widget read: what the silicon latches.** *[route: software now; hardware residue: what the hardware latches for a refused read, if the handlers do not split it]* Established: a read that gets a timeout or error reply
  is typed in PI error status 0 (type 3 timeout; read types 1 to 3) and the kernel prints "Read timeout, physaddr".
  Inferred: no pending bit exists for it; the exception is the bus error and the spool entry carries the address.
  Unknown: whether status 0 and the spool entry are both written for a read, which of the CRB error codes (5, 6) a
  refused read of a Crosstalk widget produces, and what the processor sees (data bus error or a zero return). No
  shipped code distinguishes these. Next: read `handle_io_buserr` and `hub_ioerror_handler` in full, and the PROM
  error dump.
- **Bedrock error status clear: the second-error and read effects.** *[route: hardware residue]* The clear mechanism is write-clear for the status words and write-one-to-clear for the pending register, per the Bedrock-family header, consistent with every IRIX access (docs/coverage-bedrock.md, graded inferred). Open: what a second error does to a status word whose valid bit is still set beyond the overrun bit, and whether a read of the clear address has any effect.
- **Bedrock pending bits 25 to 34 and fatal selection.** *[route: software now; hardware residue: what physically sets bits 29 to 34; proposed: the mask code that ORs bit 24]* Established: names from the kernel's table and the fatal
  and miscellaneous masks. Unknown: what sets bits 29 to 34 beyond their names (crossbar data cycle count, intervention
  state, state-pending timeout), and why bit 24 is ORed into one interrupt mask only (the first one written).
- **Bedrock protected-region replies.** *[route: software now]* The strings "Protection error response" and "Vector response timeout" are settled (chips/hub/README.md, "The texts for the vector routines' return codes": router vector return codes -6 and -7, not Bedrock status). Unknown: which status 0 type or CRB error code a memory protection violation produces. Next: the memory/directory error decode in `kernel.o` that prints the protection-index, protection-value and protection-rights fields, and the IP35 PROM error dump.
- **Bedrock interrupt numbers: the dispatcher's input.** *[route: software now]* Answered in chips/hub/README.md, "Interrupts to the processor": the II error
  level is 64 (inferred from the allocator and the hardwired table) and cause level 6 is the Cause IP6 bit (inferred from the dispatcher's bit tests). Open: that
  the dispatcher's fourth argument is the Cause word masked by the interrupt mask was not traced to the exception vector. Next: the IP27 exception vector code
  that calls `intr`.
- **Harness limits.** *[route: software now; tool work; proposed: map the object's data by gp in the harness]* `retools/tools/chips/run_routine.py` replaces calls with `v0 = 0` and has no global data, so a routine
  that reads a table by gp (`pcireg_int_ate_set`, `pcireg_force_always_set`, `pcireg_intr_addr_vect_set`) ends in
  an unmapped read; the routines that touch only the chip record run to completion.
- **Scanner fixes after the first audit.** *[route: software now; tool work; a status note with one open item (large no-return code spans), so it belongs in the tool notes]* Since that audit the scan reads gp from each object's options record
  (the auto-min rule is a flagged fallback and no object needed it), alternatives chosen by a conditional move
  are kept as separate conditional sites, loop counters are widened to an indexed site instead of one site per
  pass, and routines are cut by control flow (after a return that nothing branches to, and at call targets)
  rather than by symbol or by every return. Fixed since: the PROM's non-PIC 32-bit stores are no longer
  labelled `pic`, and routines following an unconditional branch or reached only as a delay-slot duplicate are
  cut or merged by control flow. Remaining: large code spans with no return
  (PROM data disassembled as code) stay single routines.
- **IOC3: why interrupts are polled while the top interrupt bits are enabled.** *[route: missing source: a published IOC3 hardware note, not held]* `ioc3_write_ireg` keeps interrupt bits 22:0 out
  of the hardware enable register and polls them every tick while bit 27 or 28 is enabled; the mechanism is read in full
  (chips/ioc3/README.md), the reason is in no string the objects carry. Next: a hardware note for the part; Linux and OpenBSD
  have no equivalent.
- **IOC3: which routine sets the device swap bit for the IOC3 window; parallel-port DMA control bit 29.** *[route: software now for the first, hardware residue for the second]* The byte lane, the inter-frame gap values, the parallel-port DMA roles and the error address decode are settled (docs/coverage-ioc3.md). Open: the IRIX routine that makes the IOC3 window byte-swapped (the Bridge device register bit 13 in the public header), and the meaning of bit 29 of the DMA control word at `0x8c`.
- **IOC4: why the word at `0x24` is cleared only from revision 79.** *[route: missing source: a published IOC4 erratum; accepted end state otherwise]* The register is a PCI bus speed field (inferred, docs/coverage-ioc4.md). Open: the revision gate and the meaning of values above 1.
- **IOC4: ATA end-of-transfer area and request list layout.** *[route: software now]* The DMA block roles are settled (docs/coverage-ioc4.md). Open: whether IRIX waits on the 128-byte area, the layout of the list the IRIX builder writes, and the error line's mask.
- **IOC3 and IOC4: reset values and the per-port tables.** *[route: software now; hardware residue: reset values of registers that no routine reads; the per-port tables are software now]* No routine reads a reset value; the mode-select pin numbers and
  serial configuration records are static data not extracted. Next: extract the data sections through their relocations.
- **CRIME rendering engine: field layouts the specification does not print.** *[route: missing binary: a shipped renderer or X server module that builds the words; the public CRIME frame-buffer driver is in an uninitialised submodule]* The pixel pipeline's depth function, stencil
  mode and stencil mask, the blend constant colour and the antialias coverage word have no field table in the 1.5 specification
  pages, and the antialias slope is given as 2.12 in one place and 2.14 in another. The loaders copy these words unchanged, so
  the shipped kernel does not decide them. Routes tried: the specification's register map and chapter text, the shadow loaders'
  copy order. Next: a shipped renderer or X server module that builds the words, and the public CRIME frame-buffer driver sources.
- **CRIME memory transfer engine: the null register and the tile table formats.** *[route: software now; the held `ide.IP32` diagnostic has rendering-engine TLB tests that are stripped; the IP32 PROM is compressed until the MACE entry's route is done; an X server module and the public CRIME frame-buffer drivers are not held]* No routine in the IP32 member objects
  writes `MTE.null` (`0x3070`), and no routine read builds a texture-TLB or clip-ID-TLB entry, so the entry bit layouts and
  the register's effect are open. The specification prints no entry layout. Routes tried: the shadow loaders, the clear,
  swap and copy routines, and a displacement scan of all 702 member objects. Next: the PROM, diagnostic and monitor
  images, an X server module, and the public CRIME frame-buffer drivers.
- **Router scan-chain tunnel (IP35).** *[route: software now]* `read_rr_reg` asks the L1 to shift 197 bits through the router chain and keeps 128 of
  them; established: the command layout, the bit reversal, the iRouter framing and the address arithmetic
  (chips/scan/README.md). Unknown: which router state the selector `2*(port-1)` and `2*(port-1)+1` names, what the 128 bits
  hold, the L1 task value `0xf` that the scan command is addressed to (the public header names tasks 1 to 6), what the `state`
  values 0, 1 and 16 stand for, and whether the router's JTAG controller registers (public `RR_LB_TO_L2`, `RR_L2_TO_LB`) are the
  chip side of this path. Tried: the held kernel, the `jtagio.a` and `irouter.o` objects, the `l1_command.o` task census, the public
  `l1.h` and `router.h`. Next: the L1 command-path callers of task `0xf` in `l1_command.o`, and any diagnostic or monitor image that
  names the scan operations (none found in the IP35 boot set).
- **DM8 board contents: sub-device ID, EEPROM image, part numbers.** *[route: missing source: a published `lspci -vv` or EEPROM dump of a DM8, or an SGI parts list; no shipped file holds them]* `mad_create_subsys` (`mad_dd.o` `0x1e4`, 560 bytes) tests config `0x2e` against `0x3630` and
  `mad_set_eeprom` (`mad_dd.o` `0x2f54`, 280 bytes) copies a 19-byte EEPROM image into the controller, but the DM8's own values are not in any held file. Read: the code, the
  probe `1412:1724`, the SGI note naming the controller. Unknown: the real sub-vendor and sub-device values, the EEPROM bytes,
  the SGI part number, whether SGI changed a component. Next: any public capture of a DM8; a `hinv -vm` line from a DM8 host gives
  the revision only (docs/audio/dm8.md).
- **ICE1724 register contract.** *[route: missing source: the vendor datasheet; software now for the remainder]* Offsets and widths the driver touches are in chips/ice1724/README.md.
  Unknown: reset values, write masks, the rate-code table in full, the DMA size and count units, the effect of `MT+0x19`
  and `MT+0x05` bit 7. Next: re-read `mad_set_rate` (`0x2268`) and `mad_start_dma` (`0xe48`) against a public vendor datasheet when one is held.
- **DM8 converter identities.** *[route: missing source: a board photograph or parts list; public AKM datasheets for the field meanings]* AK4381, AK4355 and AK5380 are leads from a sibling board's public
  driver and secondary reviews (chips/ak4381, chips/ak4355, chips/ak5380); `mad_init_revolution` (`mad_dd.o` `0x2b2c`, 412 bytes) programs them without naming them. No SGI document or shipped file names them.
- **Tezro tower onboard audio chip.** *[route: missing source: a tower hinv with PCI adapter IDs next to a known tower, or a daughtercard photograph]* The tower guide places analog jacks on the IO daughtercard.
  Unverified: published captures put a RAD (`10a9:0005`, revision 13.0) beside the IO9's IOC4 on Tezro, which suggests a RAD; the Audigy (PCI `1102:0004`) is an option card, not this part (docs/audio/drivers.md).
- **The SGI "basic audio" PCI option and the release that added `emu_dd`.** *[route: missing source: an SGI option list; the 6.5.23 to 6.5.29 IP35 object directories and any 6.5.30 `audio.sm`]* The Onyx 350 and Onyx4 guides list a basic and a
  professional PCI audio card without chip or part number; Creative Audigy cards (`1102:0004`, `4001`, `7003`) appear in Fuel, Tezro, Origin 300, Origin 350 and Onyx 350 captures. `emu_dd` is absent in 6.5.22 (docs/audio/drivers.md).
- **IP22-family audio objects.** *[route: missing source: the dmedia audio package's IP22 object directory]* The A2 (HAL2), indigo and hdsp drivers are named by master files and hinv strings only; no object is held.
- **RAD register contract in this workspace.** *[route: software now]* chips/rad/README.md records only the probe, windows and board dispatch of `rad_dd.o`. The register
  offsets, DMA engines, subcode and clock paths are not read here. Next: read `rad_start_device`, `rad_create_device`, `rad_set_*_if_params`
  in the IP35 and IP30 objects.
- **Fuel and Octane support for the DM8; Fuel support for the RAD board.** *[route: missing source: hinv captures or SGI support lists]* The Fuel evidence is a single user's hinv; the IP30 build
  carries `mad_dd.o` but no SGI document lists the Octane as a host (docs/audio/survey.md).
- **USB audio converter for the Fuel (007-4530-001).** *[route: missing source: USB descriptors or a teardown]* The class driver is `usbaudio_dd.o`; the converter's chip is not named anywhere read.
