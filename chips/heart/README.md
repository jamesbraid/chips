# HEART

Mode: **no-spec** (see [docs/specs.md](../../docs/specs.md): no specification is held). IP30 system controller:
memory controller, interrupt controller, timer and the XIO port of the Octane family. Every fact below comes from
four shipped IP30 files: the IRIX 6.5.30 kernel (`unix`), the CPU PROM (`IP30prom.bin`), the diagnostic program
(`ide.IP30`) and the symbolic monitor (`symmon.IP30`). The public Linux driver
(`arch/mips/include/asm/sgi/heart.h`, v6.12) was read afterwards, only to report agreement and conflict.
Census: [census/](census/census.md) (`census.tsv`, `fields.tsv`, `context.tsv`, `census-sites.tsv`), config
[`tools/configs/heart.json`](../../tools/configs/heart.json), header [`include/heart.h`](../../include/heart.h).

## Addresses (established)

- The register block ("PIU") sits at physical `0x0ff00000`. The kernel holds it as a pointer, `heart_piu`, whose
  initial value in the data section is `0xffffffffaff00000` (uncached window of the 32-bit compatibility segment);
  most kernel and PROM code builds the same address with `lui 0xaff0`, `0xaff1`, `0xaff2` and `0xaff5`. The
  diagnostic reaches it through the 64-bit uncached window, address `0x9000000000000000 | 0x0ff00000`
  (`0x9000...` ORed with the table address, in the register test at `0xa800000020892300` of `ide.IP30`).
- HEART also answers as XIO widget 8. Its widget block is at physical `0x18000000` (kernel pointers
  `0x9000000018000004`, `0x9000000018000014` and so on in the small-data area; `0xb8000000` in the probe routines
  `badaddr` and `wbadaddr`). The kernel reaches widget n at `0x10000000 + n * 0x1000000` (`heart_startup` probes
  widget 15 down to 0 that way, reading each identification word at offset 4).
- Register slots are 8 bytes. A widget-block register holds its 32-bit value in the low word, so the code reads it
  with a word load at slot + 4 (kernel) or at the slot (PROM dump): both widths are recorded in the census.
- In the census the widget block is reported 0x100000 above its widget offset (`0x100004` is widget offset 4), so
  the two blocks do not collide in one table.

## Register inventory

Census result over four images (kernel 276 sites, PROM 303, diagnostic 106, monitor 80; 765 site records): 39
census rows, 41 registers once the two indexed families (flow-control address and count, units 0 and 1) are
expanded. The diagnostic's register-test table names 11 more that no held code touches. 52 registers in all.
Grades: 18 established, 21 inferred, 13 unknown (the 11 untouched ones, plus TRIGGER and SYNC, which code reaches
but whose role is not read).

Grades follow AGENTS.md. A row is **established** when a routine that uses it was read in full and its offset,
width and a role or field use are in the code; **inferred** when the role rests on a name, a sibling table or the
public driver; **unknown** when no held code touches it. Names are the diagnostic's own `HEART_*` strings; SET_ISR,
CLR_ISR, ISR, IMSR, COUNT, TRIGGER, PRID and SYNC are printed by no held file and take the public driver's names
(inferred). Reset values are unknown for every register except where a section says otherwise.

