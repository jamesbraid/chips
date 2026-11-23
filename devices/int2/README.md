# INT2: the Indigo interrupt controller and 8254 timer block

INT2 gathers the Indigo's local interrupt sources into two CPU interrupt lines, holds a five-bit control port and carries an
8254 timer used for the scheduler clock. It is the first-generation part of a family: the Indy and Indigo2 have INT2 and INT3
parts behind the HPC3 with different bit layouts (below). This page covers the Indigo, both the R3000 board (IP12) and the
R4000 board (IP20). The register offsets, bit meanings, grades and `ro`/`w1c` masks are in
[`registers.toml`](registers.toml); the generated reference is `registers.md`. The routing table of which device drives which bit is
[platforms/ip20/interrupts.md](../../platforms/ip20/interrupts.md). This page holds what the register file cannot say.

Labels follow [AGENTS.md](../../AGENTS.md): **established** is read in full from a shipped object or stated by a public header,
**inferred** is reasoned, **unknown** is unsettled. Nothing was measured on hardware.

## Sources

- **IRIX 6.5 IP20 boot objects** (base media, `usr/cpu/sysgen/IP20boot/`): `kernel.o` (interrupt dispatch, vector registration, clock
  routines), `sduart.a` (`zduart.o`), `gr2.a`, `lg1.a`, `io.a` (`vdma.o`), `wd93.o`, `hpcplp.o`, `if_ec2.o`. Addresses below are
  `.text` offsets in the object as linked for relocation; they are stable for that object.
- **PROM 070-8116-004**, SGI Version 4.0.5D Rev A IP20, Aug 19 1992 (sha256 `e6e1f1ed...ba97f82f`), addresses in the `0xbfc00000` window.
  The 4.0.5G image (070-8116-005) was not disassembled for this page.
- **Shipped header** `usr/include/sys/IP20.h` (revision 1.50) for names, addresses and bit masks.
- **NetBSD sgimips** `sys/arch/sgimips/dev/int2reg.h` and `int.c` (the offsets, the Indy-generation names, and the claim of a 1 MHz
  master clock); **Linux** `arch/mips/include/asm/sgi/ioc.h` (`struct sgint_regs`, the 8254 control word, the INT3 layout).
- No INT2 specification and no 8254 data sheet is held. The 8254 register layout is the standard part's and is used as such.

## Register window (established)

INT2 sits at physical `0x1fb801c0`, 64 bytes, inside the `0x1fb80000` block that the HPC1 decodes (the placement behind HPC1 is inferred from the addresses; no document states it). Every register is one byte
on a 4-byte stride in the least significant byte lane, so a big-endian CPU addresses local 0 status at `0x1fb801c3` and a
little-endian CPU at `0x1fb801c0` (header `LIO_0_ISR_ADDR`, both byte orders). The PROM and the IRIX kernel use the big-endian addresses.
The kernel always accesses INT2 with byte loads and stores (`lbu`/`sb` throughout `kernel.o`); no shipped code uses a wider
access. The PROM's one exception is that it writes the first 8254 counter at `+0x30` (lane 0) rather than `+0x33`; see "8254" below.

| Offset (BE) | Name | Access | Role |
|---|---|---|---|
| `0x03` | local 0 status | r | raw level of eight sources |
| `0x07` | local 0 mask | rw | enable per source |
| `0x0b` | local 1 status | r | raw level of eight sources |
| `0x0f` | local 1 mask | rw | enable per source |
| `0x13` | VME status | r | VME request levels; bit 0 is also the vertical-retrace status |
| `0x17` | VME 0 mask | rw | which VME levels reach local 0 bit 7 |
| `0x1b` | VME 1 mask | rw | which VME levels reach local 1 bit 3 |
| `0x1f` | port config | rw | five bits: serial port select, retrace latch, power |
| `0x23` | timer acknowledge | w | write-1 strobe per timer interrupt |
| `0x27` | error status | unknown | NetBSD's Indy-generation name; unused on the Indigo |
| `0x33`,`0x37`,`0x3b`,`0x3f` | 8254 counters 0 to 2 and control | rw / w | the timer block |

## Status and mask behaviour

