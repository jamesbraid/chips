# Indigo R4000 (IP20): GIO32 slots, product-ID probing and graphics-board probes

How the Indigo's GIO bus is laid out and how software finds what is plugged into it: the three slot windows, the product
identification word, what an empty slot does, how the graphics boards announce themselves (they have no product ID), the three
shared interrupt lines, and what the MC arbiter is told about the slots. The GIO bus has no registers of its own on this board, so
there is no `devices/gio32` page: arbitration, error reporting and slot sizing live in the [MC](../../devices/mc/README.md), the
interrupt lines in [INT2](../../devices/int2/README.md). Window addresses repeat the [address map](address-map.md); interrupt bit
numbers repeat the [routing table](interrupts.md).

Labels follow [AGENTS.md](../../AGENTS.md). Sources, in evidence order: *IRIX source* is the public tree (`irix/kern/ml/IP20.c`,
`irix/kern/sys/giobus.h`, `irix/kern/sys/IP20.h`, `irix/kern/sys/mc.h`, `irix/kern/master.d/system.gen`,
`stand/arcs/lib/libsk/graphics/LIGHT/lg1_init.c`, `stand/arcs/lib/libsk/graphics/EXPRESS/gr2_init.c`); *PROM* is the Indigo PROM
4.0.5D (`070-8116-004`, listing addresses) and 4.0.5G (`070-8116-005`); *GIO spec* is the GIO bus specification, version 1.1 (draft),
7 April 1992 (its chapter 2 is dated 6 May 1992); *MC spec* is the MC chip specification, revision 1.15; *NetBSD* is
`sys/arch/sgimips/gio/gio.c`, `gioreg.h`, `grtwo.c`, `light.c` and `lightreg.h` (public driver, used to confirm). The GIO spec's
"Indigo-specific" section describes the R3000 board's interrupt-and-arbitration chip (`PIC1`), not the MC; every statement taken from
it for the R4000 board says so. The Indigo R3000 (IP12) is not read here.

## Slots and windows

The Indigo has three GIO32 attachment points: the graphics slot and two option slots. Established that the chassis holds two cards, the
CPU board and, separately, the graphics board (Owner's Guide 007-9065-050, "Replacing the Graphics Board": "two boards inside the
chassis; the right board is the graphics board"). The two option slots are the two 96-pin GIO32 connectors on the CPU board's top
side (GIO spec 2.13.1, p. 2-16, with a figure of two option cards on the Indigo CPU board). The Owner's Guide describes no option
card, so it names no slot order; the kernel's own numbering is slot 0, slot 1, graphics = 2.

| Slot (IRIX name, number) | Physical window | Size | Grade, source |
|---|---|---|---|
| graphics (`GIO_SLOT_GFX`, 2) | `0x1f000000`–`0x1f3fffff` | 4 MiB | **established**: `IP20.h` (`LIO_ADDR`, `LIO_GFX_SIZE` 4 MiB), MC spec section 4 (p. 22), `giobus.h` slot numbers. |
| option slot 0 (`GIO_SLOT_0`, 0) | `0x1f400000`–`0x1f5fffff` | 2 MiB | **established**: GIO spec 2.11.1 (p. 2-13), MC spec p. 22, `system.gen` (`GIO_SLOT0` = `0x1f400000` as a kseg1 address), NetBSD. |
| option slot 1 (`GIO_SLOT_1`, 1) | `0x1f600000`–`0x1f7fffff` per the GIO spec; the MC decodes `0x1f600000`–`0x1f9fffff` (4 MiB) | 2 MiB defined, 4 MiB decoded | **established** for both statements and they differ: the GIO spec says `0x1f800000`–`0x1f9fffff` is "reserved for future definition", the MC spec (p. 22) and the header's 6 MiB option-slot span (`LIO_GIO_SIZE`) cover it. What a read of `0x1f800000`–`0x1f9fffff` returns: **unknown**. |

`kmem_ioaddr` in `IP20.c` lets IRIX map `0x1f000000` for 4 + 6 MiB (the whole graphics-plus-option span), established.
The slot windows are 32-bit-wide on this board: `exp0_size_64`, `exp1_size_64` and `grx_size_64` in `gio64_arb` stay 0 (MC spec 5.9,
p. 30–31: "For Indigo this should be 0"; NetBSD refuses pipelining on this board). The IP12 board has two configuration registers per
slot at `0x1fa20000` and `0x1fa20004` (GIO spec 2.11.2, p. 2-13, `giobus.h`); they belong to the R3000 board's `PIC1` and are not part
of the MC's map on this board, **inferred** (the MC page lists no register there).

## Probing a slot: the product identification word

Established by the GIO spec 2.10 (pp. 2-12 to 2-13), the `system.gen` comment and NetBSD `gioreg.h`.

- The CPU reads one **word** at the slot's base address. The read must be a word read (the spec states this keeps it independent of
  endianness). No other address probing exists on GIO (the spec contrasts it with VME).
