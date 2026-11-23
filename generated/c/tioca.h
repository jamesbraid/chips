/* generated from devices/tioca/registers.toml by defs-gen - do not edit, change
 * the source */
/* defs-gen 4 */
/* input sha256 2b0f87fc2049e975dc7d32a6177c47d984f40da6459eabf218c44e458d55da3a */
/* TIOCA (TIO AGP bridge), as SGI's Linux Altix platform code defines it */
#ifndef TIOCA_GEN_H
#define TIOCA_GEN_H

#include <stdint.h>


/*
 * Widget identification word (part 0xe020, manufacturer 0x24, revision A = 1
 * per the header constants). The kernel keeps the revision the firmware reports
 * in the bus record, not a value read here, and uses it to select four
 * workarounds named in the provider header. Name and offset are the vendor
 * header's definition (struct member ca_id). Access r: inferred from the name
 * and role (an identification word); no code reads or writes it, since the
 * kernel takes the revision from the firmware's bus record. Reset value
 * unknown: the header and provider state none, and no firmware reading has been
 * done.
 */
/* id: r64, reset unknown */
#define TIOCA_ID                                     0x000000 /* established */

/*
 * Control 1. The provider sets bit 42 (AGP DMA operation combining delay
 * enable; a provider comment ties it to PV895469 with a question mark) when it
 * initialises the GART, and sets bit 6 (AGP fast write enable) when every
 * function on the bus supports fast writes. Everything else is untouched. Name
 * and offset are the vendor header's definition (struct member ca_control1).
 * Access rw: established as a software expectation, because the provider
 * changes single bits by reading the register back and writing it
 * (read-modify-write). Reset value unknown: the header and provider state none,
 * and no firmware reading has been done.
 */
/* control1: rw64, reset unknown */
#define TIOCA_CONTROL1                               0x000008 /* established */
#define TIOCA_CONTROL1_PCI_INT_LPCNT_SHIFT           44 /* established */
#define TIOCA_CONTROL1_PCI_INT_LPCNT_MASK            0xffull
#define TIOCA_CONTROL1_PCI_INT_LPCNT_INPLACE (TIOCA_CONTROL1_PCI_INT_LPCNT_MASK << TIOCA_CONTROL1_PCI_INT_LPCNT_SHIFT)
#define TIOCA_CONTROL1_AGPDMA_OP_ENB_COMBDELAY_SHIFT 42 /* established */
#define TIOCA_CONTROL1_AGPDMA_OP_ENB_COMBDELAY_MASK  0x1ull
#define TIOCA_CONTROL1_AGPDMA_OP_ENB_COMBDELAY_INPLACE (TIOCA_CONTROL1_AGPDMA_OP_ENB_COMBDELAY_MASK << TIOCA_CONTROL1_AGPDMA_OP_ENB_COMBDELAY_SHIFT)
#define TIOCA_CONTROL1_AGPDMA_OP_COMBDELAY_SHIFT     36 /* established */
#define TIOCA_CONTROL1_AGPDMA_OP_COMBDELAY_MASK      0x1full
#define TIOCA_CONTROL1_AGPDMA_OP_COMBDELAY_INPLACE (TIOCA_CONTROL1_AGPDMA_OP_COMBDELAY_MASK << TIOCA_CONTROL1_AGPDMA_OP_COMBDELAY_SHIFT)
#define TIOCA_CONTROL1_PIO_ADDR_OFFSET_SHIFT         24 /* established */
#define TIOCA_CONTROL1_PIO_ADDR_OFFSET_MASK          0xffull
#define TIOCA_CONTROL1_PIO_ADDR_OFFSET_INPLACE (TIOCA_CONTROL1_PIO_ADDR_OFFSET_MASK << TIOCA_CONTROL1_PIO_ADDR_OFFSET_SHIFT)
#define TIOCA_CONTROL1_PCIM_FAST_BTB_ENB_SHIFT       19 /* established */
#define TIOCA_CONTROL1_PCIM_FAST_BTB_ENB_MASK        0x1ull
#define TIOCA_CONTROL1_PCIM_FAST_BTB_ENB_INPLACE (TIOCA_CONTROL1_PCIM_FAST_BTB_ENB_MASK << TIOCA_CONTROL1_PCIM_FAST_BTB_ENB_SHIFT)
#define TIOCA_CONTROL1_PCIM_IO_NBE_AD_SHIFT          16 /* established */
#define TIOCA_CONTROL1_PCIM_IO_NBE_AD_MASK           0x7ull
#define TIOCA_CONTROL1_PCIM_IO_NBE_AD_INPLACE (TIOCA_CONTROL1_PCIM_IO_NBE_AD_MASK << TIOCA_CONTROL1_PCIM_IO_NBE_AD_SHIFT)
#define TIOCA_CONTROL1_INJ_DATA_PERR_SHIFT           13 /* established */
#define TIOCA_CONTROL1_INJ_DATA_PERR_MASK            0x1ull
#define TIOCA_CONTROL1_INJ_DATA_PERR_INPLACE (TIOCA_CONTROL1_INJ_DATA_PERR_MASK << TIOCA_CONTROL1_INJ_DATA_PERR_SHIFT)
#define TIOCA_CONTROL1_INJ_ADDR_PERR_SHIFT           12 /* established */
#define TIOCA_CONTROL1_INJ_ADDR_PERR_MASK            0x1ull
#define TIOCA_CONTROL1_INJ_ADDR_PERR_INPLACE (TIOCA_CONTROL1_INJ_ADDR_PERR_MASK << TIOCA_CONTROL1_INJ_ADDR_PERR_SHIFT)
#define TIOCA_CONTROL1_AGP_INIT_CAL_ENB_SHIFT        11 /* established */
#define TIOCA_CONTROL1_AGP_INIT_CAL_ENB_MASK         0x1ull
#define TIOCA_CONTROL1_AGP_INIT_CAL_ENB_INPLACE (TIOCA_CONTROL1_AGP_INIT_CAL_ENB_MASK << TIOCA_CONTROL1_AGP_INIT_CAL_ENB_SHIFT)
#define TIOCA_CONTROL1_AGP_CAL_PRSCL_BYP_SHIFT       10 /* established */
#define TIOCA_CONTROL1_AGP_CAL_PRSCL_BYP_MASK        0x1ull
#define TIOCA_CONTROL1_AGP_CAL_PRSCL_BYP_INPLACE (TIOCA_CONTROL1_AGP_CAL_PRSCL_BYP_MASK << TIOCA_CONTROL1_AGP_CAL_PRSCL_BYP_SHIFT)
#define TIOCA_CONTROL1_AGP_CAL_CYCLE_SHIFT           7 /* established */
#define TIOCA_CONTROL1_AGP_CAL_CYCLE_MASK            0x7ull
#define TIOCA_CONTROL1_AGP_CAL_CYCLE_INPLACE (TIOCA_CONTROL1_AGP_CAL_CYCLE_MASK << TIOCA_CONTROL1_AGP_CAL_CYCLE_SHIFT)
#define TIOCA_CONTROL1_AGP_FW_ENABLE_SHIFT           6 /* established */
#define TIOCA_CONTROL1_AGP_FW_ENABLE_MASK            0x1ull
#define TIOCA_CONTROL1_AGP_FW_ENABLE_INPLACE (TIOCA_CONTROL1_AGP_FW_ENABLE_MASK << TIOCA_CONTROL1_AGP_FW_ENABLE_SHIFT)
#define TIOCA_CONTROL1_GFX_WR_SWAP_SHIFT             5 /* established */
#define TIOCA_CONTROL1_GFX_WR_SWAP_MASK              0x1ull
#define TIOCA_CONTROL1_GFX_WR_SWAP_INPLACE (TIOCA_CONTROL1_GFX_WR_SWAP_MASK << TIOCA_CONTROL1_GFX_WR_SWAP_SHIFT)
#define TIOCA_CONTROL1_PIO_MEM_SWAP_SHIFT            4 /* established */
#define TIOCA_CONTROL1_PIO_MEM_SWAP_MASK             0x1ull
#define TIOCA_CONTROL1_PIO_MEM_SWAP_INPLACE (TIOCA_CONTROL1_PIO_MEM_SWAP_MASK << TIOCA_CONTROL1_PIO_MEM_SWAP_SHIFT)
#define TIOCA_CONTROL1_PIO_IO_SWAP_SHIFT             3 /* established */
#define TIOCA_CONTROL1_PIO_IO_SWAP_MASK              0x1ull
#define TIOCA_CONTROL1_PIO_IO_SWAP_INPLACE (TIOCA_CONTROL1_PIO_IO_SWAP_MASK << TIOCA_CONTROL1_PIO_IO_SWAP_SHIFT)
#define TIOCA_CONTROL1_DMA_PCI_SWAP_SHIFT            2 /* established */
#define TIOCA_CONTROL1_DMA_PCI_SWAP_MASK             0x1ull
#define TIOCA_CONTROL1_DMA_PCI_SWAP_INPLACE (TIOCA_CONTROL1_DMA_PCI_SWAP_MASK << TIOCA_CONTROL1_DMA_PCI_SWAP_SHIFT)
#define TIOCA_CONTROL1_DMA_AGP_SWAP_SHIFT            1 /* established */
#define TIOCA_CONTROL1_DMA_AGP_SWAP_MASK             0x1ull
#define TIOCA_CONTROL1_DMA_AGP_SWAP_INPLACE (TIOCA_CONTROL1_DMA_AGP_SWAP_MASK << TIOCA_CONTROL1_DMA_AGP_SWAP_SHIFT)
#define TIOCA_CONTROL1_SYS_BIG_END_SHIFT             0 /* established */
#define TIOCA_CONTROL1_SYS_BIG_END_MASK              0x1ull
#define TIOCA_CONTROL1_SYS_BIG_END_INPLACE (TIOCA_CONTROL1_SYS_BIG_END_MASK << TIOCA_CONTROL1_SYS_BIG_END_SHIFT)

/*
 * Control 2. The provider programs GART memory parameter 2 (cached, coherent
 * GART table), clears both GART prefetch enables, and sets the GART TLB flush
 * bit (36) to flush explicitly. On revision A hardware it pulses the flush with
 * the memory parameter cleared first (PV910244: the flush is ignored while the
 * table is cached), then restores the parameter. Name and offset are the vendor
 * header's definition (struct member ca_control2). Access rw: established as a
 * software expectation, because the provider changes single bits by reading the
 * register back and writing it (read-modify-write). The flush bit is read back
 * after setting. Reset value unknown: the header and provider state none, and
 * no firmware reading has been done.
 */
/* control2: rw64, reset unknown */
#define TIOCA_CONTROL2                               0x000010 /* established */
#define TIOCA_CONTROL2_CRM_MAX_CREDIT_SHIFT          60 /* established */
#define TIOCA_CONTROL2_CRM_MAX_CREDIT_MASK           0x7ull
#define TIOCA_CONTROL2_CRM_MAX_CREDIT_INPLACE (TIOCA_CONTROL2_CRM_MAX_CREDIT_MASK << TIOCA_CONTROL2_CRM_MAX_CREDIT_SHIFT)
#define TIOCA_CONTROL2_CRM_PRESCALER_BYP_SHIFT       57 /* established */
#define TIOCA_CONTROL2_CRM_PRESCALER_BYP_MASK        0x1ull
#define TIOCA_CONTROL2_CRM_PRESCALER_BYP_INPLACE (TIOCA_CONTROL2_CRM_PRESCALER_BYP_MASK << TIOCA_CONTROL2_CRM_PRESCALER_BYP_SHIFT)
#define TIOCA_CONTROL2_CRM_TNUMTO_ENB_SHIFT          56 /* established */
#define TIOCA_CONTROL2_CRM_TNUMTO_ENB_MASK           0x1ull
#define TIOCA_CONTROL2_CRM_TNUMTO_ENB_INPLACE (TIOCA_CONTROL2_CRM_TNUMTO_ENB_MASK << TIOCA_CONTROL2_CRM_TNUMTO_ENB_SHIFT)
#define TIOCA_CONTROL2_CRM_TNUMTO_PERIOD_SHIFT       40 /* established */
#define TIOCA_CONTROL2_CRM_TNUMTO_PERIOD_MASK        0x1fffull
#define TIOCA_CONTROL2_CRM_TNUMTO_PERIOD_INPLACE (TIOCA_CONTROL2_CRM_TNUMTO_PERIOD_MASK << TIOCA_CONTROL2_CRM_TNUMTO_PERIOD_SHIFT)
#define TIOCA_CONTROL2_GART_FLUSH_TLB_SHIFT          36 /* established */
#define TIOCA_CONTROL2_GART_FLUSH_TLB_MASK           0x1ull
#define TIOCA_CONTROL2_GART_FLUSH_TLB_INPLACE (TIOCA_CONTROL2_GART_FLUSH_TLB_MASK << TIOCA_CONTROL2_GART_FLUSH_TLB_SHIFT)
#define TIOCA_CONTROL2_GART_WR_PREFETCH_ENB_SHIFT    35 /* established */
#define TIOCA_CONTROL2_GART_WR_PREFETCH_ENB_MASK     0x1ull
#define TIOCA_CONTROL2_GART_WR_PREFETCH_ENB_INPLACE (TIOCA_CONTROL2_GART_WR_PREFETCH_ENB_MASK << TIOCA_CONTROL2_GART_WR_PREFETCH_ENB_SHIFT)
#define TIOCA_CONTROL2_GART_RD_PREFETCH_ENB_SHIFT    34 /* established */
#define TIOCA_CONTROL2_GART_RD_PREFETCH_ENB_MASK     0x1ull
#define TIOCA_CONTROL2_GART_RD_PREFETCH_ENB_INPLACE (TIOCA_CONTROL2_GART_RD_PREFETCH_ENB_MASK << TIOCA_CONTROL2_GART_RD_PREFETCH_ENB_SHIFT)
#define TIOCA_CONTROL2_GART_MEM_PARAM_SHIFT          32 /* established */
#define TIOCA_CONTROL2_GART_MEM_PARAM_MASK           0x3ull
#define TIOCA_CONTROL2_GART_MEM_PARAM_INPLACE (TIOCA_CONTROL2_GART_MEM_PARAM_MASK << TIOCA_CONTROL2_GART_MEM_PARAM_SHIFT)
#define TIOCA_CONTROL2_PCI_ARB_ERR_ENB_SHIFT         31 /* established */
#define TIOCA_CONTROL2_PCI_ARB_ERR_ENB_MASK          0x1ull
#define TIOCA_CONTROL2_PCI_ARB_ERR_ENB_INPLACE (TIOCA_CONTROL2_PCI_ARB_ERR_ENB_MASK << TIOCA_CONTROL2_PCI_ARB_ERR_ENB_SHIFT)
#define TIOCA_CONTROL2_MSI_INT_ENB_SHIFT             30 /* established */
#define TIOCA_CONTROL2_MSI_INT_ENB_MASK              0x1ull
#define TIOCA_CONTROL2_MSI_INT_ENB_INPLACE (TIOCA_CONTROL2_MSI_INT_ENB_MASK << TIOCA_CONTROL2_MSI_INT_ENB_SHIFT)
#define TIOCA_CONTROL2_RT_INT_EN_SHIFT               28 /* established */
#define TIOCA_CONTROL2_RT_INT_EN_MASK                0x3ull
#define TIOCA_CONTROL2_RT_INT_EN_INPLACE (TIOCA_CONTROL2_RT_INT_EN_MASK << TIOCA_CONTROL2_RT_INT_EN_SHIFT)
#define TIOCA_CONTROL2_PCI_MAX_RETRY_SHIFT           16 /* established */
#define TIOCA_CONTROL2_PCI_MAX_RETRY_MASK            0x3ffull
#define TIOCA_CONTROL2_PCI_MAX_RETRY_INPLACE (TIOCA_CONTROL2_PCI_MAX_RETRY_MASK << TIOCA_CONTROL2_PCI_MAX_RETRY_SHIFT)
#define TIOCA_CONTROL2_PCI_LATENCY_TO_SHIFT          8 /* established */
#define TIOCA_CONTROL2_PCI_LATENCY_TO_MASK           0xffull
#define TIOCA_CONTROL2_PCI_LATENCY_TO_INPLACE (TIOCA_CONTROL2_PCI_LATENCY_TO_MASK << TIOCA_CONTROL2_PCI_LATENCY_TO_SHIFT)
#define TIOCA_CONTROL2_AGP_LATENCY_TO_SHIFT          0 /* established */
#define TIOCA_CONTROL2_AGP_LATENCY_TO_MASK           0xffull
#define TIOCA_CONTROL2_AGP_LATENCY_TO_INPLACE (TIOCA_CONTROL2_AGP_LATENCY_TO_MASK << TIOCA_CONTROL2_AGP_LATENCY_TO_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_status1). Access r: inferred from the name (a status word); the code read
 * never touches it. Reset value unknown: the header and provider state none,
 * and no firmware reading has been done.
 */
