# Synergy: the Itanium processor-bus ASIC on an SN1 IA-64 node

Synergy is the chip between a Bedrock processor interface and an Itanium front-side bus. It exists only on the IA-64
node; the MIPS Origin 3000 node connects R12000s to the Bedrock directly. No specification is held, and no document found
(Library mail, TechPubs, or the public web) names or describes the chip outside the Linux source. Everything here comes from
SGI's Linux port (`include/asm-ia64/sn/synergy.h`, `arch/ia64/sn/sn1/synergy.c`, `sn1/irq.c`, `sn_cpuid.h`,
`nodepda.h`, v2.5.0 snapshot; `include/asm-ia64/sn/sn1/synergy.h` and `arch/ia64/sn/kernel/sn1/synergy.c` from v2.5.7 to
v2.5.72, same content with small edits) and one cross-check in the Bedrock memory page. The platform context is in
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
| The remote path (through the Bedrock's hub special space, four 16-bit-sized stores per write) differs from the local path (one 64-bit store). Both reach the same registers. A consistent explanation: the local path is a front-side-bus access to the chip, the remote path goes through the Bedrock and the junk bus that carries 16-bit writes. | inferred | `synergy.h`; [devices/bedrock_md](../../devices/bedrock_md/registers.toml) `junk_bus_timing` |
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

How the mask registers are used (`synergy_intr_connect` and `setclear_mask_a` and `_b`): an interrupt for processor `p` is
enabled by setting its bit in the A register when `p` is in slot 0 and the B register when `p` is in slot 1, and clearing
the same bit in the other register. The vector number is `irq`, where `irq = Bedrock pending bit + 64`, so the Bedrock's 128
pending bits arrive as vectors 64 to 191. Vectors outside 64 to 191 are not generated by anything the code shows.

Remote writes are not one store. `__remote_synergy_out` writes four 64-bit stores to consecutive 8-byte addresses starting at
`reg << 2`, carrying value bits 63:48, 47:32, 31:16 and 15:0 in that order, then issues `mf.a`. A remote read loads one 64-bit word
at `reg` with no shift. A local write is one 64-bit store followed by `mf.a`. The split matches the Bedrock patent's statement
that junk-bus devices take 64-bit reads and 16-bit writes ([platforms/ip35/boot-flash.md](../ip35/boot-flash.md)), which is an inference for
Synergy: the patent names the flash. Whether the remote read and write offsets really differ by a factor of four, or the
code has a defect on one side, is not stated.

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
- Which Itanium. First-generation Itanium (Merced). SGI's own account of the Linux bring-up says the prototype hardware
  used first-generation Itanium processors and that a 32-processor Itanium system ran by early 2001 (S. Neuner, "Scaling
  Linux to New Heights: the SGI Altix 3000 System", Linux Journal, 2003-02-01, linuxjournal.com/article/6440); the Linux code
  of the time is the only SGI IA-64 code that carries the Synergy driver; the simulator ran with `cpu_stepping A`; the kernel
  menu offers McKinley as a processor type only as a generic choice. No source states "Merced" beside "Synergy", so
  the identification is inferred.
- Registers beyond the known ones. Only the 8 mask registers, 8 performance registers and `FSB_CONFIG` are known. Nothing
  else was found in the Library, in kernel mail (2000 to 2003), or on the web.

## Not known

Everything else: the `FSB_CONFIG` bits other than the two written fields, reset values, the other register offsets, the per-processor error and ECC logic, coherence and snoop
control, the interface to the Bedrock PI (processor-bus command encodings), the interrupt priority and inter-processor
interrupt path through Synergy, and the meaning of the A and B performance event selectors. The open entry is in
[questions/sn1-ia64-synergy-registers.md](../../questions/sn1-ia64-synergy-registers.md). What a bring-up needs from Synergy is in
[bring-up.md](bring-up.md).
