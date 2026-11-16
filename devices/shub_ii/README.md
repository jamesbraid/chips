# SHub 1 I/O interface (II)

The II is the part of SHub 1 that talks to Crosstalk: the unit that processor loads and stores to widgets leave
through, that DMA from widgets enters through, and that holds the two block transfer engines (BTEs). On an Altix 3000
Register layouts, with a grade on
every field, are in [registers.toml](registers.toml); the generated reference is [registers.md](registers.md). The
chip-level context, the SHub 2 differences and how software tells the two apart are in [../shub/README.md](../shub/README.md).

**Mode: no-spec.** No SHub specification is held. The only source is SGI's own Linux platform header for the SN2
family (`arch/ia64/include/asm/sn/shubio.h` in Linux v5.3, GPL) and the kernel code that includes it. Under this
repository's evidence order that is the vendor's software source, so the offsets and field positions are
**established** as definitions. Role text paraphrases the header's comments and is **inferred**. Reset values are
**unknown**: the header states none.

## What the kernel actually uses

The header defines 166 register addresses. The kernel files read (setup, interrupts, BTE, BTE error recovery, hub error
interrupt) touch fifteen of them (counting each CRB column once), and only on SHub 1; the rest are definitions nothing in the platform code reads.

| Use | Registers | How |
|---|---|---|
| BTE transfer | status/length, source, destination, control, notification (engine 0 and 1) | source, destination, notify address, length, then the control register with the mode, which starts the transfer; see below |
| BTE error cleanup | CRB management, CRB entries A to E, miscellaneous error mask, error clear, BTE common control | the BTE error handler reads the CRB management register; if no CRB is marked and none that is valid belongs to a BTE, it sets the two BTE bits of the error mask, writes the BTE clear bits, then sets the soft reset bit |
| II error interrupt | CRB entries B, A, C, D, E for each of 15 CRBs; CRB deallocation | the hub error handler: for each entry with the mark bit set it reads A to E, decides whether the entry belongs to a BTE, clears the mark bit and writes the entry number plus the pending bit to the deallocation register, polling until the pending bit clears |

Everything else in the block is the II's configuration the PROM sets before the kernel runs: widget protection, the
big-window translation table, link control, PIO request buffers and the like. A synthetic firmware that never
programs them can leave them at zero for a kernel that never reads them; it must still decode every read in the block.

The kernel never uses the II on SHub 2. The same BTE and error code branches on the chip type and uses a different
register block (see [the SHub 2 overlay](../shub/registers.shub2.md)).

## Where the registers sit

The header gives block-relative offsets: the II starts at 0x400000 in the node's register space. A processor reaches
them through the node's global MMR window; on SHub 1 the address macro sends any offset without bit 32 through *small
window 1 plus 8 MiB*, so the II's registers appear 0x1c00000 into the window of any node (arithmetic in
[the SN2 address map](../../platforms/sn2/address-map.md); inferred from the macros, not seen on hardware).

## Block transfer engines

Two engines, each with six registers: length and status, source, destination, control, notification address and
interrupt address, 8 bytes apart; engine 1 is 64 KiB above engine 0. Lengths are in cache lines and the kernel's
longest transfer is 65535 lines. Addresses are cache-line aligned.

- **Sequence (established, `bte_copy` in the SN2 BTE code).** Store the busy marker (every bit set except bit 21) in the notification word in memory, then write source,
  destination, notification address, length, and last the control word. The control write starts the engine. The kernel
  writes the length register with a plain length and no busy bit; the header says a legitimate write sets busy and clears
  error. The kernel then waits until the notification word stops reading as the busy marker, so the notification word holds that marker, not zero, until the transfer completes. Completion is a write of the final status word to the notification address. The kernel decides busy from the
  notification word it owns, and uses the status register only for "busy or error" when choosing an idle engine.
- **Hazard from the header (inferred).** Reading the control register terminates the transfer in progress, and stopping
  one engine can disturb the other, so error recovery resets both.
- **Modes the kernel uses.** `notify` (bit 4) always; `zero fill` (bit 0) for memory clears, where the source address is
  written as zero.
- **Source and destination conversion.** The kernel clears the address-space bits before writing the source and the
  destination (the physical addresses it holds carry them) and keeps the node number in place. SHub 2 applies a further
  conversion (see the overlay).
- **Error codes (established for the kernel side).** The CRB error codes 0 to 7 (directory, poison, write, access,
  partial write, partial read, timeout, crosstalk) are the hardware's. On an error interrupt the kernel finds the CRB that
  belongs to the engine, adds one to its code (so that zero can mean success) and itself writes the error flag (bit 16)
  and that code into the notification word the transfer's caller is waiting on. So the hardware does not report a
  failed transfer through the notification address; whether it writes it at all on failure is unknown.

Unknown: how fast an engine moves data; whether busy is visible after the control write; what the interrupt address
register (never used by the kernel) is for beyond the header's text.

## CRBs and error capture

Fifteen CRB entries track outstanding Crosstalk and BTE operations. Each entry is five doublewords, A to E, at a
0x30 stride from 0x400400. The kernel reads them only after an II error interrupt. The mark bit in doubleword B means
the entry holds an error the hardware wants software to handle; the 3-bit code in the same doubleword
selects the error. Software clears the mark bit, then frees the entry through the deallocation register. The header
states that the hardware never clears the mark bit itself.

The header names four of the 15 as "partial cache" CRBs and notes that the first of them is now tunable, so which four
they are is unknown.

## How the Itanium sees widget registers