**Status is raw and read-only (established).** The PROM at `0xbfc03780` writes both mask registers with `00 aa cc f0 ff 55 33 0f`
and reads each back; later at `0xbfc03824` it zeroes both masks and then reads the status registers, requiring the local 0 bits other than
bit 0 and bit 6 to be zero and local 1 bits 0, 2, 3 and 4 to be zero (it allows bit 1, bits 5, 6, 7, and the two GIO bits on local 0). IRIX
computes `status AND mask` in software (`kernel.o` local 0 handler at `0x28c8`, local 1 at `0x2a1c`), so a masked-off source still
shows in status. Status bits follow the source lines directly: no shipped code ever writes a status register, so there is
no write-1-to-clear. Whether a status read has side effects is unknown; the shipped code reads status without ill effect repeatedly
(the PROM polls local 0 bit 5 for serial input).

**Mask registers are plain 8-bit latches (established).** All bits read back what was written. A qtest should write and read `0xaa`
and `0x55` to each. Power-on value: inferred zero; IRIX zeroes all of them in `mlreset` (`0x2258..0x22fc`) and the PROM's
INT2 initialiser at `0xbfc008f8` also zeroes all four before anything enables a source, so nothing depends on a reset value.

**Output lines.** Local 0 asserts its CPU interrupt while any bit of `status & mask` (local 0) is set; local 1 likewise. The outputs
follow the sources: the CPU line falls when the device drops its request (inferred: no shipped code clears a local status bit in INT2, every
driver acknowledges in its own device, and the PROM's polled-serial loop sees the bit fall without touching INT2). The IRIX dispatchers take one
snapshot of `status AND mask`, serve it from the highest bit down, and return to the CPU-level loop, which re-reads Cause. Which register clears each
source is in the routing table.

## Which CPU interrupt each output drives

IP20 (R4000 board), **established** by the kernel's CPU-level dispatch table (`kernel.o .data+0x38`, 16-byte records indexed by the
highest set Cause pending bit, plus the lookup tables at `.data+0x340`) and the `intr` routine at `0x2740`:

| INT2 output | Cause bit | R4000 name | IRIX handler |
|---|---|---|---|
| local 0 (`status & mask`) | 10 (`CAUSE_IP3`) | IP2 / Int0 | local 0 dispatcher at `0x28c8` |
| local 1 | 11 | IP3 / Int1 | local 1 dispatcher at `0x2a1c` |
| 8254 counter 0 | 12 | IP4 / Int2 | `clock()` (`os/clock.o`) |
| 8254 counter 1 | 13 | IP5 / Int3 | fast clock |
| bus error | 14 | IP6 / Int4 | `buserror_intr` (`os/trap.o`) |
| (R4000 count/compare, internal) | 15 | IP7 / Int5 | `clr_r4kcount_intr` at `0x2d30` |

The shipped header names the Cause bits `CAUSE_IP3` to `CAUSE_IP8` (bit 10 to bit 15) in its own level numbering; the R4000 manual
numbers the same bits IP2 to IP7. Cause bit 14 is bound to the bus-error handler by the dispatch table (established). No INT2 register shows a bus-error
status, and the source of the signal is not in INT2 (inferred: the MC reports the error); it belongs on the MC page.

IP12 (R3000 board): inferred. NetBSD numbers the IP12 lines one higher than the IP20 ones (local 0 on interrupt 1, local 1 on 2, timer 0
on 3, timer 1 on 4) and installs nothing on line 0, which on the R3000 is the first external input. No other source says what drives that
line. The R4000 FPU raises its exception internally, so IP20 has no FPU line. No IP12 kernel object is held, so the R3000 mapping rests on
NetBSD (`int.c`, IP12 case) only.

## Vector registration in the IP20 kernel (established)

