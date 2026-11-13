# SN0 power domains and reset reach

**Status:** draft. The power-domain facts below come from the published owner's and diagnostic guides listed under Sources. The reset-entry facts for the R10000 are taken from the processor manual's reset description and were not re-read in this pass. The register facts for the Hub are on their own pages and are only linked here.

This page covers which parts of an Origin 200 or Origin 2000 sit in which power domain, what each reset reaches, and what the processor sees afterwards. It is the cross-device view. Each register and command has its own page: the Hub pages, the [Router](../../devices/router_origin2000/README.md), the [Crossbow](../../devices/xbow/family.md), the [timekeeper](../../devices/ds1744/README.md) and the [L1 and ELSC census](../../devices/l1/README.md).

Terms: a *module* is one Origin 200 tower or one Origin 2000 midplane chassis. The *controller* is the module system controller (ELSC). A *node* is one Hub with its processors and memory.

Grades: **established** is stated by a cited manual. **inferred** follows from established facts without being stated. **unknown** is not settled by anything held, and each unknown says what would settle it.

## Sources

- Origin200 and Origin200 GIGAchannel Owner's Guide, 007-3708-002, printed pages 56, 96 to 98 and 104 to 107 (cited below as O200 guide).
- Origin2000 Rackmount Owner's Guide, 007-3456-003, printed pages 82, 83 and 112 to 116 (cited as rack guide).
- Origin2000 Deskside Owner's Guide, 007-3453-002, printed pages 64 to 68 (cited as deskside guide).
- Origin2000 and Onyx2 Diagnostic Roadmap, 108-0164-002, Appendix A, PDF pages 45 and 46, and Appendix F.1.3, printed page F-5 (cited as Roadmap).
- MIPS R10000 Microprocessor User's Manual, version 2.0, 007-2490-001, printed pages 337 to 339 (cited as R10000 manual). **Not re-read in this pass.** The Library search needed to re-read these pages could not reach its backends, so these entries are only as good as the earlier reading.

## Power domains

| Domain | Fed by | Contains |
|---|---|---|
| Standby | The module supply's 5 V auxiliary output. It is present whenever the Origin 200 master switch or the Origin 2000 breaker is on. | The controller and its serial operator port. |
| Module | The supply's main outputs, switched by the controller. | Everything else in the module. |
| Battery | A battery inside the part. | The base I/O timekeeper's clock and its SRAM (see [ds1744](../../devices/ds1744/README.md)). |

- The O200 guide says that with the master switch on, the supply sends 5 VDC to the controller at all times, and the controller stays active until the master switch is turned off. **established** (O200 guide, pages 97 and 98).
- The front switch makes the controller turn on power to the drive bays, the PCI backplane, the main board and the CPU daughter card. **established** (O200 guide, pages 97 and 98).
- On the Origin 2000 the supply starts 5V_Aux to the midplane, the controller initialises and shows its version, and only then does the keyswitch or the rack controller turn the module on. **established** (Roadmap, PDF page 45).
- The rack guide warns that the keyswitch's Standby position does not turn power completely off to the module. **established** (rack guide, page 83).

### Parts in the module domain

| Part | Origin 200 | Origin 2000 | Grade |
|---|---|---|---|
| Processors, Hub and memory | Yes | Yes, on each node board | Established for the Origin 200 (O200 guide, page 97). The deskside guide lists a per-node power-OK message (page 68). For rack modules the per-node messages are not documented. |
| Router boards | Not fitted | Yes | Inferred. The deskside guide reports a power-OK failure per Router board (page 68). |
| Crossbow, XIO boards and base I/O | Bridge, IOC3, SCSI and PCI on the main board | Yes, on the midplane and in XIO slots | Established for the Origin 200 (O200 guide, page 97). Inferred for the Origin 2000 from the single switched supply. |
| Disk bays | Yes | Yes | Established for the Origin 200. Inferred for the Origin 2000. |

