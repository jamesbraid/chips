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
  `psr.i` and `psr.dt` cleared (`rsm 0x24000`, so physical-mode access). Read and write wrappers `0xffa0bd20` and `0xffa0c560` take a route word first. Zero means the direct
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
  `0xffa62bfc`, after slot `0x1b8`. One read-modify-write: a single read (call at `0xffa9803c`) into a stack temporary, both field edits on that
  temporary, and a single write (call at `0xffa9812c`). Bits 45:32 take the node's NASID (`dep.z` 32 width 14, mask `0xffffc000ffffffff`); bits 53:48 take
  `2^bitlen(arg >> 9)` (`dep.z` 48 width 6, mask `0xffc0ffffffffffff`), the value of a doubling loop at `0xffa980b0` that shifts the argument right
  one bit and doubles a counter starting at 1 until the argument is 0 (so 1 for an argument below 512). Bits 47:46 and 31:0 are never changed.
- Readers of `0x9006_0e80`: the TIOCA attach (`0xffb61186` onward) takes the revision from bits 31:28; slot `0x120` reads bits 53:48 back; slot `0x138` (`0xffa98b06`), `0xffaae546` and `0xffb477a6` also read it.

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
4. `0xffa0afd0`: read `0x901d_0080` (slot `0x168`), clear then set bit 58, write it back (slot `0x170`). The SHub 2 image has the same step (`0xff4e02cc` calls `0xff419090`).
5. Slot `0x168` read of `0x901d_0080`, clear then set bits 57 and 40 (masks `0xfdffffffffffffff`, `0xfffffeffffffffff`; or `0x200000000000000`,
   `0x10000000000`), slot `0x170` write. So the word ends with bits 58, 57 and 40 set (read-modify-write each time). Early init is not the only writer of this word: slots `0x168` and `0x170` are also called from `0xffa1a6d0` (bit 56), `0xffa47870` (`0xffa47f00`, `0xffa47b66`, `0xffa48146`), `0xffa5b5d0`, `0xffa60550`, `0xffa637b0` and `0xffacc6e0` (bits 40 and 57). Which of them run for a TIO node was not traced (unknown); a model should keep the register as plain read/write storage.
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

**ITTE** (`0xb000_8800 + 8 i`, i = 0 to 6, and `0xb000_8838`): the PROM writes them, as the SHub 2 image does (its writer is at `0xff5930ac` to `0xff59314c`, entry 7 at
`0xff593496`, `0xff593736`, `0xff593876`, `0xff594066`, `0xff594326`). The PIO big-window map `0xffb74640` (descriptor `0xffc4ac20`, in the bus operations table at `0xffc2b978`) picks a free
window record of the node's seven 1 GiB records, then stores to `0xb000_8800 + 8 idx` the value `0x1_0000 | (width << 12) | ((xtalk_addr >> 30) & 0xff)`
(`mov r14=65536`, `dep.z 12,2`, `extr.u 30,8`; the field is 2 bits wide, bits 13:12, and "width" is our name for it) and reads it back (`0xffb74acc`). Entry 7 (`0xb000_8838`) covers a window that starts at or above
`0x2_0000_0000` and ends at or below `0x10_0000_0000`; its value is `0x1_0000 | width << 12` (store at `0xffb74d70`, read-back at `0xffb74dbc`). Unmap, `0xffb74ec0`
(descriptor `0xffc4ac30`), decrements the descriptor's reference count (`+56`) and, only when it reaches zero, writes the whole entry as 0 (`mov r41=r0` at `0xffb75096`, store at `0xffb750ac`); the `and -2`
at `0xffb750c6` clears bit 0 of the PROM's own descriptor field at `+60`, not a hardware bit. `0xffb75340` is the constructor: it zeroes all eight entries (a loop over 0 to 6, then `0xb000_8838` at `0xffb7562c`).
`0xffb49230` reads entries (hub-device info). The windows are the PROM's own PIO maps, for example the three 1 GiB memory windows `tioca_bus_fixup` takes
(section 4). The hardware use of an ITTE entry is as inferred on the SHub 2 page. Grade: established (access), inferred (meaning).

**Error and interrupt rows** (8-byte, all as on the SHub 2 page unless noted):

