# Bridge and XBridge

Mode: **no-spec** (see [docs/specs.md](../../docs/specs.md): the Bridge and XBridge specification scans held in this
repository have suspended clearance, so nothing on this page cites them). Every fact below was first read from the IRIX
6.5.30 shipped files: the IP27 and IP30 kernels (`unix`, linked, with symbols), the IP35 driver objects `pcibr.o` and
`xbridge.o`, the IP30 CPU PROM (`IP30prom.bin`), and the IP27, IP35 and I/O-board PROMs (scanned, no access resolved,
see "What the census does not reach"). The public Linux drivers (`arch/mips/include/asm/pci/bridge.h` and
`arch/mips/pci/pci-xtalk-bridge.c` in the Linux v5.3 tree, and the older IP27 and IP30 trees) and the OpenBSD
`xbridgereg.h` and `xbridge.c` are compared afterwards (section "Against the public drivers") and never supply a fact.
Census: [census/](census/census.md) (`census.tsv`, `fields.tsv`, `context.tsv`, `census-sites.tsv`,
`census-windows.tsv`), config [`tools/configs/bridge.json`](../../tools/configs/bridge.json), headers
[`include/bridge.h`](../../include/bridge.h) and [`include/xbridge.h`](../../include/xbridge.h).

Bridge and XBridge are the XIO-to-PCI bridges of the Origin 2000 family and the Octane. IRIX drives them with one
driver: the accessor routines `pcireg_*` serve four chips (Bridge, XBridge, PIC, TIOCP) and choose among them at run
time. This page covers the first two. PIC has its own page ([../pic/README.md](../pic/README.md)); the same accessors
serve it, so its rows appear in the census under their own variant and are not described here.

## What identifies the chip, and what IRIX does with the answer

- **Record and dispatch (established).** Every `pcireg_*` routine takes either a pointer to the driver's per-chip
  record or a raw window pointer. A pointer whose bits 63, 60 and 57 are all set
  (`(ptr & 0x9200000000000000) == 0x9200000000000000`, the shape of an uncached physical window) is raw: the routine
  reads the identification word at +0x4 and chooses by part number. Any other pointer is a record: the routine reads
  the chip type from the halfword at record +114 and the window base from the doubleword at record +8. Types 0 and 1 are
  the Bridge family and select the 32-bit layout; types 2 and 3 select 64-bit accesses at the slot address itself (PIC,
  TIOCP). Read in full: `pcireg_control_get` at `0xc00000000007f060` of the IP27 `unix`.
- **Identification word (established).** The word at slot 0x0 is read at +0x4 as a 32-bit load. The routines isolate
  bits 31:28 (revision), 27:12 (part number) and 11:1 (manufacturer number). Part `0xc002` with manufacturer 54 is
  Bridge; part `0xd002` with manufacturer 36 is XBridge. The raw-pointer dispatch also accepts `0xd102` and `0xd112`
  (PIC) and `0xe000` and `0xe010` (TIOCP) with manufacturer 36. Which part is which chip is read from the dispatch
  structure and from `pic.o` setting type 2 with `0xd102` and `0xd112` (established for PIC, inferred for the rest).
  Bit 0 of the word is not used.
- **Attach (established, `xbridge_attach` at `0xc0000000000703ac` of the IP27 `unix`, 2592 bytes, read in full).** It
  is the attach routine for both chips. It maps the window with `pcibr_bridge_ptr_get`, reads the identification word
  and, for part `0xc002` with manufacturer 54 only, reads the status register and returns -1 unless status bit 5 is
  set (PCI mode, see the status register below): a Bridge part that reports GIO mode is refused. It forms
  `revision | (part << 4)` and keeps it in record +120. It stores type 1 at record +114 when the part is `0xd002`
  with manufacturer 36, otherwise type 0, and stores the count of internal address-translation entries at record
  +112: 128 for type 0 and 1024 for type 1. Later steps compare record +120 with `0xc0022`, `0xc0023` and `0xc0024`
  (Bridge revisions 2, 3 and 4 in the public naming); every XBridge compares above all three.

## Register conventions (established)

