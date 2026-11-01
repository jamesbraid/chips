# Bridge-family accessors and attach routines of the IP30 kernel

Read in full from `IP30/unix` (the linked IRIX 6.5 kernel for the Octane; addresses are virtual addresses). The `pcireg_*`
accessors below share one preamble, described here once. Each takes the chip handle in `a0`. A handle with bits 63 and 60 both
set (`(a0 & 0x9000000000000000) == 0x9000000000000000`) is a raw register window: the routine reads the identification word
at window +0x4 and derives the chip type from its part and manufacturer fields. Part `0xe000` or `0xe010` with manufacturer 36
gives type 3, `0xd102` or `0xd112` with 36 gives type 2, `0xd002` with 36 gives type 1 and `0xc002` with manufacturer 54 gives
type 0; any other part gives type -1. A nonzero handle without those two bits is a driver record, whose type is the halfword at
record +0x72 and whose window is the doubleword at record +0x8. A null handle gives type -1 and window 0. Registers of types 0
and 1 are 8-byte slots read and written as one 32-bit word at slot +0x4; registers of types 2 and 3 are the whole 64-bit slot.
A record whose type is outside -1 to 3 is not trapped: a getter returns 0 and a setter stores nothing. Each `assfail` names the
source file `../io/pcibr/pcibr_reg.c` and a line number, and the strings sit in the kernel's `.rodata`. The `panic` messages
all begin with the routine's own name, apart from the three that borrow a neighbour's name, which are listed.

- `pcireg_type0_cfg_addr` (`IP30/unix` `0xa800000020059f0c`, 688 bytes) returns the address of one 32-bit word of PCI
  type 0 configuration space and touches no register. The second argument is the slot, the third the function and the
  fourth the register offset; the result is window +0x20000, plus slot * 0x1000, plus function * 0x100, plus the
  signed offset divided by 4 (rounded toward zero) times 4. For types 0 and 1 the slot is the argument itself and
  `assfail` objects when it is outside 0 to 7 (line 0xb75). For types 2 and 3 the slot used is the argument plus one,
  masked to a byte, and `assfail` objects outside 1 to 4 (line 0xb68 for type 3, 0xb70 for type 2); in each case the
  address is still returned afterwards. A null handle or an unmatched raw window calls `panic`, and the delay-slot
  `or` after that call makes it return 0 if it comes back. Established.
- `pcireg_int_ate_get` (`IP30/unix` `0xa80000002005a8f4`, 620 bytes) reads one internal address-translation entry: the
  doubleword at window +0x10000 plus 8 * index (second argument). The bound is inclusive and differs by type: 0 to 128
  for type 0 (line 0xc09) and 0 to 1024 for types 1, 2 and 3 (lines 0xc05,
  0xc01 and 0xbfd). The check follows the type test, and after a failed `assfail` the read still happens. It stores
  nothing. A null handle or an unmatched raw window calls `panic` and returns 0 if that returns. Established.
- `pcireg_int_ate_set` (`IP30/unix` `0xa80000002005ab60`, 620 bytes) is the writer of the entry that
  `pcireg_int_ate_get` reads: one 64-bit store of the third argument at window +0x10000 plus 8 * index, with no
  earlier read. It checks the same inclusive bounds, 128 for type 0 (line 0xc28) and 1024 for types 3, 2 and 1 (lines
  0xc1c, 0xc20 and 0xc24), and a failed check does not stop the store. A null handle or an unmatched raw window calls
  `panic`; a record type outside -1 to 3 stores nothing. Established.
- `pcireg_int_ate_addr` (`IP30/unix` `0xa80000002005adcc`, 596 bytes) returns the address window +0x10000 plus 8 *
  index of the entry that the get and set routines access, without touching the chip. The inclusive bounds are 128 for
  type 0 (line 0xc47) and 1024 for type 3 (line 0xc3b), type 2 (line 0xc3f) and type 1 (line 0xc43). An unmatched
  handle calls `panic` and returns 0 if that returns. Established.
- `pcireg_wrb_flush_get` (`IP30/unix` `0xa800000020058920`, 596 bytes) reads the write-buffer flush register of one
  device, the slot at window +0x240 plus 8 * device. Types 2 and 3 load the doubleword and accept devices 0 to 3
  (lines 0x9ce and 0x9ca); types 0 and
  1 load the word at slot +0x4 and accept 0 to 7 (line 0x9d3). The value read must be zero: a nonzero one calls
  `assfail` with the text "ret == 0" (line 0x9db), and the value is returned either way. A null handle or an unmatched
  raw window calls `panic`. Established.
- `pcireg_device_get` (`IP30/unix` `0xa800000020058074`, 544 bytes) returns device register
  `device`: the doubleword at window +0x200 plus 8 * device for types 2 and 3 (devices 0 to 3; lines 0x958 and
  0x95c), or the zero-extended word at +0x204 plus 8 * device for types 0 and 1 (devices 0 to 7; line 0x961). A null
  handle or an unmatched raw window calls `panic`. Established.