/* status1: r64, reset unknown */
#define TIOCA_STATUS1                                0x000018 /* established */
#define TIOCA_STATUS1_GART_TLB_VAL_SHIFT             16 /* established */
#define TIOCA_STATUS1_GART_TLB_VAL_MASK              0xffull
#define TIOCA_STATUS1_GART_TLB_VAL_INPLACE (TIOCA_STATUS1_GART_TLB_VAL_MASK << TIOCA_STATUS1_GART_TLB_VAL_SHIFT)
#define TIOCA_STATUS1_CRM_SPACE_AVAIL_SHIFT          8 /* established */
#define TIOCA_STATUS1_CRM_SPACE_AVAIL_MASK           0x7full
#define TIOCA_STATUS1_CRM_SPACE_AVAIL_INPLACE (TIOCA_STATUS1_CRM_SPACE_AVAIL_MASK << TIOCA_STATUS1_CRM_SPACE_AVAIL_SHIFT)
#define TIOCA_STATUS1_CRM_CREDIT_AVAIL_SHIFT         4 /* established */
#define TIOCA_STATUS1_CRM_CREDIT_AVAIL_MASK          0x7ull
#define TIOCA_STATUS1_CRM_CREDIT_AVAIL_INPLACE (TIOCA_STATUS1_CRM_CREDIT_AVAIL_MASK << TIOCA_STATUS1_CRM_CREDIT_AVAIL_SHIFT)
#define TIOCA_STATUS1_INTB_N_SHIFT                   3 /* established */
#define TIOCA_STATUS1_INTB_N_MASK                    0x1ull
#define TIOCA_STATUS1_INTB_N_INPLACE (TIOCA_STATUS1_INTB_N_MASK << TIOCA_STATUS1_INTB_N_SHIFT)
#define TIOCA_STATUS1_INTA_N_SHIFT                   2 /* established */
#define TIOCA_STATUS1_INTA_N_MASK                    0x1ull
#define TIOCA_STATUS1_INTA_N_INPLACE (TIOCA_STATUS1_INTA_N_MASK << TIOCA_STATUS1_INTA_N_SHIFT)
#define TIOCA_STATUS1_CORELET_ID_SHIFT               0 /* established */
#define TIOCA_STATUS1_CORELET_ID_MASK                0x3ull
#define TIOCA_STATUS1_CORELET_ID_INPLACE (TIOCA_STATUS1_CORELET_ID_MASK << TIOCA_STATUS1_CORELET_ID_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_status2). Access r: inferred from the name (a status word); the code read
 * never touches it. Reset value unknown: the header and provider state none,
 * and no firmware reading has been done.
 */
/* status2: r64, reset unknown */
#define TIOCA_STATUS2                                0x000020 /* established */
#define TIOCA_STATUS2_PDMA_RDBUFF_AVAIL_SHIFT        56 /* established */
#define TIOCA_STATUS2_PDMA_RDBUFF_AVAIL_MASK         0x3ull
#define TIOCA_STATUS2_PDMA_RDBUFF_AVAIL_INPLACE (TIOCA_STATUS2_PDMA_RDBUFF_AVAIL_MASK << TIOCA_STATUS2_PDMA_RDBUFF_AVAIL_SHIFT)
#define TIOCA_STATUS2_PDMA_WRBUFF_AVAIL_SHIFT        52 /* established */
#define TIOCA_STATUS2_PDMA_WRBUFF_AVAIL_MASK         0xfull
#define TIOCA_STATUS2_PDMA_WRBUFF_AVAIL_INPLACE (TIOCA_STATUS2_PDMA_WRBUFF_AVAIL_MASK << TIOCA_STATUS2_PDMA_WRBUFF_AVAIL_SHIFT)
#define TIOCA_STATUS2_PDMA_OPQ_AVAIL_SHIFT           48 /* established */
#define TIOCA_STATUS2_PDMA_OPQ_AVAIL_MASK            0xfull
#define TIOCA_STATUS2_PDMA_OPQ_AVAIL_INPLACE (TIOCA_STATUS2_PDMA_OPQ_AVAIL_MASK << TIOCA_STATUS2_PDMA_OPQ_AVAIL_SHIFT)
#define TIOCA_STATUS2_PCI_PIO_OP_STAT_SHIFT          47 /* established */
#define TIOCA_STATUS2_PCI_PIO_OP_STAT_MASK           0x1ull
#define TIOCA_STATUS2_PCI_PIO_OP_STAT_INPLACE (TIOCA_STATUS2_PCI_PIO_OP_STAT_MASK << TIOCA_STATUS2_PCI_PIO_OP_STAT_SHIFT)
#define TIOCA_STATUS2_ADMA_RDBUFF_AVAIL_SHIFT        40 /* established */
#define TIOCA_STATUS2_ADMA_RDBUFF_AVAIL_MASK         0x7full
#define TIOCA_STATUS2_ADMA_RDBUFF_AVAIL_INPLACE (TIOCA_STATUS2_ADMA_RDBUFF_AVAIL_MASK << TIOCA_STATUS2_ADMA_RDBUFF_AVAIL_SHIFT)
#define TIOCA_STATUS2_ADMA_WRBUFF_AVAIL_SHIFT        32 /* established */
#define TIOCA_STATUS2_ADMA_WRBUFF_AVAIL_MASK         0xffull
#define TIOCA_STATUS2_ADMA_WRBUFF_AVAIL_INPLACE (TIOCA_STATUS2_ADMA_WRBUFF_AVAIL_MASK << TIOCA_STATUS2_ADMA_WRBUFF_AVAIL_SHIFT)
#define TIOCA_STATUS2_ADMA_OPQ_AVAIL_SHIFT           24 /* established */
#define TIOCA_STATUS2_ADMA_OPQ_AVAIL_MASK            0xffull
#define TIOCA_STATUS2_ADMA_OPQ_AVAIL_INPLACE (TIOCA_STATUS2_ADMA_OPQ_AVAIL_MASK << TIOCA_STATUS2_ADMA_OPQ_AVAIL_SHIFT)
#define TIOCA_STATUS2_GFX_WRBUFF_AVAIL_SHIFT         16 /* established */
#define TIOCA_STATUS2_GFX_WRBUFF_AVAIL_MASK          0xffull
#define TIOCA_STATUS2_GFX_WRBUFF_AVAIL_INPLACE (TIOCA_STATUS2_GFX_WRBUFF_AVAIL_MASK << TIOCA_STATUS2_GFX_WRBUFF_AVAIL_SHIFT)
#define TIOCA_STATUS2_GFX_OPQ_AVAIL_SHIFT            8 /* established */
#define TIOCA_STATUS2_GFX_OPQ_AVAIL_MASK             0xffull
#define TIOCA_STATUS2_GFX_OPQ_AVAIL_INPLACE (TIOCA_STATUS2_GFX_OPQ_AVAIL_MASK << TIOCA_STATUS2_GFX_OPQ_AVAIL_SHIFT)
#define TIOCA_STATUS2_GFX_CREDIT_AVAIL_SHIFT         0 /* established */
#define TIOCA_STATUS2_GFX_CREDIT_AVAIL_MASK          0xffull
#define TIOCA_STATUS2_GFX_CREDIT_AVAIL_INPLACE (TIOCA_STATUS2_GFX_CREDIT_AVAIL_MASK << TIOCA_STATUS2_GFX_CREDIT_AVAIL_SHIFT)

/*
 * GART aperture. The provider writes size, page-size and enable bits plus the
 * bus base in one 64-bit store: size field 0x3ff for 4 MiB, one bit fewer set
 * per doubling down to 0x000 for 4 GiB (the field is the complement of the size
 * in 4 MiB units); bit 1 set when the kernel page is 16 KiB; enable bits 0
 * (AGP) and 2 (PCI); the bus base ORed in unshifted (the base field starts at
 * bit 22, and the base 0x80000000 falls inside it). The name is spelled
 * aperature in the header. Name and offset are the vendor header's definition
 * (struct member ca_gart_aperature). Software only writes it (one 64-bit store,
 * last in GART setup, after the table is built). Writability: established.
 * Readability and any bit that reads back differently: unknown, so rw stays as
 * the widest access. Reset value unknown: the header and provider state none,
 * and no firmware reading has been done.
 */
/* gart_aperature: rw64, reset unknown */
#define TIOCA_GART_APERATURE                         0x000028 /* established */
#define TIOCA_GART_APERATURE_GART_AP_BASE_SHIFT      22 /* established */
#define TIOCA_GART_APERATURE_GART_AP_BASE_MASK       0x3ffffffffffull
#define TIOCA_GART_APERATURE_GART_AP_BASE_INPLACE (TIOCA_GART_APERATURE_GART_AP_BASE_MASK << TIOCA_GART_APERATURE_GART_AP_BASE_SHIFT)
#define TIOCA_GART_APERATURE_GART_AP_SIZE_SHIFT      12 /* established */
#define TIOCA_GART_APERATURE_GART_AP_SIZE_MASK       0x3ffull
#define TIOCA_GART_APERATURE_GART_AP_SIZE_INPLACE (TIOCA_GART_APERATURE_GART_AP_SIZE_MASK << TIOCA_GART_APERATURE_GART_AP_SIZE_SHIFT)
#define TIOCA_GART_APERATURE_GART_AP_ENB_PCI_SHIFT   2 /* established */
#define TIOCA_GART_APERATURE_GART_AP_ENB_PCI_MASK    0x1ull
#define TIOCA_GART_APERATURE_GART_AP_ENB_PCI_INPLACE (TIOCA_GART_APERATURE_GART_AP_ENB_PCI_MASK << TIOCA_GART_APERATURE_GART_AP_ENB_PCI_SHIFT)
#define TIOCA_GART_APERATURE_GART_PAGE_SIZE_SHIFT    1 /* established */
#define TIOCA_GART_APERATURE_GART_PAGE_SIZE_MASK     0x1ull
#define TIOCA_GART_APERATURE_GART_PAGE_SIZE_INPLACE (TIOCA_GART_APERATURE_GART_PAGE_SIZE_MASK << TIOCA_GART_APERATURE_GART_PAGE_SIZE_SHIFT)
#define TIOCA_GART_APERATURE_GART_AP_ENB_AGP_SHIFT   0 /* established */
#define TIOCA_GART_APERATURE_GART_AP_ENB_AGP_MASK    0x1ull
#define TIOCA_GART_APERATURE_GART_AP_ENB_AGP_INPLACE (TIOCA_GART_APERATURE_GART_AP_ENB_AGP_MASK << TIOCA_GART_APERATURE_GART_AP_ENB_AGP_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_gfx_detach). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* gfx_detach: rw64, reset unknown */
#define TIOCA_GFX_DETACH                             0x000030 /* established */

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_inta_dest_addr). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* inta_dest_addr: rw64, reset unknown */
#define TIOCA_INTA_DEST_ADDR                         0x000038 /* established */
#define TIOCA_INTA_DEST_ADDR_INT_DEST_VECT_SHIFT     56 /* established */
#define TIOCA_INTA_DEST_ADDR_INT_DEST_VECT_MASK      0xffull
#define TIOCA_INTA_DEST_ADDR_INT_DEST_VECT_INPLACE (TIOCA_INTA_DEST_ADDR_INT_DEST_VECT_MASK << TIOCA_INTA_DEST_ADDR_INT_DEST_VECT_SHIFT)
#define TIOCA_INTA_DEST_ADDR_INT_DEST_ADDR_SHIFT     3 /* established */
#define TIOCA_INTA_DEST_ADDR_INT_DEST_ADDR_MASK      0x7ffffffffffffull
#define TIOCA_INTA_DEST_ADDR_INT_DEST_ADDR_INPLACE (TIOCA_INTA_DEST_ADDR_INT_DEST_ADDR_MASK << TIOCA_INTA_DEST_ADDR_INT_DEST_ADDR_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_intb_dest_addr). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* intb_dest_addr: rw64, reset unknown */
#define TIOCA_INTB_DEST_ADDR                         0x000040 /* established */
#define TIOCA_INTB_DEST_ADDR_INT_DEST_VECT_SHIFT     56 /* established */
#define TIOCA_INTB_DEST_ADDR_INT_DEST_VECT_MASK      0xffull
#define TIOCA_INTB_DEST_ADDR_INT_DEST_VECT_INPLACE (TIOCA_INTB_DEST_ADDR_INT_DEST_VECT_MASK << TIOCA_INTB_DEST_ADDR_INT_DEST_VECT_SHIFT)
#define TIOCA_INTB_DEST_ADDR_INT_DEST_ADDR_SHIFT     3 /* established */
#define TIOCA_INTB_DEST_ADDR_INT_DEST_ADDR_MASK      0x7ffffffffffffull
#define TIOCA_INTB_DEST_ADDR_INT_DEST_ADDR_INPLACE (TIOCA_INTB_DEST_ADDR_INT_DEST_ADDR_MASK << TIOCA_INTB_DEST_ADDR_INT_DEST_ADDR_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_err_int_dest_addr). Software never touches this register in the code read,
 * so access direction is unknown and rw is a placeholder. Reset value unknown:
 * the header and provider state none, and no firmware reading has been done.
 */
