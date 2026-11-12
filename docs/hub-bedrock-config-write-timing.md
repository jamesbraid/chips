# Hub and Bedrock: when a node-number, cached-alias, region-present or memory-configuration write takes effect

Question. When software writes a Hub or Bedrock node-number, cached-alias size, region-present or memory
configuration register, from which point does the new value apply to accesses that are already in flight? Does the
chip document a guarantee, or does software serialise the change (barriers, read-back, polling, a single processor
running)? What do the shipped PROMs and the IRIX 6.5.22 and 6.5.30 kernels do around each such write?

Grades: **E** established (read in full from a shipped binary or a published page), **I** inferred (a reasoned
reading, reasoning given), **U** unknown (route to settle given). Addresses are link addresses in the named build;
"IP27" is the Origin 2000/Onyx2 Hub platform, "IP35" the Bedrock platform (Origin 300/3000).

## Answer in six lines

1. No held document states any latency, ordering or in-flight rule for these registers. **U** (no Hub or Bedrock
   specification is held, [specs.md](specs.md); the only statements are the public header's one-line register comments
   quoted in the register table below, and none of them is about timing).
2. IRIX never changes a node number. It reads it, and it checks the PROM-assigned number against its own table before
   it writes the registers below. **E** (Hub `get_nasid` and the check in `mlreset`; Bedrock `get_nasid`).
3. IRIX writes region-present and cached-alias size once per node, from one routine (`mlreset`, argument 0) on the boot
   processor, with plain doubleword stores through the node alias, no `sync`, no read-back and no polling. **E** for the
   code, **I** for "boot processor only".
4. Both PROMs change the node number with by far the most ceremony found: every processor rendezvous, the
   processors switch to an uncached mapping of node-number-zero RAM, caches are flushed and invalidated, one elected
   processor writes the register three times between `sync` instructions and delay loops, delays again, and all
   rendezvous again before pointers that embed the node number are rebuilt and the node's directory is reinitialised.
   **E** for the sequence, **I** for the reasons. The Hub sequence is read in
   [ip27-prom-node-numbering.md](ip27-prom-node-numbering.md); the Bedrock one is below.
5. The PROM writes the Bedrock memory-configuration word as a read-modify-write that is the last instruction of its
   routine, with the node's other processors parked in rendezvous polls, so in effect one processor is issuing
   accesses. **E**
   ([ip35-prom-mp-presence-poll.md](questions/ip35-prom-mp-presence-poll.md) item 3, re-read here).
6. The Hub PROM's node-number write has the same shape as the Bedrock one (three stores, each between `sync`
   instructions and followed by a 20-count loop, with a 4240-count loop on each side), per
   [ip27-prom-node-numbering.md](ip27-prom-node-numbering.md), which this page does not repeat. **E** there.

## Sources and builds

| What | Identity |
|---|---|
| IRIX 6.5.22 `unix.IP27` | sha256 `40e3f6246b58aa9b0856cf36cd868355c0c3cbc5e00bb7fc886b52ca4622dc0f` |
| IRIX 6.5.22 `unix.IP35` | sha256 `87563dbc0cbc35c590348f9ec12863884fc857f6ae3a991b803aa2a71dca791c` |
| IRIX 6.5.30 `unix.IP27` | sha256 `567474674eaa83d36431e70f079a35819d0bc3ce1d4b4a2758b8e891b5acc463` |
| IRIX 6.5.30 `unix.IP35` | sha256 `412a1aae553a348376bc30cacbaf65044de1745d30222f02ec5f88297dcb1dfa` |
| IP27 PROM | segment `ip27prom`, banner "SGI Version 6.156 built 11:27:56 AM Nov 18, 2003", load 0xc00000001fc00000, sha256 of the unpacked segment `c2c69bf33c375b43ec7ac511fab41ddf595be1b6838ae717e58a9a1273437fdd` |
| IP35 PROM | "SGI Version 6.210 built 02:33:51 PM Aug 26, 2004", sha256 of the unpacked segment `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b`; addresses are 6.210 addresses, the style of [ip35-reset-window.md](questions/ip35-reset-window.md) |

All four kernels are linked, with symbols. Instruction text was read from `objdump` output (n64 MIPS-IV, numeric
register names). Literal pool words were read from the images at `gp` plus the displacement. Store sites in the kernels
were enumerated with the census scanner over the linked images, so every "no other store" below means: no store the
scanner could resolve to that offset, in either kernel. A store whose base and offset are both computed at run time is
not covered (**I** wherever that matters).

