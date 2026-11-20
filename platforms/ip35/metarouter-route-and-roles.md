# IP35 PROM on MetaRouter systems: route calculation, role values and size limits

Question. [nasid-numbering.md](nasid-numbering.md) and the router number walk stop at the numbers. Does the
shipped IP35 PROM 6.210 go on to accept a router graph with MetaRouters and repeat routers (route calculation,
the deadlock check, router table distribution, node-number distribution, the global barrier)? What does it do
with the router role values the L1 can set (`0xe` meta, `0xc` repeater), which published wirings does it accept
or reject and why, and what is the largest system it can number?

Answer in one paragraph. In a replay of the shipped code over tables built from the draft guide, every table from
160 to 512 processors is accepted except 192 as printed, which is accepted only after one cross-unit cable pair is made
same-unit, and every hub pair is delivered by the tables the PROM writes. The 48-processor table fails a paired-port
rule and the 3800-series 128-processor table fails the deadlock check. A MetaRouter graph needs exactly meta on routers
that take a rack-router cable and both role flags on repeaters, per the replay. The system tops out at 128 hubs (NASIDs
0 to 127, 512 processors) with 44 routers and three meta bits. Vector routes may reach 14 routers; the 512-processor
graph's longest is 7. [Why the two rejections happen](#why-the-pair-check-rejects-48-processors-and-the-deadlock-check-rejects-the-3800-128-processor-draft-table)
is its own section.

## Labels

E, I and U as in [AGENTS.md](../../AGENTS.md). **SE** is a software expectation: a replay in which the shipped code
was run unmodified (stubs listed below) over a table built from the draft cabling guide. An SE result says what the
code does with that table. It is not a hardware fact and not a claim about what real discovery would hand the PROM.
**E** is used only for what the code reads or the shipped binary contains. **I** is a reasoned step. **U** is not settled.

## What was read and run

| Item | Identity | Note |
|---|---|---|
| IP35 PROM 6.210 | unpacked segment `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`, load address 0x1fc00000 | Addresses below are image addresses. Read by disassembly (MIPS64 big-endian). |
| IRIX 6.5.22 IP35 kernel | `6.5.22/unix.IP35`, sha256 `87563dbc0cbc35c590348f9ec12863884fc857f6ae3a991b803aa2a71dca791c` | node-number table sizes only |
| IRIX 6.5.30 IP35 kernel | `6.5.30/unix.IP35`, sha256 `412a1aae553a348376bc30cacbaf65044de1745d30222f02ec5f88297dcb1dfa` | same |
| IRIX software (source not cited) | the IP27 boot PROM's number assignment, route assignment, deadlock check and global barrier, and the SN router, promcfg, address and architecture headers | read first, in my own words, for the shape of the algorithms of the earlier-generation PROM. Every fact below was re-read in the 6.210 binary or run; where the binary differs (entry limit) the binary is reported. |
| Cabling guide `108-xxxx-PR2` (preliminary) | Tables 2-12 to 2-31 | cable rows, parsed by script for 2-19 to 2-31 |
| `007-4311-002` | system overview | largest configuration: 512 processors, one to sixteen racks |

[Replay script](replay/metarouter_replay.py), Unicorn 2.1, MIPS64 big-endian. Stubs: console output recorded;
the environment lookup (0x1fc697ec) returns "unset"; the local node-number read (0x1fc6b5d0) returns 0; the vector
write (0x1fc5ce88) is recorded and the vector read (0x1fc5cf3c) returns 0; the two timeout setters (0x1fc52800,
0x1fc527dc) do nothing; the master's own hub-register stores (0x1fc5d044, 0x1fc5d074) and loads of the
master's hub table (0x1fc5d03c, 0x1fc5d06c) are skipped; the route cache base (0x1fc530a8 to 0x1fc530b0) is
moved from window 0x96 to 0xa8. Table layout: entry stride 0x400 from the table header, object at +0x20, type
byte at +0x20, number halfword at +0x22, flag halfword at +0x26, router port records from +0x40 (16 bytes: neighbour
index, 1-based far-end port, flag byte), router local table words from object +0xa4 (128) and global words from
+0x2a4 (16), hub local table words from +0x28 (128) and meta words from +0x228 (16). The earlier 256-processor
replay initialised router table word 0 and hub table word 127 to zero; both are all-ones in a real table. The
number walk results were not affected.

