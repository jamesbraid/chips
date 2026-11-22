# SGI Visual Workstation 320 and 540: audio open questions

Open points from the [Lithium audio page](../devices/lithium/audio.md). Each entry: question, routes tried, what would settle it.
The only Lithium source held is software (three builds of the NT audio driver, the Linux Visual Workstation driver); no
Lithium specification is held and none was releasable. The AD1843 data sheet is held.

## 1. The serial-slot field in the channel configuration word

[missing source] Linux writes 2 in bits 6:4 of both configuration words; the NT driver's copy starts at zero and no code path
sets the field, so it writes 0. Routes tried: every write site of the configuration word in the Windows 2000 build read; the other
two builds were read for the start path only. Next: the Lithium specification, or a real machine run with the field changed. Until then a model may ignore the field.

## 2. What raises the audio interrupt, and whether line 22 is the audio line

[missing source] Only Linux uses the interrupt (Cobalt line 22, status `+0x10`, mask `+0x14`); the NT driver polls. The bit roles
are Linux's names and the write-one-to-clear behaviour is read from its use. Reset state of the mask, and whether the status
reflects the raw condition or only enabled ones, are unread. Routes tried: all three NT builds (no use), Linux. Next: the
Lithium specification, or a Linux boot with a log of the status word.

## 3. Trigger pointer and mask, underflow, overflow and the idle state

[missing source] How the trigger pointer and mask raise an interrupt is Linux's description. What the engine does when the
software and hardware pointers meet (stop, repeat the last sample, output the silence word), what the enabled output channel does
between a stop and the next start (the NT driver leaves it enabled), and when the status word's underflow bit sets, are not read
from any binary. Next: the specification; a fake that tracks both pointers can model "stall and repeat" and "output silence" and
the NT driver cannot tell the difference except through the audible result.

## 4. How long the codec busy flag stays set, and link failure

[missing source] The NT driver waits up to 360 ms and Linux 2 ticks; the real duration of a codec register transfer is unknown
(the data sheet sends a control write in slot 1 of the following serial frame, so about a frame, but the engine's own latency is
not stated). What happens to a transfer when the codec is absent (bit 2 of `+0x00` set) is unread.
Next: the specification.

## 5. The three undocumented words and the other five channel rows

[missing source] `0xff00f000 + 0x500` (silence sample), `0xff010000 + 0x98` and `+0x9c` (copies of the channel pointers) are
named only in Linux comments. The driver's table has seven channel rows; rows 2 to 6 may exist in the silicon (the video capture
driver uses neighbouring time-stamp pairs). Next: the specification; no software read here touches rows 2 to 6 of the audio table.

## 6. DMA reach above 4 GiB

[missing source] The base register holds a shifted 40-bit address with a coherence bit (Linux's comment); the NT driver asks for
memory below 4 GiB. Whether the engine decodes the upper bits is unknown. Matters only for a machine with more than 4 GiB of guest RAM.

## 7. Whether `sgisound.dll` installs and runs on Windows XP

[route: a test boot] The kernel driver imports nothing XP lacks as far as the import list shows (not checked against an XP image),
and asks the HAL for nothing beyond a stall and spin locks. The user-mode driver, which creates the kernel service and issues
the device-control calls, was read for imports and strings only. Next: install the 5.2.2 Windows 2000 pack on an XP guest and
see whether the mixer and wave devices appear; read the DLL's install entry if they do not. A 64-bit XP needs a new kernel
driver in any case.

## 8. Enabling line 22 through the NT HAL

[route: a test boot, or reading the HAL's enable path] `HalGetInterruptVector` on the internal bus with level 22 returns vector
`0xb2` and `HalEnableSystemInterrupt` would write the controller's entry for line 22 with no bridge bit; nobody calls it for
audio, so that it works end to end is a reading of the HAL, not an observation.
