# Cobalt display back end (DBE): registers, scan-out and modes

The display half of the Cobalt graphics subsystem is a register block at physical `0xd0000000` that matches, offset for
offset, the display back end of the O2 (see [GBE](../gbe/README.md)): same timing generator, same tiled frame buffer
fetch, same colour map, gamma, cursor and video-capture blocks. That identity is established for every offset and field
both drivers touch; for the blocks neither drives (cursor, capture, 10-bit gamma) it is inferred from the identical
layout, and the GBE page's field tables are the best available description of them, untested on Cobalt. Linux calls
the block DBE and the NT miniport prefixes its routines with `as`. Back to the [overview](README.md).

All accesses are 32 bits wide and uncached (Linux `sgivwfb.h`: "all loads and stores must be 32 bits"). Offsets below
are from `0xd0000000`.

Evidence per row: **L** = Linux `sgivwfb.c` and `sgivw.h` (public); **N** = the routine in NT `sgcomp.sys` v5.2.4 that
writes it (read in full); both agree where both are named. Grades are the overview's. No reset value is established for
any register: neither driver reads one before writing, and both only ever see a post-firmware state.

## General block

| Offset | Name (Linux) | What | Evidence | Grade |
|---|---|---|---|---|
| `0x000` | ctrlstat | chip ID in `[3:0]` (read by Linux as a constant field), `SENSE_N` `[4]`, `PCLKSEL` `[29:28]`. NT writes `0x30000000` as the last step of every mode set; Linux writes `0x20000000` before programming and `0x30000000` afterwards if bit 25 reads set. Linux treats `PCLKSEL` below 2 as "not scanning out from the internal dot clock". Meaning of bit 25 unknown | L, N | software expectation |
| `0x004` | dotclock | PLL: `M` `[7:0]`, `N` `[13:8]`, `P` `[15:14]`, `RUN` `[20]`. Both drivers write `M-1` and `N-1`. Output is 27 MHz times `M` over `N`, divided by 2 to the `P`; reproduces the clock column of 26 of the 27 NT table rows to within 1.4 percent (see below) | L, N | software expectation (fields), inferred (formula) |
| `0x008` | i2c | CRT I2C lines (DDC). NT's `CoDDC_GetEDID` reads an EDID over it. Bit positions unknown | L, N (name only) | unknown |
| `0x00c` | sysclk | system clock PLL. Neither driver touches it | L (name only) | unknown |
| `0x010` | i2cfp | flat-panel I2C lines, bit-banged. See below | L, N | software expectation |
| `0x014` | id | NT refuses to attach unless it reads `0x666` | N | software expectation |
| `0x018` | config | see below | L, N | software expectation |
| `0x01c` | bist | internal self-test status; neither driver reads it | L (name only) | unknown |

**Dot clock start sequence (NT `asSetConfigAndTiming`).** Clear everything above bit 15, wait 40 ms, write `0x4101`
(`M=2, N=2, P=1`), wait 40 ms, write `0x104101` (adds `RUN`), wait one second, write `0x4101`, wait 100 ms. Then, after
the timing registers below, write the real value without `RUN`, wait 40 ms, set `RUN`, wait 200 ms. No lock bit is
read. Observed behaviour of the driver; the purpose of the one-second dance is unknown. Linux writes the real value
with `RUN` and waits 11 ms.

**Config register (`0x018`).** Bits from Linux names: `0x01` video DAC enable, `0x02` sync on green, `0x04` pixel
blank, `0x08` flat-panel enable, `0x20` little-endian pixel memory, `0x40` tile history, `0x80` extended addressing.
NT writes `0xe5` (all of `0x80`, `0x40`, `0x20`, `0x04`, `0x01`), adds `0x02` when the mode asks for sync on green or a
boot option says so, always adds `0x08`, and clears `0x01` when a flat panel answered the probe unless the mode carries
the "magic key" flag (`0x2000`). Linux defines a frame-buffer value of `0xa7` (`0x80`, `0x20`, `0x04`, `0x02`, `0x01`) but its mode-set code never
writes the register, so only NT's usage is observed. Software expectation; a model should accept any value.

## Video timing block (`0x10000`)

