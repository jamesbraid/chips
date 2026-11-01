# Odyssey graphics routines of the IP30 kernel

These routines of `IP30/unix` (the linked IRIX 6.5 kernel for the Octane; addresses are virtual addresses) drive the
Odyssey graphics board over its XIO window. A board record is found by indexing the table at 0xa8000000204a85b8 (a
doubleword per board) with the board number. In the board record the window pointer is the doubleword at +0x338, the board
number the halfword at +0x316, the flow-control object the doubleword at +0x328, and the shadow of the chip register at window
+0x1004 the word at +0x85a4. Window offsets below are from the pointer at +0x338. The kernel serialises a command-FIFO write
by storing the 32-bit words at window +0x110000 and following each with `SYNC` (a `sync` instruction); that sequence is
called a FIFO write below.

- `odsyReset` (`IP30/unix` `0xa800000020360b68`, 1800 bytes, frame 64 bytes) returns the board to its power-on state;
  it takes the board number and returns nothing. It stops the FIFO timer with `odsyFifoTimer`, sets the word at +0x330
  to 1 and clears the halfword at +0x31a, takes either `mutex_lock` (class 0x19) on the Odyssey crossbar lock or
  `mutex_spinlock` on the crossbar spinlock depending on the word at +0xb468, clears 0x24c bytes at +0xc8 with
  `blkclr` and writes the name "ODYSSEY" into the start of it. It then calls `odsyLowLevelReset`, writes the widget
  register at window +0x24 with the byte at +0x319 ORed with 0x4200, waits 100000 microseconds with `odsy_usdelay`,
  and builds the shadow word at +0x85a4 with the board's 4-bit id (byte at +0x318) shifted left 19, storing it to
  window +0x1004. It calls `odsyGatherInfo` (1), `odsyMMinit` with the window and the record's +0x368, `odsyInitDBE`
  with the timing table in the pointer at 0xa8000000204a85c8 and 1, and `odsyGatherInfo` (0). It looks up the boot
  argument "monitor" with `kopt_find` and, when its value is at most eight characters and starts with "72hz" or "60hz"
  (five bytes compared, so the NUL must match) it switches the timing table pointer (the 72 Hz test also needs the
  word at +0x118 to be 1). It releases the lock, then writes 0xffffffff to window +0x103c and +0x101c and 0 to
  +0x1044, +0x104c, +0x1054, +0x105c, +0x1074, +0x107c, +0x108c, +0x109c, +0x10a4, +0x10ac, +0x401c, +0x4024, +0x402c,
  +0x4034 and +0x403c, each after a shadow-store in the record at +0x85ac and following and each followed by `SYNC`.
  It builds and writes the words at window +0x4044 and +0x4014 from the board id in the shadow words at +0x85f8 and
  +0x8608, zeroes +0x404c, +0x4054 and +0x405c, and writes the widget words +0x10bc (0) and +0x10cc (0xffffffff). It
  sets or clears bits 2, 1, 3 and 4 of the +0x1004 shadow from the memory configuration (bank count at +0x104 of 2 or
  4, CAS latency at +0x100 of 2 or 3, size in megabytes at +0xfc of 32 (0x20), 33 (0x21, stored back as 32), 64 or
  128), printing "odsyReset: invalid sdram banks: %d", "invalid sdram casl: %d" or "invalid sdram size: %dMB" with
  `printf` otherwise. After that come five 400-microsecond delays interleaved with writes of the +0x1004 shadow in
  which bit 5 (0x20) is cleared and set again, cleared once more, and bit 8 (0x100) is finally set; then zero goes to
  window +0x34, +0x1044 and +0x1074, 0xffffffff to +0x103c, the pulse 0,
  1, 0 to +0x1084,
  0xffffffff to +0x101c and zero to +0x5c, and finishes with `odsy_hpipe_invalidate` and a store of 0 to +0x330.
  Inferred: read from decompiler output with the callees, the string arguments and the store addresses checked against
  the fact sheet; the order of the register stores was not traced in the disassembly.
