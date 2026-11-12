# Hub I/O interface

The Hub's I/O interface is its port onto Crosstalk (XIO). It is the block at offsets `0x400000` and up
in the Hub register space: the widget face, the protection registers, the link control, the
interrupt destination and the big-window translation entries. The census of the shipped kernel
reaches most of these offsets. The register list and the reset-value status are in
[gen/docs/hub.md](../gen/docs/hub.md). This page covers what the public Linux SN0 Hub I/O header
adds, and what stays open.

The fields below come from the public Linux SN0 Hub I/O header, Linux 7.2-rc7, as machine-readable
constants in [defs/hub_extra.toml](../defs/hub_extra.toml). The header gives names, offsets and
masks. It gives no access types and no reset values, so every reset here is unknown.

## Added from the public header

- **Widget identification** at `0x400000` (inferred as a whole). Revision in bits 31:28 and part
  number in bits 27:12 (established). The header's comment gives the Hub's part number as `0xc101`.
  Manufacturer number is bits 11:1 (established, value not named here).
- **Local access protection** at `0x400100` and **protection override** at `0x400108`. Offsets and
  names only (inferred). The header gives no fields and no unlock value.
- **Big-window translation entries** at `0x400160`, eight bytes apart, seven of them (established
  layout, inferred access). Bits 4:0 are the slice, bits 11:8 the target widget, bit 12 the I/O space
  bit. The header numbers the entries 0 to 6 and notes that the hardware manuals number them 1 to 7.
  Its comment says the top entry (index 6) stands in for the first small window
  because of a processor-interface bug (inferred: a software expectation).
- **Widget status** at `0x400008`: the crazy bit is bit 32, the transmit retry timeout bit is bit 9
  (established), and the transmit retry counter is bits 22:16 (see the open question below).
- **Widget control** at `0x400020`: the Hub's own widget number is bits 3:0 (established). The
  direct-connect bit is bit 17.
- **Link control and status** at `0x400128`: link-up is bit 13 (established as a mask, and the
  header names it IS_UP). The status field is bits 13:12, and the header names the value 2 WORKING
  (inferred). Other fields: warm reset bit 8, link enable bit 10, eight-bit mode bit 11, maximum
  retry bits 25:16, maximum burst bits 41:32 and null timeout bits 5:0 (established from the header's
  structure).
- **Link log** at `0x400130`: check-bit error count in bits 31:16 and sequence-number error count in
  bits 15:0 (established).
- **Interrupt destination** at `0x400138`: sent bit 28, enable bit 24, destination node in bits 15:8
  and interrupt number in bits 5:0 (established from the header's masks).

## Open

- **Entry 0 and entry 6 overlap the census.** The census has `hub_piomap_alloc` at `0x400160`
  under an inferred name, and a write-only register `mlreset` at `0x400190`. The header's entry 6 is
  also at `0x400190`. One reading is wrong for that offset. A Hub specification, or a read of the
  offset with its writer identified, would settle it.
- **Transmit retry counter width.** The header's mask gives seven bits (22:16), and its bit-field
  structure for the same register gives eight bits (23:16). The width stays open until a Hub
  specification settles it.
- **Interrupt destination node width.** The reviewed header has only masks for this register: eight
  bits for the node and six for the number. A wider reading is not in this tree and is not
  confirmed here.
- **Link status values other than WORKING.** The header names no other value of bits 13:12, and the
  meaning of the warm reset bit at the far end of the link is not in this source.
- **Reset values** of every Hub I/O register: unknown. No public source in this repository states
  them. A read of each register on a Hub before firmware writes it would settle them.
