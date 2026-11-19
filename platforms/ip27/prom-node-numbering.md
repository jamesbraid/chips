# IP27 PROM node numbering: the order of the Hub writes, and what the other processors do meanwhile

Question answered: in what order does the IP27 boot PROM write the Hub's node number, cached-alias size,
region-present and region-size fields, and where are the other processors (the second processor of the
node, and the processors of the other nodes) at each of those writes? Is the "other processor waits in its own
node's memory" reading right?

What the region-present register does to the decode, how mapped uncached pages reach the Hub and what the memory configuration word decodes: [decode-mapped-uncached-and-region.md](../decode-mapped-uncached-and-region.md).

Short answer. The node number is written once per node, by that node's first processor, after the whole
machine has agreed on a numbering; the second processor of the node is held in a software delay while it
happens. Every processor in the machine runs PROM code, and keeps its stack, in a RAM copy of the PROM that sits in its
**own** node's memory at that moment, and it keeps doing so through the number change by switching to an uncached
mapping first (the PROM calls it UALIAS) that is addressed with node-number bits zero. So the reading is right for the PROM's main phase and wrong for the
PROM's final wait loop, which runs from the boot flash and holds only a small launch block in node memory. Details,
with addresses, follow.

Kernel-side writers of the same registers are not repeated here: see the kudzu repository's
`docs/numa-text-replication.md` (commit f003531), which reads the IRIX 6.5.22 and 6.5.30 kernels for
them. Register names and the register census are in [devices/hub/README.md](../../devices/hub/README.md) and
[hub-processor-interface.md](../../devices/hub_pi/README.md), [hub-network-interface.md](../../devices/hub_ni/README.md).

## Labels

E, I and U are the repository's three labels ([AGENTS.md](../../AGENTS.md)): **E** established (the routine or code
path was read in full in the shipped bytes, address given), **I** inferred (a reasoned reading, reasoning
given), **U** unknown (route to settle it given). A step order taken from a function that was read for the steps
listed but not for every branch is **I**, even when each routine it calls is **E**.

## What was read

| Item | Identity | Note |
|---|---|---|
| IP27 CPU PROM, PROM 6.156 ("SGI Version 6.156  built 11:27:56 AM Nov 18, 2003", payload offset 0x6ae58) | `firmware/ip27prom.img`, sha256 `0dbd5d5f7027e380383ce81523e1f614d58343ca82e07ec48bb4740b287eba0e` | the IRIX 6.5.30 media image. A promgen64 container, one segment `ip27prom`, container offset 0x1000, load and entry 0xc00000001fc00000, length 0xdddd0, additive checksum matches (`retools/tools/chips/promgen64.py`). Payload sha256 `c2c69bf33c375b43ec7ac511fab41ddf595be1b6838ae717e58a9a1273437fdd` |
| IRIX 6.5.30 IP27 kernel | `IP27/unix`, sha256 `567474674eaa83d36431e70f079a35819d0bc3ce1d4b4a2758b8e891b5acc463` | only for the launch call, below |
| IRIX 6.5.22 IP27 kernel | `6.5.22/unix.IP27`, sha256 `40e3f6246b58aa9b0856cf36cd868355c0c3cbc5e00bb7fc886b52ca4622dc0f` | same |

Addresses below are payload load addresses, written as the low 32 bits (0x1fc4d320 is 0xc00000001fc4d320;
the payload offset is the address minus 0x1fc00000). The payload is the boot flash image: code from 0x1fc00000
to about 0x1fc5dfe8, strings and tables after it, a literal pool at the end (the global pointer is
0xc00000001fce5028, set at 0x1fc02154), and a gzip stream at payload offset 0x75e00 that inflates to a 741,486-byte
ELF (entry 0xc000000011c00140). That ELF is the PROM's command monitor and diagnostics; it was **not** read, so
nothing here says what it does to the registers (**U**).

Not read: the IRIX 6.5 base-media PROM (6.11, sha256 prefix `2247a76e`, named in
[crosstown-ktown.md](../../devices/crosstown-ktown/README.md)). It is not in this repository's `root/`. Nothing below carries over to
it (**U**; route: unpack it with `promgen64.py` and repeat the reads listed under "How to repeat").

## Registers and aliases used

