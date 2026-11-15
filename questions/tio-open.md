# TIO open questions

Open points about the TIO that SGI's Linux Altix platform code (linux-5.3) does not settle. Each entry: question, routes tried, next route.

## ITTE use

[missing source] The flush path picks ITTE entry 0 whenever the node offset has bit 33 or above set, and entries 1 to 7 only when those bits are clear and bits 32:30 are nonzero. The address header says a TIO node offset always has its top bit set, which would make entry 0 the only one a real address reaches. Either the offset is narrower than the header's top bit implies on this path, or entries 1 to 7 map windows whose offsets have the top bit clear. Routes tried: `addrs.h`, `tio.h`, `pcibr_dma.c`. Next: a TIO register specification, or the held SN2 PROM's ITTE setup code (read with Ghidra).

## TIO interrupt delivery

[missing source] The kernel says bridges behind a TIO do not target SHub 2 interrupt registers, and a TIOCE rev A workaround stores a word to a TIO address taken from the interrupt's Crosstalk address. The register or message path that turns such a store into an interrupt vector on a CPU is not described. Routes tried: the files above and `tioce_provider.c`. Next: the SN2 PROM's TIO setup and the TIO register specification.

## TIO local-block register map

[missing source] Only the identification word and the three ICE registers are named. The local block, link layer, error registers and the system controller UART (the PROM reading puts it at `0x9003_8000`, inferred) have no source. Next: Ghidra reading of the held SN2 PROMs for `sc_tio_*` and the error decoder.

## TIO_NODE_ID upper bits

[inferred] The Linux code reads only the low 32 bits of the register at node offset `0x90060e80` as a widget identification word. Ghidra's reading of the SHub 2 PROM (build 10.40, SAL 1.40) shows the function at `0xff4ae920` read-modify-writing the same offset with a 14-bit value (the node's NASID) at bits 45:32 and a 6-bit value at bits 53:48 (a power of two derived from a size argument). So the register is not read-only and carries more than the identification word. The PROM's accessor is generic and the caller was not traced to confirm the node is a TIO, so the match rests on the offset and the 14-bit width. Next: trace the caller at `0xff46ec90` and the 6-bit field's source, and read the other PROM builds.
