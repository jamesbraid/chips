# R16000 processor

This page covers the MIPS R16000 as the public sources describe it: the identity word, how printed revisions relate to the raw identity word, the printed FPU and cache lines of the 1.0 GHz and 700 MHz parts, what public software expects of the part, and what is unknown. The identity constants are in [devices/r10000_identity/registers.toml](../r10000_identity/registers.toml), generated to [devices/r10000_identity/registers.md](../r10000_identity/registers.md). The register layouts of the R10000 family are on the other pages linked from [README.md](../../README.md).

Nothing here was read from silicon or from a running machine. No R16000 processor manual is cited, so each claim is either inferred, or a printed line whose meaning for the part is inferred.

## Sources and grades

- Linux at the `references/code/linux` pin (`c339f4010dea`): `arch/mips/include/asm/cpu.h` (line 77, `PRID_IMP_R14000` covers R14K and R16K), `arch/mips/kernel/cpu-probe.c` (lines 1236-1251) and `arch/mips/mm/c-r4k.c` (lines 374-390). Lines checked at that pin. A driver shows what software expects, so its statements about the part are inferred.
- OpenBSD at the `references/code/openbsd` pin (`7011342f6a72`): `sys/arch/sgi/sgi/sginode.c` (lines 262-274, the KLCONFIG CPU record) and `sys/arch/mips64/mips64/cpu.c` (lines 140-142, 195-201 and 312-318, the revision print). The earlier line ranges for commit `9117996` could not be reproduced and are dropped. `sys/arch/mips64/mips64/cache_r10k.c` (lines 19-28 and 60-80) was re-read for the cache claim below. Inferred.
- Printed boot output. The 1.0 GHz Tezro captures are already cited in [questions/ip35-prom-cpu-config-table.md](../../questions/ip35-prom-cpu-config-table.md). A 2009 OpenBSD boot log of a 1 GHz Origin 350 (Miod Vallat's "Origin 350 support" post to sgi@openbsd.org, 11 October 2009, as reproduced in his OpenBSD/sgi story, part 5), and a 700 MHz Origin 350 forum post in nekonomicon thread 16729141, are the other two. All three were read in their retained copies and match the table below, except where noted. A printed line is established as text. What it says about the part is inferred, because firmware may print data that it did not read from the processor.
- SGI, *Origin 350 Server System User's Guide*, 007-4566-001, printed pages 75 and 114-118, lists processor and memory populations for the IP53 compute module. The populations were not extracted here.

## Identity word and printed revisions

- The implementation byte is `0x0f`, shared with the R14000. A revision whose major nibble is 3 or more is an R16000 (Linux `cpu-probe.c` line 1237: `((processor_id >> 4) & 0x0f) > 2`), and the Linux rule is in [devices/r10000_identity/README.md](../r10000_identity/README.md). Established for Linux.
- OpenBSD prints an R16000 with two subtracted from the major revision nibble (`cpu.c` lines 195-201; for the FPU line, `cpu.c` lines 312-318 subtract two only when the CPU and FPU words are equal). Established for OpenBSD at the pin; the meaning for the raw word is inferred from its print code (`R10K_R16000_DISPLAY_MAJOR_OFFSET` in the defs). Under this rule the printed 3.0 of a 1.0 GHz part is raw major nibble 5, so its raw word is `0x0f50`. A printed 2.1 is raw major nibble 4, so its raw word would be `0x0f41`.
- The OpenBSD print takes its CPU and FPU revisions from firmware KLCONFIG records, not from a CP0 or CP1 read. A printed revision therefore shows what firmware wrote to KLCONFIG. Inferred.
- A printed 2.x does not read as an R14000 once the offset is applied. The Linux test on raw `0x0f41` gives major nibble 4, which is an R16000. The R14000 example in [devices/r10000_identity/README.md](../r10000_identity/README.md) (`2.4` reads as R14000) is about raw words only. Do not run a printed revision through that raw test.
- The raw `0x0f50` value for the 1.0 GHz part (`R10K_R16000_PRID_1GHZ`) is inferred. The PROM banner prints `f50` for four processors on a public Tezro capture. The step from that print to a raw PRId read depends on a review of a PROM image that is not public. No raw read on a part exists.

## Printed identity by population

| Population | Printed by | What it prints | Grade |
| --- | --- | --- | --- |
| 1.0 GHz Tezro, node board printed as "IP35 Node Board" (the capture does not print IP59), PROM 6.210 | PROM banner and `hinv -v` | R16000 revision 3.0; banner revision `f50` on four processors; 16 MB secondary cache at 333 MHz, tap 0x15 | Printed line, inferred meaning |
| 1.0 GHz Tezro, same capture | `hinv -v` | FPU named R16010FPC, revision 3.0 | Printed line, inferred meaning |
| 1 GHz Origin 350, OpenBSD boot log of 2009 | OpenBSD attach | R16000 revision 3.0; 32 KiB two-way L1 instruction and data caches; 16 MiB two-way L2; FPU revision 10.11 | Printed line, inferred meaning |
| 700 MHz Origin 350, 8 MiB L2, after a module swap | PROM (forum post, thread 16729141) | R16000 revision 2.1 on four processors | Printed line, inferred meaning |
| 600 MHz Origin 350, 4 MiB L2, original module (same post) | PROM (same post) | Two R16000 processors, revision 2.1 | Printed line, inferred meaning |

The two 1 GHz FPU prints disagree: 10.11 on the OpenBSD Origin 350 and R16010FPC revision 3.0 on the Tezro. Nothing here explains the difference.

The PROM that printed revision 2.1 in the forum post has not been shown to use the OpenBSD decoding. So raw `0x0f41` for the 700 MHz part is a candidate only. The 1.0 GHz values fit the offset rule, but that fit does not prove it.

## What public software expects

- Linux treats implementation `0x0f` parts as MIPS IV, with a 64-entry TLB, an FPU, 32 floating-point registers, counter and watch support, and LL/SC. Inferred. The 64-entry TLB count is the `R10K_R16000_TLB_ENTRIES` constant.
- Linux treats the R16000 secondary cache as inclusive (`c-r4k.c`, lines 374-390). Inferred. No hardware check was made.
- OpenBSD uses the R10000-family cache operations for the R16000. It reads the primary and secondary sizes and the secondary line size from Config0 rather than assuming one board's population. Inferred (`cache_r10k.c` header names the R16000; `Mips10k_ConfigCache`, lines 60-80, derives all three sizes and the L2 line size from Config0).
- SGI's *SpeedShop User's Guide*, 007-3311-011, printed page 61, groups the R12000, R14000 and R16000 in its hardware-counter table (Table 4-3, printed page 61; checked) in its hardware-counter event table. The event numbering is covered in [devices/r14000_perf_counters/README.md](../r14000_perf_counters/README.md).

## Config0 reset words

The 700 MHz, 200 MHz bus, 8 MiB reset word that the IRIX 6.5.30 flash updater holds is the same word as row 10 of the PROM speed table, `0x569cad85`. See [questions/ip35-prom-cpu-config-table.md](../../questions/ip35-prom-cpu-config-table.md). That is a firmware table value. It is not a reset value read from a part, and nothing here shows that reset latches it into Config0. The 1.0 GHz word is unknown, as that page explains.

## Unknown, and what would settle it

- **Raw CP0 PRId and CP1 revision for each population.** Settled by a raw read at reset, before firmware runs, on a part of each population. A printed line does not settle it.
- **Config0 reset latching and writable mask.** Whether reset loads Config0 bits 24:0 from the mode word, as the R12000 manual describes for its own part, is unknown for the R16000. Settled by a reviewed R16000 processor specification, or by a raw Config0 read after cold reset on a part, paired with the board's flash configuration.
- **The 800 MHz print.** One source says an 800 MHz IP53 part prints revision 3.0. Another says 800 MHz prints 2.2. These conflict and are not resolved here. Settled by a printed 800 MHz boot line with its source.
- **The two 1 GHz FPU prints.** 10.11 and R16010 revision 3.0 disagree. Settled by a raw CP1 read, or a boot line for each module that names its firmware.
- **R16000A.** No population here is shown to be an R16000A, and the raw identity of any R16000A is not known. Settled by a processor specification or a printed raw identity.
- **Soft Reset effect on Config0 and WatchLo/WatchHi.** Unknown, as it is for the R14000 in [devices/r14000/README.md](../r14000/README.md). Settled by reading these registers after a soft reset, not after a cold reset, on a part.
- **Differences from the R14000.** Cache diagnostics, exception handling, performance counters and reset differences are not established. The R14000 rules are not carried over to the R16000 without a source for each one.
- **Secondary-cache syndrome field in performance control 0, bits 31:23.** The R12000A manual names it for the R12000A only, and no R16000 record exists here. Settled by an R16000 specification or a fault-injection read on a part. See [devices/r12000a_variant/README.md](../r12000a_variant/README.md).
- **Secondary-cache line size.** Linux reads it from Config for this part, but no printed Config line of an R16000 was checked. Settled by a printed Config line from a part.
- **Which IP53 and IP59 variants the machine accepts.** Settled by the Origin 350 manual pages named above and by inventory captures of processor revision, speed and cache size.
