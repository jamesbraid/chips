# Hub block transfer engines

The Origin 2000 Hub (SN0) has two block transfer engines, BTE 0 and BTE 1, in its I/O section.
Each copies or zero-fills a range of node memory in 128-byte cache lines without the processor
touching the data. The register map and the decode of the length/status word are in
[devices/hub/README.md](README.md) and the generated reference
[devices/hub/registers.md](registers.md). The Bedrock (SN1) engines are a separate page,
[bedrock-io-interface.md](../bedrock_ii/README.md).

## Register slots added from the public header

Chips' census of the shipped IRIX kernel did not reach every engine slot. These are in
[devices/hub/registers-extra.toml](registers-extra.toml), with their grades:

- Engine 0 notification address at `0x410020` and engine 0 and engine 1 interrupt addresses at
  `0x410028` and `0x420028` (offsets established from the public Linux mainline SN0 Hub I/O
  register header, tag v6.12). The header gives no access type, so the access is an assumption
  and the registers are graded inferred.
- Interrupt address fields: the level occupies bits 22:16 and the destination node bits 8:0.
  The header's masks give these positions.
- Control/terminate bits: zero-fill is bit 0, notify is bit 4 and poison is bit 8. The header names
  all three and gives no behaviour for them beyond what the Theory of Operations says below.
- Length/status busy is bit 20.
- The I/O error clear register has an engine-0 and an engine-1 error-clear bit at bits 17 and 18.
  The header marks both meanings as uncertain, so they are inferred.

## Page migration and the poison bit

The Origin and Onyx2 Theory of Operations, SGI part 007-3439-002 revision 002, says the BTE moves
the page data during page migration and replication, after the operating system has decided to
move or replicate a page (section "Page Migration and Replication", printed page 49). This is
the only use of the engine that the manual gives.

The same manual describes directory poisoning (printed page 50). In that scheme the copy sets the
Poisoned state in the source page's directory entry, so a stale translation faults and the
operating system then shoots down that one TLB entry. The manual labels directory poisoning
"an architectural feature which is being proposed for future implementations". Where poisoning is
not available, the operating system does a conventional TLB shootdown instead.

So the poison bit's effect is documented only as a proposal. Whether a shipped Hub revision
implements it is unknown. Chips has the kernel's poison-copy routine (see the Hub README's
`bte_poison_copy` entry), but no source shows that the hardware sets directory state for it.

## Unknown

- The access type and reset value of each engine register, which no public source states.
- What a completion writes to the notification address, and whether a notify-mode and an
  interrupt-mode completion can both fire for one transfer.
- Whether a load of the control register terminates a transfer, and what it returns.
- How an error reaches software, beyond the error bit and the I/O error clear bit.
- Whether shipped hardware implements directory poisoning, and what a poisoned directory entry
  does to a later access.