- **Slots.** The registers sit in 8-byte slots. Every Bridge-family routine reads and writes a slot as **one 32-bit
  word at slot +4** (`lw`/`sw`; the data is in the low word of the big-endian doubleword). The census records the slot
  address with `halves` 4. The only 64-bit accesses are the two translation arrays (`ld`/`sd`). PIC and TIOCP differ
  (64-bit at the slot address). The IP30 PROM, the only PROM with resolved accesses, uses 32-bit `lw`/`sw` at slot +4
  as well.
- **Indexed families.** The accessors bound-check their index: 8 interrupt pins, 8 devices and 8 write-buffer slots
  (a compare against 8), 2 response-buffer registers, and for the internal translation entries `index < 129` on type 0
  and `index < 1025` on type 1. The bound lets one index through past the 128 and 1024 entries the attach clears;
  whether that is slack in the check or a real extra entry is unknown.
- **Windows above the registers** (census `census-windows.tsv`, handed to the IOC3, IOC4 and PCI-configuration work):
  PCI type 0 configuration at `0x20000` (4 KB per device slot), type 1 configuration at `0x28000`, external translation
  RAM at `0x80000`, device windows from `0x200000` (the driver's own buckets: 2 MB at `0x200000` and `0x400000`, 1 MB at
  `0x600000` and at each 1 MB step above). Nothing resolved touches `0x30000` (interrupt acknowledge) or `0xc00000`
  (external flash window).

## Register inventory

Offsets are slot addresses from the window base; the access is a 32-bit word at slot +4 unless the width column says
8. **Applies** says which of the two chips the routine reaches (B Bridge, X XBridge): read from the dispatch of the
accessor in the IP27 `unix` and, for four accessors where the chips differ, run in the unicorn harness
(`scripts/run_routine.py`) over the IP35 copy of the accessors (a harness stop is a panic path or a stub read, not told
apart). Grade is of the role and fields: **E** established (the accessor and its callers read in full, or an arithmetic
the code performs), **I** inferred (role from an accessor name or a PROM string, no field arithmetic read), **U**
unknown. Names are the public names used in `include/bridge.h`, except where an IRIX accessor name is quoted.

Totals over the **41 rows** below (families count once each; a row graded for some fields and inferred for the rest counts under its first grade): **17 established, 23 inferred, 1 unknown.**

### Widget block (the registers every XIO widget carries, offsets 0x0 to 0x70)

