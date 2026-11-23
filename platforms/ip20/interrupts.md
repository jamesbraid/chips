# Indigo R4000 (IP20): interrupt routing

Which device drives which INT2 bit, and what clears it. Register detail is in [devices/int2](../../devices/int2/README.md). Labels:
**established** means read in a shipped object or stated by the shipped header (`usr/include/sys/IP20.h`); **inferred** is a reasoned reading;
**unknown** is unsettled. IP12 (R3000) differences, where a source states them, are noted at the end. Nothing was measured on a board.

## CPU interrupt levels (established)

From the IRIX `kernel.o` dispatch table (see the INT2 page). Cause bits are numbered 8 to 15; the R4000 manual calls bit 10 IP2.

| Cause bit | R4000 | Source |
|---|---|---|
| 8, 9 | SW0, SW1 | software interrupts |
| 10 | IP2 | INT2 local 0 |
| 11 | IP3 | INT2 local 1 |
| 12 | IP4 | 8254 counter 0 (scheduler clock) |
| 13 | IP5 | 8254 counter 1 (fast clock) |
| 14 | IP6 | bus error |
| 15 | IP7 | CP0 count/compare |

## Local 0 (status `0x1fb801c3`, mask `0x1fb801c7`)

| Bit | Mask | Header name | Source | Cleared by | Grade |
|---|---|---|---|---|---|
| 0 | `0x01` | LIO_FIFO / LIO_GIO_0 | GIO bus interrupt line 0, shared by all slots (the graphics board's FIFO handler registers here) | the GIO device | established; IRIX registers it through `setgiovector` line 0, shared handler at `kernel.o 0x2b3c` |
| 1 | `0x02` | LIO_CENTR | HPC1 parallel port channel | the parallel control register bit `PAR_CTRL_CLRINT` (HPC1 `+0xb4`, bit 1) | inferred: `hpcplp.o plpinit` registers a handler; the vector number was not read; the clearing register is from the header |
| 2 | `0x04` | LIO_SCSI | HPC1 SCSI channel / WD33C93 | the WD33C93 and HPC1 channel | established (`wd93_init`, vector 2) |
| 3 | `0x08` | LIO_ENET | Seeq 8003 through HPC1 (the integral Ethernet) | HPC1 | established (`if_ec2.o ec_init`, vector 3) |
| 4 | `0x10` | LIO_GDMA | graphics DMA done (MC virtual DMA) | MC register `+0x164` | established: `vdma.o MCIntClr` clears the source with a null vector and an MC `+0x164` write |
| 5 | `0x20` | LIO_DUART | serial controllers, ORed (three controller pairs on HPC1 `+0xd00`) | the serial controller | established (`zduart.o du_init`, vector 5; PROM polls this bit for console input) |
| 6 | `0x40` | LIO_GIO_1 | GIO bus interrupt line 1, shared by all slots (the GIO Ethernet driver uses it); the header also says geometry engine or second HPC1 | the GIO device | established; `setgiovector` line 1, shared handler at `0x2bd8` |
| 7 | `0x80` | LIO_VME0 | VME interrupt group 0, gated by the VME 0 mask at `0x1fb801d7` | the VME device | established for the name and mask; no VME driver in the IP20 objects |

## Local 1 (status `0x1fb801cb`, mask `0x1fb801cf`)

| Bit | Mask | Header name | Source | Cleared by | Grade |
|---|---|---|---|---|---|
| 0 | `0x01` | unused | none | | established (header); the PROM expects it to read zero |
| 1 | `0x02` | LIO_GR1MODE | GR1 mode input (IP20) / case interlock (HP1) | n/a, a level | established name; no handler in the IP20 kernel; vector 9 `VECTOR_ILOCK` exists in the header |
| 2 | `0x04` | unused | none | | established; PROM expects zero |
| 3 | `0x08` | LIO_VME1 | VME interrupt group 1, gated by `0x1fb801db` | the VME device | established for the name and mask; no VME driver |
| 4 | `0x10` | LIO_DSP | DSP interrupt, from the HPC1 DSP interrupt block (`0x1fb801a0` and `0x1fb801a4`) | the HPC1 DSP status register | established name (header vector 12, DSP driver `kdsp.a`); the clearing path is on the HPC1 page |
| 5 | `0x20` | LIO_AC | AC failure | n/a | established: `mlreset` registers vector 13 with the handler at `0x2dc0`, which resets every SCSI bus and logs "Power failure detected" |
| 6 | `0x40` | LIO_VIDEO | video option board | the video option | established name (vector 14); no handler found in the IP20 objects |
| 7 | `0x80` | LIO_GIO_2 | GIO bus interrupt line 2, shared by all slots; the graphics board's retrace handler registers here | port register `0x1fb801df` bit 3 pulse (clear then set) | established for the retrace use (`gr2_retr_intr`, `light.o`); handler at `0x2c84` |

The vertical-retrace status can also be read in VME status bit 0 (`0x1fb801d3`), active low, which the GR2 retrace handler polls (`LIO1`
bit 7 is the latched interrupt, VME status bit 0 is the live status; the two relationships are from the header comment and the polling code).

## Other INT2 signals

- **8254 counter 0** drives the CPU line for Cause bit 12, acknowledged by writing `1` to `0x1fb801e3`; **counter 1** drives Cause bit 13, acknowledged by writing `2`. Established.
- **Bus error** drives Cause bit 14. Established as the dispatch binding; the source is the MC (inferred).
- **FPU** exceptions are internal to the R4000 and use no INT2 line.
- **Front panel and power**: INT2 has no power-button input on the Indigo (the Indy's INT3 has a power interrupt on local 1 bit 1). The R4000 board's
  power control is bit 4 of the port register at `0x1fb801df` (unknown polarity); the console LED is bit 0 of the HPC1 aux register at `0x1fb801bf`.
- **Error status** at `0x1fb801e7`: no shipped software touches it.

## Order of service in IRIX (established)

The dispatcher `intr` (`kernel.o 0x2740`) reads Cause AND Status, picks the highest pending bit with a table lookup, runs that level's handler,
masks the bit and repeats until no unmasked bit is pending. The local dispatchers serve the highest set bit of `status AND mask` first.
Within one register the order is therefore bit 7 down to bit 0 (inferred from the highest-bit lookup tables at `kernel.o .data+0x340`).

## IP12 (R3000) differences

- The case interlock input replaces the GR1 mode input on local 1 bit 1 (shipped header comment only).
- NetBSD numbers the CPU lines one higher than IP20 and routes timer 0 and 1 to its lines 3 and 4 (inferred, NetBSD `int.c`), and NetBSD uses the 8254 for the clock on IP12.
- The IP12 PROM (070-8086-002, 070-8088-xxx) and kernel were not read for this page; every IP12 line here is inferred.