## Route calculation (E for code, SE for replay)

| Fact | Grade | Where |
|---|---|---|
| Master sequence after the NASID calculation (0x1fc5d63c, called at 0x1fc60e48): optional NASIDOffset (0x1fc60e6c to 0x1fc60f1c); region size (0x1fc60f08 tests each hub number against 64; "Note: Setting region size" at 0x1fc60fa4); route calculation 0x1fc5d450 (called at 0x1fc60fc8); router table distribution 0x1fc5cff0 (0x1fc60fd8); node-number distribution 0x1fc5cc60 (0x1fc610a8). | E | read |
| 0x1fc5d450 returns 0 at once when the router count (table header +0x14) is 0. It fails with "route_assign: promcfg entries more than allowed" when the entry count (header +0x08) is 257 or more (`slti 257` at 0x1fc5d4fc). IRIX software (source not cited) allows 512. | E | 0x1fc5d4e4 to 0x1fc5d5d8 |
| Order: force-local marking (0x1fc23220), next-hop table (0x1fc22e70, per source node), table fill (0x1fc22bdc, which calls the fill 0x1fc20e8c), deadlock check (0x1fc22a58). | E for the calls; I for the next-hop internals (not read in full) | 0x1fc5d558 to 0x1fc5d5c0 |
| Force-local: router i gets byte +0x24 := 1 when a neighbour router (type 2) that is **not** a MetaRouter (flag bit 0 clear) has a number whose bits above the low seven differ from i's. | E | 0x1fc23220 to 0x1fc2333c, compare at 0x1fc232d0 |
| Table fill: for hub S, destination D and the path's routers, hub S entry := (exit port minus entry port) mod 8 at the first router, stored in hub local word D & 0x7f when D >> 7 equals S's number >> 7, else meta word D >> 7. Router R_k entry on the entering link := the next router's turn, stored in local word D & 0x7f when D >> 7 equals R_k's number >> 7 or its force-local byte is set, else global word D >> 7. A field is a nibble (helper 0x1fc20e6c: nibble idx of a word); 0xf is unset; a second path that disagrees prints "Inconsistent turns". | E | 0x1fc20e8c to 0x1fc21240, 0x1fc212c4 |
| Hub table start words: all ones. A 20-router replay with the earlier harness gave 160 spurious "Inconsistent turns" lines because word 0 was zero. | SE | replay |
| Deadlock check wrapper 0x1fc22a58: for each router port that carries traffic (a per-port byte) calls 0x1fc20be4 (a recursive dependency search with a channel mask and depth); a nonzero result prints "dgraph_check failed!!!" (0x1fc22b9c) and the whole calculation fails; the search prints "Error: routing cycle detected!" (0x1fc20e60). Ports with no traffic print "router %d port %d has no traffic!" (0x1fc22abc) and pass. | E for the messages and control; I for what the search follows (the older source scans the written turn tables) | 0x1fc22a58 to 0x1fc22bd4 |
| Forwarding every hub pair through the written tables by the look-ahead rule (turn for the next element comes from the previous element's table at the entering link) delivers all pairs in every graph replayed; 0 non-minimal pairs on 224, 256 and 288 processors. | SE (replay) | script `sim` |

## Router table distribution (E)

0x1fc5cff0 prints "Distributing routing tables". Hub entries (type 1): for index 1 up, 128 local words written to
hub registers 0x681000 + 8 i by the vector write (0x1fc5d128 to 0x1fc5d148), then meta word 0 only, to 0x682000
(0x1fc5d150 to 0x1fc5d160). Router entries (type 2): vector route lookup from the master (0x1fc5d198), read router
register 0x100 (scratch 0), store bit 63 and the router number & 0x7f at bits 62:56 (0x1fc5d1f8 to 0x1fc5d218), read
register 0x10 and store the force-local byte at bit 12 and number >> 7 at bits 11:8 (0x1fc5d24c to 0x1fc5d288), write
128 local words for each of eight entering links at 0x200 + 8 D + link window (0x1fc5d2a8 to 0x1fc5d304; address
bits (p & 1) << 11 and (p & 0xe) << 15 for link p + 1 starting at 2), then 16 global words at 0x100 + 8 D'
(0x1fc5d33c to 0x1fc5d3b8). Replay: the 256-processor graph gives 1,154 writes per router (2 + 8 x 144) and 8,064
local plus 63 meta-0 writes for 63 hubs; every router prints `meta 0, floc 0`. The 512-processor graph made 67,159
writes (44 routers, 127 hubs) and returned 0.

**Consequence (E for the code, I for "cannot work").** Hub meta words 1 to 15 are never written, so a hub NASID of
128 or more has no route by table.

## Accepted and rejected wiring (SE, replay)

Each table through the number calculation (0x1fc5d63c), then the route calculation (0x1fc5d450). Hubs are one per
C-brick. Tables 2-19 to 2-31 are parsed from the guide's rows; the 32 to 128 processor "3600 series" graphs are
built from the topologies sheet's link lists. U38 routers that take a rack-router cable are given the meta flag, the
others both flags (the guide labels neither: I).

| Size, table | Hubs, routers | Max NASID | Longest route | Result |
|---|---|---|---|---|
| 32, 2-12 | 8, 2 | 7 | 2 | accept |
| 48, 2-13 | 12, 3 | | | **reject**: "corresponding ports must connect to the same module", ports 0x20 and 0x80 (the check at 0x1fc24468) |
| 64, 2-14 | 16, 4 | 15 | 2 | accept (fresh routers) |
| 80, 112 std, 112 alt | 20, 5 / 28, 7 / 28, 7 | 19 / 27 / 31 | 4 | accept; "type of 3 port 6 = 0x72, expected ftptype: 0x152" printed on the partial rack's port 6 |
| 96, 128 | 24, 6 / 32, 8 | 23 / 31 | 4 | accept |
| 128, 2-19 | 32, 12 | 31 | 5 | numbers assigned, **route calculation fails**: routing cycle |
| 160, 2-20 | 40, 14 | 63 | 6 | accept |
| 192, 2-21 | 48, 16 | | | **reject as printed**: "unsupported express link" (0x1fc23da8), 012R19p7-013R27p7 and 012R27p7-013R19p7 cross units. With those two cables same-unit: accept, 63, 5 |
| 224, 256 | 56, 18 / 64, 20 | 63 | 5 | accept |
| 288 | 72, 24 | 87 | 6 | accept |
| 320, 352, 384 | 80, 26 / 88, 30 / 96, 32 | 103 / 103 / 111 | 6 | accept |
| 416, 448, 480 | 104, 36 / 112, 38 / 120, 42 | 127 | 7 | accept |
| 512, 2-31 | 128, 44 | 127 | 7 | accept |

Single faults on the 512-processor wiring (number walk): one rack uplink, one neighbouring-rack cable or one in-rack
port-6 cable missing is accepted with "missing cable or link down"; one MetaRouter-to-repeater cable missing or
moved to another repeater port is rejected with the paired-port error on the repeater.

## Why the pair check rejects 48 processors and the deadlock check rejects the 3800 128-processor draft table

Two different routines. Both ran in the replay on the graphs the draft guide prints; neither graph is a shipped
wiring (the shipped 128-processor drawing, 8 routers and 48 cables with no unit-38 router, is the "96, 128" row
above and is accepted). Diagnostics: [route_diagnostics.py](replay/route_diagnostics.py), objdump of the unpacked
segment (the check below was read with objdump, not Ghidra).

**Pair check (48 processors).** The routine at 0x1fc241ac is named by its own console line, "check_module at %d"
(text at 0x1fc72338). The number calculation calls it once per router (0x1fc5da18), skipping MetaRouters when the
global word it tests at 0x1fc5d9f4 is nonzero. Control flow, read in full (E): it returns 0 at once for a repeat router
(flag bit 1). Otherwise, for each of the router's eight port records i (record i is port 8 - i) whose far end N is a
router of the same meta flag, it scans the other records j. Where record j of the same router leads to a router X of
the same meta flag, it takes X's record-i neighbour Z and N's record-j neighbour Y, and fails with "corresponding ports
must connect to the same module" (0x1fc723a0) when Y is a router and Y is not Z; the port mask it prints is
1 << (7 - j), so 0x80 is port 8 and 0x20 is port 6. A second error, "missing non-express links" (0x1fc723d8), prints the
fixed mask 0xe1, which is ports 8, 7, 6 and 1. The reading of the rule is **I**: the two ways round a square of four
routers must reach the same fourth router, so that router links can carry a consistent dimension number, which is how
the number walk assigns them. The error ports of the replay below are **SE**.

The 48-processor table (Table 2-13) has a partial second rack with one router, which takes both of the first rack's
unit-27 router's cables on its ports 1 and 6 while taking the unit-19 router's on 7 and 8. From the first rack's unit-19
router, port 8 then port 6 ends at the unit-27 router, while port 6 then port 8 ends at the lone router: the square
does not close. The replay prints the error three times (ports 6, 8 and 6,
once for each router of the triangle). The 64-processor graph examines 16 squares and all close. The 128-processor
draft table examines 32 and all close, so this check is not what rejects it.

**Deadlock check (Table 2-19).** The number walk accepts the table (hubs 0 to 31, depth 2, four MetaRouters) and route
calculation then fails with "Error: routing cycle detected!" and "dgraph_check failed!!!" (message texts 0x1fc74bd0 and
0x1fc74c50). The routine is the recursive dependency search at 0x1fc20be4 called from 0x1fc22a58, read in outline
earlier and not traced here. Independent of it, an analysis of the routes the PROM wrote (every hub pair forwarded by
the written tables, each router exit a channel, each consecutive pair on a path a dependency) finds a cycle in
Table 2-19 and none in Table 2-23 (256 processors, 48 channels), agreeing with the PROM's verdict on both (**SE**).
The cycle has seven channels, written as router and exit port: 002R19 p8, 002R38 p8, 013R27 p7, 012R27 p1,
012R19 p8, 013R38 p7, 002R27 p6, and back to 002R19 p8. Two MetaRouters sit on it, each entered by a unit-19 uplink
(002R38 on p3, 013R38 on p4) and left by a unit-27 uplink (p8, p7). The table gives the four U38 routers 3, 2, 2 and
1 uplinks, mixed across units, and no U38-to-U38 cable. That the PROM's routes cycle because of that shape is **I**.
What the routing code's tie-break does to produce it is **U**: the next-hop routine (0x1fc22e70) was not read in full.
Three hand-made regularisations of the uplinks were tried; each failed earlier for another reason (the
express-link check, or "get_route: bad routing table"), so none isolates the cause.

## Role values (E for the PROM, I for the pins)

The router discovery routine reads router register 0x50 by vector read (0x1fc265a8 to 0x1fc265c4), shifts right by 20,
keeps four bits, inverts, keeps the low two and ORs them into the flag halfword at +0x26 (0x1fc265d4 to 0x1fc26604):
bit 0 MetaRouter, bit 1 repeat router. Bits 23:22 are shifted in with the rest of the nibble and then masked off by the low-two keep, so they never reach the flags. The public SGI ia64 kernel patch (`linux-2.4.18-ia64-020722`, `include/asm-ia64/sn/router.h`) names register 0x50
`RR_JBUS_CONTROL` and defines a four-bit field "router position bits" at bits 23:20 (`RJC_POS_BITS`), next to the
read-strobe and output-enable timing fields; no code in the patch reads the field, and it says nothing of meta or
repeat roles (E for the field position, U for its meaning). The same patch sets `MAX_NASIDS` to 128 and `MAXCPUS` to 512
(E, public header), matching the hub limit below. The L1's router-type nibble reaches it only if L1 nibble bit n drives register bit 20 + n:
**I**. It fits all three accepted L1 values (`0xf` 11 gives no flag; `0xe` 10 gives meta; `0xc` 00 gives both). The
nibble reaches the router chip through the R-brick's ROUTER CONTROL expander on the L1 side
([R-brick page](../bricks/rbrick.md)); the pin-to-register wiring is **U**.

Flag uses: a scan for loads of the flag halfword followed by a mask finds 47 tests of bit 0 (for example number walk 0x1fc23964 and
0x1fc23ae8, route calculation 0x1fc21788, force-local 0x1fc2327c) and 17 of bit 1: the number walk's repeat-router pairing (0x1fc23a48,
0x1fc23a98: far-end port f of port p must pair with port ((f + 3) & 7) + 1), the route calculation (0x1fc21568) and the depth computation
(0x1fc5c5d0 to 0x1fc5cac4).

