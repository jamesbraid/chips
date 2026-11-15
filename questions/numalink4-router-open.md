# NUMAlink 4 router: what the PROM tables leave open

Question. What does each NUMAlink 4 router register do, what does a router reset to, and what does the firmware program
into it? The register numbers, names and bit ranges are in [devices/router_nl4](../devices/router_nl4/README.md). Nothing
held gives a reset value, a field encoding or a specification.

Status: **unknown** beyond names and positions. Route tag: software now (the PROM images are in `root/sn2/`), plus
missing source for any value no software reads.

Open items, each with the route that settles it:

- Router global and routing-table programming: `nl4r_config_global` (SHub 2 SAL 10.54, string address referenced from
  about `0xff4c84b6`; the Ghidra export found no function at that address) and the callers that fill the local, global
  and neighbour tables from the computed routes. Settles the global parameters values, what a `DIR0` value selects, the
  table lengths and the meaning of the `0xf` terminator nibble in the vector route register.
- Reply type codes 4, 5 and 6 of the vector status register and which of the PROM's vector error strings each is.
  Route: the PROM's error decoder around the "Vector Request Route Error" strings, and the callers of the vector read.
- The vector write path: the type bit value and whether the same lock is used. Route: the write routine beside the
  read routine at `0xff419e80`.
- The router serial number ("NIC") read the PROM console exposes as `rnic`: which register or channel. Route: the
  console command's handler and the L1 mailbox registers `ASIC_TO_L1_*` and `L1_TO_ASIC_*`.
- The L1 mailbox protocol (`ASIC_TO_L1_STATUS`, `_DATA`, `L1_TO_ASIC_STATUS`, `_DATA`): the PROM's `sc_nl4r_*` routines
  carry the system controller conversation over it. Route: read those routines; the sysco repository holds the
  controller side.
- Link-layer state encodings (`LINK_SEND_FSM_STATE`, `LINK_RCV_FSM_STATE`, `LINK_RESET_STATE` values), units of the
  deadlock, tail and retry timeouts and the credit and debit parameters. Route: the chip-error and link-retrain code
  ("Link retrained after %d ms", `intcon_chklink`) and the Linux `sn_hwperf` heap contents; may have no software route.
- What `SN_HWPERF_GET_MMRS` addresses mean for a router object, and whether any ProPack kernel module reads router
  registers. Route: the SAL `hwperf_op` handler in the PROM and the ProPack kernel's `sn_hwperf` symbols.
- Reset values of every router register: no code reads one before writing it (not checked exhaustively); physical read
  of a router needs the owner's approval and is not planned.
- Whether NUMAlink 4 router registers in the Altix 350 router option, the 3700 Bx2 CR-brick and the 4700 IRU are the
  same: one table covers all of them in the PROM (inferred identical, no per-product difference found).
- Does the Altix 3000 R-brick chip (part `0x3017`) match the Origin 3000 router register-for-register? The numbers
  agree; no per-register behaviour compared.
