# O2 PROM and the R5000: which Config bits the firmware reads, writes and assumes

The O2 (IP32) system PROM reads the R5000's cache-size and secondary-cache Config fields, writes only K0 and SE, and
measures the CPU clock against the CRIME timer instead of reading EC or EP. This page records how far the PROM depends
on the R5000's reset-time Config fields, how it finds the clock and what it does differently from the R10000 path.
Everything here is read from shipped flash images. No R5000 hardware, no boot capture and no emulator run was used.
Findings about the IRIX 6.5.30 kernel on the same CPU are in the crime workspace
(`software/kernel/r5000.md`); this page is the firmware half.

Images. All 18 IP32 images in the public PROM catalogue were fetched and their sha256 values matched the catalogue
(2.3, 3.3, 4.0, 4.3, 4.4, 4.7, 4.8, 4.9, 4.10, 4.11 twice, 4.12, 4.13, 4.14, 4.15, 4.16, 4.17, 4.18; list in
[../../references/prom-images.md](../../references/prom-images.md)). Versions 4.8 and 4.18 were read routine by routine.
The other sixteen were surveyed only for the signs named below (segment layout, which CPU numbers the first stage
compares, the number of Config writes per stage, and the CPU clock table), so a statement about them is **inferred**.
Addresses are 4.18 unless a version is named. `0xbfc0xxxx` is the flash address of the first stage and `post1`;
`0x81xxxxxx` is the run-time address of the `firmware` segment ([prom-software.md](prom-software.md) has the layout).
Config bit numbers follow the R5000 layout; PRId is the CP0 PRId register, implementation byte in bits 15:8
(`0x23` R5000, `0x28` RM52xx, `0x27` RM7000, `0x09`/`0x0e` R10000/R12000).

Grades: **established** (the whole routine read), **inferred**, **unknown**.

## Short answer

- EC (bits 30:28) and EP (bits 27:24): **established** that no code on the R5000 route of either PROM version reads
  them. The only Config fields the R5000 route masks out are the primary cache sizes and line sizes, SC, SS and (to
  clear or set) SE and K0. The one raw copy of Config in the firmware is a diagnostic save into an exception frame
  (`0x810179d8`) that is not interpreted. EC and EP are therefore inputs that nothing in the firmware checks. The CPU
  clock is measured, not derived from Config.
- The firmware writes Config in exactly two ways on an R5000: it forces K0 to 3, and it clears SE before touching the
  caches (and the POST secondary-cache test sets then clears it). Nothing else in Config is written.
- Count is assumed to run at half the pipeline clock when the PROM prints the CPU speed. The PROM measures the Count
  rate against the CRIME timer and prints twice that.

## Where the PROM reads Config on the R5000 route

| Field | Code | Use | Grade |
|---|---|---|---|
| K0, bits 2:0 | first stage `0xbfc0063c` | read-modify-write, see the write table | established |
| IC, bits 11:9 | first stage `0xbfc01b40`; `post1` `0xbfc068d0`; firmware read `0x8100578c`, extraction `0x81005b14` (4.8: `0x8100557c`) | I-cache size is `0x1000 << IC`: index-invalidate loop bound in the first stage, size variable in the firmware | established |
| DC, bits 8:6 | first stage `0xbfc01b70`; `post1` `0xbfc06900`; firmware `0x81005b50` | D-cache size is `0x1000 << DC`: tag-clear loop bound, size variable | established |
| IB, bit 5 / DB, bit 4 | firmware `0x81005b2c`, `0x81005b68` | primary line is 32 bytes when the bit is set, 16 when clear; also the line masks | established |
| SC, bit 17 | firmware `0x810057c4` | set means no secondary cache: sizes stay 0 and the secondary-cache variables are not written | established |
| SS, bits 21:20 | firmware `0x810057d4` | secondary size is `0x80000 << SS`; a value above 2 is treated as no secondary cache | established |
| SE, bit 12 | first stage `0xbfc01b30`; `post1` `0xbfc068c0`, POST test near `0xbfc08384` | read to be cleared; the POST test reads SC then sets SE | established |
| whole word | exception-frame save `0x810179d8` | stored for display, not decoded | established |

Not read on the R5000 route, by this search of every Config read site in 4.8 and 4.18: EC, EP, the secondary line size
bit (SB, bit 13), bit 15 (BE), bits 23:22 and the reserved bits. The R5000 firmware path hard-codes a 32-byte secondary
line (`0x81005804`). The R10000 path of the same routines does read bit 13 (secondary line size) and the fields at
31:26, but it is chosen by PRId and never runs on an R5000. The routines are `0x810062b0` (R10000/R12000) and the
first-stage `0xbfc009c0` branch.

