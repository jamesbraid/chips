# Everest IO4 PROM monitor 4.21 (IP19, IP21, IP25): what its own software does

This page records what the three CPU builds of the "IO4 PROM Monitor", version `SGI Version 4.21 Rev A`, build of Sep 3 1996, do. They are the
payloads of the 2.1 IO4 flash container `7019deae…` described in [everest-prom-payloads.md](../../software/firmware/everest-prom-payloads.md):

| Build | CPU | Form, load, entry | sha256 of the payload |
|---|---|---|---|
| IP19 | R4400 | ELF32, `0x81800000`, entry `0x81800180` | `50b71b3dc7bdc4d09e3ed26d86ef040fec6b2d9dfbc1885313ffb8c3b1162535` |
| IP21 | R8000 | ELF64, `0xa800000001800000`, entry `+0x1000` | `9d1f00d7ffba23c8f63be603a169e28c9df54e27d8e00257c5f29ac49bf0e2e6` |
| IP25 | R10000 | ELF64, `0xa800000001800000`, entry `+0x110` | `4ff8984a3bd50804354bae2a7c06e343e36cfbbafa8dacf83c5f9729ed8f5a39` |

The hashes were recomputed on the copies read. Each payload was disassembled flat at its load address (file offset = address minus load
address) with the MIPS objdump from the toolchain container, big-endian, `mips:4000` for IP19 and `mips:isa64` for the other two; Ghidra was
not used. Grades follow [AGENTS.md](../../AGENTS.md): **established** is read in the listing, **inferred** is a reasoned reading,
**unknown** is open. Where this page says an address is "referenced", the `lui`/`ori`/`addiu` pair, or the data word, was found in the
listing. A scan for pairs does not rule out addresses built some other way.

Not used as sources: Linux and NetBSD (neither has Everest support, so there are no headers to cite), the Challenge owner's guides and
theory-of-operation chapters (not read for this page; none of the facts below rest on them), and the R4400, R8000 and R10000 manuals (the
Config bit position is the one place a manual matters; see byte order). The CPU board's own reset PROM is not held, so everything that
happens before the monitor starts is out of scope and the questions about it stay open.

The monitor is the second-stage program of the machine. By the time it starts, something earlier has probed the boards and filled in
a table in low memory (below). It then runs the diagnostics, builds the console and the ARC structures, and boots.

## Answers first

1. **Byte order.** The monitor never writes the CPU's Config register and no listing sets Status.RE, so it does not change the CPU's byte
   order. It reads Config bit 15 (BE) in all three builds, and the only use of that bit is one store: the inverted bit goes to a 64-bit register at offset
   `0x70` of an IO4's slot configuration block, inside the IA register-test routine. So the monitor expects the CPU to be big-endian, and it tells
   the IO4 side "little-endian" only when Config.BE is clear. Established for the code, inferred for the register's meaning.
2. **RAM.** The monitor assumes RAM at physical 0. It describes `0x0` to `0x1fff` as firmware, builds the ARC parameter block at `0x1000`, a
   board table at `0x2000` and a processor table at `0x3000`, and calls `0x4000` (`0x6000` on IP21) up to `0x15fffff` free memory, which covers 6 MiB.
   It describes no memory above about 422.5 MiB, because free memory above 32 MiB is capped at 100000 pages. In the IP19 build it does not program the MC3
   memory boards; it consumes a size and bank table left at `0x26d0` and `0x2000` by the earlier stage. Established for the descriptors, inferred
   for "does not program MC3" (IP19 only).
3. **Device map.** Every window the monitor uses is in the system's I/O space and is reached by uncached accesses: a per-CPU block, a block per
   board slot at 2 KiB stride, and per-IO4 adapter windows at 64 KiB stride. The console is an SCC in the EPC. NVRAM is a paged 4 KiB RAM in the EPC.
4. **ARC.** There is a full ARC system parameter block with the usual signature, and a firmware vector and a private vector. IP19 uses the 32-bit
   layout. IP21 and IP25 use a 64-bit variant. A configuration tree is built.
