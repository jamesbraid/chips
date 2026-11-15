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
  entries (`itte` register). `TIO_HWIN` (offset bit 33 and above) selects entry 0. The kernel only reads a firmware copy of
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
  records also come from firmware. So these come from firmware answers, not from a register walk.
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

## Widget numbering and windows (established, `addrs.h` v5.3)

A TIO's address space is `uncached | nasid << NASID_SHIFT | node offset`. `AS_SHIFT` is `NASID_SHIFT - 2` and is the width of the node offset; firmware reports `NASID_SHIFT` through `SN_SAL_GET_SN_INFO`, so no absolute width is fixed by the header (with the SHub 1 fallback of 38 the offset is 36 bits). Inside the offset:

| Range of the offset | Meaning | Source |
|---|---|---|
| bits 29:28 | small-window widget number 0 to 3, 256 MiB each (`TIO_SWIN_WIDGETNUM`) | established |
| bits 32:30 | big-window number 0 to 7, 1 GiB each (`TIO_BWIN_WINDOWNUM`) | established |
| bits 33 and up | `TIO_HWIN` (`TIO_HWIN_SHIFT_BITS` 33), nonzero selects ITTE entry 0 in the flush path | established |
| MMR offsets `0x90060e80`, `0xb000....` | register offsets, chiplet-qualified as above | established |

The widget table in the kernel has sixteen slots (`HUB_WIDGET_ID_MAX` 0xf) because it is shared with the SHub, whose small-window widget field is four bits. A TIO's small window has only two widget bits, so only slots 0 to 3 can be addressed by a small-window address; the other slots are **inferred** unused on a TIO.

