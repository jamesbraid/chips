<!-- generated from devices/tioca/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 2b0f87fc2049e975dc7d32a6177c47d984f40da6459eabf218c44e458d55da3a -->

# TIOCA (TIO AGP bridge), as SGI's Linux Altix platform code defines it

Names, offsets and bit fields are the definitions of SGI's Linux Altix platform code (header, AGP and PCI provider, v5.3). The TIOCA's own register specification is not held. The header gives no access direction and no reset value for any register. Each row states its access and the grade of that reading from what the provider does; no reset value is known.

Unit `tioca`, macro prefix `TIOCA`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `id` | 0x0 | r | 64 |  |  | unknown | established |  |
| `control1` | 0x8 | rw | 64 |  |  | unknown | established |  |
| `control2` | 0x10 | rw | 64 |  |  | unknown | established |  |
| `status1` | 0x18 | r | 64 |  |  | unknown | established |  |
| `status2` | 0x20 | r | 64 |  |  | unknown | established |  |
| `gart_aperature` | 0x28 | rw | 64 |  |  | unknown | established |  |
| `gfx_detach` | 0x30 | rw | 64 |  |  | unknown | established |  |
| `inta_dest_addr` | 0x38 | rw | 64 |  |  | unknown | established |  |
| `intb_dest_addr` | 0x40 | rw | 64 |  |  | unknown | established |  |
| `err_int_dest_addr` | 0x48 | rw | 64 |  |  | unknown | established |  |
| `int_status` | 0x50 | rw | 64 |  |  | unknown | established |  |
| `int_status_alias` | 0x58 | rw | 64 |  |  | unknown | established |  |
| `mult_error` | 0x60 | rw | 64 |  |  | unknown | established |  |
| `mult_error_alias` | 0x68 | rw | 64 |  |  | unknown | established |  |
| `first_error` | 0x70 | rw | 64 |  |  | unknown | established |  |
| `int_mask` | 0x78 | rw | 64 |  |  | unknown | established |  |
| `crm_pkterr_type` | 0x80 | rw | 64 |  |  | unknown | established |  |
| `crm_pkterr_type_alias` | 0x88 | rw | 64 |  |  | unknown | established |  |
| `crm_ct_error_detail_1` | 0x90 | rw | 64 |  |  | unknown | established |  |
| `crm_ct_error_detail_2` | 0x98 | rw | 64 |  |  | unknown | established |  |
| `crm_tnumto` | 0xa0 | rw | 64 |  |  | unknown | established |  |
| `gart_err` | 0xa8 | rw | 64 |  |  | unknown | established |  |
| `pcierr_type` | 0xb0 | rw | 64 |  |  | unknown | established |  |
| `pcierr_addr` | 0xb8 | rw | 64 |  |  | unknown | established |  |
| `pci_rd_buf_flush` | 0xd8 | rw | 64 |  |  | unknown | established |  |
| `pci_dma_addr_extn` | 0xe0 | rw | 64 |  |  | unknown | established |  |
| `agp_dma_addr_extn` | 0xe8 | rw | 64 |  |  | unknown | established |  |
| `force_inta` | 0xf0 | rw | 64 |  |  | unknown | established |  |
| `force_intb` | 0xf8 | rw | 64 |  |  | unknown | established |  |
| `debug_vector_sel` | 0x100 | rw | 64 |  |  | unknown | established |  |
| `debug_mux_core_sel` | 0x108 | rw | 64 |  |  | unknown | established |  |
| `debug_mux_pci_sel` | 0x110 | rw | 64 |  |  | unknown | established |  |
| `debug_domain_sel` | 0x118 | rw | 64 |  |  | unknown | established |  |
| `gart_ptr_table` | 0x200 | rw | 64 |  |  | unknown | established |  |
| `gart_tlb_addr` | 0x208 | rw | 64 | 8 |  | unknown | established |  |

### Register `id`

Widget identification word (part 0xe020, manufacturer 0x24, revision A = 1 per the header constants). The kernel keeps the revision the firmware reports in the bus record, not a value read here, and uses it to select four workarounds named in the provider header. Name and offset are the vendor header's definition (struct member ca_id). Access r: inferred from the name and role (an identification word); no code reads or writes it, since the kernel takes the revision from the firmware's bus record. Reset value unknown: the header and provider state none, and no firmware reading has been done.

### Register `control1`