5. **Differences.** Address forms (kseg1 or xkphys), the parameter block layout, a two-page difference in where free memory starts on IP21, and where
   the IP21 build addresses the CPU-local block (physical `0x4_1800_0000` against `0x1800_0000`).

## Entry and the handoff block (established)

IP19 enters at `0x81800180`. It writes Status `0x24000080`, then clears Cause, WatchLo and WatchHi, then reads the word at uncached physical
`0x400` and compares it with the four ASCII bytes `XFER`. IP21 and IP25 do the same read first (through a 64-bit uncached window, `0x9000…0400`) and
write no Status on the way to the main routine. On a match with the next word between 1 and 5 all three skip the normal start and go to a shared re-entry path. Otherwise IP19
zeroes its BSS (`0x8180042c`), stores the marker `0xfeeddead` in a data word at `0x8194c1f0` and runs the main routine at `0x81800930`. IP21 and IP25 run an
initialisation routine (`0xa8…018013a0` and `0xa8…01800464`) and then their main routine (`0xa8…01801df4` and `0xa8…01800b20`). A `lui`/`ori` scan of the IP19 image found no store to physical `0x400`, so the writer of the block is probably the earlier stage. Unknown.

Status writes in the start-up and re-entry code, all established: IP19 `0x24000080` at entry (`0x81800180`) and `0x04000080` in the re-entry and halt stubs (`0x818002b4`, `0x81800360`);
IP25 `0x04000080` in the same kind of stubs (`0xa8…01800288`, `0xa8…01800338`, `0xa8…01800430`); IP21 `0x04000000` (`0xa8…01801178`) and `0x04000001` (`0xa8…01801238`, `0xa8…01801358`).
On IP21 and IP25 these are the re-entry and halt stubs, and nothing writes Status on the normal start path before the main routine. None of the values sets bit 25 (RE).
The exception paths also save and restore Status, so this covers the start-up code only.

The monitor also calls into the CPU board's reset PROM at three fixed offsets, so it expects that PROM to provide them: `0xbfc00010` is passed as the
start address when it launches the other processors in the power-on-diagnostic path (IP19 `0x81800860` to `0x818008d8`), `0xbfc00020` is called
with `jalr` after the message "Switching into Power-On Diagnostics mode..." and `0xbfc00028` is passed as a launch address at `0x8180422c` (via `0x81811738`). A stub at `0x81800610` jumps to `0xbfc00028`, but no caller or data word refers to it. The ARC Halt, PowerDown,
Restart and Reboot slots go to the re-entry code at `0x818002b4`, not to the reset PROM.
The same three physical addresses (`0x1fc00010`, `0x1fc00020`, `0x1fc00028`) appear in the IP21 and IP25 constant tables. The monitor's expectation of the reset PROM is established; what the
routines do is inferred from the callers.

## Byte order (question 1)

**Config.BE.** IP19 reads Config through the stub at `0x81812f54` and one caller returns bit 15 (`0x81807778`: shift right 15, mask 1). IP25 does the
same (`0xa8…0180939c`, wrapper `0xa8…01824910`). IP21 has the same shape (`0xa8…0180b070`, wrapper `0xa8…018172c8`, `dsrl` by 15 and mask 1). The other Config reads in the three
images size the caches (bits 6 to 8 and 9 to 11 on IP19 and IP21, the corresponding R10000 fields on IP25) or save the register in the exception register dump.
The disassembly has no `mtc0` or `dmtc0` to Config, so the monitor does not touch the CPU's mode. The bit position is the R4000-family one, where
BE set means big-endian; the R4400 and R10000 manuals agree, and the R8000 manual was not checked for it.
Established for the code; unknown for the R8000 bit position.