| Offset | Name | Width | Access | Grade | What the held code shows |
|---|---|---|---|---|---|
| `0x0` | MODE | 8 | rw | established | Mode and reset control. Bit 22 is set by read-modify-write in the PROM followed by a read-back loop (soft reset, see below); bits 63:60 are the four processor-disable bits the PROM tests (shift 60). Bit names from the monitor table. |
| `0x8` | SDRAM_MODE | 8 | - | unknown | Listed by the diagnostic (mask 0xfffff, not read-write tested); no held code touches it. |
| `0x10` | MEM_REF | 8 | - | unknown | Listed by the diagnostic (mask 0xfffff); no held code touches it. |
| `0x18` | MEM_ARB | 8 | rw | inferred | Memory request arbitration. The kernel sets bit 20 around a memory scrub in the correctable-error path and restores the old value; the name and mask 0x1fffff come from the diagnostic. |
| `0x20` | MEMCFG0 | 8, 4 | rw | inferred | Bank configuration, two 32-bit entries per register (diagnostic mask 0x803f01ff in each half). Also read as words at 0x20 + 4k, k below 8. |
| `0x28` | MEMCFG1 | 8 | rw | inferred | As MEMCFG0. |
| `0x30` | MEMCFG2 | 8 | r | inferred | As MEMCFG0. |
| `0x38` | MEMCFG3 | 8 | r | inferred | As MEMCFG0. |
| `0x40` | FC_MODE | 8 | rw | inferred | Graphics flow control mode. The kernel flow-control code stores 0x45 once; diagnostic mask 0x3fff. |
| `0x48` | FC_LIMIT | 8 | w | inferred | Flow control timer limit (name; diagnostic mask 0x3ffffff). |
| `0x50` | FC0_ADDR | 8 | w | inferred | Flow control address, one per flow-control unit (family of two at 0x50 and 0x58); diagnostic mask clears bits 4:0. |
| `0x58` | FC1_ADDR | 8 | w | inferred | As FC0_ADDR (unit 1). |
| `0x60` | FC0_COUNT | 8 | rw | inferred | Flow control credit count, read and written by the kernel credit get/set routines; diagnostic mask 0xfff. |
| `0x68` | FC1_COUNT | 8 | rw | inferred | As FC0_COUNT (unit 1). |
| `0x70` | FC0_TIMER | 8 | - | unknown | Listed by the diagnostic (mask 0x3ffffff); no held code touches it. |
| `0x78` | FC1_TIMER | 8 | - | unknown | As FC0_TIMER. |
| `0x80` | STATUS | 8 | r | established | Bits 3:0 are the widget number HEART answers to (passed to the widget registration in `heart_startup`); bits 7:4 are tested by the PROM, bit 11 by three PROM routines. Diagnostic mask 0xffff00ff. |
| `0x88` | BERR_ADDR | 8 | r | established | Address latched for a bus error: bits 39:0 are a physical address (masked and compared with the decoded faulting address in `dobuserr_common`). |
| `0x90` | BERR_MISC | 8 | r | established | Bus error companion: bits 22:21 are the processor number (shift 21, mask 3 in `dobuserr_common`). Other bits unknown. |
| `0x98` | MEM_ERR | 8 | r | established | Memory error latch: bits 33:0 address (compared with the decoded address), bits 41:34 a bank selector, bit 42 and bits 45:43 flags and a processor field. Meanings of the upper fields inferred. |
| `0xa0` | BAD_MEM | 8 | r | inferred | Passed to the DIMM error logger as the data argument; the diagnostic prints it as "bad memory data". |
| `0xa8` | PIU_ERR | 8 | r | established | PIU register access error latch: bits 21:20 processor number, bits 19:3 offset of the register the access hit (`dobuserr_common`). |
| `0xb0` | MLAN_CLK_DIV | 8 | - | unknown | Listed by the diagnostic (mask 0x7f7f); no held code touches it. |
| `0xb8` | MLAN_CTL | 8 | - | unknown | Listed by the diagnostic (mask 0xffc02); no held code touches it. |
| `0x10000` | IMR0 | 8 | rw | established | Interrupt mask, one per processor at 0x10000 + 8n. `heart_mlreset` clears all four, then arms IMR[n] with bits 42+n, 46+n, 59+n and 63. `heart_imr_bits_rmw` does read-modify-write under a compare-and-swap lock. |
| `0x10008` | IMR1 | 8 | rw | established | As IMR0, processor 1. |
| `0x10010` | IMR2 | 8 | rw | established | As IMR0, processor 2. |
| `0x10018` | IMR3 | 8 | rw | established | As IMR0, processor 3. |
| `0x10020` | SET_ISR | 8 | w | inferred | The kernel writes 1 << n here to raise vector n on a processor (`heart_set_cpu_intr`, the inter-processor send path). Name from the public driver. |
| `0x10028` | CLR_ISR | 8 | w | established | `heart_intr` writes 1 << vector to acknowledge a vector, before the handler for vectors 3 and above, after it for vectors 0 to 2. |
| `0x10030` | ISR | 8 | r | inferred | Interrupt status. Read in the error-lock wait loop of `dobuserr_common` to see whether this processor's bit 46+n is pending. Name from the public driver. |
| `0x10038` | IMSR | 8 | r | inferred | Read by `heart_intr` and ANDed with the argument it was given, then dispatched by highest set bit: used as the pending-and-enabled word (inferred). Name from the public driver. |
| `0x10040` | CAUSE | 8 | rw | established | Error cause bits, named in the cause bits section. The probe routines store back the value they read; the memory scrub path stores 1 (write-one-to-clear is inferred). |
| `0x20000` | COUNT | 8, 4 | r | inferred | Free-running timer; the kernel clock code reads it as a doubleword and `_get_timestamp` reads the low word at 0x20004. Width of the counter inferred 52 bits by the public driver only. |
| `0x30000` | COMPARE | 8 | - | unknown | Listed by the diagnostic as read-write tested with mask 0xffffff; no kernel, PROM or monitor code touches it. |
| `0x40000` | TRIGGER | 8 | w | unknown | Written twice by the PROM (two routines); the value and purpose are not read. |
| `0x50000` | PRID | 8 | r | established | Number of the processor doing the read: `getcpuid` and `VEC_dbe` use it as an index 0 to 3 into the per-processor interrupt mask. |
| `0x60000` | SYNC | 8 | r | unknown | Read once, in `dobuserr_common`; purpose not read. |
| `0x100000` | WID_ID | 8, 4 | r | established | Widget identification word, in the low word at widget offset 4: bits 31:28 revision (`heart_rev`), bits 27:12 part number and bits 11:1 manufacturer number (`heart_startup`, same layout for every widget it probes). |
| `0x100008` | WID_STAT | 8 | - | unknown | Listed by the diagnostic (mask 0xffff001f); no held code touches it. |
| `0x100010` | WID_ERR_UPPER | 4 | r | inferred | Failing-request address, upper part: the kernel reads the low word (offset 0x14), the PROM the word at 0x10; low 16 bits joined with WID_ERR_LOWER form a 48-bit address in `dobuserr_common`. |
| `0x100018` | WID_ERR_LOWER | 4 | r | inferred | Failing-request address, lower 32 bits (kernel reads offset 0x1c). |
| `0x100020` | WID_CONTROL | 8 | - | unknown | Listed by the diagnostic (mask 0xffffffff); no held code touches it. |
| `0x100028` | WID_REQ_TIMEOUT | 4 | rw | inferred | Request timeout: `heart_startup` stores 40000, or 0x80 when the kernel debugger is configured; `giobr_attach` stores 0x80. Unit unknown. |
| `0x100040` | WID_ERR_CMDWORD | 8, 4 | rw | inferred | Command word of the failing request. Cleared before every probed access; the kernel reads it as a word at offset 0x44 and takes a read/write flag from bit 7, a command code from bits 7:0 and a source widget from bits 27:24. |
| `0x100048` | WID_LLP | 8 | - | unknown | Listed by the diagnostic (mask 0x3ffffff); no held code touches it. |
| `0x100050` | WID_TARG_FLUSH | 8 | - | unknown | Listed by the diagnostic (mask 0xffffffff); no held code touches it. |
| `0x100060` | WID_ERR_TYPE | 8, 4 | rw | established | Widget error type bits; names and positions from the monitor decode table (see the widget error section). Written back with the value just read after each probe. |
| `0x100068` | WID_ERR_MASK | 8 | w | inferred | `heart_mlreset` stores 0x3ff62c07. Role inferred from the name: error types whose bit is set are enabled. |
| `0x100070` | WID_PIO_ERR_UPPER | 8, 4 | r | established | Failed PIO latch: bits 7:0 address bits 39:32, bits 23:22 processor number, bit 15 a read-or-write flag (sense inferred). |
| `0x100078` | WID_PIO_ERR_LOWER | 8, 4 | r | established | Failed PIO latch: address bits 31:0. |
| `0x100090` | WID_PIO_RTO_ADDR | 8, 4 | r | established | PIO read timeout latch: bits 19:18 processor number, bits 15:12 widget port, bits 11:0 address bits 23:12. |

`MEMCFG0` to `MEMCFG3` need two access widths: the PROM reads and writes the first two as doublewords, and word
reads at `0x20 + 4k` appear in four images.

