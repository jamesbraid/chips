# PAL image authentication on the SN2 PROM

What an Itanium 2 (Madison) processor and its PAL code check before they accept a PAL image, from the SAL 5.04
`shub1snprom.bin` (the same generic PAL_A and three processor-specific PAL_A images as in the other SHub 1 builds, PAL_B
7.79, 5.73 and 2.25). The register setup at the `br.ia` that asks the processor to authenticate is in
[boot-sequence.md](boot-sequence.md) and [pal-msrs.md](pal-msrs.md); this page answers what the check is.

**Short answer.** Every processor-specific PAL_A and PAL_B image in the PROM ends in a 48-byte DSA signature, and the
generic PAL_A carries the matching 1024-bit public key and a software verifier for it. Those signatures verify
(established, below). What the processor's own `br.ia` service checks is not visible in any code or document held, so
that service is **unknown**; the software verifier is the best available model of it (**inferred**).

**Grades.** *established*: reproduced here by computation on the shipped images, or read in full from the image or a
published page. *inferred*: reasoned, with the reasoning stated. *unknown*: not settled, with the route that would
settle it. Readings marked **Ghidra** come from the retools IA-64 Ghidra module (its decompiler output is navigation
only); readings marked **objdump** come from the binutils 2.44 disassembly of the same bytes, used where Ghidra made no
function. No PROM bytes, key bytes or signature values are reproduced here.

## Sources

Published documents and patents. Every statement below that rests on one names it.

| Source | What it says | Used for |
|---|---|---|
| Itanium Architecture SDM, volume 2, rev 2.3, 245318, section 11.2.1 (p. 2:289) | PALE_RESET "may perform a minimal processor self test. PAL may optionally perform authentication of the PAL firmware to ensure data integrity" | authentication is optional and implementation specific |
| same, section 11.2.2 (p. 2:290) | SALE_ENTRY receives in GR34 a PAL call address whose recovery-check subset includes "an implementation-specific PAL procedure for PAL authentication"; GR36 holds that call address on the second SALE_ENTRY call | the PAL authentication entry is a callable procedure |
| same, Table 11-4 (pp. 2:292 to 2:293) | status codes 4 (PAL_A authentication failure), 5 (PAL_B authentication failure), 11 to 13 (processor-specific PAL_A failed "checksum or authentication"), 16 (PAL_B failed "authentication and checksum"); "authentication of PAL_A and PAL_B should be completed before call to SALE_ENTRY" | checksum and authentication are separate checks |
| same, PAL calling-convention note b (p. 2:360) | the authentication procedure call needs PSR.dfh = 0 | call convention |
| Itanium SAL specification rev 3.4, 245359-009, section 2.5 (pdf pp. 21 to 22) | FIT entry layout: address, 3-byte size in 16-byte paragraphs, a reserved byte, 2-byte version, 7-bit type, C_V bit, checksum byte; "the modulo sum of all the bytes in the component and the value in this field (Chksum) must add up to zero" | FIT checksum rule |
| same, sections 3.1 and 3.1.1 (pdf pp. 27 to 28) | SAL_A starts recovery if "the PAL_A code reports an authentication failure on the PAL_B component"; recovery code "shall authenticate a new firmware image using a PAL_A procedure" | who calls authentication |
| same, SAL_UPDATE_PAL (pdf pp. 112 and 114) | the update call "will utilize resources within the processor and/or PAL to authenticate the contents of the new version of PAL"; on a warm reboot "it will conduct the authentication steps again" | authentication uses the processor and PAL |
| Itanium 2 Processor Specification Update 251141-001, erratum 30 (pdf p. 11) | recovery check fails if PAL_B is missing or invalid | PAL_B is checked at recovery |
| Intel Itanium Processor Specification Update 251141-063 (April 2014), erratum 165 (p. 79), summary table 3.5 sheet 3 of 5 (p. 24) | "During boot, if a code request from the system bus or L3 cache completes while any logical processor is authenticating PAL, unexpected behavior may result." The row is marked for Itanium Processor 9000 Series under PAL Version 7.46 only, no stepping marked, status Fixed. Itanium Processor sheets 3.2 to 3.4 (up to 3, 6 and 9 MB L3) have no row for 165, so Madison is not listed | the processor performs PAL authentication at boot, **established** for the 9000 Series. The erratum says nothing about the algorithm, key or coverage, so the processor's service running the same DSA check as the software route stays **inferred** |
| Intel Itanium Processor Specification Update 251141-063 (April 2014), erratum 118 (p. 70), summary table 3.5 sheet 1 of 5 (p. 22) and 3.6 sheet 1 of 2 (p. 27) | br.ia with BSPSTORE != BSP should raise an Illegal Operation fault, and the Disabled Instruction Set Transition fault wins when psr.di is also set. Workaround: "It is recommended that a srlz.i be executed prior to a br.ia." Marked C1 (9000 Series) and A1 (9100 Series), No Fix | the br.ia fault priority and the srlz.i workaround only; it says nothing about PAL authentication |
| US 6,571,335 B1, "System and method for authentication of off-chip processor firmware code" (Intel, filed 1999-04-01, granted 2003-05-27) | the PAL code carries a DSA digital signature (a pair of numbers SIG_R and SIG_S) made over a SHA-1 digest "in response to a processor reset condition"; the signatory's public key and DSA code sit in on-chip memory; in one embodiment (its FIG. 7) a mismatch leaves "the electronic system ... not released from the processor reset condition", in another (FIG. 6) it reports an error or blocks execution; the hashed bytes are "the PAL code" with no byte ranges or header layout | the scheme the images follow |
| US 6,542,981 B1, "Microcode upgrade and special function support by executing RISC instruction to invoke resident microcode" (Intel, filed 1999-12-28, granted 2003-04-01) | a special `br.ia`, gated by "one MSR to a special value", sets an error code and returns to a branch-register address; "the authentication engine achieves this by a one-way hash function or other methods"; no hash, key or signature size is given | mechanism of the `br.ia` call, no algorithm |

