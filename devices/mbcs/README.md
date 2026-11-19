# MBCS (RASC Core Services)

Mode: **no-spec**. **Not a chip**: MBCS is the register block of the "Core Services" part of an SGI RASC FPGA bitstream. It exists only
when such a bitstream is loaded behind the TIO's FPGA port ([TIOCX](../tiocx/README.md)). SGI's Linux driver `drivers/char/mbcs.c` and its header
`mbcs.h` (linux-5.3 pin 4d856f72c10e; copyright 2005) define it. For this generation that code is the vendor's software
source, so what it defines is **established** as a software definition, never as a measurement. Registers: [registers.md](registers.md) (27 registers).

## Identification (established, driver; inferred, the link to RASC)

- The driver's own description is "MOATB Core Services" and its Kconfig text is "SGI FPGA Core Services driver support", for "an SGI Altix with an attached SABrick".
  The expansion of MOATB is not given. The RASC user's guide (007-4718-007, printed pages 22 to 25) describes "Core Services" as the pre-synthesised block of the
  algorithm FPGA bitstream: SSP receive and transmit modules, a programmed-I/O request engine, a transaction-number tracker, a request gate, memory-mapped
  registers, an interrupt generator, input and output DMA engines, a memory controller and the user's algorithm block. The driver's block has the same parts (PIO registers, two DMA engines with
  completion AMO or interrupt, an algorithm run with step control, debug registers, three RAMs, a transaction number in the error detail). That the driver and the guide
  describe the same block is **inferred** from this match; neither names the other.
- The driver binds to part numbers `0xfff0` and `0xf001`, both with manufacturer 1, read from the widget identification word at offset 0 of the port's window.
  Register `id` is that word: bit 0 is one, manufacturer 11:1, part 27:12 (established, header). The Core Services driver never reads it; the TIO bus code reads the same word. Bits 35:28 are an
  8-bit bitstream revision (header); the TIO bus code's revision field is bits 31:28 of the same word, so the two readings overlap (established, both macros).
- The guide's 2.20 release adds streaming DMA, five independent RAM ports, completion signalling and local-memory error checking. The driver and header do not mention
  them. Which part numbers or register additions those bitstreams use is **unknown**.

## Address layout (established, header and driver)

The registers sit at the base of the port's 256 MiB window (offsets 0 to 0x318, with gaps). Further regions follow: a start page the driver maps to user space uncached,
the debug registers at 0x100000, and three local RAMs at 0x200000, 0x400000 and 0x600000. The driver reads the first debug register as "algorithm number and revision" (high and low 32 bits)
by its own convention. The guide says an algorithm can have one to 64 debug registers (64 by default) and one to 64 algorithm-defined registers (8 by default), and that host and algorithm
can both write an algorithm-defined register, whose write capability "overlaps the debug registers up to RASC 2.20" (printed pages 27 and 35). So the algorithm-defined registers are
probably in or beside the debug region, but their offset is **unknown**; the driver never touches them.

Local RAM: the guide gives five physical SRAMs (8 MiB each on the blade) behind three logical or five physical ports and says the offset field of an algorithm's RAM address moved to bits 23:14
in release 2.1 (pages 37 and 38). The driver's DMA local address has a 21-bit offset and a 2-bit RAM select, and the driver chooses the select from the byte offset (below 2 MiB, 4 MiB, 6 MiB, else 3). Its character device
is limited to 1 MiB, so the select is always 0 through the driver. Which RAM select is which RAM, and what select 3 is, is **unknown**.

## How software drives it (established, driver)

The driver's register-write macro stores, then loads the same address into an unused variable through a non-volatile pointer. The intent is a flush of a posted write, but a compiler may drop the load, so whether the shipped module reads back is **unknown**.