### Diagnostic register-test table (established as what the diagnostic expects)

`ide.IP30` holds a 32-byte-entry table (name, address, mask, flags) at `0xa800000020946560`, 44 entries ending in an
empty name; the routine at `0xa800000020892300` walks it. For an entry whose flag word is exactly 1 it saves the
register, writes each of six patterns (`0x5a5a...`, `0xa5a5...`, `0xcccc...`, `0x3333...`, `0xf0f0...`, `0x0f0f...`)
ANDed with the mask by doubleword store, reads back and compares under the mask, then restores the old value.
Entries tested this way: WID_REQ_TIMEOUT, WID_ERR_MASK, FC0_ADDR, FC1_ADDR, MLAN_CLK_DIV, IMR0 to IMR3, COMPARE.
Entries with flag word 3 (WID_CONTROL, WID_TARG_FLUSH, MEMCFG0 to MEMCFG3) and 0 are not written by that routine;
what flag 3 selects is unknown. The mask is the set of bits the diagnostic expects to hold a value, a statement
about the diagnostic, not a measurement of the chip. Masks are quoted in the table above where they add a field.

## Cause bits (established names, from the kernel and monitor tables)

The kernel holds a 37-entry table of CAUSE bit names (entries of mask, negated bit number, name; at file offset
`0x412ba8` of `unix`) and the monitor holds the same bits under other names (`0x49280` of `symmon.IP30`). The
diagnostic names bit 16 `WIDGET_ERR`. Both tables agree on every position.

| Bit | Kernel name | Monitor name |
|---|---|---|
| 63:60 | PE_SysCorErr3 to 0 | PE_SYS_COR_ERR_3 to 0 |
| 44 | PIOWDB_OV | PIOWDB_OFLOW |
| 43 | PIORWRB_OV | PIORWRB_OFLOW |
| 42 | PIUR_AccessErr | PIU_REG_ACC_ERR |
| 41 | BadSysWrErr | SYSAD_WR_ERR |
| 40 | BadSysRdErr | SYSAD_RD_ERR |
| 39:36 | SysStateErrProc3 to 0 | SYSSTATE_ERR_3 to 0 |
| 35:32 | SysCmdErrProc3 to 0 | SYSCMD_ERR_3 to 0 |
| 31:28 | NCorSysErrProc3 to 0 | NCOR_SYSAD_ERR_3 to 0 |
| 27:24 | CorSysErrProc3 to 0 | COR_SYSAD_ERR_3 to 0 |
| 23:20 | DataElmntErrProc3 to 0 | DATA_ELMNT_ERR_3 to 0 |
| 16 | WidgetError | WIDGET_ERR |
| 7:4 | MemAddrErrProc3 to 0 | MEM_ADDR_ERR_3 to 0 |
| 2 | MemAddrErrIO | MEM_ADDR_ERR_IO |
| 1 | NCorMemErr | NCOR_MEM_ERR |
| 0 | CorMemErr | COR_MEM_ERR |

MODE has a matching set of error-enable bits (monitor table at `0x47ca0`, low word): bit 10 BAD_SYSWR_ERE, 9
BAD_SYSRD_ERE, 8 SYSSTATE_ERE, 7 SYSCMD_ERE, 6 NCOR_SYS_ERE, 5 COR_SYS_ERE, 4 DATA_ELMNT_ERE, 3 MEM_ADDR_PROC_ERE,
2 MEM_ADDR_IO_ERE, 1 NCOR_MEM_ERE, 0 COR_MEM_ERE, 16 PE_SYS_COR_ERE; bit 22 SW_RST, 23 COLD_RST, 21 MEM_FORCE_WR,
20 DB_ERR_GEN, 18 CACHED_PIO_EN, 15 GLOBAL_ECC_EN, 14 IO_COH_EN, 13 INT_EN, 12 DATA_CHK_EN, 11 REF_EN; bits 63:60
DIS3 to DIS0. These are the names and positions the monitor prints; what each bit does to the chip is inferred from
the names, except bit 22 (below).

## Widget error type bits (established names)

The monitor's decode table for WID_ERR_TYPE (at `0x48100`) names: bit 0 PIO_WCR_ACC_ERR, 1 PIO_XTLK_ACC_ERR, 2
PIO_WR_TIMEOUT, 3 PIO_RD_TIMEOUT, 12 LLP_TX_RETRY, 13 LLP_TX_RETRY_TIMEOUT, 14 LLP_RCV_SQUASH_DATA, 15
LLP_RCV_CB_ERR, 16 LLP_RCV_SN_ERR, 17 LLP_RCV_LNK_RST, 18 LLP_RCV_WARM_RST, 20 IOR_INT_VEC_WARN, 21 IOR_INT_VEC_ERR,
22 IOR_CMD_WARN, 23 IOR_CMD_ERR, 24 IORWRB_OFLOW_ERR, 25 IO_UNEXPECTED_RESP_ERR, 26 IO_BAD_FORMAT, 27 IO_NONHEAD, 28
XBAR_CREDIT_UNDER, 29 XBAR_CREDIT_OVER. The expansion of "WCR" is not read.

## Interrupt vectors (established names, from the monitor table at `0x48858`)

Vector names by ISR bit: 63 HEART_EXC, 62 to 59 BERR3 to BERR0, 58 XBOW, 57 BASEIO, 56 to 51 WIDE to WID9 (widgets
14 to 9), 50 TIMER, 49 to 46 IPI3 to IPI0, 45 to 42 DBG3 to DBG0, 41 POWER, 40 ACFAIL, 15 ETHER, 14 SERIAL, 2 FC1,
1 FC0, 0 IRQ; the other bits print as `vecN`. The kernel agrees on the processor-specific groups: `heart_mlreset`
arms IMR[n] with bits 42+n (DBG), 46+n (IPI), 59+n (BERR) and 63 (HEART_EXC). Priority levels (bit 63 to 51 level
4, 50 level 3, 49 to 32 level 2, 31 to 16 level 1, 15 to 0 level 0) are the public driver's; not read in the kernel.

## Access sequences (established unless marked)

