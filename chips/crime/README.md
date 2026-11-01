# CRIME

Mode: **spec-backed** (see [docs/specs.md](../../docs/specs.md): CRIME 1.5 Specification, revision 0.3; its CPU
interface and memory controller register map is transcribed in
`docs/sources/specs/crime-1.5-specification-rev0.3.registers.md`). O2 (IP32) memory controller, CPU interface,
interrupt controller and timer. This page covers the CPU interface, the error registers, the interrupt registers,
the timer and the memory controller. The rendering engine (base `0x15000000`) is covered by the separate graphics
workspace and appears here only as cross-references.

Every fact below was first read from the IRIX 6.5.30 IP32 files: the kernel object (`kernel.o`, relocatable) and
`trap.o`, the CPU PROM image, the diagnostic (`ide.IP32`) and the monitor (`symmon.IP32`). There is no linked IP32
kernel, so a kernel routine is cited as `name` at its `kernel.o` offset. The published specification and the public
Linux and NetBSD drivers were read afterwards, to report agreement and conflict, never to supply a fact. OpenBSD's
CRIME code was looked for and not retrieved; nothing here depends on it.
Census: [census/](census/census.md) (`census.tsv`, `fields.tsv`, `context.tsv`, `census-sites.tsv`,
`census-windows.tsv`), config [`tools/configs/crime.json`](../../tools/configs/crime.json), header
[`include/crime.h`](../../include/crime.h).

## Addresses and widths (established)

- The register block is at physical `0x14000000`. Every image builds it as `lui 0xb400` (the uncached 32-bit window);
  the kernel's exception and interrupt paths use that constant directly, with no pointer in memory.
- Every kernel, monitor and PROM access in the census is a doubleword `ld` or `sd` (census width 8). The exceptions are
  32-bit `lw` reads by the diagnostic and by PROM routines: the identification register at `+4` (the low word of the
  doubleword) and the bank control registers, read as word pairs from `0x208` to `0x244`. The specification says the
  registers accept doubleword access only, so whether a word read works is unknown, and the shipped code relies on it
  (see "Against the published specification").
- The PROM's memory sizing indexes the bank control registers (`0x208 + 8n`). The census records the base slot of each
  routine that spells an offset and misses those loops; they are read by hand below.
- No scanned image touches `0x248` (refresh counter) or `0x4048` (the 1.5 location of the CPU error status). The
  census window covers `0x0` to `0x40ff`.

## What identifies the chip (established)

- `get_crimerev` (`kernel.o` `0x11838`, read in full) loads the identification doubleword at `0x0`. It takes the low
  nibble as `rev` and the upper 32 bits (bits 63:32) as `hi`. If `hi` is 0 it returns 0 when `rev` is 0 and 0x11 for any
  other `rev`; if `hi` is 1 it returns 0x13; any other `hi` returns 0x14. The result is cached in kernel data.
  Callers test only zero versus non-zero (the error decode, `mlreset`, `ecc_meminit`).
- The PROM and the diagnostic read the identification word at `+4` and compare it with 0xa0 and 0xa1 only: 0xa0
  selects the path for revision 0, 0xa1 the path for revision 1.1. No shipped routine compares it with another value.
  The PROM's low-level helper at `0xbfc06808` returns `id & 0xf`.
- Why the kernel reads bits 63:32 is **unknown**: the specification's identification register has only bits 7:0
  (ID value 7:4, revision 3:0). See the open entry.

## Register inventory

The census reaches 26 register rows (offsets `0x0` to `0x58`, `0x200`, `0x208` to `0x240`, `0x250` to `0x270`) from the
kernel object, the graphics object, the monitor, the diagnostic and the PROM (215 access sites). 24 rows are in the
specification's map; `0x50` and `0x58` are not. Counting the eight bank control registers as one kind, the census
reaches 19 register kinds; with the two the code never reaches (`0x248`, `0x4048`) the page grades 21 kinds:
**16 established, 3 inferred, 2 unknown**.

### Graded register table

Width and access are what the instructions do. Each entry starts with the physical address, the form the register
map and the inventory use; the offset from `0x14000000` is in brackets. The grade says whether the role is
established (the routine read in full, a symbol or string the binary carries, or code arithmetic), inferred (a reading
from a store pattern or from a name the binary carries, with the reasoning given) or unknown. Names are the
specification's, with the table in brackets, except `0x50` and `0x58`.

- `0x14000000` (`0x0`): ID / revision (spec Table 5-8, p. 5-26). Established.
  Eight bytes wide, with a four-byte read at +4. Read only.
  `get_crimerev` reads the doubleword at 0x1184c and keeps the low nibble as the revision and bits 63:32 as a second value.
  `__sysad_wbflush` reads it at 0x13ec after a `sync` to drain posted stores. The PROM and the diagnostic read it too.
