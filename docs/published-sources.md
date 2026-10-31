# Public sources other than the specifications

Cited by file and version, never copied. Labels in the entries say which source a fact rests on.

- **Linux**: `arch/mips/include/asm/pci/bridge.h` and `arch/mips/pci/pci-xtalk-bridge.c` (Bridge and
  XBridge, PIC and TIOCP register layout as the driver uses it), `arch/mips/include/asm/sn/` and
  `arch/mips/sgi-ip27/` (Hub and node code, in the 2.4-era history), `arch/mips/sgi-ip30/` (HEART),
  `drivers/ioc3/` and `drivers/net/ethernet/sgi/ioc3-eth.c` (IOC3), `arch/mips/sgi-ip32/` (CRIME, MACE),
  `drivers/video/fbdev/gbefb.c` (GBE). Read from the current tree and from the history for deleted files.
  A header is a driver author's naming, not a hardware measurement.
- **OpenBSD** (the SGI port, last commit before its removal from the tree): `sys/arch/sgi/xbow/`
  (`xbridgereg.h`, `xbow.c`, `xbridge.c`, `widget.h`), `sys/arch/sgi/xbow/` Hub and IOC code, and the
  man pages `xbow(4)` and `xbridge(4)`.
- **NetBSD** `sgimips` port for CRIME, MACE and GBE.
- **Patents** (published): the Bedrock family US 6,751,698, US 6,487,685, US 6,532,501, US 6,546,451,
  US 6,564,277, and the Bridge patents US 5,915,104 and US 6,604,161. A patent states a designer's intent,
  not register layout: labels from them are "inferred".
- **Usenet and mailing lists**: by message-id only, added to the entry that uses them.
- **Published captures** (`hinv` output, PROM console transcripts, `ide` diagnostics): described by what they
  show and how many were read, in the entry that uses them.

Nothing here is a path into any local store.
