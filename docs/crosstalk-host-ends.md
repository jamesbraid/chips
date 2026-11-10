# Crosstalk host ends: HEART, Hub and Bedrock

> **Status: PROVISIONAL.** Part of the interconnect reverse-engineering program, written
> beside [crosstalk-link.md](crosstalk-link.md) (section 5 there is the short version of this
> file). Nothing here is a hardware measurement except the owner PROM-console reads called out
> as such.
> No HEART, Hub or Bedrock specification is held, so every register fact comes from shipped
> IRIX kernels and PROMs, headers shipped with IRIX, public drivers or SGI manuals. Each fact says
> which, and carries a grade.

**What this is.** A Crosstalk (XIO) widget is a chip on a link. The *host end* is the chip
that owns the processors' route into widget space and is the target of every widget's DMA
and interrupt writes. Three exist in the families covered here:

| Host end | Machines | Board / platform | Processor interfaces |
|---|---|---|---|
| HEART | Octane, Octane2 | IP30 | 1 (up to 2 R10000-family CPUs; the register file has 4 slots) |
| Hub | Origin 200, Origin 2000, Onyx2 | IP29 (Origin 200), IP27 (Origin 2000/Onyx2 below 250 MHz), IP31 (250 MHz and above) | 1, two CPUs A and B |
| Bedrock | Origin 300/350, Origin 3000, Onyx 3000, Onyx 300/350, Onyx 4, Fuel, Tezro | IP35 (Origin 3000, Onyx 3000), IP45 (Origin 300, Onyx 300), IP53 (Origin 350, Onyx 350, Tezro), IP34 (Fuel), IP39 (Onyx 4) | 2 (PI0, PI1), two CPUs each |

II (the I/O interface) and LB (the local block) are units inside the Hub and Bedrock, not chip
names; "Hub II" and "Bedrock II" are not names of chips. Board names follow
[interconnect-naming.md](interconnect-naming.md). IP35 is also the architecture name shared by
all the Bedrock boards.

Names: the Hub and Bedrock names are SGI's (Origin Theory of Operations 007-3439-002 p28;
Origin 300 guide 007-4365-002 p10 "Bedrock ASIC (or hub ASIC)"). "Little Window (LWin)" and
"big window (BWin)" are SGI's names for the Origin address spaces (Origin Family Memory Map
007-3410-001 printed p23, p27). "Small window" is the Linux/OpenBSD software spelling for the
same 16 MB per-widget region and is not used here. HEART is named in the SGI OCTANE
Technical Report section 2.3.2; a search of that report for "widget" finds nothing, and it
gives no names for Octane's PIO address spaces, so the Octane window names below are IRIX
and OpenBSD software names and are labelled as such.

**Grades.** *established* = read in a shipped binary, a published SGI document, or a public
driver file. *inferred* = a reading, with the reasoning given. *unknown* = not settled, with
a discriminating test. A fact that no shipped binary, published document or public driver
supports is left **unknown**.

**Sources, short forms.**
- *Census*: the `chips` repository entries for each chip ([HEART](../chips/heart/README.md),
  [Hub](../chips/hub/README.md), [Bedrock](../chips/bedrock/README.md)), read from the IRIX
  6.5.30 kernels, IP30/IP27/IP35 PROMs and the IP30 diagnostic and monitor.
- *Linux*: `arch/mips/include/asm/sgi/heart.h`, `asm/sn/sn0/{hubio,hubpi,addrs}.h`,
  `arch/mips/sgi-ip27/{ip27-xtalk,ip27-init}.c`, `sgi-ip30/ip30-xtalk.c`; the IP35 tree's
  `asm/sn/sn1/{hubio,hubio_next,hubpi}.h`.
- *OpenBSD*: `sys/arch/sgi/xbow/{xheartreg.h,xheart.c,xbridge.c,hub.h}`,
  `sgi/{ip27_machdep.c,ip30_machdep.c,sginode.c}`.
- *Owner reads*: PROM-console reads of an initialized Octane2 (HEART revision F) of the
  widget identity, status, request-timeout, error-type and error-mask slots.


## Corrections (2026-11-10)

A checker raised five problems; each was re-checked against the shipped 6.5.30 kernels, the
shipped SN1 headers and the public trees. Result: four confirmed, one partly right.

- *Chip names (confirmed).* "Hub II" and "Bedrock II / LB" are gone from the host-end
  table. II and LB are units inside the chips, as [interconnect-naming.md](interconnect-naming.md)
  rules.
- *Board names (confirmed).* The table now lists IP31 for Origin 2000/Onyx2 at 250 MHz and
  above, and IP34 (Fuel), IP35, IP39 (Onyx 4), IP45 and IP53 as Bedrock boards, with the
  Onyx variants.
- *Bedrock prescale and Itanium evidence (confirmed).* The IP35 kernel's `per_hub_init` does
  store constants to `0x4003c0`: `0xfffe`, or `0x00fffffe` when a global is `0x21` or more
  (disassembly read; the global is not traced). The "Itanium port `0x1000`" and `0xff` values
  were unsupported, and the Itanium (SN2, SHub) tree is a different chip, so it is no longer
  cited for Bedrock anywhere. The Bedrock-direct-connect reading that rested on it is now
  inferred from the field name alone.
- *Interrupt-destination address note (confirmed).* The fixed PI0/PI1 addresses come from a
  note in the shipped 6.5.30 SN1 I/O header.
- *Big Window selection bits (partly right).* The 31:29 / 30:28 spans were wrong; the entry
  supplies Crosstalk address bits 33:29 (M) or 32:28 (N), five bits, as in 3.2 and as the
  shipped I/O header's 5-bit offset field says. The offset layout was already right.