Published manuals: none held for either chip ([specs.md](specs.md)). A title and document-number search of the
reference library for Hub and Bedrock register-level material found none, so what the chips document rests on the
public header's register comments that `defs/` already imports. **U** whether any 3000-family reference text states a
timing rule; none of the pages the existing PROM question pages cite does.

## The registers

Offsets are the local form (processor interface 0 at +0x0, I/O block +0x400000, local block or network interface
+0x600000, memory controller +0x200000 on the Hub and +0x780000 on Bedrock). The node alias adds the node number
shifted left 32 (Hub) or 33 (Bedrock) to a window base. Facts in the last column come from the public header as
imported in `defs/` and are **E** as statements of the header, not of silicon.

| Chip | Register | Offset | Fields that matter here | chips source |
|---|---|---|---|---|
| Hub | `NI_STATUS_REV_ID` | 0x600000 | node number bits 16:8; region size bit 17; chip revision 7:4 | `defs/hub_ni_extra.toml` |
| Hub | `PI_REGION_PRESENT` | 0x18 | one bit per region | `defs/hub.toml` |
| Hub | `PI_CALIAS_SIZE` | 0x28 | size code 0 (none), 1 = 4 KB, doubling to 15 = 64 MB | `defs/hub_pi_extra.toml` |
| Hub | `MD_MEMORY_CONFIG` | 0x200018 | bank size codes 23:0 (3 bits each); directory format bit 28; ignore-ECC bit 29; flash timing 53:44 | `defs/hub_md_extra.toml` |
| Bedrock | local-block `rev_id` | 0x600000 | node number 39:32; region size 47:46 (0 = one node per region, 1 two, 2 four) | `defs/bedrock_lb.toml` |
| Bedrock | PI `region_present` | 0x18 and +0x200000 for the second PI | one bit per region; clear bits block speculative coherent reads; not reset by a soft reset (header) | `defs/bedrock_pi.toml` |
| Bedrock | PI `calias_size` | 0x28 and +0x200000 | size code; "all cached-alias spaces in a system must carry the same size" (header); not reset by a soft reset (header) | `defs/bedrock_pi.toml` |
| Bedrock | local-block `region_present` | 0x604020 | regions that can receive an invalidate; sampled when an invalidate arrives (header) | `defs/bedrock_lb.toml` |
| Bedrock | local-block `nodes_absent` | 0x604028 | four 16-bit entries: node in 7:0, valid bit 15 | `defs/bedrock_lb.toml` |
| Bedrock | memory `memory_config` | 0x780008 | per-DIMM bytes (enables 1:0, width 3, size 7:4); bank select 33:32; survives a soft reset (header) | `defs/bedrock_md.toml` |
| Bedrock | memory `junk_bus_timing` | 0x7a0008 | flash setup-hold 7:0 and enable 15:8 | `defs/bedrock_md.toml`, [ip35-prom-poll-timing.md](questions/ip35-prom-poll-timing.md) |

## 1. What the chip documents (U)

