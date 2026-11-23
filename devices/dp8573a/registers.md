<!-- generated from devices/dp8573a/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 4 -->
<!-- input sha256 3d5cf3c64ca396076a616c64c2650a09e803487e15909b32eb1f6fd64cc9c1d7 -->

# National DP8573A real-time clock and battery-backed RAM (Indigo, R3000 and R4000 boards)

The Indigo's time-of-day chip, reached through the first peripheral controller at physical 0x1fb80e00. Offsets here are byte addresses from that base and name the byte a big-endian CPU addresses: each chip register sits in the low byte lane of a 4-byte slot, so register n is at offset 4n+3 (a little-endian CPU addresses the same register 3 bytes lower). Registers 1 to 4 exist twice, selected by the register-select bit of the main status register, which are the dp8573a_rs0 and dp8573a_rs1 spaces below; everything else is in common. IRIX comments call the part a DP8572 or DP8573 and name its header and structure after the 8573; the 8573A data sheet's address table is the layout software uses, and the 8572A adds a second page, two Julian-day counters and a page-select bit that no Indigo software touches. The board's exact part number is not stated by any shipped file. Grades: established means read in the IRIX source, the kernel object or the 4.0.5D PROM (the README cites addresses) or stated by the data sheet; inferred means a reasoned reading; unknown means nothing held settles it. Nothing was measured on a board. The prose and the behaviour a model needs are in devices/dp8573a/README.md.

Unit `dp8573a`, macro prefix `DP8573A`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| dp8573a_common | byte | Registers that answer whichever register block is selected: main status, the clock counters, compare RAM, time save RAM and the general RAM bytes. |
| dp8573a_rs0 | byte | Register block 0 (main status bit 6 clear): the periodic flag and time save control registers, at the slots of chip registers 3 and 4. |
| dp8573a_rs1 | byte | Register block 1 (main status bit 6 set): real time mode, output mode and the two interrupt control registers, at the slots of chip registers 1 to 4. |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `status` | 0x3 | rw | 8 |  | dp8573a_common | unknown | established |  |
| `hundredths` | 0x17 | rw | 8 |  | dp8573a_common | unknown | established |  |
| `seconds` | 0x1b | rw | 8 |  | dp8573a_common | unknown | established |  |
| `minutes` | 0x1f | rw | 8 |  | dp8573a_common | unknown | established |  |
| `hours` | 0x23 | rw | 8 |  | dp8573a_common | unknown | established |  |
| `day_of_month` | 0x27 | rw | 8 |  | dp8573a_common | unknown | established |  |
| `month` | 0x2b | rw | 8 |  | dp8573a_common | unknown | established |  |
| `year` | 0x2f | rw | 8 |  | dp8573a_common | unknown | established |  |
| `ram_0c` | 0x33 | rw | 8 |  | dp8573a_common | unknown | established |  |
| `reg_0d` | 0x37 | rw | 8 |  | dp8573a_common | unknown | unknown |  |
| `day_of_week` | 0x3b | rw | 8 |  | dp8573a_common | unknown | established |  |
| `cmp_seconds` | 0x4f | rw | 8 |  | dp8573a_common | unknown | established |  |
| `cmp_minutes` | 0x53 | rw | 8 |  | dp8573a_common | unknown | established |  |
| `cmp_hours` | 0x57 | rw | 8 |  | dp8573a_common | unknown | established |  |
| `cmp_day_of_month` | 0x5b | rw | 8 |  | dp8573a_common | unknown | established |  |
| `cmp_month` | 0x5f | rw | 8 |  | dp8573a_common | unknown | established |  |
| `cmp_day_of_week` | 0x63 | rw | 8 |  | dp8573a_common | unknown | established |  |
| `save_seconds` | 0x67 | rw | 8 |  | dp8573a_common | unknown | established |  |
| `save_minutes` | 0x6b | rw | 8 |  | dp8573a_common | unknown | established |  |
| `save_hours` | 0x6f | rw | 8 |  | dp8573a_common | unknown | established |  |
| `save_day_of_month` | 0x73 | rw | 8 |  | dp8573a_common | unknown | established |  |
| `save_month` | 0x77 | rw | 8 |  | dp8573a_common | unknown | established |  |
| `ram_1e` | 0x7b | rw | 8 |  | dp8573a_common | unknown | established |  |
| `ram_test` | 0x7f | rw | 8 |  | dp8573a_common | unknown | established |  |
| `periodic_flag` | 0xf | rw | 8 |  | dp8573a_rs0 | unknown | established |  |
| `timesave_ctl` | 0x13 | rw | 8 |  | dp8573a_rs0 | unknown | established |  |
| `rt_mode` | 0x7 | rw | 8 |  | dp8573a_rs1 | unknown | established |  |
| `output_mode` | 0xb | rw | 8 |  | dp8573a_rs1 | unknown | established |  |
| `int0_ctl` | 0xf | rw | 8 |  | dp8573a_rs1 | unknown | established |  |
| `int1_ctl` | 0x13 | rw | 8 |  | dp8573a_rs1 | unknown | established |  |

