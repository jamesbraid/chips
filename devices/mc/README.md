# MC memory controller (Indigo R4000, Indy, Indigo2)

Mode: **spec-backed**. The memory and bus controller gate array of the R4000 SGI workstations. It joins the R4000 SysAD bus, the
main-memory SIMMs, the GIO bus (and, on machines that have one, EISA), and holds the CPU control, watchdog, refresh, arbitration,
error-reporting, semaphore and graphics-DMA registers. Registers: [registers.md](registers.md). The machine this page is written for
is the Indigo R4000 board ([address map](../../platforms/ip20/address-map.md), [PROM reading](../../platforms/ip20/prom-software.md));
the Indy and Indigo2 carry the same chip, so differences are stated per item.

Sources, in the repository's evidence order:

1. The public IRIX source tree: the MC header, the Indigo R4000 PROM start-up and memory-configuration code, the Indigo kernel's
   `mlreset`, bank and error code, and the virtual-DMA driver (paths in each section). `established` for what they define.
2. Shipped binaries, which confirm the source against what ran: the Indigo PROM 4.0.5D (listing addresses below) and the IRIX 6.5
   Indigo kernel object (`mlreset`).
3. Public Linux and NetBSD MC headers: used only to confirm.
4. The MC chip specification (R4000 project, revision 1.15; its own change log ends April 1992). Held in the document cache. It
   documents revisions A and B, mentions the Indigo in several register notes, and does not describe the graphics DMA registers (its
   graphics-DMA section points at a separate document that is not held).
5. Notes from other projects (an emulator's MC model) are cited only where they agree or disagree.

## Revision on the Indigo R4000

**Unknown which one.** What is known:

- The specification gives `SYSID` revision A as 0 and revision B as 1, and lists the revision B fixes (section 7). `established`.
- The Indigo kernel treats revision 0 as a special case (no virtual-address translation in the DMA engine; every MC register store
  needs a workaround; older cache-flush path) and warns when the revision is below 3 and large-DRAM SIMMs are installed that it "may
  require the revision C" part. So A is 0, B is 1, and C is at least 3. `established` for the code, `inferred` that C reads exactly 3.
  An emulator's MC model returns 3 and calls it revision C (a note, not evidence).
- Boards in the field carried A, B and C parts. A Usenet report of a 030-8096-004 Rev E board says it "had Rev. C memory controllers"
  and would not boot with 384 MiB under PROM 4.0.5D but would under PROM 4.0.5G
  (`3DF1F502.D82C6820@machtnix.net`, `3EF3585F.DBE9C4C1@machtnix.net`), which is the memory-clear defect described in the PROM
  section below. `inferred`: the chip marking is the poster's, not a register read.
- The Indigo PROM 4.0.5D never reads `SYSID`. Software that does: the kernel's `mlreset` (`mc_rev_level = SYSID & 0xf`,
  confirmed in the IRIX 6.5 Indigo kernel object).
- The Indy and Indigo2 kernels refer to revision levels of 5 and above (a later chip with a 16 MiB memory unit). Not an Indigo part.

For an emulator: model revision C (`SYSID` low nibble 3, EISA bit 0) and keep revision A's write-flush behaviour out. `inferred`.

## Access model

- Every register answers at two word addresses four bytes apart. A big-endian CPU uses the higher; a little-endian CPU the lower
  (the chip is wired to SysAD bits 31:0). Using the wrong one sets the address-error bit of `cpu_err_stat` and bus-errors the
  access. `established` (specification section 5, `cpu_err_stat` bit 10). The offsets in [registers.md](registers.md) are the
  big-endian view. The Indigo PROM's byte-order flip routine uses the lower view.
- MC registers sit in the first two 4 KiB pages of the window; the semaphores are 16 further pages (below) so that user processes can
  map one each; the RPSS counter has its own page; the DMA registers have a page.
- **Stores are followed by a read of `cpuctrl0` in the PROM** (`0xbfc01048`, `0xbfc00cfc` and about two dozen other sites): a dummy
  read to flush the write path. The kernel's equivalent for a first-revision chip is `writemcreg`, which runs uncached and does a
  dummy read of the PROM before each MC store "to flush the MUX FIFO". Only revision 0 needs it. `established`.
- A qtest can check: the two-address aliasing, that the wrong-endian address sets `cpu_err_stat.addr`, and that reads of a reserved
  offset in the window raise a bus error (the last is `unknown`: the specification says unused addresses in the physical map bus-error
  but does not say the same of unused MC offsets).

