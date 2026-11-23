/* generated from devices/lithium/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 2ecc848822dac3d53b8566dbf237b74f289a92c859754826456896e519933761 */
/* Lithium (I/O ASIC of the SGI Visual Workstation 320 and 540): the PCI bridge window and the audio engine, as SGI's Linux platform code names them */
#ifndef LITHIUM_GEN_H
#define LITHIUM_GEN_H

#include <stdint.h>


/*
 * Audio link controller. The driver resets the codec link by writing reset, waiting a microsecond, then writing link_enable alone, and never reads the register after that in the code read. PROM 1.1005 also stores link enable plus bit 8 here, as a 32-bit write on Lithium generation 5 (software/visws/boot-path.md). The three low bits are named by the driver but never tested.
 */
/* host_ctl: rw32, space audio, reset unknown */
#define LITHIUM_HOST_CTL_OFFSET                      0x0u /* established */
#define LITHIUM_HOST_CTL_RESET_SHIFT                 15 /* established */
#define LITHIUM_HOST_CTL_RESET_MASK                  0x1u
#define LITHIUM_HOST_CTL_RESET_INPLACE               (LITHIUM_HOST_CTL_RESET_MASK << LITHIUM_HOST_CTL_RESET_SHIFT)
#define LITHIUM_HOST_CTL_LINK_ENABLE_SHIFT           14 /* established */
#define LITHIUM_HOST_CTL_LINK_ENABLE_MASK            0x1u
#define LITHIUM_HOST_CTL_LINK_ENABLE_INPLACE         (LITHIUM_HOST_CTL_LINK_ENABLE_MASK << LITHIUM_HOST_CTL_LINK_ENABLE_SHIFT)
#define LITHIUM_HOST_CTL_PROM_BIT8_SHIFT             8 /* unknown */
#define LITHIUM_HOST_CTL_PROM_BIT8_MASK              0x1u
#define LITHIUM_HOST_CTL_PROM_BIT8_INPLACE           (LITHIUM_HOST_CTL_PROM_BIT8_MASK << LITHIUM_HOST_CTL_PROM_BIT8_SHIFT)
#define LITHIUM_HOST_CTL_LINK_FAILURE_SHIFT          2 /* established */
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
#define LITHIUM_COMM1_CTL_SIZE_SHIFT                 28 /* established */
#define LITHIUM_COMM1_CTL_SIZE_MASK                  0x7u
#define LITHIUM_COMM1_CTL_SIZE_INPLACE               (LITHIUM_COMM1_CTL_SIZE_MASK << LITHIUM_COMM1_CTL_SIZE_SHIFT)
#define LITHIUM_COMM1_CTL_DMA_ENABLE_SHIFT           27 /* established */
#define LITHIUM_COMM1_CTL_DMA_ENABLE_MASK            0x1u
#define LITHIUM_COMM1_CTL_DMA_ENABLE_INPLACE         (LITHIUM_COMM1_CTL_DMA_ENABLE_MASK << LITHIUM_COMM1_CTL_DMA_ENABLE_SHIFT)
#define LITHIUM_COMM1_CTL_TMASK_SHIFT                24 /* inferred */
#define LITHIUM_COMM1_CTL_TMASK_MASK                 0x7u
#define LITHIUM_COMM1_CTL_TMASK_INPLACE              (LITHIUM_COMM1_CTL_TMASK_MASK << LITHIUM_COMM1_CTL_TMASK_SHIFT)
#define LITHIUM_COMM1_CTL_TPTR_SHIFT                 16 /* inferred */
#define LITHIUM_COMM1_CTL_TPTR_MASK                  0xffu
#define LITHIUM_COMM1_CTL_TPTR_INPLACE               (LITHIUM_COMM1_CTL_TPTR_MASK << LITHIUM_COMM1_CTL_TPTR_SHIFT)
#define LITHIUM_COMM1_CTL_RPTR_SHIFT                 8 /* established */
#define LITHIUM_COMM1_CTL_RPTR_MASK                  0xffu
#define LITHIUM_COMM1_CTL_RPTR_INPLACE               (LITHIUM_COMM1_CTL_RPTR_MASK << LITHIUM_COMM1_CTL_RPTR_SHIFT)
#define LITHIUM_COMM1_CTL_WPTR_SHIFT                 0 /* established */
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
#define LITHIUM_COMM1_CFG_DIRECTION_SHIFT            3 /* established */
#define LITHIUM_COMM1_CFG_DIRECTION_MASK             0x1u
#define LITHIUM_COMM1_CFG_DIRECTION_INPLACE          (LITHIUM_COMM1_CFG_DIRECTION_MASK << LITHIUM_COMM1_CFG_DIRECTION_SHIFT)
#define LITHIUM_COMM1_CFG_MODE_SHIFT                 2 /* established */
#define LITHIUM_COMM1_CFG_MODE_MASK                  0x1u
#define LITHIUM_COMM1_CFG_MODE_INPLACE               (LITHIUM_COMM1_CFG_MODE_MASK << LITHIUM_COMM1_CFG_MODE_SHIFT)
#define LITHIUM_COMM1_CFG_FORMAT_SHIFT               0 /* established */
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
 * Low word of a 64-bit counter Linux calls unadjusted system time, microseconds since boot (the unit is Linux's comment; the time driver scales the value by 1000). The NT audio driver never reads it. The time driver and the video driver map these eight bytes on their own, and the time driver writes zero to both words at load, so they are writable. Both drivers also retry a read when the low halfword is 0xffff (their rules differ; see the NT drivers page).
 */
/* ust_low: rw32, space audio, reset unknown */
#define LITHIUM_UST_LOW_OFFSET                       0x200u /* established */

/*
 * High word of the same counter. The NT audio, time and video drivers all read it before and after the other words and retry if it changed; the time driver zeroes it at load.
 */
/* ust_high: rw32, space audio, reset unknown */
#define LITHIUM_UST_HIGH_OFFSET                      0x204u /* established */

/*
 * Time stamp of the input channel's last sample counter update. The NT driver pairs it with ust_high (read first, re-read afterwards, retried until equal) to form a 64-bit time stamp for the media stream counter.
 */
/* audio1_ust: r32, space audio, reset unknown */
#define LITHIUM_AUDIO1_UST_OFFSET                    0x300u /* established */

/*
 * Input media stream counter: samples processed as of audio1_ust. The NT driver writes zero to it when it starts input with no pending counter pair, so it is writable.
 */
/* audio1_msc: rw32, space audio, reset unknown */
#define LITHIUM_AUDIO1_MSC_OFFSET                    0x304u /* established */

/*
 * Time stamp for the output channel, read the same way as audio1_ust.
 */
/* audio2_ust: r32, space audio, reset unknown */
#define LITHIUM_AUDIO2_UST_OFFSET                    0x308u /* established */

/*
 * Output media stream counter. The NT driver writes zero to it when it starts output with no pending counter pair, so it is writable.
 */
/* audio2_msc: rw32, space audio, reset unknown */
#define LITHIUM_AUDIO2_MSC_OFFSET                    0x30cu /* established */

/*
 * A word on the second audio page, offset from physical 0xff00f000. Both audio drivers store the silence sample here before they start DMA: 0x80808080 for 8-bit samples, 0 for 16-bit (sgisound.sys 5.2.2, sndStartDMA, read in full; Linux's Visual Workstation sound driver writes the same). Linux's comment calls it an undocumented register holding the zero sample, which the hardware repeats after an underflow with a bug that leaves the old value in place. That comment is the only statement of its role, so the role is inferred; reads are never made, so the readable value is unknown.
 */
/* silence_word: rw32, space audio_page1, reset unknown */
#define LITHIUM_SILENCE_WORD_OFFSET                  0x500u /* inferred */

/*
 * Two words on the third audio page, offset from physical 0xff010000 (0x98 and 0x9c). Linux's comment calls them undocumented internal copies of the DMA read and write pointers that the chip fails to zero when DMA stops, so it zeroes them itself after stopping output. The NT driver zeroes both when it starts output (sgisound.sys 5.2.2, sndStartDMA). Which word is which pointer is unknown. The behaviour is Linux's statement only and the accesses are established, so the role is inferred.
 */
/* dma_pointer_copy: rw32, space audio_page2, reset unknown */
#define LITHIUM_DMA_POINTER_COPY_OFFSET              0x98u /* inferred */
#define LITHIUM_DMA_POINTER_COPY_COUNT               2
#define LITHIUM_DMA_POINTER_COPY_STRIDE              4

/*
 * Command word of the standard header. The NT HAL stores all ones here once when it sets up a bridge whose revision byte is above zero; nothing reads it back. Whether every bit is writable is unknown. No reset value is known.
 */
/* bridge_cmd: rw16, space bridge, reset unknown */
#define LITHIUM_BRIDGE_CMD_OFFSET                    0x4u /* inferred */

/*
 * Status word of the standard header. The HAL stores a value with bits 15:11 set here at bridge set-up and the master-abort bit (bit 13) after each configuration access; the PROM never touches it. That the bits clear on a written one is the standard header's rule and is inferred. Which bits the bridge ever sets is unknown.
 */
/* bridge_status: rw16, space bridge, reset unknown */
#define LITHIUM_BRIDGE_STATUS_OFFSET                 0x6u /* inferred */

/*
 * Revision byte. The HAL tests it above zero to choose where the bus number goes; the PROM tests bridge B's byte against zero and maps zero to Lithium generation 1. Only zero or not zero is used; the values and the reset state are unknown.
 */
/* bridge_rev: r8, space bridge, reset unknown */
#define LITHIUM_BRIDGE_REV_OFFSET                    0x8u /* established */

/*
 * When the revision byte is zero the top byte holds the bus number: the HAL clears bits 31:24 and ORs in the bus number shifted up 24, as a 32-bit read-modify-write. PROM 1.0002 and 1.0004 also read-modify-write this word before their error-status and control stores; later PROM images do not touch it. The meaning of the other bits is unknown.
 */
/* bridge_40: rw32, space bridge, reset unknown */
#define LITHIUM_BRIDGE_40_OFFSET                     0x40u /* inferred */

/*
 * Bus numbers behind the bridge. Linux reads it as a 16-bit value from each bridge's window and keeps the low byte as that bridge's PCI bus number, then scans that bus. The header comment says low byte primary, high byte subordinate; the high byte is never read by Linux. It is writable: the NT HAL read-modify-writes it (clears and sets the low byte for the primary number, then the next byte for the subordinate number) and the PROM stores its two bytes separately in its bus numbering. The self-test also reads and restores the dword that holds it, in bridge B only.
 */
/* bus_number: rw16, space bridge, reset unknown */
#define LITHIUM_BUS_NUMBER_OFFSET                    0x44u /* inferred */
#define LITHIUM_BUS_NUMBER_SUBORDINATE_SHIFT         8 /* inferred */
#define LITHIUM_BUS_NUMBER_SUBORDINATE_MASK          0xffu
#define LITHIUM_BUS_NUMBER_SUBORDINATE_INPLACE       (LITHIUM_BUS_NUMBER_SUBORDINATE_MASK << LITHIUM_BUS_NUMBER_SUBORDINATE_SHIFT)
#define LITHIUM_BUS_NUMBER_PRIMARY_SHIFT             0 /* inferred */
#define LITHIUM_BUS_NUMBER_PRIMARY_MASK              0xffu
#define LITHIUM_BUS_NUMBER_PRIMARY_INPLACE           (LITHIUM_BUS_NUMBER_PRIMARY_MASK << LITHIUM_BUS_NUMBER_PRIMARY_SHIFT)

/*
 * Interrupt enables, one bit per PCI interrupt source of the bridge. Linux writes it once at start-up, to every device bit on both bridges (the 2.2 kernel writes 0xffff, later kernels 0x00ff), and never reads it. The header calls the five low bits the INTA lines of the five slots and the next three the shared INTB, INTC and INTD. The PROM self-test requires bits 13:8 to be settable and clearable, on bridge B only (it reads, tests and restores the 32-bit word that holds this register in its upper half, mask bits 29:24), so six more bits exist above the eight the kernels use; their sources are unknown. The NT HAL uses the register differently from the header comment: for a Cobalt interrupt line n below 16 (lines 0 to 7 on bridge A, 8 to 15 on bridge B) it ORs bit n&7 into this register, under a spin lock, once, and never clears a bit (halborg.dll 1.3 HalpEnableLiInt, read in full). So the bit gates the Cobalt line by number, whichever bus the source is on, which does not fit the per-device reading of the bit names below; the bit names stay as the header comment gives them (inferred) and the HAL's use is the established software behaviour. Reset state unknown, and so whether the firmware leaves it masked.
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

/*
 * Error status. The PROM stores all ones here in both bridges at the start of its bridge set-up and nothing in the NT HAL or the PROM reads it, so the PROM never examines what the bridge records. The shipped NT USB driver also writes all ones and prints the word as PCI Error Status. Write-one-to-clear is the reading of those stores and the name. The bit meanings, what raises them and whether the bridge reports parity errors are unknown. The USB driver's message table also has a "PCI Error Status Address" string, which implies an address register beside this one; the driver's code touches only the error status word (it maps 0x70 bytes of the window and stores once), so the address register's offset is unread and unknown.
 */
/* err_status: rw32, space bridge, reset unknown */
#define LITHIUM_ERR_STATUS_OFFSET                    0x48u /* inferred */

/*
 * Bridge control, meaning unknown. All accesses are 32-bit and all by the PROM: the boot block ORs the low five bits into it in both bridges before the main module runs, the main module then stores a value with bit 11 and bits 4:0 set, and the self-test checks that bits 1:0 can be set and cleared, on bridge B only. The NT HAL never touches it.
 */
/* bridge_58: rw32, space bridge, reset unknown */
#define LITHIUM_BRIDGE_58_OFFSET                     0x58u /* inferred */

/*
 * Thirty-two words, one per PCI device number on the bridge's bus (inferred from the PROM's device scan, which indexes them by device number). The PROM sets up the first five with one 32-bit read-modify-write each, in both bridges, and its device scan read-modify-writes any of the 32 for a QLogic ISP2100 Fibre Channel adapter: it clears bits 7:6 and sets bits 9:8 of that device's word. Bits 5:1 and bit 10 are cleared and bits 31:12, 11, 9:6 and 0 are kept. Then bit 10 is set unless the firmware setting coherentdma starts with n, and bits 13, 7, 6 and 1 are set on Lithium generation 5 or later unless the setting streambuffer starts with n. The setting names make bit 10 coherent DMA and the other four stream buffering (inferred from the names only). What bits 11, 8 and 5:2 do is unknown. The NT HAL never touches them.
 */
/* dma_ctl: rw32, space bridge, reset unknown */
#define LITHIUM_DMA_CTL_OFFSET                       0x60u /* inferred */
#define LITHIUM_DMA_CTL_COUNT                        32
#define LITHIUM_DMA_CTL_STRIDE                       4

/*
 * Configuration address for a type 1 cycle on the bridge's own bus and the buses behind it: bit 31 set, bus in 23:16, device in 15:11, function in 10:8, dword register in 7:2. Used by the HAL and, from the first instruction after reset, by the PROM boot block on bridge B. The PROM self-test checks, on bridge B only, that bits 23:2 can be set and cleared; it reads the old value first and restores it.
 */
/* cfg_addr: rw32, space bridge, reset unknown */
#define LITHIUM_CFG_ADDR_OFFSET                      0xf8u /* established */

/*
 * Configuration data. Accessed as a byte, halfword or word; the lane is picked by the low address bits (the boot block stores a byte at this offset plus the register's low two bits).
 */
/* cfg_data: rw32, space bridge, reset unknown */
#define LITHIUM_CFG_DATA_OFFSET                      0xfcu /* established */

/*
 * Word at physical 0xff01c004, in a one-page Lithium-side block that no driver touches. The PROM reads it (no HAL or driver read was found) and compares it with four values that decode as Unix times of 30 July, 10 September, 2 November and 7 December 1998 (0x35c0194c, 0x35f7357f, 0x363e4470, 0x366c3dfb) to pick the Cobalt I/O generation 2 to 5; a larger value gives 6, any other value gives -2, and bridge B's revision byte of zero gives 1 before the word is read. It also copies a table into the table window (constant TABLE_WINDOW_PHYS) unless the word is above 0x36ffd62f. The firmware prints it as the Serial I/O revision. A build stamp is a reading from the values, so the meaning is inferred; the reads are established (PROM 1.1005 and 1.0006, whole functions; see software/visws/boot-path.md). The block's other words are unknown, and so are its reset and write behaviour.
 */
/* build_stamp: r32, space stamp, reset unknown */
#define LITHIUM_BUILD_STAMP_OFFSET                   0x4u /* inferred */

#define LITHIUM_AUDIO_DMA_CHANNELS                   0x7u /* inferred */
#define LITHIUM_AUDIO_PAGE1                          0xff00f000u /* established */
#define LITHIUM_AUDIO_PAGE2                          0xff010000u /* established */
#define LITHIUM_AUDIO_PHYS                           0xff001000u /* established */
#define LITHIUM_BRIDGE_A_PCI_MEM_PHYS                0xf0000000u /* established */
#define LITHIUM_BRIDGE_B_PCI_MEM_PHYS                0xf4000000u /* established */
#define LITHIUM_DEVICE_ID                            0x1002u /* inferred */
#define LITHIUM_DMA_CHUNK                            0x20u /* inferred */
#define LITHIUM_PCI_A_PHYS                           0xfc000000u /* established */
#define LITHIUM_PCI_B_PHYS                           0xfd000000u /* established */
#define LITHIUM_PCI_MEM_BUS_BASE                     0x80000000u /* established */
#define LITHIUM_PCI_MEM_SIZE                         0x4000000u /* established */
#define LITHIUM_STAMP_PHYS                           0xff01c000u /* established */
#define LITHIUM_TABLE_WINDOW_PHYS                    0xff018000u /* established */
#define LITHIUM_VENDOR_ID                            0x10a9u /* inferred */

#endif /* LITHIUM_GEN_H */