- `gf_OdsyInitialize` (`IP30/unix` `0xa8000000203601e8`, 1196 bytes, frame 96 bytes) brings a graphics board up for a
  new owner. Its argument is the graphics context; the board record is the doubleword at context +0x28. It returns -1
  in two cases, when render nodes are still open after the wait described next and after six failed FIFO set-ups, and
  otherwise the result of `odsyInitCfifo` (0 on success). It clears the word at record +0xb468. When the open render
  node count at +0x6f40 is nonzero it enters a wait of up to twelve rounds: it prints "odsy board %d: %d rnodes still
  open when OdsyInitialize called" with `cmn_err` (level 4), starts a semaphore at +0x6f30 with `init_sema`, arms a
  500-tick `timeout` on the routine at 0xa800000020360088 and blocks in `psema`, and leaves the wait as soon as the
  count is zero. When the record's current owner (+0x48) is not the caller, it waits on the semaphore at +0x38 with
  `psema` and polls the word at +0x68 with `us_delay` (2). It adds 1 to the open count at +0x50, calls
  `htp_register_board` with zeros, detaches and frees any existing flow-control object (`gfx_flow_am_i_attached`,
  `gfx_flow_detach_me`, `gfx_flow_dealloc`), and repeats up to six times: `odsyReset`,
  `gfx_flow_alloc` for the window ORed with 0x100000, a 0x1ffff mask, 0x800 and 10000 and the interrupt handler
  `odsyHiwaterInterrupt`, `gfx_flow_wg_info_get`, a wait for the 9-bit field of window +0x106c (bits 15:7) to reach
  zero, the pulse 0, 1, 0 to window +0x1084, then the flow-control word at +0x85c4 built from the target
  (`xtalk_intr_target_get`), the credit number (`gfx_flow_credit_tnum_get`) shifted left 12,
  0x800000 and 200, stored also to window +0x1074, and `odsyInitCfifo`; a nonzero result frees the flow object, waits
  10000 microseconds and tries again. On success it initialises the 32 KB slot map (`OdsyInit32kSlotMask`,
  `OdsyAlloc32kSlot` twice), stores the second slot at +0xb44c and its table entry pointer at +0xb450, and calls
  `odsyInitMM`, `odsyInitDMA`, `odsyInitRetrace`,
  `odsyInitInterrupts` and `odsyZeroOut` with the flow object attached around the last, then detaches, clears +0xb468
  and decrements the open count at +0x50. Inferred: read from decompiler output, with the callees checked against the
  fact sheet and the open-node wait read in the disassembly.
- `odsyInitCfifo` (`IP30/unix` `0xa800000020361270`, 860 bytes, frame 80 bytes) sets up the command FIFO and tests it.
  The first argument is the board number and the second, when nonzero, asks it to attach and detach the flow-control
  object itself (the attach sequence and its inverse are the ones `gf_OdsyInitialize` uses). It writes through a FIFO
  write the 32-bit words 0x10854, 0 and 0xfffffff, then one doubleword formed as 107 shifted left 36 (0x6b000000000),
  then the four doublewords held in the literal pool at 0xa8000000204a8fb8, 0xa8000000204a8fc0, 0xa8000000204a8fc8 and
  0xa8000000204a8fd0, and the word 0x10046, waits 2000 microseconds, and reads the word at window +0x201594. When it
  equals 0x3d0046 it writes 0x2e008380, 0x2600807f and 0x27008000, then 2048 groups of six words taken from a table at
  2000 bytes into the table named `flag_desc` (each word masked to its low 10 bits plus its upper bits shifted left 23
  and ORed with 0x40008000), the doubleword at 0xa8000000204a8fd8, and returns 0 (after detaching when asked).
  Otherwise it returns 1. Inferred: read from decompiler output.
- `odsyDMAOp` (`IP30/unix` `0xa80000002038d724`, 2056 bytes, frame 272 bytes) queues one DMA transfer on the board.
  Its arguments include the user context, the board record, a flag word (bit 1 asks for a waiter, bit 0 for a flush),
  the descriptor chain and two out values; it returns 0 or the error number 12 (ENOMEM). It takes the mutex at record
  +0x16a8 with `ddi_mutex_lock`, takes the next of 256 operation records of 0x50 bytes from the ring at +0x1f18 (index
  at +0x6f18, wrapped modulo 256), zeroes it with `blkclr`, and releases the mutex. With bit 1 set it initialises a
  semaphore in the record with `init_sv` ("dopsv"). It allocates a translation-set id with `OdsyAllocCSetId` for a
  user buffer, builds one 0x80-byte descriptor per chain entry in memory from `kmem_alloc` (copying 0x20 bytes of the
  template with `ovbcopy` and filling the size and stride fields), takes the mutex again and waits with `odsyDMAWait`
  until the ring at +0x1ae0 to +0x1ae8 has room, stores the ticket, then writes descriptors to the FIFO with the
  physical address (`kvtophys`) split into the 17-bit and upper parts, and the commands 0x10658 and 0x120000, or the
  longer wait sequence when bit 3 of the template's flags byte at +0x1f is set, and finally 0x10a5a with the counter
  at +0x16d0. On a failure it releases the translation set with `unuseracc` and `OdsyDeallocCSetId`, fills the freed
  memory with 0x8b and 0x8d markers and frees it with `kmem_free`, printing "odsy dmaop: cannot allocate outstanding
  locked rgn in gctx." or "odsy dma : cannot allocate translation table" with `cmn_err`. It releases the mutex if
  still held (`mutex_mine`). Inferred: read from decompiler output and the fact sheet; the chain loop and the FIFO
  command words were not traced word by word.
