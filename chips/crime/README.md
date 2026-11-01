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

## Rendering engine registers (pixel pipeline, first group)

The CRIME 1.5 Specification, revision 0.3, puts the rendering engine at physical `0x15000000` and splits it into five
4 KB pages: interface buffer, TLB, pixel pipeline, memory transfer engine and status (p. 7-6 and Figure 7-3, p. 7-7). This section
grades the pixel pipeline registers at `+0x2000` that the IP32 kernel's two shadow-loading routines copy to the chip;
the specification pages are cited per register. The texture registers, the memory transfer engine and the TLB pages are
not graded here yet.

How the kernel reaches them, read in full from `crime.a(crime.o)` and `crime.a(crime_debug.o)` (established):

- The first word of the `crimeBoards` array (`crime.o` `.data` bytes 0 to 3) is `0xb5000000`, the uncached address of
  physical `0x15000000`; the second word is `0xb6000000`, the uncached address of the GBE window at `0x16000000`.
  `crime_init` stores the first word at byte 120 of a 560-byte record it allocates (the `lw` at 0x53d4, the `sw` at
  0x53d8). `crimePcxSwap` (address `0x2e54`) loads the word at byte 120 of its first argument into `s0` and passes it as
  the first argument of `crmLoadGlobalsFromShadow` (address `0x3434`, 328 bytes) at 0x2f30 and of
  `crmLoadNonglobalsFromShadow` (address `0x3240`, 500 bytes) at 0x2f3c. The second argument of both is the word at byte
  8 of `crimePcxSwap`'s third argument, the shadow record. Each loader first reads a flag word at shadow +496.
- Each loader copies one shadow word to the register at the same number plus `0x2000`, so shadow +0x20 holds the value
  for offset `0x2020`. A word copy is `lw` and `sw`, a doubleword copy is `ld` and `sd`.
- `crmIsGlobalRegWrite` (`crime_debug.o`, address `0x0`) answers for offsets `0x2000` to `0x21ff` with a byte of a
  128-byte table in `.data` indexed by `(offset >> 2) & 0x3ff`. The byte is 0 for a word of a non-global register and 1
  for a word of a global one. It is 2 for every four-byte position the specification's map leaves empty, except
  `0x2098` and `0x2134`, which hold 0.

### Buffer, clip and draw mode

- `0x15002000` (`0x2000`): `BufMode.src`, the colour buffer and pixel format that pixel transfers read from (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-9 and Table 7-4 p. 7-15). Established.
  Fields `bufType` [12:10], `bufDepth` [9:8], `pixType` [7:4], `pixDepth` [3:2], `doublePix` [1] and `doublePixSel` [0];
  `bufType` picks one of three framebuffer TLBs or two linear TLBs, and `pixType` 15 is YCrCb, which only the source
  register allows. Bits 31:13 are reserved.
  `crmLoadGlobalsFromShadow` stores to it first of all: an `lw` of shadow +0 at 0x3438 and the `sw` at 0x343c, before any
  flag test. Its table byte is 1.
- `0x15002008` (`0x2008`): `BufMode.dst`, the colour buffer and pixel format that drawing and transfers write to (CRIME
  1.5 Specification rev 0.3, Table 7-3 p. 7-9 and Table 7-5 p. 7-16). Established.
  It has the `BufMode.src` fields except that `pixType` 15 is not allowed.
  The global loader's second store is the `sw` at 0x3444 of shadow +8, unconditional like the first. Its table byte is 1.
- `0x15002010` (`0x2010`): `ClipMode`, which of the clip ID test and five screen mask tests are on and whether each
  mask passes the pixels inside or outside it (CRIME 1.5 Specification rev 0.3, Table 7-6 p. 7-17). Established.
  Bit 11 `enCid`, bit 10 `cidMapSel`, bits 9 to 5 `enScrMask0` to `enScrMask4`, bits 4 to 0 `scrMaskMode0` to
  `scrMaskMode4` (1 passes inside the mask).
  Third in the global loader, shadow +0x10 stored at 0x344c. Table byte 1.
- `0x15002018` (`0x2018`): `DrawMode`, the per-stage enable bits of the pixel pipeline: GL against X mode, pixel
  transfer, scissor, stipples, shading, texture, fog, antialiasing, alpha test, blend, dither, logic op, masks, depth
  and stencil (CRIME 1.5 Specification rev 0.3, Table 7-7 p. 7-18). Established.
  Bit 23 `enNoConflict`, bit 22 `enGL`, bit 21 `enPixelXfer`, bit 20 `enScissorTest`, bit 16 `enShade`, bit 15
  `enTexture`, bit 8 `enLogicOp`, bit 7 `enColorMask`, bit 2 `enDepthTest` and bit 0 `enStencilTest` are among the
  bits it defines; bits 31:24 are reserved.
  The fourth store of the global loader, shadow +0x18 at 0x3454. Table byte 1.

### Screen masks, scissor and window offsets

- `0x15002020` (`0x2020`): `ScrMask[0]`, the first framebuffer-space rectangle that `ClipMode` can test pixels against
  (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-9 and Table 7-11 p. 7-20). Established.
  A 64-bit register: `min.x` [63:48], `min.y` [47:32] (both inclusive), `max.x` [31:16], `max.y` [15:0] (both exclusive).
  The global loader moves it as a doubleword, `ld` of shadow +0x20 at 0x3458 and `sd` at 0x345c. Both table bytes (for
  0x2020 and 0x2024) are 1.
- `0x15002028` (`0x2028`): `ScrMask[1]`, the second screen mask, tested when `ClipMode` bit 8 is set (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-9 and Table 7-6 p. 7-17). Established.
  Same 64-bit rectangle layout as `ScrMask[0]`. The map's description repeats "screen mask 0" for every element of the
  array, and the enable bits in `ClipMode` give the numbering.
  Doubleword `ld` at 0x3460, `sd` at 0x3464. Table bytes 1 and 1.
