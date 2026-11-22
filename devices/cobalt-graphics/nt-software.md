# Software that drives the Cobalt graphics: Windows NT driver set and Linux

What each shipped or public piece of software programs, and what that says an emulator must provide. Back to the
[overview](README.md); registers are in [display-engine.md](display-engine.md) and
[graphics-engine.md](graphics-engine.md).

## The SGI Cobalt Graphics driver 5.2.4 (NT 4.0)

The package is patch SG0020054, dated 12 December 2001, for NT Workstation 4.0 on SGI versions 1.0 and 1.1 of the
320 and 540. Its release note lists the fixes in this version: the bounding-box test of a display list overflowed
for coordinates above 2 to the 24th, a point light above a plane lit the plane below it (a sign error), and RGB textures
wider than 640 pixels were corrupted when loaded into texture memory. It supersedes 4.1.2 to 4.1.4 and 5.2.1 to 5.2.3,
and an earlier "MR software 1.8". A Windows 2000 build with the same version number ships separately; only the NT 4.0
one was read. Observed (release note); the file list is established.

| File | What it is | Grade |
|---|---|---|
| `sgcomp.sys` (62 992 bytes, linker timestamp 13 Dec 2001) | kernel-mode graphics driver. Imports `VIDEOPRT.SYS`, `ntoskrnl.exe` and `HAL.dll`. It does the mapping, the interrupt handlers, the scheduler and the display back-end programming | established (imports), software expectation (behaviour) |
| `sgcodd.dll` (299 696) | GDI display driver (`WIN32K.SYS` imports: `EngBitBlt`, `EngCopyBits`, `EngStretchBlt`, `EngCreateDeviceSurface`, `WNDOBJ_*`, `EngDeviceIoControl`, ...). Names the commands it sends to the kernel driver: see below | established |
| `sgcoicd.dll` (1 069 328) | OpenGL 1.1 installable client driver. Exports the standard `Drv*` ICD entry points (`DrvCreateContext`, `DrvSetContext`, `DrvSwapLayerBuffers`, `DrvDescribeLayerPlane`, layer palette calls, `DrvShareLists`, `DrvGetProcAddress`, `DrvValidateVersion`). Advertises the WGL extensions `make_current_read`, `pbuffer`, `pixel_format` and `swap_interval`, plus the SGIX pbuffer and instruments extensions (`glStartInstrumentsSGIX`, `glReadInstrumentsSGIX`, ...) | established |
| `sgcotab.cpl` (94 992) | the extra Display Properties tabs (colour, graphics, stereo, power) | established (existence) |
| `sgiFP.dll` (7 440) | flat-panel library: brightness, power save, gamma ramp, EDID get and set, a sensor interface (`sgiFP_*`, `edidAPI_*`) | established |
| `sssgipwr.scr` | screen saver that powers the display down | established |

The driver ships with its symbol files (`.dbg` and `.pdb`, built with Microsoft C 12.00), so the function and variable
names quoted in these pages are the vendor's own.

### Startup and platform dependencies

