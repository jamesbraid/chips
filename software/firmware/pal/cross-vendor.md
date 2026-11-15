# PAL builds across Itanium 2 vendors: what is common Intel code and what is SGI's

Scope: the PAL_A and PAL_B images in the firmware of seven Intel, Dell and IBM Itanium 2 server flash images and four HP Integrity ones, set against the
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
- **HP Integrity firmware is decoded and is SGI's and Intel's PAL code** (rx2620, rx4640, rx2660, rx3600/rx6600; see [HP Integrity](#hp-integrity)).
  The update EFI application carries the 8 MiB system flash compressed in the EFI compression format and checksummed by a byte sum; the
  decompressed image has a normal FIT. Its generic PAL_A is SGI's build, PAL_B 2.25 and PAL_A 5.37 and 1.27 are byte-identical to SGI's
  and PAL_A 7.46 to Intel's; PAL_B 5.72 is a new Madison build that verifies; the Montecito-shaped PAL_B 9.68, 9.08 and 1.08 and PAL_A 1.08
  do not verify with the Madison key, as Intel's do.

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
| HP Integrity rx3600 and rx6600 system firmware 0.95 | `PF_CRUSASYS0301AEFI.tar.gz` | `fweupdate_0p95.efi` | `fb0eb352bb5ff3a8...` |
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

**HP update EFI applications.** Compressed payload in the EFI compression format behind a `_CMPRM1_` wrapper; see [HP Integrity](#hp-integrity).

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
| HP | see [HP Integrity](#hp-integrity) | |

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
Montecito PALs for a different processor. So the Madison-key DSA tail is **not** on every shipped Itanium 2 PAL image (established), which is weaker than "not required": a Montecito signature under another key or scheme is not excluded;
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
| PAL_B `br.ia` x3 (Madison builds 2.14, 2.15, 2.20, 2.24, 2.25, 5.73, 7.79) | three sites in each. The msr[1225]-gated site tests bit 14 then bit 2 with the same rule in 2.14, 2.25, 5.73 and 7.79 and sets `b1` to the reset vector (`0x80000000ffffffe0`), `r5` = 0 and `r3` = 0 or 1. The first and third sites (by address) have the same 60-instruction lead-ins in the builds compared pairwise (2.14 and 2.25, 2.25 and 5.73, 5.73 and 7.79), except one image-relative `movl` constant in the third site between 2.25, 5.73 and 7.79; the gated middle site differs in how `r2` and `b0` are set (offsets, and a `cpuid` revision test in 5.73 and 7.79) | established |
| Montecito PAL_A 7.46, 5.01 and PAL_B 7.46, 8.30 | one `br.ia` each, `r2` = `r3` = `r5` = 0, `b0` an ip-relative return. PAL_B 7.46 and 8.30: gated on one bit of msr[606] (bit 1 when msr[763] bit 0 is clear, bit 2 when set), and the call is skipped when that bit is set; they write msr[522] = a command, `srlz.d`, M slot, then `br.ia`. PAL_A 5.01: gated on msr[622] bit 26 being clear. PAL_A 7.46: no gate (`cmp.eq p3,p4=r0,r0` forces the predicate). Both PAL_A images have a predicated block after the call that ORs bits 1 and 2 into msr[606]; in 7.46 it cannot run (see Review) | established for the code; the msr[606]-for-msr[1225] analogy is **inferred** |

So the `br.ia` call, the msr[1225] gate and the "function 0, no image, result ignored" form of the specific PAL_A call are Intel
common code for Madison, shipped unchanged by Dell, Intel and IBM. Dell B02's newer generic PAL_A shows Intel itself reading
msr[1225] and testing bits 14 and 2 in the generic code, which strengthens msr[1225] as the gate named in
[pal-msrs.md](../snprom/pal-msrs.md); its combining rule (both set) differs from the PAL_B and specific-PAL_A rule (either set).
Why is **unknown**. G-B also adds, at one of the two PAL_B hand-off entries, a test of msr[1640] bit 4 before the existing bit-56 test (established). It reads the register once and, when the bit is set, branches to its own bundle with no re-read, so it never leaves: a stop, not a poll (see Review). The other entry only gains the bit-56 test at a new address.

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

## HP Integrity

Four HP update packages for Madison-era and Montecito-era Integrity servers: rx2620 and rx4640 (system firmware 04.29) and rx2660 and
rx3600/rx6600 (system firmware 0.94 and 0.95). Each is a 10,155,008-byte IA-64 EFI application; the four share one layout. The
flash image is recovered, its FIT parses, and every FIT entry with C_V set passes the checksum rule above (37, 52, 38 and 60 entries).

**Container (established).** All four updaters keep their payloads in the `.data` section, each behind a 0x38-byte wrapper whose
first eight bytes are the ASCII tag `_CMPRM1_`. After the tag come a version word (2), a 32-bit sum of the payload bytes, the payload
length, and zero fill. The sum is the plain byte sum of the payload and matches in all six wrappers read. The payload starts at the
wrapper plus 0x38 (file offsets `0x60200` and, in the rx2660 and rx3600/rx6600 updaters, `0x4b0200`) and opens with two
little-endian words, the compressed length and the original length, then the stream.
The stream is the EFI compression format of the UEFI specification (LZ77 matches with Huffman-coded literal/length and distance
codes, in blocks that each carry their own code tables), in its original variant with a 4-bit position-code length, not the 5-bit
variant that Tiano uses. That is why plain deflate, bzip2, LZMA and the other generic decoders found nothing. The updater itself holds no
decoder on the path read: its image-unpack routine (`0x415360` at the preferred image base `0x400000`) checks the byte sum, locates the firmware's
Decompress protocol by GUID, asks it for the output and scratch sizes, allocates both from the loader's pool and calls it, then frees
the scratch. A decoder written from the specification (outside the repository) reproduced the first payload of each updater at
exactly its stated original length, 8,388,608 bytes, and the FIT checksums above are the independent confirmation; with the 5-bit
variant the code tables fail to build.

**The first payload is the whole system flash (established).** The 8 MiB image is mapped so that its last byte is at `0xffffffff`. The FIT pointer at 4 GiB - 0x20, the generic PAL_A entry at 4 GiB - 0x30 and every FIT address then land on the data they
describe (FIT checksums, PAL headers, `_FIT_` signature). The rx2620 image holds two FITs (pointers at 4 GiB - 0x20 and
4 GiB - 0x38) with the same entries; the other images were read through the pointer at 4 GiB - 0x20. From the bottom of the image up, the layout is: EFI driver
blocks (tag `DRVBLK01`, 0x20000 to 0x80000 apart, from offset 0), then the EFI core, the FIT and PAL_A images, PAL_B, SAL_B, and SAL_A,
the generic PAL_A and the reset vectors at the top. FIT entry versions: SAL_A `0x0200` in all four, SAL_B `0x041d` in rx2620 and rx4640 and `0x0301` in rx2660 and
rx3600/rx6600; the package names (04.29 and 0301) match them if the low byte of `0x041d` is binary (**inferred**). How the updater writes the image was read only from its message
strings, not from the flashing code: it checks sector alignment and a whole-image checksum, calls the firmware's flash service in
sectors with retries, and can swap between two flash banks (**inferred** from strings; the flashing code is not read). Nothing found
indicates any remapping or reordering between the decompressed image and the flash.

**The second payload is not firmware for the processor (established for what it is, not read further).** The rx2660 and
rx3600/rx6600 updaters carry a second wrapped stream, 8,671,401 and 9,409,647 bytes after decompression. It holds a text manifest
of management-processor and programmable-logic components (names, a type, flash offset, size and a version string) and a ZIP archive. It
has no flash layout; six `_FIT_` strings in each were not examined. In the rx2620 and rx4640 updaters the management-processor ZIP sits uncompressed in `.data`.

### Version matrix

Decoded image checksums (sha256 prefixes of the 8 MiB images, not redistributed): rx2620 `e12d0c170b729ac4`, rx4640 `7d9a781164c80468`,
rx2660 `50056053b5857d22`, rx3600/rx6600 `33661144a3025145`. Packages: rx2620 `PF_CCOUGSYS0429EFI.tar.gz` (`8ecf3e9b8a230b76...`),
rx4640 `PF_CDIABSYS0429EFI.tar.gz` (`0545215cd50bf10501...`), rx2660 `PF_CMERLSYS0301EFI.tar.gz` (`e2643dad971777f0...`), rx3600/rx6600
`PF_CRUSASYS0301AEFI.tar.gz` (`e235a123965f9d47...`).

| Image | PAL_B | Specific PAL_A (FIT order) | Generic PAL_A |
|---|---|---|---|
| HP rx2620 04.29 | 5.72, 2.25, **9.68** | 5.37, 1.27, **7.46** | G-S |
| HP rx4640 04.29 | same three, byte-identical to rx2620's | same three, byte-identical | G-S |
| HP rx2660 0.94 | 2.25, **9.08**, **1.08** | 1.27, **7.46**, **1.08** | G-S |
| HP rx3600/rx6600 0.95 | same three, byte-identical to rx2660's | same three, byte-identical | G-S |

Bold entries have family byte `0x20` (PAL_B) or do not verify (PAL_A), as for Intel's Montecito images. The PAL_B header at `+0x10114`
holds the version as minor then major (`72 05` is 5.72), and the four bytes before it look like a BCD build date (year, century,
day, month; **inferred**): 2005-03-09 for 5.72, 2007-03-14 for 2.25, 2007-11-06 for 9.68. The generic PAL_A is the SGI build G-S: the
0x7fc0 bytes below the top vectors hash to `19191cc4` (sha256 prefix) in all four updaters. Only the 64 bytes at the top (FIT pointers) differ
from SGI's. Which core HP's 9.08 and 1.08 serve is not stated by HP's text (rx2660 0.94 notes mention 12 MB cache parts); family
byte `0x20` is the only evidence tying them to Intel's Montecito images, so the processor family is **inferred**.

Which images match SGI's or Intel's (sha256 equality, established):

| HP image | Compared with | Result |
|---|---|---|
| PAL_B 2.25 (all four) | SGI PAL_B 2.25 | byte-identical. No Dell, Intel or IBM image carries 2.25 |
| PAL_A 5.37 (rx2620, rx4640), 1.27 (all) | SGI | byte-identical |
| PAL_A 7.46 (all) | Intel PAL_A 7.46 (SR870BN4 PR1.5, SR870BH2 PR2.0) | byte-identical to both |
| PAL_B 5.72 | SGI, Dell, Intel, IBM PAL_B 5.73 | different build: 696,256 bytes against 696,640, first byte difference at `0xdc0d`, 70.8% of bytes equal at the same offset, 75.4% of its 64-byte aligned chunks occur in 5.73 |
| PAL_B 9.68, 9.08, 1.08; PAL_A 1.08 | Intel PAL_B 7.46, 8.30 | not identical to any. 64-byte-chunk overlap with Intel's 8.30: 9.08 82.6%, 9.68 70.5%, 1.08 57.0%; with 7.46: 52.3%, 48.1%, 43.4%. The HP PAL_B builds share 57 to 70% of chunks with one another |

(The overlap figures count 64-byte aligned chunks of the HP image that appear anywhere in the other image, so they show lineage, not equal
address layout.) So HP's Madison-era firmware is SGI's: the PAL_B build SGI ships as 2.25 and both
older PAL_A images are unchanged, and the Montecito PAL_A 7.46 is Intel's. The newer PAL_A 1.08 and PAL_B 9.68, 9.08 and 1.08 are in no other vendor image read here.

### Signatures

Method as in the Signatures section above. The key comes from each updater's own generic PAL_A and is byte-identical in all four to
SGI's key (the same key as in every other vendor image). The verifier is the one checked against the six SGI results.

| Image | Madison images (verify) | Others |
|---|---|---|
| HP rx2620, rx4640 | 4 of 4 (PAL_B 5.72, 2.25; PAL_A 5.37, 1.27) | PAL_B 9.68 and PAL_A 7.46 fail |
| HP rx2660, rx3600/rx6600 | 2 of 2 (PAL_B 2.25; PAL_A 1.27) | PAL_B 9.08, 1.08 and PAL_A 7.46, 1.08 fail |

PAL_B 5.72 is a Madison build that verifies, as 5.73 does; PAL_B 2.25 verifies as in SGI's PROM. The failing images follow
Intel's Montecito pattern: PAL_A 1.08 has the all-zero 16-byte lead of PAL_A 7.46, and the last 48 bytes of every failing image
contain no zero byte (the Madison tail has four zero bytes after each 20-byte number). A search like the one for the Intel images, but with the second value used
directly and not inverted, covered coverage starts 0 and 16, end trims 0 to 128 bytes in steps of 4 and every pair of 4-byte aligned
20-byte values below the group order in the last 160 bytes: 55,506 attempts (PAL_A 1.08),
51,744 (PAL_B 9.68), 59,400 (PAL_B 9.08) and 67,584 (PAL_B 1.08) found no verifying signature. PAL_A 7.46 is Intel's image and was searched
there. A different scheme or key for these builds is not excluded (**unknown**, as for Intel's). HP adds no Madison image without
the tail, so the page's open question (whether a Madison part would refuse such an image) gains no discriminating image.

### `br.ia` sites and reserved slots

Counts by the project's reference decoder over each image; the HP PAL_B 2.25 and PAL_A 5.37 reproduce the page's SGI counts (217 M, 18 B, 3
`br.ia`; 22 M, 1 B, 1 `br.ia`), so the method matches. Images byte-identical to SGI's or Intel's or the generic PAL_A are not
counted again.

| Build | M word | B word | `br.ia` | M words with `srlz` as the nearest instruction | B words with no `srlz` in 12 instructions |
|---|---|---|---|---|---|
| PAL_B 5.72 (Madison) | 210 | 12 | 3 | 210 of 210 | 0 |
| PAL_B 9.68 / 9.08 (family `0x20`) | 143 / 143 | 49 / 48 | 1 / 1 | 142 of 143 each (one has an instruction between) | 1 each |
| PAL_B 1.08 (family `0x20`) | 149 | 47 | 1 | 148 of 149 | 1 |
| PAL_A 1.08 | 45 | 3 | 1 | 45 of 45 | 0 |

- PAL_B 5.72 follows the Madison pattern of its siblings: three `br.ia` sites, the reserved words always right after `srlz`, and no
  M or B word without it (established for the counts and the `srlz` rule; the msr[1225] gate at its sites was not re-read).
- PAL_B 9.68, 9.08 and 1.08 have the structure of Intel's PAL_B 7.46 and 8.30 at the one `br.ia`: they read msr[763] bit 0, then
  msr[606] and test bit 1 (or bit 2); on the taken path they write msr[522] with a command, `srlz.d`, set `r2` = `r3` = `r5` = 0 and an
  ip-relative return in `b0`, and `br.ia`. The M words follow msr[522] writes (constant tracing, approximate: 125, 125 and 128 words).
  The counts, `srlz` pattern and one unguarded B word match the Intel Montecito PAL_B (**established** for the code).
- PAL_A 1.08 is shaped like PAL_A 7.46: the msr[763] bit 0 test selects a write to msr[621], a forced predicate
  (`cmp.eq p3,p4=r0,r0`) makes the `br.ia` unconditional, `r2` = `r3` = `r5` = 0. No gate (established for the code).
- Nothing new about the reserved words: no HP build has an M or B word that consumes a value, and none with a handler or retry around
  it. New builds add 5.72 (Madison) and 9.68, 9.08, 1.08 and PAL_A 1.08 (Montecito-shaped) to the 2,139 sites already counted; the "no
  evidence against a no-op" conclusion below is unchanged and rests on the same grounds.

## What was not settled

- **HP images.** The second payload of the rx2660 and rx3600/rx6600 updaters (management processor and programmable-logic components),
  the `_FIT_` strings in it, the flashing code of the updaters and the 2013 rx2800 i2 bundle (Itanium 9300) were not read; the Compaq
  files were not opened beyond a FIT search.
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
For the HP updaters the PE32+ file was loaded into the IA-64 Ghidra module as a flat image at its section addresses (a small header-parse
step, since the exporter does not import IA-64 PE32+ yet), all 469 functions from its exception table were decompiled, and the unpack routine
was read there; the decoder, carver and verifier were throwaway scripts outside the repository, with the extracted updaters and decoded images deleted afterwards.

## Review

Independent review of the commit that added this page, by a reader who did not write it. Everything below was redone from the
vendor packages and the SGI 10.54 `shub1snprom.bin`, with a new carver and a new DSA verifier (throwaway scripts, not
committed), and the `br.ia` and reserved-slot readings were redone in the project IA-64 Ghidra module with each component
loaded at its FIT address. objdump was used only to cross-check the Dell B02 generic PAL_A msr[1640] site and the Montecito
PAL_A 7.46 `br.ia` site. Grades follow the page: facts about the images are established, readings of what code means stay
inferred.

**Confirmed (established).**

- **Containers.** Every input sha256 prefix matches the Inputs table. Dell A08 and B02 and the five Intel `.BIN` files decode as
  a volume of one component with the unprogrammed areas dropped; the PAL FIT is the second `_FIT_` in each file. I re-carved Dell
  A08, Intel BH2C and the IBM packet from scratch. IBM: 4,029 frames of `16 02 00 03`, each followed by 2 or 3 trailer bytes
  (4,020 and 9) and `0xC0`, with a second `0xC0` before 8 frames; 4,026 stream-3 frames carry 5,636,248 bytes; the 0x98-byte
  header has the tag `SALEFIFW` and three entries of size, 8-byte value and offset (0x60000, 0x100000 and 0x400000, the last
  covering two images); the four images are 0x60000, 0x100000, 0x300000 and 0x100000 bytes and each FIT is found through the pointer
  at 4 GiB - 0x20. In the Dell and Intel files the PAL_B, the first PAL_A and, in the BH2 files, all PAL_A images sit 0x1a6 past a
  straight map; the second and third PAL_A images of the Dell and Intel BN4 files sit 0xb01a6 past it, and in the three BH2 files
  every PAL_A image follows the 0x1a6 rule. The FIT checksum holds for every C_V-set entry and for the generic PAL_A entry (type 0x0f at 4 GiB - 0x30,
  size 0x7fc0, address 0xffff8000) in the three files checked.
- **Version matrix.** The 12 FIT listings, versions, order and C_V flags in the table match. PAL_A 7.31, 5.37 and 1.27 are
  byte-identical to SGI's in every image that lists them; PAL_B 5.73 is byte-identical to SGI's in Dell A08, Intel BH2B and IBM
  image 3; PAL_B 2.14, 2.15, 2.20, 2.24 and SGI's 2.25 are five different builds; PAL_B 7.79 is only in SGI's PROM. The three
  generic PAL_A builds split exactly as the page says: the 0x7fc0-byte hashes with prefixes `19191cc4` (SGI, BH2C, IBM x4),
  `6c1de461` (Dell A08, Intel SUP3, PR1.5, BH2B, BH2D) and `f925d399` (Dell B02). G-I and G-S differ in 8 bytes, all inside the first bundle.
- **Signatures.** With the page's scheme, 33 of 33 Madison (family byte `0x1f`) PAL copies verify with the key read from their own
  vendor image: 27 image copies in Dell, Intel and IBM firmware (eight distinct builds) plus SGI's six. The key blob (404 bytes) is identical in all 12 generic PAL_A copies; p and q test prime, q divides p-1, g and y
  have order q. SIG_R is the same in all 33 images; the second value differs per build (10 distinct values). The seven
  Montecito images (PAL_A 7.46 in SUP3, PR1.5, BH2C and BH2D, PAL_A 5.01, PAL_B 7.46 and 8.30) fail. A search broader than the
  page's (both starts, end trims 0 to 128, every 4-byte-aligned r and second value in the last 160 bytes, second value direct
  or inverted: 96,228 attempts on PAL_A 7.46, 143,748 on PAL_B 8.30, 126,852 on PAL_A 5.01, 118,800 on PAL_B 7.46) found no
  verifying signature. PAL_A 7.46 and 5.01 have a zero 16-byte lead; the PAL_B images do not.
- **Reserved slots and `br.ia` in Ghidra.** The Ghidra module does not decode the M word and prints it as `unknown.m
  0x108000000` (B word `unknown.b 0x48000000`); counts by exact match are 216, 217, 217, 217, 217, 211 and 211 M words in PAL_B
  2.14, 2.15, 2.20, 2.24, 2.25, 5.73 and 7.79 with 12, 12, 18, 18, 18, 12 and 12 B words; 139 and 142 M and 48 and 48 B in
  Montecito PAL_B 7.46 and 8.30; 41 and 39 M and 3 and 3 B in PAL_A 7.46 and 5.01; 1 M in each generic build. The `br.ia`
  counts (3, 3, 3, 3, 3, 3, 3 in the Madison PAL_B builds, 1 in each Montecito image, 3 in each generic build) and all the page's
  per-build counts agree. Every Madison M and B word has `srlz` as the nearest non-nop before it. In Montecito PAL_B 7.46 and 8.30
  the exceptions are 1 M word and 14 B words once `hint.m 0` is counted as a nop (11 more B words have a `hint.m 0` between).
- **PAL_B msr[1225] gate, 2.14 through 7.79 (established).** In all seven builds one site reads msr[1225], tests bit 14 with
  `tbit.z p0,p2` then ORs bit 2 into p2 with `tbit.nz.or`, and branches to the `br.ia` path when either is set. 2.14 and 2.15 are
  identical after address masking; 2.20, 2.24 and 2.25 differ from 2.14 in two offsets; 5.73 and 7.79 add the
  `cpuid[3]` bits 15:8 compare against 0x83 and 0x88 and choose `r3` of 0 or 1. All set `b1` to the reset vector, `r5` = 0.
- **msr[1212] known-answer routine (established).** The routine (msr[1544] = 0, msr[1546] = command, `srlz.d`, M word, poll
  msr[1212] bit 14, compare bits 13:0 with `r21`, compare msr[1226] with `r20`, set msr[1640] bit 59 on mismatch) is the same
  65 instructions, after address masking, in PAL_B 2.14, 2.15, 2.20, 2.24, 2.25 and 5.73. The expected msr[1212] value is
  0x317c (12668) in all three revision classes of those builds, and the msr[1226] value is the same in all three. In 7.79 two
  classes use 0x317c (with two different msr[1226] values, one equal to the older builds') and the third class uses 0xbad
  (2989) for both. The command word is the same in all seven builds.
- **Dell B02 generic PAL_A (established).** At the "no usable PAL_A" site the code reads msr[1225], takes `tbit.z p2,p0` of bit
  14 and `tbit.z.or` of bit 2, and branches past the `br.ia` when p2 is set, so the call runs only when both bits are set. G-S and G-I
  call unconditionally. The two other generic `br.ia` sites are the same bytes in all three builds.
- **Montecito msr[522] (established).** PAL_B 7.46 and 8.30 write msr[522] with the same command constant, then `srlz.d`, the
  M word, then the `br.ia` after the ip-relative `b0` setup. 137 of 139 (7.46) and 140 of 142 (8.30) M words follow an msr[522]
  write with only nops, `srlz` or `hint` between; one more in each follows an msr[522] write with a region-register read and write
  in between, giving the page's 138 and 141; the other is the `mov pr=` case. In both PAL_A images every M word follows an msr[522] write.

**Fixed in place (mechanical, established by the decode above).**

1. **Dell B02 msr[1640] bit 4 is not a spin.** The page called it a spin. The test is `mov r31=msr[r31]`, then
   `tbit.z p14,p15=r31,4`, then `br.cond (p15)` to its own bundle, with no second read of the register. If bit 4 is set once, the
   processor never leaves; if clear, it goes on to the bit-56 test. Objdump shows the same. The page now says "stop, not a poll".
   Why the code stops is **unknown**; reading it as a deliberate halt on a fault bit is **inferred**.
2. **Montecito `br.ia` gating.** The page's "gated on msr[606] bits 1 and 2, skip path sets them" holds for none of the four
   images as written. PAL_B 7.46 and 8.30 test one bit of msr[606], bit 1 or 2 selected by msr[763] bit 0, and skip when it is
   set; the skip path does not write msr[606]. PAL_A 5.01 tests msr[622] bit 26. PAL_A 7.46 has no test: `cmp.eq p3,p4=r0,r0`
   forces p3 and the call is taken; the `(p4)` block after it (msr[606] |= 6) is entered only when p4 is set, and the return
   address is computed as the bundle after that block, so it is dead there. Objdump agrees. Table row rewritten. The msr[763] bit 0 reading in
   PAL_A selects whether msr[621] is written, not a `br.ia` gate.
3. **"Identical 60-instruction lead-ins".** True for the first `br.ia` site in all pairs and for the third between 2.14 and 2.25; between
   2.25, 5.73 and 7.79 the third differs by one image-relative `movl` constant. Reworded.
4. **"Not a rule for all Itanium 2 PAL images" (grading).** What is established is that the Madison-key DSA tail is absent from the
   Montecito images. A Montecito signature under another key or scheme is not excluded, and the page's own Intel erratum citation
   in [pal-authentication.md](../snprom/pal-authentication.md) (a processor authenticating PAL 7.46 at boot on the 9000 Series)
   makes some check on those images likely. So "unsigned" is the wrong word for them: they are **not signed with the Madison
   key**; whether they carry a signature is **unknown**; that the processor authenticates PAL 7.46 is established for that
   erratum's text only. The sentence now says so.

**Changed facts.** The msr[1640] bit 4 behaviour (stop, not a poll) and the Montecito `br.ia` gating (per image, with PAL_A 7.46
ungated) are corrected above. Nothing else in the version matrix, container text, signatures or counts changed.

**Not checked.** The HP Integrity section (added after this review; not independently reviewed). The PAL_A 7.31, 5.37 and 1.27 `br.ia` gate (bits 14 or 2 of msr[1225])
was not re-read in Ghidra here; the images are byte-identical to SGI's, whose reading the snprom pages carry. The Dell and Intel `.REC` files. IBM frame
trailer contents and the 8-byte values in the IBM header table. The per-site msr census for the 17 images beyond the counts above
(msr[1546] before 145 to 151 M words, and the context-overlap figures), the predicate-consumer heuristic, and the Madison
PAL_B first-site lead-ins beyond 2.14, 2.25, 5.73 and 7.79. Pre-existing text in `pal-authentication.md` and `pal-msrs.md`
that speaks of Intel's "unsigned 7.46" was not edited.
