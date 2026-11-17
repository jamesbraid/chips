# Installing a full Altix Linux distribution

Scope: an Altix 350 booting PROM 10.54 (SAL 5.04) with elilo. Section 3 grades what an emulator needs beyond the ISP12160 SCSI disk and CD, the PIC bridge, the IOC4's PCI identity and the L1 console. No PROM reverse engineering was done for this page; it reads SGI's manuals and the public kernel sources.

Sources: SGI manuals in the Library techpubs root (007-4558-014, 007-4727-003, 007-4837-006, 007-5482-007, 007-4633-007/-013/-017, 007-4660-002); kernel sources in the local linux-sn2 mirror (tag v7.3-rc3-epic1-sn2-gpu) and Library `linux-history` (mmtimer.c).

## 1. SGI install procedure and boot media

### Release map (007-4633-017 revision history and the Start Here guides)

| ProPack | Base distro | Kernel | Start Here |
|---|---|---|---|
| 3 (SP1-SP6) | SGI Advanced Linux Environment 3 (RHEL AS3 rebuild) | 2.4.21 | 007-4558-012 / -014 |
| 4 (to SP3) | SLES 9 SP3 | 2.6.5 | 007-4727-001 / -003 |
| 5 (SP1-SP5) | SLES 10 SP1 or RHEL 5.1 | 2.6.16 / 2.6.18 | 007-4837-002 .. -006 |
| 6 (to SP6) | SLES 10 SP3, SLES 11 or RHEL 5.4 | 2.6.16 / 2.6.18 / 2.6.27 | 007-5482-001 .. -007 |

Kernel numbers are my reading of the distro versions, not stated in the guides. The 007-4558 series stops at ProPack 3 SP6.

### Two-stage install

1. Boot the base distro installer from EFI.
   - EFI shell: `Shell> fsN:` (the CD is fs0 or fs1; the guide says "fs1 at the bottom of the list" on Altix), `cd efi\boot`.
   - ProPack 3: run `elilo`, press Enter at `ELILO boot:`.
   - SLES 9/10/11 and RHEL 5: run `bootia64`, choose Installation, and type a boot line.
   - Boot line: `console=ttyS0,38400n8 vnc=1` (ProPack 4), `console=ttySG0,38400n8 vnc=1` (ProPack 6), `ttyS1` if the cable is on the serial port.
   - The guides call the serial console "not 100% clean"; use Ctrl-L to redraw.
2. Network variant (ProPack 3 guide, 007-4558-014 pp. 10-15). TFTP serves the `efi/` tree copied out of `images/boot.img`, which sits inside CD1 (ISO 9660 with a FAT image). elilo.conf `install` entry gets `append="console=ttyS0 askmethod"`. DHCP gives `filename "/sgiadvlinux-3/efi/boot/bootia64.efi"`. The installer then asks for NFS source and static IP.
3. Base install. Text anaconda (ProPack 3, RHEL 5) or YaST (SLES). Partitioning: GPT, `/boot/efi` VFAT (about 500 MB), swap, XFS root (RHEL 5.x uses ext3 and LVM). The SLES 9 notes say to check that `tg3` loaded when using the network.
4. Reboot into the installed base system. elilo.conf is `/boot/efi/efi/SuSE/` (SLES) or `/boot/efi/EFI/redhat/` (RHEL); ProPack 3 used `/boot/efi/efi/sgi/elilo.conf`.
5. Add the ProPack layer.
   - ProPack 3: mount CD1 and run `/mnt/cdrom/INSTALL` (Open Source CD1-3, Proprietary CD4).
   - ProPack 4+: add-on product in YaST (SLES) or an install script (RHEL5).
   - This drops in the SGI kernel, `snprom` and the XP modules.
6. Optional: flash the system PROM from `snprom.bin` and install the System Controller package for L1/L2.

Firmware prerequisite: ProPack 3 notes that a too-old PROM makes the kernel fail to boot during install. PROM 10.54 should be recent enough, not verified.

