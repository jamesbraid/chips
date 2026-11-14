# SN1 on IA-64 (Bedrock node with Itanium processors)

In 2000 to 2003 SGI ran Linux on a node that is the Origin 3000 node with Itaniums in place of R12000s: the same Bedrock
hub chip, the same Crosstalk I/O, the same routers and L1 controllers, and a new processor-side ASIC (Synergy) between
the Bedrock's processor interfaces and the Itanium buses. The Linux code calls it SN1, SNIA or SNI64 and the board
IP35 (the headers also say IP37). This page says what the code establishes about that machine and how its view of the
chips differs from the MIPS view the rest of this repository takes. The files and their versions are listed in
[evidence/sn1-ia64-sources.md](../../evidence/sn1-ia64-sources.md); paths below are from the Linux v2.5.0 snapshot
unless a version is given. The processor-bus ASIC has its own page: [synergy.md](synergy.md).

Grades follow the repository rules. SGI's own Linux platform code is vendor source, so what it defines is
`established`; what it only implies is `inferred`. Where the code is the only witness and it is written for a
simulator, the line says so.

## What a node was

| Item | What the code says | Grade |
|---|---|---|
| Node controller | One Bedrock per node. Chip part `0x3012` (`LRI_CHIPID`), crosstalk widget part `0xc110` for its I/O interface (`HUB_WIDGET_PART_NUM`). Both agree with the values the Bedrock pages already carry from the MIPS side. | established |
| Processor interfaces | Two PIs per Bedrock, two processors per PI: `NUM_SUBNODES 2`, `SUBNODE_SHFT 1` in `sn1/arch.h`, "4 cpus per node" in `arch.h`. The code calls a processor's position its slice (0 to 3). Slices 0 and 1 sit on PI0, 2 and 3 on PI1 (`cpuid_to_subnode`). | established |
| Processor bus | Each PI faces one Synergy ASIC. Each Synergy has one front-side bus with two Itanium slots. `sn_cpuid.h` draws it: CPU, slice, FSB slot, Synergy, Bedrock. The processor's LID register carries the NASID in `id` (bits 31:24) and the slice in `eid`: bit 17 selects the Synergy, bit 16 the FSB slot. | established |
| Processor | Itanium. `arch/ia64/config.in` offers Itanium and McKinley as processor types, and the 128-byte cache-line alignment (`CONFIG_IA64_L1_CACHE_SHIFT 7`) is written under the SN1 and Itanium branch, matching the Bedrock's 128-byte line. Which Itanium stepping was used is not stated (the code only says A1-step support was dropped from the ia64 tree in December 2000). | established for the 128-byte line; unknown for the stepping |
| Memory | Eight banks per node, bank `n` starts at node offset `n` GB. Bank sizes 64 MB, 128, 256, 512 MB and 1 GB (size nibble 1 to 5), banks paired two per size nibble (`node_memmap_t`). A node's address space is 8 GB (`NODE_SIZE_BITS 33`). The same memory-bank encoding the Bedrock memory page already records. `SN1_MIN_BANK_SIZE_SHIFT` is 64 MB. The fake PROM README says SN1 supports no smaller DIMMs; the simulator build accepts 8 to 32 MB nodes for faster boots. | established |
| I/O | Crosstalk widgets through the Bedrock's I/O interface, reached by 16 MB small windows (`SWIN_SIZE_BITS 24`) and big windows. The code handles an XBow crossbar (part `0x0`), Bridge (`0xc002`) and XBridge (`0xd002`; its crossbar part is `0xd000`). IOC3 is the on-board I/O chip (`ioc3.h`). No PIC, no TIO and no IOC4 appear anywhere in the SN1 files. | established |
| Network | Bedrock NI to SN1 routers, up to eight ports per router (`MAX_ROUTER_PORTS`), meta-routers and repeater routers present in the KLCONFIG class list. The router register layout in `sn1/router.h` is the one the router page records. | established |
| System controller | L1 (ELSC and later L1 protocol): `ksys/l1.h`, `io/l1.c`, `io/l1_command.c`. Brick types C, R, I, K, X, D, P as on the MIPS machines (`module.h`, `L1_BRICKTYPE_*`). `CONFIG_SERIAL_SGI_L1_PROTOCOL` defaults on: the console goes through the L1. | established |
| Limits | 128 NASIDs and 128 compact nodes, 512 CPUs, 64 regions (`sn1/arch.h`). M-mode only: the IA-64 `arch.h` stops with an error under N-mode. | established |
| Partitioning | `sn_fix_ivt_for_partitioned_system` rewrites the NASID into the vector table's hard-coded physical addresses because partitions other than the first have no physical address 0. So partitioned systems were designed for. | established for the design; whether one ran is unknown |

