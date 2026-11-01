# GBE

Mode: **spec-backed** (see [docs/specs.md](../../docs/specs.md)).

O2 display back end. Spec: GBE ASIC spec, revision 1.1 (18 July 1996). Builds: IP32.

Census config: [`tools/configs/gbe.json`](../../tools/configs/gbe.json); results land in `census/`.

Entries below carry a label (established, inferred, unknown) and a derivation, per AGENTS.md. Each entry starts with
the physical address the register has in the GBE window (the offset from `0x16000000` is in brackets), then the
specification's name, section and page. Offsets are the specification's.

## Early stop routine (`early_gbe_stop`, IP32 `kernel.o`)

Established. The routine is 564 bytes at `kernel.o` offset 0x8504 (n32, 141 words), read in full. It takes no
arguments and sets no return value. It first reads the normal-planes DMA enable (`FRM_2` bit 0). If that bit is
clear it reads the overlay DMA enable (`OVR_1` bit 0) and the DID DMA enable (`DID` bit 16); if all three are clear
it returns without a store. Otherwise it clears the shadow enables (`FRM_3` bit 0, `OVR_2` bit 0, `DID_SHADOW`
bit 16), adds 32 to the three shadow words, polls the live registers until their enables read clear (or 400000
passes run out), then polls until each live word equals the value its shadow was given. It then stores
0x80000000 to `VT_0`, clears bit 20 of `DOTCLK` and returns. A call to `flushbus` follows each store except the
`VT_0` store. Inferred:
the purpose is to stop scan-out at a blanking boundary, with the shadow copies taking effect at the next blanking.

- `0x16000004` (`0x4`): DOTCLK, dot clock PLL control (spec section 3.2.1, p. 36). Established.
  The routine loads the word at `kernel.o` 0x86d4, clears bit 20 with a mask built by `lui 0x10` and `nor`, and stores
  it back at 0x86e4 in the delay slot of the `flushbus` call. The fields M (7:0), N (13:8) and P (15:14) are not
  touched. The specification leaves bit 20 without a name (`20 - - -`). Open sub-fact: what bit 20 controls. Route: a
  later revision of the GBE specification or a PLL diagnostic that reads it.

- `0x16010000` (`0x10000`): VT_0, video timing x and y counters (spec section 3.2.2, p. 38). Established.
  `early_gbe_stop` stores 0x80000000 at `kernel.o` 0x86cc. Bit 31 is `vt_freeze`, which the specification gives a
  reset value of 1, and the x and y fields (11:0 and 23:12) are written as zero. The specification says `vt_x` counts
  only while `vt_freeze` is 0, so the store halts the raster counters and zeroes them.
  A second reader is an unnamed routine at offset 0x0 of IP32 `mvp.o`, which the symbol table does not name. It
  loads the word, shifts out bits 23:12 (`vt_y`), and returns 1 when `vt_y` is below 1024 and 0 otherwise
  (instructions 0x0 to 0x2c).

- `0x16020004` (`0x20004`): OVR_1, overlay tile pointer and overlay DMA enable (spec section 3.2.3, p. 42). Established.
  Only read. Five loads in `early_gbe_stop` (`kernel.o` 0x85dc, 0x8604, 0x8680, 0x86ac, 0x870c). Bit 0 is tested at
  the entry check (0x870c) and in the first poll loop (0x85e0 and 0x860c). In the second poll loop the whole word is
  compared with the value stored to `OVR_2` (0x8680 and 0x86ac).

- `0x16020008` (`0x20008`): OVR_2, shadow of the overlay registers, copied at the start of blanking (spec section
  3.2.3, p. 42). Established.
  Stored twice. The first store at `kernel.o` 0x8580 writes the loaded word (read at 0x856c) with bit 0 cleared.
  The second store at 0x8644 writes the word read at 0x8638, after the first store, with 32 added.

- `0x16030008` (`0x30008`): FRM_2, normal-planes tile pointer and DMA enable (spec section 3.2.4, p. 43). Established.
  Only read, at five sites in `early_gbe_stop` (`kernel.o` 0x8518, 0x85b4, 0x85cc, 0x8674, 0x86a0). The first read
  tests bit 0 at 0x8528 and selects between the stop sequence and the entry check. The second poll loop compares the
  whole word with the value stored to `FRM_3` (0x8678 and 0x86a4).