- The Origin 2000 power-OK monitors are per board: `POK N 0` to `POK N 3` for the processors and `POK RT 0` and `POK RT 1` for Routers. They are documented in the deskside guide (page 68). The rack guide's table has only `POK FAIL` (page 116). **established** for the deskside messages. They are monitors, not separately switched domains: no power command switches one board alone. **inferred**.
- Rack modules: the rack guide says that if you power off one module, the other modules in the configuration can still operate fully (page 82). **established** for power. The same procedure first shuts the operating system down with `shutdown -y g0`, so the guide describes a module that is its own system, not one module of a running single-system image. **inferred**.

### GIGAchannel expansion cabinet

- The cabinet has its own master switch and controller. Its switched domain (Crossbow, Bridge, XIO and PCI slots, and the blower) turns on only when the attached module turns on, and the module's front power switch turns it off too. A blower failure shuts down the cabinet and the CPU modules. **established** (007-3708-002; the page number was not re-checked).
- For power sequencing, the cabinet's switched domain belongs to the attached module's domain. How the module signals the cabinet is **inferred** to travel on the XIO cables.

### Standby and Hub warnings

- The Origin 2000 controller sends an early warning to all node boards for AC failure, over-temperature, or the keyswitch moving to Standby. **established** that the manual describes it (rack guide, page 114). Whether a separate hardware interrupt wire exists is **unknown**. A node board schematic or the Hub specification would settle it.

## Reset kinds and their reach

The table puts together facts from the Hub and CPU pages in chips. Read the linked pages for the registers.

| Kind | Initiator | Reaches | Processor entry | Preserved | Grade |
|---|---|---|---|---|---|
| AC cycle | Master switch or breaker | The whole module, controller included | Cold | Management NVRAM and timekeeper | Established (O200 guide, pages 98, 106, 107) |
| Module reset | Controller `rst` command, or the front reset button | Every node board in the module | Unknown: cold or soft | Controller state; memory inferred | Reach established for nodes (rack guide, page 112; Roadmap command table). The processor entry is unknown. |
| Module NMI | Controller `nmi` command, the front NMI button, or the watchdog's second stage | Every processor in the module | NMI | Memory, Hub state and controller state, except the processor registers listed below | Established for reach (rack guide, page 112) |
| Hub port reset, bit 0 | A write to the Hub's port reset register | This Hub's node | Cold (inferred) | Memory | See [hub-network-interface](../../devices/hub_ni/README.md) for the register |
| Hub port reset, bit 7 with bit 0 | The same write, as the IRIX and Linux reboot paths make it | Every node reachable without crossing a fence | Cold (inferred) | As bit 0 on each node | Inferred |
| Hub port reset, bit 1 | The same register | One CrayLink between this Hub and its peer | None | Everything programmed | Inferred |
| Hub I/O warm reset | Bit 8 of the Hub I/O link control register | The far end of the XIO link: a Crossbow's core or a Bridge | None | The Hub itself | Established for the Crossbow's response; inferred for the bit (see [hub-io-interface](../../devices/hub/io-interface.md)) |
| Hub soft reset | The Hub's soft reset register | Both processors on the node | Soft (inferred from the register name) | Unknown | Established that it resets both processors (see [hub-processor-interface](../../devices/hub_pi/README.md)) |
| Hub per-processor NMI | The Hub's processor NMI registers | One processor | NMI | All | Established for the trigger (see [hub-processor-interface](../../devices/hub_pi/README.md)) |

### Processor entry kinds (R10000 manual, not re-read)

The R10000 has three entries, selected by the Status register:

- **Cold reset.** The reset input is asserted with the system grant. Status `SR` reads 0. Mode bits reload from the system interface. The PROM takes its cold-start path.
- **Soft reset.** The reset input is asserted without the grant. `SR` is 1 and `NMI` is 0. Registers and caches survive, except the listed Status fields, `ErrorEPC` and the program counter.
- **NMI.** The NMI input is asserted. `SR` and `NMI` are both 1. The processor takes it at an instruction boundary and keeps its state for diagnosis. It uses the same vector as the other entries.

The R5000 family has the same three entries and the same vector. Its details are on [r5000](../../devices/r5000/README.md).

### Module reset

