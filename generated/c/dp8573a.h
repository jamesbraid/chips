/* generated from devices/dp8573a/registers.toml by defs-gen - do not edit,
 * change the source */
/* defs-gen 4 */
/* input sha256 3d5cf3c64ca396076a616c64c2650a09e803487e15909b32eb1f6fd64cc9c1d7 */
/* National DP8573A real-time clock and battery-backed RAM (Indigo, R3000 and
 * R4000 boards) */
#ifndef DP8573A_GEN_H
#define DP8573A_GEN_H

#include <stdint.h>


/*
 * Always present, whichever block is selected. Bit 0 is the interrupt status,
 * high while the chip's interrupt output is asserted (read only). Bit 1 is the
 * power-fail status, which follows the PFAIL input and cannot be written. Bit 2
 * is the periodic interrupt flag and bit 3 the alarm interrupt flag; both are
 * cleared by writing a one to them and are set whether or not the interrupt is
 * enabled. Bits 4, 5 and 7 are general RAM bits on the 8573A. Bit 6 selects
 * register block 1. IRIX and the PROM write zero to select block 0 before every
 * access sequence and set bit 6 with a read-modify-write (the PROM and kernel
 * read routines leave it set when they finish). A qtest can discriminate: bit 6
 * flips which of two registers answers at the slot of register 3, bits 2 and 3
 * clear only on a one written, bits 0 and 1 ignore writes.
 */
/* status: rw8, space dp8573a_common, reset unknown */
#define DP8573A_STATUS_OFFSET                        0x3u /* established */
#define DP8573A_STATUS_RAM7_SHIFT                    7 /* established */
#define DP8573A_STATUS_RAM7_MASK                     0x1u
#define DP8573A_STATUS_RAM7_INPLACE (DP8573A_STATUS_RAM7_MASK << DP8573A_STATUS_RAM7_SHIFT)
#define DP8573A_STATUS_REGISTER_SELECT_SHIFT         6 /* established */
#define DP8573A_STATUS_REGISTER_SELECT_MASK          0x1u
#define DP8573A_STATUS_REGISTER_SELECT_INPLACE (DP8573A_STATUS_REGISTER_SELECT_MASK << DP8573A_STATUS_REGISTER_SELECT_SHIFT)
#define DP8573A_STATUS_RAM5_SHIFT                    5 /* established */
#define DP8573A_STATUS_RAM5_MASK                     0x1u
#define DP8573A_STATUS_RAM5_INPLACE (DP8573A_STATUS_RAM5_MASK << DP8573A_STATUS_RAM5_SHIFT)
#define DP8573A_STATUS_RAM4_SHIFT                    4 /* established */
#define DP8573A_STATUS_RAM4_MASK                     0x1u
#define DP8573A_STATUS_RAM4_INPLACE (DP8573A_STATUS_RAM4_MASK << DP8573A_STATUS_RAM4_SHIFT)
#define DP8573A_STATUS_ALARM_SHIFT                   3 /* established */
#define DP8573A_STATUS_ALARM_MASK                    0x1u
#define DP8573A_STATUS_ALARM_INPLACE (DP8573A_STATUS_ALARM_MASK << DP8573A_STATUS_ALARM_SHIFT)
#define DP8573A_STATUS_PERIODIC_SHIFT                2 /* established */
#define DP8573A_STATUS_PERIODIC_MASK                 0x1u
#define DP8573A_STATUS_PERIODIC_INPLACE (DP8573A_STATUS_PERIODIC_MASK << DP8573A_STATUS_PERIODIC_SHIFT)
#define DP8573A_STATUS_POWER_FAIL_SHIFT              1 /* established */
#define DP8573A_STATUS_POWER_FAIL_MASK               0x1u
#define DP8573A_STATUS_POWER_FAIL_INPLACE (DP8573A_STATUS_POWER_FAIL_MASK << DP8573A_STATUS_POWER_FAIL_SHIFT)
#define DP8573A_STATUS_INTERRUPT_STATUS_SHIFT        0 /* established */
#define DP8573A_STATUS_INTERRUPT_STATUS_MASK         0x1u
#define DP8573A_STATUS_INTERRUPT_STATUS_INPLACE (DP8573A_STATUS_INTERRUPT_STATUS_MASK << DP8573A_STATUS_INTERRUPT_STATUS_SHIFT)