Control 1. The provider sets bit 42 (AGP DMA operation combining delay enable; a provider comment ties it to PV895469 with a question mark) when it initialises the GART, and sets bit 6 (AGP fast write enable) when every function on the bus supports fast writes. Everything else is untouched. Name and offset are the vendor header's definition (struct member ca_control1). Access rw: established as a software expectation, because the provider changes single bits by reading the register back and writing it (read-modify-write). Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 51:44 | `pci_int_lpcnt` | established |  |  |  |
| 42 | `agpdma_op_enb_combdelay` | established |  |  |  |
| 40:36 | `agpdma_op_combdelay` | established |  |  |  |
| 31:24 | `pio_addr_offset` | established |  |  |  |
| 19 | `pcim_fast_btb_enb` | established |  |  |  |
| 18:16 | `pcim_io_nbe_ad` | established |  |  |  |
| 13 | `inj_data_perr` | established |  |  |  |
| 12 | `inj_addr_perr` | established |  |  |  |
| 11 | `agp_init_cal_enb` | established |  |  |  |
| 10 | `agp_cal_prscl_byp` | established |  |  |  |
| 9:7 | `agp_cal_cycle` | established |  |  |  |
| 6 | `agp_fw_enable` | established |  |  |  |
| 5 | `gfx_wr_swap` | established |  |  |  |
| 4 | `pio_mem_swap` | established |  |  |  |
| 3 | `pio_io_swap` | established |  |  |  |
| 2 | `dma_pci_swap` | established |  |  |  |
| 1 | `dma_agp_swap` | established |  |  |  |
| 0 | `sys_big_end` | established |  |  |  |

### Register `control2`

Control 2. The provider programs GART memory parameter 2 (cached, coherent GART table), clears both GART prefetch enables, and sets the GART TLB flush bit (36) to flush explicitly. On revision A hardware it pulses the flush with the memory parameter cleared first (PV910244: the flush is ignored while the table is cached), then restores the parameter. Name and offset are the vendor header's definition (struct member ca_control2). Access rw: established as a software expectation, because the provider changes single bits by reading the register back and writing it (read-modify-write). The flush bit is read back after setting. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `crm_max_credit` | established |  |  |  |
| 57 | `crm_prescaler_byp` | established |  |  |  |
| 56 | `crm_tnumto_enb` | established |  |  |  |
| 52:40 | `crm_tnumto_period` | established |  |  |  |
| 36 | `gart_flush_tlb` | established |  |  |  |
| 35 | `gart_wr_prefetch_enb` | established |  |  |  |
| 34 | `gart_rd_prefetch_enb` | established |  |  |  |
| 33:32 | `gart_mem_param` | established |  |  |  |
| 31 | `pci_arb_err_enb` | established |  |  |  |
| 30 | `msi_int_enb` | established |  |  |  |
| 29:28 | `rt_int_en` | established |  |  |  |
| 25:16 | `pci_max_retry` | established |  |  |  |
| 15:8 | `pci_latency_to` | established |  |  |  |
| 7:0 | `agp_latency_to` | established |  |  |  |

### Register `status1`

Name and offset are the vendor header's definition (struct member ca_status1). Access r: inferred from the name (a status word); the code read never touches it. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:16 | `gart_tlb_val` | established |  |  |  |
| 14:8 | `crm_space_avail` | established |  |  |  |
| 6:4 | `crm_credit_avail` | established |  |  |  |
| 3 | `intb_n` | established |  |  |  |
| 2 | `inta_n` | established |  |  |  |
| 1:0 | `corelet_id` | established |  |  |  |

### Register `status2`

Name and offset are the vendor header's definition (struct member ca_status2). Access r: inferred from the name (a status word); the code read never touches it. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 57:56 | `pdma_rdbuff_avail` | established |  |  |  |
| 55:52 | `pdma_wrbuff_avail` | established |  |  |  |
| 51:48 | `pdma_opq_avail` | established |  |  |  |
| 47 | `pci_pio_op_stat` | established |  |  |  |
| 46:40 | `adma_rdbuff_avail` | established |  |  |  |
| 39:32 | `adma_wrbuff_avail` | established |  |  |  |
| 31:24 | `adma_opq_avail` | established |  |  |  |
| 23:16 | `gfx_wrbuff_avail` | established |  |  |  |
| 15:8 | `gfx_opq_avail` | established |  |  |  |
| 7:0 | `gfx_credit_avail` | established |  |  |  |