`setlclvector(vector, handler, arg)` (`kernel.o 0x23a0`) takes a vector 0 to 15 (the header's `VECTOR_*` numbers): vector `n` is
local register `n / 8`, bit `n % 8`. A non-null handler is stored in a 32-byte record per source and the mask bit is set at the
splhintr level followed by a bus flush; a null handler stores the default "stray" handler and clears the mask bit. `lclvec_init` (`0x20dc`)
preloads every record with that default. Sources with no handler print "stray local N interrupt" (strings at `kernel.o .rodata+0xe0`).

Registrations found by relocation in the shipped objects: SCSI vector 2 (`wd93_init`, `wd93intr`), Ethernet vector 3 (`if_ec2.o`
`integral_ecintr`), serial vector 5 (`zduart.o du_init`, `du_poll`), parallel (`hpcplp.o`), graphics DMA done vector 4 (`vdma.o MCIntClr`
passes a null handler, which disables the source and zeroes MC `+0x164`), and AC fail vector 13 (`mlreset` at `0x2268`, handler `0x2dc0`, which resets
the SCSI buses and prints "Power failure detected"). GIO interrupts are registered through `setgiovector(line, slot, fn, arg)` (`0x2528`): `line` 0 to 2 is the GIO bus interrupt line
(`GIO_INTERRUPT_0..2`) and `slot` 0 to 2 is the board slot (`GIO_SLOT_0`, `GIO_SLOT_1`, `GIO_SLOT_GFX`); the order is read from the out-of-range
messages at `kernel.o .rodata+0x90` ("vector") and `+0xb8` ("slot"). The three lines map to three INT2 bits and each INT2 bit is shared by
every slot: line 0 is local 0 bit 0, line 1 is local 0 bit 6, line 2 is local 1 bit 7. The function stores `(fn, arg)` at `(3 * slot + line) * 8`
bytes in a table and, the first time any slot uses a line, registers one shared handler for it (`0x2b3c`, `0x2bd8`, `0x2c84`), which walks
slots 0, 1 and 2 for that line and calls every registered handler (the line stays shared; INT2 cannot tell the slots apart). Both graphics
families register in the graphics slot: GR2 (`gr2.o gr2_init`) and Entry/LG1 (`light.o lg1_init`) put their FIFO handler on line 0 and their
retrace handler on line 2; the GIO Ethernet driver (`if_ec2.o ec_init`) uses line 1.

## The control port at `0x1f` (partly established)

The header names this register PORT_CONFIG: LEDs and serial port configuration, five bits. Observed use, all byte accesses by
read-modify-write:

- **Bit 3, vertical-retrace latch (established).** The graphics retrace handlers (`gr2.o gr2_retr_intr` at `0xa0`, `Gr2RetraceInterrupt` at `0xf4`)
  clear bit 3, flush the bus, and set it again. The pulse acknowledges the retrace interrupt on local 1 bit 7. Between retraces the bit is
  left set, and the header names it "disable/enable vert. retrace intr." A qtest should check that the pulse drops local 1 bit 7.
- **Bits 1 and 2, serial port select (established).** `zduart.o du_rs422` sets or clears them per port when the port mode changes. The header
  calls them RTS and TX+ of the two ports (HP1) and also LED_HEART and LED_IDLE (IP20); the kernel's LED routine does not use this register (it
  drives the console LED through the HPC1 aux register at `0x1fb801bf` bit 0, which is not INT2).
- **Bit 4, power (unknown polarity).** The PROM writes `0x16` (bits 1, 2, 4) at `0xbfc00930` in its INT2 initialiser and no shipped code
  clears bit 4. The header comment says "Power off", so clearing bit 4 is a plausible power-off request, but no shipped code does it and the
  polarity and any delay are unknown. The question of the software power-off path is filed.
- **Bit 0.** Header names it a cache-parity flag on IP20; no shipped code touches it. Unknown.

NetBSD names this offset the map polarity register and Linux the VME polarity register for the Indy generation; no Indigo code treats it that way, and the bytes at `0x13` to `0x1f` are the VME block plus this port here.

## 8254 timer block (established)

**The 8254 is used, by both the IRIX kernel and the PROM, so the acquisition note that its use on the Indigo was unconfirmed is
settled: it is a standard Intel 8254 behind INT2, with its counter 0 and counter 1 outputs wired to CPU interrupt lines and counter 2
as a divider.** NetBSD uses it for the clock on IP12 but not IP20 (it reads the R4000 CP0 count instead), which is why the NetBSD page
lists IP20 and IP22 without 8254 use; the shipped kernel for IP20 does use it.