**The one use.** The routine at IP19 `0x8180742c` (IP25 `0xa8…01809038`, IP21 `0xa8…0180ad20`) takes a slot number and a value. If the value is 1 it does nothing. Otherwise it
writes the value into the first two doublewords of the slot's configuration block, then stores `(Config.BE == 0)` into the doubleword at offset `0x70`, then sets `+0x88` to
2 and reads a few other registers. It is reached only from the IA ("IAID") register test (called with a value from `0x81807274`), and the
restore routine at `0x818076a4` calls it with 1, which skips the whole body. The constant `0x8070` occurs once in the whole IP19 image, so there is
no other constant-form store to this register. IP21 and IP25 take the register addresses from a table; on IP25 the entry for offset `0x70` is referenced once, in this routine (not checked as thoroughly on IP21). So during normal initialisation the monitor writes
nothing to `+0x70` as far as the listings show; the store is a test-time setup.
Established for the code and the single use. The register's name and its effect on the IO4 are unknown. "Little-endian flag" is inferred from the polarity.

**Everest or IO4 controls.** No string in the three images mentions endian, swap or byte order, and no other store of a byte-order value was found.
What the monitor expects: a big-endian CPU (inferred: it is a big-endian program, and the ARC clients that read its tables are big-endian). What it checks: nothing about byte order beyond
the single Config read above, and it takes no action on the result outside the IA test. Nothing in the three images refuses to run on a little-endian CPU.
The reset-time setting stays unknown, because the CPU board's reset PROM is not held.

## Low memory and where RAM sits (question 2)

**What lives in low physical memory** (IP19 kseg1 addresses; IP21 and IP25 use the same physical addresses through `0xa800…` or `0x9000…` windows):

| Physical | What | Grade |
|---|---|---|
| `0x0` | exception block; first page described as ExceptionBlock when the ARC structures are on | established |
| `0x400` | the `XFER` handoff block (word 0 tag, word 1 a count, 1 to 5 skips the normal start) | established for the read; writer unknown |
| `0x1000` | ARC system parameter block | established |
| `0x1800` | firmware vector (35 slots) | established |
| `0x1c00` | private vector (13 slots) | established |
| `0x2000` | board table: 16 slots of 108 bytes, `0x2000` to `0x26bf` | established for the read; written by the earlier stage |
| `0x26d0` | total memory size word (unit below); read only | established for the read; writer unknown |
| `0x26d4` | adapter number of the master IO4's EPC (used as `ioa << 16` in the console and NVRAM addresses); read only | established for the read, inferred for the role |
| `0x26d8` | flag word; read only. Bit 7 selects the console, bits 0 and 15 are tested in the main routine | bit 7 established; bits 0 and 15 unknown |
| `0x26dc` | buffer the monitor fills with the system serial number it gets from the system controller (`0x81815f50`), compared with the NVRAM copy | inferred from the warning strings |
| `0x3000` | processor table: 52 entries of 64 bytes, tag `0xbaddeed2` in word 0 of a valid entry; all seven users skip entries without it, and the launch loop at `0x81800860` starts CPU `n` only when the tag matches and byte `+9` equals the index | established for the read; other fields unknown |
| `0x4000` upward | free memory | established |
| `0x1580000` to `0x1c00000` | monitor and loader regions, below | established |

**Memory descriptors.** All three builds seed the same list of ARC memory descriptors (20-byte nodes: type, base page, page count, the magic
`0x4b45565e`, next) in the routine at IP19 `0x8180b528` (IP25 `0xa8…018101b4`, IP21 `0xa8…0180fcac`). The type numbers are the SGI numbering of the NetBSD
`arcbios.h` header, as on the [IP20 page](../ip20/prom-software.md) (3 free, 5 loaded program, 6 firmware temporary, 7 firmware permanent). The seeded entries:

| Physical range | Type |
|---|---|
| `0x0`, 2 pages | firmware temporary |
| the monitor image, from the page rounded up from `0x1800180`, length the image size plus a `0x20000` allowance (`0x8180b564`) | firmware temporary |
| `0x2000`, 1 page; `0x3000`, 1 page | firmware temporary |
| `0x1600000`, 256 pages; `0x1700000`, 256 pages; `0x1580000`, 64 pages; `0x1b00000`, 256 pages | firmware temporary |
| `0x1800000`, 768 pages (3 MiB) | firmware permanent |
| `0x4000`, 5628 pages (IP21: `0x6000`, 5626 pages), ending at `0x1600000` | free |
| `0x1c00000`, 1024 pages | free |
| `0x2000000`, the system's page count minus 8192, capped at 100000 pages | free |

