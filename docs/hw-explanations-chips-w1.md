# Hardware-facing routine explanations, CRIME and the IP32 kernel, wave 1

Each entry says what one routine does to the hardware and cites the instruction addresses it rests on. The facts come from the routine bodies in the shipped binaries and from the linked register and ioctl rows of the inventory. Meanings that come from a datasheet or a callee are marked Inferred, and open points are marked Unknown with the route that would settle them.

- `VEC_dbe` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x1c2d4 (n32).
  Inferred: the routine is an exception entry, since it saves CRIME error registers into kernel
  symbols and then tail-jumps to `VEC_trap` with its arguments passed on.
  Five 8-byte CRIME words, at +0x48, +0x40, +0x250, +0x258 and +0x58, are each loaded from the CRIME
  block at 0xffffffffb4000000 and stored into the symbols crm_cpu_error_stat, crm_cpu_error_addr,
  crm_mem_error_stat, crm_mem_error_addr and crm_vice_error_addr (0x1c2d8 through 0x1c328).
  It writes zero to +0x250 (`sd` at 0x1c32c) and to +0x48 (`sd` at 0x1c330), then reads both back
  into the zero register at 0x1c334 and 0x1c338, so those reads are discarded.
  It writes zero to the word at 0xffffffffbf080004 (`sw` at 0x1c344), reads it back at 0x1c34c, and
  loads the halfword at 0xffffffffffffa190 (`lh` at 0x1c348) into t0.
  The `sd` of t0 at 0x1c354, in the delay slot of the jump at 0x1c350, stores that halfword as 8 bytes
  at +0x140 of the block at a0, and the jump passes a0 through a3 unchanged to `VEC_trap`.
  Inferred: +0x40, +0x250 and +0x258 are the CPU error address, the memory error status and the memory
  error address, because the linked rows name them so and the datasheet excerpt calls the first
  read-only and gives the last as the failing memory offset.
  Unknown: which CRIME register sits at +0x48 and how a zero write there acts; the linked row leaves it
  unnamed, and the excerpt puts the CPU error status at 0x14004048 rather than the 0x14000048 offset
  used here, so the route is the 1.5 register table for that status word.
  Unknown: the device behind 0xffffffffbf080000 and the halfword at 0xffffffffffffa190; no linked row
  covers either, so the route is a datasheet for that device and the symbol-table name for the
  halfword's address in the object.
  Evidence grade: inferred.
- `VEC_ibe` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x20dc0 (n32).
  Inferred: the routine is an exception entry, since it copies CRIME error words into kernel symbols and
  then tail-jumps to `VEC_trap` with its arguments passed on.
  On entry it loads ra from +0x118 and a2 from +0x120 of the block at k1 (0x20dc0 and 0x20dc4), branches
  on the sign of ra (`bgez` at 0x20dc8), adds 4 to a2 at 0x20dd0 when ra is negative, and stores a2 to
  +0x110 of the same block (`sd` at 0x20dd4), a store that both branch paths reach.
  Then the CRIME words at +0x48, +0x40, +0x250, +0x258 and +0x58 go into the kernel symbols
  crm_cpu_error_stat, crm_cpu_error_addr, crm_mem_error_stat, crm_mem_error_addr and crm_vice_error_addr,
  one load and one store per word, from 0x20ddc to 0x20e2c.
  Zero is written to +0x250 (0x20e30) and +0x48 (0x20e34), both are read back into the zero register at
  0x20e38 and 0x20e3c, and zero is written to 0xffffffffbf080004 (`sw` at 0x20e48) with a read-back at
  0x20e50.
  The halfword at 0xffffffffffffa190 (`lh` at 0x20e4c) is stored as 8 bytes at +0x140 of the block at a0
  by the `sd` at 0x20e58, in the delay slot of the jump at 0x20e54, and that jump passes a0, a1 and a3
  unchanged to `VEC_trap`.
  Inferred: +0x40, +0x250 and +0x258 are the CPU error address, memory error status and memory error
  address, because the linked rows give those names and the datasheet excerpt marks the first read-only.
  Unknown: the block that k1 addresses and the value of a2 at the jump at 0x20e54, since the bundle
  prints k1 and a2 as untracked; the route is a listing of the code that sets k1 before 0x20dc0 and a
  trace of a2 at the jump.
  Evidence grade: inferred.
- `VEC_int` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x0 (n32).
  Inferred: the routine is the interrupt exception entry at 0x0, since it calls `intr` at 0x48,
  leaves through `exception_leave` at 0x1e0, and works on the CRIME Interrupt Enable register at
  +0x18 (linked row). On entry it loads that register (`ld` at 0xc) and stores it into +0x138 of the
  block addressed by k1 (`sd` at 0x18), combined with the word at 0xffffffffffffa2e0 shifted into
  the upper half; it then writes 0x18 to 0xffffffffffffa2e0 (`sw` at 0x20). It loads the 8-byte word
  at 0xffffffffffffa2d0 (`ld` at 0x24) and writes it to the Interrupt Enable word (`sd` at 0x2c),
  and after the call to `intr` at 0x48 (result kept in s3) it writes the saved word in s4 back to
  0xffffffffffffa2e0 (`sw` at 0x54), loads the 8-byte table entry at s4-0x5d48 (`ld` at 0x58) and
  writes that entry to the Interrupt Enable word (`sd` at 0x64). A stack pointer below the word at
  0xffffffffffffa020 (`lw` at 0x84) leaves through `exception_leave` (`bne` at 0x8c); a stack
  pointer above it that is not equal goes to `cmn_err` at 0x1f8, with the stack pointer as its third
  argument (the `or` at 0x1e8) and the word at 0xffffffffffffa1a4 loaded into sp afterwards (the
  `lw` at 0x1f4). When the saved status in s0 has any of its 0x18 bits set (at 0x9c), the byte at
  0xffffffffffffa03e or the pointer chain from the word at 0xffffffffffffa014 ending at a nonzero
  word sends the routine to 0xd4; otherwise it tail-jumps to `backtouser` at 0xcc. At 0xd4 it sets
  the byte at 0xffffffffffffa03f to 1, calls `ktimer_switch` with the word at 0xffffffffffffa018 and
  1 (the `jal` at 0xe4), and tail-jumps to `soft_trap` with a1 = 0x84 and a3 from +0x118 of the
  block at k1 (`j` at 0xf8). When those 0x18 bits are clear the path at 0x100 calls `ktimer_switch`
  when the word at 0xffffffffffffa018 is nonzero (the `jal` at 0x110), then tests the byte at
  0xffffffffffffa043. A nonzero byte sets the byte at 0xffffffffffffa03f to 3, clears the byte at
  0xffffffffffffa043, and leaves through `exception_leave` when the byte at 0xffffffffffffa040 is
  zero (`beq` at 0x134); otherwise it calls `splhi` (the `jal` at 0x13c), clears the byte at
  0xffffffffffffa040 and tail-jumps to `resumeidle` with a0 = 0 (the `j` at 0x158). A zero byte at
  0xffffffffffffa043 clears the word at +0x15c of the record at the word 0xffffffffffffa018 (the
  `sw` at 0x164), sets the byte at 0xffffffffffffa03f to 1, and leaves through `exception_leave`
  when the `intr` result in s3 is zero (the `beq` at 0x170) or the byte at 0xffffffffffffa03e is
  zero (the `beq` at 0x17c); otherwise it calls `splhi` (the `jal` at 0x184) and `kpswtch` (the
  `jal` at 0x19c), writes s4 back to 0xffffffffffffa2e0 (the `sw` at 0x1c8) and the table entry at
  s4 to the Interrupt Enable word (the `sd` at 0x1d8), and leaves through `exception_leave`. The
  routine also writes a coprocessor-0 register at several points between these steps, which the
  bundle does not list.
  Unknown: the message behind the data-section symbol passed to `cmn_err` as its second argument;
  the bundle gives no string for it, so the route is the contents of that symbol in the object's
  data section.
  Unknown: the block addressed by k1, since the bundle gives no value for it; the route is a trace
  of the code that sets k1 before the entry.
  Evidence grade: inferred.
- `_clock_func` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x129e8 (n32).
  Moves eight bytes between the caller's buffer at a1 and the eight addresses 0xffffffffbf3a0007,
  0xffffffffbf3a0207, 0xffffffffbf3a0407, 0xffffffffbf3a0707, 0xffffffffbf3a0807,
  0xffffffffbf3a0907, 0xffffffffbf3a0607 and 0xffffffffbf3a4807 through pciio_pio_read8 and
  pciio_pio_write8, bracketed by a call to splhi (`jal` at 0x129f8) and a call to splx (`jal` at
  0x12c00). Inferred: those eight addresses are device addresses, because they are the address
  arguments of the callees pciio_pio_read8 and pciio_pio_write8, which have no committed entries and
  no linked row. After splhi it tests the word at +0xfc of `_prom_cleared` (`lw` at 0x12a18, `beq`
  at 0x12a24) and calls the local routine at 0x121f4, `rtc_init`, with a direct `jal` at 0x12c18
  when that word is zero, then the argument a0 picks the path (`bne` at 0x12a50). When a0 is zero,
  it reads the byte at 0xffffffffbf3a0b07 and writes it back with 0x80 ORed in (`jal` at 0x12a58 and
  0x12a68), reads the byte at 0xffffffffbf3a0a07 and writes it back with 0x10 ORed in (`jal` at
  0x12a70 and 0x12a80), then reads the eight addresses in order into the buffer at a1: bytes +0, +1,
  +5 and +7 as read (`sb` at 0x12a94, 0x12aa0, 0x12ae0 and 0x12b00), and bytes +2, +3, +4 and +6
  masked with 0x3f, 0x3f, 0x1f and 0x7 (the `sb` at 0x12ab4, 0x12ac4, 0x12ad4 and 0x12af0). When a0
  is nonzero, it reads the byte at 0xffffffffbf3a0a07 and writes it back with 0x30 ORed in, reads it
  again and writes it back with the 0x40 bit cleared, and reads the byte at 0xffffffffbf3a0b07 and
  writes it back with 0x80 ORed in (`jal` at 0x12b04 to 0x12b48); it then writes buffer +0 to +7 to
  the eight addresses in the same order (`jal` at 0x12b54 to 0x12bb8), with the byte at +2 masked
  with 0x3f (the `andi` at 0x12b74). Both paths end by reading 0xffffffffbf3a0b07 and writing it
  back with its 0x80 bit cleared (`jal` at 0x12be0 and 0x12bf4), then call splx with the value splhi
  returned, which is saved at frame +0x8 (`sd` at 0x12a00, `ld` at 0x12bdc), and return the value
  splx returns.
  Unknown: the interrupt-state change made by splhi and by splx; neither has a committed entry, and
  their entries would settle it.
  Unknown: which device registers the eight addresses are; the bundle has no linked row for the
  block at 0xffffffffbf3a0000.
  Evidence grade: inferred.
- `_cpuclkper100ticks` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x140f8 (n32).
  Inferred: the routine counts a coprocessor-0 register against the CRIME timer at +0x38, since it
  writes zero to that timer with one 8-byte store at 0x14130, polls it with the 8-byte load at 0x14138
  until it reaches 0x5bc8 (the `bne` at 0x1414c, an unsigned compare against t0 as set at 0x14134),
  and reads the coprocessor-0 register after each poll; the linked row names the offset Crime Timer
  and the datasheet excerpt gives it as a 32-bit counter with reset zero. The coprocessor-0 register
  is number 9, which on the R4000 family is the cycle count register; the bundle does not list these
  instructions, so this reading rests on the disassembly.
  Before each pass it zeroes that coprocessor-0 register and fills five instruction-cache lines from the
  address of the polling code. An outer loop repeats the zero write and the poll four times: t3 is set
  to 3 at 0x14108 and decremented in the delay slot of the branch at 0x1415c. Each pass adds the timer
  value to a5 and the count read to a6.
  After the loop, t3 is set to 4 at 0x14164 and both sums are divided by 4: the count average stays in
  v0 as the return value, and the timer average in a4 is stored to +0x0 of the block at a0, the caller's
  argument, at 0x1418c.
  The routine makes no call, and the two accesses at 0x14130 and 0x14138 are the only memory-mapped
  accesses the bundle lists.
  Unknown: whether the zero write at 0x14130 clears the counter, since the excerpt leaves the results of
  writes for review; the route is a reviewed entry for the timer's write handling in the CRIME datasheet.
  Unknown: the counting rate of the timer at +0x38, so the time spanned by the 0x5bc8 threshold and the
  outer passes is open; the route is a reviewed frequency entry for that register.
  Evidence grade: inferred.
