# O2 PROM visual and audio assets: palette, gradient, fonts, icons, logo, tunes and menu layout

The O2 (IP32) PROM draws its graphical menus and plays its start-up sound from data inside the `firmware` segment. There
is no image file and no compression: a computed palette, a computed background gradient, four bitmap fonts, ten layered
icons, one run-length logo, a small glyph set for the tagline, and 64 voice descriptors for a plucked-string synthesiser.
This page gives the exact layout of each, how it decodes, and where it sits in PROM 4.18 and PROM 4.8, so an extractor
can be built from it. It carries no decoded bitmap, glyph or table bytes: a reader pulls those from the image.

Sources and grades:

- **PROM 4.18** (sha256 `11230c35…`, the IRIX 6.5.30 media image) and **PROM 4.8** (sha256 `820585be…`, the IRIX 6.5
  media image), both read as MIPS code and data from the shipped files. Every routine named below was read from its first
  instruction to its return; a table is **established** when the code that consumes it was read and the table's bounds
  were checked against the bytes. Layout of the images and the load map are on
  [prom-software.md](prom-software.md); this page does not repeat them except where addresses depend on them.
- **Pixel check.** A reconstruction of the System Maintenance Menu from the decoded data matched a 1280 by 1024
  framebuffer capture of the stock 4.18 PROM running on a machine model in 0 of 1 310 720 pixels. That is model
  behaviour, not a hardware capture. It confirms bit order and orientation where the code cannot (marked below) and says
  nothing about a real GBE.
- **Grades.** **Established**: read in full in the listing. **Inferred**: a reading built from names, call shapes or the
  model check. **Unknown**: not settled; the open items are in
  [../../questions/ip32-prom-software.md](../../questions/ip32-prom-software.md).

## Where the bytes are

The firmware segment is three chunks, so a run-time address is not a flat file offset (established, loader records read
in both images):

| Chunk | Run-time range, 4.18 | Segment offset of data | Run-time range, 4.8 | Segment offset of data |
|---|---|---|---|---|
| text, includes the 0x40-byte header | `0x81000000`..`0x81048e70` | `0x00000` | `0x81000000`..`0x81048350` | `0x00000` |
| read-only data and strings | `0x81048e70`..`0x81054100` | `0x48e78` | `0x81048350`..`0x81053470` | `0x48358` |
| initialised data | `0x81054100`..`0x8105ffe0` | `0x54110` | `0x81053470`..`0x8105f260` | `0x53480` |

Segment offset = address - `0x81000000` for text, + 8 for read-only data, + 0x10 for initialised data (the same shifts
in both builds). Flash offset = segment offset + `0x9200` (+ `0x100` when the file has the container header). Everything
the assets use, apart from code, is in the initialised-data chunk, so every table below sits 0x10 bytes later in the
file than its address. A flat load at `0x81000000` puts every data pointer 0x10 bytes off.

