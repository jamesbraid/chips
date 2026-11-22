# Visual Workstation 320 and 540: requirements for our own Windows XP and XP x64 HAL

This page lists what a hardware abstraction layer (HAL) written for Windows XP (32-bit) and Windows XP x64 must do on the SGI Visual
Workstation 320 and 540. It is written from hardware facts, not from SGI's HAL. The facts come from the chips pages and from the
reading of SGI's NT 4.0 HAL recorded in [nt-hal.md](nt-hal.md) and [hal-hot-path.md](hal-hot-path.md). Nothing here is a port, and no
SGI listing is reproduced. Names are function, symbol and string names the shipped files carry.

Each requirement has the same four parts. The grade rates the hardware fact behind it, with the grades of the
[software/visws README](README.md): *established*, *observed*, *software expectation*, *inferred* or *unknown*. The first words of the grade line grade the behaviour the HAL must reproduce. Weaker parts follow, each with its question link. Then come the fact with its link, what
the HAL must do, and what the guest sees. A gap is graded *unknown* and links an open question. Nothing is filled in by guess.

## Read this first

- **XP x64 cannot run on the real machines.** The 320 and 540 take Pentium II and III processors, which have no long mode. An x64 HAL
  only makes sense for an emulated board that pairs the Cobalt and Lithium chipset with a processor model that has long mode
  ([question](../../questions/visws-hal-requirements-open.md#xp-x64-on-a-board-whose-processors-cannot-run-x64)). Every requirement
  below applies to both builds unless it says otherwise.
- **No loader for XP exists.** The firmware starts an ARC loader. XP's 32-bit loader is the BIOS-based one, and no public source shows an
  ARC x86 path in XP. The contract between a loader and our HAL is ours to define
  ([question](../../questions/visws-hal-requirements-open.md#what-loads-xp-and-what-it-hands-the-hal)).
- **A hardware vector is a HAL choice.** The Cobalt entries hold whatever vector the HAL writes. The vector tables in
  [nt-hal.md](nt-hal.md#interrupt-delivery-in-the-hal) are SGI's choices, not hardware facts. Our HAL may pick its own, within the
  constraints in HR-INT-04.
- **Binary reading.** Claims with an address in this page were re-read in an `objdump` listing of `halborg.dll` 1.3 (sha-256 `0926cd50…`)
  by a follow-up pass that checked the points an independent review raised and the routines in the further-routines section. The rest are the
  established claims of the existing pages. Where those pages call a point inferred or unread, it stays so here. Addresses are the image's.

## Sources

Hardware facts: [nt-hal.md](nt-hal.md), [hal-hot-path.md](hal-hot-path.md), [boot-path.md](boot-path.md), [firmware.md](firmware.md),
[emulator-requirements.md](emulator-requirements.md), the [platform pages](../../platforms/visws/README.md), the
[Cobalt page](../../devices/cobalt/README.md) with its [register list](../../devices/cobalt/registers.md), and the
[Lithium page](../../devices/lithium/README.md). Open questions already filed: [visws-hal-open.md](../../questions/visws-hal-open.md),
[visws-open.md](../../questions/visws-open.md), [visws-firmware-open.md](../../questions/visws-firmware-open.md). New ones from this
page: [visws-hal-requirements-open.md](../../questions/visws-hal-requirements-open.md).

Microsoft material (checked in this pass) is cited in [the XP section](#what-xp-and-xp-x64-expect-that-nt-40-did-not). The Library
held none of it, so the pages were fetched from the public web.

## Requirement count by grade

Counted from the first word of each requirement's grade line.

| Grade | Requirements |
|---|---|
| established | 63 |
| observed | 0 |
| software expectation | 2 |
| inferred | 2 |
| unknown | 3 |
| Total | 70 |

The XP and XP x64 table has 17 further rows (HR-XP-01 to HR-XP-17), each marked verified, partly verified, inferred or unverified in its status column. They are not counted here.

## Section list

1. [Platform identification and the loader interface](#1-platform-identification-and-the-loader-interface)
2. [Interrupts](#2-interrupts)
3. [Clocks and timers](#3-clocks-and-timers)
4. [Inter-processor interrupts, NMI and cache operations](#4-inter-processor-interrupts-nmi-and-cache-operations)
5. [Starting the other processors](#5-starting-the-other-processors)
6. [PCI bus access, DMA and resources](#6-pci-bus-access-dma-and-resources)
7. [Memory errors and ECC](#7-memory-errors-and-ecc)
8. [Power management and reboot](#8-power-management-and-reboot)
9. [Debug output and the console](#9-debug-output-and-the-console)
10. [Further routines and exports](#further-routines-and-exports)
11. [What XP and XP x64 expect that NT 4.0 did not](#what-xp-and-xp-x64-expect-that-nt-40-did-not)
12. [Unknowns that block writing the HAL](#unknowns-that-block-writing-the-hal)

Local APIC accesses are 32-bit loads and stores at the Intel default base `0xfee00000`. Cobalt registers are 32-bit words. Mapping all
of them uncached is part of every requirement that touches a register.

## 1. Platform identification and the loader interface

#### HR-ARC-01 Board generation from the system description
- Grade: established for the HAL's use, inferred for what the bytes mean (0 is the 320, 1 the 540).
- Fact: the HAL reads a byte called SYS TYPE and a byte called BOARD REV from firmware-built nodes under the system component and uses
  them to pick the interrupt tables and the reboot method. Generation 1 is a 320 below revision 6 and the 540 revision 0, generation 2
  is a 320 revision 6 to 11, generation 3 is everything else ([nt-hal.md](nt-hal.md#interrupt-delivery-in-the-hal),
  [boards-320-540.md](../../platforms/visws/boards-320-540.md#board-generations-the-hal-selects)). The HAL never probes port `0xfb2`.
- Our HAL must: obtain the two bytes from whatever the loader supplies, treat them as unsigned, and select the generation exactly as
  above. If the loader gives nothing, the HAL must not guess. It stops with a clear message.
- Guest sees: the product name the HAL derives from the system identifier. NT 4.0 shows a name beginning "Silicon Graphics".

#### HR-ARC-02 Memory descriptors, including graphics memory
- Grade: established for how the HAL uses descriptors, unknown for how the firmware picks the split ([boot-path.md](boot-path.md#boot-into-nt),
  [nt-hal.md](nt-hal.md#memory-banks-and-the-graphics-split)).
- Fact: type 3 descriptors are ignored, type 6 counts toward the total only, type `0x16` is graphics memory, the rest is OS memory. The
  first type `0x16` descriptor large enough holds the boot frame buffer. Banks start on a 4 MiB boundary and are a multiple of 1,024
  pages, or the HAL warns and does not remap them.
- Our HAL must: treat type `0x16` memory as not available to the OS, keep it out of the memory manager's pool and publish the banks
  for the graphics driver as described in HR-ARC-05.
- Guest sees: system memory in Task Manager is the total minus graphics memory. The 64 MB the graphics profile leaves for the OS is a
  guide figure, not a hardware limit.

#### HR-ARC-03 Boot options string
- Grade: established (whole option routine read).
- Fact: options are `ONECPU`, `PCILOCK`, `INTAFFINITY`, `BREAK`, `ARCINFO`, `SYSCLOCK=COBALT|APIC`, `PAGEOPENPOLICY=OPEN|CLOSE`,
  `MEMERR=ON|OFF`, `ECC=ON|OFF`, `BLOCKINTS=n`, `INTRROUTE=...`, `CACHEOPPOLL=n` and `HALOUT=...`. Case matters. Three are
  plain substring matches ([table](nt-hal.md#boot-options-the-hal-parses)).
- Our HAL must: honour at least `ONECPU`, `SYSCLOCK`, `MEMERR`, `ECC`, `PAGEOPENPOLICY` and `BREAK` with the same effect. It may drop
  `INTAFFINITY` (nothing in the SGI image reads it), `BLOCKINTS`, `USE8254` and the `INTRROUTE` alternatives. The `INTRROUTE` values
  exist for board wiring variants we have no reason to model separately, so the HAL derives the tables from HR-ARC-01 alone unless a
  guest needs the override.
- Guest sees: the same words on the boot command line change the same behaviour. XP's own switches are parsed by the kernel, not the
  HAL, and stay unaffected.

#### HR-ARC-04 Processor table at physical `0x1e00`
- Grade: established (HAL reader and firmware writer both read).
- Fact: a 16-bit count, then 20-byte entries: type 0, local APIC id, version, flags (bit 0 enabled, bit 1 bootstrap), then `cpuid`
  words. The first entry's version byte decides whether startup IPIs and the APIC error vector are used. A zero count makes the SGI
  HAL fall back to a built-in one-entry table ([boot-path.md](boot-path.md#boot-into-nt) item 8). Which local APIC id the bootstrap
  processor carries is unknown ([question](../../questions/visws-hal-open.md#which-local-apic-id-the-bootstrap-processor-has)).
- Our HAL must: map physical page `0x1000`, read the count and entries at `+0xe00`, and accept ids as written. With a zero count it
  runs one processor and uses the id the boot processor reads from its own local APIC. The built-in table's contents are unknown, so
  we do not copy them.
- Guest sees: the processor count in Device Manager and the number of CPUs the scheduler uses.

#### HR-ARC-05 Registry values the HAL publishes
- Grade: established for NT 4.0.
- Fact: the HAL writes per-processor `FeatureSet`, `VendorIdentifier` and `~Mhz` under the CentralProcessor keys, a `Serial Number`
  when the firmware gives one, and the graphics keys under `SGICtrl\Memory`: `GraphicsMemory`, `GraphicsMemorySize`, `NumberOfBanks` and
  `BankAddrNN` and `BankSizeNN` for banks 00 to 31 ([table](nt-hal.md#registry-values-the-hal-writes)).
- Our HAL must: write the `SGICtrl\Memory` keys unchanged, since the SGI graphics miniport reads them. Writing the CPU keys is the
  kernel's job in XP and the HAL does not duplicate it unless a guest shows it is missing (HR-XP-14 lists the check).
- Guest sees: the graphics control panel's memory reservation page works. Without the keys the miniport sees no banks.

#### HR-ARC-06 Firmware environment variables
- Grade: established for access (flash at `0xfff80000`), unknown for the HAL's rewrite and the default table
  ([visws-firmware-open.md](../../questions/visws-firmware-open.md#the-environment-block-hal-side-and-defaults)).
- Fact: the environment block lives in the top sector of a 512 KiB flash, AMD-style command set, 16-bit access. The HAL's
  `HalSetEnvironmentVariable` rewrites it. The graphics miniport writes `cogfxmem` through that call ([firmware.md](firmware.md)).
- Our HAL must: provide get and set of named variables backed by the flash block, keep the block's checksum valid and reject an
  invalid block rather than writing over it.
- Guest sees: a graphics memory change in the control panel survives a restart and appears as descriptors on the next boot.

#### HR-ARC-07 SGI HAL query and set classes
- Grade: established (disassembly of the query routine at `0x80029650` and the set routine at `0x8002b2c0`, `halborg.dll` 1.3).
- Fact: `HalQuerySystemInformation` answers class 0 (installed bus information, through `0x8002b3a0`), class 8 (one byte, value 1), class 9 (a
  dword, the return value of the function at `0x80018600`, which returns zero), the SGI class `0x8100001` (three cache-flush routine pointers at offsets 0, 4 and 8 and a flag byte at offset 12,
  clear on Cobalt Lite) and `0x8100002` (the callback-register entry). Any other class gets status `0xc0000148`
  ([table](nt-hal.md#the-sgi-specific-hal-interface)). The graphics driver refuses to load when the HAL lacks the SGI classes ("Not an SGI HAL").
  `HalSetSystemInformation` is not constant. Class 1 stores a caller-supplied pointer once, at `0x800205c8`, as the performance-counter
  interrupt hook, and returns success only when the CPU feature word (the value `0x8002e1e0` returns, tested at `0x80028680` bit 0) has that bit
  set and no hook is stored yet. Otherwise it returns `0xc0000001`. Every other class goes to a routine that returns `0xc0000148`. The
  profile-vector handler for vector `0xfe` calls the stored hook with the trap frame. This corrects [nt-hal.md](nt-hal.md#the-sgi-specific-hal-interface),
  which said the set call always answers the same (now corrected there).
- Our HAL must: answer classes 0, 8 and 9 as XP's kernel expects (not established, see the note after the XP table), the two SGI classes with the same layout when the SGI
  graphics driver is to run, and set class 1. It stores two callback slots as in HR-MEM-04.
- Guest sees: the SGI graphics driver loads. Without the SGI classes it fails its HAL check.

## 2. Interrupts

#### HR-INT-01 Cobalt interrupt controller start-up
- Grade: established for the writes, unknown for reset state and the id field ([Cobalt page](../../devices/cobalt/README.md#interrupt-controller-the-cobalt-apic),
  [question](../../questions/visws-open.md#cobalt-interrupt-controller-in-service-tracking-reset-state-identification-field)).
- Fact: 30 entries, low word at `0x10 * n`, high word at `+4`. The HAL masks all 30 (low word `0x10000`, high word 0), reads the id
  register at `+0xffc`, writes 4 into bits 27:24 if they read zero, then sets bit 8 to enable the controller.
- Our HAL must: repeat that order on the boot processor only, before any entry is enabled.
- Guest sees: nothing directly. A wrong order is a dead machine, as the controller's reset state is unknown.

#### HR-INT-02 Enabling and disabling a line
- Grade: established.
- Fact: a per-entry use count under a spin lock. The first user of an entry below 16 sets the entry's bit in the owning Lithium bridge's
  16-bit enable at window `+0x46` (entries 0 to 7 in bridge A, 8 to 15 in bridge B, bit `n & 7`), then writes the low word as vector
  with bit 15 (level), unmasked, fixed, physical, then writes the high word as 0. The last user to disable writes the low word back
  with bit 16 set. The bridge bit is never cleared ([nt-hal.md](nt-hal.md#second-reading-interrupt-levels-pci-dma-memory-registry-processors)).
  Every redirection write is low word, high word, then a byte read of the high word.
- Our HAL must: do the same, including the read-back that orders the write. Sharing an entry among drivers is handled by the use count,
  so a second user of the same entry changes nothing in hardware.
- Guest sees: shared PCI lines work because a driver disconnecting does not mask a line a sibling still uses.

#### HR-INT-03 Destination
- Grade: established for what the HAL writes, inferred for what the high word means.
- Fact: every device entry and the clock are written with high word 0, physical. The HAL has no per-processor steering and the
  `INTAFFINITY` flag is unread. The SGI HAL needs a processor with local APIC id 0 to exist and run. Whether the bootstrap processor
  has id 0 is unknown ([hal-open](../../questions/visws-hal-open.md#which-local-apic-id-the-bootstrap-processor-has)).
- Our HAL must: write the destination as 0 unless the processor table says no processor has id 0. If so, it writes the bootstrap
  processor's id. That case is unobserved.
- Guest sees: all device interrupts arrive on one processor. Per-processor steering would be a change from the shipped machine, not a
  hardware feature we know exists.

#### HR-INT-04 Vector and IRQL assignment
- Grade: software expectation for the SGI table, established that the entry's vector is programmable.
- Fact: SGI's HAL takes vectors from three 30-word tables by board generation. NT vectors carry the IRQL in the high nibble, though the
  page records that `HalGetInterruptVector` hands back the vector shifted right by 3 as the Irql (not reconciled there). The local APIC compares the vector's top four bits with the task priority, so
  the HAL's IRQL-to-priority table decides which interrupts a raised level masks
  ([hot path](hal-hot-path.md#interrupt-level-is-the-task-priority-register)).
- Our HAL must: assign vectors so that each device line's vector priority class equals the DIRQL XP's kernel expects for that line, and
  no two lines needing different IRQLs share a class. Reusing SGI's table is allowed and tested, but not required.
- Guest sees: IRQ numbers in Device Manager. These are the HAL's reporting choice (HR-XP-05).

#### HR-INT-05 Line assignments
- Grade: established (the HAL's tables), with Linux agreeing on the lines it uses ([interrupts.md](../../platforms/visws/interrupts.md)).
- Fact: entries 0 to 4 bridge A device INTA, 5 to 7 bridge A shared pins and the USB function, 8 to 11 bridge B INTA, 12 the 8259 cascade,
  13 to 15 bridge B shared pins, 16 and 17 video out, 18 and 19 video in, 22 audio, 24 and 25 the graphics engine, 28 the Cobalt timer and cache
  interrupt, 29 NMI. On Cobalt Lite the clock is 27 and NMI 28. Entry 2 is also the second IDE channel on the 320 and 4 or 5 the first.
- Our HAL must: use this map. Two entries can sit behind one number (IDE and a bridge device), and the HAL must not conflate them
  until the real wiring is known ([interrupts.md](../../platforms/visws/interrupts.md#cobalt-lines-established-from-the-header)).
- Guest sees: video drivers asking for internal-bus levels 16 to 19, 24 and 25 get those entries.

#### HR-INT-06 PCI pin to entry maps
- Grade: established as HAL data for three generations, unknown for which physical slot is which device
  ([questions](../../questions/visws-hal-open.md#which-physical-pci-slot-is-which-device-number)).
- Fact: five rows per bridge, four pin bytes each ([table](nt-hal.md#interrupt-delivery-in-the-hal) item 4). Pin A of device n owns
  entry n on bridge A and 8 + n on bridge B. The other pins share entries 5 to 7 (A) or 13 to 15 (B), rotated per slot on the newest
  generation. Bridge B device 4 is the PIIX4 with only pin D wired, to entry 7. Windows 2000 has a fourth set.
- Our HAL must: select the pair of tables by HR-ARC-01 and answer the PnP interrupt translation (HR-XP-05) from them. Behind a
  PCI-to-PCI bridge it swizzles the pin by adding the device number modulo 4.
- Guest sees: a card in a slot gets the entry its table row names. A wrong row shows as a device that never interrupts.

#### HR-INT-07 Acknowledge is the local APIC only
- Grade: established for what the HAL does, unknown for whether Cobalt tracks an in-service state
  ([question](../../questions/visws-hal-open.md#does-cobalt-track-an-in-service-state-for-a-level-line-and-does-the-local-apics-eoi-reach-it)).
- Fact: a device interrupt costs a TPR read and write on entry and an EOI (`+0xb0` = 0) then TPR write and read-back on exit. No
  Cobalt, Lithium or PIIX4 register is touched. Linux masks the entry before the EOI. The HAL does not.
- Our HAL must: follow the SGI HAL, because it is the behaviour shipped and observed to work. If the emulator or an FPGA model
  later shows an in-service bit, the HAL changes with the contract.
- Guest sees: no masking. A level source that stays asserted after the driver's routine returns re-interrupts at once.

#### HR-INT-08 The PIIX4's 8259 cascade on entry 12
- Grade: established for the sequence, inferred for why it is safe (level entry, edge 8259).
- Fact: the master's output is Cobalt entry 12, vector `0xb9` in all three SGI tables. The handler is a raw gate that does not touch
  TPR. Sequence: OCW3 poll (`0x0c`) on `0x20`, follow IRQ 2 into the slave on `0xa0`, specific EOI on the master (`0x60 | irq`) or
  non-specific on the slave and `0x62` on the master, a read of `0x21`, look up the ISA IRQ's vector, then send a self-IPI (`0x40000 | vector`, edge)
  after waiting for delivery status, then EOI the local APIC ([hot path](hal-hot-path.md#a-legacy-8259-interrupt)). The 8259 is initialised edge,
  master base 0, slave base 8, all masked.
- Our HAL must: reproduce the sequence. A cascade spurious input (slave poll bit 7 clear) is answered with `0x62` and returns.
- Guest sees: ISA devices (serial, floppy, parallel, keyboard, mouse) interrupt, each costing four to seven port accesses and a second
  interrupt on the re-injected vector.

#### HR-INT-09 ISA IRQ routing tables and the NS87307
- Grade: established for the tables, inferred for what names them.
- Fact: a 16-row table of three bytes per ISA IRQ: vector, Cobalt entry used when the row bypasses the 8259, flag byte (bit 0 through
  the 8259, bit 2 needs NS87307 steering, bit 1 on IRQ 14 and 15 sends a disable through the 8259 path while unused). The NS87307
  (index `0x2e`, data `0x2f`) steers IRQs 1, 3, 4, 6, 7 and 12 by writing its interrupt-type register (index `0x71`): bit 0 set for level, bit 1 for
  polarity. The first IDE channel is entry 4 on the newest 320 generation and the 540, 5 on the middle 320 and the 540 revision 0, and 1
  on the oldest 320 ([nt-hal.md](nt-hal.md#interrupt-delivery-in-the-hal) item 3).
- Our HAL must: build the ISA translator (HR-XP-05) from the table for the selected generation. It runs the NS87307 steering only for
  rows that need it. IDE and USB are never routed through the 8259.
- Guest sees: IDE, floppy, serial and USB behave on a default configuration. The `NO8259` and `IDE8259` variants are for alternate
  wiring we do not model.

#### HR-INT-10 Local APIC set-up per processor
- Grade: established.
- Fact: task priority `0xff` during set-up and 0 after. Spurious vector register `0x11f`. Logical destination one bit per processor id,
  destination format flat. Timer LVT masked and periodic at `0xfd`, performance counter masked at `0xfe`, LINT0 masked at `0x1f`, LINT1 NMI
  and masked (`0x184ff`, level), error vector `0xe3` unmasked only when the first table entry's version byte is nonzero
  ([nt-hal.md](nt-hal.md#multiprocessor-start-up) item 3).
- Our HAL must: program the same on every processor. LINT0 stays masked because the 8259 never reaches a processor pin.
- Guest sees: no external-interrupt path. A model that wires the 8259 to LINT0 has misread this machine.

#### HR-INT-11 Interrupt level is the task-priority register
- Grade: established for the SGI HAL, an implementation choice for ours.
- Fact: raise reads then writes TPR. Lower writes then reads back. `KeGetCurrentIrql` reads TPR. The level-to-TPR table has 32 levels
  mapped onto priority classes ([hot path](hal-hot-path.md#interrupt-level-is-the-task-priority-register)). These accesses dominate the
  machine's cost.
- Our HAL must: keep IRQL in the local APIC's task priority, since the hardware has no other masking scheme for Cobalt interrupts.
  A cheaper software IRQL with deferred hardware masking is allowed if the guest-visible ordering is the same.
- Guest sees: every raise and lower is an APIC access. Under emulation, a local APIC model in user space makes the machine unusably slow.

#### HR-INT-12 Software interrupts (APC and DPC)
- Grade: established.
- Fact: APC and DPC requests set a per-processor pending byte when the level matches the current dispatch state. Otherwise they send
  a self-IPI on `0x3d` (APC) or `0x41` (DPC). Their handlers write EOI, raise or restore TPR and read it back ([hot path](hal-hot-path.md#one-inter-processor-interrupt)).
- Our HAL must: implement `HalRequestSoftwareInterrupt` and the lower-IRQL dispatch check with the same observable order. The APC
  handler writes EOI before enabling interrupts.
- Guest sees: DPC and APC delivery at the right levels. A mistake in this order shows as lost DPCs or recursion.

## 3. Clocks and timers

#### HR-CLK-01 System clock is the Cobalt CPU-block timer
- Grade: established for programming, inferred for the self-reload.
- Fact: registers at `0xc2000000`: control `+0x10` (bit 2 run, bit 3 mask), status `+0x20` (bit 1 pending, bit 0 cache operation),
  reload `+0x30`, current `+0x38`. Linux writes a reload of core rate / HZ and sets run then clears mask, and never rewrites it, so the
  timer reloads itself. The HAL's default tick is 10 ms and its minimum 1 ms. `HalpInitializeClock` programs entry 28 (27 on Lite) as
  `0x80d1` (level, vector `0xd1`), high word 0 ([nt-hal.md](nt-hal.md#cobalt-registers-the-hal-programs)).
- Our HAL must: program it once, with `SYSCLOCK=APIC` as the alternate using the local APIC timer. A new tick length takes effect at
  the next tick by rewriting the reload.
- Guest sees: a 10 ms system tick, 1 ms when a program asks for finer timer resolution.

#### HR-CLK-02 Calibration against the RTC
- Grade: established.
- Fact: two passes. Wait for the CMOS update-in-progress flag (port `0x70` = `0x0a`, read `0x71`, bit 7) to fall and rise, start the
  timer with reload `0xffffffff`, wait for the same transition one second later and read how far `+0x38` fell, rounded to 10 kHz. The
  reload for a tick is the tick length times the measured frequency divided by 10 million. The local APIC timer is scaled the same
  way, and calibration also reads the time-stamp counter.
- Our HAL must: measure, not assume 100 MHz. The 100 MHz figure comes from Linux's constant only.
- Guest sees: the measured processor speed in `~Mhz` and a wall clock that keeps true time only if the timer counts at a true rate
  against the RTC. An emulation with a wrong timer rate drifts the guest clock.

#### HR-CLK-03 Tick acknowledge sequence
- Grade: established for the write pattern, inferred for write-zero-to-clear.
- Fact: read status. If bit 0 is set, print an error, write `0xfffffffe`, read it back. If bit 1 is clear, it is not a tick, so leave.
  Otherwise write `0xfffffffd`, read status back, then update system time ([hot path](hal-hot-path.md#one-clock-tick)). The timer's pending
  bit may self-clear, and which kernel behaviour is right is unknown ([question](../../questions/visws-open.md#cobalt-timer-pending-bit)).
- Our HAL must: write the same pattern and read back. The read-back orders the write before the EOI.
- Guest sees: one tick per period. Missing the clear leaves a level line asserted and the guest storms the interrupt.

#### HR-CLK-04 Tick fan-out to other processors
- Grade: established for the SGI HAL's behaviour, inferred that only the boot processor needs Cobalt's timer.
- Fact: the SGI HAL sends the tick to the others as an all-excluding-self fixed IPI on vector `0xd1` (command `0xc00d1`) from a countdown
  re-armed at 10 ms. After a shorter tick is requested, the other processors tick at 10 ms, slower than the boot processor
  ([hot path](hal-hot-path.md#one-clock-tick)).
- Our HAL must: deliver a clock interrupt to every processor for run-time accounting. Whether to copy the 10 ms ceiling is a design choice:
  we should send every tick, because XP's kernel accounts quantum per processor. The hardware fact is only that the local APIC timer
  exists on each processor.
- Guest sees: per-processor run time and thread quantum. Copying the ceiling makes secondary processors under-account at 1 ms ticks.

#### HR-CLK-05 Profile and performance-counter interrupts
- Grade: established.
- Fact: the local APIC timer is the profile source. Start writes the initial count (`+0x380`), then LVT `+0x320` = `0x200fd` (periodic,
  `0xfd`). Stop writes `0x300fd`. Divide register `+0x3e0` is `0xb` (divide by one) set during calibration. The performance-counter vector
  `0xfe` has its LVT at `+0x340`.
- Our HAL must: implement `HalStartProfileInterrupt`, `HalStopProfileInterrupt` and `HalSetProfileInterval` this way, with the
  profile level at the top of the device range.
- Guest sees: kernel profiling works. The count is the measured bus-clock frequency, so the local
  APIC timer must count at a true rate.

#### HR-CLK-06 Performance counter and its calibration
- Grade: established for the SGI HAL's use, with the XP requirement cited in HR-XP-09. Unknown whether the processors' time-stamp counters agree.
- Fact: `KeQueryPerformanceCounter` returns the time-stamp counter, with the calibrated frequency in its second result. The 8254 path
  is off (`HalpUse8254` is never set) ([nt-hal.md](nt-hal.md#boot-options-the-hal-parses)). The HAL writes the time-stamp counter to zero
  at two sites (`wrmsr` of MSR `0x10`). The first is in the calibration routine (`0x8002c840`, write at `0x8002c8ab`). That routine runs two laps. Each
  lap waits for an RTC update-in-progress rising edge, writes `0xffffffff` to the local APIC initial count (`+0x380`) and zeroes the counter, waits for one more
  edge and reads `rdtsc` and the APIC count. The last zeroing is therefore after the third edge and the last read after the fourth, so the
  counter is left holding about one second of ticks, not zero. Agreement between processors depends on the rendezvous below. The second is the exported
  `HalCalibratePerformanceCounter` at `0x8002d210`: it disables interrupts, does a locked decrement of the caller's counter and spins until it reaches
  zero (a rendezvous of all processors), executes `cpuid` to serialise, writes MSR `0x10` = 0 and returns. No caller inside the HAL
  references it, so XP's kernel is the caller. Whether the processors' counters agree after that is unknown
  ([question](../../questions/visws-hal-requirements-open.md#time-stamp-counter-agreement-across-processors)).
- Our HAL must: export `HalCalibratePerformanceCounter` with the same rendezvous, and return a counter that Microsoft documents as fixed in
  frequency and consistent across processors (HR-XP-09). We use the time-stamp counter only if the processors agree.
- Guest sees: high-resolution time. A drifting counter makes timing APIs go backward between processors.

#### HR-CLK-07 Stall loop
- Grade: established (`KeStallExecutionProcessor` at `0x800114e0`, `HalInitializeProcessor` at `0x8002e2f0`).
- Fact: the routine reads the time-stamp counter, adds the requested microseconds times a per-processor scale factor and spins on `rdtsc` until the
  target passes. The factor is the dword at offset `0x4c` of the processor control region: `HalInitializeProcessor` sets it to 100, and the
  calibration code stores the measured value at `0x8002c950`. A leading `cpuid` serialises the first read, and when CPU feature bit 1 is set,
  `HalAllProcessorsStarted` overwrites it with a register move (`0x800114e4`). That is documented behaviour to copy: at least the interval, not
  significantly longer (HR-XP-10).
- Our HAL must: scale a loop from the calibrated time-stamp frequency per processor.
- Guest sees: driver delays of tens of microseconds.

#### HR-CLK-08 Real-time clock
- Grade: established for reads and for the write path (HR-EXP-11), unknown for extended CMOS contents.
- Fact: the CMOS RTC at `0x70` and `0x71`, BCD, years below 70 read as 20xx, an out-of-range date resets to 1 January 1998. Extended CMOS
  (`0x72`, `0x73`) answers only after PIIX4 configuration (bus 0, device 4, function 0, offset `0xcb`) has bit 2 set, and the SGI HAL
  sets it before each extended access ([nt-hal.md](nt-hal.md#follow-on-corrections-and-additions)).
- Our HAL must: implement `HalQueryRealTimeClock` the same way, and `HalSetRealTimeClock` as in HR-EXP-11: registers 0, 2, 4, 6, 7, 8 and 9 in BCD
  with bit 7 of register `0x0b` set around the writes and then cleared, and no century byte.
- Guest sees: the system date at boot. An out-of-range CMOS gives 1 January 1998.

## 4. Inter-processor interrupts, NMI and cache operations

#### HR-IPI-01 Kernel IPI
- Grade: established (`HalRequestIpi` at `0x80012c64`).
- Fact: with interrupts off, wait for delivery status clear in the command register (`+0x300` bit 12), write `+0x310` = mask << 24, then `+0x300` =
  `0x8e1` (fixed, logical, vector `0xe1`), then poll status again before restoring flags. High word first, low word triggers. Each poll is a
  counted loop of `0x5000` reads. When the count runs out, the code executes `int3` and then jumps back to the same read with a counter that
  has already reached zero, so the next lap runs about 2^32 reads before the next `int3`. There is no exit and no error return. The target runs begin,
  `KiIpiServiceRoutine`, end at the IPI level ([hot path](hal-hot-path.md#one-inter-processor-interrupt)).
- Our HAL must: implement `HalRequestIpi` that way. A stuck delivery-status bit must break into the debugger or bug check. The SGI loop
  does neither usefully, and a model whose bit never clears hangs a processor.
- Guest sees: cross-processor calls from the kernel (TLB shootdowns, DPC kicks).

#### HR-IPI-02 Broadcast call
- Grade: established (`HalpGenericCall` at `0x800129d4`, the receiver poll at `0x80012a74`, the service entry at `0x80012928`).
- Fact: the caller first runs the receiver poll itself, then takes a busy flag with `lock bts` on the dword at `0x80020534`. It stores the
  function, the context and the target processor mask at `0x80020538`, `0x8002053c` and `0x80020540`. A zero mask returns at once. Otherwise
  it writes `+0x310` = mask << 24 and `+0x300` = `0x8c1` (vector `0xc1`, fixed, logical), each after a delivery-status poll that is the same `0x5000`-read loop with `int3` and an unbounded retry as in HR-IPI-01 (no exit), enables interrupts and keeps
  running the receiver poll until the mask word is zero, then clears the busy flag. Each receiver, in the interrupt
  service routine or in the caller's own wait loop, ANDs its logical-id bit (the dword at offset `0x48` of its processor control region) against the
  mask, removes the bit with a locked AND, and calls the function with the context. The vector handler runs at the broadcast level `0x1b`: begin,
  poll, End. `HalAllProcessorsStarted` uses it (HR-EXP-04).
- Our HAL must: provide a service that runs a function on selected processors with this handshake or an equivalent one with the same
  caller-visible contract: it returns after every selected processor has taken the call.
- Guest sees: nothing named. The mechanism backs `HalAllProcessorsStarted` and cache flushing.

#### HR-IPI-03 Cache-operation requests
- Grade: unknown for the mechanism, established that the SGI HAL exports flush routines and polls (`CACHEOPPOLL`).
- Fact: Cobalt CPU status bit 0 is a cache-operation interrupt. The SGI HAL treats it as unexpected on the clock path and clears it
  with a write of `0xfffffffe`. Cobalt Lite has no cache-operation invalidate. `HalxFlushMdl`, `HalxFlushPhysicalBuffer` and
  `HalxFlushVirtualBuffer` are the three routines the SGI graphics driver calls through class `0x8100001`
  ([Cobalt page](../../devices/cobalt/README.md#cpu-block-status-and-the-memory-controller-block-established-for-what-the-hal-touches),
  [question](../../questions/visws-hal-requirements-open.md#cache-operation-interrupt-and-the-flush-routines)).
- Our HAL must: provide the three routines with `wbinvd`-class flushes as a documented fallback. The Cobalt invalidate mechanism is not modelled
  until a source says what raises status bit 0.
- Guest sees: DMA to and from graphics memory looks coherent to the SGI driver.

#### HR-NMI-01 NMI entry set-up
- Grade: established for the writes, unknown for bit 17.
- Fact: entry 29 (28 on Lite) is written as `0x8ff`, logical destination mode, high word = `1 << processor number` in bits 31:24, read
  back. If bit 17 reads set, the HAL masks the entry and prints "Failed to set NMI". Otherwise it adds delivery mode NMI (`0x400`)
  to the value it read. On NMI set-up the high word's low 24 bits are uninitialised stack contents in the SGI HAL
  ([nt-hal.md](nt-hal.md#cobalt-registers-the-hal-programs), [question](../../questions/visws-hal-open.md#meaning-of-bit-17-of-an-interrupt-entrys-low-word-and-of-the-remote-irr-bits-writability)).
- Our HAL must: write the high word fully (only bits 31:24 set) and keep the bit-17 check. Writing the readback value plus `0x400`
  preserves reserved bits as the shipped HAL does.
- Guest sees: an NMI on a bit-17 failure leaves the machine without NMI support and prints the message.

#### HR-NMI-02 NMI handler
- Grade: established for the order (`HalHandleNMI` at `0x8001a540`, `HalpHandleCoNMI` at `0x80016390`), unknown for what raises the sources.
- Fact: `HalHandleNMI` calls the power-management NMI check first (`0x8001ecf0`). That check reads port `0xfb0`. If bit 2 is set it writes port
  `0xff3` = `0xfe` and returns false ("not a power NMI"). Otherwise it either sends the stop-grant special cycle through bridge B (HR-PWR-04) or writes
  ports `0xff1` = `0xca`, `0xff0` = `0xba`, and returns true. The handler prints that the system halted and breaks into the debugger. It then
  calls `HalpHandleCoNMI`, which reads Cobalt entry `0x1d` (on every board, Lite included), prints a message when bit 14 is clear, clears bit
  14 and writes the entry back, re-reads it, and returns false if bit 14 is still set (a second debugger break follows). What raises port
  `0xfb0` bit 2 and what ports `0xff0` to `0xff3` are is unknown
  ([question](../../questions/visws-hal-open.md#what-raises-cobalt-entry-29-and-what-ports-0xff0-to-0xff3-are)).
- Our HAL must: mirror the sequence on a real NMI and keep the unknown port writes behind a clear note, as the shipped HAL does. Read entry
  `0x1d` or the Lite entry `0x1c` consistently. The shipped HAL always reads `0x1d`, which looks like a defect on Lite boards
  ([nt-hal.md](nt-hal.md#cobalt-registers-the-hal-programs)).
- Guest sees: a stop in the debugger, or a halt message. The shipped HAL does not bug check here. Microsoft's page for stop code `0x80` only
  says a hardware malfunction caused it, so that an unclaimed NMI ends there is our reading, not Microsoft's (HR-XP-13).

## 5. Starting the other processors

#### HR-SMP-01 Start sequence
- Grade: established.
- Fact: build a real-mode stub below 1 MiB and a page-table image with low memory identity-mapped. Save and set the warm-reset vector
  at `0x467`, CMOS `0x0f` = `0x0a`. Send INIT (`0xc500`) and deassert (`0x8500`) to the Nth enabled non-bootstrap entry's id. If the
  first entry's APIC version byte is nonzero, send two startup IPIs (`0x600` plus the stub page) a short delay apart, waiting for
  delivery-status clear between steps. Then wait a bounded number of times for the other processor to flag itself in a shared block, and restore `0x467` and CMOS `0x0f`
  ([nt-hal.md](nt-hal.md#multiprocessor-start-up)).
- Our HAL must: follow the sequence. On XP x64 the stub starts in real mode and enters long mode, so the stub and the shared block
  are rewritten for that mode. The IPIs and the warm-reset use are the same.
- Guest sees: every enabled processor in the table appears. `ONECPU` suppresses them.

#### HR-SMP-02 Processor state on entry
- Grade: unknown for the microcode and MTRR state the firmware leaves on the other processors, established for the local APIC
  set-up (HR-INT-10).
- Fact: the firmware parks the other processors with INIT after it records them. The start stub's local vector table settings
  are unknown ([boot-path.md](boot-path.md#legacy-bios-and-the-acpi-tables), last bullet).
- Our HAL must: program each processor's local APIC itself and not rely on any vector table the firmware wrote. It copies the
  boot processor's MTRRs and PAT to the others before they run OS code, which is the usual rule and our own design.
- Guest sees: processors with matching cache settings.

#### HR-SMP-03 Restart of one processor
- Grade: established.
- Fact: `HalpResetThisProcessor` masks that processor's local APIC sources. The boot processor then clears the CMOS shutdown byte,
  writes `0x1234` to `0x472`, re-arms the entries it owns and pulses the keyboard controller reset (`0xfe` to port `0x64`).
- Our HAL must: reproduce it for the restart path that returns to firmware. HR-PWR-01 covers the reset write itself.
- Guest sees: a restart that comes back to firmware.

## 6. PCI bus access, DMA and resources

#### HR-PCI-01 Configuration access through the bridge windows
- Grade: established for the HAL's use, unknown for whether ports `0xcf8` and `0xcfc` reach the same cycles.
- Fact: the address word is at window `+0xf8` and data at `+0xfc`, with the byte or halfword lane chosen by the low address bits.
  The address word has bit 31 set, bus in bits 23:16, device in 15:11, function in 10:8 and the dword register in 7:2. Each access raises
  to the highest level and takes a spin lock (skipped while writing a crash dump). After each access the HAL writes `0x2000` to the
  bridge's own status halfword at `+0x06` (clears received master abort). A slot judged absent reads all ones without touching the bus
  ([Lithium](../../devices/lithium/README.md#the-bridge-window-established)).
- Our HAL must: use the windows exclusively and ignore ports `0xcf8` and `0xcfc` for configuration. Bridge A is at `0xfc000000` and bridge B at `0xfd000000`.
- Guest sees: PCI devices enumerate. Whether `0xcf8` also works is an emulator question.

#### HR-PCI-02 Bus numbering and bridge words
- Grade: established for NT, unknown for what the firmware leaves.
- Fact: the HAL gives bridge B bus 0 and bridge A bus 1 (the firmware does the same). The bus-number word is at `+0x44` (low byte bus,
  next byte subordinate) when the byte at `+0x08` is above zero, or the top byte of `+0x40` at revision zero. The HAL writes
  `0xffff` to the bridge command halfword at `+0x04` and `0xf800` to the status halfword at `+0x06`, with subordinate `0xff`, then once more
  for bridge B alone with the highest bus found ([nt-hal.md](nt-hal.md#pci-numbering-and-resource-assignment)).
- Our HAL must: do the same and expose bridge B as the root with bus 0. A PCI-to-PCI bridge on bus 0 takes number 1 and pushes bridge A
  up, which is unverified on hardware.
- Guest sees: the PIIX4 on bus 0 and the Ethernet on bus 1.

#### HR-PCI-03 Host bridge windows
- Grade: inferred (read from the static records and the translation routine, not from a bridge specification).
- Fact: each bridge has a 64 MiB non-prefetchable memory range at PCI `0x80000000` to `0x83ffffff`, translated to system `0xf4000000`
  (B) and `0xf0000000` (A). The I/O ranges are `0x0000` to `0x7fff` (B) and `0x8000` to `0xffff` (A), with a system-side offset
  that the HAL zeroes before enumeration. There is no prefetch range. The firmware's root bridge records use I/O bases `0x1000`
  (B) and `0x9000` (A). How the bridges decode these is unknown ([Lithium page](../../devices/lithium/README.md),
  [question](../../questions/visws-hal-requirements-open.md#host-bridge-ranges-as-the-pnp-manager-needs-them)).
- Our HAL must: report these ranges as the resources of each root bus and translate bus addresses through them, so the PnP manager
  can assign BARs. The ranges are the minimum, and a guest that needs more has no other source.
- Guest sees: BARs placed at `0x80000000` and up on both buses, I/O below `0x10000`.

#### HR-PCI-04 Resource assignment
- Grade: established for the SGI HAL, unknown for whether firmware assigns endpoint resources.
- Fact: the SGI HAL disables decoding, probes each BAR, rejects non-power-of-two masks, raises sizes below 4 KiB to 4 KiB, sorts largest
  first and assigns from the bus's remaining range. `PCILOCK` keeps the firmware's assignment for devices already enabled. Under XP
  the PnP manager and the PCI bus driver do this; the HAL only supplies ranges and translation ([nt-hal.md](nt-hal.md#pci-numbering-and-resource-assignment),
  [question](../../questions/visws-firmware-open.md#memory-programming-graphics-split-and-pci-resources)).
- Our HAL must: not assign BARs itself on XP, and must leave devices alone until the PCI driver does. It keeps a legacy
  `HalAssignSlotResources` for old drivers (HR-XP-04).
- Guest sees: devices resourced by PnP. A device the firmware already enabled keeps its BARs only if `PCILOCK` is honoured or the PCI driver respects them.

#### HR-PCI-05 PCI-to-PCI bridge programming
- Grade: established.
- Fact: standard bridge set-up written as one 64-byte image: bus numbers at `+0x18` to `+0x1a`, I/O base and limit, memory base
  and limit, prefetchable base and limit, status cleared, bridge control 0, command with the range enables and bus master
  ([nt-hal.md](nt-hal.md#power-management-nmi-and-pci-bridge-set-up)). Nothing is Cobalt-specific.
- Our HAL must: leave this to the generic PCI driver. Only the pin swizzle in HR-INT-06 is platform knowledge.
- Guest sees: cards behind a bridge in a slot of bridge B. Behaviour on hardware is unverified.

#### HR-PCI-06 Slot to device number
- Grade: unknown ([question](../../questions/visws-hal-open.md#which-physical-pci-slot-is-which-device-number)).
- Fact: five device numbers per bridge are wired for interrupts. Which are physical slots on a 320 and a 540 is not shown by any source held.
- Our HAL must: not hard-code a slot label. The PCI driver reports the location it enumerates.
- Guest sees: device locations as "PCI bus n, device d". A friendly slot name is not available.

#### HR-PCI-07 Bridge error status
- Grade: inferred for `+0x48` (another driver writes all ones and prints it as an error status), unknown for the rest
  ([Lithium page](../../devices/lithium/README.md#the-bridge-window-established)).
- Fact: no software reads an error register to act on it. The SGI HAL clears the master-abort bit after each access.
- Our HAL must: clear the master-abort bit after each configuration access as above, and treat any other error reporting as absent.
- Guest sees: a probe of an empty slot returns all ones and nothing else.

#### HR-PCI-08 DMA adapters and map registers
- Grade: established for the SGI HAL's design, unknown for what the bridges do with a master's address.
- Fact: the SGI HAL has no scatter-gather or IOMMU for this machine. It uses the stock x86 PC HAL's adapters: ISA/EISA 8237 channels
  (page registers at the standard ports) and master adapters with map registers backed by a contiguous buffer below 16 MiB (64 KiB,
  192 KiB with memory above 16 MiB), growing in 64 KiB steps. Common buffers are contiguous memory below the adapter's mask.
  Cache flushing around DMA goes through HR-IPI-03 ([nt-hal.md](nt-hal.md#dma)). Firmware sets coherent-DMA and stream-buffer bits in
  the Lithium registers at `+0x60` to `+0x70` before the OS runs, and the HAL never touches them
  ([boot-path.md](boot-path.md#pci-bus-numbering-and-windows)).
- Our HAL must: implement the XP DMA adapter operations (HR-XP-06) on that basis. It must not clear or rewrite the firmware's Lithium
  DMA bits. Whether bus masters can reach above 16 MiB or 4 GiB is unknown, so buffers over 16 MiB are copied as in the SGI HAL.
- Guest sees: IDE and SCSI DMA through bounce buffers when a buffer sits high.

#### HR-PCI-09 The PIIX4 devices and standard ports
- Grade: established for what the HAL touches, software expectation for the rest.
- Fact: the 8259 pair, 8237 DMA at the usual ports (floppy and parallel use it), CMOS, and the NS87307 at `0x2e` and `0x2f`. The HAL
  initialises the NS87307 (`Ns307InitChip`). The values `0x0fc0` (GPIO) and `0x0fc8` (power management) are not immediates in the HAL. At
  `0x8001aac0` it selects logical devices 7 and 8 and reads each one's base from registers `0x60` and `0x61`, storing the results at `0x80028602` and
  `0x80028608`. The values come from the firmware's boot block (step `0x10`, [boot-path.md](boot-path.md#boot-into-nt) and the boot-block table) and from Linux's `setup.c`. The PIIX4's power-management block is at
  `0xf80`, set by firmware through function 3 offset `0x40` ([boards-320-540.md](../../platforms/visws/boards-320-540.md#the-byte-at-port-0xfb2)).
- Our HAL must: initialise the 8259s as in HR-INT-08, run the NS87307 initialisation, and never program the PM base.
- Guest sees: legacy ports as on a PC, with the 8259 behind Cobalt entry 12.

## 7. Memory errors and ECC

#### HR-MEM-01 ECC enable
- Grade: established for the writes, unknown for what the registers do beyond ECC.
- Fact: the memory block at `0xc6000000`: `+0x00` bit 0 enables ECC. CPU control `+0x10` bit 0 is the matching bit. The HAL clears both at
  start-up and sets both only if the board is not Cobalt Lite (revision `0xa0` or `0xa8`), `MEMERR` is on and `ECC` is on. A Lite
  board prints "ECC checking DISABLED on Cobalt Lite" ([registers](../../devices/cobalt/registers.md)).
- Our HAL must: enable only under those three conditions. The reset values of these registers are unknown
  ([question](../../questions/visws-firmware-open.md#memory-programming-graphics-split-and-pci-resources)), so the HAL clears first.
- Guest sees: ECC reporting on a populated board.

#### HR-MEM-02 Memory error interrupts
- Grade: established for the entries, inferred for what the status bits mean.
- Fact: Cobalt entries `0x1a` and `0x1b` carry memory errors (vectors `0xf1` and `0xf2` in the SGI HAL), enabled except on Lite. Status
  is at memory-block `+0x18`, address `+0x28`, syndrome `+0x30`. The error is non-fatal when bit 16 is set, or bit 17 is set and the
  syndrome is zero. Anything else is fatal. Status is cleared by writing zero.
- Our HAL must: apply the same test, keep the entries masked on Lite, and clear the status after logging.
- Guest sees: a non-fatal error is logged. A fatal one stops the machine (HR-MEM-03).

#### HR-MEM-03 Fatal error handling
- Grade: established.
- Fact: the HAL displays a message ("Invalid Address", "Hard ECC error", "MULTIPLE MEMORY ERRORS"), turns checking off, calls SGI callback slot 0
  with the address and status, logs to CMOS and bug-checks with code `0x80` ([nt-hal.md](nt-hal.md#cobalt-registers-the-hal-programs)).
  The CMOS log's layout is not described.
- Our HAL must: bug check `0x80` (NMI_HARDWARE_FAILURE, HR-XP-13) after the same steps. The CMOS log layout is ours, noted as such.
- Guest sees: a stop screen with the message on the display.

#### HR-MEM-04 Corrected errors and callbacks
- Grade: established that the SGI HAL does not rewrite the location, unknown whether hardware scrubs.
- Fact: a non-fatal error with a nonzero syndrome calls `HalpCorrectSoftEccError`, which builds a pointer from the page offset and a
  syndrome-byte offset and executes a locked add on its own stack slot. No read or write of the mapped location happens.
  Callback slot 1 gets the HAL's error log block. Callback registration takes an id of 0 or 1, rejecting others with `0xc000000d`
  and bad addresses with `0xc0000141` ([nt-hal.md](nt-hal.md#follow-on-corrections-and-additions)).
- Our HAL must: count and log the error. It does not claim the data was corrected, and must not depend on a write-back.
- Guest sees: a counter of corrected errors. Persistent ones go unscrubbed.

## 8. Power management and reboot

#### HR-PWR-01 Reboot
- Grade: established (the board test at `0x80018530`, the reboot routine at `0x80018560`).
- Fact: the board test returns false, so the Cobalt reset is used, for the 320 (SYS TYPE 0) with BOARD REV below `0xc`, and for the 540
  (SYS TYPE 1) with BOARD REV 0. Every other board gets a write of `0x06` to port `0xcf9`. The Cobalt path sets bit 0 of CPU-block register
  `+0x18`. So 320 generation 2 (revisions 6 to 11) takes the Cobalt path too, as does generation 1.
- Our HAL must: apply that exact condition from the two bytes in HR-ARC-01.
- Guest sees: a restart through firmware.

#### HR-PWR-02 Soft power button
- Grade: established for the SGI HAL's sequence, unknown how the event reaches XP's power manager without ACPI
  ([question](../../questions/visws-hal-requirements-open.md#power-button-and-soft-off-without-acpi)).
- Fact: the PIIX4 power-management block is at `0xf80` (status `+0`, enable `+2`, control `+4`). The SGI HAL clears the status, writes enable
  `0x100` (power button) and control 1. Its handler runs on the vector for ISA IRQ 9 at level `0xb1`, acknowledges and calls the suspend
  routine, and more than nine errors disable the interrupt and bug-check `0x80`.
- Our HAL must: arm the button, route IRQ 9 as in HR-INT-09 and turn a press into a clean shutdown request.
- Guest sees: a press starts a shutdown or a stop.

#### HR-PWR-03 Power off
- Grade: established for the SGI HAL's writes (`HalpPwrMgmtSuspend` at `0x8001f1b0`). The order that includes a stop-grant is our design.
- Fact: the routine writes CMOS `0x61` = `0x5a`, reads CMOS `0x60`, and if that reads `0x49` ('I') sets or clears bit 0 of port `0xfb5` (set below
  board revision `0x20`). It then writes `0x2000` (suspend enable, type 0) to port `0xf84`. It sends no stop-grant cycle and does not clear the
  status register. The only stop-grant send in the image is in the NMI handler (HR-PWR-04). Linux sends the cycle after the control write and
  the firmware's main module sends it too ([boot-path.md](boot-path.md#pci-bus-numbering-and-windows)). Port `0xfb5` bit 0 is PIIX4 output pin GPO8.
  What SGI wired to it is unknown ([boards-320-540.md](../../platforms/visws/boards-320-540.md#the-byte-at-port-0xfb2)).
- Our HAL must: write the `0x2000` control word as the shipped HAL does, and send the stop-grant cycle (HR-PWR-04) only because Linux and
  the firmware do. That order (status clear, stop-grant, `0x2000`) is our design and is untested on hardware. The CMOS test and the `0xfb5` write
  are copied only if a guest shows they are needed.
- Guest sees: the machine powers off. Whether the PIIX4 needs the stop-grant first is a hardware question the shipped NT path never answers.

#### HR-PWR-04 Stop-grant special cycle
- Grade: software expectation (Linux and the firmware send it) for its use in power off. Established that the shipped HAL sends it only from the
  NMI handler, inferred that the value is a stop-grant encoding.
- Fact: write `0x8000ff00` to bridge B's address register at `+0xf8` (bus 0, device 31, function 7, the special-cycle encoding), then
  `0x00120002` to the data register at `+0xfc`. The SGI HAL does this in the power-management NMI routine (`0x8001ecf0`) only when the byte at bridge B's
  window `+0x08` (its revision) is nonzero. When it is zero the routine writes ports `0xff1` = `0xca` and `0xff0` = `0xba` instead. Neither
  `HalpPwrMgmtSuspend` nor `HalReturnToFirmware`'s power-down path sends it. Linux and the firmware send the same pair
  ([boot-path.md](boot-path.md#pci-bus-numbering-and-windows)).
- Our HAL must: send it through bridge B's window, not through `0xcf8`, from the NMI path as the SGI HAL does, and from power off if
  hardware needs it.
- Guest sees: nothing on its own.

#### HR-PWR-05 Halt, power down and restart through `HalReturnToFirmware`
- Grade: established (`HalReturnToFirmware` at `0x80016dc0`).
- Fact: the routine switches on an action value 0 to 3. Action 0 (halt) executes one `hlt` and returns. Action 1 (power down) calls
  `HalpPwrMgmtSuspend` (HR-PWR-03). Actions 2 and 3 (restart, reboot) run two helpers and then the reboot routine of HR-PWR-01. Any other value
  prints a message and breaks into the debugger. Microsoft lists the routine as "not supported and should not be used" for drivers (HR-XP-16).
- Our HAL must: export it with those four actions. Halt must not spin with interrupts off. The shipped code returns after one `hlt`.
- Guest sees: a stopped machine after halt, a power-off or a restart for the other actions.

## 9. Debug output and the console

#### HR-DBG-01 Display console
- Grade: established for the SGI HAL, XP behaviour cited.
- Fact: the HAL's console is the display back end at `0xd0000000` (`0xa0` pages), not VGA text. It reads the flat-panel identity over
  I2C, builds a frame buffer in the first graphics bank (at most 1 MiB, height cut to fit), stops the display engine if running,
  fills a 32-word table at `+0x48000` with 3 and the colour map at `+0x60000` with a grey ramp, and starts it. VGA text routines exist
  at `0xb8000` and are unreachable ([nt-hal.md](nt-hal.md#boot-display-and-graphics-memory),
  [display engine](../../devices/cobalt-graphics/display-engine.md)). The I2C layers were not read.
- Our HAL must: not depend on this console. XP's boot text comes from a boot video driver (HR-XP-08), so a Cobalt boot video driver is a
  required companion to the HAL.
- Guest sees: boot text and stop screens only if that driver exists.

#### HR-DBG-02 Serial console and debugger port
- Grade: established for the UARTs and for the HAL's exports, software expectation for the HAL's use.
- Fact: `serial(0)` is the 16550-compatible port at `0x3f8` (IRQ 4) and `serial(1)` at `0x2f8` (IRQ 3). Both are NS87307 UARTs that the
  firmware activates. `HALOUT` picks screen, `COMn` (default 19200) or none. The NT 4.0 HAL exports the debug-port routines `KdPortInitialize`,
  `KdPortGetByte`, `KdPortPollByte`, `KdPortPutByte`, `KdPortRestore` and `KdPortSave` (ordinals 66 to 71) and the variable `KdComPortInUse`
  (ordinal 65, at `0x800211a0`, a data export). Chappell lists the `KdPort*` exports as removed after 5.0 ([boot-path.md](boot-path.md#serial-output-before-the-console)).
- Our HAL must: not carry a debug-port driver, and export `KdComPortInUse` (HR-DBG-04). The HAL's obligation is port I/O for the transport
  module and a working 16550 with the NS87307 enabled.
- Guest sees: `/DEBUG` over COM1 works with the stock transport if the NS87307 UART is live. This is untested.

#### HR-DBG-04 `KdComPortInUse`
- Grade: established that SGI's HAL exports it (ordinal 65, data export). Unknown whether XP's transport module imports it.
- Fact: the export table of `halborg.dll` lists `KdComPortInUse` as a variable at `0x800211a0`. Chappell's export table lists `KdComPortInUse` as a variable (data) export, and the NirSoft entry for the Windows 10 `kdcom.dll` shows it linked against `HAL.dll`. Together with the re-review, that confirms the Windows 10 import. No XP-era import list was checked, so it is unconfirmed for XP.
- Our HAL must: export the variable. A missing export fails the transport module's load. Its value must say whether the port is claimed by the debugger.
- Guest sees: a failed kernel debugger connection on COM1 if the export is missing.

#### HR-DBG-03 The `BREAK` option and ARC dump
- Grade: established.
- Fact: `BREAK` enters the debugger at start-up. `ARCINFO` dumps the ARC tree to the debug port.
- Our HAL must: keep `BREAK`. The tree dump has no XP counterpart unless the loader supplies a tree (HR-ARC-01).
- Guest sees: the debugger at first instruction.

## Further routines and exports

Added after review. Each row gives the export, what the shipped code does where it was read, and what ours must do. Unread items are
marked *unknown*. The full export list of `halborg.dll` 1.3 is 93 names, from which these are the ones the earlier sections do not cover.

#### HR-EXP-01 `HalProcessorIdle`, `KeFlushWriteBuffer`, `HalMakeBeep`
- Grade: established (`0x80017330`, `0x80019220`, `0x80016d30`).
- Fact: `HalProcessorIdle` is `sti; ret`. `KeFlushWriteBuffer` is a bare `ret`. `HalMakeBeep` touches no hardware: it returns true only for
  a frequency of zero, and false for any other value.
- Our HAL must: export all three with that behaviour. A halt in the idle routine is allowed if interrupts stay enabled.
- Guest sees: no beep. Idle returns at once.

#### HR-EXP-02 `HalReadDmaCounter`
- Grade: established for the shape, unknown for the full ISA channel mapping (`0x80017b50`).
- Fact: when the byte at offset `0x4d` of the adapter record is 1 it takes the 8-bit DMA controller path: it clears the 8237 flip-flop with a write
  to base + `0xc` and reads the channel's count (`base + channel * 2 + 1`, low then high byte), repeating until two reads agree. Otherwise it takes the
  16-bit path: flip-flop at base + `0x18`, count at `base + channel * 4 + 2`. What the byte means for the adapter kind was not traced.
- Our HAL must: read the 8237 count on both controller paths. Master adapters have no 8237 count, so the value we return for them is our design. Obsolete in current docs (`HalReadDmaCounter` has a replacement, `ReadDmaCounter`).
- Guest sees: floppy and parallel DMA progress.

#### HR-EXP-03 `HalInitializeProcessor` and the multiprocessor phases
- Grade: established (`0x8002e2f0`, `HalpInitMP` at `0x8002f210`).
- Fact: `HalInitializeProcessor(n)` runs with interrupts off. It stores `-1` at offset `0x30` of the processor control region and 100 at `0x4c` (the
  stall factor, HR-CLK-07), and sets the processor number in the control block. On processor 0 it maps the local APIC (`0xfee00000` at `0xfffe0000`) and the
  Cobalt CPU (`0xc2000000`), memory (`0xc6000000`) and interrupt (`0xc4000000`) blocks, one page each. For every processor it raises the IRQL to
  `0x1f`, ORs `1 << n` into the started-processor mask at `0x80028aa4` and calls the interrupt initialiser. `HalpInitMP(phase)` counts phase-1 calls,
  and in phase 0 maps physical page 0 and allocates a page below 1 MiB for the start stub. For a nonzero phase on a nonzero processor it sets the
  IPI-clock flag (`0x80020225` = `0xff`) ([nt-hal.md](nt-hal.md#follow-on-corrections-and-additions)).
- Our HAL must: do the same work in whichever order XP's initialisation phases require (the phase contract is in the note after the XP table).
- Guest sees: each processor reaching idle.

#### HR-EXP-04 `HalAllProcessorsStarted`
- Grade: established (`0x8002f280`, `0x8002f780`).
- Fact: on processor 0 only (a byte at offset `0x51` of the control region is zero), when CPU feature bit 0 is set it broadcasts, through
  the generic call (HR-IPI-02), a routine that writes `0xa0fe` to the local APIC performance-counter LVT (`+0x340`: vector `0xfe`, level, active
  low, unmasked) on every started processor. When feature bit 1 is set it overwrites the `cpuid` at `0x800114e4`, the third instruction of the stall routine, with a register move (HR-CLK-07). It
  returns true.
- Our HAL must: do the same, and enable the performance-counter vector only after all processors run.
- Guest sees: performance-counter interrupts, if a driver registers the hook of HR-ARC-07.

#### HR-EXP-05 `HalBeginSystemInterrupt`, `HalEndSystemInterrupt`
- Grade: established (`0x800135a8`, `0x80013538`).
- Fact: the HAL's own broadcast service calls Begin with (IRQL, vector, a pointer for the old level) at `0x800129bc`. The End call's arguments were not decoded. The accesses and
  order are in the [hot-path page](hal-hot-path.md#one-device-interrupt-cobalt-entries-other-than-the-clock-nmi-and-memory-error-entries).
  Both are HAL exports only on x86. On x64 the kernel owns this path (HR-XP-11).
- Our HAL must: keep the TPR-and-EOI order of HR-INT-07 for XP. The XP x64 kernel dispatch contract is not established
  (HR-XP-17).
- Guest sees: nothing directly.

#### HR-EXP-06 Display exports
- Grade: established for the path, unread for the drawing routines (`HalAcquireDisplayOwnership` at `0x80018610`, `HalDisplayString` at `0x80018670`,
  `HalQueryDisplayParameters` at `0x80018730`, `HalSetDisplayParameters` at `0x80018780`).
- Fact: `HalAcquireDisplayOwnership` stores a reset-display callback at `0x80028a9c` under a spin lock. The store is the only direct reference to that address (reader not found, so what calls it is unknown). `HalDisplayString` prints to the debug port only, with the
  message "Console OUT not yet initialized", until the display-ready byte (`0x80028aa0`) is 1. Then it takes the display lock and, per character, writes
  to the screen when bit 31 of the output-mode word is set and to the COM port when bit 30 is set. Query and set parameters pass through the
  screen routines when the screen is selected. Under XP, boot text is the boot video driver's job (HR-DBG-01, HR-XP-08).
- Our HAL must: export all four. `HalDisplayString` forwards to the XP boot-video path. Owner hand-off calls the stored callback.
- Guest sees: HAL messages on the debug port or the screen.

#### HR-EXP-07 Partition and drive-letter exports
- Grade: established that they are wrappers (`IoReadPartitionTable` `0x8002b330`, `IoSetPartitionInformation` `0x8002b350`,
  `IoWritePartitionTable` `0x8002b370`, `IoAssignDriveLetters` `0x8002b310`).
- Fact: each calls through a table the image imports at `0x80010350`: offset `0x18` for `IoAssignDriveLetters`, `0x1c` for `IoReadPartitionTable`, `0x20` for `IoSetPartitionInformation` and `0x24` for `IoWritePartitionTable`. The table is presumably the kernel's `HalDispatchTable` (inferred from the import). Chappell lists
  `IoAssignDriveLetters` as exported to 6.0 and the other three also from the kernel starting at 5.1.
- Our HAL must: export them as wrappers that call the kernel's versions. No hardware is involved.
- Guest sees: disk partition handling as on any PC. The role under XP is Chappell's table only.

#### HR-EXP-08 Common-buffer and crash-dump DMA exports
- Grade: established for the set, unknown for the code (`HalAllocateCommonBuffer` `0x80016e80`, `HalFreeCommonBuffer` `0x80016fe0`,
  `HalFlushCommonBuffer` `0x80016fd0`, `HalAllocateCrashDumpRegisters` `0x80017530`, `IoMapTransfer`, `IoFlushAdapterBuffers`, `IoFreeMapRegisters`,
  `IoFreeAdapterChannel`, `HalAllocateAdapterChannel`).
- Fact: the map-register design is in HR-PCI-08. Microsoft lists the common-buffer and adapter-channel routines as obsolete or reserved for system use (HR-XP-04).
- Our HAL must: keep them for old drivers and implement crash-dump registers so a dump can use the same adapter. The crash-dump path with
  our own map buffer is untested.
- Guest sees: a crash dump written to disk.

#### HR-EXP-09 Bus data and address translation for the internal and ISA buses
- Grade: established for the dispatch, unknown for the ISA and internal handlers' routines (`HalGetBusData` `0x8001fc30`,
  `HalGetBusDataByOffset` `0x8001fc60`, `HalTranslateBusAddress` `0x8001fd30`).
- Fact: each looks up the bus handler for the bus type and number, calls the handler's routine through its table (translation at offset
  `0x48`), then releases the handler, and returns false when no handler exists. `HalGetBusData` calls `HalGetBusDataByOffset` with offset 0. The
  PCI handlers are in HR-PCI-01 to 03.
- Our HAL must: provide handlers for the internal bus, the ISA bus and PCI. The internal bus's "level" is the Cobalt entry number (HR-INT-05).
- Guest sees: old drivers that call these routines find their devices.

#### HR-EXP-10 Spin-lock, IRQL and port exports
- Grade: established for the export list, mostly unread for the code.
- Fact: the x86 HAL exports `KeRaiseIrql`, `KfRaiseIrql`, `KfLowerIrql`, `KeLowerIrql`, `KeGetCurrentIrql`, `KeRaiseIrqlToDpcLevel`, `KeRaiseIrqlToSynchLevel`, the
  `KeAcquireSpinLock` family and `READ_PORT_*` and `WRITE_PORT_*` in all widths and buffer forms, plus `ExAcquireFastMutex` and its two partners. The IRQL
  routines are the TPR accesses of HR-INT-11. On x64 the kernel exports the IRQL and spin lock routines and the HAL does not (HR-XP-11).
- Our HAL must: export the x86 set for XP and none of the IRQL or lock routines for XP x64.
- Guest sees: nothing named.

#### HR-EXP-11 Real-time clock write
- Grade: established (`HalSetRealTimeClock` at `0x800194f0`).
- Fact: it sets bit 7 of CMOS register `0x0b`, writes BCD seconds, minutes, hours, day of week (register 6), day, month and the year modulo 100 into
  registers `0`, `2`, `4`, `6`, `7`, `8` and `9`, then clears bit 7 of register `0x0b` (mask `0x7f`). It writes no century byte. The
  read routine is HR-CLK-08.
- Our HAL must: do the same. An RTC with a century register is not modelled.
- Guest sees: the system date persists across a restart.

#### HR-EXP-12 Flash environment code
- Grade: established for the exports, unknown for the rewrite and the default table (`HalGetEnvironmentVariable` `0x8001bed0`,
  `HalSetEnvironmentVariable` `0x8001bd60`).
- Fact: HR-ARC-06 covers it. The checksum and the block rewrite are in the open question
  ([visws-firmware-open.md](../../questions/visws-firmware-open.md#the-environment-block-hal-side-and-defaults)).
- Our HAL must: not write the flash until the rewrite is read.
- Guest sees: graphics memory changes work only if the write works.

#### HR-EXP-13 `HalpHandleCoNMI`
- Grade: established. See HR-NMI-02, which now carries the whole sequence.
- Fact: the routine reads Cobalt entry `0x1d` on every board.
- Our HAL must: see HR-NMI-02.
- Guest sees: see HR-NMI-02.

## What XP and XP x64 expect that NT 4.0 did not

Source rule: Microsoft documentation (the WDK pages on Microsoft Learn), Microsoft's own published articles, and public third-party
reference work on the shipped files when no Microsoft statement exists. Each row says which kind. What could not be checked says so.
Learn pages describe current Windows, so a row marked "current docs" needs a check against the XP-era DDK before relying on it.

| # | Expectation | Source | Consequence for our HAL | Status |
|---|---|---|---|---|
| HR-XP-01 | Setup installs one HAL under the name `hal.dll`, and a `/HAL` switch in `boot.ini` can pick another | [Chappell, HAL variants](https://www.geoffchappell.com/studies/windows/km/hal/history/index.htm) (third-party study of shipped files) | Ours ships as `hal.dll` with an installer entry. SGI's `txtsetup.sif` machine-type entry shows the NT mechanism ([nt-drivers.md](nt-drivers.md)). | verified in a secondary source |
| HR-XP-02 | 32-bit XP ships seven HALs. Three are ACPI (`halacpi.dll`, `halaacpi.dll`, `halmacpi.dll`) and four are not (`hal.dll`, the standard PC HAL, `halapic.dll`, `halmps.dll`, `halsp.dll`). Server 2003 has six, three of them non-ACPI (`halsp.dll` is not in it). The ACPI split is Chappell's, inferred from the internal HAL name strings. | [Chappell, HAL variants](https://www.geoffchappell.com/studies/windows/km/hal/history/index.htm) (third-party study of shipped files). KB 309283 (HAL options after Setup, a BetaArchive copy) was seen only in a search summary and not opened. | Our 32-bit HAL is a non-ACPI HAL of the MPS kind. The firmware has no usable ACPI tables ([boot-path.md](boot-path.md#legacy-bios-and-the-acpi-tables)). | verified in a secondary source; KB 309283 unverified |
| HR-XP-03 | x64 builds of Windows have a single HAL named `hal.dll`. The Wikipedia article on Windows Server 2003 states, in its lead: "IA-64 and x64 builds of Windows Server 2003 as well as Windows Server 2008 and later strictly require ACPI". The Wikipedia article on Ntdetect.com says only that in Vista and later "the HAL only supports ACPI"; it does not mention x64. | [Chappell, HAL variants](https://www.geoffchappell.com/studies/windows/km/hal/history/index.htm) (one x64 HAL; he never studied XP x64), [Wikipedia, Windows Server 2003](https://en.wikipedia.org/wiki/Windows_Server_2003) (secondary, no Microsoft source given) | Whether a non-ACPI x64 HAL can boot is not established by Microsoft material, and Server 2003 x64 is not XP x64. Treat "x64 needs ACPI" as unverified ([question](../../questions/visws-hal-requirements-open.md#non-acpi-hal-on-x64)). | single x64 HAL verified; ACPI requirement unverified |
| HR-XP-04 | Legacy HAL bus routines (`HalGetBusData`, `HalSetBusDataByOffset`, `HalGetInterruptVector`, `HalTranslateBusAddress`, `HalAssignSlotResources`, `HalGetAdapter` and the common-buffer routines) are obsolete but "exported only to support existing drivers". PnP supplies resources and a bus interface replaces bus data access. | [Windows kernel DDI index, Microsoft Learn](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/_kernel/) (current docs) | We must still implement them, because SGI's NT 4.0 era drivers call them. The PnP path becomes primary (HR-XP-05). | verified |
| HR-XP-05 | Interrupt claims travel up the PnP tree to a translator at the HAL device node, which works out the routing and calls `HalGetInterruptVector` to pick processors, IRQL and vector. The result goes to the root interrupt arbiter in the PnP manager. | ["Arbitration and Translation, Part 3"](https://learn.microsoft.com/archive/blogs/doronh/arbitration-and-translation-part-3) (a guest post by Jake Oshins on Doron Holan's blog, 2010: Windows 7-era hindsight about earlier systems, now archived there) | Our HAL provides ISA and PCI interrupt translators and requirement-to-resource translation, from the tables in HR-INT-06 and HR-INT-09. SGI's Windows 2000 HAL already carries translator entry points ([nt-hal.md](nt-hal.md#the-windows-2000-builds)). The entry point by which the PCI driver asks for pin routing is not established from public Microsoft material. | partly verified; post is later than XP |
| HR-XP-06 | A PnP driver gets its DMA adapter from `IoGetDmaAdapter`, which returns a `DMA_ADAPTER` with a table of operations. Scatter-gather and several adapter routines are "reserved for system use". | [IoGetDmaAdapter](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) and the DDI index above (current docs). `DEVICE_DESCRIPTION` versions 2 and 3 on that page postdate XP and do not apply. | The HAL builds the adapter operations over the map-register design in HR-PCI-08. | verified for the call; versions 2 and 3 do not apply to XP |
| HR-XP-07 | The kernel debugger transport is a separate module, `kdcom.dll`, which exports `KdSendPacket`, `KdReceivePacket` and `KdInitialize` among others. The NT 4.0 HAL exports the `KdPort*` routines and the variable `KdComPortInUse`. Chappell lists the `KdPort*` exports as removed after 5.0. Chappell's export table lists `KdComPortInUse` as data, and the Windows 10 `kdcom.dll` imports it from the HAL. | [Chappell, HAL exports](https://www.geoffchappell.com/studies/windows/km/hal/api/index.htm), [NirSoft, kdcom.dll (Windows 10)](https://windows10dll.nirsoft.net/kdcom_dll.html), [Microsoft Learn, KDNET extensibility](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/how-to-develop-kdnet-extensibility-modules) | No debug-port routines in the HAL. We export `KdComPortInUse` (HR-DBG-04). The XP-era import list is unconfirmed because the source is a Windows 10 build. | verified for the split; the import list is unverified for XP |
| HR-XP-08 | Boot text and bug-check screens are drawn through `bootvid.dll`, which exports `VidInitialize`, `VidDisplayString`, `VidBitBlt` and others (11 named exports on XP). A third-party project that replaces it reports in that README that the kernel calls `VidInitialize` early in phase 1 and runs without the boot video driver if `VidInitialize` returns FALSE. | [NirSoft, bootvid.dll (XP)](http://xpdll.nirsoft.net/bootvid_dll.html) (export list), [xdqi/nt5-hvgen2, `drivers/bootvid/README.md`](https://github.com/xdqi/nt5-hvgen2) (third party, kernel behaviour as seen by that project) | We ship a Cobalt boot video driver (SGI shipped `sgibvid.dll` for Windows 2000, [nt-hal.md](nt-hal.md#the-windows-2000-builds)). Which HAL routines `bootvid.dll` imports and how `HalDisplayString` connects to it are not established by these sources. | export list verified; kernel behaviour as reported by a third party, unverified |
| HR-XP-09 | `KeQueryPerformanceCounter` is a HAL export. The counter is monotonically nondecreasing, its frequency is fixed at boot and the same on every processor. | [KeQueryPerformanceCounter](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-kequeryperformancecounter) (current docs) | HR-CLK-06. | verified |
| HR-XP-10 | `KeStallExecutionProcessor` is a HAL export that busy-waits at least the interval and not significantly longer, at any IRQL, for intervals under about 50 microseconds. | [KeStallExecutionProcessor](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/wdm/nf-wdm-kestallexecutionprocessor) | HR-CLK-07. | verified |
| HR-XP-11 | Export surface, per Chappell (x64 "all" means 5.2 SP1 onward). x86: 5.1 adds `KeAcquireInStackQueuedSpinLock`, its `RaiseToSynch` form and `KeReleaseInStackQueuedSpinLock`. `HalDisableSystemInterrupt` and `HalEnableSystemInterrupt` run through 5.2, `HalSetTimeIncrement` through 6.2. x64: the kernel exports the IRQL and spin lock routines (only partly shown in Chappell's table, which marks several "see kernel"), and the HAL exports `HalHandleMcheck`, `HalSendNMI` and `HalIsHyperThreadingEnabled` (5.2 SP1 on), `HalCallBios` (5.2 to 6.1) and `x86BiosExecuteInterrupt`, `x86BiosInitializeBiosEx`, `x86BiosTranslateAddress` (5.2 only). `HalEnumerateProcessors` (x64 from 6.0) and `HalPerformEndOfInterrupt` and `HalRequestDeferredRecoveryServiceInterrupt` (6.1) postdate XP. | Chappell, HAL exports (third-party table from shipped files) | We implement the x86 export set for XP and the x64 set for XP x64. The `x86Bios*` set needs a decision (HR-XP-12). | verified in a secondary source |
| HR-XP-12 | x64 has no V86 mode, so HAL BIOS calls run through an emulator, and the x86 HAL's V86 call path is not carried over. | Chappell (the `x86Bios*` and `HalCallBios` exports appear on x64 only, in 5.2) | The VisWS firmware has an embedded legacy BIOS only for some boot cases and exposes no VGA mode we know of ([boot-path.md](boot-path.md#legacy-bios-and-the-acpi-tables)). We provide neither BIOS call path unless a guest asks. | inferred |
| HR-XP-13 | Bug check `0x80` NMI_HARDWARE_FAILURE carries no parameters. Microsoft says only that "a variety of hardware malfunctions" cause it. That an unclaimed NMI leads to it is not stated on the page and is our reading. | [Bug Check 0x80](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/bug-check-0x80--nmi-hardware-failure) | HR-MEM-03 bug checks with it. HR-NMI-02 does not, as the shipped HAL does not. | verified for the code and parameters; the NMI link is inferred |
| HR-XP-14 | Calling `KeRaiseIrql` with a level below the current one, or `KeLowerIrql` other than to restore, is a fatal error. | [Managing hardware priorities](https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/managing-hardware-priorities) | HR-INT-11 and HR-INT-12 follow it. Whether XP's kernel writes the CPU registry values that HR-ARC-05 lists is unchecked. | verified for IRQL |
| HR-XP-15 | Windows 2000 was the last release with the SGI-specific HAL, per Wikipedia, which links that to the end of SGI support. Wikipedia says XP is unsupported on the machine. The Usenet message says patching SGI's Windows 2000 HAL into XP "might" be possible, that the result would be an XP-lookalike on Windows 2000 files, and that an old XP beta still had Cobalt support. None is a Microsoft statement about XP's loader. | [Wikipedia, SGI Visual Workstation](https://en.wikipedia.org/wiki/SGI_Visual_Workstation) (secondary), Usenet message `2msncjFqmo81U1@uni-berlin.de` (2004) | We have no evidence about an ARC path in XP's loader, so the loader contract is ours (HR-ARC-01 to 04, [question](../../questions/visws-hal-requirements-open.md#what-loads-xp-and-what-it-hands-the-hal)). | unverified for XP's loader |
| HR-XP-16 | Soft-off and the HAL's shutdown path: `HalReturnToFirmware` is listed as "not supported and should not be used" for drivers. | [DDI index above](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/_kernel/) | The kernel calls it itself. Its exact contract for XP is not established from public Microsoft material, so HR-PWR-01 to 05 are written as HAL actions behind it. | unverified |
| HR-XP-17 | The x86 HAL exports `HalBeginSystemInterrupt` and `HalEndSystemInterrupt` and the kernel dispatches device interrupts through them. On x64 the kernel exports the IRQL routines and the HAL does not export these two. | Chappell, HAL exports | The contract between the kernel and HAL for interrupt dispatch on x64 is not established from Microsoft sources. HR-EXP-05. | verified in a secondary source for the export split; the contract is unverified |

Not established from public Microsoft material at all: the `HalInitSystem` phase contract, the HAL private dispatch table's contents, the
loader block's layout, and how the PCI bus driver asks the HAL for pin routing. All four are the first things to settle before code
([question](../../questions/visws-hal-requirements-open.md#xp-hal-contract-items-not-established-from-public-microsoft-material)).

## Unknowns that block writing the HAL

In order of how much they stop:

1. **What loads XP.** No ARC path in XP, no defined loader-to-HAL hand-off
   ([question](../../questions/visws-hal-requirements-open.md#what-loads-xp-and-what-it-hands-the-hal)).
2. **The XP HAL interface not published by Microsoft** (initialisation phases, the private dispatch table, the loader block, PCI interrupt
   routing)
   ([question](../../questions/visws-hal-requirements-open.md#xp-hal-contract-items-not-established-from-public-microsoft-material)).
3. **XP x64 on this chipset**: the processors cannot run it, and non-ACPI x64 is not established
   ([question](../../questions/visws-hal-requirements-open.md#xp-x64-on-a-board-whose-processors-cannot-run-x64)).
4. **Cobalt's in-service state and reset state** ([question](../../questions/visws-hal-open.md#does-cobalt-track-an-in-service-state-for-a-level-line-and-does-the-local-apics-eoi-reach-it)).
5. **Which APIC id the bootstrap processor has** ([question](../../questions/visws-hal-open.md#which-local-apic-id-the-bootstrap-processor-has)).
6. **Boot video**: a Cobalt boot video driver is needed and the display back end's boot-time use is read only in part
   ([question](../../questions/visws-hal-requirements-open.md#boot-video-for-xp-on-the-cobalt-display-back-end)).
7. **Power button without ACPI** and what raises the power NMI
   ([question](../../questions/visws-hal-requirements-open.md#power-button-and-soft-off-without-acpi)).
8. **Host bridge decode ranges** ([question](../../questions/visws-hal-requirements-open.md#host-bridge-ranges-as-the-pnp-manager-needs-them)).
