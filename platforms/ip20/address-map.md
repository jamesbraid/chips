# Indigo R4000 (IP20) physical address map and the PROM's MC set-up

The physical address space of the Indigo R4000 board as the MC chip decodes it, with each region's contents and grade, then the
order in which the PROM 4.0.5D programs the MC. The MC registers themselves are in [devices/mc](../../devices/mc/README.md); what
else the PROM does is on [the PROM software page](prom-software.md). The interrupt controller whose six lines the MC forwards to the CPU is [INT2](../../devices/int2/README.md); which
device drives which bit is [the interrupt routing table](interrupts.md).

Grades follow [AGENTS.md](../../AGENTS.md): **established** (public IRIX source tree, shipped IRIX header, or the MC specification, and
the PROM listing agrees), **inferred**, **unknown**. Sources are named per row: *map* is the MC specification's physical map
(section 4); *IRIX* is the public tree's `irix/kern/sys/IP20.h`, `mc.h` and `IP20addrs.h` (the same text ships as headers with IRIX
6.5); *NetBSD* is `sys/arch/sgimips/gio/gio.c` (a public driver, used here only to confirm probe addresses).

All physical addresses below are 32 bits. Kernel segments: kseg0 is `0x80000000` plus the address and kseg1 `0xa0000000` plus the
address, for any address below `0x20000000`. Memory from `0x20000000` up cannot be reached through kseg0 or kseg1; IRIX maps it
(`lmem_conf.s` comment, `established`).

## The map