Question: when the SN2 PROM does a 4-byte `ld4` or `st4` on a Crosstalk widget register, which bits does it touch, and does
anything swap bytes on the way? Sources: SGI's Altix Linux code (linux-5.3 `arch/ia64/include/asm/sn/{io,pic,shubio}.h`,
`arch/ia64/sn/pci/pcibr/*.c`; the 2.4-era `include/asm-ia64/sn/sn2/shubio.h` in the same fields) and the SHub 1 PROM
(`shub1snprom.bin`, flat at `0xffa00000`).

Every widget register is a 64-bit register at an 8-byte-aligned offset. SN2 software reads it with plain loads, so an access
of N bytes at byte offset N0 is an N-byte access at N0, and little-endian rules pick the bits.

| Access to the doubleword at 8n | Itanium (little-endian) | Origin MIPS (big-endian, `lw` of the same register) |
|---|---|---|
| `ld8` at +0 | the whole register | whole register (`ld`) |
| `ld4` at +0 | bits 31:0 | bits 63:32 |
| `ld4` at +4 | bits 63:32 | bits 31:0 |

So the widget id (part number in bits 27:12) is `ld4` at `+0` on SN2 and `lw` at `+4` on MIPS; the models written for the
MIPS host must not carry their `+4` convention over. Model the register as one 64-bit value and let the access width and host
byte order choose the half.

- **(a) Width and halves.** `___sn_readl` and `___sn_readl_relaxed` are `*(volatile unsigned int *)addr` and the `readq`
  forms are `*(volatile unsigned long *)addr`, with no conversion (`io.h`). `struct pic` is `u64` fields at 8-byte steps
  (`pic.h`) and the widget id is a `u64` union with manufacturer 11:1, part 27:12, revision 31:28 and the upper 32 bits
  reserved (`shubio.h`, `ii_wid_u`). The PROM's `ld4` at `+0` of widget 0 is tested for part `0xd000` or `0xd100` in bits 27:12
  (B11, `0xffab14f0`), and the status word read at `+0x8` is shifted right by 6 and masked to 4 bits (`0xffaaf340`): both only
  make sense if `+0` and `+8` return the low 32 bits. Established for `+0` (the PROM depends on it); inferred for `+4`
  returning bits 63:32, since no SN2 code reads an `8n+4` word of a widget register that this page found. For II registers
  the PROM never uses 4 bytes: `0xffa0e5a0` is a single `ld8`.
- **(b) Byte swap in transit.** None is visible to the processor on PIO. Software does no swap (below), and the register
  fields are at their little-endian positions in the doubleword, so a PIO access is unswapped (established as the software
  contract; the hardware path itself is not described anywhere found, so nothing beyond the contract is claimed). The swap
  controls are all on the DMA side: IWC bit 0 `i_dma_byte_swap` (`shubio.h`, no description in either header; the PROM writes
  it clear at `0xffaad9f6`, row B10; Linux never writes `IIO_IWC`), and the PIC's Device register bit 19 (`PCIBR_DEV_SWAP_DIR`),
  ATE bit 29 (`ATE_SWAP_ON`) and 64-bit address attribute bit 55 (`PCI64_ATTR_SWAP`) in `pcibr_provider.h`. That these affect
  DMA data only is inferred from the names and use (`pcibr_dma.c` sets the ATE bit when the device bit is set); what they do to
  the lanes is covered in [PIC](../pic/README.md#device-register-bit-19-swap_direct-which-level-swaps). No control was found
  that swaps PIO register data: unknown whether one exists.
- **(c) Linux accessors.** No `swab`, `cpu_to_*` or `le/be` conversion appears in `pcibr_reg.c`, `pcibr_dma.c`, `pcibr_ate.c`,
  `pcibr_provider.c` or `tioce_provider.c` (v5.3, searched). The `pcireg_*` accessors are `__sn_readq_relaxed` and
  `__sn_setq_relaxed` on `u64` fields. Linux never reads the widget id: `bs_xid` comes from the SAL topology call. Established.
- **(d) PROM.** Consistent with (a) to (c). The widget read helper `0xffab14f0` builds the window address from the nasid and
  link and calls `0xffaeb170` with size 4; that reaches the generic read at `0xffb0f4b0`, which accepts sizes 1, 2, 4 and 8
  and returns `~0` for a failed access. The bundles at `0xffb5cf40` and `0xffb5cf50` are four loads with opcodes
  `ld1`, `ld2`, `ld4`, `ld8` on the unmodified address (slot decode by hand; Ghidra's decompile of that routine shows only the
  serialise) and the result is stored zero-extended into a 64-bit slot, with no swap. Established for the instructions.

Not covered: the Crossbow's own endian behaviour (the same reading applies to widget 0 `+0`, `+8` and `+0xc0`, but no
crossbow-specific swap control was looked for), and TIO.

## PROM II setup on the main_three path

What the SAL 5.04 PROM (snprom 10.54, `shub1snprom.bin`, SAL_B component, loaded at `0xffa00000`) does to the II between
the start of I/O discovery and the "Loading EFI" message, and what the II must answer for it to get there. Read in
Ghidra with the IA-64 processor module; the decompiler gave the structure, and every address, constant, loop bound and
access width quoted here was taken from or checked against the disassembly listing. Each function named was read in full.
Register names and field layouts are the Linux v5.3 `shubio.h` ones ([registers.toml](registers.toml)). Nothing was run.

