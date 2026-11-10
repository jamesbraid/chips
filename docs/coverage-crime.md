# CRIME coverage

The CRIME's register tables and routine readings are on [the chip page](../chips/crime/README.md). This page grades two
coverage questions the shipped software and the public drivers can answer, and says what stays open. Labels follow
[AGENTS.md](../AGENTS.md): **established**, **inferred**, **unknown**.

Sources: IRIX 6.5.30 IP32 `kernel.o` (`get_crimerev`, `0x11838`, read in full), the CRIME 1.5 specification revision 0.3
(Tables 5-7 and 5-8, section 5.9 and the revision history; [docs/specs.md](specs.md)), NetBSD
`sys/arch/sgimips/dev/crime.c` and `crimereg.h`, Linux `arch/mips/sgi-ip32/crime.c` and
`arch/mips/include/asm/ip32/crime.h` (mainline master of 2026-08).

## The upper word of the identification register

`get_crimerev` loads the doubleword at `0x0`, keeps the low nibble as `rev` and bits 63:32 as `hi`, and returns: with `hi`
equal 0, 0 when `rev` is 0 and `0x11` otherwise; with `hi` equal 1, `0x13`; otherwise `0x14`. The specification defines only
bits 7:0 (ID value 7:4, revision 3:0; Table 5-8, p. 5-26) and says the original (Petty) CRIME had ID `0xA` and revision 0 and
CRIME 1.1 had ID `0xA` and revision 1. CRIME 1.5's reset value is ID `0xB`, revision 1.

NetBSD's attach routine gives the upper word its meaning. For ID value `0xA` it prints revision 1.1 when bits 63:32 are 0,
1.3 when they are 1 and 1.4 otherwise; for ID `0xB` it prints 1.5; for ID 0 it prints "Petty CRIME". Linux defines the
constants `0x00`, `0x11`, `0x13` and `0x14` for the same four steps.

- **Established:** the upper word is a revision discriminator within the CRIME 1.x family on the parts that predate 1.5:
  0 is 1.1 (or Petty when the low nibble is 0), 1 is 1.3 and a larger value is 1.4. Two independent software readings
  (the IRIX return values and the NetBSD text) classify the same three values the same way. The specification does not
  describe the upper word (its revision history covers the 1.1 to 1.5 change in the error status register only), so this
  is a driver's statement, not a measurement.
- **Inferred:** IRIX never looks at the ID value in bits 7:4, so on a CRIME 1.5 it returns `0x11`, `0x13` or `0x14`
  depending on whatever the upper word holds there. Callers test only zero against non-zero (the chip page), so the
  result is harmless either way.
- **Unknown:** what the upper word holds on a CRIME 1.5, and why the hardware places a revision outside the specified
  byte. Test: read the doubleword at `0x14000000` on a 1.1, a 1.3, a 1.4 and a 1.5 part and compare with the NetBSD
  classification; the specification's low byte should read `0xA1`, `0xA1`, `0xA1`, `0xB1` or the part's own revision nibble.

## CPU error status on a CRIME 1.5: where it lives

Specification Table 5-7 (p. 5-25) puts the CPU error status register at `0x14004048` on CRIME 1.5 and says it appears at
`0x14000048` on CRIME 1.1; the revision history explains the move as putting the register on its own 16 KB page so it can
be mapped to user programs without exposing the rest of CRIME, and notes an earlier mistaken address of `0x14001048`.
Every software body read uses `0x48`:

- IRIX 6.5.30 IP32: every routine that handles a CPU bus error reads and clears `0x48` (chip page). The routine selects the
  three-bit layout, the 1.5 one, whenever `get_crimerev` is non-zero.
- NetBSD `crime.c` reads and clears `CRIME_CPU_ERROR_STAT`, defined as `0x48`.
- Linux `crime_cpuerr_intr` reads and clears `cpu_error_stat`, the structure member at `0x48`, and masks it to three bits.

**Established:** three independent kernels, each written to run on the whole O2 line (which includes CRIME 1.5), read the
three-bit status from `0x48`. **Unknown:** whether `0x48` on a CRIME 1.5 is an alias of the register at `0x4048` or the specification's move
was not carried into the shipped part. Either way a model that implements the status register at both offsets with
one backing store satisfies all three kernels and the specification. Test on a CRIME 1.5 part: write a known error
state, then read `0x48` and `0x4048`; and write 0 to `0x48` and read `0x4048`.

(The statement that IRIX runs on CRIME 1.5 rests on the product line: the R10000 and R12000 O2 systems use CRIME 1.5 per the
specification's own scope. No ID value was read from a running system here.)

## Not touched

The other CRIME open entries need work this pass did not do: the registers no scanned image reaches wait for the IP32 PROM
to be unpacked, the write-error behaviour has a hardware residue, and the rendering engine field layouts need a renderer or
X server module that is not held.