- `0x15002030` (`0x2030`): `ScrMask[2]`, the third screen mask, tested when `ClipMode` bit 7 is set (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-9 and Table 7-6 p. 7-17). Established.
  The rectangle layout is the same as for `ScrMask[0]`; `ClipMode` bit 2 chooses inside or outside.
  The loader's `ld` is at 0x3468 and its `sd` at 0x346c, shadow +0x30. Table bytes 1 and 1.
- `0x15002038` (`0x2038`): `ScrMask[3]`, the fourth screen mask, tested when `ClipMode` bit 6 is set (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-9 and Table 7-6 p. 7-17). Established.
  The same rectangle layout; `ClipMode` bit 1 chooses inside or outside.
  Loaded by the `ld` at 0x3470 from shadow +0x38 and stored by the `sd` at 0x3474. Table bytes 1 and 1.
- `0x15002040` (`0x2040`): `ScrMask[4]`, the fifth and last screen mask, tested when `ClipMode` bit 5 is set (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-9 and Table 7-6 p. 7-17). Established.
  The same rectangle layout; `ClipMode` bit 0 chooses inside or outside.
  The last doubleword pair of that run: `ld` at 0x3478 of shadow +0x40, `sd` at 0x347c. Table bytes 1 and 1.
- `0x15002048` (`0x2048`): `Scissor`, the GL scissor rectangle in window coordinates, applied when `DrawMode` bit 20 is
  set (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-9 and Table 7-10 p. 7-20). Established.
  A 64-bit register with the same layout as a screen mask, `min.x` [63:48] to `max.y` [15:0], but the coordinates are
  window-relative rather than framebuffer-relative.
  Unlike the masks, the global loader reaches it only after the flag word's 0x80 bit has been tested clear: the `ld` is
  at 0x3500 and the `sd` at 0x350c, shadow +0x48. Table bytes 1 and 1.
- `0x15002050` (`0x2050`): `WinOffset.src`, the x and y offset that turns window coordinates into framebuffer
  coordinates for the source side of a transfer (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-9 and Table 7-9
  p. 7-19). Established.
  Bits 31:16 hold `x` and bits 15:0 hold `y`; the description of the `y` field in the specification's table repeats
  "x-coordinate offset", which reads as a typing slip.
  The global loader's `lw` at 0x3480 reads shadow +0x50 and the `sw` is at 0x3484. Table byte 1.
- `0x15002058` (`0x2058`): `WinOffset.dst`, the same window-to-framebuffer offset for the destination side (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-9 and Table 7-9 p. 7-19). Established.
  It holds `x` in bits 31:16 and `y` in bits 15:0.
  Shadow +0x58 is read at 0x3488 and stored at 0x348c, right after the source offset. Table byte 1.

### Primitive and vertices

- `0x15002060` (`0x2060`): `Primitive`, the op-code word that names the geometric primitive the pixel pipeline renders
  next, a non-global write-only register (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-9 and Table 7-8 p. 7-19).
  Established.
  Bits 31:24 `opCode` (0 point, 1 line, 2 triangle, 3 rectangle), bit 18 `lineSkipLastEP`, bits 17:16 `edgeType` (four
  traversal directions), bits 15:0 `lineWidth`, which is half the width in subpixels.
  The first store of `crmLoadNonglobalsFromShadow`, with no condition: `lw` of shadow +0x60 at 0x3244, `sw` at 0x3248.
  Table byte 0.
- `0x15002080` (`0x2080`): `Vertex.GL[0].x`, the x coordinate of the first vertex of a GL primitive, a 13.6 fixed
  point value (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-10). Established.
  The non-global loader writes the six GL vertex words only when the flag word's 0x80 bit is clear: the `beqz` at 0x32bc
  jumps to them then, and with the bit set the loader copies three X vertex words instead and returns. This is the first
  GL word, the `sw` at 0x32e8 of shadow +0x80. Table byte 0.
- `0x15002084` (`0x2084`): `Vertex.GL[0].y`, the y coordinate of the first GL vertex in the same 13.6 fixed point
  format (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-10). Established.
  Stored by the `sw` at 0x32f0 from shadow +0x84, directly after the x word, on the same path as the other GL vertex
  words. Table byte 0.
- `0x15002088` (`0x2088`): `Vertex.GL[1].x`, the x coordinate of the second GL vertex, the end of a line or the
  second corner of a triangle or rectangle (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-10). Established.
  It is a 13.6 fixed point value. The loader's `sw` is at 0x32f8 and its source is shadow +0x88. Table byte 0.
- `0x1500208c` (`0x208c`): `Vertex.GL[1].y`, the matching y coordinate of the second GL vertex (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-10). Established.
  The 13.6 fixed point format again; shadow +0x8c is stored at 0x3300 in the same run. Table byte 0.
- `0x15002090` (`0x2090`): `Vertex.GL[2].x`, the x coordinate of the third vertex, used by triangles (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-10). Established.
  Format 13.6 fixed point. The loader stores shadow +0x90 at 0x330c, just before the flag bits 0x10, 0x08 and 0x20 are
  isolated for the later groups. Table byte 0.
- `0x15002094` (`0x2094`): `Vertex.GL[2].y`, the y coordinate of the third vertex (CRIME 1.5 Specification rev 0.3,
  Table 7-3 p. 7-10). Established.
  13.6 fixed point. It is the last word of the GL vertex run: its `sw` at 0x3324 sits in the delay slot of the `beqz` at
  0x3320, so it executes whether or not that branch is taken, from shadow +0x94. Table byte 0.

### Pixel transfer, stipple and colour

- `0x150020a0` (`0x20a0`): `PixelXfer.src.addr`, the start address of the framebuffer or linear buffer that a pixel
  transfer reads (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-10). Established.
  It is a 32-bit write-only register.
  In `crmLoadNonglobalsFromShadow` it follows `Primitive` unconditionally: `lw` of shadow +0xa0 at 0x324c, `sw` at
  0x3250. Table byte 0.
