# Visual Workstation 320 and 540: the Windows NT 4.0 HAL

SGI's HAL for the pair is `halborg.dll` (multiprocessor) and `halbrgup.dll` (uniprocessor), both from Recovery CD-1 v1.1 (byte-identical copies are in `\I386\` of the SGI 320 NT 4.0 install CD, Disk 1, in the Internet Archive item `sgi-vw-drivers`),
file revision strings "1.3", linked 1999-04-27 (PE timestamps), image base `0x80010000`, native-subsystem DLLs that
import only `ntoskrnl.exe`. Each has a matching CodeView symbol file (`halborg.dbg`, `halbrgup.dbg`), which names about
1,050 symbols and the 75 object files it was built from. The two HALs share all symbols except thirteen
multiprocessor-only ones (the real-mode start stub, the processor table reader and the processor start routines).
`halborg.dll` was read through Ghidra, with the debug-file names applied, covering the routines listed at the end; the
uniprocessor HAL and the remaining routines (bus-handler plumbing, DMA adapters, the PCI resource code beyond
enumeration, console output) were not read. SHA-256: `halborg.dll` `0926cd50…4a048`, `halbrgup.dll` `21978c78…f7de8`.
Grades as in the [README](README.md); unless stated, a fact is established for the routine named.

"Borg" in the file names is the Cobalt platform's name inside SGI (the PCI configuration accessors are named
`TypeBorg`). Neither source text nor listings are reproduced.

## Source modules

The build record lists these objects, which gives the shape of the code: bus and range support (`bushnd`, `rangesup`,
`drivesup`), PCI (`pciconf`, `pcidata`, `pcienum`), the board chips (`cobalta` and `lithium` for Cobalt and Lithium,
`ns97307` for the NS87307, `8259`, `ixnmi`, `power`, `memerr`, `flash`, `environ`, `arcinfo`), multiprocessing
(`mpsys`, `mpinfo`, `mpconfig`, `mpsproc`, `mpipi`, `mpirql`, `mpsysint`, `mpswint`, `mpspin`, `mpprofil`, `mpdetect`,
`mpdebug`), timing (`clockc`, `clocka`, `xxtime`), displays (`display`, `vga`, `gbe`), two I2C layers (`lli2c`,
`mli2c`, for monitor and flat-panel identification), `cacheop`, `serial` (debug port), `registry`, `sgcallbk` (a
callback table, `sgixCallbackRegister`, used by SGI drivers) and the usual x86 NT HAL files.

## Cobalt registers the HAL programs

Physical blocks, mapped uncached at processor 0 start-up (`HalInitializeProcessor`): CPU block `0xc2000000`, APIC
block `0xc4000000`, memory-controller block `0xc6000000`, and the ordinary local APIC at `0xfee00000`. The Linux names
below are from `asm/visws/cobalt.h`; the HAL agrees wherever both touch a register.

**CPU block (`0xc2000000`).**

