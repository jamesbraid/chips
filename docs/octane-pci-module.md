# OCTANE PCI module (the Octane PCI card cage)

The OCTANE PCI module is the optional three-slot PCI card cage of the Octane and Octane2. It takes its own
Crossbow port, separate from the four XIO option slots, and carries one Bridge. The Bridge's register contract
is in [bridge-family.md](bridge-family.md). The port and the Bridge's presence behind it are already on the
[XBow family page](xbow-family.md) and the Bridge page. This page adds the module's physical slot layout and
its electrical limits, which the chips repository did not record.

Grades: **established** means a published SGI specification or a public driver states the fact. **Inferred**
means a reading of one. **Unknown** means no source here settles it.

## Slots

- **Count and size.** The module takes at most three boards, full or half size. The allowed mixes are two full
  and one half, one full and two half, or three half. The guide allows boards with extra-long I/O connectors.
  **Established**: SGI *OCTANE PCI Module Installation Guide* 007-3547-001, printed page 3.
- **Software names equal physical positions.** The top slot is PCI ID #1, the middle slot is PCI ID #2 and the
  bottom, half-size slot is PCI ID #3. The guide says the physical and software designations are the same.
  **Established**: 007-3547-001, printed page 13 and Figure 1-10.
- **Slot to configuration device.** Whether slot N is wired to Bridge configuration device N is **unknown**.
  No source here states the IDSEL wiring. What would settle it: a configuration read at Crossbow port 13 that
  returns a card's vendor and device identity from a known slot, or a published board document that ties the
  slot labels to IDSEL lines.

## Power and environment

- **Signalling environment.** The module is a 5-volt system. **Established**: 007-3547-001, printed page 3.
- **Power budget.** The total for all boards on all rails must not exceed 45.0 W, which is 15.0 W per board on
  average. **Established**: 007-3547-001, printed page 3.
- **Per-rail maxima.** Table 1-1 of the same guide gives these per-rail limits:

  | Rail | Maximum current | Maximum power |
  |---|---|---|
  | 3.3 V | 10.0 A | 33.0 W |
  | 5.0 V | 9.0 A | 45.0 W |
  | 12.0 V | 1.5 A | 12.0 W |
  | -12.0 V | 0.3 A | 3.6 W |

  **Established**: 007-3547-001, printed page 3. The four rail maxima add up to 93.6 W, which is more than the
  45.0 W total. The guide states the total as the sum over all rails, so the total is the binding limit and the
  rail figures are ceilings for each rail. The guide does not say how the two combine beyond that.
- **Power is a published rating.** The module reports nothing about its load.

## Mechanical

- Boards with extra-long I/O connectors fit through an opening in the I/O door. **Established**: 007-3547-001,
  printed page 3.

## Not yet in this repository

These facts appear in secondary notes but have not been checked against the published sources here, so this
page does not state them:

- The module's identity: its SGI name, part number, the `hinv` board name and the revisions seen in the field.
- The `hinv` location of the module, `/hw/node/xtalk/13`, and the hardware-graph paths `pci/1` to `pci/3` under it.
- The interrupt pin wiring of each slot. The general rule for the Bridge's pin pairs is already a software
  convention on the [IP35 IO9 wiring note](questions/ip35-io9-pci-wiring.md); no board trace for this module is held.
- Whether devices 0 and 4 to 7 answer. Unknown.
- The width of each slot, 32-bit or 64-bit. Unknown.
- The module's Bridge revision. Unknown. See [open-questions.md](open-questions.md).
- The module's one-wire identity record, and whether PROM output names it. Unknown.

What would settle these: a read of the Technical Report pages the secondary notes cite, a `hinv` listing from a
module-equipped machine checked against the guide, or a board trace.
