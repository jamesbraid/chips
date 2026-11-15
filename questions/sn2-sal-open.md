# SN2 SAL: behaviour the kernel cannot show

Question. For each SN SAL call, what does the PROM actually do, and which structure layouts must a synthetic PROM reproduce?

Status: **unknown** beyond what the kernel passes and checks (software/sal/README.md).

- Which of the pointers inside the PROM's descriptors are physical is not settled. The KLCONFIG layout and contents are on [klconfig](../platforms/sn2/klconfig.md) (open items there: heap address, the 350's I/O board type, component field meanings).
- What `SN_SAL_IOIF_INTERRUPT` allocates in a bridge and in the SHub for a given request.
- The SAL error-record formats the platform error print call interprets.
- Whether the PROM can do without the calls the kernel makes but never needs (see the list of calls with no caller found); only the calls listed in "Calls needed to boot" are known to be required.

Routes: `klconfig.h` and `module.h` in the same v5.3 tree can be read for the KLCONFIG layout; ProPack kernel images could confirm the layouts by DWARF; a PROM image would settle behaviour.