512-processor wiring, number walk result per role (SE, replay):

| Roles given | Register 21:20 | Result |
|---|---|---|
| repeaters both flags, MetaRouters meta | 00 / 10 | accept: eight routers "fat_tree router n, depth = 1", four "depth = 2"; all numbered; route calculation passes |
| repeaters meta only | 10 | reject ("type = 0x62, expected type: 0x42", pairing error), none numbered |
| repeaters ordinary | 11 | reject, none numbered |
| every U38 router both flags | 00 | reject (512); 13 of 20 unnumbered with the cabling error on 256 |
| MetaRouters ordinary, or one MetaRouter both flags or ordinary | 11 / 00 | reject |
| repeaters repeat flag only | 01 | **number walk accepts, route calculation fails** with "route: error: get_route: bad routing table" |

Numbering (SE, replay): hub number = router number + router port - 2 (0 mismatches in 64, 72, 104 and 128 hubs).
Ports 1 and 7 carry the in-cube dimensions 2 and 3 ("router links begin at dimn 2"). A MetaRouter's ports 3, 4, 7, 8
give its neighbour the meta part plus 0, 1, 2, 3 ("next metaid set to 0 / 16 / 32 / 48" from MetaRouter 33), and
each MetaRouter-to-repeater port sets 64 (one XOR of bit 6; "set to 64", then "consistent at 64" for the paired
ports 2, 5 and 6). MetaRouters and repeaters skip the uniqueness set (0x1fc23964 to 0x1fc23968, set test at
0x1fc23e4c), so their numbers repeat rack-router numbers (512: MetaRouters 0, 4, 8, 12, 64, 68, 72, 76; repeaters 64, 68,
72, 76). The local-bit count is a static 4 (the computing routine, 0x1fc5c438 with its only store at 0x1fc5caf4, exits
for 64 or more hubs).

