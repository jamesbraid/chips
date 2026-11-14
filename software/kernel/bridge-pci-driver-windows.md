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
| 64-bit memory | `0x8000_0000 + PCI address` | upper limit from a constant at gp-32736, value not read | established offset, unknown limit in 6.5.30 (the 6.5.13f kernel reads its limit as `0x4000_0000` on address plus size, see the IP30 section below), block at 0x1468 |
| I/O | `0x1_0000_0000 + PCI address` | the range ends within 4 GiB; **and the revision word (soft +120, read at attach; see below) is above `0xc0023`**, otherwise the mapping fails with -1 | established, block at 0x149c (unix `0xa800000020043fe8`) |
| BAR window n | as the window's memory or I/O type, after adding the base the host assigned to that register | window record from the function's record +72 + 56 n | established, 0x1024 to 0x1098 |

Per-device 1 MiB or 2 MiB small windows (device 0 and 1 at 2 MiB, the rest at 1 MiB, from widget offset 0x200000, the layout the flash note in [xio-fibre-channel.md](../../devices/xio_fc/README.md) records) are used for the first mapping of a function when the range fits and no bus-wide swap mode conflicts; the code at 0x1108 to 0x11f0 and 0x1580 to 0x15a8 chooses a window per function and rewrites that device's Device register to point it: bit 12 selected, offset bits from the PCI address, bit 13 set when byte swap is requested. Established for the register rewrite, inferred for the choice order.

## The revision word and what each threshold changes

`xbridge_attach` reads the widget identification register with `pcireg_id_get` and stores `((id >> 28) & 0xf) | (((id >> 12) & 0xffff) << 4)` at soft +120 (+0x78), and as the label `_pcibr_asic_rev`: `xbridge.o` 0x184 to 0x1a8, `IP30/unix` `0xa800000020042234` to `0xa800000020042254`. The word is therefore the part number in bits 19:4 and the revision in bits 3:0. The manufacturer field is not in it. A Bridge (part `0xc002`) at revision N reads `0xc0020 + N`, an XBridge (`0xd002`) reads `0xd0020 + N`. Established. The compares at `xbridge.o` 0x2bc and 0x5d0 and at `pcibr.o` 0x14a8 are the same in the 6.5.22 objects, and the two tunables below hold the same initial values in the 6.5.22 `unix.IP30` (`.sdata` `0xa8000000203db188` and `0xa8000000203db18c`). The other rows were read in 6.5.30 only.

Every threshold below is a signed compare of this whole word, so on a Bridge it is a revision test, and on an XBridge it never fires, because `0xd0021` and above is above every limit. Revisions A to D are 1 to 4: the attach routine's debug name table in `xbridge.o` `.rodata` 0x1b8 to 0x1bf holds "A", "B", "C", "D" for `0xc0021` to `0xc0024` (selected at 0x2e0 to 0x31c), so the letters are established, not only inferred from Linux.

| Test | Bridge revisions it hits | Effect | Where | Grade |
|---|---|---|---|---|
| word below `0xc0024` | A, B, C | PCI I/O window mapping fails (-1) | `pcibr.o` 0x14a8 to 0x14b4, unix `0xa800000020043fe8` | established |
| word below `0xc0024` | A, B, C | stores `0x2000` at soft +0xa98 and +0xa9c | `xbridge.o` 0x2bc to 0x2dc, unix `0xa80000002004236c` to `0xa80000002004238c` | established (stores), unknown (role) |
| word below `0xc0024` | A, B, C | clears bits 9:0 of the bus timeout register (`pcireg_timeout_bit_clr`, 0x3ff) | `xbridge.o` 0x448 to 0x454 and 0x8e0 | established |
| word below `0xc0024` (the limit is `0xc0020 \| pcibr_wg_enable_rev`, initial value 4) | A, B, C | ORs bit 17 (0x20000) into soft +0x7c | `xbridge.o` 0x620 to 0x640 | established (the OR), unknown (role) |
| word at or above `0xc0022` and below `0xc0023` (limit `0xc0020 \| pcibr_prefetch_enable_rev`, initial value 3) | B only | soft +0x7c = 0x800 | `xbridge.o` 0x604 to 0x61c | established, unknown (role) |
| word below `0xc0022` | A only | soft +0x7c = 0x80000 (the later tests are skipped except bit 17) | `xbridge.o` 0x5dc to 0x600 | established, unknown (role) |
| word exactly `0xc0022` | B only | `pcibr_priority_bits_set` takes 0 where every other revision takes 0x20000 | `pcibr.o` 0x3a10 to 0x3a30 | established (the compare), unknown (role) |

