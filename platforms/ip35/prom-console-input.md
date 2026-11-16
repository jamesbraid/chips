# IP35 PROM 6.210: what the boot PROM does when no PS/2 keyboard or mouse answers

Question. On Fuel, Tezro and Origin 3000-class systems, how does the I/O PROM decide that no keyboard or mouse is connected, and what does it do about the console?

Method. The `ip35prom` segment of PROM 6.210 (built Aug 26 2004) carries a gzip-compressed 64-bit executable at image offset `0x8bbb0`: the I/O ("BASEIO") PROM monitor, linked at `0xc000000013000000`. It was read by decompiling it flat at that address (output is navigation, not evidence; each claim below was checked against the decompiled routine). Addresses are monitor addresses. The routines match the public IRIX 6.5.7 stand-alone PS/2 driver (`stand/arcs/lib/libsk/io/ioc3_pckm.c`), which was read first, so the source stands in for the parts the binary shares with it. The Fuel capture is Usenet `comp.sys.sgi.admin` message-id `<Dkkni.12$r21.11@newsfe6-win.ntli.net>` (2007-07-18, PROM 6.210); a 6.201 Fuel log with the same lines is `<pgzk6n75gku.fsf@kruuna.helsinki.fi>`.

Grades: **established** (the routine or capture was read and the claim follows), **observed** (a captured run), **software expectation** (the PROM relies on it, hardware not tested), **inferred**, **unknown**.

## Answer

1. **Established: two probes, one shape.** Both the PROM's port scan (`0x130668e8`, run when the PS/2 driver installs) and the power-on diagnostic (`0x130e2aa4`) identify a port with the same exchange (`0x130619f4`): send command `0xf2` (read ID) to the port's transmit register, then read the port's receive register. A reply counts only if one of the three valid bits (31:29) is set and its frame-error bit is clear; each of the three byte lanes is tried. A keyboard is `0xfa` then `0xab` then `0x83` (or `0xfa`, `0x47`, `0x53`, reported as `0x47`); a mouse is `0xfa` then `0x00`. The scan keeps the last keyboard and last mouse it finds; the diagnostic, which counts them, rejects two of a kind (`Cannot have two of the SAME PS/2 devices`, code `0xfe`).
2. **Established: what "absent" is.** No byte with a valid bit arrives. The probe then repeats: if no `0xfa` was seen it flushes the receive register (one read) and sends `0xf2` again; if `0xfa` was seen but no ID, it waits 300000 microseconds and rereads. Three rounds, then the port answers "none" (code `0xd`). Each send first calls a wait routine (`0x13061504`, not read); the public source's version waits for the transmit-pending bit (bit 0 keyboard, bit 1 mouse of the control register) to clear, 25 reads at 1000 microseconds, then writes anyway. After the write it polls the receive register, 25 reads at 1000 microseconds, until a valid bit sets. A silent port therefore costs about 4 sends of 25 ms, roughly 0.1 s per port, plus the 3 rounds. The kernel's own copy of the probe uses 250 polls of 50 microseconds.
3. **Established: nothing aborts and nothing is written to NVRAM.** The scan leaves keyboard and mouse ports at "none" (13). If the environment variable `nogfxkbd` starts with `1` and no keyboard answered, the PROM assumes a keyboard on the port the mouse is not on, port 0 by default. The diagnostic prints `No keyboard found, skipping keyboard test`, `No mouse found, skipping mouse test`, then either `Missing PS/2 device(s) AND console set to "g"` (result 0xff, final line `passed with a possible problem`) or, when `console` starts with `d`, `... BUT console set to "d"` (result 0, plain `passed`). A missing device never fails the diagnostic; only a device that answers and then fails self-test does (codes `0x49` keyboard, `0x4a` mouse).
4. **Observed (Fuel, 6.210, console `g`, keyboard and mouse unplugged):** the lines above, then graphics diagnostics, `Installing Graphics Console...`, SCSI walk, and a System Maintenance Menu on serial port 1 at 9600. The 6.201 log adds `Cannot connect to keyboard -- check the cable.` and `Cannot open /dev/input/ioc3pckm0 for input`, twice.

## What the PROM does with the answer