### EFI device map seen by the installer (007-4558-014 p. 17)

The CD appears as `Pci(2|1)/Ata(Primary,Master)/CDROM(Entry1)` (IOC4 ATAPI). Disks appear as `Pci(1|1)/Scsi(Pun0/Lun1)` (ISP12160). The NIC appears as `Pci(4|0)/Mac(..)/NicName(tg0)`, with `tg0: ASIC|Revision|MAC : 5701|B5|..`. The 007-4660-002 block diagram of IO9 shows SCSI, IOC4, NVRAM and gigabit Ethernet on one card. IO10 swaps SCSI for SATA and has a serial port.

## 2. Kernel features ProPack adds, and what they need

From the linux-sn2 tree (7.3-rc3 fork) and `linux-history`.

| Feature | Source | Hardware / SAL it uses |
|---|---|---|
| sn_console (`ttySG0`) | drivers/tty/serial/sn_console.c | SN_SAL_CONSOLE_PUTB, GETC, READC, POLL, INTR, XMIT_CHARS; polled or interrupt driven |
| snsc (/dev/sn/ L1/L2 channels, events) | drivers/char/snsc*.c | SN_SAL_IROUTER_OP (open, close, send, recv, intr), SN_SAL_SYSCTL_EVENT |
| sn_hwperf | arch/ia64/sn/kernel/sn2/sn_hwperf.c | SN_SAL_HWPERF_OP (op 1 heap size, 2 install heap, 10 object count, 12 enum objects, 100-102 cpu/node/nasid) |
| mmtimer | `linux-history` drivers/char/mmtimer.c | no SAL; SHub RTC MMRs (section 3) |
| ioc4 core | drivers/misc/ioc4.c | IOC4 BAR0 MMIO, clock calibration via GPCR/INT_OUT, interrupt enable clear |
| sgiioc4 IDE | drivers/ata/pata_sgiioc4.c (libata); old `ide/pci/sgiioc4.c` in 2.6 | IOC4 ATA taskfile at BAR0+0x100, DMA regs at +0x140, 16-byte big-endian PRD entries |
| ioc4_serial (ttyIOC4) | drivers/tty/serial/ioc4_serial.c | IOC4 serial ports and interrupts |
| tiocx / mbcs | arch/ia64/sn/kernel/tiocx.c | TIO and CE bricks only; not on an Altix 350 |
| XP/XPC/XPNET/XPMEM | 2.6-era drivers/misc/sgi-xp (gone from the 7.3 tree) | SN_SAL_GET_PARTITION_ADDR, XP_ADDR_REGION, MEMPROTECT, COHERENCE; configured off by default per 007-4633-013 |
| sgi_hotplug | 2.6-era drivers/pci/hotplug/sgi_hotplug.c | SN_SAL_IOIF_SLOT_ENABLE/DISABLE, SYSCTL_IOBRICK_PCI_OP; "not configured on by default" (007-4633-013 p. ~524) |
| cpuset, numatools, `/proc/sgi_sn/*`, prominfo | proc_fs files, userspace | `/proc/sgi_sn/prominfo` uses SN_SAL_GET_FIT_COMPT |

Not present in the linux-sn2 7.3 tree: mmtimer.c, sgi-xp, sgi_hotplug. They were removed upstream with ia64 in 6.7, and the fork only kept what it ported. The IDE driver is libata `pata_sgiioc4` there.

### SN_SAL calls beyond the console