- `0x14000008` (`0x8`): CPU interface control (spec Table 5-9, pp. 5-26 to 5-27). Established.
  Read and written at eight bytes. Touched by `mlreset`, `flushbus`, the probes, `crm_softreset`, `crm_hardreset`, the PROM and the diagnostic.
  `mlreset` reads it at 0x8754 and writes the value it builds at 0x87ac. For a processor whose implementation field (PRId bits 15:8) is below 0x23 it clears bits 13, 12 and 9; otherwise it clears bit 9 and sets bits 13:12.
  `crm_softreset` stores 0x400 and `crm_hardreset` stores 0x800, each followed by a loop that never returns. `flushbus` reads it at 0x11cd4 to drain the bus.
- `0x14000010` (`0x10`): Interrupt Status (spec Table 5-10, p. 5-28). Established.
  Read, and written with 0 by `mlreset`. Touched by `intr`, the routine at 0xa2cc, the routine at 0x8168 (the body after `add_ioboard`), the diagnostic and the graphics object.
  `intr` reads it at 0xa5d4, ANDs it with the enable mask its interrupted context saved, and returns 0 or 1. The routine at 0xa2cc reads it at 0xa304 and 0xa32c.
  `mlreset` stores 0 to it at 0x87bc.
- `0x14000018` (`0x18`): Interrupt Enable (spec Table 5-11, p. 5-29). Established.
  Read and written at eight bytes. Touched by `splx`, `spl0`, `splhi`, `spl7`, `splprof`, `splint`, `VEC_int`, `kpreemption`, `mlreset` and the PROM.
  The `spl*` routines write a per-level mask taken from a kernel table, 8 bytes a level.
  `VEC_int` reads it at 0xc and writes it at 0x2c and 0x64. `kpreemption` writes it at 0x1d8, and `mlreset` stores 0 at 0x87b4.
- `0x14000020` (`0x20`): Software Interrupt (spec Table 5-12, p. 5-29). Established.
  Read and written at eight bytes. Touched by `intr`, `synthclock`, `synthackkgclock` and the PROM. `intr` returns 0 or 1.
  `synthclock` clears bit 28 (AND with 0xefffffff) before its store at 0xa02c. `synthackkgclock` clears bit 29 (AND with 0xdfffffff).
  `intr` reads it at 0xa6bc and stores it back at 0xa700 with bit 28 or 29 set from the pending counters `cause_ip5_count` and `cause_ip6_count`. Only bits 28 and 29 are touched.
- `0x14000028` (`0x28`): Hardware Interrupt (spec Table 5-13, pp. 5-29 to 5-30). Established.
  Read and written at eight bytes. Touched by `badaddr`, `wbadaddr`, the other probes, the graphics object's `crime_init` and the PROM.
  `badaddr` reads it at 0x14364 and tests mask 0x300080 (bits 21, 20 and 7) to see whether the probe failed. `crime_init` clears bits 19:16, and the PROM stores 0.
- `0x14000030` (`0x30`): Watchdog Timer (spec Table 5-14, p. 5-30). Inferred.
  Written only. `mlreset` stores 0 to it at 0x887c. Nothing scanned reads or sets it, so the watchdog stays off in these images.
- `0x14000038` (`0x38`): Crime Timer (spec Table 5-15, p. 5-31). Established.
  Read and written at eight bytes. Touched by `delay_calibrate`, `_ticksper1024inst`, `_cpuclkper100ticks`, `absolute_rtc_current_time`, the monitor, the diagnostic and the PROM.
  A free-running counter. `absolute_rtc_current_time` reads it at 0x11828 and returns the low 32 bits.
  `_cpuclkper100ticks` stores 0 at 0x14130 and waits for 23496 ticks. The PROM's microsecond delay polls the low 32 bits against 66 ticks a microsecond.
- `0x14000040` (`0x40`): CPU Error Address (spec Table 5-16, p. 5-32). Established.
  Read only, at eight bytes. Touched by `VEC_dbe`, `VEC_ibe`, `ecc_handler`, the save routine at 0xff08 and the monitor.
  `ecc_handler` reads it at 0xda1c and saves it raw to `crm_cpu_error_addr`. `VEC_dbe` reads it at 0x1c2e8 and `VEC_ibe` at 0x20dec. The address is printed as read, not shifted.