## Where the PROM writes Config

| Writer | Address (4.18) | Field and value | When | Grade |
|---|---|---|---|---|
| first stage, reset path | `0xbfc0063c` read, `0xbfc00650` write | K0 := 3; other bits kept | every CPU, before any cache or RAM use | established (4.8 and 4.18); inferred for the sixteen other images, which show the same first-stage Config write count (two before 4.14, three from 4.14) |
| first stage, cache and TLB initialiser (`0xbfc019b0`, called at `0xbfc006d4`) | `0xbfc01b3c` (4.8: `0xbfc019e4`) | SE := 0 | PRId `0x23` or `0x28`; in 4.8 and earlier every CPU except `0x09` | established |
| same, RM7000 branch | `0xbfc01a64` | SE := 0 and bit 3 := 0 | PRId `0x27` only (4.14 and later) | established |
| `post1` copy of the same initialiser | `0xbfc068cc`, `0xbfc067f4` | as above | when the POST code re-runs the cache initialiser | established |
| `post1` POST secondary-cache test | near `0xbfc08394` to `0xbfc083a8` | SE := 1 if SC is clear, test, then SE := 0 | during POST | inferred (reading of the call shape; the test body at `0xbfc08398` was not followed) |
| `post1`, just before it jumps into the firmware | `0xbfc0462c` read, `0xbfc04644` write | K0 := 3 again | every CPU, after the firmware segment checksum passes | established |
| firmware | none on the R5000 route | | | established for 4.18 and 4.8 |

General Config accessors exist in `post1` (setter `0xbfc0712c`) and the firmware (setter `0x81004df0`, getters
`0x81004de0` and `0x81022ba8`; 4.8: `0x81004bf0` and `0x81004c00`). No direct call or data pointer to the setters was
found, so they look unused (**inferred**). The RM7000 initialiser
(`0x81006b0c`) has its own three Config writes, but it runs only on PRId `0x27`.

Result: the R5000 leaves the PROM with K0 = 3, SE = 0 and every other Config bit exactly as the reset input supplied
it. IRIX turns SE on later (see the kernel page). A model that makes only K0 and SE writable (mask `0x1007`) loses
nothing the PROM does.

## What else the reset path does on an R5000 (4.18; 4.8 is the same except for the CPU test)

- Status is set to `0x34410080` (CU0, CU1, FR, DE, BEV and KX) at `0xbfc0062c`, then Cause, PageMask, WatchLo and
  WatchHi are zeroed (`0xbfc00654`..`0xbfc00660`). **Established.**
- TLB: the initialiser at `0xbfc019b0` writes indices 47 down to 1 (not index 0) with a distinct kseg0 virtual page
  pair per entry, PageMask 0 and EntryLo values with the valid bit clear. The other branch writes 63. **Established**
  for 4.18: PRId `0x23`, `0x27` and `0x28` get 48 entries and every other value gets 63 (the R10000 shape). In 4.8
  PRId `0x09` gets 63 and everything else gets 48.
- Primary caches: I-cache by Index Invalidate over the whole size from IC, D-cache by Index Store Tag over the whole
  size from DC with the state field clear. The secondary cache is not touched, because SE was just cleared.
  **Established.**
- Cache used as RAM (`0xbfc008f0`..`0xbfc00a58`): on `0x23` and `0x28` only (4.8: any CPU but `0x09`) the first stage
  clears TagHi, then for each 32-byte line of the 4 KiB at `0x80000000` writes an Index Store Tag on the D-cache with
  TagLo = address-derived tag (zero for this range) | `0xc0`, that is state 3. The stack is then at `0x80001000`
  and the 4 KiB is filled with a pattern. The R10000 path instead writes secondary-cache tags first and a second
  primary-tag pass. **Established.** The model's cached-RAM-before-DRAM behaviour therefore needs only D-cache tags
  to be writable and hit for physical `0x0`..`0xfff` at kseg0 with state 3. What the state bits mean in hardware is
  **inferred** (R4000-style dirty exclusive).
- Firmware entry: PRId `0x23` goes to `0x81005770`, which reads Config once (`0x8100578c`), fills the cache-size
  variables, and registers its cache-flush routines in the table at `0x810600c8`. PRId `0x28` is first rewritten to
  `0x23` by the PRId reader at `0x81004e04` (4.8 has the reader at `0x81004c14`), so the firmware sees one R5000-class number. **Established.**
