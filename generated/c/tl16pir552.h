/* generated from devices/tl16pir552/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 3e2e50de5e5e0e4fa39c8450ad2520b250adcd93013d4b878cacd3fb64dce4f0 */
/* TI TL16PIR552 dual UART and IEEE 1284 parallel port, parallel-port register contract (Fuel and Origin 200 board part) */
#ifndef TL16PIR552_GEN_H
#define TL16PIR552_GEN_H

#include <stdint.h>


/* enum cnfgb_dma_select */
#define TL16PIR552_CNFGB_DMA_SELECT_DMA3             3 /* established */

/* enum cnfgb_irq_select */
#define TL16PIR552_CNFGB_IRQ_SELECT_IRQ7             1 /* established */

/* enum ecr_mode */
#define TL16PIR552_ECR_MODE_STANDARD                 0 /* established */
#define TL16PIR552_ECR_MODE_BIDIRECTIONAL            1 /* established */
#define TL16PIR552_ECR_MODE_PARALLEL_FIFO            2 /* established */
#define TL16PIR552_ECR_MODE_ECP                      3 /* established */
#define TL16PIR552_ECR_MODE_EPP                      4 /* established */
#define TL16PIR552_ECR_MODE_RESERVED                 5 /* established */
#define TL16PIR552_ECR_MODE_TEST_FIFO                6 /* established */
#define TL16PIR552_ECR_MODE_CONFIGURATION            7 /* established */

/*
 * Configuration register B, read only. Its IRQ-line sample bit depends on the board wiring, so its reset value is unknown.
 */
/* cnfgb: r8, space ecpcs, reset unknown; TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) */
#define TL16PIR552_CNFGB_OFFSET                      0x1u /* established */
#define TL16PIR552_CNFGB_COMPRESSION_SHIFT           7 /* established */
#define TL16PIR552_CNFGB_COMPRESSION_MASK            0x1u
#define TL16PIR552_CNFGB_COMPRESSION_INPLACE         (TL16PIR552_CNFGB_COMPRESSION_MASK << TL16PIR552_CNFGB_COMPRESSION_SHIFT)
#define TL16PIR552_CNFGB_IRQ_LINE_SAMPLE_SHIFT       6 /* established */
#define TL16PIR552_CNFGB_IRQ_LINE_SAMPLE_MASK        0x1u
#define TL16PIR552_CNFGB_IRQ_LINE_SAMPLE_INPLACE     (TL16PIR552_CNFGB_IRQ_LINE_SAMPLE_MASK << TL16PIR552_CNFGB_IRQ_LINE_SAMPLE_SHIFT)
#define TL16PIR552_CNFGB_IRQ_SELECT_SHIFT            3 /* established */
#define TL16PIR552_CNFGB_IRQ_SELECT_MASK             0x7u
#define TL16PIR552_CNFGB_IRQ_SELECT_INPLACE          (TL16PIR552_CNFGB_IRQ_SELECT_MASK << TL16PIR552_CNFGB_IRQ_SELECT_SHIFT)
#define TL16PIR552_CNFGB_DMA_SELECT_SHIFT            0 /* established */
#define TL16PIR552_CNFGB_DMA_SELECT_MASK             0x7u
#define TL16PIR552_CNFGB_DMA_SELECT_INPLACE          (TL16PIR552_CNFGB_DMA_SELECT_MASK << TL16PIR552_CNFGB_DMA_SELECT_SHIFT)

/*
 * Extended control register. Its top three bits select the mode, which also decides what the other chip-select offsets hold. The two low bits are read only.
 */
/* ecr: rw8, space ecpcs, reset unknown; TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) */
#define TL16PIR552_ECR_OFFSET                        0x2u /* established */
#define TL16PIR552_ECR_MODE_SHIFT                    5 /* established */
#define TL16PIR552_ECR_MODE_MASK                     0x7u
#define TL16PIR552_ECR_MODE_INPLACE                  (TL16PIR552_ECR_MODE_MASK << TL16PIR552_ECR_MODE_SHIFT)
#define TL16PIR552_ECR_ECP_FAULT_IRQ_DISABLE_SHIFT   4 /* established */
#define TL16PIR552_ECR_ECP_FAULT_IRQ_DISABLE_MASK    0x1u
#define TL16PIR552_ECR_ECP_FAULT_IRQ_DISABLE_INPLACE (TL16PIR552_ECR_ECP_FAULT_IRQ_DISABLE_MASK << TL16PIR552_ECR_ECP_FAULT_IRQ_DISABLE_SHIFT)
#define TL16PIR552_ECR_DMA_ENABLE_SHIFT              3 /* established */
#define TL16PIR552_ECR_DMA_ENABLE_MASK               0x1u
#define TL16PIR552_ECR_DMA_ENABLE_INPLACE            (TL16PIR552_ECR_DMA_ENABLE_MASK << TL16PIR552_ECR_DMA_ENABLE_SHIFT)
#define TL16PIR552_ECR_SERVICE_INTR_DISABLE_SHIFT    2 /* established */
#define TL16PIR552_ECR_SERVICE_INTR_DISABLE_MASK     0x1u
#define TL16PIR552_ECR_SERVICE_INTR_DISABLE_INPLACE  (TL16PIR552_ECR_SERVICE_INTR_DISABLE_MASK << TL16PIR552_ECR_SERVICE_INTR_DISABLE_SHIFT)
#define TL16PIR552_ECR_FIFO_FULL_SHIFT               1 /* established */
#define TL16PIR552_ECR_FIFO_FULL_MASK                0x1u
#define TL16PIR552_ECR_FIFO_FULL_INPLACE             (TL16PIR552_ECR_FIFO_FULL_MASK << TL16PIR552_ECR_FIFO_FULL_SHIFT)
#define TL16PIR552_ECR_FIFO_EMPTY_SHIFT              0 /* established */
#define TL16PIR552_ECR_FIFO_EMPTY_MASK               0x1u
#define TL16PIR552_ECR_FIFO_EMPTY_INPLACE            (TL16PIR552_ECR_FIFO_EMPTY_MASK << TL16PIR552_ECR_FIFO_EMPTY_SHIFT)

