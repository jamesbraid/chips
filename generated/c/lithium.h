/* generated from devices/lithium/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 54a43e69300a6826905d64ebdf4107626a8df0731e7019264517aa75d3188b1f */
/* Lithium (I/O ASIC of the SGI Visual Workstation 320 and 540): the PCI bridge window and the audio engine, as SGI's Linux platform code names them */
#ifndef LITHIUM_GEN_H
#define LITHIUM_GEN_H

#include <stdint.h>


/*
 * Audio link controller. The driver resets the codec link by writing reset, waiting a microsecond, then writing link_enable alone, and never reads the register after that in the code read. The three low bits are named by the driver but never tested.
 */
/* host_ctl: rw32, space audio, reset unknown */
#define LITHIUM_HOST_CTL_OFFSET                      0x0u /* established */
#define LITHIUM_HOST_CTL_RESET_SHIFT                 15 /* established */
#define LITHIUM_HOST_CTL_RESET_MASK                  0x1u
#define LITHIUM_HOST_CTL_RESET_INPLACE               (LITHIUM_HOST_CTL_RESET_MASK << LITHIUM_HOST_CTL_RESET_SHIFT)
#define LITHIUM_HOST_CTL_LINK_ENABLE_SHIFT           14 /* established */
#define LITHIUM_HOST_CTL_LINK_ENABLE_MASK            0x1u
#define LITHIUM_HOST_CTL_LINK_ENABLE_INPLACE         (LITHIUM_HOST_CTL_LINK_ENABLE_MASK << LITHIUM_HOST_CTL_LINK_ENABLE_SHIFT)
#define LITHIUM_HOST_CTL_LINK_FAILURE_SHIFT          2 /* inferred */
#define LITHIUM_HOST_CTL_LINK_FAILURE_MASK           0x1u
#define LITHIUM_HOST_CTL_LINK_FAILURE_INPLACE        (LITHIUM_HOST_CTL_LINK_FAILURE_MASK << LITHIUM_HOST_CTL_LINK_FAILURE_SHIFT)
#define LITHIUM_HOST_CTL_LINK_CODEC_SHIFT            1 /* inferred */
#define LITHIUM_HOST_CTL_LINK_CODEC_MASK             0x1u
#define LITHIUM_HOST_CTL_LINK_CODEC_INPLACE          (LITHIUM_HOST_CTL_LINK_CODEC_MASK << LITHIUM_HOST_CTL_LINK_CODEC_SHIFT)
#define LITHIUM_HOST_CTL_LINK_READY_SHIFT            0 /* inferred */
#define LITHIUM_HOST_CTL_LINK_READY_MASK             0x1u
#define LITHIUM_HOST_CTL_LINK_READY_INPLACE          (LITHIUM_HOST_CTL_LINK_READY_MASK << LITHIUM_HOST_CTL_LINK_READY_SHIFT)

/*
 * Audio interrupt status. The driver clears pending bits by writing ones to the bits it wants cleared, and writes all ones to clear everything, so the bits are write-one-to-clear (inferred from the driver's use; no comment says so). It then masks the value it read with the mask register.
 */
