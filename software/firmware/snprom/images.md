# snprom images: which image serves which machine

Which SGI PROM image and package serves which machine: image identities, containers, hashes, SAL versions and build dates,
the machine lists in SGI's `README.snprom`, the flash composition, the processor tables and the facts in the images and
manuals that bear on the match. It adds no register facts: those live in [the firmware page](README.md), [the boot-sequence
page](boot-sequence.md) and the device pages. The newest SHub 1 build held is read in full; the Altix 350 shares the Prism node board (IP57 node board, SHub 1.2 where a
manual names it) and is the smaller machine. An independent review is appended (section Review); its corrections are folded into the text below.

**Grades.** *established*: read in full in a shipped binary or printed in a published manual. *inferred*: reasoned,
with the reasoning given. *unknown*: not settled, with the route that would settle it.

**What was re-checked for this page** (chips root `sn2/`, binutils `ia64-linux-gnu-objdump` through
`retools/tools/re-run`, nothing copied): the sha256 of every candidate image (all matched `SHA256SUMS`, 25 of 25 lines
clean); the FIT and top-of-image words of the SHub images; the SAL banner and build time of each; the
processor-stepping rows in each SHub 1 SAL_A; the SAL_A 5.04 node set-up and progress-register constants; the SAL_B
reset entry and the call order of `main()`; the UART window constants in SAL_B; the decompressed EFI strings of the three
SHub 1 images; `IP57` and `Prism` string counts. The manual pages cited were re-read in the SGI printed manuals.
Everything else is taken from the pages named, at the commits named.