- `0x150020a8` (`0x20a8`): `PixelXfer.src.xStep`, the step in the source buffer for each pixel along x (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-10). Established.
  The loader reads shadow +0xa8 at 0x3254 and stores it at 0x3258; no flag guards it. Table byte 0.
- `0x150020ac` (`0x20ac`): `PixelXfer.src.yStep`, the step in the source buffer for each row along y (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-10). Established.
  Its `sw` is at 0x3260, from shadow +0xac, on the unconditional part of the loader. Table byte 0.
- `0x150020b0` (`0x20b0`): `PixelXfer.dst.linAddr`, the start address of a linear destination buffer for a pixel
  transfer (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-10). Established.
  Stored at 0x3268 from shadow +0xb0, between the source steps and the stride. Table byte 0.
- `0x150020b4` (`0x20b4`): `PixelXfer.dst.linStride`, the row stride of that linear destination buffer (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-10). Established.
  The last transfer register of the run: shadow +0xb4 is loaded at 0x326c and stored at 0x3274. Table byte 0.
- `0x150020c0` (`0x20c0`): `Stipple.mode`, which pattern word the stipple unit starts at and how long each is held
  (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-10 and Table 7-12 p. 7-21). Established.
  Fields `index` [28:24] (start word, 0 to 31), `maxIndex` [20:16], `repeatCnt` [15:8] and `maxRepeat` [7:0]; the
  specification also reserves bits 23:20, which overlaps `maxIndex`.
  The non-global loader copies it, with the pattern word after it, only when flag bit 0x01 is set: the `beqz` at 0x3284
  skips the pair, whose `lw` is at 0x328c and `sw` at 0x3290 from shadow +0xc0. Table byte 0.
- `0x150020c4` (`0x20c4`): `Stipple.pattern`, the 32-bit pattern word that line and polygon stippling take bits from
  (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-10). Established.
  It is a full word with no field split.
  The same flag-0x01 pair as `Stipple.mode`: the `lw` at 0x3294 reads shadow +0xc4 and the `sw` at 0x3298 stores it.
  Table byte 0.
- `0x150020d0` (`0x20d0`): `Shade.fgColor`, the flat shade colour or foreground colour of a primitive (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-10). Established.
  Write-only and non-global in the specification's map.
  Its store at 0x3288 sits in the delay slot of the `beqz` at 0x3284, so it runs whichever way that flag test goes; the
  value is shadow +0xd0, read at 0x327c. Table byte 0.
- `0x150020d8` (`0x20d8`): `Shade.bgColor`, the background colour for opaque stippling (CRIME 1.5 Specification rev
  0.3, Table 7-3 p. 7-10). Established.
  The only global register of the colour group, readable and writable.
  `crmLoadGlobalsFromShadow` restores it with the `lw` at 0x34a4 from shadow +0xd8 and a store at 0x34b0 in the delay
  slot of the `beqz` at 0x34ac, so it is unconditional even though it is written after the flag test of bit 0x04.
  Table byte 1.

### Logic op and colour mask

- `0x150021b0` (`0x21b0`): `LogicOp`, the logic operation applied when `DrawMode` bit 8 enables it (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-13). Established.
  A global 32-bit register, readable and writable.
  It is the twelfth store of the global loader, after the eleven buffer, mask and offset registers: `lw` at 0x3490, `sw`
  at 0x3494. Table byte 1.
- `0x150021b8` (`0x21b8`): `ColorMask`, the colour buffer plane mask applied when `DrawMode` bit 7 enables it (CRIME
  1.5 Specification rev 0.3, Table 7-3 p. 7-13). Established.
  A global 32-bit register, readable and writable.
  Shadow +0x1b8 is read at 0x3498 and stored at 0x34a0, directly after `LogicOp`. Table byte 1.

### X-primitive vertices

The non-global loader tests the flag word's 0x80 bit at 0x32bc after the memory-transfer and stipple groups. With the bit
set it falls through into the three X vertex copies below and returns at 0x32dc; the GL vertices, fog, depth, shade and
texture groups are then not loaded. With the bit clear it branches to the GL vertex copies at 0x32e4 (established).

- `0x15002070` (`0x2070`): `Vertex.X[0]`, the packed (x0,y0) first vertex of an X-window primitive (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-9). Established.
  The spec's map lists it as a 32-bit non-global write-only register and gives no field split for the packed pair.
  The `lw` at 0x32c4 reads shadow +0x70 and the `sw` at 0x32c8 stores it, the first copy of the flag-0x80 path. Table
  byte 0, as for every vertex register.
- `0x15002074` (`0x2074`): `Vertex.X[1]`, the packed (x1,y1) second vertex (CRIME 1.5 Specification rev 0.3, Table 7-3
  p. 7-9). Established.
  Same 32-bit non-global write-only class as the first vertex word. Loaded from shadow +0x74 at 0x32cc and stored at
  0x32d0, directly behind `Vertex.X[0]`. Table byte 0.
- `0x15002078` (`0x2078`): `Vertex.X[2]`, the packed (x2,y2) third vertex, the one that matters for triangles (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-10). Established.
  The loader reads shadow +0x78 at 0x32d4 and stores it at 0x32d8, the last copy before the `jr ra` at 0x32dc, so a
  flag-0x80 pass ends with this word. Table byte 0; the byte for the next word, 0x207c, is 2 (an empty position).

### Shade interpolation registers

All twelve are 32-bit non-global write-only registers holding 9.12 two's complement values (spec Table 7-3 pp. 7-10 and
7-11; section 7.3.7.1, pp. 7-44 to 7-45, adds that the hardware iterates them in 21-bit steppers and keeps the
integer part clamped to 8 bits). Their table byte is 0. The non-global loader stores them in address order, shadow
offset equal to register offset minus 0x2000, one `lw` and `sw` pair each, only when flag bit 0x10 is set: the test at
0x3370 branches to 0x33d8 over the whole run, and the run is reached only on the flag-0x80-clear path.

