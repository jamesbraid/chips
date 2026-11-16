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
  forms are `*(volatile unsigned long *)addr`, with no conversion (`io.h`; the non-relaxed forms add `mf.a` and a DMA flush
  of the bridge, not a swap). `struct pic` is `u64` fields at 8-byte steps
  (`pic.h`) and the widget id is a `u64` union with manufacturer 11:1, part 27:12, revision 31:28 and the upper 32 bits
  reserved (`shubio.h`, `ii_wid_u`). The PROM reads the widget 0 id with a size-4 access at `+0` (`0xffab14f0`, B11) and
  `0xffab15c0` then tests the part in bits 27:12 (`ld4.acq` of the returned word, `extr.u 12,16`, compare with `0xd000` and
  `0xd100`, at `0xffab16d0` to `0xffab16f0`). The status word is read with `ld4.acq` at `+0x8`, then `extr.u 6,4` (`0xffaaf340`):
  both only make sense if `+0` and `+8` return the low 32 bits. Established for `+0` (the PROM depends on it); inferred for `+4`
  returning bits 63:32, since no SN2 code reads an `8n+4` word of a widget register that this page found. For II registers
  the PROM never uses 4 bytes: `0xffa0e5a0` is a single `ld8`.
- **(b) Byte swap in transit.** None is visible to the processor on PIO. Software does no swap (below), and the register
  fields are at their little-endian positions in the doubleword, so a PIO access is unswapped (established as the software
  contract; the hardware path itself is not described anywhere found, so nothing beyond the contract is claimed). The swap
  controls are all on the DMA side: IWC bit 0 `i_dma_byte_swap` (`shubio.h`, no description in either header; the PROM forms
  the address at `0xffaad9f6`, reads it with `ld8` (`0xffa0e5a0`), and writes the value `& ~1` at `0xffaada3c`, row B10; Linux never writes `IIO_IWC`), and the PIC's Device register bit 19 (`PCIBR_DEV_SWAP_DIR`),
  ATE bit 29 (`ATE_SWAP_ON`) and 64-bit address attribute bit 55 (`PCI64_ATTR_SWAP`) in `pcibr_provider.h`. That these affect
  DMA data only is inferred from the names and use (`pcibr_dma.c` sets the ATE bit when the device bit is set); what they do to
  the lanes is covered in [PIC](../pic/README.md#device-register-bit-19-swap_direct-which-level-swaps). No control was found
  that swaps PIO register data: unknown whether one exists.
- **(c) Linux accessors.** No `swab`, `cpu_to_*` or `le/be` conversion appears in `pcibr_reg.c`, `pcibr_dma.c`, `pcibr_ate.c`,
  `pcibr_provider.c`, `tioce_provider.c` or `io_init.c` (v5.3, searched; none in `arch/ia64/sn` at all outside unrelated
  `cpu_to_node` uses). The `pcireg_*` accessors are `__sn_readq_relaxed`,
  `__sn_setq_relaxed`/`__sn_clrq_relaxed` and `writeq` on `u64` fields. Linux never reads the widget id: `bs_xid` comes from the SAL topology call. Established.
- **(d) PROM.** Consistent with (a) to (c). The widget read helper `0xffab14f0` builds the window address from the nasid, the
  widget number and a link bit (no register offset, so `+0`) and calls `0xffaeb170` with size 4; that reaches the generic read
  at `0xffb0f4b0`, which accepts sizes 1, 2, 4 and 8. The helper itself returns `~0` when the status is zero, otherwise a 4-byte
  `ld4` of the result buffer. The sized-load routine at `0xffb5cf20` holds four predicated loads, `ld1` (`0xffb5cf40`), `ld2`
  (`0xffb5cf46`), `ld4` (`0xffb5cf50`) and `ld8` (`0xffb5cf56`), each `[r32]` into `r36`, the address unmodified, then
  returns the value in `r9` with status 0 (an unsupported size returns status 1 and value 0). Ghidra's listing with our IA-64
  module shows all four loads; the decompiler shows only the serialise. Zero extension is the `ld` definition, not a PROM
  step; the width of the store into the result buffer and the call from `0xffb0f4b0` into `0xffb5cf20` were not re-traced.
  Established for the instructions; there is no swap in them.

Not covered: the Crossbow's own endian behaviour (the same reading applies to widget 0 `+0`, `+8` and `+0xc0`, but no
crossbow-specific swap control was looked for), and TIO.

### Review

Independent check of the section, with Ghidra (our IA-64 module) on `shub1snprom.bin` and Linux v5.3 `arch/ia64/sn`,
`arch/ia64/include/asm/sn`.

- Confirmed: `+0` is bits 31:0 (the `0xd000`/`0xd100` part test on bits 27:12, the `+8` status field at bits 9:6, and
  `ii_wid_u` in `shubio.h`); the bit positions and names of IWC bit 0 `i_dma_byte_swap`, `PCIBR_DEV_SWAP_DIR` (bit 19),
  `ATE_SWAPSHIFT` (29) and `PCI64_ATTR_SWAP` (55); the IWC read, write-with-bit-0-clear, read sequence; Linux never writes
  `IIO_IWC` (only the offset is defined) and has no swap call anywhere in `arch/ia64/sn`; the four sized loads.
- Corrected: the part test is in `0xffab15c0`, not in the read helper `0xffab14f0`; `~0` on failure comes from that helper,
  not from the sized load; `0xffaad9f6` only forms the IWC address (the write is at `0xffaada3c`); the non-relaxed Linux
  readers also issue `mf.a` and a bridge flush; `pcibr_reg.c` also uses `writeq` and `__sn_clrq_relaxed`.
- `+4` stays inferred. No `ld4` at an `8n+4` widget or PIC word was found in the Linux tree (no 32-bit register access in
  `arch/ia64/sn`), and the PROM was checked only in the routines above, not exhaustively.