Established. The load addresses give some of the firmware ranges a meaning: `0x1b00000` is the container's segment loader (`0x81b00000`), `0x1700000` is the graphics PROM's load address, and `0x1800000` is the monitor. The free
range from `0x4000` ends at `0x1600000` but the `0x1580000` entry lies inside it. The insert routine (`0x8181c448`) places a node by base page and does not split or merge, so the seeded
list contains overlapping entries; whether a later pass resolves them is unknown. Seeding runs only in the flag-on branch of `0x8181c0e8` (the other branch builds the list by walking the configuration tree). In that branch a second pass retypes page 0 as ExceptionBlock and page 1 (address `0x1000`) as SystemParameterBlock, the same as the IP20 PROM does.

**Size.** The total comes from the word at physical `0x26d0` shifted right by 4 (IP19 `0x8180b388`, IP21 `0xa8…0180fa4c`, IP25 `0xa8…0180ff54`). The result is treated as a page count: it
is compared with 8192 pages (32 MiB) and capped at 100000 pages, and it is also stored as the Key of the "main memory" ARC component. That implies a unit of 256 bytes for the
stored word. Inferred; the earlier stage that writes it is not held. With the cap, the highest described address is `0x2000000 + 100000 * 0x1000 = 0x1a6a0000`, about
422.5 MiB, below 512 MiB, whatever the machine holds. Established for the arithmetic.

**RAM at 0 and at 6 MiB.** The monitor treats RAM as present from physical 0 with firmware pages first, then free memory from `0x4000` to `0x15fffff` (so 6 MiB is inside free
memory), then firmware, then free from `0x1c00000`. It builds its SPB, vectors and tables at `0x1000` to `0x3fff` and its exception handlers write to `0x0`. So RAM at physical 0 is assumed; whether the
hardware provides it, and which bank, is the earlier stage's work. The monitor contains no test that checks it; the diagnostic "CPU can't access memory" is in the message table. Inferred.

**MC3.** The strings name MC3 memory boards with banks A to H (eight banks), SIMM sizes and the diagnostics "A bus error occurred during MC3 config" and "...during MC3 testing". These sit in
a table of messages shared with the CPU boot diagnostics (the table also holds "CPU testing dcache" and other CPU-board messages), so they do not show that this monitor configures MC3. Every access
to the slot configuration blocks found in IP19 is either the IA-register test (offsets listed below), the per-slice PRId store, or the adapter-present mask; none looks like bank, base or interleave setup. Inferred for the IP19 build only: it does not program MC3. IP21 and IP25 were not scanned for this.
What it does read is a 12-byte record per bank in the board-table entry for an MC3 board (type `0x31`, eight records starting at entry offset 0, then the slot number at `+0x60` and the type at `+0x64`) and prints it
as "Bank n: IP, IF, Size, Bloc": Bloc (a word) at record `+0`, an enabled flag at `+5`, Inventory at `+6`, DiagVal at `+7`, then IP, IF and Size at `+8`, `+9` and `+10` (`0x8180bd4c`). The routine that prints bank sizes in megabytes (`0x8180cc18`) uses the same record. IP and IF are probably interleave position and factor; that is a reading of the labels, not of any register. The encoding of the
MC3 configuration registers, the base and size decode, and the interleave rule are unknown. They need the MC3 documentation or the earlier stage.

## Slot and adapter windows (question 3)

Addresses below are given as the IP19 kseg1 form. IP19 and IP25 use physical `0x1800_0000` for the CPU-local block and the slot blocks; IP21 uses `0x4_1800_0000` for the same offsets.
Whether the two views are one decode or two is unknown (the I/O adapter windows on IP21 and IP25 use `0x4_0000_0000` plus the slot offset where IP19 uses `0x1000_0000`).

**CPU-local block, physical `0x1800_0000` (`0xb8000000`).** Established for the accessed; names unknown unless given.

