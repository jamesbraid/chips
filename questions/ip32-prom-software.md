# O2 PROM software: what the first reading left open

Question. What do the parts of the O2 PROM (revisions 4.8 and 4.18) that the first reading skipped do? The settled
parts are on [the PROM software page](../platforms/ip32/prom-software.md).

Status: **unknown** for everything below. Route: read the named routine in the held 6.5.30 PROM image.

- **XFER marker.** What writes `0x58464552` to `0x80000400` before the `0xbfc007e8` path jumps through `0x80000408`.
- **Private vector.** Roles of entries 1, 5, 6, 7, 8, 10 and 11 (`0x8100b0ec`, `0x8100ff1c`, `0x8100ffbc`, `0x8100e2a0`,
  `0x81032c28`, `0x8103a678`, `0x810181d0`).
- **Driver table.** The three records at `0x810542e0`..`0x810542f8` with parent tag 0 (`0x810200c0`, `0x81027280`,
  `0x81035810`).
- **Unused second copy.** Whether the `IP32.c` copy of the root, CPU and cache builders (`0x81023664`, `0x810236bc`) is
  ever executed.
- **Menu flag.** The effect of flag bit 0 on the menu descriptors at `0x81058644`, and what `0x81007010` programs.
- **4.18 raw flash dump.** `references/prom-images.md` records a raw 512 KiB dump of 4.18 with sha256 `a60e19b6…`; it is
  not in the firmware directory this reading used. The shipped 4.18 image is `11230c35…`. Route: compare the dump with
  the shipped image segment by segment (the environment segment and any stored state may differ).
- **Segment-level 4.8 versus 4.18 diff.** Only strings, the default environment table and segment sizes were compared.
