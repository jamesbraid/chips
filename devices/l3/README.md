# L3 system controller (a console host, not a controller)

Mode: no-spec. The "L3" is the third level of SGI's system-controller naming. In the shipped Origin 3000 and Altix
products it is a PC that runs SGI's controller software, so it has no firmware, registers or boards of its own. This
page records that and how the L3 reaches the controllers. Grades follow [AGENTS.md](../../AGENTS.md).

Sources: SGI, *SGIconsole Hardware Connectivity Guide*, 007-4340-003, printed pp. 1 to 7 (cited as read); *SGI L1 and
L2 Controller Software User's Guide* 007-3938-005 p. 8; *SGI Altix 3000 User's Guide* 007-4579-001 p. 71; Linux v2.5.0 `include/asm-ia64/sn/ksys/l1.h`; sysco
`evidence/controllers.md` and `evidence/irix-files.md` for the held software.

## What the sources say

| Fact | Grade and source |
|---|---|
| The address field in every controller message has a type nibble: 0 L1, 1 L2, 2 L3, 3 attached C-brick, 4 attached I/O brick. The header's comment says the target "could actually be L2, L3, not just L1". | established for the field (Linux v2.5.0 `l1.h`); no code in the header, in `l1.c` or in the Linux v5.3 files sends to type 2 |
| The product that plays the L3 is the SGIconsole (the manual never says "L3"; the pairing is sysco's, from the held `snxsc_l3` package name, inferred): a host system that manages servers with MSCs, MMSCs, L1s and L2s. With an L2 present it connects to the L2's dedicated Ethernet subnet by one cable and reaches every L2 and, through them, every L1. With only L1s it uses one serial cable to the L1 (Origin 300 and 350, Altix 350, Origin 3200 without L2). | established for what the SGIconsole connects to (007-4340-003 pp. 3 to 5); inferred for calling it the L3 |
| The guides use "system console" for the same role: an SGIconsole or a dumb terminal on an L2 or L1 console port. The firmware is updated from the console (`flashsc --l2 <ip>`, run on the SGIconsole). | established (007-3938-005 p. 8; 007-4579-001 p. 71) |
| SGIconsole 2.1 manages up to 64 serial-connected systems and 19 Ethernet-connected ones, and is advised for at most 64 partitions. Serial port servers and Ethernet hubs expand the connections. | established (007-4340-003 p. 7) |
| The software is a set of host programs: `l2`, `l2cmd`, `l2find`, `l2term`, the library `libsnxsc` (package `snxsc_l3` 1.62.0) and the `sgil1` USB driver source, from SGI's Internal Support Tools 3.24 disc, plus `flashsc`, which reflashes the controllers. These are held as a file set in sysco. | established that they exist and what they are named (sysco `evidence/controllers.md`); their wire format is not read |

## How the L3 reaches the controllers

- **To an L2:** Ethernet, to the daemon's TCP ports (sysco `software/firmware/l2/daemon.md` lists 9001, 9002, 9004, 8000
  and 8002 plus a per-copy bias); established there for the L2 side. The message format on those sockets is the L2's own
  router packet, sysco `router-packet.md`. The same daemon accepts L1s over the network, so the packet layout is the
  one the L1 firmware uses for its `RouteIRouter` task; inferred.
- **To an L1 with no L2:** USB through the `sgil1` driver (the L1's USB-B port) or an RS-232 console cable. The L1's USB
  side delivers router packets (sysco `usb-descriptors-routing.md`); established on the L1 side.
- **Through the node:** not at all. A node's kernel and PROM never talk to an L3; they talk to the L1 over the UART
  ([../l1/host-link.md](../l1/host-link.md)).

## What a model needs

Nothing, to boot a guest. An L3 matters only when software on a modelled machine expects a console host (for example
`l2cmd` talking to a modelled L2 or L1). The earlier reading in the sysco repository that the L3 is a PC and not a
firmware target stands; this repository adds only the address-type field and the manual statements above.

## Open

The format of the messages between an L3 and an L2 beyond the shared router packet, and whether any shipped product
used address type 2 as a distinct controller, are open: [../../questions/l1-l2-l3-host-protocol.md](../../questions/l1-l2-l3-host-protocol.md).
No SGIconsole product disc or L3 software newer than 1.62.0 is held.
