# Scoping datasheet: OCTANE Digital Video option (Galileo 1.5 board on the XIO module; IRIX driver `srv`, VL module `mgv`)

Status: **scoping draft, not independently reviewed.** It records what the shipped IRIX 6.5 software for the
Octane (IP30) Digital Video option reveals about its hardware and what a "board present, enumerates, opens" model
needs. It is not a register manual. Labels follow [AGENTS.md](../../AGENTS.md): **E** established, **I** inferred,
**U** unknown. Where the request asked for a "software expectation" grade, that is **E** here when the whole
routine or table was read from a shipped binary, and **I** when it is a reading from call lists or names.
Nothing here depends on a physical board. No IRIX source or restricted held document was read.

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
| D1 | Discreet Smoke 5.0, Flame 7.6 (`7.6OCT`) and Flint 8.3.4 for IRIX 6.5 IP30, read from installed guest disks (product binary `smoke_IRIX_6.5_ip30`, `flame_IRIX_6.5_ip30`, `flint_IRIX_6.5_ip30`; the shipped `init.cfg`). Licence and key files not read | the DL video layer (section 9) |
| G1 | The IMPACT graphics workspace (jamesb/gr4): `devices/mgras/registers.md`, `board-identity.md`, `readings/mgras.a-mgras_mco.o.md` | the HQ4 window as the graphics driver sees it (8.3) |
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

`_srv_reset`: set DCB control (below); write 1 to Galileo direct register 3, delay 300, **read** direct register 2 (the plain board revision byte, stored);
read the TMI revision (indirect register 147); read the CSC revision (CSC direct register 3); a TMI revision below 4 or
a CSC revision below 4 disables a workaround and, past the limits, logs and bails; then Galileo indirect register 38
is written 0, delayed 300, then written `0x80`. Read in full; E. What registers 2, 3 and 38 are is **U**.

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
bounds checked: 8 for CC, CSC and GAL, 7 for AB). An **indirect** register is reached through a pair of direct registers, and the pair differs by block
(checked against `srv_galind`, `srv_cscind`, `srv_ccind`, `srv_abind` and `srv_tmiind_hwread`): **GAL and CSC**: index
written to direct register 0 (`block + 0x08`), data at direct register 1 (`block + 0x88`); **CC**: index to direct register 1
(`+0x88`), data at direct register 2 (`+0x108`); **TMI** (inside the GAL block): index to GAL direct register 6 (`+0x308`), data at
direct register 7 (`+0x388`); **AB**: a 16-bit address, high byte written to direct register 4 (`+0x208`) and low byte to
direct register 3 (`+0x188`) by `MgrasWriteBfifo` (a graphics-driver write routine, not a plain store), then the data at
direct register 1 (`+0x88`) for the kind-1 file (registers 0 to 38) or direct register 2 (`+0x108`) for the kind-2 file (0 to 3).
So in the GAL and CSC blocks direct registers 0 and 1 are the indirect pair, and GAL direct register 2 is a plain register (the board
revision read) and direct register 3 a plain control register. Indirect ranges from the bounds checks: GAL 0 to 39 and 240 to 255, CC 0 to 80, CSC 0 to 5, AB 0 to 38, TMI
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
| `0x76640001` (`VID_GETNUM_BOARDS`, name from `mgv.so` messages) | return the board count (`srv_nboards`) as the ioctl's return value | E |
| `0x76640002` (`VID_GETBOARDINFO`) | argument block `{int index; u32 buffer; u32 length}` (12 bytes for an n32 caller, widened to 24 in the kernel); `copyout` of `min(length, 64)` bytes from per-board record +8 to the buffer; the ioctl's return value is the byte count | E |
| `0x76640004` (`VID_ATTACH_BOARD`) | not a case of `srv_ioctl`; it falls to `srvPrivate`, which logs `srv_Private: Invalid ioctl` at note level and **returns 0**. Every command the driver does not know therefore succeeds | E |
| `0x7664000a` | initialise the board: `srvInitialize` calls `srv_reset(board, 0)`, which writes CC indirect register 38 and re-runs `srv_init_regs` (the register sequence of 2.1) | E |
| `0x6d67....` ("mg", 71 distinct sites in `mgv.so`) | the board's private commands: get and set config, window, mux select, CC1, CLUT load and read, digital in and out control, TMI control, key and effect read and write, auto-wipe, genlock and ksync control, EDH, trigger setup and wait, `PutFrame`, MSC and UST read, event queue and poll select, register read and write (`MGV_GETREG`, `MGV_SETREG`), VGI1 setup, DMA and unsetup, diagnostics | E (names), U (numbers and structures) |
| `0x6b73....` ("ks") | kitchen-sync (framelock) controls | E |

## 3. What the Digital Video layer needs

What follows is the **minimum for the video list to include the board and for a client to open it**, from `videod`,
`libvl` and `mgv.so`. Binary evidence is E; it was read as imports, exports, strings and the one probe routine, not as
whole-function traces.

| Step | What the software does | Needs from the model | Grade |
|---|---|---|---|
| 1 | `videod` scans `/usr/lib32/dmedia/video/*.so`; for each it loads the DSO (`Loading DSO (%s)`) and calls its device-dependent bind function (`mgvBind` in `mgv.so`). A bind that finds no hardware prints `no device found` and the module is dropped; `videod` exits `no devices found` only if every module is dropped. A transcript of a real Octane shows `impact.so` binding one board while `mgv.so` found none | the DSO, the base `videod` and `libvl` are all that is needed on the guest | E (strings, public post) |
| 2 | `mgv.so`'s device init (`mgvDeviceInfo` callback) calls `RM_Open`, which opens `/dev/mgv` and runs the exact sequence in section 8.2; any failure drops the module. The 2002 post reports exactly this symptom for a machine with the option but the node absent | the `srv` hwgraph node and section 8.2 | E |
| 3 | `mgv.so` also opens `/dev/graphics` (and `/dev/opengl`) and asks it for board info, to find which graphics board hosts the video (strings `IMPACTSR`, `IMPACTPC`, `_mgvManagedBy`) | an ImpactSR graphics device that answers | E (strings), I (purpose) |
| 4 | `impact.so` (from `impactdm`) `impactBind` opens `/dev/mgv`; on failure it prints `impactBind: can't open %s: %s`, opens `/dev/null` instead and **still adds the device**. So `impact` lists with or without the video board | none | E |
| 5 | VL clients call `vlOpenVideo` (connects to `videod`), `vlGetDeviceList`, `vlGetDevice`, `vlGetNode`, `vlCreatePath`, `vlSetupPaths`, then `vlBeginTransfer` and buffers (`vlCreateBuffer`, `vlRegisterBuffer`, `vlGetNextValid`, `vlPutFree`). `libvl` exports all of these (`directvl` and `videodvl` variants). The device-independent calls need nothing from the hardware | the daemon running; enumeration and open succeed once step 2 does | E (exports) |
| 6 | "Products start" needs only steps 1 to 5. Running video needs the DMA, interrupt and register behaviour in section 2, plus a signal source model | defer | I |

The Discreet DL layer is read in section 9.

## 4. Holdings

| Item | Where it lives | Status |
|---|---|---|
| `impactvideo` and `impactdm` 6.5.30 overlays | the IRIX 6.5.30 overlay extracts and the retools `kudzu` root | held; the `.sw` images carry `srv.a`, `mgv.so`, `impact.so` |
| Original Octane Digital Video 6.5 image | the 6.5 driver mirror (`octane_iv_6.5`) | held |
| Octane Compression 6.5 image | same mirror (`octane_ic_6.5`) | held, not read; the compression board is a separate option on the same module |
| IP30 kernel objects for the GIO bridge and the HQ4 driver | the 6.5.22 and 6.5.30 kernel object sets | held |
| `videod`, `libvl`, `vl.h` | the DIVO/VL extract (`vl-6.5.30m`) in the chips root | held; `vl_mgv.h` and `vl_impact.h` are named in M2 and **not extracted** from the overlays yet |
| Installation guide 007-3466-001, Programmer's Guide 007-3513-001 | the SGI printed manuals library (guide); the Programmer's Guide inside `impactvideo.books` | held |
| Discreet products with the DL video layer | Smoke 5.0, Flame 7.6 and Flint 8.3.4 are held as installed Octane guest disk images (section 9); install media for Flame 7.x, Flint 7.7.2SE and Smoke 4.0.3 are not in the software mirror by name | held as disks; Flame 7.0, Flint 7.7.2SE, Smoke 4.0.3 not read |
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

## 6. Plan (passes 1 to 4 done in section 8; kept for the record)

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

## 8. Present, enumerates, opens: the model contract

What a QEMU model must present so that **unmodelled IRIX 6.5.30 `srv.a` and `mgv.so` attach, enumerate and open**,
and `videod` lists the board. The device node, the three ioctls and the hinv line are produced by the unmodified guest
driver; the model supplies hardware only. Graded as in the rest of this page. Passes 1 to 3 of the plan are folded in.

### 8.1 Ioctl numbers (pass 1)

The programmer's-guide header names (`vl_mgv.h`, `vl_impact.h`) are not held (section 4); the `0x6d67....` numbers
below are the immediates that precede an `ioctl` call in `mgv.so`, matched to the nearest exported function, so the
function column is approximate (E for the number, I for the attribution). The names `VID_GETNUM_BOARDS`,
`VID_GETBOARDINFO` and `VID_ATTACH_BOARD` are the module's own message strings (E).

| Command | Name or caller | Argument | Grade |
|---|---|---|---|
| `0x76640001` | `VID_GETNUM_BOARDS` | none; count is the return value | E |
| `0x76640002` | `VID_GETBOARDINFO` | `{int index; u32 buf; u32 len}` (n32, 12 bytes); return value is bytes copied, at most 64 | E |
| `0x76640004` | `VID_ATTACH_BOARD` | `{int index; 8 zero bytes}`; driver returns 0 as an unknown command | E |
| `0x7664000a` | initialise | none | E |
| `0x6d670021` | set-genlock-control command (`srvSetCtrl` -> `_srvGenCtl`, pair of `0x6d670022`), sent once after init | a block built by `mgvGetCtrlTriggerInfo`, about 32 bytes; return value must be 0 or more | E (number, handler), U (layout) |
| `0x6d670001`..`0x6d67003f` | the private set seen at call sites: `1 2 3 5 7 8 9 a f 10 11 14 15 17 18 1a 1b 1c 1d 1e 1f 20 21 23 24 26 27 28 29 2a 2e 2f 30 3f` | per command | E (numbers), U (structs) |