/* intr_status: rw32, space audio, reset unknown */
#define LITHIUM_INTR_STATUS_OFFSET                   0x10u /* inferred */
#define LITHIUM_INTR_STATUS_LINK_ERR_SHIFT           15 /* inferred */
#define LITHIUM_INTR_STATUS_LINK_ERR_MASK            0x1u
#define LITHIUM_INTR_STATUS_LINK_ERR_INPLACE         (LITHIUM_INTR_STATUS_LINK_ERR_MASK << LITHIUM_INTR_STATUS_LINK_ERR_SHIFT)
#define LITHIUM_INTR_STATUS_COMM2_TRIG_SHIFT         3 /* inferred */
#define LITHIUM_INTR_STATUS_COMM2_TRIG_MASK          0x1u
#define LITHIUM_INTR_STATUS_COMM2_TRIG_INPLACE       (LITHIUM_INTR_STATUS_COMM2_TRIG_MASK << LITHIUM_INTR_STATUS_COMM2_TRIG_SHIFT)
#define LITHIUM_INTR_STATUS_COMM2_UNDERFLOW_SHIFT    2 /* inferred */
#define LITHIUM_INTR_STATUS_COMM2_UNDERFLOW_MASK     0x1u
#define LITHIUM_INTR_STATUS_COMM2_UNDERFLOW_INPLACE  (LITHIUM_INTR_STATUS_COMM2_UNDERFLOW_MASK << LITHIUM_INTR_STATUS_COMM2_UNDERFLOW_SHIFT)
#define LITHIUM_INTR_STATUS_COMM1_TRIG_SHIFT         1 /* inferred */
#define LITHIUM_INTR_STATUS_COMM1_TRIG_MASK          0x1u
#define LITHIUM_INTR_STATUS_COMM1_TRIG_INPLACE       (LITHIUM_INTR_STATUS_COMM1_TRIG_MASK << LITHIUM_INTR_STATUS_COMM1_TRIG_SHIFT)
#define LITHIUM_INTR_STATUS_COMM1_OVERFLOW_SHIFT     0 /* inferred */
#define LITHIUM_INTR_STATUS_COMM1_OVERFLOW_MASK      0x1u
#define LITHIUM_INTR_STATUS_COMM1_OVERFLOW_INPLACE   (LITHIUM_INTR_STATUS_COMM1_OVERFLOW_MASK << LITHIUM_INTR_STATUS_COMM1_OVERFLOW_SHIFT)

/*
 * Audio interrupt enable mask, same bit layout as the status. The driver sets bits by read-modify-write and clears them the same way.
 */
/* intr_mask: rw32, space audio, reset unknown */
#define LITHIUM_INTR_MASK_OFFSET                     0x14u /* inferred */

/*
 * Codec register access. A write starts a codec register read or write; the driver waits until busy clears (about two ticks at most) before and after. For a write it puts the data in codec_data first; for a read it reads codec_data afterwards.
 */
/* codec_command: rw32, space audio, reset unknown */
#define LITHIUM_CODEC_COMMAND_OFFSET                 0x18u /* established */
#define LITHIUM_CODEC_COMMAND_BUSY_SHIFT             15 /* established */
#define LITHIUM_CODEC_COMMAND_BUSY_MASK              0x1u
#define LITHIUM_CODEC_COMMAND_BUSY_INPLACE           (LITHIUM_CODEC_COMMAND_BUSY_MASK << LITHIUM_CODEC_COMMAND_BUSY_SHIFT)
#define LITHIUM_CODEC_COMMAND_DIR_SHIFT              7 /* established */
#define LITHIUM_CODEC_COMMAND_DIR_MASK               0x1u
#define LITHIUM_CODEC_COMMAND_DIR_INPLACE            (LITHIUM_CODEC_COMMAND_DIR_MASK << LITHIUM_CODEC_COMMAND_DIR_SHIFT)
#define LITHIUM_CODEC_COMMAND_ADDR_SHIFT             0 /* established */
#define LITHIUM_CODEC_COMMAND_ADDR_MASK              0x7fu
#define LITHIUM_CODEC_COMMAND_ADDR_INPLACE           (LITHIUM_CODEC_COMMAND_ADDR_MASK << LITHIUM_CODEC_COMMAND_ADDR_SHIFT)

/*
 * Codec register data, 16 bits used by the driver.
 */
/* codec_data: rw32, space audio, reset unknown */
#define LITHIUM_CODEC_DATA_OFFSET                    0x1cu /* established */

/*
 * Input DMA ring buffer base: the 40-bit physical address shifted right 8, with bit 29 set. The driver says bit 37 of the address (bit 29 here) must be set, and that it enables cache coherence. The ring is up to 8 KiB, 256 byte-aligned. The driver also writes this register once with the output buffer's address even when only output is used, because the input channel carries stray data otherwise (the driver quotes the NT driver on this).
 */
/* comm1_base: rw32, space audio, reset unknown */
#define LITHIUM_COMM1_BASE_OFFSET                    0x100u /* established */

/*
 * Input DMA control and pointers. The two low bytes are the write and read pointers in 32-byte chunks; for the input channel the hardware advances the write pointer and software the read pointer. The driver reads and writes each pointer as a single byte, at the first and second byte of this register.
 */