/* err_int_dest_addr: rw64, reset unknown */
#define TIOCA_ERR_INT_DEST_ADDR                      0x000048 /* established */
#define TIOCA_ERR_INT_DEST_ADDR_INT_DEST_VECT_SHIFT  56 /* established */
#define TIOCA_ERR_INT_DEST_ADDR_INT_DEST_VECT_MASK   0xffull
#define TIOCA_ERR_INT_DEST_ADDR_INT_DEST_VECT_INPLACE (TIOCA_ERR_INT_DEST_ADDR_INT_DEST_VECT_MASK << TIOCA_ERR_INT_DEST_ADDR_INT_DEST_VECT_SHIFT)
#define TIOCA_ERR_INT_DEST_ADDR_INT_DEST_ADDR_SHIFT  3 /* established */
#define TIOCA_ERR_INT_DEST_ADDR_INT_DEST_ADDR_MASK   0x7ffffffffffffull
#define TIOCA_ERR_INT_DEST_ADDR_INT_DEST_ADDR_INPLACE (TIOCA_ERR_INT_DEST_ADDR_INT_DEST_ADDR_MASK << TIOCA_ERR_INT_DEST_ADDR_INT_DEST_ADDR_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_int_status). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* int_status: rw64, reset unknown */
#define TIOCA_INT_STATUS                             0x000050 /* established */
#define TIOCA_INT_STATUS_GFX_CREDIT_OVFLW_SHIFT      21 /* established */
#define TIOCA_INT_STATUS_GFX_CREDIT_OVFLW_MASK       0x1ull
#define TIOCA_INT_STATUS_GFX_CREDIT_OVFLW_INPLACE (TIOCA_INT_STATUS_GFX_CREDIT_OVFLW_MASK << TIOCA_INT_STATUS_GFX_CREDIT_OVFLW_SHIFT)
#define TIOCA_INT_STATUS_MULT_INTB_SHIFT             20 /* established */
#define TIOCA_INT_STATUS_MULT_INTB_MASK              0x1ull
#define TIOCA_INT_STATUS_MULT_INTB_INPLACE (TIOCA_INT_STATUS_MULT_INTB_MASK << TIOCA_INT_STATUS_MULT_INTB_SHIFT)
#define TIOCA_INT_STATUS_MULT_INTA_SHIFT             19 /* established */
#define TIOCA_INT_STATUS_MULT_INTA_MASK              0x1ull
#define TIOCA_INT_STATUS_MULT_INTA_INPLACE (TIOCA_INT_STATUS_MULT_INTA_MASK << TIOCA_INT_STATUS_MULT_INTA_SHIFT)
#define TIOCA_INT_STATUS_INTB_SHIFT                  18 /* established */
#define TIOCA_INT_STATUS_INTB_MASK                   0x1ull
#define TIOCA_INT_STATUS_INTB_INPLACE (TIOCA_INT_STATUS_INTB_MASK << TIOCA_INT_STATUS_INTB_SHIFT)
#define TIOCA_INT_STATUS_INTA_SHIFT                  17 /* established */
#define TIOCA_INT_STATUS_INTA_MASK                   0x1ull
#define TIOCA_INT_STATUS_INTA_INPLACE (TIOCA_INT_STATUS_INTA_MASK << TIOCA_INT_STATUS_INTA_SHIFT)
#define TIOCA_INT_STATUS_SBA_TYPE1_ERR_SHIFT         15 /* established */
#define TIOCA_INT_STATUS_SBA_TYPE1_ERR_MASK          0x1ull
#define TIOCA_INT_STATUS_SBA_TYPE1_ERR_INPLACE (TIOCA_INT_STATUS_SBA_TYPE1_ERR_MASK << TIOCA_INT_STATUS_SBA_TYPE1_ERR_SHIFT)
#define TIOCA_INT_STATUS_AGP_REQ_OFLOW_SHIFT         14 /* established */
#define TIOCA_INT_STATUS_AGP_REQ_OFLOW_MASK          0x1ull
#define TIOCA_INT_STATUS_AGP_REQ_OFLOW_INPLACE (TIOCA_INT_STATUS_AGP_REQ_OFLOW_MASK << TIOCA_INT_STATUS_AGP_REQ_OFLOW_SHIFT)
#define TIOCA_INT_STATUS_PCI_ARB_TO_SHIFT            13 /* established */
#define TIOCA_INT_STATUS_PCI_ARB_TO_MASK             0x1ull
#define TIOCA_INT_STATUS_PCI_ARB_TO_INPLACE (TIOCA_INT_STATUS_PCI_ARB_TO_MASK << TIOCA_INT_STATUS_PCI_ARB_TO_SHIFT)
#define TIOCA_INT_STATUS_PIO_INVALID_ADDR_SHIFT      12 /* established */
#define TIOCA_INT_STATUS_PIO_INVALID_ADDR_MASK       0x1ull
#define TIOCA_INT_STATUS_PIO_INVALID_ADDR_INPLACE (TIOCA_INT_STATUS_PIO_INVALID_ADDR_MASK << TIOCA_INT_STATUS_PIO_INVALID_ADDR_SHIFT)
#define TIOCA_INT_STATUS_CXM_REQ_CRED_OVFLW_SHIFT    11 /* established */
#define TIOCA_INT_STATUS_CXM_REQ_CRED_OVFLW_MASK     0x1ull
#define TIOCA_INT_STATUS_CXM_REQ_CRED_OVFLW_INPLACE (TIOCA_INT_STATUS_CXM_REQ_CRED_OVFLW_MASK << TIOCA_INT_STATUS_CXM_REQ_CRED_OVFLW_SHIFT)
#define TIOCA_INT_STATUS_CXM_RSP_CRED_OVFLW_SHIFT    10 /* established */
#define TIOCA_INT_STATUS_CXM_RSP_CRED_OVFLW_MASK     0x1ull
#define TIOCA_INT_STATUS_CXM_RSP_CRED_OVFLW_INPLACE (TIOCA_INT_STATUS_CXM_RSP_CRED_OVFLW_MASK << TIOCA_INT_STATUS_CXM_RSP_CRED_OVFLW_SHIFT)
#define TIOCA_INT_STATUS_TNUMTO_SHIFT                9 /* established */
#define TIOCA_INT_STATUS_TNUMTO_MASK                 0x1ull
#define TIOCA_INT_STATUS_TNUMTO_INPLACE (TIOCA_INT_STATUS_TNUMTO_MASK << TIOCA_INT_STATUS_TNUMTO_SHIFT)
#define TIOCA_INT_STATUS_CRM_DVERR_SHIFT             8 /* established */
#define TIOCA_INT_STATUS_CRM_DVERR_MASK              0x1ull
#define TIOCA_INT_STATUS_CRM_DVERR_INPLACE (TIOCA_INT_STATUS_CRM_DVERR_MASK << TIOCA_INT_STATUS_CRM_DVERR_SHIFT)
#define TIOCA_INT_STATUS_CRM_PKTERR_SHIFT            7 /* established */
#define TIOCA_INT_STATUS_CRM_PKTERR_MASK             0x1ull
#define TIOCA_INT_STATUS_CRM_PKTERR_INPLACE (TIOCA_INT_STATUS_CRM_PKTERR_MASK << TIOCA_INT_STATUS_CRM_PKTERR_SHIFT)
#define TIOCA_INT_STATUS_PIO_REQ_OVFLW_SHIFT         6 /* established */
#define TIOCA_INT_STATUS_PIO_REQ_OVFLW_MASK          0x1ull
#define TIOCA_INT_STATUS_PIO_REQ_OVFLW_INPLACE (TIOCA_INT_STATUS_PIO_REQ_OVFLW_MASK << TIOCA_INT_STATUS_PIO_REQ_OVFLW_SHIFT)
#define TIOCA_INT_STATUS_GFX_WR_OVFLW_SHIFT          5 /* established */
#define TIOCA_INT_STATUS_GFX_WR_OVFLW_MASK           0x1ull
#define TIOCA_INT_STATUS_GFX_WR_OVFLW_INPLACE (TIOCA_INT_STATUS_GFX_WR_OVFLW_MASK << TIOCA_INT_STATUS_GFX_WR_OVFLW_SHIFT)
#define TIOCA_INT_STATUS_GART_FETCH_ERR_SHIFT        4 /* established */
#define TIOCA_INT_STATUS_GART_FETCH_ERR_MASK         0x1ull
#define TIOCA_INT_STATUS_GART_FETCH_ERR_INPLACE (TIOCA_INT_STATUS_GART_FETCH_ERR_MASK << TIOCA_INT_STATUS_GART_FETCH_ERR_SHIFT)
#define TIOCA_INT_STATUS_PCI_ERR_SHIFT               0 /* established */
#define TIOCA_INT_STATUS_PCI_ERR_MASK                0x1ull
#define TIOCA_INT_STATUS_PCI_ERR_INPLACE (TIOCA_INT_STATUS_PCI_ERR_MASK << TIOCA_INT_STATUS_PCI_ERR_SHIFT)

/*
 * Interrupt status write alias. The provider writes the GART fetch error bit
 * here to clear it (the alias is the write-to-clear form of ca_int_status; the
 * name says alias, the clear role is the provider's use). Name and offset are
 * the vendor header's definition (struct member ca_int_status_alias). The
 * provider writes the single bit it wants cleared to this register to drop
 * residual GART fetch errors before unmasking. That a written 1 clears the
 * matching status bit is inferred from the provider's own comment (clear
 * residual errors first); readability is unknown, so rw stays as the widest
 * access. Reset value unknown: the header and provider state none, and no
 * firmware reading has been done.
 */
