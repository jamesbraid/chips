# Readings: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`

One entry per routine, filed here from the reading batches by binary.

- `VEC_int` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x0-0x200 (512 bytes).
  It occupies 512 bytes.
  The `lw` at 0x4 loads 4 bytes from abs 0xffffffffffffa2e0.
  The `ld` at 0xc loads 8 bytes from abs 0xffffffffb4000018.
  The `sd` at 0x18 stores 8 bytes to ?.
  3 such `sw` accesses store 4 bytes to abs 0xffffffffffffa2e0, including `sw` at 0x20, `sw` at 0x54, `sw` at 0x1c8.
  The `ld` at 0x24 loads 8 bytes from abs 0xffffffffffffa2d0.
  3 such `sd` accesses store 8 bytes to abs 0xffffffffb4000018, including `sd` at 0x2c, `sd` at 0x64, `sd` at 0x1d8.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x58, `ld` at 0x1cc.
  The `lw` at 0x84 loads 4 bytes from abs 0xffffffffffffa020.
  2 such `lb` accesses load 1 byte from abs 0xffffffffffffa03e, including `lb` at 0xa8, `lb` at 0x178.
  The `lw` at 0xb4 loads 4 bytes from abs 0xffffffffffffa014.
  The `lw` at 0xb8 loads 4 bytes from [-0x5fec] +0x280.
  The `lw` at 0xc0 loads 4 bytes from [[-0x5fec]+640] +0x0.
  3 such `sb` accesses store 1 byte to abs 0xffffffffffffa03f, including `sb` at 0xd8, `sb` at 0x128, `sb` at 0x16c.
  3 such `lw` accesses load 4 bytes from abs 0xffffffffffffa018, including `lw` at 0xe0, `lw` at 0x100, `lw` at 0x160.
  The `ld` at 0xec loads 8 bytes from a0 (arg0 at entry) +0xf8.
  The `ld` at 0xfc loads 8 bytes from a0 (arg0 at entry) +0x118.
  The `lb` at 0x118 loads 1 byte from abs 0xffffffffffffa043.
  The `lb` at 0x12c loads 1 byte from abs 0xffffffffffffa040.
  The `sb` at 0x130 stores 1 byte to abs 0xffffffffffffa043.
  2 such `lw` accesses load 4 bytes from abs 0xffffffffffffa1a4, including `lw` at 0x140, `lw` at 0x1f4.
  The `sb` at 0x154 stores 1 byte to abs 0xffffffffffffa040.
  The `sw` at 0x164 stores 4 bytes to [-0x5fe8] +0x15c.
  The `jal` at 0x48 calls intr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=s0 at entry, a3=a3 at entry (arg3).
  Calls backtouser via direct with a0=[[[-0x5fec]+640]], a1=?, a2=?, a3=? (`j` at 0xcc).
  The `jal` at 0xe4 calls ktimer_switch with a0=[-0x5fe8], a1=0x1, a2=?, a3=?.
  Calls soft_trap via direct with a0=a0 at entry (arg0), a1=0x84, a2=?, a3=[a0+280]:8 (`j` at 0xf8).
  The `jal` at 0x110 calls ktimer_switch with a0=[-0x5fe8], a1=s7 at entry, a2=?, a3=?.
  The `jal` at 0x13c calls splhi with a0=?, a1=?, a2=?, a3=?.
  Calls resumeidle via direct with a0=0x0, a1=?, a2=?, a3=? (`j` at 0x158).
  The `jal` at 0x184 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x19c calls kpswtch with a0=?, a1=?, a2=?, a3=?.
  Calls exception_leave via direct with a0=?, a1=?, a2=?, a3=? (`j` at 0x1e0).
  The `jal` at 0x1f8 calls cmn_err with a0=0x0, a1=sym(.data), a2=sp, a3=?.
  The `bne` branch at 0x8c targets 0x1e0, is taken when sp(=sp) < k0(=[-0x5fe0]) (unsigned), and falls through when sp(=sp) >= k0(=[-0x5fe0]) (unsigned).
  The `bne` branch at 0x94 targets 0x1e8, is taken when sp(=sp) != k0(=[-0x5fe0]), and falls through when sp(=sp) == k0(=[-0x5fe0]).
  The `beq` branch at 0xa0 targets 0x100, is taken when (s0 & 0x18) == 0, and falls through when (s0 & 0x18) != 0.
  The `bne` branch at 0xac targets 0xd4, is taken when a0(=[-0x5fc2]:1) != 0, and falls through when a0(=[-0x5fc2]:1) == 0.
  The `bne` branch at 0xc4 targets 0xd4, is taken when a0(=[[[-0x5fec]+640]]) != 0, and falls through when a0(=[[[-0x5fec]+640]]) == 0.
  The `beq` branch at 0x108 targets 0x118, is taken when a0(=[-0x5fe8]) == 0, and falls through when a0(=[-0x5fe8]) != 0.
  The `beq` branch at 0x11c targets 0x160, is taken when k0(=[-0x5fbd]:1) == 0, and falls through when k0(=[-0x5fbd]:1) != 0.
  The `beq` branch at 0x134 targets 0x1e0, is taken when k0(=[-0x5fc0]:1) == 0, and falls through when k0(=[-0x5fc0]:1) != 0.
  The `beq` branch at 0x170 targets 0x1e0, is taken when s3(=ret(intr)) == 0, and falls through when s3(=ret(intr)) != 0.
  The `beq` branch at 0x17c targets 0x1e0, is taken when v0(=[-0x5fc2]:1) == 0, and falls through when v0(=[-0x5fc2]:1) != 0.

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

- `kpreemption` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x19c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x19c-0x200 (100 bytes).
  It occupies 100 bytes.
  The `sw` at 0x1c8 stores 4 bytes to abs 0xffffffffffffa2e0.
  The `ld` at 0x1cc loads 8 bytes from s4 -0x5d48.
  The `sd` at 0x1d8 stores 8 bytes to abs 0xffffffffb4000018.
  The `jal` at 0x19c calls kpswtch with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  Calls exception_leave via direct with a0=[s4-23880]:8, a1=?, a2=?, a3=? (`j` at 0x1e0).
  The instructions from 0x1e8 to 0x1fc are not reached by any path from the entry, and their branches are not listed.

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

- `proc1` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x1b54 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x1b54-0x1ba0 (76 bytes).
  It occupies 76 bytes.
  The `ld` at 0x1b54 loads 8 bytes from abs 0xffffffffffffa2b8.
  The `sw` at 0x1b5c stores 4 bytes to abs 0xffffffffffffa2e0.
  The `sd` at 0x1b64 stores 8 bytes to abs 0xffffffffb4000018.
  The `sb` at 0x1b84 stores 1 byte to abs 0xffffffffffffa03f.

- `flash_write_enable` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x2540 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x2540-0x2558 (24 bytes).
  It occupies 24 bytes.
  The `ld` at 0x2544 loads 8 bytes from abs 0xffffffffbf310008.
  The `sd` at 0x2554 stores 8 bytes to abs 0xffffffffbf310008.
  The return at 0x2550 has v0 = 0xffffffffbf310000.

- `flash_write_disable` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x2558 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x2558-0x2574 (28 bytes).
  It occupies 28 bytes.
  The `ld` at 0x255c loads 8 bytes from abs 0xffffffffbf310008.
  The `sd` at 0x2570 stores 8 bytes to abs 0xffffffffbf310008.
  The return at 0x256c has v0 = 0xffffffffbf310000.

- `update_ust` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x4250 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x4250-0x4290 (64 bytes).
  It occupies 64 bytes.
  The `ld` at 0x4254 loads 8 bytes from abs 0xffffffffbf340000.
  The `lw` at 0x425c loads 4 bytes from sym(ust_val) +0x8.
  The `lw` at 0x4264 loads 4 bytes from sym(ust_val) +0x4.
  The `lw` at 0x426c loads 4 bytes from sym(ust_val) +0x0.
  The `sw` at 0x4270 stores 4 bytes to sym(ust_val) +0x8.
  The `sw` at 0x4284 stores 4 bytes to sym(ust_val) +0x4.
  The `sw` at 0x428c stores 4 bytes to sym(ust_val) +0x0.
  The return at 0x4288 has v0 = ?.

- `early_ecc_init` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x4a54 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x4a54-0x4a60 (12 bytes).
  It occupies 12 bytes.
  The `sw` at 0x4a5c stores 4 bytes to sym(.bss) +0x940.
  The return at 0x4a58 has v0 = ?.

- `add_vice` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x8168 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x8168-0x81e4 (124 bytes).
  It occupies 124 bytes.
  The `sw` at 0x8184 stores 4 bytes to abs 0xffffffffb700e014.
  The `sw` at 0x8194 stores 4 bytes to abs 0xffffffffb70001bc.
  The `ld` at 0x81a0 loads 8 bytes from abs 0xffffffffb4000010.
  The `lw` at 0x81bc loads 4 bytes from abs 0xffffffffb7000164.
  The `sw` at 0x81c8 stores 4 bytes to abs 0xffffffffb700e00c.
  The `lw` at 0x81d4 loads 4 bytes from abs 0xffffffffb700000c.
  The `jal` at 0x8180 calls us_delay with a0=0xa, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8190 calls us_delay with a0=0xa, a1=?, a2=?, a3=?.
  The `jal` at 0x81d0 calls add_to_inventory with a0=0xf, a1=0x3, a2=0x0, a3=0x0, a4=[0xffffffffb700000c], a5=[0xffffffffb7000164], a6=0xffffffffb700e00c.
  The `beq` branch at 0x81ac targets 0x81d8, is taken when (a0(=[0xffffffffb4000010]:8) & a1(=0x80000000)) == 0, and falls through when (a0(=[0xffffffffb4000010]:8) & a1(=0x80000000)) != 0.
  The return at 0x81dc has v0 = one of ret(us_delay), ret(add_to_inventory).

- `add_vice` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x8168 (n32).
  Inferred: it reads the CRIME interrupt status at offset 0x10 (linked row `CRIME 0x10 Interrupt Status`, which the reviewed datasheet gives at `0x14000010` as a read-only OR of hardware and software causes), and it calls `add_to_inventory` only when the 0x80000000 bit of that status is set. It writes 4 to `0xffffffffb700e014` (the `sw` at 0x8184, in the delay slot of the call at 0x8180) and calls `us_delay` with 0xa, then writes 0 to `0xffffffffb70001bc` (the `sw` at 0x8194) and calls `us_delay` with 0xa again. It loads the doubleword at `0xffffffffb4000010` (the `ld` at 0x81a0) and branches to the return at 0x81d8 when that bit is clear (the `beq` at 0x81ac). When the bit is set, it copies the word at `0xffffffffb7000164` to `0xffffffffb700e00c` (the `sw` at 0x81c8) and calls `add_to_inventory` with a0 0xf, a1 0x3, a2 and a3 0x0, a4 set to the word at `0xffffffffb700000c` (the `lw` in the delay slot at 0x81d4), a5 set to the word at `0xffffffffb7000164`, and a6 set to `0xffffffffb700e00c` (the `jal` at 0x81d0). The return at 0x81dc gives the v0 left by the last call: `us_delay` on the branch-taken path and `add_to_inventory` on the fall-through path. Unknown: the owner of the window at `0xffffffffb7000000`, since no linked row names it; the route is the inventory row for that window. Unknown: the handling by `add_to_inventory` of the arguments a4 to a6, since that routine has no committed entry; the route is that routine's own entry. Unknown: the timing the two `us_delay` waits impose, since the bundle shows them only as calls; the route is the `us_delay` entry.
  Evidence grade: inferred.