- `+0x008`: read as a doubleword; bits 5 to 2 are the slot number and bits 1 to 0 the processor slice on the board (IP19 `0x81800e08`, the exception stubs, the IP25 and IP21 stubs). This is how a processor finds its own table entry.
- `+0x010`: the routine at `0x8180b2b0` writes 1 here and then loops forever. Inferred to be a reset or halt request; the caller was not traced.
- `+0x100`, `+0x200`, `+0x300`, `+0x308`, `+0x340`, `+0x800`, `+0x808`, `+0x820`, `+0x830`, `+0x840`, `+0x900`, `+0x908`: accessed, roles unknown. `+0x830` is written with 0 to 127 in a loop at start-up.
- `+0x400`, `+0x408`: a status and data pair. In the status word bit 0 means transmit ready (the byte sender at `0x81812c6c` waits up to a million polls for it, then stores the byte to `+0x408`) and bit 1 means receive data present (`0x81812c48`, `0x81819f14`). Messages to the system controller go through it as `0x18`, `S`, `M`, text, newline (`0x818052d0`). It is also the console when bit 7 of the flag word at `0x26d8` is set (`0x8180b3e0`); with the bit clear the console is the EPC serial port below. The system-controller reading is inferred from the byte framing and the "Ctsysctlr_getserial" and serial-number strings.
- `+0x20000` (`0xb8020000`): a 64-bit value read repeatedly by the delay routine (`0x818005e4`) and compared with a computed deadline, so it counts. Inferred to be a free-running counter.

**Slot configuration blocks, physical `0x1800_8000 + slot * 0x800` (`0xb8008000`).** Sixteen slots, 2 KiB each; the same stride is used for the processor slices (`+0x200` each). Established as the address arithmetic.
The monitor touches these offsets: `+0x00`, `+0x08` (written with a test pattern), `+0x10` (a doubleword with a bit per IO adapter found, written by the IO4 scan at `0x81804f04`), `+0x18`, `+0x28`, `+0x30`,
`+0x38`, `+0x40`, `+0x48`, `+0x50`, `+0x70` (above), `+0x88`, and one word per processor slice at `slice * 0x200 + 0xa8`, set to 1 when the low byte of the PRId register is below 64 and to 0 otherwise (IP19 `0x81800e08`). A register-test table at `0x81866c20` lists five of them
with write masks (indices 3, 4, 15, 16, 17 times 8, masks `0x7fff`, `0xff`, `0xfffff`, `0xfffff`, `0x3`). No field decode is known. Board type, revision and slot identity are not read from this
block by the monitor: they come from the table at `0x2000`.

**IO4 adapter windows, physical `0x1000_0000 + slot * 0x80000 + ioa * 0x10000` (`0xb0000000`).** Eight adapters of 64 KiB per slot; adapter numbers 1 to 7 are scanned (the disable command says "The IOA must be a number between 1 and 7"). Established for the address arithmetic.
Per-adapter record in the board-table entry: 12 bytes, `+7` adapter type, `+8` an index within that type, `+9` an ID. The scan at `0x81804e40` goes through slots 15 down to 0 and treats an entry as an IO4 when `(type & 0xf0) == 0x20`
(the entry type is `0x21`). Adapter type byte values it recognises: `0x0e` (14) is "EPC", `0x0d` (13) is "S1" and `0x1d` (29) is "SCIP" (both SCSI controllers), `0x0f` (15) is "F" (the F-chip, VME) and `0x2b` (43) is counted separately and is not named.
Only the F adapter is probed further: a 4-byte read test of the window (`0x81843ec8`), a write of 0 to `+0x58`, then the ID at `+8`; IDs `0x11`, `0x12`, `0x20`, `0x30` and `0x31` are accepted and anything else clears the adapter.
IDs `0x11`, `0x12` and `0x20` are followed by a read test at `+0x1000`, IDs `0x30` and `0x31` by one at `+0x1108`. The names come from the strings in the print routine, the numbers from the dispatch tables; the connection between the ID and a specific VME part is not shown.