### Register `gart_aperature`

GART aperture. The provider writes size, page-size and enable bits plus the bus base in one 64-bit store: size field 0x3ff for 4 MiB, one bit fewer set per doubling down to 0x000 for 4 GiB (the field is the complement of the size in 4 MiB units); bit 1 set when the kernel page is 16 KiB; enable bits 0 (AGP) and 2 (PCI); the bus base ORed in unshifted (the base field starts at bit 22, and the base 0x80000000 falls inside it). The name is spelled aperature in the header. Name and offset are the vendor header's definition (struct member ca_gart_aperature). Software only writes it (one 64-bit store, last in GART setup, after the table is built). Writability: established. Readability and any bit that reads back differently: unknown, so rw stays as the widest access. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:22 | `gart_ap_base` | established |  |  |  |
| 21:12 | `gart_ap_size` | established |  |  |  |
| 2 | `gart_ap_enb_pci` | established |  |  |  |
| 1 | `gart_page_size` | established |  |  |  |
| 0 | `gart_ap_enb_agp` | established |  |  |  |

### Register `gfx_detach`

Name and offset are the vendor header's definition (struct member ca_gfx_detach). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

### Register `inta_dest_addr`

Name and offset are the vendor header's definition (struct member ca_inta_dest_addr). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `int_dest_vect` | established |  |  |  |
| 53:3 | `int_dest_addr` | established |  |  |  |

### Register `intb_dest_addr`

Name and offset are the vendor header's definition (struct member ca_intb_dest_addr). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `int_dest_vect` | established |  |  |  |
| 53:3 | `int_dest_addr` | established |  |  |  |

### Register `err_int_dest_addr`

Name and offset are the vendor header's definition (struct member ca_err_int_dest_addr). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63:56 | `int_dest_vect` | established |  |  |  |
| 53:3 | `int_dest_addr` | established |  |  |  |

### Register `int_status`

Name and offset are the vendor header's definition (struct member ca_int_status). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21 | `gfx_credit_ovflw` | established |  |  |  |
| 20 | `mult_intb` | established |  |  |  |
| 19 | `mult_inta` | established |  |  |  |
| 18 | `intb` | established |  |  |  |
| 17 | `inta` | established |  |  |  |
| 15 | `sba_type1_err` | established |  |  |  |
| 14 | `agp_req_oflow` | established |  |  |  |
| 13 | `pci_arb_to` | established |  |  |  |
| 12 | `pio_invalid_addr` | established |  |  |  |
| 11 | `cxm_req_cred_ovflw` | established |  |  |  |
| 10 | `cxm_rsp_cred_ovflw` | established |  |  |  |
| 9 | `tnumto` | established |  |  |  |
| 8 | `crm_dverr` | established |  |  |  |
| 7 | `crm_pkterr` | established |  |  |  |
| 6 | `pio_req_ovflw` | established |  |  |  |
| 5 | `gfx_wr_ovflw` | established |  |  |  |
| 4 | `gart_fetch_err` | established |  |  |  |
| 0 | `pci_err` | established |  |  |  |

### Register `int_status_alias`

