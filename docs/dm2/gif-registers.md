# DMediaPro DM2 (XT-DIGVID): GIF FPGA registers, XG register block and the widget block

Status: **scoping draft, not independently reviewed.** Part of the DM2 contract set that hangs off
[xio-dmediapro-dm2.md](../xio-dmediapro-dm2.md) (its section 2 lists what the kernel driver touches; its section 9 sized
this item). Labels follow [AGENTS.md](../../AGENTS.md): **E** established (read in full from a shipped binary),
**I** inferred (reasoning given), **U** unknown (route to settle it given). Only the hardware and the shipped software's use of it are described here.

## 1. Sources and method

| Tag | Object | sha256 | Used for |
|---|---|---|---|
| L | `usr/lib32/mlmodule/libdigvid.so` (n32, MIPS, ELF32, dynamic symbols only) | `aacf8d4a64dcd34b523c4b2b7bc66153104b710171d42f7e65a588bcb95bc2ca` | every register the ML module programs |
| K30 | `usr/cpu/sysgen/IP30boot/xtdigvid.o` (ELF64 relocatable) | `952c3d9ecca0864360619236b807e38c58f5025a90e85745b956ee7a275d772b` | kernel register accesses; addresses below are `.text` offsets in this object |
| K27 / K35 | same path under `IP27boot` / `IP35boot` | `138ab5488ed6263b14582c61cf324a79929459ba62f29f92113fed36630f38ae` / `64c024a59b6b1dd7962af6d7857e83ff93ef29e498816b91c524a4d00fab1976` | compared with K30 for the points marked "all three builds" |
| T | `usr/diags/ml_xtdigvid/bin/xtdigvidtst` (n32, stripped, static data tables) | `7c96c9a69f7d2378c5a0fcbbaf55fe4bfcb8b10f429ce1900a7a09f558b01234` | register names, offsets and read/write masks (section 6) |
| F | `usr/dmedia/ucode/xtdigvid/{ixcc,ixcc_2,oxcc,oxcc_2}.mcs` | `da093d89…7fb0`, `1ab2e904…f919`, `fb82307e…ed63`, `54ac4511…04e6` | which XCC image the library and the diagnostics load |

All from the DMediaPro DM2 / DM3 software 1.1.3ml set described in the scoping datasheet. Disassembly with
`mips64-linux-gnuabi64-objdump -d` (libdigvid, xtdigvidtst) and `-dr` (kernel objects) in the retools container. In libdigvid
the call target of an indirect call is resolved through the GOT (gp value `0x427d78`; slot at `gp-32164` is
`xhdWriteWord` at `0x40d9e0`, slot at `gp-32160` is `xhdReadWord` at `0x40dbe0`), not by name, because the object is stripped. A
Ghidra export was used only to find functions, never as a fact.

Where an offset in this document is attributed to a library function, the value was read from the `li`/`ori` that feeds the
second argument of the `xhdWriteWord` call and cross-checked against the nearest failure message in the same function. Where the
diagnostic's own register table (T) gives the same offset a name, that is stated; the two agree for every register
they share (HDOC, VIF, CLINK), which is the main reason the library's message order can be trusted as a name source for the
registers T does not list.

## 2. Addressing

- **E.** The window is 16 MiB (`xtdigvid_init_board`, K30 `0x884`, per the scoping datasheet). The GIF register file starts at window
  offset `0x800000`. It is a file of **64-bit slots at an 8-byte stride; the 32-bit register is the odd word of the slot**, at
  slot base plus 4. Evidence: every library access ORs the register number with `0x800004`
  (`xhdWriteWord` at `0x40d9f8` to `0x40da10`: `lui at,0x80; ori at,at,4; or at,a1,at`; `xhdReadWord` at `0x40dbec` to `0x40dc00`;
  `hdLbPioRead32` / `hdLbPioWrite32` in T do the same), and every kernel access to the file lands on an odd word:
  `0x800004`, `0x80000c`, `0x800014`, `0x80003c`, `0x800084`, `0x80008c`, `0x80180c`, `0x80200c`, `0x8038ec`, `0x8038f4`.
- This document writes a **GIF register number** `R` (the slot offset, always a multiple of 8, as the library and T use it); the
  word is at window offset `0x800000 + R + 4`. The standard Crosstalk widget block and the XG block use the same
  convention with the file at the window base (section 4).
- **E.** The library never touches the window directly for the GIF registers: it uses the device node's ioctls. A write is
  `ioctl(fd, 0x68647602, {cmd, addr, value})` with `addr = R | 0x800004` zero-extended to 64 bits, a read is `0x68647601`.
  The kernel's write handler (`xtdigvid_eval_ioctl` at K30 `0x10750`, case at `0x1081c`) refuses an address at or above `0xc00000`
  (`lui t1,0xc0; sltu`) or not 4-byte aligned (`andi t2,v0,3`) and otherwise stores one 32-bit word at window base plus
  address (`sw t9,0(at)` then `sync`). So the register file is 32-bit only from software, and software can reach window
  offsets below 12 MiB through this path.
- **E.** With the environment variable `_XTDIGVID_READBACK` set, `xhdWriteWord` (`0x40d9e0`) reads the register back through
  `xhdReadWord` and prints "Readback mismatch at addr 0x%x, expected 0x%x, got 0x%x" when it differs; the debug variant
  `xhdDebugWriteWord` (`0x40dae0`) always compares the low 16 bits. Production does no readback. That software may
  read back a register it wrote means those registers are readable; it does not say they read back what was written.
- **E (reads).** `xhdReadWord` returns the 32-bit word; the kernel's own reads (`lw` at `0x800084`, `0x64`, `0x6c`, `0x94`) are
  32-bit. No byte or halfword access to any of these registers appears in any of the objects read. The width at the Crosstalk
  link for a narrower access is **U**; nothing in the shipped software needs it.
- **E.** Every kernel store to the window is followed by `sync`; the library has no ordering of its own (the ioctl is the
  barrier).

## 3. Crosstalk widget block and the XG error register (recheck)

The registers below are in the first 256 bytes of the window. Offsets are the odd-word offsets, i.e. slot base plus 4, as in
[crosstalk-link.md](../crosstalk-link.md) section 3.3 ("software adds 4").