- **Timing.** The controller answers `rst`, waits about 1 s, then pulses reset for 100 ms. A second `rst` during the wait restarts the wait. **Unknown** for this page: the controller command set comes from the module controller, not from a published manual held here, so the timing is not settled by anything cited.
- **Reach.** Every node in the module. The rack guide says "all node cards in this module" and the Roadmap command table has no command that selects one node. **established** for nodes. On the Origin 2000 the front reset button resets the whole system and needs the key in Diagnostic position (rack guide, page 112).
- **Routers, Crossbows and XIO boards.** Whether the module reset line reaches them is **unknown**. A midplane schematic or a register read before and after reset would settle it. Software does not depend on it: the processor's reset path sends its own warm reset down the XIO link.
- **Processor entry.** Whether the reset line gives a cold or a soft entry is **unknown**. The O200 guide says the reset button reboots and skips the automatic power-on diagnostic tests (page 97). That fits either entry. A trace of processor Status at the reset vector after a module reset would settle it.
- **Memory.** Inferred preserved, because no power is removed. Whether the reset line interrupts refresh is **unknown**.

### NMI

- **Sources.** The controller's NMI command, the front NMI button, and the watchdog's second stage. On the Origin 2000 the button needs the key in Diagnostic position (rack guide, page 112). The Origin 200 has no keyswitch (O200 guide, pages 96 and 97).
- **Reach.** All node boards in the module (rack guide, page 112). **established**.
- **Processor entry.** NMI: `SR` and `NMI` set, state preserved (R10000 manual). That the module NMI line drives each processor directly, not through a Hub register, is **inferred**.

### Hub network-interface port reset

Register layout and bit meanings are on [hub-network-interface](../../devices/hub_ni/README.md). The domain view:

- Bit 0 resets this Hub's node. The register table says it resets the entire Hub. **established** for the Hub; the processors' entry is **inferred**.
- Bit 7 carries the reset over the link. A Hub that receives it resets its node unless its protection bit 0 is clear. A Router forwards it according to its permits and port reset masks. Bits 7 and 0 together reach every node the fences admit. **inferred**. Bit 7 alone is **unknown**.
- Bit 1 resets one link and nothing else. **inferred**.
- Port reset bits act on Hubs and Routers. Nothing in the controller's state changes. **inferred**: the controller is on standby power and no Hub register drives it except through its serial and I2C commands.

## Power-on

- The controller starts when AC is applied. An Origin 200 master powers the module up if its automatic power-on setting is on (O200 guide, page 97). A slave Origin 200 controller waits for the master.
- The controller issues the reset at power-on (rack guide, page 113). Every processor then starts at the reset vector with `SR` clear, the cold entry. **established**.
- The DC OK rails cover the node rails (rack guide, page 113). **established**.

## Shutdown and the end state

- With the module off, the standby domain stays up. An operator can power the module on again with the front switch, the keyswitch or the rack controller. **established** (O200 guide, page 98; Roadmap PDF page 45).
- What software does before a power-off, and how the operating systems in use drive it, is not covered here. No published manual cited on this page settles it.

## Battery domain

The base I/O timekeeper's clock and its SRAM are on a battery and keep running with the module off. The reset values of the clock and SRAM are unknown. See [ds1744](../../devices/ds1744/README.md) and [ds1742](../../devices/ds1742/README.md).

## Unknowns and what would settle them

| Unknown | What would settle it |
|---|---|
| Whether `rst` and the reset button give the processors a cold or a soft entry | A trace of processor Status at the reset vector after a module reset, on hardware |
| Whether the module reset line reaches Routers, Crossbows and XIO boards | Midplane schematics, or register reads before and after a module reset |
| Whether a separate power-fail interrupt wire reaches the Hubs, besides the controller's message | Node board schematics or the Hub specification |
| What the 5 V auxiliary rail feeds on the Origin 2000 midplane besides the controller | Midplane documentation |
| Whether the controller answers the one-wire identity command with the module off, and which rail pulls the one-wire line up | A controller exchange with the module off |
| Whether a peer Hub or Router port reads reset-failed or came-up-then-failed when the other end loses power | A two-module capture across a module power-off |
| How module numbers relate to master and slave on a two-module Origin 200 | A two-tower power-off on hardware |
| The timing of the module reset pulse and what the controller does while it waits | A capture of the controller's serial output around a reset, on hardware |

The project's own SGI systems, an Origin 350 and an Octane2, have no Hub, Router or Origin 200 or Origin 2000 controller, so none of these can be settled on them.
