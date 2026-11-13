# Origin 300 NUMAlink module

The Origin 300 NUMAlink module is the router enclosure that joins Origin 300 base modules and
PCI expansion modules over NUMAlink 3. This page records what the published Origin 300 guides
say about its population, its power and its port use, and what a public inventory says about its
router board. It is a product and topology reference, not a register contract. No register facts
were added, so the register maps were not changed.

Each fact carries one of three labels, as in the rest of this repository. **Established** means a
published manual or a public inventory states it, with the citation. **Inferred** means reasoned
from established facts. **Unknown** means not settled, with the route that would settle it.

## Sources

- **Origin 300 guide `007-4498-002`**, cited as `007-4498-002 p. N`. PDF pages are given after the
  printed page where the citation carries them.
- **Origin 300 PCI expansion guides `007-4499-001` and `007-4499-002`**, cited as
  `007-4499-00N p. N`. Both editions give the same port restriction.
- **One public hinv listing posted to a forum thread**, from a rack of Origin 350 / Onyx 350 compute
  modules (IP53 node boards) with a router at `/hw/module/001r06/router`. It reports software
  inventory fields, so it is used for identity only and is described here without the unit's
  identifiers. It is not a listing of an Origin 300 system.

The guide page numbers below were rechecked against the published PDFs: the printed and PDF page numbers pair as stated, and each cited statement is on its page.

## Population

**Inferred.** The population and expansion rules below describe one rack. In it the router
enclosure joins base modules and expansion modules over NUMAlink 3. The NUMAlink 3 medium is not
cited separately for this enclosure.

**Established** (`007-4498-002 pp. 2, 93`; PDF pp. 28, 119). A tall rack holds two to eight base
modules. A short rack holds two to six. A one-base-module composition is outside the documented
system population.

**Established** (`007-4498-002 pp. 2, 93`; PDF pp. 28, 119). The global master is the lowest
base module.

**Established** (`007-4498-002 pp. 16, 98`; PDF pp. 42, 124). In a tall rack, the supported base
module counts for each number of PCI expansion modules are:

| PCI expansion modules | Supported base modules |
|---|---|
| 1 | 2 to 7 |
| 2 | 2 to 6 |
| 3 | 3 to 5 |
| 4 | 4 |

A short rack takes one expansion with two to four base modules, or two expansions with two base
modules. These are published packaging constraints. They are not a general routing-capacity
formula.

**Established** (`007-4499-001` and `007-4499-002`, printed p. 13; PDF p. 31). PCI expansion
modules do not work on ports 1, 6, 7 or 8. The guides do not give the electrical or protocol
reason for the restriction.

## Power and controllers

**Established** (`007-4498-002 pp. 14, 132`; PDF pp. 40, 158). In the DC module, a power bay
supplies 12 Vdc standby for the L1 logic and 48 Vdc for operating power. The rear switch controls
L1 power, and the L1 requests the 48 Vdc supply.

**Established** (`007-4498-002 pp. 14, 132`; PDF pp. 40, 158). In the AC module, the rack L2
receives 48 Vdc from a separate AC-powered supply.

These are physical functions. They say nothing about register or packet encodings.

## Router board identity

**Established for an Origin 350 / Onyx 350 rack** (public hinv listing). The router board in that rack
is part `030-1634-003`, board revision `-A`. The listing's hardware graph shows it as the router under
a rack module. The same part number also appears in an Origin 3000-class hinv listing, so it names a
router board used in more than one product. That the Origin 300's NUMAlink module carries this part
is **inferred**: no Origin 300 listing is held.

**Established** (`007-4498-002 p. 131`, figure A-9). The figure draws an enclosure with an
R-Brick label. The label does not settle the board part, the chip part or the revision.

**Conflict, unknown.** The Origin 350 / Onyx 350 listing reports the router's software revision as 1
with active ports 1 to 6. A report of five active ports was not found in the held listing, so the
five-port figure is left unverified. The board revision, the software-reported router revision and
the raw silicon revision are separate fields, and the listing does not show how they correspond.

The scan guide `108-0263-004` carries a confidential, internal-use legend. It is not used here.

## Unknown

| Open item | Evidence that would settle it |
|---|---|
| The router chip's part and revision, and whether the software revision 1 and the six active ports describe that chip | A public board specification, or a photograph of the board with readable chip markings |
| Whether the software revision maps to the silicon revision | A published capture tied to that board, with the router identity and revision registers identified separately |
| Controller board parts and the L1's USB branch connection | An existing matching controller inventory or a published schematic |
| USB protocol, the physical L1 personality, reset state and error behaviour | Not in the published guides, which give external controller and connector topology only |
| The electrical or protocol reason for the port 1, 6, 7 and 8 restriction | A published electrical description of the expansion connection |

The open router-identity items are also listed in [open-questions.md](../../questions/README.md).