/* int_status_alias: rw64, reset unknown */
#define TIOCA_INT_STATUS_ALIAS                       0x000058 /* established */
#define TIOCA_INT_STATUS_ALIAS_GFX_CREDIT_OVFLW_SHIFT 21 /* established */
#define TIOCA_INT_STATUS_ALIAS_GFX_CREDIT_OVFLW_MASK 0x1ull
#define TIOCA_INT_STATUS_ALIAS_GFX_CREDIT_OVFLW_INPLACE (TIOCA_INT_STATUS_ALIAS_GFX_CREDIT_OVFLW_MASK << TIOCA_INT_STATUS_ALIAS_GFX_CREDIT_OVFLW_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_MULT_INTB_SHIFT       20 /* established */
#define TIOCA_INT_STATUS_ALIAS_MULT_INTB_MASK        0x1ull
#define TIOCA_INT_STATUS_ALIAS_MULT_INTB_INPLACE (TIOCA_INT_STATUS_ALIAS_MULT_INTB_MASK << TIOCA_INT_STATUS_ALIAS_MULT_INTB_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_MULT_INTA_SHIFT       19 /* established */
#define TIOCA_INT_STATUS_ALIAS_MULT_INTA_MASK        0x1ull
#define TIOCA_INT_STATUS_ALIAS_MULT_INTA_INPLACE (TIOCA_INT_STATUS_ALIAS_MULT_INTA_MASK << TIOCA_INT_STATUS_ALIAS_MULT_INTA_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_INTB_SHIFT            18 /* established */
#define TIOCA_INT_STATUS_ALIAS_INTB_MASK             0x1ull
#define TIOCA_INT_STATUS_ALIAS_INTB_INPLACE (TIOCA_INT_STATUS_ALIAS_INTB_MASK << TIOCA_INT_STATUS_ALIAS_INTB_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_INTA_SHIFT            17 /* established */
#define TIOCA_INT_STATUS_ALIAS_INTA_MASK             0x1ull
#define TIOCA_INT_STATUS_ALIAS_INTA_INPLACE (TIOCA_INT_STATUS_ALIAS_INTA_MASK << TIOCA_INT_STATUS_ALIAS_INTA_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_SBA_TYPE1_ERR_SHIFT   15 /* established */
#define TIOCA_INT_STATUS_ALIAS_SBA_TYPE1_ERR_MASK    0x1ull
#define TIOCA_INT_STATUS_ALIAS_SBA_TYPE1_ERR_INPLACE (TIOCA_INT_STATUS_ALIAS_SBA_TYPE1_ERR_MASK << TIOCA_INT_STATUS_ALIAS_SBA_TYPE1_ERR_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_AGP_REQ_OFLOW_SHIFT   14 /* established */
#define TIOCA_INT_STATUS_ALIAS_AGP_REQ_OFLOW_MASK    0x1ull
#define TIOCA_INT_STATUS_ALIAS_AGP_REQ_OFLOW_INPLACE (TIOCA_INT_STATUS_ALIAS_AGP_REQ_OFLOW_MASK << TIOCA_INT_STATUS_ALIAS_AGP_REQ_OFLOW_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_PCI_ARB_TO_SHIFT      13 /* established */
#define TIOCA_INT_STATUS_ALIAS_PCI_ARB_TO_MASK       0x1ull
#define TIOCA_INT_STATUS_ALIAS_PCI_ARB_TO_INPLACE (TIOCA_INT_STATUS_ALIAS_PCI_ARB_TO_MASK << TIOCA_INT_STATUS_ALIAS_PCI_ARB_TO_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_PIO_INVALID_ADDR_SHIFT 12 /* established */
#define TIOCA_INT_STATUS_ALIAS_PIO_INVALID_ADDR_MASK 0x1ull
#define TIOCA_INT_STATUS_ALIAS_PIO_INVALID_ADDR_INPLACE (TIOCA_INT_STATUS_ALIAS_PIO_INVALID_ADDR_MASK << TIOCA_INT_STATUS_ALIAS_PIO_INVALID_ADDR_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_CXM_REQ_CRED_OVFLW_SHIFT 11 /* established */
#define TIOCA_INT_STATUS_ALIAS_CXM_REQ_CRED_OVFLW_MASK 0x1ull
#define TIOCA_INT_STATUS_ALIAS_CXM_REQ_CRED_OVFLW_INPLACE (TIOCA_INT_STATUS_ALIAS_CXM_REQ_CRED_OVFLW_MASK << TIOCA_INT_STATUS_ALIAS_CXM_REQ_CRED_OVFLW_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_CXM_RSP_CRED_OVFLW_SHIFT 10 /* established */
#define TIOCA_INT_STATUS_ALIAS_CXM_RSP_CRED_OVFLW_MASK 0x1ull
#define TIOCA_INT_STATUS_ALIAS_CXM_RSP_CRED_OVFLW_INPLACE (TIOCA_INT_STATUS_ALIAS_CXM_RSP_CRED_OVFLW_MASK << TIOCA_INT_STATUS_ALIAS_CXM_RSP_CRED_OVFLW_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_TNUMTO_SHIFT          9 /* established */
#define TIOCA_INT_STATUS_ALIAS_TNUMTO_MASK           0x1ull
#define TIOCA_INT_STATUS_ALIAS_TNUMTO_INPLACE (TIOCA_INT_STATUS_ALIAS_TNUMTO_MASK << TIOCA_INT_STATUS_ALIAS_TNUMTO_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_CRM_DVERR_SHIFT       8 /* established */
#define TIOCA_INT_STATUS_ALIAS_CRM_DVERR_MASK        0x1ull
#define TIOCA_INT_STATUS_ALIAS_CRM_DVERR_INPLACE (TIOCA_INT_STATUS_ALIAS_CRM_DVERR_MASK << TIOCA_INT_STATUS_ALIAS_CRM_DVERR_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_CRM_PKTERR_SHIFT      7 /* established */
#define TIOCA_INT_STATUS_ALIAS_CRM_PKTERR_MASK       0x1ull
#define TIOCA_INT_STATUS_ALIAS_CRM_PKTERR_INPLACE (TIOCA_INT_STATUS_ALIAS_CRM_PKTERR_MASK << TIOCA_INT_STATUS_ALIAS_CRM_PKTERR_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_PIO_REQ_OVFLW_SHIFT   6 /* established */
#define TIOCA_INT_STATUS_ALIAS_PIO_REQ_OVFLW_MASK    0x1ull
#define TIOCA_INT_STATUS_ALIAS_PIO_REQ_OVFLW_INPLACE (TIOCA_INT_STATUS_ALIAS_PIO_REQ_OVFLW_MASK << TIOCA_INT_STATUS_ALIAS_PIO_REQ_OVFLW_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_GFX_WR_OVFLW_SHIFT    5 /* established */
#define TIOCA_INT_STATUS_ALIAS_GFX_WR_OVFLW_MASK     0x1ull
#define TIOCA_INT_STATUS_ALIAS_GFX_WR_OVFLW_INPLACE (TIOCA_INT_STATUS_ALIAS_GFX_WR_OVFLW_MASK << TIOCA_INT_STATUS_ALIAS_GFX_WR_OVFLW_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_GART_FETCH_ERR_SHIFT  4 /* established */
#define TIOCA_INT_STATUS_ALIAS_GART_FETCH_ERR_MASK   0x1ull
#define TIOCA_INT_STATUS_ALIAS_GART_FETCH_ERR_INPLACE (TIOCA_INT_STATUS_ALIAS_GART_FETCH_ERR_MASK << TIOCA_INT_STATUS_ALIAS_GART_FETCH_ERR_SHIFT)
#define TIOCA_INT_STATUS_ALIAS_PCI_ERR_SHIFT         0 /* established */
#define TIOCA_INT_STATUS_ALIAS_PCI_ERR_MASK          0x1ull
#define TIOCA_INT_STATUS_ALIAS_PCI_ERR_INPLACE (TIOCA_INT_STATUS_ALIAS_PCI_ERR_MASK << TIOCA_INT_STATUS_ALIAS_PCI_ERR_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_mult_error). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* mult_error: rw64, reset unknown */
#define TIOCA_MULT_ERROR                             0x000060 /* established */
#define TIOCA_MULT_ERROR_GFX_CREDIT_OVFLW_SHIFT      21 /* established */
#define TIOCA_MULT_ERROR_GFX_CREDIT_OVFLW_MASK       0x1ull
#define TIOCA_MULT_ERROR_GFX_CREDIT_OVFLW_INPLACE (TIOCA_MULT_ERROR_GFX_CREDIT_OVFLW_MASK << TIOCA_MULT_ERROR_GFX_CREDIT_OVFLW_SHIFT)
#define TIOCA_MULT_ERROR_MULT_INTB_SHIFT             20 /* established */
#define TIOCA_MULT_ERROR_MULT_INTB_MASK              0x1ull
#define TIOCA_MULT_ERROR_MULT_INTB_INPLACE (TIOCA_MULT_ERROR_MULT_INTB_MASK << TIOCA_MULT_ERROR_MULT_INTB_SHIFT)
#define TIOCA_MULT_ERROR_MULT_INTA_SHIFT             19 /* established */
#define TIOCA_MULT_ERROR_MULT_INTA_MASK              0x1ull
#define TIOCA_MULT_ERROR_MULT_INTA_INPLACE (TIOCA_MULT_ERROR_MULT_INTA_MASK << TIOCA_MULT_ERROR_MULT_INTA_SHIFT)
#define TIOCA_MULT_ERROR_INTB_SHIFT                  18 /* established */
#define TIOCA_MULT_ERROR_INTB_MASK                   0x1ull
#define TIOCA_MULT_ERROR_INTB_INPLACE (TIOCA_MULT_ERROR_INTB_MASK << TIOCA_MULT_ERROR_INTB_SHIFT)
#define TIOCA_MULT_ERROR_INTA_SHIFT                  17 /* established */
#define TIOCA_MULT_ERROR_INTA_MASK                   0x1ull
#define TIOCA_MULT_ERROR_INTA_INPLACE (TIOCA_MULT_ERROR_INTA_MASK << TIOCA_MULT_ERROR_INTA_SHIFT)
#define TIOCA_MULT_ERROR_SBA_TYPE1_ERR_SHIFT         15 /* established */
#define TIOCA_MULT_ERROR_SBA_TYPE1_ERR_MASK          0x1ull
#define TIOCA_MULT_ERROR_SBA_TYPE1_ERR_INPLACE (TIOCA_MULT_ERROR_SBA_TYPE1_ERR_MASK << TIOCA_MULT_ERROR_SBA_TYPE1_ERR_SHIFT)
#define TIOCA_MULT_ERROR_AGP_REQ_OFLOW_SHIFT         14 /* established */
#define TIOCA_MULT_ERROR_AGP_REQ_OFLOW_MASK          0x1ull
#define TIOCA_MULT_ERROR_AGP_REQ_OFLOW_INPLACE (TIOCA_MULT_ERROR_AGP_REQ_OFLOW_MASK << TIOCA_MULT_ERROR_AGP_REQ_OFLOW_SHIFT)
#define TIOCA_MULT_ERROR_PCI_ARB_TO_SHIFT            13 /* established */
#define TIOCA_MULT_ERROR_PCI_ARB_TO_MASK             0x1ull
#define TIOCA_MULT_ERROR_PCI_ARB_TO_INPLACE (TIOCA_MULT_ERROR_PCI_ARB_TO_MASK << TIOCA_MULT_ERROR_PCI_ARB_TO_SHIFT)
#define TIOCA_MULT_ERROR_PIO_INVALID_ADDR_SHIFT      12 /* established */
#define TIOCA_MULT_ERROR_PIO_INVALID_ADDR_MASK       0x1ull
#define TIOCA_MULT_ERROR_PIO_INVALID_ADDR_INPLACE (TIOCA_MULT_ERROR_PIO_INVALID_ADDR_MASK << TIOCA_MULT_ERROR_PIO_INVALID_ADDR_SHIFT)
#define TIOCA_MULT_ERROR_CXM_REQ_CRED_OVFLW_SHIFT    11 /* established */
#define TIOCA_MULT_ERROR_CXM_REQ_CRED_OVFLW_MASK     0x1ull
#define TIOCA_MULT_ERROR_CXM_REQ_CRED_OVFLW_INPLACE (TIOCA_MULT_ERROR_CXM_REQ_CRED_OVFLW_MASK << TIOCA_MULT_ERROR_CXM_REQ_CRED_OVFLW_SHIFT)
#define TIOCA_MULT_ERROR_CXM_RSP_CRED_OVFLW_SHIFT    10 /* established */
#define TIOCA_MULT_ERROR_CXM_RSP_CRED_OVFLW_MASK     0x1ull
#define TIOCA_MULT_ERROR_CXM_RSP_CRED_OVFLW_INPLACE (TIOCA_MULT_ERROR_CXM_RSP_CRED_OVFLW_MASK << TIOCA_MULT_ERROR_CXM_RSP_CRED_OVFLW_SHIFT)
#define TIOCA_MULT_ERROR_TNUMTO_SHIFT                9 /* established */
#define TIOCA_MULT_ERROR_TNUMTO_MASK                 0x1ull
#define TIOCA_MULT_ERROR_TNUMTO_INPLACE (TIOCA_MULT_ERROR_TNUMTO_MASK << TIOCA_MULT_ERROR_TNUMTO_SHIFT)
#define TIOCA_MULT_ERROR_CRM_DVERR_SHIFT             8 /* established */
#define TIOCA_MULT_ERROR_CRM_DVERR_MASK              0x1ull
#define TIOCA_MULT_ERROR_CRM_DVERR_INPLACE (TIOCA_MULT_ERROR_CRM_DVERR_MASK << TIOCA_MULT_ERROR_CRM_DVERR_SHIFT)
#define TIOCA_MULT_ERROR_CRM_PKTERR_SHIFT            7 /* established */
#define TIOCA_MULT_ERROR_CRM_PKTERR_MASK             0x1ull
#define TIOCA_MULT_ERROR_CRM_PKTERR_INPLACE (TIOCA_MULT_ERROR_CRM_PKTERR_MASK << TIOCA_MULT_ERROR_CRM_PKTERR_SHIFT)
#define TIOCA_MULT_ERROR_PIO_REQ_OVFLW_SHIFT         6 /* established */
#define TIOCA_MULT_ERROR_PIO_REQ_OVFLW_MASK          0x1ull
#define TIOCA_MULT_ERROR_PIO_REQ_OVFLW_INPLACE (TIOCA_MULT_ERROR_PIO_REQ_OVFLW_MASK << TIOCA_MULT_ERROR_PIO_REQ_OVFLW_SHIFT)
#define TIOCA_MULT_ERROR_GFX_WR_OVFLW_SHIFT          5 /* established */
#define TIOCA_MULT_ERROR_GFX_WR_OVFLW_MASK           0x1ull
#define TIOCA_MULT_ERROR_GFX_WR_OVFLW_INPLACE (TIOCA_MULT_ERROR_GFX_WR_OVFLW_MASK << TIOCA_MULT_ERROR_GFX_WR_OVFLW_SHIFT)
#define TIOCA_MULT_ERROR_GART_FETCH_ERR_SHIFT        4 /* established */
#define TIOCA_MULT_ERROR_GART_FETCH_ERR_MASK         0x1ull
#define TIOCA_MULT_ERROR_GART_FETCH_ERR_INPLACE (TIOCA_MULT_ERROR_GART_FETCH_ERR_MASK << TIOCA_MULT_ERROR_GART_FETCH_ERR_SHIFT)
#define TIOCA_MULT_ERROR_PCI_ERR_SHIFT               0 /* established */
#define TIOCA_MULT_ERROR_PCI_ERR_MASK                0x1ull
#define TIOCA_MULT_ERROR_PCI_ERR_INPLACE (TIOCA_MULT_ERROR_PCI_ERR_MASK << TIOCA_MULT_ERROR_PCI_ERR_SHIFT)

/*
 * Multiple-error write alias. The provider writes the GART fetch error bit here
 * to clear it, together with the status alias. Name and offset are the vendor
 * header's definition (struct member ca_mult_error_alias). The provider writes
 * the single bit it wants cleared here beside the status alias write. That a
 * written 1 clears the bit in the multiple-error register is inferred from the
 * provider's comment; readability is unknown, so rw stays as the widest access.
 * Reset value unknown: the header and provider state none, and no firmware
 * reading has been done.
 */