The two tunables are the kernel's variables, so what the table shows is their initial values in the shipped image. Nothing was looked for that sets them at run time.

Other sites test the revision nibble alone, as `(1 << (word & 0xf)) & mask`, with mask 2 (revision A) at `pcibr.o` 0x440, 0x474, 0x3d74, 0x64e8, 0x83f0, 0x9898, 0x99a4 and 0xcea0 and mask 6 (A or B) at 0x9a6c. They do not compare the part. Whether a part test precedes each branch, and what each one changes, was not read: unknown.

There is no `pcibr_attach` in the IP30 kernel's symbol table: `xbridge_attach` is the attach routine for both parts (`xbridge_init` registers it, 0x18 to 0x40). The IP30 chain is `xbridge_attach` then the `pcibr_*` helpers above.

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

Everything below is the hardware's contract with these routines, read from their requirements; the machine-specific cage facts (widget numbers, slot counts, part identity) are in [crosstalk-link.md](../../devices/crosstalk/README.md) and [xbow-family.md](../../devices/xbow/family.md).

- A crossbow widget whose identification word is part `0xc002` with manufacturer 54, or part `0xd002` with manufacturer 36. `xbridge_init` (`xbridge.o` 0x0) registers `xbridge_attach` for exactly those two (0x18 to 0x40); no other part number reaches it. The 3-slot Octane PCI module is on port 13 and a shoehorn takes any of the four option ports 9 to 12 ([xbow-family.md](../../devices/xbow/family.md), "Which widget sits behind which port").
- For a Bridge (part `0xc002`), revision 4 or later, that is a revision word of at least `0xc0024` (see the section above). Below it the PCI I/O window does not map and `xbridge_attach` applies revision workarounds ([ip30-kernel-bridge-routines.md](ip30/bridge-routines.md)). An XBridge always passes. Memory and configuration windows do not depend on the revision.
- Type 0 configuration cycles for device numbers the attach loop scans, slot minimum to slot maximum (soft +56 and +57; 0 to 7 for these two parts, [ip27-kernel-bridge-routines.md](ip27/bridge-routines.md)). A device number whose identity read is not all ones is treated as a present function, and its vendor and device numbers are what the connection registry matches (inferred from `pcibr_slot_info_init` 0xb768 and the registry call, not read to the last branch).
- The memory and I/O windows of the table above, translation entries (the entry count is read from soft +112 at attach), the Device registers for slots 0 to 7, the Control swap bits, interrupt pins 0 to 7 and the write-ones BAR sizing of each function. The windows in PCI address space are the host's to assign; IRIX uses the ranges in the previous section and needs the cage's PCI bus to decode them.
- Configuration cycles for functions above 0 and for bridged buses, as the routines address them (6.5.30 `IP30boot/pcibr.o`; identical instructions in the IP27 object and in both releases). A type 0 access to function `f` of device `d` is a read or write at widget offset `0x20000 + d * 0x1000 + f * 0x100 + (register & ~3)`, `d` from 0 to 7 (`pcireg_type0_cfg_addr` 0x173cc, block 0x174bc to 0x174fc; an out-of-range device number fails an assertion). The kernel probes functions 1 to 7 of a device only when function 0's header type has bit 7 set, and treats a function as absent when the access faults or the vendor halfword reads 0xffff (kudzu repository, software/kernel/pcibr-multifunction-scan.md page). A type 1 access to a bus above 0 first stores `bus << 16 | device << 11` in the 32-bit word at widget offset 0xcc (`pcireg_type1_cntr_set` 0x120d8, store at 0x1219c for bridge types 0 and 1; a different bridge type, number 3, takes a 64-bit store at 0xc8, 0x121b8, and the type 2 block at 0x121d0 was not read) and then accesses `0x28000 + function * 0x100 + (register & ~3)` (`pcireg_type1_cfg_addr` 0x1767c, block 0x17740 to 0x1776c). Established for the arithmetic and the store; the register's name and effect are the type 1 configuration counter of [bridge-family.md](../../devices/bridge/family.md), inferred.
- What the module's or the shoehorn's own Bridge revision is: unknown (see [open-questions.md](../../questions/README.md)).

