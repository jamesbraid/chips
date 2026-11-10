# TIOCP coverage

What the shipped software and the public drivers settle about the TIOCP, the PCI-X bridge of the later (Altix-class)
SN generation. Register-level facts live on [the chip page](../chips/tiocp/README.md); this page grades each coverage
question and says what would settle the rest. Labels follow [AGENTS.md](../AGENTS.md): **established**, **inferred**,
**unknown**.

Sources read for this page: IRIX 6.5.30 IP35 `pcibr.o` (the shared Bridge-family accessors, read in full where cited),
the IRIX 6.5.30 IP35 `space.o` debug types, and the public Linux ia64 SN code of the 2.6.33 era
(`arch/ia64/include/asm/sn/tiocp.h`, `pic.h`, `pcibr_provider.h`, `pcibus_provider_defs.h`;
`arch/ia64/sn/pci/pcibr/pcibr_reg.c`, `pcibr_dma.c`), read from a history tree (merge commit `981a2edd1922`,
2010-01-27). The pinned v5.3 tree of [docs/sources/INDEX.md](sources/INDEX.md) was not read.

## Which product carries a TIOCP

- **No IRIX product in scope carries one: inferred.** The IP27 and IP35 boot sets hold no TIO routine (only the two
  debug-table names the chip page records), no attach path that names the chip, and no register access outside the
  shared accessors that only a TIOCP could make. The shared accessors carry the TIOCP branch because the same object is shared with a
  later platform, not because the Origin or Onyx machines have the chip. Nothing in the 6.5.30 media instantiates it.
- **The public Linux SN code attaches TIOCP buses behind a TIO node: established** (`sn_dma_flush` in `pcibr_dma.c`
  treats an odd node number as a TIO node, and the `IS_PCI_BRIDGE_ASIC` test accepts exactly the PIC and the TIOCP as the
  platform's PCI bridges).
  The Linux source does not name the products. Which shipped systems have a TIO is **unknown**; it needs a published
  hardware overview of that generation. The IRIX 6.5.30 media cannot settle it.

## Identification

- **Part numbers `0xe000` and `0xe010`, manufacturer 36 (`0x24`): established** as what IRIX's raw-pointer accessors
  accept for the fourth chip (`pcireg_llp_cfg_get`, `pcibr.o` `0x10bb4`, and `pcireg_ext_ate_get`, `0x18c20`, both read
  in full). The Linux files read name no part number for the TIOCP bridge itself; they name the TIO widgets of the
  same family (`0xe020` for the TIOCA, `0xce00` for the TIOCE). So `0xe000` and `0xe010` as "TIOCP" rest on the IRIX
  accessors alone: **inferred**, from the accessor treating them as chip type 3 everywhere else.
- **Two unrelated numberings, do not conflate: established.** IRIX's `pciio_asic_type_e` (UNKNOWN 0, MACE 1, BRIDGE 2,
  XBRIDGE 3, PIC 4, TIOCP 5) and the halfword at bridge record +114 (0 Bridge, 1 XBridge, 2 PIC, 3 TIOCP) are IRIX
  software choices. Linux's `PCIIO_ASIC_TYPE_*` (UNKNOWN 0, PPB 1, PIC 2, TIOCP 3, TIOCA 4, TIOCE 5) is a third
  software numbering. None of them is a register value.

## Register layout

The census of the shared accessors reaches 43 TIOCP offsets (163 sites). Every one has a named register at the same
offset in the public Linux `struct tiocp`, except `+0x80000`:

| IRIX offset (accessor name) | Linux register | result |
|---|---|---|
| `+0x0` id, `+0x18` bus error, `+0x20` control, `+0x28` request timeout, `+0x38` interrupt destination, `+0x40` error command word, `+0x50` target flush | `cp_id`, `cp_err_lower`, `cp_control`, `cp_req_timeout`, `cp_intr_lower`, `cp_err_cmdword`, `cp_tflush` | agree |
| `+0x58` to `+0x78` (aux error, response, address-lock error) | `cp_aux_err`, `cp_resp_upper`, `cp_resp_lower`, `cp_addr_lkerr` | agree |
| `+0x80`, `+0x90`, `+0xa0`, `+0xb0`, `+0xc0`, `+0xc8`, `+0xd8` | `cp_dir_map`, `cp_map_fault`, `cp_arb`, `cp_ate_parity_err`, `cp_bus_timeout`, `cp_pci_cfg`, `cp_pci_err_lower` | agree |
| `+0x100` to `+0x128`, `+0x130` family, `+0x170`, `+0x178`, `+0x180` family, `+0x1c0` family | interrupt status, enable, reset status, mode, device, host error, address family, error view, multiple-interrupt, force-always, force-pin | agree |
| `+0x200` family, `+0x240` family, `+0x280` family, `+0x290`, `+0x298` | device, write request buffer flush, read response buffer map, response status, response clear | agree |
| `+0x600` to `+0x630` (PCI-X bus error and split registers) | `cp_pcix_*` | agree |
| `+0x10000` family | `cp_int_ate_ram` | agree |
| `+0x80000` family (external translation RAM) | none | **conflict, resolved below** |

