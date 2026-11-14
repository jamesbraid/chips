# SGI system ASICs: register-level reverse engineering

## Start here

- Writing a decoder, a model or any other tool that needs the register layouts: take the register maps from [generated/c](generated/c) (C headers) and
  [generated/rust](generated/rust) (a Rust crate); [generated/python](generated/python), [generated/json](generated/json)
  and [generated/xml](generated/xml) carry the same facts. Never edit them: they come from the register maps.
- Understanding one chip, board or card: read `devices/<unit>/`. `README.md` says how the hardware works, with no
  assumption about the operating system; `registers.toml` is the hand-edited register map and `registers.md` its
  generated, browsable table. Machines and their boot and PROM behaviour are in [platforms/](platforms/).
- How IRIX drives a part: [software/](software/), which links back to the device pages.
- What is covered, and what is not settled: [evidence/coverage.md](evidence/coverage.md), and
  [questions/](questions/) for the open questions with what would settle each.

What each system ASIC of the SGI Origin, Onyx, Octane, Fuel, Tezro and O2 machines does, read from the shipped IRIX 6.5.30
kernels, drivers, diagnostics and PROM images, checked against the published specifications and the public
Linux and OpenBSD drivers. Software only: no hardware is needed or assumed.

Chips covered (one directory each in [devices/](devices/)): Hub (PI, MD, IO, NI), Bedrock, HEART, Xbow,
Bridge and XBridge, PIC, TIOCP (only if a product carries it), the network router, the router scan-chain tunnel, the L1 and ELSC system
controllers (host-visible side), IOC3, IOC4, CRIME, MACE, GBE, VICE (presence), and the audio parts of the DMediaPro DM8
(ICE1724 and its converters, [devices/dm8/README.md](devices/dm8/README.md)), with stubs for the RAD and EMU10K2 audio
controllers and a [survey of the audio options](evidence/audio-survey.md) of the Fuel, Tezro and Octane.
Builds are named by board, never by product: IP27, IP30, IP32, IP35.

