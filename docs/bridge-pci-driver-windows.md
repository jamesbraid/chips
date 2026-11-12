# Bridge and XBridge: the PCI windows and swap controls IRIX drives

What the IRIX 6.5.30 Octane and Origin kernels do to a Bridge (part `0xc002`, manufacturer 54) or XBridge (part `0xd002`, manufacturer 36) to give a PCI function programmed-I/O and DMA access, and which PCI addresses they hand out. It is the register-and-address view of the generic PCI layer's behaviour; the driver-visible call interface (space numbers, flag words, the `.id` hardware-graph entries) is in the sibling kernel repository's PCI driver interface note. The IP35 PIC is not covered here: its branches in the same routines were not read.

Evidence: `IP30boot/pcibr.o` and `IP30boot/xbridge.o` of 6.5.30, offsets in each object; the IP27 objects `IP27boot/pcibr.o` and `IP27boot/xbridge.o` for the comparisons named. Bit and offset names come from the public Linux SN bridge header, used after the read to name what the binary does, never to supply a value.

Grades: **established** read in the binary, **inferred**, **unknown**.

## PIO window offsets

The helper at `pcibr.o` 0xf6c (called by `pcibr_piomap_alloc` 0x183c and `pcibr_piotrans_addr` 0x1b1c) converts a PCI space and address into an offset inside the Bridge widget's address space. For Bridge and XBridge:

| PCI space | Widget offset | Condition | Grade |
|---|---|---|---|
| configuration, type 0 | `0x20000 + slot * 0x1000 + offset` | the range ends within the first 0x100 bytes; `0x820000` replaces `0x20000` when the soft-state bus number (soft +72) is nonzero | established, block at 0x14f8 |
| 32-bit memory | `0x4000_0000 + PCI address` | the range ends by PCI address `0x4000_0000` | established, block at 0x12a8 |
| 64-bit memory | `0x8000_0000 + PCI address` | upper limit from a constant at gp-32736, value not read | established offset, unknown limit, block at 0x1468 |
| I/O | `0x1_0000_0000 + PCI address` | the range ends within 4 GiB; **and the widget revision word (soft +120, read at attach) is above `0xc0023`**, otherwise the mapping fails | established, block at 0x149c |
| BAR window n | as the window's memory or I/O type, after adding the base the host assigned to that register | window record from the function's record +72 + 56 n | established, 0x1024 to 0x1098 |

Per-device 1 MiB or 2 MiB small windows (device 0 and 1 at 2 MiB, the rest at 1 MiB, from widget offset 0x200000, the layout the flash note in [xio-fibre-channel.md](xio-fibre-channel.md) records) are used for the first mapping of a function when the range fits and no bus-wide swap mode conflicts; the code at 0x1108 to 0x11f0 and 0x1580 to 0x15a8 chooses a window per function and rewrites that device's Device register to point it: bit 12 selected, offset bits from the PCI address, bit 13 set when byte swap is requested. Established for the register rewrite, inferred for the choice order.

## Swap controls, three places

| Control | Bit | Set when | Effect | Grade |
|---|---|---|---|---|
| Control register, memory swap | 22 (0x400000) | the first memory-window mapping asks for byte-stream data; cleared otherwise | byte swap of CPU accesses through the 32-bit and 64-bit memory windows | established, `pcireg_control_bit_set` / `_clr` at 0x16e0 and 0x17fc; state kept in soft +2716 |
| Control register, I/O swap | 23 (0x800000) | same, for the I/O window; state in soft +2712 | byte swap of CPU accesses through the I/O window | established, same code |
| Device register, small-window swap | 13 (0x2000) | a small-window mapping asks for byte-stream data | byte swap of CPU accesses through that device's window | established, 0x1580 to 0x15a8 |
| Device register, translation-entry DMA swap | 20 (0x100000) | the device's endian call is unequal (device and host differ), or a DMA map asks for it (Bridge only; see below) | byte swap of DMA through address-translation entries | established |
| Device register, direct DMA swap | 19 (0x80000) | same | byte swap of direct-mapped DMA | established |
| PCI address bit 29 (0x2000_0000) of a translation-entry address | n/a | XBridge (and PIC): the DMA map asks for byte-stream data, or the Device register has bit 20 set; cleared when the map asks for word values | swap on that mapped region | established, `pcibr_dmamap_alloc` 0x2448 to 0x2498 |
| 64-bit PCI address bit 55 | n/a | 64-bit DMA with a byte-stream request | swap attribute of the 64-bit window | established, helper at 0x1f0c |

The two memory and I/O Control bits are bridge-wide: the first mapping sets the mode and a later mapping that wants the other mode fails with -1 (0x1300 to 0x1310, established); that nothing resets the mode short of a bridge reset is inferred, no clearing path was looked for. The device endian call sets or clears Device bits 19 and 20 together (`pcibr_endian_set` 0x3904): clear when the device and host endianness arguments are equal, set when they differ. It leaves the PIO controls alone. On a Bridge (type 0) the DMA map flags for byte stream and word values act on the same Device bits 19 and 20 through the helper at `.text` 0x0 (0x14c to 0x198); on an XBridge they act on bit 19 only and on the translation-entry address bit above. IP27 `pcibr_endian_set` (0x3b04) and the IP27 window set-up repeat the IP30 code (compared for those two routines only).

