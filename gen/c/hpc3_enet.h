/* generated from defs/hpc3_enet.toml by defs-gen - do not edit, change the source */
/* SGI HPC3 Ethernet DMA channels (Indy) */
#ifndef HPC3_ENET_GEN_H
#define HPC3_ENET_GEN_H

#include <stdint.h>


/*
 * Receive current buffer pointer. HPC3 loads it when it fetches a descriptor, so it names the buffer being filled.
 */
/* rx_cbp: r32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, p. 33 (address map) and p. 39 (field definitions) */
#define HPC3_ENET_RX_CBP_OFFSET                      0x14000u /* established */

/*
 * Receive next descriptor pointer. Software writes the physical address of the first descriptor here before it sets the channel active.
 */
/* rx_nbdp: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, pp. 33 and 39 */
#define HPC3_ENET_RX_NBDP_OFFSET                     0x14004u /* established */

/*
 * Receive byte count and flags of the current descriptor. The count is read only to the programmed interface; the flags are read and written.
 */
/* rx_bc: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, pp. 33 and 39-40 */
#define HPC3_ENET_RX_BC_OFFSET                       0x15000u /* established */
#define HPC3_ENET_RX_BC_EOX_SHIFT                    31 /* established */
#define HPC3_ENET_RX_BC_EOX_MASK                     0x1u
#define HPC3_ENET_RX_BC_EOX_INPLACE                  (HPC3_ENET_RX_BC_EOX_MASK << HPC3_ENET_RX_BC_EOX_SHIFT)
#define HPC3_ENET_RX_BC_XIE_SHIFT                    29 /* established */
#define HPC3_ENET_RX_BC_XIE_MASK                     0x1u
#define HPC3_ENET_RX_BC_XIE_INPLACE                  (HPC3_ENET_RX_BC_XIE_MASK << HPC3_ENET_RX_BC_XIE_SHIFT)
#define HPC3_ENET_RX_BC_COUNT_SHIFT                  0 /* established */
#define HPC3_ENET_RX_BC_COUNT_MASK                   0x3fffu
#define HPC3_ENET_RX_BC_COUNT_INPLACE                (HPC3_ENET_RX_BC_COUNT_MASK << HPC3_ENET_RX_BC_COUNT_SHIFT)

/*
 * Receive control and status. The status bits are read only copies of the SEEQ receive status.
 */
/* rx_cntl: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, pp. 39-40 */
#define HPC3_ENET_RX_CNTL_OFFSET                     0x15004u /* established */
#define HPC3_ENET_RX_CNTL_RBO_SHIFT                  11 /* established */
#define HPC3_ENET_RX_CNTL_RBO_MASK                   0x1u
#define HPC3_ENET_RX_CNTL_RBO_INPLACE                (HPC3_ENET_RX_CNTL_RBO_MASK << HPC3_ENET_RX_CNTL_RBO_SHIFT)
#define HPC3_ENET_RX_CNTL_CH_ACTIVE_MASK_SHIFT       10 /* established */
#define HPC3_ENET_RX_CNTL_CH_ACTIVE_MASK_MASK        0x1u
#define HPC3_ENET_RX_CNTL_CH_ACTIVE_MASK_INPLACE     (HPC3_ENET_RX_CNTL_CH_ACTIVE_MASK_MASK << HPC3_ENET_RX_CNTL_CH_ACTIVE_MASK_SHIFT)
#define HPC3_ENET_RX_CNTL_CH_ACTIVE_SHIFT            9 /* established */
#define HPC3_ENET_RX_CNTL_CH_ACTIVE_MASK             0x1u
#define HPC3_ENET_RX_CNTL_CH_ACTIVE_INPLACE          (HPC3_ENET_RX_CNTL_CH_ACTIVE_MASK << HPC3_ENET_RX_CNTL_CH_ACTIVE_SHIFT)
#define HPC3_ENET_RX_CNTL_ENDIAN_SHIFT               8 /* established */
#define HPC3_ENET_RX_CNTL_ENDIAN_MASK                0x1u
#define HPC3_ENET_RX_CNTL_ENDIAN_INPLACE             (HPC3_ENET_RX_CNTL_ENDIAN_MASK << HPC3_ENET_RX_CNTL_ENDIAN_SHIFT)
#define HPC3_ENET_RX_CNTL_STATUS_7_SHIFT             7 /* established */
#define HPC3_ENET_RX_CNTL_STATUS_7_MASK              0x1u
#define HPC3_ENET_RX_CNTL_STATUS_7_INPLACE           (HPC3_ENET_RX_CNTL_STATUS_7_MASK << HPC3_ENET_RX_CNTL_STATUS_7_SHIFT)
#define HPC3_ENET_RX_CNTL_STATUS_6_SHIFT             6 /* established */
#define HPC3_ENET_RX_CNTL_STATUS_6_MASK              0x1u
#define HPC3_ENET_RX_CNTL_STATUS_6_INPLACE           (HPC3_ENET_RX_CNTL_STATUS_6_MASK << HPC3_ENET_RX_CNTL_STATUS_6_SHIFT)
#define HPC3_ENET_RX_CNTL_STATUS_SHIFT               0 /* established */
#define HPC3_ENET_RX_CNTL_STATUS_MASK                0x3fu
#define HPC3_ENET_RX_CNTL_STATUS_INPLACE             (HPC3_ENET_RX_CNTL_STATUS_MASK << HPC3_ENET_RX_CNTL_STATUS_SHIFT)