### Register `status`

Always present, whichever block is selected. Bit 0 is the interrupt status, high while the chip's interrupt output is asserted (read only). Bit 1 is the power-fail status, which follows the PFAIL input and cannot be written. Bit 2 is the periodic interrupt flag and bit 3 the alarm interrupt flag; both are cleared by writing a one to them and are set whether or not the interrupt is enabled. Bits 4, 5 and 7 are general RAM bits on the 8573A. Bit 6 selects register block 1. IRIX and the PROM write zero to select block 0 before every access sequence and set bit 6 with a read-modify-write (the PROM and kernel read routines leave it set when they finish). A qtest can discriminate: bit 6 flips which of two registers answers at the slot of register 3, bits 2 and 3 clear only on a one written, bits 0 and 1 ignore writes.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `ram7` | established |  |  | General RAM bit on the 8573A. On the 8572A this is the page select; no Indigo software sets it. |
| 6 | `register_select` | established |  |  | Selects register block 1 (set) or block 0 (clear) for the slots of registers 1 to 4. |
| 5 | `ram5` | established |  |  | General RAM bit on the 8573A. |
| 4 | `ram4` | established |  |  | General RAM bit on the 8573A. |
| 3 | `alarm` | established |  |  | Alarm (time compare) interrupt flag; write one to clear. |
| 2 | `periodic` | established |  |  | Periodic interrupt flag; write one to clear. |
| 1 | `power_fail` | established |  |  | Power-fail status from the PFAIL pin. Read only. |
| 0 | `interrupt_status` | established |  |  | Interrupt output pending. |

### Register `hundredths`

Hundredths and tenths of a second, two BCD digits, 00 to 99, incrementing every 10 ms while the clock runs. The PROM's first read of the clock after reset polls this byte and requires it to change (see the README). A qtest can discriminate: with the start bit set the byte changes within a few tens of milliseconds and wraps from 99 to 00 as it carries into seconds.

### Register `seconds`

Seconds, BCD 00 to 59. Written by IRIX and the PROM only with the clock stopped.

### Register `minutes`

Minutes, BCD 00 to 59.

### Register `hours`

Hours, BCD. In 24-hour mode (real time mode bit 2 clear, which is how IRIX and the PROM run the chip) the range is 00 to 23 and bits 5:4 are the tens digit. In 12-hour mode the range is 01 to 12 and bit 7 is the AM/PM flag (PM set).

### Register `day_of_month`

Day of month, BCD 01 to 28/29/30/31. Rolls over to 01.

### Register `month`

Month, BCD 01 to 12. Rolls over to 01.

### Register `year`

Year, BCD 00 to 99. IRIX and the PROM store years since 1970 here, not a century year. The PROM accepts a clock whose year plus 1970 is below 2070.

### Register `ram_0c`

A general RAM byte. Not touched by any shipped Indigo code.

### Register `reg_0d`

The data sheet's address table shows only bits 0 and 1 present and gives no function, and the page text does not describe them. No shipped Indigo code touches this byte. Whether the other bits read as zero is not stated.

### Register `day_of_week`

Day of week counter, 1 to 7, rolls over to 1. The chip does not derive it from the date; software sets it. IRIX never writes it (its time computation ignores it); NetBSD writes it.

### Register `cmp_seconds`

Seconds compare RAM. Compared with the seconds counter only when interrupt control 1 bit 0 is set; otherwise a free RAM byte.

### Register `cmp_minutes`

Minutes compare RAM, same rules as the seconds one with interrupt control 1 bit 1.

### Register `cmp_hours`

Hours compare RAM, a free RAM byte while interrupt control 1 bit 2 is clear. IRIX keeps its bad-clock flag in bit 0 of this byte (set when the kernel finds the date lost, cleared by a successful set). The PROM's start-up RAM test saves the byte, writes a5, reads it back and restores it. A qtest can discriminate: the byte holds any written value and survives with the clock running.