The header comments give, for these registers: the cached-alias size must be equal in every node ("all cached-alias
spaces in a system must carry the same size"), region-present and cached-alias size are not reset by a soft reset,
memory configuration survives one, software must ask the system controller whether a DIMM is x4 or x8/x16 before it
sets the width bit, and the local block samples its region-present register when an invalidate arrives. None says when
a store becomes visible, whether in-flight requests see the old or new value, or that a read-back or `sync` is needed.
There is no statement either way, so the guarantee is **U**; the route is a Hub or Bedrock specification or a
hardware read-after-write experiment, neither of which is held.

The one chip statement that bears on in-flight behaviour is "the block samples [region present] when an invalidate
arrives": a sampling point exists for that register, but what it samples against a store in progress is not stated
(**U**).

## 2. Hub (IP27)

### 2.1 IRIX: `mlreset(0)`, 6.5.30 and 6.5.22 (E)

`mlreset` is `0xc0000000000260e0` (0x420 bytes) in 6.5.30 and `0xc000000000025eb0` (0x3fc) in 6.5.22. It has two
entries by argument. `cboot`, which every processor runs, calls it with 1 (6.5.30 `0x448e8`) and the argument-1 path
only flushes the TLB and caches and returns (`0x2619c` to `0x261b0`). `mlsetup` calls it with 0 (6.5.30 `0x1f2018`,
immediately after a cache flush) and that path does the hardware work:

1. `get_nasid` (`0x2623c`), `set_master_bridge_base`.
2. `is_fine_dirmode` result saved (`0x26294`), node count probed (`cpu_node_probe`, `0x262d4`), then
   `region_mask` is built (the builder at `0x2741c` ors `1 << get_region(c)` for every compact node c).
3. The boot processor's node number is checked: `get_nasid()` is compared with the compact-node table entry of the boot
   processor's node (`0x26344` to `0x26350`); a mismatch calls `assfail` (source line 302, `0x264e8`). **E.** So the
   kernel treats the node number as fixed and already assigned by the PROM.
4. The loop `0x26370` to `0x263ac`, once per compact node, with the base `0x9200000001800000` plus the node's number
   shifted left 32 (node alias): `sd` of `region_mask | 1` to offset 0x18 (`0x2638c`), `sd` of 2 to offset 0x28
   (`0x26394`), `sd` of 0 to `0x1c00000 + 0x190`, which is I/O offset 0x400190, entry 6 of the big-window table
   ([../chips/hub/README.md](../chips/hub/README.md), `0x400190`) (`0x26398`). The three stores are consecutive; no
   instruction in the loop other than table loads reads anything from the node. 6.5.22 has the same loop at `0x26138`,
   `0x26140`, `0x26144`.
5. After the loop: `spinlock_init`, `iograph_early_init`, `mem_init`, `hubdev_init` (`0x263cc` to `0x26404`); no
   instruction between the stores and these calls orders them.

**E:** no `sync` instruction lies in `mlreset` (0x420 bytes, 6.5.30; 0x3fc bytes, 6.5.22), `per_hub_init`,
`protect_hub_calias`, `cpuprom_map`, `hub_piomap_alloc`, `hub_piomap_free`, `hub_setup_prb`, `hub_set_piomode`,
`hub_widgetdev_enable`, `set_dir_access` or `memory_set_access`, in either IP27 kernel (and likewise either IP35
kernel). The stores are plain uncached doubleword stores.

Values: the cached-alias size IRIX writes is code 2 (8 KB) on every node, region present is the mask of regions that
hold a probed node, with bit 0 forced on (**E**: `ori $13,$13,0x1` at `0x26388`). The PROM wrote code 1 (4 KB) earlier
(2.3).

Not found: any read-back of `PI_REGION_PRESENT`, `PI_CALIAS_SIZE` or the I/O entry after the stores, in `mlreset` or
in the routines it calls before it returns. The only readers of the registers in the
kernel are `memory_iscalias` and `page_local_calias` (read 0x28), `handle_cac_buserr` (read 0x18), and the directory
routines (read 0x200018) (census, [../chips/hub/README.md](../chips/hub/README.md)); none of them is a verify of a
store. **E.**

Single processor? **I.** `mlsetup` is the boot processor's early setup. I did not trace when the kernel releases the
other processors, so "only the boot processor is running" is an inference from the routine's position, not a traced
fact. Cached-alias accesses are the low-memory accesses of the issuing node only (header), so the loop's remote
stores change a window that no other node is using yet; that, too, is **I** (from the header statement and the
position).

### 2.2 IRIX never writes a Hub node number (E)

The census of both IP27 kernels finds loads of `NI_STATUS_REV_ID` (0x600000) and no store: `get_nasid` (`0x1d664`,
bits 16:8), `get_hub_chiprev` (`0x1d6a4`, bits 7:4), `is_fine_dirmode` (`0x1d690`, bit 17), `start` (`0x1a780`) and
a few other readers. A store with a computed offset would not be covered.

### 2.3 IP27 PROM (E, mostly by reference)

`0x1fc01140`: `sd` of 1 to `0x9200000001000028`, `PI_CALIAS_SIZE` of the local Hub, after the first
progress-register stores and before the next ones (`0x1fc01144` onward). **E.** No `sync` follows it in the next 40
instructions, and the only loads in that span read PI offset 0x20 (the processor number), not the register just
written. This is the only PROM store to 0x18 or 0x28 the census resolves; [ip27-prom-node-numbering.md](ip27-prom-node-numbering.md)
reaches the same conclusion by a wider search and finds no PROM store to `PI_REGION_PRESENT` at all.

The PROM's node-number write, its processor roles, rendezvous and the mappings it switches between are read in full
in [ip27-prom-node-numbering.md](ip27-prom-node-numbering.md), for the PROM 6.156 image (the segment used here, banner
"SGI Version 6.156 built 11:27:56 AM Nov 18, 2003"). The facts that matter for this page, all **E** there: the
number is written once per node by the node's first processor, as three stores to `NI_STATUS_REV_ID` (the old value,
the old value, the new value; loop `0x1fc4d370` to `0x1fc4d398`, store `0x1fc4d37c`), each between a `sync` before
and a `sync` after, followed by a 20-count busy loop (`0x1fc045bc`); the second processor of the node is held in a
software delay of 8480 counts meanwhile; the caller first switches to an uncached mapping of node-number-zero RAM (the PROM's own name for it is UALIAS,
`0x1fc51fd4`), flushes and invalidates the caches (`0x1fc5201c`), runs a global barrier and a local barrier
(`0x1fc520b4`, `0x1fc520bc`), and runs a 4240-count loop before and after the write (`0x1fc520d4`, `0x1fc520e4`);
afterwards the node's directory is reinitialised ("Reinitializing directories for 32 MB", `0x1fc52164`) and
the saved base pointers get the new number.

