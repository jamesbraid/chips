# Published specifications held

Each is cited by title, document number and revision. The PDF is committed under `docs/sources/specs/`; its
text extraction is in the uncommitted `root/spec/` for searching (made with pypdf; the three scanned
specifications have no text layer, so their extraction is character recognition output and digits in it are
unreliable: read register tables from the page image). "Registers transcribed" says whether this repository
(or its census inputs) holds the register map as data.

| Chip | Title | Document number | Revision | Pages | Committed file | Text in `root/spec/` | Registers transcribed |
|---|---|---|---|---:|---|---|---|
| Bridge | Bridge ASIC Specification | none printed | 4.0 (for revision D silicon, 26 April 1998) | 178 | [bridge-asic-specification-rev4.0.pdf](sources/specs/bridge-asic-specification-rev4.0.pdf) | `bridge-rev4.0.txt` (OCR) | no (census compares against it by page) |
| XBridge | XBridge ASIC Specification | none printed | 0.5 | 254 | [xbridge-asic-specification-rev0.5.pdf](sources/specs/xbridge-asic-specification-rev0.5.pdf) | `xbridge-rev0.5.txt` (OCR) | no |
| Xbow | Crossbow ASIC Specification | none printed | 12.0 | 134 | [crossbow-asic-specification-rev12.0.pdf](sources/specs/crossbow-asic-specification-rev12.0.pdf) | `crossbow-rev12.0.txt` (OCR) | no |
| CRIME | CRIME 1.5 Specification | none printed | 0.3 (2 June 1997) | 236 | [crime-1.5-specification-rev0.3.pdf](sources/specs/crime-1.5-specification-rev0.3.pdf) | `crime-1.5-rev0.3.txt` | partial: tables 5-7, 6-12, 7-1, 7-2, 7-3, 7-15 in `scripts/inventory-config.json` |
| GBE | GBE ASIC spec | none printed | 1.1 (18 July 1996) | 50 | [gbe-specification.pdf](sources/specs/gbe-specification.pdf) | `gbe.txt` | partial: register map in `scripts/inventory-config.json` |
| MACE | MACE I/O ASIC Specification | none printed | chip revision 2.0 (31 May 1996) | 196 | [mace-specification.pdf](sources/specs/mace-specification.pdf) | `mace.txt` | no |
| VICE | VICE Design Specification | 099-0123-003 | 003 | 307 | [vice-design-specification-099-0123-003.pdf](sources/specs/vice-design-specification-099-0123-003.pdf) | `vice-099-0123-003.txt` | no |

Not held, so these chips are no-spec: Hub, Bedrock, HEART, PIC, TIOCP, IOC3, IOC4. Public drivers and patents
that describe parts of them are in [published-sources.md](published-sources.md). Where a chip has a spec the
census runs spec-backed (diff against the spec); otherwise it runs no-spec (inventory from the binaries).

A spec revision here is the one that was held; the Bridge, XBridge and Crossbow revisions differ in silicon, so
a Bridge fact is not an XBridge fact until the XBridge specification or a binary path for XBridge says so.
