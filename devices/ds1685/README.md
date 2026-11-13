# DS1685/DS1687 real-time clock and battery-backed RAM

The Octane and Octane2 system boards (IP30) carry a Dallas real-time clock with 242 bytes of
battery-backed user RAM. The sources call the die DS1685 and the same die in its sealed package
(with the crystal and cell) DS1687. The sources place it behind two byte-wide ports on the IOC3's byte
bus. This page uses DS1685 for the die.

The register contract that the sources state is in `devices/ds1685/registers.toml`, and its generated
reference is `devices/ds1685/registers.md`. This page holds what that unit does not carry: bank and update
behaviour, the driver sequences, the interrupt and power paths, the RAM-clear rules and what is
still unknown. The bit positions of Register A to Register D, of Register B, and of the bank-1
control bytes other than the three named in the unit are not transcribed here.

Each fact carries one of the labels used across this repository. **Established** means the
vendor datasheet states it, as the sources quote it. **Inferred** means a public driver or a
reasoned reading of one does it, or the fact rests on a driver's use of a byte. **Unknown** means
not settled, with the route that would settle it. No fact here was measured on a board.

## Sources

- **Maxim DS1685/DS1687 datasheet**, document 19-5215, revision 10/12. Page numbers below are the
  ones the sources give. They come from the earlier written summary this import drew on, and the
  PDF itself was not reopened for this page. A page cited off by a few is the first thing to check.
- **Linux `drivers/rtc/rtc-ds1685.c`** and `include/linux/rtc/ds1685.h`, mainline v7.2-rc7. The
  IP30 platform data is in `drivers/mfd/ioc3.c` and the IP32 platform data in
  `arch/mips/sgi-ip32/ip32-platform.c`.
- **OpenBSD `sys/arch/sgi/dev/dsrtc.c`**, `dsrtcvar.h` and `power.c`, branch 7.9; the bit names
  come from `sys/dev/ic/ds1687reg.h`.
- **NetBSD `sys/dev/ic/ds1687reg.h`**, a third transcription of the register map, used as a cross-check
  on names and region sizes.
