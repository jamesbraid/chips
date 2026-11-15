# PAL builds across Itanium 2 vendors: what is common Intel code and what is SGI's

Scope: the PAL_A and PAL_B images in the firmware of seven Intel, Dell and IBM Itanium 2 server flash images, set against the
SGI SAL 5.04 `shub1snprom.bin` read in [the snprom pages](../snprom/README.md). The aim is to say which readings in
[pal-authentication.md](../snprom/pal-authentication.md), [pal-instructions.md](../snprom/pal-instructions.md),
[pal-msrs.md](../snprom/pal-msrs.md) and [boot-sequence.md](../snprom/boot-sequence.md) rest on code that other vendors ship
unchanged. Labels as in [AGENTS.md](../../../AGENTS.md): **established** (computed or read in full here), **inferred**
(reasoned, reasoning given), **unknown**. "Shipped" is never "boots": nothing here ran on a processor. No firmware bytes, key
bytes, signature values or listings are reproduced; versions, addresses, sizes and short hashes are.

## Result in brief

- **The signature scheme is common Intel code for the Madison family (established).** Every vendor image that carries a generic
  PAL_A carries the same DSA public key, and every Madison PAL image (family byte `0x1f`) in every vendor image verifies with it:
  27 image copies of eight distinct builds (PAL_B 2.14, 2.15, 2.20, 2.24, 5.73; PAL_A 1.27, 5.37, 7.31) in Dell, Intel and IBM
  firmware.
- **Unsigned-looking images are Montecito, not Madison (established for the family, inferred for what they carry).** PAL_A 7.46,
  PAL_A 5.01, PAL_B 7.46 and PAL_B 8.30, all in Intel firmware, do not verify. Their header carries family byte `0x20` and Intel's
  release notes call 7.46 the Montecito PAL. They end in 64 high-entropy bytes of a different shape from the Madison tail. No
  Madison PAL anywhere is unsigned, so nothing here shows that a Madison processor accepts an unsigned image, and nothing shows
  that it refuses one.
- **The reserved M word and the `br.ia` are common Intel idioms (established).** The M word `0x108000000` occurs in every build of
  both families (1,932 sites in the 17 distinct images), with `srlz` the nearest instruction before all but two, and has no
  operand bits. The `br.ia` call shape and its msr[1225]
  gate are the same in every Madison PAL_B build. No vendor build treats the slot as anything that produces a value.
- **No evidence against treating the reserved M slot as a no-op was found** (last section). One new fact for the B word: a
  Montecito PAL_B has a B word with no `srlz` within twelve instructions before it.
- **HP firmware is not decoded** (rx2620, rx4640, rx2660): the flash payload inside the update EFI application is compressed or
  scrambled and was not recovered.

## Inputs

All local, read-only, not redistributed. Hashes are of the file read.