- `0x150020e0` (`0x20e0`): `Shade.Rs`, the starting red value of a smooth-shaded primitive (CRIME 1.5 Specification
  rev 0.3, Table 7-3 p. 7-10). Established.
  First of the twelve: `lw` at 0x3378 from shadow +0xe0, `sw` at 0x337c. Per the specification adding 0.5 to the
  initial value makes the truncating hardware round.
- `0x150020e4` (`0x20e4`): `Shade.Gs`, the starting green value (Table 7-3 p. 7-11). Established.
  `lw` at 0x3380, `sw` at 0x3384, second in the run.
- `0x150020e8` (`0x20e8`): `Shade.Bs`, the starting blue value (Table 7-3 p. 7-11). Established.
  Third of the run: `lw` at 0x3388, `sw` at 0x338c.
- `0x150020ec` (`0x20ec`): `Shade.As`, the starting alpha value (Table 7-3 p. 7-11). Established.
  The fourth copy, `lw` at 0x3390 and `sw` at 0x3394. The specification also uses this stepper for colour-index
  smooth shading, loaded with 12.8 values for 12-bit indices and 8.12 values for 8-bit ones (p. 7-45).
- `0x150020f0` (`0x20f0`): `Shade.drdx`, the red slope per step in x (Table 7-3 p. 7-11). Established.
  Fifth in the run, `lw` at 0x3398 and `sw` at 0x339c.
- `0x150020f4` (`0x20f4`): `Shade.dgdx`, the green slope per step in x (Table 7-3 p. 7-11). Established.
  Sixth: `lw` at 0x33a0, `sw` at 0x33a4. The x slopes are not contiguous: red, green here, blue and alpha after the y
  slopes of red and green.
- `0x150020f8` (`0x20f8`): `Shade.drdy`, the red slope per step in y (Table 7-3 p. 7-11). Established.
  Seventh: `lw` at 0x33a8, `sw` at 0x33ac.
- `0x150020fc` (`0x20fc`): `Shade.dgdy`, the green slope per step in y (Table 7-3 p. 7-11). Established.
  Eighth: `lw` at 0x33b0, `sw` at 0x33b4.
- `0x15002100` (`0x2100`): `Shade.dbdx`, the blue slope per step in x (Table 7-3 p. 7-11). Established.
  Ninth: `lw` at 0x33b8, `sw` at 0x33bc.
- `0x15002104` (`0x2104`): `Shade.dadx`, the alpha slope per step in x (Table 7-3 p. 7-11). Established.
  Tenth: `lw` at 0x33c0, `sw` at 0x33c4.
- `0x15002108` (`0x2108`): `Shade.dbdy`, the blue slope per step in y (Table 7-3 p. 7-11). Established.
  Eleventh: `lw` at 0x33c8, `sw` at 0x33cc.
- `0x1500210c` (`0x210c`): `Shade.dady`, the alpha slope per step in y (Table 7-3 p. 7-11). Established.
  Last of the run: `lw` at 0x33d0 and `sw` at 0x33d4, after which the loader tests flag 0x08 at 0x33d8. The table byte
  for the following word, 0x2110, is 1 (the first global register of the texture group).

### Fog and antialias

The non-global loader copies five registers when flag bit 0x40 is set. The test at 0x3320 sits ahead of the group, and
the delay slot of its `beq` is the `sw` of `Vertex.GL[2].y` at 0x3324, which runs whichever way the branch goes. The five
copies come in the order 0x2178, 0x2180, 0x2188, 0x2190, 0x2194, and on the flag-clear path the loader jumps to the
depth test at 0x3350 instead. One global register of the group, `Fog.color`, is in the global loader below.

- `0x15002170` (`0x2170`): `Fog.color`, the RGB colour that fogged fragments blend toward (CRIME 1.5 Specification rev
  0.3, Table 7-3 p. 7-12; section 7.3.7.9 p. 7-49 gives the blend as f*(Cr-Fc)+Fc, alpha untouched). Established.
  A global register, readable and writable, table byte 1. The global loader copies it first in its flag-0x40 group: `lw`
  of shadow +0x170 at 0x3510, `sw` at 0x3514. The group is reached only when the flag word's 0x80 bit tested clear at
  0x34ec; the 0x40 test is the `beq` at 0x3508, whose delay slot is the `Scissor` store.
- `0x15002178` (`0x2178`): `Fog.Fs`, the fog blend factor at the primitive's reference point, the start of the linear
  interpolation (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-13). Established.
  Non-global and write-only. The specification table calls it a 9.12 value and section 7.3.7.9 (p. 7-50, Table 7-18)
  calls the stepper 1.20; the loader moves the raw word, so the code settles neither. It is the first copy of the
  flag-0x40 group: `lw` at 0x3328, `sw` at 0x332c.
- `0x15002180` (`0x2180`): `Fog.dfdx`, the change of the fog factor per pixel step in x (Table 7-3 p. 7-13). Established.
  Second copy of the group, `lw` at 0x3330 and `sw` at 0x3334. Table byte 0. The 9.12 against 1.20 disagreement
  noted for `Fog.Fs` applies here too.
- `0x15002188` (`0x2188`): `Fog.dfdy`, the change of the fog factor per pixel step in y (Table 7-3 p. 7-13).
  Established.
  Third copy: `lw` at 0x3338, `sw` at 0x333c. The spec's description of this register repeats "df/dx", which reads as a
  typing slip. Table byte 0.
- `0x15002190` (`0x2190`): `Antialias.line`, the line slope and the ideal line's starting minor coordinate packed in one
  word (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-13). Established.
  The loader stores it fourth in the group: `lw` at 0x3340, `sw` at 0x3344. The specification gives its field table
  (slope [31:16], ideal start [15:0], p. 7-24) as 2.14 two's complement, the register map as 2.12, and section
  7.3.7.10 (p. 7-51) asks the host for a 2.12 slope in [-1, 1]. Which of 2.12 and 2.14 the hardware uses is unknown from the
  code, which copies the word unchanged. Table byte 0.
