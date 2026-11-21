# NUMAlink 4 router: what the PROM programs, and where in the boot it does it

The PROM's four router routines (`nl4r_init_global`, `nl4r_config_global`, `nl4r_config_port`, and the larger routine
that fills the routing tables), the lock around them, the real-time-clock distribution they carry and the place of all
of this in the boot sequence. Register names and bit positions are in [registers.toml](registers.toml); how a request
reaches a router is in [node-access.md](node-access.md); the unit page is [README.md](README.md).

Method. Ghidra (IA-64 module, `--sn2-prom`, no auto-analysis, decompile of each function named) on SHub 2 SAL 10.54
(`shub2snprom.bin`, snprom 10.54) and SHub 1 SAL 5.04 (`shub1snprom.bin`, snprom 10.54). Every constant quoted was
read again in an `ia64-linux-gnu-objdump` listing of the same image (run in the re-run container); the two agree
unless a line says otherwise. Names are the PROM's own strings and register table. The SHub 1 4.43 image
(`snprom.bin`, snprom 4.43) was compared by its listing only. Reviewed: see [Review](#review).

Grades follow [AGENTS.md](../../AGENTS.md). **established**: the whole routine read; **inferred**: reasoned, reasoning
given; **unknown**: not settled. Addresses are the SHub 2 image's unless marked SHub 1.

## The router lock

Software takes a router-wide lock before changing it. The lock method is slot `0xc8` of the router's method table
(`0xff4b3000`, which calls the generic lock loop `0xff418c20`) and the unlock is `0xff4b3050`.

- **Acquire (established as code).** Repeat a vector read of register `0x1038`, the alias one doubleword above
  `SCRATCH3` (`0x1030`). If the read fails, or bit 0 of the value is 0, stop and return the read's status. Otherwise
  fetch the time; if the time is at or past the start plus the timeout (10,000,000 in every call read) fail with -9,
  else sleep and read again. The units of the timeout are unknown (the time source was not identified).
- **Release (established).** Write 0 to `0x1030`.
- **What this implies (inferred).** The loop never stores a 1. A read of `0x1038` that returns bit 0 clear must
  therefore also set it: the alias is a read-and-set variant of `SCRATCH3`, and `0x1030` is the plain register that
  clears it. A router model needs exactly that: bit 0 of `SCRATCH3` set by a read of the alias, cleared by a write of
  0 to `0x1030`. The Origin 3000 router had `_WZ` and `_SZ` scratch aliases (README); this is the first use found.
- **Timeout path.** On failure the callers print `router lock of %I failed`; the clock routine then also prints
  `unable to program clock routing`. The same -9 is used by other callers of the generic loop (it is not router
  specific).

## `nl4r_init_global` (method slot `0x328`, `0xff4c7c40`)

Writes, in this order and with no read, each through the vector write at the router's route (established): `0x2000`,
`0x2010`, `0x2020`, `0x2050`, `0x2060` all zero, `PORT_PERF_WIN` (`0x1003100`) `0xc000000000000000`, `0x2030` zero.
Then:

1. Take the real-time-clock tick period of the PROM's own node (the helper `0xff41ffa0`: bits 13:4 of the node's
   `gc_src_ctrl` register, `0x2_1006_0700`, times 10 plus 10, nanoseconds; same formula as the SHub 1 clock in
   [prom-reset](../shub/prom-reset.md)). Write `period / 10 - 1` to `RTC_INTRN_CNTRL` (`0x1001908`), which is the
   node's `max_count` field copied into the router. Then read `RTC_SOURCE` (`0x1001900`) and replace its low nibble,
   `LB_RTC_SELECT`, with `0xf`, and write it back (helper `0xff4b31c0`). So after global initialisation the router's
   own clock select is 0xf, which `config_global` below treats as "no source yet" (inferred; the encoding of the
   select field is unknown).
2. Call slot `0x160` of the node's own method table and write its result to `ASIC_FIRST_ERROR_TIMESTAMP` (`0x2008`).
   The method was not read; that the value is the node's current clock count is inferred from the register name.