- `0x1603000c` (`0x3000c`): FRM_3, shadow of the normal-planes registers (spec section 3.2.4, p. 43). Established.
  Read at `kernel.o` 0x8554 and stored at 0x8564 with the loaded word masked by 0xfffffffe, so bit 0 clears. Read
  again at 0x8628, 32 added, and stored at 0x8634. The entry check does not touch it.

- `0x16040000` (`0x40000`): DID, DID table base and DID DMA enable (spec section 3.2.5, p. 44). Established.
  Only read, at five sites (`kernel.o` 0x85ec, 0x8614, 0x868c, 0x86b8 and 0x8720). The entry check at 0x8720 shifts
  the word left by 47, so bit 16 becomes the sign bit that `bltz` at 0x8728 tests. The first poll loop tests bit 16
  with a mask of 0x10000 (0x85f0 and 0x8618). The second poll loop compares the whole word with the value stored to
  `DID_SHADOW` (0x868c and 0x86b8).

- `0x16040004` (`0x40004`): DID_SHADOW, the DID base and DMA enable held for the next blanking (spec section 3.2.5,
  p. 44). Established.
  Read at `kernel.o` 0x858c and stored at 0x859c with bit 16 cleared through the mask `0xfffeffff`. Read again at
  0x8650, 32 added, and stored at 0x865c.

## Display register map (published specification)

Each entry below records one register of the GBE rev 1.1 map as the published specification describes it, with the
reset state of each field. The source is [the specification](../../docs/sources/specs/gbe-specification.pdf), section 3.2
(pages 36 to 48). Use of these registers by shipped software is covered by the entries above, where the early stop
routine reads them, and is otherwise not part of this page.

- `0x16000000` (`0x0`): CTRLSTAT, general control (docs/sources/specs/gbe-specification.pdf, section 3.2.1, p. 36). Established.
  Bits 3:0 hold the chip revision (reset 0001), and bit 4 is a read-only sense_n input from the monitor. The ten general
  purpose I/O pins io_0 to io_9 occupy bits 7:6 through 25:24, each pair a data bit with an active-low output-enable bit
  above it. Bit 26 (half_phase) sets the flat panel clock phase against the falling edge of blank_n, and bit 27 makes
  csync active low. Bits 29:28 choose the dot clock: 00 external TTL pclk, 01 external differential pclk, 11 the internal
  dot clock PLL.

- `0x16000008` (`0x8`): I2C, CRT I2C control (docs/sources/specs/gbe-specification.pdf, sections 2.11 and 3.2.1, p. 37). Established.
  Bit 0 is sda and bit 1 is sdc, both open-drain with reset state 1. A write drives the sda_out and sdc_out pins, and a
  read returns the level actually on the bus, which can differ from the output state. Section 2.11 says the CPU
  drives this interface directly for DDC2 monitor reads, and that it is the only I2C master on the bus.

- `0x1600000c` (`0x0c`): SYSCLK, system clock PLL control (docs/sources/specs/gbe-specification.pdf, section 3.2.1, p. 37). Established.
  Bits 0 to 3 are the PLL test and mode inputs tdwni, tupi, tm(1) and tm(0), reset to 0, 0, 0 and 1. Bits 9:8 hold vgain,
  11:10 cgain and 14:12 divsel, each reset to zero. Bits 7:4 are unused.

- `0x16000010` (`0x10`): I2CFP, flat panel I2C control (docs/sources/specs/gbe-specification.pdf, section 3.2.1, p. 37). Established.
  The layout matches I2C: bit 0 is the flat panel sda line and bit 1 the flat panel sdc line, both open-drain and reset
  to 1. This bus is separate from the CRT bus that I2C controls.

- `0x16000014` (`0x14`): DEVICE_ID, device id and chip revision (docs/sources/specs/gbe-specification.pdf, section 3.2.1, p. 37). Established.
  Bits 31:0 read 0x00000666 after reset. The specification says this is the same identifier the device exposes through
  its JTAG device ID register.

- `0x16010004` (`0x10004`): VT_1, maximum x and y counts (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 38). Established.
  Bits 11:0 hold vt_maxx and bits 23:12 hold vt_maxy, both reset to zero. vt_x resets to zero when it equals vt_maxx,
  and vt_y resets to zero when it equals vt_maxy.

- `0x16010008` (`0x10008`): VT_2, vertical sync window (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 38). Inferred.
  Bits 11:0 hold vt_vsync_off and bits 23:12 hold vt_vsync_on, both reset to zero. The first field is stated outright:
  vsync goes inactive when vt_y equals vt_vsync_off. The specification's sentence for bits 23:12 repeats vt_vsync_off,
  which reads as a typo. Taking the field name at face value, vsync goes active when vt_y equals vt_vsync_on. The
  specification's text would need a later revision to settle which compare the hardware makes.

