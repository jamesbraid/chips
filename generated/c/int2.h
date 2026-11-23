/* generated from devices/int2/registers.toml by defs-gen - do not edit, change
 * the source */
/* defs-gen 4 */
/* input sha256 ddb7d5c9a928bcccdae1a8a3a03b7439bba8c65460f360e653d4e8612963b52e */
/* INT2 local interrupt controller and 8254 timer block (Indigo, R3000 and R4000
 * boards) */
#ifndef INT2_GEN_H
#define INT2_GEN_H

#include <stdint.h>


/*
 * Raw state of the eight local 0 sources, one bit each, high while the source
 * asserts. It is not gated by the mask: the PROM clears both masks and then
 * reads status, and IRIX ANDs status with the mask in software. Bit layout is
 * the LOCAL0 constants. A qtest can discriminate: a write has no effect; the
 * bit follows the source signal.
 */
/* local0_status: r8, reset unknown */
#define INT2_LOCAL0_STATUS_OFFSET                    0x3u /* established */

/*
 * Enables local 0 sources toward the CPU. A one bit lets the source raise the
 * local 0 output. All eight bits read back what was written: the PROM writes 00
 * aa cc f0 ff 55 33 0f in turn and compares. A qtest can discriminate: byte
 * write then read of 0xaa and 0x55.
 */
/* local0_mask: rw8, reset 0x0 */
#define INT2_LOCAL0_MASK_OFFSET                      0x7u /* established */

/*
 * Raw state of the eight local 1 sources. Same rules as local 0 status. With
 * all masks clear the PROM expects bits 0, 2, 3 and 4 to read zero and
 * tolerates bits 1, 5, 6 and 7.
 */
/* local1_status: r8, reset unknown */
#define INT2_LOCAL1_STATUS_OFFSET                    0xbu /* established */

/*
 * Enables local 1 sources toward the CPU. All eight bits read back.
 */
/* local1_mask: rw8, reset 0x0 */
#define INT2_LOCAL1_MASK_OFFSET                      0xfu /* established */

/*
 * VME interrupt request levels 1 to 7 in bits 1 to 7 (inferred from the header
 * names; no shipped R4000 Indigo code reads it for VME). Bit 0 is read by the
 * GR2 retrace handler as the vertical-retrace status, active low (the header
 * says 'no interrupt' when set): the handler polls it up to ten times 1
 * microsecond apart. NetBSD names this offset the map status register of the
 * Indy's INT3 and gives it a different meaning.
 */
/* vme_status: r8, reset unknown */
#define INT2_VME_STATUS_OFFSET                       0x13u /* established */

/*
 * Which VME levels may raise local 0 bit 7. The IRIX routine that targets an
 * I/O interrupt at the CPU sets bit n in this register. The PROM never reads
 * this register back.
 */
/* vme0_mask: rw8, reset 0x0 */
#define INT2_VME0_MASK_OFFSET                        0x17u /* established */

/*
 * Which VME levels may raise local 1 bit 3. The PROM writes 0x5a and checks the
 * read-back, so all eight bits hold.
 */
/* vme1_mask: rw8, reset 0x0 */
#define INT2_VME1_MASK_OFFSET                        0x1bu /* established */

/*
 * Five-bit read/write port at the offset NetBSD calls the map polarity register
 * on the Indy generation. The header calls it the LED and serial-port
 * configuration register. Bits 1 and 2 are the RTS lines of serial ports 0 and
 * 1 (the serial driver sets and clears them to switch the port between RS-232
 * and RS-422 modes); bit 3 is the vertical-retrace interrupt latch control; bit
 * 4 is named power in the header. The PROM writes 0x16 during start-up. The
 * header also names bits 1 to 3 as LEDs on the R4000 board and bit 0 as a cache
 * parity flag; which role a bit plays on which board, and the LED polarity, are
 * not settled.
 */