3. Write bit 63 (`FREE`) to the sixteen reply-gather buffers `0x4f00` to `0x4f78` (stride 8) (established).

A failed vector access in 1 to 3 prints `nl4r_init_global: error on vector access: %d, vec 0x%x` and returns the error.

## `nl4r_config_global` (method slot `0x330`, `0xff4c7f10`)

Arguments: the router handle (route and node id), the PROM's record for the router, a second record (the one that
holds the router's eight port entries) and a port number, here called the upstream port. In order (established):

1. Lock the router (above). On failure print the two messages above and return.
2. Run `nl4r_init_global`. On failure unlock and print `nl4r_config_global: error on vector access: %d, vec 0x%x`.
3. If the upstream port is 0, print `WARNING: Programming router clock distribution with invalid source.` and go on
   (the value computed is then 0xff, which is not masked to four bits and spills into the neighbouring fields; no
   caller read passes 0 on a normal path).
4. Read `RTC_SOURCE` (`0x1001900`). For each of the eight port entries (port A first) that names a neighbour and is
   not marked absent, replace that port's 4-bit field (`PORTA_RTC_SELECT` bits 7:4 up to `PORTH_RTC_SELECT` bits 35:32)
   with `upstream - 1`. Then replace `LB_RTC_SELECT` (bits 3:0) with the same value and write the register back.
5. Call slot `0x160` of the node again and write the result to `0x2008`, then unlock (write 0 to `0x1030`).
6. Clear 88 bytes of the PROM's own router record in the router's node window (a memory write, no router register),
   and record the router's route in that record (a memory write).

The meaning (inferred, from the register and field names and the clock-distribution warning): the router receives the
global real-time clock on one port and forwards it out of every connected port; each connected port, and the router's
own local block, is told which port the clock comes from. The upstream port is the port the PROM's discovery request
entered by. The router's method slot `0x1a0` returns `INPORT` (bits 43:40 of register 0) minus 1, and both the
discovery crawl (`0xff44e52c`) and the hop code (`0xff4681ac`) add 1 back, so the stored upstream port is the 1-based
`INPORT`; `nl4r_config_global` subtracts 1 again to form the select. Hardware semantics of the select
encoding are unknown; no write of the select to an unconnected port is made.

Nothing else is written: no routing table, no protection or reset register, and the result is not read back.

## `nl4r_config_port` (method slot `0x338`, `0xff4c8580`)

Already in [README.md](README.md): six writes at `0x7000000 + n * 0x1000000` plus the offsets `0x2200`, `0x2210`
(zero), `0x2100` (1), `0x18a0`, `0x18a8` (zero), `0x2218` (`0x5c0000000006`), n the port number 1 to 8. Re-read here:
the SHub 1 image has the identical offset and value list. The table and the loop of six are the same in both images.

## The table writer (method slot `0x1d8`, `0xff471a80`)

The big routine. It writes everything a route needs into one router, from the tables the route calculation built.
Order (established as code; the data-flow of the inputs is partly decoded):

1. For each port p = 0 to 7 (block base `0x8000000 + p * 0x1000000`):
   - the **local table**, 512 doublewords at `+0x0`;
   - the **global table**, 256 doublewords at `+0x1000`;
   - the **neighbour table**, 8 doublewords at `+0x1800`;
   - then `nl4r_config_port` for port p + 1 (only in the write-everything mode below).
   Local and global entries are a one-byte direction from the PROM's per-port array (its low nibble goes into `DIR0`)
   with `VALID` (bit 63) set. A neighbour entry is a 16-bit id with `VALID` set, or 0 when the PROM's id is -1.
2. The multicast destination table, 16 entries from `0x4e80` (stride 8): an entry is valid when the router has a
   route for it; it carries `NODE_ID` (bits 13:0), `DIR0` (20:16) and `DIR1` (28:24) taken from the high and low
   nibbles of a byte in the router's record. Then `0x4f90` (destination vector 0) gets the count of valid entries
   in bits 23:16 and the mask of them in bits 15:0 (not written in one mode, flag name unknown). How `NODE_ID` is
   computed was not decoded (it depends on the node count and a per-router offset).
