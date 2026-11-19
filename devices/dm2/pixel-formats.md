# DM2 pixel formats: the packings, how one is chosen, and what Flame 9.0 asks for

Status: **draft, not independently reviewed.** Part of the [DM2 scoping datasheet](README.md). It records which memory pixel
formats the DM2 (XT-DIGVID) data path takes, how software selects one, how the pixels are laid out, and which format
Discreet Flame 9.0 requests by default. Grades follow [AGENTS.md](../../AGENTS.md): **E** established, **I** inferred, **U**
unknown. A fact read from a shipped binary's code or table is E; a fact read from a published manual's text or figure is E and
named as such; a fact that rests on a reading across several pieces is I.

## Sources

| Tag | Source | Used for |
|---|---|---|
| F | Discreet Flame 9.0 for IRIX, main executable (n32, sha256 `39a3bad85906b0c6bedd06736cb3390ed0d15b488c2b69a0045c26145a2106c3`), named routines `convertIFFtoVIOPacking`, `convertIFFToVIOColorspace`, `VideoVIOConfigureVideo` (disassembled with the toolchain `objdump`; the Ghidra import of this executable failed on its relocations, so no decompiler output was used for it) | which packing Flame requests |
| V | Same release, product `DLviodso16`, member `usr/discreet/lib32/DlVIO/16/libDlVideoDeviceMl.so` (n32, sha256 `7e512d6493dc8727c4d3d7ce0d1b10264ef1aa2762500cbcce8c63a429546a51`, 265,296 bytes), Ghidra export for navigation, every quoted value re-read in the `objdump` disassembly or data dump | the library that turns Flame's video setup into OpenML controls for the DM2 module |
| B | SGI DMediaPro DM2 OpenML module `libdigvid.so` (sha256 `aacf8d4a…c2ca`), already read in [the FPGA note](fpga-load.md) | the packing table and the image names |
| G1 | SGI DMediaPro DM2 and DM3 Board Owner's Guide 007-4317-001, Table 5-2 (printed p. 55 to 56) and Table 5-4 (printed pp. 73 and 74) | the packing and sampling controls, and the map from VL to DM names |
| G2 | SGI HD I/O Option Owner's Guide 007-3968-002, Appendix C (printed pp. 58 to 72; the diagrams are images and were read as images) | bit layouts |

## 1. What the DM2 offers