/*
 * Hundredths and tenths of a second, two BCD digits, 00 to 99, incrementing
 * every 10 ms while the clock runs. The PROM's first read of the clock after
 * reset polls this byte and requires it to change (see the README). A qtest can
 * discriminate: with the start bit set the byte changes within a few tens of
 * milliseconds and wraps from 99 to 00 as it carries into seconds.
 */
/* hundredths: rw8, space dp8573a_common, reset unknown */
#define DP8573A_HUNDREDTHS_OFFSET                    0x17u /* established */

/*
 * Seconds, BCD 00 to 59. Written by IRIX and the PROM only with the clock
 * stopped.
 */
/* seconds: rw8, space dp8573a_common, reset unknown */
#define DP8573A_SECONDS_OFFSET                       0x1bu /* established */

/*
 * Minutes, BCD 00 to 59.
 */
/* minutes: rw8, space dp8573a_common, reset unknown */
#define DP8573A_MINUTES_OFFSET                       0x1fu /* established */

/*
 * Hours, BCD. In 24-hour mode (real time mode bit 2 clear, which is how IRIX
 * and the PROM run the chip) the range is 00 to 23 and bits 5:4 are the tens
 * digit. In 12-hour mode the range is 01 to 12 and bit 7 is the AM/PM flag (PM
 * set).
 */
/* hours: rw8, space dp8573a_common, reset unknown */
#define DP8573A_HOURS_OFFSET                         0x23u /* established */

/*
 * Day of month, BCD 01 to 28/29/30/31. Rolls over to 01.
 */
/* day_of_month: rw8, space dp8573a_common, reset unknown */
#define DP8573A_DAY_OF_MONTH_OFFSET                  0x27u /* established */

/*
 * Month, BCD 01 to 12. Rolls over to 01.
 */
/* month: rw8, space dp8573a_common, reset unknown */
#define DP8573A_MONTH_OFFSET                         0x2bu /* established */

/*
 * Year, BCD 00 to 99. IRIX and the PROM store years since 1970 here, not a
 * century year. The PROM accepts a clock whose year plus 1970 is below 2070.
 */
/* year: rw8, space dp8573a_common, reset unknown */
#define DP8573A_YEAR_OFFSET                          0x2fu /* established */

/*
 * A general RAM byte. Not touched by any shipped Indigo code.
 */
/* ram_0c: rw8, space dp8573a_common, reset unknown */
#define DP8573A_RAM_0C_OFFSET                        0x33u /* established */

/*
 * The data sheet's address table shows only bits 0 and 1 present and gives no
 * function, and the page text does not describe them. No shipped Indigo code
 * touches this byte. Whether the other bits read as zero is not stated.
 */
/* reg_0d: rw8, space dp8573a_common, reset unknown */
#define DP8573A_REG_0D_OFFSET                        0x37u /* unknown */

/*
 * Day of week counter, 1 to 7, rolls over to 1. The chip does not derive it
 * from the date; software sets it. IRIX never writes it (its time computation
 * ignores it); NetBSD writes it.
 */
/* day_of_week: rw8, space dp8573a_common, reset unknown */
#define DP8573A_DAY_OF_WEEK_OFFSET                   0x3bu /* established */

/*
 * Seconds compare RAM. Compared with the seconds counter only when interrupt
 * control 1 bit 0 is set; otherwise a free RAM byte.
 */
/* cmp_seconds: rw8, space dp8573a_common, reset unknown */
#define DP8573A_CMP_SECONDS_OFFSET                   0x4fu /* established */

/*
 * Minutes compare RAM, same rules as the seconds one with interrupt control 1
 * bit 1.
 */
/* cmp_minutes: rw8, space dp8573a_common, reset unknown */
#define DP8573A_CMP_MINUTES_OFFSET                   0x53u /* established */

/*
 * Hours compare RAM, a free RAM byte while interrupt control 1 bit 2 is clear.
 * IRIX keeps its bad-clock flag in bit 0 of this byte (set when the kernel
 * finds the date lost, cleared by a successful set). The PROM's start-up RAM
 * test saves the byte, writes a5, reads it back and restores it. A qtest can
 * discriminate: the byte holds any written value and survives with the clock
 * running.
 */
/* cmp_hours: rw8, space dp8573a_common, reset unknown */
#define DP8573A_CMP_HOURS_OFFSET                     0x57u /* established */

