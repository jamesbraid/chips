<!-- generated from devices/cobalt/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 2 -->
<!-- input sha256 892f461404377c9293c3bf0c2a21948cf46d82ee52360aa46f3d72d48d14d64b -->

# Cobalt (system ASIC of the SGI Visual Workstation 320 and 540): the CPU block and the interrupt controller, as SGI's Linux platform code names them

Offsets, bit positions and values come from the Linux Visual Workstation code (kernel 2.2 to 3.14) and are cross-checked against SGI's shipped Windows NT 4.0 HAL (halborg.dll 1.3). Grades: established means the shipped HAL programs the item the same way (or the item is its own table); inferred means only Linux defines it, a software expectation of Linux and not of the shipped system. Where the HAL differs, the item says so. The chip's own specification is not held. Offsets are relative to the base of each block (CPU_PHYS and APIC_PHYS below). Linux reads and writes every register as a 32-bit word. Reset values are unknown throughout. Only what the kernel touches is here; the memory controller and graphics engine registers are not.

Unit `cobalt`, macro prefix `COBALT`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| cpu | byte |  |
| apic | byte |  |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `apic_lo` | 0x0 | rw | 32 | 30 | apic | unknown | established |  |
| `apic_hi` | 0x4 | rw | 32 | 30 | apic | unknown | inferred |  |
| `apic_id` | 0xffc | rw | 32 |  | apic | unknown | established |  |
| `cpu_rev` | 0x8 | r | 32 |  | cpu | unknown | established |  |
| `cpu_ctrl` | 0x10 | rw | 32 |  | cpu | unknown | established |  |
| `cpu_stat` | 0x20 | rw | 32 |  | cpu | unknown | established |  |
| `cpu_timeval` | 0x30 | rw | 32 |  | cpu | unknown | established |  |

### Register `apic_lo`

Interrupt redirection entry, low word, one per interrupt line (thirty lines, 0 to 29). The kernel writes the level bit and an interrupt vector to unmask a line and only the mask bit to mask it, reading the register back after masking. The vector it writes is the kernel's irq number plus 0x20, so it is not the line number.

Array of 30 registers, stride 16.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 16 | `mask` | established |  |  | 1 masks the line, 0 enables it. |
| 15 | `level` | established |  |  | 1 level-triggered, 0 edge. The kernel sets it on every line it enables. |
| 7:0 | `vector` | established |  |  | Interrupt vector delivered to the processor. The kernel's value fits in eight bits; the field's extent is not stated by any code and follows the standard I/O APIC layout. |

### Register `apic_hi`

Interrupt redirection entry, high word. The kernel writes zero beside every low word it sets and never reads it. By the standard I/O APIC layout it would hold the destination processor; that is inferred from the layout of the low word and the register spacing, and no code reads it back.

Array of 30 registers, stride 16.

### Register `apic_id`

Controller identification and enable. The kernel reads it, sets the enable bit with a read-modify-write that it says must not change the identification, and prints the result. Where the identification field sits is not known.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `enable` | established |  |  | 1 enables the interrupt controller. Linux sets it once at start-up. |

### Register `cpu_rev`

Cobalt revision. The kernel prints it at start-up and, in the 2.4 interrupt path, reads it after a driver has acknowledged its device as a way to make sure the driver's write has reached the device before the end-of-interrupt. The field layout is not known.

### Register `cpu_ctrl`

Timer and memory control. Linux sets timer_run and clears timer_mask, each by a read-modify-write, after loading the count, and touches no other bit. The NT HAL (halborg.dll 1.3: the Cobalt control set-up in HalInitSystem and HalpEccControl) also clears ecc_enable at start-up, sets timer_mask, ORs in page_close from its PAGEOPENPOLICY boot option, and sets ecc_enable together with bit 0 of the memory block when it enables ECC.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `timer_mask` | established |  |  | 1 masks the timer interrupt; 0 lets it through. |
| 2 | `timer_run` | established |  |  | 1 starts the system timer; 0 leaves it stopped. |
| 1 | `page_close` | established |  |  | Page policy. The HAL ORs 2 in for PAGEOPENPOLICY=CLOSE and 0 for OPEN (the default); it never clears the bit, so what OPEN means for a bit the firmware set is unknown. That the bit makes the controller close DRAM pages after an access is inferred from the option's names only. |
| 0 | `ecc_enable` | established |  |  | 1 turns ECC checking on (the HAL sets it with bit 0 of the first memory-controller register). Cleared by the HAL at start-up; the NT HAL never sets it on a Cobalt Lite revision (0xa0, 0xa8). |

