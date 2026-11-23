<!-- generated from devices/piix4/registers.toml by defs-gen - do not edit, change the source -->
<!-- defs-gen 3 -->
<!-- input sha256 9419598440ab2c5e0a78081f4f4024eecd7686d44a9b3e8d221f0b1de5cd234d -->

# Intel 82371AB PIIX4 (PCI-to-ISA bridge, IDE, USB, power management and SMBus) as wired in the Visual Workstation 320 and 540

Register contract of the PIIX4 southbridge, functions 0 to 3, from the published datasheet and specification update, with the board wiring taken from the system firmware, the Windows NT hardware abstraction layer and the Linux Visual Workstation code. Grades: established means a datasheet or specification update page states it (the page is cited) or the shipped firmware and HAL do it in a routine read in full, which is a software expectation and not a measurement; inferred means a reasoned reading; unknown means no held source settles it. The update corrects the datasheet and wins where they differ. Config-space registers are in one space per PCI function (f0 ISA bridge, f1 IDE, f2 USB, f3 power management and SMBus). The power management block (pm), the SMBus block (smb), the IDE bus-master block (bm) and the fixed ISA ports (isa) are I/O spaces whose base is programmed in config space. Not listed: the 8259, 8254 and DMA controller registers (standard parts at their PC ports), the USB host controller I/O registers (no held software touches them at register level), and the device-monitor registers of function 3 (offsets 0x50 to 0x7f and the device activity and resource registers), which no held software writes.

Unit `piix4`, macro prefix `PIIX4`.

Every item has a grade: established, inferred or unknown. A grade says how the item was derived from its source; it does not claim the item was measured on silicon.

## Address spaces

| Space | Offset unit | Description |
|---|---|---|
| piix4_f0 | byte | PCI function 0 (PCI-to-ISA bridge) configuration space, byte offsets. On the board it is device 4 of the Lithium bridge B bus, reached through bridge B's configuration window. |
| piix4_f1 | byte | PCI function 1 (IDE controller) configuration space, byte offsets. |
| piix4_f2 | byte | PCI function 2 (USB host controller) configuration space, byte offsets. |
| piix4_f3 | byte | PCI function 3 (power management and SMBus) configuration space, byte offsets. |
| piix4_pm | byte | Power management I/O block: base from PMBA (function 3 offset 0x40). The firmware programs the base 0xf80. |
| piix4_smb | byte | SMBus host and slave I/O block: base from SMBBA (function 3 offset 0x90). The firmware programs the base 0xfd0. |
| piix4_bm | byte | IDE bus-master I/O block: base from BMIBA (function 1 offset 0x20); primary channel at +0, secondary at +8. |
| piix4_isa | byte | Fixed ISA-compatible I/O ports the PIIX4 decodes itself (absolute port numbers). |

## Registers