## 3. Bedrock (IP35)

### 3.1 The node number: routine `0x1fc5c328` (E, read in full, 0x98 bytes)

This routine is the PROM's node-number setter: it stores to the local block's `rev_id` three times, the last with the
new number. The PROM has two other `rev_id` stores: `sd $0` of the whole word at `0x1fc67718`, in the hub
initialisation routine `0x1fc676c8` (which also stores to other node registers; where it falls relative to the rest
of the boot was not traced, **U**), and the remote one in 3.3. No kernel stores to it. (My first search for stores
used only the literal-pool slot for `0x9200000001600000`; this store builds the address with `lui`/`or` and was found
by a second search of every `lui 0x160` in the image, 23 sites, of which these two, plus reads, touch offset 0.)
Arguments: node number in `$4`, region size in `$5` (negative means leave unchanged).

1. Load the current word from `0x9200000001600000` (table word at gp-32480). Compute the new word: clear bits 39:32
   (mask `0xffffff00ffffffff`), or in `$4 << 32`; if `$5 >= 0`, also clear bits 47:46 (mask `0xffff3fffffffffff`) and
   or in `$5 << 46`.
2. Three times (`0x1fc5c378` to `0x1fc5c3a0`): `sync` (a `jal` to `0x1fc040f8`, which is `sync; jr ra`), then a second
   `jal` to the same `sync` routine whose delay slot is the store `sd $16,0($20)` to the register (so the store, then
   a `sync`), then a delay loop of 20 (`jal 0x1fc040e0` with `$4` = 20; the loop is `bne $4,$0,.; daddiu $4,$4,-1`).
   The value stored is, in order: the old word, the old word, the new word.

So the new node number is written once, third, bracketed by `sync` on both sides and followed by a 20-pass delay; the
first two stores rewrite the old word. **E** for the sequence and values. **I** for purpose: the first two stores look
like padding or a probe that re-asserts the current word before the change; no text in the image says. No read-back of
the register follows the stores in this routine.

Callers (the only two direct calls; no indirect call was searched for): `0x1fc28ba4`, with region size -1 (unchanged), and `0x1fc61254`, with the region size taken
from the master's staged word (2 bits, 60:59 of the word read at `0x1fc610c0`). **E.**

### 3.2 What surrounds the node-number change at `0x1fc61254` (E for the sequence)

The code is one routine around `0x1fc60f40` to `0x1fc61400`. In order:

| Step | Image address | What |
|---|---|---|
| "Setting region size to %d (%s mode)" printed, skipped when the mode word is zero | `0x1fc60f78` to `0x1fc60fa4` | the mode word is tested against zero and one; the `force_coarse` switch string is used at `0x1fc60f40` |
| node tables and routing tables built and distributed | `0x1fc60fc0` to `0x1fc610b0` | messages "Router table calculation failed", "... distribution failed" |
| node-ID distribution, rendezvous | `0x1fc610a8`, `0x1fc610b8` | "Node ID distribution failed"; the cross-interface rendezvous `0x1fc68fe0` |
| master prints "*** NASID assigned to %d" | `0x1fc61100` | election `0x1fc68f64` first |
| all processors rendezvous | `0x1fc61178` | `0x1fc68fe0` |
| each processor prints "CPU %C switching to UALIAS" | `0x1fc61180` | |
| each processor clears bit 4 of a flag word held in FP register `$f6` | `0x1fc61188` to `0x1fc61198` | the PROM keeps its flags and base pointers in floating-point registers (`dmtc1`/`dmfc1`) |
| each processor switches to an uncached mapping of node-number-zero RAM | `0x1fc6119c` to `0x1fc611a4`; routine `0x1fc05ce0` | the routine runs from the KSEG1 flash window and calls `0x1fc05b30` with index 61, ASID 2, the virtual base `0xc00000001fc00000` and two entry words `0x68016`, `0x6c016`, which decode as 4 KB-granule entries for physical `0x1a00000` and `0x1b00000`, uncached (**I**: `0x1fc05b30` not read; the decode follows the IP27 setter of the same ASID, **E** in [ip27-prom-node-numbering.md](ip27-prom-node-numbering.md)); it then returns to `0xc000000000000000 \| (return address & 0x1fffffff)`, the same address through the new mapping |
| each processor prints "CPU %C running in UALIAS" | `0x1fc611b4` | |
| master prints "Changing node ID to %d" | `0x1fc611c8` | election `0x1fc611bc`; then a hook call (`0x1fc64f48`) |
| master zeroes the network interface's local routing table entry 0 (`0x9200000001681000`, table word gp-31672) around a "HW Global barrier (line 4823)" (routine `0x1fc5ea08`) and restores it | `0x1fc611dc` to `0x1fc611f0` | the zero store is the delay slot of the `jal` to the barrier; **E** for the sequence, **U** for the reason |
| each processor prints "Flushing and invalidating caches" and runs the cache flush and invalidate routines | `0x1fc611f4` to `0x1fc61218` | `0x1fc03084`, `0x1fc02ffc`, `0x1fc02f80`, `0x1fc02ef0` |
| rendezvous, election | `0x1fc61230`, `0x1fc61238` | `0x1fc68fe0`, `0x1fc68f64` |
| master: spin 4240 | `0x1fc61248` | a `bne`/`daddiu` loop, about 4241 passes (**I**: `$4` = 4240) |
| **master: node-number routine** | `0x1fc61254` | section 3.1 |
| master: spin 4240 | `0x1fc6125c` | again |
| rendezvous, election, rebuild of node-relative pointers | `0x1fc61264` to `0x1fc612f0` | other processors branch to the next rendezvous at `0x1fc61374` (`0x1fc61274`); the elected processor ors the new node number shifted left 33 into FP register `$f5` (`0x1fc61294` to `0x1fc612a4`) and, under two switch-bit tests (`0x1fc612c8`, `0x1fc612f8`, not traced), `$f4`; skipped when the node number and the region size are both zero (`0x1fc6127c` to `0x1fc61288`) |
| "Reinitializing directories for 64 MB" and a directory initialisation call, elected processor only | `0x1fc61338` to `0x1fc6136c` | routine `0x1fc5c2c0` turns two memory addresses (`0x9600000000000000` plus the node number shifted left 33; the second ored with `0x4000000`) into addresses in the directory space at `0x90000001c0000000` (table word gp-32192) and calls `0x1fc05850` with zero data arguments (**I**: a fill; the callee was not read) |
| rendezvous, "HW Global barrier (line %d)" | `0x1fc61374` to `0x1fc6139c` | the barrier routine `0x1fc5ea08`, line number 4928 |

What this shows (**E** for the sequence, **I** for the readings):

- Every processor is held at a rendezvous (`0x1fc68fe0`, loops read local-block scratch registers with no
  timeout, per [ip35-prom-reset-barrier.md](questions/ip35-prom-reset-barrier.md) and
  [ip35-prom-mp-presence-poll.md](questions/ip35-prom-mp-presence-poll.md)) around the change. Only the elected processor
  stores.