- Layout of the word: bits 6:0 product ID, bit 7 "all 32 bits valid", bits 15:8 product revision, bit 16 interface size (0 = 32-bit,
  1 = 64-bit; always 0 for GIO32 and GIO32-bis), bit 17 ROM present, bits 31:18 manufacturer's code.
- If bit 7 of the ID is 0 the card is an 8-bit-ID card: only bits 7:0 are driven, bits 31:8 are "neither correct nor repeatable", and
  software must treat revision as 0, interface 32-bit and no ROM (GIO spec 2.10.2). A model should return a stable value for the
  unused bits; the spec forbids software from relying on them.
- If the ROM-present bit is set, the next three words are reserved: base + 4 board serial number, base + 8 ROM index (software writes 0
  to start, then each read of the ROM read register advances it by 4), base + 12 ROM read (GIO spec 2.11.3, p. 2-14).
- IDs known to IRIX for the Indigo (from `giobus.h`; names as the header gives them): `0x01` XPI FDDI, `0x02` token ring, `0x0a` and
  `0x0b` XPI mezzanine devices, `0x0e` 8-port Ethernet, `0x85` ATM, and several unlisted codes (`0x04`, `0x06`, `0x08`, `0x09`, `0x30`,
  `0x87`, `0x8c`, `0x8d`). NetBSD's list adds `0x35`–`0x38` and `0xb8` (the Indigo2/Indy-era Ethernet cards). Established as names; none
  of these boards is modelled.

Who probes, on this board:

- **IRIX kernel**: through the configuration file, not code in `IP20.c`. The only expansion-slot driver the IP20 build lists in
  `system.gen` is the FDDI card (`if_xpi`): it reads the 4-byte word at `GIO_SLOT1` then `GIO_SLOT0` and accepts it when the low byte is
  `0x01` (`ex_pr((r,GIO_SLOT1,4,1,0xff))`, lines 635 to 638). The graphics slot is not probed by this mechanism on the IP20 build (the
  graphics slot address is defined for the Indigo2 builds only). Established.
- **PROM**: no GIO slot ID read exists in the PROM source tree for this board and none was found in the 4.0.5D image; the PROM probes
  only graphics (below). **inferred** (absence; the listing was searched for the slot base constants and found none).
- **NetBSD**: tries each of `0x1f400000`, `0x1f600000` with `badaddr`, then reads the word. Software expectation.

## What an empty slot does

**Established contract, inferred for the exact status bit.**

- A read of an address nothing answers is a GIO time-out: the spec says the transaction times out 25 µs after the byte-count cycle and
  the arbiter then raises a bus error (GIO spec 2.7, p. 2-11, which adds "software can use this time-out mechanism to determine
  whether a device exists in a GIO32 slot"). On the R4000 board the MC does this: `cpuctrl1.abort_en` (bit 4) turns time-outs on and,
  if it is clear, "the system will hang on a bad GIO bus address" (MC spec 5.2, p. 28). The PROM sets it (`cpuctrl1` ← `0x1016`).
- The MC records the failure in `gio_err_stat` bit 10 (`GIO_ERR_STAT_TIME`) and `gio_err_addr` (MC spec 5.16 and 5.17, p. 36; `mc.h`).
  The kernel's bus-error code treats `TIME` and `PROM` as a plain bus error, not a memory parity error (`irix/kern/ml/IP20.c`,
  `dobuserr_common`).
- The MC interrupts on every such error (INT2 / Cause bit 14 per [the routing table](interrupts.md)); if the failing access was a CPU
  **read** it also asserts the R4000 bus-error pin, so the CPU takes a data bus error exception and the interrupt handler saves and
  clears the MC registers first. A **write** to an empty slot produces the interrupt only (kernel comment above `dobuserre`,
  established). IRIX therefore probes with a fault catcher (`badaddr`, which returns nonzero when the read faulted).
