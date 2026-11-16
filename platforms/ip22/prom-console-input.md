# Indy, Indigo2 and Power Indigo2 PROM: what it does when no PS/2 keyboard or mouse answers

Question. On Indy (IP24), Indigo2 (IP22) and Power Indigo2 (IP28) the PROM talks to the keyboard and mouse through the 8042-style controller in the HPC3. How does it decide a keyboard or mouse is absent, which registers does it touch, and what does it do with the console?

Method. Disassembly of the Indy PROM `SGI Version 5.3 Rev B10 R4X00/R5000 IP24 Feb 12, 1996` (part 070-9101-011, 512 KB, sha256 `d7ffc8e1adf53650672c65c871295fc45a55e6a0823ffe2e28b2aaa541c3e515`, byte-swapped by 16 bits to read it; addresses are `0x9fc00000` plus the swapped-file offset). Read against the public 6.5.7 PROM library source (`stand/arcs/lib/libsk/io/pc_kbd.c`, `stand/arcs/lib/libsk/lib/saio.c`; not quoted) and the published `prom(1M)` manual page. No IP22 or IP28 PROM image is held in the workspace roots, so IP22 and IP28 rest on the source, which builds one keyboard driver for all three. The kernel side is in kudzu (`software/kernel/headless-keyboard-ip22-ip32.md`). The sibling page for the O2 is [../ip32/prom-console-input.md](../ip32/prom-console-input.md).

Grades: **established** (code read in the binary or source and the claim follows), **software expectation** (what the code assumes a device returns), **inferred**, **unknown**. No hardware capture of a headless Indy or Indigo2 is held, so nothing is **observed**.

## Controller registers

| Item | Value | Grade |
|---|---|---|
| Data port, one byte | physical `0x1fbd9843` (`0x9fc217ac`: `lui 0xbfbd`, `ori 0x9843`) | established |
| Status and command port, one byte | physical `0x1fbd9847` (same routine) | established |
| Status bits used | `0x01` output full, `0x02` input full, `0x20` byte came from the mouse, `0x40` timeout, `0x80` parity error | established |
| Command byte (write with `0x60` to the command port, read with `0x20`) | `0x01` keyboard interrupt, `0x02` mouse interrupt, `0x10` keyboard clock off, `0x20` mouse clock off | established |
| Send the next data byte to the mouse | `0xd4` to the command port, then the byte to the data port | established |
| Device replies | `0xfa` acknowledge, `0xfe` resend, `0xaa` self-test passed, `0xfc` self-test failed, `0xff` overrun | established |

## 1. How absence is detected

Each keyboard or mouse command goes through one routine (`0x9fc217ac`): wait for input-full to clear (up to 20834 polls of 2 us), write the byte, wait 200 us, then poll the status port up to 400 times with 250 us between polls. Established.

