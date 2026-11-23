/* generated from devices/hpc1/registers.toml by defs-gen - do not edit, change
 * the source */
/* defs-gen 4 */
/* input sha256 8b6a27263e374099e75f424a29fb6a1a0374b927ab92b0309c2fc2e94aa98cda */
/* SGI HPC1 peripheral controller (Indigo, R3000 and R4000 boards) */
#ifndef HPC1_GEN_H
#define HPC1_GEN_H

#include <stdint.h>


/* enum scsi_direction */
#define HPC1_SCSI_DIRECTION_TO_DEVICE                0 /* established */
#define HPC1_SCSI_DIRECTION_TO_MEMORY                1 /* established */

/*
 * The word at the window base. Software probes it with a guarded read to find
 * out whether a controller is present at the slot; what the word holds is not
 * stated.
 */
/* enet_probe: r32, space hpc1, reset unknown; IRIX developer header */
#define HPC1_ENET_PROBE_OFFSET                       0x0u /* inferred */

/*
 * Transmit count register. The driver's register dump prints it and nothing
 * writes it; its meaning is not settled.
 */
/* enet_xcount: rw32, space hpc1, reset unknown; IRIX Ethernet driver */
#define HPC1_ENET_XCOUNT_OFFSET                      0x8u /* unknown */

/*
 * Current transmit buffer pointer, by the dump label. Read by the register dump
 * only; no driver writes it.
 */
/* enet_cxbp: rw32, space hpc1, reset unknown; IRIX Ethernet driver */
#define HPC1_ENET_CXBP_OFFSET                        0xcu /* unknown */

/*
 * Next transmit buffer descriptor pointer: the physical address of the
 * descriptor the transmit channel fetches next. Software writes the head of the
 * queue here, with bits 31:29 clear, before it starts the channel.
 */
/* enet_nxbdp: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD
 * register header */
#define HPC1_ENET_NXBDP_OFFSET                       0x10u /* established */

/*
 * Transmit byte count of the descriptor in progress. Named by the dump and by
 * the public driver; no driver reads it in a decision.
 */
/* enet_xbc: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD
 * register header */
#define HPC1_ENET_XBC_OFFSET                         0x14u /* inferred */

/*
 * Transmit FIFO pointer, by the dump label. Only dumped.
 */
/* enet_xpntr: rw32, space hpc1, reset unknown; IRIX Ethernet driver */
#define HPC1_ENET_XPNTR_OFFSET                       0x18u /* unknown */

/*
 * Transmit FIFO data port, by the dump label. Only dumped.
 */
/* enet_xfifo: rw32, space hpc1, reset unknown; IRIX Ethernet driver */
#define HPC1_ENET_XFIFO_OFFSET                       0x1cu /* unknown */

/*
 * Current transmit buffer descriptor pointer. Both drivers load it with the
 * same address they put in the next-descriptor pointer when they start or
 * restart the channel.
 */
/* enet_cxbdp: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD
 * register header */
#define HPC1_ENET_CXBDP_OFFSET                       0x20u /* established */

/*
 * Current first transmit buffer descriptor pointer: the first descriptor of the
 * frame being sent. Written with the queue head at a restart.
 */
/* enet_cpfxbdp: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD
 * register header */
#define HPC1_ENET_CPFXBDP_OFFSET                     0x24u /* established */

/*
 * Previous first transmit buffer descriptor pointer. Named by the dump and the
 * public header; neither driver writes it.
 */
/* enet_ppfxbdp: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD
 * register header */
#define HPC1_ENET_PPFXBDP_OFFSET                     0x28u /* inferred */

/*
 * Receive interrupt delay count. Bit 24 set (0x01000000) disables the delay;
 * the IRIX driver writes that value at initialisation and writes its tunable
 * delay when it re-enables the delay after a received frame.
 */
/* enet_intdelay: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD
 * register header */
#define HPC1_ENET_INTDELAY_OFFSET                    0x2cu /* established */

/*
 * Transmit status and channel start. Bit 22 starts the transmit channel when
 * written one and reads one while the channel is running. The bits above it
 * carry the SEEQ transmit status byte; the drivers only test bit 22.
 */
/* enet_trstat: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD
 * register header */
#define HPC1_ENET_TRSTAT_OFFSET                      0x34u /* established */
#define HPC1_ENET_TRSTAT_SEEQ_TX_STATUS_HIGH_SHIFT   23 /* inferred */
#define HPC1_ENET_TRSTAT_SEEQ_TX_STATUS_HIGH_MASK    0x1u
#define HPC1_ENET_TRSTAT_SEEQ_TX_STATUS_HIGH_INPLACE (HPC1_ENET_TRSTAT_SEEQ_TX_STATUS_HIGH_MASK << HPC1_ENET_TRSTAT_SEEQ_TX_STATUS_HIGH_SHIFT)
#define HPC1_ENET_TRSTAT_TX_ACTIVE_SHIFT             22 /* established */
#define HPC1_ENET_TRSTAT_TX_ACTIVE_MASK              0x1u
#define HPC1_ENET_TRSTAT_TX_ACTIVE_INPLACE (HPC1_ENET_TRSTAT_TX_ACTIVE_MASK << HPC1_ENET_TRSTAT_TX_ACTIVE_SHIFT)
#define HPC1_ENET_TRSTAT_SEEQ_TX_STATUS_LOW_SHIFT    16 /* inferred */
#define HPC1_ENET_TRSTAT_SEEQ_TX_STATUS_LOW_MASK     0x3fu
#define HPC1_ENET_TRSTAT_SEEQ_TX_STATUS_LOW_INPLACE (HPC1_ENET_TRSTAT_SEEQ_TX_STATUS_LOW_MASK << HPC1_ENET_TRSTAT_SEEQ_TX_STATUS_LOW_SHIFT)