- A reserved or unmapped address inside the MC's own physical map behaves the same way (bus error on read, interrupt on write; MC spec
  p. 22). Which `gio_err_stat` bit a reserved-region access sets, as opposed to a real time-out: **unknown** (a Usenet report of the
  PROM failing the memory test at `0x18000000` shows `GioErrorAddr: 18000000`, which says the address register latches there; the
  status bit was not printed).
- A value-returning failure mode does not exist: no source says an empty slot reads all ones or zero. **inferred** (absence).

Discriminating tests: a word read of `0x1f400000` with nothing attached sets `gio_err_stat.time` and latches the address; the same
read with `abort_en` clear is a model choice (real silicon hangs), so a model should report an error, not wait; a write to the same
address raises the MC interrupt without a CPU exception; `gio_err_stat` clears on any write.

## Graphics boards: no product ID, probed by touching the board

The Indigo's graphics boards do not answer the product-ID read. NetBSD says so for the Express family in as many words ("anything
that even vaguely resembles a product ID"), and the PROM and kernel use a board-specific probe. All established unless marked.

| Board | Where | Probe | Source |
|---|---|---|---|
| LG1 (Entry, "Starter" graphics, REX chip) | `0x1f3f0000`; a second head at `0x1f3f8000` | Write `0x12345678` to base + `0xc`, write 0 to base + 0 (a command nop), read base + `0x800`, wait a short delay, then read base + `0x14`: the board is present if it reads `0x033c0000`. | `lg1_init.c` (`Lg1Probe`); PROM 4.0.5D `0xbfc0f9a8`, 4.0.5G `0xbfc12858` (same words). The probed-address table is at `0xbfc4d1f0` (4.0.5D): `0xbf3f0000`, `0xbf3f8000`, 0. The kernel object `light.o` (`lightProbe`) carries the same constant. |
| GR2 (Express family: Elan, XS, XS24, XZ) | `0x1f000000` only (the graphics slot base); a second head exists in the source for the Indigo2 builds only | Read the word at base + `0x6a07c` (the HQ2 "mystery" register): present if it reads `0xdeadbeef`. Board version is the low nibble of the inverted byte at base + `0x6c000`; zero means no board. | `gr2_init.c` (`Gr2Probe`, `Gr2InitInfo`, the `expr[]` table has one entry unless `IP22`, `IP26` or `IP28`); PROM 4.0.5D `0xbfc0e6f0` (reads `0x6a07c`, compares), 4.0.5D table at `0xbfc4ce78`: `0xbf000000`, 0; NetBSD `grtwo.c` (`HQ2_MYSTERY`). |

Notes:

- The PROM's two probe routines issue plain loads (no `badaddr` call in the 4.0.5D routines at `0xbfc0e6f0` and `0xbfc0f9a8`, although
  the public source calls `badaddr` before the GR2 read). The PROM's fault handler honours a "no fault" pointer
  (`stand/arcs/lib/libsk/ml/faultasm.s`), so whether the caller brackets these reads, or whether a missing board is meant to fault and
  be tolerated, was not traced. **unknown**; it decides whether a model that returns a bus error for a headless Indigo is safe. Route:
  trace the callers in the 4.0.5D listing: the GR2 probe is called at `0xbfc0f6dc` and `0xbfc0f814`, the LG1 probe at `0xbfc1034c` and `0xbfc1045c`.
- The LG1 probe is a write-readback of a register, not a read of a constant: the model needs the REX register file for it. The value read
  back differs from the value written (`0x12345678` in, `0x033c0000` out), so a flat register does not pass; the transform belongs
  to the REX register page, not here.
- NetBSD probes LG1 differently (page-1 register at base + `0x47fc` reads `0x08000800`) and accepts GR2 at any of `0x1f000000`,
  `0x1f400000`, `0x1f600000`. Both are software expectations; the PROM's are the ones to model first.
- LG1 board revision: base + `0x47e4` (after writing 4 to base + `0x47ec`): bits 2:0 board revision, bits 5:3 monitor type, bit 6 clear
  when a video board is fitted (`lg1_init.c`, `Lg1InitInfo`; PROM `0xbfc0fa48`–`0xbfc0fa84`). GR2 revisions and video-backend board
  revisions: `gr2_init.c`, not read in detail.
- The MC's physical map does not distinguish the graphics boards; `gio64_arb.grx_size_64` is 0 (32-bit), `grx_rt` and `grx_mst` are
  never set by IRIX (`GRX_MST` "should be zero for all devices that exist", MC spec p. 31).

## Interrupts

Three lines, shared by every slot (GIO spec 2.9, p. 2-12; `IP20.h`; NetBSD `gio_intr_establish` uses one line for both option slots on
this board). Established.