| Vendor and platform | Package | File read | sha256 |
|---|---|---|---|
| Dell PowerEdge 7250, BIOS A08 (6M cache) | `PE7250_BIOS_A08.zip` | `S870BN4B.BIN` | `7693a654935d8426...` |
| Dell PowerEdge 7250, BIOS B02 (9M cache) | `PE7250_BIOS_B02.zip` | `S870BN4C.BIN` | `f2d7547a6a4339df...` |
| Intel SR870BN4 SUP3 | `SR870BN4_1001_SUP3.ZIP` | `S870BN4C.BIN` | `fb422439a42e3d06...` |
| Intel SR870BN4 Production Release 1.5 (Montecito BIOS) | `SR870BN4_MTC_1002.PR1.5SUP.zip` | `S870BN4D.BIN` | `c6445c159af92b82...` |
| Intel SR870BH2 BIOS 221 T01 (6M) | `T2_6M_221T01SUP.zip` | `S870BH2B.BIN` | `74be6121b1c1dabf...` |
| Intel SR870BH2 BIOS PR5.0 build 254 (9M) | `T2_9M_254PR5_0SUP.zip` | `S870BH2C.BIN` | `b15503def517f3b7...` |
| Intel SR870BH2 BIOS PR2.0 build 253 | `T2MTC_253PR2_0SUP.zip` | `S870BH2D.BIN` | `85b07abe50f266f2...` |
| IBM xSeries 455 SAL/EFI 1.05 | `OYJT29A.PKT` (IBM download) | the packet file | `6ac8a6291a09d3ef...` |
| HP Integrity rx2620 system firmware 04.29 | `PF_CCOUGSYS0429EFI.tar.gz` | `update_SFW.efi` | `a233adcddc34ff93...` |
| HP Integrity rx4640 system firmware 04.29 | `PF_CDIABSYS0429EFI.tar.gz` | `fwupdate.efi` | `ab44aff505a362f9...` |
| HP Integrity rx2660 system firmware 0.94 | `PF_CMERLSYS0301EFI.tar.gz` | `fweupdate_0p94.efi` | `f23e6a470f113ec6...` |
| SGI SHub 1 PROM (reference) | `snprom-10.54-70399` | `shub1snprom.bin` | starts `51ccf9ad` |

External documents read: Intel SR870BN4 PR1.5 release notes (`SR870BN4_MTC_PR15_RelNotes.doc`: PAL 7.46, Montecito), Intel
SR870BH2 BIOS 221 T01 and PR5.0 release notes (PAL 5.73 and 2.24, with the PAL change lists back to 2.04), IBM's `readme.txt` for
x455 SAL/EFI 1.05 (PAL 5.73 for 6M models, 2.15 for 9M models), the `SOURCE.txt` provenance notes beside the Dell, Intel and HP
packages, and the sources already cited in the snprom pages. The HP install-manual text was searched and gave no PAL facts. `.REC` recovery files beside the Dell and Intel `.BIN` files list the same PAL FIT entries as their `.BIN`
(observed on the Dell B02 and Intel BH2D pairs); they were not analysed further. Compaq `cpqia*.bin` and `SP73041.exe`
(flagged as possibly IA-64) were opened only to look for a FIT: none is visible, so they are compressed or not flash images;
**unknown**.

## Container formats

**Dell and Intel `.BIN` (established).** A volume header (`VolumHdr`, 0x66 bytes) holds the BIOS identification string (for
Dell B02, `S870BN4A.86L.0030.B02` plus a timestamp) and the total file length. A component header (`CompoHdr`, name
`PrimaryBiosArea`, a GUID and a build timestamp) follows. The payload is the flash content with unprogrammed areas left out, so
the file is not a linear window onto the 4 GiB map. The last 0x8000-odd bytes (the generic PAL_A and the top-of-flash vectors)
map straight to the top of the 4 GiB range, but the FIT and the PAL images in the 1 MiB region below sit 0x1a6 bytes later
in the file than a straight map from the end of the file predicts, and the processor-specific PAL_A images in the next region down are
shifted by a different amount. There is no single address-to-offset constant. Images were therefore located by FIT address, then
confirmed by the FIT checksum (C_V set) or, for PAL_B, by the PAL header in the image (version bytes at `+0x10114`, family byte
`0x1f` or `0x20`). Every FIT-listed PAL image was found in every file.