| Call | Constant | Used by | Notes |
|---|---|---|---|
| GET_MASTER_NASID, GET_KLCONFIG_ADDR, GET_SN_INFO, GET_SAPIC_INFO, GET_PROM_FEATURE_SET, SET_OS_FEATURE_SET, SET_CPU_NUMBER, GET_FIT_COMPT, PROBE | core setup | needed by every SN2 kernel at boot |
| IOIF_GET_PCI_TOPOLOGY / GET_PCIBUS_INFO / GET_PCIDEV_INFO / GET_HUBDEV_INFO, IOIF_INIT | PCI discovery | older kernels (2.6.5-2.6.18) use the non-ACPI `io_init.c` path; the 7.3 tree has both |
| IOIF_GET_DEVICE_DMAFLUSH_LIST, IOIF_PCI_SAFE | `sn_dma_flush`, DMA ordering | block and NIC DMA paths read these |
| IOIF_INTERRUPT | interrupt setup (pcibr) | needed by any interrupt-driven device |
| HWPERF_OP | sn_hwperf | `device_initcall`; failure only logs an error. First call per kernel is GET_HEAPSIZE |
| IROUTER_OP, SYSCTL_EVENT | snsc | L1/L2 channel for `/dev/sn/*` and event thread |
| SYSCTL_OP (ioboard_get, tio_clock_reset) | tiocx / snsc | CE/TIO bricks; not exercised on an Altix 350 (not checked per call site) |
| PRINT_ERROR, LOG_CE, REGISTER_CE, SET_ERROR_HANDLING_FEATURES | MCA/CPE paths | only on errors |
| GET_PARTITION_ADDR, XP_ADDR_REGION, MEMPROTECT, COHERENCE | XP | optional |
| SYSTEM_POWER_DOWN (SYSTEM_RESET exists but no caller found in the grep) | `halt -p`, reboot | shutdown/reboot |

## 3. What a full installer needs from the hardware

Severity key: B = boot-blocking (kernel or installer will not start), I = install-blocking (cannot complete an install), O = optional. "Inferred" means derived from driver code and docs, not observed on hardware or an emulator.

| Item | Severity | Why |
|---|---|---|
| EFI sees CD and boots it | B for CD installs | An ISP12160 SCSI CD, if present, `Pci(1|1)/Scsi(Pun?)/CDROM` should boot without IOC4 ATA. Real Altix 350 media were ATAPI on IOC4, but nothing in the installer needs that bus. Inferred; the El Torito catalog of each ISO has not been tried. |
| ISP12160 driver in the installer initrd (qla1280) | B | Debian ia64 config has `SCSI_QLOGIC_1280=m`; SLES/RHEL ship it too. |
| IOC4 PCI identity | B if ioc4 binds | ioc4 core runs clock calibration and clears interrupts, then registers submodules. Needs sane BAR0 reads (calibration failure only warns and assumes a default). |
| IOC4 ATA registers | O (I if the CD is on IOC4) | `pata_sgiioc4` refuses PCI revision below 46 (`IOC4_SUPPORTED_FIRMWARE_REV`), so the IOC4 must report revision >= 46 or the IDE driver stays off. Only needed if you put the CD on the IOC4 bus to match real hardware. |
| IOC4 serial (ttyIOC4) | O | The console goes through SAL, not IOC4. |
| L1 console via SAL (`ttySG0`) | B | `console=ttySG0` in elilo.conf is needed on kernels from 2.6; the old guides say `ttyS0`. A distro that writes the wrong console name gets no output after the kernel starts (inferred). |
| tg3 NIC (BCM5701 B5) | I for netinst/netboot ISOs; O for CD/DVD sets | Debian netinst (258M) and Fedora netinst (145M) fetch packages over the network; CD-1..3 (Debian) and the 3.0G Fedora DVD do not. Needs PCI config, MMIO, MDIO PHY (BCM5401 class), DMA rings, NVRAM or MAC fallback. Also required for the first-boot `eth0`/dhcp but the system boots without it. |
| EFI network driver `tg0` | O | PROM-side; only for PXE/network install. |
| PCI hotplug (sgi_hotplug) | O | Module not loaded by default; needs SYSCTL_IOBRICK_PCI_OP and slot enable/disable SAL calls. |
| L1/L2 controller access (`/dev/sn/*`, snsc) | O | Needs IROUTER_OP and SYSCTL_EVENT. Without it snsc init fails with a message. Not needed to boot. |
| SN_SAL_HWPERF_OP | O | `sn_io_late_init` calls sn_hwperf for nearest-node lookup per PCI bridge; on failure it logs "failed to find near node" and uses any node. Still a boot-time dependency to check: the PROM must answer or the call must return error without hanging. |
| XPC/XPMEM | O | Off by default. |
| System clock (RTC, `sn2_rtc` clocksource) | B | `SH_RTC` read at LOCAL_MMR+SH_RTC; frequency from `ia64_sal_freq_base`. Read at boot by every SN2 kernel. |
| MMTIMER | O | Only for `/dev/mmtimer` and POSIX CLOCK_SGI_CYCLE users (MPI, SHMEM). |
| IOC4 NVRAM / RT interrupt in/out | O | RT interrupts "not supported under SGI Linux + ProPack" (007-4660-002). |