- `add_vice` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x8168 (n32).
  Inferred: it reads the CRIME interrupt status at offset 0x10 (linked row `CRIME 0x10 Interrupt Status`, which the reviewed datasheet gives at `0x14000010` as a read-only OR of hardware and software causes), and it calls `add_to_inventory` only when the 0x80000000 bit of that status is set. It writes 4 to `0xffffffffb700e014` (the `sw` at 0x8184, in the delay slot of the call at 0x8180) and calls `us_delay` with 0xa, then writes 0 to `0xffffffffb70001bc` (the `sw` at 0x8194) and calls `us_delay` with 0xa again. It loads the doubleword at `0xffffffffb4000010` (the `ld` at 0x81a0) and branches to the return at 0x81d8 when that bit is clear (the `beq` at 0x81ac). When the bit is set, it copies the word at `0xffffffffb7000164` to `0xffffffffb700e00c` (the `sw` at 0x81c8) and calls `add_to_inventory` with a0 0xf, a1 0x3, a2 and a3 0x0, a4 set to the word at `0xffffffffb700000c` (the `lw` in the delay slot at 0x81d4), a5 set to the word at `0xffffffffb7000164`, and a6 set to `0xffffffffb700e00c` (the `jal` at 0x81d0). The return at 0x81dc gives the v0 left by the last call: `us_delay` on the branch-taken path and `add_to_inventory` on the fall-through path. Unknown: the owner of the window at `0xffffffffb7000000`, since no linked row names it; the route is the inventory row for that window. Unknown: the handling by `add_to_inventory` of the arguments a4 to a6, since that routine has no committed entry; the route is that routine's own entry. Unknown: the timing the two `us_delay` waits impose, since the bundle shows them only as calls; the route is the `us_delay` entry.
  Evidence grade: inferred.
- `baerror` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x149a8 (n32).
  Inferred: it works on CRIME's Memory Error Status at offset 0x250 (linked row `CRIME 0x250 Memory Error Status`; the reviewed datasheet gives that register invalid-address bits 25 for a read, 26 for a write and 27 for a read-modify-write), on the CRIME register at offset 0x48, and on a word in a second window at `0xffffffffbf080004`. It writes zero to the doubleword at offset 0x48 (the `sd` at 0x149ac) and to the doubleword at offset 0x250 (the `sd` at 0x149b0), reads both back (the `ld` at 0x149b4 and 0x149b8), then writes zero to `0xffffffffbf080004` (the `sw` at 0x149c4) and reads it back (the `lw` at 0x149c8). It loads the word at `0xffffffffffffa018` into t2 (the `lw` at 0x149e0) and branches to the store at 0x149f8 when that word is zero (the `beq` at 0x149e4), and that store writes a zero word to `0xffffffffffffa1d8`. When the word is not zero, it writes a zero halfword at offset 0xc2 from that word (the `sh` at 0x149ec) and then branches to the return path (the `beq` at 0x149f0). Either way it sets v0 to 1 in the delay slot at 0x149e8, loads ra from the entry stack pointer plus 0x8 (the `ld` at 0x149fc), and returns at 0x14a04. Unknown: the chip behind the window at `0xffffffffbf080000`, since no linked row names it; the route is a linked row for that window or the datasheet of the chip that owns it. Unknown: which CRIME 1.5 register sits at offset 0x48, since its linked row has no name; the route is the CRIME 1.5 register table that holds the linked spec row for offset 0x250. Unknown: the object that the halfword write at offset 0xc2 lands in, since the word at `0xffffffffffffa018` is only loaded here and its writer is not in the bundle; the route is the writer of that word or a trace of its value.
  Evidence grade: inferred.
