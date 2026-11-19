# Indigo2 (IP22) PROM environment store

The PROM keeps its environment (`setenv`, `printenv`, the variables that boot reads) in a 93CS56 serial EEPROM on the HPC3. This page covers the layout, the checksum, the defaults and the write order, for the IP22 image `SGI Version 5.1 Rev B IP22 Sep 16, 1993 (BE)`, part 070-8127-002, sha256 `be6b22c3b90adf6eebc18da11ce49e59292eeab35b694c6e8bd75ef485a40241`. Byte offsets are from the start of the store.

Grades: **established** (read in the image or a published source, the claim follows), **observed** (a boot capture), **software expectation**, **inferred**, **unknown**. The part is the 93CS56, not the DS1286 or DS1386 RAM. The checksum and init routines take the serial path when bit 0 of the system ID register (physical byte `0x1fbd985b`; the public Linux header says these IOC registers must not be word-accessed) is set. This image reads that bit as its machine test and so runs the serial path on IP22. Established: the PROM read in the routine, and the public Linux header that names the bit `SGIOC_SYSID_FULLHOUSE`. The same image also holds the DS1386 path (base `0x1fbe0100`, one byte per 32-bit word), which the Indy PROM takes. The Indy image `070-9101-011` has the same record table: the same offsets, lengths and defaults. Its write path is not decoded here. IP28 is not covered.

## Layout

The store is 256 bytes, 128 big-endian 16-bit words. The HPC3 register at physical `0x1fbb0008` drives the chip; the PROM reaches its control bits at `0xbfbb000b` (the low byte). Established (PROM bit-bang, and the Linux `ip22-nvram.c` read path).

Each variable has a fixed offset and length, and its value is a NUL-terminated string that fills the field. The offsets and lengths match the IRIX 6.5.7 header and the PROM's own record table (the table's code field equals the byte offset for every record). Established.

| Offset | Length | Item |
|---|---|---|
| 0 | 1 | checksum |
| 1 | 1 | layout revision, `0x08` |
| 2 | 2 | `console` |
| 4 | 48 | SystemPartition |
| 52 | 18 | OSLoader |
| 70 | 28 | OSLoadFilename |
| 98 | 12 | OSLoadOptions |
| 110 | 6 | pagecolor |
| 116 | 5 | dbaud |
| 121 | 1 | diskless |
| 122 | 8 | TimeZone |
| 130 | 48 | OSLoadPartition |
| 178 | 1 | AutoLoad (`Y` or `N`) |
| 179 | 2 | diagmode |
| 181 | 4 | netaddr (raw bytes) |
| 185 | 1 | nogfxkbd |
| 186 | 5 | keybd |
| 191 | 6 | lang |
| 197 | 17 | passwd_key |
| 214 | 17 | netpasswd_key |
| 231 | 1 | scsiretries |
| 232 | 3 | volume |
| 235 | 1 | scsihostid |
| 236 | 1 | sgilogo |
| 237 | 1 | nogui |
| 238 | 1 | rbaud |
| 239 | 1 | autopower |
| 240 | 1 | monitor |
| 241 | 1 | rebound |
| 242 | 8 | free |
| 250 | 6 | eaddr (above 250 is write-protected) |

The offsets of the first 250 bytes come from the IRIX header; byte 250 onward is the protected Ethernet address. Established.

## Checksum

Source: a reading of the IRIX 6.5.7 source, with the PROM's own routine checked by disassembly.

1. Start with `c = 0xa5` (8 bits).
2. For each word `w` from 0 to 127, with bytes `2w` (high) and `2w+1` (low):
   - `w = 0`: `c ^= byte1` (the revision byte only; byte 0 is the checksum and is left out).
   - otherwise: `c ^= byte(2w) ^ byte(2w+1)`.
   - rotate `c` left by one bit.
3. Byte 0 must equal `c`, and byte 1 must equal `0x08`.

The checksum covers all 256 bytes except byte 0, including the protected bytes 250 to 255. Established: the PROM loop in `FUN_c00000001fc2b5d0` was read in the disassembly; the decompiler's output for word 0 was misleading and was not used.

