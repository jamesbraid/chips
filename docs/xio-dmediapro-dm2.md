# Scoping datasheet: SGI DMediaPro DM2 (XT-DIGVID) XIO video board, with DIVO as the fallback

Status: **scoping draft, not independently reviewed.** It records what the shipped IRIX 6.5
software for two XIO video boards reveals about their hardware, and how much remains
unknown. It is not a register manual: the DM2 register map is partly located, the
rest is sized in section 9. Labels follow [AGENTS.md](../AGENTS.md): **E** established,
**I** inferred, **U** unknown. The IRIX-side driver and daemon facts are in the sibling kernel
repository's note on the DMediaPro and DIVO software stack; this page keeps the hardware.

The question it answers: can a model of the DM2 (Octane2 XIO slot) be built from what the
shipped software reveals, and is DIVO (Onyx2 XIO slot) a cheaper fallback? Short answer in
section 10.

## Sources

| Tag | Source | Used for |
|---|---|---|
| B1 | SGI "DMediaPro DM2 and DMediaPro DM3 Software 1.1.3ml" CD set (tar sha256 `fb1d0c17…66ef`): `ml_xtdigvid` kernel objects `usr/cpu/sysgen/IP{27,30,35}boot/xtdigvid.o` (sha256 of the IP30 object `952c3d9e…772b`), `xtdigvid.o` is ELF64 big-endian relocatable with symbols and a `.debug_line`, built for n32/mips4 | widget identity, register offsets, interrupts, mapram, status ring, error causes |
| B2 | Same set: user-space ML module `usr/lib32/mlmodule/libdigvid.so` (sha256 `aacf8d4a…c2ca`, n32, stripped of non-dynamic symbols) and `libML.so.1`, `usr/sbin/mldaemon`, `usr/bin/mlquery`, `usr/dmedia/ucode/xtdigvid/*.mcs`, `usr/dmedia/bin/vbob/*`, `usr/diags/ml_xtdigvid/bin/*` | FPGA load path, VBOB messaging, genlock, hinv text |
| B3 | Same set: `var/sysgen/{master.d,ioconfig,mtune,system}/xtdigvid` (readable configuration, not source), `usr/include/ML/ml_xtdigvid.h` (names only) | driver prefix, ioconfig class and type, tunables, custom controls |
| B4 | SGI "DIVO Option and DIVO-DVC Option" software 2.4 for IRIX 6.5.11 (product `divo_6511m`, tardist sha256 `9f2b273a…643f`): `usr/cpu/sysgen/IP{27,30,35}boot/divo.a` (members `divo.o divo_init.o divo_ioctl.o divo_intr.o divo_dma.o divo_flash.o divo_idbg.o`), `divo_al.o`, `mdivo.o`, `usr/lib32/dmedia/video/DIVO.so`, `usr/dmedia/ucode/DIVO/*`, `usr/dmedia/bin/DIVO/*` | DIVO identity, firmware, flash |
| B5 | IRIX 6.5.30 overlays: `usr/etc/videod`, `usr/lib32/dmedia/arch/{directvl,videodvl}/libvl.so.1`, `usr/include/dmedia/vl_divo.h` | what the generic VL stack carries |
| M1 | SGI DMediaPro DM2/DM3 Board Owner's Guide, 007-4317-001, printed pp. 2, 6, 7, 30 | block structure (XG ASIC, GIF FPGA, address-translation SRAM, CLINK, VIF, HDOC), LVDS rate, cabling |
| M2 | SGI DMediaPro DM2/DM3 OpenML Media Library Owner's Guide 007-4505-001; DIVO Option Owner's Guide 007-3524-004 | user-visible controls only (no registers) |
| H1 | Published `hinv -mv` captures from owner posts on public forums: two posts showing one Octane2 with a DM2 (one board barcode), a for-sale post giving a DM2 assembly revision, two Tezro records listing an XT-DIGVID, 17 unfiltered and one filtered DIVO-era `hinv` outputs and three `divohinv` outputs | board names, part numbers, widget locations |
| C1 | This repository, [crosstalk-link.md](crosstalk-link.md), [xbow-family.md](xbow-family.md), [bridge-family.md](bridge-family.md) | standard Crosstalk widget register block, Bridge part and manufacturer numbers |

Decompiled C came from a Ghidra export of B1 and B2 and is navigation only. Every fact graded E
below was checked against disassembly or the object's own tables. Symbol names and strings quoted
are the ones the shipped objects carry.

