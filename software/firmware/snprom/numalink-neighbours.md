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
`ia64-linux-gnu-objdump` listing for the branch tests and constants. Nothing was run, no hardware was read. Not
independently reviewed.

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
| `LLP_ERR` `0x1_5000_0048 + p * 0x2000` | bit 27 clear (the PROM writes it back clear and re-reads if set; set again means "down, no message"); bytes 0 and 1 constant | established |
| `0x1_5000_1040 + p * 0x2000 + 16 * i`, i = 0 to 3 | bits 22:16 non-zero (value `0x10000`: **stand-in choice**; the PROM tries 128 times per register, then fails the port; skipped when CPU ID register 2 is `0xaeeeeeee8badbeef`) | established |
| `LLP_RESET_EN` `0x1_5000_0010 + p * 0x2000`, `LLP_CONFIG` `+0x20`, `LLP_CHAN_MODE` `+0x18`, `LLP_TEST_CTL` `+0x28`, `LLP_RESET` `+0x08`, the flow registers `0x1_5003_03a0` to `0x1_5003_0400` | storage; `LLP_RESET_EN` resets to 1 (inferred from the header's init macro) | established (the accesses) |

A's other port must read as "down" (nibble not 9): the PROM then prints "shub_port_status: vector ... failed" for it,
which is expected, and during distribution retries a link reset on it for up to about 700 us.

## S1: a stand-in second SHub 1 node, one linked port

A is node 0 with its port `p` (0 = NI0, 1 = NI1) wired to the stand-in's port `q`. The route to the stand-in is the single
nibble `p + 1`. Rules: every register not listed is plain 64-bit storage (reads return the last write, 0 before) and the
first touch of each is logged; every request is logged with route, address and, for a write, data. Offsets are the
stand-in's own node-relative offsets (the request's `ADDRESS` carries bit 32, so the `0x1_` bias is part of it).