3. The router's own local block: the **local-block local table** at `0x5000` (512 entries) and **local-block global
   table** at `0x6000` (256 entries), when the router record points at them, entries `DIR1` with `VALID`, except a
   value of `0xf` is written without `VALID`.
4. `GLOBAL_PARM0` (`0x10`): read; bits 23:16 (the `PORT*_DATELINE` bits) are set to one bit per port whose PROM record
   carries a flag (`0x20` in byte `+0x2b` of the port entry) and written back only if they differ.
5. `LB_DATELINE` (`0x4000`) is written with bit 4 of a flag word in the router's record (a one-bit enable).
   In compare mode (below) the routine returns here.
6. Write-everything mode only. Six writes (a larger router type) or two (the other) from a constant table: multicast translation entries `0x4e00`
   to `0x4e18` (`0x80000000f1010f68`, `0x80000000f1030f69`, `0x80000000f1050f6a`, `0x80000000f1070f6b`), `0x4e40`
   (`0x80000000f1028787`) and `0x4f80` (`0x1f00`), or `0x4e00`, `0x4e08` (`0x80000000f1016a6a`, `0x80000000f1016b6b`).
   Which router uses which is the type test of an input flag, not decoded.
7. Write-everything mode only. `nl4r_init_global`, then lock (a failed lock prints `router lock 0x%lx from %I failed` and
   the routine carries on without it), then `PROTECTION_CONFIG` (`0x1003018`): read, bits 30:22 (nine `FORCE_LOCAL_LUT` bits:
   the local block and the eight ports) all set to the one flag argument (the PROM's `set_force_local` choice; the
   flag value used on a normal boot is unknown) and bits 21:8 (`NODE_ID`) set to the router's own NASID; written back.
   Then `SCRATCH0` (`0x1000`) read and bit 40 set (written back): a marker. What reads it is unknown. Then unlock (a
   failed unlock prints `distribute_numbers: router unlock 0x%lx from %I failed`).

One input flag (a predicate register on entry; the caller that sets it was not decoded) picks the mode. In "compare"
mode each table entry is read first and written only when it differs, an entry equal to `VALID | 0xf` is skipped, and
the routine ends after step 5. In "write-everything" mode every entry is written, `nl4r_config_port` is called for
each port and steps 6 and 7 run.

**Router `LB` tables versus port tables.** The port tables (step 1) are indexed by destination node and held per
input port; the local-block tables (step 3) belong to the router's own port. Entries are 4 bits of direction (the
`DIR0` field of the port tables, `DIR1` of the local-block tables).

### The route entry a hop writes (method slot `0x1e0`, `0xff4733a0`)

When the PROM programs a path one hop at a time (the vector-path routine `0xff467e40`, with the strings
`Reading vector path 0x%lx status`, `vector path 0x%lx in_port is %x`, `Return path is 0x%lx`), a router hop writes one
local-table entry: address `0x8000000 + p * 0x1000000 + (entry mod 512) * 8`, value the turn count with `VALID` set
(established as code; debug text `Setting %s path 0x%lx port %d local table entry %d to %d turns`).
- `p` is the 0-based input port. The input port comes from the hop's identity read: the router's method slot `0x1a0`
  returns bits 43:40 of register 0 minus 1 (so `INPORT` counts 1 to 8; established as code).
- The turn count is the number of ports from the input port to the output port, modulo 8 (the router's slot `0x188`
  returns 8; the arithmetic that adds it when the output port is lower is established; that "turns" run in the same
  direction as the Origin 3000 router is inferred from the shared name and the same eight-port formula). A zero count
  on a router is replaced with 0 and on a node with 4 in the code read (a node-end rule; meaning unknown).
- A node (SHub 2) has two NI ports and writes the same shape of entry into its own table (`0x50020000` and up, the
  NI port stride `0x2000`; the node set-entry method is slot `0x1e0` of the SHub 2 table, `0xff46c450`).