There is no register that says "this is the pixel format". The format is the pair of FPGA images loaded behind the GIF: one
packer (video in to memory) and one unpacker (memory to video out), chosen by name, so the format is selected by which
`.mcs` image the host programs (E, B; [FPGA note](fpga-load.md), "Packer and unpacker names"). Every packer and unpacker image
has the same size (104,066 records), so the choice is not visible in a size or a register. The only registers the library
writes that follow the format are the output colour converter's 8-bit flag (`0x80304c`, "pack8": 1 when the component size is 8
bits, [GIF note](gif-registers.md) section 4.4, E for the write) and the colour converter coefficients (section 5 below); the
sampling, the 10-bit variants, the component order and the alpha are not in any register (I: nothing else in the
library's commit routine reads the packing).

How the library picks the image name, from `hdPackingTable` and its two index arrays (E, B):

- The library works with two OpenML controls, the image packing (a 32-bit constant) and the image sampling (a 16-bit code).
  Sampling `0x4220` is 4:2:2, `0x4224` is 4:2:2:4, `0x4440` is 4:4:4 and `0x4444` is 4:4:4:4.
- It looks the packing up in a 15-row table, the sampling in a 4-column one, and the cell is the image name with
  `packer_` or `unpacker_` in front. The cell may be empty, which makes the pair unsupported.

Reading the packing constants (I, from the names the table pairs them with and the pattern of the values; no header was read):
the low byte is the bits per component (`0x08`, `0x0a`, `0x0c`), the next byte is the component order as four 2-bit
indices (`0x1b` is 0 1 2 3 in memory order, `0xe4` the reverse and `0x93` the rotation the guide calls 3214), and the top
nibble says simple (`1`), padded in a 16-bit word (`2`, with a left or right nibble `1` or `2` under it) or complex 10_10_10_2
(`4`). That matches the guide's own names: DM_PACKING_8, `_R` for the reversed order, `_3214` for the rotated one, `10in16L`
and `10in16R` for the padded ones, and `10_10_10_2`.

| Packing constant | Order | Image name by sampling `4220` / `4224` / `4440` / `4444` | DM_IMAGE_PACKING, DM_IMAGE_SAMPLING (G1 Table 5-4) | VL name |
|---|---|---|---|---|
| `0x1001b108` | natural | `422_8` / - / `444_8` / `4444_8` | DM_PACKING_8 with 422, 444 or 4444 | R242_8, 444_8, 4444_8 |
| `0x100e4108` | reversed | - / - / `444_8_r` / `4444_8_r` | DM_PACKING_8_R with 444 or 4444 | R444_8, R4444_8 |
| `0x10093108` | 3214 | `422_8_3214` | DM_PACKING_8_3214, 422 | 242_8 |
| `0x1001b10a` | natural | `422_10` | DM_PACKING_10, 422 | R242_10 |
| `0x1009310a` | 3214 | `422_10_3214` | DM_PACKING_10_3214, 422 | 242_10 |
| `0x2111b10a` | natural | `422_10in16l` / - / `444_10in16l` / - | DM_PACKING_10in16L, 422 | R242_10_in_16_L |
| `0x2119310a` | 3214 | `422_10in16l_3214` | DM_PACKING_10in16L_3214, 422 | 242_10_in_16_L |
| `0x2121b10a` | natural | `422_10in16r` / - / `444_10in16r` / - | DM_PACKING_10in16R, 422 | R242_10_in_16_R |
| `0x2129310a` | 3214 | `422_10in16r_3214` | DM_PACKING_10in16R_3214, 422 | 242_10_in_16_R |
| `0x2111b20c` | natural | - / - / `444_12in16l` / - | DM_PACKING_S12in16L, 444 | 444_12_in_16L |
| `0x2121b20c` | natural | - / - / `444_12in16r` / - | DM_PACKING_S12in16R, 444 | 444_12_in_16_R |
| `0x4001b001` | natural | - / `4224_10_10_10_2` / `4444_10_10_10_2` / `4444_10_10_10_2` | DM_PACKING_10_10_10_2, 4224 or 4444 | R2424_10_10_10_2Z, 4444_10_10_10_2 |
| `0x400e4001` | reversed | - / - / `4444_10_10_10_2_r` / same | DM_PACKING_10_10_10_2_R, 4444 | R4444_10_10_10_2 |
| `0x40093001` | 3214 | - / `4224_10_10_10_2_3214` | DM_PACKING_10_10_10_2_3214, 4224 | 2424_10_10_10_2Z |
| `0x1001b20c` | natural | - / - / - / `4444_12` | not in G1's table | 4444_12 (G2 text only) |

The names and the packing and sampling values are E (B). The DM and VL columns are E for the rows G1 Table 5-4 lists; the
pairing of each constant with its DM name goes through the image name, so it is I. The two 12-bit rows are the DM
"S12" packings (signed twelve-bit), which G1 spells with an S and the library constants do not.

Three more things G1 says: the 4:2:2 formats are only for CbYCr video, 4:4:4 and 4:4:4:4 take either CbYCr or RGB memory
(Table 5-2, `DM_IMAGE_SAMPLING_INT32`, E), a change of packing at the start of a transfer can take seconds to apply
(Table 5-4 note, E), and the control that carries the choice is `DM_IMAGE_PACKING_INT32` (E).

## 2. Bit layouts

Conventions (G2 p. 58 and p. 59, E): the diagrams show the smallest repeating pattern that is a multiple of 8 bits; bytes go
up in memory address left to right; within a byte and across a component the most significant bit comes first. So a
multi-byte value drawn left to right is a big-endian number. A `p` bit is padding in the low bits of a left-justified word, and a
reader may take it as a copy of the component's top bits; a writer may leave it as garbage. A `0` bit a reader may take as
zero. The guide letters the components R G B or V Y U (V is Cr, U is Cb, "for typographical convenience").

| Format | Bytes | Layout in memory order | Source |
|---|---|---|---|
| 444 8-bit, natural (`0x1001b108`, 4440) | 3 per pixel, no padding, no row alignment | byte 0 R (or Cr), byte 1 G (or Y), byte 2 B (or Cb) | G2 Figure C-6 (E); the guide's name for it is DM_IMAGE_PACKING_RGB |
| 444 8-bit, reversed (`0x100e4108`) | 3 | B (or Cb), G (or Y), R (or Cr) | G2 Figure C-7 (E); DM_IMAGE_PACKING_BGR, or CbYCr for video data |
| 4444 8-bit (`0x1001b108`, 4444) | 4 | R, G, B, A | G2 Figure C-8 (E); DM_IMAGE_PACKING_RGBA |
| 4444 10_10_10_2 natural (`0x4001b001`) | 4, one big-endian 32-bit word | `R[9:0]` bits 31 to 22, `G[9:0]` bits 21 to 12, `B[9:0]` bits 11 to 2, `A[1:0]` bits 1 to 0 | G2 Figure C-12 (E) |
| 4444 10_10_10_2 reversed (`0x400e4001`) | 4, one big-endian 32-bit word | `A` bits 31 to 30, `B` 29 to 20, `G` 19 to 10, `R` 9 to 0 | G2 Figure C-13 (E) |
| 4224 10_10_10_2 natural (`0x4001b001`, 4224) | 8 per 2 pixels, two big-endian 32-bit words | word 0 `[Cb 31:22][Y 21:12][A 11:2][00]`, word 1 `[Cr][Y][A][00]` | G2 Figure C-15 for the VL name DM maps it to (E); the order Cb then Cr follows Table 5-4's pairing (I) |
| 422 8-bit (`0x1001b108`, 4220) | 4 per 2 pixels | Cb, Y, Cr, Y | G2 Figure C-3 (E); DM_IMAGE_PACKING_CbYCrY |
| 422 10-bit packed (`0x1001b10a`) | 5 per 2 pixels | Cb, Y, Cr, Y of 10 bits each, back to back, MSB first | G2 Figure C-5 (E) |
| 422 10 in 16, left (`0x2111b10a`) | 8 per 2 pixels, four big-endian 16-bit words | Cb, Y, Cr, Y, each sample in bits 15 to 6, six `p` bits below | G2 Figure C-16 draws the V Y U Y (3214) variant; the natural order is the same words with the order swapped, I |
| 422 10 in 16, right (`0x2121b10a`) | 8 per 2 pixels | Cb, Y, Cr, Y, each in bits 9 to 0, six zero bits above | G2 Figure C-17, same remark, I |
| 444 12 in 16, left or right (`0x2111b20c`, `0x2121b20c`) | 6 per pixel, three big-endian 16-bit words | R, G, B (or the CbYCr set) as signed 12-bit samples, left variant in bits 15 to 4 | the guides draw no figure for it; I from the name and the `p` and `s` conventions. The signed range and whether the padding is a sign extension on the right variant are U |

The 3214 variants (`_3214`) swap the order of the components inside the repeating pattern; G2's non-R figures show them (C-2, C-4,
C-14, C-16, C-17). They are not drawn here because no Flame or shipped program asks for one by default.

