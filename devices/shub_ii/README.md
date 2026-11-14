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

- **Sequence (established, `bte_copy` in the SN2 BTE code).** Clear the notification word in memory, then write source,
  destination, notification address, length, and last the control word. The control write starts the engine. The kernel
  writes the length register with a plain length and no busy bit; the header says a legitimate write sets busy and clears
  error. Completion is a write of the final status word to the notification address. The kernel decides busy from the
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