- Instruction fetch and data access move onto an uncached mapping of the node's own RAM at node-number-zero addresses
  before the change (UALIAS), so the PROM keeps running from its RAM copy through the change. That is what a design
  would do if an access addressed with the old number could go astray. **I** (the code names the step; no text states why;
  the Hub's version of this reading is in [ip27-prom-node-numbering.md](ip27-prom-node-numbering.md)).
- Caches are flushed and invalidated before the change, so no line tagged with an address that embeds the old number
  is held. **I.**
- After the change the PROM waits (4240 passes), re-synchronises, re-bases its own node-relative pointers and
  reinitialises the directory of the 64 MB it uses, which means directory state is tied to the node number. **E** for
  the call and string; **I** for the reason.
- A global barrier follows. **E.**
- No read-back of the new number precedes the post-change delay. The first use of the new number after the store
  is the pointer-rebuild's call to the node-number getter `0x1fc6b5d0` (`0x1fc61294`), after the 20-pass and 4240-pass
  delays and a rendezvous. The getter (read in full, 0x24 bytes) loads `0x9200000001600000` and returns bits 39:32, so
  that call is a read-back of the register. **E.** The same getter is the PROM's source of the node number everywhere
  else (many callers), so every later node-relative address is built from the value read back. **I** for "everywhere":
  callers were counted, not all read.

### 3.3 Remote assignment (E for the code, U for completion)

Routine `0x1fc27c20` (node, value) reads the remote node's register at offset 0x600000 through the remote-register
read wrapper `0x1fc5875c`, clears bits 39:32 (`0xffffff00ffffffff`), ors `value << 32` and writes it back through
the write wrapper `0x1fc58714` (core routine `0x1fc163a4`), then tests only the error return (`0x1fc27c70`). No
`sync` or read-back at the call site. **E.** That the wrappers are the NUMAlink register-access (vector) path and
whether the core routine waits for the acknowledgement is **U** (the core's loops call the delay routine
`0x1fc6b79c` and compare a retry count; not read in full). The assigning processor performs the store. The waiting side is
the local master ("Local Master: Waiting for my NASID ...", `0x1fc61bc8`) and the local slaves ("Local Slave : Waiting
for my NASID ...", `0x1fc62190`): they poll a word whose low 12 bits read 0xfff until it is assigned (`0x1fc61bd4` to
`0x1fc61be0`, wait loop `0x1fc62300` to `0x1fc62374`: 100,000 (`0x186a0`) delay units between polls, through the
delay routine `0x1fc6b79c`, and a timeout helper `0x1fc5c3c4` that adds `0x3d090` to a counter reading; **I** that
this is a deadline), then print " finished waiting for nasid" (`0x1fc61bec`). **E** for the loop shape, **U** for which
register holds the polled word (a stack slot, 520 bytes into the frame of the routine at `0x1fc60e00`).

### 3.4 Region-present, nodes-absent and PI region-present (E)

Straight-line stores at `0x1fc5c1c0` to `0x1fc5c1f8` (routine around `0x1fc5bf68` to `0x1fc5c234`):

1. `sd $21,0($24)`: `nodes_absent` (`0x9200000001604028`, table word gp-31952), value built in a loop
   (`0x1fc5c130` to `0x1fc5c164`) that shifts left 16 and ors in `0x8000` per entry.
2. `sd $2,0($3)`: local-block `region_present` (`0x9200000001604020`, gp-31960), value `144($29)`.
3. A two-pass loop (`0x1fc5c1d0` to `0x1fc5c1f8`): for PI0 (offset 0x18) then PI1 (0x200018), through the node alias
   `0x9200000001800000 + (node << 33)`, the same value as store 2.

No `sync` and no read-back in the sequence. Each pass calls the node-number getter (`0x1fc6b5d0`) between stores; it reads `rev_id`, not a register written here.
**E.** Whether the other processors are parked here is not shown by this page: the routine's caller was not traced
(**U**); the barrier state of the memory-configuration step in 3.5 is the only traced one.

### 3.5 Memory configuration (E, from the existing page, re-read)

The memory-controller configuration word (+0x780008, reached as `0x9200000001f80000 + (node << 33) + 8`) is rewritten at
three sites (all stores to the word, with their purposes, are tabulated in [ip35-prom-md-config.md](ip35-prom-md-config.md)): `0x1fc54f14` (read-modify-write clearing per-bank fields, setting bits 58:56 to 7), `0x1fc56e28`
(bank-select field at 33:32, called from `0x1fc65aa4`, `0x1fc65b38`, `0x1fc65b4c`) and `0x1fc57c20` (the sizing code's
store, not re-read here). At `0x1fc54f14` and
`0x1fc56e28` the store is the delay slot of the routine's `jr ra`, so nothing, not even a `sync`, follows it inside
the routine. **E** (read here in 0x1fc54ee0 to 0x1fc54f18 and 0x1fc56d94 to 0x1fc56e28). The surrounding
condition: the memory step is master-only, and the node's other processors are inside the rendezvous polls (they
execute register reads and flag stores only) while it runs, per
[ip35-prom-mp-presence-poll.md](questions/ip35-prom-mp-presence-poll.md) item 3. **E** there. Whether a later routine
rewrites the word after release is **U** (same page).