The start-up and sound code at the bottom of the text sits at the same address in both builds; everything above it moved
(4.18's text is 0xb20 bytes longer). Every routine named below matches its 4.8 counterpart instruction for instruction,
apart from relocated addresses and the palette-write routine described under the toolkit. Addresses for both builds are
in each section.

## The drawing toolkit the assets go through

A small toolkit draws everything. Its device table of function pointers is at `0x8105f1d4` (4.18) and `0x8105e454`
(4.8); the first seven entries that matter here (established, each read in full):

| Slot | 4.18 routine | Job |
|---|---|---|
| 1 | `0x81039c88` | set the current colour index (the byte is replicated into a 32-bit word and written to two drawing registers) |
| 2 | `0x81039cb4` | write palette entry: `(device, index, r, g, b)` |
| 3 | `0x81039d88` | filled rectangle between two inclusive corners; one row is a degenerate rectangle |
| 4 | `0x81039e6c` | plot one point (inferred from the single coordinate write) |
| 5 | `0x81039f18` | set the pen position `(x, y)` in two words at `0x810720c0` and `0x810720c4` |
| 6 | `0x81039f30` | blit a 1-bit bitmap at the pen using the current colour |

Colours are palette indices; the drawing is 8 bits per pixel. The toolkit's y axis points up: y = 0 is the bottom row.
Primitives flip against a stored screen height. The halfword holding it (`0x81060ab2`) is set at run time and was not
traced; the measured result is screen row (counted from the top) = 1024 - y for a 1280 by 1024 screen (**inferred**).

**Blit (slot 6), established.** The caller passes a record `{bitmap pointer, width, height, -xoffset, -yoffset, advance,
0, stride}` with stride = (width + 15) / 16 halfwords. The routine draws `height` rows starting at the bottom, moving up
one row each time. Each row is `stride` big-endian halfwords handed unchanged to the drawing engine's stipple
register, 16 pixels at a time for rows wider than 16. Left edge = pen x + xoffset; bottom row = pen y + yoffset, where
the entry's offsets are the signed bytes stored in the font and glyph tables. The leftmost pixel is the most significant
bit: **inferred** (the engine's stipple convention is outside this page; the pixel check above confirms it).

**Palette write (slot 2), established for 4.18.** The routine waits on a status word in the display controller
(offset `0x58000` from its base, low six bits; it waits for zero, or for 0x3f when a mode helper at `0x8100c554` returns
2 or more), then, if the device is the active one, stores `r << 24 | g << 16 | b << 8` at base + `0x50000` + 4 * index.
That is the GBE colour-map RAM layout. **4.8 differs**: its routine (`0x81039214`, no mode helper) waits for the whole
status word to read zero and then does the same store.

## Palette

The routine at `0x81030270` (4.18) / `0x8102f7d0` (4.8) writes the palette through slot 2 (established). The two
builds' routines are identical except for relocation. Entries, as `(r, g, b)`:

- 0 black, 1 red, 2 green, 3 yellow, 4 blue, 5 magenta, 6 cyan (full-scale primaries), 7 `(240, 240, 240)`,
  8 `(127, 158, 191)`, 14 `(64, 64, 192)`.
- 9 and 10 both take the `pagecolor` environment variable if it parses, otherwise `(96, 96, 112)`. The parser
  (`0x81030170`) reads six lower-case hex digits as `rrggbb`, with two digits per channel and no `#`. The value also goes
  into the toolkit's state (words at offsets `0x4c`, `0x50`, `0x54`). A helper (`0x810301e4`) then picks the text colour
  for that background: index 0 when the colour is nearer to white than to black by squared distance, else 7.
- `0x14`..`0x20`, thirteen entries of tinted pairs: `0x14 (85,85,213)`, `0x15 (128,128,255)`, `0x16 (85,213,213)`,
  `0x17 (128,255,255)`, `0x18 (85,213,85)`, `0x19 (128,255,128)`, `0x1a (213,85,213)`, `0x1b (255,128,255)`,
  `0x1c (213,85,85)`, `0x1d (255,128,128)`, `0x1e (194,142,142)`, `0x1f (142,99,99)`, `0x20 (113,113,198)`.
- `0x23 (42,42,42)`, `0x24 (85,85,85)`, `0x25 (128,128,128)`, `0x26 (170,170,170)`, `0x27 (213,213,213)`: the grey
  ramp for bevels and button faces.
- `0x30 (255,255,0)` tagline, `0x31 (75,0,131)` logo and heading ink, `0x32 (95,95,146)` their shadow.
- `0x33 (85,85,85)`, `0x34 (198,113,113)`, `0x35 (113,198,113)`, `0x36 (142,142,56)`, `0x37 (113,113,198)`,
  `0x38 (142,56,142)`, `0x39 (56,131,131)`, `0x3a (170,170,170)`: icon colours.
- `0x60`..`0xff`: a 160-step ramp. For i = 0..159: `r = (0x5f0000 + 0x8199 * i) >> 16`,
  `g = (0x5f0000 + 0xb800 * i) >> 16`, `b = (0x8f0000 + 0xb333 * i) >> 16` (three running 32-bit sums, arithmetic
  shift). It runs from `(95, 95, 143)` to `(175, 209, 254)`.

Indices not listed (0x0b..0x0d, 0x0f..0x13, 0x21, 0x22, 0x28..0x2f, 0x3b..0x5f) are not written here. Whether the
controller holds a power-on value for them is not known.

## Background gradient

The root-window fill at `0x810461a0` (4.18) / `0x81045680` (4.8) paints one rectangle per scanline across the whole
screen (established; it has five call sites, among them the background draw and the window set-up). Callers pass the
width and height less one as the right and top limits. With H the screen height read from the root window
(offset `0x2c`, accessor `0x8103d4e4`):

    step  = 0xa00000 / (H - 1)                    (integer division)
    index = (0x600000 + y * step) >> 16           for y = 0 .. H-1, y counted up from the bottom row

So the bottom row uses index `0x60` and, at 1024 lines, the top row uses `0xff` (step 10250; 1023 * 10250 =
10 485 750, which is 159.99 steps). Each palette step covers about 6.4 rows. Nothing is stored and the code has no clamp:
the top index stays at or below `0xff` unless `H - 1` divides `0xa00000` exactly (1025 lines would give `0x100`; no
such mode is known). Identical in 4.8.

## Glyph and font format

**Font table (established).** A runtime table of four 12-byte records is written by `0x81032834` (4.18) /
`0x81031d94` (4.8) into `0x810717d8` / `0x81070a48`, in uninitialised data; the constants are in the code. A record is
`{bitmap base, entry table, height u16, descent u16}`.

| Font | Use | Height / descent | Entries | 4.18 bitmap base, entry table | 4.8 bitmap base, entry table |
|---|---|---|---|---|---|
| 0 | console text, fixed 9-pixel advance | 17 / 4 | 190 | `0x8105b970`, `0x8105ca0c` | `0x8105abf0`, `0x8105bc8c` |
| 1 | box and keycap pieces | 20 / 4 | 7 | `0x8105cffc`, `0x8105d054` | `0x8105c27c`, `0x8105c2d4` |
| 2 | serif bold, 23 pixels: menu labels, titles | 23 / 5 | 95 | `0x8105d08c`, `0x8105dfec` | `0x8105c30c`, `0x8105d26c` |
| 3 | sans, 14 pixels: button captions | 14 / 3 | 95 | `0x8105e2e4`, `0x8105ea08` | `0x8105d564`, `0x8105dc88` |

Within each font the bitmap region is followed directly by its entry table, and each table is followed by the next
font's bitmap. Fonts 0 and 2 consume their bitmap region exactly and font 3 to within a two-byte pad, which fixes the
entry counts above. All four bitmaps and all four tables are byte-identical in 4.8; only
their addresses moved (by 0xd80).

**Entry (8 bytes, big-endian).** `off s16` (halfwords from the bitmap base), `width u8`, `height u8`, `xoffset s8`,
`yoffset s8`, `advance u16`. The glyph is `height` rows of `ceil(width / 16)` halfwords, bottom row first, drawn at the
pen as described under the blit. To draw: left = pen x + xoffset, bottom row = pen y + yoffset, then advance the pen
by `advance`. Entry 0 (space) is a 1 by 1 blank glyph, not an empty entry; all font 0 entries advance by 9.

**Character to entry (established, `0x8104629c` / `0x8104577c`).** A code below 7 selects entry `code` of font 1,
whatever font was asked for. Otherwise the index is `code - 0x20` for codes below 0x80 and `code - 0x42` for codes
0x80 and up; a negative index draws nothing. The mapping makes `0x80..0x9f` reuse the entries of `0x5e..0x7d`, and
`0xa0` reuse the entry of `~`; entries from `0xa1` are new. **Inferred**: those aliases are unintended and the high half
is Latin-1 above `0xa0`. The routine returns the entry's advance.

**Font 1 (inferred).** Its seven entries are the left and right curved ends, a top bar, a bottom bar and blanks: the
parts of the key-cap outline drawn around `Esc` in the diagnostics screen. Entry 4 claims 18 rows from an offset that
lies 2 halfwords before the end of the region, so the rows overrun into the entry table; **inferred**: entry 4 is never
drawn. 4.8 is identical.

## Tagline glyphs

The yellow line under the logo ("Silicon Graphics Computer Systems") is drawn by `0x810488d8` / `0x81047db8` with three
tables (all established):

| Table | 4.18 | 4.8 |
|---|---|---|
| bitmap pool (halfword offsets, 660 bytes, consumed exactly) | `0x8105fc90` | `0x8105ef10` |
| entries, 19 of the 8-byte entry format above | `0x8105ff24` | `0x8105f1a4` |
| index list, 33 bytes, ended by `0xff` | `0x8105ffbc` | `0x8105f23c` |

The list holds one entry index per character, space included. The routine builds the same glyph record and calls the
same blit, with the colour and pen set by the caller. All three tables are identical in 4.8. The italic look is in
the stored shapes.

## Icons

Ten layered icons (established, found by scanning for the object shape and checked against the consumers).

**Object, five words:** `{width, height, xoffset, yoffset (signed), layer list pointer}`. The caller adds the offsets to
the position it was given. **Layer list**: records of six words, `{colour index, x, y, width, height, bitmap pointer}`,
ended by a record whose bitmap pointer is 0. The draw routine (`0x810486c0` / `0x81047ba0`) walks the list in order: for
each layer it sets the pen to `(origin x + layer x, origin y + layer y)`, sets the colour, and calls the bitmap
routine (`0x8103dc90` / `0x8103d180`), which wraps the pointer, width and height in a glyph record with zero offsets and
the standard stride and blits it. So each layer is a 1-bit stipple in the glyph bitmap format, y is measured up from the
icon's bottom edge, and later layers paint over earlier ones.

An icon is centred in its button box by `x = left + ((box width - icon width + 1) >> 1)` and
`y = bottom + ((box height - icon height + 1) >> 1)` (the routine at `0x8103d798` / `0x8103cc88`, established), and
then the icon's own offsets apply; only the recovery icon has a non-zero one (y -2).

| Icon | Used by | 4.18 object | 4.8 object | Layers |
|---|---|---|---|---|
| start system | menu item 0 | `0x81057498` | `0x81056728` | 10 |
| install system software | menu item 1 | `0x810578a0` | `0x81056b30` | 10 |
| run diagnostics | menu item 2 | `0x81057bd4` | `0x81056e64` | 6 |
| recover system | menu item 3 | `0x81057f70` | `0x81057200` | 6 |
| enter command monitor | menu item 4 | `0x81058320` | `0x810575b0` | 5 |
| select keyboard layout | menu item 5 | `0x81058630` | `0x810578c0` | 10 |
| remote tape | install dialog | `0x81057234` | `0x810564c4` | 9 |
| remote directory | install dialog | `0x81056520` | `0x810557b0` | 7 |
| local CD-ROM | install dialog | `0x81055e54` | `0x810550e4` | 8 |
| local tape | install dialog | `0x81056a54` | `0x81055ce4` | 8 |

The menu mapping is read from the menu builder's records (below). The dialog mapping is read from the table at
`0x810586cc`..`0x81058714` (4.18), each record pairing an icon with its two caption strings ("Remote" / "Tape",
"Remote" / "Directory", "Local" / "CD-ROM", "Local" / "Tape"). Object sizes run from 15 by 37 to 67 by 64. In 4.8 every
object, layer list and bitmap is identical to 4.18; the addresses are 0xd70 lower.

## Logo

**Run-length image (established).** 494 by 237, 1095 bytes, at `0x8105ed04` (4.18) / `0x8105df84` (4.8): segment offset
`0x5ed14` / `0x5df94`, flash offset `0x67f14` / `0x67194` after the 0x9200 base (add `0x100` with the container
header). The 4.8 copy is byte-identical to the 4.18 copy. The decoder is `0x81048780` / `0x81047c60`:

- Rows are stored bottom first; each is drawn one row above the last.
- A row is a sequence of byte lengths alternating gap, run, gap, run, starting with a gap. The row ends when the
  running total reaches or passes the image width; there is no terminator.
- A run of length 0 draws nothing. A length above 255 is written as 255, 0, remainder: the 255-zero pair extends the
  current gap or run. In this image only gaps are split that way: 45 rows are a blank full-width row `255, 0, 239`.
- Row 0 begins with twelve zero bytes (six zero-length gap and run pairs) before its `255, 0, 239`. Any even number of
  leading zero bytes up to twelve decodes the same way. The 237 rows end at the byte before the two words
  `0x000001ee, 0x000000ed` (494 and 237) at `0x8105f14c` / `0x8105e3cc`, which is the best anchor for finding the data
  without the pointer.

The width, height and data pointer the decoder reads come from three words of the root-window record (offsets `0x1c`,
`0x20` low 20 bits, `0x24`). Where the PROM writes the pointer was not found (a search for the address, for a constant
494 and for the data's start turned up nothing in code): the link between this data and that record is **inferred** from
the exact fit of 237 rows to 494 columns ending at the width/height words.

**Placement and ink (established for `W >= 1051`, taken from the immediates at `0x81048a10` / `0x81047ef0`).** For a
screen at least 1051 pixels wide the routine sets five constants: 150, 200, 530 (0x212), 520 (0x208) and 0. Everything
is drawn after the gradient, bottom-left origin, y up:

- logo shadow: colour `0x32`, image bottom-left at `(540, 66)`; logo: colour `0x31` at `(530, 80)`. (With 237 rows these
  put the image tops at screen rows 722 and 708.)
- tagline: colour `0x30`, pen at `(670, 50)`.
- "WELCOME TO": the string at `0x810540b0` / `0x81053420` (letters separated by spaces), font 2, colour `0x32` with pen
  `(155, 194)`, then colour `0x31` with pen `(150, 200)`.

For a screen narrower than 1051 pixels the constants are 65, 200, 445 (0x1bd), 520 and 0 instead (the same drawing
order). The code has a second branch for a root-window logo width of 601 pixels or more, which this logo never takes.
It was read only far enough to see it uses the root-window fields at offsets `0x20` (flag bits) and `0x24`; it is not
exercised and is **unknown**.

**When the logo is drawn (established).** The window set-up routine `0x8103caa0` / `0x8103bf90` reads `sgilogo`. A flag
is set when `sgilogo` is unset, when its first character is `n`, when a mode bit in the flag word is set, or when the
screen height is under 700 lines (`0x2bc`); the routine clears it otherwise. The flag word is `0x8107215c` /
`0x810713cc`; bit 16 means "no big logo". With the flag set the background routine draws the gradient only, with no
logo, tagline or heading. The default `sgilogo=y` (see [prom-environment.md](prom-environment.md)) clears it.

## Menu

**Records (established).** The menu builder `0x810123f0` / `0x81010380` fills six 16-byte records at `0x81060c50` /
`0x8105fea0`: `{label pointer, handler, flags, icon object}`. In menu order:

| # | Label | Label string, 4.18 / 4.8 | Handler, 4.18 |
|---|---|---|---|
| 0 | Start System | `0x8104b644` / `0x8104a8a4` | `0x81012528` |
| 1 | Install System Software | `0x8104b654` / `0x8104a8b4` | `0x810125a8` |
| 2 | Run Diagnostics | `0x8104b66c` / `0x8104a8cc` | `0x81012678` |
| 3 | Recover System | `0x8104b67c` / `0x8104a8dc` | `0x810129f4` |
| 4 | Enter Command Monitor | `0x8104b68c` / `0x8104a8ec` | `0x81012988` |
| 5 | Select Keyboard Layout | `0x8104b6a4` / `0x8104a904` | `0x81012ac4` |

The menu descriptor (`0x81058644` / `0x810578d4`) holds the records pointer, the title string "System Maintenance Menu"
(`0x8104b620`) and the count, 6. The start-up code clears bit 0 of every record's flags, then sets it on records 1 and 3
(install and recover) when `diskless` starts with `1`. The graphical draw `0x810423ec` / `0x810418cc` calls the
button's inactive setter (`0x8103d71c`) for a record whose bit 0 is set, which the frame routine then draws from a
single colour table (inferred: greyed out); the text-mode path of the same routine skips a record whose flag bit 2 is
set, which is why the keyboard-layout entry (flag 4) appears only on the graphical menu. The builder also sets bit 1 on
records 1 to 4; the start-up path calls a check (`0x81025b00`) before running a record with that bit. What that check
tests is **unknown**.

**Layout, graphical menu (established, `0x810423ec`).** With n = 6 records, W and H the screen size:

- Each button is 50 by 50 pixels; the pitch is 75 pixels, so the stack is `75 * n - 25 = 425` high.
- `V = H` when the "no big logo" flag is set, else `floor(2 * H / 3)`.
- The first button's bottom edge is at `y0 = H - ((V - 425) >> 1) - 50`; each next button is 75 lower.
- Button left edge is 150 when `W >= 1051`, else 65.
- The label is drawn in font 2 with its pen at `(left + 60, bottom + 15)`.
- The button draws its icon centred by the rule under "Icons".

At 1280 by 1024 with the logo on: V = 682, `y0 = 846`, button bottoms 846, 771, 696, 621, 546 and 471 (screen tops 129 + 75 k
with the flip above), labels at x = 210. This reproduces the positions the pixel check fitted, so nothing in the menu is
still fitted except the screen-row flip constant (1024), which is inferred as described under the toolkit.

**Button frame (inferred; `0x8103d798` / `0x8103cc88`).** A face in colour `0x26` (or `0x27` in some states) with four
nested one-pixel rings. Ring colours come from byte arrays at `0x8105f5d4`..`0x8105f5ec`, picked by pointer tables at
`0x8105f5f0` and `0x8105f600` indexed by the low two bits of the button state; the toolkit's y axis points up, so the
"top and left" rings are drawn last. The colour assignment per state was not walked beyond the idle state the pixel check
covers.

**Install-dialog icon grid (inferred).** The dialog builder (`0x810136d4`) lays four 80 by 80 icon buttons on a 96
pixel pitch, starting `((dialog width - 368) >> 1)` from the dialog's left edge, with the dialog width the smaller of the
screen width and 700. At 1280 pixels that is x = 456, 552, 648, 744 as the pixel check measured. The vertical position
(title baseline minus 98) depends on the title height and on a dialog height of 380 or 600 chosen from the device
count; the arithmetic was read but the dialog frame, captions and the other dialogs are not derived here (**unknown**).

## Sound

**Playing (established, `0x81000994`).** The sound code is at the same addresses in 4.8. The routine takes a tune number
below 11 (11 is the count in the jump table), returns at once when a status register read through `0x81004d70` from
`0xbf300000` has bit 1 clear (inferred: no audio hardware), reads the `volume` variable (string `0x810493dc` / `0x810488bc`),
and does nothing when it parses to 0. Otherwise it clamps the value to 255, turns it into an attenuation
`17 - volume / 17` and applies it through `0x81001590`. It then renders the tune into a heap buffer and feeds it to the
audio ring at `0xbf30xxxx` in chunks (the DMA and ring layout are not read here). The start-reason dispatch
(`0x81000848`, table `0x8104938c` / `0x8104886c`) plays tune 0 for reasons 0 and 1 (power-on, reset) and tune 1 for
reasons 3, 4 and 5; reasons 2, 6 and 7 play nothing. The hidden monitor command `.play N` (name string `0x810490f0` / `0x810485d0`) parses its argument and calls the same
routine (handler `0x81039930`; established).

**Tune table.** The jump table at `0x81049414` (4.18) / `0x810488f4` (4.8) holds 11 stubs. Each loads an array pointer,
a voice count, a total length and a scratch size, then runs the common play path. Established, identical in both
builds apart from the data address (4.8 arrays are 0xc90 lower):

| Tune | Voices | Array, 4.18 | Array, 4.8 | Total length field |
|---|---|---|---|---|
| 0 | 7 | `0x81054ab4` | `0x81053e24` | 0x1e576 |
| 1 | 5 | `0x810544f4` | `0x81053864` | 0x1ec2f |
| 2 | 6 | `0x810546b4` | `0x81053a24` | 0x22740 |
| 3 | 6 | `0x81054434` | `0x810537a4` | 0x21f4b |
| 4 | 5 | `0x81054394` | `0x81053704` | 0x1eb23 |
| 5 | 5 | `0x81054594` | `0x81053904` | 0x1ec2f |
| 6 | 4 | `0x81054634` | `0x810539a4` | 0x1ef43 |
| 7 | 5 | `0x81054774` | `0x81053ae4` | 0x21119 |
| 8 | 7 | `0x81054814` | `0x81053b84` | 0x1e576 |
| 9 | 7 | `0x810548f4` | `0x81053c64` | 0x1e576 |
| 10 | 7 | `0x810549d4` | `0x81053d44` | 0x1e576 |

The arrays are contiguous, from `0x81054394` for 0x800 bytes (64 voices) in 4.18; the word after them at `0x81054b94`
is a buffer cache pointer, not data. In every tune the total length equals the last voice's start plus its length.

**Voice descriptor (32 bytes, 8 big-endian words; established from the renderer at `0x81001368`):**

| Word | Meaning |
|---|---|
| 0 | delay-line length N in samples (also the number of noise samples at the start) |
| 1 | number of samples this voice renders (88 200 in every voice of every tune) |
| 2 | start offset into the mix buffer, in 4-byte units |
| 3 | float: excitation peak, the level the initial noise burst is scaled to |
| 4 | float: loss factor, applied each time round the delay line |
| 5 | float: weight of the previous delay-line sample in the two-tap average |
| 6 | float: weight of the current delay-line sample in the two-tap average |
| 7 | float: coefficient of a first-order all-pass section in the loop (fractional-delay tuning) |

**Synthesis (established).** The excitation is the delay line filled by a linear congruential generator
(`s = s * 0x41c64e6d + 0x3039`, from `0x81000e08`), mapped to a signed float, the mean removed and the peak scaled to
word 3. Per output sample, with x the oldest delay-line sample: `f = (w6 * x + w5 * x_prev) * loss`, then the all-pass
`y = c * f + f_prev - c * y_prev`, written back into the delay line; the sample added to the mix is `trunc(x) << 8`,
added to both channel words of the output slot. This is a Karplus-Strong-style plucked string; the name is
descriptive, not the PROM's. In tune 0 the voices start 6013 units apart (voice k at 6013 k).

**Not settled.** The unit mix is not consistent on its face: the renderer advances 8 bytes (two words) per sample but
offsets the start by 4 bytes per unit, and the buffer is sized at 4 bytes per unit of total length. The pitch of the
rendered note therefore depends on a sample rate the code does not state, and which unit the word 2 offsets and the
buffer size count (samples or words) is **unknown**. So are the output sample rate (44 100 Hz and a 16-bit stereo ring
are plausible, **inferred** from the 88 200-sample voices lasting 2 s), the final conversion to the ring format, and
whether a physical O2 sounds as the model's audio path would.

## Locating the tables

Both builds are identified by the banner string. For an unknown build, find the assets from code immediates rather than
by scanning data:

- palette: the routine that calls device slot 2 with index 0xff for green and index `0x60`..`0xff` from a loop of
  `0xa0` iterations with increments `0x8199`, `0xb800`, `0xb333`;
- fonts: the routine that stores four `{base, table, height, descent}` records with heights 17, 20, 23, 14 and
  descents 4, 4, 5, 3;
- icons: scan the initialised data for five-word objects whose layer-list pointer starts a run of six-word records
  ending with a zero bitmap pointer; ten exist in both builds;
- logo: the words `0x000001ee, 0x000000ed`, with 237 run-length rows summing to 494 ending the byte before them;
- tagline: the three tables read by the routine that ends its index list on `0xff`;
- tunes: the 11-entry jump table indexed from the play routine, whose stubs load the arrays.

## Grades

| Asset | 4.18 | 4.8 |
|---|---|---|
| Palette values and ramp, set-colour routine | established | established; same values, driver routine differs in its wait |
| Background gradient formula | established | established, identical |
| Font table, entry format, bitmap orientation | established (bit order inferred) | established, identical data |
| Character to entry mapping, aliases above 0x7f | established mapping, aliases inferred | same |
| Font 1 role | inferred | same |
| Tagline glyph tables | established | established, identical data |
| Icons: format, centring, ten objects | established | established, identical data |
| Logo: image format and decode | established | established, identical data |
| Logo: binding to the window record | inferred | inferred |
| Logo, tagline and heading placement, 1280-wide screen | established | established, identical constants |
| Menu records, layout formulas | established | established, identical constants |
| Button bevel colours and rings | inferred | inferred |
| Dialog icon grid | inferred | inferred |
| Tune table, voice layout, synthesis steps | established | established, identical data |
| Sample rate, ring format, mix-buffer unit | unknown | unknown |
| Screen-row flip constant (1024) | inferred | inferred |