Grades: **established** is a value, address or test read in the code; **inferred** is a meaning, or a requirement worked
out from a branch; **unknown** is stated as such. A meaning that `shubio.h` does not give is never established. Crossbow
and PIC widget registers are not II registers; they are listed only where the PROM reaches them through the II windows.

Other pages: [boot-sequence](../../software/firmware/snprom/boot-sequence.md#2-io-discovery-on-one-node-main_three),
[node-bringup](../../software/firmware/snprom/node-bringup.md), [boot path stage 2d](../../platforms/sn2/boot-path.md).

### What this reading changes

- **The set-up routine `0xffab1cc0` does not run in `main_three`.** It runs in `main`, between progress 0x12 and 0x13, in the
  call at `0xffa1a40c`: wrapper `0xffab3840` takes the node object's operation table (object offset 32), slot 91 (table
  offset 728) and calls it. Slot 91 of the first of four such tables (`0xffbd7c18`, entry 91 at `0xffbd7ef0`, descriptor
  `0xffc4bc30`) is `0xffaad720`, which calls `0xffab1cc0`. Table 0 is the SHub 1 one: the node's table is picked by
  calling each table's slot 1 with the node's 16-bit part number, and table 0's test (`0xffa959a0`) is "part is 17251"
  (`0x4363`, the part number the PROM also compares at `0xffa959ac`); the other three test 12311, 569 and 17442. If the routine returns 0 or less (no I/O brick, the
  widget-0 id read fails, or debug-switch bit 14 skips I/O) `main` sets flag 2 in the PROM flag word `0x1_5003_1550`, and
  `main_three`'s I/O discovery (`0xffab38b0`) then skips itself, because its first test is that flag (through slot 32,
  `0xffa0ebc0`). So what `main` sees in ILCSR and in widget 0 decides whether `main_three` discovers anything. (Established
  for both call chains, the flag test and the table choice.)
- **The PROM programs no translation.** All seven translation table entries are written zero and never again. The IWI,
  IIDSR, IIDEM, local and SXB protection and override registers are never read or written on this path, and nothing is
  touched through a big window. Everything the PROM reaches in a widget goes through small windows. (Established for the
  code read. A search of the whole SAL_B for the constants of those registers found users only in the memory test `0xffa7a960`
  (documented in [node-bringup](../../software/firmware/snprom/node-bringup.md)), the BTE error clean-up `0xffa94d40` and
  code at `0xffb45080` to `0xffb745e0`; no direct call from `main_three` reaches that last block, only table dispatch,
  and the dispatch slots of the SHub table that reach II code are 91 and 93, both the routines above.)
- **The only II error and interrupt set-up is in `0xffab1cc0`:** every error bit cleared, the incoming error packet headers
  cleared, one wrapper error interrupt mask bit set, the CRB timeout prescaler set. No interrupt destination is programmed.
