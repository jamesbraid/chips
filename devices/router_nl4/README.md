# NUMAlink 4 router (R-brick, CR-brick, Dense router module, IRU routers)

The NUMAlink 4 router is the eight-port crossbar that joins SHub 2 and TIO nodes in the later Altix machines. It has no
memory window: a node reaches its registers only by sending a "vector" request along a route, through the vector
registers of the node's own SHub ([node-access.md](node-access.md)). Register numbers, names and bit ranges are in
[registers.toml](registers.toml) and the generated [registers.md](registers.md). This page says where each fact comes
from and what is still unknown. The older Origin 3000 router is in [../router/README.md](../router/README.md) and
[../router_sn1/registers.md](../router_sn1/registers.md); the Altix 3000 router brick carries a chip of that family
(see "Generations").

Grades follow [AGENTS.md](../../AGENTS.md): **established** (read in full from a shipped binary, or defined by SGI's own
Linux platform code or a published manual), **inferred** (reasoned, reasoning given), **unknown**.

## Sources and what each gave

- **SGI's Linux platform code** (Linux v5.3, `arch/ia64/sn/kernel/sn2/sn_hwperf.c`,
  `arch/ia64/include/asm/sn/sn2/sn_hwperf.h`, `arch/ia64/include/asm/sn/sn_sal.h`,
  `arch/ia64/include/asm/sn/klconfig.h`, `arch/ia64/include/asm/sn/module.h`, `arch/ia64/include/asm/sn/shub_mmr.h`,
  `arch/ia64/include/asm/sn/geo.h`). Result: the kernel never reads a router register. It sees routers only as
  objects the firmware reports. No register offset of the router or of the node's network interface is defined in
  the kernel headers (the 502-line `shub_mmr.h` has none, and the 2.6.24 `shubio.h` defines only the I/O interface's
  own link registers). Everything register-level below therefore comes from the PROM.
- **Published manuals** (techpubs 007-4823-001 Altix 4700 guide pp.61, 65, 66; 007-4579-001 Altix 3000 guide pp.135
  and 140; the CR-brick and Altix 350 pages already in [../../platforms/sn2/](../../platforms/sn2/README.md)). Result:
  product and port facts only. No manual held states a router register.
- **The held SN2 PROM images** (SNPROM 10.54 build 70399, both the SHub 1 and the SHub 2 image; 10.40, 10.11, 4.43
  checked for the same strings). Each carries the register description tables its error and dump code uses, one table
  per chip family. The NUMAlink 4 router's table (names prefixed `R4_`) gives 242 register groups, 753 registers
  counting the eight ports, with every field's bit range. I parsed the record layout by hand (see below), decoded the
  SHub 2 vector send routine with Ghidra (`--sn2-prom`) and checked every constant in it against objdump. Ghidra
  readings are the vector routine and the chip-match functions; the table parse is plain Python over the image.

The register description table (established as a structure, read in full): a register record is a 16-byte entry (name
offset, first field index, field count, register number); a field record is 8 bytes (name offset, high bit, low bit,
flags). 753 registers parse with no gap, and the first register's 25 fields end exactly where the second begins.
Names come from a string pool in the same image.

Flag values carried by the fields (inferred from the fields that carry each): 0 reserved; 1 read-only status; 0xb
read-write; 7 read-write with a bit that looks self-clearing or arming (the test-control and capture-arm bits, the
`START` bit of the vector request); 9 read-only alias of a status register; 8 and 0xf the scratch alias variants. The
register lists in registers.toml turn this into `r` or `rw`.

## Generations (what the "R-brick" family is)

| Router | Part number (bits 27:12 of register 0) | Where | Grade |
|---|---|---|---|
| Origin 3000 router (IP35 family) | `0x3017` | Origin 3000 R-brick; the SHub 1 PROM also carries a match function for this value, and the PROM has an `NL3router` name | the value established in both sets of binaries; that the Altix 3000 R-brick carries the same chip is inferred from the identical value and the guide's "router chip, eight-port crossbar" (007-4579-001 p.135) |
| NUMAlink 4 router | `0x239` (569) | Altix 350 router option, 3700 Bx2 CR-brick, 4700 and 450 IRU routers, Dense router module | established: the PROM's per-chip match function compares the identification halfword with 569 and its name entry is `NL4router` |

The PROM dispatches on the chip identification word through a table of per-chip method tables. The SHub 2 images
hold three entries (SHub 2, `0x239`, TIO `0x4422`); the SHub 1 images hold four (SHub 1 `0x4363`, `0x3017`, `0x239`,
`0x4422`). Read in full: the three compare constants in the SHub 2 image and the name each entry returns; the SHub 1
compare constants were located but its name entries were not read, so the pairing of `0x3017` with `NL3router` there is
inferred from the strings.