The PROM reaches the Hub through the local alias `0x9200000001000000 + offset` (each processor's own PI bank)
and through vector reads and writes routed by the network (see below). Offsets
and names are those of [devices/hub/README.md](../../devices/hub/README.md); the names come from the public header and
are **I**.

| Offset | Name | What the PROM does with it |
|---|---|---|
| PI 0x20 | PI_CPU_NUM | read to get the processor slice (A = 0, B = 1); E (0x1fc5aa80) |
| PI 0x28 | PI_CALIAS_SIZE | written once, below |
| PI 0x18 | PI_REGION_PRESENT | **no PROM access found**, below |
| PI 0x90 / 0x98 / 0xa0 | PI_INT_PEND_MOD / _PEND0 / _PEND1 | wake-up of a waiting processor, "Slave loop" below; also the barrier |
| NI 0x600000 | NI_STATUS_REV_ID | node number in bits 16:8; region size in bit 17 |
| NI 0x600100 | NI_SCRATCH_REG0 | one store at reset |
| NI 0x600108 | NI_SCRATCH_REG1 | the PROM's mailbox: node number to be used in bits 15:0 (0xffff means not yet assigned), barrier state in bits 39:24 and 17, and a flag in bit 51 |
| II 0x400150 | (scratch word, name not read) | PROM flag word: bit 23 and bit 22 are the processor-A and processor-B enable flags, bit 35 is "this node is the global master" (I, from the uses below) |
| LB 0x30100 | real-time counter | the PROM's microsecond timer, E (0x1fc5ad88: count = microseconds * 1.25) |

Other nodes are reached before any node number exists by remote read and write routines that take an index into the
PROM's topology table, not a node number (0x1fc5a7a0 read, 0x1fc5a854 write, both E as wrappers: they look up a
route for the entry at 0x1fc46b84 and hand the access to the network layer, which was not read; I that it uses the vector-access
registers at NI 0x600200 to 0x600310, which the PROM does store to). That is why the numbers can be written into
a Hub that has none, and why the cross-node barrier works before numbering.

Processor roles, E (0x1fc585a8, read in full): the **local master** of a node is processor A (slice 0),
or processor B when bit 23 of 0x400150 is clear (A has been disabled). The other processor is the **local slave**.
Among local masters one becomes the **global master** (bit 35 of 0x400150, set in the election routine at
0x1fc4f414; I for the election rule, not read in full).

## The order of the writes

PROM 6.156, one node, from reset to the node-number change. "All" means every processor that reaches the code;
whether processor B leaves reset at the same moment as A is **U**.

| # | Where | Write | Value | Who | Label |
|---|---|---|---|---|---|
| 1 | 0x1fc00e94, cold-reset path from 0x1fc00800 | NI_SCRATCH_REG0 (0x600100) | all ones | all | E |
| 2 | 0x1fc00ec0, then 0x1fc00ee0 | PI 0x420, then NI_PORT_RESET (0x600008) | 0x52737430 ("Rst0" in ASCII), then 0x81 | all, only when PI 0x420 does not already hold 0x52737430 (compare at 0x1fc00eb8) | E for the stores; I that the second store restarts the processor and the constant stops a second restart. If the processor is still running after it, the code at 0x1fc00f98 clears this processor's enable flag in 0x400150 ("permanently disabling" in the PROM's own text) |
| 3 | 0x1fc01140 | **PI_CALIAS_SIZE** (PI 0x28) | **1** (4 KB by the code table in [hub-processor-interface.md](../../devices/hub_pi/README.md)) | all, once, after the TLB set-up at 0x1fc05914 | E |
| 4 | 0x1fc4d718 | NI_SCRATCH_REG1 of the global master | bits 15:0 replaced by the node number the PROM chose for this node (entry 0 of its topology table, field at +34); upper bits kept | global master only | E |
| 5 | 0x1fc4d800 (headless Hubs, flag 0x10000 in the table entry) and 0x1fc4d878 (all others), both by vector write | for a headless Hub (no processor), **NI_STATUS_REV_ID** (0x600000); for every other Hub, NI_SCRATCH_REG1 (0x600108) | headless: old value with bits 16:8 replaced by the node number (mask 0xfffe00ff); others: old value with bits 15:0 replaced by the node number | global master, for every other Hub in the topology table, one after another, in table order | E |
| 6 | 0x1fc4d4c0 (local) and 0x1fc4d5b0 (every other Hub, vector write) | **NI_STATUS_REV_ID bit 17 (region size)** | cleared (mask 0xfffdffff). For a headless Hub the same write also replaces bits 16:8 with the node number first (0x1fc4d554 to 0x1fc4d594) | global master, only when some Hub's node number plus the `NASIDOffset` environment value is 64 or more (flag set at 0x1fc51de0 to 0x1fc51df0), or the `force_coarse` environment variable is nonzero (0x1fc4d420) | E for the stores and conditions. E for the polarity: the public Linux Hub header defines bit 17 set as fine (region = node) and cleared as coarse (eight nodes per region), which matches the PROM's own text ("Set coarse mode at Hub"); see [decode-mapped-uncached-and-region.md](../decode-mapped-uncached-and-region.md) |
| 7 | 0x1fc4d37c (three stores in one loop, 0x1fc4d370 to 0x1fc4d398) | **NI_STATUS_REV_ID bits 16:8 (node number)** | the old value, the old value again, then the old value with bits 16:8 replaced by the node number (a0 << 8, no masking of the argument). Each store sits between a `sync` before and a `sync` after, followed by a 20-count busy loop (0x1fc045bc) | every local master, on its own node, called from 0x1fc520dc | E |
| 8 | 0x1fc25b28 | same routine as step 7 | the number typed | the monitor's node-ID command, user driven | I (call site only) |

