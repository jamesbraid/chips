/* generated from devices/bedrock_pi/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 4 */
/* input sha256 56a9d9b03087a7970d1facfa6db42468dac86685a2fa0f13c9d816cce0e4d02e */
/* Bedrock processor interface (PI) registers: field layouts, interrupt banks,
 * real-time clock, graphics credits and error capture */
#ifndef BEDROCK_PI_GEN_H
#define BEDROCK_PI_GEN_H

#include <stdint.h>


/*
 * One bit per region. A set bit lets the processor in that region reach this
 * interface's local registers. A denied access gets a protection error reply.
 * The header says the register is not reset by a soft reset and gives no reset
 * value.
 */
/* cpu_protect: rw64, reset 0xffffffffffffffff; Linux 2.5.40 SN1
 * processor-interface register header: names, offsets and field layouts */
#define BEDROCK_PI_CPU_PROTECT                       0x000000 /* established */
#define BEDROCK_PI_CPU_PROTECT_CP_CPU_PROTECT_SHIFT  0 /* established */
#define BEDROCK_PI_CPU_PROTECT_CP_CPU_PROTECT_MASK   0xffffffffffffffffull
#define BEDROCK_PI_CPU_PROTECT_CP_CPU_PROTECT_INPLACE (BEDROCK_PI_CPU_PROTECT_CP_CPU_PROTECT_MASK << BEDROCK_PI_CPU_PROTECT_CP_CPU_PROTECT_SHIFT)

/*
 * A write carrying a special data pattern sets the writing processor's region
 * bit in the CPU protect register. The header does not give the pattern.
 */
/* prot_override: w64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_PROT_OVERRIDE                     0x000008 /* established */
#define BEDROCK_PI_PROT_OVERRIDE_PO_PROT_OVRRD_SHIFT 0 /* established */
#define BEDROCK_PI_PROT_OVERRIDE_PO_PROT_OVRRD_MASK  0xffffffffffffffffull
#define BEDROCK_PI_PROT_OVERRIDE_PO_PROT_OVRRD_INPLACE (BEDROCK_PI_PROT_OVERRIDE_PO_PROT_OVRRD_MASK << BEDROCK_PI_PROT_OVERRIDE_PO_PROT_OVRRD_SHIFT)

/*
 * One bit per region. Decides whether I/O-initiated interrupt writes from that
 * region may set bits in the two pending banks. The header says it is not reset
 * by a soft reset.
 */
/* io_protect: rw64, reset 0xffffffffffffffff; Linux 2.5.40 SN1
 * processor-interface register header: names, offsets and field layouts */
#define BEDROCK_PI_IO_PROTECT                        0x000010 /* established */
#define BEDROCK_PI_IO_PROTECT_IP_IO_PROTECT_SHIFT    0 /* established */
#define BEDROCK_PI_IO_PROTECT_IP_IO_PROTECT_MASK     0xffffffffffffffffull
#define BEDROCK_PI_IO_PROTECT_IP_IO_PROTECT_INPLACE (BEDROCK_PI_IO_PROTECT_IP_IO_PROTECT_MASK << BEDROCK_PI_IO_PROTECT_IP_IO_PROTECT_SHIFT)

/*
 * One bit per region. Clear bits block speculative coherent reads to that
 * region. A coherent read to an absent region gets an error reply and no error
 * register changes. Partial reads and writes are not checked. Cached-alias
 * accesses are not affected. The header says it is not reset by a soft reset.
 */
/* region_present: rw64, reset 0xffffffffffffffff; Linux 2.5.40 SN1
 * processor-interface register header: names, offsets and field layouts */
#define BEDROCK_PI_REGION_PRESENT                    0x000018 /* established */
#define BEDROCK_PI_REGION_PRESENT_RP_REGION_PRESENT_SHIFT 0 /* established */
#define BEDROCK_PI_REGION_PRESENT_RP_REGION_PRESENT_MASK 0xffffffffffffffffull
#define BEDROCK_PI_REGION_PRESENT_RP_REGION_PRESENT_INPLACE (BEDROCK_PI_REGION_PRESENT_RP_REGION_PRESENT_MASK << BEDROCK_PI_REGION_PRESENT_RP_REGION_PRESENT_SHIFT)

/*
 * Read by a processor to learn its own slot and interface. Bit 0 is the slot (0
 * for CPU A, 1 for CPU B); bit 1 is the interface (0 for PI0, 1 for PI1).
 */
/* cpu_num: r64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_CPU_NUM                           0x000020 /* established */
#define BEDROCK_PI_CPU_NUM_CN_PI_ID_SHIFT            1 /* established */
#define BEDROCK_PI_CPU_NUM_CN_PI_ID_MASK             0x1ull
#define BEDROCK_PI_CPU_NUM_CN_PI_ID_INPLACE (BEDROCK_PI_CPU_NUM_CN_PI_ID_MASK << BEDROCK_PI_CPU_NUM_CN_PI_ID_SHIFT)
#define BEDROCK_PI_CPU_NUM_CN_CPU_NUM_SHIFT          0 /* established */
#define BEDROCK_PI_CPU_NUM_CN_CPU_NUM_MASK           0x1ull
#define BEDROCK_PI_CPU_NUM_CN_CPU_NUM_INPLACE (BEDROCK_PI_CPU_NUM_CN_CPU_NUM_MASK << BEDROCK_PI_CPU_NUM_CN_CPU_NUM_SHIFT)

/*
 * Size code for the cached-alias space. The header says all cached-alias spaces
 * in a system must carry the same size. It is not reset by a soft reset.
 */
/* calias_size: rw64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_CALIAS_SIZE                       0x000028 /* established */
#define BEDROCK_PI_CALIAS_SIZE_CS_CALIAS_SIZE_SHIFT  0 /* established */
#define BEDROCK_PI_CALIAS_SIZE_CS_CALIAS_SIZE_MASK   0xfull
#define BEDROCK_PI_CALIAS_SIZE_CS_CALIAS_SIZE_INPLACE (BEDROCK_PI_CALIAS_SIZE_CS_CALIAS_SIZE_MASK << BEDROCK_PI_CALIAS_SIZE_CS_CALIAS_SIZE_SHIFT)

/*
 * Value at which a valid coherency request buffer's timeout counter causes a
 * timeout error. The header refers to the processor interface chapter of the
 * Bedrock manual, which is not held.
 */
/* max_crb_timeout: rw64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_MAX_CRB_TIMEOUT                   0x000030 /* established */
#define BEDROCK_PI_MAX_CRB_TIMEOUT_MCT_MAX_TIMEOUT_SHIFT 0 /* established */
#define BEDROCK_PI_MAX_CRB_TIMEOUT_MCT_MAX_TIMEOUT_MASK 0xffull
#define BEDROCK_PI_MAX_CRB_TIMEOUT_MCT_MAX_TIMEOUT_INPLACE (BEDROCK_PI_MAX_CRB_TIMEOUT_MCT_MAX_TIMEOUT_MASK << BEDROCK_PI_MAX_CRB_TIMEOUT_MCT_MAX_TIMEOUT_SHIFT)

/*
 * Sets how often a valid coherency request buffer's timeout counter increments.
 * The header refers to the same manual section as the maximum timeout register.
 */
/* crb_scale_factor: rw64, reset 0x64; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_CRB_SCALE_FACTOR                  0x000038 /* established */
#define BEDROCK_PI_CRB_SCALE_FACTOR_CS_SFACTOR_SHIFT 0 /* established */
#define BEDROCK_PI_CRB_SCALE_FACTOR_CS_SFACTOR_MASK  0xffffffull
#define BEDROCK_PI_CRB_SCALE_FACTOR_CS_SFACTOR_INPLACE (BEDROCK_PI_CRB_SCALE_FACTOR_CS_SFACTOR_MASK << BEDROCK_PI_CRB_SCALE_FACTOR_CS_SFACTOR_SHIFT)

/*
 * Set by the interface when it sees the first transaction from CPU A. The
 * header gives no write behaviour.
 */
/* cpu_present_a: r64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_CPU_PRESENT_A                     0x000040 /* established */
#define BEDROCK_PI_CPU_PRESENT_A_CPA_CPU_PRESENT_SHIFT 0 /* established */
#define BEDROCK_PI_CPU_PRESENT_A_CPA_CPU_PRESENT_MASK 0x1ull
#define BEDROCK_PI_CPU_PRESENT_A_CPA_CPU_PRESENT_INPLACE (BEDROCK_PI_CPU_PRESENT_A_CPA_CPU_PRESENT_MASK << BEDROCK_PI_CPU_PRESENT_A_CPA_CPU_PRESENT_SHIFT)

/*
 * Set by the interface when it sees the first transaction from CPU B. The
 * header gives no write behaviour.
 */
/* cpu_present_b: r64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_CPU_PRESENT_B                     0x000048 /* established */
#define BEDROCK_PI_CPU_PRESENT_B_CPB_CPU_PRESENT_SHIFT 0 /* established */
#define BEDROCK_PI_CPU_PRESENT_B_CPB_CPU_PRESENT_MASK 0x1ull
#define BEDROCK_PI_CPU_PRESENT_B_CPB_CPU_PRESENT_INPLACE (BEDROCK_PI_CPU_PRESENT_B_CPB_CPU_PRESENT_MASK << BEDROCK_PI_CPU_PRESENT_B_CPB_CPU_PRESENT_SHIFT)

/*
 * While clear, the interface ignores the bus request from CPU A and never
 * grants it the bus. The header says it is not reset by a soft reset and gives
 * no reset value.
 */
/* cpu_enable_a: rw64, reset 0x1; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_CPU_ENABLE_A                      0x000050 /* established */
#define BEDROCK_PI_CPU_ENABLE_A_CEA_CPU_ENABLE_SHIFT 0 /* established */
#define BEDROCK_PI_CPU_ENABLE_A_CEA_CPU_ENABLE_MASK  0x1ull
#define BEDROCK_PI_CPU_ENABLE_A_CEA_CPU_ENABLE_INPLACE (BEDROCK_PI_CPU_ENABLE_A_CEA_CPU_ENABLE_MASK << BEDROCK_PI_CPU_ENABLE_A_CEA_CPU_ENABLE_SHIFT)

/*
 * While clear, the interface ignores the bus request from CPU B and never
 * grants it the bus. The header says it is not reset by a soft reset and gives
 * no reset value.
 */
/* cpu_enable_b: rw64, reset 0x1; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_CPU_ENABLE_B                      0x000058 /* established */
#define BEDROCK_PI_CPU_ENABLE_B_CEB_CPU_ENABLE_SHIFT 0 /* established */
#define BEDROCK_PI_CPU_ENABLE_B_CEB_CPU_ENABLE_MASK  0x1ull
#define BEDROCK_PI_CPU_ENABLE_B_CEB_CPU_ENABLE_INPLACE (BEDROCK_PI_CPU_ENABLE_B_CEB_CPU_ENABLE_MASK << BEDROCK_PI_CPU_ENABLE_B_CEB_CPU_ENABLE_SHIFT)

/*
 * A write issues a non-maskable interrupt to CPU A. The header gives no
 * predicate on the written value, no latch behaviour and no reset value.
 */
/* nmi_a: w64, reset unknown; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_NMI_A                             0x000070 /* established */

/*
 * A write issues a non-maskable interrupt to CPU B. The header gives no
 * predicate on the written value, no latch behaviour and no reset value.
 */
/* nmi_b: w64, reset unknown; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_NMI_B                             0x000078 /* established */

/*
 * Inter-processor interrupt delivery for the Itanium processor in slot A of
 * this interface (IA-64 nodes only). A store of (delivery mode << 8) | vector,
 * 64 bits wide, raises that vector on the processor. The Linux code stores to
 * this offset of PI0 for slice 0 and PI1 for slice 2, from the node's hub
 * register window. The MIPS headers do not define the offset and no MIPS
 * software is known to use it. The register's reset, read behaviour and any
 * mode beyond the written value are unknown.
 */
/* ipi_a: w64, reset unknown */
#define BEDROCK_PI_IPI_A                             0x000080 /* established */

/*
 * Inter-processor interrupt delivery for the Itanium processor in slot B of
 * this interface (IA-64 nodes only), same use as ipi_a: slice 1 on PI0, slice 3
 * on PI1.
 */
/* ipi_b: w64, reset unknown */
#define BEDROCK_PI_IPI_B                             0x000088 /* established */

/*
 * Sets or clears one bit of an interrupt pending bank. It is the only
 * pending-register write an I/O-issued write may make, and I/O protect checks
 * it. Processor writes are checked against CPU protect. The header gives no
 * reset value.
 */
/* int_pend_mod: w64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_INT_PEND_MOD                      0x000090 /* established */
#define BEDROCK_PI_INT_PEND_MOD_IPM_VALUE_SHIFT      8 /* established */
#define BEDROCK_PI_INT_PEND_MOD_IPM_VALUE_MASK       0x1ull
#define BEDROCK_PI_INT_PEND_MOD_IPM_VALUE_INPLACE (BEDROCK_PI_INT_PEND_MOD_IPM_VALUE_MASK << BEDROCK_PI_INT_PEND_MOD_IPM_VALUE_SHIFT)
#define BEDROCK_PI_INT_PEND_MOD_IPM_REG_SELECT_SHIFT 6 /* established */
#define BEDROCK_PI_INT_PEND_MOD_IPM_REG_SELECT_MASK  0x1ull
#define BEDROCK_PI_INT_PEND_MOD_IPM_REG_SELECT_INPLACE (BEDROCK_PI_INT_PEND_MOD_IPM_REG_SELECT_MASK << BEDROCK_PI_INT_PEND_MOD_IPM_REG_SELECT_SHIFT)
#define BEDROCK_PI_INT_PEND_MOD_IPM_BIT_SELECT_SHIFT 0 /* established */
#define BEDROCK_PI_INT_PEND_MOD_IPM_BIT_SELECT_MASK  0x3full
#define BEDROCK_PI_INT_PEND_MOD_IPM_BIT_SELECT_INPLACE (BEDROCK_PI_INT_PEND_MOD_IPM_BIT_SELECT_MASK << BEDROCK_PI_INT_PEND_MOD_IPM_BIT_SELECT_SHIFT)

/*
 * Pending bank 0, read only. The bits map to interrupt level 2 in the header's
 * naming. The graphics bits are set by hardware and must be cleared by
 * software.
 */
/* int_pend0: r64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_INT_PEND0                         0x000098 /* established */
#define BEDROCK_PI_INT_PEND0_INT_PEND0_HI_SHIFT      7 /* established */
#define BEDROCK_PI_INT_PEND0_INT_PEND0_HI_MASK       0x1ffffffffffffffull
#define BEDROCK_PI_INT_PEND0_INT_PEND0_HI_INPLACE (BEDROCK_PI_INT_PEND0_INT_PEND0_HI_MASK << BEDROCK_PI_INT_PEND0_INT_PEND0_HI_SHIFT)
#define BEDROCK_PI_INT_PEND0_OR_CC_PEND_B_SHIFT      6 /* established */
#define BEDROCK_PI_INT_PEND0_OR_CC_PEND_B_MASK       0x1ull
#define BEDROCK_PI_INT_PEND0_OR_CC_PEND_B_INPLACE (BEDROCK_PI_INT_PEND0_OR_CC_PEND_B_MASK << BEDROCK_PI_INT_PEND0_OR_CC_PEND_B_SHIFT)
#define BEDROCK_PI_INT_PEND0_OR_CC_PEND_A_SHIFT      5 /* established */
#define BEDROCK_PI_INT_PEND0_OR_CC_PEND_A_MASK       0x1ull
#define BEDROCK_PI_INT_PEND0_OR_CC_PEND_A_INPLACE (BEDROCK_PI_INT_PEND0_OR_CC_PEND_A_MASK << BEDROCK_PI_INT_PEND0_OR_CC_PEND_A_SHIFT)
#define BEDROCK_PI_INT_PEND0_UART_UCNTRL_SHIFT       4 /* established */
#define BEDROCK_PI_INT_PEND0_UART_UCNTRL_MASK        0x1ull
#define BEDROCK_PI_INT_PEND0_UART_UCNTRL_INPLACE (BEDROCK_PI_INT_PEND0_UART_UCNTRL_MASK << BEDROCK_PI_INT_PEND0_UART_UCNTRL_SHIFT)
#define BEDROCK_PI_INT_PEND0_PAGE_MIGRATION_SHIFT    3 /* established */
#define BEDROCK_PI_INT_PEND0_PAGE_MIGRATION_MASK     0x1ull
#define BEDROCK_PI_INT_PEND0_PAGE_MIGRATION_INPLACE (BEDROCK_PI_INT_PEND0_PAGE_MIGRATION_MASK << BEDROCK_PI_INT_PEND0_PAGE_MIGRATION_SHIFT)
#define BEDROCK_PI_INT_PEND0_GFX_INT_B_SHIFT         2 /* established */
#define BEDROCK_PI_INT_PEND0_GFX_INT_B_MASK          0x1ull
#define BEDROCK_PI_INT_PEND0_GFX_INT_B_INPLACE (BEDROCK_PI_INT_PEND0_GFX_INT_B_MASK << BEDROCK_PI_INT_PEND0_GFX_INT_B_SHIFT)
#define BEDROCK_PI_INT_PEND0_GFX_INT_A_SHIFT         1 /* established */
#define BEDROCK_PI_INT_PEND0_GFX_INT_A_MASK          0x1ull
#define BEDROCK_PI_INT_PEND0_GFX_INT_A_INPLACE (BEDROCK_PI_INT_PEND0_GFX_INT_A_MASK << BEDROCK_PI_INT_PEND0_GFX_INT_A_SHIFT)
#define BEDROCK_PI_INT_PEND0_INT_PEND0_LO_SHIFT      0 /* established */
#define BEDROCK_PI_INT_PEND0_INT_PEND0_LO_MASK       0x1ull
#define BEDROCK_PI_INT_PEND0_INT_PEND0_LO_INPLACE (BEDROCK_PI_INT_PEND0_INT_PEND0_LO_MASK << BEDROCK_PI_INT_PEND0_INT_PEND0_LO_SHIFT)

