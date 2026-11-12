/* generated from defs/rad1.toml by defs-gen - do not edit, change the source */
/* SGI RAD digital audio ASIC (PCI 10a9:0005) register contract */
#ifndef RAD1_GEN_H
#define RAD1_GEN_H

#include <stdint.h>


/* enum channel_type */
#define RAD1_CHANNEL_TYPE_ANALOG_IN                  0 /* established */
#define RAD1_CHANNEL_TYPE_ANALOG_OUT                 1 /* established */
#define RAD1_CHANNEL_TYPE_AES_IN                     2 /* established */
#define RAD1_CHANNEL_TYPE_AES_OUT                    3 /* established */
#define RAD1_CHANNEL_TYPE_ADAT_IN                    4 /* established */
#define RAD1_CHANNEL_TYPE_ADAT_OUT                   5 /* established */
#define RAD1_CHANNEL_TYPE_AES_IN_SUBCODE             6 /* inferred */
#define RAD1_CHANNEL_TYPE_ADAT_IN_SUBCODE            7 /* inferred */

/* enum status_pointer_slot */
#define RAD1_STATUS_POINTER_SLOT_ADAT_IN             0 /* established */
#define RAD1_STATUS_POINTER_SLOT_AES_IN              8 /* established */
#define RAD1_STATUS_POINTER_SLOT_ANALOG_IN           16 /* established */
#define RAD1_STATUS_POINTER_SLOT_ADAT_IN_SUBCODE     24 /* established */
#define RAD1_STATUS_POINTER_SLOT_AES_IN_SUBCODE      32 /* established */
#define RAD1_STATUS_POINTER_SLOT_ADAT_OUT            40 /* established */
#define RAD1_STATUS_POINTER_SLOT_AES_OUT             48 /* established */
#define RAD1_STATUS_POINTER_SLOT_ANALOG_OUT          56 /* established */

/*
 * Sample-position register, ADAT input, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.
 */
/* pos_adat_in_a: r32, reset unknown */
#define RAD1_POS_ADAT_IN_A_OFFSET                    0x4u /* established */
#define RAD1_POS_ADAT_IN_A_FRAME_COUNT_SHIFT         18 /* established */
#define RAD1_POS_ADAT_IN_A_FRAME_COUNT_MASK          0x3fffu
#define RAD1_POS_ADAT_IN_A_FRAME_COUNT_INPLACE       (RAD1_POS_ADAT_IN_A_FRAME_COUNT_MASK << RAD1_POS_ADAT_IN_A_FRAME_COUNT_SHIFT)
#define RAD1_POS_ADAT_IN_A_UST_LATCH_SHIFT           0 /* inferred */
#define RAD1_POS_ADAT_IN_A_UST_LATCH_MASK            0x3ffffu
#define RAD1_POS_ADAT_IN_A_UST_LATCH_INPLACE         (RAD1_POS_ADAT_IN_A_UST_LATCH_MASK << RAD1_POS_ADAT_IN_A_UST_LATCH_SHIFT)

/*
 * Sample-position register, ADAT input, position B; also the ADAT-input subcode channel's position (read at shift 4). The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.
 */
/* pos_adat_in_b: r32, reset unknown */
#define RAD1_POS_ADAT_IN_B_OFFSET                    0x8u /* established */
#define RAD1_POS_ADAT_IN_B_FRAME_COUNT_SHIFT         18 /* established */
#define RAD1_POS_ADAT_IN_B_FRAME_COUNT_MASK          0x3fffu
#define RAD1_POS_ADAT_IN_B_FRAME_COUNT_INPLACE       (RAD1_POS_ADAT_IN_B_FRAME_COUNT_MASK << RAD1_POS_ADAT_IN_B_FRAME_COUNT_SHIFT)
#define RAD1_POS_ADAT_IN_B_UST_LATCH_SHIFT           0 /* inferred */
#define RAD1_POS_ADAT_IN_B_UST_LATCH_MASK            0x3ffffu
#define RAD1_POS_ADAT_IN_B_UST_LATCH_INPLACE         (RAD1_POS_ADAT_IN_B_UST_LATCH_MASK << RAD1_POS_ADAT_IN_B_UST_LATCH_SHIFT)

/*
 * Sample-position register, AES3 input, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.
 */
/* pos_aes_in_a: r32, reset unknown */
#define RAD1_POS_AES_IN_A_OFFSET                     0xcu /* established */
#define RAD1_POS_AES_IN_A_FRAME_COUNT_SHIFT          18 /* established */
#define RAD1_POS_AES_IN_A_FRAME_COUNT_MASK           0x3fffu
#define RAD1_POS_AES_IN_A_FRAME_COUNT_INPLACE        (RAD1_POS_AES_IN_A_FRAME_COUNT_MASK << RAD1_POS_AES_IN_A_FRAME_COUNT_SHIFT)
#define RAD1_POS_AES_IN_A_UST_LATCH_SHIFT            0 /* inferred */
#define RAD1_POS_AES_IN_A_UST_LATCH_MASK             0x3ffffu
#define RAD1_POS_AES_IN_A_UST_LATCH_INPLACE          (RAD1_POS_AES_IN_A_UST_LATCH_MASK << RAD1_POS_AES_IN_A_UST_LATCH_SHIFT)

/*
 * Sample-position register, AES3 input, position B; also the AES3-input subcode channel's position (read at shift 4). The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.
 */
/* pos_aes_in_b: r32, reset unknown */
#define RAD1_POS_AES_IN_B_OFFSET                     0x10u /* established */
#define RAD1_POS_AES_IN_B_FRAME_COUNT_SHIFT          18 /* established */
#define RAD1_POS_AES_IN_B_FRAME_COUNT_MASK           0x3fffu
#define RAD1_POS_AES_IN_B_FRAME_COUNT_INPLACE        (RAD1_POS_AES_IN_B_FRAME_COUNT_MASK << RAD1_POS_AES_IN_B_FRAME_COUNT_SHIFT)
#define RAD1_POS_AES_IN_B_UST_LATCH_SHIFT            0 /* inferred */
#define RAD1_POS_AES_IN_B_UST_LATCH_MASK             0x3ffffu
#define RAD1_POS_AES_IN_B_UST_LATCH_INPLACE          (RAD1_POS_AES_IN_B_UST_LATCH_MASK << RAD1_POS_AES_IN_B_UST_LATCH_SHIFT)

/*
 * Sample-position register, analog input, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.
 */
/* pos_analog_in_a: r32, reset unknown */
#define RAD1_POS_ANALOG_IN_A_OFFSET                  0x14u /* established */
#define RAD1_POS_ANALOG_IN_A_FRAME_COUNT_SHIFT       18 /* established */
#define RAD1_POS_ANALOG_IN_A_FRAME_COUNT_MASK        0x3fffu
#define RAD1_POS_ANALOG_IN_A_FRAME_COUNT_INPLACE     (RAD1_POS_ANALOG_IN_A_FRAME_COUNT_MASK << RAD1_POS_ANALOG_IN_A_FRAME_COUNT_SHIFT)
#define RAD1_POS_ANALOG_IN_A_UST_LATCH_SHIFT         0 /* inferred */
#define RAD1_POS_ANALOG_IN_A_UST_LATCH_MASK          0x3ffffu
#define RAD1_POS_ANALOG_IN_A_UST_LATCH_INPLACE       (RAD1_POS_ANALOG_IN_A_UST_LATCH_MASK << RAD1_POS_ANALOG_IN_A_UST_LATCH_SHIFT)

/*
 * Sample-position register, analog input position B in bits 31:18; the analog output reads bits 17:4 of this same register as its position B. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.
 */