- `0x14000048` (`0x48`): CPU/VICE error status at the CRIME 1.1 location (spec Table 5-17, p. 5-32). Established.
  Read and written at eight bytes. Touched by `VEC_dbe`, `VEC_ibe`, the `dobuserr` path, the probes, `ecc_handler`, `mlreset` and the monitor.
  `mlreset` stores 0 to it at 0x8760. `badaddr` stores 0 at 0x142a4 and reads it back at 0x142b0. `ecc_handler` reads it at 0xd9ec and clears it with a store of 0 at 0xda64.
  `get_crimerev` picks the layout: a non-zero result selects the three-bit layout, zero the ten-bit one.
- `0x14000050` (`0x50`): CPU error enable, the name the public NetBSD driver gives it (not in the CRIME 1.5 map). Inferred.
  Written only, at eight bytes. `mlreset` stores 0x3ff at 0x89a0 when `get_crimerev` returned 0. The PROM stores 0 at 0xbfc083bc during cold start.
- `0x14000058` (`0x58`): VICE error address (not in the CRIME 1.5 map). Established.
  Read only. Touched by `VEC_dbe`, `VEC_ibe`, the save routine at 0xff08 and the monitor.
  `VEC_dbe` reads it at 0x1c318 and `VEC_ibe` at 0x20e1c. The save routine reads it at 0xff2c and saves it to `crm_vice_error_addr`, which is passed to `vice_err`. No routine read tests its bits.
- `0x14000200` (`0x200`): MC Status/Control (spec Table 6-13, p. 6-30). Established.
  Read and written at eight bytes. Touched by `ecc_enable`, `ecc_disable`, the PROM, the monitor and the diagnostic.
  `ecc_enable` stores 1 at 0x9254 only once memory is initialised and checking is enabled. `ecc_disable` stores 0 at 0x9268.
  The monitor's `wbflush` reads it at 0xa002852c as a write-buffer drain.
- `0x14000208` (`0x208`): Bank 0 control (spec Table 6-14, p. 6-32). Established.
  The monitor reads it as a doubleword and the diagnostic as a word. The PROM's indexed sizing writes it.
  The monitor's `cpu_get_memsize` reads it at 0xa0027e44 and counts 128 MB when bit 8 is set, 32 MB otherwise.
  The diagnostic reads its low word at 0xa00f0230. The PROM's sizing stores the candidate address's bits 29:25 in the low 5 bits, with bit 8 set.
- `0x14000210` (`0x210`): Bank 1 control (spec Table 6-14, p. 6-32). Established.
  The monitor's indexed loop and the diagnostic read it, and the PROM's indexed sizing writes it.
  The monitor's loop reads it at 0xa0027e78. It skips the bank when its value equals bank 0's; otherwise bit 8 picks 128 MB or 32 MB.
  The diagnostic's word read is at 0xa00f0260.
- `0x14000218` (`0x218`): Bank 2 control (spec Table 6-14, p. 6-32). Established.
  The same monitor loop reaches it at 0xa0027e78 as it does bank 1. The diagnostic reads its low word at 0xa00f02a8 and applies the same size rule.
- `0x14000220` (`0x220`): Bank 3 control (spec Table 6-14, p. 6-32). Established.
  The diagnostic's sizing routine reads its low word at 0xa00f02f0. Bit 8 of that word picks 128 MB or 32 MB.
- `0x14000228` (`0x228`): Bank 4 control (spec Table 6-14, p. 6-32). Established.
  A word read at 0xa00f0338 in the diagnostic's sizing routine. The value's bit 8 selects the size.
- `0x14000230` (`0x230`): Bank 5 control (spec Table 6-14, p. 6-32). Established.
  The diagnostic loads its low word at 0xa00f0380, and the bank's size follows from that word's bit 8.
- `0x14000238` (`0x238`): Bank 6 control (spec Table 6-14, p. 6-32). Established.
  The low word is read at 0xa00f03c8. Bit 8 gives 128 MB or 32 MB.
- `0x14000240` (`0x240`): Bank 7 control (spec Table 6-14, p. 6-32). Established.
  The diagnostic's sizing routine reads the word at 0xa00f0410, and the bank's own bit 8 sets its size.
- `0x248`: refresh counter, not reached by any scanned image. Unknown.
- `0x14000250` (`0x250`): Memory Error Status (spec Table 6-16, pp. 6-32 to 6-33). Established.
  Read and written at eight bytes. Touched by `VEC_dbe`, `VEC_ibe`, `dobuserre`, the probes, `ecc_handler`, the scrub routine at 0xff50, `mlreset` and the monitor.
  `ecc_handler` reads it at 0xda04 and tests the hard-error CPU-access bit (0x240000). `mlreset` stores 0 to it at 0x8768.
  The scrub routine at 0xff50 stores 0 after it scrubs the faulting line. The decode routine at 0x105c4 prints the status bits.