1. **Attach.** Read `req_timeout`, set its 24-bit field to all ones, write it back. Read `err_status` and write that value to `clr_err_stat`. Write zero to `err_detail1`. Write `0x3ffffff7e00ff` to `err_int_en`
   (bits 0 to 7, 17 to 22 and 24 to 49: every defined condition except bit 16 and bit 23; the driver's comment mentions only bit 23). Read `control`, set `rearm_stat_regs`, `alg_clr`, `wr_dma_clr` and `rd_dma_clr`, write it back.
   Then allocate three interrupts (below).
2. **Host to local RAM ("read" DMA, called a get in the code, started by the character device's write call).** Program `rd_dma_sys_addr` (host address converted to the TIO DMA view,
   `PHYS_TO_TIODMA`, the same view used by the PCI-X, AGP and PCIe bridges on the same TIO; see [TIO](../tio/README.md)), `rd_dma_loc_addr`, `rd_dma_ctrl` (length = bytes rounded up to 128-byte units,
   16 bits so up to 65535 units; `done_int_en` set, `done_amo_en` and `pio_mem_n` zero), `rd_dma_amo_dest` and `rd_dma_int_dest`. Then read `control`, set `rd_dma_go`, write it back.
3. **Local RAM to host ("write" DMA, the character device's read call).** The same with the `wr_dma_*` registers and `wr_dma_go`.
4. **Algorithm run (sysfs file written with 1).** Write `alg_amo_dest`, `alg_int_dest` and `alg_step` (the step count, zero unless set), then read `control`, set `alg_done_int_en` and `alg_go`, write it back, and wait.
5. **Completion.** Each of the three engines has its own interrupt destination, programmed with the address and vector the firmware call returned (bits 55:0 address, 63:56 vector). All three share one
   handler, which reads `status` and tests `rd_dma_done` (bit 42), `wr_dma_done` (45) and `alg_done` (48). For each it reads `control`, sets the matching clear bit (`rd_dma_clr` 39, `wr_dma_clr` 40, `alg_done_clr` 51) and writes it back.
   The driver's attach clears with `alg_clr` (41), the handler with `alg_done_clr` (51): both are bits of `control`, and what each does beyond the name is **unknown**.

Driver quirks an emulator will meet: the host-to-RAM path clears the write-DMA completion flag instead of the read flag, so after the first read-DMA completion its wait returns at once (a driver bug, observable as a model that completes late);
the probe ignores the result of the interrupt allocation; the user mapping is one page of the start region, so `status` and `control` are reachable from user space.

## Not known

Reset values of every register; the access type of each bit (write-one-to-clear, self-clearing go bits); the meaning of the `cm_id` field of `control`, `max_trans`, `address_mode`, `credit_limit`, `force_gap_war`, `prescalar_byp`
and the SRAM lock bits, which no code sets; the layout of `targ_flush`; what `pio_mem_n` selects on 1 (the driver always writes 0; the header calls it "peerIO"); the error-detail fields; the
algorithm-defined register offsets; the packet-level behaviour of the SSP; whether any bitstream other than SGI's RASC Core Services uses this register layout. Routes: the guide names the
register offsets only in its sample test bench (see the review below), chapters 5 to 9 and most of chapter 3 were not read, and no RASC driver beyond `mbcs.c` is public. See [the open questions](../../questions/tiocx-rasc-open.md).

## Review

Independent review on 2026-11-15 by a reviewer who did not write these pages. Scope: the MBCS page and `registers.toml` (chips commit 97bfb48), the RASC platform page (4f3a4e3), the TIOCX "What sits behind the port" section (8961c72) and the open-questions page (b85dc1b). Grading rule: the SN2 paragraph of the evidence order (SGI's Linux platform code is first and a fact it defines is `established` as a software definition).

**How.** Linux v5.3 `drivers/char/mbcs.h`, `drivers/char/mbcs.c`, `drivers/char/Kconfig`, `arch/ia64/sn/kernel/tiocx.c`, `arch/ia64/include/asm/sn/tiocx.h`, `l1.h`, `intr.h`, `addrs.h` and `arch/ia64/sn/include/xtalk/xwidgetdev.h` were fetched singly and read. Every register offset and every field range in `registers.toml` was compared by script with the header's structs and bit comments (27 registers, 213 fields). The RASC user's guide 007-4718-007 was read as text from the same revision (our holdings search and read calls did not resolve SGI printed manuals for this number, so the local mirror copy was used). Binary claims: the module `mbcs.ko` and the SN2 kernel of the SLES 9 SP3 release (2.6.5-7.244-sn2) were read. The module's `.text` was disassembled in Ghidra with the IA-64 processor module (flat image at base 0, bundle listing, no function recovery or decompiler output, so no function boundaries come from Ghidra); the kernel symbol list was read with `readelf`.

**Confirmed (checked, no change).**
- All 27 register offsets (0x0 to 0x318) and all 213 field ranges match the header; reserved gaps match `struct mbcs_mmr`. Part numbers `0xfff0` and `0xf001`, manufacturer 1, and the driver's three RAM starts and the debug start match.
- Widget identification layout: revision 31:28, part 27:12, manufacturer 11:1 (`xwidgetdev.h`), so the page's overlap statement about the core's 35:28 revision is right.
- Attach sequence order, `req_timeout` all ones, clear of `err_status` through `clr_err_stat`, zero to `err_detail1`, and `err_int_en` value `0x3ffffff7e00ff` (bits 0 to 7, 17 to 22, 24 to 49; bits 16 and 23 clear, the driver's comment names only 23). In the shipped module the same value is a 64-bit immediate in the probe routine, with the `req_timeout` (`0xffffff`), `err_stat` and `clr_err_stat` offsets beside it, and the control write ORs bits 33, 39, 40 and 41 (Ghidra listing).
- Completion handler: tests status bits 42, 45 and 48 and sets control bits 39, 40 and 51 respectively (Ghidra listing of the shipped module). The host-to-RAM path clears the write-DMA completion flag (offset of `dmawrite_done`) and never clears the read flag, so the page's driver-bug statement holds in source and in the shipped module.
- DMA length in 128-byte units, RAM select by byte offset thresholds 2, 4, 6 MiB, 1 MiB character-device limit, one-page user mapping, `mbcs_probe` ignoring the interrupt-allocation result, three interrupts with intr_dest address 55:0 and vector 63:56.
- TIOCX: `TIOCX_DMA_ADDR` mask `0xffffcfffffffff` clears bits 37:36 and above 55; the TIOCX-to-TIOCX macro keeps bits 35:0 and moves 55:38 up two; `tiocx_dma_addr` uses `PHYS_TO_TIODMA`; the mask is unused in both files; the credit status of 15; `SGI_TIOCX_ERROR` is 0x37 and unused; the three board-type constants; the kernel symbols the page lists are present in the SN2 kernel.
- Guide claims: first-generation brick, SSP on the TIO (p. 9), blade with two FPGAs, two TIOs, a loader FPGA, 200K logic cells, five 8 MB QDR SRAM DIMMs per FPGA (p. 11 to 12), legacy brick packaging (p. 12), eight blades and two compute blades per RASC blade (p. 19), XC4VLX200-FF1513-10 (p. 22), 1 to 64 algorithm-defined registers with 8 by default and write capability overlapping the debug registers up to 2.20 (p. 27), 0 to 64 debug registers, 64 by default (p. 35), five 64-bit memory ports from 2.20 and the offset field moving to bits 23:14 in 2.1 (p. 37 to 38), devmgr and the `.bin` and `.cfg` outputs.

**Mechanical fixes (made in place).**
- The page and the commit message said 26 registers; the unit has 27. Corrected.
- The README said the guide names no register offsets in the pages read. It does, in the sample test bench (below). Reworded to point here.
- The TIOCX page and the open-questions page said the Core Services driver was not held as a module and that whether it shipped is unknown. The held SN2 kernel's configuration sets `CONFIG_SGI_MBCS=m` and the SLES 9 SP3 kernel package (SUSE ia64 media, held mirror) carries `mbcs.ko` (sha256 `8b63a28a1e61654ac5acf7bd807a06a455814b16af6c0f17a11cdf7f9376cd18`); its id table is `0xfff0` and `0xf001`, both with manufacturer 1. Both pages corrected. Whether any system ran it stays unknown.

**Findings not fixed (change meaning, need a decision or a longer read).**
1. The guide's sample test bench (printed pages 71 to 74) is a second, independent source for the register block, and the page does not use it. It writes `CM_CONTROL` at 0x20, `CM_ERROR_STATUS` at 0x60, `CM_ERROR_DETAIL_1` at 0x10, `CM_ERROR_INTERRUPT_ENABLE` at 0x70 (all ones), the interrupt destination at 0x38, the DMA registers at 0x100 to 0x120 and 0x200 to 0x220, and the algorithm destinations at 0x300 and 0x308, reads status at 0x8 and read-DMA auxiliary status at 0x130. Every offset agrees with the driver. It also shows `control` values: `0x0000000600f00003` ("arm" with `rearm_stat_regs`, bit 34, `cm_id` 3 and bits 23:20 set), go bits 36, 37, 38 and clear bits 39, 40, 41 together. These could raise several facts from a single source to two sources, and the control value is a candidate for the "typical programmed value" the page lists as unknown.
2. The bench conflicts with the driver in three places that the page grades `established` or leaves unaddressed: (a) it clears the error status by writing zero to 0x60 (`err_status`) where the driver writes the value read to `clr_err_stat` at 0x68, so the access type `r` for `err_status` is not safe; (b) it writes `0x100020` to `rd_dma_ctrl`, setting bit 20, which the header leaves reserved (length 0x20 in 15:0 is as expected); (c) it polls `CM_STATUS` bits 51, 57, 58, 59 and 63 for SRAM calibration, where the header names 59:52 as `pending_int_reqs` and 63 as `alg_half_speed_sel`. It reads auxiliary read-DMA status as `0x400000` at the end, which is the header's `lrsp_buff_empty` (bit 22). The page's field names for status 59:57 should be treated as the header's naming only.
3. Appendix B of the guide (printed pages 229 to 231) lists the SSP packet types RASC uses (8-byte and partial 128-byte PIO reads, 128-byte memory reads and writes, 8-byte PIO writes in both directions, cache flush invalidate; FPGA-originated PIO writes use tnums 0xf0 to 0xff). The open-questions entry that calls the SSP packet format "no public source" should record this; the bit-level packet format itself is still not given.
4. The RASC page's "3.2 GB/s each direction" for the blade's NUMAlink channels is the figure's label; the surrounding blade text and figure also carry "1.6 GB/s each direction". Not resolved here.

**Cleared scope.** The register offsets, field ranges, constants, access sequences and driver quirks on this page and in `registers.toml` as graded software definitions, and the TIOCX and RASC packaging statements as corrected. Not cleared: the reading of the guide's chapters 5 to 9, any reset value or access type, and the packet format; findings 1 and 2 need a follow-up pass before the status bit names above 56 and `err_status` access are relied on.

**Not checked.** The decompiler was not used and the module's full control flow was not read; the DMA-control layout and the interrupt-allocation arguments in the shipped module were not compared. The Linux history tree 2.4 root and the community kernel trees were not consulted. The loader FPGA and the download driver were not checked (unknown on the page).