- *HEART timeout unit (unknown).* Removed the PROM and kernel timeout figures that had no
  basis in the shipped objects, the revision-A skip, the graphics-board remark and the 1.28 us
  unit derived from them. The HEART kernel constants (40000 and 128) are in the
  `heart_startup` disassembly; the store destination goes through a pointer and is graded
  inferred. The unit is unknown; section 7, unknown 2 names the measurement that would settle it.

Checked from the unchecked list: the IP35 `0xff` store to `0x4003b8` and the `0x200000` stores
at offset `0x38` (three bases, one zero) are in the disassembly as described. Not checked:
the owner reads, the part `0xc110` consumer search, the manual page citations and the
widget-status pending-field position.

---

## 1. The differences in one table

| Aspect | HEART (Octane) | Hub (Origin 200/2000, Onyx2) | Bedrock (Origin 300/3000, Fuel, Tezro) |
|---|---|---|---|
| Widget part / manufacturer | `0xc001` / `0x36` (owner read of the ID word: `0x6c00106d`, revision field 6) | `0xc101`; manufacturer **unknown** (OpenBSD table `0x36`) | `0xc110` in the SN1 headers; no shipped consumer found that tests it; manufacturer unknown |
| Where the host's own widget number lives | processor-interface status register low 4 bits (read-only; 8 on Octane) | widget control low 4 bits (read/write; reset unknown); means *the Crossbow port the Hub sits on* | widget control low 4 bits; same role (an Origin 350 capture shows port `0xa`) |
| Host chip's widget face | physical `0x18000000` (widget 8, Main space) | hub-relative `0x400000`, inside Hub register window | hub-relative `0x400000` |
| Processor-to-widget routes | three fixed decodes: 16 MB per widget, 2 GB per widget, 64 GB per widget; no translation table | Little Window (16 x 16 MB) plus seven programmable Big Windows (512 MB, or 256 MB in N mode) via a 7-entry table at `0x400160` | same structure; node field one bit higher; two PIs |
| Widgets reachable | 0 and 8-F (Crossbow ports) | 0 and 8-F through the Crossbow; widget 1 slot is the Hub's own registers | same; widget 1 slot is the Bedrock's own registers |
| Interrupt landing register | HEART widget face `+0x80` (an eight-byte slot, write-only from Crosstalk) | PI interrupt-modify, node-explicit form `0x0180_0090` | PI0 `0x0180_0090` or PI1 `0x01A0_0090` |
| Interrupt number space | 64 vectors, 5 priority levels, 4 per-CPU masks | 128 numbers in two banks of 64, 2 per-CPU masks per bank | same as Hub, per PI |
| Where the vector in the packet comes from | the widget's interrupt-destination registers (upper word bits 31:24), or a Bridge's per-pin register; 6 bits used | same sources; 7 bits used | same as Hub |
| Host's own error interrupt | HEART vectors 63 (HEART exception) and 59-62 (bus error per CPU) | II interrupt destination `0x400138`: node 16:8, level 6:0 | same register, node 16:9, PI-select bit 8, level 6:0 |
| Widget-request timeout (common register `+0x28`) | implemented, no prescale, unit unknown | slot `0x400028` has no defined register | same |
| Request-buffer (widget-to-memory request) timeout | none visible | II `0x4003b8` (7:0) and `0x4003c0` (23:0 prescale) | same pair |
| PIO read-response timeout | widget `+0x28` plus read-timeout latch `+0x90` | PI request-buffer timeout `0x30` / scale `0x38`; II tail timeout `0x4001f0` (25:0 only) | adds II read-response prescaler (54:32) and timeout (59:55) in `0x4001f0`; PI `0x30`/`0x38` |
| Credit-wait timeout | none visible | II `0x4001e0` exists, layout undocumented | II `0x4001e0`, 25:0, 128-clock ticks |
| Widget status timeout flags | no timeout bits named | bit 6 tail, bit 5 credit | bit 5 tail, bit 4 credit (**differs from Hub**) |
| Credit toward the crossbar | not seen in the shipped binaries' census; unknown | widget control 15:13; reset unknown; IP27 PROM write unknown | widget control 15:13; PROM writes 4 for an integrated crossbar or Crossbow revision 3 and later, else 3 |
| Per-widget PIO credits | none visible (PIO buffer overflow flags in the cause register) | request-buffer entries `0x400198`, `0x4001a0`+8(w-8); credits 7:0, reset unknown | same offsets, wider layout |
| Error clear | write back the value read (cause, widget error type) | `0x4001f8` clear, plus per-register write-one-to-clear | same, wider layout |
| Window naming | none from SGI | LWin / BWin, IAlias | LWin / BWin, IAlias |

Sections 2 to 4 give the detail and the grade behind each cell.

---

## 2. HEART (Octane, Octane2; IP30)

### 2.1 Identity and widget number

- HEART is both a processor-memory controller and widget 8 on the Octane Crossbow (the OCTANE
  Technical Report 2.3.2 says HEART "connects to one of the ports on the Crossbow ASIC").
  Octane's Crossbow is widget 0, the BaseIO Bridge is widget 15. **Established**: IP30 kernel
  scan from widget 15 down to 0 (Census, HEART "Addresses"); OpenBSD `ip30.h`; Linux
  `ip30-xtalk.c` ("HEART is always 8").
- The widget number is HEART status bits 3:0 (`0x0ff00080`), read by the kernel and passed to
  the widget layer as the master. **Established** (kernel `heart_startup`, read in full).
  Whether the field is strapped or fixed is **unknown**.
- Identity word: owner read of one 64-bit access at physical `0x18000000` on an initialized
  Octane2 returned `0x000000006c00106d`: revision 6 (HEART "F"), part `0xc001`, manufacturer
  `0x36`, bit 0 set. **Established** for that board and moment. Which of revisions 1 to 5 (A to E) earlier boards carry is **unknown**.