The NUMAlink 3 router's own register table (`RR_` names) is in the SHub 1 images. Its numbers match the public Origin
3000 router header positions already recorded in [../router_sn1/registers.toml](../router_sn1/registers.toml): global
registers at `0x0` to `0x48` (status/revision, port reset, protection configuration, global port definition, global
parameters, diagnostic parameters, debug address, `LB_TO_L2` at `0x40`, `L2_TO_LB` at `0x48`), the hardware barrier at
`0x8000`, and per-port blocks at `((L+1) & 0xe) << 15 | ((L+1) & 1) << 11` for link L = 1 to 8 (parameters, status and
error, channel test at `+0x10`, reset mask at `+0x18`, histograms at `+0x20` to `+0x38`, error clear at `+0x88`, global
table at `+0x100`, local table at `+0x200`). Established as a table of names and numbers; no field-level read of that
table was made.

## How software reaches the router

**Linux (established).** There is no router driver and no router MMIO. `sn_hwperf.c` asks the firmware for a list of
objects with the SAL call `SN_SAL_HWPERF_OP` (`0x02000050`) and prints them in `/proc/sgi_sn/sn_topology`. An object
is a 128-byte name, a 128-byte location string, flags (belongs to this partition, shared) and a port count. Routers
are recognised by name only: a name containing `NL4Router` is a NUMAlink 4 router, `NL3Router` a NUMAlink 3 router and
any other name with `Router` an old one. For each object `SN_HWPERF_ENUM_PORTS` returns an array of
{port, connected object id, connected port}. A node's ports and a router's ports are walked the same way, which is how
the kernel finds the router next to a node and the nodes behind it (the nearest-node search). Link protocol is printed
as `LLP3` when either end is an NL3 router and `LLP4` otherwise; the kernel's own comment says it does not read the link
configuration registers, because a NUMAlink 4 router can be configured to speak the NUMAlink 3 protocol.
Router locations use the same geoid text as nodes (`rack`, brick-type letter, bay, with `^slot` on bladed systems).
`SN_HWPERF_GET_MMRS` and `SET_MMRS` take an object id and an array of {address, data} pairs and are executed by the
firmware; what an address means for a router object is not defined in the kernel. **unknown**.

`SN_SAL_IROUTER_OP` (`0x02000043`) is not the NUMAlink router. "IRouter" there is the generalised system controller
channel (open, close, send and receive subchannel packets to the L1 and L2). Do not read the name as router
registers (`sn_sal.h`, established).

**Kernel's view of brick type (established, `klconfig.h` and `module.h`, v5.3).** Router boards are class `0x30`:
`KLTYPE_ROUTER 0x31`, `KLTYPE_META_ROUTER 0x33`, `KLTYPE_REPEATER_ROUTER 0x34`; the module brick-type list has
`MODULE_RBRICK` as type 1. Whether SN2 kernels use these classes for the Altix routers: no use was found in the files
read; the header is shared with the Origin 3000 era. **unknown** for SN2.

**Firmware (established, SHub 2 PROM).** The PROM sends vector requests with its own routine, described in
[node-access.md](node-access.md). One routine does both a node-local read (route 0, a plain read of the node's own
global MMR window) and a read across routers (nonzero route). Route layout, status codes and the lock are there.

## Router address space (established as a map; roles inferred from names)

The register number is the 32-bit value that goes in the `ADDRESS` field of the vector request (bits 34:3 of the
request, see node-access.md). The table shows these blocks:

The register number's bits 27:24 select a block in every register the table lists (established as a pattern of the
numbers; that they are hardware block selects is inferred): 0 the router's local block, 1 the global and debug
registers, 2 the arbiters, 8 to 15 ports A to H.

