# TIOCP

Mode: **no-spec** (see [references/documents/specs.md](../../references/documents/specs.md)).

PCI-X bridge of a later system family (the Altix-class SN2 generation, whose crossbar chip is the TIO). The Altix SN2 PROMs carry a TIOCP
attach routine, so it is an SN2 chip; which model has one is open. Nothing in the IRIX 6.5.30 builds read here drives it.

Status: no entries. The census of the shared Bridge-family accessors already lists the offsets those accessors reach
when the chip type is 3 or the part number is `0xe000` or `0xe010`: the `tiocp` rows of
[../pic/census/census.tsv](../pic/census/census.tsv) (43 offsets, 163 access sites). The tool config
[`tools/configs/tiocp.json`](../../tools/configs/tiocp.json) is the older stub and runs no census of its own; the header
[`generated/c/tiocp.h`](../../generated/c/tiocp.h) is generated from those same rows.

## What the binaries say about the TIO and TIOCP (established)

- **No TIO code.** The names `tio_init_xswitch_widgets` and `Tio_brick_map_widget` occur in `kernel.o` of the IP35 boot
  set, but only in its debug name tables. The object has no text symbol with either name, no call to either and no
  relocation against either: the routines were compiled out of this build or belong to a kernel for another platform. A
  search of every IP27 and IP35 object, member and firmware image for the strings `tio_`, `Tio_`, `TIO_` and `tiocp`
  finds `tiocp.h` as a header name in the debug line tables of `kernel.o`, `pcibr.o`, `pciio_ppb.o` and `xbridge.o` in
  both builds, and of `pic.o` and the USB driver in the IP35 build (the IP27 set has `usrpci.o` in the same position). A header the compiled code includes; its contents are not in the binaries.
- **The software enumeration names it.** The debug type information of `space.o` (a member of `os.a` in both the IP27 and
  IP35 boot sets) defines an enumeration `pciio_asic_type_e` with the values UNKNOWN 0, MACE 1, BRIDGE 2, XBRIDGE 3, PIC 4
  and TIOCP 5. This is the PCI I/O layer's own numbering, not the halfword at record +114 that the accessors test (0 to 3),
  so the two must not be conflated. The IP27 build carries the same enumeration, so the name is evidence that a driver could
  be written for the chip, not that the machine has one.
- **TIOCP in the shared accessors.** The `pcireg_*` routines of `pcibr.o` branch on the halfword at record +114 (3 selects the
  fourth chip) and, for a raw pointer, on part `0xe000` or `0xe010` with manufacturer id 36. Every such branch uses the
  same 64-bit layout as PIC. The census differs from the PIC rows in one register: `+0x48`
  (`pcireg_llp_cfg_get` and `pcireg_llp_cfg_set`) is reached only on the PIC path. In `pcireg_llp_cfg_get`
  (`pcibr.o` `0x10bb4`, read in full) a record with chip type 3 branches to a `panic` call (at `0x10d18`), and so does a
  raw pointer whose part number is `0xe000` or `0xe010` with manufacturer 36; the message text was not read, so whether it
  says the register is undefined for the chip is unknown.

## Against the public Linux ia64 header (reported after the reading above)

The Linux ia64 SN code of the 2.6.33 era carries a `struct tiocp` (`arch/ia64/include/asm/sn/tiocp.h`). All 41 census
offsets that fall below `+0x10000` and the `+0x10000` translation RAM sit at the same offsets there, with the same
register meanings the accessor names give (agree; two software readings meeting, so inferred, not a measurement). Two
differences, both read in full in the IRIX accessors and independent of the header: `+0x48` does not exist (the shared
accessor panics with "undefined register", the header leaves padding), and the `+0x80000` external translation RAM does
not exist (`pcireg_ext_ate_get` panics with "not a BRIDGE ASIC" for chip type 3 and for parts `0xe000` and `0xe010`; the
census row at `+0x80000` credits the Bridge-only read path to the TIOCP variant and is a scanner artifact). The grading,
the Linux-only facts (54-bit interrupt address, command type in DMA address bits 61:60, the PV907516 flush erratum) and
the tests that would settle the rest are in [devices/tiocp/coverage.md](coverage.md).