Every window register is `ON` in bits `[23:12]` and `OFF` in bits `[11:0]`. The right-hand column gives what NT
writes from its mode record (width `W`, height `H`, totals `Ht` and `Vt`, blank, sync and PLL fields; the record is the
same layout as Linux's `dbe_timing_info`). Linux differs only where noted. All entries: software expectation.

| Offset | Name | NT writes |
|---|---|---|
| `0x10000` | vt_xy | live `x` `[11:0]`, live `y` `[23:12]`, `FREEZE` `[31]`. NT writes 0 first if frozen; its `asGetScanline` returns `[23:12]`. Linux treats `FREEZE` as "counter stopped" |
| `0x10004` | vt_xymax | `Ht` in `[11:0]`, `Vt` in `[23:12]` (zero while programming) |
| `0x10008` | vt_vsync | vsync start and end |
| `0x1000c` | vt_hsync | hsync start and end |
| `0x10010` | vt_vblank | vblank start and end |
| `0x10014` | vt_hblank | `ON = (hblank_start - 5) mod Ht`, `OFF = hblank_end - 3`. Linux writes `ON = hblank_start` |
| `0x10018` | vt_flags | `[2]` invert hsync drive when the mode flag `0x10` is set, `[0]` invert vsync when `0x20`. NT's `asSetPowerState` also drives `[1]` and `[3]` (below). NT writes `0x40` then `0` during programming, and its retrace handler sets bit 6 in stereo modes |
| `0x1001c` | vt_f2rf_lock | frame-to-field and frame-lock Y: `(vblank_start << 12) \| 0xfff` (mono), `(vblank_start << 12) \| vblank_start` (stereo). Linux does not write it |
| `0x10020` | vt_intr01 | scanline interrupts 1 (`[11:0]`) and 0 (`[23:12]`). NT parks both at `0xfff` (`0xffffff` written) |
| `0x10024` | vt_intr23 | the same for interrupts 3 and 2 |
| `0x10028` | fp_hdrv | flat-panel horizontal drive; NT sets `OFF = W` when a panel is present |
| `0x1002c` | fp_vdrv | `ON = 1`, `OFF = H` (NT sets `0x1000 \| H`) |
| `0x10030` | fp_de | flat-panel data enable; NT writes `0xffffff` |
| `0x10034` | vt_hpixen | `ON = hblank_end - 19` (wrapped by `Ht`), `OFF = (ON + W - 2) mod Ht`. Same in Linux |
| `0x10038` | vt_vpixen | `ON = vblank_end`, `OFF = vblank_start`. Same in Linux |
| `0x1003c` | vt_hcmap | colour-map write window, horizontal: `hblank_start`, `hblank_end` (Linux: `hblank_end - 3`) |
| `0x10040` | vt_vcmap | vertical: `vblank_start`, `vblank_end` |
| `0x10044` | did_start_xy | `Y = vblank_start - vblank_end - 1` (a small negative number), `X = hblank_end - 20` (wrapped) |
| `0x10048` | crs_start_xy | `Y` one more than the DID `Y`, `X = hblank_end - 54` (wrapped) (Linux calls 54 `DBE_CRS_MAGIC`) |
| `0x1004c` | vc_start_xy | same `Y` as DID, `X = hblank_end - 4` |

The NT code writes `vt_hpixen`, `vt_vpixen` first as `0xffffff` (off), starts the PLL, then writes the real values
last. The scanline-interrupt registers are written only through `asSetInterrupt(n, y)`, which accepts `n` below 4 and
`y` below 4096. Software expectation.

**Blanking and power (DPMS).** NT's `asSetPowerState` takes states 1 to 6 and edits bits `[3]` and `[1]` of `vt_flags`:
state 1 (on) clears both, 2 (standby) sets `[1]`, 3 (suspend) sets `[3]`, 4 to 6 set both. Which signal each bit
gates is inferred (bit `[1]` horizontal, bit `[3]` vertical, from the VESA states). With a flat panel present NT
instead sets the panel's power-save bit over I2C.

## Overlay, normal plane, DID

| Offset | Name | What | Grade |
|---|---|---|---|
| `0x20000` | ovr_width_tile | overlay plane width: whole 512-byte tile columns in `[12:5]`, remainder in 32-byte units in `[4:0]`, `FIFO_RESET` `[13]` pulsed set then clear (NT and Linux). Overlay is always 8 bits per pixel | N, L: software expectation |
| `0x20004` | ovr_inhwctrl | live copy; bit 0 is the DMA-enable that NT polls until it reads clear | software expectation |
| `0x20008` | ovr_control | shadow; bit 0 DMA enable, rest the overlay's tile-list pointer. NT clears bit 0 to stop and writes the list pointer to start | software expectation |
| `0x30000` | frm_size_tile | normal plane. `[12:5]` whole tile columns, `[4:0]` remainder in 32-byte units, `[14:13]` depth (0 = 8 bpp, 1 = 16, 2 = 32), `[15]` `FIFO_RESET` pulsed. A tile is 512 bytes by 128 lines, so a 32-bit mode has 128 pixels per tile column and a 16-bit mode 256. NT computes exactly this and writes the register twice around the reset pulse | established (Linux and NT agree, GBE page agrees) |
| `0x30004` | frm_size_pixel | height in `[31:16]` | established |
| `0x30008` | frm_inhwctrl | live copy; bit 0 live DMA enable, polled by NT | software expectation |
| `0x3000c` | frm_control | shadow. Bit 0 DMA enable, bit 1 "linear" (Linux sets it, NT does not), `[31:9]` pointer: Linux gives the frame buffer's physical address shifted right 9, NT gives its tile list. Both stop DMA by clearing bit 0 and wait up to 20 000 ten-microsecond steps for the live copy to follow | software expectation |
| `0x40000` | did_inhwctrl | live copy; NT tests bit 16 (byte at `+0x40002`, bit 0) | software expectation |
| `0x40004` | did_control | shadow. NT writes 0 at mode set and clears bit 16 to stop. Linux names bit 0 and writes 0 | software expectation; Linux's bit looks wrong, NT and the O2's GBE use bit 16 |
| `0x48000` | mode_regs[32] | per-DID window table: buffer mode `[1:0]` (3 = both), type `[4:2]` (0 = 8-bit index, 1 = 12-bit index, 2 = RG3B2, 3 = RGB4, 4 = ARGB5, 5 = RGB8, 6 = RGBA5, 7 = RGB10). Linux fills all 32 identically (8 bpp = index, 16 bpp = RGBA5, 32 bpp = RGB8). NT's mode-set code does not write this table | L: software expectation; NT: not touched in the routines read |

**Frame buffer memory.** Both the live and the shadow word are read by software; the engine takes the shadow at the
start of vertical blank. This is how NT page-flips (`asFlipTiles`, `asFlipFrontBack`): it rewrites the tile list or the
list pointer, writes `frm_control`, and relies on the copy. Software expectation.

**Tile lists.** NT keeps its lists in main memory as arrays of 16-bit entries, one per 64 KB tile, built by copying a
list of dwords from the memory manager shifted right 4. If those dwords are 4 KB page-frame numbers, the entry is the
64 KB tile number, which is the GBE's 16-bit tile pointer. Inferred. How the hardware turns an entry into an address
for a tile that is not contiguous is unknown but follows the GBE's.

## Colour map, gamma, cursor, video capture

| Offset | What | Evidence | Grade |
|---|---|---|---|
| `0x50000` | colour map, 6144 dwords in Linux's declaration (the GBE specification says 4608), one dword per entry, written as `R<<24 \| G<<16 \| B<<8` (both drivers). NT's `asSetColorRegisters` takes a count, a first index and four-byte entries whose first three bytes go to bits `[31:24]`, `[23:16]` and `[15:8]` | L, N | software expectation |
| `0x58000` | colour-map FIFO status. Linux waits until it reads non-zero, then writes that many entries. NT before every 32nd entry spins until the low six bits read zero or the value reaches `0x30`. A model that returns `0x40` satisfies both. Meaning inferred as a free-entry count | L, N | inferred |
| `0x60000` | gamma map, 256 dwords. Linux writes identity (`i<<24 \| i<<16 \| i<<8`). NT's gamma path (`GammaDataCallback`, `CO_CMD_SET_GAMMA`) was not found writing this range in the miniport; where NT puts gamma is unresolved | L | software expectation (Linux), unknown (NT) |
| `0x68000` | 10-bit gamma map, 1024 dwords | L (name only) | unknown |
| `0x70000` to `0x78100` | hardware cursor: position, control (Linux writes 0 to turn it off), 3 colours at `0x70008`, 64-dword glyph at `0x78000`; same offsets as the GBE's cursor | L (names) | unknown for programming (inferred from the GBE layout); neither driver enables it |
| `0x80000` to `0x80020` | video capture control words (9 dwords, as in the GBE). Neither driver touches them. The video in and out ports raise Cobalt interrupt pins 16 to 19 | L (names), Linux `cobalt.h` | unknown |

The NT miniport also claims exactly `0xd0000000` to `0xd008001f`, ending at the last video-capture word, which agrees with
the block's extent. Software expectation.

## I2C and the flat panel

Flat-panel presence and type are read over I2C through `i2cfp` (`+0x10`): `mli2cFlatPanelStatus` reads one byte from
device `0x71` (read address). The panel ID is bits `[7:5]` of that byte. `5` is the SGI 1600SW digital panel (1600 by
1024), which Linux uses as `FLATPANEL_SGI_1600SW`. Bit 2 of the status byte is power-save: NT's
`mli2cFlatPanelPowerSave` sets it when the panel is to sleep. The routines drive SCL and SDA by write-ahead masks held
in a context record, so the bit positions in the register are not visible in the driver code read. Software
expectation for the byte layout; unknown for the line bits.

## Mode table

NT's table `cobaltVTimings` (27 rows of `0x30` bytes at `sgcomp.sys` data offset `0xd4a0`) holds one record per
resolution and refresh, in the same layout as Linux's `dbe_timing_info` (Linux's header calls it the O2's video timing
structure). Software expectation for the contents; the 27 rows cover everything in the datasheet's mode list. Clock is
in kHz, `Ht`/`Vt` are totals, `M N P` are the PLL values before the `-1`.