| slot | register | access | applies | who touches it | what the code does | grade |
|---|---|---|---|---|---|---|
| `0x0` | widget identification | r | both | `xbridge_attach`, `pcibr_alloc_all_rrbs`, `pcireg_id_get` and every dispatch | 32-bit read at +4; fields 31:28, 27:12, 11:1 isolated; see above | E |
| `0x8` | widget status | r | both | `xbridge_attach` (`pcireg_stat_get`) | bit 5 tested for a Bridge part (set means PCI mode); the PROM's field table names bits 31:24 `LLP_REC_CNT`, 23:16 `LLP_TX_CNT`, 6 `FLASH_SEL`, 5 `MODE` (values `GIO` and `PCI`) and 4:0 `PENDING` | E (bit 5), I (rest) |
| `0x10` | widget error address, upper | r | both | `pcireg_bus_err_get`; PROM error dump | read together with the lower word and returned as one 64-bit address; the PROM prints it under "Error address" | I |
| `0x18` | widget error address, lower | r | both | `pcireg_bus_err_get`; PROM error dump | as above | I |
| `0x20` | widget control | rw | both | `xbridge_attach`, `pcibr_map`, `pcibr_unmap`, `pcibr_reset`, `pcireg_ssram_size_set`, `pcireg_speed_get` | bit 21 set at attach; bit 31 set by `pcibr_map` and cleared by `pcibr_unmap`; bit `24 + slot` cleared then set by `pcibr_reset`; bits 18:17 replaced by the SSRAM size code (type 0 only); bits 5:4 returned as the bus speed (type 1 only). The PROM names bits 31 `FLASH_WR_EN`, 30 `EN_CLK50`, 29 `EN_CLK40`, 28 `EN_CLK33`, 27:24 `RST_MSK`, 23 `IO_SWP`, 22 `MEM_SWP`, 21 `PAGE_SZ`, 20 `SS_PAR_BAD`, 19 `SS_PAR_EN`, 18:17 `SS_RAM`, 16 `F_BAD_PKT`, 15:12 `LLP_XBAR_CRD`, 9 `ENDIAN`, 8:4 `MAX_TRANS`, 3:0 `WID_ID` | E (bits 31, 27:24, 21, 18:17, 5:4), I (rest) |
| `0x28` | widget request timeout | rw | both | `pcireg_req_timeout_get`, `pcireg_req_timeout_set` | accessors only; no constant stored by the Bridge-family attach | I |
| `0x30` | interrupt destination, upper | rw | both | `pcibr_setwidint`, `pcireg_intr_dst_*` | bits 19:16 hold the target widget (`pcireg_intr_dst_target_id_set` clears `0xf0000` and stores `(id & 0xf) << 16`); bits 15:0 hold address bits 47:32 (`pcireg_intr_dst_addr_set` clears `0xffff` and stores `(addr >> 32) & 0xffff`) | E |
| `0x38` | interrupt destination, lower | rw | both | `pcireg_intr_dst_addr_set` | stored whole: address bits 31:0 | E |
| `0x40` | widget error command word | r | both | `pcireg_cmdword_err_get`; `pcibr_error_dump`; PROM error dump | read; the PROM's field table names bits 31:28 `DIDN`, 27:24 `SIDN`, 23:20 `PACTYPE`, 19:15 `TNUM`, 14 `COHERENT`, 13:12 `DS`, 11 `GBR`, 10 `VBPM`, 9 `ERROR`, 8 `BARRIER` | I |
| `0x48` | widget LLP configuration | rw | both | `pcireg_llp_cfg_get`, `pcireg_llp_cfg_set` | accessors only | I |
| `0x50` | widget target flush | r | both | `pcireg_tflush_get` | read and discarded after the device-register, interrupt-enable and interrupt-reset writes of `pcibr_device_flags_set`, `pcibr_priority_bits_set`, `pcibr_intr_connect`, `pcibr_intr_disconnect` and `pcibr_error_cleanup`: a flush of the posted write | E (use as a read-back), I (name) |
| `0x58` | auxiliary error command word | r | both | `pcireg_linkside_err_get`; PROM error dump | read; the PROM prints it under "Aux error command word" | I |
| `0x60` | response buffer error, upper | r | both | `pcireg_resp_err_buf_get`, `pcireg_resp_err_dev_get`, `pcireg_resp_err_get` | bits 19:16 returned as a buffer number (shift 16, mask `0xf`), bits 22:20 as a device number (shift 20, mask 7), bits 15:0 are address bits 47:32 | E |
| `0x68` | response buffer error, lower | r | both | `pcireg_resp_err_addr_get` | address bits 31:0 | E |
| `0x70` | test pin control | | | none | no shipped routine touches it | U: no software depends on it |

### Bridge block (offsets 0x80 to 0x298)

