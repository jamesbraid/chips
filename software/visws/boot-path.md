# Visual Workstation 320 and 540: what the firmware hands over

This page records what the firmware does from reset and what it leaves behind for the NT loader and HAL and for the Linux
port. The reset path and the hand-off tables are read from the PROM 1.0006 and 1.1005 images ([firmware.md](firmware.md) for their
layout); the rest comes from the NT and Linux side. 1.0002, 1.0004 and 1.0005 are held too and were compared against 1.0006
([firmware.md](firmware.md#from-10002-to-10006)); [what they do differently at reset](#older-releases-and-reset) is below. 1.1002 to
1.1004 are not held. Addresses written `1.0006@` or `1.1005@` name the version read; an unlabelled routine was read in 1.0006 and
its 1.1005 counterpart was compared, as [firmware.md](firmware.md#from-10006-to-11005) says. Grades as in the [README](README.md); "software expectation" means the shipped
software assumes it. Reading was done with objdump over the whole boot block and in Ghidra (x86, 32-bit; base `0xf00000` for the 1.0002 to 1.0006 modules, `0x1100000` for 1.1005)
for the main-module routines quoted below.

## Start-up sequence

| Step | What | Grade |
|---|---|---|
| 1 | Reset vector at physical `0xfffffff0` is a near jump into the boot block at flash `0x7c000` | established (image) |
| 2 | Real-mode boot code gives the segments 4 GiB limits, sets up caching, optionally runs a patch record, then runs a table of eight set-up steps (the legacy I/O chip, DMA controller, 8259 pair, PIIX4 and Lithium set-up; [below](#the-boot-block)) | established (image) |
| 3 | The whole 512 KiB flash is copied to RAM at `0x80000`, and 32-bit code in that copy expands the compressed modules to `0xf00000`-`0xff0264` and calls the entry at `0xf00000` | established (image) |
| 4 | The main module reads the Cobalt bank registers to size memory, tests RAM, maps its device windows, sets up Lithium, starts the other processors and writes the processor table, builds the ARC tree and vectors | established for the parts quoted below; order inside the module only partly traced |
| 5 | A progress bar and the first start-up messages appear; Esc enters the firmware menus; otherwise the first boot entry runs | established (guide) |
| 6 | The firmware's own disk and file services load the OS loader named by `OSLoader` from `OSLoadPartition` or `SystemPartition` and pass it the start-up options | established (guide, loader strings) |
| 7 | The loader loads kernel and HAL, passes the loader block, and the HAL takes over devices | established (loader and HAL read) |

The power-on diagnostics level is "quick" or "extensive"; extensive also tests RAM at about 0.1 s per megabyte, and
the firmware can switch itself to extensive after a boot that did not complete (guide).

## Reset to console, in order (1.1005)

Method: the boot block and self-test module of 1.1005 listed with objdump (`i8086` and `i386`) and followed by hand; the main module
decompiled whole in Ghidra (1,555 functions) and read from the entry down. The boot block is byte-identical in every held release, so
its part holds for all five images. Addresses `1.1005@` are main-module virtual addresses, `test+` offsets in the self-test module
as in [firmware.md](firmware.md#the-self-test-module). Not every routine of the self-test and main module was read: what was read is
graded established, what is named from a call list or a string is inferred, and the gaps are listed at the end of the section and in
[questions/visws-firmware-open.md](../../questions/visws-firmware-open.md). "Tolerated" and "must be exact" for each access are collected in
[emulator-requirements.md](emulator-requirements.md#exact-versus-tolerated).

### Reset mapping and the flash

- **Where the flash is. Established (image).** The processor fetches `0xfffffff0`; the byte there is a near jump to offset `0xc000` of the
  segment based at `0xffff0000`, flash offset `0x7c000`. The boot block then reads flash through unreal-mode 4 GiB segments (reset vector
  tables, the self-test trailer at `0xffff9fa8` to `0xffff9fbf`, the self-test code itself at `0xffff4000` to `0xffff9fbf`) and, in
  32-bit code, copies the whole 512 KiB from `0xfff80000` to RAM at `0x80000` (`rep movsl`, `0x20000` dwords). So the whole flash must read back at
  `0xfff80000` to `0xffffffff` (size `0x80000`, last 64 KiB also at `0xffff0000`, the same bytes), at reset with RAM not yet usable. No other
  alias is used: the firmware never looks for the image at `0xe0000` or `0xf0000` (the legacy-BIOS image is copied into RAM there later, [below](#legacy-bios-and-the-acpi-tables)).
  Caching: the first MTRR code programs variable MTRR 0 as write-protect over `0xfff80000` (mask `0xfff80000`), variable MTRR 1 as write-back
  over `0` to `2 GiB`, clears `0x204` to `0x20e` (not `0x20f`) and sets MTRR enable `E` only (`0x2ff` = `0x800`, fixed ranges off); the self-test replaces that with its own 64 KiB write-protect range at
  `0xffff0000`; the copy to RAM is followed by a clear and one write-back MTRR over `0` to `2 GiB` again.
- **Which chip select. Unknown.** Nothing in the image names a chip select. The boot block writes PIIX4 ISA-bridge configuration register `0x4e`
  (`0xf4`) through Lithium B at step `0x1a`, after the code has already been running from the flash, so the reset-time decode is the
  hardware default (inferred: the PIIX4 decodes the top of the 4 GiB space to its BIOS chip select by default; the datasheet was not read for this).
- **Autoselect and ID. Established (`1.1005@0x1112f11`).** At main-module start-up the flash is probed: words `0xaa` at word index `0x5555`
  (byte `0xaaaa`), `0x55` at `0x2aaa` (byte `0x5554`), `0x90` at `0x5555`, then word 0 must be `0x20` and word 1 `0xd5`; then `0xf0` (read array) is written to word 0. A part that
  does not answer with those IDs leaves the flash marked unknown (`DAT_0114b9b8` is 0); the boot block's own write-protect probe in the flash tool uses the same
  commands and also reads the protection word of the boot sector at `0x7c004` ([firmware.md](firmware.md#the-flash-tool)). Writes are 16-bit, program `0xa0`, sector erase `0x80` + unlock + `0x30`, as in the HAL.
- **1.1005 against 1.0006 at the hardware interface. Established unless marked:**
  1. boot block, reset vector, environment sector and the build of the self-test's memory probe: the same;
  2. frame buffer moves from physical `0xa00000` to `0x2000000` (32 MiB), and the fixed memory descriptor list moves up 2 MiB with the module (`0xf00000` to `0x1100000`);
  3. first 32 MiB, not 16 MiB, are descriptor type 2; the bank step counts only 128 MiB banks (so a model must fill its 32 MiB banks in 128 MiB units to be seen; established, `1.1005@0x1102d90`);
  4. `gfxmem_alloc` limit 12 MiB per entry and 4 MiB alignment (graphics descriptors differ);
  5. two speed tables selected by CPUID signature (no register difference);
  6. extra display modes and the self-test's display BIST row removed (the ID row `0xd0000014 == 0x666` stays);
  7. new: ACPI tables (RSDP at `0xf0020`) and ARC node "ACPI-BIOS", board types 2 and 3 ("SG330", "SG530"), USB hub probing, disk partitioning utility, F8 boot options;
  8. the self-test gains `or $0x80` / `and $0x7f` masks around extended-CMOS indexes, and no new port or register;
  9. 1.1005's Lithium set-up has no `+0x40` access (also true from 1.0005).
  No other port, MMIO or PCI-configuration access that this page lists differs between 1.0006 and 1.1005 as far as the read routines go (inferred for the unread parts).

### The boot block's protected-mode half

**Established (`0xfd800` to `0xfffff` in the RAM copy, read as a listing).** After the step table the real-mode code copies `0x1f` dwords of vector
table from flash (`0xffffc200`) to physical `0` (RAM at address 0 must be writable and no BIOS data page is expected), loads the
descriptor tables, copies the flash and far-jumps to `0xfd800`. The 32-bit code (stack `0xeffff0`; a work area of `0x8bc` bytes is cleared at
`0x110000`) then:

1. reads the board's clock ratio from MSR `0x2a` through a table (the same 200 to 550 MHz rows) to get a delay scale (unknown ratio gives 666 MHz; used by microsecond delays that spin on the time-stamp counter, so `rdtsc` and a write of 0 to MSR `0x10` are needed and the counter must run);
2. reads port `0xfb1`: bit 7 set (GPI bit 15 of the PIIX4 power-management block at `0xf80`+`0x30`; the main module reads the same bit as its password-override jumper) requests a floppy recovery attempt;
3. checks the whole-image record at flash `0x79fe8` in the RAM copy: flag byte (top byte of the length word at `0x79ffc`) must be 1, the covered range must start at `0x80000`, and the 32-bit word sum
   must be zero. If not, the code loops forever: floppy recovery attempt, then a 5 s time-stamp delay, then again. Established;
4. floppy recovery (also run once when the jumper bit is set): resets the floppy controller (ports `0x3f2`, DMA `0x0c`), reads the boot sector of a 1.44 MB FAT floppy
   through the standard controller, compares the 19 bytes of BIOS parameter block from offset `0x0b` against a fixed 1.44 MB geometry, reads the root directory as one sector (LBA `0x13`, first 16 entries only), finds the volume label `SGISETUP` and then a root-directory file named
   `SGISETUP.EXE` or `PROM*.BIN` (first four characters `PROM`), reads it into RAM and either runs the loaded `SGISETUP.EXE` or runs the RAM copy of the firmware, in both cases with the first argument `8`.
   The file is read as contiguous sectors from LBA `first cluster + 0x1f`: there is no FAT walk, so a fragmented file fails; a `PROM*.BIN` loads at most `0x76000` bytes. Not found or any mismatch: the attempt is dropped silently. Established (listing read);
5. posts `0xc0`, expands the five sections (`dcaa`: checks the `SHDR` tag, post code `0xce` and a loop on failure), posts `0xcc`, sets `CR0.CD|NW` (cache off), `wbinvd`, and
   calls the entry address from the header as `entry(mode, arg)` with cdecl arguments taken from the work area at `0x110870` and `0x1108a4` (both zero in a normal boot; `mode` is 8 only after a recovery floppy).
   Post codes are only written; nothing reads port `0x80` back.

### Main module entry (1.1005@0x1100000)

**Established (decompilation and listing read).** Order of the first calls, with the hardware they touch:

| Step | Routine | What |
|---|---|---|
| 1 | `0x1100000` | two dwords `0x23456789` and `0xfedcba98` at physical `0xc0080` and `0xc0084`; the stack top is `0xf5ffec` (RAM to `0xf60000` must work) |
| 2 | `0x1104007` | for CPUID signature `0x672` to `0x67f` with MSR `0x17` platform id 2: the self-test's L2 control MSR `0x11e` write and restore again, without the `invd` |
| 3 | `0x1101db0` | port `0xfb7` bit 4 set (front-panel line, [below](#panel-led-or-beeper-line)) unless a quiet flag is set |
| 4 | `0x1112fc6` | flash ID probe above |
| 5 | `0x1111fda` | environment load: pointer `flash + 0x7a000`, validity test (first byte not `0x00` or `0xff`, word sum zero, [firmware.md](firmware.md#the-flash-part-and-its-contents)); invalid or erased block: a built-in default table is loaded (`DAT_0114b9b0` 5), valid: 1; the four partition and loader variables are then normalised to their ARC forms |
| 6 | `0x1100270` | platform bring-up (below) |
| 7 | `0x1107e40(0xa0)` | legacy-BIOS (V86) set-up, skipped when `console` begins with `d` or `D`, `Vx86DoNotRunBIOS` begins with `y`, the board is not newer than the second generation unless `ignorehughid` is set, or neither the flag set by a PCI scan (`0x111acd8`, variable `0x1147634`) nor `DosBoot` beginning with `y` holds ([below](#legacy-bios-and-the-acpi-tables)) |
| 8 | `0x1100530` | if `mode` is 8, the floppy flash-upgrade routine runs here (`1.1005@0x111525f`) |
| 9 | `0x1111a1d` | the autoload and menu stage ([below](#from-the-menu-to-the-loader)) |

Platform bring-up (`0x1100270`), in order: front-panel line on; coherent-DMA flag from the classifier at `0x1100240` (reads the stamp at `0xff01c004`: `0x35c0194c` gives 2, `0x35f7357f` 3, a larger stamp 4, any other `-2`) and the `coherentdma`, `l2cache` and `l2cache_ecc` variables; memory sizing
(the bank registers at `0xc6000048`/`0xc6000050` and up, [above](#the-main-module)); `0x1103c80` the processor wake-up (next subsection); `0x1113a02`
the device install list (keyboard and flash helpers, PCI scan and bridge assignment, SCSI and IDE adapters, floppy, USB, network, display, console selection); `0x11010b0` the processor and memory configuration check;
`0x11003e0` the Lithium generation reads; only then, when the Lithium generation is 5, the copy to the `0xff018000` window and the `0x4100` store ([below](#older-releases-and-reset)); then the BIOS-area copies, the boot-mode text and the front-panel line.
The order of the PCI configuration cycles inside the device install list was not traced access by access (unknown): the bridge
assignment code is as [above](#pci-bus-numbering-and-windows), configuration cycles go through the Lithium B window at `+0xf8`/`+0xfc` for bus 0 devices and through ports `0xcf8`/`0xcfc` in the generic routines.

### Processor wake-up (`1.1005@0x1103c80`)

**Established (listing; the decompiler dropped the ICR writes).** There is no warm-reset vector write and no CMOS shutdown byte in this routine; the boot processor wakes the others itself:

1. front-panel line on; interrupts off; caches switched off (`CR0.CD`, `wbinvd`, `CR3` reload, `invd`, `0x1103fd5`) until the routine ends, when `CD` and `NW` are cleared (`0x1103fc7`); count `1` written to the 16-bit word at `0x1e00`; the mailbox byte `0x505` cleared; `0x210` bytes of start-up stub copied to physical `0x50000`; byte `0x504` (the next local APIC id) cleared;
2. the boot processor enables its local APIC (spurious-vector register `0xfee000f0`, bit 8, vector nibble cleared) and sets its APIC id register (`0xfee00020`) to its sequence number (0), recording the id in a table; hook routines (microcode update) run; its own table entry is written ([below](#the-processor-table)); the Cobalt interrupt controller's `+0xffc` field (bits 27:24) is set to 4;
3. error status `0xfee00280` cleared; interrupt command register high word `0xfee00310` = 0; low word `0xfee00300` = `0x000c0650`: start-up IPI, vector `0x50`, all excluding self, edge. Mailbox `0x506` = `0x55`; spin `0x180000` loops on a 320 and `0xe00000` on a 540 (board type from port `0xfb2` bits 2 to 5);
4. read of the error status, then INIT assert (`0x000cc500` with destination field 1) and INIT de-assert (`0x000c8500`), the APIC error register cleared again: the other processors are parked in wait-for-SIPI state for the operating system;
5. each woken processor runs the stub: it takes a byte lock at `0x505` with `xchg`, switches to protected mode, sets bit 1 of port `0x92` (fast A20), increments the count at `0x1e00`, runs the same hooks, writes its processor-table entry, clears only the fixed-range MTRRs (`0x250`, `0x258`, `0x259`, `0x268` to `0x26f`) and releases the lock, sets mailbox `0x506` to `0xaa` and halts.

Nothing else is needed from the model than: local APICs that accept the SIPI and INIT broadcasts, RAM at `0x50000` and `0x1000` to `0x1fff`, and port `0x92`. How the main module handles a missing second processor (the count stays 1) is the same code path (inferred: the wait is a fixed spin, not a handshake).

### The processor table

Format as in [Boot into NT](#boot-into-nt), item 8, confirmed against the writer (`1.1005@0x1103efd`): the entry is `0x1e02 + 20*index`; byte 0 = 0 (type), byte 1 the local APIC id (register `0x20` bits 27:24), byte 2 the APIC version (low byte of register `0x30`), byte 3 the flags (bit 0 enabled, bit 1 boot processor, which the caller selects through `cl`), `cpuid(1)` EAX and EDX at `+4` and `+8`, `cpuid(2)` EAX and EDX at `+12` and `+16`. Established. The firmware's own scan of the table (`1.1005@0x11010b0`) reads four entries and
sets configuration flags; it is report-only ([above](#older-releases-and-reset)).

### CMOS, the real-time clock and the extended bank

**Established (self-test listing and `1.1005@0x1101ca0`, `0x1101470`, `0x1101530`).**

| Access | Use | If it reads otherwise |
|---|---|---|
| ports `0x70`/`0x71`, standard bytes `0x2e` and `0x2f` | looked at for an `0xa5` marker; if neither holds it, `0xa5` is written to both and Cobalt CPU block `+0x18` bit 0 is set. Both bytes are then always zeroed (`test+0x4161`); PIIX4 ISA register `0xcb` bit 0 is cleared at `test+0x40ea` and set again at `test+0x4192` in every case | the marker is rewritten; no halt |
| standard bytes `0x30` to `0x3f` | compared with a fixed 16-character tag; written when the tag is not there | CMOS counted as invalid and reinitialised; no halt |
| standard bytes `0x40` to `0x4f` | sixteen bank codes written by the self-test (3 = 128 MiB, 2 = 32 MiB, 0 absent) and read by `1.1005@0x11012f0` | see [memory](#memory-controller-and-graphics-memory) |
| standard bytes `0x50` to `0x53` | last-boot configuration word, read back and replaced by the self-test and main module | a difference only sets a flag |
| standard bytes `0x60` to `0x68` | wake/power-fail state copied from the PIIX4 power-management status (`0xf80`, `0xf8c`) | informational |
| standard byte `0x7f` | bit 2 toggled by self-test commands | informational |
| ports `0x72`/`0x73`, extended bytes `0x81` to `0x89` | a four-byte magic, two bytes of state and a CRC-16 (polynomial `0x8005`, byte-serial, start 0) of them at `0x88`/`0x89`; verified by the self-test at start (`test+0x4718`, `+0x479e`) | invalid: the record is rebuilt (`test+0x6f0e`) |
| extended byte `0x8c` | self-test state marker (two values, `0xbb` and `0xba`, and `0xff`) | selects the "about to reset for BIST" and "about to test BIST result" paths: the self-test may reset the processor and re-enter itself once |
| extended bytes `0x8a`, `0x8b`, `0x8d`, `0x8e`, `0x8f` | state, flags (`0x8a` bit 7 is read by `1.1005@0x1100a00`) and a stored copy of the previous run | tolerated |
| extended bytes `0x98` to `0x9b` | processor and memory configuration flags written by `1.1005@0x11010b0` (flag bits `0x1` to `0x80000`; bit `0x40000`: the `eaddr` variable does not begin with the SGI company id) | flags only |
| extended bytes `0x9c` to `0x9f`, `0xfc` to `0xff`, `0x00` to `0x01` | RTC and boot-state records: `0x9c` bit 0 set when seconds and minutes read at the start equal the copy stored at `0x9e`/`0x9f` (clock not running); `0x9d` bit 0 set when the year is outside 1998 to 2040; `0xfc` to `0xff` the last bank and processor configuration with a CRC-16 at `0x00`/`0x01` (`1.1005@0x1101650`, `0x1101530`) | mismatch only flags |

The RTC itself is read through the standard registers (seconds `0`, minutes `2`, register `0x0a` update-in-progress, bit 7, polled by the speed fallback); "Real-time clock is not running!" is a string of the diagnostics. Nothing was found that halts on an RTC value.

### Serial output before the console

**Established.** The self-test writes progress text to COM1 (`0x3f8`, divisor 12 so 9600 baud, 8N1, interrupts off) from the first message on, polling the line status register bit 5 (`0x3fd`)
before every byte; no initial presence test of the UART exists, so an unclaimed I/O port that reads `0xff` is tolerated (the poll sees "ready" and the bytes go nowhere). Extended byte `0x80` holding `0xee` makes a failed plug test count as a pass and is then rewritten `0xff`. A loop-back plug test follows (`test+0x4d82`: modem-control writes of `0`, `1` and `2` with modem-status reads masked `0xf0` = 0, `0x50` and `0xa0`); with the plug present the self-test serial
manager prompt is entered, otherwise it only continues. The prompt is also where the self-test stops after a failure: it posts an error code to port `0x80`, prints it, and then loops
on the console input while pulsing the front-panel line; only a byte arriving on COM1 (the `go` command) continues. So a failing self-test is a halt that needs the serial line. With no UART the line status reads `0xff`, so "data ready" is true and the byte read is `0xff`, which the loop accepts: the stop is not hard on a model without the UART.

### Panel LED or beeper line

Port `0xfb7` bit 4 (PIIX4 general-purpose output bit 28; the register is `0xf80 + 0x34` + 3). The self-test clears it, then makes one pulse (set, a `0x3fffff`-iteration delay, clear) after the UARTs are
enabled; the main module sets it in `0x1101db0` and clears it at the end of the processor wake-up and elsewhere. The effect is unknown (LED or beeper; established that it is only written, read back
only for read-modify-write).

### Console selection (main module)

**Established (`1.1005@0x1113ca1`, `0x1101d40`, `0x11277d8`).** The ARC variables `ConsoleIn` and `ConsoleOut` are set from the `console` variable: the default value is `g`. If a display and keyboard device exist (a scan of the static device table at `0x119c358`, true in this image on review; no code that empties it was found) and the first character of `console`
is not a lowercase `d`, the console is `video()` and `keyboard()`; otherwise it is `serial(0)`, or `serial(1)` when the first character is `r`. The legacy-BIOS skip in step 7 accepts `d` and `D`. A default `rbaud` of `9600` sits next to the default strings (the serial driver's use of it was not traced). `serial(0)` is the 16550-compatible port at `0x3f8` (IRQ 4) and `serial(1)` at `0x2f8` (IRQ 3);
both are NS87307 UARTs (logical devices 6 and 5 of the super-I/O, activated by the boot block's step `0x10` and again by the self-test, `test+0x46d4`); the PIIX4 has no UART. No Arsenic access is involved in console selection or in the serial driver.
If opening the console fails, the code sets `NoAutoLoad`, reports "CONSOLE OPEN FAILED" and retries on the other kind once.
The line speed of the main-module serial driver was not traced (unknown).

### Legacy BIOS and the ACPI tables

**Established (`1.1005@0x1107e40`, `0x111a293`, `0x113eda9` to `0x113f07c`; fields read from the listing).**

- The legacy-BIOS image (the "Main BIOS" in the second data module, copied so that it ends at 1 MiB, to `0xf0000`) and a V86 monitor are set up only when the conditions in step 7 hold, and then five small areas (low page `0x1000`, `0xf0000`, `0xf0020`, `0xf0e00`, `0xffff5`) are saved and restored around it.
  Whether the image exposes a VGA mode to the OS is unknown: the string "Enable VGA Mode" is a monitor setting with no code reference found.
- ACPI: only a root description pointer, a root table and one fixed description table. The pointer (`RSD PTR `, revision 0, OEM id `SGI___`) is written at physical `0xf0020`; it points at the root table at `0x116b0a0` (signature `RSDT`, length `0x28`, revision 1, OEM table id `320/640`, one entry); the entry is the fixed table at `0x116b020`
  (length `0x74`, revision 1, same ids). Each table's checksum byte makes the byte sum zero (routine `0x111a27e` sums, the table stores the negation; the pointer's covers its first 20 bytes). The fixed table's firmware-control and DSDT addresses are zero: **no FACS, no DSDT, no MADT, no
  other table exists.** The register fields are those in [firmware.md](firmware.md#from-10006-to-11005) plus: event block length 4, control length 2, timer length 4, GPE0 length 4, latency fields 10000 (C2 and C3 not supported), duty offset 1 and width 3, RTC day alarm index `0x0d`, flags `0x25`.
  An ARC child of the root node, "ACPI-BIOS", carries the 20-byte pointer as its configuration data. The node builder `0x111a293` is reached through a device-table entry (`0x119c40c`). Whether Windows 2000's loader or HAL consumes it is unknown (the NT HAL pages record no ACPI use, and without a DSDT an ACPI driver cannot enumerate devices; inferred, not proved).
- Local APIC set-up for the V86 case (`1.1005@0x1109370`, boot processor): task priority `0xff` then `0`, destination format flat, logical id 1, spurious vector register `0x11f`, error vector `0xe3`, timer `0x300fd` (masked, periodic), performance counter `0x100fe` (masked), **LINT0 `0x1001f` (masked, vector `0x1f`) and LINT1 `0x184ff` (masked, NMI, level)**, error status cleared. The other processors' local vector tables are not programmed by the stub read (unknown). On the boot processor nothing restores the table before the loader runs: every later user of the mapped APIC window (`0x119c684`) lies in the V86 code, so the loader sees this set when the V86 task has run, and reset values when it has not ([processor state at the loader call](#processor-state-at-the-loader-call)).

### From the menu to the loader

**Established (`1.1005@0x1111a1d`, `0x110fa3d`, `0x1133d4b` and callees).**

1. `AutoLoad` begins with `y` or `Y` and `NoAutoLoad` is unset: the "Press Esc key to stop system boot" countdown (`CountDown`, seconds) runs with keyboard input; Esc opens the menus. The password level (`passwd_level`) is checked first.
2. Boot (`0x110fa3d`) resolves the boot entry from the ARC variables: the loader name is built from `SystemPartition` plus `OSLoader`, the kernel from `OSLoadPartition` and `OSLoadFilename`, options from `OSLoadOptions`. Default entries are
   `multi(0)disk(0)fdisk(0)partition(1)` and on 1.1002 and later `scsi(0)disk(0)rdisk(0)partition(1)` or `(2)` for IDE (adapter 0) and `scsi(2)disk(0)rdisk(0)partition(1)` for the SCSI adapter, `scsi(0)cdrom(` for the CD-ROM, with the Windows 2000 and NT 4.0 default
   entries named "Windows 2000 IDE Default", "WinNT 4.0 IDE Default", "Windows 2000 SCSI Default", "WinNT 4.0 SCSI Default"; the IDE controller is presented as SCSI adapter 0.
3. Devices the firmware drivers name: IDE hard disks and ATAPI CD-ROM (as `scsi(0)`), the floppy, QLogic SCSI and Fibre Channel adapters through a `ql1080` family driver, the network through a PXE-style BOOTP/DHCP and TFTP client (with a Windows RIS "BINL" reply handled and `netaddr` set from the reply; `eaddr` holds the station address and a leading SGI company id is expected), and USB keyboards and mice and hubs. The network adapter driver strings name an Intel 82557-class part. File systems:
   FAT and NTFS readers (the NTFS reader is the one the 1.0002 to 1.0006 label text called a bug fix).
4. The file is loaded by a COFF/PE loader (`1.1005@0x1133dc6`): an `MZ` header is followed at `e_lfanew`; the image must be machine `0x14c` with the executable bit, optional-header magic `0x10b`, its text start (masked with `0x1fffffff`) must fall in free memory. The wrapper that calls it (`1.1005@0x113433b`) returns status 16 when the total RAM is under 64 MiB (`0x4000000`); the loader body itself returns 16 when the text range is not inside a free descriptor (`0x110f7a0`) or on a bad file. `gfxmem_alloc` returns `-1` under 64 MiB too (`0x1104882`); what that does later is unknown. The sections are loaded to
   their linked addresses masked with `0x1fffffff`. ARC errors returned: 14 not found ("Boot file not found"), 16 no memory, 20 bad device ("Invalid boot device"), 8 and 15 for read or image errors.
5. Execute (`1.1005@0x1133ab5`, `0x1140abe`): the argument list and the environment are built as string arrays (`OSLoadPartition`, `OSLoader`, `SystemPartition`, `OSLoadFilename`, `OSLoadOptions`, `X86SystemPartition` and the console pair are exported as `name=value`), one pass of the device-polling loop runs (the firmware has no interrupt state to quiesce: it never enables interrupts), `clts` and `fninit` run, the stack pointer is set to `0x61ff0` and the entry is called with cdecl `(argc, argv, envp)`: flat 32-bit protected mode with the firmware's own GDT, IDT and page tables live ([processor state at the loader call](#processor-state-at-the-loader-call)), the ARC system parameter block at `0x1000` and its vector tables at `0x1200` and `0x1300` ([above](#boot-into-nt)), memory
   descriptors from the firmware vector (the loader asks for them through `GetMemoryDescriptor`). No other register is set up (the registers are whatever the call leaves; segment registers and descriptor tables are in the subsection below), and the loader's return value is printed as "Client program exits with a status".
   The loaded file is the OS loader named by the variables (`arcldr.exe` for NT, a loader named in `OSLoader` for Linux); nothing in the firmware is specific to either. Established that no Linux-specific path exists in the firmware.

### Processor state at the loader call

**Established unless marked.** Read from the 1.1005 boot block, its protected-mode half and the main module: every site that writes CR0, CR3 or CR4, loads a descriptor-table register, a segment register or the task register, or edits a descriptor was listed in the disassembly and read in the decompilation. The boot block and its descriptor template are the same in all five held images; the main-module facts are 1.1005 only. Everything holds for the boot path (`1.1005@0x1133d4b`, stack `0x61ff0`). The ARC `Execute` vector (`1.1005@0x1133d2f`) reaches the same routine with the stack its caller passes, and the monitor's `go` command (`1.1005@0x110c09a`) passes none, so that loader runs on the firmware's own stack.

- **Registers at entry.** CS `0x08`; DS, ES, FS, GS and SS `0x10`; TR `0x28`; LDTR null (no `lldt` in the image). The boot block loads CS with a far jump (`1.1005:flash+0x7c38a`) and the five data registers once (`flash+0x7d809` to `0x7d81c`). The main module never reloads them; its exception stubs save them, load `0x10` and restore them. ESP is `0x61fdc`: from the stack top `0x61ff0` the wrapper (`1.1005@0x1140abe`) pushes its frame pointer, `envp`, `argv` and `argc`, and the call pushes the return address (`0x1140ae6`), so the loader sees a plain cdecl call, and returning goes back into the firmware (which prints "Client program exits with a status"). The other general registers are whatever the call leaves.
- **EFLAGS.** IF is clear. The boot block starts with `cli`; the boot block, the self-test module and the main module contain no `sti` (bytes that look like one appear in the 16-bit disassembly of the self-test; each one checked lies inside another instruction), and every `popf` restores flags the same routine saved. Nothing leaves IOPL, NT, VM or AC set (processor detection toggles AC and ID and restores the original flags). DF is clear (inferred: compiled code, no `std` on this path).
- **CR0 is `0x80000011` (value inferred; every write established).** Each write to CR0 in the three stages is a read-modify-write of one bit group: PE (boot block), CD and NW (cache control; last cleared by `1.1005@0x1103fc7`), TS (cleared by the boot block, the V86 helpers and the `clts` of the call) and PG (set once, `1.1005@0x1103718`). So PE, PG and the reset-time ET are set and MP, EM, NE, WP and AM keep their reset value, zero. `fninit` runs at the call.
- **CR3 is `0xd00000`; CR4 is zero.** The page directory is the first page returned by the firmware's page allocator (`1.1005@0x11032b0`: physical pages upward from `0xd00000`, one per call, nothing handed out before the directory). Nothing sets CR4: the only writes (`1.1005@0x1103ff5`, `0x1104002`) clear bit 7 and put the original value back, so PSE, PGE and PAE are off (inferred from the reset value) and every mapping is a 4 KiB page.
- **The GDT.** The boot block copies a descriptor template to physical `0xf800` and loads it, with an IDT at `0xf000` (`lgdt` at `flash+0x7d833`, `lidt` at `flash+0x7d83b`; the RAM copy runs at `0xfd833`). The page-table builder (`1.1005@0x1103400`) loads TR with `0x28`, which marks that entry busy, then calls the relocation routine (`0x1103a60`): `sgdt` and `sidt`, one new page from the same allocator, a copy of both tables (GDT at the page base, IDT at base plus `0x400`, limits `0x3ff` and `0x7ff` unchanged), then `lgdt` at `0x1103acc` and `lidt` at `0x1103ad3`. Those are the only descriptor-table loads in the boot processor's main-module path (the application-processor stub carries its own 16-bit tables). The page's address depends on RAM size (inferred, by replaying the allocator: the directory, 16 page tables for the first 32 MiB, one more per further 4 MiB, one spare, 53 for the device windows, then this page): `0xd5f000` for 128 MiB and `0xd7f000` for 256 MiB (the memory scan counts 128 MiB banks, `1.1005@0x1102d90`). A loader should find it with `sgdt`. Entries (selector: base, limit, type, DPL):

  | Selector | Descriptor |
  |---|---|
  | `0x08` | base 0, 4 GiB (G, D), code execute/read, DPL 0 (accessed bit set) |
  | `0x10` | base 0, 4 GiB, data read/write, DPL 0 (accessed) |
  | `0x18` | base 0, 4 GiB, **code execute/read, DPL 3**: not a data segment |
  | `0x20` | base 0, 4 GiB, data read/write, DPL 3 |
  | `0x28` | 32-bit TSS, base `0xff0000`, limit `0x77`, DPL 0, busy; its CR3 field holds the live CR3 and its I/O-map offset is `0xffff` (`1.1005@0x11075a0`) |
  | `0x30` | data read/write, DPL 0, base 0, limit `0x1fff` (G, D) |
  | `0x38` | data read/write, DPL 3, base 0, limit `0xfff`, byte granular |
  | `0x40` | data read/write, DPL 3, base `0x400`, limit `0xffff`, 16-bit |
  | `0x50` | 32-bit TSS (available), base `0x20000`, limit `0xffff`, DPL 0 |
  | `0x58`, `0x60` | 16-bit code (execute/read) and data (read/write), base `0x20000`, limit `0xffff`, DPL 0 |
  | `0x68` | data read/write, base `0xb8000`, limit `0x3fff`, DPL 0 |
  | `0x70` | data read/write, base `0xffff7000`, limit `0x3ff`, DPL 0 |
  | `0x78`, `0x80` | 16-bit code and data, base `0x80400000`, limit `0xffff`, DPL 0 |
  | `0x88` | data read/write, base 0, limit 0, DPL 0 |
  | `0x98` | 32-bit TSS (available), base 0, limit `0x67`, DPL 0 (no code uses it) |
  | `0xa0` | rewritten at every boot by the main module (`1.1005@0x1107e7c` through the descriptor writer `0x1105040`): 32-bit TSS (available), base `0x1157dc0`, limit `0x2088`, DPL 0, the V86 task |

  Entry 0 and every unlisted entry are zero. After the relocation only the processor touches the table (accessed bits, the busy bit of `0xa0` when the V86 task runs). The `ljmp` sites in the main module are all task switches (`1.1005@0x1107e01`, `0x1105321`, `0x110747e`, `0x110752b`); none reloads CS. The layout is the ARC x86 one (`0x08` and `0x10` kernel, `0x18` and `0x20` user, `0x28` TSS, `0x30` processor-control data), which suits NT's loader and not a Linux kernel's `0x10` and `0x18` (inferred from the table).
- **Paging.** PG is set and CR3 is `0xd00000`. The builder (`1.1005@0x1103400`, from `0x1101de0` while the memory descriptors are set up) uses 4 KiB pages, present and writable, no cache bits except where stated:
  - **All RAM is identity-mapped,** one directory entry per 4 MiB of each memory descriptor in list order (the first 32 MiB as type 2, the rest as type 5, `1.1005@0x1102d90`): virtual equals physical from `0x1000` to the top of RAM. The first 32 MiB also appear at virtual `0x80000000` (directory entries `0x200` to `0x207`, with their own page tables); the rest of RAM has no high alias.
  - **Page 0 is not present** at either alias, unless the legacy-BIOS image runs (below). Pages `0x1000` to `0x10ffff` are marked user-accessible (`1.1005@0x1101de0`); a 2 MiB window at `0x2000000` (the frame buffer) is cache-disabled (`1.1005@0x11317f6`).
  - **Directory entry `0x300` points at the directory itself,** and **entry `0x3ff` points at a zeroed page table**, so `0xffc00000` and up is unmapped.
  - **Device windows are not identity-mapped.** Each is mapped cache-disabled at the next free virtual address from `0xb0000000` up (`1.1005@0x11031b0`, called from `0x1103730`): the Cobalt blocks, the local APIC, Lithium A and B, the flash, the display back end and the windows named in item 3 of [the main module](#the-main-module). The table of physical and virtual bases starts at `1.1005@0x119c5ac`. A loader that touches a device at its physical address takes a page fault.
  - **Nothing maps virtual `0xc0100000` to physical `0x100000`.** That address goes through the self-map: directory entry `0x300` treats the directory as a page table, so virtual `0xc0100000` reads directory entry `0x100` (the range from `0x40000000`), which is zero unless RAM exceeds 1 GiB and, if present, names a page-table page rather than `0x100000`.
- **IDT.** 256 interrupt gates (selector `0x08`, DPL 0, present), all pointing at firmware stubs. The boot block fills the whole table with a default gate (`flash+0x7f050`); the main module then overwrites every vector (`1.1005@0x1105de3`, called from `0x1107e40`, which main start-up calls at `0x11000aa` before any boot attempt, and keeps the present and DPL bits of the default fill). The stubs for vectors `0` to `0x7f` run from `0x1105378`, for `0x80` to `0xff` from `0x11057e3`; vector `0x0d` has its own at `0x1105220`. They push an error code and the vector and enter the monitor's dispatcher (`0x1108fc0`). For an unexpected exception it writes post code `0xfb` to port `0x80`, prints "Unexpected exception" with the frame, CS:EIP, EFLAGS and error code when the V86 debug level allows (default 1; 0 when `console` begins with `d`), and the stub ends in `cli; hlt` (`1.1005@0x1107529`) or a task switch back to `0x28` (the `0x0d` path was not traced to its end). So a fault before the loader installs its own IDT is reported and stops the machine; no interrupt is taken, because IF is clear.
- **Interrupt controllers.** The 8259 pair has master vector base `0x08`, slave `0x70`, 8086 mode and every input masked (boot block step `0x14`, `flash+0x7c528`); the PCI set-up writes the edge and level registers `0x4d0` = 0 and `0x4d1` = `0x06` (`1.1005@0x111b475`). No later write to either 8259 was found (inferred; the legacy-BIOS image, when it runs, was not traced). The boot processor's local APIC is software-enabled with spurious vector `0x0f` (register `0xf0` = `0x10f` if it starts at its reset value `0xff`, `1.1005@0x1103f81`) and its ID register set to its sequence number (0); no other APIC register is written in the default path, so the rest holds reset values (inferred). With the legacy-BIOS image run, `1.1005@0x1109370` leaves the set listed in [Legacy BIOS and the ACPI tables](#legacy-bios-and-the-acpi-tables), and no later write to the APIC was found, so that set is what the loader sees.
- **A20, cache, MTRR.** The boot processor never writes port `0x92` or the keyboard controller (only the application-processor stub sets bit 1 of port `0x92`), yet reads and writes above 1 MiB from the start of the protected-mode half (stack `0xeffff0`), so A20 already passes at reset (inferred). The PIIX4 datasheet (290562-001, p. 87) resets port `0x92` to 0, so A20M# follows the board's A20GATE input; A20M# is open-drain (p. 26) with a required pull-up (p. 15), which points to A20 unmasked at reset. What drives A20GATE on this board is open ([questions/visws-firmware-open.md](../../questions/visws-firmware-open.md)). CD and NW are clear. The MTRRs are the boot block's hand-off set (`flash+0x7c2f1` to `0x7c37a`): variable MTRR 0 write-back from 0 over 2 GiB, `0x202` to `0x20e` cleared, `0x20f` never written, default type uncacheable, enable set, fixed ranges off (`0x2ff` = `0x800`). The main module writes MTRRs only in the application-processor stub. So RAM is cacheable, and everything from 2 GiB up, flash and APIC window included, is uncacheable.
- **Legacy-BIOS case.** The V86 task runs only when the PCI scan finds a device with an x86 expansion ROM (`1.1005@0x111bfcd`, flag `0x114bc90`) or `DosBoot` begins with `y`, and the other conditions of step 7 hold. A stock 320 or 540 without such a card does not run it (inferred; no scan was run). When it does, pages 0 to `0xff` become present, writable and user-accessible (`1.1005@0x1107e40`) and stay so; the V86 task returns by a task switch to `0x28`, which restores registers, CR3 and flags (IF stays clear); and the processor leaves CR0.TS set, which the `clts` of the call clears. Everything else above is the same in both cases.
- **"Quiescing" is almost nothing.** Before the call the firmware runs one pass of its device-polling loop (`1.1005@0x1113e3b`), sets the boot-finished bit in the ARC restart block's boot status and refreshes its checksum (`0x110d48b`), and sets a client-running flag (`0x1111505`). It does not touch the interrupt controllers, the IDT or the APIC, because nothing in the firmware ever enables interrupts: its drivers poll.
- **The NT loader and a Linux loader get the same state.** The firmware loads one program format, a 32-bit x86 COFF image with or without a DOS header (`1.1005@0x1133dc6`): machine `0x14c`, executable bit set, optional-header magic `0x10b`, every section inside type-2 memory (`0x1140a48`, `0x110f7a0`), each section read to `ImageBase` plus its virtual address with `.bss` zeroed, entry at `ImageBase` plus the entry RVA. The subsystem, link time and file name are ignored (a `.dbg` extension and the section name `.bss` are the only special cases). `arcldr.exe` (a bare COFF image) and `arclx.exe` and `arclx2` (PE images linked at `0x400000`) take the same path, the same stack, descriptor tables and paging. There is no ELF, a.out or Multiboot path: a kernel is read by the ARC loader through the firmware's file calls, never by the firmware. The wrapper (`1.1005@0x113433b`) refuses to load anything below 64 MiB of RAM.

What this settles for Linux ([Linux loader handoff](#linux-loader-handoff)):

- **Selector `0x18` exists and is code.** Loading DS, ES, FS or GS with it succeeds (a readable, non-conforming code segment of DPL 3, loaded at CPL 0), and the first store through any of them raises #GP; loading SS with it fails. A mainline 2.2 or 2.4 kernel loads `0x18` before its own `lgdt` ([what the mainline kernels expect](#4-what-the-mainline-kernels-expect)); the first store through ES in 2.4 (the page-table build, `head.S:86-106`) and the `lss` of SS in 2.2 (`head.S:82`) come before either tree loads its own GDT, so on this firmware they would take #GP into the stub above and stop.
- **SGI's 2.2.10 image does not use the firmware's GDT.** It loads CR3 with `0x101000`, then `lgdt` and `lidt` of link-address operands (`0xc0100000` to `0xc0100015`), then the segment registers with `0x18`, sets PG again, jumps to `0xc0100040` and reloads CS with a far jump to selector `0x10` at `0xc0100166`. The first two instructions run at physical `0x100000` through the firmware's identity map. The `lgdt` after the CR3 load (physical `0x100008`) is fetched through the kernel's own directory: its entries 0 and 768 both point at one static page table whose 1024 entries identity-map the first 4 MiB (checked in the image), so the fetch works, and the `lgdt` operand at `0xc0100226` goes through entry 768 to the same table. It works only because PG is already set: with paging off the CR3 load would change nothing and the `lgdt` would read physical `0xc0100226`. Nothing else in the firmware's tables matters to the image: the kernel, the zero page at `0x90000` and its stack are below 4 MiB. CS keeps selector `0x08` until `0xc0100166`, which is harmless with IF clear and EFLAGS cleared by `push 0; popf` at `0xc010005d`.
- **A stand-in that enters a kernel directly** gets those kernels to run only by providing a flat writable selector `0x18`, which the real PROM does not; see [emulator-requirements.md](emulator-requirements.md#a-replacement-for-linux).

### Gaps in this trace

Not read at access level: the RAM probe loops (`test+0x7000` to `0x9600`), the Cobalt, display and Lithium register tests, the PCI scan access order, the SCSI, IDE, network and USB drivers, the serial driver's line settings and the flash-upgrade routine. They are in
[questions/visws-firmware-open.md](../../questions/visws-firmware-open.md).

## The boot block

**Established (flash `0x7c000`-`0x7ffff` read in full).** The code below is 16-bit with 32-bit operand overrides until the
jump to the protected-mode loader.
The boot block's code is byte-identical in all five held images (1.0002 to 1.1005; only its build-time trailer differs); its offsets are flash offsets, and the steps below are read from 1.0006's copy (the 1.1005 addresses quoted elsewhere on this page are main-module addresses, not boot-block ones).

1. **Entry.** `cli`, `cld`, then the reset-time `EAX` and `EDX` are parked in two MMX registers (so they survive; the
   purpose is inferred: `EDX` holds the processor signature at reset). A flat 4 GiB descriptor table is loaded, protected mode is entered once to
   load the 4 GiB segment limits and left again ("unreal mode"), so real-mode code addresses all of memory. Progress
   is shown as byte writes to I/O port `0x80` (`0xdf`, `0xdd`, `0x4b`, then the step numbers below).
2. **Caches.** Caches are disabled and flushed, every MTRR is cleared, and one variable MTRR is set over the flash window
   (base `0xfff80000`, type 4, write-protect). Cache is then re-enabled (post code `0xdd`). Step `0x02` below clears the whole MTRR set again
   when the processor reports fixed-range MTRRs.
3. **Self-test module (the old "patch record").** If the 24-byte trailer ending at flash `0x79fc0` has a non-zero, non-`0xffffffff` length word and the
   covered words sum to zero, the code jumps to the start of the record (flash `0x74000`) with a return address in
   the boot block. Both held images carry one, and it is the power-on self-test and memory-bank set-up
   ([the self-test module](firmware.md#the-self-test-module)), not a patch.
4. **Set-up steps.** A table of (step number, handler) pairs is walked; each step number is written to port `0x80` first.
   The steps in the image are:

   | Step | Action | Grade |
   |---|---|---|
   | `0x02` | if `MTRRcap` reports fixed-range registers, write zero to 28 MTRR registers listed in a table (`0x2ff`, the fixed and variable ranges) | established |
   | `0x06` | enable the cache (clear `CD` and `NW`, flush) | established |
   | `0x10` | NS87307: 26 index/data writes through ports `0x2e`/`0x2f` activate logical devices 0 to 8, put the GPIO block at `0x0fc0` and the power-management block at `0x0fc8`, then write the power-management register 1 with bit 7 (the GPIO-enable bit Linux also sets) | established; the logical-device meanings are the part's standard layout, inferred |
   | `0x12` | initialise the DMA controllers (writes to ports `0x08`, `0xd0`, `0xd6`, `0x0b`, `0xd2`, `0xd4`) | established |
   | `0x14` | initialise the two 8259s: master vector base `0x08`, slave `0x70`, all inputs masked | established |
   | `0x1a` | write nine (register, value) bytes into the PIIX4 ISA bridge's configuration space (bus 0, device 4, function 0) through Lithium B's configuration window at `0xfd0000f8` and `0xfd0000fc`: register `0x04`=`0x0f`, `0x4e`=`0xf4`, `0x60`=`0x09`, `0x69`=`0xf2`, `0x76`=`0x0c`, `0x77`=`0x0c`, `0xb0`=`0x4d`, `0xb3`=`0x60`, `0xcb`=`0x25` | established; device identity inferred from Linux |
   | `0x1b` | PIIX4 power-management function (device 4, function 3): register `0x40`=`0x0f80` (base `0x0f80`), register `0x80`=`0x01` (enable) | established |
   | `0x2a` | set the low five bits of the dword at `+0x58` in both Lithium bridge windows (`0xfc000000`, `0xfd000000`) | established |

   The PM base `0x0f80`, the GPIO base `0x0fc0` and the NS87307 power-management base `0x0fc8` are the values Linux's
   `setup.c` uses, so Linux repeats work the firmware has already done (Linux does it again without checking).
5. **Shadow and hand-off.** The 512 KiB flash is copied (`rep movsl`) to RAM at `0x80000`, the caches are re-enabled and a
   far jump goes to flash offset `0x7d800` in that copy (physical `0xfd800`), 32-bit flat code compiled from C. It
   loads its own descriptor tables, sets the stack to `0xeffff0`, checks the `SHDR` tag (post code `0xce` and a loop if it is wrong),
   expands the five sections ([firmware.md](firmware.md)) and calls the entry address from the header (an indirect call;
   the target being `0xf00000` is inferred from the header field). **Software expectation:** RAM at least up to 16 MiB works
   at this point, before any memory sizing the main module does.

## The main module

**Established unless marked (Ghidra decompilation and listing of the quoted routines; the module is about 340 KB and was
not read in full).**

1. **Board identification.** Board type is `(inb(0x0fb2) >> 2) & 0xf` and board revision `inb(0x0fc0) & 0x7f`. Linux reads
   the same two places (PIIX4 general-purpose input bit 18, shift 2, and the NS87307 GPIO data register, 7 bits), so
   the firmware and Linux agree on where they are. The firmware also uses the type (zero for the 320) to pick a delay while
   other processors start.
2. **Memory sizing.** The Cobalt revision byte at `0xc2000008` selects where the bank registers are read. The firmware
   first clears bit 0 of the Cobalt memory-controller register at `0xc6000000`, then reads sixteen bank registers at an
   8-byte stride from `0xc6000048` (from `0xc6000050` unless the revision is `0xa0` or `0xa8`, the "Cobalt Lite" values in
   [questions](../../questions/visws-firmware-open.md)). For each: bit 2 set marks the bank as absent or bad, otherwise bit 0
   set means populated, and bit 1 chooses 128 MiB (set) or 32 MiB (clear). The total is the sum (`1.0006@0xf02d60`; the same logic, with reordered instructions, in 1.1005 at
   `0x1102cc0`). The main module only reads the bank registers: the self-test module that ran before it wrote them, by probing the
   RAM ([below](#memory-controller-and-graphics-memory)). A separate RAM test then marks good and bad pages ("low 16 MB good",
   "low 32 MB good", "all 128 MB good" are its outcome strings). The reset values of the bank registers are still unknown.
3. **Firmware address map.** The firmware builds page tables (`setup_memory_map`; RAM is identity-mapped, the windows below are reached through cache-disabled aliases from `0xb0000000` up, not at their physical addresses: [processor state at the loader call](#processor-state-at-the-loader-call)) and maps these windows: Lithium A and B
   (`0xfc000000`, `0xfd000000`), the Cobalt processor, interrupt and memory blocks (`0xc2000000`, `0xc4000000`,
   `0xc6000000`), the retrace register (`0xca000000`) and the display back end (`0xd0000000`, 0x81 pages), the local APIC
   (`0xfee00000`), the flash (`0xfff80000`, 0x80 pages), and several small windows at `0xfe000000`, `0xff000000`,
   `0xff004000`, `0xff018000` and `0xff01c000` that this repository does not describe (unknown).
4. **Lithium set-up.** One routine writes `0xffffffff` to `+0x48` and `0x81f` to `+0x58` of both bridge windows, then does
   a read-modify-write on the five dwords `+0x60` to `+0x70` (mask `0xfffffbc1`, then bits set from a board-revision-
   and variable-dependent value), and finally reads the Lithium A identification dword and prints an error unless it
   equals `0x100210a9` (vendor `0x10a9`, device `0x1002`; 1.1005 drops the message). The bit meanings of `+0x48`, `+0x58` and
   the five dwords at `+0x60` to `+0x70` are unknown, but the choice of values is read: [below](#pci-bus-numbering-and-windows).
   The helpers that write bytes to `+0x44` and `+0x45` are traced in the same section.
5. **Graphics memory.** `gfxmem_alloc` (`1.0006@0xf04a70`, `1.1005@0x1104840`) chooses the graphics reservation and enters it
   as memory type `0x16` in the loader block; `cogfxmem` and `maxpmem` steer it. Read in full: [below](#memory-controller-and-graphics-memory).
6. **PCI resources.** The first reading missed the PCI code: the main module does walk PCI-to-PCI bridges and assigns their bus
   numbers and windows (`1.0006@0xf1fe70`, strings `assign_1_bus: ...`), and numbers the two Lithium bridges itself. See
   [below](#pci-bus-numbering-and-windows). Whether it assigns resources to endpoint devices for its own boot devices
   was not traced (the drivers were not read); the OS side assigns anyway (see PCI enumeration below).
7. **Cobalt interrupt controller identification.** One routine writes the interrupt controller's `+0xffc` word as
   `(old & 0xf0ffffff) | 0x04000000` (`1.0006@0xf04072`, same in 1.1005): bits 27 to 24 are set to 4 and the enable bit at 8 is
   left alone. Which field that is, is not stated anywhere (inferred: an identification number for the controller).

### Older releases and reset

**Established (1.0002, 1.0004 and 1.0005 compared with 1.0006 and 1.1005, [firmware.md](firmware.md#from-10002-to-10006)).** "PROM 1.2"
is 1.0002, the oldest release held. It asks something different of the machine from 1.1005, not less: it needs the Lithium `+0x40`
read-modify-write below. What differs, for an emulator that runs the older images or one that wants to know which of these accesses the contract needs:

- **Lithium `+0x40` (1.0002 and 1.0004 only).** The Lithium set-up routine reads and writes `+0x40` of both register pages:
  window A (`0xfc000000`) ends with the top byte `0x01` and bit 5 set, window B (`0xfd000000`) with the top byte `0` and bit 5 set
  (`(old & 0x00ffffdf) | 0x01000020` and `(old & 0x00ffffdf) | 0x20`). The page must hold those bits. 1.0005, 1.0006 and 1.1005 do not touch it.
- **Order and a table copy.** The store runs late in platform bring-up, after the device install list (`0x1113a02`) and the generation reads (`0x11003e0`), not at entry. The same branch first calls `0x11138a2` once, which runs `0x1113860(0x11c05bc)`: unless the stamp word at `0xff01c004` (read as `[window + 0x4004]` of the `0xff018000` mapping) is above `0x36ffd62f`, it copies a 256-dword table from the data module into the 4-page window mapped from physical `0xff018000`, skipping dwords equal to `0xdeadcafe`; 117 of the 256 dwords are written. What that block is (its page lies beside the stamp page `0xff01c000`) is unknown; it is not described in the audio page.
- **`0xff001000 = 0x4100` (1.0004 to 1.1005, including 1.1005): audio host-control initialisation.** When the Lithium generation is exactly 5 (the word at `0xff01c004`
  is `0x366c3dfb`, the stamp that a real machine's registry shows as "Serial I/O: 366c3dfb"), the entry routine stores `0x4100` as a 32-bit write at offset `0x1000` of the two-page window at `0xff000000`
  (`1.0004@0xf00250`, `1.1005@0x1100270`; the only access to that window in the main module). `0xff001000` is the Lithium audio engine's register page and the dword is its host-control register
  ([audio.md](../../devices/lithium/audio.md#1-where-the-engine-sits)). Bit 14 (`0x4000`) is the link-enable bit the NT audio driver writes last of its `0x8000`, `0`, `0x4000` codec-link sequence; bit 8 (`0x100`) is set by no
  driver read for that page (its meaning is unknown), and the upper half is written as 0. So the firmware enables the codec link at generation 5 and nothing more: it never writes the codec command and data
  registers (`+0x18`, `+0x1c`), never resets the codec, and starts no DMA. Established (single access read); the effect of bit 8 unknown. On other generations the write is not made (so the NT driver's own reset sequence is the only link set-up there).
  1.0002 neither maps the window nor writes it.
- **Processor identity.** From 1.0004 the firmware checks that all processors look alike (the report strings name the jumper
  setting, mixed processors and unequal L2 sizes); an emulator with several processors should give every one the same CPUID signature (stepping is ignored) and L2 size.
  The check (`1.0004@0xf010b0`) loops over four slots, reads the signature and feature words from the table at `0x1e06 + 20*i` and
  `0x1e0a + 20*i`, compares them with per-processor speed and L2 words, stores a flag word in extended CMOS bytes `0x98` to `0x9b` (ports `0x72`/`0x73`) and always
  returns 0: a mismatch is reported and recorded, never fatal (established for 1.0004; the 1.1005 routine was not compared). It does not read MSR `0x2a`. Speed comes from the MSR `0x2a`
  ratio field through a table that every release from 1.0002 has (`1.0002@0xf1d5f0`, `1.0004@0xf1e110`, `1.0005@0xf1e110`, `1.0006@0xf1e180`, `1.1005@0x11197f0`;
  1.0006 adds the 600 and 650 MHz rows and 1.1005 has two tables); a ratio missing from the table makes
  1.0002 to 1.0006 time the processor with `rdtsc` against the real-time clock's update-in-progress flag (register `0x0a` bit 7). A model
  that leaves MSR `0x2a` at zero gets the table's reading of code 0, 333 MHz, in the speed report; the speed line is only a report
  (inferred).
- **L2 control for slot 2 processors (1.0006 and 1.1005).** For signatures `0x672` to `0x67f` with platform id 2 in MSR `0x17`, the self-test
  module reads MSR `0x11e`, writes it with `(old & 0xff881e00) | 0x1001f`, executes `invd`, and writes the old value back
  (`1.0006:test+0x4041`). Older images skip this.
- **Everything else this page records at reset is the same in 1.0002 to 1.0006:** the boot block, the self-test memory-bank probe, the
  memory descriptor list and bank step, `gfxmem_alloc`, the display start-up and the frame buffer at `0xa00000`. 1.1005's differences
  are in [firmware.md](firmware.md#from-10006-to-11005).

## Memory controller and graphics memory

Registers of the Cobalt memory-controller block at `0xc6000000` as the two images use them. The block is not described by
the Linux code or the HAL beyond the error registers, so every meaning here comes from the firmware's use (inferred unless
marked) and the names are descriptive only.

| Offset | Access in the firmware | Use | Grade |
|---|---|---|---|
| `+0x00` bit 0 | self-test sets it (writes 1) before filling a block of RAM with ones and flushing the caches, clears it (writes 0) when the probe ends; the main module clears it before sizing | error-check (ECC) enable; the HAL sets it together with the Cobalt CPU block's ECC bit | the accesses established; the meaning inferred |
| `+0x08`, `+0x10` | read | the self-test's delay: it takes half of `+0x08` and waits for `+0x10` to fall to that value and rise through it, between probe writes | inferred (a free-running counter and a period) |
| `+0x18` | written 0 | cleared right after the check bit is set; after a failed read-back the test reads `+0x28` and `+0x30` (a failing address and a byte-lane mask, looked up in a table of 65 entries) | inferred |
| `+0x48 + 8*i` (Cobalt revisions `0xa0` and `0xa8`) or `+0x50 + 8*i` (all others), i = 0 to 15 | written by the self-test, read by the main module and the "RAM Bank Control Regs" report | bank control: bit 0 enabled, bit 1 128 MiB rather than 32 MiB, bit 2 absent or bad. The self-test stores 3, 2 or 0 | read side established; the write side inferred |

**Bank detection. Inferred (self-test code read as a listing, `1.0006:test+0x80a7`-`0x8300`; not run).** There is no SPD or
other DIMM EEPROM access in either image: a search for SMBus use turns up the clock-generator commands and nothing else, and the
word "SPD" is in neither. Detection is a write and read-back test per bank slot `i` (0 to 15; slot stride 128 MiB): at
`i * 128 MiB + 64 MiB` it writes four 32-byte patterns (`0x12345678`, `0x5a5a5a5a`, `0xc3c3c3c3`, `0x9abcdef0`) at 16 MiB steps and zero
words to `0x00fffffc`, waits on the counter pair between writes, then reads back. From the comparison it stores 3, 2 or 0 in the
bank register (slot 0 never gets 0); which outcome gives which value was not traced (unknown). It copies the sixteen values to
the standard CMOS bytes `0x40`-`0x4f` (ports `0x70`/`0x71`; the main module's "Slot Group A to D" report reads them and counts `3` as
128 MB) and a bit mask of the slots whose value is 2 to the extended-bank bytes written as `0xb4`-`0xb7` (ports `0x72`/`0x73`).
Reset values of the bank registers are unknown (the code writes before it reads).

**Memory descriptors. Established (`1.0006@0xf02e30`, `0xf01ee0`; `1.1005@0x1102d90`, `0x1101e30`).** From the bank array the
firmware makes descriptors (type, base page, page count): the first 16 MiB (1.1005: 32 MiB) type 2, the rest of memory type 5, plus a
fixed list of low-memory descriptors (table in [firmware.md](firmware.md#from-10006-to-11005)); `maxpmem` (a number with `K`,
`M` or `G` suffix) caps the total, and 1.1005 refuses a cap below 128 MiB. MTRRs are then set from the same array
(`1.0006@0xf03100`: MTRRs are switched off, `0x200`-`0x20f` cleared, then up to four variable ranges are set, one per 512 MiB of
address space, sized from the banks present, type 6 (write-back) when coherent DMA is on and type 0 (uncacheable) when it is off,
and MTRRs are switched on again).

**Graphics memory. Established for the algorithm (`gfxmem_alloc`, decompiled and read in full for both images; the result was
not run).**

1. Inputs: total RAM in bytes; the variable `cogfxmem`. Below 64 MiB the function fails; between 64 and 128 MiB the variable is ignored
   and the defaults are used; from 128 MiB `cogfxmem` is parsed.
2. The variable is a comma-separated list of decimal numbers, `total,s0,s1,...` (up to twelve sizes after the total), in 4 KiB pages
   (the same form the HAL's miniport writes, [nt-hal.md](nt-hal.md#memory-banks-and-the-graphics-split)). If the sizes
   do not add up to `total`, the whole variable is discarded. Defaults: entry 1 `0x100` pages and entry 2 `0x500` pages.
3. Entry 1 is clamped to `0x100`-`0x1000` pages (1.1005: `0xc00`) and rounded down to a multiple of `0x100`; entry 2 is raised to at least `0x400`;
   a flat panel (panel id 3, 4 or 5, see [the display set-up](https://github.com/jamesbraid/cobalt/blob/main/devices/cobalt-graphics/prom-init.md))
   raises them to at least `0x400` and `0x800`. Every entry is then rounded up to a multiple of `0x400` pages (4 MiB), so the
   defaults end up 4 MiB and 8 MiB. If the RAM left over would be under 64 MiB the largest later entries are cut until it is not (the install
   guide's "largest value is installed memory minus 64 MB"). With fewer entries than the number of 32 MiB units in RAM the
   entries are merged by slot masks (details in the code, not reproduced).
4. Placement: each entry is carved, in order, from descriptors of type 2 or 5 whose base is at or above 16 MiB, as type `0x16`
   descriptors that start on a 4 MiB boundary. The next piece's search starts at the following 32 MiB boundary, and RAM above
   384 MiB makes the first start 32 MiB. So the carve-out is scattered in 32 MiB steps through low memory, not placed at the
   top of RAM. Agreement: a published registry export of a real 512 MiB machine lists reserved ranges at the starts of the
   32 MiB blocks `0x2000000`, `0x4000000`, `0x6000000`, `0x8000000`, `0xa000000`, `0xc000000`, `0xe000000`, and `0x20000000`, `0x22000000` of 4, 12,
   12, 8, 4, 4, 4, 4 and 4 MiB ([board data](https://github.com/jamesbraid/cobalt/blob/main/devices/cobalt-graphics/board-data.md)).
5. The HAL turns those type `0x16` descriptors into the miniport's bank list (section 6 of Boot into NT below), and
   the miniport's rule of at least two banks matches the two entries (inferred).

Which numbers the control panel's profiles write, and the factory default of `cogfxmem` (none was found in the image's
variable defaults), are unknown.

## Display back end start-up

The firmware programs the display back end at `0xd0000000` itself: the text console and the boot screens. The reading, with every
register write in order and the mode table, is in [the Cobalt repository's page](https://github.com/jamesbraid/cobalt/blob/main/devices/cobalt-graphics/prom-init.md).
Two facts for this page: the self-test checks that the ID register at `+0x14` reads `0x666` (a triple in its table,
`1.0006:test+0x96f7`, `1.1005:test+0x9775`; the main module has no such check), and the main module keeps the low nibble of `+0x00`
(`1.0006@0xf00200`) as the display engine's revision, the "Display Engine: 002" of a real machine's registry. The coherent-DMA
default does not come from it: `1.0006@0xf00210` classifies the word at `0xff01c004` (`0x35c0194c` is 2, `0x35f7357f` is 3, above that 4, else -2) and
coherent DMA is on when the result exceeds 2, compared unsigned (`cmp $3; jae` at `1.0006@0xf00269`), so the `-2` an unrecognised stamp gives also turns it on, unless `coherentdma` begins with `n` (`1.0006@0xf00250`).

## PCI bus numbering and windows

**Windows the main module maps (`1.0006@0xf03980`, `1.1005@0x1103730`; physical, 4 KiB pages). Established.**

| Window | Size | Role |
|---|---|---|
| `0xf0000000` | 64 MiB | PCI memory window of Lithium A (`1.0006@0xf1f6f0` pairs it with A) |
| `0xf4000000` | 64 MiB | PCI memory window of Lithium B; a real machine's registry export gives the first PCI bus ports from `0x10` and memory translated to `0xf4000000`, the second ports `0x8000`-`0xffff` and `0xf0000000`, which fits B as the first bus |
| `0xfc000000`, `0xfd000000` | 4 KiB | the Lithium A and B register pages (identification at `+0x00`) |
| `0xfc800000`, `0xfd800000` | 8 MiB | one window per bridge, A then B; role not traced |
| `0xf8000000`, `0xf9000000`, `0xfa000000`, `0xfb000000` | 16 MiB each | mapped; purpose not traced |
| `0xd0000000` | 0x81 pages | display back end |
| `0xc2000000`, `0xc4000000`, `0xc6000000`, `0xca000000` | 1 page each | Cobalt CPU block, interrupt controller, memory controller, retrace register |
| `0xff004000` (3 pages), `0xff018000` (4), `0xff01c000` (1), `0xfe000000` (1) | | Lithium-side blocks, not described elsewhere; the word at `0xff01c004` selects the Lithium generation |
| `0xff000000` | 2 pages | Lithium audio register block (the page at `+0x1000` is the engine's host control); from 1.0004 (not 1.0002) the entry routine stores `0x4100` at `+0x1000` when the Lithium generation is 5 ([above](#older-releases-and-reset)) |
| `0x00fff000` | 1 page | physical address just under 16 MiB (ordinary RAM range, not part of the audio engine's pages `0xff001000`, `0xff00f000`, `0xff010000`), mapped from 1.0004; its first dword is read by `1.0006@0xf17f40` and, in 1.1005, returned by `0x1113e28` to the idle loop that drains devices before the handoff (`0x1113e3b`) and passed to `0x11197aa`; role unknown |

**Bus numbers. Established (`1.0006@0xf1f6f0`-`0xf1f8f0` and the helpers `0xf20700`, `0xf20730`, `0xf20f90`, `0xf20fa0`; the same
code is in 1.1005 at `0x111a8ea`).** Two helpers write a byte to `+0x44` (primary bus number) and `+0x45` (subordinate bus number) of a
Lithium window, selected 0 for A and 1 for B. The sequence: A is first given primary `0xff`; a counter that starts at `-1` is
incremented, so **Lithium B gets bus 0** (subordinate `0xfe` while its subtree is scanned, then the highest bus number allocated behind
it), then the counter is incremented again and **Lithium A gets the next number** (bus 1 when nothing sits behind B), subordinate
`0xff`. The firmware's root bridge objects carry type 1 for B and 0 for A, memory window bases `0xf4000000` and `0xf0000000`, and I/O bases
`0x1000` (B) and `0x9000` (A). The PIIX4 at device 4 on bus 0 is consistent
with B being bus 0, which answers the earlier question of which bridge is bus 0.

**Configuration access. Established.** Three routes appear: the boot block and the self-test module go through Lithium B's
window, an address word at `+0xf8` and a data word at `+0xfc` (the address word is `0x80000000 | bus << 16 | device << 11 |
function << 8 | register`; example `0xfd0000f8 = 0x80002004`, `0xfd0000fc = 9` writes the PIIX4's command register); the
main module's generic functions (`1.0006@0xf1f340`-`0xf1f6e6`) use ports `0xcf8`/`0xcfc`; and the main module sends the stop-grant special cycle
the way Linux does (`0xfd0000f8 = 0x8000ff00`, `0xfd0000fc = 0x120002`, `1.0006@0xf18920`). Whether ports `0xcf8`/`0xcfc` reach the same
configuration cycles as the window for devices behind the bridges is not stated in the code (unknown).

**Bridge assignment. Established (`1.0006@0xf1fe70`, `0xf1fde0`, `0xf20ed0`).** The firmware scans devices 0 to 31 and functions
0 to 7 on a bus for class `0x0604` header-type-1 bridges, recursively, then assigns the bridges' memory and I/O base and limit
registers from the root window downwards (largest alignment first, memory alignment at least 1 MiB, I/O at least 4 KiB) and
sets bridge control bits (command register `| 5`, `| 6` when a memory window is open). This is the code the release notes call
"PCI bridge support" (1.1002); it is first in 1.0005 (`1.0005@0xf1fdf0`; 1.0002 and 1.0004 carry no bridge-assignment code or strings, so there the
firmware leaves bridge windows to the OS, inferred) and is the same in 1.0006 and 1.1005. It prints "This bridge supports 32 bit IO" or "only supports 16 bit
IO" when a debug flag is set (the strings are removed in 1.1005).

**Lithium set-up. Established for the writes (`1.0006@0xf20620`, `1.1005@0x111b496`; same values; 1.0005 is the same as 1.0006 at `0xf205a0`, and 1.0002 and 1.0004 add the `+0x40` writes [above](#older-releases-and-reset)).** For both bridge windows:
`+0x48 = 0xffffffff`, `+0x58 = 0x81f`, and for each of the five dwords `+0x60`, `+0x64`, `+0x68`, `+0x6c`, `+0x70`:
`new = (old & 0xfffffbc1) | 0x400 | 0x20c2`, where `0x400` is applied unless `coherentdma` begins with `n`, and `0x20c2` only on Lithium
generation 5 or later and unless `streambuffer` begins with `n`. The generation (`1.0006@0xf00190`) is 1 when the byte at B `+0x08` is
zero and otherwise 2, 3, 4 or 5 when the word at `0xff01c004` equals `0x35c0194c`, `0x35f7357f`, `0x363e4470` or `0x366c3dfb`, 6 when it is
above the last and -2 (`0xfffffffe`) for any other value. The callers compare the result unsigned (`cmp $5; jb` at `1.0006@0xf20672`), so an unrecognised stamp counts as a generation of 5 or later and gets the `0x20c2` bits. Read as Unix times the thresholds are 1998-07-30, 1998-09-10, 1998-11-02 and
1998-12-07; the same word appears in the real machine's registry as "Serial I/O: 366c3dfb", the last value, so the word is an
identification stamp of another ASIC on the machine and the generation reflects its release (inferred). The meanings
of the bits (`0x400` coherent DMA, `0x20c2` stream buffering) are named only by the two variables; the five dwords are likely
per-DMA-channel controls (inferred, no register source). Before the OS, the firmware also disables the PIIX4's four PCI interrupt
routing registers (configuration `0x80002000`, register `0x60`, value `0x80808080`) and clears the edge/level controls (`0x4d0 = 0`,
`0x4d1 = 6`) (`1.0006@0xf205f0`).

## Boot into NT

1. **Files and names. Established (guide, Recovery CD-1).** Boot files are `arcldr.exe` (the loader; "ARCx86 OS Loader
   V4.0", SGI build of 1999-01-22; in a directory such as `\os\winnt40\`) and the HAL, copied to the system partition
   as `hal.dll`. For a one- or two-processor NT the HAL is `halbrgup.dll` or `halborg.dll` renamed; the installer lists
   `halborg.dll` and `arcsetup.exe` as added files and removes the stock `hal486c`, `halapic`, `halmca`, `ntdetect.com`
   and `setupldr.bin`. So NT is started by the ARC loader path used on MIPS and Alpha NT, without `ntldr`,
   `boot.ini` or `ntdetect`. Which HAL file, UP or MP, setup copies as `hal.dll` is not recorded (neither name occurs in
   the standard text-mode setup file; the SGI setup program does the copy).
2. **Loader services. Software expectation.** The loader calls firmware vectors for disk and file access (its strings
   carry SCSI read-capacity and sense decoding, a Hitachi CD-ROM drive fix, El Torito CD booting, NTFS, hibernation
   file handling, a TFTP and IPsec network path), and reads these environment variables from the firmware:
   `consoleout`, `consolein`, `systempartition`, `x86systempartition`, `osloader`, `osloadpartition`, `osloadfilename`,
   `osloadoptions`. Its partition names are the ARC forms `multi(0)disk(0)fdisk(0)partition(0)`, the same with
   `eisa(0)`, and `scsi()` for SCSI after firmware 1.1002.
   **The call table. Established (loader code read at file offset `0x790`; firmware code read at `0xf42240` and the
   tables it copies).** Like MIPS and Alpha ARC machines, the firmware keeps an ARC *system parameter block* at physical
   `0x1000`: the signature `ARCS`, length `0x48`, version 1, revision 10, then pointers (restart block, debug block and the
   general-exception and TLB-miss vectors are zero or unused), the firmware vector length `0x8c` and pointer `0x1200`, the
   private vector length `0x3c` and pointer `0x1300`, and an adapter count of zero. At start-up `arcldr.exe` reads those
   fields from `0x100c` to `0x1028` into its own globals; it reaches every firmware service through the vector, and
   prints "Unimplemented Firmware Vector called (FID n)" for an empty slot. The firmware copies its static tables to
   `0x1200` and `0x1300` when the hand-off is prepared. The firmware vector has 35 four-byte entries in the standard ARC
   order: 0 Load, 1 Invoke, 2 Execute, 3 Halt, 4 PowerDown, 5 Restart, 6 Reboot, 7 EnterInteractiveMode, 8 (reserved, points
   at data), 9 GetPeer, 10 GetChild, 11 GetParent, 12 GetConfigurationData, 13 AddChild, 14 DeleteComponent, 15 GetComponent,
   16 SaveConfiguration, 17 GetSystemId, 18 GetMemoryDescriptor, 19 (reserved, zero), 20 GetTime, 21 GetRelativeTime, 22
   GetDirectoryEntry, 23 Open, 24 Close, 25 Read, 26 GetReadStatus, 27 Write, 28 Seek, 29 Mount, 30 GetEnvironmentVariable, 31
   SetEnvironmentVariable, 32 GetFileInformation, 33 SetFileInformation, 34 FlushAllCaches. The names are the ARC
   specification's for those positions (the table has no firmware symbols; entries 0 to 34 are non-null except 19); the last two ARC entries
   (test Unicode character, display status) are not in this version's table. The private vector has 15 entries (one is
   null) whose purpose was not read.
   **Which vectors the loaders call. Established (call sites in `arcldr.exe` and `arcsetup.exe`, NT 4.0 install CD).** Every
   call goes through the vector pointer the loader copied from the block at start-up (an indirect call through the entry
   offset, four bytes per index). Indices used, with the number of call sites in `arcldr.exe` / `arcsetup.exe`: GetPeer (9) 2 / 2,
   GetChild (10) 3 / 3, GetConfigurationData (12) 2 / 2, GetMemoryDescriptor (18) 4 / 4, GetTime (20) 1 / 1,
   GetRelativeTime (21) 14 / 8, Open (23) 8 / 8, Close (24) 5 / 14, Read (25) 16 / 11, GetReadStatus (26) 4 / 3, Write (27) 32 / 16,
   Seek (28) 7 / 10, GetEnvironmentVariable (30) 1 / 1; `arcsetup.exe` also calls Restart (5) 3 times. So the firmware must
   implement those fourteen; Load, Invoke, Execute, Halt, PowerDown, Reboot, EnterInteractiveMode, the tree editing calls
   (AddChild, DeleteComponent, GetComponent, SaveConfiguration), GetSystemId, GetDirectoryEntry, Mount,
   SetEnvironmentVariable, Get/SetFileInformation and FlushAllCaches have no direct call site in either loader (a count of
   direct sites; the loaders' file-system code reaches the files through Open, Read, Seek and Write only). The SPB fields read are the
   ones at `0x1004` to `0x1028`, saved to the loader's own copy; the same loader reads nothing from the private vector (no
   use of its pointer was found). Windows 2000 RTM and SP4 `arcldr.exe` ("ARCx86 OS Loader V5.00") call the same thirteen
   (GetMemoryDescriptor eight sites, Write 45); `arcsetup.exe` there adds **GetDisplayStatus (vector index 36, offset `0x90`)**, guarded by
   a test of the block's version (above 1, or 1 with revision at least 2) and of the vector length (above `0x90`), and shows
   "Your system's PROM (firmware) is below the required revision level" when a check against the text-mode setup file's
   PROM version string (`1000` for the one machine type) fails; the check compares four bytes at offset `0x4c` of the data attached to a firmware tree node (at least `0x80` bytes long)
   with that string (what the bytes are, which node, and the direction of the test were not traced; the compare is inferred to be a firmware-revision test from the message). PROM 1.0006's block (version 1,
   revision 10, vector length `0x8c`) passes the version test and fails the length test, so it has no GetDisplayStatus
   to call and Windows 2000 setup skips that call there; whether it passes the PROM check was not determined.
3. **What `ARCINFO` prints. Established (`DumpArcInfo`, `0x80014430`).** With the `ARCINFO` boot option the HAL writes, through the
   debug-port print routine (so it goes to the kernel debugger's port, not the screen), a block headed `ArcInfo:` with the
   ARC boot device name, the ARC HAL device name, the NT boot and HAL path names and the OS load options, then "Dump arc tree
   info at 0x..." followed by the whole configuration tree from the root: for each node a banner with two ids, its child and sibling
   pointers, then class (as a name and a number), type, version and revision, key, affinity mask, configuration data length,
   identifier length and the identifier string. "LoaderBlock contained no arc root" if the loader gave none.
4. **The ARC configuration tree. Established (HAL read, `DumpArcInfo`, `HalpGrabArcRevInfo`).** The HAL requires the NT loader
   block to carry an ARC root with a standard component tree (the HAL prints "LoaderBlock contained no arc root" if it
   does not). It looks up the system component, finds the child "SGI REV INFO", and under it the children "SYS TYPE"
   (a byte: 0 for the 320, 1 for the 540, inferred from the Linux board-type values and the HAL's branches) and
   "BOARD REV" (a byte, see below). It copies the system identifier from the tree and rewrites it into a product name that
   begins "Silicon Graphics", with a `-` in the identifier replaced by a blank and anything from a `_` on dropped. The
   identifier string in 1.0006 is `SGI-000_ARCx86`, next to the strings that name the loader variables (inferred to be the
   system component's identifier: the HAL's rewrite rules, dash to blank and cut at the underscore, fit it; the rewrite then
   gives a product name from the board type, not from this string alone).
   **Text-mode setup's side. Established (`txtsetup.sif` on the SGI NT 4.0 install CDs).** Setup maps the system identifier string to a
   HAL: `SGI-320_ARCx86` and `SGI-540_ARCx86` are the uniprocessor machine types (`sgiborg_up`, which copies `halbrgup.dll` to
   `hal.dll`), and the same strings with `_mp` appended are the multiprocessor types (`sgiborg_mp`, which copies `halborg.dll`).
   So the firmware's system identifier carries the model number and a `_mp` suffix when more than one processor is present;
   the held 1.0006 image's `SGI-000_ARCx86` is then probably a template, not the string a running machine reports (inferred; a 1999 user report of
   `SGI_ARCx86_mp` is the same pattern with the number missing). Setup's HAL-load step names `arcsetup.exe` in place of the
   stock `ntdetect.com`, with the setup file's own comment that this is a placeholder, and the stock `hal486c`, `halapic`,
   `halmca` and `ntdetect` are commented out.
   The HAL also carries code and strings to add MultiFunctionAdapter, Flash, Audio, Video, Raid, SCSI, Keyboard, Mouse and
   processor nodes to the NT registry itself (`HalpAddMultiFunctionNode`, `HalpFixupRegistry`); the 1.0002 notes show
   the firmware creates the floating-point nodes. **Firmware side. Established (strings; the 1.0006 data module).** The
   firmware builds the tree itself: the nodes "SGI REV INFO", "SYS TYPE" and "BOARD REV", a configuration key `CPUMask`, processor
   components with FPU children (`borg_cpu_install`), `video()`, `serial(0)`, `serial(1)`, `console`, `keyboard()`
   and `pointer()`, and the memory descriptor list (`alloc_memdesc`). Component classes, keys and types were not decoded.
5. **Board revision byte. Inferred.** The HAL treats `BOARD REV` below 6 as one hardware generation of the 320, 6 to 11
   as the second and 12 or above as the third; the 540 with revision 0 is a special case and any other 540 revision uses
   the third generation's tables. The thresholds are the same as the ones the Linux port applies to the raw 7-bit value
   it reads from the NS87307 general-purpose I/O port (below 6 revision 4, below 12 revision 5, otherwise 6), so the byte in
   the tree is the raw value. That equality is the only evidence.
6. **Memory descriptors and the graphics banks. Established (HAL read).** The loader block's memory descriptor list
   carries the graphics memory, and the HAL turns it into what the graphics driver reads:
   - `HalpSpliceGfxMemory` walks the list and prints "N MB Memory [G MB Graphics, M MB NT]": descriptors of type 3 (bad
     memory) are ignored, type 22 (`0x16`, a type outside the stock NT set) counts as graphics, type 6 (firmware
     permanent) counts toward the total only, and everything else is NT memory. Pages are 4 KiB.
   - The display start-up picks the first type-`0x16` descriptor big enough for the boot-time frame buffer (the
     visible area rounded up to 512 by 128 tiles of 16 pages each) as the frame buffer base, and keeps up to 32
     type-`0x16` descriptors as banks. If there is none it prints "You need an updated PROM!", carves 16 MiB (4,096 pages)
     off the end of a free or firmware-temporary descriptor ([nt-hal.md](nt-hal.md#memory-banks-and-the-graphics-split)), and carries on.
   - `HalpAddGbeDisplayToRegistry` publishes them under `SGICtrl\Memory` in the NT control tree as `GraphicsMemory` and
     `GraphicsMemorySize` (base and byte size of the first bank), `NumberOfBanks` and `BankAddr00` to `BankAddr31` and
     `BankSize00` to `BankSize31` (byte address and page count of each); that is the list `sgcomp.sys` reads (see
     [devices/cobalt-graphics/nt-software.md](../../devices/cobalt-graphics/nt-software.md)). Banks must start on a
     4 MiB boundary and be a multiple of 4 MiB (1,024 pages) or the HAL warns "Update the prom for aligned graphics
     memory" and does not remap them.
   So the firmware reserves the graphics memory as one or more type-`0x16` descriptors, aligned to 4 MiB; how it
   chooses the split between NT and graphics is unknown (Linux hard-codes 8 MB by default, see below).
7. **Memory map facts the HAL maps (physical).** The first 4 KiB page of memory (the BIOS data area is touched there: the
   warm-reset vector at `0x467` and the reset flag at `0x472` are written, with CMOS register `0x0f` set to `0x0a` or
   `0x00`); the processor table page at `0x1000` with the table at `+0xe00` (below); the Cobalt CPU register block
   `0xc2000000`; the Cobalt APIC `0xc4000000`; the Cobalt memory controller registers `0xc6000000`; the Lithium
   bridges A at `0xfc000000` and B at `0xfd000000` (one 4 KiB window each); the local APIC at `0xfee00000`; the flash at
   `0xfff80000`. The Cobalt blocks are described in [nt-hal.md](nt-hal.md).
8. **Processor table at physical `0x1e00`. Established (HAL and Linux read; firmware writer read in the main module at
   `0xf03f10`-`0xf0421f`, Ghidra for the entry builder).** A 16-bit processor count, followed by that
   many 20-byte entries. Both the NT HAL and the Linux 2.6 port read it from the same place (Linux: the count at `0x1e00`,
   the table two bytes on, at most four processors). If the count is zero the HAL falls back to a built-in table. The table
   is the only processor description: there is no MP floating pointer and no ACPI. The Linux 2.2 and 2.4 ports instead
   hard-code two processors, ids 0 and 1, with integrated local APICs. The 28 July 1999 SGI patch source reads this table
   instead, but the held SGI image is a uniprocessor build and uses neither ([Linux loader handoff](#linux-loader-handoff)).
   **Who writes it: the firmware, from every running processor.** The boot processor stores the count 1 at `0x1e00`,
   writes its own entry, copies a 0x210-byte start-up stub to physical `0x50000`, clears the local APIC error status, and sends a startup
   IPI (vector `0x50`) to all other processors, waits (longer on a 540, board type non-zero: `0xe00000` against `0x180000` loop
   counts), then sends an INIT assert and de-assert to the same set (parking them again for the OS). Each other
   processor runs the stub from `0x50000`: it enables its APIC, increments the count at `0x1e00`, writes its entry at
   `0x1e02 + 20 * (count - 1)`, signals through mailbox bytes at `0x504`, `0x505` and `0x506` (physical, below the table) and
   halts. The boot processor's own flag has bit 1 set. An entry is: byte 0 type 0; byte 1 the local APIC id (bits 27:24 of
   the APIC id register, masked with `0xf`); byte 2 the APIC version byte; byte 3 flags (bit 0 enabled, bit 1 boot processor);
   dwords at +4 and +8 the `cpuid(1)` `EAX` and `EDX`; dwords at +12 and +16 the `cpuid(2)` `EAX` and `EDX`. So the
   first twelve bytes are the Intel MP processor entry (type, id, version, flags, signature, feature flags) and the last
   eight are the `cpuid` cache and TLB descriptor registers where the MP layout has reserved bytes. A nonzero APIC version in the first entry tells the HAL to send
   startup interrupts as well as INIT. The firmware itself reads the same table when it builds the ARC processor nodes
   (`0xf02030`, `0xf02140`). One more write during start-up: a read-modify-write of the dword at Cobalt APIC `+0xffc` that sets
   bits 27:24 to 4; the meaning is unknown.
9. **Processor start convention. Established (HAL read; standard MP).** The bootstrap processor writes a real-mode
   stub below 1 MiB, points the warm-reset vector at it, sets CMOS shutdown byte `0x0a`, sends INIT assert and
   deassert through its local APIC, and, if the APIC version is nonzero, two startup IPIs; then waits for the other
   processor to report. The Linux port uses the same warm-reset vector method.

## Boot into Linux

1. **Loader. Observed.** SGI's Linux for the workstations was started from the firmware as an ARC program: the
   firmware boot entry's `OSLoader` is `larc.exe` or `arclx.exe` on a FAT floppy or partition, `OSLoadFilename` names
   the kernel image (`/la2210.vw` for a 2.2.10 kernel built for the workstation), `OSLoadPartition` the ARC path
   (`multi(0)disk(0)fdisk(0)partition(1)`), and `OSLoadOptions` the kernel command line (`root=/dev/fd0 load_ramdisk=1`).
   Reported by users installing Red Hat 6.0 on a 320 and a 540 in 1999 and 2000; `arclx.exe` and a second loader are held, `larc.exe` is not, see [Linux loader handoff](#linux-loader-handoff).
   SGI's later Linux releases were unpacked and checked: ProPack 1.3 Visual Workstation Edition and Visual Workstation
   Environment 3.0 (README updated 2000-12-19) name the 230, 330 and 550 (PC-BIOS workstations) only, install through a
   LILO-based installer, and ship kernels 2.2.15, 2.2.16 and 2.3.99 whose configurations read leave the Visual Workstation
   option off. No `larc.exe`, `arclx.exe` or `la2210.vw` turned up in the disc file listings, a byte search of the images,
   or the extracted kernel and boot-disk packages. The kernel source package of 2.2.16 carries the Visual Workstation
   platform code (read: board type and revision, GPIO enable, two fixed processors, Lithium sanity check bypass, as in the
   history tree's 2.2 port); the 2.3.99 package carries the same files and was not read. The loaders and their `boot_params`
   handoff are in [Linux loader handoff](#linux-loader-handoff).
2. **Kernel entry state. Established (Linux source).** The kernel reads the standard `boot_params` block and requires the
   loader to have set the memory size field `alt_mem_k` (boot-block offset `0x1e0`, a byte count in the held 2.6.0-test2 build); if it is zero the kernel prints "Bootloader didn't set memory
   size" and assumes 128 MB. It does not use E820 from the loader: the platform code builds the memory map itself, as
   conventional memory below 640 KB, RAM from 1 MB up to the top of memory minus the graphics buffer, and the
   graphics buffer, at the top of memory and 8 MB by default (the size is a boot parameter, trimmed to whole megabytes),
   as a reserved region. The Linux port's boot-time probing is only the PIIX4 board-type bits, the NS87307 GPIO
   revision, the two Lithium device and vendor words (a warning is printed if they do not read as SGI's Lithium),
   and the Cobalt revision and APIC id registers. These points are the 2.6 port; the 2.2 and 2.4 trees differ, see
   [Linux loader handoff](#linux-loader-handoff).
3. **Tables the kernel does not get.** No MP table, no E820, no ACPI, no PnP BIOS: established for Linux 2.6 (the
   platform replaces `find_smp_config`, `get_smp_config` and `memory_setup`).
4. **Interrupt set-up the kernel assumes already done.** None: the kernel unmasks the Lithium PCI interrupt-enable
   registers (`+0x46`, all eight bits on both bridges) and enables the Cobalt APIC itself by setting bit 8 of its ID
   register without changing the id ([nt-hal.md](nt-hal.md) for the register map; Linux page for the IRQ table).

## Linux loader handoff

Scope. Grades are established (read from the bytes or the source), inferred, or unknown. Held:

- arcboot, the 21 July 1999 loader source (`linux-visws-sf-arcboot-21jul99.tar.gz`, sha256 `9dd9744f2b3d`) and a build of it, `linux-visws-sf-arclx.exe` (`0602594856d5`, PE link time 21 July 1999). The only licence text in the tarball is `COPYING`, the GNU GPL version 2; the source files carry an SGI copyright line and no licence notice, and `io.c` says it derives from e2fsprogs.
- A second loader, `arclx2-arc-linux-loader.exe.gz` (`ab7305f3f8ea`; unpacks to 8,832 bytes, `c7008e1eb249`; PE link time 3 December 2002; banner "ARC Linux loader 200G2"). No source and no licence file.
- SGI's 2.2.10 kernel `linux-visws-sf-la2210.vw` (`2084e3a5c4a6`; version string "#2 Wed Jul 28 09:13:09 PDT 1999") with its `.config` (`8cc09f787faa`), and the 15 July and 28 July 1999 patches against mainline 2.2.10 (`3b159076019f`, `8091710f7da4`).
- `boor-vmlinux-vws.gz` (`2cf6ee94a96c`), which despite the name is a plain uncompressed ELF. It reports itself as Linux 2.6.0-test2, built 26 September 2003.

Mainline Linux 2.2.10 (`88e12acf949f`) and 2.4.0 (`13a80dffb749`) are the reference for what a visws-capable kernel expects. "2.2" and "2.4" below mean those trees; "patched" means 2.2.10 with either July patch applied (for every file cited as patched the cited lines are the same in both patches, except `smp.c`). Source is cited as `file:line`. Binaries are cited by link address; for the two PE loaders the file offset is the address minus `0x400c00`.

### 1. Firmware calls and the load path

- **How the loaders reach the firmware. Established.** Each call reads the pointer at `0x1020` in the system parameter block at `0x1000` and calls `slot * 4` from it (`arclib/spb.h:16-54`, `98-99`; `arclib/arc.c`). The firmware page puts that vector at `0x1200` and says its length is `0x8c`, 35 entries, slots 0 to 34, and that slots 35 and 36 are absent. The loader's structure has 37 slots, which is why the two counts differ: neither loader calls slot 35 or 36, and every slot they do call is inside the firmware's 35.
- **Calls. Established.** Both binaries have a wrapper for each of the 35 non-reserved slots (slots 8 and 19 are reserved in `spb.h`). Direct calls to the wrappers, counted in the disassembly:

  | Slot | Offset in vector | Name | arcboot source | `arclx.exe` calls | `arclx2` calls |
  |---|---|---|---|---|---|
  | 5 | `0x14` | Restart | `arclx.c:349` | 1 | 1 |
  | 7 | `0x1c` | EnterInteractiveMode | `misc.c:37` | 1 | 1 |
  | 18 | `0x48` | GetMemoryDescriptor | `arclx.c:45`, `72` | 1 (one loop) | 2 (`0x4011f2` in the loop, `0x40163f` in `_start`, result unused) |
  | 23 | `0x5c` | Open | `io.c:84`, `299` | 2 | 1 |
  | 24 | `0x60` | Close | `io.c:113` | 1 | 0 |
  | 25 | `0x64` | Read | `io.c:181`, `317`, `stdio.c:51` | 3 | 2 |
  | 27 | `0x6c` | Write | `stdio.c:25`, `98` | 2 | 2 |
  | 28 | `0x70` | Seek | `io.c:162`, `312` | 2 | 1 |

  That is 13 call sites over 8 slots in `arclx.exe` and 10 over 7 in `arclx2`. The source's write path in `io.c:213` is inside `#ifdef ARC_IO_ALLOW_WRITE` (`io.c:9` leaves it off), so it is not linked. The other 29 slots (30 for `arclx2`) are never called, two of them reserved.
- **Arguments. Established (source).** `_start(argc, argv, envp)` reads `OSLoadPartition`, `OSLoadFilename` and `OSLoadOptions` (and `LoadIdentifier`) from `name=value` arguments (`arclx.c:83-124`, `320-345`). `envp` is unused. A file name without a leading `/` that contains one is split into partition and file (`arclx.c:109-122`). The second loader prints the same four names and the same two "Invalid load" errors.
- **arcboot open path. Established (source; the binary has the same strings).** `file_open` first tries the partition as an ext2 volume through an ARC-backed I/O manager (`io.c:325-338`). If that fails it opens the partition name followed by the file name without its leading `/`, so `multi(0)disk(0)fdisk(0)partition(1)` and `/la2210.vw` give `multi(0)disk(0)fdisk(0)partition(1)la2210.vw` (`io.c:287-303`). It then seeks and reads through `arc_seek_read` (`io.c:305-321`). The messages `ARC opening %s` and `ARC reading %u bytes at offset %u` are printed at `io.c:298` and `316` and are in `arclx.exe` at file offsets `0x8003` and `0x8040`.
- **Reported transcripts. Inferred.** A 1999 Usenet report (`A7C09CFCAF83D2119C5000104B416CCF091C7D@theta.holmes.nl`, 1999-09-23) shows `OSLoadPartition` `multi(0)disk(0)fdisk(0)partition(1)`, `OSLoadFilename` `/la2210.vw`, then `ARC opening multi(0)disk(0)fdisk(0)partition(1)la2210.vw` and `ARC reading 52 bytes at offset 0`, with later reads that did not finish. A 2000 report of the same install names the partition `Floppy1` (`8csntq$vku$1@nnrp1.deja.com`, 2000-04-10). The strings match this `arclx.exe`, so the transcript is inferred to come from this build or a build of the same source; a sibling loader could print the same text, and `arclx2` does not (it has neither string).
- **ELF loading, arcboot. Established.** `LoadKernel` reads 52 bytes at offset 0 (`arclx.c:285`), requires ELF32, little-endian, `ET_EXEC`, and `EM_386` or `EM_486` (`arclx.c:287-306`), and reads the program headers at `e_phoff`. Each `PT_LOAD` segment is read to `p_vaddr - 0xc0000000`, and the part of its memory size past the file bytes is zeroed (`arclx.c:147-162`). The allocator leaves `0x100000` to `0x2fffff` alone (`arclx.c:35-36`, `62-66`).
- **ELF loading, `arclx2`. Established.** Open is the function at `0x401120` (it builds the partition-plus-file path as above and calls Open at `0x40108a`); seek-and-read is `0x401138`. `LoadKernel` is `0x4014cc`: its 52-byte read at offset 0 is the call at `0x4014e5`, the checks that follow accept `EM_386` only (`0x401579`), and `LoadProgramSegments` at `0x401380` loads and zero-fills the segments the same way. The binary contains no ext2 code, no Close call, and neither `ARC opening` nor `ARC reading`. `0x401dc4` is `printf`; it forwards to `0x401c24`.

### 2. Handoff, arcboot build (`arclx.exe`)

`StartKernel(entry, cmdline)` is called with `entry = e_entry - 0xc0000000` (`arclx.c:314-316`); the stub is `loadlx/run.S:30-56`. The binary matches it (stub at `0x401c20`): `cli` at `0x401c23`, `mov %bx,0x90020` with `0xa33f` at `0x401c28`, `mov %bx,0x90022` with `0x24` at `0x401c33`, a 256-byte `rep movsb` of the options to `0x90024`, `xor %ebx,%ebx` at `0x401c4a`, `jmp *%eax` at `0x401c4f`. Established.

- **Boot block. Established.** Only the old-style command line is written: magic at `0x90020`, offset `0x24` at `0x90022`, 256 bytes at `0x90024`. Nothing clears the block first, so every other field holds whatever was already in that memory (unknown). The 256 bytes are copied whole with no terminator added (`run.S:41-46`). The command line occupies block offsets `0x24` to `0x123`, over the APM, drive-information and system-descriptor fields the mainline kernels read from the same block.
- **Registers on leaving. Established.** `%bx` and `%ebx` are 0. The copy leaves `%esi` at the options pointer plus `0x100`, `%edi` at `0x90124` and `%ecx` at 0; `%eax` is the entry address. No GDT, segment-register, page-table or stack change. A kernel that takes its boot block from `%esi` (2.4, and the held 2.6 build) would read a block at the options pointer plus `0x100` instead of `0x90000`; what is there is unknown. Kernels that read the fixed `0x90000` (2.2 and SGI's 2.2.10) are unaffected.
- **Entry address. Established.** It is the ELF `e_entry` less `0xc0000000`: `0x100000` for the held kernels.

### 3. Handoff, `arclx2`

The order in `_start` (`0x40162c`, the PE entry point) is: GetMemoryDescriptor, banner, `InitMalloc` (`0x401154`), a "Memory avaialble: %u MB" line, argument processing, the boot-block writer (call at `0x401735`), then `LoadKernel` (call at `0x401749`), then Restart. All of the following are established from the disassembly.

- **Boot-block writer, `0x4015d8`.** It first zeroes 4 KB at `0x90000` (`rep stos` of `0x400` dwords, `0x4015e7` to `0x4015f6`), so every field it does not set is 0, including the E820 count at `0x1e8`, `EXT_MEM_K`, the loader type and the new-style command-line pointer at `0x228`. It then stores its first argument at `0x901e0` (`ALT_MEM_K`, `0x4015f8`), `0xa33f` at `0x90020` (`0x4015fe`), `0x800` at `0x90022` (`0x401607`), and copies the options string, at most 256 bytes and stopping after the terminator, to `0x90800` (`0x40161e`). The command line sits at `0x90800`, the offset that becomes `COMMAND_LINE` in the kernel's zero page; the loader reaches it through the old-style magic and offset.
- **The memory value.** `InitMalloc` keeps the largest `BasePage + PageCount` over all descriptors (`0x401154`; compare and store at `0x4011d8` to `0x4011e9`), converts it to megabytes with `shr $8` (128 when the maximum is zero, `0x401205` to `0x401218`) and the main function passes `megabytes << 20` (`0x401731`). So `ALT_MEM_K` is a byte count. The held 2.6.0-test2 build reads offset `0x1e0` as bytes (`machine_specific_memory_setup`, `0xc0342400`: the load at `0xc034240c` becomes `mem_size`, `0xc0358c18`); it subtracts 8 MB for the `sgivwfb` buffer (`0xc0342445`) and prints "Bootloader didn't set memory size" only when the value is zero (`0xc034241a`), then assumes 128 MB. With this loader the warning therefore fires only when the megabyte count is a multiple of 4096 (a zero maximum becomes 128 first). The firmware page builds the descriptors from the RAM banks plus fixed low entries, so a top at a multiple of 4 GiB is not expected on these machines (inferred). Mainline 2.2.10 and 2.4.0 read the same field as kilobytes.
- **Jump, `0x4015a6` to `0x4015cc`.** After `LoadProgramSegments`, it prints "Starting kernel; entry point = 0x%x" with a hard-coded `0x100000` (`0x4015af` to `0x4015bd`), then `xor %ebx,%ebx`, `%esi = 0x90000` (`0x4015c4`), `cli`, `jmp *%eax` with `%eax = 0x100000`. `e_entry` is never read. This loader works for a kernel linked at `0xc0100000` with entry at its start, such as the held ones, and for no other layout.
- **Which kernel it serves.** Setting `%esi` to the block and writing a byte-count memory field are what the held 2.6 vmlinux needs (it copies its parameters from `%esi`, `0xc01000be`). So this loader fits that vmlinux and `arclx.exe` does not (inferred). Whether it was the loader used with that file is unknown.

### 4. What the mainline kernels expect

All of this is source reading; SGI's changes are in the next section.

- **Load address. Established.** Kernel text is linked at `0xC0000000 + 0x100000`, physical 1 MB (`arch/i386/vmlinux.lds:9`, both trees).
- **Paging. Established.** 2.4 builds its first page tables, writes CR3 and sets PG with `orl` (`head.S:86-106`); it does not clear PG first. 2.2 does not build them: `swapper_pg_dir` and `pg0` are static image data at `0x101000` and `0x102000` (`head.S:357-373`) and the entry writes CR3 and sets PG (`head.S:67-79`). Firmware tables that are already live are replaced at once.
- **Segments before the kernel's GDT. Established for the order and for the firmware's GDT.** Both trees load DS, ES, FS and GS with `__KERNEL_DS`, `0x18` (`segment.h:5`; 2.4 `head.S:51-55`, 2.2 `head.S:47-51`) and load their own GDT only later (2.4 `head.S:250`, 2.2 `head.S:228`). The firmware's selector `0x18` is a flat DPL 3 code segment, not a writable data segment ([processor state at the loader call](#processor-state-at-the-loader-call)): the loads succeed, the first store through DS or ES, or the load of SS, takes #GP. Neither loader changes the GDT. On this firmware a mainline 2.2 or 2.4 kernel stops at its first store; it needs a loader that installs a GDT with a writable `0x18` first (inferred; none is held).
- **Stack. Established.** `lss stack_start` after paging is on (2.4 `head.S:109`, 2.2 `head.S:82`). The firmware's `0x61ff0` is not needed.
- **`%bx`. Established.** Only an SMP build tests it: a non-zero `%bx` takes the secondary-processor path (2.4 `head.S:56-57`, 111-113; 2.2 `head.S:52-54`, 84-86). A loader for an SMP kernel must zero `%bx`; a uniprocessor build never looks.
- **`%esi` and the block. Established.** 2.4 reads the boot block through `%esi` ("On entry, %esi points to the real-mode code", `head.S:42`, `144-170`). 2.2 ignores `%esi` and reads a fixed `0x90000` (`head.S:119`). A loader serving both writes the block at `0x90000` and sets `%esi` there (inferred).
- **Boot block. Established (2.4 `setup.c:154-172`, `e820.h:15-17`; 2.2 `setup.c:100-116`).** 2 KB of fields, then a 2 KB area whose first 256 bytes are the command line (`COMMAND_LINE`, `PARAM+2048`). The fields:

  | Offset | Field |
  |---|---|
  | `0x002` | `EXT_MEM_K`, 16-bit, kilobytes |
  | `0x040` | APM information |
  | `0x080` | drive information |
  | `0x0a0` | system descriptor table |
  | `0x1e0` | `ALT_MEM_K`, 32-bit, kilobytes |
  | `0x1e8` | E820 entry count (2.4 only) |
  | `0x1f2` | root mounted read-only flag |
  | `0x1f8` | RAM disk flags |
  | `0x1fc` | root device |
  | `0x210` | loader type; the initrd fields are used only when it is non-zero (2.4 also needs `INITRD_START`) |
  | `0x214` | kernel start |
  | `0x218` | initrd start |
  | `0x21c` | initrd size |
  | `0x228` | pointer to the command line (2.4 only); zero selects the old magic |
  | `0x2d0` | E820 map, up to 32 entries (2.4 only) |

  Old-style command line: magic `0xA33F` at physical `0x90020`, offset at `0x90022`, base `0x90000` (2.4 `head.S:19-22`, 2.2 `head.S:18-21`). Both trees copy the first 2 KB of the block (from `%esi` in 2.4, from `0x90000` in 2.2) to the zero page and zero the second 2 KB (2.4 `head.S:150-158`, 2.2 `head.S:119-128`), then copy 2 KB of command line into that second half (2.4 `head.S:159-170`, 2.2 `head.S:129-136`).
- **Memory map. Established.** 2.4 uses an E820 map when the loader gives one with at least two entries (`setup.c:456-460`, `497-507`); otherwise it takes the larger of `ALT_MEM_K` and `EXT_MEM_K` as a kilobyte count from address 0 and adds RAM below `0x9f000` and from 1 MB up to that count (`setup.c:511-521`). 2.2 takes the larger of `EXT_MEM_K` and `ALT_MEM_K` as kilobytes above 1 MB (`setup.c:276-283`), so the two trees differ by 1 MB in what the field means. Neither reads ARC memory descriptors, and neither has a visws memory reservation or graphics-memory setting in `setup.c` (searched; none).
- **Board type and revision. Established (2.4 `setup.c:225-301`, 2.2 `setup.c:169-245`).** The PIIX4 GPIO board bits are read first, then the NS87307 GPIO block is enabled to read the revision; it runs before memory set-up (2.4 `setup.c:604-605`, 2.2 `setup.c:259-260`).
- **Lithium and Cobalt set-up. Established.** `lithium_init` writes `0xffff` to `LI_PCI_INTEN` (`+0x46`) on both bridges (2.4 `traps.c:912-924`, 2.2 `traps.c:634-646`), then `cobalt_init` maps the Cobalt CPU block and APIC, prints their revision and ID, and ORs `CO_APIC_ENABLE` (bit 8, `cobalt.h:38`) into the APIC ID register at `+0xffc` (`cobalt.h:35`), keeping the ID (2.4 `traps.c:927-947`, 2.2 `traps.c:649-669`). This matches item 4 of [Boot into Linux](#boot-into-linux). Neither tree reads a Lithium vendor or device word (`lithium.h` defines only the bus-number and interrupt-enable registers). The PCI code uses configuration mechanism 1 (`0xCF8`, `0xCFC`) only (2.4 `pci-visws.c:27-69`) and reads bridge B's bus number to scan buses 0 and the secondary (`pci-visws.c:120-124`). The Lithium probe in item 2 of [Boot into Linux](#boot-into-linux) is 2.6 only.
- **Interrupts. Established (2.4 `visws_apic.c:374-409`).** `init_VISWS_APIC_irqs` gives each of the 16 ISA lines the PIIX4 master, PIIX4 virtual or Cobalt handler type; Cobalt entries are programmed on first use (`co_apic_set`, `visws_apic.c:136-139`).
- **SMP start-up. Established.** Neither tree reads a firmware processor table. 2.4 `find_visws_smp` (`mpparse.c:617-626`, called at `639-641`) sets `smp_found_config`, adds processor id 1 to `phys_cpu_present_map`, sets the integrated-APIC bit in both `apic_version` entries and sets `mp_lapic_addr` to `APIC_DEFAULT_PHYS_BASE`. 2.2 `init_visws_smp` (`smp.c:614-623`) does the same, so both start two processors, ids 0 and 1. The literal `0x1e00` appears nowhere under `arch/i386` or `include/asm-i386` in 2.4.0, and in 2.2.10 only inside page-table constants (`head.S:376-472`). This agrees with item 8 of [Boot into NT](#boot-into-nt). Both trees write the warm-reset vector at `0x467` and `0x469` (2.4 `smpboot.c:593-595`, 2.2 `smp.c:966-968`), as item 9 of that section describes.

### 5. The held SGI and 2.6 kernels

**SGI 2.2.10 (`linux-visws-sf-la2210.vw`).** ELF32 `EXEC`, entry `0xc0100000`, one `PT_LOAD` at file `0x1000` with file size `0x10e800` and memory size `0x131650`.

- **Build flags. Established.** It is a uniprocessor build: `.config` line 26 is `# CONFIG_SMP is not set`, the image contains no `orw %bx,%bx` test and no SMP symbol, and `CONFIG_BLK_DEV_INITRD` (line 94) is off. `CONFIG_VISWS=y` is line 49. `CONFIG_VISWS_HACKS` is defined by the top-level `Makefile` of both patches: under `ifdef CONFIG_VISWS` it adds `-DCONFIG_VISWS_HACKS` to `CFLAGS` and `AFLAGS` (`Makefile:96-99`). Because the image is uniprocessor, neither patch's `init_visws_smp` is in it. The 28 July patch reads a processor count at physical `0x1e00` and up to four `mpc_config_processor` entries after it, refusing a count above four (`smp.c:621-640`); the 15 July source hard-codes id 1 as 2.2 does (`smp.c:614-623`). Both are source facts and neither is in this image. The image's version string is dated 28 July 1999, which suggests but does not prove it came from the 28 July tree.
- **Opening instructions. Established.** `head.S` begins with a block that `CONFIG_VISWS_HACKS` adds in both patches (`head.S:43-48`): `mov $0x101000,%eax; mov %eax,%cr3; lgdt gdt_descr; lidt idt_descr` (`0xc0100000` to `0xc0100015`), and only then loads DS, ES, FS and GS with `0x18` (`0xc0100017` to `0xc0100022`). The kernel's own tables and GDT are thus in place before any segment load, so the loader's GDT is not used. The kernel's `swapper_pg_dir` at `0x101000` takes over at the first CR3 write. `gdt_descr` is at the link address `0xc0100226`, so the `lgdt` can find it only with paging on. The CR3 write before it switches to the kernel's own directory, whose entries 0 and 768 both map the first 4 MB (`0x102007`: `head.S:357-364`, checked in the image at `0xc0101000` and `0xc0101c00`). With paging off at entry the read would use physical `0xc0100226`. So the image needs paging already on, and the firmware has it on, identity-mapping all RAM including the entry page at `0x100000`; the instruction after the CR3 load is fetched through the kernel's own directory (its entries 0 and 768 both point at a static table that identity-maps the first 4 MiB, checked in the image), so what else the firmware maps does not matter. The image reloads CS with a far jump to `0x10` at `0xc0100166`; until then CS holds the firmware's `0x08`. Established from the instruction order, the image and the firmware trace ([processor state at the loader call](#processor-state-at-the-loader-call)).
- **Boot block. Established.** After paging, `head.S` sets `%esi` to `0x90000` (`0xc0100060`), so the entry value is ignored. It then copies 2048 bytes from `0x90000` to `empty_zero_page` at `0xc0105000` (`0xc0100060` to `0xc0100070`), zero-fills the next 2048 bytes, compares `0xa33f` with the word at `0x90020` (`0xc010007b`), and when it matches copies `0x800` bytes from `0x90000` plus the word at `0x90022` to `0xc0105800` (`0xc0100086` to `0xc010009d`).
- **Memory. Established.** The image has the strings "VISWS HACK: hard-wiring physical mem size to %dMb" and "taking %ldMb for gfx memory", the symbol `sgivw_gfx_mem_size` and the `gfxmem=` option. In the patched `setup_arch` (`setup.c:227-238`) `memory_end` is set to 128 MB; the code at `0xc02013f8` is that constant. The graphics size defaults to 16 MB (`setup.c:335-337`; `0xc0201594`), is cut to whole megabytes, and is subtracted (`setup.c:339-343`), so the kernel gets 112 MB and graphics start at 112 MB. A `mem=` option can still override `memory_end` before the subtraction (`setup.c:291-305`). The boot block's `EXT_MEM_K` and `ALT_MEM_K` are not read.
- **Other boot-block fields. Established.** The same branch skips the reads of root device, drive information, screen information, APM, system descriptor, auxiliary-device flag, the read-only flag and the RAM disk flags (`setup.c:240-273` is the `#else` side). The root device and RAM disk come from the command line. The initrd fields (`LOADER_TYPE`, `INITRD_START`, `INITRD_SIZE`) are still read in the source under `CONFIG_BLK_DEV_INITRD` (`setup.c:377-380`), which is off in the held configuration.
- **Fit with the loaders.** Established: the image needs only the command line at the old-style place, which both loaders write, and it ignores `%esi` and the memory fields, so `arclx.exe`'s leftover `%esi` and unwritten fields do no harm. Inferred: that `arclx.exe` is the loader SGI shipped with it, since the 1999 transcript pairs `la2210.vw` with arcboot's messages.

**Visws 2.6.0-test2 vmlinux (`boor-vmlinux-vws.gz`).** ELF32 `EXEC`, entry `0xc0100000`. Its entry tests `%bx` (it is an SMP build; file `0x1000`), builds page tables at `0x102000`, loads CR3 with `0x101000` and runs `lgdt` (file `0x1025`), then loads the segments, copies 2 KB from `%esi` to its zero page at `0xc0104000` and takes the command line from the new-style pointer at `+0x228` or the old magic at `0x90020` (`0xc01000be` to `0xc01000f5`). It prints "Silicon Graphics Visual Workstation %s (rev %d) detected". Established from the bytes. The memory handling is in section 3.

### 6. Summary of fit, conflicts and what is open

| Loader | Block written | Fits |
|---|---|---|
| `arclx.exe` (arcboot) | command line only, rest left as found; `%esi` not the block | 2.2.10 as patched (reads `0x90000`, ignores memory fields); not 2.4 or 2.6 (read `%esi`) |
| `arclx2` | 4 KB zeroed, command line at `0x90800`, byte-count memory at `0x1e0`; `%esi = 0x90000` | the held 2.6.0-test2 vmlinux (inferred); not 2.2.10 or 2.4.0 (they read kilobytes) |

- Item 1 of [Boot into Linux](#boot-into-linux) said neither loader file was held. arcboot and `arclx2` are held now. `larc.exe`, the other loader name in the user reports, is not.
- Item 8 of [Boot into NT](#boot-into-nt): the 2.2 and 2.4 ports hard-code two processors. The 28 July SGI patch source reads the firmware table, but the held SGI image is uniprocessor and does neither.
- Items 2 and 3 of [Boot into Linux](#boot-into-linux) describe the 2.6 port. The held 2.6.0-test2 build prints the warning they quote, so their scope stands.
- Settled by the firmware trace: the opening `lgdt` of the SGI image works as it stands; the segment loads of the mainline kernels succeed but their first store faults ([processor state at the loader call](#processor-state-at-the-loader-call)). Unknown: whether `arclx2` was used with the held 2.6 vmlinux; whether an SMP build of SGI's 2.2.10 existed; what `larc.exe` is.

## PCI enumeration

1. **Two host bridges. Established (Linux, HAL).** Lithium A (the "Ethernet" side, window `0xfc000000`) and Lithium B (the
   PIIX4 side, `0xfd000000`) are two PCI host bridges with their own bus numbers, read from a 16-bit register at `+0x44`
   (low byte primary bus, high byte subordinate); Linux scans both and reports bridge A's bus as `pci_bus1`. The
   Lithium vendor and device words sit in its window at the ordinary config header offsets. Linux uses configuration
   mechanism 1 only.
2. **The HAL enumerates and assigns resources itself. Established (HAL read).** It walks buses, devices and functions,
   creates sub-buses behind bridges, and gives out I/O and memory base address register ranges (with a note when
   prefetchable memory cannot be provided and non-prefetchable is used instead). It does so through the Lithium window's
   own configuration data and address registers at `+0xfc` and `+0xf8`: the address value has the 32-bit bit 31 set,
   the bus in bits 23:16, the device in bits 15:11, the function in bits 10:8 and the dword-aligned register in the
   low bits, and a read or write of the data register performs the cycle; afterwards the bridge's status word at `+6`
   is written back to clear error bits. Whether firmware also assigns resources before the OS starts is unknown
   (Linux 2.6 calls its usual resource survey, which keeps firmware assignments when present); the 1.0006 main module has no
   generic PCI walk or BAR-sizing loop that a pattern search finds (see the main module section), and the boot block's PIIX4
   writes use the same Lithium window registers (`+0xf8` address, `+0xfc` data) that the HAL uses.
3. **Interrupt pins. Established (HAL and Linux tables).** Per-slot pin-to-Cobalt-entry maps exist for each hardware
   generation: five slots per bridge (the HAL's node names are "Pci A Slot 0..4" and "Pci B Slot 0..4"). The
   PIIX4's USB uses a dedicated entry. See [nt-hal.md](nt-hal.md).

## Graphics and console

The HAL's display path has a text mode on the standard VGA registers and a Cobalt graphics (frame-buffer) mode;
`HalpInitializeGbeDisplay0` can fail and the HAL falls back. The firmware displays its menus and the NT boot screen on
the Cobalt graphics output; console and keyboard devices named `consoleout` and `consolein`, `nogfxkbd` and a `console`
variable exist (a serial console option; debug output goes to COM1 or COM2 with baud rates from the `dbaud` and
`rbaud` options). The firmware's own display initialisation, mode table and flat-panel probe are read in
[the Cobalt repository's page](https://github.com/jamesbraid/cobalt/blob/main/devices/cobalt-graphics/prom-init.md); the HAL's
`cobaltVTimings` table belongs to [devices/cobalt-graphics](../../devices/cobalt-graphics/).

## What no source settles

The reset values of the memory controller's registers and what its timing registers are; whether the firmware assigns PCI
resources to endpoint devices before the OS; the bit meanings of the Lithium `+0x48`, `+0x58` and `+0x60`-`+0x70` writes and
the Cobalt APIC `+0xffc` field; where the embedded legacy-BIOS image is mapped and whether any of it
is visible to an OS; the components, classes and keys of the ARC tree beyond the nodes named above; which firmware vectors
`arcldr.exe` calls; the private vector's purpose; firmware versions 1.1002 to 1.1004; and the open Linux loader questions. All are in
[questions/visws-firmware-open.md](../../questions/visws-firmware-open.md).