**IBM `.PKT` (established).** A stream of frames. Each frame starts `16 02 00 03`, then a two-byte big-endian length, a body of
that length, two or three trailer bytes and a closing `0xC0`; a second `0xC0` can precede a frame. The frame trailer was not
checked (**unknown**). The body begins with a 9-byte sub-header: a type word, a 4-byte little-endian payload count, two fixed
bytes and a stream number. Stream numbers 1 and 2 are two short frames at the start and 4 a short frame at the end; stream 3 carries 4,026 data frames
(4,025 of 1,400 bytes and a last of 1,248). The data frames reassemble to 5,636,248 bytes. That payload opens with a 0x98-byte header (a magic, the tag `SALEFIFW`, and a three-entry
table of size, offset and an 8-byte value that looks like a hash) and then four flash images back to back, sizes 0x60000,
0x100000, 0x300000 and 0x100000. The table lists the last two together as one 4 MB entry. Each image ends at the top of the
4 GiB map, with the generic PAL_A entry at 4 GiB - 0x30, and its FIT is found at the address in the pointer at 4 GiB - 0x20. The
mapping is linear within each image. Images 0 and 2 are recovery-style FITs with a processor-specific PAL_A but no PAL_B (1.27 and
5.37). Images 1 and 3 carry PAL_B 2.15 with 1.27 and PAL_B 5.73 with 5.37, matching IBM's readme (PAL 2.15 for 9M models, 5.73 for
6M models).

**HP update EFI applications (established for the wrapper, unknown for the payload).** Each is a 10,155,008-byte PE32+ file of
machine type `0x200` (IA-64), EFI application subsystem. The `.data` section is 0x94ae00 bytes. It holds the updater's own
runtime data, a zip of the management-processor firmware (`PK` entries near 0x7ff000), what looks like ARM code with a vector
table (management processor, **inferred**), and roughly 2.8 MB of
high-entropy blocks (0x7e000 to 0x34b000) that differ between rx2620 and rx4640 while the blocks around them are equal. No
`_FIT_` string, no 32-byte window of SGI's PAL_A 5.37 (three offsets tried), and no gzip, zlib, raw deflate, bzip2, xz or LZMA stream decodes. The
updater itself is IA-64 code, so its decompression or descrambling routine is readable in the project's IA-64 Ghidra module; that
is the route to settle it, not done here.

## FIT contents and version matrix (established)

FIT entry fields: type `0x01` PAL_B, `0x0e` processor-specific PAL_A, generic PAL_A from the entry at 4 GiB - 0x30 (type
`0x0f`). The FIT checksum (bytes plus the checksum byte is 0 mod 256) holds for every entry with C_V set. PAL_B entries have
C_V clear in every Dell and Intel image and C_V set in IBM's. Addresses: PAL_B at `0xfff00000`; the specific PAL_A images lie
between `0xffd...` and `0xffff...`, differently per vendor.

| Image | PAL_B | Specific PAL_A (FIT order) | Generic PAL_A |
|---|---|---|---|
| Dell A08 | 5.73 | 5.37, 7.31, 1.27 | build G-I |
| Dell B02 | 2.14 | 1.27, 7.31, 5.37 | build G-B |
| Intel SUP3 (BN4C) | 2.20 | 1.27, **7.46**, 5.37 | G-I |
| Intel PR1.5 (BN4D) | **7.46** | **7.46**, 1.27, 5.37 | G-I |
| Intel BH2B | 5.73 | 5.37, **5.01**, 1.27 | G-I |
| Intel BH2C | 2.24 | 1.27, **7.46**, 5.37 | G-S |
| Intel BH2D | **8.30** | **7.46**, 1.27, 5.37 | G-I |
| IBM x455 (four images) | 2.15 and 5.73 | 1.27 and 5.37 | G-S |
| SGI SAL 5.04 | 7.79, 5.73, 2.25 | 7.31, 5.37, 1.27 | G-S |

Bold entries are Montecito-family images (family byte `0x20`; release notes call 7.46 "Montecito PAL"). Generic PAL_A builds
(hash of the 0x7fc0 bytes below the top vectors): **G-S** `19191cc4`, the SGI build, byte-identical in SGI, Intel BH2C and all
IBM images; **G-I** `6c1de461`, differs from G-S only in the first 16-byte bundle at `0xffff8000`; **G-B** `f925d399`, Dell B02
only, a different build: the first 0x120 bytes differ, 1,994 of 2,044 bundles match the SGI build as sequences, the rest
are replaced or inserted (a shift of 0x70 bytes after `0xffff8c00` moves everything below), and the authentication routine is at
`0xffffdad0` instead of `0xffffda60`. New code in G-B is described below.

