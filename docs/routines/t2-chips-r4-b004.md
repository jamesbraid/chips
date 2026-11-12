# Routine roles from the chips kernel bridge accessors, tier 2 batch 4

Roles for 25 routines in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o`, each read from its rendered instruction facts: loads,
stores, branches, constants and calls. The routine names come from the inventory and are a hint only. Every entry is
graded inferred, because the facts show the mechanism but not what the selector constants or the stored values mean.

- `pcireg_intr_dst_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf160
  **Inferred.** Set-side accessor that takes a pointer in a0 and returns through 0xf1bc. It reads a 16-bit field at +0x72
  (lh at 0xf184), a doubleword at +0x8 and a word at +0x4, and branches on that field against 3, 2, 0, 1 and -1; the -1
  case goes to the panic call at 0xf2b4. Its stores are the words at 0xf228 and 0xf230 and the doublewords at 0xf24c and
  0xf268, chosen by a second comparison chain against 0xe000, 0xe010, 0xd102, 0xd112, 0xd002, 0xc002 and 0x36. The meaning
  of the selector constants and the stored values is not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_intr_dst_target_id_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf2c4
  **Inferred.** Read-side accessor with the same entry shape: a null check on a0 (beq at 0xf2cc), the 16-bit field at +0x72
  (lh at 0xf2e8) dispatched against 2, 3, 0, 1 and -1 (panic call at 0xf420 for -1), and the same second chain of
  comparisons against 0xe000 to 0xd002 and 0xc002, 0x36. It loads a word from an unknown base at 0xf38c and a doubleword at
  0xf3b0 and returns 0 or an unknown value at 0xf324. Which bridge register it reads is not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_intr_dst_target_id_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf430
  **Inferred.** Set-side accessor. It takes a0, tests it for null (beq at 0xf438 to the panic path), and dispatches the
  16-bit field at +0x72 (lh at 0xf454) against 2, 3, 0, 1 and -1. It stores words at 0xf504 and 0xf51c and doublewords at
  0xf540 and 0xf558 on the paths chosen by the 0xe000 to 0xc002 comparison chain, and panics at 0xf5bc with a1 passed
  through. The return at 0xf48c yields a panic result or an unknown value.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_intr_dst_addr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf5cc
  **Inferred.** Read-side accessor that takes a0, checks it for null at 0xf5d4, and dispatches the 16-bit field at +0x72
  (lh at 0xf5f0) against 2, 3, 0, 1 and -1, with -1 going to the panic call at 0xf73c. It loads words at 0xf694 and 0xf698
  and a doubleword at 0xf6c8 from bases the facts do not name, then returns 0 or an unknown value at 0xf62c. The selector
  constants 0xe000 to 0x36 choose among the loads; their meaning is not shown.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_intr_dst_addr_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf74c
  **Inferred.** Set-side accessor. After the null check at 0xf754 and the dispatch on the 16-bit field at +0x72 (lh at
  0xf770, values 2, 3, 0, 1, -1), it stores words at 0xf81c, 0xf830 and 0xf838 and doublewords at 0xf864 and 0xf87c. The
  -1 case panics at 0xf8e0 with a1 passed through. The return at 0xf7a8 yields a panic result or an unknown value.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_cmdword_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xf8f0
  **Inferred.** Read-side accessor with a null check at 0xf8f8 and the 16-bit field at +0x72 (lh at 0xf914) dispatched
  against 3, 2, 0, 1 and -1, where the -1 case panics at 0xfa48. The 3 and 2 cases branch to different paths (0xf9dc and
  0xf9f8). It loads a word from an unknown base at 0xf9b8 and doublewords at 0xf9e0 and 0xf9fc. The return at 0xf950 is 0
  or an unknown value. The meaning of the command-word error it may serve is not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_llp_cfg_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xfa58
  **Inferred.** Read-side accessor with a null check at 0xfa5c and the 16-bit field at +0x72 (lh at 0xfa78) dispatched
  against 3, 2, 0, 1 and -1. It has two panic calls. The one at 0xfba8 is the -1 target, and the one at 0xfbbc passes a1
  through and sits just after 0xfbb8, the target of the case-3 branch at 0xfa80. It loads a word at 0xfb1c and a
  doubleword at 0xfb44 from unknown bases, and returns 0 or an unknown value at 0xfab4. The link configuration field it
  name-suggests is not confirmed by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_llp_cfg_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xfbcc
  **Inferred.** Set-side accessor that calls splhi at 0xfbdc on entry and splx at 0xfc3c before returning, so the body
  likely runs at a raised interrupt level; the callee names are the only basis for that. It dispatches the 16-bit field at
  +0x72 (lh at 0xfc04) against 3, 2, 0, 1 and -1, stores a word at 0xfcb4 and a doubleword at 0xfcd8, and reads a word at
  0xfcbc and a doubleword at 0xfce0. The selector chain runs against 0xe000 to 0x36. Panics occur at 0xfd44 and 0xfd58,
  and the return at 0xfc48 yields the splx result.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_tflush_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xfd68
  **Inferred.** Read-side accessor with a null check at 0xfd70 and the 16-bit field at +0x72 (lh at 0xfd8c) dispatched
  against 3, 2, 0, 1 and -1; -1 goes to the panic call at 0xfecc. A second failure path calls assfail at 0xfee8 with the
  constant 0x30f as its third argument (a2). It loads a word at 0xfe28 and doublewords at 0xfe64 and 0xfe80 from unknown
  bases, and returns an unknown value at 0xfe44. The routine name suggests a flush of pending transactions, but the facts
  do not show the flush itself.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_linkside_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0xfef8
  **Inferred.** Read-side accessor with a null check at 0xff00 (beq to the panic path at 0x10048), and the 16-bit field at +0x72
  (lh at 0xff1c) dispatched against 3, 2, 0, 1 and -1. It loads a word at 0xffbc and doublewords at 0xffe4 and 0x10000
  from unknown bases, and returns 0 or an unknown value at 0xff54. The link side it names is not confirmed by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_resp_err_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1005c
  **Inferred.** Read-side accessor with a null check at 0x10064 (panic path at 0x101bc) and the 16-bit field at +0x72 (lh
  at 0x10080) dispatched against 3, 2, 0, 1 and -1. It loads words at 0x10124 and 0x10128 and doublewords at 0x10158 and
  0x10174 from unknown bases, and returns 0 or an unknown value at 0x100bc. The response-error role is named, not shown.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_resp_err_addr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x101d0
  **Inferred.** Read-side accessor with a null check at 0x101d8 and the 16-bit field at +0x72 (lh at 0x101f4) dispatched
  against 2, 3, 0, 1 and -1; -1 goes to the panic call at 0x1033c. It loads words at 0x10294 and 0x10298 and a doubleword
  at 0x102c8, and returns 0 or an unknown value at 0x1022c. The address it name-suggests is not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_resp_err_buf_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1034c
  **Inferred.** Read-side accessor with a null check at 0x10354 and the 16-bit field at +0x72 (lh at 0x10370) dispatched
  against 2, 3, 0, 1 and -1; -1 goes to the panic call at 0x104b0. It loads a word at 0x10414 and a doubleword at 0x10440
  from unknown bases, and returns 0 or an unknown value at 0x103ac. The buffer role is named, not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_resp_err_dev_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x104c0
  **Inferred.** Read-side accessor with a null check at 0x104c8 (beq to the panic path at 0x10620) and the 16-bit field at +0x72 (lh at 0x104e4)
  dispatched against 3, 2, 0, 1 and -1. It loads a word at 0x10588 and a doubleword at 0x105b4 from unknown bases, and
  returns 0 or an unknown value at 0x10520. Which device the error names is not shown; the panic call at 0x10624 takes
  only the message and unknown arguments.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_linkside_err_addr_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x10634
  **Inferred.** Read-side accessor with the 16-bit field at +0x72 (lh at 0x10658) and a doubleword at +0x8 and a word at
  +0x4 read from a0. It has two panic calls, at 0x10760 and 0x10780, the second with a5 set to 0x24, and returns
  0 or an unknown value at 0x10694. The address role is named, not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_dirmap_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x10790
  **Inferred.** Read-side accessor with the 16-bit field at +0x72 (lh at 0x107b4) dispatched against 2, 3, 0, 1 and -1,
  a word loaded from an unknown base at 0x10858 and doublewords at 0x10880 and 0x1089c. The panic call at 0x108e8 is the only call in the routine.
  The return at 0x107f0 is 0 or an unknown value. The direct-map role is named, not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_dirmap_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x108f8
  **Inferred.** Set-side accessor with the 16-bit field at +0x72 (lh at 0x1091c). It stores a word at 0x109bc and
  doublewords at 0x109d8 and 0x109f4, and calls panic at 0x10a40 with a1 passed through. The return at 0x10950 gives 3, an
  unknown value, or a panic result. The purpose of the stored direct-map values is not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_dirmap_wid_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x10a50
  **Inferred.** Set-side accessor with the 16-bit field at +0x72 (lh at 0x10a74). It stores words at 0x10b20 and 0x10b38 and
  doublewords at 0x10b60 and 0x10b78, and panics at 0x10bdc with a1 passed through. The return at 0x10aa8 gives 2, an
  unknown value, or a panic result. The widget role the name suggests is not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_dirmap_diroff_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x10bec
  **Inferred.** Set-side accessor with the 16-bit field at +0x72 (lh at 0x10c10). It stores words at 0x10cc0 and 0x10cd8
  and six doubleword sites, including 0x10d00, 0x10d14 and 0x10d28, and panics at 0x10dcc with a1 passed through and a5
  set to -1. The return at 0x10c48 is an unknown value or a panic result. The offset role is named, not shown.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_dirmap_add512_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x10ddc
  **Inferred.** Set-side accessor with the 16-bit field at +0x72 (lh at 0x10e00). It reads a word at 0x10ea0, stores a word
  at 0x10eb0 and doublewords at 0x10ed8 and 0x10f00, and panics at 0x10f4c. The return at 0x10e38 is an unknown value or a
  panic result. The 512-entry window the name suggests is not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_dirmap_add512_clr` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x10f5c
  **Inferred.** Set-side accessor with the 16-bit field at +0x72 (lh at 0x10f80). It reads a word at 0x1101c, stores a word
  at 0x11030 and doublewords at 0x1105c and 0x11088, and panics at 0x110d4. The return at 0x10fb4 gives 3, an unknown
  value, or a panic result. The clear role is suggested by the name and its pairing with the add512_set entry, not by
  the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_ssram_parity_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x110e4
  **Inferred.** Read-side accessor with the 16-bit field at +0x72 (lh at 0x11108). It loads a word at 0x111ac from an
  unknown base, and has two panic calls, at 0x11234 and at 0x11248 with a5 set to 0x24. It returns 0 or an
  unknown value at 0x11144. The SSRAM parity role is named, not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_map_fault_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x11260
  **Inferred.** Read-side accessor with the 16-bit field at +0x72 (lh at 0x11284). It loads a word at 0x11324 from an
  unknown base, and has two panic calls, at 0x113b8 (a5 set to 0xc002) and 0x113c4. It returns 0 or an unknown
  value at 0x112c0. The map-fault role is named, not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_arbitration_get` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x113d4
  **Inferred.** Read-side accessor with the 16-bit field at +0x72 (lh at 0x113f8). It loads a word at 0x1149c from an
  unknown base, and panics at 0x1152c. It returns 0 or an unknown value at 0x11434. The arbitration role is named, not
  shown by the facts.
  Reviewed: 2026-11-12 (sonnet)

- `pcireg_arbitration_set` in `IP27/usr/cpu/sysgen/IP27boot/pcibr.o` at 0x1153c
  **Inferred.** Set-side accessor with the 16-bit field at +0x72 (lh at 0x11560). It stores a word at 0x11604 and
  doublewords at 0x11620 and 0x1163c, and panics at 0x11688 with a1 passed through. The return at 0x11598 is an unknown
  value or a panic result. The arbitration value it writes is not shown by the facts.
  Reviewed: 2026-11-12 (sonnet)