- `pcireg_device_set` (`IP30/unix` `0xa800000020058294`, 540 bytes) writes the third argument to device register
  `device` with no earlier read: a 64-bit store at window +0x200 plus 8 * device for types 2 and 3 (0 to 3; lines
  0x974 and 0x978), or a 32-bit store of its low half at +0x204 plus 8 * device for types 0 and
  1 (0 to 7; line 0x97d). A null handle or an unmatched raw window calls `panic`. Established.
- `pcireg_device_bit_set` (`IP30/unix` `0xa8000000200584b0`, 552 bytes) sets bits in a device register. It loads the
  register, ORs in the third argument and stores the result back as a doubleword at window +0x200 plus 8 * device for
  types 2 and 3 (0 to 3; lines 0x98f and
  0x993) or as a word at +0x204 plus 8 * device for types 0 and 1 (0 to 7; line 0x998). The load and the store are
  separate instructions and nothing serialises them. A null handle or an unmatched raw window calls `panic`.
  Established.
- `pcireg_device_bit_clr` (`IP30/unix` `0xa8000000200586e4`, 572 bytes) removes bits from a device register by the
  same load, modify and store as `pcireg_device_bit_set`, at the same slots (doubleword at +0x200 for types 2 and 3,
  word at +0x204 for types 0 and 1, plus 8 * device), but ANDing with the complement of the third argument. The bound
  lines are 0x9aa and 0x9ae for types 3 and
  2 (0 to 3) and 0x9b3 for types 0 and 1 (0 to 7). A null handle or an unmatched raw window calls `panic`.
  Established.
- `pcireg_intr_addr_get` (`IP30/unix` `0xa800000020056870`, 528 bytes) returns the interrupt address register of pin
  `int_n` (second argument): the doubleword at window +0x130 plus 8 * pin for types 2 and 3, or the zero-extended word
  at +0x134 plus 8 * pin for types 0 and 1. The pin bound 0 to 7 (line 0x7ec) is tested before the type is looked at,
  so a null handle trips `assfail` first and `panic` second. Established.
- `pcireg_intr_addr_set` (`IP30/unix` `0xa800000020056a80`, 524 bytes) writes the third argument to the interrupt
  address register of pin `int_n`: a 64-bit store at window +0x130 plus 8 * pin for types 2 and 3, or a 32-bit store
  of the low half at +0x134 plus 8 * pin for types 0 and 1. The bound (line 0x807) comes before the type test, and
  only type -1 reaches `panic`; a record type outside -1 to 3 does nothing. Established.
- `pcireg_intr_addr_addr` (`IP30/unix` `0xa800000020056c8c`, 524 bytes) returns the address of the pin's interrupt
  register instead of its contents: window +0x130 plus 8 * pin for types 2 and 3, window +0x134 plus 8 * pin for types
  0 and 1. It makes no access to the chip. The bound is line 0x822. Type -1 calls `panic` and returns 0 if that comes
  back, as does a record type outside the range. Established.
- `pcireg_intr_addr_addr_get` (`IP30/unix` `0xa8000000200572d8`, 560 bytes) builds the interrupt target address of pin
  `int_n`. For types 2 and 3 it loads the doubleword at window +0x130 plus 8 * pin and keeps its low 48 bits. For
  types 0 and 1 the low 32 bits of the result are the word at window +0x3c; the high 32 bits are the word at +0x34
  masked to bits 5:0, ORed with bits 17:8 of the pin's word at +0x134 plus 8 * pin shifted right by two. The bound is
  line 0x87b and type -1 calls `panic`. Established.
- `pcireg_intr_addr_addr_set` (`IP30/unix` `0xa800000020057508`, 588 bytes) writes the address part of the pin's
  interrupt register. Types 2 and 3 first store the doubleword at window +0x130 plus 8 * pin with its low 48 bits
  cleared (mask `0xffff000000000000`), then load it again and store it with the third argument, masked to 48 bits,
  ORed in. Types 0 and 1 clear bits 17:8 of the word at +0x134 plus 8 * pin (mask `0xfffffffffffc00ff`, from the
  literal at 0xa8000000204a89f8), store, then reload and store with the argument shifted right 30 and masked with
  `0x3ff00` ORed in. They never write the window words at +0x34 or +0x3c that the matching getter reads. The bound is
  line 0x89a. Type -1 calls `panic` with the message of `pcireg_intr_addr_addr_get`, not its own. Established.
