# RASC (reconfigurable application-specific computing) on Altix

RASC is SGI's name for an FPGA co-processor attached to an Altix through the TIO's FPGA port. This page is the machine view; the register view is [MBCS](../../devices/mbcs/README.md) and the
bus is [TIOCX](../../devices/tiocx/README.md). Source: SGI, *Reconfigurable Application-Specific Computing User's Guide*, `007-4718-007` (January 2008), printed pages as cited; Linux v5.3 as `v5.3:path`.

## Packaging (established, guide)

- **First generation (brick).** "SGI's first generation peer attached I/O brick" with a TIO that attaches to NUMAlink directly "instead of being driven from a compute node using the XIO channel". The TIO supports two PCI-X buses,
  an AGP-8X bus and the Scalable System Port (SSP), which connects the FPGA. The RASC card holds the co-processor FPGA, SRAMs and a small loader FPGA on 33 MHz PCI (p. 9 to 10, figure 1-4: 72-bit SSP to the algorithm FPGA, 36-bit SRAM ports).
  The Linux Kconfig text for the core-services driver says "SABrick", and the TIO bus driver scans a TIO whose board type is the SA brick, the Athena brick or the Daytona board. That the SA brick is this brick is **inferred** (the guide does not name it).
- **Blade (Altix 450 and 4700).** One blade carries two computational FPGAs, two TIOs and a loader FPGA with a PROM; each FPGA is on an SSP of its own TIO, each TIO has NUMAlink channels (3.2 GB/s each direction),
  and each FPGA has five 8 MB QDR SRAM DIMMs (p. 11 to 12, figure 1-5). Up to eight RASC blades per single system image, with two compute blades per RASC blade (p. 19). The guide also says optional brick packaging exists for legacy systems (p. 12).
- **FPGA.** A Xilinx Virtex-4 LX200 (XC4VLX200-FF1513-10) with the bitstream holding the algorithm and Core Services (p. 22). The blade text also says 200K logic cells.

## Loading (established, guide and Linux)

The loader FPGA loads the bitstream; the host side is a device manager (`devmgr`, a client and server over TCP) with a bitstream registry of `.bin` files plus two `.cfg` files, an algorithm device driver and a download driver (p. 13, 167 to 176).
The Linux side sees only the result: the TIO bus driver resets the FPGA port's corelet, tests a credit status register for "bitstream loaded", resets the clock and reads the identification word ([TIOCX](../../devices/tiocx/README.md)).
The download driver and the algorithm driver of the guide are not in the public Linux tree; their registers and the loader FPGA's interface are **unknown**.

## What a model must provide

To run `drivers/char/mbcs.c`: a TIO whose I/O board type reports one of the three FPGA board types, a credit status of 15 in the transmit credit register, an identification word of part `0xfff0` or `0xf001` with manufacturer 1,
and the [MBCS register block](../../devices/mbcs/registers.md) with three RAMs, two DMA engines and an interrupt per engine. Whether any real system had the SA brick in a retail configuration is **unknown**.

## Which machines (inferred)

The guide's system overview chapter covers the Altix 350 (p. 15 to 17) and the Altix 450 and 4700 (p. 17 to 20) and is generic: it adds no RASC topology beyond the packaging above. Other models are not named in the pages read.
Product pages: [Altix 350](altix-350.md), [Altix 4700](altix-4700.md).