- `early_gbe_stop` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x8504 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x8504-0x8738 (564 bytes).
  It occupies 564 bytes.
  5 such `lw` accesses load 4 bytes from abs 0xffffffffb6030008, including `lw` at 0x8518, `lw` at 0x85b4, `lw` at 0x85cc.
  2 such `lw` accesses load 4 bytes from abs 0xffffffffb603000c, including `lw` at 0x8554, `lw` at 0x8628.
  2 such `sw` accesses store 4 bytes to abs 0xffffffffb603000c, including `sw` at 0x8564, `sw` at 0x8634.
  2 such `lw` accesses load 4 bytes from abs 0xffffffffb6020008, including `lw` at 0x856c, `lw` at 0x8638.
  2 such `sw` accesses store 4 bytes to abs 0xffffffffb6020008, including `sw` at 0x8580, `sw` at 0x8644.
  2 such `lw` accesses load 4 bytes from abs 0xffffffffb6040004, including `lw` at 0x858c, `lw` at 0x8650.
  2 such `sw` accesses store 4 bytes to abs 0xffffffffb6040004, including `sw` at 0x859c, `sw` at 0x865c.
  5 such `lw` accesses load 4 bytes from abs 0xffffffffb6020004, including `lw` at 0x85dc, `lw` at 0x8604, `lw` at 0x8680.
  5 such `lw` accesses load 4 bytes from abs 0xffffffffb6040000, including `lw` at 0x85ec, `lw` at 0x8614, `lw` at 0x868c.
  The `sw` at 0x86cc stores 4 bytes to abs 0xffffffffb6010000.
  The `lw` at 0x86d4 loads 4 bytes from abs 0xffffffffb6000004.
  The `sw` at 0x86e4 stores 4 bytes to abs 0xffffffffb6000004.
  The `jal` at 0x8548 calls flushbus with a0=a0 at entry (arg0), a1=0xffffffffb6020000, a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x8560 calls flushbus with a0=[0xffffffffb603000c], a1=?, a2=?, a3=?.
  The `jal` at 0x857c calls flushbus with a0=?, a1=?, a2=0xffffffffb6020000, a3=[0xffffffffb6020008].
  The `jal` at 0x8598 calls flushbus with a0=?, a1=?, a2=?, a3=?, a5=0xffffffffb6040000, a6=0xfffffffffffeffff.
  The `jal` at 0x8630 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x8640 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x8658 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x86e0 calls flushbus with a0=?, a1=?, a2=[0xffffffffb6030008], a3=?.
  The `beq` branch at 0x853c targets 0x870c, is taken when (at(=[0xffffffffb6030008]) & 0x1) == 0, and falls through when (at(=[0xffffffffb6030008]) & 0x1) != 0.
  The `beq` branch at 0x85a4 targets 0x85b4 and is always taken.
  The `blez` branch at 0x85ac targets 0x8624, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `beq` branch at 0x85bc targets 0x8604, is taken when (a2(=[0xffffffffb6030008]) & 0x1) == 0, and falls through when (a2(=[0xffffffffb6030008]) & 0x1) != 0.
  The `blez` branch at 0x85c4 targets 0x8624, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `bne` branch at 0x85d4 targets 0x85ac, is taken when (a3(=[0xffffffffb6030008]) & 0x1) != 0, and falls through when (a3(=[0xffffffffb6030008]) & 0x1) == 0.
  The `bne` branch at 0x85e4 targets 0x85ac, is taken when (a4(=[0xffffffffb6020004]) & 0x1) != 0, and falls through when (a4(=[0xffffffffb6020004]) & 0x1) == 0.
  The `bne` branch at 0x85f4 targets 0x85ac, is taken when (a5(=[0xffffffffb6040000]) & s2(=0x10000)) != 0, and falls through when (a5(=[0xffffffffb6040000]) & s2(=0x10000)) == 0.
  The `beq` branch at 0x85fc targets 0x8624 and is always taken.
  The `bne` branch at 0x860c targets 0x85c4, is taken when (a6(=[0xffffffffb6020004]) & 0x1) != 0, and falls through when (a6(=[0xffffffffb6020004]) & 0x1) == 0.
  The `bne` branch at 0x861c targets 0x85c4, is taken when (a7(=[0xffffffffb6040000]) & s2(=0x10000)) != 0, and falls through when (a7(=[0xffffffffb6040000]) & s2(=0x10000)) == 0.
  The `beq` branch at 0x8664 targets 0x8674 and is always taken.
  The `blez` branch at 0x866c targets 0x86c4, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `bne` branch at 0x8678 targets 0x8698, is taken when a2(=[0xffffffffb6030008]) != s2(=[0xffffffffb603000c]+32), and falls through when a2(=[0xffffffffb6030008]) == s2(=[0xffffffffb603000c]+32).
  The `bne` branch at 0x8684 targets 0x8698, is taken when a3(=[0xffffffffb6020004]) != s3(=[0xffffffffb6020008]+32), and falls through when a3(=[0xffffffffb6020004]) == s3(=[0xffffffffb6020008]+32).
  The `beq` branch at 0x8690 targets 0x86c4, is taken when a4(=[0xffffffffb6040000]) == s5(=[0xffffffffb6040004]+32), and falls through when a4(=[0xffffffffb6040000]) != s5(=[0xffffffffb6040004]+32).
  The `blez` branch at 0x8698 targets 0x86c4, is taken when a1(?) <= 0 (signed), and falls through when a1(?) > 0 (signed).
  The `bne` branch at 0x86a4 targets 0x866c, is taken when a5(=[0xffffffffb6030008]) != s2(=[0xffffffffb603000c]+32), and falls through when a5(=[0xffffffffb6030008]) == s2(=[0xffffffffb603000c]+32).
  The `bne` branch at 0x86b0 targets 0x866c, is taken when a6(=[0xffffffffb6020004]) != s3(=[0xffffffffb6020008]+32), and falls through when a6(=[0xffffffffb6020004]) == s3(=[0xffffffffb6020008]+32).
  The `bne` branch at 0x86bc targets 0x866c, is taken when a7(=[0xffffffffb6040000]) != s5(=[0xffffffffb6040004]+32), and falls through when a7(=[0xffffffffb6040000]) == s5(=[0xffffffffb6040004]+32).
  The `bne` branch at 0x8718 targets 0x8548, is taken when (t9(=[0xffffffffb6020004]) & 0x1) != 0, and falls through when (t9(=[0xffffffffb6020004]) & 0x1) == 0.
  The `bltz` branch at 0x8728 targets 0x8548, is taken when ra(=([0xffffffffb6040000] << 0x2f)) < 0 (signed), and falls through when ra(=([0xffffffffb6040000] << 0x2f)) >= 0 (signed).
  The `beq` branch at 0x8730 targets 0x86ec and is always taken.
  The return at 0x8704 has v0 = one of ret(flushbus), ?.

- `early_gbe_stop` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x8504 (n32).
  Inferred: it works on the GBE registers that the linked rows name `FRM_2`, `FRM_3`, `OVR_1`, `OVR_2`, `DID`, `DID_SHADOW`, `DOTCLK` and `VT_0`, and the bits it tests are DMA-enable fields that the reviewed GBE datasheet gives for those registers: bit 0 of FRM_2 and OVR_1, and the 0x10000 bit of DID. It reads FRM_2 at `0xffffffffb6030008` (the `lw` at 0x8518); when bit 0 is clear (the `beq` at 0x853c) it reads OVR_1 (the `lw` at 0x870c) and DID (the `lw` at 0x8720), enters the call path at 0x8548 when OVR_1 bit 0 is set (the `bne` at 0x8718) or DID's 0x10000 bit is set (the shift by 0x2f and the `bltz` at 0x8728), and otherwise returns at 0x8704. The call path calls `flushbus` at 0x8548, 0x8560, 0x857c and 0x8598, stores into FRM_3, OVR_2 and DID_SHADOW in the delay slots of the calls at 0x8560, 0x857c and 0x8598 (the `sw` at 0x8564, 0x8580 and 0x859c), and sets a1 to 0x61a80 (the `ori` at 0x85a8). The first poll loop (0x85ac to 0x861c) repeats while FRM_2 bit 0, OVR_1 bit 0 or the DID 0x10000 bit is set, counts a1 down on each pass, and leaves for 0x8624 when all three are clear or a1 is zero or below (the `blez` at 0x85ac and 0x85c4). From 0x8624 it adds 0x20 to FRM_3, OVR_2 and DID_SHADOW in turn (the `addiu` at 0x862c, 0x863c and 0x8654), stores each sum in the delay slot of its `flushbus` call (the `sw` at 0x8634, 0x8644 and 0x865c), resets a1 to 0x61a80 at 0x8668, and repeats a second loop (0x866c to 0x86c0) until FRM_2 equals FRM_3 plus 0x20, OVR_1 equals OVR_2 plus 0x20 and DID equals DID_SHADOW plus 0x20 (the `bne` at 0x8678 and 0x8684 and the `beq` at 0x8690), or until a1 runs out (the `blez` at 0x866c and 0x8698). At 0x86c4 it writes 0xffffffff80000000 (set in t3 at 0x86c4) to `0xffffffffb6010000` (the `sw` at 0x86cc), and it reads `0xffffffffb6000004` into t0 (the `lw` at 0x86d4) and stores t0 back to it in the delay slot of the call at 0x86e0 (the `sw` at 0x86e4); the return at 0x8704 gives the v0 that `flushbus` returned. Unknown: which bit of VT_0 the value 0xffffffff80000000 sets, since the reviewed datasheet names a freeze bit without its position, and the field layout of DOTCLK, which no reviewed excerpt names; the route is the linked spec rows for VT_0 and DOTCLK. Unknown: the device-side result of the four `flushbus` calls, whether the word stored at 0x86e4 equals the word loaded at 0x86d4, and the v0 left by the path that leaves at 0x8730; the route is the `flushbus` entry and the listing of those addresses.
  Evidence grade: inferred.

- `mlreset` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x8738 (n32).
  Grade: inferred.
  It is the IP32 bring-up path, as far as the call sites show, and it resembles the IP30 `mlreset`. It checks the `arg_triton_invall` option with `is_enabled`, reads the CRIME revision through `get_crimerev`, and calls `flushbus`. It installs handlers with `setkgvector`, `setcrimevector` (vectors 0x1c, 0x1d, 0x15 and 0x14, the last two using `buserror_intr`) and `setmaceisavector` (vector 0x5, `powerintr`), then calls `setup_ip32_flags`, `init_sysid` and `load_nvram_tab`. The reasons for each vector are inferred from the handler names.
  Reviewed: 2026-11-12

- `isa_dma_buf_init` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x9010 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x9010-0x9084 (116 bytes).
  It occupies 116 bytes.
  The `sd` at 0x9038 stores 8 bytes to abs 0xffffffffbf310000.
  The `jal` at 0x9034 calls flushbus with a0=?, a1=[sym(isa_dma_buf_addr)], a2=?, a3=?.
  The `jal` at 0x9054 calls contig_memalloc with a0=0x8, a1=0x8, a2=0x18000110, a3=a3 at entry (arg3).
  The `jal` at 0x9074 calls panic with a0=sym(.rodata)+2904, a1=?, a2=?, a3=(ret(contig_memalloc) << 0xc).
  The `beq` branch at 0x9018 targets 0x9048, is taken when a1(=[sym(isa_dma_buf_addr)]) == 0, and falls through when a1(=[sym(isa_dma_buf_addr)]) != 0.
  The `beq` branch at 0x9060 targets 0x9070, is taken when a3(=(ret(contig_memalloc) << 0xc)) == 0, and falls through when a3(=(ret(contig_memalloc) << 0xc)) != 0.
  The `beq` branch at 0x9068 targets 0x9020 and is always taken.
  The `beq` branch at 0x907c targets 0x9068 and is always taken.
  The return at 0x9040 has v0 = ret(flushbus).

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

- `ecc_enable` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x920c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x920c-0x9260 (84 bytes).
  It occupies 84 bytes.
  The `sd` at 0x9254 stores 8 bytes to abs 0xffffffffb4000200.
  The `jal` at 0x9218 calls is_specified with a0=sym(arg_ecc_enabled), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x9228 calls is_enabled with a0=sym(arg_ecc_enabled), a1=?, a2=?, a3=?.
  The `beq` branch at 0x9220 targets 0x9234, is taken when v0(=ret(is_specified)) == 0, and falls through when v0(=ret(is_specified)) != 0.
  The `beq` branch at 0x9244 targets 0x9258, is taken when a1(=[sym(ecc_meminited)]) == 0, and falls through when a1(=[sym(ecc_meminited)]) != 0.
  The `beq` branch at 0x924c targets 0x9258, is taken when a0(=[sym(ecc_checking_enabled)]) == 0, and falls through when a0(=[sym(ecc_checking_enabled)]) != 0.
  The return at 0x9258 has v0 = ?.

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

- `mace_hwgraph_lookup` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x926c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x926c-0x92c4 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0x929c calls sprintf with a0=sp-48, a1=sym(.rodata)+2936, a2=sym(.rodata)+2856, a3=sym(.rodata)+2872, a4=sym(.rodata)+2880.
  The `jal` at 0x92ac calls hwgraph_traverse with a0=-0x1, a1=sp-48, a2=a0 at entry (arg0), a3=?.
  The return at 0x92bc has v0 = ret(hwgraph_traverse).