/* port_config: rw8, reset unknown */
#define INT2_PORT_CONFIG_OFFSET                      0x1fu /* established */
#define INT2_PORT_CONFIG_POWER_SHIFT                 4 /* unknown */
#define INT2_PORT_CONFIG_POWER_MASK                  0x1u
#define INT2_PORT_CONFIG_POWER_INPLACE (INT2_PORT_CONFIG_POWER_MASK << INT2_PORT_CONFIG_POWER_SHIFT)
#define INT2_PORT_CONFIG_VR_INTERRUPT_LATCH_SHIFT    3 /* established */
#define INT2_PORT_CONFIG_VR_INTERRUPT_LATCH_MASK     0x1u
#define INT2_PORT_CONFIG_VR_INTERRUPT_LATCH_INPLACE (INT2_PORT_CONFIG_VR_INTERRUPT_LATCH_MASK << INT2_PORT_CONFIG_VR_INTERRUPT_LATCH_SHIFT)
#define INT2_PORT_CONFIG_SER1_RTS_SHIFT              2 /* established */
#define INT2_PORT_CONFIG_SER1_RTS_MASK               0x1u
#define INT2_PORT_CONFIG_SER1_RTS_INPLACE (INT2_PORT_CONFIG_SER1_RTS_MASK << INT2_PORT_CONFIG_SER1_RTS_SHIFT)
#define INT2_PORT_CONFIG_SER0_RTS_SHIFT              1 /* established */
#define INT2_PORT_CONFIG_SER0_RTS_MASK               0x1u
#define INT2_PORT_CONFIG_SER0_RTS_INPLACE (INT2_PORT_CONFIG_SER0_RTS_MASK << INT2_PORT_CONFIG_SER0_RTS_SHIFT)
#define INT2_PORT_CONFIG_PARITY_OR_EXT_CLOCK_SHIFT   0 /* unknown */
#define INT2_PORT_CONFIG_PARITY_OR_EXT_CLOCK_MASK    0x1u
#define INT2_PORT_CONFIG_PARITY_OR_EXT_CLOCK_INPLACE (INT2_PORT_CONFIG_PARITY_OR_EXT_CLOCK_MASK << INT2_PORT_CONFIG_PARITY_OR_EXT_CLOCK_SHIFT)

/*
 * Write-only strobe. Writing 1 clears the timer 0 interrupt latch, 2 clears
 * timer 1. IRIX acknowledges timer 0 with 1 and timer 1 with 2; the PROM writes
 * 3 at start to clear both. Writing zero bits has no effect. A qtest can
 * discriminate: timer 0 interrupt line drops after a write of 1 and timer 1
 * stays asserted.
 */
/* timer_ack: w8, reset unknown */
#define INT2_TIMER_ACK_OFFSET                        0x23u /* established */
#define INT2_TIMER_ACK_TIMER1_SHIFT                  1 /* established */
#define INT2_TIMER_ACK_TIMER1_MASK                   0x1u
#define INT2_TIMER_ACK_TIMER1_INPLACE (INT2_TIMER_ACK_TIMER1_MASK << INT2_TIMER_ACK_TIMER1_SHIFT)
#define INT2_TIMER_ACK_TIMER0_SHIFT                  0 /* established */
#define INT2_TIMER_ACK_TIMER0_MASK                   0x1u
#define INT2_TIMER_ACK_TIMER0_INPLACE (INT2_TIMER_ACK_TIMER0_MASK << INT2_TIMER_ACK_TIMER0_SHIFT)

/*
 * No R4000 Indigo kernel object or the PROM touches this offset. NetBSD defines
 * it for the Indy generation, where Linux calls it reserved on INT2. Nothing
 * shipped for the Indigo reads it.
 */
/* error_status: r8, reset unknown */
#define INT2_ERROR_STATUS_OFFSET                     0x27u /* unknown */

/*
 * 8254 counter 0 data, one byte at a time per the control word. Its output is
 * the timer 0 interrupt (CPU IP4). IRIX loads it with 50 after control word
 * 0x34, giving 100 Hz from the 5 kHz counter 2 output.
 */
/* timer0: rw8, reset unknown */
#define INT2_TIMER0_OFFSET                           0x33u /* established */