The PROM's validity check (`FUN_c00000001fc2c0dc`) compares byte 0 with `c` and requires byte 1 to be `0x08`. A mismatch in either prints `NVRAM checksum is incorrect: reinitializing.` and writes the defaults. Established. The IRIX source tries the checksum twice; the PROM shows one comparison. Minor, unresolved.

## Power-on reads and defaults

Both branches of the PROM's `init_env` walk the same 27-record table (the table above lists 29 rows; which two fall outside the walk is not recorded), so every variable is loaded on each boot. Established. The defaults below come from the table strings. An empty default is not written when the store is reinitialised.

| Variable | Default | Grade |
|---|---|---|
| console | `g` | established (string); written on reinit: inferred |
| TimeZone | `PST8PDT` | established; inferred for reinit |
| dbaud | `9600` | established; inferred for reinit |
| volume | `80` | established; inferred for reinit |
| sgilogo | `y` | established; inferred for reinit |
| autopower | `y` | established; inferred for reinit |
| diskless | `0` | established; inferred for reinit |
| AutoLoad | `Yes` (one byte stored, `Y`) | established; inferred for reinit |
| netaddr | `192.0.2.1` | established string; stored form unknown (see below) |
| eaddr | `ff:ff:ff:ff:ff:ff` | established string; whether reinit writes it: unknown |
| every other record | empty | established; not written on reinit (inferred) |

The consumers of `console`, `AutoLoad`, the OSLoad fields and `netaddr` are the strings the image holds. Software expectation.

## setenv and the write order

- `setenv` writes the variable's bytes word by word, each word in place: write-enable, WRITE, wait for ready, write-disable. Established (`FUN_c00000001fc2b860`, `FUN_c00000001fc2bf10`, and the same sequence in IRIX source).
- After the data, the checksum is recomputed and byte 0 is written last, as a read-modify-write of word 0.
- The writer copies the field's full length from the value pointer and does not stop at the NUL. A value shorter than its field therefore stores the bytes that follow its NUL in the caller's buffer. Established (writer loop, and the same copy in the IRIX source). The contents of those bytes are unknown. The defaults fit their fields exactly, so a blank-store reset is not affected, and `setenv console d` fits (`d`, NUL).
- The 93CS56 erases on WRITE. There is no append, no wear levelling and no separate erase cycle. Inferred: no 93CS56 datasheet is held, and the PROM issues no separate erase command.
- Revision and checksum are written together when the store is reinitialised (revision first, then checksum). Established (`FUN_c00000001fc2c170`).
- Interrupted write: the checksum is last, so an interrupted `setenv` leaves a stale checksum. The next boot reinitialises the whole store to defaults. Inferred from the write order and the reinit branch.
- `resetenv`: not decoded. Unknown.

## Worked example: `setenv console d`

Only the change is exact here. The checksum is affected only through word 1.

- Before: bytes 2 and 3 are `67 00` (`g`, NUL). Byte 0 is `c`.
- After: bytes 2 and 3 are `64 00` (`d`, NUL). Byte 0 is `c ^ 0x81`.

Why `0x81`: word 1's `hi ^ lo` changes from `0x67` to `0x64`, a delta of `0x03`. Words 1 to 127 each rotate `c` left once after the XOR, 127 rotations in all, and rotating left by 127 is the same as rotating right by 1. `0x03` rotated right by 1 is `0x81`. A script checked this on 2000 random stores; the delta was `0x81` every time.

Blank store: the exact bytes after reinitialising an erased store are unknown. Two things are not settled: how netaddr is stored on IP22 (its reinit branch takes a different route from the other fields and was not decoded), and whether the protected bytes are written. An erased store has checksum `0x5a` by the arithmetic above; that value is computed, not observed.

## Unknown

- `resetenv`, and the storage form of netaddr on IP22.
- Whether reinitialisation writes eaddr (bytes 250 to 255).
- The IP28 image: the IRIX header gives revision 9 for IP26 and IP28, and that was not checked against the IP28 PROM.
- The IRIX 6.5.22 and 6.5.30 nvram ioctl and `nvram(1M)` paths: not read.
- The IP24 write path and whether its netaddr and protected bytes match this page: not decoded.
- A documented recovery that pokes the Ethernet address at `0xbfbe04e8`: this image has no reference to that address. Its only window reference is the base `0x100` in the DS1386 routines.

## Observed