- `early_mte_zero` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x9960 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x9960-0x9a34 (212 bytes).
  It occupies 212 bytes.
  The `sw` at 0x99d4 stores 4 bytes to [sym(.sdata)+88] +0x3030.
  The `sw` at 0x99dc stores 4 bytes to [sym(.sdata)+88] +0x3038.
  The `sw` at 0x99e0 stores 4 bytes to [sym(.sdata)+88] +0x3018.
  The `sw` at 0x99e8 stores 4 bytes to [sym(.sdata)+88] +0x3008.
  The `sw` at 0x99ec stores 4 bytes to [sym(.sdata)+88] +0x3800.
  The `jal` at 0x99ac calls mte_set_tlb with a0=?, a1=?, a2=0x700, a3=sp-64.
  The `jal` at 0x99b8 calls min with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x99c4 calls mte_fifo_wait with a0=0x5, a1=?, a2=?, a3=?.
  The `jal` at 0x99f0 calls mte_spin with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x9988 targets 0x9a10, is taken when a1 == 0, and falls through when a1 != 0.
  The `beq` branch at 0x9998 targets 0x99fc and is always taken.
  The `beq` branch at 0x99f8 targets 0x9a10, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `bne` branch at 0x9a00 targets 0x99a0, is taken when a0(?) != 0, and falls through when a0(?) == 0.
  The `beq` branch at 0x9a08 targets 0x99a0 and is always taken.
  The return at 0x9a2c has v0 = one of 0x11, ret(mte_spin).

- `crimestray` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x9f20 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x9f20-0x9f54 (52 bytes).
  It occupies 52 bytes.
  The `jal` at 0x9f34 calls cmn_err with a0=0x4, a1=sym(.rodata)+2984, a2=a1 at entry (arg1), a3=a3 at entry (arg3).
  The return at 0x9f4c has v0 = ret(cmn_err).

- `synthclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x9ff8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x9ff8-0xa0d4 (220 bytes).
  It occupies 220 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000020, including `ld` at 0xa008, `ld` at 0xa078.
  2 such `sd` accesses store 8 bytes to abs 0xffffffffb4000020, including `sd` at 0xa02c, `sd` at 0xa084.
  The `lw` at 0xa074 loads 4 bytes from abs 0xffffffffffffa018.
  The `jal` at 0xa058 calls hwperf_intr with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xa070 calls clock with a0=a0 at entry (arg0), a1=[-0x5fe8], a2=?, a3=?.
  The `jal` at 0xa080 calls spl7 with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa0b4 calls splx with a0=ret(spl7), a1=?, a2=?, a3=[sym(late_clock_count)]+1.
  The `beq` branch at 0xa028 targets 0xa044, is taken when v0(=[sym(.sdata)+104]) == 0, and falls through when v0(=[sym(.sdata)+104]) != 0.
  The `beq` branch at 0xa050 targets 0xa060, is taken when t8(=[sym(.sdata)+96]) == 0, and falls through when t8(=[sym(.sdata)+96]) != 0.
  The `beq` branch at 0xa064 targets 0xa0c4, is taken when ra(=[sym(cause_ip5_count)]) == 0, and falls through when ra(=[sym(cause_ip5_count)]) != 0.
  The `bne` branch at 0xa098 targets 0xa0a4, is taken when a4(=[sym(cause_ip5_count)]) < 0x2 (unsigned), and falls through when a4(=[sym(cause_ip5_count)]) >= 0x2 (unsigned).
  The `beq` branch at 0xa0bc targets 0xa070, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The `beq` branch at 0xa0cc targets 0xa030 and is always taken.
  The return at 0xa03c has v0 = one of [sym(.sdata)+104], ?.

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

- `synthackkgclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xa0d4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xa0d4-0xa1ac (216 bytes).
  It occupies 216 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000020, including `ld` at 0xa0ec, `ld` at 0xa13c.
  2 such `sd` accesses store 8 bytes to abs 0xffffffffb4000020, including `sd` at 0xa110, `sd` at 0xa148.
  The `jalr` at 0xa134 calls (unknown callee) with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=?.
  The `jal` at 0xa144 calls spl7 with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa178 calls splx with a0=ret(spl7), a1=?, a2=?, a3=?, a4=[sym(late_kgclock_count)]+1.
  The `bne` branch at 0xa10c targets 0xa194, is taken when v0(=[sym(.sdata)+108]) != 0, and falls through when v0(=[sym(.sdata)+108]) == 0.
  The `beq` branch at 0xa120 targets 0xa188, is taken when t8(=[sym(cause_ip6_count)]) == 0, and falls through when t8(=[sym(cause_ip6_count)]) != 0.
  The `bne` branch at 0xa15c targets 0xa168, is taken when a5(=[sym(cause_ip6_count)]) < 0x2 (unsigned), and falls through when a5(=[sym(cause_ip6_count)]) >= 0x2 (unsigned).
  The `beq` branch at 0xa180 targets 0xa130, is taken when s0(?) == 0, and falls through when s0(?) != 0.
  The return at 0xa1a4 has v0 = one of [sym(.sdata)+108], ?.

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

- `crimegang` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xa1dc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xa1dc-0xa248 (108 bytes).
  It occupies 108 bytes.
  The `lw` at 0xa208 loads 4 bytes from (sym(crimegang_tbl) + (a1 << 0x2)) +0x0.
  2 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa20c, `lw` at 0xa21c.
  The `jalr` at 0xa218 calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa210 targets 0xa230, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `bne` branch at 0xa228 targets 0xa20c, is taken when s1(?) < 0x10 (signed), and falls through when s1(?) >= 0x10 (signed).
  The return at 0xa240 has v0 = one of ?, ret(?).

- `crime_intr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xa2cc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xa2cc-0xa578 (684 bytes).
  It occupies 684 bytes.
  2 such `ld` accesses load 8 bytes from a0 (arg0 at entry) +0x138, including `ld` at 0xa2f8, `ld` at 0xa4d0.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000010, including `ld` at 0xa304, `ld` at 0xa32c.
  The `sw` at 0xa364 stores 4 bytes to (sp-208 + ([sym(.data)+1468]:2 << 0x2)) +0x0.
  The `lh` at 0xa370 loads 2 bytes from sym(.data) +0x58c.
  The `sw` at 0xa394 stores 4 bytes to (sp-208 + ([sym(.data)+1420]:2 << 0x2)) +0x0.
  The `lh` at 0xa3a0 loads 2 bytes from sym(.data) +0x5bc.
  3 such `lw` accesses load 4 bytes from table(sym(.data)+1408) +0x98, including `lw` at 0xa3d0, `lw` at 0xa44c, `lw` at 0xa4fc.
  5 such `ld` accesses load 8 bytes from table(sym(.data)+1408) +0xa0, including `ld` at 0xa3d8, `ld` at 0xa474, `ld` at 0xa4cc.
  3 such `ld` accesses load 8 bytes from ?, including `ld` at 0xa3f8, `ld` at 0xa480, `ld` at 0xa518.
  3 such `sd` accesses store 8 bytes to ?, including `sd` at 0xa40c, `sd` at 0xa494, `sd` at 0xa52c.
  The `lw` at 0xa42c loads 4 bytes from ?.
  2 such `lh` accesses load 2 bytes from table(sym(.data)+1408) +0x9e, including `lh` at 0xa448, `lh` at 0xa4bc.
  The `lw` at 0xa454 loads 4 bytes from table(sym(.data)+1408) +0xa8.
  The `lw` at 0xa4a8 loads 4 bytes from table(sym(.data)+1408) +0x90.
  The `lw` at 0xa4b8 loads 4 bytes from table(sym(.data)+1408) +0x94.
  2 such `sd` accesses store 8 bytes to a0 (arg0 at entry) +0x138, including `sd` at 0xa4dc, `sd` at 0xa540.
  The `jal` at 0xa3c8 calls splint with a0=[table(sym(.data)+1408)+152], a1=?, a2=?, a3=?.
  The `jal` at 0xa410 calls vsema with a0=table(sym(.data)+1408)+172, a1=?, a2=?, a3=?.
  The `jal` at 0xa418 calls splx with a0=ret(splint), a1=?, a2=?, a3=?.
  The `jal` at 0xa4a0 calls splint with a0=[table(sym(.data)+1408)+152], a1=?, a2=?, a3=?.
  The `jalr` at 0xa4b4 calls (unknown callee) with a0=a0 at entry (arg0), a1=[table(sym(.data)+1408)+148], a2=?, a3=?.
  The `jal` at 0xa4ec calls splx with a0=ret(splint), a1=?, a2=?, a3=?.
  The `beq` branch at 0xa31c targets 0xa56c and is always taken.
  The `beq` branch at 0xa338 targets 0xa538, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `beq` branch at 0xa34c targets 0xa368 and is always taken.
  The `beq` branch at 0xa360 targets 0xa3c0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `beq` branch at 0xa378 targets 0xa3b8, is taken when (a6(?) & v0(?)) == 0, and falls through when (a6(?) & v0(?)) != 0.
  The `beq` branch at 0xa390 targets 0xa3c0, is taken when v0(?) == 0, and falls through when v0(?) != 0.
  The `bne` branch at 0xa3a8 targets 0xa354, is taken when t0(?) != 0, and falls through when t0(?) == 0.
  The `beq` branch at 0xa3b0 targets 0xa358 and is always taken.
  The `beq` branch at 0xa3b8 targets 0xa388 and is always taken.
  The `beq` branch at 0xa3c0 targets 0xa430 and is always taken.
  The `blez` branch at 0xa3ec targets 0xa410, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `bne` branch at 0xa408 targets 0xa3f4, is taken when a6(?) < a3(?) (signed), and falls through when a6(?) >= a3(?) (signed).
  The `beq` branch at 0xa424 targets 0xa324, is taken when s7(?) == 0, and falls through when s7(?) != 0.
  The `beq` branch at 0xa438 targets 0xa420, is taken when v1(?) == s6(=-0x1), and falls through when v1(?) != s6(=-0x1).
  The `beq` branch at 0xa464 targets 0xa498, is taken when (a1(=[table(sym(.data)+1408)+158]:2) & 0x4) == 0, and falls through when (a1(=[table(sym(.data)+1408)+158]:2) & 0x4) != 0.
  The `blez` branch at 0xa46c targets 0xa498, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `bne` branch at 0xa490 targets 0xa47c, is taken when a5(?) < a3(?) (signed), and falls through when a5(?) >= a3(?) (signed).
  The `bne` branch at 0xa498 targets 0xa3c8, is taken when a6(?) != 0, and falls through when a6(?) == 0.
  The `beq` branch at 0xa4c4 targets 0xa4fc, is taken when (t1(=[table(sym(.data)+1408)+158]:2) & 0x4) == 0, and falls through when (t1(=[table(sym(.data)+1408)+158]:2) & 0x4) != 0.
  The `beq` branch at 0xa4f4 targets 0xa424 and is always taken.
  The `blez` branch at 0xa508 targets 0xa4ec, is taken when a3(?) <= 0 (signed), and falls through when a3(?) > 0 (signed).
  The `bne` branch at 0xa528 targets 0xa514, is taken when a5(?) < a3(?) (signed), and falls through when a5(?) >= a3(?) (signed).
  The `beq` branch at 0xa530 targets 0xa4ec and is always taken.
  The `beq` branch at 0xa570 targets 0xa344 and is always taken.
  The return at 0xa564 has v0 = ?.

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

- `intr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xa578 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xa578-0xa7c4 (588 bytes).
  It occupies 588 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffffffa100, including `ld` at 0xa58c, `ld` at 0xa714.
  The `ld` at 0xa5c8 loads 8 bytes from a0 (arg0 at entry) +0x138.
  The `ld` at 0xa5d4 loads 8 bytes from abs 0xffffffffb4000010.
  The `sd` at 0xa5e8 stores 8 bytes to a0 (arg0 at entry) +0x138.
  4 such `lw` accesses load 4 bytes from ?, including `lw` at 0xa604, `lw` at 0xa61c, `lw` at 0xa67c.
  The `lbu` at 0xa664 loads 1 byte from table(sym(.data)+1408) +0x690.
  The `lbu` at 0xa6ac loads 1 byte from table(sym(.data)+1408) +0x6a0.
  The `ld` at 0xa6bc loads 8 bytes from abs 0xffffffffb4000020.
  The `sd` at 0xa700 stores 8 bytes to abs 0xffffffffb4000020.
  The `lw` at 0xa704 loads 4 bytes from abs 0xffffffffffffa224.
  The `lw` at 0xa708 loads 4 bytes from [-0x5ddc] +0xd0.
  The `sw` at 0xa710 stores 4 bytes to [-0x5ddc] +0xd0.
  The `jalr` at 0xa60c calls (unknown callee) with a0=a0 at entry (arg0), a1=?, a2=?, a3=[sym(ip32nokp)].
  The `jal` at 0xa614 calls splx with a0=ret(splint), a1=?, a2=?, a3=?.
  The `jal` at 0xa62c calls getcause with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa678 calls splint with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xa798 calls log_tstamp_event with a0=0x66, a1=0x0, a2=0x0, a3=0x0, a4=0x0.
  The `jal` at 0xa7b4 calls log_tstamp_event with a0=0x65, a1=0x66, a2=0x0, a3=0x0, a4=0x0, a5=[sym(cause_ip6_count)].
  The `bne` branch at 0xa5ac targets 0xa788, is taken when (at(=[-0x5f00]:8) & 0x20) != 0, and falls through when (at(=[-0x5f00]:8) & 0x20) == 0.
  The `beq` branch at 0xa5f8 targets 0xa638 and is always taken.
  The `beq` branch at 0xa644 targets 0xa6b8, is taken when (s0(?) & 0xff00) == 0, and falls through when (s0(?) & 0xff00) != 0.
  The `beq` branch at 0xa64c targets 0xa660, is taken when a3(?) == 0, and falls through when a3(?) != 0.
  The `beq` branch at 0xa654 targets 0xa6b0, is taken when t8(?) == 0, and falls through when t8(?) != 0.
  The `beq` branch at 0xa668 targets 0xa69c, is taken when v0(=[table(sym(.data)+1408)+1680]:1) == 0, and falls through when v0(=[table(sym(.data)+1408)+1680]:1) != 0.
  The `beq` branch at 0xa684 targets 0xa600, is taken when s8(?) == 0, and falls through when s8(?) != 0.
  The `bne` branch at 0xa68c targets 0xa600, is taken when a3(=[sym(ip32nokp)]) != 0, and falls through when a3(=[sym(ip32nokp)]) == 0.
  The `beq` branch at 0xa694 targets 0xa608 and is always taken.
  The `beq` branch at 0xa6a8 targets 0xa670 and is always taken.
  The `beq` branch at 0xa6b0 targets 0xa638 and is always taken.
  The `beq` branch at 0xa6d0 targets 0xa758, is taken when v1(=[sym(cause_ip5_count)]) == 0, and falls through when v1(=[sym(cause_ip5_count)]) != 0.
  The `beq` branch at 0xa6dc targets 0xa76c, is taken when a4(=[sym(.sdata)+104]) == 0, and falls through when a4(=[sym(.sdata)+104]) != 0.
  The `beq` branch at 0xa6e8 targets 0xa6f8, is taken when a5(=[sym(cause_ip6_count)]) == 0, and falls through when a5(=[sym(cause_ip6_count)]) != 0.
  The `beq` branch at 0xa6f0 targets 0xa778, is taken when a2(=[sym(.sdata)+108]) == 0, and falls through when a2(=[sym(.sdata)+108]) != 0.
  The `beq` branch at 0xa6f8 targets 0xa704, is taken when a6(?) == 0, and falls through when a6(?) != 0.
  The `bne` branch at 0xa71c targets 0xa7a8, is taken when (a7(=[-0x5f00]:8) & 0x20) != 0, and falls through when (a7(=[-0x5f00]:8) & 0x20) == 0.
  The `bne` branch at 0xa75c targets 0xa6dc, is taken when t1(=[sym(.sdata)+96]) != 0, and falls through when t1(=[sym(.sdata)+96]) == 0.
  The `beq` branch at 0xa764 targets 0xa6e4 and is always taken.
  The `beq` branch at 0xa770 targets 0xa6e4 and is always taken.
  The `beq` branch at 0xa780 targets 0xa6f4 and is always taken.
  The `beq` branch at 0xa7a0 targets 0xa5b8 and is always taken.
  The `beq` branch at 0xa7bc targets 0xa728 and is always taken.
  The return at 0xa750 has v0 = one of 0x0, 0x1.

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

