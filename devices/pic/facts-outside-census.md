# PIC: facts outside the register census

The PIC is the PCI-X bridge on the IP53 family: one chip with two PCI-X heads, each with its own register block and bus. Register offsets, widths and access come from the generated contract in [devices/pic/registers.toml](registers.toml) and the bit constants in [devices/pic/registers-extra.toml](registers-extra.toml). The family and widget identity are in [bridge-family.md](../bridge/family.md). The Tezro widget map is in [questions/tezro-widget-11.md](../../questions/tezro-widget-11.md), and the IO9 interrupt pins are in [questions/ip35-io9-pci-wiring.md](../../questions/ip35-io9-pci-wiring.md). This page holds the rest.

Grades: **established** (a cited manual, a published register header or a captured value), **inferred** (a reading of firmware or driver code, or a sibling part), **unknown** (with the test that would settle it). Firmware reads are static readings of shipped images. Driver code shows what software expects, not what the chip does.

## Error bits and clears

| Bit or item | Meaning | Grade |
| --- | --- | --- |
| Status `0x100` bit 11 | PCI master timeout, recorded only when enable bit 11 is also set | established |
| Error view `0x170` bit 11 | The same timeout, recorded whether or not it is enabled | established |
| Status `0x100` bit 34 | PCI-X master timeout | established |
| Reset `0x110` bit 6 | Clears the multiple-error indication | established |
| Reset `0x110`, other bits | A one written at an error bit's own position clears that bit and rearms the error registers. Any write to `0x110` also clears the error view. | established |
| Status `0x100` bits 7:0 | Current level of the eight input pins, read-only | established |

The PIC clears one error bit per position. Bridge and Xbridge clear whole groups with a single strobe, so software written for those chips does not port directly. [bridge-family.md](../bridge/family.md) has the same finding for the wider register layout.

Unknown: which bit a head in PCI-X mode sets for an unclaimed configuration cycle, bit 11 or bit 34. Test: a configuration read of an empty device on a PCI-X-mode head, then reads of `0x100` and `0x170`.

The IA64 PIC probe writes bit 0 of `0x110`, the Bridge group strobe, together with the PCI-X bits. Whether a PIC honours that bit is unknown.

## Empty-slot configuration reads

Inferred: a configuration cycle that no device claims ends in a PCI master timeout, and the processor sees a bus error. Nothing public states this for the PIC, and no capture of an empty slot exists. The Tezro's observed failing reads are in [questions/ip35-boot-probe-registers.md](../../questions/ip35-boot-probe-registers.md).

How the stock IP35 PROM 6.210 probes one 32-bit configuration read (inferred, from the shipped image):

1. It writes `0x41` to the head's reset-interrupt low word (`+0x114`) before the read. That write is inside its own fault guard.
2. It reads the device's configuration word inside a fault-recovery context.
3. If the read faults, it clears the Bedrock processor-interface error records, writes `0x41` again and reports the slot absent.
4. If the read completes, it reads the identity word at `+0x04`. For a PIC part (`0xd102` or `0xd112`), it tests bit 11 of the status low word (`+0x104`). For an Xbridge part (`0xd002`), it tests bit 11 of the error view low word (`+0x174`). Bit 11 set means absent.

The PROM probes function 1 only when function 0 is present and the header's multifunction bit is set. It never probes functions 2 to 7. Device 0 is the PIC's own configuration device. The PROM probes it, and what the PIC returns there is unknown.

The PROM clears the enable register before the probes. With every enable bit clear, the bit 11 status test cannot fire, so the PROM's "absent" answer must come from the fault path. The same reading also means a status latch that ignores the enable would make later devices on that head look absent.

Test that settles the inference: one configuration read of an empty device at the PROM prompt on an Origin 350 or Tezro, with no writes, followed by reads of the same head's `+0x104` and `+0x174`. That needs a physical-test proposal first.

## The 0x7c write in the PROM bridge diagnostic

