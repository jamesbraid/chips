/* generated from devices/ds1685/registers.toml by defs-gen - do not edit, change the source */
/* defs-gen 2 */
/* input sha256 2d03aff8397fa4913c718e61cdbc7f8b15ad4905a2ec4a42ae8709b19c99ca92 */
/* Dallas DS1685/DS1687 real-time clock and battery-backed RAM (Octane and Octane2 system boards) */
#ifndef DS1685_GEN_H
#define DS1685_GEN_H

#include <stdint.h>


/*
 * Bank-0 user RAM, 114 bytes. The driver's write loop covers a 50-byte run from 0Eh and a 64-byte run from 40h, whose sum is 114, so the block runs from 0Eh to 7Fh. The sources do not state a layout inside it; Linux exposes it as unstructured storage.
 */
/* user_ram: rw8, space bank0, reset unknown; Linux rtc-ds1685 driver, ds1685_nvram_write, which treats the bank-0 bytes as one 114-byte run */
#define DS1685_USER_RAM_OFFSET                       0xeu /* inferred */
#define DS1685_USER_RAM_COUNT                        114
#define DS1685_USER_RAM_STRIDE                       1

/*
 * Model byte, the first of the eight identification bytes; the datasheet gives the value 71h. Probe does not read it, so only the sysfs and proc views show a wrong value.
 */
/* model: r8, space bank1, reset unknown; Maxim DS1685 datasheet 19-5215 rev 10/12, silicon serial number section (page 18): register 40h holds the model number 71h, read-only */
#define DS1685_MODEL_OFFSET                          0x40u /* established */

/*
 * Six serial-number bytes that follow the model byte. Linux exposes them through sysfs and nothing consulted checks them.
 */
/* serial: r8, space bank1, reset unknown; Maxim DS1685 datasheet 19-5215 rev 10/12, silicon serial number section (page 18): registers 41h to 46h, unique and read-only */
#define DS1685_SERIAL_OFFSET                         0x41u /* established */
#define DS1685_SERIAL_COUNT                          6
#define DS1685_SERIAL_STRIDE                         1

/*
 * CRC byte over the seven identification bytes before it. The datasheet text gives no polynomial, so this import cannot reproduce the check. No driver consulted validates it.
 */
/* serial_crc: r8, space bank1, reset unknown; Maxim DS1685 datasheet 19-5215 rev 10/12, silicon serial number section (page 18): register 47h, CRC over 40h to 46h */
#define DS1685_SERIAL_CRC_OFFSET                     0x47u /* established */

/*
 * Century, in the same data-mode form as the other calendar bytes. Linux computes the year as the year byte plus the century times 100.
 */
/* century: rw8, space bank1, reset unknown; Maxim DS1685 datasheet 19-5215 rev 10/12, century register section (bank 1, 48h, binary or BCD); Linux rtc-ds1685 driver, ds1685_rtc_read_time */
#define DS1685_CENTURY_OFFSET                        0x48u /* established */

/*
 * Date alarm. The wake-up alarm matches this byte together with the hours, minutes and seconds alarm bytes. Linux also writes it as the alarm date.
 */
/* date_alarm: rw8, space bank1, reset unknown; Maxim DS1685 datasheet, wake-up section, as quoted by the sources consulted */
#define DS1685_DATE_ALARM_OFFSET                     0x49u /* established */

/*
 * Extended control and flag byte. Only the bits named below are positioned here. Its other bits (the wake-up, RAM-clear and valid-battery flags) are read and cleared by the drivers, but their positions are not transcribed in this unit.
 */
/* ctrl4a: rw8, space bank1, reset unknown; Linux rtc-ds1685 driver, probe and poweroff paths; OpenBSD power driver, power_intr */
#define DS1685_CTRL4A_OFFSET                         0x4au /* inferred */
#define DS1685_CTRL4A_INCR_SHIFT                     6 /* inferred */
#define DS1685_CTRL4A_INCR_MASK                      0x1u
#define DS1685_CTRL4A_INCR_INPLACE                   (DS1685_CTRL4A_INCR_MASK << DS1685_CTRL4A_INCR_SHIFT)
#define DS1685_CTRL4A_PAB_SHIFT                      3 /* established */
#define DS1685_CTRL4A_PAB_MASK                       0x1u
#define DS1685_CTRL4A_PAB_INPLACE                    (DS1685_CTRL4A_PAB_MASK << DS1685_CTRL4A_PAB_SHIFT)
#define DS1685_CTRL4A_KICKSTART_FLAG_SHIFT           0 /* inferred */
#define DS1685_CTRL4A_KICKSTART_FLAG_MASK            0x1u
#define DS1685_CTRL4A_KICKSTART_FLAG_INPLACE         (DS1685_CTRL4A_KICKSTART_FLAG_MASK << DS1685_CTRL4A_KICKSTART_FLAG_SHIFT)