/* pos_analog_b: r32, reset unknown */
#define RAD1_POS_ANALOG_B_OFFSET                     0x18u /* established */
#define RAD1_POS_ANALOG_B_FRAME_COUNT_SHIFT          18 /* established */
#define RAD1_POS_ANALOG_B_FRAME_COUNT_MASK           0x3fffu
#define RAD1_POS_ANALOG_B_FRAME_COUNT_INPLACE        (RAD1_POS_ANALOG_B_FRAME_COUNT_MASK << RAD1_POS_ANALOG_B_FRAME_COUNT_SHIFT)
#define RAD1_POS_ANALOG_B_UST_LATCH_SHIFT            0 /* inferred */
#define RAD1_POS_ANALOG_B_UST_LATCH_MASK             0x3ffffu
#define RAD1_POS_ANALOG_B_UST_LATCH_INPLACE          (RAD1_POS_ANALOG_B_UST_LATCH_MASK << RAD1_POS_ANALOG_B_UST_LATCH_SHIFT)

/*
 * Sample-position register, ADAT output, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.
 */
/* pos_adat_out_a: r32, reset unknown */
#define RAD1_POS_ADAT_OUT_A_OFFSET                   0x1cu /* established */
#define RAD1_POS_ADAT_OUT_A_FRAME_COUNT_SHIFT        18 /* established */
#define RAD1_POS_ADAT_OUT_A_FRAME_COUNT_MASK         0x3fffu
#define RAD1_POS_ADAT_OUT_A_FRAME_COUNT_INPLACE      (RAD1_POS_ADAT_OUT_A_FRAME_COUNT_MASK << RAD1_POS_ADAT_OUT_A_FRAME_COUNT_SHIFT)
#define RAD1_POS_ADAT_OUT_A_UST_LATCH_SHIFT          0 /* inferred */
#define RAD1_POS_ADAT_OUT_A_UST_LATCH_MASK           0x3ffffu
#define RAD1_POS_ADAT_OUT_A_UST_LATCH_INPLACE        (RAD1_POS_ADAT_OUT_A_UST_LATCH_MASK << RAD1_POS_ADAT_OUT_A_UST_LATCH_SHIFT)

/*
 * Sample-position register, ADAT output, position B. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.
 */
/* pos_adat_out_b: r32, reset unknown */
#define RAD1_POS_ADAT_OUT_B_OFFSET                   0x20u /* established */
#define RAD1_POS_ADAT_OUT_B_FRAME_COUNT_SHIFT        18 /* established */
#define RAD1_POS_ADAT_OUT_B_FRAME_COUNT_MASK         0x3fffu
#define RAD1_POS_ADAT_OUT_B_FRAME_COUNT_INPLACE      (RAD1_POS_ADAT_OUT_B_FRAME_COUNT_MASK << RAD1_POS_ADAT_OUT_B_FRAME_COUNT_SHIFT)
#define RAD1_POS_ADAT_OUT_B_UST_LATCH_SHIFT          0 /* inferred */
#define RAD1_POS_ADAT_OUT_B_UST_LATCH_MASK           0x3ffffu
#define RAD1_POS_ADAT_OUT_B_UST_LATCH_INPLACE        (RAD1_POS_ADAT_OUT_B_UST_LATCH_MASK << RAD1_POS_ADAT_OUT_B_UST_LATCH_SHIFT)

/*
 * Sample-position register, AES3 output, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.
 */
/* pos_aes_out_a: r32, reset unknown */
#define RAD1_POS_AES_OUT_A_OFFSET                    0x24u /* established */
#define RAD1_POS_AES_OUT_A_FRAME_COUNT_SHIFT         18 /* established */
#define RAD1_POS_AES_OUT_A_FRAME_COUNT_MASK          0x3fffu
#define RAD1_POS_AES_OUT_A_FRAME_COUNT_INPLACE       (RAD1_POS_AES_OUT_A_FRAME_COUNT_MASK << RAD1_POS_AES_OUT_A_FRAME_COUNT_SHIFT)
#define RAD1_POS_AES_OUT_A_UST_LATCH_SHIFT           0 /* inferred */
#define RAD1_POS_AES_OUT_A_UST_LATCH_MASK            0x3ffffu
#define RAD1_POS_AES_OUT_A_UST_LATCH_INPLACE         (RAD1_POS_AES_OUT_A_UST_LATCH_MASK << RAD1_POS_AES_OUT_A_UST_LATCH_SHIFT)

/*
 * Sample-position register, AES3 output, position B. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.
 */
/* pos_aes_out_b: r32, reset unknown */
#define RAD1_POS_AES_OUT_B_OFFSET                    0x28u /* established */
#define RAD1_POS_AES_OUT_B_FRAME_COUNT_SHIFT         18 /* established */
#define RAD1_POS_AES_OUT_B_FRAME_COUNT_MASK          0x3fffu
#define RAD1_POS_AES_OUT_B_FRAME_COUNT_INPLACE       (RAD1_POS_AES_OUT_B_FRAME_COUNT_MASK << RAD1_POS_AES_OUT_B_FRAME_COUNT_SHIFT)
#define RAD1_POS_AES_OUT_B_UST_LATCH_SHIFT           0 /* inferred */
#define RAD1_POS_AES_OUT_B_UST_LATCH_MASK            0x3ffffu
#define RAD1_POS_AES_OUT_B_UST_LATCH_INPLACE         (RAD1_POS_AES_OUT_B_UST_LATCH_MASK << RAD1_POS_AES_OUT_B_UST_LATCH_SHIFT)

/*
 * Sample-position register, analog output, position A. The upper 14 bits count frames and advance only while the channel's DMA runs. A copy sits in the status slot at offset + 0x40. Channel roles follow the shipped driver's per-channel tables; the table entries are established, the role names inferred from the direction flags and interface objects.
 */
/* pos_analog_out_a: r32, reset unknown */
#define RAD1_POS_ANALOG_OUT_A_OFFSET                 0x2cu /* established */
#define RAD1_POS_ANALOG_OUT_A_FRAME_COUNT_SHIFT      18 /* established */
#define RAD1_POS_ANALOG_OUT_A_FRAME_COUNT_MASK       0x3fffu
#define RAD1_POS_ANALOG_OUT_A_FRAME_COUNT_INPLACE    (RAD1_POS_ANALOG_OUT_A_FRAME_COUNT_MASK << RAD1_POS_ANALOG_OUT_A_FRAME_COUNT_SHIFT)
#define RAD1_POS_ANALOG_OUT_A_UST_LATCH_SHIFT        0 /* inferred */
#define RAD1_POS_ANALOG_OUT_A_UST_LATCH_MASK         0x3ffffu
#define RAD1_POS_ANALOG_OUT_A_UST_LATCH_INPLACE      (RAD1_POS_ANALOG_OUT_A_UST_LATCH_MASK << RAD1_POS_ANALOG_OUT_A_UST_LATCH_SHIFT)

/*
 * Free-running counter that the driver reads for timestamps and a liveness check: two reads 10 microseconds apart must differ by at least 3. No write to it exists. The tick period is inferred to be about 1 microsecond (the driver scales by 800 or 960 ns); the reset routine that runs on the PCI audio board stores 960 ns (UST_TICK_NS_FIXED) or a period computed from the Bedrock register, and the choice is unknown. Reset value, wrap, and read side effects are unknown. On board mode 7 it runs from reset with no enable write.
 */
/* ust_counter: r32, reset unknown */
#define RAD1_UST_COUNTER_OFFSET                      0x30u /* established */
#define RAD1_UST_COUNTER_COUNT_SHIFT                 0 /* inferred */
#define RAD1_UST_COUNTER_COUNT_MASK                  0xffffffffu
#define RAD1_UST_COUNTER_COUNT_INPLACE               (RAD1_UST_COUNTER_COUNT_MASK << RAD1_UST_COUNTER_COUNT_SHIFT)

/*
 * Receiver and video-reference status. The driver reads it only through the status slot copy. The bits are undecoded; use is established, meaning inferred.
 */
/* sync_status: r32, reset unknown */
#define RAD1_SYNC_STATUS_OFFSET                      0x34u /* inferred */

/*
 * Controls the counter on the Octane board. The bit meanings, whether the writes are pulses, and whether the counter resets are unknown. On the PCI audio board (mode 13) the reset routine writes 6 then 2 when the Bedrock flag is set or the brick type is 55, 56, 57, 69 or 81, and 4 then 0 otherwise (see docs/rad1.md).
 */