| slot | register | access | applies | who touches it | what the code does | grade |
|---|---|---|---|---|---|---|
| `0x80` | direct-map window | rw | both | `pcibr_directmap_init`, `pcireg_dirmap_*` | field writes: bits 23:20 widget (`dirmap_wid_set` clears `0xf00000` and stores `(w & 0xf) << 20`), bits 16:0 offset (`dirmap_diroff_set` clears `0x1ffff`; `pcibr_directmap_init` passes it the translated address shifted right 31), bit 17 add-512-MB (`dirmap_add512_set` sets `0x20000`, `dirmap_add512_clr` clears it) | E |
| `0x90` | SSRAM parity error (Bridge) or map fault address (XBridge) | r | B (`pcireg_ssram_parity_get`), X (`pcireg_map_fault_get`, harness) | the two getters | one 32-bit read at +0x94 under either name; the two names are the two chips' | I |
| `0xa0` | arbitration | rw | both | `pcireg_arbitration_get`, `_set`, `_bit_set`, `_bit_clr` | accessors only on these chips (the one caller, `_bit_set` with `0xf00000` in `pcibr_error_intr_handler`, is on the PIC path) | I |
| `0xb0` | number-in-a-can (NIC) | rw | both | `pcireg_nic_addr` | returns a pointer to window +0xb4 instead of accessing it (census kind `a`); the PROM carries a "Number-In-a-Can (NIC)" string | I |
| `0xc0` | PCI bus timeout | rw | both | `xbridge_attach`, `pcireg_timeout_*` | attach clears bits 9:0 (mask `0x3ff`) when `revision | part << 4` is below `0xc0024` | E (bits 9:0), I (rest) |
| `0xc8` | PCI configuration (type 1 counter) | rw | both | `pcireg_type1_cntr_get`, `pcireg_type1_cntr_set` | accessors only | I |
| `0xd0` | PCI bus error address, upper | r | both | `pcireg_pci_bus_addr_get`, `pcibr_error_extract`; PROM error dump | the two are returned as one 64-bit address, `0xd0` word shifted left 32 over the `0xd8` word, without a mask in the accessor (Bridge and XBridge read each as a 32-bit word at +4; the PIC layout reads `0xd8` as one doubleword); the width of the upper field is not shown by the accessor | I |
| `0xd8` | PCI bus error address, lower | r | both | as `0xd0` | as `0xd0` | I |
| `0x100` | interrupt status | r | both | `pcibr_error_intr_handler`, `pcibr_force_interrupt`, IP30 PROM (three routines) | read; the handler tests bits 31:8 as errors and bits 7:0 are the pin inputs; the IP30 PROM tests mask `0x40` (name `PWR_SWITCH/6` in its table) and mask `0x20` (`PASSWD/5`) | E |
| `0x108` | interrupt enable | rw | both | `xbridge_attach`, `pcibr_detach`, `pcibr_intr_connect`, `pcibr_intr_disconnect` | attach reads the register and ORs in a 64-bit literal (`0x00003eff7ffffe00`, low word bits 30:9, no bit is cleared afterwards) in one 64-bit store; detach writes 0; connect and disconnect set and clear a pin bit | E |
| `0x110` | interrupt reset | w | both | `xbridge_attach`, `pcibr_error_cleanup`, `pcibr_dmard_error` | attach writes `0x7f`; the cleanup passes the 64-bit constant `0x3cff00000041`, of which the 32-bit store keeps `0x41`; `pcibr_dmard_error` writes `0x10`; one more routine writes `0x40` | E |
| `0x118` | interrupt mode | rw | both | `xbridge_attach` | attach writes 0; set and clear accessors exist | I |
| `0x120` | interrupt device | rw | both | `xbridge_attach`, `pcibr_intr_alloc`, `pcibr_intr_free` | attach writes `0xffffffff`; alloc clears and sets a field per pin and free clears with mask 7: three bits per pin by the mask | I |
| `0x128` | interrupt host error field | rw | both | `pcireg_intr_host_err_get`, `pcireg_intr_host_err_set` | `pcibr_setwidint` writes the low byte of the interrupt vector here | I |
| `0x130` + 8n | interrupt address (n = 0 to 7) | rw | both | `pcibr_intr_connect`, `pcibr_setpciint`, `pcireg_intr_addr_*` | bits 7:0 are the vector (`intr_addr_vect_set` clears `0xff` and stores `v & 0xff`); bits 17:8 (mask `0x3ff00`) are address bits that `intr_addr_addr_get` shifts right 2 and merges with the destination register's address | E (vector, mask), I (rest) |
| `0x170` | interrupt view | r | X | `pcireg_intr_view_get` | read on type 1; none on type 0 (harness) | I |
| `0x178` | interrupt multiple | r | X | `pcireg_intr_multiple_get` | as `0x170` | I |
| `0x180` + 8n | force interrupt always (n = 0 to 7) | w | X | `pcireg_force_always_set` | write on type 1; type 0 reaches `panic` (read in full) | E (chip, bound), I (role) |
| `0x1c0` + 8n | force interrupt with pin (n = 0 to 7) | w | X | `pcibr_force_interrupt` (`pcireg_force_intr_set`) | write per pin on type 1 | I |
| `0x200` + 8n | device (n = 0 to 7) | rw | both | `pcibr_device_flags_set`, `pcibr_priority_bits_set`, `pcibr_endian_set`, `pcireg_device_*`; IP30 PROM (one write) | `pcibr_endian_set` sets or clears the two bits `0x180000`; the flags and priority routines rewrite the register and read the flush register; the IP30 PROM writes device 2 with `0x1004` | I |
| `0x240` + 8n | write-buffer flush (n = 0 to 7) | r | both | `pcibr_wrb_flush` (`pcireg_wrb_flush_get`) | read of the device's slot; the value is returned | I |
| `0x280`, `0x288` | even and odd response buffers | rw | both | `pcibr_alloc_all_rrbs`, `pcibr_rrb_flush`, `pcireg_rrb_*` | index 0 touches `0x280`, index 1 `0x288`; the attach path passes `0x8` | I |
| `0x290` | response status | r | both | `pcireg_rrb_status_get` | read | I |
| `0x298` | response clear | w | both | `pcireg_rrb_clear_set` | write | I |

