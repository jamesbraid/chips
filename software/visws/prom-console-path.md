# Visual Workstation 320 and 540: what the PROM needs from the machine before its console works

Access-level reading of PROM 1.1005 for the points that decide whether a machine model reaches the firmware console: the
self-test's RAM probe and register tests, how a failure shows, the PCI scan and what it writes, the embedded legacy BIOS,
the local APIC state left behind, and A20. It extends [boot-path.md](boot-path.md) and
[emulator-requirements.md](emulator-requirements.md) and does not repeat them.

Method: the self-test module and boot block listed with objdump and followed by hand; the main module (1,555 functions)
decompiled in Ghidra (x86, flat, base `0x1100000`) with every access claim below checked against the disassembly, because the
decompiler drops dead loads (the dummy read after a store is one) and folds immediates. Grades are established, inferred
or unknown. `test+0xNNNN` is an offset in the self-test module (the module's instruction addresses equal these offsets, see
[firmware.md](firmware.md#the-self-test-module)); `1.1005@` is a main-module address. Only 1.1005 was re-read for this page.
The boot block and the self-test's memory probe are the same in the other four images (existing pages), so the RAM facts
carry back; the main-module addresses do not.

## How the self-test runs its tests

**Established (`1.1005:test+0x7856` table, dispatcher `test+0x43cc`).** The tests are rows of a table (identifier, mode flags,
routine, extended-CMOS slot for the result), run in two passes: the RAM group (flag bit 5 set) first, then the rest. A mode
byte selects rows: 4 (quick), 8 (diagnostic) or `0x10` (extended); a row runs when its flags contain the mode bit. If the
flags hold the other of 4 and 8 but not the current one, the row's result slot is stamped as skipped and the row does not
run. Before each routine the dispatcher writes the identifier to port `0x80`, records it in extended CMOS bytes `0x8e`
(and its complement in `0x8d`), and drops the front-panel line (port `0xfb7` bit 4); afterwards it raises the line. A routine
returns its result in an MMX register: zero is a pass, any other value is stored in the row's slot.

| Id | Routine | Result slot | Modes | What |
|---|---|---|---|---|
| `0x09` | `test+0x80cd` | `0xb4` | quick, diagnostic, extended | RAM probe and sizing ([below](#ram-probe)) |
| `0x0d` | `test+0x7f17` | `0xc4` | all | "DIMM Speed Check": one read of the register at `0xc6000048` ([below](#cobalt-lithium-and-piix4-register-tests)) |
| `0x0b` | `test+0x8369` | `0xbc` | all | "ECC RAM Bus" |
| `0x0a` | `test+0x85cc` | `0xb8` | all | "Test Valid RAM Banks" |
| `0x0c` | `test+0x8858` | `0xc0` | diagnostic, extended | "Test All RAM": every present bank, in full |
| `0x06` | `test+0x910d` | `0xa8` | all | "Cobalt-I/O Bus": three Lithium B bit-walks |
| `0x10` | `test+0x9646` | `0xd0` | all | "Cobalt Display ASIC" |
| `0x11` | `test+0x9222` | `0xd4` | all | "Cobalt I/O ASIC": the Lithium identification |
| `0x12` | `test+0x928d` | `0xd8` | all | "PiiX4": identification read |
| `0x13` | `test+0x950f` | `0xdc` | all | "PCI Bus B": byte bit-walks of PIIX4 configuration registers |
| `0x54` | `test+0x98c9` | `0x9c` | all | real-time clock: saves seconds and minutes at extended `0x9e`/`0x9f`, always returns 0 ([below](#rtc-row)) |
| `0xe1` | `test+0x7ec5` | none | none (flags `0x21`) | never auto-run: its flags carry no mode bit, so the dispatcher skips it |
| `0x51` | `test+0x92f4` | `0x90` | diagnostic, extended | "Memory Bus Noise" |
| `0x15` | `test+0x96e4` | `0xe4` | extended | display ASIC built-in test |

The remaining rows (identifiers `0xa0` to `0xd2`) are the serial manager's infinite-loop RAM tests and run only on command.
The identifier-to-name pairs are from the main module's report table (`1.1005@0x119c298`), which reads the same slots back
(established).

**What a failure does. Established.** Two classes, split on bit 31 of the result:

- Bit 31 set is fatal. The dispatcher stores the identifier in extended byte `0x8c`, posts `0xee` to port `0x80` and
  enters the serial test manager (`test+0x4e21`): it prints on COM1, then loops waiting for a byte on COM1, as
  [boot-path.md](boot-path.md#serial-output-before-the-console) records. Only the first test of `0x0a` (the low 16 MiB)
  can set it; the register tests fold their top two bits down into bits 29 and 28 before returning, so a failing register
  test never has bit 31 set. The DIMM check (`0x0d`) does not fold: it returns the register with bit 20 forced on, so a value
  with bit 31 set and bit 16 clear takes the fatal path.
- Any other non-zero value is a soft failure: the code is kept in the slot, nothing halts. In extended mode only, the
  dispatcher also sets extended byte `0x85` or `0x86` to 1 (what the retry around it does was not decoded; unknown).

The visible effect of a soft failure is later, in the main module. `1.1005@0x1100dd0` counts report rows whose slot is not
zero, not `0xdeadbeef` (skipped) and not `0x01010101` (never ran), prints "FAILED, error code 0x%08X" for each, and unless
the CMOS marker bytes `0x7d` = `0xbb` and `0x7e` = `0x71` select the factory autoboot mode, waits for Esc ("booting paused
by test failure") before booting. The marker is consumed when read (`1.1005@0x1100d70` rewrites `0x7e` to `0x8e`), so the autoboot mode
works once; it prompts "Type 'p' for pause" and times out. In diagnostic and extended modes the report is shown even when every
test passes (only quick mode with no failures skips it). **So a model whose register tests fail soft is stopped at a prompt; one that passes
every row is not (in quick mode).** (Established from the decompilation and the listing of `1.1005@0x1100b60`, `0x11008f0`, `0x1100dd0`.)

No beep code was found in the self-test, the boot block or the main module: their outputs are port `0x80` post codes, COM1
text and the port `0xfb7` bit 4 line, and no access to the speaker ports (`0x42`, `0x43`, `0x61`) turns up in them (checked
for immediate port numbers; a port passed through a variable was not chased). The speaker accesses are inside the embedded
legacy BIOS image ([below](#embedded-legacy-bios)). The front-panel line's effect stays unknown.

**Mode selection. Inferred.** With erased or invalid extended CMOS (the record is a four-byte magic, two state bytes and a
CRC-16 at `0x81` to `0x89`, [boot-path.md](boot-path.md#cmos-the-real-time-clock-and-the-extended-bank)), every result slot
(`0x90` to `0xef`) is set to 1 and the mode is 4, or 8 when standard CMOS byte `0x7f` bit 2 is set (`test+0x439d`). With a
valid record and extended byte `0x8b` bit 0 clear, the self-test prints "About to reset for BIST", stores `0xbb` in `0x8c`,
writes 3 to the Cobalt processor block's `+0x18` and expects a reset; where the write does not reset (a late board, see
[devices/cobalt](../../devices/cobalt/README.md)) it continues to the "test BIST result" path (`test+0x4276`), which tests extended byte `0x8b` bit 1 at `test+0x436e`: if set, it stores `0xba` in `0x8c` and enters the serial manager; if clear, it selects mode `0x10` and sets bit 7 of extended byte `0x8a` (the main module then prints "Extended boot"). Nothing in the three modules sets `0x8b` bit 0,
so which mode a second boot with persistent CMOS takes on real hardware is unknown. The consequence for a model with persistent
CMOS: a second start may run the extended set, which includes the slow tests below.

## RAM probe

**Established (`1.1005:test+0x80cd` to `0x8367`, read as a listing; same probe in the other images).** For slot `i`
from 0 to 15, in order, with `base = i * 128 MiB + 64 MiB`:

1. Write eight 32-bit words (one 32-byte block), 32-bit stores, with a pattern at each of four addresses 16 MiB apart: `base`
   gets `0x12345678`, `base + 16 MiB` gets `0x5a5a5a5a`, `base + 32 MiB` gets `0xc3c3c3c3`, `base + 48 MiB` gets
   `0x9abcdef0`. Then one zero word at each of physical `0x00fffffc`, `0x01fffffc` and `0x02fffffc`, in that order. After
   every one of the seven writes the code waits on the memory controller's counter pair: it reads `+0x08`, halves it, spins
   while `+0x10` reads above that value, then spins while it reads below it (so it needs `+0x10` to cross the half-period
   point; a counter that never moves hangs it).
2. Read back the first word of each of the four blocks, XOR-ing the four values together; for the fourth block compare all
   eight words with `0x9abcdef0` and count mismatches.
3. Decide the bank code. Zero mismatches: 3 when the XOR is `0x11111111` (each block read back its own pattern, a 128 MiB
   module), otherwise 2 (the 16 MiB blocks alias, a 32 MiB-class module); slot 0 gets 3 whenever it is not entirely absent (`test+0x825d`). Eight mismatches (nothing there): 0, except slot 0,
   which gets 2. One to seven mismatches: 2, except slot 0, which gets 3. Slot 0 is never 0. The first-word read-backs of the four blocks are each followed by the same counter wait (1.1005). The code goes to the bank
   register: `0xc6000048 + 8*i` on Cobalt revisions `0xa0` and `0xa8`, `0xc6000050 + 8*i` on every other (revision read from
   `0xc2000008` each time).
4. When the 16 slots are done, read the 16 bank registers back, store each at standard CMOS byte `0x40 + i`, and store a
   16-bit mask of the slots whose value is 2 at extended bytes `0xb4` to `0xb7`. The routine returns that mask: **any 32 MiB-class
   or partial slot makes the "RAM Sizing" row report a soft failure.**

What a wrong answer costs: an unclaimed address that reads all ones, or RAM that does not hold the pattern, makes the slot
absent (0) or 32 MiB-class (2) and the main module then counts only 128 MiB banks (1.1005), so a slot read as 2 contributes
no memory. A model that backs every populated 128 MiB slot completely (including the three zero-word addresses and all four
block addresses) gets 3 for it and 0 for the rest, with no soft failure. The bank registers must read back what was written
(32-bit). Their reset values are not read before the writes (unknown, as before).

The other RAM rows, all established from the listing (not run):

- **`0x0d` "DIMM Speed Check".** One 32-bit read of the fixed address `0xc6000048`, whatever the revision. It passes (zero)
  only when bit 16 of the value read is set; otherwise the result is the value with bit 20 forced on, a soft failure. On a
  revision other than `0xa0` and `0xa8` that register is not a bank register (the banks start at `0x50`), so this is a
  separate register whose bit 16 must read 1. On revisions `0xa0` and `0xa8` the same address is bank register 0, which holds 3 or 2, so
  the check always fails there. Its meaning is inferred from the row's name only; the register is unknown.
- **`0x0b` "ECC RAM Bus".** A conditional jump at `test+0x83a4` tests flags left by the dispatcher, not by the read before it
  (no instruction between sets them), and the dispatcher's address add always leaves them in the "not zero" state, so the
  automatic run always takes the long path (established; the short path is reachable only from the manager's `rt` command, and
  was not read). The long path: with caches switched on through one variable MTRR (`0x202`/`0x203`), clear the first 128 MiB
  and every 128 MiB bank whose register is 3 with 32-bit stores; then for every slot with a non-zero register, a slot at 2
  is marked bad at once and a slot at 3 gets three groups of four 64-bit pattern stores at slot base + 1 MiB (written as
  pairs of 32-bit stores), with the memory controller's `+0x00` bit 0 set and its `+0x18` cleared, a read of 24 words, then a
  read of `+0x18`: non-zero marks the slot bad. The result is the bad-slot mask, stored at extended bytes `0xbc` to `0xbf`. A
  controller that never reports an error (status stays 0) and banks that read 3 pass.
- **`0x0a` "Test Valid RAM Banks".** First the low memory: physical 0 to `0xffffff` with seven sub-tests. A failure there is
  fatal. Then every slot whose register is exactly 3, over `i * 128 MiB` to `i * 128 MiB + 0xff` (slot 0: `0x100000` to
  `0x1000ff`), the same seven sub-tests; a failing slot other than 0 has its register overwritten with 2 and the failure is soft.
- **`0x0c` "Test All RAM".** The same seven sub-tests over the whole 128 MiB of every slot whose register has bit 1 set (2 or
  3). Diagnostic and extended modes only. A failing slot other than 0 is set to 2.
- **`0x51` "Memory Bus Noise".** For each 512 MiB group with a non-zero bank code (the four CMOS bytes `0x40 + 4n` OR-ed),
  write 8192 zero dwords at group base + `0x1000` and 8192 dwords of all ones at group base + `0xa000`, then read the zero
  block back, up to 8192 times, flagging any non-zero word. Diagnostic and extended modes only, about 67 million reads per group.

The seven sub-tests (one shared routine, `test+0x8aa3`; each range is tested and the first failing sub-test's number is the
error class): (1) 32-bit data walk, a one and a zero walked through each bit of every dword in 32-byte lines with the
complement written 32 bytes on; (2) address-line test, 0x87654321 and 0xedcba987 stored at pairs of addresses that differ by
growing powers of two; (3) fill with ones, set the controller's ECC bit, read back, rewrite zeros, read the error status; (4) a
dword store read back as four byte loads; (5) four byte stores read back as a dword; (6) misaligned dword loads at +1, +2 and
+3 of a two-dword pattern; (7) misaligned dword stores at +1, +2 and +3 and a check of both dwords. These need byte-lane and
unaligned access to work on RAM, and every access runs with caching off except where stated. The front-panel line toggles in
step.

Costs for a model that executes them (inferred from counts, not timed): the quick set is small; `0x0b` stores 128 MiB twice per
present slot; `0x0c` and `0x51` are the slow ones, and the extended display test below spins for hundreds of millions of
iterations if bit 31 of its status never sets.

<a id="rtc-row"></a>
**RTC row (`0x54`). Established (`test+0x98c9`, `1.1005@0x1101ca0`).** The self-test reads standard CMOS seconds and minutes and
saves them at extended `0x9e`/`0x9f`; it returns 0. The main module then zeroes those two bytes, sets bit 0 of `0x9c` when a
fresh read of seconds and minutes equals the saved copy (the clock did not advance between the two reads), and sets bit 0 of
`0x9d` when the year is outside 1998 to 2040. The count function takes a non-zero `0x9c` to `0x9f` dword as a failure ("Real-time
clock is not running!"), so a clock that does not advance, or a year outside the range, is a counted soft failure that stops
the boot at the Esc prompt.

## Cobalt, Lithium and PIIX4 register tests

**Established (listing of `test+0x910d` to `0x98c9`).** The bit-walk routine (`test+0x91ad`) takes an address and a mask and does, in
order, all with 32-bit accesses: read the register (kept); write it with the mask bits set; read the dword 4 bytes above (a dummy
read, result unused); read the register; collect mask bits that are not set; write it with the mask bits clear; dummy read;
read; collect bits still set; write the 0x55555555 pattern through the mask (other bits as read); dummy read; read; collect
mismatches; the same with 0xaaaaaaaa; write the original value back. Any collected bit is a failure; the failing bit mask is
the result.

**`0x06` "Cobalt-I/O Bus": Lithium B (`0xfd000000`).** Three walks, in this order: `+0x58` mask 3 (bits 1:0; the dummy read is
`+0x5c`), `+0xf8` mask `0xfffffc` (the configuration address register; the dummy read at `+0xfc` is a configuration cycle to
whatever address the walk left in `+0xf8`, which must complete without an abort), `+0x44` mask `0x3f000000` (bits 29:24, which
are bits 13:8 of the interrupt-enable halfword at `+0x46`; dummy read `+0x48`). All three are plain read-write storage in the
model's page. If every walk passes, the routine returns the Cobalt revision word (`0xc2000008`) with its low nibble cleared
XOR `0xa0`: zero for revisions `0xa0` to `0xaf`, so a revision outside that range reports this row as failed. A failed walk
returns the failing bits instead.

**`0x11` "Cobalt I/O ASIC".** A 32-bit read of `0xfc000000`; if it equals `0x100210a9` a 32-bit read of `0xfd000000`; the
result is the last word read XOR `0x100210a9` (zero when both match). **`0x12` "PiiX4".** A 32-bit store of `0x80002000` to
`0xfd0000f8` and a 32-bit read of `0xfd0000fc`, XOR `0x71108086`: the PIIX4 ISA bridge's vendor and device words on bus 0,
device 4, function 0.

**`0x13` "PCI Bus B".** Byte walks of PIIX4 function 0 configuration registers, through the Lithium B window at `+0xf8`
(address word `0x80002000 | register`, bit 31 set, the register number's low two bits included) and `+0xfc`: register
`0x09` once with its result discarded, then `0x90`, `0x95`, `0xb2` and `0x93`, in that order. The byte lane is
`register & 3` (a mask of `0xff` rotated by it at `test+0x959d`); an independent reviewer read the lane as always 0, which
the rotate contradicts. Each walk reads the containing dword and, for the patterns all ones, all zeros and then a single bit
walked from `0x01` to `0x80` in the lane, writes the whole dword back with only that lane changed, does a dummy read of bus 0
device 4 register 0 (through `+0xf8` and `+0xfc` again) and re-reads the dword; the masked difference is the failure. The
original dword is restored last. If the window ignores the low two address bits, the aligned dwords are `0x08`, `0x90`,
`0x94`, `0xb0` and `0x90` again; whether the window does is unknown. The registers must hold every pattern in their lane.
Whether they are writable on the real PIIX4 was not checked against its datasheet (unknown); the real machine passes
the test, so the model must make them hold values.

**`0x10` "Cobalt Display ASIC".** First a single read check: the 32-bit word at `0xd0000014` must equal `0x666` (mask all
bits); a mismatch returns the address and skips the rest. Then bit-walks, in this order, of the registers (address, mask):
`0xd0000018` `0xef`; `0xd0010004` to `0xd001004c` step 4 `0xffffff` except `0xd0010018` `0x7f`; `0xd0020000` `0x3fff`;
`0xd0020004` and `0xd0020008` `0xffffffe3`; `0xd0030000` `0xffff`; `0xd0030004` `0xffff0000`; `0xd0030008` and `0xd003000c`
`0xfffffe03`; `0xd0040000` and `0xd0040004` all bits; `0xd0070000` all bits; `0xd0070004` `0x3`; `0xd0070008` and
`0xd007000c` `0xffffff00`; `0xd0080000` and `0xd0080004` `0xffffff`; `0xd0080008` `0x1f`; `0xd0080010`, `0xd0080014`,
`0xd0080018` and `0xd0080020` all bits. Every register in the list must hold written values under its mask, and the dummy read
4 bytes above each must not fault or change state (the dummy read of `0xd0010018`'s neighbour is `0xd001001c`; `0xd0080008`'s
is `0xd008000c`; unlisted neighbours must still answer). The registers are otherwise described on
[the Cobalt repository's page for the PROM's display set-up](https://github.com/jamesbraid/cobalt/blob/main/devices/cobalt-graphics/prom-init.md).
**`0x15` display built-in test (extended mode only).** Write 0 to `0xd000001c`, delay about 67 million loop iterations, then
read it up to 134 million times until bit 31 is set. Timeout returns `0x7777777`. On completion, a zero `0x0f000000` field in
the value is a pass; non-zero is the failure code.

**Failure-path summary.** All of these are soft failures (the top bits fold away), so a failing register test never halts the
self-test: it stores a code, the main module prints it and waits for Esc. The model needs: read-write registers with the listed
bit masks, the Lithium and display identification values, a Cobalt revision from `0xa0` to `0xaf`, and `0xc6000048` bit 16
set.

## PCI scan and resource assignment

**Established (`1.1005@0x111a8ea` and callees, decompiled and checked against the listing).** The PROM assigns PCI resources
itself, for bridges and endpoints, before the operating system runs. Configuration cycles in this code all use ports
`0xcf8` (32-bit address) and `0xcfc` plus the byte offset (8, 16 or 32-bit data); the address word is `0x80000000 | bus << 16 |
device << 11 | function << 8 | register & 0xfc`. (The boot block and self-test use the Lithium B window instead,
[boot-path.md](boot-path.md#pci-bus-numbering-and-windows); whether the two routes reach the same configuration space is
unknown but the PROM relies on both reaching bus 0 device 4.) The writes, in order:

1. **Lithium set-up** (`0x111b496`): `+0x48` all ones and `+0x58` `0x81f` in both windows, then the five `+0x60` to `+0x70` words
   read-modify-written, as [boot-path.md](boot-path.md#pci-bus-numbering-and-windows) lists. Then the PIIX4 interrupt routing
   registers (`0x80002000` register `0x60`, one 32-bit store of `0x80808080`) and ports `0x4d0` = 0, `0x4d1` = 6.
2. **Bus numbers.** `+0x44` of window A = `0xff`; the counter increments to 0 and bridge B gets primary bus 0 and `+0x45` =
   `0xfe`; bus 0 is scanned; then B's `+0x45` is set to the highest bus allocated, the counter increments again, A gets that
   bus and `+0x45` = `0xff`, and bus 1 (and any bus behind it) is scanned.
3. **Scan order.** Per bus: devices 0 to 31, functions 0 to 7. A 16-bit read of register 0; `0xffff` ends that device (no
   functions beyond it are tried); after function 0 the header-type byte (register `0x0e`) bit 7 decides whether functions 1
   to 7 are tried. A function whose class byte (`0x0b`) is 6, subclass (`0x0a`) 4 and header type 1 is a PCI-to-PCI bridge: it
   gets a new bus number (registers `0x18`, `0x19`, `0x1a` written primary, secondary, then subordinate `0xff`), the scan
   recurses behind it, and the subordinate number is rewritten afterwards. A class-6 function that is not subclass 1 (the PIIX4
   ISA bridge is subclass 1 and is treated as an ordinary device) or `0x80` is skipped.
4. **Endpoints.** The command register (`0x04`) is read and rewritten with bits 3:2 set. Each of the six base address
   registers (`0x10` to `0x24`) is written `0xffffffff` and read back to find its size (a 64-bit memory BAR takes two
   slots); the expansion ROM register (`0x30`) is written `0x0ffffffe` and read back for a size. No BAR is restored at this
   point.
5. **Interrupt line.** The interrupt-pin byte (`0x3d`) is mapped through a per-device table to one of the PIIX4's PIRQ inputs;
   the first user of PIRQ 1, 2 or 3 gets that PIIX4 routing byte (`0x60` + n - 1 through the window at `0x80002000`) set to
   ISA IRQ 11 and the matching bit of `0x4d1` set (level); PIRQ 0 is preassigned IRQ 10. The chosen IRQ is written to the
   interrupt-line byte (`0x3c`). The table has entries only for devices 0 to 3 on each root bus and none for device 4
   (bridge B device 4 is the PIIX4). The HAL's own Cobalt line tables are independent of this (established, [nt-hal.md](nt-hal.md)).
6. **Assignment**, bottom-up per bus (`0x111ae31`): the sizes found are packed largest first, halving from 1 GiB; memory starts
   at 1 MiB (or the size, if larger) in each root's own PCI memory space, I/O at `0x1000` on bridge B and `0x9000` on A. Memory
   BARs are written with the PCI-side address (the window-relative offset, which starts at 0 and gives `0x00100000` for the first memory BAR, minus `0x80000000`: the 32-bit result is `0x80100000`; the CPU address is the offset plus the window base, `0xf0000000` for bridge A and `0xf4000000` for B), I/O BARs with the port address, and
   the endpoint's command register gets bit 1 (memory) or bit 0 (I/O) added. A bridge's windows are written as I/O base and
   limit bytes (`0x1c`, `0x1d`; the upper halves `0x30` and `0x32` only when the bridge reports 32-bit I/O), the prefetch window
   (`0x24`) disabled (`0x0000ffff`), the memory base and limit words (`0x20`, `0x22`) as the address's upper 16 bits OR `0x8000`,
   and the bridge command register OR 5 when it has I/O and OR 6 when it has memory.
7. **Drivers and ROMs.** After assignment the driver table is matched on vendor and device identifiers and the matching install
   routine called. When a QLogic ISP2100 function 0 is seen the Lithium window's `+0x60 + 4 * device` word gets bits 7:6
   cleared and bits 9:8 set. Option ROMs: see the next section.

The order of the cycles inside a bus is therefore fixed (device number, then function), and Lithium B (bus 0) is scanned
before Lithium A (bus 1). The model needs: reads of absent devices that return `0xffff` rather than an abort, working size
probing on every BAR, and bridges whose bus-number, base and limit registers hold what is written.

## Embedded legacy BIOS

**Established (`1.1005@0x1107e40`, `0x1107e10`, `0x1108040`, `0x1109370`, `0x11092e0`; image at `1.1005@0x119cd64`).**

- **Image and placement.** A 32 KiB BIOS ("Main BIOS v1.0", dated 01/01/99) sits in the second data module. When the V86 set-up
  runs the PROM copies it to physical `0xf8000` to `0xfffff` (so its reset vector at `0xffff0` is the image's last paragraph) with
  plain byte stores; it also saves, for restoring afterwards, the pages at `0x1000`, `0xf0000` (32 bytes), `0xf0020` (32),
  `0xf0e00` (128) and `0xffff5` (10). Pages 0 to `0xff` (the first megabyte) are made present, writable and user-accessible in
  the PROM's page tables. No chipset shadow-control write was found: the megabyte is plain RAM (inferred).
- **When it runs.** Conditions as in [boot-path.md](boot-path.md#legacy-bios-and-the-acpi-tables): a PCI function with a
  valid x86 option ROM is found (flag set at `0x111bfcd`), or `DosBoot` begins with `y`; and `console` does not begin with `d`, the BIOS-skip setting (`Vx86DoNotRunBIOS`) does not begin with `y`, and the board test passes (not a first-generation 320, or `ignorehughid` set; `1.1005@0x1107ee4` to `0x1107efb`).
  A stock board with no add-in card therefore does not run it (inferred; no scan was run).
- **Option ROMs.** For each function found, the PROM sets the command register to 2 (memory enable only), writes the ROM base
  register with the address the bridge assignment reserved for its bus plus bit 0, requires a `PCIR` data structure of type 0
  (x86), copies the image to physical `0xc0100` and up (up to ten, ending below `0xe8101`), clears the ROM base register and
  restores the command register. It keeps a table (count, end paragraph, per-ROM bus/device/function and segment) for the BIOS.
  **The PROM never calls a ROM: the embedded BIOS does,** from its own start-up code, which scans `0xc0000` to `0xe0000` in
  2 KiB steps for `0xaa55`, checks the byte checksum and calls offset 3 (established from the BIOS listing; whether the copy at
  `0xc0100` is found by that scan, given its alignment, was not traced; unknown).
- **How it is entered.** The V86 task (descriptor `0xa0` in the PROM's GDT, a 32-bit TSS the PROM builds) starts at
  `F000:FFF0` in virtual-8086 mode, entered by a hardware task switch; the PROM first programs its local APIC
  ([below](#local-apic-state-left-behind)). INT 18h is intercepted. The task returns by a task switch back to selector `0x28`.
  Port and interrupt handling in the V86 monitor (`1.1005@0x1108c70` and the routines around `0x1109510`) was not read
  beyond that, so which of the BIOS's port accesses it traps or forwards, and whether a VGA text mode is ever shown to the
  operating system, stay unknown. The BIOS image itself uses INT 10h and text memory at `0xb8000`, and has no VGA ROM of its
  own, so a display there would be an option ROM's.
- **After it.** `1.1005@0x1108040` clears the display, runs the post-V86 cleanup (local APIC and Cobalt below) and copies the
  five saved areas back.
- **Beeps.** The BIOS image programs the speaker (ports `0x42`, `0x43`, `0x61`); nothing else in the PROM does.

## Local APIC state left behind

**Boot processor. Established.** In the default path (no V86 run): software enable with spurious vector low nibble kept and
bit 8 set, ID register set to 0, nothing else; every local vector table entry stays at its reset value (inferred as masked;
the reset value itself was not asserted from the datasheet). When the V86 task runs, `1.1005@0x1109370` writes, in order:
task priority `0xff`, spurious vector `0x100` then, after the logical-destination and flat-model writes (logical ID 1),
`0x11f`; error vector `0xe3` (`+0x370`); timer `0x300fd` (masked, periodic, `+0x320`); performance counter `0x100fe`
(masked, `+0x340`); **LINT0 `0x1001f` (masked, `+0x350`) and LINT1 `0x184ff` (masked, NMI, level, `+0x360`)**; error
status cleared; task priority 0. **After the task returns, `1.1005@0x11092e0` (called from `0x1108040`) reverses part of it:
every Cobalt interrupt controller entry is rewritten masked and level-triggered, the controller's enable bit (`+0xffc` bit 8)
is cleared, the local task priority goes to `0xff`, and bit 8 of the local spurious-vector register is cleared, so the local
APIC is software-disabled and the table above is what the loader sees on its (disabled) APIC.** This corrects the earlier
statement that nothing restores the state.

**Other processors. Inferred.** The start-up stub (copied to `0x50000`) sets the spurious-vector register enable bit (low nibble
kept), sets the ID register to the counter value and runs the hook list; no stub, hook or cleanup code writes any local vector
table entry (the only references to the local APIC base `0xfee00000` or the mapped pointer are in the boot processor's wake-up,
the table writer, the stub itself and the V86 set-up above; the hooks were scanned for them and have none). After the stub
halts, the boot processor sends INIT assert and de-assert to them. So the vector tables of the others are whatever the processor
leaves at its start-up and at INIT; the manual's rules for what INIT keeps in the local APIC were not re-checked here.
Grade: inferred, since the hook routines were only scanned, not read.

## A20

**At reset. Inferred.** No instruction in the boot block, self-test or main module writes the keyboard controller's output
port (no `0xd1`, `0xdd` or `0xdf` command) or port `0x92` on the boot processor, yet all three run with their stacks and page
tables above 1 MiB (stack `0xeffff0`, directory `0xd00000`), so A20 passes at reset; the PIIX4 datasheet's reset state and
the open-drain A20M# pull-up point the same way, as [boot-path.md](boot-path.md#processor-state-at-the-loader-call) records. What
drives the board's A20GATE input is unknown.

**At handoff. Inferred.** The state is the reset state: no code on the boot path changes it. The only A20 write is each other
processor's stub setting bit 1 of port `0x92`. The PROM's own PS/2 keyboard driver (`1.1005@0x111c22a` and the routines at
`0x111c3e4` to `0x111c5be`) talks to ports `0x60` and `0x64` but sends only keyboard and auxiliary-device commands (`0xf0`, `0xf3`,
`0xf4`, `0xed`, `0xd4` and data), never the output-port write; it polls the status register and tolerates an absent keyboard
(the timeouts return -1). The embedded BIOS and V86 monitor, which do use the controller, run only in the legacy-BIOS case and
were not traced for A20 (unknown; the BIOS image holds no output-port write command).
