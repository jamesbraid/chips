# IP34 (Fuel) system Timekeeper

The Fuel has a second battery-backed clock and calendar, apart from the Dallas DS1742W that holds
the L1's state. Public owner observations place it on its own battery-and-crystal assembly, which
the observations tie to the system clock and the PROM variables. The fitted part, its capacity and
its wiring to the IOC3 are unknown. The [DS1742W page](../../devices/ds1742/README.md) covers the L1 part and its
Fuel decoder question.

Each fact carries one label, as on the other chip pages here. **Established** means the
manufacturer specification states it. **Inferred** means a public driver, owner observations or
arithmetic on either supports it. A driver's software expectation is inferred: it says what the
software assumes, not what the chip does. **Unknown** means the sources do not settle it, with the
route that would. No fact here was measured on a board.

## Sources

- **OpenBSD `sys/arch/sgi/dev/dsrtc.c`**, commit `2df91d80c104636deeef8124252ddd5951b55fbf`: the
  IOC3 attach (lines 118 to 186; its comment on the `DS1742W` label is lines 124 to 133), the year base (lines 170 to 174 and 210 to 214), and the clock read
  and write routines (lines 359 to 428).
- **OpenBSD `sys/arch/sgi/pci/ioc.c`**, same commit, lines 307 to 355: the IP35 branch that attaches
  the clock on IOC3 byte bus 0.
- **OpenBSD `sys/arch/sgi/pci/iocreg.h`**, same commit, line 211: `IOC3_BYTEBUS_0`.
- **OpenBSD `sys/dev/ic/mk48txxreg.h`**, same commit, lines 53 to 82: the register indices, the
  control bits and the `MK48T35` clock offset and size.
- **OpenBSD `sys/sys/time.h`**, same commit, line 367: `POSIX_BASE_YEAR`.
- **John Hartley, "SGI NVRAM & Time Keeper Chips"** (web.archive.org snapshot of
  just.graphica.com.au/tips/sgi-nvram, 2024-12-24) and **IRIXNet thread 2535** (posts 1 and 3). The
  article says the Tezro, Origin 350 and Fuel each have two independent clock and battery-backed RAM
  chips: the L1's, and the system's, managed by the PROM and operating system. Its Fuel photograph
  shows a Snaphat battery module. The earlier draft also cited two posts by another forum user; their
  thread could not be found again and nothing here rests on them. The board revisions in the
  article are not stated.

## Window and byte map (inferred, driver expectation)

The driver reaches the clock through IOC3 byte bus 0, which starts at IOC3 offset `0x80000`. The
clock block is the top of a 32 KiB (`0x8000`) span. The driver maps from offset `0x7ff0`. Its header
leaves the first eight bytes of that span unassigned ("find out later"). The eight clock bytes are
at `0x7ff8` to `0x7fff`:

| Offset | Driver name | What the driver does with it |
|---|---|---|
| `0x7ff8` | control (ICSR) | Bit `0x80` enables a clock write. Bit `0x40` freezes the calendar for a read. The driver sets and clears each bit around its access. |
| `0x7ff9` | seconds | BCD, 0 to 59 |
| `0x7ffa` | minutes | BCD, 0 to 59 |
| `0x7ffb` | hours | BCD, 0 to 23 |
| `0x7ffc` | weekday | Written as the day of the week plus one, so 1 to 7 |
| `0x7ffd` | day of month | BCD, 1 to 31 |
| `0x7ffe` | month | BCD, 1 to 12 |
| `0x7fff` | year | BCD, 0 to 99, plus a base year set by the driver |

The base year is 1968 on the IP35 branch, which takes `POSIX_BASE_YEAR` (1970) less two. The IP27
branch uses 1970. A two-digit year from 0 to 99 therefore reads as 1968 to 2067 on the IP35 branch.
The driver's IP35 branch is the one this import takes for the Fuel. The mapping of the Fuel to
that system type in the driver was not re-checked here.

The driver's constant names say `MK48T35`. Those names describe the register layout the driver
expects. They do not identify the fitted part, and no source read here identifies it as an MK48T35.

## Role (inferred)

- Hartley's article supports a separate system clock and NVRAM, distinct from the L1's DS1742W, on
  the Fuel; thread 2535 reports that with a failing Snaphat the machine needed its time reset in
  single-user mode. That the assembly also holds the PROM variables is the article's general statement
  for these machines, not a Fuel-specific observation. Neither source establishes that the DS1742W has
  no other connection.
- The window placement is in the [DS1742W page](../../devices/ds1742/README.md) as an open question. This page holds the
  byte map and the year base that the driver assumes.

## Unknown

- **Fitted part, marking and package.** Route: a board marking read on a board whose revision is
  recorded, with the marking's provenance.
- **Capacity, select wiring and aliases.** Whether the part answers across the whole 32 KiB span,
  and whether any address mirrors inside the byte-bus span. Route: a schematic, or an address and
  select capture on a revision-identified board. A battery-capacity part number on the battery
  assembly cannot settle the SRAM capacity.
- **Reset and power-up contents** of the clock and the storage. Route: a read on a
  revision-identified board, under a read-only plan that names each register's side effects.