/* mult_error_alias: rw64, reset unknown */
#define TIOCA_MULT_ERROR_ALIAS                       0x000068 /* established */
#define TIOCA_MULT_ERROR_ALIAS_GFX_CREDIT_OVFLW_SHIFT 21 /* established */
#define TIOCA_MULT_ERROR_ALIAS_GFX_CREDIT_OVFLW_MASK 0x1ull
#define TIOCA_MULT_ERROR_ALIAS_GFX_CREDIT_OVFLW_INPLACE (TIOCA_MULT_ERROR_ALIAS_GFX_CREDIT_OVFLW_MASK << TIOCA_MULT_ERROR_ALIAS_GFX_CREDIT_OVFLW_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_MULT_INTB_SHIFT       20 /* established */
#define TIOCA_MULT_ERROR_ALIAS_MULT_INTB_MASK        0x1ull
#define TIOCA_MULT_ERROR_ALIAS_MULT_INTB_INPLACE (TIOCA_MULT_ERROR_ALIAS_MULT_INTB_MASK << TIOCA_MULT_ERROR_ALIAS_MULT_INTB_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_MULT_INTA_SHIFT       19 /* established */
#define TIOCA_MULT_ERROR_ALIAS_MULT_INTA_MASK        0x1ull
#define TIOCA_MULT_ERROR_ALIAS_MULT_INTA_INPLACE (TIOCA_MULT_ERROR_ALIAS_MULT_INTA_MASK << TIOCA_MULT_ERROR_ALIAS_MULT_INTA_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_INTB_SHIFT            18 /* established */
#define TIOCA_MULT_ERROR_ALIAS_INTB_MASK             0x1ull
#define TIOCA_MULT_ERROR_ALIAS_INTB_INPLACE (TIOCA_MULT_ERROR_ALIAS_INTB_MASK << TIOCA_MULT_ERROR_ALIAS_INTB_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_INTA_SHIFT            17 /* established */
#define TIOCA_MULT_ERROR_ALIAS_INTA_MASK             0x1ull
#define TIOCA_MULT_ERROR_ALIAS_INTA_INPLACE (TIOCA_MULT_ERROR_ALIAS_INTA_MASK << TIOCA_MULT_ERROR_ALIAS_INTA_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_SBA_TYPE1_ERR_SHIFT   15 /* established */
#define TIOCA_MULT_ERROR_ALIAS_SBA_TYPE1_ERR_MASK    0x1ull
#define TIOCA_MULT_ERROR_ALIAS_SBA_TYPE1_ERR_INPLACE (TIOCA_MULT_ERROR_ALIAS_SBA_TYPE1_ERR_MASK << TIOCA_MULT_ERROR_ALIAS_SBA_TYPE1_ERR_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_AGP_REQ_OFLOW_SHIFT   14 /* established */
#define TIOCA_MULT_ERROR_ALIAS_AGP_REQ_OFLOW_MASK    0x1ull
#define TIOCA_MULT_ERROR_ALIAS_AGP_REQ_OFLOW_INPLACE (TIOCA_MULT_ERROR_ALIAS_AGP_REQ_OFLOW_MASK << TIOCA_MULT_ERROR_ALIAS_AGP_REQ_OFLOW_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_PCI_ARB_TO_SHIFT      13 /* established */
#define TIOCA_MULT_ERROR_ALIAS_PCI_ARB_TO_MASK       0x1ull
#define TIOCA_MULT_ERROR_ALIAS_PCI_ARB_TO_INPLACE (TIOCA_MULT_ERROR_ALIAS_PCI_ARB_TO_MASK << TIOCA_MULT_ERROR_ALIAS_PCI_ARB_TO_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_PIO_INVALID_ADDR_SHIFT 12 /* established */
#define TIOCA_MULT_ERROR_ALIAS_PIO_INVALID_ADDR_MASK 0x1ull
#define TIOCA_MULT_ERROR_ALIAS_PIO_INVALID_ADDR_INPLACE (TIOCA_MULT_ERROR_ALIAS_PIO_INVALID_ADDR_MASK << TIOCA_MULT_ERROR_ALIAS_PIO_INVALID_ADDR_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_CXM_REQ_CRED_OVFLW_SHIFT 11 /* established */
#define TIOCA_MULT_ERROR_ALIAS_CXM_REQ_CRED_OVFLW_MASK 0x1ull
#define TIOCA_MULT_ERROR_ALIAS_CXM_REQ_CRED_OVFLW_INPLACE (TIOCA_MULT_ERROR_ALIAS_CXM_REQ_CRED_OVFLW_MASK << TIOCA_MULT_ERROR_ALIAS_CXM_REQ_CRED_OVFLW_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_CXM_RSP_CRED_OVFLW_SHIFT 10 /* established */
#define TIOCA_MULT_ERROR_ALIAS_CXM_RSP_CRED_OVFLW_MASK 0x1ull
#define TIOCA_MULT_ERROR_ALIAS_CXM_RSP_CRED_OVFLW_INPLACE (TIOCA_MULT_ERROR_ALIAS_CXM_RSP_CRED_OVFLW_MASK << TIOCA_MULT_ERROR_ALIAS_CXM_RSP_CRED_OVFLW_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_TNUMTO_SHIFT          9 /* established */
#define TIOCA_MULT_ERROR_ALIAS_TNUMTO_MASK           0x1ull
#define TIOCA_MULT_ERROR_ALIAS_TNUMTO_INPLACE (TIOCA_MULT_ERROR_ALIAS_TNUMTO_MASK << TIOCA_MULT_ERROR_ALIAS_TNUMTO_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_CRM_DVERR_SHIFT       8 /* established */
#define TIOCA_MULT_ERROR_ALIAS_CRM_DVERR_MASK        0x1ull
#define TIOCA_MULT_ERROR_ALIAS_CRM_DVERR_INPLACE (TIOCA_MULT_ERROR_ALIAS_CRM_DVERR_MASK << TIOCA_MULT_ERROR_ALIAS_CRM_DVERR_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_CRM_PKTERR_SHIFT      7 /* established */
#define TIOCA_MULT_ERROR_ALIAS_CRM_PKTERR_MASK       0x1ull
#define TIOCA_MULT_ERROR_ALIAS_CRM_PKTERR_INPLACE (TIOCA_MULT_ERROR_ALIAS_CRM_PKTERR_MASK << TIOCA_MULT_ERROR_ALIAS_CRM_PKTERR_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_PIO_REQ_OVFLW_SHIFT   6 /* established */
#define TIOCA_MULT_ERROR_ALIAS_PIO_REQ_OVFLW_MASK    0x1ull
#define TIOCA_MULT_ERROR_ALIAS_PIO_REQ_OVFLW_INPLACE (TIOCA_MULT_ERROR_ALIAS_PIO_REQ_OVFLW_MASK << TIOCA_MULT_ERROR_ALIAS_PIO_REQ_OVFLW_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_GFX_WR_OVFLW_SHIFT    5 /* established */
#define TIOCA_MULT_ERROR_ALIAS_GFX_WR_OVFLW_MASK     0x1ull
#define TIOCA_MULT_ERROR_ALIAS_GFX_WR_OVFLW_INPLACE (TIOCA_MULT_ERROR_ALIAS_GFX_WR_OVFLW_MASK << TIOCA_MULT_ERROR_ALIAS_GFX_WR_OVFLW_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_GART_FETCH_ERR_SHIFT  4 /* established */
#define TIOCA_MULT_ERROR_ALIAS_GART_FETCH_ERR_MASK   0x1ull
#define TIOCA_MULT_ERROR_ALIAS_GART_FETCH_ERR_INPLACE (TIOCA_MULT_ERROR_ALIAS_GART_FETCH_ERR_MASK << TIOCA_MULT_ERROR_ALIAS_GART_FETCH_ERR_SHIFT)
#define TIOCA_MULT_ERROR_ALIAS_PCI_ERR_SHIFT         0 /* established */
#define TIOCA_MULT_ERROR_ALIAS_PCI_ERR_MASK          0x1ull
#define TIOCA_MULT_ERROR_ALIAS_PCI_ERR_INPLACE (TIOCA_MULT_ERROR_ALIAS_PCI_ERR_MASK << TIOCA_MULT_ERROR_ALIAS_PCI_ERR_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_first_error). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* first_error: rw64, reset unknown */
#define TIOCA_FIRST_ERROR                            0x000070 /* established */
#define TIOCA_FIRST_ERROR_GFX_CREDIT_OVFLW_SHIFT     21 /* established */
#define TIOCA_FIRST_ERROR_GFX_CREDIT_OVFLW_MASK      0x1ull
#define TIOCA_FIRST_ERROR_GFX_CREDIT_OVFLW_INPLACE (TIOCA_FIRST_ERROR_GFX_CREDIT_OVFLW_MASK << TIOCA_FIRST_ERROR_GFX_CREDIT_OVFLW_SHIFT)
#define TIOCA_FIRST_ERROR_MULT_INTB_SHIFT            20 /* established */
#define TIOCA_FIRST_ERROR_MULT_INTB_MASK             0x1ull
#define TIOCA_FIRST_ERROR_MULT_INTB_INPLACE (TIOCA_FIRST_ERROR_MULT_INTB_MASK << TIOCA_FIRST_ERROR_MULT_INTB_SHIFT)
#define TIOCA_FIRST_ERROR_MULT_INTA_SHIFT            19 /* established */
#define TIOCA_FIRST_ERROR_MULT_INTA_MASK             0x1ull
#define TIOCA_FIRST_ERROR_MULT_INTA_INPLACE (TIOCA_FIRST_ERROR_MULT_INTA_MASK << TIOCA_FIRST_ERROR_MULT_INTA_SHIFT)
#define TIOCA_FIRST_ERROR_INTB_SHIFT                 18 /* established */
#define TIOCA_FIRST_ERROR_INTB_MASK                  0x1ull
#define TIOCA_FIRST_ERROR_INTB_INPLACE (TIOCA_FIRST_ERROR_INTB_MASK << TIOCA_FIRST_ERROR_INTB_SHIFT)
#define TIOCA_FIRST_ERROR_INTA_SHIFT                 17 /* established */
#define TIOCA_FIRST_ERROR_INTA_MASK                  0x1ull
#define TIOCA_FIRST_ERROR_INTA_INPLACE (TIOCA_FIRST_ERROR_INTA_MASK << TIOCA_FIRST_ERROR_INTA_SHIFT)
#define TIOCA_FIRST_ERROR_SBA_TYPE1_ERR_SHIFT        15 /* established */
#define TIOCA_FIRST_ERROR_SBA_TYPE1_ERR_MASK         0x1ull
#define TIOCA_FIRST_ERROR_SBA_TYPE1_ERR_INPLACE (TIOCA_FIRST_ERROR_SBA_TYPE1_ERR_MASK << TIOCA_FIRST_ERROR_SBA_TYPE1_ERR_SHIFT)
#define TIOCA_FIRST_ERROR_AGP_REQ_OFLOW_SHIFT        14 /* established */
#define TIOCA_FIRST_ERROR_AGP_REQ_OFLOW_MASK         0x1ull
#define TIOCA_FIRST_ERROR_AGP_REQ_OFLOW_INPLACE (TIOCA_FIRST_ERROR_AGP_REQ_OFLOW_MASK << TIOCA_FIRST_ERROR_AGP_REQ_OFLOW_SHIFT)
#define TIOCA_FIRST_ERROR_PCI_ARB_TO_SHIFT           13 /* established */
#define TIOCA_FIRST_ERROR_PCI_ARB_TO_MASK            0x1ull
#define TIOCA_FIRST_ERROR_PCI_ARB_TO_INPLACE (TIOCA_FIRST_ERROR_PCI_ARB_TO_MASK << TIOCA_FIRST_ERROR_PCI_ARB_TO_SHIFT)
#define TIOCA_FIRST_ERROR_PIO_INVALID_ADDR_SHIFT     12 /* established */
#define TIOCA_FIRST_ERROR_PIO_INVALID_ADDR_MASK      0x1ull
#define TIOCA_FIRST_ERROR_PIO_INVALID_ADDR_INPLACE (TIOCA_FIRST_ERROR_PIO_INVALID_ADDR_MASK << TIOCA_FIRST_ERROR_PIO_INVALID_ADDR_SHIFT)
#define TIOCA_FIRST_ERROR_CXM_REQ_CRED_OVFLW_SHIFT   11 /* established */
#define TIOCA_FIRST_ERROR_CXM_REQ_CRED_OVFLW_MASK    0x1ull
#define TIOCA_FIRST_ERROR_CXM_REQ_CRED_OVFLW_INPLACE (TIOCA_FIRST_ERROR_CXM_REQ_CRED_OVFLW_MASK << TIOCA_FIRST_ERROR_CXM_REQ_CRED_OVFLW_SHIFT)
#define TIOCA_FIRST_ERROR_CXM_RSP_CRED_OVFLW_SHIFT   10 /* established */
#define TIOCA_FIRST_ERROR_CXM_RSP_CRED_OVFLW_MASK    0x1ull
#define TIOCA_FIRST_ERROR_CXM_RSP_CRED_OVFLW_INPLACE (TIOCA_FIRST_ERROR_CXM_RSP_CRED_OVFLW_MASK << TIOCA_FIRST_ERROR_CXM_RSP_CRED_OVFLW_SHIFT)
#define TIOCA_FIRST_ERROR_TNUMTO_SHIFT               9 /* established */
#define TIOCA_FIRST_ERROR_TNUMTO_MASK                0x1ull
#define TIOCA_FIRST_ERROR_TNUMTO_INPLACE (TIOCA_FIRST_ERROR_TNUMTO_MASK << TIOCA_FIRST_ERROR_TNUMTO_SHIFT)
#define TIOCA_FIRST_ERROR_CRM_DVERR_SHIFT            8 /* established */
#define TIOCA_FIRST_ERROR_CRM_DVERR_MASK             0x1ull
#define TIOCA_FIRST_ERROR_CRM_DVERR_INPLACE (TIOCA_FIRST_ERROR_CRM_DVERR_MASK << TIOCA_FIRST_ERROR_CRM_DVERR_SHIFT)
#define TIOCA_FIRST_ERROR_CRM_PKTERR_SHIFT           7 /* established */
#define TIOCA_FIRST_ERROR_CRM_PKTERR_MASK            0x1ull
#define TIOCA_FIRST_ERROR_CRM_PKTERR_INPLACE (TIOCA_FIRST_ERROR_CRM_PKTERR_MASK << TIOCA_FIRST_ERROR_CRM_PKTERR_SHIFT)
#define TIOCA_FIRST_ERROR_PIO_REQ_OVFLW_SHIFT        6 /* established */
#define TIOCA_FIRST_ERROR_PIO_REQ_OVFLW_MASK         0x1ull
#define TIOCA_FIRST_ERROR_PIO_REQ_OVFLW_INPLACE (TIOCA_FIRST_ERROR_PIO_REQ_OVFLW_MASK << TIOCA_FIRST_ERROR_PIO_REQ_OVFLW_SHIFT)
#define TIOCA_FIRST_ERROR_GFX_WR_OVFLW_SHIFT         5 /* established */
#define TIOCA_FIRST_ERROR_GFX_WR_OVFLW_MASK          0x1ull
#define TIOCA_FIRST_ERROR_GFX_WR_OVFLW_INPLACE (TIOCA_FIRST_ERROR_GFX_WR_OVFLW_MASK << TIOCA_FIRST_ERROR_GFX_WR_OVFLW_SHIFT)
#define TIOCA_FIRST_ERROR_GART_FETCH_ERR_SHIFT       4 /* established */
#define TIOCA_FIRST_ERROR_GART_FETCH_ERR_MASK        0x1ull
#define TIOCA_FIRST_ERROR_GART_FETCH_ERR_INPLACE (TIOCA_FIRST_ERROR_GART_FETCH_ERR_MASK << TIOCA_FIRST_ERROR_GART_FETCH_ERR_SHIFT)
#define TIOCA_FIRST_ERROR_PCI_ERR_SHIFT              0 /* established */
#define TIOCA_FIRST_ERROR_PCI_ERR_MASK               0x1ull
#define TIOCA_FIRST_ERROR_PCI_ERR_INPLACE (TIOCA_FIRST_ERROR_PCI_ERR_MASK << TIOCA_FIRST_ERROR_PCI_ERR_SHIFT)

/*
 * Interrupt mask. The provider clears the GART fetch error bit (enables it);
 * the sense of the mask bit is the provider's use. Name and offset are the
 * vendor header's definition (struct member ca_int_mask). Access rw:
 * established as a software expectation (read-modify-write). The provider
 * clears the GART fetch error bit to unmask it, so a set bit masks the
 * interrupt: inferred from the unmask comment. Reset value unknown: the header
 * and provider state none, and no firmware reading has been done.
 */