- `0x15002194` (`0x2194`): `Antialias.cov`, the start and end endpoint coverage values of an antialiased line (CRIME 1.5
  Specification rev 0.3, Table 7-3 p. 7-13). Established.
  The map describes two 7-bit coverage values and gives no bit positions; the extracted pages do not either, so the field
  split is unknown. Last of the group: `lw` at 0x3348, `sw` at 0x334c. Table byte 0; the byte at 0x2198 is 1.

### Alpha test and blend

All three are global registers (table byte 1) copied by the global loader in the flag-0x40 group: after `Fog.color` at
0x3510 come `Blend.constColor`, `Blend.func` and `AlphaTest`, in that order, not in address order.

- `0x15002198` (`0x2198`): `AlphaTest`, the comparison function and 8-bit reference that fragment alpha is tested against
  once `DrawMode` bit 11 enables the test (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-13 and section 7.3.1.15 p.
  7-24). Established.
  `func` is bits 11:8 (0 NEVER, 1 LESS, 2 EQUAL, 3 LEQUAL, 4 GREATER, 5 NOTEQUAL, 6 GEQUAL, 7 ALWAYS, Table 7-19), `ref`
  is bits 7:0, bits 31:12 are reserved. The map prints its name with a trailing dot. It is the last copy of the group:
  `lw` at 0x3528, `sw` at 0x352c.
- `0x150021a0` (`0x21a0`): `Blend.constColor`, the RGBA constant that the CONSTANT_COLOR and CONSTANT_ALPHA blend factors
  use (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-13; blend factors on p. 7-25). Established.
  The spec's map says only "blend RGBA constant color"; which byte is which channel is not given in the extracted pages
  and is unknown. The loader reads shadow +0x1a0 at 0x3518 and stores it at 0x351c, second in the group.
- `0x150021a8` (`0x21a8`): `Blend.func`, the blend operation and the two blend factors (CRIME 1.5 Specification rev 0.3,
  Table 7-3 p. 7-13 and section 7.3.1.16 pp. 7-24 to 7-25). Established.
  Fields: `op` [11:8] (0 ADD, 1 MIN, 2 MAX, 3 SUBTRACT, 4 REVERSE_SUBTRACT), `src` [7:4] (0 to 12, ZERO through
  SRC_ALPHA_SATURATE) and `dst` [3:0] (0 to 11, ZERO through ONE_MINUS_CONSTANT_ALPHA; the destination list has no
  saturate and lists SRC_COLOR where the source list has DST_COLOR). Third in the group: `lw` at 0x3520, `sw` at 0x3524.

### Depth and stencil

- `0x150021c0` (`0x21c0`): `Depth.func`, the comparison between the fragment's depth and the stored depth, enabled by
  `DrawMode` bit 2 (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-13 and section 7.3.7.17 p. 7-57). Established.
  The function values are the eight of Table 7-25 (NEVER, LESS, EQUAL, LEQUAL, GREATER, NOTEQUAL, GEQUAL, ALWAYS); the
  specification's register layout table has no body in the extracted pages, so the bit position of the value is
  unknown. A global register (table byte 1): in the global loader's flag-0x20 group, whose test is at 0x3530 and whose
  first copy is `lw` at 0x3538 and `sw` at 0x353c, shadow +0x1c0.
- `0x150021c8` (`0x21c8`): `Depth.Zs`, the starting depth of the primitive's depth plane (CRIME 1.5 Specification rev
  0.3, Table 7-3 p. 7-13 and Table 7-24 p. 7-57). Established.
  A 64-bit non-global write-only register holding a 25.12 two's complement value. The non-global loader moves it as a
  doubleword (`ld` at 0x3358, `sd` at 0x335c) as the first of three in its flag-0x20 group, the test being the `beq` at
  0x3350. Table byte 0.
- `0x150021d0` (`0x21d0`): `Depth.dzdx`, the depth slope per pixel step in x, 25.12 (CRIME 1.5 Specification rev 0.3,
  Table 7-3 p. 7-13). Established.
  Doubleword copy, `ld` at 0x3360 and `sd` at 0x3364, the second of the depth trio. Table byte 0.
- `0x150021d8` (`0x21d8`): `Depth.dzdy`, the depth slope per pixel step in y, 25.12 (CRIME 1.5 Specification rev 0.3,
  Table 7-3 p. 7-13). Established.
  The closing doubleword of the trio: `ld` at 0x3368, `sd` at 0x336c, followed by the flag-0x10 test for the shade run
  at 0x3370. Table byte 0.
- `0x150021e0` (`0x21e0`): `Stencil.mode`, the stencil test parameters: comparison function, reference and the three
  stencil operations (CRIME 1.5 Specification rev 0.3, Table 7-3 p. 7-13; Tables 7-26 and 7-27 p. 7-58). Established.
  The function values are the eight of Table 7-26 and the operations ZERO, KEEP, REPLACE, INCR, DECR and INVERT. The
  specification's stencil test text says "TBD" and its register layout table has no body in the extracted pages.
  Unknown: the bit positions of its fields; the route is the unpublished field table of the 1.5 specification or a
  shipped renderer that builds the word. Global (table byte 1): the second copy of the
  global loader's flag-0x20 group, `lw` at 0x3540 and `sw` at 0x3544 from shadow +0x1e0.
- `0x150021e8` (`0x21e8`): `Stencil.mask`, the stencil buffer bit mask (CRIME 1.5 Specification rev 0.3, Table 7-3
  p. 7-14). Established.
  The map gives its type as global read/write and its description as one line; no layout is printed. It is the last
  register of the global loader's flag-0x20 group, `lw` at 0x3548 and `sw` at 0x354c, after which the loader tests flag
  0x08 at 0x3550. Table byte 1.

## Routines in the IP32 build

One entry per routine, read from the object or member named in its entry, with the relocations for the calls. Addresses
are offsets inside that object.

### Graphics member routines (`crime.a`)