### Arrays

| slot | register | width | access | applies | who touches it | what the code does | grade |
|---|---|---:|---|---|---|---|---|
| `0x10000` + 8n | internal address-translation entries | 8 | rw | both | `xbridge_attach`, `pcireg_int_ate_get`, `pcireg_int_ate_set` | 128 entries on type 0 and 1024 on type 1 (record +112); attach zeroes all of them, one 64-bit store each; accepted index bound `< 129` and `< 1025` | E |
| `0x80000` + 8n | external translation RAM | 8 | rw | B | `pcibr_init_ext_ate_ram`, `pcireg_ext_ate_get`, `pcireg_ext_ate_set` | sized by a probe, see below; `pcireg_ext_ate_get` calls `panic` for types 1 to 3 | E |

### Not reached by any shipped routine or public driver (unknown)

- XBridge registers between `0x2a0` and `0x10000`: the census reaches nothing there, and the public OpenBSD and Linux
  headers name nothing there either. Whether the XBridge has registers at `0x300` to `0x5f8` is **unknown** (valid end
  state: no routine or public driver depends on it; the routes tried are the two kernels, the IP35 objects, the PROMs
  and the public headers).
- The interrupt-acknowledge window at `0x30000` and the flash window at `0xc00000`: no resolved access.

## Established sequences

- **Attach order (established, `xbridge_attach`, read in full).** In order, with the chip-type branches: status test
  (Bridge part only); identification; the mode and speed accessors, whose result goes to record +116; for
  `revision | part << 4` below `0xc0024`, `pcireg_timeout_bit_clr(0x3ff)`; interrupt reset `0x7f`; interrupt device
  `0xffffffff`; `pcibr_directmap_init`; `xbridge_attach` sets control bit `0x200000` through `pcireg_control_bit_set`; every internal translation entry zeroed; on type 0
  `pcibr_init_ext_ate_ram`; interrupt enable read, ORed with the literal and written back whole (the `revision | part << 4` tests
  near it, against `0xc0023` and `0xc0022`, set record fields and never touch the enable); interrupt mode 0; target flush read. The Bridge revision 2 path (at `0xc000000000070d98`)
  builds the enable mask differently and was not decoded. `xbridge_attach` returns -1 on two exit paths and 0 on the third. The returning instructions in each build's `xbridge.o` are: IP27 `0x15c` and `0x918` (-1), `0x85c` (0); IP30 `0x150` and `0x8d8` (-1), `0x820` (0); IP35 `0x19c` and `0xb14` (-1), `0xa3c` (0).
- **External translation RAM probe (established, `pcibr_init_ext_ate_ram` at `0xc00000000007566c`, read in full).** For
  sizes 1, 2 and 3 it writes `0x0123456789abcdef` to the last entry of the candidate size from a table of 8192, 16384
  and 65536 entries (the table is in the `unix` data section), writes zero to the last entries of the smaller
  candidates, reads the last entry back and records the largest size that returned the pattern. It then calls
  `pcireg_ssram_size_set` with that size (a code 1 to 3, shifted to bits 18:17 of control) and zeroes every entry.
  Reached on type 0 only.