- `clearbadclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12e48 (n32).
  Its own instructions never load or store the addresses 0xffffffffbf3a0a07 and 0xffffffffbf3a0e07;
  it passes them to the callees `pciio_pio_read8` and `pciio_pio_write8` in two read-modify-write
  pairs, between the `splhi` call at 0x12e50 and the `splx` call at 0x12ea4. The read at 0x12e60
  passes 0xffffffffbf3a0a07 in `a0`, and the write at 0x12e78 passes the same address in `a1` with
  the value read ANDed with -0x11, which clears the 0x10 bit, and masked to the low byte by the
  `andi` at 0x12e7c. The second pair, at 0x12e84 and 0x12e9c, uses 0xffffffffbf3a0e07 the same way,
  with the read value ANDed with -0x2, which clears the low bit, and masked to the low byte by the
  `andi` at 0x12ea0. It saves `ra` and `s0` at 0x12e4c and 0x12e54, restores them at 0x12eac and
  0x12eb0, and passes the value `splhi` returned to `splx` (the `jal` at 0x12ea4, with `or
  a0,s0,zero` in its delay slot). The bundle has no branch, so the code runs straight through once,
  and the return at 0x12eb4 leaves `v0` as `splx` returned it.
  Unknown: the device-side result of the two read calls and the two write calls, which need
  committed entries for `pciio_pio_read8`, `pciio_pio_write8`, `splhi` and `splx`.
  Unknown: the callers of the routine at 0x12e48, and why the two bits are cleared, which a
  committed caller entry or a reviewed datasheet excerpt naming the offsets from 0xffffffffbf3a0000
  would settle.
  Evidence grade: established.
- `cpu_powerdown` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x11124 (n32).
  Loops without a return over three byte locations, 0xffffffffbf3a0a07, 0xffffffffbf3a4a07 and
  0xffffffffbf3a4b07, after one call to `flash_write_env` at 0x11148; the bundle has no return
  instruction. Inferred: the hostfacts output lists those three addresses under addresses outside
  the file (memory-mapped I/O), so the loads and stores in the loop go to memory-mapped I/O. At
  0x1116c it loads the byte at 0xffffffffbf3a0a07 once, clears its 0x40 bit with the mask -0x41 set
  at 0x11174 and forms two values from the result: the form with 0x30 ORed in (s5, at 0x11184) and
  the form with 0x20 ORed in (s6, at 0x11180). The `sb` at 0x1118c stores the 0x30 form to the
  address in the delay slot of the `flushbus` call at 0x11188, and the `sb` at 0x111b8 stores the
  0x20 form in the delay slot of the second `flushbus` call at 0x111b4. Between the two flushes, at
  0x11190 it loads the byte at 0xffffffffbf3a4b07 into `ra` and stores it ORed with 0x81 at 0x11198;
  it loads the byte at 0xffffffffbf3a4a07 into `t9`, clears its low three bits with the mask -0x8
  set at 0x11150 and stores it at 0x111a4, then loads it again into `t8` and stores it ORed with 0x8
  at 0x111b0. Each pass calls `us_delay` with 0xf4240 in `a0` at 0x111bc and again at 0x111d0, calls
  `cmn_err` with 0x4 in `a0` at 0x111c8, and branches unconditionally back to 0x11188 at 0x111d8, so
  later passes store the 0x30 form again. The `flash_write_env` call passes the four entry arguments
  through unchanged.
  Unknown: the device-side result of the `flash_write_env` call at 0x11148, which needs its
  committed entry.
  Unknown: the time unit of 0xf4240 passed to `us_delay`, and the text at `sym(.rodata)`+15792
  passed to `cmn_err` at 0x111c8, which need the callee entries and a string read from the binary.
  Evidence grade: inferred.
- `cpu_waitforreset` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x1121c (n32).
  Has no return instruction; it loops over the byte at 0xffffffffbf3a0a07, the byte at
  0xffffffffbf3a4a07, the byte at 0xffffffffbf3a0c07 and the 8-byte word at 0xffffffffbf310010, with
  the word test bracketed by `spl7` and `splx`. Inferred: the hostfacts output lists those four
  addresses under addresses outside the file (memory-mapped I/O), so the loads and stores of the
  loop go to memory-mapped I/O. It saves `s5`, `s1`, `s4`, `s6`, `s3`, `ra`, `s2` and `s0` in its
  frame, and passes its four entry arguments unchanged to `flash_write_env` at 0x11238 before the
  first test. Each pass through 0x1126c loads the byte at 0xffffffffbf3a0a07 and stores it ORed with
  0x10 at 0x11278, in the delay slot of the `flushbus` call at 0x11274; it then loads the byte at
  0xffffffffbf3a4a07 and branches on bit 0x1 at 0x11284, calling `cpu_powerdown` at 0x1128c when
  that bit is set, and either way reads the byte at 0xffffffffbf3a0a07 into `ra` at 0x11294 and
  stores it back at 0x1129c ANDed with the mask -0x11 set in s6 at 0x11240, which clears the 0x10
  bit that the earlier store set. The `spl7` call at 0x112a8 returns a value that `or s0,v0,zero` at
  0x112bc keeps in `s0`; the 8-byte word at 0xffffffffbf310010 is loaded at 0x112b0, and while bit
  0x100 of it is clear the routine calls `splx` with `s0` at 0x112a0 and loops back to the `spl7`
  call. When bit 0x100 is set, the byte at 0xffffffffbf3a0c07 is tested for bit 0x80 at 0x112c8: a
  set bit goes back to 0x1126c, and a clear bit calls `cmn_err` with 0x4 in `a0` at 0x112d0 and then
  goes back to 0x1126c.
  Unknown: the device-side result of the `flash_write_env` call at 0x11238, and the content of
  `spl7`, `splx`, `cpu_powerdown`, `flushbus` and `cmn_err` as called here, which need their
  committed entries.
  Unknown: which register the 8-byte word at 0xffffffffbf310010 is and which device sets its bit
  0x100, which a linked mmio row or a reviewed datasheet excerpt naming offset 0x10 from
  0xffffffffbf310000 would settle.
  Evidence grade: inferred.
- `crimeFifoFullHandler` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x1a8 (n32).
  Inferred: it is a CRIME interrupt-path routine, because it reads the CRIME interrupt status at
  offset 0x10 (the `ld` at 0x1dc, linked row CRIME 0x10 Interrupt Status) and then acts on one bit
  of that status and on the register block behind its argument. At entry it loads the pointer at
  +0x78 of the argument in a1 (the `lw` at 0x1b0), reads the word 0x4000 past it (the `lw` at 0x1b4)
  and takes the field of that word selected by a right shift of 0x12 and a mask of 0x7f (the `srl`
  at 0x1b8 and the `andi` at 0x1bc). When the field is 0x41 or more signed (the `beq` at 0x1d0), it
  calls `cmn_err` (the `jal` at 0x348) with the word at +0x400 of the same block as its fourth
  argument, and then reads the status. The 8-byte status is tested by the sign of its value shifted
  left by 0x25 (the `bgez` at 0x1e8); when the sign is clear, the routine adds 1 to the word at
  +0x1c of the record that the word at `gfxinfo` points to (the `sw` at 0x27c) and returns. When the
  sign is set, it calls `gfx_waitf_on` (the `jal` at 0x1f0) and loops from 0x200 to 0x230: each pass
  calls `us_delay` with 1 (the `jal` at 0x200), loads the `ibctl` word (the `lw` at 0x208 on later
  passes and at 0x370 on the first), takes its field selected by a right shift of 0x15 and a mask of
  0x7f (the `srl` at 0x214 and `andi` at 0x21c, or the `srl` at 0x374 and `andi` at 0x378 on the
  first pass), takes the same field of the +0x4000 word as before (the `lw` at 0x220, the `srl` at
  0x224 and the `andi` at 0x228), and continues while the +0x4000 field is at or above the `ibctl`
  field (the unsigned compare of the `beq` at 0x230). The loop ends when the +0x4000 field falls
  below the `ibctl` field or the counter s1 reaches 0x64 (the `slti` at 0x210, tested by the `beq`
  at 0x218), and either way it calls `gfx_waitf_off` (the `jal` at 0x238). If s1 is still below 0x64
  (the `beq` at 0x244 is not taken), it adds 1 to the word at +0x1c of the gfxinfo record again (the
  `sw` at 0x254) and returns. Otherwise the path at 0x280 adds 1 to the word at +0x18 of that record
  (the `sw` at 0x288), reloads the +0x4000 word (the `lw` at 0x28c), calls `splhi` (the `jal` at
  0x290) and takes the same field of the reloaded word from the frame copy (the `sd` at 0x294, the
  `ld` at 0x298). It adds 1 to that field (the `addiu` at 0x2b0), shifts it left by 0x15 (the `sll`
  at 0x2b8) and merges it into `ibctl` over the field selected by the mask 0xfe00000 (the `lui` at
  0x2a4 builds the mask). It stores the merged word to `ibctl` (the `sw` at 0x2c0) and to +0x400 of
  the block (the `sw` at 0x2cc, in the delay slot of the `flushbus` call at 0x2c8), then calls
  `splx` with the value `splhi` returned (the `jal` at 0x2d0). Before the common exit, a nonzero
  word at +0x3c of the argument (the `lw` at 0x2d8) sends the path through `cmn_err` (the `jal` at
  0x360); the common exit sets +0x3c to 1 (the `sw` at 0x2ec), adds 1 to the word at +0x2c of the
  record reached through +0x28 and +0x18 (the `sw` at 0x2fc), calls `force_resched` (the `jal` at
  0x300), sets +0x48 and +0x220 to 1 (the `sw` at 0x304 and 0x314), calls `timeout` with
  `crimeEmptyWaitTimeout`, its argument and 0xc8 (the `jal` at 0x318), stores the return at +0x13c
  (the `sw` at 0x328), and returns the value of `crime_intr_enable` called with 0x19 (the `jal` at
  0x324).
  Unknown: what the two fields count, since no datasheet row covers the block behind the pointer at
  +0x78 of the argument or the `ibctl` word.
  Unknown: the text of the messages passed to `cmn_err` at 0x348 and 0x360, since the bundle has no
  strings for them.
  Evidence grade: inferred.
- `crimeInitInfo` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0xec (n32).
  Inferred: it fills the video-format fields of the record in a2 from the board state, because it
  stores the address of the `crimeVTimings` table at +0x30 (the `sw` at 0x2f0) and picks the word at
  +0xe4 from the byte at +0x2e of that record (the `lbu` at 0x1c8). It reads the first word of the
  block in a1 (the `lw` at 0xec), keeps the bits selected by 0x30000000, ORs in 0xaa000 and stores
  it back (the `sw` at 0x108); it stores the low four bits of the 8-byte CRIME ID-Revision register
  at +0x29 (the `ld` at 0x10c, linked row CRIME 0x0 ID-Revision, the `sb` at 0x118), adding 1 (the
  `sb` at 0x144) when bit 0 of the value loaded from +0x400 of a0 (the `lw` at 0x11c) is set, and
  four-bit fields of the first word of the a1 block at +0x2a and +0x28 (the `sb` at 0x170 and
  0x180); it calls `strncpy` with a2, `.rodata`+16 and 0x10 as its first three arguments (the `jal`
  at 0x26c), and `i2cfp_DMI2_KernelEDID` with a1 and a2 as its first two arguments (the `jal` at
  0x334). It copies two halfwords from the table at the pointer in +0x30 of the record into +0x20
  and +0x22 (the `lh` at 0x280 and 0x288, the `sh` at 0x284 and 0x298), stores 0x1f0 at +0x24 (the
  `sw` at 0x290), and when the bytes at +0x2c and +0x2d are both nonzero, doubles the halfword at
  +0x22 (the `lhu` at 0x2a8 and the `sh` at 0x2b0). The byte at +0x2e picks the word at +0xe4: 0x82
  stores 0x4 (the `sw` at 0x2fc), 0x83 stores 0x9 (the `sw` at 0x350), and 0x84 stores 0xf (the `sw`
  at 0x318) unless the word at +4 of the table is 0x400 (the `beq` at 0x310). The word at
  `crm_fbdepth` picks 0x10 or 0x20 for the byte at +0x2f (the `sb` at 0x2e8 and 0x1fc), and when
  `physmem` is below 0x2001 it stores 0 at +0x2b and 0x10 at +0x2f (the `sb` at 0x210 and 0x214).
  When a3 is zero (the `beq` at 0x194) and the word at +0xe4 is still zero (the `beq` at 0x2c4), it
  calls `getNvramTiming` (the `jal` at 0x378) and stores the result at +0xe4 (the `sw` at 0x388). A
  nonzero result selects the `crimeVTimings` entry at 48 bytes per index and stores its address at
  +0x30 (the `sw` at 0x3ac); a zero result makes the word at +0xe4 `crm_default_vtiming` (the `sw`
  at 0x3d8) and stores the matching table address at +0x30 (the `sw` at 0x3ec). The loop from 0x234
  to 0x25c copies twelve words of the table at +0x30 into the record from +0x34 on, two words a pass
  (the `lw` at 0x23c and 0x250, the `sw` at 0x248 and 0x25c).
  Unknown: the register writes made by `getNvramTiming`, `crime_i2cFpProbe` and
  `i2cfp_DMI2_KernelEDID`, which have no committed entries.
  Evidence grade: inferred.
- `crimeRetraceHandler` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0xb80 (n32).
  Inferred: it is the per-board update that runs on the CRIME interrupt path, because it reads the
  CRIME Hardware Interrupt register at offset 0x28 (the `ld` at 0xbbc, linked row CRIME 0x28
  Hardware Interrupt) and works on one record under `mutex_lock` (the `jal` at 0xbb0) and
  `mutex_unlock` (the `jal` at 0xd34). It takes the lock at +0x348 of the record at +0x8c of its
  argument (the `jal` at 0xbb0, with 0x19 as the second argument). It reads the CRIME Hardware
  Interrupt register (the `ld` at 0xbbc), clears the 0x10000 bit with the mask 0xfffffffffffeffff
  (the `ori` at 0xbc4) and stores the result back (the `sd` at 0xbd4). It then writes the word at
  +0x10020 of the block at +0x80 of its argument (the `sw` at 0xbf4, in the delay slot of the
  `flushbus` call at 0xbf0) with the halfword at +0x8 of that record ORed with the halfword at +0xa
  shifted left by 0xc. It adds 1 to the doubleword at +0x0 of the record (the `ld` at 0xbf8 and the
  `sd` at 0xc04) and 1 to the word at +0x10 of the `gfxinfo` record (the `sw` at 0xc1c). When the
  word at `.sbss` +0x18 is nonzero it calls through it (the `jalr` at 0xc20) with the word at
  `.sbss` +0x1c as its argument (the `lw` at 0xc24). Further down it clears the word at +0x340 of
  the record (the `sw` at 0xcc0), calls `rrmValidateRetrace` (the `jal` at 0xcac),
  `crime_i2cFpGbeRetrace` with +0x344 of the record (the `jal` at 0xd08), `rrmValidateVideoSync`
  (the `jal` at 0xdf0), `rrmValidateBuffer` (the `jal` at 0xe28) and `rrmValidateMGRSwapBuf` (the
  `jal` at 0xfa4), and `vsema` on `crmswapsema` (the `jal` at 0xf90), under the conditions its
  branches select; it releases the lock with `mutex_unlock` and returns 0 (the return at 0xd44).
  Unknown: the value of the `.sbss` +0x18 word that the `jalr` at 0xc20 calls, which this routine
  only loads, and the bodies of `mutex_lock`, `mutex_unlock` and the `rrmValidate` callees, since
  the bundle has no notes for them.
  Evidence grade: inferred.
- `crime_hli_handler` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_retrace.o)` at 0x2a64 (n32).
  Inferred: it is a CRIME interrupt handler that works on one table slot of the structure at a0,
  since it reads and writes the CRIME Hardware Interrupt register at +0x28 (linked row) and walks
  record lists held in that structure. The entry argument a1 indexes the table that the pointer at
  a0+0x8c points to, and the word at +0x32c from the indexed slot (`lw` at 0x2a80, tested at 0x2a90)
  starts a record list that the walk follows through +0x14 (`lw` at 0x2aa8 and 0x2ac0). For each
  record whose +0x4 word is nonzero (`bne` at 0x2ab8), the walk calls through that word with the
  record's +0x8 word as a0 (`jalr` at 0x2aa0). When the word at +0x33c of the structure is nonzero,
  the slot's list head at +0x32c is replaced by it (`sw` at 0x2af0), the entry argument kept in s1
  is tested against 2 and 3 (0x2af4 and 0x2afc), a second list walk runs, and a word is written to
  +0x33c (`sw` at 0x2b40 and 0x2c00). For entry argument 2 the word at +0x328 of the structure is
  rewritten (`lw` at 0x2bc8, `sw` at 0x2be0) with its bits kept under the 8-byte constant at `.lit8`
  +0x8 (`ld` at 0x2bc4) and the low 0xfff bits of the record's +0xc word (at 0x2bcc) shifted left by
  0xc ORed in. For entry argument 3 the same word is rewritten (`sw` at 0x2c1c) with its low 0xfff
  bits replaced by that field, the rest kept by the mask -0x1000 (at 0x2c08). In both cases the new
  word is also written to 0x10024 past the pointer at a0+0x80 (`sw` at 0x2bf8 and 0x2c34). On every
  path that reaches 0x2b68 the routine loads the 8-byte Hardware Interrupt register at +0x28 into
  a0, then clears one bit of it chosen by the entry argument, one of four consecutive bits starting
  at bit sixteen: it ANDs the word with a mask whose upper half is 0xfffe for argument 0 (at
  0x2c38), 0xfffd for 1 (0x2c4c), 0xfffb for 2 (0x2b88) or 0xfff7 for 3 (0x2b94) and whose lower
  half is 0xffff; the `beq` tests at 0x2b74, 0x2b7c, 0x2b84 and 0x2b90 pick the case, and any other
  argument leaves the word as loaded. The low 32 bits of the result are written back to the Hardware
  Interrupt word in the delay slot of the common return at 0x2bac (`sd` at 0x2bb0).
  Unknown: which device the word at a0+0x80 plus 0x10024 belongs to, since the stores at 0x2bf8 and
  0x2c34 address it through a pointer the bundle does not follow; the route is the reviewed Hardware
  Interrupt field table.
  Unknown: the targets of the call at 0x2aa0, which are whatever the +0x4 words of the records hold.
  Evidence grade: inferred.