/* int_mask: rw64, reset unknown */
#define TIOCA_INT_MASK                               0x000078 /* established */
#define TIOCA_INT_MASK_GFX_CREDIT_OVFLW_SHIFT        21 /* established */
#define TIOCA_INT_MASK_GFX_CREDIT_OVFLW_MASK         0x1ull
#define TIOCA_INT_MASK_GFX_CREDIT_OVFLW_INPLACE (TIOCA_INT_MASK_GFX_CREDIT_OVFLW_MASK << TIOCA_INT_MASK_GFX_CREDIT_OVFLW_SHIFT)
#define TIOCA_INT_MASK_MULT_INTB_SHIFT               20 /* established */
#define TIOCA_INT_MASK_MULT_INTB_MASK                0x1ull
#define TIOCA_INT_MASK_MULT_INTB_INPLACE (TIOCA_INT_MASK_MULT_INTB_MASK << TIOCA_INT_MASK_MULT_INTB_SHIFT)
#define TIOCA_INT_MASK_MULT_INTA_SHIFT               19 /* established */
#define TIOCA_INT_MASK_MULT_INTA_MASK                0x1ull
#define TIOCA_INT_MASK_MULT_INTA_INPLACE (TIOCA_INT_MASK_MULT_INTA_MASK << TIOCA_INT_MASK_MULT_INTA_SHIFT)
#define TIOCA_INT_MASK_INTB_SHIFT                    18 /* established */
#define TIOCA_INT_MASK_INTB_MASK                     0x1ull
#define TIOCA_INT_MASK_INTB_INPLACE (TIOCA_INT_MASK_INTB_MASK << TIOCA_INT_MASK_INTB_SHIFT)
#define TIOCA_INT_MASK_INTA_SHIFT                    17 /* established */
#define TIOCA_INT_MASK_INTA_MASK                     0x1ull
#define TIOCA_INT_MASK_INTA_INPLACE (TIOCA_INT_MASK_INTA_MASK << TIOCA_INT_MASK_INTA_SHIFT)
#define TIOCA_INT_MASK_SBA_TYPE1_ERR_SHIFT           15 /* established */
#define TIOCA_INT_MASK_SBA_TYPE1_ERR_MASK            0x1ull
#define TIOCA_INT_MASK_SBA_TYPE1_ERR_INPLACE (TIOCA_INT_MASK_SBA_TYPE1_ERR_MASK << TIOCA_INT_MASK_SBA_TYPE1_ERR_SHIFT)
#define TIOCA_INT_MASK_AGP_REQ_OFLOW_SHIFT           14 /* established */
#define TIOCA_INT_MASK_AGP_REQ_OFLOW_MASK            0x1ull
#define TIOCA_INT_MASK_AGP_REQ_OFLOW_INPLACE (TIOCA_INT_MASK_AGP_REQ_OFLOW_MASK << TIOCA_INT_MASK_AGP_REQ_OFLOW_SHIFT)
#define TIOCA_INT_MASK_PCI_ARB_TO_SHIFT              13 /* established */
#define TIOCA_INT_MASK_PCI_ARB_TO_MASK               0x1ull
#define TIOCA_INT_MASK_PCI_ARB_TO_INPLACE (TIOCA_INT_MASK_PCI_ARB_TO_MASK << TIOCA_INT_MASK_PCI_ARB_TO_SHIFT)
#define TIOCA_INT_MASK_PIO_INVALID_ADDR_SHIFT        12 /* established */
#define TIOCA_INT_MASK_PIO_INVALID_ADDR_MASK         0x1ull
#define TIOCA_INT_MASK_PIO_INVALID_ADDR_INPLACE (TIOCA_INT_MASK_PIO_INVALID_ADDR_MASK << TIOCA_INT_MASK_PIO_INVALID_ADDR_SHIFT)
#define TIOCA_INT_MASK_CXM_REQ_CRED_OVFLW_SHIFT      11 /* established */
#define TIOCA_INT_MASK_CXM_REQ_CRED_OVFLW_MASK       0x1ull
#define TIOCA_INT_MASK_CXM_REQ_CRED_OVFLW_INPLACE (TIOCA_INT_MASK_CXM_REQ_CRED_OVFLW_MASK << TIOCA_INT_MASK_CXM_REQ_CRED_OVFLW_SHIFT)
#define TIOCA_INT_MASK_CXM_RSP_CRED_OVFLW_SHIFT      10 /* established */
#define TIOCA_INT_MASK_CXM_RSP_CRED_OVFLW_MASK       0x1ull
#define TIOCA_INT_MASK_CXM_RSP_CRED_OVFLW_INPLACE (TIOCA_INT_MASK_CXM_RSP_CRED_OVFLW_MASK << TIOCA_INT_MASK_CXM_RSP_CRED_OVFLW_SHIFT)
#define TIOCA_INT_MASK_TNUMTO_SHIFT                  9 /* established */
#define TIOCA_INT_MASK_TNUMTO_MASK                   0x1ull
#define TIOCA_INT_MASK_TNUMTO_INPLACE (TIOCA_INT_MASK_TNUMTO_MASK << TIOCA_INT_MASK_TNUMTO_SHIFT)
#define TIOCA_INT_MASK_CRM_DVERR_SHIFT               8 /* established */
#define TIOCA_INT_MASK_CRM_DVERR_MASK                0x1ull
#define TIOCA_INT_MASK_CRM_DVERR_INPLACE (TIOCA_INT_MASK_CRM_DVERR_MASK << TIOCA_INT_MASK_CRM_DVERR_SHIFT)
#define TIOCA_INT_MASK_CRM_PKTERR_SHIFT              7 /* established */
#define TIOCA_INT_MASK_CRM_PKTERR_MASK               0x1ull
#define TIOCA_INT_MASK_CRM_PKTERR_INPLACE (TIOCA_INT_MASK_CRM_PKTERR_MASK << TIOCA_INT_MASK_CRM_PKTERR_SHIFT)
#define TIOCA_INT_MASK_PIO_REQ_OVFLW_SHIFT           6 /* established */
#define TIOCA_INT_MASK_PIO_REQ_OVFLW_MASK            0x1ull
#define TIOCA_INT_MASK_PIO_REQ_OVFLW_INPLACE (TIOCA_INT_MASK_PIO_REQ_OVFLW_MASK << TIOCA_INT_MASK_PIO_REQ_OVFLW_SHIFT)
#define TIOCA_INT_MASK_GFX_WR_OVFLW_SHIFT            5 /* established */
#define TIOCA_INT_MASK_GFX_WR_OVFLW_MASK             0x1ull
#define TIOCA_INT_MASK_GFX_WR_OVFLW_INPLACE (TIOCA_INT_MASK_GFX_WR_OVFLW_MASK << TIOCA_INT_MASK_GFX_WR_OVFLW_SHIFT)
#define TIOCA_INT_MASK_GART_FETCH_ERR_SHIFT          4 /* established */
#define TIOCA_INT_MASK_GART_FETCH_ERR_MASK           0x1ull
#define TIOCA_INT_MASK_GART_FETCH_ERR_INPLACE (TIOCA_INT_MASK_GART_FETCH_ERR_MASK << TIOCA_INT_MASK_GART_FETCH_ERR_SHIFT)
#define TIOCA_INT_MASK_PCI_ERR_SHIFT                 0 /* established */
#define TIOCA_INT_MASK_PCI_ERR_MASK                  0x1ull
#define TIOCA_INT_MASK_PCI_ERR_INPLACE (TIOCA_INT_MASK_PCI_ERR_MASK << TIOCA_INT_MASK_PCI_ERR_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_crm_pkterr_type). Software never touches this register in the code read,
 * so access direction is unknown and rw is a placeholder. Reset value unknown:
 * the header and provider state none, and no firmware reading has been done.
 */
/* crm_pkterr_type: rw64, reset unknown */
#define TIOCA_CRM_PKTERR_TYPE                        0x000080 /* established */
/* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_MSSNG_HDR_SHIFT 28
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_MSSNG_HDR_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_MSSNG_HDR_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_MSSNG_HDR_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_MSSNG_HDR_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_MSSNG_TAIL_SHIFT 27
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_MSSNG_TAIL_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_MSSNG_TAIL_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_MSSNG_TAIL_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_MSSNG_TAIL_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_EARLY_TAIL_SHIFT 26
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_EARLY_TAIL_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_EARLY_TAIL_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_EARLY_TAIL_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_EARLY_TAIL_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_EARLY_TERM_SHIFT 25
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_EARLY_TERM_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_EARLY_TERM_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_EARLY_TERM_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_EARLY_TERM_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_SBERR_NH_SHIFT 24
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_SBERR_NH_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_SBERR_NH_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_SBERR_NH_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_SBERR_NH_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_CW_ERR_SHIFT 23 /* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_CW_ERR_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_CW_ERR_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_CW_ERR_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_CW_ERR_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_HDR_PARAM_SHIFT 22
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_HDR_PARAM_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_HDR_PARAM_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_HDR_PARAM_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_HDR_PARAM_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_ADDR_ALGN_SHIFT 21
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_ADDR_ALGN_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_ADDR_ALGN_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_ADDR_ALGN_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_ADDR_ALGN_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_ADDR_RNG_SHIFT 20
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_ADDR_RNG_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_ADDR_RNG_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_ADDR_RNG_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_ADDR_RNG_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_INV_TNUM_SHIFT 19
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_INV_TNUM_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_INV_TNUM_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_INV_TNUM_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_INV_TNUM_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_PACTYPE_SHIFT 18
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_PACTYPE_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_PACTYPE_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_PACTYPE_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_PACTYPE_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_DIDN_SHIFT 17 /* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_DIDN_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_DIDN_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_DIDN_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_DIDN_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_SBERR_HDR_SHIFT 16
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_SBERR_HDR_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_SBERR_HDR_INPLACE (TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_SBERR_HDR_MASK << TIOCA_CRM_PKTERR_TYPE_FIRST_CRM_PKTERR_SBERR_HDR_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_MSSNG_HDR_SHIFT 12 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_MSSNG_HDR_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_MSSNG_HDR_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_MSSNG_HDR_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_MSSNG_HDR_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_MSSNG_TAIL_SHIFT 11 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_MSSNG_TAIL_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_MSSNG_TAIL_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_MSSNG_TAIL_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_MSSNG_TAIL_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_EARLY_TAIL_SHIFT 10 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_EARLY_TAIL_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_EARLY_TAIL_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_EARLY_TAIL_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_EARLY_TAIL_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_EARLY_TERM_SHIFT 9 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_EARLY_TERM_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_EARLY_TERM_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_EARLY_TERM_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_EARLY_TERM_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_SBERR_NH_SHIFT 8 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_SBERR_NH_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_SBERR_NH_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_SBERR_NH_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_SBERR_NH_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_CW_ERR_SHIFT 7 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_CW_ERR_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_CW_ERR_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_CW_ERR_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_CW_ERR_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_HDR_PARAM_SHIFT 6 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_HDR_PARAM_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_HDR_PARAM_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_HDR_PARAM_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_HDR_PARAM_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_ADDR_ALGN_SHIFT 5 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_ADDR_ALGN_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_ADDR_ALGN_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_ADDR_ALGN_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_ADDR_ALGN_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_ADDR_RNG_SHIFT 4 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_ADDR_RNG_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_ADDR_RNG_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_ADDR_RNG_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_ADDR_RNG_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_INV_TNUM_SHIFT 3 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_INV_TNUM_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_INV_TNUM_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_INV_TNUM_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_INV_TNUM_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_PACTYPE_SHIFT 2 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_PACTYPE_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_PACTYPE_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_PACTYPE_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_PACTYPE_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_DIDN_SHIFT  1 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_DIDN_MASK   0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_DIDN_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_DIDN_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_DIDN_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_SBERR_HDR_SHIFT 0 /* established */
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_SBERR_HDR_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_SBERR_HDR_INPLACE (TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_SBERR_HDR_MASK << TIOCA_CRM_PKTERR_TYPE_CRM_PKTERR_SBERR_HDR_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_crm_pkterr_type_alias). Software never touches this register in the code
 * read, so access direction is unknown and rw is a placeholder. Reset value
 * unknown: the header and provider state none, and no firmware reading has been
 * done.
 */
/* crm_pkterr_type_alias: rw64, reset unknown */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS                  0x000088 /* established */
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_MSSNG_HDR_SHIFT 28
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_MSSNG_HDR_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_MSSNG_HDR_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_MSSNG_HDR_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_MSSNG_HDR_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_MSSNG_TAIL_SHIFT 27
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_MSSNG_TAIL_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_MSSNG_TAIL_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_MSSNG_TAIL_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_MSSNG_TAIL_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_EARLY_TAIL_SHIFT 26
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_EARLY_TAIL_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_EARLY_TAIL_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_EARLY_TAIL_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_EARLY_TAIL_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_EARLY_TERM_SHIFT 25
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_EARLY_TERM_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_EARLY_TERM_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_EARLY_TERM_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_EARLY_TERM_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_SBERR_NH_SHIFT 24
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_SBERR_NH_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_SBERR_NH_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_SBERR_NH_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_SBERR_NH_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_CW_ERR_SHIFT 23
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_CW_ERR_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_CW_ERR_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_CW_ERR_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_CW_ERR_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_HDR_PARAM_SHIFT 22
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_HDR_PARAM_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_HDR_PARAM_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_HDR_PARAM_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_HDR_PARAM_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_ADDR_ALGN_SHIFT 21
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_ADDR_ALGN_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_ADDR_ALGN_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_ADDR_ALGN_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_ADDR_ALGN_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_ADDR_RNG_SHIFT 20
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_ADDR_RNG_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_ADDR_RNG_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_ADDR_RNG_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_ADDR_RNG_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_INV_TNUM_SHIFT 19
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_INV_TNUM_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_INV_TNUM_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_INV_TNUM_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_INV_TNUM_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_PACTYPE_SHIFT 18
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_PACTYPE_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_PACTYPE_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_PACTYPE_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_PACTYPE_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_DIDN_SHIFT 17
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_DIDN_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_DIDN_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_DIDN_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_DIDN_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_SBERR_HDR_SHIFT 16
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_SBERR_HDR_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_SBERR_HDR_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_SBERR_HDR_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_FIRST_CRM_PKTERR_SBERR_HDR_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_MSSNG_HDR_SHIFT 12
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_MSSNG_HDR_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_MSSNG_HDR_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_MSSNG_HDR_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_MSSNG_HDR_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_MSSNG_TAIL_SHIFT 11
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_MSSNG_TAIL_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_MSSNG_TAIL_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_MSSNG_TAIL_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_MSSNG_TAIL_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_EARLY_TAIL_SHIFT 10
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_EARLY_TAIL_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_EARLY_TAIL_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_EARLY_TAIL_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_EARLY_TAIL_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_EARLY_TERM_SHIFT 9
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_EARLY_TERM_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_EARLY_TERM_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_EARLY_TERM_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_EARLY_TERM_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_SBERR_NH_SHIFT 8
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_SBERR_NH_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_SBERR_NH_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_SBERR_NH_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_SBERR_NH_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_CW_ERR_SHIFT 7 /* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_CW_ERR_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_CW_ERR_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_CW_ERR_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_CW_ERR_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_HDR_PARAM_SHIFT 6
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_HDR_PARAM_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_HDR_PARAM_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_HDR_PARAM_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_HDR_PARAM_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_ADDR_ALGN_SHIFT 5
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_ADDR_ALGN_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_ADDR_ALGN_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_ADDR_ALGN_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_ADDR_ALGN_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_ADDR_RNG_SHIFT 4
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_ADDR_RNG_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_ADDR_RNG_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_ADDR_RNG_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_ADDR_RNG_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_INV_TNUM_SHIFT 3
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_INV_TNUM_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_INV_TNUM_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_INV_TNUM_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_INV_TNUM_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_PACTYPE_SHIFT 2 /* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_PACTYPE_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_PACTYPE_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_PACTYPE_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_PACTYPE_SHIFT)
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_DIDN_SHIFT 1 /* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_DIDN_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_DIDN_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_DIDN_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_DIDN_SHIFT)
/* established */
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_SBERR_HDR_SHIFT 0
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_SBERR_HDR_MASK 0x1ull
#define TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_SBERR_HDR_INPLACE (TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_SBERR_HDR_MASK << TIOCA_CRM_PKTERR_TYPE_ALIAS_CRM_PKTERR_SBERR_HDR_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_crm_ct_error_detail_1). Software never touches this register in the code
 * read, so access direction is unknown and rw is a placeholder. Reset value
 * unknown: the header and provider state none, and no firmware reading has been
 * done.
 */
