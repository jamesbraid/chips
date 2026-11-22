# L2 system controller (Origin 3000 and Altix 3000 racks; the Altix 4700 software L2)

Mode: no-spec. The L2 is a board with its own CPU and firmware, not a memory-mapped device. A node never reads or writes
an L2 register. This page says what the L2 is, what it joins, and how a host reaches it. The L1 side is
[../l1/host-link.md](../l1/host-link.md); the shipped L2 firmware, board contract and daemon are read in the sysco
repository (links at the end). Grades follow [AGENTS.md](../../AGENTS.md).

Sources: SGI, *SGI L1 and L2 Controller Software User's Guide*, 007-3938-005, printed pages 3 to 5, 8 to 19 and 137
to 138; *SGI Altix 3000 User's Guide*, 007-4579-001, pp. 37 to 44, 55 to 58, 62 to 64, 70 to 72; *SGIconsole Hardware
Connectivity Guide*, 007-4340-003, pp. 3 to 5 (printed); Linux v2.5.0 `include/asm-ia64/sn/ksys/l1.h`; Linux v5.3
`snsc.c`, `sn_sal.h`. Firmware facts are quoted from sysco and carry its grades.

## What it is

| Fact | Grade and source |
|---|---|
| A supervisor above the per-brick L1 controllers. It controls resource sharing and the L1s of its rack, keeps controller configuration and topology between L1s and other L2s, routes messages between upstream devices (consoles) and downstream ones (L1s), and interprets power sequencing, because bricks must power up in a set order. | established (007-3938-005 pp. 3 to 4, 13) |
| Several hardware L2s in one system are peers. Each propagates configuration to the others and tracks its own L1s. | established (007-3938-005 p. 4) |
| One L2 is mounted at the top of a rack and uses no rack units; rack 001 carries a touch display on its rear door. The display offers power up, power down, reset, NMI and destination selection, and shows the firmware version and serial number (`SGI L2 Controller, Firmware V1.17.7`). | established (007-4579-001 pp. 37 to 44) |
| Ports: four downstream USB ports (an L2 is the USB master; each goes to an R-brick's hub or, with no R-brick, to a C-brick's L1), one 10/100 Ethernet port, a console RS-232 port and a modem RS-232 port at 115 kbaud, the touch display, and power from the power distribution strip. | established (007-4579-001 p. 39) |
| The L2 firmware has two parts, a boot image and a kernel image. There is no second copy to fall back to; a bad kernel image is not run, and the L2 can be reflashed from its console port (`flashsc --l2recover`). The L1, by contrast, has a boot image and two images, A and B, and runs the newer valid one. | established (007-4579-001 pp. 71 to 72) |
| Brick names are `rrrbss.p`: rack, brick type letter, slot, and partition when partitioned. A brick's L2-level address is `a.b.c.d:x:y`, the L2's IP address, USB port number and an L1 index (0 is the L1 on that USB cable; the guide says only that other values are system and device specific, and its `config verbose` example, p. 50, lists attached bricks under higher indexes, which is a reading, inferred). | established (007-3938-005 pp. 9 to 10; 007-4579-001 pp. 62 to 63) |
| Commands the L2 does not understand pass to the L1s of the current destination (`rack <list> slot <list>`, `partition <n>`; default all racks and slots). The L2 interprets `power`, `config`, `select`, `destination` and similar. | established (007-3938-005 pp. 10 to 13, 137) |
| Operating modes on the console port: L2 prompt, console mode (Ctrl-D, all input to the selected system console) and L1 mode (`l1`, input to one L1); Ctrl-T escapes. The L2 picks the console from two things, the last brick and subchannel that produced output and the brick with the lowest rack and slot; the guide does not say which wins. | established (007-3938-005 pp. 8 to 15) |

## Hardware and firmware, as shipped (quoted from sysco)

Read from the L2 image of IRIX 6.5.30, firmware 1.44.0, the Origin 3000-era L2 that also serves Altix 3000. Grades are
sysco's.

- PowerPC MPC8xx-family microcontroller (memory-map register `0xfa200000`), a 50 MHz bus, embedded Linux 2.4.7 from a
  read-only cramfs, board contract in `platforms/l2/board-contract.md`. Established there.
- Daemon `l2`, listening on ports 9001, 9002, 9004, 8000 and 8002 plus a bias (`--copy N` adds `10 * N`), reaches L1s
  over USB through the SGI `sgil1` kernel driver (`/dev/sgil1_<n>`, up to 40 devices, a control node
  `/dev/sgil1_cs`), over the network, or over a serial line. USB is the default. Established there
  (`software/firmware/l2/daemon.md`).
- A task registry above the same framing as the L1: tasks the daemon registers for clients include `l2part` 10, `l2flash`
  8 and `l2gui` 6; the partition database lives in the flash top sectors. Established there.
- Conflict: the manual gives the console port as 115 kbaud; the boot stages' board-information block carries the
  value `0x9600`, which sysco reads as 38,400. Not reconciled: the block may describe the boot loader's own port. Open.