| Register | Offset | Access | Width | Count | Space | Reset | Grade | Source |
|---|---|---|---|---|---|---|---|---|
| `bm_cmd` | 0x0 | rw | 8 |  | piix4_bm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.99) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.99 |
| `bm_status` | 0x2 | rw | 8 |  | piix4_bm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.100) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.100 |
| `bm_prd` | 0x4 | rw | 32 |  | piix4_bm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.101) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.101 |
| `bm_cmd_sec` | 0x8 | rw | 8 |  | piix4_bm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.99) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.99 |
| `bm_status_sec` | 0xa | rw | 8 |  | piix4_bm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.100) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.100 |
| `bm_prd_sec` | 0xc | rw | 32 |  | piix4_bm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.101) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.101 |
| `f0_vid` | 0x0 | r | 16 |  | piix4_f0 | 0x8086 (Intel 82371AB datasheet 290562-001 (April 1997) p.53) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.53 |
| `f0_did` | 0x2 | r | 16 |  | piix4_f0 | 0x7110 (Intel 82371AB datasheet 290562-001 (April 1997) p.53) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.53 |
| `f0_pcicmd` | 0x4 | rw | 16 |  | piix4_f0 | 0x7 (Intel 82371AB datasheet 290562-001 (April 1997) p.54) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.54 |
| `f0_pcists` | 0x6 | rw | 16 |  | piix4_f0 | 0x280 (Intel 82371AB datasheet 290562-001 (April 1997) p.55) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.55 |
| `f0_rid` | 0x8 | r | 8 |  | piix4_f0 | unknown | established | Intel 82371AB datasheet 290562-001 (April 1997) p.55 |
| `f0_classc_pi` | 0x9 | r | 8 |  | piix4_f0 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.56) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.56 |
| `f0_classc_scc` | 0xa | r | 8 |  | piix4_f0 | 0x1 (Intel 82371AB datasheet 290562-001 (April 1997) p.56) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.56 |
| `f0_classc_basec` | 0xb | r | 8 |  | piix4_f0 | 0x6 (Intel 82371AB datasheet 290562-001 (April 1997) p.56) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.56 |
| `f0_hedt` | 0xe | r | 8 |  | piix4_f0 | 0x80 (Intel 82371AB datasheet 290562-001 (April 1997) p.56) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.56 |
| `f0_iort` | 0x4c | rw | 8 |  | piix4_f0 | 0x4d (Intel 82371AB datasheet 290562-001 (April 1997) p.56) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.57 |
| `f0_xbcs` | 0x4e | rw | 16 |  | piix4_f0 | 0x3 (Intel 82371AB datasheet 290562-001 (April 1997) p.57) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.57-58 |
| `f0_pirqrc` | 0x60 | rw | 8 | 4 | piix4_f0 | 0x80 (Intel 82371AB datasheet 290562-001 (April 1997) p.59) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.59 |
| `f0_serirqc` | 0x64 | rw | 8 |  | piix4_f0 | 0x10 (Intel 82371AB datasheet 290562-001 (April 1997) p.59) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.59 |
| `f0_tom` | 0x69 | rw | 8 |  | piix4_f0 | 0x2 (Intel 82371AB datasheet 290562-001 (April 1997) p.60) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.60 |
| `f0_mstat` | 0x6a | rw | 16 |  | piix4_f0 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.61) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.61 |
| `f0_mbdma` | 0x76 | rw | 8 | 2 | piix4_f0 | 0x4 (Intel 82371AB datasheet 290562-001 (April 1997) p.61) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.61 |
| `f0_apicbase` | 0x80 | rw | 8 |  | piix4_f0 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.62) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.62 |
| `f0_dlc` | 0x82 | rw | 8 |  | piix4_f0 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.62) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.62-63 |
| `f0_pdmacfg` | 0x90 | rw | 16 |  | piix4_f0 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.63) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.63-64 |
| `f0_ddmabp` | 0x92 | rw | 16 | 2 | piix4_f0 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.64) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.64 |
| `f0_gencfg` | 0xb0 | rw | 32 |  | piix4_f0 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.65) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 |
| `f0_rtccfg` | 0xcb | rw | 8 |  | piix4_f0 | 0x21 (Intel 82371AB datasheet 290562-001 (April 1997) p.67) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.67-68 |
| `f1_vid` | 0x0 | r | 16 |  | piix4_f1 | 0x8086 (Intel 82371AB datasheet 290562-001 (April 1997) p.89) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.89 |
| `f1_did` | 0x2 | r | 16 |  | piix4_f1 | 0x7111 (Intel 82371AB datasheet 290562-001 (April 1997) p.89) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.89 |
| `f1_pcicmd` | 0x4 | rw | 16 |  | piix4_f1 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.89) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.89-90 |
| `f1_pcists` | 0x6 | rw | 16 |  | piix4_f1 | 0x280 (Intel 82371AB datasheet 290562-001 (April 1997) p.90) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.90 |
| `f1_rid` | 0x8 | r | 8 |  | piix4_f1 | unknown | established | Intel 82371AB datasheet 290562-001 (April 1997) p.91 |
| `f1_classc_pi` | 0x9 | r | 8 |  | piix4_f1 | 0x80 (Intel 82371AB datasheet 290562-001 (April 1997) p.91) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.91 |
| `f1_classc_scc` | 0xa | r | 8 |  | piix4_f1 | 0x1 (Intel 82371AB datasheet 290562-001 (April 1997) p.91) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.91 |
| `f1_classc_basec` | 0xb | r | 8 |  | piix4_f1 | 0x1 (Intel 82371AB datasheet 290562-001 (April 1997) p.91) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.91 |
| `f1_mlt` | 0xd | rw | 8 |  | piix4_f1 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.91) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.91 |
| `f1_hedt` | 0xe | r | 8 |  | piix4_f1 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.92) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.92 |
| `f1_bmiba` | 0x20 | rw | 32 |  | piix4_f1 | 0x1 (Intel 82371AB datasheet 290562-001 (April 1997) p.92) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.92 |
| `f1_idetim` | 0x40 | rw | 16 | 2 | piix4_f1 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.93) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 |
| `f1_sidetim` | 0x44 | rw | 8 |  | piix4_f1 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.95) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.95 |
| `f1_udmactl` | 0x48 | rw | 8 |  | piix4_f1 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.96) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.96 |
| `f1_udmatim` | 0x4a | rw | 16 |  | piix4_f1 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.96) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.96-97 |
| `f2_vid` | 0x0 | r | 16 |  | piix4_f2 | 0x8086 (Intel 82371AB datasheet 290562-001 (April 1997) p.102) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.102 |
| `f2_did` | 0x2 | r | 16 |  | piix4_f2 | 0x7112 (Intel 82371AB datasheet 290562-001 (April 1997) p.102) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.102 |
| `f2_pcicmd` | 0x4 | rw | 16 |  | piix4_f2 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.103) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.103 |
| `f2_pcists` | 0x6 | rw | 16 |  | piix4_f2 | 0x280 (Intel 82371AB datasheet 290562-001 (April 1997) p.103) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.103-104 |
| `f2_rid` | 0x8 | r | 8 |  | piix4_f2 | unknown | established | Intel 82371AB datasheet 290562-001 (April 1997) p.104 |
| `f2_classc_pi` | 0x9 | r | 8 |  | piix4_f2 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.104) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.104 |
| `f2_classc_scc` | 0xa | r | 8 |  | piix4_f2 | 0x3 (Intel 82371AB datasheet 290562-001 (April 1997) p.104) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.104 |
| `f2_classc_basec` | 0xb | r | 8 |  | piix4_f2 | 0xc (Intel 82371AB datasheet 290562-001 (April 1997) p.104) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.104 |
| `f2_mlt` | 0xd | rw | 8 |  | piix4_f2 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.105) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.105 |
| `f2_hedt` | 0xe | r | 8 |  | piix4_f2 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.105) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.105 |
| `f2_usbba` | 0x20 | rw | 32 |  | piix4_f2 | 0x1 (inferred) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.108 |
| `f2_intln` | 0x3c | rw | 8 |  | piix4_f2 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.105) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.105 |
| `f2_intpn` | 0x3d | r | 8 |  | piix4_f2 | 0x4 (Intel 82371AB datasheet 290562-001 (April 1997) p.106) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.106 |
| `f2_sbrnum` | 0x60 | r | 8 |  | piix4_f2 | 0x10 (Intel 82371AB datasheet 290562-001 (April 1997) p.106) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.106 |
| `f2_legsup` | 0xc0 | rw | 16 |  | piix4_f2 | 0x2000 (Intel 82371AB datasheet 290562-001 (April 1997) p.107) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.107-108 |
| `f2_miscsup` | 0xff | rw | 8 |  | piix4_f2 | unknown | established | Intel 82371AB datasheet 290562-001 (April 1997) p.109 |
| `f3_vid` | 0x0 | r | 16 |  | piix4_f3 | 0x8086 (Intel 82371AB datasheet 290562-001 (April 1997) p.117) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.117 |
| `f3_did` | 0x2 | r | 16 |  | piix4_f3 | 0x7113 (Intel 82371AB datasheet 290562-001 (April 1997) p.117) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.117 |
| `f3_pcicmd` | 0x4 | rw | 16 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.117) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.117-118 |
| `f3_pcists` | 0x6 | rw | 16 |  | piix4_f3 | 0x280 (Intel 82371AB datasheet 290562-001 (April 1997) p.118) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.118 |
| `f3_rid` | 0x8 | r | 8 |  | piix4_f3 | unknown | established | Intel 82371AB datasheet 290562-001 (April 1997) p.119 |
| `f3_classc_pi` | 0x9 | r | 8 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.119) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.119 |
| `f3_classc_scc` | 0xa | r | 8 |  | piix4_f3 | 0x80 (Intel 82371AB datasheet 290562-001 (April 1997) p.119) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.119 |
| `f3_classc_basec` | 0xb | r | 8 |  | piix4_f3 | 0x6 (Intel 82371AB datasheet 290562-001 (April 1997) p.119) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.119 |
| `f3_hedt` | 0xe | r | 8 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.119) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.119 |
| `f3_intln` | 0x3c | rw | 8 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.120) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.120 |
| `f3_intpn` | 0x3d | r | 8 |  | piix4_f3 | 0x0 (Intel 82371AB specification update 297738-017 (January 2002) p.13) | established | Intel 82371AB specification update 297738-017 (January 2002) p.13 |
| `f3_pmba` | 0x40 | rw | 32 |  | piix4_f3 | 0x1 (Intel 82371AB datasheet 290562-001 (April 1997) p.120) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.120 |
| `f3_cnta` | 0x44 | rw | 32 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.121) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.121 |
| `f3_cntb` | 0x48 | rw | 32 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.121) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.121-122 |
| `f3_gpictl` | 0x4c | rw | 32 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.123) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.123 |
| `f3_pmregmisc` | 0x80 | rw | 8 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.134) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.134 |
| `f3_smbba` | 0x90 | rw | 32 |  | piix4_f3 | 0x1 (Intel 82371AB datasheet 290562-001 (April 1997) p.135) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.135 |
| `f3_smbhstcfg` | 0xd2 | rw | 8 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.135) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.135 |
| `f3_smbslvc` | 0xd3 | rw | 8 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.135) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.135 |
| `f3_smbshdw1` | 0xd4 | rw | 8 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.136) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.136 |
| `f3_smbshdw2` | 0xd5 | rw | 8 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.136) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.136 |
| `f3_smbrev` | 0xd6 | r | 8 |  | piix4_f3 | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.136) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.136 |
| `rirq` | 0x60 | r | 8 |  | piix4_isa | unknown | established | Intel 82371AB datasheet 290562-001 (April 1997) p.86 |
| `nmisc` | 0x61 | rw | 8 |  | piix4_isa | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.83) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.83 |
| `rtci` | 0x70 | w | 8 |  | piix4_isa | unknown | established | Intel 82371AB datasheet 290562-001 (April 1997) p.84-85 |
| `rtcd` | 0x71 | rw | 8 |  | piix4_isa | unknown | established | Intel 82371AB datasheet 290562-001 (April 1997) p.85 |
| `rtcei` | 0x72 | w | 8 |  | piix4_isa | unknown | established | Intel 82371AB datasheet 290562-001 (April 1997) p.85 |
| `rtced` | 0x73 | rw | 8 |  | piix4_isa | unknown | established | Intel 82371AB datasheet 290562-001 (April 1997) p.85 |
| `p92` | 0x92 | rw | 8 |  | piix4_isa | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.87) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.87 |
| `apmc` | 0xb2 | rw | 8 |  | piix4_isa | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.86) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.86 |
| `apms` | 0xb3 | rw | 8 |  | piix4_isa | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.86) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.86 |
| `cerr` | 0xf0 | w | 8 |  | piix4_isa | unknown | established | Intel 82371AB datasheet 290562-001 (April 1997) p.87 |
| `rc` | 0xcf9 | rw | 8 |  | piix4_isa | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.88) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.88 |
| `pmsts` | 0x0 | rw | 16 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.137) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.137 |
| `pmen` | 0x2 | rw | 16 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.138) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.138 |
| `pmcntrl` | 0x4 | rw | 16 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.138) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.138-139 |
| `pmtmr` | 0x8 | r | 32 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.139) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.139 |
| `gpsts` | 0xc | rw | 16 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.139) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.139-140 |
| `gpen` | 0xe | rw | 16 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.140) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.140 |
| `pcntrl` | 0x10 | rw | 32 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.141) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.141 |
| `plvl2` | 0x14 | r | 8 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.142) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.142 |
| `plvl3` | 0x15 | r | 8 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.142) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.142 |
| `glbsts` | 0x18 | rw | 16 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.143) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.143 |
| `devsts` | 0x1c | rw | 32 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.144) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.144 |
| `glben` | 0x20 | rw | 16 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.144) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.144 |
| `glbctl` | 0x28 | rw | 32 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.145) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.145 |
| `devctl` | 0x2c | rw | 32 |  | piix4_pm | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.146) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.146-147 |
| `gpireg` | 0x30 | r | 32 |  | piix4_pm | unknown | established | Intel 82371AB datasheet 290562-001 (April 1997) p.147 |
| `gporeg` | 0x34 | rw | 32 |  | piix4_pm | 0x7fffbfff (established; Intel 82371AB datasheet 290562-001 (April 1997) p.148 (default 7FFFBFFFh) and Intel 82371AB specification update 297738-017 (January 2002) p.23 (erratum 3, per-bit table)) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 |
| `smbhststs` | 0x0 | rw | 8 |  | piix4_smb | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.148) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.148-149 |
| `smbslvsts` | 0x1 | rw | 8 |  | piix4_smb | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.149) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.149 |
| `smbhstcnt` | 0x2 | rw | 8 |  | piix4_smb | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.150) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.150 |
| `smbhstcmd` | 0x3 | rw | 8 |  | piix4_smb | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.150) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.150 |
| `smbhstadd` | 0x4 | rw | 8 |  | piix4_smb | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.151) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.151 |
| `smbhstdat0` | 0x5 | rw | 8 |  | piix4_smb | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.151) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.151 |
| `smbhstdat1` | 0x6 | rw | 8 |  | piix4_smb | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.151) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.151 |
| `smbblkdat` | 0x7 | rw | 8 |  | piix4_smb | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.152) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.152 |
| `smbslvcnt` | 0x8 | rw | 8 |  | piix4_smb | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.152) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.152 |
| `smbshdwcmd` | 0x9 | r | 8 |  | piix4_smb | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.153) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.153 |
| `smbslvevt` | 0xa | rw | 16 |  | piix4_smb | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.153) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.153 |
| `smbslvdat` | 0xc | r | 16 |  | piix4_smb | 0x0 (Intel 82371AB datasheet 290562-001 (April 1997) p.153) | established | Intel 82371AB datasheet 290562-001 (April 1997) p.153 |