/*
 * Receive status and channel start. Bit 14 starts the receive channel when
 * written one and reads one while it runs; the other bits of the upper byte
 * carry the Ethernet chip's receive status.
 */
/* enet_rcvstat: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD
 * register header */
#define HPC1_ENET_RCVSTAT_OFFSET                     0x38u /* established */
#define HPC1_ENET_RCVSTAT_SEEQ_RX_STATUS_HIGH_SHIFT  15 /* inferred */
#define HPC1_ENET_RCVSTAT_SEEQ_RX_STATUS_HIGH_MASK   0x1u
#define HPC1_ENET_RCVSTAT_SEEQ_RX_STATUS_HIGH_INPLACE (HPC1_ENET_RCVSTAT_SEEQ_RX_STATUS_HIGH_MASK << HPC1_ENET_RCVSTAT_SEEQ_RX_STATUS_HIGH_SHIFT)
#define HPC1_ENET_RCVSTAT_RX_ACTIVE_SHIFT            14 /* established */
#define HPC1_ENET_RCVSTAT_RX_ACTIVE_MASK             0x1u
#define HPC1_ENET_RCVSTAT_RX_ACTIVE_INPLACE (HPC1_ENET_RCVSTAT_RX_ACTIVE_MASK << HPC1_ENET_RCVSTAT_RX_ACTIVE_SHIFT)
#define HPC1_ENET_RCVSTAT_SEEQ_RX_STATUS_LOW_SHIFT   8 /* inferred */
#define HPC1_ENET_RCVSTAT_SEEQ_RX_STATUS_LOW_MASK    0x3fu
#define HPC1_ENET_RCVSTAT_SEEQ_RX_STATUS_LOW_INPLACE (HPC1_ENET_RCVSTAT_SEEQ_RX_STATUS_LOW_MASK << HPC1_ENET_RCVSTAT_SEEQ_RX_STATUS_LOW_SHIFT)

/*
 * Ethernet channel control: reset, interrupt clear and loopback. Reading bit 1
 * reports a pending interrupt.
 */
/* enet_ctl: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD
 * register header; Indigo PROM */
#define HPC1_ENET_CTL_OFFSET                         0x3cu /* established */
#define HPC1_ENET_CTL_CLEAR_OVERFLOW_SHIFT           3 /* inferred */
#define HPC1_ENET_CTL_CLEAR_OVERFLOW_MASK            0x1u
#define HPC1_ENET_CTL_CLEAR_OVERFLOW_INPLACE (HPC1_ENET_CTL_CLEAR_OVERFLOW_MASK << HPC1_ENET_CTL_CLEAR_OVERFLOW_SHIFT)
#define HPC1_ENET_CTL_BIT2_SHIFT                     2 /* unknown */
#define HPC1_ENET_CTL_BIT2_MASK                      0x1u
#define HPC1_ENET_CTL_BIT2_INPLACE (HPC1_ENET_CTL_BIT2_MASK << HPC1_ENET_CTL_BIT2_SHIFT)
#define HPC1_ENET_CTL_CLEAR_INT_SHIFT                1 /* established */
#define HPC1_ENET_CTL_CLEAR_INT_MASK                 0x1u
#define HPC1_ENET_CTL_CLEAR_INT_INPLACE (HPC1_ENET_CTL_CLEAR_INT_MASK << HPC1_ENET_CTL_CLEAR_INT_SHIFT)
#define HPC1_ENET_CTL_RESET_SHIFT                    0 /* established */
#define HPC1_ENET_CTL_RESET_MASK                     0x1u
#define HPC1_ENET_CTL_RESET_INPLACE (HPC1_ENET_CTL_RESET_MASK << HPC1_ENET_CTL_RESET_SHIFT)

/*
 * Receive count register, by the dump label. Only dumped.
 */
/* enet_rcount: rw32, space hpc1, reset unknown; IRIX Ethernet driver */
#define HPC1_ENET_RCOUNT_OFFSET                      0x44u /* unknown */

/*
 * Receive byte count of the descriptor in progress.
 */
/* enet_rbc: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD
 * register header */
#define HPC1_ENET_RBC_OFFSET                         0x48u /* inferred */

/*
 * Current receive buffer pointer, by the dump label.
 */
/* enet_crbp: rw32, space hpc1, reset unknown; IRIX Ethernet driver */
#define HPC1_ENET_CRBP_OFFSET                        0x4cu /* inferred */

/*
 * Next receive buffer descriptor pointer: physical address of the first
 * descriptor the receive channel fetches. Software writes the head of the ring
 * here, with bits 31:29 clear, before it sets the receive start bit.
 */
/* enet_nrbdp: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD
 * register header */
#define HPC1_ENET_NRBDP_OFFSET                       0x50u /* established */

/*
 * Current receive buffer descriptor pointer. The IRIX driver loads it with the
 * ring head at start and its watchdog reads it to see whether the channel has
 * moved.
 */
/* enet_crbdp: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD
 * register header */
#define HPC1_ENET_CRBDP_OFFSET                       0x54u /* established */

/*
 * Receive FIFO pointer, by the dump label. The PROM's early test stores the
 * byte 0x5a to its low byte lane and reads the register after it, without a
 * recorded check.
 */
/* enet_rpntr: rw32, space hpc1, reset unknown; IRIX Ethernet driver; Indigo
 * PROM */
#define HPC1_ENET_RPNTR_OFFSET                       0x58u /* unknown */

/*
 * Receive FIFO data port, by the dump label.
 */
/* enet_rfifo: rw32, space hpc1, reset unknown; IRIX Ethernet driver; Indigo
 * PROM */