## Repeat routers at 416 to 512 processors

Which U38 routers are repeaters, and is the L1 value `0xc` the right setting? Replay of PROM 6.210 over Tables 2-28 to
2-31 with [route_diagnostics.py](replay/route_diagnostics.py) (`ROLES=` overrides a router's flags) and an exhaustive
number walk over role assignments (every way of giving the repeat-and-meta flag pair to 1, 2, 3, 4 or 5 U38 routers
with the rest MetaRouters; 0.3 s per walk). The draft prints only the rule (neighbouring racks' U38 routers, printed
p. 2-28); no table labels a role.

| Fact | Grade | Evidence |
| --- | --- | --- |
| Exactly one assignment passes the number walk in each table: 416 and 448 processors, repeaters 004R38 and 014R38 (the two U38 routers that take no rack-router uplink); 480 and 512 processors, repeaters 004R38, 005R38, 014R38 and 015R38; every other U38 router a MetaRouter. Of 45 pairs at 416 and at 448, of 495 four-sets at 480 and at 512, and of the other set sizes (1 and 3 at 416 and 448, 3 and 5 at 480 and 512), none other passes | software expectation (replay; roles tried were meta-only or both flags, so "ordinary" for U38 routers is not covered) | `walk` outcomes, 2026-11-19 |
| Both flags are required on a repeater. Repeat flag only (register bits 21:20 `01`) passes the number walk and fails route calculation ("bad routing table"); meta flag only, or ordinary, fails the number walk on the repeater's paired ports; a MetaRouter given both flags fails | software expectation | ten single-router variants at 448 and 480 |
| With the full assignment, route calculation and the deadlock check pass at 416, 448, 480 and 512, the pair check closes every square (96, 96, 112 and 128 examined), and the dependency walk finds no cycle | software expectation | same replay |
| The printed drawings mark the same routers: at 416 the U38 routers of racks 004 and 014 are drawn in a different colour; at 480 and 512 the four central U38 routers (004, 005, 014, 015) carry no uplink port numbers and are joined to the MetaRouters by bundles marked 4. The drawings do not say "repeater" | established (figure content) for what is drawn; inferred for the reading | `108-0266-001` printed pp. 81, 83, 84 |
| The public SGI ia64 kernel headers keep three router types (`KLTYPE_ROUTER`, `KLTYPE_META_ROUTER`, `KLTYPE_REPEATER_ROUTER`) and two independent flags, `PCFG_ROUTER_META` and `PCFG_ROUTER_REPEATER`, tested by separate macros. They do not say whether a repeater carries the meta flag | established | `linux-2.4-klconfig.h`; patch `linux-2.4.18-ia64-020722` (`IS_META`, `IS_REPEATER`) |
| The L1 value `0xc` makes a repeater read both flags (register bits 21:20 `00`) if the L1 nibble's bit n reaches register bit 20 + n. Support: the nibble values `0xe` (meta) and `0xc` (repeater) differ from `0xf` in nested bits (bit 4 clear for both, bit 5 clear only for the repeater, controller repository, `platforms/bricks/router-role-setting.md`), which is the nesting the PROM needs (repeater: both flags; meta: one). Against the other order (bit n to register bit 23 - n) neither value would read as a role. The mapping itself is not read | inferred, strong | this section; [role values](#role-values-e-for-the-prom-i-for-the-pins) |
| A real repeater's register 0x50 | unknown | needs a read of register 0x50 on a repeater, or the router board's position-pin schematic |

## 416 processors: 184 cables printed in the table, 204 in the drawing

Table 2-28 has 184 cable rows (104 compute, 26 in-rack, 12 neighbouring-rack, 26 uplink, 16 U38 to U38); the drawing
`108-0266-001` printed p. 81 prints "204 cables" for 13 racks, 36 R-bricks and 104 C-bricks. The table is consistent
with its neighbours: the same row classes give 164, 200, 222 and 240 at 384, 448, 480 and 512 processors, all equal to
the drawings' totals.

- **The PROM accepts the 184-cable graph (software expectation).** Number walk, route calculation (which includes the
  deadlock check) and the pair check all pass; the pair check closes 96 squares; the dependency walk finds no cycle.
  Repeaters are 004R38 and 014R38.
- **The 204-cable graph cannot be built (not rebuilt).** The drawing prints no cable list, only 13 racks of bricks,
  ten U38 routers and a few port digits, so the endpoints of the 20 cables beyond the table are not recorded in any
  retained source. By arithmetic they cannot exist among these routers: with the table's 184 cables the 36 R-bricks
  have 24 unused ports of eight, in twelve routers (ten of them U38 routers and the two rack routers of rack 007), which
  allows at most 12 more cables, not 20 (**inferred**: assumes eight-port R-bricks and the same 36 routers). Also, 204 would exceed 200 at
  448 processors, which has eight more compute cables. So the PROM's checks cannot tell the two graphs apart, since
  only one is buildable; the printed 204 is probably a typo or counts some cables twice (**inferred**).
- What would settle it: a vector-level extraction of the drawing's cables (each endpoint's brick and port), a
  shipped 416-processor `hinv` or L2 `config`, or the draft's own cable total for the table (it prints none).

