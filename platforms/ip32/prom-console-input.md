# O2 PROM 6.5.30: what it does when no PS/2 keyboard or mouse answers

Question. On the O2 (IP32) the PROM talks to the keyboard and mouse through the two PS/2 ports in the MACE I/O chip. How does it decide a keyboard or mouse is absent, which registers does it touch, and what does it do with the console?

Method. Disassembly of the shipped O2 PROM image `ip32prom.image` (6.5.30 media, sha256 `11230c353cb14fcc50ede286df228e169e32fc9e5a2206276ae29c259fafb23c`). The image is unpacked and runs from an address with file offset 0 at `0x80ff6cf8`; that base was found by matching string references (about 480 consistent hits) and is inferred. Addresses below use it. Read against the public 6.5.7 PROM library source (`stand/arcs/lib/libsk/io/mh_kbd.c`, `saio.c`; not quoted) and the published `prom(1M)` manual page. The kernel side is in kudzu (`software/kernel/headless-keyboard-ip22-ip32.md`). The Indy and Indigo2 page is [../ip22/prom-console-input.md](../ip22/prom-console-input.md).

Grades: **established**, **software expectation**, **inferred**, **unknown**. No hardware capture of a headless O2 is held, so nothing is **observed**.

## Controller registers

| Item | Value | Grade |
|---|---|---|
| Keyboard port base, mouse port base | physical `0x1f320000`, `0x1f320020` (`lui 0xbf32` in the poll routine) | established |
| Registers in each port (64-bit) | transmit buffer `+0x00`, receive buffer `+0x08`, control `+0x10`, status `+0x18`; the PROM reads status at `+0x18`/`+0x38` and receive at `+0x08`/`+0x28` | established |
| Control bits | `0x01` inhibit clock after transmit, `0x02` transmit enable, `0x04` transmit interrupt, `0x08` receive interrupt, `0x10` assert clock | established (source header) |
| Status bits | `0x01` clock, `0x02` clock inhibit, `0x04` transmitting, `0x08` transmit buffer empty, `0x10` receive buffer full, `0x20` receiving, `0x40` parity error, `0x80` framing error | established (source header; the PROM tests `0x10`, `0x40`) |
| Chip revision | bit `0x10` of the ID register at physical `0x1f310000`; clear means the older MACE, whose received byte is shifted right one bit with parity carrying bit 7; set means parity errors are retried | established (source) |
| Device replies | as on Indy: `0xfa` acknowledge, `0xfe` resend, `0xaa` self-test passed, `0xff` overrun | established |

The PROM fixes the ports: keyboard is port 0 and mouse is port 1. It does not identify devices by reply, unlike the kernel. Established (source: constants; the binary uses the two bases as above).

## 1. How absence is detected

One routine sends and waits (file offset `0x28e78`, address `0x8101fb70`): wait for the transmitter to be free, write control 0, wait 100 us, write the byte to the transmit buffer, write control `0x12` (transmit enable and assert clock), then poll the status register up to 400 times, 250 us apart, for receive-buffer-full. Established.

- Receive-buffer-full set: read the byte (2 us after). Reply `0xfe`: send again (counts against the retry budget). Reply `0xff`: ignored, keep polling. Otherwise return the byte. On the older MACE the byte is shifted and the parity bit supplies bit 7 first. Established.
- Parity error set on the newer MACE: read and drop the byte, send again. Established.
- 400 empty polls: send again. **3 retries after the first try, 4 sends in all** (counter value 3 and 400 in the code at `0x8101fbb0`, `0x8101fbc4`), then return -1. About 100 ms per send, so a silent port costs about 0.4 s per command (inferred from the delay constants). **MACE has no timeout bit: an absent device is only found by the 400-poll timeout.** Established.

Keyboard probe (source): drain the receive buffer (up to 25000 reads), send `0xf5`, and send it again while the reply is `0xaa`. -1 means no keyboard; any other reply counts as a keyboard. Present: bell, then scan set 3 and make/break on selected keys. Established. Software expectation: `0xf5` is acknowledged with `0xfa`.