The layout and working style follow Dominik Behr's
[gr2](https://github.com/techomancer/gr2) and
[gr4](https://github.com/techomancer/gr4), as do the sibling graphics workspaces.
Proprietary IRIX binaries are not tracked; copy them from your own IRIX install into the
ignored `root/` directory as [evidence/irix-files.md](evidence/irix-files.md) describes.

- [AGENTS.md](AGENTS.md): the rules, the labels, the working procedure and the rules for reading MIPS code.
- [evidence/reading-brief.md](evidence/reading-brief.md): how to run a census and write entries, for a cheap worker.
- [evidence/irix-files.md](evidence/irix-files.md): the shipped files the repository reads (not committed).
- [references/documents/specs.md](references/documents/specs.md): the published specifications held here, with coverage.
- [references/documents/published-sources.md](references/documents/published-sources.md): public drivers and other sources.
- [references/documents/INDEX.md](references/documents/INDEX.md): every public source with its pin and URL: the Linux, OpenBSD, NetBSD, GXemul and MAME
  submodules, older Linux trees for SN1, SN2 and IP27, the IP30 port and the sources recorded by URL only.
- [evidence/coverage.md](evidence/coverage.md) and [evidence/inventory/](evidence/inventory/): measured coverage.
- [questions/README.md](questions/README.md): what is not settled and the next route.
- [devices/xio_fc/README.md](devices/xio_fc/README.md): the XIO Fibre Channel board (AIC-1160) and its `fcadp` driver contract.
- [devices/dm2/README.md](devices/dm2/README.md): scoping datasheet for the DMediaPro DM2 (XT-DIGVID) XIO video board and, at lower depth, DIVO.
- [devices/tl16pir552/README.md](devices/tl16pir552/README.md): TI TL16PIR552 parallel port on the Fuel and Origin 200 boards: the part's register contract and mode values from the TI datasheet, the board marking evidence, and what is unknown about Fuel wiring; the register contract is in [devices/tl16pir552/registers.md](devices/tl16pir552/registers.md).
- [devices/router_origin2000/README.md](devices/router_origin2000/README.md): the Origin 2000 and Onyx2 six-port CrayLink router: ports, message and micropacket layout, virtual channels, age, histogram selectors, the Router boards, and what is unknown; the register offsets are in [devices/router_origin2000/registers.md](devices/router_origin2000/registers.md).
- [devices/isp1040/README.md](devices/isp1040/README.md): QLogic ISP1040 SCSI adapter on the BaseIO: identity and revision, mailbox commands, status entries and what the public drivers leave open; the register contract is in [devices/isp1040/registers.md](devices/isp1040/registers.md).
- [devices/isp12160/README.md](devices/isp12160/README.md): QLogic ISP12160 dual-channel SCSI adapter on the Origin 300 IO-8 and Origin 350 IO9 boards: identity, bus count, mailbox opcodes the shipped programs send, and what is unknown; the constants are in [devices/isp12160/registers.md](devices/isp12160/registers.md).
- [devices/lucent_ohci/README.md](devices/lucent_ohci/README.md): AT&T/Lucent 11C1:5802 two-port OHCI USB host controller on the Origin 300 IO-8: identity, PCI configuration values, operational register expectations, root-hub port power, the board diagnostics, and what is unknown; the register contract is in [devices/lucent_ohci/registers.md](devices/lucent_ohci/registers.md).
- [devices/tsb12lv22/README.md](devices/tsb12lv22/README.md): TI TSB12LV22 PCI-to-1394 OHCI 1.00 link controller on the I-brick IO7: product boundary, PCI configuration, reset and interrupt rules, the PHY and DMA gaps, and the shipped PROM and IRIX expectations; the register contract is in [devices/tsb12lv22/registers.md](devices/tsb12lv22/registers.md).
- [devices/aic7880/README.md](devices/aic7880/README.md): Adaptec AIC-7880, the O2 onboard SCSI controller: host DMA, COMMAND-phase DMA and SCB page storage (external SRAM, parity, queues) from the published AIC-7870 data book, graded as sibling inference, and what is unknown; the register contract is in [devices/aic7880/registers.md](devices/aic7880/registers.md).
- [devices/isp2200/README.md](devices/isp2200/README.md): QLogic ISP2200 Fibre Channel host adapter on the Origin 3000 I-brick: identity, register window, reset and RISC control, mailbox commands, rings and interrupts, and what is unknown; the register contract is in [devices/isp2200/registers.md](devices/isp2200/registers.md).
- [platforms/ip32/cpu-cache.md](platforms/ip32/cpu-cache.md): the R10000's primary instruction and data caches and secondary cache as the O2 uses them (geometry, cache algorithms and the TLB fields that select them, instruction-cache diagnostics, CACHE operations and their writeback rules, index operations with their tag and data formats, aliases) and CRIME 1.5's noncoherent processor interface, with what is unknown. It holds no register contract.
- [devices/r10000_identity/README.md](devices/r10000_identity/README.md): the R10000 family's PRId identity word (implementation and revision, the R14000 and R16000 split), the Config secondary cache size and line fields, and what is unknown.
- [devices/r10000_fpu/README.md](devices/r10000_fpu/README.md): the R10000 family's floating-point handling of denormalized inputs with the FCSR flush bit clear, the R12000 rules with the bit set, the CVT.L range, the Cause E bit that reports them, and what is unknown for the R16000. The constant is in [devices/r10000_fpu/registers.md](devices/r10000_fpu/registers.md).
- [devices/r10000_diagnostic/README.md](devices/r10000_diagnostic/README.md): the R10000 family's branch Diagnostic register (CP0 register 22): the R10000 and R12000 field positions, what the Linux driver does with the bits, the inferred R16000 layout, and what is unknown. The constants are in [devices/r10000_diagnostic/registers.md](devices/r10000_diagnostic/registers.md).
- [devices/r10000_secondary_cache_ecc/README.md](devices/r10000_secondary_cache_ecc/README.md): the R10000 family's secondary-cache check matrix for the data array, the syndrome classification it allows, the correction and Cache Error delivery rules, and the CP0 CacheErr fields for a secondary error, with what is unknown. The constants are in [devices/r10000_secondary_cache_ecc/registers.md](devices/r10000_secondary_cache_ecc/registers.md).
- [devices/r10000_cp0/registers.md](devices/r10000_cp0/registers.md): the R10000 CP0 Count and Compare register numbers, the Cause bit that carries the timer interrupt, and the TLB entry count and ASID width the shipped IRIX kernel assumes (graded inferred)
- [devices/r14000_perf_counters/README.md](devices/r14000_perf_counters/README.md): the R12000 and R14000 CP0 register 25 performance counters: the four control and counter pairs and their selectors, the control field positions, the event numbers, the counter width and overflow bit, and what is unknown for the R14000. The constants are in [devices/r14000_perf_counters/registers.md](devices/r14000_perf_counters/registers.md).
- [devices/r14000/README.md](devices/r14000/README.md): the R14000 processor as the public R10000-family manuals describe it: the Config register reset and write rules, the big-endian narrow store lanes, the partial LWR result, and what is unknown for the R14000. The Config constants are in [devices/r10000_config/registers.md](devices/r10000_config/registers.md).
- [devices/r16000/README.md](devices/r16000/README.md): the R16000 processor as the public sources describe it: the identity word, how printed revisions (offset by two in OpenBSD) relate to the raw word, the printed FPU and cache lines of the 1.0 GHz and 700 MHz parts, what software expects, and what is unknown. The identity constants are in [devices/r10000_identity/registers.md](devices/r10000_identity/registers.md).
- [devices/r5000/README.md](devices/r5000/README.md): the NEC VR5000 (R5000 family) processor as the NEC user's manual and the MIPS overview describe it: the PRId and FCR0 identity words (the O2 values are owner reports), cold, soft-reset and NMI entry, the Config, Status, PageMask, LLAddr and FCR31 fields, the caches and CACHE operations, and what is unknown. The constants are in [devices/r5000_identity/registers.md](devices/r5000_identity/registers.md) and [devices/r5000_cp0/registers.md](devices/r5000_cp0/registers.md).
- [devices/r12000a_variant/README.md](devices/r12000a_variant/README.md): the NEC VR12000A's differences from the R12000: the SysClkDiv, SCClkDiv and HSTL mode fields, and the 9-bit read-only syndrome in CP0 register 25 control 0, with what is unknown. The constants are in [devices/r12000a_variant/registers.md](devices/r12000a_variant/registers.md).
- [platforms/bricks/ixbrick.md](platforms/bricks/ixbrick.md): the Origin 3000 and Onyx 3000 IX-brick I/O enclosure: slots and bus rules, the IO9 card, drives, USB card, power and management, PIC wiring as drawn, and what is unknown. It holds no register facts.
- [platforms/bricks/pxbrick.md](platforms/bricks/pxbrick.md): the Origin 3000 and Onyx 3000 PX-brick PCI-X I/O enclosure: the enclosure size and its conflicting figures, the PIC wiring as drawn, the L1 `ioport` output, bus and slot rules, the L1 brick-type constants and what is unknown. It holds no register facts.
- [platforms/bricks/xbrick.md](platforms/bricks/xbrick.md): the Origin 3000 and Onyx 3000 X-brick XIO enclosure: the XBridge port roles, the slot and connector wiring as drawn and its conflicts, the Crosstown2 rates, the supported XIO boards, the L1 and its firmware personality, and what is unknown. It holds no register facts.
- [platforms/bricks/pbrick.md](platforms/bricks/pbrick.md): the Origin 3000 and Onyx 3000 P-brick I/O enclosure: slot and bus layout, the three XBridge chips as drawn, the widget-to-bus map, host routing, power and L1 identity, and what is unknown. It holds no register facts.
- `devices/<chip>/census/`: register-access censuses per chip, produced by [tools/](tools/).

### Every document

Generated tables under `evidence/inventory/` and the generated block of `evidence/coverage.md` are listed above, not here.

Audio:

- [devices/dm8/README.md](devices/dm8/README.md): DMediaPro DM8 PCI audio option, not an SGI ASIC board.
- [software/kernel/audio-drivers.md](software/kernel/audio-drivers.md): Audio driver objects and config lines in IRIX 6.5.30 and 6.5.22.
- [evidence/audio-survey.md](evidence/audio-survey.md): Audio options of the Fuel, Tezro and Octane.
- [devices/rad1/facts-outside-registers.md](devices/rad1/facts-outside-registers.md): RAD1 audio ASIC facts outside its register file (placement, PCI status, byte order, DMA request, the PCI audio board of revision 0xd0 and its UST and analog differences, and the Tezro audio correction); the register contract is in [devices/rad1/registers.md](devices/rad1/registers.md).

Kernel object scope:

- [evidence/binaries-scope-chip-drivers.md](evidence/binaries-scope-chip-drivers.md): Chip driver objects in the IP27, IP30, IP32 and IP35 kernel builds.
- [evidence/binaries-scope-filesystem.md](evidence/binaries-scope-filesystem.md): File-system objects in the kernel builds.
- [evidence/binaries-scope-kernel-objects.md](evidence/binaries-scope-kernel-objects.md): Excluded kernel objects of the IP27 build.

Crosstalk, XIO and interconnect:

- [devices/bridge/family.md](devices/bridge/family.md): Bridge, Xbridge and PIC as Crosstalk widgets.
- [devices/pic/facts-outside-census.md](devices/pic/facts-outside-census.md): PIC facts outside the register census: error bits and clears, empty-slot probes, the PROM diagnostic's 0x7c write, 64-bit store order, Origin 350 slot labels and force registers.
- [devices/crosstalk/host-ends.md](devices/crosstalk/host-ends.md): Crosstalk host ends: HEART, Hub and Bedrock.
- [devices/crosstalk/README.md](devices/crosstalk/README.md): Crosstalk (XIO): the link, its widgets and its host ends.
- [devices/crosstalk/packets.md](devices/crosstalk/packets.md): Crosstalk packets and the link under them.
- [devices/octane-pci-module/README.md](devices/octane-pci-module/README.md): OCTANE PCI module (the Octane three-slot PCI card cage): slot count and sizes, software slot names, the power budget and per-rail limits, and what is unknown.
- [platforms/ip27/pci-discovery.md](platforms/ip27/pci-discovery.md): PCI discovery on the Origin 200 Bridge: the device-number map of its base I/O and option slots, the dual-slot guest at device 3, and how IRIX walks device numbers 0 to 7.
- [devices/baseio/README.md](devices/baseio/README.md): BaseIO and BaseIO-G: the XIO I/O board of the Origin 2000 and Onyx2, its PCI placement, interrupt paths, panel and one-wire identity records.
- [devices/menet/README.md](devices/menet/README.md): MENET (030-0873), the four-port Fast Ethernet and asynchronous serial XIO board: its four IOC3s, the subdevice words and second slots IRIX gives them, interrupt pins, board record and what is unknown.
- [devices/mscsi/README.md](devices/mscsi/README.md): MSCSI (030-0872, 030-1243, 030-1281), the four-channel SCSI XIO board: one Bridge and four ISP1040 controllers, its listed revisions and placements, the bus-type evidence and what is unknown.
- [devices/pci-shoebox/README.md](devices/pci-shoebox/README.md): PCI shoebox (the Origin 2000 PCI carrier, 030-1062): one XIO slot giving three PCI slots on one Bridge, its board type and names, how it differs from the Octane PCI module, and what is unknown.
- [devices/pci-shoehorn/README.md](devices/pci-shoehorn/README.md): PCI shoehorn (030-1275), the single-slot XIO-to-PCI adapter with one Bridge: identity and revisions, the Octane and Origin 2000 placements, the slot and interrupt wiring software expects, the PROM and IRIX output, and what is unknown.
- [platforms/ip27/node-configuration.md](platforms/ip27/node-configuration.md): Origin 2000 node board clock, Hub and secondary-cache configuration: the published 180 MHz and 195 MHz configurations, node PROM mixing and copy rules, and the boot-flash configuration block; it holds no register contract.
- [platforms/ip27/power-and-reset-domains.md](platforms/ip27/power-and-reset-domains.md): which parts of an Origin 200 or Origin 2000 sit in which power domain (standby, module, battery), what each reset and NMI reaches and what survives it, the R10000 entry kinds, and what is unknown. It links the register pages for the Hub, Router, Crossbow and timekeeper.
- [devices/crosstown-ktown/README.md](devices/crosstown-ktown/README.md): Crosstown, KTOWN, Ktown2 and Xtown2: the XIO-over-cable conversion boards.
- [platforms/bricks/graphics-topology.md](platforms/bricks/graphics-topology.md): Onyx 3000 graphics bricks: where a G-brick pipe and a V-brick V12 sit, and the smallest configuration.
- [platforms/bricks/gbrick.md](platforms/bricks/gbrick.md): Onyx 3000 G-brick: the 18U enclosure and its slot rule, the InfiniteReality3 and InfiniteReality4 pipe board sets, raster manager counts per pipe, the N-brick's pipe connectors, the L1 and what is unknown. No register contract.
- [platforms/bricks/cbrick.md](platforms/bricks/cbrick.md): Origin 3000 C-brick (partial): the R16000 PIMM clock options and the L1's USB channel, with the manual citations and what is unknown.
- [platforms/bricks/powerbay.md](platforms/bricks/powerbay.md): Origin 3000 power bay: the 3 U supply unit, its `pbay` command set and ICMB link, the retained 5,888-byte controller image, and what is unknown. It holds no register contract.
- [platforms/bricks/cxbrick.md](platforms/bricks/cxbrick.md): Origin 3000 Cx-brick: node boards, memory-only nodes, the router board, XIO connectors, brick naming and what is unknown.
- [platforms/bricks/size-ladder.md](platforms/bricks/size-ladder.md): Origin 3000 and Onyx 3000 size ladder: brick counts, routers per rack, MetaRouters, rack numbering, bay and I/O rack rules and maximum processors for the 3200, 3400, 3800 and 3900, with the L1 and L2 firmware cross-check and the conflicts between sources. No register contract.
- [platforms/bricks/rbrick.md](platforms/bricks/rbrick.md): Origin 3000 R-brick: the router enclosure, its eight NUMAlink 3 ports and USB rule, the six-port limit, the L1 and L2 paths, the routed configurations and what is unknown. Its register fields are in `devices/router_origin3000_rbrick/registers.toml`.
- [platforms/ip35/nasid-numbering.md](platforms/ip35/nasid-numbering.md): Origin 3000 NASID numbering: how the IP35 PROM computes hub node numbers from the router graph, its offset and coarse-mode rules, what IRIX does with them and what is unknown. No register contract.
- [platforms/bricks/dbrick.md](platforms/bricks/dbrick.md): Origin 3000 D-brick: the Fibre Channel disk enclosure, its loop attachment, its lack of an L1 and what is unknown.
- [platforms/bricks/origin300-numalink-module.md](platforms/bricks/origin300-numalink-module.md): Origin 300 NUMAlink module (router enclosure): base and PCI expansion population, power, the port 1, 6, 7 and 8 restriction, router board identity and what is unknown. No register contract.
- [platforms/bricks/origin300-pci-expansion-module.md](platforms/bricks/origin300-pci-expansion-module.md): Origin 300 PCI expansion module: the direct NI cable, the BIC's Bedrock and three XBridge chips, the widget-to-bus map, the XBridge and Super Bridge modes, the PCI data width and what is unknown. No register contract.
- [evidence/interconnect-naming.md](evidence/interconnect-naming.md): SGI interconnect naming: every name, from the deepest source.
- [devices/xbow/family.md](devices/xbow/family.md): Crossbow (XBOW), XXBOW and PXBOW: the XIO switch family.

Chip coverage pages:

- [devices/bedrock/coverage.md](devices/bedrock/coverage.md): Bedrock coverage: processor-interface error clear semantics.
- [devices/bedrock_xb/README.md](devices/bedrock_xb/README.md): Bedrock internal crossbar: register block, first-error latching and what is unknown.
- [devices/bedrock_ii/README.md](devices/bedrock_ii/README.md): Bedrock I/O interface: block transfer engines, processor and widget access gating, link control and what is unknown.
- [devices/hub/bte.md](devices/hub/bte.md): Hub block transfer engines: the engine slots and control bits added from the public header, the poison bit's documented status and what is unknown.
- [devices/hub/io-interface.md](devices/hub/io-interface.md): Hub I/O interface: the widget face, protection registers, link control, interrupt destination and big-window translation entries that the public header adds, and the open conflicts with the census.
- [devices/hub_pi/README.md](devices/hub_pi/README.md): Hub processor interface: the protection, cross-call, self-test, graphics and check registers, the real-time clock control and cached-alias layouts, and the Cause bits of the Hub interrupt lines that the public header adds, with the rate evidence and what stays open.
- [devices/hub_ni/README.md](devices/hub_ni/README.md): Hub network interface: the status and identity fields, port reset, port error and parameter layouts, vector routing fields and ageing controls that the public header adds, the open conflicts in that header and what stays open.
- [devices/hub_md/README.md](devices/hub_md/README.md): Hub memory and directory: the field layouts the public header adds (memory configuration, bank size codes, error latches, migration thresholds, one-wire control) and what stays open.
- [devices/bedrock_lb/README.md](devices/bedrock_lb/README.md): Bedrock local block: node identity, access vectors, error bits, real-time clock source, scratch locks, vector I/O and what is unknown.
- [devices/bedrock_md/README.md](devices/bedrock_md/README.md): Bedrock memory and directory: register layouts, backdoor carriers, directory words, check codes, error records and what is unknown.
- [devices/bedrock_ni/README.md](devices/bedrock_ni/README.md): Bedrock network interface: the NUMAlink port registers, port error bits, routing tables and what is unknown.
- [devices/bedrock_pi/README.md](devices/bedrock_pi/README.md): Bedrock processor interface: interrupt banks and masks, real-time compares, graphics credits, error capture and what is unknown.
- [platforms/ip35/prom-md-config.md](platforms/ip35/prom-md-config.md): IP35 PROM: every store to the memory controller's bank configuration word during boot, what each does and how many layout changes a boot makes.
- [evidence/hub-bedrock-config-write-timing.md](evidence/hub-bedrock-config-write-timing.md): Hub and Bedrock: when a node-number, cached-alias, region-present or memory-configuration write takes effect, what the chips document (nothing held) and the barriers, delays and rendezvous the PROMs and IRIX 6.5.22 and 6.5.30 put around each write.
- [evidence/runtime-address-decode-changes.md](evidence/runtime-address-decode-changes.md): Hub and Bedrock: what changes the meaning of an address after boot under IRIX 6.5.22 and 6.5.30 (I/O big windows, directory poison, flash timing, protection of the first pages), and the partition, hot-plug and bank-disable routines that turn out to be stubs or deferred to the next PROM run.
- [devices/crime/coverage.md](devices/crime/coverage.md): CRIME coverage: two coverage questions graded beyond the chip page.
- [devices/ioc3/coverage.md](devices/ioc3/coverage.md): IOC3 coverage: what the shipped software and public drivers settle.
- [devices/cad-duo-pci-card/README.md](devices/cad-duo-pci-card/README.md): Cad Duo PCI card (030-1155-002), an IOC3 option board with Ethernet and PS/2 and no serial ports: its board record, the one-wire parts it likely carries, the interrupt line its keyboard uses, and what is unknown.
- [devices/dual-serial-pci-card/README.md](devices/dual-serial-pci-card/README.md): Dual-serial PCI card (030-1657), an IOC3 option board with serial A and B and no Ethernet: its enable word, interrupt line, how the PROM recognises it, and what is unknown.
- [devices/ds1685/README.md](devices/ds1685/README.md): DS1685/DS1687 real-time clock and 242-byte battery-backed RAM of the Octane system board: banks, the update cycle, interrupts, kickstart and RAM clear, and what is unknown. The register contract is in `devices/ds1685/registers.toml`.
- [devices/ds1742/README.md](devices/ds1742/README.md): DS1742W 2 KiB battery-backed RAM and clock of the Fuel L1: package and pins, the clock bytes, the read freeze, what the Fuel board evidence supports and what is unknown. The register contract is in `devices/ds1742/registers.toml`.
- [platforms/ip34/system-timekeeper.md](platforms/ip34/system-timekeeper.md): Fuel system Timekeeper (IP34): the separate clock and PROM-variable assembly the owner reports support, the driver's byte map and year base for the system clock, and what is unknown. Prose only: the fitted part is unidentified, so it has no register map.
- [devices/ds1744/README.md](devices/ds1744/README.md): DS1744 32 KiB battery-backed SRAM and clock: package and interface, the clock bytes, the battery flag, the read freeze, and the IO9 board questions that are unknown. The register contract is in `devices/ds1744/registers.toml`.
- [devices/ds2502/README.md](devices/ds2502/README.md): DS2502 1-Wire add-only memory: the ROM, the command set, the EPROM and status layout, the timing windows, and the O2 identity-part questions that are unknown. The constants are in `devices/ds2502/registers.toml`, and the NIC line bits in `devices/mace/registers-extra.toml`.
- [devices/hpc3_enet/README.md](devices/hpc3_enet/README.md): HPC3 Ethernet DMA channels of the Indy: the interrupt, reset and descriptor rules, the receive and transmit channel behaviour, the IRIX recovery path and what is unknown. The register contract is in `devices/hpc3_enet/registers.toml`.
- [devices/seeq_8003/README.md](devices/seeq_8003/README.md): SEEQ 8003 and 80C03 Ethernet controller behind the Indy's HPC3: the register directions and banks, the 80C03 counters and control, the receive and transmit rules, and what is unknown. The register contract is in `devices/seeq_8003/registers.toml`.
- [devices/xframe/README.md](devices/xframe/README.md): Neterion Xframe 10-gigabit Ethernet card on SGI's 10-Gigabit Ethernet adapter: the scheduled-interrupt chain, link state, receive and descriptor layout, byte order, the IRIX driver's watchdog and what is unknown. The register and layout constants are in `devices/xframe/registers.toml`.
- [devices/dp83843/README.md](devices/dp83843/README.md): DP83840A and DP83843 Ethernet transceivers of the Origin 200 and Origin 300 I/O boards: identity, the autonegotiation restart, loopback, strap-dependent bits and what is unknown.
- [devices/ics1890/README.md](devices/ics1890/README.md): ICS1890 Ethernet transceiver of the Octane and Octane2 base I/O board: identifier registers, the MII address and what is unknown. The register contract is in `devices/ics1890/registers.toml`.
- [devices/tigon/README.md](devices/tigon/README.md): Alteon Tigon/PCI Ethernet controller of the SGI IRIS Gigabit Ethernet board: the 32- and 64-bit data-phase rules, the PCI State bit 20 width flag, the board's bus capability and what is unknown. No register contract yet.
- [devices/ioc4/coverage.md](devices/ioc4/coverage.md): IOC4 coverage: what shipped software and public drivers settle.
- [devices/ioc4/serial-dma.md](devices/ioc4/serial-dma.md): IOC4 serial ring DMA: ring pointers, the receive timer, the port shadow bits and what is unknown. The field masks are in `devices/ioc4/registers-extra.toml`.
- [devices/mace/coverage.md](devices/mace/coverage.md): MACE coverage: what software, specification and drivers settle.
- [devices/tiocp/coverage.md](devices/tiocp/coverage.md): TIOCP coverage: what the shipped software and drivers settle.
- [devices/vice/coverage.md](devices/vice/coverage.md): VICE coverage: the O2's video imaging and compression engine.

Routine readings from the kernels and PROMs:

- [evidence/hw-explanations-chips-w1.md](evidence/hw-explanations-chips-w1.md): Hardware-facing routine explanations, CRIME and the IP32 kernel, wave 1.
- [software/kernel/ip27/bridge-routines.md](software/kernel/ip27/bridge-routines.md): Routines of the IP27 kernel that serve the Bridge family.
- [software/kernel/ip27/entropy-readers.md](software/kernel/ip27/entropy-readers.md): Kernel routines that read the Hub real-time counter for entropy (IP27 build).
- [software/kernel/ip27/xconn.md](software/kernel/ip27/xconn.md): The xconn.o pairing driver of the IP27 build.
- [platforms/decode-mapped-uncached-and-region.md](platforms/decode-mapped-uncached-and-region.md): Mapped uncached accesses (where the R10000's uncached attribute comes from, how IRIX builds the pages), what the region-present register does on the Hub and Bedrock, and what the Hub memory configuration word decodes, with the PROM and kernel addresses.
- [platforms/ip27/prom-node-numbering.md](platforms/ip27/prom-node-numbering.md): IP27 PROM 6.156: the order of its writes to the Hub node number, cached-alias size, region-present and region-size fields, and what the other processors do at each write, including the slave loop and launch handshake.
- [software/kernel/ip30/bridge-routines.md](software/kernel/ip30/bridge-routines.md): Bridge-family accessors and attach routines of the IP30 kernel.
- [software/kernel/ip30/heart-routines.md](software/kernel/ip30/heart-routines.md): HEART error, timer and reset routines of the IP30 kernel.
- [software/kernel/ip30/odyssey-routines.md](software/kernel/ip30/odyssey-routines.md): Odyssey graphics routines of the IP30 kernel.
- [software/kernel/ip30/support-routines.md](software/kernel/ip30/support-routines.md): Machine-independent kernel routines of the IP30 build read for completeness.
- [software/kernel/ip30/xbow-routines.md](software/kernel/ip30/xbow-routines.md): Xbow routines of the IP30 kernel.
- [platforms/ip30/flash.md](platforms/ip30/flash.md): IP30 boot flash as the Bridge drives it: the shared SSRAM and flash pins, the FLASH_SELECT strap, the write enable, and what is unknown.
- [platforms/ip35/boot-flash.md](platforms/ip35/boot-flash.md): IP35 boot flash: the LBOOT and RBOOT windows, the two PROM positions, the 16 MB flash as the patent describes it, and what is unknown.
- [devices/at29c040a/README.md](devices/at29c040a/README.md): AT29C040A 512 KiB flash: the byte-load program cycle, polling, block locks and the unloaded-byte question the datasheet leaves open.
- [devices/lh28f800su/README.md](devices/lh28f800su/README.md): Sharp LH28F800SU 1 MiB x16 flash: block geometry, pins, the command set, the identifier words, the extended and block status registers, status upload, and the reset and failure questions the datasheet leaves open. The constants and status fields are in `devices/lh28f800su/registers.toml`.
- [platforms/ip32/prom-rom.md](platforms/ip32/prom-rom.md): O2 system ROM: the CRIME and MACE decode of the 4 MB window, the flash alias counts, the R10000 reset fetch and the photographed AT29C040A parts.
- [evidence/instruction-readings-chips-g1.md](evidence/instruction-readings-chips-g1.md), [g2](evidence/instruction-readings-chips-g2.md) and [g3](evidence/instruction-readings-chips-g3.md): instruction readings from hostfacts, one group, not listed entry by entry.

Open questions, one page each:

- [questions/ip35-board-class-and-flash-record.md](questions/ip35-board-class-and-flash-record.md): IP35 PROM: board class of IP53 and IP59 node boards, flash record.
- [questions/ip35-board-word-and-config-block.md](questions/ip35-board-word-and-config-block.md): IP35 PROM: board-identification word and config block.
- [questions/ip35-io9-pci-wiring.md](questions/ip35-io9-pci-wiring.md): IP35 base I/O board: which PCI devices sit where.
- [questions/ip35-prom-cache-staging.md](questions/ip35-prom-cache-staging.md): IP35 PROM cache staging: do later cached fetches hit staged lines?
- [questions/ip35-prom-cpu-config-table.md](questions/ip35-prom-cpu-config-table.md): IP35 PROM: the processor speed table and what feeds it.
- [questions/ip35-prom-l1-brick-class.md](questions/ip35-prom-l1-brick-class.md): IP35 PROM: use of the brick type and known board names.
- [questions/ip35-prom-memory-bank-config.md](questions/ip35-prom-memory-bank-config.md): IP35 PROM: how the memory bank configuration word is read and sized.
- [questions/ip35-prom-mp-presence-poll.md](questions/ip35-prom-mp-presence-poll.md): IP35 PROM: how processors publish presence and end their waits.
- [questions/ip35-prom-reset-barrier.md](questions/ip35-prom-reset-barrier.md): IP35 PROM: reset barrier, boot-master election and progress registers.
- [questions/ip35-reset-window.md](questions/ip35-reset-window.md): IP35 reset window: how the boot PROM runs at 0x1fc0_0000.
- [questions/tezro-io-topology.md](questions/tezro-io-topology.md): Tezro: widget population, per-head PCI devices and second PROM build.
- [questions/tezro-v12-placement.md](questions/tezro-v12-placement.md): Tezro: where the V12 sits and what differs on one-processor boards.
- [questions/tezro-widget-11.md](questions/tezro-widget-11.md): Tezro: how the PROM discovers the second PIC at widget 0xb.

Published sources and specifications:

- [references/documents/README.md](references/documents/README.md): Published sources held in this repository.
- [references/documents/specs/crime-1.5-specification-rev0.3.registers.md](references/documents/specs/crime-1.5-specification-rev0.3.registers.md): CRIME 1.5 specification rev 0.3: CPU interface register map.
- [references/documents/specs/crossbow-asic-specification-rev12.0.registers.md](references/documents/specs/crossbow-asic-specification-rev12.0.registers.md): Crossbow ASIC Specification, revision 12.0: register map.
- [references/documents/specs/mace-specification.registers.md](references/documents/specs/mace-specification.registers.md): MACE I/O ASIC Specification, chip revision 2.0: register map.
- The spec PDFs in `references/documents/specs/` are listed in [references/documents/specs.md](references/documents/specs.md), not here.

## Layout

    AGENTS.md  LICENSE  README.md
    devices/<unit>/    one directory per chip, board or card. README.md is the page (entries with labels), census/
                       the machine-made tables (hub bedrock heart xbow bridge pic tiocp router scan l1 ioc3 ioc4
                       crime mace gbe vice; bridge/ also holds the XBridge census; router/ is a call-argument census,
                       retools/tools/chips/callargs.py, because the router has no memory window). registers.toml is
                       the register map: written from the census by retools/tools/chips/gen_headers.py for the census
                       units, with registers.xbridge.toml (XBridge as an overlay on Bridge) and the hand-written
                       registers-extra.toml, xio_fc and ice1724 for facts the census cannot reach (PROM stores,
                       specification pages). registers.md is the generated reference page; helpers.h holds C helpers.
    formats/<name>/    software data structures with a definition file: format.toml (l1_requests)
    platforms/<board>/ the machines: topology, address map, boot and PROM (ip27, ip30, ip32, ip34, ip35, bricks).
                       ip27 to ip35 also hold relative symlinks into root/ (boot objects, members, kernel, PROM,
                       ide, symmon, sash)
    software/kernel/   how the IRIX kernels drive the parts, by build
    generated/         generated from the register maps by retools/tools/defs/defs-gen, never hand-edited: c/ headers,
                       rust/ crate, python/, json/, xml/
    questions/         open questions, one page each, with what would settle it
    evidence/          coverage.md, inventory/ (tables), routines/ (routine readings), the instruction readings and
                       the other audits, irix-files.md and reading-brief.md
    references/        documents/ (specs.md, published-sources.md, INDEX.md and the committed specification PDFs)
                       and code/ (m2c spimdisasm linux linux-5.3 linux-2.5.40 linux-2.4.37 linux-ip30 netbsd openbsd
                       gxemul mame arcboot irix-657m-src: public submodules, pinned and shallow, init only what you need)
    tools/             configs/ (one census config per chip), setup-clone.sh (the bootstrap stub), config/
                       (inventory-config.json, inventory-siblings.json, inventory-root.sha256, defs-check.toml and
                       the allow-lists the checks read) and ghidra/ (this workspace's Ghidra processors, import and
                       type scripts)
    retools/           submodule (sgi-retools): the shared tools in retools/tools/, the census tools in
                       retools/tools/chips/, the Ghidra scripts in retools/ghidra/
    root/              the filled IRIX tree and spec text; ignored, never committed

Graphics inputs (libGLcore, X modules, OpenGL sources) and graphics-only tables are not part of this
repository; the graphics workspaces own them.

## Running the tools and reproducing a result

The host needs Podman, git and python3. Everything else runs in a container built from
[retools/tools/Containerfile](retools/tools/Containerfile): MIPS binutils, dwarfdump, pyelftools, capstone, unicorn,
numpy, pycparser and spimdisasm, at pinned versions on a pinned Debian base.

    tools/setup-clone.sh --root /path/to/filled/root   # siblings at their pins, submodules, root/
    retools/tools/re-run python3 retools/tools/inventory.py          # the first run builds the image

`retools/tools/re-run COMMAND` runs `COMMAND` in the image with this repository mounted at `/work`, `root/`
included; with no command it opens a shell. `root/` is your own copy of the IRIX 6.5.30 files listed in
[evidence/irix-files.md](evidence/irix-files.md); they are never committed. Fill it from your install or media, then unpack and
link the archives by hand as evidence/irix-files.md describes; retools no longer ships a script for that.

To reproduce a cited result:

- Generated tables under `evidence/inventory/` come from `retools/tools/re-run python3 retools/tools/inventory.py`.
  `git status --short docs` shows nothing afterwards when your `root/` matches `tools/config/inventory-root.sha256`.
- A claim an entry marks as established by execution is reproduced by the script that
  the entry names; its docstring says what it reproduces and how to run it, always as
  `retools/tools/re-run python3 retools/tools/NAME.py ...` from the repository root.
- The shared tooling (container definitions, wrappers, Ghidra scripts, the inventory, fact sheet and claim checker, and the device extractors) is the `retools/` submodule (sgi-retools). Run its tools by their submodule path from the repository root (`retools/tools/NAME`, device tools under `retools/tools/chips/`); they find this workspace from the current directory. There are no local links into it, so a change to a shared tool is made in retools and the pin here moves with a commit. The optional Ghidra image is built from `retools/tools/Containerfile.ghidra` by
  `retools/tools/re-run --ghidra COMMAND`, and `retools/tools/re-run --ghidra-export OBJECT` writes decompiled C and
  function-similarity output as JSON (see `tools/ghidra/README.md`); nothing else needs it. `retools/tools/README-analysis.md`
  describes the `.mdebug` importer and the kernel table extractors.

## Clone and query

    git clone https://github.com/jamesbraid/chips.git && cd chips
    tools/setup-clone.sh --root /path/to/filled/root
    retools/tools/chips/disasm.sh tools/configs/pic.json             # stage 1, in the container
    python3 retools/tools/chips/scan.py tools/configs/bridge.json --base "$PWD" --out work/bridge

Questions are answered from `devices/<chip>/census/` (the TSV tables), `devices/<chip>/README.md` (entries with
labels) and `grep -r` over `root/spec/*.txt` (text of the specifications, not committed).

Licence: BSD-3-Clause, see [LICENSE](LICENSE). The scripts descend from gr4's
and keep its notice in [retools/tools/LICENSE-gr4](retools/tools/LICENSE-gr4).
