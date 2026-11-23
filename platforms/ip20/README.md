# Indigo R4000 (IP20)

The R4000 Indigo workstation: the processor board, its memory, its slots and the pages that describe them. IP20 is the board; the
R3000 Indigo is IP12 and shares only some chips (see the [MC page](../../devices/mc/README.md#ip12-r3000-indigo)).

Pages for this board:

- [address-map.md](address-map.md): physical map, and the order in which the PROM programs the MC.
- [interrupts.md](interrupts.md): which device drives which INT2 bit.
- [gio.md](gio.md): GIO32 slots, product-ID probing, graphics-board probes, arbitration.
- [prom-software.md](prom-software.md): what PROM 4.0.5D (and the changes in 4.0.5G) does.
- Chips on the board: [MC](../../devices/mc/README.md), [INT2](../../devices/int2/README.md), [HPC1](../../devices/hpc1/README.md),
  [WD33C93](../../devices/wd33c93/README.md), [DP8573A clock](../../devices/dp8573a/README.md).

## Board facts

Labels follow [AGENTS.md](../../AGENTS.md). Sources: *R4000 manual* is the MIPS R4000 Microprocessor User's Manual, second edition
(page numbers are the manual's own); *Owner's Guide* is IRIS Indigo Workstation Owner's Guide 007-9065-050; *MC spec* is the MC chip
specification, revision 1.15; *IRIX source* is the public tree; *PROM* is 4.0.5D `070-8116-004`, listing addresses (4.0.5G `070-8116-005` where marked); *hinv captures* are four published `hinv` listings of R4000 Indigos (two with a
100 MHz R4000, two with a 150 MHz R4400); *Usenet* posts are cited by message-id.

### Processor

| Fact | Value | Grade, source |
|---|---|---|
| CPU on the base board | MIPS **R4000 with a secondary cache** (R4000SC), on a replaceable module on the CPU board; later modules carry an R4400 (same board, same PROM family). | **established**: Owner's Guide p. 144 onward ("the CPU module is the large elevated module"; on the R4000 family only the module is replaced) and pp. 175–176 (declared models "R4000 50 MHz processor", "R4400 75 MHz processor"); every held `hinv` capture shows a secondary cache. The no-secondary-cache variant (R4000PC) is not shown by any source: **unknown** that one shipped. Firmware does handle it (see Caches). |
| Chip revisions seen | R4000 revision 2.2 and 3.0 (FPU "R4010", revision 0.0); R4400 revision 5.0. | **observed**, `hinv` captures. The kernel keeps a jump workaround below revision 3 (`irix/kern/ml/IP20.c`, established). |
| MasterClock | **50 MHz** on the R4000 module; 75 MHz on the 150 MHz R4400 module. | **established** for the 50 MHz R4000 (Owner's Guide p. 176; the PROM's measured-clock table has 50 MHz; kernel comment "50MHZ R4000": 20 timer ticks per 1024 instructions, `irix/kern/ml/delay.c`); 75 MHz for the R4400: **established** from the Owner's Guide model name and `hinv` ("150 MHZ"). |
| PClock (internal) | MasterClock × 2: **100 MHz** (R4000), 150 MHz (R4400). | **established**: R4000 manual p. 229 ("PClock at twice the frequency of MasterClock"); IRIX doubles the measured master clock for R4000 to report the rating (`cpu_mhz_rating`, `delay.c`; the hinv inventory call uses `2 * cpufreq`, `IP20.c`). `hinv` shows "100 MHZ IP20" and "150 MHZ IP20". |
| System-interface (SysAD) clock | **50 MHz** = PClock ÷ 2 on the 100 MHz R4000 (`Config.EC` = 0). For the R4400 at 150 MHz the MC stays at 50 MHz, so `Config.EC` = 1 (÷ 3). | the MC's clock is **established** at 50 MHz (MC spec 5.13, p. 33: CPU memory timing counts "20 ns" clocks; PROM source comment "100ns counter for 50Mhz MC" in `IP20prom/csu.s`; the RPSS divider `0x0104` is a 100 ns tick at that rate). The divisor values are **inferred**: the divisor field is boot-mode strapping (R4000 manual p. 91, Table 4-12) that no Indigo firmware reads. |
| How the PROM measures the speed | Times 1024 instructions against the 1 MHz 8254 counter, retries up to ten times, rounds to a table of master clocks (8, 12, 16, 20, 25, 30, 33, 36, 40, 50, 66, 75 MHz at `0xbfc53d80`) and falls back to 75 MHz when the tick count is outside 20 to 400, printing "Can't determine CPU speed". Stored as the `cpufreq` variable that `hinv` reads. | **established**: PROM `0xbfc2b7e0` (table `0xbfc53d80`, fallback word `0xbfc53dac`); public `stand/arcs/lib/libsk/ml/freq.c` (4.0.5G has the same table at `0xbfc5ac30`, with 67 MHz in place of 66 MHz). A model must make 1024 instructions take about 20 timer microseconds for the 50 MHz result, or the 75 MHz fallback shows. The 150 MHz R4400 would run 1024 instructions in about 14 µs, below the 4.0.5D lower limit, so the fallback gives the right answer there by accident: **inferred**. |

### Caches

| Fact | Value | Grade, source |
|---|---|---|
| Primary caches | **8 KiB instruction + 8 KiB data** on the R4000; 16 KiB each on the R4400. | **established**: R4000 manual p. 6 and p. 92, Table 4-12 (`IC`, `DC` fields); `hinv` captures; the PROM computes the sizes from `Config` (`0xbfc07564`, `0xbfc07594`; [PROM page](prom-software.md#caches-established)). |
| Primary line size | 16 bytes assumed by the PROM (mask 15); `Config.IB` and `DB` are boot-mode strapping selecting 16 or 32 bytes. The kernel reads them (`irix/kern/ml/error.c`, `get_config() & CONFIG_IB`). | PROM use **established**; the strapped value on the Indigo module **unknown**: the PROM would have mis-set lines on a 32-byte module, so 16 is **inferred**. |
| Secondary cache | **1 MiB, unified** (`Config.SS` = joint), one per CPU. | **observed**, `hinv` captures ("Secondary unified instruction/data cache size: 1 Mbyte"); firmware sizes it, so the size is read, not fixed: the PROM tries 64 KiB doubling to 4 MiB by tag test (`0xbfc07660`, [PROM page](prom-software.md#caches-established)); the R4000 allows 128 KiB to 4 MiB (manual p. 33). |
| No secondary cache | `Config.SC` (bit 17) = 1. The PROM returns 0 and prints " no S-cache"; the kernel tests the same bit. | **established** (`0xbfc07660`, `irix/kern/ml/error.c`); whether any Indigo shipped without: **unknown**. |
| Secondary line size | Strapped in `Config.SB` (4, 8, 16 or 32 words). The PROM starts from 128 bytes and sets the MC high-water mark from the value read (`cpuctrl0.mc_hwm` formula on the [MC page](../../devices/mc/README.md)). | **unknown** for the Indigo module; no held capture shows `cpuctrl0` or `Config` after reset. Route: a PROM-console or `hinv -v` print of the cache line, or the module's data sheet. |

### Memory

| Fact | Value | Grade, source |
|---|---|---|
| Layout | **Three** banks, each four identical SIMMs; 12 sockets in three groups labelled A, B and C, SIMMs numbered S1 to S4 in each. MC bank 0 is group C, bank 1 is group B, bank 2 is group A; the MC's fourth bank is not wired to a socket. | **established** for three groups and their order: Owner's Guide p. 45 ("room for up to 12 SIMMs", groups A, B, C, "at least four SIMMs ... S1A, S2A, S3A, S4A", "four of the same type into each group"); IRIX `log_perr` has three table rows (bank 0 → `S1C S3C S2C S4C`, bank 1 → group B, bank 2 → group A); the PROM's failed-SIMM report loop runs three times with letter `'C' - bank` (`0xbfc032d4` sets `'C'`, `0xbfc032dc` bound 3, `0xbfc03288` routine); the PROM message "No usable memory found. Make sure you have a full bank (4 SIMMs)". The MC supports four ([MC](../../devices/mc/README.md)); the PROM still probes bank 3 (loop bound 4 at `0xbfc00ac4`) and finds nothing: **inferred**. This corrects the "four banks" wording in the address map. |
| SIMM lane to socket | The four 32-bit lanes of a 128-bit line map to sockets as lane 0 → S1, lane 1 → S3, lane 2 → S2, lane 3 → S4. | **established**: kernel `log_perr` table order and the PROM's report (flag `0x8000` → S1, `0x4000` → S3, `0x2000` → S2, `0x1000` → S4 at `0xbfc03314`–`0xbfc03378`; the flags are the lane tests on the [MC page](../../devices/mc/README.md)). |
| SIMM type | 72-pin, 36 bits wide (32 data + 4 parity), fast page mode, 60 or 70 ns; not interchangeable with the R3000 Indigo's SIMMs. EDO unsupported. | Owner's Guide p. 41 (the two families use different SIMMs); the rest from Usenet `7e37t2$lev$1@canopus.cc.umanitoba.ca`: **inferred** (a user's statement); the MC spec (p. 16) names 36-bit SIMMs and asks for 80 ns DRAM for the chip's family. |
| Sizes per bank | 4, 8, 16, 32, 64 or 128 MiB, from four SIMMs of 256K×36, 512K×36, 1M×36, 2M×36, 4M×36 or 8M×36 (1, 2, 4, 8, 16 or 32 MB each). The PROM and kernel accept exactly these (size codes 0 to 31, `mc.h`). | **established** for the encoding (MC spec 5.12, p. 32; PROM sizing; `mc.h`); which SIMM sizes SGI shipped for the Indigo: **inferred**. Usenet reports 4 MB SIMMs (16 MiB bank) as the base fit and 32 MB SIMMs (128 MiB bank) as the largest (`6235ua$m17$1@jura.cc.ic.ac.uk`, `7e37t2$lev$1@canopus.cc.umanitoba.ca`). The `hinv` captures show 96, 128, 224 and 256 MB: all sums of the sizes above. |
| Rules | A bank is four SIMMs of one size; banks may differ. Larger banks go at lower addresses; a bank's base must be a multiple of its size. The PROM sorts and programs this. | **established**: MC spec 5.12 (p. 32–33); PROM placement at `0xbfc00f64` ([MC page](../../devices/mc/README.md#memory-sizing-and-the-bank-registers-established)). |
| Minimum | One full bank: **4 MiB** by the MC and PROM; 16 MiB base configuration reported on a shipped board. | 4 MiB **established** (MC spec p. 16 "minimum system is four 256Kx36 simms"); the 16 MB base configuration is Usenet `6235ua$m17$1@jura.cc.ic.ac.uk`: **observed**, one report. A sensible default for a model is 32 MiB (one 32 MiB bank is not a shipped fit by any source; two banks of 16 MiB are): **unknown**, a choice. |
| Maximum | **384 MiB** (three banks of 128 MiB). 256 MiB at the low window plus up to 128 MiB at the high window; IRIX caps the high window at 128 MiB (`mc.h`, `SEG1_SIZE`). | **established**: IRIX `mc.h` and `IP20.c` (`szmem`); the PROM 4.0.5D fails with 384 MiB, 4.0.5G does not (the [address map](address-map.md) and MC page, Usenet `3DF1F502.D82C6820@machtnix.net`); Usenet `7e37t2$lev$1@canopus.cc.umanitoba.ca`. The MC specification's 512 MiB (four banks) is the chip's limit, not the board's. |
| Parity | Parity checked on every word; reporting enabled by the PROM and kernel only from board revision 2 up (the [MC page](../../devices/mc/README.md#indigo-against-indy-and-indigo2)). | **established**. |

### What this changes in a model

- Offer three SIMM groups, not four; a four-bank layout makes the PROM probe an empty bank 3, which a model must answer as "no SIMM
  responds" for the lane test, as the [MC page](../../devices/mc/README.md#sizing-memory-exactly-as-the-prom-expects-a-model-checklist)
  already requires of an empty bank.
- Report 8 KiB primary caches, a 1 MiB joint secondary cache, `Config.SC` = 0 for an R4000SC; PRId revision 2.2 or 3.0.
- The 8254 counter that the PROM times against must run at 1 MHz, and 1024 instructions must take about 20 ticks, or the PROM prints
  the wrong speed (75 MHz fallback) without failing.

## Open

[questions/ip20-gio.md](../../questions/ip20-gio.md), [questions/ip20-mc.md](../../questions/ip20-mc.md),
[questions/ip20-prom-software.md](../../questions/ip20-prom-software.md); the board-fact unknowns above (secondary line size,
whether an R4000PC shipped, the strapped primary line size) are listed in [questions/ip20-gio.md](../../questions/ip20-gio.md).