## Address map: the IA-64 view

`sn1/addrs.h` and `addrs.h` are the MIPS IP35 files with different region bases. The node arithmetic is identical: node
`n` occupies 8 GB at `n << 33` (M-mode), the NASID is 7 bits, and each node's window holds the same uncached spaces. Only the
way a processor names them changes.

| Space | IA-64 base (`CAC_BASE` etc.) | Notes |
|---|---|---|
| Cached memory | `0xe000000000000000` (region 7) | The Itanium identity-mapped cached region; MIPS uses cached XKPHYS. |
| Memory special (MSPEC), uncached memory | `0xc000000000000000` (region 6) | `MSPEC_BASE`, `UNCAC_BASE`. |
| I/O (Crosstalk widgets) | `0xc0000a0000000000` | `IO_BASE`; swizzled alias `0xc000020000000000`. |
| Hub special (HSPEC) | `0xc0000b0000000000` | `HSPEC_BASE`; swizzled alias `0xc000030000000000`. Inside it, as on the MIPS side: position-independent alias at +0, local registers at +0x10000000 (128 MB), local boot space at +0x18000000, another node's registers at +0x30000000 and its boot space at +0x38000000. |

Hub registers: `LOCAL_HUB_ADDR` is the small window of widget 1 (`IALIAS_BASE`, 8 MB); a remote node's hub registers are at
widget 1's window plus `0x800000` on that node. So PI0's registers are at `IO_BASE | nasid << 33 | 0x1800000` and PI1's are
2 MB higher, which is what the Bedrock processor-interface page says about PI1.

The Itanium tree names the same regions as MIPS KLDIR, KLCONFIG and the global data area (`KLDIR_OFFSET 0x2000`,
`ARCS_SPB_OFFSET 0x1000`), so the PROM data structures the Bedrock pages describe from the IRIX side are the structures the
Linux code walks. The ARCS and KLCONFIG data are the same; what differs is the Itanium firmware interface around them.

## Interrupts and inter-processor interrupts

- Bedrock's pending bits are the same ones IRIX uses. `intr.h` names them: levels 1 and 2 graphics, 3 page migration, 4 UART,
  5 and 6 cross-call, 36-37 debug, 41-42 LLP power fail, 43-44 TLB, 45-52 reserved for the PROM, 54-55 crossbar and local-block
  error, 56-57 NACK, 59-60 correctable error. These names also appear in the Bedrock processor-interface page.
- The IA-64 kernel turns a pending bit into an interrupt vector with `irq = bit + 64` (bit numbers above 118 clamp to 118) and
  clears the bit at the end of the handler (`sn1/irq.c`). The Synergy ASIC holds 256 vector-mask bits in four 64-bit pairs per
  side (A and B), selected per processor; see [synergy.md](synergy.md).
- An inter-processor interrupt is a 64-bit store to PI base `+0x80` (slice A of a PI) or `+0x88` (slice B), value
  `(delivery_mode << 8) | vector` (`sn1/smp.c`, `sn1_send_IPI`; offsets `0x1800080`, `0x1800088`, `0x1a00080`, `0x1a00088`).
  The Bedrock register headers do not define those two registers. They are recorded in the PI register page as `ipi_a` and
  `ipi_b`, with the source named there.

## Firmware interface

The Linux tree contains no PROM source for the Itanium node; the firmware is the PROM that builds the same KLCONFIG as on the MIPS machines. What the kernel expects of it:

- SAL, PAL and EFI as on any Itanium: SAL system table with entry-point and AP-wakeup descriptors, `ia64_bootparam`
  with the CPU and memory map, an ACPI-style LSAPIC list, a SAL PTC-domain descriptor (the kernel forces uniprocessor mode if
  it is absent).
