# Scoping datasheet: DIVO and DIVO-DVC digital video options (Onyx2 and Origin XIO boards; IRIX driver `divo`, VL module `DIVO.so`)

Status: **scoping draft, not independently reviewed.** It records what the shipped IRIX 6.5 software for the DIVO and
DIVO-DVC XIO boards reveals, and what a "board present, enumerates, opens, passes product start-up" model must supply so
that unmodified guest software accepts it. It is not a register manual. No published specification of the board's ASICs
is held, and nothing here depends on a physical board. Companion page:
[linc-register-map.md](linc-register-map.md) (the per-LINC window, mailbox, packet and ioctl tables). Modelled on
[devices/octane-digital-video](../octane-digital-video/README.md), the sibling Octane board.

Ratings: **established** (a published document states it), **observed** (seen in a guest disk or run), **software
expectation** (SE: the shipped binary does exactly this), **inferred**, **approximation** (a stand-in an implementer must
choose; not a hardware fact) and **unknown**. In the terms of [AGENTS.md](../../AGENTS.md), SE is "established from a
shipped binary" and is limited here by one caveat: the decompiler output was the working view of the object code and the
immediates quoted were spot-checked against the disassembly (the PCI ids and their call, the flash identifier, the LINC
and flash window constants, the mailbox window, the ioctl base), not every instruction by hand. Decompiler output is
navigation, not evidence; a reviewer should recheck an access before building on it.

The answer in one paragraph: the guest-side chain is short and fully visible. A Bridge-family XIO card with an ID PROM
whose text names a `030-1046`, `030-1305` or `030-1387` part, carrying two PCI functions `10a9:0002` (the "LINCs"), makes
the unmodified kernel driver attach, create `/hw/.../divo`, add the `INV_VIDEO_DIVO` inventory entry and, after the
`ioconfig` step, `/hw/video/divo/<n>`. That makes `videod` list `DIVO_<n>` and Inferno find it. What stops a bare PCI model
is the **board's own MIPS firmware**: `videod` talks to it through a mailbox on the first thing it does, so a model needs a
firmware stand-in (an approximation), a flash that survives the library's checksum scan, the packet ring and two
interrupts. The sections give the smallest such set. The guests today have none of this software installed (section 2).

## Sources

| Tag | Source | Used for |
|---|---|---|
| B1 | SGI DIVO software 1.2 for IRIX 6.5, from the community driver archive (`divo_1.2.tar.bz2`, sha256 `30b5c98c…`): tardist `divo` product with `usr/cpu/sysgen/IP{27,30}boot/divo.a`, `var/sysgen/{master.d,ioconfig,system}`, `usr/lib32/dmedia/video/DIVO.so`, `etc/init.d/initdivo` (only the 2.4 `DIVO.so` is analysed below) | the base product the 2.4 overlay needs; `master.d`, `ioconfig` and `system` files, which the overlay does not carry |
| B2 | SGI "DIVO Option and DIVO-DVC Option" software 2.4 for IRIX 6.5.11, `divo_6511m` (tardist sha256 `9f2b273a…643f`; the `.sw` image sha256 `e5d80bc4…` and `.idb` `4f84c248…`): `usr/cpu/sysgen/IP{27,30,35}boot/{divo.a,divo_al.o,mdivo.o}` (the IP27 `divo.a` sha256 `48c7a193…3af3`, members `divo.o divo_init.o divo_ioctl.o divo_intr.o divo_dma.o divo_flash.o divo_idbg.o`), `usr/lib32/dmedia/video/DIVO.so` (sha256 `0d506518…eb02`, n32, not stripped), `usr/dmedia/ucode/DIVO/{divofw,divofw.dvc,lincprom}` and the packer/FPGA files, `usr/dmedia/bin/DIVO/{divo_cmd,divohinv,flashdivo}`, `usr/diags/DIVO/bin/*`, the release notes (`divo.man.relnotes`) | kernel driver, VL module, firmware image headers, user-visible behaviour |
| B3 | Discreet Inferno 4.6 IR2 beta 1 (`inferno_IRIX_6.5_ip27`, sha256 `540ca892…bee3`, n32, dynamic symbols present) and its shipped `cfg/sample/init_*.cfg`; Inferno 6.2.5 media: `DLviodso19` libraries `libDlVideo.so`, `libDlVideoVl.so`, `libDlVideoDeviceDivo.so`, `libDlVideoDeviceVl.so` and `cfg/onyx2/sample/init_*.cfg`. Licence and key material was not read | device selection, the "No video list" trigger, the start-up call chain |
| B4 | Installed guest disks, opened read-only through qcow2 overlays: the Onyx2 6.5.21f base of the Discreet ladder and the working Inferno 4.6/4.7.2 disk (`/usr/discreet/...cfg/init.cfg`, kernel object set, `/usr/lib32`, `/etc/config`). No file under any private directory and no licence file was opened | what the guests have today |
| M1 | SGI *DIVO (Digital Video Option) XIO Board Installation Instructions*, 108-0173-001 (held copy; contents, figures 2-12 and 2-13 read) | which XIO slots take the board |
| M2 | SGI *DIVO Option and DIVO-DVC Option Release Notes* (the `divo.man.relnotes` subsystem of B2, chapters 1 to 6, read in full) | numbering, `hinv` lines, supported releases, known problems |
| M3 | SGI *DIVO XIO Board Owner's Guide*, 007-3524-001 (listed in the SGI printed manuals index; **not read**; the page of the DM2 sibling cites 007-3524-004, which is not held) | user-visible behaviour only (no registers) |
| C1 | This repository: [dm2](../dm2/README.md) section 11 (the earlier lower-depth DIVO entry), [bridge](../bridge/README.md), [at29c040a](../at29c040a/README.md) | Bridge register meaning, flash part |