#define HPC1_ENET_RFIFO_OFFSET                       0x5cu /* unknown */

/*
 * SCSI channel byte count of the descriptor being moved. The channel loads it
 * from the descriptor; software does not write it in normal operation.
 */
/* scsi_bc: rw32, space hpc1, reset unknown; IRIX developer header; IRIX kernel;
 * Indigo PROM */
#define HPC1_SCSI_BC_OFFSET                          0x88u /* established */

/*
 * SCSI channel current buffer pointer: the physical address of the data being
 * moved, loaded from a descriptor.
 */
/* scsi_cbp: rw32, space hpc1, reset unknown; IRIX developer header; IRIX
 * kernel; Indigo PROM */
#define HPC1_SCSI_CBP_OFFSET                         0x8cu /* established */

/*
 * SCSI next descriptor pointer. Software writes the physical address of the
 * first descriptor, then the control register with the start bit; the channel
 * then walks the chain by itself.
 */
/* scsi_nbdp: rw32, space hpc1, reset unknown; IRIX developer header; IRIX
 * kernel */
#define HPC1_SCSI_NBDP_OFFSET                        0x90u /* established */

/*
 * SCSI channel control. The reset bit holds the WD33C93 chip in reset while
 * set. The flush bit drains the channel FIFO and the start bit reads one while
 * the channel is active, so software sets flush and waits for the start bit to
 * read zero.
 */
/* scsi_ctrl: rw32, space hpc1, reset unknown; IRIX developer header; IRIX
 * kernel; Indigo PROM */
#define HPC1_SCSI_CTRL_OFFSET                        0x94u /* established */
#define HPC1_SCSI_CTRL_START_SHIFT                   7 /* established */
#define HPC1_SCSI_CTRL_START_MASK                    0x1u
#define HPC1_SCSI_CTRL_START_INPLACE (HPC1_SCSI_CTRL_START_MASK << HPC1_SCSI_CTRL_START_SHIFT)
#define HPC1_SCSI_CTRL_DIRECTION_SHIFT               4 /* established */
#define HPC1_SCSI_CTRL_DIRECTION_MASK                0x1u
#define HPC1_SCSI_CTRL_DIRECTION_INPLACE (HPC1_SCSI_CTRL_DIRECTION_MASK << HPC1_SCSI_CTRL_DIRECTION_SHIFT)
#define HPC1_SCSI_CTRL_FLUSH_SHIFT                   1 /* established */
#define HPC1_SCSI_CTRL_FLUSH_MASK                    0x1u
#define HPC1_SCSI_CTRL_FLUSH_INPLACE (HPC1_SCSI_CTRL_FLUSH_MASK << HPC1_SCSI_CTRL_FLUSH_SHIFT)
#define HPC1_SCSI_CTRL_RESET_SHIFT                   0 /* established */
#define HPC1_SCSI_CTRL_RESET_MASK                    0x1u
#define HPC1_SCSI_CTRL_RESET_INPLACE (HPC1_SCSI_CTRL_RESET_MASK << HPC1_SCSI_CTRL_RESET_SHIFT)

/*
 * SCSI FIFO pointer register. Present in both headers and in the chip interface
 * table; no driver read or write of it was found.
 */
/* scsi_pntr: rw32, space hpc1, reset unknown; IRIX developer header; IRIX
 * kernel */
#define HPC1_SCSI_PNTR_OFFSET                        0x98u /* inferred */

/*
 * SCSI FIFO data port. No driver access was found.
 */
/* scsi_fifo: rw32, space hpc1, reset unknown; IRIX developer header; IRIX
 * kernel */
#define HPC1_SCSI_FIFO_OFFSET                        0x9cu /* inferred */

/*
 * Parallel port byte count with the strobe timing fields. The header gives
 * three seven-bit timing fields at bits 30:24, 22:16 and 14:8; the driver
 * stores a placeholder here before it loads a descriptor.
 */
/* par_bc: rw32, space hpc1, reset unknown; IRIX developer header; IRIX parallel
 * driver */
#define HPC1_PAR_BC_OFFSET                           0xa8u /* established */
#define HPC1_PAR_BC_STROBE_MIN_SHIFT                 24 /* inferred */
#define HPC1_PAR_BC_STROBE_MIN_MASK                  0x7fu
#define HPC1_PAR_BC_STROBE_MIN_INPLACE (HPC1_PAR_BC_STROBE_MIN_MASK << HPC1_PAR_BC_STROBE_MIN_SHIFT)
#define HPC1_PAR_BC_STROBE_LEAD_SHIFT                16 /* inferred */
#define HPC1_PAR_BC_STROBE_LEAD_MASK                 0x7fu
#define HPC1_PAR_BC_STROBE_LEAD_INPLACE (HPC1_PAR_BC_STROBE_LEAD_MASK << HPC1_PAR_BC_STROBE_LEAD_SHIFT)
#define HPC1_PAR_BC_STROBE_TRAIL_SHIFT               8 /* inferred */
#define HPC1_PAR_BC_STROBE_TRAIL_MASK                0x7fu
#define HPC1_PAR_BC_STROBE_TRAIL_INPLACE (HPC1_PAR_BC_STROBE_TRAIL_MASK << HPC1_PAR_BC_STROBE_TRAIL_SHIFT)

/*
 * Parallel current buffer pointer. The PROM's power-on test writes a walking
 * one from bit 27 down to bit 0 and reads each value back, so at least the low
 * 28 bits are plain storage (the test cannot show bits 31:28 clear).
 */
/* par_cbp: rw32, space hpc1, reset unknown; IRIX developer header; Indigo PROM
 */
#define HPC1_PAR_CBP_OFFSET                          0xacu /* established */