## What a host sees of it

1. **A node's kernel does not address the L2 directly.** A message from a node goes to its own L1 over the UART, with a
   target address whose type field names L1, L2 or L3 (0, 1 and 2; Linux v2.5.0 `l1.h`; see
   [../l1/host-link.md](../l1/host-link.md)). Whether an L1 forwards a type-1 target to an L2 is the L1's routing
   decision; the L1 firmware's router is described in sysco `software/firmware/l1/` (`RouteIRouter`, task 23, and the
   chunked-request notes). Grade inferred for the forwarding, established for the field.
2. **On SN2 the PROM mediates.** The kernel's controller pipe is `SN_SAL_IROUTER_OP` ("IRouter") with one subchannel per
   open and 127-byte chunks (`snsc.c`, `sn_sal.h`, Linux v5.3). The kernel names the target by node, not by L2; the PROM
   owns the route. What the PROM itself sends an L2 is read: the text commands `version` (a probe), `p <partition> rst` and
   `p <partition> pwr d`, all to destination word `0x1ffff003` through its own L1, and the L1 answers a routing error when no
   L2 is attached (and the PROM sends `* rst` or `* pwr d` to its own L1 only when its partition is 0) ([software/firmware/snprom/l1-requests.md](../../software/firmware/snprom/l1-requests.md), "Requests after boot"; sysco
   `software/firmware/l2/altix-l2-model.md`). Established for the PROM and for a ColdFire `O` L1. What user space sends through the
   kernel's controller pipe is unknown.
3. **Operators and consoles** reach the L2 by the console port, by telnet through the daemon's shell service, or by the
   Ethernet port from an L3 (SGIconsole), which sees every L1 through the L2s.
4. **Firmware** is replaced through the L2: `flashsc --l2 <ip> ... l1.bin all` reflashes L1s, `... l2.bin local` the L2.
   Established (007-4579-001 pp. 71 to 72).

## Which systems have one

| System | L2 | Grade and source |
|---|---|---|
| Origin 3000 series, Onyx 3000, Origin 300 and 350 with NUMAlink module | yes, except an Origin 3200 without one | established (007-4340-003 p. 5) |
| Altix 3700 | yes: standard in the 3700; required in a rack with an R-brick or an L2 touch display, or for remote maintenance | established (007-4579-001 pp. 35 to 36) |
| Altix 3700 Bx2 | no hardware L2. The L1 of a CR-brick or NUMAlink 4 R-brick acts as an L2 emulator when a USB-to-Ethernet adapter is plugged into its type A connector; the adapter goes on the bottom CR-brick (64 processors or fewer) or on named R-bricks in larger systems | established (007-4377-002 pp. 18, 24 to 25, 33 to 35; agrees with 007-4340-003 p. 5) |
| Altix 350 and 330 | none required; an optional L2 joins through the base module's USB type B L1 port | established (007-4340-003 p. 4 for the 350; [platforms/sn2/altix-350.md](../../platforms/sn2/altix-350.md)) |
| Altix 4700 and 450 | no L2 hardware. Every IRU has an embedded Linux system controller. The L1 application always runs. Connecting the IRU's (or a Dense router's) Ethernet connector to a live LAN makes it start the L2 application, which controls several L1s and talks to other L2s. The L1 command `l2` reports whether it runs, and `! init 4` starts it. | established (007-3938-005 pp. 3, 5, 19 to 20; 007-3938-006 pp. 4, 13 to 14; Altix 4700 guide 007-4823-003 pp. 27, 31); established for the 450 only through the shared 007-3938-006 text, its own guide was not read |

The NUMAlink 4 cables carry the 4700's controller traffic between enclosures by low-voltage differential signalling
(007-3938-005 p. 5). Whether that traffic shares the NUMAlink wires or only the cable assembly is **unknown**.

## Open

[../../questions/l1-l2-l3-host-protocol.md](../../questions/l1-l2-l3-host-protocol.md) lists the PROM's routing of L2
traffic, the console-baud conflict and the 4700's LVDS path. No Altix 3000 product L2 image is named as such, so the Altix 3000 L2 firmware
is assumed to be the 1.x line sysco reads (inferred from the manual's firmware-version strings, 007-4579-001 p. 44:
`V1.17.7`; 007-3938-005 p. 5 for the 4700 change). Sysco reads 1.44.0 in full and compares L2 1.62.0 from the
Internal Support Tools 3.24 disc (the set that carries the L1 1.62.1 the SN2 PROM link page reads) against 1.48.0 in
the "Version diffs" section of its `COVERAGE.md`; this page did not read that comparison.

## Related pages in the sysco repository

`software/firmware/l2/README.md`, `daemon.md`, `l1-conversation.md`, `partition-task.md`, `router-packet.md`,
`platforms/l2/board-contract.md`, and `software/firmware/controllers.md`.

What a model of the L2 needs for an Altix 3700, 3700 Bx2, 4700 or 450, graded and with a ready-to-model list, is in the sysco repository, `software/firmware/l2/altix-l2-model.md`.
