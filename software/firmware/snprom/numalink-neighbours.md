# What the SAL 5.04 PROM needs from a NUMAlink neighbour

The SHub 1 PROM (`shub1snprom.bin`, SAL 5.04, snprom 10.54, sha256 `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`)
finds other nodes and routers by sending vector requests out of the node's two network ports. This page is the contract a
stand-in must keep so the PROM goes on: what a second SHub 1 node reached over a linked port (case S1) and an NUMAlink 4
router reached over a linked port (case S2) have to answer, what to record, and what an unexpected access means. The
mechanisms are read in [boot-sequence.md](boot-sequence.md#numalink-discovery-with-a-linked-port-the-neighbour-crawl-sal-504),
[the vector request](../../../devices/router_nl4/node-access.md#shub-1-sal-504-the-vector-request-as-the-image-sends-it) and
[router access](../../../devices/router_nl4/global-config.md#router-access-from-a-shub-1-node-sal-504); this page only
collects them by register.

Method: Ghidra (the whole-image decompile with this repository's IA-64 processor) for every function, an
`ia64-linux-gnu-objdump` listing for the branch tests and constants. Nothing was run, no hardware was read. Independently reviewed: see [Review](#review); the corrections it made are in the text.

Amended on 2026-11-21 after an emulator run of the stock PROM against a stub built from this page (the rows below that
say so were corrected by it). An emulator run shows what the PROM did against that stub, not what hardware does: where a
row says "seen in an emulator run" the fact is graded *inferred* unless the sentence also names the code path read in the
image. The amendments (S1 rows 2 and 10, S2 rows 4, 6 and 9, the two sections after the S2 table and the interrupt-scrub
row) were independently reviewed on 2026-11-21: see [Review](#review).

**Grades.** *established*: read in the image (a software expectation: the PROM does this or requires this value; it says
nothing about what the hardware does). *inferred*: reasoned, with the reasoning. *unknown*. **Stand-in choice** marks a
value the image does not constrain and the stand-in has to pick; it is an approximation of the hardware, not a reading.
A reset value is established only when the PROM depends on it; none of the neighbour's registers has one that was read
from hardware.

## Address checks

Every address the request named, read in the image (the SHub 2 column is for the comparison the request asked for).

| Claimed | Verdict |
|---|---|
| `0x1_101d_0080` is a firmware mailbox word | confirmed: it is `SH_SCRATCH1`; the word is built by `0xffa46530`, bit table in boot-sequence |
| `0x1_5000_0010 + (port << 13)` bit 0 | confirmed: `LLP_RESET_EN.OK`, read by `0xffa5e0b0` only when the neighbour's word has bit 40 set |
| crawl at `0xffa47290` | confirmed (`0xff44fd70` in SHub 2) |
| step `0xffa45780` | confirmed: the per-neighbour step; reads chip word via `0xffa46a50` ("intcon_chklink") |
| `0xffa469f0` | confirmed: reads the neighbour's `0x1_5003_1580` through the vector read |
| `0xffa5b5d0` as a vector-request routine | **wrong: it is "intcon_distribute_numbers" ("Distributing routing tables")**; the vector routines are `0xffa0bd20` (read) and `0xffa0c560` (write) |
| route calculation `0xff4663d0` (SHub 2) | SHub 1 counterpart `0xffa5a670` ("Calculating routes"; 3936 against 3920 bytes) |
| SHub 2 read `0xff419e80` and "write neighbour" | write is `0xff41ad30`; SHub 1 counterparts `0xffa0bd20`, `0xffa0c560`; the SHub 2 pair has no error-summary poll |
| router parts `0x239` / `0x4422` "inferred from SHub 2 only" | closed for 5.04: the four method tables are read: `0x4363` SHub, `0x3017` NL3 router, `0x239` NL4 router, `0x4422` TIO |
| the node-bring-up page's "(hops - 1) * 2" in the request word | wrong: it is `(first route nibble - 1) * 2` |

## What the local node must give the PROM first

For either case the node the PROM runs on (A) needs, besides everything its single-node bring-up already needs:

| Register (A, SHub 1 offsets) | Answer | Grade |
|---|---|---|
| `VEC_PARMS` `0x1_1006_6080` | bit 63 (`BUSY`) reads 0 whenever idle; a write with bit 62 set starts a request: `PIO_ID` 45:35, `ADDRESS` 34:3, `NI_PORT` bit 1, `TYPE` bit 0 | established |
| `VEC_DATA` `0x1_1006_6000`, `VEC_ROUTE` `0x1_1006_6100` | storage; log each request with route, address, data | established |
| `VEC_STATUS` `0x1_1007_4100` | a write of 0 clears it and bit 63 must then read 0; within 100 us of the start (the first poll; the PROM polls up to 1024 times at 100 us) it reads: bit 63 set, bit 62 0, `TYPE` 0 for a read or 1 for a write, `PIO_ID` the request's (`0x1c8` read, `0x7b` write), bits 34:3 the request's address, bits 59:46 any | established |
| `VEC_RDDATA` `0x1_1007_4000` | the PROM stores `0xdeadbeefdeadbeef` first (a read of it before the reply is stale), then reads the answer here | established |
| `LB_ERROR_SUMMARY` `0x1_1005_0580`, `LB_ERROR_DETAIL_1` `0x1_1005_0200` | read 0 (bit 16 clear; low byte not `0xe9` or `0xea`); the alias, mask and detail writes are accepted | established |
| `NI_PORT` routing | the first route nibble (1 = NI0, 2 = NI1) minus one picks the port; the remaining nibbles go to `VEC_ROUTE` shifted down one nibble, or `0xf00000000` when none remain | established |
| `LLP_STAT` `0x1_5000_0000 + p * 0x2000` | low nibble 9 on the linked port p; any other value on the other port | established (the nibble); the other bits unknown |
| `LLP_ERR` `0x1_5000_0048 + p * 0x2000` | bit 27 clear (the PROM writes it back clear and re-reads if set; set again means "down, no message"); bytes 0 and 1 constant. The node set-up also writes 0 to it on both ports (S1 row 2): accept the write and keep bit 27 clear after it; ignoring it was enough in an emulator run | established (reads and the write); the effect of the write on the counters is not read |
| `0x1_5000_1040 + p * 0x2000 + 16 * i`, i = 0 to 3 | bits 22:16 non-zero (value `0x10000`: **stand-in choice**; the PROM tries 128 times per register, then fails the port; skipped when CPU ID register 2 is `0xaeeeeeee8badbeef`) | established |
| `LLP_RESET_EN` `0x1_5000_0010 + p * 0x2000`, `LLP_CONFIG` `+0x20`, `LLP_CHAN_MODE` `+0x18`, `LLP_TEST_CTL` `+0x28`, `LLP_RESET` `+0x08`, the flow registers `0x1_5003_03a0` to `0x1_5003_0400` | storage; `LLP_RESET_EN` resets to 1 (inferred from the header's init macro) | established (the accesses) |

A's other port must read as "down" (nibble not 9): the PROM then prints "shub_port_status: vector ... failed" for it,
which is expected, and during distribution retries a link reset on it for up to about 700 us.

## S1: a stand-in second SHub 1 node, one linked port

A is node 0 with its port `p` (0 = NI0, 1 = NI1) wired to the stand-in's port `q`. The route to the stand-in is the single
nibble `p + 1`. Rules: every register not listed is plain 64-bit storage (reads return the last write, 0 before) and the
first touch of each is logged; every request is logged with route, address and, for a write, data. Offsets are the
stand-in's own node-relative offsets (the request's `ADDRESS` carries bit 32, so the `0x1_` bias is part of it).

**Expected sequence (established, in order):** chip word reads; the link-quality re-reads; claim (read, two writes, port reads on both of the stand-in's ports, a write); the `SCRATCH2` read; the insert (no further access); "Discovery
results"; route calculation (no access); distribution writes; `SH_SHUB_ID` read-modify-write; nothing more was read for
the PROM's stages after "Distributing routing tables". With the stand-in claimed, the wait loop skips it and no barrier or election includes it (established, see
[the barrier section](#barriers-master-election-and-the-stages-after-distribution-with-a-second-node)); the stages after
distribution that do touch it are in the same section.

| # | Stand-in register | Accessed by | Answer | Log | An unexpected access means |
|---|---|---|---|---|---|
| 1 | chip word `0x1_0000_0000`, read | `0xffa46a50`: first, then 1, 2 or 4 more (debug-word bits 1:0 = 0, 2, 3; the value 1 skips them), retried once on error | bits 27:12 `0x4363` (established: the only value that selects the SHub method table); bits 31:28 the same revision A's own word has (stand-in choice); bits 42:32 the stand-in's NASID (read only if its `SCRATCH1` bit 40 is set; 0 until the PROM writes `SH_SHUB_ID`, stand-in choice); **bit 56 = q** (established as the field read; that it is the port is inferred); everything else 0 | every read; count | a read with a route of two or more nibbles is **expected** once the claim has published port q (row 7): the crawl steps out of the stand-in's port q, the request goes back to A and A answers it as its own chip word ([loop-back](#what-an-emulator-run-of-the-stock-prom-showed-2026-11-21)) |
| 2 | `LLP_ERR` `0x1_5000_0048 + k * 0x2000`, read (k = q for the link-quality check; both ports for the claim, which reads it first on each); **written 0 on both ports by the node set-up** | link-quality check; claim; the error-clear list (below) | reads: bit 27 clear; bytes 0 and 1 constant (0): the PROM fails the step if a counter grows by more than 50 between its reads. The write: accept it (plain storage or ignore it, and keep bit 27 clear) | each read and write, with the caller's `b0` | a write of 0 whose caller is the list writer (return address `0xffae4050`) is expected, not a sign of a set bit 27: slot 84 (the local node) and slot 85 (the remote node set-up, so also the stand-in through its global window) write the 70-entry error-clear list at `0xffbd8e18` through `0xffae3f50`, whose `NI0_LLP_ERR` and `NI1_LLP_ERR` entries are 0 at `0x1_5000_0048` and `0x1_5000_2048` ([prom-reset.md](../../../devices/shub/prom-reset.md#the-xn-compare-words-the-prom-zeroes-in-the-chip-object-method-at-0xffa236f0)); slot 85 calls the writer at `0xffa2389c` (this list) and `0xffa238bc` (the 24-entry list at `0xffbd93e0`), established in the listing. Only a write from the probe `0xffa5cf40` is the clear of a set bit 27 (a read returned it set) |
| 3 | `LLP_STAT` `0x1_5000_0000 + k * 0x2000`, k = 0, 1, read | claim (`shub_port_status` against the stand-in) | port q: low nibble 9; the other port: not 9 | each read | the other port read as 9 would set both mask bits |
| 4 | `0x1_5000_1040 + q * 0x2000 + 16 * i`, i = 0 to 3, read | same | bits 22:16 non-zero | each read | more than 128 reads of one register: the value is wrong |
| 5 | `SCRATCH1` `0x1_101d_0080`, read | claim; the wait loop only for an entry that was not claimed | **0** on the first read (established: 0, or any word with bit 41 or bit 39 set and bits 55:54 clear, lets the claim go on; non-zero otherwise stalls the claim 300 s and then forces bit 41; bits 55:54 non-zero makes the PROM skip the claim entirely, which is the "already prepared" model, not S1) | each read | a read that returns bits 55:54 set before any write: the claim was skipped and the stand-in is not programmed |
| 6 | `0x1_5003_1550`, `0x1_5003_1540`, write | claim | accept; expected data 0 | each write | none |
| 7 | `SCRATCH1`, write | claim | accept; expected value `0x0040008000000000` for q = 0 or `0x0080008000000000` for q = 1 (bit 39, plus bit `54 + q`: only port q is up) | the write | a value with bit 41 only: the claim timed out |
| 8 | `SCRATCH2` `0x1_101d_0100`, read | `0xffa8d120`, from `shub_discover` | low byte `0x6c`; bits 34:26 rack, 25:20 bay, 18:16 slab, 15:8 partition; **must differ from A's in the geoid key** (A's is `0x0410006c` for rack 1 bay 1 slab 0). For the second node of one brick use A's rack, bay and partition with slab 1: `0x0411006c` (the shape the brick's L1 writes; [A second node that runs its own PROM](#a-second-node-that-runs-its-own-prom-the-two-node-brick)). `0x0420006c` (bay 2) also passes and was the earlier stand-in choice | the read | a read failure prints "shub_discover: sysctl_get_pushed_data failed", and a stand-in that returns A's value is dropped as the same chip |
| 9 | `0x1_5003_1580`, read | only the wait loop and the barrier, neither of which includes a claimed stand-in | storage | each read | a read means the stand-in was waited for: its flags lack `0x10000` |
| 10 | NI tables: local `0x1_5002_2000 + k * 0x1000 + 8 * i` (i < 128), global `+0x400` (16), override `+0x480`; memory `0x1_5002_4000`, `+0x400`, `+0x480`; I/O `0x1_5002_0000`, `+0x400`, `+0x480`; processor `0x1_5002_1000`, `+0x400`, `+0x480`; k = 0, 1 | `0xffa5e880` (distribution), vector writes; read-back first when the entry's NASID is final | accept; read back what was written | every write: address, value | writes to NI tables with a valid bit (63) in an entry other than 0 and A's and the stand-in's own: a route to a third node |
| 11 | `0x1_5003_03a0 + k * 0x200` (read-modify-write, OR `0x100`, or `0x101` when the port record's bit 5 is set), `0x1_5003_0400 + k * 0x200` (`(v & ~0xff00) | 0xc000` only when A has no router), flow registers `0x1_5003_03c0`, `03d0`, `03e0`, `03f0` (read-modify-write, mask clears) | distribution; `0xffa5d850` | storage with read-back | each access | none |
| 12 | `LLP_CONFIG` `0x1_5000_0020 + k * 0x2000` (bits 9:0 set to 400), `LLP_CHAN_MODE` `+0x18` (read, bit 0), `LLP_TEST_CTL` `+0x28` (read; bits 41:40 written), `LLP_RESET` `+0x08` (write 1 when the port reads down) | `0xffa5d850` | storage | each access | `LLP_RESET` writes on port q: the PROM saw q down |
| 13 | `0x1_2000_0000`, write `0x0001000100000000`; `0x1_5003_1550` read-modify-write clearing bits 29:26; 300 ms wait on A's side | `0xffa9fc70` | accept | each access | none |
| 14 | `SH_SHUB_ID` `0x1_1006_0580`, read then write | `0xffa95a30` | read: whatever A's reads; the PROM writes back with NASID bits 42:32 = the stand-in's new NASID (2 by the defaults, inferred) and two size fields (bits 45:44 and 52:48, values not decoded) | read and write | a NASID other than 2 means the defaults changed |

Table values (replaces an earlier inference of `VALID | 4` for local entry 0). **Established** for the rule: in `0xffa5e880`
the value of an entry is the turn nibble of the PROM's route table for it (`0xf` when the route programmer stored none), and
`VALID` (bit 63) is added when the entry is entry 0, or its nibble is not `0xf`, or it is the node's own entry (the
global tables get `VALID` only for a nibble other than `0xf`). **Seen in an emulator run** for the values the stand-in
received (the run had no router, so the route programmer stored nothing for the stand-in's own tables): local tables
(`0x1_5002_2000` and `0x1_5002_3000`) entry 0 (A, NASID 0) and entry 2 (the stand-in) are `VALID | 0xf`, every other entry
is plain `0xf`, the global tables are plain `0xf`, the override tables 0. The node-end turn count 4 (0 for a router, from
`0xffa5e510`) appears in the memory (`0x1_5002_4000`), I/O (`0x1_5002_0000`) and processor (`0x1_5002_1000`) tables, which
are written by the same routine straight after the local tables (not at progress 0x23): entry 0 is `VALID | 0x0404` (the
nibble in both byte fields), entry 2 is `VALID | 0x0f0f`, the rest plain `0x0f0f`. The vector route for each write is the
nibble `p + 1` alone, so `VEC_ROUTE` reads `0xf00000000`. What the values 4 and 0 are, which register fields they land in and which
word the memory, I/O and processor tables get from the two ports is in
[the terminal hop values](../../../devices/router_nl4/global-config.md#the-terminal-hop-values-0-and-4): 4 when the
destination is the neighbouring node, 0 when it is the neighbouring router, both the same in the SHub 2 image. Words for a router that reports part `0x3017` (NL3) on a node's NI port also carry `V0`/`V1` in the processor table.

**What S1 does not establish.** The barriers, the election and `main_three` for two nodes are read in
[the section below](#barriers-master-election-and-the-stages-after-distribution-with-a-second-node). Two results change
this page: the claimed stand-in is **not** inert after distribution (the node set-up and its latch run against it at
progress 0x23, and the board walk reads the peer's memory), and a stand-in that publishes its own word with bit 22 set is
excluded from every election and barrier, so a passive stand-in can be the other model.

## A second node that runs its own PROM (the two-node brick)

Read on 2026-11-22 in the same image (Ghidra decompiles of `0xffa8d120`, `0xffa5df20`, `0xffa5d2a0`, `0xffa7d010`, `0xffa7d510`, `0xffa7d760`, `0xffa7d950`, `0xffa7ca10`, `0xffa7cbe0`, `0xffa7ce90`, `0xffaac4b0`, `0xffa11ab0`, `0xffa450e0`, `0xffa4d390`; the `ia64-linux-gnu-objdump` listing for call order). Nothing was run. The Altix 3300 and 3700 C-brick holds two nodes joined by one internal NUMAlink ([altix-3000.md](../../../platforms/sn2/altix-3000.md)); both run this PROM. S1 above is the case where node B is a passive register file. Here B executes the same code as A. Timeline of the `SCRATCH1` events: [boot-sequence.md](boot-sequence.md#when-each-node-publishes-bits-5455-and-22-execution-order).

**Identity of one node (what its own PROM derives; established).** In `main` (call `0xffaac4b0(2, nasid)` at `0xffa19d8c`) the node asks its own system controller over its own UART window (the request carries no node selector: the L1 tells the nodes apart by the link the request arrives on), caches the answers per node object (`0xffa81510` lookup, `0xffa81630` store) and builds the 12-byte local geoid:

| Field | L1 request | Site | Lands in |
|---|---|---|---|
| rack, bay, type | `0x0003` (word: rack bits 15:6, bay 5:0; second integer the type letter) | `0xffa7ca10`, folded by `0xffa7d510` (`5`, `o`, `m`, `@` to `c`), packed by `0xffa7d010` | module word `rack << 16 \| type << 8 \| bay`, so rack 1 bay 1 type `c` is `0x00016301` |
| slot | `0x0013` (first integer) | `0xffa7d760` via `0xffa80270` | geoid bits 47:44 |
| slab | `0x000e` (one integer, a signed byte) | `0xffa7d950` via `0xffa802f0` | geoid bits 43:40 |
| partition | `0x0009` | `0xffa7db00`, call at `0xffa19dec` | record byte `+5`, the same byte `SCRATCH2` bits 15:8 carries |

So the **slab is the SHub's index in the brick**: node 0 of a C-brick answers `0x000e` with 0 and node 1 with 1 over its own UART ([altix-3000.md](../../../platforms/sn2/altix-3000.md) names node 0 as slab 0). The same reply feeds `SCRATCH2` bits 18:16 when the L1 writes that register at reset (`(shub & 0xf) << 16`, [prom-reset.md](../../../devices/shub/prom-reset.md)); `0xffa8d120` reads bits 18:16 (3 bits), 38:35 (4 bits, the slot nibble), 34:26 and 25:20 (rack, bay) and 15:8 (partition), packs type `c` (99) fixed, and ORs a flag when bit 19 is set (`0xffaac0a0` stores a 1 in a RAM record byte; its reader was not traced). Established.

**What the neighbour sees, and what must agree (established code; the consequences inferred).**

1. A reads B's `SCRATCH2` in `0xffa5df20`, after the claim test `0xffa5d2a0` returned non-negative: for a claimed node and for one found "already prepared" (bits 55:54 non-zero) alike. The geoid built from it is compared with every table entry by `0xffa11ab0`: low 32 bits (rack, bay, type; bits 15:8 masked), then the slot nibble, then the slab (signed), then the kind. Equal means the same chip and nothing is added.
2. A's own entry is built from L1 answers, B's from `SCRATCH2`, and each node also meets *itself* through the loop-back crawl. For that dedup, and for the two entries to differ, the L1 answers and `SCRATCH2` of each node have to agree: `0x0003` rack, bay and a type that folds to `c`; `0x0013` equal to `SCRATCH2` bits 38:35; `0x000e` equal to bits 18:16. A C-brick's L1 reports type `5` (folded to `c`).
3. The two entries differ only by slab, so they are one brick's two nodes; the partition byte is the same. A lower slab compares lower (`0xffa450e0` inserts a negative compare in front): **slab 0 is first in the list and gets NASID 0, slab 1 gets NASID 2** from `0xffa4d390` with the default `NASIDOffset` 0 and `NASIDStride` 2 (type-1 entries in list order; the stride arithmetic is in `0xffa149c0`, whose body was not read: the 0, 2 rule is the earlier reading). Each node runs the same numbering on its own list, so both reach the same assignment if both lists hold both entries. Node B then installs NASID 2 in its own `SHUB_ID` (`0xffacd2b0`) and runs the NASID-change block of `main_three` that node A skips.
4. A passive B that A has claimed (S1) gets its NASID, tables and `SHUB_ID` from A's distribution instead; its `SCRATCH2` still has to carry its slab.

**Router module word (S2 row 7) for comparison.** `0xffa668b0` builds the router's `SCRATCH0` from the same three L1 requests (`0xffa80dd0` module id in bits 31:0, `0xffa81170` slab `& 0xf` at bit 32, `0xffa80f90` slot `& 0xf` at bit 42), so a router's L1 plays the same role as a node's.

**Per-node accesses before the neighbour exists (summary of the order, established).** Own `SCRATCH2` pre-loaded by the L1; L1 requests `0x0003`, `0x0013`, `0x000e`, `0x0009`, `0x0001` (rows 3 to 7 of the request list in [boot-sequence.md](boot-sequence.md#the-l1-requests-from-reset-to-the-end-of-memory-set-up-with-arguments)); first `SCRATCH1` publication; crawl; count; wait; bit 22; elections; barrier; numbering; distribution; barrier; NASID install.

**What B's hardware and L1 must present for A to come out right.**

| # | Item | Value | Grade |
|---|---|---|---|
| 1 | B's `SCRATCH2` at A's read | low byte `0x6c`; A's rack, bay and partition; slab 1; bits 38:35 equal to B's `0x0013` answer (0 for racks below 512); bit 19 clear | established (decode); the L1's own write is established in the sysco repository |
| 2 | B's L1 over B's UART | `0x0003`, `0x0013`, `0x000e` (= 1), `0x0009` consistent with row 1; replies per [l1-requests.md](l1-requests.md) | established |
| 3 | B's `SCRATCH1` when A's crawl reads it | non-zero with bits 55:54 = B's port-up mask at B's own publication (bit `54 + q` for the internal link on B's port q), bit 20, and **no** bit 39, 41 or 22 | established (the claim test); inferred (that this is what real hardware shows at that moment) |
| 4 | the link | `LLP_STAT` low nibble 9 on A's port p and B's port q by the time of each node's first publication (progress 22 in `main`); otherwise the claim test stalls 300 s | established (code); unknown (when hardware trains the link) |
| 5 | B's chip word `0x1_0000_0000` | part `0x4363`, bit 56 = q | established (S1 row 1) |
| 6 | B as a barrier participant | B must run its half of the tree and global barriers, since its word has no bit 22 at A's read | established |

## S2: a stand-in NL4 router on a linked port

A's port `p` goes to router port `R` (1 to 8). The Altix 350 guide's table puts the module's NUMAlink 1 on the router, which
this page reads as NI1, `p = 1`, first route nibble 2, A's registers at `0x1_5000_2000` (the page of the guide's other
reading, "port 0", is the open item in [numalink4-router-open.md](../../../questions/numalink4-router-open.md); the
numbers change with `p` only). The route to the router is `p + 1`. Addresses are router register numbers (the `ADDRESS`
value after masking; the image writes them with bit 38 set, which the mask drops). Port block of router port n:
`0x800_0000 + (n - 1) * 0x100_0000`. Same storage and logging rules as S1.

**Expected sequence (established):** chip word reads; counter reads at both ends; `SCRATCH0` read, lock, a second `SCRATCH0` read (both must give 0, or the PROM treats the router as advertised and releases the lock), first-time set-up writes, three system-controller requests, `SCRATCH0` write, unlock; insert (reads); then, if the router reports a
link on other ports, a chip word read through each; then the distribution writes.

| # | Router register | Accessed by | Answer | Log | An unexpected access means |
|---|---|---|---|---|---|
| 1 | register 0 (`STATUS_REV_ID`), read; the request carries `ADDRESS` `0x1_0000_0000`, so the router must decode that as register 0 (**inferred**: the image has no other read for it) | `0xffa46a50` (also 1, 2 or 4 more reads) and `0xffa67220` | part `0x239` in 27:12 (established as required); `INPORT` bits 43:40 = R (established: the PROM stores it as the router's port the link lands on); bit 0 = 1 (the `force1` field; the PROM does not test it: stand-in choice); revision, manufacturer: stand-in choice; `POSITION` 47:44: **chooses the router's kind** (established as code, `0xffa67220`: bits 45:44 read `10` make a meta router, bit 45 clear a repeater router, bits 47:46 and 44 set the level; see [inputs of the table writer](../../../devices/router_nl4/global-config.md#inputs-of-the-table-writer)). `0xf` gives an ordinary router (flag halfword 0, **inferred** as the intended stand-in value: whether the numbering then accepts it was not traced); 0 gives a repeater at level 3, six translation writes in row 9. Bits 15 (`floc`) and 4 of the same flag halfword are set later by the numbering (`0xffa547e0`: a level-2 router in a three-level topology; `0xffa49fc0`: a loop through routers), so a one- or two-router stand-in sees them 0 (inferred); `LOCAL_POK` 57: 1 (stand-in choice); error flags 56:48: 0; link-up flags 39:32: see the next paragraph | every read | a read of any other register before this one: the crawl order changed |
| 2 | port counters `R base + 0x18a0` | link-quality check (`0xffa66fb0`: bits 15:0 and 47:16) | constant (0); a rise of more than 50 fails the step | each read | none |
| 3 | `SCRATCH0` `0x1000`, read | `0xffa668b0` | 0 first (established: non-zero means "already advertised": the PROM then neither programs nor sets the router's mark) | each read | a non-zero first read: the router is treated as advertised by someone else |
| 4 | lock: `SCRATCH3_ALIAS` `0x1038` read, `SCRATCH3` `0x1030` write 0 | `0xffa9a6f0` (to `0xffa0ad80`), `0xffa9a750` | read returns bit 0 clear when free; the write of 0 frees it. The PROM only tests bit 0 of the read (`0xffa0ad80` returns on a read with bit 0 clear, else re-reads until its deadline) and writes only 0 to `0x1030`, so plain storage and a test-and-set alias (**inferred** from the name) cannot be told apart by it. Seen in an emulator run with plain storage: five reads of `0x1038`, each followed by a write of 0 | each access | a read with bit 0 set: the lock is held; the PROM retries for up to 10 s (`nl4r_config_global`) and a held lock at `cache_advert` makes it re-read `SCRATCH0` every 10 ms |
| 5 | set-up writes: `0x1001900` (`0x888888888`), `0x1010` (0), `0x1001938` (1), `0x20` read-modify-write (clear bits 20:16 and 12:8), per port `+0x18d0` and `+0x1840` read-modify-write, 40 credit registers (`0x2000010`, `0x2000030`, `0x2000050`, `0x2000070`, `0x2000090`, `0x20000b0`, `0x20000d0`, `0x20000f0`, `0x2000120`, `0x2000140`, each at `+0`, `+8`, `+0x10`, `+0x18`) `0x111111111`, ten age registers (`0x2000400`, `0x2000408`, `0x2000428`, `0x2000430`, `0x2000438`, `0x2000440`, `0x2000410`, `0x2000418`, `0x2000420`, `0x2000448`) `0x10101010` | `0xffa66460`, once, when `SCRATCH0` was 0 | accept; storage | every write | none |
| 6 | L1 mailbox `ASIC_TO_L1_STATUS` `0x30`, `ASIC_TO_L1_DATA` `0x38`, `L1_TO_ASIC_STATUS` `0x40`, `L1_TO_ASIC_DATA` `0x48` | the requests of `0xffa80dd0`, `0xffa80f90`, `0xffa81170` (module id, slot, slab) through the frame layer `0xffa82a10`; the word protocol is [below](#the-routers-l1-mailbox-s2-row-6) | **read, not unknown**: `0x30` bit 0 clear before each word the PROM writes to `0x38` (8 frame bytes, first byte in bits 7:0, `0x7e` fill); a reply is one word at a time, `0x40` bit 0 set with 8 bytes in `0x48`, and the PROM writes 0 to `0x40` after taking it. The requests, in the order the PROM sends them: `0x0003`, `0x000e`, `0x0013`, `0x000e` (an emulator run saw all four; the code gives `0x0003` in module id, `0x000e` inside its type switch, `0x0013` in slot, `0x000e` in slab). **Silence is not survivable:** no reply within 3 s of the node's RTC parks the boot processor | every access, in order, with data | a missing reply: the PROM polls `0x40` for 3 s (about 12,647 polls in an emulator run), then takes the die path (write `0x0001000100000000` to `0x1_2000_0000`, then the park). The three prints "cache_advert: sysctl_vec_moduleid_get failed" (and `slot_get`, `slab_get`) are the form of an *error reply* (status below 0), after which the PROM goes on; they are not the form of silence |
| 7 | `SCRATCH0` write | `0xffa668b0` | accept; the word is module id (31:0) \| slab << 32 \| slot << 42 \| `0x0400008000000000` (bits 58 and 39), plus bit 41 if `0xffaac160` is non-zero; if all three requests failed it is `0x04003c8fffffffff` (module id, slot and slab all read as all ones, so the module id fills bits 31:0 and the slab and slot fields are `0xf`; `0x04003e8fffffffff` with bit 41; derived from `0xffa668b0`) | the value | a value without bit 39: the code path changed |
| 8 | `GLOBAL_PARM0` `0x10` read; per port n = 1 to 8: write 1 to `+0x2208`, read `+0x2200` | `0xffa67220` | read: any; `+0x2200` bit 0 clear | each access | a port whose `+0x2200` bit 0 is set is not crawled |
| 9 | tables per port: local `+0x0` (512 entries), global `+0x1000` (256), neighbour `+0x1800` (8) and then that port's six `nl4r_config_port` writes of row 10 (`0xffa67cb0` calls `0xffaab070` itself); multicast `0x4e80 + 8 * i`, `0x4f90`; `0x5000` and `0x6000` tables; `0x4000`; `PROTECTION_CONFIG` `0x1003018` read-modify-write; the multicast translation entries `0x4e00`, `0x4e08`, `0x4e10`, `0x4e18`, `0x4e40` (`0x80000000f1010f68`, `0x80000000f1030f69`, `0x80000000f1050f6a`, `0x80000000f1070f6b`, `0x80000000f1028787`) and `0x4f80` (`0x1f00`) from the table at `0xffbdfc90`, when bit 0 of the router entry's flag halfword is clear (when it is set, only `0x4e00` = `0x80000000f1016a6a` and `0x4e08` = `0x80000000f1016b6b` from `0xffbdfcf0`); the fence routine `nl4r_fence_ports` (`0xffa69d20`, slot `0x1f0`: lock, read-modify-write of `0x1003018`, then, when bit 1 of its flag argument is set, of each port reset mask `0x1003020 + 8 * i` whose bit `i` is set in its mask argument; the emulator run saw all eight); then `SCRATCH0` bit 40 | `0xffa67cb0` (distribution, only for a router the PROM advertised itself); `0xffa69d20` | accept; storage with read-back (an entry is read back before it is written only in compare mode, that is when the `SCRATCH0` value the PROM saw has bit 40 set; a fresh router gets plain writes: [inputs](../../../devices/router_nl4/global-config.md#inputs-of-the-table-writer)). On a default boot the multicast destination entries are all `0x0f0f0000` (not valid), `0x4f90` is 0, `LB_DATELINE` (`0x4000`) is 0 and bits 30:22 of `0x1003018` are 0 (inferred for one or two routers: the multicast byte stores need the `RtrRoutes` variable, and the other two are set only by a loop through routers and by a three-level topology) | every write: address, value | **all eight ports are written whether or not they have a link** (the writer loops over the router's port records 1 to 8 with no link test; seen in an emulator run). `0x1003018` is read and written more than once (seen in an emulator run: `0x100`, then `0x101`; the code's two writers are the table writer, which keeps bits 21:8 and sets the nine bits 30:22, and the fence routine, which sets or clears a mask), the eight `0x1003020 + 8 * i` each read-modify-written twice |
| 10 | board-walk set-up: `0x2000`, `0x2010`, `0x2020`, `0x2050`, `0x2060`, `0x2030`, `0x1003100`, `0x1001908`, `0x1001900`, `0x2008`, `0x4f00` to `0x4f78`; per port `+0x2200`, `+0x2210`, `+0x2100`, `+0x18a0`, `+0x18a8`, `+0x2218` (the per-port six are also written during the distribution, row 9) | `nl4r_init_global`, `nl4r_config_global`, `nl4r_config_port` (the board walk, `main_three` side) | accept; storage | every write | none; when in the boot this runs is open |

**The link-up flags of register 0 decide how far the crawl goes.** The PROM crawls through every router port whose
link-up flag (bits 39:32) is set and whose error summary bit 0 is clear. The port the node itself is on is one of them in
hardware. Two options: (a) **minimal, a stand-in choice that deviates from the hardware:** report no link on any port, the
crawl ends at the router and nothing is forwarded; (b) **full:** report the link on R and forward a request whose route is
`p + 1`, `R` out of router port R back to A's port `p`, so that A reads its own chip word through the router (bit 56 = p)
and finds itself already in the table (dropped as the same chip). Option (b) is what hardware does and needs the router to
carry a request in both directions; the reply's `INPORT`, route and `TYPE` fields for a two-hop request are inferred, not read.

## The router's L1 mailbox (S2 row 6)

Read on 2026-11-21 in the same image (Ghidra decompiles, `ia64-linux-gnu-objdump` for the branch predicates and
constants). Nothing was run for this section. The requests of `cache_advert` go through the PROM's controller object in
"vector mode" (bit 5 of its flag word at `+0x50`, set by the `1` argument of `0xffa8f900`): the object does not use the
node's UART but four registers of the router's own register space, reached with vector requests on the router's route. An
emulator run of the stock PROM against a stub, 2026-11-21, agrees with every row below (it answered one frame and the PROM
accepted it).

| Register | PROM access | What the PROM does with it | Grade |
|---|---|---|---|
| `ASIC_TO_L1_STATUS` `0x30` | read before each word it sends | bit 0 set: sleep 100 us and read again, for at most 5,000,000 us per word; on expiry the rest of the frame is dropped without an error (`0xffa8d870`) | established (access, test, limits); the reading "bit 0 = busy" is inferred |
| `ASIC_TO_L1_DATA` `0x38` | write, 8 bytes per word | frame bytes, **first byte in bits 7:0**; when fewer than 8 remain the high bytes are `0x7e` (`0xffa8d720`) | established |
| `L1_TO_ASIC_STATUS` `0x40` | write 0 once at start (`0xffa8e290`); read to poll; write 0 after taking a word | bit 0 set: a word is waiting in `0x48`. No other bit is tested by the two routines that read it (`0xffa8daa0` byte reader, `0xffa8dff0` drain) | established (access, bit 0); the other bits are unknown |
| `L1_TO_ASIC_DATA` `0x48` | read, 8 bytes per word, only while `0x40` bit 0 is set | reply bytes, **first byte in bits 7:0**. The byte reader hands out one byte per call from the word it read and writes 0 to `0x40` after the eighth; the drain takes all 8 and writes 0 at once | established |

The register numbers come from the NL4 router's method slot `0x268` (`0xffa8ce60`): index `i` of the controller object's
16550-style register set maps to router offset `0x30 + 8 * (i xor 1)`, so index 0 (transmit data) is `0x38`, 1 (transmit
status) `0x30`, 2 (receive data) `0x48` and 3 (receive status) `0x40`. The SHub class has its own slot `0x268` (`0xffa942d0`, not read here; its UART path is the
`0x8000000ffed40000` register set of [l1-requests.md](l1-requests.md#the-link-start-before-the-first-request)). Established for the router.

The bytes are the frames of [l1-requests.md](l1-requests.md#the-requests-in-order) unchanged: flag `0x7e`, header byte, big-endian
address word, request code, argument count, arguments, then the FCS-16 (reflected `0x8408`, residue `0xf0b8`), with
`0x7e` and `0x7d` escaped. The first frame of the emulator run, `7e 05 0f ff f0 06 00 03 69 27 7e` (request `0x0003`, no
arguments, so no count byte), went out as two words: `7e 05 0f ff f0 06 00 03`, then `69 27 7e` and five `0x7e` fill bytes. The
header `0x05` is the open handle `5 + slice`; the reply the PROM accepts has header `0x20 | 5 + slice` (`0x25` for slice 0) and
any frame with residue `0xf0b8` completes the slot ([l1-requests.md](l1-requests.md), "Silence"). The status word, the
argument count and the argument tags are then checked by `0xffa82270` ("tag and count mismatch" gives -32 and -33).
The reply layout of each request is in the sysco repository's `software/firmware/l1/sn2-prom-link-1.62.1.md`.

**Timing and silence (established).** A request first waits for the transmitter (up to 50 tries 500 us apart, then -26),
sends, and then waits for a complete reply for 3,000,000 us of the node's own RTC (`0xffa82c10` to `0xffa82a10` to
`0xffa82730`; the timer `0xffa0da70` is the local `0x81_101c_0000` count times the period field of `0x81_1006_0280` bits
13:4, `field * 10 + 10` (nanoseconds, inferred), divided by 1000). On expiry the status is -24 and the die routine `0xffad2cb0` runs before any
caller sees it; for the local node and the boot processor it parks the processor ([l1-requests.md](l1-requests.md), "Silence"). The
router's requests are all addressed to the local controller object (the route is the router's), so a silent mailbox parks the
boot processor at the first request; error *replies* are the case the three "failed" prints describe.

**The L1's end (inferred).** The sysco repository records that for the NL4 router and TIO families the L1 reaches the chip
through the scan chain: `NL4R_SysComInt` calls `SysComJTagReadReady`, which calls `JTAG_UART_read`; `JTAG_UART_write` and
`JTAG_UART_read` access the test data registers `WR_SYSCOM` and `RD_SYSCOM`, packing bytes with bit-reversal masks. That
`RD_SYSCOM` returns what the PROM wrote to `ASIC_TO_L1_DATA` and `WR_SYSCOM` fills `L1_TO_ASIC_DATA` is by name only; the
bit reversal is the L1's own packing and is not visible in the PROM's words; the status handshake the L1 performs (when it
clears `0x30` bit 0 and sets `0x40` bit 0) was not read. **Unknown:** the meaning of the other bits of `0x30` and `0x40`,
whether the hardware queues a second word before the first is taken, and the real latency between a request and its reply.

**For a stand-in (approximation, not a reading).** Keep `0x30` reading 0, answer a frame with header `0x20 | 5 + slice`, status
0 and the values the request needs (rack and bay, type, slab, slot), cut into 8-byte words with `0x7e` fill; present one word
at a time (`0x40` = 1 and the word in `0x48` until the PROM writes 0 to `0x40`, then the next word or `0x40` = 0).

## Barriers, master election and the stages after distribution with a second node

Read for this contract in the same image (Ghidra decompile, plus the `ia64-linux-gnu-objdump` listing for every call
site and constant; Ghidra misses some direct `br.call` sites, so callers come from the listing). Nothing was run.
Reviewed (see the end of the page). Grades as above; **stand-in choice** marks a value the stand-in invents.

### Where the barriers run

The wrappers are `0xffa44710` (global scope: candidate array at `[[0x1000070] + 0x20]`, master index at record `+4`) and
`0xffa44950` (partition scope: array at `+0x40`, master index at record `+8`, partition byte at entry 0 `+0x35`). Both
do nothing but a local-slice barrier unless the slice passes the gate `0xffa0ff30`. On the first slice they read
`cpu_bits` bit 4 (`0x81_5003_1550`, local): clear, they run the tree barrier `0xffa42a30`; it returning 0 ends the
barrier; it returning non-zero sets bit 4 and the global barrier `0xffa43d20` runs in the same call; with bit 4 already
set every later call skips the tree and runs the global barrier. Established.

| Call site | Wrapper | Place |
|---|---|---|
| `0xffa1b14c` | global | `main_two`, after discovery, the master elections (`0xffa445b0`, `0xffa44660`) and `0xffa44ba0` |
| `0xffa1b1ac` | global | `main_two`, after "Distributing routing tables", before the NASID install |
| `0xffad73dc` | global | `main_three`, after the interrupt-enable scrub `0xffae3160` |
| `0xffad742c`, `0xffad750c`, `0xffad757c`, `0xffad75bc`, `0xffad766c` | partition | `main_three`, around progress 0x23 to 0x26 |

No call site tests the return value (checked at the three global sites): a failed barrier is not fatal. Established.

### Candidate arrays and the election (`0xffa42640`)

The record's entries are a list sorted by the geoid compare `0xffa11ab0` (it is a three-way compare, not a hash: insertion
`0xffa450e0` walks the list, a result of 0 means "same chip, add nothing", a negative result stops the walk and the new
entry goes in front). The key, in order: the 32-bit geoid word with bits 15:8 masked (rack in 31:16, bay in 7:0, built
by `0xffa7d010` from `SCRATCH2` bits 34:26 and 25:20), then a 4-bit field (`SCRATCH2` bits 38:35), then a signed 4-bit
field (`SCRATCH2` bits 18:16), then the geoid kind (2 for a node found through `SCRATCH2`). The partition byte
(`SCRATCH2` 15:8) is not in the key. Established, including the mapping of the two 4-bit fields (`0xffa8d120` outputs
and the arguments of the geoid builder `0xffa11f10` at `0xffa5dfdc`: bits 47:44 and 43:40 of the geoid) and the
constant `99` in bits 15:8 that the compare masks.

The array holds, in list order, every entry of class 1 (a node) whose flag word has neither `0x10000` (claimed, or dead)
nor `0x800000` (`SCRATCH1` bit 22, finished discovery); the partition array also needs the same partition byte. The
local entry's position goes into array word 0, the count into word 1. Highest score wins, the earlier list entry wins a
tie; the winner's index is stored (record `+4` global, `+8` partition), `cpu_bits` bit 0 or 1 is set when the winner is
the local entry, and "Global master is %I" / "Partition master is %I" is printed. Established.

`0xffa44ba0` (called between the elections and the first barrier) ORs the published switches of every non-claimed node:
flag `0x100000` (`SCRATCH1` bit 20), `0x200000` (bit 18) and `0x400000` (bit 19) become `cpu_bits` bits 13, 14 and 15
(the walk includes A's own entry, so bit 13 is always set),
and it then calls the router routine `0xffa5c900` ("nl4r_mip_clear failed" on a negative result). Established. This
is the reader the bit table lists as "not found"; `cpu_bits` bits 14 and 15 are tested in `main_three` at `0xffad76a0` and
`0xffad7736` (what the branches do was not read).

### The tree barrier (`0xffa42a30`, 240 s)

A is at position `pos` of `count`; its children are positions `2 * pos + 1` and `2 * pos + 2`, its parent `(pos - 1) / 2`.
The sense `s` is `~(local 0x1_5003_1570 & 1) & 1` read at entry. The two child flag registers are `0x1_5003_13f0` (first
child) and `0x1_5003_13d0` (second child), table at `0xffbdfbb0`. Established.

| # | Access | When | Value |
|---|---|---|---|
| 1 | read the child's `0x1_5003_1580` (vector read, child's route) | before waiting for each real child | baseline for the progress check |
| 2 | poll A's own `0x1_5003_13f0`, then `0x1_5003_13d0`, bit 0 until it equals `s` | per real child, in that order | the child writes it, below |
| 3 | write A's own `0x1_5003_13f0` / `13d0` = `s` | for a child position at or beyond `count` (no child) | local store |
| 4 | root (`pos` 0): write A's own `0x1_5003_1570` = `s` | after both children | local store |
| 5 | non-root: vector write the parent's `0x1_5003_13f0` (`pos` 1) or `0x1_5003_13d0` (`pos` 2) = `s`, then read the parent's `0x1_5003_1580` as the baseline | after its own children | the arrival message |
| 6 | non-root: poll A's own `0x1_5003_1570` bit 0 until it equals `s` | after row 5 | the parent writes it, row 7 |
| 7 | vector write each real child's `0x1_5003_1570` = `s` | last (release) | root after row 4, others after row 6 |

While it polls, each pass increments A's own `0x1_5003_1580` (`0xffa46980`), sleeps 1 ms and may print a spinner
character (`cpu_bits` bit 1 set only). Every 240 s of RTC time (`240000000` microseconds) it re-reads the awaited node's
`0x1_5003_1580`: unchanged since the previous read prints "tree barrier at %I timed out" (the awaited node's geoid) and
returns -1; changed, it keeps waiting with the new value as baseline. A failed vector access prints
"tree_barrier: vector 0x%lx/%d from %I failed: %s" and returns the error. Entry prints "Tree barrier " and success
"Tree barrier passed." (both through the debug-level print `0xffa17770`; the two failure texts always print). A
stand-in whose `0x1_5003_1580` keeps changing therefore stalls the barrier for ever; a constant one stalls it 240 s.
Established.

### The global barrier (`0xffa43d20`; no timeout)

The mailbox is bit 17 (`0x20000`) of each node's own `SCRATCH1` `0x1_101d_0080`, read and written through the chip
method slots `0x168` and `0x170`. It prints "Global barrier " and, at the end, "Global barrier passed." (debug level).
Established.

- **Local node is the elected master (index 0):** read own word, write it back with bit 17 set; for every other entry
  that is a node, is not flagged `0x810000` and (partition scope) has the partition byte: wait for its bit 17 **set**;
  then read own word again and write it back with bit 17 clear; wait for every such entry's bit 17 **clear**. The
  partition scope tests the byte only when the byte passed in is non-zero: the wrapper passes the local entry's
  partition byte, so with a local byte of 0 (A's `SCRATCH2` `0x0410006c` has bits 15:8 clear) the global-barrier
  fallback waits on every unflagged node whatever its partition byte; the arrays of the tree barrier still filter.
- **Another node is the master:** wait for the master's bit 17 set; read own word, write it with bit 17 set; wait for the
  master's bit 17 clear; write own word with bit 17 clear.
- **The wait (`0xffa43670`):** prints "> Waiting for master|slave set|clear: index %d, %I, nasid %d", then loops: read
  the awaited node's `SCRATCH1` (a negative result prints "> Global barrier failed node %d" and returns -1); exit when
  bit 17 matches; **the console interrupt check (`0xffa1f340`, a ^C, prints "^C") also ends the wait as success**; a read
  with bit 41 set (and `0x81_5003_1560` bit 8 clear) disables a slave (flag `0x1010000`) and ends the wait, and fails
  against a master; bit 39 does the same with flag `0x10000`. Otherwise it prints "waiting for node, %I, at global
  barrier..." once and ".." on every 100th pass, and sleeps 100 ms (100 us under the simulator signature). There is no
  deadline and no progress-counter test.

### What A needs, per model

| # | Model | What the stand-in must do | Grade |
|---|---|---|---|
| 1 | **S1, claimed stand-in** (flag `0x10000`) | Nothing for any barrier or election: it is in no candidate array, so every wrapper call sees `count` 1, writes only A's own `0x1_5003_13f0`, `13d0` and `1570`, reads no remote register and prints "Tree barrier passed." (`count` 1 and `pos` 0 checked in the loop bounds). A is the global and the partition master. A's NASID is 0 only if A sorts first (see row 5). | established (code); inferred (the whole-run consequence) |
| 2 | **Self-published, bit 22 set** | `SCRATCH1` constant with bits 55:54 non-zero (claim skipped), bit 22 set, bits 15:0 equal to A's object count (2 for two nodes), bits 39 and 41 clear: A's wait loop is satisfied by the count, and flag `0x800000` keeps the stand-in out of every candidate array, the election, and both barriers. A passive stand-in suffices for the barriers. Because the flags are decoded once at the crawl (`0xffa5e0b0`; bit 22 to `0x800000`), the first read of the word during the crawl must already carry bit 22. Keep bit 40 clear: the wait loop (`0xffa47870`) tests only entries whose NASID-final byte is clear, and distribution (`0xffa5b5d0`) gives such an unclaimed entry the number -1 and skips it; with bit 40 set the entry is numbered like a claimed one and A's table writes (slot `0x1d8`) can reach it. With bit 40 clear A does not program the stand-in: its own tables and NASID are a **stand-in choice**. Stage 0x23 does not touch it (it needs flag `0x10000`), so no board record is built for it, and the board-walk driver (`0xffaa7190`, from `0xffaa7090`) prints "setup_hub_port: no connecting hub board! Node %d port %d" for each port and goes on (its callers ignore the result). | established (decode, filters, wait loop, distribution numbering, stage 0x23 condition); inferred (that nothing else reads it: the three `0x810000` sites are the only readers of the flag by constant, and no accessor call with index `0x18` was found, in a listing search that is not exhaustive) |
| 3 | **Self-published, bit 22 clear** | A passive stand-in cannot pass the tree barrier. As a candidate it needs a peer that writes A's `0x1_5003_13f0` (position 1) with the sense value and then A's `0x1_5003_1570` to release (the roles in the tree table); with a constant `0x1_5003_1580` A prints "tree barrier at %I timed out" after 240 s and falls back to the global barrier. There, if A is the master (it is, on a tie, when it sorts first), the stand-in's `SCRATCH1` must read with bit 17 **set** at the first read of the set wait and **clear** at the first read of the clear wait; bit 17 of A's own word is set when the first wait starts and cleared before the second, so "bit 17 equals A's bit 17" is the simplest rule, or "set on one read, then clear". If the stand-in is the master (its word has bit 21, or it sorts first on a score tie) the roles reverse and it must drive A's wait: no passive answer. | established |
| 4 | **S1, partition** | A stand-in with a different partition byte (`SCRATCH2` bits 15:8) is not in A's partition arrays (so not in the partition tree barrier); with the same byte a claimed stand-in is still excluded. A local partition byte of 0 turns the byte filter off in the global-barrier loops (see that section). | established |
| 5 | NASID order | `0xffa4d390` numbers type-1 entries in **list order** with 0, 2, 4, and so on (not in insertion order): A is NASID 0 only if its geoid compares lower than the stand-in's. With A's `SCRATCH2` `0x0410006c` (rack 1, bay 1) and the stand-in's `0x0420006c` (bay 2) it does. With no router in the table the fat-tree depth is 0 (debug-level prints "ftdepth = 0" and "nasid_nlocal_bits = 1", no `nasid_loop` message). | established (order, depth); the writer of A's own `SCRATCH2` low bits was not traced here |

The geoid compare treats the stand-in as the same chip as A when rack, bay, the two 4-bit fields and the kind all match.

### `main_three` and the stages that touch a claimed stand-in

Read at call level. For A at NASID 0 the NASID-change block of `main_three` is skipped (as on a lone node); all its barrier
calls are local with a claimed stand-in (row 1).

| # | Stage | Accessed by | What a claimed stand-in sees | Grade |
|---|---|---|---|---|
| 1 | Progress 0x23 walk `0xffa1a9e0`, then a partition barrier, then `0xffa1ac80` | `main_three` at `0xffad74fc`, `0xffad7510` | For each entry of class 1 or 3 in A's partition with flag `0x10000` set and the "NASID final" byte (`+0x5b` bit 0) clear: the latch `0xffa1a6d0` (below), then flag `0x4000000` set and a call of **class slot 5** (`0xffacc6e0`, the node set-up of the SHub page) on that entry. `0xffa1ac80` calls **class slot 6** (`0xffaccae0`) for entries with that flag. The class pointer is the entry's own `+0x50` (the 40-byte entry copy overlaps the saved-class slot, which is how the call reads it). So the claimed stand-in is the target of the remote node set-up; this settles that slot 5 has callers. The accesses of the two methods are in [the section below](#what-the-prom-does-to-a-claimed-remote-node-class-slots-5-and-6-and-the-board-walk). | established (conditions, targets); the bodies as graded there |
| 2 | Latch `0xffa1a6d0` | stage 1 | Read the stand-in's `SCRATCH1` (vector); if bit 56 is set stop; else take lock 17 (class slot `0xd8`, `0xffa0f1a0`), read the word again, write it with bit 56 set (vector write), release (slot `0xf0`, `0xffa0f650`). The lock acts on the stand-in's own registers: a vector read of `0x1_101d_0188` (bit 0 must read 0; polled for up to 1 s, then -9) takes a spin lock, the lock word `0x1_5003_1540` is read and written (bit 17 set to lock, cleared by the release, which repeats the spin lock; the wait for bit 17 to clear has no deadline, the third argument is 0) through the global window `0x9_5003_1540 \| nasid << 38`, and a vector write of 0 to `0x1_101d_0180` frees the spin lock. A plain-storage stand-in satisfies it; the global window must route by the NASID A assigned. | established |
| 3 | Interrupt scrub `0xffae3160`, called just before the first global barrier of `main_three` (`0xffad73cc`, then `0xffad73dc`) | `main_three` | Local to A. With a port up (A's own link mask, class slot `0x1b0`) it skips the "no NI ports are up" notice and runs the ICC underflow workaround: A's own `0x1_5002_1400 + 8 * k` (saved, written, restored), `0x1_2000_0100` (saved, `0x5f5e06`, restored), `0x1_2000_0180` (saved, count + 2, restored), 20 zero stores (`WrbWARCnt` default 20, at most 0x20) of 8 bytes at 128-byte strides ending at `0x4_0000_0000` in node `nasid ^ 0x400`'s uncached window (`0x8000_0030_0000_0000 + ((nasid ^ 0x400) << 38) + 0x4_0000_0000 - 128 * count`: for NASID 0 and 20 stores the first is at physical `0x1_0033_ffff_f600`, as seen in an emulator run), a 4 s and a 1 s wait, then `0xffa30b40(nasid, 5)` and `0xffa24810`. The stores go out of the first up NI port: before them the PROM saves and rewrites A's own `0x1_5002_1400 + 8 * ((address >> 45) & 0xf)` (entry 8 for NASID 0) with `0xf0f | port << 5 | port << 13` (port 0 or 1, the lowest up one) and restores it afterwards. Nothing is read back; the error clear that follows is the PROM's only reaction. | established (list, the routing entry, the port choice); unknown (what the neighbour does with the stores: a model that accepts and drops them is an approximation, and an emulator without a node behind the window gets a bus error) |
| 4 | Board walk `0xffaa03f0` (`0xffaa7090`, `0xffaf1350`, `0xffaeeb20`, `0xffaedff0`), after the progress 0x26 code, partition master only (`cpu_bits` bit 1) | `main_three` at `0xffad765c` | For each connection of A's HUB component it reads bytes `+5` and `+9` of the peer's board record and sets bit 3 of `+9` (a write) at `(peer nasid << 38) + 0x30_0000_0000 + offset`, so that memory must answer reads and writes. The record is built by A in stage 1 (slot 99) in the stand-in's RAM or, if it is memory-less, in A's RAM; details and the router branch in [the section below](#what-the-prom-does-to-a-claimed-remote-node-class-slots-5-and-6-and-the-board-walk). | established (reads, write, address, source of the record); unknown (the three closing routines) |
| 5 | Console and `Loading EFI` | `main_three` at `0xffad76ec` to `0xffad777c` | `0xffae77a0` reads only the RAM table of CPU ids at `[0x1000038] + 0x18` and `cr.lid`; no register access, so a stand-in without CPUs is not an input. | established |

### What the PROM does to a claimed remote node: class slots 5 and 6, and the board walk

Read in the same image (Ghidra decompile, objdump listing for the branch conditions). Slots 5 and 6 are sequences of
calls through the class method table of the entry's chip class (SHub 1: the table at `0xffbd7c18`); the entry copy is
the object (`obj`: the NASID A assigned is the halfword at `+0`, the vector route at `+0x18`, the class at `+0x20`).
Every method below reads its NASID and route from `obj`, so each register access reaches the stand-in either through
its global window (bit 63, `0x8_0000_0000`, `nasid << 38` and the offset, so `1_101d_0100` appears as
`0x8000_0009_101d_0100` with the NASID shifted in) or, when `obj`'s route is non-zero, through the vector engine (slots 45 and 46 and the latch). The
local-node rows of [prom-reset.md](../../../devices/shub/prom-reset.md#slot-5-after-the-permission-set-up-slot-by-slot)
therefore describe the stand-in's accesses too, with the stand-in's NASID in place of A's; this section lists where the
remote case differs. **Stub choice** marks a value the stand-in invents. Nothing was run.

**Slot 5 (`0xffacc6e0`), in order (established from the listing).** Print (A's console); slot 36; slot 95; slot 85;
slot 97; `0xffa788b0(nasid)`; when it returns 0 ("no memory"): `0xffa13190(index, 0x15, 1)` (sets flag `0x2000000` in A's
entry) and `0xffa0afd0(obj)`; slot 45 (read `SCRATCH1`); a negative result prints a message and stops here; else slot 46
(write it back with bits 57 and 40 set, whatever else it held); then slots 3, 81, 99 and 92 with the no-memory flag as
the fourth, third, third and third argument. **Slot 6 (`0xffaccae0`)**: `ffa129f0(index, 0x15)` (the same flag), then
slots 37, 96, 98, 4, 64, 82, 100, 86, 93 with it.

| # | Call | Accesses at the stand-in | What it needs back | Grade |
|---|---|---|---|---|
| 1 | slot 36 `0xffa96180` | `0xffa964e0(obj, 2, 50)` (the `SH_GC_SRC_CTRL` write of the SHub page), write 0 to `1_101c_0000` (`rtc`), slot 34 (`0xffa95c20`, the SHub page's store list), read `1_2000_0000` and `1_1006_0580` (`SHUB_ID`), write `1_2000_0000` OR-ed with `0x3f1` (`SHUB_ID` bits 31:28 below 3) or `0x3b03f7`, then `0xffa97960(nasid)`: read `SHUB_ID`, six permission writes (`1_1006_0000`, `0400`, `0180`, `0380`, `0480`, `0100`) | nothing tested. The mask in the permission writes comes from the node table of block A in A's RAM, so it depends on whether A has put the stand-in's NASID in it (not read) | established (accesses); unknown (mask value) |
| 2 | slot 95 `0xffa1ef70` to `0xffa1f430` | NASID differs from A's, so the remote branch: `0xffa8fb80` reads `SCRATCH2` `1_101d_0100` (the offset comes from slot 78) in the `0x8_0000_0000` form and writes it back with bits 41:39 set to 7; then `0xffa8f960` runs the node-object body `0xffa8b5d0` with `obj` as the node and the record in A's RAM. That body is the one in the SHub page's slot 95 table: the UART step is taken because bits 41:39 now read 7 (poll the line status at `0xf_fed4_0028 \| nasid << 38` until bit 6 is set, 100 ms limit, then the eight line-control writes), the lock on `1_5003_1540` bit 6 (slot 71 via `1_101d_0188` and `1_101d_0180`) and its release, the `SCRATCH2` read, clear bits 41:39, increment bits 49:42, write bit 63 clear, and the read-backs. Last, an L1 request `0x100b` goes out from A's own channel, not from the stand-in | `SCRATCH2` must read back what was written (bits 41:39 = 7); the UART line status must read with bit 6 set within 100 ms; `1_101d_0188` bit 0 clear | established (branch, accesses); inferred (that the UART steps are the SHub page's rows 3 and 4: same code, remote NASID; that the `0x100b` request is A's own, its argument being A's slice record) |
| 3 | slot 85 `0xffa23850` | `0xffa2bd60`, the two error lists, then `0xffa23a20(obj, local)`; per slice `i` whose bit `0x1a + i` is set in A's local `cpu_bits`: write `SH_LOCAL_INT0/1_CONFIG`, write `SH_INT_NODE_ID_CONFIG` `1_1000_0300` = A's NASID or `0x800` (the stand-in is not the local node), write the enables `0x7ef`; one read of `1_1001_0000` (`SH_EVENT_OCCURRED`) whose `& 0x7ef` selects error-list clears | storage; `SH_EVENT_OCCURRED` 0 skips the clears | established (same constants as the SHub page rows, remote NASID) |
| 4 | slot 97 `0xffa6a100` | with memory flag 0, on the stand-in's NASID and whatever the DIMM word holds: `0xffa733d0` (`1_0003_0000` read-modify-write, `1_0005_0000` write), `0xffa78100` (DIMM discovery `0xffa77bb0`, controller programming, DRAM initialisation commands), `0xffb94670`, `0xffb94680`, `0xffa6f000` (the test driver), `0xffa788b0` (read `SH_JNR_DIMM_CFG` `1_0001_0010`) and `0xffa7c6d0` while the debug-word bit 8 is clear; `0xffa782c0` and `0xffa73590` only if `0xffa788b0` is non-zero. A zero result (every bank byte's density bits 2:0 equal 7) is "no memory": `0xffa0afd0(obj)` sets bit 58 of the stand-in's `SCRATCH1` through slots 45 and 46 (vector). The DIMM word is the PROM's own output: discovery writes it from SPD answers, which it requests through the node's L1 channel (`0xffa7fcb0(nasid)`, a node record built from the entry, so by inference the stand-in's UART); no answer for a bank gives density 7 on the SHub page's evidence (local node) | the registers of the SHub page's slot 97 table and [memory-init.md](../../../devices/shub/memory-init.md) as plain storage at the stand-in's NASID, plus L1 replies over the stand-in's UART (no DIMM in any slot) or a tolerable timeout (its length not read) | established (order, test, no-memory path); inferred (the L1 channel is the stand-in's UART); unknown (remote behaviour of discovery, timeouts) |
| 5 | slots 45, 46 | vector read of `SCRATCH1` `1_101d_0080`, write back with bits 57 and 40 set (so the stand-in's word ends with at least bits 40, 56 (the latch) and 57 set, and bit 58 when memory-less) | the read result is not tested | established |
| 6 | slot 3 `0xffacbfa0` (memory present only) | `0xffac42d0(1, nasid, 0)` and the RAM table work in the stand-in's memory: reads `[0x8000_0030_0100_0070 \| nasid << 38]` and `[... 0100_0038]` (the pointer table at node offset `0x0100_0000`), writes a 40-byte copy of the entry, the heap arena (`0xffadd540`), copies A's words `0x1000040` and `0x1000078` into the same offsets of the stand-in, then `0xffafbca0` (the EFI-store checksum: 16 reads of 64 KiB from the stand-in's flash, `0xffa0fa00`) | real RAM behind node offset `0x0100_0000` and above, readable and writable, and a flash window; the checksum text only changes a message | established (accesses); inferred (that the flash is the stand-in's) |
| 7 | slot 81 `0xffa915f0` | memory present: record work in the stand-in's RAM (`[0x1000010]`, `0x188`) and `0xffa80720`; memory-less: `0xffa8f9c0(obj, local)` builds the record in A's RAM and a missing record prints a message (`0xffbb4978`) and returns | no register beyond rows 1 and 2 | established (shape); unknown (bodies) |
| 8 | slot 99 `0xffaacaf0` | memory present: `0xffaa0100(nasid)` allocates the `0xb0000`-byte hardware-configuration block from the stand-in's heap and lays it out (stores into the stand-in's RAM); then, always, the board builder `0xffa9fe80(obj, 0x11, flag)` (see the board record below) | see rows 6 and the board record | established |
| 9 | slot 92 `0xffaadae0` | `0xffa99870(obj, 2)`: read `1_5003_1550` of the stand-in (global window) and test bit 2. Set: no I/O set-up. Clear: slot 91 (`0xffaad720`, the I/O initialisation of the SHub page: long, includes II-block accesses at the stand-in) and, if it returns 0 or less, a locked read-modify-write setting bit 2 (`1_101d_0208` poll, `1_101d_0200` release). Then `0xffb91760` | **stub choice:** bit 2 of `1_5003_1550` reads 1, which skips the whole I/O set-up | established (test); unknown (slot 91 body, as on the SHub page) |
| 10 | slot 6: slots 37, 96, 64, 82, 100, 86 | nothing: each method is a 16-byte return | | established |
| 11 | slot 6: slot 98 `0xffa6a310` and slot 4 `0xffacc680` | only when the flag is 0 (memory present). Slot 98 reads the stand-in's RAM pointer (`0x8000_0030_0100_0038 \| nasid << 38`, then `+0x188`) and stores a zero word. Slot 4 is the EFI-store synchronisation `0xffaf72e0`: for every present NASID it reads `SH_JNR_DIMM_CFG` and the checksum word at `[[0x0100_0070] + 0x80]` of that node's RAM, votes, and, if A's checksum loses, copies flash blocks from the winner (`0xffaf6640`) | RAM and flash as in row 6 | established (accesses); unknown (the copy's reads and writes) |
| 12 | slot 6: slot 93 `0xffaadc10` | `0xffab38b0(nasid)`: on the slice gate, `0xffa99870(obj, 2)` again; clear: prints "Discovering local I/O on nasid %d" and runs `0xffab15c0`: the crossbar initialisation `0xffab0560` on the stand-in's window (`0x8000_0008_0000_0000 \| nasid << 38`; it compares the node's link with the crossbar master and prints "early return from xbow_init" if they differ, else walks the widget ports), then a 4-byte identification read at that window and a continue only for part `0xd000` or `0xd100`; any other value prints "New Widget %x connected to HUB." and stops. Set (row 9's stub choice): returns at once | | established (gate, first read); unknown (the rest of the I/O walk) |

**The peer's board record (established for the source and the condition).** Slot 99's board builder `0xffa9fe80` goes
to `0xffaa1ea0(obj, 0x11, flag)`, which allocates the board (`0xffaed240` through `0xffaa4c60`), writes type `0x11`, the
node's geoid words from `obj` and the chip method `+0x138` (slot 39, a global read of `SHUB_ID` bits 31:28), builds the
HUB component (`0xffaa1310`: the board's EEPROM text through an L1 request to the node, `0xffaeccd0`; a failure prints
"init_klcfg_hub: Could not retrieve EEPROM info on nasid %d" and continues; the two port-connection slots are set to
`0xffff`), the error structures (`0xffaa4f50`, `0xffaa4560`) and the rest. So the record exists only because A built it
in stage 0x23. Where it lives: `0xffaa4c60` asks `0xffa99b80(entry)` whether the node is memory-less: that reads the
stand-in's `SCRATCH1` (vector) and answers memory-less if bit 58 is set, or if bit 39 is set with bit 57 clear; any other
word means it has memory. A memory-bearing node's board is allocated in its own RAM (`0xffaa33a0`), a memory-less
node's in a memory-bearing node of the same partition (A, `0xffaa3960`; "WARNING: Unable to find host for memless node %d!"
if none). The connections that tie A's HUB component to the stand-in's board are written by `0xffaa7190` (called from
`0xffaa7090`, before the walk) through `setup_hub_port` (`0xffaa5c30`), which needs the peer's board: it finds it by
NASID and geoid and otherwise prints "setup_hub_port: no connecting hub board!". It runs on the partition master only.

**The board walk (`0xffaa03f0`; partition master only, after the slice gate).** `0xffaf1350` ("hwcfg_node_probe") finds
A's own type `0x11` board in A's block and breadth-first walks the connections of each HUB component (two entries per
HUB, a 12-byte record each: peer NASID halfword, flag byte, a 32-bit board offset, port halfword). For each connected
board it forms `(offset & 0x7fffffcfffffffff) | ((nasid << 38) + 0x30_0000_0000)` (a physical address in the peer's, or
its host's, memory), reads byte `+5` (type: high nibble `0x10` node board, `0x30` router board, other values print
"Unknown brd type"), reads byte `+9` and sets its bit 3 (the visited mark) **with a write**, and, for a node board, reads
the board's components (`0xffaa93c0`) and queues it; for a router board it also runs the router chip's class slots
`0x330` and `0x338` (`nl4r_config_global` and a per-port method) and follows the router's ports. Afterwards it checks
that the master HUB's NASID equals A's ("node_probe: Error - Master hub NASID == 0x%x not 0x%x") and runs
`0xffaeedf0`, `0xffaef420`, `0xffaefa20` (not read). The memory the walk reads and writes is the board memory above, so
a claimed stand-in needs no register access here beyond rows 1 to 9; a memory-less one adds nothing to its own side.
Grade: established (the reads, the write of `+9`, the address form, the source of the record); unknown (the three
closing routines and the router branch for a node-only configuration).

**What a stub must give for the two models (inferred as a summary of the rows; every value marked is a stub choice).**

| Model | Stub requirements |
|---|---|
| bit-22 stand-in (unclaimed) | None of this section runs (stage 0x23 needs flag `0x10000`). Keep bit 40 clear. The board walk prints "no connecting hub board" per port and goes on. |
| claimed S1 stand-in, memory-less | Plain storage for the registers in rows 1 to 5 and the SHub page's slot 97 tables at the stand-in's NASID (`SCRATCH1` and `SCRATCH2` read back what was written; the vector lock pair `1_101d_0188` reads 0 with bit 0 clear and `1_101d_0180` takes writes); UART line status `0xf_fed4_0028` reading bit 6 set; an L1 behind the UART that answers the SPD and EEPROM requests with "no DIMM" and an error (stub choice), or silence with the timeout lengths unread; `1_5003_1550` bit 2 set (stub choice) to skip I/O set-up; `1_5003_1540` bits 6 and 17 clear. A's RAM hosts the board. |
| claimed S1 stand-in with memory | The above, plus RAM and a flash window at the stand-in's NASID for rows 6, 7, 8 and 11, and real SPD answers. Use the memory-less model first. |

### The router routines: when they run

- `nl4r_init_global` (`0xffaaa840`) and `nl4r_config_port` (`0xffaab070`) are called inside the router table writer
  `0xffa67cb0` (call sites `0xffa68ffc` and `0xffa695ac`), which `0xffa5b5d0` calls through slot `0x1d8` for a router
  the PROM advertised itself. So they run in the distribution of `main_two`, not in the crawl. Established.
- `nl4r_config_global` (slot `0x330`, entry `0xffaaab10`) is called from the board walk `0xffaedff0` of the table above
  (once per router board in the configuration), and itself calls `nl4r_init_global` (`0xffaaac5c`). So it runs in
  `main_three` on the partition master, after the distribution. Established for the call chain.
- The crawl `0xffa47290` has no test of its own for a router port: for every entry it asks the class for its port count
  (slot `0x188`) and steps every port whose record byte `+3` has bit 0 set. For a node that bit comes from bits 55:54 of
  the word the node published; for an NL4 router from `0xffa67220` (link-up flag in register 0 bits 39:32 and bit 0 of
  the port's `+0x2200` clear, read in the listing at `0xffa674c0` to `0xffa67500`). A failed step is counted; the fourth
  failure prints "LLP link was up but could not talk to router." and fails the crawl (the caller waits 10 s and runs it
  once more). A set bit 11 of the debug word `0x81_5003_1560` skips the crawl with "*** Skipping NUMAlink discovery".
  Established.

## What an emulator run of the stock PROM showed (2026-11-21)

An emulator run of the stock PROM against a stub built from this page (observation only: the stub's answers are choices,
not hardware) went past the rows above. Each item says what in the image confirms it.

- **The claimed stand-in is reached through its global window.** After distribution the PROM drives the stand-in with plain
  loads and stores at `0x88_0000_0000 + offset` (NASID 2 << 38, bit 35), not with vector requests; the run touched 239
  registers that are not rows here. They are the accesses of slots 5 and 6 listed in
  [the section above](#what-the-prom-does-to-a-claimed-remote-node-class-slots-5-and-6-and-the-board-walk): the `SCRATCH2`
  read-modify-write (`0x420006c`, bay 2, to `0x3800420006c`: bits 41:39 set to 7), the UART line-status polling at
  `0xf_fed4_0028 | nasid << 38` and its eight line-control writes, the lock words `0x1_101d_0180` and `0x1_101d_0188`, the
  error-clear lists (row 2), and the `SCRATCH1` words: `0x0140008000000000` (the claim's `0x0040008000000000` plus the latch
  bit 56), then `0x0740018000000000` (plus bits 57 and 40 from slots 45 and 46 and bit 58 from the memory-less path), which is
  the sequence this page derives. The flash probe at the stand-in's offsets `0x7ff800000` and `0x7ff810000` (a 2-byte write of `0xf0`, then four 8-byte
  reads at +0 to +0x18 of each) is **inferred** only (seen in an emulator run; the callers `0xffaceb40` and `0xffacef70` were not read).
- **The spin after memory initialisation is a receive wait, not a lock wait.** The run polled `0x1_5003_1540` of the stand-in
  about 8.4 million times from return address `0xffa0f300`, each read returning 0. That address is the second read in the lock
  acquire `0xffa0f1a0` (the first is at `0xffa0f240`): `0xffa0f1a0(nasid, bit, timeout)` reads the lock word through the
  global window, takes the spin lock `0x1_101d_0188`, reads the word again and, if the bit is clear, sets it; the release
  `0xffa0f650` clears it. Both are the PROM's software lock on that word; the UART methods take bit 6 of it around each UART access (`0xffa93cd0`,
  `0xffa93d80`, see [l1-requests.md](l1-requests.md#the-link-start-before-the-first-request)), and the loop takes and drops
  it around every poll of the receiver `0xffa87830` (the run's earlier acquisitions of the word used bits 17, the latch, and
  2; the log did not record the bit taken in the spin). Nobody has to write `0x1_5003_1540` or `0x1_5003_1550` for the loop to end, and on real hardware
  nothing on the peer's side would: the loop ends when a complete reply frame arrives on the stand-in's UART (the line status
  `0xf_fed4_0028` reading bit 0 set, the byte in `0xf_fed4_0000`; the stub answered `0x60`, transmitter empty and no data), which on
  hardware is the L1 of the stand-in's brick answering the request the PROM wrote there, or when 3,000,000 us of A's RTC have
  passed (`0xffa82730`). On expiry the die routine runs with the stand-in's NASID, so it writes the stand-in's
  `0x1_2000_0000` and waits 300 ms but does not park (the park needs the local node), and the request fails with -24. The
  requests on that channel at this point are most likely the sixteen `0x0006` DIMM reads of the remote memory discovery
  (inferred from the slot 97 row; the run's log does not name the request): 16 failures, about 3.3 s each, and then the
  node is memory-less (`SCRATCH1` bit 58). Why the run's timeout did not end the loop is a model question: the count comes
  from A's RTC and the period field above. Grades: established (the loop, the polled registers and the limit); inferred (which request).
- **`0x1_5003_13f0` writes.** A's own `0x1_5003_13f0` and `0x1_5003_13d0` are zeroed at `0xffa48510` to `0xffa48550` (documented
  in [prom-reset.md](../../../devices/shub/prom-reset.md)) and written again with the sense bit by `0xffa42dc0` once per tree
  barrier call on the first slice (the no-child case of the table in the barrier section, both words). The run logged
  only the `13f0` word, so "three writes" is the node set-up write plus the two barrier calls of the early boot (after
  discovery and after distribution). Established.
- **Interrupt scrub.** The 20 zero stores at physical `0x1_0033_ffff_f600` are the scrub's stores (row 3 of the table in the
  `main_three` section, now with the address formula and the routing-entry write). Without a node behind that window the model
  gets a bus error; the PROM routes them out of the up port.
- **The loop-back is not an artefact of the stub.** The claim writes `SCRATCH1` with bit `54 + q` (row 7), and row 3 needs
  `LLP_STAT` nibble 9 on port q for the claim at all. The crawl `0xffa47290` steps every port of every entry whose record bit
  is set; neither it nor the step `0xffa45780` tests the port an entry was reached on. So the PROM sends a chip-word read
  with the route `p + 1, q + 1` (out of A's port p, then out of the stand-in's port q). On a real two-node cable port q is
  the other end of the link to A's port p, so that packet comes back to A, which answers it as its own chip word, bit 56 the
  port it arrived on; the insert (`0xffa450e0`) finds the same geoid and adds nothing. Established (code); inferred
  (that the hardware forwards the second nibble and delivers it to A's vector engine, which is the hardware behaviour the
  S2 option (b) also assumes). A stand-in that wants the crawl to end at it must either leave port q down in its own
  `LLP_STAT` (then the claim does not happen) or loop the request back as the run did.

## Address bit 32 and the router registers the PROM reads before writing (SAL 5.04)

Read on 2026-11-22 in the same image (Ghidra decompiles of `0xffa0bd20`, `0xffa0c560`, `0xffa66460`, `0xffa67220`, `0xffa668b0`; the listing for the address tests). The names are the Linux v5.3 SHub 1 header's (`SH1_*_MMR_OFFSET` in `arch/ia64/include/asm/sn/addrs.h`, `SH_SHUB_ID` in `shub_mmr.h`).

**What bit 32 selects (established as code and as the Linux expectation).** Every SHub 1 register offset the PROM uses has bit 32 set (`0x1_xxxx_xxxx`). The two access routines test it in the argument address, route 0 only (`tbit` at `0xffa0bda6` in the read, `0xffa0c5e6` in the write): with bit 38 of the argument clear they form `0x8000_0008_0000_0000 | nasid << 38 | address` (bit 63 uncached, bit 35 the global MMR window, `0x8_0000_0000`) and

| Bit 38 of the argument | Bit 32 | Address issued |
|---|---|---|
| clear | set | the address as given: the SHub's own register block |
| clear | clear | the address plus `0x180_0000` (widget 1, offset `0x80_0000`): the small-window path |
| set | either | bit 38 cleared, nothing added (the form the PROM uses for router register numbers) |

Linux does the same for a remote SHub 1 register: `SH1_IS_BIG_WINDOW_ADDR(x)` is `x & BWIN_TOP` with `BWIN_TOP` = `0x1_0000_0000`; set goes straight through `GLOBAL_MMR_ADDR`, clear goes to `NODE_SWIN_BASE(n, 1) + 0x800000 + x`, and `0x180_0000` is `1 << 24` plus `0x80_0000`. For the local window the Linux offset is `0x80_0000_0000` (bit 39), for the global window `0x8_0000_0000` (bit 35). So, for the node: **bit 32 set means the register block of the SHub itself; clear means the small-window path through widget 1.** A stand-in must decode `0x1_xxxx_xxxx` as its registers.

With a non-zero route the same two routines send a vector request and mask the address with `0x7_ffff_fff8` (bits 34:3), so bit 32 reaches the remote chip unchanged inside the request's `ADDRESS` field and bit 38 is dropped ([vector request](../../../devices/router_nl4/node-access.md#shub-1-sal-504-the-vector-request-as-the-image-sends-it)). The neighbour must treat that address like a local offset. **For a router, the one access read here that carries bit 32 is the chip-word read** (`0xffa46a50` passes the constant `0x1_0000_0000` at `0xffa46b36`, the same for node and router); every other router address in the S2 tables is a register number below `0x1000_0000` with no bit 32. So the router must answer the `0x1_0000_0000` read with register 0 (`STATUS_REV_ID`, part `0x239`), by ignoring bit 32 or by decoding it: **inferred** (software expectation: the crawl requires part `0x239` from this read, `0xffa0f7e0`); the hardware decode is **unknown**.

**Router registers the PROM reads before it writes them, and what it needs (all reset values `unknown` in the register table; the PROM's dependence is graded here).** Router register numbers as in S2; each is a vector read on the router's route.

| Register | Read at | What the PROM does with the value | Value it relies on | Grade |
|---|---|---|---|---|
| `SCRATCH0` `0x1000` | `0xffa668b0` (twice, around the lock) | non-zero means "already advertised": no set-up, no mark | 0 until the PROM writes it | established (test); inferred (reset 0) |
| `SCRATCH3_ALIAS` `0x1038` | `0xffa9a6f0` | lock: bit 0 clear means free | bit 0 clear at reset | established (test); inferred (reset) |
| `GLOBAL_PARM1` `0x20` | `0xffa66460`, once, when `SCRATCH0` was 0 | read-modify-write clearing bits 20:16 and 12:8 | none (other bits preserved) | established; any reset works |
| port `+0x18d0`, `+0x1840` (ports 1 to 8) | `0xffa66460` | read-modify-write: low 6 bits of each byte of `+0x18d0` cleared and bit 0 set, bit 29 of `+0x1840` set | none (other bits preserved) | established; any reset works |
| `GLOBAL_PARM0` `0x10` | `0xffa67220` (insert) | bit `16 + n` of the value becomes bit 5 of port n's record; that bit adds `0x1` to the flow-register write of the node's port set-up (row 11 of S1) | bits 23:16 read 0 unless a dateline is meant | established (use); inferred (reset 0) |
| port `+0x2200` | `0xffa67220`, after writing 1 to `+0x2208` | link flag set when chip-word bit `32 + n - 1` is set **and** bit 0 here is clear | bit 0 clear after the clear write (so `+0x2208` must clear it) | established (test); the clear semantics of `+0x2208` inferred from the name |
| `PROTECTION_CONFIG` `0x1003018` | `0xffa67220` (only when `SCRATCH0` bit 40 is set), the table writer `0xffa67cb0` and the fence routine `0xffa69d20` (read-modify-write) | bits 21:8 become the router's id when bit 40 is set (else `0xffff`); bit `n` of the low byte zero sets port n's record bit 1 (fenced) | bits 7:0 and 21:8 zero at reset on a fresh router | established (use); inferred (reset 0) |
| `PORT_RST_MASK` `0x1003020 + 8 * i` | `0xffa69d20` | read-modify-write | none (preserved) | established |
| `RTC_SOURCE` `0x1001900` | `nl4r_config_global` (`0xffaaab20`), after `nl4r_init_global` or the first-time set-up wrote it | read-modify-write of the select nibbles | what the earlier write left: `0x888888888` after first-time set-up | established |
| port counters `+0x18a0` | `0xffa66fb0` (link-quality check) | a rise of more than 50 between reads fails the step | constant | established |
| L1 mailbox `0x30` bit 0, `0x40` bit 0 | S2 row 6 | busy and receive-ready tests | bit 0 of `0x30` clear when idle; bit 0 of `0x40` clear when empty | established (tests) |

A router model therefore needs: `SCRATCH0` 0, lock free, `GLOBAL_PARM0` bits 23:16 zero, `PROTECTION_CONFIG` zero, port `+0x2200` bit 0 clear, and plain storage for every other register it writes; it does not need any other reset value. The reset values themselves stay **unknown** until a capture or the router's own documentation settles them (route: the router's register description in a published SGI router guide, or a read of a router at power-up with the owner's approval).

## Unknown, and the route that would settle it

- What reply types 4 and 5 are, and whether a route error gives one of them: the image only groups them with link errors
  ([the vector request](../../../devices/router_nl4/node-access.md#shub-1-sal-504-the-vector-request-as-the-image-sends-it));
  route: the SHub 2 image's decoder of the vector status, or a hardware capture (needs the owner's approval).
- The router's decode of address bit 32 (the PROM sends a node's and a router's chip-word read with the same address, [below](#address-bit-32-and-the-router-registers-the-prom-reads-before-writing-sal-504)). The L1 mailbox framing and the PROM's wait per request are now read ([the
  mailbox section](#the-routers-l1-mailbox-s2-row-6)); still unknown are the other bits of the mailbox status registers and
  the hardware's queueing; route: the L1's scan-chain side (`JTAG_UART_read`, `JTAG_UART_write`) in the sysco repository, or a capture.
- When the internal link between the two nodes of a brick is trained, and which NI port of each node it uses; route: a capture of `LLP_STAT` on both nodes around the memory probe, or the training sequence in SAL_A and PAL (not traced).
- What the bit-19 flag of `SCRATCH2` does (`0xffaac0a0` sets a RAM record byte); route: that byte's readers.
- What `0` and `4` select in a node's direction tables, and the meaning of `POSITION`: route: the node table-write
  routines (`0xffa5e880`, `0xffa5e510`) read against the SHub 1 header names, and the Linux `sn_hwperf` heap.
- What slots 5 and 6 leave unread on a claimed stand-in ([the section above](#what-the-prom-does-to-a-claimed-remote-node-class-slots-5-and-6-and-the-board-walk)):
  the remote behaviour of DIMM discovery over the stand-in's UART and the timeout when the L1 does not answer (`0xffa7fcb0`,
  `0xffa77bb0`, `0xffa7bd60`), the memory-present bodies of slots 3, 81 and 99, slot 91's I/O set-up, the EFI-store copy
  `0xffaf6640`, the builders `0xffaa1a10`, `0xffaa1930`, `0xffaa5450`, `0xffaa2760` and the three closing routines of the
  board walk (`0xffaeedf0`, `0xffaef420`, `0xffaefa20`), and the mask `0xffa97960` writes for the stand-in's NASID. Route:
  read those bodies with the stand-in's NASID; a run with the stand-in under the interpreter would show model behaviour only,
  never hardware.
- What the neighbour does with the ICC underflow workaround's 20 stores at `0xffae3160` (they do leave A's NI port when a
  port is up, row 3 of the `main_three` table), and what the `cpu_bits` 14 and 15 branches at `0xffad76a0` and `0xffad7736` do.
- What `0xffa5c900` ("nl4r_mip_clear") accesses when the table has a router.
- The meaning of `SCRATCH1` bits 16 and 46 to 53, and of the debug-word fields behind bits 18 and 19: no reader found. Bits 18 to
  20 are read (OR-ed over the non-claimed nodes into `cpu_bits` 14, 15 and 13 by `0xffa44ba0`); what those `cpu_bits` do is open.

## Review

Independent review of chips `08c8955`. The reviewer wrote none of it. Method: `shub1snprom.bin` (sha256 `51ccf9ad...`) imported with this repository's IA-64 loader and decompiled in Ghidra, every cited function re-read with its listing, the method tables read as raw words from the image, and the SHub 2 image (`shub2snprom.bin`) imported for the counterpart table. Nothing was run.

**Confirmed.** `SH_SCRATCH1` producer `0xffa46530` and decoder `0xffa5e0b0`, every row of the bit table (including the version bytes 5 and 4 at `0xffba20e8`, the debug-word bits 4:3 and 8, and bit 3 of `0x81_5003_1550`); `shub_port_status` and its per-port helper `0xffa5cf40` (`LLP_ERR` bit 27 write-back, `LLP_STAT` nibble 9, the four `+0x1040` registers with 128 tries, the simulator skip); the part numbers `0x4363`, `0x3017`, `0x239` and `0x4422` and their method tables (slots `0x168`, `0x170`, `0x1a0`, `0x1a8`, `0x1c0`, `0x1c8`, `0x1d8`); that `0xffa5b5d0` is the distribution routine; the SHub 2 counterpart sizes of the crawl, wait, route and distribution routines; the vector read and write (all register addresses, the `PARMS` constants, `(nibble - 1) * 2`, the 1024-pass polls, the retry waits, the result-code and message map); the claim (`0xffa5d2a0`), the wait loop's skip test, the turn counts (`(out - in)` modulo the port count; node-end 0 for a router and 4 otherwise); the router lock, `cache_advert`, the set-up tables and values, register 0 field uses, the insert, and the table writer's addresses.

**Corrected in this review.**
- The claim does two writes before the port reads (`0x1_5003_1550`, `0x1_5003_1540`), not three.
- A word with bit 41 or bit 39 set lets the claim go on whatever its other bits (55:54 clear); the page said "only".
- The claim reads `LLP_ERR` on both of the stand-in's ports, not only on the linked one.
- `cache_advert` reads `SCRATCH0` a second time after taking the lock; a non-zero second read is treated as advertised.
- The router table writer `0xffa67cb0` calls `nl4r_config_port` itself for each port, so those six writes belong to the distribution row; the page and global-config.md called them board-walk only.
- The error pre-check writes 0 to `0x1_1007_1000` when its bit 3 is set; it does not clear the one bit.
- The vector pair is matched to SHub 2 by constants, not by size (the SHub 2 forms are larger).
- Register 0 bit 0 is not tested by the PROM; it is a stand-in choice, not a requirement.

**Contract rows the experiment should read with care.**
- S1 row 7 and the claim: the final `SCRATCH1` value depends on the stand-in's *other* port reading down; if it reads 9 both mask bits are set (as the page says in row 3).
- S1 row 10: with the stand-in's word bit 40 clear (the S1 case) the table writes are plain writes with no read-back; "read back what was written" is the stand-in's storage behaviour, not something the PROM checks in that pass.
- S1 row 11: "A has no router" means no entry with part `0x239` in the configuration (a count in `0xffa5b5d0`), which holds for S1 and not for S2.
- S2 row 6 (L1 mailbox): "reads of 0 are the cheapest answer" is a guess; the page elsewhere says the wait per request is unread. Treat it as a stand-in choice until `0xffa80dd0` is read.
- `0x1_1007_1000`, `0x1_1001_0008` and `0x1_1001_0088` are written only when the error summary reads non-zero; a stand-in that always returns 0 never sees them.

**Not checked.** The call sites of the router set-up routines `nl4r_init_global` and `nl4r_config_global` (so whether they run during discovery), the crawl routine `0xffa47290`'s own port test for router ports, the global barrier and `main_three`, the geoid hashing at `0xffa11ab0`, and the claim that A's `SCRATCH2` is `0x0410006c` (taken from another page). The `0x1_5003_03a0` flow-register mask values were read only from the decompile.

Independent review of chips `2ff39a3` (the barrier section of this page and the `boot-sequence.md` changes). The reviewer wrote none of it. Method: `shub1snprom.bin` (sha256 `51ccf9ad...`) imported with the SN2 PROM profile of the IA-64 Ghidra module and decompiled whole; the decompiles and the `ia64-linux-gnu-objdump` listing came from an earlier run over the same image (hash checked), and the slot 5 and 6 bodies, which that run had no functions for, from a second Ghidra run seeded at their entry addresses. Every cited address re-read; call sites searched in the listing. Nothing was run.

**Confirmed.** The wrappers `0xffa44710` and `0xffa44950` (record `+4` or `+8`, array `+0x20` or `+0x40`, partition byte at entry 0 `+0x35`, the gate `0xffa0ff30`, `cpu_bits` bit 4) and all eight call sites; that no call site tests the result; the tree barrier `0xffa42a30` row by row (sense from `0x1_5003_1570`, the two child flags `0x1_5003_13f0` and `0x1_5003_13d0` from the table at `0xffbdfbb0`, the release writes, the 240 s test on the awaited node's `0x1_5003_1580`, the two failure texts); the global barrier `0xffa43d20` and its wait `0xffa43670` (bit 17, no deadline, the `^C` exit, bits 41 and 39); the election `0xffa42640` (class 1, mask `0x810000`, scores 2 and 1, tie to the earlier list entry, the index stored as an array index so that index 0 is the local entry); the geoid compare `0xffa11ab0` as a three-way compare with the key order stated, and the insertion `0xffa450e0`; the flag decode (bit 22 to `0x800000`) and the three `0x810000` sites; the stage 0x23 walk, the latch `0xffa1a6d0` and the lock routines `0xffa0f1a0` and `0xffa0f650`; `0xffa44ba0` and its mapping to `cpu_bits` 13 to 15; the slot addresses 5 and 6 and their table (`0xffbd7c18`, entries `0xffbd7c40` and `0xffbd7c48`).

**Corrected in this review.**
- The interrupt scrub `0xffae3160` runs just before the first global barrier of `main_three`, not after it.
- The master branch of the global barrier re-reads its own word before the clear write; and the partition scope filters by partition byte only when the byte is non-zero, which A's `0x0410006c` (bits 15:8 clear) makes a no-op in the global-barrier fallback.
- A self-published stand-in with bit 22 is skipped by distribution only while its bit 40 is clear; with bit 40 set it is numbered and can be programmed. The wait loop also tests only entries whose bit 40 is clear.
- When A is not first in list order the tree barrier roles swap (A writes the neighbour's flag and waits for its own `1570`); the boot-sequence text had only the A-root case.
- The mapping of the two 4-bit geoid fields is established, not inferred.
- The board walk reads bytes `+5` and `+9` and writes bit 3 of `+9`; it did not read "two bytes".
- The latch's lock wait has no deadline.

**The bit-22 claim.** It holds. Flag `0x800000` is set in the decode whatever the other bits; the election and both global-barrier loops skip entries with `0x810000`; the tree barrier walks only the election's array; the distribution and stage 0x23 skip the entry. The listing search for other readers (the `0x810000` constant, the flag accessor with index `0x18`, bit 23 tests near the flags offset) found none, but it is not exhaustive. The earlier statement it overturns ("no passive stand-in satisfies that") was about the bit-22-clear case and stays true for that case.

**Not checked.** The bodies listed under "What slots 5 and 6 leave unread"; the `main_two` position of the elections relative to distribution (only the call order around `0xffa1b14c` was read); the nesting of `main_three` calls between `0xffad7436` and `0xffad766c` beyond the barrier and stage calls.

Independent review of chips `792d8f5` (the 2026-11-21 amendments: the stub-run fold-in, the router mailbox section and the rows they touch). The reviewer wrote none of it. Method: `shub1snprom.bin` (sha256 `51ccf9ad...`) imported with the SN2 PROM profile of the IA-64 Ghidra module, every cited routine decompiled, `ia64-linux-gnu-objdump` for call sites and return addresses, and the data tables read as raw words from the image. The emulator-run observations themselves (counts, logged values) were not re-run and are taken from the commit as reported.

**Confirmed.** The error-clear list `0xffbd8e18` (70 entries, terminated by a zero address; `NI0_LLP_ERR` `0x1_5000_0048` and `NI1_LLP_ERR` `0x1_5000_2048`, both value 0) and the 24-entry list `0xffbd93e0`; the writer `0xffae3f50` (the return address `0xffae4050` is the call to its store helper) and the two call sites `0xffa2389c` and `0xffa238bc` in slot 85 (`0xffa23850`) with the lists they load; the table-value rule of `0xffa5e880` (the entry is the route table's nibble, `VALID` for entry 0, a nibble other than `0xf` or the node's own entry in the local tables, for a nibble other than `0xf` only in the global tables; memory, I/O and processor tables take `nibble | nibble << 8`, so the node-end turn count 4 gives `0x0404`; the override tables are written 0) and the node-end count of `0xffa5e510` (0 for a router, else 4); the two multicast tables (`0xffbdfc90`: six entries `0x4e00`, `0x4e08`, `0x4e10`, `0x4e18`, `0x4e40`, `0x4f80` with the values in row 9; `0xffbdfcf0`: `0x4e00`, `0x4e08`) and their selection by bit 0 of the router record's flag halfword in `0xffa67cb0`; that the table writer loops over all eight port records with no link test (the only per-port test is record byte `+0x2b` bit 5, which builds a mask); the method slot numbers (`0x1d8` writer, `0x1f0` fence, `0x268` mailbox register map, from the descriptors in the table at `0xffbd8318`); the mailbox register map of `0xffa8ce60` (`(index xor 1) * 8 + 0x30`: 0 gives `0x38`, 1 `0x30`, 2 `0x48`, 3 `0x40`, with bit 38 set); the transmit routine `0xffa8d870` (reads `0x30`, sleeps 100 us while bit 0 is set, gives up the rest of the frame after 5,000,000 us) and `0xffa8d720` (eight bytes per word, first byte in bits 7:0, `0x7e` fill); the byte reader `0xffa8daa0` (index starts at 7 so the first byte is bits 7:0; writes 0 to `0x40` after the eighth) and the drain `0xffa8dff0`; the start-up write of 0 to `0x40` (`0xffa8e290`); the request wrapper `0xffa82c10` (50 transmitter tries 500 us apart then -26; 3,000,000 us wait; -24 calls the die routine `0xffad2cb0`) and the timer `0xffa0da70` (count times the period field, divided by 1000, microseconds); the die routine's write of `0x1_2000_0000`, the 300 ms wait and the park only when the processor is local (`0xffa9fc70`); the lock acquire `0xffa0f1a0` (word `0x1_5003_1540` through the global window, spin lock `0x1_101d_0188`, second read, return addresses `0xffa0f240` and `0xffa0f300`); the router lock reads `0x1038` and writes 0 to `0x1030` (`0xffa9a6f0`, `0xffa9a750`) with the 10 s limit in the fence and table writer; the crawl `0xffa47290` and step `0xffa45780` have no test of the port a node was reached on beyond record byte `+3` bit 0.

**Corrected in this review.**
- The derived `SCRATCH0` word when all three router requests fail was `0x0400044fffffffff`. `0xffa668b0` ORs the all-ones module id, slab `0xf` at bit 32 and slot `0xf` at bit 42 into `0x0400008000000000`: the word is `0x04003c8fffffffff` (`0x04003e8fffffffff` with bit 41). The old value contained no bit 39 and so contradicted the row's own "bits 58 and 39".
- `nl4r_fence_ports` does not touch all eight port masks unconditionally: it touches `0x1003018` when bit 0 of its flag argument is set, and a mask `0x1003020 + 8 * i` only when bit 1 is set and bit `i` of its mask argument is set (the emulator run's mask was evidently all ones).

**Not checked.** The emulator-run counts and logged values; the order and codes of the four mailbox requests (`0x0003`, `0x000e`, `0x0013`, `0x000e`); the `-2` result of the receiver `0xffa87830` and its use of the lock around each poll (the call to the lock acquire was not found in the listing's first calls of that routine); the interrupt scrub's processor-table entry; the flash probe callers; whether the insert method slot `0x1c8` clears record bit 0 for the arrival port (so "the crawl does not test the arrival port" is established for the two routines named only, and the hardware behaviour stays inferred, as the page says).