Not found: any Intel document that defines the PAL_A header or a processor-specific `br.ia` function number. The SDM
and the Itanium 2 hardware developer's and reference manuals (251109, 251110) say nothing about the `br.ia` service or
the PAL header; the held SAL specification does not list the FIT reserved byte's meaning. The UEFI Platform
Initialization boot-path text says processor microcode authenticates PAL_A and PAL_A authenticates PAL_B; it was seen
only as a search snippet and the page itself could not be fetched. No public firmware source (EDK, ELILO, Linux) that
builds or checks these signatures was found; the search was not exhaustive (an automated search was refused partway).

## What the images carry (established)

All measurements on the three processor-specific PAL_A images (FIT type 0x0e, 7.31 at `0xfffc2fc0`, 5.37 at
`0xfffc9ac0`, 1.27 at `0xfffd0280`; sizes 0x6b00, 0x67c0 and 0x6ce0 bytes from the FIT size field times 16), the three
PAL_B images, and Intel's PAL_A 5.37, 1.27 and 7.46 in the SR870BN4 BIOS (`S870BN4C.BIN`). Offsets are from the image start;
N is the image length.

- **FIT checksum rule holds.** The sum of all bytes of the image plus the FIT checksum byte is 0 mod 256 for all three SGI
  PAL_A images and all three Intel ones (SAL specification section 2.5). It covers the whole image including the first 16
  bytes. This is software-visible arithmetic only; it is not the authentication.
- **16-byte lead.** Bytes 0 to 15 of 7.31, 5.37 and 1.27 are random-looking and different. 5.37 and 1.27 are byte-identical
  to Intel's copies, lead included, so the lead is the same for any vendor and is not a per-vendor key. Intel's 7.46 has
  sixteen zero bytes there (and no signature tail, below).
- **PAL header** begins at byte 16: byte 21 and 20 are the version (5.37 is `37 05`), byte 22 the CPUID model the image
  targets (0, 1, 2 for 7.31, 5.37, 1.27), byte 23 the CPUID family (0x1f). The generic PAL_A compares the bytes at +20
  with CPUID register 3 when it picks an image (objdump, bundles `0xffff8636` to `0xffff869c`; that the model and family
  fields are the compared ones is **inferred** from the bit positions).
