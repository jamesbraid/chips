# DP8573A: the Indigo's real-time clock and battery-backed RAM

The Indigo keeps its time of day in a National Semiconductor DP8573A-family real-time clock: BCD counters from hundredths of a
second to years, compare RAM for an alarm, time save RAM for a rollover-free read, three interrupt sources and a handful of free
RAM bytes. It sits behind the first peripheral controller (HPC1) at physical `0x1fb80e00`, on both the R3000 board (IP12) and the
R4000 board (IP20). The register offsets, bit meanings, grades and `ro`/`w1c` masks are in [`registers.toml`](registers.toml);
the generated reference is [`registers.md`](registers.md). This page holds what the register file cannot say: which part it is,
how software reaches it, what the shipped IP20 PROM and kernel do with it, and what a model must provide for the PROM to get past
its clock check.

Labels follow [AGENTS.md](../../AGENTS.md): **established** is read in full from a shipped object, the public IRIX source or the
data sheet, **inferred** is reasoned, **unknown** is unsettled. Nothing was measured on a board.

## Which part (established for the software contract, unknown for the board)

The brief for this unit said DP8572A. The evidence says the software contract is the **DP8573A**:

- The shipped clock header and structure are named for the 8573 (`dp8573clk.h`, `struct dp8573_clk`), as are the PROM library
  routines. Two kernel comments say "dp8572/8573" without choosing. NetBSD's clock driver for IP12 and IP20 includes `dp8573areg.h`.
- The 8573A data sheet (National 1993 real-time clock handbook, DP8573A section) lists the same address table the header's
  structure follows: main status at 0, mode and control registers at 1 to 4 under a register-select bit, counters at 5 to 11 with
  day of week at 14, compare RAM at 19 to 24, time save RAM at 25 to 29, RAM at 30 and 31.
- The DP8572A section of the same handbook differs in ways no Indigo code touches: a second 31-byte RAM page selected by main
  status bit 7, two Julian-day counters at 12 and 13 (the 8573A has a RAM byte at 12 and an unexplained two-bit byte at 13), two crystal-select
  bits in the mode register, a low-battery flag in the time save control register, a power-fail delay enable bit there, and a
  few more selectable crystals. Shipped software leaves bit 7 of main status clear, never selects a crystal and never touches
  register 12 or 13, so both parts present the same contract to it. A model that implements the 8573A map is sufficient.
- The part number actually soldered on an Indigo board is not stated by any held file. Unknown. Route: a board photograph or parts list.

## Sources

- **Data sheet**: National Semiconductor, 1993 Real Time Clock Handbook, DP8573A section (address table, main status, periodic flag,
  time save control, real time mode, output mode and interrupt control registers, functional description) and the DP8572A section for
  the differences. Held in the reference library as the DP8572A handbook; page references are to the handbook's own numbering
  (8573A pages 2-71 to 2-82, 8572A pages 2-51 to 2-68).
