# HEART error, timer and reset routines of the IP30 kernel

Read from `IP30/unix` (the linked IRIX 6.5 kernel for the Octane; addresses are virtual addresses). The HEART register
offsets below are the ones the [HEART page](../chips/heart/README.md) lists; the kernel reaches the chip through the uncached
window at 0xffffffffaff00000 (so MODE is 0xffffffffaff00000, CAUSE 0xffffffffaff10040) and the widget slot of HEART itself at
0x9000000018000000. A bare number such as `-15456` addresses the process page below zero: the halfword there is the number of
the processor running the code.

- `dobuserr_common` (`IP30/unix` `0xa800000020023f74`, 9460 bytes, frame 880 bytes) is the common bus-error handler
  that the kernel's `dobuserr` entry calls. The first argument is the exception frame, which is also passed to
  `heart_intr` while the lock is awaited; the second is a pointer stored in the report record when nonzero; the third
  is a mode of 0, 1 or 2, handed on to
  `heart_error_refine` as 1, 0 or
  2; the fourth is a flag. A nonzero flag with a frame switches on the address decode and the final interrupt-mask
  update, and in mode 0 makes the routine release the lock and return 0 after a handled error; with a zero flag a
  handled error in mode 0 ends in `cmn_err_tag` (0x44, 0, "Bus Error"). It calls `heart_paddr_to_port` and
  `heart_error_refine` to classify the error, `heart_imr_bits_rmw` to re-arm the interrupt mask, `log_dimmerr` for
  memory errors, `is_in_main_memory`, `ldst_addr`, `compare_and_swap_int`,
  `heart_intr`, `us_delay` and `__dcache_wb_inval`, and prints its report with
  `cmn_err` (level 6 in all but two call sites, which use level 4). It returns 0 whenever the mode is 1, and for the
  other modes 1 when it handled no error and 0 when it did. It begins by taking a lock word at 0xa8000000204a68e0:
  each processor owns one bit of it, bit 1 << cpu to hold it or bit 0x100 << cpu when it already held it (a nested
  entry), and while another bit is set it spins, calling `heart_intr` when its own interrupt bit (46 plus cpu) is set
  in the status register at +0x10030 and `us_delay` (5) otherwise. It then snapshots fourteen registers into a
  per-processor table at 0xa8000000204b0d30, 16 bytes per register, in this order: MODE (+0x0), CAUSE (+0x10040),
  PIU_ERR (+0xa8), BERR_MISC (+0x90), BERR_ADDR (+0x88), then the HEART widget's own registers at +0x60, +0x44, +0x14,
  +0x1c, +0x90, +0x70 and +0x78, and last MEM_ERR (+0x98) and BAD_MEM (+0xa0). It then decodes the faulting address
  when a frame is given. The frame's flags doubleword at +0x118 is masked with 0x7c: value 0x18 takes the address from
  frame +0x120 (plus 4 when bit 31 of the flags is set), and value 0x1c calls `ldst_addr`; the result is converted to
  a physical address by masking (0x1fffffff for kseg0 and kseg1 addresses, 0xffffffffff for the 64-bit uncached range,
  and a call to an unnamed helper at 0xa800000020026468 otherwise) and handed to `heart_paddr_to_port`. Causes are
  then tested and cleared one at a time, each in a block that builds a report record and calls `heart_error_refine`:
  bus error bits 41 and 40 of CAUSE with the bus-error address, widget error bits 0x4f00000 of the widget error type
  word (command word path), bit 3 of it (PIO read timeout, with a check of the port and the address bits 23:12 against
  the decoded fault), bits 2:0 (PIO error), the memory error bits 1:0 (the correctable case rewrites the failing
  doubleword with bit 20 of the register at +0x18 set, using `__dcache_wb_inval`, and calls `log_dimmerr`), the PIU
  access bit 42 and the counter bits that only increment the words at 0xa8000000204a68e4 to 0xa8000000204a6908. Any
  path that `heart_error_refine` answers with 9, and each fatal case, ends in `cmn_err` and does not return. At the
  end it clears CAUSE bits it handled, writes the handled widget error bits back to the widget error type slot and
  zeroes the command word slot at +0x44 when bits 0x4f00000 were handled, calls `heart_imr_bits_rmw` for this
  processor when the flag argument is nonzero, writes 1 << (cpu + 0x3b) to +0x10020 when CAUSE is still nonzero, and
  releases the lock bits. The branch at 0xa800000020025d68 compares a nonzero string address with zero and is never
  taken, and the two words at 0xa800000020025de4 are unreachable. Inferred: the decode and the order of the blocks
  were read from decompiler output and the full fact sheet, with the stores, callees and string arguments checked in
  the disassembly, and the long report-printing tail was not read word for word.
