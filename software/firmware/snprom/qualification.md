# First-target firmware qualification

Which real SGI PROM image, and which minimal machine, an emulator should boot first: no synthetic firmware, no patched
firmware, no skipped diagnostics, no invented success. The end goal is the Prism (IP57 node board, SHub 1.2 where a
manual names it); the Altix 350 shares that node board and is the smaller machine. This page only qualifies. It adds no
register facts: those live in [the firmware page](README.md), [the boot-path page](altix350-boot-path.md) and the
device pages. It has not had an independent review.

**Grades.** *established*: read in full in a shipped binary or printed in a published manual. *inferred*: reasoned,
with the reasoning given. *unknown*: not settled, with the route that would settle it.

**What was re-checked for this page** (chips root `sn2/`, binutils `ia64-linux-gnu-objdump` through
`retools/tools/re-run`, nothing copied): the sha256 of every candidate image (all matched `SHA256SUMS`, 25 of 25 lines
clean); the FIT and top-of-image words of the SHub images; the SAL banner and build time of each; the
processor-stepping rows in each SHub 1 SAL_A; the SAL_A 5.04 node set-up and progress-register constants; the SAL_B
reset entry and the call order of `main()`; the UART window constants in SAL_B; the decompressed EFI strings of the three
SHub 1 images; `IP57` and `Prism` string counts. The manual pages cited were re-read in the Library `techpubs` root.
Everything else is taken from the pages named, at the commits named.