/*
 * Pending bank 1, read only. Bits map to interrupt level 3 unless the remap
 * register moves bits 31 to 0 to level 2. The correctable-error, NACK and
 * performance-overflow bits are set by hardware and must be cleared by
 * software. The system shutdown, network, local-block and crossbar bits only
 * reflect other logic and cannot be changed through this interface.
 */
/* int_pend1: r64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_INT_PEND1                         0x0000a0 /* established */
#define BEDROCK_PI_INT_PEND1_SYSTEM_SHUTDOWN_SHIFT   63 /* established */
#define BEDROCK_PI_INT_PEND1_SYSTEM_SHUTDOWN_MASK    0x1ull
#define BEDROCK_PI_INT_PEND1_SYSTEM_SHUTDOWN_INPLACE (BEDROCK_PI_INT_PEND1_SYSTEM_SHUTDOWN_MASK << BEDROCK_PI_INT_PEND1_SYSTEM_SHUTDOWN_SHIFT)
#define BEDROCK_PI_INT_PEND1_NI_ERROR_SHIFT          62 /* established */
#define BEDROCK_PI_INT_PEND1_NI_ERROR_MASK           0x1ull
#define BEDROCK_PI_INT_PEND1_NI_ERROR_INPLACE (BEDROCK_PI_INT_PEND1_NI_ERROR_MASK << BEDROCK_PI_INT_PEND1_NI_ERROR_SHIFT)
#define BEDROCK_PI_INT_PEND1_MD_CORR_ERROR_SHIFT     61 /* established */
#define BEDROCK_PI_INT_PEND1_MD_CORR_ERROR_MASK      0x1ull
#define BEDROCK_PI_INT_PEND1_MD_CORR_ERROR_INPLACE (BEDROCK_PI_INT_PEND1_MD_CORR_ERROR_MASK << BEDROCK_PI_INT_PEND1_MD_CORR_ERROR_SHIFT)
#define BEDROCK_PI_INT_PEND1_SYS_COR_ERR_A_SHIFT     60 /* established */
#define BEDROCK_PI_INT_PEND1_SYS_COR_ERR_A_MASK      0x1ull
#define BEDROCK_PI_INT_PEND1_SYS_COR_ERR_A_INPLACE (BEDROCK_PI_INT_PEND1_SYS_COR_ERR_A_MASK << BEDROCK_PI_INT_PEND1_SYS_COR_ERR_A_SHIFT)
#define BEDROCK_PI_INT_PEND1_SYS_COR_ERR_B_SHIFT     59 /* established */
#define BEDROCK_PI_INT_PEND1_SYS_COR_ERR_B_MASK      0x1ull
#define BEDROCK_PI_INT_PEND1_SYS_COR_ERR_B_INPLACE (BEDROCK_PI_INT_PEND1_SYS_COR_ERR_B_MASK << BEDROCK_PI_INT_PEND1_SYS_COR_ERR_B_SHIFT)
#define BEDROCK_PI_INT_PEND1_PERF_CNTR_OFLOW_SHIFT   58 /* established */
#define BEDROCK_PI_INT_PEND1_PERF_CNTR_OFLOW_MASK    0x1ull
#define BEDROCK_PI_INT_PEND1_PERF_CNTR_OFLOW_INPLACE (BEDROCK_PI_INT_PEND1_PERF_CNTR_OFLOW_MASK << BEDROCK_PI_INT_PEND1_PERF_CNTR_OFLOW_SHIFT)
#define BEDROCK_PI_INT_PEND1_NACK_INT_B_SHIFT        57 /* established */
#define BEDROCK_PI_INT_PEND1_NACK_INT_B_MASK         0x1ull
#define BEDROCK_PI_INT_PEND1_NACK_INT_B_INPLACE (BEDROCK_PI_INT_PEND1_NACK_INT_B_MASK << BEDROCK_PI_INT_PEND1_NACK_INT_B_SHIFT)
#define BEDROCK_PI_INT_PEND1_NACK_INT_A_SHIFT        56 /* established */
#define BEDROCK_PI_INT_PEND1_NACK_INT_A_MASK         0x1ull
#define BEDROCK_PI_INT_PEND1_NACK_INT_A_INPLACE (BEDROCK_PI_INT_PEND1_NACK_INT_A_MASK << BEDROCK_PI_INT_PEND1_NACK_INT_A_SHIFT)
#define BEDROCK_PI_INT_PEND1_LB_ERROR_SHIFT          55 /* established */
#define BEDROCK_PI_INT_PEND1_LB_ERROR_MASK           0x1ull
#define BEDROCK_PI_INT_PEND1_LB_ERROR_INPLACE (BEDROCK_PI_INT_PEND1_LB_ERROR_MASK << BEDROCK_PI_INT_PEND1_LB_ERROR_SHIFT)
#define BEDROCK_PI_INT_PEND1_XB_ERROR_SHIFT          54 /* established */
#define BEDROCK_PI_INT_PEND1_XB_ERROR_MASK           0x1ull
#define BEDROCK_PI_INT_PEND1_XB_ERROR_INPLACE (BEDROCK_PI_INT_PEND1_XB_ERROR_MASK << BEDROCK_PI_INT_PEND1_XB_ERROR_SHIFT)
#define BEDROCK_PI_INT_PEND1_INT_PEND1_GEN_SHIFT     0 /* established */
#define BEDROCK_PI_INT_PEND1_INT_PEND1_GEN_MASK      0x3fffffffffffffull
#define BEDROCK_PI_INT_PEND1_INT_PEND1_GEN_INPLACE (BEDROCK_PI_INT_PEND1_INT_PEND1_GEN_MASK << BEDROCK_PI_INT_PEND1_INT_PEND1_GEN_SHIFT)

/*
 * Masks bank 0 for CPU A. A set bit passes the pending bit through as a level 2
 * interrupt (bit 10 of the processor's Cause register).
 */
/* int_mask0_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_INT_MASK0_A                       0x0000a8 /* established */
#define BEDROCK_PI_INT_MASK0_A_IMA_INT_MASK0_HI_SHIFT 7 /* established */
#define BEDROCK_PI_INT_MASK0_A_IMA_INT_MASK0_HI_MASK 0x1ffffffffffffffull
#define BEDROCK_PI_INT_MASK0_A_IMA_INT_MASK0_HI_INPLACE (BEDROCK_PI_INT_MASK0_A_IMA_INT_MASK0_HI_MASK << BEDROCK_PI_INT_MASK0_A_IMA_INT_MASK0_HI_SHIFT)
#define BEDROCK_PI_INT_MASK0_A_IMA_OR_CCP_MASK_B_SHIFT 6 /* established */
#define BEDROCK_PI_INT_MASK0_A_IMA_OR_CCP_MASK_B_MASK 0x1ull
#define BEDROCK_PI_INT_MASK0_A_IMA_OR_CCP_MASK_B_INPLACE (BEDROCK_PI_INT_MASK0_A_IMA_OR_CCP_MASK_B_MASK << BEDROCK_PI_INT_MASK0_A_IMA_OR_CCP_MASK_B_SHIFT)
#define BEDROCK_PI_INT_MASK0_A_IMA_OR_CCP_MASK_A_SHIFT 5 /* established */
#define BEDROCK_PI_INT_MASK0_A_IMA_OR_CCP_MASK_A_MASK 0x1ull
#define BEDROCK_PI_INT_MASK0_A_IMA_OR_CCP_MASK_A_INPLACE (BEDROCK_PI_INT_MASK0_A_IMA_OR_CCP_MASK_A_MASK << BEDROCK_PI_INT_MASK0_A_IMA_OR_CCP_MASK_A_SHIFT)
#define BEDROCK_PI_INT_MASK0_A_IMA_UART_UCNTRL_SHIFT 4 /* established */
#define BEDROCK_PI_INT_MASK0_A_IMA_UART_UCNTRL_MASK  0x1ull
#define BEDROCK_PI_INT_MASK0_A_IMA_UART_UCNTRL_INPLACE (BEDROCK_PI_INT_MASK0_A_IMA_UART_UCNTRL_MASK << BEDROCK_PI_INT_MASK0_A_IMA_UART_UCNTRL_SHIFT)
#define BEDROCK_PI_INT_MASK0_A_IMA_PAGE_MIGRATION_SHIFT 3 /* established */
#define BEDROCK_PI_INT_MASK0_A_IMA_PAGE_MIGRATION_MASK 0x1ull
#define BEDROCK_PI_INT_MASK0_A_IMA_PAGE_MIGRATION_INPLACE (BEDROCK_PI_INT_MASK0_A_IMA_PAGE_MIGRATION_MASK << BEDROCK_PI_INT_MASK0_A_IMA_PAGE_MIGRATION_SHIFT)
#define BEDROCK_PI_INT_MASK0_A_IMA_GFX_INT_B_SHIFT   2 /* established */
#define BEDROCK_PI_INT_MASK0_A_IMA_GFX_INT_B_MASK    0x1ull
#define BEDROCK_PI_INT_MASK0_A_IMA_GFX_INT_B_INPLACE (BEDROCK_PI_INT_MASK0_A_IMA_GFX_INT_B_MASK << BEDROCK_PI_INT_MASK0_A_IMA_GFX_INT_B_SHIFT)
#define BEDROCK_PI_INT_MASK0_A_IMA_GFX_INT_A_SHIFT   1 /* established */
#define BEDROCK_PI_INT_MASK0_A_IMA_GFX_INT_A_MASK    0x1ull
#define BEDROCK_PI_INT_MASK0_A_IMA_GFX_INT_A_INPLACE (BEDROCK_PI_INT_MASK0_A_IMA_GFX_INT_A_MASK << BEDROCK_PI_INT_MASK0_A_IMA_GFX_INT_A_SHIFT)
#define BEDROCK_PI_INT_MASK0_A_IMA_INT_MASK0_LO_SHIFT 0 /* established */
#define BEDROCK_PI_INT_MASK0_A_IMA_INT_MASK0_LO_MASK 0x1ull
#define BEDROCK_PI_INT_MASK0_A_IMA_INT_MASK0_LO_INPLACE (BEDROCK_PI_INT_MASK0_A_IMA_INT_MASK0_LO_MASK << BEDROCK_PI_INT_MASK0_A_IMA_INT_MASK0_LO_SHIFT)

/*
 * Masks bank 1 for CPU A. Bits 63 to 32 always raise a level 3 interrupt (bit
 * 11 of Cause). Bits 31 to 0 raise level 3 or level 2 depending on the remap
 * register. The header says only one processor per Bedrock should enable the
 * network, local-block, crossbar and memory-correctable bits.
 */
/* int_mask1_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_INT_MASK1_A                       0x0000b0 /* established */
#define BEDROCK_PI_INT_MASK1_A_IMA_INT_MASK1_SHIFT   0 /* established */
#define BEDROCK_PI_INT_MASK1_A_IMA_INT_MASK1_MASK    0xffffffffffffffffull
#define BEDROCK_PI_INT_MASK1_A_IMA_INT_MASK1_INPLACE (BEDROCK_PI_INT_MASK1_A_IMA_INT_MASK1_MASK << BEDROCK_PI_INT_MASK1_A_IMA_INT_MASK1_SHIFT)

/*
 * Masks bank 0 for CPU B. Same layout and meaning as the CPU A mask.
 */
/* int_mask0_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_INT_MASK0_B                       0x0000b8 /* established */
#define BEDROCK_PI_INT_MASK0_B_IMB_INT_MASK0_HI_SHIFT 7 /* established */
#define BEDROCK_PI_INT_MASK0_B_IMB_INT_MASK0_HI_MASK 0x1ffffffffffffffull
#define BEDROCK_PI_INT_MASK0_B_IMB_INT_MASK0_HI_INPLACE (BEDROCK_PI_INT_MASK0_B_IMB_INT_MASK0_HI_MASK << BEDROCK_PI_INT_MASK0_B_IMB_INT_MASK0_HI_SHIFT)
#define BEDROCK_PI_INT_MASK0_B_IMB_OR_CCP_MASK_B_SHIFT 6 /* established */
#define BEDROCK_PI_INT_MASK0_B_IMB_OR_CCP_MASK_B_MASK 0x1ull
#define BEDROCK_PI_INT_MASK0_B_IMB_OR_CCP_MASK_B_INPLACE (BEDROCK_PI_INT_MASK0_B_IMB_OR_CCP_MASK_B_MASK << BEDROCK_PI_INT_MASK0_B_IMB_OR_CCP_MASK_B_SHIFT)
#define BEDROCK_PI_INT_MASK0_B_IMB_OR_CCP_MASK_A_SHIFT 5 /* established */
#define BEDROCK_PI_INT_MASK0_B_IMB_OR_CCP_MASK_A_MASK 0x1ull
#define BEDROCK_PI_INT_MASK0_B_IMB_OR_CCP_MASK_A_INPLACE (BEDROCK_PI_INT_MASK0_B_IMB_OR_CCP_MASK_A_MASK << BEDROCK_PI_INT_MASK0_B_IMB_OR_CCP_MASK_A_SHIFT)
#define BEDROCK_PI_INT_MASK0_B_IMB_UART_UCNTRL_SHIFT 4 /* established */
#define BEDROCK_PI_INT_MASK0_B_IMB_UART_UCNTRL_MASK  0x1ull
#define BEDROCK_PI_INT_MASK0_B_IMB_UART_UCNTRL_INPLACE (BEDROCK_PI_INT_MASK0_B_IMB_UART_UCNTRL_MASK << BEDROCK_PI_INT_MASK0_B_IMB_UART_UCNTRL_SHIFT)
#define BEDROCK_PI_INT_MASK0_B_IMB_PAGE_MIGRATION_SHIFT 3 /* established */
#define BEDROCK_PI_INT_MASK0_B_IMB_PAGE_MIGRATION_MASK 0x1ull
#define BEDROCK_PI_INT_MASK0_B_IMB_PAGE_MIGRATION_INPLACE (BEDROCK_PI_INT_MASK0_B_IMB_PAGE_MIGRATION_MASK << BEDROCK_PI_INT_MASK0_B_IMB_PAGE_MIGRATION_SHIFT)
#define BEDROCK_PI_INT_MASK0_B_IMB_GFX_INT_B_SHIFT   2 /* established */
#define BEDROCK_PI_INT_MASK0_B_IMB_GFX_INT_B_MASK    0x1ull
#define BEDROCK_PI_INT_MASK0_B_IMB_GFX_INT_B_INPLACE (BEDROCK_PI_INT_MASK0_B_IMB_GFX_INT_B_MASK << BEDROCK_PI_INT_MASK0_B_IMB_GFX_INT_B_SHIFT)
#define BEDROCK_PI_INT_MASK0_B_IMB_GFX_INT_A_SHIFT   1 /* established */
#define BEDROCK_PI_INT_MASK0_B_IMB_GFX_INT_A_MASK    0x1ull
#define BEDROCK_PI_INT_MASK0_B_IMB_GFX_INT_A_INPLACE (BEDROCK_PI_INT_MASK0_B_IMB_GFX_INT_A_MASK << BEDROCK_PI_INT_MASK0_B_IMB_GFX_INT_A_SHIFT)
#define BEDROCK_PI_INT_MASK0_B_IMB_INT_MASK0_LO_SHIFT 0 /* established */
#define BEDROCK_PI_INT_MASK0_B_IMB_INT_MASK0_LO_MASK 0x1ull
#define BEDROCK_PI_INT_MASK0_B_IMB_INT_MASK0_LO_INPLACE (BEDROCK_PI_INT_MASK0_B_IMB_INT_MASK0_LO_MASK << BEDROCK_PI_INT_MASK0_B_IMB_INT_MASK0_LO_SHIFT)

/*
 * Masks bank 1 for CPU B. Same layout and meaning as the CPU A mask.
 */
/* int_mask1_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_INT_MASK1_B                       0x0000c0 /* established */
#define BEDROCK_PI_INT_MASK1_B_IMB_INT_MASK1_SHIFT   0 /* established */
#define BEDROCK_PI_INT_MASK1_B_IMB_INT_MASK1_MASK    0xffffffffffffffffull
#define BEDROCK_PI_INT_MASK1_B_IMB_INT_MASK1_INPLACE (BEDROCK_PI_INT_MASK1_B_IMB_INT_MASK1_MASK << BEDROCK_PI_INT_MASK1_B_IMB_INT_MASK1_SHIFT)

/*
 * A store by a CPU sets the bit for the storing processor's region in the CPU A
 * CPU-to-CPU pending register. These registers have no access protection.
 */