## Limits

| Limit | Value | Grade | Where |
|---|---|---|---|
| Hub NASIDs | 0 to 127: hub local words 128, meta word 0 only distributed | E | 0x1fc5d128 to 0x1fc5d160 |
| Kernel NASID table | `nasid_to_compact_node` and `compact_to_nasid_node` are 0x100 bytes of halfwords: 128 entries each, in both IP35 kernels | E | symbol sizes, both kernels; accessors read |
| Discovery entries | 256 | E | 0x1fc5d4fc |
| Routers, 512 processors | 44 = 32 + 8 + 4 | SE (replay) | table 2-31 |
| Meta bits | MetaRouter ports 3, 4, 7, 8 (2 bits) + repeater bit 6 = 3 | SE (replay) | walk text |
| Coarse region size | any hub number >= 64: first at 288 processors | E | 0x1fc60f08 |
| Router number set | 512 bits | E | earlier reading, 0x1fc23e4c |
| Router local id | 7 bits (bits 62:56 of scratch 0); meta bits 4 (bits 11:8 of register 0x10) | E | 0x1fc5d1f8, 0x1fc5d278 |
| Vector route depth | 14 routers (loop bound 15 at 0x1fc20b7c; search 0x1fc20950); master to all 171 other entries of the 512-processor graph, longest 7 = breadth-first minimum | E for the bound, SE for the longest route | 0x1fc20b7c; replay of 0x1fc20ad0 |
| Larger than 512 | no cable table; every limit above stops at 128 hubs | I | |

