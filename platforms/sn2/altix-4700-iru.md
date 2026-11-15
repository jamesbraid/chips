# Altix 4700 and 450: the IRU, its blades and its routers

The 4700 and 450 replace the brick-and-cable layout of the earlier Altix machines with a backplane chassis, the individual
rack unit (IRU). Compute, memory, I/O and graphics-carrier blades plug into the front; router boards sit at the two sides.
The population summary is on [altix-4700.md](altix-4700.md); this page records the chassis structure, slot and router
map, the controller's naming, and the blade types. How the kernel discovers all of it is on
[altix-4700-discovery.md](altix-4700-discovery.md). No register facts here.

Sources: SGI, *SGI Altix 4700 System User's Guide*, `007-4823-001` (March 2006), printed pages (PDF page is printed page
plus 20); SGI, *SGI Altix 450 System User's Guide*, `007-4857-001` (August 2006, first release; PDF page is printed page
plus 22); SGI, *SGI L1 and L2 Controller Software User's Guide*, `007-3938-005` (PDF page is printed page plus 26);
Linux v5.3. Grades are those of [AGENTS.md](../../AGENTS.md).

## Chassis

| | Altix 4700 (007-4823-001) | Altix 450 (007-4857-001) |
|---|---|---|
| IRU height | 10U (p.53) | 5U (p.64) |
| Blade slots | ten, numbered 0 to 9; slots 10 and 11 are the left and right router boards (007-3938-005 Figure 2-2, p.52) | five, numbered 0 to 4 (Figure 3-3, p.64) |
| Routers | four router ASICs, two on each of two router boards (Figure 3-4, p.48; p.47) | two, one per router board, labelled "Slab 0" (left) and "Slab 1" (right) (Figure 3-4, p.65) |
| Rack | 42U; up to four IRUs and a 2U space at the top for an optional router module (p.53) | 20U "short" rack, up to four IRUs, or 42U "tall" rack, up to eight IRUs and a 2U option space (p.70) |
| Processors per rack | up to 64 (p.46) | up to 76 cores (p.64) |
| System controller | a system control board at the bottom of the IRU, driving the blades and power supplies (Figure 3-4); four power supplies | a system control board and an "L1 controller panel" on the front; two power supplies (Figures 3-4, 3-5, pp.65, 71) |

Established for every row, as printed. Both IRUs share a DC power bus drawn between the power supplies and the blades
(Figure 3-4 in each guide), redundant hot-swap fans and power supplies (4700 pp.49, 51; 450 p.66). Rack numbering is a three-digit number from
001; in a one-rack system the rack is 001. An IRU position is named by the lowest rack unit it occupies, for example U01
for an IRU in U01 to U10 of a 42U rack (4700 p.55; 450 p.71).

## Blade types

| Controller code | Blade | Source and grade |
|---|---|---|
| C1 | one processor with memory, "SHub 2.x based" | established (007-3938-005 p.50) |
| C2 | two processors with memory, "SHub 2.x based" | established (same) |
| M2 | memory-only blade | established (p.51) |
| IA | base I/O blade, "double-height" in the controller guide, "double-wide" in the user's guide; one per system or partition is required | established (p.51; 007-4823-001 p.53) |
| I2E | single-height PCIe or graphics expansion | established (p.51) |
| I3X | three-slot PCI-X expansion, hot-pluggable | established (p.51) |
| I4E | four-slot double-height PCI-X, PCIe or graphics expansion | established; the table prints "14E", a misprint, since the graphics option guide uses I4E (007-4954-001 pp.2, 9) |
| RC | FPGA compute blade (RASC) | established as a controller blade type; hardware not read |

User's-guide names for the same parts (007-4823-001 p.53): compute/memory blade (up to two IA-64 sockets, 4, 8 or 12
DIMMs), memory-only blade (4, 8 or 12 DIMMs), double-wide PCI-X expansion blade (three 133 MHz 64-bit slots, card
carriers that slide in and out), single-wide PCIe blade (two PCI Express cards), double-wide PCIe/PCI-X blade (two PCIe and
two PCI/PCI-X cards), and the IA blade (one or two disks, a DVD drive, two low-profile PCI slots, two Ethernet connectors,
one SAS/SATA II port, four USB ports). The 450 guide adds a single-wide two-slot PCI-X blade with a separate bus per card,
and optional RAID 0 or 1 on the IA blade (007-4857-001 p.70). The match of C1/C2/M2/IA/I2E/I3X/I4E to the user's-guide
names is **inferred** from the identical function and slot counts; neither guide states the equivalence.

### Names the controller prints for the boards in a blade listing (established as one example, not a catalogue)

The L1 `blade` command prints the slot, a name, an enable flag, a serial number, a blade type and a state. The one example
in the guide lists slot 0 as `BaseIO`, slots 2, 3, 6, 7 and 8 as `IP73_667`, slots 10 and 11 named `RTRL` and `RTRR` as
`DUAL_ROUTER`, and the rest empty (007-3938-005 Example 3-3, p.66). So the base I/O blade appears as `BaseIO` in slot 0, a
router board as `DUAL_ROUTER`, and a compute blade by a board name with a speed suffix. The example's slot 0 for the IA blade
is a sample, not a rule: **unknown** whether the base I/O must sit in slot 0.

