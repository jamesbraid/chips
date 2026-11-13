# AKM AK4381 stereo DAC (DMediaPro DM8, inferred)

Mode: **no-spec**. A stub: the part is never named in any shipped file read here.

- **Inferred.** Chip 1 of the DM8 driver's serial-control bus is an AK4381. The binary side is established: the IP35
  `mad_dd.o` writes registers 0 to 4 of a device with serial chip address 1 over GPIO (`mad_init_revolution`, `0x2b2c`;
  `mad_gpio_write_spi_register`, `0x28d8`), with a rate-dependent register 1 (values `3`, `11`, `19`) and two attenuation
  registers (3 and 4). The reasoning that makes it an AK4381: the public Linux driver (`sound/pci/ice1712/revo.c`, Linux 7.2-rc7)
  programs an AK4381 as chip address 1 on the board whose PCI sub-device ID (`1412:3630`) the IRIX driver tests for. The part
  name rests on that sibling-board match, so it is inferred, not established. Full register tables and the bus protocol:
  [../ice1724/README.md](../ice1724/README.md).
- **Unknown.** Register field meanings; the vendor datasheet is not held. A public AKM datasheet would settle them.
