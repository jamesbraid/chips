# SHub 2: register rows a model needs for the PROM and for Linux

For someone building a SHub 2 model. It picks, from [shub2.md](shub2.md), the rows the shipped SHub 2 firmware (snprom 10.54 build 70399, SAL 1.54; the 10.40 build, SAL 1.40, has the same reset path) needs to get from reset to its first console message, and says plainly what is not yet read between there and the `Shell>` prompt. The SHub 2 PROM listing was re-read for this page on 2026-11-22; independent review is pending.

**Grades.** *established*: the access (address, width, direction, value) is read in the instruction listing, or a public Linux v5.3 header defines it. *software expectation*: what the code or the Linux driver needs, not a hardware fact. *inferred*: reasoned, reason given. *unknown*: not settled. No SHub 2 manual is held and no hardware read exists, so **no row has an established reset value**; every "must return" below is a software expectation. All offsets are in the local window (`0x2_0000_0000` + offset, bit 63 set), or the global form of [shub2.md section 1](shub2.md#1-address-map) for another node.

## Which chip is in a 3700 Bx2

SHub 1.2, established. The Altix 3700 Bx2 guide's CR-brick block diagram labels its four nodes "SHUB 1.2" ([Bx2 page](../../platforms/sn2/altix-3700-bx2.md)). This page's rows do not apply to the Bx2; they apply to the Altix 4700 and 450 (the machines SGI's `README.snprom` lists for the SHub 2 image).

## Rows that carry the PROM to its first console message

| Row | Address and access | A model must | Grade |
|---|---|---|---|
| Progress ports | W16 `0x2_f000_0000 + 0x1_0000 * n`, n = `cr.lid` bits 24:23 | accept any value (codes `0x30`, `0x31`, `0x35`, `0x32`, `0x34`, `0x08`, `0x0c`, `0x0d`, `0x0e`, `0x10` onward; `0xb0` to `0xb7` are stops; `0xb7` is a PAL `0x208` status of `-4`, `0xb6` any other nonzero status) | established (access); software expectation (any value) |
| Junk bus time | W `0x1002_0000` = `0xffff_ffff_0003` | accept | established (access) |
| Address mode `V` | R `0x2_2011_0000` | return 0 to 4 (it indexes a five-entry table; no range check) | established (use); unknown (real value) |
| Node-addressing row | RW `0x101d_0c00` (`SCRATCH24`) | store 64 bits and read back | established |
| Clock | W `0x1006_0700` (`GC_SRC_CTRL`) = `0x1_0000_0000`, W `0x101c_0000` (`RTC`) = 0, W `0x1006_0700` = `0x1_0000_0041` (B2 to B4, `0xff4a9810`; identical in 10.40 at `0xff4a8ac0`) | make `RTC` count after the last write, 20 ticks per microsecond (the PROM converts with the `MAX_COUNT` field it reads back: bits 13:4 = 4) | established (writes); software expectation (rate) |
| PAL entry choice (B5) | R `0x101d_0300` (`SCRATCH6`) bit 21 + slice | read the bit as 0 until the PROM sets it (it does in the lock cycle of B8); the SAL_A entry is then used | established (access); software expectation (value) |
| Reset entry (B1, B7) | progress `0x31` at `0xff42fed0`, `0x32` and `0x34` around the PAL call at `0xff4b3c30`, `0x35` at `0xff430226` | the PAL call (index `0x208`, `r29 = 0x100_0000`, `r30 = 0x4_0000`) is the processor's, not the chip's; the chip needs only to serve plain RAM at physical `0x100_0000` upward | established (sites); inferred (cache-as-RAM role) |
| Node number and part | R `0x1006_0f00` bits 45:32 (stable, the node's NASID, even); R offset `0x0` bits 27:12 = `0x254`, bits 31:28 any | as stated; part `0x254` selects the SHub 2 method table | established (reads); inferred (`0x254` is the SHub 2 part, from table order) |
| Node lock and scratch | RW `0x101d_0200`/`0208`, `0180`/`0188`, `0280`, `0100`, `0380`, `0080`/`0088` | plain 64-bit storage; the `...0208` and `...0188` reads return 0 when idle | established (access); software expectation (lock reads 0) |
| L1 console link | `0x1003_8000`, `0x1003_8080`, `0x1003_8100`, `0x1003_8180`, `0x1003_8200` | `0x1003_8080` bit 0 clear soon after a word is written; `0x1003_8180` bit 0 clear when there is no L1; `0x1003_8200` (read on the PAL-pair selection, reason 3 only) bit 39 clear | established (access); software expectation (values) |
| Memory and directory | [shub2.md section 4](shub2.md#4-memory-and-directory-registers-the-bring-up-programs): `0x1_0000` to `0x1_00f8`, `0x3_xxxx` and `0x5_xxxx` blocks, `0x3_8xxx` to `0x6_8xxx` test ports, `0x2_0080` and `0x2_0088` | accept every write; `0x2_0088` bit 40 clear soon after the command, bit 41 clear; error registers 0 | established (access, constants); software expectation (a pass) |

Constants the PROM programs (all read in the listing, 10.54): `X_CFG` and `Y_CFG` `0x4856_5320_3324_110e` (bit 53 also set when the DIMM record's word at offset 8 is 4); `X_DQCT_CFG` and `Y_DQCT_CFG` fields `5, 1, 2, 4, 5, 2` (value `0x25_4215`); `MEM_RED_BLACK` `0x4e20_0400`; `MISC_MEM_CFG` `0x0fc4_0000_000c_4c4c` (then bits 58 and 59 cleared by size); credit controls `PI_MD_RQ` 12, `PI_MD_RP` 4, `XN_MD_RQ` 11, `XN_MD_RP` 3 (and `PIO_RQ` 2 from SAL_A); `DIR_TIMER` `0x1000`; `DIR_LOCVEC` all ones; `DIR_PRIVEC` `0x4bfff, 0xc96f25b, 0xfffffff, 0x96ffff, 0, 0, 0x4803f, 0x48000`. Their field meanings are inferred from the PROM's own register-name table; the DIMM-derived values (DIMM_CFG, refresh, ODT) depend on the L1's DIMM data.

## Between the first console message and `Shell>`

**Unknown.** The SHub 2 listing has been read through "Init memory", the memory test start and the directory set-up (progress `0x16` and the "Testing memory" print), and not beyond. What a one-node SHub 2 PROM needs after that (the NUMAlink interface set-up, TIO and PIC discovery, the interrupt registers the second-stage code and the EFI start use, the exit from the memory test) is not read for SHub 2. The SHub 1 pages ([prom-reset.md](prom-reset.md), [interrupts.md](interrupts.md)) are a sibling's behaviour and do not fill any SHub 2 row. Route: continue the same reading from the caller of the memory-test print (`0xff47a970`) to the EFI start, listing every register constant per routine ([the question](../../questions/shub2-reset-open.md)).

## Linux (Altix 4700 and 450) after the PROM

Names and offsets come from the public header (Linux v5.3 `shub_mmr.h`, `SH2_` constants), so they are established; behaviour is what the kernel expects. [registers.shub2.toml](registers.shub2.toml) holds them.

| Row | Offset | Linux needs | Grade |
|---|---|---|---|
| `IPI_INT` | `0x1000_0380` | a store with the send bit delivers the vector to the named processor, including the sender | established (name, offset); software expectation (behaviour) |
| `EVENT_OCCURRED` and alias | `0x1001_0000`, `0x1001_0008` | read, clear through the alias | same |
| `RTC`, `RTC_INT_CONFIG`, `RTC_INT_ENABLE`, `INT_CMP` | `0x2_101c_0000`, `0x1000_1480`, `0x1000_1500`, `0x101b_0080` | a monotonic counter and comparator interrupts for the timer | same |
| `IPI_ACCESS0..3` | `0x1006_0c00` | writable (SAL_A sets 1, 0, 0, 0) | established (access) |
| `PIO_WRITE_STATUS` and alias | `0x2007_0200`, `0x2007_0208` | read idle after posted writes drain | same |
| `PTC` | `0x1_7000_0000` | one store per target node; the kernel then waits on the PIO write status | established (name, offset); behaviour unknown (window width) |
| `BT_ENG_*` (BTE) | `0x3004_0000` to `0x3004_0180` | only if the kernel uses the BTE; field layout unknown | established (offsets); unknown (fields) |
| `SN_SAL_GET_SN_INFO` | PROM, not a register | shub type flag 1 (SHub 2), mask `(1 << (V + 10)) - 1`, shift `40 - V`, sharing domain from `NODE_ID` bit 54 | established (read in full, [shub2.md section 1](shub2.md#nasid-shift-and-mask-established-as-the-firmwares-computation)) |

Console: the kernel's SN console goes through SAL calls to the L1, so the rows above suffice for a serial login (inferred: the kernel reaches the L1 through the PROM, not through a chip UART it programs itself). **Disks and networking are not covered**: they sit behind TIO nodes and PIC bridges, and the TIO register set is five names from Linux and nothing else ([devices/tio](../tio/README.md)). A model that boots the PROM to a prompt and runs Linux to a console login on memory alone needs no more than the rows above plus the unread stretch; one that reaches a disk needs TIO, which is unknown.
