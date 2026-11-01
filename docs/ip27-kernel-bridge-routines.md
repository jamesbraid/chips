# Routines of the IP27 kernel that serve the Bridge family

Read in full from the linked IRIX 6.5.30 IP27 kernel (`IP27/unix`); addresses are the kernel's own. The routines are the Bridge-family attach path and register accessors,
which choose among Bridge, XBridge, PIC and TIOCP at run time as described in [chips/bridge/README.md](../chips/bridge/README.md).

- `xbridge_attach` (`IP27/unix` at 0xc0000000000703ac,
  2592 bytes) attaches a Bridge or XBridge on a Crosstalk widget and builds the driver's per-chip record; `a0` is the widget vertex. It returns 0 after a complete attach and -1 when the chip is an original Bridge not in PCI mode. It prints the debug lines "pcibr_attach" and "pcibr_attach: bridge=0x%lx"
  (`pcibr_debug`, level 4), calls `hub_device_flags_set` (vertex, 1) and gets the register base with `pcibr_bridge_ptr_get` (vertex, 0).
  For part 0xc002 with manufacturer 0x36 (bits 27:12 and 11:1 of the identification word at +4) it reads the status register through
  `pcireg_stat_get` and returns -1 unless bit 5 is set. It adds the vertex path "pci" (`hwgraph_path_add`), registers and starts the
  provider `pci_xbridge_provider`, adds the character device "pcibr_" named "controller", reads the card's serial-number
  string (`pcireg_nic_addr`, `nic_bridge_vertex_info`) and the optional hints (`pcibr_hints_get`); when the hints say not to attach (word
  +0xc nonzero) it also returns -1. Otherwise it reads the identification word
  (`pcireg_id_get`), forms `revision | (part << 4)` (bits 31:28 and 27:12), attaches it under the label `_pcibr_asic_rev` and allocates and zeroes the
  0xab8-byte record (`kmem_zalloc`, `memset`), storing: widget vertex at +0, controller vertex at +4, register base at +8, the vertex name at
  +0x10 (`vertex_to_name`, copied), interrupt-bit table `pcibr_intr_bits` at +0x500, revision code at +0x78, type halfword at +0x72 (1 for part 0xd002
  with manufacturer 0x24, else 0), the entry count at +0x70 (0x400 for XBridge, 0x80 for Bridge with its slot-limit bytes), mode and speed bits at +0x74, the
  widget number at +0x28, master at +0x2c and master id at +0x30, first and last slot bytes at +0x38 and +0x39 (0 and 7), and initialises
  the lock at +0x80. For revision codes below 0xc0024 it stores 0x2000 into two words at +0xa98 and +0xa9c and clears bits 9:0 of the PCI bus
  timeout (`pcireg_timeout_bit_clr` 0x3ff). It then sets up the per-slot arrays, honouring hints, and eight interrupt-bit records, registers
  the widget error handler `pcibr_error_handler`, resets the interrupt state (`pcireg_intr_reset_set` 0x7f, `pcireg_intr_device_set`
  0xffffffff), runs `pcibr_directmap_init`, sets control bit 21 (`pcireg_control_bit_set` 0x200000), clears every internal translation entry with
  `pcireg_int_ate_set(record, i, 0)`, sizes external entries with `pcibr_init_ext_ate_ram` on a Bridge, creates the entry maps with `rmallocmap` and
  `pcibr_ate_free`, allocates the error interrupt (`xtalk_intr_alloc`, name "Bridge error", connected to `pcibr_error_intr_handler` with
  `pcibr_setwidint`), enables interrupts (OR with the mask `0x3eff7ffffe00`; clears bit 28 below revision 0xc0023; for 0xc0022 sets bit 20 and
  ANDs `0xffffffbbffff77ff`; mode 0; `pcireg_tflush_get`), sets prefetch and write-gather bits in +0x7c by revision, creates three PCI window maps
  (0x10000000/0x100000, 0x100000/0x4000, 0x40000000/0x100000) and runs the slot initialisers (`pcibr_slot_info_init`,
  `_addr_space_init`, `_device_init`, `_guest_info_init`), `pcibr_initial_rrb` (and `pcibr_rrb_alloc_init` for a card with the "030-1275-"
  prefix), the per-slot device attach and `pciio_device_attach`. Established for the order and constants above. Inferred: the role of
  the record fields, from their later users and the debug strings.
- `pcibr_alloc_all_rrbs` (`IP27/unix` at 0xc000000000077074,
  980 bytes) sets the read-response-buffer assignment of one PCI bus controller from per-device counts. It takes the controller vertex in `a0`
  and the bus number in `a1`; the device counts for the four device groups are `a2`, `a4`, `a6` and the first stack argument, and the counts reserved
  for the second kind of buffer are `a3`, `a5`, `a7` and the second stack argument. The result is 0, or -1 for a bad request. It finds the
  register block through `hwgraph_traverse` on the vertex's "pci" child and `hwgraph_fastinfo_get` (the pointer at +0x8 of the record),
  falling back to `xtalk_piotrans_addr` (offset 0, length 8) when the child is missing. Where the identification word at +4 shows part 0xc002
  with manufacturer 0x36 or part 0xd002 with 0x24 the shift selector is 2, any other chip uses 1 and returns -1 when the third and fourth
  device counts or either of their reserved counts is nonzero. The four device counts must be nonnegative and sum to 8 or less, else -1.
  It builds a 32-bit word of eight 4-bit fields from bits 31:28 downward: for each device i = 0 to 3, first one field `i | (1 << selector) | 8`
  for each reserved buffer (reducing that device's remaining count by one each time), then one field `i | 8` for each remaining buffer
  (bit 3 enables the field). With the record present it takes the lock at +0x80 (`mutex_spinlock`), writes the word with
  `pcireg_rrb_set` (register block, bus number AND 1, word), sets the bits `0x55 << (bus & 1)` in the record word at +0x51c, zeroes the four
  words at +0x528 to +0x540 (stride 4 per bus), stores `8 - total` at +0x520 + 4 * bus, and for each device (stride 0x10 per bus) stores the
  reserved count at +0x56c, +0x58c, +0x5ac and +0x5cc and the remainder (device count minus reserved) at +0x568, +0x588, +0x5a8 and +0x5c8; it releases the
  lock with `mutex_io_spinunlock` and returns 0. Established. Inferred: that the fields name read-response buffers, from the routine name and the
  `pcireg_rrb_set` callee.
