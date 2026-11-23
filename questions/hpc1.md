# HPC1: what the first reading left open

Question. What does the Indigo's HPC1 do in the places the shipped IP20 objects and the 4.0.5D PROM could not settle? The settled parts are
on [the HPC1 page](../devices/hpc1/README.md). Route tag for all entries: **software now** unless noted.

Status: **unknown** for everything below.

- **Which HPC revision each Indigo carries.** Two public boot logs (an R4000 and an R3000 Indigo) print HPC1, not HPC1.5. The IRIX header says the
  endian register's bits 7:6 hold 1 on the 1.5. Whether every IP20 and IP12 board has an HPC1 without the endian register, or a part that reports
  another revision, is not read from any binary. Tried: both PROMs, the kernel and driver objects. Route: a hardware read. Reviewed 2026-11-23: the 4.0.5G PROM is
  held and its `+0xc0` accesses are identical to 4.0.5D's (a bit-0 test with a zero store, and a guarded zero byte store at `+0xc3`), so it adds nothing.
- **Descriptor completion flags.** Which bit of word 0 the HPC clears when a receive or transmit descriptor completes (the IRIX driver tests bit 31,
  the public driver bit 30 on receive). Tried: the IRIX Ethernet driver's whole interrupt routine, the public drivers. Route: read the receive
  recycling path in `if_ec2.o` against the descriptor writes with the debug build, or a model run against both drivers.
- **Reach of the buffer address.** Descriptors carry 28 address bits; the IRIX SCSI driver keeps a second physical address for memory above 128 MiB.
  How the HPC reaches memory at `0x20000000` and above on a machine with more than 128 MiB is unknown. Route: the MC page's remap rule and the SCSI
  driver's bounce path (`wd93_dma`).
- **Ethernet registers nothing writes.** `+0x08`, `+0x0c`, `+0x14`, `+0x18`, `+0x1c`, `+0x28`, `+0x44`, `+0x4c`, `+0x58`, `+0x5c`: the driver dump labels
  fix the names; meanings and side effects are unknown. The PROM stores `0x5a` to the byte at `+0x5b` and reads `+0x5f` during its power-on check.
- **SCSI `+0x98` and `+0x9c`, parallel `+0xbc`, and the strobe timing fields of `+0xa8`.** Named by the shipped header and the public driver; no
  object touches them.
- **DSP interface.** Every field of `+0x180` to `+0x1b4`. The audio driver object (`hdsp`) is not held; the `kdsp` archive reaches the block through a
  table of pointers and was not decoded. Route: decode `kdsp.a`'s register accesses with the pointer table, or find the `hdsp` object on a release
  that carried it. The PROM's SRAM load (tables at `0xbfc43360` and `0xbfc43990`) and its pass criterion (SRAM word 0 is 1 or 2) are read; what the
  tables hold is not.
- **Reset values.** None of the HPC1 registers has an established reset value. Route: hardware read, or a firmware path that reads one before it writes
  it (none found).
- **Write-all and protect-register details of the EEPROM.** `SER_WRALL` is named by the shipped header; no code was seen issuing it. Whether
  the protect-register write at word 125 survives power-off (the part's protect register is nonvolatile in the FM93CS56 datasheet, which is not
  held) is unknown. Route: the part's datasheet.
- **EEPROM word 0 after the byte-order flip.** The start-up flip routine XORs `0x8400` into word 0, whose high byte is the NVRAM checksum byte; the
  checksum algorithm excludes that byte, so the stored checksum would no longer validate. Who rewrites it is unknown. Route: trace the PROM's
  next boot of a flipped part, or read the little-endian path of the environment initialiser. Reviewed 2026-11-23: 4.0.5G has the same routine; the
  MC page says EEPROM bits feed CPUCTRL0 bit 18 and an HPC width bit at reset, which a checksum in word 0's high byte would corrupt. Route: the MC
  specification's text on which EEPROM bits are loaded.
- **Keyboard and mouse channels.** Which Z85C30 channel is the keyboard and which the mouse on the Indigo, and which of the three serial blocks is
  populated on each board. Route: the serial driver's port table and `du_keyboard_port`/`du_mouse_port`, read with its initialiser.
