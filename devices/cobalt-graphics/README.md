# Cobalt graphics: the Visual Workstation 320 and 540 graphics subsystem

The Silicon Graphics 320 and 540 Visual Workstations (1999, Pentium II and Pentium II Xeon, Windows NT 4.0) have no
graphics card. Their display, 3D rasteriser and video ports are part of SGI's "Cobalt" core-logic chip set and use the
same 100 MHz main memory as the processors (a unified memory design, like the O2's). This page is the overview and the
emulator brief. The registers and the software that drives them are in three companion pages:

- [display-engine.md](display-engine.md): the display back end (timing, frame buffer scan-out, palette, gamma, cursor,
  I2C) and the mode table.
- [graphics-engine.md](graphics-engine.md): the rendering engine's window, the packet queue in main memory, interrupts.
- [nt-software.md](nt-software.md): what the Windows NT miniport, display driver and OpenGL driver do, and the Linux
  frame buffer driver.

The system side is covered by other pages: [the platform](../../platforms/visws/README.md), [the Cobalt system ASIC](../cobalt/README.md)
(processor interface, interrupt controller, timer) and [Lithium](../lithium/README.md) (PCI bridges, audio). This one stops
at the graphics blocks and says where it leans on them.

## Grades

Every fact carries one of five grades. Nothing is unlabelled.

- **established**: stated in a published SGI specification page, or read in full from a public driver and independently
  agreed by a shipped binary's routine read in full.
- **software expectation**: what one shipped driver does. It shows what software relies on, not what the hardware
  allows. A register the driver never touches stays unknown however well the driver is understood.
- **observed**: reported by trade press or a public post about the shipped system, not by a specification.
- **inferred**: a reasoned reading; the reasoning is given.
- **unknown**: not settled. The route that would settle it is given, and it is listed in
  [the open questions](../../questions/cobalt-graphics-open.md).

## Sources

| Source | Kind | Used for |
|---|---|---|
| SGI 320 Visual Workstation datasheet, Silicon Graphics 1999 | published specification | feature list, supported modes, driver list |
| SGI 320 Visual Workstation Product Guide, Silicon Graphics 1999 | published brochure | architecture overview, chip names |
| Microprocessor Report, 15 February 1999, "SGI Chip Set Powers NT Workstations" | trade press | bandwidth split, fill and triangle rates, UMA rationale |
| Design News, "SGI reinvents NT workstations" (1999) | trade press | three-ASIC structure, static memory split |
| SGI Cobalt Graphics Driver 5.2.4 for Windows NT 4.0 (patch SG0020054, 12 December 2001): `sgcomp.sys`, `sgcodd.dll`, `sgcoicd.dll`, `sgcotab.cpl`, with the matching `.dbg` symbol files | shipped binaries | everything marked software expectation |
| Same driver for Windows 2000 (also v5.2.4) | shipped binaries | cross-check only; not read in full |
| Linux `drivers/video/sgivwfb.c`, `include/video/sgivw.h`, `arch/x86/kernel/visws_quirks.c`, `arch/x86/include/asm/visws/cobalt.h` (Linux history tree, 2.6.x era) | public driver | display back end registers, memory reservation |
| Usenet posts in comp.sys.sgi.admin (2003 to 2004) | public posts | history, absence of Linux 3D support |

The NT driver package is on the Internet Archive as item `sgi_320_540_drivers` (file `SGICoGraphics524nt4.exe`). It is
a self-extracting InstallShield archive; its `data1.cab` holds the files above. SGI Support Folio, the original host,
is gone. The driver symbols ship in the package, so function and many variable names in `sgcomp.sys` are the
vendor's own and are cited here by name.

## What the subsystem is

- **A graphics, memory and I/O chip set of three ASICs.** The Linux kernel's own Visual Workstation notes name them Cobalt,
  Lithium and Arsenic, with the 3D engine inside Cobalt (see [the Cobalt page](../cobalt/README.md)). Design News counts
  the same three as a graphics engine, a display engine and an I/O engine, and the Product Guide names two custom parts, a
  "graphics and memory controller" and an "I/O coprocessor". Observed. Mapping them: the rendering engine is in Cobalt
  (established by the kernel notes); the display back end at `0xd0000000` is inferred to be Arsenic, because the NT
  driver prefixes every display-back-end routine `as` (`asStartFrm`, `asSetConfigAndTiming`, `asSetInterrupt`) and
  names its pixel-format table `ArsenicPixelFormats`; Lithium is the I/O chip. Nothing states where the register
  blocks physically are, so the mapping of blocks to chips is inferred.
- **Unified memory.** The memory array is 100 MHz, 256 bits wide and not interleaved, 3.2 GB/s in total. Per the trade
  press, up to 800 MB/s of that goes to the processors' front-side bus, up to 1.6 GB/s to the I/O side, and the rest,
  plus whatever the others leave unused, to graphics. Observed. The datasheet states 256-bit, 3.2 GB/s, ECC SDRAM and up
  to about 80 percent of system memory for textures. Established (published datasheet).
- **Memory split is static.** Design News says the video share is fixed by a profile, not allocated on demand. The
  Linux driver agrees: it reserves the top 8 MB of RAM as the frame buffer and never tells the kernel about it
  (`visws_memory_setup`), and the NT miniport takes its bank list from the loader (see
  [nt-software.md](nt-software.md)). Software expectation.
- **Pipeline stages the datasheet lists for the rendering engine.** Transform and lighting of vertices (up to four
  lights), culling, clipping to screen masks and clip IDs, setup of rasteriser and attribute interpolation, Gouraud
  shading, anti-aliased lines, point, line, triangle and rectangle rasterisation, stippling, scissor, texture mapping
  (nearest, bilinear, trilinear mip-mapped, up to 4096 by 4096), fog, alpha and chroma key, blending, dithering,
  logical operations, plane mask, stencil (8-bit), depth (16-bit float or 24-bit fixed), full-scene anti-aliasing at 4x,
  pixel transfer with format conversion and a 4x4 colour matrix (YCrCb to RGB and back), p-buffers, an overlay buffer,
  occlusion instruments, and frame-lock video sync. Established as a feature list (published datasheet); the order of
  the stages and what runs in software on the host is **unknown**. Trade press quotes 7.4 Mtriangles/s and 176 Mpixels/s
  with trilinear filtering as peaks. Observed.
- **Frame buffer formats.** The datasheet lists 8-, 16- and 32-bit colour, 16/16 and 32/32 double buffering, and
  1920 by 1200 at 66 Hz in 32-bit RGBA as the largest mode. Established. The display back end exposes three pixel depths
  (8, 16, 32 bits) as a two-bit field; see [display-engine.md](display-engine.md).

## Physical map (graphics-related windows only)

| Physical range | What | Source | Grade |
|---|---|---|---|
| `0xc2000000` | Cobalt CPU block. Register `+0x08` is the revision (high nibble `0xa`). NT refuses the part if the low nibble is 0 or 8 and names it "Cobalt Graphics ChipSet A0" to "AF" from the low nibble. Also holds the timer (Linux) | `sgcomp.sys` `CobaltFindAdapter`, Linux `cobalt.h` | software expectation (revision), established (timer block exists) |
| `0xc4000000` | Cobalt interrupt controller ("APIC" in Linux). Graphics pins below | Linux `cobalt.h` | established |
| `0xc8000000`, `0x19000` bytes | Rendering engine register window | `sgcomp.sys` `CobaltInitialize` maps exactly this length | software expectation |
| `0xca000000`, 4 bytes | Vertical-retrace interrupt register, read and then rewritten with its complement in the retrace handler. Mapped only if the display back end's ID register reads `0x666` | `sgcomp.sys` `CoVRetraceHandler` | software expectation |
| `0xc0000020`, 4 bytes | Mapped on the same condition; its value is copied into a command packet by `CobaltStartIO` and nothing else reads it. Purpose unknown | `sgcomp.sys` | unknown |
| `0xd0000000`, 16 MB | Display back end (DBE). Linux reserves `0x01000000` bytes; the NT miniport claims `0xd0000000` to `0xd008001f` and maps `0x80020` bytes | `sgivwfb.h`, `sgcomp.sys` | established (base), software expectation (extent) |
| Top of RAM, 8 MB default | Linux frame buffer. NT takes its own bank list from the loader | `visws_quirks.c`, `sgcomp.sys` | software expectation |

Interrupt pins on the Cobalt controller (numbering from Linux `cobalt.h`): 16 and 17 video out, 18 and 19 video in, 22
audio, 24 "AS", 25 "RE", 28 CPU timer and cache. The NT miniport asks the HAL for the vectors of pins 24 and 25 and
connects the engine's handler to pin 25 and the retrace handler to pin 24. So pin 25 carries the rendering engine's
interrupt and pin 24 the display's vertical retrace. Software expectation. That "RE" stands for rendering engine and
"AS" for Arsenic is inferred, not published: it agrees with the `as` prefix and the Arsenic pixel-format table above,
and with the kernel notes naming Arsenic as the video chip.

## What an emulator needs for a console and for the NT or Linux display

Enough to show text and a desktop:

1. **The DBE register window** at `0xd0000000`, 32-bit uncached accesses only. Reads must return the ID `0x666` at
   `+0x14` (NT refuses to attach otherwise). Software expectation.
2. **A timing generator state machine** good enough that the status bits NT and Linux poll change: the live DMA-enable
   words (`+0x20004`, `+0x30008`, `+0x40000`) must follow the shadow words (`+0x20008`, `+0x3000c`, `+0x40004`)
   within a frame, and the colour map FIFO word (`+0x58000`) must report free entries. Both drivers spin on these
   with a time limit and carry on regardless, so a fixed "ready" answer is enough to boot. Software expectation.
3. **Scan-out from main memory.** Either a linear frame buffer (Linux: tile pointer is the physical address shifted
   right by 9, linear bit set, 8 MB at the top of RAM) or a tile list (NT: 64 KB tiles named by a list in memory).
   Both are needed. The pixel formats are 8-bit indexed through the colour map, 16-bit and 32-bit RGB. Both drivers
   leave the DID (per-pixel window ID) fetch disabled by writing zero; the enable bit is bit 16 in NT and in the
   O2's GBE, and the Linux constant names bit 0, which looks like a slip. See [display-engine.md](display-engine.md).
4. **A dot clock that reports stable.** NT and Linux program a PLL and wait fixed times (40 ms, 200 ms, and a one-second
   dance); they never poll a lock bit, so none is needed.
5. **Interrupt pins 24 and 25** can stay idle for a Linux text console, which uses neither. The NT miniport connects
   both handlers at attach, so the pins must exist for NT. Whether NT waits for an engine interrupt before the
   first draw is not established.

Enough to run the NT display driver's 2D and the OpenGL driver:

6. **The rendering engine window**, the packet chain in main memory and its ownership bit (bit 0 of a header word,
   set by software and cleared by the engine), and the context-switch and doorbell registers. See
   [graphics-engine.md](graphics-engine.md). What the packets mean, to the level needed to rasterise, is **unknown**:
   no source describes the packet formats and no public code drives the engine other than SGI's own driver. A
   functional model will have to be clean-room reverse engineered from the OpenGL driver's setup code; that work is
   not done.

Not needed to show a console: video capture and video out, the cursor (neither driver programs the hardware cursor in
the routines read), I2C, flat-panel logic, DDC, the audio, 1394 and USB blocks.

## Open

The unknowns are in [the open questions](../../questions/cobalt-graphics-open.md): the packet format and the rendering
engine's unread register range, the cursor and video-capture programming, what the chip set's second interrupt
register at `0xca000000` carries, the I2C bit positions, the reset values of every register, and which ASIC hosts the display
back end (Arsenic is inferred).
