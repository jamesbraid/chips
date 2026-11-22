# CPU PROM payloads inside the Challenge and Onyx IO4 flash images

Real console logs of Challenge and Onyx machines (IP19 R4400, IP21 R8000, IP25 R10000) show the IO4 PROM downloading the CPU's boot PROM and
printing "Loading and executing R4400 boot prom image". This page answers whether those CPU PROM payloads sit inside the IO4 flash images we
hold, and how to take them out. Labels follow [AGENTS.md](../../AGENTS.md): established is read in the bytes and checked, inferred is a reasoned
reading, unknown is not settled.

## Answer

- **Yes. Every image from the IRIX 6.0 era on is a container whose segments are the CPU PROMs.** Established. The 13 images are 6 flat
  single-CPU images (IP19 only, 1993 to 1994) and 7 segmented containers (1994 to 1998). A segmented container holds a small segment
  loader, a compressed IP19 (R4400) PROM, a compressed IP21 (R8000) PROM and, from the February 1996 build on, a compressed IP25 (R10000) PROM. The four
  1994 to 1995 builds also hold a compressed graphics-board PROM.
- **The compression is the ordinary Unix `compress` LZW stream** (magic `1f 9d`, 16-bit codes, block mode) behind a 16-byte header. A stock
  decompressor reproduces every payload; each result matches the header's stored length and byte sum. Established.
- **Every payload is big-endian MIPS** and decodes as code at the stated load address. Established. The IP21 and IP25 payloads and the later IP19
  payloads are complete ELF executables (the ELF header is the first bytes of the loaded image); the earlier IP19 payloads are flat code with no header.
- **The payloads are the "IO4 PROM Monitor" itself**, built once per CPU type, each carrying a banner of the form `SGI Version 4.21 Rev A IP21`.
  The container version (1.0, 2.1) and the CPU PROM version (3.11 to 3.17, 4.19, 4.21) are different numbers. Established.
- **No second reset vector exists in any payload.** The payloads are linked to run from RAM after the loader copies them; none is a ROM image
  that expects to start at the MIPS reset address. Inferred from the load addresses (physical `0x01800000`) and the entry code, which starts
  by reading a handoff block at a fixed address rather than initialising the CPU from scratch.
- **The log lines "Downloading PROM code" and "Jumping into IO4 PROM" are in none of the 13 images.** They come from firmware we do not hold,
  presumably the CPU board's own boot PROM. Unknown.

## Images

All 13 are published in the PROM catalogue and were checked against the catalogue's sha256. The 1996 image `7019deae...` is also byte-identical to the
copy on the retail 6.5 base media (checked by hash). The retail media carry no other IO4 flash file; the standalone programs under `stand/` are
operating-system tools, not PROM payloads, and were not opened.

