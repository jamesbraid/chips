# Visual Workstation 320 and 540: the NT HAL's per-interrupt, tick, IPI and profile register accesses

What the shipped Windows NT 4.0 HAL touches, in order, each time an interrupt, a clock tick, an inter-processor
interrupt or a profile tick is taken, and which of those a hypervisor with an in-kernel local APIC can answer without
leaving the kernel. Source: `halborg.dll` (multiprocessor) and `halbrgup.dll` (uniprocessor) 1.3, read in a Ghidra
project with the shipped symbols applied and checked against a disassembly; addresses below are `halborg.dll`'s unless
marked. The page is for people writing a replacement HAL or a user-space model of Cobalt, Lithium and the PIIX4; the
register meanings are in [nt-hal.md](nt-hal.md), [devices/cobalt](../../devices/cobalt/README.md) and
[devices/lithium](../../devices/lithium/README.md). Grades as in the [README](README.md): what a routine does is
*established* (read in full); statements about what a hypervisor can serve are *inferred* (a design reading, not
checked against a hypervisor's source here).

The local APIC is reached at its default physical base `0xfee00000`, through a fixed high virtual mapping
(`0xfffe0000`); every access is a 32-bit load or store. Offsets below are from that base.

## Interrupt level is the task-priority register

Every raise and lower of the interrupt level is a local APIC access (established):

| Operation | Accesses |
|---|---|
| `KfRaiseIrql` `0x800125f4`, `KeRaiseIrqlToDpcLevel`, `KeRaiseIrqlToSynchLevel` | read TPR (`+0x80`), write TPR with the level's priority value; no read back |
| `KfLowerIrql` `0x80012650` | write TPR, then read TPR back (read-after-write) |
| `KeGetCurrentIrql` `0x80012668` | read TPR; the level is looked up from TPR >> 4 |

The level-to-TPR table (256 bytes at `0x8002027c`, indexed by level): 0 gives 0, APC (1) `0x3d`, DPC (2) and 3 `0x41`,
levels 4 to 9 `0x51` to `0xa1` in steps of `0x10`, levels `0xa` to `0x1a` `0xb1`, `0x1b` `0xc1`, `0x1c` (clock) `0xd1`, `0x1d` (IPI)
`0xe1`, `0x1e` `0xef`, `0x1f` and above `0xff`. The reverse table (16 bytes at `0x8002039c`, indexed by TPR >> 4) maps back.
These are the most frequent accesses on the machine by far, so the replacement HAL's choice here sets the cost of everything else.

## One device interrupt (Cobalt entries other than the clock, NMI and memory-error entries)

The interrupt arrives on the vector the HAL wrote into the Cobalt entry (low word of entry *n* at `0xc4000000 + 0x10 * n`;
vector tables in [nt-hal.md](nt-hal.md#interrupt-delivery-in-the-hal)). The kernel's dispatch stub calls the HAL twice
(established):

1. `HalBeginSystemInterrupt` `0x800135a8`: read TPR `+0x80`; write TPR (the handler's level value); `sti`. The old level is
   returned. If it was below DPC level, a per-processor flag is set (no APIC access).
2. The driver's routine runs.
3. `HalEndSystemInterrupt` `0x80013538`: write EOI (`+0xb0`, value 0) **first**; then, if the old level is at or above DPC
   level, write TPR (old level) and read TPR back; below DPC level it runs pending software interrupts instead of
   restoring TPR itself. A deferred-8259 mask is tested at the end; nothing in this build sets it (the block that would is
   unreachable), so `HalpDeliverPending8259Ints` `0x80013dd4` never delivers anything (inferred from the unreferenced block).

There is **no access to any Cobalt, Lithium or PIIX4 register** in the acknowledge path: no mask, no end-of-interrupt to Cobalt,
no bridge access. The HAL relies on the source deasserting once the driver has cleared the device and on the local APIC's own
EOI. Whether Cobalt does anything on that EOI (a remote-IRR style state that the EOI clears) is not visible
([questions](../../questions/visws-hal-open.md)). The Linux port masks the entry before the EOI; the HAL does not.

## A legacy (8259) interrupt

Cobalt entry 12 carries the PIIX4's cascaded 8259 output. Its vector is `0xb9` in all three board-generation tables
(established; the vector tables were decoded from the image). The handler `Halp8259Interrupt` `0x80013cbc` is a raw interrupt gate handler: it does
not call the Begin and End routines and does not change TPR (established). Sequence, all byte-wide port accesses:

| Step | Access |
|---|---|
| 1 | write port `0x20` = `0x0c` (OCW3 poll), read port `0x20`; bit 7 clear means nothing pending |
| 2 | if the low three bits are 2 (the cascade): write port `0xa0` = `0x0c`, read port `0xa0`; bit 7 clear means a spurious cascade, answered with write port `0x20` = `0x62` and an exit; otherwise the IRQ is 8 plus the low three bits |
| 3 | end of interrupt: IRQ 0 to 7, write port `0x20` = `0x60` OR the IRQ (specific EOI); IRQ 8 to 15, write port `0xa0` = `0x20` (non-specific EOI of the slave) and then port `0x20` = `0x62` (specific EOI of the cascade input on the master) |
| 4 | read port `0x21` (the result is discarded; an ordering read) |
| 5 | look up the vector for the ISA IRQ in the board's route table; zero means none and the handler goes to step 8 |
| 6 | `cli`; read the interrupt command register (`+0x300`) until bit 12 (delivery status) is clear, at most `0x5000` reads, then a breakpoint |
| 7 | write the command register (`+0x300`) = `0x40000` OR vector: fixed delivery, destination shorthand self, edge. Only the low word is written; the high word is not touched. Restore flags |
| 8 | write EOI (`+0xb0`) = 0 and leave through the kernel's interrupt-exit helper |

So a legacy interrupt costs four to seven port accesses, one command-register read-and-write pair and an EOI, and the
real handler then runs as a second interrupt on the re-injected vector. The 8259 is programmed for edge-triggered inputs
(established), so a second pending IRQ is only presented again if the 8259's output stays or goes high again; the Cobalt entry is level
triggered, so the HAL appears to rely on the entry re-delivering after the local APIC's EOI while the 8259 output is
still high (inferred: nothing in the HAL says so). The IDE channels and the USB function are on their own Cobalt entries and do not take this path.

## One clock tick

The system clock is the Cobalt CPU-block timer (established; the local APIC timer only with `SYSCLOCK=APIC`). It is
calibrated at start-up against the CMOS update-in-progress flag (port `0x70` = 0x0a, read port `0x71`, bit 7), so the
model's timer must tick at its true rate against its RTC. Default tick 10 ms (`0x186a0` in 100 ns units), minimum 1 ms
when a program asks for finer timer resolution (`HalSetTimeIncrement` `0x80016130` stores the new reload and the clock
handler writes it at the next tick); reload value = tick length x measured frequency / 10,000,000. The entry is programmed once
(`HalpInitializeClock`): reload `+0x30`, control `+0x10` run bit set and mask bit cleared, then Cobalt entry 28 (27 on Cobalt
Lite) low word `0x80d1` (level, vector `0xd1`), high word 0, so the tick goes to processor id 0.

The handler `HalpCobaltInterrupt` `0x8001408c` (UP: `halbrgup.dll` `0x80013f6c`) on vector `0xd1`, level `0x1c`:

| Step | Access |
|---|---|
| 1 | `HalBeginSystemInterrupt`: TPR read, TPR write `0xd1` |
| 2 | read Cobalt CPU status (`0xc2000000 + 0x20`); bit 0 set (cache operation, unexpected) prints an error and writes status = `0xfffffffe` |
| 3 | bit 1 clear (not a timer tick): `HalEndSystemInterrupt` and leave |
| 4 | write status (`+0x20`) = `0xfffffffd`: clears the pending bit, other bits written as ones |
| 5 | multiprocessor build, when the IPI-clock flag is set: subtract the current tick length from an accumulator; when it reaches zero (the accumulator is reloaded with the 10 ms maximum, so the broadcast happens at most at 100 Hz even if the timer runs faster, and the other processors tick slower than the boot processor after `HalSetTimeIncrement` shortens the tick; the flag is set only when a second processor has been started, see [nt-hal.md](nt-hal.md#follow-on-corrections-and-additions)), wait for command-register bit 12 clear and write `+0x300` = `0x000c00d1` (vector `0xd1`, all excluding self, fixed). The high word is not written |
| 6 | if the tick length was changed, write the new reload to `0xc2000000 + 0x30` |
| 7 | `KeUpdateSystemTime`, which calls `HalEndSystemInterrupt` (EOI, TPR restore) |

Each other processor takes the broadcast on vector `0xd1` in `HalpClockInterruptPn` `0x80011788`: Begin, `KeUpdateRunTime`, End. It touches no Cobalt register.

## One inter-processor interrupt

| Case | Sender | Receiver |
|---|---|---|
| Kernel IPI (`HalRequestIpi` `0x80012c64`) | read `+0x300` until bit 12 clear; write `+0x310` = mask << 24; write `+0x300` = `0x8e1` (vector `0xe1`, fixed, logical destination). High word first, low word triggers | `HalpIpiHandler` `0x80012d80`: Begin (level `0x1d`), `KiIpiServiceRoutine`, End |
| Broadcast call (`HalpGenericCall` `0x800129d4`) | shared-memory handshake, then `+0x310` = mask << 24 and `+0x300` = `0x8c1` (vector `0xc1`) | `HalpBroadcastCallService` `0x80012928` (level `0x1b`): Begin, `HalpPollForBroadcast`, End |
| APC and DPC requests (`HalRequestSoftwareInterrupt` `0x80016810`) | a DPC the HAL judges "short" only sets a per-processor flag (inferred: `HalpCmpShortDpc` was not read in full). Otherwise `HalpGenerateInterrupt` `0x800168c0`: `cli`, read `+0x300`, wait for bit 12 clear, write `+0x300` = `0x40000` OR the vector (`0x3d` for APC, `0x41` for DPC), wait again, restore flags | `HalpDispatchInterrupt` `0x80013178`: read TPR, write TPR `0x41`, write EOI, `KiDispatchInterrupt`, restore TPR. `HalpApcInterrupt` `0x800132fc` likewise |

## One profile tick

The profile interrupt is the local APIC timer (established). `HalStartProfileInterrupt` `0x80013610` writes the initial count
(`+0x380`) and then the timer LVT (`+0x320`) = `0x200fd` (periodic, vector `0xfd`, unmasked); `HalStopProfileInterrupt` writes
`+0x320` = `0x300fd` (masked); `HalSetProfileInterval` writes `+0x380` and reads the current count (`+0x390`). The divide
register (`+0x3e0`) is set to `0xb` (divide by one) once, in calibration. The count is the bus-clock frequency the HAL
measured against the RTC second (so the local APIC timer must count at a true rate, and the emulated time-stamp counter must
tick as well: the calibration writes the time-stamp-counter MSR and reads it back). Handler `HalpProfileInterrupt` `0x80013758`:
Begin (level `0x1f`, vector `0xfd`), `KeProfileInterrupt` only if profiling is on, End. The performance-counter vector `0xfe`
(LVT `+0x340`, masked until enabled) has the same shape.

## What a hypervisor can serve in the kernel, and what leaves it (inferred)

| Access | Frequency | Needs user space? |
|---|---|---|
| Local APIC: TPR, EOI, command register, timer LVT, initial and current count, spurious vector, logical destination | every IRQL change, every interrupt, every IPI, profile ticks | No. An in-kernel local APIC (ideally with its hardware-assisted APIC virtualisation) serves all of them; a local APIC modelled in user space would exit on every IRQL change and is not viable |
| Cobalt CPU block `0xc2000000` (`+0x20` read and write, `+0x30` on a tick-length change) | two accesses per clock tick (100 per second, up to 1,000 with 1 ms timers) | Yes, a memory-mapped I/O exit each; the status write must take effect before the next read. Cheap enough |
| Cobalt interrupt controller `0xc4000000` | enable and disable of a line, start-up | Yes; not in the per-interrupt path |
| Lithium windows `0xfc000000`, `0xfd000000` (`+0xf8` and `+0xfc` configuration cycles, `+0x46` enables) | PCI configuration and driver connect, not interrupts | Yes |
| PIIX4 8259 ports `0x20`, `0xa0`, `0x21` | four to seven per legacy interrupt (serial, floppy, parallel, keyboard and mouse) | Yes. The in-kernel 8259 cannot be used as is: its output goes to the processor's external-interrupt input, which the HAL masks, not to a Cobalt entry (inferred from the HAL's local APIC set-up); a user-space 8259 raising Cobalt entry 12 is the fit |
| CMOS ports `0x70`, `0x71` | start-up calibration, RTC reads | Yes |

Delivery into the in-kernel local APIC from a user-space Cobalt model is by injecting the entry's vector at processor id 0.
The HAL never rewrites a device entry's destination, so the model does not need to redirect a line per processor: all device
lines and the clock go to the processor with local APIC id 0 (the HAL's bootstrap processor, assuming the firmware's table
gives it id 0; unknown, see the questions page). Only the NMI entry is delivered in logical mode. Level lines that
must be re-presented after the guest's EOI (entry 12 above) need an end-of-interrupt notification to user space; how a given
hypervisor delivers that was not checked.
