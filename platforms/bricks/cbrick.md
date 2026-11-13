# Origin 3000 C-brick

The C-brick is the processor brick of the Origin 3000 family. Its single IP35 board carries
the Bedrock, the processors and the brick's L1 controller. This page records the C-brick facts
that the published SGI manuals state and that the repository did not hold before. It is partial:
the C-brick enclosure, its board and its register behaviour are not covered here. The combined
processor and router brick is in [the Cx-brick notes](cxbrick.md).

Each fact carries one label. **Established** means a published manual states it, with the
citation. **Inferred** means reasoned from established facts. **Unknown** means not settled, with
the route that would settle it. The manual citations below were carried from a review of the
published manuals; each was re-read against the retained text of the manual in a later verification pass.

## Processor clock options

**Established as printed** (`007-4576-006` p. 17). System Controller Software 1.5 adds L1 firmware
support for "R16KA 700MHz and 800MHz" parts, in a release that also names Origin 3900 and Origin
350 bricks. The release does not name the brick type for that line.

**Established as printed** (`007-4364-008` p. 8, 2002). The L3 1.8 update guide lists, among L1
firmware additions, support for "R16K 600-MHz PIMM boards built as R14KA 600-MHz PIMMs", part
`030-1823-001`. The guide's wording leaves open whether the CPU reports as an R16000 or an
R14000A. The guide does not say the board shipped.

**Inferred.** `030-1823-001` is a PIMM, from its place in the L1 firmware section of that guide.
Whether it is a C-brick PIMM is inferred from the guide's title only.

**Unknown.** Whether an 800 MHz C-brick PIMM shipped, and its part number. Whether the
`030-1823-001` boards are C-brick parts. No retained capture of an R16000 C-brick exists in this
repository. Route: a price list, an upgrade bulletin or a `hinv` naming the part.

**Unknown.** Any 1 GHz C-brick part. No published source shows one in a C-brick, so the
question stays open.

## L1 USB channel

**Established as printed** (`007-4363-001` p. 21; `007-3938-005` pp. 96-97). A C-brick L1 has one
USB channel. The L1 `network` command points that channel at the external L1 port or at the link
port, over USB or RS-422. With no L2 in the system, a workstation running the L3 software attaches
to the L1 port.

**Established as printed** (`007-4364-003` p. 5). The L1 `usb` command reports the statistics of
the L1-to-L2 link.

**Unknown.** Whether the PROM or IRIX ever reach the L1 over this USB channel, rather than over the
Bedrock UART. Route: a boot transcript or a kernel routine that opens the USB path.
