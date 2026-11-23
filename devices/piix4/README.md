# Intel 82371AB PIIX4 as wired in the Visual Workstation 320 and 540 (functions 0 to 3)

Mode: **spec-backed**. The chip is Intel's PCI-to-ISA, IDE, USB, power management and SMBus southbridge, and its datasheet
and specification update are held (see [documents](../../platforms/visws/documents.md)): *82371AB (PIIX4)* order number
290562-001, April 1997 (preliminary, 284 pages), and *82371AB, 82371EB, 82371MB PIIX4 Specification Update* 297738-017,
January 2002. Page numbers below are printed pages, which equal file pages. The update corrects the datasheet and wins
where they differ. Registers: [registers.md](registers.md) (113 registers). The board is in
[platforms/visws](../../platforms/visws/README.md).

**Grades.** *Established*: a datasheet or update page states it (cited), or the shipped firmware or Windows NT HAL does it in
a routine read in full; the second kind is a **software expectation**, what shipped software requires, not a measurement
of the chip. *Inferred*: a reasoned reading. *Unknown*: nothing held settles it. The registers file carries only these
three; the words "software expectation" appear here and in each register's text. A reset value is a datasheet default;
none was read from a board.

## What it is on this machine

- **Position.** PCI device 4 on the bus behind Lithium bridge B; the firmware reaches it through that bridge's address and
  data window pair. Functions: 0 PCI-to-ISA bridge (8259 pair, 8254 timer, two DMA controllers, 256 bytes of clock RAM, the
  reset control and port 92), 1 IDE, 2 USB (UHCI), 3 power management and SMBus.
- **The board wires it unlike a PC.** The 8259 pair's combined output goes to the board's interrupt controller (below), the
  IDE interrupts and the USB interrupt each have an entry of their own, and the flash holding the system firmware sits behind
  the chip's BIOS chip select (inferred; see unknowns). The Super I/O ([ns-pc87307](../ns-pc87307/README.md)) supplies the
  UARTs, floppy and parallel port.
- **Not described here.** The standard 8259, 8254 and DMA register sets, the USB host controller's I/O registers (no held
  software touches them at register level) and the function 3 device-monitor registers (offsets 0x50 to 0x7f), which no
  held software writes.

## What the firmware, the HAL and Linux do to it

All software expectations; sources are [boot-path.md](../../software/visws/boot-path.md),
[prom-console-path.md](../../software/visws/prom-console-path.md), [nt-hal.md](../../software/visws/nt-hal.md) and the Linux
code on [boot-and-detection](../../platforms/visws/boot-and-detection.md).

| When | What | Registers |
|---|---|---|
| Boot block, set-up step for function 0 | nine byte writes through bridge B's window | `f0_pcicmd` 0x0f (special cycle enable and the hardwired bits); `f0_xbcs` byte 0xf4; `f0_pirqrc` first byte 0x09 (PIRQA to IRQ9); `f0_tom` 0xf2 (top of memory 16 MB); both `f0_mbdma` bytes 0x0c (channel 100, disabled); `f0_gencfg` byte 0 = 0x4d and byte 3 = 0x60; `f0_rtccfg` 0x25 |
| Boot block, function 3 | `f3_pmba` written 0x0f80 (reads back 0x0f81), then `f3_pmregmisc` = 1 | the power management block at the base 0xf80 |
| Self-test | bit-walks function 0 bytes 0x09 (result discarded), 0x90, 0x95, 0xb2 and 0x93 through all-ones, all-zeros and a single bit, restoring each; clears and sets `f0_rtccfg` bit 0; writes dword 0x25000000 to offset 0xc8; reads vendor and device words as one dword and expects 0x71108086; pulses GPO28 | registers hold every pattern: the bytes walked are `f0_pdmacfg`, `f0_ddmabp` and `f0_gencfg` byte 2, all read/write |
| Main module, function 3 attach (read in full) | clears status; writes `f3_smbba` = 0x0fd0, sets `f3_pcicmd` bit 0, writes `pmen` 0x0100, `pmcntrl` 0x1401 and `gpen` 0, then `f3_smbhstcfg` = 0x09; makes one six-byte SMBus block write to slave address 0x69 through the SMBus block at 0xfd0 (control 0x54) | the SMBus base is 0xfd0; neither HAL build touches it |
| Main module, IDE attach | `f1_pcicmd` 5, `f1_mlt` 0x80, `f1_idetim` dword 0xc077c077, `f1_sidetim` 0; on board type 1 byte 0x43 = 0x40 | decode enabled and fast timing on both channels; on the 540 the secondary channel's decode is then off |
| Main module and Linux | read `gpireg` byte 2 as (value >> 2) and 0xf for the board type; main module also reads byte 1 bit 7 | GPI21 to GPI18, GPI15 |
| HAL | reads `pmsts`, writes `pmen` 0x0100 and `pmcntrl` 1, suspends by writing `pmcntrl` 0x2000, writes bit 0 of GPOREG byte 1 (GPO8), sets `f0_rtccfg` bit 2 before the extended clock RAM, reboots by writing 0x06 to the reset control register on all but the earliest boards | |
| Linux | powers off with `pmcntrl` 0x2000 and, up to 2.6.20, a shutdown special cycle through the host bridge; reboots with 0x06 to `rc`; reads `gpireg` byte 2 | |