- **Soft reset.** The PROM routine at `0xffffffffbfc30b6c` loads MODE, ORs bit 22, stores it, and loops
  re-reading MODE: it waits for the reset to take hold. Another PROM routine (`0xffffffffbfc358bc`) sets bit 21,
  then stores zero doublewords over a 128-byte-aligned block (a memory initialisation: role of bit 21 inferred).
- **Probe an address that may not answer** (`badaddr`, `badaddr_val`, `wbadaddr`, `wbadaddr_val`, and the early
  forms, all in `unix`, `wbadaddr` and `badaddr` read in full). With interrupts off (coprocessor 0 Status 0xa0):
  read WID_ERR_TYPE, store zero to WID_ERR_CMDWORD, read WID_ID as a flush, store the saved WID_ERR_TYPE value
  back, read CAUSE and store the same value back, read PRID as a flush; mark the thread no-fault; do the access
  (a load of 1, 2, 4 or 8 bytes for `badaddr`, a store of zero of that width for `wbadaddr`); flush with PRID and
  WID_ID reads and a sync (twice for `wbadaddr`, which then reads the word at uncached physical address 0). Then the
  failure test: coprocessor 0 Cause bit 14 (the IP6 line) pending, or CAUSE bit 16 (WIDGET_ERR) set. Either sends
  the routine to `baerror`, which repeats the clear sequence and reports failure. The probe never tests CAUSE
  bits 40, 41 or 42.
- **Interrupt dispatch** (`heart_intr`). Reads IMSR, ANDs it with the pending mask passed in, takes the highest
  set bit. Vectors below 59 call the handler registered in `heart_ivec` (64 bytes per vector); for vector 3 and
  above CLR_ISR is written with that bit first, for vectors 0 to 2 after the handler. Vectors 59 and above go to
  `buserror_intr` (the bus-error and HEART_EXC path).
- **Reset of the controller state** (`heart_mlreset`, read in full). Stores zero to WID_ERR_MASK, stores
  WID_ERR_TYPE back unchanged, stores zero to WID_ERR_CMDWORD, stores `0x3ff62c07` to WID_ERR_MASK, zeroes IMR0 to
  IMR3, then arms the calling processor's mask as above.
- **Data bus error** (`VEC_dbe`, read in full). Reads PRID, removes bits 59+n and 63 from IMR[n] before it
  continues to the generic trap path, so the per-processor error vector and HEART_EXC do not fire again while the
  exception is handled.
- **Vector allocation for widget errors** (`do_heart_intr_alloc`). When the request carries the widget-error flag
  the vector is `51 + ((widget + 7) & 7)`: widgets 9 to 15 get 51 to 57, widget 0 gets 58. Widget 8 (HEART itself)
  also computes 58.

## Error handling in the kernel (`dobuserr_common`, read for the cause paths below)

`dobuserr_common` takes a lock, snapshots MODE, CAUSE, PIU_ERR, BERR_MISC, BERR_ADDR, MEM_ERR, BAD_MEM and the
widget error registers into a per-processor record, decodes the faulting address from the load or store at the
exception address, and converts it to a widget with `heart_paddr_to_port` (decompiler output read against the
listing, so the decode is read, not read in full). The message strings below are the ones the calls print
(checked against the small-data string base). Paths, in the order the routine tests them:

1. **Bits 41 and 40 and the system address bits 31:24** (mask `0x300ff000000`, a word in the small-data area): if
   BERR_MISC bits 22:21 equal this processor, the error address is BERR_ADDR bits 39:0, the record is flagged read
   (bit 40), write (bit 41) and passed to `heart_error_refine`; the message is "Heart Bus Error". When the faulting
   address decodes to a widget and WID_ERR_TYPE bit 3 is set, CAUSE is treated as if bit 16 were set too.
2. **Widget error (bit 16).** Any of WID_ERR_TYPE bits 29:28, 25:24, 17:16, 13 (mask `0x33062000`) is fatal ("Fatal
   Heart Widget Error"); bits 26 and 23:20 (mask `0x4f00000`) take the command-word path (WID_ERR_CMDWORD,
   WID_ERR_UPPER and LOWER; "Heart Widget Error"); bit 3 takes the read-timeout path (WID_PIO_RTO_ADDR; "Heart PIO
   Read Timeout Error"); bits 2:0 take the PIO error path (WID_PIO_ERR_UPPER and LOWER: address bits 39:0, processor
   bits 23:22 of UPPER; "Heart Widget PIO Error"). The LLP bits are only counted.
3. **Memory errors (CAUSE bits 1:0)**: when only bit 0 (correctable) is set the routine stores 1 to CAUSE, sets
   MEM_ARB bit 20, rewrites the failing location (address MEM_ERR bits 33:0) and restores MEM_ARB (a scrub) and logs
   the DIMM; any other combination is fatal. Bits 7:4 and 2 not read.
4. **PIU register access (bit 42)**: if PIU_ERR bits 21:20 equal this processor, the routine builds the physical
   address `0x0ff00000 | PIU_ERR[19:3]`, compares it with the decoded faulting address (the result is only
   recorded) and panics with the message "Heart PIU Register Access Error".

## Reset expectations

Established: `heart_mlreset` (above) is the kernel's whole reset of interrupt masks and widget error state.
Unknown: reset values of all registers (no held code reads a register to compare it with a reset value; the
diagnostic's "Heart cause was not reset" and "Heart ISR was not reset" messages say CAUSE and ISR are expected to
read zero after its reset routine, which is a statement about the diagnostic).

## Against the public driver (reported after the reading above)

No HEART specification is held, so there is no specification comparison. The public Linux header
(`heart.h`, v6.12) was compared with every register above.

Agreements:
- Every PIU offset the code reaches, 0x0 to 0xa8, 0x10000 to 0x10040, 0x20000, 0x40000, 0x50000, 0x60000, matches
  a Linux register (mode, memory, flow control, status, bus error, memory error, PIU access error, mask, set and
  clear status, status, masked status, cause, count, trigger, processor id, sync). The diagnostic's COMPARE at
  0x30000 matches Linux `compare`.
- All 37 CAUSE bit positions in the kernel and monitor tables equal Linux `HC_*`; all 27 MODE bit positions
  the monitor prints equal Linux `HM_*`; vectors 51 to 63 equal Linux `HEART_L4_INT_*` in count and order (widget
  vectors, per-processor bus errors, HEART_EXC). The `+0x0ff00000` base equals Linux `HEART_XKPHYS_BASE`.