### Register `bm_cmd`

Bus-master IDE command, primary channel; the secondary channel's is at +8 (bm_cmd_sec).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `rw` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.99 | 0 reads from the drive, 1 writes to it. |
| 0 | `start` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.99 | 1 starts bus-master operation. |

### Register `bm_status`

Bus-master IDE status, primary channel; secondary channel's copy is at offset 0x0a.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `dma1_cap` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.100 | Drive 1 DMA capable (software flag). |
| 5 | `dma0_cap` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.100 | Drive 0 DMA capable (software flag). |
| 2 | `irq` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.100 | IDE interrupt status, write 1 to clear. |
| 1 | `error` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.100 | DMA error, write 1 to clear. |
| 0 | `active` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.100 | Bus-master active, read only. |

### Register `bm_prd`

Descriptor table pointer, primary channel; secondary channel's copy is at offset 0x0c.

### Register `bm_cmd_sec`

Bus-master IDE command, secondary channel.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `rw` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.99 | 0 reads from the drive, 1 writes to it. |
| 0 | `start` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.99 | 1 starts bus-master operation. |

### Register `bm_status_sec`

Bus-master IDE status, secondary channel.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `dma1_cap` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.100 | Drive 1 DMA capable (software flag). |
| 5 | `dma0_cap` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.100 | Drive 0 DMA capable (software flag). |
| 2 | `irq` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.100 | IDE interrupt status, write 1 to clear. |
| 1 | `error` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.100 | DMA error, write 1 to clear. |
| 0 | `active` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.100 | Bus-master active, read only. |

### Register `bm_prd_sec`

Descriptor table pointer, secondary channel.

### Register `f0_vid`

Vendor identification, Intel.

### Register `f0_did`

Device identification of function 0. The firmware's self-test reads the function 0 vendor and device words as one dword and expects 0x71108086.

### Register `f0_pcicmd`

PCI command. The firmware writes 0x0f once. Bits 2 to 0 are hardwired to 1 and the bits the datasheet marks not implemented read 0, so the write leaves special cycle enable (bit 3) and SERR enable unchanged except bit 3 set; the special cycle enable is what lets the chip see the shutdown special cycle that Linux sends before powering off. The read-only mask lists the hardwired and reserved bits; only the fields shown are writable.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 8 | `serre` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.54 | SERR# enable. |
| 3 | `sce` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.54 | Special cycle enable: 1 makes the chip recognise PCI shutdown special cycles and assert INIT. |
| 2 | `bus_master` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.54 | Hardwired 1. |
| 1 | `memory` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.54 | Hardwired 1. |
| 0 | `io_space` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.54 | Hardwired 1: the function always answers I/O cycles. |

### Register `f0_pcists`

PCI status. Bits 14 to 11 are write-1-to-clear; DEVSEL# timing is medium (01).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 14 | `sig_serr` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.55 | Signalled SERR#, write 1 to clear. |
| 13 | `master_abort` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.55 | Master abort received, write 1 to clear. |
| 12 | `rcv_target_abort` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.55 | Target abort received, write 1 to clear. |
| 11 | `sig_target_abort` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.55 | Target abort signalled, write 1 to clear. |
| 10:9 | `devsel` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.55 | DEVSEL# timing, always 01 (medium). |
| 7 | `fast_b2b` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.55 | Fast back-to-back capable, read only. |

### Register `f0_rid`

Revision. Stepping 00h initially; the specification update lists later values. Which stepping the board carries is not known.

### Register `f0_classc_pi`

Class code, programming interface byte, 0x00. The PROM's register walk reads this dword once and discards the result.

### Register `f0_classc_scc`

Class code, sub-class byte: 0x01 (PCI-to-ISA bridge) while GENCFG bit 1 selects subtractive decode, 0x80 (other bridge) when it selects positive decode.

### Register `f0_classc_basec`

Class code, base class byte, 0x06 (bridge).

### Register `f0_hedt`

Header type, 0x80: a multifunction device. Functions 1 to 3 read their own header type as 0.

### Register `f0_iort`

ISA I/O recovery timer. Reset enables 8-bit and 16-bit recovery with one SYSCLK added to the 3.5 SYSCLK minimum. Not written by any held software.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `dmaac` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57 | DMA reserved page register aliasing control. |
| 6 | `rec8_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57 | 8-bit I/O recovery enable. |
| 5:3 | `rec8` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57 | Additional SYSCLKs of 8-bit recovery when enabled (001 is 1 ... 111 is 7, 000 is 8). |
| 2 | `rec16_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57 | 16-bit I/O recovery enable. |
| 1:0 | `rec16` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57 | Additional SYSCLKs of 16-bit recovery (00 is 3, 01 is 1, 10 is 2, 11 is 4). |