## Board wiring

- **Board id, GPI21 to GPI18.** `gpireg` bits 21:18, port 0xfb2 bits 5:2: 0 on a 320, 1 on a 540 in the firmware's and Linux's
  reading. The pins are the chip's non-multiplexed inputs, so they are always inputs (established, Table 1, p.36). That SGI
  strapped them to the board type is the software's reading; no held source gives the wiring (inferred). On the 540 the
  Linux expression cannot produce type 1 under its own checks ([boot-and-detection](../../platforms/visws/boot-and-detection.md)).
- **Front-panel line, GPO28.** `gporeg` bit 28 (port 0xfb7 bit 4) is non-multiplexed. The self-test clears it, pulses it
  once after the UARTs are up, and the main module sets it at start and clears it after processor start. Whether it drives an
  LED or a beeper is unknown ([boot-path.md](../../software/visws/boot-path.md)).
- **8259 pair to the board's interrupt controller.** The master 8259's output is one level input to the Cobalt interrupt
  controller, entry 12, vector 0xb9 in all three HAL route tables (established by the HAL; Linux installs its master handler
  on the same line). Neither HAL nor Linux gives the ISA IRQs entries of their own: each polls the master (command 0x0c),
  follows IRQ 2 into the slave, issues a specific end of interrupt and re-injects the interrupt on the local APIC. The PROM
  initialises the pair edge-triggered with vector bases 0x08 and 0x70, the HAL with bases 0 and 8, all inputs masked.
  Entry 12 shares a number with bridge B device 4 pin A, which is never wired ([interrupts.md](../../platforms/visws/interrupts.md)).
- **IDE and USB bypass the 8259.** The IDE channels use Cobalt entries 4 (primary) and 2 (secondary; the 540 has one channel);
  the HAL's tables give the primary entry 5 or 1 on earlier boards. USB uses entry 7 on pin D. The power button and SMBus
  interrupt are routed to ISA IRQ 9 (`f3_smbhstcfg` interrupt select 100; the HAL's soft-power handler is installed on the
  vector of ISA IRQ 9), which on the 8259 route reaches the processors through entry 12 (inferred).
- **Flash.** The reset vector is in the flash; the firmware's `f0_xbcs` write opens the 0xfff80000 region to the BIOS chip
  select only after code runs from the flash, so the flash is behind the reset-decoded top 64 KiB of the BIOS chip select
  (inferred).
- **Port 92 and A20.** The boot processor never writes port 92; the application processors set bit 1 (FAST_A20). The
  datasheet text for that bit is reversed relative to its own table; specification update documentation change 11 (p.54)
  corrects it: 1 deasserts A20M#.

## Where sources disagree or say more than the datasheet

- **Function 3 interrupt pin (`f3_intpn`).** The datasheet says function 3 has pin A (p.120). The specification update, spec
  change 1 (p.13), says the register is not implemented, because the power management and SMBus interrupts are hardwired
  to IRQ 9. The update wins; what the register returns is unknown.
- **Extended clock index bit 7 (`rtcei`).** The datasheet calls it reserved. Spec change 2 (p.13) makes it an aliased copy of
  the NMI enable bit of port 0x70.
- **The firmware writes the SMBus base.** The main module's function 3 attach, read in full, writes `f3_smbba` = 0x0fd0 and
  `f3_smbhstcfg` = 0x09 and runs one block transaction (see the table above). Neither HAL build touches them.
- **XBCS clears two chip selects.** The firmware's 0xf4 write sets bits 7, 6 and 2 and the coprocessor and mouse functions
  and also clears bits 1 and 0, the external keyboard and RTC chip selects. With the Super I/O's keyboard controller
  decoding its own ports this fits the board using that controller (inferred).
- **GPOREG default.** The datasheet intends zero; erratum 3 (p.23) says the chip's actual default is 0x7fffbfff and gives it
  per bit. This unit takes it as the reset value with that source.
- **Datasheet inconsistencies.** MBDMA defaults to 04h while its bit 3 reads 1 (the PROM writes 0x0c); the extended index is
  write only in its register page and read/write in Table 5; GENCFG bit 29 is printed "GPO2" and is GPO24 in the GPO table;
  Tables 1 and 2 label GENCFG and XBCS "PCI Function 1" but both are function 0 registers (pp.57, 65).

## Unknowns

- Which silicon stepping the board carries (`f0_rid`; the update lists later values).
- Board strap levels: GPI18 to GPI21 on each product, CONFIG1 and CONFIG2 (`f0_gencfg` bits 2 and 3 are read only).
- What GPO28, GPO8 and the other outputs drive.
- Which chip select the flash sits on, and what the reset decode is before the first XBCS write.
- Whether the real chip powers off on the control write alone or waits for the stop grant cycle, and whether a shutdown
  special cycle is required (the HAL sends none; Linux and the firmware send one).
- Where accesses to ports 0x72 to 0x77 go with `f0_rtccfg` bit 2 clear: the register text (forwarded to ISA) and Table 5
  (aliases of the index and data ports) conflict.
- The bytes the PROM walks at 0x94 and 0x96 to 0x97 (the walk reads the whole dword and writes it back with one lane changed;
  the datasheet lists nothing at 0x96 and 0x97).
- The meaning of the six bytes the PROM writes to the SMBus slave at address 0x69 (inferred to be a clock generator).
