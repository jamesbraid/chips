# Windows 2000 text-mode Setup: the wait in `setupdd.sys`

Windows 2000 text-mode Setup (RTM 5.0.2195 and SP4 5.0.2195.6717, started through the SGI loader with SGI's `halborg`
build as `hal.dll`) was seen spinning at one address in `setupdd.sys` on an emulated 320, with a black screen. This page
says what that loop waits for. Short answer: it is Setup's idle wait for a keystroke at the Welcome screen, not a hung
dependency on the video miniport or the HAL.

Grades as in the [README](README.md). **Sources and limits.** The structural reading of `setupdd.sys` (what writes the
word, the call chain) comes from a static pass over both builds made on 2026-11-23, with Ghidra and objdump. The two
installation images were not available to re-open for this page, so those statements are *inferred* here wherever no
emulator run confirmed them; where a run did confirm one, it is marked *observed*. The HAL frames in answer 4 were read
directly from the HAL files for this page. Emulator runs show model behaviour, not hardware behaviour. Nothing is copied
from the binaries; names are the drivers' own export names, and anonymous routines are described by role.

## The loop

`SpkbdGetKeypress` (a `setupdd.sys` export) clears `ecx`, compares a doubleword in the driver's own data with it, jumps
back while equal, then loads the word, stores zero back and returns it. `SpkbdIsKeyWaiting` tests the same word without
waiting. One small routine clears it. These four accesses and the writer in answer 1 are every reference to it, in both
builds.

| Item | RTM | SP4 |
|---|---|---|
| Poll routine (RVA) | `0x18680` | `0x18716` |
| Mailbox word (RVA) | `0x5669c` | `0x5715c` |
| Writer (APC routine, RVA) | `0x186ae` | `0x18744` |
| Wait routine (`SpWaitValidKey`) | `0x13a4d` is its return into the caller | `0x13adb` likewise |
| Welcome routine; main Setup routine; IOCTL handler | `0x15f64`; `0x26a06`; `0x12c50` | `0x1635c`; `0x26dfe`; handler return sites `0x12dca`, `0x12df3` |

## 1. Writers of the word

One writer stores a non-zero value: the completion routine of an asynchronous `ZwReadFile` on
`\Device\KeyboardClass0`. *Inferred* (static reading); the identity of the routine is *observed*: the pending read IRP on
the stalled RTM guest has its user APC routine field (IRP offset `0x30`, `Overlay.AsynchronousParameters.UserApcRoutine`)
equal to the RTM routine's address `0xfd71c6ae`, with the user IOSB pointer (offset `0x28`) pointing into `setupdd.sys`'s own
data next to the mailbox.

- Context: a kernel APC routine, queued by the I/O manager to the thread that issued the read when the keyboard class
  driver completes it. It is not an interrupt routine, DPC, timer, work item or second thread. It runs at passive level on the
  thread that is spinning (the Session Manager's main thread, inside its first device control call, code `0x220000`, on
  `\Device\Setup`). *Inferred*.
- Value and event: it takes the byte count from the status block, walks that many bytes of a 120-byte buffer as 12-byte
  keyboard input records, translates each through the loaded keyboard layout into a character or Setup key code, and stores
  any non-zero result in the word. While a "keep reading" flag is set it reissues the read with itself as the APC routine, so
  one read is always outstanding. The first read is issued by the keyboard-layout setup routine (RTM `0x18590`). *Inferred*.
- The handle is opened by Setup itself without the synchronous flag, so the read is asynchronous. The set-indicators
  control code (`0x000b0008`) is sent to the same device and nothing waits on it. *Inferred*.

## 2. What the caller chain does before it waits

*Inferred* from the stalled stack, which maps onto one chain in both builds: the spin is in `SpkbdGetKeypress`, called from
`SpWaitValidKey`, called from the Welcome routine, called at RTM `0x26b83` (return `0x26b88`) from the main Setup routine,
called from the control-code handler. The other two words from the stack (RTM `0x12d3c`, SP4 `0x12dca`) are only returns from
a handle-resolving helper earlier in the same handler.

The Welcome routine draws one screen and waits for one of: ENTER (continue), ESC, and two function keys (F3, which opens the
quit confirmation, and the repair key). It matches the NT 4.0 Welcome structure (ENTER, R, F3). The screen identity is
inferred from that structure; the message text was not read. *Observed* in a later run: the first ENTER left this routine and
Setup moved on to the next screen.