- `ecc_handler` (`IP30/unix` `0xa800000020027fd4`, 1776 bytes, frame 128 bytes) is the cache-error handler. Its first
  argument is the exception frame, its second the per-processor cache-error record; it returns a pointer to a message
  when the error cannot be recovered and 0 when it was repaired. It reads the cache error register image, the unsigned
  word at record +0x18, and when bit 29 is set it formats the register with `cer_to_hex` into the text "CER=" plus a
  fixed message about multiple errors in one unit and returns that string at once. Otherwise it logs the register word
  at record +0x38 plus 32 * n and the doubleword at record +0x0 at +0x50 plus 32 * n (n is the word at +0x238,
  advanced modulo 16; the log is skipped when it would catch up with the word at +0x23c). It clears the doublewords at
  +0x8 and +0x10 and branches on the two top bits (31 and 30) of the register word. Neither bit set is a primary
  instruction cache error: it adds 1 to the word at +0x28, and for each of the two ways whose error bits are set
  (masks 0x5500000 and 0xaa00000) reads the tag with the routine at 0xa8000000200279b8, then runs that routine again
  with code 0 on the index and the index XOR 1 and calls `ecc_force_cache_line_invalid` for both ways, returning 0.
  Bit 30 only is a primary data cache error: it counts at +0x2c, and returns "unrecoverable dcache error, neither way"
  when neither way is flagged, otherwise reads each flagged way's tag (cache operation code 5) into record +0x8 or
  +0x10 and returns one of the "unrecoverable - dcache tag mod", "dcache tag" or "dcache data" messages for the
  combinations of mask 0x300000, 0x3c00000 and 0xc000000 with the state bits it reads, and "unrecoverable - dcache tag
  on inconsistent block" when bit 28 of the register is set; otherwise it repairs each flagged way with code 1 and
  returns 0. Bit 31 only returns "unrecoverable secondary cache error" after adding 1 to +0x30. Both bits set is a
  system interface error: it counts at +0x34, tests masks 0x12000000 and 0x3800000, compares the register at +0x98
  (MEM_ERR) when the register at +0x10040 has bit 1 set, and in the uncorrectable multi-bit case formats
  "unrecoverable SIE caused by multi bit ECC error at physaddr 0x%x, DIMM %s" with `sprintf` and `maddr_to_dimm`; for
  the other cases it reads secondary-cache tags with code 7, repairs lines that are not dirty with code 3 and
  `ecc_force_cache_line_invalid`, and returns "unrecoverable SIE - dirty scache" for a dirty one. Every other
  combination returns "unrecoverable - unknown cache error". On every exit it sets the byte at -14624 to 1. When the
  message is not null and the byte at record +0x26 is not yet 2 it sets that byte to 2 and copies 45 doublewords of
  the first argument, from +0x0 upward, to +0x3b8 upward. It always ends by running cache operation code 0x13 on 32
  lines of the record, at 128-byte steps from the record. Inferred: the branch structure and strings come from
  decompiler output checked against the fact sheet and the dumped strings; the tag state fields it compares are named
  only by their masks here.