- **chips pages**: [bridge-family.md](../bridge/family.md) (Octane Bridge interrupt pin 6) and
  [coverage-mace.md](../mace/coverage.md) and [mace/README.md](../mace/README.md) (the calendar clock on
  the O2's MACE, a directly mapped part of the same family).

The driver facts above are as the earlier summary recorded them. None of the trees was reopened for
this import.

## Placement

- **Established**: the sealed DS1687 carries the crystal and cell; the die is the same (Maxim, as quoted).
- **Inferred**: the part sits on the Octane and Octane2 system board behind the IOC3's byte bus. Linux
  adds the clock as a cell of the IOC3 driver, and OpenBSD's power driver matches the Octane.
- **Unknown**: how far up its byte-bus span each select answers, and how the Bridge's byte-lane
  correction maps a driver's address onto the part. The sources report that a driver's access lands
  three bytes above the address it names. That was not checked here. See the open questions.
- **Inferred**: on the O2 the same part is directly mapped through MACE, with a register step of 0x100.
  That path is covered in [coverage-mace.md](../mace/coverage.md) and the MACE README, not here.

## Banks and the update cycle

- **Inferred**: Register A selects the bank. Linux's `ds1685_rtc_switch_to_bank1` and
  `ds1685_rtc_switch_to_bank0` both read the register, change the bank bit and write it back, so
  every other bit survives. The probe sets the oscillator and selects bank 1 in one write.
- **Inferred**: the update-in-progress bit of Register A is read-only, so a write that changes the
  other bits must not change it. Writing back a value just read must not set it.
- **Inferred**: OpenBSD selects bank 1 in its clock routines and never selects bank 0 again. Its power
  driver then reads and writes the extended control byte through helpers that do no bank management.
  The bank therefore stays where software left it between accesses, and the sources do not say the part
  resets it.
- **Inferred**: Linux's time read sets SET in Register B, switches to bank 1, polls the increment bit
  (bit 6 of the extended control byte at 0x4A) until it clears, reads the calendar bytes and the
  century, switches back to bank 0 and clears SET. The increment bit must read zero outside an update.
  Linux polls it without a bound, so a bit stuck at one hangs the guest in probe.
- **Established**: when SET goes high it clears UIE (Maxim, page 12). Linux sets SET on every time read
  and alarm access, so an update-ended interrupt enabled by software is cleared by the next read. The
  IP30 platform data declares no UIE support, so Linux never meets this.
- **Inferred**: OpenBSD's read path differs. It selects bank 1, reads the data-mode bit, polls the
  update-in-progress bit of Register A instead of the increment bit, reads six fields and the century,
  and sets no SET. Its set path does set SET, forces 24-hour mode, writes eight fields including the day
  of the week and restores Register B.

## Driver probe (Linux, in order)

Each step is a read-modify-write of the named register.

1. Register A: set DV1 if clear, which starts the oscillator; clear DV2 and the rate-select bits; set DV0,
   which selects bank 1; write it back in one access.
2. Set E32K in the extended enable byte at 0x4B.
3. Set SET in Register B.
4. Poll the increment bit at 0x4A until it clears. Unbounded.
5. Register B: set or clear the data-mode bit from the platform's BCD choice, clear DSE, force 24-hour
   mode, converting both hours bytes first if the part was in 12-hour mode.
6. Clear SET.
7. Warn, and continue, if VRT in Register D is clear or VRT2 in 0x4A is clear.
8. Clear PIE, AIE and UIE; read Register C to clear PF, AF and UF; clear RIE, WIE and KSE in 0x4B;
   clear the wake-up, RAM-clear and kickstart flags in 0x4A; then set KSE alone.
9. Register the interrupt handler, then switch to bank 0.

Probe never reads the model byte, so a wrong model value probes without complaint. Only the sysfs and
proc views show it.

## Calendar format, hours and the century

- **Inferred**: the data-mode bit decides binary or BCD, and a driver must honour the bit on every field.
  The IP30 platform data asks for binary (`bcd_mode = false`). The IP32 data asks for BCD. OpenBSD reads
  the bit and converts to match. Both forms are real uses.
- **Inferred**: Linux forces 24-hour mode at probe and converts both the time hours and the alarm hours
  first if the part was in 12-hour mode.
- **Established**: the DSE bit selects the pre-2007 United States daylight-saving rule: the first Sunday
  in April and the last Sunday in October (Maxim, page 12). Linux clears DSE, because the rule is obsolete.
- **Inferred**: the century is the byte at 0x48 in bank 1. Linux computes the year as the year byte plus
  the century times 100, and restricts the RTC core to 2000 through 2099. OpenBSD does the same arithmetic
  without the restriction.

## Interrupts

- **Inferred**: Linux's handler reads Register B and Register C. If the interrupt flag is set but none of
  PF, AF or UF is, it is one of the three extended sources, and it goes to bank 1 to find which. It leaves
  the part in bank 0. It is a shared, threaded, one-shot handler, and it returns "not mine" whenever it
  finds no event of the classic kind. On a level line an assertion with no flag and enable actually set
  produces a handler that neither handles nor clears it, which is a storm.
- **Inferred, Linux's account only**: on IP30 the clock is added without the IOC3's interrupt domain, so
  its interrupt number is a Bridge interrupt taken whole. Linux asks the Bridge for pin 6 by mapping
  slot 6, pin 0, and the IP30 table leaves that route at its default. So Linux puts the clock on Bridge
  interrupt pin 6 and the IOC3 on pin 4. Slot 6 is a lookup key and no PCI slot is populated.
- **Established, OpenBSD**: the Octane Bridge's interrupt pin 6 is the power-switch signal, wired to a HEART
  interrupt bit ([bridge-family.md](../bridge/family.md), item 7). That agrees with Linux's pin 6 and suggests
  the power path runs pin 6 to HEART. Neither source says the clock drives the pin.
- **Inferred, OpenBSD**: the power button reaches the kernel through HEART's power interrupt, not through
  the clock. Its handler clears the HEART condition first and then reads the clock's kickstart flag.
- **Reading**: both kernels agree that the clock records the event and differ on which line carries it.
  A clock output that nothing unmasks is invisible, so OpenBSD's behaviour does not show the clock's
  line is absent.

## Power, kickstart, wake-up and RAM clear

- **Established**: PAB, bit 3 of 0x4A. Zero makes the PWR pin active low. One makes it high impedance
  (Maxim, page 21). Linux's power-off path writes PAB as one, which never returns.
- **Inferred**: Linux's power-off path forces the oscillator on and the countdown chain out of reset,
  checks VRT2, enables ABE, WIE and KSE when the auxiliary battery is good, writes PAB and spins. It leaves the part in bank 1.
- **Established**: a low-going transition on the KS pin while the system is unpowered drives PWR low to
  switch the supply on and sets KF. With VCC present the same pin is an interrupt input (Maxim, pages 5
  and 19 to 20). The vendor says the pin is meant for "such events as a key closure or modem-ring detect".
- **Inferred**: on the Octane the KS pin is the power button. Linux treats a kickstart as a button press:
  it clears KSE, clears KF, sleeps 500 ms, re-enables KSE, then calls the platform's pre-power-off hook
  or powers down. OpenBSD clears KF to debounce a press. Two kernels support this identification, and
  the vendor does not state it.
- **Established**: the wake-up alarm matches the date alarm at 0x49 together with the hours, minutes and
  seconds alarm bytes. It drives PWR low and sets WF, whatever AIE says (Maxim, page 19).
- **Established**: a low-going transition on RCLR, with RCE set and RF clear, sets all 242 bytes of user
  RAM to ones and sets RF. An uncleared RF blocks the next clear. All accesses are locked out for a
  minimum recovery time tREC of 150 ms (Maxim, pages 5 and 20 and the electrical table).
- **Inferred**: Linux sleeps 150 ms after servicing a RAM clear. It disables the three extended enables at
  probe and at remove, clears the flags by writing zeros, and then re-enables KSE alone.
- **Reading**: the vendor text that the sources quote for the RAM clear also says the clock, calendar and
  extended RAM are untouched. That conflicts with 242 bytes of user RAM being cleared, since the extended
  RAM is part of those 242. Settle it from the vendor page 20 wording before relying on either sentence.

## Non-volatile RAM

- **Inferred**: bank-0 user RAM is 114 bytes, from 0x0E to 0x7F. The driver's write loop covers a 50-byte run
  from 0x0E and a 64-byte run at 0x40, and their sum is 114.
- **Established**: the extended RAM is addressed by a seven-bit address written to 0x50 and read or written at
  0x53. The address does not advance by itself on this part (Maxim, page 21).
- **Inferred**: that makes 128 extended bytes, and 114 plus 128 is the 242 bytes of user RAM.
- **Inferred**: Linux's read path rewrites the address before every byte, which the part requires. Its
  DS17x85 path sets burst mode and writes the address once instead, and that is a different part.
- **Inferred, a driver defect**: Linux's write path cannot reach the extended RAM. Its loop over the
  64-byte run writes the bare base every time and never advances the position, so the position sticks
  below the bank-0 total and control never reaches the bank-1 section. The read path has the offset
  arithmetic the write path lacks. Nothing here says the part behaves so; it is a driver slip.
- **Unknown**: what an Octane's firmware keeps in the 242 bytes. Linux exposes them as unstructured storage
  and no public source consulted gives a layout.

## Identification

- **Inferred**: the model byte is at 0x40, and six serial bytes follow it at 0x41 to 0x46. The sysfs and
  proc views show both.
- **Established**: 0x47 holds a CRC byte used to validate the bytes at 0x40 to 0x46 (Maxim, as quoted).
  The sources give no polynomial, so the check cannot be reproduced from this page, and no driver
  consulted validates it.

## Periodic interrupt, square wave, and the other bits

- **Inferred**: Linux clears the periodic rate bits at probe and sets E32K, so no periodic interrupt is
  armed. The RTC core dropped hardware periodic interrupts in favour of timers, and the rate table in the
  Linux header is unused.
- **Inferred**: no source consulted says an Octane consumes the SQW pin, and no driver reads back a
  waveform. Linux sets E32K at probe and prints both E32K and SQWE, so they must read back as written.
- **Established**: the crystal-select bit is inert on the DS1687 (the vendor says so). On the DS1685 it selects
  an analogue setting. It is stored and read back.
- **Inferred**: VRT and VRT2 reading zero means an exhausted cell. Linux prints warnings at probe and carries on.
- **Inferred**: PRS selects what the PWR pin does when power fails. The sources give no table of its states, so
  this page says nothing more about it.
- **Established**: the SMI recovery stack at 0x4E and 0x4F is a PC BIOS recovery aid (Maxim, as quoted). No driver consulted reads it.
  Its use on an Octane is unknown.

## Parts this page does not cover

The DS17x85 and DS17x87 and the DS1689 and DS1693 have larger extended RAM, burst mode, a write counter and
power-cycle counters, and the Linux driver selects between them at compile time. The DS1685 has none of these.

## Open questions

1. **Byte-bus span and the byte-lane correction.** Does each select answer across its whole span, and how does
   the Bridge's byte-lane correction place a driver's access on the part? The sources report a three-byte
   offset from the address a driver names; that was not checked here. Settled by the IOC3's byte-bus description
   or a trace of an Octane's firmware reaching the part.
2. **The Bridge interrupt route.** Linux puts the clock on Bridge pin 6, and OpenBSD takes the power event from
   HEART. Whether the clock's own line reaches pin 6, or pin 6 is the power switch alone, is unsettled. Settled
   by a board schematic or by firmware seen programming the Bridge.
3. **The CRC polynomial.** Settled by the Dallas application note the datasheet cites, or by firmware that checks
   the bytes.
4. **Firmware use of the 242 bytes.** Settled by reading the bytes from an Octane firmware image, or by a
   capture of the PROM's use of them. It matters once a PROM reads them.
5. **Bit positions not transcribed.** Register A to Register D, Register B and the bank-1 bytes 0x4A and 0x4B
   other than the three bits in the unit have their positions in the Maxim datasheet. Settled by transcribing
   those pages.
6. **The RAM-clear sentence.** See the reading under RAM clear. Settled by the vendor page 20 wording.

## Not carried here

The sources also cover material that is not a fact about the hardware: software design choices, storage
formats and sizes for saved clock state, and review history. None of it is imported. Restricted source: none.
No vendor source tree was used for this page.