/* cc_pend_set_a: w64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_CC_PEND_SET_A                     0x0000c8 /* established */
#define BEDROCK_PI_CC_PEND_SET_A_CPSA_CC_PEND_SHIFT  0 /* established */
#define BEDROCK_PI_CC_PEND_SET_A_CPSA_CC_PEND_MASK   0xffffffffffffffffull
#define BEDROCK_PI_CC_PEND_SET_A_CPSA_CC_PEND_INPLACE (BEDROCK_PI_CC_PEND_SET_A_CPSA_CC_PEND_MASK << BEDROCK_PI_CC_PEND_SET_A_CPSA_CC_PEND_SHIFT)

/*
 * A store by a CPU sets the bit for the storing processor's region in the CPU B
 * CPU-to-CPU pending register. These registers have no access protection.
 */
/* cc_pend_set_b: w64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_CC_PEND_SET_B                     0x0000d0 /* established */
#define BEDROCK_PI_CC_PEND_SET_B_CPSB_CC_PEND_SHIFT  0 /* established */
#define BEDROCK_PI_CC_PEND_SET_B_CPSB_CC_PEND_MASK   0xffffffffffffffffull
#define BEDROCK_PI_CC_PEND_SET_B_CPSB_CC_PEND_INPLACE (BEDROCK_PI_CC_PEND_SET_B_CPSB_CC_PEND_MASK << BEDROCK_PI_CC_PEND_SET_B_CPSB_CC_PEND_SHIFT)

/*
 * A read returns the CPU A CPU-to-CPU pending bits. A write clears each bit
 * whose data bit is one.
 */
/* cc_pend_clr_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_CC_PEND_CLR_A                     0x0000d8 /* established */
#define BEDROCK_PI_CC_PEND_CLR_A_CPCA_CC_PEND_SHIFT  0 /* established */
#define BEDROCK_PI_CC_PEND_CLR_A_CPCA_CC_PEND_MASK   0xffffffffffffffffull
#define BEDROCK_PI_CC_PEND_CLR_A_CPCA_CC_PEND_INPLACE (BEDROCK_PI_CC_PEND_CLR_A_CPCA_CC_PEND_MASK << BEDROCK_PI_CC_PEND_CLR_A_CPCA_CC_PEND_SHIFT)

/*
 * A read returns the CPU B CPU-to-CPU pending bits. A write clears each bit
 * whose data bit is one.
 */
/* cc_pend_clr_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_CC_PEND_CLR_B                     0x0000e0 /* established */
#define BEDROCK_PI_CC_PEND_CLR_B_CPCB_CC_PEND_SHIFT  0 /* established */
#define BEDROCK_PI_CC_PEND_CLR_B_CPCB_CC_PEND_MASK   0xffffffffffffffffull
#define BEDROCK_PI_CC_PEND_CLR_B_CPCB_CC_PEND_INPLACE (BEDROCK_PI_CC_PEND_CLR_B_CPCB_CC_PEND_MASK << BEDROCK_PI_CC_PEND_CLR_B_CPCB_CC_PEND_SHIFT)

/*
 * Masks both CPU-to-CPU pending registers.
 */
/* cc_mask: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_CC_MASK                           0x0000e8 /* established */
#define BEDROCK_PI_CC_MASK_CM_CC_MASK_SHIFT          0 /* established */
#define BEDROCK_PI_CC_MASK_CM_CC_MASK_MASK           0xffffffffffffffffull
#define BEDROCK_PI_CC_MASK_CM_CC_MASK_INPLACE (BEDROCK_PI_CC_MASK_CM_CC_MASK_MASK << BEDROCK_PI_CC_MASK_CM_CC_MASK_SHIFT)

/*
 * Moves bank 1 bits 31 to 0 from level 3 to level 2 under control of the low
 * four bits. Bit 4 forwards the memory and unit error interrupts to the I/O
 * interface, which raises its interrupt to the node named in its destination
 * register, so the errors can reach another node. The header does not give the
 * encoding of the four-bit selector.
 */
/* int_pend1_remap: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_INT_PEND1_REMAP                   0x0000f0 /* established */
#define BEDROCK_PI_INT_PEND1_REMAP_IPR_ERROR_FORWARD_SHIFT 4 /* established */
#define BEDROCK_PI_INT_PEND1_REMAP_IPR_ERROR_FORWARD_MASK 0x1ull
#define BEDROCK_PI_INT_PEND1_REMAP_IPR_ERROR_FORWARD_INPLACE (BEDROCK_PI_INT_PEND1_REMAP_IPR_ERROR_FORWARD_MASK << BEDROCK_PI_INT_PEND1_REMAP_IPR_ERROR_FORWARD_SHIFT)
#define BEDROCK_PI_INT_PEND1_REMAP_IPR_REMAP_SHIFT   0 /* established */
#define BEDROCK_PI_INT_PEND1_REMAP_IPR_REMAP_MASK    0xfull
#define BEDROCK_PI_INT_PEND1_REMAP_IPR_REMAP_INPLACE (BEDROCK_PI_INT_PEND1_REMAP_IPR_REMAP_MASK << BEDROCK_PI_INT_PEND1_REMAP_IPR_REMAP_SHIFT)

/*
 * When the real-time counter equals this value, the CPU A real-time pending bit
 * is set. The header's comment says this sends a level 4 interrupt. Access is
 * not stated; read and write is assumed.
 */
/* rt_compare_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_RT_COMPARE_A                      0x000108 /* established */
#define BEDROCK_PI_RT_COMPARE_A_RCA_RT_COMPARE_SHIFT 0 /* established */
#define BEDROCK_PI_RT_COMPARE_A_RCA_RT_COMPARE_MASK  0x7fffffffffffffull
#define BEDROCK_PI_RT_COMPARE_A_RCA_RT_COMPARE_INPLACE (BEDROCK_PI_RT_COMPARE_A_RCA_RT_COMPARE_MASK << BEDROCK_PI_RT_COMPARE_A_RCA_RT_COMPARE_SHIFT)

/*
 * When the real-time counter equals this value, the CPU B real-time pending bit
 * is set. The header's comment says this sends a level 4 interrupt. Access is
 * not stated; read and write is assumed.
 */
/* rt_compare_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_RT_COMPARE_B                      0x000110 /* established */
#define BEDROCK_PI_RT_COMPARE_B_RCB_RT_COMPARE_SHIFT 0 /* established */
#define BEDROCK_PI_RT_COMPARE_B_RCB_RT_COMPARE_MASK  0x7fffffffffffffull
#define BEDROCK_PI_RT_COMPARE_B_RCB_RT_COMPARE_INPLACE (BEDROCK_PI_RT_COMPARE_B_RCB_RT_COMPARE_MASK << BEDROCK_PI_RT_COMPARE_B_RCB_RT_COMPARE_SHIFT)

/*
 * When the low 32 bits of the real-time counter equal this value, both
 * profiling pending registers are set to one. Access is not stated; read and
 * write is assumed.
 */
/* profile_compare: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_PROFILE_COMPARE                   0x000118 /* established */
#define BEDROCK_PI_PROFILE_COMPARE_PC_PROFILE_COMPARE_SHIFT 0 /* established */
#define BEDROCK_PI_PROFILE_COMPARE_PC_PROFILE_COMPARE_MASK 0xffffffffull
#define BEDROCK_PI_PROFILE_COMPARE_PC_PROFILE_COMPARE_INPLACE (BEDROCK_PI_PROFILE_COMPARE_PC_PROFILE_COMPARE_MASK << BEDROCK_PI_PROFILE_COMPARE_PC_PROFILE_COMPARE_SHIFT)

/*
 * Real-time interrupt pending for CPU A. When the matching enable is set, CPU
 * A's interrupt line follows this bit. The header's comment on this register
 * says level 5, which conflicts with the compare register's level 4. Any store
 * clears the bit.
 */
/* rt_int_pend_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_RT_INT_PEND_A                     0x000120 /* established */
#define BEDROCK_PI_RT_INT_PEND_A_RIPA_RTC_INT_PEND_SHIFT 0 /* established */
#define BEDROCK_PI_RT_INT_PEND_A_RIPA_RTC_INT_PEND_MASK 0x1ull
#define BEDROCK_PI_RT_INT_PEND_A_RIPA_RTC_INT_PEND_INPLACE (BEDROCK_PI_RT_INT_PEND_A_RIPA_RTC_INT_PEND_MASK << BEDROCK_PI_RT_INT_PEND_A_RIPA_RTC_INT_PEND_SHIFT)

/*
 * Real-time interrupt pending for CPU B. When the matching enable is set, CPU
 * B's interrupt line follows this bit. The header's comment says level 5. Any
 * store clears the bit.
 */
/* rt_int_pend_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_RT_INT_PEND_B                     0x000128 /* established */
#define BEDROCK_PI_RT_INT_PEND_B_RIPB_RTC_INT_PEND_SHIFT 0 /* established */
#define BEDROCK_PI_RT_INT_PEND_B_RIPB_RTC_INT_PEND_MASK 0x1ull
#define BEDROCK_PI_RT_INT_PEND_B_RIPB_RTC_INT_PEND_INPLACE (BEDROCK_PI_RT_INT_PEND_B_RIPB_RTC_INT_PEND_MASK << BEDROCK_PI_RT_INT_PEND_B_RIPB_RTC_INT_PEND_SHIFT)

/*
 * Profiling interrupt pending for CPU A. Set when the profile compare matches.
 * Any store clears it. The A and B copies are separate so each can be cleared
 * alone.
 */
/* prof_int_pend_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_PROF_INT_PEND_A                   0x000130 /* established */
#define BEDROCK_PI_PROF_INT_PEND_A_PIPA_PROF_INT_PEND_SHIFT 0 /* established */
#define BEDROCK_PI_PROF_INT_PEND_A_PIPA_PROF_INT_PEND_MASK 0x1ull
#define BEDROCK_PI_PROF_INT_PEND_A_PIPA_PROF_INT_PEND_INPLACE (BEDROCK_PI_PROF_INT_PEND_A_PIPA_PROF_INT_PEND_MASK << BEDROCK_PI_PROF_INT_PEND_A_PIPA_PROF_INT_PEND_SHIFT)

/*
 * Profiling interrupt pending for CPU B. Set when the profile compare matches.
 * Any store clears it.
 */
/* prof_int_pend_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_PROF_INT_PEND_B                   0x000138 /* established */
#define BEDROCK_PI_PROF_INT_PEND_B_PIPB_PROF_INT_PEND_SHIFT 0 /* established */
#define BEDROCK_PI_PROF_INT_PEND_B_PIPB_PROF_INT_PEND_MASK 0x1ull
#define BEDROCK_PI_PROF_INT_PEND_B_PIPB_PROF_INT_PEND_INPLACE (BEDROCK_PI_PROF_INT_PEND_B_PIPB_PROF_INT_PEND_MASK << BEDROCK_PI_PROF_INT_PEND_B_PIPB_PROF_INT_PEND_SHIFT)

/*
 * Enables the real-time interrupt to CPU A.
 */
/* rt_int_en_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_RT_INT_EN_A                       0x000140 /* established */
#define BEDROCK_PI_RT_INT_EN_A_RIEA_RTC_INT_EN_SHIFT 0 /* established */
#define BEDROCK_PI_RT_INT_EN_A_RIEA_RTC_INT_EN_MASK  0x1ull
#define BEDROCK_PI_RT_INT_EN_A_RIEA_RTC_INT_EN_INPLACE (BEDROCK_PI_RT_INT_EN_A_RIEA_RTC_INT_EN_MASK << BEDROCK_PI_RT_INT_EN_A_RIEA_RTC_INT_EN_SHIFT)

/*
 * Enables the real-time interrupt to CPU B.
 */
/* rt_int_en_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_RT_INT_EN_B                       0x000148 /* established */
#define BEDROCK_PI_RT_INT_EN_B_RIEB_RTC_INT_EN_SHIFT 0 /* established */
#define BEDROCK_PI_RT_INT_EN_B_RIEB_RTC_INT_EN_MASK  0x1ull
#define BEDROCK_PI_RT_INT_EN_B_RIEB_RTC_INT_EN_INPLACE (BEDROCK_PI_RT_INT_EN_B_RIEB_RTC_INT_EN_MASK << BEDROCK_PI_RT_INT_EN_B_RIEB_RTC_INT_EN_SHIFT)

/*
 * Enables the profiling interrupt to CPU A.
 */
/* prof_int_en_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_PROF_INT_EN_A                     0x000150 /* established */
#define BEDROCK_PI_PROF_INT_EN_A_PIEA_PROF_INT_EN_SHIFT 0 /* established */
#define BEDROCK_PI_PROF_INT_EN_A_PIEA_PROF_INT_EN_MASK 0x1ull
#define BEDROCK_PI_PROF_INT_EN_A_PIEA_PROF_INT_EN_INPLACE (BEDROCK_PI_PROF_INT_EN_A_PIEA_PROF_INT_EN_MASK << BEDROCK_PI_PROF_INT_EN_A_PIEA_PROF_INT_EN_SHIFT)

/*
 * Enables the profiling interrupt to CPU B.
 */
/* prof_int_en_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_PROF_INT_EN_B                     0x000158 /* established */
#define BEDROCK_PI_PROF_INT_EN_B_PIEB_PROF_INT_EN_SHIFT 0 /* established */
#define BEDROCK_PI_PROF_INT_EN_B_PIEB_PROF_INT_EN_MASK 0x1ull
#define BEDROCK_PI_PROF_INT_EN_B_PIEB_PROF_INT_EN_INPLACE (BEDROCK_PI_PROF_INT_EN_B_PIEB_PROF_INT_EN_MASK << BEDROCK_PI_PROF_INT_EN_B_PIEB_PROF_INT_EN_SHIFT)

/*
 * Selects the debug data the interface drives, together with the debug module's
 * select. The header gives the selector names below and says the B-select bit
 * chooses CPU A or CPU B logic for some selections. Each low and high selector
 * bit is one signal, named by the header as follows: low selector bits are t5cc
 * A, t5cc B, totcc A, totcc B, reqcc A, reqcc B, rplcc A, rplcc B, intcc, perf
 * increment A 0 and 1, perf increment B 0 and 1; high selector bits are the
 * same names in the same order.
 */
/* debug_sel: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_DEBUG_SEL                         0x000160 /* established */
#define BEDROCK_PI_DEBUG_SEL_DS_B_SEL_SHIFT          26 /* established */
#define BEDROCK_PI_DEBUG_SEL_DS_B_SEL_MASK           0x1ull
#define BEDROCK_PI_DEBUG_SEL_DS_B_SEL_INPLACE (BEDROCK_PI_DEBUG_SEL_DS_B_SEL_MASK << BEDROCK_PI_DEBUG_SEL_DS_B_SEL_SHIFT)
#define BEDROCK_PI_DEBUG_SEL_DS_HIGH_SELECT_SHIFT    13 /* established */
#define BEDROCK_PI_DEBUG_SEL_DS_HIGH_SELECT_MASK     0x1fffull
#define BEDROCK_PI_DEBUG_SEL_DS_HIGH_SELECT_INPLACE (BEDROCK_PI_DEBUG_SEL_DS_HIGH_SELECT_MASK << BEDROCK_PI_DEBUG_SEL_DS_HIGH_SELECT_SHIFT)
#define BEDROCK_PI_DEBUG_SEL_DS_LOW_SELECT_SHIFT     0 /* established */
#define BEDROCK_PI_DEBUG_SEL_DS_LOW_SELECT_MASK      0x1fffull
#define BEDROCK_PI_DEBUG_SEL_DS_LOW_SELECT_INPLACE (BEDROCK_PI_DEBUG_SEL_DS_LOW_SELECT_MASK << BEDROCK_PI_DEBUG_SEL_DS_LOW_SELECT_SHIFT)

/*
 * Alias of the pending-modify register with the same layout and checks. The
 * header does not say why a second address exists.
 */
/* int_pend_mod_alias: w64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_INT_PEND_MOD_ALIAS                0x000180 /* established */
#define BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_VALUE_SHIFT 8 /* established */
#define BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_VALUE_MASK 0x1ull
#define BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_VALUE_INPLACE (BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_VALUE_MASK << BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_VALUE_SHIFT)
#define BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_REG_SELECT_SHIFT 6 /* established */
#define BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_REG_SELECT_MASK 0x1ull
#define BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_REG_SELECT_INPLACE (BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_REG_SELECT_MASK << BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_REG_SELECT_SHIFT)
#define BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_BIT_SELECT_SHIFT 0 /* established */
#define BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_BIT_SELECT_MASK 0x3full
#define BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_BIT_SELECT_INPLACE (BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_BIT_SELECT_MASK << BEDROCK_PI_INT_PEND_MOD_ALIAS_IPM_BIT_SELECT_SHIFT)

/*
 * Graphics page for CPU A. Uncached I/O stores into the enabled page are
 * graphics write commands tracked by the credit counter, not ordinary write
 * commands. Access is not stated; read and write is assumed.
 */
/* gfx_page_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_GFX_PAGE_A                        0x000300 /* established */
#define BEDROCK_PI_GFX_PAGE_A_GPA_EN_GFX_PAGE_SHIFT  40 /* established */
#define BEDROCK_PI_GFX_PAGE_A_GPA_EN_GFX_PAGE_MASK   0x1ull
#define BEDROCK_PI_GFX_PAGE_A_GPA_EN_GFX_PAGE_INPLACE (BEDROCK_PI_GFX_PAGE_A_GPA_EN_GFX_PAGE_MASK << BEDROCK_PI_GFX_PAGE_A_GPA_EN_GFX_PAGE_SHIFT)
#define BEDROCK_PI_GFX_PAGE_A_GPA_GFX_PAGE_ADDR_SHIFT 17 /* established */
#define BEDROCK_PI_GFX_PAGE_A_GPA_GFX_PAGE_ADDR_MASK 0x7fffffull
#define BEDROCK_PI_GFX_PAGE_A_GPA_GFX_PAGE_ADDR_INPLACE (BEDROCK_PI_GFX_PAGE_A_GPA_GFX_PAGE_ADDR_MASK << BEDROCK_PI_GFX_PAGE_A_GPA_GFX_PAGE_ADDR_SHIFT)

