# Router (SN0 and SN1 network router)

Mode: **no-spec** (see [docs/specs.md](../../docs/specs.md): no specification is held). The router is the crossbar chip
between node controllers in the Origin 200/2000-class and Origin 3000-class machines. It has no memory window. Software
reaches its registers with a vector packet sent through the node controller's network interface, so the census is a
census of call arguments: the register numbers the kernel passes to its router accessors. Builds are named by board:
IP27 (`IP27/unix`, linked) and IP35 (`IP35/usr/cpu/sysgen/IP35boot/kernel.o`, relocatable object, cited by offset).

Every fact below is read from those two kernels. The public Linux `asm-ia64/sn/router.h` (in the pinned `linux-2.4.37`
submodule, see [docs/sources/INDEX.md](../../docs/sources/INDEX.md)) was read afterwards, to report agreement and
conflict, never to supply a fact; where a name appears it is that header's name for the same offset.

Census: [census/](census/) (`census.tsv`, `census-sites.tsv`, `call-sites.tsv`, `values.tsv`, `census-symbolic.tsv`,
`unresolved.tsv`), config [`tools/configs/router.json`](../../tools/configs/router.json), scanner
[`retools/tools/chips/callargs.py`](../../retools/tools/chips/callargs.py), headers [`include/router_origin2000.h`](../../include/router_origin2000.h) and
[`include/router_origin3000.h`](../../include/router_origin3000.h).

## What this census covers, and what it does not

- `retools/tools/chips/callargs.py` resolves the register number at each call to `router_reg_read`, `router_reg_write`,
  `hub_vector_read`, `hub_vector_write`, `vector_read_node` and `vector_write_node` by straight-line constant
  propagation. It found **67 call sites** in the two kernels. 47 resolve to a constant or to a constant added to a
  per-port base the code builds from a port number; 20 do not (the accessors themselves, which forward their
  argument, and the callers that spill the number to the stack).
- Per-port registers are recorded at the port-relative offset with the index flag set (a family; its extent is the port
  count, 6 in the IP27 loops, 8 in the IP35 loops).
- Six sites were read by hand where the pass loses its state at a branch target. They are listed in the config's
  `by_hand` entries and flagged in `census.tsv`.
- Reset values are unknown for every register: no code reads one before writing it.
- One IP35 routine reaches router registers by a different route and is not in this census: `router_acquire_port_info`
  calls `read_rr_reg`, which the member `read_reg.o` of the IP35 boot set defines, and which drives a scan-chain (JTAG)
  interface (`simp_jtag_open`, `scancmd_init`, `simp_process_scancmd`). That is a second access path to the same chip, read in
  [../scan/README.md](../scan/README.md).

## How a register is reached (established)

- `router_reg_read` (`IP27/unix` `0xc00000000001b344`, 48 bytes; `kernel.o` `0x266c`, 48 bytes) takes a router record and
  calls `hub_vector_read` with the halfword at +2 of the record (the node number), the doubleword at +24 (the vector
  path), the word at +32 (the vector length), its own second argument (the register number) and its third (a pointer
  for the result). `router_reg_write` (`IP27/unix` `0xc00000000001b374`; `kernel.o` `0x269c`) is the same call to
  `hub_vector_write`. Both builds are read in full and are identical in shape. The register number is therefore the
  second argument of `router_reg_*` and the fourth of the `hub_vector_*` and `vector_*_node` routines (the register a3).
- The Hub side (`NI_VECTOR`, `NI_VECTOR_DATA`, `NI_VECTOR_STATUS`) is described in [../hub/README.md](../hub/README.md).

## Port block addressing (established per build; the two builds differ)

- **IP35.** `router_port_init` (`kernel.o` `0x2d5c`, 180 bytes, read in full) forms the register number of port `p` as
  `((p+1) & 0xe) << 15 | ((p+1) & 1) << 11` and or-s the per-port offset into it (`ori` with 0x20, 0x28 and 0x88).
  `router_port_hist_reselect` (`0x2e10`) and `router_print_state_specific` (`0x3ae4`) and `save_router_err` (`0x1340c`)
  form it the same way. The router has eight ports, numbered 1 to 8 by every loop (`slti` against 9). No loop passes port 0 to the formula (the formula would give it `0x800`). Agreement: the public header's `RR_PORT_PARMS(_L)` macro has the same
  expression.