/*
 * Receive FIFO tail pointer, diagnostic. Normal software does not write it.
 */
/* rx_gio: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, pp. 33 and 39 */
#define HPC3_ENET_RX_GIO_OFFSET                      0x15008u /* established */

/*
 * Receive FIFO head pointer, diagnostic.
 */
/* rx_dev: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, pp. 33 and 39 */
#define HPC3_ENET_RX_DEV_OFFSET                      0x1500cu /* established */

/*
 * Reset and interrupt control, shared by both Ethernet channels. The specification calls it misc.
 */
/* enet_reset: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, p. 41 */
#define HPC3_ENET_ENET_RESET_OFFSET                  0x15014u /* established */
#define HPC3_ENET_ENET_RESET_LOOPBACK_SHIFT          2 /* established */
#define HPC3_ENET_ENET_RESET_LOOPBACK_MASK           0x1u
#define HPC3_ENET_ENET_RESET_LOOPBACK_INPLACE        (HPC3_ENET_ENET_RESET_LOOPBACK_MASK << HPC3_ENET_ENET_RESET_LOOPBACK_SHIFT)
#define HPC3_ENET_ENET_RESET_CLRINT_SHIFT            1 /* established */
#define HPC3_ENET_ENET_RESET_CLRINT_MASK             0x1u
#define HPC3_ENET_ENET_RESET_CLRINT_INPLACE          (HPC3_ENET_ENET_RESET_CLRINT_MASK << HPC3_ENET_ENET_RESET_CLRINT_SHIFT)
#define HPC3_ENET_ENET_RESET_CH_RESET_SHIFT          0 /* established */
#define HPC3_ENET_ENET_RESET_CH_RESET_MASK           0x1u
#define HPC3_ENET_ENET_RESET_CH_RESET_INPLACE        (HPC3_ENET_ENET_RESET_CH_RESET_MASK << HPC3_ENET_ENET_RESET_CH_RESET_SHIFT)

/*
 * DMA timing and the SEEQ work-around enables. The timing fields reset to 1111 according to the specification; the other fields have no stated reset.
 */
