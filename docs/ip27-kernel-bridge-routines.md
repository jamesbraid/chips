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
- `pcireg_type0_cfg_addr` (`IP27/unix` at 0xc000000000088480,
  688 bytes) forms the address of a PCI type 0 configuration-space word on a Bridge-family chip. It takes either a raw register-block
  pointer or the driver's per-chip record in `a0`, the slot in `a1`, the function in `a2` and the byte offset in `a3`. A null `a0`
  panics ("pcireg_type0_cfg_addr(): unknown bridgetype"). A pointer whose top byte pattern matches `0x92...` (a raw alias) is typed from the
  32-bit identification word at +4: part `0xe000` or `0xe010` with manufacturer field 0x24 (bits 11:1) and `0xd102` or `0xd112` with 0x24 take the
  "slot 1 to 4" form, `0xd002` with 0x24 and `0xc002` with 0x36 take the "slot 0 to 7" form; any other part falls to the panic. A record
  pointer reads the type halfword at +0x72 and the base address from +0x8: type 3 and 2 use the slot-1-to-4 form, types 0 and 1 the
  slot-0-to-7 form, a type of -1 falls to the panic and anything else returns 0. The slot-1-to-4 form uses `(slot + 1) & 0xff`, asserting
  it is 1 to 4 (`assfail`, source lines 0xb68 and 0xb70 for the two types), the slot-0-to-7 form uses the slot itself, asserting 0 to 7
  (line 0xb75). Both return `base + slot * 0x1000 + function * 0x100 + (offset / 4) * 4 + 0x20000`, with the offset divided by four
  rounding toward zero. It touches no register. Established: the dispatch and address formula. Inferred: that the part numbers map to Bridge
  (0xc002), XBridge (0xd002), PIC (0xd102, 0xd112) and TIOCP (0xe000, 0xe010), as the Bridge-family dispatch elsewhere assumes.