- **IP27.** `router_port_init` (`IP27/unix` `0xc00000000001ba70`, 196 bytes, read in full) forms the register number as
  `p << 16` (`sll` by 16) and or-s the offset in. The loops run to 6 (`slti` against 7). Conflict with the public header:
  the header describes the IP35-style layout only. The IP27 router is a different chip revision with a different port block
  stride; nothing in the header describes it (inferred: the stride and port count differ, and the global registers
  below differ).

## Global registers (IP35 build; names are the public header's)

| number | name | access | routines | what the code does | grade |
|---|---|---|---|---|---|
| `0x0` | `RR_STATUS_REV_ID` | r | `router_init`, `router_print_state_specific`, `save_router_err`, the routine with no symbol at `0x399c` | `router_init` (`kernel.o` `0x3380`, read in full) reads it into record +16, stores bits 55:52 (shift 52, mask 0xf) in the halfword at +4 of its third argument, compares bits 27:12 with 12311 (0x3017) and, when they differ, prints a level-4 diagnostic, frees the 704-byte record, clears the pointer at +24 of its third argument and carries on; a link-working bit per port is tested at bit 37 + 2(p-1) and sets bit p-1 of the byte at record +8. Header names: input port 55:52, chip id 27:12, link working bit `35 + 2L`. | E |
| `0x10` | `RR_PROT_CONF` | rw | `router_set_fences` | read, then for each port 1 to 8 the bit p-1 is cleared when the port is absent from the usable-port byte at record +8; written back and the value kept at record +536 (0x218). | E |
| `0x20` | `RR_GLOBAL_PARMS0` | rw | `router_init` | read into record +512; bit 0 is cleared when the global `craylnk_bypass_disable` is nonzero; then bits 19:16 are replaced by 0xc and bits 8:5 by 0xa (the constants `0xc0000`, `0x140` and the masks `0xf0000`, `0x1e0`); written back. Header fields at those positions: dead-lock timeout (19:16), tail value (8:5), bypass enable (0). | E for the edits, I for the field meaning |
| `0x28` | `RR_GLOBAL_PARMS1` | rw | `router_init` | read into record +520; bits 31:12 are replaced by 0x40000 (mask `0xffffffff00000fff`, constant `0x40000000`); written back. Header field: tail timeout wrap (31:12). | E for the edit, I for the meaning |
| `0x200` | `RR_JBUS0(0)` | w | `router_set_leds` | `router_set_leds` (`kernel.o` `0x26cc`, 64 bytes, read in full) writes the byte at record +7 here when it differs from the cached byte at +6, then stores the byte to +6. The role (LED output through the JBUS port) is inferred from the routine name. | E / I |
| `0x240` to `0x268` | `RR_JBUS1(0)` to `RR_JBUS1(5)` | rw | `rtr_uart_*` of `l1.o` | `l1.o` (`rtr_uart_putc` `0x634`, `rtr_uart_getc` `0x784`, `rtr_uart_init` `0x818`) reads and writes `0x240`, `0x248`, `0x250`, `0x258`, `0x260` and `0x268` as a UART register file, data first and line status last. Inferred: the second bank holds the brick controller's console UART. | E for the access, I for the role |

## Global registers (IP27 build)

