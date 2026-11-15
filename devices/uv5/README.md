# UV5 (UV 500 generation) hub registers

Per-generation hub MMR map: part number 0xa171. Uses the RH10 address-map registers (0x470000 group) with wider base fields (bits 51:25); no BAU or GRU register groups appear in the kernel header, and the node id register loses the nodes-per-bit field. The generated map holds only the 25 registers the header defines for it.

The map is generated mechanically from SGI's Linux platform header by [tools/uv-import](../../tools/uv-import/parse.py):
offsets and field positions come from the header's address macros and field masks and are **established** as
definitions; the access letter (read-only or read-write) is the header's comment on each field, where it gives one.
Role text on a register is a paraphrase of how the kernel uses it and is **inferred**; most registers carry none. Reset
values are **unknown** (the header states none). Registers appear only where the kernel header defines them for this
generation; the rest of the hub is unknown. Register offsets by generation are side by side in
[the MMR address map](../../platforms/uv/mmr-address-map.md); window bases, node numbering and interrupt delivery are
on the [platform page](../../platforms/uv/README.md). The BAU and GRU contracts are in [uv_bau](../uv_bau/README.md)
and [uv_gru](../uv_gru/README.md).

Reference: [registers.toml](registers.toml), [registers.md](registers.md).