| Offset | Slot | Name | What software does | Grade |
|---|---|---|---|---|
| `0x04` | `0x00` | identification | read by the diagnostic only (`hdtv_xgid`, T `0x1000ab00`): prints revision `>>28`, part `>>12 & 0xffff`, manufacturer `>>1 & 0x7ff`. The kernel never reads it | E (field split); the part value `0xc102` and manufacturer `682` come from the registration call, not from this register, so the readback value is **U** |
| `0x0c` | `0x08` | status | kernel reads it once at attach (K30 `0xa7c`, `lw a5,12(a5)`) and tests bit 5 (`sll a5,a5,26; bltz`): set means the XIO link is the slower 400 MB/s kind and the driver prints "400MB/s XIO slot -- may degrade performance. Prefer 800MB/s." No other bit is read | E (test); U (what the bit encodes; the message says link speed) |
| `0x24` | `0x20` | control (the diagnostic names it `XG_XT_CTRL`, from its messages "Writing 0x%08x to XG_XT_CTRL.(Disable interrupt)" and "(Enable interrupt)") | `xtdigvid_init_xg` (K30 `0x55c0`) writes `(own widget id & 0xf) \| (interrupt target id << 22 & 0x3c00000) \| 0x4200`, then after the interrupt setup ORs `0x20000`. The XG error handler (`0x3d180`) clears `0x20000` first (`lui v1,2; nor; and; sw` at `0x3d54c` to `0x3d574`) and never sets it again; the only setter in the kernel is `xtdigvid_init_xg` (`0x5880`), which runs at attach (from `xtdigvid_init_board`, call at `0x1488`) and again from the board-reset ioctl ([fpga-load.md](fpga-load.md) section 6.1). `hdtv_xgram` in T clears and then sets `0x20000` around its map-RAM test | E (stores); the low nibble is the widget's own number (the value comes from `xwidget_info_id_get`), bits 25:22 the interrupt target widget (from `xtalk_intr_target_get`): I from the helper names; bit 17 is the XG error interrupt enable: E for the role (the handler's own disable and the diagnostic's message), I that nothing else is in the bit; bits 14 and 9 (`0x4200`) are written constant and unexplained: U |
| `0x34` | `0x30` | interrupt destination, upper | `(addr >> 32 & 0xffff) \| (target id << 16 & 0xf0000)`, from the interrupt object the kernel allocated for the XG error interrupt | E (store); I (field names) |
| `0x3c` | `0x38` | interrupt destination, lower | low 32 bits of the interrupt address | E (store) |
| `0x5c` | `0x58` | XG interrupt vectors | `vector(gv 0) \| vector(gv 1) << 9 \| vector(error) << 18 \| 0x20100` (bytes 7:0, 16:9, 25:18; constant bits 17 and 8) | E (store). Note the common block calls slot `0x58` the auxiliary error command word or arbitration reload; in the XG it holds interrupt vectors, so that slot's common role does not apply here: E for the XG use, I that it is a deliberate divergence (no read of it exists) |

