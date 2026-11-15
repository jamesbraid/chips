# SHub 2: address map, identification register, reset-path accesses and memory set-up

The SHub 2 node controller as the SHub 2 first-stage and second-stage firmware sees it, written for someone modelling the chip. The firmware image is `shub2snprom.bin` from snprom 10.54 build 70399 (sha256 `3ea833181fda8968a5297043f2260d2fc255983ecca1d418292ee008b5e2c793`, checked against the root's checksum list; 12 MiB mapped at `0xff400000`). Its banner reads "SGI SAL Version 1.54 rel081111 IP65 built 07:28:01 AM Nov 11, 2008" (the earlier SHub 2 build held is 1.40 from package 10.40; [images.md](../../software/firmware/snprom/images.md) did not record 10.54's version). The FIT places SAL_A at `0xff674000` (0x3000 bytes) and SAL_B at `0xff401000`. The chip family is described in [README.md](README.md); SHub 1 is the contrast throughout ([prom-reset.md](prom-reset.md)).

**Grades.** *established*: read in full in this image (code path, table or string) or defined by Linux v5.3. *inferred*: reasoned, reasoning given. *unknown*: not settled. A value the firmware tolerates is a software expectation, not a hardware fact. No SHub 2 reference manual is held; no register here has an established reset value.