- **Interrupt destination and vector (established, `pcibr_setwidint` at `0xc000000000079178`).** It reads the target,
  address and vector from the interrupt object (`xtalk_intr_target_get`, `xtalk_intr_addr_get`,
  `xtalk_intr_vector_get`), writes the target id with `pcireg_intr_dst_target_id_set` and the address with
  `pcireg_intr_dst_addr_set`, then writes the vector's low byte to the host error field with `pcireg_intr_host_err_set`.
  `pcibr_setpciint` writes the vector and address bits of a pin with `pcireg_intr_addr_vect_set` and
  `pcireg_intr_addr_addr_set`.
- **Interrupt enable and disable (established, `pcibr_intr_connect`, `pcibr_intr_disconnect`).** Connect sets the pin's
  bit in interrupt enable, then reads the target flush register; disconnect clears the bit, then reads the flush
  register.
- **Slot reset (established, `pcibr_reset` at `0xc000000000074688`).** It saves the slot's PCI configuration, clears
  the control bit `1 << (24 + slot)`, delays through `nano_delay` with a 1,000,000 ns interval, sets the bit, delays
  again, then writes the configuration back. The bit's polarity (set means the pin is released) is inferred from the
  order.
- **Error clean-up (established, `pcibr_error_cleanup`).** Writes `0x41` to the interrupt reset register (the low
  word of `0x3cff00000041`), then reads the flush register. `pcibr_dmard_error` writes `0x10`.

## IP30 PROM (established for the accesses, role inferred)

The IP30 PROM reaches one Bridge-family chip at `0xbf000000` (the uncached window of physical `0x1f000000`) and uses
32-bit accesses at slot +4. The census tags its rows `bridge` from the config's variant hint for that window, so they
are not evidence for Bridge against XBridge. Three routines matter:

- The routine at `0xbfc16300` sets up the chip behind the bridge for the console: it writes device 2 with `0x1004`,
  sets bit 1 of the PCI command register in configuration space (`0x22004`), writes `0x400000` to the first address
  register (`0x22010`), then writes that chip's own registers through device window 2 (`0x600000`). The offset field of
  the device register (bits 11:0) is in megabytes: 4 gives the `0x400000` the PCI address register receives.
- The routine at `0xbfc16680` is the error dump. It reads, in order, interrupt status (`0x104`), error command word
  (`0x44`), error address (`0x14`, `0x1c`), auxiliary error command word (`0x5c`), response buffer error (`0x64`,
  `0x6c`) and PCI bus error address (`0xd4`, `0xdc`), then the configuration registers at `0x22004`, `0x22044` and
  `0x22040`.
- The routines at `0xbfc00c10` and `0xbfc00dc0` read interrupt status and test mask `0x40` and mask `0x20`.

The PROM also carries the field-name tables quoted above (a block from `0xbfcc1fc0` to about `0xbfcc3040`); each
entry is a mask, a shift and a name. Which register each table decodes is inferred from the order of the dump
routine's strings and, for the response buffer error table, from the fields the kernel accessors use (device number
bits 22:20 and buffer number bits 19:16, which agree).

## What the census does not reach

- The IP27 PROM and the I/O-board PROM (`io6prom.img`): scanned with no resolved access; the window base is built at
  run time and neither has symbols. Open.
- Registers reached through an index the scan does not follow (device, interrupt pin, buffer and translation indexes):
  recorded at the family base.
- The revision 2 attach path and the decision trees of `pcibr_pioerror` and `pcibr_error_dump`: not read in full; the
  constants they pass are in `census/fields.tsv`.

## Reset expectations

Nothing in the shipped software reads a Bridge or XBridge reset value, so every reset value is **unknown** (valid end
state; routes tried: both kernels, the IP35 objects, the IP30 PROM). What the code assumes at attach, by what it
overwrites: pending interrupts are cleared (`0x7f`), the interrupt device register is written to all ones, the interrupt
mode to 0, every internal translation entry to 0, and the PCI retry counter field is cleared for the early Bridge
revisions. Which of those are settings rather than reset values is not known.

## Against the public drivers

Compared after the reading above. **Agree** means the driver's number or name is the one the binary uses;
**disagree** is a difference in value or behaviour.

- **Agree: slot layout and widths.** The Linux `bridge_t` structure puts every register at slot +4 as a 32-bit field
  and the translation arrays as 64-bit entries; OpenBSD reads and writes the same offsets.