/* ust_control: w32, reset unknown */
#define RAD1_UST_CONTROL_OFFSET                      0x40u /* inferred */

/*
 * ADAT input channel control. Start value 0xa0000008 is written unconditionally; the other bits are undecoded. The shadow word is written whole; the driver clears the enable at subsystem start.
 */
/* adat_in_ctrl: rw32, reset unknown */
#define RAD1_ADAT_IN_CTRL_OFFSET                     0x44u /* established */
#define RAD1_ADAT_IN_CTRL_SUBCODE_ENABLE_SHIFT       2 /* established */
#define RAD1_ADAT_IN_CTRL_SUBCODE_ENABLE_MASK        0x1u
#define RAD1_ADAT_IN_CTRL_SUBCODE_ENABLE_INPLACE     (RAD1_ADAT_IN_CTRL_SUBCODE_ENABLE_MASK << RAD1_ADAT_IN_CTRL_SUBCODE_ENABLE_SHIFT)
#define RAD1_ADAT_IN_CTRL_ENABLE_SHIFT               0 /* established */
#define RAD1_ADAT_IN_CTRL_ENABLE_MASK                0x1u
#define RAD1_ADAT_IN_CTRL_ENABLE_INPLACE             (RAD1_ADAT_IN_CTRL_ENABLE_MASK << RAD1_ADAT_IN_CTRL_ENABLE_SHIFT)

/*
 * AES3 input channel control. Start value 0x10. The shadow word is written whole; the driver clears the enable at subsystem start.
 */
/* aes_in_ctrl: rw32, reset unknown */
#define RAD1_AES_IN_CTRL_OFFSET                      0x48u /* established */
#define RAD1_AES_IN_CTRL_SUBCODE_ENABLE_SHIFT        2 /* established */
#define RAD1_AES_IN_CTRL_SUBCODE_ENABLE_MASK         0x1u
#define RAD1_AES_IN_CTRL_SUBCODE_ENABLE_INPLACE      (RAD1_AES_IN_CTRL_SUBCODE_ENABLE_MASK << RAD1_AES_IN_CTRL_SUBCODE_ENABLE_SHIFT)
#define RAD1_AES_IN_CTRL_ENABLE_SHIFT                0 /* established */
#define RAD1_AES_IN_CTRL_ENABLE_MASK                 0x1u
#define RAD1_AES_IN_CTRL_ENABLE_INPLACE              (RAD1_AES_IN_CTRL_ENABLE_MASK << RAD1_AES_IN_CTRL_ENABLE_SHIFT)

/*
 * Analog input channel control. Start value is 0x03000000 on board mode 12 and 0x05000000 on modes 7 and 13. On mode 7 bit 27 is also the serial clock of the video-clock mux interface: the driver clears it and sets it once per shifted bit, preserving the enable bit.
 */
/* analog_in_ctrl: rw32, reset unknown */
#define RAD1_ANALOG_IN_CTRL_OFFSET                   0x4cu /* established */
#define RAD1_ANALOG_IN_CTRL_MUX_CLOCK_SHIFT          27 /* established */
#define RAD1_ANALOG_IN_CTRL_MUX_CLOCK_MASK           0x1u
#define RAD1_ANALOG_IN_CTRL_MUX_CLOCK_INPLACE        (RAD1_ANALOG_IN_CTRL_MUX_CLOCK_MASK << RAD1_ANALOG_IN_CTRL_MUX_CLOCK_SHIFT)
#define RAD1_ANALOG_IN_CTRL_ENABLE_SHIFT             0 /* established */
#define RAD1_ANALOG_IN_CTRL_ENABLE_MASK              0x1u
#define RAD1_ANALOG_IN_CTRL_ENABLE_INPLACE           (RAD1_ANALOG_IN_CTRL_ENABLE_MASK << RAD1_ANALOG_IN_CTRL_ENABLE_SHIFT)

/*
 * ADAT output channel control. Start value 0x60000000 on modes 7 and 12; on mode 13 the reading above leaves the earlier value unknown, but a second reading of the shipped drivers finds 0x20000000 written there (see docs/rad1.md, Not settled). The shadow word is written whole; the driver clears the enable at subsystem start.
 */
/* adat_out_ctrl: rw32, reset unknown */
#define RAD1_ADAT_OUT_CTRL_OFFSET                    0x50u /* established */
#define RAD1_ADAT_OUT_CTRL_ENABLE_SHIFT              0 /* established */
#define RAD1_ADAT_OUT_CTRL_ENABLE_MASK               0x1u
#define RAD1_ADAT_OUT_CTRL_ENABLE_INPLACE            (RAD1_ADAT_OUT_CTRL_ENABLE_MASK << RAD1_ADAT_OUT_CTRL_ENABLE_SHIFT)

/*
 * AES3 output channel control. Start value 0x40000000 on modes 7 and 12 and 0 on mode 13. The driver sets bits 2 and 3 as output metadata flags without starting audio. Linux pairs 0x40000000 with clock generator 2. The shadow word is written whole; the driver clears the enable at subsystem start.
 */
/* aes_out_ctrl: rw32, reset unknown */
#define RAD1_AES_OUT_CTRL_OFFSET                     0x54u /* established */
#define RAD1_AES_OUT_CTRL_METADATA_FLAGS_SHIFT       2 /* inferred */
#define RAD1_AES_OUT_CTRL_METADATA_FLAGS_MASK        0x3u
#define RAD1_AES_OUT_CTRL_METADATA_FLAGS_INPLACE     (RAD1_AES_OUT_CTRL_METADATA_FLAGS_MASK << RAD1_AES_OUT_CTRL_METADATA_FLAGS_SHIFT)
#define RAD1_AES_OUT_CTRL_ENABLE_SHIFT               0 /* established */
#define RAD1_AES_OUT_CTRL_ENABLE_MASK                0x1u
#define RAD1_AES_OUT_CTRL_ENABLE_INPLACE             (RAD1_AES_OUT_CTRL_ENABLE_MASK << RAD1_AES_OUT_CTRL_ENABLE_SHIFT)

/*
 * Analog output channel control. Idle value 0x20000000, running 0x20000001. Software treats bit 0 as the start and the Octane PROM as busy: it waits for the bit to read clear after a one-shot transfer, so hardware clears it when the last descriptor ends. A stop routine reads the register back twice after clearing the enable.
 */
/* analog_out_ctrl: rw32, reset unknown */
#define RAD1_ANALOG_OUT_CTRL_OFFSET                  0x58u /* established */
#define RAD1_ANALOG_OUT_CTRL_CLOCK_GEN2_SHIFT        30 /* inferred */
#define RAD1_ANALOG_OUT_CTRL_CLOCK_GEN2_MASK         0x1u
#define RAD1_ANALOG_OUT_CTRL_CLOCK_GEN2_INPLACE      (RAD1_ANALOG_OUT_CTRL_CLOCK_GEN2_MASK << RAD1_ANALOG_OUT_CTRL_CLOCK_GEN2_SHIFT)
#define RAD1_ANALOG_OUT_CTRL_CLOCK_GEN1_SHIFT        29 /* inferred */
#define RAD1_ANALOG_OUT_CTRL_CLOCK_GEN1_MASK         0x1u
#define RAD1_ANALOG_OUT_CTRL_CLOCK_GEN1_INPLACE      (RAD1_ANALOG_OUT_CTRL_CLOCK_GEN1_MASK << RAD1_ANALOG_OUT_CTRL_CLOCK_GEN1_SHIFT)
#define RAD1_ANALOG_OUT_CTRL_LINE_MUX_SHIFT          25 /* unknown */
#define RAD1_ANALOG_OUT_CTRL_LINE_MUX_MASK           0x1u
#define RAD1_ANALOG_OUT_CTRL_LINE_MUX_INPLACE        (RAD1_ANALOG_OUT_CTRL_LINE_MUX_MASK << RAD1_ANALOG_OUT_CTRL_LINE_MUX_SHIFT)
#define RAD1_ANALOG_OUT_CTRL_ENABLE_SHIFT            0 /* established */
#define RAD1_ANALOG_OUT_CTRL_ENABLE_MASK             0x1u
#define RAD1_ANALOG_OUT_CTRL_ENABLE_INPLACE          (RAD1_ANALOG_OUT_CTRL_ENABLE_MASK << RAD1_ANALOG_OUT_CTRL_ENABLE_SHIFT)