- `pcireg_intr_addr_vect_set` (`IP30/unix` `0xa80000002005709c`, 572 bytes) replaces the vector field of the pin's
  interrupt register, in two separate load and store pairs each time. Types 2 and 3 clear bits 55:48 of the doubleword
  at window +0x130 plus 8 * pin (mask `0xff00ffffffffffff`, from the literal at 0xa8000000204a89f0), then OR in the
  low byte of the third argument shifted left 48. Types 0 and 1 clear bits 7:0 of the word at +0x134 plus 8 * pin,
  then OR in the low byte of the argument. The bound is line 0x85b; type -1 calls `panic` with the message of
  `pcireg_intr_addr_vect_get`. Established.
- `pcireg_force_always_set` (`IP30/unix` `0xa800000020057a20`, 552 bytes) writes the constant 1 to the force-always
  register of pin `int_n`: a doubleword at window +0x180 plus 8 * pin for types 2 and 3, a word at +0x184 plus 8 * pin
  for type 1. Type 0 has no such register and calls `panic` with a message that says so ("undefined register"), as
  type -1 does with its bridge-type message. The pin bound (0 to 7, line 0x8f9) is tested before the type.
  Established.
- `pcireg_force_always_addr_get` (`IP30/unix` `0xa800000020057c48`, 524 bytes) returns the address of the same
  force-always register without touching it: window +0x180 plus 8 * pin for types 2 and 3, +0x184 plus 8 * pin for
  type 1. Types 0 and -1 call `panic` (the first with the "undefined register" message) and fall through to a return
  of 0. The bound is line 0x915. Established.
- `pcireg_force_intr_set` (`IP30/unix` `0xa800000020057e54`, 544 bytes) writes the constant 1 to the register that
  forces pin `int_n` to interrupt: a doubleword at window +0x1c0 plus 8 * pin for types 2 and 3, a word at +0x1c4 plus
  8 * pin for type 1. Type 0 and type -1 call `panic` as in `pcireg_force_always_set`, and the bound is line 0x936.
  Established.
- `pcireg_rrb_get` (`IP30/unix` `0xa800000020058b74`, 528 bytes) returns response buffer register
  `even_odd` (0 or 1): the doubleword at window +0x280 plus 8 * index for types 2 and
  3, the zero-extended word at +0x284 plus 8 * index for types 0 and 1. The bound (line 0x9ec) comes before the type
  test, and type -1 calls `panic`. Established.
- `pcireg_rrb_set` (`IP30/unix` `0xa800000020058d84`, 520 bytes) writes the third argument to response buffer register
  `even_odd`: one 64-bit store at window +0x280 plus 8 * index for types 2 and 3, one 32-bit store of the low half at
  +0x284 plus 8 * index for types 0 and 1. The bound (line 0xa07) precedes the type test, and type -1 calls `panic`.
  Established.

