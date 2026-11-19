# IP35 PROM: every write to the memory controller's bank configuration during boot

Question. In what order does the shipped IP35 (Bedrock) boot PROM write the memory controller's configuration
word (bank enables, size codes, bank swap), what does each write do to the address decode, why is it written, how
many times does one boot change the layout, and does a warm restart take a different path?

Grades: **E** established (the instructions were read and the control flow followed), **I** inferred (follows from
the code plus one stated assumption), **U** unknown (not traced, or not decidable from the PROM image).

## Sources

Both images are the CPU PROM segment `ip35prom` of the IP35 boot PROM. Load and entry address 0xc00000001fc00000;
address = 0x1fc00000 + offset into the unpacked segment. The segment is the container payload cut to its length.

| Build | Registry entry (container) | Container sha256 | Unpacked segment sha256 | Length |
|---|---|---|---|---|
| SGI Version 6.210, built Aug 26 2004 | `firmware/6.5.30/ip35prom.img` | `d74b4b7ef9c11c66692019db9af698104595be7a0573a86feae8a83441921318` | `554924380189a03a512156af2faa38344902f251b49fd5c80c253c23ecaff27b` (`firmware/6.5.30/ip35prom.payload.bin`) | 0x1686a8 |
| SGI Version 6.211, built Jan 25 2008, from IRIX 6.5.30 patch 7208 | `firmware/6.5.30-patch7208/ip35prom.img` | `daed215f0e3b4ccd1a654e16a1e810fdf608a13509f51e3706906272ee4e727a` | `25f60c7f0bae9cf32611e04205b7d0c8cf08adfddbfc1bfe433facd95b5ce271` (`firmware/6.5.30-patch7208/ip35prom.payload.bin`) | 0x168648 |

Addresses below are 6.210 addresses. The 6.211 address of each routine is in the table at the end. Method: Capstone
disassembly of the whole segment, a scan for every use of the configuration block's address, and a call-graph walk
from each store. Constants come from the global pointer table (gp = 0xc00000001fd6f740). Nothing was run. The
register layout, the byte-lane decode of the word and the size probe are in
[ip35-prom-memory-bank-config.md](../../questions/ip35-prom-memory-bank-config.md); the processor rendezvous around the
memory step is in [ip35-prom-mp-presence-poll.md](../../questions/ip35-prom-mp-presence-poll.md); the reset vector and the
cold-path selection are in [ip35-prom-reset-barrier.md](../../questions/ip35-prom-reset-barrier.md). The BaseIO image that
the 6.210 container also carries (load address 0xc000000013000000) was not examined.

## The register, as the PROM uses it

The configuration word is at node-alias offset +0x1f80008 (gp table word 0x9200000001f80000 at segment offset
0x1679d8, plus node number << 33, plus 8). Fields the PROM reads or writes (E, from the decode routine 0x1fc56e2c
and the store sites below):