### Register `cpu_stat`

Timer status. The 2.2 and 2.4 timer handlers clear the pending bit by reading the register and writing it back with that bit cleared. The 2.5 and later code never writes it, so whether a level timer interrupt needs this clear to deassert is open.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `timer_intr` | established |  |  | Read: 1 means the timer interrupt is pending. Write 0: clear it. |

### Register `cpu_timeval`

Timer count. The kernel writes the Cobalt core rate divided by the tick rate (a 100 MHz core rate) before starting the timer and calls it a countdown value. That it reloads itself each period is inferred from the kernel using it as the periodic tick and writing it once.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `APIC_8259` | 0xc | established |  | Line the PIIX4's cascaded interrupt controllers drive. |
| `APIC_AS` | 0x18 | inferred |  | Header name AS; no code uses it. |
| `APIC_CPU` | 0x1c | established |  | Line of the Cobalt timer, which the header also calls the cache interrupt. |
| `APIC_IDE0` | 0x4 | inferred |  | Line of the first IDE channel (on board 320 revision 5 the kernel uses line 5). The NT HAL uses line 4 on the newest 320 generation and the 540 except revision 0, 5 on the middle 320 generation and the 540 revision 0, and line 1 on the oldest 320 generation, which Linux has no case for. |
| `APIC_IDE1` | 0x2 | established |  | Line of the second IDE channel, on the 320 only. |
| `APIC_LINES` | 0x1e | established |  | Number of interrupt lines the kernel knows (0 to 29). |
| `APIC_LI_AUDIO` | 0x16 | inferred |  | Line of the Lithium audio engine. |
| `APIC_NMI` | 0x1d | established |  | Last line; named NMI by the header and unused by Linux. The NT HAL programs it as an NMI-delivery entry (entry 28 on the Lite revisions 0xa0 and 0xa8 moves the NMI to 28 and the clock to 27). |
| `APIC_PCIA_BASE0` | 0x0 | established |  | First line of the per-slot INTA lines of Lithium bridge A. |
| `APIC_PCIA_BASE123` | 0x5 | established |  | First of the lines bridge A shares among INTB, INTC and INTD (the header comment says 5 and 6). |
| `APIC_PCIB_BASE0` | 0x8 | established |  | First line of the per-slot INTA lines of Lithium bridge B (8 to 12). |
| `APIC_PCIB_BASE123` | 0xd | established |  | First of the lines bridge B shares among INTB, INTC and INTD (13 to 15). Linux uses none of them; the NT HAL's bridge B interrupt map does (shared pins on entries 13 to 15). |
| `APIC_PHYS` | 0xc4000000 | established |  | Physical base of the interrupt controller. |
| `APIC_PIIX4_USB` | 0x7 | established |  | Line of the PIIX4's USB function. |
| `APIC_RE` | 0x19 | inferred |  | Header name RE; no code uses it. |
| `APIC_VIDIN0` | 0x12 | established |  | Video input 0 interrupt. |
| `APIC_VIDIN1` | 0x13 | established |  | Video input 1 interrupt. |
| `APIC_VIDOUT0` | 0x10 | established |  | Video output 0 interrupt. |
| `APIC_VIDOUT1` | 0x11 | established |  | Video output 1 interrupt. |
| `CPU_MAX` | 0x4 | inferred |  | Most processors the kernel accepts from that table. |
| `CPU_NUM_PHYS` | 0x1e00 | established |  | Physical address of the 16-bit processor count in low memory; the processor table follows at the next two bytes. Not a register: written by the machine firmware. |
| `CPU_PHYS` | 0xc2000000 | established |  | Physical base of the CPU block. |
| `TIME_HZ` | 0x5f5e100 | inferred |  | The core rate the Linux kernel divides by the tick rate to load the timer. The NT HAL assumes no rate: it measures the timer against the RTC update flag at start-up (nt-hal.md). |
