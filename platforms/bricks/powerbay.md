# Origin 3000 power bay

The power bay is the rack unit that holds the supplies for the Origin 3000 and Onyx 3000 bricks.
Its controller is the L1 of the rack's brick, reached over the ICMB link. This page records what
the published SGI manuals say about the bay, what the retained IRIX 6.5.30 firmware set holds for
it, and what is unknown. It holds no register contract. Its manual citations were re-read against
the retained text of each manual in a later verification pass.

Each fact carries one label. **Established** means a published manual, or a shipped binary read
directly, states it, with the citation. **Inferred** means reasoned from established facts.
**Unknown** means not settled, with the route that would settle it.

## Physical unit and supplies

**Established as printed** (`007-4240-002` pp. 12, 202, 207). The power bay is a 3 U unit. A bay
holds up to six 950 W supplies (p. 202), and at least two must be present (p. 207). The owner's
guide also says each bay contains three or four supplies (p. 207), so the count in a given rack
follows the bricks it feeds.

**Established as printed** (`007-3938-005` pp. 99 to 101; `007-4364-003` p. 5; `007-4364-006` pp. 8,
13). The bay is managed through an L1 with `pbay` commands. The L1 command guide lists status,
firmware version, supplies, DC ports, FRUs, reset, environment, init and `serial`. The update
guides add `pbay env` and `pbay init` (003 p. 5), `pbay serial` (006 p. 8) and issuing `pbay` through
the L2 (006 p. 13). The bay has firmware and an ICMB card.

**Established as printed** (`007-4364-007` p. 7). A later L1 guide extends the `pbay` commands to
PE-bricks.

## Link to the L2

**Established as printed** (`007-4364-003` p. 5). The L1 calls its power-bay link the ICMB
interface.

**Established as printed** (`007-4240-002` p. 76). The L2 rear panel has a connector labelled ICMB,
an RS-485 port. The same connector is discussed in [the D-brick notes](dbrick.md).

**Inferred.** The L2's ICMB connector and the power bays share a path. The inference comes from the
shared name only.

**Unknown.** Whether the L2's RS-485 port serves the power bays, the D-bricks, or neither. Route: a
captured exchange on that port, or a photograph of the L2 rear panel with its cabling.

## Retained firmware image

**Established** (`007-3938-005` pp. 99 to 101). The L1 has a command that sends power-bay
commands.

**Unknown** (regraded in the verification pass). An earlier version said the retained IRIX 6.5.30
firmware set holds a power-bay controller image of 5,888 bytes beside the L1 and L2 images, and
that the L1 has a task that flashes it. The image is not in this repository, and the set that
this pass could read (`root/`) has no power-bay image, so neither the size nor the flash task could
be re-checked. Route: re-read the full firmware set the claim came from.

**Inferred, not independently checked.** The image is MCS-51-family code. The basis is the
register-save sequence at its interrupt entry points, which lies after a text header. No second
reader has checked this reading.

**Unknown.** The controller's protocol, what the L2's `pbay` command asks it, and whether the PROM
or IRIX ever address the power bay directly. Route: disassembly of the image and of the L1's flash
task, or an L2 session that runs the `pbay` command with a capture of the exchange.