- `gf_OdsySchedSwapBuf` (`IP30/unix` `0xa800000020365afc`, 1108 bytes, frame 112 bytes) schedules a buffer swap for a
  window id. Its arguments are the board record, the graphics context and the window id (0 to 31; larger values print
  "gf_OdsySchedSwapBuf: wid %d is out of range" with `cmn_err` and return 22). It attaches the flow-control object
  when not already attached, calls `odsyPushBufferSelect` with the context's buffer state and the window, detaches
  again, and takes the mutex at record +0x6f58 with `mutex_lock`. When a swap is already pending for the window (bit
  `1 << wid` in the word at +0x6f98) and a record at +0x6fc0 plus 40 * wid exists it unlocks and returns 16; otherwise
  it waits on the condition at +0x6f68 with `sv_wait` until the bit clears. It then sets the bit, builds the mask of
  windows to select from the context's list at +0xa0 and +0xa8, stores it at window +0x10bc and record +0x6f80 when it
  changed, and records the context's per-window fields in the words at +0x6f9c and +0x6fa0. When the saved value at
  +0x6fb0 matches the table entry it calls an unnamed routine at 0xa8000000203658b8 and otherwise sets the bit in
  +0x6f84. It always unlocks and returns 0 on those paths. Inferred: read from decompiler output.
- `gfP_OdsySaveHwShadow` (`IP30/unix` `0xa800000020358bc4`, 920 bytes, frame 112 bytes) saves the board's hardware
  context shadow for a context being switched out. It returns 0, 14 (EFAULT) or 22 (EINVAL) and stores the same value
  through its fourth argument. With a nonzero third argument it only runs the owner's callback (an indirect call
  through the pointer at +0x78 of the table at argument-1 +0x20) with the open count at +0x50 raised for the call.
  Otherwise it validates the context with `RRM_CheckValidFault` (14 on failure), requires a graphics context in the
  second argument (22 if absent), attaches the flow object if needed, clears the word at context-shadow +0x8fc, writes
  the doubleword at 0xa8000000204a8f88 to window +0x118000, arms a 1500-tick `timeout` and polls with `us_delay` (1)
  until the shadow word becomes nonzero or the abort word at +0x330 is set, cancels with `untimeout_wait`, detaches,
  and returns 0 when the shadow was saved and 14 (after the abort message "odsy board %d: gfx hw pushback aborted due
  to abnormal teardown") otherwise. Inferred: read from decompiler output.
- `gf_OdsyDestroyDDRN` (`IP30/unix` `0xa80000002038b748`, 656 bytes, frame 80 bytes) tears down one render node. Its
  arguments are the board record, the graphics context and the node, and it returns 0. If the context's current node
  is the one being destroyed it calls `gfx_flow_clean_up_other_gfxp` and either swaps in another node through the
  owner's callback (printing "gf_OdsyDestroyDDRN: could not swap out dead ddrn!" with `cmn_err` when it fails) or
  clears the halfword at record +0x31a. It clears the board's current-node word at +0x334 when it names this node,
  unschedules any pending swap with `gf_OdsyUnSchedSwapBuf` and retrace event with `gf_OdsyUnSchedRetraceEvent`, and
  when the node's state word at +0x198 is zero runs `odsyDMAFinish`, `odsyMMdetach` and `odsyUnpinAndUnmapGctxRegions`
  and sets it to 1. It always calls `odsy_hpipe_cleanup`, clears two words of the node, frees the 0x4000-byte save
  area with `kmem_free`, releases the node's 32 KB slot with `OdsyFree32kSlot`, and, when the record's open-node count
  at +0x6f40 is 1, detaches and frees the flow-control object, zeroes the flow word at +0x85c4 and window +0x1074. It
  then marks the node with -1 and decrements the count. Inferred: read from decompiler output.
- `odsyRestartContext` (`IP30/unix` `0xa80000002035d738`, 2884 bytes, frame 112 bytes) replays a saved context into
  the board's command FIFO when a graphics context is switched back in. Its arguments are the board record and the
  context; it returns nothing. Almost the whole body is FIFO writes of 32-bit words at window +0x110000: it starts
  with 0x34008000, then repeats a fixed group of command words (0x10443, 0xfa, 0x10046 twice, 0x10019 or
  0x11017) three times with words from the saved state at +0x1b24 to +0x1b30 of the context's state block (the
  doubleword at context +0x58 is the state block; the doubleword at +0x60 is the shadow). It then calls
  `odsySetProgram` and `odsyRestoreVB`, writes the saved word at +0x1b4c to +0x1b70 when the word at +0x1b34 has any
  of its low three bits set (preceded by the command 0xcf80a92f), four texture-style registers recomposed from the
  words at +0x26a8, +0x2680, +0x2684 and +0x268c (each as low 10 bits plus the upper bits shifted left 23, with the
  commands 0x33008000, 0x29008000, 0x2a008000 and
  0x2c008000), and the end commands 0x10658 and 0x120000. It reduces the saved mode word in the shadow, rebases three
  2-bit fields by the pixel-size field, selects the chip variant from the low nibble of the shadow word (values up to
  10, with 10 being a separate path) and calls through a table of per-variant restore routines for nonzero rebasing.
  Pixel state is restored with `odsyRestorePIOPixel` when the saved PIO flag at shadow +0xac is set, and the routine
  ends with the saved vertex-buffer data from shadow +0xb4 to +0xbc, the command 0x34008000 ORed with a recomposed
  word from +0x26ac, and a loop copying the remaining saved words. Inferred: read from decompiler output; the variant
  table and the loops at the end were not traced instruction by instruction.