| Number range | Contents | Grade |
|---|---|---|
| `0x0` to `0x48` | status and revision (`0x0`), global parameters 0 and 1 (`0x10`, `0x20`), the L1 mailbox: `ASIC_TO_L1_STATUS` (`0x30`), `ASIC_TO_L1_DATA` (`0x38`), `L1_TO_ASIC_STATUS` (`0x40`), `L1_TO_ASIC_DATA` (`0x48`) | numbers established; role inferred |
| `0x1000` to `0x1098` | ten scratch registers, each followed by an alias one doubleword up | established; the aliases look like write-zero and set-zero variants (the SHub 1 table's `RR_SCRATCH_REG0_WZ` and `_SZ` names are the NUMAlink 3 equivalent), inferred |
| `0x2000` to `0x2060`, `0x2700` | local-block first-error and error registers, the local-block test-point select | established |
| `0x4000` to `0x6000` | local-block dateline and pre-age, `PIO_TIME_OUT` (`0x4020`), 16 multicast translation entries (`0x4e00` to `0x4e78`), multicast destination table, reply-gather buffer and configuration, four destination vectors, then the local and global routing tables at `0x5000` and `0x6000` | established; "local block" read as the router's own port, inferred |
| `0x1001900` to `0x1001938` | real-time-clock source and control, throttle interval, time, status and skip, debug-port configuration, v-bit emulation | established |
| `0x1003000` to `0x1003100` | hard, soft and port reset, protection configuration, per-port reset masks at `0x1003020 + 8 * port`, port performance window | established |
| `0x1004000` to `0x1008080`, `0x1100000` to `0x1190080` | trigger and sampling facility, test-point selects and compares, debug data, stop-clock control, performance-profile and trigger-pattern registers | established; diagnostic, no guest use found |
| `0x2000010` to `0x2000680` | per-port virtual-channel credit initial counts (four channels per port, and for the two arbiters), ageing rates, throttle enables | established |
| `0x8000000 + 0x1000000 * port` | the eight port blocks, A to H (below); the PROM's port number n = 1 to 8 gives block `0x7000000 + n * 0x1000000` | established |

Port block (offsets from the port base, established): local routing table `+0x0`, global routing table `+0x1000`,
neighbour table `+0x1800`, parameters `+0x1840`, spray direction and four spray command masks `+0x1848` to `+0x1868`,
link-layer configuration `+0x1888`, test control `+0x1890`, link state `+0x1898`, the two error words `+0x18a0` and
`+0x18a8`, capture words `+0x18b0` to `+0x18c0`, credit `+0x18c8`, debit `+0x18d0`, credit state `+0x18d8`, packet
count `+0x18e0`; error summary, first error, report mask `+0x2200` to `+0x2218`, error detail `+0x2000`, detail clear
`+0x2100`; test-point select `+0x2700`; performance configuration `+0x7000` with 37 counters to `+0x7138`.

Table sizes are **inferred** from the gaps to the next register: the local table 512 doublewords (`+0x0` to `+0x1000`),
the global table 256, the neighbour table 8. The PROM text "Local Table:" and the table dumps are consistent with that
but no loop bound was read.

Routing table entries (established for the fields): local and global tables hold `VALID` (bit 63) and a direction
field (`DIR0`, bits 4:0, in the port tables); the local-block tables use `DIR1`; the neighbour table holds `VALID` and
a 14-bit `NEIGHBOR_ID` (bits 13:0), which is as wide as a NASID the Altix address map allows. What a direction value
selects (a port number 0 to 7, plus codes for the local block and for "no route") is **unknown**: no loop that writes
the tables was read.

## Identity and link reads

- **Register 0 (established, field positions; both PROM readings).** `CHIP_REVISION` bits 31:28, `PART_NUMBER` 27:12,
  `MFG_ID` 11:1, bit 0 reads as 1 (named `FORCE1`). The PROM's link check reads this word with a vector read and stores
  bits 27:12 and 31:28 as the chip's part number and revision, then picks the chip's method table
  from the part number. The same word carries `PORTA_LINK_UP` to `PORTH_LINK_UP` at bits 32 to 39, `INPORT` 43:40 (the
  port the request came in on, inferred), `POSITION` 47:44, per-port error flags `PORTA_ERROR` to `PORTH_ERROR` at bits
  48 to 55, `LB_ERROR` 56 and `LOCAL_POK` 57 (power ok, inferred). A router model must return `0x239` in bits 27:12 or
  the PROM treats the object as an unknown chip.
- **Revision.** The PROM prints it as `Chiprev=%d`. No value is checked against a minimum in the functions read.
- **Router serial number ("NIC").** The PROM console has a command to read the router NIC and prints
  `rtr_box_nic` and `rtr_mfg_nic` words for a router, so a serial-number device exists. No NUMAlink 4 register is
  named for it (the Origin 3000 router did it through its debug address register `0x38`); the path is **unknown**. It
  is probably through the L1 mailbox registers above or through the L1 itself, which a Dense router module has (007-4823-001 p.61).
- **Link state seen from a node.** A node's link is up when its LLP state field `LINK_RESET_STATE` reads 9 (inferred
  from the SHub 1 PROM's use: it is the only value that lets the port continue; the field is named in the PROM
  table). The router's own view is `LLP_STATE` in each port block (send and receive finite-state machine states and
  `LINK_RESET_STATE`) and the link-up bits in register 0. **The encodings of the state fields are unknown.**

## Router addressing (what a node puts in the request)