/*
 * Parallel next descriptor pointer: the physical address of the first
 * descriptor, written before the control register.
 */
/* par_nbdp: rw32, space hpc1, reset unknown; IRIX developer header; IRIX
 * parallel driver */
#define HPC1_PAR_NBDP_OFFSET                         0xb0u /* established */

/*
 * Parallel port control.
 */
/* par_ctrl: rw32, space hpc1, reset unknown; IRIX developer header; IRIX
 * parallel driver */
#define HPC1_PAR_CTRL_OFFSET                         0xb4u /* established */
#define HPC1_PAR_CTRL_START_SHIFT                    7 /* established */
#define HPC1_PAR_CTRL_START_MASK                     0x1u
#define HPC1_PAR_CTRL_START_INPLACE (HPC1_PAR_CTRL_START_MASK << HPC1_PAR_CTRL_START_SHIFT)
#define HPC1_PAR_CTRL_FLUSH_SHIFT                    6 /* established */
#define HPC1_PAR_CTRL_FLUSH_MASK                     0x1u
#define HPC1_PAR_CTRL_FLUSH_INPLACE (HPC1_PAR_CTRL_FLUSH_MASK << HPC1_PAR_CTRL_FLUSH_SHIFT)
#define HPC1_PAR_CTRL_IGNORE_ACK_SHIFT               5 /* inferred */
#define HPC1_PAR_CTRL_IGNORE_ACK_MASK                0x1u
#define HPC1_PAR_CTRL_IGNORE_ACK_INPLACE (HPC1_PAR_CTRL_IGNORE_ACK_MASK << HPC1_PAR_CTRL_IGNORE_ACK_SHIFT)
#define HPC1_PAR_CTRL_TO_MEMORY_SHIFT                4 /* established */
#define HPC1_PAR_CTRL_TO_MEMORY_MASK                 0x1u
#define HPC1_PAR_CTRL_TO_MEMORY_INPLACE (HPC1_PAR_CTRL_TO_MEMORY_MASK << HPC1_PAR_CTRL_TO_MEMORY_SHIFT)
#define HPC1_PAR_CTRL_SOFT_ACK_SHIFT                 3 /* established */
#define HPC1_PAR_CTRL_SOFT_ACK_MASK                  0x1u
#define HPC1_PAR_CTRL_SOFT_ACK_INPLACE (HPC1_PAR_CTRL_SOFT_ACK_MASK << HPC1_PAR_CTRL_SOFT_ACK_SHIFT)
#define HPC1_PAR_CTRL_POLARITY_SHIFT                 2 /* inferred */
#define HPC1_PAR_CTRL_POLARITY_MASK                  0x1u
#define HPC1_PAR_CTRL_POLARITY_INPLACE (HPC1_PAR_CTRL_POLARITY_MASK << HPC1_PAR_CTRL_POLARITY_SHIFT)
#define HPC1_PAR_CTRL_INTERRUPT_SHIFT                1 /* established */
#define HPC1_PAR_CTRL_INTERRUPT_MASK                 0x1u
#define HPC1_PAR_CTRL_INTERRUPT_INPLACE (HPC1_PAR_CTRL_INTERRUPT_MASK << HPC1_PAR_CTRL_INTERRUPT_SHIFT)
#define HPC1_PAR_CTRL_RESET_SHIFT                    0 /* established */
#define HPC1_PAR_CTRL_RESET_MASK                     0x1u
#define HPC1_PAR_CTRL_RESET_INPLACE (HPC1_PAR_CTRL_RESET_MASK << HPC1_PAR_CTRL_RESET_SHIFT)

/*
 * Parallel FIFO status. Bits 22:16 hold the number of bytes still in the port
 * FIFO; the stop routine drains that many bytes by hand when the count is under
 * four.
 */
/* par_fifo: r32, space hpc1, reset unknown; IRIX parallel driver; NetBSD
 * register header */
#define HPC1_PAR_FIFO_OFFSET                         0xb8u /* inferred */

/*
 * Parallel DMA configuration, named by the public header only. No IRIX object
 * touches it.
 */
/* par_dmacfg: rw32, space hpc1, reset unknown; NetBSD register header */
#define HPC1_PAR_DMACFG_OFFSET                       0xbcu /* unknown */

/*
 * DMA byte order of each channel and the controller revision. A set bit makes
 * that channel's DMA words and descriptors little-endian; clear leaves them
 * big-endian. Only the low byte is used.
 */
/* endian: rw32, space hpc1, reset unknown; IRIX developer header; IRIX kernel;
 * NetBSD register header; Indigo PROM */