- Parity error set: read and drop the data byte, resend. Reply `0xfe`: resend. Reply `0xff`: ignored, keep polling. Any other byte is the answer. The resend and parity retries share the same budget as a timeout retry. Established.
- Timeout bit set on a keyboard command: read and drop the data byte, abandon the 400-poll loop and send again at once. The mouse port never checks the timeout bit; only the 400 polls end it. Established.
- After 400 empty polls the command is sent again. Up to **3 retries after the first try, 4 sends in all**, then the routine returns -1. Established. If no timeout bit ever appears each send waits about 100 ms, so a silent device costs about 0.4 s per command (inferred from the delay constants; the delay routine's accuracy was not checked).

Keyboard probe (source, not located separately in the Indy image): write command byte `0x20` (mouse clock off), flush input (up to about 1/4 s), then send `0xf5` and send it again while the reply is `0xaa` (a stale self-test byte). A result of **-1 means no keyboard**; any other reply, even a non-acknowledge, counts as a keyboard. A present keyboard rings the bell, gets scan set 3 and make/break only on selected keys, and the command byte is written back to 0. Established (source). Software expectation: a keyboard answers `0xfa` to `0xf5`.

Mouse probe: command byte `0x10` (keyboard clock off), flush, send `0xd4 0xf6`. If the reply is not `0xfa` the whole step is tried once more, so at most 2 x 4 sends. Only `0xfa` counts as a mouse; it then gets sample rate 40 (`0xf3 0x28`). Command byte back to 0. Established (source).

Each command byte write is read back with `0x20` and rewritten up to 5 times until it matches, so the controller must return the value just written. Established (source).

A keyboard marked present registers an ARCS `keyboard()` peripheral under the keyboard controller; a missing one leaves only the controller node. A mouse likewise gets a `pointer()` peripheral only if it answered. Established (source). The environment variable `nogfxkbd`, if it starts with `1`, makes the PROM register the keyboard peripheral even when the probe failed (published `prom(1M)`; code in source). Established.

## 2. What the PROM does with the answer

- Boot sets `ConsoleIn` and `ConsoleOut` from `console`. If `console` starts with `d`, or the machine has no graphics probe, both are `serial(0)`. Otherwise `ConsoleOut` is `video()` and `ConsoleIn` is `keyboard()`. A missing `console` is set to `g`. Established (source). The console-variable code tests only the first character, so `d2` also yields `serial(0)` there; the Indy image also holds a `serial(1)` string, so the second port may be chosen elsewhere (the selecting code was not located: unknown).
- The PROM then opens `ConsoleIn` for reading and `ConsoleOut` for writing (code at `0x9fc0c87c`..`0x9fc0ca24`, same as the source). With no keyboard peripheral the first open fails. It prints `Cannot open keyboard() for input`; it prints `Cannot connect to keyboard -- check the cable.` first only when the failure code is ARCS ENODEV (13). Established for the compare; **which code a missing peripheral returns is unknown**, and where those first lines are printed (no console is open yet) is unknown.
- It then recomputes `ConsoleIn` and `ConsoleOut` from the environment and tries once more. That fails the same way when the cause is the missing keyboard. Established.
- If `console` does not start with `d` it sets `NoAutoLoad` to `CONSOLE OPEN FAILED.`, forces `ConsoleIn` and `ConsoleOut` to `serial(0)` and tries a third time. This works whenever the serial driver does. Established.
- If `console` is already `d` and the open fails, or the third try fails: panic `Cannot open any console!`. Established.
- Net effect with `console=g`, graphics present, no keyboard, no `nogfxkbd`: the machine ends up on the first serial port with `NoAutoLoad` set, so it stops at the command monitor instead of booting. This is also what `prom(1M)` states: the PROM treats an unresponsive keyboard as broken, switches to the serial terminal and waits for a command. Established.
- The `console` variable itself is **not** rewritten; it stays `g`, and `NoAutoLoad` is not cleared. Only `ConsoleIn` and `ConsoleOut` change. Established (source; the Indy image has the same sequence).
- With `console=d` the keyboard is never opened; absence has no effect. With `nogfxkbd=1` the keyboard peripheral exists, the open succeeds and the console is graphics with no input. Established.
- Linux `arch/mips/sgi-ip22/ip22-setup.c` confirms the interface a later kernel sees: it picks a serial console when `ConsoleOut` starts with `s` even if `console` is `g`, and its comment calls out "console is g but no keyboard". Published code, confirms only.

## 3. Kernel reaction

See the kudzu page. In short: the kernel does not read `ConsoleIn` or `ConsoleOut`, a missing keyboard does not stop the graphics textport, and the only message is a debug-level line on IP22. Whether a kernel booted after the serial fallback therefore uses the textport is inferred in that page.

## 4. Mouse without keyboard, keyboard without mouse

- Keyboard missing, mouse present: serial fallback as above. The mouse peripheral exists but is unused. Established.
- Keyboard present, mouse missing: console stays graphics. The mouse probe costs up to 8 sends. The PROM's own pointer use (the graphical menu) finds no mouse peripheral. Established (source).
- The two probes are independent; neither result changes the other, and the command byte is cleared between them. Established.

## 5. What an absent device looks like at the controller

This is what the PROM accepts as "absent". It is software expectation: no capture or manual in the repositories says which of these a real controller shows.

| Step | A model must make the PROM see | Result |
|---|---|---|
| any write while input-full is set | input-full (`0x02`) clears within about 40 ms | otherwise each command waits 1/4 s first |
| keyboard command `0xf5` to the data port | either status stays `0x00` for 400 polls (no timeout bit), or status shows `0x40` (timeout bit) | reply -1 after 4 sends |
| `0xd4` then `0xf6` for the mouse | status stays without output-full for 400 polls; the timeout bit is ignored | reply -1 after 4 sends, twice |
| read of the command byte after `0x60` write | returns the written value | needed or the PROM repeats the write 5 times |

Setting the timeout bit speeds the keyboard probe from about 0.4 s to a few polls and is accepted by both the PROM and the kernel; leaving it clear is accepted as well. A data byte of `0xff` read with output-full is ignored by both. A reply of `0xfe` is resent up to 3 times, then returned, and the probe treats any returned byte other than -1 as a keyboard, so a model must not answer `0xfe`.

## Unknown

- The ARCS open failure code for a missing keyboard peripheral and where the first error lines are printed.
- What the real controller drives for an unconnected keyboard or mouse.
- Whether IP22 (Indigo2) or IP28 PROM images differ from the IP24 image; no image is held for either.