- `counter_intr` (`IP30/unix` `0xa800000020014370`, 1724 bytes, frame 48 bytes) is the handler for the processor's
  count/compare timer interrupt. It first tests a word at -14760: when nonzero it only logs the event
  (`log_tstamp_event` with 0x6c, then 0x65 with 0x6c, when the flag bit 5 of the doubleword at -15744 is set), calls
  `frs_handle_counter_intr` and returns. Otherwise it calls `hwperf_overflowed_intr`, and when that returns nonzero
  calls `hwperf_intr` and returns. A word at -16312 with bit 6 set calls `resetcounter` with -1 and jumps to the
  common tail. Otherwise it reads the free-running counter at 0xffffffffaff20000 (HEART COUNT), compares it with the
  next-tick doubleword at -15016 and with a second deadline at -15032, which it advances in steps of 0x1e848 (125000)
  counts, counting missed ticks in the words at -15008, -15004, -15000 and -14996; it calls `resetlatency` and
  `resetcounter` to re-arm the compare register, with a delay worked out from `cpufreq_cycles` and `count_min_delta`
  and a divide-by-zero trap for each. It measures the gap since the last interrupt (doubleword at -14992) against
  `counter_intr_warn_cycles`, or `counter_intr_warn_period` times 6250000 when that is between 1 and
  255, and when the gap is long and `lbolt` and a per-processor flag allow it prints "CPU %d hasn't seen a scheduler
  clock interrupt in %d seconds, EPC 0x%x, RA: 0x%x" with `cmn_err` at level 0 when `counter_intr_panic` is set and
  level 4 otherwise, followed by a hint string chosen by whether the elapsed seconds are within 2 of the expected
  figure. The tail clears a per-processor flag word and calls two unnamed routines at 0xa80000002001679c and
  0xa8000000200152c8, and logs the 0x65 end event. Inferred: this entry follows decompiler output, with callees and
  the absolute-address words taken from the fact sheet.
- `mlreset` (`IP30/unix` `0xa800000020012450`, 864 bytes, frame 32 bytes) is the machine-level reset hook the kernel
  calls once per processor. With a nonzero argument (a secondary processor) it clears the four performance counter
  control and data registers (`r1nkperf_control_register_set` and `r1nkperf_data_register_set` with index 0 and
  1, and also 2 and 3 when `get_cpu_irr` shifted right 8 is 14 or
  15), calls `getcpuid` and `heart_mp_intr_init`, then `flush_tlb` (1) and `flush_cache`, and returns. With zero it
  does the same counter clearing first and then the boot-processor work. It sets `kdebug` to 0 if it is -1 and
  `master_procid` to the processor number, marks processors 0 and 1 enabled in
  `processor_enabled` when MODE bit 60 plus the index is clear and bit 4 plus the index of the register at +0x80 is
  set, calls three unnamed setup routines at 0xa8000000200131d0, 0xa800000020013560 and 0xa80000002001234c,
  `load_nvram_tab`, and sets `reboot_on_panic` to 0 if it is -1. It clears bits 12 and 14 of `valid_icache_reasons`
  and `valid_dcache_reasons` (mask 0xffffafff), sets `softpowerup_ok` to 1 and `cachewrback` to 0, and sets
  `cachecolormask` to the signed `pdcache_size` divided by 0x8000 minus 1, or 0 when that quotient is below 1. It then
  decides the HEART invalidate workaround: the `heart_invalidate_war` boot argument when present (`is_specified`,
  `atoi`), otherwise 1 when, for an enabled processor, the word at 0xa800000000000604 plus 0x80 per processor index is
  below 0x927 or equal to 0x930. With the workaround off it clears with `blkclr` the byte ranges from `ovbcopy` to
  `bcopy_nopage` and from `blkclr` to `bzero_nopage`; with it on it stores 0 in the three words
  `bcopy_pref1`, `bcopy_pref2` and `bzero_pref`. It calls `flush_cache`, `spinlock_init` for
  "ip30clock" and "ip30led", sets `maxcpus` to the highest enabled processor index plus 1, and sets
  `is_octane_lx` to 1 when the word at 0x900000001f600048 is zero, in which case it stores 0x100000 to the word at
  0x900000001f600038 and 0x7001a to the word at 0x900000001f60002c. Last it sets `_prom_cleared` to 1. Inferred: from
  decompiler output checked against the fact sheet's callees, literal-pool words and absolute addresses.
