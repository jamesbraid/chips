# SGI RAD audio controller, PCI 10a9:0005 (stub)

Mode: **no-spec**. A stub: only the probe, window sizes and board dispatch of the driver `rad_dd.o` are recorded here. The
driver is present in the IP27, IP30, IP32 and IP35 builds. It drives the SGI PCI Digital Audio Board (hinv
`Iris Audio Processor: version RAD revision 12.0, number 1`, board installation guide 007-3502-003, p. 11, **established** as the
board's report). Which other machines carry the same part on a board of their own (the Octane and Octane2 system module
is the likely case, its audio ports are shown on the system module in 007-4207-002, p. 3) is **inferred** from the IP30 build
carrying this driver; the only other PCI audio driver in that build, `mad_dd.o`, probes the ICE1724 (PCI 1412:1724).

- **Established.** `rad_init` registers PCI vendor `0x10a9` (4265) and device `0x0005` with no flags in the IP27, IP30, IP32
  and IP35 builds (`rad_dd.o`, IP35 SHA-256 `e19248075cd2bb245f722f6b10792db5629f199eb71b7276eae87ecaec5438fc`, `rad_init`
  at `0x5110`; IP30 `0x4e9c`..`0x4ea0`; IP27 `0x506c`; IP32 `0x5074`).
- **Established.** `rad_attach` (IP35 `0x4fb4`) maps window space 7 for 32 bytes (config) and space 8 for 8192 bytes (BAR0), reads config
  `0x08` (size 4), and uses bits 7:4 as a board number; board 12 sets PCI priority 2, every other board priority 1
  (`0x5008`..`0x5040`). The PCI revision byte is `board << 4 | chip revision`; the hinv "revision 12.0" is board 12, chip
  revision 0.
- **Established.** No interrupt call is imported (only PIO windows, DMA address translation and error registration).
- **Not read here.** Register offsets, DMA engines, subcode and UST behaviour. The driver is 138 KB and carries ADAT, AES, A/D and
  D/A engines, a Genlock/"ksync" video clock path and a status-DMA path (strings such as `RAD UST not incrementing`,
  `one-shot status dma failed. Try power cycling the machine.`). Bringing it to the label standard needs the full-routine
  reading `docs/open-questions.md` now lists.