- `crime_cmov2i` (`crime.a(crime_tp.o)`, address `0x2b0`, 20 bytes): stores `a1` at byte 0 and `a2` at byte 4 of a
  two-word static record in `.bss`, then returns with v0 untouched. Established.
- `crime_color` (`crime.a(crime_tp.o)`, address `0x0`, 44 bytes): stores one word to `.bss` and leaves it in v0. For
  `a1` below 255 the word is `a1 + 1`; for 255 or more it is 255. The 8-bit value is repeated in all four bytes of the
  word. Established.
- `crime_getdesc` (`crime.a(crime_tp.o)`, address `0x978`, 24 bytes): returns 1 when the second argument is 1 and 0
  otherwise. The compare at +0x4 and the return at +0x10 are the whole body, so it reads no memory and writes no
  device. Established.
- `crime_positioncursor` (`crime.a(crime_tp.o)`, address `0x990`, 44 bytes): writes one word at the GBE window's
  `0x70000` offset that packs `a1` into bits 11:0 and `a2` into bits 27:16, each masked to 12 bits. It returns 0 and
  does not use `a0`. The window base is the pointer at byte 4 of `crimeBoards`. Established for the store. Inferred:
  that pointer is the display back end (GBE) window base, since `0x70000` lies inside that window's 16 MB.
- `crime_unblank` (`crime.a(crime_tp.o)`, address `0x944`, 52 bytes): calls `gbeBlankScreen`. The first, fourth
  and fifth arguments are zero. The second is the word at byte 8 of `crimeBoards`, and the third is the word at
  byte 4 of it. It returns what the callee returns. Established.
- `crime_FpSchedForRetrace` (`crime.a(crime_retrace.o)`, address `0x1098`, 60 bytes): reads the byte at offset 40 of
  the record that the word at byte 124 of `a0` points to. It clears the word at byte 836 of the record that the word at
  byte 140 points to. If the byte is zero it stores 1 when `a1` is zero and 2 when `a1` is nonzero. Established.
- `crime_retrace_callback` (`crime.a(crime_retrace.o)`, address `0xb70`, 16 bytes): stores `a1` and `a2` in two words
  of the small-data area at gp offsets -30696 and -30692, and returns 0. Established.
- `crime_getustmsc` (`crime.a(crime_retrace.o)`, address `0x3274`, 68 bytes): picks the 64-byte record of `crimeBoards`
  indexed by `a0`, follows its word at byte 12, and calls `crm_getustmsc` with the word at byte 128 as the first
  argument, the word at byte 140 as the second and the word at byte 48 of the record at byte 124 as the third. It
  drops its own `a1` and returns 0. Established.
- `crimeDownload` (`crime.o`, address `0xa6c`, 8 bytes): returns 0. The return at +0x0 and its delay slot at +0x4,
  which clears v0, are the whole body, so it touches no memory and no device. Established.
- `crimeLockOut` (`crime.o`, address `0x36c8`, 8 bytes): returns 1. The return at +0x0 and its delay slot at +0x4,
  which sets v0 to 1, are the whole body, so it touches no memory and no device. Established.
- `crimePcxSwitch` (`crime.o`, address `0x36d0`, 8 bytes): returns 0. The return at +0x0 and its delay slot at +0x4,
  which clears v0, are the whole body, so it touches no memory and no device. Established.
- `crmIsGlobalRegWrite` (`crime.a(crime_debug.o)`, address `0x0`, 56 bytes): takes a register offset in `a0`. It
  returns 1 below `0x2000` and from `0x2200` up. For offsets `0x2000` to `0x21ff` it returns the byte at index
  `(a0 >> 2) & 0x3ff` of a table in `.data`, which covers 128 words. Established.
- `crm_curproc_vtop` (`crime.a(crime_dma.o)`, address `0x0`, 128 bytes): calls `curproc_vtop` with its first three
  arguments and 4 as the fourth. If that returns 0 it returns 14. Otherwise it counts the pages from `a1` plus the page
  offset of `a0`, rounded up, and reads that many words from the third argument. It returns 14 if any word is zero and
  0 if none is. Established.
- `crimeEmptyWaitTimeout` (`crime.a(crime.o)`, address `0x120`, 136 bytes): the timeout routine for the FIFO-empty wait.
  It raises the level with `splhi`. When the word at byte 544 of `a0` is nonzero it calls `crime_intr_disable` with 25,
  clears the word at byte 316, restores the level with `splx`, and calls `crimeError` with the word at byte 120 of `a0`
  and a `.rodata` address. It then clears the words at bytes 544 and 60 of `a0` and decrements the word at byte 44 of
  the record at byte 24 of the record at byte 40 of `a0`. When byte 544 is zero it only restores the level and returns
  the `splx` result. Established for the paths. Inferred: `crimeFifoFullHandler` arms this routine with `timeout` and a
  200-unit delay (the constant 0xc8).
- `crimeInfo` (`crime.a(crime.o)`, address `0x384`, 88 bytes): caps the count in `a2` at 496: a count of 497 or more
  becomes 496. It calls `copyout` with the word at byte 124 of `a0` as the first argument, `a1` unchanged as the second
  and the count as the third. A nonzero `copyout` result makes it return 14. Otherwise it stores the count in the word
  that `a3` points to and returns 0. Established.
- `crmNextIncarnation` (`crime.a(crime.o)`, address `0x3dc`, 56 bytes): adds 1 to the small-data word at gp offset -30712
  under `splhi` and `splx`, and returns the new value in v0. Established.
- `crimeDetach` (`crime.a(crime.o)`, address `0x514`, 64 bytes): clears the word at byte 28 of `a0` and passes its old
  value to `gfxdd_munmap` as the first argument. It then decrements the word at byte 320 of the record at byte 24 of `a0`
  and returns 0. Established.
- `crimeInitialize` (`crime.a(crime.o)`, address `0x554`, 76 bytes): clears the byte at offset 152 of the record at byte
  24 of `a0`. The delay slot of the call clears the halfword at byte 120 of `crimeBoards`, and the call is
  `htp_register_board` with four zero arguments. The routine then sets the byte at offset 152 to 1 and returns 0.
  Established.
