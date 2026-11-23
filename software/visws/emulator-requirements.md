# Visual Workstation 320 and 540: what an emulator must provide

Two routes: run the firmware image (PROM 1.0002, 1.0004, 1.0005, 1.0006 and 1.1005 are held), or replace it with a small stand-in that leaves the machine in the state
the operating system software expects. Grades as in the [README](README.md). Everything below is a requirement
derived from shipped NT software and the public Linux port; the chipset's register behaviour itself is in the chip
pages.

## Running the real firmware

The PROM 1.0002, 1.0004, 1.0005, 1.0006 and 1.1005 images are held ([firmware.md](firmware.md)), so this route can be tried; no run has been done. 1.1005 is the release a real 320
reports and the one to aim for; "PROM 1.2" is 1.0002, the oldest; it asks for something different (the Lithium `+0x40` read-modify-write). What the image
asks of the machine before it reaches its main module: RAM that works up to 16 MiB with no sizing (the boot block copies
the flash to `0x80000` and expands the firmware to `0xf00000`-`0xff0264`), the Lithium configuration window at
`0xfd0000f8`/`0xfd0000fc` and the PIIX4 behind it, an NS87307 answering on ports `0x2e`/`0x2f`, the 8259 and DMA
ports, MSR and MTRR instructions, and Cobalt bank registers at `0xc6000048` and up (`0xc6000050` and up on all but Cobalt revisions `0xa0` and `0xa8`) that report populated banks
([boot-path.md](boot-path.md)). Before any of that the self-test module runs from flash: it needs RAM that answers write and read-back at
`bank * 128 MiB + 64 MiB` in 16 MiB steps for the banks that exist, a timer pair at `0xc6000008`/`0xc6000010`, CMOS at ports `0x70`-`0x73`,
COM1, the display ID `0x666` at `0xd0000014`, and Lithium identification `0x100210a9` at `0xfc000000` and `0xfd000000`
([firmware.md](firmware.md#the-self-test-module)). The flash is 512 KiB mapped at `0xfff80000` (software expectation: the HAL maps and programs it), accessed as a 16-bit
AMD-command-set flash with the usual two-cycle unlock; the ARC environment lives in its top 8 KiB sector, which the
operating system rewrites, so the device needs a persistent, erasable model. The firmware would additionally need the
chips the HAL expects (PIIX4, NS87307, CMOS RTC, 8259 pair, floppy, IDE and SCSI), a keyboard (a USB or PS/2
keyboard; the HAL carries `nogfxkbd` and keyboard nodes), and a working Cobalt graphics output for its menus.

What the 1.1005 firmware needs from the processor model itself (established, [processor state at the loader call](boot-path.md#processor-state-at-the-loader-call)): CPUID leaves 0, 1 and 2, `rdmsr` and `wrmsr`, `wbinvd` and `invd`, CR4 (only the global-pages bit is toggled and restored), `ltr`, `lgdt` and `lidt`, 4 KiB paging with the directory at `0xd00000`, `clts` and `fninit`. Hardware task switches (`ljmp` to a TSS selector) and V86 mode are used only when a PCI device with an x86 expansion ROM is found or `DosBoot` begins with `y`. No interrupt is ever enabled on the boot processor (IF stays clear from reset to the loader), so a model that delivers none to it is faithful. Address bit 20 must already pass at reset: the boot processor never writes port `0x92` or a keyboard controller, so A20
follows the PIIX4's A20GATE input (rows below; inferred that it passes on this board).

## A replacement for Linux

What the Linux visws port needs before it is entered ([boot-path.md](boot-path.md)), all established from the public
source:

1. A boot loader (or the emulator acting as one) that loads a kernel and sets the standard `boot_params` block with the
   memory size in `alt_mem_k` and a command line; no E820 map, MP table or ACPI table is read. Leaving `alt_mem_k` zero
   makes the kernel assume 128 MB.
2. RAM from 0 to the top of memory; the top 8 MB (the default; or the size passed as a boot parameter) is treated as the
   graphics frame buffer and reserved. Cobalt graphics memory is part of RAM, so the emulated memory map must have that
   region and the graphics model must render into it.
3. The processor table at physical `0x1e00`: a 16-bit count and the 20-byte processor entries, one per CPU
   (type 0, APIC id, APIC version, flags with bit 0 enabled and bit 1 bootstrap), at most four. For a single processor
   the 2.6 kernel needs count 1; entries after the first matter only for SMP.
4. Board identification. Linux reads the PIIX4 general-purpose-input bits 18 to 21 (the intended board-type field) from
   the byte at I/O `0x0fb2` (PM base `0x0f80` plus `0x30`, plus 2), then initialises the NS87307 (index and data ports
   `0x2e` and `0x2f`; logical device 7 is GPIO, its base register set to `0x0fc0`; logical device 8 is power
   management, base `0x0fc8`, with a function-enable register at index 1 whose bit 7 enables the GPIOs) and reads
   the 7-bit board revision from the GPIO data port `0x0fc0`. A 320 whose raw value is below 6 is revision 4, below
   12 revision 5, otherwise 6; the 540 is revision 2. In the Linux source the board-type expression masks the port
   value with the port *number* (a source slip), so only bits 1, 4, 5 and 7 of that byte take part and the
   result can only be a multiple of four: a 540 can never be recognised and a stand-in that wants the "320"
   banner must return zero in those bits. Whether any firmware or hardware cares is unknown; the HAL gets the same
   information from the ARC tree instead. The result matters only for the Cobalt IDE entry (revision 5).
5. Lithium A at `0xfc000000` and B at `0xfd000000`: the PCI vendor and device words of the Lithium device at the
   config header offsets (a missing match only prints a warning), a bus-number register at `+0x44` readable as
   primary bus in the low byte, and the 16-bit interrupt-enable register at `+0x46`. Configuration mechanism 1.
6. Cobalt CPU block `0xc2000000` (revision at `+0x08`, control at `+0x10` with the timer run and mask bits, status at
   `+0x20`, timer reload at `+0x30`) delivering a timer interrupt on Cobalt APIC entry 28; Cobalt APIC at `0xc4000000`
   with 30 redirection entries and the ID register at `+0xffc` (bit 8 the enable); local APIC at `0xfee00000`. Linux
   also reads the Cobalt revision and the APIC id.
7. Cobalt interrupt routing to the CPUs with the entries listed in [nt-hal.md](nt-hal.md): the PIIX4 8259 master as one
   level input (entry 12) that the kernel polls with the OCW3 poll command, IDE on entries 4 and 2 (the revisions noted; the HAL puts the first channel on entry 1 on the oldest 320 generation and on 5 on the middle one),
   PCI slot lines on entries 0 to 15 per the two bridge map. The kernel does not use an I/O APIC.
8. The warm-reset vector method for starting the other processors (CMOS register `0x0f` set to `0x0a` and the
   vector at `0x467`) and the local APICs' INIT and startup IPIs.
9. Reboot by a write of `0x06` to port `0xcf9` and power-off through the PIIX4 PM control registers
   (suspend-enable at `0xf84` bit 13, after clearing status at `0xf80`, then the special cycle through `0xcfc`).
10. The standard PC legacy devices (8259 pair, 8254 not used for the clock, CMOS RTC, IDE, floppy, serial, parallel, PS/2
    or USB input through the PIIX4's USB controller on its dedicated Cobalt entry).
11. The entry state, if the stand-in starts a kernel itself rather than running the PROM and an ARC loader
    ([processor state at the loader call](boot-path.md#processor-state-at-the-loader-call)): protected mode with paging on and
    all RAM identity-mapped (SGI's 2.2.10 image needs exactly this, because its first `lgdt` operand is a virtual address
    and its first CR3 load is made with paging already on); interrupts off. Reproducing the PROM further also reproduces its limits: its
    selector `0x18` is a flat DPL 3 code segment, page 0 is not mapped, and the devices are reachable only through aliases from `0xb0000000`, so
    a mainline 2.2 or 2.4 kernel (which loads `0x18` into DS and ES before its own GDT and then stores through them)
    stops at its first store, as on the real firmware. A stand-in that wants those kernels to run provides a flat writable `0x18`.

## A replacement for Windows NT 4.0

NT is started through ARC rather than BIOS and `ntldr`, so the stand-in has to be ARC-like. In addition to everything in
the Linux list that the HAL also reads (items 3 to 9):

1. An OS loader entry point: run `arcldr.exe` from the system partition, with the ARC firmware services it calls
   for disk, file, memory and environment access, the keyboard and the console, and a populated NT loader block. The
   loader reads the environment variables named in [boot-path.md](boot-path.md) and expects partition names in the
   ARC `multi()` or `scsi()` forms (firmware 1.1002 onwards uses `scsi()`).
2. The ARC component tree under the loader block: a system node whose identifier gives the product name, the
   processor and floating-point nodes NT registers, and the node "SGI REV INFO" with the children "SYS TYPE" and "BOARD
   REV" as one-byte configuration data, which the HAL cannot do without (it uses them to pick interrupt routing and the
   reset method). The loader block must supply a memory descriptor list with the usual types, a reserved graphics buffer in
   the special type `0x16`, and the firmware-permanent region.
3. Everything the HAL touches that the Linux port does not: the Cobalt memory-controller block at `0xc6000000` (error
   status, address, syndrome and the ECC enable; its reset values are unknown and the HAL clears the first register
   at start-up), the flash and its NVRAM environment at `0xfff80000` with a valid checksum, the CMOS RTC (including its
   update-in-progress flag, which the HAL uses as a one-second reference to calibrate both Cobalt's timer and the local
   APIC timer, so the Cobalt timer must count at its true rate against the emulated RTC), and the NS87307 logical
   device interrupt-type registers.
4. The Cobalt graphics device through the SGI driver `sgcomp.sys` (see [devices/cobalt-graphics](../../devices/cobalt-graphics/));
   the HAL's own text output goes through that Cobalt frame buffer only: its VGA text routines are present but unreachable (the display mode is fixed to the frame buffer), so a model that cannot start the frame buffer gets no HAL console output, not a VGA fallback ([nt-hal.md](nt-hal.md#boot-options-the-hal-parses)).

A standard Windows installer will not do: the SGI setup program replaces the HAL, the loader and the video driver.

## Exact versus tolerated

Every access the real firmware makes before its console is up that a model must answer, with what happens on any other answer. "Exact" means a different value changes the path taken in a
way that stops the boot or changes what the OS sees; "tolerated" means the firmware flags, reports or ignores it. Reading depth is in [boot-path.md](boot-path.md#reset-to-console-in-order-1005);
grades are established for what was read and inferred where a name or a branch only suggests it. Widths are those of the instruction.

| Access (width) | Expected | Other value | Class |
|---|---|---|---|
| Flash read at `0xffff0000` to `0xffffffff` and `0xfff80000` to `0xfffeffff`, 8/16/32-bit, at reset and by `rep movsl` | the image, readable before RAM works | nothing runs | exact |
| Flash autoselect at word `0x5555`, `0x2aaa`, 16-bit writes `0xaa`, `0x55`, `0x90`, then word 0 and word 1 reads | `0x20`, `0xd5`, then `0xf0` returns to the array | flash marked unknown; environment writes and the flash upgrade do not work (no halt) | exact for saving settings, tolerated for booting |
| Flash program/erase at `0x7a000` to `0x7bfff` (16-bit) | AMD-style command set with data polling, persistent | writes fail with error 6; the environment is rebuilt from defaults on each start | tolerated for a first boot, exact to keep settings |
| Environment block (`0x7a000`, zero word sum, first byte not `0x00`/`0xff`) | valid or erased | erased or wrong sum loads the built-in default table | tolerated |
| Whole-image record at flash `0x79fe8` (flag `1`, word sum zero) | consistent | the boot block loops forever retrying floppy recovery | exact |
| Self-test record at `0x79fc0` (checksum) | consistent | the self-test is skipped and boot continues | tolerated |
| Port `0xfb1` bit 7 (8-bit read) | clear | a floppy recovery attempt each boot, password override in the main module | tolerated if clear |
| Port `0xfb2` bits 2 to 5 (8-bit read) | board type: 0 for a 320, 1 for a 540 (2 and 3 for the 330 and 530); for type 0, bit 0 of the byte picks a class value `0x42` or `0x64` (`1.1005@0x1100130`) | other values change the board name; the wake-up delay is the longer one for every type except 0 | exact for the intended model |
| Port `0xfc0` bits 0 to 6 (GPIO data) | board revision | changes tables the HAL picks | exact for the intended model |
| Port `0xfb5` (GPO8 to GPO15, reset `0xbf`), `0xfb7` (GPO24 to GPO31, read-modify-write, 8-bit; bit 4 is GPO28) | read back as written; GPOREG resets to `0x7FFFBFFF` (PIIX4 p. 148), so `0xfb5` reads `0xbf` | none | tolerated |
| Ports `0x80`, `0xed` (writes) | accepted, no effect | none | tolerated |
| Lithium B window `0xfd0000f8`/`0xfd0000fc` (32-bit; also byte writes at `+0xfc..+0xff`) to PIIX4 configuration, registers `0x04`, `0x4e`, (and a dword `0x25000000` to `0xfd0000fc` after `0x800020c8` at `test+0x46ba`, which zeroes bytes `0xc8` to `0xca` and sets `0xcb`) `0x60`, `0x69`, `0x76`, `0x77`, `0xb0`, `0xb3`, `0xc8`, `0xcb`, function 3 registers `0x40`, `0x80`, and the special-cycle word | accepted and held | wrong behaviour of PM base (`0xf80`) leaves ports `0xf80`-`0xfbf` dead: later PM reads return all ones | exact for `0x40`/`0x80` (PM base `0xf80`; `0x40` reads back `0x0f81`, PIIX4 p. 120), tolerated for the others |
| Ports `0xcf8`/`0xcfc` (32-bit address, 8-bit data at `0xcff`) to bus 0 device 4 function 0 | the same registers as the window | register `0xcb` bit 0 and the `0xa5` CMOS marker handling go wrong; no halt | tolerated |
| Lithium identification `0xfc000000`, `0xfd000000` (32-bit read) | `0x100210a9` | the self-test's register test fails and the firmware prints an error (1.1005 drops the message in the main module) | exact |
| Lithium B `+0x08` (byte; zero means generation 1, so keep it non-zero), `0xff01c004` (32-bit) | generation 1 to 5 stamps (`0x35c0194c`, `0x35f7357f`, `0x363e4470`, `0x366c3dfb`); other values count as generation 5 or later | choose coherent DMA and stream-buffer bits and the audio host-control store | tolerated, exact for the audio write ([boot-path.md](boot-path.md#older-releases-and-reset)) |
| Lithium `+0x44`/`+0x45`, `+0x48`, `+0x58`, `+0x60` to `+0x70`, `+0x40` (1.0002 to 1.0004) | write-then-read-back registers | none | tolerated |
| Cobalt CPU block `0xc2000008` (revision, 32-bit) | any; `0xa0` or `0xa8` move the bank registers to `+0x48` | the bank registers are read at the wrong offset | exact |
| Cobalt memory controller `0xc6000000`..`+0x30` and bank registers `0xc6000048`/`0xc6000050` + 8*i | writeable; after the self-test's probe, reading back the bank codes 3, 2 or 0 | wrong bank codes give wrong memory size | exact (the self-test's probe is what sets them; a model may preset them) |
| RAM at `0` to `0xf60000`, `0x110000` to `0x11ffff`, `0x50000`, `0xc0080` | plain RAM, write/read back, present before the self-test's probe | the probe marks banks absent | exact |
| RAM probe at `bank*128 MiB + 64 MiB` in 16 MiB steps, patterns and the counter pair `0xc6000008`/`0xc6000010` | working RAM; counters that change | no banks found, memory error | exact |
| Memory total at least 64 MiB | yes | the load wrapper (`1.1005@0x113433b`) returns status 16 and `gfxmem_alloc` returns `-1` (what that leads to is unknown) | exact |
| Cobalt interrupt controller `+0xffc` (32-bit RMW) | holds the field written | none | tolerated |
| Local APIC `0xfee00000` (registers `0x20`, `0x30`, `0x80`, `0xd0`, `0xe0`, `0xf0`, `0x280`, `0x300`, `0x310`, `0x320`..`0x370`) | standard behaviour, SIPI and INIT broadcast delivered | other processors never appear; count stays 1 | tolerated for one processor |
| MSRs `0x17`, `0x2a`, `0x10`, `0x11e`, `0x200`-`0x20f`, `0x250`, `0x258`, `0x259`, `0x268`-`0x26f`, `0x2ff`, `0xfe` and `cpuid` 1, 2 | readable/writeable; TSC counts; signature stable across processors | unknown ratio gives 666 MHz in the boot block, 333 MHz in the report; a mismatch between processors is reported, not fatal | tolerated |
| NS87307 index/data `0x2e`/`0x2f`, power-management `0xfc8`/`0xfc9`, GPIO `0xfc0` | index/data pairs accepted; logical device 5 and 6 (UARTs) activated | the UARTs do not respond | exact for a serial console |
| COM1 `0x3f8`, `0x3f9`, `0x3fa`, `0x3fb`, `0x3fc`, `0x3fd`, `0x3fe`; COM2 `0x2f8` | 16550: LSR bit 5 ready, bit 0 data; MSR reads as written for a loop-back plug (or nothing) | absent UART (reads `0xff`) is tolerated by the self-test; the main module's serial console would not work | tolerated for the self-test, exact for `console=d` |
| CMOS `0x70`/`0x71` and extended `0x72`/`0x73` | 128 plus 128 bytes of battery RAM, preset or erased; `0x72`/`0x73` reach the extended bank only when `0xcb` bit 2 is set (reset clear, PIIX4 p. 68), `0x70`/`0x71` only when bit 0 is set | invalid contents are reinitialised; with bit 2 clear, `0x72`/`0x73` are forwarded to ISA instead | tolerated for the firmware; exact for the HAL, which sets bit 2 before its extended-bank accesses ([nt-hal.md](nt-hal.md)) |
| RTC (CMOS `0`, `2`, `0x0a` bit 7, `0x0b`, `0x0d`) | clock running, update flag toggling about once a second | "not running" flag; the speed fallback and the HAL's calibration need the toggle | exact for the HAL, tolerated for the firmware |
| PIIX4 PM `0xf80` (16-bit), `0xf84`, `0xf8c`, `0xfb0`-`0xfb7` | status clear on write one; control writes (`0x2000`) accepted | wake status bits set make the self-test take its resume path | tolerated if status reads 0 |
| PIIX4 function 3 registers `0x90` (SMBBA, written `0x0fd0`), `0xd2` (SMBHSTCFG, written `9`) and command bit 0, then SMBus I/O `0xfd0`-`0xfd7` (one six-byte block write to `0xd2`, never polled, `1.1005@0x11146b8`) | accepted and held; the I/O writes may be ignored | none visible: the firmware does not wait for or read the result. Without the I/O enable the writes are simply lost on a real part | tolerated ([boot-path.md](boot-path.md#piix4-function-3-the-smbus-base)) |
| 8259 pair (`0x20`, `0x21`, `0xa0`, `0xa1`, `0x4d0`, `0x4d1`), DMA (`0x08`, `0x0b`, `0xd0`..`0xd6`) | accept initialisation | none | tolerated |
| Port `0x92` bit 1 (APs; bit 0 is fast INIT) | bit 1 set deasserts A20M# whatever A20GATE does (PIIX4 p. 87; the text on that page says the reverse, corrected by spec update p. 54, documentation change 11) | with A20 modelled, a plain latch leaves A20 under A20GATE | exact when APs start and A20 is modelled; tolerated otherwise |
| A20 with port `0x92` bit 1 clear (reset value `0x00`): A20M# follows the board's A20GATE input; A20M# is high-Z in reset and needs a pull-up (PIIX4 pp. 15, 26, 87) | A20 unmasked for the BSP's accesses above 1 MiB, which it makes with no write to port `0x92` (inferred: A20GATE high or A20M# held high on this board) | masked A20 aliases accesses above 1 MiB onto the low megabyte; the page tables at `0xd00000` then map the wrong memory | exact (inferred). The USB legacy A20GATE pass-through is off at reset (function 2 `0xc0` bit 5, PIIX4 p. 108) |
| Floppy controller `0x3f2` etc. | only for recovery | none | tolerated |
| Self-test skipped (record bad) | the model must then preset the bank registers, the UART and the CMOS itself | no memory found | tolerated only with those presets |
| Display ID `0xd0000014` (32-bit read) | `0x666` | self-test display register test fails (no halt in the main module) | exact for the self-test |
| Audio host control `0xff001000` (32-bit write `0x4100` on generation 5, late in bring-up) and, just before it, a 256-dword table copy (117 dwords written, entries `0xdeadcafe` skipped) into the window at `0xff018000` when the stamp is at most `0x36ffd62f` | accepted | none | tolerated; exact if the NT audio driver is to start |
| Page `0x00fff000` (32-bit read) | RAM | unknown use | tolerated |
| `0xc6000048` (32-bit read, any Cobalt revision; the "DIMM Speed Check") | bit 16 set | the self-test reports a soft failure and the main module waits for Esc before booting ([prom-console-path.md](prom-console-path.md#ram-probe)) | exact for an unattended boot |
| Cobalt revision `0xc2000008` low byte | `0xa0` to `0xaf` | the "Cobalt-I/O Bus" row reports a soft failure (same wait) | exact for an unattended boot |
| Display registers `0xd0000018` to `0xd0080020`, 40 bit-walked words ([prom-console-path.md](prom-console-path.md#cobalt-lithium-and-piix4-register-tests)); Lithium B `+0x58` bits 1:0, `+0xf8` bits 23:2, `+0x44` bits 29:24; PIIX4 function 0 bytes `0x90`, `0x93`, `0x95`, `0xb2` (byte lane = register & 3; every pattern incl. a walking bit) | hold written values; dummy reads 4 bytes above must not fault | soft failure, same wait | exact for an unattended boot |
| Standard CMOS seconds and minutes (ports `0x70`/`0x71`, registers `0` and `2`), year | seconds or minutes differ between the self-test's read and the main module's later read; year 1998 to 2040 | counted failure ("Real-time clock is not running!"), same wait ([prom-console-path.md](prom-console-path.md#rtc-row)) | exact for an unattended boot |
| Memory controller `+0x18` after the ECC test (32-bit read) | 0 | the "ECC RAM Bus" row marks the slot bad | exact for an unattended boot |
| PCI configuration reads of an absent device (ports `0xcf8`/`0xcfc`, 16-bit) | `0xffff` | the scan sees a phantom device | exact |
| PCI configuration for devices behind the bridges, bus numbers `+0x44`/`+0x45` | standard header 0 and header 1 behaviour; bus 0 is Lithium B | the bridge assignment and device scan misplace devices | exact |
| Processor state at the loader call (a stand-in that enters a loader or kernel itself) | CS `0x08`, data registers `0x10`, selector `0x18` a flat code segment, PG and PE set, CR3 `0xd00000`, RAM identity-mapped, page 0 not present, IF clear, CD and NW clear, MTRR 0 write-back (type 6 with `coherentdma`) over the populated first 512 MiB group (128 MiB on a 128 MiB board), everything else uncacheable | a loader that relies on another state (a writable `0x18`, page 0, a device at its physical address, a different CS selector) behaves differently from the real firmware | exact for SGI's 2.2.10 image only as far as paging on and identity-mapped RAM; the rest is tolerated by the images held |
| Floppy/IDE/SCSI/USB/network adapters | as the driver names ([boot-path.md](boot-path.md#from-the-menu-to-the-loader)) | the boot entry cannot be opened ("Invalid boot device") | exact for the chosen boot device |
| Serial console choice | `console` variable begins `d` selects `serial(0)` | video and keyboard | tolerated |

## Not known

The graphics-memory split, the stand-in's ARC services at the byte level (the table's layout is in [boot-path.md](boot-path.md); which entries the loader calls is not enumerated),
the Cobalt memory controller's reset values and the register at `0xc6000048` on revisions other than `0xa0` and `0xa8`, and what the V86 monitor does with the embedded BIOS's port accesses. Where the embedded BIOS image goes is settled (`0xf8000` to `0xfffff`). The real firmware assigns PCI resources itself ([prom-console-path.md](prom-console-path.md#pci-scan-and-resource-assignment)), so a stand-in that skips it must do the same (bus numbers, BARs, bridge windows, command bits) or leave Linux and the HAL to; the HAL assigns anything unassigned. See
[questions/visws-firmware-open.md](../../questions/visws-firmware-open.md).

## Questions a machine model needs answered

Answers from the HAL (symbols applied), the loader and the PROM pages, each graded.

1. **Processor table, power-management block and hand-off.** The firmware writes the table at physical `0x1e00` from every running
   processor ([boot-path.md](boot-path.md#boot-into-nt) item 8); the HAL reads it at `0x1000 + 0xe00` and falls back to a built-in
   one-entry table (`DebugCpuTable`) when the count is zero (established). The PIIX4 power-management block at `0xf80` is set up by the
   boot block, through function 3 of the PIIX4: base register `0x40` = `0x0f80`, enable register `0x80` = 1 (established, firmware).
   The HAL never programs the base; it reads the status word at `0xf80`, the enable at `0xf82` and the control at `0xf84`
   (established). NT hand-off: the firmware loads `arcldr.exe` named by its environment variables, publishes the ARC system parameter block
   at `0x1000` with the vector table, and the loader builds the NT loader block, whose ARC tree must carry the "SGI REV INFO" children the
   HAL reads (established, boot-path.md). Linux hand-off: the firmware starts an ARC program (`arclx.exe` or a later loader, both held; `larc.exe` is not)
   that writes the boot block ([boot-path.md](boot-path.md#linux-loader-handoff)); what the firmware leaves in the block's other fields is unknown.
2. **Cobalt interrupt handling and the 8259/PIIX4 path.** [nt-hal.md](nt-hal.md#interrupt-delivery-in-the-hal) (established): all 30
   Cobalt APIC entries are masked at start-up; a device interrupt is enabled by writing the entry's vector with the level bit and
   unmasking the Lithium bridge's per-line enable; the master 8259's output is Cobalt entry 12, polled with OCW3 `0x0c`, with a specific
   EOI, and each legacy IRQ is re-injected as a self-IPI on its own vector; the clock is entry 28 (27 on Lite) at vector `0xd1`, IRQL `0x1c`.
3. **Lithium A versus B and the 540's board id.** The pin tables settle which device numbers have an interrupt wired
   ([platforms/visws/README.md](../../platforms/visws/README.md)): bridge B device 4 is the PIIX4 (only the USB pin D); the Ethernet in
   Linux's comments is bridge A device 3. Which device numbers are physical slots on the 320 versus the 540 is unknown. The PROM
   reads the board type as `(inb(0xfb2) >> 2) & 0xf` with 0 for the 320 and 1 for the 540 (established, firmware); that the 540 therefore
   needs bits 5:2 of the byte at `0xfb2` equal to 1 follows from the HAL's SYS TYPE values 0 and 1 and is inferred. The four bits are
   GPI18 to GPI21, non-multiplexed on the PIIX4 (PIIX4 p. 36); which pins SGI wired to them is unknown. Bits 1:0 are GPI16 and GPI17,
   and bits 7:6 are reserved.
4. **VGA or text mode.** The HAL's VGA text routines (physical `0xb8000`) exist but are unreachable: the display-mode word starts at the
   frame-buffer value and nothing changes it (established). The HAL console, and so NT's boot display, is the display back end at
   `0xd0000000` (the HAL's `gbe` code). Whether the firmware's embedded legacy-BIOS image exposes a VGA mode is unknown
   ([questions/visws-firmware-open.md](../../questions/visws-firmware-open.md)).
5. **A direct 8259-to-CPU route.** Nothing shows one. The HAL masks the local APIC's LINT0 on every processor, takes the master 8259 only
   through Cobalt entry 12, and the Linux port does the same (established for both). The PROM never unmasks LINT0 on the boot processor: the legacy-BIOS case writes it masked and the default path writes no local-vector-table
   register (established, [processor state at the loader call](boot-path.md#processor-state-at-the-loader-call)); the other processors' tables are unknown.
6. **Per-interrupt cost, destinations and acknowledge.** [hal-hot-path.md](hal-hot-path.md) (established): the HAL's interrupt level is the local
   APIC task-priority register, a device interrupt touches only the local APIC (no Cobalt, Lithium or PIIX4 register), the clock costs three Cobalt
   register accesses per tick (status read, write and read-back), a legacy interrupt costs four to seven 8259 port accesses, and every device line and the clock are written with destination 0, which on the I/O APIC layout means processor id 0 (inferred); only the NMI
   entry is logical. Board differences (memory groups, processors, slots, the `0xfb2` board-type byte):
   [boards-320-540.md](../../platforms/visws/boards-320-540.md).
7. **Processor state at the loader call.** Flat 32-bit protected mode, CS `0x08` and the data registers `0x10` from a GDT in a page the firmware allocates, interrupts
   off, paging on with the directory at `0xd00000` identity-mapping all RAM (page 0 unmapped, devices only through aliases from `0xb0000000`),
   a 256-gate IDT of firmware stubs, caches on with write-back MTRRs over populated RAM only (512 MiB-granular, from the bank table), 8259s masked, and no difference between the NT loader
   and a Linux loader (established, 1.1005; selector `0x18` is a code segment, which stops mainline 2.2 and 2.4 kernels at their first store but not SGI's
   2.2.10 image). Detail and addresses: [boot-path.md](boot-path.md#processor-state-at-the-loader-call).