Kernel clock set-up (`startrtclock`, `kernel.o 0x7544`, in `spl7`): control `0x34` (counter 0, LSB then MSB, mode 2), counter 0 loaded
with `50`; control `0xb4` (counter 2, same mode), counter 2 loaded with `200`. `stopclocks` (`0x75ec`) writes control `0x32`, `0x72`, `0xb2` (modes 1)
and acknowledges both timers. The fast clock (`startkgclock` at `0x7714`, `slowkgclock` at `0x7914`) loads counter 1 with `5000 / fasthz`
under control `0x74` and stops it with count zero. The PROM's delay routine at `0xbfc2ca70` programs counter 2 with control `0xb4` and count
`10000` (`0x2710`) and polls it after a latch command (`0x80`), apparently to time the CPU against a 100 Hz reference; the PROM's INT2 init
(`0xbfc00940`) writes `0x02`, `0x42`, `0x42` to `+0x30` and `0x03` to the acknowledge register at `+0x23`.

**Clock rate (inferred).** The kernel divides counter 2 by 200 and treats 5000 as a rate (`5000 / fasthz`), so counter 2's output is 5 kHz and the
input is 1 MHz; counter 0's divisor of 50 then ticks at 100 Hz. NetBSD and Linux both state a 1 MHz clock ("unlike in PCs it's clocked at exactly
1 MHz"). The shipped headers do not state the crystal. Counter 0 gives `HZ = 100` on IP20 (inferred from the two constants).

**Acknowledge.** `ackrtclock` (`0x76c4`) writes `1` to `+0x23` after a bus flush; `ackkgclock` (`0x76ec`) writes `2`. The header calls the register "clear timer
2 bits (ws)", a typo for timers 0 and 1: its macros are `ACK_TIMER0 0x1`, `ACK_TIMER1 0x2`. It is a strobe, not a mask: writing a bit clears that timer's
pending interrupt; writing zero bits changes nothing. Reading the register is not done by any shipped code.

**Interrupt behaviour.** The interrupt is raised by the counter output going high (rate-generator output of mode 2) and held until acknowledged;
the CPU line stays asserted until the strobe, which is why every handler's first act is to acknowledge. The model should latch the rising edge of
the output per timer and clear on the strobe. Whether the output edge or level is latched is unknown; the shipped code is consistent with either.
NetBSD's note says "int2 doesn't like counting down from one, but two works", so a counter loaded with 1 should not be assumed to produce an edge.

## INT2 and INT3

The Indy and Indigo2 replace the Indigo's INT2 with one in the IOC family reached through HPC3's peripheral bus; NetBSD puts the Indigo2 part at `0x1fbd9000` and the Indy part at `0x1fbd9880` and calls both INT2. Linux `struct sgint_regs` gives the layout those parts share: local 0 and local 1 status and mask at
the same byte offsets (`+3`, `+7`, `+0xb`, `+0xf`) as the Indigo, then a VME status and two mask registers, a polarity register, the timer clear,
an error status ("reserved on INT2") and the 8254 at `+0x33` onward. The source bits differ: on those parts local 0 is FIFO full, SCSI 0, SCSI 1,
Ethernet, graphics DMA, parallel port, second HPC, and an LIO2 line; local 1 is ISDN, power, ISDN, LIO3, HPC3, AC fail, video and GIO2. The two
tables differ at bits 1, 2, 5, 6 and 7 of local 0 and at nearly every bit of local 1, so the Indigo cannot reuse an Indy table. Neither the Indy's mappable interrupts nor the power-button
interrupt exist on the Indigo; the Indigo's `0x13` to `0x1f` are the VME block and the port register.

## What a qtest can discriminate

- Mask registers: byte write then read of `0xaa`, `0x55`, `0xff`, `0x00`.
- Status registers: writes are ignored; a source line raises its bit regardless of the mask; the CPU output follows `status & mask`.
- Timer acknowledge: write `1` drops timer 0's output, `2` drops timer 1's; writes of zero do nothing.
- Port register bit 3 pulse clears local 1 bit 7.
- 8254: control `0x34` then two byte writes to counter 0 load a 16-bit divisor; counter 2 loaded with `200` and counter 0 with `50` yield 100 Hz at a 1 MHz input.

## Open

See [questions/int2.md](../../questions/int2.md).
