# MSCSI: the four-channel SCSI XIO board

The MSCSI is an XIO board for the Origin 2000 and Onyx2, and for the GIGAchannel of the Origin 200. It carries one
Bridge and four QLogic ISP1040 SCSI controllers on the Bridge's PCI bus. The PROM types it as board type `0x22`, the
SCSI type, which the [Crosstown page](../crosstown-ktown/README.md#prom-classification-of-the-origin-200-crosstown-board) lists
with the other classifier prefixes. The controller contract is on [the ISP1040 page](../isp1040/README.md) and the Bridge
contract is on [the Bridge page](../../chips/bridge/README.md). This page holds the board's composition, its listed
revisions and placements, what IRIX prints for it and what is unknown.

Status: draft, imported from published sources. The IRIX kernel strings are read as strings only; the routine that
prints them was not read, so the bus-type rows below are software expectations.

Grades follow [AGENTS.md](../../AGENTS.md): **established** means a manual, a real listing or a routine read in full
states it; **inferred** means a reasoned reading, including what a kernel string or a driver implies; **unknown**
means no held source settles it.

## Composition and part numbers

| Property | Grade | Evidence |
|---|---|---|
| One XIO board: a Bridge and four ISP1040 SCSI controllers on the Bridge's PCI bus | established | real `hinv` listings: an Origin 2000 PROM `hinv -v` shows an `ASIC BRIDGE` and `adapter PCI-SCSI` at `pci id` 0 to 3 under one `MSCSI IO Board` |
| Part `030-0872-004` is the PCA MSCSI, and part `030-1243-001` is the PCA MSCSI B | established | SGI HMM-408-B, *Origin2000/Onyx2 Illustrated Parts Catalog*, printed and PDF page 33, "XIO Options" |
| Part `030-1281-001` is also an MSCSI board part | established | Origin 200 GIGAchannel `hinv -vm` on the Higher Intellect wiki's Origin 200 page, board at `io2` |
| The PROM types all three part prefixes `0x22` (`KLTYPE_MSCSI`) | established | [the Crosstown page](../crosstown-ktown/README.md#prom-classification-of-the-origin-200-crosstown-board), prefixes `030-0872-`, `030-1243-` and `030-1281-` |
| Revisions seen: `030-1243-001` rev F, rev G and rev M; `030-1281-001` rev D | established | the wiki's Origin 200 `hinv -vm` (rev F, rev D); a December 2001 comp.sys.sgi.hardware owner's inventory (rev G); a two-module Origin 200 `hinv -vm` posted to the Nekochan forum on 9 September 2016, thread 16731033 (rev M) |
| Four SCSI controllers at PCI devices 0, 1, 2 and 3 | established | the Origin 2000 PROM `hinv -v` above, and the wiki's Origin 200 listing |

## Placement and printed names

| Property | Grade | Evidence |
|---|---|---|
| `hinv` prints `Origin MSCSI board, module N slot M: Revision R` | established | the wiki's Origin 200 listing (`module 1 slot N`, revision 3); the 2016 Origin 200 listing (`module 2 slot 5`, revision 4) |
| Origin 200 GIGAchannel placements: `io2` and `io4` in one module; `io5` and `io6` in a two-module system | established | the two listings above |
| Origin 2000 placement: `MSCSI IO Board, Module 1, Slot io7` | established | the Origin 2000 PROM `hinv -v` in the Nekochan thread "Origin is sick", thread 16727716 |

## Bridge revision on the board

| Fact | Value | Grade and evidence |
|---|---|---|
| Bridge revision on the Origin 2000 board | Revision 3 | established: the same listing prints `ASIC BRIDGE Rev 3, (widget 14)` |
| Bridge revision on the rev M boards | Revision 4 | inferred. The 2016 listing prints `Revision 4` on the board line, and this page reads that number as the Bridge revision, as [the Bridge page](../../chips/bridge/README.md) reads the board-line number for other boards. The board line does not name the Bridge, so the reading is not checked against a Bridge line on that board |
| The wiki's Origin 200 boards | Revision 3 on the board line | inferred as the Bridge revision, on the same reading. No Bridge line for those boards is quoted |

## Controller labels

The Origin 2000 listing prints each controller as `adapter PCI-SCSI Rev 5`. [The ISP1040 page](../isp1040/README.md) explains
that the revision label on SGI inventory output names a version, not the PCI revision byte, so this label is not
read as that byte here. What each controller's revision byte is: **unknown**.

## Bus type per channel

| Fact | Value | Grade and evidence |
|---|---|---|
| IRIX's `Probing MSCSI/A` and `Probing MSCSI/B` messages name an internal single-ended bus on channel 0 and external buses that are single-ended or differential | software expectation | inferred. Five messages in the IRIX 6.5.30 IP27 kernel name these buses. The routine that prints them was not found or read, so the mapping of channels to bus types is not established |
| At least two of the MSCSI controllers are differential | inferred | The 2016 Origin 200 listing prints nine of its fifteen QL1040B controllers as differential. At most seven of the fifteen sit off the MSCSI boards (two on the IP29, four in the cabinet's PCI openings, one PCI card on the IP29 Bridge). Nine differential less at most seven leaves at least two on the MSCSI boards. The count is from the listing as the source record gives it, not re-read here |
| The BaseIO's own two SCSI controllers are single-ended | established | [the BaseIO page](../baseio/README.md#pci-placement-on-a-baseio-g), from an owner's listing. This is a different board and is not evidence for the MSCSI |

## Unknown

- Which of the four controllers on a given MSCSI is differential, and how IRIX learns that. A capture of one MSCSI
  with its controllers' bus types, or the IRIX routine behind the `Probing MSCSI` messages read in full, would settle it.
- Whether the number on the board line is the Bridge's revision on the rev M and wiki boards. A Bridge line from one
  of those boards would settle it.
- What the `Rev 5` label means on the controllers. The PCI revision byte of each controller on a real MSCSI is not held.
- The slot rules, interrupt wiring and per-slot enable words of the MSCSI. No source held here gives them. They belong
  on a board page that holds the IRIX board routine, which this checkout does not have.

## Sources

- SGI HMM-408-B, *Origin2000/Onyx2 Illustrated Parts Catalog*, printed and PDF page 33, "XIO Options".
- Real listings, each a public `hinv` output:
  - the Higher Intellect wiki's Origin 200 page, a one-module GIGAchannel `hinv -vm`;
  - the Nekochan forum thread 16727716, "Origin is sick", an Origin 2000 PROM `hinv -v`;
  - the Nekochan forum thread 16731033, a two-module Origin 200 `hinv -vm`, posted 9 September 2016;
  - a December 2001 comp.sys.sgi.hardware owner inventory with an MSCSI `030-1243-001` rev G.
- The IRIX 6.5.30 IP27 kernel: the three part prefixes and the `Probing MSCSI/A` and `Probing MSCSI/B` messages, read as
  strings only.
- The PROM classifier table in [the Crosstown page](../crosstown-ktown/README.md), which is established by disassembly of the IP27 PROM 6.156.
- Existing reviewed contracts: [ISP1040](../isp1040/README.md), [Bridge](../../chips/bridge/README.md) and [BaseIO](../baseio/README.md).