The global and neighbour tables are written only by the table writer above (a search for the offsets `0x8001000` and
`0x8001800` as immediates finds the writer and the two dump routines, `0xff471a80` and `0xff473510`, and nothing
else). The dump routine reads 512, 256 and 8 entries per port, which, with the writer's loop bounds, settles the table
lengths (established).

## Where it runs

Established as call structure (SHub 2 10.54), not traced as a timeline:

- `0xff42cd80`, the topology-and-numbering routine run from the SAL, calls in order: the object discovery crawl
  `0xff450350` (prints `Found %d objects (%d chipsets, %d routers, %d iochipsets)`, `LLP link was up but could not
  talk to router.`; every router is found by a vector read of register 0 and classified by its part number, `0x239` for
  this router), then `0xff455e80` which leads to the numbering and route calculation (`0xff455e90`: fat-tree depth
  `0xff453220`, `next metaid` `0xff455020`, `Calculating routes` `0xff4663d0`), then **`Distributing routing tables`**
  (`0xff467320`).
- `0xff467320` walks the router vertices. For each one flagged as needing programming it calls the vertex's slot
  `0x1d8`, the table writer for a router, the node's version for a node and the TIO's for a TIO. A failure prints
  `distribute_numbers: vector 0x%lx from %I failed: %s` (a router failing to answer).
- `0xff502d50`, called by `0xff503b90` (at `0xff503d2c`), walks the board graph (the strings `Cpu brd on nasid %d has no HUB!`, `Router vertex queue limit %d
  exceeded!`, queue size 2,880 entries; at most 2,048 nodes: `number_node_board(): nasid_table exceeded`). For each
  router board it builds the router's handle from the stored route, calls **`nl4r_config_global` with the upstream
  port** the walk entered by, then **`nl4r_config_port` for each of ports 1 to 8 that has a neighbour**, and queues
  the neighbours (a router neighbour is followed through `0xff502790`; a node neighbour is queued). The slot `0x330`
  and `0x338` calls are in `0xff502d50` itself. That is where
  the clock routing is set; it is run from the PROM's klconfig numbering, not from the discovery crawl.
- `0xff4e7470` runs `Erecting partition fences` (`nl4r_fence_ports`); the clear of "MIP" state
  (`nl4r_mip_clear`) runs when a link is found down. Neither was read.

The order between the three paths (the tables, the clock walk, the fences) was not traced; the call graph shows each is
a separate routine, none calls another.

## SHub 1 against SHub 2

Established by comparing what was read:

- SHub 1 SAL 5.04 holds all five router routines under the same names: `nl4r_init_global` (`0xffaaa840`),
  `nl4r_config_global` (`0xffaaab20`), `nl4r_config_port` (`0xffaab070`) and the NUMAlink 3 pair `nl3r_config_global`
  (`0xffaaa4e0`) and `nl3r_config_port` (`0xffaaa740`). The SHub 2 images have no `nl3r_` routine.
- The SHub 1 routines write the same registers with the same values, with the vector request's address carrying the
  SHub 1 bias: bit 38 is set (`0x40_0100_1900` for `RTC_SOURCE`, `0x40_0000_2000`-form for the init list); the port
  base is `0x40_0800_0000 + (n - 1) * 0x1000000`. The two lists of writes (seven and six) are identical in value.
  `nl4r_init_global` and the distribution routine (`Distributing routing tables`, `0xffa5b5d0`) match the SHub 2
  instruction for instruction after the addresses are removed; `nl4r_config_port` and the board walk (`0xffaedff0`)
  match to about 0.78 on the same comparison, the difference being address formation.
- Differences in `nl4r_config_global`: the SHub 1 routine forms the node address with a fixed 11-bit NASID field at bit 38
  (SHub 2 reads the field widths from a register), and the 4.43 image's version does not call node slot `0x160` or
  write `0x2008` (listing comparison, 4.43 against 5.04). The lock, init, `RTC_SOURCE` loop and unlock are in both.
