# PAL image authentication: the processor service

**Route: missing source.** The software verifier for the DSA signature on every PAL image is established (see
[software/firmware/snprom/pal-authentication.md](../software/firmware/snprom/pal-authentication.md)). Not established:
what the Itanium 2 `br.ia` authentication service itself checks when the generic PAL_A calls it with `r5 = 1`.

Unknown:

- the coverage, key and hash the microcode uses, and whether the 16-byte value at the start of each processor-specific
  PAL_A image takes part (the software check ignores it);
- the error code the service leaves in `r1`;
- what msr[1779] bit 15 means on the software success path.

Routes tried: the held Itanium and Itanium 2 manuals, the two Intel patents on the mechanism (US 6,571,335 and
US 6,542,981), tests of the 16-byte value against sums, CRCs and unkeyed hashes. None gives the service's definition.

Next: an Intel document on the processor service, or a recorded result of the call on a real processor with a
deliberately altered image.