/* comm1_ctl: rw32, space audio, reset unknown */
#define LITHIUM_COMM1_CTL_OFFSET                     0x104u /* inferred */
#define LITHIUM_COMM1_CTL_RESET_SHIFT                31 /* inferred */
#define LITHIUM_COMM1_CTL_RESET_MASK                 0x1u
#define LITHIUM_COMM1_CTL_RESET_INPLACE              (LITHIUM_COMM1_CTL_RESET_MASK << LITHIUM_COMM1_CTL_RESET_SHIFT)
#define LITHIUM_COMM1_CTL_SIZE_SHIFT                 28 /* inferred */
#define LITHIUM_COMM1_CTL_SIZE_MASK                  0x7u
#define LITHIUM_COMM1_CTL_SIZE_INPLACE               (LITHIUM_COMM1_CTL_SIZE_MASK << LITHIUM_COMM1_CTL_SIZE_SHIFT)
#define LITHIUM_COMM1_CTL_DMA_ENABLE_SHIFT           27 /* inferred */
#define LITHIUM_COMM1_CTL_DMA_ENABLE_MASK            0x1u
#define LITHIUM_COMM1_CTL_DMA_ENABLE_INPLACE         (LITHIUM_COMM1_CTL_DMA_ENABLE_MASK << LITHIUM_COMM1_CTL_DMA_ENABLE_SHIFT)
#define LITHIUM_COMM1_CTL_TMASK_SHIFT                24 /* inferred */
#define LITHIUM_COMM1_CTL_TMASK_MASK                 0x7u
#define LITHIUM_COMM1_CTL_TMASK_INPLACE              (LITHIUM_COMM1_CTL_TMASK_MASK << LITHIUM_COMM1_CTL_TMASK_SHIFT)
#define LITHIUM_COMM1_CTL_TPTR_SHIFT                 16 /* inferred */
#define LITHIUM_COMM1_CTL_TPTR_MASK                  0xffu
#define LITHIUM_COMM1_CTL_TPTR_INPLACE               (LITHIUM_COMM1_CTL_TPTR_MASK << LITHIUM_COMM1_CTL_TPTR_SHIFT)
#define LITHIUM_COMM1_CTL_RPTR_SHIFT                 8 /* inferred */
#define LITHIUM_COMM1_CTL_RPTR_MASK                  0xffu
#define LITHIUM_COMM1_CTL_RPTR_INPLACE               (LITHIUM_COMM1_CTL_RPTR_MASK << LITHIUM_COMM1_CTL_RPTR_SHIFT)
#define LITHIUM_COMM1_CTL_WPTR_SHIFT                 0 /* inferred */
#define LITHIUM_COMM1_CTL_WPTR_MASK                  0xffu
#define LITHIUM_COMM1_CTL_WPTR_INPLACE               (LITHIUM_COMM1_CTL_WPTR_MASK << LITHIUM_COMM1_CTL_WPTR_SHIFT)

/*
 * Input DMA configuration.
 */
/* comm1_cfg: rw32, space audio, reset unknown */
#define LITHIUM_COMM1_CFG_OFFSET                     0x108u /* inferred */
#define LITHIUM_COMM1_CFG_LOCK_SHIFT                 15 /* inferred */
#define LITHIUM_COMM1_CFG_LOCK_MASK                  0x1u
#define LITHIUM_COMM1_CFG_LOCK_INPLACE               (LITHIUM_COMM1_CFG_LOCK_MASK << LITHIUM_COMM1_CFG_LOCK_SHIFT)
#define LITHIUM_COMM1_CFG_SLOT_SHIFT                 4 /* inferred */
#define LITHIUM_COMM1_CFG_SLOT_MASK                  0x7u
#define LITHIUM_COMM1_CFG_SLOT_INPLACE               (LITHIUM_COMM1_CFG_SLOT_MASK << LITHIUM_COMM1_CFG_SLOT_SHIFT)
#define LITHIUM_COMM1_CFG_DIRECTION_SHIFT            3 /* inferred */
#define LITHIUM_COMM1_CFG_DIRECTION_MASK             0x1u
#define LITHIUM_COMM1_CFG_DIRECTION_INPLACE          (LITHIUM_COMM1_CFG_DIRECTION_MASK << LITHIUM_COMM1_CFG_DIRECTION_SHIFT)
#define LITHIUM_COMM1_CFG_MODE_SHIFT                 2 /* inferred */
#define LITHIUM_COMM1_CFG_MODE_MASK                  0x1u
#define LITHIUM_COMM1_CFG_MODE_INPLACE               (LITHIUM_COMM1_CFG_MODE_MASK << LITHIUM_COMM1_CFG_MODE_SHIFT)
#define LITHIUM_COMM1_CFG_FORMAT_SHIFT               0 /* inferred */
#define LITHIUM_COMM1_CFG_FORMAT_MASK                0x3u
#define LITHIUM_COMM1_CFG_FORMAT_INPLACE             (LITHIUM_COMM1_CFG_FORMAT_MASK << LITHIUM_COMM1_CFG_FORMAT_SHIFT)