- Four byte lanes, lane l = bits 8l+7 : 8l. Bit 8l+0 and 8l+1 enable the lane's two software banks (bank 2l and
  2l+1). Bits 8l+7 : 8l+4 are one size code for the pair; bank size is 32 MB << code (routine 0x1fc571e0 computes
  `0x2000000 << code`, 0 meaning none). Code 5 is 1 GB. Bit 8l+3 is a per-lane flag set from the DIMM scan's
  premium/standard character and printed as "premium" or "standard" (the flag's name is I).
- Bits 33:32: the bank-swap selector S (address bits 31:30 are XORed with S, see
  [ip35-prom-memory-bank-config.md](../../questions/ip35-prom-memory-bank-config.md) item 4; E for the kernel's
  reading, I for the chip).
- Bits 58:56: set to 7 by every PROM store (E). Bit 61 is set by the default-layout store (E); bit 60 is set there
  when the promlog variable `MemCfgRCD3` exists (E for the code; the text says "RAS to CAS delay set to 3 cycles",
  so I that bit 60 is that delay). What bits 61, 60 and 58:56 do in the chip is **U**. No interleave field is read
  or written by the PROM (E for the stores listed here; no field of the word is named as an interleave anywhere in
  the PROM's text, I).

The directory configuration register at node-alias +0x1fc0000 (the same +0x40000 offset the mp-presence page lists;
gp table word 0x9200000001fc0000) is written in step with the word; it is listed because a layout change usually
travels with it. Its bit meanings are U apart from the premium/standard text.

## Every store to the word (6.210)

| # | Store | Routine | Banks it changes | Value | Effect on decode | Why |
|---|---|---|---|---|---|---|
| S | 0x1fc2d668 (delay slot of the call at 0x1fc2d664), one or two per bank, banks 0 to 7 in order | DIMM scan 0x1fc2d524 (called at 0x1fc662d8, unconditionally) | All lanes: every enable and size field is rewritten. Only the bank under test stays enabled; the other seven are disabled | (word read at entry & 0xffffffff00000000) \| 7<<56 \| 1<<(8l+4) \| 1<<(8l+(b&1)) \| t<<(8l+3), where b is the bank, l = b>>1, t = 1 on the first attempt and 0 on the retry | Single bank b enabled, size code 1 (64 MB); swap bits keep the value read at entry. Changes the decode on every bank step (E for the value, I for the decode effect). The retry changes bit 8l+3 only | Probe. The call that follows (0x1fc309cc) reads that bank's DIMM through the memory controller's DIMM interface; the store selects which bank answers (I; the interface register block is +0x1fa0000 and was not decoded) |
| R | 0x1fc2d754 | same routine, exit | All lanes | Word as read at entry \| 7<<56 | Restores whatever lane and swap fields the word held before the scan (E) | Probe cleanup |
| D | 0x1fc6647c | memory configuration routine 0x1fc660b8 | All lanes | (word as read before the scan & 0xffffffff00000000) \| 1<<61 \| (1<<60 if `MemCfgRCD3`) \| 7<<56 \| for each lane l: 5<<(8l+4) \| 3<<8l \| (1<<(8l+3) if the scan character for the lane is `1`) | All eight banks enabled at code 5 (1 GB each); swap bits as before (E). Bank base = bank number << 30 | Test layout for the size probe (E for the code shape; the intent I). Documented in [ip35-prom-memory-bank-config.md](../../questions/ip35-prom-memory-bank-config.md) item 7 |
| F | 0x1fc666a8 | same routine, after the eight size probes (0x1fc66578) | All lanes | Same upper bits as D; lower 32 bits rebuilt from zero: for each bank with a nonzero measured size code, its enable bit, the code in bits 8l+7 : 8l+4 (the smaller of the pair's two codes when they differ, with a console line "sizes differ"), and bit 8l+3 from the scan character | The final bank map (E). A bank whose probe gave 0 and which the scan found empty is disabled | Final layout. This is the layout the memory test and the kernel see |
| X | 0x1fc54f14 | disable-one routine 0x1fc54ebc, called at 0x1fc65638 from 0x1fc655d8 | One bank b, once per bank named in the disabled-bank string (the promlog variable `DisableMemMask`, read at 0x1fc6a864, plus any bank the quick bank test at 0x1fc659b8 rejects) | (word & ~(1 << (8(b>>1)+(b&1)))) \| 7<<56 | Clears that bank's enable bit; size code and other lanes untouched (E) | Final layout: removes a bank the variable or the quick test names (E). Zero stores when the variable is empty and every bank passes |
| W | 0x1fc56e28 | swap writer 0x1fc56d94, called at 0x1fc65aa4 (S=3), 0x1fc65b38 (S=1), 0x1fc65b4c (S=2) | No enable or size bit; bits 33:32 only | (word & 0xfffffffcffffffff) \| S<<32 \| 7<<56 | Permutes address bits 31:30 by S (I for the chip, E for the kernel's use of it) | Final layout: only when bank 0 is not enabled or is in the disabled-bank string, and the first of banks 1, 2, 3 that is enabled and not in the string is bank S. If none exists the routine prints "no usable memory present for low address" and "Freezing node" and no store is made. Zero stores on a boot where bank 0 is good |
| P | 0x1fc57c20 | per-node routine 0x1fc578ec | All lanes and the swap field | (word & 0xfffffffc00000000) \| 0x27<<56 | All banks disabled, swap cleared (E) | Memory-less node: taken when a word read at 0x9000000034000000 (node window) has class 0xc000 in bits 15:12 (the field's meaning is U). Reached only from the monitor commands, see "Reachability" |

Stores to the directory configuration register that accompany these (E for the sites, U for what the bits do):
0x1fc664b8 writes (value read at 0x1fc66294) | 3 before the size probes; 0x1fc666b0 writes the same value with bit 1
cleared and bit 0 cleared or set according to the premium/standard outcome, after the word's final store F.
The per-node routine 0x1fc578ec (monitor path) also writes it and the register at +0x1fe0000 (clearing bit 1 of the first and bit 0 of the second).

### Reachability and completeness

- The normal boot path (E): the boot-master processor prints "Configuring memory" and calls 0x1fc660b8 at 0x1fc6a3a4
  (guarded only by the election at 0x1fc6a370: non-masters skip it), prints "Testing/Initializing memory" and calls the
  memory test and layout routine 0x1fc6587c at 0x1fc6a8a0, then calls 0x1fc655d8 (failed-bank disables X) at
  0x1fc6a8d8. Swap stores W are inside 0x1fc6587c. The node argument is 0 at both call sites, which is the local
  node's own alias at this point (I; the scan routine compares the argument with the local node number returned by
  0x1fc6b5d0 and takes its local-node branch when they are equal).
- Other callers of 0x1fc660b8: 0x1fc57c60 and of 0x1fc6587c: 0x1fc57cb0, both inside 0x1fc578ec, a per-node loop that
  the three monitor-command routines at 0x1fc5bb0c, 0x1fc5bc30 and 0x1fc5bd84 call (the help text lists "Reconfig.
  memory: reconf" and "Memory test/init: memtest"; which command is which was not matched, so which routine is `reconf` is
  U). Not on the normal boot path as traced (E that the routine is reached only from those commands; the three
  commands' own callers were not traced to boot, U). A third caller of 0x1fc660b8, at 0x1fc2d97c, sits in routine
  0x1fc2d928 that is reached through the gp pointer table (segment offset 0x1681a8); no direct call or table load
  of it was found, so whether it runs at boot is **U**.
- Completeness (I): the other code that reads the word does so with loads only. Read-only users checked: 0x1fc43a58,
  0x1fc54fb4, 0x1fc5522c, 0x1fc5579c, 0x1fc55b40, 0x1fc571e0, 0x1fc076c8, 0x1fc10148, 0x1fc101b4, 0x1fc158c0 (the
  memory test's saved copy), 0x1fc18880, 0x1fc2d05c, 0x1fc311ac, 0x1fc6b20c. The search covered every load of the gp
  table word, every `lui 0x1f8` and `lui 0x178` and every `ori 0x1f8`; the stores above are the only ones that reach
  +8 of that block. A store through a pointer built some other way would not have been found.

## Count: how many layout changes one boot makes

Counting word stores on the boot master of one node, normal boot path, after the reset vector's cold path (all
counts E for the code; "changes the decode" is I because the chip's decode was not read, only the PROM's and the
kernel's use of the fields):

| Step | Stores | Changes the decode? |
|---|---|---|
| Scan S, bank 0 to bank 7, first attempt | 8 | Yes, each: seven banks off and a different one on each time (the first also differs from the reset state unless that state already is that single bank, U) |
| Scan retry, a bank whose DIMM read returned an error | 0 to 8 (one extra store per bank that needed the retry) | No: only the premium/standard bit 8l+3 differs from the previous store (I) |
| Restore R | 1 | Yes (back from bank 7 alone to the word as read at entry) |
| Default D | 1 | Yes (all eight banks at 1 GB), unless the word already held exactly that |
| Final F | 1 | Yes, unless every bank measured 1 GB and its flag equals the default's, in which case it rewrites D's value |
| Disable X | 0 to 8 (one per failed bank) | Yes if the bank was enabled; a failed bank the final layout had already left disabled would rewrite the same value |
| Swap W | 0 or 1 | Yes (swap bits only) |

So a boot with all eight banks populated, readable, passing and bank 0 good makes **11 stores to the word**
(8 + 1 + 1 + 1), of which **10 or 11 change the decode** (11 unless F equals D). Variations add stores: 1 per scan retry
(no decode change), 1 per failed bank, 1 for a bank-0 swap. The number of decode changes cannot be below 10 on the
normal boot path for an eight-bank scan: the scan loop has the fixed bound 8 (compare at 0x1fc2d608) and the node has
no per-bank skip (E). Banks that are empty still cost a scan store each, because the store comes before the DIMM
read whose result decides whether the bank exists.

Count of stores that leave the decode unchanged: **0** on a clean boot in the best case; at most **8** (scan
retries, I) plus the cases in the table (F equal to D, a repeated disable). A model that re-lays memory only on an actual
decode change therefore sees almost as many events as a model that re-lays on every store; the counts differ by 0 to
about 9, not by a factor.

### Warm restart

The PROM has one reset-type test: at the reset vector it parks the old Status register and tests bits 20 and 19
(soft reset, NMI) at 0x1fc00458 to 0x1fc00464 (E, from [ip35-prom-reset-barrier.md](../../questions/ip35-prom-reset-barrier.md) item 1).

- Neither bit set, or bit 19 alone: the cold path, which is the path traced above. A reset that leaves Status.SR clear,
  including a full-node reset and a Bedrock local reset, therefore makes the **same stores in the same order: 11
  stores, 10 or 11 decode changes** (E for the PROM's behaviour given that Status; I that IRIX's reboot arrives this way,
  see below).
- Soft reset (bit 20 without 19): jumps to 0x1fc01bac. That path rebuilds the TLB, stores zero to the memory
  controller's +0x790010, prints "Soft reset received" and "Taking over pod mode" (strings at 0x1fc89875 and
  0x1fc89889) and enters the monitor through 0x1fc05608 and 0x1fc50c34. It makes **no store to the word** in the part
  read (0x1fc01bac to 0x1fc01ed4, E); how it continues afterwards is U. A monitor `reconf` or `memtest` would run the
  per-node routine 0x1fc578ec (stores S, R, D, F again per node, or P).
- NMI (both bits): falls to 0x1fc0046c, an NMI sequence; its memory stores were not traced (U).
- No "memory already configured" flag or promlog test was found that skips the memory step (the one restart marker the
  PROM reads skips two start-up routines and sets the diagnostic level to None only, see "Reboot reset type"): the only
  guard on the call at 0x1fc6a3a4 is the election (E for the straight-line guard; the many forward branches of the main
  routine between 0x1fc69a00 and 0x1fc6a3a4 go to error and monitor labels or rejoin, but were not each followed, so
  I). The variables `MemCfgPremium`, `MemCfgBankSize` and `MemCfgRCD3` change probe results (see the earlier page) but
  do not skip the scan or the stores: the scan routine has no such test (E).

What the kernel's restart code does, and the one marker the PROM reads on a restart, are in "Reboot reset type"
below. Result: the kernel's restart ends in a Bedrock reset, the PROM runs its cold path, and the memory stores above
all happen again (E for the PROM, I for Status.SR being clear on that path).

## Reboot reset type

Kernels read: IRIX 6.5.30 `unix.IP35` (sha256 `412a1aae553a348376bc30cacbaf65044de1745d30222f02ec5f88297dcb1dfa`) and
IRIX 6.5.22 `unix.IP35` (`87563dbc0cbc35c590348f9ec12863884fc857f6ae3a991b803aa2a71dca791c`), both linked with symbols,
disassembled with objdump. Addresses are 6.5.30 link addresses; 6.5.22 addresses are in the last table. PROM addresses
are the 6.210 addresses used above. The routines in the two kernels match instruction for instruction after masking
branch targets and global-pointer displacements (E for `mdboot`, `prom_reboot` and the restart routine; the only
differences are one extra instruction at the start of the 6.5.22 restart routine's range and one load order in
`prom_reboot`). The kernel names `he_arcs_restart` and `he_arcs_reboot` are misleading: neither calls an ARCS firmware
vector (E, routines read in full).

### 1. What the kernel does on reboot

The chain, each link read in full (E):

1. `uadmin` (0xc0000000002f95bc). Command value 2 first calls two virtual-host operations (shutdown work, message 43),
   then falls into the same code as command 1; command 1 calls `phost_reboot` (0xc000000000314ff8) with the function code
   from the second argument. Commands 4, 8 and 256 do other things (remount and similar, not followed). Which user
   program passes which command and function code (`reboot`, `init 6`, `halt`) is **U**: no `reboot`, `halt`, `init`
   or `shutdown` binary is in the held sources, so the mapping rests on the usual System V names (function 0 halt,
   1 boot, 2 interactive boot, 3 standalone boot, 9 power off; I).
2. `phost_reboot` calls `mdboot` (0xc0000000002af460) with that function code. `mdboot` takes a lock, runs every routine
   of the shutdown callback table (0xc0000000015400f8), interrupts every other CPU with `cpuaction` to run a stop routine
   (0xc0000000002af6bc), waits for them, and on the master CPU's record calls a final routine chosen by function code:

   | Function code | Final routine (from the global pointer table, gp-8000 and gp-7992) | Console text |
   |---|---|---|
   | 1 (boot) | `prom_autoboot` 0xc0000000000404c0 | none |
   | 0 (halt) | `prom_reboot` 0xc0000000002afa98 | none |
   | 2 | `prom_reboot` | "Sorry, no interactive reboot." |
   | 3 | `prom_reboot` | "Sorry, no standalone exec." |
   | 9 | `prom_reboot`, and the power-off flag set to 1 | none |

3. `prom_autoboot` calls `he_arcs_reboot` (0xc0000000000413d8). `prom_reboot` calls `prom_reinit` (0xc0000000000404dc)
   unless the machine is panicking. `prom_reinit` powers the machine off through the L1 (`elsc_pwr_off`) if a power-off
   request was received, otherwise calls `he_arcs_restart` (0xc0000000000413b8). In a panic `prom_reboot` consults the
   kernel option `rebound` and, if it is not `y`, prints "[Press reset to restart the machine.]" and waits for a reset
   (E).
4. `he_arcs_restart` and `he_arcs_reboot` enter one common routine at 0xc000000000041240 with the value **0x0ead0030**
   (restart) or **0x0ead0040** (reboot). That routine (E):
   - ORs 0x100 into the value when the `panic_level` word is zero (0xc00000000163d424);
   - for every node up to `maxnodes` stores the 64-bit value to node-alias **+0x1e08010** (gp table word
     0x9200000001e10000 at gp+2200, displacement -0x7ff0, node number shifted left 33). That is local-block offset
     +0x8010, which the PROM reads (item 3);
   - waits 1,000,000 counts (`us_delay`);
   - if `reboot_on_panic` (0xc00000000163c76c) equals 2, opens the L1 and sends the system-reset request
     (`elsc_system_reset`, 0xc0000000000cfdc4); on failure it prints "MSC Reset command failed. Doing warm reset" and
     does the network reset below. The word's value in the image is -1, so this branch is not the default (E for the
     image value, I that it is unchanged at run time);
   - otherwise, on the master CPU (`master_procid`, 0xc00000000163d380): if the power-off flag is zero, calls
     `ni_reset_port` (0xc000000000041534), which stores **1 to 0x9200000001680010** and then **6 to
     0x9200000001680008** (the local-form network interface registers at +0x1680010 and +0x1680008; table words at
     gp+2208 and gp+2216); if the power-off flag is set it calls `sc_power_down_all` (L1) instead. Every other CPU, and
     the master after the call, loop in 3,000,000-count delays until the reset takes effect.
5. The values: the public header comments name +0x680010 "NI_RESET_ENABLE" (bit 0 "let the link layer reset the
   Bedrock") and +0x680008 "NI_PORT_RESET" (bit 1 "send warm reset", bit 2 "reset local Bedrock"), per
   [devices/bedrock/README.md](../../devices/bedrock/README.md) "Network port reset" (names are I). So the kernel's default
   restart is a local Bedrock reset plus a warm reset over the link.

No store to a processor's Status, no jump to the PROM's reset vector and no call through the ARCS firmware vector is
made by the restart routine (E: the whole routine and `mdboot` were read). The kernel does **not** itself produce
Status.SR (soft reset): SR is a processor pin state, and the only thing the routine does to the hardware is the Bedrock
reset above. Whether that reset reaches the processor as a hard reset (SR clear) or asserts the processor's soft-reset
input is **U** from the binaries. It is **I** that SR is clear on this path: the marker the PROM reads (item 3) is read
only on the cold path that the SR test selects (reset vector 0x1fc00c2c lies on the cold path after the 0x1fc00458
test), and a kernel restart that arrived as SR would instead enter "Taking over pod mode" and stop at the monitor.

### 2. What the PROM does about memory when the marker is present

Nothing different (E for the call sites; I for completeness). The memory step (0x1fc6a3a4, 0x1fc6a8a0, 0x1fc6a8d8) has
only the master-election guard whether or not the marker is set, so the 11 stores above happen again. What the marker
changes is in item 3.

### 3. How the PROM tells a kernel restart from a power-on, and a soft reset from a hard one

| Test | Where | What it reads | Effect | Grade |
|---|---|---|---|---|
| Soft reset and NMI | reset vector, 0x1fc00458 to 0x1fc00464 and 0x1fc0064c | old CP0 Status parked in CP0 register 17 (0x1fc00418); bit 20 (SR) and bit 19 (NMI) | Neither bit or NMI alone: cold path. SR alone: soft-reset path 0x1fc01bac ("Soft reset received", "Taking over pod mode", monitor). Both: NMI sequence 0x1fc0046c | E ([ip35-prom-reset-barrier.md](../../questions/ip35-prom-reset-barrier.md) item 1, re-read) |
| Kernel restart marker, first read | 0x1fc00c2c (cold path, after the flash-timing step) | doubleword at 0x9200000001608010 (local block +0x8010, the register the kernel wrote through +0x1e08010). Bits 27:16 compared with 0x0ead (mask 0x0fff0000 at 0x1fc00c34, compare at 0x1fc00c3c to 0x1fc00c40); bit 8 tested (0x1fc00c48) | Both true: jump to 0x1fc00f14, which skips the routines at 0x1fc02b54 and 0x1fc02d30 (progress codes 4 and 5, each with a failure exit to the monitor) and runs the ones under codes 0xa to 0xc. Otherwise it runs both. That the skipped pair are the cache self-tests is I (from [ip35-reset-window.md](../../questions/ip35-reset-window.md)'s cache-test row); the skip itself is E | E |
| Kernel restart marker, second read | 0x1fc69d80, in the main routine before "Configuring memory" | same doubleword | Saves it, writes back (value & 0xf000000f) at 0x1fc69da4, i.e. consumes the marker. If bits 27:16 are 0x0ead and bit 8 is set (0x1fc6ae80, 0x1fc6ae8c): sets a flag (stack word 0x68), calls 0x1fc67b90 with 2 (boot-flag bits 49:48 set to 0b01), and later prints "*** Skipping diags as requested by kernel" and sets the diagnostic level to 2 ("None") at 0x1fc6a440 and 0x1fc6a448 | E |
| Bits 7:0 of the marker (0x30 restart or 0x40 reboot) | none | not read by either site | The PROM does not distinguish restart from reboot by this word (E for the two sites; a third reader was not found by a scan of every `ori ... 0x8010`) | E / I |
| Cold-path write | 0x1fc00804 to 0x1fc00828 | same doubleword, low 3 bits set to 7 | Done on every cold start before the marker is read; does not touch bits 27:16 or 8 | E |
| Reset-cause or NMI register of the Bedrock, promlog variable, launch word | none found | | No read of a Bedrock reset-cause register or a variable that distinguishes a warm start was found on the boot path (the variable names the main routine reads are `DisableMemMask`, `MemCfg*`, `GlobalMaster`, `OverrideNIC` and similar; none is a reset indicator) | I (not every load of the main routine was classified) |

So the PROM's two inputs are the processor's Status.SR and NMI and the kernel marker in local-block +0x8010. The marker
is only written by the kernel (restart routine, item 1) and, in the PROM, by the monitor's own restart command at
0x1fc620ac to 0x1fc620c0, which composes 0x0ead0030 into CP0 register 17 instead (E for the code; what reads it is U).
The disk-autoboot path that follows is unchanged: the marker carries no memory or node-numbering behaviour (I).

### Build and address table

| Item | 6.5.30 `unix.IP35` | 6.5.22 `unix.IP35` |
|---|---|---|
| `uadmin` | 0xc0000000002f95bc | 0xc0000000002bff94 |
| `phost_reboot` | 0xc000000000314ff8 | 0xc0000000002db580 |
| `mdboot` | 0xc0000000002af460 | 0xc000000000271314 |
| `prom_reboot` | 0xc0000000002afa98 | 0xc00000000027194c |
| `prom_autoboot`, `prom_reinit` | 0xc0000000000404c0, 0xc0000000000404dc | same |
| `he_arcs_restart`, `he_arcs_reboot` | 0xc0000000000413b8, 0xc0000000000413d8 | 0xc000000000041188, 0xc0000000000411a8 |
| common restart routine | 0xc000000000041240 | 0xc000000000041010 |
| `ni_reset_port` | 0xc000000000041534 | 0xc000000000041304 |
| `elsc_system_reset` | 0xc0000000000cfdc4 | 0xc0000000000d212c |
| `reboot_on_panic`, `power_off_flag`, `panic_level` | 0xc00000000163c76c, 0xc000000001646510, 0xc00000000163d424 | 0xc000000001592ee8, 0xc00000000159c440, 0xc000000001593af4 |

The PROM sites above are the same in 6.211 except that code after the reset vector moved by 8 bytes (reset-vector read
0x1fc00c2c unchanged; main-routine read 0x1fc69d80 becomes 0x1fc69d78; marker consumed at 0x1fc69d9c; 6.211 contains
the same "Skipping diags" string) (E for the reset vector, the string and the read; I for the shifted addresses).

## What the PROM alone cannot settle

- The word's reset value, and whether the first scan store (bank 0 alone) differs from it: the PROM never reads the
  word before the scan stores, so the reset value is only visible in a hardware read of the word before the PROM runs.
- Whether the single-bank scan layouts are visible to anything other than the DIMM interface read that follows each one
  (a data access in that window would see them). Settled by the DIMM interface block (+0x1fa0000) register contract.
- Whether a Bedrock local reset leaves Status.SR clear at the processor (see "Reboot reset type", item 1). Settled by
  a console capture of a kernel-initiated reboot showing "Configuring memory" again, or by the Bedrock reset
  documentation, which is not held.
- The meaning of bits 61, 60 and 58:56 of the word, and of the directory register's bits 1:0 (U).
- The routine at 0x1fc2d928 and the monitor commands' callers (reachability at boot).

## 6.211 addresses

Matched by comparing the masked instruction words of each routine in both segments (jump targets and gp-relative
displacements ignored). Every routine below has zero differences except string-pointer immediates that moved by
the same 16 bytes (`0x6fa8` became `0x6f98`, `-0x1058` became `-0x1068`). The call sites listed above have the same
callers in 6.211 (0x1fc6a39c, 0x1fc6a898, 0x1fc6a8d0, 0x1fc57c58, 0x1fc57ca8, 0x1fc57ce4, 0x1fc2d980, 0x1fc662d0).
E for those routines; the rest of the 6.211 image was not compared.

| Routine or store | 6.210 | 6.211 |
|---|---|---|
| DIMM scan routine | 0x1fc2d524 | 0x1fc2d528 |
| scan store S | 0x1fc2d668 | 0x1fc2d66c |
| restore store R | 0x1fc2d754 | 0x1fc2d758 |
| DIMM read routine | 0x1fc309cc | 0x1fc309d0 |
| memory configuration routine | 0x1fc660b8 | 0x1fc660b0 |
| default store D | 0x1fc6647c | 0x1fc66474 |
| final store F | 0x1fc666a8 | 0x1fc666a0 |
| directory register stores | 0x1fc664b8, 0x1fc666b0 | 0x1fc664b0, 0x1fc666a8 |
| memory test and layout routine | 0x1fc6587c | 0x1fc65874 |
| swap writer, store W | 0x1fc56d94, 0x1fc56e28 | 0x1fc56d8c, 0x1fc56e20 |
| disable-one, store X | 0x1fc54ebc, 0x1fc54f14 | 0x1fc54eb4, 0x1fc54f0c |
| disable-failed-banks routine | 0x1fc655d8 | 0x1fc655d0 |
| per-node monitor routine, store P | 0x1fc578ec, 0x1fc57c20 | 0x1fc578e4, 0x1fc57c18 |