**EPC window (adapter type 14), established offsets.** The console and NVRAM code forms the EPC window as `0xb0080000 + (word at 0x26d4) * 0x10000`. The constant is the slot 1 window, so the master IO4 is assumed in slot 1 and the adapter
number comes from the earlier stage (inferred; the constant could also be an artefact of how the earlier stage numbers things).

| Offset in window | Use | Grade |
|---|---|---|
| `+0x3007 + n*8` | NVRAM data byte `n` (0 to 31), byte lane 7 of each doubleword | established |
| `+0x3107` | NVRAM page register (page = address bits 11 to 5) | established |
| `+0x4007`, `0x400f`, `0x4017`, `0x401f`; `+0x5007…0x501f`; `+0x6007…0x601f` | three groups of four registers on an 8-byte stride | established for the accessed |
| `+0x600f`, `+0x601f` | the console: poll bit 2 of `+0x600f`, write the byte to `+0x601f` (IP19 `0x8180b4d4` onward) | established |

The serial groups look like Zilog SCC register banks (control and data per channel; status bit 2 as transmit-buffer-empty); the SCC name is inferred. The console path is chosen by bit 7 of the word at `0x26d8` (set: the CPU-local port above; clear: this SCC). Bits 0 and 15 of the same word are also read in the main routine; what they mean is unknown. The Ethernet driver (`0x8180a55c`) sets up descriptors that refer to physical `0x1b00000` and `0x1b80000`, inside the segment loader's firmware range (buffer role inferred). Which base address the driver's register offsets are formed against was not established, so its registers are unknown. The parallel port, the Ethernet address PROM and the SCSI controller registers (`+0x1000` area) are not decoded here.

**Large windows.** A routine at `0x81812dc0` (and `0x81812dfc` for stores) forms a physical address as `((x << 8) + y)` with `x = (slot << 22) + 0x04000000` and `y = (window << 27) + offset`, that is physical
`0x4_0000_0000 + slot * 0x4000_0000 + window * 0x800_0000 + offset`, and reads or writes a word through it. When `x`'s upper twelve bits equal `0x001` it first ORs in `0x0ff00000`. It is reached through two small wrappers (`0x81805a80` for loads, `0x81805ab4` for stores) whose callers were not traced. Established for the arithmetic; what `window` selects is unknown.

**Board types** (the print loop covers slots 1 to 15; board-table entry `+0x64`, established from the dispatch at `0x8180be34` and the printing routines): `0x00` empty, `0x11` IP19, `0x12` IP21, `0x13` IP25 (the CPU names are attached by the strings printed with each case),
`0x21` IO4, `0x31` MC3 (eight bank records). Anything else prints "Unrecognized board type". Revision registers are not read by the monitor in any routine found.

**Graphics.** The container carries a RealityEngine2 graphics PROM loaded at physical `0x1700000`; the monitor reserves that range. It also has strings for a "GR2" HQ and GE microcode loader. How it finds the adapter is not traced. Unknown.

**NVRAM layout.** The device is 4096 bytes, reached through the 32-byte window and page register above. `0x81815e4c` writes two check bytes: the first (`0x81815d34`) to byte 0 and the second (`0x81815da4`) to byte `0x368` (872). Both are rotate-left-1 and XOR sums with seed `0xa5`. The second covers bytes 0 to 4057 and skips
bytes `0x31b` and `0x368`. The first samples only the 32 multiples of 32 from 0 to `0x3e0` (the address is masked with `0x3e0`) and skips zero bytes. Byte `0x31b` (795) is not a check byte: it is a request byte that the main routine reads and clears (`0x81800b08`, `0x81800b14`); value 3 calls `0x81800230` and value 4 calls `0x81800d00`. Which bytes hold the environment records, the serial number and the Ethernet address is not traced. Unknown.

## ARC (question 4)

**Established.** All three builds build a parameter block with the usual ARC signature word (`0x53435241`) in the routine at IP19 `0x8181d388`, IP21 `0xa8…018247bc`, IP25 `0xa8…01826028`, when a flag word is set (IP19 `0x81866510`).