- The BERR_ADDR and BERR_MISC roles (error address, error context) fit Linux's guessed `bus_err_addr`,
  `bus_err_misc`; Linux labels both "likely" and gives no fields.

Conflicts and gaps:
- Linux leaves BERR_MISC, PIU_ERR, MEM_ERR and the widget block undocumented; the kernel decode above supplies
  fields (processor numbers, address bits). Nothing in the public header contradicts them.
- MODE bit 17 `CACHED_PROM_EN` is in Linux but absent from the monitor's table; the monitor table has the same
  entries otherwise. Not a contradiction, the monitor may simply not name it.
- MEMCFG density field (Linux bits 24:22, mask `0x01c00000`) is outside the diagnostic's expected mask
  `0x803f01ff` per word; the diagnostic does not test it.
- Linux says `MEMCFG` reads are right only as 32-bit; the PROM reads and writes the first two as doublewords.
  The diagnostic's mask repeats one 32-bit layout in both halves, which fits two banks per register; not a
  conflict, but a doubleword read's meaning is unproven.
- Linux uses vectors 46 and 47 for reschedule and 48 and 49 for call-function interrupts; the monitor names 46
  to 49 IPI0 to IPI3 and the kernel arms 46+n per processor. A software convention, not a hardware difference.

## Routines in the IP30 `heart.o` build

Each routine below was read in full from the shipped `heart.o` at the address given. The entries describe the instructions as
issued, including delay slots, which run before the branch or call they belong to.

- `heart_intr_alloc` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x11ec`, 28 bytes, read in full, established): saves `ra` in a
  16-byte frame, calls `do_heart_intr_alloc` at `0x11f4` with `a0` to `a2` unchanged and `a3` set to 0 in the call's delay slot, and
  returns that call's result in `v0`. The only other instructions restore `ra` and the stack pointer.
- `heart_intr_alloc_nothd` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x1208`, 28 bytes, read in full, established): the same frame
  and call as `heart_intr_alloc`, calling `do_heart_intr_alloc` at `0x1210` with `a3` set to 1 at `0x1214`. It returns that call's
  result in `v0`.
- `heart_intr_bits_free` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x120`, 32 bytes, read in full, established): ORs `a0` into the
  64-bit word `heart_ivec_free` with an `lld`/`scd` pair at `0x124` and `0x12c`. The `beql` at `0x130` repeats the pair while the `scd`
  flag left in `v1` is zero. It makes no calls. `v0` holds the address of `heart_ivec_free` on return, not a status.
- `heart_intr_bits_take` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x140`, 36 bytes, read in full, established): clears the bits set
  in `a0` from `heart_ivec_free`. It inverts `a0` at `0x144` and ANDs the result into the word with an `lld`/`scd` pair at `0x148` and
  `0x150`. The `beql` at `0x154` repeats the pair while the `scd` flag left in `a0` is zero. It makes no calls and returns the address
  of `heart_ivec_free` in `v0`.
- `heart_intr_free` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x1224`, 60 bytes, read in full, established): reads the byte at offset
  5 of the record in `a0`. It calls `heart_intr_bits_free` at `0x123c` with `1 << byte`, the shift done by the `dsllv` in the call's
  delay slot. It then restores the record pointer and calls `kmem_free` at `0x1248` with `a1` 48 (0x30). It returns `kmem_free`'s
  result.
- `heart_intr_bit_alloc` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x164`, 168 bytes, read in full, established): ANDs the request
  in `a0` with the word `heart_ivec_free`. If nothing requested is free it returns -1 from `0x204` (the delay slot at `0x208` sets
  `v0`). Otherwise `a4` becomes the lowest requested free bit, `a3 & -a3`, formed at `0x170` to `0x17c`. An `lld`/`scd` pair at `0x184`
  to `0x190` clears that bit from the word. If the `lld` value no longer has the bit set, the branch at `0x1a0` reloads the word at
  `0x1a4` and starts again at `0x16c`. After a claim, two shift loops count the position of the single set bit of `a4` into `v0`: 8-bit
  steps from `0x1a8` to `0x1d0`, then 1-bit steps from `0x1d4` to `0x1f8`, so the result is the bit number of `a4`.
- `heart_error_handler` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x15fc`, 52 bytes, read in full, established): returns 0 when `a2`
  is zero (`v0` is set to 0 at `0x1600` and the `beq` at `0x160c` jumps to the return at `0x1628`). When `a2` is nonzero it loads the
  pointer at `gp-30712`, adds 160 in the call's delay slot, and calls `ioerror_dump` at `0x1618` with that address as `a0`. After the
  call it sets `v0` to 10 at `0x1624`, so the routine returns 10 on that path.
- `heart_rev` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x1978`, 40 bytes, read in full, established): returns the cached word
  `the_heart_rev` when it is zero or positive (the `bltz` at `0x197c` is not taken). When the cached word is negative it loads the
  pointer `0x9000000018000004` from the literal pool at `gp-30672`, reads the word at that address, shifts it right by 28, stores the
  result to `the_heart_rev` in the delay slot of the return at `0x1998`, and returns it. The word read is the widget identification
  word at widget offset 4.
- `heart_widget_num` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x83c`, 40 bytes, read in full, established): calls
  `xwidget_info_get` at `0x844` with its argument unchanged, passes the result as the argument of `xwidget_info_id_get` at `0x84c`
  (the move at `0x850` sets `a0` from `v0`), and returns that call's result masked to its low byte (`andi` at `0x858`).
- `clear_cpu_intr` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x4b0`, 24 bytes, read in full, established): builds `1 << (a0 + 46)` in
  `at` with `dsllv` and stores the doubleword to `0xffffffffaff10028`, the register at HEART offset `0x10028` (the register the table
  above calls CLR_ISR). It makes no calls and returns with `v0` holding `0xffffffffaff10000`.