Before reaching it, the main routine had already finished display setup (opening `\Device\Video0`, mode list, set mode, map
video memory, clear the screen), opened the keyboard class device, read `txtsetup.sif`, loaded the layout table and issued the
first read. A missing device or a failed control call there loops forever after drawing an error, so that none of it is the
thing waiting is *inferred* from the Welcome routine being on the stack. The video control codes seen are `0x23040c` (set
mode), `0x23041c` and `0x230418` (colour and palette writes); the `ntddvdeo.h` names for these were not rechecked.

## 3. What the writer needs, and NT 4.0

The word is set only when a keystroke reaches a completed read on the keyboard class device. On this machine the module list
has `kbdclass`, `kbdhid`, `hidclass`, `hidusb`, `usbhub`, `uhcd` and no `i8042prt`, and the interrupt table has no keyboard
vector, so the only path is USB HID: the keyboard on the UHCI root hub, then `uhcd`, `usbhub`, `hidusb`, `hidclass`,
`kbdhid`, `kbdclass`, then Setup's read. The video miniport and the HAL's display code are not on it (*inferred*; nothing in
the writer touches them).

*Observed* on the model: with the keyboard enumerated and polled (the interrupt-IN transfer answering NAK), a QMP key event
for ENTER completed the transfer twice (key down and key up), `uhcd`'s vector fired, the CD was read next, and Setup went on
to its next screen. So the chain USB device, UHCI, `uhcd`, `kbdclass`, APC works on the model, and the spin is the key wait.
The hang came from no key being sent, not from a model defect on this path.

Why NT 4.0 Setup did not appear to hang: *unknown*. The NT 4.0 `setupdd.sys` was not read here. It reached a visible
Welcome screen on the same model, which suggests it idled in the same kind of wait with its screen showing (the earlier run
only sampled it); whether it takes keys from a different path is not established.

## The black screen is separate

*Observed* in the same run: Setup's text was in the model's frame buffer in RAM (blue background, grey and white glyphs, 1024-byte
row pitch at 640x480, 8 bits per pixel), the colour map held the sixteen text colours, the model's mode word had the
gamma-bypass bit clear, and the gamma map read as all zero because the guest never wrote it. The model sends every pixel through
the gamma map unless bypassed, so the screen dump was black. GUI-mode Setup drew normally later. What the real chip does with an
unwritten gamma map is *unknown*; nothing here says. This does not affect the wait above.

## 4. The two `hal.dll` stack words

Both builds' stack words (RTM `hal.dll+2790` and `+27e8`; SP4 `+27a0` and `+27f8`) are exact entry points of exported
routines in SGI's HAL, which I read for this page (RTM `halborg` 5.00.2168.1, image size `0x244c0`; SP4 image size `0x245e0`,
both equal to the loaded sizes in the stall dump). *Established* for the mapping, by export table and the routine bodies:

| Stack word | Export | What it does |
|---|---|---|
| RTM `+2790`, SP4 `+27a0` | `KfRaiseIrql` | Looks up the new level's task-priority value, writes it to the local APIC task-priority register (`0xfffe0080` in the HAL's mapping), returns the previous level by table lookup on the old register value |
| RTM `+27e8`, SP4 `+27f8` | `KfLowerIrql` | Writes the table value for the given level to the same register; no software-interrupt dispatch in the routine itself |

The HAL implements IRQL as the local APIC task priority, so these are the kernel's raise and lower calls. Because each word is
an exact function entry, not an address after a call, it is not a return address: the stack words are *inferred* to be stale
function pointers or leftovers, not live frames. The live frames are the `setupdd.sys` ones. A third word, RTM `hal.dll+3c24`
(SP4 `+3c44`) near the bottom, is `KeReleaseQueuedSpinLock`, likewise an entry address.

The only HAL dependence of the spin is therefore the IRQL path and, for the APC, the software-interrupt path
(`HalRequestSoftwareInterrupt`, RTM `+3278`), which raises the APC and DPC levels through the local APIC.

## Settled and open

| Statement | Grade |
|---|---|
| The spin is Setup's key wait at its first prompt | observed (ENTER released it) |
| Writer is the keyboard read's APC routine; its address equals the IRP's APC field | observed (RTM address); inferred (role and SP4) |
| No video or HAL service is needed to leave the wait | inferred |
| The two HAL words are `KfRaiseIrql` and `KfLowerIrql` entries and are not live frames | established (mapping), inferred (stale) |
| Why NT 4.0 Setup looked different | unknown; reading its `setupdd.sys` and checking whether it saw keys over PS/2 or USB |
| What real hardware shows with an unwritten gamma map | unknown |

Smallest experiment that would also firm up the writer on SP4: on an SP4 guest stalled in the loop, read the pending read
IRP and compare its APC field at offset `0x30` with `0xfd71c744`, then send ENTER and watch the loop exit. It is the same
test that was already run on RTM.
