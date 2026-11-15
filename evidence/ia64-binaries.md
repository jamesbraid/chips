# IA-64 binaries held for SN2 and SN1

Inventory of the IA-64 binaries this repository holds or can reach through the Library for SGI's SN2 machines (Altix 350,
3000, 4700, Prism) and the SN1 IA-64 platform. It lists each file by its chips RE root path or Library id, with its
sha256, kind, product, ELF status and machine. It is a list, not a reading: nothing here is a register contract. Grades
follow [sn2-holdings](sn2-holdings.md): established (read in the file), inferred, unknown.

Counts: 11 IA-64 binaries (8 PROM images, 2 kernel ELF images, 1 kernel module). Nothing for SN1. The files are in the chips
RE root under `sn2/`; the root is never committed. Hashes come from that root's `SHA256SUMS` and from the Prism package's
own `SHA256SUMS`, which all matched on 2026-11-15, plus one hash computed here (the decompressed SN2 kernel). The
installation media are not in these counts; they are in [IA-64 Linux media](#ia-64-linux-media).

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
userland or library files in this root. The Library's media hold members for those stages (see below).

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
SGI manuals, and linux-ia64 list mail. It also holds IA-64 Linux installation media in its IRIX mirror tree: the ProPack 4
SP3 CD1 to CD3 and QuickTransit 1.2 ISOs, found by the Library ids in the media table, and the SLES 9 and SLES 11 ISOs
from the same mirror. The earlier version of this page said the Library held none of this. That was wrong: a search for
"ProPack 4 SP3" on 2026-11-15 returned manuals and mail but not the ISOs, so a missed search does not prove absence. The
Library still holds no IA-64 kernel build outside those packages and no elilo or initrd outside the media.

The kudzu RE root names no ProPack or ia64 media in its `irix-files.md`, so it adds nothing here.

## IA-64 Linux media

ISO 9660 images from the Library's IA-64 Linux mirror. Nothing was copied or extracted. Member paths are the names
`isoinfo -f` prints, so 8.3 names with a `;1` suffix. Versions are read from strings in the RPM bytes, not from parsed
RPM headers, so they are read, not verified. Sizes are bytes.

| Media | Bytes | sha256 | Product, release and Library id | Boot-relevant members |
|---|---|---|---|---|
| ProPack 4 SP3 CD1 | 32528384 | `fbb6dd1fae0fa77db0e2882ceb114c41450eee302b51e28b52891a64b3000e27` | SGI ProPack 4 for Linux SP3, release notes disc. `irix-mirrors:mirror.rqsall.com/misc/ia64linux/SGI/ProPack4_for_Linux_SP3_CD1.iso` | `/DOCS/README.TXT`, `/DOCS/RPMS.TXT`; `/SGI/IA64/MMTIMER_.RPM`; `/SGI/IA64/KM_SN2_*.RPM` |
| ProPack 4 SP3 CD2 | 125089792 | `c3015971749c9729b599e7c5d23c84423f9f88f0b25596a00ba85b3ca51d2b5c` | SGI ProPack 4 for Linux SP3. `irix-mirrors:mirror.rqsall.com/misc/ia64linux/SGI/ProPack4_for_Linux_SP3_CD2.iso` | `/SGI/IA64/SNPROM_4.RPM` (`snprom-4.43-44607` in its strings, the build of row 1); `KM_SN2_S/U/X.RPM`; `SGI_*.RPM`; `XVM_CMDS.RPM` |
| ProPack 4 SP3 CD3 | 476696576 | `e3d42f1417a3ca585562a43f78e88947d9aeabf1ee99d79e957419de907fd479` | SGI ProPack 4 for Linux SP3, System Extensions disc (per a 2006 linux-ia64 list post). `irix-mirrors:mirror.rqsall.com/misc/ia64linux/SGI/ProPack4_for_Linux_SP3_CD3.iso` | `/SGI/IA64/KERNEL_2.RPM` (`2.6.5-7.244` in its strings); `KERNEL_R.RPM` (`2.6.5-7.244-rtgfx`); `SGI_*.RPM`; `SAX2`, `XFREE86` packages |
| QuickTransit 1.2 IA-64 | 324823040 | `40d7b33209a28d42df8ef52ea866403702c2b688b7a37ee61e39b36c2a3fc772` | QuickTransit V1.2 for Linux IA-64. `irix-mirrors:mirror.rqsall.com/misc/ia64linux/SGI/QuickTransit_V1_2_Linux_IA-64.iso` | None. Seven files: `INSTALL`, `README.TXT`, `EULA.TXT`, and four RPMs (`QUICKTRA.RPM`, `LIBUNWIN.RPM` and two more). Not a boot stage |
| SLES 9 SP3 GM CD1 | 734969856 | `bb6d5e3167ffd089ebafe6831afb544070bab528516bb4a0609699290f6bc0fe` | SUSE Linux Enterprise Server 9 SP3 for ia64, disc 1. The Library's IA-64 Linux mirror | `/BOOT/IMAGE.`, `/BOOT/INITDISK.GZ`, `/BOOT/RESCUE.`; `/SUSE/IA64/KERNEL_S.RPM` (`2.6.5-7.244-sn2` in its strings), `KERNEL_D.RPM` (`2.6.5-7.244-default`), `KERNEL_6.RPM`, `MKINITRD.RPM` |
| SLES 9 SP3 GM CD2 | 574881792 | `a77c92eb67ebbe34bc00a27476cfeb2cb21b230aa19ee191cecacd6b81aeea35` | As above, disc 2 | Kernel source RPM only (`/SUSE/SRC/KERNEL_S.RPM`); no ELILO |
| SLES 9 SP3 GM CD3 | 681666560 | `efa1e4675b34149bfeeaa27192a21c517ef1ffaafd72f2136b224e7d1feb7681` | As above, disc 3 | Source RPMs: `KERNEL_6/D/S`, `LINUXRC_`, `MKINITRD` |
| SLES 9 RC5 CD1 | 291710976 | `98f112a7043965e5af1f9a8c365aa6b81391841e717bdd183707fe799f64961e` | SLES 9 ia64 RC5 (pre-release), disc 1 | `/BOOT/IMAGE.`, `/BOOT/INITDISK.GZ`, `/BOOT/ROOT.`, `/BOOT/RESCUE.`, `/BOOT/RESCUEFL.` |
| SLES 9 RC5 CD2 | 680275968 | `ab821c321e59ddb6ea93055f3677a2428a5b1f5ae5d726b713f6f06add137ac1` | SLES 9 ia64 RC5, disc 2 | `/SUSE/IA64/ELILO_3_.RPM`; `KERNEL_6/D/S.RPM`; `MKINITRD.RPM` |
| SLES 9 RC5 CD3 | 651005952 | `66446299485d8e4c867114fc76bc431624ef14cdb7b53a4abd77333039440abb` | SLES 9 ia64 RC5, disc 3 | None by name |
| SLES 9 RC5 CD4 | 600064000 | `8d2417dc2bd35e1171fd279891ca1ca461eb0ef47256749469448c0db37d3a7c` | SLES 9 ia64 RC5, disc 4 | `/SUSE/IA64/LINUXRC_.RPM` |
| SLES 9 RC5 CD5 | 680937472 | `ccb2ddb02c4b199858d90acc664d6d66e56697bffd4751e9c3e70d488674320e` | SLES 9 ia64 RC5, disc 5 | Source RPMs: `/SUSE/SRC/ELILO_3_.RPM`, `LINUXRC_`, `MKINITRD` |
| SLES 9 RC5 CD6 | 662325248 | `388b6eb3d061274968797c8ebd7a74eb41e02c4dd55e41757eddec56513d3836` | SLES 9 ia64 RC5, disc 6 (36 files) | None by name |
| SLES 11 SP4 DVD1 | 3359084544 | `5eabd5dd5ffb21a9f37c023ddac951206c75ecd53ba6527ca5b39c4cb172581d` | SLES 11 SP4 ia64, DVD 1. The Library's IA-64 Linux mirror | `/BOOT/IA64/INITRD.` (52118160 B); `/BOOT/IA64/ROOT.` (61341696 B, installer root); `/BOOT/IA64/IMAGE.` and `/BOOT/IA64/EFI.` (both 59609088 B, identity not checked); `/BOOT/IA64/LOADER/` (empty directory); `/SUSE/IA64/ELILO_3_.RPM`; `KERNEL_S.RPM` (93229827 B, version not read), `KERNEL_D.RPM`, `KERNEL_T.RPM`, `MKINITRD.RPM` |
| SLES 11 SP4 DVD2 | 5369047040 | `c70f88270249db007e9f2bc1caf12cb1486d09be006f9d4a26e9a63a63a1721c` | SLES 11 SP4 ia64, DVD 2 | Source and no-source RPMs: `/SUSE/SRC/ELILO_3_.RPM`, `KERNEL_*` |

Release match. The ProPack 4 SP3 README describes SP3 as an overlay on SLES 9 SP3. Its RPM list names km-sn2 modules
(arsess, csa, job, numatools, xpmem) built for `2.6.5-7.244-sn2`. The held SN2 kernel is 2.6.5-7.244. The same version
string appears in the SLES 9 SP3 GM CD1 `KERNEL_S.RPM`. These are string matches; no binary was compared with row 9.

Hardware-facing members. `MMTIMER_.RPM` is on CD1 (the mmtimer package the README lists). The km-sn2 modules are on CD1
and CD2 by name. The discs' 8.3 names do not show which disc holds XPMEM or which holds the `sgi-*` packages. No ioc4,
xpc, L1, L2 or system-controller package name appears on the four SGI discs by name grep.

## SN1 IA-64

Nothing held. The only SN1 firmware is SGI's simulator fake PROM, which the Linux 2.5 tree builds from source; no SN1
binary was found in the chips root or the Library. See [sn1-ia64-sources](sn1-ia64-sources.md) and
[platforms/sn1-ia64/fake-prom.md](../platforms/sn1-ia64/fake-prom.md).

## Boot path coverage

| Stage | Covered by | Status |
|---|---|---|
| 1. PAL and SAL | Rows 4, 7 and 8: the SHub 1 and SHub 2 PROM images hold PAL_A, PAL_B and SAL in one flash file. Rows 1 to 3 and 5 and 6 hold older builds. | Covered inside the PROM images, not extracted separately. The newest SHub 1 image held is row 7 (SAL 5.04). |
| 2. EFI firmware and its console | The EFI component is inside the same PROM images (established for row 7: a gzip EFI component of 2,495,544 bytes). The console is the SAL/EFI serial path. | Covered in rows 4 to 8, not separately extracted. |
| 3. EFI boot loader (elilo) | `ELILO_3_.RPM` on SLES 11 SP4 DVD1 and SLES 9 RC5 CD2 (the file list names `elilo.efi` and `elilo.conf`, read from the package strings). SLES 11's `/BOOT/IA64/LOADER/` is empty. | Held as packages in the media. Not extracted, so the file contents are unchecked. No standalone `elilo.efi` held. |
| 4. Linux kernel | Row 9 (SN2 2.6.5-7.244, with symbols); row 10 (Prism 7.3.0 community build, with symbols); SLES 9 GM CD1 `KERNEL_S.RPM` (`2.6.5-7.244-sn2` in its strings); ProPack CD3 `KERNEL_2.RPM` (`2.6.5-7.244`); SLES 11 DVD1 `KERNEL_S.RPM` (version not read) | Covered. Row 9 matches the SLES 9 SP3 SN2 version string, not its binary. Row 10 is not SGI. |
| 5. initrd | SLES 11 DVD1 `/BOOT/IA64/INITRD.`; SLES 9 GM CD1 and RC5 CD1 `/BOOT/INITDISK.GZ` and `/BOOT/IMAGE.` (installer images) | Held as media members, not extracted. Not matched to a kernel. |
| 6. init and userland to multi-user | Installer roots: SLES 11 DVD1 `/BOOT/IA64/ROOT.`; SLES 9 RC5 CD1 `/BOOT/ROOT.`. Package sets: SLES 9 GM CD1 to CD3 and RC5 CD1 to CD6, SLES 11 DVD1 and DVD2, ProPack CD1 to CD3. | Held as packages and installer roots. No rootfs was built or booted. Row 10's build has an `os-release` and no rootfs. |

Open items: the snprom 10.54 package's SHub 2 image (row 8) has no SAL reading yet. Nothing in the root shows the boot
order of stages 3 to 6 on any SN2 machine. Extract `elilo.efi` and `elilo.conf` from `ELILO_3_.RPM` and read the kernel
RPM headers; then check that the SLES 11 `IMAGE.` and `EFI.` members (same size) are what their names say.

## Checked and not done

- No hashes were recomputed for rows 1 to 8 and 10 and 11 beyond the checksum files, which all matched.
- Symbol and DWARF status comes from `readelf -S` in the retools container. Row 9 was checked after decompression.
- Nothing was extracted from the snprom packages, the Prism image or the snxsc package.
- The media were listed with `isoinfo -f` and hashed with `sha256sum`; no member was extracted. The ProPack and
  Advanced Linux Environment 3 containers under the jrra and mega mirrors were not listed or hashed. Their path count
  (about 77 with .tar copies) does not match the owner's 61, and that is unreconciled.