Agreement by offset between a software accessor and a driver's header is two software readings meeting; it is
**inferred** for every row, never a hardware measurement, and fills no field.

### Two places where the shared code says the TIOCP differs from PIC (both established)

- **Register `+0x48` (link-layer control on the other chips) does not exist.** `pcireg_llp_cfg_get` (`pcibr.o`
  `0x10bb4`, read in full) branches on the record's chip type or the raw part number. A record of type 3 reaches the
  `panic` call at `0x10d18`; so does a raw pointer with part `0xe000` or `0xe010` and manufacturer 36. The message
  string it passes (`.rodata` offset 13872) reads "pcireg_llp_cfg_get(): undefined register". The other panic in the
  routine, at `0x10d04`, is the "unknown bridgetype" one. The public `struct tiocp` independently leaves `+0x48` as
  padding where the PIC structure has its link-layer register. Two independent sources agree the register is absent.
  The census has no TIOCP row at `+0x48`, which agrees. `pcireg_llp_cfg_set` was not read separately.
- **No external translation RAM.** `pcireg_ext_ate_get` (`pcibr.o` `0x18c20`, read in full) takes the real read path only
  for record type 0 (the Bridge); types 1, 2 and 3 and the raw TIOCP part numbers all reach the `panic` call whose
  string (`.rodata` offset 18640) reads "pcireg_ext_ate_get(): not a BRIDGE ASIC". The 6 TIOCP sites the census lists at
  `+0x80000` are therefore not accesses a TIOCP ever makes: they are the scanner crediting the panic-guarded read to the
  TIOCP variant. Treat that census row as a scanner artifact. The Linux structure has no `+0x80000` register either; it
  has internal translation RAM only, in two copies (`+0x10000` with automatic parity, `+0x14000` with manual parity).
  The `+0x14000` copy is in no IRIX accessor: **unknown** on the IRIX side, **established** as a public driver's
  structure.

### Facts the shipped code does not hold but the public driver states (all driver naming, none measured)

- The interrupt destination address is 54 bits wide on the TIOCP (`0x003fffffffffffff`), against 48 bits on the PIC
  (`0x0000ffffffffffff`) (`pcireg_intr_addr_addr_set`).
- A 64-bit DMA address carries the command type in bits 61:60 on the TIOCP: memory is 1, message-signalled interrupt
  is 3 (`TIOCP_PCI64_CMDTYPE_MEM`, `_MSI`).
- A translation entry used for an MSI mapping on the TIOCP also needs the entry's PIO bit set (`pcibr_dma.c`).
- Hardware erratum named in a Linux comment as PV907516: on the TIO revision whose revision field is 1, the
  per-device write-request flush register must not be touched. On other revisions the flush is a register read of
  `+0x240 + 8n`, and the comment says it ensures the data has entered the coherence domain, unlike the PIC's flush
  register, which does not. Established as a driver's statement; the silicon is unmeasured.

## What would settle the rest

| question | route | discriminating test |
|---|---|---|
| Which product has a TIOCP | a published hardware overview of the Altix-class generation | none in software |
| The `+0x14000` manual-parity ATE copy and the Linux-only `+0x18000` and `+0x1c000` RAMs | the v5.3 `tiocp.h` and an Altix PCI-X bridge datasheet | write a translation entry through `+0x10000` and through `+0x14000` with deliberately bad parity; only the second may report an ATE parity error through `+0xb0` |
| Whether a read of `+0x48` or `+0x80000` on a real TIOCP is benign | silicon only | read both with an error-capturing harness; IRIX never does, so no shipped software depends on the answer (valid end state: no software dependency) |
| Whether `0xe000` and `0xe010` are two revisions of one chip | a part-number list for the generation | read the identification word on both; compare the revision nibble |