#define HPC1_ENDIAN_OFFSET                           0xc0u /* established */
#define HPC1_ENDIAN_REVISION_SHIFT                   6 /* inferred */
#define HPC1_ENDIAN_REVISION_MASK                    0x3u
#define HPC1_ENDIAN_REVISION_INPLACE (HPC1_ENDIAN_REVISION_MASK << HPC1_ENDIAN_REVISION_SHIFT)
#define HPC1_ENDIAN_DSP_LITTLE_SHIFT                 4 /* established */
#define HPC1_ENDIAN_DSP_LITTLE_MASK                  0x1u
#define HPC1_ENDIAN_DSP_LITTLE_INPLACE (HPC1_ENDIAN_DSP_LITTLE_MASK << HPC1_ENDIAN_DSP_LITTLE_SHIFT)
#define HPC1_ENDIAN_PAR_LITTLE_SHIFT                 3 /* established */
#define HPC1_ENDIAN_PAR_LITTLE_MASK                  0x1u
#define HPC1_ENDIAN_PAR_LITTLE_INPLACE (HPC1_ENDIAN_PAR_LITTLE_MASK << HPC1_ENDIAN_PAR_LITTLE_SHIFT)
#define HPC1_ENDIAN_SCSI_LITTLE_SHIFT                2 /* established */
#define HPC1_ENDIAN_SCSI_LITTLE_MASK                 0x1u
#define HPC1_ENDIAN_SCSI_LITTLE_INPLACE (HPC1_ENDIAN_SCSI_LITTLE_MASK << HPC1_ENDIAN_SCSI_LITTLE_SHIFT)
#define HPC1_ENDIAN_ENET_LITTLE_SHIFT                1 /* established */
#define HPC1_ENDIAN_ENET_LITTLE_MASK                 0x1u
#define HPC1_ENDIAN_ENET_LITTLE_INPLACE (HPC1_ENDIAN_ENET_LITTLE_MASK << HPC1_ENDIAN_ENET_LITTLE_SHIFT)
#define HPC1_ENDIAN_CPU_LITTLE_SHIFT                 0 /* established */
#define HPC1_ENDIAN_CPU_LITTLE_MASK                  0x1u
#define HPC1_ENDIAN_CPU_LITTLE_INPLACE (HPC1_ENDIAN_CPU_LITTLE_MASK << HPC1_ENDIAN_CPU_LITTLE_SHIFT)

/*
 * The Ethernet chip's eight registers, one per 32-bit slot with the byte in
 * bits 7:0; register n is at 0x100 plus 4n. Registers 0 to 5 hold the station
 * address, register 6 is the receive command and status and register 7 the
 * transmit command and status. The registers themselves are in
 * devices/seeq_8003.
 */
/* seeq: rw32, space hpc1, reset unknown; IRIX Ethernet driver; NetBSD register
 * header */
#define HPC1_SEEQ_OFFSET                             0x100u /* established */
#define HPC1_SEEQ_COUNT                              8
#define HPC1_SEEQ_STRIDE                             4

/*
 * The WD33C93's address/auxiliary-status port. The chip sits on the 15:8 byte
 * lane of the word: a big-endian byte access is at +2 and a little-endian one
 * at +1.
 */
/* wd33c93_address: rw32, space hpc1, reset unknown; IRIX developer header; IRIX
 * kernel; Indigo PROM */
#define HPC1_WD33C93_ADDRESS_OFFSET                  0x120u /* established */
#define HPC1_WD33C93_ADDRESS_DATA_SHIFT              8 /* established */
#define HPC1_WD33C93_ADDRESS_DATA_MASK               0xffu
#define HPC1_WD33C93_ADDRESS_DATA_INPLACE (HPC1_WD33C93_ADDRESS_DATA_MASK << HPC1_WD33C93_ADDRESS_DATA_SHIFT)

/*
 * The WD33C93's data port, on the same byte lane.
 */
/* wd33c93_data: rw32, space hpc1, reset unknown; IRIX developer header; IRIX
 * kernel; Indigo PROM */
#define HPC1_WD33C93_DATA_OFFSET                     0x124u /* established */
#define HPC1_WD33C93_DATA_DATA_SHIFT                 8 /* established */
#define HPC1_WD33C93_DATA_DATA_MASK                  0xffu
#define HPC1_WD33C93_DATA_DATA_INPLACE (HPC1_WD33C93_DATA_DATA_MASK << HPC1_WD33C93_DATA_DATA_SHIFT)

/*
 * Parallel port external status and remote register, one byte in bits 23:16 of
 * the word. A DMA read start stores 1 and a write start stores 3; the reset
 * routine clears it then stores 3.
 */
/* par_status: rw32, space hpc1, reset unknown; IRIX developer header; IRIX
 * parallel driver */
#define HPC1_PAR_STATUS_OFFSET                       0x134u /* established */

/*
 * DSP DMA transfer length in SRAM words. See devices/hollywood-dsp.
 */
/* dsp_dma_count: rw32, space hpc1, reset unknown; IRIX developer header; NetBSD
 * register header */
#define HPC1_DSP_DMA_COUNT_OFFSET                    0x180u /* inferred */

/*
 * Low 16 bits of the memory-side DMA address.
 */
/* dsp_gio_low: rw32, space hpc1, reset unknown; IRIX developer header */
#define HPC1_DSP_GIO_LOW_OFFSET                      0x184u /* inferred */

/*
 * High 16 bits of the memory-side DMA address.
 */
/* dsp_gio_high: rw32, space hpc1, reset unknown; IRIX developer header */
#define HPC1_DSP_GIO_HIGH_OFFSET                     0x188u /* inferred */

/*
 * 16-bit peripheral-bus (DSP SRAM) address of the DMA.
 */
/* dsp_pbus_addr: rw32, space hpc1, reset unknown; IRIX developer header */
#define HPC1_DSP_PBUS_ADDR_OFFSET                    0x18cu /* inferred */

/*
 * DSP DMA control.
 */
/* dsp_dma_ctrl: rw32, space hpc1, reset unknown; IRIX developer header; NetBSD
 * register header */
#define HPC1_DSP_DMA_CTRL_OFFSET                     0x190u /* inferred */
#define HPC1_DSP_DMA_CTRL_FOLDED_SHIFT               2 /* inferred */
#define HPC1_DSP_DMA_CTRL_FOLDED_MASK                0x1u
#define HPC1_DSP_DMA_CTRL_FOLDED_INPLACE (HPC1_DSP_DMA_CTRL_FOLDED_MASK << HPC1_DSP_DMA_CTRL_FOLDED_SHIFT)
#define HPC1_DSP_DMA_CTRL_DIRECTION_SHIFT            1 /* inferred */
#define HPC1_DSP_DMA_CTRL_DIRECTION_MASK             0x1u
#define HPC1_DSP_DMA_CTRL_DIRECTION_INPLACE (HPC1_DSP_DMA_CTRL_DIRECTION_MASK << HPC1_DSP_DMA_CTRL_DIRECTION_SHIFT)
#define HPC1_DSP_DMA_CTRL_GO_SHIFT                   0 /* inferred */
#define HPC1_DSP_DMA_CTRL_GO_MASK                    0x1u
#define HPC1_DSP_DMA_CTRL_GO_INPLACE (HPC1_DSP_DMA_CTRL_GO_MASK << HPC1_DSP_DMA_CTRL_GO_SHIFT)