### MMTIMER: SHub RTC registers

From `linux-history` drivers/char/mmtimer.c and `arch/ia64/include/asm/sn/shub_mmr.h`. Values are `LOCAL_MMR_ADDR` offsets; SHub 1 differs from SHub 2 in bit 32 and the RTC block address only.

| Register | SHub 1 | SHub 2 | Use |
|---|---|---|---|
| SH_RTC | 0x00000001101c0000 | 0x00000002101c0000 | 55-bit free-running counter (`RTC_BITS` 55, mask 0x007fffffffffffff) |
| SH_INT_CMPB | 0x00000001101b0080 | 0x00000000101b0080 | compare value for comparator 0 (RTC1) |
| SH_INT_CMPC | 0x00000001101b0100 | 0x00000000101b0100 | compare for comparator 1 (RTC2) |
| SH_INT_CMPD | 0x00000001101b0180 | 0x00000000101b0180 | compare for comparator 2 (RTC3) |
| SH_RTC1_INT_CONFIG / ENABLE | 0x...110001480 / 0x...110001500 | 0x...010001480 / 0x...010001500 | vector (IDX bits 52-59) and target CPU (PID bits 4-19); ENABLE bit 0 |
| SH_RTC2_INT_CONFIG / ENABLE | 0x...110001580 / 0x...110001600 | 0x...010001580 / 0x...010001600 | same for comparator 1 |
| SH_RTC3_INT_CONFIG / ENABLE | 0x...110001680 / 0x...110001700 | 0x...010001680 / 0x...010001700 | same for comparator 2 |
| SH_EVENT_OCCURRED (+ALIAS at +8) | 0x0000000110010000 | 0x0000000010010000 | pending bits: RTC1 bit 24, RTC2 bit 25, RTC3 bit 26 |

Notes:
- Comparators are RTC1-RTC3 here (the driver comment says RTC0 belongs to SAL and "RTC1-4" exist per node).
- Sequence per comparator: disable, set CMP to -1, clear pending through the ALIAS register (write-1-to-clear), write CONFIG, enable, write the compare value, then re-read `SH_RTC` to see if it was missed.
- Interrupt vector is `SGI_MMTIMER_VECTOR`, targeted at `cpu_physical_id`.
- Which SHub the Altix 350 carries (1 or 2) is not stated in the guide; check the SHub generation before using the column.

## 4. Public ia64 distros with SN2 support

Directory listings only; nothing downloaded. Kernel-config rows say what I read, not what I assumed.