**Which ITTE a PIO address uses (established, `sn_dma_flush`).** If `TIO_HWIN` of the address is nonzero the kernel uses entry 0. Otherwise a nonzero big-window number picks that entry. Otherwise the address is a small-window address and its widget is bits 29:28. A picked entry that has `valid` clear ends the lookup with no widget. The widget is bits 13:12 of the entry. This is the kernel's use of a firmware-held copy of the entries; no register read or write is observed. **Inferred:** the header says the node offset's top bit must be set, which makes `TIO_HWIN` nonzero for every such address, so entries 1 to 7 would then be reachable only through offsets with the top bit clear. Whether that is what the hardware does is [open](../../questions/tio-open.md#itte-use).

The ITTE layout differs from the SHub's IIO table: a TIO entry has offset 7:0, widget 13:12 and valid at bit 16; the SHub entry carries a four-bit widget at bits 11:8 and has seven usable entries (`IIO_NUM_ITTES`). Do not share the decode.

## Crosstalk widget numbers and widget types (established)

The kernel distinguishes widgets by the bridge type the firmware reports in the bus record (`PCIIO_ASIC_TYPE_TIOCP` 3, `TIOCA` 4, `TIOCE` 5; the SHub-side PIC and PPB use other values) and by the widget's identification word. The record's `bs_xid` is the widget number and indexes the node's widget table. Fixed assignments seen in code: widget 3 is the FPGA port (corelet), and a TIOCE can be the occupant of widget 3 (part `0xce00`). No fixed number is given for TIOCP or TIOCA: the code takes it from firmware. Which widget a given Altix model puts each bridge on is **unknown**.

The identification word at small-window offset 0 uses the Crosstalk layout: revision 31:28, part 27:12, manufacturer 11:1. Part numbers named in the pinned files: `0xce00` (TIOCE, `TIOCE_PART_NUM`) and `0xe020` (TIOCA, `TIOCA_PART_NUM`, `tioca.h`); no TIOCP part number is stated by the files read; the PIC's (`0xd102`) is in the PROM reading, see [PIC](../pic/README.md).

The kernel also declares a Crosstalk widget configuration structure (`struct widget_cfg`, `xwidgetdev.h`: id, status, error address, control, request timeout, interrupt destination, error command, link-layer configuration, flush, each a 32-bit word in the odd half of an eight-byte pair). No TIO code read uses it, so it is established only as a declaration and **unknown** as a TIO hardware contract.

## Address views (established)

- **PIO to a TIO MMR** needs the chiplet field set to 1 on a SHub 2 system and the ordinary global MMR window on a SHub 1 system (see above).
- **Coretalk address** (what a device behind the TIO sends, and what the interrupt destination words hold): NASID in bits 53:40 (`CTALK_NASID_MASK` 0x3fff), chiplet id in bits 39:38 (`CTALK_CID_MASK`), node offset in bits 37:0 (`CTALK_NODE_OFFSET`). The header comment in `addrs.h` names bits 38 to 39 for the chiplet. Chiplet 0 is used for DMA to memory ("our belief ... ICE, which is also zero", the code says of TIO to TIO DMA); that belief is a developer note, not a measurement (inferred).
- **PHYS_TO_TIODMA** (established): SHub 1 uses `nasid << 40 | node offset`. SHub 2 uses `nasid << 40`, the low `NASID_SHIFT - 4` bits unchanged and the two bits above them moved to bits 37:36. This is the view used by TIOCP, TIOCA and TIOCE mappings (all three providers call it).
- **TIOCX** adds `TIOCX_DMA_ADDR` (clears bits 37:36, keeps 55:0) and `TIOCX_TO_TIOCX_DMA_ADDR` (keeps 35:0, moves 55:38 up two); see [TIOCX](../tiocx/README.md).

## Interrupts (established unless marked)

- **Vectors.** `SGI_TIOCA_ERROR` 0x35, `SGI_TIO_ERROR` 0x36, `SGI_TIOCX_ERROR` 0x37 are reserved kernel vectors below the first device vector 0x3c. Device interrupts from bridges behind a TIO use vectors 0x3c to 0xe6 chosen by firmware.
- **Error interrupt.** At node setup (`sn_common_hubdev_init`) a TIO calls `ice_error_init`, which requests vector 0x36 as a shared, level-handled interrupt named "SN_TIO_error" with the node's hub-device record as the cookie, and pins its affinity to the boot CPU when the PROM advertises CPU-disable support on a SHub 2. The handler calls `SN_SAL_HUB_ERROR_INTERRUPT` (0x02000060) with the NASID and panics on a nonzero first result. The SHub's own BTE and CRB handling is skipped for a TIO.
- **Allocation.** A bridge's interrupt is allocated by firmware: `SN_SAL_IOIF_INTERRUPT` (0x0200004a) with operation 1 (alloc), 2 (free) or 3 (redirect), the TIO NASID, the widget number, the physical address of an `sn_irq_info` record to fill, a requested vector, and a target NASID and slice. The record the firmware fills holds the vector, the bridge pin (`irq_int_bit`, negative for MSI), the target CPU, and `irq_xtalkaddr`, the Crosstalk address the bridge must write to raise the interrupt. The kernel never computes that address. The TIOCX path uses the same call (`tiocx_irq_alloc`) and refuses even NASIDs.
- **Delivery word (established for the TIOCE).** The bridge's per-pin destination register holds the vector shifted left by 56 ORed with `irq_xtalkaddr`; the kernel masks the pin, stores the word, then unmasks. TIOCP uses its own destination register with the address alone. See the [TIOCE](../tioce/README.md) and [TIOCP](../tiocp/README.md) pages for the registers.
- **Forced interrupt on TIOCE rev A (workaround PV945826).** When the pin is pending, the kernel stores `(1 << 8) | vector` at the TIO address that the Crosstalk address names (NASID from bits 53:40, offset from bits 37:0, through the normal TIO accessor). The NASID there is the interrupt's target, which firmware allocates on a CPU node (`req_nasid`), so the store most likely lands on the SHub 2 side through the TIO address macro, not on a TIO (inferred); the register it hits is not named (unknown).
- **No lost-interrupt check for TIO bridges** (`sn_check_intr`): the check applies to the PIC only, because bridges behind a TIO "do not target SHub II interrupt registers". That sentence says the TIO delivers interrupts by a different path from the PIC; the path itself is not described (**unknown**).

## Firmware and controller interface (established, `sn_sal.h`, `l1.h`, `klconfig.h`)

| Item | Value |
|---|---|
| `SN_SAL_SYSCTL_OP` operation 1 | board type of the I/O board of a NASID, returned in the first or second value |
| `SN_SAL_SYSCTL_OP` operation 2 | reset the TIO's corelet clock (`SAL_SYSCTL_OP_TIO_JLCK_RST`) |
| `SN_SAL_IOIF_GET_HUBDEV_INFO` 0x02000055 | fill the hub-device record: sixteen widget identities, dual-porting peer NASID, maximum segment and bus numbers |
| `SN_SAL_IOIF_GET_PCIBUS_INFO` 0x02000056 | per-bus record (type, widget id, persistent bus and segment, legacy windows, base) |
| `SN_SAL_IOIF_GET_DEVICE_DMAFLUSH_LIST` 0x0200005a | per-widget, per-device flush records (BAR ranges, slot, flush address) used by the read-ordering path |
| `SN_SAL_IOIF_INTERRUPT` 0x0200004a | see above |
| `SN_SAL_HUB_ERROR_INTERRUPT` 0x02000060 | TIO error service |
| board class `KLTYPE_TIO` | 0x12 (class node, type 2) in the klconfig board list |
| I/O board types that carry an FPGA port | controller codes 0x5e, 0x2b and board 0x0800 (named for SA, Athena and Daytona in the header); the Opus TIO brick has code 0x66 |
| module type | `MODULE_SABRICK` 13 ("TIO bring-up brick") and `MODULE_OPUS_TIO` 17 ("Opus TIO riser") |

Each widget has up to `DEV_PER_WIDGET` (32) device records. The performance interface names the TIO class "ionode" and bars it from node-only operations. The product mapping of these code names is **unknown**.

## Workaround that depends on the TIO revision

The TIO identification word's revision field decides one erratum (named PV907516 in the code): on revision 1, the TIOCP's per-device write
buffer flush register must not be read; on other revisions the read is the kernel's read-ordering primitive. See [TIOCP](../tiocp/coverage.md).
No other revision-dependent behaviour is named.

## Not covered

No register of the TIO's local block (LB) is named by any file read except the identification word. The TIO's own interrupt routing, link
layer, error registers, memory-mapped counters and the ICE chiplet beyond the three registers above are **unknown**; the route is a TIO
register specification or the controller firmware's register tables (sysco holds readings of the latter).

## Review

Independent review on 2026-11-14 by a reviewer who did not write these pages. Revisions: chips commits 4924130..b536f7d, read at main 15a5a4e484. Grading rule: the SN2 paragraph of the evidence order in `retools/tools/README-analysis.md` (SGI's Linux platform code ranks first for this generation, and a fact it defines is `established` as a software definition). Sources: the Linux v5.3 files the page cites, fetched singly from the tagged tree (`drivers/misc/ioc4.c` and `include/linux/ioc4.h` at v4.19, where they still exist).

**Reviewed commits.** 211a80d (tio page and registers); the TIO entries of the cross-check questions file (e7a9bc0 and later); the allow-list entry and the address-width change in `tools/config` that arrived with 87e1291 and b536f7d.

**Checked.** All five registers (`node_id` 0x90060e80; `itte` 0xb0008800, eight entries, stride 8, fields 7:0, 13:12 and 16; `ice_frz_cfg` 0xb0008100 bit 61; `ice_pmi_tx_cfg` 0xb000b100; `ice_pmi_tx_dyn_credit_stat_cb3` 0xb000be18 mask 0xf) and all five constants against `tio.h`, `tiocx.h`, `addrs.h` and `intr.h`: every offset, field position and value matches. The prose: node-offset layout and the chiplet comment against the SHub 2 MMR macro (the inversion is real and the open question is fair), small and big window arithmetic (`TIO_SWIN_*` 28 and mask 3, `TIO_BWIN_*` 30 and mask 7, `TIO_HWIN` selecting entry 0), the DMA view macros (`PHYS_TO_TIODMA`, NASID in bits 53:40, bank-select bits to 37:36), the firmware calls (`SN_SAL_IOIF_GET_HUBDEV_INFO`, `_GET_PCIBUS_INFO`, `SAL_SYSCTL_OP_TIO_JLCK_RST`), sixteen widget slots, the error vector 0x36 and its handler (`huberror.c`: one firmware call, panic on failure), the corelet reset and conveyor procedure (2 ms delays, bit 61, credit count 15, part 0xce00 test) and the PV907516 revision test (`(1 << rev) & (1 << 1)`, so revision 1). The node count wording ("C-brick, M-bricks and TIOs") and the performance-interface "ionode" classification are in `arch.h` and `sn_hwperf.h`. No hardware behaviour or reset value is graded established from the header; reset values are stated unknown.

**Findings.**
- Fixed (mechanical): the `node_id` text said the kernel reads a 32-bit value. The load goes through the 64-bit register type and the result is truncated to 32 bits; the register doc now says so (the width matters to a model's access check). Generated files regenerated.
- Judgement, left: `node_id` and the credit-status register are marked `access = "r"` because the kernel only reads them. The header gives no direction; the TIOCA and TIOCE pages mark the same situation as a placeholder `rw` with a note. The two conventions differ across the family and neither is stated in this page. Treat `r` here as "seen only read", not as a hardware property.
- Judgement, left: `SGI_TIOCX_ERROR` (0x37) is defined in `intr.h` but nothing in the pinned files registers it, so "the FPGA port's 0x37" is a defined name, not an observed use. The wording is compatible with that.
- The allow-list entry for 0x90060e80 is a false positive of the leak scan: the value is the TIO identification offset in `tio.h` (`TIO_NODE_ID`), a node offset, not a kernel virtual address. Benign.
- `tools/config/defs-check.toml` widens the offset check from 32 to 36 bits for every unit. The TIO offsets all fit in 32 bits (the largest is 0xb000be18), so this unit does not need it; the widening presumably serves the SHub pages, which this review did not cover.

**Cleared scope.** Every register, field and constant on this page and every sourced statement in the README, as pinned to Linux v5.3. Not cleared: anything about the TIO's own registers beyond these five (the page correctly says none are named), the link layer, and which Altix models carry a TIO.

## Review

Second independent review on 2026-11-15 by a reviewer who did not write the new sections. Revisions: chips commits 7faf65b and e001983 on main 95445a3. Grading rule as in the earlier review below: SGI's Linux platform code is the vendor's software source, so what it defines is established as a software definition. Sources: the Linux v5.3 files the page cites, fetched singly from the tagged tree (`tio.h`, `addrs.h`, `tiocx.h`, `tiocx.c`, `intr.h`, `sn_sal.h`, `io_init.c`, `io_common.c`, `irq.c`, `huberror.c`, `pcibr_dma.c`, `pcibr_provider.c`, `tioce_provider.c`, `tioca.h`, `tioce.h`, `klconfig.h`, `l1.h`, `module.h`, `arch.h`, `xwidgetdev.h`, `hubdev.h`, `pcibus_provider_defs.h`, `sn_hwperf.c`, `setup.c`), plus one Ghidra reading of the SHub 2 PROM (build 10.40) for the TIO register offsets. The review sampled about 60 statements, all in the new sections and constants.

**Confirmed.** Window arithmetic (`TIO_SWIN_SIZE_BITS` 28, mask 3; `TIO_BWIN_SIZE_BITS` 30, mask 7; `TIO_HWIN_SHIFT_BITS` 33; `AS_SHIFT` = `NASID_SHIFT` - 2; `NODE_OFFSET` masks to the node-offset width). The entry-selection order in `sn_dma_flush` and the valid-bit early return. The ITTE macro fields and the SHub entry contrast (`IIO_ITTE_WIDGET` four bits at 8, `IIO_NUM_ITTES` 7). The SHub 2 MMR macro setting `1 << (NASID_SHIFT - 2)` and the SHub 1 macro using the global MMR window, so the comment-versus-code inversion is real. `TIO_SWIN_BASE` setting no chiplet bit. Coretalk masks (NASID 53:40, chiplet 39:38, offset 37:0). `PHYS_TO_TIODMA` for both SHub generations, including the bank-select bits at 37:36, and `PHYS_TO_DMA` for the PIC. `TIOCX_DMA_ADDR` (clears 37:36, keeps 55:0) and `TIOCX_TO_TIOCX_DMA_ADDR` (keeps 35:0, moves 55:38 up two). Sixteen widget slots (`HUB_WIDGET_ID_MAX`), `DEV_PER_WIDGET` 32, eight `iio_itte` words. Vectors 0x35, 0x36, 0x37, 0x3c to 0xe6. `ice_error_init` (shared level-handled vector, name "SN_TIO_error", boot-CPU affinity only on SHub 2 with CPU-disable support) and the handler (one firmware call, panic on a nonzero first result, BTE and CRB handling skipped for a TIO). `SAL_INTR_ALLOC/FREE/REDIRECT` 1, 2, 3 and the argument order of `tiocx_intr_alloc`; the refusal of even NASIDs. Negative `irq_int_bit` meaning MSI. The TIOCE delivery word (vector shifted by 56 ORed with the Crosstalk address; mask, store, unmask) and the TIOCP register taking the address alone. The rev A forced-interrupt store `(1 << 8) | vector` and its address decode (not its destination, see Findings). `sn_check_intr` limited to the PIC. All firmware call numbers in the table (0x2000030, 0x200004a, 0x2000055, 0x2000056, 0x200005a, 0x2000060) and sysctl operations 1 and 2. `KLTYPE_TIO` 0x12, the `is_fpga_tio` set (SA 0x5e, Athena 0x2b, Daytona board 0x0800), the Opus TIO brick 0x66, module numbers 13 and 17. The "ionode" label and the node-count comment. The corelet reset, conveyor and credit-count procedure, the PV907516 test and the 64-bit read truncated to 32 bits. All eight constants in `registers.toml` that were new. `defs-gen` output matches the committed generated files.

**Mechanical fixes.**
- The big-window paragraph, the window table and the ITTE question said `TIO_HWIN` selects on "bits above 33". The macro shifts by 33, so bit 33 itself counts; now "bit 33 and above".
- The widget-numbering section said no TIOCA part number is stated. `tioca.h` defines `TIOCA_PART_NUM` as `0xE020` (the TIOCA page already says so). The sentence now names it and the TIOCE macro; no TIOCP part number is stated, which stays true.

**Findings not fixed.**
- `node_id` is probably not a read-only identification word. The SHub 2 PROM (Ghidra, function at `0xff4ae920`, called from `0xff46ec90`) read-modify-writes offset `0x90060e80` with a 14-bit value at bits 45:32 (a NASID-width field) and a 6-bit value at bits 53:48. The registers.toml entry says `access = "r"`, width 64 with fields only at 31:1, which is correct for what Linux does and incomplete for the register. Graded inferred and opened as [a question](../../questions/tio-open.md#tio_node_id-upper-bits): the caller was not traced to prove the node is a TIO, and objdump agrees with Ghidra on the immediates and field positions. The other offsets (`0xb0008100`, `0xb0008800`, `0xb000b100`, `0xb000be18`) do not appear as immediates in that PROM's decompilation, so no PROM cross-check of them was possible.
- The inferred paragraph after the entry-selection text argues from the header's "top bit must be set" that every TIO address has `TIO_HWIN` nonzero. The same header's `TIO_SWIN_BASE` builds widget addresses as `w << 28` with no high bit, and every MMR offset the code names is below `2^32`, so the header's "top bit" cannot be the bit just under the chiplet field for those. The inference may only hold for big-window or DMA-style addresses. It is labelled inferred and the question stays open; the reasoning should not be read as bounding which ITTE entries are reachable.
- The PROM's error strings name three TIO units, `TIO_ICE`, `TIO_XN` and `TIO_LB`. The page names only LB and ICE (from the two chiplet values the header gives). An XN unit exists in the PROM's vocabulary and is not in the page; that is a source gap for the local-block question, not an error.
- The forced-interrupt paragraph earlier read the store as going to "a TIO address". The NASID comes from `irq_xtalkaddr`, which `sn_intr_alloc` fills for the requested target NASID, normally a CPU node. Reworded to inferred, as above; the macro used (`TIO_IOSPACE_ADDR`) does not test the NASID's parity, so the code does not itself say the target is a TIO.
- Step 4 of the FPGA procedure says "anything else is an FPGA and is registered". The code registers the device in every case where widget 3 is not a TIOCE, including with part and manufacturer set to "none" when no bitstream is loaded. Wording only; left.
- Earlier review findings stand: `r` access means seen only read, and 0x37 is a defined name with no registration in the files read.

**Cleared scope.** Every sourced statement and constant in the sections added by e001983, the three open questions of 7faf65b and the two wording fixes above, as pinned to Linux v5.3. Not cleared: the `node_id` register's width of meaning beyond bits 31:1, the TIO's local block, link layer and error registers, and which Altix models carry a TIO. The binary reading covers one PROM build and one function; the other builds were not read.

