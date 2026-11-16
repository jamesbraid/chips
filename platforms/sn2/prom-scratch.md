# SHub 2 firmware words at 0x5003_xxxx: registers, not memory

The SHub 2 PROM (SAL 1.54, snprom 10.54 build 70399, `shub2snprom.bin`) reads and writes a group of 64-bit words at offsets `0x5003_1000` to `0x5003_1bff` of the node's register space. This page settles what they are. Neighbours: the chip page [devices/shub/shub2.md](../../devices/shub/shub2.md), the address map [address-map.md](address-map.md), the SHub 1 equivalents [devices/shub/prom-reset.md](../../devices/shub/prom-reset.md).

**Grades.** established: read in the image at the site named. inferred: reasoned, reasoning given. unknown: not settled.

## Answer

They are SHub 2 memory-mapped registers, not node memory used as scratch. The PROM happens to use a few of them as plain storage.

- **Address (established).** The firmware forms them exactly like every other SHub 2 register: local window `0x2_0000_0000 | offset`, or global `0x3_0000_0000 | node << (40 - V) | offset` ([shub2.md](../../devices/shub/shub2.md#how-the-local-and-global-windows-split)). Bit 33 selects the register window (inferred, [shub2.md](../../devices/shub/shub2.md#how-the-local-and-global-windows-split)), so an address of this form is not memory, which carries the NASID and AS fields and no window bit ([address-map.md](address-map.md)). Every access is a 64-bit `ld8`/`st8` through the same two helpers (`0xff4207a0` read, `0xff420840` write) as the other register accesses, with data translation switched off around the access (`rsm` of two `psr` bits, 0x24000, which are `psr.i` and `psr.dt` by the architecture, read in the helpers).
- **Names (established).** The image carries a register-name table for its error decoder: records of a packed name pointer and an offset. Pairing was checked on records whose meaning is known: `0x101d_0200`, `0x0280`, `0x0300` come out as `SH2_SCRATCH4`, `SCRATCH5`, `SCRATCH6` and `0x101c_0000` as `SH2_RTC`. In that table every offset in `0x5003_1000` to `0x5003_1fff` that the PROM touches is a crossbar debug register: `SH2_XN_*_CMP_EXP_DATA0/1`, `_CMP_ENABLE0/1`, `_CMP_EXP_HDR0/1`, `_CMP_HDR_ENABLE0/1`, "compare expected data" and "compare enable" registers of the node's crossbar (the XN unit) beside `SH2_XN_DEBUG_SEL` and `SH2_XN_TRIGGER_*` at `0x5003_1000` to `0x5003_1060`. The SHub 1 header of SGI's 2.4 SN2 kernel (linux-mips `linux-2.4` at `8ef7d46c94d5`, `include/asm-ia64/sn/sn2/shub_mmr.h`) defines the same family at `0x1_5003_1000` and up, 64 bits wide with all 64 bits implemented and reset value zero (SHub 1; the SHub 2 reset value is unknown). Linux v5.3's header does not carry them.
- **Use (inferred).** The PROM uses them as storage because they are free 64-bit read/write registers that nothing else on the node needs during boot. A model must keep all 64 bits; whether a non-zero value arms a hardware debug trigger is unknown.

This also settles SHub 1: `0x1_5003_1500`/`1510`/`1530`/`1540`/`1550`/`1560` are `SH_XN_MD_IILB_CMP_*` and `SH_XN_MD_NI0_CMP_*` registers by the 2.4 header ([prom-reset.md](../../devices/shub/prom-reset.md) updated). Their SHub 2 counterparts are `0x101d_0300` (SCRATCH6) and neighbours in a different block ([shub2.md](../../devices/shub/shub2.md)); the SHub 2 PROM moved its shared words, and kept these XN words for other uses.

## The words

All in the local window as `0x2_0000_0000 | offset`; the registers are in [registers.shub2.toml](../../devices/shub/registers.shub2.toml) under the PROM's names.

| Offset | PROM name | Meaning from the code | Grade |
|---|---|---|---|
| `0x5003_1240` | `SH2_XN_IILB_PI_CMP_EXP_DATA0` | **Board type.** Stored once at `0xff482690` in the routine at `0xff4824e0` after the DIMM layout check; accepted values `0x7b`, `0x200`, `0xa00`, `0xe00`, anything else stops with "unknown board type". Read back at `0xff41e390`, `0xff41e810`, `0xff476050`, `0xff476530`, `0xff477e40`, `0xff478030`, `0xff480f80` and `0xff43fe50` (a predicate, routine `0xff43fe30`, true when the word is `0xe00`). A ninth site, `0xff47e840`, forms the address but its access was not classified | store, value set and predicate established; role of each reader inferred |
| `0x5003_15e0`, `15f0`, `1590`, `15b0` | `SH2_XN_MD_SIC_CMP_HDR_ENABLE0`, `_ENABLE1`, `SH2_XN_MD_NI1_CMP_EXP_DATA1`, `SH2_XN_MD_NI1_CMP_ENABLE1` | **One word per processor slice (0 to 3).** The compact-id lookup `0xff414e00` picks one by bits 9:7 of the id (indices 4 to 7 select four other registers, `0x1000_0880`, `0980`, `0a80`, `0b80`, see [shub2.md](../../devices/shub/shub2.md)), and `0xff414d80` reads one by a table. A routine at `0xff414ca0` stores one caller-supplied value to all four (read from the slot listing). Nothing writes anything else to them in the node set-up list. Content unknown; the caller keeps bits 51:50 of the value read | addresses, store and read paths established; content unknown |
| `0x5003_15c0`, `1b50`, `12c0`, `1280` | `SH2_XN_MD_SIC_CMP_EXP_HDR0`, `SH2_XN_NI0_MD_CMP_EXP_HDR1`, `SH2_XN_IILB_NI1_CMP_EXP_DATA0`, `SH2_XN_IILB_NI0_CMP_EXP_DATA0` | First four-entry list of the node set-up zeroing (`0xff40c360`, tables of 4 offsets in the image data): one word per slice. Later use not traced | zeroing and names established; use unknown |
| `0x5003_15d0`, `1b40`, `12d0`, `1290`, `1700`, `1710`, `1800`, `1810` | `SH2_XN_MD_SIC_CMP_EXP_HDR1`, `SH2_XN_NI0_MD_CMP_EXP_HDR0`, `SH2_XN_IILB_NI1_CMP_EXP_DATA1`, `SH2_XN_IILB_NI0_CMP_EXP_DATA1`, `SH2_XN_NI0_IILB_CMP_EXP_DATA0/1`, `SH2_XN_NI0_LLP_CMP_EXP_DATA0/1` | The second and third lists of the same zeroing | same |

## Is anything zeroing them before use?

Yes, on the path read: the node set-up routine `0xff40c360` writes 0 to the twelve words in the last two rows, and `0xff4429c0` writes 0 to 44 more `0x5003_xxxx` words (the full list is in [shub2.md](../../devices/shub/shub2.md), row W2); the two lists are the ones listed there as established. The board-type word is not in either list; it is first written by the store above, and the readers run after it (inferred from the call order, not traced to every caller). The four slice words are in neither list and the sites that write them were not matched to a call in the reset path, so whether they read zero on first use is unknown. A model that zeroes the whole `0x5003_1000` block at reset satisfies every access found.

## Not settled

- What the slice words hold, and which routine calls the store at `0xff414ca0` (the call is indirect through the thunk at `0xff43fdf0`).
- Whether any XN compare register has a hardware effect during boot, and the SHub 2 reset values.
- The three zeroed lists' later reads. The per-routine reading here was done on the slot listing; a full Ghidra decompile of the SAL_B code did not finish within the memory and time limits available, so decompiler output was not used.