| Physical range | Size | Contents | Grade, source |
|---|---|---|---|
| `0x00000000`–`0x0007ffff` | 512 KiB | Alias of the first 512 KiB of main memory at `0x08000000`, for the CPU exception vectors at physical 0 and 0x80. | **established**, map and IRIX (the header says memory from 0 to 512K is aliased at 0 and at 128 MiB). The PROM relies on it (exception stubs at `0x80000000`, `0xbfc08b28`; ARC block at `0xa0001000`; see [PROM page](prom-software.md#memory-sizing-and-where-ram-sits-established-unless-marked)). Whether the alias reaches beyond 512 KiB (NT wants RAM to 6 MiB): **unknown**. |
| `0x00080000`–`0x07ffffff` | ~128 MiB | EISA I/O space and EISA memory in the MC's map. The Indigo has no EISA bus. | map: **established** for the chip; for this board **unknown** (what an access returns with no EISA chips present: a bus error or a GIO timeout). Route: a read of a real board, or the MC specification's EISA section. |
| `0x08000000`–`0x17ffffff` | 256 MiB | **Main memory, low window.** Banks are programmed here first, largest first, from `0x08000000`. | **established**: `mc.h` (`SEG0_BASE` and size), PROM placement code `0xbfc00f64`. |
| `0x18000000`–`0x1effffff` | 112 MiB | Reserved: bus error on read, bus-error interrupt on write. | map **established**. A write that runs past the low window raises the GIO error at `0x18000000` (a Usenet report of a 384 MiB board under PROM 4.0.5D shows `GioErrorAddr: 18000000` and `EPC: BFC02F60`, inside the PROM's address test at `0xbfc02f30`, which runs before the memory-clear fill), `inferred` for the cause. |
| `0x1f000000`–`0x1f3fffff` | 4 MiB | **Graphics slot.** The Entry graphics board's registers are probed at `0x1f3f0000` and `0x1f3f8000`; the Express family at the slot base. | extent **established** (`IP20.h`: 4 MiB for graphics, `LIO_ADDR` `0x1f000000`); the probe addresses are NetBSD's. Which board answers where: other pages. |
| `0x1f400000`–`0x1f5fffff` | 2 MiB | **GIO slot 0.** | **established** (IRIX: 6 MiB of GIO slots after the graphics 4 MiB; the specification gives slot 0 2 MiB; NetBSD probes `0x1f400000`). |
| `0x1f600000`–`0x1f9fffff` | 4 MiB | **GIO slot 1** (spec: 4 MiB). IRIX also names a second and third HPC1 at `0x1f980000` and `0x1f900000` ("may not be present"), i.e. inside this slot's range, for GIO cards that carry an HPC1. | slot **established**; HPC1 identities from `IP20.h` names only; whether any real card answers there: **unknown**. |
| `0x1fa00000`–`0x1fafffff` | 1 MiB | **MC registers.** `0x1fa00000` privileged registers, `0x1fa01000` RPSS counter, `0x1fa02000` DMA block, `0x1fa10000` + `n * 0x1000` semaphores, n = 0 to 15. Each register at two addresses, one per byte order. | **established**: map, `mc.h`, PROM. |
| `0x1fb00000`–`0x1fb7ffff` | 512 KiB | Second HPC (`HPC_1_ID_ADDR`, second SCSI channel at `0x1fb00088`), "may not be present". In the MC specification: the `hpc_exp_size_64` window. | names **established** (`IP20.h`, `hpc1.h`); presence on a stock Indigo: **unknown**. |
| `0x1fb80000`–`0x1fbfffff` | 512 KiB | **Primary HPC1 and everything behind its PBUS.** Offsets used by IRIX and the PROM: `+0x088`–`+0x098` SCSI DMA, `+0x0a8`–`+0x0b4` parallel DMA, `+0x0c0` endian byte, `+0x121`/`+0x122` and `+0x125`/`+0x126` WD33C93 address and data, `+0x135`/`+0x136` parallel status, `+0x180`–`+0x1b4` DSP interface, `+0x1bc`/`+0x1bf` serial EEPROM and LED byte, `+0x1c0`–`+0x1e3` interrupt status, mask and port-config bytes (INT2), `+0x1f0` the 8254 timer, `+0xd00`–`+0xd3f` four serial-controller register blocks (the fourth also carries the headphone gain DACs), `+0xe00` the DP8573 clock. | **established** for each name and offset (`IP20.h`, PROM listing); internals belong to the HPC1, INT2 and peripheral pages. The MC treats the whole `0x1fb80000`–`0x1fffffff` span as the first HPC (spec 5.9), so the PROM below is read through the HPC1's bus. |
| `0x1fbd0000` | one word | Board revision; the PROM and kernel read it as `(~word & 0x7000) >> 12`. IRIX calls the region "modem SRAM memory space". | **established** (`IP20.h`, `0xbfc07c38`, `board_rev`). |
| `0x1fbe0000` | 32 K words | DSP memory (32 K words of 24 bits), reached through the HPC1. | **established** (`IP20.h`). |
| `0x1fc00000`–`0x1fffffff` | 4 MiB | **Boot PROM**, seen at `0xbfc00000`. The Indigo PROM is 512 KiB (`0xbfc00000`–`0xbfc7ffff`); what the rest of the window shows: **unknown**. The first word is `j 0xbfc003c0`. Writes bus-error or are ignored depending on `cpuctrl0.prom_wr_en`. | window **established** (map, `R_VEC`); image from [prom-images.md](../../references/prom-images.md). |
| `0x20000000`–`0x2fffffff` | 256 MiB | **Main memory, high window.** Banks continue here after `0x18000000` is skipped; IRIX caps this window at 128 MiB on the Indigo (384 MiB total). Reachable only through mapped addresses. | **established**: `mc.h` (`SEG1_BASE`, 128 MiB), PROM placement. |
| `0x30000000`–`0x7fffffff` | 1.25 GiB | Reserved. | map **established**. |
| `0x80000000`–`0xffffffff` | 2 GiB | EISA memory in the MC's map; no bus on this board. | map; board **unknown**, as for the low EISA range. |

Memory addresses the guest uses with the layout above: the PROM places its working area at `0xa8740000` (physical `0x08740000`, `IP20addrs.h`) with the stack just below `0xa8800000`;
IRIX loads at `0x88002000` (physical `0x08002000`). All `established` from the header and the PROM.

### Memory banks

The MC has four banks, each four identical SIMMs, 36 bits wide with parity, sizes 4 MiB to 128 MiB per bank. The Indigo board wires only three
groups of sockets (A, B, C; 384 MiB at most), see [the board page](README.md#memory). The MC maps a CPU or GIO address to a
bank when the address' bits 29:22 fall in the bank's base and size range; the bank words are `memcfg0` (banks 0 and 1) and `memcfg1`
(banks 2 and 3). The largest SIMMs go lowest and a bank's base must be a multiple of its size. Details and the PROM's probe algorithm:
[devices/mc](../../devices/mc/README.md#memory-sizing-and-the-bank-registers-established). **established**.

If two valid banks overlap, or an address maps to no valid bank, the access bus-errors and `cpu_err_stat.addr` is set (spec 5.12 and 5.15).

## The PROM's MC initialisation sequence

Read from the Indigo PROM 4.0.5D Rev A (`070-8116-004`, listing addresses). The 4.0.5G image (`070-8116-005`) is **not on the host
used for this reading**, so no 4.0.5G address below was re-checked; the earlier whole-image comparison on the
[PROM page](prom-software.md#405g-differences) reports that the reset routine, the sizing and placement code are the same instruction for instruction and only the
memory-clear tail and one new CPUCTRL0 helper differ. Where this page says "4.0.5G" it is that comparison's statement, not a new read.
Every value below is confirmed against the public source of the later PROM (`stand/arcs/IP20prom/csu.s`, `lmem_conf.s`), which
differs in the items listed afterwards.

1. **Reset** `0xbfc003c0`: Status, Cause, PageMask, Watch cleared; Config written `3`; the Config.BE test and the flip
   routine (`0xbfc01320`, only when the CPU came up little-endian) are on the [PROM page](prom-software.md#reset-path-and-the-configbe-test-established).
2. **Clear error status** `0xbfc00424`, `0xbfc0042c`: `cpu_err_stat` and `gio_err_stat` stores of zero. Followed by a read of `cpuctrl0`, which the PROM does after nearly every MC store.
3. **CPU control 0** `0xbfc0048c`: whole-register store, `0x3c002014 | (hwm << 20)`: refresh enabled with a four-count burst field (eight lines),
   interrupts enabled, no parity reporting, watchdog off, graphics held in reset, big-endian, `back2` and `r4k_chk_par_n` set, bus-rate field 3. `hwm` = cache line bytes / 8 + 4.
4. **CPU control 1** `0xbfc004a8`: `0x1016` (`mc_hwm` 6, GIO timeouts on, HPC endianness fixed big-endian).
5. **DRAM timing** `0xbfc004c8`, `0xbfc004dc`: `cpu_memacc` `0x11453433`, `gio_memacc` `0x34332`.
6. **Refresh wait** `0xbfc004e4`–`0xbfc00504`: 625 RPSS-counter (`+0x1004`, not the refresh counter) ticks at the reset 100 ns rate (62.5 µs), the time for eight refresh lines. The
   PROM does not write `rpss_divider`, `ctrld` or the arbitration registers.
7. **HPC and serial set-up**, `0xbfc0089c`, `0xbfc0096c`, `0xbfc008f8`: not MC.
8. **MC data path test** `0xbfc028b0`: refresh off, a walking one through `cpu_memacc`, refresh restored.
9. **Memory sizing** `0xbfc00a00` (the exact word values and access order a model must satisfy are in the [MC page](../../devices/mc/README.md#sizing-memory-exactly-as-the-prom-expects-a-model-checklist)): both bank words ← 0; per bank the probe at `0xbfc00d1c` (four patterns at `0xa8000000`, a 4× growing
   alias test, a sub-bank test at `0xac000000`), `0xbfc00f1c` writes the size word, `0xbfc00f64` places the banks and sums the total
   (`0xbfc010a8`), an address test `0xbfc02b50` and `0xbfc02f30` runs over the whole size, and a failed bank is cleared.
10. **Refresh burst** `0xbfc00544`–`0xbfc005b4`: `cpuctrl0` low nibble ← 2 (four lines) unless some bank is a 4 or 8 MiB (256Kx36, 512Kx36) bank.
11. **Memory clear** `0xbfc00b08`–`0xbfc00bb8`: the DMA fill: `dma_ctl`, `dma_cause` ← 0, `dma_memadr` ← `0x08000000`, `dma_mode` ← `0x5a`,
    `dma_count` and `dma_stride` ← `0x10000`, `dma_size` ← `(total << 1) | 0x8000`, `dma_gio_adrs` ← 0 (starts), poll `dma_run` bit 6, `dma_cause` ← 0.
12. **Cache tag clear** `0xbfc00bbc`–`0xbfc00bf8`: tags zeroed at `0x88100000`, `0x88200000`, `0x88400000` (index store tag) so the secondary-cache probe cannot write dirty lines into the zeroed memory.
13. **Start-up** `0xbfc00848`, then `0xbfc015c0`: writes the BSS marker, saves the sizing results and total at `0xa8740db8`; later the
    console path calls `0xbfc07950` (arbiter times `lb_time` `0x34f`, `cpu_time` `0x2b`; parity enables by board revision) and the graphics probe pulses `cpuctrl0.grr` (`0xbfc03674`, `0xbfc0f5ec`).

### 4.0.5D against 4.0.5G and the source

| Item | 4.0.5D (read) | 4.0.5G | Later source |
|---|---|---|---|
| Memory-clear DMA | One run from `0x08000000` for the full total. A total above 256 MiB crosses `0x18000000` into the reserved region. | First run clamped to 256 MiB, a second at `0x20000000` for the rest (earlier comparison, not re-read) | Same as 4.0.5G |
| Address test length | Whole total (`0xbfc02f30` call at `0xbfc00afc`) | Clamped to 256 MiB (earlier comparison) | Not read |
| `rpss_divider` | Not written (relies on reset `0x0104`) | Not recorded in the comparison | Written `0x0104` |
| Graphics-reset and DMA test code | None | New helper at `0xbfc07cd8` writes `cpuctrl0` (clears `0x40000`, sets or clears `snoop_en`), `dma_ctl` ← `0x2000400d`, zeroes `dma_gio_mask`/`dma_gio_sub` (earlier comparison) | Not read |
| Reset routine, `cpuctrl1`, memory timings, `lb_time`, `cpu_time` | As above | Same values (earlier comparison) | Same |

The helper's message prints "Big Endian" right after clearing bit `0x40000` of `cpuctrl0`. That agrees with the IRIX header and the MC
specification, where bit 18 is the little-endian select and bit 19 the warm reset (the Linux header names bit 17 `LENDIAN` and bit 18 a
memory-destroying warm reset, which ranks below them). The [PROM page](prom-software.md) uses the Linux names in its reset-path and flip-routine
sections; see [questions/ip20-mc.md](../../questions/ip20-mc.md).

## Open

See [questions/ip20-mc.md](../../questions/ip20-mc.md) and [questions/ip20-prom-software.md](../../questions/ip20-prom-software.md).

## Review (2026-11-23)

Independent evidence review of `f2d9873e` (this page and the questions page), with the MC page commits `d6723f08` and `b6b9bf88`. Outcome in brief; the full table is on the [MC page](../../devices/mc/README.md#review-2026-11-23).

- Address map entries checked against the specification's CPU memory map (page 22): confirmed, including the `0x00000000` alias of `0x08000000` (512 KiB), the 256 MiB low window and the 256 MiB high window `0x20000000` to `0x2fffffff`. The specification allows 512 MiB in total; the "384 MiB" cap on the high window comes from the kernel and the PROM does not enforce it (it places four 128 MiB banks to `0x2fffffff`).
- The `0x18000000` row: the Usenet failure at `GioErrorAddr: 18000000` is the PROM's address test, not the memory-clear fill (see the MC page); the row's cause stays `inferred` and now names the address test.
- The PROM's MC set-up order (steps 3 to 6): confirmed against the listing; step 6 reads the RPSS counter, as the page says. The `cpuctrl0` word in step 3 has bits 16 to 19 clear (big-endian).
- The 4.0.5G column is the earlier comparison's statement; the image was not available to this review, so it is unverified.
- The `interrupts.md` page now appears in `platforms/README.md` (index regenerated).