- Two address blocks: the *processor-interface* block at `0x0ff00000` (MODE, memory,
  interrupt, timer, cause) and the *widget face* at `0x18000000`. The widget face has the
  nine common Crosstalk registers (`+0x00`..`+0x50`, 32-bit values in the low half of
  eight-byte slots) and HEART-specific ones above `+0x58`. **Established** (Census; OpenBSD;
  Linux `xwidget.h`). The offsets `+0x60` and `+0x68` of the *widget face* are unrelated to
  the same offsets of the processor-interface block.

### 2.2 How processor PIO reaches widget space

HEART has no programmable translation. The processor's physical address is decoded by fixed
ranges, each naming the widget in the address:

| Space (software name) | Physical range | Window per widget | Evidence |
|---|---|---|---|
| Main | `0x1000_0000 + w * 0x0100_0000` | 16 MB | **Established**: OpenBSD `ip30_widget_short`, Linux `ip30-xtalk.c`; kernel pointers at `0xb8000000` for widget 8 (Census) |
| Large | `0x8_0000_0000 + w * 0x8000_0000` | 2 GB | Unknown |
| Huge | `w * 0x10_0000_0000`, w = 1..15 | 64 GB | **Established** for use: OpenBSD `ip30_widget_long`; the range is **inferred** from that use |

- Widget 0 has no Huge window, because `0 << 36` is low memory. OpenBSD maps whole widget
  space through Huge ("On Octane, the whole widget space is always accessible") and falls
  back to Main for widget 0 and for every identification read. **Established**.
- Access goes through uncached K1/xkphys addresses. A MODE bit enables cached PIO
  (bit 18) and another enables cached PROM (bit 17); the kernel path uses uncached.
  **Established** names (Linux `heart.h`, monitor table); effect of bit 18 **unknown**.
- Octane has *no* Big-Window equivalent: a 64 GB Huge window per widget replaces
  programmable slices. This is the largest structural difference from Hub and Bedrock.
- HEART has no Hub-style "IAlias" for its own registers: they are at fixed physical
  addresses and need no node number. **Established** by absence in every consumer.

### 2.3 Interrupt landing and encoding

- A widget sends its interrupt as a Crosstalk write to **HEART widget offset `0x80`**, with
  target widget 8. Both operating systems program exactly this: OpenBSD
  `xbow_intr_address = 0x80`, Linux `HEART_INTR_ADDR 0x80`.
  **Established**. The slot is writable from Crosstalk and is not a processor-visible
  register in the PROM or kernel (Census: no held code touches it). Its width and neighbours
  are **unknown**.
- The vector (0-63) is the number of the HEART interrupt-status bit to set. The kernel
  allocator picks the vector and the dispatcher acknowledges a vector `n` by writing `1 << n`
  to the clear register. **Established** (Census `heart_intr`, `do_heart_intr_alloc`).
- In the widget's destination-upper word the vector is bits 31:24, the target widget bits
  19:16 and the high address bits 15:0. **Established** (common block; Linux/OpenBSD headers).
- **Data encoding** (vector in data 7:0, assert in bit 8) is the Crosstalk interrupt packet
  as the Bridge and Crossbow specifications give it. That HEART honours a *deassert* (clear)
  packet is **inferred**; HEART's own set, clear and pending registers are the processor-side
  mechanism and no held code relies on a deassert write. Test: see the unknown list.
- Interrupt state: 64 sources; mask registers `0x10000 + 8n` (n = 0..3), set `0x10020`,
  clear `0x10028`, status `0x10030`, masked status `0x10038`, cause `0x10040`. Levels: 63-51
  level 4 (HEART exception, four per-CPU bus errors, widget errors), 50 level 3 (timer),
  49-32 level 2, 31-16 level 1, 15-0 level 0. **Established** (OpenBSD, Linux, kernel and
  monitor tables). Widget error vectors are `51 + ((w + 7) & 7)`: widget 0 gets 58, widgets
  9-15 get 51-57, and widget 8 also computes 58. **Established** (`do_heart_intr_alloc`).
- HEART has no separate interrupt-modify register: set and clear are the interrupt registers
  in its own space.

### 2.4 Timeout and prescale

| Register | Offset | What the code shows | Grade |
|---|---|---|---|
| Widget request timeout | widget `+0x28` (32-bit value at `+0x2c`) | Owner PROM read returned `0x28` (40).  The IRIX 6.5.30 kernel `heart_startup` loads the constant 40000 and, when a debug flag is set, the constant 128 (both seen in the disassembly; the register they are stored to is reached through a pointer and was not confirmed as `+0x28`); the GIO bridge attach path raises it to at least 128 (not rechecked). | owner read and kernel constants **established**; destination of the kernel store **inferred**; unit **unknown** |
| Prescale | none | No HEART prescale register exists in any header or held binary. | **established** absence in held code; **unknown** in silicon |

- **Unit.** **Unknown.** No held specification gives the tick. The Crossbow's own packet
  timeout is 1.28 us per count (Crossbow sheet), and crosstalk-link.md records 960 ns per
  count for the common register on a Bridge (Bridge specification), so the unit is per widget
  and may differ for HEART. Test: a timed uncached read to an empty widget address on
  hardware at two programmed values.
- What the timeout bounds is the processor's PIO *read*: expiry latches the failing
  address in the read-timeout register (below) and sets widget error type bit 3.
  **Established** names and latch layout; that expiry is the only trigger is **inferred**.
- The kernel's error mask leaves bit 3 (read timeout) off, so a timed-out read reaches the
  program as a bus-error exception instead of a widget error interrupt. **Inferred** from the
  mask value; the kernel's probe routines treat "bus error pending or cause bit 16" as failure.

### 2.5 Error registers

Widget face, all 64-bit slots (Census; names from the monitor decode table at kernel/monitor
addresses given there):