- `crime_init` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime.o)` at 0x5364 (n32).
  Inferred: it sets up one CRIME board record, because it allocates a 0x230-byte block with
  `kern_malloc` (the `jal` at 0x53bc), fills the block from the board table at `crimeBoards`, and
  passes the block to `GfxRegisterBoard` (the `jal` at 0x552c) and to the vector installs after it.
  It does nothing when the pointer at `crimeBoards`+0x8 is zero (the `beq` at 0x5380); otherwise it
  reads the byte at +0x2e of that record (the `lbu` at 0x5388). When that byte is 0x82, 0x83 or 0x84
  (the `beq` branches at 0x5390 to 0x53a0), the `sw` at 0x56ac clears `gbe_gammawar`; a byte that is
  nonzero and none of those goes to `cmn_err` first (the `jal` at 0x57c4). It calls
  `add_to_inventory` (the `jal` at 0x5400), calls it again when `crm_dc_board_installed` is nonzero
  (the `jal` at 0x5420), and tests the byte against 0x84 (the `beq` at 0x5430); when it matches, the
  routine calls `find_inventory` (the `jal` at 0x5708), then `replace_in_inventory` (the `jal` at
  0x5728) or `add_to_inventory` (the `jal` at 0x5748) on its result. It stores the word at
  `crimeBoards`+0x0 at +0x78 of the block (the `sw` at 0x53d8), the address 0x10 past `crimeBoards`
  at +0x90 (the `sw` at 0x53ec), the record at +0x7c (the `sw` at 0x53f8), the word at
  `crimeBoards`+0x4 at +0x80 (the `sw` at 0x5404), then 0x20 at +0x34, 1 at +0xc, and the `kvpalloc`
  result at +0x84 (the `sw` at 0x5468), which `bzero` clears for 0x600 bytes (the `jal` at 0x5464).
  It calls `init_mutex` on +468 and +476, `mrlock_init` on +484, `spinlock_init` on +540, `init_sv`
  on +556 and `init_mutex` on the global `crm_drawlock` (the `jal` calls at 0x5478 to 0x5514), then
  `crimeRetraceInit` on the block (the `jal` at 0x551c). It writes 0xffffff to the words at 0x10020
  and 0x10024 past the pointer at `crimeBoards`+0x4 (the `sw` at 0x557c and 0x5598), reads the
  8-byte CRIME register at offset 0x28 (the `ld` at 0x554c, linked row CRIME 0x28 Hardware
  Interrupt), clears the bits selected by the mask 0xfffffffffff0ffff (the `ori` at 0x5558) and
  writes the result back (the `sd` at 0x5564). It calls `setcrimevector` for vectors 0x10, 0x11,
  0x1a and 0x19 with `crimeRetraceHandler`, `crimePreblankHandler`, `crimeFifoFullHandler` and
  `crimeFifoEmptyHandler` (the `jal` calls at 0x55e0 to 0x5648), and for `crimeInterrupt` in a loop
  bounded by 0x4 (the `jal` at 0x55ac and the `bne` at 0x55c4); a nonzero return from any of these
  calls goes to `cmn_err` at level 0x4 (the `jal` calls at 0x575c to 0x57ac); after that it calls
  `crime_i2cProbe` (the `jal` at 0x5674), calls `crime_validate_ddc_data` only when the probe
  returns nonzero (the `beq` at 0x567c and the `jal` at 0x5684), and calls `gbeBlankScreen` after
  its monitor loops (the `jal` at 0x56e4).
  Unknown: the text of the messages passed to `cmn_err` at 0x575c to 0x57c4, and the work done
  inside `kern_malloc`, `setcrimevector` and the other callees, since the bundle has no strings and
  no notes for them.
  Evidence grade: inferred.
- `crime_intr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xa2cc (n32).
  Inferred: it works on the CRIME interrupt status at offset 0x10 (linked row `CRIME 0x10 Interrupt
  Status`; the reviewed datasheet gives that register at `0x14000010` as a read-only OR of hardware
  and software causes) and on a per-source table in `.data` with a 0x30-byte entry per source. It
  loads the doubleword at a0 +0x138 into s2 on entry (the `ld` at 0xa2f8), reads the status
  doubleword at `0xffffffffb4000010` (the `ld` at 0xa304) and ANDs the two, then branches through
  0xa56c to 0xa344 (the `beq` at 0xa31c and at 0xa570), skipping the loop head. On later passes the
  loop head at 0xa324 reads the status again (the `ld` at 0xa32c), ANDs it with s2 and branches to
  the epilogue at 0xa538 when the result is zero (the `beq` at 0xa338). A bit scan from 0xa344 to
  0xa3c0 walks the set bits of that result and, for each source, stores its number in a frame array
  at an index taken from a halfword of its table entry (the `lh` at 0xa370 and 0xa3a0, the `sw` at
  0xa364 and 0xa394), or -1 when its bit is clear; the dispatch from 0xa42c then takes the sources
  in that array order and skips the entries holding -1 (the `beq` at 0xa438). For each source the
  routine reads the word at table +0x98 (the `lw` at 0xa3d0 and 0xa44c), the doubleword at +0xa0
  (the `ld` at 0xa3d8 and 0xa474) and the halfword at +0x9e, which it tests against 0x4 (the `beq`
  at 0xa464 and at 0xa4c4), and calls `splint` with the word at +0x98 (the `jal` at 0xa3c8 and
  0xa4a0). The value loaded from +0x98 shifted right by 3 counts the doublewords of a table at
  absolute address -0x5d48 (the base register starts at zero) that three loops update one doubleword
  at a time (the `ld` at 0xa3f8, 0xa480 and 0xa518, the `sd` at 0xa40c, 0xa494 and 0xa52c). When bit
  0x1000 of the word at +0xa8 is set (the `bne` at 0xa498), the source is masked out: s2 is ANDed
  with the complement of the +0xa0 doubleword (the `and` in the delay slot at 0xa3f0), the same
  complement is ANDed into each counted table doubleword, `vsema` is called with the address table
  +172 (the `jal` at 0xa410) and `splx` with the value `splint` returned (the `jal` at 0xa418).
  Otherwise the routine first ANDs the complement into the counted table doublewords when the
  halfword at +0x9e has the 0x4 bit set (the loop from 0xa47c), then makes one call through the word
  at table +0x90 with arg0 and the word at table +0x94 (the `jalr` at 0xa4b4). If the 0x4 bit is
  set, it ANDs the complement into the doubleword at a0 +0x138 and into s2 (the `ld` at 0xa4d0, the
  `sd` at 0xa4dc); if it is clear, it ORs the +0xa0 doubleword into each counted table doubleword
  (the loop from 0xa514). Either way it calls `splx` with the `splint` value (the `jal` at 0xa4ec).
  On the epilogue path it stores s2 to a0 +0x138 (the `sd` at 0xa540), which differs from the value
  read at 0xa2f8 by the bits ANDed out at 0xa3f0 and 0xa4e8.
  Unknown: the device-side result of the calls to `splint`, `vsema` and `splx`, and the target of
  the call through a register at 0xa4b4, which is whatever the table holds at +0x90; none of the
  callees has a committed entry, so the route is their own entries and the table contents.
  Evidence grade: inferred.
- `crime_setvideotiming` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x119c (n32).
  Before the key test it copies twelve words of the table at +0x30 of the record at a1 into its
  frame (the loop at 0x11e8 to 0x1210) and saves the +0xe4 value there as a doubleword (the `sd` at
  0x122c). Takes the word at [a2] as a key, and when the key is 0xd (the `beq` at 0x1228) the path
  at 0x1390 returns 0x16 after a `cmn_err` call (the `jal` at 0x1468) when a0 is nonzero and bit 0x2
  of the byte at +0x98 of a0 is clear (the `lbu` at 0x1398), and otherwise returns 0x16 when the
  byte at +0x2b of a1 is nonzero (the `lbu` at 0x13a8) and goes on to the range test when it is
  zero. When the key is above zero and below 0x10 (`blez` at 0x1230, `slti` at 0x1234), the routine
  scans the 0x30-byte entries of `crimeVTimings` from +0x60, comparing each entry's first word with
  the key while the pass count in a6 is below 0x10 (`bne` at 0x125c). A match whose entry has a
  nonzero halfword at +0x14 (`lh` at 0x1378, `beq` at 0x137c) stores the entry pointer at +0x30 and
  the pass count at +0xe4 of the record at a1 (`sw` at 0x1384 and 0x138c). A match with a zero
  halfword at +0x14 returns 0x16 at 0x145c without those two stores. A key outside that range, or a
  key with no match, calls crmInvalidVideoTiming (`jal` at 0x1264), and the routine returns 0x16
  when that call returns nonzero (`beq` at 0x126c, `addiu` at 0x1278). When that call returns zero,
  a loop of loads and stores at 0x1298 to 0x12c0 copies twelve words of the key block at a2 into the
  record at a1 from +0x34, and the routine stores the address a1+0x34 at +0x30 and 0x10 at +0xe4
  (`sw` at 0x12c4 and 0x12c8). The matched and the unmatched paths then call crimeInitInfo with the
  words at `crimeBoards` +0 and +4 and a1, with a3 set to 1 (`jal` at 0x12d8), and call crmResizeFb
  with the word at +0x30 of a1 as its first argument (`jal` at 0x12e0). When crmResizeFb returns
  nonzero (the `beq` at 0x12e8 falls through), the routine copies the twelve saved words back over
  the table at +0x30 (the loop at 0x130c to 0x1334), calls crimeInitInfo again with the saved +0xe4
  word stored in its delay slot (the `sw` at 0x1350, the `jal` at 0x134c) and returns the
  crmResizeFb result. When crmResizeFb returns zero (0x13bc), and a0 and the word at +0x1c4 of a0
  are nonzero, it walks the list that starts at that word through +0x14 of each element and, for
  each element, writes into the record at +0x4c the halfword at +0x27c from the halfword at +0x8 of
  the table at +0x30 (the `sh` at 0x13fc), the halfword at +0x27e from the halfword at +0xa (the
  `sh` at 0x140c) and the word at +0x280 from the word at +0xc (the `sw` at 0x141c). It sets or
  clears bit 0x1 of the halfword at +0x284 (the `sh` at 0x13e0 and 0x1440) according to bit 0x2 of
  the table's +0x4 field. It then calls gbeRun with the word at `crimeBoards` +4, a1 and a2 (`jal`
  at 0x144c) and returns 0.
  Unknown: the register writes of crimeInitInfo, crmResizeFb, gbeRun and crmInvalidVideoTiming (no
  committed entries).
  Evidence grade: established.
- `crimevec_intrd` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xaea8 (n32).
  Its field loads go to the record at its first argument `a0`, its stores go to its frame and to a
  table at an absolute address, and it makes an indirect call and a `splhi`/`splx` bracket, calling
  `ipsema` on the record at `a0` plus 0x1c. It loads the 4-byte word at +0x0 into `at` at 0xaeb4,
  the word at +0x4 into `a1` at 0xaec4, the halfword at +0xe into `v0` at 0xaed4, the word at +0x8
  into `a5` at 0xaee4, and the doubleword at +0x10 into `a6` at 0xaef8. Before the `splhi` call at
  0xaec8 it calls through the word at +0x0 that it loaded into `at` (the `jalr` at 0xaec0) with `a0`
  set to 0x0 and `a1` taken from +0x4 in the delay slot, and the `splhi` result is kept in `a0` for
  the later `splx` call. Bit 0x4 of the halfword at +0xe, tested at 0xaedc, sends the routine
  straight to the `splx` call at 0xaf18; if that bit is clear, `a5` is the word at +0x8 shifted
  right by 3 (at 0xaee8), and a value of 0 or less does the same at 0xaef0, while a positive value
  enters the loop at 0xaefc. The loop runs while `a4`, which starts at 0x0 at 0xaeec and gains 1
  each pass, is less than `a5` (signed). Each pass loads the doubleword at `a3` plus -0x5d48 (the
  `ld` at 0xaf00), ORs in the doubleword from +0x10, and stores the result back to the same slot
  (the `sd` at 0xaf14, in the delay slot of the branch at 0xaf10, after `a3` has stepped by 8 at
  0xaf08); `a3` starts at 0x0 from the delay slot at 0xaef4, so the loop sets the bits of the +0x10
  doubleword in the first `a5` doublewords of the table at the absolute address -0x5d48. Every path
  reaches the `splx` call at 0xaf18 and then the `ipsema` call at 0xaf20, and the return at 0xaf30
  leaves `v0` as `ipsema` returned it.
  Unknown: the layout of the record the caller passes in and the target the caller stores at its
  +0x0 word, which a committed entry for the caller that fills the record would settle.
  Evidence grade: established.