Not written by the PROM, as far as found (**I**; three searches: the census sites in
[devices/hub/census/](../../devices/hub/census/census-sites.tsv), every load of the literal-pool entries for the local and node-addressed Hub
aliases, and every remote-write call site's offset argument): **PI_REGION_PRESENT** (PI 0x18). The only calls
with a small offset of 24 (0x18) are at 0x1fc4daa8 and 0x1fc4db38 and are guarded by the table entry's
type being a router (2), so they address a router register, not PI 0x18. The kernel writes it
([devices/hub/README.md](../../devices/hub/README.md), `mlreset`); see the kudzu page. The inflated monitor ELF may
also write it (**U**).

What the node number comes from, **U** in general and **E** for one case: the number for each Hub is computed
by 0x1fc4def0 from the topology table (router and port positions). That routine was read only as far as one case:
a Hub with no router neighbour gets 0 (0x1fc4e808). The `NASIDOffset` environment value is added to every Hub's
number after the computation (0x1fc51d3c..0x1fc51dd8, E). For a multi-node machine this page does not say which numbers come
out (**U**; route: read 0x1fc4def0 and 0x1fc4dd10 in full, or run them against a recorded topology table).

### The step order in the main routine

Main is at 0x1fc514c4 (read for the steps below, not every branch: **I** for the order, **E** for each address).
All processors call it; `M` marks a step only the local master performs, `G` a step only the global master
performs, and every barrier is a call to 0x1fc5862c (local) or 0x1fc4f118 (global; line number is the argument).

1. Barrier; "CPU switching into node 0 cached RAM" (0x1fc51534): TLB entry for ASID 3 (0x1fc05a1c), see the
   next section.
2. `M` memory initialisation, kldir and klconfig set-up, discovery of the other nodes and routers (0x1fc50ff8 and
   callees). Local barriers (0x1fc5862c) between the steps.
3. `M` election of the global master (0x1fc4f414); "Global master is ..." printed at 0x1fc51994 and 0x1fc519b0.
4. `M` global barrier, line 4418 (0x1fc519bc). Then every local master sets bits 15:0 of its own NI_SCRATCH_REG1
   to 0xffff (0x1fc519d0): "no node number yet".
5. `G` calculates node numbers (0x1fc51d0c to 0x1fc4def0), adds `NASIDOffset` (0x1fc51dd8), may flag coarse mode, distributes routing tables
   (0x1fc51e34 to 0x1fc4d8a8), sets bit 51 of its own mailbox and of each headless Hub's mailbox (0x1fc51e68, 0x1fc51efc), then
   distributes node numbers (0x1fc51f1c to 0x1fc4d6a4): steps 4 and 5 of the table above.
6. `M`, not global: "Local System Topology Graph" (0x1fc52a20), set bit 51 of its own mailbox (0x1fc52a54), print
   "Local Master: Waiting for my NASID ..." (0x1fc52a50) and poll bits 15:0 of its mailbox for anything other than
   0xffff (0x1fc52a58 to 0x1fc52a90). The local slave of every node, including the global master's, instead prints
   "Local Slave : Waiting for my NASID ..." (0x1fc530c0) and goes straight to step 7's barrier. Between polls it waits 100,000 us (0x1fc52a80), and
   every 250 ms the routine at 0x1fc4d61c calls a console check and returns an error if it reports 3 (0x1fc4d658; I that this is an abort key). The poll has no
   timeout of its own.
7. Everyone: local barrier (0x1fc51f2c). Then read bits 15:0 of the mailbox, sign-extended (0x1fc51f34). Negative means
   "NASID not assigned by master" (0x1fc52cfc path). "NASID assigned to %d" (0x1fc51f50). The number goes into the
   environment as `NASID` (0x1fc51f80).
8. `M,G` check that the PROM versions of the other nodes match (0x1fc51fb8 to 0x1fc4fd54; "PROM version mismatch" otherwise).
9. Barrier; "CPU switching to UALIAS" (0x1fc51fd4), TLB write at 0x1fc51fe8 (0x1fc059a0); "CPU running in UALIAS"
   (0x1fc52004); "CPU flushing and invalidating caches" (0x1fc5201c), cache routines 0x1fc03aac, 0x1fc0356c,
   0x1fc034ec, 0x1fc03470 at 0x1fc52028..0x1fc52040.
10. `G` (and local master) coarse mode if flagged: step 6 (0x1fc52084).
11. `M` "Changing node ID to %d" (0x1fc520a0); **global barrier, line 4908 (0x1fc520b4)**; local barrier (0x1fc520bc).
12. `M` busy loop 4240 counts (0x1fc520d4), **step 7, the node number write** (0x1fc520dc), busy loop 4240 counts
    (0x1fc520e4). The local slave instead does one busy loop of 8480 counts (0x1fc52aa8, from the branch at
    0x1fc520cc), which is as long as the master's two loops together.
13. Local barrier (0x1fc520ec). If the new number is not 0, `M` re-initialises the node's directory memory
    ("Reinitializing directories for 32 MB", 0x1fc52164) and puts the new number into its saved base pointers
    (floating-point registers 4 and 5 serve as the PROM's globals: 0x1fc04004, 0x1fc03fe0). The local slave
    updates its own copy of those after the barrier (0x1fc52ac8..0x1fc52b18).
14. Barrier; global barrier line 4981 (0x1fc521c4); "CPU switching to node %d cached RAM" (0x1fc521f0): TLB entry for ASID 4 with
    the new node number (0x1fc5220c, 0x1fc05a98), "CPU running cached".
15. Later steps (bank swap, further tests, hand-over to the monitor ELF, the slave loop below) were not read.

## Where the code and the data live: the mappings

The PROM runs in mapped XKSEG addresses (0xc00000001fc00000 and up) and changes what those addresses mean by
rewriting TLB entries and the current ASID, so one instruction address is served from flash, then from RAM.
All entries are written by the helper at 0x1fc057f0 with a 1 MB page mask (0x1fe000, set at 0x1fc05948), so each
entry maps a 2 MB range; the entry-lo values are literals in the setters. **E**, read in full.

| ASID | Setter | TLB index | Physical range | Attribute | Used |
|---|---|---|---|---|---|
| 1 | 0x1fc05914 | 62 | 0x1fc00000 to 0x1fdfffff (boot flash), read-only | uncached (2) | from reset until the copy |
| 2 | 0x1fc059a0 | 61 | 0x1a00000 to 0x1bfffff (RAM, node-number bits 0) | uncached (2) | the PROM's own name for this is UALIAS |
| 3 | 0x1fc05a1c | 60 | same | cached (5) | "node 0 cached RAM" |
| 4 | 0x1fc05a98 (node number as argument) | 59 | (node number << 32) + 0x1a00000, same size | cached (5) | "node N cached RAM", after step 7 |

A setter leaves its own ASID in EntryHi and returns into the mapped alias (the return address is rebuilt as
0xc000... at 0x1fc05990 etc.), so the next instruction fetch is served from the new mapping. The setters
themselves run from KSEG1 flash (`jr` to 0xbfc05940 and similar), so they do not depend on the mapping they replace.
The copy of the PROM into RAM is made by the local master between ASID 1 and ASID 2 ("Copying PROM code to
memory", 0x1fc599ec, copy routine called at 0x1fc59a18); the local slave waits in the barrier at 0x1fc599f4.

What the setters imply for the node number. Before step 7 the RAM range is addressed with node-number bits zero.
The PROM flushes caches and drops to the uncached ASID 2 mapping before step 7 (steps 9 and 10), so no cached
line of that range is held under the old number. **It then keeps executing from ASID 2 after the number has
changed**, from step 7 until the ASID 4 mapping in step 14: every instruction fetch and every stack access in
that time goes to node-0-numbered addresses on a node that now has number N. That works only if the Hub resolves
such uncached accesses to the node's own memory (**I**; the PROM calls the mapping UALIAS). The one alias register the PROM
programs, PI_CALIAS_SIZE, is set to 4 KB (table, step 3), far smaller than the 2 MB range, so the alias that serves ASID 2 is
not that register's doing, or not only (**U**; no PROM code programs a second alias register; route: the Hub documentation, or a
run that reads a node-0 address from a node with a nonzero number).

Work areas, **E**. Each processor's PROM data pointer (floating-point register 5, set at 0x1fc59c54) is
0x9600000001bdf800 (A) or 0x9600000001bdfc00 (B), uncached XKPHYS addresses with node-number bits zero. The stack
top handed to the main routine is the mapped address 0xc00000001fdf0000 + (slice << 16) (0x1fc59e88 to 0x1fc59e9c,
installed at 0x1fc04660). That is inside the 2 MB window above, so the stack follows whichever ASID is current: node-0-numbered RAM
under ASID 2 and 3, node-N-numbered RAM under ASID 4. The flag word the PROM uses as a global is floating-point
register 0 (0x1fc03f74, 0x1fc03f80); a processor cannot lose it to a renumbering.

## What the other processors do at each step

"Same node, B" is the local slave; "other nodes" are the processors of every other node, including their
local masters. All of this is **I** for the timing (nothing was run) and **E** for the code each processor runs.

| Steps | Same node, B | Other nodes |
|---|---|---|
| 1-3 (reset) | runs the same reset code from flash (uncached, KSEG1), using registers only, no stack; writes its own progress word at PI 0x108 + 8 * slice (0x1fc00850) | same |
| copy and ASID 2 (0x1fc599ec) | waits in the local barrier (0x1fc599f4) | each node's local master copies the PROM into its own RAM at 0x1a00000, its B waits the same way |
| main steps 1-3 (discovery) | in the local barrier at 0x1fc517a0, 0x1fc5180c and similar; the barrier (0x1fc5862c) is a handshake on two interrupt-pending levels: A sets level 113, B sets level 112, each by a PI_INT_PEND_MOD store with bit 8 set (values 0x171 and 0x170; 0x1fc58718 and 0x1fc586b8) and clears it again with bit 8 clear (0x71, 0x70), and each spins on the other's level in PI_INT_PEND1 (bits 48 and 49; 0x1fc58690, 0x1fc58734) or until the partner's enable flag in 0x400150 is clear (0x1fc586a0, 0x1fc58744), calling the delay helper at 0x1fc39098 on each pass. Code is the RAM copy, data the work area above | each node does the same. The global master discovers the topology; the others discover their own view and print "Local System Topology Graph" |
| main step 4 (global barrier 4418) | local barrier | every local master takes part: it writes the line number (bits 39:24) and bit 17 of its own NI_SCRATCH_REG1 and polls the mailboxes of the other masters by vector read (0x1fc39124); it does not use node numbers, so the barrier works before numbering. B is in the local barrier |
| steps 4 and 5 of the table (the global master writing the numbers) | local barrier | other nodes' local masters loop in step 6 of the main list (poll NI_SCRATCH_REG1 bits 15:0, 100,000 us apart, code from the RAM copy via ASID 3, cached); their B is in the local barrier |
| step 6 of the table (region size, global master; step 10 of the main list) | local barrier, ASID 2 | the other local masters are at the barrier in step 9 or at their own copy of the global barrier at 0x1fc520b4. The global master's read-modify-write of their NI_STATUS_REV_ID (0x600000) is by vector, not by node number. Because every master must reach global barrier 4908 (0x1fc520b4) and the global master does so only after the coarse call (0x1fc52084), the region-size writes finish before any node's own step 7 (**I**: the order of main is **I**, the barrier routine 0x1fc4f118 is **E**) |
| step 7 (the node-number write, 0x1fc4d37c) | busy loop of 8480 counts (0x1fc52aa8). It touches no Hub register in that loop. Its code is fetched from the RAM copy through the uncached ASID 2 mapping and its stack is in the same range | every master leaves global barrier 4908 and then does its busy loop, write and busy loop on its own; nodes are not serialised against each other after the barrier, so some nodes are in the write while others are still in the first busy loop |
| after step 7 (0x1fc520ec on) | local barrier, then updates its saved base pointers with the new number | global barrier 4981, then maps the cached window with the new number |

Is B, or a processor of another node, ever "reading memory being renumbered"? During step 7 a processor still
executes from RAM range 0x1a00000 and uses its work area, so it **is** reading its own node's memory while the node number
changes. The PROM relies on that being safe by (**I**) leaving only uncached accesses to that range open
(ASID 2), flushing before, and not caching it again until the new number is in the address (ASID 4). What the
Hub does with a node-0-numbered access after the number changes is **U** (the PROM contains no read that checks).

## The slave loop and the launch handshake

After the PROM main routine has finished with a processor that is not the global master (the global master takes a different branch at 0x1fc52864; **I**, that branch was not read), it prints "Local %s
entering slave loop" (0x1fc52988; "master" or "slave" for the local master and local slave) and jumps to the
reset-vector slot at 0xbfc00010 (0x1fc52998, `jalr` of KSEG1 0xffffffffbfc00010). The slot holds `j 0x1fc01c0c`.
That code (0x1fc01c0c, 0x1fc01cd8, 0x1fc05914) resets the status register, clears the general and floating-point
registers (the PROM's flag word with them), checks that a floating-point register holds a value (the processor disables itself
if not), invalidates all 64 TLB entries (0x1fc058e0), sets the global pointer, **re-creates the ASID 1 flash mapping**, and jumps to the loop at 0x1fc04884. So the loop runs
**from the boot flash, uncached, with no stack and no RAM data other than the launch block below**. It is not
PROM code in node memory. **E** (0x1fc04884 to 0x1fc04bcc and the launch routine at 0x1fc04bd0 read in full).

The same jump table gives the launch interface to the kernel (**E**, 0x1fc00000 to 0x1fc00050): slot 0x38 is
the launch call (0x1fc01c24, then 0x1fc04bd0), 0x40 waits for a launch to be taken (0x1fc04c34), 0x48 reports
a block's state (0x1fc04c78), 0x50 is the PROM's printf. The IRIX kernels call slot 0x38 to start their other
processors: `allowboot` loads 0xffffffffbfc00038 (6.5.30 at 0xc0000000000444a0, `jalr` at 0xc000000000044588;
6.5.22 at 0xc000000000043c4c, `jalr` at 0xc000000000043d2c; **E**), with the node number, the slice, the entry
address, an argument, a stack pointer and a global pointer as the first six arguments (**E**, 0x1fc04bd0 stores them
into the launch block). At the one call site read in each kernel the argument and the global pointer are zero and the
stack pointer is loaded from a per-processor record (offset 1088).

Where the launch block is (**E**, 0x1fc04800, called with the node number from NI_STATUS_REV_ID bits 15:8 (0x1fc04858,
8 bits) and the slice from PI_CPU_NUM): read the doubleword at `0x9600000000000000 | (node << 32) | 0x2000 + 8` (an
uncached window onto physical offset 0x2008 of that node's own memory); for slice 1 add the doubleword at +40;
the sum, with the window address OR'd in again, is the block. The directory at physical offset 0x2000 is the one
the main routine builds ("Initializing kldir", 0x1fc515cc; I for the build).

The block, offsets in bytes (**E**):

| Offset | Meaning |
|---|---|
| +0 | magic 0xaddbead2addbead3; written by the waiting processor on every pass of the loop; checked after wake-up |
| +8 | go flag: set by the launcher, tested by the waiter |
| +16 | entry address |
| +24 | the complement of the entry address (+24 plus +16 plus 1 must be zero); cleared by the waiter after the check |
| +32 | argument, passed to the entry in a0 |
| +40 | stack pointer, loaded into sp if nonzero |
| +48 | global pointer, loaded into gp if nonzero |

The handshake (**E**):

1. The waiter (0x1fc04884 on) recomputes the block address from the current node number and slice, writes PI_INT_PEND_MOD
   with its own number plus 10 (processor A: 10, B: 11) and **bit 8 clear** (0x1fc048bc), writes the magic and
   zeroes +8 to +72, then polls.
2. It polls, in a loop of 20,000 reads, bit (slice + 10) of PI_INT_PEND0 (0x1fc049ac), and after
   each 20,000 reads tests the doubleword at +8 of the block. It alternates a progress byte, 0x45 and 0, in its LED register in the memory-controller junk bus window at 0x220050 or 0x220080, by slice
   (0x1fc04984). Either the interrupt bit or a nonzero +8 ends the wait.
3. The launcher (0x1fc04bd0) writes +16, +24, +32, +40, +48, then +8 = 1, then writes the **target node's** PI_INT_PEND_MOD
   through the node-addressed alias (0x9200000001800000 + (node << 32) + 0x90) with the value (slice + 10) | 0x100,
   i.e. bit 8 set. So bit 8 set is a set and bit 8 clear is a clear (**I**: the stores' roles; the Hub's sense is not read).
4. The waiter checks magic, +8, and the complement (0x1fc04a64..0x1fc04aa8). If all hold it loads sp and gp if nonzero, calls the
   entry with the argument, and when the entry returns it goes back to step 1. If a check fails it goes back
   to step 1 as well, and the block's magic is rewritten.

The wake-up word is therefore in the node's own memory (the block) and in the Hub's interrupt-pending register; the
code that tests them is in flash, not in memory.

Confirm or refute: "the other processor waits in its own node's memory". **Refuted for the PROM's final wait
(the slave loop): the code is in flash and the loop holds no stack or data in RAM except the launch block. Partly
confirmed for the main phase**: while the other processors wait in the local barrier, in the "Waiting for my NASID"
poll, or in the busy loops at the node-number write, the code they execute is the PROM's own RAM copy in their
own node's memory (0x1a00000), their stack is in that range, and the data they poll is in Hub registers (the
mailbox, the interrupt-pending bits, the 0x400150 flag word), not in memory. The writer's own busy loops and the
other processor's wait both run from that RAM copy while the node number changes.

## Unknowns

- Reset value of NI_STATUS_REV_ID's node field and region-size bit, and whether the first node-number write
  matters to the PROM's node-0 address mapping. Route: an early-boot read. The PROM's exception path reads the node field (nine bits, 0x1fc02560) to address its save
  area at 0x9600000000003000 + (node << 32), plus 64 for processor B; the slave loop reads eight bits (0x1fc04858).
- Whether processor B leaves reset together with A. Route: PI enable registers, not touched by the PROM before main.
- The node numbers the PROM computes for a multi-node machine (0x1fc4def0, 0x1fc4dd10).
- The meaning of bit 51 of the mailbox (the polarity of region-size bit 17 is settled: set is fine, see [decode-mapped-uncached-and-region.md](../decode-mapped-uncached-and-region.md)), and whether the monitor ELF writes
  PI_REGION_PRESENT or node numbers (route: inflate the ELF and read it).
- What the Hub does with node-0-numbered physical addresses after the node number changes.
- PROM 6.11 behaviour.

## How to repeat

```
retools/tools/re-run python3 retools/tools/chips/promgen64.py root/firmware/ip27prom.img out p156
retools/tools/re-run sh -c 'mips64-linux-gnuabi64-objdump -D -b binary -m mips:isa64 -EB \
    --adjust-vma=0xc00000001fc00000 -w -M no-aliases,gpr-names=numeric --no-show-raw-insn \
    out/p156.ip27prom.bin'
```

The global pointer is 0xc00000001fce5028; `ld $r,-N($28)` reads the pool entry at 0x1fce5028 - N. Strings are
reached as pool base 0x1fc5dfe8 plus a 16-bit offset (for example `daddiu $4,$17,736` at 0x1fc4d6cc is 0x1fc5e2c8,
"Distributing NASIDs"). Hub accessors are the local alias 0x9200000001000000 + offset, built by `lui 0x9200`,
`dsll 16`, `ori 0x100`, `dsll 16`.

## Reboot reset type (IP27 kernel restart path, and what PROM 6.156 reads to tell a restart from a power-on)

Added to answer: when IRIX reboots an IP27 node, what reset does the kernel issue, is there a soft-reset path in the
PROM that skips memory, directory or node-number work, and what does the PROM read to tell the cases apart. The IP35
counterpart, with the full argument, is in [ip35-prom-md-config.md](../ip35/prom-md-config.md) "Reboot reset type". Labels as
above. Sources are the two IP27 kernels in the table at the top (linked, with symbols) and PROM 6.156.

**Kernel path (E for every link; instruction-for-instruction identical in 6.5.22 and 6.5.30 after masking branch
targets and global-pointer displacements, and the same shape as the IP35 kernels).** 6.5.30 addresses first, 6.5.22 in
brackets:

1. `uadmin` 0xc000000000249a14 (0xc000000000248cf0), command 1, or command 2 after its shutdown calls, calls
   `phost_reboot` 0xc00000000026528c (0xc000000000264144), which calls `mdboot` 0xc0000000001ff034 (0xc0000000001fa4f0)
   with the function code. `mdboot` stops the other CPUs (`cpuaction`) and calls `prom_autoboot` 0xc000000000019498 for
   function 1, or `prom_reboot` 0xc0000000001ff66c (0xc0000000001fab28) for 0, 2, 3 and 9 (pointers in the global pointer
   table at gp-7440 and gp-7432). `prom_reboot` calls `prom_reinit` 0xc0000000000194b4 (no power-off branch on IP27;
   the IP35 one has it) unless the machine is panicking. Which user program passes which function code is **U** (no
   `reboot`, `halt` or `init` binary in the held sources; the System V names are I).
2. `prom_reinit` calls `he_arcs_restart` 0xc000000000029978 (0xc0000000000296c4) and `prom_autoboot` calls `he_arcs_reboot`
   0xc000000000029998 (0xc0000000000296e4). Neither calls an ARCS vector. Both enter the routine at 0xc000000000029814
   (0xc000000000029560) with 0x0ead0030 (restart) or 0x0ead0040 (reboot).
3. That routine: ORs 0x100 into the value when `panic_level` (0xc0000000014cba20) is zero; for every node below `maxnodes`
   stores the value to **0x9200000001800418 + (nasid << 32)** (pool word gp-24584, displacement 1048); waits 1,000,000
   counts; if `reboot_on_panic` (0xc0000000014cb024, value -1 in the image, so normally not 2) equals 2 sends the L1
   system reset (`elsc_system_reset` 0xc000000000099e4c) and on a negative result falls back to the store below;
   otherwise on the master CPU (`master_procid` 0xc0000000014cb980) with `power_off_flag` (0xc0000000014d4350) zero
   calls `ni_reset_port` 0xc00000000001d760, which stores **0x81 to 0x9200000001600008** (pool word gp-24512), and with the
   flag set calls `sysctlr_power_off`. Other CPUs wait in 3,000,000-count delays.

   0x81 is bits 7 and 0 of the network interface's reset register; devices/hub names bit 7 "warm reset" and bit 0 "whole
   Hub reset" ([hub-network-interface.md](../../devices/hub_ni/README.md)), so the kernel's default restart is a whole-Hub reset
   with a warm reset on the link (names I, address and value E). The IP35 equivalent stores 1 to +0x1680010 and 6 to
   +0x1680008.
4. Whether that reset reaches the R10000 as a hard reset (Status.SR clear) or as its soft-reset input is **U**. It is **I**
   that SR is clear: the marker below is read only on the cold path (item 6), and an SR restart would stop in the monitor.

**PROM 6.156 (`firmware/ip27prom.img`, payload as above), what it reads:**

5. Soft reset and NMI: the reset vector (0x1fc00000 jumps to 0x1fc00800) parks Status in CP0 register 17 (0x1fc00818),
   tests bits 20 and 19 together (0x1fc00858 to 0x1fc00860: both set falls through to an NMI sequence at 0x1fc00868),
   then bit 20 alone (0x1fc00c20 to 0x1fc00c28). **SR set without NMI goes to 0x1fc02334**, a soft-reset path: a progress
   store, the exception report with the text "Taking over pod mode" (0x1fc74875, call at 0x1fc02410) and the monitor entry
   (0x1fc050c8). In the stretch read, 0x1fc02334 to 0x1fc02530, there is no store to the Hub's node-number register, to
   PI_CALIAS_SIZE, to the region registers or to a memory-controller register, and no call to the memory or directory
   initialisation: **so the soft-reset path skips memory init, directory init and node numbering by not reaching them**
   (E for that stretch, U for what the monitor then does, since the monitor ELF was not read). SR clear (power-on, or
   NMI alone) is the cold path (LED 0x5f at 0x1fc00c60), where everything in this page happens.
6. The kernel marker, first read: **0x1fc012c8**, on the cold path, loads the doubleword at **0x9200000001000418** (PI +0x418,
   named PI_ERR_STACK_ADDR_A in [devices/hub/README.md](../../devices/hub/README.md); the name is I), compares bits 27:16 with
   0x0ead (0x1fc012d0 to 0x1fc012dc) and tests bit 8 (0x1fc012e4). Both true: jump to 0x1fc015f0, which skips the routine
   under progress code 4 (call at the 0x1fc012f0 path) and goes to the routines under codes 0xa and 0xb (E for the jump,
   I that the skipped routine is a cache self-test; same shape as the IP35 PROM).
7. The marker, second read: the main routine at 0x1fc58fe4 reads the same register again through pool word gp-0x7548, after
   zeroing PI +0x420 (0x1fc58fe0), stores the value in CP0 register 17 (0x1fc58fec), and with bits 27:16 = 0x0ead and bit 8
   set (0x1fc58ff8, 0x1fc58ffc, 0x1fc5a260) calls 0x1fc573dc with 2 (sets boot-flag bits 49:48 to 0b01), then prints
   "*** Skipping diags as requested by kernel" (0x1fc594cc) and sets the diagnostic level to 2, "None" (0x1fc594d0). E. The
   PROM does not clear PI +0x418 there; it later overwrites it with the error-stack address at 0x1fc5128c (E for the store;
   that this ends the marker is I). Bits 7:0 (0x30, 0x40) are not examined.
8. Nothing else: no read of a Hub reset-cause or NMI register, no launch word and no promlog variable that distinguishes
   a restart was found (I: the main routine was not classified load by load). The memory-initialisation call in the
   main routine (0x1fc59a18 into 0x1fc55738, with the diagnostic level as argument) is guarded by the election result
   at 0x1fc585a8, not by the marker, and the node-number writes described above are guarded by the election as
   well (I): so a kernel restart repeats memory configuration, directory initialisation and node numbering, with
   diagnostics set to None. The monitor's restart command at 0x1fc53470 to 0x1fc53484 writes 0x0ead0030 (masked into
   CP0 register 17), and the routine at 0x1fc479ac stores CP0 register 17 into +0x1800418 of every node (0x1fc479d0): that
   is the monitor's own way to leave the marker for the next start (E for the stores, U for the command that calls them).

The marker as written by the kernel and read by the PROM is the same word in the IP35 pair of images, at local-block
+0x8010 (see the IP35 page). Neither PROM was run.

