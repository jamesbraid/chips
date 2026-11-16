# SN2 SAL: behaviour the kernel cannot show

Question. For each SN SAL call, what does the PROM actually do, and which structure layouts must a synthetic PROM reproduce?

Status: **unknown** beyond what the kernel passes and checks (software/sal/README.md).

- Which of the pointers inside the PROM's descriptors are physical is not settled. The KLCONFIG layout and contents are on [klconfig](../platforms/sn2/klconfig.md) (open items there: the exact heap address, the 350's I/O board type letter, component field meanings).
- What `SN_SAL_IOIF_INTERRUPT` allocates in a bridge and in the SHub for a given request. The SAL 5.04 dispatch and the seven fields copied back are read ([sn2-runtime.md](../software/sal/sn2-runtime.md)); the provider methods that program the SHub and the bridge are not.
- Which result `SN_SAL_PROBE` gives for a machine-checked read: the 5.04 routine maps the helper's zero to 1, and the helper's own convention is unread.
- The L1 message types behind each console call other than the `0x44` text frame (the runtime objects, the putb path and the index a real 350 selects, 1 `sysctl_rt_dev`, are read: see [sn2-runtime.md](../software/sal/sn2-runtime.md#console-0x02000021-to-0x0200002c)).
- The SAL error-record formats the platform error print call interprets.
- Whether the PROM can do without the calls the kernel makes but never needs (see the list of calls with no caller found); only the calls listed in "Calls needed to boot" are known to be required.

Routes: `klconfig.h` and `module.h` in the same v5.3 tree can be read for the KLCONFIG layout; ProPack kernel images could confirm the layouts by DWARF; a PROM image would settle behaviour.