/*
 * A free-running 24-bit counter; what it counts is not stated.
 */
/* dsp_counter: r32, space hpc1, reset unknown; IRIX developer header */
#define HPC1_DSP_COUNTER_OFFSET                      0x194u /* unknown */

/*
 * Handshake transmit word, written by the DSP for the host.
 */
/* dsp_hand_tx: rw32, space hpc1, reset unknown; IRIX developer header */
#define HPC1_DSP_HAND_TX_OFFSET                      0x198u /* inferred */

/*
 * Handshake receive word, written by the host for the DSP.
 */
/* dsp_hand_rx: rw32, space hpc1, reset unknown; IRIX developer header */
#define HPC1_DSP_HAND_RX_OFFSET                      0x19cu /* inferred */

/*
 * DSP-to-CPU interrupt status: bit 0 end of DMA, bit 1 the DSP wrote the
 * transmit word, bit 2 the DSP read the receive word.
 */
/* dsp_int_status: r32, space hpc1, reset unknown; IRIX developer header */
#define HPC1_DSP_INT_STATUS_OFFSET                   0x1a0u /* inferred */

/*
 * Enable bits for the three DSP interrupt sources.
 */
/* dsp_int_mask: rw32, space hpc1, reset unknown; IRIX developer header */
#define HPC1_DSP_INT_MASK_OFFSET                     0x1a4u /* inferred */

/*
 * DSP miscellaneous control. The PROM stores 9 (reset with 32K SRAM) at
 * start-up, 1 (reset) while it loads the DSP and 8 (run, 32K SRAM) afterwards.
 */
/* dsp_misc: rw32, space hpc1, reset unknown; IRIX developer header; NetBSD
 * register header; Indigo PROM */
#define HPC1_DSP_MISC_OFFSET                         0x1b0u /* inferred */
#define HPC1_DSP_MISC_PBUS_EXTEND_SHIFT              4 /* inferred */
#define HPC1_DSP_MISC_PBUS_EXTEND_MASK               0x7u
#define HPC1_DSP_MISC_PBUS_EXTEND_INPLACE (HPC1_DSP_MISC_PBUS_EXTEND_MASK << HPC1_DSP_MISC_PBUS_EXTEND_SHIFT)
#define HPC1_DSP_MISC_SRAM_32K_SHIFT                 3 /* established */
#define HPC1_DSP_MISC_SRAM_32K_MASK                  0x1u
#define HPC1_DSP_MISC_SRAM_32K_INPLACE (HPC1_DSP_MISC_SRAM_32K_MASK << HPC1_DSP_MISC_SRAM_32K_SHIFT)
#define HPC1_DSP_MISC_IRQA_HIGH_SHIFT                2 /* inferred */
#define HPC1_DSP_MISC_IRQA_HIGH_MASK                 0x1u
#define HPC1_DSP_MISC_IRQA_HIGH_INPLACE (HPC1_DSP_MISC_IRQA_HIGH_MASK << HPC1_DSP_MISC_IRQA_HIGH_SHIFT)
#define HPC1_DSP_MISC_IRQA_SHIFT                     1 /* inferred */
#define HPC1_DSP_MISC_IRQA_MASK                      0x1u
#define HPC1_DSP_MISC_IRQA_INPLACE (HPC1_DSP_MISC_IRQA_MASK << HPC1_DSP_MISC_IRQA_SHIFT)
#define HPC1_DSP_MISC_RESET_SHIFT                    0 /* established */
#define HPC1_DSP_MISC_RESET_MASK                     0x1u
#define HPC1_DSP_MISC_RESET_INPLACE (HPC1_DSP_MISC_RESET_MASK << HPC1_DSP_MISC_RESET_SHIFT)

/*
 * DMA burst length and spacing; the fields are not stated.
 */
/* dsp_burst: rw32, space hpc1, reset unknown; IRIX developer header; NetBSD
 * register header */
#define HPC1_DSP_BURST_OFFSET                        0x1b4u /* inferred */

/*
 * The auxiliary byte: the console LED and the four wires of the serial EEPROM.
 * Bit 0 is shared by the LED and the EEPROM protect-register enable.
 */
/* aux: rw32, space hpc1, reset unknown; IRIX developer header; IRIX kernel;
 * NetBSD register header; Indigo PROM */