Established from the SHub 2 PROM's vector routine (constants cross-checked): the request carries a 64-bit route of
sixteen 4-bit nibbles. The routine takes the first nibble, subtracts one and puts the result in the request's `NI_PORT`
bit, so the first nibble is 1 or 2, the node's network port number 1 or 2 (it has two; `SH*_NI0` and `SH*_NI1` in
node-access.md). The remaining nibbles go to the route register, shifted down four bits. Each following nibble is
read as the output port at the next router (inferred; the PROM's "path 0x%lx" and "Max vector length 16 exceeded"
messages agree: sixteen nibbles are sixteen hops). When only the first nibble is set, the route register would be zero
and the routine puts `0xf` in nibble 8 of it (bits 35:32); what that terminator means is **unknown**. The port letters
A to H in the router's tables are port numbers 0 to 7; the PROM prints router ports as a number (`router %d port %d`)
and the R-brick's rear connectors as 1 to 8 or A to H (007-4579-001 p.140), so the 1 to 8 numbering of the Origin
3000 router formula and the A to H lettering name the same eight ports (inferred, from the guide's connector list).

What the PROM builds on top (names from its strings; behaviour inferred unless the page says otherwise): a discovery
crawl that reads register 0 of each neighbour, counts chipsets, routers and I/O chipsets, assigns `metaid`s and NASIDs
(fat-tree depth check, "meta router" and repeater checks, "connects to %s, expected %s", "check NUMAlink cabling"),
computes routes (`Outgoing route`, `Return route`, "routing table" prints), then writes the routing tables, partition
fences and the real-time-clock distribution (`R4_RTC_SOURCE`). A node with no peer skips all of this (established in
[../../software/firmware/snprom/boot-sequence.md](../../software/firmware/snprom/boot-sequence.md)). For SHub 2 images
the router configuration routines are `nl4r_init_global`, `nl4r_config_global` and `nl4r_config_port` (error text
"error on vector access"), `nl4r_fence_ports` (takes the router lock, fences ports, releases it) and `nl4r_mip_clear`
(clears "MIP" state when a link goes down, using SHub bits `0xd`, `0xe`, `0xf` of the PROM's own flag word). What values
they program, read in full for the first and third (SHub 2 SAL 10.54): `nl4r_init_global` writes zero to the local-block
error and first-error registers (`0x2000`, `0x2010`, `0x2020`, `0x2030`, `0x2050`, `0x2060`), writes `0xc000000000000000`
(`FORCE_EN` and `CLEAR`) to `PORT_PERF_WIN`, and sets `FREE` in all sixteen reply-gather buffers (`0x4f00` to
`0x4f78`, stride 8). `nl4r_config_port` takes a port number n and, at `0x7000000 + n * 0x1000000` plus the port-block
offset, zeroes the error summary and first-error words, writes 1 to the error-detail-clear register, zeroes both link
error counters, and writes `0x5c0000000006` to the error-report mask: the retry, check-bit and sequence-number count
non-zero bits, `EXTEND_TURN_ERR`, `RCV_LINK_RESET` and `RCV_WARM_RESET`. Because the base is `0x7000000 + n *
0x1000000`, port block A (`0x8000000`) is n = 1: the PROM numbers ports 1 to 8, as the Origin 3000 router does. The
middle routine, `nl4r_config_global`, could not be located by the Ghidra export (no function matched its string address)
and was not read; the global parameters and the routing tables it writes are **unknown**.

## What an emulator author can rely on

1. A model of a router needs only the vector protocol on the node side and register 0 on the router side to get the
   PROM through discovery; every other register can read as zero until a guest is found that reads it.
2. The register numbers, names and bit positions in registers.toml are as the PROM names them. Reset values and roles
   are **unknown** (the table gives neither).
3. Link and timeout counts (`SEND_DEADLOCK_TO_VAL`, `DEADLOCK_TO_VAL`, `TAIL_TO_VAL`, the LLP `MAXRETRY` and
   `NULLTIMEOUT`, credits) are tuning values; their units are not stated anywhere read.

Open items are listed in [../../questions/numalink4-router-open.md](../../questions/numalink4-router-open.md).

## Checks against the sources

- Offsets of the `R4_` table were checked three ways: the first register's field range runs to the second's first
  field, no two registers share a number, and the eight port copies of each port register are a constant 0x1000000
  apart except the per-port counters in the global block, which keep a constant stride of 8 or 0x10 (one family,
  `D_COUNT_INIT`, is irregular and is kept as eight separate registers).
- The vector routine's constants (`0x10067080`, `0x10067100`, `0x10074000`, `0x10074100`, the `0x1c8` operation code,
  the poison value written to the read-data register, the 1,023-try polls) were read twice, once in the decompiler
  output and once in the objdump listing of the image.
- The SHub 1 PROM's vector registers sit at the same relative positions with a `0x1_0000_0000` bias (node-access.md);
  the field layouts agree except the status register's source field, which is 14 bits in SHub 1 and 16 in SHub 2.