- `delay_calibrate` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x141a4 (n32).
  Inferred: it measures how far the CRIME timer at offset 0x38 (linked row `CRIME 0x38 Crime Timer`;
  the reviewed datasheet gives it as a 32-bit counter with reset zero) advances across counted
  loops, because it reads the timer before and after the loops and subtracts the two reads. It loads
  the doubleword at `0xffffffffb4000038` into t2 at the top of each outer pass (the `ld` at 0x141b4)
  and again into v0 after the inner loop (the `ld` at 0x141dc). There are two outer passes: t3 is
  set to 0x2 at 0x141b0, decremented at 0x141e4 and tested by the `bgtz` at 0x141ec. The inner loop
  (0x141b8 to 0x141d8) runs while t1 is positive, counting t1 down by the `addiu` in its delay slot
  at 0x141d8; t1 starts at 1, so the first pass spins twice, and is set to 0x1869f at 0x141e8 for
  the second pass. The `dsubu` in the delay slot at 0x141f0 sets v0 to v0 minus t2 on every outer
  pass, so the difference of the second pass is what remains. The routine then multiplies that
  difference by fifteen (a shift left by 4 and a subtraction of the difference), divides the product
  by 0x186a0, built at 0x14204, with an unsigned divide, and stores the quotient as a 4-byte word to
  `0xffffffffffffa248` (the `sw` at 0x14210); the quotient is also the value in v0 at the return at
  0x14220. The `bne` at 0x14214 tests the divisor and skips the break instruction at 0x1421c, which
  is a divide-by-zero guard.
  Unknown: the reader of the word at `0xffffffffffffa248`, since the bundle shows only its store at
  0x14210; the route is that reader's entry or a trace of that address.
  Unknown: how the 8-byte read at `0xffffffffb4000038` covers the 32-bit counter, and the tick rate,
  which the excerpt leaves for review; the route is the linked spec row for offset 0x38.
  Evidence grade: inferred.
- `early_gbe_stop` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x8504 (n32).
  Inferred: it works on the GBE registers that the linked rows name `FRM_2`, `FRM_3`, `OVR_1`, `OVR_2`, `DID`, `DID_SHADOW`, `DOTCLK` and `VT_0`, and the bits it tests are DMA-enable fields that the reviewed GBE datasheet gives for those registers: bit 0 of FRM_2 and OVR_1, and the 0x10000 bit of DID. It reads FRM_2 at `0xffffffffb6030008` (the `lw` at 0x8518); when bit 0 is clear (the `beq` at 0x853c) it reads OVR_1 (the `lw` at 0x870c) and DID (the `lw` at 0x8720), enters the call path at 0x8548 when OVR_1 bit 0 is set (the `bne` at 0x8718) or DID's 0x10000 bit is set (the shift by 0x2f and the `bltz` at 0x8728), and otherwise returns at 0x8704. The call path calls `flushbus` at 0x8548, 0x8560, 0x857c and 0x8598, stores into FRM_3, OVR_2 and DID_SHADOW in the delay slots of the calls at 0x8560, 0x857c and 0x8598 (the `sw` at 0x8564, 0x8580 and 0x859c), and sets a1 to 0x61a80 (the `ori` at 0x85a8). The first poll loop (0x85ac to 0x861c) repeats while FRM_2 bit 0, OVR_1 bit 0 or the DID 0x10000 bit is set, counts a1 down on each pass, and leaves for 0x8624 when all three are clear or a1 is zero or below (the `blez` at 0x85ac and 0x85c4). From 0x8624 it adds 0x20 to FRM_3, OVR_2 and DID_SHADOW in turn (the `addiu` at 0x862c, 0x863c and 0x8654), stores each sum in the delay slot of its `flushbus` call (the `sw` at 0x8634, 0x8644 and 0x865c), resets a1 to 0x61a80 at 0x8668, and repeats a second loop (0x866c to 0x86c0) until FRM_2 equals FRM_3 plus 0x20, OVR_1 equals OVR_2 plus 0x20 and DID equals DID_SHADOW plus 0x20 (the `bne` at 0x8678 and 0x8684 and the `beq` at 0x8690), or until a1 runs out (the `blez` at 0x866c and 0x8698). At 0x86c4 it writes 0xffffffff80000000 (set in t3 at 0x86c4) to `0xffffffffb6010000` (the `sw` at 0x86cc), and it reads `0xffffffffb6000004` into t0 (the `lw` at 0x86d4) and stores t0 back to it in the delay slot of the call at 0x86e0 (the `sw` at 0x86e4); the return at 0x8704 gives the v0 that `flushbus` returned. Unknown: which bit of VT_0 the value 0xffffffff80000000 sets, since the reviewed datasheet names a freeze bit without its position, and the field layout of DOTCLK, which no reviewed excerpt names; the route is the linked spec rows for VT_0 and DOTCLK. Unknown: the device-side result of the four `flushbus` calls, whether the word stored at 0x86e4 equals the word loaded at 0x86d4, and the v0 left by the path that leaves at 0x8730; the route is the `flushbus` entry and the listing of those addresses.
  Evidence grade: inferred.
- `earlybaerror` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x14a0c (n32).
  Writes zero to two words in the block at 0xffffffffb4000000, to the word at 0xffffffffbf080004 and to the
  word at the `nofault` symbol, then returns 1 in v0 at the `jr ra` at 0x14a5c.
  Inferred: the linked rows name offset 0x250 of that block Memory Error Status (CRIME 0x250), so
  the zero stored by the `sd` at 0x14a14 is a write to that status word, and the `ld` at 0x14a18
  reads it back.
  The `ld` at 0x14a1c and the `lw` at 0x14a2c read back the words at +0x48 and 0xffffffffbf080004, and no
  branch in the routine tests any value read back.
  Unknown: the name of the register at +0x48, since the linked row gives none; the datasheet entry
  for that offset would settle it.
  Unknown: which device answers at 0xffffffffbf080004, since no linked row or excerpt in the bundle covers
  that address; a linked mmio row or a reviewed datasheet excerpt for it would settle it.
  Unknown: the definition of the `nofault` symbol, which the object's symbol table would settle;
  the `sw` at 0x14a4c is the only access that uses it.
  Unknown: the caller of this routine and the condition under which it runs, which the inventory
  entries for the callers would settle.
  Evidence grade: inferred.
- `ecc_enable` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x920c (n32).
  Inferred: the linked row names CRIME offset 0x200 MC Status/Control, so this routine writes the
  value 1 to that word at 0xffffffffb4000200 (the `sd` at 0x9254), and only when two cached words
  are both nonzero. The first call, to `is_specified` at 0x9218, takes `arg_ecc_enabled` as a0 and
  passes the caller's a1 to a3 through; when it returns nonzero, the call to `is_enabled` at 0x9228
  runs and its return value is stored in `ecc_checking_enabled` (the `sw` at 0x9230). When
  `is_specified` returns zero, the call and the store are skipped, `ecc_checking_enabled` keeps its
  earlier value, and v0 returns zero; otherwise v0 returns the value of `is_enabled`. The `lw` at
  0x9234 loads `ecc_meminited` and the `lw` at 0x923c loads `ecc_checking_enabled`, and the store
  runs only when both are nonzero (the `beq` at 0x9244 and at 0x924c). The store writes a3, set to 1
  at 0x9238, through a2, which is set to 0xffffffffb4000000 at 0x9248.
  Unknown: which field of the register at +0x200 the value 1 sets, since the excerpts give the
  address map around that word but no field table; the field table for that register in the reviewed
  CRIME datasheet would settle it.
  Unknown: the content of `arg_ecc_enabled`, `is_specified` and `is_enabled`, which their committed
  entries would settle; the bundle has none beyond the facts-only reading.
  Unknown: the values of a1 to a3 at the call to `is_enabled`, which the bundle does not resolve,
  since the call to `is_specified` comes first.
  Evidence grade: inferred.
- `ecc_error_correction` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xff50 (n32).
  Inferred: the linked row names CRIME offset 0x250 Memory Error Status, and this routine writes
  zero to that word at 0xffffffffb4000250 in the delay slot of the call to `splxecc` (the `sd` at
  0xffd8), so the sequence acts on that status word. It returns 0 at once when the sign of a3
  shifted left by 0x2a is negative (the `bgez` at 0xff58), and otherwise masks a3 with 0x1900000
  into a5 (the `lui` at 0xff6c) and compares the result with 0x900000 (the `beq` at 0xff84) and with
  0x1100000 (the `beq` at 0xff8c), entering the sequence only on a match and returning 0 otherwise.
  The sequence calls `splecc` with a4 set to 0x1100000, then `map_physaddr` with the entry a0 with
  its low three bits cleared (mask -0x8) and ORed with 0x40000000 (done in the delay slot of the
  call at 0xffb8), then `scrub_memory` on the mapped address, then `splxecc` with a2 set to
  0xffffffffb4000000 and splecc's return value as a0, and finally `unmap_physaddr` on the mapped
  address. The routine tests none of the callee return values, and its normal return is 1, the value
  set in the delay slot of the branch at 0xffe8.
  Unknown: the content of `splecc`, `map_physaddr`, `scrub_memory`, `splxecc` and `unmap_physaddr`,
  which a committed entry for each would settle; the bundle has no committed entry for any of them.
  Unknown: which window 0x40000000 selects in CRIME's address map, since the excerpts for this
  routine give no address map; the reviewed CRIME address-map table would settle it.
  Unknown: whether writing zero at 0xffffffffb4000250 clears bits 25 to 27 of Memory Error Status,
  which the field access column for that register on PDF pages 152 to 153 would settle; the excerpts
  name those bits as invalid-address flags.
  Evidence grade: inferred.
- `ecc_fixmem` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xddec (n32).
  Copies one of two words from the `.bss` table at offset 6144, plus a0 records of seven times
  sixteen bytes (a0 times seven, then shifted left by 4, at the start of the routine), into the
  caller's buffer at a2 +0x8, then fills table words with the constant 0xffffffffdeadbeef and
  returns 1. Inferred: the linked row names the word at CRIME offset 0x260 ECC Syndrome Bits, so the
  `ld` at 0xde3c reads that register at 0xffffffffb4000260 and the `sw` at 0xde48 keeps its low word
  at table +0x8c. The routine branches on the sign of `r4000_config` shifted left by 0x2e (the
  `bgez` at 0xde14): when it is non-negative, the `lw` at 0xde4c loads table +0x78 and the `sd` at
  0xde5c stores it at a2 +0x8; when it is negative, the `lw` at 0xde1c loads table +0x7c and the
  `sd` at 0xde28 stores it at a2 +0x8. Both paths reach the same tail at 0xde2c, which writes
  0xffffffffdeadbeef to table +0x84 and +0x88 (the `sw` at 0xde30 and 0xde34), reads the 8-byte
  value at 0xffffffffb4000260, stores its low word at table +0x8c, and returns 1 at the `jr ra` at
  0xde44. Two loads feed no store: the 8-byte load from table +0x68 at 0xde18 and the word load from
  table +0x80 at 0xde2c.
  Unknown: which configuration field the sign test at 0xde14 reads, since the bundle has no field
  table for `r4000_config`; the field table for that CPU configuration register would settle it.
  Unknown: the consumer of the table words at +0x68 to +0x8c, which the callers' entries would
  settle.
  Evidence grade: inferred.
- `gbeRun` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x1510 (n32).
  Does not touch the device through its own loads and stores, which use only its frame and the
  records at a1 and a2; it sequences the calls to crm_callvideo, gbeStop, gbeSetTimingRegs,
  crmLoadGbelists, gbeCacheVtInfo and gbeStartVideoTiming. On every path it calls crm_callvideo with
  0x1 in a1 (`jal` at 0x1530), gbeStop with three pointers into its frame at sp-48, sp-44 and sp-40
  (`jal` at 0x1544), and gbeSetTimingRegs with a0 and a1 passed through (`jal` at 0x1550). When a2
  is nonzero (the `beq` at 0x1558 falls through), it calls crmLoadGbelists with a2 (`jal` at 0x1560)
  and gbeCacheVtInfo with a2 and the word at +0x30 of a1 (`jal` at 0x156c). It then loads the
  pointer at +0x84 of a2 (`lw` at 0x1578) and calls gbeStartVideoTiming with a0, the word at +0x30
  of a1, the words at +0x4c and +0x4 of that pointer as its third and fourth arguments and the frame
  word at sp-40 as its fifth (`lw` at 0x1574, `jal` at 0x1588). When a2 is zero, the branch at
  0x1558 goes to 0x15b4, which calls gbeStartVideoTiming with a0, the word at +0x30 of a1, and the
  frame words at sp-48, sp-44 and sp-40 as its third, fourth and fifth arguments (`lw` at 0x15b4,
  0x15b8 and 0x15c4, `jal` at 0x15c0). Both paths then reach 0x1594, which calls crm_callvideo with
  0x2 (`jal` at 0x159c) and returns the value of that call (`jr ra` at 0x15ac).
  Unknown: the values that gbeStop writes into sp-48, sp-44 and sp-40, since gbeStop has no
  committed entry; its entry would settle the values gbeStartVideoTiming receives on the zero path.
  Evidence grade: established.