- Slot `0x2a8` target (`0xffa32b40`): `0x9000_0480` := `vector << 52 | pid << 4` (vector `0x36`), `0x9000_0300` := target NASID, `0x9000_0500` := `0xd`.
- Slot `0x228` (`0xffa90430`), when bit 5 of the node object's flags word (`+0x50`) is clear (otherwise it calls `0xffa8e290` and returns): read-modify-write of `0x901d_0100`
  (the address comes from slot `0x270`, `0xffa90d80`; `& 0x83ffffffffffffff | 0x1c00000000000000`: bits 62:58 cleared, bits 60:58 set); when the cpuid[2] signature is not
  `0xaeeeeeee8badbeef`, `0x9003_8180` := 0 (slot `0x260` with argument 3: `0x9003_8000 + (3 << 7)`); then `0x9000_0980` := `pid << 4 | 0xe9 << 52`, `0x9000_0a00` := 0, `0x9001_0008` := `0x90_0000`,
  `0x9001_0088` := `0x90_0000`. The SHub 2 image has the same slot (`0xff4a5010`) with the same `0x901d_0100` read-modify-write and cpuid test.
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
3. The slot letter is `0xffac0420`'s result (L1 request `0x13`, [section 7.4](#74-l1-request-0x0013-for-a-tio-nasid-established-path-unknown-transport-and-address)). For corelet n = 0 to 2 the 8-byte ID word at `0x8000_0000_0000_0000 | NASID << 38
   | n << 28` is read (`ld8.acq`, unguarded), `& 0x0fff_f000 >> 12` gives the part (`0xaaeeed..0xaaef90`). Part `0xe000` (57344) or `0xe010` (57360) is a TIOCP,
   part `0xe020` (57376) a TIOCA. The TIOCA is attached only when the slot letter is `l` (108), `^` (94) or `b` (98) (`0xffaaf0fc` calls `ca_discover`). Corelet 3: the
   word at `0x8000_0008_b000_be18 | NASID << 38` must read `0xf` (`cmp.eq 15`, `0xffaaee50`; reading it as "an FPGA port exists" is inferred); then the CX port set-up runs, "CX PORT init failed" on failure.
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
| 2b | `0x88` `crm_pkterr_type_alias` := all ones; `0xa0` `crm_tnumto`, `0xa8` `gart_err`, `0xb0` `pcierr_type`, `0xb8` `pcierr_addr` := 0; `0x90` and `0x98` := 0 again (`0xffb61160` to `0xffb611d0`) | W | as listed | established |
| 3 | TIO `0x9007_1a00` | W | 0 (`0xffb60fa6`, `0xffb60fdc`) | established |
| 4 | corelet window `+0x2_0028 + 0x40 i`, i = 0 to 127 (so `0x2_0000` to `0x2_1fff`) | W | `0xdeadbeefbeefdead` (`0xffb26280`, called after the closest node is chosen) | established |
| 5 | `+0x3_0000 .. +0x3_1fff`: 64 iterations at stride `0x80`, two four-word groups each (128 groups of `0x40`); `+0x2_0000 .. +0x2_3fff`: 128 iterations, 256 groups; and `0x2_0030 + 0x40 i` := 0, i = 0 to 127 | W | words `0xdeadbeefbeef0000 + 0x100 n + w` (n the iteration, w the word index 0 to 7 across the pair) | established (access), inferred (a RAM init) |
| 6 | `0x08` `control1` | RMW | `& ~0x7f` (clears bits 6:0, including FW enable) | established |
| 7 | `0x10` `control2` | RMW | `& 0xffe000fffc00ffff \| 0x1ff << 40` (clear bits 25:16 `pci_max_retry`; clear the 13-bit `crm_tnumto_period` field, bits 52:40, then OR in `0x1ff << 40`); when the revision is 1 or 2 (`(6 >> rev) & 1`, rev from `0x9006_0e80`) also clear bits 35:34 (GART prefetch enables) | established |

Step 4 and 5 are the TIOCA's internal arrays; the kernel never touches `0x2_0000` or `0x3_0000`; a model needs them writable (8 bytes) or
accepts and discards them. The order inside the function is `1, 2, 3` first (`0xffb60f90` to `0xffb60fdc`), then `4, 5`, then `6, 7` (`0xffb61426` to `0xffb614f0`).

**Error interrupt init (`tioca_error_intr_init`, `0xffb7d510`)**: allocates vector 53 (`0x35`) through the bridge provider table's allocator (slot `+0x28`),
then `0x48` `err_int_dest_addr` := `vector << 56 | xtalk address`, and `0x78` `int_mask` := `0xffff_ffff_ffdf_c01e` (a bit set masks; bits 0, 5 to 13 and 21
stay unmasked). The interrupt allocator `tioca_intr_alloc` (`0xffb7cf30`) stores the same form to `0x38` `inta_dest_addr` (line A) or `0x40` `intb_dest_addr` (line B; `0xffb7d230`) and edits `0x78`. Those two destination stores and the `0x48` one are TIOCA rows too (row 15).

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
`0x7d00_6322`, and when status bit 17 is set a 16-bit 0 is written at capability offset `+0x20` (`0xffb7b4f0` to `0xffb7b510`). Otherwise the bus stays in PCI mode (`0xffb7b3xx` message). The PROM clears control1 bit 6 (FW) in that RMW; the kernel
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
- **Segment or bus.** When the PROM global at `[[0x1000040] + 0x40] + 0x10` (not a node field) is zero the value goes to the bus word (`record+8`) and the segment (`record+0xc`) is 0; otherwise the segment
  word gets the value and the bus word is 0. The flag starts at 1 (segment mode) and drops to 0 only for a kernel that asks for it: [section 7.6](#76-segment-mode-or-bus-mode-established-mechanism-one-hop-not-traced). The 2019 Prism logs list `0006:00` with the boot VGA, which fits segment mode with
  an `l` slot in slab 2 (inferred; the kernel logs do not name the slab).

The other fields of the record (the PROM's object; Linux's `struct tioca_common` is `0x48` bytes and its first `0x38` match): ASIC type 4 (`+0x00`), corelet number (`+0x04`, the xid),
legacy I/O base and legacy memory base (`+0x10`, `+0x18`, from `pciio_bus_fixup` / `tioca_bus_fixup`; the values come from the PIO allocator, not traced), TIOCA register
base (`+0x20`; `0x8000_0000_0000_0000`-form window address, section 3), widget info pointer (`+0x28`, the corelet record), TIO revision (`+0x30`, bits 31:28 of `0x9006_0e80`) and
closest NASID (`+0x34`; the nearest node with memory: `0xffb60ea0` loops over the node table, calls the distance function `0xffa0b210` and keeps the smallest positive value).
Revision and closest NASID sit where Linux's `struct tioca_common` expects `ca_rev` and `ca_closest_nasid`.

## 6. What a model must answer

### To reach the `Shell>` prompt (software contract, not a boot)

| # | Row | Needed answer | Grade |
|---|---|---|---|
| 1 | TIO identity word, `GLOBAL(N, 0x1_0000_0000)` | 8-byte read, bits 27:12 `0x4422`, bits 31:28 a revision (the PROM brackets revisions 1 and 2; Linux's PV910244 flush workaround applies to revision 1 only; a model wanting 3 or more avoids them) | established (access), software expectation (`0x4422`), unknown (real revision) |
| 2 | `0x9006_0e80` | read/write 64 bits; PROM sets bits 45:32 and 53:48 (two RMWs); bits 31:28 = the revision in row 1 | established |
| 3 | route and tables of section 2: `0xd002_4000/4800/5000/0000/0800/1000`, `0xd000_0020`, `0xd003_0490/0500/04b0/04c0/0520` | plain 8-byte storage | established (access) |
| 4 | `0x9006_0700`, `0x901c_0000`, `0x901d_0080` (bits 58, 57, 40 set by the PROM; read back), `0x9006_0000/0280/0800/0a00 + 0x80 i`, `0xb000_8880/88a0 + 8 i` | plain storage | established |
| 5 | tables A and B (91 stores) | accepted; no read-back seen | established (access) |
| 6 | `0x9000_0300/0480/0500/0980/0a00`, `0x9001_0000/0008/0080/0088` | writes accepted; the two status reads return 0 | established (access), inferred (0) |
| 7 | `0x9006_0f00`, `0x901d_0100`, `0x9003_8180` | `0x9006_0f00` readable; `0x901d_0100` read/write (bits 62:58 cleared then 60:58 set by the PROM, bits 15:8 returned by the chip-info method); `0x9003_8180` accepts a store of 0 | established (access), unknown (values) |
| 8 | ITTE `0xb000_8800..8838` | eight read/write words, the PROM writes `0x1_0000 \| widget << 12 \| addr[37:30]` and reads back | established (access), inferred (meaning) |
| 9 | `0xb000_6100` bit 12, `0xb000_8100` bit 61 (and bits 17:12 for rev 1 and 2) | read/write storage | established |
| 10 | corelet windows `NASID << 38 \| n << 28`, n = 0 to 2 | ID word with part `0xe020`, manufacturer as the kernel table, for the Prism's TIOCA; part matching none of `0xe000 0xe010 0xe020` for the rest | established (code), unknown (hardware) |
| 11 | `0xb000_be18` | reads `0xf` to take the CX port path (established); that `0xf` means an FPGA port exists is inferred | established (access), inferred (meaning) |
| 12 | TIOCA only when the L1 slot letter is `l`, `^` or `b` and the klconfig TIOCA record's revision byte is 2 or more | otherwise "ignoring board type" and no TIOCA | established |
| 13 | TIOCA block, offsets `0x08 0x10 0x50 0x58 0x68 0x70 0x78 0x88 0x90 0x98 0xa0 0xa8 0xb0 0xb8`, window `+0x2_0000..+0x3_ffff` | read/write 8-byte storage (0x50 reads bit 0 for an error) | established |
| 14 | TIOCA config window `base + 0x101_0000 + func << 8 + reg` | PCI function 0 (and further functions when multifunction): vendor ID read as 2 bytes; absent function: `0xffff` (with or without `int_status[0]` and `pcierr_type` bit 47) | established |
| 15 | TIOCA `0x38 0x40 0x48 0x78` (`0x38`/`0x40` from `tioca_intr_alloc`, `0x48`/`0x78` from the error-interrupt init) | stores accepted | established |
| 15a | TIO interrupt slots `0x9000_1080 + 0x100 i`, `0x9000_1800 + 0x80 i`, i = 0 to 7 (reads at all eight on every allocation; zero reads mean free) and trigger `0x9000_1000 + 0x100 i` | 8-byte read/write storage; a write to the trigger register is what a bridge's interrupt address targets | established (access), inferred (trigger) |
| 16 | I/O window `base + 0x300_0000` | reads and writes through `tioca_pio_safe` with the rev 1 or 2 `0xb000_8100` bracket | established |

What does not appear on any row (no store or load found in the functions read): `0xe8` `agp_dma_addr_extn`, `0xe0` `pci_dma_addr_extn`, `0x28` and `0x200` (the GART), `0x30`
(`gfx_detach`). The kernel sets the GART ones. Nothing in the PROM or in Linux sets `0xe8` ([section 7.5](#75-agp_dma_addr_extn-0xe8-no-writer-in-the-prom-established-negative-unknown-who-sets-it)); who does is unknown.

### For Linux's TIOCA provider (`tioca_bus_fixup` and `tioca_gart_init`)

Each Linux access with the PROM state it needs:

| Linux access | PROM state it needs | Grade |
|---|---|---|
| SAL `0x0200_0056` (segment, bus) returns 0 and the record | section 5; ASIC type 4 at `+0`; segment/bus numbers present | established |
| SAL revision at least `0x0406` (`is_shub1() && sn_sal_rev() < 0x0406` in linux-sn2) | SAL 5.04 is above it | established |
| `kmemdup` of the record, `ioremap(REGION_OFFSET(base), ..)` | the record's `+0x20` base is the corelet window address, usable with the uncached attribute added | established (access), inferred (value form) |
| `nasid_to_cnodeid(closest_nasid)`; `pci_find_bus(segment, bus)` must exist | PROM's closest-node loop gave a valid compute NASID; PCI scan found the bus (SAL `0x0200_0057` and PCI config SAL; the PCI config route is not read here) | established (Linux), unknown (PCI config route) |
| `control1` `|= 1 << 42` | register readable and writable; PROM left bits 6:0 clear | established |
| `control2` clear bits 33:32 then write 2 into that two-bit field; clear 35:34 | readable and writable; PROM left bits 25:16 clear and the `crm_tnumto_period` field (52:40) at `0x1ff` | established |
| `int_status_alias` and `mult_error_alias` := `1 << 4` (bit 4, GART fetch error) | write accepted (write-one-to-clear is inferred, not read) | established (access) |
| `int_mask` clear bit 4 | `int_mask` at `0xffff_ffff_ffdf_c01e` after the PROM, so bit 4 is set (masked) and the RMW clears it | established (PROM value), software expectation (clear) |
| `gart_aperature` := `0x8020_0007` (2 GiB, 16 KiB pages) | accepts it; the PROM never wrote the register | established (access) |
| `gart_ptr_table` := `SH1_TIO_PHYS_TO_DMA(paddr) \| 1` (NASID `<< 40`) | accepts it and later fetches 8-byte GART entries from that address | established (access), inferred (fetch) |
| revision A flush (`control2` bit 36, read back) | revision from the record's `+0x30` (the `0x9006_0e80` revision) | established |
| `request_irq(SGI_TIOCA_ERROR = 0x35)`; handler calls SAL `0x0200_0051` | the PROM's `err_int_dest_addr` (`0x48`) holds vector `0x35`; delivery path unknown | established (PROM write), unknown (delivery) |
| AGP aperture reads `agp_dma_addr_extn` (`0xe8`) in the 48-bit DMA path | the PROM never writes it; Linux reads it back | unknown |

## 7. How a Prism TIO is found, numbered, given a board record and an L1 answer (objdump read, 2026-11-22)

Same image and method as above (flat `shub1snprom.bin`, SAL 5.04; every address, immediate and branch below was read in an `ia64-linux-gnu-objdump` listing of the flat image at
`0xffa00000`; the data tables were read from the bytes). Nothing was run. Class slot numbers are offsets into the class tables listed under "TIO class". A "record" is the PROM's node record (the 16-bit NASID at `+0`,
the part at `+2`, the revision byte at `+4`, the route word at `+24`, the class pointer at `+32`); an "object" is the 72-byte entry the discovery code keeps for one record.

### 7.1 Attachment: over NUMAlink (established for the PROM), not through the SHub's XIO port

- **Discovery is a NUMAlink walk.** `intcon_run_discover` (`0xffa47870`, the "Discovering node interconnect" step, progress code 28 at `0xffa1b0c6`, call at `0xffa1b0dc`) calls the walker `0xffa47290` (call at `0xffa47aac`), which records the local chipset and then loops over every object it has
  found. For each it asks the object's class for its NUMAlink port count (class slot `0x188`, `0xffa47640`: SHub 2 at `0xffa5d5b0`, both router classes 8 at `0xffa642a0` and `0xffa66f70`, TIO 2 at `0xffa61240`), and for each port whose record flag
  (port byte `+3`, bit 0) is set it calls `discover_object` (`0xffa45780`, call at `0xffa477cc`). `discover_object` follows the port with a route vector (the path word; the message "Max vector length 16 exceeded on path" is at `0xffa458d0`).
  The end message is "Found %d objects (%d chipsets, %d routers, %d iochipsets) in %ld usec" (`0xffa47780`).
- **What tells a TIO from a SHub or a router.** Two reads, both through the vector path. (1) The identity word at offset `0x1_0000_0000` (`0xffa46b6c` calls `0xffa0bd20` with the route word; the same word the local node builder reads, section 1): bits 27:12 are the part and
  `0xffa0f7e0` runs each class's accept method over it: SHub `0x4363` (`0xffa959a0`), NL3 router `0x3017` (`0xffa948d0`, name "NL3router"), NL4 router `0x239` (`0xffa949e0`, "NL4router"), TIO `0x4422` (`0xffa97ce0`). (2) The class then answers what kind of
  object it is through slot `0x190`: SHub 1 (chipset), routers 2, TIO 3 (I/O chipset; `0xffa5d5c0`, `0xffa642b0`, `0xffa66f80`, `0xffa61250`). `intcon_add_object` (`0xffa450e0`) stores that kind in the object at `+90` (call at `0xffa453dc`) and counts it into the three
  totals the end message prints (object `+24`, `+28`, `+32`, indexed by kind at `0xffa4541c`). A TIO is therefore an "iochipset" found at the far end of a NUMAlink port, with two NUMAlink ports of its own whose status the class reads at `0xd000_0048 + 0x2000 n`
  (slot `0x1a8`, `0xffa61270`; slot `0x1b0`, `0xffa61330`, calls it for n = 0 and 1 through `0xffa60710`).
- **Negative result for the XIO port.** The node-record builder `0xffa0f8c0` has fourteen call sites. Only one passes a non-zero route word, `0xffa46d4c` in the discovery path above; the ones I opened (`0xffa7fcec`, `0xffaa399c`, `0xffaa4c9c`, `0xffa0b24c`,
  `0xffaa960c`, `0xffad2cec`) all pass route 0 and a NASID the caller already holds. No path that finds a TIO from a SHub XIO widget scan was found, and the TIO class has no XIO-type method (its corelets are read in the TIO's own `nasid << 38` window, section 3).
  Not opened: `0xffa0b5cc`, `0xffa1982c`, `0xffad4d5c`, `0xffaee15c`, `0xffb0998c`, `0xffb0c58c`, `0xffb19cdc`. Grade: established (the NUMAlink discovery path, the two reads, the class kind); inferred (that nothing attaches a TIO over XIO: seven call sites are unopened, and I did not walk the SHub class's own I/O-widget code);
  unknown (what the real SHub XIO port carries in a Prism, which is hardware).

### 7.2 Node number: where the NASID comes from and the order of the install (established)

- **Source.** The NASID written to the TIO is the 16-bit word at record `+0` (object `+48`). It is not read from the TIO. A freshly discovered record starts with a placeholder: `0xffa46d4c` builds it with the discovering object's number as the third argument (inferred; the load is at `0xffa46a60`). `intcon_assign_numbers` (`0xffa4d3a0`; boot progress code 29 "Assigning and distributing nasids, routes, etc.", call at `0xffa1b26c`; failure code `0x8b` "Nasid assignment failed")
  then rewrites it for every object whose flag byte `+91` bit 0 is set: `(old - base) / granule` through the integer divide `0xffa149c0` (call at `0xffa4d97c`), stored back at `0xffa4d990`; objects that are not routers also get the number copied to `+94` and a bit set in a presence bitmap (`0xffa4d9c0` to `0xffa4da16`). Base and granule start at 0 and 2 (`0xffa4d3c0`, `0xffa4d3d6`) and are changed later in the function; I did not decode that, so the actual numbers a Prism gets are unknown.
  Two helpers finish the pass: `0xffa4efa0` returns the largest NASID among non-router objects (with a width term from object `+109`) and `0xffa4f1a0` a second limit; assign stores them at `0xffa4e430` (second output, `sp+18`) and `0xffa4e446` (first output, `sp+16`) and hands them to the distribution step as its two arguments.
  `tio_intr_init` (section 2) forms the TIO's NASID as the compute NASID with bit 0 set, and the L1 code below treats an odd NASID as a TIO (`0xffac0440`), so odd NASIDs for TIOs is what the code expects (software expectation); that the numbering pass produces them is not shown here.
- **Order.** The distribution function `0xffa5b5d0` ("Distributing routing tables", call at `0xffa1b2ac`) calls the class's route-install method (slot `0x1d8`, loaded at `0xffa5bf30`) for each object. For the TIO that is `0xffa620a0` (it prints "Set up %s: index %d, %I, nasid %d" at `0xffa622fc`), which (1) copies the record, (2) writes the per-port route
  rows and the `0xd002_0000` rows, then `0xd002_1000` := 0 (`0xffa62bac`), (3) calls slot `0x1b8` (`0xffa614e0`, `0xffa62bcc`), (4) calls slot `0x108` (`0xffa97fe0`, `0xffa62bfc`) with the record, the record's NASID and the largest non-router NASID (`0xffa4efa0`'s result reaches `0xffa97fe0` as its fourth argument; its third is the other limit and is unused).
  The `0xd002_1000` store and steps (3) and (4) (the block at `0xffa62b70`) run only when bit 0 of record byte `+43` is clear (`0xffa62b3c` branches to it); that bit is set by TIO slot `0x1c8` (`0xffa61cc0`) and its SHub twin (`0xffa5e450`) after a port bring-up. Its meaning is inferred: the node already carries its final number.
- **How the TIO is reached before it has a number.** Every access in `0xffa97fe0` goes through the route-word accessors `0xffa0bd20` (read, call at `0xffa9803c`) and `0xffa0c560` (write, `0xffa9812c`) with the record's route word (`+24`) as the first argument, not zero. A non-zero route word takes the vector path
  (`0xffa0be50`, through `0xffa0cec0`; it also touches local SHub registers at `0x9_1007_4100` and `0x9_1006_6080` plus `NASID << 38`, `0xffa0bf26`, `0xffa0bf96`, not decoded), so the NASID argument is not what addresses the TIO; the direct form `0x8000_0008_0000_0000 | NASID << 38 | offset` is used when the route word is 0. So the node number is written into `0x9006_0e80` over the discovery vector, and
  later accesses (for example the revision read in slot `0x138`, `0xffa98b06`, form `0x8000_0008_9006_0e80 | NASID << 38`, route 0) use the NASID. A model must route vector reads and writes to the TIO and apply `0x9006_0e80` before NASID-addressed accesses reach it.
  Bits 53:48 hold `2^bitlen(limit >> 9)` as in section 1, and the limit is the largest non-router NASID from `0xffa4efa0` (established), so the field counts 512-NASID regions rounded up to a power of two (inferred).
- Boot order (progress codes through `0xffa0ddb0`; the sequencer is `0xffa1ade0`): 28 discover, 29 assign and distribute (`0xffa1b240`), 30 begin node-id install (`0xffa1b1d6`), 31 and 32 inside the install function (`0xffad7aa6`; it sets the local `cr.lid` first, `0xffaec240`), then `main_three` (`0xffad7280`) with 33 "Installation of new node id complete", 34 late
  node-id routines, 35 "Calling remote mem. available notification routines" (the TIO early-init loop `0xffa1a9e0` at `0xffad74fc` and the late-init loop `0xffa1ac80` at `0xffad751c`, which reaches `tio_init`) and 36 "Discovering I/O" (`0xffad7526`).

### 7.3 The TIO board record and "No TIO lboard" (established)

- **The message.** Printed by `tio_init` (`0xffaaf110`, message at `0xffaaf160`, string `0xffbb68d0`) when `0xffaa94c0(nasid, 18)` returns 0: it looks for a klconfig board of type 18 (`0x12`) for that NASID (the klconfig lookup `0xffaa8a40` first maps the NASID to the
  NASID whose memory holds its klconfig, `0xffaa3960`, then tail-calls `0xffaa8e30`, which I did not open). With no board it returns; `corelet_discover` (`0xffaaeb10`), which `0xffaaf110` otherwise tail-calls at `0xffaaf18c`, does not run.
- **Where the board is created.** In TIO class slot `0x318` (`0xffaad610`): it calls `0xffa9fe80(record, 18, flag)`, which calls the board builder `0xffaa1ea0`. That builds the board and names it "TIO" (string `0xffbb5dd8`, `0xffaa1ff6`) for every type except 17, which is the SHub's and is named "IP41" (`0xffaa2040`). It allocates the board with
  `0xffaed240` (which needs a hardware-config block for the NASID, `0xffaa4c60`; failures print "hwcfg_io_board_init: Cannot allocate lboard." at `0xffaed460`, "WARNING: Can't add %I lboard to nasid %d" at `0xffaa230c`, or, from slot `0x318` itself, "ERROR: failed to create lboard for headless node %d!" at `0xffaad666`).
  Slot `0x318` is called from the TIO early-init method (slot `0x28`, `0xffad01e0`; call at `0xffad051c` via offset `0x318` at `0xffad04fc`), after slot `0x288` (`0xffa94570`, call `0xffad04dc`) has created the node's system-controller handle.
- **What must exist for the message not to print.** (a) The TIO's object must be visited by the early-init loop `0xffa1a9e0` (call of slot `0x28` at `0xffa1ac4c`): it walks objects that have bit 3 and bit 16 of the `+104` word set and bit 0 of byte `+91` clear (the property switch at `0xffa129f0`, cases 3, 11 and 19; the branch polarity is read from `0xffa1ab9c` and `0xffa1abc6`),
  and skips the object when the arbitration bit 56 of TIO register `0x901d_0080` is already set (`0xffa1a6d0`). That `+91` bit 0 must be clear here yet is set for the numbering pass means something clears it in between; I did not find the clear (unknown). (b) Slot `0x288` must have made the handle (`0xffa9462c` calls `0xffa8f9c0`, "couldn't create sysctl_t for headless nasid %d" at `0xffa94640`). (c) The klconfig host mapping `0xffaa3960` must resolve the NASID to a node with a hardware-config block. It is the identity when `0xffa99b80` returns 0 (that function reads the node's advertisement register `0x901d_0080` and returns 1 when bit 58 is set, or when bit 39 is set and bit 57 clear,
  and 0 otherwise or for the local node; TIO early init sets bit 58 at `0xffa0afd0`, so a TIO takes the other branch; the reading of those bits as "headless" is inferred). For such a node it finds the object by the halfword table `[[0x1000038] + 16] + 2 + 2 * nasid` (`0xffaa3aa6`, filled by `intcon_assign_numbers` at `0xffa4e610`) and searches the topology for a hosting node
  (`0xffaa95a0` or `0xffaa98c0`, calls at `0xffaa3b7c` and `0xffaa3bfc`), printing "WARNING: Unable to find host for memless node %d!" (`0xffaa3ba0`) when it finds none. So a TIO board needs a compute node in reach that can hold its klconfig. This is the precondition most likely to keep a model's TIO from getting a board when everything above is in place.

### 7.4 L1 request `0x0013` for a TIO NASID (established path, unknown transport and address)

- **Entry.** The slot-letter function `0xffac0420(nasid)` tests bit 0 of the NASID (`0xffac0440`). Odd (TIO) goes to `0xffa80270` (call `0xffac045c`), even to `0xffa80490`. Both call the L1-handle finder `0xffa7fcb0(nasid)` and then the cached-or-asked reader (`0xffa7d760` for the TIO; `0xffa7e6d0` for the even form). A result with
  low byte 255 is "unknown" and the function returns `0xffff`. A letter reply is folded to lower case (`0xffa7cd3c` to `0xffa7cd60`: values 65 to 90 get 32 added).
- **Handle.** `0xffa7fcb0(nasid)` builds the node record (route 0) and calls `0xffa99b80`. When that returns 0 (the local node, or a node whose advertisement bits do not say headless) it reads that node's own PROM global pointer, `0x1000038` locally and `0x8000_0030_0100_0038 | NASID << 38` for another node
  (`0xffa7ffe0` to `0xffa800a6`: a memory word, not an L1 address), and when it is non-zero returns the system-controller object stored at `+384` of that global (`0xffa80196` to `0xffa801fc`). Otherwise, which is the TIO's case (bit 58 set, above), it takes the per-NASID table `[[0x1000040] + 0x108]` (8 bytes per NASID, `0xffa7fd66`).
  The TIO's entry is made by TIO class slot `0x288` (`0xffa94570`, in early init): it calls `0xffa8f9c0`, which allocates a 3768-byte system-controller object (`0xffa8fa6c`), initialises it from the record with `0xffa8b5d0` (copies the record's 40 bytes into the object's first words and sets bits 1 and 3 of its flag word at `+80`; bit 5 follows a caller argument
  that I did not trace) and stores it in the table at `0xffa8fb56`. With no table entry `0xffa7fcb0` falls back to the executing node's object (`0xffa7fe16`: `cr.lid` bits 26:23, entry at `0x100_0000 + (id + 2) * 8`, `+24`), accepts it when its magic word at `+3760` is `0x4c015343` and its NASID matches, and otherwise starts one with `0xffa8f960`.
- **Request.** `0xffa7d760` first asks the handle's cache (`0xffa81510`), then, except for the simulator signature `cpuid[2] = 0xaeeeeeee8badbeef` (which uses `0xffa7c780`), builds the request in `0xffa7cbe0`: clear a 128-byte buffer (`0xffa16750`), open the handle (`0xffa819c0`), pack the request with code `0x13` and a six-byte
  body (`mov r43=19` at `0xffa7cc50`, `mov r42=6`, call `0xffa81f40`), then flush (`0xffa82c10`), read the reply (`0xffa82270`) and close (`0xffa81e40`). The open call takes a channel selector `0xffff000` or `0x4ffff000` (`0xffa819d6`), and the handle holds up to twenty channels at `+0x210 + n * 0x98` (`0xffa81a6c`).
- **Not traced.** The channel transport (`0xffa8ca50`, `0xffa7d1f0`, `0xffa82a10`), so I cannot say which L1 a request for a TIO NASID reaches or what bytes go out; the handle carries the TIO's own record (so its route word), and the strings in the advertisement code (`cache_advert: sysctl_vec_slab_get failed for TIO`, `0xffbb22f8`; `sysctl_vec_slot_get`, `0xffbb2330`) show that
  slab, slot and module of a TIO are also read through vector-addressed system-controller calls, which points at the TIO's own route rather than a compute node's UART (inferred, not shown). Unknown without a capture of the L1 link or a Prism.

### 7.5 `agp_dma_addr_extn` (`0xe8`): no writer in the PROM (established negative; unknown who sets it)

- Searched the whole flat image for every `adds rN=232,rM` (47 sites: 19 below `0xffb00000`, 22 in the I/O code up to `0xffb8f5f0`, 6 in the PAL tail) and for every `mov` of 232 or 224. In TIOCA code the only ones are reads: the POD register dump (`0xffb24b1c`, prints "ca_agp_dma_addr_extn [0E8]"), the DMA-address decoder (`0xffb24300`)
  and a status print (`0xffb27a9c`). `tioca_attach` (`0xffb60ea0`), `tioca_pci_init` (`0xffb7a680`), `tioca_agp_func_init` (`0xffb7b250`), `tioca_error_intr_init` (`0xffb7d510`), `tioca_intr_alloc` (`0xffb7cf30`), `tioca_bus_fixup` (`0xffb7d700`) and the rest of `0xffb7a600` to `0xffb7f600` contain no 224 or 232 offset.
  The other I/O-code sites are PIC and TIOCP code (`0xffb48696` to `0xffb491d0`, `0xffb6eaf6` to `0xffb6f320`, identified by their strings), a PCI-bridge dump and structure fields (`0xffb2ddd6`, `0xffb35c46`); the 19 below `0xffb00000` and the 6 in the PAL tail are node, L1 and PAL code that I did not open one by one. So "no writer" is a negative over the TIOCA, POD and I/O code,
  not a proof over every instruction in the image. The POD `tioca rd` and `tioca wr` commands (usage strings at `0xffbc3510`, code near `0xffb26ebc`) take a buffer number and count, which suggests the PCI read buffers rather than this register (inferred; not decoded).
- Public SGI Linux (linux-sn2 branch, `arch/ia64/sn/pci/tioca_provider.c:351` and `include/asm/sn/tioca.h:51, 334-337`) reads the register once, to check that the upper node bits of an AGP direct address equal `agp_dma_extn >> 20` (field `CA_AGP_DMA_NODE_ID`, bits 35:20), and nothing under `arch/` or `include/` writes it. So neither the PROM code read nor Linux's `arch/` writes `0xe8`.
  Unknown without hardware or a TIO specification: whether the TIOCA resets it to a value or derives it itself, or whether another component writes it (an out-of-tree driver, the EFI or IO-PROM stage, which were not read). A model should make it read/write storage and, when the AGP direct path matters, hold the node id of the DMA target in bits 35:20 (software expectation from the Linux check; not a hardware fact).

### 7.6 Segment mode or bus mode (established mechanism, one hop not traced)

- **The flag.** `[[0x1000040] + 0x40] + 0x10` is a 64-bit word in the PROM's I/O globals block (168 bytes, allocated by `io_init_memory`, `0xffb2cbf0`). Its only writers are `io_reinit_memory` (`0xffb2d110` entry, body `0xffb2d120`): it stores 1 at `0xffb2d316` when its argument is non-zero and 0 at `0xffb2d440` when it is zero, and
  `0xffb2cbf0` itself, which stores **1** during allocation (`0xffb2d010`; no predicate). `pci_bus_mapping` (`0xffb2aff0`, after the allocation in `0xffb2d450`; the call at `0xffb2d50c`) therefore starts in **segment mode**: `ca_pci_bus_map_create` (`0xffb2a620`, branch at `0xffb2a900`) puts the value in the segment word
  (`record + 0xc`) and 0 in the bus word, and records the highest value in globals `+0x28` (`0xffb2a92c`). The first call of the allocation is not shown, because the boot-time I/O initialisation reaches `0xffb2d450` through code I did not trace (the other four callers pass a non-zero third argument and skip the allocation); that it runs before the numbering is inferred
  from the function needing the block.
- **SAL `0x02000066` (the OS feature call, `0xffb5fc90`, table entry `0xffc26458`).** Feature 3 (Linux's `OSF_PCISEGMENT_ENABLE`, `sn_feature_sets.h`) runs `0xffb20230`: if the flag is 0 it calls `io_reinit_memory(1)` and re-runs the bus mapping (`0xffb2d450`), then sets bit 3 of the word at `[[0x1000040] + 0xc8]`
  (`0xffb5fe76` to `0xffb5fed6`), and returns 0 status. Feature 2 (ACPI) sets bit 2 of the same word (`0xffb60040` to `0xffb60076`). Any other value returns -1 in `r8` (`0xffb5fd3c`). SAL `0x02000065` (`0xffb60170`, entry `0xffc26468`) is the read side and was not opened.
- **SAL `0x02000055` (`SN_SAL_IOIF_GET_HUBDEV_INFO`, `0xffb1efb0`).** On the first call (guarded by globals `+0x18`, which it sets to 1 at `0xffb1f160`) it reads the OS buffer's u32 at `+744` (`0xffb1f076`). If non-zero and the flag is 0, it calls `io_reinit_memory(1)`; if zero and the flag is 1, it calls `io_reinit_memory(0)` and
  re-runs the mapping (`0xffb1f2f6`). Then it writes the globals `+0x28` (largest segment) and `+0x30` (largest bus) back into the buffer at `+744` and `+748` (`0xffb1f280`, `0xffb1f286`). In linux-sn2, `sn_fixup_ionodes` (`io_init.c:102-103`) sets `max_segment_number = 0xffffffff` and
  `max_pcibus_number = 0xff` before the call, and `struct hubdev_info` ends with those two fields, so the offsets agree (field order only; the struct size was not computed). `sn_setup` (`setup.c:385`) calls the feature set with `OSF_PCISEGMENT_ENABLE` first.
- **Answer.** The Prism PROM boots in segment mode and stays in it for any kernel that either sends feature 3 or passes a non-zero `max_segment_number` (linux-sn2 does both). It drops to bus mode only for a kernel that passes 0 in the hubdev buffer and has not sent feature 3. For a TIOCA record that means segment word = the table value,
  bus word = 0; the 2019 `0006:00` is segment 6, bus 0, which fits this (the kernel in those logs is not identified, so which of the two requests it sent is unknown).
  Unknown: the first caller of `0xffb2d450` with a zero third argument (the PROM's own I/O discovery step), the value the SAL `0x02000065` read side returns, and whether the shipped Prism kernels of the 2019 logs send either request.

## Differences between our two pages, and what really differs in the firmware

Several items first appeared as differences only because the SHub 2 page had not listed them. The SHub 2 10.54 image has all of these as well: the ITTE map writer
(above), the bit-58 read-modify-write of `0x901d_0080` (`0xff4e02cc` calls `0xff419090`), and the slot `0x228` sequence with the L1-word read-modify-write and the cpuid test
(`0xff4a5010`). The SHub 2 page now lists them. The firmware differences found are:

- the identity-read offset: `0x1_0000_0000` here, LB `0x8000_0000` there;
- bit 38 in the table and immediate offsets here (a marker the accessor strips), against the explicit chiplet bit there.

What this page adds that the SHub 2 page lacks: the TIOCA attach and probe register stores (section 4), `tio_eint_init` and `tio_intr_init`, and the TIO interrupt slots.
The tables at `0xffbdd0c8` and `0xffbdd5f0` match the SHub 2 tables as sets, with the same values.

## Unknowns and what would settle each

- **SAL 4.65 and 4.90.** Not read. Route: read `snprom-10.15` and `10.40` `snprom.bin` with the same slot addresses (4.65 `tio_init` is `0xffaadfd0`).
- **Which segment/bus mode a Prism ends in, and the slab of its TIOCA.** Mechanism read (section 7.6): segment mode unless the kernel passes `max_segment_number` 0 and never sends feature 3. Still open: which of the two the 2019 Prism kernels sent, the first caller of `0xffb2d450` with a zero third argument, and the SAL `0x0200_0065` read side (`0xffb60170`). Route: the kernel in the 2019 logs, then read `0xffb60170` and the boot-time I/O initialiser.
- **The TIOCA register base value in `record+0x20`** (whether bit 63 is present) and the legacy I/O and memory bases. Route: decompile the corelet map method behind `(corelet+0x18)->+0x18` and the PIO allocator `0xffb3cca0`.
- **How standard SAL PCI configuration calls reach `tioca_config_get`** (`0xffbd43a0` strings). Route: the dispatcher that serves SAL function `0x01000010`; the immediate `0x1000010` found in SAL_B is a firmware-global address, not the function number.
- **Hardware behaviour for an absent corelet, an absent PCI function, and the reset values of every row.** Route: a TIO and TIOCA register specification or a hardware capture. Model runs show model behaviour only.
- **What the TIO does on a write to `0x9000_1000 + 0x100 i`, and the three extra offset lists** `0xffbdeed8`, `0xffbdf2a8`, `0xffbdf628`. Route: a TIO register specification, the error-handler consumers.
- **Who writes `agp_dma_addr_extn` (`0xe8`) and whether a model must pre-set it.** Searched the PROM and linux-sn2: no writer (section 7.5). Route: a TIO or TIOCA register specification, a hardware read of the reset value (needs approval), or the SGI graphics kernel module if it can be found.
- **How the TIO number is chosen and which L1 a TIO request reaches.** Section 7.2 and 7.4: the base and granule in `intcon_assign_numbers`, the `+91` bit 0 clear between numbering and early init, the host search for a memless node (`0xffaa95a0`, `0xffaa98c0`), and the system-controller transport (`0xffa8ca50`, `0xffa7d1f0`). Route: decode those four, or a capture of a Prism boot console with the "Set up ..., nasid %d" lines.
- **Whether a model that satisfies these rows reaches `Shell>` and a Linux login.** Not established; no image was run.