- **48-byte tail.** The last 48 bytes of each PAL_A_spec and each PAL_B hold two 20-byte little-endian numbers, each padded
  with four zero bytes to 24: SIG_R at N-48 and a second value at N-24. The 16 bytes before the tail are a constant
  bundle. SIG_R is the same in all six SGI images and in Intel's 5.37 and 1.27; the second value differs per image.
  Intel's 7.46 carries no signature that verifies with this key (established: no tried coverage and no tail position verifies); that it has no tail at all is inferred.

## The software verifier in the generic PAL_A (established)

The vector bundle at `0xffffff80` is `br.few 0xffffda60` ([boot-sequence.md](boot-sequence.md) lists it among the event
vectors). Reading the routine at `0xffffda60` (objdump; Ghidra made no function there, see the notes below) and the SHA-1
code it calls:

- **Entry and arguments (established).** `r32 = -1` selects PAL_B: the routine reads the FIT address from
  `0xffffffe0`, takes the first FIT entry after the header and uses its address (bit 63 forced) and size times 16. Any
  other `r32` takes a component the caller describes: `r8` is the start of the hashed bytes and `r9` the byte count
  from there to the component end. The generic PAL_A FIT walk calls it with `r32 = -2`, `r8` = component address + 16
  and `r9` = size times 16 minus 16 at `0xffff881c`, but only when bit 24 of the FIT entry's second word (the reserved
  byte) is set (`tbit` at `0xffff86d6`). When that bit is clear, which is the case in all FIT entries of this image, the
  walk takes the `br.ia` path at `0xffff872c` instead.
- **Message (established).** SHA-1 (standard FIPS 180-1; the routine's digest was reproduced exactly for message lengths
  up to 27 KB by running its own code in a small emulator, and every round constant and the one-bit schedule rotation are
  those of SHA-1) over `[addr, addr + len - 64)`. For a processor-specific PAL_A that is bytes 16 to N-65 of the image
  (the lead and the last 64 bytes are excluded); for PAL_B it is bytes 0 to N-65.
- **Key (established).** At `0xffffa1d0` are three 128-byte little-endian numbers p, g and y, followed at `0xffffa350`
  by a 20-byte q. p is prime (1024 bits), q is prime (160 bits), q divides p-1, and g and y both have order q mod p:
  a DSA public key.
- **Check (established).** With H the digest read as a big-endian number, r the first value of the tail and w the second:
  u1 = H*w mod q, u2 = r*w mod q, and the signature is good when (g^u1 * y^u2 mod p) mod q = r. The second value is
  stored already inverted, so the routine does no modular inversion. Return: `r8 = 0` and `r32 = 0` on success, `-1`
  in both on failure; the success tail also tests msr[1779] bit 15 and leaves through the common error exit with
  `r30 = 1` when it is set (what that register is is unknown).

**Verification run (established).** Reproduced outside the firmware with SHA-1 and big-integer arithmetic: all six
signatures verify (PAL_A 7.31, 5.37, 1.27 over `[16, N-64)`; PAL_B 7.79, 5.73, 2.25 over `[0, N-64)`); Intel's copies of
5.37 and 1.27 verify; Intel's 7.46 does not. Flipping one bit in the body of 5.37 breaks the check; flipping a bit in the
16-byte lead, or in the 16 constant bytes before the tail, does not. A re-implementation of the firmware routine in a
small IA-64 interpreter reproduced the SHA-1 digest and the first modular multiply (s*H mod q, which is how the
no-inversion form was recognised) but not the final comparison, so the interpreter is not a validated model of the
routine's last stage; the verification above does not depend on it.

Observation, not used further: SIG_R is identical in every signed image, so the signing tool used the same per-signature
value each time.

## What the SAL and PAL specifications define

Documents: SDM volume 2, 245318 rev 2.3 ("SDM"), and SAL specification 245359-009 rev 3.4 ("SAL spec"). Page numbers are printed numbers.

- **Authentication is optional and implementation-specific.** PALE_RESET "may optionally perform authentication of the PAL
  firmware" (SDM 11.2.1, p. 2:289). The recovery-check exit state lists "an implementation-specific PAL procedure for PAL
  authentication" among the calls PAL provides, in GR34; GR36 carries that procedure's address on the second SALE_ENTRY
  call (SDM 11.2.2, p. 2:290). The specs give no index, arguments or return values for it. The call needs PSR.dfh = 0
  (SDM PAL note b, p. 2:360). **established**