- `0x1601000c` (`0x1000c`): VT_3, horizontal sync window (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 38). Established.
  Bits 11:0 hold vt_hsync_off and bits 23:12 hold vt_hsync_on, both reset to zero. hsync goes inactive when vt_x equals
  vt_hsync_off and active when vt_x equals vt_hsync_on.

- `0x16010010` (`0x10010`): VT_4, vertical blank window (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 38). Established.
  Bits 11:0 hold vt_vblank_off and bits 23:12 hold vt_vblank_on, both reset to zero. Blanking ends when vt_y equals
  vt_vblank_off and begins when vt_y equals vt_vblank_on.

- `0x16010014` (`0x10014`): VT_5, horizontal blank window (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 38). Established.
  Bits 11:0 hold vt_hblank_off and bits 23:12 hold vt_hblank_on, both reset to zero. Horizontal blanking ends when vt_x
  equals vt_hblank_off and begins when vt_x equals vt_hblank_on.

- `0x16010018` (`0x10018`): VT_6, sync polarity and forced sync levels (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 39). Established.
  All seven bits reset to zero. Bit 0 (vt_vdrv_invert) inverts vsync, and bit 1 (vt_vdrv_low) holds vsync at 0, or at 1
  when the invert bit is set; the spec says this is the DPMS power-saving path. Bits 2 and 3 do the same for hsync.
  Bits 4 and 5 (vt_sync_high, vt_sync_low) force sync_n to 1 or 0 to disable sync on green. Bit 6 (vt_f2rf_high) forces
  f2rf to 1, which the spec describes as the left and right synchronisation signal.

- `0x1601001c` (`0x1001c`): VT_7, field toggle point and frame lock preset (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 39). Established.
  Bits 11:0 hold vt_f2rf, which toggles f2rf when vt_y equals it, and bits 23:12 hold vt_frmlock, the value vt_y takes
  on the rising edge of frmlock. Both reset to zero. The spec adds that vt_y must not be reset until vt_x equals vt_maxx.

- `0x16010020` (`0x10020`): VT_8, interrupt lines 0 and 1 (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 39). Established.
  Bits 11:0 hold vt_intr1 and bits 23:12 hold vt_intr0, both reset to zero. GBE raises interrupt 1 when vt_y equals
  vt_intr1 and interrupt 0 when vt_y equals vt_intr0.

- `0x16010024` (`0x10024`): VT_9, interrupt lines 2 and 3 (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 39). Established.
  Bits 11:0 hold vt_intr3 and bits 23:12 hold vt_intr2, both reset to zero. GBE raises interrupt 3 when vt_y equals
  vt_intr3 and interrupt 2 when vt_y equals vt_intr2.

- `0x16010028` (`0x10028`): VT_10, flat panel horizontal drive edges (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 39). Established.
  Bits 11:0 hold fp_hdrv_off and bits 23:12 hold fp_hdrv_on, both reset to zero. The flat panel horizontal drive clears
  when vt_x equals fp_hdrv_off and sets when vt_x equals fp_hdrv_on.

- `0x1601002c` (`0x1002c`): VT_11, flat panel vertical drive edges (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 39). Established.
  Bits 11:0 hold fp_vdrv_off and bits 23:12 hold fp_vdrv_on, both reset to zero. The flat panel vertical drive clears
  when vt_y equals fp_vdrv_off and sets when vt_y equals fp_vdrv_on.

- `0x16010030` (`0x10030`): VT_12, flat panel data enable edges (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 40). Established.
  Bits 11:0 hold fp_de_off and bits 23:12 hold fp_de_on, both reset to zero. fp_de clears when vt_x equals fp_de_off
  and sets when vt_x equals fp_de_on.

- `0x16010034` (`0x10034`): VT_13, horizontal internal pixel enable (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 40). Established.
  Bits 11:0 hold vt_hpixen_off and bits 23:12 hold vt_hpixen_on, both reset to zero. The internal pixel enable clears
  when vt_x equals vt_hpixen_off and sets when vt_x equals vt_hpixen_on.

- `0x16010038` (`0x10038`): VT_14, vertical internal pixel enable (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 40). Established.
  Bits 11:0 hold vt_vpixen_off and bits 23:12 hold vt_vpixen_on, both reset to zero. The internal pixel enable clears
  when vt_y equals vt_vpixen_off and sets when vt_y equals vt_vpixen_on.