A PROM-console capture of a live IP22 ran `printenv`: `console=g`, `diskless=0`, `dbaud=9600`, `volume=128`, `sgilogo=y`, `autopower=y`, `AutoLoad=Yes`, `TimeZone=PST8PDT`, plus `netaddr` and `eaddr`. The runtime-only variables `ConsoleIn`, `ConsoleOut`, `NoAutoLoad` and `cpufreq` are set in memory and not stored. Observed. `volume=128` is not the default, so that store was set after reinit.

## Review (IP22 PROM environment, f3d2d71)

Independent review on 2026-11-18 by a reviewer who did not write this page. Revision: the page as added in f3d2d71; it is unchanged on main at e0a328f. Sources: the public Linux/MIPS tree tree at c9bace5bce3 (`arch/mips/sgi-ip22/ip22-nvram.c`, `arch/mips/include/asm/sgi/hpc3.h`, `ioc.h`, `pi1.h`, `ip22.h`, `arch/mips/sgi-ip22/ip22-hpc.c`), the public NetBSD and OpenBSD sgimips and sgi trees for the variable names, and an independent public emulator of the same store, used only as a cross-check and never as an authority. The IP22 PROM image is listed in `references/prom-images.md` but is not held in this checkout, so no PROM byte was read. The reviewer did not read the IRIX sources the page cites.

**Method.** Offsets were computed by hand from the struct definitions in the Linux headers. The record table was checked by summing its field sizes (it tiles the 256 bytes exactly). The checksum and the setenv delta were recomputed in a script that uses the page's algorithm, over 2000 random stores for the delta.

**Claims.** Numbered in page order. Verdicts: confirmed, wrong, unsupported, UNSURE.

