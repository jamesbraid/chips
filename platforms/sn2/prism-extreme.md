# Silicon Graphics Prism, Extreme

The large Prism: CR-bricks (compute plus router) and I/O bricks in 40U racks, with XG2N graphics modules and CPU expansion
modules racked beside them. The compute side is the same brick family as the [Altix 3700 Bx2](altix-3700-bx2.md); the
graphics modules are the [Power and Team](prism-power-team.md) XG2N. The product line is on [the Prism overview](prism.md).

Sources: SGI, *Silicon Graphics Prism Visualization System User's Guide for Extreme Scalable Configurations*, `007-4774-001`
(May 2005), printed pages (PDF page is printed page plus 26). -002 (Oct 2005) differs by the ProPack 4 Service Pack 2
update; only its revision record was read. Linux cites are `v5.3:path`. Grades: see [the SN2 README](README.md).

## Scale (established)

- "A family of multiprocessor distributed shared memory computer systems that scale from 8 to 128 Intel 64-bit processors" as
  one cache-coherent system image; each rack holds 8 to 64 processors in one to eight CR-bricks (p.55). A rack can hold up to
  40 processors and 8 graphics pipes (p.57); the system tops out at 128 Itanium 2 processors and 8 pipes (p.57), with up to
  1.5 TB of contiguous memory (p.59).
- The interconnect is described as "fourth-generation NUMAflex ... NUMAlink-4", with two router switches in each CR-brick
  (p.59).
- Memory is distributed over the CR-bricks and XG2N and compute modules; a CR-brick with memory and no processors is called a
  "memory node" or M-brick (p.61).

## Bricks (established, pp.65, 66, 95 to 97; Figure 3-4)

| Brick | Facts |
|---|---|
| CR-brick (4U) | four SHUB ASICs, eight Itanium 2 CPUs on four node boards (two CPUs and 4, 8 or 12 DIMMs each), eight NUMAlink-4 router ports on two 8-port router ASICs ("NL4"), up to 48 DIMMs (JEDEC 184-pin), two XIO ports from nodes 1 and 3 on the rear; 6.67 in. high, 29 in. deep, 68 lb, 48 VDC about 1300 W |
| IX-brick (4U) | boot I/O: 12 PCI-X slots, disks and DVD-ROM; one IO9 base I/O card per partition (Figure 3-4) |
| PX-brick (4U) | 12 PCI-X slots on 6 buses |
| R-brick (2U) | eight-port NUMAlink router, optional |
| XG2N module (2U) | 0 or 2 Itanium 2, 0 to 24 GB, two graphics pipes, L1; connects "as an integral part of the system's compute/memory fabric" and "may not be used as a standalone system" (pp.74, 75) |
| CPU expansion module (2U) | like the XG2N with no pipes (p.81) |
| Power bay (3U) | up to six supplies, 200 to 240 VAC to 48 VDC, eight 48 VDC outputs |
| D-brick2, TP900, SGIconsole | storage and management options (p.65, 68) |

Rack numbering: three digits, compute racks from 001 (p.67); L1 brick names such as "001c02" use rack, brick type and slot.

## SHub generation and node board (conflicted)

The CR-brick block diagram (Figure 3-3, p.60) labels each of its four nodes "IP57 Node Card" and "SHUB 1.2", with two
`XIO` pads and two `NI` ports per node. Established as the figure's text. The text beside it
calls the machine NUMAlink-4 (p.59). The Altix 3700 Bx2 guide's own CR-brick diagram carries the same "SHUB 1.2" label, so the label is consistent: NUMAlink 4 with SHub 1.2 (see [the Bx2 page](altix-3700-bx2.md)). The Linux
kernel decides at boot from the PROM (`ia64_sn_get_sn_info`, see the README) and a boot capture would still confirm it. The same
"IP57" name is the Altix 350 node board ([altix-350.md](altix-350.md)); here it appears as a node card inside the CR-brick.

## Graphics (established)

- Same XG2N as Power and Team, same two pipe numbering, same ImageSync daisy chain (IS card in the base compute side to
  `IS1` of the first XG2N, `Repeat` to the next `IS1`; pp.83 to 85) and the FireGL X2PRO-256 and X3-256 rear panels
  (Figures 5-2 to 5-5, pp.76 and 77). See [the overview](prism.md#graphics-boards-and-outputs).
- The Extreme guide's Figure 3-4 shows the compositor ("CBOB", the Scalable Graphics Compositor) in the rack, with four
  DVI inputs, a DVI output and an analog output (p.66).
- Pipe numbers follow the module order; `gfxtopology` (007-4751-001) prints rack, slot and the closest CPU brick.
- Node-connected NUMAlink, through the CR-brick routers or an R-brick: the XG2N's two `NUMALINK` ports connect to the
  fabric (Figure 5-2). The cabling lists beyond the figure were not read.

## Controllers and firmware (established)

L1 in every brick and XG2N; an L2 is emulated by an SGIconsole or by a USB-to-Ethernet adapter ("L2 emulator operation",
chapter 2). The L1 firmware is the `snxsc_firmware` package, version `1.18.3-1` in the guide's example, with a boot image and
images A and B, flashed through `flashsc` (pp.52, 53). That version string is the only SGI controller revision tied to a
Prism document. Details: [the overview](prism.md#firmware).

## Not covered

CR-brick pinouts and rear panel (chapter 6, pp.91 to 94), IX-brick and PX-brick PCI card lists and tables (chapters 7 and 8),
the L2 emulator commands (chapter 2). Open questions: [prism-open.md](../../questions/prism-open.md).

## Review

Independent review, 2026-11-14, by a reviewer who wrote none of these pages. Reviewed chips revision a399d6d (pages from ee45651 and a399d6d). Sources: the SGI printed manuals, printed pages; Linux v5.3 single files from raw.githubusercontent.com, `arch/ia64/include/asm/sn/{tioca.h,pcibus_provider_defs.h}`, `arch/ia64/sn/pci/tioca_provider.c`, `arch/ia64/sn/kernel/setup.c`, `drivers/char/agp/{sgi-agp.c,Kconfig}`; public github.com/jamesbraid/voyager `README.md`, `devices/README.md`, `questions/open-questions.md`.

Checks: 007-4774-001 Figure 3-3 (printed p.60) shows four nodes labelled "SHUB 1.2" and "IP57 Node Card", two `XIO` pads and `NI` ports per node, with two router banks; the page records exactly that text, notes that the page 59 text says NUMAlink-4, calls the conflict unknown and names a boot capture as the settling evidence. The scale, the brick table sources (pp.55 to 66 and 95 to 97) and the L1 firmware version `1.18.3-1` are as cited in the overview review (only the figure, the record of revision and the contents were re-read for this page). "IP57" is correctly said to be the Altix 350 node board name, here appearing as a node card.

Findings: none that need editing. The page graded the label "established as the figure's text" and the machine's SHub generation unknown; that is the right split.

Cleared scope: the scale statements, the SHub-label and IP57-label handling, and the firmware and graphics statements as sourced. Not cleared: the brick table rows other than those in the figure and p.55 to 61 (the weights, power and DIMM counts were not re-read).