- `crimevec_thread_setup` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xadf8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xadf8-0xae50 (88 bytes).
  It occupies 88 bytes.
  The `jal` at 0xae1c calls sprintf with a0=sp-64, a1=sym(.rodata)+3168, a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0xae38 calls xthread_setup with a0=sp-64, a1=a1 at entry (arg1), a2=a2+24, a3=sym(crimevec_intrd_init), a4=a2 at entry (arg2).
  The return at 0xae48 has v0 = ret(xthread_setup).

- `crimevec_intrd_init` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xae50 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xae50-0xaea8 (88 bytes).
  It occupies 88 bytes.
  The `lw` at 0xae60 loads 4 bytes from abs 0xffffffffffffa018.
  The `ll` at 0xae7c loads 4 bytes from a0 (arg0 at entry) +0x18.
  The `sc` at 0xae84 stores 4 bytes to a0 (arg0 at entry) +0x18.
  The `jal` at 0xae6c calls xthread_set_func with a0=[-0x5fe8], a1=sym(crimevec_intrd), a2=a0 at entry (arg0), a3=a3 at entry (arg3).
  The `jal` at 0xae90 calls ipsema with a0=a0+28, a1=?, a2=[a0+24], a3=a0+24, a4=0x400, a5=([a0+24] | 0x400).
  The `beql` branch at 0xae88 targets 0xae7c, is taken when a5(=([a0+24] | 0x400)) == 0, and falls through when a5(=([a0+24] | 0x400)) != 0; its branch-likely delay slot `nop` at 0xae8c runs only when taken and is annulled on fall-through.
  The return at 0xaea0 has v0 = ret(ipsema).

- `crimevec_intrd` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xaea8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xaea8-0xaf38 (144 bytes).
  It occupies 144 bytes.
  The `lw` at 0xaeb4 loads 4 bytes from a0 (arg0 at entry) +0x0.
  The `lw` at 0xaec4 loads 4 bytes from a0 (arg0 at entry) +0x4.
  The `lh` at 0xaed4 loads 2 bytes from a0 (arg0 at entry) +0xe.
  The `lw` at 0xaee4 loads 4 bytes from a0 (arg0 at entry) +0x8.
  The `ld` at 0xaef8 loads 8 bytes from a0 (arg0 at entry) +0x10.
  The `ld` at 0xaf00 loads 8 bytes from ?.
  The `sd` at 0xaf14 stores 8 bytes to ?.
  The `jalr` at 0xaec0 calls (unknown callee) with a0=0x0, a1=[a0+4], a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0xaec8 calls splhi with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0xaf18 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0xaf20 calls ipsema with a0=a0+28, a1=?, a2=?, a3=?.
  The `bne` branch at 0xaedc targets 0xaf18, is taken when (v0(=[a0+14]:2) & 0x4) != 0, and falls through when (v0(=[a0+14]:2) & 0x4) == 0.
  The `blez` branch at 0xaef0 targets 0xaf18, is taken when a5(?) <= 0 (signed), and falls through when a5(?) > 0 (signed).
  The `bne` branch at 0xaf10 targets 0xaefc, is taken when a4(?) < a5(?) (signed), and falls through when a4(?) >= a5(?) (signed).
  The return at 0xaf30 has v0 = ret(ipsema).

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

- `spl0` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xb1cc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xb1cc-0xb21c (80 bytes).
  It occupies 80 bytes.
  The `ld` at 0xb1e8 loads 8 bytes from abs 0xffffffffffffa2b8.
  The `sd` at 0xb1f4 stores 8 bytes to abs 0xffffffffb4000018.
  The `lw` at 0xb1f8 loads 4 bytes from abs 0xffffffffffffa2e0.
  The `sw` at 0xb210 stores 4 bytes to abs 0xffffffffffffa2e0.
  The return at 0xb214 has v0 = ?.

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

- `splhi` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xb21c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xb21c-0xb2a0 (132 bytes).
  It occupies 132 bytes.
  3 such `lw` accesses load 4 bytes from abs 0xffffffffffffa2e0, including `lw` at 0xb224, `lw` at 0xb25c, `lw` at 0xb280.
  The `ld` at 0xb24c loads 8 bytes from abs 0xffffffffffffa2c0.
  The `sd` at 0xb258 stores 8 bytes to abs 0xffffffffb4000018.
  The `sw` at 0xb274 stores 4 bytes to abs 0xffffffffffffa2e0.
  The `beq` branch at 0xb22c targets 0xb280, is taken when t0(=[-0x5d20]) >= t1(=0x8) (signed), and falls through when t0(=[-0x5d20]) < t1(=0x8) (signed).
  The return at 0xb278 has v0 = ?.
  The return at 0xb298 has v0 = ?.

- `splprof` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xb308 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xb308-0xb38c (132 bytes).
  It occupies 132 bytes.
  3 such `lw` accesses load 4 bytes from abs 0xffffffffffffa2e0, including `lw` at 0xb310, `lw` at 0xb348, `lw` at 0xb36c.
  The `ld` at 0xb338 loads 8 bytes from abs 0xffffffffffffa2c8.
  The `sd` at 0xb344 stores 8 bytes to abs 0xffffffffb4000018.
  The `sw` at 0xb360 stores 4 bytes to abs 0xffffffffffffa2e0.
  The `beq` branch at 0xb318 targets 0xb36c, is taken when t0(=[-0x5d20]) >= t1(=0x10) (signed), and falls through when t0(=[-0x5d20]) < t1(=0x10) (signed).
  The return at 0xb364 has v0 = ?.
  The return at 0xb384 has v0 = ?.

- `spl7` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xb38c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xb38c-0xb410 (132 bytes).
  It occupies 132 bytes.
  3 such `lw` accesses load 4 bytes from abs 0xffffffffffffa2e0, including `lw` at 0xb394, `lw` at 0xb3cc, `lw` at 0xb3f0.
  The `ld` at 0xb3bc loads 8 bytes from abs 0xffffffffffffa2d0.
  The `sd` at 0xb3c8 stores 8 bytes to abs 0xffffffffb4000018.
  The `sw` at 0xb3e4 stores 4 bytes to abs 0xffffffffffffa2e0.
  The `beq` branch at 0xb39c targets 0xb3f0, is taken when t0(=[-0x5d20]) >= t1(=0x18) (signed), and falls through when t0(=[-0x5d20]) < t1(=0x18) (signed).
  The return at 0xb3e8 has v0 = ?.
  The return at 0xb408 has v0 = ?.

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

- `splx` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xb450 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xb450-0xb4b4 (100 bytes).
  It occupies 100 bytes.
  The `ld` at 0xb480 loads 8 bytes from table(sym(.data)+3120) +0x0.
  The `ld` at 0xb498 loads 8 bytes from ?.
  The `sd` at 0xb4a4 stores 8 bytes to abs 0xffffffffb4000018.
  The `sw` at 0xb4a8 stores 4 bytes to abs 0xffffffffffffa2e0.
  The return at 0xb4ac has v0 = ?.

- `splint` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xb4b4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xb4b4-0xb4fc (72 bytes).
  It occupies 72 bytes.
  The `ld` at 0xb4c8 loads 8 bytes from a0 (arg0 at entry) -0x5d48.
  The `sd` at 0xb4d4 stores 8 bytes to abs 0xffffffffb4000018.
  The `lw` at 0xb4d8 loads 4 bytes from abs 0xffffffffffffa2e0.
  The `sw` at 0xb4f0 stores 4 bytes to abs 0xffffffffffffa2e0.
  The return at 0xb4f4 has v0 = ?.

- `ecc_handler` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xd894 (n32).
  Grade: inferred.
  It is the ECC error handler on IP32, and it works with the R4600 secondary cache, judged from its callees. It calls `_r4600sc_disable_scache` only when `two_set_pcaches` and the word at absolute address -0x5d50 are both nonzero. It calls `_r4600sc_enable_scache` at 0xdddc only when the disable call ran and returned zero, and the path that returns at 0xd9ac does not call it. It fetches the failing address through `ecc_get_perr_addr`, logs with `ecc_log_error` and `ecc_assign_msg`, repairs with `ecc_fixmem` and `ecc_fixcache`, and schedules `ecc_cleanup` with `timeout`. The codes passed to the log calls are not decoded, so the error classes it recognises are open.
  Reviewed: 2026-11-12