Pages synthesised (chips `c567510`, sysco `5d62fbd`):
[snprom README](README.md) (`1579f00`), [boot path](altix350-boot-path.md) (`c567510`),
[SN2 holdings](../../../evidence/sn2-holdings.md) (`c4a3255`),
[irix-files](../../../evidence/irix-files.md#sn2-firmware-and-kernels) (`ec38a7e`),
[Altix 350](../../../platforms/sn2/altix-350.md) and [Altix 3000](../../../platforms/sn2/altix-3000.md) (`94c62dd`),
[Prism](../../../platforms/sn2/prism.md) (`06bdc20`), and in sysco `software/firmware/l1/sn2-prom-link-1.62.1.md`
(`5d62fbd`) and `sn2-l1-1.62.1-packages.md` (`8ceefe9`).

## Decision in brief

- **Image:** `shub1snprom.bin` from snprom 10.54 build 70399, SAL 5.04, sha256
  `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`.
- **Machine:** one Altix 350 base compute module: one IP57 node (one SHub 1, one Itanium 2), memory in group 0, the PIC
  on the PCI riser, an IOC4-based base I/O card in riser slot 1, an L1 peer. No router, no second node.
- **Not ready to boot.** Image and machine are chosen. The blockers in section 9 (PAL, SHub, L1, memory, I/O) are open
  readings or missing contracts, not choices.

## 1. Candidate images

All hashes were recomputed with `sha256sum` on the files under `root/sn2/` and match the values chips records. The
container row is what the pages record; a container hash is a different thing from the image hash and is treated
separately below.

| | `snprom.bin` | `shub1snprom.bin` | `shub1snprom.bin` | `shub2snprom.bin` | `ip65prom.bin` |
|---|---|---|---|---|---|
| Package | snprom 4.43 build 44607 | snprom 10.40 build 62478 | snprom 10.54 build 70399 | snprom 10.40 build 62478 | snprom 10.11 build 52277 |
| Container recorded | `snprom-4.43-44607.ia64.rpm`, ProPack 4 SP3 CD 2 | `snprom-10.40-62478.ia64.rpm`, ProPack 4 SP4 CD 2 | `snprom-10.54-70399.ia64.rpm`, package mirror | same rpm as 4.90 | `snprom-10.11-52277.ia64.rpm`, package mirror |
| SAL banner | 4.43 rel051202 IP41 | 4.90 rel071217 IP41 | 5.04 rel081111 IP41 | 1.40 rel071217 IP65 | 1.11 (IP65) |
| Built | 2005-12-02 14:14:24 | 2007-12-17 06:06:11 | 2008-11-11 07:25:21 | 2007-12-17 06:08:32 | 2006-10-18 (firmware page; banner not re-read here) |
| Size (bytes) | 6291456 | 6291456 | 6291456 | 12582912 | 12582912 |
| sha256 (re-hashed) | `035274812b5065bde3f1b3227a23c05637d8a13f7cab7736ddde4718d46f02eb` | `26170cc83c3db243601da8f55610bcdd6bb408136c3b3d19b7c4823e491b9a06` | `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617` | `1c8144e3d318f71a7633dddc268c3ebd0f64febb87c2f234a9a917df0673dd77` | `372e74f7201d35e56ef871c330ccbd66fda9f921376ae5dd3045cf4ae6319199` |

Banner, build time and size: established (strings and FIT read by me). The 10.54 package also ships a
`shub2snprom.bin` (`3ea83318...`, SAL not read) and SGI's `README.snprom` (`00f0a21d...`, re-hashed).

**Container hash.** No hash of any rpm container is recorded in chips or sysco, and
[irix-files](../../../evidence/irix-files.md#sn2-firmware-and-kernels) says the container name of most images was not
recorded when the files were copied. A Library search for the 10.54 rpm file name found nothing. So there is no
metadata-verified container hash to cite: **unknown**. The route is to hash the rpm in the owner's package mirror and
check it against the rpm header. Until then the image hash is the only identity, and nobody can tie it to a specific
download.

**Why the SHub 2 builds do not apply (established).** `shub2snprom.bin` and `ip65prom.bin` are built for the CPU board
`IP65` with SHub 2.0, carry the string `SHUB2 does not support XIO I/O.`, and SGI's `README.snprom` lists them for the
Altix 4700 and 450 only. The Altix 350's PIC sits behind the SHub's XIO link (007-4660-001 p.105, section 2), and the
SHub 2 first stage touches the `0x2_xxxx_xxxx` window, not the SHub 1 window. A SHub 2 machine is a later target.

**Why 4.43 and 4.90 are fallbacks (established for the facts, inferred for the ranking).** `README.snprom` (shipped from
package 10.20) says `shub1snprom.bin` supports Altix 330, 350, 3300, 3700, 3700 Bx2, Prism Rackmount and Prism
Deskside: a vendor statement of intent for the 10.54 package, not evidence that the image boots a given machine. 4.43
predates it. 4.43 also has the only `sysctl_probe` that really probes the controller (a 2,000,000-tick retry) and lacks
`SN_SAL_BTE_RECOVER` and the feature-set calls; 4.90 is the previous build of the 5.04 line. All three SHub 1 images
carry the same three processor rows (section 2) and the same top-of-image block (section 3).

## 2. Machine candidates

**Altix 350, one module (recommended).** One base compute module is a complete system: IP57 node board with one SHub,
one or two Itanium 2, at least four DIMMs (group 0 of three groups of four), four PCI/PCI-X riser slots, a base I/O
card, an L1 on the interface board, no rack, no L2, no router (007-4660-001 pp.69 to 71, 96, 100 to 106;
[Altix 350](../../../platforms/sn2/altix-350.md), established). The PIC ASIC is on the PCI riser card, and the riser has
a nonstandard connector for the IO9 card (007-4660-001 p.105, re-read). The SHub block list names an I/O interface (II),
two network interfaces (NI) and a local block (LB) (007-4660-002 p.112, re-read). The base I/O card is the IO10
(standard) or the IO9 (optional) in the later guide, and the IO9 only in the 2004 guide; it sits in riser slot 1; the
IO10 has serial ATA, the IO9 SCSI (007-4660-002 p.112, re-read). Both cards use an IOC4 (the Linux IOC4 driver, graded
established on the machine page under the repository's evidence rule).

**Altix 3300 plus IX-brick (not first).** The 3300 has up to 12 Itanium 2, one IX-brick, no routers, one power bay and
an optional L2, in a 17U rack (007-4579-001 p.77, re-read; the machine page had not read p.77). Its C-brick is two SHub
nodes joined internally, two processors each (p.99, `altix-3000.md`), so even the smallest 3300 has two SHubs, two
NASIDs and an internal NUMAlink hop. The PROM's node-interconnect phase then reads network registers instead of taking
the single-node skip of section 6, and none of those registers has a contract. The IX-brick adds three PIC adapters and
six PCI-X buses. In its favour, its compute board is the one the images name: banner and build say IP41, and sysco infers
the C-brick reports L1 type `5`, the IP41 board (inferred). Against the Prism goal, it shares the SHub 1 image but not
the node board. It is a second target, after one node boots.

**Supported product, board and CPU, from the images.**

- Product: `README.snprom` (section 1), established as vendor intent. No image contains `IP57`, `Prism` or any model
  name (string counts of 0 in all four SHub images, re-checked). The board string in the images is `IP41` only. The PROM
  does not branch on the compute board name (boot-path review, established): the klconfig name is a fixed string and
  the board EEPROM supplies part, serial and revision. So the same code runs on an IP57 node; what differs is data from
  the L1 and EEPROMs (unknown which).
- Build flags (embedded command line, 4.43 only): `CPUBOARD=IP41`, `IOBOARD=TIO`, `CONFIG_SHUB`, `CONFIG_NL3R`,
  `CONFIG_NL4R`, `CONFIG_TIO`, `SHUB1`, `SN2IA`, `OPUS_P0_WAR` and many `SHUB_*_WAR` workarounds. 4.90 and 5.04 carry
  no command line. Established as strings. That `OPUS_P0_WAR` concerns the 350's node is inferred from sysco reading the
  350 compute module as an "Opus" family board.
- Chip names in the 5.04 SAL runtime: `SHub 1.1`, `SHub 1.2`, `SHub 1.x`, `NL3router` (re-read). SAL_B warns "SHUB 1.1
  present" when it cannot target an interrupt, so 1.1 is a degraded case. Which revision the PROM prefers or rejects is
  not decoded (unknown).
- Processors, all three SHub 1 images (re-read from each SAL_A): three rows keyed by the low word of `cpuid[3]`
  (`0x1f000404`, `0x1f010504`, `0x1f020104`: family `0x1f`, models 0, 1, 2, revisions 4, 5, 1), each followed by two
  version words, 7.31/7.79, 5.37/5.73 and 1.27/2.25 (4.43 has 2.15 in the last). Those numbers equal the PAL_A and PAL_B
  versions in the image's FIT, which supports reading them as minimum versions (inferred). No family `0x20` (Montecito)
  row exists. Names such as Madison come from Intel's numbering, not the image (inferred). A CPU whose `cpuid[3]` is
  outside the rows would fail PAL selection; what the code then does was not read (unknown).
- The 350's Itanium 2 is 1.0 to 1.5 GHz with 1.5, 3 or 6 MB L3 (007-4660-001 p.101). Which of the three rows a given
  part falls in is not stated by any held document (unknown).

## 3. Image composition against flash payload

The 6 MiB file is the flash image. It maps to the top of the 32-bit physical space at `0xffa00000` to `0xffffffff`
(established: the words at `0xffffffe0` and `0xffffffe8` and the FIT addresses). What it holds, 5.04:

| Region | What | Runs from |
|---|---|---|
| FIT at `0x000000`, SAL_B at `0x001000` (2.3 MiB) | SAL_B at `0xffa01000`: reset entry, `main()`, the whole PROM in physical mode | executes in place from flash until the jump to RAM (progress 0x19 to 0x1a, "Copying PROM to RAM") |
| `0x250000` and later | SAL_A (16 KiB, `0xffc4e000`), SAL runtime (gzip, 918,824 bytes expanded), type 0x13 x86-emulation component (gzip), EFI (gzip, 2,495,544 bytes), type 0x22 archive (gzip, tar of three EFI drivers), type 0x23 (672 bytes, empty ELF) | SAL_A in place; the gzip components are expanded into RAM by the PROM or EFI |
| three PAL_B, three PAL_A | processor-specific PAL, chosen by SAL_A | PAL_A first, from reset, in place |
| `0x5f8000` to `0x5fffff` (32 KiB, `0xffff8000`) | a block no FIT entry describes, high-entropy, containing the string "Copyright (C) 2002 Intel Corporation"; the word at `0xffffffd0` points to it; byte-identical in all four SHub images (same hash of the range) | unknown. New observation, not in the firmware page |
| `0xffffffe0`, `0xffffffe8` | FIT pointer and SAL_A entry, both with bit 63 | read at reset (the roles agree with the SAL_A reading; the architectural reading is unread) |

A model must supply the whole file as flash at those addresses, readable. A CFI command interface is needed for the
variable store and PROM log (inferred from `cfi_*` names; the EFI image calls SAL id `0x02000008` for the variable
store). Flash writes are not needed to reach the EFI shell (inferred). Outside FIT components, the non-erased bytes are
the 32 KiB block, 16 bytes at `0xffffffd0`, the FIT pointers and the last 16 bytes (an x86 far jump and a date string;
what reads them is unknown).

## 4. Reset, entry and PAL requirements

- **Reset path (inferred from the pointers).** The processor starts in PAL_A; PAL_A calls SAL_A (address from
  `0xffffffe8`) first with reason 3 (the PAL-pair query), then PAL_B runs, then PAL enters SAL_A with reason 0, which
  scans the FIT and enters SAL_B offset 0. Reasons 1 and 2 (machine check, INIT) go to offsets 0x20 and 0x10. SAL_A's
  side is established (boot-path review). PAL's side is architectural and unread: no Itanium PAL specification was read
  for this page.
- **FIT (established, re-read).** Signature `_FIT_   ` at file offset 0, 13 live entries in 5.04 plus the header and an
  empty slot. Types: 0x01 PAL_B, 0x0e PAL_A, 0x10 SAL_A, 0x11 SAL_B, 0x12 runtime, 0x13, 0x1f EFI, 0x22, 0x23. SAL_A
  checks the signature and a type-0 header and hangs with progress 178 if the scan fails.
- **PAL must be the shipped PAL.** SAL_A reason 3 selects PAL_A and PAL_B by `cpuid[3]` and passes a field back in
  `r37`, makes static PAL call 528 with argument 5, and spins if bit 3 of `r33` is set. A CPU that substitutes its own
  PAL removes these. SAL_B then calls these PAL procedures (boot-path page; my count of direct `r28` immediates in
  SAL_B found the same set: 1, 2, 3, 12, 22, 26, 29, 41, 42, 0x208 and 530, plus whatever the four call wrappers
  carry): 1 CACHE_FLUSH, 2 CACHE_INFO, 3 CACHE_INIT, 4 CACHE_SUMMARY, 9 and 10 BUS_GET/SET_FEATURES, 12 FIXED_ADDR, 14
  FREQ_RATIOS, 17 and 18 PROC_GET/SET_FEATURES, 20 VERSION, 21 MC_CLEAR_LOG, 22 MC_DRAIN, 25 MC_ERROR_INFO, 26
  MC_RESUME, 29 HALT_LIGHT, 30 COPY_INFO, 32 PMI_ENTRYPOINT, 37 MEM_FOR_TEST, 41 PREFETCH_VISIBILITY, 42
  LOGICAL_TO_PHYSICAL, 256 COPY_PAL, 258 TEST_PROC, 259 and 260 CACHE_READ and CACHE_WRITE, and the implementation-specific
  99, 520 (0x208, arguments `0x1000000` and `0x40000`), 528 and 530. Names are Linux `pal.h` numbering (software
  expectation). Wrapper-passed indexes were not all resolved, so this is the static set. The meanings of 99, 520, 528
  and 530 are unknown beyond a guess.
- **RAM at `0x1000000`.** The SAL_B reset entry (`0xffa01000` branches to `0xffa1de00`) writes progress 49 (179 if its
  argument is nonzero), then a table builder (`0xffac42d0`) fills the area at `0x1000000`, then the entry reads
  `[0x1000010 + 8 * slot]` and `[0x1000038]` for its stack and backing store, with translation off (re-read; the
  `[0x1000000 + 8 * (9 + slot)]` read is from the boot-path page). The reads follow the builder's writes, so plain
  read/write memory at `0x1000000` is the requirement. On hardware PAL call 520 preloads 256 KiB of cache there before
  DRAM is up (inferred). An emulator gives ordinary RAM from the first instruction; that is a model choice, not a
  firmware fact.
- **Interrupt vectors in flash.** The SHub 2 build installs its table from flash at `0xff5c0000`; the 5.04 address was
  not re-read. Whether the CPU model needs flash executable with translation on is unknown.

## 5. First hardware-access prefix: reset to the first L1 exchange

Order as read. "Minimum answer" is what the access must return for the code to continue (boot-path page).

| # | Access | Minimum answer | Grade |
|---|---|---|---|
| 1 | PAL_A, PAL_B, SAL_A reason 3 entry; static PAL 528 argument 5 | the real PAL | established for SAL_A's side |
| 2 | write `0x15031010` to `0x81_1002_0000` | accept | established (constant re-read) |
| 3 | read-modify-write bit 24 of `0x81_2001_0100` | read back what was written | established (re-read) |
| 4 | read `0x81_5003_1510` and `0x81_5003_1530`; write each OR `0x60` (16 bit) to `0x87_fed1_0000` and `0x87_fed3_0000` | any value; plain storage | established |
| 5 | progress write: history register `0x81_5003_1500 + 16 * lid[26:23]` (shift 8, code in the low byte) and LED registers `0x87_fed0_0000 + n * 0x10000`; repeated in the SAL_B reset entry and `main()` | plain storage | established (`0xffa0ddb0`, `0xffa1de00` re-read) |
| 6 | election: write `slice + 1` to `0x81_101d_0088`, read `0x81_101d_0080`; a match wins | one processor reads back at 0x80 what it wrote at 0x88; alias or latch unknown | established for the access, unknown for the relation |
| 7 | winner zeroes `0x81_5003_1550`, `1540`, `1560`, writes 1 to `0x81_1006_0480`, re-reads `0x81_101d_0080`, sets bits 41:39 of `0x81_101d_0100` to 7 | write then read back; bits 41:39 = 7 | established |
| 8 | FIT scan, progress 48, read `0x81_1003_0000 + (slice & 3) * 128` into `r31`, branch to SAL_B | any value; 0 accepted | established |
| 9 | SAL_B reset entry: progress 49, builder fills `0x1000000`, RAM reads, `main()` | RAM | established |
| 10 | `main()`: read `0x81_1006_0580` (node id, bits 42:32; zero in the trace run); read the RAM table at `0x1000038`; progress; PAL 520 and others; a call chain that reaches the SHub identification read at node offset `0x1_0000_0000` (part number `0x4363`, revision in bits 31:28); then `sysctl_init` (called at `0xffa19c0c`, phase 0xd) | node id; valid SHub ID | call order from the `br.call` sequence of `main` (re-read, established); callee roles inferred; the interpreter trace is the boot-path page's |
| 11 | real-time clock at `0x1_101c_0000` must advance (delay loops) | advances | inferred (boot-path trace) |
| 12 | first L1 exchange: UART init (poll line-status bit 6, up to 100000 ticks; divisor and line control; check that bits 41:39 of `0x81_101d_0100` read 7), then framed requests to task 6 | section 6 | UART offsets re-read (`0x00 0x08 0x10 0x18 0x20 0x28 0x38` from `0x8000000ffed40000`); request path established at the node side |

Not settled: whether the direct-console probe (scratch register write 0x55 then 0xaa at `0xf_fed4_0038`, progress 9) runs
before the first L1 request, and the order of the identity queries (unknown on both the node and L1 sides).

## 6. Dependencies

- **L1 (mandatory, established).** Without a peer the PROM stops at progress 0x8d, "Critical system controller
  transaction failed", before memory. `sysctl_probe` in 5.04 returns 1 without touching hardware, except when `cpuid[2]`
  is `0xaeeeeeee8badbeef`: that signature makes the PROM skip the L1 and use built-in board data. It is a diagnostic skip
  and is excluded here by rule.
- **L1 framing and requests (established at both ends, sysco `sn2-prom-link-1.62.1.md`).** Frames start and end with
  `0x7e`; payload bytes `0x7e` and `0x7d` go as `0x7d` plus the byte xor `0x20`; FCS-16, reflected `0x8408`, initial
  `0xffff`, residue `0xf0b8`; payload at most 127 bytes. Header: class and index byte, 32-bit big-endian address word
  built from `0x0ffff000` and the task, 16-bit request code, argument count, then arguments (type `0x00` integer,
  `0x01` string, `0x80 | n` raw bytes). The node sends numbered requests to task 6: `0x0001`, `0x0003`, `0x0006` (8
  arguments; board EEPROM and DIMM data), `0x0008`, `0x0009`, `0x000a`, `0x000e`, `0x0010` (CPU presence; bit 0 must
  be set), `0x0012`, `0x0013`, `0x0015`, `0x1005`, `0x1007`, `0x100a`, `0x200d`, `0x200e`, `0x200f`, `0x2004`, and a text
  command to task 3 (`version`, FRU capture, display). A reply carries a status integer first (0 success, negative
  failure). Most reply bodies are inferred.
- **Open on the L1 side.** Which L1 CPU the 350 carries (ColdFire "Opus" or ARM "Opus TIO"; sysco, unknown), so which
  program an emulated peer imitates; how the L1 reaches the SHub junk-bus UART (wire or JTAG chain: unknown for the
  IP57 family); the order of the first requests; the response header bytes; the SPD reply layout.
- **SHub 1.** NASID and part number in `0x81_1006_0580` and at node offset `0x1_0000_0000`; the MD, PI, NI and interrupt
  blocks read in later phases. No SHub 1 register contract exists in this repository yet. Only the first-stage list in
  section 5 is established.
- **Memory.** DIMM presence and SPD data come only through the L1 (`0x0006`, one request per bank and bus, sixteen
  slots), then the memory controller is programmed and a self-test runs (inferred; the self-test completion bits and
  the IBLS0 register address are unread). No DIMM gives fatal 0x80.
- **Interconnect.** One node with no router takes a skip if bit 11 of `0x81_5003_1560` reads set after phase 0xe (read
  from `0xffa47290`, never run); the source of that bit is unread.
- **I/O.** `main_three` is unread beyond ordering: widget id with part number `0xd102` (PIC), IOC4 in one of the first
  three slots, a riser EEPROM record through the L1 (`sysctl_eeprom_io_riser`). The EFI in all three SHub 1 images
  carries driver messages for the IOC4 ATA controller, the QLogic 12160 (IO9) and a Vitesse SATA controller (IO10),
  re-read in the decompressed EFI. That shows both base I/O cards were supported from 4.43 (2005), not what the PROM
  requires to continue.
- **Console.** The default is the system-controller console through the L1; a direct UART console needs the scratch
  loopback. Both exist in the PROM; which is selected is inferred.

## 7. Contradictions and unreconciled facts

1. **Versions in the field against versions held.** Published Prism logs (irixnet forum thread 849, post 12, 2019-01-27)
   print "SGI SAL version 4.65"; an Altix 350 owner's notes state SAL 4.56 and SHub 1.2 (a statement, not a log:
   inferred). Neither build is held: 4.43 is 2005, 4.90 is 2007, 5.04 is 2008, so 4.56 and 4.65 fall between 4.43 and
   4.90. No held image has been seen on a real machine, and comparing an emulated log with the Prism log compares
   different builds. The 5.04 recommendation rests on `README.snprom`, not on observation.
2. **IO10 against IO9.** 007-4660-001 knows only the IO9 and says it is required; -002 makes the IO10 standard and the
   IO9 optional (pp.72, 112). The 4.43 EFI (2005) already has the Vitesse SATA message, so the IO10 existed in firmware
   before the 2008 build. Prism guides use the IO10 in compute modules (`prism.md`). Which card a given owner machine has
   is unknown.
3. **Board name.** All SHub 1 images say IP41; the Altix 350 guide and the L1 say IP57. The PROM has no branch on the
   name, so behaviour does not contradict, but the label cannot be used as a selector.
4. **SHub revision for Prism.** The Extreme guide's figure labels "SHUB 1.2" and "IP57 Node Card" (007-4774-001 p.60)
   while its text says NUMAlink-4, and the Altix 3700 Bx2 is inferred SHub 2 (`platforms/sn2/README.md`).
   `README.snprom` puts Prism on the SHub 1 image, which agrees with the figure.
5. **`prism.md` is stale.** It says no PROM image is held and that the meaning of "snprom supports Prism" is unknown; the
   held 10.54 `README.snprom` states it. Not edited here.
6. **Register stride.** The boot-path page has stride 8 for the UART (confirmed here from the SAL_B constants); the
   sysco link page says the node's `sc_shub_dev_reg` adds the register index shifted left by 6. Possibly two
   accessors; not settled.
7. **DIMM request shape.** The boot-path page describes the DIMM EEPROM request as length 4, id 48; sysco gives request
   `0x0006` with 8 arguments. Both say the layout is unread; they may describe different layers.
8. **Top of image.** The firmware page says what reads the last 16 bytes is unknown; the image also has a 32 KiB
   Intel-labelled block and a pointer to it at `0xffffffd0`, which no page records.

## 8. Minimum discriminating tests

Each test shows the emulated machine following the shipped firmware, and is tied to a cited fact. Group F tests check
the firmware's own behaviour at the emulated hardware. Group S tests check software expectations and must not stand in
for group F.

| Test | Observable | Source fact |
|---|---|---|
| F1 | SAL_A entered with reason 3 before reason 0; reason 0 hand-off writes progress 48 | boot-path SAL_A reading; table at `0xffbd7000` |
| F2 | the PAL pair selected matches the CPU's `cpuid[3]` row and the version minimums | SAL_A rows, section 2 |
| F3 | the SAL_A stores of section 5 rows 2 to 8, in order, with the election read after the `0x88` write | SAL_A 5.04, re-read |
| F4 | history register low byte reads 0x30, then 0x31; later 0x08, 0x0c, 0x0d; LED registers receive the code (odd register OR 0x60) | progress table, SAL_A |
| F5 | after the builder writes `0x1000000`, the entry's reads of `0x1000010` and `0x1000038` return pointers into RAM | SAL_B reset entry, re-read |
| F6 | the first UART access is a 16550-style line-status poll at the stride-8 offsets; frames carry a valid FCS-16 (residue `0xf0b8`) and header; requests go to task 6 with codes from section 6 | UART constants, sysco link page |
| F7 | without a CPU-presence reply with bit 0 set, the PROM stops at 0x87; with it, phase 0x16 starts DIMM requests | boot-path interpreter trace (inferred) |
| F8 | with no L1 peer the PROM stops at 0x8d, not later; with no DIMM, at 0x80 | progress table, boot-path (negative checks that the model does not fake success) |
| F9 | console strings, when printed: "Testing memory", "Probing memory DIMMs", "Initializing memory controller", "Installed Memory Configuration", "Loading EFI ...", "Jumping to EFI"; then "EFI Shell [Built-in]" and "Shell> " | SAL_B and EFI strings, re-read; whether each prints in a normal run is unknown |

F7 and F9 rest on a trace with a stubbed controller and on string presence, so they are inferred.

**S tests (software expectations).** A kernel using the SAL console calls reaches `ttySG0`. `SN_SAL_GET_SN_INFO` returns
chip 0 and NASID mask `0x7ff`, shift 38 (read in full in 4.43; 5.04 not re-read). The SAL revision is at least 4.06
for a TIOCA (Prism graphics; Linux v5.3 `tioca_provider.c`). The published Prism log shape (EFI 1.10, SAL header 3.2,
ACPI OEM ids such as `XSDTSN2`) comes from a different build (4.65) and is a rough check only.

## 9. Recommendation and blockers

**Image: `shub1snprom.bin`, snprom 10.54 build 70399, SAL 5.04 rel081111 IP41, sha256
`51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`** (6291456 bytes). Reasons: SGI's note names the Altix
350 and both Prism models for this image (established as intent); it is the newest SHub 1 build held; its first stage
is read in full; its EFI carries both base I/O driver families. Fallbacks in order: 10.40 SAL 4.90
(`26170cc83c3db243601da8f55610bcdd6bb408136c3b3d19b7c4823e491b9a06`), then 4.43
(`035274812b5065bde3f1b3227a23c05637d8a13f7cab7736ddde4718d46f02eb`).

**Configuration:** one Altix 350 base compute module. One SHub 1 node (revision 1.2 if a choice is needed: the owner's
notes and the Extreme figure say 1.2, and the 5.04 runtime names 1.1, 1.2 and 1.x). One Itanium 2 with a `cpuid[3]` in
section 2, running the shipped PAL. DIMM group 0 populated (four DIMMs, 2 GB minimum, reported through the L1). The PIC
on the riser, with the base I/O card in slot 1 of its first bus: an IO10 (IOC4 and Vitesse SATA; matches the Prism
modules) or an IO9 (IOC4 and QLogic SCSI), as the owner's machine dictates. The 6 MiB image as flash at `0xffa00000`. An
L1 peer speaking the framed link. No router, no second node, no L2. Graded: image, product list and module composition
established; the I/O card choice is open (section 7, item 2).

**Blockers, in the order the firmware meets them.**

1. **PAL.** The shipped PAL_A and PAL_B must run on the CPU model. The PAL bytes are opaque, the meanings of 99, 520, 528
   and 530 are unknown, and the role of the 32 KiB top block is unknown. The CPU model's fidelity to what an Itanium 2 PAL
   expects has not been assessed. Route: read the Itanium PAL and processor reference documents (none read for this
   page), then trace PAL_A.
2. **SHub 1 contract.** The election relation (`0x88` to `0x80`), the ID and revision fields, the memory-controller and
   interrupt blocks. Route: the SHub 1 contract from the Linux headers, then check the PROM's stores against it.
3. **L1 peer.** Request order, the DIMM and EEPROM reply layouts, the CPU-presence reply, which L1 variant. Route: read
   the call chain from `main` through `sysctl_init` to each first use (the boot-path gap list) and the ColdFire or ARM
   handler for each code.
4. **Memory sizing and self-test.** The completion bits and the IBLS0 address. Route: read `0xffa6f000` and the memory
   controller functions.
5. **Single-node skip.** The source of bit 11 of `0x81_5003_1560`. Route: phase 0xe and the environment-variable read.
6. **I/O discovery.** `main_three`, the PIC widget reads and the riser record. Route: the PIC contract, then read
   `0xffad7280` onward.
7. **No hardware capture of any held build.** No log or register capture ties an image to a machine. Any physical read
   follows the repository's rules for the owner's machines and is not proposed here.
8. **Container hash and owner machine identity** (section 1, section 7 item 2): small, but needed to name what is being
   emulated.

None of 1 to 6 needs a firmware change or a diagnostic skip. Item 1 is the largest unknown, and decides whether the
first boot is a PROM question or a CPU question.