/* dmacfg: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, pp. 41-42 */
#define HPC3_ENET_DMACFG_OFFSET                      0x15018u /* established */
#define HPC3_ENET_DMACFG_FIX_TIMEOUT_SHIFT           16 /* established */
#define HPC3_ENET_DMACFG_FIX_TIMEOUT_MASK            0x3u
#define HPC3_ENET_DMACFG_FIX_TIMEOUT_INPLACE         (HPC3_ENET_DMACFG_FIX_TIMEOUT_MASK << HPC3_ENET_DMACFG_FIX_TIMEOUT_SHIFT)
#define HPC3_ENET_DMACFG_FIX_INTR_SHIFT              15 /* established */
#define HPC3_ENET_DMACFG_FIX_INTR_MASK               0x1u
#define HPC3_ENET_DMACFG_FIX_INTR_INPLACE            (HPC3_ENET_DMACFG_FIX_INTR_MASK << HPC3_ENET_DMACFG_FIX_INTR_SHIFT)
#define HPC3_ENET_DMACFG_FIX_EOP_SHIFT               14 /* established */
#define HPC3_ENET_DMACFG_FIX_EOP_MASK                0x1u
#define HPC3_ENET_DMACFG_FIX_EOP_INPLACE             (HPC3_ENET_DMACFG_FIX_EOP_MASK << HPC3_ENET_DMACFG_FIX_EOP_SHIFT)
#define HPC3_ENET_DMACFG_FIX_RXDC_SHIFT              13 /* established */
#define HPC3_ENET_DMACFG_FIX_RXDC_MASK               0x1u
#define HPC3_ENET_DMACFG_FIX_RXDC_INPLACE            (HPC3_ENET_DMACFG_FIX_RXDC_MASK << HPC3_ENET_DMACFG_FIX_RXDC_SHIFT)
#define HPC3_ENET_DMACFG_WR_CTRL_SHIFT               12 /* established */
#define HPC3_ENET_DMACFG_WR_CTRL_MASK                0x1u
#define HPC3_ENET_DMACFG_WR_CTRL_INPLACE             (HPC3_ENET_DMACFG_WR_CTRL_MASK << HPC3_ENET_DMACFG_WR_CTRL_SHIFT)
#define HPC3_ENET_DMACFG_D3_SHIFT                    8 /* established */
#define HPC3_ENET_DMACFG_D3_MASK                     0xfu
#define HPC3_ENET_DMACFG_D3_INPLACE                  (HPC3_ENET_DMACFG_D3_MASK << HPC3_ENET_DMACFG_D3_SHIFT)
#define HPC3_ENET_DMACFG_D2_SHIFT                    4 /* established */
#define HPC3_ENET_DMACFG_D2_MASK                     0xfu
#define HPC3_ENET_DMACFG_D2_INPLACE                  (HPC3_ENET_DMACFG_D2_MASK << HPC3_ENET_DMACFG_D2_SHIFT)
#define HPC3_ENET_DMACFG_D1_SHIFT                    0 /* established */
#define HPC3_ENET_DMACFG_D1_MASK                     0xfu
#define HPC3_ENET_DMACFG_D1_INPLACE                  (HPC3_ENET_DMACFG_D1_MASK << HPC3_ENET_DMACFG_D1_SHIFT)

/*
 * PIO timing to the SEEQ. The timing fields reset to 1111 according to the specification; the other bits have no stated reset.
 */
/* piocfg: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, pp. 41-42 */
#define HPC3_ENET_PIOCFG_OFFSET                      0x1501cu /* established */
#define HPC3_ENET_PIOCFG_FIFO_RAM_TEST_SHIFT         12 /* established */
#define HPC3_ENET_PIOCFG_FIFO_RAM_TEST_MASK          0x1u
#define HPC3_ENET_PIOCFG_FIFO_RAM_TEST_INPLACE       (HPC3_ENET_PIOCFG_FIFO_RAM_TEST_MASK << HPC3_ENET_PIOCFG_FIFO_RAM_TEST_SHIFT)
#define HPC3_ENET_PIOCFG_P3_SHIFT                    8 /* established */
#define HPC3_ENET_PIOCFG_P3_MASK                     0xfu
#define HPC3_ENET_PIOCFG_P3_INPLACE                  (HPC3_ENET_PIOCFG_P3_MASK << HPC3_ENET_PIOCFG_P3_SHIFT)
#define HPC3_ENET_PIOCFG_P2_SHIFT                    4 /* established */
#define HPC3_ENET_PIOCFG_P2_MASK                     0xfu
#define HPC3_ENET_PIOCFG_P2_INPLACE                  (HPC3_ENET_PIOCFG_P2_MASK << HPC3_ENET_PIOCFG_P2_SHIFT)
#define HPC3_ENET_PIOCFG_P1_SHIFT                    0 /* established */
#define HPC3_ENET_PIOCFG_P1_MASK                     0xfu
#define HPC3_ENET_PIOCFG_P1_INPLACE                  (HPC3_ENET_PIOCFG_P1_MASK << HPC3_ENET_PIOCFG_P1_SHIFT)

/*
 * Transmit current buffer pointer. The specification gives the access as read in one place and read and write in another.
 */
