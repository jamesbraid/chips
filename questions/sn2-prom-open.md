# SN2 PROM: what the four snprom images leave open

Question. What does each snprom image do, in order, from reset to the EFI prompt, and which hardware answers does it
need on the way? The SAL dispatch tables, the image layout and the first stage of the SHub 2 build are read; the rest
is not ([software/firmware/snprom](../software/firmware/snprom/README.md)).

Status: **unknown** beyond the first stage and the call tables. Route tag: software now (images are in `root/sn2/`).

Open items, each with the route that settles it:

- The ordered init path of SAL_B (`0xff42fbb0` in the 1.40 image onward): six early calls, then what is probably
  `main()`. Needs the call graph followed with the symbolised runtime as a name key (a signature match names about a
  third of the functions). Settles memory sizing, SPD/DIMM access, flash probing and the first system-controller
  contact.
- Whether boot continues when the system controller does not answer ("System controller communication init failed"),
  and what the minimum controller answer is. Route: the callers of `sysctl_init` and `sc_link_init` in SAL_B, and
  the sysco repository's controller protocol.
- The simulator escape: `sysctl_probe` tests `cpuid[2]` against a fixed value, and `sc_shub2_sim_data` builds the
  controller's answer from a SHub register block at offset `0x1003_8200`. Route: read `sc_shub2_sim_data`,
  `sc_tio_sim_data`, `sc_nl4r_sim_data` in full and who calls `sysctl_probe`.
- The SHub 1 SAL_A order for 4.43 and 4.90: only constants listed. SAL 5.04 is read in full ([boot path](../software/firmware/snprom/altix350-boot-path.md#sal_a-on-shub-1)).
- Names of the SHub 2 registers the first stage writes. The PROM's error decoder carries "SH2_..." name tables; the
  structure that pairs them with offsets has not been decoded.
- Which EFI configuration tables the PROM installs (SAL system table entry types, ACPI, SMBIOS, HCDP). Route: the
  callers of `InstallConfigurationTable` in the EFI component.
- The value V of the SHub 2 register at `0x2_2011_0000` on real hardware, which sets the NASID width and shift
  `SN_SAL_GET_SN_INFO` reports. Route: a booted-machine capture; the PROM does not write it.
- The role of the empty ELF component (type 0x23) and of `main_verify_elf_signature`.
- Behaviour of the SAL handlers not read: console, hardware performance, serial number, topology queries.
- Altix 350 / SAL 5.04 first-boot gaps ([boot path](../software/firmware/snprom/altix350-boot-path.md)): the ordered register list and completion bits of memory initialisation and test; the L1 command ids and the response each needs; the single-node skip of interconnect discovery; PIC widget discovery reads; what PAL call 528 does; where the node id is installed after the election. Route: continue the SAL_B call-graph reading from `main_two` (`0xffa1ade0`) and `main_three` (`0xffad7280`).
- Board identity: the PROM shows no difference between IP41 and IP57 (no `IP57` string, compute board named "IP41" in klconfig). Whether the SHub ID register or the board EEPROM is the only discriminator is unread; a captured EEPROM info area from an Altix 350 would settle it.
