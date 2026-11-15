# IA-64 binaries held for SN2 and SN1

Inventory of the IA-64 binaries this repository holds or can reach through the Library for SGI's SN2 machines (Altix 350,
3000, 4700, Prism) and the SN1 IA-64 platform. It lists each file by its chips RE root path or Library id, with its
sha256, kind, product, ELF status and machine. It is a list, not a reading: nothing here is a register contract. Grades
follow [sn2-holdings](sn2-holdings.md): established (read in the file), inferred, unknown.

Counts: 11 IA-64 binaries (8 PROM images, 2 kernel ELF images, 1 kernel module). Nothing for SN1. The files are in the chips
RE root under `sn2/`; the root is never committed. Hashes come from that root's `SHA256SUMS` and from the Prism package's
own `SHA256SUMS`, which all matched on 2026-11-15, plus one hash computed here (the decompressed SN2 kernel).

## IA-64 binaries

| # | Path under `sn2/` | Kind | Product and version | ELF | Symbols or DWARF | Machine | sha256 |
|---|---|---|---|---|---|---|---|
| 1 | `snprom-4.43-44607/boot/efi/snprom.bin` | PROM image | SNPROM 4.43 build 44607, SAL 4.43, board IP41 | no (flash image) | n/a | SHub 1 build target; no machine named | `035274812b5065bde3f1b3227a23c05637d8a13f7cab7736ddde4718d46f02eb` |
| 2 | `snprom-4.20-40503/boot/efi/snprom.bin` | PROM image | SNPROM 4.20 build 40503, SAL 4.20, IP41 | no | n/a | SHub 1; no machine named | `0fdd129ecc2efdcfb875c873d67c9e18e57bc75b4500d6c1e72a1d9ca8dfa866` |
| 3 | `snprom-3.32-30085/boot/efi/snprom.bin` | PROM image | SNPROM 3.32 build 30085, SAL 3.32, IP41 | no | n/a | SHub 1; no machine named | `cce7adf38c0bb5b50d7c48c571fa4194f5b714d5c46e0e6519b2a64b2b34e0d6` |
| 4 | `snprom-10.40-62478/boot/efi/efi/sgi/snprom/shub1snprom.bin` | PROM image | SNPROM 10.40 build 62478, SAL 4.90, IP41 | no | n/a | SHub 1 (Altix 350 and Prism per the later package README, inferred) | `26170cc83c3db243601da8f55610bcdd6bb408136c3b3d19b7c4823e491b9a06` |
| 5 | `snprom-10.40-62478/boot/efi/efi/sgi/snprom/shub2snprom.bin` | PROM image | SNPROM 10.40 build 62478, SAL 1.40, IP65 | no | n/a | SHub 2 (Altix 4700 and 450 per the package README, inferred) | `1c8144e3d318f71a7633dddc268c3ebd0f64febb87c2f234a9a917df0673dd77` |
| 6 | `snprom-10.11-52277/boot/efi/efi/sgi/ip65prom.bin` | PROM image | SNPROM 10.11 build 52277, SAL 1.11, IP65 | no | n/a | SHub 2; no machine named (predates the README) | `372e74f7201d35e56ef871c330ccbd66fda9f921376ae5dd3045cf4ae6319199` |
| 7 | `snprom-10.54-70399/boot/efi/efi/sgi/snprom/shub1snprom.bin` | PROM image | SNPROM 10.54 build 70399, SAL 5.04, IP41 | no | n/a | SHub 1: Altix 330, 350, 3300, 3700, 3700 Bx2, Prism (SGI README, intent) | `51ccf9ad830b85ee6c88d6d73d2512322a86454e63db51c57454679283a34617` |
| 8 | `snprom-10.54-70399/boot/efi/efi/sgi/snprom/shub2snprom.bin` | PROM image | SNPROM 10.54 build 70399, SAL not read | no | n/a | SHub 2: Altix 4700 and 450 (SGI README, intent) | `3ea833181fda8968a5297043f2260d2fc255983ecca1d418292ee008b5e2c793` |
| 9 | `kernel-sn2-2.6.5-7.244/boot/vmlinuz-2.6.5-7.244-sn2` | kernel ELF (gzip-wrapped) | SLES 9 SP3 SN2 kernel 2.6.5-7.244 | yes, once decompressed: IA-64 ELF64 EXEC, not stripped | `.symtab` and `.strtab`; no DWARF | SN2 Altix (config has `CONFIG_IA64_SGI_SN2=y`; narrower machine unknown) | `39131bd96291fa395389c5c280b99f33a1a9d7599f1e9871fb1b812d0b51803a` (the gzip file); the decompressed ELF is `fa56fc37688f1826512718b7e46aa29ad0ea69e4e29dd9fbeb78b8de713a1be2` (computed here) |
| 10 | `prism-t2/boot/vmlinux-7.3.0-epic1-SN2-GPU-eb5ca12536d3-ia64` | kernel ELF | Community T2 Linux build of a mainline SN2 tree, kernel 7.3.0, Prism GPU variant | yes, IA-64 ELF64 EXEC, statically linked, not stripped | `.symtab` and `.strtab`; no DWARF | Prism (per the build's PROVENANCE; not SGI firmware or an SGI release) | `2ffaeef5697badfcbc7d79af4cac2593f7024d6bd6afa14dddf403d4aeb6c021` |
| 11 | `prism-t2/lib/modules/7.3.0-epic1-SN2-GPU-eb5ca12536d3-ia64/kernel/drivers/char/agp/sgi-agp.ko` | kernel module | `sgi-agp`, from the same community build | yes, IA-64 ELF64 relocatable, not stripped | `.symtab` and `.strtab`; no DWARF | Prism (the only SGI module in that build; the GPU bridge driver) | `6401ee6982513ab41a249c7a05dcb32764d3ec5536338005a3d6bee28171e13c` |

Totals by kind: PROM image 8, kernel ELF 2, kernel module 1. Zero standalone PAL/SAL, EFI application, elilo, initrd,
userland or library files.

Notes on the rows:

- Rows 1 to 8 are flash images: the PAL, SAL, EFI and the boot code sit inside one file. A PROM image is not ELF. The
  files are named by their packages, which are in `snprom-*` directories. Machines are as in
  [snprom images](../software/firmware/snprom/images.md).
- Rows 9 and 10 carry symbols but no debug information, so the function names are there but not the source lines.
- The `kernel-2.4.21-sgi300r3` package is a symbol map only (`System.map`, text). No 2.4 kernel image is held.
- The `snxsc_firmware-1.62.1` package is for the SN2 system controller, not the IA-64 CPUs. Its contents are not IA-64
  binaries and are not counted: four i386 ELF tools (`flashfile`, `flashpbay`, `flashsc`, `flashsvf`), one shell script
  (`flashioc4`), five controller firmware images (`l1`, `l2`, `l1_mips`, `l2_mips`, `pbay`) and one SVF file.
  The firmware images report as "EST flat binary" or data; their CPU is unknown (unknown).
- Text files in the root (`System.map` files, `config`, `MODULE-LIST.txt`, `PROVENANCE.txt`, `os-release`,
  `radeon-prism.conf`, `README.snprom`, `RPM-INFO.txt`) are not binaries and are not counted.

## Library

The Library holds ProPack manuals (for example 007-3844-001, "SGI ProPack 1.2 for Linux -230 Edition Start Here"), other
SGI manuals, and linux-ia64 list mail. It holds no ProPack RPM or media, no IA-64 kernel, no elilo, no initrd and no SN2
PROM image. Searches on 2026-11-15 for ProPack, elilo, "SGI Advanced Linux Environment", snprom and "ia64 rpm" returned
manuals, notes and mail only.

The kudzu RE root names no ProPack or ia64 media in its `irix-files.md`, so it adds nothing here.

## SN1 IA-64

Nothing held. The only SN1 firmware is SGI's simulator fake PROM, which the Linux 2.5 tree builds from source; no SN1
binary was found in the chips root or the Library. See [sn1-ia64-sources](sn1-ia64-sources.md) and
[platforms/sn1-ia64/fake-prom.md](../platforms/sn1-ia64/fake-prom.md).

## Boot path coverage

| Stage | Covered by | Status |
|---|---|---|
| 1. PAL and SAL | Rows 4, 7 and 8: the SHub 1 and SHub 2 PROM images hold PAL_A, PAL_B and SAL in one flash file. Rows 1 to 3 and 5 and 6 hold older builds. | Covered inside the PROM images, not extracted separately. The newest SHub 1 image held is row 7 (SAL 5.04). |
| 2. EFI firmware and its console | The EFI component is inside the same PROM images (established for row 7: a gzip EFI component of 2,495,544 bytes). The console is the SAL/EFI serial path. | Covered in rows 4 to 8, not separately extracted. |
| 3. EFI boot loader (elilo) | none | not held |
| 4. Linux kernel | Row 9 (SN2 2.6.5, SLES 9 SP3, with symbols) and row 10 (Prism 7.3.0 community build, with symbols) | Covered. Row 9 is the SGI shipped kernel. Row 10 is not SGI. |
| 5. initrd | none | not held |
| 6. init and userland to multi-user | none. Row 10's build has an `os-release` and one SGI module in the root, but no rootfs. | not held |

Open items: the snprom 10.54 package's SHub 2 image (row 8) has no SAL reading yet. Nothing in the root shows the boot
order of stages 3 to 6 on any SN2 machine.

## Checked and not done

- No hashes were recomputed for rows 1 to 8 and 10 and 11 beyond the checksum files, which all matched.
- Symbol and DWARF status comes from `readelf -S` in the retools container. Row 9 was checked after decompression.
- Nothing was extracted from the snprom packages, the Prism image or the snxsc package.