- `ecc_fixmem` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xddec (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xddec-0xde60 (116 bytes).
  It occupies 116 bytes.
  The `ld` at 0xde18 loads 8 bytes from table(sym(ecc_info)) +0x68.
  The `lw` at 0xde1c loads 4 bytes from table(sym(ecc_info)) +0x7c.
  2 such `sd` accesses store 8 bytes to a2 (arg2 at entry) +0x8, including `sd` at 0xde28, `sd` at 0xde5c.
  The `lw` at 0xde2c loads 4 bytes from table(sym(ecc_info)) +0x80.
  The `sw` at 0xde30 stores 4 bytes to table(sym(ecc_info)) +0x84.
  The `sw` at 0xde34 stores 4 bytes to table(sym(ecc_info)) +0x88.
  The `ld` at 0xde3c loads 8 bytes from abs 0xffffffffb4000260.
  The `sw` at 0xde48 stores 4 bytes to table(sym(ecc_info)) +0x8c.
  The `lw` at 0xde4c loads 4 bytes from table(sym(ecc_info)) +0x78.
  The `bgez` branch at 0xde14 targets 0xde4c, is taken when v0(=([sym(r4000_config)] << 0x2e)) >= 0 (signed), and falls through when v0(=([sym(r4000_config)] << 0x2e)) < 0 (signed).
  The `beq` branch at 0xde58 targets 0xde2c and is always taken.
  The return at 0xde44 has v0 = 0x1.

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

- `err_save_regs` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xff08 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xff08-0xff50 (72 bytes).
  It occupies 72 bytes.
  The `ld` at 0xff0c loads 8 bytes from abs 0xffffffffb4000048.
  The `ld` at 0xff14 loads 8 bytes from abs 0xffffffffb4000040.
  The `ld` at 0xff1c loads 8 bytes from abs 0xffffffffb4000250.
  The `ld` at 0xff24 loads 8 bytes from abs 0xffffffffb4000258.
  The `ld` at 0xff2c loads 8 bytes from abs 0xffffffffb4000058.
  The `ld` at 0xff34 loads 8 bytes from abs 0xffffffffb4000268.
  The `ld` at 0xff3c loads 8 bytes from abs 0xffffffffb4000260.
  The `sd` at 0xff44 stores 8 bytes to abs 0xffffffffb4000048.
  The `sd` at 0xff4c stores 8 bytes to abs 0xffffffffb4000250.
  The return at 0xff48 has v0 = [0xffffffffb4000260]:8.

- `ecc_error_correction` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0xff50 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0xff50-0xfff0 (160 bytes).
  It occupies 160 bytes.
  The `sd` at 0xffd8 stores 8 bytes to abs 0xffffffffb4000250.
  The `jal` at 0xff9c calls splecc with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3), a4=0x1100000.
  The `jal` at 0xffb8 calls map_physaddr with a0=?, a1=0x40000000, a2=?, a3=?.
  The `jal` at 0xffc4 calls scrub_memory with a0=ret(map_physaddr), a1=?, a2=?, a3=?.
  The `jal` at 0xffd4 calls splxecc with a0=ret(splecc), a1=?, a2=0xffffffffb4000000, a3=?.
  The `jal` at 0xffdc calls unmap_physaddr with a0=ret(map_physaddr), a1=?, a2=?, a3=?.
  The `bgez` branch at 0xff58 targets 0xff6c, is taken when at(=(a3 << 0x2a)) >= 0 (signed), and falls through when at(=(a3 << 0x2a)) < 0 (signed).
  The `beq` branch at 0xff84 targets 0xff9c, is taken when a5(?) == v1(=0x900000), and falls through when a5(?) != v1(=0x900000).
  The `beq` branch at 0xff8c targets 0xff9c, is taken when a5(?) == a4(=0x1100000), and falls through when a5(?) != a4(=0x1100000).
  The `beq` branch at 0xff94 targets 0xff64 and is always taken.
  The `beq` branch at 0xffe8 targets 0xff64 and is always taken.
  The return at 0xff64 has v0 = one of 0x0, 0x1.

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

- `dobuserre` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x1026c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x1026c-0x102b0 (68 bytes).
  It occupies 68 bytes.
  The `ld` at 0x10288 loads 8 bytes from abs 0xffffffffb4000268.
  The `ld` at 0x10290 loads 8 bytes from abs 0xffffffffb4000260.
  The `jal` at 0x10294 calls dobuserr_common [0x10754] with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `bne` branch at 0x10274 targets 0x10284, is taken when a2 != at(=0x1), and falls through when a2 == at(=0x1).
  The `beq` branch at 0x1027c targets 0x102a4 and is always taken.
  The return at 0x102a8 has v0 = one of 0x0, ret(dobuserr_common).

