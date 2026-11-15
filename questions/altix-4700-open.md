# Altix 4700 and 450: what the manuals and Linux do not settle

Question. How are the IRU's blades wired to its routers, which bridge sits on each expansion blade, and what does the PROM
report for each?

Status: **unknown** for everything below. What is established is on [the IRU page](../platforms/sn2/altix-4700-iru.md),
[the discovery page](../platforms/sn2/altix-4700-discovery.md) and [the graphics page](../platforms/sn2/graphics-attachment.md).

- **Blade to router port map.** The block diagrams (007-4823-001 Figure 3-4, p.48; 007-4857-001 Figure 3-4, p.65) draw ports
  A to H on each router, but the lettering does not say which port each blade slot uses, which ports are inter-router, or which two
  are the external NUMAlink connectors. Route: the PROM's port graph on a running machine (`ENUM_PORTS`), or a router
  specification. The held SHub 2 PROM may carry the wiring table.
- **Which bridge on which expansion blade.** PIC, TIOCP and TIOCE all have providers in SGI's Linux code; no document says the
  two-slot PCIe blade carries a TIOCE or the three-slot PCI-X blade a TIOCP or PIC. Route: a boot capture's bus list with ASIC types,
  or the PROM's bus-record builder.
- **Base I/O chips.** The IA blade's disk, SATA/SAS, Ethernet and USB controllers and their bridge; the guide lists connectors only.
  Linux names the IOC4 for the IO9 and IO10 cards of the earlier machines, not for the IA blade.
- **Slab numbering.** Which slab number a SHub, a TIO and a router carry within a blade or router board (the location string
  has a slab field).
- **Compute board codes.** Which of `IP69`, `IP63` and the printed `IP73_667` is which blade, and whether any is SHub 2.
- **Altix 450.** SHub generation (the PROM package README says the SHub 2 image supports it from 10.23, vendor intent only)
  and whether the blades are identical to the 4700's.
- **Dense router.** Which 16 of the 32 router channels (four boards of eight, 007-4823-001 p.61) reach the 16 front connectors, and whether the router commands of the controller apply to
  the IRU routers.
- **Graphics blade.** The 4700 graphics board's chip, the bridge on its PCIe slot, and whether the PROM publishes a console
  entry for it. Route: a PROM string search in the held SHub 2 image, or any 4700 boot capture.