- `heart_intr_swlevel_to_hwlevel` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x20c`, 84 bytes, read in full, established): when
  `a0` is negative it calls `cmn_err` at `0x24c` and returns -1. Otherwise it returns 2 when `a0` is at or above
  `swlevel_thread_hi`, 1 when `a0` is at or above `swlevel_thread_med` but below `swlevel_thread_hi`, and 0 when `a0` is below
  `swlevel_thread_med`.
- `heart_addr_xio_to_kva` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0xa28`, 56 bytes, read in full, established): calls
  `heart_addr_xio_to_phys` at `0xa30` with its argument unchanged. A zero result is returned as zero (the `beq` at `0xa40` jumps to
  `0xa58`). A nonzero result is ORed with `0x9000000000000000`, which the code builds as -7 shifted left by 60 (`dsll32` by 28 at
  `0xa48`), and returned.
- `heart_intr_cpu_get` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x13a4`, 28 bytes, read in full, established): loads the halfword at
  `a0 + 36`, scales it by 16, and adds it to the `pdaindr` array base (the pointer is at `gp-30688`). It loads the doubleword at element
  offset 8 and returns the word at offset 1764 of that pointer. It makes no calls.
- `heart_piomap_free` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0xb20`, 28 bytes, read in full, established): calls `kmem_free` at
  `0xb28` with `a0` unchanged and `a1` 40 (0x28), and returns its result.
- `heart_dmamap_free` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0xc10`, 28 bytes, read in full, established): calls `kmem_free` at
  `0xc18` with `a0` unchanged and `a1` 12 (0xc), and returns its result.

- `heart_intr_cpuid_get` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x13c0`, 8 bytes, read in full, established): returns the
  sign-extended halfword at `a0 + 36`, the field that `heart_intr_cpu_get` above reads as its processor index. It makes no calls.
- `heart_piomap_addr` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0xb3c`, 20 bytes, read in full, established): returns
  `a1 + [a0+24] - [a0+8]`. It loads the doublewords at `a0 + 24` and `a0 + 8`, adds `a1` to the first, subtracts the second and
  returns the difference in `v0`. It makes no calls.
- `heart_dmamap_addr` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0xc2c`, 32 bytes, read in full, established): sets `a0` from `a1`
  and `a1` from `a2` before its call, then calls `heart_addr_phys_to_xio` at `0xc38` with those two values. It returns that call's
  result in `v0`, and keeps `ra` in a 16-byte frame.
- `heart_init` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x5b0`, 44 bytes, read in full, established): calls
  `xwidget_driver_register` at `0x5c8` with `a0` 0xc001, `a1` 54 (0x36), `a3` 0, and `a2` set to the pointer in the small-data pool
  at `gp-30712` plus 96 (the `daddiu` in the call's delay slot at `0x5cc`). It returns that call's result.
- `heart_intr_disconnect` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x1334`, 112 bytes, read in full, established): reads the
  doubleword at `a0 + 24`, the byte at `a0 + 5` (the vector) and the halfword at `a0 + 36` (the processor). It calls
  `heart_imr_bits_rmw` at `0x135c` with the processor, `1 << vector` (the `dsllv` in the delay slot) and `a2` 0. It then writes the
  vector's table entry, which is `heart_ivec` (from the small-data pool) plus `vector << 6`: `heart_stray_intr` at offset 0 and the
  vector number at offset 8 (`0x1374` to `0x137c`). If the doubleword read from `a0 + 24` is nonzero it calls that pointer at `0x1394`
  with the original `a0`, and returns that call's result. Otherwise it returns `heart_imr_bits_rmw`'s result.

- `heart_provider_startup` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x13c8`, 8 bytes, read in full, established):
  the whole body is `jr ra` at `0x13c8` with a nop in its delay slot at `0x13cc`. Nothing is stored and no call is
  made, so the caller's `v0` is what it returns.
- `heart_provider_shutdown` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x13d0`, 28 bytes, read in full, established):
  opens a 16-byte frame and saves `ra` at `0(sp)` (`sd` at `0x13d4`). It calls `xtalk_provider_unregister` at `0x13d8`
  with `a0` unchanged from entry, restores `ra` at `0x13e0`, and returns the callee's result in `v0`. The frame is
  popped in the delay slot of the `jr` at `0x13e4`.
- `heart_error_devenable` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x179c`, 8 bytes, read in full, established):
  the `jr ra` at `0x179c` carries `or v0,zero,zero` in its delay slot at `0x17a0`, so the constant 0 is the return
  value. The routine makes no call.
- `heart_intrd` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x17a4`, 52 bytes, read in full, established): saves `ra`
  and `s8` in a 16-byte frame and keeps the record pointer in `s8`. It loads the doubleword at record offset 0 into
  `at` and calls through `at` at `0x17b8`, with `a0` set from the doubleword at record offset 8 by the call's delay
  slot. It then calls `ipsema` at `0x17c0` with `a0` set to record plus 32, and returns `ipsema`'s result.
- `heart_intrd_start` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x17d8`, 124 bytes, read in full, established):
  calls `setmustrun` at `0x17e8` with `a0` set from the halfword at record offset 16. It calls `xthread_set_func` at
  `0x17f8` with `a1` set to `heart_intrd` (the pointer at `gp-30680`) and `a2` set to the record. It calls
  `fetch_kname` at `0x1804` with the doubleword at record offset 0 as `a0` and the bottom of its frame as `a1`.
  `strncpy` at `0x1818` copies 16 bytes from the `fetch_kname` result to the pointer at `0xffffffffffffc020` plus 832.
  An `ll`/`sc` pair at `0x1828` and `0x1830` ORs 0x400 into the word at record offset 24. The branch-likely `beql` at
  `0x1834` repeats that pair only when `sc` fails. The routine ends with `ipsema` at `0x183c` on record plus 32 and
  returns its result.
- `heart_intr_prealloc` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0xfcc`, 92 bytes, read in full, established):
  saves the entry `a2`, `a3` and `a4` in a 48-byte frame, keeps the entry `a1` in `s8`, and calls
  `heart_intr_bits_take` at `0xfec` with `1` shifted left by the entry `a1` (the `dsllv` in the delay slot). It then
  calls through `a5`, which holds the entry `a2`, at `0x1010`. That call gets `a0` from the entry `a3`, `a1` from the
  entry `a4`, `a2` as the low four bits of the doubleword at `0xffffffffaff00080`, `a3` 128, and `a4` from the entry
  `a1`. The routine returns the indirect call's result.