**Tools.** Every code reading below was done in Ghidra with the IA-64 processor module (`re-run --ghidra-export IMAGE --sn2-prom`, decompiler output plus the module's slot listing for exact sites). Names marked "PROM name" come from the register-name table the image carries for its error decoder (strings in the shipped binary: a table of name, address and field list, with bit ranges); the table's own field ranges are read from the image and are the source for every field layout given here. Linux v5.3 names (`arch/ia64/include/asm/sn/addrs.h`, `shub_mmr.h`, `arch.h`, `sn_sal.h`, `arch/ia64/sn/kernel/setup.c`) are cited as "Linux". Objdump was used only to cross-check one routine's bytes.

## 1. Address map

### Address forms the firmware issues

The firmware runs in physical mode with bit 63 set on every device address (uncached). Two MMR window bases, both in node-offset bits below the node number:

| Window | Base | Form | Source |
|---|---|---|---|
| Local MMR | `0x2_0000_0000` | `0x8000_0002_0000_0000 + offset` | SAL_A and SAL_B constants (established); Linux `SH2_LOCAL_MMR_OFFSET` (established) |
| Global MMR | `0x3_0000_0000` | `0x8000_0003_0000_0000 \| (nasid << (40 - V)) \| offset` | SAL_B routines at `0xff414e00`, `0xff414fa0`, `0xff4aeaa0` (established); Linux `SH2_GLOBAL_MMR_OFFSET` (established) |

Register offsets are the 32-bit values of the PROM name table and of Linux `SH2_` constants (Linux's `SH2_RTC` is `0x2_101c_0000`, which already carries the local window; the PROM's name table lists the same register as `0x101c_0000`). The offset space is 32 bits wide (up to `0x3fff_ffff` in the table), with a few registers at offset bit 32 (Linux `SH2_PTC` `0x1_7000_0000`).

### NASID shift and mask (established)

SAL_A selects the node-addressing parameters from a five-row table in SAL_A (at `0xff676000`, rows of 0x80 bytes) indexed by V, the 64-bit value read from `0x2_2011_0000` (PROM name `SH2_ADDRESS_MODE`; field `CODE` bits 2:0, bits 63:61 reserved). Row V holds, in order:

| V | NASID shift (40 - V) | NASID width (10 + V) | NASID mask | AS shift (38 - V) | node-offset mask |
|---|---|---|---|---|---|
| 0 | 40 | 10 | `0x3ff` | 38 | `0x3f_ffff_ffff` |
| 1 | 39 | 11 | `0x7ff` | 37 | `0x1f_ffff_ffff` |
| 2 | 38 | 12 | `0xfff` | 36 | `0xf_ffff_ffff` |
| 3 | 37 | 13 | `0x1fff` | 35 | `0x7_ffff_ffff` |
| 4 | 36 | 14 | `0x3fff` | 34 | `0x3_ffff_ffff` |

The row also holds the three AS values (1, 2, 3 shifted by the AS shift: GET, AMO, cacheable), the value `shift - 4` (36 at V=0, the same quantity Linux's `SH2_NETWORK_BANK_OFFSET` uses), a copy of the AS shift and the width. The NASID field therefore always ends at bit 49 and starts at 40 - V. The firmware stores the row's address (low 32 bits, bit 63 set) in a register, `0x2_101d_0c00` (PROM name `SH2_SCRATCH24`), and every later NASID shift is read back through it: that register is firmware scratch, not a chip identity register. The PROM's `SN_SAL_GET_SN_INFO` (SAL_B at `0xff5838b0`, read in full) returns mask `(1 << (V + 10)) - 1` in bits 15:0 and shift `40 - V` in bits 23:16 of its second value, shub type 1, log2 of the maximum node count `V + 10`, and a sharing-domain size of 9 or 11 by one bit of the node-id register (section 2). Linux then takes `as_shift = shift - 2`, which matches the table (established).

A value of V above 4 indexes past the table; the firmware does not mask or check it (established as the code; the hardware never reports it on a working chip is inferred).

What V is on real hardware is unknown; the shipped table covers 10 to 14 bit node numbers, and Linux's `MAX_NUMALINK_NODES` of 16384 is the V=4 case (established).

### How the local and global windows split

The Linux offsets 0x2_0000_0000 and 0x3_0000_0000 are bit 33 and bits 33:32 of the address. With shift 36 to 40 the AS field starts at bit 34 to 38 and the NASID field above it, so both offsets lie inside the node-offset field (below the AS bits), not in the NASID or space-id field SHub 1 uses (SHub 1 puts the local MMR space id 2 in the NASID field: `0x80_0000_0000`). Reading of what the firmware does, all established as the addresses it forms:

- A local MMR access is `bit 63 | 0x2_0000_0000 | offset` with the NASID, AS and every bit above 33 clear. It needs no node number.
- A global MMR access to node n (including the issuing node itself) is `bit 63 | 0x3_0000_0000 | (n << (40 - V)) | offset`: the same address with bit 32 also set and the node number in the NASID field. The firmware computes `40 - V` from the register at `0x2_2011_0000` every time it forms such an address.
- So bit 33 selects MMR space and bit 32 selects "use the NASID field": inferred (it is the only reading that fits every address constant; no document states the decode). That the chip ignores bit 32 when the NASID field is nonzero, or treats AS bits as anything but zero in these accesses, is unknown.
- The SAL_B per-node scratch words are reached the same way: `0x3_0000_0000 | (id) << (40 - V) | 0x5003_15xx` (tables at `0xff5fa618` and `0xff5f73c0`): offsets `0x5003_1590`, `15b0`, `15e0`, `15f0` and `0x5003_12c0`, `1280`, `15c0`, `1b50` and the like (established as constants; use unknown).

The routine at `0xff414e00` builds a global address from a 16-bit compact id: bits 6:0 and 15:10 become the node number as `((id[15:10] << 7) | id[6:0]) << 1` (an even NASID, SHub), bits 9:7 select one of four offsets `0x5003_15e0`, `15f0`, `1590`, `15b0` (established). The routine at `0xff4150b0` forms the TIO form (odd NASID): `bit 63 | nasid << shift | (1 << (38 - V)) | 0x8000_0000 | offset` with no global bit, matching Linux's `(1 << AS_SHIFT)` TIO form (established as the arithmetic; chiplet meaning from Linux header comment, inferred).

### The memory window

- Cacheable memory space is AS = 3: `(3 << (38 - V))` (table entry; Linux `AS_CAC_SPACE`, established). The firmware addresses its own node's data area at node offset `0x100_0000` (16 MiB) through the local compatibility space as physical address `0x100_0000` with bit 63 clear (about twenty pointer loads at `0x100_0010` to `0x100_0070`, established) and another node's as `0x8000_0000_0100_0000 + (3 << (38 - V)) + (n << (40 - V))` (routine `0xff4d0350`, established). That the two address the same bytes on the local node is inferred.
- AMO space is AS = 2 and GET is AS = 1 (table entries, established; same values as SHub 1 per Linux).
- Remote flash remap: the register at `0x2_2011_0008` (PROM name `SH2_FIRMWARE_REMAP`: `ENABLE` bit 60, `OFFSET` bits 32:24) is written by `0xff420910` with `(arg & 0x1_ff00_0000) | 1 << 60` (established access; meaning inferred from the name).
- I/O: the firmware prints "SHUB2 does not support XIO I/O." (established string). SHub 2 has no II big or small windows (SHub 1's `0x1c0_0000` window arithmetic does not apply); I/O sits behind the TIO nodes (odd NASID, Linux `TIO_IO_BASE`, established).

### Differences from SHub 1

| | SHub 1 | SHub 2 |
|---|---|---|
| NASID field | bits 48:38 fixed, 11 bits, shift 38 (Linux fallback and SAL 5.04 constants) | bits 49:(40 - V), 10 to 14 bits, shift 40 - V, V from a register |
| AS shift | 36 | 38 - V |
| Local MMR window | NASID-field space id 2: `0x80_0000_0000` | bit 33: `0x2_0000_0000` |
| Global MMR window | node-offset top bit: `0x8_0000_0000` | bits 33:32: `0x3_0000_0000` |
| Register offsets | `0x1_xxxx_xxxx` (bit 32 set) | `0x xxxx_xxxx` below bit 32 (mostly SHub 1 offset minus `0x1_0000_0000`) |
| Where the firmware keeps the node number | bits 42:32 of `0x1_1006_0580` | `NODE_ID` field bits 45:32 of `0x1006_0f00` (section 2) |
| I/O | II windows | none; TIO only |

Cross-check against [address-map.md](../../platforms/sn2/address-map.md): its constants for both windows agree. Its "SHub 2 NASID shift and mask: unknown" is settled here for the firmware's view: shift `40 - V`, mask `(1 << (V + 10)) - 1`. Its question "how SHub 2 splits local and global MMR" is answered above at inferred grade.