- `crimeSetNullClip` (`crime.a(crime.o)`, address `0xa74`, 56 bytes):
  stores 0 at `+0x34` and `+0x24` of `a0`, -1 at `+0x20`, 0 at `+0x18`, `+0x14` and `+0x10`, -1 at `+0xc` and `+0x8`,
  and 1 at `+0x2c` and `+0x28`, then returns 0. The stores go out in that order, `+0x20` third. Established.
- `crimePositionCursor` (`crime.a(crime.o)`, address `0xaac`, 92 bytes):
  stores `a1` at `+0x9c` and `a2` at `+0xa0` of `a0`. It reads the word at `+0x38` of the record at `+0x7c` of `a0`.
  When bit 1 of that word is set and `a2` is 513 or more, `a2` drops by 512 first. The x value is `a1` minus the byte
  at `+0x9a`, and the y value is `a2` minus the byte at `+0x9b`. Each is masked to 12 bits, and y goes to bits 27:16.
  The packed word is stored at `+0x94`, the byte at `+0x99` is set to 1, and the routine returns 0. Established.
- `crm_freedrawable` (`crime.a(crime.o)`, address `0xb08`, 80 bytes): unlinks the record `a0` from a list. The forward
  link is the word at byte 0 and the back link is the word at byte 4. The back record's byte 0 gets the forward link, and
  when the forward link is nonzero its byte 4 gets the back link. It then clears 108 bytes at `a0` with `bzero` and
  returns the result of `kern_free` on `a0`. The back link is not checked for zero. Established for the sequence.
  Inferred: the record is a 108-byte node of a doubly linked list.
- `crm_createdrawable` (`crime.a(crime.o)`, address `0xb58`, 72 bytes): allocates 108 bytes with `kern_malloc`, clears
  them with `bzero`, stores 16 at byte 36 and its first argument at byte 8, and returns the allocated pointer. The
  allocation result is not checked before `bzero` runs on it. Established.
- `crm_mapcliptodraw` (`crime.a(crime.o)`, address `0xba0`, 92 bytes): starts from the word at byte 6592 of
  `crmFrameBuffer` and walks a list along the word at byte 0 of each node while the key at byte 8 is below `a0`. It
  returns the node whose key equals `a0`, or 0 when the list ends or the first key at or above `a0` is not equal to it.
  Established.
- `crmunpinscratch` (`crime.a(crime.o)`, address `0x1010`, 44 bytes): calls `fast_undma` with the words at bytes 0, 4 and
  8 of `a0` as arguments 1 to 3 and 0 as argument 4, and returns its result. Established.
- `crimeInvalTLB` (`crime.a(crime.o)`, address `0x29a0`, 40 bytes): calls `ddv_invaltlb` with the word at byte 28 of
  `a0`, 0 and -1, and returns 0. Established.
- `crimeSuspend` (`crime.a(crime.o)`, address `0x36d8`, 36 bytes): when `a0` is nonzero and the word at byte 60 of `a0` is
  zero, it clears the word at byte 72 of `a0`. It returns 0 on every path. Established.
- `crimeResume` (`crime.a(crime.o)`, address `0x36fc`, 48 bytes): when `a0` is nonzero and the word at byte 72 of `a0` is
  nonzero, it clears that word and calls `force_resched`. It returns 0 on every path. Established.
- `crimeLoadTimingTable` (`crime.a(crime.o)`, address `0x372c`, 36 bytes): calls `crime_setvideotiming` with its first
  argument unchanged, the word at byte 124 of `a0` as the second and its own second argument as the third. It returns
  the callee's result. Established.
- `crimeInterrupt` (`crime.a(crime.o)`, address `0x4af8`, 68 bytes):
  for `a1` equal to 18 or 19 it calls `crime_hli_handler` with the word at byte 24 of `crimeBoards` as the first argument, `a1` minus 16 as the second,
  19 as the third and the original `a1` as the fourth. For any other `a1` it returns with `v0` unchanged. Established.
- `crime_present` (`crime.a(crime.o)`, address `0x58f4`, 40 bytes): returns -1 when `a0` is nonzero. Otherwise it returns
  0 when the word at byte 16 of `crimeBoards` is zero and 1 when it is nonzero. Established.
- `crime_resync_sched` (`crime.a(crime.o)`, address `0x59c0`, 32 bytes): stores `a2` at byte 28 and `a1` at byte 24 of the
  64-byte entry of `crimeBoards` indexed by `a0` (`crimeBoards` plus `a0` times 64), and returns 0. Established.
- `crimeFifoWaitTimeout` (`crime.a(crime.o)`, address `0x2b34`, 96 bytes): reports through `cmn_err` at level 4, calls
  `crime_intr_disable` with 25, and writes 1 to the word at byte 548 of `a0` before it raises the level with `splhi`. It
  then calls `sv_signal` on the address of byte 556 of `a0` and restores the level with `splx`, returning the `splx`
  result. Established.
- `crm_makecurrentpbuf` (`crime.a(crime.o)`, address `0x38fc`, 76 bytes): calls `crmAllocPbufTiles` with the word at byte
  24 of `a1` as the first argument and the word at byte 36 ANDed with 8 as the second. A nonzero result makes it return 12.
  Otherwise it sets bit 2 of the word at byte 36 of `a1` and returns 0. Established.
- `crime_regmatch` (`crime.a(crime.o)`, address `0x5848`, 84 bytes): when `a0` is nonzero it calls `crimeUnMapGfx`
  and clears the word at byte 40 of `a0`. If the word at byte 28 of `a0` is nonzero it destroys that handle with
  `ddv_destroy_handle` and clears byte 28. It then stores `a1` at byte 28 of `a2` in the return delay slot and returns
  `a2`. The store happens on every path. Established.
