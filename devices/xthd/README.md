# XT-HD (XT-DIGVID): the present, enumerates, opens, passes-start-up contract

Status: **scoping draft, not independently reviewed.** It answers one question: what must a model of the SGI XIO digital
video option supply so that unmodified IRIX 6.5 software and the Discreet products of 2007 and 2008 see the board, list
it, open it and get through product start-up. It is not a register manual; every register is in the [DM2 pages](../dm2/README.md)
and is only referenced here. No physical board was used.

Grades follow [AGENTS.md](../../AGENTS.md) with two additions that the sibling [DIVO page](../divo/README.md) also uses. **E**
established: a whole routine, table or document passage was read; this is the "software expectation" grade when the source is a
shipped binary. **I** inferred. **U** unknown. **O** observed: seen in a guest run or an installed guest disk (a model run shows
what the guest asks for, never what hardware does). **A** approximation: a stand-in a model author must choose; not a hardware fact.

## 0. The answer in one paragraph

"XT-HD", "XTHD" and "XT-DIGVID" are not three products for this purpose. The board is the DMediaPro DM2 (Octane2) and DM3
(Onyx 350, Onyx 3000 family and Tezro), one XIO card with one IRIX driver; its inventory name is `XT-DIGVID` and `xthd` is the
driver's internal prefix (section 1). What Discreet calls `XTHD` in its video layer is a different code path that talks Video
Library, not OpenML, and does not open this board (section 6). The guest-visible chain is short: a widget with part `0xc102`
and manufacturer 682 and a one-wire ID text naming `XT-DIGVID` makes the stock driver attach; the `ioconfig` step gives it a
unit number; `mldaemon` finds `/hw/video/xt-digvid/<n>`, loads the eight FPGAs through the board and registers the ML device
`xt-digvid`; Discreet's video layer then matches that name. What a model must add to get through Flame 9.0's start-up is the
VBOB control channel and a reference lock, not pixel processing (section 8). The registers behind each step are already
graded in the DM2 pages; the delta this page adds is the naming resolution, the machine fit, the node and enumeration
sequence, the Discreet selection logic and the observed start-up.

## Sources

| Tag | Source | Used for |
|---|---|---|
| K | SGI "DMediaPro DM2 and DM3 Software 1.1.3ml" CD set, product `ml_xtdigvid`: kernel object `usr/cpu/sysgen/IP30boot/xtdigvid.o` (sha256 `952c3d9e…275d772b`), the IP27 and IP35 objects for constants, and the `var/sysgen` configuration files. Disassembled with the MIPS64 `objdump` (binutils) from the build container; Capstone-based call lists from the repository's `hostfacts` tool. Ghidra was not run for this page | attach order, node names, inventory call, ioconfig, unit number |
| L | Same set: `usr/lib32/mlmodule/libdigvid.so` (`aacf8d4a…b95bc2ca`), `libML.so.1` (`19c056d1…842ca9b8`), `usr/sbin/mldaemon` (`b46a10ae…523062bb`), `usr/bin/mlquery` (`4e48e215…fc196348`), the `.idb` manifests of `ml`, `ml_xtdigvid` and `vbob`, `usr/include/ML` (names only) | enumeration, daemon, inventory text |
| D | Discreet Flame 9.0 for IRIX, product `DLviodso16`: `libDlVideo.so` (`a37b48ce…310bfaeb`), `libDlVideoMl.so` (`71b49bd0…acfbaa43`), `libDlVideoDeviceMl.so` (`7e512d64…29546a51`), `libDlVideoDeviceXthd.so` (`2acbc178…3ad6a192`), unpacked from the installer image into scratch and read with the same tools. No licence or key material was opened | device selection |
| G | SGI *DMediaPro DM2 and DM3 Board Owner's Guide* 007-4317-001 (printed p. xiii); *DMediaPro DM3 Board User's Guide* 007-4647-001 (printed p. xiii); *HD I/O Option Owner's Guide* 007-3968-002 (printed p. xiii) | machines, IRIX release, which layer drives which board |
| O | A licensed-to-working pass of Flame 9.0 and 7.6 on an Octane2 V12 model with an XT-DIGVID model fitted: guest `hinv`, `mlquery`, `versions` and the application log, excerpts only | what the guest does end to end |