Tools: Ghidra export (decompile navigation) over `divo_*.o` and `DIVO.so`, `objdump` spot checks as described above,
`nm`/`readelf` for sizes. No firmware bytes, listings or vendor identifiers are reproduced here.

## 1. Identity

| Fact | Value | Rating |
|---|---|---|
| Marketing names | "DIVO" and "DIVO-DVC" (DVC: DIVO plus two DVCPRO codec daughter cards); the XIO brick list gives `XT-DIVO` and `XT-DIVO-DVC` ([xbrick](../../platforms/bricks/xbrick.md)) | established (M2, brick list) |
| Systems | Onyx2, Onyx3000, Origin200, Origin2000 and Origin3000 ("plugs in directly to an XIO slot"); release 2.4 adds SN1 (Onyx3000/Origin3000) | established (M2) |
| Slots | not XIO slot 1 in an Origin2000 deskside or rackmount or an Onyx2 rackmount; not XIO slot 4 in an Onyx2 deskside | established (M1, figures 2-12, 2-13) |
| Kernel driver | sysgen module `divo` (flags `ocsn`, prefix `divo_`), and `divo_al` (flags `cso`, prefix `divo_al_`, depends on `kdsp` and `divo`) for embedded audio. Objects: `usr/cpu/sysgen/IP27boot/divo.a`, `IP30boot`, `IP35boot`; shipped by the `divo.sw.eoe` subsystem of the DIVO products, **not** by the IRIX base | SE (B1, B2) |
| Kernel releases | base 1.2 (IRIX 6.5) plus the 2.4 overlay for 6.5.11 ("not complete images, but rather an overlay"); 2.4 needs 1.2 installed first. A 2.4 `divo.a` is 148,324 bytes for IP27 against 119,908 in 1.2. Whether 2.4 loads on a 6.5.21f kernel is unknown; the guest kernel does carry `dms.a` and `kdsp.a` | established (M2: prerequisites); U (6.5.21f) |
| Bus identity | the driver registers for **PCI vendor `0x10a9` device `0x0002`** (`pciio_driver_register(0x10a9, 2, "divo_", 0)`). One board is **two** such functions (two LINC ASICs, "pipes" 0 and 1) | SE |
| Widget | the card is Bridge-based: the driver uses `pcibr_hints_dualslot`, `pcibr_hints_fix_rrbs`, `pcibr_alloc_all_rrbs` and `xtalk_piotrans_addr`. The Crosstalk part number of that Bridge is **not read by the driver**; the standard Bridge identification ([bridge](../bridge/README.md)) is what the pcibr layer expects | SE (calls), I (that it is a plain Bridge) |
| ID PROM text | the driver reads it from the hwgraph label `_nic` on the Bridge vertex (written by the pcibr layer from the board's ID PROM). It looks for `Part:030-1046-`, `Part:030-1305-`, `Part:030-1387-` (and, for the DVC test, `Part:030-1388-`). With `030-1046-`: the digits after the prefix must be 3 or more, or exactly 2 with revision letter `C` to `Z` after `Revision:`; otherwise "board is down rev; not supported". The registered NIC callbacks are `divo_vmc` for the first three prefixes | SE |
| Parts seen in public `hinv -mv` | DIVO `030-1046-002` (rev F, G, H), `030-1305-001` (rev E), `030-1305-003` (rev A); DIVO-DVC `030-1387-001` (rev A, E) with two `DVCPRO_CODEC` `030-1388-001` (rev A) | observed (M2 example, [dm2](../dm2/README.md) captures) |
| Which part is which family | `030-1046` boards have their second LINC in PCI slot 1; `030-1305` and `030-1387` boards have it in PCI slot 2. The attach routine accepts only that combination; anything else is "NIC inconsistent with board config" | SE |
| hwgraph | board vertex `/hw/module/<m>/slot/io<k>/divo` (the `hinv -mv` "Location" lines), with sibling vertices `pipe0` and `pipe1`; `divo` is the character device the VL module opens (one opener at a time: a second open gets `EBUSY`); `pipeN` nodes are poll-only | SE; observed (M2 `hinv -mv` lines) |
| `ioconfig` | shipped line `12 10 -1 -1 divo 0 0x6d687767` (class `INV_VIDEO`, type `INV_VIDEO_DIVO`); the `ioconfig` utility sends command `0x6d687767`; the driver then assigns the controller number, adds `/hw/video/divo/<n>` (link to the board), `/hw/video/divo/.<n>debug` and `/hw/video/divo/<n>p0`, `<n>p1` | SE |
| `hinv` | `DIVO Video: controller <n> unit <n> state 0`, one line per board with no DIVO/DIVO-DVC distinction; unit is 0 until `videod` has run once. `hinv -mv` adds `DIVO Board: barcode ... part 030-... rev ...` and, for DVC, the daughter cards. `divohinv` prints the VL device name | established (M2), SE (inventory call: class 12, type 10, controller -1, unit 0, state 0) |
| `/dev` name | none under `/dev` is created by the driver; user space opens `/hw/video/divo/<n>` | SE (`DIVO.so` strings) |
| VL name | `DIVO_<n>` or, when the NIC text carries a `030-1388-` or `030-1225-` token, `DIVO_DVC_<n>`; the VL unit is set through the ioctl `0x64767306` and cross-checked with `0x64767307` | SE |
| Interrupts | two (one per LINC), INTA of each PCI function: `divo_0 a`, `divo_1 a` | SE |
| Error handling | `pciio_error_register` for both functions (PIO and DMA write/read errors are logged, not fatal) | SE |

## 2. What the guests have today

The Discreet ladder's Onyx2 base disk (IRIX 6.5.21f, system disk of the Inferno 4.6 and 4.7.2 runs) and its working
copy carry `videod` (`/usr/etc/videod`, `chkconfig videod` on), `libvl`, `dms.a`, `kdsp.a` and `mgvstubs.a`. They have
**no** `divo.a`, `divo_al.o`, `mdivo.o`, `DIVO.so`, `/usr/lib32/dmedia/video` directory, `/usr/dmedia`,
`/var/sysgen/master.d/divo` or `/var/sysgen/ioconfig/divo`. So there is no `divo` driver, no `/hw/video/divo`, and `videod`
has nothing to load. Observed (B4). The DIVO base 1.2 and the 2.4 overlay (B1, B2) must be installed with `inst` and the
kernel autoconfigured before a model can matter. The sample `init.cfg` of Inferno 4.6 on the working disk carries the
line `Video DIVO, Serial` (active; the Discreet notes' own test runs commented it out).

## 3. Where Inferno chooses the device and where it complains

**Inferno 4.6 IR2 beta 1.** The configuration line is `Video <device>, <input>[, <board>]`; the shipped samples use
`Video DIVO, Serial` (NTSC/PAL) and `Video XTHD, Serial` (HDTV). The word table in the binary holds `SIRIUS`, `DIVO` and
`XTHD` among the video words; the start-up code switches on a numeric device type (3 selects `InitVideoDivo`, 4
`InitVideoXTHD`; 0 to 2 other paths). SE.

* `InitVideoDivo` sets the device type, then `VideoDivoSetInput(1)`: it builds a `DivoVideo` (the same `libimpact` `Video`
  base class the Octane products use), whose constructor calls `vlOpenVideo(NULL)` and `vlGetNode`. A failure logs
  `vlOpenVideo failed` or `vlGetNode failed` through the `VIDEO :` message line and the constructor still returns.
* `DivoVideo` wants the device named **`DIVO_<board>`** when a board number is given and **`DIVO_1`** when it is not.
  `SetupPath` gets the device list (`vlGetDeviceList`, 48-byte records), compares names exactly, then compares after
  cutting the wanted name at its last underscore (so `DIVO_DVC_0` is satisfied by a `DIVO...` prefix), and if nothing
  matches logs `Found no video device named "%s". Using device named "%s"` and takes the **first** device. So any
  non-empty list works; an empty list does not. SE.
* The string **"No video list" is not in the 4.6 binary** (nor in its message catalogues). The DIVO message on 4.6 with no
  board is the `vlOpenVideo failed` / node-setup failure family, which the product survives. The reported "No video list"
  therefore belongs to Inferno 5.5 and later (and Flame/Flint 9.x), not to 4.6; the notes record it for 5.5, 6.2.5 and
  Flame 9.0. Observed (the Discreet notes), SE (absence by string search of the 4.6 ELF).

**Inferno 5.5, 6.2.5 (and later `DlVIO` releases).** The video layer is a set of shared libraries
(`libDlVideo.so`, `libDlVideoVl.so`, `libDlVideoDevice*.so`). Read for 6.2.5 (`DLviodso19`); the 5.5 media was not
unpacked, so identical behaviour in 5.5 is inferred from the same class names in its executable. SE (6.2.5), I (5.5).

1. `DlVideoGetListMgr` calls `getInstance(false)`. The first call builds the list: `_detectDevice` runs
   `_detectMlDevices` (media-library devices, the DM2/XT-DIGVID path, `libDlVideoMl.so`), then, only if that found none,
   `_detectVlDevices` (`libDlVideoVl.so`: `vlOpenVideo("")`, `vlGetDeviceList`, one record per entry, closing the server)
   and `_detectDvsDevices`. It logs `DlVideo: system has %d ml devices`, `... vl devices`, `... dvs devices`.
2. **If the three counts sum to 0 it throws "No video device detected"**. The instance is not stored but a "detection done"
   flag is set, so **every later `DlVideoGetListMgr` call throws "No video list detected"**. That second message is the
   one the product prints (`VIDEO : DlVideo Error: No video list` in the Discreet console captures).
3. When the list is not empty, `getDeviceByName` upper-cases the configured name and the device names and accepts the
   first VL device whose name **contains** the configured word (`DIVO`, `XTHD`, `IMPACT`, `MVP`, `DVS` are the words in
   the table); none found throws "Desired device is not supported". The sample `init_sdtv.cfg` for Onyx2 reads
   `Video DIVO, Default, Serial1`; HDTV reads `Video XTHD, Default, Serial1`. The environment switch
   `DLVIDEO_DISABLE_DETECTION` exists in the library.
4. A vl count of 0 happens when `vlOpenVideo` fails (no `videod`, or `videod` exited because it loaded no device) or when
   `vlGetDeviceList` is empty. For DIVO that means `DIVO.so` registered no board: section 4.

## 4. The VL module: enumerate and open

`videod` loads `/usr/lib32/dmedia/video/DIVO.so` (it exports `DIVODeviceInfo` and `DIVOBind`; the name matches the
`DIVO` prefix of the VL device names). SE.

| Step | What `DIVO.so` does | If it fails |
|---|---|---|
| 1 | `DIVOBind` reads the directory `/hw/video/divo/`, keeps entries whose names are numbers (skips names starting with `.` or containing `p`), sorts them | no entry: logs **"No DIVO boards on the system!"** and returns, so `videod` has no DIVO device |
| 2 | optional avoid list: environment `_DIVO_AVOIDS` or the file `/usr/diags/DIVO/bin/DIVO_AVOIDS` | skips those boards |
| 3 | for each number `n`: opens `/hw/video/divo/<n>` read-write, calls `AddDevice` (which calls `divoInit`) | on failure logs "Unable to add device" and the hint "setenv _DIVO_AVOIDS" and stops |
| 4 | `divoInit`: `divo_dvc_get_nic` (ioctl `0x64767305`, NIC text split on whitespace; tokens cut after the last dash and compared with `030-1225-` and `030-1388-`) decides the name `DIVO_DVC_<n>` or `DIVO_<n>`; ioctl `0x64767300` must return **1**; ioctl `0x64767306` sets the unit; ioctl `0x64767307` must echo the same unit | "driver and videod version mis-match", "DIVO_IOCTL_SET_VL_UNIT failed" or "GET_UNITS disagrees" |
| 5 | per-board start routine (below), then event thread (flush events ioctl `0x64767324`, set mask `0x64767323`, a `pipe` and an `sproc` thread that `select`s the two pipe poll nodes `/hw/video/divo/<n>p0` and `p1`) | "can init divo device" / "can init divo videod nodes" |

The per-board start routine, in order, SE:

1. read the NIC again; allocate state; for each pipe open `/hw/video/divo/<n>p<pipe>` (the poll nodes);
2. **flash check** (`divoCheckFlash`) unless the environment variable `_DIVO_NOFLASH_FIRMWARE` is set: for each pipe set mode
   3 (boot mode), compare the flash against the files under `/usr/dmedia/ucode/DIVO/` and burn what differs (section 7),
   then reset each pipe to run the firmware (`0x6476730c` mode 0; `EBUSY` is retried up to 200 times at 100 ms; a
   failure prints "Cannot bring pipe %d out of reset"), then set mode 1;
3. **three firmware reads per pipe** (section 5 of the register map), a write to `0x05000004`, a flush;
4. build the node tables, then start the event thread.

Nothing in these steps reads a hardware ID register of the LINC; the only hardware-ID check is the VIP word inside the
boot-mode sequence ([register map](linc-register-map.md) section 1).

## 5. The minimal model contract

Written so that each row can be tested against an unmodified guest with section 2's software installed.

| # | The model provides | Why (what breaks without it) | Rating |
|---|---|---|---|
| 1 | an XIO Bridge-class widget holding two PCI functions `10a9:0002`, in PCI slots 0 and 1 (`030-1046` flavour) or 0 and 2 (`030-1305`/`030-1387` flavour); each function in memory space, bus-master enabled by the driver | the driver registers only for these ids and checks the slot pairing | SE |
| 2 | an ID PROM readable through the Bridge's NIC path whose text contains `Part:030-1305-001`, then `Revision:` plus a letter (and for DVC the extra `Part:030-1388-` token twice) | attach refuses a down-rev or unknown part and the `_nic` label is what the driver searches | SE |
| 3 | per function: config dword `0x10` = a 128 MiB-aligned window base, pipe 1's base exactly pipe 0's plus `0x8000000`; the driver maps one 256 MiB window from pipe 0's base | "LINC 1 BAR invalid" fails the attach | SE |
| 4 | config dword `0x14` reading the mailbox consumer index (register map section 3) | the first 32 mailbox writes would otherwise fill the ring | SE (use), I (meaning) |
| 5 | the window of the register map, section 1: plain read/write storage for the LINC control block and the unlisted offsets, with these active rules: VIP word reads `0x000810a9`; `[0x07800000]` bit 6 reads 0; `[0x07800018]` bit 20 write-1-to-clear and the interrupt line; the mailbox ring; the flash | the boot-mode sequence refuses a missing VIP and the reset ioctl retries on bit 6 | SE |
| 6 | the **flash** (512 KiB, id `0x1fa4`, sector write and erase, register map section 4) | the library reads the flash headers on every start | SE |
| 7 | the **firmware stand-in** (an approximation): consume mailbox words; for opcode `0x10` and `0x12` return a reply packet with the value; for `0x20`/`0x23` to `0x28` read the block and send the completion packet; keep the consumer index current; for everything else accept and drop | `videod` blocks in the synchronous read (ioctl `0x6476731f`) at its first register read | SE (the host side), approximation (the stand-in) |
| 8 | the **packet ring** in host memory (64 entries of 128 bytes, entry valid when its dword at `0x7c` is non-zero) and the INTA line | replies and completions travel as packets | SE |
| 9 | writes the firmware stand-in must perform on release from reset: none that the host sees; the board needs only to start accepting mailbox words once the reset ioctl has returned | the host's reset path writes nothing it waits on, except bit 6 | I |
| 10 | LINC status `0x07800018` bit 21 never set | it would take the "firmware crash" path | SE |

Items 1 to 6 make the card **present, enumerate and open**: with them the driver attaches, `hinv` shows the line,
`/hw/video/divo` appears, but `videod`'s first start would still block on item 7. Items 7 and 8 let it **pass
`videod` start-up** and list `DIVO_<n>`. Whether that is enough for **Inferno's first screen** is the next section.

## 6. Product start-up beyond the list (Inferno 4.6)

`VideoDivoSetInput(1)` goes on from the device lookup as follows (SE for the call order, I for each call's effect on the
driver): `SetupPath` with timing, sync and sync source converted from the configuration; `vlGetControl` on the source
node for the raster size; the video-node controls (format, dominance, precision); the memory-node controls (packing,
dominance, colour space); the transfer size; a vendor control (`0x44495651`, "DIVQ") read and, if not 1, set to 1; then a
call through the object's vtable at slot `0x104` that I take to be the begin-transfer call (unconfirmed). Along the way
the library creates a digital-media pool and registers it. Through `videod` and `DIVO.so` these become
mailbox words (opcodes `0x00`, `0x02`, `0x03`), event mask changes, the pool attach and transfer management ioctls
(`0x64767325`, `0x64767326`) and, if a transfer begins, the frame-time packets. The packet types a stand-in would send
for frames are in the register map section 6; their content and the descriptor format were not decoded. **Unknown**: whether
Inferno 4.6 reaches "Startup complete" with a stand-in that sends no frame packets. The route that settles it is a
guest run with the stand-in and `par`/event tracing.

## 7. The flash and the firmware images

The video library keeps ten flash sections in step with files under `/usr/dmedia/ucode/DIVO/`: `lincprom`, `firmware`
(`divofw`), `rpc`, `rpc2`, `vidif`, `vidif28` (FPGA configuration files), two packer sections, an audio packer and
`bootinfo`; the FPGA and packer files come in about 50 pixel-packing variants. Each section has a header (a four-letter
magic such as `FiRm`, a version and a checksum) which `divo_read_fhdr` reads through the flash ioctl; the library compares
the magic, the version and the checksum with its own tables and "reflashes" a section that disagrees ("Invalid flash
magic number ... reflashing"), taking about 45 s (DIVO) to 60 s (DIVO-DVC) per board (M2). SE.

* A model whose flash starts erased makes the library burn every section on first start. That works through the flash
  sequences above and is the faithful behaviour; making the flash persistent across runs avoids the delay later.
* `divofw` and `divofw.dvc` in the 2.4 package are **byte-identical** (619,984 bytes, MIPS-II ELF, entry `0x80022b14`,
  one loadable segment of `0x37240` bytes at `0x80000000` plus a `0x1880`-byte bss at `0x80058000`). `lincprom` is a
  32,744-byte MIPS-II ELF with entry `0xbfc00000`. The library reads `divofw` itself into a 0x4d000-byte image at flash
  offset `0x32f00` (a 32-byte header plus the ELF payload). SE (headers, sizes, the burn layout); U (what the firmware does).
* Everything that runs on the board (LINC PROM, firmware, FPGAs) is inside those images; a model that does not execute
  `divofw` has to answer for it. That is the one approximation in this contract. Executing `divofw` on a modelled MIPS
  core is possible in principle (the image is a plain MIPS-II program) but its board memory map, the LINC internal
  registers it drives and the other ASICs are **unknown**.

### Memory packings the VL module offers (component depth)

**Software expectation** (B2, `usr/lib32/dmedia/video/DIVO.so` 2.4, the 51-record table `divoMemPackingList` at 0x5fff4af8, 36 bytes a record with the name inline, count in `divoNumMemPackings`; names read from the data section). The VL module can select, by name, memory packings of up to 13 bits a component, which is what bounds the component depth the board path can be asked for:

| Bits a component | Names (an `R` prefix is the reversed component order; `L` and `R` suffixes are left or right justified in a 16-bit word) |
|---|---|
| under 8 | `444_332`, `444_5_6_5`, `X4444_5551`, `4444_6`, `4_4` |
| 8 | `444_8`, `4444_8`, `0444_8`, `242_8`, `2424_8`, `4_8` (and the `R` forms) |
| 10 | `4444_10_10_10_2`, `2424_10_10_10_2Z`, `242_10`, `242_10_in_16_L`/`_R`, `444_10_in_16_L`/`_R`, `4444_10_in_16_L`/`_R` |
| 12 | `444_12`, `4444_12`, `444_12_in_16_L`/`_R`, `4444_12_in_16_L`/`_R`, `242_12_in_16_L`/`_R`, `2424_12_in_16_L`/`_R` |
| 13 | `444_13_in_16_L`/`_R`, `4444_13_in_16_L`/`_R` |

The list also holds two compressed-video entries, `DV` and `SDTI_DV`, which have no component depth. The sampling digits follow the VL names (`4444` RGBA or YCbCrA, `444` three components, `242` and `2424` 4:2:2 and 4:2:2:4). The same module also has strings "Invalid VL_RICE_COMP_PRECISION value" and "64-bit packings not yet supported". What the board hardware does with a 13-bit packing, and whether any shipped application asks for one, is **unknown**: the table is the library's menu, not a hardware contract. The DM2's list ([pixel-formats.md](../dm2/pixel-formats.md)) tops out at 12 bits, so the 13-bit forms are a DIVO difference. The ucode file names (`/usr/dmedia/ucode/DIVO/4444_8...`) show each packing is a packer image chosen by name, as on the DM2, so the packing is not a register (**inferred** from the file names).

## 8. DIVO against DIVO-DVC

| Aspect | DIVO | DIVO-DVC | Rating |
|---|---|---|---|
| NIC parts | `030-1046-002` or `030-1305-00x` | `030-1387-001` plus two `030-1388-001` (`DVCPRO_CODEC`) | observed (M2) |
| Kernel driver | same `divo`, same PCI ids; the driver only records a DVC flag (`030-1388-` found in the NIC text) in the board record | same | SE |
| PCI slot pairing | `030-1046`: LINC 1 in slot 1; `030-1305`: slot 2 | `030-1387`: slot 2 | SE |
| VL name | `DIVO_<n>` | `DIVO_DVC_<n>` | SE |
| Firmware | `divofw` | `divofw.dvc` is present but identical to `divofw` in 2.4; the flash check names only `divofw` | SE |
| Extra tools | | `dvcpro_init`, SDTI/DV packers (`DV`, `SDTI_DV`) | SE |
| Flash reflash time | about 45 s | about 60 s | established (M2) |
| Features the model does not need for start-up | | DVCPRO/DVCAM compression, SDTI | established (M2) |

## 9. Unknowns, sized, and what settles each

| Unknown | Size | What settles it |
|---|---|---|
| The board firmware's behaviour and the LINC/VIP/FPGA register behaviour behind the mailbox | one 620 KB MIPS program, one 32 KB PROM, two ASICs | read `divofw` and `lincprom` (Ghidra export of the two ELFs; they are not stripped); no physical capture is needed to start |
| The Crosstalk part number of the XIO card's Bridge, revision and widget status | a few words | no shipped software reads them; record as an implementer choice, or one read-only capture under the physical-test procedure |
| The meaning of LINC `0x07800000` bit 6, `0x07800020` bits 21:20 and the `0x05000004` bits | a handful of bits | `divofw` and `lincprom` |
| Frame-time packet content, DMA descriptor layout, the pool/fifo ioctl structures | the rest of `divo_dma.o` (about 3.7 KB of code) and `divo_intr.o` helpers | read `divo_dma` and `check_dma`; trace a run |
| Whether Inferno 4.6 starts with a firmware stand-in that sends no frame packets | an experiment | a guest run |
| Whether the 6.5.11 overlay loads on the 6.5.21f kernel of the guests | an experiment | install it on an overlay copy of the disk |
| The exact flash part (identification `0x1fa4` but an erase command the AT29C040A datasheet does not define) | one part | a part marking from a board photograph, or the implementer's choice |
| Owner's guide 007-3524-001 content (LED meanings, jumpers) | 142 pages | read it; it holds no registers |

## Not done in this pass

* `divofw`, `lincprom`, the FPGA and packer images, `divo_dma.o` in detail, `divo_idbg.o`, `divo_al.o` and the
  `mdivo.o` diagnostic module were not read; `divotest` and `divo_confidence` were not run.
* Inferno 5.5 and Flame 9.x video libraries were not unpacked; only 6.2.5's `DLviodso19` was read.
* The IP30 (Octane) and IP35 builds of `divo.a` were not compared with IP27 beyond sizes.
* No model was built and no guest was run: everything here is software reading, so the "stand-in is enough" claims in
  sections 5 and 6 are predictions.