| Offset | Meaning | Clear rule | Grade |
|---|---|---|---|
| `+0x10`, `+0x18` | common error address, upper (16 bits) and lower | read-only by use | inferred |
| `+0x40` | common error command word; probes zero it before each access | write zero | inferred |
| `+0x60` | widget error type; bit names below | kernel writes back the value read | established names, inferred clear rule |
| `+0x68` | widget error mask (enable) | plain write | inferred |
| `+0x70` | failed PIO latch, upper: bits 7:0 address 39:32, 23:22 processor, 15 read/write flag (sense inferred) | cleared with error type | established fields |
| `+0x78` | failed PIO latch, lower: address 31:0 | | established |
| `+0x90` | PIO read-timeout latch: bits 19:18 processor, 15:12 widget port, 11:0 address bits 23:12 | | established fields |

- **Error-type bits** (monitor decode table): 0 PIO write-control-register access error, 1
  PIO Crosstalk access error, 2 PIO write timeout, 3 PIO read timeout, 12 LLP transmit retry, 13 retry timeout, 14 LLP squashed data, 15 LLP check-bit error, 16 LLP
  sequence-number error, 17 link reset received, 18 warm reset received, 20-23 interrupt-vector
  and command warnings and errors, 24 response-buffer overflow, 25 unexpected response, 26 bad
  format, 27 non-head, 28 and 29 Crossbow credit underflow and overflow. **Established**
  names and positions (monitor table). The meaning of bits 10 and 11 and of "WCR" in bit 0 is **unknown**.
- **Masks.** The owner's board read back `0x3ff7fc0f` after PROM start (which bits the PROM wrote
  is not traced). The 6.5.30 kernel stores `0x3ff62c07`.
  The difference is bits 3, 12, 14, 15 and 16: read timeout and four LLP events are left
  to the processor bus-error path and to counting. **Established** values and arithmetic;
  the reading of why is **inferred**.
- **Processor-interface side.** Cause bit 16 flags a widget error; 40 and 41 bad system
  read and write; 42 a bad access to the processor-interface block (latched in the access
  error register with processor and offset); 43 and 44 overflow of the PIO read-write response
  buffer and the PIO write-data buffer. Bus-error address and misc registers hold the address (39:0) and processor
  (bits 22:21). The two sets (cause and widget type) are consulted together by the kernel's
  bus-error routine. **Established** (Census error section).
- What a store to an address no widget claims sets is **unknown**: the kernel's write probe
  expects either the processor interrupt line or cause bit 16.

### 2.6 Credits

- HEART's link to the Crossbow is port 8. What the PROM writes to the Crossbow's link-control
  credit field for port 8 and to HEART's own widget control register is **unknown**: the
  census sees no such store.
- The shipped binaries' census sees no access to HEART's widget control (`+0x20`): the
  diagnostic lists it with mask `0xffffffff` and no code writes it. Whether the shipped PROM
  writes it through a pointer the census scan does not follow is **unknown**. Test: read the
  PROM's HEART bring-up routine for a store at widget `+0x20`, or an owner read of `+0x20`
  after PROM start.
- Credit errors are widget error type bits 28 and 29; the kernel treats both as fatal.
  **Established** (Census error paths).
- PIO flow control inside HEART is visible only as cause bits 43 and 44 (overflow).
  Buffer depths are **unknown**. There is no per-widget PIO credit register.

---

## 3. Hub (Origin 200, Origin 2000, Onyx2; IP27 / IP29)

### 3.1 Identity and widget number

- Part `0xc101` (Linux header, OpenBSD table). Manufacturer 11:1: OpenBSD's table groups the
  Hub with the Bridge and HEART under `0x36`; that is a published table, not a measurement. **Unknown.** Test: read the low word of the Hub widget face
  through the Crossbow from a peer, or the local register at `0x400000` (a local read answers
  the question without a peer).
- Bit 0 reads one: common widget convention (Bridge and Crossbow specifications).
- **Two different "widget 1"s must not be confused.** (a) Widget slot 1 of the *processor's*
  Little Window is where the Hub maps its own register file (section 3.2). (b) The widget
  control register's low four bits (`0x400020`) name the *Crossbow port the Hub is plugged
  into*. The 6.5.30 kernel (`hub_widget_id`) reads them once per node and
  passes the result to every Bridge it masters as the interrupt and DMA target widget.
  **Established** (kernel disassembly, Census). The reset value and who writes the
  field are **unknown**. The node PROM's own Bridge setup uses a slot-to-widget
  table that gives 0xa on an Origin 200, and Linux hard-codes master widget 0xa for a directly
  attached Bridge, so a reset of 1 disagrees with what the PROM programs for that
  configuration. Test: read `0x400020` before any firmware write.

### 3.2 How processor PIO reaches widget space

Uncached I/O space (the uncached-attribute value `01` binary, printed p23), per the Origin
Family Memory Map 007-3410-001:

- **Little Window** (printed p23, p27): lowest 256 MB of a node's I/O space = 16 windows of
  16 MB, one per widget 0..F. The next 256 MB aliases it. Widget `w` at `w << 24`
  (A[27:24]); A[31:28] must be zero. **Established.**
- **Big Windows 1..7** (p23, p32-33): the remaining seven 512 MB spaces in M mode (256 MB in
  N mode). Each maps through a translation entry to a 512 MB-aligned slice of any widget's
  Crosstalk space. Linux numbers entries 0..6; SGI numbers windows 1..7. **Established.**
- **Translation table** at `0x400160 + 8n`, n 0..6: bit 12 selects the widget's memory (0) or
  I/O/device (1) space, bits 11:8 the widget, bits 4:0 Crosstalk address bits 33:29 (M mode)
  or 32:28 (N mode). **Established** (Linux, OpenBSD, kernel `0x400160`
  routines in Census). Seven windows cover only seven widget-slices at once, so widget space
  above 16 MB is reached by repointing entries.