| Fact | Grade | Where |
|---|---|---|
| ConsoleIn and ConsoleOut are chosen by `0x130da80c`. The choice is serial if `console` starts with `d` (or an explicit `d` is passed), if no graphics device is installed, or if the quiet flag `0x1311a9b8` is set (the flag's meaning is inferred from the "Initializing PROM Device drivers" lines it suppresses). Otherwise ConsoleOut is `/dev/graphics/textport` and ConsoleIn is the keyboard path below. If `console` is unset the PROM sets it to `g`. | established | `0x130da80c`, `0x130cb958`, `0x130cba68` |
| Keyboard path for `console=g`: the NVRAM variable `gConsoleIn` if set and valid, else `/dev/input/usb/keyboard` if a USB keyboard was found during enumeration, else `/dev/input/ioc4pckm0` if the console base I/O has an IOC4, else `/dev/input/ioc3pckm0`. USB is therefore preferred to PS/2 whenever a USB boot keyboard enumerated. | established | `0x130cb958`, `0x130cb910`, `0x130dcc24` |
| A USB keyboard is any HID interface the PROM's USB code classifies with boot protocol 1; protocol 2 marks a mouse. It sets the "USB keyboard seen" word that `0x130cb910` tests. | established (the protocol codes are read from the code; naming them boot keyboard and mouse is inferred) | `0x1307902c` |
| Serial path: `/dev/tty/ioc4tty0` or `ioc4tty1` (IOC4), `/dev/tty/ioc30` or `ioc31` (IOC3), `/dev/tty/hubtty0` otherwise. Port 1 only when `console` is exactly `d2`, else port 0. | established | `0x130cba88` |
| After drivers install, `0x130d32b4` opens ConsoleIn for input and ConsoleOut for output. If opening the keyboard fails with code 13 it prints `Cannot connect to keyboard -- check the cable.`, then `Cannot open <path> for input`. It retries once through `0x130da80c(0)` (same choice). On a second failure, if `console` is not `d`, it sets the environment variable `NoAutoLoad` to `CONSOLE OPEN FAILED.` and calls `0x130da80c("d")`, which points ConsoleIn and ConsoleOut at the serial port for this boot. It does not rewrite `console`. `NoAutoLoad` keeps the autoboot from running, which is why the maintenance menu appears. | established; the effect of `NoAutoLoad` is inferred | `0x130d32b4` |
| With `console=d` the keyboard is never opened and a missing keyboard changes nothing. | established | `0x130da80c`, `0x130d32b4` |
| Graphics install runs even with no keyboard (it returns early only for `console` starting with `d`), so a headless Fuel with `console=g` still brings up the graphics device and prints on serial only after the fallback. | established | `0x130d1708` |

## Mouse without keyboard, keyboard without mouse

Established: the probe is per port and symmetric, so either can be absent alone. The ConsoleIn decision looks only at the keyboard path (the mouse never enters it), so a missing mouse affects nothing but the `No mouse found` line and the "possible problem" result when `console` is not `d`. A mouse with no keyboard behaves as the keyboard-absent case: the open of the keyboard device fails and the serial fallback runs. A keyboard plugged into the mouse port (or the reverse) is detected by ID, not by position, and is used.

## What an absent device looks like at the registers

The register layouts come from two tables in the monitor: IOC3 control `0x9c`, receive `0xa0` (port 0) and `0xa4` (port 1), transmit `0xa8` and `0xac` (set by `0x13066bc8`); IOC4 control `0x200`, receive `0x204` and `0x208`, transmit `0x20c` and `0x210` (set by `0x13066ac0`). Both share the receive-register decode: three byte lanes, valid bits 31, 30 and 29 for bits 23:16, 15:8 and 7:0, frame-error bits 26, 25 and 24, overflow bit 28.

| Step | What the PROM does | Absent device, as the code requires it | Grade |
|---|---|---|---|
| Install | stores `0xc00000` (clamp bits 23:22) to the control register | accepted | established |
| Send `0xf2` | waits for pending bit clear (source: 25 x 1 ms), writes `0xf2` | the write must not hang; whether pending stays set is not known | unknown (hardware) |
| Poll | reads receive register 25 times at 1 ms until bits 31:29 are non-zero | stays zero for all 25 reads (no valid byte, no frame error) | established as the "absent" signature the code takes |
| Retry | flush read, resend `0xf2`, 3 rounds | same | established |
| Self-test / reset (`0xff`, `0xaa`) | not sent to an absent port; the diagnostic sends `0xf5` (disable) to both ports first | no reply expected | established that nothing is sent after "none" |

The diagnostic also writes `0xc00880` to the control register, waits 10 ms, clears bits 11 and 7 (`& 0xfffff77f`), and finishes by writing `0xf4` (enable) to both ports. What the control register's other bits do (transmit-pending timeout, line states) is not settled by the PROM; see the IOC3 and IOC4 device pages.

## Machines

| Machine | Keyboard hardware | Grade |
|---|---|---|
| Fuel | PS/2 on the base I/O; the captures name `ioc3pckm0`. USB keyboards are also searched (USB path precedes PS/2). | observed (6.201 and 6.210 captures); USB path established from the PROM |
| Tezro, Origin 350 (IO9) | PS/2 through an IOC4 (`ioc4pckm0` is chosen when the console base I/O has an IOC4); USB also searched | established (selection code); that the Tezro daughtercard carries IOC4 is the Tezro guide cited on [the IOC4 page](../../devices/ioc4/README.md) |
| Origin 3200, Onyx 3000 | the I-brick panel has no PS/2 connector, so the keyboard is USB and the same PROM prefers it | software expectation (chips topology page); no capture held |

## Unknown

- Whether the transmit-pending bit of the control register ever clears when no device is attached, and any timeout bit that makes it. Settling it needs a hardware read of the control register after a send to an empty port (a physical test, not proposed here).
- The 6.211 PROM and any Tezro-specific (IP53) PROM: not read; only 6.210 is in the root.
- A capture of a Tezro or Origin 350 with the keyboard unplugged. The PROM logic is shared, so the same lines are expected.
- Whether `console=d` set in NVRAM and a missing keyboard changes the IRIX miniroot behaviour; this page covers only the PROM.
