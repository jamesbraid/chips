# TIO

Mode: **no-spec**. No TIO register specification, firmware or silicon capture is held. Everything below comes from SGI's
own Linux platform code for the Altix (linux-5.3 pin 4d856f72c10e, the last release that carries it). For this
generation that code ranks as the vendor's software source: a fact it defines is **established**, as a software
definition, never as a measurement. Anything it only implies is **inferred**; anything it does not say is **unknown**.
Registers: [registers.md](registers.md) (five named by the code).

## What the chip is

- **A NUMAlink node that hosts widgets, not a CPU node (established).** The kernel gives a TIO its own NASID with the low
  bit set (`IS_TIO_NASID`); SHubs have even NASIDs. The architecture header counts "C-brick, M-bricks and TIOs" as the
  nodes of the NUMAlink fabric, and the hardware-performance interface lists a TIO as an "ionode" next to the
  compute nodes. The kernel's per-node data for a TIO is hub-device data only (widgets, an error interrupt), which suggests no CPUs or memory (inferred).
- **It exposes up to four widgets (established).** The small-window address field is two bits wide (256 MiB each), so widget
  0 to 3. Behind them the code knows four kinds of bridge, told apart by the type the firmware reports and by the widget
  part number: [TIOCP](../tiocp/README.md) (PCI-X), [TIOCA](../tioca/README.md) (AGP), [TIOCE](../tioce/README.md)
  (PCI Express) and the FPGA port [TIOCX](../tiocx/README.md) (widget 3).
- **Which Altix models have one is not stated.** [Open question](../../questions/altix-io-sn2-cross-check.md#pic-versus-tio-by-product).
  The PIC is the bridge the same provider drives when the node is a SHub, see [../pic/README.md](../pic/README.md).

## How the CPU reaches a TIO (established, address macros; the SHub half is the SHub page's)

- A TIO address is the NASID in the NASID field, then a two-bit chiplet field, then a node offset whose top bit must be
  set. The header's comment gives chiplet 0 as `LB` ("TIO MMR access") and 1 as `ICE` ("coretalk space access"). The NASID
  field's position and width are read from firmware at boot (the address-space field sits two bits below).
- MMRs are reached by `REMOTE_HUB_L`/`_S`, which on a SHub2 system sets the low bit of the chiplet field (`1 << (nasid shift - 2)`)
  for every TIO MMR address (`TIO_IOSPACE_ADDR`), and on a SHub1 system uses the global MMR window. Widget space is reached with no chiplet bit
  set. So the code puts MMRs in chiplet 1 and widgets in chiplet 0, **the opposite of the comment**: [question](../../questions/altix-io-sn2-cross-check.md#tio-chiplet-field).
- **Small windows** (256 MiB, widget number in address bits 29:28 of the node offset) give each widget its configuration and
  register space; every widget has its identification word at window offset 0 (revision 31:28, part 27:12, manufacturer 11:1, the Crosstalk widget layout,
  the same layout as the PIC). The FPGA-port driver reads widget 3's this way.
- **Big windows** (1 GiB, window number in address bits 32:30) are translated onto a widget by eight translation-table
  entries (`itte` register). `TIO_HWIN` (offset bits above 33) selects entry 0. The kernel only reads a firmware copy of
  these entries (to find the widget of an address in the read-ordering flush), so the register's field layout is the macro's and no write is
  observed.
- **DMA direction.** A TIOCP, TIOCA or TIOCE device addresses memory with a view whose NASID sits in bits 53:40. On a SHub1 system the node
  offset follows directly; on a SHub2 system the two bank-select bits above the bank offset are moved to bits 37:36
  (`PHYS_TO_TIODMA`). A PIC uses a different view (`PHYS_TO_DMA`). Chiplet id 0 is used for memory.

## Discovery and ownership (established)

- The kernel does not scan a TIO. Firmware describes every node, widget and bus: the kernel passes each node's hub-device
  record to a firmware call (`SN_SAL_IOIF_GET_HUBDEV_INFO`), which fills a table of up to sixteen widget identities (part, revision, manufacturer),
  the node's peer NASID ("dual-porting peer"), and the largest PCI segment and bus numbers. Each PCI bus then comes from a second firmware
  call (`SN_SAL_IOIF_GET_PCIBUS_INFO`) carrying a bus record: bridge type, widget number, persistent bus and segment numbers, the legacy
  I/O and memory window addresses and the widget base. A provider is chosen from the bridge type. Interrupt vectors and the device read-ordering
  records also come from firmware. So an emulator must supply these firmware answers, not a register walk.
- A TIO's compact node is registered like a SHub's and has hub-device data; its error interrupt is vector `0x36` (`SGI_TIO_ERROR`, a different vector from the SHub's I/O error `0x31`
  and from the PCI bridge error `0x33`; the TIOCA error is `0x35`, the FPGA port's `0x37`). The handler calls one firmware routine and panics on a
  nonzero result; it does not read TIO error registers. The firmware owns error decode. Which registers it decodes is unknown here.
- The system controller is involved: resetting the FPGA port's clock is a controller operation
  (`SAL_SYSCTL_OP_TIO_JLCK_RST`, "TIO clock reset"), and the board type of a TIO node comes from the controller
  (the sysco repository's Linux L1 firmware notes name SHub2 and TIO routines).

## The link to the SHub

The code never programs the link. No register of the TIO or the SHub that sets the link up appears in any file read; the node is simply present with
its NASID and widgets when the kernel starts. Link bring-up belongs to the controller and firmware (unknown here; the
sysco repository's firmware notes read the controller's side). **Unknown:** the physical link kind (the architecture header
counts TIOs inside the NUMAlink node limit, so a NUMAlink-class attachment is likely but not stated).

## Registers and constants the code names

[registers.md](registers.md): `node_id`, `itte` (eight entries), `ice_frz_cfg`, `ice_pmi_tx_cfg` and
`ice_pmi_tx_dyn_credit_stat_cb3`. The last three are the only ICE-chiplet registers touched, all by the FPGA-port driver.

Read together, the FPGA-port driver's procedure is established:

1. Pulse corelet reset: write `1 << 3` to `ice_pmi_tx_cfg`, wait 2 ms, write 0, wait 2 ms.
2. Clear the conveyor-disable bit (bit 61) of `ice_frz_cfg` to enable the conveyor (the driver does this once at attach).
3. Treat `ice_pmi_tx_dyn_credit_stat_cb3` low nibble equal to 15 as "bitstream loaded".
4. On the reload path, when the bitstream is loaded, ask the controller to reset the port clock, then read the identification word at offset 0 of widget 3's small window. A part number of
   `0xce00` is a TIOCE, which the driver leaves alone; anything else is an FPGA and is registered as a bus device with its part and manufacturer numbers.

## Workaround that depends on the TIO revision

The TIO identification word's revision field decides one erratum (named PV907516 in the code): on revision 1, the TIOCP's per-device write
buffer flush register must not be read; on other revisions the read is the kernel's read-ordering primitive. See [TIOCP](../tiocp/coverage.md).
No other revision-dependent behaviour is named.

## Not covered

No register of the TIO's local block (LB) is named by any file read except the identification word. The TIO's own interrupt routing, link
layer, error registers, memory-mapped counters and the ICE chiplet beyond the three registers above are **unknown**; the route is a TIO
register specification or the controller firmware's register tables (sysco holds readings of the latter).