- **IP19** (32-bit): physical `0x1000`; `+0` signature, `+4` length `0x48`, `+8` version 1, `+10` revision 10, `+0xc` restart block 0, `+0x10` debug block 0, `+0x14` general exception vector `0x8181d470`, `+0x18` UTLB-miss vector `0x8181d634`,
  `+0x1c` firmware vector length 140, `+0x20` firmware vector `0xa0001800`, `+0x24` private vector length 52, `+0x28` private vector `0xa0001c00`, `+0x2c` adapter count 0. The firmware vector has 35 slots copied from `0x8186f410`, the private vector 13 slots from `0x8186f49c`.
  Slot order follows the IP20 layout. The five stubs after Load, Invoke and Execute (Halt, PowerDown, Restart, Reboot, EnterInteractiveMode) are the `0x81800210` to `0x81800230` routines; slot 8 is 0 and slot 19 is 0.
  Slot 34 is `0x8180c234` with no ARC counterpart named here. The slot names beyond those stubs are inferred from the order.
- **IP21 and IP25** (64-bit variant): the same two vectors at physical `0x1800` (35 slots of 8 bytes, 280 bytes) and `0x1c00` (13 slots, 104 bytes), the block at `0x1000`: signature in an 8-byte slot at `+0`, length `0x90` at `+8`, a 16-bit value 64 at `+0x10` and a 16-bit 0 at `+0x12`,
  restart and debug fields 0 at `+0x18` and `+0x20`, general exception vector at `+0x28`, UTLB vector at `+0x30` (`0xa8…01824900` and `0xa8…01824a90` on IP21), vector lengths 280 and 104 at `+0x38` and `+0x48`, vector pointers at `+0x40` and `+0x50`, and 0 at `+0x58`. What the 16-bit value 64 means is not read (version is my guess).

**Configuration tree.** The strings "SGI-IP19", "SGI-IP21", "SGI-IP25", "MIPS-R4400", "MIPS-R8000", "MIPS-R10000" (each with an FPC variant), "icache", "dcache", "s_cache", "main memory", "video()", "keyboard()",
"multi(0)serial(0)", "multi(0)serial(6)", "serial(3)pointer()" and "EPC1.0" are the component names, and a "Cannot malloc ... component of config tree" error. The "main memory" key is the page count from `0x26d0` (above). The walk and
the full tree shape were not read. Inferred from the strings.

## Differences between the builds (question 5)

| Item | IP19 (R4400) | IP21 (R8000) | IP25 (R10000) |
|---|---|---|---|
| Address forms | 32-bit kseg0/kseg1 | 64-bit `0xa800…` and `0x9000…` windows | same as IP21 |
| `XFER` test address | `0xa0000400` | `0x9000…0400` | `0x9000…0400` |
| First action at entry | Status `0x24000080`, Cause, Watch cleared | XFER test first | XFER test first |
| Config.BE reader | yes | yes | yes |
| SPB | 32-bit, length `0x48`, version 1 revision 10 | 64-bit variant, length `0x90` | 64-bit variant, length `0x90` |
| Free memory starts | `0x4000`, 5628 pages | `0x6000`, 5626 pages | `0x4000`, 5628 pages |
| CPU-local block (physical) | `0x1800_0000` | `0x4_1800_0000` | `0x1800_0000` |
| Slot blocks (physical) | `0x1800_8000 + slot * 0x800` | `0x4_1800_8000 + slot * 0x800` | `0x1800_8000 + slot * 0x800` |
| IO4 adapter window base | `0x1000_0000` | `0x4_0000_0000` | `0x4_0000_0000` |
| Register offsets in the IA test | `+0, +8, +0x28, +0x30, +0x40, +0x50, +0x70, +0x88` | same | same |
| Cache-size source | Config fields | Config fields | Config fields (R10000 layout) |

Register addresses are compiled in as immediates on IP19 and taken from a table of 64-bit constants on IP21 and IP25; the table values listed above were read from the data. The other dispatch tables (SPB, descriptors, board types) agree across the three builds in the parts checked. Differences in the diagnostics and the
cache test code were not compared function by function. Unknown for the parts not compared.

## Unknowns and routes that would settle them

See [questions/everest-prom-software.md](../../questions/everest-prom-software.md).