- `heart_mp_intr_init` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x56c`, 68 bytes, read in full, established): a
  leaf routine with no frame and no call. From the entry `a0` it forms three single bits, at `a0+42`, `a0+46` and
  `a0+59` (each `dsllv` uses the shift count modulo 64), and ORs in bit 63 (`dsll32` by 31 of -1). The doubleword it
  stores is the OR of those four bits. The store goes to `0xffffffffaff10000` plus `8 * a0` (`dsll` by 3 at `0x578`,
  `daddu` at `0x5a0`), in the delay slot of the `jr ra` at `0x5a8`.
- `heart_cpu_intr` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x3fc`, 56 bytes, read in full, established): loads the
  halfword at `0xffffffffffffc3a0`, adds 46, and shifts `1` left by that value. The `sd` in the delay slot of `jal
  doacvec` at `0x418` writes the result to `0xffffffffaff10028`, the offset-0x10028 register that `clear_cpu_intr`
  also writes. It then calls `doactions` at `0x420` and returns its result.
- `heart_debug_intr` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x434`, 56 bytes, read in full, established): the
  same halfword at `0xffffffffffffc3a0`, now plus 42, forms the bit `1 << (value+42)`. That bit is stored to
  `0xffffffffaff10028` in the delay slot of `jal debug` at `0x458`. The call's `a0` is the `.rodata` pointer from
  `gp-30712` plus 88, and the routine returns `debug`'s result.
- `chkdebug` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x46c`, 68 bytes, read in full, established): ANDs the bit `1
  << (halfword at 0xffffffffffffc3a0 + 42)` with the doubleword at `0xffffffffaff10030`. If the result is zero the
  `beq` at `0x48c` returns with `v0` unchanged. Otherwise the bit is stored to `0xffffffffaff10028` at `0x498`, and
  `debug` is called at `0x49c` with the `.rodata` pointer plus 88. The routine returns `debug`'s result.
- `heart_stray_intr` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x3b4`, 72 bytes, read in full, established): keeps
  the entry `a0` in `s8`, calls `heart_imr_bits_rmw` at `0x3d0` with `a0` the halfword at `0xffffffffffffc3a0`, `a1`
  equal to `1` shifted left by the entry `a0` (the `dsllv` in the delay slot), and `a2` 0. It then calls `cmn_err` at
  `0x3e4` with `a0` 6, `a1` the `.rodata` pointer from `gp-30712` plus 48, and `a2` the low word of the entry `a0`. It
  returns `cmn_err`'s result.
- `heart_ithread_setup` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x1854`, 108 bytes, read in full, established):
  takes the 64-byte record at `heart_ivec` plus `a1 << 6` (the pointer at `gp-30720` plus `v1` in `v0`). `s8` is set
  to the entry `a2` unless bit 0 of the word at record offset 24 is set. In that case `s8` keeps the word loaded from
  `gp+0`. `sprintf` is called at `0x1890` to format the entry `a1` into the bottom of the frame with the `.rodata`
  pointer plus 168 as its format. `xthread_setup` is called at `0x18a8` with the buffer, `s8`, record plus 24, and
  `heart_intrd_start` (the pointer at `gp-30672`) as `a3`. It returns that call's result.
- `heart_flow_control_enable` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x1a8c`, 60 bytes, read in full,
  established): forms `s8 = 1 << ((entry a0 + 1) & 31)` with `sllv`. It calls `heart_imr_bits_rmw` at `0x1aac` with
  `a0` the halfword at `0xffffffffffffc3a0`, `a1` the bit, and `a2` the bit. It returns the bit ANDed with the
  callee's result.
- `heart_flow_control_disable` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x1ac8`, 60 bytes, read in full,
  established): the same bit, `1 << ((entry a0 + 1) & 31)`, and the same halfword at `0xffffffffffffc3a0` as
  `heart_flow_control_enable`. The call at `0x1ae8` passes `a2` 0, so the bit is passed as `a1` only. The result is
  the bit ANDed with `heart_imr_bits_rmw`'s return value.
- `heart_flow_control_disconnect` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x1a24`, 104 bytes, read in full,
  established): builds the same bit from `(entry a0 + 1) & 31` in `s0`. It calls `heart_imr_bits_rmw` four times, at
  `0x1a44`, `0x1a54`, `0x1a64` and `0x1a74`, with `a0` 0, 1, 2 and 3 in turn, `a1` the bit and `a2` 0. It returns the
  fourth call's result.
- `heart_flow_control_connect` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0x19a0`, 132 bytes, read in full,
  established): calls `heart_intr_preconn` at `0x19c0` with `a0` 0, `a1` equal to `(entry a0 + 1) & 255`, `a2` the
  entry `a1`, and `a3` the entry `a0`. It then calls `heart_imr_bits_rmw` at `0x19d8`, `0x19ec`, `0x19fc` and `0x1a0c`
  with `a0` 0, 1, 2 and 3, `a1` the bit `1 << ((entry a0 + 1) & 31)` and `a2` 0. It returns the last call's result.
- `heart_intr_preconn` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0xf64`, 104 bytes, read in full, established):
  saves the entry `a2` and `a3` in its 48-byte frame and calls `heart_intr_bits_take` at `0xf84` with `1 << a1`. It
  stores the entry `a2` at offset 0 and the entry `a3` at offset 8 of the `heart_ivec` record for `a1` (`heart_ivec`
  plus `a1 << 6`), the first in the delay slot of `jal getcpuid` at `0xfa4`. Then it calls `heart_imr_bits_rmw` at
  `0xfb8` with `a0` the value `getcpuid` returned, `a1` 0, and `a2` the bit saved at `16(sp)`, and returns that
  result.
- `heart_piotrans_addr` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0xb58`, 92 bytes, read in full, established):
  calls `heart_widget_num` at `0xb6c` with `a0` unchanged, then `heart_addr_xio_to_kva` at `0xb7c` with `a0` the
  widget number, `a1` the entry `a2` and `a2` the entry `a3`. If the entry `a4` has bit 3 set (the `andi` 8 at
  `0xb88`), the result is ORed with `0x3800000000000000` (`7` shifted left by 59). Otherwise the result is returned as
  the callee gave it.
