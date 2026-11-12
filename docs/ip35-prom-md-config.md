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
[ip35-prom-memory-bank-config.md](questions/ip35-prom-memory-bank-config.md); the processor rendezvous around the
memory step is in [ip35-prom-mp-presence-poll.md](questions/ip35-prom-mp-presence-poll.md); the reset vector and the
cold-path selection are in [ip35-prom-reset-barrier.md](questions/ip35-prom-reset-barrier.md). The BaseIO image that
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
  [ip35-prom-memory-bank-config.md](questions/ip35-prom-memory-bank-config.md) item 4; E for the kernel's
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
| D | 0x1fc6647c | memory configuration routine 0x1fc660b8 | All lanes | (word as read before the scan & 0xffffffff00000000) \| 1<<61 \| (1<<60 if `MemCfgRCD3`) \| 7<<56 \| for each lane l: 5<<(8l+4) \| 3<<8l \| (1<<(8l+3) if the scan character for the lane is `1`) | All eight banks enabled at code 5 (1 GB each); swap bits as before (E). Bank base = bank number << 30 | Test layout for the size probe (E for the code shape; the intent I). Documented in [ip35-prom-memory-bank-config.md](questions/ip35-prom-memory-bank-config.md) item 7 |
| F | 0x1fc666a8 | same routine, after the eight size probes (0x1fc66578) | All lanes | Same upper bits as D; lower 32 bits rebuilt from zero: for each bank with a nonzero measured size code, its enable bit, the code in bits 8l+7 : 8l+4 (the smaller of the pair's two codes when they differ, with a console line "sizes differ"), and bit 8l+3 from the scan character | The final bank map (E). A bank whose probe gave 0 and which the scan found empty is disabled | Final layout. This is the layout the memory test and the kernel see |
| X | 0x1fc54f14 | disable-one routine 0x1fc54ebc, called at 0x1fc65638 from 0x1fc655d8 | One bank b, once per bank named in the failed-bank string | (word & ~(1 << (8(b>>1)+(b&1)))) \| 7<<56 | Clears that bank's enable bit; size code and other lanes untouched (E) | Final layout: removes a bank that failed the memory test (E). Zero stores on a boot where nothing failed |
| W | 0x1fc56e28 | swap writer 0x1fc56d94, called at 0x1fc65aa4 (S=3), 0x1fc65b38 (S=1), 0x1fc65b4c (S=2) | No enable or size bit; bits 33:32 only | (word & 0xfffffffcffffffff) \| S<<32 \| 7<<56 | Permutes address bits 31:30 by S (I for the chip, E for the kernel's use of it) | Final layout: only when bank 0 is not enabled or failed its test and the first of banks 1, 2, 3 that is enabled and passed is bank S. If none exists the routine prints "no usable memory present for low address" and "Freezing node" and no store is made. Zero stores on a boot where bank 0 is good |
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
(soft reset, NMI) at 0x1fc00458 to 0x1fc00464 (E, from [ip35-prom-reset-barrier.md](questions/ip35-prom-reset-barrier.md) item 1).

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
- No "memory already configured" flag, warm-boot flag or promlog test was found that skips the memory step: the only
  guard on the call at 0x1fc6a3a4 is the election (E for the straight-line guard; the many forward branches of the main
  routine between 0x1fc69a00 and 0x1fc6a3a4 go to error and monitor labels or rejoin, but were not each followed, so
  I). The variables `MemCfgPremium`, `MemCfgBankSize` and `MemCfgRCD3` change probe results (see the earlier page) but
  do not skip the scan or the stores: the scan routine has no such test (E).

Whether an IRIX warm reboot reaches the cold path (a Bedrock reset) or the soft-reset path (Status.SR) is a property
of the kernel's restart code, not of this image. The network-port reset that restarts a node (bit 2 of +0x1680008,
see [open-questions.md](open-questions.md), "IP35 network port reset") is a Bedrock reset (I); whether the L1 or the
processor path is used for `reboot` and `init 6` is **U** here.

## What the PROM alone cannot settle

- The word's reset value, and whether the first scan store (bank 0 alone) differs from it: the PROM never reads the
  word before the scan stores, so the reset value is only visible in a hardware read of the word before the PROM runs.
- Whether the single-bank scan layouts are visible to anything other than the DIMM interface read that follows each one
  (a data access in that window would see them). Settled by the DIMM interface block (+0x1fa0000) register contract.
- Which reset an IRIX warm reboot produces (cold path or soft reset). Settled by the kernel's restart routine for
  this board and, if that goes to the L1, the L1 firmware's reset command; or by a console capture of a warm reboot
  showing "Configuring memory" and "Testing/Initializing memory" again.
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
