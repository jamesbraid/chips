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

## 2. The identification register

**Address.** Local `0x2_1006_0f00`, global `0x3_1006_0f00 | (nasid << (40 - V))`. PROM name `SH2_NODE_ID`. The Linux v5.3 header defines only the SHub 1 counterpart (`SH1_SHUB_ID` at `0x1_1006_0580`, revision field bits 31:28 only) and no SHub 2 identification register, so nothing here is Linux-defined; the layout below is read from the image's own field table (established as the table's content; the field meanings are inferred from the names).

| Bits | PROM field name | Notes |
|---|---|---|
| 0 | `FORCE1` | reads 1 by its name (inferred) |
| 11:1 | `MANUFACTURER` | no code reads it (established: no reader found in SAL_A, SAL_B or the runtime) |
| 27:12 | `PART_NUMBER` | no reader found; value unknown |
| 31:28 | `REVISION` | no reader found; the encoding is unknown (Linux: SHub 1 revision at the same bits) |
| 45:32 | `NODE_ID` | the node number; the firmware reads `(value >> 32) & mask` with the mask from section 1 |
| 47:46 | `SHARING_MODE` | read as `(value >> 46) & 3`; the firmware also writes it |
| 53:48 | `NODES_PER_BIT` | the firmware reads bits 53:49 (5 bits) to size a bit vector, and writes the 6-bit field |
| 54 | `SHARERS_1K` | tested by the firmware: clear selects a sharing domain of 512 nodes (log2 9) and shifts the node id by 9, set selects 2048 (log2 11) and 11 (`SN_SAL_GET_SN_INFO`, `0xff5838b0`; and the coherence-id computation) |
| 55 | `RANGE_CHECK` | set by the firmware in a later phase |
| 56 | `NI_PORT` | no reader found |
| 57 | reserved | |
| 58 | `SYSTEM_TYPE` | no reader found |

Where it is read (established): SAL_A never touches it. Every later read of the node number goes through the routine at `0xff420290`, which returns `(read(0x2_1006_0f00) >> 32) & (*(table row + 0x38))`, the row being the one SAL_A left in `0x2_101d_0c00` (about 260 call sites). The runtime's `SN_SAL_GET_SN_INFO` reads it for bit 54. The interconnect phase (outside the reset path) writes it on a node: `NODE_ID` from the discovered number (14-bit field), `SHARING_MODE` in 47:46 as 0 for fewer than 32 nodes, 1 below 64, 2 below 128, else 3 (from the node count), `NODES_PER_BIT` from the sharing group size (1, 2, 4, 8, 16 or 32 per bit), and `RANGE_CHECK` set (routine `0xff4a9880`, established).