- Ghidra: the listing shows the loads at `0xffb5cf40` to `0xffb5cf56`; the decompile of `0xffb5cf20` is just `srlz_i(); return 0;`.
  Probably the module's prototype returns only `r8`, so the value in `r9` (the loaded result) is dead; a decompiler defect
  to report, not checked further.

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
clears psr.i and psr.dt (`rsm 0x24000`; psr.ic is not touched) around a single access, then runs `mf.a` and a serialise, so all
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
| B12 | `0xffab34b0` then `0xffab3260`, if part is `0xd000` or `0xd100` | crossbow handshake and link flags (table X, rows X1 and X2), then WCR: set `tag` (bit 4) | | established; any other part prints a warning, leaves WCR alone and makes the routine return 0, so `main` skips I/O (see [the handshake](#the-widget-0-handshake-io_llp_setup-0xffab34b0-and-what-follows-it)) |
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
| X6 | per valid link (not the hub's own): 4-byte id read at the link window; `0xffffffff` skips the link; part `0xd102` or `0xd112` is a PIC in `xbow_init`; the later walk in `0xffab0f10` sets up only `0xd102` (see [the instruction-level trace](#io-discovery-in-main_three-instruction-by-instruction-0xffab38b0)) | `0xd102` on a Altix 350 | | established |
| X7 | for a PIC link: link block `+0x08` = `0x80000`, `+0x18` = 0, `+0x20` = 0, then poll `+0x10` bit 31 up to 100 times at 1 ms | | alive within 100 ms | established |
| X8 | link credits (`0xffab0130`): link block `+0x08` bits 22:18 = table credits; widget `+0x20` (and `+0x80_0020` for a PIC) masked-written with `4 << shift`; 1 ms wait. Table at `0xffbe10e0`: `0xc120` credits 4 mask `0xe000` shift 13; `0xd102` and `0xd112` credits 3, mask `0xf000` shift 12; `0xd000` and `0xd100` credits 4, mask `0x7c0000` shift 18 | | read/write registers | established |

### D. Block transfer for PI-to-memory credits (conditional)

`main_three` calls `0xffa73b00` at `0xffad760c`. On the master it runs `0xffa736d0`: it writes `0x88c` to `0x81_2005_0d80`
(a processor interface register, not II; local-form address), reads `0x81_2006_0980` and takes bits 5:0. If that is below 8 it
zero-fills a 1 KiB buffer with the BTE (`0xffa952f0`: engine 0 or 1 by cr.lid bit 23, local alias
`0x80_0141_0000` or `0x80_0142_0000`; writes IBLS = length in lines with bit 20 set, IBSA, IBDA, IBNA, then IBCT = `0x11`,
notify and zero fill; polls the notify word for up to 10,000,000 timer units, microseconds by inference, see the BTE section) and re-reads the credits until they reach 8 or 1,000,000
units pass (messages "BTE failed trying to adjust pi2md credits" and "pi2md request credits at:%d, should be %d"). With 8 on the
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

## The II and BTE set-up after the first BTE read (`0xffab22d0`)

Read in Ghidra (IA-64 module, `--sn2-prom --no-analysis`) on `shub1snprom.bin` of snprom 10.54, from the disassembly. Names:
"2.4" is `include/asm-ia64/sn/sn2/shubio.h` in linux-mips at 8ef7d46c (offsets all match; it carries no INIT values for
the II, so every reset value stays **unknown**); "PROM" is the register-name table of the SHub 1 error decoder
(records `{name offset:32, field-list word:32, register offset:64}` at `0xffc075c0` to `0xffc08040`, name pool base
`0xffc08068`; pairing re-derived from `II_IGFX0`).

The stop at ip `0xffa0e5b0`, b0 `0xffab22d0`, is the `ld8` of `0x8_01c1_0018` called at `0xffab22cc`: IBCT0
(2.4 `IIO_IBCT0`, PROM `II_IBCT0`; fields `POISON`, `NOTIFY`, `ZEROFILL`, which are 2.4 bits 8, 4 and 0).
**It is a plain read.** The value is discarded: no instruction reads r8 between `0xffab22d0` and the next load, and nothing
compares it. It is not a poll and not a read-modify-write. The 2.4 header says a read terminates a transfer in
progress, so a model aborts a running transfer on it; the PROM has none running (inferred). Established.

All accesses below are one 8-byte `ld8` (`0xffa0e5a0`) or `st8` (`0xffa0e640`), global window
`0x8000_0008_0000_0000 + 0x180_0000 + offset | nasid << 38` (the II MMR window, never widget space), run
with psr.i and psr.dt cleared. All established.

| Step | Site | Access | Value, and what continues the boot |
|---|---|---|---|
| 1 | `0xffab22cc` | R `0x410018` IBCT0 | discarded; any value |
| 2 | `0xffab230c` | R `0x420018` IBCT1 (`II_IBCT1`) | discarded |
| 3 | `0xffab232c` | R `0x410000` IBLS0 (`II_IBLS0`) | discarded |
| 4 | `0xffab234c` | R `0x420000` IBLS1 (`II_IBLS1`) | discarded |
| 5 | stores `0xffab236c` to `0xffab257c` (IBLS0 first, IBIA1 last) | W 0 to IBLS0 `0x410000`, IBSA0 `+8`, IBDA0 `+0x10`, IBNA0 `+0x20`, IBIA0 `+0x28`; then the same five at `0x420000` | IBCT never written; plain storage suffices |
| 6 | `0xffab25bc` | W 0 to ILLR `0x400130` (`II_ILLR`) | |
| 7 | loop `0xffab264c` to `0xffab28dc`, 15 passes, offset `0x30 * n` | W 0 to `0x400400 + 0x30n + {0, 8, 0x10, 0x18, 0x20}` (`II_ICRBn_A` to `_E`) | |
| 8 | `0xffab294c`/`0xffab29ac`, loop `0xffab2a6c`/`0xffab2b4c` | R then W `0x400198` IPRB0, then `0x4001a0` to `0x4001d8` IPRB8 to F (`II_IPRB*`): value read OR bit 42 | any read value |
| 9 | `0xffab2bcc`, `0xffab2bfc` | W 0 to `0x400220` IIEPH1, `0x400228` IIEPH2 | |
| 10 | `0xffab2c00`, `0xffab2c2c` | R `0x400260` IWEIM (`II_IWEIM`), W value OR `0x8000` | any |
| 11 | `0xffab2c5c` | W `0x1fffff` to `0x4003c0` ICTP (`II_ICTP`), then return at `0xffab2c7c` | |

The routine calls only the two helpers. The listing check covered steps 1 to 5 and 9 to 11 line by line; the loops
(6 to 8) agree with the decompiler and with the earlier review. The routine writes no BTE control and starts no transfer.
IBIA is written 0 and never again; IBNA 0.

After the return, `0xffaad720` goes on in this order (listing re-read, all established, the same table as rows B2 to B13
above): `0xffab30e0` W `0xff01` to IOWA `0x400110` and IIWA `0x400118`; `0xffab2e60` R ILCSR `0x400128` (`II_ILCSR`) and
**bit 13 must be set** ("I/O brick attached", else return 0 and I/O is skipped; 2.4 `IIO_ILCSR`); `0xffab3020` (ILCSR bits
27:26 = 0); `0xffab3320` (WCR bit 17 = 0); `0xffab2f80` (ILCSR bit 10 set, wait 10 ms); `0xffab3640` (widget 0 status read,
bits 9:6); `0xffab33e0` (WCR bits 3:0 = that, bit 4 = 0); `0xffa91260`; IWC `0x400250` read, bit 0 cleared, read;
`0xffab14f0` (widget 0 id read; `0xffffffff` skips); `0xffab34b0` (part `0xd000` or `0xd100`, else a warning and return 0);
`0xffab3780` (ILCSR bits 5:0 = 3). Each read-modify-write waits 10 ms (`0xffa0db90(10000)`).

**Next large step: the Crossbow handshake `0xffab34b0`**, which calls `0xffaaf8b0` (link flags, the unbounded `+0xc0`
loop) and then `0xffab3260`. Read here only for its part test (`0xd100`, `0xd000`); `0xffaaf8b0` is as in rows X1 and X2.

### What the PROM does with the BTE (`0xffa952f0`, the block copy)

Arguments: source, destination, length in bytes (128-aligned, at most `0x7fffff`; a zero length returns 0 with no transfer, a misaligned or oversize
value, or a failed scratch-block allocation, returns 10), flags, notify pointer. The only caller passes one 128-aligned
1 KiB stack buffer as both source and destination, flags `0x11` and no notify pointer.
Used by the credit adjustment of section D. Established.

1. Engine: bit 23 of `cr.lid` picks engine 0 (clear) or 1, at the local alias `0x8000_0080_0141_0000` or
   `0x8000_0080_0142_0000`. A model must decode this form as well as the global window; the earlier "slice parity" wording
   named the same choice without the bit. A processor-id register 2 value of `0xaeeeeeee8badbeef` takes a simulation path
   that never touches the engine.
2. It stores `0xffffffffffffffff` in the notify word (a release store; the PROM's busy marker, unlike the Linux kernel's
   marker with bit 21 clear).
3. Writes, in this order: IBLS = `0x100000 | length >> 7` (busy set, length in lines), IBSA and IBDA with bits 63, 37 and
   36 cleared, IBNA the notify address, same mask, and last IBCT = flags `& 0x11`. IBIA is not written. The IBCT write starts
   the transfer; the PROM passes `0x11` (zero fill and notify).
4. The helper allocates a scratch block (`0xffac3da0`) that holds the engine base, the notify address and, when the caller
   gave no pointer, the notify word itself. With a caller pointer it frees the block and returns 0 at once. Without one it
   polls with `ld8.acq`: rounds of up to 1,000,000 reads, then a timer check (`0xffa0da70`) against start + `0x989680`,
   repeated until the deadline. It stops when the word is not all ones. Bit 16 of the final word clear means success: free
   the block, return 0. Bit 16 set (a timeout leaves all ones, so it is an error too): read IBLS once, print a message,
   run `0xffa94d40`, clear the notify word, and return the notify value with bit 16 cleared (so exactly `0x10000` returns 0).
5. A model must therefore: accept IBCT `0x11`, move or zero the memory, then store to the notify address a word that is not
   `~0` with bit 16 clear (the Linux kernel's status word, busy bit 20 clear, satisfies both). On success the PROM never
   reads the status register; on error it reads IBLS once for the message.

Graded: sequence and values established; engine choice by `cr.lid` bit 23 established. The timer `0xffa0da70` returns
rtc * P / 1000 for the clock at `0x1_101c_0000` (local form `0x81_101c_0000`) and `P = 10 * (field + 1)`, field = bits 13:4 of the
register at `0x1_1006_0280` (`0xffa0da00`), while `0xffa0db90(n)` waits `n * 1000 / P` ticks. That pairs P as nanoseconds per tick
and the timer as microseconds, so the BTE poll bound is 10 s: inferred (P's register is not named anywhere).

Corrections to the section above: B-section helper text says the helpers disable interrupt collection; it is psr.i. The
registers.toml field widths for BTE addresses (bits 48:7) and the interrupt node (11:1) are also what the 2.4 `shubio.h`
structs declare (`i_addr` 42 bits after 7 reserved, `i_node_id` 11 bits after 1); only the 2.4 comment prose says "bits 39:0".
The PROM's `ADDRESS<39:07>` is a field label, and its masks clear only bits 63, 37 and 36, so they keep bits 62:38 and are
consistent with the wider field.

### The PROM's block-transfer operations (BTE operations table)

Every site in SAL_B (snprom 10.54, `shub1snprom.bin`, flat at `0xffa00000`) that writes IBCT, found by searching the
whole image for the engine register addresses and reading each hit in Ghidra (IA-64 module, `--sn2-prom --no-analysis`) with
the objdump listing as the instruction check. A search of the address immediates would miss an address built by arithmetic;
the only built one known is the engine base in `0xffa952f0`. Nothing was run.

**IBCT decode** (Linux v5.3 `arch/ia64/include/asm/sn/bte.h` and `shubio.h`, GPL; the 2.4 `shubio.h` carries the same
bits). Bit 0 `IBCT_ZFIL_MODE` zero fill (the source is ignored and the destination is filled with zeros), bit 4
`IBCT_NOTIFY` write the notification word when the transfer ends, bit 8 `IBCT_POISON`. Linux `BTE_NORMAL` is notify alone
(`0x10`, a copy) and `BTE_ZERO_FILL` is `0x11`; `BTE_VALID_MODE` keeps bits 4 and 0 only. IBLS: busy bit 20, error bit 16, length
in bits 15:0 in cache lines (`BTE_LEN_BITS` 16; Linux converts `len >> L1_CACHE_SHIFT`, so 128-byte lines on SN2).
Established as definitions.

| Site (IBCT store, return ip) | Routine and caller | IBCT | Engine, window | Source, destination, length | Notify | Reached on a lone node |
|---|---|---|---|---|---|---|
| `0xffa9700c` (`0xffa97010`) and `0xffa9702c` (`0xffa97030`) | `0xffa96980`, called from `main_two` at `0xffa1b04c` | `0x10` copy plus notify, on both engines | engine 0 and engine 1 together, local alias `0x8000_0080_01c1_0000` and `0x8000_0080_01c2_0000` | src0 to dst0 and src1 to dst1; four 512 KiB heap buffers (`0xffac3da0`, 128-byte aligned), IBLS `0x101000` (busy plus `0x1000` lines) on each engine | a separate 8-byte zeroed word per engine, address masked | yes when debug-switch word bits 1:0 are not 1 (a zero word runs it); skipped when the word's bits 1:0 are 1, when `0xffa0ff30` is 0, or when `cpuid[2]` is the simulation marker |
| `0xffa95640` store, call `0xffa9564c` | `0xffa952f0` (block copy), only caller `0xffa736d0` (credit adjustment) | flags and `0x11` (the caller passes `0x11`: zero fill plus notify) | engine by `cr.lid` bit 23, local alias `0x8000_0080_0141_0000` or `0x8000_0080_0142_0000` | the 1 KiB stack buffer as source and destination, IBLS `0x100000 | length >> 7` | caller's scratch word, busy marker preset | only when the first read of `0x81_2006_0980` is below 8 |
| `0xffa7ae9c` (`0xffa7aea0`) | `0xffa7a960` (`memctl_mbist_credit_war`), from "Testing memory" (argument 4) and "Initializing memory" (argument 2) | `0x11` | engine 0, global window `0x8_01c1_0000 + nasid << 38` | zero fill; source, destination and notify address all equal the flagged bank's base, IBLS `0x100000 + 2 * (argument - register)` | the bank base (as IBNA) | first call yes if `0x1_0001_0068` reads below 4 (reset 0 gives IBLS `0x100008`); polls IBLS bit 20 clear, 2,000,000 ticks |

No other IBCT writer exists among the address immediates; the error clean-up `0xffa94d40` writes IBCR, IMEM and IECLR and never IBCT, and the II set-up `0xffab1cc0` only reads IBCT.

#### The two-engine copy test (`0xffa96980`)

Role (established): a copy self-test of both engines at once, after progress 27 in `main_two`. The mode it is called with is
`0xffa17b90(0)`, debug-switch word bits 1:0 plus 16 for bit 2 (`0xffa97660` and `0xffa975e0`; the first argument comes from
the stub `0xffb91cb0`, which returns 0); `0xffa96980` returns at once when the mode masked with 15 is 1. The gate
`0xffa0ff30` is the master-slice test (nonzero on a lone node, as the first part of `main_two` needs).

Sequence (established, listing and Ghidra agree):

1. Allocate four 512 KiB blocks (`0xffac3da0(align 128, size, arena)`) and two 8-byte words. Fill block 0 with `0xC3`, block 1
   with `0xA5`, blocks 2 and 3 (the destinations) with `0xAD` (`0xffa15b80` is a byte `memset`; the C argument is the 16-bit
   pattern but only the low byte is stored). Zero both words.
2. Write, in order, IBLS0 = `0x101000`, IBSA0 = block 0, IBDA0 = block 2, IBNA0 = word 0, then the same five on engine 1
   (block 1, block 3, word 1; the engine-1 values use IBLS1, IBSA1, IBDA1 and IBNA1). Each address is ANDed with
   `0x7fffffcfffffffff`, clearing bits 63, 37 and 36, which leaves `nasid << 38` and the physical offset (the arena sits in the
   node window, `prom-reset.md`). IBIA is not written.
3. IBCT0 = `0x10` at `0xffa9700c`, IBCT1 = `0x10` at `0xffa9702c`. No IBLS or IBCT read follows; the routine reads no BTE
   register.
4. Poll: read the timer (`0xffa0da70`; the deadline is that plus 30,000,000, microseconds by inference as for `0xffa952f0`).
   Loop while bit 20 of word 0 or of word 1 is set. Because both words were zeroed in step 1, bit 20 is already clear, so the loop
   is never entered: the PROM does not wait for the hardware. On a timeout the loop also just falls through (no message, no error clean-up).
5. `memcmp` (`0xffa166a0`) of block 0 against block 2 and block 1 against block 3, 512 KiB each. **Both results are discarded.**
6. Free the six blocks and return. Nothing is printed on any path.

The stop is therefore "accept the control write", not "complete a zero fill". Grades: sequence, values, order, the discarded
compare and the absent wait are established. The allocator's address form (a heap pointer in the node window, bit 63 and the
address-space bits possibly set before masking) is inferred from the masks and the arena construction; the arena base itself
was not re-derived here. The timer unit stays inferred.

Window forms: the PROM writes the same engine registers through three address forms: the local alias `0x8000_0080_01c1_0000`
(this routine), the local alias `0x8000_0080_0141_0000` (`0xffa952f0`) and the global form `0x8_01c1_0000 + nasid << 38`
(`0xffa7a960`, the II set-up). That the `0x0141` form is the same register block as the `0x01c1` form is carried over from the
review of `0xffa952f0` and not shown independently here: the two differ in bit 23, **unknown** how the hardware decodes it.

What a model must implement for the PROM:

- Accept IBCT `0x10` on both engines. No PROM path reads the result: completion, copying and the notification word are not
  tested here. For fidelity, copy `length` 128-byte lines from IBSA to IBDA (physical, node in bits above 37) and then store a
  completion word at IBNA; the Linux kernel's final-status word (busy clear, error clear) is what its caller waits for.
- Do it before the IBCT write returns, or accept a late write: the PROM frees the buffers (and the arena may reuse them) right
  after the compare, so a transfer that completes much later writes into freed memory (as hardware would).
- IBLS must be a plain writable register that reads bit 20 clear after the transfer (the mbist routine needs that); the error bit
  is read once by `0xffa952f0` on its failure path.

Unknown: what the hardware stores in the notification word on success (the Linux kernel's own status word is the only
evidence, and the kernel-side waiter treats anything but its busy marker as done); the engine's timing; the `0x0141` decode above.

### Review (II and BTE set-up)

Independent check, 2026-11-16, by a reviewer who wrote none of it: snprom 10.54 `shub1snprom.bin`, flat at `0xffa00000`, in
Ghidra (IA-64 module, `--no-analysis`) with the `ia64-linux-gnu-objdump` listing as the instruction check, and the 2.4
`shubio.h` at 8ef7d46c. The decompiler was used for navigation only.

Confirmed from the listing: the four IBCT0/1 and IBLS0/1 reads whose values are never used; the ten zero writes (IBLS, IBSA,
IBDA, IBNA, IBIA, per engine) with IBCT absent from every store in `0xffab1cc0` (its two addresses occur only in the reads);
ILLR; the 15 CRB A to E passes at stride `0x30`; the IPRB0 and IPRB8 to F bit-42 read-modify-writes; IIEPH1 and IIEPH2 zeroed;
IWEIM `|= 0x8000`; ICTP `0x1fffff`; the `0xffaad720` call order; IOWA and IIWA `0xff01`; ILCSR bit 13 (extract of bits
13:12 masked with 2) returning 1 when set and 0 when clear; ILCSR bits 27:26, WCR bit 17, ILCSR bit 10 and the 10 ms waits.
The helpers `0xffa0e5a0` and `0xffa0e640` run `rsm 0x24000` (psr.i and psr.dt), `mf.a`, restore psr.l and serialise.
For `0xffa952f0`: engine from `cr.lid` bit 23 (the same field, bits 26:23 plus 9, indexes a per-processor table for the scratch
block); notify word stored `-1` with release before any register write; IBLS `0x100000 | (len >> 7) & 0xffff`;
IBSA, IBDA and IBNA masked with `0x7fffffcfffffffff`; IBCT `flags & 0x11` last; the completion rule and the 1,000,000-read
rounds. Settled: the timer unit (microseconds, inferred, see above).

Changed: a zero length succeeds without a transfer and bad arguments return 10; the error path reads IBLS and returns the notify
word with bit 16 cleared; the poll is rounds repeated to a deadline, not one 1,000,000-read bound; "never read after the
start" held only for success; the slice-parity wording and the `0x81_0141_0000` alias in section D were wrong.

Field widths: 48:7 and 11:1 apply. The 2.4 header, read in full for IBSA, IBDA, IBNA and IBIA, declares exactly those widths; the
"39:7 and 8:1" statement came from the prose comment and the PROM label. registers.toml is unchanged and needs no regeneration.
The PROM masks do not discriminate between the two widths for the one caller (a stack buffer).

## The widget-0 handshake: `io_llp_setup` (`0xffab34b0`) and what follows it

Row B12 and B13 of the table above, read at instruction level in Ghidra (snprom 10.54, `shub1snprom.bin`, SAL_B). The PROM
names `0xffab34b0` itself: its warning string is "io_llp_setup: WARNING: Use of part 0x%x with SHUB unexpected!". Header
names are the 2.4 SN2 headers (`xtalk/xbow.h`, `xtalk/xwidget.h`, `sn2/shubio.h`); the 2.4 xbow header lists registers by
the MIPS word at slot + 4, the Itanium `ld4` reaches the same register at slot + 0 (see
[How the Itanium sees widget registers](#how-the-itanium-sees-widget-registers)). The PROM's own register-name table
(the II error decoder) has the II names `II_WID`, `II_WSTAT`, `II_WCR`, `II_ILCSR`; it has no names for widget 0 registers.
The only PROM name for the link flag word below is the debug-print field `xbow_port_info[%d].port_flag`.

Address forms. "II" is `0x8_0180_0000 + offset + (nasid << 38)` with bit 63 set, an 8-byte access through
`0xffa0e5a0` / `0xffa0e640`. "W0" is widget 0's small window: `0x8_0000_0000 + (nasid << 38)` with bit 63 set; for an odd
NASID bit 35 is left out (`0xffaaf8b0`, `0xffab14f0`, `0xffab3640` all test NASID bit 0). W0 accesses are 4-byte
`ld4.acq` / `st4.rel`. Established.

| # | Where | Space, offset, width | Dir | Value written / what it is compared with | Keeps the Altix 350 path | 2.4 name; PROM name | Grade |
|---|---|---|---|---|---|---|---|
| 1 | `0xffab34b0` | none: id word from B11, part = bits 27:12 | test | part == `0xd100` or `0xd000`; else prints the warning, returns 0 | `0xd100` (`0xd000` also passes; revision and manufacturer are not tested here) | `PXBOW_WIDGET_PART_NUM` 0xd100 ("PIC"), `XXBOW_WIDGET_PART_NUM` 0xd000; `io_llp_setup` | established |
| 1a | return path | none | | an unexpected part returns 0, so `0xffaad720` returns 0 (it returns the value of this call) and `main` sets flag 2: no I/O discovery. `0xffab3780` still runs. B12 above said only "leaves WCR alone" | | | established (return value read in `0xffaad720` at `0xffaada8c` to `0xffaadab0`) |
| 2 | `0xffab3720` (from `0xffaaf8b0`) | II `0x400020`, 8 | R | keeps bits 3:0 (`wid`, the hub's widget number). Used as the hub's link number | 8 to 15, else the later link scan (row C3) fails | `IIO_WCR`, field `wid`; `II_WCR` | established; "must be 8 to 15" inferred from C3 |
| 3 | `0xffaaf340` | W0 `+0x08`, 4 | R, once | keeps bits 9:6 as `v` | any; `v` is then written as is | `XBOW_WID_STAT` (`WIDGET_STATUS`), `XB_WID_STAT_SRCID_MASK 0x3c0`, shift 6 (header: Xbridge only) | established; field meaning from the header |
| 4 | `0xffaaf2e0` in a loop | W0 `+0xc0`, 4 | W then R, poll | writes `v`; reads back; exits when the 32-bit read equals `v`; otherwise waits 1000 microseconds (`0xffa0db90`, which polls the real-time clock at `0x1_101c_0000`) and writes `v` again. No bound | `+0xc0` must store 4 bits and read them back. An all-ones or zero read hangs the PROM unless `v` is 0 | `XBOW_LOCK` (`xb_lock`, Xbridge only); none | established; role as a lock acquire inferred (the register is named the lock, it is written with the requester's widget number, and row 8 writes the clear register) |
| 5 | `0xffaaf8b0` | W0 `+0x118 + 0x40 * (wid & 7)`, 4 | RMW | sets bit 0 | plain storage | `XB_LINK_ARB_UPPER(wid)` (`XB_LINK_REG_BASE + 0x1c` at the MIPS word); `xbow_port_info[].port_flag` | established offset and bit; meaning inferred. The PROM treats the register as a flag word, not an arbitration register |
| 6 | node operation slot 54 (`0xffa5d6a0`, PROM string `shub_port_status`) | no widget access: NI vector reads of ports 0 and 1 (`0x1_5000_0048`, `0x1_5000_0000` plus port << 13, through `0xffa0bd20`) | R | result is a two-bit mask, bit n = port n; non-zero sets bit 1 of the row-5 word | any (bit 1 is read only for a link whose part is `0xc120`, none on one node) | none | established; return decoded in the review below: bit n set when port n's NI status nibble is 9, so bit 1 of the flag word means at least one port is up |
| 7 | `0xffaaf8b0` | W0 `+0x118 + 0x40 * (other & 7)`, 4, where other = `0xa` (`0xb` if `wid` == `0xa`) | R | bit 2 clear: RMW own word `|= 5` (bits 0 and 2). Set and `wid` != `0xa`: own word keeps bit 0 (and bit 1 when row 6 is non-zero). Set and `wid` == `0xa`: clear bit 2 in the `0xb` word (`and -5`), then RMW `0x198` `|= 5` | the words start from the model's storage; no other link has bit 2, so the hub's link gets bits 0 and 2 | as row 5 | established |
| 8 | `0xffaaf8b0` | W0 own-link word, 4 | R, discarded | read after the stores, then `0xffaaf400` | any | | established |
| 9 | `0xffaaf400` | W0 `+0xc8`, 4 | W then R | writes 1, reads back, discards | any (a write-only or plain register is fine) | `XBOW_LOCK_CLR` (`xb_lock_clr`, Xbridge only); none | established; role as the release inferred |
| 10 | `0xffab3260` | II `0x400020`, 8 | R, W, R | sets bit 4 (`tag`), reads back (discarded), waits 10 ms | WCR holds what is written | `IIO_WCR` field `tag`; `II_WCR` | established |
| 11 | `0xffab3780(nasid, 3)` | II `0x400128`, 8 | R, W, R | read value with bits 5:0 (`nullto`) replaced by 3, written, read back (discarded), waits 10 ms | plain storage | `IIO_ILCSR` field `nullto`; `II_ILCSR` | established |

`0xffaaf8b0` returns 1 always. It also calls the node-record lookup `0xffa0fa00` (software only, no hardware access; it
fills a record and returns the node object whose slot 54 row 6 calls). The wait helper `0xffa0db90(n)` waits `n` microseconds
by reading the clock register `0x1_101c_0000` (read with `ld8`) until it has advanced; a model needs an advancing counter
there, and any value in the register at `0x1_1006_0280` (the tick period is `10 * (bits 13:4 + 1)` ns, inferred; never zero)
(established for the loop).

What reads keep the hardware path on a one-node Altix 350 with one PIC: part `0xd100` at W0 `+0x00`; WCR `wid` 8 to 15; W0
`+0xc0` that reads back what is written (or `v` of 0); the flag words plain storage. Nothing reads a link-up bit in this
section. The link-alive and present bits (`+0x10` bit 31, `+0x38` bit 5 of each link block) are read in rows X3 and X6 above,
after this handshake, in `main_three`.

Is there a Crossbow on an Altix 350? No discrete Crossbow chip is evidenced: the held material shows one SHub 1 and one PIC
on the riser ([base I/O page](../../platforms/sn2/altix-350-base-io.md)), and the PROM accepts parts `0xd000` and `0xd100`
only. The part the PROM expects at widget 0 is `0xd100`, which `xbow.h` glosses as "PIC": the Crossbow-compatible face a PIC
presents at widget 0 (the same part the Origin 350 and Tezro PROMs accept, see [PXBOW](../xbow/README.md#pxbow-part-0xd100)).
That the Altix 350's widget 0 is this face rather than an Xbridge (`0xd000`) is inferred, not read from hardware. Whether a
PIC implements `+0xc0` and `+0xc8` is unknown (the only measurement is an Octane2 Crossbow reading the lock as 0).

Next large step: I/O discovery in `main_three`, `0xffab38b0` (gate: master processor and flag 2 clear), which prints "Discovering
local I/O" and calls `0xffab15c0` (crossbow walk, rows C1 to C8). Between this handshake and it, `0xffaad720` returns and
`main` runs the memory phases; nothing in that range touches the II or widget 0 (established for the code read earlier; the
`main` text between `0xffa1a40c` and the memory phases was not re-read at instruction level here).

### Review (widget-0 handshake)

Same check and date. Confirmed in the listing: the part test (`extr.u` bits 27:12, `0xd000` or `0xd100`, else a message and
return 0); `0xffaaf8b0` reading WCR bits 3:0 through `0xffab3720`; the W0 `+0x08` read keeping bits 9:6; the `+0xc0` loop (4-byte
store, 4-byte reload through a stack spill, 32-bit compare, 1000 microsecond wait, no bound); the flag words at
`+0x118 + 0x40 * (wid & 7)` as 4-byte read-modify-writes; the other-link logic (other `0xa`, or `0xb` when wid is `0xa`; the
`0x198` word); `+0xc8` written 1 and read back; WCR `|= 0x10`; ILCSR bits 5:0 = 3, each followed by a 10 ms wait. An unexpected
part makes `0xffaad720` return 0 and its caller takes the non-positive path (`0xffa1a450`, a call with arguments 2 and 1). That
this call sets PROM flag 2 was carried from the earlier page, not re-read.

Added: `0xffab33e0` writes WCR bits 3:0 from that same W0 `+0x08` field (or `0xf` if its protected read failed) just before the
handshake, so the WCR `wid` that `0xffaaf8b0` reads back is the xbow's source id. A model needs W0 `+0x08` bits 9:6 in 8 to 15
and the same value in WCR. That 8 to 15 is required remains inferred from the link scan.

`shub_port_status` (`0xffa5d6a0`, slot 54 of the table at `0xffbd7c18`; that this table is the one the object's slot 54
reaches is inferred from the descriptor being in no other table) returns a mask. For port n it calls `0xffa5cf40`: read the NI
register at `0x1_5000_0048 + n * 0x2000`; if bit 27 is set, clear it, write, re-read, and if still set the port's result is 0;
otherwise read `0x1_5000_0000 + n * 0x2000`: low nibble `9` gives 1 (after a 4 by 128 read check outside simulation), anything
else gives -1 and a printed message. Negative results add no bit. Polarity: bit n set means port n looks up (nibble 9); the
caller sets bit 1 of the flag word when the mask is non-zero, so bit 1 means at least one NI port is up, and clear on a node with
no responding NI. What nibble 9 names is unknown.

Grades: "Widget 0 is the PIC's PXBOW face" stays inferred. Not re-read: `0xffaaf8b0`'s lookup `0xffa0fa00` beyond being software only.

## I/O discovery in `main_three`, instruction by instruction (`0xffab38b0`)

Read in the Ghidra listing of snprom 10.54 (`shub1snprom.bin`, SAL_B) from `0xffab38b0` through `xbow_init` (`0xffab0560`)
and every callee that touches hardware. Notation: "W0" is widget 0's small window and "link L" the window of widget L,
both from the address forms above; a link window for NASID n is `n << 38` plus `0x8000_0008_0000_0000 + (L << 24)` for an even
NASID, or `0x8000_0000_0000_0000 + (L << 28)` for an odd one (`0xffab1510`, `0xffab0160`). "Block L" is the link register block
`W0 + 0x100 + 0x40 * (L & 7)`. All W0, block and link-window accesses are 4 bytes (`ld4.acq` / `st4.rel`); the II accesses are 8
(`0xffa0e5a0`, `0xffa0e640`). Register names: widget and link-block offsets are the 2.4 headers' word offsets
(`xtalk/xwidget.h`, `xtalk/xbow.h`) minus 4, because the Itanium word at `+0` is what the MIPS header calls `+4`; the PROM has no
names for them (its name table covers II registers only). The PROM's flag word for each link is stored in block L `+0x18`,
the slot the header names `xb_link_arb_upper` (offset `+0x1c` there); that the PROM uses it as scratch storage and the
hardware meaning is ignored is established for the PROM, and the register's own behaviour is unknown.

The path is `0xffab38b0` (gates: master processor `0xffa0ff30`, then flag 2 via `0xffa99870`; prints "Discovering local I/O on
nasid %d") then `0xffab15c0(nasid)`, which looks up the node record `0xffaa8a40`, forms the W0 pointer from the record's NASID
halfword (+0x30) and calls `xbow_init`.

| # | Site | Space, offset, width | Dir | Value, compare, exit | Value that keeps the one-node Altix 350 path | 2.4 name; PROM name | Grade |
|---|---|---|---|---|---|---|---|
| 1 | `0xffab0560` (`0xffab3720`) | II `0x400020`, 8 | R | bits 3:0 (`0xffab3720` returns the doubleword `& 0xf`; the caller's sign extension of a byte changes nothing): `wid` | 8 to 15 | `IIO_WCR.wid`; `II_WCR` | established |
| 2 | `0xffaaf630`, first call | W0 `+0x118 + 0x40*(L&7)` for L = 8, 9, ... 15 (that is block L `+0x18`), 4 | R, up to 8 | stops at the first word with bit 2 set and returns L; none gives 0 | the word of link `wid` has bit 2 set (the PROM set it, row X2) | PROM `xbow_port_info[].port_flag`; message "Check_master: link %d is master" | established |
| 3 | `0xffab05cc` | none | test | master == `wid`, else prints "*** early return from xbow_init: master 0x%x, link 0x%x" (scanning again for the message) and returns | equal | | established |
| 4 | `0xffab066c` | none | call | `0xffaf2700` is `r8 = 0; return`; `0xffaf26f0` the same: both are empty stubs | | | established |
| 5 | `0xffab06b0` | W0 `+0x50`, 4 | R, value unused | one read before the stores | any | `WIDGET_TFLUSH` (word `0x54`); none | established (read happens, value ignored); role inferred |
| 6 | `0xffab06c0` to `0xffab0710` | W0 `+0x38` = 0; `+0x30` = master link `<< 16`; `+0x28` = `0x4000`; `+0x40` = 0; `+0x20` = `0x3c`; `+0x48` = `0x3ff1be0`, 4 each, in this order, once | W | no read back | accepted | `WIDGET_INTDEST_LOWER_ADDR`, `_UPPER_ADDR`, `WIDGET_REQ_TIMEOUT`, `WIDGET_ERR_CMD_WORD`, `WIDGET_CONTROL`, `WIDGET_LLP_CFG`; none | established (offsets, values, order); register names inferred from the standard widget header |
| 7 | loop `0xffab0720` (`0xffaaf700`, `0xffaaf430`) | block L `+0x10`, `+0x38`, 4, for L from the current link to 15 (links below 8 skipped) | R | valid if block `+0x10` bit 31 is set and block `+0x38` bit 5 is set. Otherwise: if W0's part (`ld4` at `+0` bits 27:12) is `0xd100`, link `0xb` is valid when `+0x10` bit 31 is set and link `0xf` is always valid. Otherwise invalid. A link with `+0x38` bit 5 set and `+0x10` bit 31 clear prints "WARNING: xbow_base: 0x%lx link: %d Widget present, but link not alive!" and is invalid. Returns the first valid link, -1 when none | the hub's own link and the PIC's link: both bits set. Any other link: `+0x38` bit 5 clear | `XB_LINK_STATUS` word `0x14`, `XB_STAT_LINKALIVE`; `XB_LINK_AUX_STATUS` word `0x3c`, `XB_AUX_STAT_PRESENT` (0x20) | established |
| 8 | `0xffab078c` (`0xffaaf7e0`) | block L `+0x18`, 4 | R | bit 0: the hub's own link (set at row X2 above) | own link only | `port_flag` | established; meaning inferred |
| 9 | not own link: `0xffab0520` then `0xffab0380` | W0 `+0` (4, R, the part again), then link L window `+0x20` = `(L | 0xf003000)` and, if W0's part is `0xd100`, also link L window `+0x80_0020`; each read back (value discarded) | R, W, R | `0xf003000` is `XBAR_CREDIT 3` in bits 15:12 plus bits 27:24 (all other bits of the old value are overwritten); low nibble L | accepted, any read | `WIDGET_CONTROL` word `0x24` (`WIDGET_WIDGET_ID` bits 3:0, `WIDGET_LLP_XBAR_CRD` bits 15:12); none | established (offsets, value); bits 27:24 unnamed in the header: unknown |
| 10 | `0xffab08cc` (`0xffab14f0`) | link L window `+0`, 4, through `0xffaeb170` | R | helper returns 0 on a failed protected read and the PROM maps that to `~0`; `0xffffffff` skips the link (and does a discarded read of block L `+0x28`, `0xffaaf840`) | the PIC's id word; for any other link nothing may answer (see "What an empty window returns" below) | `WIDGET_ID` | established |
| 11 | `0xffab07b0` | none | test | part (id bits 27:12) `0xd102` or `0xd112` takes row 12; anything else goes to row 13 | `0xd102` | | established |
| 12 | `0xffab0040(W0, L)` | block L `+0x28`, 4, R, discarded; `+0x08` = `0x80000`; `+0x18` = 0; `+0x20` = 0; then poll `+0x10` bit 31 | R, W, W, W, R | writes in that order. Poll: read, count, if bit 31 clear wait 1000 us (`0xffa0db90`) and read again; at most 100 reads and 100 waits; no message and no failure on timeout | bit 31 set within the first reads (the PROM does not need it) | `XB_LINK_STATUS_CLR` word `0x2c`; `XB_LINK_CTRL` word `0xc` (`XB_CTRL_WIDGET_CR_MSK` 22:18: `0x80000` is 2 credits); `XB_LINK_ARB_UPPER`, `XB_LINK_ARB_LOWER`; none | established; note the writes also clear the PROM's flag word for that link |
| 13 | `0xffab07d0` (`0xffab0130`, `0xffaaff60`) | block L `+0x08` RMW: `& ~0x7c0000 | credits << 18`; credits from the table at `0xffbe10e0` (`0xc120` 4, `0xd102` and `0xd112` 3, `0xd000` and `0xd100` 4; an unknown part prints "WARNING: Using default link credit counts" and takes 2); then link L window `+0x20` RMW masked by the table: for `0xd102` clear `0xf000`, set `0x4000`, and the same at `+0x80_0020`; 1 ms wait. For the hub's own link (part assumed `0xc120`): II `0x400020` RMW bits 15:13 = 4 (`0xffab3580`), read back, 10 ms wait | R, W (and R) | | accepted | `XB_LINK_CTRL`, `WIDGET_CONTROL.LLP_XBAR_CRD`, `IIO_WCR.dst_crd` | established |
| 14 | after the loop (`0xffab16b0`) | W0 `+0`, 4, via `0xffaeb170` | R | part `0xd000` or `0xd100` else prints "New Widget %x connected to HUB." and returns 0 | `0xd100` | `WIDGET_ID` | established |

After `xbow_init` returns, `0xffab0f10(W0 pointer, ...)` builds the hardware graph. Its hardware accesses, in order: II `0x400020`
(row 1 again); `0xffab19f0` which reads the W0 id (`0xffab1800`, `ld4` at `+0`, copied into the crossbar record as part and
revision) and runs the master scan (row 2) once more; a second master scan; then, when `wid` is the master (the one-node case), a walk of
links from 8: `0xffaaf700`, row 8, for a link that is not the hub's own the id read of row 10, and by part:

- `0xc120` (a NUMAlink to another hub, or the hub's own link whose id is not read): the own link makes a record; any other
  needs block L `+0x18` bit 1 (`0xffaaf810`), else "XBow link %d:no NUMAlink, skipping". Not reached on one node.
- `0xd102` only (`0xd112` takes the next case here, unlike `xbow_init` which accepts both for rows 12 and 13): PIC set-up
  `0xffab0c00` for the link window, again for the link window `+ 0x80_0000`, then `bridge_discover` `0xffabfb10`.
- anything else: "New Widget %x connected to HUB." and a record, no set-up.

Everything else in `0xffab0f10`, `0xffab19f0`, `0xffab1b60` and `0xffabfb10` is KLCONFIG construction (software;
[KLCONFIG](../../platforms/sn2/klconfig.md)), with these exceptions: `0xffabfb10` reads the brick's NIC string through the L1
(`0xffaf1ee0`; under the simulator signature, `cpuid[2]` equal to `0xaeeeeeee8badbeef`, it uses a built-in string) and reads each
bridge's identification word (`0xffab39f0`, a 4-byte `ld4` at `+0`).

**What the PIC set-up does is on the [PIC page](../pic/README.md#prom-set-up-of-a-pic-in-main_three-0xffab0c00).**

### Link-up and presence, in one place

A link counts as present and up for `main_three` when block L `+0x38` bit 5 and `+0x10` bit 31 are both set (row 7). The
exceptions are the `0xd100` widget 0: link `0xf` counts as valid whatever its bits say, and link `0xb` when only bit 31 is set. The
hub's own link needs the flag word bit 0 (row 8, set earlier by the handshake) and is valid by the same bit test. The PROM never
tests bit 2 of the flag word for presence: it is the "master" marker (row 2). The `+0x118 + 0x40 * (L & 7)` reads at `0xffaaf630` are
the master scan, not a link-up test. Established.

### What an empty window returns

Nothing in this section reads a link that is absent: row 10 is reached only for a valid link (rows 7 and 8). The protected
read helper `0xffaeb170` returns a status and the PROM treats a non-zero status as `~0`; what the hardware sends for a read to
an unpopulated widget window (a time-out error response, a machine check, `0xffffffff`) is unknown. Because the walk reads
only valid links, a model that gives block L `+0x38` bit 5 clear for every link except the hub's own link and the PIC's link never has
the PROM read an absent window, except row 14's re-read of W0.

### Review (I/O discovery in `main_three`)

Independent re-read of the rows above and of the PIC set-up they call, on 2026-11-16, in the Ghidra decompiles of snprom 10.54 (`shub1snprom.bin`, flat at `0xffa00000`, `--sn2-prom --sal-runtime`) with a Ghidra instruction listing of `0xffab0040`, `0xffab0560` to `0xffab0840`, `0xffab0c00` to `0xffab0f10`, `0xffab0130` and the II control-word helpers; no IA-64 objdump was available, so the listing is Ghidra's. The 2.4 widget and crossbar headers were not re-read; names are as graded above. At a model stop inside the leaf helpers `0xffa0e5a0` (load) and `0xffa0e640` (store), which run in a frame of two (`sof=2`), registers `r34` and above are out of frame and show stale values, so a register read there is not evidence.

**Confirmed (established, read in the decompile and the listing).**
- The `xbow_init` order: II WCR read, master scan (`0xffaaf630`, W0 `+0x118 + 0x40 * (L & 7)` bit 2, L from 8), the compare against `wid`, the empty stubs, one discarded `ld4.acq` of `+0x50`, then the six W0 stores in the order and with the values of row 6 (`+0x38` 0, `+0x30` master `<< 16`, `+0x28` `0x4000`, `+0x40` 0, `+0x20` `0x3c`, `+0x48` `0x3ff1be0`).
- The link-valid rule of row 7 and the link-up special cases, exactly: valid when `+0x10` bit 31 and `+0x38` bit 5 are both set, or, for a W0 part of `0xd100`, link `0xb` with bit 31 alone and link `0xf` always. The "link not alive" message is printed only for bit 5 set, bit 31 clear, and only when the link is not already valid by the `0xd100` exception. Links below 8 are skipped by `0xffaaf700`.
- The `0xd102` and `0xd112` link-up block (row 12): a discarded `ld4.acq` of `+0x28`, then `+0x08` `0x80000`, `+0x18` 0, `+0x20` 0, then at most 100 reads of `+0x10` with a 1000 us wait after each read that finds bit 31 clear (100 reads, 100 waits at worst, no failure).
- The credit step (row 13), including the table at `0xffbe10e0` (`0xc120` 4, `0xd102` and `0xd112` 3, `0xd000` and `0xd100` 4; unknown parts default to 2 with the message), the `0xf000` mask with shift 12 for a PIC (and the same read-modify-write at `+0x80_0020`), the 1 ms wait, and the own-link path (II control word bits 15:13 = 4, read back, 10 ms).
- Both link windows for the `0xf003000 | L` write (row 9) are 4-byte stores at `+0x20` and, for a `0xd100` widget 0, at `+0x80_0020`.
- The PIC set-up is reached only for part `0xd102` in the walk of `0xffab0f10`, for window `W` then `W + 0x80_0000`; `0xd112` falls to "New Widget %x connected to HUB.". No PCI configuration access is made on this path.

**Changed.** Row 1 said the WCR `wid` is the low byte sign-extended; `0xffab3720` masks it to bits 3:0 (the listing shows the `sxt1` after the call, harmless for 0 to 15).

**Not confirmed from the decompile.** The discarded read-backs after the `0xf003000` write (row 9) are not visible: the decompiler drops unused loads, and the listing of `0xffab0380` was not dumped. Treat "each read back" as the earlier reader's listing reading, inferred here. The `0xffa0ff30` and flag-2 gates in front of `0xffab38b0` and the `0xffab1b60` record builder were not read.

**Grades.** Unchanged: the rows stay established for access, offset, value and order; names and the meaning of unnamed bits stay as graded.

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