- **Failure.** The specs define failure only as SALE_ENTRY status values (table below). SAL_A starts recovery when PAL_A
  reports an authentication failure on PAL_B or checksum errors in the FIT or PAL_B (SAL spec 3.1, p. 27), and the
  recovery code "shall authenticate a new firmware image using a PAL_A procedure" (SAL spec 3.1.1, p. 28). SAL_UPDATE_PAL
  returns -2 when the supplied PAL "failed the authentication test" (SAL spec, p. 113). That is a SAL return, not a PAL one.
  **established**
- **FIT fields.** Entry layout (SAL spec Figure 2-5, p. 22): Checksum bits 63:56, C_V bit 55, Type 54:48, Version 47:32,
  Reserved 31:24, Size 23:0. The bytes of the component plus Chksum sum to zero, and Chksum counts only when C_V is set.
  The PAL_A FIT entry at 4 GB - 48 is outside the FIT checksum (SAL spec 2.5, p. 22). The specs define no authentication
  flag in the FIT. Bit 24 is the low bit of the reserved byte, to which the spec gives no meaning. **established**
- **Not defined by the specs:** the value of the PAL authentication address in this PROM (0xffffda60), the argument
  (r32 = -2 at 0xffff881c) and result convention of its routine (the r1 accept test, r8, r32), and the msr[1643] carrier.
  Each stays inferred or unknown as stated above.

SALE_ENTRY status values (SDM Table 11-4, pp. 2:292 and 2:293). The status is the 8-bit field of the SALE_ENTRY state
parameter in GR20 (Figure 11-7, p. 2:291). The table is the spec's definition, not a statement about msr[1643]:

| Value | Specification meaning | PROM use | Grade |
|---|---|---|---|
| 0 | Normal reset | written before the specific PAL_A entry | defined |
| 4, 5, 16 | PAL_A / PAL_B authentication failure | not used | defined |
| 9, 12, 14 | no usable specific PAL_A (checksum or authentication, or not found) | assigned, then overwritten | defined |
| 10 | specific PAL_A found in the alternate FIT, FIT checksum failed | written | defined |
| 11 | some specific PAL_A failed checksum or authentication, a good one found in the FIT | written | defined |
| 13 | some specific PAL_A failed checksum or authentication, a good one found in the alternate FIT | written | defined |
| 15 | none in the FIT, a good one found in the alternate FIT | written | defined |

Two consequences. Values 10, 11, 13 and 15 each report a good specific PAL_A being found, so none is a plain failure code;
the "failure" reading in [boot-sequence.md](boot-sequence.md) fits only 11 and 13, and those also report a good one. This image's alternate FIT
address is zero, so 10 and 15 describe an alternate FIT the image does not have. Which register delivers these values to
SAL is not defined; GR20 is the spec's carrier. **established** for the definitions, **inferred** for the PROM mapping.

The SALE_ENTRY exit state in [boot-sequence.md](boot-sequence.md) matches SDM 11.2.2 (pp. 2:289 to 2:291): GR20 to GR38
as listed, RSC 0, CFM.sof 96, PSR.bn 1 with the other PSR bits 0, DCR 0, IVA 0 for the recovery check, and the
interruption block pointer at 0xFEE00000. **established**

## What the processor's `br.ia` service checks (unknown)

The generic PAL_A reaches the service at `0xffff872c` (`r2` = component address with bit 63, `r3` = size in paragraphs,
`r5` = 1, `b0` = `0xffff8730`) after msr[212] = 0 and msr[1225] = 4; it accepts the image when `r1` is zero afterwards
([pal-msrs.md](pal-msrs.md) has the full setup). The specific PAL_A calls it again at `0xfffc4a6c` (5.37
`0xfffcb670`) with `r2` = `r3` = `r5` = 0 and ignores the result; that is function 0 of the same service and takes no
image (objdump). Ghidra models both as an opaque `br_ia(b0)` call and loses `r1`, so it cannot show the result test.

No held document describes the service. Evidence that it checks the same signature (all **inferred**):

1. The software verifier takes exactly the data the call passes (component address and size), skips the same 16-byte
   lead region the PAL header begins after, and is selected by a flag bit in the same FIT entry word: two alternative
   routes to one decision.