| No. | Line | Claim | Checked against | Verdict |
|---|---|---|---|---|
| 1 | 5 | The store is a 93CS56 (128x16), not DS1286 or DS1386 RAM | Linux `ip22-nvram.c`: the 93CS56 read path is taken when `ip22_is_fullhouse()`, otherwise a byte path over `bbram`. `hpc3.h` calls `rtcregs` the Dallas clock | confirmed |
| 2 | 9 | The EEPROM register is at physical 0x1fbb0008 | `eeprom` is at offset 0x30008 in `struct hpc3_regs`, base 0x1fb80000 | confirmed |
| 3 | 9 | The PROM reaches the control bits at 0xbfbb000b (low byte) | Address follows from claim 2 and big-endian byte order. The PROM's own access not read | confirmed for the address; UNSURE for the PROM side |
| 4 | 5 | The serial path is taken when bit 0 of sysid is set | `SGIOC_SYSID_FULLHOUSE` is 0x01, tested by `ip22_is_fullhouse()` | confirmed for Linux; the PROM's test UNSURE |
| 5 | 5 | The sysid register is at physical 0x1fbd9858 | The IOC base 0x1fbd9800 is `pbus_extregs[6]` (confirmed). `pi1_regs` is 0x28 bytes, then 0x18 bytes of IOC fields, then three pad bytes, so sysid is at +0x5b, physical 0x1fbd985b. The header also says these registers are byte-wide and word access is wrong | wrong as a byte address; 0x1fbd9858 is the first pad byte of the containing word |
| 6 | 5 | The DS1386 path has base 0x1fbe0100, one byte per 32-bit word | `bbram` is at offset 0x60100 in `hpc3_regs`. Linux reads `bbram[reg] & 0xff` from a u32 array | confirmed |
| 7 | 5 | The Indy image 070-9101-011 has the same record table | Not checked: no Indy PROM byte read here. Linux's IP24 path shows byte access only. The emulator treats both models as one block layout, which is not evidence | UNSURE |
| 8 | 9 | The store is 256 bytes, 128 big-endian 16-bit words | Linux 128x16 comment; big-endian target | confirmed |
| 9 | 13-45 | Field offsets and lengths | Offsets 0, 1, 2, 116, 121, 122, 178, 232, 236, 239 and 250 agree with the emulator. The rest rests on the IRIX header and the PROM record table, neither read | UNSURE (the other offsets) |
| 10 | 53-58 | Checksum: seed 0xa5, word 0 uses byte 1 only, rotate left after each word, byte 0 equals the result, byte 1 is 0x08 | Same algorithm as the emulator. The cited IRIX source and the PROM loop not read. No public tree searched has it | UNSURE |
| 11 | 60 | Checksum covers all bytes except byte 0, including 250 to 255 | As claim 10; the emulator agrees | UNSURE |
| 12 | 62 | The PROM's validity check prints `NVRAM checksum is incorrect: reinitializing.` and writes defaults | PROM not read; message not checked | UNSURE |
| 13 | 68-77 | Defaults: console g, dbaud 9600, diskless 0, TimeZone PST8PDT, AutoLoad Y, volume 80, sgilogo y, autopower y | Emulator defaults agree on all eight, with the same offsets. The PROM table not read | UNSURE (agrees with the emulator) |
| 14 | 78-79 | Defaults netaddr 192.0.2.1 and eaddr ff:ff:ff:ff:ff:ff | Not checked. The emulator has no netaddr default and leaves eaddr alone. 192.0.2.0/24 is the documentation range, so the page should say whether the string is the PROM's or a placeholder | UNSURE |
| 15 | 80 | Every other record defaults to empty | Not checked | UNSURE |
| 16 | 66 | Both `init_env` branches walk the same 27-record table | The table at lines 13 to 45 has 29 rows, and the page does not say which two sit outside the walk | inconsistent (count) |
| 17 | 86 | setenv writes word by word: write-enable, WRITE, wait for ready, write-disable | PROM not read. The emulator uses the same opcodes, which is not evidence | UNSURE |
| 18 | 88 | The writer copies the full field length and does not stop at the NUL | No source | UNSURE |
| 19 | 87 | The checksum is recomputed and byte 0 is written last, as read-modify-write of word 0 | PROM not read | UNSURE |
| 20 | 90 | Revision and checksum are written together, revision first | PROM not read | UNSURE |
| 21 | 89 | The 93CS56 erases on WRITE, with no append, wear levelling or separate erase cycle, marked established | No datasheet cited. None held in the public sources searched; the one hit (a PLX PCI9060 datasheet) was not opened | unsupported |
| 22 | 91 | An interrupted setenv leaves a stale checksum and the next boot reinitialises | Follows from claim 19, not checked | UNSURE (inferred) |
| 23 | 94-102 | setenv console d changes byte 0 by XOR 0x81, from a word-1 delta of 0x03 rotated right | Recomputed over 2000 random stores with the page's algorithm: the XOR delta is 0x81 every time | confirmed (self-consistency only) |
| 24 | 103 | An erased store has checksum 0x5a | Recomputed for an all-0xFF store: 0x5a | confirmed |
| 25 | 116 | The printenv capture values, and that ConsoleIn, ConsoleOut, NoAutoLoad and cpufreq are runtime only | Capture not in this checkout and not cited by file | UNSURE |
| 26 | 105-112 | Unknowns list | Scope statements, not claims. Note: 0xbfbe04e8 is byte 250 of the DS1386 store (0x3e8 past the `bbram` base at a 4-byte stride), the eaddr position. The page could say so | not a verdict |

**Hygiene.** The page names no internal hosts, scratch paths, tool names, or emulator names. Checked by grep.

**Findings.**
- Claim 5 is wrong as stated. The register byte is at 0x1fbd985b. A word read at 0x1fbd9858 returns the register in its low byte, but the Linux header says these registers must not be read as words. Fix the address and say which byte or word is meant.
- Claim 16 is inconsistent. The count is 27 in the text and 29 rows in the table.
- Claim 21 is unsupported. Either cite a 93CS56 datasheet or grade the claim as inferred.
- Every PROM-derived claim (7, 12 to 20, 22, 25) is UNSURE until someone with the IP22 PROM image checks it against the disassembly. This review did not do that.

**Cleared scope.** Claims 1, 2, 4 (for Linux), 6, 8, 23 and 24. The arithmetic in claims 2, 5 and 26 was checked by hand. Not cleared: claim 5 as written, claim 16, claim 21, and every PROM-derived claim.

**Not verified.** The IP22 PROM image and any disassembly of it. The IRIX sources the page cites, which were not read. The Indy image. A 93CS56 datasheet, none of which is held. The printenv capture. `resetenv`. No restricted source was opened, and no restricted search result was opened or shown.
