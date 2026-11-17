# SN1 on IA-64 (Bedrock node with Itanium processors)

In 2000 to 2003 SGI ran Linux on a node that is the Origin 3000 node with Itaniums in place of R12000s: the same Bedrock
hub chip, the same Crosstalk I/O, the same routers and L1 controllers, and a new processor-side ASIC (Synergy) between
the Bedrock's processor interfaces and the Itanium buses. The Linux code calls it SN1, SNIA or SNI64 and the board
IP35 (the headers also say IP37). This page says what the code establishes about that machine and how its view of the
chips differs from the MIPS view the rest of this repository takes. The files and their versions are listed in
[references/sn1-ia64-sources.md](../../references/sn1-ia64-sources.md); paths below are from the Linux v2.5.0 snapshot
unless a version is given. The processor-bus ASIC has its own page: [synergy.md](synergy.md). The fake PROM SGI's simulator ran, with the kernel tags and configuration it was built for, is in [fake-prom.md](fake-prom.md).

Grades follow the repository rules. SGI's own Linux platform code is vendor source, so what it defines is
`established`; what it only implies is `inferred`. Where the code is the only witness and it is written for a
simulator, the line says so.

## What a node was

| Item | What the code says | Grade |
|---|---|---|
| Node controller | One Bedrock per node. Chip part `0x3012` (`LRI_CHIPID`), crosstalk widget part `0xc110` for its I/O interface (`HUB_WIDGET_PART_NUM`). Both agree with the values the Bedrock pages already carry from the MIPS side. | established |
| Processor interfaces | Two PIs per Bedrock, two processors per PI: `NUM_SUBNODES 2`, `SUBNODE_SHFT 1` in `sn1/arch.h`, "4 cpus per node" in `arch.h`. The code calls a processor's position its slice (0 to 3). Slices 0 and 1 sit on PI0, 2 and 3 on PI1 (`cpuid_to_subnode`). | established |
| Processor bus | Each PI faces one Synergy ASIC. Each Synergy has one front-side bus with two Itanium slots. `sn_cpuid.h` draws it: CPU, slice, FSB slot, Synergy, Bedrock. The processor's LID register carries the NASID in `id` (bits 31:24) and the slice in `eid`: bit 17 selects the Synergy, bit 16 the FSB slot. | established |
| Processor | Itanium. `arch/ia64/config.in` offers Itanium and McKinley as processor types, and the 128-byte cache-line alignment (`CONFIG_IA64_L1_CACHE_SHIFT 7`) is written under the SN1 and Itanium branch, matching the Bedrock's 128-byte line. The hardware was first-generation Itanium (Merced): SGI's own account says its prototype hardware used first-generation Itanium processors (see "Product or prototype"). Which stepping is not stated (the code only says A1-step support was dropped from the ia64 tree in December 2000; the simulator ran with `cpu_stepping A`). | established for the 128-byte line; established for first-generation Itanium on the prototypes (source does not name SN1); unknown for the stepping |
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
  four CPUs per node, two per FSB, and builds the memory map from a per-node bank table the simulator writes into memory. Its own README says it will be replaced by the
  real PROM. What a real SN1 PROM returned for these values is unknown. What the fake PROM does, builds and expects is in [fake-prom.md](fake-prom.md).

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
| Uncached views | One uncached view per space | Each I/O and hub-special space has an unswizzled view (physical bit 43 set, `0xc0000a...`, `0xc0000b...`) and a swizzled one (bit 43 clear). The kernel uses the unswizzled view and XORs 32-bit register offsets with 4 ([synergy.md](synergy.md)) |
| Write ordering | Hub uncached-write ordering as the PI page records | Before an I/O barrier the 2.4.18 kernel polls a Synergy register (`0x330`/`0x338`) until nonzero, the code comment calling it the Bedrock PIO write status ([synergy.md](synergy.md)) |
| Error source | Which of the two processor buses raised an error picks CPU A or B | In Bedrock Synergy mode (a PROM mode bit) the source processor comes from bit 52 of the SysAD bus in every command, supplied by Synergy ([synergy.md](synergy.md)) |
| Console | L1 and Bedrock UART | L1 protocol by default; with it off, a 16550-style console at the remote register space +0x80 with an 8-byte register stride (see [the question](../../questions/sn1-ia64-bedrock-uart-location.md)) |