### Register `cmp_day_of_month`

Day-of-month compare RAM. The PROM's RAM test writes 5a here and restores it.

### Register `cmp_month`

Month compare RAM.

### Register `cmp_day_of_week`

Day-of-week compare RAM.

### Register `save_seconds`

Time save RAM, seconds. While time save control bit 7 is set this byte follows the seconds counter; clearing that bit freezes it, which is how software reads the clock without a rollover. The PROM zeroes all five time save bytes before latching (the data sheet says to clear unused bits first); the kernel does not.

### Register `save_minutes`

Time save RAM, minutes.

### Register `save_hours`

Time save RAM, hours.

### Register `save_day_of_month`

Time save RAM, day of month.

### Register `save_month`

Time save RAM, month. There is no year in time save RAM; software reads the year counter directly after the latch.

### Register `ram_1e`

A general RAM byte. Not touched by any shipped Indigo code.

### Register `ram_test`

A general RAM byte that doubles as the chip's test-mode register while the test-enable bit of the periodic flag register is set. The data sheet says to write zero here in a start-up sequence that first sets that bit. No shipped Indigo code touches it; a model can treat it as RAM.

### Register `periodic_flag`

Block 0. Bits 0 to 5 are the six periodic event flags: minutes, tens of seconds, seconds, 100 ms, 10 ms and 1 ms rollovers. They are set whether or not the matching interrupt is enabled and are cleared by reading the register. Bit 6 reads as the oscillator-fail flag (set on initial power-up and after an oscillator failure, cleared by starting the clock with the oscillator running) and, when written, selects battery-backed operation (zero) or single-supply operation (one). Bit 7 is the test-mode enable; software must keep it clear. IRIX and the PROM write zero here once while setting the clock, which asks for battery-backed operation and clears test mode. A qtest can discriminate: bits 0 to 5 are clear after a read, bit 6 is high before the first start of the clock after power-up and low after.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `test_enable` | established |  |  | Test mode enable; keep clear. |
| 6 | `osc_fail_or_single_supply` | established |  |  | Read: oscillator failed. Write: zero selects battery-backed mode, one selects single-supply mode. |
| 5 | `ms` | established |  |  | 1 ms tick. |
| 4 | `ten_ms` | established |  |  | 10 ms digit rolled over. |
| 3 | `hundred_ms` | established |  |  | 100 ms digit rolled over. |
| 2 | `second` | established |  |  | Seconds counter rolled over. |
| 1 | `ten_second` | established |  |  | Tens-of-seconds digit rolled over. |
| 0 | `minute` | established |  |  | Minutes counter rolled over. |

### Register `timesave_ctl`

Block 0. Bit 7 is the time save enable: while set the time save RAM follows the clock, and a write that clears it freezes the clock's value there. Bits 0 to 5 are general RAM; bit 6 is not present and reads zero. IRIX and the PROM read the clock by writing 80 then 00 and then reading the time save bytes; the kernel's set sequence writes zero here. A qtest can discriminate: write 80 then 00 leaves the five time save bytes equal to the counters at that instant and unchanged afterwards.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `enable` | established |  |  | Time save enable. |
| 6 | `absent` | established |  |  | Not present on the 8573A; reads zero. |
| 5:0 | `ram` | established |  |  | General RAM bits. |

### Register `rt_mode`

Block 1. Bits 1:0 are the leap-year counter: years since the last leap year, 0 meaning this year is one. Bit 2 selects 12-hour (set) or 24-hour (clear) mode; IRIX and the PROM leave it clear. Bit 3 starts the clock when set and holds the counters stopped when clear; while the oscillator has not started the chip holds it clear, and it clears itself on an oscillator failure. Bit 4 keeps the interrupt configuration alive in standby; both programs set it with bit 3 (run bits 0x18). Bits 7:5 are general RAM on the 8573A (crystal select bits on the 8572A). The data sheet requires clearing bit 3 before writing the counters; IRIX and the PROM do exactly that and then write the mode back with bit 3 set and the leap field from the year. A qtest can discriminate: the counters advance only while bit 3 is set, and a read of the clock sequence returns the mode byte with bits 3 and 4 as written.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:5 | `ram` | established |  |  | General RAM bits on the 8573A. |
| 4 | `int_standby` | established |  |  | Interrupt operation in standby. |
| 3 | `run` | established |  |  | Clock start (set) or stop (clear). |
| 2 | `hour12` | established |  |  | Set for 12-hour mode with an AM/PM bit; clear for 24-hour mode. |
| 1:0 | `leap` | established |  |  | Years since the last leap year. |