- `0x1601003c` (`0x1003c`): VT_15, colour map write enable on the x counter (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 40). Established.
  Bits 11:0 hold vt_hcmap_off, which clears the colour map write enable when vt_x equals it. Bits 23:12 are named
  vt_vcmap_on, but the spec compares them with vt_x, the horizontal counter, and sets the write enable on that compare.
  This entry takes the compare as written. Both fields reset to zero.

- `0x16010040` (`0x10040`): VT_16, colour map write enable on the y counter (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 40). Established.
  Bits 11:0 hold vt_vcmap_off, which clears the colour map write enable when vt_y equals it. Bits 23:12 hold
  vt_vcmap_on, which sets the enable when vt_y equals it. Both reset to zero.

- `0x16010044` (`0x10044`): VT_17, display ID counter preset (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 40). Established.
  Bits 11:0 hold did_startx. When vt_x equals it, did_x is preset to zero. Bits 23:12 hold did_starty, which presets
  did_y when vt_y equals vt_vblank_on. Both reset to zero.

- `0x16010048` (`0x10048`): VT_18, cursor position preset (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 40). Established.
  Bits 11:0 hold crs_startx. When vt_x equals it, crs_x is preset to binary 111111100000 (0xfe0). Bits 23:12 hold
  crs_starty, which presets crs_y when vt_x minus crs_x_offset and vt_y both match the blanking points. The spec defines
  crs_x_offset as vt_hblank_on plus binary 100000 (32). Both fields reset to zero.

- `0x1601004c` (`0x1004c`): VT_19, video capture origin preset (docs/sources/specs/gbe-specification.pdf, section 3.2.2, p. 41). Established.
  Bits 11:0 hold vc_startx. When vt_x equals it, vc_x is preset to zero. Bits 23:12 hold vc_starty, which presets vc_y
  when vt_y equals vt_vblank_on. Both reset to zero.

- `0x16020000` (`0x20000`): OVR_0, overlay plane tile geometry (docs/sources/specs/gbe-specification.pdf, section 3.2.3, p. 42). Established.
  Bits 4:0 hold ovr_rhs, the width of the right-hand tile in 32-byte units. Bits 12:5 hold ovr_width_tile, the overlay
  width in whole tiles. Bit 13 is a diagnostic FIFO reset that the spec says not to modify. All fields reset to zero.

- `0x16030000` (`0x30000`): FRM_0, normal plane tile geometry and depth (docs/sources/specs/gbe-specification.pdf, section 3.2.4, p. 43). Established.
  Bits 4:0 hold frm_rhs (right-hand tile width in 32-byte units) and bits 12:5 hold frm_width_tile (width in whole tiles).
  Bits 14:13 select the pixel depth: 00 for 8 bit, 01 for 16 bit and 10 for 32 bit. Bit 15 is a diagnostic FIFO reset.
  All fields reset to zero, so the depth resets to 8 bit.

- `0x16030004` (`0x30004`): FRM_1, normal and overlay plane height (docs/sources/specs/gbe-specification.pdf, section 3.2.4, p. 43). Established.
  Bits 31:16 hold fb_height_pix, the height of the normal and overlay planes in pixels, reset to zero. The table names
  no field in bits 15:0.

- `0x16048000` (`0x48000`): WID, the window ID table, 32 words (docs/sources/specs/gbe-specification.pdf, section 3.2.5, p. 44). Established.
  Each word holds buf in bits 1:0 (01 lower half, 10 upper half, 11 both), typ in bits 4:2 (000 I8, 001 I12, 010 RG3B2,
  011 RGB4, 100 RGB5, 101 RGB8), cm in bits 9:5, gm in bit 10 (0 enables gamma, 1 disables) and aux in bits 12:11,
  which drive the digital pixel bus. The spec says cm is the upper five bits of the colour map index in I8 mode and the
  direct visual map value for RGB8 pixels when it is nonzero. The words run from 0x48000 to 0x4807C at a stride of 4.

- `0x16050000` (`0x50000`): CMAP, colour map RAM, 4608 words (docs/sources/specs/gbe-specification.pdf, section 3.2.6, p. 45). Established.
  Each word holds blue in bits 15:8, green in bits 23:16 and red in bits 31:24. The table names no field in bits 7:0.
  The words run from 0x50000 to 0x547FC at a stride of 4.