/* tx_cbp: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, p. 34 (address map, read) and p. 43 (field text, read and write) */
#define HPC3_ENET_TX_CBP_OFFSET                      0x16000u /* established */

/*
 * Transmit next descriptor pointer. Software writes the physical address of the first descriptor here before it sets the channel active.
 */
/* tx_nbdp: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, pp. 33 and 43 */
#define HPC3_ENET_TX_NBDP_OFFSET                     0x16004u /* established */

/*
 * Transmit byte count and flags of the current descriptor. The count and the end-of-chain sample bit are read only.
 */
/* tx_bc: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, pp. 33, 43 */
#define HPC3_ENET_TX_BC_OFFSET                       0x17000u /* established */
#define HPC3_ENET_TX_BC_EOX_SHIFT                    31 /* established */
#define HPC3_ENET_TX_BC_EOX_MASK                     0x1u
#define HPC3_ENET_TX_BC_EOX_INPLACE                  (HPC3_ENET_TX_BC_EOX_MASK << HPC3_ENET_TX_BC_EOX_SHIFT)
#define HPC3_ENET_TX_BC_EOXP_SHIFT                   30 /* established */
#define HPC3_ENET_TX_BC_EOXP_MASK                    0x1u
#define HPC3_ENET_TX_BC_EOXP_INPLACE                 (HPC3_ENET_TX_BC_EOXP_MASK << HPC3_ENET_TX_BC_EOXP_SHIFT)
#define HPC3_ENET_TX_BC_XIE_SHIFT                    29 /* established */
#define HPC3_ENET_TX_BC_XIE_MASK                     0x1u
#define HPC3_ENET_TX_BC_XIE_INPLACE                  (HPC3_ENET_TX_BC_XIE_MASK << HPC3_ENET_TX_BC_XIE_SHIFT)
#define HPC3_ENET_TX_BC_EOX_SAMPLED_SHIFT            28 /* established */
#define HPC3_ENET_TX_BC_EOX_SAMPLED_MASK             0x1u
#define HPC3_ENET_TX_BC_EOX_SAMPLED_INPLACE          (HPC3_ENET_TX_BC_EOX_SAMPLED_MASK << HPC3_ENET_TX_BC_EOX_SAMPLED_SHIFT)
#define HPC3_ENET_TX_BC_COUNT_SHIFT                  0 /* established */
#define HPC3_ENET_TX_BC_COUNT_MASK                   0x3fffu
#define HPC3_ENET_TX_BC_COUNT_INPLACE                (HPC3_ENET_TX_BC_COUNT_MASK << HPC3_ENET_TX_BC_COUNT_SHIFT)

/*
 * Transmit control and status. The status bits are read only copies of the SEEQ transmit status.
 */
/* tx_cntl: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, p. 44 */
#define HPC3_ENET_TX_CNTL_OFFSET                     0x17004u /* established */
#define HPC3_ENET_TX_CNTL_CH_ACTIVE_MASK_SHIFT       10 /* established */
#define HPC3_ENET_TX_CNTL_CH_ACTIVE_MASK_MASK        0x1u
#define HPC3_ENET_TX_CNTL_CH_ACTIVE_MASK_INPLACE     (HPC3_ENET_TX_CNTL_CH_ACTIVE_MASK_MASK << HPC3_ENET_TX_CNTL_CH_ACTIVE_MASK_SHIFT)
#define HPC3_ENET_TX_CNTL_CH_ACTIVE_SHIFT            9 /* established */
#define HPC3_ENET_TX_CNTL_CH_ACTIVE_MASK             0x1u
#define HPC3_ENET_TX_CNTL_CH_ACTIVE_INPLACE          (HPC3_ENET_TX_CNTL_CH_ACTIVE_MASK << HPC3_ENET_TX_CNTL_CH_ACTIVE_SHIFT)
#define HPC3_ENET_TX_CNTL_ENDIAN_SHIFT               8 /* established */
#define HPC3_ENET_TX_CNTL_ENDIAN_MASK                0x1u
#define HPC3_ENET_TX_CNTL_ENDIAN_INPLACE             (HPC3_ENET_TX_CNTL_ENDIAN_MASK << HPC3_ENET_TX_CNTL_ENDIAN_SHIFT)
#define HPC3_ENET_TX_CNTL_STATUS_7_5_SHIFT           5 /* established */
#define HPC3_ENET_TX_CNTL_STATUS_7_5_MASK            0x7u
#define HPC3_ENET_TX_CNTL_STATUS_7_5_INPLACE         (HPC3_ENET_TX_CNTL_STATUS_7_5_MASK << HPC3_ENET_TX_CNTL_STATUS_7_5_SHIFT)
#define HPC3_ENET_TX_CNTL_STATUS_4_SHIFT             4 /* established */
#define HPC3_ENET_TX_CNTL_STATUS_4_MASK              0x1u
#define HPC3_ENET_TX_CNTL_STATUS_4_INPLACE           (HPC3_ENET_TX_CNTL_STATUS_4_MASK << HPC3_ENET_TX_CNTL_STATUS_4_SHIFT)
#define HPC3_ENET_TX_CNTL_STATUS_SHIFT               0 /* established */
#define HPC3_ENET_TX_CNTL_STATUS_MASK                0xfu
#define HPC3_ENET_TX_CNTL_STATUS_INPLACE             (HPC3_ENET_TX_CNTL_STATUS_MASK << HPC3_ENET_TX_CNTL_STATUS_SHIFT)