- **Widget 1 holds the Hub itself.** Its 16 MB are two 8 MB halves: IAlias at `0x0100_0000`
  (node field not checked, reachable only from local processors) and Hub at `0x0180_0000`
  (node field checked, remote access allowed). Each half is four 2 MB regions: processor
  interface (+0), memory/directory (+`0x20_0000`), I/O interface (+`0x40_0000`), network
  interface (+`0x60_0000`). **Established** (007-3410-001 p28-31, figures 3-2, 3-3, 3-4;
  Census). Kernels reach it at `0x9200_0000_0100_0000 + offset` (local) or
  `0x9200_0000_0180_0000 + (node << 32) + offset`.
- **Node field.** The destination node is in SysAD A[39:32] in M mode (007-3410-001 p31,
  p33); OpenBSD computes the shift as `32 - N` (A[38:31] in N mode). **Established** for M
  mode; N mode from OpenBSD only (**inferred**).
- **Which widgets exist.** Only widgets 0 and 8..F are addressable on the Crossbow
  (007-3410-001 p32). Widget 0 short-window access is unreliable on early Hub silicon: the PROM
  remaps widget 0 through the last Big Window (entry 6, window 7) and OpenBSD does the same
  (Linux `SWIN0_BIGWIN`). **Established** (OpenBSD comment and code, Linux).
- Widget accesses are qualified by two 16-bit masks (outbound `0x400110`, inbound `0x400118`;
  bit 0 widget 0, bits 15:8 widgets 8..F) and a 64-bit local-access-protection register
  (`0x400100`, reset unknown). The stock PROM writes `0xff01` to both
  widget masks. **Established** (Census, Hub I/O sheet).

### 3.3 Interrupt landing and encoding

- Landing: the PI **interrupt-modify** register at PI offset `0x90`. A widget interrupt is a
  Crosstalk write whose address is XIO bit 47 set, destination node at XIO bit 38, offset
  `0x0180_0090` (node-explicit Hub half, PI region, `+0x90`). Linux builds it as
  `BIT(47) + 0x01800000 + PI_INT_PEND_MOD`; OpenBSD derives the same number from the register
  address. **Established** (two independent public derivations agree; 007-3410-001 gives the
  Hub half base).
- Data: bits 6:0 interrupt number, bit 8 set (1) or clear (0). Numbers 0-63 address pending
  bank 0 (`0x98`), 64-127 bank 1 (`0xa0`). **Established** (Linux `PI_INT_PEND_MOD`, OpenBSD
  `PI_IR_SET 0x100`, Census `intr_connect_level`). The *sense*
  (set versus clear on bit 8) is **inferred**: no held code reads it back.
- Where the vector in the packet comes from: the bridge's per-pin register holds the
  interrupt number in its low 8 bits and the high address bits above (OpenBSD
  `xbridge.c`: `((xbow_intr_address >> 30) & 0x3ff00) | intrsrc`), and the bridge's widget-wide
  destination registers carry the rest of the address and the target widget (the Hub's
  Crossbow port, section 3.1). Detail belongs to the Bridge sheet.
- Masks: four per-CPU registers, `0xa8`/`0xb0` for CPU A banks 0/1 and `0xb8`/`0xc0` for B.
  **Established** (Census; Linux and OpenBSD agree on the offsets).
- **The Hub's own errors** use a separate II register, `0x400138`: bits 6:0 level, 16:8 node,
  24 enable, 28 sent. The II sends the same kind of packet to the same `0x90` register.
  **Established** (kernel `hubii_eint_init` read in full; Linux has contradictory narrow masks
  and a wide bit-field; the wide one is right, the cleared Hub I/O sheet gives the reasoning). Levels 0-9 and
  103-106, 121-127 are reserved by the kernel; the II error level is allocated at run time
  from 64 upward (**inferred**: probably 64).

### 3.4 Timeout and prescale

The Hub has **no defined common widget request timeout**: Linux uses the name of slot `0x400028` in
an alias macro without ever defining the address. Instead there are separate mechanisms:

| Register | Offset | Layout | What the code shows | Grade |
|---|---|---|---|---|
| II request-buffer ("CRB") timeout | `0x4003b8` | 7:0, reset unknown | IRIX 6.5.30 IP27 `per_hub_init` writes `0xff`; Linux writes `0xff` | established values |
| II request-buffer timeout prescale | `0x4003c0` | 23:0 | IRIX 6.5.30 writes **`0x1000`**; Linux writes **`0x800`** with a comment: 5 ms, "less than the processor-interface timeout of 10 ms" | established values; unit **unknown** |
| PI maximum request-buffer timeout | PI `0x30` | 7:0, reset unknown | IRIX writes `0xd0` or `0xfe` depending on two kernel conditions | values established; conditions not read |
| PI request-buffer scale factor | PI `0x38` | 23:0 on Bedrock; Hub width and reset unknown | IRIX writes `0xd400` or `0xc000` with the matching value above | values established |
| II tail timeout | `0x4001f0` | 25:0, reset unknown | no held code writes it | layout inferred |
| II credit-count timeout | `0x4001e0` | undocumented | no held code writes it | unknown |

- **Correction.** The II pair at `0x4003b8`/`0x4003c0` times out entries in the II's request
  buffer table (the "CRB": requests widgets make toward memory, i.e. coherent DMA requests).
  It is *not* the processor's PIO read timeout, and calling it a "Crosstalk timeout" (as
  crosstalk-link.md did) misdescribes it. Linux names it "CRB Time Out" and "CRB Time Out
  Prescalar". **Established** names; scope **inferred** from the register name, the CRB
  error code "CRB timeout before deallocating" and Linux's comment.
- The processor's PIO to a widget goes through the PI's read and write response blocks; their
  timeout (the PI pair above) produces the PI error types "write response block, timeout
  error" and "read response block, timeout error". **Established** (shipped decode text,
  Census "Error reporting for a refused or timed-out write"); trigger conditions
  **unknown** (no held code causes one).