- `gbeStartVideoTiming` in `IP32/usr/cpu/sysgen/IP32boot/crime.a(crime_init.o)` at 0x974 (n32).
  Inferred: it programs fields of the table at a1 into device blocks at a0+0x10000, a0+0x20000,
  a0+0x30000 and a0+0x40000, because it stores values built from halfwords of that table and
  constants into those blocks and polls status words at +0x30008, +0x20004 and +0x10000 between the
  writes. It reads the 8-byte CRIME register at offset 0x28 at entry (the `ld` at 0x98c), clears the
  0x10000 bit with the mask 0xfffffffffffeffff (the `ori` at 0x9a0) and writes the result back to
  the register in the delay slot of the first `flushbus` call (the `sd` at 0x9c8, after the `jal` at
  0x9c4). It then stores 0xffffff at +0x10038 and +0x10034 (the `sw` at 0x9e4 and 0x9ec) and a word
  built from the halfword at +0x14 of the table masked with 0xfff and the halfword at +0x1e shifted
  left by 0xc at +0x10004 (the `lh` at 0x9f0 and 0x9f4, the `sw` at 0xa0c). Each of the five
  `flushbus` calls (the `jal` at 0x9c4, 0x9e8, 0xa1c, 0xa38 and 0xa58) has one store in its delay
  slot; the stores at 0xa20 and 0xa3c set bit 0x8000 of the word at +0x30000 and bit 0x2000 of the
  word at +0x20000, and the stores at 0xa28 and 0xa40 write the saved words back. It then stores a2,
  a3 and a4 at +0x3000c, +0x20008 and +0x40004 (the `sw` at 0xa48, 0xa50 and 0xa5c), the last in the
  delay slot of the flush at 0xa58. It polls the word at +0x30008 (the `lw` at 0xa98 and 0xac0) with
  `us_delay` of 1 between passes (the `jal` at 0xab8) until its low bit equals the low bit of a2
  (the `andi` at 0xa74 and the `beq` at 0xab0), then the word at +0x20004 (the `lw` at 0xad0 and
  0xaf0) with `us_delay` of 1 (the `jal` at 0xae8) until its low bit equals the low bit of a3 (the
  `andi` at 0xad4 and the `beq` at 0xae0). The last poll reads the word at +0x10000 (the `lw` at
  0xb04, 0xb24, 0xb34 and 0xb4c) and compares it with the halfword at +0x20 of the table (the `lh`
  at 0xb00, 0xb20 and 0xb50): it waits with `us_delay` of 1 (the `jal` at 0xb18) while the word is
  not below that halfword, then waits (the `jal` at 0xb44) while it is not above it. On exit it
  stores two words built from table halfwords at +0x10034 and +0x10038 (the `sw` at 0xb68 and
  0xb6c): the second is the halfword at +0x20 masked with 0xfff ORed with the halfword at +0x22
  masked with 0xfff and shifted left by 0xc, and the first combines the halfword at +0x18 less a
  constant, wrapped by adding the halfword at +0x14 when negative and shifted left by 0xc, with the
  remainder of a division by the halfword at +0x14.
  Unknown: which device the blocks at a0+0x10000, a0+0x20000, a0+0x30000 and a0+0x40000 belong to,
  since the bundle has no linked rows for them.
  Evidence grade: inferred.
- `get_crimerev` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x11838 (n32).
  Returns a code chosen by the low four bits and the upper word of the CRIME word at offset 0, and
  stores that code at `_prom_cleared` +0xf4 (the `sw` instructions at 0x11878, 0x1188c and 0x11894),
  except on the path where the flag is zero.
  When the flag word at `_prom_cleared` +0xf8 is zero (the `beq` at 0x11844), the routine returns
  the word at `_prom_cleared` +0xf4 that the `lw` at 0x11840 loaded, and it stores nothing.
  Otherwise it clears the flag word (the `sw` at 0x11858), so the later calls take the first path.
  Inferred: the linked row names CRIME offset 0x0 ID-Revision, so the `ld` at 0x1184c reads that
  word at 0xffffffffb4000000, the value masked with 0xf at 0x11850 is its low four bits, and the
  upper 32 bits, shifted down into a2 at 0x11854, are the second input.
  When the masked value is zero, the `beq` at 0x1185c goes to 0x11868 with v0 at zero; otherwise
  v0 is set to 0x11 at 0x11864 before it reaches 0x11868.
  With the upper word zero (the `beq` at 0x11868), the routine returns v0, which is 0 or 0x11 by the
  masked value, and stores it at +0xf4 in the delay slot of the return at 0x11890; with the upper word
  equal to the constant 1 set at 0x1183c (the `beq` at 0x11870), it returns 0x13 and stores that;
  otherwise it stores and returns 0x14.
  Unknown: how the flag word at `_prom_cleared` +0xf8 is set, since this routine only clears it; the
  other stores to that word in the object would settle it.
  Unknown: the callers' handling of the codes 0x11, 0x13 and 0x14, which the callers' entries
  would settle.
  Evidence grade: inferred.
- `intr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xa578 (n32).
  Inferred: it services CRIME interrupt causes, reading the Interrupt Status register at
  0xffffffffb4000010 (the `ld` at 0xa5d4, linked row CRIME 0x10 Interrupt Status) and the Software
  Interrupt register at 0xffffffffb4000020 (the `ld` at 0xa6bc, linked row CRIME 0x20 Software
  Interrupt). On every path it reads the doubleword at +0x138 of the argument `a0` into fp (the `ld`
  at 0xa5c8), keeps only its low 32 bits with a mask built from -1 shifted right by 32 in `ra` (at
  0xa5cc and 0xa5d8, applied just before the store) and writes the masked value back to that
  doubleword (the `sd` at 0xa5e8), which clears its upper word. The bit tested on entry is 0x20 of
  the doubleword at 0xffffffffffffa100 (the `ld` at 0xa58c and the `bne` at 0xa5ac); when it is set
  the routine calls `log_tstamp_event` with 0x66 (the `jal` at 0xa798) and rejoins the main path at
  0xa5b8, and the same bit test at 0xa71c leads to a call with 0x65 (the `jal` at 0xa7b4) and then
  the exit. The doubleword read from 0xffffffffb4000010 at 0xa5d4 is saved at sp+0x20 (the `sd` at
  0xa5f4), reloaded at 0xa640, and tested against zero by the `beq` at 0xa654. Inferred: the store
  at 0xa700 writes `v0` to 0xffffffffb4000020 only when `a6`, which is `v0` ANDed with 0x30000000
  (the `and` at 0xa6ec), is nonzero (the `beq` at 0xa6f8 skips it otherwise); `v0` is the Software
  Interrupt word read at 0xa6bc, after the `sll v0,v0,0x0` at 0xa6d4, with 0x10000000 ORed in on the
  path at 0xa76c or 0x20000000 on the path at 0xa778, which the counters `cause_ip5_count` and
  `cause_ip6_count` and two `.sdata` words select; the mask covers bits 28 and 29, which the
  datasheet calls the software causes (the 0x14000020 row). The loop at 0xa600 calls through the
  first word of the table entry that s2 points to (the `lw` at 0xa604 and the `jalr` at 0xa60c),
  then calls `splx` at 0xa614, `getcause` at 0xa62c and `splint` at 0xa678, and branches back to
  0xa600 under the tests at 0xa684 and 0xa68c. It returns 0 or 1 in `v0` at the `jr ra` at 0xa750,
  after reloading the saved registers from the frame (0xa724 to 0xa74c). Unknown: the value of the
  table word that the call at 0xa60c uses, the values `getcause` returns into the test at 0xa644,
  and the value `splx` is given; committed entries for `getcause`, `splx`, `splint` and the call
  target would settle these.
  Evidence grade: inferred.
- `isa_dma_buf_init` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x9010 (n32).
  Reads the global word `isa_dma_buf_addr` through `gp` at 0x9010; when that word is zero it calls
  `contig_memalloc` and stores the shifted result into the word, and on every path it writes to the
  8-byte location at 0xffffffffbf310000 and calls `flushbus` with the word in `a1`. The `beq` at
  0x9018 branches to 0x9048 when `a1` is zero and falls through to 0x9020 otherwise, and the `sd
  ra,0(sp)` at 0x901c runs on both paths. On the zero path, `contig_memalloc` is called at 0x9054
  with `a0` and `a1` set to 0x8 and `a2` set to 0x18000110, and the `sw` at 0x9064, in the delay
  slot of the test at 0x9060, stores `a3`, the result shifted left by 0xc, to the global word on
  both outcomes of that test. When the shifted value is zero, the test branches to 0x9070, where
  `panic` is called at 0x9074 with `a3` at that zero and a `.rodata` address adjusted by 2904 in its
  delay slot; if `panic` returns, control continues at 0x9068, where the delay slot reloads `a1`
  from the global word at 0x906c. At 0x9020 the routine ANDs the buffer address in `a1` with the
  mask -0x8000 set there, which clears the low fifteen bits, zero-extends the result from 32 bits
  with a pair of shifts by 32, sets `v0` to 0xffffffffbf310000 (at 0x902c), and the `sd` at 0x9038
  writes the masked address to that location in the delay slot of the `flushbus` call at 0x9034.
  Inferred: the hostfacts output lists 0xffffffffbf310000 under addresses outside the file
  (memory-mapped I/O), so the 8-byte store at 0x9038 is a store to memory-mapped I/O. After `ra` is
  restored at 0x903c, the return at 0x9040 leaves `v0` as `flushbus` returned it.
  Unknown: the content of `contig_memalloc` and `flushbus`, the device-side result of the 8-byte
  store to 0xffffffffbf310000, and the text behind the `panic` address, which need their committed
  entries, a reviewed datasheet excerpt naming that address, and a string read from the binary.
  Evidence grade: inferred.
- `isbadclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12ebc (n32).
  Reports bit 0 of the byte register at 0xffffffffbf3a0e07 after one byte write to
  0xffffffffbf3a0a07, bracketed by calls to `splhi` and `splx`. The `jal` at 0x12ed4 reads
  0xffffffffbf3a0a07 and the `jal` at 0x12eec writes that byte back ANDed with -0x11 (set at
  0x12ee0), which clears the 0x10 bit, and masked to a byte in the delay slot. The `splhi` return is
  stored at +0x10 (`sd` at 0x12ed0) and reloaded into `a0` by the `ld` at 0x12f08, in the delay slot
  of the `jal` at 0x12f04 that calls `splx`. The read at 0x12ef8 of 0xffffffffbf3a0e07 is stored at
  +0x8 (`sd` at 0x12f00) and reloaded into `v0` at 0x12f10, and the `andi` with 0x1 in the return
  delay slot at 0x12f1c leaves 0 or 1 for the `jr ra` at 0x12f18. Inferred: `splhi` and `splx` read
  as an interrupt-level raise and restore, and `pciio_pio_read8` and `pciio_pio_write8` as byte-wide
  device accesses, going by their symbol names with no callee note to confirm either. Unknown: the
  register name and bit fields of the byte at 0xffffffffbf3a0e07 whose bit 0 is returned, and the
  device-side result of clearing the 0x10 bit of 0xffffffffbf3a0a07; a reviewed datasheet register
  table for the block at 0xffffffffbf3a0000 would settle the first, and the same table with its
  write rules would settle the second.
  Evidence grade: inferred.
