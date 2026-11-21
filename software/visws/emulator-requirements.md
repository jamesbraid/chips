# Visual Workstation 320 and 540: what an emulator must provide

Two routes: run the firmware image (only PROM 1.0006 is held), or replace it with a small stand-in that leaves the machine in the state
the operating system software expects. Grades as in the [README](README.md). Everything below is a requirement
derived from shipped NT software and the public Linux port; the chipset's register behaviour itself is in the chip
pages.

## Running the real firmware

The PROM 1.0006 image is held ([firmware.md](firmware.md)), so this route can be tried; no run has been done. What the image
asks of the machine before it reaches its main module: RAM that works up to 16 MiB with no sizing (the boot block copies
the flash to `0x80000` and expands the firmware to `0xf00000`-`0xff0264`), the Lithium configuration window at
`0xfd0000f8`/`0xfd0000fc` and the PIIX4 behind it, an NS87307 answering on ports `0x2e`/`0x2f`, the 8259 and DMA
ports, MSR and MTRR instructions, and Cobalt bank registers at `0xc6000048` and up that report populated banks
([boot-path.md](boot-path.md)). The flash is 512 KiB mapped at `0xfff80000` (software expectation: the HAL maps and programs it), accessed as a 16-bit
AMD-command-set flash with the usual two-cycle unlock; the ARC environment lives in its top 8 KiB sector, which the
operating system rewrites, so the device needs a persistent, erasable model. The firmware would additionally need the
chips the HAL expects (PIIX4, NS87307, CMOS RTC, 8259 pair, floppy, IDE and SCSI), a keyboard (a USB or PS/2
keyboard; the HAL carries `nogfxkbd` and keyboard nodes), and a working Cobalt graphics output for its menus.

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
   level input (entry 12) that the kernel polls with the OCW3 poll command, IDE on entries 4 and 2 (the revisions noted),
   PCI slot lines on entries 0 to 15 per the two bridge map. The kernel does not use an I/O APIC.
8. The warm-reset vector method for starting the other processors (CMOS register `0x0f` set to `0x0a` and the
   vector at `0x467`) and the local APICs' INIT and startup IPIs.
9. Reboot by a write of `0x06` to port `0xcf9` and power-off through the PIIX4 PM control registers
   (suspend-enable at `0xf84` bit 13, after clearing status at `0xf80`, then the special cycle through `0xcfc`).
10. The standard PC legacy devices (8259 pair, 8254 not used for the clock, CMOS RTC, IDE, floppy, serial, parallel, PS/2
    or USB input through the PIIX4's USB controller on its dedicated Cobalt entry).

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
   for the HAL's own text output the display has to initialise through its Cobalt path or fall back to VGA text.

A standard Windows installer will not do: the SGI setup program replaces the HAL, the loader and the video driver.

## Not known

The graphics-memory split, the stand-in's ARC services at the byte level (the table's layout is in [boot-path.md](boot-path.md); which entries the loader calls is not enumerated), the
the Cobalt memory controller's programming and reset values, where the embedded legacy-BIOS image is mapped; and whether the real firmware or
the OS assigns PCI resources, which determines whether an emulated stand-in must. See
[questions/visws-firmware-open.md](../../questions/visws-firmware-open.md).