- **Agree: identification.** Linux defines part `0xc002` with manufacturer `0x036` and part `0xd002` with `0x024`
  (`BRIDGE_WIDGET_PART_NUM`, `XBRIDGE_WIDGET_PART_NUM`, `BRIDGE_WIDGET_MFGR_NUM`, `XBRIDGE_WIDGET_MFGR_NUM`), the
  revisions A to D as 1 to 4. The binary compares 54 and 36 and uses `0xc0022` to `0xc0024` as revision thresholds.
- **Agree: control bits.** Page size bit 21, flash write enable bit 31, SSRAM size 18:17, reset pins 27:24 and the
  speed field 5:4 (OpenBSD `BRIDGE_WIDGET_CONTROL_SPEED_MASK 0x30`, shift 4) match the constants the binary uses. The
  PROM's own field names agree with the Linux names at every position except two spellings: the PROM calls the
  link-counter overflow bits `LLP_REC_CNT_OFLOW` and `LLP_TX_CNT_OFLOW` where Linux calls them `LLP_RCTY` and
  `LLP_TCTY`.
- **Agree: interrupt addressing.** Linux and OpenBSD put the vector in bits 7:0 and the address bits at 17:8
  (`BRIDGE_INT_ADDR_FLD 0xff`, `BRIDGE_INT_ADDR_HOST 0x3ff00`); the Linux probe writes the destination upper register
  as `(addr >> 32 & 0xffff) | widget << 16`, the field layout the IRIX accessors use.
- **Agree: direct map.** Linux `BRIDGE_DIRMAP_W_ID` (shift 20), `BRIDGE_DIRMAP_ADD512` (bit 17) and
  `BRIDGE_DIRMAP_OFF` (`0x1ffff`) are the fields the binary's accessors edit; the Linux bit 18 (`RMF_64`) is never
  touched by IRIX.
- **Agree: interrupt reset and enable.** Linux `BRIDGE_IRR_ALL_CLR` is `0x7f`, the value attach writes; Linux sets
  `0x7ffffe00` into interrupt enable ("more stuff in int_enable"), the low word of the literal the binary ORs in.
- **Agree: translation entry counts.** OpenBSD `BRIDGE_INTERNAL_ATE` 128 and `XBRIDGE_INTERNAL_ATE` 1024 are the counts
  stored at record +112.
- **Agree: XBridge-only registers.** OpenBSD marks `0x180 + 8d` (force always) and `0x1c0 + 8d` (force with pin) as
  XBridge-only; the binary panics on them for type 0.
- **Agree: response buffer fields.** OpenBSD `RRB_VALID 0x8`, `RRB_VCHAN 0x4`, `RRB_DEVICE_MASK 0x3`; Linux
  `BRIDGE_RRB_EN 0x8`; the attach path passes `0x8`.
- **Disagree: interrupt device register at attach.** The Linux probe and OpenBSD both write 0 to the interrupt device
  register; IRIX writes `0xffffffff`. Neither public driver says why. Open.
- **Disagree: control swap bits.** The Linux probe clears the I/O and memory swap bits (23 and 22) in control; the
  IRIX attach does not touch them. The reset value of those bits is unknown.
- **Not in the public drivers: the SSRAM probe.** Neither public driver sizes the external translation RAM; IRIX does
  (above).
- **Public register names with no IRIX access:** test pin control (`0x70`), interrupt acknowledge (`0x30000`),
  external flash window (`0xc00000`).

## Routines in the IP27 `io6.o`, `pciiox.o` and `xbridge.o` builds

Read in full from the IRIX 6.5.30 IP27 objects (`IP27/usr/cpu/sysgen/IP27boot/io6.o`, `pciiox.o` and `xbridge.o`, relocatable;
addresses are offsets in `.text`). `io6.o` and `pciiox.o` each register a callback with `nic_vmc_add` for the part-number
prefixes of one board. Inferred: the callback receives the Bridge vertex of a matching board, because it passes the
argument to `pcibr_hints_fix_rrbs` and `xtalk_piotrans_addr`. Both callbacks call `xtalk_piotrans_addr` with offset 0 and length
`0x1000000` and store words at +644 and +652 of the pointer it returns, which are the low words of the doubleword
response-buffer registers at `0x280` and `0x288` (see "Bridge block") if that pointer is the register base.

