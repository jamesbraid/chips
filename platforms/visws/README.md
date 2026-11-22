# SGI Visual Workstation 320 and 540 (Linux name "visws")

An IA-32 workstation SGI sold in 1999 and 2000 with Windows NT, built from SGI's own system chips and a few standard
PC parts. It is an x86 machine, outside the MIPS and IA-64 scope of the rest of this repository, and was added because its
chips are SGI's and its Linux platform code is public. This page is the overview; the chips have their own pages and
the details are in the sub-pages.

Status: the primary target is the Windows NT 4.0 and Windows 2000 system SGI shipped, so the shipped software ranks
first: SGI's HAL (`halborg.dll`), the SGI drivers, and the system firmware (PROM 1.0002 to 1.1005, see [firmware.md](../../software/visws/firmware.md) for which are held), all read in Ghidra
([software/visws](../../software/visws/README.md), [NT drivers](../../software/visws/nt-drivers.md)). The public Linux
platform code is a second, later source. **No manual or chip specification is held**
([what was read and what is missing](../../references/visws-sources.md)). Grades follow [the repository rules](../../AGENTS.md)
with one addition for this machine: a fact that only Linux states is a *software expectation of Linux*, graded
`inferred`, not `established`, because Linux ran on the machine only as an unsupported port written after the fact. A
fact is `established` here when a shipped binary, a published SGI document or the firmware agrees. Posts are `inferred`
at best. The older pages in this directory still say "established" for Linux's behaviour; read that word as "what
Linux does", and use the table below for what rests on what.

## Sources by origin

Count of graded items in the register definitions ([Cobalt](../../devices/cobalt/registers.toml),
[Lithium](../../devices/lithium/registers.toml); 99 registers, fields and constants at the first count, 102 now) before and after checking each against
the shipped Windows software. The rows are the first count; the paragraph after the table gives the changes since:

| Origin of the item | Cobalt | Lithium | What happened |
|---|---|---|---|
| Linux and a shipped binary agree | 26 | 26 | Stay `established`; the page names the binary. |
| Number agrees, name is Linux's only | 6 | 0 | The four video interrupt entries 16 to 19 (the SGI video capture driver uses levels 16 to 19, and only Linux says which are in and out) and the two graphics-engine entries 24 and 25 (the graphics miniport connects handlers to both; only Linux names them). Stay `established` for the number. |
| Shipped binary differs or measures instead | 2 | 0 | The core clock rate (the HAL measures it) and the first IDE entry (the HAL uses 1, 4 or 5 by board generation). Linux's value re-rated `inferred`. |
| Only Linux states it | 3 | 36 | Re-rated `inferred`, a software expectation of Linux: 30 `established` items became `inferred` on the Lithium page (six were already `inferred`) and two on the Cobalt page (one was already). |

Since that count (second reading of the HAL and the audio driver): twelve Lithium items moved from "only Linux" to "Linux and a shipped binary agree" and are `established` again (the audio DMA pointer, size, enable, format, mode and direction fields, the link-failure bit, and the four time-stamp and counter registers); three new items have only a shipped binary behind them (two Cobalt control-register fields, bits 0 and 1 of the CPU control word, and the count of audio DMA channel sets). So the Lithium column is now 38 / 0 / 0 / 24 and the Cobalt column 26 / 6 / 2 / 3 with two new binary-only items (entries 24 and 25 moved to "number agrees" in review: the graphics miniport uses both).

Linux-only items by group (first count; the audio ring-buffer control and configuration fields and the time-stamp and counter words are no longer on it): the processor limit; the audio interrupt entry (22);
the bridge bus-number word; the audio interrupt status and mask bits; the audio ring-buffer control and configuration
registers; the audio time-stamp and media-stream counters; the bridge PCI ids; the DMA chunk size. The shipped audio driver
was read for the codec access path and the ring base register only, so the control and configuration registers are
`inferred` until it is read further.

Platform facts, by what supports them:

| Fact | Linux | Shipped Windows or firmware | Now rated |
|---|---|---|---|
| Cobalt, Lithium and local APIC windows and the register offsets Linux touches | yes | HAL initialisation, same addresses | established |
| Cobalt timer clock | assumes 100 MHz | HAL calibrates against the RTC; the performance counter is the TSC | established (HAL) |
| Interrupt entry numbering (clock 28, NMI 29, 8259 at 12) | yes | HAL tables, with a different layout for the Cobalt Lite revisions | established |
| PCI pin to Cobalt entry map for bridge B | contradictory (Linux 2.6 reuses bridge A's) | HAL table: shared pins on entries 13 to 15 | established (HAL); Linux's map is `inferred` wrong |
| Board type and revision | port `0xfb2` probe, 540 branch unreachable | firmware's configuration tree carries both bytes | established (firmware) |
| PCI configuration cycles | ports `0xcf8` and `0xcfc` | memory-mapped address and data registers inside each Lithium bridge window (`+0xf8`, `+0xfc`) | both established; they are different mechanisms, see [Lithium](../../devices/lithium/README.md) |
| Which bridge is bus 0 | inferred only | the firmware numbers bridge B first (counter starts at -1, so B is bus 0, A gets the next number); the HAL numbers B's window first too | established (firmware, `1.0006@0xf1f6f0`) |
| Processor table at `0x1e00` | reads it | HAL reads it too; written by the firmware side | established |
| PIIX4 and NS87307 set-up, soft power, reboot | partly | the boot block sets the chips up (power-management base `0xf80`, GPIO `0xfc0`, NS87307 power management `0xfc8`); the HAL reads the NS87307 bases back, steers six legacy interrupts through the NS87307, and does soft power and reboot, but never sets the PIIX4 power-management base | established (HAL, firmware) |
| Memory controller and graphics memory split | none | HAL reads error and ECC registers only; the firmware's self-test probes the RAM and writes the sixteen bank registers, and `gfxmem_alloc` carves the graphics memory from `cogfxmem` ([boot-path.md](../../software/visws/boot-path.md#memory-controller-and-graphics-memory)) | firmware part established; the bank register bits inferred |
| Contents of the PCI interrupt line register | not stated | the HAL writes a first-use ordinal, 1 to 16, and its bus handler maps the ordinal back to the Cobalt entry | established (HAL) |
| System-side address of each bridge's PCI memory window | none | bus `0x80000000` to `0x83ffffff` at `0xf4000000` (bridge B) and `0xf0000000` (bridge A) | established (HAL translation routine and initial data) |
| Cobalt APIC id at start-up | sets the enable bit only | the HAL and the firmware both write 4 into bits 27:24 when they read zero; reset value unknown | established that both write it; reset value unknown |
| Interrupt routing mode names | none | HAL boot options `INTRROUTE=` `DEFAULT`, `NO8259`, `IDE8259`, `HUGH006` | established (HAL) |
| Audio engine register file | most of it | sgisound.sys 5.2.2: codec port and base register only | partly established |
| Ethernet device | Intel 82557 per Linux 2.2 header | SGI INF matches PCI 8086:1229 revisions 1 and 2 | established |
| USB | PIIX4 UHCI | SGI USB driver matches PIIX4 (8086:7112) and PIIX3 (8086:7020, revision 0 rejected) | established |
| Video interrupt entries 16 to 19 | in and out named | SGI video capture driver uses levels 16 to 19 | numbers established |
| Graphics-engine interrupt entries 24 and 25 | named `AS` and `RE`, unused | graphics miniport asks the HAL for both vectors and connects handlers | numbers established |

| Page | Covers |
|---|---|
| [boot-and-detection.md](boot-and-detection.md) | How the kernel recognises the machine, board type and revision, the processor table, memory, reboot and power-off |
| [interrupts.md](interrupts.md) | Interrupt routing end to end: device to Lithium to Cobalt to processor, the PIIX4's cascaded 8259s, board-revision exceptions |
| [documents.md](documents.md) | What the published documents (owner's, install and audio/video guides, the Microprocessor Report article, the Tech Monitor piece) say about the chips, set against the Windows software |
| [model-needs.md](model-needs.md) | What an emulator needs to boot Linux 2.6 on it |
| [../../devices/cobalt/README.md](../../devices/cobalt/README.md) | The system ASIC: timer, revision, interrupt controller, memory |
| [../../devices/lithium/README.md](../../devices/lithium/README.md) | The I/O ASIC: the two PCI bridges and the audio engine |

## Models

| | 320 | 540 |
|---|---|---|
| Processors | One or two Pentium II, Slot 1, 100 MHz front-side bus; a terminator module sits in an empty second slot; both must run at one speed. Later units took Pentium III (posts, inferred) | One to four Pentium III Xeon, Slot 2; a voltage regulator per processor |
| Memory | Two groups (A, B) of six non-standard DIMMs; each group empty (B only) or six DIMMs of 128, 256 or 512 MB: 128 MB to 1 GB | Four groups (A to D) of six DIMMs, A always populated, filled in order: 128 MB to 2 GB |
| IDE | Two UltraDMA/33 channels (the PIIX4's): system and option drive; CD or DVD with a removable drive | One UltraDMA/33 channel (CD) |
| SCSI | Option PCI card | Ultra2 SCSI system drive and bays. The board specification lists no SCSI port, so the controller is a PCI card (inferred; a sales listing names a single-channel Ultra2 SCSI PCI card among the machine's parts). The kernel's QLogic driver has an MMIO setting keyed to this platform |
| PCI slots | "One PCI 64-bit 33 MHz bus ... that supports the PIIX4 IDE interface and the three PCI slots" | "Two PCI buses, one with four slots and one with two. All slots are 33 MHz, 64 bit." Slots 1 to 4 take 5 V and universal cards, 5 and 6 take 3.3 V and universal |
| Other on-board | Two USB, two IEEE 1394 (400 Mb/s), one RS-232 serial port with separate DMA channels for each direction, parallel, floppy, 10/100 Ethernet, analog audio (line, mic, headphone) and video (composite and S-Video in and out); optional digital flat panel connector | The same list |
| Board revisions the kernel knows | 4, 5, 6 (derived from a 7-bit board id) | 2 |

Memory, processor, slot and port rows are the SGI owner's guides: *Silicon Graphics 320 Visual Workstation Owner's Guide*
007-3701-001 (printed pages 24 to 25 and Appendix A, table A-3) and *Silicon Graphics 540 Visual Workstation Owner's
Guide* 007-3882-001 (printed pages 28 to 31 and Appendix A, table A-5). They are user documentation: they state what the
machines have and say nothing about the chips or registers. The revision row is the kernel's board probe (established,
see [boot-and-detection.md](boot-and-detection.md)). Differences the guides and the kernel agree on: one IDE channel on the 540
against two on the 320 (the second IDE interrupt line is "only on 320"), and the processor and memory counts above.

Two things the guides and the kernel's naming do not settle. The 320 guide describes **one** PCI bus holding the
PIIX4 and three slots, whereas the kernel finds two Lithium bridges on every machine, each with a bus of its own; the 540
guide describes two buses of 4 and 2 slots. How the on-board devices (Ethernet, the PIIX4, the 1394 and USB functions)
and the slots divide between bridge A and bridge B is therefore **unknown** as a physical layout, as is which bus a SCSI card sits on. What the HAL's pin tables do settle is which device numbers have an interrupt wired: on bridge B devices 0 to 3 have all four pins and device 4 is the PIIX4 (only the USB function's pin D); bridge A has devices 0 to 4 on the oldest board generation; on the middle generation devices 0 and 1 (four pins) and 3 (pin A only, the Ethernet in Linux's comments); on the newest devices 0 and 1 (four pins) and 2 and 3 (pin A only) ([nt-hal.md](../../software/visws/nt-hal.md#interrupt-delivery-in-the-hal)). The earlier 1999 post's claim that both buses are 3.3 V is contradicted for the 540 by the guide (slots 1 to 4
accept 5 V cards); the guide governs.

The kernel documentation says both models "are based around the Cobalt, Lithium, and Arsenic ASICs", with a PIIX4 and a
National Semiconductor 87307 Super I/O "to provide legacy device support (IDE, serial, floppy, and parallel)", and that
the chipset "largely conforms to the PC architecture with some notable exceptions such as interrupt handling"
(established, Documentation/sgi-visws.txt, removed with the code).

## Topology

```
 1..4 x86 processors (front-side bus)
        |
     Cobalt  ---- memory (banks; the top 8 MB is the frame buffer)
     |  |  \--- 3D engine, video DMA ---- Arsenic (video in/out; not covered)
     |  \--- interrupt controller ("Cobalt APIC", 30 lines, delivers to the processors' local APICs)
     |
   Lithium ---- PCI bridge A (bus 1?)  ---- Ethernet (Intel 82557, device 3), option slots
          |---- PCI bridge B (bus 0?)  ---- PIIX4 (device 4: IDE, USB, power management, 8259 pair)
          |                                   \--- ISA-style bus: NS87307 Super I/O (serial, parallel, floppy)
          \---- audio engine ---- AD1843 codec
```

- Lithium is both of the PCI bridges and the audio engine (established); the diagram's bus numbers are inferred (see
  [the Lithium page](../../devices/lithium/README.md)). The Arsenic link, the video paths and the 3D engine are not described by any code read.
- The PIIX4 is a normal Intel PIIX4 with SGI's wiring: its two 8259s are not wired to the processor; their combined
  output goes to one Cobalt interrupt line. Its USB function has a line of its own. Its IDE channels drive Cobalt
  lines directly, not the 8259 (established; [interrupts.md](interrupts.md)).
- The NS87307 is at the usual Super I/O index and data ports. SGI uses its GPIO block for the board revision, and for the
  320 rev 5 board its UART interrupt is switched off because that board's legacy interrupts reach Cobalt by a second route.
- One physical address map is visible in the code, and it is thin: the Cobalt CPU block, the Cobalt interrupt controller,
  the two Lithium bridge windows, the audio pages and the processor table. The rest (memory map, PCI windows, flash) are
  unknown.

| Physical address | What |
|---|---|
| `0x00001e00` | 16-bit processor count; processor table at `0x1e02` (written by firmware) |
| `0xc2000000` | Cobalt CPU block (revision, timer) |
| `0xc4000000` | Cobalt interrupt controller |
| `0xfc000000` | Lithium bridge A window |
| `0xfd000000` | Lithium bridge B window |
| `0xff001000`, `0xff00f000`, `0xff010000` | Lithium audio register pages |
| `0xff005000` (`0x20` bytes) | the I2C master of the optional analogue video board, as SGI's NT `sgijack.sys` uses it ([NT drivers](../../software/visws/nt-drivers.md)); the ASIC that decodes it is unknown |
| `0xfee00000` | Local APIC of each processor (Intel default) |

I/O ports of note: `0x2e`/`0x2f` Super I/O index and data; `0xf80` PIIX4 power-management block (set by firmware,
the kernel assumes it); `0xfc0` Super I/O GPIO block and `0xfc8` its power-management block, both placed there by the
kernel; `0xcf8`/`0xcfc` PCI type 1 configuration; `0xcf9` reset control.

All of this is established as the kernel's choices. Nothing says what the firmware decodes elsewhere.

## Life of the Linux code (established, public history)

2.2 had a `CONFIG_VISWS` special case sprinkled through the generic i386 code, with different wiring tables per board
revision. A December 2001 patch split it into its own file ("unmaintained for moons"). It was a sub-architecture,
`arch/i386/mach-visws`, from 2.5.63 to 2.6.23; Ingo Molnar's patch of 10 July 2008 turned it into quirks inside the
generic x86 code in 2.6.24; H. Peter Anvin deleted it in February 2014, for 3.15, with the message that the machine "seems
to be dead". The last working kernel for an emulator to target is therefore 3.14, though 2.6.x is what the maintainers
last exercised. The register facts are unchanged across all versions; only the interrupt numbering and the use of the
per-revision wiring tables differ. [Details](../../references/visws-sources.md).