- `xbridge_attach` (`IP30/unix` `0xa800000020042104`, 2496 bytes) is the attach routine the Octane kernel runs for a
  Bridge or XBridge widget; it returns 0 after a full attach and -1 on its two refusals. It calls
  `pcibr_bridge_ptr_get` for the window and, for part `0xc002` with manufacturer 54 only, calls `pcireg_stat_get` and
  returns -1 unless status bit 5 (0x20) is set. It makes the "pci" vertex with `hwgraph_path_add`, calls
  `pciio_provider_register` and `pciio_provider_startup`, adds the "controller" character device named "pcibr_", and
  reads the NIC string with `pcireg_nic_addr` and `nic_bridge_vertex_info`. It then calls `pcibr_hints_get`; when that
  returns a record whose word at +0xc is nonzero it returns -1 (second refusal), so a hint record with that word set
  stops the attach before anything is allocated. Otherwise it reads the identification word with `pcireg_id_get`,
  forms `revision | part << 4`, stores it as the label "_pcibr_asic_rev" with `hwgraph_info_add_LBL`, and allocates
  and zeroes a 2744-byte (0xab8) record with `kmem_zalloc` and `memset`, attaching it to the vertex with
  `hwgraph_fastinfo_set`. Into that record it stores, in this order: a name copy (`kmem_alloc` of the string length
  plus one, `strcpy`) at +0x10, the argument handle at +0x0, 0 at +0x48,
  7 as a byte at +0x39, 0 as a byte at +0x38, the window at +0x8, the address of `pcibr_intr_bits` at +0x500, the
  revision and part word at +0x78 and the vertex at +0x4. The chip type halfword at +0x72 is 1 for part `0xd002` with
  manufacturer 36 and 0 otherwise; type 1 stores 0x400 as the halfword at +0x70 (the translation entry count) and type
  0 stores 0x80, each with a short name string from `.rodata` stored at +0x18. It stores mode OR speed shifted left
  one (`pcireg_mode_get`, `pcireg_speed_get`) at +0x74, zeroes the doubleword at +0x828, and for a revision word below
  0xc0024 stores 0x2000 into the words at +0xa98 and +0xa9c. It records the widget id, master and master id from
  `xwidget_info_get` and its accessors and calls `spinlock_init` with the name "pcibr_loc". With a hint record it
  copies hint fields into the per-slot entries; without one it uses slots +0x38 to +0x39 as the slot range. It
  registers `pcibr_error_handler` with `xwidget_error_register`; for a revision word below 0xc0024 it clears bits 9:0
  of the timeout register (`pcireg_timeout_bit_clr` with 0x3ff). It writes 0x7f to the interrupt reset register
  (`pcireg_intr_reset_set`), 0xffffffff to the interrupt device register (`pcireg_intr_device_set`), calls
  `pcibr_directmap_init`, sets bit 21 (0x200000) of the control register with `pcireg_control_bit_set`, and zeroes
  every internal translation entry with `pcireg_int_ate_set` (index 0 up to the count at +0x70). On type 0 it calls
  `pcibr_init_ext_ate_ram`. It builds the allocation maps with `rmallocmap` and `pcibr_ate_free`, allocates the error
  interrupt with `xtalk_intr_alloc` on a duplicated device descriptor (flags OR 1, name "Bridge error") and connects
  it with `xtalk_intr_connect` using `pcibr_error_intr_handler` and `pcibr_setwidint`, then reads the destination with
  `pcireg_intr_dst_target_id_get` and `pcireg_intr_dst_addr_get`. It reads the interrupt enable register and writes it
  back ORed with 0x3eff7ffffe00 (`pcireg_intr_enable_get` and `pcireg_intr_enable_set`), sets the interrupt mode to 0,
  and reads the target flush register. The word at +0x7c is set by revision: 0x80000 below 0xc0022, 0x800 below a
  limit derived from `pcibr_prefetch_enable_rev`, and bit 17 (0x20000) ORed in below a limit derived from
  `pcibr_wg_enable_rev`. Three window maps at record +0x848, +0x858 and +0x868 are created with
  `pciio_device_win_map_new` (arguments 0x10000000 and 0x100000, then 0x100000 and
  0x4000, then 0x40000000 and 0x100000) and each is filled with `pciio_device_win_populate` (arguments 0x200000 and
  0xff00000, then 0x4000 and 0xfc000, then 0x200000 and
  0x3ff00000). It then registers a placeholder device with `pcibr_device_info_new` (0xff, 0xff) and
  `pciio_device_info_register`, runs `pcibr_slot_info_init`, `pcibr_slot_addr_space_init`,
  `pcibr_slot_device_init` and `pcibr_slot_guest_info_init` over the slot range in four separate passes. It then calls
  `pcibr_initial_rrb`; when the NIC string contains "030-1275-" it also calls `pcibr_rrb_alloc_init` with one, zero
  and eight. A last pass calls `pcibr_slot_call_device_attach` on each slot, and `pciio_device_attach` finishes. The
  IP27 build's `xbridge_attach` is 96 bytes longer. The store order and the callees come from the disassembly; the
  branches over the hint record and the revision tests were read from decompiler output checked against it. It stores
  the handle returned by `xtalk_intr_alloc` at +0x828 after the allocation. Inferred.
- `pcibr_alloc_all_rrbs` (`IP30/unix` `0xa800000020048b48`, 980 bytes) divides one bank of response buffers among up
  to four devices. The first argument is the widget vertex and the second selects the bank, using only its bit 0 (0
  for the even bank, 1 for the odd bank). Arguments three to ten are four pairs, one per device in order: a count of
  buffers and, after it, how many of those are virtual. It finds the window by calling `hwgraph_traverse` with "pci"
  and, when that yields a record, reading the doubleword at record +0x8 after `hwgraph_fastinfo_get`, then
  `hwgraph_vertex_unref`; with no usable window it calls `xtalk_piotrans_addr` (0, 0,
  8, 0). It returns -1 in three cases. The first is an id word that matches neither Bridge (part `0xc002`,
  manufacturer 54) nor XBridge (part `0xd002`, manufacturer 36) while the count or the virtual count of device 2 or 3
  (seventh to tenth arguments) is nonzero. The second is a sum of the four counts (third, fifth, seventh and ninth
  arguments) above 8. The third is any of those four counts being negative. Otherwise it packs eight 4-bit entries
  from the top of a 32-bit word downward, device by device: one entry of (device | 8) per buffer that is not virtual
  and, for each virtual buffer, (device | 8 | 4) on Bridge and XBridge or (device | 8 | 2) on the other chips, the
  virtual entries placed before the plain ones. With a soft-state record it takes `mutex_spinlock` on record +0x80,
  writes the word to the bank with `pcireg_rrb_set`, ORs `0x55 << bank` into the word at +0x51c, stores 0 at +0x540,
  +0x538, +0x530 and +0x528 plus 4 * bank, stores 8 minus the buffer sum at +0x520 plus 4 * bank, and records the
  virtual counts and the differences (count minus virtual) of the four devices at the 16-byte-stride words +0x568 to
  +0x5cc, then releases with `mutex_io_spinunlock`; without a record it only writes the register. It returns 0 on
  success. The packing loops and the soft-state words were read from decompiler output and not traced instruction by
  instruction. Inferred.