## Product or prototype

Answer: a prototype and development platform. Prototype hardware existed and ran Linux; no source found says any unit was
sold. The evidence, newest reading first:

- SGI's own engineering account (S. Neuner, SGI Linux engineering, "Scaling Linux to New Heights: the SGI Altix 3000 System",
  Linux Journal, 2003-02-01, linuxjournal.com/article/6440, fetched 2026-11-14). SGI "developed and used simulators extensively
  for both the system firmware and kernel development"; kernel work used "the first-generation Itanium processors for
  making the CPU scaling, I/O performance and other changes"; "By early 2001, we had succeeded in running a
  32-processor Itanium-based system - the first of its kind"; "When the original prototype hardware based on first-generation
  Itanium processors arrived, it was time for power-on", ending in "taking a processor out of reset, then fetching and
  executing the first instructions from PROM". The article does not say SN1 or Merced. That this hardware is the Bedrock-and-Synergy node is
  inferred: the SN1 code is the only SGI Itanium platform code of that period and runs with the first-generation
  processor. Grade: established that prototype Itanium 1 hardware existed and ran Linux; inferred that it was SN1.
- Press, secondhand. HPCwire 2003-01-10, "SGI Ups the Ante in High-Performance Linux Computing", reported through a search
  result because the page refused a direct fetch (HTTP 403): "An SN1 version of Altix, based on Itanium 1 (Merced) and Linux,
  never made it to market because of the Intel chip's weak performance, and instead was used for software development." Enterprise Systems Journal, 2003-01-09
  (esj.com/articles/2003/01/09/sgi-unveils-64way-linux-supercomputers.aspx): SGI "also introduced a system based on Intel's
  first-generation Itanium processor", and "its Itanium 1 system was developed for the most part as a prototype". Grade: inferred;
  these are journalists' summaries and the second leaves open that a handful of units were announced or placed.
- Plans and delays. Computerworld, 2001-03-16 ("SGI to offer Linux-based IA-64 Origin computer", computerworld.com/article/1450041):
  the chief executive says SGI will offer the Origin 3000 with an Itanium and Linux "once Intel has Itanium IA-64 in the market
  under general availability". No date; the piece names no prototype. A former SGI product manager's 2009 retrospective
  (HPCwire 2009-04-10, "How It All Went Wrong for SGI in HPC") says the follow-on to the Origin 3000 was "our first systems
  based on Itanium chips. First-generation Itanium chips", that Intel "delayed it, then delayed it again" and "We retooled
  for McKinley, also delayed", without naming SN1. An anonymous Slashdot comment of 2001-12-29 (comment 2761768) says "SN-IA is
  still a product on the roadmap, but nobody is working on it" and "maybe after McKinley"; unattributed, so it is weak
  support for the same picture.
- SGI's kernel work. The ia64 maintainer's mail of 2000-12-14 lists "various SGI SN1 updates"; the SN1 option in the
  Linux ia64 config menu read "SN1-simulator For the SGI SN1 simulator" until its removal (mail of 2003-05-19, `marc-linux-ia64-105590723705952`); the only firmware in the tree is the
  simulator's fake PROM, whose source says "we need this in the simulator only. Once we run on real hw, this can all go away"; the kernel carries `BRINGUP`
  conditionals and an error handler that panics on most error interrupts with the comment "this is bring up". By 2003-02-05 the 2.4 `MAINTAINERS` entry for the
  Itanium SN sub-platform pointed to SGI's Altix web page (mail of that date). SN2 replaced SN1 in the same directory by mid-2003 and the Kconfig help changed from the simulator to "SGI Altix systems".
- What shipped instead: SGI Altix 3000 (SN2: Itanium 2 and the SHub controller), announced
  2003-01-07 (CBR/Tech Monitor, 2003-01-07, "SGI launches 64-Way Linux-Itanium super for big clusters"; the SN2 pages
  under [../sn2/](../sn2/README.md) carry the machine itself).