Inferred from the shipped PROM image, for the XBridge and both PIC heads:

1. Enable bit 24 of the enable register (`+0x108`).
2. Write a host-error number to `+0x12c`.
3. Write `0xdeadbeef` to `+0x7c`, the low word of slot `0x78`.
4. Poll the status low word for bit 24.
5. Check that Bedrock processor-interface pending register 0 has bit *n* set, where *n* is the host-error number.

The PROM repeats this for number 0 and for numbers 7 to 19. Between levels it writes only bit 3 to the clear register's low word, and it never writes bit 24 to that register.

The public IA64 PIC header marks slot `0x78` read-only. The OpenBSD driver names bit 24 as the invalid-address interrupt, recorded for the Bridge family as `INT_STATUS_INVALID_ADDRESS` in [devices/bridge/registers-extra.toml](../bridge/registers-extra.toml).

Established, as printed output: the verbose heavy-diagnostic capture of a real four-processor Tezro, PROM 6.210, shows no status-bit failure message and no interrupt-delivery failure message for either PIC. The capture shows the checks passed. It does not show register values.

Unknown: whether a write to bit 3 of the clear register clears status bit 24, or whether each invalid write sends a new interrupt while bit 24 stays set. Whether a write to any other read-only or undefined register also sets bit 24 is unknown. Test: write bit 3 to `0x110` after a provoked bit 24 and read `0x100`. Test: an aligned 64-bit write to `0x78` and a 32-bit write to `0x0c`, each followed by a status read.

## Eight-byte processor stores to a 32-bit device

Question: an aligned eight-byte store through a PIC window to a function with 32-bit registers. Which half lands at the lower PCI address?

- Candidate (a): two 32-bit data phases, the more significant half first, so it lands at the lower address. Each phase follows the narrow-width byte rule, a CPU byte `a` to PCI byte `a XOR 3`.
- Candidate (b): one 64-bit data phase, reversed as a whole doubleword, so the less significant half lands at the lower address.

Inferred: candidate (a). No PIC specification is held, so the chip itself is not established. Evidence:

1. SGI's *IRIX Device Driver Programmer's Guide*, 007-0911-210, (November 2003), printed page 719, says 64-bit PIO is handled as two 32-bit units, with the more significant half first, and tells drivers to swap or store the halves separately before writing a 64-bit PCI register. The guide describes SGI's PCI adapters in general and does not name the PIC. It is a software expectation.
2. Broadcom's *BCM57XX Programmer's Guide*, 57XX-PG105-R, printed pages 232 to 234, says the Ethernet chip is internally 64-bit big-endian. With endian word swap set, a 32-bit access at offset 0 of an eight-byte field reaches the more significant word. The guide draws no figure for word swap on a 64-bit phase. Established for 32-bit phases. Unknown for 64-bit phases.
3. The public Linux network driver writes the high half at `+0` and the low half at `+4` as two 32-bit stores. That agrees with candidate (a).
4. The factory gigabit port on an Origin 350's IO9 sits behind PIC head 0. Under candidate (a) its drivers work. Under candidate (b) split into two 32-bit phases, the halves would swap. That the port works is inferred from SGI shipping it; no traffic capture is cited.

Unknown: the same question for 64-bit phases, and whether the Ethernet chip's word swap acts on them. What would settle it: a PIC specification section on data-phase width and Device bit 22, a published Broadcom statement on 64-bit phases, or a measurement on a PIC revision 3. The measurement stores an asymmetric doubleword to a read-write 32-bit register pair on a function with no swap of its own and reads the pair back as two 32-bit loads. That needs a physical-test proposal first.

The Bridge version of this question is open in [bridge-family.md](../bridge/family.md).

## Device bit 19 (swap_direct)

Set in the Device register (`0x200` plus 8n), bit 19 is named `swap_direct` in the public PIC header. It is set for byte-stream requests and cleared for word-value requests. The mapping from the public byte-stream and word-value flags to this bit is in the SN2 driver. The IRIX 6.5.30 IP35 flag routine does the same for chip type 2, which is PIC (inferred from the numbering in the public SN2 headers).