**Expected sequence (established, in order):** chip word reads; the link-quality re-reads; claim (read, three writes, port
reads on both of the stand-in's ports, a write); the `SCRATCH2` read; the insert (no further access); "Discovery
results"; route calculation (no access); distribution writes; `SH_SHUB_ID` read-modify-write; nothing more was read for
the PROM's stages after "Distributing routing tables". With the stand-in claimed, the wait loop skips it and the tree
barrier does not include it (inferred, see boot-sequence).

| # | Stand-in register | Accessed by | Answer | Log | An unexpected access means |
|---|---|---|---|---|---|
| 1 | chip word `0x1_0000_0000`, read | `0xffa46a50`: first, then 1, 2 or 4 more (debug-word bits 1:0 = 0, 2, 3; the value 1 skips them), retried once on error | bits 27:12 `0x4363` (established: the only value that selects the SHub method table); bits 31:28 the same revision A's own word has (stand-in choice); bits 42:32 the stand-in's NASID (read only if its `SCRATCH1` bit 40 is set; 0 until the PROM writes `SH_SHUB_ID`, stand-in choice); **bit 56 = q** (established as the field read; that it is the port is inferred); everything else 0 | every read; count | a read with a route of two or more nibbles: the crawl went through the stand-in, so a port flag leaked from the stand-in's `LLP_STAT` |
| 2 | `LLP_ERR` `0x1_5000_0048 + q * 0x2000`, read | link-quality check; claim | bit 27 clear; bytes 0 and 1 constant (0): the PROM fails the step if a counter grows by more than 50 between its reads | each read | a write to it: the PROM cleared bit 27, which means a read returned it set |
| 3 | `LLP_STAT` `0x1_5000_0000 + k * 0x2000`, k = 0, 1, read | claim (`shub_port_status` against the stand-in) | port q: low nibble 9; the other port: not 9 | each read | the other port read as 9 would set both mask bits |
| 4 | `0x1_5000_1040 + q * 0x2000 + 16 * i`, i = 0 to 3, read | same | bits 22:16 non-zero | each read | more than 128 reads of one register: the value is wrong |
| 5 | `SCRATCH1` `0x1_101d_0080`, read | claim; the wait loop only for an entry that was not claimed | **0** on the first read (established: 0 or only bits 41 or 39 lets the claim go on; non-zero otherwise stalls the claim 300 s and then forces bit 41; bits 55:54 non-zero makes the PROM skip the claim entirely, which is the "already prepared" model, not S1) | each read | a read that returns bits 55:54 set before any write: the claim was skipped and the stand-in is not programmed |
| 6 | `0x1_5003_1550`, `0x1_5003_1540`, write | claim | accept; expected data 0 | each write | none |
| 7 | `SCRATCH1`, write | claim | accept; expected value `0x0040008000000000` for q = 0 or `0x0080008000000000` for q = 1 (bit 39, plus bit `54 + q`: only port q is up) | the write | a value with bit 41 only: the claim timed out |
| 8 | `SCRATCH2` `0x1_101d_0100`, read | `0xffa8d120`, from `shub_discover` | low byte `0x6c`; bits 34:26 rack, 25:20 bay, 15:8 partition; **must differ from A's** (A's is `0x0410006c` for rack 1 bay 1; use `0x0420006c`, bay 2, the same partition byte; stand-in choice) | the read | a read failure prints "shub_discover: sysctl_get_pushed_data failed", and a stand-in that returns A's value is dropped as the same chip |
| 9 | `0x1_5003_1580`, read | only the wait loop and the barrier, neither of which includes a claimed stand-in | storage | each read | a read means the stand-in was waited for: its flags lack `0x10000` |
| 10 | NI tables: local `0x1_5002_2000 + k * 0x1000 + 8 * i` (i < 128), global `+0x400` (16), override `+0x480`; memory `0x1_5002_4000`, `+0x400`, `+0x480`; I/O `0x1_5002_0000`, `+0x400`, `+0x480`; processor `0x1_5002_1000`, `+0x400`, `+0x480`; k = 0, 1 | `0xffa5e880` (distribution), vector writes; read-back first when the entry's NASID is final | accept; read back what was written | every write: address, value | writes to NI tables with a valid bit (63) in an entry other than 0 and A's and the stand-in's own: a route to a third node |
| 11 | `0x1_5003_03a0 + k * 0x200` (read-modify-write, OR `0x100`, or `0x101` when the port record's bit 5 is set), `0x1_5003_0400 + k * 0x200` (`(v & ~0xff00) | 0xc000` only when A has no router), flow registers `0x1_5003_03c0`, `03d0`, `03e0`, `03f0` (read-modify-write, mask clears) | distribution; `0xffa5d850` | storage with read-back | each access | none |
| 12 | `LLP_CONFIG` `0x1_5000_0020 + k * 0x2000` (bits 9:0 set to 400), `LLP_CHAN_MODE` `+0x18` (read, bit 0), `LLP_TEST_CTL` `+0x28` (read; bits 41:40 written), `LLP_RESET` `+0x08` (write 1 when the port reads down) | `0xffa5d850` | storage | each access | `LLP_RESET` writes on port q: the PROM saw q down |
| 13 | `0x1_2000_0000`, write `0x0001000100000000`; `0x1_5003_1550` read-modify-write clearing bits 29:26; 300 ms wait on A's side | `0xffa9fc70` | accept | each access | none |
| 14 | `SH_SHUB_ID` `0x1_1006_0580`, read then write | `0xffa95a30` | read: whatever A's reads; the PROM writes back with NASID bits 42:32 = the stand-in's new NASID (2 by the defaults, inferred) and two size fields (bits 45:44 and 52:48, values not decoded) | read and write | a NASID other than 2 means the defaults changed |

Expected table values (**inferred**, from the route programmer): the stand-in's local table entry 0 (A, NASID 0) carries
`VALID | 4` on its port q (a node neighbour at the far end gives 4, a router 0); entries with no route carry `0xf`; the
stand-in's own entry (index 2) is valid with `0xf`. The vector route for each write is the nibble `p + 1` alone, so `VEC_ROUTE`
reads `0xf00000000`.

**What S1 does not establish.** The global barrier `0xffa43d20`, the first jump to RAM and `main_three` for two nodes (the
console arbitration, the NASID install on the neighbour, I/O discovery) were not read for more than one node; the PROM
may touch more of the stand-in after "Distributing routing tables". A stand-in that publishes its own word first
(`SCRATCH1` with bits 55:54, 21, 20 and the version bytes) is the other model: the PROM then does not claim or program it,
it may be elected master, and the tree barrier waits for that node's own PROM to write A's `0x1_5003_13f0` (240 s, then
"tree barrier ... timed out" and the global barrier); no passive stand-in satisfies that.

## S2: a stand-in NL4 router on a linked port

A's port `p` goes to router port `R` (1 to 8). The Altix 350 guide's table puts the module's NUMAlink 1 on the router, which
this page reads as NI1, `p = 1`, first route nibble 2, A's registers at `0x1_5000_2000` (the page of the guide's other
reading, "port 0", is the open item in [numalink4-router-open.md](../../../questions/numalink4-router-open.md); the
numbers change with `p` only). The route to the router is `p + 1`. Addresses are router register numbers (the `ADDRESS`
value after masking; the image writes them with bit 38 set, which the mask drops). Port block of router port n:
`0x800_0000 + (n - 1) * 0x100_0000`. Same storage and logging rules as S1.