Interrupt status write alias. The provider writes the GART fetch error bit here to clear it (the alias is the write-to-clear form of ca_int_status; the name says alias, the clear role is the provider's use). Name and offset are the vendor header's definition (struct member ca_int_status_alias). The provider writes the single bit it wants cleared to this register to drop residual GART fetch errors before unmasking. That a written 1 clears the matching status bit is inferred from the provider's own comment (clear residual errors first); readability is unknown, so rw stays as the widest access. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21 | `gfx_credit_ovflw` | established |  |  |  |
| 20 | `mult_intb` | established |  |  |  |
| 19 | `mult_inta` | established |  |  |  |
| 18 | `intb` | established |  |  |  |
| 17 | `inta` | established |  |  |  |
| 15 | `sba_type1_err` | established |  |  |  |
| 14 | `agp_req_oflow` | established |  |  |  |
| 13 | `pci_arb_to` | established |  |  |  |
| 12 | `pio_invalid_addr` | established |  |  |  |
| 11 | `cxm_req_cred_ovflw` | established |  |  |  |
| 10 | `cxm_rsp_cred_ovflw` | established |  |  |  |
| 9 | `tnumto` | established |  |  |  |
| 8 | `crm_dverr` | established |  |  |  |
| 7 | `crm_pkterr` | established |  |  |  |
| 6 | `pio_req_ovflw` | established |  |  |  |
| 5 | `gfx_wr_ovflw` | established |  |  |  |
| 4 | `gart_fetch_err` | established |  |  |  |
| 0 | `pci_err` | established |  |  |  |

### Register `mult_error`

Name and offset are the vendor header's definition (struct member ca_mult_error). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21 | `gfx_credit_ovflw` | established |  |  |  |
| 20 | `mult_intb` | established |  |  |  |
| 19 | `mult_inta` | established |  |  |  |
| 18 | `intb` | established |  |  |  |
| 17 | `inta` | established |  |  |  |
| 15 | `sba_type1_err` | established |  |  |  |
| 14 | `agp_req_oflow` | established |  |  |  |
| 13 | `pci_arb_to` | established |  |  |  |
| 12 | `pio_invalid_addr` | established |  |  |  |
| 11 | `cxm_req_cred_ovflw` | established |  |  |  |
| 10 | `cxm_rsp_cred_ovflw` | established |  |  |  |
| 9 | `tnumto` | established |  |  |  |
| 8 | `crm_dverr` | established |  |  |  |
| 7 | `crm_pkterr` | established |  |  |  |
| 6 | `pio_req_ovflw` | established |  |  |  |
| 5 | `gfx_wr_ovflw` | established |  |  |  |
| 4 | `gart_fetch_err` | established |  |  |  |
| 0 | `pci_err` | established |  |  |  |

### Register `mult_error_alias`

Multiple-error write alias. The provider writes the GART fetch error bit here to clear it, together with the status alias. Name and offset are the vendor header's definition (struct member ca_mult_error_alias). The provider writes the single bit it wants cleared here beside the status alias write. That a written 1 clears the bit in the multiple-error register is inferred from the provider's comment; readability is unknown, so rw stays as the widest access. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21 | `gfx_credit_ovflw` | established |  |  |  |
| 20 | `mult_intb` | established |  |  |  |
| 19 | `mult_inta` | established |  |  |  |
| 18 | `intb` | established |  |  |  |
| 17 | `inta` | established |  |  |  |
| 15 | `sba_type1_err` | established |  |  |  |
| 14 | `agp_req_oflow` | established |  |  |  |
| 13 | `pci_arb_to` | established |  |  |  |
| 12 | `pio_invalid_addr` | established |  |  |  |
| 11 | `cxm_req_cred_ovflw` | established |  |  |  |
| 10 | `cxm_rsp_cred_ovflw` | established |  |  |  |
| 9 | `tnumto` | established |  |  |  |
| 8 | `crm_dverr` | established |  |  |  |
| 7 | `crm_pkterr` | established |  |  |  |
| 6 | `pio_req_ovflw` | established |  |  |  |
| 5 | `gfx_wr_ovflw` | established |  |  |  |
| 4 | `gart_fetch_err` | established |  |  |  |
| 0 | `pci_err` | established |  |  |  |

### Register `first_error`

Name and offset are the vendor header's definition (struct member ca_first_error). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21 | `gfx_credit_ovflw` | established |  |  |  |
| 20 | `mult_intb` | established |  |  |  |
| 19 | `mult_inta` | established |  |  |  |
| 18 | `intb` | established |  |  |  |
| 17 | `inta` | established |  |  |  |
| 15 | `sba_type1_err` | established |  |  |  |
| 14 | `agp_req_oflow` | established |  |  |  |
| 13 | `pci_arb_to` | established |  |  |  |
| 12 | `pio_invalid_addr` | established |  |  |  |
| 11 | `cxm_req_cred_ovflw` | established |  |  |  |
| 10 | `cxm_rsp_cred_ovflw` | established |  |  |  |
| 9 | `tnumto` | established |  |  |  |
| 8 | `crm_dverr` | established |  |  |  |
| 7 | `crm_pkterr` | established |  |  |  |
| 6 | `pio_req_ovflw` | established |  |  |  |
| 5 | `gfx_wr_ovflw` | established |  |  |  |
| 4 | `gart_fetch_err` | established |  |  |  |
| 0 | `pci_err` | established |  |  |  |

### Register `int_mask`

Interrupt mask. The provider clears the GART fetch error bit (enables it); the sense of the mask bit is the provider's use. Name and offset are the vendor header's definition (struct member ca_int_mask). Access rw: established as a software expectation (read-modify-write). The provider clears the GART fetch error bit to unmask it, so a set bit masks the interrupt: inferred from the unmask comment. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21 | `gfx_credit_ovflw` | established |  |  |  |
| 20 | `mult_intb` | established |  |  |  |
| 19 | `mult_inta` | established |  |  |  |
| 18 | `intb` | established |  |  |  |
| 17 | `inta` | established |  |  |  |
| 15 | `sba_type1_err` | established |  |  |  |
| 14 | `agp_req_oflow` | established |  |  |  |
| 13 | `pci_arb_to` | established |  |  |  |
| 12 | `pio_invalid_addr` | established |  |  |  |
| 11 | `cxm_req_cred_ovflw` | established |  |  |  |
| 10 | `cxm_rsp_cred_ovflw` | established |  |  |  |
| 9 | `tnumto` | established |  |  |  |
| 8 | `crm_dverr` | established |  |  |  |
| 7 | `crm_pkterr` | established |  |  |  |
| 6 | `pio_req_ovflw` | established |  |  |  |
| 5 | `gfx_wr_ovflw` | established |  |  |  |
| 4 | `gart_fetch_err` | established |  |  |  |
| 0 | `pci_err` | established |  |  |  |

### Register `crm_pkterr_type`

Name and offset are the vendor header's definition (struct member ca_crm_pkterr_type). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 28 | `first_crm_pkterr_mssng_hdr` | established |  |  |  |
| 27 | `first_crm_pkterr_mssng_tail` | established |  |  |  |
| 26 | `first_crm_pkterr_early_tail` | established |  |  |  |
| 25 | `first_crm_pkterr_early_term` | established |  |  |  |
| 24 | `first_crm_pkterr_sberr_nh` | established |  |  |  |
| 23 | `first_crm_pkterr_cw_err` | established |  |  |  |
| 22 | `first_crm_pkterr_hdr_param` | established |  |  |  |
| 21 | `first_crm_pkterr_addr_algn` | established |  |  |  |
| 20 | `first_crm_pkterr_addr_rng` | established |  |  |  |
| 19 | `first_crm_pkterr_inv_tnum` | established |  |  |  |
| 18 | `first_crm_pkterr_pactype` | established |  |  |  |
| 17 | `first_crm_pkterr_didn` | established |  |  |  |
| 16 | `first_crm_pkterr_sberr_hdr` | established |  |  |  |
| 12 | `crm_pkterr_mssng_hdr` | established |  |  |  |
| 11 | `crm_pkterr_mssng_tail` | established |  |  |  |
| 10 | `crm_pkterr_early_tail` | established |  |  |  |
| 9 | `crm_pkterr_early_term` | established |  |  |  |
| 8 | `crm_pkterr_sberr_nh` | established |  |  |  |
| 7 | `crm_pkterr_cw_err` | established |  |  |  |
| 6 | `crm_pkterr_hdr_param` | established |  |  |  |
| 5 | `crm_pkterr_addr_algn` | established |  |  |  |
| 4 | `crm_pkterr_addr_rng` | established |  |  |  |
| 3 | `crm_pkterr_inv_tnum` | established |  |  |  |
| 2 | `crm_pkterr_pactype` | established |  |  |  |
| 1 | `crm_pkterr_didn` | established |  |  |  |
| 0 | `crm_pkterr_sberr_hdr` | established |  |  |  |

### Register `crm_pkterr_type_alias`

Name and offset are the vendor header's definition (struct member ca_crm_pkterr_type_alias). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 28 | `first_crm_pkterr_mssng_hdr` | established |  |  |  |
| 27 | `first_crm_pkterr_mssng_tail` | established |  |  |  |
| 26 | `first_crm_pkterr_early_tail` | established |  |  |  |
| 25 | `first_crm_pkterr_early_term` | established |  |  |  |
| 24 | `first_crm_pkterr_sberr_nh` | established |  |  |  |
| 23 | `first_crm_pkterr_cw_err` | established |  |  |  |
| 22 | `first_crm_pkterr_hdr_param` | established |  |  |  |
| 21 | `first_crm_pkterr_addr_algn` | established |  |  |  |
| 20 | `first_crm_pkterr_addr_rng` | established |  |  |  |
| 19 | `first_crm_pkterr_inv_tnum` | established |  |  |  |
| 18 | `first_crm_pkterr_pactype` | established |  |  |  |
| 17 | `first_crm_pkterr_didn` | established |  |  |  |
| 16 | `first_crm_pkterr_sberr_hdr` | established |  |  |  |
| 12 | `crm_pkterr_mssng_hdr` | established |  |  |  |
| 11 | `crm_pkterr_mssng_tail` | established |  |  |  |
| 10 | `crm_pkterr_early_tail` | established |  |  |  |
| 9 | `crm_pkterr_early_term` | established |  |  |  |
| 8 | `crm_pkterr_sberr_nh` | established |  |  |  |
| 7 | `crm_pkterr_cw_err` | established |  |  |  |
| 6 | `crm_pkterr_hdr_param` | established |  |  |  |
| 5 | `crm_pkterr_addr_algn` | established |  |  |  |
| 4 | `crm_pkterr_addr_rng` | established |  |  |  |
| 3 | `crm_pkterr_inv_tnum` | established |  |  |  |
| 2 | `crm_pkterr_pactype` | established |  |  |  |
| 1 | `crm_pkterr_didn` | established |  |  |  |
| 0 | `crm_pkterr_sberr_hdr` | established |  |  |  |

### Register `crm_ct_error_detail_1`

Name and offset are the vendor header's definition (struct member ca_crm_ct_error_detail_1). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `valid` | established |  |  |  |
| 35 | `cw_err` | established |  |  |  |
| 34 | `pio_op` | established |  |  |  |
| 33:32 | `mem_rd_param` | established |  |  |  |
| 31:24 | `gfx_cred` | established |  |  |  |
| 23:16 | `dw_data_en` | established |  |  |  |
| 15:8 | `tnum` | established |  |  |  |
| 7:6 | `data_sz` | established |  |  |  |
| 5:4 | `src_id` | established |  |  |  |
| 3:0 | `pkt_type` | established |  |  |  |

### Register `crm_ct_error_detail_2`

Name and offset are the vendor header's definition (struct member ca_crm_ct_error_detail_2). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:3 | `pkt_addr` | established |  |  |  |

### Register `crm_tnumto`

Name and offset are the vendor header's definition (struct member ca_crm_tnumto). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `crm_tnumto_wr` | established |  |  |  |
| 7:0 | `crm_tnumto_val` | established |  |  |  |

### Register `gart_err`

Name and offset are the vendor header's definition (struct member ca_gart_err). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 39:4 | `gart_err_addr` | established |  |  |  |
| 1:0 | `gart_err_source` | established |  |  |  |

### Register `pcierr_type`

Name and offset are the vendor header's definition (struct member ca_pcierr_type). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 49 | `pcierr_mst_retry_tout` | established |  |  |  |
| 48 | `pcierr_mst_tabt` | established |  |  |  |
| 47 | `pcierr_mst_mabt` | established |  |  |  |
| 46 | `pcierr_mst_rd_perr` | established |  |  |  |
| 45 | `pcierr_mst_wr_perr` | established |  |  |  |
| 44 | `pcierr_mst_serr` | established |  |  |  |
| 43 | `pcierr_slv_rd_perr` | established |  |  |  |
| 42 | `pcierr_slv_wr_perr` | established |  |  |  |
| 41 | `pcierr_slv_serr` | established |  |  |  |
| 40 | `pcierr_a64` | established |  |  |  |
| 39:36 | `pcierr_cmd` | established |  |  |  |
| 35:32 | `pcierr_enb` | established |  |  |  |
| 31:0 | `pcierr_data` | established |  |  |  |

### Register `pcierr_addr`

Name and offset are the vendor header's definition (struct member ca_pcierr_addr). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

### Register `pci_rd_buf_flush`

Name and offset are the vendor header's definition (struct member ca_pci_rd_buf_flush). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

### Register `pci_dma_addr_extn`

Name and offset are the vendor header's definition (struct member ca_pci_dma_addr_extn). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 28 | `pci_dma_pio_mem_type` | established |  |  |  |
| 27:12 | `pci_dma_node_id` | established |  |  |  |
| 9:8 | `chiplet_id` | established |  |  |  |
| 5:0 | `upper_node_offset` | established |  |  |  |

### Register `agp_dma_addr_extn`

AGP DMA address extension. The 48-bit direct AGP DMA path reads it and requires its node-id field to equal the upper node bits of the target; the node-id field is 16 bits wide at bit 20, which overlaps the pio-mem-type bit 28 the header also names (see the unit page). Name and offset are the vendor header's definition (struct member ca_agp_dma_addr_extn). The 48-bit direct AGP path reads it (established), so it is readable. Whether software or firmware writes it is not shown by the code read; rw stays as the widest access, write direction unknown. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 35:20 | `agp_dma_node_id` | established |  |  |  |

### Register `force_inta`

Name and offset are the vendor header's definition (struct member ca_force_inta). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

### Register `force_intb`

Name and offset are the vendor header's definition (struct member ca_force_intb). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

### Register `debug_vector_sel`

Name and offset are the vendor header's definition (struct member ca_debug_vector_sel). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 59:56 | `debug_pm_vsel` | established |  |  |  |
| 55:52 | `debug_ps_vsel` | established |  |  |  |
| 51:48 | `debug_as_vsel` | established |  |  |  |
| 47:44 | `debug_bi_vsel` | established |  |  |  |
| 43:40 | `debug_bo_vsel` | established |  |  |  |
| 39:36 | `debug_pe_vsel` | established |  |  |  |
| 35:32 | `debug_ba_vsel` | established |  |  |  |
| 31:28 | `debug_cr_vsel` | established |  |  |  |
| 27:24 | `debug_cx_vsel` | established |  |  |  |
| 23:20 | `debug_ad_vsel` | established |  |  |  |
| 19:16 | `debug_pd_vsel` | established |  |  |  |
| 15:12 | `debug_gt_vsel` | established |  |  |  |
| 11:8 | `debug_gw_vsel` | established |  |  |  |
| 7:4 | `debug_pp_vsel` | established |  |  |  |
| 3:0 | `debug_mn_vsel` | established |  |  |  |

### Register `debug_mux_core_sel`

Name and offset are the vendor header's definition (struct member ca_debug_mux_core_sel). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `debug_nsel7` | established |  |  |  |
| 58:56 | `debug_msel7` | established |  |  |  |
| 54:52 | `debug_nsel6` | established |  |  |  |
| 50:48 | `debug_msel6` | established |  |  |  |
| 46:44 | `debug_nsel5` | established |  |  |  |
| 42:40 | `debug_msel5` | established |  |  |  |
| 38:36 | `debug_nsel4` | established |  |  |  |
| 34:32 | `debug_msel4` | established |  |  |  |
| 30:28 | `debug_nsel3` | established |  |  |  |
| 26:24 | `debug_msel3` | established |  |  |  |
| 22:20 | `debug_nsel2` | established |  |  |  |
| 18:16 | `debug_msel2` | established |  |  |  |
| 14:12 | `debug_nsel1` | established |  |  |  |
| 10:8 | `debug_msel1` | established |  |  |  |
| 6:4 | `debug_nsel0` | established |  |  |  |
| 2:0 | `debug_msel0` | established |  |  |  |

### Register `debug_mux_pci_sel`

Name and offset are the vendor header's definition (struct member ca_debug_mux_pci_sel). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 62:60 | `debug_nsel7` | established |  |  |  |
| 58:56 | `debug_msel7` | established |  |  |  |
| 54:52 | `debug_nsel6` | established |  |  |  |
| 50:48 | `debug_msel6` | established |  |  |  |
| 46:44 | `debug_nsel5` | established |  |  |  |
| 42:40 | `debug_msel5` | established |  |  |  |
| 38:36 | `debug_nsel4` | established |  |  |  |
| 34:32 | `debug_msel4` | established |  |  |  |
| 30:28 | `debug_nsel3` | established |  |  |  |
| 26:24 | `debug_msel3` | established |  |  |  |
| 22:20 | `debug_nsel2` | established |  |  |  |
| 18:16 | `debug_msel2` | established |  |  |  |
| 14:12 | `debug_nsel1` | established |  |  |  |
| 10:8 | `debug_msel1` | established |  |  |  |
| 6:4 | `debug_nsel0` | established |  |  |  |
| 2:0 | `debug_msel0` | established |  |  |  |

### Register `debug_domain_sel`

Name and offset are the vendor header's definition (struct member ca_debug_domain_sel). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `debug_domain_h` | established |  |  |  |
| 0 | `debug_domain_l` | established |  |  |  |

### Register `gart_ptr_table`

GART table pointer. The provider stores the coretalk address of the page table ORed with 1 (bit 0 valid). Table entries are 8 bytes: the coretalk page address shifted right 12, with bit 63 set for valid. Name and offset are the vendor header's definition (struct member ca_gart_ptr_table). Software only writes it (the table's coretalk address ORed with 1, last store of GART setup). Writability: established. Readability: unknown, so rw stays as the widest access. Reset value unknown: the header and provider state none, and no firmware reading has been done.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 55:12 | `gart_ptr_addr` | established |  |  |  |
| 0 | `gart_ptr_val` | established |  |  |  |

