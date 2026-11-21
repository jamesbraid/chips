# SN2 SAL: behaviour the kernel cannot show

Question. For each SN SAL call, what does the PROM actually do, and which structure layouts must a synthetic PROM reproduce?

Status: **unknown** beyond what the kernel passes and checks (software/sal/README.md).

- Which of the pointers inside the PROM's descriptors are physical is not settled. The KLCONFIG layout and contents are on [klconfig](../platforms/sn2/klconfig.md) (open items there: the exact heap address, the 350's I/O board type letter, component field meanings).
- `SN_SAL_IOIF_INTERRUPT`: settled for SHub 1 in SAL 5.04 and 4.90 ([allocator](../devices/shub/interrupts.md#the-firmwares-interrupt-allocator-sn_sal_ioif_interrupt)). Open: the SHub 2 build, the TIO methods (decompile only), the first cookie value, and the topology distance function.
- Which result `SN_SAL_PROBE` gives for a machine-checked read: the 5.04 routine maps the helper's zero to 1, and the helper's own convention is unread.
- The L1 message types behind each console call other than the `0x44` text frame (the runtime objects, the putb path and the index a real 350 selects, 1 `sysctl_rt_dev`, are read: see [sn2-runtime.md](../software/sal/sn2-runtime.md#console-0x02000021-to-0x0200002c)).
- The SAL error-record formats the platform error print call interprets.
- Whether the PROM can do without the calls the kernel makes but never needs (see the list of calls with no caller found); only the calls listed in "Calls needed to boot" are known to be required.
- Which Linux trees call `SN_SAL_PROBE` (`0x02000003`). The stock PROM, ProPack 2.6.5-7.244-sn2 and RHEL 2.6.18-398 never issued it in an emulator run (2026-11-21). [sn2-runtime.md](../software/sal/sn2-runtime.md) cites a 2.6.12 `pci_dma.c` caller, which that run does not check. Route: software now; a text search of the 2.4.37, 2.5.40 and 2.6.12 sources for the id.
- What the PROM does for `SN_SAL_NO_FAULT_ZONE_VIRTUAL` (`0x02000010`). The stock kernels called it and got 0 back in the emulator run. [runtime-services.md](../software/sal/runtime-services.md) has no row for it. Route: software now; read the handler that registers the region, and the status it returns, in the runtime table.
- Which routine issues `0x02000057` before any OS. The emulator run saw three calls in the PROM and EFI phase (devfn 0x8, 0x18, 0x20), before ProPack's three boot calls. The IOIF dispatcher is listed as OS-facing. Route: software now; the callers of the dispatcher in the EFI phase.
- Which operation `0x02000013` ran in physical mode during ELILO. The emulator run saw it twice. The page's row covers only the SetVirtualAddressMap case. Route: software now; read the other cases of the handler and the callers in the EFI component.

Routes: `klconfig.h` and `module.h` in the same v5.3 tree can be read for the KLCONFIG layout; ProPack kernel images could confirm the layouts by DWARF; a PROM image would settle behaviour.
