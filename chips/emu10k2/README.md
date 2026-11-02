# Creative EMU10K2 audio controller, PCI 1102:0004 (IP35 build driver `emu_dd.o`)

Mode: **no-spec**. A stub: the probe and the access shape are read, the rest is not.

- **Established.** `emu_init` (`0x0`) in `IP35/usr/cpu/sysgen/IP35boot/emu_dd.o` (SHA-256
  `621698b1da9928b6262022021e17d53d4a86b50e3f637ca6c5f8d4b422d817b4`) registers PCI vendor `0x1102` (4354) and device `0x0004`
  with no flags. `1102:0004` is the Sound Blaster Audigy in the public PCI ID list. The driver exists in the IP35 build and
  not in the IP27, IP30 or IP32 builds. Its object is linked into the IP35 kernel (the string `emu_dd: could not allocate memory
  for subsystem` is in the linked kernel).
- **Established.** `emu_attach` (`0x30`) maps window space 8, 32 bytes, flag word 8192, sets config byte `0x0d` to all ones, sets PCI priority
  1. 32 bytes is the public Audigy's I/O port block size.
- **Established as code, role unknown.** `emu_ac97_write` (`0x33e0`) polls byte offset `0x1e` bit 7, then stores a halfword
  and a byte in the register block at `0x1c`/`0x1e` and bytes at `0x1c` (the lane arithmetic gives CPU addresses `+0x1c` and
  `+0x1f`), then waits 25 microseconds. The debug dump strings name a STAC97 codec's GPIO register, an AC'97 register
  link-down message, analog input and output, record select, record gain and record mic gain registers, and "voice"
  routines (`emu_voice_*`, `emu_init_efx`, `emu_wrefx`) that load an effects program.
- **Inferred.** The part is the EMU10K2 of the Audigy. The hinv string for it is `Iris Audio Processor: version EMU revision %02X, number %d`,
  with revision the PCI revision byte plus `0xa0` (established: `emu_create_subsys` `0x2f0`). Published hinv captures show it on Fuel, Tezro,
  Origin 300, Origin 350 and Onyx 350 with the Audigy FireWire and game-port functions beside it: an add-in Creative card, not the Tezro tower's
  onboard audio, and absent from IRIX 6.5.22. Detail and sources: [docs/audio/drivers.md](../../docs/audio/drivers.md).
- **Unknown.** Every register meaning, the product that carries it, the DMA programming, the interrupt connection (none is
  imported). Route: read `emu_voice_setup`, `emu_start_dma`, `emu_init_efx` in full against the public Linux `emu10k1`
  driver; find the SGI product name for the card.