- `giobr_attach` (`IP30/unix` `0xa800000020040ae0`, 740 bytes) attaches a Bridge widget that is running in GIO mode,
  the case that `xbridge_attach` refuses. It first raises the word at 0x900000001800002c to 0x80 when it is below
  0x80; the heart page lists that word as the widget request timeout. It calls `xtalk_piotrans_addr` for a window of
  0x1000000 bytes and returns -1 when bit 5 (0x20) of the status word at window +0xc is set. Otherwise it makes the
  "gio" vertex with `hwgraph_path_add`, reads the NIC string at window +0xb4 with `nic_bridge_vertex_info`, and adds
  the "controller" device named "giobr_". It zeroes a 0x108-byte record from `kmem_alloc` and `blkclr`, stores the
  vertex at +0x0, the window at +0x8, the argument at +0x14 and the widget id, master and master id
  (`xwidget_info_get` and its accessors) at +0x10, +0x18 and +0x1c, 0xff as a byte at +0x4c, and clears the eight
  16-byte pairs from +0x50. It sizes a DMA window from `physmem` shifted left 14 (capped at 0x80000000) with
  `xtalk_dmatrans_addr`, and probes four device slots from a table with `xtalk_piotrans_addr`, recording each slot
  that answers in the word at +0x44 and a byte at +0x40 plus the index. When no slot answers it prints "unknown device
  on gio bridge" with `cmn_err` (level 7). It then calls `gioio_provider_register`, `gioio_provider_startup`,
  `gioio_device_register` and `gioio_device_attach`, and returns 0. Inferred.
- `pcireg_intr_addr_vect_get` (`IP30/unix` `0xa800000020056e98`, 516 bytes, frame 32 bytes) returns the interrupt
  vector number programmed for pin `int_n`, the second argument. Types 2 and 3 take bits 55:48 of the doubleword at
  window +0x130 plus 8 * pin (a `dsrl32` by 16, then a mask of 0xff). Types 0 and 1 take the low byte of the word at
  +0x134 plus 8 * pin. The pin test, 0 to 7, is tested before the type and is `assfail` line 0x841; the read is made
  whether or not it fires. Type -1 calls `panic` with a message that carries this routine's own name and returns 0,
  and a record type outside -1 to 3 returns 0 without a message. Established.
- `pcireg_dirmap_diroff_set` (`IP30/unix` `0xa8000000200534b8`, 496 bytes, frame 16 bytes) writes bits 16:0 of a
  direct-map register from its second argument (the register whose bits 23:20 `pcireg_dirmap_wid_set` rewrites). Types
  0 and 1 work on the word at window +0x84: clear bits 16:0 (`lui` 0xfffe, sign-extended, ANDed), store, reload, OR in
  the argument masked to 0x1ffff, store. Type 2 does the same two stores on the doubleword at +0x80. Type 3 first does
  two stores of its own on that doubleword: clear bits 25:20 (mask 0x3f00000), reload, OR in the argument shifted left
  3 and masked to 0x3f00000, so argument bits 22:17 become register bits 25:20, and only then the bits 16:0 pair. The
  routine has no bound test and no interrupt-level change and returns no value. Type -1 calls `panic` and stores
  nothing, and so does a record type outside -1 to 3. Established.
- `pcireg_ssram_size_set` (`IP30/unix` `0xa800000020051124`, 496 bytes, frame 48 bytes) stores its second argument,
  which must be 0 to 3, into bits 18:17 of the word at window +0x24, the word that `pcireg_control_set` writes for
  types 0 and 1; only type 0 is accepted without a message. It raises the interrupt level with `spl1` before it looks
  at the handle and restores it with `splx` on every path, including the panic ones. Types 1, 2 and 3 call `panic`
  with "undefined register" and then carry on into the same bound test and stores as type 0, so the register is still
  written. The size argument is tested for 0 to 3 (`assfail` line 0x158, 344) and a failure does not stop the stores.
  The stores are a load, a clear of bits 18:17 (`lui` 6 and `nor`), a store, a reload, an OR of the argument shifted
  left 17 with no mask, a store and a read-back of the word. Type -1 calls `panic` with the bridge-type message,
  writes nothing and still restores the level, and a record type outside -1 to 3 does nothing but restore it.
  Established.
- `pcireg_type1_cfg_addr` (`IP30/unix` `0xa80000002005a1bc`, 468 bytes, frame 16 bytes) returns the address of one
  32-bit word of PCI type 1 configuration space without touching the chip. The second argument is shifted left 8
  (`dsll`), the third is a signed register offset divided by 4 with rounding toward zero (`addiu` 3 conditionally
  added when negative, `sra` 2) and multiplied back by 4, and the result is window plus those two plus 0x28000. The
  arithmetic is present three times: one copy serves types 0 and 1, and types 3 and 2 each jump to a copy of their
  own; there is no bound test and no `assfail`. Type -1 or a null handle calls `panic` with the bridge-type message
  and returns 0, and a record type outside -1 to 3 also returns 0. Established.