- `heart_startup` (`IP30/unix` `0xa80000002003ee44`, 488 bytes, frame 96 bytes) builds the HEART part of the hardware
  graph and registers every crosstalk widget that answers; it returns nothing and takes the parent vertex in a0. It
  first stores 40000 (0x9c40) to the word at 0x900000001800002c, the widget request timeout, or 0x80 when the halfword
  `kdebug` is nonzero, and loads the doubleword at 0xffffffffaff00080, of which the low four bits (the widget number
  HEART answers to) are kept in s5. It then adds the vertices "node" under the argument, registers `heart_provider` on
  it with `xtalk_provider_register` and `xtalk_provider_startup`, adds "xtalk" under it, sets its switch id to 0 with
  `xswitch_id_set`, adds "0" under that and keeps the vertex in `the_error_vhdl`, adds the edge "io" from the node
  vertex to the xtalk vertex with `hwgraph_edge_add` and makes the node the master of "0" with `device_master_set`.
  For widget 0 it reads the identification word at 0x9000000010000004 and calls `xwidget_register` with part (bits
  27:12), manufacturer (bits 11:1), the "0" vertex, widget number 0, the node vertex and s5. It then walks widgets 15
  down to 0 over the switch information from `xswitch_info_get` (nothing is done when that is zero): each widget that
  `xswitch_info_link_ok` accepts gets a vertex named with `sprintf` "%d", recorded with `xswitch_info_vhdl_set`, and
  is registered from the identification word at 0x9000000010000004 plus the widget number shifted left 24 in the same
  way. Established.
- `badaddr_val` (`IP30/unix` `0xa80000002001c328`, 364 bytes, frame 16 bytes)
  reads one value from an address that may not answer and reports whether the bus complained. `a0` is the address to
  read, `a1` the width (1, 2,
  4 or 8) and `a2` the address where the value read is stored with the same width. It saves Status and writes 0xa0 to
  it. It then clears the error state by: reading the doubleword at 0xffffffffb8000000+0x60, storing 0 to the
  doubleword at +0x40, reading the doubleword at +0x0, and writing the first value back to +0x60; reading the
  doubleword at 0xffffffffaff10040 and writing it back; and reading the doubleword at 0xffffffffaff50000. It marks the
  thread no-fault: when the doubleword at -16352 of the process page is nonzero it stores 1 as the halfword at +246 of
  that record, otherwise it stores 1 as the word at -15356 of the process page. Then it switches on `a1`: `lb`/`sb`,
  `lh`/`sh`,
  `lw`/`sw` or
  `ld`/`sd` from `a0` to
  `a2`. Any other width calls `cmn_err` with 0 and the string "baddaddr_val" and then carries on with no access.
  Afterwards it reads the doubleword at 0xffffffffaff50000 and at 0xffffffffb8000000, executes `sync`, and tests two
  failure conditions. Coprocessor 0 Cause bit 14 (0x4000) set, or bit 16 of the doubleword at 0xffffffffaff10040,
  branches to the separate 92-byte routine at `0xa80000002001c908` (symbol `baerror`), which repeats the clear sequence,
  restores Status, removes the no-fault mark and leaves 1 in v0 for the caller. With neither set it removes the mark in the same way (the halfword
  at +246, or the word at -15356 when the record pointer is 0), restores Status and returns 0. Established.
- `heart_intr` (`IP30/unix` `0xa80000002003fe98`, 364 bytes, frame 80 bytes)
  is the HEART interrupt dispatcher: it runs the handler of each pending, enabled vector until none is left. The first
  argument (`a0`) is the exception frame, kept in s8 and handed only to `buserror_intr`; the second
  (`a1`) is the mask of vectors the caller will service. It reads the doubleword at 0xffffffffaff10038 (the interrupt
  mask-status register the HEART page calls IMSR), ANDs it with `a1`, and stops when the result is 0. Each pass calls
  `ffintr64` for the highest set bit of that value (the vector number). A vector of 59 or more goes to `buserror_intr`
  with the frame and writes nothing to the acknowledge register. Below 59 the vector indexes the table `heart_ivec` at
  64 bytes per vector: for vectors 3 and above it stores 1 shifted left by the vector as a doubleword to
  0xffffffffaff10028 (the clear register) before the handler, and for vectors 0 to 2 after it. The test that picks the
  handler is the word at record +24 ANDed with 0x1000. When that bit is clear the handler is the doubleword at
  record +0, called through `jalr` at `0xa80000002003ff98` with the doubleword at record +8 as its only argument. When
  it is set the record holds a semaphore at record +32: `valusema` is called and, if its result is below 28673,
  `vsema` signals it, while from 28673 up `cvsema` is called instead; no handler address is used. After each vector
  the mask-status register is read again and ANDed with `a1`; a nonzero result loops. On exit it adds the number of
  vectors it dispatched, minus one, to the word at +208 of the structure that the doubleword at -15224 of the process
  page points to, by an `ll`/`sc` loop whose `beql` at `0xa80000002003ffec` is the only branch-likely in the routine;
  when nothing was pending that adds -1. It has no deliberate return value; v0 is 0 on exit, left by the final AND. Established.
