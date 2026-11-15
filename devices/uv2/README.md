# UV2 (UV 2000 and 3000 generation) hub registers

Per-generation hub MMR map: part numbers 0x8eb8 and 0x1111. The first generation the current kernel still supports. The RTC register is replicated per cache line; the RTC comparator pending bit is in event register 2 (UV1 has it in register 0); MMR32 window kept.

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