/*
 * Starts and stops the status ring. One shot is 0x40001, continuous is the interval field plus 0x40003, stop is 0x1fffc. Bit meanings beyond the grade of each field are undecoded.
 */
/* status_ctrl: w32, reset unknown */
#define RAD1_STATUS_CTRL_OFFSET                      0x5cu /* established */
#define RAD1_STATUS_CTRL_GO_SHIFT                    18 /* unknown */
#define RAD1_STATUS_CTRL_GO_MASK                     0x1u
#define RAD1_STATUS_CTRL_GO_INPLACE                  (RAD1_STATUS_CTRL_GO_MASK << RAD1_STATUS_CTRL_GO_SHIFT)
#define RAD1_STATUS_CTRL_INTERVAL_SHIFT              2 /* inferred */
#define RAD1_STATUS_CTRL_INTERVAL_MASK               0x7fffu
#define RAD1_STATUS_CTRL_INTERVAL_INPLACE            (RAD1_STATUS_CTRL_INTERVAL_MASK << RAD1_STATUS_CTRL_INTERVAL_SHIFT)
#define RAD1_STATUS_CTRL_CONTINUOUS_SHIFT            1 /* inferred */
#define RAD1_STATUS_CTRL_CONTINUOUS_MASK             0x1u
#define RAD1_STATUS_CTRL_CONTINUOUS_INPLACE          (RAD1_STATUS_CTRL_CONTINUOUS_MASK << RAD1_STATUS_CTRL_CONTINUOUS_SHIFT)
#define RAD1_STATUS_CTRL_START_SHIFT                 0 /* inferred */
#define RAD1_STATUS_CTRL_START_MASK                  0x1u
#define RAD1_STATUS_CTRL_START_INPLACE               (RAD1_STATUS_CTRL_START_MASK << RAD1_STATUS_CTRL_START_SHIFT)

/*
 * Output control shadow. Bring-up value 0x1500; halt ORs bit 8. A vendor PROM writes 0x480. Write-and-shadow: the drivers never read it back.
 */
/* output_misc: w32, reset unknown */
#define RAD1_OUTPUT_MISC_OFFSET                      0x70u /* inferred */
#define RAD1_OUTPUT_MISC_MUTE_SHIFT                  8 /* inferred */
#define RAD1_OUTPUT_MISC_MUTE_MASK                   0x1u
#define RAD1_OUTPUT_MISC_MUTE_INPLACE                (RAD1_OUTPUT_MISC_MUTE_MASK << RAD1_OUTPUT_MISC_MUTE_SHIFT)
#define RAD1_OUTPUT_MISC_SUBCODE_ENABLE_SHIFT        6 /* inferred */
#define RAD1_OUTPUT_MISC_SUBCODE_ENABLE_MASK         0x1u
#define RAD1_OUTPUT_MISC_SUBCODE_ENABLE_INPLACE      (RAD1_OUTPUT_MISC_SUBCODE_ENABLE_MASK << RAD1_OUTPUT_MISC_SUBCODE_ENABLE_SHIFT)

/*
 * Written 0x08000010 once at start on every board mode. Purpose unknown.
 */
/* config_74: w32, reset unknown */
#define RAD1_CONFIG_74_OFFSET                        0x74u /* unknown */

/*
 * Written 0x00fac688 once at start on every board mode. Purpose unknown.
 */
/* config_78: w32, reset unknown */
#define RAD1_CONFIG_78_OFFSET                        0x78u /* unknown */

/*
 * On analog-capable boards: four gain bytes, each the driver's dB value plus 0x48, with 0 meaning mute; the whole shadow is written on each change. Start value 0xd6d6d6d6. On the PCI board (mode 13) the register instead carries the video-clock mux word.
 */
/* gain: w32, reset unknown */
#define RAD1_GAIN_OFFSET                             0x7cu /* established */
#define RAD1_GAIN_OUT_RIGHT_SHIFT                    24 /* established */
#define RAD1_GAIN_OUT_RIGHT_MASK                     0xffu
#define RAD1_GAIN_OUT_RIGHT_INPLACE                  (RAD1_GAIN_OUT_RIGHT_MASK << RAD1_GAIN_OUT_RIGHT_SHIFT)
#define RAD1_GAIN_OUT_LEFT_SHIFT                     16 /* established */
#define RAD1_GAIN_OUT_LEFT_MASK                      0xffu
#define RAD1_GAIN_OUT_LEFT_INPLACE                   (RAD1_GAIN_OUT_LEFT_MASK << RAD1_GAIN_OUT_LEFT_SHIFT)
#define RAD1_GAIN_IN_RIGHT_SHIFT                     8 /* established */
#define RAD1_GAIN_IN_RIGHT_MASK                      0xffu
#define RAD1_GAIN_IN_RIGHT_INPLACE                   (RAD1_GAIN_IN_RIGHT_MASK << RAD1_GAIN_IN_RIGHT_SHIFT)
#define RAD1_GAIN_IN_LEFT_SHIFT                      0 /* established */
#define RAD1_GAIN_IN_LEFT_MASK                       0xffu
#define RAD1_GAIN_IN_LEFT_INPLACE                    (RAD1_GAIN_IN_LEFT_MASK << RAD1_GAIN_IN_LEFT_SHIFT)

/*
 * Block reset and receiver control, written whole from a shadow. At start the driver writes 0xffffffff, 0xffe3cffe, 0xffe3c0fe, 0xffe24070, then 0xffe20000, with 1 ms delays in between, so a set bit is read as holding a block in reset. Linux brackets each clock-generator load with 0xffe20000 | (0x100 << n) before and 0xffe20000 after. Whole-register meaning is inferred; the bits below are the ones the drivers name by use.
 */
/* central_ctrl: w32, reset unknown */
#define RAD1_CENTRAL_CTRL_OFFSET                     0x80u /* inferred */
#define RAD1_CENTRAL_CTRL_ANALOG_OUT_IF_RESET_SHIFT  14 /* inferred */
#define RAD1_CENTRAL_CTRL_ANALOG_OUT_IF_RESET_MASK   0x1u
#define RAD1_CENTRAL_CTRL_ANALOG_OUT_IF_RESET_INPLACE (RAD1_CENTRAL_CTRL_ANALOG_OUT_IF_RESET_MASK << RAD1_CENTRAL_CTRL_ANALOG_OUT_IF_RESET_SHIFT)
#define RAD1_CENTRAL_CTRL_CLOCKGEN_RESET_SHIFT       8 /* inferred */
#define RAD1_CENTRAL_CTRL_CLOCKGEN_RESET_MASK        0xfu
#define RAD1_CENTRAL_CTRL_CLOCKGEN_RESET_INPLACE     (RAD1_CENTRAL_CTRL_CLOCKGEN_RESET_MASK << RAD1_CENTRAL_CTRL_CLOCKGEN_RESET_SHIFT)
#define RAD1_CENTRAL_CTRL_ADAT_RX_RESYNC_SHIFT       7 /* inferred */
#define RAD1_CENTRAL_CTRL_ADAT_RX_RESYNC_MASK        0x1u
#define RAD1_CENTRAL_CTRL_ADAT_RX_RESYNC_INPLACE     (RAD1_CENTRAL_CTRL_ADAT_RX_RESYNC_MASK << RAD1_CENTRAL_CTRL_ADAT_RX_RESYNC_SHIFT)
#define RAD1_CENTRAL_CTRL_ADAT_RX_ENABLE_SHIFT       6 /* inferred */
#define RAD1_CENTRAL_CTRL_ADAT_RX_ENABLE_MASK        0x1u
#define RAD1_CENTRAL_CTRL_ADAT_RX_ENABLE_INPLACE     (RAD1_CENTRAL_CTRL_ADAT_RX_ENABLE_MASK << RAD1_CENTRAL_CTRL_ADAT_RX_ENABLE_SHIFT)

