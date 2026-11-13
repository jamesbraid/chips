# ICS1890 Ethernet PHY (Octane base I/O)

The ICS1890 is Integrated Circuit Systems' 10Base-T/100Base-TX PHYceiver, the
Ethernet transceiver on the Octane and Octane2 base I/O board (inferred: neither
the datasheet nor a public driver names that board; the public Linux `meth.c` driver
names this part, identifier `0x0015F42`, for the O2's MACE Ethernet, which agrees with
the identity register below). The IOC3 Ethernet controller reaches it through the MII
management port. The register contract is
in `devices/ics1890/registers.toml` and its reference page is `devices/ics1890/registers.md`.

## Source

*ICS1890 10Base-T/100Base-TX Integrated PHYceiver*, Integrated Circuit Systems,
document revision G, dated 1997-10-21 (publication label `ICS1890RevG 10/21/97`).
The datasheet has 66 pages, and the printed page numbers match the PDF page
numbers. Each fact in the defs unit cites the page it came from.

## Which part, and how it is identified

The part answers two MII identifier registers, which the datasheet gives as
register 2 and register 3:

- Register 2 reads `0x0015`, the low 16 bits of the Integrated Circuit Systems
  OUI (datasheet p. 23).
- Register 3 reads `0xf423` (datasheet p. 24). Its model field, bits 9 to 4, is 2,
  which the datasheet names ICS1890. Model 1 is the ICS1889, a different part with
  the same layout. Its revision field, bits 3 to 0, is 3, which the datasheet
  calls the "1890 J release and above". Revision 2 is the first general release.

Both identifier registers reset to the ICS OUI. Writes to them are accepted only
after the command override bit (bit 15 of register 16, datasheet p. 29) is set,
and the datasheet describes this as the way a system vendor can substitute its own
OUI. The defs unit records the identifier values and the register 16 bit, but not
the substitution procedure in full.

## Address on the Octane

The address comes from the LED pin connections (register 16 bits 10 to 6,
datasheet p. 29), so a board sets it in hardware and software can only read it.
The datasheet does not say which address a given board uses.

Which MII address the Octane's PHY answers at, and whether it reads back identity
`0x15f42` (model 2, revision 3), is **unknown** here. An earlier version of this page
recorded it as observed in three public Linux boot captures, but those captures are
not held in this repository and could not be re-read, so the claim rested only on a
note from another project. The route that settles it is a public Octane boot log
that prints the PHY address and identifier, kept with its source. The datasheet
values above show what the part reports by default, which is consistent with
model 2, revision 3, but do not show what an Octane board's part does. Transfer of
any such address to the Octane2 is likewise unknown.

The Origin 200 and Origin 300 use other PHYs, the DP83840A and DP83843, which
[devices/dp83843/README.md](../dp83843/README.md) covers. Their identities differ from this part's.

## Reserved bit in the extended control register

Register 16 bit 4 is reserved for ICS use. Its read value is unspecified, and the
datasheet says it may be zero or one. Writes must use zero, and a write of one may
stop the part from operating correctly (datasheet p. 29). The defs unit records
this as established and leaves the read value unknown. A driver or a model should
not expect either value on read.

## What this page does not cover

The datasheet also describes the auto-negotiation registers 4, 5 and 6 (pp. 25 to
28), and the rest of register 16 (the stream cipher, scrambler and 4B5B test bits,
and the NRZ/NRZ1 encoding bit, p. 29). None of those are transcribed into
`devices/ics1890/registers.toml` yet, so their reset values and bit meanings are unknown in
this repository. Reading the datasheet pages cited above is the route to settle
them.