/* crm_ct_error_detail_1: rw64, reset unknown */
#define TIOCA_CRM_CT_ERROR_DETAIL_1                  0x000090 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_1_VALID_SHIFT      63 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_1_VALID_MASK       0x1ull
#define TIOCA_CRM_CT_ERROR_DETAIL_1_VALID_INPLACE (TIOCA_CRM_CT_ERROR_DETAIL_1_VALID_MASK << TIOCA_CRM_CT_ERROR_DETAIL_1_VALID_SHIFT)
#define TIOCA_CRM_CT_ERROR_DETAIL_1_CW_ERR_SHIFT     35 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_1_CW_ERR_MASK      0x1ull
#define TIOCA_CRM_CT_ERROR_DETAIL_1_CW_ERR_INPLACE (TIOCA_CRM_CT_ERROR_DETAIL_1_CW_ERR_MASK << TIOCA_CRM_CT_ERROR_DETAIL_1_CW_ERR_SHIFT)
#define TIOCA_CRM_CT_ERROR_DETAIL_1_PIO_OP_SHIFT     34 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_1_PIO_OP_MASK      0x1ull
#define TIOCA_CRM_CT_ERROR_DETAIL_1_PIO_OP_INPLACE (TIOCA_CRM_CT_ERROR_DETAIL_1_PIO_OP_MASK << TIOCA_CRM_CT_ERROR_DETAIL_1_PIO_OP_SHIFT)
#define TIOCA_CRM_CT_ERROR_DETAIL_1_MEM_RD_PARAM_SHIFT 32 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_1_MEM_RD_PARAM_MASK 0x3ull
#define TIOCA_CRM_CT_ERROR_DETAIL_1_MEM_RD_PARAM_INPLACE (TIOCA_CRM_CT_ERROR_DETAIL_1_MEM_RD_PARAM_MASK << TIOCA_CRM_CT_ERROR_DETAIL_1_MEM_RD_PARAM_SHIFT)
#define TIOCA_CRM_CT_ERROR_DETAIL_1_GFX_CRED_SHIFT   24 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_1_GFX_CRED_MASK    0xffull
#define TIOCA_CRM_CT_ERROR_DETAIL_1_GFX_CRED_INPLACE (TIOCA_CRM_CT_ERROR_DETAIL_1_GFX_CRED_MASK << TIOCA_CRM_CT_ERROR_DETAIL_1_GFX_CRED_SHIFT)
#define TIOCA_CRM_CT_ERROR_DETAIL_1_DW_DATA_EN_SHIFT 16 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_1_DW_DATA_EN_MASK  0xffull
#define TIOCA_CRM_CT_ERROR_DETAIL_1_DW_DATA_EN_INPLACE (TIOCA_CRM_CT_ERROR_DETAIL_1_DW_DATA_EN_MASK << TIOCA_CRM_CT_ERROR_DETAIL_1_DW_DATA_EN_SHIFT)
#define TIOCA_CRM_CT_ERROR_DETAIL_1_TNUM_SHIFT       8 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_1_TNUM_MASK        0xffull
#define TIOCA_CRM_CT_ERROR_DETAIL_1_TNUM_INPLACE (TIOCA_CRM_CT_ERROR_DETAIL_1_TNUM_MASK << TIOCA_CRM_CT_ERROR_DETAIL_1_TNUM_SHIFT)
#define TIOCA_CRM_CT_ERROR_DETAIL_1_DATA_SZ_SHIFT    6 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_1_DATA_SZ_MASK     0x3ull
#define TIOCA_CRM_CT_ERROR_DETAIL_1_DATA_SZ_INPLACE (TIOCA_CRM_CT_ERROR_DETAIL_1_DATA_SZ_MASK << TIOCA_CRM_CT_ERROR_DETAIL_1_DATA_SZ_SHIFT)
#define TIOCA_CRM_CT_ERROR_DETAIL_1_SRC_ID_SHIFT     4 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_1_SRC_ID_MASK      0x3ull
#define TIOCA_CRM_CT_ERROR_DETAIL_1_SRC_ID_INPLACE (TIOCA_CRM_CT_ERROR_DETAIL_1_SRC_ID_MASK << TIOCA_CRM_CT_ERROR_DETAIL_1_SRC_ID_SHIFT)
#define TIOCA_CRM_CT_ERROR_DETAIL_1_PKT_TYPE_SHIFT   0 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_1_PKT_TYPE_MASK    0xfull
#define TIOCA_CRM_CT_ERROR_DETAIL_1_PKT_TYPE_INPLACE (TIOCA_CRM_CT_ERROR_DETAIL_1_PKT_TYPE_MASK << TIOCA_CRM_CT_ERROR_DETAIL_1_PKT_TYPE_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_crm_ct_error_detail_2). Software never touches this register in the code
 * read, so access direction is unknown and rw is a placeholder. Reset value
 * unknown: the header and provider state none, and no firmware reading has been
 * done.
 */
/* crm_ct_error_detail_2: rw64, reset unknown */
#define TIOCA_CRM_CT_ERROR_DETAIL_2                  0x000098 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_2_PKT_ADDR_SHIFT   3 /* established */
#define TIOCA_CRM_CT_ERROR_DETAIL_2_PKT_ADDR_MASK    0x1fffffffffffffull
#define TIOCA_CRM_CT_ERROR_DETAIL_2_PKT_ADDR_INPLACE (TIOCA_CRM_CT_ERROR_DETAIL_2_PKT_ADDR_MASK << TIOCA_CRM_CT_ERROR_DETAIL_2_PKT_ADDR_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_crm_tnumto). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* crm_tnumto: rw64, reset unknown */
#define TIOCA_CRM_TNUMTO                             0x0000a0 /* established */
#define TIOCA_CRM_TNUMTO_CRM_TNUMTO_WR_SHIFT         8 /* established */
#define TIOCA_CRM_TNUMTO_CRM_TNUMTO_WR_MASK          0x1ull
#define TIOCA_CRM_TNUMTO_CRM_TNUMTO_WR_INPLACE (TIOCA_CRM_TNUMTO_CRM_TNUMTO_WR_MASK << TIOCA_CRM_TNUMTO_CRM_TNUMTO_WR_SHIFT)
#define TIOCA_CRM_TNUMTO_CRM_TNUMTO_VAL_SHIFT        0 /* established */
#define TIOCA_CRM_TNUMTO_CRM_TNUMTO_VAL_MASK         0xffull
#define TIOCA_CRM_TNUMTO_CRM_TNUMTO_VAL_INPLACE (TIOCA_CRM_TNUMTO_CRM_TNUMTO_VAL_MASK << TIOCA_CRM_TNUMTO_CRM_TNUMTO_VAL_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_gart_err). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* gart_err: rw64, reset unknown */
#define TIOCA_GART_ERR                               0x0000a8 /* established */
#define TIOCA_GART_ERR_GART_ERR_ADDR_SHIFT           4 /* established */
#define TIOCA_GART_ERR_GART_ERR_ADDR_MASK            0xfffffffffull
#define TIOCA_GART_ERR_GART_ERR_ADDR_INPLACE (TIOCA_GART_ERR_GART_ERR_ADDR_MASK << TIOCA_GART_ERR_GART_ERR_ADDR_SHIFT)
#define TIOCA_GART_ERR_GART_ERR_SOURCE_SHIFT         0 /* established */
#define TIOCA_GART_ERR_GART_ERR_SOURCE_MASK          0x3ull
#define TIOCA_GART_ERR_GART_ERR_SOURCE_INPLACE (TIOCA_GART_ERR_GART_ERR_SOURCE_MASK << TIOCA_GART_ERR_GART_ERR_SOURCE_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_pcierr_type). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* pcierr_type: rw64, reset unknown */
#define TIOCA_PCIERR_TYPE                            0x0000b0 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_MST_RETRY_TOUT_SHIFT 49 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_MST_RETRY_TOUT_MASK 0x1ull
#define TIOCA_PCIERR_TYPE_PCIERR_MST_RETRY_TOUT_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_MST_RETRY_TOUT_MASK << TIOCA_PCIERR_TYPE_PCIERR_MST_RETRY_TOUT_SHIFT)
#define TIOCA_PCIERR_TYPE_PCIERR_MST_TABT_SHIFT      48 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_MST_TABT_MASK       0x1ull
#define TIOCA_PCIERR_TYPE_PCIERR_MST_TABT_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_MST_TABT_MASK << TIOCA_PCIERR_TYPE_PCIERR_MST_TABT_SHIFT)
#define TIOCA_PCIERR_TYPE_PCIERR_MST_MABT_SHIFT      47 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_MST_MABT_MASK       0x1ull
#define TIOCA_PCIERR_TYPE_PCIERR_MST_MABT_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_MST_MABT_MASK << TIOCA_PCIERR_TYPE_PCIERR_MST_MABT_SHIFT)
#define TIOCA_PCIERR_TYPE_PCIERR_MST_RD_PERR_SHIFT   46 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_MST_RD_PERR_MASK    0x1ull
#define TIOCA_PCIERR_TYPE_PCIERR_MST_RD_PERR_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_MST_RD_PERR_MASK << TIOCA_PCIERR_TYPE_PCIERR_MST_RD_PERR_SHIFT)
#define TIOCA_PCIERR_TYPE_PCIERR_MST_WR_PERR_SHIFT   45 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_MST_WR_PERR_MASK    0x1ull
#define TIOCA_PCIERR_TYPE_PCIERR_MST_WR_PERR_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_MST_WR_PERR_MASK << TIOCA_PCIERR_TYPE_PCIERR_MST_WR_PERR_SHIFT)
#define TIOCA_PCIERR_TYPE_PCIERR_MST_SERR_SHIFT      44 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_MST_SERR_MASK       0x1ull
#define TIOCA_PCIERR_TYPE_PCIERR_MST_SERR_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_MST_SERR_MASK << TIOCA_PCIERR_TYPE_PCIERR_MST_SERR_SHIFT)
#define TIOCA_PCIERR_TYPE_PCIERR_SLV_RD_PERR_SHIFT   43 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_SLV_RD_PERR_MASK    0x1ull
#define TIOCA_PCIERR_TYPE_PCIERR_SLV_RD_PERR_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_SLV_RD_PERR_MASK << TIOCA_PCIERR_TYPE_PCIERR_SLV_RD_PERR_SHIFT)
#define TIOCA_PCIERR_TYPE_PCIERR_SLV_WR_PERR_SHIFT   42 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_SLV_WR_PERR_MASK    0x1ull
#define TIOCA_PCIERR_TYPE_PCIERR_SLV_WR_PERR_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_SLV_WR_PERR_MASK << TIOCA_PCIERR_TYPE_PCIERR_SLV_WR_PERR_SHIFT)
#define TIOCA_PCIERR_TYPE_PCIERR_SLV_SERR_SHIFT      41 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_SLV_SERR_MASK       0x1ull
#define TIOCA_PCIERR_TYPE_PCIERR_SLV_SERR_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_SLV_SERR_MASK << TIOCA_PCIERR_TYPE_PCIERR_SLV_SERR_SHIFT)
#define TIOCA_PCIERR_TYPE_PCIERR_A64_SHIFT           40 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_A64_MASK            0x1ull
#define TIOCA_PCIERR_TYPE_PCIERR_A64_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_A64_MASK << TIOCA_PCIERR_TYPE_PCIERR_A64_SHIFT)
#define TIOCA_PCIERR_TYPE_PCIERR_CMD_SHIFT           36 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_CMD_MASK            0xfull
#define TIOCA_PCIERR_TYPE_PCIERR_CMD_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_CMD_MASK << TIOCA_PCIERR_TYPE_PCIERR_CMD_SHIFT)
#define TIOCA_PCIERR_TYPE_PCIERR_ENB_SHIFT           32 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_ENB_MASK            0xfull
#define TIOCA_PCIERR_TYPE_PCIERR_ENB_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_ENB_MASK << TIOCA_PCIERR_TYPE_PCIERR_ENB_SHIFT)
#define TIOCA_PCIERR_TYPE_PCIERR_DATA_SHIFT          0 /* established */
#define TIOCA_PCIERR_TYPE_PCIERR_DATA_MASK           0xffffffffull
#define TIOCA_PCIERR_TYPE_PCIERR_DATA_INPLACE (TIOCA_PCIERR_TYPE_PCIERR_DATA_MASK << TIOCA_PCIERR_TYPE_PCIERR_DATA_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_pcierr_addr). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* pcierr_addr: rw64, reset unknown */
#define TIOCA_PCIERR_ADDR                            0x0000b8 /* established */

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_pci_rd_buf_flush). Software never touches this register in the code read,
 * so access direction is unknown and rw is a placeholder. Reset value unknown:
 * the header and provider state none, and no firmware reading has been done.
 */
/* pci_rd_buf_flush: rw64, reset unknown */
#define TIOCA_PCI_RD_BUF_FLUSH                       0x0000d8 /* established */

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_pci_dma_addr_extn). Software never touches this register in the code read,
 * so access direction is unknown and rw is a placeholder. Reset value unknown:
 * the header and provider state none, and no firmware reading has been done.
 */