- `io6_init` (`IP27/usr/cpu/sysgen/IP27boot/io6.o` at 0x0, 64 bytes)
  calls `nic_vmc_add` three times with the callback `io6_vmc` and the part-number prefixes `030-0734-`, `030-1023-` and
  `030-1124-`, in that order (the strings sit 16 bytes apart in `.rodata`). It returns nothing of its own. Established.
- `io6_vmc` (`IP27/usr/cpu/sysgen/IP27boot/io6.o` at 0x40, 260 bytes)
  takes the Bridge vertex in `a0`. It calls `nic_vertex_info_match` with the prefix `030-0734-`, then reads the byte at
  `0xffffffffffffc523`; when that byte is nonzero it calls `panic` with the string "SN00 without programed nic on mother
  board" (the match result is not tested there) and the code after it runs if `panic` returns. It then calls `pcibr_hints_dualslot` (vertex, 2, 4),
  `pcibr_hints_subdevs` (vertex, 2, and `0xbf` when the match was nonzero, else `0xb7`), `xtalk_piotrans_addr` and
  `pcibr_hints_fix_rrbs`. Using the pointer `xtalk_piotrans_addr` returned it rewrites two words: at +644 it keeps bits 31:28 and
  sets bits 27:0 to `0x0ca98888`, and at +652 it keeps bits 31:20 and sets bits 19:0 to `0x000c8888`; the second store sits in the
  delay slot of the `hwgraph_traverse` call that follows with the path `pci/controller`. Last it calls `device_inventory_add`
  with the vertex that traversal returned, class 21 and four zeros. Established. Inferred: the two words are the low halves of the
  even and odd response-buffer registers, since the Bridge register inventory records `0x280` and `0x288` as the response buffer
  registers that `pcibr_alloc_all_rrbs` indexes by 0 and 1 and the stores are 4 bytes past them. The byte at `0xffffffffffffc523` is
  the one `cpuprom_map` in `hubspc.o` tests; what sets it is unknown, and the route is the stores to that address in the kernel.
- `pciiox_init` (`IP27/usr/cpu/sysgen/IP27boot/pciiox.o` at 0x0, 32 bytes)
  calls `nic_vmc_add` once with the callback `pciiox_vmc` and the prefix `030-1062-`. Established.
- `pciiox_vmc` (`IP27/usr/cpu/sysgen/IP27boot/pciiox.o` at 0x20, 80 bytes)
  takes the Bridge vertex in `a0`, calls `pcibr_hints_fix_rrbs` and then `xtalk_piotrans_addr`, and stores whole words through the
  returned pointer: `0x00999888` at +644 and `0x888` at +652 (the second store is in the delay slot of the return). Unlike
  `io6_vmc` it keeps no bits of the old values and makes no hint or inventory call. Established. Inferred: these are the same
  response-buffer words as in `io6_vmc`, for the same reason.
- `xbridge_init` (`IP27/usr/cpu/sysgen/IP27boot/xbridge.o` at 0x0, 84 bytes)
  calls `pcibr_debug` with 1, 0 and the string "pcibr_init()", then `xwidget_driver_register` twice with the
  prefix `xbridge_`: for part `0xd002` and manufacturer 36, then for part `0xc002` and manufacturer 54, each with flags 0.
  Established. Those pairs are the XBridge and Bridge identities listed under "What identifies the chip", so one driver
  serves both.

## Routines in the IP30 and IP27 kernels

The accessors and the attach routines of the Octane kernel, which serve this chip family through the same `pcireg_*`
dispatch, are described routine by routine in [docs/ip30-kernel-bridge-routines.md](../../docs/ip30-kernel-bridge-routines.md).

The routines of the IP27 kernel that serve the same family are in [docs/ip27-kernel-bridge-routines.md](../../docs/ip27-kernel-bridge-routines.md).

## Open

See docs/open-questions.md: the revision 2 attach path; the interrupt device value at attach; the units and layout of
the response buffer registers; whether any XBridge register lies above `0x298`; the PROMs that reach the chip through
a run-time window.