**The chip identification word (offset 0).** The part number and revision the firmware acts on are read from offset 0 of the node, not from `SH2_NODE_ID`: local `0x2_0000_0000`, global `0x3_0000_0000 | (nasid << (40 - V))`, the same place the SHub 1 firmware reads at `0x1_0000_0000`. The routine at `0xff4231e0` (called early in `main`, `0xff42b790`) does one 64-bit read through `0xff419e80` and stores bits 27:12 as the part number and bits 31:28 as the revision (established). It then offers the part number to three method tables in turn (array at `0xff5fd888`); each table's method 1 accepts exactly one part number: `0x254` (596, first table), `0x239` (569, second), `0x4422` (17442, third); a miss leaves the node's table pointer 0 (established). Which chip each is: unnamed in the image. The first table is the one the node-level code of a SHub 2 uses (inferred from table order against the SHub 1 firmware, which lists its SHub part number first; `0x239` and `0x4422` also appear in the SHub 1 firmware's list, where they are not SHub 1, so they are probably the router and TIO parts; inferred). The register has no entry in the image's name table, so its name and field layout beyond those two fields are unknown.

**What the PROM tests of `SH2_NODE_ID`.** Nothing about its part number, revision or manufacturer fields: no read of the register extracts them (established by listing every read). Compared with SHub 1, which selects among four method tables by part number (first `0x4363`), SHub 2 selects among three (first `0x254`).

**What a model must return.** Bits 45:32 = this node's NASID, even (SHub) and fitting the V in section 1. Bit 54 consistent with the intended sharing-domain size (0 for a domain of 512). Bits 47:46 and 53:48 hold whatever was last written, 0 before the firmware writes them (inferred: the firmware writes before it relies on them; no read before a write was found). The register must be writable in bits 55, 53:46 and 45:32. The offset-0 word must return part number `0x254` in bits 27:12 for the SHub 2 method table to be selected (inferred as the SHub 2 part; a value that matches none leaves the node without a method table and later calls through it fail); the revision field 31:28 is stored, never tested (established); real revision encodings are unknown. `SH2_NODE_ID`'s own part number, revision and manufacturer fields: any value passes.

**Unknown.** The real revision encoding and manufacturer code; the register name and layout of the offset-0 word; the reset value of `NODE_ID`; whether bit 58, 57:56 mean what their names say.

## 3. Reset-path accesses (SAL_A, the SAL_B reset entry and the start of `main`)

Order and form follow [prom-reset.md](prom-reset.md). Sites are PROM addresses in this image (Ghidra module listing). R is a read, W a write; widths are 64 bits unless given. Names are the image's own register-name table (PROM name) where it has one; Linux v5.3 defines only `SH2_IPI_ACCESS0..3` of the registers below. Every address is shown as its offset in the local window (`0x2_0000_0000 + offset`, bit 63 set); "what a read must return" is the software expectation, not a hardware reset value. Grades: *established* means the instruction, address, width and direction were read in full here; meanings are *inferred* unless stated.

### The progress write

SHub 1 wrote a history word in scratch memory and two LED registers per code. SHub 2 does one 16-bit store of the code to `0x2_f000_0000 | ((cr.lid >> 23 & 3) << 16)` (the four "real junk bus" LED ports, Linux `SH2_REAL_JUNK_BUS_LED0..3` at `0xf000_0000 + 0x1_0000 * n`, established), so slice n writes port n. No history word and no second LED register. The PROM's name table also has four LED registers at `0x1003_0000 + 0x80 * n` (`SH2_JUNK_BUS_LED0..3`, field `LEDn_DATA` bits 7:0), which the firmware reads (`0xff420420`, `0xff420760`: R64 `0x2_1003_0000 | slice << 7`) only to remember the current code while it waits on a lock, and to pass to SAL_B from SAL_A on reasons 1, 2 and above 3 (`r31`). Any value is accepted; nothing branches on it (established). Codes on this path: `0x30` (SAL_A hand-off), `0x31`, `0x35`, `0x08`, `0x0c`, `0x0d`, `0x0e`, `0x10` and onward; `0xb0` to `0xb4` are fatal stops.

### SAL_A (`0xff674000`, reason 0; reason 3 is the PAL-pair selection and returns to PAL)

SAL_A is entered at `0xff674030` by the FIT's SAL_A entry. For reason 3 it also reads `0x2_1003_8200` (`SH2_RACK_SLOT_DATA`, the register `0xff674d10` tests bit 39 of; established) and spins forever if that bit is set and bit 3 of PAL's `r33` is set; this is not on the reason 0 path (the routine returns before the read for reason 0).

| # | Site | Access | Value | What the code needs | Grade |
|---|---|---|---|---|---|
| S1 | `0xff6745d0` | W `0x2_1002_0000` (`SH2_JUNK_BUS_TIME`: `TIMEOUT_VALUE` bits 47:16, `SETUP_HOLD` bits 2:0) | `0xffff_ffff_0003` (timeout `0xffffffff`, setup/hold 3) | accepted | established (access); inferred (meaning: junk-bus access timing) |
| S2 | `0xff6745e0` | R `0x2_2011_0000` (`SH2_ADDRESS_MODE`) | V | must be 0 to 4 (index into the table at `0xff676000`); see section 1 | established (use) |
| S3 | `0xff674650` | W `0x2_101d_0c00` (`SH2_SCRATCH24`) | `(table[V] & 0xffffffff) \| 1 << 63`, the SAL_A table row address | the write must read back; every later NASID computation loads the row through it | established |
| S4 | `0xff674800` | R `0x2_2011_0010` (`SH2_PROCESSOR_TYPE`, `CODE` bit 0) | selects bits 2:1 (bit clear) or 3:2 (set) of PAL's `r33`; the two bits are swapped and become `cr.lid` bits 24:23 (`0xff674b80`) | any value; the register must not fault | established (access); inferred (what `CODE` means) |
| S5 | `0xff674696` | W (release) `0x2_101d_0088` (`SH2_SCRATCH1_ALIAS`) | slice + 1 (`cr.lid` bits 25:23, plus 1; 1 to 8) | accepted | established |
| S6 | `0xff6746a0` | R (acquire) `0x2_101d_0080` (`SH2_SCRATCH1`) | compared with slice + 1 | must read exactly slice + 1 after S5 on the winner. The alias at `+8` is a write path onto the same word (inferred from the name and the use) | established (test); inferred (alias) |
| S7 | `0xff6746f0`, `f6`, `0xff674700` | W `0x2_101d_0300`, `0x2_101d_0280`, `0x2_101d_0380` (`SH2_SCRATCH6`, `SCRATCH5`, `SCRATCH7`) | 0 | plain storage; winner only | established |
| S8 | `0xff674726` | W `0x2_0001_00d8` (`SH2_PIO_RQ_CRD_CTL`, `DEPTH` bits 5:0) | 2 | accepted (PIO request credit depth 2; inferred from the name) | established (access) |
| S9 | `0xff674750`, `70`, `90`, `b0` | W `0x2_1006_0c00` = 1; `0x2_1006_0c80`, `0d00`, `0d80` = 0 (`SH2_IPI_ACCESS0..3`, Linux names) | 1, 0, 0, 0 | accepted. IPI access 0 = 1 as in the earlier build; SHub 1 wrote one register | established |
| S10 | `0xff674536` | R `0x2_101d_0080` (second check) | compared with slice + 1 again | winner reads slice + 1; a loser skips S11 | established |
| S11 | `0xff674570`, `0xff674580` | RMW `0x2_101d_0100` (`SH2_SCRATCH2`) | bits 41:39 set to 7 | plain storage | established (access); unknown (reader) |
| S12 | `0xff6744b0` | W16 `0x2_f000_0000 \| slice << 16` | `0x30` | accepted. SAL_A then jumps to SAL_B offset 0 | established |

The fatal-error branch (`PAL r35` bit 2 set and bits 1:0 not zero: `0xff6740d6` to `0xff674180`) writes progress `0xb0`, RMW clears bits 29:26 of `0x2_101d_0300`, ORs `0x280_0000_0000` into `0x2_101d_0080`, writes `0x1_0001_0000_0000` to `0x2_2000_0000` (`SH2_CRB_MESSAGE_CONTROL`) and spins; byte 1 of `r20` other than 0 or 7 stops with `0xb2`. These are not taken in a normal reset. The register set matches what [the earlier 1.40 reading](../../software/firmware/snprom/README.md#shub-registers-the-first-stage-writes-shub-2-sal_a-established) lists, address for address; the 1.54 build's election value uses the 3-bit `cr.lid` slice field (bits 25:23), which the earlier page also gave.

### SAL_B reset entry (`0xff401000` to `0xff42fe30`, reason 0)

| # | Site | Access | Value | What the code needs | Grade |
|---|---|---|---|---|---|
| B1 | `0xff42fed0` | W16 progress | `0x31` | as above | established |
| B2 | `0xff4a9810` (called `0xff42ff40`) | W `0x2_1006_0700` (`SH2_GC_SRC_CTRL`) | `0x1_0000_0000` (`SOURCE_SEL` 33:32 = 1) | accepted | established |
| B3 | same | W `0x2_101c_0000` (`SH2_RTC`, 55-bit counter) | 0 | the counter restarts from 0 and counts afterwards (the firmware times 500-microsecond and 1000-microsecond waits with it) | established (access); inferred (restart) |
| B4 | same | W `0x2_1006_0700` | `0x1_0000_0041` (`SOURCE_SEL` 1, `MAX_COUNT` bits 13:4 = 4, `ENABLE_COUNTER` bit 0) | the clock must advance. The firmware converts to microseconds as `counter * (MAX_COUNT * 10 + 10) / 1000` (reads `0x2_1006_0700` bits 13:4 each time, helper `0xff41ffa0`; established arithmetic), so with 4 the counter advances 20 per microsecond for the firmware's timing to be right | established |
| B5 | `0xff42f4e0` (via `0xff4b3580`) | R `0x2_101d_0300` (`SCRATCH6`), bit 21 + slice | bit clear: the PAL entry point is used unchanged. Bit set: translated through RAM tables. The bits are written by B8 | S7 zeroed the word, so the bit reads 0 | established (test) |
| B6 | `0xff4d0350` (called `0xff42ffc6`) | R `0x2_1006_0f00` and `0x2_101d_0c00`, about 40 reads each | the node number and the table row (section 1) | the node number must be stable | established |
| B7 | `0xff42fe30` | W16 progress | `0x32` (in `0xff4b3c30`), then `0x35` | as above | established |
| B8 | `0xff421bd0(slice + 0x15)` and `(slice + 0x23)`, `0xff42feee` onward | lock cycle L(bit) setting bits 21 + slice and 35 + slice of `0x2_101d_0300` | see below | lock reads 0; word reads back | established |

**The node lock (L).** Routine `0xff421430` (set or clear a bit) and `0xff421ad0` (set a field) of `SCRATCH6`; the same shape on `SCRATCH7` at `0xff4ae770`. One cycle: R64 `0x2_1003_0000 | slice << 7` (remember the code); R64 `0x2_101c_0000` and `0x2_1006_0700` (clock); R64 `0x2_101d_0208` (`SCRATCH4_ALIAS`) repeated, with a 1000-microsecond wait between reads and a progress-code xor `0xff` each wait (`0xff423680`), until it reads 0, with a 1,000,000-microsecond deadline after which the firmware writes 0 to `0x2_101d_0200` (`SCRATCH4`) and keeps polling; then R `0x2_101d_0300`, W `0x2_101d_0300` with the bit or field changed; W `0x2_101d_0200` = 0 to release (established). Hardware behaviour of `0x...0208` on read (a read-to-take lock) is unknown; a plain register that always reads 0 satisfies every access. SHub 1 used the same offsets `0x101d_0200/0208`.

**Second lock and claim.** `0xff4221b0` (claim bit n in `0x2_101d_0280`, `SCRATCH5`, with an optional deadline) and `0xff422c90` (clear): poll R `0x2_101d_0280` until bit n is clear, take `0x2_101d_0188` (`SCRATCH3_ALIAS`, read until 0), test-and-set the bit, W `0x2_101d_0180` = 0 to release (established). Not on the direct reset path (callers are indirect).

### `main` (`0xff42b9c0`) to the first console message

| # | Site | Access | What the code needs | Grade |
|---|---|---|---|---|
| M1 | `0xff420290` (about 260 call sites) | R `0x2_1006_0f00` bits 45:32 masked, R `0x2_101d_0c00` | the node number | established |
| M2 | progress `0x08`, then `0xff4b2850(0)` | local-master arbitration, progress `0x0c`. For each slice 0 and 1 other than this one, `0xff425bb0` reads `0x3_...` global `0x2002_0010` (`SH2_FSB_SYMMETRIC_AGENT_STATUS`, `CPU_0_ACTIVE` bit 0, `CPU_1_ACTIVE` bit 1, `CPUS_READY` bit 2) until two consecutive reads agree and are non-zero, then tests bit n. SCRATCH6 bits `0x1a` + slice (this slice present), `0x2f` + 3 * (n & 1) (a 3-bit field per slice pair) and 500-microsecond polls up to 5,000,000 microseconds. A single-processor node with CPU_0 only: bit 0 = 1 for slice 0, bit 1 = 0 | the register must return a stable non-zero word (for example bit 0 set, bit 2 set) | established (access); inferred (bit meanings) |
| M3 | progress `0x0d`, `0xff4b2c90` | second barrier on `SCRATCH6` bits `0x1e` + i and `0x1a` + i, bit `0x22`, each read back; same lock | word reads back as written | established (access) |
| M4 | `0xff42b790` | chip identification read, offset 0 (section 2): `0x3_0000_0000 \| nasid << (40 - V)` | part number `0x254` | established (access) |
| M5 | `0xff42c8b0`, `0xff43b460`, `0xff430b00`, `0xff5b2f40` | method-table calls (indirect through the table chosen in M4); `0xff430b00` is the node set-up that reaches the console. "Prom starting..." is printed after these | the L1 UART block `0x2_1003_8000` (`SH2_ASIC_TO_L1_DATA`), `0x...8080` (`ASIC_TO_L1_STATUS`), `0x...8100` (`L1_TO_ASIC_DATA`), `0x...8180` (`L1_TO_ASIC_STATUS`) and the status reads at `0xff4a71c0` (R `0x1003_8180`, `0x1003_8080`, `0x1001_0000`, `0x1001_0080`) | not traced beyond the named registers |

**Not traced.** The call chain after M4 goes through method tables (indirect calls) down to the L1 console start; only the registers whose constants the PROM's own helper functions form (the L1 UART block, event registers `0x1001_0000` and `0x1001_0008`, the interrupt configuration registers) were located by searching the listing, not by following the calls. The order and values of the console accesses, and the part of `main` between "Prom starting..." and "Init memory...", are unknown to this page.

### Differences from SHub 1

- Progress codes go to one junk-bus LED port by a 16-bit store; no history word at `0x1_5003_1500 + 16 n`.
- The firmware's shared scratch word is `0x2_101d_0300` (SCRATCH6, was `0x1_5003_1550`), its second word `0x2_101d_0280` (was `0x1_5003_1540`), third `0x2_101d_0380` (was `0x1_5003_1560`); the lock registers keep the same offsets `0x101d_0200/0208` and `0x101d_0180/0188`; the election pair `0x101d_0080/0088` is the same, now with slice + 1 up to 8.
- SAL_A writes `SH2_IPI_ACCESS0..3` (four registers) and `SH2_PIO_RQ_CRD_CTL`; there is no write of a constant `0x1503_1010` as SHub 1 A1.
- The clock control is `0x1006_0700` (`SH2_GC_SRC_CTRL`), a different offset from SHub 1's `0x1006_0280`, with the same start sequence.
- The node number is read from `0x1006_0f00` bits 45:32, not `0x1006_0580` bits 42:32; the part number from offset 0 as before (`0x254` first).
- The firmware's node-addressing table row is held in a SHub register (`SCRATCH24`) instead of a constant.