- `gfx_flow_alloc` (`IP30/unix` `0xa80000002038f318`, 512 bytes, frame 96 bytes) allocates and fills one 104-byte
  flow-control record for a graphics widget and returns its address, or 0 when `kmem_alloc` (size 104, flags 0)
  returns 0. The first argument (a0) is the widget handle and the second (a1) the widget's physical window. It takes
  `mutex_spinlock` on `gfx_flow_init_lock` and, when the doubleword `gfx_flow_owners` is zero, first calls the unnamed
  routine at 0xa80000002038f230. It then adds 1 to the word at 0xa8000000204b0020 and stores it back; when the new
  count is 1 it runs the HEART hookup for the first record: for index 0 and 1 in turn it stores 2 and then 4 (1
  shifted left by index plus 1) to 0xffffffffaff10028, the HEART acknowledge register, and calls
  `heart_flow_control_connect` with the index and the prehandler `gfx_flow_delayed_hiwater_intr_prehandler`. The lock
  is released with `mutex_spinunlock` before the allocation. Into the record it stores, in this order: the handle as a
  word at +0x0 (in the delay slot of `xwidget_info_id_get`), the window at +0x8, the widget id from `xwidget_info_get`
  and `xwidget_info_id_get` as a word at +0x4, the third argument (a2) as a doubleword at +0x10, the low 32 bits of
  the fourth (a3) divided by 8 at +0x1c and then +0x18, the fifth (a4) times 100 divided by 1000 (unsigned, replaced
  by 1 when it comes out zero) at +0x20, the value 1 at +0x38, +0x3c and +0x40, the value 56 at +0x44, the sixth
  argument (a5) at +0x28 and the seventh (a6) at +0x30 as doublewords, and the eighth (a7) as a word at +0x48. It then
  calls `kvalloc` (1, 0, 0), stores the result at +0x50 and writes a page-table entry: the entry address is the table
  whose pointer is the doubleword `kptbl`, plus 8 times ((result plus 0x4000000000000000) >> 14), and the entry is the
  window shifted right 14 and left 8, ORed with the doubleword at 0xa8000000204a9140 (0x10000003f). It calls the
  unnamed routine at 0xa80000002038f270 with the record, stores 0xffff as a halfword at +0x5c and -1 as a doubleword
  at +0x60, and returns the record. Established.
- `gf_OdsyAttach` (`IP30/unix` `0xa80000002036f8cc`, 384 bytes, frame 288 bytes) creates the user mapping of an
  Odyssey board through `gfxdd_mmap` and returns 0, 12 or 22; its first argument (a0) is the board record and its
  second (a1) the user address to map at. It copies 256 bytes from the table at 0xa800000020419730 (eight 32-byte
  entries whose first two doublewords are 0 and 0x4000 in the first entry) to the stack, loads the HEART doubleword at
  0xffffffffaff00080 and discards it, and returns 22 when any of bits 13:0 of a1 is set. Otherwise it calls
  `gfxdd_recycle` with `odsy_regmatch`, the record and the address, and returns 0 when that returns nonzero. For a
  record whose flag word at +0x4 has bit 0x20 or 0x04 set it uses all eight entries and a length of 16 shifted left
  14; otherwise the first two and 2 shifted left 14. It adds a1 to the first two doublewords of each entry it uses,
  then calls `gfxdd_mmap` with 1, the length, the address, `gfx_fault`, the record, the table, the entry count and
  record +0x30. A nonzero result prints "odsy: cannot attach (ENOMEM)" with `cmn_err` (level 4) and returns 12. On
  success it raises the level with `spl1`, stores the flag word ORed with 1 (in the delay slot of the next call),
  calls `gf_OdsyUnMapGfx`, restores the level with `splx`, reads the HEART doubleword at 0xffffffffaff00080 again and
  returns 0. Established.