/*
 * 8254 counter 1 data. Its output is the timer 1 interrupt (CPU IP5), the
 * profiling and fast clock. IRIX loads it with 5000 divided by the wanted rate,
 * MSB shifted down, after control word 0x74.
 */
/* timer1: rw8, reset unknown */
#define INT2_TIMER1_OFFSET                           0x37u /* established */

/*
 * 8254 counter 2 data. Its output clocks counters 0 and 1 (NetBSD's header
 * states this; IRIX's counter 0 and 1 divisors only make sense with it). IRIX
 * counts 200 into it; the PROM reuses it as a 100 Hz reference with count 10000
 * and latches it with control word 0x80.
 */
/* timer2: rw8, reset unknown */
#define INT2_TIMER2_OFFSET                           0x3bu /* established */

/*
 * 8254 control word. The R4000 Indigo kernel and the PROM only write it.
 * Standard 8254 layout; the values seen are 0x34, 0x74 and 0xb4 (counter 0, 1,
 * 2 in mode 2 with LSB then MSB), 0x32, 0x72 and 0xb2 (mode 1) and 0x80 (latch
 * counter 2) and 0xb8 (counter 2 mode 4).
 */
/* timer_control: w8, reset unknown */
#define INT2_TIMER_CONTROL_OFFSET                    0x3fu /* established */
#define INT2_TIMER_CONTROL_COUNTER_SHIFT             6 /* established */
#define INT2_TIMER_CONTROL_COUNTER_MASK              0x3u
#define INT2_TIMER_CONTROL_COUNTER_INPLACE (INT2_TIMER_CONTROL_COUNTER_MASK << INT2_TIMER_CONTROL_COUNTER_SHIFT)
#define INT2_TIMER_CONTROL_RW_SHIFT                  4 /* established */
#define INT2_TIMER_CONTROL_RW_MASK                   0x3u
#define INT2_TIMER_CONTROL_RW_INPLACE (INT2_TIMER_CONTROL_RW_MASK << INT2_TIMER_CONTROL_RW_SHIFT)
#define INT2_TIMER_CONTROL_MODE_SHIFT                1 /* established */
#define INT2_TIMER_CONTROL_MODE_MASK                 0x7u
#define INT2_TIMER_CONTROL_MODE_INPLACE (INT2_TIMER_CONTROL_MODE_MASK << INT2_TIMER_CONTROL_MODE_SHIFT)
#define INT2_TIMER_CONTROL_BCD_SHIFT                 0 /* established */
#define INT2_TIMER_CONTROL_BCD_MASK                  0x1u
#define INT2_TIMER_CONTROL_BCD_INPLACE (INT2_TIMER_CONTROL_BCD_MASK << INT2_TIMER_CONTROL_BCD_SHIFT)

#define INT2_ACK_TIMER0                              0x1u /* established */
#define INT2_ACK_TIMER1                              0x2u /* established */
#define INT2_LOCAL0_CENTR                            0x2u /* established */
#define INT2_LOCAL0_DUART                            0x20u /* established */
#define INT2_LOCAL0_ENET                             0x8u /* established */
#define INT2_LOCAL0_FIFO                             0x1u /* established */
#define INT2_LOCAL0_GDMA                             0x10u /* established */
#define INT2_LOCAL0_GIO1                             0x40u /* established */
#define INT2_LOCAL0_SCSI                             0x4u /* established */
#define INT2_LOCAL0_VME0                             0x80u /* established */
#define INT2_LOCAL1_ACFAIL                           0x20u /* established */
#define INT2_LOCAL1_DSP                              0x10u /* established */
#define INT2_LOCAL1_GIO2                             0x80u /* established */
#define INT2_LOCAL1_GR1MODE                          0x2u /* established */
#define INT2_LOCAL1_VIDEO                            0x40u /* established */
#define INT2_LOCAL1_VME1                             0x8u /* established */
#define INT2_TIMER_MASTER_HZ                         0xf4240u /* inferred */

#endif /* INT2_GEN_H */