## Against SGI's Altix Linux code (linux-5.3 pin 4d856f72c10e)

The PIC page records the provider and its checks ([../pic/README.md](../pic/README.md)); this section is the TIOCP half. Under the evidence rule
for the Altix generation, SGI's own header and provider define names and layouts, so each name below is **established** as a software definition (the
IRIX accessor names the census carries stay inferred; the two readings agree on every offset, which the coverage page tabulates). Files read in full:
`tiocp.h`, `pcibr_provider.h`, `pcibus_provider_defs.h`, `pcibr_reg.c`, `pcibr_dma.c`, `pcibr_ate.c`, `pcibr_provider.c`.

**Names.** The census registers map to the same SGI names as the PIC's, with a `cp_` prefix in place of `p_wid_` or `p_`: `+0x0` `cp_id`,
`+0x18` `cp_err_lower`, `+0x20` `cp_control` (the census name `ssram_size` came from the accessor that sets the SSRAM size field of it), `+0x28`
`cp_req_timeout`, `+0x38` `cp_intr_lower`, `+0x40` `cp_err_cmdword`, `+0x50` `cp_tflush`, `+0x58` `cp_aux_err`, `+0x60` `cp_resp_upper`, `+0x68`
`cp_resp_lower`, `+0x78` `cp_addr_lkerr`, `+0x80` `cp_dir_map`, `+0x90` `cp_map_fault`, `+0xa0` `cp_arb`, `+0xb0` `cp_ate_parity_err`, `+0xc0`
`cp_bus_timeout`, `+0xc8` `cp_pci_cfg`, `+0xd8` `cp_pci_err_lower`, the interrupt block `+0x100` to `+0x1f8`
(`cp_int_status`, `_enable`, `_rst_stat`, `_mode`, `_device`, `_host_err`, `cp_int_addr[8]`, `cp_err_int_view`, `cp_mult_int`, `cp_force_always[8]`, `cp_force_pin[8]`),
`cp_device[4]`, `cp_wr_req_buf[4]` (`+0x240`), `cp_rrb_map[2]`, `cp_resp_status`, `cp_resp_clear`, the PCI-X block `+0x600` to `+0x630`, and `cp_int_ate_ram[1024]` at `+0x10000`.
The PIC's `+0x48` link-layer register has no TIOCP counterpart (the header leaves padding). The full table of the shared names is on the [PIC page](../pic/README.md).

**Registers the header adds** (extra unit `tiocp_extra`, all unreached by IRIX): the upper halves of the widget error, interrupt and PCI error addresses, widget status,
test pin control, the buffer address match pairs, the performance monitor blocks, `cp_pcix_timeout`, the **debug control registers at `+0x700` to `+0x730`** (TIOCP only), the PCI-X
read and write buffers, the manual-parity translation copy at `+0x14000`, the **write request RAM** (`+0x18000`, three banks) and the **read response RAM** (`+0x1c000`, three banks).
The PIC has the write request RAM too, at the same offsets, and no read response RAM or debug registers.

**What the provider adds** (S = SGI Linux v5.3; the PIC differences are in the PIC section):

- **Window layout differs from the PIC.** Seven type-0 configuration windows from `+0x21000` (the first window below is the unused host device),
  device I/O windows of 1 MiB from `+0x200000` and the same again with flush from `+0xa00000`; device n uses window 2n for n below 2 and n + 2 otherwise.
  The PIC has eight configuration windows from `+0x20000` and no device I/O windows.
- **DMA addresses.** A 64-bit direct address carries a command type in bits 61:60 (1 memory, 3 message-signalled interrupt) where the PIC carries a
  target widget in bits 63:60. The DMA view of memory is `PHYS_TO_TIODMA`, not the PIC's.
- **Translation entries.** Bit 1 is programmed-I/O (the PIC's coherent bit). For a message-signalled mapping the kernel sets both bit 2 and bit 1. No target widget field.
- **Interrupt address field is 54 bits** (mask `0x003fffffffffffff`) against the PIC's 48.
- **Read ordering (erratum PV907516).** Instead of forcing an interrupt and waiting, S reads the per-device write-request flush register `cp_wr_req_buf[slot - 1]`, which "ensures the data has entered the
  coherence domain, unlike the PIC's". On a TIO whose identification revision is 1 the kernel does not read it and returns without ordering at all (the kernel's choice; what the hardware does on revision 1 is unknown).