/*
 * Graphics credit counter for CPU A. It drops by one per doubleword sent to
 * graphics and rises by one per doubleword acknowledged. When it is below the
 * bias, the header says write-ready is withheld, an interrupt is sent, and
 * write-ready is allowed again. Access is not stated; read and write is
 * assumed.
 */
/* gfx_credit_cntr_a: rw64, reset 0x40; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_GFX_CREDIT_CNTR_A                 0x000308 /* established */
/* established */
#define BEDROCK_PI_GFX_CREDIT_CNTR_A_GCCA_GFX_CREDIT_CNTR_SHIFT 0
#define BEDROCK_PI_GFX_CREDIT_CNTR_A_GCCA_GFX_CREDIT_CNTR_MASK 0xfffull
#define BEDROCK_PI_GFX_CREDIT_CNTR_A_GCCA_GFX_CREDIT_CNTR_INPLACE (BEDROCK_PI_GFX_CREDIT_CNTR_A_GCCA_GFX_CREDIT_CNTR_MASK << BEDROCK_PI_GFX_CREDIT_CNTR_A_GCCA_GFX_CREDIT_CNTR_SHIFT)

/*
 * Graphics bias for CPU A. When the credit counter is at or below this value,
 * the header says a flow-control interrupt is sent. Access is not stated; read
 * and write is assumed.
 */
/* gfx_bias_a: rw64, reset 0x24; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_GFX_BIAS_A                        0x000310 /* established */
#define BEDROCK_PI_GFX_BIAS_A_GBA_GFX_BIAS_SHIFT     0 /* established */
#define BEDROCK_PI_GFX_BIAS_A_GBA_GFX_BIAS_MASK      0xfffull
#define BEDROCK_PI_GFX_BIAS_A_GBA_GFX_BIAS_INPLACE (BEDROCK_PI_GFX_BIAS_A_GBA_GFX_BIAS_MASK << BEDROCK_PI_GFX_BIAS_A_GBA_GFX_BIAS_SHIFT)

/*
 * Graphics interrupt counter for CPU A. The header says it is written by
 * software, loaded from the compare on an interrupt, NMI or soft reset, zeroed
 * when the credit counter rises above the bias, and counts one per clock while
 * the credit counter is at or below zero. Access is not stated; read and write
 * is assumed.
 */
/* gfx_int_cntr_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_GFX_INT_CNTR_A                    0x000318 /* established */
#define BEDROCK_PI_GFX_INT_CNTR_A_GICA_GFX_INT_CNTR_SHIFT 0 /* established */
#define BEDROCK_PI_GFX_INT_CNTR_A_GICA_GFX_INT_CNTR_MASK 0x3ffffffull
#define BEDROCK_PI_GFX_INT_CNTR_A_GICA_GFX_INT_CNTR_INPLACE (BEDROCK_PI_GFX_INT_CNTR_A_GICA_GFX_INT_CNTR_MASK << BEDROCK_PI_GFX_INT_CNTR_A_GICA_GFX_INT_CNTR_SHIFT)

/*
 * Graphics interrupt compare for CPU A. The interrupt is sent when the
 * interrupt counter reaches this value. Access is not stated; read and write is
 * assumed.
 */
/* gfx_int_cmp_a: rw64, reset 0x10000; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_GFX_INT_CMP_A                     0x000320 /* established */
#define BEDROCK_PI_GFX_INT_CMP_A_GICA_GFX_INT_CMP_SHIFT 0 /* established */
#define BEDROCK_PI_GFX_INT_CMP_A_GICA_GFX_INT_CMP_MASK 0x3ffffffull
#define BEDROCK_PI_GFX_INT_CMP_A_GICA_GFX_INT_CMP_INPLACE (BEDROCK_PI_GFX_INT_CMP_A_GICA_GFX_INT_CMP_MASK << BEDROCK_PI_GFX_INT_CMP_A_GICA_GFX_INT_CMP_SHIFT)

/*
 * Graphics page for CPU B. Uncached I/O stores into the enabled page are
 * graphics write commands tracked by the credit counter, not ordinary write
 * commands. Access is not stated; read and write is assumed.
 */
/* gfx_page_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_GFX_PAGE_B                        0x000328 /* established */
#define BEDROCK_PI_GFX_PAGE_B_GPB_EN_GFX_PAGE_SHIFT  40 /* established */
#define BEDROCK_PI_GFX_PAGE_B_GPB_EN_GFX_PAGE_MASK   0x1ull
#define BEDROCK_PI_GFX_PAGE_B_GPB_EN_GFX_PAGE_INPLACE (BEDROCK_PI_GFX_PAGE_B_GPB_EN_GFX_PAGE_MASK << BEDROCK_PI_GFX_PAGE_B_GPB_EN_GFX_PAGE_SHIFT)
#define BEDROCK_PI_GFX_PAGE_B_GPB_GFX_PAGE_ADDR_SHIFT 17 /* established */
#define BEDROCK_PI_GFX_PAGE_B_GPB_GFX_PAGE_ADDR_MASK 0x7fffffull
#define BEDROCK_PI_GFX_PAGE_B_GPB_GFX_PAGE_ADDR_INPLACE (BEDROCK_PI_GFX_PAGE_B_GPB_GFX_PAGE_ADDR_MASK << BEDROCK_PI_GFX_PAGE_B_GPB_GFX_PAGE_ADDR_SHIFT)

/*
 * Graphics credit counter for CPU B. It drops by one per doubleword sent to
 * graphics and rises by one per doubleword acknowledged. When it is below the
 * bias, the header says write-ready is withheld, an interrupt is sent, and
 * write-ready is allowed again. Access is not stated; read and write is
 * assumed.
 */
/* gfx_credit_cntr_b: rw64, reset 0x40; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_GFX_CREDIT_CNTR_B                 0x000330 /* established */
/* established */
#define BEDROCK_PI_GFX_CREDIT_CNTR_B_GCCB_GFX_CREDIT_CNTR_SHIFT 0
#define BEDROCK_PI_GFX_CREDIT_CNTR_B_GCCB_GFX_CREDIT_CNTR_MASK 0xfffull
#define BEDROCK_PI_GFX_CREDIT_CNTR_B_GCCB_GFX_CREDIT_CNTR_INPLACE (BEDROCK_PI_GFX_CREDIT_CNTR_B_GCCB_GFX_CREDIT_CNTR_MASK << BEDROCK_PI_GFX_CREDIT_CNTR_B_GCCB_GFX_CREDIT_CNTR_SHIFT)

/*
 * Graphics bias for CPU B. When the credit counter is at or below this value,
 * the header says a flow-control interrupt is sent. Access is not stated; read
 * and write is assumed.
 */
/* gfx_bias_b: rw64, reset 0x24; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_GFX_BIAS_B                        0x000338 /* established */
#define BEDROCK_PI_GFX_BIAS_B_GBB_GFX_BIAS_SHIFT     0 /* established */
#define BEDROCK_PI_GFX_BIAS_B_GBB_GFX_BIAS_MASK      0xfffull
#define BEDROCK_PI_GFX_BIAS_B_GBB_GFX_BIAS_INPLACE (BEDROCK_PI_GFX_BIAS_B_GBB_GFX_BIAS_MASK << BEDROCK_PI_GFX_BIAS_B_GBB_GFX_BIAS_SHIFT)

/*
 * Graphics interrupt counter for CPU B. The header says it is written by
 * software, loaded from the compare on an interrupt, NMI or soft reset, zeroed
 * when the credit counter rises above the bias, and counts one per clock while
 * the credit counter is at or below zero. Access is not stated; read and write
 * is assumed.
 */
/* gfx_int_cntr_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_GFX_INT_CNTR_B                    0x000340 /* established */
#define BEDROCK_PI_GFX_INT_CNTR_B_GICB_GFX_INT_CNTR_SHIFT 0 /* established */
#define BEDROCK_PI_GFX_INT_CNTR_B_GICB_GFX_INT_CNTR_MASK 0x3ffffffull
#define BEDROCK_PI_GFX_INT_CNTR_B_GICB_GFX_INT_CNTR_INPLACE (BEDROCK_PI_GFX_INT_CNTR_B_GICB_GFX_INT_CNTR_MASK << BEDROCK_PI_GFX_INT_CNTR_B_GICB_GFX_INT_CNTR_SHIFT)

/*
 * Graphics interrupt compare for CPU B. The interrupt is sent when the
 * interrupt counter reaches this value. Access is not stated; read and write is
 * assumed.
 */
/* gfx_int_cmp_b: rw64, reset 0x10000; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_GFX_INT_CMP_B                     0x000348 /* established */
#define BEDROCK_PI_GFX_INT_CMP_B_GICB_GFX_INT_CMP_SHIFT 0 /* established */
#define BEDROCK_PI_GFX_INT_CMP_B_GICB_GFX_INT_CMP_MASK 0x3ffffffull
#define BEDROCK_PI_GFX_INT_CMP_B_GICB_GFX_INT_CMP_INPLACE (BEDROCK_PI_GFX_INT_CMP_B_GICB_GFX_INT_CMP_MASK << BEDROCK_PI_GFX_INT_CMP_B_GICB_GFX_INT_CMP_SHIFT)

/*
 * Writable view of the error interrupt pending bits. A read returns every error
 * source. A direct write sets or clears each unreserved bit, except the memory
 * uncorrectable bit. Bit layout is the same as the write-with-clear register.
 */
/* err_int_pend_wr: rw64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_INT_PEND_WR                   0x0003f8 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_IRB_TIMEOUT_A_SHIFT 34 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_IRB_TIMEOUT_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_IRB_TIMEOUT_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_IRB_TIMEOUT_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_IRB_TIMEOUT_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_IRB_TIMEOUT_B_SHIFT 33 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_IRB_TIMEOUT_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_IRB_TIMEOUT_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_IRB_TIMEOUT_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_IRB_TIMEOUT_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_IRB_ERR_A_SHIFT   32 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_IRB_ERR_A_MASK    0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_IRB_ERR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_IRB_ERR_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_IRB_ERR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_IRB_ERR_B_SHIFT   31 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_IRB_ERR_B_MASK    0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_IRB_ERR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_IRB_ERR_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_IRB_ERR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_PKT_LEN_ERR_A_SHIFT 30 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_PKT_LEN_ERR_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_PKT_LEN_ERR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_PKT_LEN_ERR_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_PKT_LEN_ERR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_PKT_LEN_ERR_B_SHIFT 29 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_PKT_LEN_ERR_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_PKT_LEN_ERR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_PKT_LEN_ERR_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_PKT_LEN_ERR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_UE_CACHED_A_SHIFT 28 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_UE_CACHED_A_MASK  0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_UE_CACHED_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_UE_CACHED_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_UE_CACHED_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_UE_CACHED_B_SHIFT 27 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_UE_CACHED_B_MASK  0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_UE_CACHED_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_UE_CACHED_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_UE_CACHED_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_BAD_DATA_A_SHIFT 26 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_BAD_DATA_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_BAD_DATA_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_BAD_DATA_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_BAD_DATA_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_BAD_DATA_B_SHIFT 25 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_BAD_DATA_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_BAD_DATA_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_BAD_DATA_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_BAD_DATA_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_MEM_UNC_SHIFT     24 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_MEM_UNC_MASK      0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_MEM_UNC_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_MEM_UNC_MASK << BEDROCK_PI_ERR_INT_PEND_WR_MEM_UNC_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_TAG_A_SHIFT 23 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_TAG_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_TAG_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_TAG_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_TAG_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_TAG_B_SHIFT 22 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_TAG_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_TAG_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_TAG_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_TAG_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_UE_UNCACHED_A_SHIFT 21 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_UE_UNCACHED_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_UE_UNCACHED_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_UE_UNCACHED_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_UE_UNCACHED_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_UE_UNCACHED_B_SHIFT 20 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_UE_UNCACHED_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_UE_UNCACHED_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_UE_UNCACHED_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_UE_UNCACHED_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_ERR_A_SHIFT 19 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_ERR_A_MASK  0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_ERR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_ERR_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_ERR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_ERR_B_SHIFT 18 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_ERR_B_MASK  0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_ERR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_ERR_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_ERR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_ADDR_PAR_A_SHIFT 17 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_ADDR_PAR_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_ADDR_PAR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_ADDR_PAR_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_ADDR_PAR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_ADDR_PAR_B_SHIFT 16 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_ADDR_PAR_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_ADDR_PAR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_ADDR_PAR_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_ADDR_PAR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_DATA_PAR_A_SHIFT 15 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_DATA_PAR_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_DATA_PAR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_DATA_PAR_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_DATA_PAR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_DATA_PAR_B_SHIFT 14 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_DATA_PAR_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_DATA_PAR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_DATA_PAR_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSCMD_DATA_PAR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_ADDR_ECC_A_SHIFT 13 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_ADDR_ECC_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_ADDR_ECC_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_ADDR_ECC_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_ADDR_ECC_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_ADDR_ECC_B_SHIFT 12 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_ADDR_ECC_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_ADDR_ECC_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_ADDR_ECC_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_ADDR_ECC_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_DATA_ECC_A_SHIFT 11 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_DATA_ECC_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_DATA_ECC_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_DATA_ECC_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_DATA_ECC_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_DATA_ECC_B_SHIFT 10 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_DATA_ECC_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_DATA_ECC_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_DATA_ECC_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSAD_DATA_ECC_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_PAR_A_SHIFT 9 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_PAR_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_PAR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_PAR_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_PAR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_PAR_B_SHIFT 8 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_PAR_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_PAR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_PAR_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SYSSTATE_PAR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_WRB_WERR_A_SHIFT  7 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_WRB_WERR_A_MASK   0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_WRB_WERR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_WRB_WERR_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_WRB_WERR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_WRB_WERR_B_SHIFT  6 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_WRB_WERR_B_MASK   0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_WRB_WERR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_WRB_WERR_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_WRB_WERR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_WRB_TERR_A_SHIFT  5 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_WRB_TERR_A_MASK   0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_WRB_TERR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_WRB_TERR_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_WRB_TERR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_WRB_TERR_B_SHIFT  4 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_WRB_TERR_B_MASK   0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_WRB_TERR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_WRB_TERR_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_WRB_TERR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SPURIOUS_A_SHIFT  3 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SPURIOUS_A_MASK   0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SPURIOUS_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SPURIOUS_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SPURIOUS_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SPURIOUS_B_SHIFT  2 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SPURIOUS_B_MASK   0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SPURIOUS_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SPURIOUS_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SPURIOUS_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_COMP_A_SHIFT 1 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_COMP_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_COMP_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_COMP_A_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_COMP_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_COMP_B_SHIFT 0 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_COMP_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_COMP_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_COMP_B_MASK << BEDROCK_PI_ERR_INT_PEND_WR_SPOOL_COMP_B_SHIFT)

/*
 * Error interrupt pending. A read returns every error source. A store clears
 * each bit whose data bit is one. Bits 0 to 23 are twelve CPU B and CPU A pairs
 * with B at the even bit, in order: spool complete, spurious message, the two
 * write-buffer error kinds, system-state parity, system data ECC, system
 * address ECC, command data parity, command address parity, spool error,
 * uncached uncorrectable, system-state tag. Bit 24 is memory uncorrectable.
 * Bits 25 to 34 are five pairs with A at the even bit: bad data, cached
 * uncorrectable, packet length, request-buffer error and request-buffer
 * timeout.
 */
