# IP35 base I/O board: which PCI devices sit where, and what routes their interrupts

Question. On the base I/O board of an IP53-class node (the board that carries the IOC4, a SCSI controller and a
single-port gigabit Ethernet controller behind a PIC), which configuration device and interrupt input does each part
use, what revision does each report, and what do the IP35 boot PROM and the IRIX 6.5.30 IP35 kernel objects expect of
them? Which of those expectations are established and which only agree with a capture?

Method. Disassembly of the shipped IP35 PROM (SGI Version 6.210, built Aug 26 2004, unpacked segment loaded at
0xc00000001fc00000, address = 0x1fc00000 + offset; global pointer 0xc00000001fd6f740, so a table word is read from
segment offset 0x16f740 + displacement) and of the relocatable IRIX 6.5.30 objects `usr/cpu/sysgen/IP35boot/pcibr.o`,
`if_tg.o` and `ioc4.o`. Routines were read with the repository's host-side fact tool and a listing of its decoder;
nothing was run. PROM 6.211 (built Jan 25 2008) carries the same strings 0x10 to 0x18 lower; its routines were not
read beyond those string offsets. Register names for the Ethernet controller are the public Linux `tg3` names.

## Short answer

- Established (capture): on one real Origin 350 (same IO9 family board, PIC revision 3) the public OpenBSD boot
  output lists the IOC4 at logical device 0 (revision 0x53, interrupt 0), the QLogic ISP12160 at device 2 (revision
  0x06, interrupt 2) and the BCM5701 at device 3 (revision 0x15, chip id 0x105 "B5", interrupt 3, PHY at MII address 1),
  all on the first bus of the PIC at widget 15. The PIC occupies configuration device 0 of its bus, so logical device
  n is configuration window n + 1 (window 1 for the IOC4, 3 for the ISP12160, 4 for the BCM5701).
  The Ethernet controller's station address in that capture is in SGI's 08:00:69 block.
- Established (IRIX 6.5.30 `pcibr_intr_bits`, `pcibr.o` 0x7534, 76 bytes, read in full): a function's interrupt pin
  letter maps to bridge input `slot` for INTA and INTC, and `slot ^ 4` for INTB and INTD, where `slot` is the byte at
  record +0x21c and the routine returns 0 when it is not below the slot count passed. With slot = window - 1 this gives
  inputs 0, 2 and 3 for the three parts, which are the interrupt numbers in the capture. The IRIX `tg` driver
  allocates INTA for function 0 and INTB only when the function number is 1 (`if_tgattach`, `if_tg.o` 0x9344 with the
  `movn` at 0x9348), so a single-port 5701 uses INTA alone.
- Inferred: the Tezro's IO9 is the same board family as the Origin 350's, so the three placements and inputs carry over.
  No public capture of a Tezro's interrupt numbers was found.
- Established (captures, [tezro-io-topology.md](tezro-io-topology.md) item 3): a Tezro's widget 15 head 0 lists the
  IOC4 at pci id 1, a TI PCI-to-PCI bridge (vendor `0x104c`, device `0xac28`) at pci id 2, the SCSI controller at 3 and
  the gigabit Ethernet at 4. The bridge is on all five Tezro postings that print that head and on none of the seven
  Origin 350 and Onyx 350 IO9 captures. If the printed pci id is one more than the logical device number used above,
  the bridge is logical device 1 (window 2), the slot the Origin 350 layout leaves empty, and the SCSI and Ethernet
  parts keep windows 3 and 4. That mapping is **inferred**, and the cause of the bridge's absence on Origin 350 is
  **unknown**.
- Established (PROM 6.210): the PROM scans all eight configuration windows of the bus from 0x20000 in steps of
  0x1000 (the loop at 0x1fc426d8 to 0x1fc426d4, helper 0x1fc47d44 called with the window index) and decides what each
  device is from the identification dword (device id high, vendor low). Inferred (the compare tree was read, not every
  arm followed): the dwords it knows include 0x100a10a9 (IOC4), 0x164514e4 and 0x164714e4 (Broadcom 5701 and 5703),
  0x12161077 (ISP12160), 0x10201077 and 0x22001077 (other QLogic parts). It has no case for 0x164814e4 (5704) in that
  tree (constant sets at 0x1fc42980 to 0x1fc42a98).
- Established (PROM 6.210): the Ethernet component builder at 0x1fc4653c stores component type 0x35 and, from a
  dword loaded at window + 0x8 (class and revision), its low byte into the new KLCONFIG component (load at 0x1fc465b8,
  store at 0x1fc465d0). Inferred: that byte is the PCI revision. Strings
  naming the IOC4 and Ethernet component builders and the console choice ("IOC4 found, but is not the console") sit at
  6.210 offsets 0x7e360, 0x7e3c8 and 0x788b8.

## What is not settled

| Item | Grade | What would settle it |
|---|---|---|
| IOC4 at window 1, ISP at 3, BCM5701 at 4, inputs 0, 2, 3 on a Tezro | inferred (established for an Origin 350 by capture) | a Tezro boot capture that lists PCI devices and interrupt numbers, or a Tezro `hinv -v` with the hardware graph paths |
| TI bridge (104c:ac28) at widget 15 pci id 2 on a Tezro, window 2 | printed presence established (five Tezro postings); window mapping inferred; the cause of its absence on Origin 350 unknown | a Tezro capture that lists a card behind the bridge (see [tezro-io-topology.md](tezro-io-topology.md)) |
| BCM5701 PCI revision 0x15 (chip id 0x105) on a Tezro | inferred, same board family | the same capture on a Tezro |
| INTB and INTD wiring on the board | unknown | no software on this board uses them for these parts; a board schematic would settle it |
| Why the IOC4 reports PCI bus speed through register 0x24 | see [../../chips/ioc4/README.md](../../chips/ioc4/README.md) | the PIC control register's speed field on the IO9 bus, read by the PROM or IRIX at attach |
| What the PROM's Ethernet and NIC diagnostics do ("BCOM_570X_GIGE", "GIGE570X", "nic_eaddr" strings at 6.210 offsets 0x84ba0, 0x881c8, 0x88e70) | unknown | read the routines that reference those strings; they sit in a data region beyond the text this pass read |

Sources. SGI IP35 PROM 6.210 and 6.211 as above; IRIX 6.5.30 `pcibr.o`, `if_tg.o`; OpenBSD/sgi Origin 350 support
announcement and 4.6-current boot output (October 2009, OpenBSD `misc` list); public OpenBSD
`sys/arch/sgi/xbow/xbridge.c` for the PIC-at-device-0 numbering, as used in [../../chips/pic/README.md](../../chips/pic/README.md).