/*
 * Transmit FIFO tail pointer, diagnostic.
 */
/* tx_gio: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, pp. 33 and 43 */
#define HPC3_ENET_TX_GIO_OFFSET                      0x17008u /* established */

/*
 * Transmit FIFO head pointer, diagnostic.
 */
/* tx_dev: rw32, space hpc3, reset unknown; HPC3 Chip Specification, revision 1.4, pp. 33 and 43 */
#define HPC3_ENET_TX_DEV_OFFSET                      0x1700cu /* established */

/*
 * Receive current descriptor pointer. The specification does not list it. The IRIX driver writes it at initialisation with the descriptor it marks end-of-chain, and reads it after the receive channel stops. How the hardware updates it is not settled; see docs/hpc3-ethernet.md.
 */
/* rx_cur_desc: rw32, space hpc3, reset unknown; IRIX 6.5 base-release Ethernet driver object (initialisation and interrupt handler). Not in the HPC3 specification. */
#define HPC3_ENET_RX_CUR_DESC_OFFSET                 0x18000u /* established */

/*
 * First descriptor of the packet in progress. The specification does not list it. The IRIX driver reads it. Its update rule is unknown.
 */
/* tx_first_cur: r32, space hpc3, reset unknown; IRIX 6.5 base-release Ethernet driver object (transmit path and interrupt handler). Not in the HPC3 specification. */
#define HPC3_ENET_TX_FIRST_CUR_OFFSET                0x1a000u /* established */

/*
 * First descriptor of the previous packet. The specification does not list it. The IRIX driver reads it while the transmit channel is active, to reclaim transmit descriptors. Its update rule is unknown.
 */
/* tx_first_prev: r32, space hpc3, reset unknown; IRIX 6.5 base-release Ethernet driver object (transmit path and interrupt handler). Not in the HPC3 specification. */
#define HPC3_ENET_TX_FIRST_PREV_OFFSET               0x1a004u /* established */

/*
 * Word 1 of a receive descriptor, the count and flags that HPC3 writes back when a frame has been stored.
 */
