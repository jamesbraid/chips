# AKM AK4355 six-channel DAC (DMediaPro DM8, inferred)

Mode: **no-spec**. A stub: the part is never named in any shipped file read here.

- **Inferred.** Chip 2 of the DM8 driver's serial-control bus is an AK4355: serial chip address 3, registers 0 to 10, six
  attenuation registers (4 to 9), rate-dependent register 2 (values `14`, `30`, `46`), chip select on GPIO bit 6
  (`mad_init_revolution`, `0x2b2c`; `mad_set_rate`, `0x2268`). The part name comes from the public Linux driver
  (`sound/pci/ice1712/revo.c`, Linux 7.2-rc7), which programs an AK4355 as chip address 3 on the board whose sub-device ID the IRIX
  driver tests for, so it is inferred. Bus protocol and values: [../ice1724/README.md](../ice1724/README.md).
- **Unknown.** Register field meanings; no datasheet is held.