| Distro | Kernel | SN2 in config | ISO sizes | URL |
|---|---|---|---|---|
| Debian 7.11.0 wheezy ia64 (last ia64 release) | 3.2.x | SGI_SNSC=y, SERIAL_SGI_L1_CONSOLE=y, HOTPLUG_PCI_SGI=y, SGI_TIOCX=y, BLK_DEV_SGIIOC4=m, SERIAL_SGI_IOC4=m, MMTIMER=m, SCSI_QLOGIC_1280=m seen in `debian/config/ia64/config`; machine type not in fragment, IA64_GENERIC inferred from the Kconfig default | netinst 258M; CD-1/2/3 646M/647M/628M; DVD-1 4.4G; update CDs 1-12 | https://cdimage.debian.org/mirror/cdimage/archive/7.11.0/ia64/iso-cd/ , https://cdimage.debian.org/cdimage/archive/7.11.0/ia64/iso-dvd/ |
| CentOS 4.7 ia64 (RHEL 4) | 2.6.9 | not read; RHEL ia64 kernels are generic (see RHEL 5 row) | bin1of4 622M, 2of4 638M, 3of4 622M, 4of4 434M | https://vault.centos.org/4.9/isos/ia64/ (path says 4.9, files are 4.7) |
| CentOS 4.6 ia64 | 2.6.9 | same | CD set 628M/638M/638M/411M; DVD 2.3G | https://mirrors.ircam.fr/pub/CentOS-vault/4.6/isos/ia64/ |
| CentOS 3.9 ia64 (RHEL 3) | 2.4.21 | not read | not read | https://vault.centos.org/3.9/isos/ (ia64/ dir exists, dated 2006-10-30) |
| CentOS 5 ia64 | n/a | none: vault 5.11 has only i386 and x86_64 | n/a | https://vault.centos.org/5.11/isos/ |
| RHEL 5 ia64 (config only) | 2.6.18 | OpenVZ rhel5-2.6.18 ia64 config: IA64_GENERIC=y, SGI_SN2 not set | no ISO found | https://mirror.clientvps.com/openvz/kernel/branches/rhel5-2.6.18/028stab119.2/configs/kernel-2.6.18-ia64.config.ovz |
| Fedora 9 ia64 (only Fedora release with ia64 in the archive) | 2.6.25 | not read, GENERIC inferred | DVD 3.0G; discs 1-5 618M/635M/632M/638M/567M; netinst 145M | https://mirror1.hs-esslingen.de/Mirrors/archive.fedoraproject.org/fedora-secondary/releases/9/Fedora/ia64/iso/ |
| Fedora 11-13 secondary | n/a | no ia64 tree (arm, mips, sparc only) | n/a | https://mirror1.hs-esslingen.de/Mirrors/archive.fedoraproject.org/fedora-secondary/releases/ |
| Gentoo ia64 minimal install ISO | user-built (genkernel) | depends on the config you choose | 167M (2024-04-04); stage3 tarballs to 2024-04-26 | https://ftp.fau.de/gentoo/releases/ia64/autobuilds/current-install-ia64-minimal/ |
| SLES 9 ia64 RC5 (Novell, 2004) | 2.6.5 | not read | CD1-CD6, sizes not stated, probably no longer served | http://support.novell.com/techcenter/psdb/ade33678802fc5fc52e5750ee0e26230.html |
| SLES 10/11 ia64 | 2.6.16 / 2.6.27 | n/a | no public ISO found (archive.org `sles-10-intel` is x86) | n/a |
| Scientific Linux ia64 | 2.4.21 (SL 3) | n/a | SL 3.0.2 RC1 only, FTP gone | Fermilab list post (listserv.fnal.gov, June 2004) |

Pages read: cdimage.debian.org 7.11.0 ia64 iso-cd listing; sources.debian.org linux 3.2.78-1 debian/config/ia64 (config, config.itanium); www.debian.org wheezy ia64 release notes; vault.centos.org 3.9, 4.9, 5.11 listings; archive.kernel.org/centos-vault; mirrors.ircam.fr 4.6 ia64 listing; mirror1.hs-esslingen.de Fedora secondary 9, 11, 12, 13 listings; fedoraproject.org wiki Architectures/IA64/F9Relnotes; ftp.fau.de Gentoo ia64 autobuilds; support.novell.com SLES 9 ia64 RC5 page; mirror.clientvps.com OpenVZ RHEL5 ia64 config (via search summary only). dl.fedoraproject.org and archives.fedoraproject.org returned an Anubis block page.

Uncertain items: the machine-type choice in the Debian, CentOS 4 and Fedora 9 kernels; whether Debian's installer writes `console=ttySG0`; whether the Altix 350 uses SHub 1 or SHub 2; whether the ISOs' El Torito catalogues work in PROM 10.54 as-is.

