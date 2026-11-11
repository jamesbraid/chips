# IOC3 coverage

What the shipped software and the public drivers settle about the IOC3, and what stays open. The register inventory and
per-routine readings are on [the chip page](../chips/ioc3/README.md); this page grades the coverage questions that were
open. Labels follow [AGENTS.md](../AGENTS.md): **established**, **inferred**, **unknown**.

Sources: IRIX 6.5.30 IP35 objects `ioc3.o`, `if_ef.o`, `ecpplp.o` (all routines cited were read in full unless a line says
otherwise); the shipped Ethernet driver's tunable file (`var/sysgen/master.d/if_ef`), from which only the numeric values
are used; one shipped development header (`usr/include/sys/PCI/ioc3.h`), cited for register names and master identifiers
only. Public: Linux `arch/mips/include/asm/sn/ioc3.h`, `drivers/net/ethernet/sgi/ioc3-eth.c`,
`drivers/tty/serial/8250/8250_ioc3.c` and `arch/mips/pci/pci-xtalk-bridge.c` (mainline master of 2026-08); OpenBSD
`sys/arch/sgi/xbow/xbridge.c` and `sys/arch/sgi/pci/ioc.c`. A driver is a driver author's naming, not a measurement.

## The byte lane question (settled at the PCI level; one residue)

The chip page recorded two disagreements: the 16550 line-control register sits at UART+3 in the IRIX driver and at UART+0
in Linux, and the parallel-port control and status registers come in the opposite order. Both are one effect.