/* word RX_DESC_CTL: 32 bits; HPC3 Chip Specification, revision 1.4, pp. 6-7 and 14 */
#define HPC3_ENET_RX_DESC_CTL_WIDTH                  32 /* established */
#define HPC3_ENET_RX_DESC_CTL_EOX_SHIFT              31 /* established */
#define HPC3_ENET_RX_DESC_CTL_EOX_MASK               0x1u
#define HPC3_ENET_RX_DESC_CTL_EOX_INPLACE            (HPC3_ENET_RX_DESC_CTL_EOX_MASK << HPC3_ENET_RX_DESC_CTL_EOX_SHIFT)
#define HPC3_ENET_RX_DESC_CTL_EOXP_SHIFT             30 /* established */
#define HPC3_ENET_RX_DESC_CTL_EOXP_MASK              0x1u
#define HPC3_ENET_RX_DESC_CTL_EOXP_INPLACE           (HPC3_ENET_RX_DESC_CTL_EOXP_MASK << HPC3_ENET_RX_DESC_CTL_EOXP_SHIFT)
#define HPC3_ENET_RX_DESC_CTL_XIE_SHIFT              29 /* established */
#define HPC3_ENET_RX_DESC_CTL_XIE_MASK               0x1u
#define HPC3_ENET_RX_DESC_CTL_XIE_INPLACE            (HPC3_ENET_RX_DESC_CTL_XIE_MASK << HPC3_ENET_RX_DESC_CTL_XIE_SHIFT)
#define HPC3_ENET_RX_DESC_CTL_OWN_SHIFT              14 /* inferred */
#define HPC3_ENET_RX_DESC_CTL_OWN_MASK               0x1u
#define HPC3_ENET_RX_DESC_CTL_OWN_INPLACE            (HPC3_ENET_RX_DESC_CTL_OWN_MASK << HPC3_ENET_RX_DESC_CTL_OWN_SHIFT)
#define HPC3_ENET_RX_DESC_CTL_COUNT_SHIFT            0 /* established */
#define HPC3_ENET_RX_DESC_CTL_COUNT_MASK             0x3fffu
#define HPC3_ENET_RX_DESC_CTL_COUNT_INPLACE          (HPC3_ENET_RX_DESC_CTL_COUNT_MASK << HPC3_ENET_RX_DESC_CTL_COUNT_SHIFT)

/*
 * Word 1 of a transmit descriptor: the count, flags and inter-packet gap byte.
 */
/* word TX_DESC_CTL: 32 bits; HPC3 Chip Specification, revision 1.4, pp. 6-7, 13-14 */
#define HPC3_ENET_TX_DESC_CTL_WIDTH                  32 /* established */
#define HPC3_ENET_TX_DESC_CTL_EOX_SHIFT              31 /* established */
#define HPC3_ENET_TX_DESC_CTL_EOX_MASK               0x1u
#define HPC3_ENET_TX_DESC_CTL_EOX_INPLACE            (HPC3_ENET_TX_DESC_CTL_EOX_MASK << HPC3_ENET_TX_DESC_CTL_EOX_SHIFT)
#define HPC3_ENET_TX_DESC_CTL_EOXP_SHIFT             30 /* established */
#define HPC3_ENET_TX_DESC_CTL_EOXP_MASK              0x1u
#define HPC3_ENET_TX_DESC_CTL_EOXP_INPLACE           (HPC3_ENET_TX_DESC_CTL_EOXP_MASK << HPC3_ENET_TX_DESC_CTL_EOXP_SHIFT)
#define HPC3_ENET_TX_DESC_CTL_XIE_SHIFT              29 /* established */
#define HPC3_ENET_TX_DESC_CTL_XIE_MASK               0x1u
#define HPC3_ENET_TX_DESC_CTL_XIE_INPLACE            (HPC3_ENET_TX_DESC_CTL_XIE_MASK << HPC3_ENET_TX_DESC_CTL_XIE_SHIFT)
#define HPC3_ENET_TX_DESC_CTL_IPG_SHIFT              16 /* established */
#define HPC3_ENET_TX_DESC_CTL_IPG_MASK               0xffu
#define HPC3_ENET_TX_DESC_CTL_IPG_INPLACE            (HPC3_ENET_TX_DESC_CTL_IPG_MASK << HPC3_ENET_TX_DESC_CTL_IPG_SHIFT)
#define HPC3_ENET_TX_DESC_CTL_TXD_SHIFT              15 /* established */
#define HPC3_ENET_TX_DESC_CTL_TXD_MASK               0x1u
#define HPC3_ENET_TX_DESC_CTL_TXD_INPLACE            (HPC3_ENET_TX_DESC_CTL_TXD_MASK << HPC3_ENET_TX_DESC_CTL_TXD_SHIFT)
#define HPC3_ENET_TX_DESC_CTL_COUNT_SHIFT            0 /* established */
#define HPC3_ENET_TX_DESC_CTL_COUNT_MASK             0x3fffu
#define HPC3_ENET_TX_DESC_CTL_COUNT_INPLACE          (HPC3_ENET_TX_DESC_CTL_COUNT_MASK << HPC3_ENET_TX_DESC_CTL_COUNT_SHIFT)

#endif /* HPC3_ENET_GEN_H */