- `0x14000258` (`0x258`): Memory Error Address (spec Table 6-17, p. 6-34). Established.
  Read only. Touched by `VEC_dbe`, `VEC_ibe`, `ecc_handler`, the save routine at 0xff08 and the monitor.
  `ecc_handler` reads it at 0xda24, `VEC_dbe` at 0x1c308 and `VEC_ibe` at 0x20e0c. The value is saved raw to `crm_mem_error_addr` and printed as read.
- `0x14000260` (`0x260`): ECC Syndrome Bits (spec Table 6-18, p. 6-34). Established.
  Read only. Touched by `dobuserre`, the save routine at 0xff08 and the monitor.
  `dobuserre` reads it at 0x10290 and the save routine reads it at 0xff3c. The value is saved to `crm_mem_error_ecc_syn`.
- `0x14000268` (`0x268`): ECC Generated Check Bits (spec Table 6-19, p. 6-34). Established.
  Read by `dobuserre` at 0x10288 and by the save routine at 0xff34. The copy goes to `crm_mem_error_ecc_chk`.
  The monitor prints it as well.
- `0x14000270` (`0x270`): ECC Replacement Check Bits (spec Table 6-20, p. 6-35). Inferred.
  Written and read. Touched by the PROM and the monitor.
  The PROM's sloader stores an argument register to it at 0xbfc00208. A monitor routine at 0xa0010538 reads it and prints it as "MEM Ecc Repl". The pairing of the register with that label rests on the monitor's print order.
- `0x4048`: CPU error status at the CRIME 1.5 location. Not reached by any image. Unknown.

`crm_cpu_error_stat`, `crm_cpu_error_addr`, `crm_vice_error_addr`, `crm_mem_error_stat`, `crm_mem_error_addr`,
`crm_mem_error_ecc_syn` and `crm_mem_error_ecc_chk` are the kernel's own global symbols; they tie `0x48`, `0x40`,
`0x58`, `0x250`, `0x258`, `0x260` and `0x268` to their roles. The monitor's strings "Crime CPU Error Addr", "CPU Error
Stat", "VICE Error Addr", "MEM Error Stat", "MEM Error Addr", "MEM Ecc Syn", "MEM Ecc Chk" and "MEM Ecc Repl" follow the
order of its eight saved loads (`0x40`, `0x48`, `0x58`, `0x250`, `0x258`, `0x260`, `0x268`, `0x270`); only the last
pairing, `0x270` with "Repl", rests on that order alone, hence inferred.

### CPU interface control (`0x8`)

- Written bits (established): `mlreset` reads the register, then writes it. For a processor whose implementation field
  (`PRId` bits 15:8) is below 0x23 it clears bits 13, 12 and 9 (mask `0x3200`); otherwise it clears bit 9 and sets bits
  13:12 (`0x3000`). The PROM's reset code reads bits 13:12 and compares them with `0x3000`. The specification lists bit
  13 as the "R5000 SysADC check control" and bit 12 as the "CRIME SysADC check control", both marked not used in
  CRIME 1.5, and bit 9 as the watchdog enable. No census site sets bit 9, so these images never enable the watchdog.
- Reset (established): `crm_softreset` stores `0x400` and `crm_hardreset` stores `0x800`, each followed by a loop that
  never returns; the PROM, the monitor and the diagnostic carry the same pair. The specification names bit 10 "soft
  reset" (not used in 1.5) and bit 11 "cold reset".
- The PROM clears bit 0 (read, AND with -2, write) in two routines (`0xbfc05c34`, `0xbfc06214`). The specification marks
  bits 4:0 reserved. Why is **unknown**.