The lane sense is inferred, not measured. Set selects the address-preserving byte map. Clear selects the lane-preserving map, so a card's byte at address `a` of an aligned word lands at `a XOR 3`.

The IOC4 numbers its DMA bytes big-endian across the PCI lanes, as the IOC3 does. IRIX leaves the IOC4's own bit 19 clear. Changing the PIC's bit 19 sense therefore changes IOC4 serial output unless the IOC4's byte order changes with it. That interaction is inferred from driver code and not tested on hardware.

The open test for the sense is in [open-questions.md](../../questions/README.md) under the PIC direct-window lane sense.

## Processor PIO byte lanes: what the IRIX 6.5.30 IP35 kernel does

Question: how does software on a big-endian processor place byte, halfword and word accesses to a device behind a PIC, and does
anything differ for an enclosure ("outer") PIC of an IX-brick compared with the PIC of an Origin 350 or Tezro? Readings are of
`IP35/usr/cpu/sysgen/IP35boot` objects (sha256 in the Sources list); offsets are object offsets. Static readings, nothing run.

**One kernel, no host switch (established).** The object set carries one PIC attach (`pic_attach`, `pic_attach2` in `pic.o`) and one
Bridge-family driver (`pcibr.o`). Its branches test the chip type (`lh` at record +114, 2 is PIC), the chip revision (`lw` at +120,
low nibble 1), the bus index (record +72, 0 or 1) and the L1 brick-type code (record +138). None tests the compute brick or
the enclosure's position. So the swap and lane setup below is the same code for every PIC the kernel meets (established as
code). That the hardware behaves the same behind an outer PIC is **unknown**.

**What the kernel programs (established).**
- `pcibr_slot_device_init` (`pcibr.o` `0xdc18`, read in full): per slot, Device(n) loses bit 27, gains bit 16, and gains bit 25
  unless the chip is a PIC at revision 1. It does not touch bit 13 (`dev_swap`) or bit 19 (`swap_direct`): whatever the
  firmware left there stays until a PIO mapping rewrites bit 13.
- The address-translation routine behind `pcibr_piomap_alloc` (`0x1b24`, calls it at `0x1bac`) and `pcibr_piotrans_addr` (`0x1e38`, at
  `0x1e98`) is a static routine at `0x1250`. A request carrying flag `0x1000` (byte stream) wants the window's Device bit 13 set;
  any other request wants it clear. It reuses an existing window only when bit 13 agrees (`0x14b0` to `0x14d4`, `0x17d0`), and
  when it allocates a window it writes Device(n) with bit 13 set or cleared accordingly, bit 12 set for memory, the window offset in
  bits 11:0, and the other upper bits kept (`0x1864` to `0x1890`, store at `0x1aa8`). So bit 19 is never changed by a PIO mapping.
- The same routine, for the memory alias (space codes 4 and 5; bus index 0 at `0x4000_0000`, index 1 at `0xc000_0000`), sets Control bit 22
  (`mem_swap`) through `pcireg_control_bit_set` (`0x19c4`) for a byte-stream request and clears it (`0x1ae4`) otherwise. It keeps the
  chosen mode in the bus record (`+2724`) and refuses a later request for the other mode. Configuration space (space code 7 in this routine) is
  refused for flag `0x1000` (`0x157c`). Space code 2 returns the unmappable value when the chip is a PIC (`0x1788` to `0x1a68`), which agrees with a PIC having no I/O alias.
- `pic_attach2` (`pic.o` `0x64c`) writes Control as: clear bits 55:48 and set the bus index there, clear 62:61 and 47:40, set 31:30,
  set 29 unless revision 1, set 21 (`0xb70` to `0xbc0`, literal masks from `.lit8`). It sets neither bit 22 nor bit 9 (`sys_end`).