Of the other common-block slots (`0x10`/`0x18` error address, `0x28` request timeout, `0x40` error command, `0x48` LLP configuration,
`0x50` target flush), exactly one is touched: the request timeout, whose register is the odd word `0x2c` (section 3.0). It is
stored 0 once, by the routine the XG init routine calls just before it enables the error interrupt (K30 `0x5534`, store at `0x5550`;
K27 `0x548c`, store `0x54a8`; K35 `0x5438`, store `0x5454`). That routine reads the error cause word `0x6c`, prints
`%v: XG ERR_STAT==0x%x after reset.` through `cmn_err` (level 4) when it is non-zero, stores 0 to `0x2c`, then reads `0x6c` again and
writes the value back (the same write-back the error handler uses) (E, read in full). Nothing reads `0x2c`. The other four slots
are never touched by the three kernel objects, the library or the diagnostic. For them the register address is **I**
(section 3.0) and the contents **U** for the XG (settle: a capture of a real board's block, which is a physical test under the
repository's agreement rule).

### 3.0 Which word of a slot (settled)

Question: are the common-block registers at the slot bases (`0x10`, `0x18`, `0x28`, `0x40`, `0x48`, `0x50`) or at the odd words
(`0x14`, `0x1c`, `0x2c`, `0x44`, `0x4c`, `0x54`)? Answer: **the odd words**; the slot bases are never addressed.

- **E.** Every access to the first 256 bytes of the window in the three kernel objects is a 32-bit `lw` or `sw` at an offset that is 4
  modulo 8. The list, from a scan of every load and store through the window base (the 64-bit pointer at board record `+0x18`) with
  a displacement below `0x100`, each hit then read in context: loads at `0x0c` (status, K30 `0xa7c`), `0x24` (K30 `0x577c`, `0x5874`,
  `0x3d55c`, `0x24d4`), `0x64` (`0x9a8`, debug-gated print only), `0x6c` (`0x3d3f4`, `0x5538`, `0x555c`), `0x74` (`0x588c`),
  `0x94` (`0x3d9a0`, `0x3d9d4`); stores at `0x24` (`0x575c`, `0x5880`, `0x3d574`, `0x24ec`), `0x2c` (`0x5550`), `0x34` (`0x57a8`),
  `0x3c` (`0x5784`), `0x5c` (`0x5860`), `0x6c` (`0x3d5bc`, `0x5560`), `0x74` (`0x58c8`); and the one-wire accessor handed the
  address `0x9c` (`0x9f0`, `0x5e0`). K27 and K35 give the same set of offsets and widths at shifted addresses (the scan output is identical in the three objects apart from the addresses).
  No byte, halfword or doubleword access to the window exists in any of the three objects (the one halfword store the scan
  reports, in `xtdigvid_poll`, writes a poll-event structure, not the window).
- **E.** The library and the diagnostic reach these words only through the 32-bit read and write ioctls and pass the offsets
  unchanged: the library's delay helper stores to `0x6c` (L `0x4164f0`); the diagnostic's `hdXgPioRead32` and `hdXgPioWrite32`
  (T `0x1000e540`, `0x1000e5f0`) hand the caller's offset to the ioctl unmodified and their callers pass `0x24`, `0x64` and `0x6c`
  (T `hdtv_xgram` `0x1000d03c`, `0x1000d0d4`, `0x1000d104`, `0x1000d130`).
- **I.** The six slots the shipped software never reaches follow the same rule (error address upper `0x14`, lower `0x1c`, request timeout
  `0x2c`, error command `0x44`, LLP configuration `0x4c`, target flush `0x54`). The reasoning is the uniform layout of the block
  (every register the software does reach, in slots `0x00`, `0x08`, `0x20`, `0x28`, `0x30`, `0x38`, `0x58`, is its slot's odd word),
  plus the common-block description in [crosstalk-link.md](../crosstalk-link.md) section 3.3. Settled for the six by a transaction
  capture or the XG specification.
- The scoping datasheet's list of slot bases is the slot list, not a register list. Register offsets are slot base plus 4.

### 3.0a Target widget for interrupt and DMA packets

- **E (store), I (role).** The target widget of an interrupt packet is held in bits 19:16 of the interrupt destination upper word
  `0x34`. `xtdigvid_init_xg` (K30 `0x55c0`) takes the target of the XG error interrupt object with `xtalk_intr_target_get` (call at
  `0x5660`), keeps the low byte, and stores `(target << 16) & 0xf0000 | (address >> 32) & 0xffff` to `0x34` (`0x5774` to `0x57a8`),
  and the low 32 address bits to `0x3c` (`0x5784`). It asserts (`0x56a4` to `0x5734`) that the two video interrupt objects have
  the same address and target, so one destination serves the error interrupt and both video interrupts.
- **E (store), I (role).** The same target value is also stored in bits 25:22 of the control word `0x24`: `(target << 22) & 0x3c00000`
  ORed with the widget's own number in bits 3:0 and the constant `0x4200` (`0x573c` to `0x575c`). That is the only other place a target
  widget is stored anywhere in the software.
- **I.** DMA packets: the map RAM entry (dma.md section 2) holds only address bits 39:14, no widget field, and the driver writes no
  other target register, so the target widget of the board's own DMA requests can only come from control bits 25:22 (or be hardwired,
  or be implied by the address). The shipped software never states it. On every machine the DMA target and the interrupt target are the
  same widget in practice (the Octane's HEART at widget 8 for both), so no software evidence can separate the two roles. U: whether
  control bits 25:22 steer DMA. Settled by: the XG specification, a Crosstalk transaction capture of the first DMA request, or a
  second machine type whose interrupt and DMA targets differ.
### 3.1 XG-specific registers (offsets `0x5c` to `0xa0`)

| Offset | Name | Access seen | Contents | Grade |
|---|---|---|---|---|
| `0x64` | configuration | kernel: read at attach (K30 `0x9a8`, `lw v0,100(a1)`); diagnostic: read in `hdtv_xgid` and `hdtv_xgram` | bits 2:0 "subsystem", must read 1 (T message "XG CONFIG REG subsystem is NOT 1"); bits 5:3 map-RAM size code (the kernel prints `code*32` as "mapram %dk"; `hdtv_xgid` compares the code against six constants and has an "INVALID XG MAP RAM SIZE" message); bits 7:6 map-RAM type: `hdtv_xgid` (T `0x1000ab00`) indexes a three-string table with it, 0 "32K*36 bits", 1 "64K*18 bits", 2 "128K*9 bits", 3 is "XG MAP RAM TYPE is invalid". Read-only from software | E (accesses, the subsystem value and the type-to-string order); U (the size-code-to-size table: the comparisons in `hdtv_xgid` and `hdtv_xgram` were not worked out; settle by reading those two functions' size branches, a software-only route) |
| `0x6c` | error cause | kernel: read, then written back with the same value (`sw s1,108(a5)` at K30 `0x3d5bc`, before the bits are decoded), then decoded; clears happen even for bits no message tests. Diagnostic: writes 0 in `hdtv_xgram` | one bit per error, section 3.2 | E (read, write-back, decode); I that the write-back is write-one-to-clear (a plain overwrite with the value read cannot be told from it by the kernel's use; the diagnostic's write of 0 is the evidence that a write of 0 is a harmless clear request on a board with no errors) |
| `0x74` | high/low water mark | kernel `xtdigvid_init_xg` (K30 `0x588c`): `r = (r >> 16 & 0x3f) << 16 \| (r >> 22 & 0x3f) << 22 \| 0x3f40`; diagnostic table T names it `XG_HI_LO_WATER_REG`, mask `0xfffffff` | two 6-bit fields at 21:16 and 27:22 are preserved from the current value; bits 15:0 are forced to `0x3f40`; bits 31:28 forced to 0 | E (the operation and the name); I (what "high" and "low" water mark; presumably the graphics FIFO thresholds the 11 "FIFO overflow" causes refer to) |
| `0x94` | map-RAM error address | read after cause bits 12 and 13, printed with `%05x` | offending map-RAM entry address, 20 bits | E (read, format); I (read-only) |
| `0x9c` | NIC (board identity one-wire) | `nic_access_mcr32` is the accessor handed to `nic_info_get` (K30 `0x9f0` to `0xa38`, `daddiu a1,a1,156` on the window base: `0x9c`); diagnostic names it `XG_NIC_REG`, mask `0xfffc` | the one-wire control register; the driver walks the NIC with the same accessor family the Bridge and IOC3 one-wire code uses (see [binaries-scope-chip-drivers.md](../binaries-scope-chip-drivers.md)), then searches the returned text for `Name:XT-DIGVID` or `page A data not available` | E (offset, accessor, strings); U (the bit protocol of the register: it is not in this object, it is in the shared accessor; settle by reading `nic_access_mcr32` in the same kernel object and comparing with the IOC3 register layout, which is a software-only route) |
| `0x100000` and up | map RAM | see the scoping datasheet section 2 | | E |

The diagnostic's mask for `0x9c` (`0xfffc`) and for `0x74` (`0xfffffff`) means bits 15:2 and bits 27:0 read back what a test wrote
(section 6). For `0x9c` that leaves bits 1:0 as the one-wire pulse and sample bits (**I**, same layout idea as the sibling accessor).

### 3.2 The error cause bits, and the quirk

E (K30 `xtdigvid_xg_intr_handler` `0x3d180`, bytes `0xb68`). The handler tests bits by `sll s1, n; bltz` for n = 30 down to 1 after
`andi s1,1` for bit 0. The table below lists the n actually used, the bit it tests (31 - n), and the message string the branch
prints, resolved through the string offsets in the branch blocks.

| Bits | Message |
|---|---|
| 0 | Guava overlap |
| 1, 2 | Guava PIO data response overflow, PIO command response overflow |
| 3, 4, 5 | Guava valid-when-idle, bad command, bad interrupt |
| 6, 7, 8, 9, 10 | Xtalk address, bad command, read request timeout, response, request |
| 11 | graphics FIFO overflow |
| 12, 13 | map RAM parity, map RAM invalid (both print the address read from `0x94`) |
| 14, 15, 16 | Guava bus command parity, data parity, parity |
| 17, 18, 19, 20 | Xtalk request credit overflow, underflow; response credit overflow, underflow |
| 21 | graphics cache-line credit overflow |
| **22** | graphics cache-line credit underflow (first test, branch at `0x3d698`, string at rodata `+0x44f18`) |
| 23 | graphics double-word credit overflow (`0x3d6a0`, string `+0x44f50`) |
| **22 again** | graphics double-word credit **underflow** (second test, `bltz s3` at `0x3d6a8`, string `+0x44f88`) |
| 24 | **never tested** |
| 25, 26 | command FIFO overflow, ODMA FIFO overflow |
| 27, 28 | IDMA response size, IDMA response invalid tag |
| 29, 30 | Guava write too few, Xtalk write to full input FIFO |
| 31 | no test seen in the shift sequence (a direct sign test on the raw word was not looked for) |

- **E.** Bit 22 is tested twice: the register `s3 = s1 << 9` is computed once (`0x3d694`), used at `0x3d698`, kept live, and
  reused at `0x3d6a8` after the bit-23 test (`s1 << 8` at `0x3d69c`). Shift 7 (bit 24) never appears. Both messages print when
  bit 22 is set; neither prints when only bit 24 is set, although the write-back at `0x3d5bc` has already cleared it. The same
  shift sequence (30 ... 9, 8, 6 ... 1, with a duplicate use of the shift-9 register, and no shift 7) is present in K27 and K35
  (all three builds).
- **I.** The intended assignment is bit 24 = graphics double-word credit underflow (the sequence 21 / 22 / 23 / 24 is
  cache-line overflow, cache-line underflow, double-word overflow, double-word underflow, and the second message is the only
  double-word underflow text in the object). Hardware's actual meaning of bit 24 is **U**; the diagnostic never reads `0x6c` to decode
  it either. Settled by a capture where bit 24 is forced, or by the XG manual, if one is ever found.
- E: 31 messages exist, 30 tested bits; bits 0 to 30 less bit 24 give 30, and the cause for 22 has two messages.

## 4. GIF register map

Window offset = `0x800000 + R + 4`. "Who" gives the first writer or reader. The "Fields" column is what the software formula shows;
bits not mentioned are never set by software. "Mask" is the read/write mask from table T (section 6) where T lists the register.

### 4.0 Block layout

**E** (from the offsets in 4.1 to 4.5 and the diagnostic's table): the GIF register file is divided into 2 KiB blocks, one per
FPGA behind the GIF, at register number `0x800 * n`: GIF core and pipes `0x000`, packer `0x800`, unpacker `0x1000`, VIF `0x1800`, HDOC `0x2000`,
input XCC `0x2800`, output XCC `0x3000`, CLINK `0x3800`. Every register found sits inside its block. The order of the blocks is not the
order of the library's FPGA programming numbers (packer 1, unpacker 2, output XCC 3, input XCC 4, HDOC 5, VIF 6, CLINK 7), so the block
base cannot be computed from the programming number (**E** for the mismatch).

### 4.1 Core file and DMA pipes (kernel side)

Two pipes. **Pipe 0** uses the registers at `0x10`..`0x30`, **pipe 1** those at `0x38`..`0x58`; the kernel selects them by pipe
index (`movn t0,t8,t3` with `t3 = (index == 0)` at K30 `0x6838`: index 0 gets the `0x14` word). The diagnostic names pipe 0's registers
`XTHD_GIF_IDMA_*` and pipe 1's `XTHD_GIF_ODMA_*` (the XG error causes "IDMA response size" and "IDMA response invalid tag" say IDMA is the
engine that issues reads to host memory, so it feeds the video output). The [DMA part](dma.md) assigns pipe 0 to video out (HDOC side)
and pipe 1 to video in (VIF side) from the driver's own trace names; the register numbers here are E, the direction of each
pipe is **I** (names, not a traced data path). The names `IDMA_OV` (output video) and `ODMA_IV` (input video) for the two video-control words agree with that assignment.

| R | Window | Name | Access | Fields and formula | Grade |
|---|---|---|---|---|---|
| `0x00` | `0x800004` | reset/enable | `init_gif` stores 0 when asked to reinitialise (K30 `0x709c`); the FPGA load path polls it for `0x80` (see the scoping datasheet section 6) | meaning of bits U; software only ever stores 0 and polls for 0x80 | E (accesses); U (bits) |
| `0x08` | `0x80000c` | per-FPGA program control | bit 7 set and cleared around each FPGA download (scoping datasheet section 6) | | E; U |
| `0x10` | `0x800014` | **IDMA control** (pipe 0 DMA control) | `configure_raster` (K30 `0x7d40`) stores the shadow `gif_dma_control_shadow` (`2568(s7)`); `dma_abort` ORs `0x10` into the shadow and stores it (`0x14bcc`); `init_gif` stores the initial shadow `0xea040` (`lui a3,0xe; ori a3,a3,0xa040` at `0x67b0`, `0x7048`; the other pipe gets `0xa040`) and separately stores 0 (`0x6848`) | T mask `0x1e7fe0` (bits 20:17 and 14:5); raster code sets and clears bits 12, 10 and 9; bits 3:0 are per-slot valid latches, bit 4 abort and bit 16 interrupt enable are written but never kept in the shadow ([DMA part](dma.md) section 6, the object's own assertion on `DMA_VALID_MASK` and `DMA_ABORT_MASK`); all of 4:0 and 16 are outside the T mask, so the diagnostic cannot store them | E (offset, shadow, initial value); E for bits 3:0 and 4 per the DMA part; I (other bit roles) |
| `0x18` | `0x80001c` | IDMA start address 1 | `configure_raster` (`0x7dd4`) stores `start_addr1`, value must be below `0x1000000` ("start_addr1 out of range: 0x%x" at K30 rodata `+0x1228`) | 24 bits; T mask `0xfffff8` (low 3 bits not storing) | E; I (8-byte alignment) |
| `0x20` | `0x800024` | IDMA start address 2 | `0x7dec`; same range test ("start_addr2 out of range" `+0x1248`) | same | E; I |
| `0x28` | `0x80002c` | **IDMA_OV**, pipe 0 video control (the kernel's `vid_control`) | `0x7d9c`: `(a & 0xfff) \| ((b << 12) & 0xfff000) \| (lhu 2652(s7) == 0) << 24 \| (lhu 2654(s7) != 0) << 25` | 26 bits (T mask `0x3ffffff`), exactly the bits the formula sets: bits 11:0 from a 16-bit field of the pipe record (`2646(s7)`), bits 23:12 from a 12-bit argument of `configure_raster`, bit 24 set when the 16-bit field at `2652(s7)` is zero, bit 25 set when the one at `2654(s7)` is nonzero | E (formula and width); U (what the two counts and flags mean in the video path) |
| `0x30` | `0x800034` | IDMA video control 2 (`vid_control2`) | `0x7dbc`: `a & 0xfff` | 12 bits | E; U |
| `0x38` | `0x80003c` | **ODMA control** (pipe 1 DMA control) | same formulas as `0x10`; initial shadow `0xa040`; `dma_abort`/`siglost_abort` pick this word when index is not 0 | T mask `0x7fe0` (bits 14:5) | E; I |
| `0x40`, `0x48` | `0x800044`, `0x80004c` | ODMA start address 1, 2 | as `0x18`, `0x20` | T mask `0xfffff8` for `0x40` | E |
| `0x50` | `0x800054` | **ODMA_IV**, pipe 1 video control | as `0x28` | T mask `0x3ffffff` | E |
| `0x58` | `0x80005c` | ODMA video control 2 | as `0x30` | | E |
| `0x60`, `0x68` | `0x800064`, `0x80006c` | pipe 1 per-pipe words | `0x800064` is stored 0 by the ioctl that resets a pipe's status buffer (`xtdigvid_ioctl` at K30 `0xbfc4`: `movz t8,ra,t9` picks `0x64` when the pipe index is not 0) and by `init_gif` (`0x6184`); `0x80006c` is stored 0 at DMA start (`xtdigvid_dma`, K30 `0x16bf4`) | status-buffer related (the pipe's status DMA address is `0x9000000`) | E (stores); I (role) |
| `0x70`, `0x78` | `0x800074`, `0x80007c` | pipe 0 per-pipe words | same code, index 0 selects `0x74` and `0x7c`; status DMA address `0x8000000` | | E; I |
| `0x80` | `0x800084` | GIF identification | read in `init_gif` (K30 `0x5c48`); upper 24 bits must be `0x474946` (`lui ra,0x47; ori ra,ra,0x4946`), low byte is the GIF version | read-only | E |
| `0x88` | `0x80008c` | UST/MSC counter (inferred) | stored 0 by `xtdigvid_init_ust` (K30 `0xa060`) just before the host UST is sampled | | E (store); I (role) |
| `0x820` | `0x800824` | `XTHD_PACK_MISC_SEL` | not touched by the library or the kernel; diagnostic only (T) | T mask `0x5` (bits 2 and 0) | name and mask E; role U |
| `0x1010` to `0x1038` | `0x801014` ... | unpacker: `VERSION_SEL` (`0x1010`), `MISC_SEL` (`0x1018`, mask `0xffd`), `IDMA_DATA0/1_SEL` (`0x1020`, `0x1028`), `OVFIFO_TEST_PATTERN0/1_SEL` (`0x1030`, `0x1038`) | diagnostic only | mask 0 on all but `MISC` means T does not test read-back (read-only, or reading has an effect) | names E; roles U |

### 4.1a Packer and unpacker blocks (library, `xhdSendPIO`)

**E** (L `0x4087e0`, 0xb30 bytes with the HDOC routine of 4.3 as its tail; the call is `xhdSendPIO(handle, pipe, flag)` and `xhdInit` calls it once for each pipe, with `flag` 0). Values are the 32-bit words stored.
`v` is `0x1000` for pipe 1 and `0x1200` for pipe 0.

| Pipe | Window offset (R) | Value | Name where T has one |
|---|---|---|---|
| 1 (packer block) | `0x800844` (`0x840`) | `v` = `0x1000` | |
| 1 | `0x80084c` (`0x848`) | `0x1000` | |
| 1 | `0x800854` (`0x850`) | `0xd00` | |
| 1 | `0x800814` (`0x810`) | `0x1f0008` | |
| 1 | `0x800824` (`0x820`) | `1` | `XTHD_PACK_MISC_SEL` (mask `0x5`) |
| 1 | `0x800804` (`0x800`) | `0x1f0008` | |
| 1 | `0x80080c` (`0x808`) | `0x1f0008` | |
| 0 (unpacker block) | `0x801044` (`0x1040`) | `v` = `0x1200` | |
| 0 | `0x801004` (`0x1000`) | `0x160008` | |
| 0 | `0x80104c` (`0x1048`) | `0xd00` | |
| 0 | `0x80100c` (`0x1008`) | `0x32001f` | |
| 0 | `0x80101c` (`0x1018`) | `0x0fffe0f9 \| (flag << 28)` | `XTHD_UNPACK_MISC_SEL` (mask `0xffd`) |

The pairing of pipe 1 with the packer block (video in, board to host) and pipe 0 with the unpacker block (host to board) follows the pipes'
directions in the [DMA part](dma.md) and the names (**I**). The formats chosen at run time by file name (`packer_*.xla`, `unpacker_*.xla`) are
what changes pixel packing; these constants do not depend on the packing. Roles of every bit are **U**: `0x0fffe0f9` has bits outside the diagnostic's `0xffd` mask,
so those bits are either not storage or not tested.

Library-side use of the core file: none. `xhdSetPids`, `xhdIsPipeBusy`, `xhdDoTransfer`, `xhdSendBuffer`, `xhdEndTransfer` and
the path open/close routines go through the DMA and event ioctls, not through register writes (the only register writes in
`xhdOpenPath` are the CLINK reset pair, section 4.5).

### 4.2 Video input formatter (VIF) block, base `0x1800`

Programmed by `xhdCommitPathControls` (L `0x409e50`, 8,248 bytes). Names are the diagnostic's; the library's failure message for the
same register is quoted so the pair can be checked.

| R | Name (T) | Library write and formula | Fields | Grade |
|---|---|---|---|---|
| `0x1800` | `XTHD_VIF_CONTROL_SEL`, mask `0x3fff` | `0x40a698`, message "Failed to program VIF control reg". `v = (x & 1) \| (flag ? 0x10 : 0x20) \| (flag << 6 & 0x40) \| (w << 11 & 0x800) \| (nz << 12 & 0x1000) \| 0x700`, where `flag` is the second output of `mlToVlTiming` (L `0x407680`, exported; section 4.3), `w` is word 1 of the format-table row, `nz` is "(path field `1120(s0)` times a float scale, truncated, & 0x7f) is nonzero"; `x` is 0 on the path read | 14 bits: 0 (0 on the path read), 5:4 (one of two bits chosen by `flag`), 6 (`flag`), 10:8 (always 7), 11 (row word 1), 12 (nonzero test) | E (formula); U (meaning of any bit) |
| `0x1808` | `XTHD_VIF_ENABLE_SEL`, mask `0x3` | kernel: the pipe's second shadow word is stored here (`xtdigvid_dma` K30 `0x21fec`, `0x27e24`: `sw ...,6156(t9)`; `siglost_abort`/`dma_abort` clear bit 0 through the shadow) | 2 bits; bit 0 cleared on abort | E; I (bit 0 enable) |
| `0x1810` | scratch, written between accesses | the diagnostic writes `0x1810` between every write and the read-back of the other VIF registers (T `hdtv_vifregs` inner loop, `li a0,6160; Write32`) | a bus-hold or clearing write; not used by the library | I |
| `0x1828` | `XTHD_VIF_DMUX_REG_SEL`, mask `0xff` | `0x40a784`, "Failed to program VIF dmux reg". `v = (a & 7) \| (b << 3 & 0x18) \| (path field `1080(s0)` == 10) << 5 \| (c << 7 & 0x80)` | bits 2:0 a small selector (0 on the path read), 4:3 a two-bit mode (2 or 3, from the format class in `1088(s0)`), 5 set when the path field equals 10, 7 set except in one special path case (L `0x40ab30`) | E (formula); U |
| `0x1880` | f0_actvid | `0x40a8e8`, "Failed to program vif f0_actvid register": `(l0 & 0x7ff) \| ((l1 << 11) & 0x3ff800)` | two 11-bit line numbers (21:11 and 10:0), computed from the format row's line count and the path's start offsets (path `+0x44c`, `+0x458`) | E (layout); U (what each line is) |
| `0x1888` | f1_actvid | `0x40aaf4`: same layout for field 1 | | E |
| `0x1890` | lines_per_frame | `0x40ad98`, "Failed to program vif lines_per_frame register": format row word 6 minus 1 (1124 for the 1125-line HD rows) | | E |

### 4.3 HDOC block, base `0x2000`

The names below are T's (table of 25 registers). The library writes the first 12 in `xhdSendPIO` (L `0x4087e0`, called through the
GOT slot `-32216`, with the status register read first), writes the resync pair in `xhdProgramHdocResyncRegs` (L `0x4092c0`), and writes the
status register again in `xhdCommitPathControls` (`0x40ac24`, `0x40b07c`).

| R | Name (T) | Mask (T) | Library formula | Fields | Grade |
|---|---|---|---|---|---|
| `0x2000` | `XTHD_HDOC_STATUS_SEL` | `0x3ffffff` | read-modify-write with bit 24 set before the other HDOC registers are written, cleared after (L `0x408c00` to `0x408c4c`, `0x409238` to `0x409254`). `xhdCommitPathControls` builds the word from pipe flags: `(a<<17 & 0x20000) \| (b<<12 & 0x1000) \| (c<<11 & 0x800) \| (d<<10 & 0x400) \| (e & 3) \| (f<<5 & 0x60) \| (g<<7 & 0x380) \| const`, `const = 0xc8008` or `0x2c8008` by a path flag (L `0x40abd0` to `0x40ac20`), and finally ORs `0x20000` (`0x40b060`), except that on a board whose NIC part number is 1653 (`li a3,1653` against `1798(s0)`) with revision field `1796(s0)` of 3 or more (`slti a2,a2,3`) bit 17 is cleared instead (L `0x40b050` to `0x40b268`). The same part and revision test picks the HDOC image: `hdoc_hd%s.xla` / `hdoc_sd%s.xla` get the suffix `_fast` unless the part is 1653 and the revision is below 3 (L `0x407b00` to `0x407c5c`, `0x40ae38` to `0x40b0bc`) | 26 bits. Bit 24 is a hold-off during programming, bit 17 is set last | E (formula, the 24 hold, the 17 final, the 1653 / revision rule); E (the two fields are the last and middle dash groups of the NIC `Part` field, parsed by `xhdInit` at L `0x4085f0`: `1798(s0)` is 1653 and `1796(s0)` is 2 for `030-1653-002`; the "revision" of this rule is that assembly dash number, not the `Revision:` letter, see [fpga-load.md](fpga-load.md) section 13); U (field meanings) |
| `0x2008` | `XTHD_HDOC_ENABLE_SEL` | `0x1` | kernel stores the pipe's second shadow here (`0x80200c`, K30 `0x2249c`, `0x29fc4`); abort clears bit 0 | 1 bit | E; I |
| `0x2010` | format | `0x7fffff` | `(lines_total - 1) << 12 & 0x7ff000 \| (samples_per_line - 1) & 0xfff`, from format row words 6 and 7 (1125 lines, 2200 samples for 1080i/59.94) | 11 + 12 bits | E |
| `0x2018` | xcc_rden | `0xffffff` | `(active_width + 41) & 0xfff \| 0x29000` | 12 bits plus constant bits 17, 15, 12 | E (formula); U |
| `0x2020` | trs_hblank | `0xffffff` | `(active_width + (flag ? 4 : 8)) << 12 & 0xfff000 \| (flag ? 2 : 4)` | two 12-bit fields | E (formula); U |
| `0x2028` | actvid_fld0 | `0x3fffff` | `(l0 & 0x7ff) \| ((l1 << 11) & 0x3ff800)` with `l0 = k + (lines_total - path.0x44c)`, `k` is 1, 3 or 5 from the format row's word 20 (0 gives 5, 1 gives 1, others 3) | 11 + 11 bits | E (formula); U |
| `0x2030` | trs_vblank_fld0 | `0x3fffff` | same layout, from the row's `+0x28` word | | E |
| `0x2038` | actvid_fld1 | `0x3fffff` | same layout, field 1 | | E |
| `0x2040` | trs_vblank_fld1 | `0x3fffff` | same layout, field 1 | | E |
| `0x2048` | field | `0x3fffff` | same layout; value forced to 0 when the first and second operands are equal | | E |
| `0x2050` | xcc_rden2 | `0xffffff` | `(v & 0xfff) \| ((n << 12) & 0xfff000)`; normally `v = active_width + 41`, `n = 41`; when the path's geometry equals the full raster (L `0x408dc0` to `0x408e04`) `v = n = samples_per_line - 41` | two 12-bit fields | E (formula); U |
| `0x2058` | `VITC_SEL` | `0x7fffff` | not written by the library | | name, mask E |
| `0x2060` | resync | `0x7fffff` | `xhdInit` reads it (L `0x408174`, "HDOC_RESYNC readWord failed") and hands `v & 0xfff`, `v >> 12 & 0x7ff` to a `SET_RESYNC_VALUE` ioctl; `xhdProgramHdocResyncRegs` writes `(s1 & 0xfff) \| ((s0 << 12) & 0x7ff000)` (L `0x4094e4`) | 12-bit sample position and 11-bit line position | E |
| `0x2068` | resync_wndw | `0x7fffff` | `0x409588`: the same position moved by +7 samples with carry into the line count and a wrap at the line total | window around the resync point | E |
| `0x2070` | data_rden | `0xffffff` | `(active_width + (flag ? 1 : 2)) & 0xfff \| (flag ? 0x1000 : 0x2000)` | | E |
| `0x2078`, `0x2080` | `FIFOA_WEN_SEL`, `FIFOB_WEN_SEL` | `0xffffff` | not written by the library | | name, mask E |
| `0x20b0` to `0x20e8` | `LFIFO_TEST_PATTEN`, `OXCC_DATA_HI/LO`, `LFIFO_DATA`, `VIF_LB_TEST_PATTERN_LO/HI`, `DEFAULT_Y` (`0x20e0`), `DEFAULT_C` (`0x20e8`) | 0 | diagnostic only | | names E; roles U |

`flag` in the formulas is the second output of `mlToVlTiming` (L `0x407680`, a dynamic symbol of the library), which maps an ML timing
number (0 to 28) to a row of the format table and stores 1 through its second argument only for the two rows that return 2 and 3
(`VL_TIMING_525_CCIR601`, `VL_TIMING_625_CCIR601`: L `0x4076f4` to `0x407728`), 0 for every other timing. So `flag` is "standard-definition timing" (**E** for
the mapping; **I** for the name, from the two row names). The row index the formulas use is that function's return value. The pipe's timing
number is `1092(s0)`; the default 10 in the delay slot at `0x409ee0` is used when `1732(s0)` is zero.

The format table the formulas read is the 88-byte-row table at L `0x41c6d0` (rows 2, 3, 6 to 13 populated; rows 2, 3, 9 to 11 carry
`VL_TIMING_*` names). Row words: 1 progressive flag, 2 active width, 3 active lines, 6 total lines, 7 total samples per line,
8 (1 or 4), 9 first line of field 1, 10 and 12 line offsets (-1 on progressive rows), 20 the "k" selector. Only the words the
formulas above use were checked.

### 4.4 XCC blocks (input colour converter `0x2800`, output `0x3000`), two images

**E, and easy to miss:** the XCC block has two register layouts, selected by which FPGA image is loaded.

- The library loads `ixcc.mcs` and `oxcc.mcs` (the strings `ixcc%s` and `oxcc%s` with an empty suffix, L `xhdInit` `0x407e44` and `0x407bc8`;
  the library is built with `-DPROGRAMABLE_XCC`, visible in its compile line). Its register map is the "programmable" one below.
- The diagnostic loads `ixcc_2` and `oxcc_2` (T tables `hdtv_ixccregs` and `hdtv_oxccregs` list "gif_1.xla clink ixcc_2" and
  "gif_1.xla clink oxcc_2"). Its map is different: T names `0x2800` `CONTROL0` (mask `0x1ff`), `0x2808` `CONTROL1` (mask `0xff`), `0x2810`
  `LUT_CONTROL` (mask `0x1f`), `0x2818` `LUT_DATA`; for the output block `0x3000`, `0x3008` (mask `0x3ff`), `0x3010` (mask `0x1f`), `0x3018`.
  The two images are different files of the same size (895,193 bytes each; hashes in section 1).
  Which layout belongs to which image is read from who loads it, not from the bitstreams: the library's map goes with `ixcc.mcs` /
  `oxcc.mcs`, T's map with the `_2` files (**I**; the bitstreams were not opened). Nothing shipped other than the diagnostic selects the `_2` images
  (checked in the library and in `mldaemon` by name only: **U** for completeness).

Programmable layout, from `xhdCommitPathControls` (L). Register and message pairs; the message is the failure string printed on the same write.

| R | Name | Value written | Grade |
|---|---|---|---|
| `0x2810` | ixcc red offset | format-table row word 10 (full 32 bits; ixcc offsets are the unsplit word) | E |
| `0x2818` | ixcc green offset | row word 11 | E |
| `0x2820` | ixcc blue offset | row word 12 | E |
| `0x2828` | ixcc alpha offset | row word 13 | E |
| `0x2830` | ixcc misc | `(x == 0) \| (x << 8 & 0x100)` where `x` is the path's conversion mode | E (formula); U |
| `0x2838`, `0x2840` | ixcc alpha (two registers, one message) | `0x2838`: `flag ? 4 : mode`; `0x2840`: 0 if the table row index equals a path field, else 3 or the path mode | E (offsets); U |
| `0x2848` | ixcc coeflo | low 16 bits of the coefficient | E |
| `0x2850` | ixcc coefhi | bit 16 of the coefficient (`sra a2,16; andi 1`) | E |
| `0x2858` | ixcc coefind | coefficient index, `& 0x1f`; written after `lo` and `hi`, so it is the latch | E (order); I (latch) |
| `0x3010` / `0x3018` | oxcc red offset, low 16 bits / bit 16 | row word 10 | E |
| `0x3020` / `0x3028` | oxcc green offset, low 16 / bit 16 | row word 11 | E |
| `0x3030` / `0x3038` | oxcc blue offset, low 16 / bit 16 | row word 12 | E |
| `0x3040` | oxcc around | row word 13 | E |
| `0x3048` | oxcc pack8 | 1 when the component size is 8 bits | E |
| `0x3050` | oxcc dec | 0, or 3 / the pipe mode, chosen by the path | E (offset); U (formula) |
| `0x3058`, `0x3060`, `0x3068` | oxcc coeflo, coefhi, coefind | as the ixcc triple | E |

Coefficient loads: 10 coefficients from the ixcc table at L `0x41a3b0` (14-word rows, one per format id; the oxcc table at `0x41a730`),
each written lo, hi, ind; table word `i` (0 to 9) goes to index `16 + i/3 + 4*(i%3)` for `i < 9` and index 28 for `i = 9` (jump table at
`0x4191b8`, read), so words 0 to 8 are a 3x3 matrix transposed into indices 16, 20, 24, 17, 21, 25, 18, 22, 26. Then 7 filter taps from
`xtdigvid_xcc_filter_values` (`0x418268`: `0x285, -200, 0x68, -59, 0x21, -17, 6`), index `i` for tap `i` (0 to 6; jump table at `0x419218`). Both
tables have a 14-word row; words 10 to 13 are the four offsets above. **E** for the layout, **I** that the nine are a colour matrix.

LUTs (`xhdLUTDownload`, L `0x4070f0`, 564 bytes; `xhdLUTCompute` L `0x407330` builds the 8192-entry tables): control register at the block
base (`0x2800` input, `0x3000` output) and data at base + 8 (`0x2808`, `0x3008`). Sequence per component: write control `8`, write
control `{2, 4, 1}` for component 0, 1, 2, then 8192 writes of the 32-bit entry to the data register, then write control 0. **E**
(sequence). Whether the data register auto-increments the entry index, and the meaning of control values 8, 2, 4, 1, are **U** (the
8192 stores carry no index). Settle with the Y/C table maths in `xhdLUTCompute` and a read of the data register by the diagnostic's
`hdtv_ilut`/`hdtv_olut`.

### 4.5 CLINK block, base `0x3800`

| R | Name | Access | Fields | Grade |
|---|---|---|---|---|
| `0x3860` | `XTHD_CLINK_PGEN_LO_SEL`, mask `0xffff` | `xhdInit` writes `0xc3f7` right after printing "Configuring Clink to generate on-board 50Mhz clock" (L `0x407fe8`), **only when `getenv("_XTDIGVID_NO_VBOB_SUPPORT")` is non-null** (L `0x407f9c` to `0x407fa8`; the string at L `0x418680`, followed by the notice "Running diag version of libdigvid with no vbob support!!"); in normal operation the register is never written | 16-bit pattern-generator divider (low) | E (value); I (role) |
| `0x3868` | `PGEN_HI_SEL`, mask `0xff` | written 37 (`0x25`, L `0x4081b4`), under the same environment-variable condition | 8 bits, high part | E; I |
| `0x3870` | `KSYNC_SEL`, mask `0x1ff` | diagnostic only | | name, mask E |
| `0x38e0` | `UART_RESET_SEL`, mask `0x1` | `xhdInit` writes 1 then 0 ("Failed to reset clink", L `0x407f1c`, `0x407f60`); `xhdOpenPath` does the same pair (L `0x409bec`, `0x409c00`) | bit 0 = reset the CLINK UART | E (name from T, accesses from L) |
| `0x3800` to `0x3858` | 12 halfword registers | an ioctl case in `xtdigvid_ioctl` (K30 `0xbaf4` to `0xbb40`) copies 12 halfwords from the user argument into `R = 0x3800 + 8*i` (`li v0,14336; ori t0,0x4; or; sw` per halfword) | 24 bytes of a CLINK transmit message (inferred from the next store) | E (stores); I (role) |
| `0x38e8` | transmit doorbell | the same ioctl then stores 1 at window `0x8038ec` (K30 `0xbbf4`) and arms a 250-tick timeout; the board answers with status flag bit 18 ([VBOB part](vbob.md) section on the kernel handler) | | E (store); the doorbell role is E in the VBOB part |
| `0x3880` + `8k`, k = 0..11 | receive message words | read by the status-ring service routine at window `0x803884 + 8k` (K30 `0x35c00`..`0x35c4c`), low 16 bits of each kept ([VBOB part](vbob.md), receive) | 12 halfwords | E (per the VBOB part; not re-read here) |
| `0x38f0` | receive release | the service routine stores 1 at window `0x8038f4` after copying the frame (K30 `0x35c60`); `xtdigvid_post_event` stores a register value to the same word at `0x11718` and `0x11d1c` (the register, `s7`, was not traced) | | E (store at `0x35c60`); U (value stored by `post_event`) |

## 5. Kernel register accesses, completed list

All window stores by the kernel (K30; K27 and K35 carry the same `0xc0` range check and the `0x38ec`/`0x38f4` stores, counted by constant only): `0x800004`, the six DMA
registers per pipe, `0x80006c`/`0x80007c` and `0x800064`/`0x800074`, `0x80008c`, `0x80180c`, `0x80200c`, `0x8038ec`,
`0x8038f4`, the 12 CLINK halfwords, and `0x120000` (FPGA load) and the XG words of section 3. The scoping datasheet's section 2 omitted `0x80006c`, `0x80007c`, the pipe-1 and pipe-0 start-address and video-control words, and the CLINK halfword block; those are added here.

Related, not the same load path: the kernel has its own byte-load case (`xtdigvid_eval_ioctl`, K30 `0x10784` to `0x10800`, command `0x6864760e`).
It runs eight iterations, each storing `byte | 0x200` three times and `byte | 0x300` three times at window `0x120000`. The ML module's own load
(which the [FPGA load part](fpga-load.md) reads) drives the same register from user space through the mapped window; the library never
issues command `0x760e` (no such immediate in `libdigvid.so`). Which user calls the kernel's case is **U** (the diagnostic does not either).

## 6. The diagnostic's register tables (T)

`hdtv_*regs` test functions in T share one engine (T `0x1000cd08` for the GIF table): for each table entry
`{name pointer, register number, mask}` (12 bytes) it reads the register (`hdLbPioRead32`, `0x7601`, `R | 0x800004`), then for the six patterns
`0, 0xffffffff, 0x55555555, 0xaaaaaaaa, 0x33333333, 0xcccccccc` writes `pattern & mask`, reads back and compares `read & mask` with `pattern & mask`;
finally it restores the saved values. So **E** that the diagnostic expects every bit in a "mask" to behave as plain storage (its test fails otherwise); **I** that real hardware passes it, since a shipped diagnostic would not otherwise ship. This holds for the GIF/HDOC/VIF/CLINK blocks, which the diagnostic loads with the same images as production, and for the `_2` XCC images. A mask of 0 means "not tested", not "read-only".

Tables, with their masks (decoded from the T `.data` section at `0x10018808`, entry size 12):

| Block | Entries (register number: mask) |
|---|---|
| XG (`hdXgPio*`) | `0x74`: `0xfffffff`; `0x9c` (`XG_NIC_REG`): `0xfffc` |
| GIF | `0x10`: `0x1e7fe0`; `0x18`: `0xfffff8`; `0x28`: `0x3ffffff`; `0x38`: `0x7fe0`; `0x40`: `0xfffff8`; `0x50`: `0x3ffffff` |
| packer | `0x820`: `0x5` |
| unpacker | `0x1010`: 0; `0x1018`: `0xffd`; `0x1020`, `0x1028`, `0x1030`, `0x1038`: 0 |
| VIF | control `0x1800` (`0x3fff`), enable `0x1808` (`0x3`), dmux `0x1828` (`0xff`) |
| HDOC | as section 4.3 |
| IXCC (`_2` image) | `0x2800` `0x1ff`, `0x2808` `0xff`, `0x2810` `0x1f`, `0x2818` 0 |
| OXCC (`_2` image) | `0x3000` `0x1ff`, `0x3008` `0x3ff`, `0x3010` `0x1f`, `0x3018` 0 |
| CLINK | `0x3860` `0xffff`, `0x3868` `0xff`, `0x3870` `0x1ff`, `0x38e0` `0x1` |

Where the library's formula sets N bits (VIF control 14, HDOC format 23, the video
controls 26, the actvid words 22) the diagnostic's mask is exactly N bits, which is independent confirmation of the formulas' field
widths. That agreement is the evidence for the "E (formula and width)" labels above. It does not hold for the XCC block, which is why section 4.4 exists.

## 7. Reset, read, clear

- **U for hardware reset values, for every register in this document.** Software never reads a register before writing it, except
  the three read-modify-write cases (`0x74`, HDOC status, HDOC resync) and the identification words. The values software writes at
  initialisation are chosen by the driver and say nothing about reset: the pipe controls get `0xea040` / `0xa040`, the CLINK reset pair is 1 then 0, the
  XG control gets its constant `0x4200`. Settled only by a capture from a board after power-on, under the physical-test agreement.
- **Read behaviour.** The identification (`0x80`) is read-only and constant in its top 24 bits (E). The XG cause register is
  read, then written back (section 3.1). Every other register is either written without being read back (production) or only
  read back by the diagnostic under the pattern test (storage). **I** that the video-control and DMA words in a pipe are
  read/write storage; that does not cover bit 4 of the DMA control (abort) or the status-ring flag word, which the host reads from memory.
- **Clear behaviour.** Only `0x6c` has a clear protocol (read, write back). No GIF register has a read-to-clear or write-one-to-clear use
  anywhere in the shipped software.

## 8. Counts and what is left

The scoping datasheet's section 9 sized this item as about 20 located and about 20 named by string. Counting register numbers (slots) in
the GIF file with an E offset: core and pipes 18 (`0x00`, `0x08`, ten pipe words, the six `0x60`..`0x88` words), packer and unpacker 7, VIF 7 (with the
scratch slot `0x1810`), HDOC 25, input XCC 12 (ten offset, misc and coefficient slots plus two LUT slots), output XCC 14 (twelve plus two LUT slots),
CLINK 18 (`0x3860`, `0x3868`, `0x3870`, `0x38e0`, `0x38e8`, `0x38f0` and 12 message halfwords); about 100 in all, of which about 55 have a decoded
software formula or a written constant (pipe controls and video controls, VIF 6, HDOC 14, input and output XCC about 20, CLINK 6). The rest are named by the diagnostic's table
with an E offset and read/write mask and have no software use (`0x820`, the unpacker block, HDOC `0x2058`, `0x2078`, `0x2080`, `0x20b0` to `0x20e8`, CLINK `0x3870`).
The "about 40" in the scoping datasheet was an undercount because the diagnostic's table was not read then.

| Unknown | Size | What settles it |
|---|---|---|
| Hardware meaning of every control bit (video controls, HDOC status fields, VIF control bits) | about 100 bits | the Owner's Guide block descriptions (M1 in the scoping datasheet) and the bitstream's behaviour |
| XG revision and ID readback, status bit 5, reset values, bit 24 of `0x6c`, bits 14 and 9 of control | a handful | a physical capture |
| The NIC bit protocol at `0x9c` | one register | read `nic_access_mcr32` and its callers in the same kernel object; software-only |
| Control values and index behaviour of the LUT registers | 2 registers | `xhdLUTCompute` body and the diagnostic's `hdtv_ilut` |
| Format-table row words 8 and 20 and the `flag` selector | table of 14 rows | the `libdigvid` timing structures (`xhdVerifyPathConfig` at L `0x40e420`) |
| Whether the kernel ioctl read path (`0x7601`) applies the same 12 MiB and alignment limits as the write | one handler | read the `0x7601` case in `xtdigvid_ioctl` (K30 `0xaf44` carries the same `0xc00000` test, but the command dispatch to it was not traced) |
