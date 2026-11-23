# Everest IO4 PROM monitor 4.21: what the reading left open

Question. What did the reading of the three 4.21 monitor builds (IP19, IP21, IP25) leave unsettled? The settled parts are on
[the Everest PROM software page](../platforms/everest/prom-software.md); the container is described in
[everest-prom-payloads.md](../software/firmware/everest-prom-payloads.md).

Status: **unknown** for everything below. The CPU board's own reset PROM is not held, which is the cause of most of the entries. `0xbfc00028` is passed as a launch address at IP19 `0x8180422c`; the stub at `0x81800610` that jumps to it has no caller.

- **Reset-time byte order.** What the CPU is set to when the monitor starts, and what sets it. The monitor only reads Config bit 15 and writes
  its inverse to slot-block offset `0x70` in the IA register test. Tried: every Config access in all three images, every store to `+0x70`.
  Route: the CPU board's reset PROM, the R4400, R8000 and R10000 manuals for the strap, or the IO4 and CC documentation for the register at `+0x70`.
- **The register at slot-block `+0x70`.** Whether it is an IO4 byte-order control and what a set bit does. Route: IO4 (IA chip) documentation, or a
  trace of the IRIX kernel's access to it.
- **What writes the `XFER` block at `0x400`.** Tried: a `lui`/`ori` scan of the IP19 image found no store to it; IP21 and IP25 were not scanned. Route: the CPU board's reset PROM.
- **Everything the earlier stage leaves in low memory.** Who writes the board table at `0x2000` (108-byte entries), the processor table at `0x3000` (64-byte
  entries) and the words at `0x26d0` to `0x26d8`, and the meaning of the fields beyond type, slot number, adapter type and bank record. Tried: stores through
  every `0xa000…` base in IP19. Route: the CPU board's reset PROM.
- **Unit of the memory size word at `0x26d0`.** The monitor uses its value shifted right by 4 as a page count, which gives 256-byte units. Route: the
  reset PROM, or a captured run that prints the descriptor list.
- **MC3 registers.** The bank base, size and interleave encoding, and how RAM is placed at physical 0 and across banks. In the IP19 build the monitor does not
  program MC3 as far as the listings show (IP21 and IP25 not scanned), but prints bank records (IP, IF, size, base). Route: MC3 documentation or the earlier stage.
- **Overlapping seeded descriptors.** The free range from `0x4000` to `0x1600000` contains the firmware entry at `0x1580000`; whether a later pass
  splits it. Route: read the list walkers after the seed (IP19 callers of `0x8181c208` and `0x8181c324`), or a capture of the descriptor dump.
- **Why IP21 starts free memory at `0x6000`.** Two pages `0x4000` to `0x5fff` are not described on IP21. Route: IP21 users of those pages.
- **IP21 and IP25 physical addressing.** Why the CPU-local block is at `0x4_1800_0000` on IP21 and `0x1800_0000` on IP25 and IP19, and why IO4 windows
  are at `0x4_0000_0000` on IP21 and IP25 and `0x1000_0000` on IP19. Route: the system-bus address decode in the CC and IO4 documentation.
- **Slot-block and CPU-local registers.** The meaning of `+0x00`, `+0x08`, `+0x18`, `+0x28` to `+0x50`, `+0x88`, the offsets `0x100` to `0x908` of the CPU-local block,
  and of the `0xb8000830` loop. Route: the CC and IA documentation.
- **IO4 adapter IDs.** What IDs `0x11`, `0x12`, `0x20`, `0x30`, `0x31` and adapter type `0x2b` are. Route: the IO4 documentation, or the VME and graphics
  paths in the monitor.
- **Large windows.** What the `window` argument of `0x81805a80` and `0x81805ab4` selects, and who calls them.
- **EPC.** Its three serial register groups, the Ethernet registers (the base the `et0` driver forms its offsets against is not established), the parallel port, the Ethernet address PROM and the SCSI controllers. Route: read the
  `et0` driver and the SCSI paths in full.
- **NVRAM layout.** Where the environment, serial number and Ethernet address live. The first check byte (byte 0) samples only the 32 multiples of 32 below `0x400` and skips zero bytes, the second (byte `0x368`) covers bytes 0 to 4057 except `0x31b` and `0x368`. Byte `0x31b` is a read-and-clear request byte (3 calls `0x81800230`, 4 calls `0x81800d00`); who writes it is unknown.
- **Graphics adapter.** How the monitor finds the RealityEngine2 board and loads microcode.
- **Private ARC vector.** The 13 slot roles and slot 34 of the firmware vector. The IP21 and IP25 SPB's 16-bit field at `+0x10`.
- **Differences not compared.** The IP21 and IP25 diagnostics, cache code and command set were not compared function by function.
- **Flag word `0x26d8` bits 0 and 15.**
