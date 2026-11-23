# Indigo prior art: what exists before a full reverse-engineering pass

A survey for the SGI Indigo in both generations, IP12 (R3000) and IP20 (R4000), with Entry (LG1), XS/XZ/Elan/Extreme
(GR2, also called Express) graphics and the board chips: MC, HPC1, INT2, the SCSI, Ethernet, serial, clock and audio
parts. It lists what other people already did, what we hold, and what is still open, then proposes an order of work.
It sits beside [indigo-challenge-era-holdings.md](indigo-challenge-era-holdings.md), which lists documents and PROM
images for the whole early 1990s family; this page adds the code, schematics, specifications and graphics material that page
missed, and corrects some "not held" lines in earlier pages (see "Corrections" below).

Nothing here was verified on hardware. Grades are the surveyor's judgement of a source's usefulness, not a review.
Restricted vendor-source hits turned up in several Library searches (the DS1286 clock headers, the system generation
files). They were not opened and are not listed.

Library ids: `origami-docs:` is the document cache, `techpubs:` the SGI publications mirror. A bare `refs/` name is a
public tree held in the project checkout.

## Short answers

- **Is there a gr2 workspace of ours?** No. Neither the Forgejo `jamesb` and `infra` organisations nor the GitHub
  account `jamesbraid` has a `gr2` repository. `gr2` is techomancer's public repository
  (<https://github.com/techomancer/gr2>). The rules name it as the Express graphics workspace and `README.md` credits it,
  but nothing of it has been mirrored or forked. `gr4` is mirrored (a fork); `gr2` is not.
- **Does techomancer have Indigo, GR2, Elan, LG1 or Newport work?** Yes for GR2 and Newport, no for LG1 and the Indigo
  boards. `techomancer/gr2` is a register-header reverse-engineering workspace for GR2 (HQ2, GE7, RE3, VM2, VC1, XMAP5).
  `techomancer/iris` emulates Indy and Indigo2 with a Newport model and a GR2 model (see below). It models neither IP12
  nor IP20, and states that the older HPC1 region is not emulated.
- **What do chips and the other RE repos cover?** Almost nothing of this hardware. Details in section 1.

## 1. Existing workspaces

### techomancer/gr2

Public, one commit (`91af78f`, 2026-10-28), created for the GR2 family on Indigo (IP20), Indy and Indigo2.

| Item | What it holds | Grade |
|---|---|---|
| `GR2.h` (875 lines) | Block diagram, board-variant table (XS, XS24, XZ, Elan, Extreme by chip counts), GIO slot addresses (`0x1f000000`, `0x1f400000`, `0x1f600000`), region offsets of the shared RAM and command FIFO | medium |
| `HQ2.h` (2300 lines) | Command engine registers and the FIFO token set | medium |
| `GE7.h`, `RE3.h`, `VC1.h`, `XMAP5.h`, `VM2.h` (121 to 648 lines) | Geometry engine, raster engine, video controller, colour mapper, framebuffer | medium; VM2 is thin |
| `ucode/` | `ge7.bin`, `hq2.bin` and two video-timing binaries, committed | see section 5 |
| `docs/` | Bt457, Bt475/477 datasheets, schematics of two later boards (called GR-4 and VB-3 there), an Elan technical report page, a wiki page it labels "NOT HUMAN REVIEWED. MACHINE GENERATED" | mixed |
| `IRIX_FILES.md` | The IRIX 6.5.0 files to put in a local `root/`: kernel objects, GL and X driver libraries with debug information | n/a |

Trust notes. The headers were written by an AI-assisted pass over shipped objects, PROM-level standalone code and
diagnostics, public driver sources and the two schematics, per the header comment. The repository's own workflow reads
vendor source, so a reader of `gr2` should treat it as exposure for the Express family (the project rule for graphics
workspaces already says so). The header comments carry few explicit uncertainty marks (about 15 across 5184 lines), so
every field needs a second source before it is called established. There is no LG1 header; the notes say Newport and LG1
are "similar" and stop there. Nothing in it covers the MC, HPC1 or INT2.

### chips and the other repositories

- **chips**: no `platforms/ip12`, `ip20` or `ip17` page and no `devices` page for MC, HPC1, INT2, LG1, GR2 or Newport.
  `platforms/ip22/` holds only two PROM notes (`prom-console-input.md`, `prom-environment.md`). The nearest device
  pages are `devices/hollywood-dsp` (the Indigo DSP audio block, inferred from shipped headers, no driver object),
  `devices/seeq_8003` and `devices/hpc3_enet` (both partial, from public drivers, for the Indy and Indigo2 Ethernet path),
  and `devices/mace` and `devices/crime` (the O2, unrelated). `COVERAGE.md` rows 76 to 96 list MC, INT2/INT3/IOC2, HPC1/HPC3,
  HAL2, VINO, GIO and Newport as missing or partial, and Express as "owned by the Express repository".
- **kudzu**: the driver side of the DSP block is described in its `docs/hollywood-dsp-driver.md` (cited by the chips page;
  not read here).
- **kona, odsy, crime, gr4, sysco, voyager, psitech, cobalt**: other families; none cover Indigo.
- **sgi-retools** supplies the tooling (`defs`, `reading_round.py`, Ghidra processors) and has an `hdsp` tool directory.

## 2. Emulator prior art

### MAME (mamedev/mame), `src/mame/sgi`

The most useful emulator source, because the Indigo is a first-class target. License BSD-3-Clause. Files, with size,
completeness and comments (the headers carry TODO lists rather than register documentation; register names are in the
code):

| File | Lines | What it models | Completeness and comments |
|---|---|---|---|
| `ip12.cpp` | 428 | IP12 board: R3000, LG1 at `0x1f3f0000`, HPC1 at `0x1fb80000`, INT2, Z85C30 serial, WD33C93A SCSI, Seeq 8003, DP8572A clock, DSP56001 plus 32K-word DSP RAM, board revision register, PROM sets for four PROMs | boots to PROM and diagnostics; DSP and VME TODO; install notes in the header are practical |
| `ip20.cpp` | 298 | IP20 board: R4000/R4400, MC, 93C56 EEPROM, same HPC1, INT2, serial, SCSI, Ethernet, clock; two PROM revisions (4.0.5G Rev B and 4.0.5D Rev A) | flagged `MACHINE_NO_SOUND`, `IMPERFECT_GRAPHICS` |
| `hpc1.cpp` | 555 | HPC1 with SCSI and Ethernet DMA channels | TODO: HPC1.5, PBUS and DSP, interrupt delay |
| `int2.cpp` | 214 | INT2 interrupt multiplexer with the source table in comments | TODO: bus error, FPU interrupt; the table is the best written account found |
| `mc.cpp` | 861 | MC (shared with Indy and Indigo2); `sys_id` set to a revision-C part | minimal comments; DMA, EEPROM, interrupts modelled; IP22 era |
| `light.cpp` | 284 | LG1 (Entry graphics) | "passes power-on diagnostics, usable for firmware output, fails badly for IRIX output"; REX device-ification TODO |
| `pic1.cpp`, `ctl1.cpp` | 237, 366 | Processor Interface Controller and CPU control gate array of the older Personal IRIS 4D/20 and 4D/25 class | the IP12 model maps PIC1 at `0x1fa00000`; unverified against hardware |
| `sgi_gr1.cpp`, `sgi_ge5.cpp`, `sgi_re2.cpp`, `sgi_xmap2.cpp`, `vc1.cpp`, `gm1.cpp` | 337, 776, 542, 192, 206, 138 | GR1 and GT-class pieces; GE5/HQ1 microcode decoded; `vc1.cpp` is a stub "only enough to pass power-on diagnostics" | not GR2 |
| `kbd.cpp` | 397 | The serial keyboard and mouse of the 4D series, Indigo and Onyx | documented well: electrical protocol, DIP switch byte |
| `hal2.cpp`, `hpc3.cpp`, `ioc2.cpp`, `vino.cpp`, `indy_indigo2.cpp`, `newport.cpp` (`src/devices/bus/gio64`, 4500 lines) | various | Indy and Indigo2 side | not Indigo; useful as a sibling-chip cross check only |
| `src/devices/machine/edlc.cpp`, `dp8573a.cpp`, `wd33c9x.cpp`, `z80scc.cpp` | n/a | Generic Seeq 8003, DP857x clock, WD33C93, Z85C30 | `edlc.cpp` has a descriptive header (frame-sized FIFOs rather than 16 bytes) |

There is no GR2 (Express, Elan, XS) model in MAME and no HPC-attached audio model. The `gr2` repository's notes list MAME as
a source, but the files above are what exists. Trust: medium. It is an independent model written from running software and
from the PROM; it confirms or contradicts, it does not establish a register fact. The IP12 and IP20 PROM sets also show that
MAME holds a 4.0.5G Rev B IP20 PROM that [prom-images.md](prom-images.md) does not list.

### The sibling QEMU branch

The maintained QEMU branch of the sibling emulator project (checked in a local checkout at `723f3c0df35` and in the manual
pages under `docs/system/mips/sgi/`) has no IP12, IP20, IP22 or IP24 machine and no device for MC, HPC1, HPC3, INT2,
Newport or GR2. Its hardware pages cover the O2, Octane, Origin, Fuel and Tezro families only. The only Indigo-family
mentions are incidental (a CD-ROM page that cites an Indy drive). A second GPL QEMU fork held under `refs/qemu-sgi` does
carry `hw/mips/sgi_indy.c` with an `indigo` machine (IP20, "MC/HPC1/INT2"), `sgi_mc.c`, `sgi_hpc3.c` and a stub `sgi_hpc1.c` of
88 lines, and `sgi_newport.c`. Its HPC1 is a stub, so it adds nothing for the Indigo beyond a machine skeleton. Trust: low
to medium; it is a young community fork and I did not boot it.

### techomancer/iris

Rust emulator, BSD-3, very active. Machines: Indy (IP24), Indigo2 (IP22, IP26/IP28 mentioned for IMPACT), O2, Octane,
Origin and later. Modelled for this family: MC (`src/dev/mc.rs`, 1628 lines), HPC3 (3064 lines), INT2 and the IOC family
(`ioc.rs`, 1690 lines), HAL2, Seeq 8003, WD33C93A, Z85C30, Newport (`src/dev/ng1/`) and a GR2 model (`src/dev/gr2/`: HQ2, GE7
stub, RE3 with a JIT, VC1, XMAP5, Bt457, about 2680 lines of GL command handling). It does not model IP12 or IP20, no LG1
and no HPC1; `src/ip22_bus.rs` says the HPC1 region is left unmodelled. Its GR2 model is the only running GR2 emulator, and its
`docs/dev/wd33c93a.md` (1.9k lines) is a long WD33C93A behaviour note. Trust: medium for behaviour, and as the rules say, emulator
behaviour is not hardware evidence.

### GXemul and others

`refs/gxemul`: `dev_sgi_ip20.c` (113 lines) is a stub that returns random bytes for one register, with a TODO; `dev_sgi_ip22.c` (437
lines) is an Indy and Indigo2 skeleton. It is useful only for the fake-ARCS code. Nothing found for IP12. No other emulator with
Indigo support was found (SIMH-class and 86Box trees held under `refs/` are unrelated).

## 3. Public drivers

| Source | Files | Establishes | Grade |
|---|---|---|---|
| NetBSD sgimips (`refs/netbsd-src/sys/arch/sgimips`) | `sgimips/machdep.c` (IP12 and IP20 cases), `dev/int.c` plus `int1reg.h`, `int2reg.h` (INT2 base addresses for IP12 and IP20, timers, mask and status), `dev/imc.c` plus `imcreg.h` (MC for IP20 and IP22, IP20 cannot pipeline), `hpc/hpcreg.h` (HPC1 and HPC1.5 DMA descriptors, SCSI channel offsets, revision bits), `hpc/hpc.c`, `hpc/if_sq.c`, `hpc/sqvar.h` and `seeq8003reg.h` (Ethernet), `hpc/wdsc.c` (SCSI), `dev/dpclock.c` with `dp8573areg.h` (clock), `dev/zs.c`, `dev/scn.c`, `dev/ctl.c`, `gio/light.c` plus `lightreg.h` (LG1 console), `gio/grtwo.c` plus `grtworeg.h` (GR2 console, 798 and 207 lines), `hpc/haud.c` plus `haudreg.h` (Indigo DSP audio block: DMA, handshakes, interrupt status and mask, miscellaneous control, burst control; dated June 2026) | The only public driver set that treats IP12 and IP20 as targets. LG1 and GR2 are wscons console drivers, so they establish enough to put text on screen (mode, colour map, block copy), not the pipeline. `haudreg.h` is a full register list for the DSP block | high for what each file does, medium for coverage |
| OpenBSD sgi | `refs/openbsd-sgi/sys/arch/sgi/{gio,hpc}`: `light.c`, `grtwo.c`, `hpc.c`, `if_sq.c`, `wdsc.c`, `dpclock.c`, `zs.c` | Mostly the same drivers re-skinned for IP22 and later; gives a second reader of the same registers. OpenBSD does not run on IP12 or IP20 | medium |
| Linux MIPS (snapshot from 2018) | `arch/mips/sgi-ip22` (`ip22-mc.c`, `ip22-int.c`, `ip22-hpc.c`, `ip22-gio.c`, `ip22-time.c`), `arch/mips/include/asm/sgi/{mc,hpc3,ioc,gio,ip22}.h`, `drivers/net/ethernet/seeq/sgiseeq.c`, `sound/mips/hal2.c`, `drivers/scsi/{sgiwd93,wd33c93}.c`, `drivers/tty/serial/ip22zilog.c`, `drivers/video/console/newport_con.c` | IP22 only. Linux never supported IP12 or IP20, and has no LG1 or GR2 driver. Good for MC and Seeq 8003 behaviour shared with the Indy generation | high for IP22, none for IP12 |

Nothing public documents HPC1 beyond NetBSD's descriptor and register constants, MAME's model and the shipped IRIX headers.

## 4. Specifications and documents

Held and open (read directly, nothing restricted):

| Document | Id | Covers | Notes |
|---|---|---|---|
| MC chip specification | `origami-docs:library/cache/graphics/indy/erikarn-sgi_indy_mc.pdf` | 61 pages; the memory controller between the R4000, main memory, GIO64 and EISA | The Indy and Indigo2 generation. Whether the IP20 revision is the same part is not settled; MAME and NetBSD both use one MC for IP20 and IP22 |
| HPC3 chip specification | `origami-docs:library/cache/io-chip/sgi-hpc3-chip-specification-bukosek.pdf` (a second copy `...-sigxcpu.pdf`; a third `sgi-hpc3-iris.pdf` is damaged) | 65 pages; successor to HPC1 | The only HPC family specification held; HPC1 differs (NetBSD notes the swapped descriptor fields) |
| IOC2 specification | `origami-docs:library/cache/graphics/indy/erikarn-sgi_indy_ioc.pdf` | Indy I/O and interrupt controller | Not the Indigo INT2 |
| GIO64 bus | `origami-docs:library/cache/graphics/indy/erikarn-sgi_indy_gio64.pdf` | The 64-bit GIO bus | The Indigo uses GIO32; the 64-bit spec is a superset reference |
| Newport family | `...erikarn-sgi_indy_rex3.pdf`, `_vc2.pdf`, `_xmap9.pdf`, `_rb2.pdf`, `_ro1.pdf`, `erikarn-bt445_ramdac.pdf` | REX3, VC2, XMAP9, RB2, RO1, Bt445 for Indy graphics | Not the Indigo graphics, but they are the nearest siblings of LG1 |
| Seeq 8003 | `origami-docs:library/cache/io-chip/seeq-dq8003-datasheet-iris.pdf`, `seeq-1990-data-book.pdf` | EDLC register set and frame format | The chips page says the 80C03 data sheet is not held; the 8003 is |
| Indigo board schematic (HP-1) | `origami-docs:library/cache/bitsavers/sgi/indigo/HP-1_Schematic.pdf` | 36 pages, text-searchable (about 64 kB of extracted text); the R3000 Indigo CPU board | The best primary hardware source for IP12: chip list, GIO wiring, INT2 connections. Not yet read for any page |
| Other schematics | `.../bitsavers/sgi/iris4d/SGI_IP-6_Schematic.pdf`, `SGI_IP-10_Schematic.pdf`, `VIP-10_Schematic.pdf`, `GR-4_Schematic.pdf`, `VB-3_Schematic.pdf`, `VME-Eclipse_CPU_VIP10_Specification.pdf` | Earlier 4D boards and the GR2-family board generation that also appears in the Indy Elan | Context for PIC1, CTL1 and GR2 boards |
| V30/35 integrator's guide, TG-V integrator's guide | `.../bitsavers/sgi/iris4d/007-5015-020_V30_35_System_Integrators_Guide_1992.pdf`, `007-5016-010_TG-V_Graphics_System_Integrators_Guide_1992.pdf` | The VME IP12 variants (4D/30, 4D/35) | |
| IRIS Indigo Workstation Owner's Guide, 007-9065-050 | `techpubs:library/manuals/9000/007-9065-050/pdf/007-9065-050.pdf` | 228 pages; user-level, ports, options | Not a technical reference |
| Audio/Serial Option User's Guide, 007-2645-001 and installation sheet 108-0134-001 | `techpubs:library/manuals/2000/007-2645-001/pdf/007-2645-001.pdf` | Option board, not the on-board audio | |
| Hardware Developer Handbook 2.0 | `origami-docs:library/cache/sgi-hw/hardware-developer-handbook-2.0.pdf` | Graphics-family taxonomy | Late (1997); identity, not registers |
| Elan Graphics technical report | `techomancer/gr2` `docs/` page and Wikipedia's "Elan Graphics" | Architecture overview | Overview only |
| Indigo photographs and brochure | `origami-docs:library/cache/photos/bukosek-indigo/`, `.../sgi-hw/archive-org-sgi-indigo-brochure-1992.pdf`, `.../sgi-hw/bukosek-sgi-indigo.html` | Boards, chip markings, product configurations | Chip markings are the way to confirm parts |
| MIPS R3000, R4000 user's manuals | see the holdings page | CPU | Held |

Not held, no record found in the Library: any HPC1 specification, any INT2 specification, an MC revision list covering IP20, an
LG1 or LG2 document, GR2 chip specifications (HQ2, GE7, RE3, VC1, XMAP5), a Z85C30 or WD33C93 datasheet, a DP8572A/8573
datasheet, an 8254 datasheet and any Indigo audio-part datasheet. Searches for the Z85C30 and the Brooktree RAMDACs returned
nothing; the Bt457, Bt475 and Bt477 sheets exist only inside the gr2 repository. I did not run per-chip Library searches for every
part, so "no record" for the minor parts means "nothing came up in two or three queries". Searches for DS1286 returned only
restricted vendor source. Public sources worth fetching, none retrieved by this survey (the one fetch attempted, of the
bitsavers SGI directory, was refused with HTTP 403 from the fetch tool, so its index was read from the local cache copy):

- bitsavers, `pdf/sgi`, for further board schematics and parts lists; the Library cache already mirrors a subset.
- The Linux-MIPS wiki SGI pages (Indigo and Indy status pages), and the NetBSD port documentation for sgimips.
- Zilog Z85C30, Western Digital WD33C93A, National DP8572A and Motorola DSP56001 datasheets from archive collections.

## 5. PROM, firmware and microcode held

From `assets/prom-catalog.toml` (sha256 and sizes also in [prom-images.md](prom-images.md)):

| Board | Part | Banner | Size |
|---|---|---|---|
| IP12 | 070-8086-002 | 4.0.1 Rev C, GR1/GR2/LG1, 14 Feb 1992 (labelled 4D/35) | 512 KiB |
| IP12 | 070-8088-xxx | 4.0.1 Rev C, LG1/GR2, 9 Jul 1992 | 256 KiB |
| IP12 | 070-8088-002 | 4.0.1 Rev D, LG1/GR2, 24 Mar 1992 | 256 KiB |
| IP20 | 070-8116-004 | 4.0.5D Rev A, 19 Aug 1992 | 512 KiB |

Missing: the IP20 4.0.5G Rev B PROM (MAME lists it as dumped over serial from the boot monitor), the 4D/30 PROM, and earlier IP12
revisions. No boot captures are held for any of these.

Shipped IRIX 6.5 base media under `refs/irix-media/6.5-base` (shipped binaries and headers, citable as software
expectation) is richer than the holdings page assumed:

- `usr/gfx/ucode/ge7.bin` (611432 bytes) and `hq2.bin` (58682 bytes), the GR2 geometry and command microcode. `usr/gfx/ucode/GR2/vof/`
  has the video output format files (`30hz.u` to `72hz.u`, `ccir50.u`, `ccir60.u`, `adjntsc.bin`, `adjpal.bin`).
- `usr/gfx/arch/IP12GR2`, `IP12GR232` and `IP20LG1MC` with GL libraries for GR2 on IP12 and LG1 on IP20, plus `IP22GR2NG1`.
- `usr/cpu/sysgen/IP20boot/`: 216 kernel objects and archives including `gr2.a`, `lg1.a`, `kdsp.a`, `sduart.a`, `wd93.o`, `scsi.o`,
  `hpcplp.o`, `gfx.o` and `rrm.o`. This contradicts the holdings page statement that no IP20 object directory is held. There is no
  `IP12boot`: IRIX 6.5 dropped IP12, so IP12 kernel objects would need an IRIX 5.3 or earlier medium.
- `sbin/stand/ide.IP20`, `symmon.IP20`, and `var/sysgen/master.d/lg1`.
- Shipped headers `usr/include/sys/IP20.h`, `IP20addrs.h`, `IP20nvram.h`, `hpc1.h`, `mc.h`, `sbd.h`.

IRIX 5.3 network-install images exist for the Indy only in the harness catalogue; none for IP12 or IP20.

## 6. Grades by source

| Source | Use it for | Grade |
|---|---|---|
| Held MC, HPC3, GIO64, Seeq specifications, Newport sibling specs | Register layouts of parts shared with the Indy generation | high, with the caveat that the Indigo revisions differ |
| HP-1 schematic | Which chips exist, how they connect | high for connectivity, no register content |
| Shipped IP20 kernel objects and headers, PROMs | Software expectation for MC, HPC1, INT2, LG1, GR2 on IP20; PROM reset behaviour | high, if read to the project's evidence order |
| NetBSD sgimips | HPC1, INT2, IMC, LG1, GR2 console, haud registers | high for what it uses, partial coverage |
| MAME ip12, ip20, hpc1, int2, light | Independent model; address maps, interrupt wiring, the DSP RAM size | medium; a cross check, not evidence |
| techomancer/gr2 | GR2 register names and the board-variant table | medium; machine-generated and reads vendor source |
| iris GR2 and Newport models | GR2 behaviour that actually draws; Newport behaviour for LG1 comparison | medium; emulator behaviour |
| `refs/qemu-sgi` HPC1 and GXemul stubs | nothing | low |

## 7. Recommended plan

Principles: IP20 before IP12 (more material, and the shipped kernel objects and PROMs are held for it); public prior art
settles what it settles; only original reading fills the rest. One page per unit under `devices/`, a platform page per board
under `platforms/`, labels per [AGENTS.md](../AGENTS.md).

1. **Platform pages first** (`platforms/ip20`, then `platforms/ip12`): physical address map, interrupt tree, the boot path
   from the PROM, chip list. Sources: the HP-1 schematic for IP12; MAME's memory maps and NetBSD's `int.c` and `machdep.c`
   as cross checks; the IP20 `IP20addrs.h` and `sbd.h` shipped headers; the PROM images. Public prior art covers the
   map; the interrupt and reset facts need a PROM reading.
2. **INT2** (`devices/int2`): small, central, and needs no spec. NetBSD `int2reg.h` and `int.c` and MAME `int2.cpp` give the
   register map and source table; confirm with the IP20 interrupt code in the held `ide.IP20` and kernel objects. Labels
   likely established for most registers. A page of this quality may already settle it, so RE can stop at confirmation.
3. **MC for IP20** (`devices/mc`): start from the held MC specification and diff it against the IP20 MAME and NetBSD uses and
   the shipped `mc.h`; the work is the revision delta (pipelining, the bank layout), not a new reading. Reuses the Indy page
   when that is written.
4. **HPC1** (`devices/hpc1`): the biggest gap. No specification. Sources: NetBSD `hpcreg.h` and `hpc.c`, MAME `hpc1.cpp`, shipped
   `hpc1.h`, and kernel objects `hpcplp.o`, `wd93.o`, `scsi.o` and the Ethernet and serial objects. Cover the SCSI and Ethernet
   DMA channels, PBUS decode, and the DSP window. Expect to need Ghidra readings on the IP20 objects to establish the descriptor
   and interrupt rules. Reuse the HPC3 specification for channel structure, labelled as a sibling.
5. **Board peripherals**: Seeq 8003 (extend `devices/seeq_8003`; the datasheet is held), WD33C93A, Z85C30 serial, DP8572A clock
   (pages only for what the Indigo wiring changes; public datasheets are not held and must be fetched), the 93C56 EEPROM.
   Mostly public prior art makes RE unnecessary; the work is the board glue through HPC1.
6. **Audio DSP block**: extend `devices/hollywood-dsp` using NetBSD `haudreg.h` as a second public source, which upgrades
   several "inferred" lines. The DSP firmware interface stays in kudzu.
7. **LG1 (Entry graphics)**: no spec held and no public model beyond MAME's `light.cpp` (which fails for IRIX output) and
   NetBSD's console driver. This needs an original reading: `lg1.a` and the `IP20LG1MC` GL libraries, with the PROM's graphics
   init. Do it after the HPC1 work. Its REX-style command interface likely resembles the Newport REX3 spec held for the Indy.
8. **GR2 (XS, XZ, Elan, Extreme)**: the largest job. Start by mirroring techomancer's `gr2` as a reference tree (not a
   fork we edit), then own the page set: board-variant table, HQ2 FIFO token interface, GE7 microcode loading, RE3, VC1, XMAP5. Use the
   held `gr2.a`, `libGLcore` and the microcode binaries, with `ucode` checked against `gr2`'s committed copies by hash. Treat `gr2`
   headers as hypotheses until a second source agrees. Expect Elan and Extreme multi-GE variants to be a second phase.