Which images are byte-identical to SGI's (sha256 equality, established):

| Image | Identical to SGI's | In vendors |
|---|---|---|
| PAL_A 7.31, 5.37, 1.27 | yes (all three) | every image that lists them, all vendors |
| PAL_B 5.73 | yes | Dell A08, Intel BH2B, IBM image 3 |
| Generic PAL_A | G-S yes; G-I differs in 16 bytes | see above |
| PAL_B 7.79 | SGI only, in none of the vendor images | |
| PAL_B 2.14, 2.15, 2.20, 2.24 | no: five builds of the 2.x line, SGI's is 2.25 | Dell B02; IBM; Intel BN4C; Intel BH2C |
| PAL_B 7.46, 8.30; PAL_A 7.46, 5.01 | Montecito, not in SGI's PROM | Intel only |

## Signatures (established unless marked)

Method as in [pal-authentication.md](../snprom/pal-authentication.md): SHA-1 over bytes `[16, N-64)` (PAL_A) or `[0, N-64)`
(PAL_B), DSA check with the key at generic PAL_A `+0x21d0` (`+0x2240` in G-B), r and the second value in the last 48 bytes. The
verifier reproduces the six SGI results first. The key blob read from each vendor's own generic PAL_A is byte-identical to SGI's
in SGI's generic PAL_A and in the generic PAL_A of all eleven vendor images (three builds). Counts are image occurrences.

| Image | Madison images, verify with the image's own key | Others |
|---|---|---|
| Dell A08 | 4 of 4 (PAL_B 5.73; PAL_A 5.37, 7.31, 1.27) | none |
| Dell B02 | 4 of 4 (PAL_B 2.14; PAL_A 1.27, 7.31, 5.37) | none |
| Intel SUP3 | 3 of 3 (PAL_B 2.20; PAL_A 1.27, 5.37) | PAL_A 7.46 fails |
| Intel PR1.5 | 2 of 2 (PAL_A 1.27, 5.37) | PAL_B 7.46, PAL_A 7.46 fail |
| Intel BH2B | 3 of 3 (PAL_B 5.73; PAL_A 5.37, 1.27) | PAL_A 5.01 fails |
| Intel BH2C | 3 of 3 (PAL_B 2.24; PAL_A 1.27, 5.37) | PAL_A 7.46 fails |
| Intel BH2D | 2 of 2 (PAL_A 1.27, 5.37) | PAL_B 8.30, PAL_A 7.46 fail |
| IBM x455 | 6 of 6 (PAL_B 2.15, 5.73; PAL_A 1.27 twice, 5.37 twice) | none |
| HP | not decoded | |

The Madison signature's first value (r) is the same in every signed image, as on SGI; the second value differs per image.

**Non-verifying images (Montecito).** PAL_A 7.46 and 5.01 have an all-zero 16-byte lead, as the earlier page found for 7.46. All
four images end in 64 bytes with no constant bundle and no four-zero padding inside the last 48 bytes, so they are not in the
Madison tail shape. A search with the Madison key over starts 0 and 16, end trims 0 to 128 bytes in steps of 4, every 4-byte
aligned position for r and the second value in the last 160 bytes, with the second value used directly or inverted, made
44,352 (PAL_A 7.46), 57,288 (PAL_B 7.46), 57,024 (PAL_A 5.01) and 65,076 (PAL_B 8.30) attempts and found no verifying signature.
That the Montecito images carry a signature of another scheme, or none, is **unknown**: 64 random-looking trailing bytes could be
a signature, a MAC or filler.