/* err_int_pend: rw64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_INT_PEND                      0x000400 /* established */
#define BEDROCK_PI_ERR_INT_PEND_IRB_TIMEOUT_A_SHIFT  34 /* established */
#define BEDROCK_PI_ERR_INT_PEND_IRB_TIMEOUT_A_MASK   0x1ull
#define BEDROCK_PI_ERR_INT_PEND_IRB_TIMEOUT_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_IRB_TIMEOUT_A_MASK << BEDROCK_PI_ERR_INT_PEND_IRB_TIMEOUT_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_IRB_TIMEOUT_B_SHIFT  33 /* established */
#define BEDROCK_PI_ERR_INT_PEND_IRB_TIMEOUT_B_MASK   0x1ull
#define BEDROCK_PI_ERR_INT_PEND_IRB_TIMEOUT_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_IRB_TIMEOUT_B_MASK << BEDROCK_PI_ERR_INT_PEND_IRB_TIMEOUT_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_IRB_ERR_A_SHIFT      32 /* established */
#define BEDROCK_PI_ERR_INT_PEND_IRB_ERR_A_MASK       0x1ull
#define BEDROCK_PI_ERR_INT_PEND_IRB_ERR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_IRB_ERR_A_MASK << BEDROCK_PI_ERR_INT_PEND_IRB_ERR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_IRB_ERR_B_SHIFT      31 /* established */
#define BEDROCK_PI_ERR_INT_PEND_IRB_ERR_B_MASK       0x1ull
#define BEDROCK_PI_ERR_INT_PEND_IRB_ERR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_IRB_ERR_B_MASK << BEDROCK_PI_ERR_INT_PEND_IRB_ERR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_PKT_LEN_ERR_A_SHIFT  30 /* established */
#define BEDROCK_PI_ERR_INT_PEND_PKT_LEN_ERR_A_MASK   0x1ull
#define BEDROCK_PI_ERR_INT_PEND_PKT_LEN_ERR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_PKT_LEN_ERR_A_MASK << BEDROCK_PI_ERR_INT_PEND_PKT_LEN_ERR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_PKT_LEN_ERR_B_SHIFT  29 /* established */
#define BEDROCK_PI_ERR_INT_PEND_PKT_LEN_ERR_B_MASK   0x1ull
#define BEDROCK_PI_ERR_INT_PEND_PKT_LEN_ERR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_PKT_LEN_ERR_B_MASK << BEDROCK_PI_ERR_INT_PEND_PKT_LEN_ERR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_UE_CACHED_A_SHIFT    28 /* established */
#define BEDROCK_PI_ERR_INT_PEND_UE_CACHED_A_MASK     0x1ull
#define BEDROCK_PI_ERR_INT_PEND_UE_CACHED_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_UE_CACHED_A_MASK << BEDROCK_PI_ERR_INT_PEND_UE_CACHED_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_UE_CACHED_B_SHIFT    27 /* established */
#define BEDROCK_PI_ERR_INT_PEND_UE_CACHED_B_MASK     0x1ull
#define BEDROCK_PI_ERR_INT_PEND_UE_CACHED_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_UE_CACHED_B_MASK << BEDROCK_PI_ERR_INT_PEND_UE_CACHED_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_BAD_DATA_A_SHIFT 26 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_BAD_DATA_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_BAD_DATA_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSAD_BAD_DATA_A_MASK << BEDROCK_PI_ERR_INT_PEND_SYSAD_BAD_DATA_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_BAD_DATA_B_SHIFT 25 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_BAD_DATA_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_BAD_DATA_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSAD_BAD_DATA_B_MASK << BEDROCK_PI_ERR_INT_PEND_SYSAD_BAD_DATA_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_MEM_UNC_SHIFT        24 /* established */
#define BEDROCK_PI_ERR_INT_PEND_MEM_UNC_MASK         0x1ull
#define BEDROCK_PI_ERR_INT_PEND_MEM_UNC_INPLACE (BEDROCK_PI_ERR_INT_PEND_MEM_UNC_MASK << BEDROCK_PI_ERR_INT_PEND_MEM_UNC_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSSTATE_TAG_A_SHIFT 23 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSSTATE_TAG_A_MASK  0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSSTATE_TAG_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSSTATE_TAG_A_MASK << BEDROCK_PI_ERR_INT_PEND_SYSSTATE_TAG_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSSTATE_TAG_B_SHIFT 22 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSSTATE_TAG_B_MASK  0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSSTATE_TAG_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSSTATE_TAG_B_MASK << BEDROCK_PI_ERR_INT_PEND_SYSSTATE_TAG_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_UE_UNCACHED_A_SHIFT  21 /* established */
#define BEDROCK_PI_ERR_INT_PEND_UE_UNCACHED_A_MASK   0x1ull
#define BEDROCK_PI_ERR_INT_PEND_UE_UNCACHED_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_UE_UNCACHED_A_MASK << BEDROCK_PI_ERR_INT_PEND_UE_UNCACHED_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_UE_UNCACHED_B_SHIFT  20 /* established */
#define BEDROCK_PI_ERR_INT_PEND_UE_UNCACHED_B_MASK   0x1ull
#define BEDROCK_PI_ERR_INT_PEND_UE_UNCACHED_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_UE_UNCACHED_B_MASK << BEDROCK_PI_ERR_INT_PEND_UE_UNCACHED_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SPOOL_ERR_A_SHIFT    19 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SPOOL_ERR_A_MASK     0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SPOOL_ERR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_SPOOL_ERR_A_MASK << BEDROCK_PI_ERR_INT_PEND_SPOOL_ERR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SPOOL_ERR_B_SHIFT    18 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SPOOL_ERR_B_MASK     0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SPOOL_ERR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_SPOOL_ERR_B_MASK << BEDROCK_PI_ERR_INT_PEND_SPOOL_ERR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSCMD_ADDR_PAR_A_SHIFT 17 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSCMD_ADDR_PAR_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSCMD_ADDR_PAR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSCMD_ADDR_PAR_A_MASK << BEDROCK_PI_ERR_INT_PEND_SYSCMD_ADDR_PAR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSCMD_ADDR_PAR_B_SHIFT 16 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSCMD_ADDR_PAR_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSCMD_ADDR_PAR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSCMD_ADDR_PAR_B_MASK << BEDROCK_PI_ERR_INT_PEND_SYSCMD_ADDR_PAR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSCMD_DATA_PAR_A_SHIFT 15 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSCMD_DATA_PAR_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSCMD_DATA_PAR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSCMD_DATA_PAR_A_MASK << BEDROCK_PI_ERR_INT_PEND_SYSCMD_DATA_PAR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSCMD_DATA_PAR_B_SHIFT 14 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSCMD_DATA_PAR_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSCMD_DATA_PAR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSCMD_DATA_PAR_B_MASK << BEDROCK_PI_ERR_INT_PEND_SYSCMD_DATA_PAR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_ADDR_ECC_A_SHIFT 13 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_ADDR_ECC_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_ADDR_ECC_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSAD_ADDR_ECC_A_MASK << BEDROCK_PI_ERR_INT_PEND_SYSAD_ADDR_ECC_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_ADDR_ECC_B_SHIFT 12 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_ADDR_ECC_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_ADDR_ECC_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSAD_ADDR_ECC_B_MASK << BEDROCK_PI_ERR_INT_PEND_SYSAD_ADDR_ECC_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_DATA_ECC_A_SHIFT 11 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_DATA_ECC_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_DATA_ECC_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSAD_DATA_ECC_A_MASK << BEDROCK_PI_ERR_INT_PEND_SYSAD_DATA_ECC_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_DATA_ECC_B_SHIFT 10 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_DATA_ECC_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSAD_DATA_ECC_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSAD_DATA_ECC_B_MASK << BEDROCK_PI_ERR_INT_PEND_SYSAD_DATA_ECC_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSSTATE_PAR_A_SHIFT 9 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSSTATE_PAR_A_MASK  0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSSTATE_PAR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSSTATE_PAR_A_MASK << BEDROCK_PI_ERR_INT_PEND_SYSSTATE_PAR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SYSSTATE_PAR_B_SHIFT 8 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SYSSTATE_PAR_B_MASK  0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SYSSTATE_PAR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_SYSSTATE_PAR_B_MASK << BEDROCK_PI_ERR_INT_PEND_SYSSTATE_PAR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WRB_WERR_A_SHIFT     7 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WRB_WERR_A_MASK      0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WRB_WERR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WRB_WERR_A_MASK << BEDROCK_PI_ERR_INT_PEND_WRB_WERR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WRB_WERR_B_SHIFT     6 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WRB_WERR_B_MASK      0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WRB_WERR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WRB_WERR_B_MASK << BEDROCK_PI_ERR_INT_PEND_WRB_WERR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WRB_TERR_A_SHIFT     5 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WRB_TERR_A_MASK      0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WRB_TERR_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_WRB_TERR_A_MASK << BEDROCK_PI_ERR_INT_PEND_WRB_TERR_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_WRB_TERR_B_SHIFT     4 /* established */
#define BEDROCK_PI_ERR_INT_PEND_WRB_TERR_B_MASK      0x1ull
#define BEDROCK_PI_ERR_INT_PEND_WRB_TERR_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_WRB_TERR_B_MASK << BEDROCK_PI_ERR_INT_PEND_WRB_TERR_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SPURIOUS_A_SHIFT     3 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SPURIOUS_A_MASK      0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SPURIOUS_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_SPURIOUS_A_MASK << BEDROCK_PI_ERR_INT_PEND_SPURIOUS_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SPURIOUS_B_SHIFT     2 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SPURIOUS_B_MASK      0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SPURIOUS_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_SPURIOUS_B_MASK << BEDROCK_PI_ERR_INT_PEND_SPURIOUS_B_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SPOOL_COMP_A_SHIFT   1 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SPOOL_COMP_A_MASK    0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SPOOL_COMP_A_INPLACE (BEDROCK_PI_ERR_INT_PEND_SPOOL_COMP_A_MASK << BEDROCK_PI_ERR_INT_PEND_SPOOL_COMP_A_SHIFT)
#define BEDROCK_PI_ERR_INT_PEND_SPOOL_COMP_B_SHIFT   0 /* established */
#define BEDROCK_PI_ERR_INT_PEND_SPOOL_COMP_B_MASK    0x1ull
#define BEDROCK_PI_ERR_INT_PEND_SPOOL_COMP_B_INPLACE (BEDROCK_PI_ERR_INT_PEND_SPOOL_COMP_B_MASK << BEDROCK_PI_ERR_INT_PEND_SPOOL_COMP_B_SHIFT)

/*
 * Masks the error pending bits for CPU A. A set bit lets that error raise the
 * level 6 interrupt to CPU A. The header says only one processor per Bedrock
 * should enable the memory uncorrectable bit.
 */
/* err_int_mask_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_INT_MASK_A                    0x000408 /* established */
#define BEDROCK_PI_ERR_INT_MASK_A_EIMA_MASK_SHIFT    0 /* established */
#define BEDROCK_PI_ERR_INT_MASK_A_EIMA_MASK_MASK     0x7ffffffffull
#define BEDROCK_PI_ERR_INT_MASK_A_EIMA_MASK_INPLACE (BEDROCK_PI_ERR_INT_MASK_A_EIMA_MASK_MASK << BEDROCK_PI_ERR_INT_MASK_A_EIMA_MASK_SHIFT)

/*
 * Masks the error pending bits for CPU B. A set bit lets that error raise the
 * level 6 interrupt to CPU B. The header says only one processor per Bedrock
 * should enable the memory uncorrectable bit.
 */
/* err_int_mask_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_INT_MASK_B                    0x000410 /* established */
#define BEDROCK_PI_ERR_INT_MASK_B_EIMB_MASK_SHIFT    0 /* established */
#define BEDROCK_PI_ERR_INT_MASK_B_EIMB_MASK_MASK     0x7ffffffffull
#define BEDROCK_PI_ERR_INT_MASK_B_EIMB_MASK_INPLACE (BEDROCK_PI_ERR_INT_MASK_B_EIMB_MASK_MASK << BEDROCK_PI_ERR_INT_MASK_B_EIMB_MASK_SHIFT)

/*
 * Address of the next write to the CPU A error stack. It increments after each
 * write, and only the low bits that the stack size selects count up. The header
 * says it is not reset by a soft reset.
 */
/* err_stack_addr_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_STACK_ADDR_A                  0x000418 /* established */
#define BEDROCK_PI_ERR_STACK_ADDR_A_ESAA_ADDR_SHIFT  3 /* established */
#define BEDROCK_PI_ERR_STACK_ADDR_A_ESAA_ADDR_MASK   0x3fffffffull
#define BEDROCK_PI_ERR_STACK_ADDR_A_ESAA_ADDR_INPLACE (BEDROCK_PI_ERR_STACK_ADDR_A_ESAA_ADDR_MASK << BEDROCK_PI_ERR_STACK_ADDR_A_ESAA_ADDR_SHIFT)

/*
 * Address of the next write to the CPU B error stack. It increments after each
 * write, and only the low bits that the stack size selects count up. The header
 * says it is not reset by a soft reset.
 */
/* err_stack_addr_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_STACK_ADDR_B                  0x000420 /* established */
#define BEDROCK_PI_ERR_STACK_ADDR_B_ESAB_ADDR_SHIFT  3 /* established */
#define BEDROCK_PI_ERR_STACK_ADDR_B_ESAB_ADDR_MASK   0x3fffffffull
#define BEDROCK_PI_ERR_STACK_ADDR_B_ESAB_ADDR_INPLACE (BEDROCK_PI_ERR_STACK_ADDR_B_ESAB_ADDR_MASK << BEDROCK_PI_ERR_STACK_ADDR_B_ESAB_ADDR_SHIFT)

/*
 * Size of the error stack that is spooled to local memory when an error occurs.
 * The header describes it as a count of 64-bit entries and says it is not reset
 * by a soft reset. The encoding of the four-bit field is not given in this
 * header.
 */
/* err_stack_size: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_STACK_SIZE                    0x000428 /* established */
#define BEDROCK_PI_ERR_STACK_SIZE_ESS_SIZE_SHIFT     0 /* established */
#define BEDROCK_PI_ERR_STACK_SIZE_ESS_SIZE_MASK      0xfull
#define BEDROCK_PI_ERR_STACK_SIZE_ESS_SIZE_INPLACE (BEDROCK_PI_ERR_STACK_SIZE_ESS_SIZE_MASK << BEDROCK_PI_ERR_STACK_SIZE_ESS_SIZE_SHIFT)

/*
 * First error status record for CPU A. Saved only when the valid bit is set.
 * Writing the matching clear alias clears both status records for this CPU. The
 * header says it is not reset by a soft reset.
 */
/* err_status0_a: r64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_STATUS0_A                     0x000430 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_ESA_VALID_SHIFT     63 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_ESA_VALID_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS0_A_ESA_VALID_INPLACE (BEDROCK_PI_ERR_STATUS0_A_ESA_VALID_MASK << BEDROCK_PI_ERR_STATUS0_A_ESA_VALID_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_A_ESA_OVER_RUN_SHIFT  62 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_ESA_OVER_RUN_MASK   0x1ull
#define BEDROCK_PI_ERR_STATUS0_A_ESA_OVER_RUN_INPLACE (BEDROCK_PI_ERR_STATUS0_A_ESA_OVER_RUN_MASK << BEDROCK_PI_ERR_STATUS0_A_ESA_OVER_RUN_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_A_ESA_ADDR_SHIFT      25 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_ESA_ADDR_MASK       0x1fffffffffull
#define BEDROCK_PI_ERR_STATUS0_A_ESA_ADDR_INPLACE (BEDROCK_PI_ERR_STATUS0_A_ESA_ADDR_MASK << BEDROCK_PI_ERR_STATUS0_A_ESA_ADDR_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_A_ESA_CMD_SHIFT       17 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_ESA_CMD_MASK        0xffull
#define BEDROCK_PI_ERR_STATUS0_A_ESA_CMD_INPLACE (BEDROCK_PI_ERR_STATUS0_A_ESA_CMD_MASK << BEDROCK_PI_ERR_STATUS0_A_ESA_CMD_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_A_ESA_SUPPLEMENTAL_SHIFT 6 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_ESA_SUPPLEMENTAL_MASK 0x7ffull
#define BEDROCK_PI_ERR_STATUS0_A_ESA_SUPPLEMENTAL_INPLACE (BEDROCK_PI_ERR_STATUS0_A_ESA_SUPPLEMENTAL_MASK << BEDROCK_PI_ERR_STATUS0_A_ESA_SUPPLEMENTAL_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_A_ESA_PROC_REQ_NUM_SHIFT 3 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_ESA_PROC_REQ_NUM_MASK 0x7ull
#define BEDROCK_PI_ERR_STATUS0_A_ESA_PROC_REQ_NUM_INPLACE (BEDROCK_PI_ERR_STATUS0_A_ESA_PROC_REQ_NUM_MASK << BEDROCK_PI_ERR_STATUS0_A_ESA_PROC_REQ_NUM_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_A_ESA_ERROR_TYPE_SHIFT 0 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_ESA_ERROR_TYPE_MASK 0x7ull
#define BEDROCK_PI_ERR_STATUS0_A_ESA_ERROR_TYPE_INPLACE (BEDROCK_PI_ERR_STATUS0_A_ESA_ERROR_TYPE_MASK << BEDROCK_PI_ERR_STATUS0_A_ESA_ERROR_TYPE_SHIFT)

/*
 * Write-clear alias of the first error status record for CPU A. Any write
 * clears both the status 0 and status 1 records for this CPU.
 */
/* err_status0_a_clr: w64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_STATUS0_A_CLR                 0x000438 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_VALID_SHIFT 63 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_VALID_MASK 0x1ull
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_VALID_INPLACE (BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_VALID_MASK << BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_VALID_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_OVER_RUN_SHIFT 62 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_OVER_RUN_MASK 0x1ull
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_OVER_RUN_INPLACE (BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_OVER_RUN_MASK << BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_OVER_RUN_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_ADDR_SHIFT 25 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_ADDR_MASK  0x1fffffffffull
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_ADDR_INPLACE (BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_ADDR_MASK << BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_ADDR_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_CMD_SHIFT  17 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_CMD_MASK   0xffull
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_CMD_INPLACE (BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_CMD_MASK << BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_CMD_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_SUPPLEMENTAL_SHIFT 6 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_SUPPLEMENTAL_MASK 0x7ffull
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_SUPPLEMENTAL_INPLACE (BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_SUPPLEMENTAL_MASK << BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_SUPPLEMENTAL_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_PROC_REQ_NUM_SHIFT 3 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_PROC_REQ_NUM_MASK 0x7ull
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_PROC_REQ_NUM_INPLACE (BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_PROC_REQ_NUM_MASK << BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_PROC_REQ_NUM_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_ERROR_TYPE_SHIFT 0 /* established */
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_ERROR_TYPE_MASK 0x7ull
#define BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_ERROR_TYPE_INPLACE (BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_ERROR_TYPE_MASK << BEDROCK_PI_ERR_STATUS0_A_CLR_ESCA_ERROR_TYPE_SHIFT)