- Cache operations on the R5000 route, encoded as the CACHE instruction's 5-bit field: the firmware's routines
  (`0x810058a0`, `0x81005950`, `0x81005a40`) use Index Invalidate I (`0x00`), Index Writeback Invalidate D (`0x01`) and
  S (`0x03`), and Index Load Tag D (`0x05`, to probe whether a line is present). The first stage and `post1` initialiser
  use `0x00` and Index Store Tag D (`0x09`). The hit-style writeback-invalidate operations (`0x15`, `0x17`) in the
  `post1` line flusher at `0xbfc050bc` are skipped for `0x23`, `0x27` and `0x28`. No flash-invalidate, hit-invalidate or
  page-invalidate operation appears on the R5000 route. **Established** for 4.18.
- Memory-size state, `0x81003cec`: independent of the CPU. **Established** (no PRId read on that path).

## Finding the CPU clock

Established in the 4.18 firmware (`0x81004f40` measures, `0x81003208` converts, `0x81003314` prints). 4.8 holds the
same constants (`0x5bc8` and 66 666 500) and a shorter table; its routine was found by constant search, not read
end to end (**inferred**):

1. Write Count with 0 and the CRIME timer (`0x14000038`) with 0.
2. Poll the low 32 bits of the CRIME timer until it reaches 23 496 (`0x5bc8`) ticks, then read Count.
3. Repeat four times and average both numbers.
4. Count rate = Count average multiplied by (66 666 500 divided by the CRIME tick average). The constant `66 666 500`
   is the CRIME timer rate the PROM assumes.
5. Round to the nearest value in a built-in table of nominal Count rates. A measured value more than about 4 MHz above
   the table's last entry is used unrounded.
6. Print twice the rounded Count rate in MHz (`0x81003344` formats with a doubled argument).

So the PROM's only assumption about Count is that the pipeline clock is twice its rate, for every CPU. **Established.**
There is no Config-based path: EC is not consulted. The table grows by release: 2.3 to 4.0 end at 120 MHz, 4.3 and 4.4
add one entry, 4.7 and 4.8 end at 137.5 MHz, 4.9 to 4.13 at 225 MHz, 4.14 to 4.16 at 250.565 MHz and 4.17 and 4.18 at
501.13 MHz (**inferred** from the entry counts for the sixteen unread images). Every version's table contains 87.37,
90, 97.5 and 100 MHz, so a nominal 100 MHz Count (200 MHz R5000) rounds to exactly 100 000 000 in all of them.

The PROM also appears to keep its own elapsed-time counter from Count at that rate (`0x81003360` reads Count and
accumulates against the stored rate; **inferred**), so a Count that does not match the CRIME timer ratio would skew the
firmware's delays.

## Which versions carry R5000 support, and RAM

- **Banner text** (the version string in each image): 2.3, 3.3, 4.0, 4.3, 4.4 and 4.7 name R4600, R5000 and R10000;
  4.8 to 4.16 name R5000 and R10000; 4.17 and 4.18 name R5K, R7K, R10K and R12K. The banner is a label, not behaviour.
- **First-stage CPU tests** (surveyed for all 18, read in 4.8 and 4.18): 2.3 to 4.8 test only for `0x09`, so any other
  CPU, R5000 included, takes the non-R10000 route. 4.9 and 4.10 test for `0x23`; 4.11 to 4.13 for `0x23` and `0x28`;
  4.14 to 4.18 for `0x23`, `0x27` and `0x28`. **Inferred** for the unread images.
- The firmware CPU-init dispatch (`0x810040c0` in 4.18) prints "Not supported CPU type" and asserts for PRId values it
  has no routine for. The R5000 (`0x23`) has a routine in every version read.
- **RAM:** the memory sizing (CRIME bank registers, see [prom-software.md](prom-software.md)) and the memory
  descriptors contain no CPU test, and no PRId read sits on those paths in 4.8 or 4.18. Nothing in the firmware
  refuses or special-cases an R5000 for any RAM size. Bank 0 must hold a module (the "no SIMM in bank0" error).
  **Established** for 4.8 and 4.18.

## Unknown or not read

- `post1` `0xbfc07050` returns `0x30` for PRId `0x23` and `0x23` otherwise. The caller and the meaning were not
  traced. **Unknown.**
- The body of the POST secondary-cache test and what its pass or fail does. **Unknown.**
- The sixteen other images were not read routine by routine. Differences in the R5000 routine bodies between 4.8 and
  4.18 were not diffed beyond the points above.
- Whether the reset-time Config EC and EP are set by the module's mode stream and what values factory modules carry:
  no shipped software reads them, so no PROM or kernel read can settle it. Routes tried: every Config read site in
  4.8 and 4.18 first stage, `post1` and firmware; the IRIX 6.5.30 kernel objects (crime workspace). **Unknown: no
  shipped software depends on it.**