### Register `output_mode`

Block 1. Bit 7 chooses what the MFO pin carries: the power-fail interrupt (clear) or the buffered crystal oscillator (set). Bits 6:0 are general RAM. IRIX and the PROM write zero while setting the clock. Where MFO is wired on the Indigo is unknown.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `mfo_oscillator` | established |  |  | MFO pin carries the buffered oscillator instead of the power-fail interrupt. |
| 6:0 | `ram` | established |  |  | General RAM bits. |

### Register `int0_ctl`

Block 1. Bits 0 to 5 enable the six periodic interrupts (minutes, tens of seconds, seconds, 100 ms, 10 ms, 1 ms), which raise main status bit 2 and the interrupt output; bits 6 and 7 are general RAM. Shipped Indigo code never writes this register (the kernel's clock tick comes from the 8254 timer), so what it holds at power-up decides whether the chip interrupts; the data sheet says its contents are random until written.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:6 | `ram` | established |  |  | General RAM bits. |
| 5 | `ms` | established |  |  | 1 ms periodic interrupt enable. |
| 4 | `ten_ms` | established |  |  | 10 ms periodic interrupt enable. |
| 3 | `hundred_ms` | established |  |  | 100 ms periodic interrupt enable. |
| 2 | `second` | established |  |  | Seconds periodic interrupt enable. |
| 1 | `ten_second` | established |  |  | Tens-of-seconds periodic interrupt enable. |
| 0 | `minute` | established |  |  | Minutes periodic interrupt enable. |

### Register `int1_ctl`

Block 1. Bits 0 to 5 enable the compare of seconds, minutes, hours, day of month, month and day of week against the matching compare RAM byte: a clear bit forces that comparison to always-equal and frees the RAM byte. Bit 6 lets an alarm match (all enabled compares equal) raise the interrupt output; bit 7 enables the power-fail interrupt and the low-battery circuit. IRIX and the PROM write 80 whenever they set the clock, which disables every compare and the alarm interrupt and leaves only the power-fail interrupt enabled. A qtest can discriminate: with bits 0 to 5 clear the compare RAM never raises main status bit 3.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `power_fail_int_enable` | established |  |  | Power-fail interrupt enable. |
| 6 | `alarm_int_enable` | established |  |  | Alarm match raises the interrupt output. |
| 5 | `cmp_day_of_week` | established |  |  | Compare day of week. |
| 4 | `cmp_month` | established |  |  | Compare month. |
| 3 | `cmp_day_of_month` | established |  |  | Compare day of month. |
| 2 | `cmp_hours` | established |  |  | Compare hours. |
| 1 | `cmp_minutes` | established |  |  | Compare minutes. |
| 0 | `cmp_seconds` | established |  |  | Compare seconds. |

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `BAD_CLOCK_FLAG` | 0x1 | established |  | Bit of the hours compare RAM byte the IRIX kernel uses as its software flag that the clock date is not trustworthy. |
| `EPOCH_YEAR` | 0x7b2 | established |  | Calendar year the year counter counts from in both IRIX and the PROM: the counter holds BCD years since 1970. |
| `INT1_INIT` | 0x80 | established |  | Interrupt control 1 value both IRIX and the PROM write: only the power-fail interrupt enable set, all alarm compares off. |
| `LANE_OFFSET` | 0x3 | established |  | Byte of each 4-byte slot that carries the register on a big-endian CPU. The header shifts word accesses by 0 on the R4000 board and by 24 on the older R3000 and 4D-generation boards. |
| `RAM_TEST_A` | 0xa5 | established |  | Pattern the PROM writes to the hours compare RAM byte in its start-up RAM test. |
| `RAM_TEST_B` | 0x5a | established |  | Pattern the PROM writes to the day-of-month compare RAM byte in the same test. |
| `RT_RS` | 0x40 | established |  | Main status bit 6, register select, as the header names it. |
| `RT_RUN` | 0x18 | established |  | Real time mode bits the IRIX header calls run: start (bit 3) plus interrupt-in-standby (bit 4). The kernel and PROM treat a clock whose mode register has neither bit set as not running. |
| `RT_TIMSAV_ON` | 0x80 | established |  | Time save control bit 7, time save enable. |
| `WINDOW_SIZE` | 0x80 | established |  | Bytes the 32 four-byte slots occupy, from the clock base. |