- `pcireg_ext_ate_set` (`IP30/unix` `0xa80000002005a55c`, 460 bytes, frame 32 bytes) writes one external
  address-translation entry, the third argument, as a 64-bit store to window +0x80000 plus 8 * index (second
  argument), with no earlier read. The index is bounded inclusive, 0 to 0x10000 (`assfail` line 0xbcd), by two tests,
  one against zero and one with `slt` against 0x10000; a failure does not stop the store. Only type 0 is a Bridge:
  types 1, 2 and 3 call `panic` with "not a BRIDGE ASIC" and still go on to the bound test and the store. Type -1
  calls `panic` with the bridge-type message and stores nothing, and so does a record type outside -1 to 3. There is
  no interrupt-level change. Established.
- `pcireg_ext_ate_addr` (`IP30/unix` `0xa80000002005a728`, 460 bytes, frame 32 bytes) returns the address of the
  external translation entry that `pcireg_ext_ate_get` loads and `pcireg_ext_ate_set` stores: window plus 0x80000 plus
  8 * index, with no access to the chip. The inclusive bound 0 to 0x10000 is `assfail` line 0xbe5 and the address is
  returned afterwards whether or not it fires. Types 1, 2 and 3 call `panic` with "not a BRIDGE ASIC" first and then
  build the same address; type -1 calls `panic` with the bridge-type message and returns 0, as does a record type
  outside -1 to 3. Established.
- `pcireg_ext_ate_get` (`IP30/unix` `0xa80000002005a390`, 460 bytes, frame 32 bytes) reads one external
  address-translation entry: the doubleword at window +0x80000 plus 8 * index, a single `ld` made in the delay slot of
  the jump to the epilogue. The bound is inclusive, 0 to 0x10000 (`assfail` line 0xbb5) and the load follows a
  failure. Types 1, 2 and 3 first call `panic` with "not a BRIDGE ASIC" and still do the load; type -1 calls `panic`
  with the bridge-type message and returns 0, and a record type outside -1 to 3 returns 0 too. Established.
- `pcireg_control_bit_clr` (`IP30/unix` `0xa800000020050ddc`, 428 bytes, frame 32 bytes) clears bits of the control
  register under a raised interrupt level: `spl1` is the first call, before the handle is looked at, and `splx` closes
  every path. Types 2 and 3 load the doubleword at window +0x20, AND it with the complement (`nor`) of the second
  argument and store it; types 0 and 1 do the same on the word at +0x24. Each path then loads the register once more,
  a read-back that the delay slot of the exit branch runs and whose value is dropped. There is no bound test. Type -1
  calls `panic` with the bridge-type message and still restores the level; the routine returns no value. Established.
- `pcireg_intr_dst_addr_set` (`IP30/unix` `0xa800000020052018`, 420 bytes, frame 16 bytes) stores a 48-bit target
  address, its second argument, into the interrupt destination register. Types 0 and 1 split it over two words: the
  word at window +0x34 has bits 15:0 cleared (`lui` 0xffff mask), is stored, reloaded and ORed with bits 47:32 of the
  argument (`dsrl32`, then a 0xffff mask), and stored again, and the low 32 bits of the argument go to the word at
  +0x3c in the delay slot of the exit branch. Types 2 and 3 clear bits 47:0 of the doubleword at +0x38 (mask `li -1`
  shifted left 48), store, reload, OR in the argument masked to 48 bits and store. It has no bound test and no `spl1`,
  and returns no value. Type -1 and a null handle call `panic` and store nothing; other record types return.
  Established.
- `pcireg_control_bit_set` (`IP30/unix` `0xa800000020050f88`, 412 bytes, frame 32 bytes) sets bits in the control
  register under a raised level, the mirror of `pcireg_control_bit_clr`: `spl1` first, `splx` on every path. Types 2
  and 3 OR the second argument into the doubleword at window +0x20; types 0 and 1 OR it into the word at +0x24, and in
  each case the register is loaded again straight after the store, in the delay slot of the branch to the exit, so the
  write is followed by a read. Nothing tests the argument. Type -1 or a null handle calls `panic` with the bridge-type
  message and restores the level without storing anything. Established.
- `pcireg_intr_dst_target_id_set` (`IP30/unix` `0xa800000020051cfc`, 412 bytes, frame 16 bytes) replaces the four-bit
  target id of the interrupt destination register with the low four bits of its second argument. Types 0 and 1 clear
  bits 19:16 of the word at window +0x34 (`lui` 0xf, `nor`), store, reload, OR in the argument masked with 0xf and
  shifted left 16, and store. Types 2 and 3 clear bits 51:48 of the doubleword at +0x38 with the literal
  0xfff0ffffffffffff from the pool word at 0xa8000000204a89e8, then reload and OR in the argument masked with 0xf and
  shifted left 48. The two-store sequence is unlocked, with no bound test and no `spl1`. Type -1 and a null handle
  call `panic` with a message whose name and colon have no space between them, and store nothing. Established.