- Timeout tick units for all four registers are **unknown**; only Linux's 5 ms intent exists
  for the prescale/timeout pair, and IRIX writes twice that prescale.

### 3.5 Error registers

- II widget status `0x400008`: bit 32 "crazy" (link failure), 23:16 transmit retry count
  (write-one-to-clear; Linux's extraction macro takes seven bits), bit 9
  transmit max-retry, **bit 6 tail timeout, bit 5 credit timeout**, 3:0 pending requests.
  **Established** (kernel decode strings, Census `hubii_eint_handler`).
- `0x4001e8` shutdown flags (bit 0 widget 0, 4 BTE0, 8 BTE1; read), `0x4001f8` error clear
  (`0xffffff` after service), `0x400198`/`0x4001a0`+ PIO request buffers (bit 48 write response
  packet error), `0x400400`..`0x4005d8` request-buffer entries (error code 55:52 selects a
  printed name: directory, poison, write, access, partial write, partial read, timeout,
  Crosstalk error). **Established** (Census).
- PI side: error interrupt pending `0x400` (cause line IP6), masks `0x408` (A) and `0x410`
  (B), per-CPU error status 0 and 1 at `0x430`/`0x440` and `0x450`/`0x460`, error stack
  address/size. A failed uncached **read** also raises a bus-error exception; a failed write
  raises only the error interrupt (**inferred**, Census error section item 5 is open).
  **Established** latches.
- II error interrupt `0x400138` as in 3.3.

### 3.6 Credits

- Hub widget control `0x400020`: 22:18 elasticity threshold, 17 direct-connect, 16 force bad
  packet, **15:13 crossbar credit**, 4 tag mode, 3:0 own Crossbow port. **Established**
  fields (Linux); the reset value is **unknown**.
- The 3-or-4 credit rule by Crossbow revision is **established** in the IP35 PROM for Bedrock
  (4.6); for IP27 it is **unknown**.
- Per-widget PIO credits: request-buffer entry `0x400198` (widget 0) and `0x4001a0` + 8(w-8),
  low 8 bits credits, reset unknown; fields for NACK counters, mode, fire-and-forget,
  overflow count and error. **Established** layout (Linux); behaviour **unknown**.
- Crossbow side: link-control widget credit (22:18, reset 2) for the Hub's port, per the
  Crossbow sheet. Whether any IP27 firmware writes it for a Hub port is **unknown**.

---

## 4. Bedrock (Origin 300/350, Origin 3000, Onyx 4, Fuel, Tezro; IP34 / IP35 / IP39 / IP45 / IP53)

Bedrock is a Hub successor with two processor interfaces. Evidence is thinner: only the IP35
kernel, IP35 PROM, SN1 headers (IRIX and an out-of-tree MIPS Linux port) exist. The Itanium
(SN2, SHub) Linux tree is a different chip and is not evidence for Bedrock.
Where Bedrock matches Hub the statement is a hypothesis (a sibling chip is a neighbouring row,
not evidence) unless a Bedrock consumer is named.

### 4.1 Identity and widget number

- Part `0xc110` in the SN1 headers; OpenBSD's table lists `0xc110` "Bedrock" under `0x36` and
  the Hub `0xc101`. No shipped or public consumer was found that tests the Bedrock constant.
  Revision and manufacturer are echoes of the local-block revision register (SN1 header).
  Part **established as a table entry**; value on silicon **unknown**. Test: read `0x400000`.
- Own widget number: widget control (`0x400020`) low four bits. The out-of-tree Linux port
  reads them as "the port to skip when walking the crossbar". On an Origin 350 capture the
  Bedrock is crossbar port `0xa` and the master check reports "link 10 is master". The two PICs
  of a Tezro sit at ports `0xb` and `0xf`. **Established** (Census question file on Tezro
  widget 0xb; public capture).
- Bit 17 of widget control ("direct connect") tells software the neighbour is a Bridge/PIC
  with no crossbar. The held Bedrock consumers do not read it for that purpose, so this is
  **inferred** from the field name alone.

### 4.2 How processor PIO reaches widget space

Same Little Window / Big Window structure as the Hub, with these differences:

- **Two PIs.** Each hosts two processors (A,B) and its own full register file. The Bedrock PI0
  is at `0x0180_0000` and PI1 at `0x01A0_0000` in the node-explicit half (a 2 MB step; on the
  Hub that slot is the memory/directory region, so where Bedrock puts that block is
  **unknown**). OpenBSD's second-PI offset is `0x200000`;
  the IP35 kernel visits a second PI file `0x200000` above the first. **Established**
  (Census, OpenBSD `HUBPI_OFFSET`, and the interrupt-destination note in the shipped 6.5.30 SN1 I/O header). The local form
  (`0x0100_0000`, no node) is assumed by OpenBSD to reach the requester's own PI; no header
  states it. **Unknown.** Test: PIO from a processor on PI1 to `0x9200000001000090` and read
  back which PI's pending bank changed.
- I/O interface at `+0x400000` in the Hub half (kernel local alias `0x1400000`, node-addressed
  `0x1c00000`), network interface at `+0x600000`. **Established** (Census). Widget face at
  hub-relative `0x400000`. Every register is 64-bit.
- **Node field one bit higher**: OpenBSD `kl_n_shift = (IP35 ? 33 : 32) - N`, and the
  Crosstalk-side node position in the interrupt address is bit 39 (Hub: 38). **Established**
  (public). Big Window size is 512 MB in M mode and 256 MB in N mode, the entry supplies Crosstalk
  address bits 33:29 (M) or 32:28 (N), as in 3.2. **Established** (Bedrock I/O sheet reading of
  the SN1 header).
- Same translation-table offset `0x400160` (seven entries, bit 12 space, 11:8 widget, 4:0
  slice; the 5-bit offset width is in the shipped 6.5.30 I/O header). **Established**
  (OpenBSD reads and writes them on IP35).
- The widget-access masks, local-access protection and device error mask have the Hub
  offsets and layouts (`0x400100`..`0x400120`); the stock PROM writes `0xff01` to both widget
  masks. **Established** (Census, Bedrock I/O sheet).
- A graphics node-widget map (`0x400140`, `0x400148`: widget 3:0, PI 4, node 12:5, slot 16)
  routes a graphics widget's write responses back as credits to a named node, PI and slot.
  Hub's version (`0x400140`) has no PI field. **Established** layout (kernel graphics
  routine, SN1 header).