/*
 * Day-of-month compare RAM. The PROM's RAM test writes 5a here and restores it.
 */
/* cmp_day_of_month: rw8, space dp8573a_common, reset unknown */
#define DP8573A_CMP_DAY_OF_MONTH_OFFSET              0x5bu /* established */

/*
 * Month compare RAM.
 */
/* cmp_month: rw8, space dp8573a_common, reset unknown */
#define DP8573A_CMP_MONTH_OFFSET                     0x5fu /* established */

/*
 * Day-of-week compare RAM.
 */
/* cmp_day_of_week: rw8, space dp8573a_common, reset unknown */
#define DP8573A_CMP_DAY_OF_WEEK_OFFSET               0x63u /* established */

/*
 * Time save RAM, seconds. While time save control bit 7 is set this byte
 * follows the seconds counter; clearing that bit freezes it, which is how
 * software reads the clock without a rollover. The PROM zeroes all five time
 * save bytes before latching (the data sheet says to clear unused bits first);
 * the kernel does not.
 */
/* save_seconds: rw8, space dp8573a_common, reset unknown */
#define DP8573A_SAVE_SECONDS_OFFSET                  0x67u /* established */

/*
 * Time save RAM, minutes.
 */
/* save_minutes: rw8, space dp8573a_common, reset unknown */
#define DP8573A_SAVE_MINUTES_OFFSET                  0x6bu /* established */

/*
 * Time save RAM, hours.
 */
/* save_hours: rw8, space dp8573a_common, reset unknown */
#define DP8573A_SAVE_HOURS_OFFSET                    0x6fu /* established */

/*
 * Time save RAM, day of month.
 */
/* save_day_of_month: rw8, space dp8573a_common, reset unknown */
#define DP8573A_SAVE_DAY_OF_MONTH_OFFSET             0x73u /* established */

/*
 * Time save RAM, month. There is no year in time save RAM; software reads the
 * year counter directly after the latch.
 */
/* save_month: rw8, space dp8573a_common, reset unknown */
#define DP8573A_SAVE_MONTH_OFFSET                    0x77u /* established */

/*
 * A general RAM byte. Not touched by any shipped Indigo code.
 */
/* ram_1e: rw8, space dp8573a_common, reset unknown */
#define DP8573A_RAM_1E_OFFSET                        0x7bu /* established */

/*
 * A general RAM byte that doubles as the chip's test-mode register while the
 * test-enable bit of the periodic flag register is set. The data sheet says to
 * write zero here in a start-up sequence that first sets that bit. No shipped
 * Indigo code touches it; a model can treat it as RAM.
 */
/* ram_test: rw8, space dp8573a_common, reset unknown */
#define DP8573A_RAM_TEST_OFFSET                      0x7fu /* established */

/*
 * Block 0. Bits 0 to 5 are the six periodic event flags: minutes, tens of
 * seconds, seconds, 100 ms, 10 ms and 1 ms rollovers. They are set whether or
 * not the matching interrupt is enabled and are cleared by reading the
 * register. Bit 6 reads as the oscillator-fail flag (set on initial power-up
 * and after an oscillator failure, cleared by starting the clock with the
 * oscillator running) and, when written, selects battery-backed operation
 * (zero) or single-supply operation (one). Bit 7 is the test-mode enable;
 * software must keep it clear. IRIX and the PROM write zero here once while
 * setting the clock, which asks for battery-backed operation and clears test
 * mode. A qtest can discriminate: bits 0 to 5 are clear after a read, bit 6 is
 * high before the first start of the clock after power-up and low after.
 */
