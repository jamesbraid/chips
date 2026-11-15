# MBCS (RASC Core Services)

Mode: **no-spec**. **Not a chip**: MBCS is the register block of the "Core Services" part of an SGI RASC FPGA bitstream. It exists only
when such a bitstream is loaded behind the TIO's FPGA port ([TIOCX](../tiocx/README.md)). SGI's Linux driver `drivers/char/mbcs.c` and its header
`mbcs.h` (linux-5.3 pin 4d856f72c10e; copyright 2005) define it. For this generation that code is the vendor's software
source, so what it defines is **established** as a software definition, never as a measurement. Registers: [registers.md](registers.md) (26 registers).

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
algorithm-defined register offsets; the packet-level behaviour of the SSP; whether any bitstream other than SGI's RASC Core Services uses this register layout. Routes: the guide names
no register offsets in the pages read (chapters 5 to 9 and most of chapter 3 were not read), and no RASC driver beyond `mbcs.c` is public. See [the open questions](../../questions/tiocx-rasc-open.md).