| Image sha256 | Container | Size | Container build | CPU PROMs inside |
|---|---|---|---|---|
| `248cfc68422fbd9b41d41e10c1ce6e3f0b4dae941f2ba0d26fac13c484654490` | flat | 369752 | 1.09, Aug 28 1993 | IP19 1.09 |
| `53f19c35205b7b1b81df2bc4e12b81da2c77f4232800ddbf18b170b328ca502b` | flat | 381048 | 1.11, Dec 19 1993 | IP19 1.11 |
| `e07b482e3324b6f4b2f8effbe14f88806629a42f93a4f55aa99de19b6b0d13a2` | flat | 386152 | 1.15, Feb 11 1994 | IP19 1.15 |
| `4b068858800d102cb5ab39dd676733fd1222ef513fb6c6796ef1eb7d628a46ea` | flat | 386488 | 1.17, Feb 23 1994 | IP19 1.17 |
| `037b11747d9dca557c9e2cd1c4df2f13e3fac62d54e65713aa9eb58e57aa4247` | flat | 386488 | 1.17, Mar 28 1994 | IP19 1.17 |
| `1d5986809203bab17b97ee8968789112b3dd5ff721d612b4a2cd554e744b34db` | flat | 386488 | 1.18, Jun 21 1994 | IP19 1.18 |
| `10d24938b7fcd7f62c4b1fa413781719fc6b4694aacc30653235024bb0d8ef27` | segmented | 696768 | 1.0, Jul 30 1994 | IP19 and IP21 3.11, graphics |
| `cf61738815e8ca2a6ab4774250b0b6fd586fc276f93a734e5927ed5f6019bcd5` | segmented | 697424 | 1.0, Sep 27 1994 | IP19 and IP21 3.13, graphics |
| `a639d23e2e1744edb054646c890a63b92965b1204ffb60bc1e2b68344ed895db` | segmented | 697410 | 1.0, Oct 29 1994 | IP19 and IP21 3.14, graphics |
| `31c657b40aa15e3f684d38a3b56307e51907cf7f265a666a6bcf4d01ae0d1aca` | segmented | 702958 | 1.0, Apr 12 1995 | IP19 and IP21 3.17, graphics |
| `935cda249801d3668b6910a526b94d4c50987a51298d5f31c5416365b62e02cf` | segmented | 1029914 | 2.1, Feb 21 1996 | IP19, IP21, IP25 4.19 |
| `7019deaeacfe5476ffb5e80c50181bb4590c39793de2fc722994ccca83d5a4f1` | segmented | 1035936 | 2.1, Sep 3 1996 | IP19, IP21, IP25 4.21 |
| `bc9e654a8c05351d44e0ddb38aa35d42a4de5748c5627137213c5c49ad09254f` | segmented | 1012308 | 2.1, Nov 25 1998 | IP19, IP21, IP25 4.21 |

The CPU PROM banners carry the build date of the container they ship in (for example `SGI Version 4.21 Rev A IP19, Sep  3, 1996` in the 1996
container and `... Nov 25, 1998` in the 1998 one), so the two 4.21 builds are different binaries.

## Flat container (1993 to 1994 images)

Established. A 24-byte big-endian header followed by one image: the magic `JFK4`, a checksum, the load address `0x81800000`, the payload length, the
entry address (equal to the load address) and a build number (109, 111, 115, 117, 118, matching the version in the banner). The checksum is the
plain 32-bit sum of the payload read as big-endian words; it holds for all six. The payload is flat IP19 code (the IO4 monitor built for the
R4400) with no segment table, no compression and no other CPU type.

## Segmented container (1994 to 1998 images)

Established unless marked.

- **Header, 24 bytes:** magic `JKSW`, a checksum, then load address `0x81b00000`, length, entry and build number of the first segment, which is
  the segment loader. What range the checksum covers is unknown; it matches none of the byte, word or halfword sums tried over the loader bytes.
- **Segment table at offset 0x18:** the tag `SEG2`, a segment count (4 in every image, including the three-CPU ones: loader plus three
  payloads), then 48-byte records. Each record holds an id, a file offset, a 64-bit entry address, a 64-bit load address, the stored length, a checksum,
  and a few words whose use is unknown (one looks like a size or address in the `0x10000000` range).
- **Ids:** `0xff01` is the loader; `0x105` is the IP19 R4400 PROM, `0x205` the IP21 R8000 PROM, `0x405` the IP25 R10000 PROM and `0x305` the
  graphics PROM. The CPU assignments are read from each payload's banner. The graphics assignment is inferred from its contents (RealityEngine2
  strings and microcode loaders). The meaning of the low byte `05` is unknown.
- **Offsets are biased.** In all seven segmented images the table's offset for every payload is `0xce0` bytes larger than where the data is, and the
  table's end falls `0xce0` bytes past the end of the file. The loader's stored length is likewise `0xce0` larger than its bytes. Subtracting
  `0xce0` lands each payload on its `_LZW` header and the last one exactly on the end of file. The constant is identical in every build, so it is not a
  per-image zero fill. Why the table counts it is unknown.