- **No part number.** The v5.3 headers define part numbers for the TIOCA (`0xe020`) and TIOCE (`0xce00`) but none for the TIOCP, so `0xe000` and `0xe010` as TIOCP remain IRIX-accessor evidence only (inferred).

## Field layouts, reads and reset (SGI Linux v5.3 provider; PROM names)

Bit layouts are in the extra unit's words ([registers-extra.md](registers-extra.md)): the translation entry flags, the 64-bit direct DMA address
attributes (command type in 61:60), the swap bit of a 32-bit mapped address, the control register's page-size bit (21), the device register's
swap-direction bit (19), the widget identification split, the per-pin interrupt bits and the 54-bit interrupt destination field. All
**established** as software definitions, and only for the bits the provider touches. The header gives no field layout for any other register, so
the rest of every register is **unknown**. The PIC page's layouts are a sibling's and fill nothing here.

- **Reads with an expected value (established, driver expectations).** The target flush register (`+0x50`) must read zero; the provider panics on
  any other value after every translation-entry update, as its way of waiting for the stores to complete. The per-device write request flush
  register (`+0x240` and up) is documented as reading zero; its value is discarded, the read itself is the effect.
- **Reset values: unknown for every register.** No source read states one. The provider writes the interrupt address, enable and force
  registers and the control page-size bit at attach, which shows nothing about reset state.
- **Field names exist in a shipped binary, positions not read.** The SAL runtime in the 4.43 and 5.04 PROM images carries a TIOCP attach routine
  and a register and field name pool with a `TIO_CP_` prefix (about 180 names; established as strings, 5.04 image checked). It names fields
  the Linux header does not: in the control register `NS`, `RO`, `BUS_NUM`, `DEV_NUM`, `FUN_NUM`, three parity enables, `RST_PIN_N`, `MEM_SWAP`,
  `PAGE_SIZE`, `CRED_LIMIT` and `SYS_END`; in each device register `EN_ERROR_LOCK`, `EN_PAGE_CHK`, `FORCE_PCI_PAR`, `EN_VIRTUAL`, `DIR_WRT_GEN`,
  `DEV_SIZE`, `REAL_TIME`, `SWAP_DIRECT`, `PREFETCH`, `PRECISE`, `BARRIER`, `CTALK_ARB`, `DEV_SWAP`, `DEV_IO_MEM` and `DEV_OFF`; and a
  status register with `TX_REQ_CREDIT_CNT`, `TX_RSP_CREDIT_CNT`, `PCI_X_SPEED`, `PCI_X_ACTIVE`, `RX_REQ_CREDIT_CNT`. The names confirm the
  Linux bits (page size, swap direction, prefetch, precise, barrier). Where each field sits is **unknown**: no static pointer to the
  name pool was found in the image, so the decoder tables are built by code that was not read. Route: read the error decoder that formats
  `TIO_CP_CONTROL` and `TIO_CP_DEVICE_0` (Ghidra export of the 5.04 image; a function-finding pass is needed because the analysis did not
  create the TIOCP attach routine).

## Revision 1 and the flush read

Read in full from `sn_dma_flush` in `pcibr_dma.c` (v5.3; the same test is in v2.6.14, v2.6.18 and v2.6.33).

- The routine runs after a programmed-I/O read to a device behind a bridge. For a TIO node (odd NASID) it reads the **TIO's own** node
  identification register, not the bridge's `+0x0`, takes revision from bits 31:28, and **returns at once when the revision is 1**. On any other
  revision it reads the per-device write request flush register for the device's slot (`slot - 1`). On a SHub node (PIC) it uses the forced-interrupt
  loop instead.
- So on revision 1 the kernel gives the programmed-I/O read no ordering against earlier DMA at all. The kernel's comment calls it a bring-up
  workaround and the header comment says not to write the register; the code skips a read. **Established** as the kernel's behaviour.
- What the hardware does on revision 1 when the register is read (hang, wrong data, no ordering) is **unknown**; no source says. Settling it
  needs the erratum text or a revision-1 board; neither is held.