- `wbadaddr_val` (`IP30/unix` `0xa80000002001c5e0`, 360 bytes, frame 16 bytes)
  is the store-side twin of `badaddr_val`: it copies one value to an address that may not answer and reports a bus
  complaint. `a0` is the address written, `a1` the width (1,
  2, 4 or 8) and
  `a2` the address the value is read from, so the roles of `a0` and `a2` are the reverse of `badaddr_val`. It saves
  Status, writes 0xa0 to it and runs the same clear sequence on 0xffffffffb8000000 (+0x60 read, +0x40 zeroed, +0x0
  read, +0x60 written back), 0xffffffffaff10040 (read and written back) and 0xffffffffaff50000 (read). It then stores
  1 as the halfword at +246 of the record at -16352 of the process page without testing the pointer. A width other
  than 1, 2, 4 or
  8 calls `cmn_err` with 0 and the string "wbaddaddr_val" and goes on. After the access it reads 0xffffffffaff50000
  and 0xffffffffb8000000 and executes `sync`, and does that pair again, then loads the word at 0x9000000000000000, and
  tests Cause bit 14 and bit 16 of the doubleword at 0xffffffffaff10040 the way `badaddr_val` does. Failure branches to
  that same routine, so the caller sees 1 in v0; success clears the halfword at +246 (again without a pointer test), restores Status and
  returns 0. Established.
- `badaddr` (`IP30/unix` `0xa80000002001c200`, 296 bytes, frame 16 bytes)
  is `badaddr_val` without the copy-out: it probes whether a read of `a0` at width `a1` (1, 2, 4 or 8) is answered and
  discards the value (the load lands in v0, which the epilogue overwrites). It saves Status in t0, writes 0xa0 to it,
  and runs the same clear sequence as `badaddr_val` on 0xffffffffb8000000 (read +0x60, store 0 to +0x40, read +0x0,
  write +0x60 back), 0xffffffffaff10040 (read, write back) and 0xffffffffaff50000 (read). It then stores 1 as the halfword
  at +246 of the record at -16352 of the process page with no test of the pointer. The width switch is `lb`, `lh`, `lw`
  or `ld` (compared in that order with 1, 2, 4, 8); anything else calls `cmn_err` with 0 and the string "baddaddr" and
  carries on. It then reads 0xffffffffaff50000 and 0xffffffffb8000000, executes `sync`, and sends Cause bit 14 set, or
  bit 16 of the doubleword at 0xffffffffaff10040 set, to `baerror` at `0xa80000002001c908`, which returns 1. With neither
  set it clears that halfword (again without a pointer test), restores Status and returns 0. Established.
- `wbadaddr` (`IP30/unix` `0xa80000002001c494`, 332 bytes, frame 16 bytes)
  probes a write: it stores zero at `a0` with the width in `a1` (`sb`, `sh`, `sw` or `sd` of the zero register, compared
  with 1, 2, 4, 8 in that order) and reports whether the bus complained. There is no value argument. The prologue is
  the one of `wbadaddr_val`: Status saved and set to 0xa0, the three-register clear sequence, and 1 stored as the halfword
  at +246 of the record at -16352 of the process page. Any other width calls `cmn_err` with 0 and the string
  "wbaddaddr" and goes on. After the store it reads 0xffffffffaff50000 and 0xffffffffb8000000, executes `sync`, repeats
  that pair and `sync`, then reads the word at 0x9000000000000000 into t2, and tests Cause bit 14 and bit 16 of the
  doubleword at 0xffffffffaff10040. Failure branches to `baerror`, which leaves 1 in v0 for the caller; success clears the halfword at
  +246, restores Status and returns 0. Established.
