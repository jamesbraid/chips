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
graph's longest is 7.

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
| IRIX 6.5.7 sources (public submodule `irix-657m-src`) | the IP27 boot PROM's number assignment, route assignment, deadlock check and global barrier, and the SN router, promcfg, address and architecture headers | read first, in my own words, for the shape of the algorithms of the earlier-generation PROM. Every fact below was re-read in the 6.210 binary or run; where the binary differs (entry limit) the binary is reported. |
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
| 0x1fc5d450 returns 0 at once when the router count (table header +0x14) is 0. It fails with "route_assign: promcfg entries more than allowed" when the entry count (header +0x08) is 257 or more (`slti 257` at 0x1fc5d4fc). The IRIX 6.5.7 source allows 512. | E | 0x1fc5d4e4 to 0x1fc5d5d8 |
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

## Role values (E for the PROM, I for the pins)

The router discovery routine reads router register 0x50 by vector read (0x1fc265a8 to 0x1fc265c4), shifts right by 20,
keeps four bits, inverts, keeps the low two and ORs them into the flag halfword at +0x26 (0x1fc265d4 to 0x1fc26604):
bit 0 MetaRouter, bit 1 repeat router. Bits 23:22 are shifted in with the rest of the nibble and then masked off by the low-two keep, so they never reach the flags. The public SN1 router header calls register 0x50
the JBUS control register. The L1's router-type nibble reaches it only if L1 nibble bit n drives register bit 20 + n:
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
| 1 | which U38 routers carry which role on shipped systems | a shipped system's `hinv` or L2 config |
| 2 | why 2-19's routes contain a cycle; the 0x1fc22e70 next-hop and tie-break were not read in full | read both |
| 3 | minimality above 288 processors | run the same check on 320 to 512 |
| 4 | whether node distribution and the barrier complete at 128 hubs | needs a 128-hub run |