- `crimeClosePbuf` (`crime.a(crime.o)`, address `0x385c`, 160 bytes): calls `mutex_lock` on `crm_drawlock` with 25 as the
  second argument, finds the record for the word at byte 0 of `a1` with `crm_mapcliptodraw`, and unlocks. A null record
  returns 22. When the word at byte 40 of the record is zero it calls `crm_destroydrawable` on the record, unlocks and
  returns 0. Otherwise it sets bit 5 of the word at byte 36 of the record, unlocks, calls `RRM_CheckValidFault` on the
  word at byte 0 of `a0`, and returns 4 on a nonzero result or 0 on zero. Established.
- `crmIdleWait` (`crime.a(crime.o)`, address `0x2dbc`, 152 bytes): polls the word at offset 16384 of `a0` for up to `a1`
  passes. A pass ends the loop when bit 28 is set and the seven bits 24 to 18 are zero. Otherwise it calls `us_delay` with
  1 and counts down. It returns 0 when a pass saw the condition. When the count runs out it reports through `cmn_err`
  at level 4 with the original `a1` as the third argument, and returns 1. Established.

### Interrupt and bus routines (`kernel.o`)

- `crime_intr_enable` (`kernel.o`, address `0xa248`, 64 bytes): sets bit `a0` of the 64-bit word at address
  `-23880(zero)` under `spl7`, then restores the level with `splx`. The word is written before the `splx` call.
  Established. The routine touches only that one doubleword and no other level's entry.
- `crime_intr_disable` (`kernel.o`, address `0xa288`, 68 bytes): clears bit `a0` of the same word under `spl7`, with the
  same write before `splx`. Established.
- `__sysad_wbflush` (`kernel.o`, address `0x13e0`, 16 bytes): executes `sync`, then loads the 64-bit word at
  `0xb4000000`, the CRIME identification register, and returns it in v0. Established for the instructions. Inferred:
  the load is the read that completes outstanding uncached writes.
- `ecc_disable` (`kernel.o`, address `0x9260`, 12 bytes): stores a 64-bit zero to address 0xb4000200, which is the
  CRIME register at offset 0x200. Established.

### Serial and EDID routines (`crime_i2c.o`, `crime_init.o`)

- `i2_start_addr` (`crime.a(crime_i2c.o)`, address `0x1bec`, 76 bytes): calls `i2_start` and then `i2_sendbyte`, each
  with the caller's `a0`, `a1` and `a2`. Its return values are 0 and 1: it returns 1 when `i2_sendbyte` returns any
  nonzero value, and 0 when it returns 0. Established.
- `i2cfp_SetBit` (`crime.a(crime_i2c.o)`, address `0x410c`, 76 bytes): calls `i2cfp_PortWrite` with the caller's `a0`,
  port `0x70` and the value `0xef` when `a1` is nonzero or `0xe7` when it is zero. The two values differ only in bit 3,
  so bit 3 is set or cleared. It stores 1 or 0 to the small-data word at gp offset -30708 before the call, and returns
  what `i2cfp_PortWrite` returns. Established.
- `crime_EdidCksum` (`crime.a(crime_i2c.o)`, address `0x70c`, 76 bytes): sums the 128 bytes at `a0` with 8-bit
  wraparound and returns the low byte of the sum. Established.
- `sgiEdid` (`crime.a(crime_i2c.o)`, address `0x7e8`, 56 bytes): returns 1 when byte 8 of the block at `a0` is `0x4c` and
  byte 9 is `0xf8` or `0xe9`, otherwise 0. Established for the tests. Inferred: bytes 8 and 9 are the manufacturer
  identifier of the public EDID layout.
- `crimeProbe` (`crime.a(crime_init.o)`, address `0x44`, 68 bytes): reads the 64-bit word at address 0xb4000000 and
  keeps its low byte. It returns 0 for `0xa0` and for any byte whose high nibble is not `0xa`, and 1 for the other bytes whose high
  nibble is `0xa`, which are `0xa1` to `0xaf`. Established.

### Tile bookkeeping (`crime.a(crime_db.o)`)

Both routines take a tile record in `a0`. The word at +8 of the record points to a table of 16-bit entries, one per
tile index, and the word at +4 counts the tiles the record holds.

- `crmAddBackTiles` (`crime.a(crime_db.o)`, address `0x0`, 252 bytes): with a count of zero it skips the allocation and
  only does the counter update. Otherwise it fills a stack buffer of 16-bit values through `crmAllocTiles`, with the
  count, the word at +12 of the record and 3 as its arguments, and returns 1 when that call is nonzero. On success it
  adds the count to the two 16-bit counters at `crm_tileusage`+2 and +6. For each of the count bytes at `a2`, it
  stores the next buffer value at the table entry the byte indexes. It then adds the count to the word at +4 of the
  record, stores the return of `crmNextIncarnation` at +16, and returns 0. Established for the sequence. Inferred: the
  table holds the per-tile state and the byte array holds the tile indices being returned.
- `crmSubtractBackTiles` (`crime.a(crime_db.o)`, address `0xfc`, 220 bytes): allocates a buffer of two bytes per
  requested tile with `kern_malloc`. For each byte at `a2` it reads the table entry that byte indexes; a nonzero entry
  is copied into the buffer, cleared in the table, and counted. When that number is nonzero it subtracts it from
  the word at +4 of the record, calls `crmNextIncarnation`, and calls `crmFreeTiles` with the buffer, the number, the
  word at +12 and the byte at +21 of the record. The return of `crmFreeTiles` goes to +16. It frees the buffer with
  `kern_free` and returns whatever `kern_free` leaves in v0. Established for the sequence. Inferred: the routine gives
  back the tiles that a previous add took, the inverse of `crmAddBackTiles`.

## Open

See [docs/open-questions.md](../../docs/open-questions.md): the identification upper word, the status register location on
CRIME 1.5, the write-error questions above, the unreached registers (refresh counter, replacement select, JUICE field,
watchdog), the PROM's indexed sizing loops (the census records only the bases) and the diagnostic's stripped CRIME
routines (the census names them by address only).