/* periodic_flag: rw8, space dp8573a_rs0, reset unknown */
#define DP8573A_PERIODIC_FLAG_OFFSET                 0xfu /* established */
#define DP8573A_PERIODIC_FLAG_TEST_ENABLE_SHIFT      7 /* established */
#define DP8573A_PERIODIC_FLAG_TEST_ENABLE_MASK       0x1u
#define DP8573A_PERIODIC_FLAG_TEST_ENABLE_INPLACE (DP8573A_PERIODIC_FLAG_TEST_ENABLE_MASK << DP8573A_PERIODIC_FLAG_TEST_ENABLE_SHIFT)
/* established */
#define DP8573A_PERIODIC_FLAG_OSC_FAIL_OR_SINGLE_SUPPLY_SHIFT 6
#define DP8573A_PERIODIC_FLAG_OSC_FAIL_OR_SINGLE_SUPPLY_MASK 0x1u
#define DP8573A_PERIODIC_FLAG_OSC_FAIL_OR_SINGLE_SUPPLY_INPLACE (DP8573A_PERIODIC_FLAG_OSC_FAIL_OR_SINGLE_SUPPLY_MASK << DP8573A_PERIODIC_FLAG_OSC_FAIL_OR_SINGLE_SUPPLY_SHIFT)
#define DP8573A_PERIODIC_FLAG_MS_SHIFT               5 /* established */
#define DP8573A_PERIODIC_FLAG_MS_MASK                0x1u
#define DP8573A_PERIODIC_FLAG_MS_INPLACE (DP8573A_PERIODIC_FLAG_MS_MASK << DP8573A_PERIODIC_FLAG_MS_SHIFT)
#define DP8573A_PERIODIC_FLAG_TEN_MS_SHIFT           4 /* established */
#define DP8573A_PERIODIC_FLAG_TEN_MS_MASK            0x1u
#define DP8573A_PERIODIC_FLAG_TEN_MS_INPLACE (DP8573A_PERIODIC_FLAG_TEN_MS_MASK << DP8573A_PERIODIC_FLAG_TEN_MS_SHIFT)
#define DP8573A_PERIODIC_FLAG_HUNDRED_MS_SHIFT       3 /* established */
#define DP8573A_PERIODIC_FLAG_HUNDRED_MS_MASK        0x1u
#define DP8573A_PERIODIC_FLAG_HUNDRED_MS_INPLACE (DP8573A_PERIODIC_FLAG_HUNDRED_MS_MASK << DP8573A_PERIODIC_FLAG_HUNDRED_MS_SHIFT)
#define DP8573A_PERIODIC_FLAG_SECOND_SHIFT           2 /* established */
#define DP8573A_PERIODIC_FLAG_SECOND_MASK            0x1u
#define DP8573A_PERIODIC_FLAG_SECOND_INPLACE (DP8573A_PERIODIC_FLAG_SECOND_MASK << DP8573A_PERIODIC_FLAG_SECOND_SHIFT)
#define DP8573A_PERIODIC_FLAG_TEN_SECOND_SHIFT       1 /* established */
#define DP8573A_PERIODIC_FLAG_TEN_SECOND_MASK        0x1u
#define DP8573A_PERIODIC_FLAG_TEN_SECOND_INPLACE (DP8573A_PERIODIC_FLAG_TEN_SECOND_MASK << DP8573A_PERIODIC_FLAG_TEN_SECOND_SHIFT)
#define DP8573A_PERIODIC_FLAG_MINUTE_SHIFT           0 /* established */
#define DP8573A_PERIODIC_FLAG_MINUTE_MASK            0x1u
#define DP8573A_PERIODIC_FLAG_MINUTE_INPLACE (DP8573A_PERIODIC_FLAG_MINUTE_MASK << DP8573A_PERIODIC_FLAG_MINUTE_SHIFT)

/*
 * Block 0. Bit 7 is the time save enable: while set the time save RAM follows
 * the clock, and a write that clears it freezes the clock's value there. Bits 0
 * to 5 are general RAM; bit 6 is not present and reads zero. IRIX and the PROM
 * read the clock by writing 80 then 00 and then reading the time save bytes;
 * the kernel's set sequence writes zero here. A qtest can discriminate: write
 * 80 then 00 leaves the five time save bytes equal to the counters at that
 * instant and unchanged afterwards.
 */
/* timesave_ctl: rw8, space dp8573a_rs0, reset unknown */
#define DP8573A_TIMESAVE_CTL_OFFSET                  0x13u /* established */
#define DP8573A_TIMESAVE_CTL_ENABLE_SHIFT            7 /* established */
#define DP8573A_TIMESAVE_CTL_ENABLE_MASK             0x1u
#define DP8573A_TIMESAVE_CTL_ENABLE_INPLACE (DP8573A_TIMESAVE_CTL_ENABLE_MASK << DP8573A_TIMESAVE_CTL_ENABLE_SHIFT)
#define DP8573A_TIMESAVE_CTL_ABSENT_SHIFT            6 /* established */
#define DP8573A_TIMESAVE_CTL_ABSENT_MASK             0x1u
#define DP8573A_TIMESAVE_CTL_ABSENT_INPLACE (DP8573A_TIMESAVE_CTL_ABSENT_MASK << DP8573A_TIMESAVE_CTL_ABSENT_SHIFT)
#define DP8573A_TIMESAVE_CTL_RAM_SHIFT               0 /* established */
#define DP8573A_TIMESAVE_CTL_RAM_MASK                0x3fu
#define DP8573A_TIMESAVE_CTL_RAM_INPLACE (DP8573A_TIMESAVE_CTL_RAM_MASK << DP8573A_TIMESAVE_CTL_RAM_SHIFT)