- `pcireg_dirmap_wid_set` (`IP30/unix` `0xa80000002005331c`, 412 bytes, frame 16 bytes) rewrites the four-bit widget
  number of the direct-map register, bits 23:20, from the low four bits of its second argument. The register is the
  word at window +0x84 for types 0 and 1 and the doubleword at +0x80 for types 2 and 3, which is the register whose
  bits 16:0 `pcireg_dirmap_diroff_set` writes. Each arm clears the field (`lui` 0xf0 and `nor`), stores, reloads, ORs
  in the masked argument shifted left 20 and stores. There is no bound test, no level change and no read-back. A null
  handle or type -1 calls `panic` with the bridge-type message and stores nothing, and a record type outside -1 to 3
  returns. Established.
- `pcireg_llp_cfg_set` (`IP30/unix` `0xa800000020052498`, 412 bytes, frame 32 bytes) writes the link-layer
  configuration register from its second argument under a raised level (`spl1` first and `splx` on every path; the
  argument is parked at 0(sp) across the first call). Types 0 and 1 store the low 32 bits as a word at window +0x4c,
  type 2 stores the full doubleword at +0x48, and each is followed by a load of the same register in the delay slot of
  the exit branch, so the write is read back. Type 3 has no such register: it calls `panic` with "undefined register"
  and stores nothing. Type -1 and a null handle call `panic` with the bridge-type message, also with no store. There
  is no bound test. Established.
- `pcireg_rrb_bit_clr` (`IP30/unix` `0xa80000002005911c`, 408 bytes, frame 16 bytes) clears bits of one response
  buffer register under no lock. The second argument selects the register of the pair (0 or 1) and the third is the
  mask; types 2 and 3 clear them in the doubleword at window +0x280 plus 8 * index, types 0 and 1 in the word at
  +0x284 plus 8 * index, each as a load, an AND with the complement (`nor`) and a store. Unlike `pcireg_rrb_get` and
  `pcireg_rrb_set` it makes no `assfail` check on the index. Type -1 and a null handle call `panic` with the
  bridge-type message and store nothing, and a record type outside -1 to 3 does nothing. The routine returns no value.
  Established.
- `pcireg_tflush_get` (`IP30/unix` `0xa800000020052634`, 400 bytes, frame 16 bytes) reads the target flush register
  and requires it to be zero: types 2 and 3 load the doubleword at window +0x50 and types 0 and 1 the word at +0x54,
  zero-extended with `dsll32` and `dsrl32`. A nonzero value calls `assfail` with the text "ret == 0" (line 0x30f, 783)
  and the value is returned all the same. Type -1 or a null handle calls `panic`, whose message begins with
  "pcibr_tflush_get()" rather than this routine's own name, and returns 0. The read is the only access; nothing is
  written. A record type outside -1 to 3 leaves the register unread. Established.
- `pcireg_rrb_bit_set` (`IP30/unix` `0xa800000020058f8c`, 400 bytes, frame 16 bytes) ORs a mask into one response
  buffer register: the register is selected by the second argument and the third argument is ORed into the doubleword
  at window +0x280 plus 8 * index (types 2 and 3) or the word at +0x284 plus 8 * index (types 0 and 1). It does the
  load, OR and store with no lock, no index check and no read-back, which is also how `pcireg_rrb_bit_clr` differs
  from `pcireg_rrb_get`. Type -1 and a null handle call `panic` with the bridge-type message and write nothing; a
  record type outside -1 to 3 does nothing. The routine returns no value. Established.
- `pcireg_dirmap_add512_clr` (`IP30/unix` `0xa800000020053828`, 392 bytes, frame 16 bytes) clears bit 17 (0x20000,
  from `lui` 2 and `nor`) of the direct-map register: the word at window +0x84 for types 0 and 1, the doubleword at
  +0x80 for types 2 and 3, as one load, AND and store. It takes only the handle, so nothing is passed in the second
  argument; there is no bound test, level change or read-back. Type -1 or a null handle calls `panic` with the
  bridge-type message and stores nothing, and a record type outside -1 to 3 does nothing. Its counterpart
  `pcireg_dirmap_add512_set` ORs the same bit in. Established.
- `pcireg_control_set` (`IP30/unix` `0xa800000020050c54`, 392 bytes, frame 32 bytes) overwrites the whole control
  register with its second argument, with no earlier read: types 2 and 3 store a doubleword at window +0x20 and types
  0 and 1 a word at +0x24, and each store is followed by a reload of the same register in the delay slot of the exit
  branch. The level is raised first with `spl1`, whose old value is parked at 0(sp), and every path ends in `splx`,
  including the panic path. Type -1 and a null handle call `panic` with the bridge-type message and store nothing, and
  a record type outside -1 to 3 stores nothing either. It takes no bound test; `pcireg_control_bit_set` and
  `pcireg_control_bit_clr` are the load-modify-store neighbours of it. Established.
