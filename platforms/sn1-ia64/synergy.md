# Synergy: the Itanium processor-bus ASIC on an SN1 IA-64 node

Synergy is the chip between a Bedrock processor interface and an Itanium front-side bus. It exists only on the IA-64
node; the MIPS Origin 3000 node connects R12000s to the Bedrock directly. No specification is held, and no document found
(mailing list archive, TechPubs, or the public web) names or describes the chip outside the Linux source. Everything here comes from
SGI's Linux port (`include/asm-ia64/sn/synergy.h`, `arch/ia64/sn/sn1/synergy.c`, `sn1/irq.c`, `sn_cpuid.h`,
`nodepda.h`, v2.5.0 snapshot; `include/asm-ia64/sn/sn1/synergy.h` and `arch/ia64/sn/kernel/sn1/synergy.c` from v2.5.7 to
v2.5.72, same content with small edits) one cross-check in the Bedrock memory page, and the 2.4-series patches described below. The platform context is in
[README.md](README.md).

## Where it sits

| Fact | Grade | Source |
|---|---|---|
| Two Synergies per node, numbered 0 and 1; each fronts one FSB; each FSB holds two processor slots (0 and 1). A processor's LID `eid` field is `synergy << 1 | slot`; the NASID is the LID `id`. | established | `sn_cpuid.h` |
| Synergy 0 faces PI0 (slices 0 and 1) and Synergy 1 faces PI1 (slices 2 and 3). | inferred | the code gives both pairings (slice to synergy, slice to subnode) but never states that a Synergy connects to the PI with the same number; the subnode numbering and the Synergy numbering agree for every slice |
| A Synergy is reached by ordinary uncached loads and stores. From a remote node its registers are in the Bedrock's hub special space: node `n`'s remote register window (`HSPEC_BASE + n << 33 + 0x30000000`) plus `0x04000000` for Synergy 0 or `0x05000000` for Synergy 1 (16 MB apart, `HS_SYNERGY_STRIDE`). | established | `synergy.h` (`RSYN_REG_OFFSET`, `NODE_LREG_BASE`) |
| From its own processors a Synergy is reached at physical `0xe0000000000` plus the register offset (`SSPEC_BASE`, `LB_REG_BASE`), uncached. Which Synergy a local access reaches is the one on the processor's own bus (the code's own comment says "which fsb?" and does not answer). | established for the address; inferred for the selection | `synergy.h` |
| The Bedrock's junk-bus timing register has setup-and-hold and enable fields for a device named Synergy, next to the flash and the UART. So Synergy hangs off the Bedrock's junk bus. | inferred (the field names are established; that they are the same chip is the Linux header's own name for the device) | [devices/bedrock_md/registers.toml](../../devices/bedrock_md/registers.toml), `junk_bus_timing` |
| The processor's own accesses to its Synergy (fake PROM and kernel) go to physical `0xe0000000000` plus the offset, with no node number in the address. The simplest reading of the kernel's "which fsb?" comment is that the Synergy on the issuing bus decodes the address itself, so no choice is made. | inferred | `synergy.h`, `fprom/main.c` (base `0x80000e0000000000`), `klgraph_hack.c` (`SYNERGY_WIDGET 0xc0000e0000000000`) |
| The remote path (through the Bedrock's hub special space, four 64-bit stores per write, each carrying a 16-bit slice of the value) differs from the local path (one 64-bit store). Both reach the same registers. A consistent explanation: the local path is a front-side-bus access to the chip, the remote path goes through the Bedrock and the junk bus that carries 16-bit writes. | inferred | `synergy.h`; [devices/bedrock_md](../../devices/bedrock_md/registers.toml) `junk_bus_timing` |
| The simulator control file gives its Synergy model a cache: `synergy_cache_type syn_cac_64m_8w`, which by the setting's name is 64 MB, 8-way. Whether silicon had a cache in Synergy is not stated; the simulator ran with `coherency_type nasid`. | established for the settings; inferred for the reading | `arch/ia64/sn/fprom/runsim`, v2.5.0 |

## Register offsets the kernel and the fake PROM use

All 64-bit, offsets in the Synergy's own register space. `0x450` is from the fake PROM (`arch/ia64/sn/fprom/main.c`, `synergy_init`, v2.5.0; unchanged in v2.5.72 `fakeprom/main.c`); the rest are from the kernel.

| Offset | Name | Use | Grade |
|---|---|---|---|
| `0x2a0` / `0x2a8` | `VEC_MASK3A` / `VEC_MASK3B` | Interrupt vector enable mask for vectors 192 to 255, slot A and slot B | established |
| `0x2b0` / `0x2b8` | `VEC_MASK2A` / `VEC_MASK2B` | Vectors 128 to 191 | established |
| `0x2c0` / `0x2c8` | `VEC_MASK1A` / `VEC_MASK1B` | Vectors 64 to 127 | established |
| `0x2d0` / `0x2d8` | `VEC_MASK0A` / `VEC_MASK0B` | Vectors 0 to 63 | established |
| `0x450` | `FSB_CONFIG` (the comment's name) | Written once by the fake PROM, per Synergy, with `(nasid << 16) \| (synergy << 9)`, so bits 23:16 (at least) carry the node's NASID and bit 9 the Synergy number. No other bit is written or read by anything held. | established for the offset, the written value and the name; inferred for "NASID" and "Synergy number" as the field meanings, from the comment and the arguments; unknown for every other bit |
| `0xab0`, `0xab8` | `PERF_CNTL0_A`, `PERF_CNTL0_B` | Performance control, FSB 0, counter A and B (only with `CONFIG_IA64_SGI_SYNERGY_PERF`) | established as offsets; field layout unknown except bit 45 (enable) |
| `0xac0`, `0xac8` | `PERF_CNTL1_A`, `PERF_CNTL1_B` | Performance control, FSB 1 | established as offsets |
| `0xad0`, `0xad8` | `PERF_CNTR0_A`, `PERF_CNTR0_B` | Performance counters, FSB 0 | established as offsets |
| `0xaf0`, `0xaf8` | `PERF_CNTR1_A`, `PERF_CNTR1_B` | Performance counters, FSB 1 | established as offsets |

The header comments label the `A` and `B` performance registers "on FSB0" (control and counters 0) and "on FSB1" (set 1). The kernel's multiplexer (`synergy_perf_update`, 2.4.18 and v2.5.0) instead reads `PERF_CNTR0_A` through Synergy 0 and `PERF_CNTR0_B` through Synergy 1, and writes the same event word to `PERF_CNTL0_A` on Synergy 0 and `PERF_CNTL0_B` on Synergy 1. So `A` and `B` may name the Synergy rather than a bus-side counter, and the FSB0/FSB1 labels may not mean a bus number. Not settled; grade unknown.

How the mask registers are used (`synergy_intr_connect` and `setclear_mask_a` and `_b`): an interrupt for processor `p` is
enabled by setting its bit in the A register when `p` is in slot 0 and the B register when `p` is in slot 1, and clearing
the same bit in the other register. The vector number is `irq`, where `irq = Bedrock pending bit + 64`, so the Bedrock's 128
pending bits arrive as vectors 64 to 191 by the formula, but `bit_pos_to_irq` clamps bits above 118 to 118, so the highest vector the code produces is 182. Vectors outside 64 to 182 are not generated by anything the code shows.

Remote writes are not one store. `__remote_synergy_out` writes four 64-bit stores to consecutive 8-byte addresses starting at
`reg << 2`, carrying `value >> 48`, `value >> 32`, `value >> 16` and `value` in that order (unmasked, so the upper words hold more than 16 bits; that the chip takes the low 16 of each is inferred from the patent statement below), then issues `mf.a`. A remote read loads one 64-bit word
at `reg` with no shift. A local write is one 64-bit store followed by `mf.a`. The split matches the Bedrock patent's statement
that junk-bus devices take 64-bit reads and 16-bit writes ([platforms/ip35/boot-flash.md](../ip35/boot-flash.md)), which is an inference for
Synergy: the patent names the flash. Whether the remote read and write offsets really differ by a factor of four, or the
code has a defect on one side, is not stated.

## Register map as a unit

The offsets, widths and grades of every register below and in the next section are also in
[devices/synergy/registers.md](../../devices/synergy/registers.md), generated from `devices/synergy/registers.toml`.

## Further facts from the 2.4-series patches and unread v2.5.0 headers

Source: SGI's SN1 code as published in the Linux/IA-64 project's 2.4.16 and 2.4.18 patch series (`linux-2.4.16-ia64-011126`,
`linux-2.4.18-ia64-020410` and `020722`; `include/asm-ia64/sn/sn1/synergy.h`, `arch/ia64/sn/kernel/sn1/{cache.c,iomv.c,
synergy.c,error.c}`, `arch/ia64/sn/kernel/irq.c`, `arch/ia64/sn/fakeprom/`). The v2.5.0 snapshot in our holdings has neither `0xae0` nor `0x330`/`0x338`; the 2.4.18 header's register set is the v2.5.0 set plus them. Rows marked v2.5.0 come from that snapshot's headers, which the first pass did not read. The 2.4.0-test10 patch of November 2000, the first
to add `arch/ia64/sn/` files (the August 2000 test6 patch only edits three existing files there), already has the mask registers and the fake PROM's `FSB_CONFIG` write.

| Fact | Grade | Source |
|---|---|---|
| Register `0xae0` (`SYN_TAG_DISABLE_WAY`, from the 2.4.16 patch). The kernel's cache-flush routine writes `0xff` with bit `w` cleared, walks 512-byte blocks through nine aliases 8 MB apart, repeats for `w` = 0 to 7, and writes 0. The header sizes the Synergy's L4 at 64 MB, 8 ways, 512-byte blocks. That a set bit disables a way, and that the walk evicts a block from the one way left enabled, is the routine's evident design. | register, constants and sequence established; meaning of a set bit inferred | `cache.c`, `synergy.h` |
| Synergy implements the Itanium `fc` instruction so that it purges the line from every processor cache and from the L4 of the other buses and from both processors on its own bus, but not from its own L4; that is why the routine above is needed. | the comment's words are established; its "local FSB" is read here as the Synergy's own L4, which is inferred from the routine's purpose; the mechanism is unknown | `cache.c` |
| Registers `0x330` and `0x338` (`GBL_PERF_A`, `GBL_PERF_B`, from the 2.4.18-020410 patch). The kernel's I/O write barrier, after reading the Bedrock revision register, polls the one for its Synergy until it is nonzero, sleeping 5 microseconds a pass. The code comment says it waits for the Bedrock PIO write status to clear. The names say performance, the use says write status. | offsets and polling established; role as write-drain status inferred; bit meaning unknown | `iomv.c`, `setup.c`, `synergy.h` |
| Interrupt vectors 65 and 182. Vector 65 (`SGI_UART_IRQ`) stands for the Bedrock pending bits 1 to 6 together (graphics A and B, page migration, UART, and the two `CC_PEND` bits, whose function the header does not give); vector 182 (`SGI_HUB_ERROR_IRQ`) for pending bits 118 to 127, which the kernel clamps to one vector. The kernel's handler for 182 reads the second pending register and tests the crossbar, local-block, NACK, clock, correctable-error, memory-correctable, network and system-controller panic bits, and panics on each. The header says these two numbers are "not strictly accurate" and sends the reader to a Synergy specification. | established for the numbers and handlers; the flat numbering of the second pending register (bit `b` there is pending bit `64 + b`, so 54 to 63 are 118 to 127) is inferred from `182 = 118 + 64` and the handler's tests | `irq.c`, `error.c`, `intr.h` |
| The 2.4.18 `irq_to_bit_pos` is plain `irq - 64`. The v2.5.0 version, as the review below records it, subtracts 64 again above 127, so the two trees disagree; the 2.4.18 one is the simpler. | 2.4.18 form established; v2.5.0 form as reviewed | `irq.c` |
| Synergy-mode status of the Bedrock. A Bedrock processor-interface header comment says that "in Synergy mode" the source processor of a command is given by bit 52 of the SysAD bus (which of the two processors on that bus sent it), set by Synergy in every command; the PI keeps it in its request buffers and uses it to pick the A or B error bit and the matching error status and spool registers. The PROM configuration header says bit 8 of the high 32 mode bits is "the synergy mode bit". So Synergy sits on the Bedrock's SysAD-style processor port, and the Bedrock has a mode that reads the source processor from the bus instead of from which of two physical busses carried it. | established as the headers' statements; that Synergy speaks the R1x000 SysAD protocol is inferred | `sn1/hubpi.h`, `sn1/ip27config.h`, v2.5.0 |
| Bedrock junk-bus defaults for Synergy: enable `0xff`, setup `0xff` (UART `0x0c` and `0x02`, flash `0x10` and `0x10`). These fill the three byte pairs of the junk-bus timing register ([devices/bedrock_md](../../devices/bedrock_md/registers.toml)), and the register's reset value in the memory page is `0xffffffffffff`, so Synergy keeps the reset setting while the UART and flash are tightened. | established as the PROM header's defaults | `sn1/ip27config.h`, v2.5.0 |
| Uncached space has two views. The kernel's I/O and hub-special bases come in a pair that differs only in physical address bit 43: `0xc0000a...` and `0xc0000b...` against `0xc00002...` and `0xc00003...`. The code calls the first the unswizzled and the second the swizzled Synergy space. Through the unswizzled view a 32-bit register at offset `r` of a 64-bit-wide device is reached at `r ^ 4` (the PCI Bridge and crossbar register structures in the kernel pad each register with a filler word for this reason); the alternative named is to use the swizzled view and byte-swap data in software. Clearing bit 43 in a PCI ROM address is how the kernel chooses the swizzled view. The simulator is told `swizzling on`. | established as the code's behaviour; that the Synergy performs the data-lane swap, rather than the Bedrock, is inferred from the phrase "synergy space" | `pcibr.c`, `pci_bus_cvlink.c`, `xbow.h`, `bridge.h`, `addrs.h`, `runsim`, v2.5.0 |
| The fake PROM's debug constants `SYNERGY_WIDGET` (`0xc0000e0000000000`) and `SYNERGY_SWIZZLE` (`0xc0000e0000000400`) are the uncached region base plus physical `0xe0000000000`, the same address `SSPEC_BASE` gives for the local register space. They are only printed. The physical address bits 43 to 40 of the spaces the code names are `0x2` and `0xa` (I/O, swizzled and not), `0x3` and `0xb` (hub special, swizzled and not) and `0xe` (Synergy), so bits 43 to 41 look like a space selector; that is a pattern, not something the code states. What lives at `+0x400` is not stated. | established as constants; selector reading inferred; role of `+0x400` unknown | `fakeprom/klgraph_init.c`, 2.4.18 patch; `sn1/addrs.h`, `synergy.h` |
| Per-Synergy software state: two `synergy_da` structures per node, one per Synergy, hold the interrupt-mask bookkeeping; a hardware-graph directory `synergy/0` and `synergy/1` per node exposes the performance counters through ioctls that set an event word, read counters and set a multiplex rate. The counters are multiplexed one event at a time, one switch every N timer interrupts (default 10), and read masked to 40 bits. | established | `klgraph.c`, `synergy.c`, `sndrv.h`, 2.4.18 patch |

## What it was

Question: function, which Itanium, bus conversion.

- Function. A bus-conversion and interrupt-steering ASIC, one per Itanium front-side bus, between the bus and one Bedrock
  processor interface. What the code shows it doing: it takes a NASID and a Synergy number (`FSB_CONFIG`), it holds the
  per-slot vector enables that decide which of the two Itanium slots on its bus receives a Bedrock interrupt (as vectors 64
  to 191), it carries performance counters, and processors on its bus address it directly. Grade: the listed behaviours are
  established; "converts the Itanium bus protocol into what the Bedrock's processor interface speaks, and snoops for the
  two slots" is inferred, because two Itaniums on one bus cannot meet a Bedrock port built for two MIPS processors without
  one, and nothing in the code touches a bus-protocol register.
- The reading that Synergy converts the Itanium bus to the Bedrock's processor interface, which keeps the MIPS-derived
  SysAD style of the R1x000 hub attachment, is consistent with all of this and is not contradicted by anything found. It is not confirmed: no source names the
  Bedrock-side protocol. A contemporary poster on the comp.arch Usenet group described the SN2 change as replacing "SysADs" with "Itanium FSBs" on the
  hub (Usenet `y4mdncYfzLtevg_dRVn-sw@speakeasy.net`, 2004-04-30); that describes the later SHub, not Synergy, and is a
  poster's summary, so it supports the picture only as an inference.
- Which Itanium. First-generation Itanium (Merced). SGI's own account of getting Linux running says the prototype hardware
  used first-generation Itanium processors and that a 32-processor Itanium system ran by early 2001 (S. Neuner, "Scaling
  Linux to New Heights: the SGI Altix 3000 System", Linux Journal, 2003-02-01, linuxjournal.com/article/6440); the Linux code
  of the time is the only SGI IA-64 code that carries the Synergy driver; the simulator ran with `cpu_stepping A`; the kernel
  menu offers McKinley as a processor type only as a generic choice. No source states "Merced" beside "Synergy", so
  the identification is inferred.
- Registers beyond the known ones. Only 20 offsets are known: the 8 mask registers, 8 performance registers, `FSB_CONFIG`, the L4 way mask and the two write-status registers. Nothing
  else was found in our holdings, in kernel mail (2000 to 2003), or on the web.

## Not known

Everything else: the layout of `GBL_PERF_A/B` and the L4 control beyond the way mask, the `FSB_CONFIG` bits other than the two written fields, reset values, the other register offsets, the per-processor error and ECC logic, coherence and snoop
control, the interface to the Bedrock PI (processor-bus command encodings), the interrupt priority and inter-processor
interrupt path through Synergy, and the meaning of the A and B performance event selectors. The open entry is in
[questions/sn1-ia64-synergy-registers.md](../../questions/sn1-ia64-synergy-registers.md). What the fake PROM and the kernel touch in Synergy is in
[fake-prom.md](fake-prom.md).

## Review

Independent review, 2026-11-14, by a reviewer who wrote none of these pages. Reviewed chips revision a399d6d (pages from 842b367, 55a5bcc, f5ab671 and the earlier SN1 IA-64 commits through 15a5a4e). Sources read from the Linux history tree at commit 381ab1f5 (v2.5.0): `arch/ia64/sn/fprom/{main.c,fpromasm.S,fpmem.c,fw-emu.c,README,fprom.lds}`, `include/asm-ia64/sn/{synergy.h,sn_cpuid.h}`, `arch/ia64/sn/sn1/{smp.c,irq.c}`, `arch/ia64/config.in`, `arch/ia64/sn/io/klgraph_hack.c`. Tag commit ids checked with `git ls-remote --tags` on kernel.org's history.git (v2.5.0 381ab1f5, v2.5.6 50b1b006, v2.5.7 085c9a18, v2.5.40 7570df54, v2.5.72 1eba1937, v2.5.73 6c7a48fb). Press pages fetched 2026-11-14.

Checks, confirmed: every offset in the table (`0x2a0` to `0x2d8` mask pairs named VEC_MASK3A..0B, perf registers `0xab0` to `0xaf8`) against `synergy.h`; `SSPEC_BASE 0xe0000000000`; the remote window arithmetic (`HSPEC_BASE`, `NODE_OFFSET` at `<<33`, `+0x30000000`, Synergy 0 and 1 at `0x04000000` and `0x05000000`); the four-store remote write and one-load remote read; the "which fsb?" comments; `FSB_CONFIG` at `0x450` written as `(nasid<<16)|(syn<<9)` after eight all-ones stores at `0x2a0..0x2d8` (comment "Set the NASID in the FSB_CONFIG register"); base `0x80000e0000000000`; the LID layout (id 31:24, eid bit 17 Synergy, bit 16 slot) and `cpu_physical_id_to_synergy` in `sn_cpuid.h`. The page grades the field meanings of `0x450` inferred and every other bit unknown, which is right.

Findings:
1. Mechanical, fixed: the page said the 128 pending bits arrive as vectors 64 to 191; `bit_pos_to_irq` clamps bits above 118, so the highest vector is 182 (the README already said so).
2. Not edited: `irq_to_bit_pos` subtracts a further 64 for vectors above 127, so a handler for a high vector clears a different pending bit than the one that raised it. That is a defect in the kernel and bears on the interrupt-end path read in [fake-prom.md](fake-prom.md), which describes the clear without noting it.
3. Not checked: the simulator control file reading (`runsim`) beyond the `synergy_cache_type` line quoted, the Bedrock patent statement and the comp.arch post.

Cleared scope: all offsets, address arithmetic, access sequences, the `FSB_CONFIG` written value and the grades on them. Not cleared: the "What it was" interpretation beyond what its grades already say is inferred.

## Review (SN1 IA-64 Synergy and Bedrock differences)

Independent review, 2026-11-15, by a reviewer who wrote none of these pages. Reviewed chips revision 8961c72 (Synergy commits c014b16 and 7fce3c0). Sources read: the Linux/IA-64 project patches `linux-2.4.16-ia64-011126`, `linux-2.4.17-ia64-011226`, `linux-2.4.18-ia64-020410`, `020508`, `020722` and 2.4.0 `test6-000811`, `test10-001101`, `test10-001115`, `test11-001206` (kernel.org ia64 ports directory, read directly, not through Ghidra; no binary claim exists on these pages); and from the Linux history tree at v2.5.0 (`381ab1f5`): `include/asm-ia64/sn/{synergy.h,sn_cpuid.h}`, `include/asm-ia64/sn/sn1/{hubpi.h,ip27config.h,addrs.h}`, `arch/ia64/sn/sn1/{synergy.c,irq.c}`. About 45 facts were checked.

Confirmed: all 20 offsets and names (mask pairs `0x2a0` to `0x2d8`, `0xab0` to `0xaf8`, `0xae0`, `0x330`/`0x338`, `0x450`); `SSPEC_BASE`; remote window arithmetic (`<<33`, `+0x30000000`, `0x04000000`/`0x05000000`, so `0x34000000`/`0x35000000`); remote read at `reg`, write at `reg<<2`; L4 64 MB, 8 ways, 512-byte blocks; the way-walk (write `0xff ^ (1<<way)`, nine aliases 8 MB apart, write 0); the barrier polling `GBL_PERF_B` for `cpuid_to_synergy` true and `GBL_PERF_A` otherwise, after reading the Bedrock revision register, 5 microsecond sleep, comment "wait ... to clear"; bit 45 enable; 40-bit counter mask; `FSB_CONFIG` write value and the all-ones mask writes (offsets `0x2a0` to `0x2d8`) before it; vectors 65 and 182, their handlers' bit lists, `bit_pos_to_irq` clamp, 2.4.18 `irq_to_bit_pos` (plain minus 64) against the v2.5.0 one (minus 64 again above 127); the Synergy-mode comment (SysAD bit 52) and "bit 8 ... synergy mode bit"; junk-bus defaults `0xff`/`0xff`, `0x0c`/`0x02`, `0x10`/`0x10`; address pairs `0xc0000a`/`0xc0000b` and `0xc00002`/`0xc00003`, the bit 43 clear on the PCI ROM address, and the `^4` register structures; `runsim` settings (`swizzling on`, `syn_cac_64m_8w`, `cpu_stepping A`); `0xae0` absent from 2.4.0-test10 and present from 2.4.16; `0x330`/`0x338` absent from 2.4.16 and 2.4.17 and present from 2.4.18-020410; test10-001115 the first patch adding `arch/ia64/sn/` files. The generated tree is current and `ci-check` exits 0.

Mechanical fixes: remote write described as "16 bits each" although the stores are `value>>48`, `>>32`, `>>16`, `value` unmasked (the 16-bit width is now marked inferred, in this page, the unit README and the register notes); the open question said 17 known offsets, now 20; "first to carry" test10 now "first to add" (test6 edits three existing files); the `fc` row now marks "local FSB" as the comment's words and the local L4 as inferred; the `0x330` note no longer states the nonzero polarity as fact (the loop waits for nonzero, the comment says clear).

Findings not fixed (change meaning): the performance register `A`/`B` pairing. The header labels both `CNTL0_A/B` and `CNTR0_A/B` as FSB0 and `*1_*` as FSB1, but the kernel reads and writes `*0_A` through Synergy 0 and `*0_B` through Synergy 1, so `B` may mean Synergy 1; recorded in the register notes and above as unknown. Separately, the SN1 `snia_error_intr_handler` and the nonzero-versus-"clear" barrier polarity remain kernel-code oddities; neither changes a register offset.

Not checked: Ghidra readings (none apply); the Bedrock patent statement and the junk-bus 16-bit write inference; Usenet, Linux Journal and kernel mail citations; 2.4.0-test10 beyond the presence of the mask registers and `FSB_CONFIG` write; the sn_cpuid LID bit layout beyond the v2.5.0 macros (`synergy = (physical id >> 1) & 1`, slot = bit 0, NASID = `>> 8` of the physical id), which agree with the page.

Cleared scope: all offsets, access sequences, constants, grades on the register unit, and the Synergy rows of the platform README. Not cleared: "What it was", beyond its inferred grades.