/* pci_dma_addr_extn: rw64, reset unknown */
#define TIOCA_PCI_DMA_ADDR_EXTN                      0x0000e0 /* established */
#define TIOCA_PCI_DMA_ADDR_EXTN_PCI_DMA_PIO_MEM_TYPE_SHIFT 28 /* established */
#define TIOCA_PCI_DMA_ADDR_EXTN_PCI_DMA_PIO_MEM_TYPE_MASK 0x1ull
#define TIOCA_PCI_DMA_ADDR_EXTN_PCI_DMA_PIO_MEM_TYPE_INPLACE (TIOCA_PCI_DMA_ADDR_EXTN_PCI_DMA_PIO_MEM_TYPE_MASK << TIOCA_PCI_DMA_ADDR_EXTN_PCI_DMA_PIO_MEM_TYPE_SHIFT)
#define TIOCA_PCI_DMA_ADDR_EXTN_PCI_DMA_NODE_ID_SHIFT 12 /* established */
#define TIOCA_PCI_DMA_ADDR_EXTN_PCI_DMA_NODE_ID_MASK 0xffffull
#define TIOCA_PCI_DMA_ADDR_EXTN_PCI_DMA_NODE_ID_INPLACE (TIOCA_PCI_DMA_ADDR_EXTN_PCI_DMA_NODE_ID_MASK << TIOCA_PCI_DMA_ADDR_EXTN_PCI_DMA_NODE_ID_SHIFT)
#define TIOCA_PCI_DMA_ADDR_EXTN_CHIPLET_ID_SHIFT     8 /* established */
#define TIOCA_PCI_DMA_ADDR_EXTN_CHIPLET_ID_MASK      0x3ull
#define TIOCA_PCI_DMA_ADDR_EXTN_CHIPLET_ID_INPLACE (TIOCA_PCI_DMA_ADDR_EXTN_CHIPLET_ID_MASK << TIOCA_PCI_DMA_ADDR_EXTN_CHIPLET_ID_SHIFT)
#define TIOCA_PCI_DMA_ADDR_EXTN_UPPER_NODE_OFFSET_SHIFT 0 /* established */
#define TIOCA_PCI_DMA_ADDR_EXTN_UPPER_NODE_OFFSET_MASK 0x3full
#define TIOCA_PCI_DMA_ADDR_EXTN_UPPER_NODE_OFFSET_INPLACE (TIOCA_PCI_DMA_ADDR_EXTN_UPPER_NODE_OFFSET_MASK << TIOCA_PCI_DMA_ADDR_EXTN_UPPER_NODE_OFFSET_SHIFT)

/*
 * AGP DMA address extension. The 48-bit direct AGP DMA path reads it and
 * requires its node-id field to equal the upper node bits of the target; the
 * node-id field is 16 bits wide at bit 20, which overlaps the pio-mem-type bit
 * 28 the header also names (see the unit page). Name and offset are the vendor
 * header's definition (struct member ca_agp_dma_addr_extn). The 48-bit direct
 * AGP path reads it (established), so it is readable. Whether software or
 * firmware writes it is not shown by the code read; rw stays as the widest
 * access, write direction unknown. Reset value unknown: the header and provider
 * state none, and no firmware reading has been done.
 */
/* agp_dma_addr_extn: rw64, reset unknown */
#define TIOCA_AGP_DMA_ADDR_EXTN                      0x0000e8 /* established */
#define TIOCA_AGP_DMA_ADDR_EXTN_AGP_DMA_NODE_ID_SHIFT 20 /* established */
#define TIOCA_AGP_DMA_ADDR_EXTN_AGP_DMA_NODE_ID_MASK 0xffffull
#define TIOCA_AGP_DMA_ADDR_EXTN_AGP_DMA_NODE_ID_INPLACE (TIOCA_AGP_DMA_ADDR_EXTN_AGP_DMA_NODE_ID_MASK << TIOCA_AGP_DMA_ADDR_EXTN_AGP_DMA_NODE_ID_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_force_inta). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* force_inta: rw64, reset unknown */
#define TIOCA_FORCE_INTA                             0x0000f0 /* established */

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_force_intb). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* force_intb: rw64, reset unknown */
#define TIOCA_FORCE_INTB                             0x0000f8 /* established */

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_debug_vector_sel). Software never touches this register in the code read,
 * so access direction is unknown and rw is a placeholder. Reset value unknown:
 * the header and provider state none, and no firmware reading has been done.
 */
/* debug_vector_sel: rw64, reset unknown */
#define TIOCA_DEBUG_VECTOR_SEL                       0x000100 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PM_VSEL_SHIFT   56 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PM_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PM_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_PM_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_PM_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PS_VSEL_SHIFT   52 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PS_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PS_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_PS_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_PS_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_AS_VSEL_SHIFT   48 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_AS_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_AS_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_AS_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_AS_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_BI_VSEL_SHIFT   44 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_BI_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_BI_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_BI_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_BI_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_BO_VSEL_SHIFT   40 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_BO_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_BO_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_BO_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_BO_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PE_VSEL_SHIFT   36 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PE_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PE_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_PE_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_PE_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_BA_VSEL_SHIFT   32 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_BA_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_BA_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_BA_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_BA_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_CR_VSEL_SHIFT   28 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_CR_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_CR_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_CR_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_CR_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_CX_VSEL_SHIFT   24 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_CX_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_CX_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_CX_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_CX_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_AD_VSEL_SHIFT   20 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_AD_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_AD_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_AD_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_AD_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PD_VSEL_SHIFT   16 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PD_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PD_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_PD_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_PD_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_GT_VSEL_SHIFT   12 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_GT_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_GT_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_GT_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_GT_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_GW_VSEL_SHIFT   8 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_GW_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_GW_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_GW_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_GW_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PP_VSEL_SHIFT   4 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PP_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_PP_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_PP_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_PP_VSEL_SHIFT)
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_MN_VSEL_SHIFT   0 /* established */
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_MN_VSEL_MASK    0xfull
#define TIOCA_DEBUG_VECTOR_SEL_DEBUG_MN_VSEL_INPLACE (TIOCA_DEBUG_VECTOR_SEL_DEBUG_MN_VSEL_MASK << TIOCA_DEBUG_VECTOR_SEL_DEBUG_MN_VSEL_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_debug_mux_core_sel). Software never touches this register in the code
 * read, so access direction is unknown and rw is a placeholder. Reset value
 * unknown: the header and provider state none, and no firmware reading has been
 * done.
 */
/* debug_mux_core_sel: rw64, reset unknown */
#define TIOCA_DEBUG_MUX_CORE_SEL                     0x000108 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL7_SHIFT   60 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL7_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL7_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL7_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL7_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL7_SHIFT   56 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL7_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL7_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL7_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL7_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL6_SHIFT   52 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL6_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL6_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL6_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL6_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL6_SHIFT   48 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL6_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL6_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL6_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL6_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL5_SHIFT   44 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL5_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL5_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL5_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL5_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL5_SHIFT   40 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL5_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL5_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL5_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL5_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL4_SHIFT   36 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL4_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL4_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL4_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL4_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL4_SHIFT   32 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL4_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL4_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL4_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL4_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL3_SHIFT   28 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL3_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL3_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL3_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL3_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL3_SHIFT   24 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL3_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL3_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL3_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL3_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL2_SHIFT   20 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL2_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL2_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL2_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL2_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL2_SHIFT   16 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL2_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL2_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL2_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL2_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL1_SHIFT   12 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL1_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL1_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL1_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL1_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL1_SHIFT   8 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL1_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL1_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL1_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL1_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL0_SHIFT   4 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL0_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL0_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL0_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_NSEL0_SHIFT)
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL0_SHIFT   0 /* established */
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL0_MASK    0x7ull
#define TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL0_INPLACE (TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL0_MASK << TIOCA_DEBUG_MUX_CORE_SEL_DEBUG_MSEL0_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_debug_mux_pci_sel). Software never touches this register in the code read,
 * so access direction is unknown and rw is a placeholder. Reset value unknown:
 * the header and provider state none, and no firmware reading has been done.
 */
/* debug_mux_pci_sel: rw64, reset unknown */
#define TIOCA_DEBUG_MUX_PCI_SEL                      0x000110 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL7_SHIFT    60 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL7_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL7_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL7_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL7_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL7_SHIFT    56 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL7_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL7_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL7_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL7_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL6_SHIFT    52 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL6_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL6_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL6_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL6_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL6_SHIFT    48 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL6_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL6_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL6_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL6_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL5_SHIFT    44 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL5_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL5_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL5_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL5_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL5_SHIFT    40 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL5_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL5_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL5_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL5_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL4_SHIFT    36 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL4_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL4_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL4_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL4_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL4_SHIFT    32 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL4_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL4_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL4_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL4_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL3_SHIFT    28 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL3_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL3_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL3_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL3_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL3_SHIFT    24 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL3_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL3_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL3_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL3_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL2_SHIFT    20 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL2_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL2_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL2_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL2_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL2_SHIFT    16 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL2_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL2_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL2_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL2_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL1_SHIFT    12 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL1_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL1_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL1_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL1_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL1_SHIFT    8 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL1_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL1_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL1_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL1_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL0_SHIFT    4 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL0_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL0_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL0_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_NSEL0_SHIFT)
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL0_SHIFT    0 /* established */
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL0_MASK     0x7ull
#define TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL0_INPLACE (TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL0_MASK << TIOCA_DEBUG_MUX_PCI_SEL_DEBUG_MSEL0_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_debug_domain_sel). Software never touches this register in the code read,
 * so access direction is unknown and rw is a placeholder. Reset value unknown:
 * the header and provider state none, and no firmware reading has been done.
 */
/* debug_domain_sel: rw64, reset unknown */
#define TIOCA_DEBUG_DOMAIN_SEL                       0x000118 /* established */
#define TIOCA_DEBUG_DOMAIN_SEL_DEBUG_DOMAIN_H_SHIFT  1 /* established */
#define TIOCA_DEBUG_DOMAIN_SEL_DEBUG_DOMAIN_H_MASK   0x1ull
#define TIOCA_DEBUG_DOMAIN_SEL_DEBUG_DOMAIN_H_INPLACE (TIOCA_DEBUG_DOMAIN_SEL_DEBUG_DOMAIN_H_MASK << TIOCA_DEBUG_DOMAIN_SEL_DEBUG_DOMAIN_H_SHIFT)
#define TIOCA_DEBUG_DOMAIN_SEL_DEBUG_DOMAIN_L_SHIFT  0 /* established */
#define TIOCA_DEBUG_DOMAIN_SEL_DEBUG_DOMAIN_L_MASK   0x1ull
#define TIOCA_DEBUG_DOMAIN_SEL_DEBUG_DOMAIN_L_INPLACE (TIOCA_DEBUG_DOMAIN_SEL_DEBUG_DOMAIN_L_MASK << TIOCA_DEBUG_DOMAIN_SEL_DEBUG_DOMAIN_L_SHIFT)

/*
 * GART table pointer. The provider stores the coretalk address of the page
 * table ORed with 1 (bit 0 valid). Table entries are 8 bytes: the coretalk page
 * address shifted right 12, with bit 63 set for valid. Name and offset are the
 * vendor header's definition (struct member ca_gart_ptr_table). Software only
 * writes it (the table's coretalk address ORed with 1, last store of GART
 * setup). Writability: established. Readability: unknown, so rw stays as the
 * widest access. Reset value unknown: the header and provider state none, and
 * no firmware reading has been done.
 */
/* gart_ptr_table: rw64, reset unknown */
#define TIOCA_GART_PTR_TABLE                         0x000200 /* established */
#define TIOCA_GART_PTR_TABLE_GART_PTR_ADDR_SHIFT     12 /* established */
#define TIOCA_GART_PTR_TABLE_GART_PTR_ADDR_MASK      0xfffffffffffull
#define TIOCA_GART_PTR_TABLE_GART_PTR_ADDR_INPLACE (TIOCA_GART_PTR_TABLE_GART_PTR_ADDR_MASK << TIOCA_GART_PTR_TABLE_GART_PTR_ADDR_SHIFT)
#define TIOCA_GART_PTR_TABLE_GART_PTR_VAL_SHIFT      0 /* established */
#define TIOCA_GART_PTR_TABLE_GART_PTR_VAL_MASK       0x1ull
#define TIOCA_GART_PTR_TABLE_GART_PTR_VAL_INPLACE (TIOCA_GART_PTR_TABLE_GART_PTR_VAL_MASK << TIOCA_GART_PTR_TABLE_GART_PTR_VAL_SHIFT)

/*
 * Name and offset are the vendor header's definition (struct member
 * ca_gart_tlb_addr). Software never touches this register in the code read, so
 * access direction is unknown and rw is a placeholder. Reset value unknown: the
 * header and provider state none, and no firmware reading has been done.
 */
/* gart_tlb_addr: rw64, reset unknown */
#define TIOCA_GART_TLB_ADDR                          0x000208 /* established */
#define TIOCA_GART_TLB_ADDR_COUNT                    8
#define TIOCA_GART_TLB_ADDR_STRIDE                   8
#define TIOCA_GART_TLB_ADDR_GART_TLB_ENTRY_VAL_SHIFT 63 /* established */
#define TIOCA_GART_TLB_ADDR_GART_TLB_ENTRY_VAL_MASK  0x1ull
#define TIOCA_GART_TLB_ADDR_GART_TLB_ENTRY_VAL_INPLACE (TIOCA_GART_TLB_ADDR_GART_TLB_ENTRY_VAL_MASK << TIOCA_GART_TLB_ADDR_GART_TLB_ENTRY_VAL_SHIFT)
#define TIOCA_GART_TLB_ADDR_GART_TLB_ADDR_SHIFT      0 /* established */
#define TIOCA_GART_TLB_ADDR_GART_TLB_ADDR_MASK       0xffffffffffffffull
#define TIOCA_GART_TLB_ADDR_GART_TLB_ADDR_INPLACE (TIOCA_GART_TLB_ADDR_GART_TLB_ADDR_MASK << TIOCA_GART_TLB_ADDR_GART_TLB_ADDR_SHIFT)

/* established */
#define TIOCA_AGP_DIRECT_BASE                        0x40000000u
/* established */
#define TIOCA_AGP_DMA_PIO_MEM_TYPE                   0x10000000u
/* established */
#define TIOCA_AGP_MAPPED_BASE                        0x80000000u
/* established */
#define TIOCA_AGP_MAPPED_SIZE                        0x40000000u
/* established */
#define TIOCA_DIRECT64_COHERENT                      0x1000000000000000ull
#define TIOCA_ERROR_VECTOR                           0x35u /* established */
/* established */
#define TIOCA_GART_ENTRY_VALID                       0x8000000000000000ull
#define TIOCA_PART_NUMBER                            0xe020u /* established */
/* established */
#define TIOCA_PCI32_DIRECT_BASE                      0xc0000000u
/* established */
#define TIOCA_PCI32_MAPPED_BASE                      0xc0000000u
/* established */
#define TIOCA_PCI32_MAPPED_SIZE                      0x40000000u
/* established */
#define TIOCA_PCI_DMA_PIO_MEM_TYPE                   0x10000000u
#define TIOCA_PIO_ADMIN                              0x0u /* established */
#define TIOCA_PIO_AGP_DMAREAD                        0x30000u /* established */
#define TIOCA_PIO_AGP_DMAWRITE                       0x20000u /* established */
#define TIOCA_PIO_GFX                                0x10000u /* established */
/* established */
#define TIOCA_PIO_PCI_IO                             0x3000000u
/* established */
#define TIOCA_PIO_PCI_MEM                            0x40000000u
/* established */
#define TIOCA_PIO_PCI_MEM_OFFSET                     0x8000000u
/* established */
#define TIOCA_PIO_PCI_TYPE0_CONFIG                   0x1000000u
/* established */
#define TIOCA_PIO_PCI_TYPE1_CONFIG                   0x2000000u

#endif /* TIOCA_GEN_H */