## 3. Worked examples

Each is a sample set written out as the bytes in memory, first byte first. The samples are chosen to hit every field.

- **444 8-bit natural, RGB memory** (Flame's default, section 4). Pixel R=0x10, G=0x80, B=0xEB gives `10 80 EB`. A 720 by 486
  frame is 720 x 486 x 3 = 1,049,760 bytes. The next pixel starts at byte 3, with no
  row padding unless the row-bytes control is set (G1: the default of 0 means exactly width x pixel size).
- **444 8-bit reversed**: the same pixel is `EB 80 10`.
- **4444 8-bit**: R=0x10, G=0x80, B=0xEB, A=0xFF gives `10 80 EB FF`.
- **4444 10_10_10_2 natural**: R=0x040, G=0x200, B=0x3AC, A=3 gives the word `(0x040<<22)|(0x200<<12)|(0x3AC<<2)|3` =
  `0x10200EB3`, bytes `10 20 0E B3`. Checked against Figure C-12 byte by byte: byte 0 is R[9:2] = `0x10`; byte 1 is R[1:0] then G[9:4] =
  `00 100000` = `0x20`; byte 2 is G[3:0] then B[9:6] = `0000 1110`; byte 3 is B[5:0] then A = `101100 11` = `0xB3`.
- **4444 10_10_10_2 reversed**: the same values give the word `(3<<30)|(0x3AC<<20)|(0x200<<10)|0x040` = `0xFAC80040`, bytes
  `FA C8 00 40` (Figure C-13: `11 111010`, `1100 1000`, `000000 00`, `0x40`).
- **422 10 in 16, left, natural order** (I for the order): Cb=0x200, Y=0x3AC, Cr=0x200, Y=0x3AC. Each sample shifts left 6 and the six `p` bits
  copy the sample's bits 9 to 4 (a reader may rely on it, a writer need not): Cb gives `0x8020`, Y gives `0xEB3A`. Bytes
  `80 20 EB 3A 80 20 EB 3A`.
- **422 8-bit**: white-ish pixel pair Cb=0x80, Y=0xEB, Cr=0x80, Y=0xEB gives `80 EB 80 EB`.

## 4. What Flame 9.0 asks for by default

**Result.** Flame 9.0 asks the DM2 library for the VIO packing numbered 0. The device library translates it to the packing
constant `0x1001b108` and sampling `0x4440`, which is the 4:4:4 8-bit natural-order packing: three bytes per pixel,
`R G B` for RGB memory (the guide draws the same three bytes as V Y U for video data), no padding. The module loads
`packer_444_8` and `unpacker_444_8` for it, the same pair it loads at initialisation (E, B). Grade: the translation from VIO packing 0 is E (V);
that Flame sends 0 is E for the depth value 0x82 and I for the claim that an 8-bit project, the default, is the one coded 0x82
(see "How it was determined").

**How it was determined.**

1. `VideoVIOConfigureVideo` (F, `0x11317940`) builds the video setup. Its packing comes from `convertIFFtoVIOPacking` (F,
   `0x11316600`, called at `0x11317cfc`) applied to a depth value derived from the project's frame resolution (E for the call; the
   routine between `VideoGetFrameResolution` and the conversion, reached through a table, was not followed, so the derivation of
   the depth value is U). The packing is a property of the project's frame depth, not a separate setting in the configuration file
   (I: no keyword for it was found in the executable's strings).
2. `convertIFFtoVIOPacking` returns, for a frame depth of 0x82, the VIO packing 0 on every platform (E). Depth 0x86 returns 0 for HD
   projects or platform type 3 or 4, 4 for platform type 5 and 3 for types 6 and 8. Depth 0x88 returns 3 except on platform type
   4 with HD video, where it returns 0. The depth names behind 0x82, 0x86 and 0x88 are not in the executable's exported
   symbols, so which depth is 8, 10 or 12 bit is U; 0x82 is I as the 8-bit one because it maps the same way everywhere.
3. `DlMlControlBase::toImagePacking` (V, `0x0b591c40`) turns the VIO packing into the library constant: 0 gives `0x1001b108`, 1 gives
   `0x2111b10a`, 3 gives `0x4001b001`, 4 gives `0x2111b20c`, and 2 is not supported by this module (it raises an error). `toImageSampling` (`0x0b591e00`)
   gives `0x4220` for 1 and `0x4440` for 0, 3 and 4. E (disassembly and the decompiler agree).
4. The same library's default video configuration (`getDefaultCfg`, V `0x0b5aa550`) carries packing 0, and the device constructor and `setPacking` (`0x0b5aa740`) store it in the
   configuration word at offset `0x94` (E). That the path-parameter word the `toImage*` routines read at offset `0x28` is this field is I (the
   routine that builds the path parameters from the configuration is not exported).
5. Flame's own packing names, found as a table of strings in the executable, line up with these four: "CbYCrY 10 in 16 L" (VIO 1,
   `422_10in16l`), "RGBA 10 10 10 2" (VIO 3), "RGB 12 in 16 L" (VIO 4) and the 8-bit ones (I: the table is of names; its index is not followed to the numbers).

