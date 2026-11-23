# Origin 3000 NASID numbering

This page covers how the IP35 (Bedrock) PROM numbers the hubs of a Bedrock system (their NASIDs), what it
does with the numbers, and what IRIX does with them after boot. It answers a question the
[Cx-brick page](../bricks/cxbrick.md#module-identity-and-node-names) leaves open: the Origin 3900 guide gives the four
boards of a Cx-brick the NASID order 1, 2, 0, 3 by board, and does not say how that order arises. It is not a
register contract. No Cx-brick capture exists in this repository, so statements about a real Cx-brick are
either printed in a manual or unknown.

What the region-present register does to the decode, and how mapped uncached pages reach the Bedrock: [decode-mapped-uncached-and-region.md](../decode-mapped-uncached-and-region.md).

Each fact carries one grade, as elsewhere in the repository. **Established** means a published document, a
shipped binary or a public driver states it, with the citation. **Inferred** means it follows from established
facts but no source states it. **Unknown** means it is not settled, with the route that would settle it.

## Sources

- **IP35 PROM 6.210**, the build listed in [ip35-prom-md-config.md](prom-md-config.md), SHA-256 of the
  unpacked segment `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`. Read by disassembly.
  The routines were found by their console text and by the string-pool base the PROM sets at reset. The
  reading behind this page records no load addresses for them; re-locate them by the quoted text.
- **IRIX 6.5.30 IP35 kernel**, SHA-256 `412a1aae553a348376bc30cacbaf65044de1745d30222f02ec5f88297dcb1dfa`.
  Read by disassembly with its symbol table. The routines below are named by role, not by symbol.
- **SGI Origin 3900 Server User's Guide**, `007-4653-001` printed p. 62 (Figure 3-5 and the text above it): IP53 node board 1 is NASID n, board 2 is n+1, board 0 is n+2 and board 3 is n+3. Rechecked.
- **Public code.** OpenBSD `sginode.c` walks the same node table. The 128-entry size of that table is taken from
  the public Linux IP27 header as the reading states it. Neither public tree is checked out in this clone, so
  neither was re-read for this page.

No vendor source text was used. The facts below come from the binary reading and the published guide.

## Already covered elsewhere

| Question | Where it is settled |
|---|---|
| The four Cx-brick boards take consecutive NASIDs in the order board 1, 2, 0, 3 | [Cx-brick node numbering](../bricks/cxbrick.md#module-identity-and-node-names) |
| Module and slab names come from the L1's rack, slot and `0x000e` answers, not from the NASID | [Cx-brick, brick type letter 6](../bricks/cxbrick.md#brick-type-letter-6-in-the-prom-and-kernel) |
| Module ids come from the L1's rack, bay, type letter and position answers, one per node board, not from the NASID; the duplicate-position check compares them | [IP35 PROM module ids](prom-module-ids.md) |
| The Bedrock region-size field (bits 47:46) and its coarse value | [Bedrock local block](../../devices/bedrock_lb/README.md#identity-and-node-number), `devices/bedrock_lb/registers.toml` |
| Hub and Bedrock node-number writes, and the ordering of those writes | [Hub and Bedrock node-number write timing](../../questions/hub-bedrock-config-write-timing.md) |

This page does not restate them.

## How the PROM picks a NASID

| Fact | Grade | Evidence and limit |
|---|---|---|
| The global master computes every hub's NASID itself, from the discovered router graph, before it writes any NASID to a hub. The L1 identity queries the PROM sends (rack, slot, type, serial, position) return no NASID-like value. | established | The step prints "Calculating NASIDs" and fails with "NASID calculation failed". |
| The calculation walks the discovery table. Each entry's neighbour records (the neighbour's index and the far end's port number) link it to other entries. Routers, metarouters and hubs have separate branches. Its messages include an internal-error message for the walk and "metaid fixed to %d" for a metarouter. | inferred | The walk and its messages were read in outline, not in full, so the structure is a reading. The messages themselves are in the 6.210 image. The arithmetic was not traced end to end. |
| The numbers have a local-bits part and a router part. The PROM's debug output prints the local-bit count and, for a metarouter, its meta ID. | established for the text, which is in the 6.210 image | Same routine. |
| A router's number is its parent's number combined with a weight from a per-topology table, shifted past the local bits. A hub's low bits number it within its router. | inferred | The shift-and-combine pattern is in the routine. Which table entry each port pair selects, and where the low hub index comes from, were not traced. |
| After discovery, the PROM checks that each hub's NASID agrees with the router port it was found on, and prints a mismatch message if not ("nasid %d and router port mismatch during rediscovery" is in the 6.210 image). | inferred (the message text is established; that the check runs after discovery and that NASID is a function of router position are readings) | Same routine, read in outline. |
| An optional environment setting adds a fixed offset to the number of every discovery-table entry, hubs and routers alike, after the calculation. The PROM prints "*** Warning: NASIDOffset set to %d" when it is set. A bit in the PROM's flag word makes it skip reading this setting and the `force_coarse` setting below. | established for the offset, the warning and the skip | The loop was read in full. Which flag bit, and what sets it, were not traced. |
| Only entries of type 1 are then tested against 64. Type 1 is taken to mean hub. | established for the test; inferred for the meaning of type 1 | The mapping of type numbers to kinds is not sourced in this repository. |
| No input to the calculation is a node board number or an L1 position. | inferred | None was seen in the outline read. The L1 queries that carry those values happen at discovery and are stored beside the fields the walk uses, not in them. A full trace would settle it. |

## Region size from NASIDs

| Fact | Grade | Evidence and limit |
|---|---|---|
| If any hub's NASID is 64 or more after the offset, the PROM sets the flag-word bit that selects region size 1, and prints "Note: Setting region size to %d (%s mode)", with the size and the mode name filled in. Node-number distribution later writes that size into every hub's node-number word. Region size 1 is the coarse value of the Bedrock local block. | established | The loop that tests each hub against 64, the flag store and the message. The node-number setter's stores to the same register are read in [the write-timing page](../../questions/hub-bedrock-config-write-timing.md). |
| The `force_coarse` setting can force a larger region size. The PROM then prints "*** Warning: force_coarse = %d". | established | Same routine. The switch name is also noted in the write-timing page. |

## What IRIX does with NASIDs

| Fact | Grade | Evidence and limit |
|---|---|---|
| The kernel gives compact node id *i* to the NASID in entry *i* of the node table in the global data area. The table has 128 halfword entries and the kernel skips empty ones. A second, short table marked by a four-letter tag can add up to four more nodes. | established for the node ids | The node-probe loop walks 128 halfword entries. Each non-empty entry is stored into both lookup arrays and passed, with its index, to the per-node processor routine. OpenBSD's walk agrees. |
| Processors are numbered in the order the node loop adds them, so processor order follows table order, not ascending NASID. | inferred | The processor-numbering code inside the per-node routine was not traced. |
| The first physical memory click is computed from the lowest NASID in the table, not from node 0 or the console node. | established | The first-click routine calls a lowest-NASID helper and turns the result into a 16 KiB click. |
| A running kernel reads its own NASID from the local block identity word at each use, and builds its NASID tables once, at boot. It never reads local-block scratch 1, where the PROM is said to post a peer's number (the PROM's use of scratch 1 is not sourced here). It has no handler for a renumbering. A rewrite of the identity word under a running kernel is undefined and, by the code, fails at the next use. | inferred | Code read, not run. |
| Who fills the node table, and in what order, is not settled. No store to the table was found among the PROM stores read. If the PROM fills it in discovery order, compact node 0 is the master and the table is not sorted. If it sorts, node ids ascend with NASID. | unknown | Route: a trace of every store to the table during a PROM run. |

## Consequence for the Cx-brick

| Fact | Grade | Evidence and limit |
|---|---|---|
| With the guide's numbers, the lowest NASID is board 1 (NASID *n*), not board 0 (*n*+2). IRIX would start its physical memory at board 1's memory. Compact node 0 is board 1 if the table is sorted. | inferred | Follows from the first-click fact and the guide's order. Nothing read requires the console node to be node 0 or the lowest NASID, but the kernel's boot-node selection was not read. |
| Hypothesis: the PROM numbers hubs by their place in the router graph, so the guide's order is the order in which the boards' links reach the router ports. One reading puts board 1 on router port 2, board 2 on port 3, board 0 on port 4 and board 3 on port 5. | unknown | The guide and the rear XIO labels give numbers, not ports. The router port order is already unknown on the [Cx-brick page](../bricks/cxbrick.md#what-is-not-settled). Route: the real router-board wiring, or a real `hinv -v` with NASIDs. |

## What is not settled

| Unknown | Route that would settle it |
|---|---|
| How the calculation numbers several hubs on one router (the low hub index), and which table entry each port pair takes | A full read of the calculation routine |
| Whether any input besides port and neighbour (board number, L1 position, serial) reaches the calculation | The same read, or a capture from a brick whose boards are seated in another order |
| The flag-word bit that skips the offset and coarse settings, and what sets it | A trace of the PROM's flag-word stores |
| The type numbers of the discovery table, and which one is a hub | A source for the table's type codes |
| What fills the node table, and in what order | A trace of every store to the table during a PROM run |
| Whether IRIX needs the console node to be node 0 or the lowest NASID | The kernel's boot-node selection |
| The processor numbering inside the node loop | A read of the per-node routine |
| The NASID base *n* and the order with fewer than four boards | A real `hinv -v` with NASIDs, from a brick with fewer boards |
| The real board-to-port wiring of the Cx-brick router board | A router-board schematic or photograph, or a real `hinv -v` with NASIDs |