| number | name | access | routines | what the code does | grade |
|---|---|---|---|---|---|
| `0x0` | `RR_STATUS_REV_ID` (LED write path) | rw | `router_init`, `router_print_state_specific`, the routine with no symbol at `0xc00000000001c63c` | read by the three routines. `router_set_leds` (`IP27/unix` `0xc00000000001b454`, 84 bytes, read in full) writes it with bits 21:16 taken from the low six bits of the byte at record +7 and bits 15:12 kept from the doubleword at record +16 (the last status read). | E |
| `0x18` | `RR_GLOBAL_PORT_DEF` | rw | `router_init`, `router_acquire_info` | read by `router_init`, which tests bits 35:28 against 32, then writes it back with a literal-pool mask applied and the constant 0x57f shifted left 37 or-ed in; `router_acquire_info` writes it twice. The meaning of the fields is unknown. | E for the access, U for the bits. Settling test: the public Linux router register header (named in `include/router_origin2000.h`) for field definitions of this register, then compare with the two constants `router_init` applies (the bits 35:28 compare against 32 and the `0x57f` left shifted 37 or-ed in); a header that names fields lets those constants be decoded, otherwise unknown with the writes as the only evidence |
| `0x38` | (header: `RR_DEBUG_ADDR`) | rw | routine at `0xc00000000001b3a4` | writes a value built from two arguments (shifted by 10 and 2) and the result of `nic_get_phase_bits`, then reads it back until bit 1 is set and returns bit 0. A one-wire serial-number access through the router is inferred from the callee name. Conflict with the header, which names this offset a debug address; the header may describe a later chip. | E for the sequence, I for the role |
| `0x10` | `RR_PROT_CONF` | rw | `router_set_fences` | same use as IP35: read and written once. | E |

## Per-port registers (offset from the port base)

| offset | name | IP27 | IP35 | what the code does | grade |
|---|---|---|---|---|---|
| `+0x0` | `RR_PORT_PARMS` | rw | rw | `router_port_init` clears bits 19:18 (mask `0xc0000`) and sets bit 18 (IP27, constant `0x40000`) or bits 20 and 18 (IP35, constant `0x140000`). `router_port_hist_reselect` clears the same two bits and ors in its third argument shifted left 18. Header fields: 20 histogram enable, 19:18 histogram select (value 1 is link utilisation). | E for the edits, I for the field names |
| `+0x8` | `RR_STATUS_ERROR` | r | r | read per port by `router_print_state_specific`, the routine with no symbol at `0xc00000000001c63c` (IP27) or `kernel.o` `0x399c` (IP35, also without a symbol) and by `save_router_err` (IP35, through `vector_read_node`); the value is passed to a printing routine. | E for the access, I for the role |
| `+0x10` | (none in header) | rw | - | IP27 only: written with zero by `router_port_init` and `router_port_hist_reselect`, read by `router_acquire_port_info` into record +8. A port counter is inferred. | E / U |
| `+0x18` | `RR_RESET_MASK` | rw | rw | `router_set_fences` reads each usable port's word, clears the bit of every port that is not usable and writes it back. | E |
| `+0x20`, `+0x28` | `RR_HISTOGRAM0`, `RR_HISTOGRAM1` | - | w | IP35 only: both written with zero by `router_port_init` and `router_port_hist_reselect`. | E |
| `+0x88` | `RR_ERROR_CLEAR` | r | r | read once per port by `router_port_init` (IP27 also by `router_acquire_port_info`), the result kept. | E for the access, I for the role |

## Public-header comparison (reported after the reading above)

Agreements: every IP35 offset above equals a header offset; the port block formula is the header's; the `PORT_PARMS`
histogram field positions agree with the edits made.

Conflicts and gaps:
- The header lists registers the kernels never touch by constant: `RR_PORT_RESET` `0x8`, `RR_DIAG_PARMS` `0x30`,
  `RR_LB_TO_L2` `0x40`, `RR_L2_TO_LB` `0x48`, `RR_JBUS_CONTROL` `0x50`, `RR_SCRATCH_REG0` to `4` at `0x100` to `0x120`,
  `RR_VECTOR_HW_BAR` at `0x8000`, `RR_CHANNEL_TEST`, the global and local routing tables. They may be reached through
  computed indexes (the routing tables) or only by the controller firmware; the census cannot tell.
- The header places `RR_DEBUG_ADDR` at `0x38`; the IP27 kernel uses `0x38` for a serial-number sequence (above).
- The IP27 router has six ports and a 16-bit port stride; the header has eight and the 11/15-bit formula.

## Open

See [../../docs/open-questions.md](../../docs/open-questions.md): the router register map of the IP27 chip, the routing
tables, and the scan-chain path.
