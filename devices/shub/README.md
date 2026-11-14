# SHub (SN2 node controller), SHub 1 and SHub 2

SHub is the node controller of the Altix 3000 family and its successors (SGI's SN2 platform): one chip per node that joins one or two Itanium 2 processors and their memory to the NUMAlink fabric and to Crosstalk I/O. It is the Itanium counterpart of the Origin 3000's Bedrock, a different chip with different field positions and register offsets. The kernel for this platform distinguishes two generations, SHub 1 (Altix 3000) and SHub 2 (later Altix, up to the 4000 series), at run time. Register contracts are in [registers.toml](registers.toml) (SHub 1), [registers.shub2.toml](registers.shub2.toml) (SHub 2, an overlay on it, the way [bridge](../bridge/README.md) holds XBridge) and, for the I/O interface, [../shub_ii/](../shub_ii/README.md). Generated references: [registers.md](registers.md), [registers.shub2.md](registers.shub2.md). The node address layout is [../../platforms/sn2/address-map.md](../../platforms/sn2/address-map.md); the firmware calls the kernel makes are [../../software/sal/README.md](../../software/sal/README.md).

**Mode: no-spec.** No SHub specification, PROM or SAL image is held, and none is public. Every fact here comes from SGI's own Linux platform code for SN2 (Linux v5.3: `arch/ia64/include/asm/sn/` and `arch/ia64/sn/`; the real-time clock driver at v4.9; the SN2 platform was removed in v5.4). That code is the vendor's software source: what it defines is **established** (an offset, a field position, a call sequence), what it implies about hardware behaviour is **inferred**, and what it leaves out is **unknown**. The only chip documents held are the Altix user's guides, which are not register specifications. Reset values are unknown throughout, except three register families the header names with an INIT macro (the RTC interrupt configuration and enable, and the comparators; graded inferred).

**What the public header gives, and what it does not.** The register header, `shub_mmr.h`, defines about two dozen register names, not the hundreds a chip reference would. It is a subset the kernel needed: interrupt, clock, PIO write status, TLB purge and BTE registers, plus two memory/directory privilege vectors. There is no network interface register at all, no memory controller register beyond those two, no processor interface register beyond the few named, and no local-block register beyond the identification, clock and interrupt ones. Everything the PROM programs before the kernel starts is invisible in this source. A model built from this page can run the kernel the source describes; a model of the chip needs more evidence ([questions/shub-registers-unnamed.md](../../questions/shub-registers-unnamed.md)).

## The functional units, as the header and code have them

The header does not say which unit holds a register. The unit named below is inferred from the register's name prefix and its address block (bits 31:28 of the offset, which differ by name family: 0x0 memory/directory, 0x1 local block, 0x2 processor interface on SHub 1).

| Unit | What the sources show | Registers |
|---|---|---|
| Processor interface (PI) | PIO write status, one per processor slice; CRB CAM access control (SHub 1 only) | `pio_write_status`, `pio_write_status_alias`, `pi_cam_control`; TLB purge registers (`ptc`) are in the local-block address block but act on the processor side (inferred) |
| Memory and directory (MD) | two privilege vectors named for the "DQLP" and "DQRP" queue ports, no use by the kernel | `md_dqlp_dir_privilege_vector`, `md_dqrp_dir_privilege_vector` (SHub 1) |
| I/O interface (II) | the Crosstalk port, access protection, the CRBs and two block transfer engines on SHub 1 | [shub_ii](../shub_ii/README.md); on SHub 2 the BTEs move to their own block (below) |
| Network interface (NI) | nothing in the sources read | none; unknown |
| Local block (LB) | identification, interrupt event and send, IPI access, the real-time clock and its comparators | `shub_id`, `event_occurred`, `ipi_int`, `ipi_access`, `rtc`, `rtc_int_*`, `int_cmp` |
| Junk bus | four LED registers; a UART whose interrupt is an event bit | `junk_bus_led` |

## Telling SHub 1 from SHub 2 at run time

- **Firmware tells the kernel (established).** At start-up each processor calls (the boot processor twice, early and again after platform setup) the SAL entry `SN_SAL_GET_SN_INFO` and stores the answer: bits 7:0 of the first result are 0 for SHub 1 and 1 for SHub 2 (comment in the SAL header). The kernel's `is_shub1()` and `is_shub2()` read that field; every chip-specific choice below branches on it. The same call returns the NASID mask and shift, the system size, the sharing-domain size, the partition and coherency ids and the region size ([SAL page](../../software/sal/README.md)).
- **Fallback (established).** If the PROM does not implement the call the kernel assumes SHub 1 with a fixed NASID layout and reads the nodes-per-bit field of the SHub 1 identification register for the region size. Nothing checks the identification register to decide the chip type.
- **Registers the generic names hide (established).** Many registers have a generic name (`SH_IPI_INT`) that the header defines as a run-time choice between the `SH1_` and `SH2_` constant (`is_shub2() ? SH2_x : SH1_x`). The header comment says there is "a small performance penalty" and tells hot paths not to use the generic names; the kernel keeps chip type, address shifts and the PIO status address in per-processor data.
- **Names for monitoring (established).** The performance and topology code reports a node as "SHub 1" or "SHub 2.x" by string, and recognises SHub 2 nodes by the prefix `SHub 2.`; the string comes from firmware, so it does not give a register-level test.
- **Revision (established for SHub 1 only).** The identification register's revision field is read only on SHub 1, to find chips of revision 2 or lower ("SHub 1.1") that need workarounds. The header names no SHub 2 identification register.

## What differs on SHub 2 (from the kernel's branches)

| Item | SHub 1 | SHub 2 |
|---|---|---|
| Register offsets | `SH1_` set in [registers.toml](registers.toml) | `SH2_` set in [registers.shub2.toml](registers.shub2.toml): mostly the SHub 1 offset minus 0x1_0000_0000, the clock 0x2_101c_0000 |
| Local and global MMR windows | 0x80_0000_0000 and 0x8_0000_0000 | 0x2_0000_0000 and 0x3_0000_0000 ([address map](../../platforms/sn2/address-map.md)) |
| Processors per node, as the PIO status table implies | 2 (slices 0 and 2) | up to 4 (slices 0 to 3) |
| PIO write status | two registers; idle when the count field reads all ones | four registers, slices mapped to instances 0, 2, 1, 3; idle when the count is zero; the recovery code reads the alias instead of writing 7 to it |
| TLB purge (PTC) | two registers per node written back to back; region id and address in data | one register per node; region id added to the address; address in the data |
| BTE | two engines inside the I/O interface, started by writing length then control | four engines in their own block; one store to the control register starts a transfer with busy, mode and length together; six-bit error code in the status |
| Interrupt events | bits 20, 24 to 26, 28, 29, 30 | adds bits 33 and 34 (external I/O interrupts 2 and 3) |
| Workarounds | SHub 1.1 (revision 2 or lower): PI CAM write on every timer tick, a global lock round IPI stores; lost-interrupt check from the timer for PIC | none named ("none yet" in the kernel) |
| Cached-address requirement for cache flush | the flush needs a cached address (uncached ones are converted) | not needed |
| Error handling | hub error interrupt: PROM call, then CRB scan in the kernel | PROM call only for TIO errors; BTE errors handled by the kernel through a PROM BTE recovery call |
| CPU disable | not supported | the kernel sends all error interrupts to the boot processor when the PROM advertises CPU disable support (a PROM feature bit) |
| AMO cache | none | the kernel flushes four AMO lines through a scratch page before a BTE zero fill |
| IA-64 simulator I/O base | `0xc0000087cc000000` | `0xc00000028c000000` |

The SHub 2 contract is therefore thinner than SHub 1's: its offsets for the SHub 1 registers come from the same header, and what the header adds for SHub 2 alone is the purge register, the four BTE engines' four registers, two more PIO write status instances and three more IPI access registers; and the II block's layout on SHub 2 is not given (the kernel uses neither the II registers nor the CRBs on SHub 2 except through firmware).

## Interrupts and IPIs

- **Sending an IPI (established).** The sender stores one 64-bit message to the target node's `ipi_int` register: send bit, target processor id (the id the processor's SAPIC holds), a type (0 interrupt, 2 platform management interrupt, 4 NMI, 5 INIT), a vector, and a constant base. The store is an uncached physical-mode `st8.rel` after a memory barrier. On a SHub 1.1 the kernel serialises under a global lock: it takes the lock, makes the store, waits for the PIO write status to drain, then drops the lock. The receiving processor sees an ordinary external interrupt with the given vector; the event register shows `ipi_int` (bit 28) pending until cleared.
- **Pending events and acknowledge (established).** The interrupt acknowledge reads the event register, ANDs it with the mask of the bits it manages (junk-bus UART, IPI, II 0, II 1, and on SHub 2 the two external I/O bits) and writes the result to the alias register. The RTC comparator bits (24 to 26) are not in that mask; the clock driver clears them itself through the alias. The header's mask lists the II 1 bit twice and leaves out nothing else; harmless.
- **Processor id layout (established as a fallback).** For an old PROM the kernel decodes a processor id as NASID in bits 11:0, slice in bits 13:12 and the subnode in bit 13; the code that does it contradicts itself on the subnode bit, so only the NASID field is firm. The normal path asks SAL (`SN_SAL_GET_SAPIC_INFO`).
- **Vectors the platform reserves (established).** XPC activate 0x30, II error 0x31, crossbow error 0x32, PCI ASIC error 0x33, ACPI SCI 0x34, TIOCA error 0x35, TIO error 0x36, TIOCX error 0x37, RTC comparator timer 0x38, then device vectors 0x3c to 0xe6, XPC notify 0xe7, UART 0xe9.
- **Device interrupts (unknown).** How a bridge interrupt reaches a CPU is set up by firmware (`SN_SAL_IOIF_INTERRUPT`: allocate, free, redirect); the kernel never programs the bridge-to-SHub path itself and keeps only what firmware returns (`sn_irq_info`: target node and slice, the Crosstalk address the bridge writes to). Which SHub register that address names is not in the sources (the comment above says a PIC interrupt targets a SHub interrupt register); see the question page.
- **Lost-interrupt check (established).** On SHub 1 the timer interrupt scans the PIC interrupt status every hundred ticks and forces an interrupt for a pin whose status bit is set but whose vector is neither pending nor in service. The kernel comment says only PIC bridges need this, because bridges attached to a TIO do not target the SHub's interrupt registers: so a PIC interrupt is a store into a SHub interrupt register (established as the comment's statement; which register, see below).