Pages synthesised (chips `c567510`, sysco `5d62fbd`):
[snprom README](README.md) (`1579f00`), [boot path](boot-sequence.md) (`c567510`),
[SN2 holdings](../../../references/sn2-holdings.md) (`c4a3255`),
[irix-files](../../../references/irix-files.md#sn2-firmware-and-kernels) (`ec38a7e`),
[Altix 350](../../../platforms/sn2/altix-350.md) and [Altix 3000](../../../platforms/sn2/altix-3000.md) (`94c62dd`),
[Prism](../../../platforms/sn2/prism.md) (`06bdc20`), and in sysco `software/firmware/l1/sn2-prom-link-1.62.1.md`
(`5d62fbd`) and `sn2-l1-1.62.1-packages.md` (`8ceefe9`).

## In brief

- **Newest SHub 1 image held:** `shub1snprom.bin` from snprom 10.54 build 70399, SAL 5.04, sha256
  `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`. SGI's `README.snprom` in that package lists it for
  the Altix 330, 350, 3300, 3700, 3700 Bx2 and both Prism models (vendor intent, not evidence of a boot).
- **Altix 350 base compute module:** one IP57 node (one SHub 1, one or two Itanium 2), memory in group 0, the PIC
  on the PCI riser, an IOC4-based base I/O card in riser slot 1, an L1 on the interface board; no router, no second node.
- **No held image has been captured running on any machine.** What the firmware needs from PAL, the SHub, the L1, memory
  and I/O is in the boot-sequence page; the open readings are in section 8.

## 1. Candidate images

All hashes were recomputed with `sha256sum` on the files under `root/sn2/` and match the values chips records. The
container row is what the pages record; a container hash is a different thing from the image hash and is treated
separately below.

| | `snprom.bin` | `shub1snprom.bin` | `shub1snprom.bin` | `shub2snprom.bin` | `shub2snprom.bin` | `ip65prom.bin` |
|---|---|---|---|---|---|---|
| Package | snprom 4.43 build 44607 | snprom 10.40 build 62478 | snprom 10.54 build 70399 | snprom 10.40 build 62478 | snprom 10.54 build 70399 | snprom 10.11 build 52277 |
| Container recorded | `snprom-4.43-44607.ia64.rpm`, ProPack 4 SP3 CD 2 | `snprom-10.40-62478.ia64.rpm`, ProPack 4 SP4 CD 2 | `snprom-10.54-70399.ia64.rpm`, package mirror | same rpm as 4.90 | same rpm as 5.04 | `snprom-10.11-52277.ia64.rpm`, package mirror |
| SAL banner | 4.43 rel051202 IP41 | 4.90 rel071217 IP41 | 5.04 rel081111 IP41 | 1.40 rel071217 IP65 | 1.54 rel081111 IP65 | 1.11 (IP65) |
| Built | 2005-12-02 14:14:24 | 2007-12-17 06:06:11 | 2008-11-11 07:25:21 | 2007-12-17 06:08:32 | 2008-11-11 07:28:01 | 2006-10-18 (firmware page; banner not re-read here) |
| Size (bytes) | 6291456 | 6291456 | 6291456 | 12582912 | 12582912 | 12582912 |
| sha256 (re-hashed) | `035274812b5065bde3f1b3227a23c05637d8a13f7cab7736ddde4718d46f02eb` | `26170cc83c3db243601da8f55610bcdd6bb408136c3b3d19b7c4823e491b9a06` | `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617` | `1c8144e3d318f71a7633dddc268c3ebd0f64febb87c2f234a9a917df0673dd77` | `3ea833181fda8968a5297043f2260d2fc255983ecca1d418292ee008b5e2c793` | `372e74f7201d35e56ef871c330ccbd66fda9f921376ae5dd3045cf4ae6319199` |

Banner, build time and size: established (strings and FIT read by me). The 10.54 package also ships a
`shub2snprom.bin` (`3ea83318...`, SAL 1.54 rel081111 IP65, the sixth column above; the SHub 2 address map and reset accesses read from it are in [devices/shub/shub2.md](../../../devices/shub/shub2.md)) and SGI's `README.snprom` (`00f0a21d...`, re-hashed).

**The README.snprom machine lists (established as SGI's statement).** `README.snprom` from the 10.54 build 70399
package, 6,112 bytes, sha256 `00f0a21d82c4b3a392043b52ec77d357c84ed74bfc0eb1cf5cb76c552571bcb0`, held in the Library as
`firmware/sn2/snprom-10.54-70399/README.snprom`. Line numbers count the file's blank first line.

| Lines | What they say |
|---|---|
| 15 | `shub1snprom.bin` supports the Altix machines listed below |
| 17–23 | Altix 330, Altix 350, Altix 3300, Altix 3700, Altix 3700 Bx2, Prism Rackmount, Prism Deskside, one per line |
| 25 | `shub2snprom.bin` supports the Altix machines listed below |
| 27–28 | Altix 4700, Altix 450 |

**Container hash.** The holdings catalogue records the 10.54 container as `snprom-10.54-70399.ia64.rpm`, 6,296,643
bytes, sha256 `48616566404b060bf606f1ce7d6149c9261c6477f89d32051336df60ee423ce4`. This is catalogue metadata: the rpm is
not in the chips root and was not re-hashed for this page, so nobody here has tied it to the extracted files (the
extracted `shub1snprom.bin` and `README.snprom` hashes above are the only ones computed). No container hash is recorded
for the other packages, and [irix-files](../../../references/irix-files.md#sn2-firmware-and-kernels) says the container
name of most images was not recorded when the files were copied. A search of held sources for the 10.54 rpm file name found
nothing. The route to close this is to hash the rpm in the owner's package mirror, compare it with the catalogue value,
and check the rpm header against the extracted files.

**Why the SHub 2 builds are not for the Altix 350 (established).** `shub2snprom.bin` and `ip65prom.bin` are built for the CPU board
`IP65` with SHub 2.0, carry the string `SHUB2 does not support XIO I/O.`, and SGI's `README.snprom` lists them for the
Altix 4700 and 450 only. The Altix 350's PIC sits behind the SHub's XIO link (007-4660-001 p.105, section 2), and the
SHub 2 first stage touches the `0x2_xxxx_xxxx` window, not the SHub 1 window.

**The earlier SHub 1 builds (established for the facts).** `README.snprom` (shipped from
package 10.20) says `shub1snprom.bin` supports Altix 330, 350, 3300, 3700, 3700 Bx2, Prism Rackmount and Prism
Deskside: a vendor statement of intent for the 10.54 package, not evidence that the image boots a given machine. 4.43
predates it. 4.43 also has the only `sysctl_probe` that really probes the controller (a 2,000,000-tick retry) and lacks
`SN_SAL_BTE_RECOVER` and the feature-set calls; 4.90 is the previous build of the 5.04 line. All three SHub 1 images
carry the same three first-table processor rows (section 2) and the same top-of-image block (section 3).

The NUMAlink 4 router routines of the 5.04 SHub 1 image (`nl4r_init_global`, `nl4r_config_global`, `nl4r_config_port`,
the NUMAlink 3 pair, and the routing-table distribution) are read and compared with the SHub 2 10.54 image in
[devices/router_nl4/global-config.md](../../../devices/router_nl4/global-config.md): same source, same register values,
the SHub 1 vector request carrying a bias bit. The 4.43 image was compared by listing; 4.20 and 10.40 by strings only.

## 2. Machines the SHub 1 images serve

**Altix 350, one module.** One base compute module is a complete system: IP57 node board with one SHub,
one or two Itanium 2, at least four DIMMs (group 0 of three groups of four), four PCI/PCI-X riser slots, a base I/O
card, an L1 on the interface board, no rack, no L2, no router (007-4660-001 pp.69 to 71, 96, 100 to 106;
[Altix 350](../../../platforms/sn2/altix-350.md), established). The PIC ASIC is on the PCI riser card, and the riser has
a nonstandard connector for the IO9 card (007-4660-001 p.105, re-read). The SHub block list names an I/O interface (II),
two network interfaces (NI) and a local block (LB) (007-4660-002 p.112, re-read). The base I/O card is the IO10
(standard) or the IO9 (optional) in the later guide, and the IO9 only in the 2004 guide; it sits in riser slot 1; the
IO10 has serial ATA, the IO9 SCSI (007-4660-002 p.112, re-read). Both cards use an IOC4 (the Linux IOC4 driver, graded
established on the machine page under the repository's evidence rule).

**Altix 3300 plus IX-brick.** The 3300 has up to 12 Itanium 2, one IX-brick, no routers, one power bay and
an optional L2, in a 17U rack (007-4579-001 p.77). Its C-brick is two nodes joined internally, two processors each
(p.99, `altix-3000.md`). The guide names the node chip Super-Bedrock (p.81) and the driver guide names it SHub
(007-4520-006 p.16). The smallest 3300 therefore has two node chips and an internal NUMAlink link. The guide gives
that link one channel on p.81 and two on p.101, so its channel count is open (see `altix-3000.md`). The PROM's
node-interconnect phase then reads network registers instead of taking the single-node skip of section 6, and none of
those registers has a contract. The IX-brick adds three PIC adapters and
six PCI-X buses. Its compute board is the one the images name: banner and build say IP41, and sysco infers
the C-brick reports L1 type `5`, the IP41 board (inferred). It shares the SHub 1 image with Prism but not
the node board.

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
- Processors, all three SHub 1 images (re-read from each SAL_A, reader's correction folded in). SAL_A holds two tables.
  The first has three rows, each three 64-bit words: a `cpuid[3]` value and two version words: `0x1f000404` with
  7.31/7.79, `0x1f010504` with 5.37/5.73 and `0x1f020104` with 1.27/2.25 (4.43 has 2.15 in the last). The lookup masks
  `cpuid[3]` with `0xffffff0000` before comparing, so the key is the architecture revision, family and model (family
  `0x1f`, models 0, 1 and 2) and the revision and number bytes are not compared (established from the `and` before the
  compare at `0xffc4eac0` and `0xffc4eb40`). The version words equal the PAL_A and PAL_B versions of the image's FIT
  entries, which supports reading them as the PALs to use (inferred). The second table, at `0xffc51000` (a copy at `0xffbe0a08` in SAL_B), has 15 rows
  of `0x60` bytes, ended by a zero key, keyed by the exact `cpuid[3]` value: seven rows with family `0x1f` (Itanium 2 models 0, 1 and 2: `0x1f000404`, `0x1f000504`, `0x1f000604`, `0x1f000704`,
  `0x1f010504`, `0x1f020104` and `0x1f020204`) and eight with family `0x20` (`0x20000104` to `0x20000504`, `0x20000704`, `0x20010004` and `0x20010104`; established, from the later review of [the boot-sequence page](boot-sequence.md)). Each row has a version window (a low and a high 16-bit value,
  repeated for the second version). For the first eight keys in the order above the lows are 4.05, 5.05, 6.28, 7.13, 5.37, 1.27, 2.10 and 1.10 and the high is 9.99 in
  every row; the windows of the other seven rows were not re-read. The lookup at `0xffc4eb60` tests the two version words from the first table against these windows (inferred
  from the compare sequence). A family `0x20` (Montecito) row exists in the second table but not in the first;
  with no first-table row the version words are set to -1 and every window test fails, so a family `0x20` CPU does not
  match (inferred). Names such as Madison come from Intel's numbering, not the image (inferred). What the code does after
  a failed lookup was not read (unknown).
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
| `0x5f8000` to `0x5fffff` (32 KiB, `0xffff8000`) | a block no FIT entry describes, with 256 distinct byte values but 45 percent zero bytes (4.58 bits per byte; not high-entropy), containing the string "Copyright (C) 2002 Intel Corporation" at `0xffffff00` and the date string `11/02/99` at `0xfffffff5`; the word at `0xffffffd0` points to its start; the range `0xffff8000` to `0xffffffcf` is byte-identical in the three SHub 1 images, both SHub 2 images and `ip65prom.bin` (same sha256 prefix of that range; the last 48 bytes differ only in the SAL_A entry pointer) | unknown. New observation, not in the firmware page |
| `0xffffffe0`, `0xffffffe8` | FIT pointer and SAL_A entry, both with bit 63 | read at reset (the roles agree with the SAL_A reading; the architectural reading is unread) |

The firmware reads the whole file as flash at those addresses. A CFI command interface is used for the
variable store and PROM log (inferred from `cfi_*` names; the EFI image calls SAL id `0x02000008` for the variable
store). Flash writes are not needed to reach the EFI shell (inferred). Outside FIT components, the non-erased bytes are
the 32 KiB block (which includes the pointers at `0xffffffd0` to `0xffffffe8` and the last 16 bytes, so those are not
separate regions). The last 16 bytes are an x86 far jump (`ea 5b e0 00 f0`, to `f000:e05b`) and the date `11/02/99`,
the layout of an IA-32 BIOS reset vector at the top of a 32 KiB image that ends at 1 MiB in the F-segment; that this
block is an IA-32 BIOS image for the processor's IA-32 mode is inferred from the layout, and what reads it is unknown.

## 4. Reset, entry and PAL requirements

- **Reset path (inferred from the pointers).** The processor starts in PAL_A; PAL_A calls SAL_A (address from
  `0xffffffe8`) first with reason 3 (the PAL-pair query), then PAL_B runs, then PAL enters SAL_A with reason 0, which
  scans the FIT and enters SAL_B offset 0. Reasons 1 and 2 (machine check, INIT) go to offsets 0x20 and 0x10. SAL_A's
  side is established (boot-path review). PAL's side is architectural and unread: no Itanium PAL specification was read
  for this page.
- **FIT (established, re-read).** Signature `_FIT_   ` at file offset 0, 13 live entries in 5.04 plus the header and an
  empty slot. Types: 0x01 PAL_B, 0x0e PAL_A, 0x10 SAL_A, 0x11 SAL_B, 0x12 runtime, 0x13, 0x1f EFI, 0x22, 0x23. SAL_A
  checks the signature and a type-0 header and hangs with progress 178 if the scan fails.
- **The PAL is the shipped PAL.** SAL_A reason 3 selects PAL_A and PAL_B by `cpuid[3]` and passes a field back in
  `r37`, makes static PAL call 528 with argument 5, and spins if bit 3 of `r33` is set. These steps run only with the PAL pair from the image. SAL_B then calls these PAL procedures (boot-sequence page; my count of direct `r28` immediates in
  SAL_B found the same set: 1, 2, 3, 12, 22, 26, 29, 41, 42, 0x208 and 530, plus whatever the four call wrappers
  carry): 1 CACHE_FLUSH, 2 CACHE_INFO, 3 CACHE_INIT, 4 CACHE_SUMMARY, 9 and 10 BUS_GET/SET_FEATURES, 12 FIXED_ADDR, 14
  FREQ_RATIOS, 17 and 18 PROC_GET/SET_FEATURES, 20 VERSION, 21 MC_CLEAR_LOG, 22 MC_DRAIN, 25 MC_ERROR_INFO, 26
  MC_RESUME, 29 HALT_LIGHT, 30 COPY_INFO, 32 PMI_ENTRYPOINT, 37 TEST_INFO, 41 PREFETCH_VISIBILITY, 42
  LOGICAL_TO_PHYSICAL, 256 COPY_PAL, 258 TEST_PROC, 259 and 260 CACHE_READ and CACHE_WRITE, and the implementation-specific
  99, 520 (0x208, arguments `0x1000000` and `0x40000`), 528 and 530. Names are Linux `pal.h` numbering (software
  expectation). Wrapper-passed indexes were not all resolved, so this is the static set. The meanings of 99, 520, 528
  and 530 are unknown beyond a guess.
- **RAM at `0x1000000`.** The SAL_B reset entry (`0xffa01000` branches to `0xffa1de00`) writes progress 49 (179 if its
  argument is nonzero), then a table builder (`0xffac42d0`) fills the area at `0x1000000`, then the entry reads
  `[0x1000010 + 8 * slot]` and `[0x1000038]` for its stack and backing store, with translation off (re-read; the
  `[0x1000000 + 8 * (9 + slot)]` read is from the boot-sequence page). The reads follow the builder's writes, so plain
  read/write memory at `0x1000000` is the requirement. On hardware PAL call 520 preloads 256 KiB of cache there before
  DRAM is up (inferred).
- **Interrupt vectors in flash.** The SHub 2 build installs its table from flash at `0xff5c0000`; the 5.04 address was
  not re-read. Whether flash must be executable with translation on is unknown.

## 5. First hardware-access prefix: reset to the first L1 exchange

Order as read. "Value the code needs" is what the access must return for the code to continue (boot-sequence page).

| # | Access | Value the code needs | Grade |
|---|---|---|---|
| 1 | PAL_A, PAL_B, SAL_A reason 3 entry; static PAL 528 argument 5 | the real PAL | established for SAL_A's side |
| 2 | write `0x15031010` to `0x81_1002_0000` | accept | established (constant re-read) |
| 3 | read-modify-write bit 24 of `0x81_2001_0100` | read back what was written | established (re-read) |
| 4 | read `0x81_5003_1510` and `0x81_5003_1530`; write each OR `0x60` (16 bit) to `0x87_fed1_0000` and `0x87_fed3_0000` | any value; plain storage | established |
| 5 | progress write: history register `0x81_5003_1500 + 16 * lid[26:23]` (shift 8, code in the low byte) and LED registers `0x87_fed0_0000 + n * 0x10000`; repeated in the SAL_B reset entry and `main()` | plain storage | established (`0xffa0ddb0`, `0xffa1de00` re-read) |
| 6 | election: write `slice + 1` to `0x81_101d_0088`, read `0x81_101d_0080`; a match wins | one processor reads back at 0x80 what it wrote at 0x88; alias or latch unknown | established for the access, unknown for the relation |
| 7 | winner zeroes `0x81_5003_1550`, `1540`, `1560`, writes 1 to `0x81_1006_0480`, re-reads `0x81_101d_0080`, sets bits 41:39 of `0x81_101d_0100` to 7 | write then read back; bits 41:39 = 7 | established |
| 8 | FIT scan, progress 48, branch to SAL_B; reason 0 does not read `0x81_1003_0000 + (slice & 3) * 128` (reasons 1, 2 and above 3 read it into `r31`) | nothing for reason 0 | established (the reason test and branch re-read) |
| 9 | SAL_B reset entry: progress 49, builder fills `0x1000000`, RAM reads, `main()` | RAM | established |
| 10 | `main()`: read `0x81_1006_0580` (node id, bits 42:32; zero in the trace run); read the RAM table at `0x1000038`; progress; PAL 520 and others; a call chain that reaches the SHub identification read at node offset `0x1_0000_0000` (part number `0x4363`, revision in bits 31:28); then `sysctl_init` (called at `0xffa19c0c`, phase 0xd) | node id; valid SHub ID | call order from the `br.call` sequence of `main` (re-read, established); callee roles inferred; the interpreter trace is the boot-sequence page's |
| 11 | real-time clock at `0x1_101c_0000` must advance (delay loops) | advances | inferred (boot-path trace) |
| 12 | first L1 exchange: UART init (poll line-status bit 6, up to 100000 ticks; divisor and line control; check that bits 41:39 of `0x81_101d_0100` read 7), then framed requests to task 6 | section 6 | UART offsets re-read (`0x00 0x08 0x10 0x18 0x20 0x28 0x38` from `0x8000000ffed40000`); request path established at the node side |

Not settled: whether the direct-console probe (scratch register write 0x55 then 0xaa at `0xf_fed4_0038`, progress 9) runs
before the first L1 request, and the order of the identity queries (unknown on both the node and L1 sides).

## 6. Dependencies

- **L1 (mandatory, established).** Without a peer the PROM stops at progress 0x8d, "Critical system controller
  transaction failed", before memory. `sysctl_probe` in 5.04 returns 1 without touching hardware, except when `cpuid[2]`
  is `0xaeeeeeee8badbeef`: that signature makes the PROM skip the L1 and use built-in board data. It is a diagnostic skip
  that the normal boot does not take.
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
  program the L1 runs; how the L1 reaches the SHub junk-bus UART (wire or JTAG chain: unknown for the
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
  carries driver messages for the IOC4 ATA controller, the QLogic 12160 (IO9), a Vitesse SATA controller (IO10) and a
  Silicon Image Sil0680 ATA controller (not otherwise discussed here), re-read in the decompressed EFI. That shows both base I/O cards were supported from 4.43 (2005), not what the PROM
  requires to continue.
- **Console.** The default is the system-controller console through the L1; a direct UART console needs the scratch
  loopback. Both exist in the PROM; which is selected is inferred.

## 7. Contradictions and unreconciled facts

1. **Versions in the field against versions held.** Published Prism logs (irixnet forum thread 849, post 12, 2019-01-27)
   print "SGI SAL version 4.65"; an Altix 350 owner's notes state SAL 4.56 and SHub 1.2 (a statement, not a log:
   inferred). Both banners are held: 4.56 is snprom 10.6 (build 49286, `4.56 rel060615`) and 4.65 is snprom 10.15 (build 53414,
   `4.65 rel061204`). The owner's 4.56 is a statement with no log to match. The 4.65 match rests on the version number alone.
   No held image has been seen on a real machine, and a Prism log and a log of a held build come from different builds.
   That the 5.04 image serves the Altix 350 and Prism rests on `README.snprom`, not on observation.
2. **IO10 against IO9.** 007-4660-001 knows only the IO9 and says it is required; -002 makes the IO10 standard and the
   IO9 optional (pp.72, 112). The 4.43 EFI (2005) already has the Vitesse SATA message, so the IO10 existed in firmware
   before the 2008 build. Prism guides use the IO10 in compute modules (`prism.md`). Which card a given owner machine has
   is unknown.
3. **Board name.** All SHub 1 images say IP41; the Altix 350 guide and the L1 say IP57. The PROM has no branch on the
   name, so behaviour does not contradict, but the label cannot be used as a selector.
4. **SHub revision for Prism.** The Extreme guide's figure labels "SHUB 1.2" and "IP57 Node Card" (007-4774-001 p.60)
   while its text says NUMAlink-4, and the Altix 3700 Bx2 is inferred SHub 2 (`platforms/sn2/README.md`).
   `README.snprom` puts Prism on the SHub 1 image, which agrees with the figure.
5. **`prism.md` was stale.** It said no PROM image is held and that the meaning of "snprom supports Prism" is unknown; the
   held 10.54 `README.snprom` states it. Corrected in the review commit to point here and to
   [the holdings page](../../../references/sn2-holdings.md).
6. **Register stride (resolved in review).** The UART is spaced 8 bytes apart: the UART driver and the PROM's own
   accesses use fixed addresses `0x8000000ffed40000 + 0, 8, ... 0x38`. The sysco page's `sc_shub_dev_reg` shifts the
   index left by 6 and is a separate chipset accessor whose users in the UART driver were not found; sysco's page is
   corrected.
7. **DIMM request shape (resolved in review).** The request is task 6, code `0x0006`, 8 arguments (sysco, correct). The
   boot-sequence page's pair is the two constants the DIMM routine passes to the shared read: 48 is the byte count (each
   request carries at most 64 bytes) and 4 is a fixed selector argument, so the boot-sequence page (now boot-sequence.md) has the two reversed
   (length 48, selector 4). The boot-sequence page is not edited here.
8. **Top of image.** The firmware page says what reads the last 16 bytes is unknown; they lie inside a 32 KiB
   Intel-labelled block with a pointer to its start at `0xffffffd0`, which no page records. The firmware page is not
   edited here.

## 8. Open readings

Not an order; the current list with routes is [questions/sn2-prom-open.md](../../../questions/sn2-prom-open.md).

- **PAL.** The PAL bytes are opaque. The meanings of PAL procedures 99, 520, 528 and 530 are unknown beyond a guess, and so is
  the role of the 32 KiB top block. No Itanium PAL or processor reference document was read for this page.
- **SHub 1.** The election relation (`0x88` to `0x80`), the ID and revision fields, and the memory-controller and interrupt
  blocks had no register contract when this page was written. The memory-test completion bits, IBLS0 and the source of the
  single-node skip (bit 11 of `0x81_5003_1560`) were read afterwards, in [the boot-sequence page](boot-sequence.md).
- **L1.** Request order, the DIMM and EEPROM reply layouts, the CPU-presence reply and which L1 variant the 350 carries.
- **I/O.** `main_three` (the PIC widget reads and the riser record) was unread beyond ordering here; the boot-sequence page has
  a later static reading of it.
- **No hardware capture of any held build.** No log or register capture ties an image to a machine. Any physical read of the
  owner's machines follows the repository's rules and is not proposed here.
- **Container hash and owner machine identity** (section 1, section 7 item 2).

## Review

The page reviewed below also carried a list of F and S discriminating tests, a recommendation of one image and machine as a first target, and a blocker list; those were removed from this page, and the review's remarks on them (tests F2, F4, F7 to F9, section 9) are kept as the record of what facts they rested on.

Independent review of commit `9de55f3` by a reviewer who wrote none of it, read against the held binaries and our holdings
SGI printed manuals. Tools: `ia64-linux-gnu-objdump` through `retools/tools/re-run` on the images in `root/sn2/`, Python
for the FIT, gzip components and hashes, `strings` on the decompressed components. Nothing copied into the repository.
The corrections the review found are folded into the text above (processor tables, the top-of-image block, test F2, the
grading of the recommendation, the container hash); the contradictions list now records the resolutions.

**Confirmed.**

- Hashes: `sha256sum -c SHA256SUMS` over `root/sn2/` is 25 of 25 clean; the three SHub 1 candidates and `README.snprom`
  hash to the values on the page, and every size matches. The package identity of an image is the extraction directory's
  name (`snprom-10.54-70399` and so on) together with the holdings catalogue; the root holds no rpm header, so only the
  SAL banner and build time are read from the image itself.
- Banners and build dates, from the image strings: 4.43 rel051202 IP41, 2005-12-02 14:14:24; 4.90 rel071217 IP41,
  2007-12-17 06:06:11; 5.04 rel081111 IP41, 2008-11-11 07:25:21; and the SHub 2 and IP65 rows (1.40 rel071217 IP65,
  06:08:32; 1.11 rel061018 IP65, 2006-10-18 06:32:58, which the page marked as not re-read).
- `README.snprom` (10.54): `shub1snprom.bin` lists Altix 330, 350, 3300, 3700, 3700 Bx2, Prism Rackmount and Prism
  Deskside; `shub2snprom.bin` lists Altix 4700 and 450. The page's statement about 10.20 and 10.23 comes from the
  holdings catalogue; the README does not say it.
- Manuals, read at the printed page numbers the page uses (our holdings PDF index runs 24 to 28 pages ahead of them):
  007-4579-001 p.77 (Altix 3300: up to 12 processors, one IX-brick, no routers, single power bay, optional L2, 17U;
  up to three C-bricks), p.81 (the node chip is "Super-Bedrock ASIC"; the internal channel is "NUMAlink 4") and p.99
  (the C-brick is two nodes joined by NUMAlink, two processors each; the manual says "ASIC", not "SHub");
  007-4660-001 p.100 (IP57 board: twelve DIMM slots), p.101
  (1.0 to 1.5 GHz, 1.5, 3 and 6 MB L3) and p.105 (PIC ASIC on the riser card, IO9 connector, four slots; the DVD-ROM
  needs an IO9); 007-4660-002 p.72 and p.112 (IO10 has serial, IO9 SCSI; IO10 standard, IO9 optional, in slot 1; the SHub
  block list). The machine choice follows from these. Not re-read: the page's other manual pages (69 to 71, 96, 100,
  102 to 104, 106).
- Composition: the FIT in 5.04 has 13 entries after the header, with the types, SAL_A at `0xffc4e000` (16 KiB), SAL_B
  at `0xffa01000` (2.3 MiB), runtime 918,824 bytes, EFI 2,495,544 bytes, type `0x22` archive and type `0x23` of 672
  bytes (an ELF). The words at `0xffffffe0` and `0xffffffe8` read `0x80000000ffa00000` and `0x80000000ffc4e000`.
- EFI strings (decompressed type `0x1f`, 4.43, 4.90 and 5.04 alike): "SGI IOC4 ATA detected", "Qlogic 12160 SCSI Controller
  detected", "Vitesse Serial ATA detected", and also "Silicon Image Sil0680 Ultra ATA detected", which the page did not
  list. `IP57` and `Prism` do not occur in any of the three images, raw or decompressed.
- SAL_A 5.04: the stores of section 5 rows 2 to 8 are as listed (constants, order, the election write to `...0088` then
  read of `...0080`, bits 41:39 set to 7 in the routine at `0xffc4e740`, progress 48 at `0xffc4e4ec`, progress 178 on a
  failed FIT scan). SAL_B reset entry: `0xffa01000` branches to `0xffa1de00`, which writes progress 49 on the path taken
  when its argument is zero and 179 otherwise, calls five routines, then the builder at `0xffac42d0` (which references
  `0x1000000` to `0x1000050` throughout), then reads `[0x1000010 + 8 * slot]` and `[0x1000038]` with data translation off
  and reads `[0x1000000 + 8 * (9 + slot)]`. The claim stands; that the builder writes the area is read from its address
  references, not from a store-by-store trace.
- `sysctl_probe` returns 0 when `cpuid[2]` equals `0xaeeeeeee8badbeef` and 1 otherwise, with no call.

**Findings (corrected in the text).**

1. The processor description was wrong in three ways. SAL_A has two tables, not one: the three-row table the page
   describes and an eight-row table of `0x60`-byte rows at `0xffc51000` that includes a family `0x20` row
   (`0x20000104`), so "no family `0x20` row exists" was false of the image. The first table's key is `cpuid[3] &
   0xffffff0000`, not the low word, so the revision byte is not compared. Version words and the second table are now
   described as read.
2. The top-of-image block is not high-entropy (4.58 bits per byte, 45 percent zero), the hash match holds for
   `0xffff8000` to `0xffffffcf` only (the last 48 bytes differ in the SAL_A pointer), it is identical in six images, not
   four, and the last 16 bytes lie inside it (they were listed as a separate region). It looks like an IA-32 BIOS image
   (reset-vector jump and date) rather than anything the PAL needs; that is inferred.
3. The recommendation's grade: "image established" read as proof of fit. It is graded as vendor intent plus inference,
   with no boot proof, in section 9.
4. The container hash was missing. The catalogue value is added and marked as metadata that was not re-hashed.
5. `prism.md` said no PROM was held. Corrected in the same commit.

**Open items the author should address (not changed here).**

- SAL_A also writes progress `0xb0` (176) at `0xffc4e100`, `0xffc4e166` and `0xffc4e1e0` (history register and the two
  LED registers) under a test of the low two bits of an entry argument (`0xffc4e0b0`); section 5 and test F4 list
  `0x30` first. The condition is unread.
- Not re-verified by this review: section 5 rows 10 and 11 beyond the entry, the PAL procedure list and its call
  counts, the `SN_SAL_GET_SN_INFO` values, the 4.43 `sysctl_probe` retry count, the progress codes `0x08`, `0x0c`, `0x0d`
  and `0x8d`/`0x87`/`0x80`, and the F7 to F9 observables. They rest on the boot-sequence page.
- The boot-sequence page has the DIMM request's length and selector reversed (contradiction 7); the firmware page says what
  reads the top 16 bytes is unknown (contradiction 8). Neither was edited by this review.

**Cleared scope.** The candidate hashes, packages (as directory and catalogue identity), banners and build times; the
`README.snprom` machine lists; the machine choice and its manual citations as listed above; the composition table after the
corrections; the EFI driver messages; the first-stage constants of section 5 rows 2 to 9 and the progress-49 entry; the
contradictions list after the resolutions; the separation of firmware tests (F) from software expectations (S); and the
recommendation as vendor intent with inference, not boot proof. Not cleared: the items listed under "Not re-verified", the
PAL requirement beyond the table readings, and any claim about what an Itanium 2 PAL does with the images.