- Drivers that ask for byte stream or word values: `ioc4.o` and `sio_ioc4.o` pass flags 0 to `pciio_pio_addr` / `pciio_piotrans_addr` for
  BAR0 (space 8, 928 bytes; `ioc4_attach` `0x25c`, `ioc4_serial_attach` `0xcd8`), as does `ql.o` for the SCSI adapter (space 9, 256 bytes, `0x4664`). So their windows have Device bit 13 clear.

**Where software compensates for lanes (established as code).** In every IOC4 path the code reads and writes by the width it means and at the
plain offset: 32-bit `lw`/`sw` for registers, `lbu`/`sb` at `UART + n` for the 16550 registers (`hardware_init`, `sio_ioc4.o` `0x8f8`;
`ioc4_attach`, `ioc4.o` `0x204`), and for the ATA block a 32-bit access at `base + 4 * index`, with the byte and halfword forms
masking the loaded word and storing a whole word (`xide_putb` `0x905c`, `xide_getb` `0x9154`, vendor halfword `0x10a9` branch, `ide.o`). No
byte reversal instruction and no address `XOR` is on the IOC4 path. For other devices the kernel does the opposite:
- PCI config space: `do_pcibr_config_get` (`pcibr.o` `0xbadc`) reads one aligned word and shifts and masks in software, so a sub-word read is
  a word read. `do_pcibr_config_set` (`0xbb68`) stores a byte at offset `XOR 3` and a halfword at offset `XOR 2` (`xori` at `0xbba4`, `0xbbdc`,
  `0xbc2c`, `0xbc48`), a word at the aligned offset. The Tigon driver wraps both with the same XORs before calling the generic
  routines (`tg_pci_cfg_rd` `0x8c88`, `tg_pci_cfg_wr` `0x8cc8`, `if_tg.o`).
- The ATA driver for a non-IOC4 vendor halfword uses `index XOR 3` (byte) and `XOR 2` (halfword) (`ide.o` `0x9074`, `0x90c8`, `0x916c`, `0x91cc`).
- The SCSI adapter driver (`ql.o`) does 16-bit accesses at literal offsets that are the public SCSI-adapter register offsets with bit 1 flipped: `0xc2` (45
  sites) for the host command and control register that the public header puts at `0xc0`, `0x0a` (37) for the interface control register at `0x08`, and
  a mailbox command written to `0x72` with its status (`0x4000`) polled at `0x72` while an argument goes to `0x70` (`ql_enable_sram_parity`, `ql.o` `0xe94`, stores at `0xf94`, `0xfa0`, `0xfac`, poll at `0xfb0`). The access width is established; that these are the `XOR 2` images of those register offsets is **inferred** (register offsets from
  the public Linux driver for the part, not re-fetched here).
- The Tigon (Broadcom) and SCSI (QLogic) parts are the ordinary devices on an IO9 behind an outer PIC (see [IX-brick](../../platforms/bricks/ixbrick.md)); the audio
  drivers (`mad_dd.o`, `emu_dd.o`) carry the same XORs on their byte and halfword accesses and are not tied to a PIC.