- **The "single node interconnect skip" is not an II decision.** NUMAlink discovery is skipped in `main_two` by bit 11 of
  the debug-switch word (see [boot-sequence](../../software/firmware/snprom/boot-sequence.md#single-node-interconnect-the-skip)).
  The II-level counterpart in `main_three` is the crossbow walk's "XBow link %d:no NUMAlink, skipping", below.
- **No II register the header lacks.** Every II offset the PROM touches is one of the 60 already in
  [registers.toml](registers.toml). What this reading adds is the PROM's values and sequence, recorded in the register
  notes and a few constants there.

### Address forms

The PROM reaches II register `X` (header offset, `0x400000` and up) at `0x8_0000_0000 + 0x180_0000 + X`, with bit 63 set and
`nasid << 38` added: `0x8_01c0_0020` is IIO_WCR, `0x8_01c1_0000` IIO_IBLS0. That is Linux's small window 1 plus 8 MiB
(`SH1_REMOTE_SWIN_MMR`, `addrs.h`). The code builds each address with two untaken alternatives (an offset with bit 38 set, an
offset with bit 32 set, the big-window form); for every II constant the small-window form is taken. One routine, the block
transfer copy `0xffa952f0`, uses a local alias instead, `0x8000_0080_0141_0000` and `0x8000_0080_0142_0000`
(local MMR space `0x80_0000_0000` plus `0x100_0000` plus the offset); that this is the same register as the global form is
inferred. Every II register access goes through two helpers, `0xffa0e5a0` (64-bit load) and `0xffa0e640` (64-bit store); each
disables data translation and interrupt collection around a single access, then runs `mf.a` and a serialise, so all
accesses are single, ordered, uncached 8-byte accesses (established). Widget window accesses are 4-byte loads and stores
(`ld4.acq`, `st4.rel`) at `0x8_0000_0000 + nasid << 38 + link * 0x100_0000 + offset` for link 0 to 15 (small window `link`),
the read of widget 0 at link 0, which Linux sends through a big window.

### Order of events

| Step | Where | II accesses |
|---|---|---|
| 1 | `main`, call `0xffa1a40c`, `0xffaad720` (master processor only; debug-switch bit 14 skips) | B1 (module type 111 only), then table A, then B2 to B13 |
| 2 | `main_three`, call `0xffad756c`, `0xffaad6d0`, `0xffab38b0`, `0xffab15c0` | rows C1 to C8 |
| 3 | `main_three`, call `0xffad760c`, `0xffa73b00` | row D (conditional) |
| 4 | the rest of `main_three` to "Loading EFI" (`0xffad777c`) | none found |

### A. The set-up routine `0xffab1cc0`, called with the node's NASID

It runs first in `0xffaad720` (after B1 when the module type is 111).

| Row | II registers (offset) | Direction and value | What a read must return | Grade |
|---|---|---|---|---|
| A0 | non-II word at `0x1_1007_1080` (no Linux definition) | one write of 0 first | accept the store | established; role unknown |
| A1 | IPRTE_A 0 to 7 (`0x400308 + 8i`), IPRTE_B 0 to 7 (`0x400348 + 8i`) | for i = 0 to 7: read A, write A = 0, read B, write B = 0 | any; the value is discarded | established; the writes mark every PIO read entry invalid (inferred) |
| A2 | IPPR (`0x430008`), IPCR (`0x430000`) | IPPR read (discarded), then IPCR written 0 | any | established |
| A3 | WSTAT (`0x400008`) | write 0 | | established |
| A4 | IECLR (`0x4001f8`) | write `0x7ff_ffff_ffff` (bits 42:0: every defined clear bit and the reserved bits between them) | write-one-to-clear; clears all sticky error state | established |
| A5 | IGFX0 (`0x400140`), IGFX1 (`0x400148`) | write 2, write 3 (widget 2 and 3, node 0, PI 0) | read back the written value | established |
| A6 | ITTE1 to ITTE7 (`0x400160 + 8i`) | write 0, i ascending | a plain read/write register | established |
| A7 | IBCT0 (`0x410018`), IBCT1 (`0x420018`), IBLS0 (`0x410000`), IBLS1 (`0x420000`) | four reads, in that order, values discarded | any. The header says reading IBCT ends a transfer, so this stops both engines (inferred) | established; meaning inferred |
| A8 | IBLS (`+0x00`), IBSA (`+0x08`), IBDA (`+0x10`), IBNA (`+0x20`), IBIA (`+0x28`) of engine 0 then engine 1 | write 0 to each, IBCT not written | plain read/write | established |
| A9 | ILLR (`0x400130`) | write 0 | | established |
| A10 | CRB 0 to 14, doublewords A to E (`0x400400 + 0x30 * n + 8k`) | write 0, entry by entry, A before E (75 writes) | | established |
| A11 | IPRB0 (`0x400198`), then IPRB8 to IPRBF (`0x4001a0` to `0x4001d8`) | read-modify-write: set bit 42 (the header's `i_f`) | any; the other bits written back unchanged | established; the header gives `i_f` no meaning, unknown |
| A12 | IIEPH1 (`0x400220`), IIEPH2 (`0x400228`) | write 0 | | established |
| A13 | IWEIM (`0x400260`) | read-modify-write: set bit 15 (`ioq_req_overflow`) | any | established |
| A14 | ICTP (`0x4003c0`) | write `0x1fffff` | | established |

That is 158 II accesses in the routine: 32 in A1, 2 in A2, 1, 1, 2, 7 in A3 to A6, 4 and 10 in A7 and A8, 1 in A9, 75 in A10, 18 in A11,
2 in A12, 2 in A13 and 1 in A14. None depends on a reset value: every read is discarded or written back with a bit changed.

### B. Other accesses of `0xffaad720`, in order (table A runs between B1 and B2)

Each read-modify-write below is a read, a write, a read back and a 10 ms wait (`0xffa0db90(10000)`, microseconds), except
where stated.

| Row | Site | II registers and widget accesses | What a read must return | Grade |
|---|---|---|---|---|
| B1 | `0xffab3170`, only if the L1 module type byte is 111 | ILCSR: set bit 8 (`wrmrst`), then write back the value read after it | bit 8 may self-clear | established; why 111 unknown |
| B2 | `0xffab30e0` | IOWA (`0x400110`) and IIWA (`0x400118`) written `0xff01` | read back | established; the bits are widget 0 and widgets 8 to F (header fields), that a one opens them is inferred |
| B3 | `0xffab2e60` | ILCSR read; bit 13 (`llp_stat` bit 1, the header's `IIO_LLP_CSR_IS_UP`) is "I/O brick attached" in the PROM's own message | **bit 13 set**, else the routine returns 0 and I/O is skipped (flag 2) | established |
| B4 | `0xffab3020`, arg 0 | ILCSR: `d_avail_sel` (27:26) = 0 | | established |
| B5 | `0xffab3320`, arg 0 | WCR: `dir_con` (bit 17) = 0 | | established |
| B6 | `0xffab2f80` | ILCSR: `llp_en` (bit 10) = 1 | | established |
| B7 | `0xffab3640` | 4-byte read of widget 0 at window offset 8 (status); keeps bits 9:6 | any value; **bits 9:6 must be 8 to 15** (see X2 and C3); a failed read gives 0xf | access established; the requirement inferred from the compare in C3; the field's meaning unknown |
| B8 | `0xffab33e0` | WCR: bits 4:0 = that field (`wid`; `tag` cleared) | read back | established |
| B9 | `0xffa91260` | node and port records; no II offset constant was found beneath it | | established for the absence of constants only |
| B10 | `0xffaad9f6` | IWC (`0x400250`): read, write with bit 0 (`dma_byte_swap`) cleared, read; no wait | any | established |
| B11 | `0xffab14f0`, link 0 | 4-byte read of widget 0, offset 0 (the id): if the read fails or returns `0xffffffff`, I/O is skipped | the xbow id, part (27:12) `0xd000` or `0xd100` | established; see C2 |
| B12 | `0xffab34b0` then `0xffab3260`, if part is `0xd000` or `0xd100` | crossbow handshake and link flags (table X, rows X1 and X2), then WCR: set `tag` (bit 4) | | established; any other part prints a warning and leaves WCR alone |
| B13 | `0xffab3780`, arg 3 | ILCSR: `nullto` (5:0) = 3 | | established |

Return value 1 (rows B1 to B13 done), 0 (B3 or B11 failed) or -1 (switch bit 14). Only the master processor of the node does
this; any other returns 1 at once.

### C. I/O discovery in `main_three`: `0xffab38b0` for the node

Reached from `main_three` at `0xffad756c`. Gates, none touching the II: master processor (`0xffa0ff30`) first, then flag 2 clear.

| Row | Site | Accesses | What a read must return | Grade |
|---|---|---|---|---|
| C1 | `0xffab3720` (in `0xffab0560`) | WCR read (`0x400020`), bits 3:0 = `wid` | what B8 wrote | established |
| C2 | `0xffab15c0` through `0xffaeb170`, after C1 and C3 to C6 (`0xffab15c0` calls `0xffab0560` first) | 4-byte read of widget 0 window offset 0 (id), through the machine-check protected helper that returns 0 on a fault or timeout | part `0xd000` or `0xd100`; anything else prints "New Widget %x connected to HUB." and stops without klconfig entries | established |
| C3 | `0xffab0560`, `0xffaaf630` | read link flag word of links 8 to 15 until one has bit 2 (up to 8 reads); that link number must equal WCR `wid` | the flag B12 set on the hub's own link, so `wid` must be 8 to 15, or "*** early return from xbow_init" prints | established |
| C4 | `0xffab0560` | widget 0 write sequence (table X, row X4) | accept | established |
| C5 | `0xffab0560`, per valid link | table X rows X5 to X8 | see the table | established |
| C6 | `0xffab0130`, called for the hub's own link (part assumed `0xc120`) | `0xffab3580`: WCR `dst_crd` (15:13) = 4 | read back | established |
| C7 | `0xffab0f10` | WCR read again; widget 0 id read (`0xffab1800`, a plain load); master scan again; link scan `0xffab0900`; per link id read | as above | established |
| C8 | `0xffab0c00`, twice for a PIC at `0xd102`, once per bus | WCR read each time, used as the PIC direct-map widget field | what B8 wrote | established |

That is 7 II register accesses in `main_three`: 4 WCR reads (C1, C7, two in C8) and the 3 of C6.

### X. Widget 0 and link window accesses (not II registers)

The widget behind small window 0 answers as a crossbow (part `0xd000` or `0xd100`). Linux v5.3 does not define its registers,
so names and meanings are unknown; offsets, widths and values are what the code does.

| Row | Access | Value or test | What a read must return | Grade |
|---|---|---|---|---|
| X1 | read widget 0 `+0x08` again, take bits 9:6, write them to `+0xc0`, read `+0xc0` until it equals what was written; at the end write 1 to `+0xc8` and read it back (`0xffaaf340`, `0xffaaf400`, from `0xffaaf8b0`) | no bound: the loop waits 1 ms per pass forever if `+0xc0` does not hold the value | `+0xc0` reads back exactly the 4-bit value written (a 32-bit compare, so bits 31:4 read 0); the status word at `+0x08` is read once, not per pass; `+0xc8` is written and read back with the value discarded, so any behaviour is accepted | established |
| X2 | link flag word of the hub's link `wid`, at `+0x118 + 0x40 * (wid & 7)` (`0xffaaf8b0`): set bit 0; set bit 1 if a node operation (table slot 54, `0xffa5d6a0`, the NI port status routine; the object it is read from was not traced) returns non-zero; then bit 2 (master): set bits 0 and 2 on the own link unless link `0xa` (link `0xb` when `wid` is `0xa`) already has bit 2; when `wid` is `0xa` and `0xb` has it, move it to `0xa`; `0xffaaf630` later finds the master by scanning links 8 to 15 | the word is plain storage to the PROM; bit 0 "hub's own link", bit 1 "NUMAlink up", bit 2 "master" (inferred) | 32-bit read/write storage | established; meanings inferred |
| X3 | per link block base `0x100 + 0x40 * (link & 7)`: `+0x10` bit 31 (link alive), `+0x38` bit 5 (widget present) | a link is valid if both set; for a `0xd100` crossbow, link `0xb` is valid if alive and link `0xf` always | the hub's own link and the PIC's link: both bits set; others: clear | established; meanings inferred |
| X4 | `+0x50` read first, then writes in this order: `+0x38` = 0, `+0x30` = master link `<< 16`, `+0x28` = `0x4000`, `+0x40` = 0, `+0x20` = `0x3c`, `+0x48` = `0x3ff1be0` | `st4.rel`; these offsets are the standard widget configuration block (`p_wid_*` in `pic.h`) | accept; reads of `+0x50` return anything | established; for the PIC names and offsets established, for the crossbow inferred |
| X5 | per valid link whose flag bit 0 is clear: widget `link` `+0x20` written `link | 0xf003000`; if widget 0 is `0xd100`, `+0x80_0020` too (`0xffab0380`) | the widget's own `wid` in the low nibble (inferred) | accept | established |
| X6 | per valid link (not the hub's own): 4-byte id read at the link window; `0xffffffff` skips the link; part `0xd102` or `0xd112` is a PIC | `0xd102` on a Altix 350 | | established |
| X7 | for a PIC link: link block `+0x08` = `0x80000`, `+0x18` = 0, `+0x20` = 0, then poll `+0x10` bit 31 up to 100 times at 1 ms | | alive within 100 ms | established |
| X8 | link credits (`0xffab0130`): link block `+0x08` bits 22:18 = table credits; widget `+0x20` (and `+0x80_0020` for a PIC) masked-written with `4 << shift`; 1 ms wait. Table at `0xffbe10e0`: `0xc120` credits 4 mask `0xe000` shift 13; `0xd102` and `0xd112` credits 3, mask `0xf000` shift 12; `0xd000` and `0xd100` credits 4, mask `0x7c0000` shift 18 | | read/write registers | established |

### D. Block transfer for PI-to-memory credits (conditional)

`main_three` calls `0xffa73b00` at `0xffad760c`. On the master it runs `0xffa736d0`: it writes `0x88c` to `0x81_2005_0d80`
(a processor interface register, not II; local-form address), reads `0x81_2006_0980` and takes bits 5:0. If that is below 8 it
zero-fills a 1 KiB buffer with the BTE (`0xffa952f0`: engine 0 or 1 by processor slice parity, local alias
`0x81_0141_0000` or `0x81_0142_0000`; writes IBLS = length in lines with bit 20 set, IBSA, IBDA, IBNA, then IBCT = `0x11`,
notify and zero fill; polls the notify word for up to 10,000,000 timer ticks) and re-reads the credits until they reach 8 or 1,000,000
ticks pass (messages "BTE failed trying to adjust pi2md credits" and "pi2md request credits at:%d, should be %d"). With 8 on the
first read the BTE is not used. If the BTE reports an error (bit 16 of the notify word)
`0xffa94d40` runs an error clean-up (CRB scan, ICDR, IMEM, IECLR, IBCR). Established for the sequence; what a model must return:
credits 8 on the first read of `0x81_2006_0980` avoids all of it (inferred). The PROM skips the call when processor id register 2
equals the platform-simulation marker `0xaeeeeeee8badbeef` (established).

### What a model must answer to reach "Loading EFI"

- ILCSR bit 13 set; every II register above a plain 64-bit read/write cell with the write-one-to-clear IECLR the only
  special case; WCR holds what is written.
- Widget 0: id part `0xd000` or `0xd100` (revision in 31:28, manufacturer 11:1 free), status bits 9:6 in 8 to 15, `0xc0`
  storing a 4-bit value and reading back only that value, `0xc8` accepting a write, link blocks as in X2 to X3, `+0x20` to `+0x48` storage.
- One PIC link: link block alive and present, window id `0xd102` (see [the PIC page](../pic/README.md)).
- No other link valid; then the "no NUMAlink, skipping" case never arises.

### Skips on a single node

- **Debug-switch bit 14** (`0xffa975e0(14)` in `0xffaad720`) prints "---- DEBUG - skipping I/O initialization" and
  returns -1. Established. It is a different switch from the NUMAlink one (bit 11).
- **No brick or no widget 0:** ILCSR bit 13 clear (B3) or the widget 0 id read failing (B11) returns 0, `main` sets flag 2 and
  `main_three` prints nothing for I/O. Established.
- **"XBow link %d:no NUMAlink, skipping" (`0xffab0f10`):** for a link whose part is `0xc120`, other than the hub's own link,
  and whose flag word bit 1 is clear, the walk skips it. Bit 1 is set in X2 only if the NI port status call says up. On one node
  with no cable, no other link reports `0xc120` and the case does not arise. Established for the test; the NI call's
  identity inferred from the operation table slot.

Unknown: the meaning of the xbow `+0x08` bits 9:6, `+0xc0`, `+0xc8` and the flag bits beyond the PROM's use; why module type 111
needs a warm reset; what `0x1_1007_1080` is; the failure signal of the protected read for an absent widget.

## Consistency with Bedrock

109 of the 119 offsets recorded for Bedrock's I/O interface ([bedrock_ii](../bedrock_ii/registers.toml)) are
also in this block; the ten that are not are the sixth doubleword of each CRB. SHub 1's interface is evidently the
Bedrock one, enlarged (the header is derived from the Bedrock header: it still says "Hub" and "SN1" in places). That
is a hypothesis from a sibling chip and fills no field here; every entry rests on this header.

## Open questions

See [questions/shub-ii-reset-and-roles.md](../../questions/shub-ii-reset-and-roles.md).

## Review

Independent review of this page and [registers.toml](registers.toml) at chips commit 87e1291, against Linux v5.3 `shubio.h` and the SN2 BTE, BTE error and hub error code. The reviewer did not write the page.

**Checked.**
- All 60 register entries (166 register instances after counts and strides) were compared by script with the header's `IIO_` offsets: every offset matches, every repeated register's count and stride matches (CRB 15 x 0x30, BTE 2 x 0x10000, translation table 7, partial-read and PRB tables), and no offset in the file is absent from the header. The header defines no register outside the 166 that the file does not carry (the two other numeric `IIO_` constants at or above 0x400000 are field masks).
- All 312 field positions were compared by script with the header's bitfield unions read from bit 0 up: all match (widget id, status and control, protection, LLP, translation entries, CRB A to E, BTE, error and wrapper registers included).
- "The kernel touches fifteen of them" recounts to 15: five BTE registers (status, source, destination, control, notify; the interrupt address is never used), CRB management, CRB A to E, miscellaneous error mask, error clear, BTE common control, CRB deallocate.
- The 0x1c00000 arithmetic: `SH1_REMOTE_SWIN_MMR` is small window 1 base (global node base plus 1 << 24) plus 0x800000 plus the register offset, used for any offset without bit 32. For the II block start 0x400000 that is 0x1000000 + 0x800000 + 0x400000 = 0x1c00000 from the global node base. Correct and correctly graded inferred (nothing was read from hardware).
- BTE: the engine register order and 64 KiB engine stride, busy at bit 20, error flag at bit 16, length mask 16 bits, the two mode bits (zero fill bit 0, notify bit 4), cache-line length units, source and destination address-space bit clearing, the SHub 1 start order (length write, then control), the CRB error codes and the kernel's add-one convention. All match.

**Grades.** Offsets and field positions established as header definitions; role text inferred; resets unknown. No issue.

**Findings (wording, not changed).**
1. "Clear the notification word in memory" is not what `bte_copy` does: it stores the busy marker (every bit set except bit 21), and waits until the word changes. The word holds that marker, not zero, until the transfer completes.
2. The page's claim of 109 of 119 Bedrock offsets in common was not re-derived (it needs the Bedrock page); it is graded as a hypothesis and fills no field, so it does not affect clearance.

**Cleared:** offsets, counts, strides and field positions of all 60 entries; the fifteen-register use count; the 0x1c00000 arithmetic; the BTE sequence apart from finding 1. **Not cleared:** role and "inferred" text (inferred by design), the Bedrock overlap figure, and any behaviour of the BTE or CRBs on real hardware.

Findings 1-8 addressed in the commit "docs: address the SN2 SHub review findings"; renewed review needed for the changed claims.

### Renewed review

Renewed review of the changed claims only, 2026-11-14, by a reviewer who wrote none of them. Reviewed chips commit f5ab671 (contains 1d4f24f and 9995be1). Grading rule: sgi-retools `tools/README-analysis.md` "Evidence order" at c50bfeb. Sources were fetched as single files from Linux v5.3 into scratch and compared with the changed text. 

**Checked.** `bte_copy` stores `BTE_WORD_BUSY` (`~BTE_WORD_AVAILABLE`, where `BTE_WORD_AVAILABLE` is `IBLS_BUSY << 1` and `IBLS_BUSY` is bit 20 in `shubio.h`) in the notification word before programming the engine, then loops while the word equals that value. "Every bit set except bit 21" and "leave the marker in place until the transfer completes" are right.

**Findings.** None.

**Cleared:** the BTE sequence wording. **Not cleared:** as in the first review (Bedrock overlap figure, real-hardware behaviour).

## Review (PROM II setup)

Independent review of the "PROM II setup" section above, the note added to [the reset and roles question](../../questions/shub-ii-reset-and-roles.md) (commit 88a9411) and the register notes and constants in [registers.toml](registers.toml) (commit 8fff0ff). The reviewer wrote none of it. Image: SAL 5.04, snprom 10.54, `shub1snprom.bin` (sha256 `51ccf9ad...`). Method: Ghidra with the IA-64 module (retools at da7f0c0 or later); each function was decompiled and its listing re-read, with a whole-image listing used to search constants and call sites. Nothing was run. Register meanings were checked against Linux v5.3 `arch/ia64/include/asm/sn/shubio.h`, fetched as one file.

**Confirmed (read in the listing).**
- **II setup runs in `main`.** `0xffa1a40c` calls the wrapper `0xffab3840`, which takes the node object's table (object `+0x20`) and calls slot 91 (`+0x2d8`). Table `0xffbd7c18` (the first of four listed at `0xffbd8a18`) has slot 91 at `0xffbd7ef0`, descriptor `0xffc4bc30`, entry `0xffaad720`, which calls `0xffab1cc0`. The table is picked by `0xffa0f7e0`, which calls each table's slot 1 with the 16-bit part number at node object `+2`; table 0's slot 1 (`0xffa959a0`) compares with `0x4363`, the others with `0x3017`, `0x239` and `0x4422`. Progress 0x12 is at `0xffa19f86` and 0x13 at `0xffa1a41c`. A result of 0 or less (the branch is on `0 < r8`) calls `0xffa0eae0(2, 1)`, which sets bit 2 of the word at local `0x81_5003_1550`. `0xffab38b0` tests that bit through slot 32 (`0xffa0ebc0`, via `0xffa99870`) and returns 1 without discovering anything when it is set. `0xffa0ecd0(2)` (`0xffa19fcc`) gates the whole call: `main` skips the setup if flag 2 is already set.
- **Counts.** 158 II accesses in `0xffab1cc0`, plus the one non-II store (A0): 31 store sites and 10 load sites, with the loops of 8, 7, 8 and 15 passes multiplying out to the table's per-row counts. In `main_three` 7 II accesses (WCR read in `0xffab0560`, `0xffab0f10` and twice in `0xffab0c00`, three in `0xffab3580`); a search of every function reachable by direct call from `main_three` finds II register constants only in `0xffab3580`, `0xffab3720` and the BTE error clean-up `0xffa94d40`.
- **Accesses.** Well over 40 accesses were checked for address, value and direction against the listing and decompile: every row of A (IPRTE loop, IPPR read, IPCR, WSTAT, IECLR, IGFX0 and 1, the seven ITTE writes, the four BTE reads and ten BTE writes, ILLR, 15 x 5 CRB writes, IPRB0 and IPRB8 to F read-modify-write of bit 42, IIEPH1 and 2, IWEIM bit 15, ICTP) and B1 to B13. The write of 0 to `0x1_1007_1080` comes first. The offsets match `shubio.h`; IPRB bit 42, IWEIM bit 15, IWC bit 0, WCR bits 4:0, 13 to 15 and 17, ILCSR bits 5:0, 8, 10, 13 and 27:26 all match its field layouts.
- **Requirements.** ILCSR bit 13 set (return 1, with a "Found I/O brick attached" message; clear returns 0). Widget 0 id part `0xd000` or `0xd100` (`0xffab14f0` and again in `0xffab15c0`). Status bits 9:6 give WCR `wid`, and `0xffab0560` requires the master link found in links 8 to 15 (`0xffaaf630`) to equal it. The `+0xc0` loop has no bound: it writes the value, reads it back and retries every 1 ms until the 32-bit read equals it.
- **Untouched.** ITTE zeroed and never programmed. ILAPR, ILAPO, IIDEM, ISLAPR, ISLAPO, IWI and IWS have no constant anywhere in the image; IIDSR, IWEL and the other ITTE users sit only in the block from `0xffb45080`, which no direct-call chain from `main` or `main_three` reaches (the chain roots are descriptors, the IWEIM routine's in the SAL procedure table `0xffc26380` to `0xffc264e0`; one root has no static reference). The error and interrupt setup in the routine is as listed (IECLR, IIEPH1 and 2, IWEIM bit 15, ICTP); IECLR bits 17 and 18 in `0xffa94d40` are the BTE bits.
- **Skips.** Debug-switch bit 14 (`0xffa975e0(14)`, set means skip) prints the "skipping I/O initialization" message and returns -1. Bit 11 is tested at `0xffa4754c` in the interconnect step and prints "Skipping NUMAlink discovery". The "XBow link %d:no NUMAlink, skipping" test in `0xffab0f10` is link flag bit 1 (`0xffaaf810`), set in `0xffaaf8b0` only when slot 54 of the node's table returns non-zero; for table 0 slot 54 is `0xffa5d6a0`, which prints "shub_port_status" and returns a mask of the two NI ports.
- **Constants and notes.** The 5 constants match their sites and the header's fields. The register notes number 30, not 28 (the CRB, BTE and performance registers account for the difference); all 30 match the listing apart from the wording fixed below.

**Fixed in place.**
- A2 said IPPR and IPCR were both read; IPPR is read and IPCR written 0.
- A4 and `ERROR_CLEAR_ALL` called the IECLR value "every defined clear bit": bits 42:0 also cover the reserved bits between them.
- B2: the header only says IOWA and IIWA "qualify" accesses, so that a one opens a widget is inferred.
- B3 and the ILCSR note: bit 13 is the header's `IIO_LLP_CSR_IS_UP`; "brick attached" is the PROM's own message.
- X1: only `+0xc0` can stall the PROM, and it must read back exactly the 4-bit value (bits 31:4 read 0). The status word at `+0x08` is read once before the loop. `+0xc8` is written and read back with no check.
- C2 happens after C1 and C3 to C6 in time: `0xffab15c0` runs `0xffab0560` first and reads the widget 0 id afterwards. In `0xffab38b0` the master test comes before the flag test.
- `boot-sequence.md` and `boot-path.md` no longer place `0xffab1cc0` in `main_three`. The gate bullet in `boot-sequence.md` named the wrong table slot (+256, a flag test) as the I/O initialiser.

**Changed or added requirements for a model.**
- The flag word (local `0x81_5003_1550`, read through the node's small window at `0x1_5003_1550`) and the debug-switch word (local `0x81_5003_1560`, loaded from the L1 command 1 reply) are SHub registers outside the II. A model of the whole node needs both as plain storage; bits 11 and 14 of the debug word must read 0.
- `main` runs the II setup only on the master processor and only while flag 2 is clear. A return of 0 also happens when the widget 0 part is not `0xd000` or `0xd100` (`0xffab34b0` warns and returns 0), so that case sets flag 2 as well; the page lists only the brick and read-failure causes.
- The widget window form depends on bit 0 of the NASID: even uses `0x8000_0008_0000_0000 + (nasid << 38) + (link << 24)`, odd uses `0x8000_0000_0000_0000 + (nasid << 38) + (link << 28)`. The II registers always use the small-window form. Only even NASIDs were read through; the odd form is not analysed and the page's "no big window" statement holds for even NASIDs only.
- For a part `0xd100` crossbow link `0xf` is always valid and link `0xb` needs only the alive bit (`0xffaaf430`); the page states this in X3.

**Not covered by the page's claims.** An OS-called SAL procedure (descriptors at `0xffc26390` and `0xffc26460`, reaching `0xffb714a0` through `0xffb45a10`) also programs the II: it writes IWEIM `0xc000` and touches ILCSR and more. It is not on the boot path, so "the only II error and interrupt setup" holds for the boot path only; its register list was not read.

**Not checked.** The 25-access helper figure: B1 to B13 give 21 II accesses (26 with the module-111 reset in B1), plus 3 for IWC read inline in `0xffaad720`, which does not reproduce 25. Why part `0x4363` is SHub 1 (inferred from the image name and table order, not from a header). The odd-NASID path, the meaning of module type 111, the L1 side of the debug word, the contents of `0xffa91260`'s records beyond the absence of II constants, rows X5 to X8 beyond the credit table (checked) and the BTE zero-fill sequence of D (`0xffa73b00`, read only for its gates and the 8-credit exit). The static call search misses calls through descriptors, so the "no other II access" statements are for direct calls only. The section heading says `main_three`; the routine runs in `main`, and the heading is kept because other pages link to its anchor.

**Cleared:** the sequence, addresses, values and polarity of `0xffab1cc0` and its helpers; the call chain and flag; the requirement list after the fixes above. **Not cleared:** the odd-NASID path, rows X5 to X8 meanings, and anything beyond the boot path.