`mgv.so` call sites also use `/dev/graphics` commands 101, 102 and 103 (8.2).

### 8.2 What the open path requires (pass 2)

`mgvDeviceInfo` (name `mgv`) names an init callback. It calls `RM_Open`, which reaches `SUPP_Open`, `MGV_OpenFD` and
`MGV_FindResources` in `mgv.so`, read in full. Any failure returns nonzero and `videod` drops the module
(`no device found`). The sequence, with the condition each step needs:

| Step | Call | Required | Grade |
|---|---|---|---|
| 1 | `open("/dev/mgv", O_RDONLY)` | succeeds (the `srv` hwgraph node exists, 8.5) | E |
| 2 | ioctl `0x76640001` | returns above 0 | E |
| 3 | for each board *i*: ioctl `0x76640002` with length 20 | returns 20 or more; the buffer starts with a NUL-terminated name | E |
| 4 | if the name equals `mgv`: open `/dev/mgv` again, ioctl `0x76640004` | returns 0 or more | E |
| 5 | ioctl `0x7664000a` | returns 0 or more | E |
| 6 | ioctl `0x6d670021` with the trigger block | returns 0 or more | E |
| 7 | ioctl `0x76640002`, board 0, length 64 | returns 64 (the driver copies exactly 64) | E |
| 8 | read word at buffer +40 (board record +48, the TMI revision byte) | below 13 or equal to 15 marks features available; 13, 14 or above 15 prints `Warning - Video texturing not supported on old TMI hardware` and clears the texture resource | E (code), I (meaning of the printed text) |

`/dev/graphics` is opened by a separate routine of `mgv.so` that never fails the bind: `open("/dev/graphics",
O_RDWR|O_NONBLOCK)`, `fcntl` close-on-exec, ioctl 101 for the board count, ioctl 102 per board with a 204-byte buffer,
matching the name against `IMPACTPC` or `IMPACTSR`, reading a one-byte refresh code at buffer +42 (50, 60 or 72 select a
floating-point value) and a flag at +53, then ioctl 103. Failure of any step prints through `ErrorF` and returns 0 (`mgvdd:
Couldn't find gfx! Default to IMPACT on board 0`). The graphics driver is a separate model (section 2.3); it is not part
of this contract. E. `/dev/opengl` is opened by `impact.so`, not `mgv.so`.

### 8.3 The graphics-side coupling (pass 3)

Read in full: `_gameraProbeVideo`, `_srvProbeVideo`, `_srv_init_dcbctrl`, `_srv_reset` of `srv_main.o`/`srv_init.o`,
`giobr.o`. The IMPACT graphics workspace's pages, which record the same HQ4 window from the graphics driver's side
(`devices/mgras/registers.md`, `board-identity.md`, `readings/mgras.a-mgras_mco.o.md`), are cited where they cover it.

| Fact | Value | Grade |
|---|---|---|
| `MgrasBoards` | a table of two records of 88 bytes, filled by the graphics driver before `srv` probes. Record +0: the uncached register base of the HQ4 window (64-bit pointer); +8: a pointer to the graphics driver's per-board structure; +24: a nonzero word when the entry is valid. The structure at +8 holds, at its +200, a pointer to a block whose byte at +55 is the HQ revision (1 = rev A per the graphics workspace's `HQ_REVISION`) | E (offsets), I (meaning of +55) |
| Probe | for each valid record in order: store the 32-bit value `0x4210` at base `+0x61000`; load the byte at base `+0x70008`; the first record whose byte is `0x11` wins and its base becomes the video chip window. No match returns 0, the driver prints `No SpeedRacer Pro Video (srv)` and fails | E |
| Same byte, other reader | the graphics driver's multi-channel-option probe reads the same offset and accepts a high nibble of 4 as "option present", `0xff` as absent. A video board therefore reads `0x11`, which is not a multi-channel option, and a missing board reads `0xff`. The graphics workspace calls this the option ID byte at DCB device 0 | E (both probes), I (that one byte serves both) |
| DCB address layout | the graphics workspace decodes a DCB address as device in bits 14:10, register select in bits 9:7, data width in bits 4:3 (1 is one byte), the low bit pattern `...8` being a one-byte access. Decoding this driver's windows with that rule: `0x70008` is device 0 select 0, the AB block `0x72800` is device 10, CC `0x73000` is device 12, GAL `0x73400` is device 13, CSC `0x73800` is device 14, each with one-byte accesses at select *n* (the `(n & 7) * 0x80 + 8` rule of 2.2) | I (the graphics workspace grades the layout inferred) |
| HQ4 revision byte effect | when the byte is 1 the driver writes 0 to base `+0x61010`; any other value leaves it | E |
| DCB control stores | `_srv_init_dcbctrl` stores `1`, `0x4210`, `0x208a`, `0x1004` at base `+0x61070`, `+0x61068`, `+0x61050`, `+0x61060`. The graphics workspace lists a 12-entry `dcb_ctrl` array (fields: setup 12:10, hold 8:6, width 4:2, async acknowledge 1, sync acknowledge 0) at a different offset; whether the two are the same registers is unknown | E (stores), U (alias) |
| Video option bit | the graphics workspace records that bit 7 of the byte at HQ4 `+0x071708` is **clear** when a video option board is present. The video driver does not read it | I (source grades it inferred) |

### 8.4 Hardware accesses the model must serve (every one on the attach and init path)

All register facts E unless marked. A model that answers every other access with zero is, per the code read, accepted
(section 8.6); only the rows marked **required** change the outcome.

