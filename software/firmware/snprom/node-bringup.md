# Altix 350 single node: memory and node bring-up in SAL 5.04

What the SHub 1 firmware (`shub1snprom.bin`, SAL 5.04, snprom-10.54-70399, sha256 `51ccf9ad...3a34617`) does to bring up one
node, a single SHub 1 with 2 GiB of local memory and no NUMAlink peer, far enough to pass memory initialisation, and what
each hardware access has to return. It consolidates the reviewed reading in [boot-sequence.md](boot-sequence.md) and adds
a re-read of the master election, the node-id register writer and the directory initialiser. Addresses are SAL_B
addresses (base `0xffa00000`) unless stated; register addresses are SHub 1 node offsets (`0x1_xxxx_xxxx`), which the PROM
reaches as `0x81_xxxx_xxxx` (local window) or `0x8_0000_0000 + (nasid << 38) + offset` (global window). "Linux name" is a
constant in Linux v5.3 `arch/ia64/include/asm/sn/shub_mmr.h`; where there is none the register is unnamed (see
[shub-registers-unnamed](../../../questions/shub-registers-unnamed.md)).

**Grades.** *established*: the whole function was read and the statement follows from it. *inferred*: reasoned from part of
a function, a call list, a trace of the image under assumed inputs, or a name; the reasoning is given. *unknown*: not
settled. Statements marked "reviewed" were independently reviewed on [boot-sequence.md](boot-sequence.md); everything else here
has not been. No register has a published specification, so no hardware reset value is established anywhere below.

## Order of events