- `heart_dmamap_alloc` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0xbb4`, 92 bytes, read in full, established): calls
  `kmem_zalloc` at `0xbd0` with a size of 12 and `a1` set to 1 when bit 1 of the entry `a3` is set, else 0. If the
  allocation returns zero the routine returns zero. Otherwise it stores the entry `a0` at offset 0 of the block, calls
  `heart_widget_num` at `0xbf8`, stores the low byte of that result at offset 4 (the `sb` at `0xc00`), stores the
  entry `a3` word at offset 8, and returns the block.
- `heart_dmatrans_addr` (`IP30/usr/cpu/sysgen/IP30boot/heart.o` at `0xdc0`, 32 bytes, read in full, established):
  moves the entry `a2` into `a0` and the entry `a3` into `a1`, then calls `heart_addr_phys_to_xio` at `0xdcc` with
  those two values. It returns the callee's result.

## Open

Graded entries. "Established" lines are read from the files above; "inferred" lines say what they rest on. Each
entry ends with the route that would settle it. Collected in [docs/open-questions.md](../../docs/open-questions.md).

- **BAD_SYSWR_ERR (CAUSE bit 41): what sets it, what a failed or timed-out uncached store latches.**
  Established: bit 41 is `BadSysWrErr` in the kernel and `SYSAD_WR_ERR` in the monitor; enable bit is MODE bit 10
  (`BAD_SYSWR_ERE`). When set, the kernel reads BERR_ADDR (physical address, bits 39:0) and BERR_MISC (processor
  in bits 22:21) and flags the record as a write error. The kernel's own write probe (`wbadaddr`) never tests this
  bit: it expects a refused store to show up as IP6 pending or CAUSE bit 16. Inferred: "SYSAD" names the
  processor system bus, so the bit is raised by a store HEART refuses on that bus (a hole in the physical map,
  `heart_paddr_to_port` returning 0xff); no held code shows a store reaching it. Unknown: the exact condition, whether
  a store to an XIO widget that times out also sets it, whether BERR_ADDR is valid for every setting. Next: read the
  diagnostic's PIU access test (stripped; the strings "Heart PIU Access" and "Heart PIO Access" locate its menu entry)
  and the PROM error dump at `0xffffffffbfc16680` in full.
- **BAD_SYSRD_ERR (bit 40).** Established: `BadSysRdErr` / `SYSAD_RD_ERR`; enable MODE bit 9; same latches and
  decode as bit 41, flagged read. Reads of unanswered addresses take the data bus error exception (`VEC_dbe`
  masks the error vectors first). Unknown: as for bit 41. Same route.
- **PIUR_ACC_ERR (bit 42).** Established: named `PIUR_AccessErr` / `PIU_REG_ACC_ERR`; PIU_ERR holds the
  processor (bits 21:20) and the register offset (bits 19:3); the kernel treats it for its own processor as fatal
  and compares the offset with the decoded faulting address, so the trigger is an access whose address is in the
  PIU block. Established by a public source, not by the shipped files: the Linux header says a write to the
  undefined register at offset 0x1000 triggers it. No held code touches offset 0x1000. Unknown: which other
  accesses (reads, short widths, unaligned, other holes) raise it. Next: the diagnostic's PIU access test.
- **WIDGET_ERR (bit 16) and the widget error type.** Established: bit 16 is set when HEART's widget block holds an
  error; the type is in WID_ERR_TYPE: bit 2 `PIO_WR_TIMEOUT`, bit 3 `PIO_RD_TIMEOUT`, bit 1 `PIO_XTLK_ACC_ERR`, bit
  0 `PIO_WCR_ACC_ERR` (names and positions from the monitor table, decode paths from the kernel). A failed or
  timed-out processor store latches WID_PIO_ERR_UPPER/LOWER (address 39:0, processor 23:22 of UPPER, bit 15 a flag
  whose sense is not read); a read timeout latches WID_PIO_RTO_ADDR (processor, widget port, address 23:12).
  WID_REQ_TIMEOUT is set to 40000 by the kernel. The kernel write probe expects the result, for a store to an
  unanswered widget address, by the end of one flush read pair. WID_ERR_MASK is written `0x3ff62c07`: bits 2:0 on,
  bit 3 off (read timeouts are reported through the bus error exception instead, inferred). Unknown: the unit of the
  timeout, which of bits 0, 1, 2 an unanswered store produces, whether CAUSE bit 16 or bits 40 to 42 is set for an
  address in no widget window, what clears each bit (the kernel stores the read value back; write-one-to-clear is
  inferred). Next: the PROM dump routine and the diagnostic's widget error wait routine (`_hb_wait_for_widgeterr`
  string).
- **Level 4 vectors 51 to 63: which fires for what.** Established: widget error vectors are 51 + ((widget + 7) & 7)
  (`do_heart_intr_alloc`): widgets 9 to 15 give 51 to 57, widget 0 gives 58 (monitor names XBOW at 58, BASEIO at
  57, WID9 to WIDE at 51 to 56). Vectors 59 to 62 are per-processor bus error (BERR0 to 3), 63 is HEART_EXC; the
  kernel arms 59+n and 63 for each processor at reset and masks both on a data bus error. Vectors at or above 59
  go to `buserror_intr`; vectors below 59 go to the handler connected for them. Inferred: widget errors from a
  crossbar widget reach HEART as an interrupt packet to the vector the widget was configured with; HEART's own
  widget (8) has no vector of its own and shares 58. Unknown: which CAUSE bits assert 59 to 62 and which assert
  63, and whether bit 16 asserts a widget vector or HEART_EXC. Next: the PROM error dump and the diagnostic's
  interrupt-register tests ("Heart Interrupt Registers").
- **Registers no held code reaches.** SDRAM_MODE, MEM_REF, FC0_TIMER, FC1_TIMER, MLAN_CLK_DIV, MLAN_CTL, COMPARE,
  WID_STAT, WID_CONTROL, WID_LLP, WID_TARG_FLUSH: only the diagnostic's table names them. TRIGGER (two PROM
  stores) and SYNC (one kernel read) are reached but their roles are not read. Unknown: roles and reset values.
  Valid end state unless a held PROM or diagnostic routine that sets them is found.
- **Small-data pointers.** The census follows loads of the widget-block pointers the kernel keeps in its small-data
  area only where the word holds an address inside a configured window; a pointer held in a register across a call
  is not followed. A widget-block access through such a pointer in a routine not listed above would be missed.
