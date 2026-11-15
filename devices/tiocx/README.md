# TIOCX

Mode: **no-spec**. **Not a chip**: TIOCX is SGI's Linux driver bus for the FPGA port of a [TIO](../tio/README.md), "CX" for the corelet extension port at widget 3 of the
TIO's small windows. The kernel header and driver (linux-5.3 pin 4d856f72c10e, `tiocx.h` and `tiocx.c`) define a bus type `tiocx` whose devices are whatever FPGA bitstream is
loaded behind that port; drivers match on the widget part and manufacturer number found at offset 0 of the port's window. There is no register map of its own: the three ICE registers
and the corelet number the driver uses are in [../tio/registers.md](../tio/registers.md), and the procedure is on [the TIO page](../tio/README.md).

## What the driver establishes

- Only TIO nodes (odd NASID) whose I/O board type, asked from the controller, is one of the three FPGA-carrying board types the driver lists
  (a "SA", an "Athena" and a "Daytona" board type in the controller header) are scanned. Those names are the controller's board-type constants; no product name is given.
  A TIO whose widget 3 reports part `0xce00` is a [TIOCE](../tioce/README.md) on the same port and is skipped.
- At attach the driver resets corelet 3, enables the conveyor and registers a device with the widget's part and manufacturer numbers. A part number of zero means no bitstream is loaded;
  such a device is still registered so user space can see the state. A per-device control file accepts 1 (reset then reload), 2 (reload) and 3 (reset only).
- Interrupts for devices on the port are allocated through a firmware call that takes the TIO NASID, the widget, a kernel vector and a target; the TIOCX error vector is `0x37`.
- DMA macros: the header also defines a DMA mask for an FPGA device (see below for what the driver actually uses), with two bits stripped (`TIOCX_DMA_ADDR` clears bits 37:36 and keeps only the low 56 bits; the header's comment calls this stripping the address-space bits); a TIOCX-to-TIOCX view
  keeps bits 35:0 and moves bits 55:38 up by two.

## What sits behind the port

In the public Linux tree one driver binds to it, the FPGA Core Services driver, which matches part `0xfff0` or `0xf001` with manufacturer 1 and presents the [MBCS register block](../mbcs/README.md)
(established, `drivers/char/mbcs.c`). SGI's RASC user's guide (007-4718-007, printed pages 9 to 12) describes the port as the TIO's "SSP" and gives the packaging, see [RASC](../../platforms/sn2/rasc.md). That the SSP and the
driver's corelet 3 are the same port is **inferred**: the guide says the FPGA connects to the TIO's SSP port and the driver calls the FPGA port the CX port, and no text equates them. Interrupts a bitstream raises
reach the host through vectors the firmware allocates per device (the driver asks for three, one per engine); the defined vector `0x37` is not used by the files read.

The exported helper `tiocx_dma_addr` (used by the Core Services driver) applies the TIO DMA view `PHYS_TO_TIODMA`, the view the TIO's other bridges use, and does not use the `TIOCX_DMA_ADDR` mask this page lists above
(established, `tiocx.c` and `mbcs.c`). The mask is defined and unused in the files read.

The shipped SN2 kernel (SLES 9 SP3, 2.6.5-7.244, symbol table read with `readelf`, not Ghidra; no function was decompiled) carries `tiocx_init`, `tiocx_match`, `cx_device_probe`, `tio_corelet_reset`,
`tiocx_reload`, `tiocx_irq_alloc`/`_free` and the exported `cx_*` registration functions, plus `show_cxdev_control` and `store_cxdev_control` (established: the code shipped). No `mbcs` symbol is in that kernel image: its configuration sets the Core Services driver as a module (`CONFIG_SGI_MBCS=m`) and the same release's kernel package carries `mbcs.ko` (established, see the review on the [MBCS page](../mbcs/README.md)).

## Open

What a bitstream other than SGI's Core Services looks like on this port, and which products and board types carry it, are **unknown**; the board-type constants
come from the controller header with no product name. Bitstream-dependent behaviour (reset values, the algorithm registers, the SSP packet format) is recorded as unknown on the
[MBCS page](../mbcs/README.md) and in [the open questions](../../questions/tiocx-rasc-open.md).

## Review

The "What sits behind the port" section and the MBCS and RASC pages it links were reviewed on 2026-11-15; see [the MBCS page review](../mbcs/README.md#review).

Independent review on 2026-11-14 by a reviewer who did not write these pages. Revisions: chips commits 4924130..b536f7d, read at main 15a5a4e484. Grading rule: the SN2 paragraph of the evidence order in `retools/tools/README-analysis.md` (SGI's Linux platform code ranks first for this generation, and a fact it defines is `established` as a software definition). Sources: the Linux v5.3 files the page cites, fetched singly from the tagged tree (`drivers/misc/ioc4.c` and `include/linux/ioc4.h` at v4.19, where they still exist).

**Reviewed commits.** 6ee0360 (tiocx page). The page has no register file; its three ICE registers live in [the TIO page](../tio/registers.md).

**Checked.** Every statement against `tiocx.c` and `tiocx.h`: bus type name, match on part and probe on part plus manufacturer, odd-NASID and board-type scan (`L1_BRICKTYPE_SA`, `L1_BRICKTYPE_ATHENA`, `L1_BOARDTYPE_DAYTONA`), skipping a part 0xce00, corelet reset and conveyor enable at attach, device registered even with no bitstream, the control file's 1, 2 and 3, the interrupt-allocation firmware call arguments, the DMA macros and the TIOCX-to-TIOCX macro (bits 35:0 kept, 55:38 moved up two).

**Findings.**
- Fixed (mechanical): `TIOCX_DMA_ADDR` was said to clear bits 45:44. The mask `0xffffcfffffffff` clears bits 37:36 and every bit above 55. Corrected in the page.
- Judgement, left: "A part number of zero means no bitstream is loaded" is the driver's reading, but zero part and manufacturer numbers also result when the clock reset fails after a bitstream was seen; the page's wording is slightly stronger than the code.
- Judgement, left: the board-type constants are named brick or board types in the header (two `BRICKTYPE`, one `BOARDTYPE`); the page calls all three board types. The page already says no product name is given.
- `SGI_TIOCX_ERROR` (0x37) is defined but not registered in the files read; see the TIO page review.

**Cleared scope.** The driver-bus description and DMA macros as corrected. Not cleared: which bitstreams or products use the port (the page marks this unknown).