- **IRIX 6.5 public source tree** (read, never copied): `irix/kern/sys/dp8573clk.h` (the register structure and the run, register-select
  and time-save masks), `irix/kern/sys/IP20.h` (`RT_CLOCK_ADDR`, physical `0x1fb80e00`), `irix/kern/ml/IP20.c` (kernel clock routines),
  `stand/arcs/lib/libsk/ml/dp8573.c` (the PROM library's clock routines of a later release than the 4.0.5D image), and
  `stand/arcs/ide/IP20/time/rt_clock.c` (the diagnostic that checks the clock against the 8254).
- **IRIX 6.5 IP20 boot object `kernel.o`** (base media, `usr/cpu/sysgen/IP20boot/`); addresses are `.text` offsets of the object as linked
  for relocation, as on the [INT2 page](../int2/README.md). Symbols: `inittodr` `0x4a3c`, `resettodr` `0x4bd8`, `rtodc` `0x4bf4`, `wtodc`
  `0x4df8` (its two static helpers, the clock read at `0x50e0` and write at `0x518c`, have no symbols), the bad-clock flag helpers at
  `0x5254`, `0x526c` and `0x5288`, `chktimedrift` `0x529c`.
- **PROM 070-8116-004**, SGI Version 4.0.5D Rev A IP20, Aug 19 1992 (sha256 `e6e1f1ed...ba97f82f`), addresses in the `0xbfc00000` window. The
  4.0.5G image (070-8116-005) was **not available** to this reading; see "4.0.5G and IP12".
- **NetBSD sgimips** `dev/dpclock.c` and `dev/dp8573areg.h`: register names, the 4-byte stride and the lane offset (3 on IP12 and IP20),
  and a time-save read sequence. NetBSD matches the clock at `0x1fb80e00` for both boards (and at `0x1fbc0000` for the older IP6/IP10).

## Window and byte lane (established)

The clock occupies 32 four-byte slots from `0x1fb80e00` to `0x1fb80e7f`, inside the `0x1fb80000` block the HPC1 decodes; the HPC1 owns the
decode and bus timing. Chip register `n` is at `0x1fb80e00 + 4n + 3` for a big-endian CPU (the R4000 Indigo runs big-endian; the header's
`CLK_SHIFT` is 0 on the R4000 board and 24 on the older boards, which means the older boards put the register in the *most* significant
byte, an IP6/IP10 layout the R3000 Indigo does not follow, per NetBSD). `registers.toml` offsets are these `4n+3` values from the base.

Software mixes access widths. The PROM and the IRIX kernel read and write the registers with 32-bit loads and stores at `0x1fb80e00 + 4n`
and use the low byte (`andi 0xff`, a `char` truncation, or the written value is at most 0xff). The PROM's start-up RAM test uses byte
accesses at `+4n+3`. Every shipped reader ignores the upper 24 bits of a word read; one shipped sequence does
`status |= 0x40` as a word read-modify-write, so whatever the upper bits read is written back and must be harmless. How the HPC1
turns a word access into the one-byte peripheral cycle is the HPC1 page's contract; this page only needs the low byte of the word to
reach the chip.

IP12 uses the same address and stride (inferred from NetBSD and from the 4.0.1C PROM, below).

## Register map

All offsets are `4n+3`; `registers.md` has the bits. "Both" means the register answers in either register block.

| Chip reg | Offset | Block | Name | Notes |
|---|---|---|---|---|
| 0 | `0x03` | both | main status | interrupt status, power fail, periodic and alarm flags, register-select bit 6 |
| 1 | `0x07` | 1 | real time mode | leap years, 12/24 hour, **start/stop**, standby interrupt |
| 2 | `0x0b` | 1 | output mode | MFO pin function |
| 3 | `0x0f` | 0 | periodic flag | rollover flags, oscillator fail, test enable |
| 3 | `0x0f` | 1 | interrupt control 0 | periodic interrupt enables |
| 4 | `0x13` | 0 | time save control | time save enable |
| 4 | `0x13` | 1 | interrupt control 1 | alarm compare enables, alarm and power-fail enables |
| 5 to 11 | `0x17` to `0x2f` | both | counters | hundredths, seconds, minutes, hours, day of month, month, year (BCD) |
| 12, 13 | `0x33`, `0x37` | both | RAM, and a two-bit byte | unused by Indigo software |
| 14 | `0x3b` | both | day of week | 1 to 7 |
| 15 to 18 | `0x3f` to `0x4b` | | not present | the structure leaves four unused slots; reads unknown |
| 19 to 24 | `0x4f` to `0x63` | both | compare RAM | seconds, minutes, hours, day of month, month, day of week |
| 25 to 29 | `0x67` to `0x77` | both | time save RAM | seconds, minutes, hours, day of month, month |
| 30, 31 | `0x7b`, `0x7f` | both | RAM; RAM or test mode register | |

Registers 1 and 2 have no block 0 meaning (the data sheet lists them N/A there) and registers 3 and 4 swap between the two roles by main
status bit 6. A model needs two register-select-dependent pairs; everything else is flat.

## Behaviour a model has to get right

All established from the data sheet unless marked.

- **Register select.** Main status bit 6 selects block 1 for slots 1 to 4. Both shipped writers set it by read-modify-write and clear it by writing zero
  to main status; the read routines in the kernel and PROM *leave it set* after reading the mode register, which is why every
  sequence begins by writing zero.
- **Counters.** BCD, 10 ms per tick, clocked only while real time mode bit 3 is set. Rollovers: hundredths into seconds at 100, seconds and minutes at 60,
  hours at 24 (or 12 with an AM/PM flag in bit 7), day of week 7 to 1, day of month and month roll to 1. Year is a free two-digit counter. The leap-year field (mode bits 1:0)
  counts years since the last leap year; it increments on 31 December and February has 29 days while it reads zero.
- **Start/stop.** With bit 3 clear the counters hold and are writable. Software clears it, writes the counters and sets it again (both the kernel and
  the PROM do exactly this). Setting bit 3 with the oscillator running also clears the oscillator-fail flag (periodic flag bit 6).
  Power-up state per the data sheet: oscillator-fail flag set, start bit clear, everything else random.
- **Time save (latched read).** While time save control bit 7 is set, the five time save bytes continuously copy seconds, minutes, hours, day of month and month. A write that clears the bit freezes them. Software
  writes 0x80 then 0x00, then reads the frozen bytes and the year counter. The data sheet says to clear the time save bytes first because only the bits the counters
  use are latched; the PROM does, the kernel does not.
- **Compare RAM.** A compare byte only participates when its enable bit in interrupt control 1 is set; with the bit clear the comparison counts as equal and
  the byte is plain RAM. All six enables clear (what IRIX and the PROM write) means no alarm ever fires and all six bytes are RAM.
- **Periodic flags** (periodic flag bits 0 to 5) set at each rollover whether or not enabled, clear on a read of the register. The periodic interrupt flag (main status bit 2)
  and alarm flag (bit 3) clear by writing one; both set whether or not the matching interrupt enable is on.
- **Interrupt output.** Raised by an enabled periodic event, an enabled alarm match or the power-fail input, open-drain; main status bit 0 mirrors it. Whether it goes anywhere on the Indigo is unknown (below).

## What the IRIX kernel does (established, `kernel.o`; header and source agree)

- **Read** (`0x50e0`): write 0 to main status; write 0x80 and then 0 to the time save control register; read the five time save bytes (seconds to month),
  the year counter, then OR 0x40 into main status and read the real time mode byte. The clock counts as running when mode bits 3 or 4 are set (`rtodc` `0x4bf4`:
  `(mode & 0x18) != 0`); otherwise it returns time 0.
- **Write** (`0x518c`): write 0 to main status and to the time save control register; write 0 to the periodic flag register; set main status to 0x40;
  write 0x80 to interrupt control 1 and 0 to the output mode register; clear mode bits 3 and 4; write seconds, minutes, hours, day of month, month and year
  (registers 6 to 11) as BCD; write the mode register as `0x18 | (calendar year mod 4)`. The hundredths counter is not written. The year counter holds years since 1970.
  Hours are written as 24-hour BCD with mode bit 2 clear.
- **Bad-clock flag** (`0x5254`, `0x526c`, `0x5288`): bit 0 of the hours compare RAM byte (offset `0x57`). `inittodr` (`0x4a3c`) sets it (message "lost battery backup clock") when the clock reads before a fixed 1988 floor and is not older than the file system time; a successful `wtodc` clears it. This is the only battery-RAM use found in the kernel.
- **Drift check** `chktimedrift` (`0x529c`): the kernel compares `rtodc` to its own time and slews when they differ by more than two seconds.

Nothing in the kernel writes interrupt control 0, the compare enables other than the constant 0x80, or reads main status flags 1 to 3.

## What the 4.0.5D PROM does with the clock

Three pieces of code touch `0x1fb80e00..0x1fb80e77`. All addresses are PROM addresses.

### 1. Start-up RAM test (`0xbfc029f8`, established)

Part of the early power-on test sequence: reads the byte at `0x1fb80e57` (hours compare RAM), saves it, writes `0xa5`, then reads and writes `0x5a` to `0x1fb80e5b`
(day-of-month compare RAM), reads both back, and restores the saved bytes. If either read-back differs it sets bit 2 (value 4) in a local result mask (register `t7`); the mask's
reporting path was not followed. Required of a model: the two compare RAM bytes hold what is written, byte accesses at `4n+3`, whatever state main status is in.

### 2. The clock routine (`0xbfc2c73c`, established)

One routine, argument 0 reads and argument 1 writes, with the same register sequences as the kernel's, plus:

- **Read** first writes 0 to the five time save bytes (`0x1fb80e64` to `0x1fb80e74`), then writes 0 to main status, 0x80 and 0 to time save control, reads the five time save bytes,
  the year counter, sets main status bit 6 and reads the mode byte.
- **Write** is the kernel's sequence with the counters written as hundredths, seconds, minutes, hours, day of month, month, year (registers 5 to 11, seven bytes), then
  the mode register as `0x18 | (year counter & 3)`. The year it writes is always 0 (1970): see `reset to the epoch` below. (The `& 3` leap field is zero for 1970; per the data sheet's leap table that
  says the current year is a leap year, which is wrong for 1970 and would matter only if the clock ran through February 1970. Inferred, harmless to this model.)

### 3. Get the time of day (`0xbfc2c390`, established) and the "not moving" test (`0xbfc2c878`, established)

The time of day is read through a three-level call chain: the PROM's seconds-since-1970 routine (`0xbfc3616c`) calls the time-structure routine (`0xbfc0a5fc`), which calls the get-time routine
(`0xbfc2c390`); the table of firmware entry points also holds the time-structure routine (data word at `0xbfc53390`) and the seconds routine (`0xbfc540e0`). The get-time routine
reads the clock (above) and then:

1. If mode bits 3 and 4 are both clear, the clock is not running: print `Initializing tod clock.` and reset the clock to the epoch (next step), then try again once.
2. Otherwise, if a RAM flag (`0xa87456a0`) is zero, run the **motion test** (`0xbfc2c878`): write 0 to main status, read the low byte of the **hundredths counter**
   (`0x1fb80e14` as a word, which is the hundredths register at `0x1fb80e17` as a byte), then re-read it up to 1,000,000 times (several million instructions), succeeding as soon as the byte differs from the
   first read. On success the flag is set to 1 and never tested again; on failure the flag stays 0, and the routine reports "not moving", which takes the same path as step 1 (message, reset to epoch, one more try).
3. A second consecutive failure prints `Can't set tod clock.` and returns with the time structure unfilled. The structure is not validated, so the caller sees whatever was there.
4. On success the BCD fields are converted (hours with `& 0x3f` digit decode, year plus 1970) and checked: second and minute 0 to 59, hour 0 to 23, day 1 to 31, month 1 to 12, year 1970 to 2069.
   Any failure resets the clock to the epoch, which prints the `setting` line.

**Reset to the epoch** (`0xbfc2c580`, established): the argument is always 0. It formats 1970-01-01 00:00:00 from the seconds count, prints
`setting secs=%d min=%d hour=%d day=%d month=%d year=%d` (the strings are at `0xbfc53f14`), and calls the clock write routine, so the epoch is stored as hundredths 0, seconds 0, minutes 0, hours 0, day 1, month 1, year 0, then
started.

### What the loop waits for, and why a QEMU run looked hung

The routine at `0xbfc2c878` waits for **the hundredths counter to change**. It does not wait for a seconds change and it does not read a status bit. It reads only the byte at `0x1fb80e17`
(through the word at `0x1fb80e14`), so a model that returns a constant there, or maps the window as plain RAM, fails the test every time.

The failure is bounded per call but not overall: each time the PROM asks for the time, the motion test runs afresh (the flag stays 0), costs up to a million
reads per attempt, prints its messages and writes the epoch again. Several PROM paths ask for the time repeatedly, so a clock that never moves looks
like an endless poll of `0x1fb80e14`. Those paths include the start-up sequence (`0xbfc05fe4`) and the disk and SCSI retry waits at `0xbfc04884` to `0xbfc049f0` (inferred to be a ready wait: it records the
time plus 70 and repeats a half-second delay and a command while the time is below it), which wait on a seconds counter that never advances. This reading is from the disassembly; no QEMU run was
made for this page, so the "forever" is explained but not reproduced.

A model satisfies the PROM when:

1. The hundredths register changes on its own while mode bit 3 is set, at 10 ms of **guest-visible** time or faster (a read of any fixed value, or a counter that ticks only on guest writes, fails). A million
   polling reads take far longer than 10 ms of emulated time at the CPU's clock, so a tick source on the emulated virtual clock passes.
2. The seconds register and the rest advance with it (the SCSI waits need real elapsed seconds).
3. Main status select works, so that writing 0 then reading the counters and time save bytes returns the counters.
4. The time save latch works (write 0x80 then 0 to the time save control register freezes the five bytes); a model with plain RAM there returns zeros, month 0 fails validation and the clock is reset to the epoch on every call.
5. After the PROM writes the epoch the registers read back what was written (mode `0x18`, leap field 0, counters 1970-01-01).

A model that starts running with a valid calendar (mode `0x18` or `0x1a`, counters at a current date) skips the "Initializing" path entirely and only the motion test remains. A model that starts
with everything zero takes the epoch path once. Either passes.

## What lives in the battery RAM

- The **PROM keeps nothing** of its own in the clock chip beyond the transient RAM test above. The PROM's environment variables and the Ethernet address are in the separate serial
  EEPROM, reached through the HPC1 auxiliary register (see the PROM page), not in the clock.
- **IRIX's bad-clock flag**, bit 0 of the hours compare RAM byte. Survives the PROM's RAM test, which restores the byte.
- The remaining compare RAM bytes (when their enables are clear), the time save RAM (when time save is off), the RAM bytes at registers 12, 30 and 31 and the RAM bits in the mode and control registers are free battery RAM that no Indigo software
  uses. A model that keeps all of it with the counters across restarts is adequate.

## Interrupt routing (unknown)

The chip's interrupt output (INTR) and its programmable second output (MFO) are open-drain. Neither the INT2 page nor the interrupt routing table names a clock source. What is known:

- IRIX and the PROM both write interrupt control 1 as `0x80` (power-fail interrupt enabled, alarm off) and set mode bit 4, which the data sheet says keeps the power-fail enable alive in standby.
  Nothing writes interrupt control 0, so the periodic interrupts are enabled or not according to a power-up value the data sheet calls random.
- INT2 local 1 bit 5 is an AC-failure input whose handler prints "Power failure detected" ([the routing table](../../platforms/ip20/interrupts.md)). A power-fail interrupt from this chip
  is a candidate source, but there is also the case of a separate AC-failure comparator, and no file settles it. Inferred at best; unknown.
- The clock tick, profiling clock and timers all come from the 8254 (INT2), never from this chip; the 8254 is the time base the diagnostic checks this chip against.

A model that never raises INTR is consistent with every shipped reader. A qtest cannot discriminate routing.

## IP12 and 4.0.5G

- **IP12.** The R3000 Indigo PROM 070-8086-002 (4.0.1 Rev C, sha256 `5fdc6b65...`) contains the same access routine pair (clock routine at `0xbfc0b80c`, read path clearing the five
  time save bytes as the IP20 routine does) and the same RAM test (the `0xe57` byte at `0xbfc02c8c`), so the window, stride and register use are the same. Inferred: the routine was
  read for the register sequence only, not in full, and the IP12 kernel was not read. NetBSD uses the same window and lane for both boards.
- **4.0.5G.** The 070-8116-005 image was not held for this page. The public IRIX 6.5 source of the PROM's library clock routines counts failures and returns after six; if 4.0.5G has that change, an unmoving clock stops
  printing messages after six get-time calls instead of repeating forever. Unknown whether 4.0.5G has that change.

## What a QEMU qtest can discriminate

The register contract tests worth writing (each is one line of the table above):

1. Byte read-write at `4n+3` of a compare RAM byte holds the value; the same through a word access at `4n`.
2. Main status bit 6 swaps register 3 between the periodic flag and interrupt control 0, and register 4 between time save control and interrupt control 1; register 1 and 2 exist only with bit 6 set.
3. Main status bits 2 and 3 clear only on a one written; bits 0 and 1 are not writable.
4. With mode bit 3 set the hundredths byte changes within 20 ms and carries into seconds at 100; with it clear nothing moves and the counters are writable.
5. Time save: write 0x80 then 0; five bytes equal the counters at that instant and stay put while the counters advance.
6. A periodic flag read clears bits 0 to 5.
7. The oscillator-fail flag is set at power-up and clear after mode bit 3 is set with the oscillator running.
8. Compare RAM with all six enables clear never raises main status bit 3.
9. The PROM's sequence end to end: epoch write, mode readback `0x18`, motion test passes.

## Unknown

- The board's part number (8572A or 8573A) and the crystal frequency (the 8573A takes 32.768 kHz only; software never selects another).
- What reading registers 15 to 18 (`0x3f` to `0x4b`) or the unexplained register 13 returns, and the upper 24 bits of a word read.
- Power-up contents of interrupt control 0 and the periodic flag test bit; the data sheet says random.
- INTR, MFO and PFAIL wiring; whether the power-fail interrupt reaches INT2 local 1 bit 5.
- Whether 4.0.5G changes the get-time routine.
- Reset (power-on) values of the counters on a board whose battery has gone flat.

Routes: a board photograph for the part number; the 4.0.5G image and the IP12 kernel for the last two software items; a boot capture from a flat-battery Indigo for the power-up contents. Hardware residue: the three read-only
items would need a read of an unwritten board register, which needs agreement first.