#define HPC1_AUX_OFFSET                              0x1bcu /* established */
#define HPC1_AUX_EEPROM_DO_SHIFT                     4 /* established */
#define HPC1_AUX_EEPROM_DO_MASK                      0x1u
#define HPC1_AUX_EEPROM_DO_INPLACE (HPC1_AUX_EEPROM_DO_MASK << HPC1_AUX_EEPROM_DO_SHIFT)
#define HPC1_AUX_EEPROM_DI_SHIFT                     3 /* established */
#define HPC1_AUX_EEPROM_DI_MASK                      0x1u
#define HPC1_AUX_EEPROM_DI_INPLACE (HPC1_AUX_EEPROM_DI_MASK << HPC1_AUX_EEPROM_DI_SHIFT)
#define HPC1_AUX_EEPROM_SK_SHIFT                     2 /* established */
#define HPC1_AUX_EEPROM_SK_MASK                      0x1u
#define HPC1_AUX_EEPROM_SK_INPLACE (HPC1_AUX_EEPROM_SK_MASK << HPC1_AUX_EEPROM_SK_SHIFT)
#define HPC1_AUX_EEPROM_CS_SHIFT                     1 /* established */
#define HPC1_AUX_EEPROM_CS_MASK                      0x1u
#define HPC1_AUX_EEPROM_CS_INPLACE (HPC1_AUX_EEPROM_CS_MASK << HPC1_AUX_EEPROM_CS_SHIFT)
#define HPC1_AUX_LED_PRE_SHIFT                       0 /* established */
#define HPC1_AUX_LED_PRE_MASK                        0x1u
#define HPC1_AUX_LED_PRE_INPLACE (HPC1_AUX_LED_PRE_MASK << HPC1_AUX_LED_PRE_SHIFT)

/*
 * The interrupt controller window, 64 bytes at 0x1c0. The registers are in the
 * interrupt controller's own unit; the controller is not part of the HPC1.
 */
/* int2_window: rw32, space hpc1, reset unknown; IRIX developer header */
#define HPC1_INT2_WINDOW_OFFSET                      0x1c0u /* established */
#define HPC1_INT2_WINDOW_COUNT                       16
#define HPC1_INT2_WINDOW_STRIDE                      4

/*
 * Four 16-byte blocks of 8-bit registers at 0xd00, 0xd10, 0xd20, 0xd30, each
 * register in its own slot with the byte in bits 7:0 (offset +3 big-endian).
 * Blocks 0 to 2 are Z85C30 serial controllers; block 3 holds the two headphone
 * gain converters. The chip's registers are in its own unit.
 */
/* serial_window: rw32, space hpc1, reset unknown; IRIX developer header; IRIX
 * serial driver */
#define HPC1_SERIAL_WINDOW_OFFSET                    0xd00u /* established */
#define HPC1_SERIAL_WINDOW_COUNT                     16
#define HPC1_SERIAL_WINDOW_STRIDE                    4

/*
 * The battery-backed real-time clock window, one 8-bit register per 32-bit
 * slot, accessed by word at the slot. The chip's registers are in its own unit.
 */
/* clock_window: rw32, space hpc1, reset unknown; IRIX developer header; IRIX
 * kernel */
#define HPC1_CLOCK_WINDOW_OFFSET                     0xe00u /* established */
#define HPC1_CLOCK_WINDOW_COUNT                      32
#define HPC1_CLOCK_WINDOW_STRIDE                     4

/*
 * Board revision word, in the modem SRAM space. The kernel inverts the word and
 * takes bits 14:12; bit 15 is the header's marker for the HP1 base board.
 */
/* board_rev: r32, space hpc1, reset unknown; IRIX developer header; IRIX
 * kernel; Indigo PROM */
#define HPC1_BOARD_REV_OFFSET                        0x50000u /* established */
#define HPC1_BOARD_REV_HP1_MARKER_SHIFT              15 /* inferred */
#define HPC1_BOARD_REV_HP1_MARKER_MASK               0x1u
#define HPC1_BOARD_REV_HP1_MARKER_INPLACE (HPC1_BOARD_REV_HP1_MARKER_MASK << HPC1_BOARD_REV_HP1_MARKER_SHIFT)
#define HPC1_BOARD_REV_REVISION_INVERTED_SHIFT       12 /* established */
#define HPC1_BOARD_REV_REVISION_INVERTED_MASK        0x7u
#define HPC1_BOARD_REV_REVISION_INVERTED_INPLACE (HPC1_BOARD_REV_REVISION_INVERTED_MASK << HPC1_BOARD_REV_REVISION_INVERTED_SHIFT)

/*
 * The DSP SRAM, one 24-bit word per 32-bit slot, 128 KB.
 */
/* dsp_sram: rw32, space hpc1, reset unknown; IRIX developer header; NetBSD
 * register header; Indigo PROM */
#define HPC1_DSP_SRAM_OFFSET                         0x60000u /* established */
#define HPC1_DSP_SRAM_COUNT                          32768
#define HPC1_DSP_SRAM_STRIDE                         4

/*
 * Word 0 of the Ethernet DMA descriptor: flags and byte count. The HPC3 puts
 * the buffer address first and the flags second; the HPC1 order is the reverse.
 */
/* word ENET_DESC_W0: 32 bits; IRIX Ethernet driver; NetBSD register header */
#define HPC1_ENET_DESC_W0_WIDTH                      32 /* established */
#define HPC1_ENET_DESC_W0_EOP_SHIFT                  31 /* inferred */
#define HPC1_ENET_DESC_W0_EOP_MASK                   0x1u
#define HPC1_ENET_DESC_W0_EOP_INPLACE (HPC1_ENET_DESC_W0_EOP_MASK << HPC1_ENET_DESC_W0_EOP_SHIFT)
#define HPC1_ENET_DESC_W0_OWN_SHIFT                  30 /* inferred */
#define HPC1_ENET_DESC_W0_OWN_MASK                   0x1u
#define HPC1_ENET_DESC_W0_OWN_INPLACE (HPC1_ENET_DESC_W0_OWN_MASK << HPC1_ENET_DESC_W0_OWN_SHIFT)
#define HPC1_ENET_DESC_W0_INTR_SHIFT                 15 /* inferred */
#define HPC1_ENET_DESC_W0_INTR_MASK                  0x1u
#define HPC1_ENET_DESC_W0_INTR_INPLACE (HPC1_ENET_DESC_W0_INTR_MASK << HPC1_ENET_DESC_W0_INTR_SHIFT)
#define HPC1_ENET_DESC_W0_BYTE_COUNT_SHIFT           0 /* established */
#define HPC1_ENET_DESC_W0_BYTE_COUNT_MASK            0x1fffu
#define HPC1_ENET_DESC_W0_BYTE_COUNT_INPLACE (HPC1_ENET_DESC_W0_BYTE_COUNT_MASK << HPC1_ENET_DESC_W0_BYTE_COUNT_SHIFT)