Not found anywhere: a price list, an order, a customer, a serial number, or a field report of an SN1 IA-64 system outside SGI. The
first-person SGI account makes "prototype" safe; "never sold" rests on a secondhand sentence and on absence, so it stays
inferred. A detailed question remains in
[questions/sn1-ia64-shipped-or-prototype.md](../../questions/sn1-ia64-shipped-or-prototype.md).

## Open items

- Synergy register contract beyond the few registers the kernel touches: [synergy.md](synergy.md) and
  [questions/sn1-ia64-synergy-registers.md](../../questions/sn1-ia64-synergy-registers.md).
- Where the Bedrock UART sits on real hardware: [questions/sn1-ia64-bedrock-uart-location.md](../../questions/sn1-ia64-bedrock-uart-location.md).
- Whether any SN1 IA-64 unit left SGI, and which Itanium stepping the prototypes used: [questions/sn1-ia64-shipped-or-prototype.md](../../questions/sn1-ia64-shipped-or-prototype.md).
- What the simulator answered for the Bridge and XBridge during the kernel's I/O initialisation, and the other open points of the fake PROM page: [fake-prom.md](fake-prom.md#5-open-points).

## Review

Independent review, 2026-11-14, by a reviewer who wrote none of these pages. Reviewed chips revision a399d6d (pages from 842b367, 55a5bcc, f5ab671 and the earlier SN1 IA-64 commits through 15a5a4e). Sources read from the Library root `linux-history` at commit 381ab1f5 (v2.5.0) with `read_library`: `arch/ia64/sn/fprom/{main.c,fpromasm.S,fpmem.c,fw-emu.c,README,fprom.lds}`, `include/asm-ia64/sn/{synergy.h,sn_cpuid.h}`, `arch/ia64/sn/sn1/{smp.c,irq.c}`, `arch/ia64/config.in`, `arch/ia64/sn/io/klgraph_hack.c`. Tag commit ids checked with `git ls-remote --tags` on kernel.org's history.git (v2.5.0 381ab1f5, v2.5.6 50b1b006, v2.5.7 085c9a18, v2.5.40 7570df54, v2.5.72 1eba1937, v2.5.73 6c7a48fb). Press pages fetched 2026-11-14.

Checks, confirmed: `LRI_CHIPID`-style values were not re-read (they come from earlier reviewed pages); LID layout; the IPI path (`sn1_send_IPI`: `0xc0000a0000000000 | nasid<<33 | {0x1800080, 0x1800088, 0x1a00080, 0x1a00088}[slice]`, store of `(delivery_mode<<8)|(vector&0xff)`), which gives `ipi_a` at PI `+0x80` for slices 0 and 2 and `ipi_b` at `+0x88` for slices 1 and 3, PI1 two megabytes above PI0; `irq = bit + 64` with the clamp at 118 (`irq.c`); `PTC_NOTYET` compiled out in `smp.c`; the config choices in `config.in` (`CONFIG_IA64_SGI_SN1` with menu text "SGI-SN1", Itanium and McKinley processor types, `CONFIG_IA64_L1_CACHE_SHIFT 7` under SN1 and Itanium, L1 protocol default y). Product-or-prototype sources: Linux Journal, S. Neuner, 2003-02-01 (fetched; the quoted sentences about simulators, first-generation Itanium prototype hardware, the 32-processor system by early 2001 and the power-on step are verbatim; it names neither SN1 nor Merced, as the page says); Enterprise Systems Journal 2003-01-09 (verbatim "also introduced a system based on Intel's first-generation Itanium processor" and "developed for the most part as a prototype", by Stephen Swoyer); Computerworld 2001-03-16 (verbatim "Once Intel has Itanium IA-64 in the market under general availability ..."; the speaker is the chairman and CEO). HPCwire 2003-01-10 returned HTTP 403 here too, so the quotation stays marked secondhand and graded inferred, as the page does. The grades follow the evidence: established for prototype hardware (first-person SGI account), inferred for its being SN1 and for "never sold".

Findings: none needing edits. Not checked: the marc-linux-ia64 and ratatoskr mail ids, the Slashdot comment, the HPCwire 2009 retrospective and the CBR piece.

Cleared scope: node description, address map, interrupt and IPI paths, firmware-interface summary and the product-or-prototype grading. Not cleared: the cited mail and secondary press items listed above.