## IP30: from a Bridge widget offset to a processor address, and the registers read after a failed PIO (IRIX 6.5.13f)

Evidence: the IRIX 6.5.13f IP30 kernel, a linked ELF with symbols (SHA-256 `5ab52e7574ef157af434805d7251ee731691eea4a8f090da8b44b419aa348bcc`),
read at the virtual addresses given. This kernel has `pcibr_*` routines and no `xbridge_attach`; the PCI window helper below is the
same arithmetic as the helper at `pcibr.o` 0xf6c in 6.5.30 (matching structure and call sites, so the identification is inferred).

### The chain, in call order

All calls are direct. No Crossbow routine is in the chain (the kernel's symbol table has no `xbow_*` PIO routine), and no step reads a
HEART or Crossbow register: the address is arithmetic on the widget number.

| Step | Routine and address | What it does | Grade |
|---|---|---|---|
| user mapping | `usrpci_map` `0xa8000000200863b0` | for resolved space codes 2, 4, 5 and 6 calls `pciio_piomap_alloc` (`0x…864cc`), then `pciio_piomap_addr`; for codes 7 and 8 calls `pciio_piotrans_addr` (`0x…865d4`, `0x…86604`); then `v_mapphys` (`0x…8651c`) with the kernel virtual address it got | established for the calls; what code 8 means (BAR window 0) inferred from the window code below |
| generic PCI layer | `pciio_piomap_alloc` `0xa8000000200870ec`, `pciio_piomap_addr` `0xa800000020087124`, `pciio_piotrans_addr` `0xa800000020087168` | each calls the `pcibr_` routine of the same name; `pciio_piomap_addr` also stores the address it returns in the map at `+0x20` | established |
| Bridge layer | `pcibr_piomap_alloc` `0xa80000002007c834` (helper call at `0x…7c8bc`), `pcibr_piotrans_addr` `0xa80000002007ca9c` (helper call at `0x…7cb08`), `pcibr_piomap_addr` `0xa80000002007ca54` | convert a PCI space, address and length to a widget offset with the helper at `0xa80000002007c280`, then call the crosstalk layer | established |
| crosstalk layer | `xtalk_piomap_alloc` `0xa800000020073194`, `xtalk_piotrans_addr` `0xa800000020073204`, `xtalk_piomap_addr` `0xa8000000200731cc` | each is a bare call to the `heart_` routine of the same name | established |
| HEART layer | `heart_piomap_alloc` `0xa800000020077cbc`, `heart_piotrans_addr` `0xa800000020077d90`, `heart_piomap_addr` `0xa800000020077d74` | widget number from the registry (`0x…77aa4`), then `heart_addr_xio_to_kva` `0x…77c84` and `heart_addr_xio_to_phys` `0x…77be4`; `heart_piomap_addr` adds `offset - map base` to the map's kernel address | established |

The window helper at `0xa80000002007c280` (no symbol; objdump places it at `pcibr_write_gather_flush+0x48`) for the cases a PCI
memory BAR needs:

| Space code | Widget offset | Limit | Grade |
|---|---|---|---|
| 4 or 5 (memory) | `0x4000_0000 + PCI address` (`0x…7c590`) | address plus length at most `0x4000_0000` (`0x…7c574` to `0x…7c588`) | established |
| 6 (64-bit memory) | `0x8000_0000 + PCI address` (`0x…7c6b0`) | address plus length at most `0x4000_0000`: the check adds `0x7fff_ffff` and compares with the word `0xbfff_ffff` read from the small-data area at `0xa8000000203da930` (`0x…7c684` to `0x…7c6a4`) | established |
| 2 (I/O) | `0x1_0000_0000 + PCI address` (`0x…7c700`) | at most `2^32`; refused when the revision word at soft state `+0x54` is not above `0xc0023` (`0x…7c6c4` to `0x…7c6d0`) | established |
| 7 (configuration) | `0x20000 + slot * 0x1000 + address` (`0x…7c748` to `0x…7c754`) | address plus length at most `0x100` | established |
| 8 to 13 (BAR window n) | the window record (type word at `+0x40`, base at `+0x48`, size at `+0x50`) gives a memory or I/O type, the base is added to the offset, and the plain-space case above runs (`0x…7c5d4` to `0x…7c61c`) | offset plus length within the window's size | established |

Worked example from this arithmetic: a BAR at PCI address `0x0800_0000` reached as window 0 gives widget offset
`0x4000_0000 + 0x0800_0000 = 0x4800_0000`, and `+0x40` gives `0x4800_0040`. `heart_addr_xio_to_phys` on widget 13 then gives physical
`0xe_c800_0040` (the large window, see [the HEART page](../../devices/heart/README.md#processor-pio-windows-and-the-latches-read-after-a-failed-access-irix-6513f)).
The `0xe` is bits 35:32 of the address: bit 35 plus widget bits 3:1, not the widget number.

### What the PIO error path reads from the Bridge

After a failed access the kernel reaches `pcibr_pioerror` (`0xa800000020082158`). Every Bridge register access in the routines below is a
**32-bit `lw` at slot + 4**, the odd (low) word of the big-endian doubleword slot; there is no `ld`, and no `lw` at the even
(upper) word of a slot. Established, whole routines read.

| Slot | Register (see [Bridge registers](../../devices/bridge/README.md)) | Instruction and address |
|---|---|---|
| `0x100` | interrupt status | `lw` `+0x104`: `pcibr_pioerror` at `0xa80000002008330c` (then `andi 0x8800` and a call to `pcibr_error_dump`); `pcibr_error_dump` `0xa800000020081350` at `0x…8135c`; the helper at `0x…818ac` at `0x…818b0` and `0x…818cc`; `pcibr_error_intr_handler` `0xa800000020081a10` at `0x…81a34` |
| `0xd0` | PCI bus error address, upper | `lw` `+0xd4`: `pcibr_error_dump` at `0x…81648` and `0x…81654`; the helper at `0x…818c8`; `pcibr_error_extract` `0xa8000000200820c8` at `0x…82118` |
| `0xd8` | PCI bus error address, lower | `lw` `+0xdc`: `pcibr_error_dump` at `0x…8164c` and `0x…81650`; the helper at `0x…818c4`; `pcibr_error_extract` at `0x…82114` |

The dump forms the 64-bit address as the `+0xd4` word shifted left 32 over the zero-extended `+0xdc` word (`dsll32`/`dsrl32` at
`0x…81658` to `0x…81664`). The same routines also read, all as `lw` at slot + 4: the identification word (`+0x04`), widget error
address words (`+0x14`, `+0x1c`), error command word (`+0x44`), `+0x5c`, response buffer words (`+0x64`, `+0x6c`), `+0x94`, `+0x10c` (read and
written back) and `+0x17c`.

Slots `0x28`, `0x30` and `0x38` are not read by the PIO error path in this kernel: no `lw`, `lwu` or `ld` at `+0x2c`, `+0x34` or `+0x3c` in
the PCI routines from `0xa80000002007b000` to `0xa8000000200860c8` except in two small interrupt-routing helpers.
`pcibr_clearwidint` (`0xa800000020080fd8`) stores zero at `+0x34` and `+0x3c` (`sw` at `0x…80fd8` and `0x…80fe0`), and `pcibr_setwidint`
(`0xa800000020080fe4`) reads `+0x34` and `+0x3c` (`lw` at `0x…8102c` and `0x…81044`) and writes them back (`sw` at `0x…81058` and
`0x…81060`). Neither has a direct caller; the kernel keeps `pcibr_setwidint`'s address in a small-data table beside the error
handler pointers (at `0xa8000000203dbb90`), so how it is reached was not traced (unknown). Nothing in the range touches `+0x2c`.

What a real Bridge returns for a 32-bit read of the upper word of a register slot: the Bridge ASIC specification revision 4.0 (register
address map, Table 6, PDF pages 30 to 32, read through a page transcription, not re-read from the page image) says every register is on
data bits 31:0 of its doubleword and is reachable only by a doubleword packet with the data enables `0x0f` set, and that any other
packet type raises an address error exception. A `lw` at slot + 4 is that access. A `lw` at slot + 0 would enable bytes 7:4, not
`0x0f`, so by the specification it is an address error, not a read of zero. Established as the specification's statement; the
processor-visible effect (bus error versus returned data) was not observed and no shipped code issues such a read (unknown).

## Open

- The PIC branches (`lh 114(soft) == 2`) of the PIO helper at 0x153c, 0x173c, 0x17f4 and 0x1784 were not read.
- The default CPU named in the interrupt fallback of the kernel note is a global the kernel sets elsewhere; not chip-specific.