/*
 * Output DMA ring buffer base, same encoding as comm1_base.
 */
/* comm2_base: rw32, space audio, reset unknown */
#define LITHIUM_COMM2_BASE_OFFSET                    0x10cu /* established */

/*
 * Output DMA control and pointers, same layout as comm1_ctl. For output the hardware advances the read pointer and software the write pointer.
 */
/* comm2_ctl: rw32, space audio, reset unknown */
#define LITHIUM_COMM2_CTL_OFFSET                     0x110u /* inferred */

/*
 * Output DMA configuration, same layout as comm1_cfg.
 */
/* comm2_cfg: rw32, space audio, reset unknown */
#define LITHIUM_COMM2_CFG_OFFSET                     0x114u /* inferred */

/*
 * Low word of a 64-bit counter the driver calls unadjusted system time, microseconds since boot.
 */
/* ust_low: r32, space audio, reset unknown */
#define LITHIUM_UST_LOW_OFFSET                       0x200u /* established */

/*
 * High word of the same counter. The driver reads it before and after the other words and retries if it changed.
 */
/* ust_high: r32, space audio, reset unknown */
#define LITHIUM_UST_HIGH_OFFSET                      0x204u /* established */

/*
 * Time stamp of the input channel's last sample counter update.
 */
/* audio1_ust: r32, space audio, reset unknown */
#define LITHIUM_AUDIO1_UST_OFFSET                    0x300u /* inferred */

/*
 * Input media stream counter: samples processed as of audio1_ust.
 */
/* audio1_msc: r32, space audio, reset unknown */
#define LITHIUM_AUDIO1_MSC_OFFSET                    0x304u /* inferred */

/*
 * Time stamp for the output channel.
 */
/* audio2_ust: r32, space audio, reset unknown */
#define LITHIUM_AUDIO2_UST_OFFSET                    0x308u /* inferred */

/*
 * Output media stream counter.
 */
/* audio2_msc: r32, space audio, reset unknown */
#define LITHIUM_AUDIO2_MSC_OFFSET                    0x30cu /* inferred */

/*
 * Bus numbers behind the bridge. Linux reads it as a 16-bit value from each bridge's window and keeps the low byte as that bridge's PCI bus number, then scans that bus. The header comment says low byte primary, high byte subordinate; the high byte is never read. Whether the register is writable is unknown (only read).
 */
/* bus_number: r16, space bridge, reset unknown */
#define LITHIUM_BUS_NUMBER_OFFSET                    0x44u /* inferred */
#define LITHIUM_BUS_NUMBER_SUBORDINATE_SHIFT         8 /* inferred */
#define LITHIUM_BUS_NUMBER_SUBORDINATE_MASK          0xffu
#define LITHIUM_BUS_NUMBER_SUBORDINATE_INPLACE       (LITHIUM_BUS_NUMBER_SUBORDINATE_MASK << LITHIUM_BUS_NUMBER_SUBORDINATE_SHIFT)
#define LITHIUM_BUS_NUMBER_PRIMARY_SHIFT             0 /* inferred */
#define LITHIUM_BUS_NUMBER_PRIMARY_MASK              0xffu
#define LITHIUM_BUS_NUMBER_PRIMARY_INPLACE           (LITHIUM_BUS_NUMBER_PRIMARY_MASK << LITHIUM_BUS_NUMBER_PRIMARY_SHIFT)