### 4.3 Interrupt landing and encoding

- Landing: **PI0 `0x0180_0090` or PI1 `0x01A0_0090`**, plus the node at XIO bit 39 and bit 47.
  The addresses are fixed in the II interrupt-destination logic (a note on the II error
  interrupt destination register in the shipped 6.5.30 SN1 I/O header; the SHub header repeats it
  but SHub is another chip). OpenBSD aims every IP35 widget interrupt at PI0 by reusing the Hub formula
  with the shift raised to 39. **Established** (public sources agree).
- Data: bits 6:0 level/number, bit 8 set or clear. Same pending banks `0x98` and `0xa0` per
  PI; bank 1's low 32 bits can be remapped from level 3 to level 2 (`0xf0`). **Established**
  (SN1 header, OpenBSD).
- Which PI a given device's interrupts reach is set by the address the widget was told, so
  per-device choice of PI is a software decision. **Established**.
- Own error interrupt: II `0x400138`, bits 6:0 level (seven bits, not six), **8 PI select**,
  16:9 node, 24 enable, 28 sent, 32 and 33 forwarded-interrupt pending for PI0 and PI1.
  **Established** (kernel `hubii_eint_init` and Census; contradicts Linux's Hub header).

### 4.4 Timeout and prescale

| Register | Offset | Layout | Evidence | Grade |
|---|---|---|---|---|
| II request-buffer timeout | `0x4003b8` | 7:0 | IP35 kernel `per_hub_init` stores `0xff` (disassembly) | established |
| II request-buffer prescale | `0x4003c0` | 23:0 | IP35 kernel `per_hub_init` stores `0x00fffffe` when a global count is `0x21` or more, else `0xfffe` (disassembly; what the global holds is not read) | values established; unit unknown |
| II credit-count timeout | `0x4001e0` | 25:0 | counts 128-clock ticks while outbound credits are below 1 (direct) or 2 (crossbar); saturates and raises one interrupt (SN1 header) | layout established; no consumer |
| II tail timeout | `0x4001f0` | 25:0 | SN1 header | layout established |
| II read-response timeout | `0x4001f0` | prescaler 54:32, timeout 59:55 | SN1 header; unit unknown | layout established |
| PI request-buffer timeout and scale | PI `0x30` (7:0), `0x38` (23:0) | reset not given | SN1 header | layout established |

Bedrock's header documents a programmable read-response timeout (the `0x4001f0` fields) that
works on an eight-entry "PIO read address table" at `0x400308` + 8n whose entries carry a
timeout count (62:58). Layout **established** from the header, behaviour **inferred**. The
Hub's Linux header names the same table (`IIO_PRTE_0`, eight entries) with no timeout field
and its tail-timeout register has no read-response fields; whether Hub silicon has the
Bedrock fields is **unknown**.

### 4.5 Error registers

- Widget status `0x400008`: 3:0 pending, **bit 4 credit timeout, bit 5 tail timeout**,
  9 transmit max-retry, 23:16 retry count, 32 "crazy". **Established** (kernel decode
  strings; this swaps relative to the Hub).
- Error clear `0x4001f8`: bit 0 request buffer 0, 15:8 buffers 8..F, 16 crazy, 17 and 18 BTE0 and
  BTE1, 28 internal, 29 spurious read header, 30 and 31 forwarded-interrupt bits.
  **Established** layout. Request-buffer entries `0x400198` + 8i (i 0..8; entry 0 widget 0,
  1..8 widgets 8..F): 48 error, 49 read timeout, 50 spurious write, 51 spurious read, 63
  multiple errors. **Established.**
- Per-PI error pending `0x400` (35 bits, two sides A and B), masks `0x408`/`0x410`, spool
  address/size `0x418`..`0x428`, status 0/1 for each side, spurious message headers
  `0x4c8`/`0x4d0`, all at PI0 base and again at +`0x200000` for PI1. **Established** (Census
  graded table).

### 4.6 Credits

- Widget control 15:13 "destination credits": the IP35 PROM writes **4** for an integrated
  crossbar (part `0xd000` or `0xd100`) or a Crossbow of revision code 3 and later, else 3.
  **Established** (PROM disassembly cited in the Bedrock I/O sheet).
- Per-widget PIO request-buffer credits (7:0) as for the Hub.
- Crossbow side per-link widget credit: PROM sets per-part values for a bridge-class widget
  (PIC `0xd102` credit 3, from a PROM table). **Established** (Tezro question file).
- Credit-count timeout `0x4001e0` as in 4.4.

---

## 5. What is genuinely common, and what is not

Common to all three (**established** unless noted):

1. A widget interrupt is a Crosstalk write to a host register chosen by software; the packet
   carries a vector and a set/clear bit; the host sets a pending bit. Only the register
   address, the number space and the count of landing registers differ.
2. The widget face of the host chip carries the standard identification word at the same
   offset as every widget (rev 31:28, part 27:12, manufacturer 11:1, bit 0 = 1).
3. Processor access to a widget is uncached and routed by widget number with no translation
   inside the Crossbow.
4. The host end, not the target widget, times out a processor PIO read and logs the failing
   address.

Not common (the table in section 1 has the rest):

- Programmability of the processor-to-widget map: HEART fixed, Hub and Bedrock windowed.
- Who owns the common request-timeout register: HEART implements it (`+0x28`); Hub and
  Bedrock do not, and use PI and II registers instead.
- The status flag positions for tail and credit timeouts (Hub bits 6 and 5, Bedrock bits 5
  and 4).
- Whether the host's own widget number is read-only (HEART status) or read/write
  (Hub, Bedrock widget control).

---

## 6. Corrections to earlier statements

Against [crosstalk-link.md](crosstalk-link.md) (commit `3cb44f3`):

1. **Section 2.6 and 5.2: the Hub/Bedrock pair at `0x4003b8`/`0x4003c0` is the II request
   buffer (CRB) timeout and prescale, not a "host Crosstalk timeout".** The table row labelled
   "Host crosstalk timeout" should be renamed. IRIX 6.5.30 on a Hub writes prescale `0x1000`
   (not Linux's `0x800`), so "firmware programs both before anything else" is true but the
   value differs by OS.
2. **Section 5.1 "Interrupt landing ... established".** The landing offset `0x80` is
   established (two public drivers). That HEART *honours the deassert bit* is inferred, and
   the packet data encoding is from the Bridge/Crossbow specifications, not a HEART source.
3. **Section 3.1 "Hub's own number resets to 1".** No cited document gives the reset value, so
   it is **unknown**. The register's *meaning* (the Crossbow port the Hub occupies) is read
   from a shipped kernel.
4. **Matrix "Crosstalk timeout/prescale: HEART --".** HEART has a widget request timeout
   register (`+0x28`) that Hub and Bedrock lack; the matrix cell should name it.
5. **Section 3.1 and matrix: "Hub = widget 1".** Two unrelated numbers are both "1": the
   Little Window slot where the Hub keeps its registers, and the Crossbow port number the Hub
   reports in widget control. The second is not established as 1 on shipped hardware.

---

## 7. Unknowns and the test that settles each

| # | Unknown | Discriminating test |
|---|---|---|
| 1 | HEART honours a deassert (bit 8 clear) interrupt packet | Hardware: Bridge pin with clear mode on; observe pending bit after the pin drops |
| 2 | HEART request-timeout tick | Timed uncached read to an unclaimed widget address at two programmed values; derive the unit from the latency |
| 3 | HEART cold-reset values of the widget block | Single owner reads of each slot `+0x10`..`+0x50` before PROM init |
| 4 | HEART widget control (`+0x20`) role and whether the shipped PROM writes it | Read the PROM bring-up routine for a store at `+0x20`; a read after PROM start (see 2.6) |
| 5 | HEART large-window use and size | Binary search of IP30 kernel/PROM for `0x8_0000_0000`-range literals; currently unknown |
| 6 | Hub manufacturer number | Read local `0x400000` on a Hub; sibling IDs (Bridge `0x36`, XBridge `0x24`) do not decide |
| 7 | Hub widget-control reset and writer | Read `0x400020` before any firmware write; trace the PROM's first write |
| 8 | Units of Hub/Bedrock timeouts (`0x4003b8`, `0x4003c0`, PI `0x30`, `0x38`, `0x4001f0`) | Program two values and time a forced timeout, or find the unit in a Hub/Bedrock specification |
| 9 | What times out a Hub PIO read | Stimulus: processor read to an unanswered widget address; record which of PI read-response block or PRB timeout fires |
| 10 | Whether Bedrock's local `0x0100_0000` form reaches the requester's own PI | PIO from a PI1 processor, observe which PI's register changed |
| 11 | What global selects the IP35 kernel's `0x4003c0` prescale (`0xfffe` or `0x00fffffe`) | Trace the global read by `per_hub_init` to its writer |
| 12 | Meaning of the two conditions selecting `0xd0`/`0xd400` versus `0xfe`/`0xc000` in the IP27 PI timeout stores | Read `per_hub_init` to the tests |
| 13 | HEART write to an unclaimed address: which error bits set | One 64-bit uncached store to an unmapped widget range, then read `+0x60`, cause and `+0x70`/`+0x78` |
| 14 | Credit semantics (what a credit unit bounds) in HEART | Not testable without a bus analyser; documented as unknown |

---

## 8. Sources consulted

- SGI: *Origin and Onyx2 Theory of Operations* 007-3439-002 (p28, p53, p73, p82);
  *Origin Family Memory Map* 007-3410-001 (printed p23, p25, p27-33); *SGI Origin 300 Server*
  007-4365-002 (p10); *Origin 3000 Series* 007-4240-002 (Crosstown2); SGI OCTANE Technical
  Report (section 2.3.2, printed p42-44).
- Public drivers: Linux `arch/mips/include/asm/sgi/heart.h`, `asm/xtalk/xwidget.h`,
  `asm/sn/sn0/{addrs,hubio,hubpi}.h`, `asm/sn/addrs.h`, `arch/mips/sgi-ip27/{ip27-init,ip27-xtalk}.c`,
  `arch/mips/sgi-ip30/ip30-xtalk.c`; the IP35 tree (`sn1/hubio.h`, `hubio_next.h`, `hubpi.h`);
  OpenBSD `sys/arch/sgi/xbow/{xheartreg.h,xheart.c,xbow.c,xbridge.c,hub.h}`,
  `sys/arch/sgi/sgi/{ip27_machdep.c,ip30_machdep.c,ip30.h,sginode.c}`.
- Shipped: IRIX 6.5.30 IP27 and IP35 kernels, IP27/IP30/IP35 PROMs, IP30 diagnostic and
  monitor, as reported in the `chips` HEART, Hub and Bedrock entries and the Tezro widget
  question file.
- The cleared HEART, Hub I/O, Hub processor-interface, Bedrock I/O, Bedrock
  processor-interface, Crossbow and Bridge datasheets, read after the above for agreement.