/*
 * Extended enable byte, holding the enables for the wake-up, RAM-clear and kickstart interrupts. Linux writes it at probe and remove. Bit positions are not transcribed in this unit.
 */
/* ctrl4b: rw8, space bank1, reset unknown; Linux rtc-ds1685 driver, probe and remove paths */
#define DS1685_CTRL4B_OFFSET                         0x4bu /* inferred */

/*
 * Address for the extended RAM, seven bits. The address does not advance on its own, so software writes it before each byte.
 */
/* ext_ram_address: w8, space bank1, reset unknown; Linux rtc-ds1685 driver, extended-RAM read and write paths; the vendor text as quoted by the sources */
#define DS1685_EXT_RAM_ADDRESS_OFFSET                0x50u /* inferred */

/*
 * Extended RAM data at the address in the address register.
 */
/* ext_ram_data: rw8, space bank1, reset unknown; Linux rtc-ds1685 driver, extended-RAM read and write paths */
#define DS1685_EXT_RAM_DATA_OFFSET                   0x53u /* inferred */

/*
 * Seconds. Binary or BCD according to the data-mode bit, which this unit does not carry.
 */
/* seconds: rw8, space common, reset unknown; Linux rtc-ds1685 driver, ds1685_rtc_read_time, which reads this byte first among the time fields */
#define DS1685_SECONDS_OFFSET                        0x0u /* inferred */

/*
 * Seconds alarm byte. Linux's alarm paths read and write it with the other alarm bytes; the sources consulted do not describe how the match treats a wildcard value.
 */
/* alarm_seconds: rw8, space common, reset unknown; Linux rtc-ds1685 driver, alarm read and write paths */
#define DS1685_ALARM_SECONDS_OFFSET                  0x1u /* inferred */

/*
 * Minutes. Same data-mode rule as seconds.
 */
/* minutes: rw8, space common, reset unknown; Linux rtc-ds1685 driver, ds1685_rtc_read_time */
#define DS1685_MINUTES_OFFSET                        0x2u /* inferred */

/*
 * Minutes alarm byte.
 */
/* alarm_minutes: rw8, space common, reset unknown; Linux rtc-ds1685 driver, alarm read and write paths */
#define DS1685_ALARM_MINUTES_OFFSET                  0x3u /* inferred */

/*
 * Hours. Linux forces 24-hour mode at probe and converts the stored value first if the chip was in 12-hour mode.
 */
/* hours: rw8, space common, reset unknown; Linux rtc-ds1685 driver, ds1685_rtc_read_time and its probe, which forces 24-hour mode */
#define DS1685_HOURS_OFFSET                          0x4u /* inferred */

/*
 * Hours alarm byte. Probe converts it together with the time hours when it finds 12-hour mode.
 */
/* alarm_hours: rw8, space common, reset unknown; Linux rtc-ds1685 driver, probe conversion of both hours registers */
#define DS1685_ALARM_HOURS_OFFSET                    0x5u /* inferred */

/*
 * Day of the week. Linux reads it on the time path and OpenBSD writes it on the set path; OpenBSD's read path does not read it.
 */
/* day_of_week: rw8, space common, reset unknown; Linux rtc-ds1685 driver, ds1685_rtc_read_time; OpenBSD dsrtc driver, ds1687_settime */
#define DS1685_DAY_OF_WEEK_OFFSET                    0x6u /* inferred */

/*
 * Date of the month.
 */
/* date: rw8, space common, reset unknown; Linux rtc-ds1685 driver, ds1685_rtc_read_time */
#define DS1685_DATE_OFFSET                           0x7u /* inferred */

/*
 * Month.
 */
/* month: rw8, space common, reset unknown; Linux rtc-ds1685 driver, ds1685_rtc_read_time */
#define DS1685_MONTH_OFFSET                          0x8u /* inferred */

/*
 * Year within the century. The century comes from the century byte in bank 1.
 */
/* year: rw8, space common, reset unknown; Linux rtc-ds1685 driver, ds1685_rtc_read_time */
#define DS1685_YEAR_OFFSET                           0x9u /* inferred */

#define DS1685_BANK0_RAM_BYTES                       0x72u /* inferred */
#define DS1685_EXT_RAM_BYTES                         0x80u /* inferred */
#define DS1685_RAM_CLEAR_RECOVERY_MS                 0x96u /* established */
#define DS1685_RAM_TOTAL_BYTES                       0xf2u /* established */

#endif /* DS1685_GEN_H */
