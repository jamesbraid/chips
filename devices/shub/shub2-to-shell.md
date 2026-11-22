# SHub 2: from "Testing memory" to the EFI start

What an emulated SHub 2 node has to answer between the memory test and the jump into EFI, read from the SHub 2 PROM (`shub2snprom.bin`, snprom 10.54 build 70399, SAL 1.54, sha256 `3ea833181fda8968a5297043f2260d2fc255983ecca1d418292ee008b5e2c793`). It continues [shub2.md](shub2.md) and [shub2-model-rows.md](shub2-model-rows.md); the register rows up to the memory test are there. Scope: one IRU, one blade, one node, no NUMAlink neighbours, no L2. Independent review is pending.

**Grades.** *established*: the access (address, width, direction) and the constants were read in the instruction listing; of 250 offsets and constants that the decompiled C showed in register accesses on this path, 246 were found as immediates in the listing, and the other four are masks built from several immediates (`0xff414e00`, `0xff424a00`). *software expectation*: what the code needs a register to return; no SHub 2 manual and no hardware read exists, so **no value here is a reset value**. *inferred*: reasoned, reason given. *unknown*: not settled. A value written with nine hex digits (`0x2_101d_0380`) is the full local address (bit 63 set); one with eight or fewer (`0x101d_0380`, `0x1_0010`, `0x2_0088`) is an offset in the local window, add `0x2_0000_0000`. `A(n, off)` is the per-node form of [shub2.md section 3](shub2.md#main-0xff42b9c0-from-the-node-election-to-the-first-console-message) (every use is preceded by one or two reads of `0x2_2011_0000`).

**How it was read.** Ghidra with the IA-64 module, `re-run --ghidra-export IMAGE --sn2-prom`, 12 MiB flat image, every function the path reaches decompiled, plus a full instruction listing of the image. Accesses go through four leaf routines (`0xff4207a0` read 64, `0xff420840` write 64, `0xff4207f0` read 8, `0xff420890` write 8); a reachability walk over direct calls and over the node method tables (table of SHub 2 at `0xff5fce08`, router `0xff5fd188`, TIO `0xff5fd508`, 112 slots each, found by the part-number walk at `0xff423100`) listed every function that uses them, and each function was read in the decompile with its constants checked in the listing. Not every function on the path was read in full; section 8 says which.

## 1. The path, with progress codes

Progress codes go through `0xff420380` (16-bit store to the junk-bus LED port, [shub2.md](shub2.md#the-progress-write)). Every barrier named below is `0xff4b2c90` (SCRATCH6 bits 30 to 34, established in [shub2.md](shub2.md)); on one node it passes as soon as the node's own slice has arrived.

| Step | Code | Entry | What it prints or does |
|---|---|---|---|
| End of the memory test | `0x17` | `0xff47a970` | "Testing memory ...", per-bank test (section 2 of [shub2.md](shub2.md#4-memory-and-directory-registers-the-bring-up-programs)) |
| Bank bookkeeping | | `main` `0xff42b9c0` | section 2 |
| Initialize memory | | `0xff486c40` | "Initializing memory ...", section 2 |
| Node-wide hooks | `0x18`, `0x19` | `main` | empty routines (`0xff5b2b10` and its neighbours return at once) |
| Switch to RAM | `0x40`, `0x41` | `0xff4d4420` | "Switching to RAM and testing CPU ..."; PAL calls and RAM bookkeeping, no chip access but the progress dot counter (section 3) |
| Restore in RAM | `0x43`, `0x44`, `0x45` | `0xff4d5060` | restore of the transfer area, "Shadowing SAL to ..." (section 3) |
| Second stage | `0x1a` to `0x1e` | `main_two`, `0xff42cd70` | section 4 |
| Node id change | `0x59`, `0x5a`, `0x1f`, `0x20` | `0xff4db670`, `0xff4db5a0`, `0xff4e7c90` | "Flushing caches and changing nasid...", section 5 |
| Third stage | `0x21` to `0x27` | `main_three`, `0xff4e7470` | "Done.  Reached main_three", "Init I/O...", "Running", section 6 |
| Load and jump | `0x48` | `0xff519770` | loads "SAL runtime", "Bios Emulator", "EFI" from the flash image, prints "SAL->EFI handoff at ...", calls the EFI entry (section 7) |

The shape is the SHub 1 one ([boot-sequence.md](../../software/firmware/snprom/boot-sequence.md) is a map only); every row below is read from this image.

## 2. After the memory test, before the jump to RAM (`main`, `0xff486c40`)

Node and memory registers; all are in [shub2.md section 4](shub2.md#4-memory-and-directory-registers-the-bring-up-programs) unless marked new here.

| Order | Access | Value and condition | A model must | Grade |
|---|---|---|---|---|
| 1 | R `0x2_101d_0380` bit 8 (`0xff4ae670`, call at `0xff42c24c`) | debug word bit 8 ("no disable", section 8) | return the word the L1 supplied; 0 is normal | established (access); software expectation (value) |
| 2 | `0xff48e6a0`: for each bank whose flag bit 0 is clear (unpopulated or failed): R `0x1_0010`, then W the value (bank field `7 << 8*bank` set) to `0x1_0000`, `0x1_0008`, `0x1_0010` | marks the bank absent in the X, Y and JNR DIMM configuration | store 64 bits | established |
| 3 | R `0x1_0010` (`0xff4879d0`) | sum of the bank sizes; zero gives "No memory on node %I" and stop `0x80` | read back what step 2 left | established |
| 4 | `0xff486c40` "Initializing memory": R `0x1_0010`; per populated bank `0xff479340(1, ...)` runs the memory BIST once more through the same engine as the test (`0x2_0080`, `0x2_0088`, `0x3_8xxx` to `0x6_8xxx` ports, [shub2.md section 4](shub2.md#the-memory-test-engine)) | zero fill by the engine | `0x2_0088` bit 40 clear soon, bit 41 clear, error registers 0, memory reads 0 afterwards | established (access); software expectation (value) |
| 5 | credit workaround `0xff48b420(node, rec, 2)`: R `0x1_00d8`, R `0x1_0008`; if `0x1_00d8` is below 2, W `0x1_00d8` = 2 and run the block-transfer engine (W `0x3004_0100`, `0x3004_0180`, `0x3004_0080` = node and memory offset, W `0x3004_0000` = `((2 - old) * 2) \| 0x1110_0000`, poll bit 20 of `0x3004_0000` for up to 2,000,000 us of RTC) | SAL_A wrote `0x1_00d8` = 2 | return what was written (2), so the first compare ends the routine; the BTE path is then not reached | established (access and constants); inferred (that the compare ends it: the only case read was `2 <= old`) |
| 6 | `0xff48c290(node, 0)`: R `0x1_0020`, W `0x1_0020` and `0x1_0050` with bit 0 cleared, R `0x1_0020` | `X_CFG`, `Y_CFG` bit 0 := 0 | store | established |
| 7 | four W 0 to the first four cache lines of the node's memory (`0xff486c40`, node-relative offsets 0, `0x80`, `0x100`, `0x180`, uncached form with the memory-space bit pair `2 << (38 - V)`) | skipped when CPUID register 2 reads the simulator marker | accept as RAM stores | established (form); inferred (they are memory, not registers: the address form is the memory window) |
| 8 | R `0x3_0000`, W `0x3_0000` and `0x5_0000` with bit 3 set | `DIR_CONFIG` bit 3 (`EN_DIRECC` in the PROM's name table, unverified) | store | established |

## 3. Switch to RAM and the restore (`0xff4d4420`, `0xff4d5060`)

| Step | Access | A model must | Grade |
|---|---|---|---|
| progress dots | R then W `0x2_5003_1580` (+1), several times between `0x40` and `0x45` (`0xff44f470`) | plain storage | established |
| `0xff4d4420` | PAL_TEST_INFO, PAL_COPY_INFO and the CPU test (`0xff516220`) are PAL calls; on a CPU-test failure it shifts the status into the word at `0x2_5003_1500 + 0x10 * slice`, clears SCRATCH6 bits 29:26, sets `0x2_101d_0080` \|= `0x280_0000_0000` and writes `0x2_2000_0000` = `0x1_0001_0000_0000`, then spins | not reached on a pass; the PAL must pass the test | established (sites); the PAL side is the processor model's |
| SCRATCH6 | clear bits `0x15 + slice` and `0x23 + slice` before the jump, set bit `0x15 + slice` after the restore | plain storage | established |
| `0xff4d5060` restore | RAM only (transfer area rebuilt, "Error: SDA xfer space overflowed on restore" if over 0x4000 bytes) | RAM | established |
| shadow the SAL (`0xff4dc990`, only when CPUID register 2 is not the simulator marker) | read 12 MiB (`0xc00000`) of the flash alias in 1 MiB steps into RAM at the shadow base + `0x40_0000`, flushing each (`0xff4fffe0`); then W `0x2_2011_0008` = `(base & 0x1_ff00_0000) \| (1 << 60)`; then set the directory access for the copy: W `0x3_1000` and `0x5_1000` = `6 << 55`, with a memory-engine command `0x40` (W `0x2_0080` = start, W `0x80` = 0, W `0xc0` = all ones, W `0x2_0088` = `length \| (0x40 << 32) \| (1 << 40)`, poll bit 40 clear within 20,000,000 us (`0xff420010` counts microseconds: it multiplies the RTC by the `GC_SRC_CTRL` rate and divides), then W `0xc0` = `0x80_0000_0000`, then R `0x2_0088` bit 41 must be clear) | the flash window must read as the PROM image; the engine must finish and report no failure | established (access and constants); inferred (meaning of `0x2_2011_0008`: the register is `0x8` above the address-mode register, name unknown) |
| after the restore | `0xff516220` again with the entry of `main_two` (`0xff42cd70`, descriptor `0xff672ae0`) | PAL-side | established |

## 4. `main_two` (`0xff42cd70`, codes `0x1a` to `0x1e`)

| Step | Access | A model must | Grade |
|---|---|---|---|
| start | `0xff4250f0` (a PAL call, `0xff4b3a10`) decides whether `0xff424a00` runs: W `0x1000_0400` = 1, and for each further logical processor of this package W to the sibling's `0x1000_0380` (IPI form, global window) a vector | a plain register; one logical processor per slice runs nothing else | established (writes); inferred (siblings only: reasoned from the loop over the PAL's thread count) |
| node election, stage 1 (`0xff4b2850(1)`) | lock cycles and SCRATCH6 fields as in [shub2.md](shub2.md#main-0xff42b9c0-from-the-node-election-to-the-first-console-message) | as there | established |
| `0x1a` | `0xff4b64c0` PAL calls (PAL copy of the PROM's PAL, `0xff4b6b40`), `0xff4a9730` and `0xff481bd0` set the directory access for the SAL shadow again (same W `0x3_1000`, `0x5_1000`, engine command `0x40` as section 3) | as section 3 | established |
| PMI | `0xff43aaf0`, per slice: W `0x1000_0880 + 0x100 * slice` = `(((nasid >> 8) & 0x3f) << 10 \| ((nasid >> 1) & 0x7f) \| (slice << 7)) << 4 \| 5`; W `0x1000_0900 + 0x100 * slice` = `0x4000`; W `0x1000_0400` = 1. Then the PAL registers the PMI entry (`0xff42f8a0`); non-zero status prints "SAL_PMI entry point not registered". At the end (`0xff43fde0`, `0xff414ca0`) W `0x2_5003_1590`, `0x2_5003_15b0`, `0x2_5003_15e0`, `0x2_5003_15f0` = `0xff_0000_0000` | plain registers (the offsets are two of the 27 interrupt-config and enable pairs of section 5) | established (offsets, values); software expectation (the PAL answers 0) |
| `0xff42d580` | reads the NVRAM variables `DisabledMem`, `DisMemReason`, `DisabledCpus`, `DisCpusReason`, the PROM log (`promlog`) and the FIT "PROM debug info" (`0xff4d6610`, `0xff51c540`) | a flash that reads as the image and an empty variable area | established (reads); unknown (the variable store layout, [efi.md](../../software/firmware/snprom/efi.md) is the SHub 1 one) |
| `0x1b` | prints "Init Intercon..." (L1 text `0x1005`), then `0xff42c920`, `0xff4b7d70` build the node's configuration records: L1 requests `0x0003`, `0x0013`, `0x000e`, `0x0006` (chassis and board area), `0x0010` and the console channel; RAM allocation | an L1 (section 7) | established (order); the records are RAM |
| `0x1c` | discovery (`0xff450350`, "Discovering NUMAlink connectivity ..."), section 4a | | |
| `0x1c` | `0xff451040`, `0xff44cf10`, `0xff44cfc0` (SCRATCH6 set-bit helpers for partition and global flags), `0xff44d500` ("nl4r_mip_clear": routers only), `0xff44d070` (tree barrier then global barrier: with one node nothing is read beyond `0x2_5003_1570` and the RTC; not traced to the end) | plain storage | established (call list); inferred (one node passes at once) |
| `0x1d` | `0xff455e80` reads the NVRAM variables `NASIDOffset`, `NASIDStride` and the node-id register `0x1006_0f00` (three reads, `0xff4580a0` twelve more) to number the nodes, then the route tables (RAM only for one node) and `0xff467320` "Distributing routing tables" | `0x1006_0f00` stable | established (reads); the tables are RAM |
| `0x1e` | `0xff4db670` "Flushing caches and changing nasid..." | section 5 | |

**4a. NUMAlink discovery for one node (`0xff450350`).** Skipped with "*** Skipping NUMAlink discovery" when bit 11 of the debug word `0x2_101d_0380` is set (`0xff4ae670(0xb)` at `0xff45002c`). Otherwise:

1. R `0x2_101d_0080` through the chipset method (slot `0x168`, `0xff4ae610`), the "advertisement register" (SCRATCH1). Bit 40 set means the node has a network interface; clear gives no ports (`0xff46a120`). The PROM sets bit 40 itself (`0xff457750`, `0xff4ae560`), so a plain 64-bit register that keeps what was written works.
2. With the network interface present, for each of the two ports p (0, 1): `0xff4690b0` reads `0x2_5000_0048 + 0x2000 * p` (if bit 35 is set it clears it by writing back and reads again; still set means down), then `0x2_5000_0000 + 0x2000 * p`; the port is up only when the low nibble is `0xe` and, over four reads of `0x2_5000_1040 + 0x10 * k` (k = 0 to 3, each polled up to 128 times), bits 22:16 become non-zero. Anything else gives down. The `0x2_5000_0010 + 0x2000 * p` bit 0 is read for the port's enable state (`0xff46a120`). For no neighbours the model returns `0x2_5000_0000` low nibble not `0xe` (for example 0); then no neighbour is probed, no vector is sent, and the pass ends with "Found 1 objects (1 chipsets, 0 routers, 0 iochipsets)". **Established** (offsets, tests); **software expectation** (values).
3. The count of objects goes to SCRATCH1 bits 15:0 (W through slot `0x170`, `0xff4ae560`); a loop over the other chipsets waits up to 300 s (`300000000` in `0xff420010` units, microseconds) for their counts (none with one object). At the end SCRATCH1 bit 22 is set (`| 0x40_0000`). **Established.**
4. Reads and writes of remote registers go through `0xff419e80` (read) and `0xff41ad30` (write): for the local node (vector 0) they are plain accesses, so the vector engine (`0x1007_4100`, `0x1007_4000`, `0x1006_7000`, `0x1006_7080`, `0x1006_7100`, lock at `0x2_101d_0280` bit and `0x2_101d_0180/0188`) is **not used on one node**. With a neighbour it is: W `0x1007_4100` = 0, R `0x1007_4100` (sign bit = busy), W `0x1007_4000` = `0xdeadbeefdeadbeef`, W `0x1006_7100` and `0x1006_7080` = the command (`... \| 0x4000_0e40_0000_0000` for a read), poll `0x1006_7080` then `0x1007_4100` (bit 63 set means done) and read `0x1007_4000`; the router and neighbour behaviour is not modelled here (unknown for SHub 2; [numalink-neighbours.md](../../software/firmware/snprom/numalink-neighbours.md) is the SHub 1 account).

## 5. The node id change (`0xff4db5a0`, `0xff4e7c90`)

Order read: barrier; `0xff4ae880` (master slice only):

| Order | Access | Value | Grade |
|---|---|---|---|
| progress `0x59` | R `0x2_2001_0018`, W it \| `0x100_0000` (bit 24) | | established |
| | `0xff4a9880` (node method slot `0x108`): R `0x1006_0f00`, then W `0x1006_0f00` = old with bits 47:32 replaced by the node id (`(nasid & 0x3fff) << 32`, bits 45:32) and a two-bit code in bits 47:46 (0 to 3, from the node count), bits 53:48 replaced by a one-hot code (1, 2, 4, 8, `0x10`, `0x20`, from the node count) and bit 55 set ([shub2.md section 2](shub2.md#2-the-identification-register) has the field names) | `0x1006_0f00` is writable in bits 45:32 | established (access, field positions); inferred (field meanings) |
| | R `0x2_2000_0000`, W `(old & 0xffff_ffff_ff00_ffff) \| 0x3b_0017` | | established (constants); unknown (register name; the SHub 1 analogue is the CRB message control) |
| | W `0x2_2001_0018` = the value read first (bit 24 back to its old state) | | established |
| progress `0x5a` | | | |

then `0xff4e7c90` (progress `0x1f`):

| Step | Access | Grade |
|---|---|---|
| `0xff500ce0`, `0xff500e00` | the interrupt retarget: 27 pairs (config offset, enable offset) from the table at `0xff5dc248`: R the enable; when it is non-zero, R the config and W it with bits 19:4 replaced by `((nasid >> 8) & 0x3f) << 10 \| (nasid >> 1) & 0x7f \| (old bits 13:11) << 7` and bits 3:0 and the rest kept. Pairs: `0x1000_0480/0500`, `0580/0600`, `0680/0700`, `0780/0800`, `0880/0900`, `0980/0a00`, `0a80/0b00`, `0b80/0c00`, `0c80/0d00`, `0d80/0e00`, `1780/1800`, `1880/1900`, `1980/1a00`, `1a80/1b00`, `0080/0200`, `0180/0280`, `0f80/1100`, `1080/1180`, `1b80/1c00`, `1c80/1d00`, `1d80/1e00`, `1e80/1f00`, `1280/1300`, `1380/1400`, `1480/1500` (the RTC pair, [Linux](shub2-model-rows.md#linux-altix-4700-and-450-after-the-prom)), `1580/1600`, `1680/1700` (all `0x1000_xxxx`). For one node and nasid 0 the rewritten value is the same as the old one except the field layout. | established (offsets, field positions); software expectation (plain registers) |
| `0xff4aea90`, `0xff5b2d60`, `0xff5b5f80` | empty | established |
| `0xff481280(nasid, B, C)` | R `0x3_0000`, R `0x1_0080`, R `0x2_1006_0f00` (bit 54 selects the sharing form), R V; W `0x1_0080` = old with bits 58 and 59 cleared according to the node count (`... & 0xfbff..`, `& 0xf7ff..`), W `0x3_0000` and `0x5_0000` = old with `SYS_SIZE` (bits 2:0) from the node count (0 to 7) and bits 11:10 cleared the same way | established (access and masks) |
| then `0xff51d060` (progress `0x20`) | builds the node's stack arena in the new window (`0xff4f2dd0`, RAM address arithmetic) and jumps to `main_three` through `0xff516500` with type 0: no flush, no PAL call, no chip access | established |

`0xff4db670` copies the new id into its argument frame and flushes with PAL calls; the target of the flush call is `0xff4db5a0` and then `main_three`. **Established.**

## 6. `main_three` (`0xff4e7470`, codes `0x21` to `0x27`)

| Step | Access | A model must | Grade |
|---|---|---|---|
| `0x21` | for a non-zero node number only: `0xff4d0350`, `0xff4f0ab0`, rebuild of the RAM tables; node 0 skips them | | established |
| `0x22` | `0xff4aeaa0`: R `0x1006_0f00`; for i = 0 to 3: W `0x1006_0000 + 0x80 * i`, `0x1006_0480 + 0x80 * i`, `0x1006_0c00 + 0x80 * i` (the last is `SH2_IPI_ACCESS0..3`) = the bitmap word i of present nodes (one bit per node, the packing is inferred), and W `0x1006_0280 + 0x80 * i` = 0 | plain registers | established (offsets, widths); inferred (names: the first two are not named in the Linux header) |
| | `0xff481b20`: `0xff488140` (R `0x3_0000`, W the presence form to `0x3_0xxx` and `0x5_0xxx`), `0xff4886c0` (R `0x1006_0f00`; W `DIR_PRESVEC0..3` from the sharing mode), `0xff4891c0` (the eight `PRIVEC` words, W to `0x3_0300` to `0x3_0370` and `0x5_0300` to `0x5_0370`: `0x4bfff, 0xc96f25b, 0xfffffff, 0x96ffff, 0, 0, 0x4803f, 0x48000`) | store | established |
| | `0xff43ff30` (`0xff4405a0`, "AttrCheck" variable): when the variable selects it, `0xff4f9a20` writes one of the two short tables of [shub2.md W4](shub2.md#main-0xff42b9c0-from-the-node-election-to-the-first-console-message) to `0x2005_0a80`, `0x2005_0080`, `0x2005_0500`, `0x2006_0080`, `0x2006_0480` | store | established (offsets); unknown (which table the default selects) |
| | SCRATCH6 bit `0xc` set (master), `0xff4186f0`, `0xff4dc1c0`, `0xff44d2b0`: RAM and barriers | | established |
| `0x23` | `0xff4b6940` (RAM), `0xff457750` (master: R, then W `0x2_101d_0080` with bit 40 set; builds the processor table in RAM from SCRATCH6 bits `0x1a` to `0x1d` and the per-slice flags), `0xff431030`, `0xff51d3c0` (RAM); `0xff42c980` (every node of this module without processors, "headless" nodes: not present on one node with CPUs), `0xff42cc20` (late init of those) | SCRATCH1 and SCRATCH6 as plain storage | established |
| `0x24` | "Init I/O..." (L1 `0x1005`); the I/O hooks `0xff5b2d40`, `0xff5b2d50` return at once. Debug word bit 14 ("no I/O") is tested only in the headless-node initialization (`0xff4ca500`, call at `0xff4ca52c`) | | established |
| `0x25` | `0xff451080`: partition fences, L1 request `0x0012`; "Checking partitioning information ....", "Erecting partition fences ....": RAM and L1 | an L1 | established (order); inferred (gating) |
| `0x26` | `0xff4b46a0` (NVRAM `CacheSize`), `0xff51c490` ("Syncing EFI var. store": flash and RAM, `0xff517970`, reads `0x1_0010`), `0xff43b040` (NVRAM `LogErrors`, `MfrOverride`, `MaxOut`; R `0x2_5003_1240` through `0xff43fe20`), `0xff4b87b0` ("Checking Prom Rev/Ver", a table walk and delays), `0xff44d2b0`, `0xff43ffe0` | the flash and the NVRAM variables | established (order) |
| "Running" | L1 text `0x1005`; then `0xff4ff200` "Export compliance" (section 7); POD checks: SCRATCH6 bit `0xe` ("Local POD request") and bit `0xf` ("Global POD request") are tested and, when set, the PROM enters the POD; for a normal boot they are clear | bits clear | established |
| `0x27` | `0xff519770` | section 7 | |

SCRATCH6 bits `0xb`, `0xc`, `0xe`, `0xf` and `0x1` in these steps are the firmware flags of [shub2.md](shub2.md#main-0xff42b9c0-from-the-node-election-to-the-first-console-message): `0xb` "debug word loaded", `0xe` and `0xf` POD requests. Their setters are `0xff421bd0` (set, `0xff421430`), tests `0xff421eb0` (`0xff421c30`), all on `0x2_101d_0300` under the node lock.

## 7. The last stage and the console

**The load and the jump (`0xff519770`).** For each of the three components ("SAL runtime", FIT type `0x12`; "Bios Emulator", `0x13`; "EFI", `0x1f`) the PROM finds the FIT entry (`0xff51c540`), loads and relocates the ELF image into RAM (`0xff519140`), and prints "Loading %s ..... DONE". Then `0xff51db70` builds the hand-off (memory descriptors, SAL system table, "%d ptc.g domains"), prints "SAL->EFI handoff at 0x%llx", progress `0x48`, calls the EFI entry (`(*local_30)(...)`), and stops with `0xbe` if it returns. The only chip access in the whole stage is R `0x1_0010` (`0xff4879d0`, memory present for each node); the rest is RAM, flash reads and PAL calls. **Established** (the subtree was walked; no other register access was found by direct calls and method slots).

**L1 requests after the memory test (all with target word `0x0ffff006`, [l1-requests.md](../../software/firmware/snprom/l1-requests.md) describes the frame; ids and call sites below are this image).**

| Id | Where | Reply the PROM parses | If it fails |
|---|---|---|---|
| `0x0001` debug switches | `main`, `0xff48f010`; before the test | 1 int; stored in the low 16 bits of `0x2_101d_0380` and SCRATCH6 bit `0xb` set | the PROM asks on the console "DIP switches [0000]:" (6 s) |
| `0x1005` text | "Prom starting...", "Init memory...", "Init Intercon...", "Init I/O...", "Running", error codes | status only | ignored |
| `0x100b` version | `0xff4a64f0` from `0xff430b00` | status only (3 args sent) | 3 s then error `0x8d` (as in [shub2.md](shub2.md#main-0xff42b9c0-from-the-node-election-to-the-first-console-message)) |
| `0x0003` rack, bay, type | `0xff48e9e0`, from the module-id readers `0xff48ebb0`, `0xff48f1c0`, `0xff490560` | 2 ints | established (id and call chain); replies not decoded for SHub 2 |
| `0x0013` slot, `0x000e` slab | `0xff48ebb0` (from `0xff48f620`), `0xff48ee60` (from `0xff48f810`) | | same |
| `0x0009` partition | `0xff48f9c0` (from `0xff493750`) | 1 int | same |
| `0x0006` chassis and board area | `0xff496c20` via `0xff496ef0`, `0xff4971c0` (`read_chassis_ia`, `read_board_ia`) | the FRU record, 64-byte chunks | a message, then the boot goes on |
| `0x0010` processor presence | `0xff4fbe90` (from `0xff4fc2a0`) | | same |
| `0x0012` | `0xff490c40` from `0xff451080` | 1 int | |
| `0x0005` firmware revision | `0xff48fc60` from `0xff4ff200` | 3 ints (major, minor, patch) | **boot halts**: "Export compliance verification failure: system controller firmware revision unavailble" |
| `0x0017` limit | `0xff4ff040` | 1 int | an error value is taken as a huge limit and passes |
| `0x0016` weight | `0xff4feeb0`, once per I/O node (odd node number) | 1 int | an error counts as 0 |
| `0x0008` | `0xff48ff50` from `0xff4c74c0` | a string | |

The export-compliance check (`0xff4ff200`, progress `0x26` onward, skipped when CPUID register 2 is the simulator marker): the revision value `major * 1,000,000 + minor * 1,000 + patch` must exceed `0x100594` (compare at `0xff4ff360`; the message prints "required 1.50.5"); the sum of the per-node weights (the processors' own value from the node record, and `0x0016` for each I/O node) must not exceed the `0x0017` limit, else "maximum performance value exceeded" and the PROM kills every node (`0xff4e2c30(n, 0x90)`). **Established** for the compare constants and the messages; the weights of the processors come from the node record built from `0x0010` and the CPU table, **unknown** for their size.

Console and L1 UART: as [shub2.md M7 to M9](shub2.md#main-0xff42b9c0-from-the-node-election-to-the-first-console-message). The PROM's output after "Prom starting..." is printed on the console by `0xff429600`; the console objects and where the characters go are the same exchange (class-2 frames on the UART, `0x1003_8000` to `0x1003_8180`).

**L2.** No L2 request is sent on the boot path: the `version` probe to `0x1ffff003` and the `p %d rst` and `p %d pwr d` texts are in the reset and power-down helpers (`0xff4a0820` called only from `0xff41f970` and `0xff41fbb0`, which are not reached from `main`, `main_two` or `main_three`). With no L2 a boot sends nothing to it. **Established** (callers); the answer an L1 gives to the probe is the one in [../l2/README.md](../l2/README.md) (non-zero status when no L2 is attached).

**The debug word (DIP switches).** The PROM prints this table when it prompts (string at `0xff5db140`), so the bits are established as the PROM's own names: `0001` no diag, `0002` heavy diag, `0003` mfg diag, `0004` verbose, `0008` global pod, `0010` local pod, `0018` no mem pod, `0020` default env, `0080` no err clear, `0100` no disable, `0200` output prefixes, `0400` plain console, `0800` no NUMAlink, `1000` dump errors, `2000` no autoboot, `4000` no I/O. The bits the path above tests: 2 (extra prints), 8 and 9 (disable handling), `0x800` (skip NUMAlink), `0x4000` (skip I/O on headless nodes), 3:2 and 5 (POD and environment). A debug word of `0x4800` skips both NUMAlink discovery and the TIO initialization; it is a legitimate L1 setting and not a hardware fact about the node.

## 8. TIO and PIC

**Part numbers and objects.** The chipset method tables the part-number walk (`0xff423100`, table list at `0xff5fd888`) chooses among: SHub 2 (part `0x254`, name "SHub2"), the NL4 router (`0x239`, "NL4router") and the TIO (part `0x4422`, name "TIO"). **Established** (the three test functions at `0xff4ae5e0`, `0xff4a9540`, `0xff4af370`). A TIO is a NUMAlink chipset with an odd node number, found by the discovery of section 4a through the same vector reads (its chip id is the first word, bits 27:12 part, 31:28 revision); with no link up it is never found.

**Initialization of a headless node (`0xff42c980`, `0xff42cc20`).** Only for nodes the discovery found and that have no processors. Early (`0xff4e0150`, "Initializing headless node %I"): TIO method slots `0x120` (`0xff4af800`, 24 accesses), `0x2f8`, `0x2a8`, `0x308`, then R and W of SCRATCH1 (`0x101d_0080` \| `0x200_0100_0000_0000`) and slots `0x18`, `0x288`, `0x318`, `0x2e0`; late (`0xff4e0520`): slots `0x128`, `0x300`, `0x310`, `0x20`, `0x200`, `0x290`, `0x320`, `0x2b0`, `0x2e8` (`0xff4ca6f0`, "tio_io_late_init_headless", which calls `tio_init` `0xff4cc2d0` unless debug word bit 14 is set). The slot bodies were listed but not read register by register; the registers seen in them are in the table below as a census, not as a trace.

| Access | Where | Grade |
|---|---|---|
| W `A(n, 0x9000_0480)` = `(a << 52) \| (b << 4)`, W `A(n, 0x9000_0300)`, W `A(n, 0x9000_0500)` = `0xd` | `0xff449b60` (a TIO method) | established (offsets); unknown (meaning) |
| W `A(n, 0x901c_0000)` = 0, R `A(n, 0x9006_0e80)`, and a run of R, W, R, R pairs at addresses taken from tables | `0xff4af800` (`tio_chipset_early_init_headless`) | established (the first two); unknown (the table addresses) |
| R32 (`ld4.acq`, `0xff4cc146`) at `(n << (40 - V)) \| bit 63 \| c * 0x1000_0000` for c = 0 to 2, part number in bits 27:12: the corelet identification; part `0xe000` or `0xe010` selects the first bridge set-up (the PCI-X corelet; Linux names it `tiocp`, inferred) (`0xff4cae30`, `0xff513d10`), `0xe020` a second bridge set-up (`0xff4caf50`, `0xff514a30`; inferred to be the AGP corelet that Linux names `tioca`); R64 `A(n, 0xb000_be18)` (through the read helper, `0xff4cc01c`) must equal `0xf` for corelet 3 | `0xff4cc2d0` (`tio_init`, "corelet_discover: lbrd = 0x%x, type = 0x%x, base = 0x%lx") | established (reads, comparisons); inferred (names) |
| R then W `A(n, 0xb000_6100)` with bit 12 cleared; R then W `A(n, 0xb000_8100)` with bit 61 cleared unless the board type byte is `b` | `0xff4ca8e0` | established |
| the PCI-X bridge routines `pcireg_*` for bridge types PIC and TIOCP (`0xff507650` to `0xff512080`, "unknown bridgetype" for the rest) | register helpers; not reached from the three stages by direct calls | established (they exist); unknown (who calls them: SAL procedures the OS invokes, as for SHub 1) |

Corelet part `0xe000`, `0xe010` and `0xe020` are what the TIO's own page holds ([devices/tio](../tio/README.md)); this page does not edit it. **Unknown:** every TIO register the slot bodies touch beyond the five rows above, whether the TIO's L1-side request `0x0016` is sent on an I/O blade (it is sent once per odd node that the discovery found), and which `pcireg_*` helpers the PROM itself calls.

## 9. Ready-to-model rows for reaching `Shell>` on one node

Everything the earlier page lists still applies. In addition, from the memory test to the EFI jump a node answers:

| Row | Access | Must answer | Grade |
|---|---|---|---|
| Debug word | R/W `0x2_101d_0380` | low 16 bits written by the PROM from the L1 reply (id `0x0001`); default 0 | established |
| Election and flags | R/W `0x2_101d_0080` (SCRATCH1), `0x101d_0100` (SCRATCH2), `0x101d_0280` (SCRATCH5), `0x101d_0300` (SCRATCH6), lock `0x101d_0180/0188` and `0x101d_0200/0208` | plain 64-bit storage, locks read 0 when idle | established (use); software expectation |
| Progress dot | R/W `0x2_5003_1580`, `0x2_5003_1570`, `0x2_5003_1240`, and the writes of 0 to `0x2_5003_1110`, `1360`, `1370` (zero stores of [shub2.md W2](shub2.md#main-0xff42b9c0-from-the-node-election-to-the-first-console-message)) and `1590`, `15b0`, `15e0`, `15f0` (W `0xff_0000_0000`) | plain storage | established |
| Memory | `0x1_0000` to `0x1_00f8`, `0x1_0010`, `0x1_0020/0050`, `0x1_0080`, `0x1_00d8`, `0x3_0000/0x5_0000`, `0x3_1000/0x5_1000`, `0x3_0100` to `0x3_0370` and `0x5_...`, `0x2_0080`, `0x2_0088` | as sections 2 and 3; `0x1_00d8` reads back 2 | established; software expectation |
| BTE | `0x3004_0000/0080/0100/0180` | reachable only if `0x1_00d8` reads below 2; then `0x3004_0000` bit 20 must clear within 2 s | established (access) |
| Interrupt pairs | the 27 pairs of section 5 | plain storage, reset 0 | established (offsets); software expectation |
| IPI and permissions | `0x1006_0000`, `0x1006_0280`, `0x1006_0480`, `0x1006_0c00` (+ `0x80 * i`, i = 0 to 3) | plain storage | established (offsets); inferred (meaning) |
| Node id | `0x1006_0f00` | writable bits 45:32 (id), 47:46, 55:48; reads back | established |
| Address mode | `0x2_2011_0000` (read), `0x2_2011_0008` (written once) | V in 0 to 4; the second register plain storage | established (use) |
| `0x2_2000_0000`, `0x2_2001_0018` | R/W once each | plain storage; `0x2_2001_0018` bit 24 not interpreted | established |
| NI | `0x2_5000_0000 + 0x2000 * p` low nibble not `0xe`; `0x2_5000_0048 + 0x2000 * p` bit 35 clear; `0x2_5000_0010 + 0x2000 * p` bit 0 anything | link down on both ports | established (offsets, tests); software expectation (values) |
| Vector engine | `0x1007_4100`, `0x1007_4000`, `0x1006_7000`, `0x1006_7080`, `0x1006_7100` | not accessed on one node | established (the local path skips it) |
| Flash | read of the PROM image at the flash alias; 12 MiB | serve reads | established |
| L1 | ids of section 7; `0x0005` returns 3 ints at least 1.50.5 | as section 7 | established (ids and parse); software expectation (values) |
| L2 | none | nothing is sent | established |
| TIO | none if no TIO is present; if present, section 8 | | inferred (a one-blade, no-TIO system finds none) |

## 10. Unknowns and what would settle them

- **Replies of the L1 for every id of section 7 beyond `0x0001`, `0x0005`, `0x0017`, `0x0016`.** The argument counts and types are in `0xff494680` calls; the SHub 1 pages describe the same ids and are a hint, not evidence. Route: decode each caller's parse call (`0xff494680` format, third and later arguments) and the L1 model; the L1's own firmware (sysco) answers what it sends.
- **The processors' weight in the export check.** It is taken from the node record built from `0x0010` (`[node + 0x100]` of the module object); settle by reading `0xff4fc2a0` and what stores it.
- **NUMAlink with a neighbour (vector engine commands and reply bits), router objects and routing tables.** Not read for SHub 2. Route: a second reading of `0xff419e80` and `0xff41ad30` with a router present, and the router method table (`0xff5fd188`).
- **TIO and bridge registers** (section 8). Route: read slots `0x120`, `0x2f8`, `0x2a8`, `0x308`, `0x288`, `0x318`, `0x2e0` of the TIO table and `0xff4cae30`, `0xff513d10`, `0xff4caf50`, `0xff514a30`; the TIO page has the Linux side.
- **The names of `0x2_2000_0000`, `0x2_2001_0018`, `0x2_2011_0008`, `0x1006_0000`, `0x1006_0280`, `0x1006_0480`, `0x2_5000_0010` and the NI fields.** The PROM's register-name table holds them; its entries were not found (no 8-byte pointer to the name strings exists; the layout needs a read of the decoder `0xff4e6410`).
- **Whether the memory engine must write zeros.** The PROM relies on zeroed memory after "Initializing memory"; a model that starts zeroed passes.
- **Real-time clock and delays.** All waits go through the RTC at `0x2_101c_0000` and the `GC_SRC_CTRL` rate (`0xff41ffa0`, `0xff420010`, `0xff420130`): a model whose RTC does not advance hangs every poll (the longest on this path are 10 s (`0xff450350` retry), 20 s (`0xff475240` memory engine), 300 s (peers)).
- **The simulator marker.** CPUID register 2 equal to `0xaeee_eeee_8bad_beef` skips the export check, the SAL shadow, the credit workaround, the four RAM zero stores and every L1 exchange (`0xff494e20` returns `-0x18` without a frame), and makes the RTC read scale by 128 (`0xff420010`, `0xff420130`). A model that presents it takes a different path than hardware does; this page's rows are the path without it.
- **EFI.** What EFI and the SAL runtime do after the jump (console through the SAL, the shell prompt) is not read for SHub 2; [efi.md](../../software/firmware/snprom/efi.md) is the SHub 1 account and fills no SHub 2 row.