Mouse probe (source): drain, send `0xf6`; if not `0xfa`, once more (2 x 4 sends at most); only `0xfa` counts. Then sample rate 40 (`0xf3 0x28`). Established. There is no controller command byte on MACE, so none of the Indy command-byte steps exist.

A keyboard answering the probe registers an ARCS `keyboard()` peripheral under the `pckbd` controller; a mouse registers `pointer()`. A missing keyboard leaves only the controller node. `nogfxkbd` starting with `1` registers the keyboard anyway (the PROM image contains the variable name twice). Established (source; binary strings).

## 2. What the PROM does with the answer

The console code is the same as on Indy. The image contains the strings `Cannot connect to keyboard -- check the cable.`, `CONSOLE OPEN FAILED.` and `Cannot open any console!`, the open routine at `0x81016b7c` (file offset `0x1fe84`) compares the open result with 13 (ARCS ENODEV) before printing the keyboard-cable line, and it has the retry and fallback structure described below. Established.

- `ConsoleOut` is `video()` and `ConsoleIn` is `keyboard()` when `console` is not `d` and the machine has graphics; otherwise both `serial(0)`. The image also holds `serial(1)`, so `d2` can select the second port (inferred from the string; the selecting code was not located). Established for the first rule (source), inferred for the second.
- Open `ConsoleIn`, then `ConsoleOut`. With no keyboard peripheral the first open fails. It prints `Cannot open keyboard() for input` (preceded by the cable line only on code 13), recomputes both variables and retries once, then, if `console` does not start with `d`, sets `NoAutoLoad` to `CONSOLE OPEN FAILED.`, forces both to `serial(0)` and opens again. `console` itself is not rewritten and stays `g`. Established.
- Net effect: `console=g`, no keyboard, no `nogfxkbd`: serial console, autoload suppressed, the command monitor waits. Matches `prom(1M)`. With `console=d` or `nogfxkbd=1` absence has no effect. Established.
- Which code a missing peripheral returns, and where those first lines are printed, is unknown.

## 3. Kernel reaction

See the kudzu page: the kernel finds the two devices itself, keeps its own present flags, never reads `ConsoleIn` or `ConsoleOut`, and a missing keyboard does not stop the graphics textport. Linux `arch/mips/sgi-ip32/ip32-setup.c` only acts on a `console` starting with `d`; it does not look at keyboards. Published code, confirms only.

## 4. Mouse without keyboard, keyboard without mouse

- Keyboard missing, mouse present: serial fallback. Keyboard present, mouse missing: console stays graphics; the mouse probe adds up to 8 sends. The two probes are independent. Established (source).
- A keyboard plugged into the mouse connector is not found by the PROM (it looks at port 0 only) although the kernel would accept it. Established.

## 5. What an absent device looks like at the controller

Software expectation: this is what the PROM accepts as "absent". No capture or specification statement says what real hardware shows beyond "the receive buffer never fills".

| Step | A model must make the PROM see | Result |
|---|---|---|
| any transmit | transmit buffer empty (`0x08`) and not transmitting/receiving within about 40 ms | otherwise each command waits 1/4 s first |
| `0xf5` on port 0 | status without `0x10` for 400 polls, 4 times | reply -1, no keyboard |
| `0xf6` on port 1 | status without `0x10` for 400 polls, up to 8 times | reply -1, no mouse |
| a present device | `0x10` set within 100 ms and the byte `0xfa` in the receive register (low byte; model the newer revision, ID bit `0x10` set, so no bit shifting) | present |

Do not answer `0xfe`, and do not set the parity bit on an absent port: either makes the PROM retry or flush instead of timing out.

## Unknown

- The ARCS open failure code for a missing keyboard peripheral and where the first error lines are printed.
- What real MACE shows on an unconnected port other than "no receive-buffer-full".
- The exact load address of the unpacked image (inferred above); instruction text and data were matched consistently but no loader description was found.
