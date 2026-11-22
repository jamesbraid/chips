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
- The SHub 1 SAL_A order for 4.43 and 4.90: only constants listed. SAL 5.04 is read in full ([boot path](../software/firmware/snprom/boot-sequence.md#sal_a-on-shub-1)).
- Names of the SHub 2 registers the first stage writes. The PROM's error decoder carries "SH2_..." name tables; the
  structure that pairs them with offsets has not been decoded.
- Which EFI configuration tables the PROM installs (SAL system table entry types, ACPI, SMBIOS, HCDP). Route: the
  callers of `InstallConfigurationTable` in the EFI component.
- The value V of the SHub 2 register at `0x2_2011_0000` on real hardware, which sets the NASID width and shift
  `SN_SAL_GET_SN_INFO` reports. Route: a booted-machine capture; the PROM does not write it.
- The role of the empty ELF component (type 0x23) and of `main_verify_elf_signature`.
- Behaviour of the SAL handlers not read: console, hardware performance, serial number, topology queries.
- Altix 350 / SAL 5.04 first-boot gaps ([boot path](../software/firmware/snprom/boot-sequence.md)): settled since the first reading are the DIMM read and SPD bytes, the memory controller field layout, the memory-test completion bits, IBLS0 and the source of the single-node skip (the L1's DIP-switch reply, bit 11). Still open: which L1 command id each remaining request is and what it needs; the route-table initialisation the interpreter run stopped at (so `main_two` past "Calculating routes", the non-skip interconnect registers and everything in `main_three` have not been run; the linked-port crawl, the `SCRATCH1` word, the wait, the master selection and the distribution are read in [the neighbour crawl](../software/firmware/snprom/boot-sequence.md#numalink-discovery-with-a-linked-port-the-neighbour-crawl-sal-504), and what a stand-in neighbour must answer is [numalink-neighbours.md](../software/firmware/snprom/numalink-neighbours.md); the global barrier `0xffa43d20` and `main_three` for two nodes are not read); the PIC register reads, riser EEPROM ids and PCI walk; what PAL call 528 does; where the node id is installed after the election. Route: model the skipped jump to RAM in the interpreter (or run the real step with a CPU model), then continue from `main_two` (`0xffa1ade0`) and `main_three` (`0xffad7280`).
- Board identity: the PROM shows no difference between IP41 and IP57 (no `IP57` string, compute board named "IP41" in klconfig). Whether the SHub ID register or the board EEPROM is the only discriminator is unread; a captured EEPROM info area from an Altix 350 would settle it.
- Altix 350 / SAL 5.04, static reading of the jump to RAM and `main_three` ([boot path](../software/firmware/snprom/boot-sequence.md#static-reading-for-one-node-sal-504-not-independently-reviewed), not independently reviewed): settled since the earlier items are the jump-to-RAM sequence, the layout and SAL copy it makes, the gate polarity of `0xffab38b0`, the PIC id check and register offsets, the console probe order and the EFI hand-off arguments. Still open: the node-window layout the interpreter run needs before `main_two` can finish (the PCFG pointer was a placeholder); the II register set-up in `0xffab1cc0`; which module-type query id the L1 sees; what `0xffab0130` writes; whether any SAL procedure handler (ids `0x02000045` to `0x02000066`, including the IOC3/IOC4 slot check) is called by the PROM itself; the contents of the 88-byte hand-off record; the CPU family value for Madison (the PAL shadow block is skipped for 0x20); the meaning of address bits 37:36 on SHub 1.
- SHub 1 PIC device mask, SAL 5.04 ([PIC page](../devices/pic/README.md#what-widens-the-device-mask-the-ix-brick-base-io-bus-sal-504)): settled are the mask stores, the bus-number table, the base-I/O test and its one setter (an IOC4 found by the slot probe). Still open: what `0xffaa8a40` returns beyond the first board record, what the node-table halfword at `+14` names, and the downstream effect of mask 3 on slots 2 and 3 (resource count and slot accessor read for their range checks only). Next: trace `0xffb35b40` and the `0xffb33420` callers to a result, or a captured IX-brick PROM console log.
