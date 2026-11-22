# SGI Visual Workstation 320 and 540: open points from the HAL requirements page

From [software/visws/hal-requirements.md](../software/visws/hal-requirements.md). Each entry: question, routes tried, what would settle it.

## What loads XP and what it hands the HAL

[route: design decision plus missing source] The firmware starts an ARC loader. XP's loader is BIOS-based, and no public Microsoft
source shows an ARC x86 path in XP. Windows 2000 was the last release with SGI's loader and HAL. Tried: Microsoft Learn, the HAL
history and export studies, secondary articles on the machine. Settles it: our own loader or a firmware stand-in that defines the system
description bytes, the memory descriptors and the processor table, written before the HAL.

## XP HAL contract items not established from public Microsoft material

[route: missing source] The `HalInitSystem` phase contract, the HAL private dispatch table's contents, the loader block layout and how the
PCI bus driver asks the HAL for pin routing are not documented for non-Microsoft HAL authors. Tried: the kernel DDI index, the HAL export
study, an engineer's blog on arbitration and translation. Settles it: Microsoft's HAL kit for OEMs if a copy exists, or observing a stock
HAL's behaviour in a run.

## XP x64 on a board whose processors cannot run x64

[route: design decision] The 320 and 540 take Pentium II and III processors. XP x64 needs long mode, so only an emulated board with the
Cobalt and Lithium chipset and a long-mode processor can run it. Whether a non-ACPI HAL boots on x64 is not established by Microsoft material:
Chappell's study says x64 has one HAL, and the Wikipedia article on Windows Server 2003 says x64 builds "strictly require ACPI" without naming a Microsoft source (that article is about Server 2003, not XP x64; the Ntdetect.com article says only that Vista and later HALs are ACPI-only; a vendor advisory link returned an error and is not cited). Settles it: a statement from Microsoft on x64
hardware requirements, or a run.

## Non-ACPI HAL on x64

[route: missing source] See the previous entry. The firmware's fixed ACPI table has no DSDT, FACS or MADT, so an ACPI HAL cannot enumerate devices
([boot-path.md](../software/visws/boot-path.md#legacy-bios-and-the-acpi-tables)). Settles it: the same sources.

## Time-stamp counter agreement across processors

[route: missing source] Microsoft requires one performance counter frequency across processors. The SGI HAL writes each
processor's time-stamp counter to zero in the calibration routine (write at `0x8002c8ab`; two laps, so the last zeroing follows the third
RTC edge and the last read the fourth, leaving about one second of ticks) and in the exported `HalCalibratePerformanceCounter`
(`0x8002d210`), which first makes all processors rendezvous on a counter. No call to the second inside the HAL was found, so the kernel is the
caller. Whether the counters then agree to within a tick, and whether the kernel calls it on this platform, is not shown. Settles it: a model
run, or the processors' documentation.

## HAL routines not yet read

[route: software now] Read in the follow-up pass: the stall loop (`0x800114e0`), the real-time clock write (`0x800194f0`), the broadcast-call
handshake (`0x800129d4`), the IPI wait loops, `HalReturnToFirmware`, `HalAllProcessorsStarted`, `HalInitializeProcessor`, `HalpInitMP`. Still
unread: the end of `HalEndSystemInterrupt`'s argument decoding, the two I2C layers, `HalReportResourceUsage`'s port list, the common-buffer
and crash-dump DMA routines, the ISA and internal bus handlers behind `HalGetBusData` and `HalTranslateBusAddress`, `HalpGetCmosData`'s use of
the PIIX4 extended-CMOS bit, the environment rewrite, and the display drawing routines. Settles it: read each in full in `halborg.dll` 1.3.

## Cache-operation interrupt and the flush routines

[route: missing source] What raises Cobalt CPU status bit 0 and how `HalxFlush*` reach the Cobalt invalidate is not shown. Tried: the clock
handler and the callers of the flush routines as recorded. Settles it: the Cobalt specification, or reading the cache-operation routines
(`CacheopInitialize`, `CacheopInterrupt`) in full.

## Host bridge ranges as the PnP manager needs them

[route: missing source] The memory and I/O ranges per bridge are inferred from the HAL's static records. Whether the bridges decode more,
and whether the system-side I/O offset exists, is unknown ([Lithium page](../devices/lithium/README.md)). Settles it: the Lithium specification
or the firmware's programming of the bridge windows.

## Power button and soft off without ACPI

[route: design decision] The SGI HAL arms the PIIX4 power button on ISA IRQ 9 and suspends. How a non-ACPI XP HAL turns that into the power
manager's shutdown request is not established. Settles it: the XP HAL contract entry above.

## Boot video for XP on the Cobalt display back end

[route: software now] XP draws boot text through a boot video driver that the kernel loads. SGI's Windows 2000 CD has one (`sgibvid.dll`). Its
register use is not recorded here, and the HAL's own start-up of the back end reads a flat-panel identity over I2C that is unread.
Settles it: read `sgibvid.dll` and the HAL's I2C layers.
