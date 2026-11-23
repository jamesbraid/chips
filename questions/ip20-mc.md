# Indigo R4000 MC: what the MC page leaves open

Question. What does the MC memory controller of the Indigo R4000 (IP20) do where the held sources stop? The settled parts are on
[the MC page](../devices/mc/README.md) and the [address map](../platforms/ip20/address-map.md).

Status: **unknown** for everything below.

- **Which MC revision the Indigo carries.** `sysid` is never read by the Indigo PROM 4.0.5D; the kernel reads it. A and B read 0 and 1
  (specification); a "revision C" is at least 3 by the kernel's warning test. Route: a boot capture or `hinv`-style print of the revision
  from an Indigo, or the revision list the specification does not hold. Hardware residue: a read of `sysid` on a real board.
- **Reset values of `cpuctrl0` bit 18 and `gio64_arb` bit 0.** Both load from the serial EEPROM at reset (specification 2.9); the
  value that the Indigo's EEPROM holds is not in the PROM image. Route: a read of the EEPROM contents (public boot captures do not show it).
- **Reset values the specification gives for revision A and B only.** Whether revision C changed any reset value. Route: a revision C
  specification, or a read of an untouched register on a board with a rev C part (never-written registers only).
- **DMA block layout.** `dma_gio_mask` and `dma_gio_sub` bit layout; the `dma_ctl` fields beyond `ie`, `xlate`, `decslv` (the constant the
  kernel writes carries fields no held source names); `dma_count` fields; what `dma_memadrd` and `dma_memadrds` default. The
  specification's graphics-DMA section points at a separate document that is not held. Route: that document, or a read of the GR2 and LG1
  driver objects for these registers.
- **What a write to `cpu_err_addr`, `gio_err_addr`, `ref_ctr`, `dogc` read-only offsets does, and what a read of an unused MC offset returns.** The specification says the
  error status registers clear on any write; it does not say whether read-only registers ignore or bus-error writes.
- **Whether `sysid`, `cpuctrl1` and others have unlisted bits.** The specification lists bits 31:18 of `cpuctrl1` and the high bits
  of several registers as reserved; whether they read back as written is not stated.
- **Where the low alias of RAM ends** (also in [the PROM questions](ip20-prom-software.md)): the specification says 512 KiB; NT's use of 6 MiB
  is unexplained.
- **What an access to the EISA ranges returns on the Indigo**, and whether the second and third HPC1 windows (`0x1fb00000`, `0x1f980000`,
  `0x1f900000`) answer on a stock board.
- **4.0.5G was not re-read.** The 4.0.5G image (`070-8116-005`) is listed in the PROM catalogue but is not on the storage this reading used.
  Route: put the image where the reader can reach it, then confirm the clamp at the memory clear and the `rpss_divider` handling.
