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
- DMA from an FPGA device uses the TIO view of an address, with two bits stripped (`TIOCX_DMA_ADDR` clears bits 45:44, which the header calls address-space bits); a TIOCX-to-TIOCX view
  keeps bits 35:0 and moves bits 55:38 up by two.

## Open

Which bitstreams and products use the port (the RASC module of the Altix 350, 3700 and 4700 guides is a candidate, unproven), what a loaded bitstream's registers look like, and what the board-type constants correspond to
are **unknown**; the RASC user's guide (007-4718-007) is held but not read for this.