/*
 * Written 0 at start on board modes 7 and 13; skipped on mode 12. Purpose unknown.
 */
/* mode_84: w32, reset unknown */
#define RAD1_MODE_84_OFFSET                          0x84u /* unknown */

/*
 * General-purpose output 1. On the Octane board a vendor PROM treats it as the analog-output relay: 3 releases the mute and 2 applies it; halt writes 2 then 0. On the MediaIO card the mux routine writes 2 then 3 after its 16 shifted bits, which latches the word into the clock-selection logic (the latch strobe; effect inferred). It has no effect on any DMA channel as far as the sources show. On the PCI audio board (mode 13) a second reading of the shipped drivers finds 0 written here at start, which the reading above does not cover.
 */
/* gpio_relay: w32, reset unknown */
#define RAD1_GPIO_RELAY_OFFSET                       0x88u /* inferred */
#define RAD1_GPIO_RELAY_BIT1_SHIFT                   1 /* inferred */
#define RAD1_GPIO_RELAY_BIT1_MASK                    0x1u
#define RAD1_GPIO_RELAY_BIT1_INPLACE                 (RAD1_GPIO_RELAY_BIT1_MASK << RAD1_GPIO_RELAY_BIT1_SHIFT)
#define RAD1_GPIO_RELAY_BIT0_SHIFT                   0 /* inferred */
#define RAD1_GPIO_RELAY_BIT0_MASK                    0x1u
#define RAD1_GPIO_RELAY_BIT0_INPLACE                 (RAD1_GPIO_RELAY_BIT0_MASK << RAD1_GPIO_RELAY_BIT0_SHIFT)

/*
 * General-purpose output 2. On the MediaIO card (mode 7) it is the serial data line of the 16-bit video-clock mux: for each of 16 bits, most significant first, the driver writes (bit | 2), then drops and raises the clock on the analog input control register (bit 27), and after all 16 bits writes 2 then 3 to gpio_relay as the latch strobe and restores this register from a shadow. Separately every 1024 status passes (about 1.024 s) the driver rewrites it as (selector | 2), flipping the selector between 0 and 1, which is the 3, 2, 3, 2 pattern seen on the bus: the selector alternates 0 and 1 between writes, bit 1 stays set, and the driver samples bit 10 of the register 0x34 mirror in the status slot between writes (what that probes is unknown). On the Octane board a vendor PROM uses it as the DAC mute: 3 mutes and 2 unmutes, and the unmute also writes 0x03000000 to the analog input control. On the PCI audio board (mode 13) a second reading of the shipped drivers finds 0 written here at start.
 */
/* gpio_data: w32, reset unknown */
#define RAD1_GPIO_DATA_OFFSET                        0x8cu /* inferred */
#define RAD1_GPIO_DATA_CONST1_SHIFT                  1 /* inferred */
#define RAD1_GPIO_DATA_CONST1_MASK                   0x1u
#define RAD1_GPIO_DATA_CONST1_INPLACE                (RAD1_GPIO_DATA_CONST1_MASK << RAD1_GPIO_DATA_CONST1_SHIFT)
#define RAD1_GPIO_DATA_DATA_SHIFT                    0 /* inferred */
#define RAD1_GPIO_DATA_DATA_MASK                     0x1u
#define RAD1_GPIO_DATA_DATA_INPLACE                  (RAD1_GPIO_DATA_DATA_MASK << RAD1_GPIO_DATA_DATA_SHIFT)

/*
 * Analog-output level or mode. Written 2 on board modes 7 and 12, 0 on mode 13, and 2 or 3 when the output's interface parameter selects it. What the settings select is unknown.
 */
/* analog_out_mode: w32, reset unknown */
#define RAD1_ANALOG_OUT_MODE_OFFSET                  0x90u /* established */

/*
 * Loads one clock generator: set select bit 28 + n and the integer divisor minus one in the low bits. Rate = master / (divisor + remainder / denominator), with the remainder in clockgen_frac. A 64-bit store to this offset appears in one setup path. Bring-up value 0x02000001 loads no generator (bit 25 is set in such words; meaning unknown). Linux writes flag bits 10:9 as 0x600 or 0x200 and the Octane PROM 0x400; their effect is unknown.
 */
/* clockgen_load: w32, reset unknown */
#define RAD1_CLOCKGEN_LOAD_OFFSET                    0xa0u /* established */
#define RAD1_CLOCKGEN_LOAD_SELECT_SHIFT              28 /* established */
#define RAD1_CLOCKGEN_LOAD_SELECT_MASK               0xfu
#define RAD1_CLOCKGEN_LOAD_SELECT_INPLACE            (RAD1_CLOCKGEN_LOAD_SELECT_MASK << RAD1_CLOCKGEN_LOAD_SELECT_SHIFT)
#define RAD1_CLOCKGEN_LOAD_FLAGS_SHIFT               9 /* unknown */
#define RAD1_CLOCKGEN_LOAD_FLAGS_MASK                0x3u
#define RAD1_CLOCKGEN_LOAD_FLAGS_INPLACE             (RAD1_CLOCKGEN_LOAD_FLAGS_MASK << RAD1_CLOCKGEN_LOAD_FLAGS_SHIFT)
#define RAD1_CLOCKGEN_LOAD_DIVISOR_MINUS_1_SHIFT     0 /* inferred */
#define RAD1_CLOCKGEN_LOAD_DIVISOR_MINUS_1_MASK      0x1ffu
#define RAD1_CLOCKGEN_LOAD_DIVISOR_MINUS_1_INPLACE   (RAD1_CLOCKGEN_LOAD_DIVISOR_MINUS_1_MASK << RAD1_CLOCKGEN_LOAD_DIVISOR_MINUS_1_SHIFT)

/*
 * Fractional part of the clock divisor: the remainder in bits 31:16 and 0x10000 minus the denominator in bits 15:0.
 */
/* clockgen_frac: w32, reset unknown */
#define RAD1_CLOCKGEN_FRAC_OFFSET                    0xa4u /* established */
#define RAD1_CLOCKGEN_FRAC_REMAINDER_SHIFT           16 /* established */
#define RAD1_CLOCKGEN_FRAC_REMAINDER_MASK            0xffffu
#define RAD1_CLOCKGEN_FRAC_REMAINDER_INPLACE         (RAD1_CLOCKGEN_FRAC_REMAINDER_MASK << RAD1_CLOCKGEN_FRAC_REMAINDER_SHIFT)
#define RAD1_CLOCKGEN_FRAC_DENOMINATOR_COMPLEMENT_SHIFT 0 /* established */
#define RAD1_CLOCKGEN_FRAC_DENOMINATOR_COMPLEMENT_MASK 0xffffu
#define RAD1_CLOCKGEN_FRAC_DENOMINATOR_COMPLEMENT_INPLACE (RAD1_CLOCKGEN_FRAC_DENOMINATOR_COMPLEMENT_MASK << RAD1_CLOCKGEN_FRAC_DENOMINATOR_COMPLEMENT_SHIFT)

/*
 * Master clock select of clock generator 3, at 0xb4 - 4 * n. Bit 0 selects the 192 kHz master when set and 176.4 kHz when clear. Higher bits are unknown. The shipped drivers' writes to this offset were not read directly; the layout is from the public driver.
 */
/* clockgen_master_3: w32, reset unknown; public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_set_cg */
#define RAD1_CLOCKGEN_MASTER_3_OFFSET                0xa8u /* inferred */
#define RAD1_CLOCKGEN_MASTER_3_MASTER_192K_SHIFT     0 /* inferred */
#define RAD1_CLOCKGEN_MASTER_3_MASTER_192K_MASK      0x1u
#define RAD1_CLOCKGEN_MASTER_3_MASTER_192K_INPLACE   (RAD1_CLOCKGEN_MASTER_3_MASTER_192K_MASK << RAD1_CLOCKGEN_MASTER_3_MASTER_192K_SHIFT)