/*
 * Second error status record for CPU A. The header says it is not reset by a
 * soft reset.
 */
/* err_status1_a: r64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_STATUS1_A                     0x000440 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_SOURCE_SHIFT        53 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_SOURCE_MASK         0x7ffull
#define BEDROCK_PI_ERR_STATUS1_A_SOURCE_INPLACE (BEDROCK_PI_ERR_STATUS1_A_SOURCE_MASK << BEDROCK_PI_ERR_STATUS1_A_SOURCE_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_P_BIT_SHIFT         52 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_P_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_P_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_P_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_P_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_V_BIT_SHIFT         51 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_V_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_V_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_V_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_V_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_R_BIT_SHIFT         50 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_R_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_R_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_R_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_R_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_A_BIT_SHIFT         49 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_A_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_A_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_A_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_A_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_W_BIT_SHIFT         48 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_W_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_W_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_W_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_W_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_H_BIT_SHIFT         47 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_H_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_H_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_H_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_H_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_I_BIT_SHIFT         46 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_I_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_I_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_I_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_I_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_T_BIT_SHIFT         45 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_T_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_T_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_T_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_T_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_E_BITS_SHIFT        43 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_E_BITS_MASK         0x3ull
#define BEDROCK_PI_ERR_STATUS1_A_E_BITS_INPLACE (BEDROCK_PI_ERR_STATUS1_A_E_BITS_MASK << BEDROCK_PI_ERR_STATUS1_A_E_BITS_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_WRB_SHIFT           42 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_WRB_MASK            0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_WRB_INPLACE (BEDROCK_PI_ERR_STATUS1_A_WRB_MASK << BEDROCK_PI_ERR_STATUS1_A_WRB_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CRB_NUM_SHIFT       39 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CRB_NUM_MASK        0x7ull
#define BEDROCK_PI_ERR_STATUS1_A_CRB_NUM_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CRB_NUM_MASK << BEDROCK_PI_ERR_STATUS1_A_CRB_NUM_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_INVAL_COUNT_SHIFT   29 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_INVAL_COUNT_MASK    0x3ffull
#define BEDROCK_PI_ERR_STATUS1_A_INVAL_COUNT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_INVAL_COUNT_MASK << BEDROCK_PI_ERR_STATUS1_A_INVAL_COUNT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_TIME_OUT_COUNT_SHIFT 21 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_TIME_OUT_COUNT_MASK 0xffull
#define BEDROCK_PI_ERR_STATUS1_A_TIME_OUT_COUNT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_TIME_OUT_COUNT_MASK << BEDROCK_PI_ERR_STATUS1_A_TIME_OUT_COUNT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_SPOOL_COUNT_SHIFT   0 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_SPOOL_COUNT_MASK    0x1fffffull
#define BEDROCK_PI_ERR_STATUS1_A_SPOOL_COUNT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_SPOOL_COUNT_MASK << BEDROCK_PI_ERR_STATUS1_A_SPOOL_COUNT_SHIFT)

/*
 * Write-clear alias of the second error status record for CPU A. Any write
 * clears both status records for this CPU.
 */
/* err_status1_a_clr: w64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_STATUS1_A_CLR                 0x000448 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_SOURCE_SHIFT    53 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_SOURCE_MASK     0x7ffull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_SOURCE_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_SOURCE_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_SOURCE_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_P_BIT_SHIFT     52 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_P_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_P_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_P_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_P_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_V_BIT_SHIFT     51 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_V_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_V_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_V_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_V_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_R_BIT_SHIFT     50 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_R_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_R_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_R_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_R_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_A_BIT_SHIFT     49 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_A_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_A_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_A_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_A_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_W_BIT_SHIFT     48 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_W_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_W_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_W_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_W_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_H_BIT_SHIFT     47 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_H_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_H_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_H_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_H_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_I_BIT_SHIFT     46 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_I_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_I_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_I_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_I_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_T_BIT_SHIFT     45 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_T_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_T_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_T_BIT_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_T_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_E_BITS_SHIFT    43 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_E_BITS_MASK     0x3ull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_E_BITS_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_E_BITS_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_E_BITS_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_WRB_SHIFT       42 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_WRB_MASK        0x1ull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_WRB_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_WRB_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_WRB_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_CRB_NUM_SHIFT   39 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_CRB_NUM_MASK    0x7ull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_CRB_NUM_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_CRB_NUM_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_CRB_NUM_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_INVAL_COUNT_SHIFT 29 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_INVAL_COUNT_MASK 0x3ffull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_INVAL_COUNT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_INVAL_COUNT_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_INVAL_COUNT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_TIME_OUT_COUNT_SHIFT 21 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_TIME_OUT_COUNT_MASK 0xffull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_TIME_OUT_COUNT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_TIME_OUT_COUNT_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_TIME_OUT_COUNT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_A_CLR_SPOOL_COUNT_SHIFT 0 /* established */
#define BEDROCK_PI_ERR_STATUS1_A_CLR_SPOOL_COUNT_MASK 0x1fffffull
#define BEDROCK_PI_ERR_STATUS1_A_CLR_SPOOL_COUNT_INPLACE (BEDROCK_PI_ERR_STATUS1_A_CLR_SPOOL_COUNT_MASK << BEDROCK_PI_ERR_STATUS1_A_CLR_SPOOL_COUNT_SHIFT)

/*
 * First error status record for CPU B. Saved only when the valid bit is set.
 * Writing the matching clear alias clears both status records for this CPU. The
 * header says it is not reset by a soft reset.
 */
/* err_status0_b: r64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_STATUS0_B                     0x000450 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_ESB_VALID_SHIFT     63 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_ESB_VALID_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS0_B_ESB_VALID_INPLACE (BEDROCK_PI_ERR_STATUS0_B_ESB_VALID_MASK << BEDROCK_PI_ERR_STATUS0_B_ESB_VALID_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_B_ESB_OVER_RUN_SHIFT  62 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_ESB_OVER_RUN_MASK   0x1ull
#define BEDROCK_PI_ERR_STATUS0_B_ESB_OVER_RUN_INPLACE (BEDROCK_PI_ERR_STATUS0_B_ESB_OVER_RUN_MASK << BEDROCK_PI_ERR_STATUS0_B_ESB_OVER_RUN_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_B_ESB_ADDR_SHIFT      25 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_ESB_ADDR_MASK       0x1fffffffffull
#define BEDROCK_PI_ERR_STATUS0_B_ESB_ADDR_INPLACE (BEDROCK_PI_ERR_STATUS0_B_ESB_ADDR_MASK << BEDROCK_PI_ERR_STATUS0_B_ESB_ADDR_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_B_ESB_CMD_SHIFT       17 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_ESB_CMD_MASK        0xffull
#define BEDROCK_PI_ERR_STATUS0_B_ESB_CMD_INPLACE (BEDROCK_PI_ERR_STATUS0_B_ESB_CMD_MASK << BEDROCK_PI_ERR_STATUS0_B_ESB_CMD_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_B_ESB_SUPPLEMENTAL_SHIFT 6 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_ESB_SUPPLEMENTAL_MASK 0x7ffull
#define BEDROCK_PI_ERR_STATUS0_B_ESB_SUPPLEMENTAL_INPLACE (BEDROCK_PI_ERR_STATUS0_B_ESB_SUPPLEMENTAL_MASK << BEDROCK_PI_ERR_STATUS0_B_ESB_SUPPLEMENTAL_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_B_ESB_PROC_REQ_NUM_SHIFT 3 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_ESB_PROC_REQ_NUM_MASK 0x7ull
#define BEDROCK_PI_ERR_STATUS0_B_ESB_PROC_REQ_NUM_INPLACE (BEDROCK_PI_ERR_STATUS0_B_ESB_PROC_REQ_NUM_MASK << BEDROCK_PI_ERR_STATUS0_B_ESB_PROC_REQ_NUM_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_B_ESB_ERROR_TYPE_SHIFT 0 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_ESB_ERROR_TYPE_MASK 0x7ull
#define BEDROCK_PI_ERR_STATUS0_B_ESB_ERROR_TYPE_INPLACE (BEDROCK_PI_ERR_STATUS0_B_ESB_ERROR_TYPE_MASK << BEDROCK_PI_ERR_STATUS0_B_ESB_ERROR_TYPE_SHIFT)

/*
 * Write-clear alias of the first error status record for CPU B. Any write
 * clears both the status 0 and status 1 records for this CPU.
 */
/* err_status0_b_clr: w64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_STATUS0_B_CLR                 0x000458 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_VALID_SHIFT 63 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_VALID_MASK 0x1ull
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_VALID_INPLACE (BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_VALID_MASK << BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_VALID_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_OVER_RUN_SHIFT 62 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_OVER_RUN_MASK 0x1ull
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_OVER_RUN_INPLACE (BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_OVER_RUN_MASK << BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_OVER_RUN_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_ADDR_SHIFT 25 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_ADDR_MASK  0x1fffffffffull
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_ADDR_INPLACE (BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_ADDR_MASK << BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_ADDR_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_CMD_SHIFT  17 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_CMD_MASK   0xffull
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_CMD_INPLACE (BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_CMD_MASK << BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_CMD_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_SUPPLEMENTAL_SHIFT 6 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_SUPPLEMENTAL_MASK 0x7ffull
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_SUPPLEMENTAL_INPLACE (BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_SUPPLEMENTAL_MASK << BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_SUPPLEMENTAL_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_PROC_REQ_NUM_SHIFT 3 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_PROC_REQ_NUM_MASK 0x7ull
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_PROC_REQ_NUM_INPLACE (BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_PROC_REQ_NUM_MASK << BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_PROC_REQ_NUM_SHIFT)
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_ERROR_TYPE_SHIFT 0 /* established */
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_ERROR_TYPE_MASK 0x7ull
#define BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_ERROR_TYPE_INPLACE (BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_ERROR_TYPE_MASK << BEDROCK_PI_ERR_STATUS0_B_CLR_ESCB_ERROR_TYPE_SHIFT)

/*
 * Second error status record for CPU B. The header says it is not reset by a
 * soft reset.
 */
/* err_status1_b: r64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_STATUS1_B                     0x000460 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_SOURCE_SHIFT        53 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_SOURCE_MASK         0x7ffull
#define BEDROCK_PI_ERR_STATUS1_B_SOURCE_INPLACE (BEDROCK_PI_ERR_STATUS1_B_SOURCE_MASK << BEDROCK_PI_ERR_STATUS1_B_SOURCE_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_P_BIT_SHIFT         52 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_P_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_P_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_P_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_P_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_V_BIT_SHIFT         51 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_V_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_V_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_V_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_V_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_R_BIT_SHIFT         50 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_R_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_R_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_R_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_R_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_A_BIT_SHIFT         49 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_A_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_A_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_A_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_A_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_W_BIT_SHIFT         48 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_W_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_W_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_W_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_W_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_H_BIT_SHIFT         47 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_H_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_H_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_H_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_H_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_I_BIT_SHIFT         46 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_I_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_I_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_I_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_I_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_T_BIT_SHIFT         45 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_T_BIT_MASK          0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_T_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_T_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_T_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_E_BITS_SHIFT        43 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_E_BITS_MASK         0x3ull
#define BEDROCK_PI_ERR_STATUS1_B_E_BITS_INPLACE (BEDROCK_PI_ERR_STATUS1_B_E_BITS_MASK << BEDROCK_PI_ERR_STATUS1_B_E_BITS_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_WRB_SHIFT           42 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_WRB_MASK            0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_WRB_INPLACE (BEDROCK_PI_ERR_STATUS1_B_WRB_MASK << BEDROCK_PI_ERR_STATUS1_B_WRB_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CRB_NUM_SHIFT       39 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CRB_NUM_MASK        0x7ull
#define BEDROCK_PI_ERR_STATUS1_B_CRB_NUM_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CRB_NUM_MASK << BEDROCK_PI_ERR_STATUS1_B_CRB_NUM_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_INVAL_COUNT_SHIFT   29 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_INVAL_COUNT_MASK    0x3ffull
#define BEDROCK_PI_ERR_STATUS1_B_INVAL_COUNT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_INVAL_COUNT_MASK << BEDROCK_PI_ERR_STATUS1_B_INVAL_COUNT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_TIME_OUT_COUNT_SHIFT 21 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_TIME_OUT_COUNT_MASK 0xffull
#define BEDROCK_PI_ERR_STATUS1_B_TIME_OUT_COUNT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_TIME_OUT_COUNT_MASK << BEDROCK_PI_ERR_STATUS1_B_TIME_OUT_COUNT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_SPOOL_COUNT_SHIFT   0 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_SPOOL_COUNT_MASK    0x1fffffull
#define BEDROCK_PI_ERR_STATUS1_B_SPOOL_COUNT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_SPOOL_COUNT_MASK << BEDROCK_PI_ERR_STATUS1_B_SPOOL_COUNT_SHIFT)

/*
 * Write-clear alias of the second error status record for CPU B. Any write
 * clears both status records for this CPU.
 */
/* err_status1_b_clr: w64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_STATUS1_B_CLR                 0x000468 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_SOURCE_SHIFT    53 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_SOURCE_MASK     0x7ffull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_SOURCE_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_SOURCE_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_SOURCE_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_P_BIT_SHIFT     52 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_P_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_P_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_P_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_P_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_V_BIT_SHIFT     51 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_V_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_V_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_V_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_V_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_R_BIT_SHIFT     50 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_R_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_R_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_R_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_R_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_A_BIT_SHIFT     49 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_A_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_A_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_A_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_A_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_W_BIT_SHIFT     48 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_W_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_W_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_W_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_W_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_H_BIT_SHIFT     47 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_H_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_H_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_H_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_H_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_I_BIT_SHIFT     46 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_I_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_I_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_I_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_I_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_T_BIT_SHIFT     45 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_T_BIT_MASK      0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_T_BIT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_T_BIT_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_T_BIT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_E_BITS_SHIFT    43 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_E_BITS_MASK     0x3ull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_E_BITS_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_E_BITS_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_E_BITS_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_WRB_SHIFT       42 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_WRB_MASK        0x1ull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_WRB_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_WRB_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_WRB_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_CRB_NUM_SHIFT   39 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_CRB_NUM_MASK    0x7ull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_CRB_NUM_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_CRB_NUM_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_CRB_NUM_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_INVAL_COUNT_SHIFT 29 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_INVAL_COUNT_MASK 0x3ffull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_INVAL_COUNT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_INVAL_COUNT_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_INVAL_COUNT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_TIME_OUT_COUNT_SHIFT 21 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_TIME_OUT_COUNT_MASK 0xffull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_TIME_OUT_COUNT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_TIME_OUT_COUNT_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_TIME_OUT_COUNT_SHIFT)
#define BEDROCK_PI_ERR_STATUS1_B_CLR_SPOOL_COUNT_SHIFT 0 /* established */
#define BEDROCK_PI_ERR_STATUS1_B_CLR_SPOOL_COUNT_MASK 0x1fffffull
#define BEDROCK_PI_ERR_STATUS1_B_CLR_SPOOL_COUNT_INPLACE (BEDROCK_PI_ERR_STATUS1_B_CLR_SPOOL_COUNT_MASK << BEDROCK_PI_ERR_STATUS1_B_CLR_SPOOL_COUNT_SHIFT)

/*
 * Spool compare for CPU A. The header gives the field only.
 */
/* spool_cmp_a: rw64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_SPOOL_CMP_A                       0x000470 /* established */
#define BEDROCK_PI_SPOOL_CMP_A_SCA_COMPARE_SHIFT     0 /* established */
#define BEDROCK_PI_SPOOL_CMP_A_SCA_COMPARE_MASK      0xfffffull
#define BEDROCK_PI_SPOOL_CMP_A_SCA_COMPARE_INPLACE (BEDROCK_PI_SPOOL_CMP_A_SCA_COMPARE_MASK << BEDROCK_PI_SPOOL_CMP_A_SCA_COMPARE_SHIFT)

/*
 * Spool compare for CPU B. The header gives the field only.
 */
/* spool_cmp_b: rw64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_SPOOL_CMP_B                       0x000478 /* established */
#define BEDROCK_PI_SPOOL_CMP_B_SCB_COMPARE_SHIFT     0 /* established */
#define BEDROCK_PI_SPOOL_CMP_B_SCB_COMPARE_MASK      0xfffffull
#define BEDROCK_PI_SPOOL_CMP_B_SCB_COMPARE_INPLACE (BEDROCK_PI_SPOOL_CMP_B_SCB_COMPARE_MASK << BEDROCK_PI_SPOOL_CMP_B_SCB_COMPARE_SHIFT)

/*
 * Coherency request buffer timeout. The header says a timeout can be forced by
 * writing one bits; the two fields are named read and write.
 */
