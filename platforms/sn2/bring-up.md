# Bringing up an emulated Altix 350

Where to start if you're building an emulated SGI Altix 350 that boots SGI's own firmware. Prism shares the
Altix 350's node board, so the same work carries forward to it. This page only points at the contracts; the facts,
grades and sources live on the pages it links.

## The target

One Altix 350 base compute module: one SHub 1 node, one Itanium 2, DIMM group 0, a PIC on the I/O riser with an
IOC4-based base I/O card, and an L1 controller. No router, no second node, no L2. The reasons, and why the Altix 3300
is not the first target, are in the [qualification report](../../software/firmware/snprom/qualification.md).

The firmware is SGI's `shub1snprom.bin`, SAL 5.04 (snprom 10.54 build 70399, built 2008-11-11), sha256
`51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`. SGI's own README for the package lists the
Altix 350 and both Prism models for this image. Boot it as shipped: the firmware's built-in simulator path, which
skips the L1 when the processor reports a particular signature, is not to be used. The other held images and their
checksums are in [evidence/sn2-holdings.md](../../evidence/sn2-holdings.md).

## What the firmware needs, in the order it meets it

| Step | What it needs | Contract |
|---|---|---|
| Reset | The 6 MiB image as flash ending at 4 GiB; the firmware's own PAL run from it (no substitute PAL); an Itanium 2 identity matching the firmware's processor table | [snprom README](../../software/firmware/snprom/README.md), [qualification](../../software/firmware/snprom/qualification.md) |
| First stage | The SHub 1 registers the first stage writes and reads, an advancing clock, RAM at physical 0x1000000 | [boot path](../../software/firmware/snprom/altix350-boot-path.md), [devices/shub](../../devices/shub/README.md) |
| L1 link | A 16550-style UART on the SHub junk bus answering framed requests; without it the firmware stops at progress 0x8d | [boot path](../../software/firmware/snprom/altix350-boot-path.md), sysco `software/firmware/l1/sn2-prom-link-1.62.1.md` |
| Identity and switches | L1 answers for board EEPROM, rack/bay/type, CPU presence, and the debug switches (0x800 for a single node) | sysco `software/firmware/l1/sn2-prom-link-1.62.1.md` |
| Memory | DIMM SPD data through the L1, the memory controller registers, the memory self-test completing | [boot path](../../software/firmware/snprom/altix350-boot-path.md) |
| Jump to RAM | The node-window RAM the firmware copies itself into | [boot path](../../software/firmware/snprom/altix350-boot-path.md) |
| I/O | A crossbar part at widget 0 and a PIC (part 0xd102) on the link, the I/O riser EEPROM through the L1 | [boot path](../../software/firmware/snprom/altix350-boot-path.md), [devices/pic](../../devices/pic/README.md), [devices/shub_ii](../../devices/shub_ii/README.md) |
| Console and EFI | The console through the L1 or the junk-bus UART, then the hand-off into EFI | [boot path](../../software/firmware/snprom/altix350-boot-path.md) |

The operating system then expects the SAL calls in [software/sal](../../software/sal/README.md) and the address
layout in [address-map.md](address-map.md). The machine's documented configuration is in
[altix-350.md](altix-350.md).

## What is still open

Each open item is listed with its grade on the linked pages and in
[questions/sn2-prom-open.md](../../questions/sn2-prom-open.md). In short: the meaning of four PAL procedures the
firmware calls, the SHub 1 registers behind the processor election, the order of the firmware's first L1 requests and
the L1's reply bodies, the I/O interface set-up the firmware does before reading the PIC, the link-credit settings,
and the contents of the EFI hand-off record. None of these needs a change to the firmware or a skipped test to get
past; each needs the device modelled.

## Telling a correct boot from a lucky one

The [qualification report](../../software/firmware/snprom/qualification.md) lists discriminating checks, each tied to
a source fact, and keeps checks of firmware behaviour separate from checks that only show the software is happy. The
firmware's own progress codes, which it writes to the LED registers and keeps in a table with a message for each, are
the main way to see how far a boot got.

Published serial-console logs from a real Prism (SAL 4.65) show what the start of a good Linux boot prints; they are
cited in [evidence/sn2-holdings.md](../../evidence/sn2-holdings.md).
