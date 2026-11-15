# TIOCX and RASC open questions

Open points from reading SGI's Linux FPGA-port code (linux-5.3 pin 4d856f72c10e, `tiocx.c`, `mbcs.c`, `mbcs.h`) and the RASC user's guide (007-4718-007) for
[TIOCX](../devices/tiocx/README.md), [MBCS](../devices/mbcs/README.md) and [RASC](../platforms/sn2/rasc.md). Each entry: question, routes tried, next route. Route tag in brackets.

## Algorithm-defined and debug register offsets

[missing source] Where the guide's algorithm-defined registers (1 to 64, 8 by default) and the 64 debug registers sit in the window. The driver names only the debug region start (`0x100000`) and
reads its first register; the guide says the algorithm-defined registers' write capability overlaps the debug registers up to release 2.20. Routes tried: driver and header read in full; guide chapter 3 read
to the SRAM interface. Next: guide chapter 7 (extractor directives) and the sample test bench constants in chapter 3, a RASC library or driver header if one is published.

## Reset values and bit behaviour of the Core Services registers

[missing source] No reset value is stated anywhere read, and whether the go and clear bits of `control` self-clear, or the clear register bits are write-one-to-clear, is not stated. The driver sets bits by
read-modify-write, so a sticky go bit would restart an idle engine at the next start; it works, which suggests self-clearing (inferred, not graded as a fact). Routes tried: driver, header, guide pp. 22 to 29. Next: the guide's core-services
register chapter if a later revision (007-4718-004 to -006 are held, unread) has one.

## What the second part number means

[missing source] `0xf001` ("ALG0") against `0xfff0`. Both bind the same driver. Routes tried: header, driver. Next: guide algorithm-configuration chapter, an algorithm-ID table.

## Which board types carry the FPGA port

[missing source] The driver scans three controller board types (SA brick, Athena brick, Daytona board). The Kconfig says "SABrick" for the core-services driver. The guide never names these. Which board type is the first-generation
brick and which is the 4700 blade is unknown (inferred only that SA is the brick). Routes tried: v5.3 `l1.h`, Kconfig, guide pp. 9 to 12. Next: the L1 controller guide (007-3938) brick type tables; the 4700 and 450 user guides.

## Whether the Core Services driver shipped as a module

[missing binary] The SLES 9 SP3 SN2 kernel carries the bus code but no `mbcs` symbol, and no module is held. Routes tried: symbol table of the held kernel (readelf, not Ghidra) and the community Prism kernel, which has `mbcs.c` in its symbol table
(a FILE entry only). Next: a ProPack module package; none is held.

## The SSP packet format and the loader FPGA

[unknown, no public source] The guide's SSP, SRM and SXM blocks are described in one paragraph each; the packet format, the loader FPGA's PCI interface and the download driver are not public. No software route in this repository reaches them.
