# DS2502 one-wire identity part

The Maxim DS2502 is a 1-Wire add-only memory: a factory-lasered 64-bit ROM (family code, unique serial number and CRC),
1024 bits of EPROM in four 32-byte pages, and 64 bits of status memory. Public O2 software reads the O2's Ethernet
address from a firmware variable, and two sources tie a one-wire identity part to the O2's I/O ASIC. Which part a
physical O2 carries, and what it holds, is not settled. The part's constants are in `devices/ds2502/registers.toml`, and the
generated reference is `devices/ds2502/registers.md`. The MACE register bits that drive and sample its line are in
`devices/mace/registers-extra.toml` and on [the MACE chip page](../../chips/mace/README.md). This page holds what those units do not.

Each fact carries one label. **Established** means the manufacturer datasheet or the MACE specification states it, as
the source records it. **Inferred** means arithmetic on an established fact, or a public driver's reading of how
software uses the part. **Unknown** means the sources do not settle it.

## Sources

- **Maxim DS2502 1Kb Add-Only Memory datasheet**, document 19-5075, revision 12/11. The timing table and the ROM,
  memory and status sections are the basis of the constants. Page numbers are not recorded in this import.
- **SGI MACE I/O ASIC Specification**, chip revision 2.0, July 16, 1996
  ([references/documents/specs](../../references/documents/specs/mace-specification.pdf)). Table 54 (Flash-ROM/NIC control register, printed
  page 124) gives the NIC bits at `0x310008`. The chip feature summary names a "Number-In-a-Can serial PROM" interface
  and a calendar clock module with a serial number and Ethernet address.
- **Public NetBSD** at `07004b2a9dac23a1cdd33b76dc45b65be56c6f1f`: `sys/arch/sgimips/mace/mace.c` (the MACE match
  function, which accepts only the O2 machine type) and `sys/arch/sgimips/mace/if_mec.c` (the Ethernet address setup,
  with a comment about the DS2502 on the PCI riser).
- **Public Linux** at `db2ddb87143519e20a95aa36c60b36107b736a58`: `arch/mips/sgi-ip32/ip32-setup.c`, which takes the
  Ethernet address from the firmware `eaddr` variable.
- **Public OpenBSD** SGI port reads the same firmware variable. Its files were not re-read for this page.

## The part (established)

- **ROM.** Family code `0x09`, a 48-bit serial number and a CRC-8 of the first 56 bits. Bits go out least significant
  first. The CRC uses x^8 + x^5 + x^4 + 1 with a zero start. The constants are `DS2502_FAMILY_CODE`,
  `DS2502_ROM_BITS` and `DS2502_CRC_POLY`.
- **EPROM.** 128 bytes in four 32-byte pages. Programming can only change a bit from 1 to 0. A virgin part reads all
  ones in data memory, which says nothing about a fitted part's contents.
- **Status memory.** Eight bytes. Byte 0 is a write-protect bit per page: once a bit is programmed, its page cannot be
  altered but can still be read. Bytes 1 to 4 hold page-redirection values, which the chip does not act on. The first
  seven bytes program from 1 to 0. Byte 7 is factory-programmed to `0x00`. The datasheet passages this import read do
  not describe bytes 5 and 6 further.

## Protocol (established)

- **Reset.** The master holds the line low for 480 to 960 us, then releases it. The part answers after 15 to 60 us
  with a presence pulse held low for 60 to 240 us. A reset ends any command in progress.
- **Slots.** Each slot lasts 60 to 120 us, with at least 1 us of recovery between slots. A write-one holds the line low
  for 1 to 15 us. A write-zero holds it low for at least 60 us, to the end of the slot. For a read, the part holds the
  line low to send a zero, and its bit is valid 15 us after the slot starts.
- **ROM commands.** Read ROM (`0x33`) is valid only with one slave on the bus. Match ROM (`0x55`) followed by 64 bits
  selects one part, and a mismatch stays silent until the next reset. Skip ROM (`0xcc`) selects every slave. Search
  ROM (`0xf0`) enumerates the bus: for each ROM bit the master reads the bit, reads its complement and writes the
  chosen value. Before selection, `0xf0` and `0x55` mean Search ROM and Match ROM. After selection they mean Read Memory
  and Write Status.
- **Memory commands** (after a ROM selection).
  - Read Memory (`0xf0`): two address bytes, low byte first. The part returns a CRC-8 over the command and address,
    then data up to address `0x007f`. A data CRC follows only when the master reads through the last byte. After that
    the part sends ones until a reset.
  - Read Data with CRC (`0xc3`): a CRC after each 32-byte page, then the next page. After the last page's CRC the part
    sends ones until a reset.
  - Read Status (`0xaa`): a CRC over the command and address, then the status bytes through byte 7 and a CRC over
    those bytes. Ones follow until a reset.
  - Write Memory (`0x0f`) and Write Status (`0x55`) program the part. Programming takes a 12 V pulse of at least 10 mA
    for 480 us on the bus, and it is outside the read-only contract here.
- **CRC checks are the master's job.** The part does not stop a sequence when the master's CRC disagrees. A master
  that ignores a bad CRC carries on with bad data.

## O2 fit and Ethernet address (open)

- **Which identity part a physical O2 carries: unknown.** The MACE specification names a Number-In-a-Can serial PROM
  behind one drive bit and one sample bit in its NIC control register (table 54). It also places the system serial
  number and Ethernet address in a 56-bit silicon serial number inside the calendar clock module. These two statements
  disagree about where the identity data lives. Neither source says whether they describe different assemblies or a
  design change. Settling route: a published dump of a real O2's identity part, read with its board revision, or a
  board-level description that names the part.
- **Where the riser part sits: unknown.** NetBSD's comment says that on some machines the DS2502 that holds the
  serial and MAC is on the PCI riser board, and that without that board the firmware has no good address. The comment
  is a driver author's report without a board revision or a read-out. Labelled **inferred** as a software expectation.
- **Software reads the firmware variable (established for the code, inferred for the hardware).** The Linux IP32 setup
  and NetBSD's MACE driver both take the address from the firmware `eaddr` variable. Neither driver shows which
  device the firmware reads that variable from. Labelled **unknown** for the device.
- **Family code and serial.** The family code identifies a DS2502, not a particular board or O2. No serial number or
  MAC address can be derived from the family code. Labelled **unknown**.
- **MACE NIC line reset state.** Table 54 gives bit 2 a reset value of 0, which holds the NIC interface low after
  reset (**established**). Whether the O2 firmware relies on that state is not in the sources read here.