/*
 * Word 1 of the Ethernet DMA descriptor: the buffer address with the
 * end-of-chain flag.
 */
/* word ENET_DESC_W1: 32 bits; IRIX Ethernet driver; NetBSD register header */
#define HPC1_ENET_DESC_W1_WIDTH                      32 /* established */
#define HPC1_ENET_DESC_W1_EOCHAIN_SHIFT              31 /* established */
#define HPC1_ENET_DESC_W1_EOCHAIN_MASK               0x1u
#define HPC1_ENET_DESC_W1_EOCHAIN_INPLACE (HPC1_ENET_DESC_W1_EOCHAIN_MASK << HPC1_ENET_DESC_W1_EOCHAIN_SHIFT)
#define HPC1_ENET_DESC_W1_BUFFER_SHIFT               0 /* established */
#define HPC1_ENET_DESC_W1_BUFFER_MASK                0xfffffffu
#define HPC1_ENET_DESC_W1_BUFFER_INPLACE (HPC1_ENET_DESC_W1_BUFFER_MASK << HPC1_ENET_DESC_W1_BUFFER_SHIFT)

/*
 * Word 2 of the Ethernet DMA descriptor.
 */
/* word ENET_DESC_W2: 32 bits; IRIX Ethernet driver; NetBSD register header */
#define HPC1_ENET_DESC_W2_WIDTH                      32 /* established */
#define HPC1_ENET_DESC_W2_NEXT_SHIFT                 0 /* established */
#define HPC1_ENET_DESC_W2_NEXT_MASK                  0xfffffffu
#define HPC1_ENET_DESC_W2_NEXT_INPLACE (HPC1_ENET_DESC_W2_NEXT_MASK << HPC1_ENET_DESC_W2_NEXT_SHIFT)

/*
 * Word 0 of the SCSI and parallel DMA descriptor. A descriptor is three
 * hardware words in a 16-byte slot; the fourth word is software-only. The words
 * are in the byte order that the endian register selects for the channel.
 */
/* word SCSI_DESC_W0: 32 bits; IRIX developer header; IRIX kernel */
#define HPC1_SCSI_DESC_W0_WIDTH                      32 /* established */
#define HPC1_SCSI_DESC_W0_BYTE_COUNT_SHIFT           0 /* established */
#define HPC1_SCSI_DESC_W0_BYTE_COUNT_MASK            0x1fffu
#define HPC1_SCSI_DESC_W0_BYTE_COUNT_INPLACE (HPC1_SCSI_DESC_W0_BYTE_COUNT_MASK << HPC1_SCSI_DESC_W0_BYTE_COUNT_SHIFT)

/*
 * Word 1 of the SCSI and parallel DMA descriptor.
 */
/* word SCSI_DESC_W1: 32 bits; IRIX developer header; IRIX kernel */
#define HPC1_SCSI_DESC_W1_WIDTH                      32 /* established */
#define HPC1_SCSI_DESC_W1_EOX_SHIFT                  31 /* established */
#define HPC1_SCSI_DESC_W1_EOX_MASK                   0x1u
#define HPC1_SCSI_DESC_W1_EOX_INPLACE (HPC1_SCSI_DESC_W1_EOX_MASK << HPC1_SCSI_DESC_W1_EOX_SHIFT)
#define HPC1_SCSI_DESC_W1_BUFFER_SHIFT               0 /* established */
#define HPC1_SCSI_DESC_W1_BUFFER_MASK                0xfffffffu
#define HPC1_SCSI_DESC_W1_BUFFER_INPLACE (HPC1_SCSI_DESC_W1_BUFFER_MASK << HPC1_SCSI_DESC_W1_BUFFER_SHIFT)

/*
 * Word 2 of the SCSI and parallel DMA descriptor.
 */
/* word SCSI_DESC_W2: 32 bits; IRIX developer header */
#define HPC1_SCSI_DESC_W2_WIDTH                      32 /* established */
#define HPC1_SCSI_DESC_W2_NEXT_SHIFT                 0 /* established */
#define HPC1_SCSI_DESC_W2_NEXT_MASK                  0xfffffffu
#define HPC1_SCSI_DESC_W2_NEXT_INPLACE (HPC1_SCSI_DESC_W2_NEXT_MASK << HPC1_SCSI_DESC_W2_NEXT_SHIFT)

#define HPC1_EEPROM_OP_PROTECT_CLEAR                 0xffffu /* established */
#define HPC1_EEPROM_OP_READ                          0xc000u /* established */
#define HPC1_EEPROM_OP_WRITE                         0xa000u /* established */
#define HPC1_EEPROM_OP_WRITE_ALL                     0x8800u /* inferred */
#define HPC1_EEPROM_OP_WRITE_DISABLE                 0x8000u /* established */
#define HPC1_EEPROM_OP_WRITE_ENABLE                  0x9800u /* established */
#define HPC1_NVRAM_ENET_OFFSET                       0xfau /* established */
#define HPC1_NVRAM_REVISION                          0x6u /* established */
#define HPC1_NVRAM_SIZE                              0x100u /* established */
#define HPC1_SCSI_START_DMA                          0x80u /* established */
#define HPC1_SCSI_START_DMA_TO_MEM                   0x90u /* established */

#endif /* HPC1_GEN_H */