/*
 * Master clock select of clock generator 2, at 0xb4 - 4 * n. Bit 0 selects the 192 kHz master when set and 176.4 kHz when clear. Higher bits are unknown. The shipped drivers' writes to this offset were not read directly; the layout is from the public driver.
 */
/* clockgen_master_2: w32, reset unknown; public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_set_cg */
#define RAD1_CLOCKGEN_MASTER_2_OFFSET                0xacu /* inferred */
#define RAD1_CLOCKGEN_MASTER_2_MASTER_192K_SHIFT     0 /* inferred */
#define RAD1_CLOCKGEN_MASTER_2_MASTER_192K_MASK      0x1u
#define RAD1_CLOCKGEN_MASTER_2_MASTER_192K_INPLACE   (RAD1_CLOCKGEN_MASTER_2_MASTER_192K_MASK << RAD1_CLOCKGEN_MASTER_2_MASTER_192K_SHIFT)

/*
 * Master clock select of clock generator 1, at 0xb4 - 4 * n. Bit 0 selects the 192 kHz master when set and 176.4 kHz when clear. Higher bits are unknown. The shipped drivers' writes to this offset were not read directly; the layout is from the public driver.
 */
/* clockgen_master_1: w32, reset unknown; public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_set_cg */
#define RAD1_CLOCKGEN_MASTER_1_OFFSET                0xb0u /* inferred */
#define RAD1_CLOCKGEN_MASTER_1_MASTER_192K_SHIFT     0 /* inferred */
#define RAD1_CLOCKGEN_MASTER_1_MASTER_192K_MASK      0x1u
#define RAD1_CLOCKGEN_MASTER_1_MASTER_192K_INPLACE   (RAD1_CLOCKGEN_MASTER_1_MASTER_192K_MASK << RAD1_CLOCKGEN_MASTER_1_MASTER_192K_SHIFT)

/*
 * Master clock select of clock generator 0, at 0xb4 - 4 * n. Bit 0 selects the 192 kHz master when set and 176.4 kHz when clear. Higher bits are unknown. The shipped drivers' writes to this offset were not read directly; the layout is from the public driver.
 */
/* clockgen_master_0: w32, reset unknown; public Linux RAD1 driver (linux-mips posting, 2008-07-31) snd_rad1_set_cg */
#define RAD1_CLOCKGEN_MASTER_0_OFFSET                0xb4u /* inferred */
#define RAD1_CLOCKGEN_MASTER_0_MASTER_192K_SHIFT     0 /* inferred */
#define RAD1_CLOCKGEN_MASTER_0_MASTER_192K_MASK      0x1u
#define RAD1_CLOCKGEN_MASTER_0_MASTER_192K_INPLACE   (RAD1_CLOCKGEN_MASTER_0_MASTER_192K_MASK << RAD1_CLOCKGEN_MASTER_0_MASTER_192K_SHIFT)

/*
 * Written once at start on every board mode with a 32-bit mask of all ones except bits 30 and 29. Purpose unknown.
 */
/* config_b8: w32, reset unknown */
#define RAD1_CONFIG_B8_OFFSET                        0xb8u /* unknown */

/*
 * Written with the same all-ones-but-bits-30:29 mask as config_b8, immediately after it. Purpose unknown.
 */
/* config_bc: w32, reset unknown */
#define RAD1_CONFIG_BC_OFFSET                        0xbcu /* unknown */

/*
 * Descriptor RAM, low 32 bits of the buffer's PCI address of each entry; 16 entries of 12 bytes from 0x400 (lowest address, highest address, control). Entry n of data channel type n holds the descriptor the channel's working registers link to for the next lap; the status ring's descriptor is inferred to be entry 15. Whether the RAM is shared by every channel's engine, and what a write to a live entry does, are unknown: no shipped software does it.
 */
/* desc_lo: rw32, reset unknown */
#define RAD1_DESC_LO_OFFSET                          0x400u /* established */
#define RAD1_DESC_LO_COUNT                           16
#define RAD1_DESC_LO_STRIDE                          12

/*
 * Descriptor RAM, high 32 bits of the buffer's PCI address of each entry; 16 entries of 12 bytes from 0x400 (lowest address, highest address, control). Entry n of data channel type n holds the descriptor the channel's working registers link to for the next lap; the status ring's descriptor is inferred to be entry 15. Whether the RAM is shared by every channel's engine, and what a write to a live entry does, are unknown: no shipped software does it.
 */
/* desc_hi: rw32, reset unknown */
#define RAD1_DESC_HI_OFFSET                          0x404u /* established */
#define RAD1_DESC_HI_COUNT                           16
#define RAD1_DESC_HI_STRIDE                          12

/*
 * Descriptor RAM, control word, see DESC_WORD of each entry; 16 entries of 12 bytes from 0x400 (lowest address, highest address, control). Entry n of data channel type n holds the descriptor the channel's working registers link to for the next lap; the status ring's descriptor is inferred to be entry 15. Whether the RAM is shared by every channel's engine, and what a write to a live entry does, are unknown: no shipped software does it.
 */
/* desc_ctrl: rw32, reset unknown */
#define RAD1_DESC_CTRL_OFFSET                        0x408u /* established */
#define RAD1_DESC_CTRL_COUNT                         16
#define RAD1_DESC_CTRL_STRIDE                        12

/*
 * Working descriptor of channel type 4 (adat_in), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.
 */
/* work_adat_in_lo: rw32, reset unknown */
#define RAD1_WORK_ADAT_IN_LO_OFFSET                  0x4c0u /* established */

/*
 * Working descriptor of channel type 4 (adat_in), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.
 */
/* work_adat_in_ctrl: rw32, reset unknown */
#define RAD1_WORK_ADAT_IN_CTRL_OFFSET                0x4c4u /* established */

/*
 * Working descriptor of channel type 2 (aes_in), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.
 */
/* work_aes_in_lo: rw32, reset unknown */
#define RAD1_WORK_AES_IN_LO_OFFSET                   0x4c8u /* established */

/*
 * Working descriptor of channel type 2 (aes_in), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.
 */
/* work_aes_in_ctrl: rw32, reset unknown */
#define RAD1_WORK_AES_IN_CTRL_OFFSET                 0x4ccu /* established */

/*
 * Working descriptor of channel type 0 (analog_in), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.
 */
/* work_analog_in_lo: rw32, reset unknown */
#define RAD1_WORK_ANALOG_IN_LO_OFFSET                0x4d0u /* established */

/*
 * Working descriptor of channel type 0 (analog_in), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.
 */
/* work_analog_in_ctrl: rw32, reset unknown */
#define RAD1_WORK_ANALOG_IN_CTRL_OFFSET              0x4d4u /* established */

/*
 * Working descriptor of channel type 7 (adat_in_sub), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.
 */
/* work_adat_in_sub_lo: rw32, reset unknown */
#define RAD1_WORK_ADAT_IN_SUB_LO_OFFSET              0x4d8u /* established */

/*
 * Working descriptor of channel type 7 (adat_in_sub), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.
 */
/* work_adat_in_sub_ctrl: rw32, reset unknown */
#define RAD1_WORK_ADAT_IN_SUB_CTRL_OFFSET            0x4dcu /* established */

/*
 * Working descriptor of channel type 6 (aes_in_sub), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.
 */
/* work_aes_in_sub_lo: rw32, reset unknown */
#define RAD1_WORK_AES_IN_SUB_LO_OFFSET               0x4e0u /* established */

/*
 * Working descriptor of channel type 6 (aes_in_sub), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.
 */
/* work_aes_in_sub_ctrl: rw32, reset unknown */
#define RAD1_WORK_AES_IN_SUB_CTRL_OFFSET             0x4e4u /* established */

/*
 * Working descriptor of channel type 5 (adat_out), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.
 */
/* work_adat_out_lo: rw32, reset unknown */
#define RAD1_WORK_ADAT_OUT_LO_OFFSET                 0x4e8u /* established */

/*
 * Working descriptor of channel type 5 (adat_out), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.
 */
