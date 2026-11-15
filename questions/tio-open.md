# TIO open questions

Open points about the TIO that SGI's Linux Altix platform code (linux-5.3) does not settle. Each entry: question, routes tried, next route.

## ITTE use

[missing source] The flush path picks ITTE entry 0 whenever the node offset has bits above 33 set, and entries 1 to 7 only when those bits are clear and bits 32:30 are nonzero. The address header says a TIO node offset always has its top bit set, which would make entry 0 the only one a real address reaches. Either the offset is narrower than the header's top bit implies on this path, or entries 1 to 7 map windows whose offsets have the top bit clear. Routes tried: `addrs.h`, `tio.h`, `pcibr_dma.c`. Next: a TIO register specification, or the held SN2 PROM's ITTE setup code (read with Ghidra).

## TIO interrupt delivery

[missing source] The kernel says bridges behind a TIO do not target SHub 2 interrupt registers, and a TIOCE rev A workaround stores a word to a TIO address taken from the interrupt's Crosstalk address. The register or message path that turns such a store into an interrupt vector on a CPU is not described. Routes tried: the files above and `tioce_provider.c`. Next: the SN2 PROM's TIO setup and the TIO register specification.

## TIO local-block register map

[missing source] Only the identification word and the three ICE registers are named. The local block, link layer, error registers and the system controller UART (the PROM reading puts it at `0x9003_8000`, inferred) have no source. Next: Ghidra reading of the held SN2 PROMs for `sc_tio_*` and the error decoder.