- `kpreemption` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x19c (n32).
  Inferred: it acts on the CRIME Interrupt Enable register at 0xffffffffb4000018, which the linked row
  names CRIME 0x18 Interrupt Enable, and it writes into that register the doubleword at s4-0x5d48 before
  it tail-jumps to `exception_leave`. It starts with a call to `kpswtch` at 0x19c that passes the four
  argument registers through, and its delay slot is a nop. After that it stores `s4` to the word at
  0xffffffffffffa2e0 (the `sw` at 0x1c8), loads the doubleword at s4-0x5d48 into `a0` (the `ld` at
  0x1cc), and stores `a0` to 0xffffffffb4000018 (the `sd` at 0x1d8, with `k1` set to that address at
  0x1d0 and 0x1d4). The tail jump at 0x1e0 passes that doubleword to `exception_leave` in `a0`, with
  `a1` to `a3` unresolved. The range from 0x1e8 to 0x1fc is not reached by any path from the entry.
  Unknown: the handling by `exception_leave` of the doubleword in `a0` and of the values in `a1` to `a3`;
  a committed entry for `exception_leave` would settle it. Unknown: the work done by `kpswtch` and the
  value it returns, since no committed entry exists for it; an entry for `kpswtch` would settle it.
  Evidence grade: inferred.
- `power_dump` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x112e0 (n32).
  Runs a byte-register sequence on 0xffffffffbf3a0a07 and 0xffffffffbf3a4a07 between `splprof` and
  `splx`, when its argument `a0` is zero or the 8-byte word at 0xffffffffbf310010 has bit 0x100 set
  (`beq` at 0x11304 and `beq` at 0x11314). First it loads `power_dump_crash` and stores that value
  plus one in the delay slot of the `jal` at 0x11328, which calls `us_delay` with 0x7a120. The
  register traffic that follows is a read of 0xffffffffbf3a0a07 and a write back with 0x10 ORed in
  (`jal` at 0x11338 and 0x11348), a bus flush (`jal` at 0x11350), two reads of 0xffffffffbf3a4a07
  (`jal` at 0x11360 and 0x1136c) with the first result stored at +0x0 (`sw` at 0x11368), a write
  back of the second read ANDed with -0x8 and masked to a byte to 0xffffffffbf3a4a07 (`jal` at
  0x11380), a read of 0xffffffffbf3a0a07 and a write back ANDed with -0x11, which clears the 0x10
  bit (`jal` at 0x11388 and 0x1139c), and a final bus flush (`jal` at 0x113a4). Both paths that run
  the sequence then call `cmn_err_tag` with tag 0x3d (`jal` at 0x113c8) and `splx` (`jal` at
  0x113d0), while a nonzero argument with bit 0x100 clear goes straight to `splx` (`jal` at
  0x11400), and the routine returns the `splx` result (`jr ra` at 0x113ec). Inferred: by their
  symbol names, `splprof` and `splx` raise and restore the interrupt level, `us_delay` is a timed
  wait, and `pciio_pio_read8` and `pciio_pio_write8` are single-byte device accesses; the bundle has
  no callee note for any of them. Unknown: the bit fields of the registers at 0xffffffffbf3a0a07 and
  0xffffffffbf3a4a07 and of the 8-byte word at 0xffffffffbf310010 are open; a reviewed datasheet's
  register table for the blocks at 0xffffffffbf3a0000 and 0xffffffffbf310000 would close them.
  Evidence grade: inferred.
- `powerintr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x11410 (n32).
  Returns without touching the device unless bit 0x100 of the 8-byte word at 0xffffffffbf310010 is
  set (`beq` at 0x11428); when it is set and `power_button_changed_to_crash_dump` is nonzero (`beq`
  at 0x11430) it calls `power_dump` with `a0` = 0 (`jal` at 0x11438), and a zero value skips that
  call. Next it reads the byte at 0xffffffffbf3a0c07 (`lbu` at 0x11444), and when bit 0x80 of that
  byte is clear it calls `cmn_err` with 4 (`jal` at 0x11578) before the register pass. The register
  pass reads 0xffffffffbf3a0a07 (`jal` at 0x1145c), writes it back with 0x10 ORed in (`jal` at
  0x1146c) and flushes (`jal` at 0x11474), reads 0xffffffffbf3a4a07 twice (`jal` at 0x11484 and
  0x11490), writes the second read of 0xffffffffbf3a4a07 back ANDed with -0x8 and masked to a byte
  (`jal` at 0x114a4), reads 0xffffffffbf3a0a07 and writes it back ANDed with -0x11, which clears the
  0x10 bit (`jal` at 0x114b0 and 0x114c4), and flushes again (`jal` at 0x114cc). It then tests bit 0
  of the `pciio_pio_read8` return that the tool ties to `s2` (`beq` at 0x114dc): when that bit is
  clear, two `cmn_err` calls run (`jal` at 0x11594 and 0x115ac, the second passing that return as
  `a2`) and the routine returns (`jr ra` at 0x11500). When the bit is set it stores 1 to
  `power_off_flag` (`sw` at 0x114ec) and tests the word at +0x104 of `flash_env_seg`: when that word
  is zero it calls `flash_led` with 3 and 1 (`jal` at 0x11508), `sigtopid` (`jal` at 0x11524),
  `timeout` (`jal` at 0x1154c) and `set_autopoweron` (`jal` at 0x1155c), and stores `lbolt` plus 100
  back to +0x104 (`sw` at 0x11560); when that word is nonzero and below `lbolt` (`bne` at 0x114f4)
  it calls `us_delay` with 0x2710 (`jal` at 0x115bc), `cmn_err` with 5 (`jal` at 0x115d0) and
  `cpu_powerdown` (`jal` at 0x115d8). Inferred: `cpu_powerdown`, `set_autopoweron`, `sigtopid` and
  `flash_led` read as power-control and indicator calls, going by their symbol names with no callee
  note to confirm. Unknown: the register names and bit fields behind 0xffffffffbf3a0c07,
  0xffffffffbf310010 and the word at +0x104 of `flash_env_seg`, and the device-side result of the
  `cpu_powerdown` call; a reviewed datasheet register table for the blocks at 0xffffffffbf3a0000 and
  0xffffffffbf310000 would settle the first two.
  Evidence grade: inferred.
- `read_dallas_nvram` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12c28 (n32).
  Copies a2 bytes read from the byte registers at 0xffffffffbf3a0e08 plus a1 into the caller's
  buffer at a0, one byte per pass, after a range check on `a1` and `a2`. The check returns 1 before
  any device access when `a1` is 0 or less (`blez` at 0x12c50) or when `a1` + `a2` is at least 0x72
  (`beq` at 0x12c44). Otherwise, after `splhi` at 0x12c58 and a read of 0xffffffffbf3a0a07 at
  0x12c68, it writes that byte back (`jal` at 0x12c84) ANDed with -0x11, set at 0x12c74, which
  clears the 0x10 bit, and masked to a byte in the delay slot. The loop runs while `s1` is not -1
  (`bne` at 0x12cc8), with `s1` holding `a2` - 1 at the `beq` at 0x12ca0 and counting down, so an
  `a2` of 0 skips it; each pass reads the byte at 0xffffffffbf3a0e08 plus `a1` plus `s1` (`s0`,
  built at 0x12ca8 to 0x12cb0, is passed in `a0` by the delay slot of the `jal` at 0x12cb4) and
  stores the byte returned at the caller's pointer plus `s1` (`sb` at 0x12ccc). `s2` is the caller's
  `a0`, saved at +0x8 (`sd` at 0x12c4c) and reloaded at 0x12c9c, so those stores land in the
  caller's buffer, from the last byte to the first. It then restores the level with `splx` (`jal` at
  0x12cd8), passing the `splhi` return saved at +0x0 (`sd` at 0x12c64) in `a0` from the delay slot,
  and returns 0 on this path (`v0` set at 0x12ce4). Inferred: `splhi` and `splx` read as an
  interrupt-level raise and restore, and `pciio_pio_read8` and `pciio_pio_write8` as byte-wide
  device accesses, going by their symbol names with no callee note to confirm. Unknown: the register
  name and fields behind 0xffffffffbf3a0e08 and 0xffffffffbf3a0a07; a reviewed datasheet register
  table for the block at 0xffffffffbf3a0000 and the call sites of this routine would settle them.
  Evidence grade: inferred.
- `rtc_init` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x121f4 (n32).
  Updates byte registers in the block at 0xffffffffbf3a0000 and the 8-byte word at
  0xffffffffbf310018, but only when the word at +0xfc of `_prom_cleared` is zero (`beq` at 0x121fc);
  otherwise it returns at once. On that path it calls `splhi` at 0x1220c, then updates the bytes in
  place with the stores in this order. The byte at 0xffffffffbf3a0b07 is first ANDed with -0x75
  (`sb` at 0x12224) and then stored again with 0x2 ORed in (`sb` at 0x12230). The byte at
  0xffffffffbf3a0a07 is stored with 0x10 ORed in (`sb` at 0x1223c). The byte at 0xffffffffbf3a4a07
  is stored ANDed with -0x4 (`sb` at 0x1224c). The byte at 0xffffffffbf3a4b07 is stored ANDed with
  -0x53 (`sb` at 0x1225c) and then with 0x9 ORed in (`sb` at 0x1226c). It then stores 1 to the word
  at +0xfc of `_prom_cleared` (`sw` at 0x1227c), so the guard at 0x121fc returns at once on later
  calls. It stores the byte at 0xffffffffbf3a0a07 again ANDed with -0x20 (`sb` at 0x12290, in the
  delay slot of the `pciio_pio_read64` call). It reads the 8-byte word at 0xffffffffbf310018 with
  `pciio_pio_read64` (`jal` at 0x1228c), then writes that return with 0x100 ORed in back to
  0xffffffffbf310018 with `pciio_pio_write64` (`jal` at 0x1229c). It restores the level with `splx`
  (`jal` at 0x122a4), passing the `splhi` return saved at +0x0 (`sd` at 0x12264) in `a0` from the
  delay slot. Inferred: `pciio_pio_read64` and `pciio_pio_write64` are 8-byte device accessors by
  their symbol names; the bundle has no callee note on either.
  Unknown: the register names and bit fields behind the byte addresses 0xffffffffbf3a0a07,
  0xffffffffbf3a0b07, 0xffffffffbf3a4a07 and 0xffffffffbf3a4b07, and the value `pciio_pio_read64`
  returns at 0xffffffffbf310018; a reviewed datasheet register table for the blocks at
  0xffffffffbf3a0000 and 0xffffffffbf310000 would settle the names.
  Evidence grade: inferred.
- `setbadclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12dd8 (n32).
  Inferred: the symbol name and the callee names `pciio_pio_read8` and `pciio_pio_write8` (PCI
  programmed-I/O accessors by name) suggest that this routine records a bad-clock state on the
  board, and those two accessors are its only device access. Established: it saves `ra` and `s0` in
  a 16-byte frame (`sd` at 0x12ddc and 0x12de4), calls `splhi` at 0x12de0, keeps its result in s0
  (`or s0,v0,zero`), and reads 0xffffffffbf3a0a07 with `pciio_pio_read8` (`jal` at 0x12df0).
  Established: it then writes that byte back with `pciio_pio_write8` at 0x12e08, ANDed with -0x11
  (set at 0x12dfc), which clears the 0x10 bit, and masked with 0xff in the delay slot, while a1
  holds 0xffffffffbf3a0a07 (set at 0x12e00). Established: the read and write pair for
  0xffffffffbf3a0e07 follows, with `pciio_pio_read8` at 0x12e14 (a0 set at 0x12e18) and
  `pciio_pio_write8` at 0x12e28 (a1 set at 0x12e2c); the byte read is ORed with 0x1, which sets its
  low bit (the `ori` at 0x12e1c), and masked with 0xff at 0x12e24. Established: the routine has no
  branch; it calls `splx` at 0x12e30 with a copy of s0 in a0 (`or a0,s0,zero` in the delay slot) and
  returns the value `splx` returned, in v0 (`jr ra` at 0x12e40).
  Unknown: the device registers behind 0xffffffffbf3a0a07 and 0xffffffffbf3a0e07, since no linked
  mmio row or datasheet excerpt covers them; an mmio row for the window that holds
  0xffffffffbf3a0000 settles it.
  Evidence grade: inferred.
