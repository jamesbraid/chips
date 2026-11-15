# UV1 (UV 1000 generation) hub registers

Per-generation hub MMR map: part number 0x88a5. The oldest generation; only the v3.10 and v5.4 headers carry it. It has a 64 MiB local window and the original GRU, BAU and RTC register groups, and a dual_hub bit in the MMR overlay register. The header's target physical apic id mask register (0x320130) shares its address with the third BAU activation status register that UV2 and UV3 define; whether it is the same register is unknown.

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
