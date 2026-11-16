# IP27 PROMs: keyboard detection and the console choice with no keyboard

Question answered: on an Origin 200, Origin 2000 or Onyx2, which PROM probes the PS/2 keyboard and mouse on the base I/O board's IOC3, how, and
what does the PROM do with the answer. Ratings follow [AGENTS.md](../../AGENTS.md): **established** (public IRIX 6.5.7 source and the shipped image
agree), **software expectation**, **inferred**, **unknown**. No real-hardware capture of a keyboard-less boot is held, so nothing here is observed.

The kernel side is in kudzu `software/kernel/ip27-ip30-ioc3-pckm-absent-device.md`. IP30 is in [ip30/prom-console-input.md](../ip30/prom-console-input.md).

## Which PROM

| PROM | Role here | Rating |
|---|---|---|
| IP27 CPU PROM (`ip27prom.img`, load `0xc00000001fc00000`) | Chooses which base I/O board's serial port is the console (message text: "No console found. Searching for console...", `ForceConsole`, `ConsolePath`). It holds no keyboard probe and no ARCS console variables. The one keyboard string in it, "Keyboard input from ELSC", belongs to the system-controller console path | established (strings and source `IP27prom/main.c`); the full image was not decompiled |
| I/O-board PROM (`io6prom.img`, segment `io6prom` loaded at `0xc000000011c00000`) | Runs the IOC3 keyboard and mouse probe, builds `ConsoleIn` and `ConsoleOut` and opens them | established |

The addresses below are in the unpacked `io6prom` segment (promgen64 container, checksum ok; unpack with `retools/tools/chips/promgen64.py`).

## The probe

The PROM driver is the same standalone-library code the Indy-era PROMs use, with the IOC3 register offsets. Every command goes through one
routine: wait for the port's transmit-pending bit, write the byte, then read the port's receive register up to 25 times, 1000 us apart, until any
of the three valid bits (31:29) is set.

| Step | What the PROM does | Absent device | Rating |
|---|---|---|---|
| Start-up | write `0xc00000` to the keyboard/mouse control register (`0x9c`) | none | established |
| `check_port` (`0x11c2c378`) | flush (one read), send `0xf2` (read ID), classify valid bytes: `0xfa` ack, `0xab` identity response, `0x83` keyboard (needs ack and `0xab`), `0x47` then `0x53` (alternate keyboard), `0x00` mouse (needs ack). Up to 3 passes; with an ack seen it waits 300 ms and reads once more, with none it flushes and sends `0xf2` again | no byte ever arrives: 4 sends of `0xf2` per port, each about 25 ms of polling, about 100 ms per port; returns ENODEV (13) | established |
| `set_ports` (`0x11c31c50`) | probe port 0 then port 1; the keyboard answer sets the keyboard port, the mouse answer the mouse port | keyboard port and mouse port both ENODEV; keyboard-present word `0x11eca3d0` is 0 | established |
| default mouse port | if no mouse answered, the mouse port is set anyway: port 0 when the keyboard is on port 1, else port 1 | mouse port = 1 even with nothing attached; the mouse-present word `0x11eca3d4` stays 0 | established |
| `nogfxkbd` | if the NVRAM variable `nogfxkbd` starts with `1` and no keyboard answered, the keyboard port is set to the connector the mouse did not answer on (port 1 if the mouse is on port 0, otherwise port 0) | keyboard port = 0 although nothing is attached | established |
| `pckbd_install` (`0x11c33d98`) | stores a presence mask into the board's configuration record: bit 0 keyboard port set, bit 1 mouse port set. If the keyboard port is set it runs keyboard setup, loads the keyboard map named by `keybd`, and sets the keyboard-exists word `0x11eca810` to 1 | without `nogfxkbd`: bit 0 clear and keyboard-exists stays 0. With `nogfxkbd=1`: bit 0 set, keyboard setup sends `0xf0` (scan set), `3`, `0xfa`, `0xfc 0x14`, `0xfc 0x76` into a port that never answers (each a 25 ms timeout), keyboard-exists becomes 1. The mouse bit is always 1 | established |
| mouse setup | if the mouse port is set (always) the PROM sends `0xf3` and `0x28`; no answer is required | always counted as present | established |