## 1. Identity: one board, three names

| Fact | Value | Grade |
|---|---|---|
| Inventory name | `XT-DIGVID Multi-standard Digital Video: controller 0, unit 0, version 0x0` in `hinv` and `mlquery -i` on a guest with the package installed; inventory class 12, type 14 | E (format string in `mlquery`, class and type from the driver and `ioconfig`), O (the guest line) |
| `xthd` is the same driver | the kernel object names its own data `xthd_...`, its assertions `XTHD_MAGIC1`, `XTHD_VERTEX_TYPE_BOARD` and `XTHD_VIDEO_DMA_DEPTH`, the ioctl set `XTHD_IOCTL_*`, and one message says "can't find video/xt-hd path" while the path it registers is `video/xt-digvid`. The shipped `system` file for the module reads "xthd -> XIO-based systems only" | E (strings and file text) |
| What "HD" refers to | the board does uncompressed HD and SD video. Why the driver kept the older `xthd` prefix is not stated by any shipped file | U |
| Ordering of names | `xtdigvid` is the module, hwgraph and ML name; `xthd` only appears inside the object. A model needs only `XT-DIGVID` | E |
| Discreet's `XTHD` keyword | a different device type with its own library; see section 6 | E |
| DM2 | for Octane2 V10 and V12; IRIX 6.5.11 or later; installed by the user in the Octane2 (guide chapter 2) | E (G, 007-4317-001) |
| DM3 | for Onyx 350 dual-head and Tezro (deskside and rackmount), installed by an SGI engineer; IRIX 6.5.21 or later. The earlier guide pairs DM2 with Octane2 and DM3 with Onyx 3000 and Origin 3000 | E (G, both guides) |
| Board assembly | `030-1653-002` (rev G, H) on Octane2; `030-1927-003` in two Tezro captures. Whether the Tezro assembly is the DM3 or a later DM2 is not decided; the driver treats every middle group other than 1653 alike | O (captures, [DM2 page](../dm2/README.md) section 1), U (which is DM3) |
| Slot | XIO widget 10 on Octane2 (graphics at 11, the fibre channel board at 9), widget 13 in the Tezro captures | O |
| Bus attach | a Crosstalk widget; `xwidget_driver_register(0xc102, 682, "xtdigvid_", 0)`, identical constants in the IP27, IP30 and IP35 objects, so one driver covers Octane2, Origin 3000-family and Onyx 350 and Tezro | E |
| VBOB | the board has no connector for video; two LVDS cables go to the Video Breakout Box, which has the SDI, analogue and genlock connectors | E (G) |

## 2. The install image and the driver

Three SGI inst products carry the stack. All are needed; Flame 9.0's own media ships none of them (O: on a 9.0 guest without
them `Video XT-DIGVID` ends in "No video list", section 6).