| Mode | Hz | Clock | Ht x Vt | M N P | Note |
|---|---:|---:|---|---|---|
| 640 x 480 | 59.94 | 25 175 | 800 x 525 | 14 15 0 | neg hsync, neg vsync (flags `0x30`). Linux uses `15 2 3` for the same clock |
| 800 x 600 | 60.3 | 40 000 | 1056 x 628 | 3 1 1 | |
| 800 x 600 | 75 | 49 500 | 1056 x 625 | 11 3 1 | |
| 800 x 600 | 119.9 | 81 000 | 1056 x 640 | 3 1 0 | |
| 1024 x 768 | 50 | 54 163 | 1344 x 806 | 4 1 1 | |
| 1024 x 768 | 60 | 65 000 | 1344 x 806 | 12 5 0 | negative syncs |
| 1024 x 768 | 75 | 78 750 | 1312 x 800 | 35 6 1 | |
| 1024 x 768 | 85 | 94 500 | 1376 x 808 | 7 2 0 | |
| 1024 x 768 | 119.8 | 135 000 | 1392 x 809 | 5 1 0 | |
| 1280 x 1024 | 50 | 89 460 | 1680 x 1065 | 10 3 0 | |
| 1280 x 1024 | 60 | 108 000 | 1688 x 1066 | 4 1 0 | |
| 1280 x 1024 | 75 | 135 000 | 1688 x 1066 | 5 1 0 | |
| 1280 x 1024 | 85 | 157 500 | 1728 x 1072 | 35 6 0 | |
| 1376 x 768 | 59.94 | 162 000 | 1560 x 805 | 11 2 1 | clock column is wrong for this row: the totals and the PLL values both give about 74 MHz |
| 1600 x 1000 | 75 | 171 000 | 2160 x 1050 | 19 3 0 | |
| 1600 x 1000 | 85 | 193 500 | 2160 x 1050 | 36 5 0 | |
| 1600 x 1024 | 53 | 107 447 | 1900 x 1067 | 4 1 0 | flat panel, magic key (flags `0x3000`) |
| 1600 x 1024 | 60 | 106 913 | 1670 x 1080 | 4 1 0 | flat panel (flags `0x1000`); 1600SW |
| 1600 x 1200 | 50 | 130 500 | 2088 x 1250 | 29 6 0 | |
| 1600 x 1200 | 59.94 | 162 000 | 2160 x 1250 | 6 1 0 | |
| 1600 x 1200 | 75 | 202 500 | 2160 x 1250 | 15 2 0 | |
| 1920 x 1080 | 50 | 133 200 | 2368 x 1125 | 5 1 0 | |
| 1920 x 1080 | 59.94 | 159 840 | 2368 x 1125 | 6 1 0 | |
| 1920 x 1080 | 72 | 216 023 | 2560 x 1172 | 8 1 0 | |
| 1920 x 1200 | 50 | 161 500 | 2584 x 1250 | 6 1 0 | |
| 1920 x 1200 | 59.94 | 193 606 | 2584 x 1250 | 36 5 0 | |
| 1920 x 1200 | 66 | 213 180 | 2584 x 1250 | 8 1 0 | datasheet's maximum |

The datasheet's own list (640 x 480 at 60 up to 1920 x 1200 at 66) is a subset of these rows. NT picks a record by
exact width and height and a refresh rounded to whole hertz (`asMapModeToVTP`). Mode flags in the record: bit 3
(`0x8`) sync on green, bit 4 (`0x10`) invert hsync, bit 5 (`0x20`) invert vsync, `0x1000` flat-panel timing, `0x2000` a
key that keeps the DAC on with a panel attached. The user can also supply timings under a registry key
(`...\Silicon Graphics\Control Panel\Display\Timings`, and a "Video Format Creator" key whose records carry a CRC);
`VTableValidateMode` checks them. Software expectation.
