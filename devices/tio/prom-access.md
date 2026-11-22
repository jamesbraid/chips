# TIO: what the SHub 2 firmware does to a TIO, and what a model must answer

Question. Which TIO registers does the SHub 2 PROM read or write, in what order, and which of them must exist for the
PROM to finish with a TIO present? This page records the PROM side. The kernel side is on [the TIO page](README.md),
[TIOCA](../tioca/README.md), [TIOCE](../tioce/README.md) and [TIOCP](../tiocp/README.md).

**Images and method.** Read in full: `shub2snprom.bin` of snprom 10.54 (SAL 1.54, flat at `0xff400000`, SAL_B at `0xff401000`).
Compared by constants and by the one table named below: `shub2snprom.bin` of snprom 10.40 (SAL 1.40) and `ip65prom.bin` of
snprom 10.11 (SAL 1.11). Checksums are in [the holdings list](../../references/irix-files.md#sn2-firmware-and-kernels).
Method: Ghidra with the IA-64 module (SN2 import, whole image analysed and decompiled, then the TIO class methods again from their
addresses); every constant, accessor width and mask quoted as established was then checked in an `ia64-linux-gnu-objdump` listing of
the same bytes. Where only the decompiler shows a value (a merged mask, a loop bound), the entry says so and is graded inferred.
Nothing was run and no hardware was read. Names in quotes are strings the image prints; the register names are ours.

Grades as in [AGENTS.md](../../AGENTS.md): established is the instruction-level fact read in the image, a software expectation,
never a silicon measurement. Reset values are unknown throughout: the PROM writes each register before it relies on it, or ignores it.

## How the PROM addresses a TIO (established)

- Every register access is one 8-byte uncached load or store, through two helpers (`0xff4207a0` load, `0xff420840` store; listing:
  `ld8` and `st8` between a `srlz.d` and a `mf.a`, interrupt collection masked). The one exception is the corelet identification read, a 4-byte `ld4.acq` (below); every other TIO access read is 8 bytes.
- The address of a TIO register is `bit 63 | NASID << (40 - V) | (1 << (38 - V)) | 0x8000_0000 | offset`. V is read from the SHub 2
  register at `0x2_2011_0000` on every access ([SHub 2 page](../shub/shub2.md#1-how-the-node-number-and-windows-are-formed)). The extra bit
  `1 << (38 - V)` is the chiplet field set to 1, as Linux's `TIO_IOSPACE_ADDR` sets it, so TIO local-block registers are in chiplet 1.
  A SHub (even NASID) takes `0x3_0000_0000` instead. Offsets below carry bit 31 as the PROM's constants do (`0x90060e80` is Linux's
  `TIO_NODE_ID`), so the `0x8000_0000` term is redundant for them and no offset without bit 31 was seen against a TIO.
- The widget windows are reached with the chiplet field zero: corelet n of a TIO is at `bit 63 | NASID << (40 - V) | n * 0x1000_0000`
  (`0xff4cc2d0`, Linux's small windows of 256 MiB).
- A second path exists. The read and write wrappers (`0xff419e80`, `0xff41ad30`) take a route word from the node record (offset `0x18`).
  When it is zero the access is the direct one above. When it is non-zero the wrapper takes a lock, writes a request into
  `0x1007_4100`, `0x1006_7000`, `0x1006_7080`, `0x1006_7100` and `0x1007_4000` (same address form, on the node named in the call), polls
  `0x1006_7080` and `0x1007_4100` up to 1024 times, retries up to 8 times and decodes a reply status word into -1 to -7. This is the
  vector (maintenance) path used before routes exist. Whether the PROM ever runs it against a TIO, and whether a TIO has those
  registers, is unknown: see the unknowns.

## TIO class in the PROM (established)

Chip drivers are method tables selected by the part number in the node's identification word. The array is at `0xff5fd888`; the
third table, at `0xff5fd508`, is the TIO. Its name method returns the string "TIO", and its accept method (`0xff4af370`) returns true for
exactly part `0x4422`. The identification word is read once per node by `0xff4231e0`, at register offset 0 in the form above: part in bits
27:12, revision in 31:28. So a TIO's chip identification word is the LB register at offset `0x8000_0000` in chiplet 1, part `0x4422`.
`0x4422` appears in the 10.40 and 10.11 images at the same routine (listing grep: one `mov 17442` each; the accept routine is at `0xff4ae620` and the test at `0xff4ae62c` in 10.40, the test at `0xff4af37c` in
10.54 and at `0xff4ab02c` in 10.11). Of the table's slots about 80 are TIO methods; most are empty returns shared with the stub `0xff42c5a0`.
A TIO node is called "headless" in the PROM's messages (no processors).

## Order of events (established unless marked)

1. **Identification.** `0xff4231e0` reads the word at offset `0x8000_0000` (above), stores node id, part, revision and the route word, and
   the part selects the TIO table.
2. **Routing tables and node number** (`Distributing routing tables`, `0xff467320`; the TIO method is slot `0x1d8`, `0xff46eaa0`). The method
   depends on a flag byte of the node object (`ld1` at `0xff46ec40`, inverted, tested by the predicates at `0xff46ec70`; the flag's meaning was not
   traced). Addresses and loop bounds are from the listing.
   - **Flag clear.** For each of the TIO's two network ports n (0 and 1):
     - 256 eight-byte entries at `0xd002_4000 + 0x2000 * n + 8 * i`, written without a prior read, and 256 at `0xd002_4800 + 0x2000 * n + 8 * i`.
       The value is the port nibble from the PROM's route tables. In the first table bit 63 is left unset only when the nibble is `0xf`, i is not 0 and
       i is not the node's own index (`0xff46edd0` to `0xff46edf6`); in the second table bit 63 is always ORed in (`0xff46efb6`).
     - `0xd002_5000 + 0x2000 * n` := 0.
     - `0xd003_0490 + 0x200 * n`: read, bit 0 set, written back (when a port-record flag is set).
     - `0xd003_0520 + 0x200 * n`: when the call's first argument is 0, read, bits 15:8 cleared (`and` with `-65281`) and `0xc000` ORed in
       (`0xff46f6c0` to `0xff46f6fc`), written back.
     - Then once: 256 entries at `0xd002_0000 + 8 * i` and 256 at `0xd002_0800 + 8 * i` (entry, or entry with bit 5 set when only the second table has it),
       and `0xd002_1000` := 0.
     - Then slot `0x1b8` (`0xff46dee0`): for n = 0 and 1, `0xd000_0020 + 0x2000 * n` read and bits 9:0 replaced by `0x190`; `0xd003_0500 + 0x200 * n`,
       `0xd003_04b0 + 0x200 * n` and, when a PROM option read through `0xff4e7020` is clear, `0xd003_04c0 + 0x200 * n` each read and the low nibble of every
       16-bit lane cleared (`& 0xfff0_fff0_fff0_fff0`).
     - Last, slot `0x108` (`0xff4af670`, called at `0xff46f58c`): read-modify-write of `0x90060e80`. Bits 45:32 get the caller-supplied NASID (14 bits,
       `dep.z` width 14 at 32) and bits 53:48 get `2^bitlen(arg >> 9)`, or 1 when `arg >> 9` is 0, truncated to 6 bits (`dep.z` width 6 at 48;
       `0xff4af706` to `0xff4af75c`); every other bit is kept (masks `0xffffc000ffffffff` and `0xffc0ffffffffffff`). Established. This settles the
       [question about TIO_NODE_ID](../../questions/tio-open.md#tio_node_id-upper-bits): the register is a read-write node-number register for a TIO and
       Linux's widget-format reading covers only bits 31:1. The meaning of the 6-bit value is inferred (the SHub 2 page names the same field
       `NODES_PER_BIT`).
   - **Flag set.** Only the four route tables are touched, by read-compare-write, skipping entries whose nibble is plain `0xf`; the method returns 0 at
     `0xff46f4c6` without writing `0xd002_5000`, `0xd003_0490`, `0xd003_0520`, `0xd002_1000`, the slot `0x1b8` registers or `0x90060e80`.
3. **Early init, slot `0x28`** (`0xff4e0150`; prints "Initializing headless node"). In order:
   1. Slot `0x120` (`0xff4af800`), the chipset early init, which has a "not enough malloc space" failure path. It writes `0x90060700` :=
      `0x1_0000_0041` (the call arguments 2 and 50 are in the listing; the reciprocal-multiply form of `50 / 10 - 1` is the decompiler's
      reading, so the value is inferred), `0x901c0000` := 0, calls an empty method, builds two bit vectors of the node table (one of odd
      NASIDs, one of even, `0xff4af400`, using the 6-bit value just read back from `0x90060e80`), and writes the first vector's first four
      words to `0x90060000 + 0x80 * i`, `0xb000_8880 + 8 * i` and `0x90060800 + 0x80 * i` (i = 0 to 3) and the second vector's to
      `0x90060280 + 0x80 * i`, `0xb000_88a0 + 8 * i` and `0x90060a00 + 0x80 * i`. Addresses and widths established; the vector contents and
      what they gate are inferred (likely sharer or presence masks).
   2. Slot `0x2f8` (`0xff4306a0` to `0xff430b00`): node object set-up; no TIO register access seen.
   3. Slot `0x2a8` (`0xff449a10`): writes two tables of (offset, value) pairs, then the interrupt target. The tables (82 and 9 pairs in
      10.54; the first is byte-identical in 10.40 and 10.11) are listed below. Then `0xff449b60` (vector 0x36): the target is a node record fetched through the PROM's global pointer block (entry at offset `0x38`; which node that selects was not traced), `0x90000480` := `0x36 << 52 | pid << 4` (pid computed by `0xff40add0`), `0x90000300` := the target NASID,
      `0x90000500` := `0xd`. A second writer of the same three registers exists in the node-object constructor wrapper `0xff593e20`, which calls
      `0xff59a030` (`0x90000300` at `0xff59a1b6`) and `0xff594480` (`0x90000480` at `0xff594786`, `0x90000500` at `0xff5948a6`); the status pairs
      `0x90010000/08/80/88` are also touched there (`0xff594b16`, `0xff5945d6`, `0xff594c46`, `0xff594dc6`). Values there were not decoded.
   4. Slot `0x308` (`0xff48dfc0`) is called between slot `0x2a8` and slot `0x168`; it is an empty return in the TIO table (listing: only `nop.b` and `br.ret`).
   5. Slot `0x168` reads `0x901d0080` (an error message "reading advertisement register" if the read fails) and slot `0x170` writes it back
      with bits 57 and 40 set (the listing shows `and` with `0xfdff...` and `or` with `0x0200...` at `0xff4e0336` to `0xff4e039c`, then the same for bit 40). The same word is the SHub 1 scratch
      register `SH_SCRATCH1` at the same offset ([SHub reset](../shub/prom-reset.md)); a TIO has it too.
   5a. Before the slot `0x168` read, `0xff4e02cc` calls `0xff419090`, which reads `0x901d0080` through slots `0x168` and `0x170`, clears bit 58 (`0xfbffffffffffffff`) and
      sets it again (read-modify-write; matches the SHub 1 image's `0xffa0afd0`).
   6. Slot `0x288` (`0xff4a91e0`) looks up a PROM-side object for the node and hands it to `0xff4929f0` (not read; no register access seen).
      Slot `0x318` (`0xff4ca440`) creates the klconfig-style board record of type `0x12` (a TIO lboard, via `0xff4b7d70`) and prints a message
      when that fails.
   7. Slot `0x2e0` (`0xff4ca610`) sets flag 2 of the node when slot `0x2d8` (`0xff4ca500`) returns less than 1; `0x2d8` returns -1 and prints
      when `0xff4ae670(0xe)` is non-zero and 1 otherwise. Flag 2 suppresses corelet discovery in late init. What `0xff4ae670` tests is not read.
4. **Late init, slot `0x30`** (`0xff4e0520`; prints "Late initialization of headless node"): calls ten methods, nine empty. The one with
   an effect, slot `0x2e8` (`0xff4ca6f0`), runs corelet discovery (below) unless flag 2 is set.
5. **Interrupt enable** (not in the two init slots; slots `0x228`, `0x248`, `0x250`, `0x258`; call order not traced): see the interrupts section.

### Early-init tables (established, 10.54 `0xff6004d8` and `0xff600a00`)

All are 8-byte stores. Value `-1` is all ones. Offsets carry bit 31.

First table (82 stores; the two lists below are grouped by value, not in store order: the stores of zero begin `0x90071000`, `0xb0000020`, `0xb0002020`): the 30 that write all ones are `0x90010008`, `0x90010088`, `0xb0000008`, `0xb0000018`,
`0xb0002008`, `0xb0004008`, `0xb0006008`, `0xb0008008`, `0xb000a008`, `0xb000b008`, `0xb000b018`, `0xb000e008`, `0xb000e018`,
`0xd0040008`, `0xd0040028`, `0xd0040208`, `0xd0040218`, `0xd0040208` (again), `0xd0040228`, `0xd0040238`, `0xd0040508`, `0xd0040518`,
`0xd0040528`, `0xd0040538`, `0xd0040608`, `0xd0040618`, `0xd0040628`, `0xd0040638`, `0x90050588` and `0x90050508`. The 52 that write zero are
`0x90071000`, `0x90071100`, `0x90071380`, `0x90071900`, `0x90050280`, `0x90050300`, `0x90050380`, `0x90050400`, `0x90050600`, `0xb0000020`,
`0xb0002020`, `0xb0002040`, `0xb0002048`, `0xb0004020`, `0xb0004040`, `0xb0004048`, `0xb0004060`, `0xb0004068`, `0xb0006020`, `0xb0006040`,
`0xb0006048`, `0xb0006060`, `0xb0006068`, `0xb0008020`, `0xb0008040`, `0xb0008048`, `0xb0008050`, `0xb0008058`, `0xb0008060`, `0xb000a020`,
`0xb000a060`, `0xb000a068`, `0xb000b020`, `0xb000e020`, `0xd0000048`, `0xd0002048`, `0xd0040060`, `0xd0040130`, `0xd0040140`, `0xd0040150`,
`0xd0040160`, `0xd0040170`, `0xd0040260`, `0xd0040270`, `0xd0040560`, `0xd0040570`, `0xd0040580`, `0xd0040590`, `0xd0040660`, `0xd0040670`,
`0xd0040680` and `0xd0040690`. Second table (9 stores, all zero): `0xd0040540`, `0xd0040550`, `0xd0040640`, `0xd0040650`, `0xd0040240`,
`0xd0040250`, `0xd0040040`, `0xb0000028` and `0x90050480`.
Inferred from the pattern and from the PROM's error-name tables (`TIO_ICE_*`, `TIO_LB_*`, `TIO_XN*`, `TIO_NI0_*`, `TIO_NI1_*`): these are error
summary clears (0), error mask or enable fills (-1) and detail clears. No register in these tables is read back by the code read.

## Local block map (established offsets, inferred roles)

Offsets the PROM uses against a TIO local block (chiplet 1), with the roles read from the code. No PROM-supplied name exists for any of
them except where the image prints one.

| Offset | Access (width 8) | What the PROM does | Grade |
|---|---|---|---|
| `0x8000_0000` | R | chip identification word: part bits 27:12 must be `0x4422`, revision 31:28 | established |
| `0x90060e80` | R, RMW | node-number register (above); revision in 31:28 is read by the revision method (`0xff4b0550`, slot `0x138`) and by the TIOCA attach (`0xff585010`) and corelet record builder (`0xff4cb310`) | established |
| `0x90060f00` | R | chip-info method (slot `0x298`, `0xff4a9320`): bit 0 flag, bits 3:1 index into the table 7, 10, 13, 20, 23, 30, 33, 36, bits 63:4 plus `0x65` (a rate or speed field); the result block also carries `0x6b`, `0x6b`, 0 and `0x4000`. Consumer: the port discovery slot `0x1c0` | established (access), inferred (meaning) |
| `0x90060700` | R, W, RMW | written `0x1_0000_0041` in early init (above); slot `0x140` writes `(x ^ arg) << 33 | (n/10 - 1) * 16` or `0x1_0000_0001`, slot `0x148` reads bits 33:32 as a mode (1 gives 2, 0 or 2 derive a value from a node-table lookup), slot `0x158` clears bit 0 and bits 33:32 and sets bit 32 | established (access), inferred (value and meaning) |
| `0x901c0000` | W 0, R | real-time clock counter (same offset as the SHub 1 `SH_RTC`): slot `0x150` writes, slot `0x160` reads | established (access), inferred (meaning from the SHub 1 page) |
| `0x901d0080` | R, W, RMW | advertisement or scratch word. Early init read-modify-writes it to set bits 57 and 40; `0xff4b0fc0` is a plain write. Other read-modify-write callers (found by independent review; only the bit-56 constant at `0xff42c6a6` re-checked here) set bit 58 (`0xff4190bc`), bit 40 (`0xff46cfa6`, `0xff47018c`), bits 57 and 40 (`0xff4dac3c`) and bit 56 (`0xff42c6b0`). | established (access) |
| `0x901d0100` | R | L1 state word: bits 15:8 returned by the chip-info method (`0xff4a9320`); also read by slot `0x250` | established (access), inferred (meaning from the SHub 1 page) |
| `0x901d0180`, `0x901d0188` | R, W, RMW | a bit-set register pair. Before a change the PROM calls `0xff4b1720` with `0x901d0188` and a count of 1,000,000, after it `0xff4b1770`, which writes 0 to `0x901d0180`, which reads as a lock and release (inferred). Slots `0xc8` to `0x100` test, set and clear single bits of `0x901d0188` (position n or n + 32) and one waits for a bit to clear with a timeout | established (access), unknown (meaning) |
| `0x90000300`, `0x90000480`, `0x90000500` | W | interrupt target set in early init (above) | established |
| `0x90000980`, `0x90000a00` | W, RMW | interrupt destination `(pid << 4) | 0x0e90_0000_0000_0000` and its enable bits 13 and 16 (slots `0x228`, `0x248`, `0x250`) | established (access), inferred (meaning) |
| `0x90010000`, `0x90010008` | R, W | status, with bits 0, 2 and 3 treated as pending (`& 0xd`) in slots `0x2c0` and `0x2c8`; `0x90010008` is written with the pending bits that were handled (slot `0x2c8`) and `0x0090_0000` in slot `0x228` | established (access), inferred (meaning) |
| `0x90010080`, `0x90010088` | R, W | the second copy of the same pair, `0x90010088` := `0x0090_0000` | established (access), inferred (meaning) |
| `0x90038080`, `0x90038180` | R | read by the status helper `0xff4a47b0`; the base `0x9003_8000` is the one the TIO page puts the system controller UART at (inferred there) | established (access), unknown (meaning) |
| `0x90071a00` | W 0 | written 0 when a TIOCA corelet is attached (`0xff4caf50`, `0xff585010`) | established (access) |
| `0x9005_0xxx`, `0x9007_1xxx` | W | error clear and enable writes from the table above | established (access), inferred (meaning) |

The `0x901d_0100`, `0x901c_0000` and `0x901d_0080` offsets, and `0x1006_0580`/`0x1006_0e80` for the identity word, are the TIO's counterparts to
the SHub 1 registers the [SHub reset page](../shub/prom-reset.md) records at the same low offsets; that the TIO local block shares the layout
is inferred from the equal offsets and equal use (the clock counter, the election word, the L1 state word), not read from a document.

## Corelet discovery and ICE registers (established)

Late init calls `0xff4cc2d0` (the TIO bring-up, "tio_init"; same logic as the SHub 1 image's, [Prism page](../../platforms/sn2/prism.md#sal-465-against-sal-504-ghidra-read-2026-11-22)):

1. Looks up the TIO lboard of the NASID (type `0x12`); with none it prints "No TIO lboard for NASID" and returns.
2. `0xff4ca8e0`: read-modify-write of `0xb000_6100` clearing bit 12, and, when the slot letter returned by `0xff4260f0` is not `b` (compare with 98 at `0xff4caba0`), of `0xb000_8100`
   clearing bit 61. `0xb000_8100` is Linux's `ice_frz_cfg` and bit 61 its `disable_cb`, the conveyor-disable bit the kernel also clears
   ([TIO page](README.md#registers-and-constants-the-code-names)), so the PROM and the kernel agree on that register.
3. For corelet n = 0 to 2 it reads the identification word at the widget window `n * 0x1000_0000` with a 4-byte load (`ld4.acq` at `0xff4cc146`, masked with `0x0ffff000` to give part << 12). A model must accept 4-byte reads at offset 0 of widget windows 0 to 2. Part (bits 27:12)
   `0xe000` or `0xe010`: a TIOCP, attached when the slot-type word from `0xff4cc5c0` is one of `0x6a 0x5e 0x700 0x800 0x6c 0x2b 0x66 0x6b 0x300 0x7b 0xd00
   0x500` or equals `0x600`; for any other word the branch at `0xff4cc1ec` skips it (established from the listing; what the words mean is not read). Part `0xe020`: a TIOCA, only for slot letters `l`, `^`
   and `b` (`0x6c`, `0x5e`, `0x62`). Corelet 3 is the FPGA (CX) port: `0xb000_be18` is read and must equal `0xf`, then the CX setup
   (`0xff492850`) runs; "CX PORT init failed" is printed and the next corelet tried on failure. No test for part `0xce00` (TIOCE) exists
   in the SAL_B code of any of the three images (grep of the listing); TIOCE discovery was not located (unknown).
4. The TIOCA path (`0xff4caf50`, `0xff585010`) zeroes state, writes `0x90071a00` := 0, reads the TIO revision from `0x90060e80` bits 31:28 and keeps it;
   with revision 1 or 2 (`6 >> rev & 1`) the TIOCA guarded-access method (`0xff59ff90`, see the interrupt section) sets bits 17:12 of `0xb000_8100` to `1` around each
   configuration access in the window `0x300_0000` to `0x301_0000` and restores the value afterwards (read in the decompiler only; inferred).

## ITTE (established for the PROM, unknown for hardware use)

- The object constructor at `0xff593df0` (descriptor stored at `0xff6701a0`; its caller was not traced) writes 0 to all eight entries,
  `0xb000_8800 + 8 * i` for i = 0 to 6 in a loop and `0xb000_8838` after it (listing: base `0xb000_8800`, `cmp4.eq 7`, final constant
  `0xb000_8838`, each a store of zero). Zero has the valid bit (bit 16) clear.
- An allocator in the function at `0xff592d50` writes valid entries: it forms `0xb000_8800` at `0xff5930b6` (and `0xb000_8838` for entry 7) and stores through
  `0xff420840` at `0xff59314c` and `0xff5937bc`. The value is `(addr >> 30 & 0xff)` (`extr.u 30,8`), `| (widget field << 12 & 0x3000)` (`dep.z 12,2`) and
  `| 0x10000` (the valid bit). A release routine at `0xff593a30` writes 0 back (store at `0xff593c3c`), and a reader at `0xff56c340` loads entries
  (`0xff56c60c`). Whether the boot path reaches the allocator, and with what widget and address, was not traced.
- The constructor also sets up five widget window records at `n * 0x1000_0000` (n = 0 to 4) and eight big-window records of 1 GiB each; the
  eighth has a different base (`(1 << (38 - V)) - 0x2_0000_0000`) and type, which fits the `TIO_HWIN` selector's entry 0. This is bookkeeping in the
  PROM's memory, not register traffic.
- Linux never writes the entries (it reads a firmware copy). The copy comes from `SN_SAL_IOIF_GET_HUBDEV_INFO` (`0x02000055`), which copies `0x2f0` bytes of
  the node's PROM-side object into the caller's record (`0xff561d80`), so the copy is the PROM's object, not a read-back of the registers. What the object
  holds for the ITTE field was not decoded.
- Settles the [ITTE question](../../questions/tio-open.md#itte-use) only in part: the entry layout the PROM writes matches Linux's macro (offset 7:0, widget
  13:12, valid 16). Still unknown: whether boot reaches the allocator, why `TIO_HWIN` selects entry 0, and what the hardware does for a PIO that hits an
  invalid entry.

## Interrupt delivery (established access, inferred meaning)

- **Target for the TIO's own error interrupt.** Early init sets `0x90000480` to `0x36 << 52 | pid << 4`, `0x90000300` to the target NASID and
  `0x90000500` to `0xd` (above). Vector `0x36` is Linux's `SGI_TIO_ERROR`. The 16-bit pid is built by `0xff40add0` from the target NASID
  (`(nasid >> 8 & 0x3f) << 10 | (nasid >> 1 & 0x7f)`) and the target's processor slice index; the target record comes from the PROM's global pointer block (offset `0x38`); which node that is was not traced, so the
  destination of the TIO error interrupt is unknown beyond "a SHub node". The bit layout (vector 59:52, pid 19:4) is the SHub
  interrupt message layout the [SHub interrupts page](../shub/interrupts.md) records for other registers.
- **Slot `0x228` L1-word step** (`0xff4a5010`, same slot in the SHub 1 image at `0xffa90430`): before the target writes it does a read-modify-write of `0x901d0100`
  (`& 0x83ffffffffffffff | 0x1c00000000000000`, `0xff4a5216`, `0xff4a5236`) and tests the cpuid[2] signature `0xaeeeeeee8badbeef` (`0xff4a5276`); the SHub 1 image stores 0 to
  `0x9003_8180` on the not-equal path, and the SHub 2 code calls `0xff4a4400` at the same point (`0xff4a52bc`); that this is the same store was not decoded here.
- **Second target.** Slot `0x228` writes `0x90000980` := `(pid << 4) | 0x0e90_0000_0000_0000` (vector `0xe9`), `0x90000a00` := 0 and
  `0x90010008`, `0x90010088` := `0x0090_0000`. Slots `0x248` and `0x250` set or clear bit 13 or bit 16 of `0x90000a00`. When enabling,
  and when the status helper reports a pending source, the PROM sends one message itself: a store to the target SHub's register at global
  offset `0x1000_0380` (`0x3_1000_0380 | target << (40 - V)`) with `(pid << 4) | 0x8e90_0000_0000_0000` (read in the decompiler only;
  inferred). The register `0x1000_0380` on a SHub is not named in any held source.
- **Bridge interrupts are allocated by the SAL runtime, not by TIO registers.** The call `SN_SAL_IOIF_INTERRUPT` (`0x0200004a`, `0xff544130`)
  dispatches alloc (`+0x28`), free (`+0x30`) and redirect (`+0x38`) through a per-widget provider object found from the node record (offset `0x958`,
  `0x30` bytes per widget); which functions those are was not identified. (The bridge-type tables `0xff650910`, `0xff6509f8` and `0xff650ac8`, for
  TIOCP, TIOCA and TIOCE, are a different table: `SN_SAL_IOIF_PCI_SAFE` calls offset `+0x30` of it, which for the TIOCA is `0xff59ff90`, the guarded
  PCI access method that touches `0xb000_8100`.) The functions fill the `sn_irq_info` record Linux reads back (vector, bit, cpu, crosstalk address); the address
  computation was not read, so the target address a TIOCP, TIOCA or TIOCE writes is unknown.
- Linux's own TIO-side expectations are on [the TIO page](README.md#interrupts-established-unless-marked). The kernel's error handler makes one
  SAL call and panics on a non-zero result, so a model that returns success from `SN_SAL_HUB_ERROR_INTERRUPT` (`0x02000060`) is enough
  for Linux; the PROM-side handler for it was not read.

## What Linux needs for the Prism AGP aperture through a TIOCA (established as code, from the kernel pages)

All of it is the kernel writing the TIOCA's own registers; none of it touches a TIO local-block register, an ITTE entry or `TIO_NODE_ID`
(the kernel reads `TIO_NODE_ID` only through the revision the PROM puts in the bus record). The order is on
[the Prism page](../../platforms/sn2/prism.md#bring-up-order-established-as-the-code-order): control 1 bit 42, control 2 bits 33:32
set to 2 and bits 35:34 cleared, the status and multiple-error aliases written, the interrupt mask cleared for bit 4, the aperture word `0x80200007` (16 KiB
pages, 2 GiB, base `0x80000000`) to offset `0x28` and the table pointer, with bit 0 set, to `0x200`. The TIO side must therefore:
accept the TIOCA's widget window (identification word with part `0xe020`, manufacturer `0x24`); keep its registers readable and writable so the
read-modify-writes succeed; accept 8-byte coherent writes into the GART table address the kernel allocates on the closest node; deliver the
TIOCA error interrupt as vector `0x35` through whatever the SAL runtime allocated (unknown above); and report TIO revision 2 or
later if a model wants to avoid the revision A flush workaround (`PV910244`). Which TIO revision the real Prism boards carry is unknown.

## Ready-to-model list

What a TIO model must do for the SHub 2 PROM to take one TIO from "node present" to a finished early and late init, and for Linux to see
the widgets. This is a software contract. That the PROM then reaches the `Shell>` prompt and Linux logs in on a machine with a TIO is not
established here: no image was run, and the TIO is only one of the chips the PROM must find (see unknowns).

| # | Row | Needed behaviour | Grade |
|---|---|---|---|
| 1 | Identity word at LB offset `0x8000_0000` | bits 27:12 = `0x4422`, 31:28 = a revision, bits 11:0 plausible; readable before any write | established (access), unknown (revision and low bits) |
| 2 | `0x90060e80` node-number register | readable and writable (64-bit); the node-number method (flag clear only, see order of events) stores bits 45:32 and 53:48, keeps bits 47:46 and 31:0; bits 31:28 = the same revision | established |
| 3 | Route tables `0xd002_4000`..`0xd002_5000` per port (stride `0x2000`), `0xd002_0000`, `0xd002_0800`, `0xd002_1000`, `0xd003_0490/0500/04b0/04c0/0520` (stride `0x200`), `0xd000_0020` (stride `0x2000`) | plain read/write storage, 8 bytes. With the node flag clear the first tables are written blind and the rest of the list is written; with it set only the four tables are read-compare-written and the others are not touched | established (access), inferred (which are optional) |
| 4 | `0x90060700`, `0x901c0000`, `0x901d0080`, `0x90060000/0x90060280/0x90060800/0x90060a00` (stride `0x80`, four each), `0xb000_8880..8898`, `0xb000_88a0..88b8` | plain read/write storage; `0x901d0080` is read-modify-written (bits 57 and 40 set) by early init and other callers, so it must read back whatever was last stored | established (access) |
| 5 | The 91 early-init stores listed above (`0x9001_xxxx`, `0x9005_xxxx`, `0x9007_1xxx`, `0xb000_xxxx`, `0xd000_0048`, `0xd000_2048`, `0xd004_xxxx`) | writes accepted; values unobserved; no read-back found | established (access) |
| 6 | Interrupt registers `0x90000300/0480/0500/0980/0a00`, status pairs `0x90010000/0008/0080/0088` | writes accepted; reads of `0x90010000` and `0x90010080` return 0 (no pending bits; `& 0xd` must be 0) | established (access), inferred (0 for no pending) |
| 7 | `0x90060f00`, `0x901d0100` | readable; the values feed the port-discovery result (a rate index and a byte); any value avoids a fault, which values the later code accepts is not traced | established (access), unknown (valid values) |
| 8 | ITTE `0xb000_8800`..`0xb000_8838` | eight read/write words, zeroed by the constructor; an allocator writes valid entries `(addr >> 30 & 0xff) | (widget << 12) | 0x10000` and a release routine writes 0 (whether boot reaches the allocator is not traced); Linux never writes them | established |
| 9 | `0xb000_6100` bit 12 and `0xb000_8100` bit 61 | read-modify-write storage (clear bits); `0xb000_8100` is the kernel's `ice_frz_cfg` | established |
| 10 | Corelet windows `0x0`, `0x1000_0000`, `0x2000_0000` (chiplet 0) | a 4-byte-readable identification word per corelet (the PROM reads it with `ld4.acq`): part `0xe000`/`0xe010` (TIOCP) or `0xe020` (TIOCA), manufacturer `0x24`; an absent corelet must return a part that matches none of these (what hardware returns is unknown) | established (code), unknown (hardware) |
| 11 | `0xb000_be18` | reads `0xf` only when an FPGA port is present; any other value skips the CX port silently | established |
| 12 | SHub target register at global offset `0x1000_0380` | accept a 64-bit store when the TIO's interrupt is forwarded by hand | inferred |
| 13 | The vector path registers `0x1006_7000/7080/7100`, `0x1007_4000/4100` on the TIO | needed only when a node's route word is non-zero; unknown whether it is for a TIO | unknown |

The TIOCP and TIOCA bridges' own set-up by the PROM (`0xff4cae30`, `0xff514a30`, `0xff59ece0` and the provider tables) was listed but not read
register by register, so rows for the bridges' own registers are not on this list; the TIOCA and TIOCP kernel pages and the
[SAL 4.65 against 5.04 reading](../../platforms/sn2/prism.md#sal-465-against-sal-504-ghidra-read-2026-11-22) are the sources until a
register-level reading exists.

## Builds

- **10.40 (SAL 1.40):** same TIO class (accept routine `0xff4ae620`, test at `0xff4ae62c`), same set of TIO-form immediates (46 values compared by a listing scan,
  no difference) and a byte-identical early-init tables (82 and 9 pairs). Method bodies were not compared one by one.
- **10.11 (SAL 1.11):** the same 46 immediates plus four more, `0x90001080`, `0x90001180`, `0x90001800` and `0x90001880`, used by the TIOCA
  attach function there (`0xff585046` to `0xff5853f6`, and `0xff585e96`); not present in 10.54. Their role is unknown. The first early-init table
  is identical. The accept constant `0x4422` is present.
- **SHub 1 builds (SAL 5.04, 4.65), which Prism and the Altix 350 use:** the 5.04 TIO class methods and the TIOCA set-up are read in
  [prom-access-shub1.md](prom-access-shub1.md); 4.65 is not re-read there.

## Unknowns and what would settle each

- **Whether the PROM tolerates a missing TIO register.** Every access is an unchecked 8-byte load or store except the routed path
  (status codes -1 to -7). What a store to an undecoded TIO address does is not in any source. Route: a run of the image against a
  model that logs accesses (the model run is model behaviour, never hardware evidence), or a hardware capture.
- **The reset values of every row above**, including the revision a real TIO reports. Route: a TIO register specification, or a captured
  read of a register the PROM never writes (the identity word qualifies).
- **How the node reaches a TIO before routes exist** (vector path or direct): the route word's source in the node record and its value for a
  TIO were not traced. Route: trace the node-record builder `0xff4231e0`'s callers `0xff4192d0` and `0xff491d90`.
- **The address a bridge writes to raise an interrupt** (the crosstalk address in `sn_irq_info`): the allocation functions of the three
  providers (`0xff556670`, `0xff59fe30`, `0xff5b0290` and the helpers they call at `0xff555600`, `0xff59f3e0`, `0xff5af950`) were opened
  but not followed. Route: read those helpers; settles the open point on [the TIO interrupt question](../../questions/tio-open.md#tio-interrupt-delivery).
- **TIOCE discovery in SAL_B** (no `0xce00` test found) and the SHub 2 PROM's TIOCE provider (`0xff650ac8`). Route: the callers of the type-5
  provider table.
- **Meaning of the `0x901d0180` and `0x901d0188` pair, `0x90060700`, `0x90060f00`, the 4-word vectors at `0x90060000`, `0x90060280`,
  `0x90060800`, `0x90060a00` and of the route-table registers.** Route: the PROM's `SH2_`/`TIO_` register-name tables (the SHub 2 record
  table at `0xff61bd40` has no TIO entries; the TIO names sit in the error decoder, `0xff4179c0` and neighbours, which pair a name string with a
  record offset the decoder prints) or the register specification.
- **The four extra 10.11 immediates and the SHub 1 TIO class.** Route: read `0xff585046` in 10.11; compare slot `0x28` of the SHub 1 TIO table.
- **Whether a model that satisfies this list reaches `Shell>` and a Linux login.** Not established: the rest of the node set-up (L1,
  memory, the other chips) is on the [boot-sequence](../../software/firmware/snprom/boot-sequence.md) pages, and the TIO rows are only the TIO's part.