| Offset | Use | Grade |
|---|---|---|
| `+0x08` | Revision. Values `0xa0` and `0xa8` mean "Cobalt Lite": no ECC, no memory error reporting, no cache-operation invalidate, and different APIC entry numbers for the clock and NMI (below). | established |
| `+0x10` | Control. Bit 0: ECC checking on (set with bit 0 of the memory block's first register). Bit 2: timer run. Bit 3: timer interrupt mask (0 = unmasked). | established |
| `+0x18` | Bit 0 is set to reset the machine on early boards (below). | established |
| `+0x20` | Status. Bit 0: a cache-operation interrupt (unexpected: the HAL prints an error and clears it with a write of all ones but bit 0). Bit 1: timer interrupt pending, cleared by writing a zero to it. | established |
| `+0x30` | Timer reload value; writing `0xffffffff` starts a calibration pass | established |
| `+0x38` | Timer current value (counts down) | established |

The Cobalt core clock is 100 MHz in the Linux headers and the Cobalt timer is the HAL's system clock by default
(`HalpUseCobaltClock` is initialised on); the HAL calibrates it instead of assuming the figure: for two passes, it waits
until the CMOS RTC's update-in-progress flag (register `0x0a`, bit 7) falls and rises, starts the timer with the load
value, waits for the same transition one second later, and reads how far the counter fell, rounded to the nearest 10 kHz.
The reload value for a tick is the tick length (default 10 ms, in 100-ns units, `maximum_increment` `0x186a0`; the
minimum increment is `0x2710`, 1 ms) multiplied by the measured frequency and divided by 10 million, with rounding.
The local APIC timer is the alternative clock source, selected by the boot option `SYSCLOCK=APIC` ([options](#boot-options-the-hal-parses)); the
same calibration scheme (against the RTC second) is used to scale the local APIC timer.

**Memory-controller block (`0xc6000000`).** Established for the registers the HAL touches; the rest unknown.

| Offset | Use |
|---|---|
| `+0x00` | Bit 0 enables ECC checking; zero at timer start-up |
| `+0x18` | Error status. The HAL treats the error as non-fatal when bit 16 is set, or when bit 17 is set and the syndrome is zero; anything else is fatal. It is cleared by writing zero. |
| `+0x28` | Error address (printed as "Address") |
| `+0x30` | Syndrome |

What the bits mean is inferred from the HAL's message selection (messages are "Invalid Address ... during
read/write from ...", "Hard ECC error", "Soft ECC error ... syndrome", "MULTIPLE MEMORY ERRORS"). A non-fatal error with
a nonzero syndrome is corrected by rewriting the location (`HalpCorrectSoftEccError`); the error is logged and the
status cleared. A fatal one displays the message, turns checking off, calls the SGI callback, logs to CMOS and
bug-checks with code `0x80`. Memory
error interrupts use Cobalt APIC entries `0x1a` and `0x1b` with vectors `0xf1` and `0xf2`; they are enabled only if the
board is not Cobalt Lite and the `HalpEnableMemerr` default (on) holds. Register `+0x18` of the CPU block is a
separate register from the memory block's.

**Cobalt APIC (`0xc4000000`).** Standard I/O-APIC-style redirection entries, two 32-bit words each, low word at
`n * 0x10`, high word at `n * 0x10 + 4`, for entries 0 to 29; the ID register at `+0xffc` has bit 8 as the enable, set
by the OS without changing the id (Linux and HAL alike). Low-word bits as used: vector in bits 7:0; bit 15 level
(always set by both Linux and the HAL for device interrupts); bit 14 remote IRR (HAL reads it, and clears it
in the NMI path); bit 16 mask; the HAL's NMI entry uses delivery mode NMI (`0x400`) with destination field in bits
31:24 of the high word. Entry 28 (`0x1c`) is the timer and cache interrupt, entry 29 (`0x1d`) the NMI, for Cobalt revisions
other than Lite; on Cobalt Lite the HAL uses entry `0x1b` for the clock and `0x1c` for NMI. Established for the HAL's use
and for Linux's constants.

Entries 0 to 15 are the bridge-fed PCI and legacy inputs and each has an interrupt-enable bit in a Lithium bridge:
entries 0 to 7 in bridge A, 8 to 15 in bridge B, bit `n & 7` of the 16-bit register at `+0x46` in the bridge's window
(`HalpEnableLiInt`, established; Linux's `LI_PCI_INTEN`). Entries 16 and above (video out and in, audio, the
two non-PCI ASIC sources, CPU) are enabled without a bridge bit.

The Linux names of the entries: IDE0 at 4 (5 on one board generation), IDE1 at 2 (320 only), the PIIX4 8259 cascade at
12, PCI A and B slot 0 lines and shared lines at 0 to 1, 5 to 6, 8 to 12 and 13 to 15, the PIIX4 USB at 7, video out 16
to 17, video in 18 to 19, Lithium audio 22, two graphics-engine entries 24 and 25, CPU 28, NMI 29.

## Interrupt delivery in the HAL

1. **Vectors. Established.** NT vectors encode the IRQL in the high nibble. Each Cobalt entry has a fixed vector in a
   per-board-generation table (`CobaltInt2Vec`, 30 words): for the newest generation entries 0 to 29 map to `92 8a 5a 69 59 91
   81 9b 82 89 7a 73 b9 71 79 72 ac ab aa a9 61 9c b2 6a a5 a3 bc f2 f7 f9`, and the earlier generations differ
   in entries 1, 3, 4, 5, 6, 13 and 15. The clock uses vector `0xd1` and IRQL `0x1c`. The HAL installs its own handlers
   on fixed vectors: `0xe1` the processor IPI, `0xc1` the broadcast-call service, `0x41` the DPC and `0x3d` the APC
   software interrupts, `0xfd` the profile interrupt and `0xfe` the performance-counter interrupt, `0xe3` the local
   APIC error.
2. **PIIX4 legacy interrupts. Established.** The PIIX4's 8259 pair is not wired to the processors directly: the master
   output is an input to Cobalt (entry 12), so none of the ISA IRQs has its own Cobalt entry. The HAL programs the
   8259s with edge cascade, master base 0, slave base 8, mask everything, then on a Cobalt interrupt it polls the master
   (command `0x0c`, port `0x20`), follows IRQ 2 into the slave, issues a specific end-of-interrupt, and re-injects the
   interrupt as a self-IPI through the local APIC at the vector assigned to that ISA IRQ. Linux does the same poll and
   treats legacy IRQs 1 to 15 as virtual. The IDE channels (IRQs 14 and 15) bypass the 8259 and have their own Cobalt
   entries.
3. **ISA-to-vector route tables. Established for content, inferred for meaning.** One 16-entry table of three bytes per
   ISA IRQ is selected from the board generation (HAL "SYS TYPE" and "BOARD REV", see [boot-path.md](boot-path.md)):
   vector, a second number that is the Cobalt entry for IRQs that do not use the 8259 or an NS87307 input
   number otherwise, and a flag byte (bit 0: delivered through the 8259; bit 2: needs the NS87307 interrupt
   steering, `HalpEnable307Int`; bit 1 is carried but unused in the enable path). Tables exist for the three 320 generations and for the 540 revision 0;
   the `INTRROUTE` boot option (values 1, 2, 3: "no8259", "ide8259", "Hugh006") swaps in alternatives for the middle
   320 generation: "no8259" steers IRQs 1, 4, 6, 7 and 12 through the NS87307 and "ide8259" sends the IDE channels
   through the 8259 as well. For the newest generation, IRQs 1, 4, 6, 7, 9, 12, 14, 15 carry vectors `9a 53 52 51 b8 99 59 5a`.
   The secondary IDE channel (IRQ 15) uses Cobalt entry 2 in every table. The primary channel (IRQ 14) uses entry 4 on
   the newest 320 generation and on the 540 except revision 0, entry 5 on the middle 320 generation and the 540
   revision 0, and entry 1 on the oldest 320 generation. This agrees with Linux, which uses entry 4 and switches to 5
   for one 320 revision; Linux has no case for the oldest generation, which would therefore use the wrong entry
   (unconfirmed on hardware). The floppy interrupt polarity is inverted at the
   NS87307 on the middle generation only.
4. **PCI pin to Cobalt entry. Established (HAL data tables, read in full).** For each bridge and board generation the HAL
   holds five slot rows of four bytes (pins A to D), each byte a Cobalt APIC entry or "none"; the generation is chosen as
   for the ISA table (generation 1: 320 below revision 6 and the 540 revision 0; generation 2: 320 revisions 6 to 11;
   generation 3: newer 320s and every other 540). `HalpPciIntPin2SysIntLine` then numbers the distinct entries it meets
   in order of first use to give the system interrupt line.

   | Bridge, generation | Slot 0 | Slot 1 | Slot 2 | Slot 3 | Slot 4 |
   |---|---|---|---|---|---|
   | A, 1 | 0 5 6 7 | 1 5 6 7 | 2 5 6 7 | 3 5 6 7 | 4 5 6 7 |
   | B, 1 | 8 13 14 15 | 9 13 14 15 | 10 13 14 15 | 11 13 14 15 | pin D only: 7 |
   | A, 2 | 0 6 7 6 | 1 7 6 7 | none | A only: 3 | none |
   | B, 2 | 8 14 15 14 | none | none | none | pin D only: 7 |
   | A, 3 | 0 5 6 5 | 1 6 5 6 | A only: 2 | A only: 3 | none |
   | B, 3 | 8 13 14 15 | 9 15 13 14 | 10 14 15 13 | 11 13 14 15 | pin D only: 7 |

   Reading: pin A of slot *n* has its own entry (bridge A `n`, bridge B `8 + n`); the other pins share entries 5 to 7
   (bridge A) or 13 to 15 (bridge B), rotated per slot on the newest generation. Bridge B slot 4 is the PIIX4: only
   pin D (its USB controller) is wired, to entry 7, which agrees with Linux's "PIIX4 USB on bus 0, slot 4, line 3" and
   with Linux giving that slot's pin A no interrupt. Bridge A slot 3 is the on-board Ethernet in Linux's comments, wired
   to entry 3 here. Linux 2.6's map sends bridge B's shared pins to entries 5 to 7 and their rotations (the base of bridge
   A) and leaves 13 to 15 unused, which this table contradicts for bridge B.

## PCI configuration cycles

The `TypeBorg` accessors send configuration cycles through a memory-mapped address and data register pair inside each
Lithium bridge window rather than through ports `0xcf8` and `0xcfc`; the address word layout, locking and the
master-abort clean-up are in [devices/lithium](../../devices/lithium/README.md#the-bridge-window-established).

## The NS87307 super-I/O and the PIIX4

The NS87307 sits at index and data ports `0x2e` and `0x2f` (logical device 7 is GPIO at `0x0fc0`, 8 is power
management at `0x0fc8`). The HAL initialises it (`Ns307InitChip`) and uses it for interrupt steering of IRQs 1, 3, 4, 6, 7
and 12: the HAL selects the logical device for that IRQ (codes 0, 5, 6, 3, 4 and 1 respectively) and writes its
interrupt-type register (index `0x71`) with a level/edge bit and a polarity bit (established). The PIIX4 PM block is at `0x0f80`
(status `+0`, enable `+2`, control `+4`). The soft-power interrupt handler (`HalpInitSoftPower`, installed on the vector the HAL assigns to ISA IRQ 9)
clears the PM status, enables the power-button interrupt (`0x100`) and arms the control register; the handler suspends
the machine on a power-button event and bug-checks with `0x80` after repeated errors. Reboot is a write of `0x06` to I/O
port `0xcf9` except on the earliest boards (320 generations below revision 12, and the 540 revision 0), where bit 0 of
the Cobalt CPU register `+0x18` is set instead (`HalpReboot`, `BoardResetAtPIIX4`). Linux's power-off clears the PM status, sets the suspend-enable bit in the PM control register, and then writes a PCI
special-cycle (stop grant) value through port `0xcfc`.

## Multiprocessor start-up

1. `HalpInitMP` allocates, below 1 MiB, space for the real-mode stub; `HalpGetProcessorInfo` reads the count and table
   at physical `0x1e00` ([boot-path.md](boot-path.md)); `HalStartNextProcessor` copies the stub and a copy of the
   processor context, builds a page-table image with the low memory identity-mapped (`HalpBuildTiledCR3`), writes the
   warm-reset vector at `0x467`, sets CMOS `0x0f` to `0x0a`, and calls `HalpStartProcessor`.
2. `HalpStartProcessor` finds the Nth enabled non-bootstrap table entry, sends INIT (ICR low word `0xc500`) and deassert
   (`0x8500`) to its APIC id, and, if the first table entry's APIC version byte is nonzero, two startup IPIs
   (ICR `0x600` plus the stub's page number) a short delay apart, waits for ICR delivery-status clear between steps, then waits for
   the other processor to flag itself in a shared block, a bounded number of times. `ONECPU` (boot option, above) stops secondary
   processors from being started.
3. Inter-processor interrupts are local APIC fixed IPIs at vector `0xe1`; a broadcast-call mechanism (vector `0xc1`)
   and a cache-operation interrupt exist. Local APIC set-up for each processor (`HalpInitLocalAPIC`): task priority
   `0xff` during set-up and `0` at the end; spurious vector register `0x11f` (software enable, vector `0x1f`); logical
   destination register set to one bit per processor id; destination format flat; LVT timer masked and periodic
   at vector `0xfd` (re-armed as an unmasked periodic timer at vector `0xd1` only if the Cobalt clock is not in use),
   performance counter masked at `0xfe`, LINT0 masked at `0x1f`, LINT1 NMI-delivery and masked, and the error entry
   at vector `0xe3` unmasked only when the processor table's first APIC version is nonzero.
   `HalpResetThisProcessor`, the restart path, masks the local APIC sources; the bootstrap processor then clears the
   CMOS shutdown byte, writes `0x1234` to `0x472`, re-arms the I/O-APIC-style entries it owns and pulses the keyboard
   controller reset line (value `0xfe` to port `0x64`).
4. **Profile and performance interrupts.** The HAL enables the Pentium performance counter interrupt on all
   processors when the feature bits say so (`HalpEnablePerfInterupt`).

## NVRAM, flash and the SGI callbacks

`HalpInitFlash` maps the flash at `0xfff80000` and `HalpInitEnvironmentVariables` loads the environment block described
in [firmware.md](firmware.md); `HalGetEnvironmentVariable` and `HalSetEnvironmentVariable` read and write it
(`HalSetEnvironmentVariable` special-cases `passwd_key`; the reason was not read). `HalpPwrMgmtSuspend` and the callback table
(`sgixCallbackRegister`, `sgixExecuteCallback`, with a registered name for the suspend callback) let SGI's drivers hook
power-state and memory-error events. The callback interface is described under "The SGI-specific HAL interface" below; its consumers are in
[devices/cobalt-graphics](../../devices/cobalt-graphics/) and the SGI driver set.

## Boot display and graphics memory

`HalpInitializeGbeDisplay0` maps the Cobalt display back end at `0xd0000000` (0xa0 bytes, more is mapped by later
steps), reads the flat-panel identity over I2C (retrying twice), takes the screen size from one of two built-in mode records
according to whether a panel answered, copies the console font into a mapped page, and builds the frame buffer in the first graphics bank (above).
`HalpGbeDisplaySetup` stops the display engine if it is running (writing `0xffffff` to two registers at `+0x10020` and
`+0x10024`, clearing the enable bits at `+0x3000c`, `+0x20008` and `+0x40004`, waiting a bounded 20,000 reads for three
idle bits), fills a table of 32 words at `+0x48000` with the value 3 and the colour map at `+0x60000` with a grey ramp,
and then starts the display (`+0x18` set to `0xa7` then with bit 3 added). The registers are those of the display back end
described in [devices/cobalt-graphics/display-engine.md](../../devices/cobalt-graphics/display-engine.md); the HAL's
use is established, their meaning is that page's.

## The SGI-specific HAL interface

`HaliQuerySystemInformation` (the HAL dispatch-table entry NT's `HalQuerySystemInformation` reaches) answers the
stock classes (installed bus information, class 0; display BIOS information, class 9; a one-byte answer for class 8)
and two classes of SGI's own, which is what the graphics driver's "Not an SGI HAL" check relies on (see
[devices/cobalt-graphics/nt-software.md](../../devices/cobalt-graphics/nt-software.md)). Established (read in full):

| Class | Returns |
|---|---|
| `0x8100001` | 16 bytes: three function pointers to the HAL's cache-flush routines for a memory descriptor list, a physical buffer and a virtual buffer (`HalxFlushMdl`, `HalxFlushPhysicalBuffer`, `HalxFlushVirtualBuffer`), and in the last byte the flag saying whether cache-operation invalidate is supported (clear on Cobalt Lite, set otherwise by default) |
| `0x8100002` | 4 bytes: a pointer to `sgixCallbackRegister` |
| anything else | status `0xc0000148` (not implemented); `HalSetSystemInformation` always answers the same |

`sgixCallbackRegister` takes a record of an id (0 or 1), a callback pointer and a context pointer; a null pointer
unregisters; invalid addresses give `0xc0000141` and an id outside 0 and 1 gives `0xc000000d`. The HAL stores two
slots. Slot 0 is called from the fatal memory-error path with the error address and status (`HalpMemErrorHandler`,
above); slot 1 belongs to the power-state path (`HalpPwrMgmtSuspend`, inferred from the suspend callback name the HAL
registers).

## Boot options the HAL parses

Established (the whole option routine at `0x8002dee0`, `HalInitSystem`'s first-processor path, and `HalpXtractOptionString`
at `0x8001a6e0`, read in full; the strings are in the image at file offsets `0x1de20` to `0x1ded4` and `0x206f0` to `0x20730`).
The load-options string (the ARC `osloadoptions` variable the loader passes) is searched, not tokenised: a name matches
where it is at the start or follows a blank, a tab or `/`, and a value follows `=` or `:`. Case is significant for the
names as stored (upper case).

| Option | Effect |
|---|---|
| `ONECPU` | counts up the "do not start processors" flag; secondary processors are not started |
| `PCILOCK` | sets a flag that keeps the PCI resource settings (read by the PCI set-up, not traced) |
| `INTAFFINITY` | static interrupt affinity flag |
| `BREAK` | breakpoint into the debugger at start-up |
| `ARCINFO` | sets bit 0 of the HAL's boot-command flags (enables the ARC-tree dump at start-up, inferred from the dump routine) |
| `SYSCLOCK=COBALT` / `SYSCLOCK=APIC` | choose the Cobalt timer (default) or the local APIC timer as the system clock |
| `PAGEOPENPOLICY=OPEN` / `CLOSE` | memory-controller page policy value (set to 0 for `OPEN` and 2 for `CLOSE`); the register it feeds is not found in the routines read |
| `MEMERR=ON` / `OFF` | enables or disables the Cobalt memory-error interrupts (default on) |
| `ECC=ON` / `OFF` | enables or disables ECC checking (default on) |
| `BLOCKINTS=n` | numeric flag the HAL prints when set (use not traced) |
| `INTRROUTE=DEFAULT` / `NO8259` / `IDE8259` / `HUGH006` | the interrupt routing mode, below |
| `CACHEOPPOLL=n` | microseconds the cache-operation code polls (an integer) |

`TIMERRES`, `CLOCKLEVEL` and `NOGUI` are not options of this HAL: the first two do not occur in the image at all, and `nogui`
and the debug port settings (`dbaud`, `rbaud`) belong to the debugger-port set-up rather than this routine. `USE8254`
is a string in the image that this routine does not read; the HAL's performance counter reads the 8254 only if a flag
that the routines read never set is non-zero, and otherwise returns the processor's time-stamp counter with the calibrated
frequency in its second result (`KeQueryPerformanceCounter`, `0x80013990`). So the Windows performance counter on this
machine is the TSC unless the flag is set elsewhere (inferred for who sets it).

**`INTRROUTE` and "Hugh006" (established, `HalpInitIntrRoute` at `0x80016bd0`).** The HAL picks its tables from two bytes of
the firmware's SGI REV INFO node: SYS TYPE (0 for the 320, 1 for the 540) and BOARD REV. A 320 below board revision 6 and
the 540 revision 0 use the first tables; a 320 of revision 6 to 11 uses the middle tables and inverts the floppy interrupt
at the NS87307; everything else uses the third tables. Only the middle generation honours `INTRROUTE`: `NO8259` and
`IDE8259` swap in two alternative ISA route tables (with the debug message "interrupt route no8259" or "ide8259");
`HUGH006` prints "interrupt route Hugh006", clears the floppy inversion and falls through to the newest generation's tables
for the ISA route, the Cobalt-entry vector table and both PCI pin maps. So "Hugh006" is not a new routing mode of its own: it
is the switch that makes a middle-generation 320 (revision 6 to 11) wire its interrupts like the newest boards, which is
what a board with the later interrupt fix-up would need. "Hugh" in the HAL's data is a bare string next to "Twibble" and
"Borg", unused by any routine read. A 2000 Usenet post by an SGI employee (`8gbvta$fos$1@murrow.corp.sgi.com`) says the 320,
the 540 and the 1600SW flat panel carried the code names borg, hugh and 7of9 without saying which is which, so "Hugh006"
probably names a board revision of one of the two workstations (inferred; unknown which).

## Points this reading settles for the platform pages

Against the open list in [questions/visws-open.md](../../questions/visws-open.md):

- **Bridge B's interrupt map.** Settled for all three generations (table above): bridge B's shared pins use Cobalt
  entries 13 to 15, not 5 to 7 as Linux 2.6 does.
- **Cobalt timer pending bit.** The NT clock handler clears it on every tick by writing a zero to bit 1 of the status
  register, as Linux 2.2 and 2.4 do. Whether it would self-clear is still not answered by this evidence.
- **Cobalt interrupt controller.** Entries have a remote-IRR style bit (bit 14 of the low word) that the HAL reads and
  clears in the NMI path, and a mask bit; the HAL masks nothing before end of interrupt for the clock. Reset state and
  the id field remain unknown.
- **Board type.** The HAL does not probe hardware for it: the firmware's ARC tree carries the model and board
  revision bytes ([boot-path.md](boot-path.md)), so the 540 probe slip in Linux has no counterpart there.
- **Processor table producer.** The table at `0x1e00` is read by the HAL as well, so it is the firmware's (or the
  firmware's loader's) output, not something a Linux boot loader invents; which one writes it is still unknown.
- **Memory controller.** The NT HAL does program and read the Cobalt memory block at `0xc6000000` (table above), but only
  ECC enable and error status; bank decoding and the frame-buffer placement are still unread.
- **Bus numbering.** The HAL addresses bridge B's window first (index 0 at `0xfd000000`) and bridge A second, matching
  Linux's choice of bridge B as the PIIX4 bus; the numbers the bridges hold are assigned by the HAL's host-bridge
  init when it enumerates, so which is bus 0 at run time is still not stated.

## Routines read

`HalInitSystem`, `HalInitializeProcessor`, `HalpInitializeInterrupts`, `HalpEnableNMI`, `HalpInitLithium`, `HalpInitMP`,
`HalStartNextProcessor`, `HalpStartProcessor`, `HalpInitializeClock`, `HalpCalibrateCobaltTimer`, `HalpScaleTimers`,
`HalpInitCoTimer`, `HalpBeginTime`, `HalpGetCoApicRedirEntry`, `HalpSetCoApicRedirEntry`, `HalpHandleCoNMI`,
`HalEnableSystemInterrupt`, `HalpCobaltInterrupt`, `HalpInitLocalAPIC`, `HalpInitSGIHostBridge`, `HalpGetLiCnfgAddr`,
`HalpEnableLiInt`, the Borg PCI synchronise, read and config accessors, `HalpPciIntPin2SysIntLine`, `HalpInitIntrRoute`,
`HalpGetIntrDataByVector`, `HalpReboot`, `BoardResetAtPIIX4`, `HalpInitMemErrSubsystem`, `HalpMemErrorHandler`,
`HalpEccControl`, `HalpInitFlash`, the flash erase, program and poll routines, `HalpInitEnvironmentVariables`,
`HalpGrabArcRevInfo`, `HalpGrabSystemName`, `HalpGetSystemGenome`, `HalpGetProcessorInfo`, `HalpResetThisProcessor`,
`HalpInitSoftPower`, `pm_init_intr`, `pm_intr_handler`, `HalpInit8259`, `Halp8259Interrupt`, `Ns307InitChip`,
`HalpEnable307Int`, `HalpSpliceGfxMemory`, `HalpCheckCompatibility`, `CacheopInitialize`, `CacheopInterrupt`,
`HalQueryRealTimeClock` (CMOS RTC in BCD, years below 70 read as 20xx; an out-of-range date resets to 1 January 1998),
`HalpInitializeRtc`.

Not read: the PCI resource assignment beyond naming, the `HalpGbeDisplaySetup` register programming beyond the sequence summarised in the next paragraph, the DMA adapter and map-register code, the bus handler tables, the V86 BIOS call path, the I2C layers.