9. **GIO32 bus** and the VME variants (IP12 4D/30 and 4D/35, the V30/35 guide) last; they add no new chips.

Where prior art makes RE unnecessary: Seeq 8003 frame format and register set, WD33C93A behaviour, Z85C30 basic
operation, Linux and NetBSD hardware-independent glue. Where it does not: HPC1, LG1, all of GR2, and everything about IP12's
board glue beyond the schematic.

## Corrections to earlier pages

- [indigo-challenge-era-holdings.md](indigo-challenge-era-holdings.md) lists the MC chip specification as not held. A
  specification for the Indy-generation MC is held (see section 4); whether it fits the IP20 revision is open. The HPC3
  specification is also held. HPC1 still has none.
- `devices/hollywood-dsp` says the IP20 object directory is not held. The extracted IRIX 6.5 base media carries
  `usr/cpu/sysgen/IP20boot` (section 5); no IP12 directory exists there.
- `COVERAGE.md` says the Seeq 80C03 data sheet is not held and that the MC has no source. The Seeq 8003 data sheet is held
  (two copies), and the MC specification is held.

## How this was checked

- The gr2 and iris trees were cloned shallow and read directly; MAME was fetched with a partial, sparse clone of its
  `src/mame/sgi`, `src/devices/bus/gio64` and `src/devices/machine` directories.
- NetBSD, OpenBSD, Linux, GXemul and the IRIX media listings were read from the project's local checkouts. File sizes are line
  counts at the revisions then held; the Linux snapshot is from 2018 and so predates later IP22 work.
- Forgejo and GitHub repository lists were read through their APIs.
- No hardware was touched. No restricted source was opened. Nothing here was run in an emulator.