- `0x16058000` (`0x58000`): CMFIFO, colour map FIFO status (docs/sources/specs/gbe-specification.pdf, section 3.2.6, p. 45). Established.
  Bits 5:0 hold cm_fifo, the number of free entries in the colour map FIFO, reset to zero. The table names no field
  above bit 5.

- `0x16060000` (`0x60000`): GMAP, gamma map RAM, 256 words (docs/sources/specs/gbe-specification.pdf, section 3.2.6, p. 45). Established.
  Each word holds blue in bits 15:8, green in bits 23:16 and red in bits 31:24. The table names no field in bits 7:0.
  The words run from 0x60000 to 0x603FC at a stride of 4.

- `0x16070000` (`0x70000`): CRS_0, cursor position (docs/sources/specs/gbe-specification.pdf, section 3.2.7, p. 46). Established.
  Bits 15:0 hold crs_posx, the cursor x position, and bits 31:16 hold crs_posy, the cursor y position. Both reset to zero.

- `0x16070004` (`0x70004`): CRS_1, cursor mode (docs/sources/specs/gbe-specification.pdf, section 3.2.7, p. 46). Established.
  Bit 0 is crs_enable, where 1 enables the cursor. Bit 1 is crs_crosshair, where 1 selects crosshair mode. Both reset to zero.

- `0x16070008` (`0x70008`): CRS_CM, cursor colour map entries 1 to 3, three words (docs/sources/specs/gbe-specification.pdf, section 3.2.7, p. 46). Established.
  Each word holds blue in bits 15:8, green in bits 23:16 and red in bits 31:24. The table names no field in bits 7:0.
  The words run from 0x70008 to 0x70010 at a stride of 4.

- `0x16078000` (`0x78000`): CRS_GLY, cursor glyph RAM, 64 words (docs/sources/specs/gbe-specification.pdf, section 3.2.7, p. 46). Established.
  Each word holds two-bit pixels: crs_pix0 in bits 31:30 is the leftmost pixel of the glyph row and crs_pix15 in bits 1:0
  is the rightmost. The memory map gives the range as 0x78000 to 0x780FC at a stride of 4. The register table prints the
  upper bound with an extra digit, 0x0780FC, which is a typo.

- `0x16080000` (`0x80000`): VC_0, video capture left and right edges (docs/sources/specs/gbe-specification.pdf, section 3.2.8, p. 47). Established.
  Bits 11:0 hold vc_left and bits 23:12 hold vc_right. Both edges are inclusive and reset to zero.

- `0x16080004` (`0x80004`): VC_1, video capture top and bottom edges (docs/sources/specs/gbe-specification.pdf, section 3.2.8, p. 47). Established.
  Bits 11:0 hold vc_top and bits 23:12 hold vc_bottom. Both edges are inclusive and reset to zero.

- `0x16080008` (`0x80008`): VC_2, video capture mode (docs/sources/specs/gbe-specification.pdf, section 3.2.8, p. 47). Established.
  Bit 0 is vc_dmavideo, which enables video capture DMA when 1, reset 0. Bit 1 is vc_flick, the flicker filter enable,
  reset 1. Bit 2 is vc_autofield, which advances the odd and even field sequence at the end of a field when 1, reset 1.
  When it is 0 the field type has to be set by programmed I/O. Bit 3 is vc_fullscreen, reset 0. Bit 4 is vc_cscbypass,
  which enables RGB555 mode without colour space conversion, reset 0 and intended for diagnostics only.

- `0x1608000c` (`0x8000c`): VC_3, video capture field and DMA status (docs/sources/specs/gbe-specification.pdf, section 3.2.8, p. 47). Established.
  Bit 0 is vc_field, which selects the field to capture (0 even, 1 odd), reset 0. Bit 1 is vc_discdmaenb, the descriptor
  list DMA enable, reset 0. The spec says this feature does not work on revision 1.1 and the list must be written by
  programmed I/O. Bit 2 is vc_fieldcorrupt, set when the current field is corrupt and cleared by software. Bit 3 is vc_eof,
  set when the last field finished its DMA and cleared by software. Bit 4 is vc_oddeven, read only, the field type
  being DMAed, reset 1. Bits 31:5 hold vc_descr_ptr, the pointer to a 32-byte descriptor list, reset zero.

- `0x16080010` (`0x80010`): VC_4, first two video capture tile addresses (docs/sources/specs/gbe-specification.pdf, section 3.2.8, p. 47). Established.
  Bits 31:16 hold vc_Tileaddr#1, the first tile address in the descriptor list, and bits 15:0 hold vc_Tileaddr#2, the
  second. Both reset to zero.
