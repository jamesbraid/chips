# IP30 PROM: keyboard detection and the console choice with no keyboard

Question answered: on an Octane (IP30), how does the PROM find out that no PS/2 keyboard is attached to the IOC3, what does it do with the answer,
and what does it leave in `ConsoleIn` and `ConsoleOut`. Ratings follow [AGENTS.md](../../AGENTS.md): **established**, **software expectation**,
**inferred**, **unknown**. The IP30 PROM code was **not** decompiled; the sections below rest on public IRIX 6.5.7 source, on the shipped image
containing the same strings, and on the matching code in the IO6 PROM, which was decompiled ([ip27/prom-console-input.md](../ip27/prom-console-input.md)).
Nothing here is observed on hardware.

The kernel side is in kudzu `software/kernel/ip27-ip30-ioc3-pckm-absent-device.md`.

## Evidence and its limits

- Image: `root/firmware/IP30prom.bin` (`platforms/ip30/prom.bin`), the 6.5.30 PROM, flat from `0xbfc00000`. The first `0x40000` bytes are the reset and
  start-up code; the large program that holds the console and driver code is linked to run from memory (the references to its strings are not
  `0x9fc` or `0xbfc` addresses), and the link address was not settled, so addresses in that program are given as image offsets.
- Strings present in the image, as file offsets: "IOC3 keyboard/mouse" (`0x94628`, the power-on test name), "Keyboard/mouse controller
  diagnostic *FAILED*" (`0x936d0`), "Keyboard diagnostic *FAILED*" (`0x93708`), "Mouse diagnostic *FAILED*" (`0x93768`), "Cannot connect to keyboard --
  check the cable." (`0x96e80`), "CONSOLE OPEN FAILED." (`0x96ed8`), "Cannot open any console!" (`0x96ef8`), "ConsoleIn" and "ConsoleOut" (`0x97320`,
  `0x97330`), "keyboard()" (`0x97798`), "pckbd_install: Keyboard/mouse not attached to an IOC3 or IOC4" (`0x9cc78`), `nogfxkbd` (`0x94608`, `0x9ccf6`,
  `0xd5028`), "ConsoleWarning" (`0x9d510`), "Select Keyboard Layout" (`0x987a0`). Established (the strings exist); the code that uses them is the
  library code below by inference from the identical IO6 PROM.
- The 6.5.7 source tree used for the structure: the standalone I/O library driver (`stand/arcs/lib/libsk/io/ioc3_pckm.c`), its console setup
  (`lib/libsk/lib/saio.c`), the machine layer (`lib/libsk/ml/IP30.c`, `ml/nvram.c`) and the IP30 power-on keyboard test
  (`stand/arcs/ide/godzilla/ioc3/pon_pckm.c`).

## Probe

Same driver as the IO6 PROM, so the sequence and register use are the ones in the IP27 page: clear-and-clamp write of `0xc00000` to the IOC3
keyboard/mouse control register, then `check_port` on port 0 and port 1 (identify `0xf2`, up to 3 passes, 25 reads 1000 us apart per send, 300 ms
wait after an ack), then `nogfxkbd`. Software expectation (source; the matching routine in the IO6 PROM was decompiled).

Differences on IP30:

| Item | Behaviour | Rating |
|---|---|---|
| Install guard | the install routine returns at once if it has already run (`pckbd_installed`), so the probe happens once | software expectation (source) |
| Component tree | with a keyboard port set, the PROM adds a keyboard controller (`pckbd`) and keyboard peripheral flagged ConsoleIn and Input; with a mouse port set (always) a pointer controller (`pcms`) and pointer peripheral. With no keyboard port, there is no keyboard component | software expectation (source) |
| Console strings | `ConsoleOut=video()`, `ConsoleIn=keyboard()`, serial `serial(0)` | software expectation (source, `IP30.c`) |
| Function keys | the keyboard path maps function keys to `F<n>` environment strings; irrelevant when absent | software expectation |
| Power-on keyboard test | before the probe above, the IP30 power-on tests include "IOC3 keyboard/mouse": it writes the same `0xc00000` to the control register and fails with "pull-clock set" if bits 7 or 11 stay set, then reads each port's receive register for a keyboard self-test result (`0xaa` pass, `0xfc` fail, `0x00` mouse after a pass) before falling back to the identify command | software expectation (source) |
| Test verdict | with no keyboard on either port the test fails only when `console` starts with `g` and `nogfxkbd` is not `1`; with any other `console`, or `nogfxkbd=1`, absence passes | software expectation (source) |
| Effect of a failed power-on test on the console | not traced. The messages exist; whether the failure forces serial or only prints is unknown | unknown |
| Jumper | with the password jumper pulled, `console` is forced to `g` and `ConsoleWarning` is set to "PASSWD JUMPER MISSING--forced to g." | software expectation (source, `nvram.c`); the string is in the image |

## Console choice

Same as the IO6 PROM (`console_open` and `console_select`): `console` unset becomes `g`; if graphics is possible and `console` does not start with
`d`, ConsoleOut is `video()` and ConsoleIn is `keyboard()`; otherwise both are `serial(0)`. The input open fails with ENODEV when no keyboard component
exists, which prints "Cannot connect to keyboard -- check the cable." and "Cannot open keyboard() for input". The standard-I/O setup rebuilds the variables
once and retries, then sets `NoAutoLoad` to "CONSOLE OPEN FAILED.", rebuilds for `console=d` and opens `serial(0)`. NVRAM `console` is not changed. With
`nogfxkbd=1` the keyboard port is assigned although nothing answered, a keyboard component is added, the open succeeds and the graphics console stays.
The same applies to a failed output open (no graphics board). Software expectation (source; the IO6 PROM binary implements it).

## Mouse without keyboard, keyboard without mouse

Mouse only: the keyboard component is missing, so the fallback applies as with neither. Keyboard only: the mouse component is always present and the
open succeeds. Software expectation (source).

## What a standalone program sees after the fallback

After the serial fallback `console` stays `g`, so a standalone program that decides "graphics console" from that variable alone still takes
its graphics path. The firmware's private vector entry 8 (the textport-state call) still returns a non-null object in that state, but the
object's font table pointer is null, because the textport start-up that fills it only runs once a graphics board was opened. Observed on the
model with the stock 6.5.30 PROM, no board and `console=g`: object at `0x20f29d28`, font table field null. The consequence in `sash64` (read
null font table, bad address `0x38`, Install System Software from CD) is in kudzu `software/standalone/sash-console.md`. Observed; that a real
Octane returns the same is inferred, because the PROM routine itself was not decompiled.

## Unknowns

1. Code-level confirmation in `IP30prom.bin`: the main program's link address and the routine addresses.
2. Whether a failed "IOC3 keyboard/mouse" power-on test changes the console.
3. Register image of an unplugged port on a real Octane IOC3.