- **Record checksum:** for a payload record, the sum of the big-endian 16-bit halfwords of the whole stored segment, header included. It matches in
  every payload checked. For the loader it does not match any sum tried (unknown).
- **Payload record, 16-byte header then the stream:** `_LZW`, the uncompressed length, the 32-bit byte sum of the uncompressed data, and one word
  that is 0 or 1 (meaning unknown). The stream follows, starting `1f 9d 90`.
- **Loader (the first segment, 10 to 15 KiB):** carries the strings of the "Everest PROM Segment Loader" menu (list, power-on diagnostic mode, reset,
  select slot, load and execute a segment, copy in a segment, jump), the "Loading and executing %s boot prom image..." message, and error text that
  names the LZW magic, decompressed length and checksum checks. Its CPU-name table lists R4400 IP19, R8000 IP21 and R10000 IP25 (2.1 builds)
  or R4400 IP19, an R4400 IP23 entry, R8000 IP21, master and graphics (1.0 builds). The table is read from strings only; the selection code was not
  read.
- **Decompressed payloads:** the stream ends with the exact stored length, except that the 1998 IP19 payload decompresses to one extra trailing zero
  byte, which does not change the byte sum; the header length is the right size.

## Payloads

Each is big-endian. "Form" is flat code or a complete ELF executable (ELF headers read with a MIPS toolchain; the section table points past the end
of the data, so the file carries no section headers, but the loadable segment covers the whole file with a larger memory size for zero-filled data).
Entry code was disassembled with the MIPS toolchain at the stated base and reads as plausible code. Load addresses are physical `0x01800000`
reached through a 32-bit cached address (IP19) or a 64-bit address window (IP21, IP25).

| Payload | Banner | Form | Load, entry | Length | sha256 of decompressed bytes |
|---|---|---|---|---|---|
| 1.0 Jul 1994, IP19 | 3.11, Aug 3 1994 | flat | `0x81800000`, same | 451984 | `3df8837b4097f934244900ae0f18215fd47b14ec8c17a80d7adedb65531e39a2` |
| 1.0 Jul 1994, IP21 | 3.11, Aug 3 1994 | ELF64 | `0xa800000001800000`, `+0x5000` | 499712 | `53410dad9068abee035cb35a22ce72730b7d26a04ae3c3b34c40bf10a7941d0e` |
| 1.0 Sep 1994, IP19 | 3.13, Sep 29 1994 | flat | `0x81800000`, same | 453296 | `cd4d6ad92e7259501f5b1fab16c61c8370484133421d021685373558c190edce` |
| 1.0 Sep 1994, IP21 | 3.13, Sep 29 1994 | ELF64 | as above | 499712 | `c84efcbd401ba56f348d13b280156fef5d8de87398b1b1ab471d2e8e5df746a8` |
| 1.0 Oct 1994, IP19 | 3.14, Oct 29 1994 | flat | as above | 453312 | `373d5a2104d994a8b4ea6832ea22df6a6556714c8e4dc450ebfd5421bbaa14b6` |
| 1.0 Oct 1994, IP21 | 3.14, Oct 29 1994 | ELF64 | as above | 499712 | `817bc14835f6d8c8a1b400fce1935186f3e7604ef1533275cb6d797ff5f80a0f` |
| 1.0 Apr 1995, IP19 | 3.17, Apr 12 1995 | flat | as above | 454144 | `ecc1c75eed440b0cc68d539f30f0a2d0398ac3d39fc67b26de8ac0709754f001` |
| 1.0 Apr 1995, IP21 | 3.17, Apr 12 1995 | ELF64 | as above | 499712 | `43e4181126ed46939dfc486cdea3f191e71372e9ee86579c8adda7731ca3ef61` |
| 1.0, graphics (same bytes in all four) | none; RealityEngine2 PROM strings | not ELF | `0xa800000001700000`, same | 211936 | `f94b68cfec6731444ce900794e1a732931c062d05c789f3b0a3c09170abea164` |
| 2.1 Feb 1996, IP19 | 4.19, Mar 13 1996 | ELF32 | `0x81800000`, `0x81800180` | 496912 | `a83d4c4c1b62cdf8b67c2a2801a4dc952575aedfd112a15718b37ce968b33dfd` |
| 2.1 Feb 1996, IP21 | 4.19, Mar 13 1996 | ELF64 | `0xa800000001800000`, `+0x1000` | 578944 | `cc9ebf7b725b1195d01999a58d9613d7922cbf5b8b823cdf197f4fb3ce35315c` |
| 2.1 Feb 1996, IP25 | 4.19, Mar 13 1996 | ELF64 | `0xa800000001800000`, `+0x110` | 586648 | `143a0ccaa2a95dc6396830f34dbf1bc00a05fc4393ee2ac5ceec0d8873d93b6f` |
| 2.1 Sep 1996, IP19 | 4.21, Sep 3 1996 | ELF32 | as above | 501168 | `50b71b3dc7bdc4d09e3ed26d86ef040fec6b2d9dfbc1885313ffb8c3b1162535` |
| 2.1 Sep 1996, IP21 | 4.21, Sep 3 1996 | ELF64 | as above | 585944 | `9d1f00d7ffba23c8f63be603a169e28c9df54e27d8e00257c5f29ac49bf0e2e6` |
| 2.1 Sep 1996, IP25 | 4.21, Sep 3 1996 | ELF64 | as above | 593240 | `4ff8984a3bd50804354bae2a7c06e343e36cfbbafa8dacf83c5f9729ed8f5a39` |
| 2.1 Nov 1998, IP19 | 4.21, Nov 25 1998 | ELF32 | as above | 500928 | `bbbc0be25b7e698960ee33adf7284187cf81f797d4c093a26c28c4b3535da679` |
| 2.1 Nov 1998, IP21 | 4.21, Nov 25 1998 | ELF64 | as above | 584680 | `bc9e9412aa1aca49ff6da21dd00b27a6ba11de8fa9baf779c30a9bff1c200daf` |
| 2.1 Nov 1998, IP25 | 4.21, Nov 25 1998 | ELF64 | as above | 552800 | `d41322da06fa9804f780862b3cf3a95c4ac5fe6aa51924498eba6f357d1af76a` |