## Translation entries and DMA address ranges

Established from `pcibr_dmamap_alloc` 0x20c0 and `pcibr_dmatrans_addr` 0x2e28:

- A translation-entry (mapped) DMA address is `0x4000_0000 + (entry index << 14)`, each entry mapping a 16 KiB page (0x2430). The entry word carries the crossbow widget number in bits 15:8 and bits 4:0 are flags (`pcibr_flags_to_ate` 0x47f0): bit 0 valid and bit 1 coherent always; bit 3 prefetch for a data stream (DMA data, or an explicit prefetch request) and cleared for a command stream; bit 4 barrier for a command stream (or explicit); bit 2 precise by request.
- A direct 32-bit DMA address is in the 2 GiB window from `0x8000_0000` (the limit `0x8000 << 16` at 0x2f88); 64-bit direct addresses carry attributes in the top bits (bit 59 prefetch, 58 precise, 56 barrier, 55 swap, target widget in 63:60; helper at 0x1f0c).

## PCI addresses IRIX assigns to base-address registers

`xbridge_attach` builds three allocation maps of PCI address space in the soft state with `pciio_device_win_map_new` and `pciio_device_win_populate` (IP30 `xbridge.o` 0x644 to 0x6ac; IP27 0x684 to 0x6e8, same values), granule 1 MiB unless stated. The base passed is `0x200000` (the register `s5` holds the constant `lui 0x20` from 0x47c to 0x658, read in both builds).

| Map (soft offset) | Granule | Populated range | Used for | Grade |
|---|---|---|---|---|
| I/O (+2120) | 1 MiB | base 0x200000, size 0x0ff00000 | I/O base-address registers (space 2) | established arguments |
| low memory (+2136) | 16 KiB | base 0x4000, size 0xfc000 (to 0x100000) | memory registers whose type bits say "below 1 MiB" | established arguments |
| 32-bit memory (+2152) | 1 MiB | base 0x200000, size 0x3ff00000 | other memory registers, 32-bit and 64-bit, and the ROM register | established arguments |

`pcibr_slot_addr_space_init` (0xc770) sizes each register by the usual write-ones probe and asks `pcibr_bus_addr_alloc` (0xdacc) for the register's size aligned to itself, from the map for its type (I/O: 2, below 1 MiB: 4, other: 5). A 64-bit memory register is placed in the 32-bit map; nothing is placed above 4 GiB. The 32-bit memory range ends 1 MiB past the `0x4000_0000` limit the PIO helper accepts, so a function allocated the last megabyte could not be reached by the PIO helper (inferred from the two constants; not observed to happen).

## What a PCI card cage has to present to this code

Everything below is the hardware's contract with these routines, read from their requirements; the machine-specific cage facts (widget numbers, slot counts, part identity) are in [crosstalk-link.md](crosstalk-link.md) and [xbow-family.md](xbow-family.md).

- A crossbow widget whose identification word is part `0xc002` with manufacturer 54, or part `0xd002` with manufacturer 36. `xbridge_init` (`xbridge.o` 0x0) registers `xbridge_attach` for exactly those two (0x18 to 0x40); no other part number reaches it. The 3-slot Octane PCI module is on port 13 and a shoehorn takes any of the four option ports 9 to 12 ([xbow-family.md](xbow-family.md), "Which widget sits behind which port").
- A widget revision word of at least `0xc0024`: below it the PCI I/O window does not map (above) and `xbridge_attach` applies revision workarounds (the stores at soft +0xa98 and +0xa9c; [ip30-kernel-bridge-routines.md](ip30-kernel-bridge-routines.md)).
- Type 0 configuration cycles for device numbers the attach loop scans, slot minimum to slot maximum (soft +56 and +57; 0 to 7 for these two parts, [ip27-kernel-bridge-routines.md](ip27-kernel-bridge-routines.md)). A device number whose identity read is not all ones is treated as a present function, and its vendor and device numbers are what the connection registry matches (inferred from `pcibr_slot_info_init` 0xb768 and the registry call, not read to the last branch).
- The memory and I/O windows of the table above, translation entries (the entry count is read from soft +112 at attach), the Device registers for slots 0 to 7, the Control swap bits, interrupt pins 0 to 7 and the write-ones BAR sizing of each function. The windows in PCI address space are the host's to assign; IRIX uses the ranges in the previous section and needs the cage's PCI bus to decode them.
- What the module's or the shoehorn's own Bridge revision is: unknown (see [open-questions.md](open-questions.md)).

## Open

- The PIC branches (`lh 114(soft) == 2`) of the PIO helper at 0x153c, 0x173c, 0x17f4 and 0x1784 were not read.
- The default CPU named in the interrupt fallback of the kernel note is a global the kernel sets elsewhere; not chip-specific.