| Product | Subsystems | Carries | Grade |
|---|---|---|---|
| `ml` | `ml.sw.eoe`, `ml.sw.dev`, `ml.sw.diags`, `ml.sw.examples`, `ml.sw64.eoe`, `ml.man.*` | `libML`, `libMLU`, `mldaemon`, `mlquery`, `/etc/init.d/mldaemon` and its `/etc/config/mldaemon` flag (shipped `on`), headers. Listed as "ML 1.1 for IRIX 6.5, based on OpenML Media Library 1.0" | E (manifest), O (version line) |
| `ml_xtdigvid` | `ml_xtdigvid.sw.eoe` (63 entries), `.sw.diags` (25), `.sw.examples`, `.man.*` | the kernel objects `usr/cpu/sysgen/IP27boot`, `IP30boot` and `IP35boot/xtdigvid.o`, the ML module `usr/lib32/mlmodule/libdigvid.so`, `var/sysgen/{ioconfig,master.d,mtune,system}/xtdigvid`, the `usr/dmedia/ucode/xtdigvid/*.mcs` FPGA files, the `xtdigvid_hinv` and `xtdigvid_confidence` scripts. Listed as "DMediaPro DM2/DM3 ML Execution Environment, 1.1.3ml" | E, O |
| `vbob` | `vbob.sw.eoe` (33), `vbob.sw.flash` | the VBOB configuration tools and the box's firmware set. Listed as "VBOB Execution Environment, 1.3.1" | E, O |

Sysgen wiring (E, the shipped text): `master.d` flags `ocsn`, prefix `xtdigvid_`, no soft dependencies; the `system` file contains
`USE: xtdigvid`; the `ioconfig` line is `12 14 -1 -1 xtdigvid 0 0x6d687767`, meaning inventory class `INV_VIDEO`, type
`INV_VIDEO_XTDIGVID`, controller -1, pattern `xtdigvid`, first unit 0, ioctl number `'mhwg'`. The kernel object is not part of the IRIX
base; a guest without the product has no driver and no `/hw/video/xt-digvid`.

Discreet's own 7.6 OCT2 media ships an older build of the same driver and module (module stamp 2001-12-14 against SGI's 2003-10-15,
dmSDK names instead of OpenML names); the comparison lives in the stonewire repository's DM2 note and is not repeated here. Which
Discreet releases use the older module and which use SGI's `ml` stack is section 6.

## 3. Probe: what the driver reads at attach

Everything below is in `xtdigvid_attach` and `xtdigvid_init_board` of the IP30 object; the register meanings are in
[gif-registers.md](../dm2/gif-registers.md) and [fpga-load.md](../dm2/fpga-load.md) section 11. Only the rows that change the outcome are
listed. "Free" means the code stores or reads the value but no branch depends on it.

| Step | Access | Required | If not | Grade |
|---|---|---|---|---|
| 1 | widget ID: part `0xc102`, manufacturer 682 | the kernel matches the driver on it | no attach | E |
| 2 | 16 MiB PIO window at offset 0 | mappable | attach fails (-1) | E |
| 3 | word at `0x64` | free (printed only at debug level above 0) | | E |
| 4 | one-wire ID text through the accessor at `0x9c` | the text contains `Name:XT-DIGVID`, or the reader's own `page A data not available` | attach fails (-1); the message "board is not a XT-DIGVID" is printed only when the debug level is above 0 | E (re-read in this pass: both `strstr` misses branch to the common return of -1) |
| 5 | widget status word `0x0c`, bit 5 | free: set prints a "400MB/s XIO slot" warning | | E |
| 6 | three interrupt objects, then `xtdigvid_init_xg` (control `0x24`, destinations, vectors, water mark, read of the cause word `0x6c`, expected 0) | cause word reads 0 | a message and the error interrupt is armed anyway | E ([fpga-load.md](../dm2/fpga-load.md) section 12) |
| 7 | map RAM invalidated entry by entry | stores accepted | | E |
| 8 | the GIF window `0x800000` and `0x120000` | **not touched at attach** | | E (scan in [fpga-load.md](../dm2/fpga-load.md) section 11) |

So the minimum hardware for "attaches": the widget block, the NIC text, a cause word that reads 0 and a store-only map RAM. The
GIF, the FPGAs and the VBOB are needed only when a library opens the board.

## 4. Nodes, `ioconfig` and the unit number