/*
 * Block 1. Bits 1:0 are the leap-year counter: years since the last leap year,
 * 0 meaning this year is one. Bit 2 selects 12-hour (set) or 24-hour (clear)
 * mode; IRIX and the PROM leave it clear. Bit 3 starts the clock when set and
 * holds the counters stopped when clear; while the oscillator has not started
 * the chip holds it clear, and it clears itself on an oscillator failure. Bit 4
 * keeps the interrupt configuration alive in standby; both programs set it with
 * bit 3 (run bits 0x18). Bits 7:5 are general RAM on the 8573A (crystal select
 * bits on the 8572A). The data sheet requires clearing bit 3 before writing the
 * counters; IRIX and the PROM do exactly that and then write the mode back with
 * bit 3 set and the leap field from the year. A qtest can discriminate: the
 * counters advance only while bit 3 is set, and a read of the clock sequence
 * returns the mode byte with bits 3 and 4 as written.
 */
/* rt_mode: rw8, space dp8573a_rs1, reset unknown */
#define DP8573A_RT_MODE_OFFSET                       0x7u /* established */
#define DP8573A_RT_MODE_RAM_SHIFT                    5 /* established */
#define DP8573A_RT_MODE_RAM_MASK                     0x7u
#define DP8573A_RT_MODE_RAM_INPLACE (DP8573A_RT_MODE_RAM_MASK << DP8573A_RT_MODE_RAM_SHIFT)
#define DP8573A_RT_MODE_INT_STANDBY_SHIFT            4 /* established */
#define DP8573A_RT_MODE_INT_STANDBY_MASK             0x1u
#define DP8573A_RT_MODE_INT_STANDBY_INPLACE (DP8573A_RT_MODE_INT_STANDBY_MASK << DP8573A_RT_MODE_INT_STANDBY_SHIFT)
#define DP8573A_RT_MODE_RUN_SHIFT                    3 /* established */
#define DP8573A_RT_MODE_RUN_MASK                     0x1u
#define DP8573A_RT_MODE_RUN_INPLACE (DP8573A_RT_MODE_RUN_MASK << DP8573A_RT_MODE_RUN_SHIFT)
#define DP8573A_RT_MODE_HOUR12_SHIFT                 2 /* established */
#define DP8573A_RT_MODE_HOUR12_MASK                  0x1u
#define DP8573A_RT_MODE_HOUR12_INPLACE (DP8573A_RT_MODE_HOUR12_MASK << DP8573A_RT_MODE_HOUR12_SHIFT)
#define DP8573A_RT_MODE_LEAP_SHIFT                   0 /* established */
#define DP8573A_RT_MODE_LEAP_MASK                    0x3u
#define DP8573A_RT_MODE_LEAP_INPLACE (DP8573A_RT_MODE_LEAP_MASK << DP8573A_RT_MODE_LEAP_SHIFT)

/*
 * Block 1. Bit 7 chooses what the MFO pin carries: the power-fail interrupt
 * (clear) or the buffered crystal oscillator (set). Bits 6:0 are general RAM.
 * IRIX and the PROM write zero while setting the clock. Where MFO is wired on
 * the Indigo is unknown.
 */
/* output_mode: rw8, space dp8573a_rs1, reset unknown */
#define DP8573A_OUTPUT_MODE_OFFSET                   0xbu /* established */
#define DP8573A_OUTPUT_MODE_MFO_OSCILLATOR_SHIFT     7 /* established */
#define DP8573A_OUTPUT_MODE_MFO_OSCILLATOR_MASK      0x1u
#define DP8573A_OUTPUT_MODE_MFO_OSCILLATOR_INPLACE (DP8573A_OUTPUT_MODE_MFO_OSCILLATOR_MASK << DP8573A_OUTPUT_MODE_MFO_OSCILLATOR_SHIFT)
#define DP8573A_OUTPUT_MODE_RAM_SHIFT                0 /* established */
#define DP8573A_OUTPUT_MODE_RAM_MASK                 0x7fu
#define DP8573A_OUTPUT_MODE_RAM_INPLACE (DP8573A_OUTPUT_MODE_RAM_MASK << DP8573A_OUTPUT_MODE_RAM_SHIFT)