- `nl3r_config_global` (SHub 1) is not the NL4 routine: it reads register `0x20` (`RR_GLOBAL_PARMS0` in the Origin 3000
  router header), replaces bits 4:1 with `(port - 1) * 2` and writes it back, then does the same record clean-up. It
  takes no lock. `nl3r_config_port` makes one vector read of the port's `+0x88` register (the Origin 3000 router's
  `ERROR_CLEAR`, which is read here; a read-to-clear is possible and not established). That `0x20` bits 4:1 select the
  clock source port is inferred from the parallel with the NL4 routine.
- All four SHub 1 builds from snprom 4.20 on (4.20, 4.43, 10.40, 10.54) hold the `nl4r_` strings; 3.32 holds only two
  of them; the SHub 2 images (10.11, 10.40, 10.54) hold seven. The `R4_` register table is in all of them. For 4.20 and
  10.40 only the strings were checked.
- Chip dispatch: the SHub 1 image loads 569 (`0x239`) as an argument at `0xffa53916`, `0xffa5b6b0` and `0xffa5c11c`, and compares
  against it at `0xffa5c5a6` and in the predicate at `0xffa949ec`, beside the `0x3017` NL3 tests; a SHub 1 node therefore recognises and programs a NUMAlink 4 router exactly as a SHub 2 node
  does. That an Altix 350 router option uses this path is the product fact below, and is not shown by a run.
- Same source: the two images were built from one tree. This means the multi-node walk, the numbering and the route
  tables of a SHub 1 machine with a router (Altix 350 with the optional router, 3700 Bx2) are the ones read here, not a
  different algorithm (inferred from the identical routines; the SHub 1 board-walk and route-calculation routines were
  compared by instruction match, not read in full).

## Router access from a SHub 1 node (SAL 5.04)

Read in Ghidra (whole-image decompile of `shub1snprom.bin`, SAL 5.04) with an `ia64-linux-gnu-objdump` listing checked at
the constants; every access is a vector request in the SHub 1 form of
[node-access.md](node-access.md#shub-1-sal-504-the-vector-request-as-the-image-sends-it). Numbers below are router
register numbers, the value of `ADDRESS` after the image's own mask (bit 38 of the argument, which the image sets on router
addresses, is dropped by the mask on a vector request). Not independently reviewed; nothing was run.