The 1.0 IP21 PROMs have entry `+0x5000` and a load segment of 499712 bytes (the same length in all four, probably padded); the 2.1 ones enter at
`+0x1000`. The flat IP19 payloads of the six 1993 to 1994 images are the six `JFK4` bodies, not repeated here; their sha256 values are
`f1ca1b8d...` (1.09), `5abe1fea...` (1.11), `bf849c7c...` (1.15), `004cbbc6...` (1.17, Feb), `0ebc962f...` (1.17, Mar) and `ba6478c1...` (1.18).

Entry code of the ELF payloads for IP21 and IP25 begins by reading a word at a fixed uncached address and comparing it with the ASCII tag `XFER`,
then reading a count from the next word. That is a handoff block the loader or earlier firmware writes before jumping. Established as code; its
producer is inferred to be the segment loader and was not read.

## Unknowns

- What the checksum in the 24-byte segmented header covers.
- Why segment offsets (and the loader's length) are biased by `0xce0`.
- The meaning of the word after the byte sum in each `_LZW` header (0 or 1), of the low byte of each segment id, and of the record's
  `0x10000000`-range word.
- Whether the "R4400 IP23" name in the 1.0 loaders ever selects a payload; no held image has one.
- Where "Downloading PROM code" and "Jumping into IO4 PROM" are printed; neither is in any of these images.
- How the IP25 start-up differs from IP21 beyond entry offset: the two images were not compared function by function.

## How to reproduce

Read the 24-byte header, then the table at offset 0x18; for each payload record, take the stored length starting at (offset minus `0xce0`),
drop the 16-byte header, run a standard `compress` decompressor over the rest, and check the length and byte sum against the header. For a ROM
that is not a flat image, disassemble with a big-endian MIPS target at the load address above.