**What this says about the processor requirement.** An unsigned or non-Madison-signed image does ship, in production Intel
firmware: PAL 7.46 in SR870BN4 PR1.5 "Production Release 1.5 Montecito BIOS" (release notes: "Montecito Processors, B, C0, and C1
stepping"), PAL 7.46 and 8.30 in SR870BH2 PR2.0 build 253, PAL 7.46 in BN4C SUP3 and BH2C PR5.0, and PAL 5.01 in BH2B. They are
Montecito PALs for a different processor. So the Madison DSA tail is **not** a rule for all Itanium 2 PAL images (established);
whether Madison silicon refuses a Madison image without the tail is **unknown**, because no Madison image lacks it. Whether those
Montecito PALs boot is not shown here: they shipped in a production release (vendor text), nothing more.

## `br.ia` sites: same bytes, same setup, same gate

Decoded with the project IA-64 decoder over each image at its FIT address, and the counts and addresses of the reserved slots and
every `br.ia` confirmed in the IA-64 Ghidra module on Dell B02's generic PAL_A, PAL_B 2.14, PAL_B 7.46, PAL_B 8.30 and PAL_A 7.46
(identical counts: 1 M word and 3 `br.ia`; 216, 12, 3; 139, 48, 1; 142, 48, 1; 41, 3, 1).

| Site | Result across vendors | Grade |
|---|---|---|
| Generic PAL_A reset stub (msr[212] = 0, msr[1225] = 4, `srlz.d`, `r5` = 1, `br.ia`) | same bytes in G-S, G-I and G-B | established |
| Generic PAL_A FIT-walk `br.ia` (`r2` = entry, `r3` = size, `r5` = 1) | same bytes in all three builds | established |
| Generic PAL_A "no usable PAL_A" `br.ia` (`r2` = `r3` = `r5` = 0) | same bytes in G-S and G-I; **G-B reads msr[1225] first and skips the `br.ia` unless bits 14 and 2 are both set** (SGI: unconditional) | established |
| Specific PAL_A `br.ia` (`r2` = `r3` = `r5` = 0, gated on msr[1225] bit 14 or bit 2) | the 7.31, 5.37 and 1.27 images are byte-identical to SGI's in every vendor | established |
| PAL_B `br.ia` x3 (Madison builds 2.14, 2.15, 2.20, 2.24, 2.25, 5.73, 7.79) | three sites in each. The msr[1225]-gated site tests bit 14 then bit 2 with the same rule in 2.14, 2.25, 5.73 and 7.79 and sets `b1` to the reset vector (`0x80000000ffffffe0`), `r5` = 0 and `r3` = 0 or 1. The first and third sites (by address) have identical 60-instruction lead-ins in the builds compared pairwise (2.14 and 2.25, 2.25 and 5.73, 5.73 and 7.79); the gated middle site differs in how `r2` and `b0` are set (offsets, and a `cpuid` revision test in 5.73 and 7.79) | established |
| Montecito PAL_A 7.46, 5.01 and PAL_B 7.46, 8.30 | one `br.ia` each, `r2` = `r3` = `r5` = 0, `b0` an ip-relative return, gated on **msr[606] bits 1 and 2** (PAL_A also msr[763] bit 0, msr[621]); the skip path sets bits 1 and 2 of msr[606]. PAL_B 7.46 and 8.30 write msr[522] = a command, `srlz.d`, M slot, then `br.ia` | established for the code; the msr[606]-for-msr[1225] analogy is **inferred** |

So the `br.ia` call, the msr[1225] gate and the "function 0, no image, result ignored" form of the specific PAL_A call are Intel
common code for Madison, shipped unchanged by Dell, Intel and IBM. Dell B02's newer generic PAL_A shows Intel itself reading
msr[1225] and testing bits 14 and 2 in the generic code, which strengthens msr[1225] as the gate named in
[pal-msrs.md](../snprom/pal-msrs.md); its combining rule (both set) differs from the PAL_B and specific-PAL_A rule (either set).
Why is **unknown**. G-B also adds, at one of the two PAL_B hand-off entries, a spin on msr[1640] bit 4 before the existing bit-56
test (established); the other entry only gains the bit-56 test at a new address.

## Reserved slots: same words, same contexts

The 747 SGI sites are classified one by one in [reserved-slot-sites.md](../snprom/reserved-slot-sites.md); this section compares
counts and contexts across builds.

Counts of exact slot matches (M `0x108000000`, B `0x48000000`) from the project decoder, per build:

| Build | M word | B word | M words not directly after `srlz` | Msr command written just before the M word |
|---|---|---|---|---|
| generic PAL_A (all three builds) | 1 | 0 | 0 | none (msr[1553], [1640], [1730] window) |
| PAL_A 7.31 / 5.37 / 1.27 | 18 / 22 / 22 | 1 | 0 | msr[1546] and others, as in SGI |
| PAL_B 2.14 / 2.15 / 2.20 / 2.24 / 2.25 | 216 / 217 / 217 / 217 / 217 | 12 / 12 / 18 / 18 / 18 | 0 | msr[1546] 151 of 217 in 2.25 |
| PAL_B 5.73 / 7.79 | 211 / 211 | 12 / 12 | 0 | msr[1546] 145 of 211 in both |
| PAL_A 5.01 / 7.46 (Montecito) | 39 / 41 | 3 / 3 | 0 | msr[522] 39 of 39 and 41 of 41 |
| PAL_B 7.46 / 8.30 (Montecito) | 139 / 142 | 48 / 48 | M: 1 / 1 (one instruction between); B: 14 / 14 (13 with one instruction between, 1 with none within 12) | msr[522] 138 of 139 and 141 of 142 |

(The earlier pages count 20 B words in PAL_B 2.25 and give 257 and 217 M words for it in different places; the exact-word count
here is 217 and 18.)

- In every Madison build and the generic and PAL_A images, `srlz.d` or `srlz.i` is the nearest non-nop instruction before every
  M word and every B word. In Montecito PAL_B 7.46 and 8.30 that holds for 138 and 141 of the M words and 34 of the 48 B words;
  the rest have one instruction between (an msr read, `mov pr=`), and one B word in each has no `srlz` within twelve instructions
  (a predicated `mov msr[r1]=r2` for msr[258] precedes it). **Established** by decoder over the 2,139 sites in the 17 distinct
  images. So the "companion to `srlz`" shape holds for all Madison code and nearly all Montecito code, and is not a rule.
- The context across Madison PAL_B builds is stable. Taking each M word with its four non-nop instructions before and after
  (addresses masked): 216 of 216 contexts in PAL_B 2.14 also occur in 2.25; 188 of 211 in 5.73 and 179 of 211 in 7.79 do; 185 of
  211 in 7.79 also occur in 5.73. Among the M words, msr[1546] is the last command register written before 145 to 151 of them in
  every build, and msr[1545] is the commonest next msr access (40 in 7.79 and 5.73, 48 in 2.25). A different PAL version doing
  the same command, slot and status read is evidence of a stable interface (**inferred**: a stable Intel
  interface across Madison PAL_B 2.14 to 7.79).
- Montecito uses the same two words in the same shape on a different register file: no msr[212], [1225], [1544] to [1547],
  [1600] to [1627] or [1640] to [1643] appears in any Montecito image; msr[522] is the register written before 138 of 139 M
  words in PAL_B 7.46 (141 of 142 in 8.30) and before every M word in the two Montecito PAL_A images; msr[258], [640] and
  [432] precede most B words. The words are therefore not specific to the Madison msr set
  (established), and the same "command, `srlz`, slot" idiom spans both families (inferred as meaning).
- No M or B word has a register or predicate field, so it cannot name a value. Looking for code that consumes a predicate the
  slot could have set: a heuristic scan (predicate used within 24 slots after the word, not written by a compare or `tbit` in the
  60 slots before it or within the 24 after) flagged 14 or 15 of the M words and 5 of the B words in every Madison PAL_B build,
  with the same counts in all builds, and 2 M and 20 B in Montecito. Reading the 7.79 sites at `0xffdda746` and `0xffdda796`
  showed predicates p06, p07 and p15 set by the caller of the routine, not by the word. The scan cannot prove that every flagged
  site is caller-set (**inferred**).

## The expected-answer routine at PAL_B 7.79 `0xffe26856` (established)

The routine writes msr[1544] = 0 and msr[1546] = a command word, `srlz.d`, the M word, then polls msr[1212] until bit 14 is set,
compares bits 13:0 of msr[1212] with an expected constant and msr[1226] with a second one; on a mismatch it sets bit 59 of msr[1640],
then writes msr[1546] again, `srlz.d`, M word. The constants are chosen by `cpuid[3]` revision byte.

| Build | Command word | msr[1212] expected | msr[1226] expected per revision class |
|---|---|---|---|
| PAL_B 2.14, 2.15, 2.20, 2.24, 2.25 | same word in all | 12668, all three classes | one value, the same in all three classes |
| PAL_B 5.73 (Dell, Intel, IBM) | same | 12668 | the same value, all three classes |
| PAL_B 7.79 (SGI) | same | 12668 (two classes), 2989 (third) | three different values, one equal to the 2.x and 5.73 value |

So the table is not an SGI addition: the 2.x and 5.73 builds that Dell, Intel and IBM ship carry it with the same command and
the same expected constant in every revision class, and 7.79 refines it per revision. That the routine checks a hardware
status answer against compiled-in constants is read from the code (established); what the constants name (a self-test
signature, a revision identifier) is **unknown**. Montecito images carry no counterpart.

## What was not settled

- **HP images.** Route: read the updater's decompression or descrambling code in Ghidra (it is IA-64 PE32+) and carve the flash
  at its FIT address; the FIT and PAL list for the rx2620, rx4640 and rx2660 then compare against this page. The rx2800 i2 bundle
  (Itanium 9300) and the Compaq files were not opened beyond a FIT search.
- Whether the processor's `br.ia` service verifies the same DSA signature stays **unknown**: no vendor build tests its result
  differently, and none of the Madison PALs is unsigned, so there is no discriminating image. A Montecito image in a Madison
  board, or the reverse, would be one; none is shipped here.
- What the Montecito 64-byte tail is.
- The 0x1a6-byte offset steps in the Dell and Intel files (what container records them).
- IBM frame trailers.
- Msr census figures use forward constant tracing, which is approximate; they agree with the earlier page where it states counts
  (generic 52; 7.31 257; PAL_B 7.79 3,738, 5.73 3,789, 2.25 3,674) and are off by one for PAL_A 1.27 (368 against 367).

## Evidence against treating the reserved slots as no-ops

None found. The word has no register or predicate field, and no site in any build was seen to consume a value only the word
could have produced (the heuristic above, read by hand at two sites). The same code runs the word in 2,139 places across eight
vendor-shipped Madison builds, four Montecito builds, three generic builds and SGI's two extra PAL_B builds, with no handler,
recovery table or retry around it that the decode shows. Reachability of individual sites was not traced, and the Madison boot-path
sites that run with `psr.ic` cleared (see [pal-instructions.md](../snprom/pal-instructions.md)) remain the strongest evidence that
the processor does not fault on the word. This shows no vendor PAL needs a result from the word. It does not show what the
processor does with it.

## Method notes

Tools ran from a scratch directory outside the repository: a FIT parser and carver, a DSA verifier (checked first against the six
SGI results), the retools IA-64 decoder over each image and an msr trace. Ghidra, run through the toolchain image on carved
copies kept untracked in `.cache/`, confirmed decode and counts as stated. No carved image or listing is stored in the repository.