2. The signature tail exists on every image the service would see, and Intel's 7.46 is the one image with no
   `br.ia` of the msr[1225] kind (the PAL_A 7.46 code uses none of 212, 1225 or 1640 to 1643,
   [pal-msrs.md](pal-msrs.md)). The Montecito images are not signed with the Madison DSA key; whether they carry some other
   signature is unknown ([cross-vendor review](../pal/cross-vendor.md)).
3. US 6,571,335 describes a processor verifying a DSA/SHA-1 signature on PAL code at reset from a key held on-chip.

Evidence against treating it as proven: nothing shows the microcode uses the same coverage, the same key or the lead
bytes. The 16-byte lead is not covered by the software check and its purpose is unknown.

## Hypotheses tested on the lead value (all negative)

Against bytes 0 to 15 of each PAL_A image (and the six-image tail, where stated):

| Test | Result |
|---|---|
| 8, 16, 32 and 64-bit little- and big-endian sums and two's-complement sums of the whole image, of the image minus the lead, minus the tail, and up to the size field; 8-bit XOR | no lead value matches; the one-byte matches (7.31's byte 1 equals the 8-bit sum; 5.37's byte 14 equals the 8-bit sum of the body) are what a 1-in-256 chance gives across 16 positions and is not repeated in the other images |
| CRC-16 (CCITT-false, XMODEM, ARC, Kermit, Modbus, X.25), CRC-32, Adler-32 over the same ranges | no match |
| MD5, SHA-1, SHA-224/256/384/512 over 7 coverage ranges, and over slices that start or end at the lead, tail and tail-field boundaries, the public key, SIG_R and SIG_R plus the second value (every 16-byte window of each digest, and the reverse); SHA-3-256, BLAKE2b/s, RIPEMD-160 and SM3 over the 7 ranges | no match for the full 16 bytes; none of the digests had a 4- or 8-byte window equal to the lead's first, middle or last 4 or 8 bytes |
| FIT checksum byte rule | holds, but is a separate byte-sum check, not the lead |
| Compare across versions and vendors | lead is identical for the same version in SGI and Intel builds (5.37, 1.27); different across versions; zero in Intel 7.46 |

Reading: the lead is deterministic per image or per version, not vendor-keyed. A keyed construction cannot be ruled out;
no unkeyed function over the image or the tail reproduces it.

## Other sites

- **The specific PAL_A's own PAL_B check (Ghidra).** The decompiled 7.31 and 5.37 entry routines walk the FIT themselves
  for the first PAL_B (type 1): they test the low 11 bits of its address, compare header bytes at +0x10114 with CPUID
  register 3, and accept it when the FIT C_V bit is clear or a byte-sum helper plus the FIT checksum byte is zero. The
  helper (`0xfffced80` in 5.37, `0xfffc99d0` in 7.31) decompiles as a modulo-scheduled byte-lane sum (`padd1`). That is a
  checksum, not a signature check. The `br_ia` call that follows is gated by msr[1225] bit 2 or bit 14, as in
  [pal-msrs.md](pal-msrs.md).
- **PAL_B's `br.ia` sites** are catalogued in [pal-msrs.md](pal-msrs.md). Their `r2`, `r3`, `r5` setup differs from the
  PAL_A one and none passes a component address and size in the PAL_A form; they were not traced to a result use.
  Their purpose is unknown.
- **SAL.** SAL_A at `0xffc4e000` has no pointer or immediate to `0xffffda60` or `0xffffff80` (objdump search of its 16 KiB),
  so it reaches authentication only through the call address PAL passes in GR34 and GR36 at SALE_ENTRY (SDM section 11.2.2).
  The SALE_ENTRY recovery path (function 3) and the SAL runtime's firmware update were not traced to that call.
- **`main_verify_elf_signature` (Ghidra).** The SAL runtime component (FIT type 0x12, gzip, an ELF) exports this 160-byte
  function at `0x25590`. Ghidra decompiles it to a 16-byte copy of a constant followed by a 16-byte `strncmp` against the
  argument. The constant, found through the gp offset in the first instruction (objdump), is the 16-byte ELF64
  little-endian identification (`7f 'E' 'L' 'F'`, class 2, data 1, version 1, padding). It is a file-format magic test,
  not a hash or key check (established; because `strncmp` stops at the first zero byte it compares the first seven bytes
  only). It shares nothing with the PAL scheme.