- `earlybadaddr` (`IP30/unix` `0xa80000002001c748`, 312 bytes, frame 16 bytes)
  is the read probe for use before the per-thread record exists: instead of the halfword at +246 it stores the word 9
  into the global `nofault` (address 0xa8000000204af10c). Only widths 1, 2 and 4 are handled (`lb`, `lh`, `lw` into v0,
  value discarded); width 8 and anything else calls `cmn_err` with 0 and the string "earlybaddaddr" and goes on. The
  entry sequence is Status saved in t0 and set to 0xa0, then the clear sequence on 0xffffffffb8000000,
  0xffffffffaff10040 and 0xffffffffaff50000 used by `badaddr`. After the access it reads 0xffffffffaff50000 and
  0xffffffffb8000000, executes `sync` and tests Cause bit 14 and bit 16 of the doubleword at 0xffffffffaff10040. Failure
  branches to `earlybaerror` at `0xa80000002001c964`, which repeats the clear sequence, restores Status, stores 0 to
  `nofault` and leaves 1 in v0; success stores 0 to `nofault`, restores Status and returns 0. Established.
- `wbadmemaddr` (`IP30/unix` `0xa80000002001c880`, 136 bytes, frame 16 bytes)
  tests whether memory at `a0` accepts a word write and a read, a lighter probe than the others. It saves Status in t0,
  writes 0xa0 to it, stores the word 9 into the global `nofault` (0xa8000000204af10c), stores a zero word to `a0` and
  loads the word back into v0. It does none of the clearing the other probes do, makes no width choice, and tests only
  bit 16 of the doubleword at 0xffffffffaff10040; Cause bit 14 is not looked at. A set bit branches to `baerror`
  (`0xa80000002001c908`), which leaves 1 in v0 and clears the thread's no-fault mark, not `nofault`, so the 9 stays in the
  global on that path. Otherwise it stores a zero word to `nofault`, restores Status and returns 0 from the delay slot.
  Established.
- `_ecc_end` (`IP30/unix` `0xa80000002001dd98`, 292 bytes, no frame) is a symbol that follows the ECC exception vector
  and, by its size, covers four routines that have no symbols of their own. The first, at the symbol address, takes the
  bank number in `a0` and returns the word at 0xffffffffaff00020 plus 4 times the bank, which is a HEART MEMCFG word. The
  second (`sub_a80000002001ddb0`) calls the first and returns its low nine bits shifted left by 25, the bank's base
  address in 32 MB units. The third (`sub_a80000002001ddd4`) calls the first and returns 0 when bit 31 of the word
  is clear and otherwise bits 21:16 plus 1 shifted left by 25 (a 32-bit `sll`), the bank size. The fourth
  (`sub_a80000002001de18`) maps the address in `a0` to a bank number: an address of 0x20000000 or more has 0x20000000
  taken off (a 64-bit add of 0xffffffffe0000000), then banks 0 to 3 are tried in turn, skipping banks of size 0, and the first bank
  whose base is at or below the address and whose base plus size (the size taken as an unsigned 32-bit value) is above
  it is returned; -1 comes back when none matches. Nothing is stored except stack saves. Established.
- `heart_imr_bits_rmw` (`IP30/unix` `0xa80000002003e868`, 288 bytes, frame 64 bytes)
  changes bits of one HEART interrupt mask register and returns the value it held before. `a0` (masked with 3) picks the
  register, at 0xffffffffaff10000 plus 8 times the index, `a1` is the mask of bits to clear and `a2` the bits to set;
  the new value is `a2` ORed with the old value ANDed with the complement of `a1`. Updates are serialised by a
  per-register owner word in a table of doublewords at 0xa80000002043e018 (the pool word at 0xa80000002043cfd8 plus 4160),
  8 bytes per register, holding -1 when free. The routine reads the processor number (halfword at -15456). When the owner
  word already equals that number it skips locking and does the read-modify-write directly, leaving the word as
  it was. Otherwise it calls `spl7`, then `compare_and_swap_int64` (word, -1, processor); when that fails it calls
  `splx` with the saved level and repeats `spl7` and the swap until it succeeds. The store of the new value is in the
  delay slot of the `flushbus` call that follows the read. On the locking path the owner word is then set back to -1
  with a doubleword store and `splx` restores the level (the old value is saved at 40(sp) in that call's delay slot),
  which is also the value returned; the already-held path returns it too. Established.