- `pcireg_intr_enable_bit_clr` (`IP30/unix` `0xa800000020055484`, 384 bytes, frame 16 bytes) clears bits in the
  interrupt enable register: the second argument's complement (`nor`) is ANDed into the doubleword at window +0x108
  for types 2 and 3 and into the word at +0x10c for types 0 and 1, as one load and one store with nothing after it.
  There is no `spl1`, no bound test and no read-back; the load and the store are separate instructions. Type -1 and a
  null handle call `panic` with the bridge-type message, and a record type outside -1 to 3 stores nothing. The routine
  returns no value. Established.
- `pcireg_pci_bus_addr_addr_get` (`IP30/unix` `0xa800000020054ee0`, 384 bytes, frame 16 bytes) returns the 48-bit
  address part of the PCI bus address register. Types 2 and 3 load the doubleword at window +0xd8 and mask it to its
  low 48 bits (`li -1` shifted right 16). Types 0 and 1 assemble it from two words: bits 15:0 of the word at +0xd4
  become bits 47:32, and the word at +0xdc, zero-extended, supplies bits 31:0. Only loads are made. Type -1 or a null
  handle calls `panic` with the bridge-type message and returns 0, and a record type outside -1 to 3 returns 0 without
  a load. It has the same shape as `pcireg_intr_dst_addr_get` over different offsets. Established.
- `pcireg_dirmap_add512_set` (`IP30/unix` `0xa8000000200536a8`, 384 bytes, frame 16 bytes) sets bit 17 (0x20000) of
  the direct-map register, the word at window +0x84 for types 0 and 1 and the doubleword at +0x80 for types 2 and 3,
  by a load, an OR with the constant and a store. The only argument is the handle, so it has no way to choose a value.
  Nothing guards it: no bound test, no level change, no read-back. A null handle or type -1 calls `panic` with the
  bridge-type message and stores nothing, and a record type outside -1 to 3 stores nothing. `pcireg_dirmap_add512_clr`
  is its inverse. Established.
- `pcireg_intr_dst_addr_get` (`IP30/unix` `0xa800000020051e98`, 384 bytes, frame 16 bytes) returns the 48-bit
  interrupt destination address. Types 2 and 3 load the doubleword at window +0x38 and keep its low 48 bits (`li -1`
  and `dsrl` 16). Types 0 and 1 take bits 15:0 of the word at +0x34, shift them left 32 (`dsll32`) and OR them with
  the word at +0x3c zero-extended by a `dsll32` and `dsrl32` pair, the same two words that `pcireg_intr_dst_addr_set`
  stores. It makes no other access. Type -1 or a null handle calls `panic` with the bridge-type message and returns 0,
  and a record type outside -1 to 3 returns 0 without any load. Established.
- `pcireg_ssram_parity_get` (`IP30/unix` `0xa8000000200539b0`, 380 bytes, frame 16 bytes) returns the SSRAM parity
  register, which only the first two chip types have: it loads the word at window +0x94 and zero-extends it with
  `dsll32` and `dsrl32`. Types 2 and 3 call `panic` with "undefined register" and then read the same word anyway, so
  on those types the value comes back after the message. Type -1 or a null handle calls `panic` with the bridge-type
  message and returns 0 without reading, and a record type outside -1 to 3 returns 0 too. The read is the only access
  and nothing is checked. Established.
- `pcireg_intr_device_bit_clr` (`IP30/unix` `0xa800000020056430`, 380 bytes, frame 16 bytes) removes bits from the
  interrupt device register: the doubleword at window +0x120 for types 2 and 3, the word at +0x124 for types 0 and 1,
  each loaded, ANDed with the complement of the second argument and stored with no read-back. It does not raise the
  level and has no bound test, so it is a plain unlocked read-modify-write. Type -1 and a null handle call `panic`
  with the bridge-type message and store nothing. The routine returns no value. Established.
- `pcireg_resp_err_addr_get` (`IP30/unix` `0xa800000020052a9c`, 380 bytes, frame 16 bytes) returns the address
  recorded for the last response error, 48 bits. Types 2 and 3 take the low 48 bits of the doubleword at window +0x68.
  Types 0 and 1 combine the word at +0x64 masked to bits 15:0, shifted left 32, with the word at +0x6c zero-extended;
  the word at +0x64 is the one that `pcireg_resp_err_buf_get` and `pcireg_resp_err_dev_get` read for types 0 and 1.
  Nothing is written. Type -1 or a null handle calls `panic` with the bridge-type message and returns 0, as does a
  record type outside -1 to 3. Established.