The keyboard-exists word is what the keyboard driver's initialise entry tests (`0x11c2d8b8`): zero makes it fail with ENODEV (13) and leave an error in
the request block; nonzero lets the open proceed. The software test in the library source is the same shape.

An older repository note (`docs/research/graphics/io6prom-kona-console-open-lifecycle-20260927.md`) says `nogfxkbd` does not waive the keyboard because
it leaves the word `0x11eca3d0` alone. That word is "a keyboard answered"; it is not what the open tests. The open tests `0x11eca810`, and
`pckbd_install` sets that for any non-ENODEV keyboard port, including the one `nogfxkbd` assigns. The disassembly and the decompiled call order give
that reading; no run with `nogfxkbd=1` was made, so it is established from code and unconfirmed in execution.

## What the answer does to the console

| Item | Behaviour | Rating |
|---|---|---|
| `console_select` (`0x11c79c84`) | `console` unset becomes `g`. If a graphics probe is installed and `console` does not start with `d`, `ConsoleOut=/dev/graphics/textport` and `ConsoleIn=/dev/input/ioc3pckm0`. Otherwise both are the serial path: `/dev/tty/ioc30`, or `/dev/tty/ioc31` when `console` is `d2` | established |
| `console_open` (`0x11c736e0`, the standard-I/O setup) | Open `ConsoleIn` read-only, then `ConsoleOut`. A failure on the input open with ENODEV prints "Cannot connect to keyboard -- check the cable." and then "Cannot open /dev/input/ioc3pckm0 for input". On the first failure it rebuilds the variables from `console` (`console_select(0)`) and tries again. On the second failure, if `console` does not start with `d`, it sets `NoAutoLoad` to "CONSOLE OPEN FAILED.", rebuilds for `console=d` and opens the serial port. A failure with `console=d` or after that is a panic ("Cannot open any console!") | established |
| NVRAM `console` | not rewritten; only `ConsoleIn`, `ConsoleOut` and `NoAutoLoad` change in the run-time environment | established |
| ARCS environment after fallback | `ConsoleIn` and `ConsoleOut` are the serial path, `NoAutoLoad` is set, `console` still reads `g` | established |

With no keyboard and `console=g`, then: the PROM tries graphics, fails on the keyboard open twice, prints the cable message twice, and ends on the
serial console with autoload off. With `nogfxkbd=1` the keyboard open succeeds, so the textport stays the console. With `console=d` neither input
device is opened.

## Mouse without keyboard, keyboard without mouse

| Case | Behaviour | Rating |
|---|---|---|
| Mouse only | the keyboard port is still ENODEV, so the same fallback as no keyboard applies; the mouse answer only fixes which port the mouse is on (and so, with `nogfxkbd=1`, which port is borrowed for the keyboard) | established |
| Keyboard only | nothing changes: the mouse is always installed, so `ConsoleIn` opens | established |
| Keyboard on the mouse connector, or the reverse | `check_port` is by identity, not by port, so the ports are assigned by answer; the PROM re-probes if the first byte of a stream looks like the other device (`reinit_kbd`, `reinit_pcms` in the source) | established (source) |

## What an emulator has to model

For the PROM to take the headless branch it needs only the following from each IOC3 port:

- `0xa0` and `0xa4` read with none of bits 31:29 set for every read; a write to `0xa8` or `0xac` is accepted and ignored. The PROM then spends about
  100 ms per port in probes. Rating: established (software side). The actual register image of a real unplugged port is unknown.
- `0x9c` bits 0 and 1 (transmit pending) clear after a write. The PROM tolerates them staying set, at 25 ms per command (25 reads, 1000 us apart); how
  a real part behaves with no device clock is unknown.
- A present keyboard answers `0xf2` with `0xfa`, `0xab`, `0x83` in three slots of one read or across reads; a present mouse answers `0xfa`, `0x00`.

## Unknowns

1. Register image of an unplugged port on real IOC3 (receive, control).
2. Whether the open path reaches ENODEV through the driver's initialise entry or through a missing device node in the PROM's device graph (the
   disassembly shows the initialise entry returns ENODEV; the path from `Open` to it was not traced). The result, ENODEV with the cable message, is
   what the library source expects.
3. A real keyboard-less boot capture for Octane or Origin: none held.