/*
 * Block 1. Bits 0 to 5 enable the six periodic interrupts (minutes, tens of
 * seconds, seconds, 100 ms, 10 ms, 1 ms), which raise main status bit 2 and the
 * interrupt output; bits 6 and 7 are general RAM. Shipped Indigo code never
 * writes this register (the kernel's clock tick comes from the 8254 timer), so
 * what it holds at power-up decides whether the chip interrupts; the data sheet
 * says its contents are random until written.
 */
/* int0_ctl: rw8, space dp8573a_rs1, reset unknown */
#define DP8573A_INT0_CTL_OFFSET                      0xfu /* established */
#define DP8573A_INT0_CTL_RAM_SHIFT                   6 /* established */
#define DP8573A_INT0_CTL_RAM_MASK                    0x3u
#define DP8573A_INT0_CTL_RAM_INPLACE (DP8573A_INT0_CTL_RAM_MASK << DP8573A_INT0_CTL_RAM_SHIFT)
#define DP8573A_INT0_CTL_MS_SHIFT                    5 /* established */
#define DP8573A_INT0_CTL_MS_MASK                     0x1u
#define DP8573A_INT0_CTL_MS_INPLACE (DP8573A_INT0_CTL_MS_MASK << DP8573A_INT0_CTL_MS_SHIFT)
#define DP8573A_INT0_CTL_TEN_MS_SHIFT                4 /* established */
#define DP8573A_INT0_CTL_TEN_MS_MASK                 0x1u
#define DP8573A_INT0_CTL_TEN_MS_INPLACE (DP8573A_INT0_CTL_TEN_MS_MASK << DP8573A_INT0_CTL_TEN_MS_SHIFT)
#define DP8573A_INT0_CTL_HUNDRED_MS_SHIFT            3 /* established */
#define DP8573A_INT0_CTL_HUNDRED_MS_MASK             0x1u
#define DP8573A_INT0_CTL_HUNDRED_MS_INPLACE (DP8573A_INT0_CTL_HUNDRED_MS_MASK << DP8573A_INT0_CTL_HUNDRED_MS_SHIFT)
#define DP8573A_INT0_CTL_SECOND_SHIFT                2 /* established */
#define DP8573A_INT0_CTL_SECOND_MASK                 0x1u
#define DP8573A_INT0_CTL_SECOND_INPLACE (DP8573A_INT0_CTL_SECOND_MASK << DP8573A_INT0_CTL_SECOND_SHIFT)
#define DP8573A_INT0_CTL_TEN_SECOND_SHIFT            1 /* established */
#define DP8573A_INT0_CTL_TEN_SECOND_MASK             0x1u
#define DP8573A_INT0_CTL_TEN_SECOND_INPLACE (DP8573A_INT0_CTL_TEN_SECOND_MASK << DP8573A_INT0_CTL_TEN_SECOND_SHIFT)
#define DP8573A_INT0_CTL_MINUTE_SHIFT                0 /* established */
#define DP8573A_INT0_CTL_MINUTE_MASK                 0x1u
#define DP8573A_INT0_CTL_MINUTE_INPLACE (DP8573A_INT0_CTL_MINUTE_MASK << DP8573A_INT0_CTL_MINUTE_SHIFT)

/*
 * Block 1. Bits 0 to 5 enable the compare of seconds, minutes, hours, day of
 * month, month and day of week against the matching compare RAM byte: a clear
 * bit forces that comparison to always-equal and frees the RAM byte. Bit 6 lets
 * an alarm match (all enabled compares equal) raise the interrupt output; bit 7
 * enables the power-fail interrupt and the low-battery circuit. IRIX and the
 * PROM write 80 whenever they set the clock, which disables every compare and
 * the alarm interrupt and leaves only the power-fail interrupt enabled. A qtest
 * can discriminate: with bits 0 to 5 clear the compare RAM never raises main
 * status bit 3.
 */
