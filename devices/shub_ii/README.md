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
  error. The kernel then waits until the notification word stops reading as the busy marker, so a model must leave that marker, not zero, in place until the transfer completes. Completion is a write of the final status word to the notification address. The kernel decides busy from the
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
1. "Clear the notification word in memory" is not what `bte_copy` does: it stores the busy marker (every bit set except bit 21), and waits until the word changes. A model must see that marker, not zero, before the transfer completes.
2. The page's claim of 109 of 119 Bedrock offsets in common was not re-derived (it needs the Bedrock page); it is graded as a hypothesis and fills no field, so it does not affect clearance.

**Cleared:** offsets, counts, strides and field positions of all 60 entries; the fifteen-register use count; the 0x1c00000 arithmetic; the BTE sequence apart from finding 1. **Not cleared:** role and "inferred" text (inferred by design), the Bedrock overlap figure, and any behaviour of the BTE or CRBs on real hardware.

Findings 1-8 addressed in the commit "docs: address the SN2 SHub review findings"; renewed review needed for the changed claims.