- `spl0` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xb1cc (n32).
  Inferred: it acts on the CRIME Interrupt Enable register at 0xffffffffb4000018, which the linked
  row names CRIME 0x18 Interrupt Enable and the datasheet gives as one bit per cause with reset
  zero. The bundle does not list the coprocessor-0 instructions; from the disassembly it reads
  coprocessor-0 register number twelve, the status register on the R4000 family, as its first
  instruction (the value goes to v0), keeps the bits of it selected by a mask built from 0x1 in the
  upper half and 0x84 in the lower, ORs in 0x8701 (at 0xb1dc), and writes that value with its low
  bit cleared (an exclusive OR with 0x1 at 0xb1e0) before it touches CRIME. It then copies the
  doubleword at 0xffffffffffffa2b8 into the Interrupt Enable register (the `ld` at 0xb1e8 and the
  `sd` at 0xb1f4), with no change to the value in between. It loads the word at 0xffffffffffffa2e0
  into `t0` (the `lw` at 0xb1f8) and stores 0x0 to that word (the `sw` at 0xb210). The value it
  returns in v0 is the original coprocessor-0 value with its second byte replaced by that loaded
  word shifted left by 8 (the mask built at 0xb1fc and 0xb200), and the new coprocessor-0 value,
  with its low bit set, is written back in the delay slot of the return (the `jr ra` at 0xb214 and
  the write at 0xb218). There is no branch and no call.
  Unknown: which interrupt masks the bits ORed in at 0xb1dc select, which needs the coprocessor-0
  status register table.
  Evidence grade: inferred.
- `spl7` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xb38c (n32).
  Inferred: it acts on the CRIME Interrupt Enable register at 0xffffffffb4000018, which the linked row
  names CRIME 0x18 Interrupt Enable, and on the word at 0xffffffffffffa2e0, which it compares with 0x18.
  It loads that word into `t0` (the `lw` at 0xb394) and branches to 0xb3f0 when the word is at least
  0x18 as a signed comparison (the `beq` at 0xb39c). Below 0x18 it copies the doubleword at
  0xffffffffffffa2d0 into the enable register (the `ld` at 0xb3bc and the `sd` at 0xb3c8), stores 0x18 to
  the word at 0xffffffffffffa2e0 (the `sw` at 0xb3e4), and returns through `jr ra` at 0xb3e8. At 0x18 or
  above it reads the word again (the `lw` at 0xb3f0), makes no store, and returns through `jr ra` at
  0xb408. Unknown: who else writes or reads the word at 0xffffffffffffa2e0; a cross-reference listing of
  that address across the kernel object would settle it. Unknown: which causes the doubleword copied from
  0xffffffffffffa2d0 enables; the per-bit cause routing in the CRIME datasheet on PDF pp. 106–111, which
  the excerpts here cover only in part, would settle it.
  Evidence grade: inferred.
- `stkscr3` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x1945c (n32).
  Inferred: it is an error-report path, judging by its calls to `printf` and `panic`, and it writes the
  CRIME Interrupt Enable register at 0xffffffffb4000018, which the linked row names CRIME 0x18 Interrupt
  Enable. It stores the stack pointer as it was on entry to `ovflwword` (the `sw` at 0x19470), reads the
  byte at 0xffffffffffffa03f into `s1` (the `lb` at 0x19480), and then stores 0x3 to that byte (the `sb`
  at 0x1948c). The first `printf` call at 0x19490 takes the stack pointer as its a2 argument, and the `lw`
  in that call's delay slot at 0x19494 reloads `sp` from 0xffffffffffffa1a4; the second `printf` at
  0x194a4 takes the byte read at 0x19480 as its a2 argument. Then it stores 0x18 to the word at
  0xffffffffffffa2e0 (the `sw` at 0x194b0), reads the doubleword at 0xffffffffffffa2d0 through `a0` set to
  0x18 (the `ld` at 0x194b4), and writes it to 0xffffffffb4000018 (the `sd` at 0x194c0). It then calls
  `panic` at 0x194e0 with a .data address in `a0`, and tail-jumps to `_baduk` at 0x194e8 with `a0` to `a3`
  unresolved; apart from the unconditional branch at 0x19460, the routine is one straight path. Unknown:
  the text of the messages at sym(.data)+21990, +22120 and +22160; reading those strings from the binary
  would settle it. Unknown: the readers of the byte at 0xffffffffffffa03f after the store at 0x1948c and of
  the word at `ovflwword`; a cross-reference listing of those addresses in the kernel object would settle
  it. Unknown: the handling by `panic` of its message and by `_baduk` of the arguments it is tail-called
  with; committed entries for `panic` and `_baduk` would settle it.
  Evidence grade: inferred.
- `synthackkgclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xa0d4 (n32).
  Loads the 8-byte word at 0xffffffffb4000020 (`ld` at 0xa0ec), ANDs it with a mask whose upper half
  is 0xdfff and lower half 0xffff, which clears bit 29, and stores the result back to the same
  address (`sd` at 0xa110, in the delay slot of the branch at 0xa10c), then works on the counters
  `cause_ip6_count` and `late_kgclock_count`. Inferred: the address 0xffffffffb4000020 falls at
  offset 0x20 of the CRIME block, since the linked row CRIME 0x20 Software Interrupt names that
  offset and the constant at 0xa0e4 gives the block base. Inferred: bits 28 and 29 of that register
  are software causes, because the datasheet excerpt for 0x14000020 says bits 28 to 29 are software
  causes, so the store at 0xa110 clears one of those software causes. If the word at +0x6c of
  `_prom_cleared` (`lw` at 0xa0e0) is nonzero, the routine returns that word at once (`bne` at
  0xa10c, return at 0xa1a4). Otherwise it stores that word plus one, which is 1 on this path, back
  at +0x6c (`sw` at 0xa128); if `cause_ip6_count` is zero it stores zero there instead (`sw` at
  0xa190) and returns, and if not, it loops from 0xa130 to 0xa180. Each pass calls the code address
  loaded from a gp-relative slot at 0xa12c (the `jalr` at 0xa134), with the routine's own a0 and a1,
  reloads the software-interrupt word, clears the same bit and stores it (`ld` at 0xa13c, `sd` at
  0xa148 in the delay slot of the `spl7` call at 0xa144), adds one to `late_kgclock_count` when
  `cause_ip6_count` is at least 2 (`bne` at 0xa15c, `sw` at 0xa164), decrements `cause_ip6_count`
  (`sw` at 0xa170), and calls `splx` (`jal` at 0xa178). The loop repeats from 0xa130 while
  `cause_ip6_count` is nonzero: the delay slot of the `splx` call sets s0 when the count is below 1
  (at 0xa17c) and the `beq` at 0xa180 leaves the loop when s0 is set.
  Unknown: the routine that the `jalr` at 0xa134 reaches, since the gp-relative slot it loads is set
  elsewhere.
  Evidence grade: inferred.
- `synthclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x9ff8 (n32).
  Reads the 8-byte word at 0xffffffffb4000020 (`ld` at 0xa008) and ANDs it with a mask whose upper
  half is 0xefff and lower half 0xffff, which clears bit 28; the result goes back to the same
  address in the delay slot of the branch at 0xa028 (`sd` at 0xa02c). Inferred: that address sits at
  offset 0x20 of the CRIME block, going by the linked row CRIME 0x20 Software Interrupt; the
  constant at 0xa004 supplies the upper bits of the address. The datasheet excerpt for 0x14000020
  calls bits 28 and 29 software causes, so the store clears one of those software causes. If the
  word at +0x68 of `_prom_cleared` (`lw` at 0xa000) is nonzero, the routine returns that word at
  once. Otherwise the word at +0x60 of `_prom_cleared` (`lw` at 0xa044) decides whether hwperf_intr
  is called with a0 to a3 passed through (`jal` at 0xa058, with zero stored to +0x60 in its delay
  slot at 0xa05c), and when cause_ip5_count is zero the routine stores zero to +0x68 (`sw` at
  0xa0d0) and returns. Otherwise each pass calls clock with a0 and the word at 0xffffffffffffa018 as
  a1 (`jal` at 0xa070, `lw` at 0xa074), reloads the software-interrupt word, clears bit 28 again and
  stores it back (`ld` at 0xa078, `sd` at 0xa084 in the delay slot of the `spl7` call at 0xa080),
  adds one to late_clock_count when cause_ip5_count is at least 2 (`bne` at 0xa098, `sw` at 0xa0a0),
  decrements cause_ip5_count (`sw` at 0xa0ac), and calls splx (`jal` at 0xa0b4) with the `spl7`
  result in a0. The pass loop ends when cause_ip5_count has reached zero: s0 is set in the delay
  slot of the splx call (at 0xa0b8) when the count is below 1, and the `beq` at 0xa0bc repeats the
  pass while s0 is clear.
  Unknown: the access type of bit 28 of the register at 0x14000020, which the excerpt does not give;
  the reviewed field table for that register would settle it.
  Evidence grade: inferred.
- `write_dallas_nvram` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12d00 (n32).
  Inferred: the symbol name and the callee names `pciio_pio_read8` and `pciio_pio_write8` suggest
  that this routine writes a buffer of bytes to a Dallas-type NVRAM on the board, through the I/O
  addresses 0xffffffffbf3a0a07 and 0xffffffffbf3a0e08 plus an offset. Established: when a1 + a2 is
  0x72 or more (`beq` at 0x12d1c) or a1 is zero or negative (`blez` at 0x12d28), it branches to the
  return through 0x12dd0 with v0 = 1 (preset at 0x12d0c), without calling `splhi` or touching the
  device. Established: otherwise it calls `splhi` at 0x12d30, saves its return value at frame offset
  +0 (`sd` at 0x12d3c), reads 0xffffffffbf3a0a07 with `pciio_pio_read8` (`jal` at 0x12d40), and
  writes that byte back with `pciio_pio_write8` at 0x12d5c, ANDed with -0x11 (set at 0x12d4c), which
  clears the 0x10 bit, with a1 = 0xffffffffbf3a0a07 and a0 masked with 0xff in the delay slot.
  Established: each loop pass reads one byte with `lbu` at 0x12d8c from s0, which starts at the
  entry a0 plus the count minus one (a0 is stored at +0x8 at 0x12d24 and reloaded at 0x12d7c) and
  steps back 1 at the end of each pass (`addiu` at 0x12da4); the byte goes in a0 to
  `pciio_pio_write8` (`jal` at 0x12d90) with a1 = s1 in the delay slot, which is 0xffffffffbf3a0e08
  plus the entry a1 plus the count minus one (built at 0x12d80) and also steps back 1 each pass
  (0x12d9c). Established: s2 holds a2 - 1 at the `beq` at 0x12d74, counts down by 1 each pass
  (0x12d98), and the `bne` at 0x12da0 ends the loop when it reaches -1, so the loop writes a2 bytes
  and is skipped when a2 is 0. Established: after the loop, or on that skip, it calls `splx` at
  0x12db0 with the saved splhi value in a0 (`ld a0,0(sp)` in the delay slot), sets v0 to 0 at
  0x12dbc, and returns through `jr ra` at 0x12dc8.
  Unknown: the device registers behind 0xffffffffbf3a0a07 and 0xffffffffbf3a0e08, and the
  device-side result of the writes at 0x12d5c and 0x12d90, since no linked mmio row or datasheet
  excerpt covers them; an mmio row for the window that holds 0xffffffffbf3a0000 settles it.
  Evidence grade: inferred.