/*
 * Interrupt enables, one bit per PCI interrupt source of the bridge. Linux writes it once at start-up, to every device bit on both bridges (the 2.2 kernel writes 0xffff, later kernels 0x00ff), and never reads it. The header calls the five low bits the INTA lines of the five slots and the next three the shared INTB, INTC and INTD. Reset state unknown, and so whether the firmware leaves it masked.
 */
/* int_enable: rw16, space bridge, reset unknown */
#define LITHIUM_INT_ENABLE_OFFSET                    0x46u /* established */
#define LITHIUM_INT_ENABLE_INTD_SHIFT                7 /* inferred */
#define LITHIUM_INT_ENABLE_INTD_MASK                 0x1u
#define LITHIUM_INT_ENABLE_INTD_INPLACE              (LITHIUM_INT_ENABLE_INTD_MASK << LITHIUM_INT_ENABLE_INTD_SHIFT)
#define LITHIUM_INT_ENABLE_INTC_SHIFT                6 /* inferred */
#define LITHIUM_INT_ENABLE_INTC_MASK                 0x1u
#define LITHIUM_INT_ENABLE_INTC_INPLACE              (LITHIUM_INT_ENABLE_INTC_MASK << LITHIUM_INT_ENABLE_INTC_SHIFT)
#define LITHIUM_INT_ENABLE_INTB_SHIFT                5 /* inferred */
#define LITHIUM_INT_ENABLE_INTB_MASK                 0x1u
#define LITHIUM_INT_ENABLE_INTB_INPLACE              (LITHIUM_INT_ENABLE_INTB_MASK << LITHIUM_INT_ENABLE_INTB_SHIFT)
#define LITHIUM_INT_ENABLE_INTA_4_SHIFT              4 /* inferred */
#define LITHIUM_INT_ENABLE_INTA_4_MASK               0x1u
#define LITHIUM_INT_ENABLE_INTA_4_INPLACE            (LITHIUM_INT_ENABLE_INTA_4_MASK << LITHIUM_INT_ENABLE_INTA_4_SHIFT)
#define LITHIUM_INT_ENABLE_INTA_3_SHIFT              3 /* inferred */
#define LITHIUM_INT_ENABLE_INTA_3_MASK               0x1u
#define LITHIUM_INT_ENABLE_INTA_3_INPLACE            (LITHIUM_INT_ENABLE_INTA_3_MASK << LITHIUM_INT_ENABLE_INTA_3_SHIFT)
#define LITHIUM_INT_ENABLE_INTA_2_SHIFT              2 /* inferred */
#define LITHIUM_INT_ENABLE_INTA_2_MASK               0x1u
#define LITHIUM_INT_ENABLE_INTA_2_INPLACE            (LITHIUM_INT_ENABLE_INTA_2_MASK << LITHIUM_INT_ENABLE_INTA_2_SHIFT)
#define LITHIUM_INT_ENABLE_INTA_1_SHIFT              1 /* inferred */
#define LITHIUM_INT_ENABLE_INTA_1_MASK               0x1u
#define LITHIUM_INT_ENABLE_INTA_1_INPLACE            (LITHIUM_INT_ENABLE_INTA_1_MASK << LITHIUM_INT_ENABLE_INTA_1_SHIFT)
#define LITHIUM_INT_ENABLE_INTA_0_SHIFT              0 /* inferred */
#define LITHIUM_INT_ENABLE_INTA_0_MASK               0x1u
#define LITHIUM_INT_ENABLE_INTA_0_INPLACE            (LITHIUM_INT_ENABLE_INTA_0_MASK << LITHIUM_INT_ENABLE_INTA_0_SHIFT)

#define LITHIUM_AUDIO_PAGE1                          0xff00f000u /* established */
#define LITHIUM_AUDIO_PAGE2                          0xff010000u /* established */
#define LITHIUM_AUDIO_PHYS                           0xff001000u /* established */
#define LITHIUM_DEVICE_ID                            0x1002u /* inferred */
#define LITHIUM_DMA_CHUNK                            0x20u /* inferred */
#define LITHIUM_PCI_A_PHYS                           0xfc000000u /* established */
#define LITHIUM_PCI_B_PHYS                           0xfd000000u /* established */
#define LITHIUM_VENDOR_ID                            0x10a9u /* inferred */

#endif /* LITHIUM_GEN_H */
