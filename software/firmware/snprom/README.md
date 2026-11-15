# SN2 system firmware: the snprom images

What the SGI Altix and Prism firmware images in hand are made of (four read in full, four more builds listed, one of
them read from reset to the EFI console), which machines they target, what the processor does before the EFI console appears, which SAL
calls they answer, and which SHub registers the first stage writes. The path an Altix 350 or Prism node takes from reset
to the EFI console, read in the newest SHub 1 image, is in [boot-sequence.md](boot-sequence.md); every model-specific register access in the PAL code is catalogued in [pal-msrs.md](pal-msrs.md). The two instruction encodings no manual defines, the state a processor must hand the PAL at its event vectors and the register layout at each `br.ia` are in [pal-instructions.md](pal-instructions.md). The single-node memory and node bring-up, with the value each register must return, is in [node-bringup.md](node-bringup.md). What the processor checks before it accepts a PAL image (a DSA signature on each PAL image, the key and software verifier in the generic PAL_A, and what stays unknown about the `br.ia` service) is in [pal-authentication.md](pal-authentication.md). The L1 requests the PROM sends from reset to the console, in order, are in [l1-requests.md](l1-requests.md). The EFI component itself (container, hand-off record, configuration tables, console, variables, boot manager and what a model must provide) is in [efi.md](efi.md). Source for every statement: the shipped images themselves, read with a binutils 2.44 `ia64-linux-gnu-objdump`
built in the retools toolchain image. Nothing here is copied from the images: names are function and string names the
binaries carry, addresses and numbers are quoted as facts.

**Grades.** *established*: read in full from the shipped binary (the whole function, table or structure). *inferred*:
a reading built from a name, a call list, a signature match or a sibling image, with the reasoning given.
*unknown*: not settled, with the route that would settle it ([questions/sn2-prom-open.md](../../../questions/sn2-prom-open.md)).
The kernel names used for SAL calls are Linux v5.3 (`arch/ia64/include/asm/sn/sn_sal.h`, the SN2 platform's vendor
source); the SLES 9 SP3 kernel `2.6.5-7.244-sn2` in the same root confirms which calls shipped kernels make.

## The images