- `pci_error_intr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x10b48 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x10b48-0x10bb8 (112 bytes).
  It occupies 112 bytes.
  The `jal` at 0x10b58 calls pciio_pio_read32 with a0=0xffffffffbf080004, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x10b64 calls pciio_pio_read32 with a0=0xffffffffbf080000, a1=?, a2=?, a3=?.
  The `jal` at 0x10b88 calls pciio_pio_write32 with a0=0x0, a1=0xffffffffbf080004, a2=?, a3=?.
  The `jal` at 0x10ba8 calls cmn_err with a0=0x0, a1=sym(.rodata)+7840, a2=ret(pciio_pio_read32), a3=ret(pciio_pio_read32).
  The `bne` branch at 0x10b74 targets 0x10b9c, is taken when (s0(=ret(pciio_pio_read32)) & a1(=0x3d000000)) != 0, and falls through when (s0(=ret(pciio_pio_read32)) & a1(=0x3d000000)) == 0.
  The `beq` branch at 0x10bb0 targets 0x10b80 and is always taken.
  The return at 0x10b94 has v0 = ret(pciio_pio_write32).

- `reset_leds` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x10df8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x10df8-0x10e24 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0x10e00 loads 8 bytes from abs 0xffffffffbf310008.
  The `sd` at 0x10e14 stores 8 bytes to abs 0xffffffffbf310008.
  The `jal` at 0x10e10 calls set_leds with a0=0x0, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The return at 0x10e1c has v0 = ret(set_leds).

- `bump_leds` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x10e40 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x10e40-0x10eac (108 bytes).
  It occupies 108 bytes.
  The `ld` at 0x10e60 loads 8 bytes from abs 0xffffffffbf310008.
  The `jal` at 0x10e80 calls set_leds with a0=0x0, a1=[sym(last_bump_time)], a2=[0xffffffffbf310008]:8, a3=[sym(time)], a4=[sym(do_bump_leds)].
  The `jal` at 0x10e94 calls set_leds with a0=?, a1=[sym(last_bump_time)], a2=[0xffffffffbf310008]:8, a3=[sym(time)], a4=[sym(do_bump_leds)].
  The `bne` branch at 0x10e44 targets 0x10e6c, is taken when at(=[sym(power_off_flag)]) != 0, and falls through when at(=[sym(power_off_flag)]) == 0.
  The `beq` branch at 0x10e5c targets 0x10e74, is taken when a4(=[sym(do_bump_leds)]) == 0, and falls through when a4(=[sym(do_bump_leds)]) != 0.
  The `bne` branch at 0x10e64 targets 0x10e90, is taken when a3(=[sym(time)]) != a1(=[sym(last_bump_time)]), and falls through when a3(=[sym(time)]) == a1(=[sym(last_bump_time)]).
  The `bne` branch at 0x10e78 targets 0x10e6c, is taken when (a2(=[0xffffffffbf310008]:8) & 0x10) != 0, and falls through when (a2(=[0xffffffffbf310008]:8) & 0x10) == 0.
  The `beq` branch at 0x10e88 targets 0x10e6c and is always taken.
  The `beq` branch at 0x10ea4 targets 0x10e6c and is always taken.
  The return at 0x10e6c has v0 = one of ?, ret(set_leds).

- `set_leds` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x10eac (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x10eac-0x10ee0 (52 bytes).
  It occupies 52 bytes.
  The `ld` at 0x10eb4 loads 8 bytes from abs 0xffffffffbf310008.
  The `sd` at 0x10ed0 stores 8 bytes to abs 0xffffffffbf310008.
  The `beq` branch at 0x10eb8 targets 0x10ed4, is taken when a0 == 0, and falls through when a0 != 0.
  The `beq` branch at 0x10ed8 targets 0x10ec4 and is always taken.
  The return at 0x10ecc has v0 = ?.

- `cpu_powerdown` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x11124 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x11124-0x111e0 (188 bytes).
  It occupies 188 bytes.
  The `lbu` at 0x1116c loads 1 byte from abs 0xffffffffbf3a0a07.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a0a07, including `sb` at 0x1118c, `sb` at 0x111b8.
  The `lbu` at 0x11190 loads 1 byte from abs 0xffffffffbf3a4b07.
  The `sb` at 0x11198 stores 1 byte to abs 0xffffffffbf3a4b07.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a4a07, including `lbu` at 0x1119c, `lbu` at 0x111a8.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a4a07, including `sb` at 0x111a4, `sb` at 0x111b0.
  The `jal` at 0x11148 calls flash_write_env with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11188 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x111b4 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x111bc calls us_delay with a0=0xf4240, a1=?, a2=?, a3=?.
  The `jal` at 0x111c8 calls cmn_err with a0=0x4, a1=sym(.rodata)+7896, a2=?, a3=?.
  The `jal` at 0x111d0 calls us_delay with a0=0xf4240, a1=?, a2=?, a3=?.
  The `beq` branch at 0x111d8 targets 0x11188 and is always taken.

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
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x1121c-0x112e0 (196 bytes).
  It occupies 196 bytes.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a0a07, including `lbu` at 0x1126c, `lbu` at 0x11294.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a0a07, including `sb` at 0x11278, `sb` at 0x1129c.
  The `lbu` at 0x1127c loads 1 byte from abs 0xffffffffbf3a4a07.
  The `ld` at 0x112b0 loads 8 bytes from abs 0xffffffffbf310010.
  The `lbu` at 0x112c0 loads 1 byte from abs 0xffffffffbf3a0c07.
  The `jal` at 0x11238 calls flash_write_env with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11274 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x1128c calls cpu_powerdown with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x112a0 calls splx with a0=ret(spl7), a1=?, a2=?, a3=?.
  The `jal` at 0x112a8 calls spl7 with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x112d0 calls cmn_err with a0=0x4, a1=sym(.rodata)+7896, a2=?, a3=?.
  The `beq` branch at 0x11264 targets 0x112a8 and is always taken.
  The `beq` branch at 0x11284 targets 0x11294, is taken when (t9(=[0xffffffffbf3a4a07]:1) & 0x1) == 0, and falls through when (t9(=[0xffffffffbf3a4a07]:1) & 0x1) != 0.
  The `beq` branch at 0x112b8 targets 0x112a0, is taken when (at(=[0xffffffffbf310010]:8) & 0x100) == 0, and falls through when (at(=[0xffffffffbf310010]:8) & 0x100) != 0.
  The `bne` branch at 0x112c8 targets 0x1126c, is taken when (v0(=[0xffffffffbf3a0c07]:1) & 0x80) != 0, and falls through when (v0(=[0xffffffffbf3a0c07]:1) & 0x80) == 0.
  The `beq` branch at 0x112d8 targets 0x1126c and is always taken.

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

- `power_dump` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x112e0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x112e0-0x11410 (304 bytes).
  It occupies 304 bytes.
  The `ld` at 0x1130c loads 8 bytes from abs 0xffffffffbf310010.
  The `jal` at 0x112f0 calls splprof with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x11328 calls us_delay with a0=0x7a120, a1=?, a2=?, a3=?.
  The `jal` at 0x11338 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x11348 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x11350 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x11360 calls pciio_pio_read8 with a0=0xffffffffbf3a4a07, a1=?, a2=?, a3=?.
  The `jal` at 0x1136c calls pciio_pio_read8 with a0=0xffffffffbf3a4a07, a1=?, a2=?, a3=?.
  The `jal` at 0x11380 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a4a07, a2=?, a3=?.
  The `jal` at 0x11388 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x1139c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x113a4 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x113c8 calls cmn_err_tag with a0=0x3d, a1=0x0, a2=sym(.rodata)+7896, a3=sym(.rodata)+7896.
  The `jal` at 0x113d0 calls splx with a0=ret(splprof), a1=?, a2=?, a3=?.
  The `jal` at 0x11400 calls splx with a0=ret(splprof), a1=?, a2=?, a3=?.
  The `beq` branch at 0x11304 targets 0x11318, is taken when s2(=a0) == 0, and falls through when s2(=a0) != 0.
  The `beq` branch at 0x11314 targets 0x11400, is taken when (at(=[0xffffffffbf310010]:8) & 0x100) == 0, and falls through when (at(=[0xffffffffbf310010]:8) & 0x100) != 0.
  The `beq` branch at 0x113ac targets 0x113f4, is taken when s2(=a0) == 0, and falls through when s2(=a0) != 0.
  The `beq` branch at 0x113f8 targets 0x113c0 and is always taken.
  The `beq` branch at 0x11408 targets 0x113dc and is always taken.
  The return at 0x113ec has v0 = ret(splx).

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
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x11410-0x115e8 (472 bytes).
  It occupies 472 bytes.
  The `ld` at 0x11414 loads 8 bytes from abs 0xffffffffbf310010.
  The `lbu` at 0x11444 loads 1 byte from abs 0xffffffffbf3a0c07.
  The `jal` at 0x11438 calls power_dump with a0=0x0, a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1145c calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x1146c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x11474 calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x11484 calls pciio_pio_read8 with a0=0xffffffffbf3a4a07, a1=?, a2=?, a3=?.
  The `jal` at 0x11490 calls pciio_pio_read8 with a0=0xffffffffbf3a4a07, a1=?, a2=?, a3=?.
  The `jal` at 0x114a4 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a4a07, a2=?, a3=?.
  The `jal` at 0x114b0 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x114c4 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x114cc calls flushbus with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x11508 calls flash_led [0x10d40] with a0=0x3, a1=0x1, a2=?, a3=?.
  The `jal` at 0x11524 calls sigtopid with a0=0x1, a1=0x2, a2=0x12, a3=0x0, a4=0x0, a5=0x0.
  The `jal` at 0x1154c calls timeout with a0=sym(cpu_godown), a1=0x0, a2=?, a3=[sym(clean_shutdown_time)].
  The `jal` at 0x1155c calls set_autopoweron with a0=?, a1=?, a2=?, a3=[sym(lbolt)]+100.
  The `jal` at 0x11578 calls cmn_err with a0=0x4, a1=sym(.rodata)+7896, a2=?, a3=?.
  The `jal` at 0x11594 calls cmn_err with a0=0x4, a1=sym(.rodata)+7896, a2=?, a3=?.
  The `jal` at 0x115ac calls cmn_err with a0=0x4, a1=sym(.rodata)+7896, a2=ret(pciio_pio_read8), a3=?.
  The `jal` at 0x115bc calls us_delay with a0=0x2710, a1=0x1, a2=?, a3=?.
  The `jal` at 0x115d0 calls cmn_err with a0=0x5, a1=sym(.rodata)+7896, a2=?, a3=?.
  The `jal` at 0x115d8 calls cpu_powerdown with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x11428 targets 0x114f8, is taken when (at(=[0xffffffffbf310010]:8) & 0x100) == 0, and falls through when (at(=[0xffffffffbf310010]:8) & 0x100) != 0.
  The `beq` branch at 0x11430 targets 0x11444, is taken when v0(=[sym(power_button_changed_to_crash_dump)]) == 0, and falls through when v0(=[sym(power_button_changed_to_crash_dump)]) != 0.
  The `beq` branch at 0x1144c targets 0x1156c, is taken when (v0(=[0xffffffffbf3a0c07]:1) & 0x80) == 0, and falls through when (v0(=[0xffffffffbf3a0c07]:1) & 0x80) != 0.
  The `beq` branch at 0x114dc targets 0x11588, is taken when (s2(=ret(pciio_pio_read8)) & 0x1) == 0, and falls through when (s2(=ret(pciio_pio_read8)) & 0x1) != 0.
  The `beq` branch at 0x114e8 targets 0x11508, is taken when a0(=[sym(.sbss)+260]) == 0, and falls through when a0(=[sym(.sbss)+260]) != 0.
  The `bne` branch at 0x114f4 targets 0x115bc, is taken when a0(=[sym(.sbss)+260]) < v0(=[sym(lbolt)]) (signed), and falls through when a0(=[sym(.sbss)+260]) >= v0(=[sym(lbolt)]) (signed).
  The `beq` branch at 0x11564 targets 0x114fc and is always taken.
  The `beq` branch at 0x11580 targets 0x11454 and is always taken.
  The `beq` branch at 0x115b4 targets 0x114fc and is always taken.
  The `beq` branch at 0x115e0 targets 0x114fc and is always taken.
  The return at 0x11500 has v0 = one of [sym(lbolt)], ?, ret(set_autopoweron), ret(cmn_err), ret(cpu_powerdown).

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

- `absolute_rtc_current_time` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x11820 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x11820-0x11838 (24 bytes).
  It occupies 24 bytes.
  The `ld` at 0x11828 loads 8 bytes from abs 0xffffffffb4000038.
  The return at 0x11830 has v0 = ?.

- `get_crimerev` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x11838 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x11838-0x11898 (96 bytes).
  It occupies 96 bytes.
  The `ld` at 0x1184c loads 8 bytes from abs 0xffffffffb4000000.
  The `beq` branch at 0x11844 targets 0x1187c, is taken when at(=[sym(.sdata)+248]) == 0, and falls through when at(=[sym(.sdata)+248]) != 0.
  The `beq` branch at 0x1185c targets 0x11868, is taken when (a5(=[0xffffffffb4000000]:8) & 0xf) == 0, and falls through when (a5(=[0xffffffffb4000000]:8) & 0xf) != 0.
  The `beq` branch at 0x11868 targets 0x11890, is taken when a2(?) == 0, and falls through when a2(?) != 0.
  The `beq` branch at 0x11870 targets 0x11884, is taken when a2(?) == a3(=0x1), and falls through when a2(?) != a3(=0x1).
  The return at 0x1187c has v0 = one of [sym(.sdata)+244], 0x14.
  The return at 0x11888 has v0 = 0x13.
  The return at 0x11890 has v0 = ?.

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

- `flushbus` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x11ccc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x11ccc-0x11cf8 (44 bytes).
  It occupies 44 bytes.
  The `ld` at 0x11cd4 loads 8 bytes from abs 0xffffffffb4000008.
  The return at 0x11cf0 has v0 = ?.

- `kvmiss_hit` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x121a4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x121a4-0x122b4 (272 bytes).
  It occupies 272 bytes.
  The `sd` at 0x121b8 stores 8 bytes to sym(_assregs) +0x18.
  The `sd` at 0x121c4 stores 8 bytes to sym(_assregs) +0x20.
  The `sd` at 0x121d0 stores 8 bytes to sym(_assregs) +0x28.
  Calls assfail via direct with a0=sym(.data)+10380, a1=sym(.data)+10399, a2=0x0, a3=a3 at entry (arg3) (`j` at 0x121e8).
  The `beq` branch at 0x121a4 targets 0x121ac and is always taken.
  The instructions from 0x121f0 to 0x122b0 are not reached by any path from the entry, and their branches are not listed.

- `rtc_init` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x121f4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x121f4-0x122b4 (192 bytes).
  It occupies 192 bytes.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a0b07, including `lbu` at 0x12218, `lbu` at 0x12228.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a0b07, including `sb` at 0x12224, `sb` at 0x12230.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a0a07, including `lbu` at 0x12234, `lbu` at 0x12278.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a0a07, including `sb` at 0x1223c, `sb` at 0x12290.
  The `lbu` at 0x12240 loads 1 byte from abs 0xffffffffbf3a4a07.
  The `sb` at 0x1224c stores 1 byte to abs 0xffffffffbf3a4a07.
  2 such `lbu` accesses load 1 byte from abs 0xffffffffbf3a4b07, including `lbu` at 0x12250, `lbu` at 0x12260.
  2 such `sb` accesses store 1 byte to abs 0xffffffffbf3a4b07, including `sb` at 0x1225c, `sb` at 0x1226c.
  The `jal` at 0x1220c calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1228c calls pciio_pio_read64 with a0=0xffffffffbf310018, a1=-0x20, a2=([0xffffffffbf3a4b07]:1 | 0x9), a3=?, a4=-0x53, a6=-0x4, a7=([0xffffffffbf3a0a07]:1 | 0x10).
  The `jal` at 0x1229c calls pciio_pio_write64 with a0=(ret(pciio_pio_read64) | 0x100), a1=0xffffffffbf310018, a2=?, a3=?.
  The `jal` at 0x122a4 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `beq` branch at 0x121fc targets 0x1220c, is taken when at(=[sym(.sdata)+252]) == 0, and falls through when at(=[sym(.sdata)+252]) != 0.
  The `beq` branch at 0x122ac targets 0x12204 and is always taken.
  The return at 0x12204 has v0 = one of ?, ret(splx).

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

- `_clock_func` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x129e8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x129e8-0x12c28 (576 bytes).
  It occupies 576 bytes.
  The `sb` at 0x12a94 stores 1 byte to a1 (arg1 at entry) +0x0.
  The `sb` at 0x12aa0 stores 1 byte to a1 (arg1 at entry) +0x1.
  The `sb` at 0x12ab4 stores 1 byte to a1 (arg1 at entry) +0x2.
  The `sb` at 0x12ac4 stores 1 byte to a1 (arg1 at entry) +0x3.
  The `sb` at 0x12ad4 stores 1 byte to a1 (arg1 at entry) +0x4.
  The `sb` at 0x12ae0 stores 1 byte to a1 (arg1 at entry) +0x5.
  The `sb` at 0x12af0 stores 1 byte to a1 (arg1 at entry) +0x6.
  The `sb` at 0x12b00 stores 1 byte to a1 (arg1 at entry) +0x7.
  The `lbu` at 0x12b50 loads 1 byte from a1 (arg1 at entry) +0x0.
  The `lbu` at 0x12b60 loads 1 byte from a1 (arg1 at entry) +0x1.
  The `lbu` at 0x12b6c loads 1 byte from a1 (arg1 at entry) +0x2.
  The `lbu` at 0x12b84 loads 1 byte from a1 (arg1 at entry) +0x3.
  The `lbu` at 0x12b90 loads 1 byte from a1 (arg1 at entry) +0x4.
  The `lbu` at 0x12b9c loads 1 byte from a1 (arg1 at entry) +0x5.
  The `lbu` at 0x12ba8 loads 1 byte from a1 (arg1 at entry) +0x6.
  The `lbu` at 0x12bb4 loads 1 byte from a1 (arg1 at entry) +0x7.
  The `jal` at 0x129f8 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12a58 calls pciio_pio_read8 with a0=0xffffffffbf3a0b07, a1=?, a2=?, a3=?.
  The `jal` at 0x12a68 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0b07, a2=?, a3=?.
  The `jal` at 0x12a70 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12a80 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12a88 calls pciio_pio_read8 with a0=0xffffffffbf3a0007, a1=?, a2=?, a3=?.
  The `jal` at 0x12a98 calls pciio_pio_read8 with a0=0xffffffffbf3a0207, a1=?, a2=?, a3=?.
  The `jal` at 0x12aa4 calls pciio_pio_read8 with a0=0xffffffffbf3a0407, a1=?, a2=?, a3=?.
  The `jal` at 0x12ab8 calls pciio_pio_read8 with a0=0xffffffffbf3a0707, a1=?, a2=?, a3=?.
  The `jal` at 0x12ac8 calls pciio_pio_read8 with a0=0xffffffffbf3a0807, a1=?, a2=?, a3=?.
  The `jal` at 0x12ad8 calls pciio_pio_read8 with a0=0xffffffffbf3a0907, a1=?, a2=?, a3=?.
  The `jal` at 0x12ae4 calls pciio_pio_read8 with a0=0xffffffffbf3a0607, a1=?, a2=?, a3=?.
  The `jal` at 0x12af4 calls pciio_pio_read8 with a0=0xffffffffbf3a4807, a1=?, a2=?, a3=?.
  The `jal` at 0x12b04 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12b14 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12b1c calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12b30 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12b38 calls pciio_pio_read8 with a0=0xffffffffbf3a0b07, a1=?, a2=?, a3=?.
  The `jal` at 0x12b48 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0b07, a2=?, a3=?.
  The `jal` at 0x12b54 calls pciio_pio_write8 with a0=[a1]:1, a1=0xffffffffbf3a0007, a2=?, a3=?.
  The `jal` at 0x12b64 calls pciio_pio_write8 with a0=[a1+1]:1, a1=0xffffffffbf3a0207, a2=?, a3=?.
  The `jal` at 0x12b78 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0407, a2=?, a3=?.
  The `jal` at 0x12b88 calls pciio_pio_write8 with a0=[a1+3]:1, a1=0xffffffffbf3a0707, a2=?, a3=?.
  The `jal` at 0x12b94 calls pciio_pio_write8 with a0=[a1+4]:1, a1=0xffffffffbf3a0807, a2=?, a3=?.
  The `jal` at 0x12ba0 calls pciio_pio_write8 with a0=[a1+5]:1, a1=0xffffffffbf3a0907, a2=?, a3=?.
  The `jal` at 0x12bac calls pciio_pio_write8 with a0=[a1+6]:1, a1=0xffffffffbf3a0607, a2=?, a3=?.
  The `jal` at 0x12bb8 calls pciio_pio_write8 with a0=[a1+7]:1, a1=0xffffffffbf3a4807, a2=?, a3=?.
  The `jal` at 0x12be0 calls pciio_pio_read8 with a0=0xffffffffbf3a0b07, a1=?, a2=?, a3=?.
  The `jal` at 0x12bf4 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0b07, a2=?, a3=?.
  The `jal` at 0x12c00 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `jal` at 0x12c18 calls rtc_init [0x121f4] with a0=?, a1=?, a2=?, a3=?.
  The `beq` branch at 0x12a24 targets 0x12c18, is taken when at(=[sym(.sdata)+252]) == 0, and falls through when at(=[sym(.sdata)+252]) != 0.
  The `bne` branch at 0x12a50 targets 0x12b04, is taken when t8(=a0) != 0, and falls through when t8(=a0) == 0.
  The `beq` branch at 0x12afc targets 0x12bc0 and is always taken.
  The `beq` branch at 0x12c20 targets 0x12a30 and is always taken.
  The return at 0x12c10 has v0 = ret(splx).

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

- `read_dallas_nvram` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12c28 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x12c28-0x12d00 (216 bytes).
  It occupies 216 bytes.
  The `sb` at 0x12ccc stores 1 byte to ?.
  The `jal` at 0x12c58 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12c68 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12c84 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12cb4 calls pciio_pio_read8 with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x12cd8 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `beq` branch at 0x12c44 targets 0x12cf8, is taken when at(=(a1 + a2)) >= 0x72 (signed), and falls through when at(=(a1 + a2)) < 0x72 (signed).
  The `blez` branch at 0x12c50 targets 0x12cf8, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0x12ca0 targets 0x12cd0, is taken when s1(=a2-1) == s3(=-0x1), and falls through when s1(=a2-1) != s3(=-0x1).
  The `bne` branch at 0x12cc8 targets 0x12cb4, is taken when s1(?) != s3(=-0x1), and falls through when s1(?) == s3(=-0x1).
  The `beq` branch at 0x12cf8 targets 0x12cec and is always taken.
  The return at 0x12cf0 has v0 = one of 0x0, 0x1.

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

- `write_dallas_nvram` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12d00 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x12d00-0x12dd8 (216 bytes).
  It occupies 216 bytes.
  The `lbu` at 0x12d8c loads 1 byte from ?.
  The `jal` at 0x12d30 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12d40 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12d5c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12d90 calls pciio_pio_write8 with a0=?, a1=?, a2=?, a3=?.
  The `jal` at 0x12db0 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The `beq` branch at 0x12d1c targets 0x12dd0, is taken when at(=(a1 + a2)) >= 0x72 (signed), and falls through when at(=(a1 + a2)) < 0x72 (signed).
  The `blez` branch at 0x12d28 targets 0x12dd0, is taken when a1 <= 0 (signed), and falls through when a1 > 0 (signed).
  The `beq` branch at 0x12d74 targets 0x12da8, is taken when s2(=a2-1) == s3(=-0x1), and falls through when s2(=a2-1) != s3(=-0x1).
  The `bne` branch at 0x12da0 targets 0x12d8c, is taken when s2(?) != s3(=-0x1), and falls through when s2(?) == s3(=-0x1).
  The `beq` branch at 0x12dd0 targets 0x12dc4 and is always taken.
  The return at 0x12dc8 has v0 = one of 0x0, 0x1.

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

- `setbadclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12dd8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x12dd8-0x12e48 (112 bytes).
  It occupies 112 bytes.
  The `jal` at 0x12de0 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12df0 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12e08 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12e14 calls pciio_pio_read8 with a0=0xffffffffbf3a0e07, a1=?, a2=?, a3=?.
  The `jal` at 0x12e28 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0e07, a2=?, a3=?.
  The `jal` at 0x12e30 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The return at 0x12e40 has v0 = ret(splx).

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

