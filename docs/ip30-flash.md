# IP30 boot flash

The IP30 boot PROM sits in flash that the Bridge chip drives. This page records what the published
Bridge specification settles about that interface and what it leaves open. The register bits are in
`devices/bridge/registers-extra.toml`. The fitted flash part is not identified in this repository, and the PROM's
own flash code has not been read here, so nothing below says how software uses the flash.

Sources: Bridge ASIC specification rev 4.0 (3/27/97), `docs/sources/specs/bridge-asic-specification-rev4.0.pdf`.
The file is a scan with no text layer; the pages cited were read as images.

## Pins and configuration

| Fact | Grade | Where |
| --- | --- | --- |
| The flash and the local SSRAM share the address pins `SSRAM_A(20:0)`, the data pins `SSRAM_D(15:0)` and the write enable `SSRAM_WE_N`. | established | section 2.1.3, table 3, printed page 12 |
| The flash has its own output enable, `FLASH_OE_N`, and two chip selects, `FLASH_CS(1:0)_N`. | established | section 2.1.3, table 3, printed page 12 |
| The flash data path is 16 bits wide. | established | section 2.1.3, table 3, printed page 12 |
| The controller supports flash configurations up to 2M x 16. | established | section 1.10, printed page 6 |
| The hard-wired strap `FLASH_SELECT` chooses which chip select serves the flash at address `0xc00000`: 0 for CS0, 1 for CS1. | established | section 2.1.4, table 4, printed page 13 |
| Status register bit 6 reports the strap. The register is read only and its reset value is undefined. | established | section 3.2.2, table 8, printed page 20 |

## Writes

| Fact | Grade | Where |
| --- | --- | --- |
| Control register bit 31, `FLASH_WR_EN`, resets to 0. Set, it allows writes to the flash. Clear, a flash write is an error and is not completed. | established | section 3.2.5, table 11, printed page 21 |
| The specification does not say what Crosstalk response a refused flash write produces. | unknown | section 3.2.5, table 11 |

## Address window and size

| Fact | Grade | Where |
| --- | --- | --- |
| The widget-space address map ends at `0x1f_ffff` and lists no flash range. The only flash address the specification names is `0xc00000`, in the strap and status text. | established | section 4.2.4, table 43, printed page 55; pin and status text above |
| The flash window's extent in widget space is not given. | unknown | as above |
| Twenty-one address lines reach 16-bit words, so a full 2M x 16 array is 2^21 words, or 4 MiB, not 2 MiB. | inferred | arithmetic on `SSRAM_A(20:0)` and the 2M x 16 limit |
| Which array size the board wires, and whether address bits above the fitted part alias back into it, is unknown. | unknown | board wiring |

## Conflict: bit 31 on the IP30 Bridge

The IRIX kernel's `pcibr_map` sets control bit 31 and `pcibr_unmap` clears it (the widget control row in
`chips/bridge/README.md`). The specification names bit 31 as the flash write enable. Either the kernel
toggles flash writes around device mapping, or the bit means something else in the chip revision the
IP30 board carries. The sources read here do not decide which. Settling it needs the kernel's
`pcibr_map` call sites read in full, or a published revision of the Bridge specification that
redefines the bit.

## Unknown

- The fitted flash part and its size.
- The board wiring of `FLASH_SELECT`, the upper address lines and the chip-select routing.
- The Crosstalk response to a refused flash write.
- The meaning of control bit 31 on the IP30 Bridge (see the conflict above).

## Not imported

- The Sharp LH28F800SU command interface. The part is not identified on any SGI board here, and a
  manufacturer's command table would describe the wrong chip if the board carries another.
- The flash identification and programming sequences the IP30 PROM issues. The IP30 PROM image is not
  held in this clone, and repository facts come from the binaries and published sources.
- An alternate flash window at `0xe00000`. The public header that names it is not in this clone.
- Crosstalk read and write size rules for the flash window. The passages read (printed pages 6, 12,
  13, 20, 21, 55, 88) do not state them. Chapter 6 (error cases, printed pages 77 to 84) and section
  8.3 (PCI operations, printed pages 98 to 100) are the next place to look.