/* work_adat_out_ctrl: rw32, reset unknown */
#define RAD1_WORK_ADAT_OUT_CTRL_OFFSET               0x4ecu /* established */

/*
 * Working descriptor of channel type 3 (aes_out), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.
 */
/* work_aes_out_lo: rw32, reset unknown */
#define RAD1_WORK_AES_OUT_LO_OFFSET                  0x4f0u /* established */

/*
 * Working descriptor of channel type 3 (aes_out), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.
 */
/* work_aes_out_ctrl: rw32, reset unknown */
#define RAD1_WORK_AES_OUT_CTRL_OFFSET                0x4f4u /* established */

/*
 * Working descriptor of channel type 1 (analog_out), address low: the descriptor now running. The driver writes the same value to the channel's descriptor RAM entry.
 */
/* work_analog_out_lo: rw32, reset unknown */
#define RAD1_WORK_ANALOG_OUT_LO_OFFSET               0x4f8u /* established */

/*
 * Working descriptor of channel type 1 (analog_out), control word (DESC_WORD). The upper field counts toward zero while the channel runs, which the Linux driver reads as progress.
 */
/* work_analog_out_ctrl: rw32, reset unknown */
#define RAD1_WORK_ANALOG_OUT_CTRL_OFFSET             0x4fcu /* established */

/*
 * Status ring, base PCI address low. A one-shot transfer uses the same registers with the limit set to 0xfffffffc.
 */
/* status_lo: rw32, reset unknown */
#define RAD1_STATUS_LO_OFFSET                        0x500u /* established */

/*
 * Status ring limit and wrap: the driver writes 0x78 minus slot count times 0x80, and 0xfffffffc for one shot. Field layout undecoded.
 */
/* status_limit: rw32, reset unknown */
#define RAD1_STATUS_LIMIT_OFFSET                     0x504u /* established */

/*
 * Working descriptor of channel type 4 (adat_in), address high.
 */
/* work_adat_in_hi: rw32, reset unknown */
#define RAD1_WORK_ADAT_IN_HI_OFFSET                  0x508u /* established */

/*
 * Working descriptor of channel type 2 (aes_in), address high.
 */
/* work_aes_in_hi: rw32, reset unknown */
#define RAD1_WORK_AES_IN_HI_OFFSET                   0x50cu /* established */

/*
 * Working descriptor of channel type 0 (analog_in), address high.
 */
/* work_analog_in_hi: rw32, reset unknown */
#define RAD1_WORK_ANALOG_IN_HI_OFFSET                0x510u /* established */

/*
 * Working descriptor of channel type 7 (adat_in_sub), address high.
 */
/* work_adat_in_sub_hi: rw32, reset unknown */
#define RAD1_WORK_ADAT_IN_SUB_HI_OFFSET              0x514u /* established */

/*
 * Working descriptor of channel type 6 (aes_in_sub), address high.
 */
/* work_aes_in_sub_hi: rw32, reset unknown */
#define RAD1_WORK_AES_IN_SUB_HI_OFFSET               0x518u /* established */

/*
 * Working descriptor of channel type 5 (adat_out), address high.
 */
/* work_adat_out_hi: rw32, reset unknown */
#define RAD1_WORK_ADAT_OUT_HI_OFFSET                 0x51cu /* established */

/*
 * Working descriptor of channel type 3 (aes_out), address high.
 */
/* work_aes_out_hi: rw32, reset unknown */
#define RAD1_WORK_AES_OUT_HI_OFFSET                  0x520u /* established */

/*
 * Working descriptor of channel type 1 (analog_out), address high.
 */
/* work_analog_out_hi: rw32, reset unknown */
#define RAD1_WORK_ANALOG_OUT_HI_OFFSET               0x524u /* established */

/*
 * Status ring, base PCI address high.
 */
/* status_hi: rw32, reset unknown */
#define RAD1_STATUS_HI_OFFSET                        0x528u /* established */

/*
 * ADAT output subcode buffer A: 15 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doubleword inside these ranges that belongs to the neighbouring buffer; do not infer a cross-buffer effect from that.
 */
/* adat_out_subcode_a: rw64, reset unknown */
#define RAD1_ADAT_OUT_SUBCODE_A_OFFSET               0x1000u /* established */
#define RAD1_ADAT_OUT_SUBCODE_A_COUNT                15
#define RAD1_ADAT_OUT_SUBCODE_A_STRIDE               8

/*
 * ADAT output subcode buffer B: 15 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doubleword inside these ranges that belongs to the neighbouring buffer; do not infer a cross-buffer effect from that.
 */
/* adat_out_subcode_b: rw64, reset unknown */
#define RAD1_ADAT_OUT_SUBCODE_B_OFFSET               0x1080u /* established */
#define RAD1_ADAT_OUT_SUBCODE_B_COUNT                15
#define RAD1_ADAT_OUT_SUBCODE_B_STRIDE               8

/*
 * AES3 output subcode buffer A: 16 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doubleword inside these ranges that belongs to the neighbouring buffer; do not infer a cross-buffer effect from that.
 */
/* aes_out_subcode_a: rw64, reset unknown */
#define RAD1_AES_OUT_SUBCODE_A_OFFSET                0x1100u /* established */
#define RAD1_AES_OUT_SUBCODE_A_COUNT                 16
#define RAD1_AES_OUT_SUBCODE_A_STRIDE                8

/*
 * AES3 output subcode buffer B: 16 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doubleword inside these ranges that belongs to the neighbouring buffer; do not infer a cross-buffer effect from that.
 */
/* aes_out_subcode_b: rw64, reset unknown */
#define RAD1_AES_OUT_SUBCODE_B_OFFSET                0x1180u /* established */
#define RAD1_AES_OUT_SUBCODE_B_COUNT                 16
#define RAD1_AES_OUT_SUBCODE_B_STRIDE                8

/*
 * extra AES3 subcode doublewords of buffer A: 2 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doubleword inside these ranges that belongs to the neighbouring buffer; do not infer a cross-buffer effect from that.
 */
/* aes_out_subcode_extra_a: rw64, reset unknown */
#define RAD1_AES_OUT_SUBCODE_EXTRA_A_OFFSET          0x1200u /* established */
#define RAD1_AES_OUT_SUBCODE_EXTRA_A_COUNT           2
#define RAD1_AES_OUT_SUBCODE_EXTRA_A_STRIDE          8

/*
 * extra AES3 subcode doublewords of buffer B: 2 doublewords written with 64-bit stores. Physical packing is unknown. The ADAT-output writer also clears one doubleword inside these ranges that belongs to the neighbouring buffer; do not infer a cross-buffer effect from that.
 */
/* aes_out_subcode_extra_b: rw64, reset unknown */
#define RAD1_AES_OUT_SUBCODE_EXTRA_B_OFFSET          0x1210u /* established */
#define RAD1_AES_OUT_SUBCODE_EXTRA_B_COUNT           2
#define RAD1_AES_OUT_SUBCODE_EXTRA_B_STRIDE          8

/*
 * Control word of a descriptor, in the RAM entry and in the working descriptor of a channel. The driver builds it as ((tag & 0xf) << 3) + (-length_units << 7), so bits 2:0 are zero in every driver-written word.
 */
/* word DESC_WORD: 32 bits */
#define RAD1_DESC_WORD_WIDTH                         32 /* inferred */
#define RAD1_DESC_WORD_LENGTH_UNITS_SHIFT            7 /* established */
#define RAD1_DESC_WORD_LENGTH_UNITS_MASK             0x1ffffffu
#define RAD1_DESC_WORD_LENGTH_UNITS_INPLACE          (RAD1_DESC_WORD_LENGTH_UNITS_MASK << RAD1_DESC_WORD_LENGTH_UNITS_SHIFT)
#define RAD1_DESC_WORD_NEXT_INDEX_SHIFT              3 /* inferred */
#define RAD1_DESC_WORD_NEXT_INDEX_MASK               0xfu
#define RAD1_DESC_WORD_NEXT_INDEX_INPLACE            (RAD1_DESC_WORD_NEXT_INDEX_MASK << RAD1_DESC_WORD_NEXT_INDEX_SHIFT)
#define RAD1_DESC_WORD_END_OF_DESCRIPTOR_SHIFT       2 /* inferred */
#define RAD1_DESC_WORD_END_OF_DESCRIPTOR_MASK        0x1u
#define RAD1_DESC_WORD_END_OF_DESCRIPTOR_INPLACE     (RAD1_DESC_WORD_END_OF_DESCRIPTOR_MASK << RAD1_DESC_WORD_END_OF_DESCRIPTOR_SHIFT)

