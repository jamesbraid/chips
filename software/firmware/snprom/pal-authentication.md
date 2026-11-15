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
| US 6,571,335 B1, "System and method for authentication of off-chip processor firmware code" (Intel, filed 1999-04-01, granted 2003-05-27) | the PAL code carries a DSA digital signature (a pair of numbers SIG_R and SIG_S) made over a SHA-1 digest "in response to a processor reset condition"; the signatory's public key and DSA code sit in on-chip memory; on mismatch "the electronic system is not released from the processor reset condition" | the scheme the images follow |
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
  Intel's 7.46 has no such tail (established by the verification failing for every coverage tried, and its last bytes
  looking like code).

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
2. The signature tail exists on every image the service would see, and Intel's unsigned 7.46 is the one image with no
   `br.ia` of the msr[1225] kind (the PAL_A 7.46 code uses none of 212, 1225 or 1640 to 1643,
   [pal-msrs.md](pal-msrs.md)).
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
