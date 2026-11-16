# Indigo2 (IP22) PROM environment store

The PROM keeps its environment (`setenv`, `printenv`, the variables that boot reads) in a 93CS56 serial EEPROM on the HPC3. This page covers the layout, the checksum, the defaults and the write order, for the IP22 image `SGI Version 5.1 Rev B IP22 Sep 16, 1993 (BE)`, part 070-8127-002, sha256 `be6b22c3b90adf6eebc18da11ce49e59292eeab35b694c6e8bd75ef485a40241`. Byte offsets are from the start of the store.

Grades: **established** (read in the image or a published source, the claim follows), **observed** (a boot capture), **software expectation**, **inferred**, **unknown**. The part is the 93CS56, not the DS1286 or DS1386 RAM. The checksum and init routines take the serial path when bit 0 of the system ID register (physical `0x1fbd9858`) is set. This image reads that bit as its machine test and so runs the serial path on IP22. Established: the PROM read in the routine, and the public Linux header that names the bit `SGIOC_SYSID_FULLHOUSE`. The same image also holds the DS1386 path (base `0x1fbe0100`, one byte per 32-bit word), which the Indy PROM takes. The Indy image `070-9101-011` has the same record table: the same offsets, lengths and defaults. Its write path is not decoded here. IP28 is not covered.

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

Source: IRIX 6.5.7 `stand/arcs/lib/libsk/ml/IP12nvram.c` (`nvchecksum`), with the PROM's own routine checked by disassembly.

1. Start with `c = 0xa5` (8 bits).
2. For each word `w` from 0 to 127, with bytes `2w` (high) and `2w+1` (low):
   - `w = 0`: `c ^= byte1` (the revision byte only; byte 0 is the checksum and is left out).
   - otherwise: `c ^= byte(2w) ^ byte(2w+1)`.
   - rotate `c` left by one bit.
3. Byte 0 must equal `c`, and byte 1 must equal `0x08`.

The checksum covers all 256 bytes except byte 0, including the protected bytes 250 to 255. Established: the PROM loop in `FUN_c00000001fc2b5d0` was read in the disassembly; the decompiler's output for word 0 was misleading and was not used.

The PROM's validity check (`FUN_c00000001fc2c0dc`) compares byte 0 with `c` and requires byte 1 to be `0x08`. A mismatch in either prints `NVRAM checksum is incorrect: reinitializing.` and writes the defaults. Established. The IRIX source tries the checksum twice; the PROM shows one comparison. Minor, unresolved.

## Power-on reads and defaults

Both branches of the PROM's `init_env` walk the same 27-record table, so every variable is loaded on each boot. Established. The defaults below come from the table strings. An empty default is not written when the store is reinitialised.

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
- The 93CS56 erases on WRITE. There is no append, no wear levelling and no separate erase cycle. Established.
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