## Contract for a model

Established parts:

1. FIT checksum: for any component with C_V set, the sum of its bytes plus the checksum byte is 0 mod 256.
2. Authentication entry `0xffffff80` (`r32 = -1` PAL_B, other `r32` a described component): returns `r8 = 0` when the
   DSA signature described above verifies, `r8 = -1` otherwise.

The `br.ia` service the generic PAL_A actually uses on this path (inferred, not established): given `r2` = component
address and `r3` = size in 16-byte paragraphs with msr[1225] = 4 and `r5` = 1, treat the call as the same verification
of a processor-specific PAL_A (message `[16, N-64)`), and set `r1` to 0 when it verifies and non-zero when it does not.
The 16-byte lead is not checked in this model. A model that always sets `r1` to 0 also matches every image in this
PROM, so only a test with a corrupted image separates the two, and no such hardware result is held.

## Remaining unknowns

- What the microcode `br.ia` function with `r5 = 1` checks: coverage, key, whether the 16-byte lead is used, the meaning of
  the error code. Route: a hardware trace of the call (`r1` after the call, with a modified image) or an Intel
  document on the service; neither is held. Listed in [../../../questions/pal-authentication-open.md](../../../questions/pal-authentication-open.md).
- Who calls the authentication entry with `r32 = -1` and the exact path SALE_ENTRY takes (recovery check, firmware update).
- What msr[1779] bit 15 means on the software success path.

## Ghidra notes

- `--decompile-all` of the whole 6 MiB image did not finish: the run ended with exit 143 (killed) about five minutes in,
  after auto-analysis, and wrote no decompile output. Targeted `@0xADDR` lists worked.
- No function is created at `0xffff8720`, `0xffff8210`, `0xffff9120`, `0xffff8600`, `0xffff88f0` or `0xffffda60`
  (`no function matches`), so the generic PAL_A FIT walk and the authentication routine could not be decompiled; those
  readings are from the disassembly. Only the reset-vector function stubs and the PAL_A_spec entry routines (offset
  0x300) exist.
- `br.ia` is modelled as an opaque `br_ia(b0)` userop that falls through; `r2`, `r3`, `r5` and the `r1` result do not
  appear, so the accept test after the call is invisible in the C.
- Modulo-scheduled loops (the byte-sum helper, the multiprecision routines) decompile to `rotate_regs()` placeholders.
- A flat-image import of the SAL runtime ELF has no symbols; `salruntime_checksum_fit` (`0x7390`) had no function and
  was not read.

## Review

Independent review of chips commit `416e8b5` (this page and `questions/pal-authentication-open.md`). The reviewer did not write the page and did not use the author's scripts: the verification below is a fresh big-integer and SHA-1 computation in Python written for this review, run over `shub1snprom.bin` (SAL 5.04, snprom 10.54 build 70399) and over Intel's `S870BN4C.BIN` (package `SR870BN4_1001_SUP3.ZIP`, sha256 `fb422439a42e3d06fe5286c68942c03293868cdde07891758437d4f98642d252`). Nothing was taken from the page's own tables. The route selection was read in the retools IA-64 Ghidra disassembly (every bundle of the image dumped through the module) and cross-checked with the binutils disassembly. The decompiler could not be used: `--decompile-symbol @0xffffff80`, `@0xffffda60`, `@0xffff86d6`, `@0xffff872c` and `@0xffff881c` each reported "no function matches", as the Ghidra notes say.

**Reproduced independently.**