## 1. Identity (DM2)

| Fact | Value | Grade |
|---|---|---|
| Crosstalk widget part number and manufacturer | part `0xc102`, manufacturer `682` (`0x2aa`). `xtdigvid_reg` calls `xwidget_driver_register(0xc102, 682, "xtdigvid_", 0)` (`xtdigvid.o` text 0xb8 to 0xc0); the same two immediates in the IP27, IP30 and IP35 objects. The argument order is part first, manufacturer second, as in the Bridge registration recorded in [bridge-family.md](bridge-family.md) (part `0xc002`, manufacturer 54) | E |
| Part and manufacturer encode in a standard widget ID word as part in bits 27:12, manufacturer in bits 11:1 | per [crosstalk-link.md](crosstalk-link.md) | E |
| Widget revision number | not visible: the driver never tests it. A revision does not appear in any `hinv` capture (the printed `version 0x0` is not the widget revision, see below) | U |
| Part number of the ASIC behind the widget | the Owner's Guide (M1 p. 6) calls the ASIC "XG"; the driver's messages name it the same way and name the bus behind it "Guava". Whether "XG" is a custom SGI ASIC or a programmable part is not stated | E for the name, U for the technology |
| Board assembly | `030-1653-002` (DM2 in the Octane2 captures, rev G and H seen); `030-1927-003` in two Tezro captures (DM3 or a later DM2 assembly, not decided) | E (captures) |
| `hinv` strings | `XT-DIGVID Multi-standard Digital Video: controller 0, unit 0, version 0x0` and, with `-mv`, `XT-DIGVID Board: barcode <serial> part 030-1653-002 rev G` at `Location: /hw/node/xtalk/10`. The first is the format `mlquery -i` prints (`XT-DIGVID Multi-standard Digital Video: controller %d, unit %d, version 0x%x`); the hinv program is not held here, so that it prints the same text is **I** (the captures show it) | E (format, captures) / I (hinv builds it from the same inventory entry) |
| Inventory entry | class 12 (`INV_VIDEO`), type 14 (`INV_VIDEO_XTDIGVID`) from the shipped ioconfig line `12 14 -1 -1 xtdigvid 0 0x6d687767`; unit number is assigned by ioconfig and exported as the `irix_unit` attribute; the ML layer's own index is the `dm_index` attribute | E |
| Slot in Octane2 | widget 10 (`/hw/node/xtalk/10`) in both Octane2 captures, with the FC board at 9 and the graphics board at 11; widget 13 in the Tezro captures | E (captures) |
| Name check at attach | the driver reads the board's NIC (a one-wire part) through the access routine at window offset `0x9c`, and requires the text `Name:XT-DIGVID`; it also accepts the text `page A data not available` ("NIC reading WAR" in its own message) | E |
| Link speed note | the driver tests bit 5 of the widget status word (window offset `0xc`) and prints "400MB/s XIO slot -- may degrade performance. Prefer 800MB/s." when set. The hardware meaning of the bit (link clock or width) is not named | E for the test, U for the meaning |

## 2. PIO window and register map reachable from the driver (DM2)

The driver maps **16 MiB** of the widget: `xtalk_piomap_alloc(widget, space 0, offset 0, size 0x1000000)`
(`xtdigvid_init_board`, text 0x884). The user ML module maps the same 16 MiB again (`mmap` of 0x1000000
bytes, shared, offset 0) through the board's device node when it programs the FPGAs. All registers are
32-bit words and every store the driver makes to the window is followed by a `sync`. Offsets are from the
window base.