- `clearbadclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12e48 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x12e48-0x12ebc (116 bytes).
  It occupies 116 bytes.
  The `jal` at 0x12e50 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12e60 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12e78 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12e84 calls pciio_pio_read8 with a0=0xffffffffbf3a0e07, a1=?, a2=?, a3=?.
  The `jal` at 0x12e9c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0e07, a2=?, a3=?.
  The `jal` at 0x12ea4 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The return at 0x12eb4 has v0 = ret(splx).

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

- `isbadclock` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12ebc (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x12ebc-0x12f20 (100 bytes).
  It occupies 100 bytes.
  The `jal` at 0x12ec4 calls splhi with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x12ed4 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x12eec calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x12ef8 calls pciio_pio_read8 with a0=0xffffffffbf3a0e07, a1=?, a2=?, a3=?.
  The `jal` at 0x12f04 calls splx with a0=ret(splhi), a1=?, a2=?, a3=?.
  The return at 0x12f18 has v0 = ?.

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

- `set_autopoweron` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x12f20 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x12f20-0x131d8 (696 bytes).
  It occupies 696 bytes.
  2 such `lw` accesses load 4 bytes from sym(.data) +0x28a8, including `lw` at 0x12fa0, `lw` at 0x12fc0.
  3 such `lw` accesses load 4 bytes from sym(.data) +0x28ac, including `lw` at 0x12fc8, `lw` at 0x12ff4, `lw` at 0x130f4.
  2 such `sw` accesses store 4 bytes to sym(.data) +0x28ac, including `sw` at 0x13100, `sw` at 0x1310c.
  The `jal` at 0x12f44 calls get_dayof_week [0x131d8] with a0=[sym(autopoweron_alarm)], a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3).
  The `jal` at 0x1312c calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0307, a2=?, a3=?.
  The `jal` at 0x13150 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0507, a2=?, a3=?.
  The `jal` at 0x13160 calls pciio_pio_read8 with a0=0xffffffffbf3a0a07, a1=?, a2=?, a3=?.
  The `jal` at 0x13174 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a0a07, a2=?, a3=?.
  The `jal` at 0x13198 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a4907, a2=?, a3=?.
  The `jal` at 0x131a8 calls pciio_pio_write8 with a0=0xc0, a1=0xffffffffbf3a0107, a2=?, a3=?.
  The `jal` at 0x131b8 calls pciio_pio_read8 with a0=0xffffffffbf3a4b07, a1=?, a2=?, a3=?.
  The `jal` at 0x131c8 calls pciio_pio_write8 with a0=?, a1=0xffffffffbf3a4b07, a2=?, a3=?.
  The `bne` branch at 0x12f3c targets 0x130bc, is taken when a0(=[sym(autopoweron_alarm)]) < at(=[sym(time)]) (unsigned), and falls through when a0(=[sym(autopoweron_alarm)]) >= at(=[sym(time)]) (unsigned).
  The `beq` branch at 0x12f5c targets 0x12f68 and is always taken.
  The `beq` branch at 0x12f8c targets 0x130d4, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `beq` branch at 0x12f94 targets 0x12f64, is taken when a4(?) == 0, and falls through when a4(?) != 0.
  The `bne` branch at 0x12fb4 targets 0x12ff0, is taken when s0(?) < a5(?) (unsigned), and falls through when s0(?) >= a5(?) (unsigned).
  The `beq` branch at 0x12fe8 targets 0x12fc0, is taken when s0(?) >= a2(?) (unsigned), and falls through when s0(?) < a2(?) (unsigned).
  The `beq` branch at 0x12ff0 targets 0x13104, is taken when a7(?) == 0, and falls through when a7(?) != 0.
  The `bne` branch at 0x13008 targets 0x13038, is taken when s0(?) < a0(=0x15180) (unsigned), and falls through when s0(?) >= a0(=0x15180) (unsigned).
  The `bne` branch at 0x13020 targets 0x13038, is taken when s0(=table(0xfffffffffffeae80)) < a0(=0x15180) (unsigned), and falls through when s0(=table(0xfffffffffffeae80)) >= a0(=0x15180) (unsigned).
  The `beq` branch at 0x13030 targets 0x13014, is taken when s0(=table(0xfffffffffffd5d00)) >= a0(=0x15180) (unsigned), and falls through when s0(=table(0xfffffffffffd5d00)) < a0(=0x15180) (unsigned).
  The `bne` branch at 0x1303c targets 0x1306c, is taken when s0(?) < 0xe10 (unsigned), and falls through when s0(?) >= 0xe10 (unsigned).
  The `bne` branch at 0x13054 targets 0x1306c, is taken when s0(?) < 0xe10 (unsigned), and falls through when s0(?) >= 0xe10 (unsigned).
  The `beq` branch at 0x13064 targets 0x13048, is taken when s0(?) >= 0xe10 (unsigned), and falls through when s0(?) < 0xe10 (unsigned).
  The `bne` branch at 0x13074 targets 0x130ac, is taken when s0(?) < 0x3c (unsigned), and falls through when s0(?) >= 0x3c (unsigned).
  The `bne` branch at 0x1308c targets 0x130a0, is taken when s0(?) < 0x3c (unsigned), and falls through when s0(?) >= 0x3c (unsigned).
  The `beq` branch at 0x13098 targets 0x13080, is taken when s0(?) >= 0x3c (unsigned), and falls through when s0(?) < 0x3c (unsigned).
  The `beq` branch at 0x130a4 targets 0x130c0, is taken when a4(?) >= 0x3c (signed), and falls through when a4(?) < 0x3c (signed).
  The `beq` branch at 0x130ac targets 0x130c0, is taken when a0(?) == 0, and falls through when a0(?) != 0.
  The `bne` branch at 0x130b4 targets 0x13110, is taken when a5(?) != 0, and falls through when a5(?) == 0.
  The `bne` branch at 0x130dc targets 0x130ec, is taken when s0(?) < t0(=0x1e28500) (signed), and falls through when s0(?) >= t0(=0x1e28500) (signed).
  The `beq` branch at 0x130e4 targets 0x12f68 and is always taken.
  The `beq` branch at 0x130fc targets 0x12f98 and is always taken.
  The `beq` branch at 0x13108 targets 0x12ff8 and is always taken.
  The `beq` branch at 0x131d0 targets 0x130c0 and is always taken.
  The return at 0x130cc has v0 = one of ret(get_dayof_week), ?, ret(pciio_pio_write8).

- `_ticksper1024inst` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x140c0 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x140c0-0x140f8 (56 bytes).
  It occupies 56 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000038, including `ld` at 0x140d0, `ld` at 0x140dc.
  The `bgtz` branch at 0x140d4 targets 0x140d4, is taken when t1(?) > 0 (signed), and falls through when t1(?) <= 0 (signed).
  The `bgtz` branch at 0x140e8 targets 0x140d0, is taken when t3(?) > 0 (signed), and falls through when t3(?) <= 0 (signed).
  The return at 0x140f0 has v0 = ?.

- `_cpuclkper100ticks` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x140f8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x140f8-0x141a4 (172 bytes).
  It occupies 172 bytes.
  The `sd` at 0x14130 stores 8 bytes to abs 0xffffffffb4000038.
  The `ld` at 0x14138 loads 8 bytes from abs 0xffffffffb4000038.
  The `sw` at 0x1418c stores 4 bytes to a0 (arg0 at entry) +0x0.
  The `bne` branch at 0x1414c targets 0x14138, is taken when t2(?) < t0(=0x5bc8) (unsigned), and falls through when t2(?) >= t0(=0x5bc8) (unsigned).
  The `bne` branch at 0x1415c targets 0x1412c, is taken when t3(?) != 0, and falls through when t3(?) == 0.
  The `bne` branch at 0x14174 targets 0x14180 and is always taken.
  The `bne` branch at 0x14190 targets 0x1419c and is always taken.
  The return at 0x1419c has v0 = ?.
  The instructions from 0x1417c to 0x1417c are not reached by any path from the entry, and their branches are not listed.
  The instructions from 0x14198 to 0x14198 are not reached by any path from the entry, and their branches are not listed.

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

- `delay_calibrate` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x141a4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x141a4-0x14228 (132 bytes).
  It occupies 132 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000038, including `ld` at 0x141b4, `ld` at 0x141dc.
  The `sw` at 0x14210 stores 4 bytes to abs 0xffffffffffffa248.
  The `bgtz` branch at 0x141d4 targets 0x141b8, is taken when t1(?) > 0 (signed), and falls through when t1(?) <= 0 (signed).
  The `bgtz` branch at 0x141ec targets 0x141b4, is taken when t3(?) > 0 (signed), and falls through when t3(?) <= 0 (signed).
  The `bne` branch at 0x14214 targets 0x14220 and is always taken.
  The return at 0x14220 has v0 = ?.
  The instructions from 0x1421c to 0x1421c are not reached by any path from the entry, and their branches are not listed.

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

- `badaddr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x14270
  Probes one address with a 1, 2, 4 or 8 byte load chosen by the size in a1: `lb` at 0x142dc, `lh` at 0x142f4, `lw` at 0x1430c and `ld` at 0x14324 all read through a0. Any other size reaches the `cmn_err` call at 0x14338. The normal return at 0x143a0 gives v0 = 0, and the facts do not show how a faulting load is caught here, though the probe shape suggests it reports whether the address is readable. A mask test of the doubleword at 0xffffffffb4000028 at 0x14374 sends control to 0x149a8 when a bit is set, and that path is not rendered.
  Grade: inferred.
  Reviewed: 2026-11-12