The progress codes (the PROM's own table, established) put the steps in this order:

| Code | Step | Section |
|---|---|---|
| (SAL_A) | node set-up and per-node election | [4](#4-processor-interface-and-node-set-up-before-memory) |
| 0x08, 0x0c | `main`, local master arbitration | [3](#3-nasid-and-role) |
| 0x0d | first init routines, including the L1 start (`sysctl_init`) | [2](#2-dimm-identity-spd-only-through-the-l1) |
| 0x0e | debug switches from the L1 | [3](#3-nasid-and-role) |
| 0x10 | processor presence from the L1 | [3](#3-nasid-and-role) |
| 0x16 | discovering memory (SPD, bank sizes) | [1](#1-memory-and-directory-md-bring-up), [2](#2-dimm-identity-spd-only-through-the-l1) |
| 0x17 | testing and initialising memory | [1](#1-memory-and-directory-md-bring-up) |
| 0x18, 0x19 | post-memory init, jump to RAM | end of this page's scope |
| 0x1c, 0x1d | node interconnect, NASIDs | [3](#3-nasid-and-role) |

The order of calls inside `main` is not the order of execution (the compiler placed blocks out of order); the order above
is the progress-code order (established) and the phase of each call (inferred where a call is not between two progress
writes).

## 1. Memory and directory (MD) bring-up

Facts in this section about the register list, the engine and the SPD bytes are the reviewed reading; the directory
initialiser and the unit assignment are new here.

**Sizing (established as the code, reviewed).** `mdir_fill_node_dimmcfg` (`0xffa77bb0`, phase 0x16) asks the L1 for the
SPD of sixteen DIMMs (four banks of four slots, device id `8 + 8*(slot&1) + 2*bank + (slot>>1)`, ids 8 to 23) and marks a
slot present on any success. A bank must have all four slots present or none ("DIMM groups must be plugged in sets of 4
DIMMs"). Bank size in MB is `64 << (density index + rank code + 2)` (the PROM's arithmetic; the SPD layout itself is not
held here, so the MB meaning is inferred). A 2 GiB node is therefore one bank of four 512 MB single-rank DIMMs (SPD byte 5
= 1, byte 31 = 0x80; inferred arithmetic) or the equivalent. With no DIMM at all the PROM stops at progress 0x80 ("No
memory on node").

**Which SHub registers the sizing reads.** Only one: `0x1_1006_0500`, bits 1:0, read at `0xffa77e0c`, select the DRAM bus
clock from a four-entry flash table (0 gives 200 MHz, 1 160, 2 133, 3 100; established, reviewed). The SPD bytes are never
read from a SHub register (section 2).

**Controller programming (established as the register list and field positions, reviewed; values depend on the DIMMs).**
`0xffa76bf0` ("Initializing memory controller") reads then writes, in the MD block (offset bits 31:28 = 0, grouped by
bits 19:16):

| Register (offset) | Access | What | Linux name |
|---|---|---|---|
| `0x1_0001_0000`, `_0008`, `_0010` | write (008 read first) | per-bank config: timing index in bits 35:32; one byte per bank at bit 8k: bits 2:0 density index (7 = empty), bit 3 rank code, bits 6:5 bank number | none |
| `0x1_0001_0020`, `_0040` | read, write | timing fields from a 32-byte flash table row; bits 7:0 = 0x02; one of bits 52, 53, 54 for tRCD 3, 2, 4 | none |
| `0x1_0001_0028`, `_0048` | read, write | six 4-bit timing fields | none |
| `0x1_0001_0030`, `_0050` | write | refresh interval 195 in bits 16:8 (overridable by the `MemoryRefresh` variable), tRFC clocks in bits 22:17, per-bank enables | none |
| `0x1_0001_0058`, `_0078` | write | constants `0x400_4e20`, `0x24` | none |
| `0x1_0001_0060` | write | `0x4047` when SHub ID revision (31:28 of `0x1_1006_0580`) is above 2, else `0x4045` | none |
| `0x1_0003_0200`..`_0270`, `0x1_0005_0200`..`_0270` | write | eight words each, all ones in the traced run; role not decoded | none |
| `0x1_0003_0400`, `0x1_0005_0400` | write | `0x1000` | none |
| `0x1_0003_0100`..`_0130`, `0x1_0005_0100`..`_0130` | write | presence vector (`mdir_create_presence_vec`, `0xffa79310`): 1, 0, 0, 0 | none |
| `0x1_0003_0300`..`_0370`, `0x1_0005_0300`..`_0370` | write | privilege vectors (`mdir_create_privilege_vecs`, `0xffa79960`) | `SH1_MD_DQLP_MMR_DIR_PRIVEC0` (`0x1_0003_0300`), `SH1_MD_DQRP_MMR_DIR_PRIVEC0` (`0x1_0005_0300`) |
| `0x1_0183_0200`, `0x1_0185_0200` | write | per-processor pair, loop of up to eight (role not decoded) | none |

The 0x0003 and 0x0005 blocks are named in the PROM's error text as the directory queue ports for "DQLP" and "DQRP"
(strings in the image, established as strings); that the two blocks are those ports is inferred from the Linux names.
Every register in the table was a plain store in the trace and was never read back for a decision (inferred, trace).

**The memory test and DRAM initialisation engine (established for the completion logic, reviewed).** One engine, started
by writing `0x1_0002_0080` (address or command word), `0x1_0000_0080` (0), `0x1_0000_00c0` (all ones), then
`0x1_0002_0088` with bit 40 (go), operation code in bits 38:32, value in bits 30:0. `0xffa6fc60` polls `0x1_0002_0088`
until `(value & 0x300_0000_0000) != 0x100_0000_0000`, with a deadline of 20,000,000 ticks of the clock at `0x1_101c_0000`
(timeout: "MBIST TIMEOUT"). After the poll the caller reads bit 41 of `0x1_0002_0088` and then bit 36 of `0x1_0000_0080` on every pass (`0xffa70290`, `0xffa702c0`);
either set is failure (-2). The error report (`0xffa72500`) reads bit 36 again and, if set, `0x1_0000_00b8`. DRAM initialisation uses the same register with operation codes 7, 2, 0, 0, 2, 1, 1, 0 for the first bank
(the command words are in [boot-sequence.md](boot-sequence.md#memory-discovery-what-is-read-and-what-an-interpreter-run-of-the-image-shows);
their DRAM meaning is inferred) and the memory test with operation codes 48 and 16. The test driver (`0xffa6f000`) reads
each bank's config byte from `0x1_0001_0010`, skips banks whose density index is 7, and honours a skip mode ("Skipping
memory test, as requested"; the controlling value is a caller argument, not read here).

**Directory initialisation (new; function read in full, meaning inferred).** `memctl_write_dir_access` (`0xffa6b060`;
the string "memctl_write_dir_access: Bist timed out" names it) stores `value << 55` to `0x1_0003_1000` and then to
`0x1_0005_1000` (global window, node in bits 38 up), runs the engine with operation code 64 and the 20,000,000-tick
deadline, and fails on timeout (-3) or bit 41 of `0x1_0002_0088`. Callers are `0xffa738d0` (in `main_two`, after the jump to RAM, so after the point
this page covers), `0xfface570` (the PROM-to-RAM copy) and `0xffb1a8c0`. So directory memory is written through the same
engine by value, with no separate ECC-initialise register seen (inferred: no other directory register is touched in the
function). The two `0x..1000` registers are unnamed.

**Block transfer zero fill (established logic, reviewed).** `memctl_mbist_credit_war` (`0xffa7a960`) programs the I/O
interface's block transfer engine 0 (IBLS0 at `0x8_01c1_0000 + (nasid << 38)`, that is II offset `0x41_0000`) with bit 20
set and polls it to clear, 2,000,000-tick deadline. The PROM never checks that memory was zeroed.

**Polling loops in this section.** (a) engine busy, `0x1_0002_0088` bit 40, 20,000,000 ticks; (b) IBLS0 bit 20,
2,000,000 ticks; (c) every delay loop compares the clock at `0x1_101c_0000`, which must advance (established that it
is read; the tick rate was not measured).

## 2. DIMM identity: SPD only through the L1

**Established.** The only path the PROM has to DIMM identity is the L1 request `0x0006` (EEPROM read): four integer
arguments, device id, selector 4, byte offset 0, length 48, built by the shared reader at `0xffa84680` (reviewed, and
confirmed here: it fixes selector 4, offset 0, length 48). The reply is status 0, an integer (the byte count) and a raw
byte string, copied into a 256-byte per-slot buffer. I found exactly one caller of `sysctl_eeprom_dimm` (`0xffa85470`,
from `0xffa7bd60`, from `mdir_fill_node_dimmcfg`); `0xffa7bd60` compares the node id (`chipset_get_nasid`) with the target
and calls the L1 reader on both branches, taking the handle from a different table slot for a node that is not the local one. No branch to a SHub register, an I2C master or a junk-bus device exists on the
path. The only other branch is the CPU ID signature (`cpuid[2] == 0xaeeeeeee8badbeef`), which returns built-in data and
is a simulator path, stated as a fact and not recommended. The L1 (ARM 1.62.1) serves device ids 8 to 13 and 16 to 21 for
the module type the L1 page calls F (an Opus TIO brick) and answers every other id as not present (from the separate reading of the L1 firmware, which
holds the id table). The PROM's ids 14, 15, 22 and 23, which make up bank 3, therefore
always fail on that brick, so bank 3 cannot be populated there (inferred from two readings).

**Bytes to configuration (established, reviewed).** The PROM uses SPD bytes 5 (ranks), 31 (density), 9, 18, 23, 25 (CAS
latency and clock), 29 (tRCD) and 42 (tRFC) of the 48 it asks for; the other bytes may be anything. Each maps to a field
of the table in section 1. A model of the L1 must return, for the four ids of bank 0 (8, 16, 9, 17), a 48-byte reply whose
byte 5 is 1 or 2, byte 31 one of 0x10, 0x20, 0x40, 0x80, 0x01, 0x02, byte 18 a supported-latency mask, bytes 9, 23, 25 the
minimum periods in the SPD coding, byte 29 tRCD, byte 42 tRFC, identical across the four DIMMs, and an error status for the
twelve other ids. The bus clock and CAS latency pair must be in the PROM's supported set (100 MHz CL 2.0; 133 MHz CL 2.0 or
2.5; 160 or 200 MHz CL 2.0, 2.5 or 3.0) or it prints "memory bus speed ... not supported". The exact layout of the SPD is
not held here; the byte numbers are those the PROM reads.

## 3. NASID and role

**NASID read (established).** `chipset_get_nasid` (`0xffa0dcf0`, read in full) is a single 64-bit load of `0x81_1006_0580`
(Linux `SH1_SHUB_ID`) followed by an extract of bits 42:32. It is the first thing `main` does (`0xffa19a4c`) and every
global-window address afterwards is formed from the value. Nothing in the path read the NI, the router or any other
register to learn the node id. So the NASID of a node at power-on is whatever this register reads, and the PROM works
with it unchanged at first (the reset value is unknown; see the table).

**NASID write (new; function read in full, role inferred).** `0xffa95a30` (a chip operation reached through a function
descriptor; one direct call at `0xffa5f84c` inside the route and number distribution path) reads `0x1_1006_0580`, replaces
bits 42:32 with its NASID argument, sets bits 45:44 to 0, 1, 2 or 3 depending on whether an argument (after masking bits
10:9 and halving) is at most 31, 63, 127 or more, sets bits 52:48 to 1, 2, 4, 8 or 16 by thresholds 63, 127, 255 and 511 on
a 16-bit argument, and writes it back. Bits 52:48 are the "nodes per bit" field the Linux header reads for the region
size ([address map](../../../platforms/sn2/address-map.md)); the meaning of the other bits is inferred only. The register
is therefore read-write with at least those three fields stored; after the write the NASID field must read back as
written.

**Which NASID a single node is given (inferred).** `intcon_assign_numbers` (starts at `0xffa4d3a0`) starts from the
node's current NASID, takes two environment variables, `NASIDOffset` (default 0) and `NASIDStride` (default 2; read only
when bit 5 of the debug-switch word is clear). Even NASIDs are SHubs. With the defaults a single node keeps NASID 0;
this is read from the default initialisations at `0xffa4d3c0` and `0xffa4d3d6` only, not from the whole function.

**Local master, progress 0x0c (read in full, meaning inferred).** `0xffa99cf0` runs right after progress 8. It
(1) reads the node id; (2) for each slice not equal to the caller's own, reads bit `slice` of `0x1_2002_0080` through
`0xffa11560` (a per-slice presence bit; the meaning is inferred from use) and builds a mask and a count of other
present processors; (3) sets bit `26 + slice` of the scratch word `0x1_5003_1550` for the running processor
(`0xffa0eae0`, a read-modify-write under the lock at `0x1_101d_0200` and `_0208`); (4) waits, in 500-tick steps up to 5,000,000
ticks, until those bits are set for every other present processor; (5) later `0xffa0ff30` returns 1 for the processor
whose number is lowest among the set bits (reviewed). With no other processor present the loop ends at once and the
single processor is the node's master. The lock is taken by reading `0x1_101d_0208` and treating zero as acquired (retry
with a back-off until a deadline of 1,000,000 ticks, after which it writes zero to `0x1_101d_0200` and keeps polling), released by
writing zero to `0x1_101d_0200` (`0xffa0ed30`, `0xffa0ee40`; the
function that sets the bit under the lock is `0xffa0e740`). Whether a read of the register has a side effect in the
chip is unknown; a plain register that always reads zero satisfies the code.

**Node election before that (reviewed).** SAL_A writes `0x1_101d_0088` and reads `0x1_101d_0080`; the single processor
must read back what it wrote at `0x88`. The relation of the two registers is unknown ([boot-sequence.md](boot-sequence.md#sal_a-on-shub-1)).

**Role from the system controller.** The PROM does not decide master role from a NUMAlink register. Single-node
discovery depends on bit 11 of the debug-switch word the L1 returns for request `0x0001`. A blank L1 returns 0
(sysco L1 settings note, reviewed), so the PROM takes the route that reads the node's own NI registers, below. Processor
presence comes from request `0x0010` (the presence word must have bit 0 set or the PROM stops at 0x87).

**NI reads with no link (reviewed, established).** Per port p = 0, 1, `shub_port_status` reads
`0x1_5000_0048 + p*0x2000` (if bit 27 is set it writes the value back with bit 27 clear and reads again; still set means
no link and no message), then `0x1_5000_0000 + p*0x2000`, whose bits 3:0 must be 9 for a link. Any other value fails the
port with "shub_port_status ... failed" and discovery goes on. `0x1_5000_1040 + p*0x2000 + 16*i` (i = 0 to 3) is read
only after nibble 9, re-reading while bits 22:16 are zero and failing after 128 zero reads; with no link it is not
reached. A no-peer model therefore returns anything but 9 in bits 3:0 of `0x1_5000_0000` and `0x1_5000_2000`, and a value
with bit 27 clear in `0x1_5000_0048` and `0x1_5000_2048`. If a model returned 9 it would have to answer the
`0x1_5000_1040` registers with a non-zero bits 22:16 within 128 reads. Both ports "not connected" makes the crawl visit
nothing and the one-entry record is the node itself, with the same continuation as the skip route (inferred, reviewed).
The word at `0x1_101d_0080` is read by the chip operation at `0xffa959d0` and, if zero, discovery prepares it with bit 39
set and bits 55:54 (the link mask) left 0.

## 4. Processor interface and node set-up before memory

The PROM's early writes to the processor-interface (PI, offset bits 31:28 = 2) and local-block registers, none read back
for a decision except where noted:

| Register | When | Access | Linux name |
|---|---|---|---|
| `0x1_1002_0000` | SAL_A | write `0x15031010` | none |
| `0x1_2001_0100` | SAL_A | read-modify-write, set bit 24 (value unused) | none |
| `0x1_1006_0480` | SAL_A, election winner | write 1 | `SH1_IPI_ACCESS` |
| `0x1_5003_1550`, `_1540`, `_1560` | SAL_A, winner | write 0 | none |
| `0x1_101d_0100` | SAL_A, winner | set bits 41:39 to 7; later read by the L1 UART start | none |
| `0x1_5003_1500 + 16*n`, `_1510`, `_1530` | every progress code | shift-in of the code (read, write) | none |
| `0x7_fed0_0000 + n*0x10000` | every progress code | 16-bit LED write | `SH1_REAL_JUNK_BUS_LED0` to `LED3` (`0x7_fed0_0000` and `+0x10000` steps) |
| `0x1_2000_0000`, `0x1_2001_0100` | error path and `0xffa976e0` (call site not located) | set `0x1_2001_0100` bit 24, run a chip operation, OR `0x3b03f7` (revision above 2) or `0x3f1` (1009, otherwise) into `0x1_2000_0000`, write back, clear bit 24 | none |
| `0x1_2005_0300`, `0x1_2000_0180`, `0x1_2006_0100`, `_0180`, `_0200` | `0xffa24510`, `0xffa245f0`, `0xffa25460` (reached through tables; order not located) | write low 7 bits of an argument with bit 63 to `0x1_2005_0300`, OR bit 63 into `0x1_2000_0180`; read the three `0x1_2006_xxxx` registers | `SH1_PI_CAM_CONTROL` (`0x1_2005_0300`) |
| `0x1_1005_0608` then `0x1_2007_0200` | `pio_wt_st_force_err` (`0xffa24cc0`, early in `main_two`) | store, then spin until bit 0 or bit 2 of the status is set; clear through the alias at `0x..0208` | `SH1_PIO_WRITE_STATUS_0` and `_ALIAS` |

The graded parts: the SAL_A rows and the progress rows are established (reviewed). The `0xffa976e0` row is established as
code; that it re-arms an error mask is inferred from the progress codes 0x59 and 0x5a it writes and the revision split
(the same split as `0x4047` and `0x4045` in section 1, suggesting two chip revisions with different error bit sets).
The PI rows through tables are established as accesses and unknown as to when they run and what the bits mean.

**What the PI setup needs to allow (inferred).** Nothing the PROM does before memory depends on a value read from
PI registers except `0x1_2002_0080` (section 3) and the PIO status self test in `main_two`. The memory is reached
by the processor through the normal cached path once the controller is programmed; there is no PI address-decode write
in the list above, so the node's memory window must already decode at reset (inferred; the only memory the PROM
uses before the controller is up is RAM-less cache preload at `0x1000000`, see [boot-sequence.md](boot-sequence.md#memory-discovery)).

## What a single-node model must return

| Register (offset) | Read site | Required value or behaviour | Grade |
|---|---|---|---|
| `0x1_0000_0000` chip identification | `chipset_init_chip` `0xffa0f8c0` | bounded read must not fault; part number (value >> 12, 16 bits) 17251 = `0x4363`; revision in bits 31:28 | established (check at `0xffa959a6`) |
| `0x1_1006_0580` SHub ID (`SH1_SHUB_ID`) | `0xffa0dcf0` and about 15 more sites | read-write; bits 42:32 NASID (any value at reset; must read back what `0xffa95a30` writes); bits 31:28 revision (3 in the trace; above 2 selects the `0x4047` and `0x3b03f7` values); bits 52:48 and 45:44 stored | established as reads and writes; reset value unknown |
| `0x1_1006_0500` | `0xffa77e0c` | bits 1:0 = 0 (200 MHz) or 1 to 3; must be a supported pair with the DIMM CAS | established |
| `0x1_0001_00xx`, `0x1_0003_xxxx`, `0x1_0005_xxxx`, `0x1_0183_0200`, `0x1_0185_0200` | `0xffa76bf0` | store what is written; zero before the first store | inferred (trace) |
| `0x1_0002_0088` MBIST control | `0xffa6fc60`, `0xffa6fb30` | after a write with bit 40 set, bit 40 reads 0 within 20,000,000 clock ticks; bit 41 never set | established (logic), inferred (hardware) |
| `0x1_0002_0080`, `0x1_0000_0080`, `0x1_0000_00c0` | `0xffa6fb30` | plain storage; bit 36 of `0x1_0000_0080` is read after every engine run in the memory test and must read 0 (set is failure) | established |
| `0x1_0003_1000`, `0x1_0005_1000` | `0xffa6b060` | plain storage; engine completes as above | established |
| IBLS0 `0x8_01c1_0000` | `0xffa7a960` | bit 20 reads 0 after a write with it set | established |
| `0x1_101c_0000` RTC (`SH1_RTC`) | every delay loop | monotonically advancing 55-bit counter | established |
| `0x1_101d_0080`, `0x1_101d_0088` | SAL_A | reading `0x80` after writing `0x88` returns what was written (slice + 1) | established as the test; relation unknown |
| `0x1_101d_0100` | L1 UART start | bits 41:39 read 7 after SAL_A set them | established |
| `0x1_101d_0208` read, `0x1_101d_0200` write | `0xffa0ed30` | the read at `_0208` returns 0 (lock free); writes of 0 to `_0200` accepted | established as the test; read side effect unknown |
| `0x1_5003_1500`..`_1590` scratch | all progress and master code | plain 64-bit storage; zero at start | inferred (what the PROM reads is what it wrote) |
| `0x1_2002_0080` | `0xffa11560` | bit n = 0 for each slice other than the PROM's own, or 1 where a second processor exists | inferred (meaning) |
| `0x1_2007_0200` PIO status | `0xffa24cc0` | bit 0 or 2 set after the forcing store, count field all ones when idle, cleared by a write to the alias | inferred (trace) |
| `0x1_5000_0000`, `0x1_5000_2000` (NI ports) | `0xffa5cf40` | bits 3:0 not 9 | established (reviewed) |
| `0x1_5000_0048`, `0x1_5000_2048` | `0xffa5cf40` | bit 27 clear | established (reviewed) |
| `0x1_5000_1040`, `+0x2000` | not reached | only with nibble 9: bits 22:16 non-zero within 128 reads | established (reviewed) |
| `0x7_fed0_0000 + n*0x10000` LEDs | every progress code | writes accepted | established |
| L1 `0x0001` debug switches | phase 0x0e | any non-negative integer; bit 11 set skips NUMAlink discovery, 0 reads the NI | established (reviewed) |
| L1 `0x0010` presence | phase 0x10 | presence word bit 0 set | established (reviewed) |
| L1 `0x0006` DIMM read | phase 0x16 | four consistent 48-byte SPDs for ids 8, 16, 9, 17; error for the other twelve ids | established (reviewed) |

## Unknowns

- Reset value and any side effect on read of `0x1_1006_0580`, `0x1_101d_0208`, `0x1_101d_0080` and `0x88`.
- Where and when the PI table-called functions and `0xffa976e0` run, and what their bits mean.
- The role of the `0x1_0003_0200` and `0x1_0183_0200` families, and of the `0x1_0001_00xx` per-bank values beyond field
  positions; the DRAM command meaning of the engine operation codes.
- Which NASID `intcon_assign_numbers` finally writes for one node (the default reading says 0, whole function unread).
- Whether the real L1 returns SPD for ids 14, 15, 22, 23 on any brick type.

## Review

Independent review of `node-bringup.md` as committed in chips `c5b1e2e`. The reviewer wrote none of it. Method: the SAL_B image `shub1snprom.bin` (SAL 5.04, sha256 `51ccf9ad...3a34617`, base `0xffa00000`) was disassembled with `ia64-linux-gnu-objdump` through the retools container and every "must return" row was re-read at its read site, with the branch on each polarity followed to the other value. Linux v5.3 `arch/ia64/include/asm/sn/shub_mmr.h`, `arch/ia64/sn/kernel/setup.c`, `arch/ia64/include/asm/sn/addrs.h` and `arch/ia64/sn/kernel/sn2/sn_hwperf.c` were fetched as single files for the grades. The sysco page `software/firmware/l1/sn2-prom-link-1.62.1.md` was read for the L1 device-id table. No PROM bytes or listings are kept.

**Confirmed (re-read in the binary).**

- `chipset_get_nasid` (`0xffa0dcf0`): one 64-bit load of `0x81_1006_0580` with the interrupt-collection state saved and restored, then `extr.u` of bits 42:32. Revision test: `0xffa962b0` and `0xffa77390` extract bits 31:28 and branch on `2 < rev` (unsigned), selecting `0x3b03f7` against `1009` and `0x4047` against `0x4045`.
- `0x1_1006_0500` bits 1:0 (`0xffa77e0c`): `and r8=3`, index into a table of 16-bit words that holds 200, 160, 133, 100 (checked at the table). Any of the four values is accepted; what changes is the timing-index map `0xffa76630`: 100 MHz maps only CL 2.0; 133 MHz CL 2.0 and 2.5; 160 and 200 MHz all three, others give a printed warning ("not supported", "timing parameters unknown") and the run goes on. The "supported set" sentence on this page is therefore right as a statement of what avoids the warning.
- Engine poll `0xffa6fc60`: the first loop leaves when bits 41:40 of `0x1_0002_0088` are not `01`; bit 40 set with bit 41 clear is busy. After the exit the register is read again: bit 40 clear returns 0; bit 40 still set (bits 41:40 = `11`) is written back with bit 40 cleared and bit 40 is polled to clear, with the same deadline. A timeout in either loop returns -3. The default deadline `0x1312d00` (20,000,000) is used when the timeout argument is zero. The go word is `(value & 0x7fffffff) | op << 32 | bit 40`, preceded by stores to `0x1_0002_0080`, `0x1_0000_0080` (0) and `0x1_0000_00c0` (all ones). So a register that never clears bit 40 gives "MBIST TIMEOUT" after the deadline; a register that clears it at once and never sets bit 41 passes.
- `memctl_write_dir_access` (`0xffa6b060`): `value << 55` stored to `0x1_0003_1000` and `0x1_0005_1000` of the node, engine operation 64, deadline `0x1312d00`, failure on -3 or bit 41. It does not test bit 36 of `0x1_0000_0080` (only operation 16 does).
- Block transfer zero fill (`0xffa7a960`): IBLS0 at `0x8_01c1_0000 | nasid << 38`, written with bit 20 plus a length, polled with `(value & 0x100000) == 0` to leave, deadline now + 2,000,000. Polarity as the page says: bit 20 must read 0.
- SPD path: `0xffa85470` has one direct caller (`0xffa7bef0`, in `0xffa7bd60`), `0xffa7bd60` has one (`0xffa77cd0`), `0xffa84680` has one (`0xffa854f0`). None of the three has a function descriptor anywhere in the image (searched for the eight-byte address), so there is no indirect route. `0xffa84680` fixes selector 4, offset 0 and length 48 (the request carries at most 64 bytes per chunk; I saw no SPD checksum test in the reader). The device id is `8 + 8*(slot & 1) + 2*bank + (slot >> 1)` (outer loop bank, inner loop slot, checked at `0xffa85480`), giving 8, 16, 9, 17 for bank 0 and 14, 22, 15, 23 for bank 3. The L1 table in the sysco page serves 8 to 13 and 16 to 21 and answers every other id as not present.
- SPD bytes: `0xffa7b1b0` maps byte 31 (`0x10`, `0x20`, `0x40`, `0x80`, `0x01`, `0x02`, anything else is 7, empty) to density index 0 to 5 and takes the minimum over the four slots; `0xffa7b310` maps byte 5 (1 to rank code 0, 2 to rank code 1, anything else -1) and requires all four slots to agree; `0xffa7afd0` uses byte 18 bits 4, 3, 2 (CL 3.0, 2.5, 2.0) with bytes 9, 23, 25 against the bus period code (`0x75` at 133 MHz, `0xa0` at 100, `0x63` at 160, `0x50` at 200; `0xffa7b7e0`). Bank size `64 << (index + rank code + 2)` MB: index 3 and rank code 0 gives 2048 MB for four DIMMs, as the page says. The simulator path (`0xffa7b940`, reached only from the CPU ID test) fabricates SPD data and is not on the real path.
- Local master `0xffa99cf0`: `0xffa11560(nasid, slice)` reads `0x9_2002_0080 | nasid << 38` (so offset `0x1_2002_0080`) and returns `(value >> slice) & 1`; a set bit counts the slice as present, and the PROM's own slice is counted without a read. The loops on `0x1_5003_1550` are as described: the processor sets bit `26 + slice` under the lock, waits in 500-step delays up to 5,000,000 and goes on after the deadline.
- Lock: read of `0x1_101d_0208`, zero is acquired; release is a store of zero to `0x1_101d_0200` (`0xffa0ee40`). See the fix below.
- SAL_A election (`0xffc4e970`): the processor stores slice + 1 (CR.LID bits 26:23, plus one) to `0x1_101d_0088`, reads `0x1_101d_0080`, and is the winner only if the two are equal; the winner zeroes `0x1_5003_1550`, `_1540`, `_1560` and writes 1 to `0x1_1006_0480`. `0xffc4e740` (the winner) read-modify-writes `0x1_101d_0100` bits 41:39 to 7.
- NI port status `0xffa5cf40`: `0x1_5000_0048 + p*0x2000` bit 27 handled as the page says. Return values are 1 (link up), 0 (bit 27 still set after the clear write, no message) and -1 (nibble not 9, read error, or 128 zero reads of the `0x1_5000_1040` field). The port-mask builder (`0xffa5d6a0`) ORs the result in for results of zero or more, and on -1 prints and goes to the next port.
- `0xffa95a30`: read-modify-write of `0x1_1006_0580`, bits 42:32 replaced by the second argument, bits 45:44 set to 0, 1, 2, 3 by 31, 63, 127 on the third argument (after clearing bits 10:9 and halving), bits 52:48 to 1, 2, 4, 8, 16 by 63, 127, 255, 511 on the fourth.
- Chip identification check (`0xffa959a0`): zero-extends a 16-bit argument and returns 1 for 17251 (`0x4363`), else 0; `chipset_init_chip` stores bits 27:12 of the read of `0x1_0000_0000` as the part number and bits 31:28 as the revision.

**Mechanical fixes made in this review (this page).**

1. The lock read is at `0x1_101d_0208`, not `0x1_101d_0200`. `0xffa0ed30` reads its first argument (callers pass `_0208`) and writes zero to its second (`_0200`), both on release and when its one-second deadline expires. The text, the table row and the unknowns list now say so.
2. Bit 36 of `0x1_0000_0080` is read after every engine run in the memory-test loop (`0xffa702c0`, failure if set), not only in the error report; the table row and the engine paragraph say so. The error report (`0xffa72500`) reads it again and then `0x1_0000_00b8`.
3. `0xffa7bd60` calls the L1 reader on both the local and the remote branch (different handle); the page said only the local branch.
4. The L1 id table is for the module type the sysco page names F (an Opus TIO brick), not a "compute brick".
5. The LEDs at `0x7_fed0_0000 + n*0x10000` have Linux names, `SH1_REAL_JUNK_BUS_LED0` to `LED3` (`0x7fed00000UL` and steps of `0x10000`); the page said none.

**Findings not fixed.**

1. Time units. Every deadline on this page (20,000,000; 2,000,000; 1,000,000; 5,000,000; the 500 steps) is in microseconds, not RTC ticks. `0xffa0da70` converts the RTC count to microseconds with a period read from `0x1_1006_0280` bits 13:4 (`0xffa0da00`: nanoseconds = 10 * field + 10, then count * nanoseconds / 1000), and the delay routine (`0xffa0db90`) scales its argument back the same way. The page's "tick rate was not measured" and the `SH1_RTC` row need a companion row for `0x1_1006_0280` (unnamed in Linux v5.3): with a read of zero the PROM assumes a 10 ns RTC period, so the RTC must advance at 100 MHz or every deadline stretches by the ratio. Established as code; the register's meaning is inferred.
2. Block transfer is conditional. `0xffa7a960` loops over the four banks of the node's configuration, takes the first bank whose flag word has bit 0 set (halfword at `+4 + 8*bank` of a structure passed in) and zero-fills only that one; if no bank is flagged it returns without touching IBLS0. On timeout it prints and re-issues the transfer with no exit. The flag's origin, and so when a single node with one bank is flagged, was not traced.
3. NASID assignment is not settled. The page's "default reading says 0" holds as far as I read: `0xffa4d3a0` to `0xffa4eb40` reads `NASIDOffset` (default 0) and `NASIDStride` (default 2) at `0xffa4e980` to `0xffa4eb30` only when bit 5 of the debug-switch word is clear. Nodes whose record flag at `+91` bit 0 is set are first converted to numbers by `(nasid - offset) / stride` (signed divide at `0xffa149c0`) and mark that number used; new numbers are the lowest free value stepping by 2 (SHubs even), and the NASID stored in the record is `number * stride + offset | (number & 1)` (`0xffa4e070`). So the first SHub with nothing preassigned gets number 0 and NASID 0. This function does not write `0x1_1006_0580`; the one direct call of the writer (`0xffa5f840`, inside `0xffa5e880`) passes the first halfword of that function's first argument as the NASID, so a single node ends up with whatever id its handle carries. I did not read `0xffa4e0a0` to `0xffa4e850` or the construction of the handle, so whether a power-on NASID other than 0 is renumbered is unknown. A model that reads zero at reset avoids the question.
4. `0x1_101d_0100`. The write of bits 41:39 = 7 by the SAL_A winner is confirmed. I found no reader that tests those bits for 7 and ties them to the L1 UART start: the SAL_B reader I found (`0xffa94460`) takes bits 15:8, and the functions that compare a 3-bit field at bit 39 with 7 (`0xffa93c70`, `0xffa8c400`) read registers built from a computed address and were not shown to be this one. The "must read 7" requirement is unconfirmed, and the row's grade is inferred, not established. A plain storage register satisfies it either way.
5. NI no-link route. A model that leaves bit 27 of `0x1_5000_0048` stuck set also works and is quieter (result 0, no message); the page requires bit 27 clear and nibble not 9, which is the noisier route (result -1, "failed" message, discovery goes on). Both are valid.
6. Master wait. Each present slice publishes a 3-bit count at bit 47 (even slice) or bit 50 (odd slice) of `0x1_5003_1550`, taken from PAL procedure 42 (`0xffa9ae00`: 1 if the call returns -1, else bits 39:32 of the second return); the processor waits for that many ready bits among 29:26. A model whose PAL reports more threads than run only costs the 5,000,000 microseconds, then continues. The slice number is CR.LID bits 26:23 everywhere (LED address, scratch index, election value), which the page does not state. `0x1_2002_0080` is also read by four callers of `0xffa115e0` (`0xffac6340` and three more, a CPU enumeration) with bits 0, 1 for the first processor of slice 0, 1 and bits 4, 5 for the second; the own-slice bit those callers expect was not traced, so a model should set it.
7. Grades against Linux v5.3. Linux defines `SH1_SHUB_ID` only with the revision field (31:28), `SH1_RTC` with a 55-bit mask, `SH1_IPI_ACCESS`, `SH1_PI_CAM_CONTROL`, `SH1_PIO_WRITE_STATUS_0` with its deadlock bit (1) and pending-count field (bit 56), the privilege-vector bases and the LEDs. It does not define the NASID field (42:32) of the ID register (Linux takes the NASID from the system firmware), the bus-clock field of `0x1_1006_0500`, the memory-test engine at `0x1_0002_0088` and its bits, or the lock registers. Where the page says established for these it means what the code does at the access, not the register's meaning; the meaning is inferred, and a clean-room reader should treat NASID, bus clock and the engine's go and fail bits as inferred unless a document is found.
8. The chip-identification check's caller (the function at `0xffa959a0` is reached through a function-descriptor table) was not found, so whether a part number other than `0x4363` stops the PROM is not shown.
9. The progress-code order table and the `0x87` presence stop were not re-read.

**Not checked.** The PI-table functions in section 4 and the `0x1_2007_0200` status handling; the `0xffa0ff30` lowest-processor rule; DRAM initialisation operation codes and the timing-table rows other than the index map; the full `0xffa4d3a0` function; how the L1 handle for a remote node is built; the `0xffa976e0` error-mask path; progress codes 0x0d, 0x0e, 0x10.

**Cleared scope.** The register reads and polarities for `0x1_1006_0580` (read side), `0x1_1006_0500`, `0x1_0002_0088`, `0x1_0002_0080`, `0x1_0000_0080`, `0x1_0003_1000`, `0x1_0005_1000`, IBLS0, `0x1_101d_0080` and `_0088`, the lock addresses as corrected, `0x1_5003_1550`, `0x1_2002_0080` for non-own slices, `0x1_5000_0000`, `_0048`, `_1040` and their `+0x2000` copies; the SPD path, byte list, id formula and the L1 id range; the register-write layout of `0xffa95a30`. Not cleared: the NASID reset behaviour, the `0x1_101d_0100` requirement, the time-unit statements in the page (superseded by finding 1), the conditional zero fill, and every meaning graded established that Linux v5.3 does not define (finding 7).
