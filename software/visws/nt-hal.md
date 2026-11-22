# Visual Workstation 320 and 540: the Windows NT 4.0 HAL

SGI's HAL for the pair is `halborg.dll` (multiprocessor) and `halbrgup.dll` (uniprocessor), both from Recovery CD-1 v1.1 (byte-identical copies are in `\I386\` of the SGI 320 NT 4.0 install CD, Disk 1, in the Internet Archive item `sgi-vw-drivers`),
file revision strings "1.3", linked 1999-04-27 (PE timestamps), image base `0x80010000`, native-subsystem DLLs that
import only `ntoskrnl.exe`. Each has a matching CodeView symbol file (`halborg.dbg`, `halbrgup.dbg`), which names about
1,050 symbols and the 75 object files it was built from. The two HALs share all symbols except thirteen
multiprocessor-only ones (the real-mode start stub, the processor table reader and the processor start routines).
`halborg.dll` was read through Ghidra, with the debug-file names applied, covering the routines listed at the end (a second
pass re-checked every established claim below in a Ghidra project with all 1,050 public-symbol records applied: 541 of 560 functions
decompile, and the 41 static routines that have no public name are cited by what they do); the
uniprocessor HAL (1,037 records; the symbol counts differ between passes, see the review section) was compared symbol by symbol and read where it differs. The Windows 2000 builds (no symbols) were compared by table and string
([second reading](#second-reading-interrupt-levels-pci-dma-memory-registry-processors)). SHA-256: `halborg.dll` `0926cd50…4a048`, `halbrgup.dll` `21978c78…f7de8`.
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

Physical blocks, each mapped as one page with the write-through and cache-disable page bits set (so uncached), at processor 0
start-up (`HalInitializeProcessor`; the pointers are `HalpCobaltCpu`, `HalpCobaltApic`, `HalpCobaltMem`): CPU block `0xc2000000`,
APIC block `0xc4000000`, memory-controller block `0xc6000000`, and the ordinary local APIC at `0xfee00000`. The Linux names
below are from `asm/visws/cobalt.h`; the HAL agrees wherever both touch a register.

**CPU block (`0xc2000000`).**

| Offset | Use | Grade |
|---|---|---|
| `+0x08` | Revision. Values `0xa0` and `0xa8` mean "Cobalt Lite": no ECC, no memory error reporting, no cache-operation invalidate, and different APIC entry numbers for the clock and NMI (below). | established |
| `+0x10` | Control. Bit 0: ECC checking on (set with bit 0 of the memory block's first register). Bit 1: page policy, set by `PAGEOPENPOLICY=CLOSE` (below). Bit 2: timer run. Bit 3: timer interrupt mask (0 = unmasked). | established |
| `+0x18` | Bit 0 is set to reset the machine on early boards (below). | established |
| `+0x20` | Status. Bit 0: a cache-operation interrupt (unexpected: the HAL prints an error and clears it with a write of all ones but bit 0). Bit 1: timer interrupt pending. The clock handler writes the register with `0xfffffffd` (bit 1 zero, every other bit one) on every tick: the write pattern is established; that a zero in bit 1 is what clears the pending bit (write-zero-to-clear) is inferred from the handler's use. | established for the pattern, inferred for the semantics |
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
a nonzero syndrome sends the handler to `HalpCorrectSoftEccError` (`0x80019810`), which **does not rewrite the location** (below); the error is logged and the
status cleared. A fatal one displays the message, turns checking off, calls the SGI callback, logs to CMOS and
bug-checks with code `0x80`. Memory
error interrupts use Cobalt APIC entries `0x1a` and `0x1b` with vectors `0xf1` and `0xf2` (entry `0x1b`'s vector equals its table slot; entry `0x1a`'s table value is `0xbc`, so only that entry and the NMI entry differ from their slots); they are enabled only if the
board is not Cobalt Lite and the `HalpEnableMemerr` default (on) holds. Register `+0x18` of the CPU block is a
separate register from the memory block's.

**Cobalt APIC (`0xc4000000`).** Standard I/O-APIC-style redirection entries, two 32-bit words each, low word at
`n * 0x10`, high word at `n * 0x10 + 4`, for entries 0 to 29; the ID register at `+0xffc` has bit 8 as the enable. Linux sets that bit
alone; the HAL's start-up first masks all 30 entries (low word `0x10000`), then, if bits 27:24 of the ID register read zero, writes
4 into them, and then sets bit 8 (so a zero id is treated as "unset"; established for the HAL). Low-word bits as used: vector in bits 7:0; bit 15 level
(always set by both Linux and the HAL for device interrupts); bit 14 remote IRR (HAL reads it, and clears it
in the NMI path); bit 16 mask; the HAL's NMI entry uses delivery mode NMI (`0x400`) with destination field in bits
31:24 of the high word. Entry 28 (`0x1c`) is the timer and cache interrupt, entry 29 (`0x1d`) the NMI, for Cobalt revisions
other than Lite; on Cobalt Lite the HAL uses entry `0x1b` for the clock and `0x1c` for NMI (`HalpEnableNMI` makes that choice, but `HalpHandleCoNMI`
always reads and clears entry `0x1d`, so the NMI handler would look at the wrong entry on a Lite board). `HalpEnableNMI` writes the
entry as vector `0xff`, logical destination mode (low word `0x8ff`, the processor's logical id in bits 31:24 of the high word), reads it
back, and gives up (masks the entry and prints "Failed to set NMI") if bit 17 of the low word reads set; only then does it set
delivery mode NMI (`0x400`). What bit 17 means is not known. Established for the HAL's use
and for Linux's constants.

Entries 0 to 15 are the bridge-fed PCI and legacy inputs and each has an interrupt-enable bit in a Lithium bridge:
entries 0 to 7 in bridge A, 8 to 15 in bridge B, bit `n & 7` of the 16-bit register at `+0x46` in the bridge's window
(`HalpEnableLiInt`, established; Linux's `LI_PCI_INTEN`). Entries 16 and above (video out and in, audio, the
two non-PCI ASIC sources, CPU) are enabled without a bridge bit. Entry 12 is the PIIX4 cascade: `HalpAttach8259Handler` asks for the
internal-bus level `0xc` and installs the 8259 interrupt handler on the vector it returns (established).

The Linux names of the entries: IDE0 at 4 (5 on one board generation), IDE1 at 2 (320 only), the PIIX4 8259 cascade at
12, PCI A and B slot 0 lines and shared lines at 0 to 1, 5 to 6, 8 to 12 and 13 to 15, the PIIX4 USB at 7, video out 16
to 17, video in 18 to 19, Lithium audio 22, two graphics-engine entries 24 and 25, CPU 28, NMI 29.

## Interrupt delivery in the HAL

1. **Vectors. Established.** NT vectors encode the IRQL in the high nibble (the Irql `HalGetInterruptVector` reports back is the vector shifted right by 3). Each Cobalt entry has a fixed vector in a
   per-board-generation table (the pointer `CobaltInt2Vec` selects one of three tables of 32 words, the last two zero; entries 0 to 29
   are used): for the newest generation entries 0 to 29 map to `92 8a 5a 69 59 91
   81 9b 82 89 7a 73 b9 71 79 72 ac ab aa a9 61 9c b2 6a a5 a3 bc f2 f7 f9`. The oldest generation differs in entries 1, 3, 4 and 6
   (`59 53 51 52`) and the middle one in entries 4, 5, 13, 14 and 15 (`51 59 53 72 79`). The clock handler runs at IRQL `0x1c` on
   vector `0xd1` (written as a literal, not taken from the table), and entry `0x1a` (memory error, vector `0xf1`) and the NMI entry do not use their table slots; entry `0x1b` (memory error, `0xf2`) happens to equal its slot (below). The HAL installs its own handlers
   on fixed vectors: `0xe1` the processor IPI, `0xc1` the broadcast-call service, `0x41` the DPC and `0x3d` the APC
   software interrupts, `0xfd` the profile interrupt and `0xfe` the performance-counter interrupt, `0xe3` the local
   APIC error. In the multiprocessor build the Cobalt timer interrupt arrives on one processor, which re-sends the tick to the others
   as a fixed all-excluding-self IPI on vector `0xd1` (ICR `0xc00d1`) when the IPI-clock flag is set (`HalpIpiClock`).
2. **PIIX4 legacy interrupts. Established.** The PIIX4's 8259 pair is not wired to the processors directly: the master
   output is an input to Cobalt (entry 12), so none of the ISA IRQs has its own Cobalt entry. The HAL programs the
   8259s with edge cascade, master base 0, slave base 8, mask everything, then on a Cobalt interrupt it polls the master
   (command `0x0c`, port `0x20`), follows IRQ 2 into the slave, issues the end-of-interrupt (specific on the master; a non-specific one on the slave, see the follow-on section), and re-injects the
   interrupt as a self-IPI through the local APIC at the vector assigned to that ISA IRQ. Linux does the same poll and
   treats legacy IRQs 1 to 15 as virtual. The IDE channels (IRQs 14 and 15) bypass the 8259 and have their own Cobalt
   entries.
3. **ISA-to-vector route tables. Established for content, inferred for meaning.** One 16-entry table of three bytes per
   ISA IRQ is selected from the board generation (HAL "SYS TYPE" and "BOARD REV", see [boot-path.md](boot-path.md)):
   vector, a second number that is the Cobalt entry used when the 8259 flag is clear (it is ignored for an 8259 row), and a flag byte
   (bit 0: delivered through the 8259; bit 2: also needs the NS87307 interrupt steering, `HalpEnable307Int`, which is given the ISA
   IRQ number, not the second byte; bit 1, set on IRQs 14 and 15 in the middle, newest and 540 revision 0 tables but not in the oldest, `no8259` (flag byte 0) or `ide8259` (flag byte 1) tables, is returned by `HalpGetIntrDataByVector`;
   `HalEnableSystemInterrupt` ignores it, and `HalDisableSystemInterrupt` uses it: for such a row whose use count is zero the disable goes to the 8259 path instead of masking the Cobalt entry). Tables exist for the three 320 generations and for the 540 revision 0, which
   steers IRQs 4 and 7 through the NS87307 to Cobalt entries 3 and 4 and has no vector for IRQ 5;
   the `INTRROUTE` boot option (values 1, 2, 3: "no8259", "ide8259", "Hugh006") swaps in alternatives for the middle
   320 generation: "no8259" steers IRQs 1, 4, 6, 7 and 12 through the NS87307 and "ide8259" sends the IDE channels
   through the 8259 as well. For the newest generation, IRQs 1, 4, 5, 6, 7, 9, 12, 14, 15 carry vectors `9a 53 b1 52 51 b8 99 59 5a` (IRQ 5 has a vector in the middle and newest generations only).
   The secondary IDE channel (IRQ 15) uses Cobalt entry 2 in every table except `ide8259`, which sends it through the 8259. The primary channel (IRQ 14) uses entry 4 on
   the newest 320 generation and on the 540 except revision 0, entry 5 on the middle 320 generation and the 540
   revision 0, and entry 1 on the oldest 320 generation. This agrees with Linux, which uses entry 4 and switches to 5
   for one 320 revision; Linux has no case for the oldest generation, which would therefore use the wrong entry
   (unconfirmed on hardware). The NS87307 steering (`HalpEnable307Int` `0x8001ab60`, three arguments: ISA IRQ, mode, polarity; mode is forced to 0, level, whenever the row is not an 8259 row, and the polarity is the floppy-inversion output of `HalpGetIntrDataByVector`) is reached only from rows with flag bit 2, which exist only in the `no8259` table (IRQs 1, 4, 6, 7, 12) and the 540 revision 0 table (IRQs 4 and 7); no table has a row for IRQ 3. The floppy inversion is therefore non-zero only when the middle-generation board runs `INTRROUTE=NO8259` (IRQ 6's row is then not an 8259 row); on a default middle-generation board IRQ 6 goes through the 8259 and the 307 steering is never invoked (established, decoded tables and call site).
4. **PCI pin to Cobalt entry. Established (HAL data tables, read in full).** For each bridge and board generation the HAL
   holds five slot rows of four bytes (pins A to D), each byte a Cobalt APIC entry or "none"; the generation is chosen as
   for the ISA table (generation 1: 320 below revision 6 and the 540 revision 0; generation 2: 320 revisions 6 to 11;
   generation 3: newer 320s and every other 540). `HalpPciIntPin2SysIntLine` then numbers the distinct entries it meets
   in order of first use (1 to 16, kept in `PciIntOrder`) and writes that ordinal, not the Cobalt entry, into the device's interrupt
   line register; a pin outside A to D gives 0. The table rows are 8 bytes (four pin bytes and a pointer the lookup does not
   read) indexed by the device number, with no bound. When a driver asks for the interrupt, the PCI bus handler's `HalpGetPciInterrupt`
   maps the ordinal back through `PciIntOrder` to the Cobalt entry and then the vector (established).

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
and 12: the HAL selects the logical device for that IRQ (index register 7, then the device number 0, 5, 6, 3, 4 and 1 respectively,
which are the standard keyboard, COM2, COM1, floppy, parallel and mouse devices) and writes its
interrupt-type register (index `0x71`): bit 0 is set when the interrupt mode argument is zero (level-sensitive) and bit 1 when the
polarity argument is nonzero (established for the write and for the polarity argument: it is the floppy-inversion output of `HalpGetIntrDataByVector`, set only for IRQ 6 on a middle-generation board whose IRQ 6 row is not an 8259 row, that is under `INTRROUTE=NO8259`). The PIIX4 PM block is at `0x0f80`
(status `+0`, enable `+2`, control `+4`). The soft-power interrupt handler (`HalpInitSoftPower`, installed on the vector the HAL assigns to ISA IRQ 9)
clears the PM status, enables the power-button interrupt (`0x100`) and arms the control register; the handler suspends
the machine on a power-button event and bug-checks with `0x80` after repeated errors. `HalpPwrMgmtSuspend` ends by writing `0x2000` (the
suspend-enable bit, type 0) to the PM control register at `0xf84`; before that, if a CMOS byte test passes, it sets or clears bit 0 of
I/O port `0xfb5` (set below board revision `0x20`; what that port is was not identified). Reboot is a write of `0x06` to I/O
port `0xcf9` except on the earliest boards (320 generations below revision 12, and the 540 revision 0), where bit 0 of
the Cobalt CPU register `+0x18` is set instead (`HalpReboot`, `BoardResetAtPIIX4`). Linux's power-off clears the PM status, sets the suspend-enable bit in the PM control register, and then writes a PCI
special-cycle (stop grant) value through port `0xcfc`.

## Multiprocessor start-up

1. `HalpInitMP` allocates, below 1 MiB, space for the real-mode stub; `HalpGetProcessorInfo` reads the count and table
   at physical `0x1e00` ([boot-path.md](boot-path.md); the HAL maps physical page `0x1000` and reads at `+0xe00`: a 16-bit count, then
   20-byte entries in the layout of an MP-specification processor entry, type 0, local APIC id, version, flags with bit 0 enabled and
   bit 1 bootstrap; the first entry's version byte decides whether startup IPIs and the APIC error vector are used; established); `HalStartNextProcessor` copies the stub and a copy of the
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
(`HalSetEnvironmentVariable` special-cases `passwd_key`; the reason was not read). The callback table
(`sgixCallbackRegister`, `sgixExecuteCallback`) lets SGI's drivers hook fatal and corrected memory-error events. The callback interface is described under "The SGI-specific HAL interface" below; its consumers are in
[devices/cobalt-graphics](../../devices/cobalt-graphics/) and the SGI driver set.

## Boot display and graphics memory

`HalpInitializeGbeDisplay0` maps the Cobalt display back end at `0xd0000000` (`0xa0` pages, 640 KiB: the mapping routine's second
argument is a page count), reads the flat-panel identity over I2C (retrying twice), takes the screen size from one of two built-in mode records
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
above); slot 1 is called from `HalpLogEccError`, the corrected-error path, with a pointer to the HAL's error log block (`ElogData`) and zero
(established; an earlier reading took slot 1 for the power-state path, but `HalpPwrMgmtSuspend` calls no callback).

## Boot options the HAL parses

Established (the whole static boot-option routine that `HalInitSystem` calls on the first processor, which has no public symbol, and
`HalpXtractOptionString`, `HalpXtractOptionValue`, read in full).
The load-options string (the ARC `osloadoptions` variable the loader passes) is searched, not tokenised. `ONECPU`, `PCILOCK`,
`INTAFFINITY`, `BREAK`, `ARCINFO` and `SYSCLOCK=` are plain substring matches with no check on what precedes them. The
others go through `HalpXtractOptionString`, where a name matches only at the start or after a blank, a tab or `/`, and a value follows `=` or `:`; a
value is compared by prefix (`ON`, `OFF`, `OPEN`, `CLOSE` and the `INTRROUTE` names). Case is significant (upper case).

| Option | Effect |
|---|---|
| `ONECPU` | counts up the "do not start processors" flag; secondary processors are not started |
| `PCILOCK` | sets `HalpPciLockSettings`, read by `HalpAdjustPCIResourceList`: when set, a type-0 device whose I/O or memory decode is already enabled has its current base registers read (probed with ones and restored) and used for its resource list, which keeps the firmware's assignment (inferred from that routine; the later steps were not traced) |
| `INTAFFINITY` | static interrupt affinity flag |
| `BREAK` | breakpoint into the debugger at start-up |
| `ARCINFO` | sets bit 0 of the HAL's boot-command flags (enables the ARC-tree dump at start-up, inferred from the dump routine) |
| `SYSCLOCK=COBALT` / `SYSCLOCK=APIC` | choose the Cobalt timer (default) or the local APIC timer as the system clock |
| `PAGEOPENPOLICY=OPEN` / `CLOSE` | page policy value, 0 for `OPEN` and 2 for `CLOSE`; it is OR-ed (`HalpCobaltPOP`) into the Cobalt CPU control register at `+0x10` (bit 1) by the static clock-and-control routine `HalInitSystem` calls, which also clears bit 0 (ECC off until `HalpEccControl`) and sets bit 3 (timer interrupt masked). The OR never clears bit 1, so `OPEN` leaves whatever the firmware left there |
| `MEMERR=ON` / `OFF` | enables or disables the Cobalt memory-error interrupts (default on) |
| `ECC=ON` / `OFF` | enables or disables ECC checking (default on). `HalpEccControl` turns ECC on only if the board is not a Cobalt Lite (revision `0xa0` or `0xa8`, which prints "ECC checking DISABLED on Cobalt Lite"), `MEMERR` is on and `ECC` is on: ECC checking depends on both options |
| `BLOCKINTS=n` | numeric flag the HAL prints when set, and only if its debug level is 2 or more (use not traced) |
| `INTRROUTE=DEFAULT` / `NO8259` / `IDE8259` / `HUGH006` | the interrupt routing mode, below |
| `CACHEOPPOLL=n` | microseconds the cache-operation code polls (an integer) |
| `HALOUT` | read by the display start-up (`HalpInitializeDisplay0`), not the option routine: after `HALOUT` and one of `:`, `=` or `+`, `AS` selects the screen (the default), `COMn` (optionally `@baud`, default 19200) a serial console, `NONE` neither; `=` makes the choice exclusive. The screen is always the Cobalt frame buffer: the display-mode word is initialised to select it and nothing changes it, so the HAL's VGA text routines (physical `0xb8000`) are present but unreachable, and a failed frame-buffer start-up leaves the HAL console uninitialised rather than falling back to VGA text |

`TIMERRES`, `CLOCKLEVEL` and `NOGUI` are not options of this HAL: the first two do not occur in the image at all, and `nogui`
and the debug port settings (`dbaud`, `rbaud`) belong to the debugger-port set-up rather than this routine. `USE8254`
is a string in the image that this routine does not read; the HAL's performance counter reads the 8254 only if a flag
that the routines read never set is non-zero, and otherwise returns the processor's time-stamp counter with the calibrated
frequency in its second result (`KeQueryPerformanceCounter`; `HalpUse8254` starts at zero and nothing else writes it). So the Windows performance counter on this
machine is the TSC unless the flag is set elsewhere (inferred for who sets it).

**`INTRROUTE` and "Hugh006" (established, `HalpInitIntrRoute`).** The HAL picks its tables from two bytes of
the firmware's SGI REV INFO node: SYS TYPE (0 for the 320, 1 for the 540) and BOARD REV. A 320 below board revision 6 and
the 540 revision 0 use the first tables; a 320 of revision 6 to 11 uses the middle tables and, only under `INTRROUTE=NO8259`, inverts the floppy interrupt
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
- **Processor table producer.** The table at `0x1e00` is read by the HAL as well, so it is the firmware's output, not something
  a Linux boot loader invents; the firmware writes it from every running processor ([boot-path.md](boot-path.md)).
- **Memory controller.** The NT HAL does program and read the Cobalt memory block at `0xc6000000` (table above), but only
  ECC enable and error status; bank decoding and the frame-buffer placement are still unread. The graphics split reaches the HAL only as memory descriptors, see [Memory banks and the graphics split](#memory-banks-and-the-graphics-split); the HAL never decodes banks.
- **Bus numbering.** The HAL addresses bridge B's window first (index 0 at `0xfd000000`) and bridge A second, matching
  Linux's choice of bridge B as the PIIX4 bus; the numbers the bridges hold are assigned by the HAL's host-bridge
  init when it enumerates, so which is bus 0 at run time is still not stated. Settled by the second reading ([PCI numbering](#pci-numbering-and-resource-assignment)): the HAL registers the first bridge it finds as bus 0, so at run time bridge B (window `0xfd000000`) is bus 0 and bridge A (`0xfc000000`) is bus 1 (established for the NT HAL, for a machine whose PCI-to-PCI bridges, if any, are behind bridge B).

## Second reading: interrupt levels, PCI, DMA, memory, registry, processors

Read in Ghidra with the shipped debug symbols applied (`halborg.dll` 1.3, sha-256 `0926cd50…4a048`, and `halbrgup.dll`,
`21978c78…f7de8`) and checked against `objdump`. Addresses are `halborg.dll`'s; the uniprocessor build has the same routines at
nearby addresses. Grades as above.

### Interrupt level to Cobalt entry

- **The internal bus's "level" is the Cobalt entry number. Established.** `HalGetInterruptVector` hands a
  request to the bus handler for the bus type; for the internal bus (type 0) and PCI (type 5) that is
  `HalpGetSystemInterruptVector`. It indexes `CobaltInt2Vec` with the entry number directly (no bounds check;
  the table has 30 used words) and returns the vector. For internal-bus requests that number is the caller's level. For the PCI bus the
  bus handler's own routine `HalpGetPciInterrupt` runs first: the level there is the ordinal that `HalpPciIntPin2SysIntLine` wrote into
  the device's interrupt line register, and it is mapped through `PciIntOrder` to the Cobalt entry before this routine is called. The Irql it reports is the vector shifted right by 3, and the affinity is
  the default mask if the vector is nonzero, else zero. Any other interface type prints "Unexpected interface type" and
  returns vector 0. So the video drivers' levels 16 to 19 ([nt-drivers.md](nt-drivers.md)) are Cobalt entries 16 to 19.
- **Vector back to entry. Established.** `HalEnableSystemInterrupt` calls `HalpGetIntrDataByVector`, which first searches the generation's 16-row ISA route table for the vector (three bytes per row, the
  columns of the table above) and, if the vector is not there, searches `CobaltInt2Vec` for it: the position found is the
  Cobalt entry. An ISA row with the 8259 flag enables the line at the 8259 (`HalpEnable8259Int`); a row that needs the
  NS87307 also calls `HalpEnable307Int`; a row without the 8259 flag (including the NS87307 ones) takes the Cobalt entry in its second byte. A Cobalt entry is enabled once: a per-entry use count (an array of bytes with no public symbol, under a spin lock) is incremented, and only the first user, for entries below 16, sets that entry's bit in the owning
  Lithium bridge (`HalpEnableLiInt`) and writes the redirection entry with the vector and bit 15 (level) set
  (`HalpSetCoApicRedirEntry`). `HalDisableSystemInterrupt` (`0x800166f0`) is **not** the reverse: it only decrements the use count and, at zero, reads the entry and writes its low word back with the mask bit (16) set (the 8259 path described above for rows with flag bit 1 aside). Nothing ever clears a Lithium enable bit: `HalpEnableLiInt` does a 16-bit `|=` of bit `n & 7` into window `+0x46` under a spin lock, so once an entry has been enabled its bridge bit stays set for the life of the system.
- **Internal-bus vectors installed in the IDT.** `HalpSetInternalVector` records a vector's IRQL in a per-vector
  table (`HalpRegisterVector`, 16 entries indexed by vector >> 4) and writes the IDT gate's two halves at 8 bytes per vector.
  Established; the table's consumers (`HalBeginSystemInterrupt`) were not followed.

### PCI numbering and resource assignment

- **Bus numbers. Established.** `HalpInitializePciBus` makes one PCI bus handler per primary bus
  (`_ucNumPrimaryBusses` is initialised to 2) in the order bridge B (index 0, window `0xfd000000`) then bridge A (index 1,
  window `0xfc000000`; `HalpGetLiCnfgAddr`). The handler is registered with bus number "any"
  (`HaliRegisterBusHandler`), which takes the lowest unused PCI bus number. Bridge B is therefore bus 0 and
  bridge A bus 1, except that a PCI-to-PCI bridge found while enumerating bus 0 would take number 1 first and push A to
  the next free number (the machines' behaviour with a bridged card in a slot of B is therefore unverified).
- **Bridge window write. Established.** `HalpInitSGIHostBridge` runs for each bridge before it is
  enumerated, with a subordinate-bus value of `0xff`, and again afterwards for bridge B only, with the highest bus number
  found behind it (bridge A keeps `0xff`). It tests the byte at window `+0x08` (the revision half of the class word): above
  zero, the low byte of the word at `+0x44` is set to the bus number and its next byte to the subordinate number, and `0xffff` is written to the halfword
  at `+0x04` (the bridge's own command word); at revision zero the bus
  number goes in the top byte of the word at `+0x40` instead. (The HAL also notes a bus-number limit of `0x20` or `5` in its own bookkeeping; its use was not followed.) In both cases the status halfword at `+0x06` is then written
  `0xf800`, which clears the five error bits of a standard status word. This is the bus-number word that Linux reads at `+0x44`; Linux
  only knows the revision above zero layout. See [Lithium](../../devices/lithium/README.md).
- **Enumeration. Established.** `HalpEnumeratePciBus` walks devices 0 to 31, functions 0 to 7 of each
  device (the function step happens inside the device loop, the loop stops on an all-ones vendor), reading each header
  through the bridge's window (`TypeBorg`). Header type 0 goes to `HalpInitializePCIFunction`; type 1 (PCI-to-PCI bridge) goes
  to it and then to `HalpCreatePCISubBus`, which registers a child bus handler, copies the parent's ranges,
  rounds the memory ranges to 1 MiB and the I/O range to 4 KiB, programs the bridge's numbers
  (`HalpInitializePCIBridge`) and recurses. Any other header type prints "Unknown header Type" and is skipped.
- **The HAL assigns the resources itself. Established.** `HalpInitializePCIFunction` disables I/O and memory
  decoding, writes ones to each base address register and reads the size back, rejects a register whose mask is not a power
  of two ("PCI: defective device"), raises every memory size below 4 KiB to 4 KiB, sorts the registers by size (largest first),
  and hands out addresses from the bus's remaining ranges (memory base aligned to its size; 64-bit registers take two
  slots; a prefetchable register falls back to non-prefetchable memory if the bus has no prefetch range, "cannot give out
  Prefetch Memory"). It then sets the I/O and memory enable bits and calls the bus's interrupt-pin hook to write the
  interrupt line register from the pin tables above. `PCILOCK` (boot option) is read by the PCI set-up path; the routine that
  tests it was not traced. Resource-exhaustion returns `0xc000009a`.
- **The initial windows. Inferred.** The HAL image carries one statically initialised record per bridge (`PCISystemBusData`, two records of `0xc0` bytes, B first;
  the NT 4.0 image agrees with Windows 2000 RTM and SP4 as recorded in the first pass; the follow-on pass did not compare the bridge records, see [the Windows 2000 HAL tables](#windows-2000-hal-tables)). Each starts with the bridge's physical window address and the HAL replaces it with
  the mapped address, then the address and data registers (`+0xf8`, `+0xfc`) and a register at window `+0x48`. The bus handler's bus
  data points into the record, and the translation routine reads its range lists from there, so the layout is read from the
  consumer: for bridge B the I/O range is `0x0000` to `0x7fff`, for A `0x8000` to
  `0xffff`; both have a non-prefetchable memory range from PCI address `0x80000000` to `0x83ffffff` (64 MiB each); a further
  word holds `0x74000000` (B) and `0x70000000` (A), which looks like each bridge's system-side base for its 64 MiB (the 64-bit
  addition `HalpTranslatePCIBusAddress`, performs when it maps a bus address through the matched range's offset),
  and the translation routine (`HalpTranslatePCIBusAddress`) finds the range whose base and limit contain the bus address and
  adds that entry's 64-bit offset, so a bus-side `0x80000000` to `0x83ffffff` lands at system `0xf4000000` to `0xf7ffffff` on bridge B
  and `0xf0000000` to `0xf3ffffff` on bridge A (established for the routine and the initial data; the resource assignment that
  consumes the same ranges later was not re-read). Bridge A's I/O range carries an offset word of `0xffff8000` in the initial data, but `HalpInitSGIHostBridge` (`0x80018200`) rewrites the bridge's I/O range before enumeration: for a bridge revision above zero it zeroes the I/O range's system-side offset (64 bits, `+0x10` of the supported-ranges record); at revision zero it zeroes the I/O range base (`+0x18`) instead. It touches the memory ranges not at all (established, decompiled; in the newer build 20021 the routine only gains debug prints). So the offset in the initial data does not survive on revision-above-zero bridges. Neither bridge has a prefetch range. Memory BARs land at
  `0x80000000` on both buses (PCI side) and the Lithium windows are the only thing that tells them apart.
- **Interrupt pins. Established (above).** The per-bridge pin tables are reached through the pointer at record `+0xb8`
  (`HalpPciIntPin2SysIntLine`; `HalpSysIntLine2PciIntPin`).

### DMA

Established. The HAL has no scatter-gather or IOMMU code for the Cobalt or Lithium: its adapter objects are the stock x86
PC HAL's. `HalGetAdapter` hands out ISA/EISA 8237 channel adapters (page registers at the standard ports; the
EISA control base is never written, so it stays zero; the 8237 on the PIIX4 serves the floppy and parallel port) and master adapters that use *map
registers*: `HalpInitAdapterObjects` allocates a physically contiguous map buffer below 16 MiB from the
firmware's descriptors (64 KiB, or 192 KiB when the machine has memory above 16 MiB, ignoring firmware-permanent and
graphics-special descriptors in that test), and `IoMapTransfer` copies through it when a buffer lies above 16 MiB or crosses
a boundary the adapter cannot take (`HalpMapTransfer`, `HalpCopyBufferMap`). `HalpGrowMapBuffers` grows the pool in 64 KiB
steps. Common buffers (`HalAllocateCommonBuffer`) are contiguous memory below the adapter's mask. Cache flushing around DMA goes
through the Cobalt cache-operation path (`HalxFlushMdl` and friends, above). What the bridges or Cobalt do with a bus-master address (translation, limits, snooping) is not visible in the HAL: it
programs none of it.

### Memory banks and the graphics split

- **The HAL reads descriptors, not banks. Established.** `HalpSpliceGfxMemory` adds the page counts of the
  loader block's memory descriptors by type: type 3 (bad) is skipped, type 6 (firmware permanent) is counted in the total
  only, type `0x16` (the loader's "special memory") is the graphics memory, everything else is NT's. It prints "N MB Memory
  [G MB Graphics, M MB NT]". The first graphics bank comes from `HalpInitializeGbeDisplay0`: the first
  type-`0x16` descriptor large enough for the frame buffer (the size field times 16); if none is large enough it prints
"You need an updated PROM!" and carves 16 MiB (`0x100` units of 64 KiB) off the end of a free or firmware-temporary descriptor instead.
The boot frame buffer itself is capped at 1 MiB, with the visible height cut to fit. A static helper then records up to 32 banks
  (base address and size in pages) in `HalpGfxBankAddr` / `HalpGfxBankSize`. `HalpAddGbeDisplayToRegistry`
  publishes them: under `\Registry\Machine\System\CurrentControlSet\Services\SGICtrl\Memory` (keys the HAL creates) it writes `GraphicsMemory` (the frame
buffer's physical base), `GraphicsMemorySize` (bytes of the first bank), `NumberOfBanks` and per bank `BankAddrNN` / `BankSizeNN` (`NN` 00 to 31; the
HAL warns "Update the prom for aligned graphics memory" if a bank's base is not 4 MiB aligned or its size is not a multiple of 1,024
pages; an aligned bank is also remapped through KSEG0). The graphics miniport reads these.
- **How the split is requested. Established (miniport).** The graphics control panel's "Memory Reservation Profile" (a
  per-profile list of up to twelve bank sizes) reaches the miniport (`sgcomp.sys` 5.2.4, control code `0x232094`) as a count and
  sizes; the miniport rounds each size up to 4 KiB pages and writes the firmware environment variable `cogfxmem` through
  `HalSetEnvironmentVariable` as a decimal total followed by one decimal size per bank, all in pages, comma separated
  (`"total,b0,b1,..."`). A restart applies it: the firmware turns the variable into the special-memory descriptors the HAL
  reads (the install guide 007-3703-003 says a restart prompt appears and that the largest value offered is the installed
  memory minus 64 MB that NT reserves). What the PROM does with the string is the firmware side of
  [firmware.md](firmware.md) (the variable name `cogfxmem` is in the PROM image); not re-read here.
- **Bank decode registers. Unknown.** The HAL touches no Cobalt register that carries a bank address or size; the only
  memory-controller registers it uses are the ones above (ECC enable, error status, address and syndrome). The sixteen
  bank registers the firmware sizes memory from (`firmware.md`) are not used by any Windows code read.
- **Memory error and ECC path. Established.** `HalpInitMemErrSubsystem`: on non-Lite boards with `MEMERR` on, it
  maps physical page 0 (the window `HalpSoftEccVaddr` that `HalpCorrectSoftEccError` maps and then does not write through) and installs the two memory-error vectors on Cobalt entries `0x1a` and `0x1b` (on a Lite board it prints
  "Memory Access Error checking DISABLED on Cobalt Lite"); turning ECC on is the separate `HalpEccControl`, with the conditions in the option table.
  `HalpMemErrorHandler`, `HalpCorrectSoftEccError` and the logging helpers behave as described under the memory-controller table.

### Registry values the HAL writes

All through the standard registry calls (`ZwSetValueKey`, `RtlWriteRegistryValue`). Established.

| Key | Value | Written from |
|---|---|---|
| `\Registry\Machine\Hardware\Description\System\CentralProcessor\N` | `FeatureSet` (dword), `VendorIdentifier` (string), `~Mhz` (dword) | `HalpFixupRegistry` via `HalpFixupCpuRegistryNode`, one pass per processor until the open of key N fails; the values come from the HAL's per-processor `ChipSpecs` table (`HalpGetCpuFeatureBits`, CPUID) and its measured frequency |
| `\Registry\Machine\Hardware\Description\System` | `Serial Number` (binary) | `HalpReportSerialNumber`, only when the firmware gave a non-empty serial; the string's origin in the ARC tree was not followed |
| `...\Description\System\MultifunctionAdapter\N` | `Identifier`, `Configuration Data`, `Component Information` | `HalpAddMultiFunctionNode` for the nodes the HAL adds (Internal, PCI, ISA names from its table) |
| `SGICtrl\Memory` (HAL-created key) | `GraphicsMemory`, `GraphicsMemorySize`, `NumberOfBanks`, `BankAddrNN`, `BankSizeNN` | `HalpAddGbeDisplayToRegistry`, above |
| `\Registry\Machine\System\CurrentControlSet\Control\SystemResources\ReservedResources` | reserved ports and memory of the platform | `HalReportResourceUsage` family (key name in the image; the list was not read) |

### Uniprocessor and multiprocessor builds

`halbrgup.dll` has the same ~1,040 symbols as `halborg.dll` minus thirteen: the real-mode start stub (`StartPx_RMStub`, `StartPx_PMStub`,
`MpLowStub*`), `HalpGetProcessorInfo`, `HalpStartProcessor`, `HalpBuildTiledCR3`, `HalpMapCR3`, `HalpFreeTiledCR3`,
`MpFreeCR3`, `DebugCpuTable`, `Halp1stPhysicalPageVaddr` and a spin-lock variant. Established. The uniprocessor build still uses the
local APIC for the IPI-capable paths, the clock option, profile interrupt and performance counter (`HalpInitLocalAPIC`,
`HalRequestIpi` at the local APIC's interrupt command register `0xfffe0300` through the high-address mapping) and the Cobalt
entries; it has no table reader and `HalStartNextProcessor` returns false at once, and `HalpInitMP` does nothing more than
count calls and set the IPI-clock flag (no low-memory stub, no processor table read). In the multiprocessor build
`HalpInitMP` (phase 0) maps physical page 0 and allocates a page below 1 MiB for the stub (`HalpAllocPhysicalMemory`);
`HalStartNextProcessor` fills it as above. Setup chooses `halbrgup.dll` for the `SGI-320_ARCx86` and `SGI-540_ARCx86`
machine types and `halborg.dll` for the `_mp` ones ([nt-drivers.md](nt-drivers.md)).

### The Windows 2000 builds

Windows 2000 RTM (HAL file version string `5.00.2168.1`, PE time 1999-10-30) and SP4 (`5.00.2195.6655`, PE time 2003-01-15) each carry
one `halborg.dll` on their install CD (stripped, no symbol file shipped). The two differ in a few strings and one import. Their vector and ISA route tables are byte-identical, and their PCI pin
tables have the same pins with different string pointers (the bridge records were not compared). The tables are checked in the
[subsection below](#windows-2000-hal-tables). Against the NT 4.0 HAL:

- **A fourth board wiring.** Windows 2000 selects among four tables, not three: SYS TYPE 0 (320) by BOARD REV as before; SYS TYPE 1 (540)
  revision 0 uses the oldest tables and any other 540 the newest; any other SYS TYPE, or `INTRROUTE=HUGH2`, selects a new set. Its Cobalt
  entry vectors are `5a 92 8a 73 59 91 81 9b 69 89 7a (none) b9 71 79 72 ac ab aa a9 61 9c b2 6a a5 a3 bc f2 f7 f9`, bridge A's pin rows
  are slot 0 pin A `0`, slot 1 `1 5 6 5`, slot 2 `2 6 5 6`, slots 3 and 4 none; bridge B's are slot 0 pin A `8`, slot 1 `9 13 14 15`,
  slot 2 `10 15 13 14`, slot 3 none and slot 4 pin D `7` (slot 0 corrected in the subsection). Established as data. Which board this is (the name resembles the NT 4.0 option
  `HUGH006`; the Usenet note gives "hugh" as a code name for the 540 or the flat panel) is unknown.
- **Options.** `INTRROUTE` survives with one value, `HUGH2`, printed as "HAL: interrupt route %s"; `DEFAULT`, `NO8259`,
  `IDE8259` and `HUGH006` are gone. `ONECPU`, `PCILOCK`, `INTAFFINITY`, `BREAK`, `ARCINFO`, `SYSCLOCK`, `PAGEOPENPOLICY`, `MEMERR`, `ECC`,
  `BLOCKINTS`, `CACHEOPPOLL` and `USE8254` strings are still in the image.
- **Plug and Play.** The Windows 2000 HAL has the translator/arbiter entry points (`HaliGetInterruptTranslator`, "HalIrqTranslateResourcesRoot"
  messages), a one-vector-per-level table of eight-byte entries instead of NT 4.0's word table (`HalpGetSystemIntVec` reads the vector from
  offset 4 of the entry), and prints the frame buffer address and size ("Graphics: Framebuffer address"). The "You need an updated PROM" message
  is gone.
- **One HAL for both processor counts.** `txtsetup.sif` has a single computer type, `sgiborg_mp`, for the firmware ids `*SGI-3`, `*SGI-4`, `*SGI-5` and
  `*SGI-6` (Windows 2000 RTM and SP4), copying `halborg.dll` as `hal.dll`, `sgibvid.dll` as the boot video driver and `arcldr.exe`
  as the loader. Where NT 4.0 distinguished a 320 from a 540 and a uniprocessor from a multiprocessor NT in the machine identifier, Windows 2000 does
  not; the four ids are the firmware's, and mapping them to boards is unknown. The CD also holds `sgiu.inf` and `sgiul50.dll` / `sgiulnt5.sys`
  (SGI USB support); those are cabinet-compressed and were not opened.

### Windows 2000 HAL tables

Compared by bytes and values across the NT 4.0 image and both Windows 2000 images; no code was read. The NT 4.0 tables sit at
the addresses that the interrupt route set-up (`HalpInitIntrRoute`) loads. The symbol file names only the run-time pointers
(`CobaltInt2Vec`, `PciIntMapBusA`, `PciIntMapBusB`, `HalpIntrRoute`), which are zero in the file, and names none of the tables.
The NT 4.0 image holds fifteen tables of these shapes: three vector, six ISA route and six PCI pin.

Images, by file name, version and SHA-256 prefix:

- NT 4.0 `halborg.dll`, revision string 1.3, version resource 4.00, `0926cd50`.
- Windows 2000 RTM `halborg.dll`, version 5.00.2168.1, `a51bb518`.
- Windows 2000 SP4 `halborg.dll`, version 5.00.2195.6655, `213b3d97`.

Offsets are file offsets in each Windows 2000 image.

| NT 4.0 tables | NT 4.0 addresses | Windows 2000 RTM | Windows 2000 SP4 | Result |
|---|---|---|---|---|
| Vector: oldest, middle, newest (30 vectors each) | `0x80020e48`, `0x80020ec8`, `0x80020f48` | `0x10a08`, `0x10b08`, `0x10c08` | `0x10a28`, `0x10b28`, `0x10c28` | Same vectors in 8-byte entries (a zero dword, then the vector); no byte match |
| ISA route: oldest 320, middle 320, `no8259`, `ide8259`, 540 revision 0, newest 320 | `0x80020d28`, `0x80020d58`, `0x80020d88`, `0x80020db8`, `0x80020e18`, `0x80020de8` | `0x10888`, `0x108b8`, `0x108e8`, `0x10918`, `0x10948`, `0x10978` | `0x108a8`, `0x108d8`, `0x10908`, `0x10938`, `0x10968`, `0x10998` | Byte-identical, 48 bytes each |
| PCI pins: bridge A and B, generations 1 to 3 | `0x80020fc8`, `0x80020ff0`, `0x80021018`, `0x80021040`, `0x80021068`, `0x80021090` | `0x10e08`, `0x10e30`, `0x10e58`, `0x10e80`, `0x10ea8`, `0x10ed0` | `0x10e28`, `0x10e50`, `0x10e78`, `0x10ea0`, `0x10ec8`, `0x10ef0` | All 30 pin bytes identical; string pointers differ in every row, so no 40-byte match |

The ISA names are inferred from row content against the descriptions above, not stated by the image. Grades: byte-identical
blobs and pin bytes are established; the vector values are established with the layout difference noted.

Only in Windows 2000:

- **Vector table, new set.** RTM `0x10d08`, SP4 `0x10d28`. Against the NT 4.0 newest table, entries 0 (`92` to `5a`), 1 (`8a` to `92`),
  2 (`5a` to `8a`), 3 (`69` to `73`), 8 (`82` to `69`) and 11 (`73` to none) differ. Its values match the list in "A fourth board wiring" above.
- **PCI pins, new set.** Bridge A at RTM `0x10ef8` / SP4 `0x10f18`, bridge B at `0x10f20` / `0x10f40`. Slots 1 to 4 match the
  wiring above. Slot 0 does not: bridge A's slot 0 pin A is entry 0 and bridge B's is entry 8, not none.
- **Two ISA route tables.** RTM `0x109a8` and `0x109d8`, SP4 `0x109c8` and `0x109f8`. The first is the newest 320 table
  without its IRQ 15 row. The second adds that row: vector `0x73`, Cobalt entry 3, flag `2`. That vector equals entry 3 of the new
  vector table, so the row agrees with the new set. Why the first table has no IRQ 15 row is unknown.

Findings:

- Windows 2000 has four vector tables, eight pin blocks (four sets) and eight ISA route tables. Against NT 4.0 that is one more
  vector table, one more pin set and two more ISA tables. The "four vector tables" count and the "fourth board wiring" stand.
- RTM and SP4 agree: every vector and ISA table is byte-identical, and every pin block has the same pins. Only the pointer
  fields in the pin rows differ.
- RTM code names all four vector tables, all eight pin blocks and six of the eight ISA tables by absolute address (found by a
  scan of the RTM image; the code is not decoded). The two ISA tables with no such reference are byte-identical to the NT 4.0
  `no8259` and `ide8259` tables. That fits Windows 2000 keeping only `HUGH2`, but it is inferred until the selection code is read.

Still unknown: which table each SYS TYPE and `INTRROUTE` value selects, which board the new set serves, and the bridge records.

## Follow-on corrections and additions

Checked against `halborg.dll` 1.3 (and `halbrgup.dll` where noted) after the independent review of the second reading. Established unless marked.

- **Soft-ECC "rewrite" (`HalpCorrectSoftEccError`, `0x80019810`; the uniprocessor build has the same bytes).** The routine maps the page of the error address through the soft-ECC window, then forms a pointer to a quadword within the 32-byte line: the page offset of the address plus a lane offset from the syndrome argument (the third argument): `+0x00` if syndrome byte 0 is nonzero, else `+0x08` if byte 1 is nonzero, else `+0x10` if byte 2 is nonzero, else `+0x18`. It then executes `lock add dword ptr [esp+4], 0` at `0x80019867`, and `esp+4` is the stack slot that holds that pointer, not the memory it points to; no read or write of the mapped location occurs. It increments a counter and returns. A model must not depend on the HAL writing the corrected data back; whether the hardware scrubs the line on its own is unknown. The syndrome-byte-to-quadword lane mapping above is from the disassembly; its meaning for the memory width (256 bits plus ECC per the Cobalt page) is inferred.
- **`+0x20` bit 1.** The write pattern is established; write-zero-to-clear semantics are inferred.
- **Tick forwarding to the other processors.** The countdown that gates the broadcast is re-armed with the maximum increment each time it expires, and decremented by the current increment on every Cobalt tick, so after `HalSetTimeIncrement` shortens the tick the other processors tick at 10 ms intervals, slower than the boot processor's clock. The IPI-clock flag is set by the non-boot-processor phase-1 initialisation (`HalpInitMP`, `0x8002f210`: phase nonzero and processor number nonzero), so it stays clear on a machine that never starts a second processor. See [hal-hot-path.md](hal-hot-path.md).
- **`HalStartNextProcessor`.** It saves the dword at `0x467` and CMOS register `0x0f` before writing the warm-reset vector and `0x0a`, and restores both after the started processor has flagged itself or the wait expires.
- **8259 end of interrupt.** For a slave IRQ the slave gets the non-specific EOI (`0x20` to port `0xa0`) and the master the specific EOI `0x62`; a master IRQ gets `irq | 0x60`. (The earlier "specific EOI" wording in this page and the interrupt page covers the master only.)
- **`HalpEnableNMI`.** It writes the entry back as the value it read plus bit `0x400`, including whatever read-only bits the read returned.
- **LINT1** of the local APIC is programmed NMI delivery, masked and level-triggered (`0x184ff`: bit 15 set).
- **`FUN_800196e0` (no public name).** A read-modify-write of one byte of PIIX4 configuration space (bus 0, device 4, function 0, offset `0xcb`), setting bit 2; `HalpGetCmosData` and `HalpSetCmosData` call it once, the first time (flag at `0x800211a8`), and fail the access if it fails; what the bit enables is not shown in the HAL. The bit's name (the reviewer called it the CMOS extended-data enable) comes from the PIIX4 datasheet, which is not held: the byte and bit are established, the name is not.
- **Newer builds.** The two later 1999 NT 4.0 multiprocessor HAL builds (patch SG0020002, 28 April 1999; SG0020021, 28 July 1999; both unpacked from their installer cabinets, with their symbol files) were compared function by function with 1.3 after masking addresses. The interrupt, clock, IPI, profile, NMI, power-management, memory-error and Cobalt/Lithium code, and the vector, ISA-route and PCI-pin tables, are the same in both; 20002 differs only in the display start-up and the PCI range type-translation data, and 20021 in the PCI enumeration, BAR assignment, range handling and configuration accessors (about fifty routines, mostly larger) plus a debug-level test replacing a comparison throughout. Only the multiprocessor builds were compared; the uniprocessor builds of the patches were not.

## Power-management NMI and PCI bridge set-up

Read in the follow-on pass ([hot-path page](hal-hot-path.md) for the interrupt side). Established, `halborg.dll` 1.3.

**`HalpHandlePwrMgmtNMI` (`0x8001ecf0`, called first by `HalHandleNMI`, which Cobalt entry 29 reaches).** Reads I/O port `0xfb0`
(byte 0 of the PIIX4 general-purpose input register, offset inferred). If bit 2 is set it writes port `0xff3` = `0xfe` and reports
"not a power NMI". Otherwise it reads the byte at bridge B's window `+0x08`: nonzero, it writes bridge B's address register
(`+0xf8`) = `0x8000ff00` (bus 0, device 31, function 7: the configuration-mechanism-1 encoding of a special cycle) and data
register (`+0xfc`) = `0x00120002`, which is the encoding of an x86 "stop grant" special cycle (inferred from the value);
zero, it writes port `0xff1` = `0xca` and port `0xff0` = `0xba`. It returns true. `HalHandleNMI` then prints that the system halted and
breaks into the debugger; it does not power off. The ports `0xff0` to `0xff3` belong to no device identified so far and what
raises bit 2 is unknown ([questions](../../questions/visws-hal-open.md)). The soft-power path is separate: `pm_init_intr` clears the PM
status (`0xf80`), writes enable (`0xf82`) = `0x100` (power button) and control (`0xf84`) = 1; `pm_intr_handler` (on the vector for ISA
IRQ 9, level `0xb1`) acknowledges and calls `HalpPwrMgmtSuspend`, which writes CMOS `0x61` and reads `0x60`, if that reads `I` sets or
clears bit 0 of port `0xfb5` (set below board revision `0x20`), and writes `0x2000` to `0xf84` (suspend-enable, type 0). More than nine
errors disable the interrupt and bug-check `0x80`.

**`HalpInitializePCIBridge` (`0x8001d350`).** A standard PCI-to-PCI bridge set-up, written through the parent bus handler's
configuration-write routine as one 64-byte image: primary, secondary and subordinate bus numbers at `+0x18` to `+0x1a`
(the subordinate number is `0xff` during enumeration and the real highest bus afterwards), I/O base and limit at `+0x1c`, `+0x1d`
(upper 4 bits of the 4 KiB-aligned range), memory base and limit at `+0x20`, `+0x22`, prefetchable at `+0x24`, `+0x26` (1 MiB
granularity, an empty range is written inverted), secondary status `+0x1e` and status `+0x06` cleared with `0xffff`, bridge control
`+0x3e` = 0, command `+0x04` = (I/O and memory enables for the ranges that exist) plus bus-master. Behind such a bridge the
interrupt pin is swizzled by adding the device number modulo 4 (`HalpBridgedPciIntPin2SysIntLine`). Nothing is Cobalt-specific here; a
replacement HAL can use the generic bridge code.

**Not read** in either pass: the two I2C layers (flat-panel identification for the boot display; a replacement that does not
need the panel size can skip them), the V86 BIOS call path (for display BIOS calls only), and the Windows 2000 HAL below its
tables (no symbols). Two newer 1999 NT 4.0 HAL builds are compared in the follow-on section above.

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
`HalpInitializeRtc`; in the second reading also `HalpGetSystemInterruptVector`, `HalGetInterruptVector`, `HalpGetIntrDataByVector`, `HalEnableSystemInterrupt`, `HalpInitializePciBus`, `HalpAllocateAndInitPciBusHandler`, `HaliRegisterBusHandler`, `HalpEnumeratePciBus`, `HalpCreatePCISubBus`, `HalpInitializePCIFunction`, `HalpInitBarArray`, `HalpInitSGIHostBridge`, `HalGetAdapter`, `HalpInitAdapterObjects`, `HalpInitializeGbeDisplay0` and its bank helpers, `HalpAddGbeDisplayToRegistry`, `HalpFixupRegistry`, `HalpFixupCpuRegistryNode`, `HalpAddValueKey`, `HalpReportSerialNumber`, `HalpRegisterInternalBusHandlers` and `HalpTranslatePCIBusAddress`.

Not read: the `HalpGbeDisplaySetup` register programming beyond the sequence summarised above, the V86 BIOS call path, the I2C layers, the rest of the registry-reporting routines (`HalReportResourceUsage`'s port list), the PCI-to-PCI bridge programming in detail (`HalpInitializePCIBridge`), the translation range lists, and the Windows 2000 HAL below the tables (no symbols).
## Review

Independent review of chips commits 7990dc9..7a40091 by a reviewer who wrote none of them. Method: `halborg.dll` 1.3 (sha-256
`0926cd50…a048`) and `halbrgup.dll` from the SGI 320 NT 4.0 install CD Disk 1, with that disc's `halborg.dbg` and `halbrgup.dbg`
(counted as 1,044 and 1,031 public symbols by that review's reader; the Ghidra importer in the follow-on pass reads 1,050 records in `halborg.dbg`'s CodeView public-symbol stream, 1,037 in `halbrgup.dbg`. The reason for the gap of six was not traced, and the thirteen-symbol difference between the two builds matches the list above either way); symbol addresses were applied to an
`objdump` listing of each image and the routines below were read from it. Windows 2000 RTM and SP4 `halborg.dll` and `txtsetup.sif`
were compared by table. Ghidra was not run in this pass.

**Confirmed.** The whole boot-option routine and `HalpXtractOptionString`: all fourteen names and their value strings, the
`PAGEOPENPOLICY` values 0 and 2 OR-ed into Cobalt CPU `+0x10` by the static clock-and-control routine (which also clears bit 0 and sets
bit 3), and the `ECC` conditions in `HalpEccControl`. The `TypeBorg` accessors (address word at window `+0xf8`, data at `+0xfc`,
bus, device, function layout, raise-and-lock, crash-dump bypass), the `0x2000` write to the bridge status halfword at the end of
`HalpPCIConfig`, and the `0xf800` write and bus-number words in `HalpInitSGIHostBridge`. `HalpGetSystemInterruptVector` (types 0 and
5, unbounded table index, IRQL = vector >> 3), the newest-generation vector table, all six PCI pin tables, the ISA route tables
and the board-generation selection in `HalpInitIntrRoute`, the clock (`0x1c`/`0x1b`, vector `0xd1`) and NMI (`0x1d`/`0x1c`)
entries, the memory-error entries `0x1a`/`0x1b` with vectors `0xf1`/`0xf2`, and the map-buffer sizes. The Windows 2000 RTM and
SP4 vector tables (both the "new" and the `HUGH2` set, 8-byte entries) and the `txtsetup.sif` HAL mapping for NT 4.0 and
Windows 2000.

**Corrected in review.** The plain-substring options are not boundary-checked; the earlier-generation vector tables also differ at
entry 14; IRQ 5 has a vector in the middle and newest ISA tables; `HalpInitMemErrSubsystem` maps physical page 0,
not the memory-controller block; `BLOCKINTS` prints only at debug level 2 or more.

**Not checked here.** The Windows 2000 board-selection logic (only the tables), `HalpInitializePCIFunction` resource assignment, the
registry writes, and the `PCISystemBusData` bridge records.

## Re-check against a symbol-applied Ghidra project

Every established claim above was re-read from `halborg.dll` and `halbrgup.dll` with all public names and the data symbols applied, and
the data tables were dumped and decoded from the images. Windows 2000 RTM and SP4 were compared by table.

**Confirmed.** The boot options, their values and defaults; the Cobalt CPU, memory-controller and APIC register uses and the three
block mappings; the clock and calibration sequence; the memory-error path and its fatal and non-fatal conditions; the vector table
of the newest generation; the generation selection in `HalpInitIntrRoute` and the four ISA route tables plus the two alternates; all six
PCI pin tables; the bridge window registers and the `HalpInitSGIHostBridge` writes; the local APIC set-up values; the multiprocessor start
sequence; the `HaliQuerySystemInformation` classes; the descriptor accounting in `HalpSpliceGfxMemory`; the map-buffer sizes;
the reboot rule; the 8259 programming; the miniport's side of the graphics split (the 5.2.4 `sgcomp.sys` rounds each requested bank up to 4 KiB pages, accepts at most twelve, and writes `cogfxmem` as the page total then one count per bank), its request for internal-bus levels 24 and 25, and its query of the cache-flush class (checked with that pack's debug symbols and type file); the four Windows 2000 vector tables, identical in RTM and SP4.

**Corrected.** The graphics-bank fallback takes 16 MiB, not 1 MiB; the display back end is mapped as `0xa0` pages, not bytes; callback
slot 1 belongs to the corrected-error log, not the power path; the PCI interrupt line register holds a first-use ordinal that the bus
handler maps back to the Cobalt entry; the second byte of an ISA route row is a Cobalt entry used only when the 8259 flag is clear; the
oldest and middle vector tables differ from the newest in the entries listed under Interrupt delivery; the HAL writes id 4 into a zero
Cobalt APIC id; `HalpHandleCoNMI` reads entry `0x1d` on every board; the `SGICtrl\Memory` key is under the Services key.

**Regraded.** The system-side offsets of the bridge memory windows (`0x74000000` for B, `0x70000000` for A) were inferred and are now
established for the translation routine and the initial data. `PCILOCK`'s consumer is now named (`HalpAdjustPCIResourceList`) and the
meaning is inferred.

**Not re-read.** `HalpHandlePwrMgmtNMI` (power-management NMI decode through port `0xfb0` and a bridge write), the GBE display set-up
register sequence, the V86 BIOS path, the I2C layers and `HalpInitializePCIBridge`.