- Reads of `0x8` and `0x200` serve as write-buffer drains (`flushbus`, the probes, the monitor's `wbflush`, the
  diagnostic's drain routine). The code is established; that a read from CRIME waits for the stores ahead of it is
  inferred.

### Timer (`0x38`)

Established: the PROM's microsecond delay stores 0 then polls the low 32 bits (sign-extended) until they exceed `66 * n`;
`_cpuclkper100ticks` stores 0 and waits for 23496 ticks while counting the processor's own cycle counter;
`delay_calibrate` multiplies a tick difference by 15 and divides by 100000; `absolute_rtc_current_time` returns the low 32
bits. So the counter is writable and 32 bits of it are used; the PROM's 66 ticks per microsecond puts it near 66.7 MHz
(the public Linux driver's tick is 15 ns). Whether it is wider than 32 bits is not read.

### Interrupt registers (`0x10` to `0x28`)

- Dispatch (`intr`, `0xa578`): reads `0x10`, ANDs it with the enable mask the interrupted context saved in its exception
  frame, finds the vector. The `spl*` routines rewrite `0x18` on every priority change from a table indexed by level;
  `crime_intr_enable` and `crime_intr_disable` set and clear one bit in every level's table entry.
- `mlreset` stores 0 to `0x18` and `0x10`, then registers vectors with `setcrimevector(bit, level, handler, ...)`: bit 28
  level 1 (`synthclock`), bit 29 level 2 (`synthackkgclock`), bits 21 and 20 level 3, both with `buserror_intr`.
  Inferred: the level argument is the R10000 interrupt number minus 3. All four registrations agree with the
  specification's Table 5-5 under that rule (bit 28 to IP4, 29 to IP5, 20 and 21 to IP6); `setcrimevector` accepts 0 to 5.
- Software interrupt (`0x20`): `synthclock` clears bit 28 (AND `0xefffffff`). `synthackkgclock` clears bit 29 (AND `0xdfffffff`); `intr` reads the register and stores it back with bit 28 or 29 set
  from the pending-clock counters `cause_ip5_count` and `cause_ip6_count`. Established. `intr` returns 0 or 1.
- Hardware interrupt (`0x28`): the graphics object's `crime_init` reads it, ANDs `0xfff0ffff` and stores it back,
  clearing the four GBE interrupt bits 19:16 (the specification says a GBE interrupt is cleared by writing 0 to its bit).
  The probes test bits 21, 20 and 7 (below).
- Cross-references to the graphics side: `crimeFifoFullHandler` reads `0x10` and tests bit 26 (rendering engine FIFO full,
  level sensitive). `0x8168` is the body that follows the 8-byte `add_ioboard` symbol in IP32's `kernel.o` (the symbol at `0x8160`
  is a bare return; objdump labels the body `add_ioboard+0x8`, past the recorded size). It writes two registers in the VICE window
  (`0xb700e014`, `0xb70001bc`), then tests bit 31 (VICE interrupt).

## Error registers (established decode)

### CPU error status (`0x48`) and address (`0x40`)

The kernel handles two layouts, chosen by `get_crimerev` (zero or not). Its symbol names for the two printing routines are
the reverse of the obvious reading: `print_buserr_rev1` (`0x102ec`) prints the three-bit layout, used when `get_crimerev`
is non-zero; `print_buserr_rev0` (`0x103fc`) prints the ten-bit layout, used when it is 0. Established from both routines
read in full and their message strings.

**Three-bit layout** (revision non-zero), printed as `CPU Error/Addr 0x<stat & 5><...>: 0x<addr>` and `VICE Error/Addr`:

| bit | meaning in the kernel's strings |
|---:|---|
| 2 | CPU "Invalid address" |
| 1 | VICE "Write parity error" |
| 0 | CPU "Write parity error" |

The routine tests `stat & 5` for the CPU line and `stat & 2` for the VICE line; bits 8:3 are never tested (the
specification adds address bits 39:34 there, "if it can be implemented"). The address is printed as read, not shifted left
by two.

**Ten-bit layout** (revision 0): CPU group, tested mask `0x217`: bit 9 "Invalid read address", bit 4 "Illegal instruction",
bit 3 "SysAD parity error", bit 2 "SysCMD parity error", bit 1 "Invalid write address", bit 0 "Invalid register address".
VICE group, mask `0x1e0`: bit 8 "Illegal instruction", bit 7 "SysAD parity error", bit 6 "SysCMD parity error", bit 5
"Invalid address". Bit 3 is tested for its string but is not in the `0x217` "anything to report" mask, so with the kernel
debug flag (`kdebug`) zero a lone SysAD parity bit prints nothing. `mlreset` stores `0x3ff` into `0x50` for revision 0,
the ten bits of this layout (inferred from the value; the register's role is the public driver's name only).

What the kernel does after decoding (`dobuserr` `0x102b0` and the routine at `0x10754`, read as far as the status bits): a
CPU-group error in user mode (mode argument 2) prints "Process %d [%s] sent SIGBUS due to Bus Error"; any other mode
prints "IRIX Killed due to Bus Error at PC". A VICE-group error is passed to `vice_err`. The status is cleared by storing 0
to `0x48` and `0x250` in `VEC_dbe`, `VEC_ibe`, the save routine at `0xff08` and the probes (sequences below).

### Memory error status (`0x250`), address (`0x258`), ECC registers

Decode routine at `kernel.o` `0x105c4` (read in full), printed as `MEMORY Error/Addr 0x<stat><<kind> during <access>>`:

| bits | meaning in the kernel's strings |
|---|---|
| 27, 26, 25 | invalid memory address on R/M/W, on write, on read (mask `0x0e000000`; exactly one tested at a time) |
| 22 | multiple ECC errors, "on R/M/W" if bit 24 is set, otherwise "on read" |
| 21 | hard ECC error, same bit-24 rule |
| 20 | soft ECC error, same bit-24 rule |
| 24 | R/M/W flag for 22, 21 and 20 (specification: "ECC read error during a read-modify-write") |
| 18, 17, 16, 15, 7 | access source: CPU, VICE, GBE, RE, MACE (the single bit under mask `0x78080`; none or several prints "UNKNOWN ACCESS TYPE") |

`ecc_handler` (`0xd894`, the R10000 cache-error exception path) reads `0x48`, `0x250`, `0x40` and `0x258`, tests
`0x250 & 0x240000` (hard error with CPU access), `0x48 & 5 == 5` and, for the ten-bit layout, `0x48 & 0x201 == 0x201`, and in
each case stores 0 to the status register. `ecc_error_correction` (`0xff50`) stores 0 to `0x250` after scrubbing the
faulting line through `scrub_memory`. The code is established; the intent of each combination is inferred.

### Probe sequence (how the kernel learns that an uncached access failed)

`badaddr`, `badaddr_val`, `wbadaddr`, `wbadaddr_val` and `earlybadaddr` (`0x14270` to `0x14a0c`) were read in full. They
share one shape:

1. store 0 to `0x48`, then 0 to `0x250`; read `0x250` and `0x48` back (drain).
2. store 0 to the MACE PCI error flags at `0xbf080004`; read them back.
3. perform the access: a read by width (`lb`, `lh`, `lw`, `ld`) or a store of 0 by width.
4. read `0x8` to drain (the write probes read it twice and then read physical address 0 through the uncached window).
5. read `0x28` and AND with `0x00300080` (bits 21, 20 and 7). If non-zero, call `baerror`, which repeats steps 1 and 2
   and returns failure.

So IRIX decides that a failed uncached read or write happened from the hardware interrupt register, not from an
exception, and groups memory error (21), CPU interface error (20) and MACE PCI error (7).

### Bus error exception path

`VEC_dbe` (`0x1c2d4`) and `VEC_ibe` (`0x20dc0`) run the same sequence: load `0x48`, `0x40`, `0x250`, `0x258` and `0x58` into
the `crm_*` globals; store 0 to `0x250` then `0x48`; read `0x48` and `0x250` back; clear the MACE PCI error flags at
`0xbf080004`; jump to the common trap code. `dobuserr` calls the save routine at `0xff08`, which reads those five plus
`0x268` and `0x260`, then stores 0 to `0x48` and `0x250`.

## Access sequences (established)

- Cold start (PROM): store 0 to `0x200`, `0x18`, `0x20`, `0x28` and `0x50` in turn (`0xbfc08390` to `0xbfc083bc`). The
  sloader's first routine stores an argument register to `0x270` and 0 to `0x200`.
- `mlreset`: read `0x8`; store 0 to `0x48` and `0x250`; call `get_crimerev`; if it is 0 store `0x3ff` to `0x50`; write `0x8` as
  above; store 0 to `0x18` then `0x10`; call `flushbus`; register the vectors; store 0 to `0x30`; clear the MACE PCI error flags.
- ECC: `ecc_enable` stores 1 to `0x200` only when the memory has been initialised and checking is enabled
  (`ecc_meminited`, `ecc_checking_enabled`); `ecc_disable` stores 0. Bit 1 (replacement select) is not written by any
  scanned image.
- Memory sizing: `cpu_get_memsize` (monitor) loads bank 0 control and counts 128 MB (`0x8000000`) if bit 8 is set, 32 MB
  otherwise; for banks 1 to 7 it skips a bank whose register equals bank 0's, else adds 128 MB or 32 MB by that bank's own
  bit 8. The diagnostic's sizing routine reads the banks as word pairs and applies the same rule. The PROM's sizing
  (`0xbfc05c28` on) clears bit 0 of `0x8`, stores `((candidate >> 25) & 0x1f) | 0x100` into the bank control registers
  (indexed), writes patterns at four addresses of the candidate range (base, `+0x1fffff8`, `+0x2000000`, `+0x7fffff8`) and
  reads them back to choose 32 MB or 128 MB per bank (its strings: "bank%d = 0x%lx (32M)" and "(128M)").

## Against the published specification

The comparison covers every register the census reached: 24 of 26 rows are in the map; `0x50` and `0x58` are not. Page
numbers are printed pages of the CRIME 1.5 Specification, revision 0.3.

**Agreements (read in the code first):**

- Identification (p. 5-26): ID 7:4, revision 3:0; the code takes the low nibble and compares the low word with 0xa0 and
  0xa1, which the specification gives for Petty Crime (ID 0xa, revision 0) and CRIME 1.1 (ID 0xa, revision 1).
- CPU interface control (pp. 5-26 to 5-27): bits 13:12 SysADC controls, 11 cold reset, 10 soft reset, 9 watchdog enable.
  The values the code stores (`0x3000`, `0x400`, `0x800`, bit 9 cleared) are those bits.
- Interrupt bit assignment (Table 5-5, pp. 5-18 to 5-20): bits 28 and 29 software interrupts and their IP levels, bit 20
  CPU interface error and bit 21 memory error, both at IP6, bit 31 VICE, bit 26 RE FIFO full (level), bits 19:16 GBE (edge).
- CPU error status (p. 5-32): bit 2 CPU illegal address, bit 1 VICE write parity, bit 0 CPU write parity: exactly the
  kernel's three-bit layout. The address register (p. 5-32) is treated by the kernel as an opaque doubleword.
- Memory error status (pp. 6-32 to 6-33): bits 27, 26, 25 invalid address (RMW, write, read), 24 ECC read error during
  RMW, 23 ECC read error, 22 multiple hard errors, 21 hard error, 20 soft error, 18 CPU, 17 VICE, 16 GBE, 15 RE, 7 MACE:
  the kernel's decode matches every bit it uses. Bank control (p. 6-32): bit 8 SDRAM size, 4:0 compare bits, as the sizing
  routines use them. Memory controller control (p. 6-30): bit 0 ECC enable.
- Timer (p. 5-31): 31:0 value; the specification's 66.7 MHz is consistent with the PROM's 66 ticks per microsecond.

**Conflicts and differences:**

- **CPU error status location.** The specification puts the CRIME 1.5 register at `0x4048` and says CRIME 1.1 has it at
  `0x48` (p. 5-25). Every IP32 routine reads and clears `0x48`; none touches `0x4048`. Whether a CRIME 1.5 aliases `0x48`
  is **unknown**.
- **Identification upper word.** The kernel uses bits 63:32 as part of the revision; the specification defines only 7:0.
  Unknown (open entry).
- **Ten-bit status layout.** The specification documents bits 2:0 and, as 8:3, address bits 39:34. The kernel's
  revision-0 layout, bits 9 and 4:0 for the CPU and 8:5 for VICE, is not in the specification.
- **Interrupt bits 20 and 21 in the prose.** Section 5.7.2.2 (p. 5-21) says bit 21 is the CPU transaction error and
  section 5.7.2.3 (p. 5-22) says bit 20 is the memory ECC error; Table 5-5, Table 5-10 and the kernel's decode say 20 is
  CPU and 21 is memory, as do the public drivers. The kernel gives both bits one handler, so it cannot decide.
- **Registers `0x50` and `0x58`.** In neither the map nor any table. The kernel reads `0x58` and calls it the VICE error
  address. `0x50` is stored to by `mlreset` and the PROM; the public NetBSD driver names it CPU error enable.
- **Interrupt status written.** `mlreset` stores 0 to the interrupt status register, which the specification lists as
  read-only. Effect unknown.
- **Access width.** The specification says doubleword access only; the diagnostic and PROM routines read the
  identification word and the bank controls with 32-bit loads. Unknown whether the chip honours that.
- **Not confirmed by the code:** the refresh counter (`0x248`), memory control bit 1 (replacement select), the JUICE field
  (control bits 7:5), watchdog operation, the ECC replacement register's contents, and second-error behaviour.

## Against the public drivers (reported after the reading above)

- Linux `arch/mips/include/asm/ip32/crime.h` and `sgi-ip32/crime.c` (v6.12): same offsets; ID low nibble `0x0f`, ID bits
  `0xf0`, revisions `0x00`, `0x11`, `0x13`, `0x14` (the values `get_crimerev` returns); CPU error status mask `0x7` with
  bit 2 illegal address, 1 VICE write parity, 0 CPU write parity; memory error bit names equal the kernel's;
  `CRIME_NS_PER_TICK` 15 and `CRIME_MASTER_FREQ` 66666500 match the timer. The handlers print status and address and clear
  the status by storing 0; the CPU error handler shifts the address left by two. Disagreement: Linux defines control bits
  3:0 and 7:4 as queue marks and bit 8 as endianness, while the specification gives 7:5 as the JUICE field and 4:0 as
  reserved. The kernel code here touches none of these.
- NetBSD `sys/arch/sgimips/dev/crimereg.h` and `crime.c`: names `0x50` CPU error enable and `0x58` VICE error address,
  matching what the kernel does. Its bank control macros put bank 1 at `0x218`, bank 2 at `0x210` and so on in swapped
  pairs, and bank 7 at `0x248`, which is the refresh counter; the shipped sizing code and the specification both read the
  eight banks in order from `0x208`. NetBSD's timer mask is 48 bits against the specification's 32.

## Reset expectations

Unknown for every register. No scanned routine reads a register before writing it except `0x8` (`mlreset` and the PROM
read-modify-write it). The specification gives defaults (JUICE field 001, endianness bit reading 1, everything else 0, ECC
off); the code agrees only in intent: the PROM stores 0 to `0x200`, `0x18`, `0x20`, `0x28` and `0x50`, and `mlreset` stores 0
to `0x18`, `0x10`, `0x30`, `0x48` and `0x250`.

## Write-error questions

What sets each error bit, what is latched on a failed or timed-out uncached access, and which vectors fire. Graded
entries: "established" lines are read from the files above or cited from a specification page; each ends with what is
not known.

1. **What sets CPU error status bit 2 and which addresses count?** Established: bit 2 is the "Invalid address" of the
   three-bit layout; the kernel prints it and, in user mode, raises SIGBUS, otherwise "IRIX Killed due to Bus Error".
   Established by the specification: the CPU error address "is recorded in the event of SysAD Parity Error, Invalid
   Address" (p. 5-32), bus errors are generated "for all cache reads not to memory address space" (p. 9-5), and uncached
   accelerated writes are not supported to I/O (p. 9-5). Inferred: a CPU access to a physical address nothing in Table 3-1
   decodes (p. 3-4) sets it. Unknown: which reserved ranges count, whether read and write differ in the three-bit layout
   (the ten-bit layout has separate bits 9 and 1), and whether a wrong-width access is an illegal address. The kernel
   never causes the error on purpose; its probes accept any of bits 21, 20 and 7.
2. **What is latched on a failed uncached write or read?** Established: the exception paths and the save routine read the
   CPU error address (`0x40`), status (`0x48`), VICE address (`0x58`) and the memory error pair, and print the address
   raw. Established by the specification: the address register holds address bits 33:2 and the address of the error
   (p. 5-32); the memory error address holds a 30-bit address (p. 6-34). Unknown: whether a second error overwrites the
   first (no code reads that case), whether status bits 8:3 are implemented, and what `0x58` holds after a CPU error.
3. **How does the kernel learn that an uncached store failed?** Established: the five-step probe above (drain, read the
   hardware interrupt register, test bits 21, 20 and 7); it never reads the status register to tell a write from a read.
   Unknown: whether the same failed store also takes a bus error exception on an R10000, and whether an uncached read of
   an undecoded address returns data or only sets the bits (the probe does not look at the value).
4. **Which interrupts fire?** Established: the kernel registers `buserror_intr` for CRIME interrupt bits 21 and 20. A
   handler for the MACE PCI error exists (`pci_error_intr`, `0x10b48`): it reads the MACE flags at `0xbf080004`, panics
   ("catastrophic error on PCI bus") for any of flag bits `0x3d000000` and otherwise clears them. No object read registers
   it, so which CRIME bit it is attached to is not read (the specification's Table 5-5 gives bit 7, "MACE PCI Error
   Conditions", IP6). `crmerr_intr` (`0x9f54`) only prints "CRIME/VICE error" and is likewise unregistered in the objects
   read. Inferred: bits 20 and 21 reach processor interrupt 6 (level argument 3 plus the specification's table). Unknown:
   the order between the exception and the interrupt for one failure, and whether the interrupt asserts with its enable
   bit clear (the probes read the unmasked hardware register; the enable register at `0x18` gates delivery per Table 5-11).
5. **Timed-out accesses.** Established: nothing in the scanned code or the specification gives CRIME a bus time-out other
   than the watchdog (`0x30`, pp. 5-30 to 5-31). A MACE-side failure appears as bit 7 and the MACE flags. Unknown: whether
   any CPU access to MACE space can time out inside CRIME. Route: the MACE chip page (not read here).
6. **Memory addresses.** Established: an invalid memory address on read, write and R/M/W sets status bits 25, 26 and 27
   with the source bit and the address (kernel decode above; the specification lists the same bits). Unknown: the range
   that is invalid (a bank hole, an address above the populated total, or an address no bank control register matches),
   and whether a CPU uncached store to such an address is posted and reported only through these bits. The PROM's sizing
   probes unpopulated ranges without reading `0x250` in the routines read, so it does not show it.
7. **Second errors and clears.** Inferred: status bits are sticky until software stores 0 (the kernel and both public
   drivers rely on it; none checks the result). Unknown: whether a store of 1 does anything, and what a new error between
   the read and the clear does.

## Open

See [docs/open-questions.md](../../docs/open-questions.md): the identification upper word, the status register location on
CRIME 1.5, the write-error questions above, the unreached registers (refresh counter, replacement select, JUICE field,
watchdog), the PROM's indexed sizing loops (the census records only the bases) and the diagnostic's stripped CRIME
routines (the census names them by address only).