### Register `f0_xbcs`

X-bus chip select. The PROM writes the byte 0xf4: that sets the extended BIOS, lower BIOS, BIOSCS# write enable, coprocessor error and mouse functions and clears bits 1 and 0, the external keyboard and RTC chip selects (a software expectation). Clearing them while the Super I/O keyboard controller decodes its own ports is consistent with the board using the Super I/O's keyboard controller (inferred). Bit 9 and bit 7 forward the flash regions 0xfff00000 to 0xfff7ffff and 0xfff80000 to 0xfffdffff to the BIOS chip select; the top 64 KiB is always decoded. Which chip select the flash sits on is not stated by any source.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 10 | `mc_loc` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57-58 | Microcontroller address location enable (ports 0x62 and 0x66). |
| 9 | `bios_1meg` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57-58 | 1-Meg extended BIOS enable: 0xfff00000 to 0xfff7ffff. |
| 8 | `apic_cs` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57-58 | APIC chip select; also selects GPI5, GPO12 to GPO14 and GPO29 versus the APIC functions. |
| 7 | `ext_bios` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57-58 | Extended BIOS enable: 0xfff80000 to 0xfffdffff. |
| 6 | `lower_bios` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57-58 | Lower BIOS enable: 0xe0000 to 0xeffff and 0xfffe0000 to 0xfffeffff. |
| 5 | `coproc_err` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57-58 | Coprocessor error function (FERR# raises internal IRQ13). |
| 4 | `mouse` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57-58 | IRQ12/M mouse function. |
| 3 | `port61_alias` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57-58 | Alias ports 0x63, 0x65 and 0x67 to 0x61. |
| 2 | `bioscs_wp` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57-58 | 1 asserts BIOSCS# for writes as well as reads in the decoded BIOS regions. |
| 1 | `kbccs_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57-58 | KBCCS# and XOE# for ports 0x60 and 0x64. |
| 0 | `rtccs_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.57-58 | RTCCS#/RTCALE and XOE# for ports 0x70 to 0x77. |

### Register `f0_pirqrc`

PIRQ[A:D]# route control, one byte each at 0x60 to 0x63. The PROM writes 0x09 to the first (route PIRQA# to IRQ9). The routed IRQ must be level sensitive.

Array of 4 registers, stride 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `route_off` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.59 | 0 enables the route, 1 disables it. |
| 3:0 | `irq` | established | irq3=3, irq4=4, irq5=5, irq6=6, irq7=7, irq9=9, irq10=10, irq11=11, irq12=12, irq14=14, irq15=15 | Intel 82371AB datasheet 290562-001 (April 1997) p.59 | IRQ the PIRQ line is routed to when enabled; other values are reserved. |

### Register `f0_serirqc`

Serial IRQ control. Not written by the PROM; GENCFG bit 16 must also select SERIRQ for it to take effect.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `enable` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.59 | Serial IRQ enable. |
| 6 | `continuous` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.59 | 1 continuous mode, 0 quiet mode. |
| 5:2 | `frame_size` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.59 | Frame size; only 0100 (21 slots) is supported. |
| 1:0 | `start_width` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.59 | Start frame pulse width: 4, 6 or 8 PCI clocks. |

### Register `f0_tom`

Top of memory and ISA/DMA forwarding. The PROM writes 0xf2: top of memory 16 MB and the 512-640 KB region forwarded to PCI.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7:4 | `top` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.60 | Top of ISA-accessible memory in 1 MB steps, 0000 is 1 MB, 1111 is 16 MB. |
| 3 | `lower_bios_fwd` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.60 | Forward ISA/DMA accesses to the lower BIOS region to PCI (when XBCS bit 6 is 0). |
| 2 | `a0000_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.60 | Forward ISA master and DMA cycles to 0xa0000 to 0xbffff to PCI. |
| 1 | `low512_fwd` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.60 | Forward 512-640 KB ISA master and DMA cycles to PCI. |

### Register `f0_mstat`

Miscellaneous status.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `serr_dtt` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.61 | SERR# generated by a delayed transaction time-out, write 1 to clear. |
| 7 | `host_retry` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.61 | Retry CPU-initiated non-locked PCI cycles without a delayed transaction. |

### Register `f0_mbdma`

Motherboard device DMA control, 0x76 and 0x77. The PROM writes 0x0c to both, which is the disabled channel (100) with the bit the datasheet says reads 1. The datasheet gives the default as 04h while saying bit 3 reads as 1; the two do not agree.

Array of 2 registers, stride 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `fast` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.61 | Type F DMA and 4-byte buffer enable for the channel selected below. |
| 3 | `one` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.61 | Reserved, read as 1. |
| 2:0 | `chnl` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.61 | DMA channel for type F transfers; 100 is disabled. |

### Register `f0_apicbase`

APIC base address relocation (the I/O APIC window follows the Intel 0xfec0 base). Not written by held software.

### Register `f0_dlc`

Deterministic latency control: delayed transaction, passive release and SERR# generation enables. Not written by held software.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `serr_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.62-63 | SERR# on delayed transaction time-out. |
| 2 | `usb_pr` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.62-63 | USB passive release enable. |
| 1 | `passive_release` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.62-63 | Passive release enable. |
| 0 | `delayed_txn` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.62-63 | Delayed transaction enable. |

### Register `f0_pdmacfg`

PCI DMA configuration: the DMA type of each channel. Channel 4 is the cascade and has no field. The PROM bit-walks the byte at 0x90 and the one at 0x95 (high byte of the channel 5 to 7 pointer) in its function 0 register test, and the walked bytes hold every pattern on the real board.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:14 | `ch7` | established | normal_isa=0, pc_pci=1, distributed=2 | Intel 82371AB datasheet 290562-001 (April 1997) p.63-64 | Channel 7 type. |
| 13:12 | `ch6` | established | normal_isa=0, pc_pci=1, distributed=2 | Intel 82371AB datasheet 290562-001 (April 1997) p.63-64 | Channel 6 type. |
| 11:10 | `ch5` | established | normal_isa=0, pc_pci=1, distributed=2 | Intel 82371AB datasheet 290562-001 (April 1997) p.63-64 | Channel 5 type. |
| 7:6 | `ch3` | established | normal_isa=0, pc_pci=1, distributed=2 | Intel 82371AB datasheet 290562-001 (April 1997) p.63-64 | Channel 3 type. |
| 5:4 | `ch2` | established | normal_isa=0, pc_pci=1, distributed=2 | Intel 82371AB datasheet 290562-001 (April 1997) p.63-64 | Channel 2 type. |
| 3:2 | `ch1` | established | normal_isa=0, pc_pci=1, distributed=2 | Intel 82371AB datasheet 290562-001 (April 1997) p.63-64 | Channel 1 type. |
| 1:0 | `ch0` | established | normal_isa=0, pc_pci=1, distributed=2 | Intel 82371AB datasheet 290562-001 (April 1997) p.63-64 | Channel 0 type. |

### Register `f0_ddmabp`

Distributed DMA slave base pointers: 0x92 for channels 0 to 3, 0x94 for channels 5 to 7; bits 15:6 are I/O address bits. The PROM bit-walks bytes 0x93 and 0x95 of these.

Array of 2 registers, stride 2.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:6 | `base` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.64 | I/O address bits 15 to 6 of the 64-byte slave register window. |

### Register `f0_gencfg`

General configuration: pin function selects and bus mode. The PROM writes the bytes 0x4d (register 0xb0) and 0x60 (register 0xb3). 0x4d sets bit 0 (ISA mode, so the pins carry IOCHK# and LA[23:17] and are not GPI0 and GPO[7:1]), bit 6 (positive decode of the Plug and Play ports 0x279 and 0xa79) and the read-only bits 2 and 3, which stay as the straps set them. 0x60 sets bits 30 and 29, turning the RTCALE and RTCCS# pins into outputs GPO25 and GPO24. Bit 29 is printed as 'GPO2' in the datasheet and is GPO24 in its GPO table (a datasheet inconsistency). Tables 1 and 2 label the register 'PCI Function 1' but it is a function 0 register.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 31 | `kbccs_gpo26` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 KBCCS# (default), 1 GPO26. |
| 30 | `rtcale_gpo25` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 RTCALE (default), 1 GPO25. |
| 29 | `rtccs_gpo24` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 RTCCS# (default), 1 GPO24. |
| 28 | `xoe_gpo` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 XOE#/XDIR# (default), 1 GPO23/GPO22. |
| 27 | `ri_gpi12` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 RI# (default), 1 GPI12. |
| 25 | `lid_gpi10` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 LID (default), 1 GPI10. |
| 24 | `batlow_gpi9` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 BATLOW# (default), 1 GPI9. |
| 23 | `thrm_gpi8` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 THRM# (default), 1 GPI8. |
| 22 | `susstat2_gpo` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 SUS_STAT2# (default), 1 GPO21. |
| 21 | `susstat1_gpo` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 SUS_STAT1# (default), 1 GPO20. |
| 20 | `zz_gpo` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 ZZ (default), 1 GPO19. |
| 19 | `pcistp_gpo` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 PCI_STP# (default), 1 GPO18. |
| 18 | `cpustp_gpo` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 CPU_STP# (default), 1 GPO17. |
| 17 | `susbc_gpo` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 SUSB#/SUSC# (default), 1 GPO15/GPO16. |
| 16 | `serirq_sel` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 GPI7 (default), 1 SERIRQ. |
| 15 | `smbalert_sel` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 SMBALERT# (default), 1 GPI11. |
| 14 | `irq8_sel` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 GPI6 (default), 1 IRQ8# pin. The specification update says to select GPI6 when the internal RTC is used. |
| 12 | `sec_ide_tristate` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 1 tri-states the secondary IDE interface. |
| 11 | `pri_ide_tristate` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 1 tri-states the primary IDE interface. |
| 10 | `reqc_sel` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 GPI4 and GPO11 (default), 1 REQC#/GNTC#. |
| 9 | `reqb_sel` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 GPI3 and GPO10 (default), 1 REQB#/GNTB#. |
| 8 | `reqa_sel` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 GPI2 and GPO9 (default), 1 PC/PCI REQA#/GNTA#. |
| 6 | `pnp_decode` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | Positive decode and forwarding of the Plug and Play ports 0x279 and 0xa79. |
| 5 | `alt_access` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | Alternate access mode: exposes shadow registers. |
| 4 | `ide_split` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 primary and secondary IDE interfaces, 1 primary drive 0 and drive 1 only. |
| 3 | `config2` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | CONFIG2 pin status, read only, meaning undefined. |
| 2 | `config1` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | CONFIG1 pin status, read only: 0 Pentium, 1 Pentium II (changes INIT and CPURST polarity). The board's strap is not known. |
| 1 | `pos_decode` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 subtractive (default), 1 positive decode; changes the class code sub-class byte. |
| 0 | `isa_mode` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.65-67 | 0 EIO (default), 1 ISA; also selects IOCHK#/LA[23:17] (1) versus GPI0/GPO[7:1] (0). |

### Register `f0_rtccfg`

Real-time clock configuration. The PROM writes 0x25 (positive decode, upper bank enable, RTC enable). The HAL sets bit 2 by read-modify-write before using the extended clock RAM at ports 0x72 and 0x73. The PROM's self-test clears and sets bit 0 around its clock RAM probe. The lock bits are write-once until a hardware reset. With bit 2 clear the datasheet says the access is forwarded to ISA (RTCCFG text) and also lists ports 0x72 to 0x77 as aliases of the index and data ports (Table 5); the two statements conflict.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 5 | `pos_decode` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.67-68 | 1 positive decode of ports 0x70 to 0x73 (default), 0 subtractive. |
| 4 | `lock_upper` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.67-68 | Locks bytes 0x38 to 0x3f of the upper bank until a hardware reset. |
| 3 | `lock_lower` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.67-68 | Locks bytes 0x38 to 0x3f of the lower bank until a hardware reset. |
| 2 | `upper_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.67-68 | 1 sends ports 0x72 and 0x73 to the upper 128-byte bank; 0 forwards as bit 5 decides. |
| 0 | `rtc_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.67-68 | 1 sends ports 0x70 and 0x71 to the lower 128-byte bank; 0 forwards them to ISA. |

### Register `f1_vid`

Vendor identification, Intel.

### Register `f1_did`

Device identification of function 1.

### Register `f1_pcicmd`

PCI command. The PROM's IDE attach writes 5 (I/O space and bus master enable). The read-only mask lists the hardwired and reserved bits; only the fields shown are writable.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `bme` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.89-90 | Bus master function enable. |
| 0 | `iose` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.89-90 | I/O space enable: legacy IDE ports and the bus-master block. |

### Register `f1_pcists`

PCI status.

### Register `f1_rid`

Revision.

### Register `f1_classc_pi`

Class code, programming interface (bus master capable, both channels legacy mode).

### Register `f1_classc_scc`

Class code, sub-class: IDE.

### Register `f1_classc_basec`

Class code, base class: mass storage.

### Register `f1_mlt`

Master latency timer. The PROM's IDE attach writes 0x80.

### Register `f1_hedt`

Header type, 0: single function (multifunction is reported by function 0).

### Register `f1_bmiba`

Bus-master interface base address: I/O space, bits 15:4 are address bits, bit 0 hardwired 1.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:4 | `base` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.92 | I/O address bits 15 to 4 of the 16-byte bus-master block. |
| 0 | `rte` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.92 | Resource type indicator, hardwired 1 (I/O). |

### Register `f1_idetim`

IDE timing: 0x40 primary channel, 0x42 secondary. The PROM's IDE attach writes the dword 0xc077c077 (both channels: decode enabled, slave timing register enabled, fast timing with prefetch and IORDY sampling on both drives, ISP 5 clocks, RTC 4 clocks) and, on board type 1 (the 540, which has one IDE channel), writes the byte 0x40 to 0x43, which leaves only the slave timing enable set for the secondary channel and its decode disabled.

Array of 2 registers, stride 2.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `ide_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 | 1 positively decodes the channel's IDE register blocks; 0 decodes them subtractively to ISA. |
| 14 | `sitre` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 | Slave IDE timing register (SIDETIM) enable. |
| 13:12 | `isp` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 | IORDY sample point: 00 5 clocks, 01 4, 10 3, 11 2. |
| 9:8 | `rtc` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 | Recovery time: 00 4 clocks, 01 3, 10 2, 11 1. |
| 7 | `dte1` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 | DMA timing enable only, drive 1. |
| 6 | `ppe1` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 | Prefetch and posting enable, drive 1. |
| 5 | `ie1` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 | IORDY sample enable, drive 1. |
| 4 | `time1` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 | Fast timing bank, drive 1. |
| 3 | `dte0` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 | DMA timing enable only, drive 0. |
| 2 | `ppe0` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 | Prefetch and posting enable, drive 0. |
| 1 | `ie0` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 | IORDY sample enable, drive 0. |
| 0 | `time0` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.93-94 | Fast timing bank, drive 0. |

### Register `f1_sidetim`

Slave IDE timing (drive 1 of each channel) when IDETIM bit 14 is set. The PROM writes 0.

### Register `f1_udmactl`

Ultra DMA/33 enable per drive.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `ssde1` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.96 | Secondary drive 1. |
| 2 | `ssde0` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.96 | Secondary drive 0. |
| 1 | `psde1` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.96 | Primary drive 1. |
| 0 | `psde0` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.96 | Primary drive 0. |

### Register `f1_udmatim`

Ultra DMA/33 cycle times, two bits per drive (00 CT 4 and RP 6 PCI clocks, 01 3 and 5, 10 2 and 4).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13:12 | `sct1` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.96-97 | Secondary drive 1. |
| 9:8 | `sct0` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.96-97 | Secondary drive 0. |
| 5:4 | `pct1` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.96-97 | Primary drive 1. |
| 1:0 | `pct0` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.96-97 | Primary drive 0. |

### Register `f2_vid`

Vendor identification, Intel.

### Register `f2_did`

Device identification of function 2.

### Register `f2_pcicmd`

PCI command. The read-only mask lists the hardwired and reserved bits; only the fields shown are writable.

### Register `f2_pcists`

PCI status.

### Register `f2_rid`

Revision.

### Register `f2_classc_pi`

Class code, programming interface: OpenHCI-style USB host controller.

### Register `f2_classc_scc`

Class code, sub-class: USB.

### Register `f2_classc_basec`

Class code, base class: serial bus.

### Register `f2_mlt`

Master latency timer.

### Register `f2_hedt`

Header type, 0.

### Register `f2_usbba`

USB I/O space base address: bits 15:5, bit 0 hardwired 1. The datasheet's default of 00h disagrees with bit 0 being hardwired to 1; the reset here is 1 (inferred).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:5 | `base` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.108 | I/O address bits 15 to 5. |
| 0 | `rte` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.108 | Resource type indicator, hardwired 1 (I/O). |

### Register `f2_intln`

Interrupt line; no effect on the hardware.

### Register `f2_intpn`

Interrupt pin, hardwired 4 (INTD#). The datasheet says the USB interrupt is also ORed to PIRQD#; the board wires only this pin to its own interrupt entry, never through the 8259.

### Register `f2_sbrnum`

Serial bus release number, 0x10 (USB 1.0).

### Register `f2_legsup`

Legacy keyboard and mouse support: trap and SMI enables and status. Not written by held software.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13 | `usbpirqden` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.107-108 | USB interrupt routed to PIRQD# (default 1). |

### Register `f2_miscsup`

Miscellaneous support: bit 4 lets a read of port 0x70 return the RTC index. Byte accesses only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `rtciren` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.109 | RTC index read enable. |

### Register `f3_vid`

Vendor identification, Intel.

### Register `f3_did`

Device identification of function 3.

### Register `f3_pcicmd`

PCI command. Bit 0 enables the SMBus I/O block and works independently of PMREGMISC bit 0. The PROM's function 3 attach sets it after writing the SMBus base. The read-only mask lists the hardwired and reserved bits; only the fields shown are writable.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `iose` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.117-118 | SMBus I/O space enable. |

### Register `f3_pcists`

PCI status; the PROM's attach clears it by writing 0x3800.

### Register `f3_rid`

Revision.

### Register `f3_classc_pi`

Class code, programming interface.

### Register `f3_classc_scc`

Class code, sub-class: other bridge.

### Register `f3_classc_basec`

Class code, base class: bridge.

### Register `f3_hedt`

Header type, 0.

### Register `f3_intln`

Interrupt line. The datasheet (p.120) says it has no effect on the hardware. Specification update spec change 9 (p.15) says the register 'is not implemented and is RESERVED'.

### Register `f3_intpn`

Interrupt pin: not implemented. The datasheet (p.120) says it is read only, default 01h, and that PIRQA# is used for the power management module. Specification update spec change 1 (p.13) retitles it 'INTPN Register Not Implemented' and says: 'the INTPN register indicates the PCI interrupt pin PIRQA# is used for routing Serial Interrupts. However, Serial Interrupts are hardwired to IRQ9. This register is not implemented.' It lists bits 7:0 as Not Implemented with default 00h. The datasheet's pin A is superseded. The update says 'Serial Interrupts'; that this means the power management and SMBus interrupts is our reading (inferred). What a read returns is taken as 0 from the update's default.

### Register `f3_pmba`

Power management base address. Bits 15:6 hold the I/O base, bit 0 is hardwired 1, bits 31:16 are hardwired 0. The PROM writes 0x0f80 and the register then reads 0x0f81; the base 0xf80 is what Linux and the HAL assume. The HAL never programs it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:6 | `base` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.120 | I/O address bits 15 to 6 of the 64-byte power management block. |
| 0 | `rte` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.120 | Resource type indicator, hardwired 1 (I/O). |

### Register `f3_cnta`

Idle timer counts and resolutions for the device monitors and the slow burst count. Not written by held software.

### Register `f3_cntb`

Fast burst timer count, CPU select, thermal duty and video status. The specification update (spec change 5) corrects bit 5 to 8 microsecond granularity. Not written by held software.

### Register `f3_gpictl`

General purpose input control: enable, polarity and edge for the device-monitor GPI inputs (Table 17 maps GPI18 to GPI21 to device monitors 10 to 13). Not written by held software.

### Register `f3_pmregmisc`

Miscellaneous power management. The PROM writes 1 after the base. When the bit is clear every access to the power management block goes unclaimed.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 0 | `pmiose` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.134 | Power management I/O space enable; set after PMBA is programmed. |

### Register `f3_smbba`

SMBus base address: bits 15:4, bit 0 hardwired 1. The PROM's function 3 attach writes 0x0fd0, so the register reads 0x00000fd1 (not read back by any held software); neither HAL build touches it.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15:4 | `base` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.135 | I/O address bits 15 to 4 of the 16-byte SMBus block. |
| 0 | `rte` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.135 | Resource type indicator, hardwired 1 (I/O). |

### Register `f3_smbhstcfg`

SMBus host configuration. The PROM writes 0x09: host interface enabled and the interrupt routed to IRQ9.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3:1 | `intrsel` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.135 | Interrupt: 000 SMI#, 100 IRQ9; others reserved. |
| 0 | `host_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.135 | SMBus host interface enable. |

### Register `f3_smbslvc`

SMBus slave command match value.

### Register `f3_smbshdw1`

SMBus slave shadow port 1.

### Register `f3_smbshdw2`

SMBus slave shadow port 2.

### Register `f3_smbrev`

SMBus revision.

### Register `rirq`

Reset X-bus IRQ12/M and IRQ1: a read clears the latched mouse and keyboard interrupts; the read value has no defined pattern. Reads and writes are also sent to ISA.

### Register `nmisc`

NMI status and control. Bits 7:4 are read-only status (SERR# NMI source, IOCHK# NMI source, counter 2 output, refresh toggle) and must be written as 0.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `serr_status` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.83 | SERR# NMI source status. |
| 6 | `iochk_status` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.83 | IOCHK# NMI source status. |
| 5 | `timer2_out` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.83 | Counter 2 output state. |
| 4 | `refresh` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.83 | Refresh cycle toggle. |
| 3 | `iochk_dis` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.83 | 1 clears and disables IOCHK# NMIs. |
| 2 | `serr_dis` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.83 | 1 clears and disables PCI SERR# NMIs. |
| 1 | `spkr_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.83 | 1 drives SPKR from counter 2. |
| 0 | `timer2_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.83 | Counter 2 enable. |

### Register `rtci`

RTC index and NMI enable, shared. Bits 6:0 index the lower RTC bank and are undefined at reset (the datasheet gives only 'Bit[6:0]=undefined; Bit 7=1', p.84); bit 7 set disables NMI. Write only. The PROM and the HAL reach the clock through ports 0x70 and 0x71.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `nmi_dis` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.84-85 | 1 disables NMI generation. |
| 6:0 | `addr` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.84-85 | RTC address. |

### Register `rtcd`

RTC data, lower 128-byte bank.

### Register `rtcei`

RTC extended index: bits 6:0 address the upper bank (the datasheet lists it write only in its register page and read/write in Table 5). Bit 7 is the aliased NMI enable according to specification update spec change 2 (p.13); the datasheet calls it reserved. The upper bank is reached only with RTCCFG bit 2 set.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 7 | `nmi_dis` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.85 | Aliased NMI enable, mirrors rtci bit 7 (specification update). |
| 6:0 | `addr` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.85 | Upper bank address. |

### Register `rtced`

RTC extended data, upper 128-byte bank (battery-backed RAM).

### Register `p92`

Port 92. The PROM never writes it; the application processors set bit 1. The datasheet text says FAST_A20 set asserts A20M# low but its own table and specification update documentation change 11 (p.54) say a 1 deasserts A20M#.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 1 | `fast_a20` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.87 | 1 forces A20M# negated (A20 unmasked), 0 lets A20GATE decide (corrected by the specification update). |
| 0 | `fast_init` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.87 | Fast INIT: a write of 1 pulses INIT for about 16 PCI clocks; must be rewritten 0 before the next pulse. |

### Register `apmc`

APM control port; a write can raise an SMI#.

### Register `apms`

APM status port.

### Register `cerr`

Coprocessor error: a write asserts IGNNE# if FERR# is asserted and negates internal IRQ13; any value. Reads and writes flow through to ISA.

### Register `rc`

Reset control. Linux restarts the board by writing 0x06 (reset CPU with system reset set); the HAL does the same on all but the earliest boards. Bit 2 going 0 to 1 starts the reset; bit 1 chooses a hard reset (1) or a soft INIT-only reset (0).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 2 | `rcpu` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.88 | Reset CPU on a 0 to 1 transition; cannot be read as 1. |
| 1 | `srst` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.88 | 1 hard reset, 0 soft reset (INIT). |

### Register `pmsts`

Power management status. The HAL clears it and reads bit 8 for the power button; the PROM reads it for wake-up state and writes it back to clear.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 15 | `rsm_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.137 | Resume event occurred. |
| 11 | `pwrbtnor_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.137 | Power button held over 4 s (override). |
| 10 | `rtc_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.137 | RTC alarm. |
| 8 | `pwrbtn_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.137 | Power button pressed (16 ms debounce). |
| 5 | `gbl_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.137 | Global status (SCI from BIOS_RLS). |
| 4 | `bm_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.137 | Bus master request seen. |
| 0 | `tmrof_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.137 | Timer overflow. |

### Register `pmen`

Power management resume enable. The PROM and the HAL write 0x0100 (power button).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 10 | `rtc_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.138 | RTC resume. |
| 8 | `pwrbtn_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.138 | Power button SMI# or SCI. |
| 5 | `gbl_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.138 | Global SCI. |
| 0 | `tmrof_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.138 | Timer overflow SCI. |

### Register `pmcntrl`

Power management control. Linux powers off, and the HAL suspends, by writing 0x2000 (suspend enable with type 0, soft off). The PROM writes 0x1401 (working type, SCI enabled) at attach and 0x2000 to power down.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 13 | `sus_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.138-139 | Suspend enable, write only: enters the state in sus_typ. |
| 12:10 | `sus_typ` | established | soff=0, str=1, poscl=2, posccl=3, pos=4, working=5 | Intel 82371AB datasheet 290562-001 (April 1997) p.138-139 | Suspend type. |
| 2 | `gbl_rls` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.138-139 | Global release: raises an SMI# to the BIOS. |
| 1 | `brld_en_bm` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.138-139 | Bus-master reload enable. |
| 0 | `sci_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.138-139 | SCI enable. |

### Register `pmtmr`

Power management timer: a free-running 24-bit counter at 3.579545 MHz; bit 23 toggling sets TMROF_STS. The register summary table (p.51) lists the register as R/W while its description (p.139) says read only; this unit takes read only.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 23:0 | `tmr_val` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.139 | Timer value. |

### Register `gpsts`

General purpose status. The PROM reads it (0xf8c) for wake-up and power-fail state.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11 | `lid_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.139-140 | LID asserted. |
| 10 | `ri_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.139-140 | Ring indicate. |
| 9 | `gpi_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.139-140 | GPI1# asserted. |
| 8 | `usb_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.139-140 | USB resume. |
| 7 | `thrmor_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.139-140 | Thermal override. |
| 0 | `thrm_sts` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.139-140 | THRM# asserted. |

### Register `gpen`

General purpose enable. The PROM's function 3 attach writes 0 (0xf8e).

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 11 | `lid_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.140 | LID event. |
| 10 | `ri_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.140 | Ring resume. |
| 9 | `gpi_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.140 | GPI1# SMI#, SCI or resume. |
| 8 | `usb_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.140 | USB resume. |
| 0 | `thrm_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.140 | Thermal SMI# or SCI. |

### Register `pcntrl`

Processor control: throttling, clock control and PCI clock run enables. Not written by held software.

### Register `plvl2`

Processor level 2: a read enters stop grant or quick start.

### Register `plvl3`

Processor level 3: a read enters stop clock, sleep or deep sleep.

### Register `glbsts`

Global status. Bits 10, 8, 5, 2, 1 and 0 are write-1-to-clear; bits 7, 6 and 4 are read only summaries. Bit 11 is labelled R/W in the datasheet but also 'can only be reset by writing a 1', so it is not in the write-1-to-clear mask here (p.143).

### Register `devsts`

Device status: idle and trap status of the device monitors.

### Register `glben`

Global enable.

### Register `glbctl`

Global control: SMI enable, end of SMI, BIOS release, global standby timer.

### Register `devctl`

Device control: trap and idle enables of the device monitors.

### Register `gpireg`

General purpose input, byte reads only (offsets 0x30 to 0x32; the byte at 0x33 is not listed). Bits 21:0 are the logical value on pins GPI21 to GPI0; GPI13 to GPI21 and GPI1 are not multiplexed, the others need their select bit. A bit that is not configured as an input reads indeterminate. The register is not reset; it follows the pins. Port 0xfb2 is byte 2.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 21:18 | `board_id` | inferred |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI21 to GPI18: the board type. The firmware and Linux read (inb(0xfb2) >> 2) & 0xf and call 0 a 320 and 1 a 540. That these pins are strapped to the board type is the software's reading; no held source gives the wiring. |
| 17 | `gpi17` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI17 pin level. |
| 16 | `gpi16` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI16 pin level. |
| 15 | `gpi15` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI15 pin level. Port 0xfb1 bit 7: the boot block reads it as a floppy recovery request and the main module as a password override jumper (software expectation). |
| 14 | `gpi14` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI14 pin level. |
| 13 | `gpi13` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI13 pin level. |
| 12 | `gpi12` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI12 pin level (shared pin: reads as an input only when the select bit chooses it). |
| 11 | `gpi11` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI11 pin level (shared pin: reads as an input only when the select bit chooses it). |
| 10 | `gpi10` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI10 pin level (shared pin: reads as an input only when the select bit chooses it). |
| 9 | `gpi9` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI9 pin level (shared pin: reads as an input only when the select bit chooses it). |
| 8 | `gpi8` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI8 pin level (shared pin: reads as an input only when the select bit chooses it). |
| 7 | `gpi7` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI7 pin level (shared pin: reads as an input only when the select bit chooses it). |
| 6 | `gpi6` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI6 pin level (shared pin: reads as an input only when the select bit chooses it). |
| 5 | `gpi5` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI5 pin level (shared pin: reads as an input only when the select bit chooses it). |
| 4 | `gpi4` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI4 pin level (shared pin: reads as an input only when the select bit chooses it). |
| 3 | `gpi3` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI3 pin level (shared pin: reads as an input only when the select bit chooses it). |
| 2 | `gpi2` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI2 pin level (shared pin: reads as an input only when the select bit chooses it). |
| 1 | `gpi1` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI1 pin level. |
| 0 | `gpi0` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.147 | GPI0 pin level (shared pin: reads as an input only when the select bit chooses it). |

### Register `gporeg`

General purpose output, byte accesses only (ports 0xfb4 to 0xfb7). Bits 30:0 drive GPO30 to GPO0 and read back the last value written; a pin shared with another function follows that function until GENCFG or XBCS selects the output. The reset value 0x7fffbfff is the datasheet's default (p.148) and the specification update's erratum 3 (p.23) gives the actual value per bit: bit 31 has no output, bits 30:15 and 13:0 reset to 1 and bit 14 to 0. Port 0xfb5 therefore resets to 0xbf.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 30 | `gpo30` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO30 output. |
| 29 | `gpo29` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO29 output. |
| 28 | `gpo28` | inferred |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO28, non-multiplexed. The front-panel line: the PROM's self-test clears it, pulses it once and sets and clears it later; software only ever writes it. Whether it is an LED or a beeper is not known. |
| 27 | `gpo27` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO27 output. |
| 26 | `gpo26` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO26 output. |
| 25 | `gpo25` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO25 output. |
| 24 | `gpo24` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO24 output. |
| 23 | `gpo23` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO23 output. |
| 22 | `gpo22` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO22 output. |
| 21 | `gpo21` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO21 output. |
| 20 | `gpo20` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO20 output. |
| 19 | `gpo19` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO19 output. |
| 18 | `gpo18` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO18 output. |
| 17 | `gpo17` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO17 output. |
| 16 | `gpo16` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO16 output. |
| 15 | `gpo15` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO15 output. |
| 14 | `gpo14` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO14 output. |
| 13 | `gpo13` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO13 output. |
| 12 | `gpo12` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO12 output. |
| 11 | `gpo11` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO11 output. |
| 10 | `gpo10` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO10 output. |
| 9 | `gpo9` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO9 output. |
| 8 | `gpo8` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO8, non-multiplexed, driven low when core power is removed. The HAL writes bit 0 of port 0xfb5 (this bit) around its power-off sequence; what the pin drives on the board is not known. |
| 7 | `gpo7` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO7 output. |
| 6 | `gpo6` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO6 output. |
| 5 | `gpo5` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO5 output. |
| 4 | `gpo4` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO4 output. |
| 3 | `gpo3` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO3 output. |
| 2 | `gpo2` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO2 output. |
| 1 | `gpo1` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO1 output. |
| 0 | `gpo0` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148; Intel 82371AB specification update 297738-017 (January 2002) p.23 | GPO0 output. |

### Register `smbhststs`

SMBus host status: failed, bus collision, device error, interrupt (all write 1 to clear) and host busy. The PROM clears it by writing before its one transaction.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 4 | `failed` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148-149 | Transaction killed. |
| 3 | `bus_err` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148-149 | Bus collision. |
| 2 | `dev_err` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148-149 | Device error. |
| 1 | `inter` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148-149 | Command completed. |
| 0 | `host_busy` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.148-149 | Host busy, read only. |

### Register `smbslvsts`

SMBus slave status.

### Register `smbhstcnt`

SMBus host control. The PROM's single transaction writes 0x54 (start, block protocol); reading the register resets the block data index.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 6 | `start` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.150 | Start; always reads 0. |
| 4:2 | `cmd_prot` | established | quick=0, byte=1, byte_data=2, word_data=3, block=5 | Intel 82371AB datasheet 290562-001 (April 1997) p.150 | Protocol. |
| 1 | `kill` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.150 | Kill the transaction. |
| 0 | `interen` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.150 | Interrupt on completion. |

### Register `smbhstcmd`

SMBus host command field.

### Register `smbhstadd`

SMBus host address: bits 7:1 slave address, bit 0 read (1) or write (0).

### Register `smbhstdat0`

SMBus host data 0 (byte count for block transfers).

### Register `smbhstdat1`

SMBus host data 1.

### Register `smbblkdat`

SMBus block data port.

### Register `smbslvcnt`

SMBus slave control.

| Bits | Field | Grade | Values | Source | Description |
|---|---|---|---|---|---|
| 3 | `alert_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.152 | SMBALERT# enable. |
| 2 | `shdw2_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.152 | Shadow port 2 enable. |
| 1 | `shdw1_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.152 | Shadow port 1 enable. |
| 0 | `slv_en` | established |  | Intel 82371AB datasheet 290562-001 (April 1997) p.152 | Slave port (address 10h) event enable. |

### Register `smbshdwcmd`

SMBus shadow command: command received by an external master access to the slave or shadow ports.

### Register `smbslvevt`

SMBus slave event: data bits compared with incoming slave data.

### Register `smbslvdat`

SMBus slave data: data received by an external master access to the slave or shadow ports.

## Constants

| Constant | Value | Grade | Source | Description |
|---|---|---|---|---|
| `BOARD_ID_SHIFT` | 0x2 | inferred |  | Bit position of the board type in the byte at port 0xfb2 (GPIREG byte 2); the field is four bits wide. |
| `IDETIM_PROM_VALUE` | 0xc077c077 | established |  | Dword the PROM's IDE attach writes to function 1 offset 0x40 (both IDETIM registers). |
| `PM_BASE` | 0xf80 | established |  | Power management I/O base the firmware programs through PMBA (software expectation; Linux assumes the same value). |
| `RC_PORT` | 0xcf9 | established | Intel 82371AB datasheet 290562-001 (April 1997) p.88 | I/O port of the reset control register. |
| `SMB_BASE` | 0xfd0 | established |  | SMBus I/O base the firmware's function 3 attach programs through SMBBA. |

## Test vectors

A vector is a value recorded from a source. An example only shows the layout.

| Target | Value | Kind | Decoded |
|---|---|---|---|
| `f0_pcicmd` | 0xf | vector | io_space=1, memory=1, bus_master=1, sce=1, serre=0 |
| `f0_xbcs` | 0xf4 | vector | rtccs_en=0, kbccs_en=0, bioscs_wp=1, port61_alias=0, mouse=1, coproc_err=1, lower_bios=1, ext_bios=1, apic_cs=0, bios_1meg=0, mc_loc=0 |
| `f0_pirqrc` | 0x9 | vector | route_off=0, irq=9 |
| `f0_tom` | 0xf2 | vector | top=15, lower_bios_fwd=0, a0000_en=0, low512_fwd=1 |
| `f0_mbdma` | 0xc | vector | fast=0, one=1, chnl=4 |
| `f0_gencfg` | 0x6000004c | example | isa_mode=0, pnp_decode=1, rtccs_gpo24=1, rtcale_gpo25=1, kbccs_gpo26=0 |
| `f0_rtccfg` | 0x25 | vector | rtc_en=1, upper_en=1, lock_lower=0, lock_upper=0, pos_decode=1 |
| `f1_pcicmd` | 0x5 | vector | iose=1, bme=1 |
| `f1_idetim` | 0x4000 | vector | ide_en=0, sitre=1, isp=0, rtc=0 |
| `f1_idetim` | 0xc077 | vector | ide_en=1, sitre=1, isp=0, rtc=0, dte1=0, ppe1=1, ie1=1, time1=1, dte0=0, ppe0=1, ie0=1, time0=1 |
| `f3_pmba` | 0xf81 | vector | rte=1, base=62 |
| `f3_pmregmisc` | 0x1 | vector | pmiose=1 |
| `f3_smbba` | 0xfd1 | vector | rte=1, base=253 |
| `f3_smbhstcfg` | 0x9 | vector | host_en=1, intrsel=4 |
| `rc` | 0x6 | vector | srst=1, rcpu=1 |
| `pmen` | 0x100 | vector | pwrbtn_en=1, rtc_en=0 |
| `pmcntrl` | 0x1401 | vector | sus_en=0, sus_typ=5, sci_en=1 |
| `pmcntrl` | 0x2000 | vector | sus_en=1, sus_typ=0, sci_en=0 |
| `smbhstcnt` | 0x54 | vector | start=1, cmd_prot=5, kill=0, interen=0 |