## What the Indigo PROM writes to the MC (4.0.5D)

From the image `070-8116-004` (4.0.5D Rev A, 19 Aug 1992); sha256 `e6e1f1ed…` as in [prom-images.md](../../references/prom-images.md).
Addresses are PROM addresses; every value is read from the listing. The values match the later PROM's public source
(`stand/arcs/IP20prom/csu.s`, `lmem_conf.s`), which is organised differently in places. Details of the little-endian flip are on the [PROM page](../../platforms/ip20/prom-software.md#the-flip-routine-and-what-runs-little-endian-established-unless-marked).

| Address | Access | What |
|---|---|---|
| `0xbfc00424`, `0xbfc0042c` | `cpu_err_stat` ← 0, `gio_err_stat` ← 0 | Clears leftover error bits; the read of `cpuctrl0` at `0xbfc00438` flushes. |
| `0xbfc0048c` | `cpuctrl0` ← `0x3c002014 \| (hwm << 20)` | Whole-register store. Bits: refresh enable, refresh burst field 4 (eight lines), interrupt enable, `r4k_chk_par_n`, `back2`, bus-rate field 3. Parity reporting, watchdog, `grr` (graphics held in reset), `little` and warm-reset bits all clear. `hwm` is 6, 8, 12 or 20 for a 16-, 32-, 64- or 128-byte cache line, taken from CP0 Config (secondary cache absent: 16 bytes). |
| `0xbfc004a8` | `cpuctrl1` ← `0x1016` | `mc_hwm` 6, `abort_en`, `hpc_fx` set, `hpc_little` clear. The only store to this register in the image. |
| `0xbfc004c8` | `cpu_memacc` ← `0x11453433` | Write/read column 3/3, row 4, precharge 3, refresh timings 5/4/1, `cas_half`. |
| `0xbfc004dc` | `gio_memacc` ← `0x34332` | Write column 2, read column 3, row 3, precharge 4, `cas_half`, `addr_half`. |
| `0xbfc004e8`–`0xbfc00500` | `rpss_ctr` read | Waits for 625 counter ticks (62.5 µs at the reset 100 ns tick) so the SIMMs see at least eight refresh lines before use. The image never writes `rpss_divider` or `ctrld`: it relies on their reset values. `inferred` (reset `0x0104` and `0x0c30`, specification). |
| `0xbfc028b0`–`0xbfc02934` (pon_mc) | `cpuctrl0` bit 4 cleared; `cpu_memacc` walking-one test | Clears refresh enable, writes 1 << 27 down to 1 into `cpu_memacc` reading each back, restores the old value and `cpuctrl0`, then repeats on an HPC1 register. Failure spins at `0xbfc02938`. Bits 28 and up of `cpu_memacc` are not tested. |
| `0xbfc00a0c`, `0xbfc00a10` | `memcfg0`, `memcfg1` ← 0 | Invalidates all four banks. |
| `0xbfc01000` helper | one 16-bit half of `memcfg0/1` | Bank 0 is the high half of `memcfg0`, bank 1 its low half, bank 2 the high half of `memcfg1`, bank 3 its low half. Followed by the `cpuctrl0` read. |
| `0xbfc00a1c`–`0xbfc00ac8`, `0xbfc00d1c`, `0xbfc00f1c`, `0xbfc00f64` | bank probe | See "Memory sizing". |
| `0xbfc00544`–`0xbfc005b4` | `cpuctrl0` low nibble ← 2 | After sizing, drops the refresh burst to four lines unless some valid bank has size code 0 or 1 (256Kx36 or 512Kx36 SIMMs, which need eight). |
| `0xbfc00b28`–`0xbfc00bb8` | DMA block | Memory clear by DMA fill, below. |
| `0xbfc03674`, `0xbfc0f5ec` | `cpuctrl0` bit 10 clear, delay (`0xbfc0a9cc`, argument 5), set | Pulses the graphics reset. |
| `0xbfc07950` | `lb_time` ← `0x34f` (`0xbfc0796c`), `cpu_time` ← `0x2b` (`0xbfc0797c`); then `cpuctrl0` parity bits | Board revision (`0x1fbd0000`, `0xbfc07c38`, bits `0x7000` inverted) 2 or more: clear `r4k_chk_par_n`, set `gpr`, `mpr`, `cpr`, `cmd_par` (`0x10e0`). Below 2: the reverse. Same rule as the kernel's `mlreset`. |
| `0xbfc07ec4` | `cpuctrl0` ← `0x200` | `sin`: reset the whole machine; spins afterwards. |
| `0xbfc01320`, `0xbfc01340` | `eerom` bit-bang, `cpuctrl0` ← `0x10000` | Byte-order flip: rewrites EEPROM word 0, then sets `wr_st`. Through the lower (little-endian) addresses. |
| `0xbfc01960`, `0xbfc01b94`, `0xbfc038c4`, `0xbfc06c88` | error status ← 0 | Clear both status registers; reads of status and address at `0xbfc021e4`–`0xbfc0228c` and `0xbfc06c08`–`0xbfc06c74` feed the PROM's fault report (CpuErrorAddr, GioErrorAddr and so on). |

The PROM **never** reads or writes: `sysid`, `dogc`, `rpss_divider`, `ctrld`, `ref_ctr`, `gio64_arb`, `sys_semaphore`,
`lock_memory`, `eisa_lock`, `semaphore`, `dma_gio_mask`, `dma_gio_sub`, `dma_tlb_*`, `dma_stdma`. This is the set of constant-address
accesses found by scanning every `lui` plus offset pair; an access through a computed base would be missed. `inferred` (a scan, not a proof).

Reset values the PROM depends on before it writes them (all `inferred`, from the PROM address): `rpss_divider` (`0xbfc004e8`),
`ctrld` and `cpuctrl0` refresh enable (the refresh wait above), `gio64_arb` (all HPC and graphics accesses before the kernel writes it;
including the HPC width bit loaded from the EEPROM), and `cpuctrl0` bit 18, loaded from the EEPROM (the PROM's byte-order test
reads CP0, not the MC).

### Memory sizing and the bank registers (`established`)

Sources: `stand/arcs/IP20prom/lmem_conf.s` in the public tree and the 4.0.5D listing at `0xbfc00a00`–`0xbfc01110`. The listing and
the source follow the same idea (probe with one bank at a time, grow a trial size by four, then test for two sub-banks); the listing
does it in two stages at `0xa8000000` and `0xac000000` and is the authority for 4.0.5D. Kernel readers of the same
fields: `get_mem_conf`, `bank_addrlo`, `banksz`, `szmem` in the Indigo kernel (`irix/kern/ml/IP20.c`).

- A bank word is 16 bits: base (4 MiB units), size code, valid, two-subbank. Bank size in bytes = `((word & 0x1f00) + 0x100) << 14`
  (4 MiB × (code + 1)); `szmem` sums the four. Valid only if the valid bit is set; a zero word is "no memory".
- **Probe.** For each bank in turn: set that bank's word to `0x3f20` (valid, size code 31 = 128 MiB, base `0x20` = `0x08000000`), all
  other banks cleared. Write four different patterns (`0x11111111` shifted left one bit each) at `0xa8000000`+0, 4, 8, 12, zero at +16 to +28,
  read the four back: each of the four SIMMs supplies one word of a 16-byte line, so a mismatch names a missing or bad SIMM.
  Then clear the first four words, write the four patterns at `0x08000000` plus 4 MiB, then plus 16 MiB, and after each read the first four
  words back: a nonzero value means the address wrapped, and the wrap distance (4 MiB, 16 MiB, or none within 64 MiB) is the size of one
  sub-bank. Finally set the two-sub-bank bit (`0x7f20`) and probe `0x0c000000` (64 MiB up) the way the first test did: if all four
  SIMMs answer there, there is a second sub-bank and the bank is twice the distance; otherwise it is the distance.
- The size word is stored as `((units − 1) << 8)`, two-subbank bit (`0x4000`) for 2, 8 and 32 units (8, 32, 128 MiB banks).
  Placement: banks are sorted largest first; the first base is unit 32 (`0x08000000`), each base advances by the bank size, and
  when it reaches unit `0x60` (`0x18000000`) it jumps to unit `0x80` (`0x20000000`). A bank needs a base that is a multiple of its size.
  So the MC's two memory windows are `0x08000000`–`0x17ffffff` and `0x20000000`–`0x2fffffff`; the header says the board holds at most 384 MiB, so the
  second window is at most 128 MiB on the Indigo.
- **The two Indigo PROMs differ here (`established` for 4.0.5D; 4.0.5G is the earlier [PROM comparison](../../platforms/ip20/prom-software.md#405g-differences), not re-read).**
  After sizing, the PROM clears memory with the MC's DMA engine in fill mode: `dma_ctl` ← 0 (no translation), `dma_cause` ← 0,
  `dma_memadr` ← `0x08000000`, `dma_mode` ← `0x5a` (long burst, incrementing, fill, graphics-to-host), `dma_count` ← `0x10000`, `dma_stride` ←
  `0x10000` (zoom 1, stride 0), `dma_size` ← `(total << 1) | 0x8000` (lines of 32 KiB, `total / 32 KiB` of them), `dma_gio_adrs` ← 0
  (the fill constant; this starts the DMA), poll `dma_run` bit 6, then `dma_cause` ← 0 (`0xbfc00b28`–`0xbfc00bb8`). **4.0.5D does this in one run
  from `0x08000000` for the whole total**, so a total above 256 MiB runs the fill across the hole at `0x18000000` into I/O space. 4.0.5G
  (and the later source) clamp the first run to 256 MiB and start a second at `0x20000000`. The Usenet failure with 384 MiB reports
  `GioErrorAddr: 18000000` exactly. `inferred` that this is the cause; the same report shows PROM 4.0.5G booting with 384 MiB.
- Valid bit and size are set for the test with base `0x20`, address test over the whole size, then the bank is cleared if the walking-bit
  test fails; the final base comes last (`0xbfc00f64`).

## Register notes and what a qtest can discriminate

One row per register. Offsets are the big-endian view. "IP12" says whether the R3000 Indigo has this register: see the last section.

| Register | Offset | Reset | Notes | Discriminating test |
|---|---|---|---|---|
| `cpuctrl0` | `0x04` | `0x00100012` (EEPROM bit 18 may differ) | Established. `grr` low means graphics reset asserted; the PROM's first store leaves it low. `sin` resets the machine. | Reset value; store/readback of every defined field including `mux_hwm` and `bus_rate`; `wr_st` restarts the CPU; the PROM-write interrupt follows `prom_wr_en`. |
| `cpuctrl1` | `0x0c` | `0xc` | Established. `hpc_fx` set for HPC1.5. | Reset; fields read back. |
| `dogc` | `0x14` | 0 | Established. 20-bit counter of refresh bursts; any write clears. Wrap with `dog` set resets the machine. | Counter advances once per refresh interval; a write clears it. |
| `sysid` | `0x1c` | revision | Established; value on the Indigo `unknown` (see revision above). | Read-only: a write is ignored. |
| `rpss_divider` | `0x2c` | `0x0104` | Established (spec); `inferred` for the Indigo, via the PROM's reliance. The kernel writes `0x0101`. | Reset; counter tick rate follows the two fields. |
| `eerom` | `0x34` | 0 | Established. Bit 0 (PRE) is Linux's name; the IRIX header and specification say reserved (`inferred`). | `sck`/`cs`/`sdata_out` read back; `sdata_in` reads the modelled EEPROM and ignores writes. |
| `ctrld` | `0x44` | `0x0c30` | Established. Preload of the 20 ns refresh counter. | Reset. |
| `ref_ctr` | `0x4c` | n/a | Established. Counts down from `ctrld`. | Two reads differ; a write is ignored (`unknown` whether it bus-errors). |
| `gio64_arb` | `0x84` | `0x400` | Established. The kernel notes reads can return corrupt data on silicon, so it never reads back. On the Indigo every size and pipelining bit is 0 and slot master/real-time bits are set only for installed cards. | Reset; every defined bit stores. |
| `cpu_time`, `lb_time` | `0x8c`, `0x9c` | `0x100`, `0x200` | Established. Same read-corruption note. | Reset; fields store. |
| `memcfg0`, `memcfg1` | `0xc4`, `0xcc` | valid bits 0 | Established. Decode rule above. | Programming a bank makes exactly its window respond; overlap bus-errors; an unmapped address sets `cpu_err_stat.addr`. |
| `cpu_memacc`, `gio_memacc` | `0xd4`, `0xdc` | `0x01454333`, `0x4333` | Established. Timing only. Bits 27 to 0 of the first store (PROM walking test). | Reset; store/readback of the low 28 bits (first) and 18 bits (second). |
| `cpu_err_addr`, `cpu_err_stat` | `0xe4`, `0xec` | 0 | Established. Any write clears the status. | Fault injection: read of an unmapped address sets `addr` and latches the address; a write clears. |
| `gio_err_addr`, `gio_err_stat` | `0xf4`, `0xfc` | 0 | Established. | GIO timeout (needs `abort_en`) sets `time`; a PROM write with `prom_wr_en` clear sets `prom`; a write clears. |
| `sys_semaphore`, `semaphore[16]` | `0x104`, `0x10004` + `n * 0x1000` | 0 | Established. Read returns the bit and sets it to one; write stores bit 0. | Read-set semantics; independent pages. |
| `lock_memory`, `eisa_lock` | `0x10c`, `0x114` | 1 | Established. `eisa_lock` is dead on the Indigo (no EISA). | Reset; store/readback. |
| `dma_gio_mask`, `dma_gio_sub` | `0x154`, `0x15c` | `unknown` | Role named by the IRIX header; bit layout `unknown`. | Readback only. |
| `dma_cause` | `0x164` | `unknown` | Established bits (page fault, uTLB miss, clean, complete, bad memory, bad PTE). Cleared by a write of 0. | Complete bit after a DMA; raises the DMA interrupt when `dma_ctl.ie` is set. |
| `dma_ctl` | `0x16c` | `unknown` | Three bits established (`ie`, `xlate`, `decslv`); the kernel's initial constant carries more fields with no source naming them. | `xlate` selects physical vs virtual. |
| `dma_tlb_hi/lo[4]` | `0x184` + 0x10 × n, `0x18c` + 0x10 × n | `unknown` | Established: segment tag; low word valid bit 1, page-table address bits 25:6 (physical / 64). | Translation uses the entry: a miss sets `utlbmiss`. |
| `rpss_ctr` | `0x1004` | 0 | Established. | Rate follows `rpss_divider`. |
| `dma_memadr` … `dma_run`, `dma_memadrd`, `dma_memadrds` | `0x2004`–`0x204c`, `0x2074` | `unknown` | Established for the parameter registers and mode bits; `dma_count` layout and the two "set defaults" registers `unknown`. | A fill DMA writes the constant over the memory range; `dma_run.running` clears when done. |

### What the IRIX kernel does to the MC (`mlreset`, `established`)

Source: `irix/kern/ml/IP20.c`; confirmed against the IRIX 6.5 Indigo kernel object (`mlreset`, same constants). In order: clear both
error status registers; write `rpss_divider` = `0x0101`; clear the SysAD parity bit (`disable_sysad_parity`); if board revision is 2 or more, OR
`gpr|mpr|cpr|cmd_par` into `cpuctrl0`, otherwise clear them; read `sysid` low nibble into the revision variable; set `cpuctrl1.mc_hwm` to 13
(keeping the other bits); write `gio64_arb` from a software copy that starts as `one_gio` alone (slot bits are added later by
`setgioconfig`); initialise the DMA engine (`dma_ctl` constant, mask and substitution zero, cause zero, all four TLB entries zero); read
`memcfg0/1` into software copies. The kernel never reads back the arbitration and time registers, because on silicon a read can return garbage.

### The graphics DMA engine, in brief

Sources: `irix/kern/io/vdma.c` and `irix/kern/sys/vdma.h` in the public tree; the PROM listing for the fill case.
`established` unless marked.

- Parameters: memory address (virtual if `dma_ctl.xlate`, else physical), mode, `dma_size` (width low half, line count high half),
  `dma_stride` (signed stride low, zoom high), then a store to `dma_gio_adrs` starts it. The memory address register advances as it
  runs; the kernel reads it after a fault to find the address.
- Translation: the engine looks up the page tables through four uTLB entries; each maps one segment (the span of one page of PTEs).
  An entry's low word points at the PTE page. If none matches, `utlbmiss`. The kernel keeps only four, so a transfer is limited to four
  segments (16 MiB with 4 KiB pages), and can fake a fifth for negative strides.
- The kernel resumes after a page-fault stop by fixing the PTE, clearing `dma_cause`, and writing 1 to `dma_stdma`; a timeout writes 0.
- Fill mode writes the constant held in the GIO address register to memory (the IP20 PROM memory clear). In a normal transfer the
  register is the GIO slave address.
- Completion raises an interrupt only when `dma_ctl.ie` is set, delivered through the INT2 local-interrupt 0 bit named "graphics DMA done"
  in the Indigo header. The engine needs MC revision 1 or later for translation; revision 0 transfers physical only.
- An emulator's MC model implements the copy and fill loop; its behaviour is a note only.

## Indigo against Indy and Indigo2

The same chip family, but the board around it differs. Established unless marked; sources are the public Indigo and Indigo2 PROM
start-up sources (`stand/arcs/IP20prom/csu.s`, `stand/arcs/IP22prom/csu.s`) and kernels (`irix/kern/ml/IP20.c`, `IP22.c`), and the
specification notes.

| Item | Indigo R4000 | Indy / Indigo2 |
|---|---|---|
| I/O controller | HPC1.5 (`gio64_arb.hpc_size_64` = 0, `cpuctrl1.hpc_fx` set, `hpc_little` = CPU endian: "set to 0 for HPC1") | HPC3 (width bit 1, `hpc_fx` clear). The spec calls them "HPC1.5 and HPC3" explicitly. |
| Interrupt controller | INT2, registers inside the HPC1 window; the MC takes its six lines (spec 2.8) | Other INT2 variants at other addresses (NetBSD `int.c`: separate IP22 and IP24 bases). The same six-line contract; not an MC difference. |
| GIO width | Slots and graphics 32-bit; `exp0_size_64`, `exp1_size_64`, `grx_size_64`, `*_piped` all 0 (spec notes "for Indigo this should be 0"; NetBSD refuses pipelining on this board) | Written from the HPC3 board's flags: `hpc_size_64`, `hpc_exp_size_64`, `one_gio`, `exp0_piped` for Fullhouse, with `exp1_piped` and `eisa_mst` from board revision 2, `exp1_mst`/`exp1_rt` below it; Indy: `hpc_size_64`, `one_gio`, `eisa_size_64`, `eisa_mst` |
| `gio64_arb` | The PROM leaves the reset value (`0x400`); the kernel's initial software copy is `one_gio` alone and drivers add slot bits through `setgioconfig` | The PROM and kernel write a board-revision-dependent value with the HPC 64-bit bits |
| `gio_memacc` | `0x34332` | `0x34322` (read column 2, as the specification recommends) |
| `cpuctrl1` | `0x1016` (`hpc_fx`) | `0x16` |
| EISA | None: `sysid.eisa` 0, `eisa_lock` unused, `eisa_mst` 0 | Indigo2 has it on some boards |
| Parity enables | Set only when board revision ≥ 2 (older boards write bad parity during virtual DMA through a faulty MUX); the PROM and the kernel do the same | All reporting enabled, with `r4k_chk_par_n` set (kernel) |
| `rpss_divider` | Reset `0x0104` kept by the PROM 4.0.5D; kernel writes `0x0101` | The PROM writes `0x0104`; kernel `0x0101` |
| Memory | Two windows, 384 MiB maximum, 4 banks of SIMMs (the 128 MiB bank maximum applies) | Same layout; the Indigo2 kernel also handles a revision 5 or later chip whose base and size units are four times larger (not an Indigo part) |
| Revisions | A, B, C | Indigo2: revision A not supported (kernel comment) |

## IP12 (R3000 Indigo)

The R3000 Indigo is not an MC machine, as far as the sources show: the specification's change log removed R3000 support in February
1992 ("Removed R3K support"), and the 4.0.1 Rev C PROM for the R3000 board (`070-8088-xxx`) touches only a different, much smaller set of
offsets in the `0x1fa00000` page: `0x00`, `0x04` (one read at `0xbfc15a20`), `0x08`, then `0x1fa10000`, `0x1fa10004`, `0x1fa10200`–`0x1fa10210`,
`0x1fa20008` and `0x1faa0000`, `0x1faa0100` (listing scan; accesses through computed bases not seen). No `memcfg`, `*_memacc`,
`cpu_err_*` or DMA offset appears, and the register at `+0x00` is written with `0x200` and `0xc00` and ORed with `0xc`, `0xe`, `0x80`,
`0x40` in ways that do not match `cpuctrl0`'s fields. An emulator's R3000 Indigo model names this region the earlier PIC and CTL gate arrays
(a note, not evidence). So for every register in [registers.md](registers.md): **IP12 does not use it** (`inferred`: no access found, no
source states otherwise), except `+0x00`/`+0x04`/`+0x08`, whose IP12 meaning is `unknown` and a different layout from the MC's.

## Open

See [questions/ip20-mc.md](../../questions/ip20-mc.md).