/*
 * Low byte of PCI config offset 8. The driver reads the dword and splits this byte.
 */
/* word PCI_REVISION: 8 bits */
#define RAD1_PCI_REVISION_WIDTH                      8 /* established */
#define RAD1_PCI_REVISION_BOARD_MODE_SHIFT           4 /* established */
#define RAD1_PCI_REVISION_BOARD_MODE_MASK            0xfu
#define RAD1_PCI_REVISION_BOARD_MODE_INPLACE         (RAD1_PCI_REVISION_BOARD_MODE_MASK << RAD1_PCI_REVISION_BOARD_MODE_SHIFT)
#define RAD1_PCI_REVISION_CHIP_REV_SHIFT             0 /* established */
#define RAD1_PCI_REVISION_CHIP_REV_MASK              0xfu
#define RAD1_PCI_REVISION_CHIP_REV_INPLACE           (RAD1_PCI_REVISION_CHIP_REV_MASK << RAD1_PCI_REVISION_CHIP_REV_SHIFT)

/*
 * Slot word at byte offset 0x7c. The driver clears it before a transfer and waits for the engine to set bit 31.
 */
/* word STATUS_DONE: 32 bits */
#define RAD1_STATUS_DONE_WIDTH                       32 /* established */
#define RAD1_STATUS_DONE_DONE_SHIFT                  31 /* established */
#define RAD1_STATUS_DONE_DONE_MASK                   0x1u
#define RAD1_STATUS_DONE_DONE_INPLACE                (RAD1_STATUS_DONE_DONE_MASK << RAD1_STATUS_DONE_DONE_SHIFT)
#define RAD1_STATUS_DONE_AES_RATE_CODE_SHIFT         24 /* established */
#define RAD1_STATUS_DONE_AES_RATE_CODE_MASK          0x7u
#define RAD1_STATUS_DONE_AES_RATE_CODE_INPLACE       (RAD1_STATUS_DONE_AES_RATE_CODE_MASK << RAD1_STATUS_DONE_AES_RATE_CODE_SHIFT)
#define RAD1_STATUS_DONE_AES_NO_INPUT_SHIFT          19 /* inferred */
#define RAD1_STATUS_DONE_AES_NO_INPUT_MASK           0x1u
#define RAD1_STATUS_DONE_AES_NO_INPUT_INPLACE        (RAD1_STATUS_DONE_AES_NO_INPUT_MASK << RAD1_STATUS_DONE_AES_NO_INPUT_SHIFT)

/*
 * Slot word at byte offset 0x78 of each status slot. Bits not listed are never read by the driver.
 */
/* word STATUS_FLAGS: 32 bits */
#define RAD1_STATUS_FLAGS_WIDTH                      32 /* inferred */
#define RAD1_STATUS_FLAGS_VIDEO_EVENT_B_SHIFT        8 /* inferred */
#define RAD1_STATUS_FLAGS_VIDEO_EVENT_B_MASK         0x1u
#define RAD1_STATUS_FLAGS_VIDEO_EVENT_B_INPLACE      (RAD1_STATUS_FLAGS_VIDEO_EVENT_B_MASK << RAD1_STATUS_FLAGS_VIDEO_EVENT_B_SHIFT)
#define RAD1_STATUS_FLAGS_VIDEO_EVENT_A_SHIFT        7 /* inferred */
#define RAD1_STATUS_FLAGS_VIDEO_EVENT_A_MASK         0x1u
#define RAD1_STATUS_FLAGS_VIDEO_EVENT_A_INPLACE      (RAD1_STATUS_FLAGS_VIDEO_EVENT_A_MASK << RAD1_STATUS_FLAGS_VIDEO_EVENT_A_SHIFT)
#define RAD1_STATUS_FLAGS_ADAT_PRESENT_SHIFT         6 /* inferred */
#define RAD1_STATUS_FLAGS_ADAT_PRESENT_MASK          0x1u
#define RAD1_STATUS_FLAGS_ADAT_PRESENT_INPLACE       (RAD1_STATUS_FLAGS_ADAT_PRESENT_MASK << RAD1_STATUS_FLAGS_ADAT_PRESENT_SHIFT)

#define RAD1_BAR0_SIZE                               0x2000u /* inferred */
#define RAD1_CLOCKGEN_AES_OUT                        0x2u /* established */
#define RAD1_CLOCKGEN_ANALOG_IN                      0x0u /* established */
#define RAD1_CLOCKGEN_ANALOG_OUT                     0x1u /* established */
#define RAD1_CLOCKGEN_COUNT                          0x4u /* inferred */
#define RAD1_DESC_ENTRIES                            0x10u /* inferred */
#define RAD1_DESC_ENTRY_BYTES                        0xcu /* established */
#define RAD1_DESC_STATUS_ENTRY                       0xfu /* inferred */
#define RAD1_DMA_UNIT_BYTES                          0x80u /* established */
#define RAD1_GAIN_BIAS                               0x48u /* established */
#define RAD1_GAIN_BRINGUP                            0xd6d6d6d6u /* established */
#define RAD1_MODE_MEDIAIO                            0x7u /* established */
#define RAD1_MODE_OCTANE                             0xcu /* established */
#define RAD1_MODE_PCI_BOARD                          0xdu /* established */
#define RAD1_MUX_BITS                                0x10u /* established */
#define RAD1_MUX_PROBE_PASSES                        0x400u /* inferred */
#define RAD1_PCI_CLASS_OCTANE                        0x0u /* established */
#define RAD1_PCI_DEVICE                              0x5u /* established */
#define RAD1_PCI_VENDOR                              0x10a9u /* established */
#define RAD1_RBUF_REQUEST_BOARD12                    0x3u /* established */
#define RAD1_RBUF_REQUEST_BOARD13                    0x2u /* established */
#define RAD1_REV_MEDIAIO                             0x70u /* inferred */
#define RAD1_REV_OCTANE                              0xc0u /* established */
#define RAD1_REV_PCI_BOARD                           0xd0u /* inferred */
#define RAD1_RING_WORDS_ADAT                         0x1000u /* established */
#define RAD1_RING_WORDS_ANALOG                       0x400u /* established */
#define RAD1_STATUS_INTERVAL_DRIVER                  0xfau /* established */
#define RAD1_STATUS_INTERVAL_UNITS                   0x21u /* inferred */
#define RAD1_STATUS_ONESHOT_POLLS                    0x64u /* established */
#define RAD1_STATUS_ONESHOT_POLL_US                  0x5u /* established */
#define RAD1_STATUS_SLOTS_MAX                        0x80u /* established */
#define RAD1_STATUS_SLOT_BYTES                       0x80u /* established */
#define RAD1_STATUS_SLOT_DONE                        0x7cu /* established */
#define RAD1_STATUS_SLOT_FLAGS                       0x78u /* established */
#define RAD1_STATUS_SLOT_MIRROR                      0x44u /* established */
#define RAD1_STATUS_START_CONT                       0x40003u /* established */
#define RAD1_STATUS_START_ONESHOT                    0x40001u /* established */
#define RAD1_STATUS_STOP                             0x1fffcu /* established */
#define RAD1_UST_BEDROCK_FLAG_MASK                   0xf000u /* established */
#define RAD1_UST_BEDROCK_FLAG_VALUE                  0x4000u /* established */
#define RAD1_UST_MIN_ADVANCE                         0x3u /* established */
#define RAD1_UST_TICK_NS_FIXED                       0x3c0u /* established */

#endif /* RAD1_GEN_H */