**Which chip is a router (established).** `0xffa0f7e0` offers the part number (register 0 bits 27:12) to four method
tables. Part `0x239` selects the table at `0xffbd8318`, whose name method returns "NL4router"; `0x3017` "NL3router"
(`0xffbd7f98`); `0x4363` "SHub"; `0x4422` "TIO". So the earlier statement that `0x239` and `0x4422` were inferred from the
SHub 2 tables only is closed for the SHub 1 image: both are read in full there, and the NL4 table has eight ports
(`0xffa66f70` returns 8), tables of 512 and 256 entries (`0xffa66f50`, `0xffa66f60`) and 2 as its type code
(`0xffa66f80`; a SHub's is 1).

**Lock (established for the code, inferred for the register).** Acquire (`0xffa9a6f0`, through `0xffa0ad80`): vector-read
`0x1038` (`SCRATCH3_ALIAS`) until bit 0 of the data is clear, polling with the platform delay, with a timeout of
10,000,000 us (10 s; `nl4r_config_global` passes it; `cache_advert` passes 0, one try); a timeout is -9. Release
(`0xffa9a750`): vector-write 0 to `0x1030` (`SCRATCH3`). That a read of `0x1038` itself sets bit 0 (a test-and-set) is
**inferred** from the loop: a model that always reads bit 0 clear also works, but then the lock gives no exclusion.

**First contact: "cache_advert" (`0xffa67070`, slot `0x1c0`; established, with `0xffa668b0`).**

1. Read `SCRATCH0` (`0x1000`). Non-zero: somebody already advertised this router; if the lock was taken release it; return 0
   without marking the entry as programmed by this master.
2. Zero: try the lock once; while the word is still zero and the lock was not obtained, re-read every 10 ms for up to
   10 s ("cache_advert: timed out locking 0x%lx from %I", then carry on as if locked).
3. Still zero: first-time router set-up `0xffa66460`. Writes `RTC_SOURCE` (`0x1001900`) `0x888888888`, `0x1010` 0,
   `0x1001938` 1; read-modify-write `0x20` clearing bits 20:16 and 12:8; for ports 1 to 8 (port base
   `0x8000000 + (n - 1) * 0x1000000`) read-modify-write `+0x18d0` (each of four bytes: low six bits cleared, bit 0
   set) and set bit 29 of `+0x1840`; ten virtual-channel credit registers (`0x2000010`, `0x2000030` ... `0x20000f0`,
   `0x2000120`, `0x2000140`, each at `+0`, `+8`, `+0x10`, `+0x18`) written `0x111111111`; ten age registers (`0x2000400`,
   `0x2000408`, `0x2000428`, `0x2000430`, `0x2000438`, `0x2000440`, `0x2000410`, `0x2000418`, `0x2000420`, `0x2000448`)
   written `0x10101010`.
4. Ask the router's own system controller for its module id, slot and slab (`0xffa80dd0`, `0xffa80f90`, `0xffa81170`) over
   the vector path (the L1 mailbox registers `0x30` to `0x48`; the conversation was not read). A failure prints
   "cache_advert: sysctl_vec_moduleid_get failed" (or `slot_get`, `slab_get`) and the build goes on with the error
   values.
5. Write `SCRATCH0` (`0x1000`) = module id (bits 31:0) | slab << 32 | slot << 42 | bit 41 (if `0xffaac160` is non-zero) |
   `0x0400008000000000` (bits 58 and 39). Release the lock; mark the entry programmed (`+0x2b` bit 1).

**Insert (`0xffa67220`, slot `0x1c8`; established).** From the chip word: the position pins (bits 47:44, inverted) set the
router's level bits in the entry. If bit 40 of the word passed in (the `SCRATCH0` word; clear after step 5 above) is set it
reads `PROTECTION_CONFIG` (`0x1003018`) and keeps bits 21:8; otherwise the id is 0xffff. Read `GLOBAL_PARM0` (`0x10`). For
each port n = 1 to 8: write 1 to the port's `+0x2208` (error-summary clear) and read `+0x2200` (error summary) into the
port record; the record's link flag is set when chip-word bit `32 + n - 1` (port link-up) is set and bit 0 of the error
summary is clear.

**Per-boot configuration from the board walk (`0xffaedff0` and `0xffaaa840`, `0xffaaab20`, `0xffaab070`; established).**
`nl4r_config_global` (`0xffaaab20`): lock (10 s), `nl4r_init_global` (`0xffaaa840`), read `RTC_SOURCE` (`0x1001900`), set
the select nibble of every connected port to the upstream port number minus one and bits 3:0 to the same value, write it
back, call node slot `0x160` and write its result to `0x2008`, unlock. `nl4r_init_global` writes 0 to `0x2000`, `0x2010`,
`0x2020`, `0x2050`, `0x2060`, `0x2030`, `0xc000000000000000` to `0x1003100` (`PORT_PERF_WIN`); then writes the RTC delay
(the platform clock period divided by 10, minus 1) to `RTC_INTRN_CNTRL` (`0x1001908`), sets bits 3:0 of `RTC_SOURCE` to
`0xf`, writes the result of node slot `0x160` to `0x2008`, and writes `0x8000000000000000` to the 16 registers `0x4f00` to
`0x4f78` (`MCAST_REP_GATHER_BUF`). `nl4r_config_port` (`0xffaab070`), per port n: `+0x2200` 0, `+0x2210` 0,
`+0x2100` 1, `+0x18a0` 0, `+0x18a8` 0, `+0x2218` `0x5c0000000006`. Where in the boot this runs relative to the crawl is
unchanged from the SHub 2 reading: it is part of the board walk, not of discovery.

**Table writes (`0xffa67cb0`, slot `0x1d8`, with `0xffa695f0`; established as the registers written).** For each port: local
table at `port base + 0 + 8 * entry` (512 entries), global table at `+0x1000` (256), neighbour table at `+0x1800` (8),
each entry `VALID` (bit 63) with the turn count of the next section of [boot-sequence.md](../../software/firmware/snprom/boot-sequence.md#numalink-discovery-with-a-linked-port-the-neighbour-crawl-sal-504); then the multicast destination table
(`0x4e80` + 8 * i) and `0x4f90` (`MCAST_DEST_VEC_0`), the local-block tables at `0x5000` and `0x6000`, `GLOBAL_PARM0` (`0x10`), `0x4000` (`LB_DATELINE`) and a read-modify-write of `PROTECTION_CONFIG` (`0x1003018`), then `SCRATCH0` bit 40. The dump routine
`0xffa69760` reads the same tables back and prints each local-table row as one 32-bit word, one nibble per port 1 to 8
(the low four bits of that port's entry) in the format "%03x:%08lx", then the global table the same way and the eight
neighbour rows as four-digit words.

The router's address decode for `0x1_0000_0000` and the L1 mailbox protocol remain **unknown**.

## Altix 350: how modules attach to routers (007-4660-002)

Published guide, Altix 350 System User's Guide 007-4660-002, printed pages 69 to 71, 81 to 85 and 149 to 154 (PDF
offset +28). Established as the guide's statements.

- A module (a base compute, a CPU expansion or a CMPX module) has two NUMAlink-4 ports, numbered 0 and 1 in the tables.
  Up to eight modules can be joined without a router, in a ring (Figures 2-5 to 2-11, ring bisection Table 2-2).
  A router is "generally only used when there are eight or more modules" (p.149); the maximum is 16 modules and 32
  processors in one image.
- The router (R-brick) is a 2U brick with eight NUMAlink-4 connectors, lettered A to H and numbered 1 to 8 (Figure 6-3
  pairs A with 1, B with 2, through H with 8), an L1 controller with a 12-by-2 character display, a USB L1 port, a
  console port, two fans. The router chip is an eight-port crossbar (p.149). Links peak at 3.2 GB/s in each direction
  (Table 6-2). Each connector has a yellow LED (both ends powered) and a green LED (link up).
- **Single plane** (Table 2-3, Figure 2-12): the router's A to H go to NUMAlink 1 of modules 5 to 12, one cable each,
  A with 5 through H with 12. NUMAlink 0 of module 9 to module 13, 10 to 14, 11 to 15 and 12 to 16, and of modules 1 to
  4 to modules 5 to 8, are the other eight cables. So modules 1 to 4 and 13 to 16 are two hops from the router, through
  a partner module; the router has no free port in a 16-module system.
- **Dual plane** (Table 2-4, Figure 2-13): two routers. Router 1's A to H go to NUMAlink 1 of modules 5 to 12 as
  above; router 2's A to H go to NUMAlink 1 of modules 1 to 4 and 13 to 16 (its A to D to modules 1 to 4, E to H to
  modules 13 to 16). NUMAlink 0 still pairs 1 with 5, 2 with 6, 3 with 7, 4 with 8, 9 with 13, 10 with 14, 11 with 15
  and 12 with 16. Every module then has one port on a router and one on a partner, which is on the other router.
- The guide contradicts itself once, for single plane only: the prose of p.69 puts the router on "port 0" and modules 9
  to 16 on "port 1", while Table 2-3 and Figure 2-12 have the router on NUMAlink 1 and the module-to-module cables on
  NUMAlink 0. The dual-plane prose (router links on port 1, module pairs joined port 0 to port 0) agrees with Table 2-4. The tables are the longer and
  self-consistent statement and are used here; which is right on the hardware is **unknown**.
- Each system or partition needs one base I/O card (IO10 or IO9) in a base compute module (p.72).
- The guide gives no cabling rules beyond the tables (no length limit, no rule on which module may be 1 to 16, and no
  statement of what happens with an unpopulated port); no power-on or cable-check procedure for the router is given in
  the router chapter.

## Unknown

- Where the upstream port in the walk record (offset 16) is first set, and where the per-port dateline flag comes from.
- The encodings of the `RTC_SOURCE` select fields (what `0xf` means; whether the upstream port's own select matters).
- What the `0x2008` timestamp write is for, and the node method at slot `0x160`.
- Whether `0x1038` really is a read-and-set (inferred from the loop only). The timeout is 10,000,000 microseconds
  (10 s) in `nl4r_config_global` and 0 (one try) in the router's first-contact routine ([above](#router-access-from-a-shub-1-node-sal-504)).
- The input flags of the table writer (compare or write-everything mode, the type test for the two multicast tables,
  the `set_force_local` value, the `NODE_ID` arithmetic of the multicast entries) and who passes them.
- The order of the three router phases (table distribution, clock walk, fences) in one boot, and the fence routine.
- What the direction nibble in a table entry selects: **partly settled** in the SHub 1 image, whose route programmer
  calls the value "turns" and stores `(out - in)` modulo the port count for each router
  ([boot-sequence.md](../../software/firmware/snprom/boot-sequence.md#numalink-discovery-with-a-linked-port-the-neighbour-crawl-sal-504));
  `0xf` is "no route". Open: what the node-end values 0 and 4 select in a node's own tables, and whether the SHub 2
  routine `0xff4663d0` differs (its SHub 1 counterpart is `0xffa5a670`).
- Whether any guest behaviour is changed by the router tables a model leaves empty: a model that answers register 0 and
  accepts these writes lets the PROM run; whether the PROM then checks routes by sending traffic through the router was
  not read.
- Whether a SHub 1 Altix 350 PROM has a different path for the three-node-and-fewer case (rings need no router) than
  for the router case: the route calculation is the same routine, and it was read only for a lone node.

## Review

Independent review, 2026-11-21, by a reviewer who wrote none of this page. Reviewed chips revision fee9859. Method: a
fresh `ia64-linux-gnu-objdump` listing of `shub2snprom.bin` (snprom 10.54, base `0xff400000`) and `shub1snprom.bin`
(base `0xffa00000`); Altix 350 guide 007-4660-002 printed pp.69 and 149 read from the held PDF.

Checked and confirmed in the listing: the lock (`0xff4b3000` reads `0x1038`, timeout `0x989680`; unlock at `0xff4b3050`
writes 0 to `0x1030`); `nl4r_init_global` (period from bits 13:4 of `0x2_1006_0700`, times 10 plus 10; the helper
`0xff4b31c0` called with port 8 writes period/10-1 to `0x1001908`, then sets the low nibble of `0x1001900` to `0xf`; the
sixteen `FREE` writes to `0x4f00` on); `nl4r_config_global` (invalid-port warning on 0, `upstream - 1` into the
fields, slot `0x160`, router handle method slots `0x330` and `0x338` called inside `0xff502d50` at `0xff502ef0` and
`0xff5030c0`); the table writer's constants (loop bounds 512, 256 and 8 over `0x8000000`, `0x8001000`, `0x8001800`;
16 multicast entries; local-block tables at `0x5000` and `0x6000`; `GLOBAL_PARM0` mask `0xff0000`; `LB_DATELINE`
`0x4000` from bit 4; `PROTECTION_CONFIG` `0x1003018` with `NODE_ID` at bits 21:8 and the bit-22 shifts); `INPORT`
minus 1 in the method at `0xff470d50` and the `+1` at `0xff44e52c`; the SHub 1 bias (bit 38, port base
`0x40_0800_0000`) and the `0x239` compare at `0xffa5c5a6`; the Altix 350 guide's p.69 prose against its tables.

Finding, fixed: the SHub 1 `RTC_SOURCE` request address was printed `0x40_0000_1900`; the listing (`0xffaaaca6`)
has `0x40_0100_1900`.

Not re-checked: the multicast translation constants of step 6, the dateline flag byte, the SHub 1 4.43 comparison, the
instruction-match ratio and the dump routine `0xff473510`, the Altix 350 tables 2-3 and 2-4. Grades as written stand.