| Item | Value | Grade |
|---|---|---|
| Registration | `xtdigvid_reg` adds the path `video/xt-digvid` under the hwgraph root (so `/hw/video/xt-digvid`), then registers the widget driver. The path add failing prints "can't add /hw/video/xt-digvid path" | E |
| Board vertex | `xtdigvid_attach` creates a character device named `xtdigvid` (driver prefix `xtdigvid_`, mode 0666, vertex type 2) on the widget's vertex, so under the widget at e.g. `/hw/node/xtalk/10`; it adds the inventory entry (class 12, type 14, controller -1, unit 0, state 0) and registers the one-wire accessor as the vertex's NIC info | E (calls and constants), I (the argument names of the inventory call) |
| Pipe vertices | `xtdigvid_init_board` creates two more character devices, `pipe1` then `pipe0`, the same way as the board vertex; the `ioconfig` handler reaches them by the relative paths `../pipe1` and `../pipe0` from the board vertex, so they are siblings of it under the widget. The driver also carries edge names `pipe-input` and `pipe-output`; which pipe is which direction is not shown by the names (the interrupt page labels pipe 1 input) | E (names, creation, the paths), I (siblings), U (edge use) |
| `ioconfig` | the `ioconfig` utility sends the ioctl `0x6d687767` ('mhwg'); the handler takes a controller number from the kernel (`device_controller_num_get`), stores it as the unit (board `+0x20`, initialised to -1 at attach), traverses to `video/xt-digvid`, adds a link there named with the unit number (`%d`), adds `%dp%d` links to the two pipe vertices, and exports the label `irix_unit`. A unit number the kernel considers invalid prints "unit number %d from ioconfig is invalid" | E (calls, format strings, init to -1), I (that the `%d` link targets the board and `%dp%d` the pipes) |
| `dm_index` | ioctl `0x68647609` (the library's `XTHD_IOCTL_SET_DM_INDEX`) fails with `EINVAL` while the unit is still -1 (the library prints "ioctl XTHD_IOCTL_SET_DM_INDEX failed"); otherwise it stores the ML layer's index as the label `dm_index` and updates the inventory entry | E |
| `/dev` | none. User space opens `/hw/video/xt-digvid/<n>` and `/hw/video/xt-digvid/<n>p<k>` | E (library strings `/hw/video/xt-digvid/`, `%sp%d`) |
| Guest check | `hinv` line of section 1, `/hw/video/xt-digvid` present, `mlquery -d all` listing `xt-digvid:0` | O |

`hinv` shows `controller 0, unit 0, version 0x0` after `ioconfig` has run. The `version 0x0` is the inventory state word, set to
0 at the add and not changed by anything read here (I; not the widget revision, which no software reads).

## 5. Enumerate and open: the ML module

Order, as the shipped code does it. The ML layer, not `videod`, owns this board: `videod` logs `no devices found` on a guest with
only this board (O), because the board has no Video Library module.

| Step | Who | What | Grade |
|---|---|---|---|
| 1 | `mldaemon` (started by `/etc/init.d/mldaemon` if `chkconfig mldaemon` is on, or on demand by a client) | daemonises, opens the log, creates the shared capability segment (`/tmp/.ml32DaemonSharedCapabilites`), then runs a loop that was not read. Loading `libML` runs its initialiser, which scans `/usr/lib32/mlmodule` (the message "Ignoring mlmodule %s" is for files it skips) and connects each module | E (daemon main call list, strings), I (that the scan runs in the library initialiser when the daemon loads it) |
| 2 | `libdigvid` `ddInterrogate` | `getenv("_MLMODULE_ROOT")`; `opendir("/hw/video/xt-digvid/")`; keeps entries whose name does not start with `.` and does not contain `p` (so not `.`, `..` or `<n>p<k>`); none: "Information - no XT-DIGVID boards appear to be present on this system." | E |
| 3 | same | for each numeric entry `<n>`: `open("/hw/video/xt-digvid/<n>", O_RDWR)`; ioctl `0x68647609` with the index; `xhdInit(fd)`; `close`; `mlDINewPhysicalDevice` with a name built from the unit. Failures print "can't open", "can't initialize" or "can't add" and skip the board | E |
| 4 | `xhdInit` | get-NIC ioctl `0x6864760f`; parse `Part`; load the GIF; reset ioctl with argument 3; the seven other FPGAs; reset ioctl with argument 4. All of it is in [fpga-load.md](../dm2/fpga-load.md); the model has to make every poll in its section 5 pass | E |
| 5 | `mlquery`, `libML` clients | `mlGetCapabilities` on the system reference returns the device list; each device's name parameter is `xt-digvid` | E (call), O (output) |
| 6 | an application's `mlOpen` | `ddOpen`: reopens the node, opens the pipe nodes (`%sp%d`), maps the 16 MiB window only for FPGA reloads, then `xhdOpenPath`; see [pipes-timing.md](../dm2/pipes-timing.md) section 1 | E |

Consequence: the FPGA download runs inside the daemon's enumeration, once per boot of the daemon, before any application opens
the device (E for the order; that the download therefore happens at daemon start is I, since the daemon's initialiser was not read
beyond its strings). A model that fails any poll of [fpga-load.md](../dm2/fpga-load.md) section 5 gives an empty ML device list, not a
partly working board.

## 6. How the Discreet video layer selects the board

Read from Flame 9.0's `DLviodso16` libraries (D). The Discreet release family that matters (2007 and 2008) is the ML one.

| Step | Behaviour | Grade |
|---|---|---|
| Configuration | the `Video` line of `cfg/init.cfg` names the device; the word `XT-DIGVID` is in the configuration parser's table beside `OCTANEVIDEO`, `DIVO` and `NO_VIDEO` ([octane-digital-video](../octane-digital-video/README.md) section 9). The 9.0 line is `Video XT-DIGVID, Default, Serial1` and the application prints `VIDEO : XT-DIGVID, timing DEFAULT, in format SERIAL1, out format SERIAL1` | O |
| List build | `DlVideoListImp::_detectDevice` calls `_detectMlDevices` first, then `_detectVlDevices`, then `_detectDvsDevices`, logging `system has %d ml devices`, `%d vl devices`, `%d dvs devices`. In a run that found an ML device the VL line is absent, so the VL probe is skipped once an ML device exists. If the three counts are all 0 it throws "No video device detected" and every later call throws "No video list detected"; the product prints `VIDEO : DlVideo Error: No video list` and its menu does not draw | E (calls, strings), O (both log shapes) |
| ML detection | `DlVideoMl::_detectMlDevices`: `mlGetCapabilities` on the local-host system reference; on failure it starts the daemon (`/etc/init.d/mldaemon start`, after looking for a running one by name), sleeps one second and asks again; reads the system device-id array; for each id gets that device's capabilities and compares its name parameter with `strcmp` to the exact string **`xt-digvid`**; a match logs `found board named xt-digvid`; then `detected %d ml video devices` | E (calls, constants, strings), I (the retry bound was not decoded; the helper is passed 1000 as a further argument, meaning not shown) |
| Name match | `getDeviceByName` upper-cases the configured word and the device names and accepts the first device whose name contains it; none gives "Desired device is not supported" | E |
| Library load | `DlVideoImp::deviceInit` switches on the device type in the configuration: 1 `libDlVideoDeviceDivo`, 2 `libDlVideoDeviceOctane`, 3 `libDlVideoDeviceO2`, 5 **`libDlVideoDeviceXthd`**, 6 **`libDlVideoDeviceMl`**, 7 `libDlDeviceDvs`. `XT-DIGVID` is type 6, the ML library: it imports `mlOpen`, `mlSetControls`, `mlBeginTransfer`, `mlSendBuffers`, `mlReceiveMessage` and the wait handle calls, and no Video Library call. The log shows `Loaded libDlVideoDeviceMl.so` | E (switch and imports), O (log) |
| `XTHD` | type 5 loads `libDlVideoDeviceXthd`, which links `libvl` and `libDlVideoDeviceVl` and sets Video Library nodes, paths and colour space. It cannot open an OpenML device, so Discreet's `XTHD` is not this board. It is, by its API, the Video Library board of the HD I/O option (Onyx2 and Origin 2000, IRIX 6.5.4, guide 007-3968-002) | E (imports), I (that its board is the HD I/O option; its open path was not read) |
| Escape | `DLVIDEO_DISABLE_DETECTION` is read by the list code | E (string) |
| Release scope | 9.0 was read and run with the board. 9.2.5 and 9.5.1 were run only with the `Video` line commented out; their libraries were not read. Flame 7.6 OCT2 installs its own `xtdigvid` product and the `libDlVideoDeviceXthd` and dmSDK libraries; which of them it uses for a DM2 was not read | O (9.0), U (9.2.5, 9.5.1, 7.6) |

What a model must therefore present for Discreet: the ML device named exactly `xt-digvid` (so the board's `ddGetCapabilities`
has to run, which needs section 5 to have succeeded), the SGI `ml`, `ml_xtdigvid` and `vbob` products installed, and `mldaemon` running or
startable. The Video Library need not list it, and the Video Library listing is not what Discreet consults when an ML device exists.

## 7. Start-up read-backs, polls and interrupts

These are the accesses after attach that change the outcome. Full tables: [fpga-load.md](../dm2/fpga-load.md) section 5,
[interrupts-status.md](../dm2/interrupts-status.md), [dma.md](../dm2/dma.md), [vbob.md](../dm2/vbob.md).

| Phase | Access | Must hold | Grade |
|---|---|---|---|
| FPGA download | `0x120000` DONE (bit 0) and INIT (bit 1) transitions; `0x800004 \| off` READY (bit 7) per byte; per-FPGA DONE and INIT masks | as the table in [fpga-load.md](../dm2/fpga-load.md) section 5; a stuck bit fails with a named message and the ML device never appears | E |
| First reset | reset ioctl, argument 3: widget reset, XG rewritten, cause word reads 0, map RAM invalid | GIF stays configured across it | E, I (the GIF survival) |
| GIF ident | `0x800084`: upper 24 bits `0x474946` ("GIF") | read only in the argument-4 reset | E |
| UST | `0x80008c` cleared, host UST sampled | store accepted | E |
| Interrupts | three: XG error, video 0 (pipe 1, input), video 1 (pipe 0, output); the video ones are not waited for until a transfer starts. Starting a transfer needs the status ring in host memory and the field interrupt ([interrupts-status.md](../dm2/interrupts-status.md)) | not needed to attach or enumerate | E |
| VBOB | a transfer start sends VBOB messages (genlock source `0x21`, timing record `0x22`, routing `0x24` and `0x25`, sync state `0x26`, output default `0x28`, TV standard `0x20`) and waits for the acknowledgement interrupt; with no VBOB at all, `_XTDIGVID_NO_VBOB_SUPPORT` switches the CLINK to an on-board clock | E ([vbob.md](../dm2/vbob.md)) |
| Lock | after Flame 9.0 sets a genlock source of analog reference, a model that reports no lock produces `ML_EVENT_VIDEO_SYNC_LOST` about 3 s after the memory-to-video thread starts and `ML_EVENT_DEVICE_ERROR` about 2 s later; reporting a locked 525-line reference removed both | O (model run; the hardware behaviour is the documented genlock rule, not shown by software) |

## 8. Pixel formats and their relation to the DM2

There is nothing new here: XT-DIGVID is the DM2/DM3, so the formats are [the DM2 pixel formats](../dm2/pixel-formats.md). The
points that matter for a contract:

- The format is chosen by which packer and unpacker FPGA images the library loads (`packer_<name>`, `unpacker_<name>` through the GIF),
  not by a register; the only format-dependent writes are the 8-bit flag at `0x80304c` and the colour converter coefficients. E.
- Flame 9.0 requests VIO packing 0, which `libDlVideoDeviceMl` maps to the 4:4:4 8-bit natural packing (library constant
  `0x1001b108`, sampling `0x4440`), three bytes per pixel, loading `packer_444_8` and `unpacker_444_8`, with a 4:2:2 serial interface
  on the jack (`SERIAL1`). E ([pixel-formats.md](../dm2/pixel-formats.md) section 4).
- The bit layouts come from the HD I/O guide's appendix (007-3968-002), which describes the same packings in Video Library terms
  for the other board, and the DM2 guide's Table 5-4 maps them to OpenML names. So "the same formats as the HD I/O option" is true of
  the layouts and the names, not of the driver or the API. E (guides).
- A model that does not execute the FPGA images can recognise the pair loaded and act on it, or take the format from a property. A.

## 9. The minimal model contract

For "present, enumerates, opens, passes Flame 9.0 start-up" on an Octane2 V10 or V12, and the same widget on IP35 hosts:

1. An XIO widget with part `0xc102`, manufacturer 682, a 16 MiB window, the standard widget block, a cause word at `0x6c` that reads 0 and
   a map RAM that accepts stores. E.
2. A one-wire ID reader at window offset `0x9c` returning text with `Name:XT-DIGVID` and `Part:030-1653-00N` (decimal groups at offsets
   4 and 9; any `Revision`, any `Serial`). E ([fpga-load.md](../dm2/fpga-load.md) section 13).
3. The GIF configuration port at `0x120000` and the per-FPGA select, port and READY registers so that every poll of
   [fpga-load.md](../dm2/fpga-load.md) section 5 passes, the GIF ident `0x474946` at `0x800084` after the GIF is loaded. E.
4. The unit number comes from the guest's `ioconfig`, not from the hardware; nothing in the model supplies it. E.
5. Three interrupt sources wired to the widget's interrupt destination (the guest programs them), the status ring writes and the field
   interrupt once a transfer starts. E.
6. A VBOB endpoint answering the control channel, including a reference lock for the standard the project uses (section 7). A.
7. Nothing for hwgraph, `/hw`, inventory, `hinv`, `mlquery` or the ML names: the unmodified guest driver and libraries produce all
   of them. E.

What can stay unmodelled: pixel processing (the library does not read pictures back), the board's FPGA behaviour beyond the
handshake, the second VBOB link, and any register the guest never touches. E for the code read; the video data path is U.

## 10. Not settled, and what settles it

| Unknown | Route |
|---|---|
| Whether the Discreet `XTHD` library's board is the HD I/O option, and what it opens | read the open path of `libDlVideoDeviceXthd` and `libDlVideoDeviceVl`; the HD I/O board's driver is not held |
| Which module Flame 7.6 OCT2 uses for a DM2 (dmSDK `libDlVideoDeviceDmsdk` or `Xthd`) | read that release's device selection; its media is not unpacked in this pass |
| DM3 against DM2: assembly `030-1927-003`, any register or NIC difference | a DM3 capture, or the Tezro and Onyx 350 objects compared function by function (constants match; bodies were not diffed) |
| What the `pipe-input` and `pipe-output` edges are used for | the code that adds them (not found in the attach, ioconfig or open paths read here) |
| Whether the daemon's initialiser, not the first client, runs the FPGA download | read `libML`'s initialiser and `ddConnect` |
| Tezro and Onyx 350 start-up with Discreet software | no guest run exists; the Octane2 V12 runs are the only observation |
| Widget revision, reset values, what status bit 5 means | no shipped software reads them; model-author choices ([DM2 page](../dm2/README.md) section 9) |
| Colour converter maths and the 12-in-16 and 3214 layouts | [pixel-formats.md](../dm2/pixel-formats.md) section 6 |
