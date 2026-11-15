# PIC fields and revisions: open points

Open after adding the field layouts and the revision table to [devices/pic/README.md](../devices/pic/README.md).
Each entry: question, routes tried, next route.

## PCI-X error group location

[missing source] SGI's 2.4-era PIC header lists the PCI-X error address, attribute, data and read-request-timeout registers
at 0xe0 to 0xf8, while its own structure, SGI's v5.3 `struct pic` and the IRIX code (0x600 to 0x630) place them at 0x600
and up, with the timeout at 0x638. Routes tried: both headers, the IRIX census. Next: a PIC datasheet, or a read of 0xe0 to
0xf8 on a running chip (needs the repository owner's approval; the registers are read-only error holders, but the PIC
page's rules on physical reads apply).

## Which silicon revision an Altix PIC is

[missing source] The SN2 Linux provider never reads the identification register and the SN2 PROM reading (inferred) compares only the low
twelve bits and the part number. No manual states a revision. Routes tried: Linux v5.3 provider files, the SN2 PROM
reading, the Altix 350 guides. Next: a boot log from an Altix 350 that prints the widget identification, or the PROM's
bridge discovery output.

## Whether SN2 firmware applies the revision-1 workarounds

[missing source] The Linux kernel does not apply the erratum workarounds that IRIX and the 2.4-era driver apply on revision 1.
A revision 1 part on an Altix would need firmware to apply them. Routes tried: Linux v5.3 files. Next: read the SN2 PROM's
bridge setup for the response-buffer constant 0xf000f and the 0x750 timeout, with a PROM image.

## What the SN2 PROM page calls part 0xd112

[software now] The SN2 PROM page reads the compare against 0xd112 as the TIOCP. SGI's header names 0xd112 as the PIC's second
bus. The PROM page's label should be rechecked against the header (not edited here: the page is outside the PIC unit).

## Reset values

[missing source] Only the interrupt enable register has a stated reset (zero, header comment). Everything else, including the
control register, is unknown. A PIC datasheet would settle them.