- `pcireg_int_ate_set` (`IP27/unix` at 0xc0000000000890d4,
  620 bytes) writes one internal address-translation entry of a Bridge-family chip. It takes the register-block pointer or per-chip
  record in `a0`, the entry index in `a1` and the value in `a2`, and does one doubleword store, `sd`, of `a2` at `base + index * 8 +
  0x10000`. The typing, bounds and panic are those of `pcireg_int_ate_get`: a null `a0` panics ("pcireg_int_ate_set(): unknown
  bridgetype"), parts 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 allow index 0 to 1024 inclusive and part 0xc002 with manufacturer 0x36 allows
  0 to 128 inclusive, record type 3, 2 and 1 allow 0 to 1024 and type 0 allows 0 to 128; a type of -1 panics and any other type returns without
  a store. An index outside the range calls `assfail` with the source lines 0xc1c (type 3), 0xc20 (type 2), 0xc24 (type 1) or 0xc28
  (type 0); the check is `index <= limit`. It returns nothing. Established. Inferred: that the entries are the internal translation table
  of the chip, from the routine's identifier and the 0x10000 base.
- `pcireg_int_ate_get` (`IP27/unix` at 0xc000000000088e68,
  620 bytes) reads one internal address-translation entry of a Bridge-family chip. It takes the chip's register-block pointer or the
  driver's per-chip record in `a0` and the entry index in `a1`, and returns the doubleword at `base + index * 8 + 0x10000`. A null `a0`
  panics ("pcireg_int_ate_get(): unknown bridgetype"). A pointer whose upper bits match `0x92...` is typed by the identification word at
  +4: part 0xe000 or 0xe010 and part 0xd102 or 0xd112 (manufacturer field 0x24) and part 0xd002 (0x24) allow indexes 0 to 1024
  inclusive, part 0xc002 with manufacturer 0x36 allows 0 to 128 inclusive. A record pointer is typed by the halfword at +0x72 (types 3,
  2 and 1 allow 0 to 1024, type 0 allows 0 to 128; -1 panics, any other value returns 0) and its base comes from +0x8. An index outside the
  range calls `assfail` with the source lines 0xbfd (type 3), 0xc01 (type 2), 0xc05 (type 1) or 0xc09 (type 0). The check is `index <= limit`,
  so the index equal to the limit passes. It is one doubleword load, `ld`, from the entry, with no other register access. Established.
  Inferred: that the four parts are Bridge, XBridge, PIC and TIOCP, as `pcireg_type0_cfg_addr` assumes.
- `pcireg_wrb_flush_get` (`IP27/unix` at 0xc000000000086e94,
  596 bytes) reads the write-buffer flush register of one device slot of a Bridge-family chip and returns what it read. It takes the chip's register-block pointer or the
  driver's per-chip record in `a0` and the device number in `a1`. A null `a0` and a record type of -1 call `panic` ("pcireg_wrb_flush_get(): unknown bridgetype") and
  return 0; a record type other than -1 to 3 returns 0. A record of type 3 or 2 checks `device <= 3` (`assfail`, source lines 2506 and 2510) and loads the doubleword at
  +576 + 8 * device (0x240 + 8n) of the base at record +0x8; types 0 and 1 check `device <= 7` (line 2515) and load the word at +580 + 8 * device (0x244 + 8n),
  zero-extended. After the load it calls `assfail` (line 2523, text "ret == 0") when the value is not zero, and returns the value in either case.
  A raw window pointer (upper bits `0x92...`) is typed from the identification word at +4: parts 0xe000 and 0xe010 with manufacturer field 36
  take the type 3 path, 0xd102 and 0xd112 with 36 the type 2 path, and 0xd002 with 36 and 0xc002 with 54 the word path; any other part
  panics. Established. Inferred: that the register is the chip's write-buffer flush, from the routine's name and the `ret == 0` check on the value.
- `pcireg_int_ate_addr` (`IP27/unix` at 0xc000000000089340,
  596 bytes) returns the address of one internal address-translation entry of a Bridge-family chip instead of reading it. It takes the chip's register-block pointer or the
  per-chip record in `a0` and the entry index in `a1`, and returns the base plus `index * 8 + 0x10000`, where the base is the raw pointer or the doubleword at record +0x8. A
  record of type 3, 2 or 1 accepts indexes up to and including 1024 (`assfail` with source lines 3131, 3135 and 3139) and type 0 up to and including 128 (line 3143);
  the same limits follow from the raw dispatch: parts 0xe000, 0xe010, 0xd102, 0xd112 and 0xd002 (manufacturer 36) allow 1024 and 0xc002 (manufacturer 54) allows 128.
  A null `a0`, a type of -1 or an unknown raw part calls `panic` ("pcireg_int_ate_addr(): unknown bridgetype") and returns 0; any other record type returns 0 without a
  message. It touches no register. Established. Inferred: that the entries are the chip's address-translation table, from the 0x10000 base shared with the get and set accessors.
- `pcireg_intr_addr_addr_set` (`IP27/unix` at 0xc000000000085a7c,
  588 bytes) replaces the address part of one interrupt-address register of a Bridge-family chip. It takes the chip's register-block pointer or record in `a0`, the interrupt
  number 0 to 7 in `a1` (`assfail`, source line 2202) and the address in `a2`, and returns nothing. For types 2 and 3 (doubleword layout) it works on the doubleword at +0x130 + 8n:
  it stores the value with bits 47:0 cleared (mask 0xffff000000000000), reloads it and stores it again with `a2 & 0xffffffffffff` ORed in. For types 0 and 1 it works on the word at
  +0x134 + 8n: it clears bits 17:8 (mask 0xfffffffffffc00ff, read from the pool at `gp - 23336`), stores, reloads and stores again with `(a2 >> 30) & 0x3ff00` ORed in, so
  address bits 47:38 land in bits 17:8. A null `a0` or a type of -1 calls `panic` with the text "pcireg_intr_addr_addr_get(): unknown bridgetype", the name of the getter
  rather than this routine, and a type outside -1 to 3 returns. Established. Inferred: that the field is the address of the interrupt target, from the routine's name and the way the getter shifts it.
- `pcireg_intr_addr_vect_set` (`IP27/unix` at 0xc000000000085610,
  572 bytes) stores the vector byte of one interrupt-address register of a Bridge-family chip. It takes the register-block pointer or record in `a0`, the interrupt number 0 to 7 in `a1`
  (`assfail`, source line 2139) and the vector in `a2`, and returns nothing. For types 2 and 3 it clears bits 55:48 of the doubleword at +0x130 + 8n (mask 0xff00ffffffffffff, from
  the pool at `gp - 24280`), stores it, reloads it and stores it again with `(a2 & 0xff) << 48` ORed in. For types 0 and 1 it clears the low byte of the word at +0x134 + 8n (mask -256),
  stores, reloads and stores with `a2 & 0xff` ORed in. A null `a0` or a type of -1 calls `panic` with "pcireg_intr_addr_vect_get(): unknown bridgetype", the getter's name, and
  a type outside -1 to 3 returns. Established. Inferred: that the byte is the interrupt vector, from the routine's name and the matching getter.
- `pcireg_device_bit_clr` (`IP27/unix` at 0xc000000000086c58,
  572 bytes) clears bits in the device register of one slot of a Bridge-family chip. It takes the register-block pointer or record in `a0`, the device number in `a1` and the bits to clear in `a2`,
  and returns nothing. Types 0 and 1 check `device <= 7` (`assfail`, source line 2483) and AND the complement of `a2` into the word at +0x204 + 8 * device with one load and one 32-bit store;
  types 3 and 2 check `device <= 3` (lines 2474 and 2478) and do the same on the doubleword at +0x200 + 8 * device with `ld` and `sd`. A null `a0` or a type of -1 calls
  `panic` ("pcireg_device_bit_clr(): unknown bridgetype"); another type returns. Raw pointers are typed from the identification word by the same six parts (0xe000, 0xe010, 0xd102, 0xd112, 0xd002, 0xc002)
  as the other accessors. Established. Inferred: that the register is the per-device configuration register, from its slot stride and the 0x200 base shared with `pcireg_device_get`.
- `pcireg_device_bit_set` (`IP27/unix` at 0xc000000000086a24,
  564 bytes) sets bits in the device register of one slot of a Bridge-family chip. It takes the register-block pointer or record in `a0`, the device number in `a1` and the bits to set in `a2`, and returns nothing.
  Types 0 and 1 check `device <= 7` (`assfail`, source line 2456) and OR `a2` into the word at +0x204 + 8 * device (`lw`, `sw`); types 3 and 2 check `device <= 3` (lines 2447 and 2451) and OR it into the
  doubleword at +0x200 + 8 * device (`ld`, `sd`). A null `a0` or a type of -1 calls `panic` ("pcireg_device_bit_set(): unknown bridgetype"); a type outside -1 to 3 returns. The raw-pointer dispatch accepts parts 0xe000
  and 0xe010 into the type 3 path, 0xd102 and 0xd112 into the type 2 path, and 0xd002 and 0xc002 into the word path. Established. Inferred: that the register is the per-device configuration register, from the 0x200 base and slot stride.