/*
 * Configuration register A, read only. It reads the constant with the implementation ID in the top nibble and the low nibble reserved and read as ones.
 */
/* cnfga: r8, space ecpcs_cfg, reset 0x1f; TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) */
#define TL16PIR552_CNFGA_OFFSET                      0x0u /* established */
#define TL16PIR552_CNFGA_IMPL_ID_SHIFT               4 /* established */
#define TL16PIR552_CNFGA_IMPL_ID_MASK                0xfu
#define TL16PIR552_CNFGA_IMPL_ID_INPLACE             (TL16PIR552_CNFGA_IMPL_ID_MASK << TL16PIR552_CNFGA_IMPL_ID_SHIFT)
#define TL16PIR552_CNFGA_RESERVED_LOW_SHIFT          0 /* established */
#define TL16PIR552_CNFGA_RESERVED_LOW_MASK           0xfu
#define TL16PIR552_CNFGA_RESERVED_LOW_INPLACE        (TL16PIR552_CNFGA_RESERVED_LOW_MASK << TL16PIR552_CNFGA_RESERVED_LOW_SHIFT)

/*
 * Forward data FIFO that uses the standard parallel-port handshake.
 */
/* pp_fifo: rw8, space ecpcs_cfifo, reset unknown; TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) */
#define TL16PIR552_PP_FIFO_OFFSET                    0x0u /* established */

/*
 * ECP data FIFO. A forward write enqueues data. A reverse read receives peripheral data through the ECP handshake.
 */
/* ecp_dfifo: rw8, space ecpcs_ecp, reset unknown; TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) */
#define TL16PIR552_ECP_DFIFO_OFFSET                  0x0u /* established */

/*
 * Test FIFO with no parallel-port protocol handshake. FIFO state stays reflected by the FULL and EMPTY bits. Overflow and underrun do not stall. Read and write counters wrap in test mode.
 */
/* test_fifo: rw8, space ecpcs_tfifo, reset unknown; TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) */
#define TL16PIR552_TEST_FIFO_OFFSET                  0x0u /* established */

/*
 * Parallel data port in standard and bidirectional modes. A write drives the data lines and a read returns their value. In the other modes offset 0 of this chip select is a different register; see the ECP-mode and FIFO spaces.
 */
/* data: rw8, space ppcs, reset unknown; TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) */
#define TL16PIR552_DATA_OFFSET                       0x0u /* established */

/*
 * Status inputs, plus the PRINT and EPP TIMEOUT status. PRINT clears on a rising ACK and sets when this register is read. TIMEOUT clears when this register is written. Bit positions are in the fields below.
 */