Board codes the Linux kernel names for these boards are on [the discovery page](altix-4700-discovery.md#board-and-brick-codes).

## Routers and the NUMAlink ports

Established (007-4823-001 pp.47, 48; 007-4857-001 pp.64, 65): the router is a custom eight-port crossbar ASIC; the IRU
joins its blades through the routers on a backplane, with NUMAlink 4 cables to other IRUs. A processor node is a SHub
and one or two processors; the SHub sits between the processors, local memory and the network interface (see
[altix-4700.md](altix-4700.md)).

Established from the block diagrams (Figure 3-4 in each guide):

- Each router is drawn as a box with ports lettered A to H. On the 4700 each of the two router boards carries two router
  boxes (an upper and a lower); on the 450 each carries one. Two ports of each router are labelled "NUMAlink" and lead to
  connectors on the IRU; the other ports are drawn to the blades. The 4700 IRU has eight NUMAlink connectors on its front
  (007-4823-001 p.107), which is two per router; the figure's lettering is too small to say which port letter is which.
- Each compute blade has two network interface links, NI0 and NI1, each with its own LED showing the connection between the
  blade and "the router board within the IRU" (007-4823-001 p.108, Figure 7-1). So every compute blade is on both router
  boards, one NI per board: **inferred** (the guide says "the router board", singular, and draws both boards).
- The base I/O blade has two NUMAlink ports (007-4823-001 p.50).
- Each connector has a green LED for link established and an amber LED for both ends powered (p.107).

**Unknown:** which router port each blade slot uses (the figure draws the blades by number 1 to 10, while the slot map
numbers them 0 to 9, and the upper and lower halves are drawn by odd and even blade numbers while Figure 3-3 draws two rows
of five); the use of the remaining router ports (inter-router links or spares); the router's internal addressing and
routing. A router register contract is not held: the chips repository's router pages cover the Origin 3000 router. Route:
a PROM or hardware-discovery dump from a 4700, or an SGI router specification.

Link speed: the Dense router table lists 32 NUMAlink channels at "3.2 GB/s each direction" (007-4823-001 p.66).

### Dense router module

An optional 2U box at the top of the rack (007-4823-001 pp.61 to 66): four router boards, each with one router ASIC
("eight-port crossbar... any of the seven other possible output-link channels"), "32 NUMAlink channels" in the feature list,
and "sixteen NUMAlink 4 connection ports" on the front; one L1 controller; an L2-host RJ45 and a DB-9 console port; four fans;
power from a 12 V and 3.3 V supply, about 160 W. Used when IRUs span more than one rack. The guide's 32 channels against 16
front ports is **unresolved** (each port may carry two channels, or the feature list counts router-side channels). It carries
its own L1, needs a valid unique rack and module id like an IRU (007-3938-005 p.52), and the L1 `router` command set applies
to it (below).

## Controller naming and identity

Established (007-3938-005 pp.48 to 53):

- There is no hardware L2: the L2 is an application controlling several L1s (007-3938-005 p.3, in [altix-4700.md](altix-4700.md)).
  Each IRU and each Dense router has an L1. The L1 name has the form rack (three digits), brick type letter, slot
  (two digits), for example `001c07`; an IRU is type `c` (blade examples are printed as `001c03-L1>`).
- Each IRU and Dense router needs a valid and unique rack and module id; the module id should match the rack unit number that
  aligns with the bottom of the IRU or router (Figure 2-3, p.52).
- The rack and slot are held in non-volatile memory on the L1 and set with `brick rack`, `brick slot` or `brick rackslot`;
  an L1 reboot is needed for them to take effect. Without them, L2 `config` prints "(no rack/slot set)" (pp.52, 53).
- The L1 generates the identity the L2 emulator shows from a formula, `RackID = 100 * L1 rack number + L1 slot number`
  (p.52). That is a controller-emulation identity, not the kernel's module id (next page).
- Commands that act on a blade: `blade` lists and enables or disables a slot by number (`blade <num> e` or `d`); the `router`
  commands "view and set router types", including `router 6 port`, `router 8 port`, `router meta`, `router repeater`,
  `router service`, valid only for R-bricks and NUMAlink modules (007-3938-005 pp.65, 66, 108). Whether the 4700's IRU
  routers take these commands is **unknown**: the guide says "R-bricks and NUMAlink modules".
- Environment: temperature advisory, critical and fault thresholds at the IRU air inlet are 30, 35 and 40 degrees C at low
  altitude and 27, 31, 35 at high altitude; the L1 powers the IRU down after a fault (007-4823-001 p.106).

Host protocol and L1 firmware for these bricks live in the sysco repository, as on the [SN2 README](README.md#which-chip-where).

## Memory

Established (007-4823-001 pp.81, 82, Figures 6-10, 6-11): up to twelve DIMM slots per blade in three groups of four; DIMMs
go in groups of four of one size and speed; group 0 must be populated for the blade's memory to work; blades may differ in
DIMM capacity. The node-board diagram draws the SHub 2 between two memory buses on each side, labelled "left bus X, Y" and
"right bus X, Y" with DIMM locations 0 to 5 each, so twelve slots in all; it also shows two NUMAlink 4 ports, the front-side
bus to the processors, and blocks labelled "SAW" and "OSC". The 450 uses the same compute blade description (4, 8 or 12
DIMMs, two sockets; 007-4857-001 p.70). The page cannot say what the buses X and Y map to on the SHub: **unknown**, SHub
memory-controller facts are the SHub page's.

## Coherence unit

Established (007-4823-001 p.50): directory-based coherence over 128-byte blocks, each directory entry holds an unowned,
exclusive or shared state and a bit vector of sharers; coherence uses invalidation. Memory, caches and bus transfers use
single-bit correct, double-bit detect ECC; NUMAlink uses a CRC. The directory format itself is the SHub's business.

## What would settle the unknowns

A boot log or `/proc/sgi_sn/` capture and the hardware-performance topology listing from a 4700, or the held SHub 2 PROM
read against the node-discovery code ([questions/altix-4700-open.md](../../questions/altix-4700-open.md)).
