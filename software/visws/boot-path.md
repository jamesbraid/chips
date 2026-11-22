# Visual Workstation 320 and 540: what the firmware hands over

This page records what the firmware does from reset and what it leaves behind for the NT loader and HAL and for the Linux
port. The reset path and the hand-off tables are read from the PROM 1.0006 and 1.1005 images ([firmware.md](firmware.md) for their
layout); the rest comes from the NT and Linux side. 1.0002, 1.0004 and 1.0005 are held too and were compared against 1.0006
([firmware.md](firmware.md#from-10002-to-10006)); [what they do differently at reset](#older-releases-and-reset) is below. 1.1002 to
1.1004 are not held. Addresses written `1.0006@` or `1.1005@` name the version read; an unlabelled routine was read in 1.0006 and
its 1.1005 counterpart was compared, as [firmware.md](firmware.md#from-10006-to-11005) says. Grades as in the [README](README.md); "software expectation" means the shipped
software assumes it. Reading was done with objdump over the whole boot block and in Ghidra (x86, 32-bit, base `0xf00000`)
for the main-module routines quoted below.

## Start-up sequence

| Step | What | Grade |
|---|---|---|
| 1 | Reset vector at physical `0xfffffff0` is a near jump into the boot block at flash `0x7c000` | established (image) |
| 2 | Real-mode boot code gives the segments 4 GiB limits, sets up caching, optionally runs a patch record, then runs a table of eight set-up steps (the legacy I/O chip, DMA controller, 8259 pair, PIIX4 and Lithium set-up; [below](#the-boot-block)) | established (image) |
| 3 | The whole 512 KiB flash is copied to RAM at `0x80000`, and 32-bit code in that copy expands the compressed modules to `0xf00000`-`0xff0264` and calls the entry at `0xf00000` | established (image) |
| 4 | The main module reads the Cobalt bank registers to size memory, tests RAM, maps its device windows, sets up Lithium, starts the other processors and writes the processor table, builds the ARC tree and vectors | established for the parts quoted below; order inside the module only partly traced |
| 5 | A progress bar and the first start-up messages appear; Esc enters the firmware menus; otherwise the first boot entry runs | established (guide) |
| 6 | The firmware's own disk and file services load the OS loader named by `OSLoader` from `OSLoadPartition` or `SystemPartition` and pass it the start-up options | established (guide, loader strings) |
| 7 | The loader loads kernel and HAL, passes the loader block, and the HAL takes over devices | established (loader and HAL read) |

The power-on diagnostics level is "quick" or "extensive"; extensive also tests RAM at about 0.1 s per megabyte, and
the firmware can switch itself to extensive after a boot that did not complete (guide).

## The boot block

**Established (flash `0x7c000`-`0x7ffff` read in full).** The code below is 16-bit with 32-bit operand overrides until the
jump to the protected-mode loader.
The boot block's code is byte-identical in all five held images (1.0002 to 1.1005; only its build-time trailer differs); its offsets are flash offsets, and the steps below are read from 1.0006's copy (the 1.1005 addresses quoted elsewhere on this page are main-module addresses, not boot-block ones).

1. **Entry.** `cli`, `cld`, then the reset-time `EAX` and `EDX` are parked in two MMX registers (so they survive; the
   purpose is inferred: `EDX` holds the processor signature at reset). A flat 4 GiB descriptor table is loaded, protected mode is entered once to
   load the 4 GiB segment limits and left again ("unreal mode"), so real-mode code addresses all of memory. Progress
   is shown as byte writes to I/O port `0x80` (`0xdf`, `0xdd`, `0x4b`, then the step numbers below).
2. **Caches.** Caches are disabled and flushed, every MTRR is cleared, and one variable MTRR is set over the flash window
   (base `0xfff80000`, type 4, write-protect). Cache is then re-enabled (post code `0xdd`). Step `0x02` below clears the whole MTRR set again
   when the processor reports fixed-range MTRRs.
3. **Self-test module (the old "patch record").** If the 24-byte trailer ending at flash `0x79fc0` has a non-zero, non-`0xffffffff` length word and the
   covered words sum to zero, the code jumps to the start of the record (flash `0x74000`) with a return address in
   the boot block. Both held images carry one, and it is the power-on self-test and memory-bank set-up
   ([the self-test module](firmware.md#the-self-test-module)), not a patch.
4. **Set-up steps.** A table of (step number, handler) pairs is walked; each step number is written to port `0x80` first.
   The steps in the image are:

   | Step | Action | Grade |
   |---|---|---|
   | `0x02` | if `MTRRcap` reports fixed-range registers, write zero to 28 MTRR registers listed in a table (`0x2ff`, the fixed and variable ranges) | established |
   | `0x06` | enable the cache (clear `CD` and `NW`, flush) | established |
   | `0x10` | NS87307: 26 index/data writes through ports `0x2e`/`0x2f` activate logical devices 0 to 8, put the GPIO block at `0x0fc0` and the power-management block at `0x0fc8`, then write the power-management register 1 with bit 7 (the GPIO-enable bit Linux also sets) | established; the logical-device meanings are the part's standard layout, inferred |
   | `0x12` | initialise the DMA controllers (writes to ports `0x08`, `0xd0`, `0xd6`, `0x0b`, `0xd2`, `0xd4`) | established |
   | `0x14` | initialise the two 8259s: master vector base `0x08`, slave `0x70`, all inputs masked | established |
   | `0x1a` | write nine (register, value) bytes into the PIIX4 ISA bridge's configuration space (bus 0, device 4, function 0) through Lithium B's configuration window at `0xfd0000f8` and `0xfd0000fc`: register `0x04`=`0x0f`, `0x4e`=`0xf4`, `0x60`=`0x09`, `0x69`=`0xf2`, `0x76`=`0x0c`, `0x77`=`0x0c`, `0xb0`=`0x4d`, `0xb3`=`0x60`, `0xcb`=`0x25` | established; device identity inferred from Linux |
   | `0x1b` | PIIX4 power-management function (device 4, function 3): register `0x40`=`0x0f80` (base `0x0f80`), register `0x80`=`0x01` (enable) | established |
   | `0x2a` | set the low five bits of the dword at `+0x58` in both Lithium bridge windows (`0xfc000000`, `0xfd000000`) | established |

   The PM base `0x0f80`, the GPIO base `0x0fc0` and the NS87307 power-management base `0x0fc8` are the values Linux's
   `setup.c` uses, so Linux repeats work the firmware has already done (Linux does it again without checking).
5. **Shadow and hand-off.** The 512 KiB flash is copied (`rep movsl`) to RAM at `0x80000`, the caches are re-enabled and a
   far jump goes to flash offset `0x7d800` in that copy (physical `0xfd800`), 32-bit flat code compiled from C. It
   loads its own descriptor tables, sets the stack to `0xeffff0`, checks the `SHDR` tag (post code `0xce` and a loop if it is wrong),
   expands the five sections ([firmware.md](firmware.md)) and calls the entry address from the header (an indirect call;
   the target being `0xf00000` is inferred from the header field). **Software expectation:** RAM at least up to 16 MiB works
   at this point, before any memory sizing the main module does.

## The main module

**Established unless marked (Ghidra decompilation and listing of the quoted routines; the module is about 340 KB and was
not read in full).**

1. **Board identification.** Board type is `(inb(0x0fb2) >> 2) & 0xf` and board revision `inb(0x0fc0) & 0x7f`. Linux reads
   the same two places (PIIX4 general-purpose input bit 18, shift 2, and the NS87307 GPIO data register, 7 bits), so
   the firmware and Linux agree on where they are. The firmware also uses the type (zero for the 320) to pick a delay while
   other processors start.
2. **Memory sizing.** The Cobalt revision byte at `0xc2000008` selects where the bank registers are read. The firmware
   first clears bit 0 of the Cobalt memory-controller register at `0xc6000000`, then reads sixteen bank registers at an
   8-byte stride from `0xc6000048` (from `0xc6000050` unless the revision is `0xa0` or `0xa8`, the "Cobalt Lite" values in
   [questions](../../questions/visws-firmware-open.md)). For each: bit 2 set marks the bank as absent or bad, otherwise bit 0
   set means populated, and bit 1 chooses 128 MiB (set) or 32 MiB (clear). The total is the sum (`1.0006@0xf02d60`; the same logic, with reordered instructions, in 1.1005 at
   `0x1102cc0`). The main module only reads the bank registers: the self-test module that ran before it wrote them, by probing the
   RAM ([below](#memory-controller-and-graphics-memory)). A separate RAM test then marks good and bad pages ("low 16 MB good",
   "low 32 MB good", "all 128 MB good" are its outcome strings). The reset values of the bank registers are still unknown.
3. **Firmware address map.** The firmware builds page tables (`setup_memory_map`) and maps these windows: Lithium A and B
   (`0xfc000000`, `0xfd000000`), the Cobalt processor, interrupt and memory blocks (`0xc2000000`, `0xc4000000`,
   `0xc6000000`), the retrace register (`0xca000000`) and the display back end (`0xd0000000`, 0x81 pages), the local APIC
   (`0xfee00000`), the flash (`0xfff80000`, 0x80 pages), and several small windows at `0xfe000000`, `0xff000000`,
   `0xff004000`, `0xff018000` and `0xff01c000` that this repository does not describe (unknown).
4. **Lithium set-up.** One routine writes `0xffffffff` to `+0x48` and `0x81f` to `+0x58` of both bridge windows, then does
   a read-modify-write on the five dwords `+0x60` to `+0x70` (mask `0xfffffbc1`, then bits set from a board-revision-
   and variable-dependent value), and finally reads the Lithium A identification dword and prints an error unless it
   equals `0x100210a9` (vendor `0x10a9`, device `0x1002`; 1.1005 drops the message). The bit meanings of `+0x48`, `+0x58` and
   the five dwords at `+0x60` to `+0x70` are unknown, but the choice of values is read: [below](#pci-bus-numbering-and-windows).
   The helpers that write bytes to `+0x44` and `+0x45` are traced in the same section.
5. **Graphics memory.** `gfxmem_alloc` (`1.0006@0xf04a70`, `1.1005@0x1104840`) chooses the graphics reservation and enters it
   as memory type `0x16` in the loader block; `cogfxmem` and `maxpmem` steer it. Read in full: [below](#memory-controller-and-graphics-memory).
6. **PCI resources.** The first reading missed the PCI code: the main module does walk PCI-to-PCI bridges and assigns their bus
   numbers and windows (`1.0006@0xf1fe70`, strings `assign_1_bus: ...`), and numbers the two Lithium bridges itself. See
   [below](#pci-bus-numbering-and-windows). Whether it assigns resources to endpoint devices for its own boot devices
   was not traced (the drivers were not read); the OS side assigns anyway (see PCI enumeration below).
7. **Cobalt interrupt controller identification.** One routine writes the interrupt controller's `+0xffc` word as
   `(old & 0xf0ffffff) | 0x04000000` (`1.0006@0xf04072`, same in 1.1005): bits 27 to 24 are set to 4 and the enable bit at 8 is
   left alone. Which field that is, is not stated anywhere (inferred: an identification number for the controller).

### Older releases and reset

**Established (1.0002, 1.0004 and 1.0005 compared with 1.0006 and 1.1005, [firmware.md](firmware.md#from-10002-to-10006)).** "PROM 1.2"
is 1.0002, the oldest release held. It asks something different of the machine from 1.1005, not less: it needs the Lithium `+0x40`
read-modify-write below. What differs, for an emulator that runs the older images or one that wants to know which of these accesses the contract needs:

- **Lithium `+0x40` (1.0002 and 1.0004 only).** The Lithium set-up routine reads and writes `+0x40` of both register pages:
  window A (`0xfc000000`) ends with the top byte `0x01` and bit 5 set, window B (`0xfd000000`) with the top byte `0` and bit 5 set
  (`(old & 0x00ffffdf) | 0x01000020` and `(old & 0x00ffffdf) | 0x20`). The page must hold those bits. 1.0005, 1.0006 and 1.1005 do not touch it.
- **`0xff001000 = 0x4100` (1.0004 to 1.1005, including 1.1005).** When the Lithium generation is exactly 5 (the word at `0xff01c004`
  is `0x366c3dfb`, the stamp that a real machine's registry shows as "Serial I/O: 366c3dfb"), the entry routine stores `0x4100` in a
  dword at offset `0x1000` of the two-page window at `0xff000000`. The window must accept a 32-bit write there; the register's
  meaning, and its value on any other generation, are unknown. 1.0002 neither maps the window nor writes it. (`1.0004@0xf00250`,
  `1.1005@0x1100270`.)
- **Processor identity.** From 1.0004 the firmware checks that all processors look alike (the report strings name the jumper
  setting, mixed processors and unequal L2 sizes); an emulator with several processors should give every one the same CPUID signature (stepping is ignored) and L2 size.
  The check (`1.0004@0xf010b0`) loops over four slots, reads the signature and feature words from the table at `0x1e06 + 20*i` and
  `0x1e0a + 20*i`, compares them with per-processor speed and L2 words, stores a flag word in extended CMOS bytes `0x98` to `0x9b` (ports `0x72`/`0x73`) and always
  returns 0: a mismatch is reported and recorded, never fatal (established for 1.0004; the 1.1005 routine was not compared). It does not read MSR `0x2a`. Speed comes from the MSR `0x2a`
  ratio field through a table that every release from 1.0002 has (`1.0002@0xf1d5f0`, `1.0004@0xf1e110`, `1.0005@0xf1e110`, `1.0006@0xf1e180`, `1.1005@0x11197f0`;
  1.0006 adds the 600 and 650 MHz rows and 1.1005 has two tables); a ratio missing from the table makes
  1.0002 to 1.0006 time the processor with `rdtsc` against the real-time clock's update-in-progress flag (register `0x0a` bit 7). A model
  that leaves MSR `0x2a` at zero gets the table's reading of code 0, 333 MHz, in the speed report; the speed line is only a report
  (inferred).
- **L2 control for slot 2 processors (1.0006 and 1.1005).** For signatures `0x672` to `0x67f` with platform id 2 in MSR `0x17`, the self-test
  module reads MSR `0x11e`, writes it with `(old & 0xff881e00) | 0x1001f`, executes `invd`, and writes the old value back
  (`1.0006:test+0x4041`). Older images skip this.
- **Everything else this page records at reset is the same in 1.0002 to 1.0006:** the boot block, the self-test memory-bank probe, the
  memory descriptor list and bank step, `gfxmem_alloc`, the display start-up and the frame buffer at `0xa00000`. 1.1005's differences
  are in [firmware.md](firmware.md#from-10006-to-11005).

## Memory controller and graphics memory

Registers of the Cobalt memory-controller block at `0xc6000000` as the two images use them. The block is not described by
the Linux code or the HAL beyond the error registers, so every meaning here comes from the firmware's use (inferred unless
marked) and the names are descriptive only.

| Offset | Access in the firmware | Use | Grade |
|---|---|---|---|
| `+0x00` bit 0 | self-test sets it (writes 1) before filling a block of RAM with ones and flushing the caches, clears it (writes 0) when the probe ends; the main module clears it before sizing | error-check (ECC) enable; the HAL sets it together with the Cobalt CPU block's ECC bit | the accesses established; the meaning inferred |
| `+0x08`, `+0x10` | read | the self-test's delay: it takes half of `+0x08` and waits for `+0x10` to fall to that value and rise through it, between probe writes | inferred (a free-running counter and a period) |
| `+0x18` | written 0 | cleared right after the check bit is set; after a failed read-back the test reads `+0x28` and `+0x30` (a failing address and a byte-lane mask, looked up in a table of 65 entries) | inferred |
| `+0x48 + 8*i` (Cobalt revisions `0xa0` and `0xa8`) or `+0x50 + 8*i` (all others), i = 0 to 15 | written by the self-test, read by the main module and the "RAM Bank Control Regs" report | bank control: bit 0 enabled, bit 1 128 MiB rather than 32 MiB, bit 2 absent or bad. The self-test stores 3, 2 or 0 | read side established; the write side inferred |

**Bank detection. Inferred (self-test code read as a listing, `1.0006:test+0x80a7`-`0x8300`; not run).** There is no SPD or
other DIMM EEPROM access in either image: a search for SMBus use turns up the clock-generator commands and nothing else, and the
word "SPD" is in neither. Detection is a write and read-back test per bank slot `i` (0 to 15; slot stride 128 MiB): at
`i * 128 MiB + 64 MiB` it writes four 32-byte patterns (`0x12345678`, `0x5a5a5a5a`, `0xc3c3c3c3`, `0x9abcdef0`) at 16 MiB steps and zero
words to `0x00fffffc`, waits on the counter pair between writes, then reads back. From the comparison it stores 3, 2 or 0 in the
bank register (slot 0 never gets 0); which outcome gives which value was not traced (unknown). It copies the sixteen values to
the standard CMOS bytes `0x40`-`0x4f` (ports `0x70`/`0x71`; the main module's "Slot Group A to D" report reads them and counts `3` as
128 MB) and a bit mask of the slots whose value is 2 to the extended-bank bytes written as `0xb4`-`0xb7` (ports `0x72`/`0x73`).
Reset values of the bank registers are unknown (the code writes before it reads).

**Memory descriptors. Established (`1.0006@0xf02e30`, `0xf01ee0`; `1.1005@0x1102d90`, `0x1101e30`).** From the bank array the
firmware makes descriptors (type, base page, page count): the first 16 MiB (1.1005: 32 MiB) type 2, the rest of memory type 5, plus a
fixed list of low-memory descriptors (table in [firmware.md](firmware.md#from-10006-to-11005)); `maxpmem` (a number with `K`,
`M` or `G` suffix) caps the total, and 1.1005 refuses a cap below 128 MiB. MTRRs are then set from the same array
(`1.0006@0xf03100`: MTRRs are switched off, `0x200`-`0x20f` cleared, then up to four variable ranges are set, one per 512 MiB of
address space, sized from the banks present, type 6 (write-back) when coherent DMA is on and type 0 (uncacheable) when it is off,
and MTRRs are switched on again).

**Graphics memory. Established for the algorithm (`gfxmem_alloc`, decompiled and read in full for both images; the result was
not run).**

1. Inputs: total RAM in bytes; the variable `cogfxmem`. Below 64 MiB the function fails; between 64 and 128 MiB the variable is ignored
   and the defaults are used; from 128 MiB `cogfxmem` is parsed.
2. The variable is a comma-separated list of decimal numbers, `total,s0,s1,...` (up to twelve sizes after the total), in 4 KiB pages
   (the same form the HAL's miniport writes, [nt-hal.md](nt-hal.md#memory-banks-and-the-graphics-split)). If the sizes
   do not add up to `total`, the whole variable is discarded. Defaults: entry 1 `0x100` pages and entry 2 `0x500` pages.
3. Entry 1 is clamped to `0x100`-`0x1000` pages (1.1005: `0xc00`) and rounded down to a multiple of `0x100`; entry 2 is raised to at least `0x400`;
   a flat panel (panel id 3, 4 or 5, see [the display set-up](https://github.com/jamesbraid/cobalt/blob/main/devices/cobalt-graphics/prom-init.md))
   raises them to at least `0x400` and `0x800`. Every entry is then rounded up to a multiple of `0x400` pages (4 MiB), so the
   defaults end up 4 MiB and 8 MiB. If the RAM left over would be under 64 MiB the largest later entries are cut until it is not (the install
   guide's "largest value is installed memory minus 64 MB"). With fewer entries than the number of 32 MiB units in RAM the
   entries are merged by slot masks (details in the code, not reproduced).
4. Placement: each entry is carved, in order, from descriptors of type 2 or 5 whose base is at or above 16 MiB, as type `0x16`
   descriptors that start on a 4 MiB boundary. The next piece's search starts at the following 32 MiB boundary, and RAM above
   384 MiB makes the first start 32 MiB. So the carve-out is scattered in 32 MiB steps through low memory, not placed at the
   top of RAM. Agreement: a published registry export of a real 512 MiB machine lists reserved ranges at the starts of the
   32 MiB blocks `0x2000000`, `0x4000000`, `0x6000000`, `0x8000000`, `0xa000000`, `0xc000000`, `0xe000000`, and `0x20000000`, `0x22000000` of 4, 12,
   12, 8, 4, 4, 4, 4 and 4 MiB ([board data](https://github.com/jamesbraid/cobalt/blob/main/devices/cobalt-graphics/board-data.md)).
5. The HAL turns those type `0x16` descriptors into the miniport's bank list (section 6 of Boot into NT below), and
   the miniport's rule of at least two banks matches the two entries (inferred).

Which numbers the control panel's profiles write, and the factory default of `cogfxmem` (none was found in the image's
variable defaults), are unknown.

## Display back end start-up

The firmware programs the display back end at `0xd0000000` itself: the text console and the boot screens. The reading, with every
register write in order and the mode table, is in [the Cobalt repository's page](https://github.com/jamesbraid/cobalt/blob/main/devices/cobalt-graphics/prom-init.md).
Two facts for this page: the self-test checks that the ID register at `+0x14` reads `0x666` (a triple in its table,
`1.0006:test+0x96f7`, `1.1005:test+0x9775`; the main module has no such check), and the main module keeps the low nibble of `+0x00`
(`1.0006@0xf00200`) as the display engine's revision, the "Display Engine: 002" of a real machine's registry. The coherent-DMA
default does not come from it: `1.0006@0xf00210` classifies the word at `0xff01c004` (`0x35c0194c` is 2, `0x35f7357f` is 3, above that 4, else -2) and
coherent DMA is on when the result exceeds 2, compared unsigned (`cmp $3; jae` at `1.0006@0xf00269`), so the `-2` an unrecognised stamp gives also turns it on, unless `coherentdma` begins with `n` (`1.0006@0xf00250`).

## PCI bus numbering and windows

**Windows the main module maps (`1.0006@0xf03980`, `1.1005@0x1103730`; physical, 4 KiB pages). Established.**

| Window | Size | Role |
|---|---|---|
| `0xf0000000` | 64 MiB | PCI memory window of Lithium A (`1.0006@0xf1f6f0` pairs it with A) |
| `0xf4000000` | 64 MiB | PCI memory window of Lithium B; a real machine's registry export gives the first PCI bus ports from `0x10` and memory translated to `0xf4000000`, the second ports `0x8000`-`0xffff` and `0xf0000000`, which fits B as the first bus |
| `0xfc000000`, `0xfd000000` | 4 KiB | the Lithium A and B register pages (identification at `+0x00`) |
| `0xfc800000`, `0xfd800000` | 8 MiB | one window per bridge, A then B; role not traced |
| `0xf8000000`, `0xf9000000`, `0xfa000000`, `0xfb000000` | 16 MiB each | mapped; purpose not traced |
| `0xd0000000` | 0x81 pages | display back end |
| `0xc2000000`, `0xc4000000`, `0xc6000000`, `0xca000000` | 1 page each | Cobalt CPU block, interrupt controller, memory controller, retrace register |
| `0xff004000` (3 pages), `0xff018000` (4), `0xff01c000` (1), `0xfe000000` (1) | | Lithium-side blocks, not described elsewhere; the word at `0xff01c004` selects the Lithium generation |
| `0xff000000` | 2 pages | Lithium-side block; from 1.0004 (not 1.0002) the entry routine stores `0x4100` at `+0x1000` when the Lithium generation is 5 ([above](#older-releases-and-reset)) |
| `0x00fff000` | 1 page | physical address just under 16 MiB, mapped from 1.0004; the first dword is read by `1.0006@0xf17f40`, role unknown |

**Bus numbers. Established (`1.0006@0xf1f6f0`-`0xf1f8f0` and the helpers `0xf20700`, `0xf20730`, `0xf20f90`, `0xf20fa0`; the same
code is in 1.1005 at `0x111a8ea`).** Two helpers write a byte to `+0x44` (primary bus number) and `+0x45` (subordinate bus number) of a
Lithium window, selected 0 for A and 1 for B. The sequence: A is first given primary `0xff`; a counter that starts at `-1` is
incremented, so **Lithium B gets bus 0** (subordinate `0xfe` while its subtree is scanned, then the highest bus number allocated behind
it), then the counter is incremented again and **Lithium A gets the next number** (bus 1 when nothing sits behind B), subordinate
`0xff`. The firmware's root bridge objects carry type 1 for B and 0 for A, memory window bases `0xf4000000` and `0xf0000000`, and I/O bases
`0x1000` (B) and `0x9000` (A). The PIIX4 at device 4 on bus 0 is consistent
with B being bus 0, which answers the earlier question of which bridge is bus 0.

**Configuration access. Established.** Three routes appear: the boot block and the self-test module go through Lithium B's
window, an address word at `+0xf8` and a data word at `+0xfc` (the address word is `0x80000000 | bus << 16 | device << 11 |
function << 8 | register`; example `0xfd0000f8 = 0x80002004`, `0xfd0000fc = 9` writes the PIIX4's command register); the
main module's generic functions (`1.0006@0xf1f340`-`0xf1f6e6`) use ports `0xcf8`/`0xcfc`; and the main module sends the stop-grant special cycle
the way Linux does (`0xfd0000f8 = 0x8000ff00`, `0xfd0000fc = 0x120002`, `1.0006@0xf18920`). Whether ports `0xcf8`/`0xcfc` reach the same
configuration cycles as the window for devices behind the bridges is not stated in the code (unknown).

**Bridge assignment. Established (`1.0006@0xf1fe70`, `0xf1fde0`, `0xf20ed0`).** The firmware scans devices 0 to 31 and functions
0 to 7 on a bus for class `0x0604` header-type-1 bridges, recursively, then assigns the bridges' memory and I/O base and limit
registers from the root window downwards (largest alignment first, memory alignment at least 1 MiB, I/O at least 4 KiB) and
sets bridge control bits (command register `| 5`, `| 6` when a memory window is open). This is the code the release notes call
"PCI bridge support" (1.1002); it is first in 1.0005 (`1.0005@0xf1fdf0`; 1.0002 and 1.0004 carry no bridge-assignment code or strings, so there the
firmware leaves bridge windows to the OS, inferred) and is the same in 1.0006 and 1.1005. It prints "This bridge supports 32 bit IO" or "only supports 16 bit
IO" when a debug flag is set (the strings are removed in 1.1005).

**Lithium set-up. Established for the writes (`1.0006@0xf20620`, `1.1005@0x111b496`; same values; 1.0005 is the same as 1.0006 at `0xf205a0`, and 1.0002 and 1.0004 add the `+0x40` writes [above](#older-releases-and-reset)).** For both bridge windows:
`+0x48 = 0xffffffff`, `+0x58 = 0x81f`, and for each of the five dwords `+0x60`, `+0x64`, `+0x68`, `+0x6c`, `+0x70`:
`new = (old & 0xfffffbc1) | 0x400 | 0x20c2`, where `0x400` is applied unless `coherentdma` begins with `n`, and `0x20c2` only on Lithium
generation 5 or later and unless `streambuffer` begins with `n`. The generation (`1.0006@0xf00190`) is 1 when the byte at B `+0x08` is
zero and otherwise 2, 3, 4 or 5 when the word at `0xff01c004` equals `0x35c0194c`, `0x35f7357f`, `0x363e4470` or `0x366c3dfb`, 6 when it is
above the last and -2 (`0xfffffffe`) for any other value. The callers compare the result unsigned (`cmp $5; jb` at `1.0006@0xf20672`), so an unrecognised stamp counts as a generation of 5 or later and gets the `0x20c2` bits. Read as Unix times the thresholds are 1998-07-30, 1998-09-10, 1998-11-02 and
1998-12-07; the same word appears in the real machine's registry as "Serial I/O: 366c3dfb", the last value, so the word is an
identification stamp of another ASIC on the machine and the generation reflects its release (inferred). The meanings
of the bits (`0x400` coherent DMA, `0x20c2` stream buffering) are named only by the two variables; the five dwords are likely
per-DMA-channel controls (inferred, no register source). Before the OS, the firmware also disables the PIIX4's four PCI interrupt
routing registers (configuration `0x80002000`, register `0x60`, value `0x80808080`) and clears the edge/level controls (`0x4d0 = 0`,
`0x4d1 = 6`) (`1.0006@0xf205f0`).

## Boot into NT

1. **Files and names. Established (guide, Recovery CD-1).** Boot files are `arcldr.exe` (the loader; "ARCx86 OS Loader
   V4.0", SGI build of 1999-01-22; in a directory such as `\os\winnt40\`) and the HAL, copied to the system partition
   as `hal.dll`. For a one- or two-processor NT the HAL is `halbrgup.dll` or `halborg.dll` renamed; the installer lists
   `halborg.dll` and `arcsetup.exe` as added files and removes the stock `hal486c`, `halapic`, `halmca`, `ntdetect.com`
   and `setupldr.bin`. So NT is started by the ARC loader path used on MIPS and Alpha NT, without `ntldr`,
   `boot.ini` or `ntdetect`. Which HAL file, UP or MP, setup copies as `hal.dll` is not recorded (neither name occurs in
   the standard text-mode setup file; the SGI setup program does the copy).
2. **Loader services. Software expectation.** The loader calls firmware vectors for disk and file access (its strings
   carry SCSI read-capacity and sense decoding, a Hitachi CD-ROM drive fix, El Torito CD booting, NTFS, hibernation
   file handling, a TFTP and IPsec network path), and reads these environment variables from the firmware:
   `consoleout`, `consolein`, `systempartition`, `x86systempartition`, `osloader`, `osloadpartition`, `osloadfilename`,
   `osloadoptions`. Its partition names are the ARC forms `multi(0)disk(0)fdisk(0)partition(0)`, the same with
   `eisa(0)`, and `scsi()` for SCSI after firmware 1.1002.
   **The call table. Established (loader code read at file offset `0x790`; firmware code read at `0xf42240` and the
   tables it copies).** Like MIPS and Alpha ARC machines, the firmware keeps an ARC *system parameter block* at physical
   `0x1000`: the signature `ARCS`, length `0x48`, version 1, revision 10, then pointers (restart block, debug block and the
   general-exception and TLB-miss vectors are zero or unused), the firmware vector length `0x8c` and pointer `0x1200`, the
   private vector length `0x3c` and pointer `0x1300`, and an adapter count of zero. At start-up `arcldr.exe` reads those
   fields from `0x100c` to `0x1028` into its own globals; it reaches every firmware service through the vector, and
   prints "Unimplemented Firmware Vector called (FID n)" for an empty slot. The firmware copies its static tables to
   `0x1200` and `0x1300` when the hand-off is prepared. The firmware vector has 35 four-byte entries in the standard ARC
   order: 0 Load, 1 Invoke, 2 Execute, 3 Halt, 4 PowerDown, 5 Restart, 6 Reboot, 7 EnterInteractiveMode, 8 (reserved, points
   at data), 9 GetPeer, 10 GetChild, 11 GetParent, 12 GetConfigurationData, 13 AddChild, 14 DeleteComponent, 15 GetComponent,
   16 SaveConfiguration, 17 GetSystemId, 18 GetMemoryDescriptor, 19 (reserved, zero), 20 GetTime, 21 GetRelativeTime, 22
   GetDirectoryEntry, 23 Open, 24 Close, 25 Read, 26 GetReadStatus, 27 Write, 28 Seek, 29 Mount, 30 GetEnvironmentVariable, 31
   SetEnvironmentVariable, 32 GetFileInformation, 33 SetFileInformation, 34 FlushAllCaches. The names are the ARC
   specification's for those positions (the table has no firmware symbols; entries 0 to 34 are non-null except 19); the last two ARC entries
   (test Unicode character, display status) are not in this version's table. The private vector has 15 entries (one is
   null) whose purpose was not read.
   **Which vectors the loaders call. Established (call sites in `arcldr.exe` and `arcsetup.exe`, NT 4.0 install CD).** Every
   call goes through the vector pointer the loader copied from the block at start-up (an indirect call through the entry
   offset, four bytes per index). Indices used, with the number of call sites in `arcldr.exe` / `arcsetup.exe`: GetPeer (9) 2 / 2,
   GetChild (10) 3 / 3, GetConfigurationData (12) 2 / 2, GetMemoryDescriptor (18) 4 / 4, GetTime (20) 1 / 1,
   GetRelativeTime (21) 14 / 8, Open (23) 8 / 8, Close (24) 5 / 14, Read (25) 16 / 11, GetReadStatus (26) 4 / 3, Write (27) 32 / 16,
   Seek (28) 7 / 10, GetEnvironmentVariable (30) 1 / 1; `arcsetup.exe` also calls Restart (5) 3 times. So the firmware must
   implement those fourteen; Load, Invoke, Execute, Halt, PowerDown, Reboot, EnterInteractiveMode, the tree editing calls
   (AddChild, DeleteComponent, GetComponent, SaveConfiguration), GetSystemId, GetDirectoryEntry, Mount,
   SetEnvironmentVariable, Get/SetFileInformation and FlushAllCaches have no direct call site in either loader (a count of
   direct sites; the loaders' file-system code reaches the files through Open, Read, Seek and Write only). The SPB fields read are the
   ones at `0x1004` to `0x1028`, saved to the loader's own copy; the same loader reads nothing from the private vector (no
   use of its pointer was found). Windows 2000 RTM and SP4 `arcldr.exe` ("ARCx86 OS Loader V5.00") call the same thirteen
   (GetMemoryDescriptor eight sites, Write 45); `arcsetup.exe` there adds **GetDisplayStatus (vector index 36, offset `0x90`)**, guarded by
   a test of the block's version (above 1, or 1 with revision at least 2) and of the vector length (above `0x90`), and shows
   "Your system's PROM (firmware) is below the required revision level" when a check against the text-mode setup file's
   PROM version string (`1000` for the one machine type) fails; the check compares four bytes at offset `0x4c` of the data attached to a firmware tree node (at least `0x80` bytes long)
   with that string (what the bytes are, which node, and the direction of the test were not traced; the compare is inferred to be a firmware-revision test from the message). PROM 1.0006's block (version 1,
   revision 10, vector length `0x8c`) passes the version test and fails the length test, so it has no GetDisplayStatus
   to call and Windows 2000 setup skips that call there; whether it passes the PROM check was not determined.
3. **What `ARCINFO` prints. Established (`DumpArcInfo`, `0x80014430`).** With the `ARCINFO` boot option the HAL writes, through the
   debug-port print routine (so it goes to the kernel debugger's port, not the screen), a block headed `ArcInfo:` with the
   ARC boot device name, the ARC HAL device name, the NT boot and HAL path names and the OS load options, then "Dump arc tree
   info at 0x..." followed by the whole configuration tree from the root: for each node a banner with two ids, its child and sibling
   pointers, then class (as a name and a number), type, version and revision, key, affinity mask, configuration data length,
   identifier length and the identifier string. "LoaderBlock contained no arc root" if the loader gave none.
4. **The ARC configuration tree. Established (HAL read, `DumpArcInfo`, `HalpGrabArcRevInfo`).** The HAL requires the NT loader
   block to carry an ARC root with a standard component tree (the HAL prints "LoaderBlock contained no arc root" if it
   does not). It looks up the system component, finds the child "SGI REV INFO", and under it the children "SYS TYPE"
   (a byte: 0 for the 320, 1 for the 540, inferred from the Linux board-type values and the HAL's branches) and
   "BOARD REV" (a byte, see below). It copies the system identifier from the tree and rewrites it into a product name that
   begins "Silicon Graphics", with a `-` in the identifier replaced by a blank and anything from a `_` on dropped. The
   identifier string in 1.0006 is `SGI-000_ARCx86`, next to the strings that name the loader variables (inferred to be the
   system component's identifier: the HAL's rewrite rules, dash to blank and cut at the underscore, fit it; the rewrite then
   gives a product name from the board type, not from this string alone).
   **Text-mode setup's side. Established (`txtsetup.sif` on the SGI NT 4.0 install CDs).** Setup maps the system identifier string to a
   HAL: `SGI-320_ARCx86` and `SGI-540_ARCx86` are the uniprocessor machine types (`sgiborg_up`, which copies `halbrgup.dll` to
   `hal.dll`), and the same strings with `_mp` appended are the multiprocessor types (`sgiborg_mp`, which copies `halborg.dll`).
   So the firmware's system identifier carries the model number and a `_mp` suffix when more than one processor is present;
   the held 1.0006 image's `SGI-000_ARCx86` is then probably a template, not the string a running machine reports (inferred; a 1999 user report of
   `SGI_ARCx86_mp` is the same pattern with the number missing). Setup's HAL-load step names `arcsetup.exe` in place of the
   stock `ntdetect.com`, with the setup file's own comment that this is a placeholder, and the stock `hal486c`, `halapic`,
   `halmca` and `ntdetect` are commented out.
   The HAL also carries code and strings to add MultiFunctionAdapter, Flash, Audio, Video, Raid, SCSI, Keyboard, Mouse and
   processor nodes to the NT registry itself (`HalpAddMultiFunctionNode`, `HalpFixupRegistry`); the 1.0002 notes show
   the firmware creates the floating-point nodes. **Firmware side. Established (strings; the 1.0006 data module).** The
   firmware builds the tree itself: the nodes "SGI REV INFO", "SYS TYPE" and "BOARD REV", a configuration key `CPUMask`, processor
   components with FPU children (`borg_cpu_install`), `video()`, `serial(0)`, `serial(1)`, `console`, `keyboard()`
   and `pointer()`, and the memory descriptor list (`alloc_memdesc`). Component classes, keys and types were not decoded.
5. **Board revision byte. Inferred.** The HAL treats `BOARD REV` below 6 as one hardware generation of the 320, 6 to 11
   as the second and 12 or above as the third; the 540 with revision 0 is a special case and any other 540 revision uses
   the third generation's tables. The thresholds are the same as the ones the Linux port applies to the raw 7-bit value
   it reads from the NS87307 general-purpose I/O port (below 6 revision 4, below 12 revision 5, otherwise 6), so the byte in
   the tree is the raw value. That equality is the only evidence.
6. **Memory descriptors and the graphics banks. Established (HAL read).** The loader block's memory descriptor list
   carries the graphics memory, and the HAL turns it into what the graphics driver reads:
   - `HalpSpliceGfxMemory` walks the list and prints "N MB Memory [G MB Graphics, M MB NT]": descriptors of type 3 (bad
     memory) are ignored, type 22 (`0x16`, a type outside the stock NT set) counts as graphics, type 6 (firmware
     permanent) counts toward the total only, and everything else is NT memory. Pages are 4 KiB.
   - The display start-up picks the first type-`0x16` descriptor big enough for the boot-time frame buffer (the
     visible area rounded up to 512 by 128 tiles of 16 pages each) as the frame buffer base, and keeps up to 32
     type-`0x16` descriptors as banks. If there is none it prints "You need an updated PROM!", takes 256 pages from
     the loader's free memory, and carries on.
   - `HalpAddGbeDisplayToRegistry` publishes them under `SGICtrl\Memory` in the NT control tree as `GraphicsMemory` and
     `GraphicsMemorySize` (base and byte size of the first bank), `NumberOfBanks` and `BankAddr00` to `BankAddr31` and
     `BankSize00` to `BankSize31` (byte address and page count of each); that is the list `sgcomp.sys` reads (see
     [devices/cobalt-graphics/nt-software.md](../../devices/cobalt-graphics/nt-software.md)). Banks must start on a
     4 MiB boundary and be a multiple of 4 MiB (1,024 pages) or the HAL warns "Update the prom for aligned graphics
     memory" and does not remap them.
   So the firmware reserves the graphics memory as one or more type-`0x16` descriptors, aligned to 4 MiB; how it
   chooses the split between NT and graphics is unknown (Linux hard-codes 8 MB by default, see below).
7. **Memory map facts the HAL maps (physical).** The first 4 KiB page of memory (the BIOS data area is touched there: the
   warm-reset vector at `0x467` and the reset flag at `0x472` are written, with CMOS register `0x0f` set to `0x0a` or
   `0x00`); the processor table page at `0x1000` with the table at `+0xe00` (below); the Cobalt CPU register block
   `0xc2000000`; the Cobalt APIC `0xc4000000`; the Cobalt memory controller registers `0xc6000000`; the Lithium
   bridges A at `0xfc000000` and B at `0xfd000000` (one 4 KiB window each); the local APIC at `0xfee00000`; the flash at
   `0xfff80000`. The Cobalt blocks are described in [nt-hal.md](nt-hal.md).
8. **Processor table at physical `0x1e00`. Established (HAL and Linux read; firmware writer read in the main module at
   `0xf03f10`-`0xf0421f`, Ghidra for the entry builder).** A 16-bit processor count, followed by that
   many 20-byte entries. Both the NT HAL and the Linux 2.6 port read it from the same place (Linux: the count at `0x1e00`,
   the table two bytes on, at most four processors). If the count is zero the HAL falls back to a built-in table. The table
   is the only processor description: there is no MP floating pointer and no ACPI. The Linux 2.2 and 2.4 ports instead
   hard-code two processors, ids 0 and 1, with integrated local APICs.
   **Who writes it: the firmware, from every running processor.** The boot processor stores the count 1 at `0x1e00`,
   writes its own entry, copies a 0x210-byte start-up stub to physical `0x50000`, clears the local APIC error status, and sends a startup
   IPI (vector `0x50`) to all other processors, waits (longer on a 540, board type non-zero: `0xe00000` against `0x180000` loop
   counts), then sends an INIT assert and de-assert to the same set (parking them again for the OS). Each other
   processor runs the stub from `0x50000`: it enables its APIC, increments the count at `0x1e00`, writes its entry at
   `0x1e02 + 20 * (count - 1)`, signals through mailbox bytes at `0x504`, `0x505` and `0x506` (physical, below the table) and
   halts. The boot processor's own flag has bit 1 set. An entry is: byte 0 type 0; byte 1 the local APIC id (bits 27:24 of
   the APIC id register, masked with `0xf`); byte 2 the APIC version byte; byte 3 flags (bit 0 enabled, bit 1 boot processor);
   dwords at +4 and +8 the `cpuid(1)` `EAX` and `EDX`; dwords at +12 and +16 the `cpuid(2)` `EAX` and `EDX`. So the
   first twelve bytes are the Intel MP processor entry (type, id, version, flags, signature, feature flags) and the last
   eight are the `cpuid` cache and TLB descriptor registers where the MP layout has reserved bytes. A nonzero APIC version in the first entry tells the HAL to send
   startup interrupts as well as INIT. The firmware itself reads the same table when it builds the ARC processor nodes
   (`0xf02030`, `0xf02140`). One more write during start-up: a read-modify-write of the dword at Cobalt APIC `+0xffc` that sets
   bits 27:24 to 4; the meaning is unknown.
9. **Processor start convention. Established (HAL read; standard MP).** The bootstrap processor writes a real-mode
   stub below 1 MiB, points the warm-reset vector at it, sets CMOS shutdown byte `0x0a`, sends INIT assert and
   deassert through its local APIC, and, if the APIC version is nonzero, two startup IPIs; then waits for the other
   processor to report. The Linux port uses the same warm-reset vector method.

## Boot into Linux

1. **Loader. Observed.** SGI's Linux for the workstations was started from the firmware as an ARC program: the
   firmware boot entry's `OSLoader` is `larc.exe` or `arclx.exe` on a FAT floppy or partition, `OSLoadFilename` names
   the kernel image (`/la2210.vw` for a 2.2.10 kernel built for the workstation), `OSLoadPartition` the ARC path
   (`multi(0)disk(0)fdisk(0)partition(1)`), and `OSLoadOptions` the kernel command line (`root=/dev/fd0 load_ramdisk=1`).
   Reported by users installing Red Hat 6.0 on a 320 and a 540 in 1999 and 2000; neither loader file is held.
   SGI's later Linux releases were unpacked and checked: ProPack 1.3 Visual Workstation Edition and Visual Workstation
   Environment 3.0 (README updated 2000-12-19) name the 230, 330 and 550 (PC-BIOS workstations) only, install through a
   LILO-based installer, and ship kernels 2.2.15, 2.2.16 and 2.3.99 whose configurations read leave the Visual Workstation
   option off. No `larc.exe`, `arclx.exe` or `la2210.vw` turned up in the disc file listings, a byte search of the images,
   or the extracted kernel and boot-disk packages. The kernel source package of 2.2.16 carries the Visual Workstation
   platform code (read: board type and revision, GPIO enable, two fixed processors, Lithium sanity check bypass, as in the
   history tree's 2.2 port); the 2.3.99 package carries the same files and was not read. So the ARC loaders, and how they
   build `boot_params`, are still not held.
2. **Kernel entry state. Established (Linux source).** The kernel reads the standard `boot_params` block and requires the
   loader to have set the memory size field `alt_mem_k`; if it is zero the kernel prints "Bootloader didn't set memory
   size" and assumes 128 MB. It does not use E820 from the loader: the platform code builds the memory map itself, as
   conventional memory below 640 KB, RAM from 1 MB up to the top of memory minus the graphics buffer, and the
   graphics buffer, at the top of memory and 8 MB by default (the size is a boot parameter, trimmed to whole megabytes),
   as a reserved region. The Linux port's boot-time probing is only the PIIX4 board-type bits, the NS87307 GPIO
   revision, the two Lithium device and vendor words (a warning is printed if they do not read as SGI's Lithium),
   and the Cobalt revision and APIC id registers.
3. **Tables the kernel does not get.** No MP table, no E820, no ACPI, no PnP BIOS: established for Linux 2.6 (the
   platform replaces `find_smp_config`, `get_smp_config` and `memory_setup`).
4. **Interrupt set-up the kernel assumes already done.** None: the kernel unmasks the Lithium PCI interrupt-enable
   registers (`+0x46`, all eight bits on both bridges) and enables the Cobalt APIC itself by setting bit 8 of its ID
   register without changing the id ([nt-hal.md](nt-hal.md) for the register map; Linux page for the IRQ table).

## PCI enumeration

1. **Two host bridges. Established (Linux, HAL).** Lithium A (the "Ethernet" side, window `0xfc000000`) and Lithium B (the
   PIIX4 side, `0xfd000000`) are two PCI host bridges with their own bus numbers, read from a 16-bit register at `+0x44`
   (low byte primary bus, high byte subordinate); Linux scans both and reports bridge A's bus as `pci_bus1`. The
   Lithium vendor and device words sit in its window at the ordinary config header offsets. Linux uses configuration
   mechanism 1 only.
2. **The HAL enumerates and assigns resources itself. Established (HAL read).** It walks buses, devices and functions,
   creates sub-buses behind bridges, and gives out I/O and memory base address register ranges (with a note when
   prefetchable memory cannot be provided and non-prefetchable is used instead). It does so through the Lithium window's
   own configuration data and address registers at `+0xfc` and `+0xf8`: the address value has the 32-bit bit 31 set,
   the bus in bits 23:16, the device in bits 15:11, the function in bits 10:8 and the dword-aligned register in the
   low bits, and a read or write of the data register performs the cycle; afterwards the bridge's status word at `+6`
   is written back to clear error bits. Whether firmware also assigns resources before the OS starts is unknown
   (Linux 2.6 calls its usual resource survey, which keeps firmware assignments when present); the 1.0006 main module has no
   generic PCI walk or BAR-sizing loop that a pattern search finds (see the main module section), and the boot block's PIIX4
   writes use the same Lithium window registers (`+0xf8` address, `+0xfc` data) that the HAL uses.
3. **Interrupt pins. Established (HAL and Linux tables).** Per-slot pin-to-Cobalt-entry maps exist for each hardware
   generation: five slots per bridge (the HAL's node names are "Pci A Slot 0..4" and "Pci B Slot 0..4"). The
   PIIX4's USB uses a dedicated entry. See [nt-hal.md](nt-hal.md).

## Graphics and console

The HAL's display path has a text mode on the standard VGA registers and a Cobalt graphics (frame-buffer) mode;
`HalpInitializeGbeDisplay0` can fail and the HAL falls back. The firmware displays its menus and the NT boot screen on
the Cobalt graphics output; console and keyboard devices named `consoleout` and `consolein`, `nogfxkbd` and a `console`
variable exist (a serial console option; debug output goes to COM1 or COM2 with baud rates from the `dbaud` and
`rbaud` options). The firmware's own display initialisation, mode table and flat-panel probe are read in
[the Cobalt repository's page](https://github.com/jamesbraid/cobalt/blob/main/devices/cobalt-graphics/prom-init.md); the HAL's
`cobaltVTimings` table belongs to [devices/cobalt-graphics](../../devices/cobalt-graphics/).

## What no source settles

The reset values of the memory controller's registers and what its timing registers are; whether the firmware assigns PCI
resources to endpoint devices before the OS; the bit meanings of the Lithium `+0x48`, `+0x58` and `+0x60`-`+0x70` writes and
the Cobalt APIC `+0xffc` field; where the embedded legacy-BIOS image is mapped and whether any of it
is visible to an OS; the components, classes and keys of the ARC tree beyond the nodes named above; which firmware vectors
`arcldr.exe` calls; the private vector's purpose; firmware versions 1.1002 to 1.1004; and the Linux ARC loaders. All are in
[questions/visws-firmware-open.md](../../questions/visws-firmware-open.md).