/* int1_ctl: rw8, space dp8573a_rs1, reset unknown */
#define DP8573A_INT1_CTL_OFFSET                      0x13u /* established */
#define DP8573A_INT1_CTL_POWER_FAIL_INT_ENABLE_SHIFT 7 /* established */
#define DP8573A_INT1_CTL_POWER_FAIL_INT_ENABLE_MASK  0x1u
#define DP8573A_INT1_CTL_POWER_FAIL_INT_ENABLE_INPLACE (DP8573A_INT1_CTL_POWER_FAIL_INT_ENABLE_MASK << DP8573A_INT1_CTL_POWER_FAIL_INT_ENABLE_SHIFT)
#define DP8573A_INT1_CTL_ALARM_INT_ENABLE_SHIFT      6 /* established */
#define DP8573A_INT1_CTL_ALARM_INT_ENABLE_MASK       0x1u
#define DP8573A_INT1_CTL_ALARM_INT_ENABLE_INPLACE (DP8573A_INT1_CTL_ALARM_INT_ENABLE_MASK << DP8573A_INT1_CTL_ALARM_INT_ENABLE_SHIFT)
#define DP8573A_INT1_CTL_CMP_DAY_OF_WEEK_SHIFT       5 /* established */
#define DP8573A_INT1_CTL_CMP_DAY_OF_WEEK_MASK        0x1u
#define DP8573A_INT1_CTL_CMP_DAY_OF_WEEK_INPLACE (DP8573A_INT1_CTL_CMP_DAY_OF_WEEK_MASK << DP8573A_INT1_CTL_CMP_DAY_OF_WEEK_SHIFT)
#define DP8573A_INT1_CTL_CMP_MONTH_SHIFT             4 /* established */
#define DP8573A_INT1_CTL_CMP_MONTH_MASK              0x1u
#define DP8573A_INT1_CTL_CMP_MONTH_INPLACE (DP8573A_INT1_CTL_CMP_MONTH_MASK << DP8573A_INT1_CTL_CMP_MONTH_SHIFT)
#define DP8573A_INT1_CTL_CMP_DAY_OF_MONTH_SHIFT      3 /* established */
#define DP8573A_INT1_CTL_CMP_DAY_OF_MONTH_MASK       0x1u
#define DP8573A_INT1_CTL_CMP_DAY_OF_MONTH_INPLACE (DP8573A_INT1_CTL_CMP_DAY_OF_MONTH_MASK << DP8573A_INT1_CTL_CMP_DAY_OF_MONTH_SHIFT)
#define DP8573A_INT1_CTL_CMP_HOURS_SHIFT             2 /* established */
#define DP8573A_INT1_CTL_CMP_HOURS_MASK              0x1u
#define DP8573A_INT1_CTL_CMP_HOURS_INPLACE (DP8573A_INT1_CTL_CMP_HOURS_MASK << DP8573A_INT1_CTL_CMP_HOURS_SHIFT)
#define DP8573A_INT1_CTL_CMP_MINUTES_SHIFT           1 /* established */
#define DP8573A_INT1_CTL_CMP_MINUTES_MASK            0x1u
#define DP8573A_INT1_CTL_CMP_MINUTES_INPLACE (DP8573A_INT1_CTL_CMP_MINUTES_MASK << DP8573A_INT1_CTL_CMP_MINUTES_SHIFT)
#define DP8573A_INT1_CTL_CMP_SECONDS_SHIFT           0 /* established */
#define DP8573A_INT1_CTL_CMP_SECONDS_MASK            0x1u
#define DP8573A_INT1_CTL_CMP_SECONDS_INPLACE (DP8573A_INT1_CTL_CMP_SECONDS_MASK << DP8573A_INT1_CTL_CMP_SECONDS_SHIFT)

#define DP8573A_BAD_CLOCK_FLAG                       0x1u /* established */
#define DP8573A_EPOCH_YEAR                           0x7b2u /* established */
#define DP8573A_INT1_INIT                            0x80u /* established */
#define DP8573A_LANE_OFFSET                          0x3u /* established */
#define DP8573A_RAM_TEST_A                           0xa5u /* established */
#define DP8573A_RAM_TEST_B                           0x5au /* established */
#define DP8573A_RT_RS                                0x40u /* established */
#define DP8573A_RT_RUN                               0x18u /* established */
#define DP8573A_RT_TIMSAV_ON                         0x80u /* established */
#define DP8573A_WINDOW_SIZE                          0x80u /* established */

#endif /* DP8573A_GEN_H */