**Expected sequence (established):** chip word reads; counter reads at both ends; `SCRATCH0` read, lock, first-time
set-up writes, three system-controller requests, `SCRATCH0` write, unlock; insert (reads); then, if the router reports a
link on other ports, a chip word read through each; then the distribution writes.

| # | Router register | Accessed by | Answer | Log | An unexpected access means |
|---|---|---|---|---|---|
| 1 | register 0 (`STATUS_REV_ID`), read; the request carries `ADDRESS` `0x1_0000_0000`, so the router must decode that as register 0 (**inferred**: the image has no other read for it) | `0xffa46a50` (also 1, 2 or 4 more reads) and `0xffa67220` | part `0x239` in 27:12 (established as required); `INPORT` bits 43:40 = R (established: the PROM stores it as the router's port the link lands on); bit 0 = 1; revision, manufacturer: stand-in choice; `POSITION` 47:44: 0 (the image tests them inverted; effect unknown); `LOCAL_POK` 57: 1 (stand-in choice); error flags 56:48: 0; link-up flags 39:32: see the next paragraph | every read | a read of any other register before this one: the crawl order changed |
| 2 | port counters `R base + 0x18a0` | link-quality check (`0xffa66fb0`: bits 15:0 and 47:16) | constant (0); a rise of more than 50 fails the step | each read | none |
| 3 | `SCRATCH0` `0x1000`, read | `0xffa668b0` | 0 first (established: non-zero means "already advertised": the PROM then neither programs nor sets the router's mark) | each read | a non-zero first read: the router is treated as advertised by someone else |
| 4 | lock: `SCRATCH3_ALIAS` `0x1038` read, `SCRATCH3` `0x1030` write 0 | `0xffa9a6f0`, `0xffa9a750` | read returns bit 0 clear when free (a test-and-set model sets bit 0 on a read; **inferred**); the write of 0 frees it | each access | a read with bit 0 set: the lock is held; the PROM retries for up to 10 s (`nl4r_config_global`) and a held lock at `cache_advert` makes it re-read `SCRATCH0` every 10 ms |
| 5 | set-up writes: `0x1001900` (`0x888888888`), `0x1010` (0), `0x1001938` (1), `0x20` read-modify-write (clear bits 20:16 and 12:8), per port `+0x18d0` and `+0x1840` read-modify-write, 40 credit registers (`0x2000010`, `0x2000030`, `0x2000050`, `0x2000070`, `0x2000090`, `0x20000b0`, `0x20000d0`, `0x20000f0`, `0x2000120`, `0x2000140`, each at `+0`, `+8`, `+0x10`, `+0x18`) `0x111111111`, ten age registers (`0x2000400`, `0x2000408`, `0x2000428`, `0x2000430`, `0x2000438`, `0x2000440`, `0x2000410`, `0x2000418`, `0x2000420`, `0x2000448`) `0x10101010` | `0xffa66460`, once, when `SCRATCH0` was 0 | accept; storage | every write | none |
| 6 | L1 mailbox `ASIC_TO_L1_STATUS` `0x30`, `ASIC_TO_L1_DATA` `0x38`, `L1_TO_ASIC_STATUS` `0x40`, `L1_TO_ASIC_DATA` `0x48` | the three requests of `0xffa80dd0`, `0xffa80f90`, `0xffa81170` (module id, slot, slab) | **unknown**: the framing was not read. Reads of 0 (nothing to receive) are the cheapest answer; the PROM's wait per request was not read, so the cost is unknown | every access, in order, with data: the first accesses give the framing | a refused or very slow reply: the three prints "cache_advert: sysctl_vec_moduleid_get failed" (and `slot_get`, `slab_get`) are the failure form and the PROM goes on |
| 7 | `SCRATCH0` write | `0xffa668b0` | accept; the word is module id (31:0) \| slab << 32 \| slot << 42 \| `0x0400008000000000` (bits 58 and 39), plus bit 41 if `0xffaac160` is non-zero; if all three requests failed it is `0x0400044fffffffff` (derived) | the value | a value without bit 39: the code path changed |
| 8 | `GLOBAL_PARM0` `0x10` read; per port n = 1 to 8: write 1 to `+0x2208`, read `+0x2200` | `0xffa67220` | read: any; `+0x2200` bit 0 clear | each access | a port whose `+0x2200` bit 0 is set is not crawled |
| 9 | tables per port: local `+0x0` (512 entries), global `+0x1000` (256), neighbour `+0x1800` (8); multicast `0x4e80 + 8 * i`, `0x4f90`; `0x5000` and `0x6000` tables; `0x4000`; `PROTECTION_CONFIG` `0x1003018` read-modify-write; then `SCRATCH0` bit 40 | `0xffa67cb0` (distribution, only for a router the PROM advertised itself) | accept; storage with read-back | every write: address, value | writes only to ports with a link |
| 10 | board-walk set-up: `0x2000`, `0x2010`, `0x2020`, `0x2050`, `0x2060`, `0x2030`, `0x1003100`, `0x1001908`, `0x1001900`, `0x2008`, `0x4f00` to `0x4f78`; per port `+0x2200`, `+0x2210`, `+0x2100`, `+0x18a0`, `+0x18a8`, `+0x2218` | `nl4r_init_global`, `nl4r_config_global`, `nl4r_config_port` (the board walk, `main_three` side) | accept; storage | every write | none; when in the boot this runs is open |

**The link-up flags of register 0 decide how far the crawl goes.** The PROM crawls through every router port whose
link-up flag (bits 39:32) is set and whose error summary bit 0 is clear. The port the node itself is on is one of them in
hardware. Two options: (a) **minimal, a stand-in choice that deviates from the hardware:** report no link on any port, the
crawl ends at the router and nothing is forwarded; (b) **full:** report the link on R and forward a request whose route is
`p + 1`, `R` out of router port R back to A's port `p`, so that A reads its own chip word through the router (bit 56 = p)
and finds itself already in the table (dropped as the same chip). Option (b) is what hardware does and needs the router to
carry a request in both directions; the reply's `INPORT`, route and `TYPE` fields for a two-hop request are inferred, not read.

## Unknown, and the route that would settle it

- What reply types 4 and 5 are, and whether a route error gives one of them: the image only groups them with link errors
  ([the vector request](../../../devices/router_nl4/node-access.md#shub-1-sal-504-the-vector-request-as-the-image-sends-it));
  route: the SHub 2 image's decoder of the vector status, or a hardware capture (needs the owner's approval).
- The router's decode of address bit 32, the L1 mailbox framing and the PROM's wait per L1 request: route: the
  `sysctl_vec_*` request builders (`0xffa8f900` and its callers) and the sysco repository's controller side.
- What `0` and `4` select in a node's direction tables, and the meaning of `POSITION`: route: the node table-write
  routines (`0xffa5e880`, `0xffa5e510`) read against the SHub 1 header names, and the Linux `sn_hwperf` heap.
- The PROM after "Distributing routing tables" with two nodes: the global barrier `0xffa43d20`, the NASID install on the
  neighbour and `main_three`. Route: read those routines; a run with the stand-in under the interpreter, which would show
  model behaviour only, never hardware.
- The meaning of `SCRATCH1` bits 16, 18 to 20, 46 to 53 and the debug-word fields behind bits 18 and 19: no reader found.
