# Xbow routines of the IP30 kernel

Routines of `IP30/unix` (the linked IRIX 6.5 kernel for the Octane; addresses are virtual addresses) that reach the
crossbar's per-link register blocks. A link block is 0x40 bytes and the registers below are the 32-bit words at the offsets
the [Xbow page](../chips/xbow/README.md) lists. A bare number such as `-15456` addresses the process page below zero.

- `xbow_reset_link` (`IP30/unix` `0xa80000002003d430`, 236 bytes, frame 48 bytes)
  resets one crossbar link and waits for it to come back, returning 0 when it did and -1 when a timed wait ran out. The
  argument (`a0`) is a widget vertex: `xwidget_info_get` turns it into the widget information and `xwidget_info_id_get`
  gives the widget number, which is masked with 7, shifted left by 6 and added to the window constant
  0x9000000010000000 (the doubleword in the literal pool at 0xa8000000204a87f0) to find the link block. It
  first reads the word at block +0x10c (the low half of the link control register) and keeps it at 0(sp), then stores a
  zero word at +0x134 (the link reset register), and calls `us_delay` with the word `xbow_reset_delay`
  (0xa8000000204a7724, 20 in this image). It then takes the low 32 bits of the free-running counter at
  0xffffffffaff20000 as a start time and polls bit 31 of the word at block +0x114 (the link status register). When the
  bit is set it writes the saved word back to +0x10c and returns 0. When it is clear it subtracts the start time from the
  counter (32-bit) and, unless that exceeds the word at 0xa8000000204a7728, calls `us_delay` with `xbow_reset_delay` again and
  polls again; once the limit is exceeded it returns -1 without the write-back. The limit word starts at 0: on entry
  the routine finds it zero, reads the counter, calls `us_delay` with 1000 and stores the counter difference there, so the
  limit is the number of counter ticks in 1000 microseconds, and later calls reuse it. Established.
- `xbow_widget_present` (`IP30/unix` `0xa80000002003be48`, 100 bytes, no frame) says whether the link of one widget
  counts as populated. `a0` is the window of the crossbar and `a1` the widget number. It reads the identification word at
  window +0x4 and branches to the link test unless the part number (bits 27:12) is 0xd100, the manufacturer field
  (bits 11:1) is 0 and `a1` is 15, in which case it returns 1 without reading the link (the `li` that sets v0 to 1 is
  at the first instructions, so the exit's delay slot leaves it). The first branch, taken when 1 shifted left by the
  revision field (bits 31:28) is zero, cannot be taken for a four-bit revision. For every other case the result is the
  word at link block +0x13c ANDed with 0x20, where the block is the window plus (`a1` & 7) times 0x40. Nothing is
  stored. Established.