### 3.6 Cached-alias size (E)

PROM: `sd` of 1 to `0x9200000001000028` at `0x1fc009ac`, just after the first TLB install and after the first
barrier stores (`0x1fc007d4` to `0x1fc00828`), before the flash-timing store (`0x1fc00b98`); the next loads read PI
offset 0x20, not 0x28 (census and [ip35-reset-window.md](questions/ip35-reset-window.md)). Only PI0's register is
written. **E.** Whether every processor of the node executes it or only one is **U** (not traced).

IRIX: `mlreset(0)`, 6.5.30 `0xc00000000004d94c` (0x480 bytes), 6.5.22 `0xc00000000004e270` (0x4b4). Per compact node,
per PI slot (two passes), through the node alias (`dsll32 ...,0x1`, node shifted left 33): `sd` region mask to
offset 0x18 (slot 0) or 0x200018 (slot 1) at `0x4dc80` (6.5.30) / `0x4e5b8` (6.5.22); `sd` 2 to offset 0x28 / 0x200028
in the delay slot of the loop branch (`0x4dc88` / `0x4e5c0`); after the slot loop `sd` 0 to I/O offset 0x400190
(`0x4dc8c` / `0x4e5c4`). Here, unlike the Hub, the region mask is stored without forcing bit 0. No `sync` in the
routine, no read-back, and the argument-1 path again only flushes (`0x4d9c4`, `0x4d9cc`). The check that
`get_nasid()` equals the compact-node table's entry for the boot processor is `0x4dc00` to `0x4dc04` with the failure
branch `0x4ddb4`. **E.**

IRIX node-number reads: `get_nasid` (`0x41434`) loads local `rev_id` and returns bits 39:32; `is_fine_dirmode`
(`0x41460`) returns whether bits 47:46 (region size) are zero. No kernel store to `rev_id`. **E.**

## 4. What can and cannot be concluded about accesses in flight

- The chip is silent. **U.**
- Whenever software is known to change a node number (PROM, either chip), it removes every in-flight-access hazard it can
  by construction, in the order: stop other processors in a rendezvous; move instruction fetch and data access to a
  number-independent uncached mapping; flush and invalidate caches; one writer; sync on both sides of the store; delay; delay again; barrier;
  rebuild every pointer that embeds the number; reinitialise the directory. **E** for each step. That the steps are
  needed (as opposed to belt and braces) is **I**; the repeated rewrite of the old word before the new one suggests
  caution rather than a documented requirement.
- For region present and cached-alias size, IRIX relies on position alone: it writes them during the boot processor's
  own setup, before the node's memory is in service, without ordering instructions. That nothing is in flight to the
  affected windows at that moment is **I**. Cached-alias size also has an equality requirement across nodes (header)
  that the loop satisfies by writing the same code to all nodes, so nodes may briefly carry different codes
  mid-loop (the boot node already carried the PROM's code 1 before it): **I** that this is safe because only
  low-memory accesses of the issuing node use the window.
- Neither IRIX kernel stores to the bank-size word after the PROM. The Hub kernel's only store to `MD_MEMORY_CONFIG`
  is a read-modify-write of its flash-timing fields (`cpuprom_map`), and the Bedrock kernel's matching store goes to the
  junk-bus timing register beside the configuration word (see
  [runtime-address-decode-changes.md](runtime-address-decode-changes.md)). So IRIX exercises no timing rule for
  the bank sizes at all. **E.**

## 5. Open items

| Question | Why open | Route |
|---|---|---|
| Whether any sequence is a requirement or an excess | no spec | a Hub or Bedrock specification; or a read-after-write test on a physical machine |
| What the `0x1fc163a4` core does (remote-register write completion) | not read in full | read it |
| Which register holds the polled node-assignment word | stack slot, not resolved | trace the stack slot at 520($29) in the routine at `0x1fc60e00` |