**Colour space and the converters.** The default video setup has an in format and out format of SERIAL1, which the library maps to a
4:2:2 video sampling (`toVideoSampling`, V `0x0b590ca0`: path field 0 gives `0x4220`, 2 gives `0x4440`; the field being the format is I). So with packing 0 the
memory side is 4:4:4 and the jack side is 4:2:2: the board's output colour converter (section 4.4 of the [GIF note](gif-registers.md)) converts and subsamples. The image colour space
comes from `toImageColorspace` (V `0x0b5918e0`). With a 4:2:2 jack it is a 12-entry table indexed by Flame's colour-space number:
entries 0 to 3 are 601 (CbYCr head, RGB head, CbYCr full, RGB full), 4 to 7 are 709 in the same order, 8 to 11 are 240M, giving the OpenML
colour-space values `0x111, 0x211, 0x112, 0x212, 0x131, 0x231, 0x132, 0x232, 0x121, 0x221, 0x122, 0x222` (E for the table words; the reading of the digits as
representation, standard and range is I, from G1 Table 5-2's list of names). With a 4:4:4 jack (disassembly `0x0b591a1c` to `0x0b591b3c`, E) the library's `_forceVideoToRGB` byte decides: set, it returns the CbYCr full-range value of the
matching standard for any index; clear, it returns the RGB full-range value (`0x212`, `0x232`, `0x222`) for the odd indices 1, 3, 5, 7, 9 and 11 only, and raises an error for the even
(CbYCr) ones. Whether any caller sets the flag is U; it is a plain data byte in the library.
`convertIFFToVIOColorspace` (F, `0x113169c0`) maps Flame's standard (601, 709 or 240) and a 0 to 3 variant to those indices: 601 maps 0, 1, 2, 3 to 0, 1, 2, 3; 709 maps 0, 1, 2, 3 to 4, 6, 5, 7;
240 maps them to 8, 10, 9, 11 (E). Which variant and standard a default project uses is U here.

## 5. Rules a model needs

1. Select the unpack format from the unpacker image name loaded behind the GIF. A model that does not execute the images can recognise the pair
   by the image's contents (each shipped image has a fixed sha256; the [FPGA note](fpga-load.md) lists the first ones) or take the format
   from a property. The loaded image is not otherwise visible (E, section 1).
2. For `444_8` (the Flame default): read three bytes per pixel, R first, no padding, rows contiguous unless the row-bytes control says
   otherwise. Convert to the jack's colour space and sampling according to the colour converters' coefficients and offsets and the 8-bit flag at `0x80304c`.
3. For `4444_8`: four bytes, alpha last, alpha not sent to the jack.
4. For `4444_10_10_10_2`: one big-endian word, fields as the table in section 2; the reversed variant swaps the field positions.
5. For the 16-bit padded formats: big-endian words, mask or shift to the sample, ignore the padding.
6. The image dimensions come from the VBOB timing record and the raster controls ([pipes note](pipes-timing.md)); a frame is the active width by the two field heights
   summed. The placement of a frame in a DMA slot (line order, second start address) is not settled by any register read so far ([DMA note](dma.md)).

## 6. Not settled

| Unknown | What would settle it |
|---|---|
| Which Flame project depth is coded 0x82, 0x86 and 0x88, and the default project depth | the executable's depth table (its strings name only the movie-library packings); a project-creation trace |
| Flame's default colour-space number and standard for a new project | the configuration reader's default values in the executable |
| Signed range and padding of the 444 12 in 16 formats, and the 3214 layouts | a figure in the DM2 guide's appendix if one exists in an edition not held here; otherwise a loaded packer image's behaviour |
| Whether the DM2 interprets the `4:4:4` memory side exactly as the HD I/O figures draw it | the guides only state that the DM names map onto the VL names; the board's own documentation of the pixel path is not held |
| Flame 7.6 and later releases (9.2.5, 9.5.1) | the same two routines in those releases' `libDlVideoDeviceMl.so`; only 9.0 was read |
| Hardware: which image bytes differ between `packer_444_8` and `packer_422_8` | not needed unless a model runs the images |
