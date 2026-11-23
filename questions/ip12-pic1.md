# R3000 Indigo (IP12): the PIC1 memory and bus interface

Question. What does the Processor Interface Controller (`PIC1`) of the R3000 Indigo do: its register map in the `0x1fa00000` page, how it
encodes and sizes the three memory banks, error reporting and its part in interrupts? The R3000 Indigo has no MC chip (see [the MC page](../devices/mc/README.md#ip12-r3000-indigo)).

Status: **unknown**.

- **Register map.** The 4.0.1 Rev C PROM (`070-8088-xxx`) reads `+0x04` once (`0xbfc15a20`), reads `+0x08` at seven sites and stores to `+0x210` (listing
  scan of constant-address pairs). No held document names the registers. Route: the R3000 Indigo schematic (`032-8044-003`, sheet 8) for the pin names; the 4.0.1 PROM listings
  for the access order; the IRIX 5.3 or earlier IP12 kernel objects (not held; IRIX 6.5 dropped IP12).
- **Memory sizing.** Three banks (`BANK0` to `BANK2`, schematic sheets 10 to 12). How the PROM finds their size and where it maps them is not read.
  Route: a reading of the 4.0.1 PROM's start-up code.
- **Address of the `PIC1`.** Inferred from the PROM's accesses and another project's model; the schematic states no address. Route: the PROM listing and the IP12 kernel header.