## Node-number distribution and the barrier

0x1fc5cc60 sends, for every other hub entry, a vector read and write over the route from the master (found by
0x1fc5306c, which calls the search at 0x1fc20ad0 and caches by destination below 1024). The barrier (0x1fc5ea08, wait 0x1fc44758) uses
vector reads of the hubs' scratch 1 and no router register or table (read earlier; not re-read here). The only
topology dependence is therefore the vector route: the replay found a route to every entry on every graph replayed, depth <= 7 of the 14
allowed. SE for the route search (replayed), E for the barrier's data path (read earlier), U for the polling time at 128 hubs.

## Open

| # | Unknown | Route |
|---|---|---|
| 0 | pin-to-register-0x50 mapping (does L1 nibble bit n drive register bit 20 + n) | read register 0x50 of a real meta and repeat router, or the router board and chip pin descriptions |
| 1 | which U38 routers carry which role on shipped systems: the replay and the drawings agree on four (two at 416 and 448), but no printed label or listing says so | a shipped system's `hinv` or L2 config |
| 2 | which routing choice makes 2-19's routes cycle (the cycle itself is located above); the 0x1fc22e70 next-hop and tie-break were not read in full | read both, then replay a regularised 128-processor table |
| 3 | minimality above 288 processors | run the same check on 320 to 512 |
| 4 | whether node distribution and the barrier complete at 128 hubs. The 512-processor replay numbers all 128 hubs 0 to 127 and every hub pair forwards (16,256 pairs, longest 7 routers), but neither stage can be replayed without live peers: both only poll hubs over the vector routes, so the open part is their polling time and the response of 127 real hubs | a 128-hub run of the PROM on a model or a real 512-processor console capture |
