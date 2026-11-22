# NUMAlink 4 router: what the PROM tables leave open

Question. What does each NUMAlink 4 router register do, what does a router reset to, and what does the firmware program
into it? The register numbers, names and bit ranges are in [devices/router_nl4](../devices/router_nl4/README.md). Nothing
held gives a reset value, a field encoding or a specification.

Status: **unknown** beyond names and positions. Route tag: software now (the PROM images are in `root/sn2/`), plus
missing source for any value no software reads.

Open items, each with the route that settles it:

- Settled in [global-config.md](../devices/router_nl4/global-config.md): `nl4r_config_global` (clock-source select per
  connected port, under the router lock), the table writer and the table lengths (512, 256 and 8 per port).
- What a direction value in a routing-table entry selects, and the `0xf` terminator nibble of the vector route
  register. **Partly settled** in the SHub 1 SAL 5.04 image: a router entry is a count of "turns", `(out - in)` modulo 8
  with 1-based ports, `0xf` is "no route", and the route register holds absolute output ports with `0xf` in nibble 8
  when no hop remains ([boot-sequence.md](../software/firmware/snprom/boot-sequence.md#numalink-discovery-with-a-linked-port-the-neighbour-crawl-sal-504)).
  Open: the node-end values 0 and 4, why nibble 8 is set to `0xf`, and the SHub 2 routine `0xff4663d0` itself (SHub 1
  counterpart `0xffa5a670`).
- The inputs of the table writer (`0xff471a80`): which call uses compare mode and which write-everything, which router
  gets six and which two multicast translation writes, the `set_force_local` value and the multicast `NODE_ID`
  arithmetic. Route: its caller `0xff467320` and the graph record it walks.
- The `RTC_SOURCE` select encoding (`0xf` after initialisation), the `0x2008` timestamp and the node method behind it,
  the units of the router lock timeout, and whether `0x1038` is a read-and-set. Route: the node method at slot `0x160`
  (SHub 2 `0xff4ae400`); the encodings and units may have no software route.
- The order of the three router phases in one boot (table distribution, the board walk that sets the clock source, the
  partition fences). Route: the callers of `0xff42cd80` and `0xff4e7470` in SHub 2 SAL 10.54.
- Altix 350 single-plane cabling: the guide's prose contradicts its tables. Page 69 puts the router on "port 0" of up
  to eight modules, with modules 9 to 16 on the open "port 1" of those eight. Table 2-3 (pp.81 to 82), Figure 2-12
  (p.83) and Figure 2-3 (p.70) put the router on NUMAlink 1 of modules 5 to 12, and pair modules 1 to 4 with 5 to 8
  and 9 to 12 with 13 to 16 on NUMAlink 0. The tables, the figures and the dual-plane Table 2-4 agree with each other,
  so [platforms/sn2/altix-350.md](../platforms/sn2/altix-350.md) uses the table reading (inferred). Unknown: which one
  a cabled single-plane system matches. -001 has no router text, and no -003 or -004 was located.
  Route: a photograph of a cabled single-plane system, or an SGI errata notice for -002. Neither was located.
- Altix 350 router L1: its address. The -002 guide gives the router one L1 controller and one L1 USB port (pp.150,
  152 to 154) and no address. The L1 and L2 guide 007-3938-005 addresses a brick by USB port, L1 index, rack, type
  character and slot (pp.10, 49, 69), and uses `r` for the R-brick (Table 3-1, p.70), but it shows no Altix 350 router.
  Unknown: the L1 index the L2 uses for a router behind the router's USB hub, and whether the L2 `cfg` listing
  shows the router (the guide describes that listing on p.56 but prints none). Route: an L2 `cfg` listing from a cabled
  Altix 350 with a router.
- Reply type codes 4, 5 and 6 of the vector status register. **Mapping settled, meaning not:** the SHub 1 image reports
  6 as "Hub got protection err from rtr" and 4 and 5 as "Hub NI saw too many link errors"; the "Vector Request Route
  Error" and "Vector Reply Route Error" strings are bits 14 and 15 of an error-summary decode table, and "VERRA",
  "VERRC", "VERAC" are message-type names, so no reply type is tied to them
  ([node-access.md](../devices/router_nl4/node-access.md#shub-1-sal-504-the-vector-request-as-the-image-sends-it)).
  Route: the SHub 2 image's vector-status decoder, or a hardware capture (owner approval).
- The vector write path. **Settled** for SHub 1: type bit 1, `PIO_ID` `0x7b`, the same software lock (number 9), the same
  error-summary poll; the SHub 2 write is `0xff41ad30`, not compared line by line.
- Whether the router decodes address bit 32 (the SHub 1 PROM reads register 0 with address `0x1_0000_0000`), the
  framing of the router's system-controller mailbox (`0x30` to `0x48`) and the PROM's wait per request. Route: the
  `sysctl_vec_*` request builders in the SHub 1 image (`0xffa8f900` and its callers) and the sysco repository.
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