| GIO line | INT2 bit | Use |
|---|---|---|
| 0 (`GIO_INTERRUPT_0`) | local 0 bit 0 (`LIO_GIO_0`, same bit as `LIO_FIFO`) | graphics only (FIFO full); option cards must not use it (spec) |
| 1 (`GIO_INTERRUPT_1`) | local 0 bit 6 (`LIO_GIO_1`, geometry engine) | **the line option cards use** (spec 2.11.4: "option slot devices must use INT1") |
| 2 (`GIO_INTERRUPT_2`) | local 1 bit 7 (`LIO_GIO_2`, vertical retrace) | graphics only (retrace) |

The kernel's `setgiovector(level, slot, func, arg)` keeps one handler per (slot, level) and installs the shared dispatcher for a level
when any slot has a handler. The dispatcher calls the slot-0 handler, then slot 1, then graphics, which each must cope with a call
when their own board is not interrupting (the spec says so, and says handlers must tolerate spurious calls; `gio0_intr`, `gio1_intr`,
`gio2_intr`). Where the line is cleared (the board, or INT2's port register for retrace) is on the [routing table](interrupts.md).
A model needs no per-slot interrupt source for the first boards it supports: one level-sensitive input per line, owned by the device.

## Arbitration and DMA masters

- **Arbiter**: the MC (spec 2.1, pp. 6–7), not a separate chip. The slot and graphics bits in `gio64_arb` are `*_rt` (real time or long
  burst), `*_mst` (can be a bus master), `*_size_64` and `*_piped`. On the Indigo every size and pipelining bit is 0, `one_gio` is 1,
  `eisa_mst` 0 (MC spec 5.9). The PROM 4.0.5D never writes `gio64_arb` (reset `0x400` stays); the kernel keeps a software copy that
  starts as `one_gio` alone, writes it in `mlreset`, and `setgioconfig(slot, flags)` (`IP20.c`) ORs a slot's `size_64`, `rt`, `mst` and
  `piped` bits in at the slot-0 bit positions (shifted left by one for slot 1) and rewrites the register. Established. The kernel never
  reads the register back (the MC has a read-corruption defect on silicon, per its comment). The graphics slot is not configured through
  `setgioconfig`: its `grx_*` bits are never set. Established from `IP20.c`.
- **DMA masters on GIO**: the MC's graphics DMA engine (virtual DMA to the graphics slot; see the [MC page](../../devices/mc/README.md#the-graphics-dma-engine-in-brief)),
  the HPC1 (SCSI, Ethernet, parallel and audio DMA, a 32-bit device here: `hpc_size_64` 0), and an option card if `exp*_mst` is set.
  The graphics board itself is a slave. EISA is absent. Endianness of option-card DMA is controlled by `cpuctrl1.exp0_fx`,
  `exp0_little`, `exp1_fx`, `exp1_little` (MC spec 5.2); the IRIX and PROM stores leave them clear. **inferred** from the stores.
- **Timing**: `gio_memacc` is `0x34332` on this board (MC page). The kernel's burst and delay estimates assume a 33 MHz GIO clock
  (`GIO_CYCLE` 30 ns in `IP20.c`: "assume 33 MHZ"); the actual GIO clock of the board is **unknown**. The spec's "about fifteen bus
  clocks for a single-word read" is for the `PIC1` (IP12), not the MC.

## What the checks in a qtest or functional test can use

- Word read at `0x1f400000` and `0x1f600000` with no card: bus error plus `gio_err_stat.time`, `gio_err_addr` = address; MC interrupt
  pending; write: interrupt only.
- With a modelled 8-bit-ID card at slot 0: a word read returns the ID in bits 7:0 with bit 7 clear; the high bits are not
  tested. With a 32-bit-ID card: bit 7 set, fields as above, bit 16 clear.
- Graphics presence: LG1 passes the write-readback probe at `0x1f3f0000`; GR2 returns `0xdeadbeef` at `0x1f000000 + 0x6a07c`; an
  absent graphics board must not satisfy either.
- INT2 bits for the three lines raise from the device; one device per line is enough.
- `gio64_arb` reset `0x400`; slot bits stored by a software write; no read-back dependence.

## Open

Filed in [questions/ip20-gio.md](../../questions/ip20-gio.md): the PROM's handling of a missing-board fault, the status bit for
reserved-region accesses, behaviour of `0x1f800000`–`0x1f9fffff`, and the GIO clock.