`DriverEntry` first asks the HAL for system information through the HAL dispatch table, class `0x8100001`, 16 bytes
back. If the answer is not success it prints "cobalt: Not an SGI HAL" and does not attach. So the NT HAL on these
machines is SGI's, and answers a query no stock HAL answers. What it returns is read in the HAL: three cache-flush
routine pointers and the cache-operation-invalidate flag ([nt-hal.md](../../software/visws/nt-hal.md#the-sgi-specific-hal-interface)). Established for the HAL's side, software expectation for the driver's use.

`CobaltFindAdapter` then claims `0xd0000000` to `0xd008001f` with `IoAssignResources`, reads the chip revision at
`0xc2000008` (accepted if the high nibble is `0xa` and the low nibble is neither 0 nor 8), and stores it. The revision
names the chip set as "Cobalt Graphics ChipSet A0" to "AF" in the registry's `HardwareInformation.ChipType`. The
adapter string is "Cobalt Graphics", the DAC "Cobalt Graphics Backend". Software expectation.

`CobaltInitialize` runs once (it counts calls and returns the first status after that) and does, in order: reads the
memory-bank list; maps the engine window `0xc8000000` and the display back end `0xd0000000`; reads the ID at `+0x14`
and, if it is `0x666`, maps `0xca000000` and `0xc0000020`; probes the flat panel over I2C; reads registry values;
sets up the tile and packet pools; connects both interrupts; and finally programs the display back end's mode.

### Memory banks (the UMA carve-out)

The driver does not size memory itself. It reads, from the control key `SGICtrl\Memory` under the system's `Control`
tree, the values `NumberOfBanks` and `BankSize00` to `BankSize31` and `BankAddr00` to `BankAddr31` (up to 32 banks). If
fewer than two are present it prints "GRAPHICS: no preallocated memory" through the HAL's display routine and bug-checks
(`0x5a`). So the loader, or the firmware through it, must hand NT a list of graphics banks by address and size; the
graphics memory is carved out of RAM ahead of the OS, as it is for Linux. The extent is a static split, as the trade
press says. How the firmware picks the split (a "profile") and where it keeps it is unknown. Software expectation.

### What is programmed where

| Step | Registers | Page |
|---|---|---|
| Mode set (`CoSetMode` to `asSetConfigAndTiming`, `asStartFrm`) | display back end `0x04`, `0x18`, `0x10004`..`0x1004c`, `0x20000`, `0x30000`..`0x3000c`, `0x40004`, `0x0` | [display-engine.md](display-engine.md) |
| Stop (`asStopAll`) | `0x10020`, `0x10024` set to `0xffffff`, then clear DMA enables of normal plane, overlay and DID, waiting for each live copy | same |
| Palette | `0x50000` colour map with FIFO at `0x58000` | same |
| Flip | rewrite tile lists, then `0x3000c` | same |
| Power (DPMS) | `0x10018` bits 1 and 3 | same |
| Context switch and kick | engine `0x10000`, `0x10008` | [graphics-engine.md](graphics-engine.md) |
| Interrupts | engine `0x10018`, `0x10020`; retrace `0xca000000` | same |

The miniport does not program the hardware cursor, the video capture block, the gamma tables in the routines read, or
the system clock PLL at `+0x0c`; the 2D path draws the cursor in software or through the engine, which is unknown.

### Commands from the display driver and the ICD

`sgcodd.dll` carries the names of the commands it sends to the miniport: `CO_CMD_CREATECONTEXT`,
`DELETECONTEXT`, `RELEASECONTEXT`, `SETCONTEXT`, `FIRSTSETCONTEXT`, `FINISH`, `CLEARBUFFER`, `KICKSCHEDULER`, `PIXELDMA`,
`PIXELDMA_CLEANUP`, `CACHEOP`, `SETUP_SCR2SCR`, `CREATE_BUFFER`, `FREE_BUFFERS`, `BIND_BUFFERS`, `UNBIND_BUFFERS`,
`SWAPBUFFERS`, `CREATE_PBUFFER`, `DELETE_PBUFFER`, `PIXELFORMATEXTDESCRIBE`, `GET_GAMMA`, `SET_GAMMA`, `WAIT_FOR_HARDWARE`,
`ALLOC_PACKET_BUFFER`, `FREE_PACKET_BUFFER`, `SHARELISTS`, `DESCRIBELAYERPLANE`, `SETLAYERPALETTEENTRIES`; the texture
table commands `CO_CREATE_TEXTLBPKT`, `CO_FREE_TEXTLBPKT` and `CO_SET_READY_TEXTLBPKT`; and an `OPENGL_GETINFO` query.
Each is a video IOCTL in the `0x23xxxx` range of the video device type that `CobaltStartIO` in `sgcomp.sys` dispatches
(base code `0x230400`; others include `0x230478` and `0x23206c`). The OpenGL driver does not call the kernel
driver: its import list has `ExtEscape` from GDI and no `DeviceIoControl`, so it goes through the display driver. Established for the names, software
expectation for the path.

Reading the names together, the OpenGL driver asks for a packet buffer mapped into its process
(`ALLOC_PACKET_BUFFER`), fills it with packets itself, and then asks the kernel to run it (`KICKSCHEDULER`,
`FINISH`, `WAIT_FOR_HARDWARE`). That is inferred from names, not from a read of the call sites.

### The OpenGL driver

`sgcoicd.dll` is mostly a software OpenGL front end: its 8 672 symbols include the `__glim_` (immediate mode), `__gllc_`
(display-list compile) and `__glle_` (display-list execute) families for every OpenGL 1.1 call, the span unpack and
pack routines for pixel transfer, and 15 texture storage formats (`Luminance8`, `LuminanceAlpha8`, `RGB8`, `RGB332`,
`XRGB1555`, `RGB565`, `RGBA8`, `RGBA4`, `ARGB4`, `RGBA5551`, `ARGB1555`, `Alpha8`, `Intensity8`, `ColorIndex8`,
`ColorIndex16`). Its hardware path is `__glGenerateSetup` and the `__glDrawVertexes_*` family, which compute per-triangle
setup with x87 and MMX code and write packets. The table `___glBlendTab`, the fog-and-dither tables and the "MMX q bias"
constants show that perspective-correct texture coordinates, colour and depth interpolation setup is done on the host
CPU, in packet-ready form. Observed from names and constants; the instruction-level behaviour was not read. That
means the engine consumes *setup* (edge and attribute slopes), not raw vertices, which is the single most important
fact for scoping a functional model, but it is inferred from names and has not been checked in code. The datasheet
lists "per-vertex lighting computation" and "rasterizer setup" among the Cobalt features; whether the engine or the
host does them is therefore **unknown**.

The datasheet lists "Direct X, GDI" next to the OpenGL driver; the OpenGL driver contains `DDERR_*` strings. Which
DirectDraw or Direct3D calls the hardware accelerates is unknown.

## Linux: `sgivwfb`

Linux has a frame buffer driver, `drivers/video/sgivwfb.c`, written by SGI (Jeffrey Newquist, 1999), and the platform
code in `arch/x86/kernel/visws_quirks.c` and `arch/x86/pci/visws.c`. It is the only open driver and uses only the
display back end. It does not use the rendering engine: the Linux 3D acceleration SGI demonstrated in 1999
was never published (SGI engineers' Usenet posts, 2004). Observed.

- Reserves the top 8 MB of RAM (`sgivwfb_mem_phys = mem_size - 8 MB`, size defaulted to 8 MB and trimmed to a megabyte)
  and tells the kernel it is reserved. The memory-size boot value is "alt_mem_k" from the loader.
- Registers the frame buffer at `0xd0000000`, `0x01000000` long, uncached, and adds a write-combining MTRR over the
  frame buffer.
- Mode set (`sgivwfb_set_par`): the sequence analysed in [display-engine.md](display-engine.md): select the internal PLL
  (`0x20000000` to `ctrlstat`), stop DMA, load an identity gamma and an identity colour map, program the frame tile
  fields with a linear frame buffer (`FRM_LINEAR`, tile pointer = physical address shifted right 9), fill the WID table,
  program timing, start the PLL, wait for the live frame DMA-enable word, set the pixel-enable windows, turn off the
  cursor.
- Supports 8, 16 and 32 bits per pixel from the table of modes in `sgivw.h` (about the NT table, fewer rows; the
  1600 x 1024 flat-panel mode is selected with `monitor:1600sw`). Pseudocolour for 8 bpp; 16 bpp is RGBA5551 and 32 bpp is
  RGBA8888 with red in the low byte in Linux's view. NT's pixel-format table (`ArsenicPixelFormats`) has the same 16-bit
  masks and puts red in the top byte of a 32-bit pixel, the opposite order; which is right for the hardware is unknown.
- Does not use any interrupt, DDC or the flat-panel I2C.

The kernel platform code, in the same files, gives the interrupt routing and the board type detection. Those belong to
the system-side pages, not here.

## Emulator checklist

1. `0xd0000000` DBE window with the register behaviour above; a scan-out that follows `frm_control`, `frm_size_*`
   and honours either the linear or the tile-list form. Enough for Linux's console and for NT's VGA-class use before the
   Cobalt driver loads (the PROM's own display path is unknown).
2. `0xc2000000` Cobalt CPU block with a revision byte in `0xa1`..`0xa7`, `0xa9`..`0xaf` at `+8`.
3. Memory-bank registry values: NT reads them from its own registry, which the PROM and loader fill; an emulated PROM
   path must supply two or more banks.
4. HAL: an SGI HAL answering `HalQuerySystemInformation(0x8100001)`.
5. Engine window `0xc8000000`, `0x19000` bytes: accept writes everywhere, return zero on reads except `+0x10000` (the
   running context), `+0x10018` (cause) and `+0x185c0`..`+0x185d0`, and reflect the context word the driver writes.
   That is enough for NT's miniport to attach, init, and schedule; it is not enough to draw.
6. Interrupt pins 24 and 25 with the register at `0xca000000`.
7. For hardware rendering, nothing is specified: see the open question on the packet format.
