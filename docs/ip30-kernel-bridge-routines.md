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