/* dsr: r8, space ppcs, reset unknown; TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) */
#define TL16PIR552_DSR_OFFSET                        0x1u /* established */
#define TL16PIR552_DSR_BUSY_SHIFT                    7 /* established */
#define TL16PIR552_DSR_BUSY_MASK                     0x1u
#define TL16PIR552_DSR_BUSY_INPLACE                  (TL16PIR552_DSR_BUSY_MASK << TL16PIR552_DSR_BUSY_SHIFT)
#define TL16PIR552_DSR_ACK_SHIFT                     6 /* established */
#define TL16PIR552_DSR_ACK_MASK                      0x1u
#define TL16PIR552_DSR_ACK_INPLACE                   (TL16PIR552_DSR_ACK_MASK << TL16PIR552_DSR_ACK_SHIFT)
#define TL16PIR552_DSR_PERROR_SHIFT                  5 /* established */
#define TL16PIR552_DSR_PERROR_MASK                   0x1u
#define TL16PIR552_DSR_PERROR_INPLACE                (TL16PIR552_DSR_PERROR_MASK << TL16PIR552_DSR_PERROR_SHIFT)
#define TL16PIR552_DSR_SELECT_IN_SHIFT               4 /* established */
#define TL16PIR552_DSR_SELECT_IN_MASK                0x1u
#define TL16PIR552_DSR_SELECT_IN_INPLACE             (TL16PIR552_DSR_SELECT_IN_MASK << TL16PIR552_DSR_SELECT_IN_SHIFT)
#define TL16PIR552_DSR_FAULT_SHIFT                   3 /* established */
#define TL16PIR552_DSR_FAULT_MASK                    0x1u
#define TL16PIR552_DSR_FAULT_INPLACE                 (TL16PIR552_DSR_FAULT_MASK << TL16PIR552_DSR_FAULT_SHIFT)
#define TL16PIR552_DSR_PRINT_INTR_SHIFT              2 /* established */
#define TL16PIR552_DSR_PRINT_INTR_MASK               0x1u
#define TL16PIR552_DSR_PRINT_INTR_INPLACE            (TL16PIR552_DSR_PRINT_INTR_MASK << TL16PIR552_DSR_PRINT_INTR_SHIFT)
#define TL16PIR552_DSR_TIMEOUT_SHIFT                 0 /* established */
#define TL16PIR552_DSR_TIMEOUT_MASK                  0x1u
#define TL16PIR552_DSR_TIMEOUT_INPLACE               (TL16PIR552_DSR_TIMEOUT_MASK << TL16PIR552_DSR_TIMEOUT_SHIFT)

/*
 * Parallel control register.
 */
/* dcr: rw8, space ppcs, reset unknown; TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) */
#define TL16PIR552_DCR_OFFSET                        0x2u /* established */
#define TL16PIR552_DCR_DIRECTION_SHIFT               5 /* established */
#define TL16PIR552_DCR_DIRECTION_MASK                0x1u
#define TL16PIR552_DCR_DIRECTION_INPLACE             (TL16PIR552_DCR_DIRECTION_MASK << TL16PIR552_DCR_DIRECTION_SHIFT)
#define TL16PIR552_DCR_IRQ_ON_ACK_SHIFT              4 /* established */
#define TL16PIR552_DCR_IRQ_ON_ACK_MASK               0x1u
#define TL16PIR552_DCR_IRQ_ON_ACK_INPLACE            (TL16PIR552_DCR_IRQ_ON_ACK_MASK << TL16PIR552_DCR_IRQ_ON_ACK_SHIFT)
#define TL16PIR552_DCR_SELECT_CTL_SHIFT              3 /* established */
#define TL16PIR552_DCR_SELECT_CTL_MASK               0x1u
#define TL16PIR552_DCR_SELECT_CTL_INPLACE            (TL16PIR552_DCR_SELECT_CTL_MASK << TL16PIR552_DCR_SELECT_CTL_SHIFT)
#define TL16PIR552_DCR_INIT_CTL_SHIFT                2 /* established */
#define TL16PIR552_DCR_INIT_CTL_MASK                 0x1u
#define TL16PIR552_DCR_INIT_CTL_INPLACE              (TL16PIR552_DCR_INIT_CTL_MASK << TL16PIR552_DCR_INIT_CTL_SHIFT)
#define TL16PIR552_DCR_AUTOFD_CTL_SHIFT              1 /* established */
#define TL16PIR552_DCR_AUTOFD_CTL_MASK               0x1u
#define TL16PIR552_DCR_AUTOFD_CTL_INPLACE            (TL16PIR552_DCR_AUTOFD_CTL_MASK << TL16PIR552_DCR_AUTOFD_CTL_SHIFT)
#define TL16PIR552_DCR_STROBE_CTL_SHIFT              0 /* established */
#define TL16PIR552_DCR_STROBE_CTL_MASK               0x1u
#define TL16PIR552_DCR_STROBE_CTL_INPLACE            (TL16PIR552_DCR_STROBE_CTL_MASK << TL16PIR552_DCR_STROBE_CTL_SHIFT)

/*
 * EPP address. An access generates the EPP address strobe automatically.
 */
/* epp_addr: rw8, space ppcs, reset unknown; TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) */
#define TL16PIR552_EPP_ADDR_OFFSET                   0x3u /* established */

/*
 * EPP data. Each of the four offsets with the high address bit set is this register. An access generates the EPP data strobe automatically.
 */
/* epp_data: rw8, space ppcs, reset unknown; TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) */
#define TL16PIR552_EPP_DATA_OFFSET                   0x4u /* established */
#define TL16PIR552_EPP_DATA_COUNT                    4
#define TL16PIR552_EPP_DATA_STRIDE                   1

/*
 * ECP address FIFO. A written byte enters the FIFO tagged as an ECP address.
 */
/* ecp_afifo: w8, space ppcs_ecp, reset unknown; TI TL16PIR552 datasheet, SLLS222A (December 1995, revised August 1996) */
#define TL16PIR552_ECP_AFIFO_OFFSET                  0x0u /* established */

#endif /* TL16PIR552_GEN_H */