Reading: the kernel treats a PIC window as a map in which a CPU byte at address `a` reaches PCI byte lane `a XOR 3` and a halfword reaches
`a XOR 2`, with 32-bit values kept numerically. The IOC4 is the exception because it numbers its bytes big-endian across the lanes (see
[devices/ioc4](../ioc4/README.md#ioc4-behind-a-pic-how-its-dma-bytes-are-numbered-public-linux)). That is a **software expectation** and an inference about the hardware (the XOR could equally be
done by Bedrock, the crossbar or the PIC); the kernel code cannot say which part reverses lanes.

**IX-brick and brick type (established as code; meaning inferred).** `pic_attach` (`0x42c`) asks the L1 for the brick type. For codes `0x30` and `0x56`
it names the buses `agp/0` and `agp/1`, for every other code `pci-x/0` and `pci-x/1`. `pic_attach2` then picks slot limits and read-response-buffer
splits from a table indexed by the code minus `0x23` (`pic_attach2` `0x9d8` to `0x9fc` and `0xef4` to `0xf10`; the tables are at `.rodata +0x448` and `+0x5e8`, targets `0xa20`, `0xa58`, `0x12d8`): codes `0x23`, `0x37`, `0x38`,
`0x39`, `0x3d`, `0x45`, `0x51` get slots 0 to 1 (the bytes the "slots %d-%d" message prints, record +49 and +50), code `0x39` slots 0 to 2 when `pcibr_widget_to_bus` returns 2
(`0x12c0`), code `0x3d` slots 0 to 3 when it returns 1 (`0x12cc`), codes `0x30` and `0x56` slot 0 only. The public Altix header calls `0x3d` the IX-brick and its bus 1 holds the IO9 at config devices 1 to 4; reading code `0x3d` that way is inferred.
None of these branches touches a swap bit.

**IP35 PROM (6.210).** The CPU PROM reaches the IOC4 with 32-bit stores and loads at `+0x20`, `+0x28`, `+0x30`, `+0x38` and a byte load of the UART line status at `+5`
(`0x1fc2af84`, `0x1fc2af18`); its PIC accesses are the interrupt-clear and probe sites in the census (`0xc00000001fc41f38`). It programs no Device or Control swap bit.
The BaseIO monitor inside the same image (gzip ELF at image offset `0x8cbb0`, sha256 of the decompressed ELF `f903b3ce33b86c286f168ba43395f36a0073c24b1d4e703adce240f683b8c2d7`)
carries its own Bridge-family driver; where it sets Device bit 13 or Control bit 22 is **unknown** (not read).

## Force registers

Established, from the public PIC header:

- Force-always at `0x180` plus 8n sends a set packet for the input, as if it had transitioned, even when the input is already active.
- Force-with-pin at `0x1c0` plus 8n sends a set packet only while the input is active, and is ignored otherwise.

The public SN2 driver writes force-with-pin at the end of an interrupt dispatch, and only when the input has no handler. The shipped IRIX 6.5.30 IP35 dispatch routine also writes force-with-pin for PIC at its tail. The flush use is in [bridge-family.md](../bridge/family.md).

The chip does not re-send a packet on its own while an input stays active. A second interrupt that arrives before the first is cleared can leave the status bit set with no packet. The SN2 driver's comment calls that a deadlock. Software recovers with a force write.

Unknown: whether a refused or NACKed packet returns a response, and whether any chip timer re-sends a packet. Test: force-always with the input low and then high, force-with-pin with the input high and then low, each read against the packet count.

## Origin 350 chassis slots

Established, from the Origin 350 user's guide and the Onyx 350 guide. The Origin 350 guide is *Origin 350 Server System User's Guide*, 007-4566-001, printed pages 70, 87 to 89, 110, 119, 125 and 141. The Onyx 350 guide is *Onyx 350 Visualization System User's Guide*, 007-4632-001, pages 53 and 57.

Each compute module has four 64-bit 3.3 V PCI or PCI-X slots, on two buses, labelled PCI 1 to PCI 4 from the bottom. The IO9 card sits in bus 1 slot 1, the lowest slot of the base module. Bus 1 slot 2 shares the IO9's bus, so it runs PCI mode at 66 MHz or slower (page 110). An MPX module has four slots with the same labels and no IO9. It has its own IP53 node board, interface board and a PCI riser card that carries the PIC (printed pages 135 and 138); the same pages and 141 show the PCI 1 to PCI 4 labels, and the guide does not say whether an IO9 is fitted, so the absence of an IO9 is inferred. A PCI expansion module has six buses of two slots each, which the [Origin 300 expansion module sheet](../../platforms/bricks/origin300-pci-expansion-module.md) owns.

| Chassis label | IRIX label | PIC head | Device | INTA and INTC input | INTB and INTD input |
| --- | --- | --- | --- | --- | --- |
| PCI 1 | bus 1 slot 1 | 0 | 1 (the IO9 also answers at 3 and 4) | 0 | 4 |
| PCI 2 | bus 1 slot 2 | 0 | 2 | 1 | 5 |
| PCI 3 | bus 2 slot 1 | 1 | 1 | 0 | 4 |
| PCI 4 | bus 2 slot 2 | 1 | 2 | 1 | 5 |

The input columns use the pin rule in [questions/ip35-io9-pci-wiring.md](../../questions/ip35-io9-pci-wiring.md). IRIX's `bus` is the PIC head plus one, and its `slot` is the configuration device. Both are inferred from the IO9's printed device list and from one Tezro capture. Board wiring for INTA and INTC is inferred. Board wiring for INTB and INTD is unknown, because the pin rule is a software convention. No capture shows an interrupt on one of these inputs.

Unknown: whether head 1 is bus 2 on every module. The captures that print a bus all come from compute modules. Also unknown: whether device 2 of head 0 is bus 1 slot 2 or sits behind a bridge. Test: a card in PCI 2 should appear in `hinv` as bus 1 slot 2 with an adapter at `pci-x/0/2`, and a card in PCI 4 as bus 2 slot 2 at `pci-x/1/2`.

## Sources

- Public SGI PIC register header, `include/asm-ia64/sn/pci/pic.h` and `bridge.h` in the pinned `linux-2.4.37` submodule (GPL): register bit names and force-register layout.
- Public SN2 PIC driver (`pcibr_intr.c`, `pcibr_dvr.c`): force-write timing, byte-stream flags and the Device bit mapping.
- Shipped IP35 PROM 6.210 and IRIX 6.5.30 IP35 kernel objects, static readings only. No symbol names or source text are carried here.
- Objects read for the lane section (sha256, `IP35boot`): `pcibr.o` `5a79bfd6f2bf07f4c614b5794a9a3e6f5f973f8e60110e0ac2f6b293eb252a29`, `pic.o` `4ccc69e42c0fde78fe7d49e2c67a1095131022d33d24fa48caf131238ca9f188`, `ioc4.o` `e15e32c04c3260244fb2995f636128dadc4145d4d98aded4e2bbc2caa6c941f8`, `sduart.a` member `sio_ioc4.o` (archive `e68b526b8f3aafded170871f43f180706f1f6ce5d039fb9dc2fab68ef1c9bb2f`, member `eaf1d7d5d4e6f7db2c1594bcc2d0581fb51c30730143290b17c999c04c288733`), `ide.o` `1e61f46697355749673539c0b4a90a3112f7f87d95c5b47d99e45e0ab74baa8c`, `ql.o` `6d95ec4c32d288ce31a4ab38142db0154c22189736df282ae2ae393e7e22e23a`, `if_tg.o` `0dec82e929558ac27fa2a9fdc826db90f6dabd4142fa07dd8a7bc95233d92bce`; PROM `ip35prom.img` `d74b4b7ef9c11c66692019db9af698104595be7a0573a86feae8a83441921318`. All match `tools/config/inventory-root.sha256`.
- Spot checks of the PROM readings against the 6.210 image (`ip35prom.img`): a store of `0x41` to offset `0x114` of a head at image offset `0x2d388`, and the `0xdeadbeef` store to offset `0x7c` at image offset `0x4dd9c`. The rest of the PROM sequences were not re-derived and stay inferred.
- Captures: the verbose heavy-diagnostic Tezro PROM output with no failure messages, and the Tezro `hinv` captures named in [questions/tezro-widget-11.md](../../questions/tezro-widget-11.md).
- *IRIX Device Driver Programmer's Guide*, 007-0911-210 (2003), printed pages 718 to 719.
- Broadcom, *BCM57XX Programmer's Guide*, 57XX-PG105-R (2008), printed pages 232 to 234.
- Origin 350 and Onyx 350 user's guides, as listed in the slot section.
