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
- **Menu flags.** What `0x81007010` programs. (Flag bit 0 greys a menu button, bit 1 gates the entry on `0x81025b00`,
  bit 2 hides it from the text menu; see [prom-assets.md](../platforms/ip32/prom-assets.md). What `0x81025b00` tests is
  still open.)
- **4.18 raw flash dump.** `references/prom-images.md` records a raw 512 KiB dump of 4.18 with sha256 `a60e19b6…`; it is
  not in the firmware directory this reading used. The shipped 4.18 image is `11230c35…`. Route: compare the dump with
  the shipped image segment by segment (the environment segment and any stored state may differ).
- **Segment-level 4.8 versus 4.18 diff.** Only strings, the default environment table and segment sizes were compared.

Assets (see [the assets page](../platforms/ip32/prom-assets.md)). Route for each: read the named routine in 4.18, or a
capture of the stock PROM on hardware, as a last resort.

- **Logo binding.** Where the PROM stores the run-length logo's data pointer and its 494 by 237 size in the root-window
  record (offsets `0x1c`, `0x20`, `0x24`). The pointer, 494 and 237 do not appear as code immediates, and the words
  `494, 237` sit after the image data at `0x8105f14c`.
- **Large-logo layout.** The branch at `0x81048a50` taken when the logo width is 601 or more (uses root-window flag
  bits at offset `0x20`); never taken by this logo.
- **Screen-row flip.** The value in the halfword at `0x81060ab2` and where it is set; the flip is 1024 on a 1280 by
  1024 screen only by measurement.
- **Stipple bit order.** Whether bit 15 of each bitmap halfword is the left pixel on a real GBE and CRIME drawing
  engine; confirmed only by a model's pixel output.
- **Glyph oddities.** Whether codes `0x80..0x9f` and `0xa0` aliasing earlier font entries is intended, and whether
  font 1 entry 4 (18 rows from two halfwords before the end of its bitmap region) is ever drawn.
- **Button states.** The ring colours for the pressed, focused and inactive states (pointer tables at `0x8105f5f0` and
  `0x8105f600`), and the other dialogs' frames, captions and vertical placement (`0x810136d4`, `0x8103c818`,
  `0x8103c2d0`).
- **Palette gaps.** The indices the palette routine never writes (`0x0b`..`0x0d`, `0x0f`..`0x13`, `0x21`, `0x22`,
  `0x28`..`0x2f`, `0x3b`..`0x5f`) and whether anything draws with them.
- **Hourglass and mono bitmaps.** The five-entry `{pointer, width, height}` table at `0x8105f57c` (6 by 20, 12 by 23,
  11 by 20, 4 by 20 and 22 by 22, the last probably the hourglass) and the mouse pointer: not read.
- **Sound units.** The unit of voice word 2 and of the mix-buffer size (the renderer steps 8 bytes per sample, the start
  offset 4 bytes per unit, the buffer is sized 4 bytes per unit), the output sample rate, the ring format behind the
  attenuation and the conversion at `0x81001590`, and the audio-present test at `0x81000910`.
- **Layout on other screens.** The 600-line and narrower layouts of the menu and dialogs, the `monitor` and `crt_option`
  modes, and whether `sgilogo` or the 700-line threshold changes anything beyond hiding the logo.
- **Bit 0 of the logo flag word.** `0x8107215c` bit 0 also means no big logo (readers mask `0x10001`); what sets it is not found.
- **Sound seed.** The first LCG seed is stale stack (`0x81000e48`); whether the noise is meant to vary is open.
