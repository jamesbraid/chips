# TIO and TIOCA: what the SHub 1 firmware (Prism) does, and what a model must answer

Question. The Prism runs the SHub 1 PROM, so the TIO class methods in that image decide what a Prism's TIO and TIOCA must answer. The
[SHub 2 page](prom-access.md) covers the other build. Which TIO and TIOCA registers does the SHub 1 PROM touch, in what order, and
which answers does Linux's TIOCA provider then rely on?

**Image and method.** Read: `shub1snprom.bin` of snprom 10.54 (SAL 5.04, sha256 `51ccf9ad...34617`, flat at `0xffa00000`, SAL_B at
`0xffa01000`, SAL global pointer `0xffd98000`). The whole image was analysed and decompiled in Ghidra (IA-64 module, `--sn2-prom
--sal-runtime`), and every address, immediate, mask and store width quoted as established was read in an `ia64-linux-gnu-objdump` listing
of the same bytes. Where only the decompiler shows a value, the entry says so. Nothing was run and no hardware was read. **Not read:**
SAL 4.65 (snprom 10.15) and SAL 4.90 (10.40): those images were not in the workspace. The
[4.65 against 5.04 comparison](../../platforms/sn2/prism.md#sal-465-against-sal-504-ghidra-read-2026-11-22) calls `tio_init`,
`ca_discover` and `tioca_space_to_xtalk` the same code and `tioca_attach` the same up to the closest-node loop; the register rows below
are therefore 5.04 rows, and 4.65 is inferred to match.

Kernel side: the public linux-sn2 tree (`arch/ia64/sn/pci/tioca_provider.c`, `include/asm/sn/tioca.h`, `tioca_provider.h`,
`pcibus_provider_defs.h`, `addrs.h`, `sn_sal.h`, branch `master-epic-sn2`) and the 2.6.5-7.308 reading on
[the Prism page](../../platforms/sn2/prism.md#tioca-kernel-expectations-265-7308-read-2026-11-21). Grades as in [AGENTS.md](../../AGENTS.md):
established is the instruction-level fact, a software expectation is a value code needs, never a silicon measurement.

## Addressing (established)

- Every register access is one 8-byte uncached load (`0xffa0e5a0`: `ld8` then `mf.a`) or store (`0xffa0e640`: `st8` then `mf.a`) with
  interrupt collection masked. Read and write wrappers `0xffa0bd20` and `0xffa0c560` take a route word first. Zero means the direct
  access; non-zero takes the vector path (`0xffa0cec0`), not read here.
- Register offsets in the PROM's immediates and tables carry bit 38 (`0x40_0000_0000`) as a marker for the TIO local block. The accessor
  strips it. The address is `0x8000_0008_0000_0000 | NASID << 38 | offset` (`0xffa0bd20` listing: `xor` of bit 38, `or` of
  `0x8000000800000000`). `0x8_0000_0000` is Linux's SHub 1 `GLOBAL_MMR_OFFSET`, so a TIO register `0x9006_0e80` is Linux
  `GLOBAL_MMR_ADDR(nasid, 0x9006_0e80)`. Offsets without bit 38 and with bit 32 set (`0x1_xxxx_xxxx`) take
  `0x8000_0008_0000_0000 | NASID << 38 | offset`; offsets with neither get `+ 0x180_0000` added. The second form is the SHub's. The
  `+ 0x180_0000` twins in immediates such as `0x40_9186_0000` and `0x40_b180_8880` sit on the dead branch of the same inlined macro and are
  never reached with bit 38 set (listing `0xffa985e0` to `0xffa986a0`).
- Corelet n of a TIO is at `0x8000_0000_0000_0000 | NASID << 38 | n << 28` (tio_init advances by `0x1000_0000`; `0xffaaeb96`).
- The chip identification word is read through the SHub-style form `0x8000_0009_0000_0000 | NASID << 38` (offset `0x1_0000_0000`;
  `0xffa0f8c0`, `movl 0x100000000`): part in bits 27:12 (stored as a 16-bit value), revision in 31:28.

## TIO class (established)

Four class tables hang off the array at `0xffbd8a18`: `0xffbd7c18` (name "SHub", accept part `0x4363`), `0xffbd7f98`, `0xffbd8318` and
`0xffbd8698`. The fourth is the TIO: name method `0xffa97cc0` returns "TIO", accept `0xffa97ce0` returns true for part `0x4422` only
(`mov r14=17442`). The class selector `0xffa0f7e0` calls each class's accept with the part and revision of the node record. Slot numbers
match the SHub 2 build for every slot used below. Slot entries, as `slot` `address`:

`0x28` early init `0xffad01e0` - `0x30` late init `0xffad05b0` - `0x108` node number `0xffa97fe0` - `0x120` chipset early init `0xffa98170` -
`0x140` `0xffa98b60` - `0x148` `0xffa98ca0` - `0x168` and `0x170` read and write of `0x901d0080` `0xffa97d10`, `0xffa98fa0` - `0x1b8` `0xffa614e0` -
`0x1d8` routing tables `0xffa620a0` - `0x228` `0xffa90430` - `0x288` `0xffa94570` - `0x298` chip info `0xffa946b0` - `0x2a8` `0xffa329f0` -
`0x2e0` `0xffaade10` - `0x2e8` corelet discovery `0xffaadef0` - `0x2f8` `0xffa1efd0` - `0x308` `0xffa7bff0` - `0x318` `0xffaad610`.
Slots `0x18` and `0x308` are empty returns. The 5.04 image prints "Initializing headless node" and "Late initialization of headless node" from
slots `0x28` and `0x30` as the SHub 2 image does.

## 1. Identity and TIO_NODE_ID (established)

- **Identity word** (`0xffa0f8c0`, the node-record builder): one 8-byte read at the SHub-style offset `0x1_0000_0000` (above). Part (bits
  27:12) selects the class; revision (31:28) is kept in the node record. A TIO answers `0x4422`.
- **TIO_NODE_ID, `0x9006_0e80`, writer** = slot `0x108`, `0xffa97fe0`, called directly from the routing-table install `0xffa620a0` at
  `0xffa62bfc`, after slot `0x1b8`. It reads `0x9006_0e80`, replaces bits 45:32 with the node's NASID (`dep.z` 32 width 14, mask
  `0xffffc000ffffffff`) and writes it back, then reads it again, replaces bits 53:48 with `2^k` (`dep.z` 48 width 6, mask
  `0xffc0ffffffffffff`; k is the count of nine-bit groups in the call's last argument, `shr 9` loop at `0xffa98076`) and writes it back. Two
  read-modify-writes, not one. Bits 47:46 and 31:0 are never changed. The SHub 2 build does the same through a single merged path
  ([SHub 2 page](prom-access.md#order-of-events-established-unless-marked)).
- Readers of `0x9006_0e80`: the TIOCA attach (`0xffb61186` onward) takes the revision from bits 31:28; slot `0x120` reads bits 53:48 back.

## 2. Route rows, ITTE and error-interrupt rows, early-init stores

All 8-byte accesses, local-block offsets as above. SHub 1 and SHub 2 match for the sets below, checked by listing.

**Route install** (slot `0x1d8`, `0xffa620a0`), per network port n = 0 and 1, then shared: `0xd002_4000 + 0x2000 n + 8 i` and `0xd002_4800 + 0x2000 n + 8 i`
(256 entries each, read-compare-write, bit 63 set on the value); `0xd002_5000 + 0x2000 n` := 0; `0xd003_0490 + 0x200 n` bit 0 set when a port flag is
set; `0xd003_0520 + 0x200 n` bits 15:8 := `0xc0` (`mov r14=49152`) when the first argument is 0; then `0xd002_0000 + 8 i`, `0xd002_0800 + 8 i`,
`0xd002_1000` := 0; slot `0x1b8` (`0xffa614e0`): `0xd000_0020 + 0x2000 n` bits 9:0 := `0x190` (`and -1024`, `or 400`), and `0xd003_0500`, `0xd003_04b0`
and `0xd003_04c0` (+ `0x200 n`) with the low nibble of each 16-bit lane cleared (`and -16`, `-983041`, `0xfffffff0ffffffff`, `0xfff0ffffffffffff`);
then the node-number write (section 1). The per-port tail (`0xd002_5000`, `0xd003_0520`, `0xd003_0490`) is a loop at `0xffa62c20` entered from
`0xffa626cc`; the exact order of the last two inside the loop is not separated here. What the registers mean is inferred, as on the SHub 2 page.

**Early init, slot `0x28` (`0xffad01e0`), in order:**

1. Slot `0x120` (`0xffa98170`): `0x9006_0700` := `0x1_0000_0041` through slot `0x140` (args 2 and 50: `(50/10 - 1) * 16 | 1 << 32 | 1`; `0xffa98bf0`);
   `0x901c_0000` := 0; builds two node bit vectors from the node table and the 6-bit value read back from `0x9006_0e80`, then writes the first
   vector's four words to `0x9006_0000 + 0x80 i`, `0xb000_8880 + 8 i`, `0x9006_0800 + 0x80 i` and the second's to `0x9006_0280 + 0x80 i`,
   `0xb000_88a0 + 8 i`, `0x9006_0a00 + 0x80 i`, i = 0 to 3. The vector contents are inferred (presence masks), the addresses and the
   loop of four are established.
2. Slot `0x2f8` (`0xffa1efd0`): node object set-up, no TIO register access. Slot `0x2a8` (`0xffa329f0`): table A (82 stores) then table B
   (9 stores), then the interrupt target (below).
3. Slot `0x308`: empty. A progress call (`0xffa13190`, arguments 21 and 1): no TIO register.
4. `0xffa0afd0`: read `0x901d_0080` (slot `0x168`), clear then set bit 58, write it back (slot `0x170`). This is extra against the SHub 2 build.
5. Slot `0x168` read of `0x901d_0080`, clear then set bits 57 and 40 (masks `0xfdffffffffffffff`, `0xfffffeffffffffff`; or `0x200000000000000`,
   `0x10000000000`), slot `0x170` write. So the word ends with bits 58, 57 and 40 set (read-modify-write each time).
6. Slot `0x18`: empty. Slot `0x288` (`0xffa94570`): finds the PROM-side object, no TIO register. Slot `0x318` (`0xffaad610`): creates the
   klconfig-style board record (type `0x12` per the SHub 2 page). Slot `0x2e0`: sets flag 2 when slot `0x2d8` returns less than 1.

**Tables A and B** (data at `0xffbdd0c8`, 82 pairs, and `0xffbdd5f0`, 9 pairs; each pair is offset with bit 38 set, then an 8-byte value): the offset
sets and values are identical to the SHub 2 build's first and second tables (checked against the lists on the SHub 2 page: same 29 all-ones
offsets, same 52 zero offsets, same 9 zero offsets; `0xd004_0208` appears twice). Store order, which the SHub 2 page lists grouped by value:
`0x9001_0008`, `0x9001_0088`, `0x9007_1000`, `0xb000_0008`, `0xb000_0018`, `0xb000_0020`, `0xb000_2008`, `0xb000_2020`, `0xb000_2040`, `0xb000_2048`, `0xb000_4008`,
`0xb000_4020`, `0xb000_4060`, `0xb000_4068`, `0xb000_4040`, `0xb000_4048`, `0xb000_6008`, `0xb000_6020`, `0xb000_6060`, `0xb000_6068`, `0xb000_6040`, `0xb000_6048`, `0xb000_8008`,
`0xb000_8020`, `0xb000_8060`, `0xb000_8040`, `0xb000_8050`, `0xb000_8048`, `0xb000_8058`, `0xb000_a008`, `0xb000_a020`, `0xb000_a060`, `0xb000_a068`, `0xb000_b008`, `0xb000_b018`,
`0xb000_b020`, `0xb000_e008`, `0xb000_e018`, `0xb000_e020`, `0x9007_1380`, `0xd004_0008`, `0xd004_0028`, `0xd004_0060`, `0xd004_0208`, `0xd004_0218`, `0xd004_0208`, `0xd004_0228`,
`0xd004_0238`, `0xd004_0260`, `0xd004_0270`, `0xd004_0130`, `0xd004_0140`, `0xd004_0150`, `0xd004_0508`, `0xd004_0518`, `0xd004_0528`, `0xd004_0538`, `0xd004_0560`, `0xd004_0570`,
`0xd004_0580`, `0xd004_0590`, `0xd004_0160`, `0xd000_0048`, `0xd004_0608`, `0xd004_0618`, `0xd004_0628`, `0xd004_0638`, `0xd004_0660`, `0xd004_0670`, `0xd004_0680`, `0xd004_0690`,
`0xd004_0170`, `0xd000_2048`, `0x9007_1900`, `0x9005_0588`, `0x9005_0508`, `0x9005_0600`, `0x9005_0280`, `0x9005_0300`, `0x9005_0380`, `0x9005_0400`, `0x9007_1100`; table B
follows: `0xd004_0540`, `0xd004_0550`, `0xd004_0640`, `0xd004_0650`, `0xd004_0240`, `0xd004_0250`, `0xd004_0040`, `0xb000_0028`, `0x9005_0480` (all zero). The writer is
`0xffae3f50` (offset, value pairs until a zero offset). Three more offset lists (`0xffbdeed8`, `0xffbdf2a8`, `0xffbdf628`, 20, 19 and 17 entries) sit with
the error handlers; the last carries the values `0x17f83ff` (to `0x9005_0588` and `0x9005_0508`), 8 (to `0x9001_0008`, `0x9001_0088`) and 0. Their
consumers were not traced.

**ITTE** (`0xb000_8800 + 8 i`, i = 0 to 6, and `0xb000_8838`): **the SHub 1 PROM does write them**, unlike the SHub 2 reading, which found only a
constructor store of zero. The PIO big-window map `0xffb74640` (descriptor `0xffc4ac20`, in the bus operations table at `0xffc2b978`) picks a free
window record of the node's seven 1 GiB records, then stores to `0xb000_8800 + 8 idx` the value `0x1_0000 | (widget << 12) | ((xtalk_addr >> 30) & 0xff)`
(`mov r14=65536`, `dep.z 12,2`, `extr.u 30,8`) and reads it back (`0xffb74acc`). Index 7 is `0xb000_8838` and is used for a window at or above
`0x2_0000_0000` (the value is `0x1_0000 | widget << 12`, constructed at `0xffb74d70`). `0xffb74ec0` (descriptor `0xffc4ac30`) clears bit 0 of
the entry on unmap (`and -2`, `0xffb750c6`) and writes `0xb000_8838` likewise. `0xffb75340` writes entry 7 in a third form. `0xffb49230`
reads entries (hub-device info). The windows are the PROM's own PIO maps, for example the three 1 GiB memory windows `tioca_bus_fixup` takes
(section 6). The hardware use of an ITTE entry is as inferred on the SHub 2 page. Grade: established (access), inferred (meaning).

**Error and interrupt rows** (8-byte, all as on the SHub 2 page unless noted):

- Slot `0x2a8` target (`0xffa32b40`): `0x9000_0480` := `vector << 52 | pid << 4` (vector `0x36`), `0x9000_0300` := target NASID, `0x9000_0500` := `0xd`.
- Slot `0x228` (`0xffa90430`), when bit 5 of the node object's flags word (`+0x50`) is clear (otherwise it calls `0xffa8e290` and returns): read-modify-write of `0x901d_0100`
  (the address comes from slot `0x270`, `0xffa90d80`; `& 0x83ffffffffffffff | 0x1c00000000000000`: bits 62:58 cleared, bits 60:58 set); when the cpuid[2] signature is not
  `0xaeeeeeee8badbeef`, `0x9003_8180` := 0 (slot `0x260` with argument 3: `0x9003_8000 + (3 << 7)`); then `0x9000_0980` := `pid << 4 | 0xe9 << 52`, `0x9000_0a00` := 0, `0x9001_0008` := `0x90_0000`,
  `0x9001_0088` := `0x90_0000`. The SHub 2 page does not list the `0x901d_0100` write or the `0x9003_8180` store for this slot.
- `tio_eint_init` (`0xffb75660`, caller through descriptor `0xffc4ac70`, not traced): allocates vector `0x36`, then `0x9001_0008` := `0x90_0000`,
  `0x9000_0480` := `pid fields << 4 | 0x36 << 52`, `0x9000_0500` := **1** (the early-init store above is `0xd`). It is a later rewrite of the same
  three registers. `tio_intr_init` (`0xffb78ee0`): for compute node c writes TIO `c | 1` (the constant carries bit 38, so NASID bit 0 is set)
  `0x9000_0300` := a target value and `0x9000_0980` := `(pid) << 4 | 0xe9 << 52`.
- `0x9001_0000`/`0x9001_0080` reads in `0xffa32cb0` and `0xffa32d30` (pending status `& 0xd`) and `0x9001_0008` write-back as on the SHub 2 page.
- **TIO interrupt slots** (`tio_intr_alloc` `0xffb79bb0` via `tio_intr_reg_manage` `0xffb79030`, decompiler reading checked against the listing): the TIO has eight
  slots, i = 0 to 7. For each the PROM reads `0x9000_1080 + 0x100 i` (target: bits 63:50 NASID, bits 19:4 the 16-bit pid) and `0x9000_1800 + 0x80 i` (non-zero means
  in use). An in-use slot with the same target is shared (a count at node object `+0xc50 + 4 i` is incremented). Otherwise the lowest free slot gets
  `0x9000_1080 + 0x100 i` := `NASID << 50 | pid << 4` and `0x9000_1800 + 0x80 i` := 1. The address it returns for a bridge to write to is the TIO register `0x9000_1000 +
  0x100 i` (in the TIO's `NASID << 40` coretalk form). Free on release: `0x9000_1800 + 0x80 i` := 0, then `0x9000_1080 + 0x100 i` := 0. This is the four-immediate set the SHub 2 10.11
  image had. Grade: established (offsets, widths, field positions), inferred (that a write to `0x9000_1000 + 0x100 i` raises the interrupt; the vector comes from the written data, as in the
  kernel's `vector << 56` destination form).

## 3. Corelet probing and the `0xe020` test (established)

Late init (`0xffad05b0`) calls slot `0x2e8` (`0xffaadef0`) unless flag 2 is set; that runs `tio_init` (`0xffaaeb10`, wrapper `0xffaaf110`):

1. Looks up the TIO lboard of the NASID; with none it prints "tio_init: No TIO lboard for NASID" and returns.
2. `0xffaae050`: read-modify-write `0xb000_6100` (bit 12 clear) and, when the slot letter is not `b`, `0xb000_8100` (bit 61 clear) as on the SHub 2 page.
3. The slot letter is `0xffac0420`'s result (from the L1 slot-type request `0x13`). For corelet n = 0 to 2 the 8-byte ID word at `0x8000_0000_0000_0000 | NASID << 38
   | n << 28` is read (`ld8.acq`, unguarded), `& 0x0fff_f000 >> 12` gives the part (`0xaaeeed..0xaaef90`). Part `0xe000` (57344) or `0xe010` (57360) is a TIOCP,
   part `0xe020` (57376) a TIOCA. The TIOCA is attached only when the slot letter is `l` (108), `^` (94) or `b` (98) (`0xffaaf0fc` calls `ca_discover`). Corelet 3: the
   word at `0x8000_0008_b000_be18 | NASID << 38` must read `0xf` (`cmp.eq 15`, `0xffaaee50`); then the CX port set-up runs, "CX PORT init failed" on failure.
   Unmatched parts are ignored, so a model needs a part word that matches none of `0xe000`, `0xe010`, `0xe020` for an absent corelet; what hardware returns is unknown.
4. `ca_discover` (`0xffaf23f0`): needs a `KLSTRUCT_TIOCA` (type `0x33`) record under the lboard; a record whose revision byte (+3) is below 2 prints "Ignoring probe of rev
   1 CA bus due to PV 908609" and the TIOCA is not probed. It then reads the PCI vendor and device IDs of function 0 straight through the corelet
   window (`0xffaf2310`: `window | 0x101_0000 | func << 8 | reg`, 2-byte reads, `0xffaf20e0` safe read), builds a VGA klconfig record (type 53) when the vendor is not
   `0xffff`, and stores the IDs in it.

## 4. TIOCA set-up by the PROM, register by register (established; roles from the kernel header)

Offsets are from the TIOCA register block, which is the corelet window (above); names from Linux `struct tioca` ([TIOCA registers](../tioca/registers.md)).
The PROM maps `0x248` bytes of the window through the corelet's map method (`0xffb60ee6`, size `0x248`), and uses ordinary uncached pointer
loads and stores, 8 bytes wide.

**`tioca_attach` (`0xffb60ea0`)**, called from the TIOCA's bus-record builder:

| Order | Offset | Access | Value | Grade |
|---|---|---|---|---|
| 1 | `0x58` `int_status_alias`, `0x68` `mult_error_alias` | W | all ones | established |
| 2 | `0x70` `first_error`, `0x90` `crm_ct_error_detail_1`, `0x98` `crm_ct_error_detail_2` | W | 0 | established |
| 3 | TIO `0x9007_1a00` | W | 0 (`0xffb60fa6`, `0xffb60fdc`) | established |
| 4 | corelet window `+0x2_0028 + 0x40 i`, i = 0 to 127 | W | `0xdeadbeefbeefdead` (`0xffb26280`, called after the closest node is chosen) | established |
| 5 | `+0x3_0000 .. +0x3_0018`, `+0x2_0000 .. +0x2_0018` (stride `0x80`/`0x40`, 64 and 128 groups) | W | pattern `0xdeadbeefbeef0000 + n`, and `0x2_0030 + 0x40 i` := 0 | established (access), inferred (a RAM init) |
| 6 | `0x08` `control1` | RMW | `& ~0x7f` (clears bits 6:0, including FW enable) | established |
| 7 | `0x10` `control2` | RMW | `& 0xffe000fffc00ffff \| 0x1ff << 40` (clear bits 25:16 `pci_max_retry`, set `crm_tnumto_period` bits 48:40 to `0x1ff`); when the revision is 1 or 2 (`(6 >> rev) & 1`, rev from `0x9006_0e80`) also clear bits 35:34 (GART prefetch enables) | established |

Step 4 and 5 are the TIOCA's internal arrays; the kernel never touches `0x2_0000` or `0x3_0000`; a model needs them writable (8 bytes) or
accepts and discards them. The order inside the function is `1, 2, 3` first (`0xffb60f90` to `0xffb60fdc`), then `4, 5`, then `6, 7` (`0xffb61426` to `0xffb614f0`).

**Error interrupt init (`tioca_error_intr_init`, `0xffb7d510`)**: allocates vector 53 (`0x35`) through the bridge provider table's allocator (slot `+0x28`),
then `0x48` `err_int_dest_addr` := `vector << 56 | xtalk address`, and `0x78` `int_mask` := `0xffff_ffff_ffdf_c01e` (a bit set masks; bits 0, 5 to 13 and 21
stay unmasked). The interrupt allocator `tioca_intr_alloc` (`0xffb7cf30`) stores the same form to `0x38` `inta_dest_addr` or `0x40` `intb_dest_addr` for lines
A and B and edits `0x78`.

**PCI function probing (`tioca_pci_init`, `0xffb7a680`)**, one pass per function (one for revision 1, up to eight when function 0 is multifunction):
config address `window | 0x101_0000 | func << 8 | reg` (bus 0; `0xffb7b520`); a read through `tioca_pio_safe` (`0xffb7e9b0`):

- `0x78` `int_mask` bit 0 set for the duration (restored after), `0xb0` `pcierr_type` := 0, `0x58` `int_status_alias` := 1.
- Revision 1 or 2: TIO `0xb000_8100` bits 17:12 := 1 around accesses whose address low 28 bits are in `0x300_0000..0x301_0000` (the TIOCA I/O window, not
  config space; the SHub 2 page's wording "configuration access" read the window as config), restored after.
- After the access `0x50` `int_status` bit 0 is tested. If set: `0xb0` `& 0x3ff_0000_0000_00` (bits 49:40) must equal `0x8000_0000_0000` (master abort, bit 47) or the PROM
  prints "unexpected ca_pcierr_type" and goes on; then `0xb0` := 0, `0x58` := 1, `0xb8` := 0 and the read value is forced to all ones. An absent function therefore
  tolerates either a master abort with `int_status[0]` set, or a plain `0xffff` read with no error.
- A vendor ID of `0xffff` is skipped; 0 prints "bogus vendor id" and a debug dump.

Then BAR sizing and placement (writes `0xffffffff`, reads the size, writes the assigned address; pools memory `0xc0000` size `0x40000`, memory `0x100000` size
`0xfff00000`, I/O `0x1000` size `0xefff`), the expansion ROM likewise, command register (offset 4) := 7 and status (offset 6) := 0 when every BAR fit.
An AGP capability (id 2, config offset from the capability list) goes to `tioca_agp_func_init` (`0xffb7b250`): if the card's AGP status has bits 3 and 1 set (AGP 3.0 and
8x; `& 10 == 10`), `0x08` `control1` := `(cal << 7) | (control1 & ~0x3c0)` where cal is status bits 12:10 (7 becomes 0), the AGP command register at capability +8 :=
`0x7d00_6322`, and the isochronous bit is cleared. Otherwise the bus stays in PCI mode (`0xffb7b3xx` message). The PROM clears control1 bit 6 (FW) in that RMW; the kernel
sets it back later.

**`tioca_bus_fixup` (`0xffb7d700`)**: no TIOCA register access. It maps the three memory windows (PCI `0x100000..0x3fffffff`, `0x40000000..0x7fffffff`,
`0x80000000..0xbfffffff`) and the 64 KiB I/O and 1 MiB legacy-memory windows through the PIO allocator (`0xffb3cca0`), which can reach the ITTE writes of section 2
for windows above 256 MiB of widget space. That these maps do reach `0xffb74640` was not traced (inferred). `tioca_space_to_xtalk` (`0xffb7de00`) is the 4.65
function read earlier.

## 5. The bus record behind SAL `0x0200_0056` (`SN_SAL_IOIF_GET_PCIBUS_INFO`)

(Established unless marked.) The call stores a pointer to the PROM's own TIOCA object through the out pointer and returns 0, or 1 when the lookup fails
(dispatcher `0xffb1f300`, lookup `0xffb2a140`: it compares the call's first argument with `record+0xc` and its second with `record+8`). The numbers
that lookup compares come from `pci_bus_mapping` (`0xffb2aff0`, caller `0xffb2d50c`): it builds a sorted list of every bus (`0xffb29920`, `pcibus_insert`
`0xffb29730`: PIC and TIOCP on node list `+0x88`, TIOCA on `+0x90`, TIOCE on `+0x98`) and, for each TIOCA, calls `ca_pci_bus_map_create` (`0xffb2a620`).
That function sets the persistent numbers:

- **Value** = a module term + a table term. The module term is the module's first-seen index times 16 (`0xffb6a690`; zero on a single-module system).
  The table term for slot letter `l` is `L[slab][2]` with the table at `0xffc2b7e4` (slab 1 gives 5, slab 2 gives 6); for other letters it is the row for that
  letter in the table at `0xffc2b2d8` (row stride 17 words) plus `slab * 4`.
- **Segment or bus.** When the node's flag at `+0x10` is zero the value goes to the bus word (`record+8`) and the segment (`record+0xc`) is 0; otherwise the segment
  word gets the value and the bus word is 0. Which of the two modes a Prism is in is unknown. The 2019 Prism logs list `0006:00` with the boot VGA, which fits segment mode with
  an `l` slot in slab 2 (inferred; the kernel logs do not name the slab).

The other fields of the record (the PROM's object, first `0x38` bytes are Linux's `struct tioca_common`): ASIC type 4 (`+0x00`), corelet number (`+0x04`, the xid),
legacy I/O base and legacy memory base (`+0x10`, `+0x18`, from `pciio_bus_fixup` / `tioca_bus_fixup`; the values come from the PIO allocator, not traced), TIOCA register
base (`+0x20`; `0x8000_0000_0000_0000`-form window address, section 3), widget info pointer (`+0x28`, the corelet record), TIO revision (`+0x30`, bits 31:28 of `0x9006_0e80`) and
closest NASID (`+0x34`; the nearest node with memory: `0xffb60ea0` loops over the node table, calls the distance function `0xffa0b210` and keeps the smallest positive value).
Revision and closest NASID sit where Linux's `struct tioca_common` expects `ca_rev` and `ca_closest_nasid`.

## 6. What a model must answer

### To reach the `Shell>` prompt (software contract, not a boot)

| # | Row | Needed answer | Grade |
|---|---|---|---|
| 1 | TIO identity word, `GLOBAL(N, 0x1_0000_0000)` | 8-byte read, bits 27:12 `0x4422`, bits 31:28 a revision (1 or 2 triggers the revision A workarounds; a model wanting 3 or more avoids them) | established (access), software expectation (`0x4422`), unknown (real revision) |
| 2 | `0x9006_0e80` | read/write 64 bits; PROM sets bits 45:32 and 53:48 (two RMWs); bits 31:28 = the revision in row 1 | established |
| 3 | route and tables of section 2: `0xd002_4000/4800/5000/0000/0800/1000`, `0xd000_0020`, `0xd003_0490/0500/04b0/04c0/0520` | plain 8-byte storage | established (access) |
| 4 | `0x9006_0700`, `0x901c_0000`, `0x901d_0080` (bits 58, 57, 40 set by the PROM; read back), `0x9006_0000/0280/0800/0a00 + 0x80 i`, `0xb000_8880/88a0 + 8 i` | plain storage | established |
| 5 | tables A and B (91 stores) | accepted; no read-back seen | established (access) |
| 6 | `0x9000_0300/0480/0500/0980/0a00`, `0x9001_0000/0008/0080/0088` | writes accepted; the two status reads return 0 | established (access), inferred (0) |
| 7 | `0x9006_0f00`, `0x901d_0100`, `0x9003_8180` | `0x9006_0f00` readable; `0x901d_0100` read/write (bits 62:58 cleared then 60:58 set by the PROM, bits 15:8 returned by the chip-info method); `0x9003_8180` accepts a store of 0 | established (access), unknown (values) |
| 8 | ITTE `0xb000_8800..8838` | eight read/write words, the PROM writes `0x1_0000 \| widget << 12 \| addr[37:30]` and reads back | established (access), inferred (meaning) |
| 9 | `0xb000_6100` bit 12, `0xb000_8100` bit 61 (and bits 17:12 for rev 1 and 2) | read/write storage | established |
| 10 | corelet windows `NASID << 38 \| n << 28`, n = 0 to 2 | ID word with part `0xe020`, manufacturer as the kernel table, for the Prism's TIOCA; part matching none of `0xe000 0xe010 0xe020` for the rest | established (code), unknown (hardware) |
| 11 | `0xb000_be18` | `0xf` only when an FPGA port exists | established |
| 12 | TIOCA only when the L1 slot letter is `l`, `^` or `b` and the klconfig TIOCA record's revision byte is 2 or more | otherwise "ignoring board type" and no TIOCA | established |
| 13 | TIOCA block, offsets `0x08 0x10 0x50 0x58 0x68 0x70 0x78 0x90 0x98 0xb0 0xb8`, window `+0x2_0000..+0x3_ffff` | read/write 8-byte storage (0x50 reads bit 0 for an error) | established |
| 14 | TIOCA config window `base + 0x101_0000 + func << 8 + reg` | PCI function 0 (and further functions when multifunction): vendor ID read as 2 bytes; absent function: `0xffff` (with or without `int_status[0]` and `pcierr_type` bit 47) | established |
| 15 | TIOCA `0x38 0x40 0x48 0x78` | stores accepted | established |
| 15a | TIO interrupt slots `0x9000_1080 + 0x100 i`, `0x9000_1800 + 0x80 i`, i = 0 to 7 (reads at all eight on every allocation; zero reads mean free) and trigger `0x9000_1000 + 0x100 i` | 8-byte read/write storage; a write to the trigger register is what a bridge's interrupt address targets | established (access), inferred (trigger) |
| 16 | I/O window `base + 0x300_0000` | reads and writes through `tioca_pio_safe` with the rev 1 or 2 `0xb000_8100` bracket | established |

What does not appear on any row (no store or load found in the functions read): `0xe8` `agp_dma_addr_extn`, `0xe0` `pci_dma_addr_extn`, `0x28` and `0x200` (the GART), `0x30`
(`gfx_detach`). The kernel sets the GART ones. Who sets `0xe8` is unknown.

### For Linux's TIOCA provider (`tioca_bus_fixup` and `tioca_gart_init`)

Each Linux access with the PROM state it needs:

| Linux access | PROM state it needs | Grade |
|---|---|---|
| SAL `0x0200_0056` (segment, bus) returns 0 and the record | section 5; ASIC type 4 at `+0`; segment/bus numbers present | established |
| SAL revision at least `0x0406` (`is_shub1() && sn_sal_rev() < 0x0406` in linux-sn2) | SAL 5.04 is above it | established |
| `kmemdup` of the record, `ioremap(REGION_OFFSET(base), ..)` | the record's `+0x20` base is the corelet window address, usable with the uncached attribute added | established (access), inferred (value form) |
| `nasid_to_cnodeid(closest_nasid)`; `pci_find_bus(segment, bus)` must exist | PROM's closest-node loop gave a valid compute NASID; PCI scan found the bus (SAL `0x0200_0057` and PCI config SAL; the PCI config route is not read here) | established (Linux), unknown (PCI config route) |
| `control1` `|= 1 << 42` | register readable and writable; PROM left bits 6:0 clear | established |
| `control2` clear bits 33:32, set 2; clear 35:34 | readable and writable; PROM left bits 25:16 clear and `crm_tnumto_period` at `0x1ff` | established |
| `int_status_alias` and `mult_error_alias` := `1 << 4` (bit 4, GART fetch error) | write accepted (write-one-to-clear is inferred, not read) | established (access) |
| `int_mask` clear bit 4 | `int_mask` at `0xffff_ffff_ffdf_c01e` after the PROM, so bit 4 is set (masked) and the RMW clears it | established (PROM value), software expectation (clear) |
| `gart_aperature` := `0x8020_0007` (2 GiB, 16 KiB pages) | accepts it; the PROM never wrote the register | established (access) |
| `gart_ptr_table` := `SH1_TIO_PHYS_TO_DMA(paddr) \| 1` (NASID `<< 40`) | accepts it and later fetches 8-byte GART entries from that address | established (access), inferred (fetch) |
| revision A flush (`control2` bit 36, read back) | revision from the record's `+0x30` (the `0x9006_0e80` revision) | established |
| `request_irq(SGI_TIOCA_ERROR = 0x35)`; handler calls SAL `0x0200_0051` | the PROM's `err_int_dest_addr` (`0x48`) holds vector `0x35`; delivery path unknown | established (PROM write), unknown (delivery) |
| AGP aperture reads `agp_dma_addr_extn` (`0xe8`) in the 48-bit DMA path | the PROM never writes it; Linux reads it back | unknown |

## Differences from the SHub 2 page

- TIO identity is read at the SHub-style offset `0x1_0000_0000`, not at LB offset `0x8000_0000`.
- Early init has the extra `0x901d_0080` bit-58 read-modify-write, a progress call and two empty slots.
- The PROM writes ITTE entries in the big-window map, with a read-back.
- `tio_eint_init` and `tio_intr_init` exist and write `0x9000_0500` := 1, `0x9000_0300`, `0x9000_0980`.
- TIOCA attach register stores (section 4) and the PCI probing with `tioca_pio_safe` are read here; the SHub 2 page left them open.
- The tables at `0xffbdd0c8` and `0xffbdd5f0` match the SHub 2 tables as sets, with the same values.

## Unknowns and what would settle each

- **SAL 4.65 and 4.90.** Not read. Route: read `snprom-10.15` and `10.40` `snprom.bin` with the same slot addresses (4.65 `tio_init` is `0xffaadfd0`).
- **Which segment/bus mode a Prism uses (`node+0x10`) and the slab of its TIOCA.** Route: trace the feature-set calls (SAL `0x0200_0065`, `0x0200_0066`) that set it.
- **The TIOCA register base value in `record+0x20`** (whether bit 63 is present) and the legacy I/O and memory bases. Route: decompile the corelet map method behind `(corelet+0x18)->+0x18` and the PIO allocator `0xffb3cca0`.
- **How standard SAL PCI configuration calls reach `tioca_config_get`** (`0xffbd43a0` strings). Route: the dispatcher that serves SAL function `0x01000010`; the immediate `0x1000010` found in SAL_B is a firmware-global address, not the function number.
- **Hardware behaviour for an absent corelet, an absent PCI function, and the reset values of every row.** Route: a TIO and TIOCA register specification or a hardware capture. Model runs show model behaviour only.
- **What the TIO does on a write to `0x9000_1000 + 0x100 i`, and the three extra offset lists** `0xffbdeed8`, `0xffbdf2a8`, `0xffbdf628`. Route: a TIO register specification, the error-handler consumers.
- **Who writes `agp_dma_addr_extn` (`0xe8`) and whether a model must pre-set it.** Route: search every store in the TIOCA functions not read here (`0xffb3xxxx` pio map and DMA setup), and the kernel DMA path.
- **Whether a model that satisfies these rows reaches `Shell>` and a Linux login.** Not established; no image was run.