## Which product carries a TIOCP

- **Part numbers (established as software expectation).** The 5.04 PROM's bridge classifier (Ghidra, `0xffab3f40`, read in full) reads the
  32-bit identification word, requires manufacturer 36 in bits 11:1, and returns bridge type 2 for parts `0xd102` and `0xd112` and **type 3 for parts
  `0xe000` and `0xe010`**. Linux numbers the PIC 2 and the TIOCP 3 and says its values "must agree with what prom thinks they are". With the IRIX
  accessors that makes `0xe000` and `0xe010` the TIOCP in every shipped reader. That the silicon part field holds those numbers is still no measurement.
  (The PROM page's earlier reading of `0xd112` as the TIOCP is wrong: `0xd112` is the second PIC head.)
- **Boards (inferred).** The PROM routine `tiocp_widget_to_bus` (Ghidra, `0xffb47210`, read in full) maps a TIO widget to a bus number from the L1
  module type: types 123, 102 and 108 take the base number, other types add twice the slab. In the PROM's brick-name table 102 is the Opus TIO brick and
  108 is on-board I/O; 123 is not in that table. The PIC attach routine, by contrast, accepts the IX-brick and PX-brick types. So a TIOCP sits on TIO-based I/O boards
  (the Opus TIO brick and on-board I/O), and the IX- and PX-bricks keep PICs. No guide read names the product, so the Altix model list stays **unknown**.
  The routine `tiocp_attach` itself was not found by the Ghidra analysis and is unread.

## Open

- Which Altix model carries a TIOCP. The Altix PROM attaches one (boards narrowed above); IRIX does not. A published hardware
  overview of the Altix-class generation would name the models ([question](../../questions/altix-io-sn2-cross-check.md#pic-versus-tio-by-product)).
- The `+0x14000` manual-parity translation RAM and the `+0x18000` and `+0x1c000` write-request and read-response RAMs
  exist only in the public header. No IRIX accessor reaches them. They are now named registers of the extra unit.

## Review

Independent review on 2026-11-14 by a reviewer who did not write these pages. Revisions: chips commits 4924130..b536f7d, read at main 15a5a4e484. Grading rule: the SN2 paragraph of the evidence order in `retools/tools/README-analysis.md` (SGI's Linux platform code ranks first for this generation, and a fact it defines is `established` as a software definition). Sources: the Linux v5.3 files the page cites, fetched singly from the tagged tree (`drivers/misc/ioc4.c` and `include/linux/ioc4.h` at v4.19, where they still exist).

**Reviewed commits.** b536f7d (tiocp), including its one-line change to `coverage.md`.

**Checked.** All 35 registers of `registers-extra.toml` against `struct tiocp`: offset, count and stride, exact (including the debug control registers 0x700 to 0x730, the manual-parity copy at 0x14000 and the read response RAM at 0x1c000, 0x1d000 and 0x1e000 with 512 entries). All 12 constants against `tiocp.h` and `pcibr_provider.h`. Every offset in the README's name paragraph against the struct, the PIC and TIOCP differences (seven type-0 windows from 0x21000, device windows 2n or n + 2, command type in bits 61:60, 54-bit interrupt address mask, no link-layer register), and the PV907516 read-ordering description against `sn_dma_flush`.

**Findings.**
- Judgement, left: the PV907516 constant and the page say the kernel must not read the per-device flush register on revision 1. The header comment says "do not write", the code skips a *read*, and the page already notes that what the hardware does on revision 1 is unknown. Read this as the kernel's behaviour, not a hardware rule.
- Judgement, left: the one-line change in `coverage.md` says the v5.3 `tiocp.h` and provider files "have the same layout" as the 2.6.33-era files read before. I confirmed the v5.3 layout and offsets against the census; I did not have the 2.6.33 tree and cannot confirm the equality claim itself. It changes the page's statement of what was read, not a register fact.
- The earlier TIOCP content (census registers, inferred grades) is unchanged apart from added citations and the two appended "Open" sentences.

**Cleared scope.** The extra unit's registers and constants and the README's Altix section. Not cleared: the coverage statement above, TIOCP revision behaviour, and which product carries a TIOCP.
