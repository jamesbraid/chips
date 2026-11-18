# Scoping datasheet: OCTANE Digital Video option (Galileo 1.5 board on the XIO module; IRIX driver `srv`, VL module `mgv`)

Status: **scoping draft, not independently reviewed.** It records what the shipped IRIX 6.5 software for the
Octane (IP30) Digital Video option reveals about its hardware and what a "board present, enumerates, opens" model
needs. It is not a register manual. Labels follow [AGENTS.md](../../AGENTS.md): **E** established, **I** inferred,
**U** unknown. Where the request asked for a "software expectation" grade, that is **E** here when the whole
routine or table was read from a shipped binary, and **I** when it is a reading from call lists or names.
Nothing here depends on a physical board. No IRIX source or restricted Library document was read.

The question it answers: can IRIX's driver and the Digital Video layer (VL, `videod`) be made to accept a modelled
board, enough that Flame, Flint and Smoke on an Octane see a video device, open it and start? Short answer in
section 7.

## Sources

| Tag | Source | Used for |
|---|---|---|
| B1 | IRIX 6.5.30 overlay product `impactvideo` (`impactvideo_6530m`, `.sw` sha256 `9bc8113b…`): `usr/cpu/sysgen/IP30boot/srv.a` (sha256 `829bae1f…4d6f59fe`, 28 members, ELF64 big-endian relocatable with symbols), `var/sysgen/master.d/srv`, `var/sysgen/mtune/srv`, `usr/lib32/dmedia/video/mgv.so` (sha256 `f1edf556…c1f656c2`, n32) and the 32-bit `usr/lib/dmedia/video/mgv.so` | kernel driver, tunables, VL module |
| B2 | Original 6.5 Octane Digital Video image (`octane_iv_6.5`, tar sha256 `59d5458e…`): the same product, an earlier build. `IP30boot/srv.a` sha256 `181d4a0b…50c32037`; also `IP22boot/mgv.a` and `IP28boot/mgv.a`, `master.d/{mgv,srv}`, `system/{mgv,srv}.sm` | release differences, the Indigo2 sibling driver, sysgen wiring |
| B3 | IRIX 6.5.30 overlay product `impactdm`: `usr/lib32/dmedia/video/impact.so` (sha256 `c1ade768…4c1bbff1`) | the other VL module that opens `/dev/mgv` |
| B4 | IRIX 6.5.22 kernel objects for IP30 (`giobr.o`, `gioio.o`, `gfx.o`, `mgras.a`, `mgvstubs.a`) and the 6.5.30 `usr/etc/videod`, `usr/lib32/dmedia/arch/{directvl,videodvl}/libvl.so.1`, `usr/include/dmedia/vl.h` | the GIO bridge the driver attaches through, the HQ4 side, the stub, the daemon and client library |
| M1 | SGI *OCTANE Digital Video and OCTANE Compression Installation Guide*, 007-3466-001 | board names, slots, flex cables, expected `hinv` text |
| M2 | SGI *OCTANE Digital Video Programmer's Guide*, 007-3513-001 (shipped as the `OctDigVid_PG` book in `impactvideo.books`) | VL nodes, formats, header names |
| H1 | Public Usenet posts, by message-id: `aud1v6$slq$1@news.lucky.net` (an Octane with the option: `videod -verbose` and `hinv -m -c video` output), `a43mev$8cn@netaxs.com` (board identifies itself as GALILEO15, part 030-0931-003 rev C), `WXvo9.1574$%25S.104377537@newssvr14.news.prodigy.com` (`/dev/mgv` missing), `35EADABF.ACB68815@cs.unc.edu` (the `MAKEDEV` stanzas), `32B054B6.2847@shoreline-studios.com` (what "mgv" stands for in SGI's own vocabulary), `6seppt$1t9q5@fido.engr.sgi.com` (Onyx2 video is DIVO) | product names, hinv captures, device node wiring |
| C1 | This repository: [bridge](../bridge/README.md), [crosstalk](../crosstalk/README.md), [dm2](../dm2/README.md) | Bridge identification and mode bit, widget conventions, sibling video board |

Disassembly in this pass is `mips64-linux-gnuabi64-objdump` and `nm` over the extracted objects through the retools
container. Ghidra was not run. Every fact graded E below was read from disassembly of the whole routine or from the
object's own data and string tables; routine names are the symbols the objects carry. No decompiled text, firmware
bytes or listings are in this page.

## 1. Identity

| Fact | Value | Grade |
|---|---|---|
| Marketing name | "OCTANE Digital Video" option (the guide's title and the `impactvideo` product description, "IMPACT Video Execution Environment"); the Usenet question about the board's other name asks whether it is the "D9-OCT-DIGVID" option and is unanswered in the corpus | E (guide, product), U (the order code D9-OCT-DIGVID) |
| Board name in `hinv -m` | `GALILEO15 Board: part 030-0931-003 rev C` (two public posts, same board). The graphics board beside it prints `GM20 Board: part 030-0957-003 rev H` | E (captures, one board) |
| Chip family name | The driver's sysgen files and strings call it "Galileo 1.5" (`srv: ... video driver (Galileo 1.5)`). The ASICs on the board that the driver addresses are named by the driver as VGI1 (DMA engine), CC1, CSC, AB (alpha blender) and TMI (texture/video map interface) | E (names), U (which are SGI ASICs, FPGAs or third-party parts) |
| Attach | A board in **slot B** of the Octane **XIO module** (the four-slot tray; graphics in slot A, or A and D), tied to the graphics board in slot A by **flex cables**, with a daughterboard on the video board. Software reaches it two ways: **registers** through the graphics board (HQ4, the ImpactSR family; see 2.3) and **DMA and interrupts** through a **Bridge widget in GIO mode** (its physical home is I) | E (guide for slots and cables; driver for the two paths) |
| Widget behind the GIO path | `giobr_init` registers for crosstalk part `0xc002`, manufacturer 54: the same identification as the PCI Bridge. `giobr_attach` accepts it only when widget status bit 5 is **clear** (GIO mode); the PCI attach path refuses a Bridge part whose bit 5 is clear, so the two drivers split one part number by mode ([bridge](../bridge/README.md)). That this Bridge sits on the XIO module beside slot B, rather than on the graphics board, is I | E |
| Kernel driver | sysgen module **`srv`**, prefix `srv_`, flags `soc`, objects in `usr/cpu/sysgen/IP30boot/srv.a`, shipped by the `impactvideo.sw.eoe` subsystem, **not** in the IRIX base. Its `master.d` and `mtune` names: `gal15itimeout`, `srv_ignore_2vgi1`, `srv_ignore_vgi1_warning`, `srv_reset_delay`, `srv_check_for_missing_interrupt`, `csc_reset_delay`, `i2c_reset_delay`, `srv_poolsize` (default 50 MiB), `srv_number_of_pools` (default 2) | E |
| Driver for the Indigo2 sibling | `mgv` (`IP22boot/mgv.a`, `IP28boot/mgv.a`, prefix `mgv_`), a GIO-bus driver with fixed vectors at `0x1f400000` and `0x1f600000`. It is the same video board generation on a different host | E |
| **Is the base-kernel `mgvstubs` this board's driver?** | **No.** `mgvstubs.a` (all of IP22, IP27, IP30, IP32, IP35 in 6.5.22) holds one function, `srvVidTextureXfer`, a stub for the hook the HQ4 graphics driver (`mgras.a`, `MgrasVidTextureXfer*`) calls when the video option is not installed; its master file declares only the module `oxu`. `mgv` is the product-family name; the driver on Octane is `srv`. A `USE: ... mgvstubs` line in `irix.sm` is how a kernel without the option satisfies that symbol | E |
| `/dev` node | `MAKEDEV` on IP30 links `/dev/mgv` to `/hw/srv` when that node exists (quoted in two public posts). `srv_attach` creates the hwgraph character device `srv` (prefix `srv_`) and adds it to the hwgraph root | E |
| `hinv` inventory entry | `_srv_init` calls `add_to_inventory` with class 12, type 11, controller 0, unit = the board count, state = board revision byte in bits 7:0, TMI revision in 11:8, CSC revision in 15:12. That matches the printed `Digital Video: unit 1, revision 4.2, TMI: revision 2, CSC: revision 1` | E (call arguments), I (class 12 type 11 as the hinv type name; the symbol names are not in the object) |
| IRIX releases | Present from the original 6.5 image through 6.5.30 (B1, B2 differ only in build). Not in the 6.5.22 base kernel set | E |
| User software | `impactvideo` (VL module `mgv.so`, demos, the Programmer's Guide), `impactdm` (the shared `impact.so` VL module, which also opens `/dev/mgv`), base `videod` and `libvl`, header `vl_mgv.h` (linked as `vl/dev_mgv.h`) and `vl_impact.h` per the guide | E |

## 2. What the driver touches

### 2.1 Probe and attach order

All of this is `srv_main.o`, read in full (`_gameraProbeVideo`, `_srvProbeVideo`, `_srv_init`, `_srv_init_intrs`,
`srv_attach`, `srv_reg`, `srv_ioctl`).

| Step | What happens | Grade |
|---|---|---|
| Registration | `srv_reg` calls `gioio_driver_register` twice with keys `0x11000000` and `0x11110000`, flags 0, prefix `srv_`. The keys look like four packed 8-bit GIO product ids (below): product `0x11` in slot 0, and in slots 0 and 1 for the two-VGI1 case | E (literals), I (the packing) |
| GIO bridge attach | `giobr_attach` (6.5.22 `giobr.o`, read in full) maps 16 MiB of the widget, refuses a Bridge with status bit 5 set, adds a `nic` vertex (the one-wire part that gives the `GALILEO15 Board` part number), then probes **four GIO slots** by reading a 32-bit word at slot offset + 4 with `badaddr_val` and masking to 7 bits. Slot offsets in the widget window are `0x200000`, `0x600000`, `0x700000`, `0x800000` with sizes `0x400000`, `0x200000`, `0x100000`, `0x400000`. The four ids are packed into one word, slot 0 in bits 31:24 down to slot 3 in bits 7:0, and `gioio_device_register` / `gioio_device_attach` match that word against the driver keys. If no slot answers, it logs and stops | E |
| Product id | `_srv_init` stores the value 17 (`0x11`) as the board's product id and the probe below expects the same value | E |
| Presence probe | `_srvProbeVideo` calls `_gameraProbeVideo`, which for each of two graphics-board records (`MgrasBoards`) writes `0x4210` to graphics register base + `0x61000`, then reads one byte at base + `0x70008` and requires `0x11`. On a match it records the graphics base and the HQ4 revision (a byte of the graphics record). Without a match the driver prints `No SpeedRacer Pro Video (srv)` and fails | E |
| PIO windows | `srv_attach` calls `giobr_bridge_config`, then `gioio_piotrans_addr(conn, 0, 0, 0, 0x400000)`: **4 MiB** at GIO slot 0, which is the VGI1 register file. When `srv_ignore_2vgi1` is 0 it also maps **2 MiB** at slot 1 (second VGI1). The default is 1 (ignore) | E |
| Per-board record | A 9,504-byte record is allocated; board name `mgv` is copied in at +8; locks, sync variables and eight small tables (sizes 39, 129, 38, 20, 6, 172, 15, 15, 15 bytes) are set up | E |
| Registers, one-time init | `srv_init_regs`: `_srv_reset` (below), then `_srv_init_edh`, `_srv_input_standard_detection`, `_srv_init_xpoint`, `_srv_init_videoin`, `_srv_init_videoout`, `_srv_init_genlock`, `_srv_init_CC`, `_srv_init_AB`, `_srv_init_CSC`, `_srv_init_TMI`, `_srv_init_cc1_io`, `_srv_setup_srv_bd`, `_srv_init_CC1Int`, `srv_gio_dma_init` (with mode 6), `_srv_init_i2c` | E (order), U (the values) |
| Hang-off | `ksync_attach` registers the board with the kitchen-sync (framelock) layer; `idbg` commands `srv`, `srvintrlog`, `srvlog`, `srvpcc`, `srvpdrb`, `srvvgi1`, `srvvgi1d` | E |
| Low memory | After init, if installed memory is above 1.5 GiB (`0x18000` pages, 16 KiB), the driver reserves `srv_number_of_pools * srv_poolsize` bytes of low memory with `srv_grab_lomem`; failure prints `Can't load srv driver:not enough low memory` and returns 12. The board's DMA reaches only low memory | E |

`_srv_reset`: set DCB control (below); write 1 to Galileo direct register 3, delay 300, write 0 to direct register 2;
read the TMI revision (indirect register 147); read the CSC revision (CSC direct register 3); a TMI revision below 4 or
a CSC revision below 4 disables a workaround and, past the limits, logs and bails; then Galileo indirect register 38
is written 1, delayed, then 128. Read in full; E. What registers 2, 3 and 38 are is **U**.

### 2.2 The two register paths

**Path A: the DCB window on the graphics board (E for addresses and widths, I for what each block is).** The driver
holds the graphics board's register base (`HQ4 base`, from `MgrasBoards`) and reaches the video chips through the
HQ4 **display control bus** window:

| HQ4 offset | What the driver does | Grade |
|---|---|---|
| `0x61000` | probe stores `0x4210` here before reading the id | E |
| `0x61010` | cleared to 0 when the HQ4 revision is 1 | E |
| `0x61050`, `0x61060`, `0x61068`, `0x61070` | `_srv_init_dcbctrl` stores `0x208a`, `0x1004`, `0x4210`, `1` (32-bit stores; the graphics board's DCB control registers, so the video part sits on a DCB slave) | E (stores), I (DCB meaning) |
| `0x70008` (byte) | board id, must read `0x11` | E |
| `0x72800` | block **AB** (alpha blender) | E (base), I (name from `srv_ab*` routines) |
| `0x73000` | block **CC** (CC1: crosspoint, input and output control) | E, I |
| `0x73400` | block **GAL** (the Galileo control block; also holds the TMI indirect pair) | E, I |
| `0x73800` | block **CSC** (colour-space converter) | E, I |

Inside each block the access rule is the same, read from `srv_ccdir`, `srv_cscdir`, `srv_abdir`, `srv_galdir` and their
indirect twins: a **direct** register *n* is the **byte** at `block + (n & 7) * 0x80 + 8` (so n=0..7 at stride `0x80`,
bounds checked: 8 for CC, CSC and GAL, 7 for AB). An **indirect** register is reached through two direct registers:
the index goes to direct register 1 (`block + 0x88`) and the data is read or written at direct register 2
(`block + 0x108`); AB uses registers 3 and 4 (`+0x188`, `+0x208`); TMI uses GAL direct registers 6 and 7 (`+0x308`,
`+0x388`). Indirect ranges from the bounds checks: GAL 0 to 39 and 240 to 255, CC 0 to 80, CSC 0 to 5, AB 0 to 38, TMI
0 to 149. All accesses are 8 bits wide and serialised with a spin lock per block. E for the rule, ranges and widths. The
meaning of any single register is U except where the driver's own names give it (see the ioctl names in 2.6).

**Path B: the GIO window through the Bridge (E for existence, size and slot, U for the map).** The VGI1 register file is
a 4 MiB window in GIO slot 0 (second one 2 MiB in slot 1). The driver's own debug tables name the global registers
`gioid`, `sysmode`, `chipid` and the per-channel registers `setup`, `intenab`, `hparam`, `vparam`, `trig`, `status`,
`stride`, `debug`, `dataaddr`, `descaddr`; two channels per chip ("VGI1 Channel 1/2 registers"). The offsets those names
sit at are **not** recovered: `srv_dma_getreg` and `srv_dma_setreg` read and write a software shadow of the registers,
so the `srv_vgi1_*_regs` tables are ioctl register numbers, not window offsets. The hardware stores are in
`srv_dma_setup`, `srv_dma_req`, `srv_dma_h_params` and `srv_gio_dma_init` and are not yet read. **U.**

### 2.3 Why the graphics board matters

The presence probe and every Galileo register access go through the HQ4 window, so the video option cannot attach
unless the ImpactSR (MGRAS) graphics driver has attached and filled `MgrasBoards`. The kernel's HQ4 driver also calls
back into the video driver for texture transfer (`MgrasVidTextureXfer*` calls `srvVidTextureXfer`) and the video
driver calls `MgrasGetVertLineCnt`, `MgrasWriteBfifo` and `MgrasVidTextureXfer*` in the other direction. E (symbols
and calls). A model of the board therefore needs a **graphics board model that provides the DCB window and the HQ4
revision byte**, or a shim at that boundary. The graphics repositories own that board; this page records only the
boundary the video driver uses. Whether the flex cables are the DCB itself or a separate sideband is **U**.

### 2.4 Interrupts

`_srv_init_intrs` allocates GIO interrupt lines 4, 6 and 7 on the board's connection (and line 5 for the second VGI1)
and connects two handlers: `srv_dma_interrupt` on line 4 (VGI1 DMA and, from inside it, the TMI interrupt
`srv_tmi_interrupt`) and `srv_cc1_interrupt` on line 6 (CC1: field and frame events, trigger, auto-wipe). Line 7 is
allocated and not connected there. `giobr_intr_alloc` / `giobr_setgioint` program the Bridge's GIO interrupt routing.
E for the allocations and handler names, U for which source raises which line and the status registers read in the
handlers (`srv_llvgi1_interrupt.o`, `srv_interrupt.o` not yet read). The driver also arms a periodic timeout every
`gal15itimeout` ticks (default 25) that checks for a missed interrupt and force-resets the chip (`srv_force_reset`);
`srv_check_for_missing_interrupt` defaults to 1. E.

### 2.5 DMA

VGI1 is a scatter-gather DMA engine on the GIO side. E for the following, read from the debug printers and the
interface routines: a **descriptor** is a list of 64-bit entries printed with a page frame number and a GIO address
(`%2d: %12llx (PFN:%x GIOaddr:%x)`), with a "more entries" link to a further descriptor page; a **request block (DRB)**
carries `dma_start`, `dma_end`, `status`, type, `msc`, two `ust` and `seq` pairs, two `ident` and `offset` pairs and a
count; a **channel** carries `setup`, `status`, `int_enab`, `trig`, `h_param`, `v_param`, `stride`, `data_adr` and
`desc_adr`. Buffers come from the digital-media streaming layer (`dms_*`) and are pinned (`userdma`, `kvtophys`),
the GIO-side address comes from `gioio_dmatrans_addr`, and cache handling uses `cache_operation` plus the
`srv_coherency_war` and `_heart_invalidate_war` switches. The byte layout of a descriptor entry, the register offsets
and the burst-length controls (`SRV_VGI1_READ_BURSTLEN`, `SRV_VGI1_WRITE_BURSTLEN` in `mgv.so`) are **U**.

### 2.6 FPGA and microcode loading

No firmware load path was found. `srv.a` has no `*flash*`, `*ucode*` or `*download*` routine (the Indigo2 `mgv.a` was
not read for one either), and `impactvideo` ships no `usr/dmedia/ucode` tree in the file list. The only one-time
programming is the register init above and the two-wire (I2C) sequences for the EDH and ML parts
(`i2c_start`, `i2c_send`, `i2c_rcv`, `srv_I2C_edh_seq`, `srv_I2C_ml_seq`, `srv_edh_*`), both E. Treat the board as
**fixed-function with a register-programmed configuration** until a pass proves otherwise (I). Compare
[DM2](../dm2/README.md), which loads FPGAs.

### 2.7 The user interface

`srv_open` and `srv_close` take no board number (one device node for all boards). `srv_poll` supports `poll` for
board events. `srv_ioctl` (read in full) dispatches by command word:

| Command | Meaning | Grade |
|---|---|---|
| `0x76640001` | store the board count (`srv_nboards`) to the user word | E |
| `0x76640002` | get board info: copies a 24-byte argument block (ABI-translated for 32-bit callers), then `copyout` of up to 64 bytes starting at the per-board record +8 (board name `mgv`, TMI and CSC revisions, test results) | E |
| `0x7664000a` | initialise the board (`srvInitialize`, not read further) | E |
| `0x6d67....` ("mg", 71 distinct sites in `mgv.so`) | the board's private commands: get and set config, window, mux select, CC1, CLUT load and read, digital in and out control, TMI control, key and effect read and write, auto-wipe, genlock and ksync control, EDH, trigger setup and wait, `PutFrame`, MSC and UST read, event queue and poll select, register read and write (`MGV_GETREG`, `MGV_SETREG`), VGI1 setup, DMA and unsetup, diagnostics | E (names), U (numbers and structures) |
| `0x6b73....` ("ks") | kitchen-sync (framelock) controls | E |

## 3. What the Digital Video layer needs

What follows is the **minimum for the video list to include the board and for a client to open it**, from `videod`,
`libvl` and `mgv.so`. Binary evidence is E; it was read as imports, exports, strings and the one probe routine, not as
whole-function traces.

| Step | What the software does | Needs from the model | Grade |
|---|---|---|---|
| 1 | `videod` scans `/usr/lib32/dmedia/video/*.so`; for each it loads the DSO (`Loading DSO (%s)`) and calls its device-dependent bind function (`mgvBind` in `mgv.so`). A bind that finds no hardware prints `no device found` and the module is dropped; `videod` exits `no devices found` only if every module is dropped. A transcript of a real Octane shows `impact.so` binding one board while `mgv.so` found none | the DSO, the base `videod` and `libvl` are all that is needed on the guest | E (strings, public post) |
| 2 | `mgv.so` opens `/dev/mgv`, which must resolve to `/hw/srv`; it issues `0x76640001` (count) and `0x76640002` (info, 64 bytes) and fails the bind on a short or failed answer. The 2002 post reports exactly this symptom for a machine with the option but the node absent | the `srv` hwgraph node with working open and the two ioctls | E (call sites), I (that count 0 or failure is what dropped the module) |
| 3 | `mgv.so` also opens `/dev/graphics` (and `/dev/opengl`) and asks it for board info, to find which graphics board hosts the video (strings `IMPACTSR`, `IMPACTPC`, `_mgvManagedBy`) | an ImpactSR graphics device that answers | E (strings), I (purpose) |
| 4 | `impact.so` (from `impactdm`) opens `/dev/mgv` as well; a public post shows `impactBind: can't open /dev/mgv` on a machine with only the compression board | `/dev/mgv` for the shared module | E |
| 5 | VL clients call `vlOpenVideo` (connects to `videod`), `vlGetDeviceList`, `vlGetDevice`, `vlGetNode`, `vlCreatePath`, `vlSetupPaths`, then `vlBeginTransfer` and buffers (`vlCreateBuffer`, `vlRegisterBuffer`, `vlGetNextValid`, `vlPutFree`). `libvl` exports all of these (`directvl` and `videodvl` variants). The device-independent calls need nothing from the hardware | the daemon running; enumeration and open succeed once step 2 does | E (exports) |
| 6 | "Products start" needs only steps 1 to 5. Running video needs the DMA, interrupt and register behaviour in section 2, plus a signal source model | defer | I |

Not examined for this scoping: the Discreet DL video layer itself (what it calls beyond VL, and whether it opens
`/dev/mgv` directly). See section 4 and the last list.

## 4. Holdings

| Item | Where it lives | Status |
|---|---|---|
| `impactvideo` and `impactdm` 6.5.30 overlays | the IRIX 6.5.30 overlay extracts and the retools `kudzu` root | held; the `.sw` images carry `srv.a`, `mgv.so`, `impact.so` |
| Original Octane Digital Video 6.5 image | the 6.5 driver mirror (`octane_iv_6.5`) | held |
| Octane Compression 6.5 image | same mirror (`octane_ic_6.5`) | held, not read; the compression board is a separate option on the same module |
| IP30 kernel objects for the GIO bridge and the HQ4 driver | the 6.5.22 and 6.5.30 kernel object sets | held |
| `videod`, `libvl`, `vl.h` | the DIVO/VL extract (`vl-6.5.30m`) in the chips root | held; `vl_mgv.h` and `vl_impact.h` are named in M2 and **not extracted** from the overlays yet |
| Installation guide 007-3466-001, Programmer's Guide 007-3513-001 | the techpubs library (guide); the Programmer's Guide inside `impactvideo.books` | held |
| Discreet Flame, Flint, Smoke installers | partial: Effects 7.1, Flame 4.02 media, spark 7.71 for O2 and the 2007 Flame, Smoke and Fire sets are in the software mirror | **Flame 7.x, Flint 7.7.2SE and 8.3.4, Smoke 4.0.3 and 5.0 for Octane were not found by name** |
| A real board's register captures, VGI1 window map, firmware | none | missing, and not expected: the driver shows none |
| Owner's or service manual with block diagram of the Galileo 1.5 board | none | missing; 007-3466-001 is installation only |

## 5. Unknowns, sized, and what settles each

| Unknown | Size | Route |
|---|---|---|
| VGI1 register offsets, widths, reset, and descriptor entry layout | the whole DMA contract; needed only to run video | read `srv_dma_setup`, `srv_dma_req`, `srv_dma_h_params`, `srv_gio_dma_init`, `srv_vgi1_dma.o` (disassembly); medium |
| What the HQ4 DCB window is, and the HQ4 revision byte the video driver reads | needed to answer the probe | the HQ4 graphics datasheet; read `mgras` init and `_srv_init_dcbctrl` callers; small |
| Meaning of GAL direct 2 and 3, indirect 38, 147 and the other init values | needed for a faithful reset | the init routines are small; list every constant and map to the ioctl names; small |
| Which interrupt line is raised by what; status registers in the handlers | needed for events | read `srv_llvgi1_interrupt.o`, `srv_interrupt.o`; medium |
| What `0x6d67....` ioctl numbers are, and their argument structs | needed for any control beyond count and info | extract `vl_mgv.h`; match to `mgv.so` call sites; small |
| What `/dev/graphics` info `mgv.so` needs | needed for enumeration on real IRIX | read `mgv.so` `mgvQueryXdevSource` and the `vs:` strings' routine; small |
| What the Discreet layer calls | scope of the target | locate the named Flame, Flint and Smoke installers (section 4), then read their video library imports against `libvl` and `/dev/mgv`; small once held |
| Flex-cable function; DV daughterboard role; GIO slot assignment on the XIO module | background | not needed for a software model; settle only if a capture exists |
| Widget number the XIO module takes on an Octane | needed for `hinv -mv` location | a published `hinv -mv` capture with the option; none held |

## 6. Plan

Smallest set that makes a board that is present, enumerates and opens:

1. **Extract `vl_mgv.h` and `vl_impact.h`** from the overlays and tabulate the `0x6d67` commands against `mgv.so`
   (small, no disassembly of the driver). This gives the ioctl numbers and structure sizes.
2. **Read `mgv.so` `mgvBind`, `mgvQueryXdevSource` and the open path** to the point where it declares a device found,
   and record exactly what `/dev/graphics` and `/dev/mgv` must return (small).
3. **Read the HQ4 side** (`MgrasBoards`, the DCB window and the revision byte) with the graphics-architecture owners,
   so the probe write to `0x61000` and the read of `0x70008` can be modelled (small).
4. **Decide the model boundary** (section 7) and write the qtest-style contract for count, info and init only.
5. Later, for running video: the VGI1 pass (2.2 path B, 2.5), then the interrupt pass (2.4), then the long ioctl set.

## 7. Verdict

A "present, enumerates, opens" model is **reachable from what is shipped**, and needs less than the DM2: no firmware,
three fixed ioctls (count, info, init), a character device `srv` in the hardware graph, and the probe contract against
the graphics board. The hard coupling is that the board is addressed **through the ImpactSR graphics board's DCB window
and through a GIO-mode Bridge widget on the XIO module**, so the work belongs with the graphics model and the XIO
module model rather than as a standalone widget. Real video (DMA, interrupts, the other 70-odd private commands) is
unmapped (section 5) and should wait. The Discreet requirement beyond VL has not been read. This is I, not E: it rests
on the 6.5.30 and early 6.5 drivers and the VL module, not on a run.

## Not done in this pass

- Ghidra was not used; objdump only. No whole-function decompile of the DMA or interrupt routines.
- The Indigo2 `mgv.a`, the `octane_ic` compression image, the `srv_i2c.o` and `srv_edh.o` routines were not read.
- The Discreet DL layer and the Flame, Flint, Smoke binaries were not read or located by version.
- No `hinv -mv` capture with a widget location for this board was found.