- **Rule (established by agreement of eleven byte registers).** For every byte-wide super-I/O register the IRIX offset and the
  Linux offset differ by exactly an exclusive-or with 3. UART A line control: IRIX `0x2017b`, Linux first byte of the
  `uarta` structure at `0x20178`. Parallel-port status/control: IRIX data, status, control at `0x20150`, `0x20151`,
  `0x20152` (the shipped header's order), Linux control, status, data at `0x20151`, `0x20152`, `0x20153`. The ECP
  extended control register: IRIX `0x2015a`, Linux `0x20159`. The FIFO, configuration B and extended control trio:
  IRIX `0x20158`, `0x20159`, `0x2015a` against Linux `0x2015b`, `0x2015a`, `0x20159`. The two header layouts agree the same way for the
  UART configuration and keyboard configuration pair (IRIX `0x20141`, `0x20142`; Linux `0x20142`, `0x20141`) and the
  real-time-clock address and data pair (IRIX `0x20168`, `0x20169`; Linux `0x2016b`, `0x2016a`). In every case the two
  offsets are the same byte read through opposite orders inside a 32-bit word. The IRIX order is the natural 16550 and PC
  parallel-port register order, so the natural (PCI-side) byte address of register *n* is base + *n*: **established**
  (the register contents and call sequences make sense only in that order: `plp_reset` writes `0x08` then `0x0e` to
  `0x20152`, the PC control register's select-input then initialize-high pattern; `plpattach` reads `0x2015a` and then
  stores `0x34`, a PC ECP control register value).
- **Linux and OpenBSD both apply `offset ^ 3` to byte accesses and `^ 2` to halfword accesses** through the large device
  window (OpenBSD `xbridge_read_1`, `xbridge_read_2`; Linux `ioc3_serial_in`). The Bridge device register's DMA byte-swap
  bits are cleared for the IOC3 by both (OpenBSD and Linux `bridge_disable_swapping`), and both clear the widget-control
  swap bits for PIO through the large window. With no swap in the path a big-endian CPU sees the little-endian PCI byte
  *n* of a 32-bit word at word offset 3 minus *n*: **established** as the reason for the `^ 3`, since both drivers say so.
- **So IRIX is looking at the same bytes through a swapped path: inferred.** IRIX uses the natural order, which a
  big-endian CPU gets only if the path swaps bytes within each 32-bit word. The Bridge-family device register has such a
  bit (the public Linux header calls it the device swap bit, `0x2000`, distinct from the two DMA swap bits at
  `0x180000`).
- **Which routine sets that bit, and what the IOC3 asks of it: established (read in full, IP27 and IP35 `pcibr.o`).**
  Bit 13 of a slot's device register is written by one routine only: the generic address-mapping routine that
  `pcibr_piotrans_addr` and the map allocator reach (`IP27boot/pcibr.o` 0x1004, `IP35boot/pcibr.o` 0x1250; neither
  carries a symbol, both sit between `pcibr_write_gather_flush` and `pcibr_piomap_alloc`). When a request lands in one of
  the device windows (spaces 8 to 13) it rebuilds the register as: keep the old value above bit 12, clear bit 12 and
  bit 13 together, set bit 12 (I/O versus memory select, in the Linux header's wording) unless the space is the large
  window (space 2), put the window offset in bits 11:0, and finally set bit 13 if bit 12 of the caller's flag word is
  set and clear it otherwise. The IOC3 attach (`IP35boot/ioc3.o` 0x3bc and 0x3f8) maps spaces 7 and 8 (the device window is space 8) with flag word 0, so
  the routine clears bit 13 for the IOC3 window; no other routine in either kernel, including the bit-by-bit device
  register routines `pcibr_device_flags_set`, `pcibr_priority_bits_set` and `pcibr_endian_set` (see
  chips/bridge/README.md), writes it. A request with flag bit 12 clear also refuses to share a device window whose shadow
  has bit 13 set, so the two kinds of mapping never mix in one slot.
- **Consequence for the swapped-path inference above: the IRIX kernel itself does not turn the device swap bit on for the
  IOC3.** What is still unknown is why IRIX's byte offsets are the exclusive-or-3 mirror of Linux's if the swap bit is
  clear in both. Candidates (inferred, not read): the PROM leaves another swap path on (the widget control swap bits 23
  and 22 that the Linux probe clears), or the IP27/IP35 hardware presents big-endian CPU accesses to the little-endian
  PCI side with the byte lanes already mirrored, so the `^ 3` is Linux compensating for something its own probe changed.
  Test: on a running IRIX system read the IOC3 slot's device register (bit 13) and the bridge control register
  (bits 23:22); on a stock PROM read both before IRIX loads.

**Consequence for a model.** The hardware presents the 16550 and PC parallel-port registers at natural PCI byte
addresses base + *n*. A model that wants both guests to work must either swap bytes within each word for the large
window when the device swap bit is set, or present natural addresses to IRIX and mirrored ones to the drivers that clear
it. This is a statement about the observed software, not a claim about the silicon beyond the PCI-side order.

## Parallel-port DMA registers `0x80` to `0x98` (roles established by two agreeing sources)

The chip page listed `0x84` to `0x98` as unread. `plp_dma` (`ecpplp.o` `0x2c40`), `plp_dma_reset` (`0x30d0`),
`plp_stop_dma` (`0x3198`) and `plpintr` (`0x2380`) were read. The shipped header and Linux name the same seven words.

| offset | role (shipped header and Linux agree) | what IRIX does | grade |
|---|---|---|---|
| `0x80` | context A buffer address, upper 32 bits | `plp_dma` stores the high half of the first descriptor's 64-bit address | established |
| `0x84` | context A buffer address, lower 32 bits | stores the low half | established |
| `0x88` | context A count and flags | stores the descriptor's 32-bit count ORed with `0x40000000` when another descriptor follows, with `0xc0000000` when it is the last | role established; the flag names (valid, last) are **inferred** from that pattern |
| `0x8c` | DMA control | `plp_dma` sets bit 31 and clears bit 29; `plp_stop_dma` clears bits 31 and 29 with one mask; `plp_dma_reset` sets bit 30 and writes it back later | bit 31 is enable and bit 30 a reset pulse: **inferred**; bit 29: **unknown**. `plpintr` was re-read in the IP27 object: it clears bit 31 (AND with `0x7fffffff`) and neither tests nor sets bit 29 or 30, so that half of the test is done and found nothing. `plp_dma` clears bit 29 and no routine read sets it. Remaining test: any per-bit definition of this control word in the public Linux IOC3 header that names the seven words above; failing that, bit 29 stays unknown and nothing in IRIX depends on it beyond clearing it |
| `0x90`, `0x94`, `0x98` | the same three for context B | `plp_dma` loads the next descriptor into B, using the next-descriptor pointer at descriptor +16; `0xc0000000` again marks the last | established |

The descriptor `plp_dma` walks, as the code reads it: 64-bit buffer address at +0, 32-bit count at +8, physical pointer
to the next descriptor at +16 (zero ends the chain). That is IRIX's software structure, not a hardware format.
Interrupt side: shared-interrupt-status bits 18 to 21 are pass-through, context A done, context B done and PCI error,
in both the header and Linux; `plp_dma` clears all four with one store of `0x3c0000` to the status register at `0x1c`, and `plpintr` stores `0x40000` and
`0x80000` there (**established** from the stores; the bit names are from the header).

The super-I/O parallel registers in IRIX numbering (natural order): data `0x20150`, status `0x20151`, control `0x20152`,
FIFO access `0x20158`, configuration B `0x20159`, extended control `0x2015a`. `plp_dma` clears bit 5 of control (the PC
direction bit) before arming and, further on, sets bit 3 and clears bit 2 of the extended control register (DMA enable and
service-interrupt unmask in the PC ECP layout); `plpintr` also reads and rewrites that register. Roles: **inferred** from conformity with the PC
parallel-port register set, which the shipped header names the same way.

## The Ethernet inter-frame gap (`0x118`): established

The three table words `ef_ioc3init` loads sit in the IRIX driver's tunable file, not in the object's data. Values, in
order gap, first receive gap, second receive gap (the register fields at bits 6:0, 14:8 and 22:16 per the public Linux
header):

| mode | values | register image |
|---|---|---|
| full duplex | 21, 21, 21 | `0x00151515` |
| half duplex | 21, 11, 17 | `0x00110b15` |

These equal Linux's full and half duplex constants field for field (full: 21 in each; half: 21 gap, 11 first receive gap,
17 second receive gap). They are initialised tunables the administrator can change, so they are IRIX defaults that
happen to equal Linux's; the part's reset value is still **unknown** (settling test: read the register from an early-boot monitor before `ef_ioc3init` runs, or a published IOC3 specification page; no held code reads it first). Check: `ef_ioc3init` stores them at bit offsets
0, 8 and 16 (chip page), so full duplex writes `0x00151515` and half duplex `0x00110b15`.

## Error address registers (config `0x40`, `0x44`): established decode

`ioc3_error_handler` (`ioc3.o` `0xf2c`, read in full) prints the PCI status bits it finds set in the command/status word,
then reads config `0x40`: bit 0 is valid, bits 4:1 select one of 13 messages through a jump table (values above 12 take a
generic message), bits 31:6 are address bits 31:6 and the word at `0x44` supplies the upper 32 bits, and the handler
clears the latch by storing 1 to `0x40`. The shipped header and Linux agree on the same fields. Requester numbers
(shipped header): 0 serial port A transmit, 1 A receive, 2 port B transmit, 3 B receive, 4 parallel port, 8 Ethernet
transmit descriptor read, 9 and 10 transmit buffer reads, 11 receive descriptor read, 12 receive buffer write. Numbers 5
to 7 and 13 to 15 are named nowhere: **unknown**. Settling test: a published IOC3 specification page listing the DMA requester numbers; no shipped code writes or tests those numbers (the census over the IOC3 objects reaches none), so the end state is unknown with no software dependency. The same two registers also appear as a mirror at `0x14` and `0x18`
of the memory window (Linux and the shipped header): **established** by two sources, not accessed by the IRIX objects
read.

## Why interrupts are polled while the top interrupt bits are enabled

Unchanged: **unknown**. The mechanism is read in full. The Linux driver has no equivalent and the OpenBSD driver enables
bits directly. The shipped header's comments say the enable registers are read-only to general kernel code and must be
changed through the IRIX IOC3 driver's own functions, which is the lock the mechanism implements, but state no reason
for the polling. Route: a published hardware note. Valid end state otherwise.

## Still open

| item | route | discriminating test |
|---|---|---|
| Why the device swap bit is clear for the IOC3 window yet IRIX and Linux offsets mirror each other | the routine is identified (above); the remaining path is the widget control swap bits, set by the PROM or by the large-window state | read the device register bit 13 and the control register bits 23:22 on running IRIX and before it loads |
| `0x8c` bit 29 and the exact meaning of bit 30 | silicon, or a published IOC3 data sheet | set bit 29 alone and observe the transfer |
| Reset values | no routine reads one | read everything after a PCI reset |
| Requester numbers 5 to 7 and 13 to 15 | silicon only | provoke each master's error and read config `0x40` |
| Per-slot subdevice masks (which board string selects `0x91`) | extract the string table | none |
