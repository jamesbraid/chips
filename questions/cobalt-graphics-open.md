# Cobalt graphics (Visual Workstation 320 and 540): what the sources do not settle

Question. What are the packet formats and register meanings of the Cobalt rendering engine, and which blocks sit on
which of the chip set's ASICs?

Status: **unknown** for everything below. What is established and what software expects is in
[the Cobalt graphics pages](../devices/cobalt-graphics/README.md).

- **Packet formats.** Partly settled ([graphics-engine.md](../devices/cobalt-graphics/graphics-engine.md#how-the-opengl-driver-builds-and-submits-packets-sgcoicddll-524)): the payload-count field of the header word (bits 11:5, checked against the shadow table), the chaining packet that ends a node and the two link-word layouts. Constant headers are now listed by emitting routine, and the target field of the pass-state family is two fields stepping together. Open: the headers built from computed fields (per-vertex draw packets), what the target bits select in the engine, the two builders' one-off length difference and which link word the engine reads, and the instance bits. Route: read the packet emitters of the OpenGL
  driver (`__glGenerateSetup`, `__glDrawVertexes_*`, the clear, copy and pixel-transfer builders) in Ghidra and
  correlate each emitted header with the field it feeds; the NT 4.0 `sgcoicd.dll` ships with symbols.
- **Host setup versus engine setup.** Clipping runs on the host: `__glDrawVertexes_Triangles` tests each vertex's clip code and calls `__glDoClipTriangle` for the triangles that cross (established, one routine). Whether lighting and culling run on the host or in the engine is open. The OpenGL
  driver's names suggest triangle setup runs on the host; the datasheet lists vertex lighting as a Cobalt feature. Route:
  the same emitters (does a lit vertex reach a packet?).
- **Engine register window.** Meaning of `0x08000` entries, `0x0c000` entries, `0x10000` write fields, `0x10008`, the two
  interrupt causes and `0x185c0` to `0x18800`; contents of `0x00000` to `0x07fff` and `0x0c200` to `0x17fff`. Route:
  the rest of `sgcomp.sys` (`pCoContextSwitch`, `CoBuildTlbPacket`, `CoProcessCobaltEvent`) read in full, and the same
  driver for Windows 2000 as a cross-check.
- **Second interrupt register.** The 32-bit register at `0xca000000` that the retrace handler reads and complements, and
  the register at `0xc0000020`. Route: the Linux Cobalt interrupt code (`visws_quirks.c` and the Lithium and PIIX4
  paths) and the HAL image for the PROM's use.
- **Which ASIC.** The kernel's notes name Cobalt, Lithium and Arsenic; the rendering engine is in Cobalt and the display
  back end is inferred to be Arsenic (NT's `as` routine prefix and `ArsenicPixelFormats`). Unconfirmed: which chip
  decodes `0xd0000000`, `0xca000000` and `0xc0000020`, and what the link between Cobalt and Arsenic carries. Route:
  a board photograph with chip markings, the PROM's device tables, or a boot log naming the resources.
- **Reset values.** For every register. Neither driver reads one before writing. Route: the PROM's initialisation of
  the display (the PROM image and the SGI "Software Support Kit" if held), or a hardware read, which needs the
  repository owner's approval and a read-only plan.
- **Cursor, gamma and video capture.** The `0x70000` cursor block, the `0x60000` and `0x68000` gamma maps and
  the `0x80000` capture words are named by Linux and untouched by Linux and by the NT miniport routines read. Where NT
  puts gamma and how the 2D cursor is drawn is unresolved. Route: the display driver `sgcodd.dll` (it may draw the
  cursor itself and send gamma as engine packets) and the Windows 2000 driver.
- **PLL and clock.** The `sysclk` register (`+0x0c`), the purpose of the one-second PLL restart in NT's mode set, and
  `ctrlstat` bit 25.
- **Pixel order.** Whether 32-bit pixels are red-first in memory (Linux) or red in the top byte of the word (NT's
  `ArsenicPixelFormats`), and what the config bit `LENDIAN` does. Route: a Linux boot of the real hardware, or the
  pixel-format table's users in `sgcodd.dll`.
- **Memory banks.** How the firmware chooses and passes the graphics memory split ("profile") and the bank list NT reads
  from `SGICtrl\Memory`. Route: the PROM and the NT loader on a system disk.