/* crb_timeout_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_CRB_TIMEOUT_A                     0x000480 /* established */
#define BEDROCK_PI_CRB_TIMEOUT_A_CTA_WRB_SHIFT       4 /* established */
#define BEDROCK_PI_CRB_TIMEOUT_A_CTA_WRB_MASK        0xffull
#define BEDROCK_PI_CRB_TIMEOUT_A_CTA_WRB_INPLACE (BEDROCK_PI_CRB_TIMEOUT_A_CTA_WRB_MASK << BEDROCK_PI_CRB_TIMEOUT_A_CTA_WRB_SHIFT)
#define BEDROCK_PI_CRB_TIMEOUT_A_CTA_RRB_SHIFT       0 /* established */
#define BEDROCK_PI_CRB_TIMEOUT_A_CTA_RRB_MASK        0xfull
#define BEDROCK_PI_CRB_TIMEOUT_A_CTA_RRB_INPLACE (BEDROCK_PI_CRB_TIMEOUT_A_CTA_RRB_MASK << BEDROCK_PI_CRB_TIMEOUT_A_CTA_RRB_SHIFT)

/*
 * Coherency request buffer timeout. The header says a timeout can be forced by
 * writing one bits; the two fields are named read and write.
 */
/* crb_timeout_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_CRB_TIMEOUT_B                     0x000488 /* established */
#define BEDROCK_PI_CRB_TIMEOUT_B_CTB_WRB_SHIFT       4 /* established */
#define BEDROCK_PI_CRB_TIMEOUT_B_CTB_WRB_MASK        0xffull
#define BEDROCK_PI_CRB_TIMEOUT_B_CTB_WRB_INPLACE (BEDROCK_PI_CRB_TIMEOUT_B_CTB_WRB_MASK << BEDROCK_PI_CRB_TIMEOUT_B_CTB_WRB_SHIFT)
#define BEDROCK_PI_CRB_TIMEOUT_B_CTB_RRB_SHIFT       0 /* established */
#define BEDROCK_PI_CRB_TIMEOUT_B_CTB_RRB_MASK        0xfull
#define BEDROCK_PI_CRB_TIMEOUT_B_CTB_RRB_INPLACE (BEDROCK_PI_CRB_TIMEOUT_B_CTB_RRB_MASK << BEDROCK_PI_CRB_TIMEOUT_B_CTB_RRB_SHIFT)

/*
 * Controls error checking and forwarding of system bus errors. The header does
 * not give a reset value.
 */
/* sysad_errchk_en: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_SYSAD_ERRCHK_EN                   0x000490 /* established */
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_QUAL_CHK_EN_SHIFT 5 /* established */
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_QUAL_CHK_EN_MASK 0x1ull
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_QUAL_CHK_EN_INPLACE (BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_QUAL_CHK_EN_MASK << BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_QUAL_CHK_EN_SHIFT)
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_STATE_CHK_EN_SHIFT 4 /* established */
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_STATE_CHK_EN_MASK 0x1ull
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_STATE_CHK_EN_INPLACE (BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_STATE_CHK_EN_MASK << BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_STATE_CHK_EN_SHIFT)
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_CMDP_CHK_EN_SHIFT 3 /* established */
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_CMDP_CHK_EN_MASK 0x1ull
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_CMDP_CHK_EN_INPLACE (BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_CMDP_CHK_EN_MASK << BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_CMDP_CHK_EN_SHIFT)
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_SADP_CHK_EN_SHIFT 2 /* established */
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_SADP_CHK_EN_MASK 0x1ull
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_SADP_CHK_EN_INPLACE (BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_SADP_CHK_EN_MASK << BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_SADP_CHK_EN_SHIFT)
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_QUAL_GEN_EN_SHIFT 1 /* established */
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_QUAL_GEN_EN_MASK 0x1ull
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_QUAL_GEN_EN_INPLACE (BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_QUAL_GEN_EN_MASK << BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_QUAL_GEN_EN_SHIFT)
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_ECC_GEN_EN_SHIFT 0 /* established */
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_ECC_GEN_EN_MASK 0x1ull
#define BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_ECC_GEN_EN_INPLACE (BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_ECC_GEN_EN_MASK << BEDROCK_PI_SYSAD_ERRCHK_EN_SEE_ECC_GEN_EN_SHIFT)

/*
 * For CPU A: when reply data arrives with the uncorrectable indicator set, the
 * check bits sent on the system bus are inverted in each set position, and the
 * data quality indicator is not asserted.
 */
/* force_bad_check_bit_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_FORCE_BAD_CHECK_BIT_A             0x000498 /* established */
/* established */
#define BEDROCK_PI_FORCE_BAD_CHECK_BIT_A_FBCBA_BAD_CHECK_BIT_SHIFT 0
#define BEDROCK_PI_FORCE_BAD_CHECK_BIT_A_FBCBA_BAD_CHECK_BIT_MASK 0xffull
#define BEDROCK_PI_FORCE_BAD_CHECK_BIT_A_FBCBA_BAD_CHECK_BIT_INPLACE (BEDROCK_PI_FORCE_BAD_CHECK_BIT_A_FBCBA_BAD_CHECK_BIT_MASK << BEDROCK_PI_FORCE_BAD_CHECK_BIT_A_FBCBA_BAD_CHECK_BIT_SHIFT)

/*
 * For CPU B: when reply data arrives with the uncorrectable indicator set, the
 * check bits sent on the system bus are inverted in each set position, and the
 * data quality indicator is not asserted.
 */
/* force_bad_check_bit_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_FORCE_BAD_CHECK_BIT_B             0x0004a0 /* established */
/* established */
#define BEDROCK_PI_FORCE_BAD_CHECK_BIT_B_FBCBB_BAD_CHECK_BIT_SHIFT 0
#define BEDROCK_PI_FORCE_BAD_CHECK_BIT_B_FBCBB_BAD_CHECK_BIT_MASK 0xffull
#define BEDROCK_PI_FORCE_BAD_CHECK_BIT_B_FBCBB_BAD_CHECK_BIT_INPLACE (BEDROCK_PI_FORCE_BAD_CHECK_BIT_B_FBCBB_BAD_CHECK_BIT_MASK << BEDROCK_PI_FORCE_BAD_CHECK_BIT_B_FBCBB_BAD_CHECK_BIT_SHIFT)

/*
 * Counts CPU A's negative acknowledgements while the count is enabled. The
 * count clears on any other reply. When a negative acknowledgement arrives with
 * the count equal to the compare, the count clears, the processor gets an error
 * reply instead, and the CPU A NACK bit is set.
 */
/* nack_cnt_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_NACK_CNT_A                        0x0004a8 /* established */
#define BEDROCK_PI_NACK_CNT_A_NCA_CNT_EN_SHIFT       20 /* established */
#define BEDROCK_PI_NACK_CNT_A_NCA_CNT_EN_MASK        0x1ull
#define BEDROCK_PI_NACK_CNT_A_NCA_CNT_EN_INPLACE (BEDROCK_PI_NACK_CNT_A_NCA_CNT_EN_MASK << BEDROCK_PI_NACK_CNT_A_NCA_CNT_EN_SHIFT)
#define BEDROCK_PI_NACK_CNT_A_NCA_NACK_CNT_SHIFT     0 /* established */
#define BEDROCK_PI_NACK_CNT_A_NCA_NACK_CNT_MASK      0xfffffull
#define BEDROCK_PI_NACK_CNT_A_NCA_NACK_CNT_INPLACE (BEDROCK_PI_NACK_CNT_A_NCA_NACK_CNT_MASK << BEDROCK_PI_NACK_CNT_A_NCA_NACK_CNT_SHIFT)

/*
 * Counts CPU B's negative acknowledgements while the count is enabled. The
 * count clears on any other reply. When a negative acknowledgement arrives with
 * the count equal to the compare, the count clears, the processor gets an error
 * reply instead, and the CPU B NACK bit is set.
 */
/* nack_cnt_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_NACK_CNT_B                        0x0004b0 /* established */
#define BEDROCK_PI_NACK_CNT_B_NCB_CNT_EN_SHIFT       20 /* established */
#define BEDROCK_PI_NACK_CNT_B_NCB_CNT_EN_MASK        0x1ull
#define BEDROCK_PI_NACK_CNT_B_NCB_CNT_EN_INPLACE (BEDROCK_PI_NACK_CNT_B_NCB_CNT_EN_MASK << BEDROCK_PI_NACK_CNT_B_NCB_CNT_EN_SHIFT)
#define BEDROCK_PI_NACK_CNT_B_NCB_NACK_CNT_SHIFT     0 /* established */
#define BEDROCK_PI_NACK_CNT_B_NCB_NACK_CNT_MASK      0xfffffull
#define BEDROCK_PI_NACK_CNT_B_NCB_NACK_CNT_INPLACE (BEDROCK_PI_NACK_CNT_B_NCB_NACK_CNT_MASK << BEDROCK_PI_NACK_CNT_B_NCB_NACK_CNT_SHIFT)

/*
 * Compare value for both NACK counts. It affects both processors on this
 * interface.
 */
/* nack_cmp: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_NACK_CMP                          0x0004b8 /* established */
#define BEDROCK_PI_NACK_CMP_NC_NACK_CMP_SHIFT        0 /* established */
#define BEDROCK_PI_NACK_CMP_NC_NACK_CMP_MASK         0xfffffull
#define BEDROCK_PI_NACK_CMP_NC_NACK_CMP_INPLACE (BEDROCK_PI_NACK_CMP_NC_NACK_CMP_MASK << BEDROCK_PI_NACK_CMP_NC_NACK_CMP_SHIFT)

/*
 * Chooses which error kinds are spooled. A set bit spools that error. It
 * affects both processors on this interface.
 */
/* spool_mask: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_SPOOL_MASK                        0x0004c0 /* established */
#define BEDROCK_PI_SPOOL_MASK_SM_NACK_OFLOW_ERR_SHIFT 5 /* established */
#define BEDROCK_PI_SPOOL_MASK_SM_NACK_OFLOW_ERR_MASK 0x1ull
#define BEDROCK_PI_SPOOL_MASK_SM_NACK_OFLOW_ERR_INPLACE (BEDROCK_PI_SPOOL_MASK_SM_NACK_OFLOW_ERR_MASK << BEDROCK_PI_SPOOL_MASK_SM_NACK_OFLOW_ERR_SHIFT)
#define BEDROCK_PI_SPOOL_MASK_SM_POISON_ERR_SHIFT    4 /* established */
#define BEDROCK_PI_SPOOL_MASK_SM_POISON_ERR_MASK     0x1ull
#define BEDROCK_PI_SPOOL_MASK_SM_POISON_ERR_INPLACE (BEDROCK_PI_SPOOL_MASK_SM_POISON_ERR_MASK << BEDROCK_PI_SPOOL_MASK_SM_POISON_ERR_SHIFT)
#define BEDROCK_PI_SPOOL_MASK_SM_TIMEOUT_ERR_SHIFT   3 /* established */
#define BEDROCK_PI_SPOOL_MASK_SM_TIMEOUT_ERR_MASK    0x1ull
#define BEDROCK_PI_SPOOL_MASK_SM_TIMEOUT_ERR_INPLACE (BEDROCK_PI_SPOOL_MASK_SM_TIMEOUT_ERR_MASK << BEDROCK_PI_SPOOL_MASK_SM_TIMEOUT_ERR_SHIFT)
#define BEDROCK_PI_SPOOL_MASK_SM_DIR_ERR_SHIFT       2 /* established */
#define BEDROCK_PI_SPOOL_MASK_SM_DIR_ERR_MASK        0x1ull
#define BEDROCK_PI_SPOOL_MASK_SM_DIR_ERR_INPLACE (BEDROCK_PI_SPOOL_MASK_SM_DIR_ERR_MASK << BEDROCK_PI_SPOOL_MASK_SM_DIR_ERR_SHIFT)
#define BEDROCK_PI_SPOOL_MASK_SM_UNCACHED_ERR_SHIFT  1 /* established */
#define BEDROCK_PI_SPOOL_MASK_SM_UNCACHED_ERR_MASK   0x1ull
#define BEDROCK_PI_SPOOL_MASK_SM_UNCACHED_ERR_INPLACE (BEDROCK_PI_SPOOL_MASK_SM_UNCACHED_ERR_MASK << BEDROCK_PI_SPOOL_MASK_SM_UNCACHED_ERR_SHIFT)
#define BEDROCK_PI_SPOOL_MASK_SM_ACCESS_ERR_SHIFT    0 /* established */
#define BEDROCK_PI_SPOOL_MASK_SM_ACCESS_ERR_MASK     0x1ull
#define BEDROCK_PI_SPOOL_MASK_SM_ACCESS_ERR_INPLACE (BEDROCK_PI_SPOOL_MASK_SM_ACCESS_ERR_MASK << BEDROCK_PI_SPOOL_MASK_SM_ACCESS_ERR_SHIFT)

/*
 * Captures the header of an incoming message that matches no coherency request
 * buffer entry while the valid bit is clear. Write zero to clear. The header
 * says it is not reset by a soft reset.
 */
/* spurious_hdr_0: rw64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_SPURIOUS_HDR_0                    0x0004c8 /* established */
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_VALID_SHIFT    63 /* established */
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_VALID_MASK     0x1ull
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_VALID_INPLACE (BEDROCK_PI_SPURIOUS_HDR_0_SH0_VALID_MASK << BEDROCK_PI_SPURIOUS_HDR_0_SH0_VALID_SHIFT)
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_TAIL_SHIFT     62 /* established */
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_TAIL_MASK      0x1ull
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_TAIL_INPLACE (BEDROCK_PI_SPURIOUS_HDR_0_SH0_TAIL_MASK << BEDROCK_PI_SPURIOUS_HDR_0_SH0_TAIL_SHIFT)
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_ADDR_SHIFT     25 /* established */
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_ADDR_MASK      0x1fffffffffull
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_ADDR_INPLACE (BEDROCK_PI_SPURIOUS_HDR_0_SH0_ADDR_MASK << BEDROCK_PI_SPURIOUS_HDR_0_SH0_ADDR_SHIFT)
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_CMD_SHIFT      17 /* established */
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_CMD_MASK       0xffull
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_CMD_INPLACE (BEDROCK_PI_SPURIOUS_HDR_0_SH0_CMD_MASK << BEDROCK_PI_SPURIOUS_HDR_0_SH0_CMD_SHIFT)
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_SUPPLEMENTAL_SHIFT 6 /* established */
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_SUPPLEMENTAL_MASK 0x7ffull
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_SUPPLEMENTAL_INPLACE (BEDROCK_PI_SPURIOUS_HDR_0_SH0_SUPPLEMENTAL_MASK << BEDROCK_PI_SPURIOUS_HDR_0_SH0_SUPPLEMENTAL_SHIFT)
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_PREV_VALID_A_SHIFT 1 /* established */
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_PREV_VALID_A_MASK 0x1ull
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_PREV_VALID_A_INPLACE (BEDROCK_PI_SPURIOUS_HDR_0_SH0_PREV_VALID_A_MASK << BEDROCK_PI_SPURIOUS_HDR_0_SH0_PREV_VALID_A_SHIFT)
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_PREV_VALID_B_SHIFT 0 /* established */
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_PREV_VALID_B_MASK 0x1ull
#define BEDROCK_PI_SPURIOUS_HDR_0_SH0_PREV_VALID_B_INPLACE (BEDROCK_PI_SPURIOUS_HDR_0_SH0_PREV_VALID_B_MASK << BEDROCK_PI_SPURIOUS_HDR_0_SH0_PREV_VALID_B_SHIFT)

/*
 * Second half of the spurious message capture. Write zero to clear. The header
 * says it is not reset by a soft reset.
 */
/* spurious_hdr_1: rw64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_SPURIOUS_HDR_1                    0x0004d0 /* established */
#define BEDROCK_PI_SPURIOUS_HDR_1_SH1_SOURCE_SHIFT   53 /* established */
#define BEDROCK_PI_SPURIOUS_HDR_1_SH1_SOURCE_MASK    0x7ffull
#define BEDROCK_PI_SPURIOUS_HDR_1_SH1_SOURCE_INPLACE (BEDROCK_PI_SPURIOUS_HDR_1_SH1_SOURCE_MASK << BEDROCK_PI_SPURIOUS_HDR_1_SH1_SOURCE_SHIFT)

/*
 * Arms the injection of one error kind into the next outbound system bus
 * transfer of that type. The bit clears when the error is injected. Writing
 * does not cause a transaction. A bit stays set until a matching transfer
 * occurs, so software can poll it. Data quality injection is not in this
 * register.
 */