### Register `gart_tlb_addr`

Name and offset are the vendor header's definition (struct member ca_gart_tlb_addr). Software never touches this register in the code read, so access direction is unknown and rw is a placeholder. Reset value unknown: the header and provider state none, and no firmware reading has been done.

Array of 8 registers, stride 8.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 63 | `gart_tlb_entry_val` | established |  |  |  |
| 55:0 | `gart_tlb_addr` | established |  |  |  |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `AGP_DIRECT_BASE` | 0x40000000 | established |  | Start of the 48-bit AGP direct window, up to 0xffffffffffff. Direct DMA below this base is PIO space. |
| `AGP_DMA_PIO_MEM_TYPE` | 0x10000000 | established |  | Bit 28 of the AGP DMA address extension, named PIO memory type. It overlaps the 16-bit node-id field the header places at bit 20; the header comment says bits 27:26 are unused. |
| `AGP_MAPPED_BASE` | 0x80000000 | established |  | Start of the graphics aperture, the part of the GART the AGP driver owns; also the base of the whole aperture. |
| `AGP_MAPPED_SIZE` | 0x40000000 | established |  | Size of the graphics aperture, 1 GiB. Aperture total is 2 GiB. |
| `DIRECT64_COHERENT` | 0x1000000000000000 | established |  | Packet type 1 (coherent memory get and put) in bits 63:60 of a 64-bit direct DMA address. Type 2 would be non-coherent PIO; the provider always uses 1. Bits 53:0 are the coretalk address. |
| `ERROR_VECTOR` | 0x35 | established |  | Kernel interrupt vector of the TIOCA error interrupt. The handler makes one firmware call and does not read TIOCA registers. |
| `GART_ENTRY_VALID` | 0x8000000000000000 | established |  | Bit 63 of a GART entry: valid. The rest is the coretalk page address shifted right 12. |
| `PART_NUMBER` | 0xe020 | established |  | Widget part number of the TIOCA. Manufacturer number 0x24, revision A is 1. |
| `PCI32_DIRECT_BASE` | 0xc0000000 | established |  | Start of the 32-bit direct DMA window. The provider sets its size to zero, so the window is unused: the header says an addressing flaw makes 32-bit direct DMA unusable below 3 GiB, and all 32-bit DMA goes through the GART. |
| `PCI32_MAPPED_BASE` | 0xc0000000 | established |  | Start of the PCI 32-bit GART-mapped window (the upper half of the aperture). |
| `PCI32_MAPPED_SIZE` | 0x40000000 | established |  | Size of the PCI GART-mapped window, 1 GiB (the header comment says 2 GB). |
| `PCI_DMA_PIO_MEM_TYPE` | 0x10000000 | established |  | Bit 28 of the PCI DMA address extension, named PIO memory type. |
| `PIO_ADMIN` | 0x0 | established |  | PIO window of the internal registers, 64 KiB. |
| `PIO_AGP_DMAREAD` | 0x30000 | established |  | AGP DMA read buffer, diagnostics, 64 KiB. |
| `PIO_AGP_DMAWRITE` | 0x20000 | established |  | AGP DMA write buffer, diagnostics, 64 KiB. |
| `PIO_GFX` | 0x10000 | established |  | Graphics write buffer, diagnostics, 64 KiB. |
| `PIO_PCI_IO` | 0x3000000 | established |  | PCI I/O cycles, mapped to PCI addresses 0 to 0x04ffffff. |
| `PIO_PCI_MEM` | 0x40000000 | established |  | PCI memory cycles mapped to PCI addresses 0 to 0xbfffffff. |
| `PIO_PCI_MEM_OFFSET` | 0x8000000 | established |  | PCI memory cycles at the address offset held in the PIO address offset field of control 1. |
| `PIO_PCI_TYPE0_CONFIG` | 0x1000000 | established |  | PCI type 0 configuration window, 16 MiB. |
| `PIO_PCI_TYPE1_CONFIG` | 0x2000000 | established |  | PCI type 1 configuration window, 16 MiB. |