## Real-time clock and comparators

A 55-bit free-running counter at `rtc` (clock source, delays, user-mapped by the clock driver). The frequency is not in a register: the kernel asks firmware (`SAL_FREQ_BASE`, the generic SAL real-time clock query), and if that fails guesses 1,000,000,000,000 / 30,000 (about 33.3 MHz). Three comparators (`int_cmp` B, C, D) fire an interrupt when the counter reaches the compare value; each has a configuration register (same layout as the IPI message) and an enable. The clock driver programs them in the order: disable, set compare to all ones, clear pending, write configuration, enable, write expiry. A fourth comparator exists and is "used by SAL" (driver comment).

## TLB purge

`ptc` makes the SHub purge a translation range on all processors of a node (**inferred** from the name "purge translation cache"; the kernel's use is the only evidence). The kernel's use is the global TLB flush on SN2: for each node that has a processor running the address space it does the register stores, waits for the PIO write status to drain, and recovers from a deadlock by repeating the stores one node at a time in physical mode. The local node uses the processor's own global purge instruction on SHub 1. On SHub 1 the purge uses two stores per page (control word, address word); on SHub 2 one store (address and region id in the address). After every group of up to 32 (SHub 1) or 7 (SHub 2) nodes it waits for the write count to drain; on a deadlock indication it drops to one node per group. The hardware's purge behaviour (does the SHub issue the purge in the local node's processors too, is it acknowledged) is **unknown**.

## PIO write ordering

PIO writes from different processors of a node are not guaranteed to reach a target in order (kernel comment on task migration); the memory-mapped I/O barrier is to spin on the processor's PIO write status until the count shows idle. This is the reason a model of SHub must make the status register meaningful, not constant: idle must read as the value the kernel waits for (all ones for the count field on SHub 1, zero on SHub 2).

## Block transfer engines on SHub 2

Four engines, one per interface, at 0x30040000 + engine x 0x10000: control and status, then source (+0x80), destination (+0x100), notify address (+0x180). The kernel writes source, destination and notify address, then one 64-bit store to the control register with busy (bit 20), mode (shifted left 24) and the length in cache lines. Completion is written to the notify address like on SHub 1. Errors appear as a six-bit code in bits 41:36, which the kernel decodes both from the control and status register (error handler) and from the notification word the engine writes (`bte_copy`); inferred. The kernel's names for the bit values are 0x1 short response, 0x2 long response, 0x4 (the kernel's name is RESP_DSP), 0x8 access, 0x10 CRB timeout and 0x20 NACK limit. When the field is non-zero the kernel's status decode treats the transfer as failed and ORs the error flag in itself. Source, destination and notification addresses are written in the network address form ([address map](../../platforms/sn2/address-map.md)). Error recovery asks firmware to reset the BTEs (`SN_SAL_BTE_RECOVER`).

## Unknown

Everything the PROM programs; the network interface; the memory controller and directory; reset values; the SHub 2 identification register; the SHub 2 II layout; what the PTC and PIO status do in hardware beyond the kernel's use. Routes: a Linux ia64 PROM or ProPack kernel image would settle the PROM's register programming; an SGI SHub programmer's reference, if one is ever found, would settle the rest. See [questions](../../questions/shub-registers-unnamed.md).

## Review

Independent review of this page, [registers.toml](registers.toml) and [registers.shub2.toml](registers.shub2.toml) at chips commit 87e1291 (the address map and SAL pages it links were reviewed at 788b7be and 40866b2; their own review sections say what was cleared). The reviewer did not write the page. The source was re-fetched as single files from Linux v5.3 (v4.9 for the real-time clock driver) and compared with the text. There is no `devices/shub2/` directory: the SHub 2 contract is this page plus the `registers.shub2.toml` overlay, so this section covers both.

**Checked.**
- Every offset in both register files was compared with the header's `SH1_` and `SH2_` constants by script: 16 SHub 1 register entries (including the repeated RTC configuration, enable, comparator, PIO status, PTC and LED instances and their strides) and 11 patched plus 5 added SHub 2 register entries. All match exactly, including the overlay's removal list (no `SH2_` name exists for the identification, CAM control, PTC 0/1 and memory privilege registers).
- Field positions compared with the header's shift and mask macros: IPI message (type, agent, processor id, base, vector, send), event bits 20, 24 to 26, 28 to 30 and SHub 2 bits 33 and 34, identification revision (31:28) and nodes-per-bit (52:48, from the SAL header), RTC and comparator widths (55 bits), RTC configuration mask, enable bit, PIO status deadlock bit 1 and count 61:56, SHub 1 PTC shifts (0, 2, 8, 63), SHub 2 PTC shifts and address mask (60:12). All match.
- Behaviour claims checked against the callers: PIO status slice tables (SHub 1 slices 0 and 2; SHub 2 instances 0, 2, 1, 3), idle value (count field all ones on SHub 1, zero on SHub 2), the CAM write on every timer tick for revision 2 or lower, the lost-interrupt scan every 100 ticks (SHub 1 only), PTC group sizes 32 and 7 and the drop to one node per group on deadlock, deadlock recovery (write 7 to the alias on SHub 1, read it on SHub 2), the interrupt acknowledge mask (including the duplicated II 1 term), the comparator programming order, the 1e12/30000 clock guess and the 100 kHz floor, the four-line AMO cache flush before a zero fill, the CPU-disable interrupt routing, the cached-address rule in the cache flush, the reserved vector list, the simulator I/O bases, and the SHub 2 block transfer engine offsets, stride, busy bit 20, mode shift 24 and error code at 41:36.
- Chip type: `is_shub2()` and `is_shub1()` read only the per-processor record filled from bits 7:0 of the first `SN_SAL_GET_SN_INFO` result (value 0 on the not-implemented fallback). No register is consulted. The claim is correct. The call is made twice on the boot processor, not once (see below).

**Grades.** Nothing is established that the source does not define. Roles, unit assignment, the PTC and PIO status behaviour and the SHub 2 block transfer field layout are inferred or unknown as the rules require. The reset values are all unknown or inferred-from-INIT, and no reset is claimed established.

**Findings (judgement or wording, not changed).**
1. The SHub 1.1 IPI text says the kernel drains the PIO write status first. `sn_send_IPI_phys` takes the global lock, does the store, then waits for the PIO write status, then unlocks. The register file's `ipi_int` text has the right order; the README sentence should match it.
2. `IPI_BASE_VALUE`: the value 0xfee is established, but the text equating it with the 0xfee00000 interrupt area does not follow. The field starts at bit 21 (2 MiB units), so 0xfee in the field is 0x1_fdc0_0000, not 0xfee00000 (the kernel's own default interrupt base constant in `hw_irq.h` is 0xfee00000). Drop the equivalence or grade it inferred with the arithmetic.
3. "Except two the header names with an INIT macro": three register families carry an inferred reset of zero (`rtc_int_config`, `rtc_int_enable`, `int_cmp`).
4. The per-processor LED state is an 8-bit value in the kernel's record, written with a 16-bit store. "16-bit LED state" should say 16-bit store.
5. The header's `SH2_PTC_ADDR_SHFT` is 4 while its mask starts at bit 12; the register file uses the mask (correct). A note would save the next reader a wrong turn.
6. The SHub 2 error code in bits 41:36 is decoded by the kernel both from the control and status register (error handler) and from the notification word the engine writes (`bte_copy`). The page mentions only "the status". Both uses are the kernel's, so the field stays inferred.
7. The boot processor calls `SN_SAL_GET_SN_INFO` twice (once from processor initialisation before platform setup, once from platform setup), not once.

**Cleared:** offsets and field positions of all 16 SHub 1 and 16 SHub 2 register entries (by script against the header) and of the behaviours listed above, including the SHub 1 versus SHub 2 test. **Not cleared:** the unit assignment column, every role text (inferred by design), the SHub 2 block transfer field layout beyond offsets and the error code position (inferred), the finding 1 to 3 wording until the author settles it, and anything outside the cited Linux files (the page's "unknown" list is consistent with them, but absence in the sources was checked only in the SN2 directories and the drivers that include the SN SAL header).

Findings 1-8 addressed in the commit "docs: address the SN2 SHub review findings"; renewed review needed for the changed claims.

### Renewed review

Renewed review of the changed claims only, 2026-11-14, by a reviewer who wrote none of them. Reviewed chips commit f5ab671 (contains 1d4f24f and 9995be1). Grading rule: sgi-retools `tools/README-analysis.md` "Evidence order" at c50bfeb. Sources were fetched as single files from Linux v5.3 into scratch and compared with the changed text. 

**Checked.**
- IPI order against `sn_send_IPI_phys` (`arch/ia64/sn/kernel/sn2/sn2_smp.c`): memory barrier, take the global lock (SHub 1.1 only), `pio_phys_write_mmr`, `wait_piowc`, release. The page now says lock, store, drain, unlock. Match.
- `IPI_BASE_VALUE`: the code ORs `0x000fee << SH_IPI_INT_BASE_SHFT` and the shift is 21 in `shub_mmr.h`; 0xfee << 21 is 0x1_fdc0_0000. `IA64_IPI_DEFAULT_BASE_ADDR` is 0xfee00000 in `arch/ia64/include/asm/hw_irq.h`. The corrected text, graded as inferred arithmetic, is right.
- Reset values: `shub_mmr.h` carries `_INIT` macros for exactly three families (RTC 1 to 3 interrupt configuration, RTC 1 to 3 interrupt enable, `SH_INT_CMPB/C/D`), all zero. "Three" is right.
- LED: `pda.h` has `u8 led_state` and `volatile short *led_address`, so an 8-bit state with a 16-bit store. Match.
- `SH2_PTC_ADDR_SHFT` is 4 (line 220, under the `SH2_PTC_ADDR_RID` comment), `SH2_PTC_ADDR_MASK` is 0x1ffffffffffff000 (bits 60:12), and `sn2_smp.c` uses `SH2_PTC_RID_SHFT`. The register file's note is right. That no other kernel code uses `SH2_PTC_ADDR_SHFT` was checked only in the fetched files.
- BTE error code: `BTE_GET_ERROR_STATUS` decodes bits 41:36 of the notification word in `bte_copy`, and `bte_error_handler` (`bte_error.c`) applies `BTE_SHUB2_ERROR` to the control and status register value. Both uses exist.
- Boot-processor double `GET_SN_INFO`: `sn_cpu_init` is called by `cpu_init` (ia64 `setup.c` line 592, before `platform_setup` at 617) and again at the end of `sn_setup` (line 481). Match.

**Findings.** None.

**Cleared:** the six wording changes above. **Not cleared:** what the first review left uncleared (unit column, role texts, the SHub 2 BTE field layout beyond offsets and the error code).