- `badaddr_val` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x143a8
  It uses the same size dispatch as `badaddr`, but the loaded value is also stored through a2 at 0x1442c, 0x1444c, 0x1446c or 0x1448c, which suggests the value is handed back to the caller. The word at -0x5fe8 is tested at 0x14400 and again at 0x144e8. When it is zero, the halfword store through it at +0xc2 (0x14408, 0x144f0) is skipped, and the word store to 0xffffffffffffa1d8 at 0x14414 (and 0x144fc) is reached either way. The normal return at 0x1451c gives v0 = 0, and an unrecognised size reaches `cmn_err` at 0x144a0.
  Grade: inferred.
  Reviewed: 2026-11-12

- `wbadaddr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x14524
  It writes a value of the size in a1 to a0, using `sb` at 0x14590, `sh` at 0x145a8, `sw` at 0x145c0 or `sd` at 0x145d8, and an unrecognised size reaches `cmn_err` at 0x145ec. The facts do not name the register holding the stored value, so what gets written stays open. On the way out it reads the doubleword at 0xffffffffb4000008 and the word at 0xffffffffa0000000, which is the uncached start of physical memory, and returns v0 = 0 at 0x14680. The store-only shape suggests a write probe, but the fault handling is not rendered.
  Grade: inferred.
  Reviewed: 2026-11-12

- `earlybadaddr` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x14808
  It probes with 1, 2 or 4 byte loads chosen by a1 (`lb` at 0x14878, `lh` at 0x14890, `lw` at 0x148a8), and sizes 8 and anything else reach `cmn_err` at 0x148bc. It stores 4 bytes to the `nofault` symbol at 0x14868 and again at 0x14908, which suggests it arms and clears a fault catch around the access, though the handler is not rendered. The name suggests a probe used before normal memory setup, which the facts neither confirm nor rule out.
  Grade: inferred.
  Reviewed: 2026-11-12

- `baerror` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x149a8 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x149a8-0x14a0c (100 bytes).
  It occupies 100 bytes.
  The `sd` at 0x149ac stores 8 bytes to abs 0xffffffffb4000048.
  The `sd` at 0x149b0 stores 8 bytes to abs 0xffffffffb4000250.
  The `ld` at 0x149b4 loads 8 bytes from abs 0xffffffffb4000250.
  The `ld` at 0x149b8 loads 8 bytes from abs 0xffffffffb4000048.
  The `sw` at 0x149c4 stores 4 bytes to abs 0xffffffffbf080004.
  The `lw` at 0x149c8 loads 4 bytes from abs 0xffffffffbf080004.
  The `lw` at 0x149e0 loads 4 bytes from abs 0xffffffffffffa018.
  The `sh` at 0x149ec stores 2 bytes to [-0x5fe8] +0xc2.
  The `sw` at 0x149f8 stores 4 bytes to abs 0xffffffffffffa1d8.
  The `beq` branch at 0x149e4 targets 0x149f8, is taken when t2(=[-0x5fe8]) == 0, and falls through when t2(=[-0x5fe8]) != 0.
  The `beq` branch at 0x149f0 targets 0x149fc and is always taken.
  The return at 0x14a04 has v0 = 0x1.

- `baerror` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x149a8 (n32).
  Inferred: it works on CRIME's Memory Error Status at offset 0x250 (linked row `CRIME 0x250 Memory Error Status`; the reviewed datasheet gives that register invalid-address bits 25 for a read, 26 for a write and 27 for a read-modify-write), on the CRIME register at offset 0x48, and on a word in a second window at `0xffffffffbf080004`. It writes zero to the doubleword at offset 0x48 (the `sd` at 0x149ac) and to the doubleword at offset 0x250 (the `sd` at 0x149b0), reads both back (the `ld` at 0x149b4 and 0x149b8), then writes zero to `0xffffffffbf080004` (the `sw` at 0x149c4) and reads it back (the `lw` at 0x149c8). It loads the word at `0xffffffffffffa018` into t2 (the `lw` at 0x149e0) and branches to the store at 0x149f8 when that word is zero (the `beq` at 0x149e4), and that store writes a zero word to `0xffffffffffffa1d8`. When the word is not zero, it writes a zero halfword at offset 0xc2 from that word (the `sh` at 0x149ec) and then branches to the return path (the `beq` at 0x149f0). Either way it sets v0 to 1 in the delay slot at 0x149e8, loads ra from the entry stack pointer plus 0x8 (the `ld` at 0x149fc), and returns at 0x14a04. Unknown: the chip behind the window at `0xffffffffbf080000`, since no linked row names it; the route is a linked row for that window or the datasheet of the chip that owns it. Unknown: which CRIME 1.5 register sits at offset 0x48, since its linked row has no name; the route is the CRIME 1.5 register table that holds the linked spec row for offset 0x250. Unknown: the object that the halfword write at offset 0xc2 lands in, since the word at `0xffffffffffffa018` is only loaded here and its writer is not in the bundle; the route is the writer of that word or a trace of its value.
  Evidence grade: inferred.

- `earlybaerror` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x14a0c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x14a0c-0x14a64 (88 bytes).
  It occupies 88 bytes.
  The `sd` at 0x14a10 stores 8 bytes to abs 0xffffffffb4000048.
  The `sd` at 0x14a14 stores 8 bytes to abs 0xffffffffb4000250.
  The `ld` at 0x14a18 loads 8 bytes from abs 0xffffffffb4000250.
  The `ld` at 0x14a1c loads 8 bytes from abs 0xffffffffb4000048.
  The `sw` at 0x14a28 stores 4 bytes to abs 0xffffffffbf080004.
  The `lw` at 0x14a2c loads 4 bytes from abs 0xffffffffbf080004.
  The `sw` at 0x14a4c stores 4 bytes to sym(nofault) +0x0.
  The return at 0x14a5c has v0 = 0x1.

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

- `stkscr3` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x1945c (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x1945c-0x194f0 (148 bytes).
  It occupies 148 bytes.
  The `sw` at 0x19470 stores 4 bytes to sym(ovflwword) +0x0.
  The `lb` at 0x19480 loads 1 byte from abs 0xffffffffffffa03f.
  The `sb` at 0x1948c stores 1 byte to abs 0xffffffffffffa03f.
  The `lw` at 0x19494 loads 4 bytes from abs 0xffffffffffffa1a4.
  The `sw` at 0x194b0 stores 4 bytes to abs 0xffffffffffffa2e0.
  The `ld` at 0x194b4 loads 8 bytes from abs 0xffffffffffffa2d0.
  The `sd` at 0x194c0 stores 8 bytes to abs 0xffffffffb4000018.
  The `jal` at 0x19490 calls printf with a0=sym(.data)+10995, a1=?, a2=sp, a3=?.
  The `jal` at 0x194a4 calls printf with a0=sym(.data)+11060, a1=ra at entry, a2=[-0x5fc1]:1, a3=?.
  The `jal` at 0x194e0 calls panic with a0=sym(.data)+11080, a1=?, a2=?, a3=?.
  Calls _baduk via direct with a0=?, a1=?, a2=?, a3=? (`j` at 0x194e8).
  The `beq` branch at 0x19460 targets 0x19468 and is always taken.

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

- `VEC_dbe` in `IP32/usr/cpu/sysgen/IP32boot/kernel.o` at 0x1c2d4 (n32).
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x1c2d4-0x1c358 (132 bytes).
  It occupies 132 bytes.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000048, including `ld` at 0x1c2d8, `ld` at 0x1c334.
  The `sd` at 0x1c2e4 stores 8 bytes to sym(crm_cpu_error_stat) +0x0.
  The `ld` at 0x1c2e8 loads 8 bytes from abs 0xffffffffb4000040.
  The `sd` at 0x1c2f4 stores 8 bytes to sym(crm_cpu_error_addr) +0x0.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000250, including `ld` at 0x1c2f8, `ld` at 0x1c338.
  The `sd` at 0x1c304 stores 8 bytes to sym(crm_mem_error_stat) +0x0.
  The `ld` at 0x1c308 loads 8 bytes from abs 0xffffffffb4000258.
  The `sd` at 0x1c314 stores 8 bytes to sym(crm_mem_error_addr) +0x0.
  The `ld` at 0x1c318 loads 8 bytes from abs 0xffffffffb4000058.
  The `sd` at 0x1c328 stores 8 bytes to sym(crm_vice_error_addr) +0x0.
  The `sd` at 0x1c32c stores 8 bytes to abs 0xffffffffb4000250.
  The `sd` at 0x1c330 stores 8 bytes to abs 0xffffffffb4000048.
  The `sw` at 0x1c344 stores 4 bytes to abs 0xffffffffbf080004.
  The `lh` at 0x1c348 loads 2 bytes from abs 0xffffffffffffa190.
  The `lw` at 0x1c34c loads 4 bytes from abs 0xffffffffbf080004.
  The `sd` at 0x1c354 stores 8 bytes to a0 (arg0 at entry) +0x140.
  Calls VEC_trap via direct with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=a2 at entry (arg2), a3=a3 at entry (arg3) (`j` at 0x1c350).

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
  Evidence grade: inferred.
  Exact binary: `IP32/usr/cpu/sysgen/IP32boot/kernel.o`.
  Range: 0x20dc0-0x20e5c (156 bytes).
  It occupies 156 bytes.
  2 such `ld` accesses load 8 bytes from ?, including `ld` at 0x20dc0, `ld` at 0x20dc4.
  The `sd` at 0x20dd4 stores 8 bytes to ?.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000048, including `ld` at 0x20ddc, `ld` at 0x20e38.
  The `sd` at 0x20de8 stores 8 bytes to sym(crm_cpu_error_stat) +0x0.
  The `ld` at 0x20dec loads 8 bytes from abs 0xffffffffb4000040.
  The `sd` at 0x20df8 stores 8 bytes to sym(crm_cpu_error_addr) +0x0.
  2 such `ld` accesses load 8 bytes from abs 0xffffffffb4000250, including `ld` at 0x20dfc, `ld` at 0x20e3c.
  The `sd` at 0x20e08 stores 8 bytes to sym(crm_mem_error_stat) +0x0.
  The `ld` at 0x20e0c loads 8 bytes from abs 0xffffffffb4000258.
  The `sd` at 0x20e18 stores 8 bytes to sym(crm_mem_error_addr) +0x0.
  The `ld` at 0x20e1c loads 8 bytes from abs 0xffffffffb4000058.
  The `sd` at 0x20e2c stores 8 bytes to sym(crm_vice_error_addr) +0x0.
  The `sd` at 0x20e30 stores 8 bytes to abs 0xffffffffb4000250.
  The `sd` at 0x20e34 stores 8 bytes to abs 0xffffffffb4000048.
  The `sw` at 0x20e48 stores 4 bytes to abs 0xffffffffbf080004.
  The `lh` at 0x20e4c loads 2 bytes from abs 0xffffffffffffa190.
  The `lw` at 0x20e50 loads 4 bytes from abs 0xffffffffbf080004.
  The `sd` at 0x20e58 stores 8 bytes to a0 (arg0 at entry) +0x140.
  Calls VEC_trap via direct with a0=a0 at entry (arg0), a1=a1 at entry (arg1), a2=?, a3=a3 at entry (arg3) (`j` at 0x20e54).
  The `bgez` branch at 0x20dc8 targets 0x20dd4, is taken when ra(?) >= 0 (signed), and falls through when ra(?) < 0 (signed).

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