- Three SGI SAL calls only (`sn_sal.h`): `SN_SAL_POD_MODE` `0x02000001`, `SN_SAL_SYSTEM_RESET` `0x02000002`, `SN_SAL_PROBE`
  `0x02000003` (read an address and survive a bus error: status 0 ok, 1 machine check, 2 bad argument).
- Secondary processors are started through the SAL OS boot rendezvous vector (`SAL_VECTOR_OS_BOOT_RENDEZ`).
- The only firmware in the tree is a fake PROM for SGI's Medusa simulator (`arch/ia64/sn/fprom/`, renamed `fakeprom` in
  2.5.7). It reports 500 MHz as the platform base frequency and 700 MHz for the interval timer, 128 nodes and 512 CPUs at most,
  four CPUs per node, two per FSB, and builds the memory map from per-node bank words. Its own README says it will be replaced by the
  real PROM. What a real SN1 PROM returned for these values is unknown.

## How this differs from the MIPS view

| Topic | MIPS Origin 3000 view (chips) | IA-64 SN1 view |
|---|---|---|
| Processors | R10000 family, two per PI on the system bus | Itanium, two per Synergy bus, Synergy behind each PI |
| Cache line | 128 bytes | 128 bytes (`L1_CACHE_SHIFT 7`) |
| Address names | XKPHYS: `0x9200...` registers, `0x90...` uncached | Regions 6 and 7: `0xc0000b...` HSPEC, `0xc0000a...` I/O, `0xe000...` cached |
| Interrupt delivery | Bedrock pending bits, enabled by the PI interrupt masks, raise the processor's interrupt lines (see the PI page) | Pending bit, then the Synergy vector mask, then an Itanium vector (`bit + 64`) |
| IPI | PI cross-call pending set and clear | A store to PI `+0x80` or `+0x88` carrying delivery mode and vector |
| TLB flush | Cross-processor interrupt on the TLB levels (43 and 44) | The code to use SAL-reported global-purge domains is compiled out (`PTC_NOTYET`); flushes use cross calls |
| Firmware | ARCS PROM | SAL, PAL and EFI front end over the same PROM data |
| Console | L1 and Bedrock UART | L1 protocol by default; with it off, a 16550-style console at the remote register space +0x80 with an 8-byte register stride (see [the question](../../questions/sn1-ia64-bedrock-uart-location.md)) |

## Product or prototype

The sources do not settle it. Evidence on each side:

- Prototype or bring-up: the ia64 Kconfig help for the SN1 choice read "SN1-simulator For the SGI SN1 simulator"
  (quoted in mail of 2003-05-19). The only firmware shipped in the tree is a simulator fake PROM whose source says "we
  need this in the simulator only. Once we run on real hw, this can all go away." The kernel README boots only under
  Medusa. Platform set-up carries `BRINGUP` conditionals. The error handler panics on most error interrupts with
  the comment "this is bring up".
- Real hardware was in view: the L1 console protocol, the SAL PTC-domain query, the Synergy performance-counter
  sampling (counters multiplexed from the timer, a `/proc/synergy` file) and a note about statistics from "a running
  system" are all hardware-facing. Mail of December 2000 reports "various SGI SN1 updates" in the ia64 patch.
- SGI's later IA-64 machine, called SN2 in the code, replaced SN1 in the same directory by mid-2003, and the Kconfig help for
  the choice changed from the simulator to "SGI Altix systems". No file or mail held here says SN1 hardware was sold.

So: the code is a vendor Linux port that was exercised in a simulator and probably on prototype hardware. Whether any
customer shipped is unknown. A question names what would settle it.

## Open items

- Synergy register contract beyond the few registers the kernel touches: [synergy.md](synergy.md) and
  [questions/sn1-ia64-synergy-registers.md](../../questions/sn1-ia64-synergy-registers.md).
- Where the Bedrock UART sits on real hardware: [questions/sn1-ia64-bedrock-uart-location.md](../../questions/sn1-ia64-bedrock-uart-location.md).
- Whether SN1 IA-64 hardware shipped, and which Itanium revision it used: [questions/sn1-ia64-shipped-or-prototype.md](../../questions/sn1-ia64-shipped-or-prototype.md).
