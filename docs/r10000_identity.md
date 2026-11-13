# R10000 family processor identity

This page covers the identity word the MIPS R10000 family reports, the revision rule that tells an R14000 from an R16000, and the Config fields that set the secondary cache size and line. It is the processor's own register contract as far as public software describes it, not a chip in the SGI system. The constants are in [devices/r10000_identity/registers.toml](../devices/r10000_identity/registers.toml), generated to [devices/r10000_identity/registers.md](../devices/r10000_identity/registers.md).

The family covers the R10000, R12000, R14000 and R16000. Nothing here was read from silicon or from a running machine except the one printed capture named below.

## Sources and grades

- Linux 6.6 (tag `v6.6`) `arch/mips/include/asm/cpu.h`, `arch/mips/include/asm/mipsregs.h`, `arch/mips/kernel/cpu-probe.c` and `arch/mips/mm/c-r4k.c`. Read for this page at the tag, not at the pinned `linux` submodule commit. A public driver file is established for what the driver does. A driver shows what software expects, so a driver fact is a statement about software, not a measurement of the chip.
- NYCBUG dmesgd record 5290, a NetBSD boot log of an O2 with an R12000, from the public archive at `dmesgd.nycbug.org`. A printed boot line is established for the text it prints.

The processor manuals (NEC VR10000 and VR12000, MIPS R10000) are the usual owner of these fields. They were not read for this page, so every claim below rests on the two sources above.

## Identity word (CP0 PRId)

- The implementation byte is bits 15:8. The R10000 is `0x09`, the R12000 is `0x0e`, and the R14000 and R16000 both use `0x0f`. Established (Linux `cpu.h`).
- The revision byte is bits 7:0, read as a major and a minor nibble. Established (Linux `PRID_REV_MASK`).
- Under implementation `0x0f`, a revision whose major nibble is 3 or more is an R16000. A major of 2 or less is an R14000. Established (Linux `cpu-probe.c`). So a revision `3.0` word reads as an R16000, and `2.4` reads as an R14000. These are raw words. OpenBSD prints an R16000 revision with two subtracted from the major nibble, so a printed R16000 revision is not a raw word; see [docs/r16000.md](r16000.md).
- The driver's name table uses only the implementation byte and this revision rule. It has no separate name for any "A" part. Established for Linux. Whether IRIX or the system firmware prints a different name was not checked here.

Bits 31:16 of PRId are outside the fields these sources test, and this page says nothing about them.

## Printed identity on one O2

NYCBUG record 5290 prints, for an O2 with an R12000 booted from a NetBSD netboot:

- `MIPS R12000 CPU (0xe23) Rev. 2.3`, so the PRId low 16 bits were `0x0e23` on that machine. Established for that print.
- `with unknown FPC type (0x900) Rev. 0.0`, so the floating-point word was `0x0900`, revision byte zero. Established for that print. NetBSD had no name for that word, so its FPU table does not list it.
- `1024KB/64B 2-way set-associative write-back L2 data cache`. The size and the 64-byte line are the values as printed. Whether NetBSD took them from Config or from the firmware's component tree was not checked, so this capture does not establish which Config fields held those values.

One capture of one machine. It does not show what other revisions or clocks print.

## Secondary cache fields in Config

The Linux driver reads the secondary cache from Config for every family member through the same case list (R10000, R12000, R14000 and R16000):

- Size: bits 18:16 (the SS field). The size is `512 KB << SS`, so SS 0 is 512 KB, SS 1 is 1 MB, SS 2 is 2 MB and SS 3 is 4 MB. Established (Linux `c-r4k.c` and `mipsregs.h`).
- Line: bit 13 (the SB bit). The line is `64 << SB` bytes, so 64 bytes when SB is 0 and 128 bytes when SB is 1. Established (Linux `c-r4k.c` and `mipsregs.h`).
- Associativity: the driver sets two ways for every family member. Established (Linux `c-r4k.c`).

The driver applies these fields to the R16000 with no separate case. That is a software expectation. No capture of an R16000 line size was checked here.

## Unknown, and what would settle it

- **Which revision each part and clock prints.** The revision list per part comes from public `hinv` postings, which this page did not collect by message identifier. Settled by citing the postings with their message identifiers.
- **Whether the R12000 revision 3 parts have a secondary-cache syndrome field in performance control 0, and whether any system software reads it.** Not checked. Settled by the processor manual section for those revisions and by reading the IRIX kernel's cache-error path.
- **Floating-point word for the R16000 and for parts other than the one O2 print.** No raw R16000 FPU word was read. Printed FPU names and revisions for the 1.0 GHz R16000 are in [docs/r16000.md](r16000.md); they come from firmware display data, and the two prints disagree. Settled by a Linux or BSD boot line that prints the FPU revision from a raw read on that part.
- **Config fields other than SS and SB** (the clock-ratio fields, K0, and the mode bits). No Linux or BSD print of them was checked. Settled by a raw Config read or a boot line that prints it, per part.
- **Refused uncached stores, CACHE operation differences, TLB register widths and partial-word loads per part.** The R10000 manual covers the R10000. The other parts are not covered here. Settled by the owning processor manual for each part, or by a register readback on the part.