/* err_inject: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_ERR_INJECT                        0x0004d8 /* established */
#define BEDROCK_PI_ERR_INJECT_SYSRESP_PAR_B_SHIFT    38 /* established */
#define BEDROCK_PI_ERR_INJECT_SYSRESP_PAR_B_MASK     0x1ull
#define BEDROCK_PI_ERR_INJECT_SYSRESP_PAR_B_INPLACE (BEDROCK_PI_ERR_INJECT_SYSRESP_PAR_B_MASK << BEDROCK_PI_ERR_INJECT_SYSRESP_PAR_B_SHIFT)
#define BEDROCK_PI_ERR_INJECT_DATA_SYSAD_UNCECC_B_SHIFT 37 /* established */
#define BEDROCK_PI_ERR_INJECT_DATA_SYSAD_UNCECC_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INJECT_DATA_SYSAD_UNCECC_B_INPLACE (BEDROCK_PI_ERR_INJECT_DATA_SYSAD_UNCECC_B_MASK << BEDROCK_PI_ERR_INJECT_DATA_SYSAD_UNCECC_B_SHIFT)
#define BEDROCK_PI_ERR_INJECT_CMD_SYSAD_UNCECC_B_SHIFT 36 /* established */
#define BEDROCK_PI_ERR_INJECT_CMD_SYSAD_UNCECC_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INJECT_CMD_SYSAD_UNCECC_B_INPLACE (BEDROCK_PI_ERR_INJECT_CMD_SYSAD_UNCECC_B_MASK << BEDROCK_PI_ERR_INJECT_CMD_SYSAD_UNCECC_B_SHIFT)
#define BEDROCK_PI_ERR_INJECT_DATA_SYSAD_CORECC_B_SHIFT 35 /* established */
#define BEDROCK_PI_ERR_INJECT_DATA_SYSAD_CORECC_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INJECT_DATA_SYSAD_CORECC_B_INPLACE (BEDROCK_PI_ERR_INJECT_DATA_SYSAD_CORECC_B_MASK << BEDROCK_PI_ERR_INJECT_DATA_SYSAD_CORECC_B_SHIFT)
#define BEDROCK_PI_ERR_INJECT_CMD_SYSAD_CORECC_B_SHIFT 34 /* established */
#define BEDROCK_PI_ERR_INJECT_CMD_SYSAD_CORECC_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INJECT_CMD_SYSAD_CORECC_B_INPLACE (BEDROCK_PI_ERR_INJECT_CMD_SYSAD_CORECC_B_MASK << BEDROCK_PI_ERR_INJECT_CMD_SYSAD_CORECC_B_SHIFT)
#define BEDROCK_PI_ERR_INJECT_DATA_SYSCMD_PAR_B_SHIFT 33 /* established */
#define BEDROCK_PI_ERR_INJECT_DATA_SYSCMD_PAR_B_MASK 0x1ull
#define BEDROCK_PI_ERR_INJECT_DATA_SYSCMD_PAR_B_INPLACE (BEDROCK_PI_ERR_INJECT_DATA_SYSCMD_PAR_B_MASK << BEDROCK_PI_ERR_INJECT_DATA_SYSCMD_PAR_B_SHIFT)
#define BEDROCK_PI_ERR_INJECT_CMD_SYSCMD_PAR_B_SHIFT 32 /* established */
#define BEDROCK_PI_ERR_INJECT_CMD_SYSCMD_PAR_B_MASK  0x1ull
#define BEDROCK_PI_ERR_INJECT_CMD_SYSCMD_PAR_B_INPLACE (BEDROCK_PI_ERR_INJECT_CMD_SYSCMD_PAR_B_MASK << BEDROCK_PI_ERR_INJECT_CMD_SYSCMD_PAR_B_SHIFT)
#define BEDROCK_PI_ERR_INJECT_SYSRESP_PAR_A_SHIFT    6 /* established */
#define BEDROCK_PI_ERR_INJECT_SYSRESP_PAR_A_MASK     0x1ull
#define BEDROCK_PI_ERR_INJECT_SYSRESP_PAR_A_INPLACE (BEDROCK_PI_ERR_INJECT_SYSRESP_PAR_A_MASK << BEDROCK_PI_ERR_INJECT_SYSRESP_PAR_A_SHIFT)
#define BEDROCK_PI_ERR_INJECT_DATA_SYSAD_UNCECC_A_SHIFT 5 /* established */
#define BEDROCK_PI_ERR_INJECT_DATA_SYSAD_UNCECC_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INJECT_DATA_SYSAD_UNCECC_A_INPLACE (BEDROCK_PI_ERR_INJECT_DATA_SYSAD_UNCECC_A_MASK << BEDROCK_PI_ERR_INJECT_DATA_SYSAD_UNCECC_A_SHIFT)
#define BEDROCK_PI_ERR_INJECT_CMD_SYSAD_UNCECC_A_SHIFT 4 /* established */
#define BEDROCK_PI_ERR_INJECT_CMD_SYSAD_UNCECC_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INJECT_CMD_SYSAD_UNCECC_A_INPLACE (BEDROCK_PI_ERR_INJECT_CMD_SYSAD_UNCECC_A_MASK << BEDROCK_PI_ERR_INJECT_CMD_SYSAD_UNCECC_A_SHIFT)
#define BEDROCK_PI_ERR_INJECT_DATA_SYSAD_CORECC_A_SHIFT 3 /* established */
#define BEDROCK_PI_ERR_INJECT_DATA_SYSAD_CORECC_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INJECT_DATA_SYSAD_CORECC_A_INPLACE (BEDROCK_PI_ERR_INJECT_DATA_SYSAD_CORECC_A_MASK << BEDROCK_PI_ERR_INJECT_DATA_SYSAD_CORECC_A_SHIFT)
#define BEDROCK_PI_ERR_INJECT_CMD_SYSAD_CORECC_A_SHIFT 2 /* established */
#define BEDROCK_PI_ERR_INJECT_CMD_SYSAD_CORECC_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INJECT_CMD_SYSAD_CORECC_A_INPLACE (BEDROCK_PI_ERR_INJECT_CMD_SYSAD_CORECC_A_MASK << BEDROCK_PI_ERR_INJECT_CMD_SYSAD_CORECC_A_SHIFT)
#define BEDROCK_PI_ERR_INJECT_DATA_SYSCMD_PAR_A_SHIFT 1 /* established */
#define BEDROCK_PI_ERR_INJECT_DATA_SYSCMD_PAR_A_MASK 0x1ull
#define BEDROCK_PI_ERR_INJECT_DATA_SYSCMD_PAR_A_INPLACE (BEDROCK_PI_ERR_INJECT_DATA_SYSCMD_PAR_A_MASK << BEDROCK_PI_ERR_INJECT_DATA_SYSCMD_PAR_A_SHIFT)
#define BEDROCK_PI_ERR_INJECT_CMD_SYSCMD_PAR_A_SHIFT 0 /* established */
#define BEDROCK_PI_ERR_INJECT_CMD_SYSCMD_PAR_A_MASK  0x1ull
#define BEDROCK_PI_ERR_INJECT_CMD_SYSCMD_PAR_A_INPLACE (BEDROCK_PI_ERR_INJECT_CMD_SYSCMD_PAR_A_MASK << BEDROCK_PI_ERR_INJECT_CMD_SYSCMD_PAR_A_SHIFT)

/*
 * Stops the processors from issuing requests while the reply FIFO holds more
 * entries than this value. The FIFO holds 63 entries, so a value of 63 never
 * stops the processors, and a value of 0 stops them whenever any reply waits.
 * The register is in its own 64 KB page.
 */
/* reply_level: rw64, reset 0x10; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_REPLY_LEVEL                       0x010060 /* established */
#define BEDROCK_PI_REPLY_LEVEL_RL_REPLY_LEVEL_SHIFT  0 /* established */
#define BEDROCK_PI_REPLY_LEVEL_RL_REPLY_LEVEL_MASK   0x3full
#define BEDROCK_PI_REPLY_LEVEL_RL_REPLY_LEVEL_INPLACE (BEDROCK_PI_REPLY_LEVEL_RL_REPLY_LEVEL_MASK << BEDROCK_PI_REPLY_LEVEL_RL_REPLY_LEVEL_SHIFT)

/*
 * Switches the credit counter from counting doublewords to counting
 * transactions. The header puts it in its own 64 KB page so it can be mapped to
 * user space. Access is not stated; read and write is assumed.
 */
/* gfx_credit_mode: rw64, reset 0x1; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_GFX_CREDIT_MODE                   0x020068 /* established */
#define BEDROCK_PI_GFX_CREDIT_MODE_GCM_TRANS_MODE_SHIFT 0 /* established */
#define BEDROCK_PI_GFX_CREDIT_MODE_GCM_TRANS_MODE_MASK 0x1ull
#define BEDROCK_PI_GFX_CREDIT_MODE_GCM_TRANS_MODE_INPLACE (BEDROCK_PI_GFX_CREDIT_MODE_GCM_TRANS_MODE_MASK << BEDROCK_PI_GFX_CREDIT_MODE_GCM_TRANS_MODE_SHIFT)

/*
 * Real-time counter. It wraps to zero at its maximum value and increments on
 * each rising edge of the global clock. The header puts it in its own 64 KB
 * page so it can be mapped to user space.
 */
/* rt_counter: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_RT_COUNTER                        0x030100 /* established */
#define BEDROCK_PI_RT_COUNTER_RC_COUNT_SHIFT         0 /* established */
#define BEDROCK_PI_RT_COUNTER_RC_COUNT_MASK          0x7fffffffffffffull
#define BEDROCK_PI_RT_COUNTER_RC_COUNT_INPLACE (BEDROCK_PI_RT_COUNTER_RC_COUNT_MASK << BEDROCK_PI_RT_COUNTER_RC_COUNT_SHIFT)

/*
 * Controls the two performance counters of CPU A. The header says each counter
 * can be set to count one of several events but does not list the events.
 * Access is not stated; read and write is assumed.
 */
/* perf_cntl_a: rw64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_PERF_CNTL_A                       0x040200 /* established */
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_ENABLE_SHIFT 63 /* established */
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_ENABLE_MASK 0x1ull
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_ENABLE_INPLACE (BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_ENABLE_MASK << BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_ENABLE_SHIFT)
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_MODE_SHIFT 60 /* established */
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_MODE_MASK  0x7ull
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_MODE_INPLACE (BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_MODE_MASK << BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_MODE_SHIFT)
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_SELECT_SHIFT 32 /* established */
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_SELECT_MASK 0xfffffffull
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_SELECT_INPLACE (BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_SELECT_MASK << BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_1_SELECT_SHIFT)
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_ENABLE_SHIFT 31 /* established */
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_ENABLE_MASK 0x1ull
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_ENABLE_INPLACE (BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_ENABLE_MASK << BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_ENABLE_SHIFT)
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_MODE_SHIFT 28 /* established */
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_MODE_MASK  0x7ull
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_MODE_INPLACE (BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_MODE_MASK << BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_MODE_SHIFT)
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_SELECT_SHIFT 0 /* established */
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_SELECT_MASK 0xfffffffull
#define BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_SELECT_INPLACE (BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_SELECT_MASK << BEDROCK_PI_PERF_CNTL_A_PCA_CNTR_0_SELECT_SHIFT)

/*
 * Performance counter 0 of CPU A. Forty bits wide. On overflow it wraps to
 * zero, sets its overflow bit and sets the performance overflow bit in bank 1.
 * Access is not stated; read and write is assumed.
 */
/* perf_cntr0_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_PERF_CNTR0_A                      0x040208 /* established */
#define BEDROCK_PI_PERF_CNTR0_A_PCA_OVERFLOW_SHIFT   40 /* established */
#define BEDROCK_PI_PERF_CNTR0_A_PCA_OVERFLOW_MASK    0x1ull
#define BEDROCK_PI_PERF_CNTR0_A_PCA_OVERFLOW_INPLACE (BEDROCK_PI_PERF_CNTR0_A_PCA_OVERFLOW_MASK << BEDROCK_PI_PERF_CNTR0_A_PCA_OVERFLOW_SHIFT)
#define BEDROCK_PI_PERF_CNTR0_A_PCA_COUNT_VALUE_SHIFT 0 /* established */
#define BEDROCK_PI_PERF_CNTR0_A_PCA_COUNT_VALUE_MASK 0xffffffffffull
#define BEDROCK_PI_PERF_CNTR0_A_PCA_COUNT_VALUE_INPLACE (BEDROCK_PI_PERF_CNTR0_A_PCA_COUNT_VALUE_MASK << BEDROCK_PI_PERF_CNTR0_A_PCA_COUNT_VALUE_SHIFT)

/*
 * Performance counter 1 of CPU A. Forty bits wide. On overflow it wraps to
 * zero, sets its overflow bit and sets the performance overflow bit in bank 1.
 * Access is not stated; read and write is assumed.
 */
/* perf_cntr1_a: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_PERF_CNTR1_A                      0x040210 /* established */
#define BEDROCK_PI_PERF_CNTR1_A_PCA_OVERFLOW_SHIFT   40 /* established */
#define BEDROCK_PI_PERF_CNTR1_A_PCA_OVERFLOW_MASK    0x1ull
#define BEDROCK_PI_PERF_CNTR1_A_PCA_OVERFLOW_INPLACE (BEDROCK_PI_PERF_CNTR1_A_PCA_OVERFLOW_MASK << BEDROCK_PI_PERF_CNTR1_A_PCA_OVERFLOW_SHIFT)
#define BEDROCK_PI_PERF_CNTR1_A_PCA_COUNT_VALUE_SHIFT 0 /* established */
#define BEDROCK_PI_PERF_CNTR1_A_PCA_COUNT_VALUE_MASK 0xffffffffffull
#define BEDROCK_PI_PERF_CNTR1_A_PCA_COUNT_VALUE_INPLACE (BEDROCK_PI_PERF_CNTR1_A_PCA_COUNT_VALUE_MASK << BEDROCK_PI_PERF_CNTR1_A_PCA_COUNT_VALUE_SHIFT)

/*
 * Controls the two performance counters of CPU B. The header says each counter
 * can be set to count one of several events but does not list the events.
 * Access is not stated; read and write is assumed.
 */
/* perf_cntl_b: rw64, reset unknown; Linux 2.5.40 SN1 processor-interface
 * register header: names, offsets and field layouts */
#define BEDROCK_PI_PERF_CNTL_B                       0x050200 /* established */
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_ENABLE_SHIFT 63 /* established */
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_ENABLE_MASK 0x1ull
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_ENABLE_INPLACE (BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_ENABLE_MASK << BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_ENABLE_SHIFT)
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_MODE_SHIFT 60 /* established */
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_MODE_MASK  0x7ull
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_MODE_INPLACE (BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_MODE_MASK << BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_MODE_SHIFT)
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_SELECT_SHIFT 32 /* established */
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_SELECT_MASK 0xfffffffull
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_SELECT_INPLACE (BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_SELECT_MASK << BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_1_SELECT_SHIFT)
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_ENABLE_SHIFT 31 /* established */
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_ENABLE_MASK 0x1ull
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_ENABLE_INPLACE (BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_ENABLE_MASK << BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_ENABLE_SHIFT)
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_MODE_SHIFT 28 /* established */
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_MODE_MASK  0x7ull
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_MODE_INPLACE (BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_MODE_MASK << BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_MODE_SHIFT)
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_SELECT_SHIFT 0 /* established */
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_SELECT_MASK 0xfffffffull
#define BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_SELECT_INPLACE (BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_SELECT_MASK << BEDROCK_PI_PERF_CNTL_B_PCB_CNTR_0_SELECT_SHIFT)

/*
 * Performance counter 0 of CPU B. Forty bits wide. On overflow it wraps to
 * zero, sets its overflow bit and sets the performance overflow bit in bank 1.
 * Access is not stated; read and write is assumed.
 */
/* perf_cntr0_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_PERF_CNTR0_B                      0x050208 /* established */
#define BEDROCK_PI_PERF_CNTR0_B_PCB_OVERFLOW_SHIFT   40 /* established */
#define BEDROCK_PI_PERF_CNTR0_B_PCB_OVERFLOW_MASK    0x1ull
#define BEDROCK_PI_PERF_CNTR0_B_PCB_OVERFLOW_INPLACE (BEDROCK_PI_PERF_CNTR0_B_PCB_OVERFLOW_MASK << BEDROCK_PI_PERF_CNTR0_B_PCB_OVERFLOW_SHIFT)
#define BEDROCK_PI_PERF_CNTR0_B_PCB_COUNT_VALUE_SHIFT 0 /* established */
#define BEDROCK_PI_PERF_CNTR0_B_PCB_COUNT_VALUE_MASK 0xffffffffffull
#define BEDROCK_PI_PERF_CNTR0_B_PCB_COUNT_VALUE_INPLACE (BEDROCK_PI_PERF_CNTR0_B_PCB_COUNT_VALUE_MASK << BEDROCK_PI_PERF_CNTR0_B_PCB_COUNT_VALUE_SHIFT)

/*
 * Performance counter 1 of CPU B. Forty bits wide. On overflow it wraps to
 * zero, sets its overflow bit and sets the performance overflow bit in bank 1.
 * Access is not stated; read and write is assumed.
 */
/* perf_cntr1_b: rw64, reset 0x0; Linux 2.5.40 SN1 processor-interface register
 * header: names, offsets and field layouts */
#define BEDROCK_PI_PERF_CNTR1_B                      0x050210 /* established */
#define BEDROCK_PI_PERF_CNTR1_B_PCB_OVERFLOW_SHIFT   40 /* established */
#define BEDROCK_PI_PERF_CNTR1_B_PCB_OVERFLOW_MASK    0x1ull
#define BEDROCK_PI_PERF_CNTR1_B_PCB_OVERFLOW_INPLACE (BEDROCK_PI_PERF_CNTR1_B_PCB_OVERFLOW_MASK << BEDROCK_PI_PERF_CNTR1_B_PCB_OVERFLOW_SHIFT)
#define BEDROCK_PI_PERF_CNTR1_B_PCB_COUNT_VALUE_SHIFT 0 /* established */
#define BEDROCK_PI_PERF_CNTR1_B_PCB_COUNT_VALUE_MASK 0xffffffffffull
#define BEDROCK_PI_PERF_CNTR1_B_PCB_COUNT_VALUE_INPLACE (BEDROCK_PI_PERF_CNTR1_B_PCB_COUNT_VALUE_MASK << BEDROCK_PI_PERF_CNTR1_B_PCB_COUNT_VALUE_SHIFT)

#define BEDROCK_PI_PI1_BASE                          0x200000u /* established */

#endif /* BEDROCK_PI_GEN_H */