The four images below are flash images that end at 4 GiB: the file maps to the top of the 32-bit physical space (a 6 MiB file
at `0xffa00000`, a 12 MiB file at `0xff400000`). Files are listed in
[evidence/irix-files.md](../../../evidence/irix-files.md#sn2-firmware-and-kernels) with sizes and sha256.

| Image | Package | SAL banner | CPU board name | SHub | Notes |
|---|---|---|---|---|---|
| `snprom.bin` | snprom-4.43-44607 | SAL 4.43, built 2005-12-02 | IP41 | SHub 1 (builds for 1.1, 1.2, "1.x") | NUMAlink 3 and 4 routers, TIO |
| `shub1snprom.bin` | snprom-10.40-62478 | SAL 4.90, built 2007-12-17 | IP41 | SHub 1 | Same line as `snprom.bin`, later build |
| `shub2snprom.bin` | snprom-10.40-62478 | SAL 1.40, built 2007-12-17 | IP65 | SHub 2.0 | NUMAlink 4 only; says SHub 2 has no XIO |
| `shub2snprom.bin` | snprom-10.54-70399 | SAL 1.54, built 2008-11-11 | IP65 | SHub 2 | Newest SHub 2 build held; same line as the 10.40 image |
| `ip65prom.bin` | snprom-10.11-52277 | SAL 1.11, built 2006-10-18 | IP65 | SHub 2.0 | Earlier build of the `shub2snprom.bin` line |

Four more images are in the root and listed in [evidence/irix-files.md](../../../evidence/irix-files.md#sn2-firmware-and-kernels):
`snprom.bin` from snprom 3.32 (SAL 3.32) and 4.20 (SAL 4.20), both IP41 and SHub 1, and `shub1snprom.bin` (SAL 5.04, built
2008-11-11, IP41, SHub 1) and `shub2snprom.bin` (SAL 1.54, built 2008-11-11, IP65, SHub 2; read in [devices/shub/shub2.md](../../../devices/shub/shub2.md)) from snprom 10.54. The SAL 5.04 image is the newest SHub 1
build held and is the one SGI's own `README.snprom` says boots the Altix 350 and both Prism models; its FIT and first
stage are read in [boot-sequence.md](boot-sequence.md). The component tables below are for the first four.

**How an image says which SHub it targets (established).** Three independent places agree in each image. The SAL_A
(first-stage) component starts with a banner string `SGI SAL Version <major>.<minor> rel<yymmdd> IP41|IP65 built ...`;
the 4.43 and 1.11 builds also embed their compiler command line, which defines `CPUBOARD=IP41` with `SHUB1`
(`CONFIG_SHUB`, `CONFIG_NL3R`, `CONFIG_NL4R`, `CONFIG_TIO`) or `CPUBOARD=IP65` with `SHUB2` (`CONFIG_SHUB2`,
`CONFIG_TIO`, `CONFIG_NL4R`). The chip-name strings differ: the IP41 images carry "SHub 1.1", "SHub 1.2", "SHub 1.x"
and "NL3Router"; the IP65 images carry "SHub 2.0" and only "NL4Router". And the code differs: the SHub 1 SAL_A touches
the register space at `0x81_xxxx_xxxx` (the SHub 1 local window), the SHub 2 SAL_A at `0x2_xxxx_xxxx`
([address map](../../../platforms/sn2/address-map.md)). `SN_SAL_GET_SN_INFO` reports chip 0 in the IP41 images and
chip 1 in the IP65 images (read in full in `shub2snprom.bin`; see below).

**What `ip65prom.bin` is (established for the identity, inferred for the history).** Package snprom-10.11 ships one
file, `ip65prom.bin`: SAL 1.11 for IP65 with SHub 2.0, built 2006-10-18, with the compiler command line still in the
image (`BRINGUP` and `MONTECITO_PWR_CYCLE_WAR` among its defines, so it is an early build for Montecito-era SHub 2
nodes). It is the same product line as `shub2snprom.bin` (the SHub 2 half of package 10.40, SAL 1.40, 14 months
later): same module set, the SAL runtime and EFI components are different builds, and it still has two SAL calls
(PCI configuration read and write, ids `0x02000047` and `0x02000048`) that the 1.40 build dropped. Package 10.40 puts one
file per SHub generation under `efi/sgi/snprom/`; 10.11 and 4.43 carry a single file. The SAL version series differ by
generation: 4.x for the SHub 1 PROM, 1.x for the SHub 2 PROM.

## Image layout

### Fixed addresses at the top of the image (established)

Every image has the same layout in its final 32 bytes. `0xFFFFFFE0` holds `0x80000000_<start of file>`, the address of the Firmware
Interface Table (FIT), which is at the start of the file (signature `_FIT_   ` at file offset 0).
`0xFFFFFFE8` holds `0x80000000_<SAL_A address>`, the first-stage SAL entry (the SAL_A component in the FIT; bit 63 is
set in both). The last 16 bytes (`0xFFFFFFF0`) are byte-identical in all four images and look like an x86 reset vector (a far
jump followed by a date string "11/02/99" and a model byte). What reads them, if anything, is unknown.

### The FIT (established)

The table has 16-byte entries: address (8 bytes), length in 16-byte units (3 bytes), reserved, version (2 bytes: major
in the high byte, minor in the low byte, as hex digits, so 0x0443 prints as 4.43), type (low 7 bits; bit 7 is "a
checksum is valid") and a checksum byte. The first entry is the header (its length field is the entry count). The SN2
kernel's PROM-information code names the types it knows: 0x01 PAL_B, 0x0e processor-specific PAL_A, 0x10 SAL_A, 0x11
SAL_B, 0x12 SAL runtime, 0x1f EFI. The other types the images use (0x13, 0x22, 0x23) are vendor types the kernel
labels "OEM type".

### snprom.bin (6291456 bytes, mapped at 0xffa00000)

| # | Type | Version | Address | Offset | Length | Checksum flag | Form |
|---|---|---|---|---|---|---|---|
| 1 | 0x01 PAL_B | 7.79 | 0xffda0000 | 0x3a0000 | 0xa8dc0 | 0 | raw |
| 2 | 0x01 PAL_B | 5.73 | 0xffe50000 | 0x450000 | 0xaa140 | 0 | raw |
| 3 | 0x01 PAL_B | 2.15 | 0xfff00000 | 0x500000 | 0x9afc0 | 0 | raw |
| 4 | 0x0e processor-specific PAL_A | 7.31 | 0xfff9afc0 | 0x59afc0 | 0x6b00 | 1 | raw |
| 5 | 0x0e processor-specific PAL_A | 5.37 | 0xfffa1ac0 | 0x5a1ac0 | 0x67c0 | 1 | raw |
| 6 | 0x0e processor-specific PAL_A | 1.27 | 0xfffa8280 | 0x5a8280 | 0x6ce0 | 1 | raw |
| 7 | 0x10 SAL_A | 4.43 | 0xffc1b000 | 0x21b000 | 0x6060 | 1 | raw |
| 8 | 0x11 SAL_B | 4.43 | 0xffa01000 | 0x001000 | 0x219160 | 1 | raw |
| 9 | 0x12 SAL runtime | 4.43 | 0xffc21060 | 0x221060 | 0x44280 | 1 | gzip, 1061808 bytes expanded (IA-64 ELF) |
| 10 | 0x1f EFI | 0.01 | 0xffc652e0 | 0x2652e0 | 0xe4750 | 1 | gzip, 3452088 bytes expanded (IA-64 ELF) |
| 11 | 0x22 OEM 0x22 | 1.01 | 0xffd49a30 | 0x349a30 | 0x53fb0 | 1 | gzip, 829440 bytes expanded (tar of EFI drivers) |

### shub1snprom.bin (6291456 bytes, mapped at 0xffa00000)

| # | Type | Version | Address | Offset | Length | Checksum flag | Form |
|---|---|---|---|---|---|---|---|
| 1 | 0x01 PAL_B | 7.79 | 0xffdc8000 | 0x3c8000 | 0xa8dc0 | 0 | raw |
| 2 | 0x01 PAL_B | 5.73 | 0xffe78000 | 0x478000 | 0xaa140 | 0 | raw |
| 3 | 0x01 PAL_B | 2.25 | 0xfff28000 | 0x528000 | 0x9afc0 | 0 | raw |
| 4 | 0x0e processor-specific PAL_A | 7.31 | 0xfffc2fc0 | 0x5c2fc0 | 0x6b00 | 1 | raw |
| 5 | 0x0e processor-specific PAL_A | 5.37 | 0xfffc9ac0 | 0x5c9ac0 | 0x67c0 | 1 | raw |
| 6 | 0x0e processor-specific PAL_A | 1.27 | 0xfffd0280 | 0x5d0280 | 0x6ce0 | 1 | raw |
| 7 | 0x10 SAL_A | 4.90 | 0xffc50000 | 0x250000 | 0x4000 | 1 | raw |
| 8 | 0x11 SAL_B | 4.90 | 0xffa01000 | 0x001000 | 0x24e150 | 1 | raw |
| 9 | 0x12 SAL runtime | 4.90 | 0xffc54000 | 0x254000 | 0x3d320 | 1 | gzip, 918824 bytes expanded (IA-64 ELF) |
| 10 | 0x13 OEM 0x13 | 0.01 | 0xffc91320 | 0x291320 | 0x16ab0 | 1 | gzip, 619440 bytes expanded (IA-64 ELF) |
| 11 | 0x1f EFI | 0.01 | 0xffca7dd0 | 0x2a7dd0 | 0xc24a0 | 1 | gzip, 2495544 bytes expanded (IA-64 ELF) |
| 12 | 0x22 OEM 0x22 | 1.01 | 0xffd6a270 | 0x36a270 | 0x58450 | 1 | gzip, 860160 bytes expanded (tar of EFI drivers) |
| 13 | 0x23 OEM 0x23 | 4.90 | 0xffdc26c0 | 0x3c26c0 | 0x2a0 | 1 | ELF relocatable |

### shub2snprom.bin (12582912 bytes, mapped at 0xff400000)

| # | Type | Version | Address | Offset | Length | Checksum flag | Form |
|---|---|---|---|---|---|---|---|
| 1 | 0x01 PAL_B | 5.73 | 0xff7f0000 | 0x3f0000 | 0xaa140 | 0 | raw |
| 2 | 0x01 PAL_B | 2.25 | 0xff8a0000 | 0x4a0000 | 0x9afc0 | 0 | raw |
| 3 | 0x01 PAL_B | 9.20 | 0xff940000 | 0x540000 | 0xc5af0 | 0 | raw |
| 4 | 0x01 PAL_B | 1.08 | 0xffa08000 | 0x608000 | 0xc8a20 | 0 | raw |
| 5 | 0x0e processor-specific PAL_A | 5.37 | 0xffad0a20 | 0x6d0a20 | 0x67c0 | 1 | raw |
| 6 | 0x0e processor-specific PAL_A | 1.27 | 0xffad71e0 | 0x6d71e0 | 0x6ce0 | 1 | raw |
| 7 | 0x0e processor-specific PAL_A | 7.46 | 0xffaddec0 | 0x6ddec0 | 0xb310 | 1 | raw |
| 8 | 0x0e processor-specific PAL_A | 1.08 | 0xffae91d0 | 0x6e91d0 | 0xc060 | 1 | raw |
| 9 | 0x10 SAL_A | 1.40 | 0xff67c000 | 0x27c000 | 0x3000 | 1 | raw |
| 10 | 0x11 SAL_B | 1.40 | 0xff401000 | 0x001000 | 0x27a730 | 1 | raw |
| 11 | 0x12 SAL runtime | 1.40 | 0xff67f000 | 0x27f000 | 0x3f9b0 | 1 | gzip, 992088 bytes expanded (IA-64 ELF) |
| 12 | 0x13 OEM 0x13 | 0.01 | 0xff6be9b0 | 0x2be9b0 | 0x16ac0 | 1 | gzip, 619440 bytes expanded (IA-64 ELF) |
| 13 | 0x1f EFI | 0.01 | 0xff6d5470 | 0x2d5470 | 0xbf5a0 | 1 | gzip, 2458680 bytes expanded (IA-64 ELF) |
| 14 | 0x22 OEM 0x22 | 1.01 | 0xff794a10 | 0x394a10 | 0x58450 | 1 | gzip, 860160 bytes expanded (tar of EFI drivers) |
| 15 | 0x23 OEM 0x23 | 1.40 | 0xff7ece60 | 0x3ece60 | 0x2a0 | 1 | ELF relocatable |

### ip65prom.bin (12582912 bytes, mapped at 0xff400000)

| # | Type | Version | Address | Offset | Length | Checksum flag | Form |
|---|---|---|---|---|---|---|---|
| 1 | 0x01 PAL_B | 7.79 | 0xff7d8000 | 0x3d8000 | 0xa8dc0 | 0 | raw |
| 2 | 0x01 PAL_B | 5.73 | 0xff888000 | 0x488000 | 0xaa140 | 0 | raw |
| 3 | 0x01 PAL_B | 2.15 | 0xff938000 | 0x538000 | 0x9afc0 | 0 | raw |
| 4 | 0x01 PAL_B | 8.30 | 0xff9d8000 | 0x5d8000 | 0xc4530 | 0 | raw |
| 5 | 0x0e processor-specific PAL_A | 7.31 | 0xffa9c530 | 0x69c530 | 0x6b00 | 1 | raw |
| 6 | 0x0e processor-specific PAL_A | 5.37 | 0xffaa3030 | 0x6a3030 | 0x67c0 | 1 | raw |
| 7 | 0x0e processor-specific PAL_A | 1.27 | 0xffaa97f0 | 0x6a97f0 | 0x6ce0 | 1 | raw |
| 8 | 0x0e processor-specific PAL_A | 7.46 | 0xffab04d0 | 0x6b04d0 | 0xb310 | 1 | raw |
| 9 | 0x10 SAL_A | 1.11 | 0xff658000 | 0x258000 | 0x3000 | 1 | raw |
| 10 | 0x11 SAL_B | 1.11 | 0xff401000 | 0x001000 | 0x256a40 | 1 | raw |
| 11 | 0x12 SAL runtime | 1.11 | 0xff65b000 | 0x25b000 | 0x44ae0 | 1 | gzip, 1104488 bytes expanded (IA-64 ELF) |
| 12 | 0x1f EFI | 0.01 | 0xff69fae0 | 0x29fae0 | 0xdc380 | 1 | gzip, 3257400 bytes expanded (IA-64 ELF) |
| 13 | 0x22 OEM 0x22 | 1.01 | 0xff77be60 | 0x37be60 | 0x58450 | 1 | gzip, 860160 bytes expanded (tar of EFI drivers) |

**What each component is.**

- **PAL_B (0x01), PAL_A (0x0e)**: processor abstraction layer, one pair per supported processor stepping range. PAL_B
  is code (raw, no checksum flag). PAL_A entries have a valid checksum flag and look like opaque data (not decoded here). SAL_A selects the pair by processor identity: it reads `cpuid[3]` and
  walks a table inside SAL_A. In both SHub 2 images the table has keys for processor family 0x1f (models 0, 1 and 2,
  the Itanium 2 line, revisions 4 to 7, 5 and 1 to 2) and family 0x20 (the Montecito line), fifteen steppings in the
  1.40 image and thirteen in 1.11 (established as table contents; the marketing names are inferred from Intel's CPUID
  numbering, which is not in the image). Each row also holds the minimum PAL_A and PAL_B version the SAL wants (the
  strings "Minimum PAL A" and "Current PAL A" show them are checked and printed). In the SHub 1 images SAL_A holds two tables.
  The first has three rows keyed by `cpuid[3] & 0xffffff0000` (family 0x1f, models 0, 1 and 2). The second, keyed by the exact
  `cpuid[3]` and holding the version windows, is at `0xffc51000` in SAL_A 5.04 (a copy at `0xffbe0a08` in SAL_B) and has 15 rows
  of `0x60` bytes: seven with family 0x1f (Itanium 2 models 0, 1 and 2) and eight with family 0x20 (established, from the
  review of [boot-sequence.md](boot-sequence.md); [images.md](images.md) lists the keys).
- **SAL_A (0x10)**: 12 KiB (SHub 2) to 24 KiB (4.43). First-stage code that runs straight out of flash with no memory
  and no stack. Walked through below.
- **SAL_B (0x11)**: 2.1 to 2.6 MiB of IA-64 code, linked to run in place from flash at `0xffa01000` or `0xff401000`
  (the first page of the file after the FIT). It is a self-contained physical-mode image: the whole PROM (chipset
  initialisation, memory, system-controller link, error handling, all SAL entry points in physical mode, the PROM's
  own console) is in it. Its first three bundles are branches: reset entry (offset 0), then two more entries (offsets
  0x10 and 0x20) that SAL_A selects by the reason code PAL hands over. Strings in it include "Prom starting...",
  "Copying PROM to RAM", "PROM is being flashed" and "Jumping to next segment (EFI or IOprom)".
- **SAL runtime (0x12)**: gzip, expands to an IA-64 ELF shared object (type DYN, entry point 0x3000 in the 4.43 image,
  which is `salruntime_entry`). It carries a dynamic symbol table with 1100 to 1300 names (C function names such as
  `chipset_*`, `memctl_*`, `sysctl_*`, `l1sc_*`, `sal_log_*`, `salruntime_*`), which is what makes the images readable.
  It is the virtual-mode copy of the SAL entry points, relocated into RAM; many of its functions are also in SAL_B (a
  signature match of the first 14 normalised instructions finds 250 of 790 functions of the 1.40 runtime in the 1.40
  SAL_B, inferred).
- **EFI (0x1f)**: gzip, expands to an IA-64 ELF (type DYN, 2.5 to 3.5 MiB): an EFI 1.10 firmware built from the Intel
  sample framework, with SGI additions (an Altix PCI root bridge, an IOC4 ATA/ATAPI pass-through, SGI system-controller
  console, SATA, USB, the shell and boot manager, a BIOS emulator interface for option-ROM video). Symbols include
  `AltixRootBridgeIo*`, `Ioc4AtapiPassThru*`, `InitializeAltixPciRootBridge`, `SalProc` and `RtSalCallBack`.
- **0x13 (SHub 1 4.90 and SHub 2 1.40 only)**: gzip, expands to an IA-64 ELF with an x86 instruction emulator (the
  symbols are `X86EMU_*` and `Int10*`, `PciConfigSpaceRW`): it runs PC option-ROM code for a VGA card. Role inferred
  from the symbols.
- **0x22**: gzip, expands to a tar archive of three EFI drivers: `drv_fpswa.efi` (the floating-point software assist,
  needed by IA-64 operating systems), `drv_lsisas.efi` (an LSI SAS driver) and `drv_b57undi64.efi` (a Broadcom NIC
  UNDI driver). Member names and sizes are established.
- **0x23 (4.90 and 1.40 only)**: 672 bytes, an empty IA-64 relocatable ELF (no code, no data). Its role is unknown.
  The SAL runtime has a function named `main_verify_elf_signature`, which suggests an image-signature or
  placeholder slot; not established.

## Product compatibility: what the images name

The images do not carry a product catalogue. They name **CPU board classes**, **brick types** and **chips**, and select
by what the hardware reports.

- **CPU board name (established):** `IP41` in the 4.43 and 4.90 images, `IP65` in the 1.11 and 1.40 images, as the
  string, the SAL banner and the build definition. No other `IPnn` appears in any of the eight snprom images in the root: `IP57`,
  the node board the Altix 350 guide names ([altix-350](../../../platforms/sn2/altix-350.md)), is in none of them, nor
  in `README.snprom`. Which product each image serves is stated by SGI's `README.snprom` (package 10.54, below), not by
  the images: `shub1snprom.bin` supports the Altix 330, 350, 3300, 3700, 3700 Bx2 and both Prism models,
  `shub2snprom.bin` the Altix 4700 and 450 (established as SGI's statement of intent; see
  [evidence/sn2-holdings.md](../../../evidence/sn2-holdings.md#system-firmware)). So the SHub 1 image's `IP41` is a
  build target covering boards the string does not name, and how it tells an IP57 from an IP41 at run time is a
  question for [boot-sequence.md](boot-sequence.md). The SAL_B of all four also
  contains a literal board identity string `Part:030-1604-001;Name:IP41;...` and an `IBRICK` one (a built-in default
  or test record; used when EEPROM info is missing, inferred from the "Could not retrieve EEPROM info" messages next
  to it).
- **Brick types (established as strings, inferred as products):** the klconfig dump code lists these board types:
  compute `IP41`, `TIO`, `Baseio`, `Router`, `MetaRouter`, `RepeaterRouter`, `IObrick`, `Weirdio`, `Opus15brick`,
  `Opus25brick` (not in 4.43), `Extendedbrick`, `Athenabrick`, `PXbrick`, `IXbrick`, `CGbrick`, `Opusbrick`,
  `SAbrick`, `IAbrick`, `PAbrick`, `GAbrick`, `OpusTiobrick`, `Doradobrick`. The same names with codes are the kernel's
  `KLTYPE_*` list (`klconfig.h`, v5.3). `OpusTiobrick`, `Opus*` and `Athena` are SGI code names; the mapping to Altix
  350, 450, 3000, 3700, 4700, Prism is not written in the images.
- **Chips (established):** SHub 1.1, 1.2, 1.x and TIO 1.x in the IP41 images; SHub 2.0 and TIO 1.x in the IP65
  images; NUMAlink 3 router (IP41 images only) and NUMAlink 4 router. TIO children: `TIO CA`, `TIO CX`, PIC, IOC3,
  IOC4, "Tigon3 GigE", QLogic Fibre Channel, 1394, USB, SCSI, "PCI Graphics Processor", "VGA Graphics Processor".
  Register-name tables for TIOCE ("CE_xxxx"), PIC ("PIC_xxxx") and SHub 2 ("SH2_...") are in SAL_B, used by the error
  decoder; they are a source for stream B and for the SHub 2 register names.
- **Processors (established as a table, see PAL above):** Itanium 2 family 0x1f and Montecito family 0x20 steppings
  in the IP65 images' first-stage table.
- **SHub 2 has no XIO (established string "SHUB2 does not support XIO I/O.")**: SHub 2 nodes reach I/O only through
  TIO or the NUMAlink fabric.

## Which image to boot first

**Recommendation for an Altix 350 or Prism model: `shub1snprom.bin`, SAL 5.04, package snprom-10.54-70399, sha256
`51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617`.** Reasons:

1. SGI's `README.snprom` (shipped in the snprom package from 10.20; the 10.54 copy is held) says `shub1snprom.bin`
   supports the Altix 330, 350, 3300, 3700, 3700 Bx2, Prism Rackmount and Prism Deskside, and `shub2snprom.bin` the
   Altix 4700 and 450. That is the vendor's statement of intent (established as such; that this exact image boots a
   given machine has not been shown by running it). The [Altix 350 page](../../../platforms/sn2/altix-350.md)
   leaves the SHub generation of its IP57 board unknown; `README.snprom` puts the machine on the SHub 1 image, so the
   Altix 350 is a SHub 1 machine (inferred from that statement and the SHub 2 image's "no XIO" string).
2. It is the newest SHub 1 build held (2008-11-11) and the last of its line in the root.
3. Its first stage was read in full ([boot-sequence.md](boot-sequence.md)).

**What this does not settle.** The SHub 2 images (`shub2snprom.bin`, `ip65prom.bin`) are for the Altix 4700 and 450 and
are not a candidate for a one-node Altix 350 or Prism: the 1.40 image says "SHUB2 does not support XIO I/O.", and the
Altix 350's I/O is a PIC on an XIO link from the SHub ([altix-350](../../../platforms/sn2/altix-350.md)). An
earlier version of this page recommended `shub2snprom.bin` before `README.snprom` was in hand; that reading is
withdrawn. The SHub 2 images stay documented here because the SHub 2 first stage is read in full and the Altix 4700 and
450 are later targets.

Fallbacks, in order: `shub1snprom.bin` from snprom 10.40 (SAL 4.90, sha256
`26170cc83c3db243601da8f55610bcdd6bb408136c3b3d19b7c4823e491b9a06`), the previous build of the same line; then
`snprom.bin` from snprom 4.43 (SAL 4.43, sha256 `035274812b5065bde3f1b3227a23c05637d8a13f7cab7736ddde4718d46f02eb`), which
predates `README.snprom` and lacks `SN_SAL_BTE_RECOVER` and the feature-set calls.

**Images that would help (requested, not required to start):** a package whose notes or strings name IP57, if one
exists (3.32, 4.20 and 10.54 do not), and any package naming a Prism board.

## Entry and initialisation order

What is read in full is the first stage; later stages are bounded by call lists and symbol names (inferred). SAL_B
function names below come from matching normalised instruction sequences against the symbolised SAL runtime, so they
are inferred, not read from SAL_B.

1. **Processor reset to PAL_A to SAL_A (established for the pointers).** The reset path ends in SAL_A at the address
   stored at `0xFFFFFFE8`. SAL_A receives a reason code in the low byte of `r20`. Reasons 0 and 3 run the first-stage
   initialisation below, reasons 1 and 2 skip it and go to the FIT scan, and any reason above 3 hangs with progress code
   177. The meaning of each reason is not in the image (reason 3 is the one that picks the PAL pair and returns to PAL,
   reason 0 the one that goes on to SAL_B, from what each does).
2. **SAL_A, SHub 2 build (1.40, `0xff67c000`), read in full (established; the 1.11 build touches the same registers, constants compared).**
   It needs no memory, no L1 controller, no I2C and no PCI. The words PAL hands over in `r33` to `r37` are used but
   not defined in the image. For reasons 0 and 3, in this order:
   - **PSR and PAL call (the PSR step for both reasons, the rest for reason 3 only).** Sets PSR bit 24 (`psr.db`). For
     reason 3 only: reads `0x2_1003_8200` and tests bit 39 (the register is in the SHub 2 junk-bus block; the same offset
     is the "simulation data" window of the system-controller link code, below); if the bit is set and bit 3 of `r33`
     is also set it spins forever, otherwise it makes one static PAL call with index 528 (the implementation-specific
     static range) and argument 1, or 5 when bit 39 was set. What that PAL call does is unknown.
   - **Node identity.** Writes `0xffffffff0003` to SHub 2 MMR `0x2_1002_0000`; reads V from `0x2_2011_0000` (the
     register the PROM reads before any other) as an index into a table in SAL_A and writes the 32-bit table entry,
     with bit 63 set, to `0x2_101d_0c00`, the register the PROM later reads as its NASID. Register names unknown; the
     table is in the image.
   - **Error path.** If bit 2 of `r35` is set and the low two bits of `r35` are not zero: writes progress code 176,
     clears bits 29:26 of `0x2_101d_0300`, ORs `0x280_0000_0000` (bits 41 and 39) into `0x2_101d_0080`, writes
     `0x1_0001_0000_0000` to `0x2_2000_0000`, and spins at a code address with bit 63 clear. What `r35` carries is
     not in the image (inferred: a PAL-reported fault).
   - **Reason sanity.** Byte 1 of `r20` must be 0 or 7; anything else is the fatal hang with progress code 178.
   - **Reason 3 ends here.** Selects the PAL pair: reads `cpuid[3]`, masks it to architecture revision, family and model,
     looks the row up in a table in SAL_A, then walks a second table keyed by the full `cpuid[3]` value that
     carries version limits (the "Minimum PAL A" strings show they are checked); ORs a field of the chosen row (shifted right 16) into `r37` and returns to PAL through `b6 = r36`. No more
     register writes. The pair is therefore chosen only on reason 3 and after the identity writes above, not first.
   - **Reason 0 only, the processor-location word.** Saves PAL's `r33` to `r37` and `r20` in the bank-0 registers
     (`r16` to `r22`). Reads `0x2_2011_0010`; when it reads 0 takes bits 2:1 of `r33`, otherwise bits 3:2, swaps the
     two bits and writes them to bits 24:23 of `cr.lid`. This is the read the earlier version of this page missed.
   - **Reason 0 only, the local master election.** Each processor writes its slice number plus one (slice is
     `cr.lid` bits 25:23) to `0x2_101d_0088` and reads `0x2_101d_0080`. The processor whose value reads back equal is
     the winner (the first-writer-wins reading is inferred from the store-then-compare shape; the reset value of
     `0x2_101d_0080` is not known). Only the winner then zeroes `0x2_101d_0300`, `0x2_101d_0280` and `0x2_101d_0380`
     (the firmware flag, an unnamed one and the DIP-switch register of the chipset code), writes `2` to `0x2_0001_00d8`,
     writes `1` to `SH2_IPI_ACCESS0` (`0x2_1006_0c00`) and `0` to `SH2_IPI_ACCESS1..3` (`0x2_1006_0c80`, `0d00`,
     `0d80`). Then (the same winner, not the losers as an earlier version said) it reads `0x2_101d_0080` again, finds
     its own slice plus one and sets bits 41:39 of `0x2_101d_0100` to 7, meaning unknown. Processors that lose do
     neither and fall through to the FIT scan.
   - **FIT scan and hand-off, reasons 0, 1 and 2.** Finds SAL_B through the FIT (checking `_FIT_   `, requiring a type 0
     header, walking entries until type 0x11, hanging with 178 if it fails), writes the progress code 48, 56 or 59 for
     reason 0, 1 or 2 (a halfword at `0x2_f000_0000 + (slice << 16)`). Before the progress write, reasons 1 and 2 (and a
     reason above 3, which hangs with 177) read `[0x2_1003_0000 + slice*128]` into `r31`; reason 0 does not, its branch at
     `0xff67c3ec` skipping the load at `0xff67c460`. SAL_A branches to SAL_B offset 0, 0x20 or 0x10 for reason 0, 1 or 2.
   - **Progress codes in SAL_A, complete (established).** 48, 56 and 59 (hand-off for reasons 0, 1, 2), 176 (the error
     path), 177 (reason above 3: spin) and 178 (fatal hang: bad `r20` byte 1, FIT not found). SAL_B writes 179 and 49,
     53, 180 later. Nothing in SAL_A reads these stores back.
3. **SAL_B reset entry (`0xff42fbb0` in 1.40; established for the first 100 instructions).** Writes progress codes,
   sets `gp`, makes six calls (not named, the first runs before RAM is needed) then reads PROM data at **physical RAM**
   `0x1000010`, `0x1000038` and `0x1000000` (a per-processor table at 16 MiB, so DRAM must be initialised and sized by
   then), sets the stack and backing store from it, installs the interruption vector table at `0xff5c0000` (flash),
   calls what is probably `main()` (`0xff42b740`) and ends in a progress-code hang (180) if it returns.
4. **System controller (L1/L2/L3) link (inferred from symbol names and constants).** The PROM talks to the L1 through a
   UART block in the SHub 2 (`sc_shub2_*`; MMR `0x1003_8000`), the TIO (`sc_tio_*`; `0x9003_8000` in the TIO's own
   space) or a NUMAlink 4 router (`sc_nl4r_*`), and builds queries on it (`sysctl_*`): max nodes, sharing mode,
   rack/bay/slab/slot of each brick, CPU presence, module ids, serial numbers, time of day, console. The boot path uses
   them from `main_early_disable` on (CPU presence and an environment lookup). An unreachable controller is reported
   ("System controller communication init failed"; "Critical system controller transaction failed"); whether boot
   stalls or continues is **unknown** (the failing path is in SAL_B, not traced).
5. **`sysctl_probe` and the simulator signature (the function bodies are established, what the callers do with the
   result is inferred).** Every build compares `cpuid[2]` with `0xaeeeeeee8badbeef`; equal returns 0. What differs is
   the other case. SAL 1.11, 1.40, 4.90 and 5.04 return 1 without touching hardware. SAL 3.32 and 4.20 call
   `sysctl_version` once and return 1 only if it succeeds. SAL 4.43 really probes: it retries `sysctl_version` while it
   answers -30, until 2,000,000 ticks of `chipset_rtc_time` have passed, and returns 1 only if the call succeeds,
   otherwise 0 (so on 4.43 a missing controller reads the same as the simulator). The system-controller link has
   `*_sim_data` routines that build the rack, bay, node and slab fields from a SHub register block (offset
   `0x1003_8200`, read with the fabric vector accessor) instead of talking to hardware. This is the likely route SGI's
   own simulator used; the kernel's `SN_SAL_FAKE_PROM` call and a `CONFIG_IA64_SGI_SN_SIM` kernel option point the same
   way. The skip applies only when the processor reports that CPUID signature.
6. **Memory (inferred).** Names: `memctl_get_bank_sizes`, `memctl_memory_present`, `run_mbist`,
   `load_and_arm_fill_bist_mmrs`, `mdir_create_presence_vec`, a warning about "tRCD ... SHUB max of 4" and "SHUB min of
   2". DIMM data comes through the SHub's own registers (the `memctl_*` functions use only `chipset_load_mmr`), so the
   minimum is a memory controller that answers its bank registers and a memory built-in self test that completes.
   Exact register accesses unknown. No I2C or SPD name appears among the symbols; the sizing may use the SHub's SPD
   reader.
7. **NVRAM and flash (inferred):** `cfi_probe`, `cfi_erase_sector` and friends exist in the runtime (CFI flash command
   set); the EFI image calls SN SAL id `0x02000008` for variable store. The PROM log (`promlog_*`) lives in flash.
8. **Console (inferred):** the PROM console is chosen by `console_probe` among the system controller console
   (`sc_cons_*`, the default), a direct SHub UART (`direct_*`) and the EFI callback console; the kernel's `ttySG`
   console is SAL calls `0x02000021` to `0x0200002c`.
9. **Other nodes, routers (inferred):** `intcon_*` (interconnect), `nl4r_*`, `sc_nl4r_*`, `chipset_node_barrier`,
   `chipset_arbitrate_lmaster`: multi-node boot has a node-barrier protocol over per-node flag registers; a single
   node with no router skips it (the one-module Altix 350 case; not verified by running).

**What the firmware needs to reach EFI (summary, SHub 2 build; the SHub 1 Altix 350 version is in
[boot-sequence.md](boot-sequence.md)):** the SHub identification and node-identity registers, the
SAL_A registers above (the code needs the writes accepted, nothing read back), DRAM at physical `0x1000000` with working sizing, a CFI-compatible
flash or an error the PROM tolerates, an L1 (or the simulator escape), one working console path. PIC, TIO and IOC4
are read for I/O (EFI's console is the system controller or a serial UART in an IOC4), not for reaching the PROM
prompt. Everything beyond SAL_A is a **reading** and has not been run.

## SHub registers the first stage writes (SHub 2 SAL_A, established)

Offsets are the SHub 2 local-window addresses the code uses (`0x2_0000_0000 + offset`; bit 63 set means uncached).
A read after the PROM ran is not a reset value; these are the PROM's accesses, in program order for reason 0 (the
ordered account is the first-stage walk above).

| Address | Access in SAL_A | Value | Name |
|---|---|---|---|
| `0x2_1003_8200` | read (reason 3 only) | bit 39 tested | junk-bus block; unnamed |
| `0x2_1002_0000` | write | `0xffffffff0003` | unnamed |
| `0x2_2011_0000` | read | V, a small node-configuration value | unnamed; the same register sets the NASID width and shift that `SN_SAL_GET_SN_INFO` reports |
| `0x2_101d_0c00` | write | table entry for that identity | read back by the PROM as its NASID; unnamed |
| `0x2_2011_0010` | read (reason 0) | selects which bits of `r33` become `cr.lid` bits 24:23 | unnamed |
| `0x2_101d_0088` | write | slice number + 1 | unnamed |
| `0x2_101d_0080` | read, twice | compared with slice + 1 | unnamed |
| `0x2_101d_0300` | write on the election winner | 0 | firmware flag register (`chipset_flag_*`); unnamed |
| `0x2_101d_0280` | write on the election winner | 0 | unnamed |
| `0x2_101d_0380` | write on the election winner | 0 | DIP-switch register (`chipset_dipsw_*`); unnamed |
| `0x2_0001_00d8` | write on the election winner | 2 | unnamed |
| `0x2_1006_0c00` | write on the election winner | 1 | `SH2_IPI_ACCESS0` (kernel header) |
| `0x2_1006_0c80`, `0d00`, `0d80` | write on the election winner | 0 | `SH2_IPI_ACCESS1..3` (kernel header) |
| `0x2_101d_0100` | read-modify-write on the election winner | bits 41:39 = 7 | unnamed |
| `0x2_1003_0000 + slice*128` | read (reasons 1, 2 and above 3 only, not reason 0) | passed to SAL_B in `r31` | unnamed |
| `0x2_f000_0000 + slice<<16` | write (16-bit) | progress codes 48, 56, 59, 176, 177, 178 | unnamed |
| `0x2_101d_0300` | read-modify-write, error path only | bits 29:26 cleared | as above |
| `0x2_101d_0080` | read-modify-write, error path only | `\|= 0x280_0000_0000` | as above |
| `0x2_2000_0000` | write, error path only | `0x1_0001_0000_0000` | unnamed |

For SHub 1 (`snprom.bin`, `shub1snprom.bin`) the SAL_A constants are the `0x81_xxxx_xxxx` forms: `0x81_1002_0000`,
`0x81_101d_0080`, `0x81_101d_0088`, `0x81_101d_0100`, `0x81_1006_0480` (`SH1_IPI_ACCESS` in the kernel header),
`0x81_2001_0100`, `0x81_5003_1500` to `0x81_5003_1560`, and the window `0x87_fed0_0000` to `0x87_fed3_0000`; the constants in the 4.43 and 4.90 builds were listed
from the instructions only (**inferred**). The SAL 5.04 SHub 1 first stage has since been read in full, in order, in
[boot-sequence.md](boot-sequence.md#sal_a-on-shub-1), which supersedes this list for that build.

Further SHub 2 locations the symbolised code uses, with what the PROM does at each (inferred from function names and
the constants in them): `0x2_1006_0f00` and `0x2_101d_0c00` (read for the node's NASID, `chipset_get_nasid`),
`0x2_2011_0008` (written by `chipset_remap_firmware`, with `0x1_ff00_0000`), `0x10038000` (system-controller UART
registers, written by `sc_shub2_init` with `0x1_8000_0000` and others), `0x101d_0300` (firmware flag register read by
`shub2_flag_get`). Register names for these are in the PROM's SAL_B error-decoder tables ("SH2_..."); the table
structure was not decoded here.

## SAL dispatch

The PROM answers SAL by function id through two tables. In **virtual mode** the SAL runtime's `salruntime_entry` scans
a table of 16-byte entries (id, flags, handler descriptor) in the ELF's data (`salruntime_functab`, 96 to 106 entries including the terminator and four non-SAL entries),
and runs the handler; for ids whose handler is `salruntime_phys_call`, it switches the processor to physical mode and
calls the physical-mode handler through a pointer found in a table the PROM keeps at physical RAM `0x1000038`. In
**physical mode** SAL_B has an equivalent table of (id, descriptor pointer) pairs (descriptors are code address and
gp). Both tables are established by reading them in full from each of the four images. Ids marked "physical only"
are the ones the runtime table forwards to SAL_B; "runtime and physical" ids have a handler on both sides.

One handler serves many ids: ids `0x02000051` to `0x02000060` and `0x02000064` are cases of a single I/O interface
dispatcher in SAL_B (a switch on `id - 0x02000051`), so they are implemented, not stubs; `0x61`, `0x62` and `0x63` fall
to its default in the 1.40 image (`0x5b` has a case of its own). Unlisted ids (including the SN ids the kernel header defines but the PROM does not,
such as `SN_SAL_WATCHLIST_ALLOC` `0x02000070`, `SN_SAL_FAKE_PROM` `0x02009999`, `SN_SAL_SYSTEM_RESET`
`0x02000002` aside from its table slot) answer `-1` through `salruntime_unimplemented_function_code`.

The first four columns of presence are in the order 4.43, 4.90, 1.40, 1.11.

| Id | Name | PROM function | Handled in | 4.43 4.90 1.40 1.11 |
|---|---|---|---|---|
| `01000000` | SAL_SET_VECTORS | `set_vectors` | runtime and physical | x x x x |
| `01000001` | SAL_GET_STATE_INFO | `get_state_info` | runtime and physical | x x x x |
| `01000002` | SAL_GET_STATE_INFO_SIZE | `get_state_info_size` | runtime and physical | x x x x |
| `01000003` | SAL_CLEAR_STATE_INFO |  | physical only | x x x x |
| `01000004` | SAL_MC_RENDEZ | `mc_rendez` | runtime and physical | x x x x |
| `01000005` | SAL_MC_SET_PARAMS | `mc_set_params` | runtime and physical | x x x x |
| `01000006` | SAL_REGISTER_PHYSICAL_ADDR | `register_physical_addr` | runtime and physical | x x x x |
| `01000008` | SAL_CACHE_FLUSH | `cache_flush` | runtime and physical | x x x x |
| `01000009` | SAL_CACHE_INIT | `cache_init` | runtime and physical | x x x x |
| `01000010` | SAL_PCI_CONFIG_READ |  | physical only | x x x x |
| `01000011` | SAL_PCI_CONFIG_WRITE |  | physical only | x x x x |
| `01000012` | SAL_FREQ_BASE | `freq_base` | runtime and physical | x x x x |
| `01000013` | SAL_PHYSICAL_ID_INFO | `physical_id_info` | runtime and physical | x x x x |
| `01000020` | SAL_UPDATE_PAL | `update_pal` | runtime and physical | x x x x |
| `02000001` | SN_SAL_POD_MODE |  | physical only | x x x x |
| `02000002` | SN_SAL_SYSTEM_RESET |  | physical only | x x x x |
| `02000003` | SN_SAL_PROBE | `probe` | runtime and physical | x x x x |
| `02000004` | SN_SAL_GET_MASTER_NASID | `get_master_nasid` | runtime and physical | x x x x |
| `02000005` | SN_SAL_GET_KLCONFIG_ADDR |  | physical only | x x x x |
| `02000006` | SN_SAL_LOG_CE | `log_error` | runtime and physical | x x x x |
| `02000007` | SN_SAL_REGISTER_CE | `register_headless` | runtime and physical | x x x x |
| `02000008` | (not named in the kernel header; the EFI image calls it for flash and variable store) |  | physical only | x x x x |
| `02000009` | SN_SAL_GET_PARTITION_ADDR | `partition_addr` | runtime and physical | x x x x |
| `0200000a` | (clock set; EFI image RtSNSetTime) | `clock_phys_call` | runtime and physical | x x x x |
| `0200000b` | (clock get; EFI image RtSNGetTime) | `clock_phys_call` | runtime and physical | x x x x |
| `0200000c` | (machine check entry, salruntime_mca) | `mca` | runtime and physical | x x x x |
| `0200000f` | SN_SAL_XP_ADDR_REGION | `register_xp_region` | runtime and physical | x x x x |
| `02000010` | SN_SAL_NO_FAULT_ZONE_VIRTUAL | `register_no_fault_zone_virtual` | runtime and physical | x x x x |
| `02000011` | SN_SAL_NO_FAULT_ZONE_PHYSICAL | `register_no_fault_zone_physical` | runtime and physical | x x x x |
| `02000012` | SN_SAL_PRINT_ERROR | `print_error` | runtime and physical | x x x x |
| `02000013` | (go virtual; EFI image RtPlSetVirtualAddressMap) | `go_virtual` | runtime and physical | x x x x |
| `02000014` | SN_SAL_REGISTER_PMI_HANDLER | `register_pmi` | runtime and physical | x x x x |
| `02000015` | (SBE log errors) | `sbe_log_errors` | runtime and physical | x x x x |
| `02000016` | (register PIO write region) | `register_piow_region` | runtime and physical | x x x x |
| `02000017` | (unwind info) | `unwind_info` | runtime and physical | x x x x |
| `02000018` | (latency) | `latency` | runtime and physical | x x x x |
| `02000019` | (platform configuration "pcfg" walk, used by the EFI image) | `pcfg` | runtime and physical | x x x x |
| `0200001a` | SN_SAL_SET_ERROR_HANDLING_FEATURES | `set_error_handling_features` | runtime and physical | x x x x |
| `0200001b` | SN_SAL_GET_FIT_COMPT | `get_fit_compt_phys_call` | runtime and physical | x x x x |
| `0200001d` | SN_SAL_GET_SAPIC_INFO | `get_sapic_info` | runtime and physical | x x x x |
| `0200001e` | SN_SAL_GET_SN_INFO | `get_sn_info` | runtime and physical | x x x x |
| `0200001f` | (checksum FIT) | `checksum_fit` | runtime and physical | x x x x |
| `02000021` | SN_SAL_CONSOLE_PUTC | `console_putc` | runtime and physical | x x x x |
| `02000022` | SN_SAL_CONSOLE_GETC | `console_getc` | runtime and physical | x x x x |
| `02000023` | SN_SAL_CONSOLE_PUTS | `console_puts` | runtime and physical | x x x x |
| `02000024` | SN_SAL_CONSOLE_GETS | `console_gets` | runtime and physical | x x x x |
| `02000025` | SN_SAL_CONSOLE_GETS_TIMEOUT | `console_gets_timeout` | runtime and physical | x x x x |
| `02000026` | SN_SAL_CONSOLE_POLL | `console_poll` | runtime and physical | x x x x |
| `02000027` | SN_SAL_CONSOLE_INTR | `console_intr` | runtime and physical | x x x x |
| `02000028` | SN_SAL_CONSOLE_PUTB | `console_putb` | runtime and physical | x x x x |
| `02000029` |  | `console_getb_timeout` | runtime and physical | x x x x |
| `0200002a` | SN_SAL_CONSOLE_XMIT_CHARS | `console_xmit_chars` | runtime and physical | x x x x |
| `0200002b` | SN_SAL_CONSOLE_READC | `console_readc` | runtime and physical | x x x x |
| `0200002c` | (console flush) | `console_flush` | runtime and physical | x x x x |
| `0200002d` | (console callback register) |  | physical only | x x x x |
| `02000030` | SN_SAL_SYSCTL_OP | `sysctl_op` | runtime and physical | x x x x |
| `02000031` | SN_SAL_SYSCTL_MODID_GET | `sysctl_moduleid_get` | runtime and physical | x x x x |
| `02000033` | SN_SAL_SYSCTL_IOBRICK_MODULE_GET | `sysctl_iobrick_module_get` | runtime and physical | x x x x |
| `02000035` | SN_SAL_SYSCTL_IO_PORTSPEED_GET | `sysctl_io_portspeed_get` | runtime and physical | x x x x |
| `02000036` | SN_SAL_SYSCTL_SLAB_GET | `sysctl_slab_get` | runtime and physical | x x x x |
| `02000037` | SN_SAL_BUS_CONFIG | `bus_config` | runtime and physical | x x x x |
| `02000038` | SN_SAL_SYS_SERIAL_GET | `sys_serial_get` | runtime and physical | x x x x |
| `02000039` | SN_SAL_PARTITION_SERIAL_GET | `partition_serial_get` | runtime and physical | x x x x |
| `0200003a` | SN_SAL_SYSCTL_PARTITION_GET | `sysctl_partition_get` | runtime and physical | x x x x |
| `0200003b` | SN_SAL_SYSTEM_POWER_DOWN |  | physical only | x x x x |
| `0200003c` | SN_SAL_GET_MASTER_BASEIO_NASID | `get_master_baseio_nasid` | runtime and physical | x x x x |
| `0200003d` | SN_SAL_COHERENCE | `extend_coherency_domain` | runtime and physical | x x x x |
| `0200003e` | SN_SAL_MEMPROTECT | `change_mem_permissions` | runtime and physical | x x x x |
| `0200003f` | SN_SAL_SYSCTL_FRU_CAPTURE | `sysctl_fru_capture` | runtime and physical | x x x x |
| `02000040` | (sysctl display text) | `sysctl_display_text` | runtime and physical | x x x x |
| `02000041` | (sysctl iobrick slab get) | `sysctl_iobrick_slab_get` | runtime and physical | x x x x |
| `02000042` | SN_SAL_SYSCTL_IOBRICK_PCI_OP | `sysctl_iobrick_pci_op` | runtime and physical | x x x x |
| `02000043` | SN_SAL_IROUTER_OP | `irouter_op` | runtime and physical | x x x x |
| `02000044` | SN_SAL_SYSCTL_EVENT | `sysctl_event` | runtime and physical | x x x x |
| `02000045` | (used by the EFI image start-IO) |  | physical only | x x x x |
| `02000047` | (PCI config read, SHub 1 images only) | `pci_config_read` | runtime and physical | x . . x |
| `02000048` | (PCI config write, SHub 1 images only) | `pci_config_write` | runtime and physical | x . . x |
| `0200004a` | SN_SAL_IOIF_INTERRUPT |  | physical only | x x x x |
| `02000050` | SN_SAL_HWPERF_OP | `hwperf_op` | runtime only | x x x x |
| `02000051` | SN_SAL_IOIF_ERROR_INTERRUPT |  | physical only | x x x x |
| `02000052` | SN_SAL_IOIF_PCI_SAFE |  | physical only | x x x x |
| `02000053` | SN_SAL_IOIF_SLOT_ENABLE |  | physical only | x x x x |
| `02000054` | SN_SAL_IOIF_SLOT_DISABLE |  | physical only | x x x x |
| `02000055` | SN_SAL_IOIF_GET_HUBDEV_INFO |  | physical only | x x x x |
| `02000056` | SN_SAL_IOIF_GET_PCIBUS_INFO |  | physical only | x x x x |
| `02000057` | SN_SAL_IOIF_GET_PCIDEV_INFO |  | physical only | x x x x |
| `02000058` | SN_SAL_IOIF_GET_WIDGET_DMAFLUSH_LIST |  | physical only | x x x x |
| `02000059` | (IOIF dispatcher case) |  | physical only | x x x x |
| `0200005a` | SN_SAL_IOIF_GET_DEVICE_DMAFLUSH_LIST |  | physical only | . x x x |
| `0200005b` | (IOIF dispatcher case) |  | physical only | . x x . |
| `0200005c` | (IOIF dispatcher case) |  | physical only | . x x . |
| `0200005d` | (IOIF dispatcher case; the EFI image calls it in SnSelectVGAConsole) |  | physical only | . x x . |
| `0200005e` | (IOIF dispatcher case) |  | physical only | . x x . |
| `0200005f` | SN_SAL_IOIF_INIT |  | physical only | . x x x |
| `02000060` | SN_SAL_HUB_ERROR_INTERRUPT |  | physical only | x x x x |
| `02000061` | SN_SAL_BTE_RECOVER |  | physical only | . x x x |
| `02000063` | (get error handling features) | `get_error_handling_features` | runtime and physical | x x x x |
| `02000064` | SN_SAL_IOIF_GET_PCI_TOPOLOGY |  | physical only | x x x x |
| `02000065` | SN_SAL_GET_PROM_FEATURE_SET |  | physical only | . x x x |
| `02000066` | SN_SAL_SET_OS_FEATURE_SET |  | physical only | . x x x |
| `02000067` | SN_SAL_INJECT_ERROR |  | physical only | . x x x |
| `02000068` | SN_SAL_SET_CPU_NUMBER | `os_cpu_number` | runtime and physical | . x x x |
| `02000069` | SN_SAL_KERNEL_LAUNCH_EVENT | `kexec` | runtime and physical | . x x . |

Reading of the table (established unless said): the 2.6.5 SN2 kernel (SLES 9 SP3, `System.map` and disassembly) makes
SAL calls with these ids in its text: `0x01` and `0x03`, `0x04` (master nasid), `0x05` (KLCONFIG), `0x06`, `0x12`,
`0x1a`, `0x1b`, `0x1d`, `0x1e`, `0x22`, `0x26`, `0x27`, `0x28`, `0x2a`, `0x2b`, `0x30`, `0x38`, `0x39`, `0x3a`, `0x3b`,
`0x43`, `0x44`, `0x4a`, `0x50`, `0x51` to `0x58`, `0x60`, `0x61`, `0x64`, `0x65` and `0x66`. All of them are in the
10.40 and 10.11 tables; `0x61`, `0x65` and `0x66` (BTE recovery, PROM and OS feature sets) are absent from the 4.43 image, so a 2.6.5 kernel
on that PROM takes the "not implemented" path the SAL README documents. `0x5f` (ACPI I/O init) is in 4.90, 1.40 and
1.11 but the 2.6.5 kernel does not call it; it uses the direct discovery calls `0x55` to `0x58`.

### What the boot-time handlers do (read from the symbolised runtime)

- **`SN_SAL_GET_SN_INFO` (`salruntime_get_sn_info`, read in full in the 4.43 and 1.40 builds; established).** Both
  builds start from the node's NASID and chip record and fill the first return value (bits 7:0 chip, 15:8 log2 of the
  maximum node count, 23:16 log2 of the sharing domain size, 31:24 one byte of the chip record, 39:32 coherency domain
  id, 47:40 region size) and the second (bits 15:0 NASID mask, 23:16 NASID shift). The 4.43 SHub 1 build gives chip 0,
  11 and 9 for the two logs, `NASID / 512` for the domain, the region size from five bits (52:48) of SHub 1 MMR
  `0x81_1006_0580`, and the constant `0x2607ff` (mask 0x7ff, shift 38). The 1.40 SHub 2 build gives chip 1 and computes
  the rest from two registers instead of constants: with V the value read from `0x2_2011_0000`, the maximum-node log2
  is V + 10, the region size is `1 << (X & 7)` with X read from `0x2_0003_0000` (an earlier version took it from V; re-read in the 1.40 function), the mask is `(1 << (V + 10)) - 1` and the shift is `40 - V`; the
  sharing-domain log2 is 9 when bit 54 of `0x2_1006_0f00` is clear and 11 when it is set, and the coherency domain is
  `NASID / 512` or `NASID / 2048` by the same bit. What value V has on hardware is unknown, so the numbers the
  kernel sees on a real SHub 2 are not known from this reading; they depend on those two registers.
- **`SN_SAL_GET_SAPIC_INFO` (`salruntime_get_sapic_info`, read in full; established).** Pure arithmetic on the SAPIC
  id argument, no register access: returns NASID (an even number built from the id's bits 6:0 and the bits above 9,
  doubled), subnode 0 and slice (id bits 9:7).
- **`SN_SAL_GET_KLCONFIG_ADDR` (`salruntime_klconfig_addr`; inferred).** Initialises the chip record for the given
  NASID, handles memory-less nodes, computes the node-local view of the physical address from the table at
  `0x1000038`, converts with `main_ptov` and adds `0x10000`, so KLCONFIG sits 64 KiB into a PROM-reserved block
  of the node's memory.
- **`SAL_FREQ_BASE` (`salruntime_freq_base`), `GET_MASTER_NASID`, `SYS_SERIAL_GET`, console calls and `HWPERF_OP`:**
  not read in full; names and sizes only (unknown for behaviour).

## EFI, SAL and ACPI tables the PROM builds for the kernel

What the 2.6.5 SN2 kernel looks for (`efi_init`, `ia64_sal_init`, `acpi_boot_init`, `sn_setup` are in its
`System.map`; `CONFIG_ACPI`, `CONFIG_EFI`, `CONFIG_IA64_SGI_SN2` are set in its config) and what the images carry:

- **SAL system table (established that the PROM builds one, by its template).** SAL_B holds the constants used to
  build it: signature `SST_`, OEM id `SGI`, product id `SN2`, followed by the diagnostic "SAL system table at 0x...".
  The SAL_A and SAL_B version words are the FIT versions (SAL_A "sal_a_rev" 4.43 and so on); the kernel prints them
  as "SGI SAL version". The entry-point descriptor in it is the address of `salruntime_entry` or its physical twin.
  Entry types present are not decoded here (unknown).
- **EFI configuration table GUIDs (established as data, unknown as to which are installed):** the EFI image carries the
  GUIDs for the SAL system table (`eb9d2d32-2d88-11d3-9a16-0090273fc14d`), ACPI 1.0 (`eb9d2d30-...`), ACPI 2.0
  (`8868e871-e4f1-11d3-bc22-0080c73c8881`), SMBIOS (`eb9d2d31-...`), MPS (`eb9d2d2f-...`), the PCI option ROM table
  (`7462660f-1cbd-48da-ad11-91717913831c`) and the debug image info table. The `gPcdpTableGuid` data symbol (HCDP/PCDP)
  is also there. The 2.6.5 kernel's `efi_init` walks the configuration table for SAL, ACPI 2.0, SMBIOS and HCDP;
  which the PROM installs is the first thing to settle by tracing `InstallConfigurationTable` calls
  ([question](../../../questions/sn2-prom-open.md)).
- **ACPI (inferred):** `Acpi20TableGuid` is present, and SN SAL `0x5f` (`SN_SAL_IOIF_INIT`) in the three newer images
  matches the kernel's ACPI I/O path. The 2.6.5 kernel's I/O path is the older direct one (`0x55` to `0x58`), so for
  that kernel the I/O description is not ACPI. Whether the 4.43 and 4.90 PROMs publish a DSDT with the `SGIHUB`
  devices the v5.3 kernel reads is unknown.
- **EFI memory map, `EFI_RUNTIME_SERVICES` time and variable calls:** the runtime calls SAL ids `0x0a`/`0x0b` for time
  (established from the EFI image's `RtSNSetTime` and `RtSNGetTime` constants) and `0x08` for variable store.
- **PAL:** reached through `PAL_PROC` calls from `cpu_MakeStaticPALCall*`/`cpu_MakeStackedPALCall*`; `SET_VECTORS`,
  `MC_SET_PARAMS` and `MC_RENDEZ` are generic SAL calls both tables answer.

## What is not covered

The ordered reading of both SAL_B init paths, which EFI configuration tables are installed, and the exact register
accesses of memory sizing are the open items of [boot-sequence.md](boot-sequence.md) for SAL 5.04; see [questions/sn2-prom-open.md](../../../questions/sn2-prom-open.md).
The images, the root layout and the kernel in use are listed in [evidence/irix-files.md](../../../evidence/irix-files.md#sn2-firmware-and-kernels).

## Review

Independent review of chips commits `98bcb20..fe7f0ae` (this page, [questions/sn2-prom-open.md](../../../questions/sn2-prom-open.md), the SN2 firmware section of [evidence/irix-files.md](../../../evidence/irix-files.md#sn2-firmware-and-kernels) and the PROM-view lines on the SHub, SN2 address-map and SAL pages), examined at `a399d6d`. The reviewer did not write the page. Method: parse the FIT and unpack the components with a fresh script, then re-read the binaries with the retools `ia64-linux-gnu-objdump`, `-readelf` and `-nm`. Nothing in the page was taken from its own tables.

**Checks and results.**

- **Checksums and sizes in irix-files.md:** all seven sha256 values match `root/sn2/SHA256SUMS` (which verifies clean) and the listed sizes match the files. Pass. The root also holds four packages the page does not list (snprom 3.32, 4.20 and 10.54 with its `README.snprom`, and kernel 2.4.21-sgi300r3); the list is stale against the root.
- **Image layout:** FIT address, offset, length, version, checksum flag and form checked for every entry of all four images; gzip expanded sizes and the tar/ELF forms checked by unpacking. All rows match. The header entry count includes trailing empty (type 0x7f) entries (14, 15, 17, 16), which the page does not say. The `0xFFFFFFF0` reset-vector bytes are identical across the four images; `0xFFFFFFE0` and `0xFFFFFFE8` differ per image as the page describes.
- **Product compatibility:** `IP57` does not occur in any of the eight snprom images now in the root (including 3.32, 4.20 and 10.54), nor in `README.snprom`. `IP65` occurs only in the SHub 2 images. `IP41` is the CPU board name in the SHub 1 banners and build definitions, but the string `IP41` also occurs in the SHub 2 images (the klconfig board-type list, the literal `Part:030-1604-001;Name:IP41` record and "update_klcfg_cpuinfo: Can't find IP41"); "IP41 only in SHub 1 images" holds for the banner and `CPUBOARD` define, not for the string. `SHub 1.1/1.2/1.x`, `NL3Router` only in the SHub 1 images, `SHub 2.0` and `SHUB2 does not support XIO I/O.` only in the SHub 2 images, `TIO 1.x` in all four: pass. Build definitions in 4.43 and 1.11 and their absence in 4.90 and 1.40: pass.
- **SAL dispatch:** the runtime `salruntime_functab` and the SAL_B table were parsed in all four images (the runtime handlers through the relocation records) and compared with every row of the table. Presence in all four columns, the "physical only" versus "runtime and physical" split and every PROM function name match. Two rows were wrong and are fixed: `0x02000068` and `0x02000069` have their own SAL_B handlers in 4.90, 1.40 and 1.11 (1.11 has only `0x68`), so they are runtime and physical. The dispatcher claim holds: one descriptor serves 17 ids (`0x51` to `0x60`, `0x64`) in 1.40 and 11 in 4.43, and its switch is on `id - 0x02000051` over 20 cases. In 1.40 the cases for `0x61`, `0x62` and `0x63` go to the default; `0x5b` has a distinct case (the page said `0x5b`, fixed). The ids 4.43 lacks match the table (`0x5a` to `0x5f`, `0x61`, `0x65` to `0x69`). The kernel call-id list was re-derived from the 2.6.5 kernel text and matches exactly. Header names for the 20 ids spot-checked against Linux v5.3 `sn_sal.h` agree.
- **`SN_SAL_GET_SN_INFO`:** read in full in 4.43 and 1.40 and checked in 4.90 and 1.11. SHub 1: chip 0, 11, 9, `NASID / 512`, bits 52:48 of `0x81_1006_0580`, constant `0x2607ff`: pass. SHub 2: chip 1, maximum-node log2 `V + 10`, mask `(1 << (V + 10)) - 1`, shift `40 - V`, sharing domain 9 or 11 from bit 54 of `0x2_1006_0f00`, coherency domain `NASID / 512` or `/ 2048`: pass. **Wrong:** the region size is `1 << (X & 7)` where X is read from `0x2_0003_0000`, not from V (`0x2_2011_0000`). Not fixed here; the page and its summary row need the author's correction.
- **`sysctl_probe` and `cpuid[2]`:** in 1.40 the function loads `0xaeeeeeee8badbeef`, compares it with `cpuid[2]` and returns 0 on equal, 1 otherwise: pass. In 4.43 it is a different function: the equal case returns 0, but otherwise it polls the controller (`sysctl_version`, a 2,000,000-tick wait on `chipset_rtc_time`) and returns 1 only if that succeeds. The page states the 1.40 behaviour as if general. `sc_shub2_sim_data` reads `0x1003_8200` through the vector accessor: pass. The simulator reading stays inferred.
- **SHub 2 SAL_A (1.40) register list and order:** every listed address, value and order of the election and flag writes was found in the code, and the PAL stepping tables (15 rows in 1.40, 13 in 1.11) are as described. Problems, none fixed: (1) the list is not complete. SAL_A also reads `0x2_2011_0010` (a helper whose result is written to `cr.lid`), and an error path writes progress code 176 and then clears bits 29:26 of `0x2_101d_0300`, ORs `0x280_0000_0000` into `0x2_101d_0080`, writes `0x1_0001_0000_0000` to `0x2_2000_0000` and spins. (2) The "losers" reading is backwards: the routine that sets bits 41:39 of `0x2_101d_0100` to 7 returns early when its slice+1 differs from `0x2_101d_0080`, so it runs on the processor whose value matches, the same one the election writes belong to. (3) Progress codes in SAL_A are 48, 56 and 59 (reasons 0, 1, 2), 177 (a reason above 3), 176 (the error path) and 178 (the fatal hang); the page lists 176 to 178 only. (4) The PAL pair is selected only for reason 3, after the `0x2_1002_0000` and NASID-table writes, not first as the numbered list reads. The SHub 1 constants list matches the 4.43 and 4.90 code.
- **Boot-first recommendation:** the root's `snprom-10.54-70399/.../README.snprom` (vendor package note) says `shub1snprom.bin` supports the Altix 330, 350, 3300, 3700, 3700 Bx2 and both Prism models, and `shub2snprom.bin` supports the Altix 4700 and 450. That settles the Altix 350 (SHub 1, IP41 family) and puts Prism on the SHub 1 image. The page's choice of `shub2snprom.bin` for Prism, its "Prism chip unknown" and "no held PROM supports the 350" statements, and the question entries on the board-to-product mapping predate that file and need revising. Not fixed.

**Mechanical fixes made in this review:** the "same final 32 bytes" wording, the two table cells, the `0x5b` mention and the runtime-table entry count.

**Grades.** The layout, FIT, component forms, product strings, dispatch tables, kernel call list, the SHub 1 `GET_SN_INFO`, the SHub 2 mask, shift and sharing-domain parts, and the 1.40 `sysctl_probe` test are correctly **established**. "Established" should not stand for the SHub 2 SAL_A list as complete or ordered, the "losers" statement or the region-size source until corrected. Statements marked inferred (SAL_B names by signature, SHub 1 SAL_A order, memory, console and simulator readings) were not re-derived and are not cleared. `SAL_B` reset-entry offsets and the first calls were spot-checked only.

**Cleared scope:** the image layout tables, checksums, product-compatibility strings (with the `IP41` qualification), the dispatch table and kernel call comparison, and the `SN_SAL_GET_SN_INFO` handler except region size. **Not cleared:** the SHub 2 SAL_A register list as a complete ordered account, the region-size source, the boot-first recommendation and Prism or Altix 350 statements, and the list in irix-files.md as the root's full contents. The three PROM-view lines on the other pages are cleared for the mask, shift and sharing-domain content they state and for the `SH2_IPI_ACCESS` writes; the address-map line attributes the global window `0x3_0000_0000` to the first-stage firmware, but the first stage does not use it (the runtime does), so reword it when the page is corrected.

**Findings addressed in ec38a7e; renewed review needed.** Items 1 to 4 of the SHub 2 SAL_A list, the region-size source, the `sysctl_probe` per-build statement, the stale root listing, the boot-first recommendation and the Prism and Altix 350 statements, and the address-map line are corrected there. The reviewer's clearance above stands for what it cleared; the corrected claims are not cleared until reviewed again.

### Renewed review

Independent review of chips commits `ec38a7e`, `4bb8d3a`, `cb0fe84` and `b8fa253`, examined at `b8fa253`, by a reviewer who did not write them. Details and method are in the [Review section of the boot-path page](boot-sequence.md#review).

**Checks and results.**

- **SHub 2 SAL_A list and order:** the earlier items (the `0x2_2011_0010` read feeding `cr.lid`, the 176 error path, progress codes 48, 56, 59, 176, 177, 178, PAL pair only on reason 3 after the identity writes) agree with the SHub 1 SAL 5.04 first stage, which has the same control structure and was read in full; I did not re-read the 1.40 SHub 2 SAL_A bundle by bundle. Election direction (the matching processor is the winner, and sets bits 41:39) holds in the SHub 1 code.
- **Progress codes:** 176 is "PAL early self-test failed" and 177 "SAL entered with invalid function code" in the PROM's own table, consistent with the stated meanings.
- **GET_SN_INFO region size:** the register `0x2_0003_0000` is loaded in the 10.40 SHub 2 SAL_B; pass.
- **`sysctl_probe` per build:** 5.04 and 4.90 compare `cpuid[2]` only (read); 4.43 has the 2,000,000-tick retry (located); 3.32, 4.20, 1.11 and 1.40 not re-derived.
- **irix-files.md:** all six new rows match `root/sn2/SHA256SUMS` in hash and size.
- **README.snprom and recommendation:** the package note lists Altix 330, 350, 3300, 3700, 3700 Bx2, Prism Rackmount and Deskside for `shub1snprom.bin` and Altix 4700 and 450 for `shub2snprom.bin`; the recommendation of the SAL 5.04 SHub 1 image follows.
- **Global window attribution:** SAL_A SHub 2 uses `0x2_...` addresses; the runtime constants for `0x3_...` were not re-read.

**Cleared scope:** the SHub 2 SAL_A corrections as far as they are shared with the read SHub 1 code, the region-size source, the 4.43, 4.90 and 5.04 `sysctl_probe` statements, the hash and size rows, the README.snprom reading and image recommendation. **Not cleared:** the `sysctl_probe` statement for 3.32 and 4.20, the 1.40 first-stage list as a bundle-level re-read, and the global-window attribution in the address-map line. Findings on the new boot-path page are listed there.