| Offset | What the driver does | Grade |
|---|---|---|
| `0x04`, `0x0c`, `0x24`, `0x2c`, `0x34`, `0x3c` | the standard Crosstalk widget block (registers are the odd word of each 8-byte slot, [GIF page](dm2/gif-registers.md) section 3.0): ID (0x04, not read by this driver), status (0x0c), control (0x24), request timeout (0x2c, stored 0 once), interrupt destination upper (0x34) and lower (0x3c) addresses, per [crosstalk-link.md](crosstalk-link.md). `xtdigvid_init_xg` writes control = `(a 4-bit value from the widget, **I** its number) | (target-id & 0xf) << 22 | 0x4200`, then the interrupt destination words from the interrupt object the kernel allocates (lower address word; upper 16 address bits plus the target id at bits 19:16), then sets control bit 17 (`0x20000`) to enable the XG error interrupt after the other setup. The error handler clears control bit 17 first and re-enables nothing; the XG init routine (attach and the board-reset ioctl) is the only code that sets it ([interrupts page](dm2/interrupts-status.md) section 2) | E (stores); I (field names, from the standard block) |
| `0x5c` | packs three 8-bit interrupt vectors, graphics-video interrupt 0 in bits 7:0, interrupt 1 in bits 16:9, the XG error vector in bits 25:18, and ORs `0x20100` (bits 17 and 8) | E (stores); I (the two OR bits are per-source enables) |
| `0x64` | read-only configuration word: bits 2:0 "subsystem", bits 5:3 map-RAM size in units of 32 (printed "mapram %dk"), bits 7:6 map-RAM "type" (the driver's own debug message) | E (reads); U (what the values encode) |
| `0x6c` | XG error cause register: the error handler reads it, writes the same value back to clear it, then decodes bits (section 5) | E |
| `0x74` | read-modify-write at init: `(x >> 16 & 0x3f) << 16 | (x >> 22 & 0x3f) << 22 | 0x3f40` | E (store); U (meaning) |
| `0x94` | read after a map-RAM parity or invalid error: the offending map-RAM address, printed `%05x` | E |
| `0x9c` | NIC access register (the one-wire reader), see section 1 | E |
| `0x100000` to about `0x100000 + 4*entries` | **map RAM**: one 32-bit entry per 16 KiB page of the board's own DMA address space, at `0x100000 + (dma_addr >> 14) * 4`. A valid entry is `(v & 0x3ffffff) << 2 | 0x20000000`, where v is the page number the caller passes (the system DMA address >> 14, **I** from the call in `init_gif`); an invalidated entry is `index | 0x10000000`. `xtdigvid_write_mapram` and `xtdigvid_invalidate_mapram` (text 0x2e3ec, 0x2e380) do exactly this; the check string "(*page & ~XG_MAP_RAM_PPN_MASK) == 0" names the mask | E |
| `0x120000` | GIF FPGA programming and status register; bit 0 set means the GIF FPGA is configured (`xtdigvid_verify_gif_loaded`, text 0x5974), bit 1 is the INIT indication during programming (section 6) | E |
| `0x800000` window | the GIF FPGA's register file | E for the offsets listed |
| `0x800004` | GIF reset/enable word, cleared when `init_gif` is asked to reinitialise; polled for the value `0x80` during FPGA download (section 6) | E (access); U (bit meaning) |
| `0x80000c` | per-FPGA programming control for the seven FPGAs behind the GIF (section 6) | E |
| `0x800014` (pipe 0), `0x80003c` (pipe 1) | the pipe's DMA control word; the driver keeps a shadow (`gif_dma_control_shadow`) and rewrites the whole word. Bit 12 `0x1000`, bit 10 `0x400`, bit 9 `0x200` are set and cleared by the raster configuration; the abort path sets bits through the shadow. Initial value `0xea040` (pipe 0) and `0xa040` (pipe 1) | E (offsets, initial values); I (bit roles) |
| `0x800064` (pipe 1), `0x800074` (pipe 0) | per-pipe words cleared when the pipe's status buffer is set up, and by the clink-timeout path | E (stores and pipe assignment, [DMA part](dm2/dma.md) section 8 item 3); U (meaning) |
| `0x800084` | GIF identification: upper 24 bits must read `0x474946` ("GIF" in ASCII); the low byte is the GIF version, printed "GIF version %x". Read only by the GIF initialisation routine, which the board-reset ioctl calls after the library has loaded the GIF ([FPGA page](dm2/fpga-load.md) section 11), not at attach. Any other value fails that ioctl with "malfunction: invalid GIF version" | E |
| `0x80008c` | cleared at UST initialisation (`xtdigvid_init_ust`, text 0x9ff4), just before the host UST is sampled | E (store); U (this is the board's own UST/MSC counter, **I** from the cleared-then-sampled pattern and the message "Use hw ust") |
| `0x80180c`, `0x80200c` | video control word of each pipe, written with the second shadow word (bit 0 cleared on abort) | E (stores); I (roles) |
| `0x8038ec`, `0x8038f4` | words the ioctl and event paths touch | E (offsets); U |
| `0x880004` | data port for the seven FPGAs behind the GIF (section 6) | E |

The remaining GIF registers (raster start addresses, vid_control, vid_control2, the ixcc and oxcc
colour-matrix registers the ML module programs, CLINK registers, LUT download) are named by strings
(`start_addr1`, `start_addr2`, `vid_control`, `vid_control2`, "Failed to program ixcc coefhi register", "Failed to
program clink_pgen_lo") but their offsets live in code that was not decompiled (section 9).

## 3. Interrupts (DM2)

- **E.** Three interrupt objects are allocated with `xtalk_intr_alloc` on the widget: "xtdigvid XG err", "xtdigvid gv 0" and
  "xtdigvid gv 1". The two video interrupts are given the kernel's video priority level and are forced to the same CPU as the error
  interrupt (the driver asserts it). They are connected to `xtdigvid_xg_intr_handler`, `xtdigvid_gv_intr_0_handler` and
  `xtdigvid_gv_intr_1_handler`. The handlers pass pipe 1 (offset `0xa3b8` in the board structure) and pipe 0 (`0x50`) respectively
  to one shared service routine, so "gv 0" belongs to pipe 1 (labelled "in", the video input) and "gv 1" to pipe 0 (labelled "out").
- **E.** The XG error interrupt reads and clears the cause word at `0x6c` (bits in section 5). The video interrupts read the status
  record the board has written into host memory (section 4) rather than a register.
- **I.** The video interrupt causes the driver logs, named by its own event table in the order bits are named: VALID, INPUT_OFF,
  TRS_ERROR, OVERFLOW, IN_CHANGE, F_INTR (field interrupt), DONE_0..3, ABORTED_0..3, CURRENT_VALID_0/1, CLINK_XMIT_DONE,
  CLINK_RCV_DONE. That these are bit positions of the status flag word, and their order, is inferred from the table and from the flag
  printer; not checked bit by bit.
- **E.** Xbow arbitration: with the tunable `xtdigvid_xbow_arb_reg_enable` set (default 1), attach reads the widget number from its
  hardware-graph path and sets bit `5 + 8 * (widget & 3)` in a word in the Xbow register file: offset `0x11c` for widgets other than 12 to 15, `0x124` for 12 to 15
  (the IP30 object hard-codes the address `0x900000001000011c` and `0x9000000010000124`). The meaning of the bit (an arbitration
  priority or guaranteed-bandwidth enable) is **U**. The Origin builds also carry the tunables `xtdigvid_hub_io_crb_enable` and
  `xtdigvid_hub_io_crb_cnt` (three values `0xf 0x4 0xf`, each at most 15); not read further.

## 4. DMA (DM2)

Established from `xtdigvid_init_board`, `xtdigvid_init_gif`, the idbg dump routine and the strings of the DMA and interrupt code; the
bodies of `xtdigvid_dma` and the video interrupt service are not read (section 9).

- **E.** Two independent pipes, one for each direction; the driver's idbg dump labels pipe 1 "in" and pipe 0 "out"; each has its own state
  record of 0xa368 bytes, four DMA slots (`dma_desc[0..3]`, 0x60 bytes each), one 16 MiB `xtalk_dmamap` per slot, and a
  status page allocated with `kvpalloc` (0x800 bytes of it are mapped for the board).
- **E.** The board does not DMA through raw physical addresses. Each slot's 16 MiB map is entered into the XG map RAM (section 2) as a list of 16 KiB pages from
  the user buffer's address list (`uvaddr_to_alenlist`, `alenlist_get`, `xtalk_dmamap_list`, `xtalk_dmamap_addr`); the board's own DMA
  address for the status page is `0x8000000` for pipe 0 and `0x9000000` for pipe 1, with the pipe's data windows just below
  (`0x7ffc000` and `0x8ffc000` are invalidated at set-up).
- **E.** The board reports progress by writing a **status ring** into host memory: 16 entries of 0x80 bytes per pipe, the flag word at
  entry offset 4, a counter `status_dma_counter`, and a ring pointer the interrupt routine advances; the debug dump prints the 16 flag
  words and names each set flag from the table above. The rest of each 0x80-byte entry is **U**.
- **E.** The driver tracks per descriptor an `int_sema`, an `msc` (media stream counter), a `gif_buf_idx` and a `dma_status` (values 1,
  2 and 5 are tested), and a `dma_address`. Raster geometry (line length, field lengths, interleave, line order, progressive flag,
  MSC increment) is validated and turned into the start-address words and the control word; line length must be even in some cases
  and start addresses must fit 24 bits (the messages "start_addr1 out of range", "start_addr2 out of range").
- **I.** UST and MSC stamps: the driver stores the host UST at the field interrupt and the board's counter at DMA completion, and
  corrects "unusually quick" completions; there is a "device UST/MSC" that the interrupt reads back from the status record. How the
  board generates the stamp (field counter fed by the genlocked field clock) is not shown by the driver.
- **U.** The DMA descriptor format the host writes to the GIF to start a transfer (the slot programming at `0x180c`, `0x200c` and
  nearby), the descriptor ring depth limit (`XTHD_VIDEO_DMA_DEPTH`, named in an assertion string, value not read), the layout of the 0x80-byte
  status entry beyond the flag word, and the "valid bits" protocol (the strings "programming both valid bits now", "DMA_VALID_MASK",
  "DMA_ABORT_MASK" name them).

## 5. XG error causes (DM2)

E. `xtdigvid_xg_intr_handler` (text 0x3d180, 0xb68 bytes) tests the cause word read from `0x6c`. By bit, with the driver's own message:
0 Guava overlap; 1 Guava PIO data response overflow; 2 Guava PIO command response overflow; 3 Guava valid-when-idle; 4 Guava bad
command; 5 Guava bad interrupt; 6 Xtalk address; 7 Xtalk bad command; 8 Xtalk read request timeout; 9 Xtalk response; 10 Xtalk request;
11 graphics FIFO overflow; 12 map RAM parity (address from `0x94`); 13 map RAM invalid (address from `0x94`); 14 Guava bus command
parity; 15 Guava bus data parity; 16 Guava bus parity; 17 Xtalk request credit overflow; 18 request credit underflow; 19 response
credit overflow; 20 response credit underflow; 21 graphics cache-line credit overflow; 22 cache-line credit underflow; 23 graphics
double-word credit overflow; 25 command FIFO overflow; 26 ODMA FIFO overflow; 27 IDMA response size; 28 IDMA response invalid tag;
29 Guava write too few; 30 Xtalk write to full input FIFO. The shift amounts in the object confirm bits 1 to 23 and 25 to 30; **the message "graphics double-word
credit underflow" is printed on the same bit 22 test as the cache-line underflow message, and bit 24 is never tested** (a driver quirk; 31 messages, 30 tested bits).
The bit number of each message is E; the hardware meaning is the message text, I.

## 6. Firmware: what loads, from which file, by whom, how (DM2)

The "firmware" is **eight Xilinx FPGA configurations**, not code for a CPU. E for everything in this section unless marked.

- **Files.** `usr/dmedia/ucode/xtdigvid/<name>.mcs`, in the Intel HEX text format (the reader is `xilinx_load_intel`, message "read_intel_hex_line failed"). The root
  directory can be overridden by the environment variable `_XTDIGVID_MCS_ROOT`. The set for normal operation: `gif_1.xla` (504,169 bytes of
  HEX text), `clink` (99,681), `hdoc_sd`/`hdoc_hd` and `_fast` variants, `vif_sd`/`vif_hd`, `ixcc`, `oxcc` (895,193 each), and a family of `packer_*` and
  `unpacker_*` files, one per pixel packing (292,744 bytes each). Diagnostic builds (`diag_*`, `ixcc_2`, `oxcc_2`) ship in the diagnostics
  subset. The first data byte of a normal configuration is `0xff` and no vendor part name is visible in the bitstreams, so the FPGA parts are **U**.
- **Who.** The user-space ML module `libdigvid.so`, in the process that opens the device (loaded by `libML`; `mldaemon` only keeps the
  shared capability segment and discovers devices, it does not touch firmware). `xthd_program_xilinx(fd, name, fpga-number 0..7)` is the routine; the message
  "Loading all FPGA's with default microcode" starts it at open. The kernel driver only exposes the window (`xtdigvid_map`) and records which microcode is
  loaded for each pipe (ioctls named by the messages "SET_MCS_INFO" and "GET_MCS_INFO"); a kernel module version tag "mload version 7.0" in the driver is the
  IRIX loadable-module version marker, not a firmware loader.
- **How, GIF first.** The GIF FPGA is configured by PIO through the status/program register at `0x120000`: write `0x300`, wait 300, write `0x100`, wait
  400, write `0x300` (delays are in the unit of the library's delay helper, microseconds by **I**); require bit 0 (DONE) clear ("DONE set at start" otherwise); poll bit 1 (INIT) up to 1000 times, 4 ms apart ("INIT timed out");
  send each byte by writing it to bits 7:0 with bit 9 then bits 9:8 set (clock low, clock high), **eight times per byte, 20 units apart** (the routine
  has no shift, so the byte is written eight times; why is **U**, a bit-serial stream with eight parallel receivers is one reading); finish with ten more clock
  pairs and poll DONE (bit 0) for up to ten tries, 20 units apart ("DONE timed out"). Then `verify_gif_loaded` reads bit 0.
- **How, the other seven.** CLINK, HDOC, OXCC, UNPACKER, VIF, PACKER and IXCC are configured **through the GIF**: write the control word at
  `0x80000c` with bit 7 set (and cleared), wait, poll `0x800004` for the value `0x80`, and send bytes to `0x880004`; status words are compared with per-FPGA masks held in
  the table `xthd_fpga_info` (eight records of 28 bytes: a pointer to the name, a kind 0, 1 or 2, a byte count, and mask words). The table's contents were not dumped (**U**, small).
- **Failure shape.** Every failure prints "[xt-digvid] Failed to load <name> FPGA with image <file>" and the open fails; a missing or bad file prints "no FPGA file" or "bad FPGA file". With the kernel side, `init_gif` fails attach with "GIF FPGA not loaded" or "invalid GIF version".
- **Audit of a boot.** The GIF image must therefore be loadable before the version word at `0x800084` can read "GIF"; everything after that depends on the other seven loads
  succeeding through the GIF.

## 7. The VBOB link (DM2)

- **E (M1 p. 2, 6, 7, 30).** Two LVDS cables, A (transmit side) and B (receive side), join the board to the VBOB. They run at seven times the video clock (189 to 519.75 MHz
  for 27 to 74.25 MHz video). The CLINK FPGA "contains the LVDS channel link control and the status logic"; VIF and HDOC FPGAs hold input and output format control.
- **E.** What the host sees of the link is a **control message channel** and nothing else: `ioctl 0x68647614` (the library's `xhdVbobWriteMessage`) sends a fixed 24-byte message plus
  a word; the driver takes an exclusive "clinkack" lock, writes the message to the CLINK transmit registers, and waits for a VBOB acknowledgement interrupt
  (events CLINK_XMIT_DONE and VBOB_CLINK_ACK, timeout path "clinkack timeout unlock"). Messages the VBOB sends arrive as CLINK_RCV_DONE and
  CLINK_DATA_RCVD events and are read back by the library. A reset-path word resets the ring pointer ("reset sdma ring ptr"). Message types seen in the library (set sync state, set routing, set
  special routing, set timing, set TV standard, set genlock source, get info, get input signal, reinit): the first bytes carry a command code (for example `0xa6` for set sync state) in
  a 24-byte frame. Byte-level layouts are not decoded (**U**).
- **E.** With no VBOB (environment variable `_XTDIGVID_NO_VBOB_SUPPORT`) the library prints "Running diag version of libdigvid with no vbob support!!" and configures the CLINK FPGA to
  **generate an on-board 50 MHz clock** (messages "Failed to program clink_pgen_lo/hi"). So the board can run without the box; video I/O then has no real source or sink.
- **E.** The VBOB itself holds its own firmware, flashed by the shipped `vbob_flash` and `vbob_update1/2`: six `oxcc_N.mcs`, `csc`, `cshi`, `cslo`, `dctl`, `ecc`, `fmta`, `fmtb`, `glock`, `glue`, `hdcntl`,
  `hdoc_sd/hd`, `out`, `scxp13`, `scxp24`, `sdcntl` FPGA files plus `bootloader.bin` (a CPU boot image) and `vbobSrec*` S-record images (a firmware set for a CPU on the box).
  `VERSION` files name the release. A model can stop at the XIO side with a virtual VBOB endpoint **if** the message set the library uses is covered; **no**
  fact about the box's CPU or its internal bus is needed for that. Which messages the box answers, with what, is **U** (section 9).

## 8. Genlock (DM2)

- **E (library).** Genlock source is chosen by the library: digital jack A, digital jack B, analog, or internal (`XTDIGVID_GENLOCK_SRC_TYPE_*`); the choice is sent to the VBOB (`xhdSetVbobGenlockSrc`), the
  VBOB reports lock state and the detected input timing back, and the ML controls `ML_VIDEO_GENLOCK_TYPE`, `XTDIGVID_GENLOCK_STATE` (unlocked, locked, unknown) and
  `XTDIGVID_GENLOCK_ERROR_STATUS` (none, no signal, unknown signal, illegal combination, timing mismatch) expose it. The sync detector and the genlock generator are on the VBOB (a `glock` FPGA); no register on the
  board itself is named "genlock" in the driver.
- **E (driver).** Sync loss on a pipe reaches the host as a hardware status flag (INPUT_OFF, IN_CHANGE, "hw signal lost/gained") and a software timeout, the tunable `xtdigvid_siglost_timer` (default 175, unit not shown),
  which on expiry runs `xtdigvid_siglost_abort`: it sets the abort bit in the pipe's DMA control shadow and rewrites the control word (`0x800014`/`0x80003c`), and posts SYNC_LOST. The diag variable `XTDV_IGNORE_SEQLOST` suppresses a sequence-lost abort.
- **U.** The bit that reports "locked", how the sync-lost timer is armed in hardware, and what the board does with no genlock reference other than the on-board clock.

## 9. Unknowns, sized, and what settles each (DM2)

| Unknown | Size | What settles it |
|---|---|---|
| Bodies of the DMA start path and the video interrupt service (they are inside one 97,484-byte symbol, `xtdigvid_dma`, which also covers three unnamed static routines) | about 97 KB of code, plus 23,240 bytes in `xtdigvid_ioctl` (whose jump table the decompiler lost) | split the symbol at its internal call targets and read it with the disassembler; the ioctl dispatch by its case table. Software route, same object |
| GIF registers outside those listed in section 2 (start addresses, vid_control words, CLINK, colour-matrix and LUT registers) | about 20 offsets located so far in a 16 MiB window; the library names about 20 more registers by message | the ML module's per-register programming routines (about 15 functions in `libdigvid.so`) and the diagnostic programs (`xtdigvidtst`, `dv_*`) |
| Status entry layout beyond the flag word; flag bit order | 0x80 bytes per entry, one word known | the interrupt service routine and `xtdv_log_intrs` table, read bit by bit |
| `xthd_fpga_info` records (masks, sizes, order) | 8 records, 224 bytes | dump the table from the library data section |
| VBOB message formats and replies | about 12 message kinds in 24-byte frames; the reply side is not read | the library's `xhd*` functions and the `vbob_config` tool |
| XG revision, widget ID register readback, reset values, what bit 5 of status means | a handful of words | no shipped software reads them. Settled only by a capture of a board's status and ID words, which is a physical test and needs the agreement procedure in the repository rules; or recorded as "chosen by the model author" |
| FPGA parts, bitstream internals | 8 bitstreams | not needed to model software-visible behaviour; settled by reading the bitstream headers only if a model wanted to run them |
| Video timing, UST generation, LUT behaviour, packing and colour-space maths | n/a (data path) | a model that does not run the FPGAs must implement the packings and conversions the ML module selects; their definitions are in the owner's guides |

## 10. Verdict: is a model reachable from what the shipped software reveals?

**DM2 on Octane2: yes, at the level of the contract software relies on, and no physical hardware is needed to learn it.** Established: the widget identity, the NIC check, the 16 MiB window,
the XG control/interrupt/error contract, the map-RAM page table, the GIF identity and its programming handshake, the seven-FPGA download path, the two-pipe status-ring and interrupt
structure, and the shape of the VBOB control channel. What is not yet known is bounded and sits in code already in hand (sections 4 and 9: the DMA start and interrupt routines, about 120 KB
of object code, and about 15 library functions). Nothing in the DM2 stack runs on an on-board CPU: the "firmware" is FPGA configuration that the software downloads and never
interprets, so a model has no firmware to source. Two things remain beyond software evidence: the widget revision and reset values, and the VBOB-side behaviour beyond the messages the library sends. Both are decisions for the model author
(documented as chosen, not as measured).

**DIVO on Onyx2 (fallback): reachable but not cheaper.** See section 11.

## 11. DIVO (lower depth)

| Fact | Value | Grade |
|---|---|---|
| Bus identity | the XIO board is a **Bridge-based PCI card**: `divo_init` calls `pciio_driver_register(0x10a9, 2, "divo_", 0)`, so it is PCI vendor `0x10a9` (SGI) device `0x0002`; the init routine configures the Bridge (`divo_init_bridge`: writes to window offsets `0x214`, `0x21c`, `0x284`, `0x28c`, `0x124`, identified in the Bridge tables of this repository only as low words of 64-bit registers, **not yet matched**) and the PCI command word (`divo_init_pcicfg`) | E (ids); I (standard Bridge) |
| Widget identity | the widget behind the PCI function is a Bridge-family widget; which part number the XIO card's bridge reads is **U** (the driver registers on PCI ids, not on a widget) | U |
| `hinv` | `DIVO Video: controller 0 unit 0: Input, Output`; with `-mv`: `DIVO Board: barcode <serial> part 030-1305-001 rev E` (also `030-1046-002` rev F/H, `030-1305-003` rev A, `030-1387-001` rev E) at `Location: /hw/module/N/slot/ioK/divo`; `divohinv` adds `VL device 0 (name DIVO_0), AL subsystem DIVO_0` | E (captures) |
| Inventory | class 12 (`INV_VIDEO`), type 10 (`INV_VIDEO_DIVO`) from the shipped ioconfig line `12 10 -1 -1 divo 0 0x6d687767` | E |
| Interrupts | two per board, `divo_intr_0` and `divo_intr_1` (two pipes), allocated through `pciio_intr_alloc`; two error handlers; the interrupt service decodes "interrupt packets" from the board (`evaluate_int_packet`) and handles a "firmware panic" | E (names); U (formats) |
| DMA | PCI bus-master DMA through the Bridge (`pciio_dmatrans_addr`), buffers by the DMS fifo and block interface (`dms_block_*`, `dms_fifo_*`); "inline control" messages (`perform_inline_control`) | E (names); U (formats) |
| **On-board CPU** | the board runs firmware `usr/dmedia/ucode/DIVO/divofw`: a 32-bit big-endian MIPS ELF (mips2, entry `0x80022b14`, text and data 0x37240 bytes at `0x80000000`), with a boot PROM image `lincprom` (entry `0xbfc00000`) and a fourth image `divofw.dvc` for DVC variants. A board "linc" ASIC is initialised by `divo_init_linc` | E (headers); U (the board CPU model, memory map and mailbox) |
| FPGAs and flash | `rpc_out`, `rpc2_in/out`, `vidif_enc/dec`, `vidif28_*` `.mcs` files and 1344-byte `.pb`/`.ub` packer files (about 50, one per pixel packing); the user-space VL module `DIVO.so` programs the packer FPGAs through `divo_xilinx_load_intel` and `divo_load_vpacker`, and burns the ELF firmware and the FPGA images into on-board FLASH with `divo_flash_write_*` (checked at start, switch `_DIVO_CHECK_FLASH`); the `initdivo` boot script starts `videod` through `divo_cmd` so the flash check runs at boot ("required for DIVO audio to work, and for hinv to be correct") | E |
| Registers | none read yet. The kernel objects (`divo.a` 116 to 148 KB depending on the release) are in hand | U |

**DIVO verdict.** The PCI front door and its identity are cheap and already visible (an existing Bridge model with a PCI function 10a9:0002 would enumerate), but behind the
door sits an embedded MIPS CPU running shipped firmware over a mailbox, plus a second ASIC. A faithful DIVO model needs either a MIPS core inside the device running `divofw` with a
model of the board's bus, or a stand-in for the firmware's mailbox replies. The first is large and its board-side memory map is unknown; the second is a stand-in for firmware behaviour that the
repository rules call an approximation. DM2 has no such layer. On RE load alone DIVO is **not** the cheaper fallback; its advantages are the better-documented user-level API and the
PCI-bridge reuse. Settling DIVO needs: the Bridge writes in `divo_init_bridge` matched to the Bridge register tables, the `divo_ioctl`/`divo_dma`/`divo_intr` bodies, and a read of `divofw` itself (a 0x37240-byte MIPS program, readable with the existing MIPS tooling) to recover the
mailbox protocol and the board bus map.

## Not done in this pass

- No hinv program, no `libvl` device-dependent source other than the shipped `DIVO.so` strings, and no Discreet binaries were read here.
- The inventory tables of this repository were not regenerated: the new binaries are outside the configured scope.
- XTHD and the DM3 (Onyx 350/Tezro) objects were not compared with DM2; the 030-1927-003 capture suggests the same driver.

## Contract parts

- [VBOB control messages](dm2/vbob.md)
- [FPGA info table and load protocol](dm2/fpga-load.md)
- [DMA start path: map RAM entries, pipe control writes, start, completion, errors](dm2/dma.md)
- [Video interrupts and the status ring](dm2/interrupts-status.md)
- ioctl dispatch: every command, argument block and return code (kudzu repository, docs/dm2-ioctl.md)
- [GIF FPGA registers, XG register block and the widget block](dm2/gif-registers.md)
- Discreet's DM2 module against SGI's 1.1.3ml build (stonewire repository, docs/dm2-flame-libdigvid.md)