**GIO-mode Bridge widget (the XIO module's video board)**

| Access | Required behaviour | Grade |
|---|---|---|
| Widget ID word at offset 4 | part `0xc002`, manufacturer 54; revision field as any Bridge revision the kernel accepts | E |
| Widget status word at offset `0xc` | bit 5 **clear** (GIO mode) **required**: with it set `giobr_attach` returns -1 and the PCI path would take the widget instead | E |
| Window of 16 MiB | `xtalk_piotrans_addr` of 0x1000000 at offset 0 | E |
| Slot probe | 32-bit reads at window offsets `0x200004`, `0x600004`, `0x700004`, `0x800004` through `badaddr_val`: a bus error means no board in that slot. Slot 0 returns a word whose low 7 bits are `0x11` **required** (it is the low word of the 64-bit GIO_ID register at slot offset 0, section 11); slots 1 to 3 must fault or return 0 | E (offsets, mask), I (the value is the product ID: the driver's key `0x11000000` and stored board product ID 17) |
| Slot windows | slot 0 4 MiB at `0x200000` (VGI1 registers, mapped by `srv_attach`), slot 1 2 MiB at `0x600000` (second VGI1, mapped only if `srv_ignore_2vgi1` is 0), slot 2 1 MiB at `0x700000`, slot 3 4 MiB at `0x800000`. The sizes of slots 0 and 1 are confirmed by `srv_attach`; the table's slot 2 window overlaps slot 1, as read | E |
| Bridge register file | `do_giobr_hw_init` and `do_giobr_bridge_config` read and write the usual Bridge widget registers (control, interrupt, request-buffer, ATE) and size the SSRAM by writing and reading back a 64-bit pattern at the Bridge's SSRAM window (offset `0x80000`); behave as a Bridge | E (access), U (which registers differ in GIO mode) |
| NIC | `nic_bridge_vertex_info` reads the board's one-wire part: supplies `GALILEO15 Board: part 030-0931-003 rev C` to `hinv -m` | E (call), I (the strings are from captures) |
| GIO interrupts | lines 4, 6, 7 allocated; 5 for a second VGI1. The model need not raise any of them for open | E |

**HQ4 window (graphics model)**

| Access | Required behaviour | Grade |
|---|---|---|
| base `+0x61000` 32-bit write `0x4210` | accepted | E |
| base `+0x70008` byte read | returns **`0x11` required** | E |
| base `+0x61010`, `+0x61050`, `+0x61060`, `+0x61068`, `+0x61070` 32-bit writes | accepted | E |
| GAL direct register 3 (`+0x73400 + 3*0x80 + 8 = +0x73588`) byte write `1`, then 300 delay units, then direct register 2 byte read | the read is the board revision byte stored at record +32; `0x24` is consistent with both the printed `4.2` and the driver's `& 0xf >= 4` test | E (access), I (0x24) |
| TMI indirect register 147 (index to GAL direct 6, data at direct 7) byte read | the TMI revision byte; `2` matches the printed `TMI: revision 2`. Values 13, 14 and above 15 disable texturing in `mgv.so` (8.2 step 8) | E (access), I (value 2) |
| CSC direct register 3 byte read | the driver stores the value plus 1 as the CSC revision; read `0` for the printed `CSC: revision 1` | E (access), I (value 0) |
| GAL indirect register 38 writes (`0`, then `0x80` after a 300 delay) | accepted; made by `_srv_reset` | E |
| all other block accesses in `srv_init_regs` (`_srv_init_edh`, `_srv_input_standard_detection`, `_srv_init_xpoint`, `_srv_init_videoin`, `_srv_init_videoout`, `_srv_init_genlock`, `_srv_init_CC`, `_srv_init_AB`, `_srv_init_CSC`, `_srv_init_TMI`, `_srv_init_cc1_io`, `_srv_init_CC1Int`, `_srv_init_i2c`) | byte writes and reads in the ranges of 2.2; their return values are ignored on the attach path (they set test bits only in the diagnostic ioctl) | E for the ignored returns of `srv_init_regs` |

**Process conditions**

| Condition | Effect | Grade |
|---|---|---|
| installed memory above 1.5 GiB (`maxmem` above `0x18000` pages) | the driver reserves 2 x 50 MiB of low memory; if that fails the load fails with `Can't load srv driver:not enough low memory` | E |
| i2c engines (`i2c_*`, EDH and ML sequences) | polled with `us_delay` and the `srv_i2c_timeout` and `i2c_reset_delay` (300000) tunables. A model that never acknowledges costs delay time and returns errors that `srv_init_regs` ignores; not traced to a hang | U |

### 8.5 The node, the three ioctls and the hinv entry

| Item | Value | Grade |
|---|---|---|
| Hardware-graph node | `/hw/srv` (character device `srv`, driver prefix `srv_`), made by `srv_attach`; `/dev/mgv` is a link made by `MAKEDEV` at boot when `/hw/srv` exists | E |
| Ioctls | `VID_GETNUM_BOARDS`, `VID_GETBOARDINFO` and `VID_ATTACH_BOARD`/init as in 8.1, all served by the guest driver | E |
| `hinv` line | `Digital Video: unit 1, revision 4.2, TMI: revision 2, CSC: revision 1`, from `add_to_inventory(class 12, type 11, controller 0, unit = board count, state = rev | TMI << 8 | CSC << 12)` with the revisions above | E (call), I (the byte for 4.2) |
| `hinv -m` board line | `GALILEO15 Board: part 030-0931-003 rev C` from the widget NIC | I |

### 8.6 What may be left unmodelled for this milestone

E for each, from the code read: the second VGI1 (default ignored); every VGI1 register beyond the four of section 11.2 and every descriptor; GIO interrupt sources (no handler runs without an interrupt, and the
missed-interrupt timer acts only while a transfer is active); video signal sources and sinks; the EDH and ML parts
behind I2C (until a path uses them); the OCTANE Compression board; the `0x6d67....` set beyond `0x6d670021`. **Not**
safely unmodelled: anything the Discreet layer drives after the board opens (section 9), because `vlSetupPaths` runs the
private ioctls that program the DCB blocks.

## 9. The Discreet DL video layer (software expectation)

Read from the shipped monolithic product binaries of Smoke 5.0, Flame 7.6 (build `7.6OCT`) and Flint 8.3.4 on IRIX
6.5 for IP30 (n32, with a symbol table). All three carry the same video layer (`libimpact/Video.C`, `videoOctane.C`,
`videoIOOctane.C`, `videoImpact.C`) and the same strings. Disassembly of Smoke 5.0; Flame 7.6 and Flint 8.3.4 compared by
string sets only. Licence and key material on the disks was neither read nor copied. Grade here: **software expectation**
(shipped-binary behaviour), written E for read in full and I for call-list readings.

**Requirements beyond VL enumeration (lead finding)**

1. **The screen nodes need the graphics path.** The output path is a `VL_SCREEN` source into a `VL_VIDEO` drain (plus a
   `VL_INTERNAL` colour-space node and an optional `VL_VIDEO` loopback); the input path is a `VL_VIDEO` source into
   `VL_MEM` and `VL_SCREEN` drains. `VL_SCREEN` nodes are the graphics board's, so the DL cannot run video on the Digital
   Video board alone. E (message strings `SetupSrcNode (VL_SCREEN) failed`, `SetupDrnNode (VL_VIDEO) failed`,
   `SetupDrnNode (VL_MEM) failed`, `SetupCscNode (VL_INTERNAL) failed`, `SetupExtNode (VL_VIDEO, loopback) failed`).
2. **Starting the product with `Video OctaneVideo` configured already opens a screen-to-video path.** `VideoInit`
   reads the configured device type; type 1 (`OCTANEVIDEO`) calls `InitVideoOctane`, which tail-calls
   `VideoOctaneVideoOutput(1, 0)`. That builds the path and runs `vlSetupPaths`, whose work in `mgv.so` is the private
   `0x6d67....` ioctl set, hence DCB block writes. "Board present, enumerates, opens" may therefore be enough for the
   listing but not for the products' first screen. E (call chain), I (that `vlSetupPaths` reaches the DCB).
3. **The X server's `XSGIvc` extension.** The DL queries its version, the video screen info, gamma maps and sets the
   screen input sync source; it prints `Failed to query video screen info from XSGIvc` and `Cannot set gamma: XSGIvc
   extension not supported by X server` when it is missing. This belongs to the graphics model and X server, not the
   board. E (strings and imports).
4. **Digital-media buffers.** Transfers use the `dmBuffer*` pool calls and `vlDMPoolRegister`, ring size from the
   environment variable `DL_VL_RING_SIZE` (`vl_ring_size` and `vl_ring_size_ui` globals). Only after a transfer starts.
   E (imports).
5. **Environment switches that change behaviour on Octane:** `DL_OCTANE_Y_OFFSET_WORKAROUND`, `DL_OCTANE_CONST_HUE`,
   `DL_MGV_FLIP_DOMINANCE`, `DL_HDCAM_OCTANE_OUTPUT_KEEP_GFX_GENLOCK`, `DL_OCTANE2_BIG_MESH_FIX`,
   `DL_OCTANE2_MESH_LAST_ADD`. Not required. E (strings).

**What it lists, opens and treats as failure**

| Step | Behaviour | Grade |
|---|---|---|
| Configuration | `init.cfg` line `Video <device>, <input>`: Smoke 5.0 ships `Video OctaneVideo, Serial1`; Flint 8.3.4 ships `Video OctaneVideo, DEFAULT, Serial1`. The device names the parser holds are `OCTANEVIDEO`, `XT-DIGVID`, `DIVO` and `NO_VIDEO`; `NO VIDEO` is the menu label | E |
| No device configured | `VideoInit` returns at once when the stored device type is unset (-1) and its second flag is clear | E |
| Connect | `Video::Video` calls `vlOpenVideo(NULL)`, then `vlGetNode(server, VL_DEVICE, 0, 0)` (`VL_DEVICE` is 3 in `vl.h`). Each failure logs `(file,function,line) error:  vlOpenVideo failed` or `vlGetNode failed` and the constructor still returns an object | E |
| No server | `SetupPath` begins by testing the connection and returns the stored error (-1) at once | E |
| Device list | `SetupPath` calls `vlGetDeviceList`, reads 48-byte `VLDevice` records (`vl.h`: device id, name, node count, node list pointer, private) and compares each name with the wanted name. The wanted name is **`impact`**: the `ImpactVideo` constructor copies it, and `OctaneVideo` inherits it | E |
| Name not found | `(...) warning:  Found no video device named "impact".  Using device named "<first>"` and the first device is used. An empty list was not traced | E (message and branch), U (empty list) |
| Open path | `vlCreatePath`, `vlAddNode`, `vlSetupPaths(server, path, 1, VL_SHARE, VL_SHARE)` (the stream and control usage arguments are both 2), `vlSelectEvents`, `vlBeginTransfer`; each failure logs `<call> failed` and the caller returns | E (call order and arguments from the listing), I (argument meaning) |
| "No video list" | the string does not occur in the three binaries. The nearest paths are the `NO_VIDEO` configuration and the `Found no video device` warning above | E (absence by string search) |

**Consequence for the model.** `videod` must list the device `impact` (always bound by `impact.so`) and the Digital Video
nodes must be reachable through it; a missing or failed `mgv.so` bind leaves the DL with a list that has no
`VL_VIDEO` or `VL_MEM` serial nodes, and it logs node-setup failures while the product keeps running. How `mgv.so` hangs
its nodes under the `impact` device (the `metaXDevInit` and `metaTrap*` imports of `impact.so` and `mgv.so`) was not
traced: I.

## 10. Start-up path: from the Discreet layer to the DCB registers

Pass 5. Companion table of every register access, bit by bit: [srv-register-map.md](srv-register-map.md). Grades as
above (E read in full, I reasoned, U unknown). Kernel objects are the 6.5.30 `impactvideo` overlay's `srv.a` and
`mgv.so`; the held Discreet guest disks carry **none of them** (10.1).

### 10.1 What the guests have today

The three installed guests (Smoke 5.0, Flame 7.6, Flint 8.3.4, all IRIX 6.5.21f on Octane) carry `videod`, `libvl`
(`dmedia/arch/videodvl`) and `libdmedia`, and in the kernel object set only `mgvstubs.a`. There is no
`/usr/lib32/dmedia/video` directory, no `impact.so`, `mgv.so` or `srv.a`, and no `/dev/mgv`. E (directory reads). So
today the video list is empty (10.10); a model needs the `impactdm` and `impactvideo` overlays installed first. Whether
the 6.5.30m overlays run on a 6.5.21f kernel is unknown (U); the original-6.5 Octane Digital Video image is the other
candidate and its `srv.a` differs in size and checksum.

### 10.2 The call chain

| Stage | What happens | Grade |
|---|---|---|
| 1. DL | `VideoInit` with device type `OCTANEVIDEO` calls `InitVideoOctane`; Smoke 5.0 and Flame 7.6 tail-call `VideoOctaneVideoOutput(1, 0)`, Flint 8.3.4 `InitVideoOctane(bool)` calls it | E |
| 2. DL | `VideoOctaneVideoOutput` builds an `OctaneVideo` (a `Video` with device name `impact`), converts the configured timing, sync, field dominance and format to VL values, sets up a `VL_SCREEN` source, a `VL_INTERNAL` colour-space node and a `VL_VIDEO` drain (`SetupSrcNode`, `SetupCscNode`, `SetupDrnNode` through the object's methods), sets controls (`vlSetControl`) and calls `vlSetupPaths(server, path, 1, VL_SHARE, VL_SHARE)`. `vlBeginTransfer` is not called here: `VideoOctaneStartOutput` and `VideoOctaneSetInput` do that later | E |
| 3. videod and `impact.so` | `vlSetupPaths` reaches the meta device `impact` (10.8), which routes to the `mgv` sub-device's `mgvSetupPath` | E (call), I (routing detail) |
| 4. `mgv.so` | `mgvSetupPath` allocates the path's resources and activates them. Each resource that changes runs its `MGV_SetParams_<resource>` through the resource manager's `RM_AddUser` (the call site is the resource record's SetParams slot). The 38 resource records, by resource type: Vin (3), Vout (3), Csc (1), Screen (6), Board (1), CC1Cbar (1), Trigger (1), VBAR (1), Tex (1), CC1 (1), Events (1), and 18 records with a no-op handler. Order inside a path follows the resource list index and the path's nodes; not traced further | E (records), I (order) |
| 5. ioctl | each `SetParams` issues the private ioctls of 10.3 on the `/dev/mgv` descriptor | E |
| 6. `srv` | the handler of each ioctl reads or writes DCB registers (10.4) | E |

### 10.3 Ioctl number to handler (every case of the driver's switch)

Read by running the driver's compare tree over each number `0x6d670001` to `0x6d670043` (E). A number not listed
reaches the default branch, which logs `srv_Private: Invalid ioctl` and returns 0. Command names in quotes are
the module's own strings; the others are the handler names.

| Number | Handler | Number | Handler |
|---|---|---|---|
| `01` | `srv_setreg` ("MGV_SETREG") | `1f` | `srvSetCtrl` -> `_srvMuxSel` |
| `02` | `srv_getreg` ("MGV_GETREG") | `20` | `srvGetMuxSel` |
| `03` | `srvSetWin` ("MGV_SETWIN") | `21` | `srvSetCtrl` -> `_srvGenCtl` |
| `04` | `srvGetWin` | `22` | `srvGetGenlockCtl` |
| `05` | `srvCC1PutFrame` | `23` | `srvSetCtrl` -> `_srvcc1Ctl` |
| `07` | `srvSetCtrl` -> `_srvClutCtl` | `24` | `srvGetcc1Ctl` ("MGV_GETCC1_CTL") |
| `08` | `srvGetClutCtl` ("MGV_GETCLUT_CTL") | `25` | `srv_force_reset` |
| `09` | `srvSetConfig` ("MGV_SET_CONFIG") | `26` | `srvSetTMICtl` |
| `0a` | `srvGetConfig` ("MGV_GET_CONFIG") | `27` | `srvGetTMICtl` ("MGV_GETTMI_CTL") |
| `0b` | `srvTriggerWait` | `28` | `srvVgi1DMA` |
| `0f` | `srvSetCtrl` -> `_srvDVinCtl` | `29`, `2a` | `srvVgi1Setup`, `srvVgi1UnSetup` |
| `10` | `srvGetDVinCtl` ("MGV_GETDIN_CTL") | `2b` | `srvTriggerSetup` |
| `11` | `srvSetCtrl` -> `srvEffectWrite` | `2c`, `2d` | `srv_vgi1_reg` (VGI1 register read and write) |
| `12` | `srvEffectRead` | `2e`, `2f`, `30` | `mgvTriggeredCtrlPost`, `Ready`, `Flush` |
| `13`, `14` | `srvSetPollSel`, `srvGetPollSel` | `32` to `3c` | diagnostics (`srvDiag*`, EDH) |
| `15` | `srvSetCtrl` -> `srvKeyerWrite` | `3d`, `3e` | `srvGetKsyncCtl`, `srvSetKsyncCtl` |
| `16` | `srvKeyerRead` | `3f` | `srvQueueEvent` |
| `17` | `srvSetCtrl` -> `srvYUVColor` | `1c`, `1d` | `srvGetAutowipe`, `srvSetAutowipe` |
| `18` | `srvSetCtrl` -> `srvLoadClut` | `1e` | `srvGetMSCandUST` |
| `19` | `srvReadClut` | `1b` | `srvGetDVoutCtl` ("MGV_GETDOUT_CTL") |
| `1a` | `srvSetCtrl` -> `_srvDVoutCtl` | | |

`srvSetCtrl` commands dispatch through a 29-entry jump table in `srvDoCtrlChange` (indexed by number minus `0x6d670007`; every other entry is the default). They copy in a 112-byte structure, then either apply it at once through
`srvDoCtrlChange` or enqueue it as a triggered control that a CC1 or VGI1 interrupt applies at a named field
(`mgvMSCTriggeredCtrlWakeup`, `mgvGPITriggeredCtrlWakeup`, `mgvInLineTriggeredCtrlWakeup`). Which path the first screen-to-video
set-up takes was not decided; the model should deliver the CC1 interrupt either way (10.7). I.

### 10.4 Register writes in order, per block

The full decoded sequences are in [srv-register-map.md](srv-register-map.md): the bit-id accessor with its 389-entry
table, the attach-time sequence (steps 0 to 15, with every default table value), and the program-order accesses of each
control handler above. Summary of what is established:

| Block | Attach-time writes | Start-up-time writes (handlers) |
|---|---|---|
| HQ4 DCB control (`+0x61000..0x61070`) | `1`, `0x4210`, `0x208a`, `0x1004`, and 0 at `+0x61010` for revision 1 | none |
| GAL direct (`+0x73400`) | 3 = 1, then 2 read | none outside reset |
| GAL indirect | crosspoint 240..255, DV in reg 2, DV out regs 8..13, genlock regs 14..16, 20, 21, 26, 39, cc1-io regs 5..7, 0 (detected input standard), 38 (reset), I2C regs 36 and 37 (only when the I2C workaround flag is set, 10.5) | DV in regs 2 to 4 (`_srvDVinCtl`), DV out regs 8 to 13, mux/genlock regs 33 to 35, 17 to 24 (timer) |
| CC direct (`+0x73000`) | 0, 3, 4 | 0 bit 0 (frame control), 4 |
| CC indirect | the 66-entry default table (38 = `0xa0`), 38 final `0xa2`, 40, 41 | 0, 1, 3, 9, 16, 32, 36, 38 (`_srvconfig`), 54 to 56 (CC1Cbar and window), others per `srvcc1Ctl` |
| AB direct and indirect (`+0x72800`) | direct 6 written `10`, `21`, `42`, `83` in turn; direct 5 from the board record; kind-2 indirect 0 = 4; kind-1 table 0..7, 16..23, 32..38 | AB 5, 6, 21, 22, 37, 38 around window enable and `_srvconfig` |
| CSC (`+0x73800`) | direct 2 = 1, delay 20, direct 2 = 0 | indirect 0 and 1 bits (`_srvClutCtl`) |
| TMI (via GAL 6/7) | GAL direct 3, 5, 6, 7 writes, 17 defaults at 0x80..0x95 and 18 at 0x60..0x71 (16-bit, through `MgrasWriteBfifo`), four 500 microsecond delays | none unless a texture node is used |
| EDH, ML (I2C, GAL 36 and 37) | part select and a sequence | none seen |

Values written at start-up come from the VL controls the DL layer set (timing, sync source, format, precision) through
`mgv.so`'s resource parameters: they are parameters, not constants, so a per-product value list was not produced. What
the three products differ in is below.

### 10.5 Read-backs, polls and waits that change the outcome

| Where | What is read | Exit or check | Effect on a RAM model | Grade |
|---|---|---|---|---|
| Probe | byte at `+0x70008` | must be `0x11` | required value | E |
| `_srv_reset` | GAL direct 2, TMI 147, CSC direct 3 | stored only; revision nibble below 4 clears the I2C workaround flag | any value | E |
| Init tables (`_gal_reg_check`) | read-back of each table entry | skipped on the attach path (diagnostic ioctl `0x6d670036` only) | none | E |
| `i2c_poll` (every I2C byte: EDH and ML parts) | GAL indirect 37 bit 7 | loop `us_delay(10)` until bit 7 clears or `srv_i2c_timeout` (1000) polls, then it writes `0xc3` to register 37 and returns -1 | **RAM fails**: `_srv_init_i2c` leaves register 37 = `0xc1` (bit 7 set), so each poll waits 10 ms and errors. `_srv_init_i2c` itself runs only while the I2C workaround flag is set, and `_srv_reset` clears the flag when the board revision byte's low nibble is below 4; a revision byte of `0x24` leaves it set. The result is ignored on the attach path, so it still attaches, slowly | E |
| `srv_itimer` (every `gal15itimeout` = 25 ticks, armed at attach) | GAL indirect 17 bit 0 and, if set, 17 & `0x50` until clear; 3, 4, 14, 15, 22 to 24; CC indirect 38 bit 7 | a RAM model reads 0 and idles. If bit 0 of 17 reads set and `0x50` never clears, the timer spins | return 0 for GAL 17 bits 0, 4 and 6 | E (flow), I (meanings) |
| `srv_field_wait` (window enable, `srvCC1PutFrame`) | CC indirect 38 bits 7 and 5 | if either is set: sleep on `srv_fieldwait_sv` for that many CC1 field interrupts; if both clear: spin `delay(1)` that many times | **interrupt required** (10.7); CC indirect 38 is `0xa2` after attach, so the wait is interrupt-driven | E |
| `_srv_enab_win`, `_srv_enableBC` | AB 37, 38, 22, 21, 6 bits and CC 54, 55 fields | each read is followed by a write that clears then restores the same bit around a field wait; no compare of the value | RAM satisfies | E |
| `_srvWaitForTMIXferStart`, `_srvWaitForVertLineCnt` | TMI and graphics line counter | texture transfers only | not on the path | E |
| `_srvWaitForFifo` (`srvCC1PutFrame`) | CC FIFO count | framebuffer put-frame only | not on the path | E |

### 10.6 Are plain write-through RAM arrays enough?

For the CC, AB, CSC, TMI and GAL blocks: **yes for storage and read-modify-write, no for four registers**, so a model
should be RAM plus these overrides (I for the overrides' exact bit meanings, E for the code that needs them):

1. GAL indirect 37 bit 7 (I2C busy) must read 0 so `i2c_poll` returns at once; otherwise start-up works but spends
   about 10 ms per I2C byte.
2. GAL indirect 17 bit 0 and bits 4 and 6 (`0x50`) must read 0 unless a field event is pending, so `srv_itimer` idles.
3. CC1 field interrupts (GIO line 6) must be delivered at the field rate once CC indirect 38 bits 5 or 7 are set, or
   every `srv_field_wait` blocks in `sv_wait_sig`.
4. The probe byte `0x11` at `+0x70008` and the three revision reads of `_srv_reset` (10.5).

No read-back compare of a written value was found on the attach path or in the handlers of 10.4. Not examined: the
handlers `srvEffectWrite`, `srvKeyerWrite`, `srvYUVColor` and `srvLoadClut` (`0x11`, `0x15`, `0x17`, `0x18`; their
register paths use the same accessor), `srv_edh.o`, and the VGI1 paths. U.

### 10.7 Interrupts and DMA the path waits for

CC1 field interrupts on GIO line 6 (`srv_cc1_interrupt` wakes `srv_fieldwait_sv`): needed by `_srv_enableBC` and
`_srv_enab_win` (reached from the `0x6d670003` window command, which `MGV_SetParams_CC1Cbar` sends for its window
parameters) and by triggered controls. No VGI1 DMA or line 4 interrupt is waited for by a screen-to-video path: the DMA
engine is used by the `VL_MEM` nodes, which this first path does not use. A model that never raises line 6 hangs
`vlSetupPaths` inside `videod` on the first window enable. E for the wait, I that the first path reaches it.

### 10.8 How `mgv.so` hangs its nodes under the device `impact`

`impact.so` is a **meta device**; `mgv.so` is one of its sub-devices. E from the code:

- `videod` loads `impact.so` and calls `impactBind`, which opens `/dev/mgv` (falling back to `/dev/null`) and calls
  `AddDevice`, which runs `__meta__AddDevice`.
- `__meta__AddDevice` opens the sub-device's file (`/dev/mgv`, with the message `__meta__AddDevice: can't open /dev/mgv:
  <error>` on failure), loads the sub-device DSO through `__meta__loadDSO`, runs the sub-device's init and its
  cross-device init, and on any failure prints `deviceInit fails` or `XDevInit fails` and skips that sub-device.
- `__meta__loadDSO` builds `/usr/lib32/dmedia/video%s/%s.so` (the `_VL_ROOT` variable prefixes `video`), `dlopen`s it,
  `dlsym`s `<name>DeviceInfo` and `<name>XDevInfo`, refuses a DSO whose version differs from `videod`'s
  (`is not the same version as videod`) or whose cross-device protocol is not version 4 (`have different cross-device
  protocols`).
- `mgv.so` exports `mgvDeviceInfo` (name `mgv`; its init callback runs `RM_Open`, 8.2) and `mgvXDevInfo` (protocol 4, six
  callbacks). `impact.so` runs `metaXDevInit` and `metaBuildFlowGraph` to merge the sub-device's nodes into the meta
  device's node list (`__meta__MergeDevice`), so a client sees one device `impact` with the `mgv` nodes inside. The
  `mgv` side calls back into the meta device for source queries (`metaQuerySource`, `metaFindDevPathNode`,
  `metaIsMetaNodeOnMetaPath`, `metaTrapSetupPaths`, `metaTrapSetConnection`, event notifiers).
- `videod` also loads `mgv.so` on its own (the transcript in section 3 shows both DSOs loading), through
  `mgvDeviceInfo`; that load needs the same `RM_Open` to succeed. I (whether the stand-alone load adds a second
  device or is merged away).

Consequence: with the `mgv` sub-device missing or failing, `impact` still lists but without the `VL_VIDEO` serial
nodes and the video-side `VL_MEM` nodes, so the DL's `SetupDrnNode (VL_VIDEO)` fails.

### 10.9 Flame 7.6 and Flint 8.3.4 against Smoke 5.0

Disassembled and compared function by function (call names, immediates, string references), addresses ignored:

- **Flame 7.6 against Smoke 5.0: identical** in `InitVideoOctane`, `VideoOctaneVideoOutput`, `VideoOctaneVideoInput`,
  `VideoOctaneStartOutput`, `VideoOctaneSetInput`, `VideoOctaneSetOutput`, `SetupSrcNode`, `SetupDrnNode`,
  `SetupExtNode`, `BeginTransfer` and the `Video` constructor. The only difference is a string constant in `SetupPath`.
  E.
- **Flint 8.3.4 differs in four ways, none in the VL skeleton:** `InitVideoOctane` takes a flag and calls
  `VideoOctaneVideoOutput` itself; timing comes from `VideoGetCurrentTiming` with `convertDLVideoTimingToVlTiming`
  (Smoke and Flame use `GetVideoStandard` with `convertDLVideoStandardToVlTiming`), which carries the HD timings;
  `VideoOctaneSetInput` also calls `VideoOctaneSetOutputDigitalFilterState` and `VideoOctaneVideoOutput(1)`;
  `SetupPath` takes a second argument. The device name, node kinds, `vlSetupPaths` arguments and the error strings are the
  same. E.
- **Same driver-side demands**: because the VL calls are the same, the `mgv.so` resources and ioctls of 10.2 to 10.4
  apply to all three. A different timing value changes register values, not the set of registers. I.

### 10.10 An empty VL device list

- `videod` with no usable DSO exits: the string `no devices found` and the public transcript `Fatal server error: no
  devices found` (a 1996 post). E (string), I (exit).
- In the DL layer: `vlOpenVideo(NULL)` returns no server, `Video::Video` logs `vlOpenVideo failed`, then `vlGetNode failed`,
  and returns an object anyway; `SetupPath` returns -1 at once. `VideoOctaneVideoOutput` then logs its node-setup
  failures and the product keeps running with no video. E (code), I (that the products start; the earlier guest runs
  with `Video OctaneVideo` configured and no board agree).
- With `videod` running and a list that has devices but none called `impact`, the DL warns and uses the first device (9).

### 10.11 What is still unknown

- The actual register values for each product's configuration (they are VL parameters); the `srvEffectWrite`, `srvKeyerWrite`,
  `srvYUVColor` and `srvLoadClut` handlers; whether `srvSetCtrl` applies at once or by trigger during the first path.
- The meaning of GAL indirect 17, 22 to 24 and CC indirect 54 to 56 beyond the roles their routine names give.
- Behaviour of `mgv.so`'s stand-alone load (10.8) and of 6.5.30m overlays on a 6.5.21f kernel (10.1).
- Settle by: a trace of an unmodified run once a model answers the 10.6 overrides; the `vl_mgv.h` header for parameter
  structures; reading `srv_edh.o` and the remaining `srvSetCtrl` cases.

## 11. VGI1 presence (`srv_gio_dma_init`)

Pass 6, from `srv_llvgi1_interface.o` of the 6.5.30 `srv.a`, read in full. `srv_attach` ends with `srv_gio_dma_init(board, 6)`
(through `srv_init_regs`); the board record's +152 holds the mapped slot-0 window ("giobase", 4 MiB, section 2.1) and +160 the
optional second window.

### 11.1 The identification register

| Fact | Value | Grade |
|---|---|---|
| Register | GIO_ID, a **64-bit** register at slot-0 window offset `0x00`, read with one 8-byte load (`ld`) | E |
| Test | `(value & 0x7f) == 0x11` (17), nothing else compared | E |
| Byte order | the guest is big-endian: the doubleword's bits 6:0 are in the **byte at offset 7**, and bits 31:0 are the 32-bit word at offset 4. A model returns bytes `00 00 00 00 00 00 RR 11` at offsets 0 to 7 (`RR` below). The giobr slot probe's 32-bit read at slot offset `+4` is the same register, so a model that already answers that read at `+4` but returns 0 for an 8-byte read at `+0` has implemented only the low word | E |
| Other bits | bits 15:8 are stored as the VGI1 revision (board record +44) and printed as `mgv_gio_dma_init: VGI1 rev 0x...`; the whole value is kept at +56 and printed as `GIO_ID` when the `showconfig` tunable is set. No other bit is tested; use `RR` = 0 or a plausible revision | E |
| Width | 8 bytes; a 4-byte-only device answers the `+4` word but fails this read | E |
| Failure | `srv_gio_dma_init: No VGI1 present` at warning level, the board record's VGI1 state pointer is cleared and the routine returns 2. The caller ignores the result, so the driver still attaches and `hinv` still prints | E |

### 11.2 Everything else the presence path does

In order, after the ID test, in `srv_gio_dma_init`:

| Step | Access | Required | Grade |
|---|---|---|---|
| 1 | read 8 bytes at `+0x20` (CHIP_ID) | none: stored at state +8; with `showconfig` printed as revision (bits 31:28), part (bits 27:12), manufacturer (bits 11:1). Return any value | E |
| 2 | **write** 8 bytes at `+0x10` (SYSMODE) | accept; the value is `((page-size code & 3) << 8) | 1`. The routine sets the kernel page size constant to 16 KiB and the code to 1, so the value is **`0x101`** | E |
| 3 | **write** 8 bytes of 0 at `+0x1000` (channel 1 register 0, the "setup" register; a state word that is 0 at this point picks channel 1) | accept | E |
| 4 | software only: `srv_dma_alloc_drbs` allocates the DMA request blocks; failure logs `Unable to allocate DRB memory`, releases them and fails | the guest's memory allocator | E |
| 5 | a counter of attached boards is incremented; a second board logs `only %d srv boards supported` | one board | E |

No poll, no wait, no interrupt and no further read is made. The second VGI1 is examined only when the tunable
`srv_ignore_2vgi1` is 0 (default 1): it then reads 8 bytes at the second window's offset 0 through `badaddr_val` (a fault means
absent), applies the same `& 0x7f == 0x11` test, prints `second VGI1 present` or `NOT present`, and repeats steps 1 to 3 on its
window; with the default it prints `second VGI1 present but ignored` only under `showconfig`. E.

Register layout that follows from the driver's own debug tables and address arithmetic: global registers at 8-byte
register index 0, 2 and 4 are GIO_ID, SYSMODE (`+0x10`) and CHIP_ID (`+0x20`); a channel register's **byte offset** is
`c * 0x1000 + (byte offset in the channel)`, with *c* = 1 or 2 (the driver builds it as `((c << 9) | r) << 3` with *r* the register **index**, the byte offset divided by 8). Channel 1 starts at `+0x1000` and channel 2 at `+0x2000`. E for the arithmetic, I for the names
beyond GIO_ID.

### 11.3 What depends on VGI1 being present

| Consumer | Without VGI1 | Grade |
|---|---|---|
| `hinv` line, `/hw/srv`, `VID_*` ioctls, `mgv.so` open and bind, the 24 nodes | unaffected: nothing on the open path tests VGI1 (the 24 nodes are static resource records, so `VL_MEM` nodes are listed though unusable) | E (open path), I (nodes) |
| `srvVgi1Setup`, `srvVgi1UnSetup`, `srvVgi1DMA` (`0x6d670028` to `2a`) | check the state pointer and return an error | E |
| `srv_vgi1_reg` (`0x2c`, `0x2d`), `srvGetMSCandUST` (`0x1e`), `srvTriggerSetup` (`0x2b`), `srv_force_reset` (`0x25`), frame-accurate triggered controls, the line-4 interrupt handler | dereference the cleared state pointer with no check: a **kernel fault** | E |
| `mgv.so` `mgvGetFrontierMSC` (`vlGetFrontierMSC`, and with it `vlGetUSTMSCPair` users) | issues `0x6d67001e`: the fault above | E |
| `VL_MEM` memory nodes: `mgvvgi1ManageTransfer` and the DMA descriptor machinery of 2.5 | cannot run | E |
| `srv_itimer` | checks the pointer; idles | E |

For the three products: the screen-to-video start-up path of section 10.2 uses neither DMA nor MSC reads (I), so
`vlSetupPaths` for it does not need VGI1 beyond the presence test. Their transfer code does (`VideoOctaneStartOutput`,
`VideoOctaneSetInput`, grab and put frame use `VL_MEM` nodes and the UST/MSC calls), in all three products because the
Discreet video layer is the same (section 10.9). So present VGI1 at least to the extent of 11.1 and 11.2 now; the register
file behind it (descriptor and channel registers, section 2.5) is needed before any frame transfer.

## 12. TMI indirect register 129: who polls it, and what makes the loop exit

Pass 6b. TMI indirect register 129 (`0x81`) is the TMI status register: the bit ids 259 to 263 of
[srv-register-map.md](srv-register-map.md) are its bits 0 to 4, read from hardware (index 129 written to GAL direct 6, `+0x73708`,
then one byte read from GAL direct 7, `+0x73788`, section 2.2). Read in full, in both the 6.5.30m `srv.a` and
the original-6.5 image's `srv.a`:

| Reader | Bit and use | Bound and exit | Reached from | Grade |
|---|---|---|---|---|
| `_srvWaitForTMIXferStart` | bit 1 (id 260): loop A waits until it reads 1; loop B then waits until it reads 0 | each iteration is one status read plus `us_delay(10)`; the shared bound is `2000 * gal15itimeout` iterations, **50,000** at the default of 25 (about 0.5 s). After a first loop that waits for a software flag to clear, loop A runs to the bound if bit 1 never rises; loop B likewise if it never falls. Success returns 1; a timeout returns 0 and the caller logs through `srv_add_log` and carries on (the timeout is not fatal) | a texture transfer start (`_srvStartTMITransferToTRAM`, `_srvChangeTMIBeginXferStatus`) | E |
| `_srvStartTMITransferToTRAM` | bits 0 and 1 (ids 259, 260), single reads after the wait | no loop of its own | `srvVidTextureXfer` (`MgrasVidTextureXfer`, the graphics driver's video-texture hook) | E |
| `srv_tmi_interrupt` | bit 0 (id 259), one read | none | the VGI1 line-4 interrupt handler | E |
| `srv_tmiind_update_timing` | bit 2 (id 261), one read | none | `_srvconfig` (SET_CONFIG), twice | E |

What this means:

1. **The attach and open paths do not poll TMI indirect 129.** `_srv_init_TMI` and `srvInitTMIRegs` (section 10.4, Step 11) only write; `_srv_reset` reads TMI
   indirect **147** once. A poll of 129 is therefore a texture-transfer start (a graphics client using video as texture, or the line-4 interrupt handler running) and
   the loop above is the only one with a bound near this size.
2. **What exits at once:** make TMI indirect 129 bit 1 read 1 on the first status read and 0 on the next (a start pulse seen by loop A, then loop B), and
   have the software flag it first waits on clear (it is zero unless a transfer is pending). Any value with bit 1 stuck at 0 spins loop A to its 50,000-iteration bound
   and returns the timeout; a value stuck at 1 passes loop A then spins loop B to the bound. With the default `gal15itimeout`, a stuck loop costs 50,000 reads and about
   0.5 s; two stuck loops 100,000 reads. A model that reads 0 always costs one bound per call.
3. **Where a count of 100,000 to 300,000 reads of one status register does arise on the attach path** is not TMI: it is `i2c_poll` on **GAL indirect 37**
   (section 10.5), which reads the I2C status up to 1000 times per poll call (`srv_i2c_timeout`) and is called once or twice per byte of the EDH and ML sequences, so a few hundred
   bytes give 100,000 to 300,000 reads when bit 7 never clears. If the guest trace shows the index port at `+0x73708` taking `0x81` before each read of `+0x73788` it is TMI 129; if it shows
   the GAL index port at `+0x73408` taking `0x25` and reads of `+0x73488` it is the I2C status, and the fix is GAL indirect 37 bit 7 reading 0 (section 10.6, override 1). I (the
   identification of the observed loop needs the raw trace addresses; this page cannot settle it from the binaries alone).

## 13. The graphics query behind "Unable to find IMPACT Graphics. Assuming board 0"

Pass 7, from the 6.5.30 `impact.so`, and the 6.5.30 `mgras.a` and `gfx.o` of the IP30 kernel (read by disassembly; the matched 6.5.13m overlays and a 6.5.21f kernel were not
disassembled, so the same logic there is I). Cross-checked against the IMPACT graphics workspace (jamesb/gr4) `devices/mgras/board-identity.md`.

### 13.1 Where the message comes from and what it asks

| Fact | Value | Grade |
|---|---|---|
| Printer | `impact.so`, the routine `_mgvManagedBy` (one routine of about 700 bytes at `0x40d930`, called while a meta device is added); the string is its `fprintf(stderr, ...)` | E |
| Device opened | `/dev/graphics` and `/dev/opengl`, each `open(..., O_RDWR|O_NONBLOCK)`, tried in turn according to a static flag (the flag starts so `/dev/opengl` is tried first; a failure falls back to the other); then `fcntl(fd, F_SETFD, FD_CLOEXEC)`. Both failing prints `_mgvManagedBy: (opengl) opened failed` and the routine returns 0 | E |
| Ioctl 101 (`GFX_GETNUM_BOARDS`, my name) | no argument; the return value is the board count. A count of 0 or less skips the search, so the message is printed with board 0 assumed | E |
| Ioctl 102 (`GFX_GETINFO`, my name) | argument `{int index; void *buf; int len}` (n32, 12 bytes), `len` = **204**, once per board index from 0 to count-1 | E |
| Fields read from the 204-byte reply | **+0**: NUL-terminated name, compared with `IMPACT`, then `IMPACTPC`, then `IMPACTSR` (any of the three matches); **+53**: one byte, must be **non-zero**; **+16**: a string searched for a `.` (`strrchr`), whose tail after the dot is `atoi`'d into a global (board number). An empty +16 is skipped | E |
| "Found" | a board whose name matches AND whose byte +53 is non-zero (the loop then breaks; with `_VL_DEBUG` set it prints `_mgvManagedBy: IMPACT gfx and video found`). A name match with byte +53 zero is **not** a hit and the loop continues. If every board fails, the message prints and board 0 is used | E |
| Ioctl 103 (`GFX_ATTACH`, my name) | argument `{int board; u32 value}`, `value` = `0x02000000`, sent for the found board (or 0 after the message). Failure prints `_mgvManagedBy:: gfx attach failed: <errno>` | E |
| Consequence of the message | the DL and VL keep running on board 0; the message is a missed match, not an error return | E |

So a reply that makes the search succeed is: count of at least 1; for the board, name `IMPACTSR` (the only name the 6.5.30 kernel sets) and byte +53 = 1.

### 13.2 Where the kernel gets the reply

| Step | What the kernel does | Grade |
|---|---|---|
| 101 | `gfxioctl` stores `GfxNumberOfBoards`, a counter that `GfxRegisterBoard` increments, once per HQ4 widget that attached (`mgras_attach` calls it) | E |
| 102 | `gfxioctl` copies in the 24-byte (kernel-width) argument, requires `index < GfxNumberOfBoards` and a non-null `GfxBoards[index]` (else error 19, ENODEV), and calls the board's function-table entry 0, **`MgrasInfo`** (`mgras_gfx_fncs[0]`) | E |
| `MgrasInfo` | calls `MgrasGatherDynamicInfo`, then `copyout`s `min(len, 204)` bytes of the per-board info record (the pointer at board +200) and returns the byte count | E |
| Info record | filled once at attach by `MgrasGatherInfo` (`mgras_init.o`): `bzero` of 204 bytes, then **name `IMPACTSR`** copied unconditionally into +0 (`strncpy`, 16 bytes), **204 stored at +36**, the HQ4 revision nibble at **+55**, and so on | E |
| Byte +53 | `1` when **bit 7 of the byte at HQ4 base `+0x71708` is clear** (the CMAP and RA revision byte), else 0. It is then cleared to 0 and byte +54 set if the multi-channel-option probe (`mgras_mco_probe`) finds a board, or if a flat-panel probe (`mgras_fp_probe`) does. Per gr4's `board-identity.md` that bit is "clear when a video option board is present" | E (code), I (the bit's meaning; gr4 grades it inferred) |
| Other reads on the same path | `+0x70008` read by `mgras_mco_probe` (a video board's `0x11` has high nibble 1, not the nibble 4 the probe accepts, so it is "absent", correct); the HQ4 word at base `+0x0` bits 31:28 (revision; 1 prints a prototype rev-A warning and continues); the HQ FIFO status at `+0x20100` polled until its low five bits are 12 or below; the board-version words at `+0x72408` and `+0x72488` (gr4 `board-identity.md` rows 2 and 3); stores of `0x108d` and `0x765b900f` at `+0x1000` and `+0x1008` (the DCB set-up) | E |
| 103 | `gfxioctl` copies in `{board, value}`, requires `GfxBoards[board]` non-null and the caller not already attached (error 16), then calls function-table entry 1, **`MgrasAttach`**, which returns 22 (EINVAL) unless `value & 0x3fff` is 0 (so `0x02000000` passes) and then only maps and records, with no register access | E |

What the QEMU MGRAS model must therefore present: at least one registered graphics board whose HQ4 window answers **bit 7 of `+0x71708` clear**, with the ordinary graphics ID reads the existing model already gives (the kernel computes the name and the 204-byte record itself, so no register holds "IMPACTSR"). The board count comes from the kernel's registration, not a register. If `hinv` already shows the graphics board, the likely cause is bit 7 of `+0x71708` reading 1 (a graphics-only configuration): that byte is the entire difference between "graphics only" and "graphics and video option present" for this query. The same byte makes the multi-channel option probe's `+0x70008` read matter, so the video board's `0x11` at `+0x70008` must not be disturbed by the graphics model.

## 14. VGI1 channel registers for playback

Pass 7b, from `srv_llvgi1_interface.o`, `srv_llvgi1_interrupt.o`, `srv_llvgi1_lib.o` and `srv_llvgi1_drb.o` of the 6.5.30 `srv.a` (read in full). Byte offset in the slot window = `c * 0x1000 + (byte offset in the channel)`, *c* = 1 or 2, using the byte offsets in the table below (the driver computes it as `((c << 9) | r) << 3` from the register index *r*, which is the byte offset divided by 8; the `Slot` column is that index, not a further multiplier). Channel 1 is at `+0x1000` and channel 2 at `+0x2000`; all accesses are 8-byte (`ld`/`sd`). Names are the driver's own debug strings (section 2.2); offsets come from its register table; roles are I unless stated.

### 14.1 Channel register map

| Offset in channel | Slot | Name | Role | Written by | Grade |
|---|---|---|---|---|---|
| `+0x000` | 0 | setup | channel configuration: pixel format, direction, mode bits; a software shadow holds it (the driver never reads it back) | `srv_dma_setup`, once per transfer set-up, value from the per-channel setup word | E (write), I (fields) |
| `+0x010` | 2 | intenab | interrupt enable; shadowed | `0x10` at abort (`srv_dma_abort_chan`) and in `srv_gio_dma_init`; at set-up the status-clear value ORed with `0x10` | E |
| `+0x020` | 4 | hparam | horizontal parameters (active pixels, per `srv_dma_h_params`) | `srv_dma_h_params` | E (reg), I (fields) |
| `+0x030` | 6 | vparam | vertical parameters (`srv_dma_v_params`) | `srv_dma_v_params` | E (reg), I (fields) |
| `+0x040` | 8 | stride | line stride in bytes (a 16-bit value from the request, `lhu +20`) | `srv_dma_setup` | E (write), I (units) |
| `+0x100` | 0x20 | debug | debug register | not touched on the playback path | U |
| `+0x200` | 0x40 | trig | trigger: `1` arms (`srv_dma_enable_trig`), `2` then `0` aborts a pending trigger (`srv_dma_trig_abort`, the `2`-then-`0` pair seen at `0x1200` and `0x2200`), `0` disables (`srv_dma_disable_trig`). Written on both channels when the channels are paired | `lib` | E |
| `+0x210` | 0x42 | dataaddr | 32-bit start offset of the transfer within its first page, from the request block | `srv_dma_start_dma` | E (write), I (meaning) |
| `+0x220` | 0x44 | descaddr | GIO address of the descriptor page in bits 39:0, with flag bits above (bit 48 set in one mode); written last, after dataaddr | `srv_dma_start_dma` | E (write), I (flags) |
| `+0x300` | 0x60 | status | interrupt and event status, read by the handler and **cleared by writing the read value back**; bit 4 is cleared by an explicit read-modify-write at abort; also written at set-up with the mask the driver is about to enable | handler, `srv_dma_abort_chan`, `srv_dma_setup` | E (access), I (clear-on-write) |

### 14.2 Sequences, in order

| Operation | Accesses to a channel | Grade |
|---|---|---|
| **Initial abort** (`srv_gio_dma_init`, once per channel, both channels attempted) | write `0x10` to intenab (`+0x1010`, `+0x2010`); trigger abort: write `2` then `0` to trig (`+0x1200`, `+0x2200`); read status (`+0x1300`, `+0x2300`), clear bit 4, write it back | E |
| **Set-up for playback** (`srv_dma_setup`) | write setup (`+0x000`); write stride (`+0x040`); write status (`+0x300`) with the interrupt-mask value (`0x2f0b`, or `0x211` for channel types 2 and 4); write intenab (`+0x010`) with that value ORed with `0x10` | E |
| **Transfer start** (`srv_dma_req` queues the request, `srv_dma_start_dma` issues it) | write dataaddr (`+0x210`), then descaddr (`+0x220`); then `srv_dma_enable_trig` writes trig = 1 when the transfer is triggered rather than free-running. The descriptor is a page of 8-byte entries in guest memory (16 KiB pages, one entry per page with the page's GIO address and flag bits; the exact bit layout is not decoded, U) that the chip reads by DMA | E (order), U (descriptor bits) |
| **Next descriptor** (`srv_dma_next_dma`) | the same two writes, dataaddr then descaddr, for the next request of the same channel | E |
| **Abort** (`srv_dma_abort_chan`) | trig abort pair, intenab = `0x10`, status read-modify-write clearing bit 4 | E |
| **Poll** | nothing is polled in a loop on the channel registers; every status read is inside the interrupt handler | E |

### 14.3 Interrupt and completion

| Item | Behaviour | Grade |
|---|---|---|
| Line | the DMA interrupt is GIO line 4 (`srv_dma_interrupt`); line 6 is the CC1 field interrupt of section 10.7 | E |
| Handler | reads status of **both** channels, masks to 14 bits, ignores bit 5 for logging, passes each channel's status to `srv_dma_drb_intrs`, then writes each status value back (clear) | E |
| Status bits | bit 0: field or frame pulse, updates the UST/MSC timestamp pair (`srv_dma_do_mscust`) and runs timed controls; bit 1: descriptor consumed, driver starts the next request (`srv_dma_next_dma`); bit 3: request complete, the driver moves the request block to the completion queue and calls the per-block callback (`srv_dma_drb_to_compqueue`); bit 4: trigger event, handed to the TMI handler when the board is in TMI mode; **bits 15:8: error**, the driver disables the trigger and calls `srv_dma_post_errors` (callbacks to `mgv.so` as a transfer error event); bit 2: routed to rate handling (`_srv_vgi1_sw_rate`, `_srv_vgi1_init_rate`), role not decoded | E (routing), I (names) |
| What a transfer needs to complete | a status of bit 3 (and bit 0 each field for the clock), then the line-4 interrupt; `intenab` bit set for what is raised. No further register read is required: completion is the interrupt plus the written-back status | E |
| Missed-interrupt timer | with a transfer active the 25-tick timer (section 2.4) force-resets the chip if no interrupt arrives for about 2 seconds, so a model that completes nothing resets the board | E |
| Not decoded | the descriptor entry bit layout; the `dataaddr` units; the `setup` field layout; `hparam`/`vparam` fields; what bits 2 and 5 mean | U |

## 15. Exercising the transfer path from Smoke 5.0

Pass 8. Reading of the Smoke 5.0 `smoke_IRIX_6.5_ip30` product binary (call graph from its DL video functions) and the shipped `init.cfg`; the menu paths come from the Autodesk Smoke 2007 user guide held in the Library mirror (no Smoke 5.0 guide was found in the Library mirror, so the paths are I: later release, same menus). Nothing here was run.

| Item | Finding | Grade |
|---|---|---|
| What startup already does | `VideoInit` with `Video OctaneVideo` runs `VideoOctaneVideoOutput(1, 0)`: it builds the screen-to-video path only, which is why srv initialises both channels and programs no transfer. `vlBeginTransfer` is not reached there | E |
| What reaches `vlBeginTransfer` | `VideoOctaneSetInput`, `VideoOctaneStartOutput` and `Video::BeginTransfer`. Their callers are `VideoSetInput`/`VideoSetOutput`/`VideoGrabFrame` and the VTR layer (`VtrStart`, `VtrOutputClipDivo`, `VtrNextFrame`, `VtrVideoIdleCB`, `VtrEndInput`, `VtrEndOutput`), the digital-disk-recorder layer (`DdrStartCommon`, `DdrEnd`) and Paint's frame-grab set-up (`PaintSetLibraryFileInit` calls `VideoGrabFrameStart`). So **clip input and output through the VTR layer is the path** | E (call graph) |
| Prerequisite: a VTR line | the `Vtr` keyword in `init.cfg` must be uncommented. The shipped file has all `Vtr` lines commented out. The one that needs no tape machine is the last, `Vtr none, Live video, SERIAL1, HOUSE, SERIAL1, HOUSE, /dev/tty4d1, AUTO, -3, 0, 0.50, 1.00, 0.00, 0.00, 8, vtrcueing`; its serial device is not used for control. The line already present, `Video OctaneVideo, Serial1`, selects the board and its input; `Sync House` selects the sync | E (file), I (the `none` line needs no serial device: the guide says Live Video is for devices without RS-422 control) |
| Output | EditDesk: enter a clip library, select a clip, click **Output Clip** (or SHIFT+F9 on the EditDesk); in the Output Clip menu set the **VTR Device / Device Name** box to **Live Video** (Start and Stop mode then fix to Start On Pen and Stop On Pen); enable the video tracks; click **Process**; after a moment the application asks to click anywhere to start; click, and click again to stop. This starts the video-out transfer (`VtrOutputClipDivo` and the frame loop) | I (2007 guide), E (the functions exist in 5.0) |
| Input (record) | enter the destination clip library, click **Input Clip** (F9), set the VTR Device box to **Live Video**, name the clip and enable the tracks, click **Process**, click anywhere to start and again to stop (capture also stops when the framestore is full). This starts the capture transfer (`vtr_input_clip_error`, `VideoSetInput`) | I |
| Project format | the project's video standard and frame size must be one the board supports in the non-square-pixel serial digital modes (the Programmer's Guide says the serial I/O produces valid output only in CCIR non-square pixel mode); the `Sync` and `Video` lines set the timing | I |
| Not this path | the **Preview** and playback to the broadcast monitor use the screen-to-video path already set up at start; the DDR device lines in `init.cfg` (`Audiodevice`, and external disk recorders) are serial-controlled devices, not the board | I |
| What this does to the model | a Live Video output start makes srv program a channel, and the first `Process` is where the descriptor, trigger and line-4 interrupt behaviour of section 14 first matter | I |

## 16. Why srv aborts after each request, and the CSC control failure

Pass 9, from `srv_llvgi1_interrupt.o` (`srv_dma_interrupt`, `srv_dma_drb_intrs`, `srv_interrupt_check`, `srv_interrupt_check_loop`, `srv_dma_do_mscust`, `srv_dma_next_dma`), `srv_clut.o`, `srv_hq4_dma.o`, and `mgv.so`/Smoke 5.0 for the CSC control (6.5.30 build; read by disassembly). The evidence trace (`vgi1-dma/`, 20261118) was read: it shows set-up and then only status polls (`0x1`, then `0x0`) with no `bit 5`, no `bit 3`, and none of the field-count bits below, so it does not itself show the failure; the cause below is from the driver code. Grades: E read in full, I reasoned, U unknown.

### 16.1 Status register fields the driver consumes (beyond the low bits of section 14)

| Bits of the 64-bit status | Use | Grade |
|---|---|---|
| 0 | vertical (field) pulse | E |
| 1 | descriptor boundary: start the next request (`DB_DN ... do next`) | E |
| 2 | rate/timing event, not decoded | U |
| 3 | end of DMA (`E_DMA`): completion of the request in flight | E |
| 4 | trigger event (handed to the TMI handler) | E |
| **5** | **start-of-frame marker: must accompany the vertical that begins a request** (16.2). Masked out of the interrupt log, but the sequence check depends on it | E (use), I (meaning) |
| 15:8 | error bits: any set takes the error path of 16.3 | E |
| 26:16 | line counter at the event (read by `srv_dma_do_mscust`) | E (use), I (name) |
| **32** | **field parity**: used (as `status << 31 < 0`) to pick the field in `_srv_vgi1_sw_rate`, `_srv_vgi1_init_rate` and in the field-order bookkeeping | E (use), I (name) |
| **47:33** | **free-running field counter** (15 bits): `srv_dma_do_mscust` takes the difference from the previous value to count fields and compute the MSC | E |

A status register that returns only the low bits gives the driver a constant field counter and parity.

### 16.2 The event-sequence check (this is what decides abort)

`srv_interrupt_check` takes `status & 0x2b` (bits 0, 1, 3, 5) and runs `srv_interrupt_check_loop`, a small state machine with two software counters per channel: C (starts seen, `pcc+472`) and F (DMA in flight, `pcc+476`). It returns "error" (1) or "ok" (0). I executed the routine's instructions over every combination of those bits (with `srv_ignore_vgi1_warning` at its default 1, so no messages print). The result, with s the status low bits:

| Event | When it is legal | Effect |
|---|---|---|
| vertical + start marker (`0x21`, or `0x23`) | any time | C = C + 1 |
| vertical alone (`0x01`) | F = 0 | if C ≥ 1 then F = 1 (the request is now in flight); a vertical while F = 1 is an **error** ("missing end-of-DMA") |
| end of DMA (`0x08`, `0x0a`, `0x28`), **not** coincident with a vertical | F = 1 (or C ≥ 1) | C = C − 1, F = 0 |
| end of DMA with C = 0 and F = 0 | never | **error** (end-of-DMA with no start seen) |
| end of DMA coincident with a vertical (`0x09`, `0x0b`) while F = 1 | never | **error** |
| any interrupt with F = 1 that carries no end-of-DMA bit | never | **error** |
| bit 1 alone (`0x02`) while F = 1 | never | **error**; with F = 0 it is ignored |

So per request the channel must produce, in this order: a vertical carrying bit 5; a plain vertical; then a **separate** end-of-DMA interrupt before the next vertical. A model that signals start with bit 1 and completion with bit 3 but never sets bit 5 leaves C at 0, and the end of DMA then hits "end-of-DMA with C = 0": error. A model that raises bit 3 together with the next vertical hits the coincident case: error. Either gives exactly an abort after every request. E (code), I (the C and F names).

### 16.3 What an error does (the abort and requeue)

In order, in `srv_interrupt_check` and then `srv_dma_drb_intrs`:

1. `srv_dma_trig_abort`: write `2` then `0` to trig on this channel and its paired channel.
2. `status |= 0x8000` (a synthetic error bit) and the channel state word gets `0x80000`; `srv_dma_next_dma` returns at once while that state bit is set, so nothing is requeued until recovery clears it.
3. Because bits 15:8 are now set: `srv_dma_disable_trig` (trig = 0); if bit 8 is set, read the debug register (`+0x100`) into the channel (`pcc+104`); save intenab, then write intenab = `0x11` and status = `0x2f0b` (clear all) to this channel and the paired one; clear the counters (C, F and the outstanding-request count); mark error recovery; `srv_dma_post_errors` calls the channel's error callback (a transfer-error event to `mgv.so`).
4. On the next event without bit 5 ("Error Recovered"): restore intenab from the saved value, clear the recovery flag, and if the channel was running, "Error Restart": zero the request's counts and set the channel's request-pending state so the same request is issued again on the next start.

That sequence, repeated per request, is the observed "abort and requeue". E.

### 16.4 What a correct completion looks like

| Step | Register-level behaviour | Grade |
|---|---|---|
| Queue | driver writes dataaddr, descaddr (and trig = 1 if triggered); no readback | E |
| Start | on the next vertical: status `0x21` (bits 0 and 5), plus bit 1 as the descriptor boundary if the model has one; the driver reads status, writes the read value back to clear, and starts the next descriptor request on bit 1 | E (0x21), I (bit 1 timing) |
| In flight | next vertical: status `0x01` | E |
| End | a separate interrupt with status `0x08` (end of DMA) before the following vertical | E |
| Request retired | `srv_dma_drb_intrs` counts end-of-DMA events in the request (`+40`); the request completes when that count equals its required count (`+112`; 0 means "complete at first end-of-DMA") and, in count mode (channel state bit `0x80`), moves to the completion queue and calls the buffer callback | E (flow), I (field meanings) |
| Field counter | bits 47:33 advance by one per field and parity (bit 32) alternates; the MSC step treats a jump of 2 or more as a missed field and does a trig abort with synthetic status `0x4000` (also an error path) | E |
| Watchdog | about 2 s without an interrupt during a transfer force-resets the chip (section 2.4) | E |
| Readbacks | status (both channels) every interrupt; GAL indirect 25 bit 0 on the trigger-mode path; the debug register only after an error | E |

### 16.5 What ends a Process after about 1300 requests

Not determined. No comparison against a count of that size exists in the VGI1 driver (`srv_llvgi1_*`, `srv_vgi1_dma`); the driver has per-channel counters (starts, completions, outstanding) with no limit. The candidates left are in the user-space layer: Smoke's output loop (`VtrOutputClipDivo` and `ImpactVideoOut::WaitNextFrame`, which logs `failed due to event: <name>` when a video event other than a frame arrives, E for the string) counting frames or giving up on repeated transfer-error events (`srv_dma_post_errors` raises one per abort), or the clip length itself (the evidence clip's last frame is 300). With the abort loop fixed the count may stop mattering; if it still ends at 1300, log the number of `srv_dma_post_errors` calls: a match means an error counter. U.

### 16.6 `vlSetControl failed (CSC)`

| Fact | Value | Grade |
|---|---|---|
| Caller | Smoke 5.0 `OctaneVideo::SetCSCControls` sets, in this order, the controls `csc_in_packing` (`0x4d470052`), `csc_out_packing` (`0x53`), `csc_in_range` (`0x50`), `csc_out_range` (`0x51`), `csc_const_hue` (`0x54`), `csc_alpha_correction` (`0x55`) and optionally `csc_output_filter_disable` (`0x60`). Each failure prints the same text, prefixed with the file, function **and source line**: **373** in_packing, **377** out_packing, **381** in_range, **385** out_range, **389** const_hue, **393** alpha_correction. The line number in the Smoke log names the control | E |
| Values Smoke passes | packings: `convertDLFrameFormatToVLPacking` returns the constant **55** (`VL_PACKING_444_8`, 3-byte RGB) for both; ranges: `convertDLColorSpaceFormatToVLValue` returns 4, 10, 1 or 2 depending on the colour space (601 or 709, set by `ipGetColorspace`), -1 when it has no match; const hue and alpha correction are 0 or a mode flag | E |
| What `mgv.so` does | `MGV_SetParams_Csc` copies the parameters into a request and sends two private ioctls, `0x6d670018` (load colour-space tables) and `0x6d670007` (set the CSC bits). It has **no** numeric range test of its own: if either ioctl returns negative it marks every parameter of the request as failed (state 3). The control table gives defaults only (in/out range default 4 `yuv_ccir`, packing default `rgba_8`), with no minimum or maximum | E |
| What `srv` does | `_srvClutCtl` writes each field through the single-bit accessor (masks, no error); `srvGetClutArgs` fails with EFAULT on a bad copy or returns 1 when the coefficient flag is set. The only ioctl failure source on a normal start is the **table load**: `_srv_csc_load` calls `_srv_csc_hq4_tdma`, which sets up a graphics-board DMA of the 1024-byte tables (`srv_hq4_setup_vdma`) and `_srv_hq4_wait_dma` polls an HQ4 busy bit (bit 12 of an HQ4 register in the `+0x2xxxx` window) up to 200 times at about 500 ns, then aborts the transfer by setting bit 1 of the HQ4 control word at `+0x81010`, logs, and returns an error | E (flow), U (the exact HQ4 register offset of the busy bit) |
| Does a model register feed the check? | **Yes, indirectly**: a CSC table load needs the MGRAS (HQ4) model to complete the video-to-texture DMA: the busy bit must clear within about 100 microseconds of polling. The range message itself ("out of range") is a VL-layer error text; the srv handlers contain no range compare, so which of `videod`'s validation or the HQ4 failure raised it is **not settled** from the binaries. The Smoke log's line number (16.6, first row) and a count of `_srv_hq4_wait_dma` timeouts in the kernel log settle it | I |

## Not done in this pass

- Ghidra was not used; objdump and a small address-resolution script only. No whole-function decompile of the DMA or
  interrupt routines.
- The Indigo2 `mgv.a`, the `octane_ic` compression image, the `srv_i2c.o` and `srv_edh.o` routines were not read.
- The DL layer was read for device selection, node setup and the start-up call chain, not for its video-timing and transfer
  code; Flame 7.6 and Flint 8.3.4 were compared with Smoke 5.0 by disassembly of the video functions (section 10.9). Flame 7.0
  and Smoke 4.0.3 not read.
- The programmer's-guide headers `vl_mgv.h` and `vl_impact.h` are not held, so the `0x6d67....` ioctl structures are not
  decoded.
- No `hinv -mv` capture with a widget location for this board was found.