- Key: p, g and y are contiguous 128-byte little-endian numbers at `0xffffa1d0`, q is 20 bytes at `0xffffa350`. p is a 1024-bit prime, q a 160-bit prime (Miller-Rabin, 64 random bases), q divides p-1, g and y are not 1 and both satisfy x^q = 1 mod p.
- Signature layout: r is the 20 little-endian bytes at N-48 and w the 20 at N-24, each padded with four zero bytes, in all six SGI images. The 16 bytes before the tail are identical in all six, r is the same in all six, and w differs in each.
- Verification, message SHA-1 over `[16, N-64)` (PAL_A) or `[0, N-64)` (PAL_B), H big-endian, u1 = H*w mod q, u2 = r*w mod q, check `(g^u1 * y^u2 mod p) mod q = r`: **verifies** for PAL_A 7.31, 5.37 and 1.27 and for PAL_B 7.79, 5.73 and 2.25.
- Intel: the SR870BN4 BIOS carries two FITs; the one whose PAL entries map to the images was used, and each Intel image was located and its FIT checksum checked against Intel's own entry. PAL_A 5.37 and 1.27 are byte-identical to the SGI images and **verify**. PAL_A 7.46 has an all-zero 16-byte lead, a valid FIT checksum and **does not verify**: no combination of start offset (0 or 16), end trim (0 to 80 bytes in 16-byte steps) and tail position (every 8-byte step in the last 200 bytes) verifies.
- Tamper tests on 5.37: a flipped bit in the body, in byte 16, and in byte N-65 each **fail**; a flipped bit in the 16-byte lead and in the 16 bytes before the tail each still **verify**. On PAL_B 7.79: a flipped bit in byte 0 or in the body fails, in the 16 bytes before the tail still verifies. Intel's 5.37 behaves the same as the SGI copy.
- FIT checksum: for all three PAL_A images in the SGI FIT (C_V set) the byte sum plus the checksum byte is 0 mod 256, covering the lead; the same holds for Intel's 5.37, 1.27 and 7.46. The three SGI PAL_B entries have C_V clear.
- Route (Ghidra listing, objdump agrees): `0xffffff80` is `br.few 0xffffda60`. In the FIT walk, `ld8 r82` and `ld8 r83` read an entry's two words (`0xffff85c0`), `tbit.z p0,p2=r83,24` at `0xffff86d6` branches to `0xffff8770` when bit 24 is set, and that path ends in `br.call b2=0xffffda60` at `0xffff881c` with `r32 = -2`, `r8 = r82 + 16` and `r9 = (size * 16) - 16`. With the bit clear it falls to `br.ia.sptk.few b0` at `0xffff872c` with `r5 = 1`, `r2 = r82`, `r3` = size. Bit 24 of the second word (the reserved byte) is zero in all 14 entries of this image's FIT.
- US 6,571,335 B1, read on patents.google.com (it is not in the Library; list it for ingestion): Intel, filed 1999-04-01 and granted 2003-05-27; DSA signature as the pair SIG_R and SIG_S, SHA-1 digest, check "in response to a processor reset condition", public key and DSA code in on-chip memory.

**Mechanical fixes made in this review.**

1. The patent row said a mismatch leaves the system "not released from the processor reset condition". That is the patent's FIG. 7 embodiment only; FIG. 6 reports an error or blocks execution. The patent also gives no byte ranges or header layout for the hashed code. Row corrected.
2. "Intel's 7.46 has no such tail (established ...)" overstated a negative. What was shown is that no signature verifies with this key under any tried coverage or tail position; that no tail exists is inferred. Text corrected.

**Not re-read (kept at the author's grade).** The return convention at `0xffffda60` (`r8` and `r32` of 0 or -1, the msr[1779] bit 15 test), the claim that the author's interpreter reproduced the SHA-1 digest, and the PAL_A and PAL_B `br.ia` site details in [pal-msrs.md](pal-msrs.md). The `main_verify_elf_signature` note and the 16-byte lead hypothesis table were not re-derived either.

**Grades.** The software check (key, layout, coverage, equation, per-image results, tamper behaviour) is **established** by computation. The route selection in the generic PAL_A is **established** from the disassembly. That the processor's `br.ia` service runs the same check is correctly **inferred**, and the patent text does not strengthen it: it describes a hash over "the PAL code" and gives no coverage, so it neither confirms nor contradicts the 16-byte lead being outside the check. The FIT checksum rule is **established** for the PAL_A images held.

**Caution for a model.** This image never takes the software route, because every FIT entry has bit 24 clear. The result of the `br.ia` step in the generic PAL_A is therefore the inferred part of the contract, not the verified software routine. A CPU model that computes the verification result for it is modelling an inference. The page already says so, and says that a model returning success for every image matches all the images in this PROM.

**Cleared scope:** the DSA key, the signature layout, the coverage, the verification equation and its per-image results (including Intel's three PAL_A images), the tamper behaviour, the route selection, the FIT checksum rule and the patent citation. **Not cleared:** the br.ia service's own behaviour (inferred), the return convention of the software routine, and the items listed as not re-read.
